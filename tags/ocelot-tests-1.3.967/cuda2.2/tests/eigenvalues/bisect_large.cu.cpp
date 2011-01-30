# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/stddef.h" 3
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
# 96 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{





  cudaSuccess = 0,





  cudaErrorMissingConfiguration = 1,





  cudaErrorMemoryAllocation = 2,





  cudaErrorInitializationError = 3,
# 131 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchFailure = 4,
# 140 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorPriorLaunchFailure = 5,
# 150 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchTimeout = 6,
# 159 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchOutOfResources = 7,





  cudaErrorInvalidDeviceFunction = 8,
# 174 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 255 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorAddressOfConstant = 22,
# 264 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureFetchFailed = 23,
# 273 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureNotBound = 24,
# 282 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorSynchronizationError = 25,





  cudaErrorInvalidFilterSetting = 26,





  cudaErrorInvalidNormSetting = 27,







  cudaErrorMixedDeviceExecution = 28,







  cudaErrorCudartUnloading = 29,




  cudaErrorUnknown = 30,





  cudaErrorNotYetImplemented = 31,
# 330 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorMemoryValueTooLarge = 32,






  cudaErrorInvalidResourceHandle = 33,







  cudaErrorNotReady = 34,






  cudaErrorInsufficientDriver = 35,
# 365 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 426 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorDevicesUnavailable = 46,




  cudaErrorInvalidKernelImage = 47,







  cudaErrorNoKernelImageForDevice = 48,
# 448 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorIncompatibleDriverContext = 49,




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
    cudaLimitPrintfFifoSize = 0x01,
    cudaLimitMallocHeapSize = 0x02
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
  int tccDriver;
  int __cudaReserved[21];
};
# 768 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct cudaGraphicsResource *cudaGraphicsResource_t;





typedef struct CUuuid_st cudaUUID_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_types.h" 1 3
# 63 "/usr/local/cuda/bin/../include/surface_types.h" 3
enum cudaSurfaceBoundaryMode
{
  cudaBoundaryModeZero = 0,
  cudaBoundaryModeClamp = 1,
  cudaBoundaryModeTrap = 2
};





enum cudaSurfaceFormatMode
{
  cudaFormatModeForced = 0,
  cudaFormatModeAuto = 1
};





struct surfaceReference
{



  struct cudaChannelFormatDesc channelDesc;
};
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 63 "/usr/local/cuda/bin/../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap = 0,
  cudaAddressModeClamp = 1,
  cudaAddressModeMirror = 2,
  cudaAddressModeBorder = 3
};





enum cudaTextureFilterMode
{
  cudaFilterModePoint = 0,
  cudaFilterModeLinear = 1
};





enum cudaTextureReadMode
{
  cudaReadModeElementType = 0,
  cudaReadModeNormalizedFloat = 1
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
# 213 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/stddef.h" 2 3
# 96 "/usr/local/cuda/bin/../include/driver_types.h"
# 466 "/usr/local/cuda/bin/../include/driver_types.h"
# 478 "/usr/local/cuda/bin/../include/driver_types.h"
# 491 "/usr/local/cuda/bin/../include/driver_types.h"
# 497 "/usr/local/cuda/bin/../include/driver_types.h"
# 510 "/usr/local/cuda/bin/../include/driver_types.h"
# 523 "/usr/local/cuda/bin/../include/driver_types.h"
# 535 "/usr/local/cuda/bin/../include/driver_types.h"
# 546 "/usr/local/cuda/bin/../include/driver_types.h"
# 564 "/usr/local/cuda/bin/../include/driver_types.h"
# 570 "/usr/local/cuda/bin/../include/driver_types.h"
# 579 "/usr/local/cuda/bin/../include/driver_types.h"
# 590 "/usr/local/cuda/bin/../include/driver_types.h"
# 603 "/usr/local/cuda/bin/../include/driver_types.h"
# 656 "/usr/local/cuda/bin/../include/driver_types.h"
# 667 "/usr/local/cuda/bin/../include/driver_types.h"
# 678 "/usr/local/cuda/bin/../include/driver_types.h"
# 689 "/usr/local/cuda/bin/../include/driver_types.h"
# 768 "/usr/local/cuda/bin/../include/driver_types.h"
# 774 "/usr/local/cuda/bin/../include/driver_types.h"
# 780 "/usr/local/cuda/bin/../include/driver_types.h"
# 786 "/usr/local/cuda/bin/../include/driver_types.h"
# 792 "/usr/local/cuda/bin/../include/driver_types.h"
# 63 "/usr/local/cuda/bin/../include/surface_types.h"
# 74 "/usr/local/cuda/bin/../include/surface_types.h"
# 84 "/usr/local/cuda/bin/../include/surface_types.h"
# 63 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 85 "/usr/local/cuda/bin/../include/texture_types.h"
# 95 "/usr/local/cuda/bin/../include/texture_types.h"
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
# 115 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 131 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 183 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t);
# 207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit);
# 237 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetCacheConfig(cudaFuncCache *);
# 278 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetCacheConfig(cudaFuncCache);
# 330 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 373 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 387 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 418 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 536 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 555 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 579 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 597 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 677 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(unsigned);
# 703 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 719 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 753 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t, cudaEvent_t, unsigned);
# 771 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 789 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 821 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 852 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, unsigned);
# 885 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0);
# 914 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 946 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 966 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 1007 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 1046 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 1073 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 1119 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache);
# 1154 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 1187 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 1209 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 1231 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 1263 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 1292 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 1331 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 1370 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0));
# 1394 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 1414 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 1436 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 1495 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 1522 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 1541 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 1576 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 1626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0));
# 1723 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 1828 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0);
# 1847 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 1880 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 1913 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 1946 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 1981 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2023 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2064 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2105 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 2144 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2179 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 2213 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 2256 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2298 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2340 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2391 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2441 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2491 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2535 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2578 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2600 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 2626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 2665 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 2692 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemsetAsync(void *, int, size_t, cudaStream_t = 0);
# 2724 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2DAsync(void *, size_t, int, size_t, size_t, cudaStream_t = 0);
# 2769 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3DAsync(cudaPitchedPtr, int, cudaExtent, cudaStream_t = 0);
# 2796 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 2819 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 2865 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t);
# 2897 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t, unsigned);
# 2932 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2963 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2992 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource_t);
# 3026 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource_t, unsigned, unsigned);
# 3059 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 3094 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 3136 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 3179 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 3207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3228 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 3253 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 3277 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 3310 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3328 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 3355 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 3372 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 3377 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
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
# 65 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 66 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 67 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 69 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 70 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 71 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 72 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 74 "/usr/local/cuda/bin/../include/driver_functions.h"
return s;
# 75 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 92 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 93 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 94 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 96 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 97 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 98 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 100 "/usr/local/cuda/bin/../include/driver_functions.h"
return p;
# 101 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 118 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 119 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 120 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 122 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 123 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 124 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 126 "/usr/local/cuda/bin/../include/driver_functions.h"
return e;
# 127 "/usr/local/cuda/bin/../include/driver_functions.h"
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
_SVID_ = 0,
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
template< class _Iterator, class _Container> class __normal_iterator;
# 74 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 76 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace std __attribute__((visibility("default"))) {
# 78 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __true_type { };
# 79 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __false_type { };
# 81 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< bool __T0>
# 82 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __truth_type {
# 83 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 86 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 87 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 91 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Sp, class _Tp>
# 92 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __traitor {
# 94 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
# 95 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 96 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 99 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class , class >
# 100 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same {
# 102 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 103 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 104 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 106 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 107 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 109 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 110 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 111 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 114 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
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
template< class _Tp>
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
template< class _Tp>
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
template< class _Tp>
# 286 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 288 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 289 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 290 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 292 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 293 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 295 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 296 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 297 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 302 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 303 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 305 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 306 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 307 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 309 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container>
# 310 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 313 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 314 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 315 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 320 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 321 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 323 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 328 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 329 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 331 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 336 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
# 337 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 339 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 344 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Tp>
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
template< class _Tp>
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
template< class _Tp>
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
template< bool __T1, class >
# 41 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if {
# 42 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 44 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< class _Tp>
# 45 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 46 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 50 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< bool _Cond, class _Iftrue, class _Iffalse>
# 51 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type {
# 52 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 54 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< class _Iftrue, class _Iffalse>
# 55 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 56 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 60 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< class _Tp>
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
template< class _Tp>
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
template< class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
# 159 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote {
# 160 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef double __type; };
# 162 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< class _Tp>
# 163 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote< _Tp, false> {
# 164 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 166 "/usr/include/c++/4.4/ext/type_traits.h" 3
template< class _Tp, class _Up>
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
template< class _Tp, class _Up, class _Vp>
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
template< class _Tp, class _Up, class _Vp, class _Wp>
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
template< class T> extern inline T __pow_helper(T, int);
# 505 "/usr/local/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __cmath_power(T, unsigned);
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
template< class T, int dim = 1>
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
template< int dim>
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
template< class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
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
# 324 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mulhi(int a, int b)
# 325 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 327 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 329 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b)
# 330 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 332 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 334 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b)
# 335 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 337 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b)
# 340 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b)
# 345 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 347 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 350 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 352 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 355 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 357 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 360 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float_as_int(float a)
# 365 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 367 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int_as_float(int a)
# 370 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float saturate(float a)
# 375 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 377 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mul24(int a, int b)
# 380 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 382 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b)
# 385 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void trap()
# 390 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 392 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void brkpt(int c)
# 395 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 397 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 399 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void syncthreads()
# 400 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 404 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void prof_trigger(int e)
# 405 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 422 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 424 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void threadfence(bool global = true)
# 425 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 430 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 437 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 438 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 445 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 446 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 453 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 454 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 459 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 102 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val)
# 103 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 105 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 107 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 108 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val)
# 113 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 115 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val)
# 118 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 120 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val)
# 123 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 125 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val)
# 128 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 130 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val)
# 133 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 135 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val)
# 138 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val)
# 143 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val)
# 148 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 150 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val)
# 153 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 155 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val)
# 158 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val)
# 163 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val)
# 168 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 170 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 173 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 175 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val)
# 178 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val)
# 183 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 185 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val)
# 188 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 190 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val)
# 193 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 195 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val)
# 198 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 203 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 205 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 75 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 76 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 78 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 80 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 81 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 83 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 85 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 86 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 88 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond)
# 91 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 93 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond)
# 96 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 98 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 170 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 171 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 176 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 178 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 179 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 184 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 186 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 187 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 194 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 195 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 203 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 208 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 210 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 211 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 216 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 218 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 219 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 224 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 226 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 227 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 234 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 235 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 240 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 242 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 243 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 245 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 248 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 252 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 253 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 66 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val)
# 67 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;
# 69 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 124 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned ballot(bool pred)
# 125 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 127 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 129 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred)
# 130 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 132 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 134 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred)
# 135 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 137 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 139 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred)
# 140 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 142 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 97 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 98 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 99 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 106 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 108 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 109 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 110 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 116 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 118 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 119 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 120 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 122 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 125 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 126 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 128 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 131 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 132 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 134 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 138 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 143 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 144 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 146 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 149 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 155 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 156 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 166 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 174 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 189 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 196 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 198 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 201 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 202 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 204 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 207 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 208 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 218 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 226 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 238 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 241 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 242 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 244 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 248 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 253 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 254 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 256 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 259 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 264 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 270 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 278 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 290 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 294 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 296 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 299 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 300 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 302 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 305 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 306 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 308 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 311 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 316 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 322 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 385 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 386 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 388 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 391 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 392 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 394 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 398 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 410 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 457 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 458 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 459 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 466 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 469 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 470 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 476 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 478 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 479 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 480 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 482 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 485 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 486 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 488 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 492 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 494 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 497 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 498 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 500 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 503 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 504 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 506 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 509 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 510 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 512 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 516 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 520 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 526 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 534 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 540 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 546 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 549 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 550 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 555 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 556 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 558 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 562 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 564 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 567 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 568 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 572 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 578 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 586 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 592 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 598 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 601 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 602 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 604 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 607 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 608 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 610 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 613 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 614 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 616 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 619 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 620 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 624 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 630 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 638 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 644 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 650 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 653 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 654 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 659 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 660 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 662 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 665 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 666 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 668 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 672 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 682 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 745 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 746 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 748 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 751 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 752 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 754 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 757 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 758 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 762 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 770 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 817 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 818 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 819 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 837 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 839 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 840 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 841 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 843 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 846 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 847 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 849 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 852 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 854 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 856 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 857 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 859 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 862 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 864 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 867 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 869 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 872 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 877 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 879 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 882 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 884 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 887 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 889 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 892 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 894 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 897 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 899 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 902 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 904 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 907 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 909 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 912 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 914 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 917 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 919 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 922 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 924 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 927 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 929 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 932 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 934 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 937 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 939 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 942 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 947 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 949 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 952 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 954 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 957 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 959 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 962 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 964 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 967 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 969 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 972 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 974 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 977 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 979 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 982 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 984 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 987 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 989 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 992 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 994 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 997 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 999 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1045 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1046 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1048 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1050 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1051 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1053 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1055 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1056 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1058 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1061 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1063 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1110 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1111 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1112 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1130 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1132 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1133 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1134 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1136 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1139 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1140 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1142 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1145 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1147 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1149 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1155 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1157 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1160 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1162 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1165 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1167 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1172 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1175 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1177 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1180 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1185 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1187 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1195 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1197 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1200 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1205 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1207 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1210 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1215 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1217 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1220 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1222 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1225 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1227 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1235 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1240 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1242 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1245 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1247 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1250 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1255 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1257 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1262 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1265 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1267 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1270 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1272 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1275 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1277 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1280 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1282 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1285 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1287 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1290 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1292 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1338 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1339 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1341 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1343 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1344 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1346 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1348 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1349 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1351 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1354 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 61 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 63 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 65 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 68 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetch(texture< T, dim, readMode> , float4, int = dim);
# 70 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetch(texture< T, dim, readMode> , float4, int = dim);
# 72 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetch(texture< T, dim, readMode> , float4, int = dim);
# 80 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 81 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 89 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 92 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 96 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 98 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 99 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 103 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 158 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 172 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 179 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 193 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 207 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 220 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 222 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 227 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 234 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 241 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 343 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 344 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 351 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 357 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 358 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 390 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 460 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 468 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 481 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 489 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 497 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 530 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 538 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 545 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 559 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 566 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 607 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 614 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 621 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 628 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 635 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 642 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 649 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 664 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 669 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 683 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 803 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 805 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 806 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 810 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 817 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 824 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 832 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 890 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 898 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 906 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 915 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 920 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 923 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 928 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 936 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 952 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 968 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 976 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 985 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 993 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 996 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1000 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1003 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1007 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1010 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1028 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1058 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1062 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1069 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1072 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1076 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1083 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1111 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1259 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1266 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1273 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1281 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1282 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1302 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1323 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1331 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1339 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1347 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1372 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1393 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1401 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1409 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1417 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1425 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1434 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1442 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1449 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1452 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1456 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1463 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1470 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1477 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1487 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1498 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1511 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1514 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1518 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1525 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1532 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1535 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1539 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1542 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1546 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1549 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1553 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1556 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1560 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1597 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1604 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1611 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1618 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1701 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1708 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1715 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1722 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1730 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1731 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1740 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1743 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1750 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1751 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1759 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1764 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1772 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1775 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1780 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1791 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1796 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1804 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1818 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1821 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1826 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1829 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1834 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1837 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern int4 __itex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1932 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern uint4 __utex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1934 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern float4 __ftex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1955 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1957 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1959 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< signed char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1964 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1965 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1967 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1969 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1972 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1974 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1975 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1977 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1979 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1980 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1982 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1985 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1987 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1989 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1990 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1992 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1994 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1997 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1999 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2000 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2004 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2005 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2007 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2010 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2012 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2015 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2019 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2020 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2022 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2025 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2027 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2029 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2032 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2034 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2039 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2040 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2047 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2050 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2052 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2054 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2055 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2059 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2060 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2062 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2067 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2069 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2070 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2072 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2074 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2075 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2077 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2080 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2082 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2084 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2087 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2089 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2094 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2095 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2102 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2109 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2114 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2115 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2122 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2125 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2129 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2130 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2132 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 threadIdx; }
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 blockIdx; }
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 blockDim; }
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 gridDim; }
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const int warpSize; }
# 106 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 107 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 108 "/usr/local/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 109 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset)
# 111 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 112 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 113 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 145 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 146 "/usr/local/cuda/bin/../include/cuda_runtime.h"
event, unsigned
# 147 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 149 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 150 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaEventCreateWithFlags(event, 0);
# 151 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 209 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 210 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 211 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 213 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 214 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc(ptr, size, flags);
# 215 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 217 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 218 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 219 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 220 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 221 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 223 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 224 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 225 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 228 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 229 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 230 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 231 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 233 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 234 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 235 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 237 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 238 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 239 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 240 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 242 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 243 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 244 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 246 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 247 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 248 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 249 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 250 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags = (0))
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 253 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size, flags);
# 254 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 256 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 257 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 258 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 259 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 260 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 261 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height)
# 263 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 264 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 265 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 276 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 277 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 278 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 279 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 280 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 282 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 283 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 284 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 286 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 287 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 288 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 289 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 290 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 291 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 292 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 294 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 295 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 296 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 298 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 299 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 300 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 301 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 302 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 303 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 304 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 306 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 307 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 308 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 310 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 311 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 312 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 313 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 314 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 315 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 316 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 317 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 319 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 320 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 321 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 329 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 330 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 331 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 332 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 333 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 334 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 336 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 337 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 338 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 340 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 341 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 342 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 343 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 344 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 345 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 346 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 348 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 349 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 350 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 352 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 353 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 354 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 355 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 356 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 357 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 358 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 360 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 361 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 362 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 364 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 365 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 366 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 367 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 368 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 369 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 370 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 371 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 373 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 374 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 375 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 377 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 378 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 379 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 381 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 382 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 383 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 410 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 411 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 412 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 413 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 415 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 416 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 417 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 425 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 426 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, char *
# 427 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 429 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 430 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 431 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 458 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 459 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 460 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 461 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 463 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 464 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 465 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 507 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 508 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 509 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 510 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 511 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 512 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 513 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 515 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 516 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 517 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 552 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 553 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 554 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 555 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 556 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 557 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 559 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 560 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 561 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 608 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 609 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 610 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 611 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 612 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 613 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 614 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 615 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 616 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 618 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 619 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 620 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 666 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 667 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 668 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 669 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 670 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 671 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 672 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 673 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 675 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 676 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &(tex.texture< T, dim, readMode> ::channelDesc), width, height, pitch);
# 677 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 708 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 709 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 710 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 711 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 712 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 714 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 715 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 716 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 746 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 747 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 748 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 749 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 751 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 752 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 753 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 755 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 756 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 785 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 786 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 787 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 789 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 790 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 791 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 825 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 826 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 827 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 828 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 830 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 831 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 832 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 886 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 887 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 888 "/usr/local/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 889 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 891 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 892 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 893 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 930 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 931 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 932 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 934 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 935 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 936 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 970 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 971 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 972 "/usr/local/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 973 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 975 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 976 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 977 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 999 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1000 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1001 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1002 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 1003 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 1005 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1006 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 1007 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 1028 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1029 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1030 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1031 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 1033 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1034 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 1035 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 1037 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 1038 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 40 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/va.h" 3
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
# 128 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned long long CUdeviceptr; }
# 135 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 136 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 137 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 138 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 139 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 140 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 141 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 142 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 143 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 144 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 148 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 146 "/usr/local/cuda/bin/../include/cuda.h"
struct CUuuid_st {
# 147 "/usr/local/cuda/bin/../include/cuda.h"
char bytes[16];
# 148 "/usr/local/cuda/bin/../include/cuda.h"
} CUuuid; }
# 162 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 153 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 154 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 155 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 156 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 157 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 158 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 159 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 160 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 161 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 162 "/usr/local/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 171 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 167 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 168 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 169 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 170 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DISABLE_TIMING
# 171 "/usr/local/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 185 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 176 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 177 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 178 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 179 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 180 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 181 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 182 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 183 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 184 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 185 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 195 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 191 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 192 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 193 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 194 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER
# 195 "/usr/local/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 203 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 200 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 201 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 202 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 203 "/usr/local/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 246 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 208 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 209 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 210 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 211 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 212 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 213 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 214 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 215 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 216 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 217 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 218 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 219 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 220 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 221 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 222 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 223 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 224 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 225 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 226 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 227 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 228 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 229 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 230 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 231 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 232 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 233 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 234 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 235 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 236 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 237 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 238 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 240 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 241 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 242 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 243 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 244 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 245 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER
# 246 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 262 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 251 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 252 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 253 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 254 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 255 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 256 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 257 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 258 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 259 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 260 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 261 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 262 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 317 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 267 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 273 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 280 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 286 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 291 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 296 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 305 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 314 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 316 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 317 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 326 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 322 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 323 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 324 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 325 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 326 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 335 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 331 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 332 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 333 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 334 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 335 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 344 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 340 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 341 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 342 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 343 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 344 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 436 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 349 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 355 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 375 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 383 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 391 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 399 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 407 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 414 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 421 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 427 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 434 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 436 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 449 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 441 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 443 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 444 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 445 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 446 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 447 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20,
# 448 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_21
# 449 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 460 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 454 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 456 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 458 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 460 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 467 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 465 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 466 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 467 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 476 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 472 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 473 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 474 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 475 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 476 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 488 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 481 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 482 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 483 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 484 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 485 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 486 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 487 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 488 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 497 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 493 "/usr/local/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 494 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 495 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 496 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE
# 497 "/usr/local/cuda/bin/../include/cuda.h"
} CUlimit; }
# 728 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 502 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 508 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 514 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 520 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 526 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 531 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 538 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 544 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 551 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 561 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 570 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 575 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 580 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 586 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 591 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 599 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 604 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 609 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 615 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 621 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 627 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 633 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 639 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 644 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 649 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 654 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 659 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 666 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 673 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 682 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 693 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 704 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 715 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 721 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 727 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 728 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 756 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 757 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 758 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 760 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 761 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 762 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 763 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 764 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 766 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 767 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 769 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 770 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 771 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 772 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 773 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 775 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 776 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 777 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 810 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 782 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 783 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 784 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 785 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcZ;
# 786 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcLOD;
# 787 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 788 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 789 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 790 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 791 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 792 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 793 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 795 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 796 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 797 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstZ;
# 798 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstLOD;
# 799 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 800 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 801 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 802 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 803 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 804 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 805 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 807 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 808 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 809 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 810 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 822 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 815 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR_st {
# 817 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 818 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 820 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 821 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 822 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 836 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 827 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR_st {
# 829 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 830 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 831 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 833 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 834 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 835 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 836 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 917 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 944 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 982 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 1008 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 1037 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 1066 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 1094 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem_v2(size_t *, CUdevice);
# 1154 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 1235 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 1333 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate_v2(CUcontext *, unsigned, CUdevice);
# 1367 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 1403 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 1435 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 1473 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 1515 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 1545 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 1575 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 1638 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit, size_t);
# 1673 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t *, CUlimit);
# 1716 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetCacheConfig(CUfunc_cache *);
# 1766 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetCacheConfig(CUfunc_cache);
# 1803 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetApiVersion(CUcontext, unsigned *);
# 1851 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 1885 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 1963 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 2000 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 2025 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 2055 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 2089 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal_v2(CUdeviceptr *, size_t *, CUmodule, const char *);
# 2123 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 2154 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref *, CUmodule, const char *);
# 2197 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo_v2(size_t *, size_t *);
# 2230 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc_v2(CUdeviceptr *, size_t);
# 2291 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch_v2(CUdeviceptr *, size_t *, size_t, size_t, unsigned);
# 2320 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree_v2(CUdeviceptr);
# 2353 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange_v2(CUdeviceptr *, size_t *, CUdeviceptr);
# 2392 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost_v2(void **, size_t);
# 2422 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 2494 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 2532 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *, void *, unsigned);
# 2557 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 2591 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD_v2(CUdeviceptr, const void *, size_t);
# 2624 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH_v2(void *, CUdeviceptr, size_t);
# 2657 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD_v2(CUdeviceptr, CUdeviceptr, size_t);
# 2691 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA_v2(CUarray, size_t, CUdeviceptr, size_t);
# 2727 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD_v2(CUdeviceptr, CUarray, size_t, size_t);
# 2761 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA_v2(CUarray, size_t, const void *, size_t);
# 2795 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH_v2(void *, CUarray, size_t, size_t);
# 2833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA_v2(CUarray, size_t, CUarray, size_t, size_t);
# 2978 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *);
# 3121 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *);
# 3273 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *);
# 3313 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr, const void *, size_t, CUstream);
# 3353 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync_v2(void *, CUdeviceptr, size_t, CUstream);
# 3390 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr, CUdeviceptr, size_t, CUstream);
# 3432 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync_v2(CUarray, size_t, const void *, size_t, CUstream);
# 3474 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync_v2(void *, CUarray, size_t, size_t, CUstream);
# 3630 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *, CUstream);
# 3790 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *, CUstream);
# 3823 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8_v2(CUdeviceptr, unsigned char, size_t);
# 3856 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16_v2(CUdeviceptr, unsigned short, size_t);
# 3889 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32_v2(CUdeviceptr, unsigned, size_t);
# 3927 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8_v2(CUdeviceptr, size_t, unsigned char, size_t, size_t);
# 3965 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16_v2(CUdeviceptr, size_t, unsigned short, size_t, size_t);
# 4003 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32_v2(CUdeviceptr, size_t, unsigned, size_t, size_t);
# 4040 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8Async(CUdeviceptr, unsigned char, size_t, CUstream);
# 4077 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16Async(CUdeviceptr, unsigned short, size_t, CUstream);
# 4113 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32Async(CUdeviceptr, unsigned, size_t, CUstream);
# 4155 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8Async(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);
# 4197 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16Async(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream);
# 4239 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32Async(CUdeviceptr, size_t, unsigned, size_t, size_t, CUstream);
# 4342 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate_v2(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 4375 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 4406 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 4508 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate_v2(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 4544 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 4582 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 4622 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamWaitEvent(CUstream, CUevent, unsigned);
# 4646 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 4671 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 4693 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 4741 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 4777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 4809 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 4843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 4866 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 4909 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 4954 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 4985 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 5042 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 5090 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction, CUfunc_cache);
# 5119 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 5149 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 5179 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 5211 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 5245 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 5281 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 5321 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 5354 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 5395 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 5433 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress_v2(size_t *, CUtexref, CUdeviceptr, size_t);
# 5474 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D_v2(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);
# 5503 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 5541 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 5574 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 5606 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 5632 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress_v2(CUdeviceptr *, CUtexref);
# 5658 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 5684 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 5708 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 5734 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 5757 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 5791 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 5811 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 5849 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref, CUarray, unsigned);
# 5870 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray *, CUsurfref);
# 5911 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 5949 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 5983 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr *, size_t *, CUgraphicsResource);
# 6024 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 6062 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 6097 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 6101 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void **, const CUuuid *);
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
# 46 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 48 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 49 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 50 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 51 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 53 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 54 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 55 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 56 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 58 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 59 "/usr/local/cuda/bin/../include/cuComplex.h"
r, float i)
# 60 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 61 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex res;
# 62 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 63 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 64 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 65 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 67 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 68 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 69 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 70 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 71 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 72 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 73 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 74 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 76 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 78 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 79 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 80 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 81 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 83 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 90 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 91 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 92 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 93 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex prod;
# 94 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuFloatComplex((cuCrealf(x) * cuCrealf(y)) - (cuCimagf(x) * cuCimagf(y)), (cuCrealf(x) * cuCimagf(y)) + (cuCimagf(x) * cuCrealf(y)));
# 98 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 99 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 106 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 107 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 108 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 109 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex quot;
# 110 "/usr/local/cuda/bin/../include/cuComplex.h"
float s = (fabsf(cuCrealf(y)) + fabsf(cuCimagf(y)));
# 111 "/usr/local/cuda/bin/../include/cuComplex.h"
float oos = ((1.0F) / s);
# 112 "/usr/local/cuda/bin/../include/cuComplex.h"
float ars = (cuCrealf(x) * oos);
# 113 "/usr/local/cuda/bin/../include/cuComplex.h"
float ais = (cuCimagf(x) * oos);
# 114 "/usr/local/cuda/bin/../include/cuComplex.h"
float brs = (cuCrealf(y) * oos);
# 115 "/usr/local/cuda/bin/../include/cuComplex.h"
float bis = (cuCimagf(y) * oos);
# 116 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 117 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0F) / s);
# 118 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuFloatComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 120 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 121 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 131 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 132 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 133 "/usr/local/cuda/bin/../include/cuComplex.h"
float a = cuCrealf(x);
# 134 "/usr/local/cuda/bin/../include/cuComplex.h"
float b = cuCimagf(x);
# 135 "/usr/local/cuda/bin/../include/cuComplex.h"
float v, w, t;
# 136 "/usr/local/cuda/bin/../include/cuComplex.h"
a = fabsf(a);
# 137 "/usr/local/cuda/bin/../include/cuComplex.h"
b = fabsf(b);
# 138 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 139 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 140 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 141 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 142 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 143 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 144 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 145 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 146 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0F) + (t * t));
# 147 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * sqrtf(t));
# 148 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 149 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 150 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 151 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 152 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 155 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 157 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 158 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 159 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 160 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 162 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 163 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 164 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 165 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 167 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 168 "/usr/local/cuda/bin/../include/cuComplex.h"
r, double i)
# 169 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 170 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex res;
# 171 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 172 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 173 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 174 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 176 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 177 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 178 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 179 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 181 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 182 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 183 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 184 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 186 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 188 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 189 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 190 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 191 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 193 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 200 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 201 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 202 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 203 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex prod;
# 204 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuDoubleComplex((cuCreal(x) * cuCreal(y)) - (cuCimag(x) * cuCimag(y)), (cuCreal(x) * cuCimag(y)) + (cuCimag(x) * cuCreal(y)));
# 208 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 209 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 216 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 217 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 218 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 219 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex quot;
# 220 "/usr/local/cuda/bin/../include/cuComplex.h"
double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 221 "/usr/local/cuda/bin/../include/cuComplex.h"
double oos = ((1.0) / s);
# 222 "/usr/local/cuda/bin/../include/cuComplex.h"
double ars = (cuCreal(x) * oos);
# 223 "/usr/local/cuda/bin/../include/cuComplex.h"
double ais = (cuCimag(x) * oos);
# 224 "/usr/local/cuda/bin/../include/cuComplex.h"
double brs = (cuCreal(y) * oos);
# 225 "/usr/local/cuda/bin/../include/cuComplex.h"
double bis = (cuCimag(y) * oos);
# 226 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 227 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0) / s);
# 228 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuDoubleComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 230 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 231 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 239 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 240 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 241 "/usr/local/cuda/bin/../include/cuComplex.h"
double a = cuCreal(x);
# 242 "/usr/local/cuda/bin/../include/cuComplex.h"
double b = cuCimag(x);
# 243 "/usr/local/cuda/bin/../include/cuComplex.h"
double v, w, t;
# 244 "/usr/local/cuda/bin/../include/cuComplex.h"
a = fabs(a);
# 245 "/usr/local/cuda/bin/../include/cuComplex.h"
b = fabs(b);
# 246 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 247 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 248 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 249 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 250 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 251 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 252 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 253 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 254 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0) + (t * t));
# 255 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * sqrt(t));
# 256 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 257 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 258 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 259 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 260 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 261 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 268 "/usr/local/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 269 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 270 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 271 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 272 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 273 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 276 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 277 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 278 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 279 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 280 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 282 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 283 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 284 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 285 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 286 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 289 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuComplex cuCfmaf(cuComplex x, cuComplex y, cuComplex d)
# 290 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 291 "/usr/local/cuda/bin/../include/cuComplex.h"
float real_res;
# 292 "/usr/local/cuda/bin/../include/cuComplex.h"
float imag_res;
# 294 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((cuCrealf(x) * cuCrealf(y)) + cuCrealf(d));
# 295 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCrealf(x) * cuCimagf(y)) + cuCimagf(d));
# 297 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimagf(x) * cuCimagf(y))) + real_res);
# 298 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimagf(x) * cuCrealf(y)) + imag_res);
# 300 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuComplex(real_res, imag_res);
# 301 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 303 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuCfma(cuDoubleComplex x, cuDoubleComplex y, cuDoubleComplex d)
# 304 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 305 "/usr/local/cuda/bin/../include/cuComplex.h"
double real_res;
# 306 "/usr/local/cuda/bin/../include/cuComplex.h"
double imag_res;
# 308 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((cuCreal(x) * cuCreal(y)) + cuCreal(d));
# 309 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCreal(x) * cuCimag(y)) + cuCimag(d));
# 311 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimag(x) * cuCimag(y))) + real_res);
# 312 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimag(x) * cuCreal(y)) + imag_res);
# 314 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(real_res, imag_res);
# 315 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 72 "/usr/local/cuda/bin/../include/cufft.h"
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
CUFFT_INVALID_SIZE,
# 71 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_UNALIGNED_DATA
# 72 "/usr/local/cuda/bin/../include/cufft.h"
} cufftResult; }
# 77 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 81 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 82 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef double cufftDoubleReal; }
# 87 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 88 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 102 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 95 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftType_t {
# 96 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_R2C = 42,
# 97 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2R = 44,
# 98 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2C = 41,
# 99 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_D2Z = 106,
# 100 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2D = 108,
# 101 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2Z = 105
# 102 "/usr/local/cuda/bin/../include/cufft.h"
} cufftType; }
# 131 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 126 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftCompatibility_t {
# 127 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_NATIVE,
# 128 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_PADDING,
# 129 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ASYMMETRIC,
# 130 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ALL
# 131 "/usr/local/cuda/bin/../include/cufft.h"
} cufftCompatibility; }
# 135 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 140 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 144 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 148 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int);
# 156 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 158 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 163 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 167 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 171 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);
# 176 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);
# 180 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);
# 184 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 187 "/usr/local/cuda/bin/../include/cufft.h"
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
printf("CUDA %d.%02d Toolkit built this project.\n", 3020 / 1000, 3020 % 100);
# 15 "sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "sdk/cutil_inline.h"
}
# 41 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
struct InputData {
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *a;
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *b;
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_a;
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_b;
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_b_raw;
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
};
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
struct ResultDataSmall {
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *eigenvalues;
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_left;
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_right;
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_left_count;
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_right_count;
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_converged;
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned mat_size_f;
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned mat_size_ui;
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *zero_f;
# 84 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *zero_ui;
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
};
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
struct ResultDataLarge {
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_num_one;
# 95 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_num_blocks_mult;
# 99 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_left_one;
# 103 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_right_one;
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_pos_one;
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_left_mult;
# 115 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_right_mult;
# 119 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_left_count_mult;
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_right_count_mult;
# 127 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_blocks_mult;
# 131 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_blocks_mult_sum;
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
float *g_lambda_mult;
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
unsigned *g_pos_mult;
# 141 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/structs.h"
};
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
template< class T> inline void
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
freePtr(T *&ptr) {
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
if (__null != ptr) {
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
free(ptr);
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
ptr = __null;
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 57 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
template< class T> T
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
min(const T &lhs, const T &rhs) {
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (lhs < rhs) ? lhs : rhs;
# 65 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
template< class T> T
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
max(const T &lhs, const T &rhs) {
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (lhs < rhs) ? rhs : lhs;
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
template< class T> T
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
sign_i(const T &val) {
# 89 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (val < 0) ? (-1) : 1;
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 99 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
inline float sign_f(const float &val) {
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (val < (0.0F)) ? (-(1.0F)) : (1.0F);
# 101 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
inline double sign_d(const double &val) {
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (val < (0.0)) ? (-(1.0)) : (1.0);
# 112 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
template< class T> void
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
swap(T &lhs, T &rhs) {
# 124 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
T temp = rhs;
# 125 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
rhs = lhs;
# 126 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
lhs = temp;
# 127 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
}
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
extern "C" { inline unsigned getNumBlocksLinear(const unsigned num_threads, const unsigned
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
num_threads_block)
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
{
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
const unsigned block_rem = (((num_threads % num_threads_block) != (0)) ? 1 : 0);
# 141 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
return (num_threads / num_threads_block) + block_rem;
# 142 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/util.h"
} }
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
extern "C" void writeTridiagSymMatlab(const char *, float *, float *, float *, const unsigned);
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
template< class T, class S> void writeMatrixMatlab(T &, const char *, S *&, const unsigned);
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
template< class T, class S> void writeVectorMatlab(T &, const char *, S *&, const unsigned);
# 102 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
template< class T, class S> void
# 104 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
writeMatrixMatlab(T &file, const char *mat_name, S *&
# 105 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
mat, const unsigned mat_size) {
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
const unsigned pitch = (sizeof(S) * mat_size);
# 109 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
(file << mat_name) << " = [";
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
for (unsigned i = (0); i < mat_size; ++i) {
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
for (unsigned j = (0); j < mat_size; ++j) {
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
(file << getMatrix(mat, pitch, i, j)) << " ";
# 114 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 115 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
if (i != (mat_size - (1))) {
# 116 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
file << "; ";
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 118 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 119 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
file << "];\n";
# 120 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 129 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
template< class T, class S> void
# 131 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
writeVectorMatlab(T &file, const char *vec_name, S *&
# 132 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
vec, const unsigned vec_len)
# 133 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
{
# 134 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
(file << vec_name) << " = [";
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
for (unsigned i = (0); i < vec_len; ++i) {
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
(file << (vec[i])) << " ";
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
file << "];\n";
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/matlab.h"
}
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cuh"
extern "C" void computeEigenvaluesLargeMatrix(const InputData &, const ResultDataLarge &, const unsigned, const float, const float, const float, const unsigned);
# 65 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cuh"
extern "C" void initResultDataLargeMatrix(ResultDataLarge &, const unsigned);
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cuh"
extern "C" void cleanupResultDataLargeMatrix(ResultDataLarge &);
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cuh"
extern "C" void processResultDataLargeMatrix(const InputData &, const ResultDataLarge &, const unsigned, const char *, const unsigned, char *);
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
__attribute__((unused)) inline int floorPow2(int n) {int volatile ___ = 1;
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
__attribute__((unused)) inline int ceilPow2(int n) {int volatile ___ = 1;
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 89 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
__attribute__((unused)) inline float computeMidpoint(const float left, const float right) {int volatile ___ = 1;
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class S, class T> __attribute__((unused)) void
# 120 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
storeInterval(unsigned addr, float *
# 121 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left, float *s_right, T *
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, float
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left, float right, S
# 124 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left_count, S right_count, float
# 125 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
precision)
# 126 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 170 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
__attribute__((unused)) inline unsigned computeNumSmallerEigenvals(float *g_d, float *g_s, const unsigned n, const float
# 171 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
x, const unsigned
# 172 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
tid, const unsigned
# 173 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_intervals_active, float *
# 174 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_d, float *s_s, unsigned
# 175 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
converged)
# 177 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 205 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 227 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
__attribute__((unused)) inline unsigned computeNumSmallerEigenvalsLarge(float *g_d, float *g_s, const unsigned n, const float
# 228 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
x, const unsigned
# 229 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
tid, const unsigned
# 230 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_intervals_active, float *
# 231 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_d, float *s_s, unsigned
# 232 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
converged)
# 234 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 271 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 298 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class S, class T> __attribute__((unused)) void
# 301 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
storeNonEmptyIntervals(unsigned addr, const unsigned
# 302 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_active, float *
# 303 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left, float *s_right, T *
# 304 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, float
# 305 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left, float mid, float right, const S
# 306 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left_count, const S
# 307 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
mid_count, const S
# 308 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
right_count, float
# 309 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
precision, unsigned &
# 310 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
compact_second_chunk, T *
# 311 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_compaction_list_exc, unsigned &
# 312 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
is_active_second)
# 313 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 346 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 357 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class T> __attribute__((unused)) void
# 360 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
createIndicesCompaction(T *s_compaction_list_exc, unsigned
# 361 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_compaction) {int volatile ___ = 1;
# 404 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 423 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class T> __attribute__((unused)) void
# 426 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
compactIntervals(float *s_left, float *s_right, T *
# 427 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, float
# 428 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
mid, float right, unsigned
# 429 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
mid_count, unsigned right_count, T *
# 430 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_compaction_list, unsigned
# 431 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_active, unsigned
# 432 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
is_active_second)
# 433 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 447 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 470 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class T, class S> __attribute__((unused)) void
# 473 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
storeIntervalConverged(float *s_left, float *s_right, T *
# 474 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, float &
# 475 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left, float &mid, float &right, S &
# 476 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left_count, S &mid_count, S &right_count, T *
# 477 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_compaction_list_exc, unsigned &
# 478 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
compact_second_chunk, const unsigned
# 479 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_active)
# 480 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 515 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 517 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class T, class S> __attribute__((unused)) void
# 520 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
storeIntervalConverged(float *s_left, float *s_right, T *
# 521 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, float &
# 522 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left, float &mid, float &right, S &
# 523 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left_count, S &mid_count, S &right_count, T *
# 524 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_compaction_list_exc, unsigned &
# 525 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
compact_second_chunk, const unsigned
# 526 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_active, unsigned &
# 527 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
is_active_second)
# 528 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 563 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 582 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
template< class T> __attribute__((unused)) void
# 585 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
subdivideActiveInterval(const unsigned tid, float *
# 586 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left, float *s_right, T *
# 587 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
s_left_count, T *s_right_count, const unsigned
# 588 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
num_threads_active, float &
# 589 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left, float &right, unsigned &
# 590 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
left_count, unsigned &right_count, float &
# 591 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
mid, unsigned &all_threads_converged)
# 592 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
{int volatile ___ = 1;
# 614 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_util.cu"
exit(___);}
# 55 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void writeToGmem(const unsigned, const unsigned, const unsigned, const unsigned, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, float *, float *, unsigned short *, unsigned short *, unsigned *, unsigned *, unsigned short *, unsigned short *, unsigned);
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void compactStreamsFinal(const unsigned, const unsigned, const unsigned, unsigned &, float *, float *, unsigned short *, unsigned short *, unsigned short *&, unsigned short *&, unsigned short *&, unsigned short *, unsigned, unsigned, float &, float &, float &, float &, unsigned &, unsigned &, unsigned &, unsigned &, unsigned, unsigned, unsigned, unsigned);
# 97 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanCompactBlocksStartAddress(const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *);
# 108 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanSumBlocks(const unsigned, const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *);
# 121 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanInitial(const unsigned, const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void storeNonEmptyIntervalsLarge(unsigned, const unsigned, float *, float *, unsigned short *, unsigned short *, float, float, float, const unsigned short, const unsigned short, const unsigned short, float, unsigned &, unsigned short *, unsigned &);
# 164 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
void bisectKernelLarge(float *g_d, float *g_s, const unsigned n, const float
# 165 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
lg, const float ug, const unsigned
# 166 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
lg_eig_count, const unsigned
# 167 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
ug_eig_count, float
# 168 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
epsilon, unsigned *
# 169 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_num_one, unsigned *
# 170 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_num_blocks_mult, float *
# 171 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_one, float *g_right_one, unsigned *
# 172 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_pos_one, float *
# 173 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_mult, float *g_right_mult, unsigned *
# 174 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_count_mult, unsigned *
# 175 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_right_count_mult, unsigned *
# 176 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_blocks_mult, unsigned *
# 177 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_blocks_mult_sum) ;
# 528 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void writeToGmem(const unsigned tid, const unsigned tid_2, const unsigned
# 529 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_active, const unsigned
# 530 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_blocks_mult, float *
# 531 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_one, float *g_right_one, unsigned *
# 532 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_pos_one, float *
# 533 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_mult, float *g_right_mult, unsigned *
# 534 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_left_count_mult, unsigned *
# 535 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_right_count_mult, float *
# 536 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 537 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left_count, unsigned short *s_right_count, unsigned *
# 538 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_blocks_mult, unsigned *
# 539 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
g_blocks_mult_sum, unsigned short *
# 540 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_compaction_list, unsigned short *
# 541 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_helper, unsigned
# 542 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
offset_mult_lambda)
# 543 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 589 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 596 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void compactStreamsFinal(const unsigned tid, const unsigned tid_2, const unsigned
# 597 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_active, unsigned &
# 598 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
offset_mult_lambda, float *
# 599 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 600 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left_count, unsigned short *s_right_count, unsigned short *&
# 601 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_one, unsigned short *&s_cl_mult, unsigned short *&
# 602 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_blocking, unsigned short *s_cl_helper, unsigned
# 603 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
is_one_lambda, unsigned is_one_lambda_2, float &
# 604 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
left, float &right, float &left_2, float &right_2, unsigned &
# 605 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
left_count, unsigned &right_count, unsigned &
# 606 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
left_count_2, unsigned &right_count_2, unsigned
# 607 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
c_block_iend, unsigned c_sum_block, unsigned
# 608 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
c_block_iend_2, unsigned c_sum_block_2)
# 610 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 673 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 680 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanCompactBlocksStartAddress(const unsigned tid, const unsigned tid_2, const unsigned
# 681 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 682 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_blocking, unsigned short *
# 683 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_helper)
# 685 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 732 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 739 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanSumBlocks(const unsigned tid, const unsigned tid_2, const unsigned
# 740 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_active, const unsigned
# 741 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 742 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_blocking, unsigned short *
# 743 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_helper)
# 744 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 792 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 800 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void scanInitial(const unsigned tid, const unsigned tid_2, const unsigned
# 801 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_active, const unsigned
# 802 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 803 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_one, unsigned short *s_cl_mult, unsigned short *
# 804 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_cl_blocking, unsigned short *s_cl_helper)
# 806 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 886 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 894 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
__attribute__((unused)) void storeNonEmptyIntervalsLarge(unsigned addr, const unsigned
# 895 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
num_threads_active, float *
# 896 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 897 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_left_count, unsigned short *
# 898 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_right_count, float
# 899 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
left, float mid, float right, const unsigned short
# 900 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
left_count, const unsigned short
# 901 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
mid_count, const unsigned short
# 902 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
right_count, float
# 903 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
epsilon, unsigned &
# 904 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
compact_second_chunk, unsigned short *
# 905 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
s_compaction_list, unsigned &
# 906 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
is_active_second)
# 907 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{int volatile ___ = 1;
# 936 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
exit(___);}
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
void bisectKernelLarge_OneIntervals(float *g_d, float *g_s, const unsigned n, unsigned
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
num_intervals, float *
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
g_left, float *g_right, unsigned *
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
g_pos, float
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
precision) ;
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
void bisectKernelLarge_MultIntervals(float *g_d, float *g_s, const unsigned n, unsigned *
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
blocks_mult, unsigned *
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
blocks_mult_sum, float *
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
g_left, float *g_right, unsigned *
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
g_left_count, unsigned *
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
g_right_count, float *
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
g_lambda, unsigned *g_pos, float
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
precision) ;
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
void initResultDataLargeMatrix(ResultDataLarge &result, const unsigned mat_size) {
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned zero = (0);
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned mat_size_f = (sizeof(float) * mat_size);
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned mat_size_ui = (sizeof(unsigned) * mat_size);
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *tempf = ((float *)malloc(mat_size_f));
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned *tempui = ((unsigned *)malloc(mat_size_ui));
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
for (unsigned i = (0); i < mat_size; ++i) {
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(tempf[i]) = (0.0F);
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(tempui[i]) = (0);
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_num_one)), sizeof(unsigned)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 82);
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_num_one, &zero, sizeof(unsigned), cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 84);
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_num_blocks_mult)), sizeof(unsigned)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 89);
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_num_blocks_mult, &zero, sizeof(unsigned), cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 92);
# 95 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_one)), mat_size_f), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 95);
# 96 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_one)), mat_size_f), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 96);
# 97 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_pos_one)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 97);
# 99 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_mult)), mat_size_f), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 99);
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_mult)), mat_size_f), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 100);
# 101 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_count_mult)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 102);
# 103 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_count_mult)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 104);
# 106 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_one, tempf, mat_size_f, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 107);
# 108 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_one, tempf, mat_size_f, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 109);
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_pos_one, tempui, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 111);
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 114);
# 115 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 116);
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_count_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 118);
# 119 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_count_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 120);
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_blocks_mult)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 122);
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_blocks_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 124);
# 125 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_blocks_mult_sum)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 125);
# 126 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_blocks_mult_sum, tempui, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 127);
# 129 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_lambda_mult)), mat_size_f), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 129);
# 130 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_lambda_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 131);
# 132 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_pos_mult)), mat_size_ui), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 132);
# 133 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_pos_mult, tempf, mat_size_ui, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 134);
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 142 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
void cleanupResultDataLargeMatrix(ResultDataLarge &result) {
# 144 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_num_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 144);
# 145 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_num_blocks_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 145);
# 146 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 146);
# 147 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 147);
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_pos_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 148);
# 149 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 149);
# 150 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 150);
# 151 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_count_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 151);
# 152 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_count_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 152);
# 153 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_blocks_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 153);
# 154 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_blocks_mult_sum), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 154);
# 155 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_lambda_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 155);
# 156 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_pos_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 156);
# 157 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 170 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
void computeEigenvaluesLargeMatrix(const InputData &input, const ResultDataLarge &result, const unsigned
# 171 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
mat_size, const float precision, const float
# 172 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
lg, const float ug, const unsigned
# 173 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
iterations)
# 174 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
{
# 175 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 blocks(1, 1, 1);
# 176 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 threads(256, 1, 1);
# 178 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned timer_step1 = (0);
# 179 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned timer_step2_one = (0);
# 180 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned timer_step2_mult = (0);
# 181 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned timer_total = (0);
# 182 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step1), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 182);
# 183 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step2_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 183);
# 184 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step2_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 184);
# 185 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_total), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 185);
# 187 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_total), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 187);
# 190 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
for (unsigned iter = (0); iter < iterations; ++iter) {
# 192 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step1), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 192);
# 193 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
cudaConfigureCall(blocks, threads) ? ((void)0) : bisectKernelLarge(input.g_a, input.g_b, mat_size, lg, ug, 0, mat_size, precision, result.g_num_one, result.g_num_blocks_mult, result.g_left_one, result.g_right_one, result.g_pos_one, result.g_left_mult, result.g_right_mult, result.g_left_count_mult, result.g_right_count_mult, result.g_blocks_mult, result.g_blocks_mult_sum);
# 202 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 202);
# 203 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step1), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 203);
# 204 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckMsg("Kernel launch failed.", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 204);
# 208 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned num_one_intervals;
# 209 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_one_intervals, result.g_num_one, sizeof(unsigned), cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 211);
# 213 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 grid_onei;
# 214 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(grid_onei.x) = getNumBlocksLinear(num_one_intervals, 256);
# 215 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 threads_onei;
# 218 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(threads_onei.x) = (256);
# 222 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step2_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 222);
# 224 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
cudaConfigureCall(grid_onei, threads_onei) ? ((void)0) : bisectKernelLarge_OneIntervals(input.g_a, input.g_b, mat_size, num_one_intervals, result.g_left_one, result.g_right_one, result.g_pos_one, precision);
# 230 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 230);
# 231 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step2_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 231);
# 239 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned num_blocks_mult = (0);
# 240 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_blocks_mult, result.g_num_blocks_mult, sizeof(unsigned), cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 242);
# 245 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 grid_mult(num_blocks_mult, 1, 1);
# 246 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
dim3 threads_mult(256, 1, 1);
# 248 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step2_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 248);
# 250 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
cudaConfigureCall(grid_mult, threads_mult) ? ((void)0) : bisectKernelLarge_MultIntervals(input.g_a, input.g_b, mat_size, result.g_blocks_mult, result.g_blocks_mult_sum, result.g_left_mult, result.g_right_mult, result.g_left_count_mult, result.g_right_count_mult, result.g_lambda_mult, result.g_pos_mult, precision);
# 259 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step2_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 259);
# 260 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckMsg("bisectKernelLarge_MultIntervals() FAILED.", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 260);
# 261 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 263 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_total), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 263);
# 266 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("Average time step 1: %f ms\n", cutGetTimerValue(timer_step1) / ((float)iterations));
# 268 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("Average time step 2, one intervals: %f ms\n", cutGetTimerValue(timer_step2_one) / ((float)iterations));
# 270 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("Average time step 2, mult intervals: %f ms\n", cutGetTimerValue(timer_step2_mult) / ((float)iterations));
# 273 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("Average time TOTAL: %f ms\n", cutGetTimerValue(timer_total) / ((float)iterations));
# 276 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step1), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 276);
# 277 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step2_one), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 277);
# 278 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step2_mult), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 278);
# 279 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_total), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 279);
# 280 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 291 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
void processResultDataLargeMatrix(const InputData &input, const ResultDataLarge &result, const unsigned
# 292 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
mat_size, const char *
# 293 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
filename, const unsigned
# 294 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
user_defined, char *exec_path)
# 295 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
{
# 296 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
const unsigned mat_size_ui = (sizeof(unsigned) * mat_size);
# 297 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
const unsigned mat_size_f = (sizeof(float) * mat_size);
# 301 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *lambda_mult = ((float *)malloc(sizeof(float) * mat_size));
# 302 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(lambda_mult, result.g_lambda_mult, sizeof(float) * mat_size, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 304);
# 305 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned *pos_mult = ((unsigned *)malloc(sizeof(unsigned) * mat_size));
# 307 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(pos_mult, result.g_pos_mult, sizeof(unsigned) * mat_size, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 309);
# 311 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned *blocks_mult_sum = ((unsigned *)malloc(sizeof(unsigned) * mat_size));
# 313 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(blocks_mult_sum, result.g_blocks_mult_sum, sizeof(unsigned) * mat_size, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 315);
# 317 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned num_one_intervals;
# 318 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_one_intervals, result.g_num_one, sizeof(unsigned), cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 320);
# 322 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned sum_blocks_mult = (mat_size - num_one_intervals);
# 327 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *left_one = ((float *)malloc(mat_size_f));
# 328 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *right_one = ((float *)malloc(mat_size_f));
# 329 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned *pos_one = ((unsigned *)malloc(mat_size_ui));
# 330 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(left_one, result.g_left_one, mat_size_f, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 331);
# 332 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(right_one, result.g_right_one, mat_size_f, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 333);
# 334 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cudaSafeCall(cudaMemcpy(pos_one, result.g_pos_one, mat_size_ui, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 335);
# 338 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *eigenvals = ((float *)malloc(mat_size_f));
# 341 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
for (unsigned i = (0); i < sum_blocks_mult; ++i) {
# 343 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(eigenvals[(pos_mult[i]) - (1)]) = (lambda_mult[i]);
# 344 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 347 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned index = (0);
# 348 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
for (unsigned i = (0); i < num_one_intervals; (++i), (++index)) {
# 350 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
(eigenvals[(pos_one[i]) - (1)]) = (left_one[i]);
# 351 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 353 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
if ((1) == user_defined) {
# 355 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
writeTridiagSymMatlab(filename, input.a, (input.b) + 1, eigenvals, mat_size);
# 357 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
} else
# 358 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
{
# 362 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float *reference = (__null);
# 363 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
unsigned input_data_size = (0);
# 365 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
char *ref_path = cutFindFilePath("reference.dat", exec_path);
# 366 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCondition((0) != ref_path, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"), 366);
# 367 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCheckError(cutReadFilef(ref_path, &reference, &input_data_size), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu", 367);
# 368 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
__cutilCondition(input_data_size == mat_size, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"), 368);
# 372 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
float tolerance = ((9.999999747e-06F) + (4.999999874e-06F));
# 374 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
if ((CUTTrue) == (cutComparefe(reference, eigenvals, mat_size, tolerance))) {
# 375 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("\nTEST PASSED.\n");
# 376 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
} else
# 377 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
{
# 378 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
printf("FAILED.\n");
# 379 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 381 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
cutFree(ref_path);
# 382 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
cutFree(reference);
# 383 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 385 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(eigenvals);
# 386 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(lambda_mult);
# 387 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(pos_mult);
# 388 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(blocks_mult_sum);
# 389 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(left_one);
# 390 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(right_one);
# 391 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
freePtr(pos_one);
# 392 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu"
}
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c" 1
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 91 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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
# 90 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 948 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 949 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 2973 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 2974 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 4683 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 5006 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 5007 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 91 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 164 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2







#pragma pack()
# 2 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00003116_00000000-3_bisect_large.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00003116_00000000-3_bisect_large.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_13$:\n"
".quad 0x33010102464c457f,0x0000000000000002,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000003e6c,0x0000000000000040,0x00380040000d010d,0x0001001000400007\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000440\n"
".quad 0x0000000000000356,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000796\n"
".quad 0x00000000000000ab,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000841\n"
".quad 0x00000000000001f8,0x0000001200000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000130,0x0000000000100006,0x0000000000000000,0x0000000000000a39\n"
".quad 0x0000000000001e38,0x1c00000a00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001fe,0x0000000000000002,0x0000000000000000,0x0000000000002871\n"
".quad 0x0000000000000038,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000172,0x0000000000000002,0x0000000000000000,0x00000000000028a9\n"
".quad 0x0000000000000190,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000001b7,0x0000000000000003,0x0000000000000000,0x0000000000002a39\n"
".quad 0x00000000000020bc,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000c1,0x0000000000100006,0x0000000000000000,0x0000000000002a39\n"
".quad 0x0000000000000460,0x1300000800000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000283,0x0000000000000002,0x0000000000000000,0x0000000000002e99\n"
".quad 0x0000000000000010,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000f7,0x0000000000000002,0x0000000000000000,0x0000000000002ea9\n"
".quad 0x00000000000000b4,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000248,0x0000000000000003,0x0000000000000000,0x0000000000002f5d\n"
".quad 0x0000000000000848,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000100006,0x0000000000000000,0x0000000000002f5d\n"
".quad 0x0000000000000de0,0x1200000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000030a,0x0000000000000002,0x0000000000000000,0x0000000000003d3d\n"
".quad 0x0000000000000028,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000007a,0x0000000000000002,0x0000000000000000,0x0000000000003d65\n"
".quad 0x0000000000000104,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000002c1,0x0000000000000003,0x0000000000000000,0x0000000000003e69\n"
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
".quad 0x00000000000de000,0x0e00030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0800030000000000,0x0000000000000000,0x0000000000046000,0x0a00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0400030000000000,0x0000000000000000\n"
".quad 0x00000000001e3800,0x0600030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0700030000000000,0x0000000000000000,0x0000000000000000,0x0500030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0b00030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0900030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0f00030000000000,0x0000000000000000,0x0000000000000000,0x0d00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0c10120000000100,0x0000000000000000\n"
".quad 0x0000000000000000,0x0810120000003f00,0x0000000000000000,0x0000000000000000\n"
".quad 0x0410120000006f00,0x0000000000000000,0x0000000000000000,0x000780a000002900\n"
".quad 0x0000031000000104,0x0007800002140500,0x00078000011409c0,0x000780080c9601c0\n"
".quad 0x3f078004004801e0,0x3f078004084c01e4,0x00078008089401e4,0x000047200a943de0\n"
".quad 0x0000c7200e943900,0x00078008189c0100,0x03c7801000f811e0,0x03c7801000f80d06\n"
".quad 0x000000861ffe0304,0x0087d0307c140100,0x0147c8a00001fd64,0x000000a001f0030c\n"
".quad 0x0011001001f00300,0x00c7801000120100,0x2007800000480144,0x00c78010001401e4\n"
".quad 0x20078000084c0144,0x00c78010001601e4,0x0007800008940144,0x00c78010001801e0\n"
".quad 0x00078000189c0144,0x00000310018001e0,0x3f07800010500100,0x20078000105201e4\n"
".quad 0x20078000105401e4,0x20078000105601e4,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x000047200a944900,0x0000c7200e944500,0x000067200b944100,0x0000032024940100\n"
".quad 0x0000432026940500,0x0007800002001100,0x0007800002020dc0,0x10078030011431c0\n"
".quad 0x1007803002142dc4,0x200780a0004235c4,0x03c7801000f85d04,0x03c7801000f80106\n"
".quad 0x03c7801000f80504,0x03c7801000f80906,0x000780d041480504,0x20c7d8340ac1fd20\n"
".quad 0x000000a005700364,0x0012801005700300,0x00c7841000000500,0x2347d8bc01c1fd44\n"
".quad 0x00c7841000000960,0x00c7801c00000544,0x0007800001240544,0x200780a4004011c0\n"
".quad 0x0007800001220504,0x200780a400400dc0,0x0011001005000304,0x2047e8bc7cc1fd00\n"
".quad 0x000000a004500360,0x2047dcb07cc1fd00,0x0021001004300360,0x03c7801000f81500\n"
".quad 0x40d2801000001506,0x0007801004500324,0x0000031001801500,0x03d2801000f81500\n"
".quad 0x00c7861000000504,0x00c7841000000144,0x204780bc00c00544,0x00c7841000000908\n"
".quad 0x0147d8a0000bfd44,0xf00003e00002012c,0x0260141d00e00403,0x00c78410000009bd\n"
".quad 0x401e00c0810a0144,0x3f07800010560100,0x00078010057003e4,0x0007800001220500\n"
".quad 0x200780a400400dc0,0x0007800001240504,0x200780a4004011c0,0x0107802040061504\n"
".quad 0x40c7d830800bfd04,0x3f15000010560164,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x000780d041580500,0x6087d83480c1fd20,0x0012801019200364,0x2087d8307cd1fd00\n"
".quad 0x00c7801000101964,0x0012801008e00344,0x000780d041480500,0x2107d8340ac1fd20\n"
".quad 0x03c7801000f82564,0xf800031000801d04,0x03c7801000f81503,0x000000861ffe0306\n"
".quad 0x0287802000122100,0x20c7e83008d1fd04,0x000000a007100364,0x0022801007100300\n"
".quad 0x1007803002124d00,0x13e84c2113ec20c4,0x13964c2008962021,0xc00780d00e264d20\n"
".quad 0xffffff203c902180,0xc00780d00e10210f,0x24c7840000000180,0x2207800c000001e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x000000a008900300,0x0011001008900300\n"
".quad 0x0007e0300d0c2100,0x00210010089003a4,0x1007803002105100,0x03c7801000f84dc4\n"
".quad 0x0007800000260504,0x000780d4012009c0,0x200780b800c05520,0x000780d421300508\n"
".quad 0x0860581500e02020,0x5107e8b0820ffdc5,0x03c78010000e2160,0x402680c0892c5906\n"
".quad 0x402680c0890e2100,0x0007809000101d00,0x054780e0072c1d00,0x004780b07c0e2104\n"
".quad 0x02078020400a1560,0x0000032004a64d04,0x0147e8301427fd00,0x0022801007900364\n"
".quad 0x02478220001a2500,0x2107e83009d1fd04,0x03478020400c1964,0x0022801006400304\n"
".quad 0x0007801008f00300,0x03c7801000f81500,0x000000861ffe0304,0x000780d041480500\n"
".quad 0x20c7d8340ac1fd20,0x000000a011c00364,0x0012801011c00300,0x0347d8b00203fd00\n"
".quad 0x000780a0000c2160,0x000780a000101904,0x0011001011400304,0x000780a000141d00\n"
".quad 0x0147d030070c4d04,0x01478030080e2564,0x400780d080264d64,0x014780a000122504\n"
".quad 0x0007e8d00927fd2c,0x104780a000004d04,0x002100100ca003c4,0x100780b013042100\n"
".quad 0x200780c008da4d80,0x32d2e71032802100,0x86544b1004802509,0x400780a000265103\n"
".quad 0x008780b000004dc4,0x000780e008282108,0x500780a0002651c0,0x00078000012405c4\n"
".quad 0x03078004000001c0,0x00c7d8e00829fde0,0x00078000012205e0,0x03878004000001c0\n"
".quad 0x000000a00c2003e0,0x001100100c000300,0x0047e0b07c041900,0x0047f8b07c01fd60\n"
".quad 0x000000a00b900360,0x0147d8a0000dfd00,0x003100100b70030c,0x03c7801000f81d00\n"
".quad 0x40e2801000001d06,0x000780100b900324,0x0000031001801d00,0x03d2801000f81d00\n"
".quad 0x008782b000001904,0x0147d8a0000ffd00,0xf00003c0000c192c,0x409980e081261903\n"
".quad 0x2187840000000100,0x2187800c000001e4,0x000780100c2003e4,0x2087840000000100\n"
".quad 0x2007800c000001e4,0x000002f0000001e4,0x00000310010031e0,0x0007800001200500\n"
".quad 0x03078004000201c0,0x00000310018019e0,0x2187800010500100,0x0000031001805de4\n"
".quad 0x0007801011c00300,0x0000031000004900,0x0007800001200500,0x04878004000201c0\n"
".quad 0x000000a0112003e0,0x001100100f100300,0x100780b013042100,0x200780c008da4d80\n"
".quad 0x32d2e71032802100,0x86544b1004802509,0x400780a000265103,0x008780b000004dc4\n"
".quad 0x000780e008282108,0x500780a0002651c0,0x00078000012405c4,0x03078004000001c0\n"
".quad 0x00c7d8e00829fde0,0x00078000012205e0,0x03878004000001c0,0x001100100ee003e0\n"
".quad 0x0047e0b07c041900,0x0047f8b07c01fd60,0x000000a00e700360,0x0147d8a0000dfd00\n"
".quad 0x003100100e50030c,0x03c7801000f81d00,0x40e2801000001d04,0x000780100e700324\n"
".quad 0x0000031001801d00,0x03d2801000f81d00,0x008782b000001904,0x0147d8a0000ffd00\n"
".quad 0xf00003c0000c192c,0x409980e081261903,0x2187840000000100,0x2187800c000001e4\n"
".quad 0x00078010112003e4,0x2087840000000100,0x2007800c000001e4,0x00078010112003e4\n"
".quad 0x100780b013021900,0x200780c006da1980,0x32d2e71032805100,0x86544b1004805509\n"
".quad 0x400780a0000c5903,0x000780b0000219c4,0x000780e0142c5108,0x500780a0000c59c0\n"
".quad 0x00078000012405c4,0x03878004000001c0,0x00c7d8e0142dfde0,0x00078000012205e0\n"
".quad 0x04078004000001c0,0x00110010110003e0,0x0047e0b07c001d00,0x0047f8b07c03fd60\n"
".quad 0x000000a010900360,0x0147d8a0000ffd00,0x003100101070030c,0x03c7801000f82100\n"
".quad 0x40e2801000002106,0x0007801010900324,0x0000031001802100,0x03d2801000f82100\n"
".quad 0x004782b000001d04,0x0147d8a00011fd00,0xf00003c0000e1d2c,0x401980e0810c1d03\n"
".quad 0x21c7840000000100,0x21c7800c000001e4,0x00078010112003e4,0x2007840000000100\n"
".quad 0x2047800c000001e4,0x03c7821000f85de4,0x0007801011c00304,0x0007800002140500\n"
".quad 0x20878004004801c0,0x20878004084c01e4,0x00078000011e05e4,0x03078004000001c0\n"
".quad 0x00078000011c05e0,0x04078004000001c0,0x03c7801000f85de0,0x000002f000000106\n"
".quad 0x000000861ffe03e0,0x000780d041400500,0x2087d8347cc1fd20,0x0012801016e00364\n"
".quad 0x000780d041500500,0x3007803401c02520,0x00c78014000021e4,0x00c7d8307c13fd44\n"
".quad 0x001280101450036c,0x0000031001801900,0x000000861ffe0300,0x00c7d8300a13fd00\n"
".quad 0x000000a014000364,0x0012801014000300,0x0000032002981d00,0x000780400d1c4d00\n"
".quad 0x04c780600c1e4d00,0x1007803010264d00,0x04c7d0600c1c1dc4,0xffffff203f8e4d00\n"
".quad 0x0000032001981d0f,0x03d5001000f84d00,0x0007800001260504,0x000780400e1a4dc0\n"
".quad 0x04c780600f184d00,0x1007803010264d00,0x04c7d0600e181dc4,0xffffff203f8e1d00\n"
".quad 0x03d5001000f81d0f,0x00078000010e0906,0x000780d8193009c0,0x0047801800003920\n"
".quad 0x000780d419300940,0x2387802800403920,0x038780040c980100,0x10078230011225e0\n"
".quad 0x0107d8307c13fdec,0x10078030010c196c,0x00128010127003c4,0x0007801014600300\n"
".quad 0x0000031001801900,0x40c7d8308311fd00,0x0012801015d00364,0x0000031002801d00\n"
".quad 0x10078030010c1900,0x000000861ffe03e4,0xffffff203f8e2500,0x0187d8300915fd0f\n"
".quad 0x000000a015a00364,0x0012801015a00300,0x0000032001942500,0x01078040090c2500\n"
".quad 0x10078030010c4d00,0x00078000011205e4,0x02478020002625c0,0x000780d4192c0904\n"
".quad 0x0007800001120520,0x00478018000049c0,0x000780d4192c0940,0x2487802800404920\n"
".quad 0x048780040c960100,0x10078230010e1de0,0x0047d830080ffdc4,0x0012801014900364\n"
".quad 0x000000861ffe0300,0x4087d830802ffd00,0x000780d041480564,0x2112d8340ac1fd20\n"
".quad 0x000000a016d00364,0x0011001016d00300,0x000780d041480900,0x0007800001200520\n"
".quad 0x200780a4004019c0,0x2187802800c01904,0x00078000020c0504,0x20078004004801c0\n"
".quad 0x20478004084c01e4,0x00078000010c05e4,0x02878004089401c0,0x01878004189c01e0\n"
".quad 0x000002f0000001e0,0x000000861ffe03e0,0x000000a018d00300,0x0001001018d00300\n"
".quad 0x000780d041480500,0x2007800401c00920,0x000780d8192c09c0,0x200780a800401520\n"
".quad 0x2147802400c01504,0xffffff203f8a1904,0x0007d8d0060bfd0f,0x2147800010520104\n"
".quad 0x00150010189003e4,0x014780a0000a1500,0x5047d8b0840bfd44,0x104780a0000a1960\n"
".quad 0x401680c08a0a15c4,0x40d6801000161d00,0x03d1001000f81d24,0x10078030170a1504\n"
".quad 0x400780d0850a15ec,0x4087d830850bfd04,0x01c78020400a1564,0x009158b07c0dfd04\n"
".quad 0xfffffb20028a1960,0x000003100180150f,0x03d6801000f81900,0x00078030060a1506\n"
".quad 0x21478000105401c4,0x00000310018015e4,0x3f07800010500100,0x21478000105601e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x000780d041500500,0x2107d8340dc1fd20\n"
".quad 0x0015001002f00364,0x000000861ffe0300,0x00078000011e0500,0x200780a400400dc0\n"
".quad 0x000780d041480504,0x02878020001a1120,0x20c7d83404c1fd04,0x00078000011c0564\n"
".quad 0x200780a4004015c0,0x0007800001080904,0x001500d8112805c0,0x201500a400406120\n"
".quad 0x001500d831380504,0x201500a400406520,0x4046801000300104,0x0006800008940120\n"
".quad 0x00068000189c01e0,0x000000861ffe03e0,0x00c78020400a1900,0x4087d030800c0104\n"
".quad 0x400780d080000164,0x41478030800c0904,0x014780a000000964,0x400780d080040108\n"
".quad 0x0007800001240504,0x00878004000201c0,0x014780a0000009e0,0x000780d0020c0108\n"
".quad 0x0007800001220504,0x00878004000201c0,0x00078000012005e0,0x00078004000201c0\n"
".quad 0x00000310000001e0,0x0007800001140500,0x000780041c9e01c0,0x000780d0414805e0\n"
".quad 0x20c7e83404c1fd20,0x000000a01d400364,0x0007800001140500,0x000780d4393c05c0\n"
".quad 0x0007800400001d20,0x000780d8393c0540,0x0007800400002120,0x002280101cd00340\n"
".quad 0x0607802040322500,0x4087803080120104,0x400780d080001964,0x4147803080120904\n"
".quad 0x0007800001080564,0x014780a0000c09c0,0x400780d080040108,0x0087800408960104\n"
".quad 0x014780a0000009e0,0x000780d002120108,0x00878004189e0104,0x000780040c9801e0\n"
".quad 0x00000310000001e0,0x0007800000100500,0x00078004000001c0,0x000780101d4003e0\n"
".quad 0x4107e8308609fd00,0x0025000001080564,0x40650010003001c0,0x002500040c980120\n"
".quad 0x00250000001005e0,0x00250004000001c0,0x03c7801000f819e0,0x000782d041500504\n"
".quad 0x3007803401c02520,0x00c78014000001e4,0x00c7e8307c13fd44,0x002280102420036c\n"
".quad 0x0000031001800500,0x000000861ffe0300,0x00c7e8300a13fd00,0x000000a023d00364\n"
".quad 0x0022801023d00300,0x0000032001980900,0x0007804004063500,0x0347806005043500\n"
".quad 0x10078030101a3500,0x03478060040435c4,0x00078000011a0900,0x000780d8112805c0\n"
".quad 0x0047801400007120,0x0000032002980940,0x0007804003083d00,0x03c78060020a3d00\n"
".quad 0x10078030101e3d00,0x03c7806002084dc4,0x0007800001260500,0x000780d4112809c0\n"
".quad 0x0007800800000920,0x2707802800401140,0x0107800408940100,0x00078000011a09e0\n"
".quad 0x000780d8313809c0,0x0007800800000920,0x0047801800001140,0x000780d431380940\n"
".quad 0x0007800800003920,0x2107802800401140,0x01078004189c0100,0x00078000011a09e0\n"
".quad 0x000780d8393809c0,0x0007800800000920,0x200780a800400940,0x0000e7200f9a3d04\n"
".quad 0x0000e7200fa63900,0x4147e8308005fd00,0x0022801020700364,0x00078000011c0900\n"
".quad 0x00078008000009c0,0xffffff203e840940,0x000780000004090f,0x200780a8004009c0\n"
".quad 0x4087e8308005fd04,0x0022801023d00364,0x00078000011e0900,0x00078008000009c0\n"
".quad 0xffffff203e840940,0x000780000004090f,0x200780a8004009c0,0x4147e8308005fd04\n"
".quad 0x0022801021500364,0x00078000011c0900,0x00078008000009c0,0xffffff203e840940\n"
".quad 0x000780000004050f,0x00000310010011c0,0x0107800400000100,0x0007801023d003e0\n"
".quad 0x00078000011c0900,0x00078008000009c0,0xffffff203e840940,0x000780000004090f\n"
".quad 0x200780a8004009c0,0x4147e8308005fd04,0x0022801022300364,0x00078000011e0900\n"
".quad 0x00078008000009c0,0xffffff203e840940,0x000780000004050f,0x00000310010011c0\n"
".quad 0x0107800400000100,0x0007801023d003e0,0x00078000011a0900,0x000780d8192c09c0\n"
".quad 0x0007800800000920,0x200780a800400940,0x000780d4192c0904,0x0007800800004d20\n"
".quad 0x200780a800404d40,0x04c7802000040904,0x40c7e8308705fd04,0x0022801023900364\n"
".quad 0x00078000011e0900,0x00078008000009c0,0x00078000011c0940,0x00078008000039c0\n"
".quad 0xffffff203e840940,0x000780000004050f,0x00000310010069c0,0x0687800400000100\n"
".quad 0xffffff203e9c09e0,0x000780000004050f,0x06878004000001c0,0x0007801023d003e0\n"
".quad 0x010780040c960100,0x00000310000011e0,0x00078000011a0900,0x010780080c9601c0\n"
".quad 0x10078230011225e0,0x0107e8307c13fdec,0x100780300102056c,0x002280101da003c4\n"
".quad 0x0007801024300300,0x0000031001800500,0x40c7e8308301fd00,0x0022801026000364\n"
".quad 0x0000031002802500,0x1007803001020500,0x000000861ffe03e4,0xffffff203f920900\n"
".quad 0x0187e8300215fd0f,0x000000a025d00364,0x0022801025d00300,0x0000032001940900\n"
".quad 0x0107804002023500,0x1007803001020900,0x03478020000409e4,0x00078000011a0504\n"
".quad 0x000780d4112805c0,0x0007800001040920,0x00478014000011c0,0x000780d811280540\n"
".quad 0x2107802400401120,0x0107800808940100,0x00078000011a05e0,0x000780d4313805c0\n"
".quad 0x0047801400001120,0x000780d831380540,0x2107802400401120,0x01078008189c0100\n"
".quad 0x10078230011225e0,0x0047e8300013fdc4,0x0022801024600364,0x000780d041480500\n"
".quad 0x3007803401c23520,0x00c7e8307c1bfde4,0x00c780140002016c,0x2007800401c00544\n"
".quad 0x00078004000009c0,0x0022801027c00340,0x0000031001802500,0x000000861ffe0300\n"
".quad 0x00c7e8300a1bfd00,0x000000a027700364,0x0022801027700300,0x0000032001980500\n"
".quad 0x0107804001123900,0x0000032002980500,0x00078000011c0500,0x01078040090205c0\n"
".quad 0x000780d4192c0900,0x0007800001020520,0x00478018000009c0,0x000780d4192c0940\n"
".quad 0x2087802800400920,0x008780040c960100,0x10078230011a35e0,0x0107e8307c1bfdec\n"
".quad 0x100780300112256c,0x00228010268003c4,0x0007801027d00300,0x0000031001802500\n"
".quad 0xffffff203f803500,0x40c7e830831bfd0f,0x0022801029500364,0x0000031002803900\n"
".quad 0x1007803001122500,0x000000861ffe03e4,0xffffff203f9c0500,0x0187e8300115fd0f\n"
".quad 0x000000a029200364,0x0022801029200300,0x0000032001940500,0x0107804001123d00\n"
".quad 0x1007803001120500,0x00078000011e05e4,0x03c78020000205c0,0x000780d4192c0904\n"
".quad 0x0007800001020520,0x00478018000009c0,0x000780d4192c0940,0x2087802800400920\n"
".quad 0x008780040c960100,0x10078230011c39e0,0x0047e8300d1dfdc4,0x0022801028100364\n"
".quad 0x000000861ffe0300,0x000000a02a100300,0x000100102a100300,0x0007800001000900\n"
".quad 0x000780d8393805c0,0x0047801400000120,0x0007800000040540,0x000780041c9c01c0\n"
".quad 0x000780d8192c05e0,0x0047801400000120,0x0007800000040540,0x000780040c9601c0\n"
".quad 0x000002f0000001e0,0x000000861ffe03e0,0x00078000000e0500,0x200780a4004001c0\n"
".quad 0x4147e8308001fd04,0x0025000001220564,0x202500a4004201c0,0x0025000001200504\n"
".quad 0x00650014000209c0,0x4025002100002540,0x4062801000300904,0x03e2801000f82520\n"
".quad 0x0007800000100506,0x200780a4004001c0,0x4147e8308001fd04,0x0025000001080564\n"
".quad 0x002500d4313c09c0,0x202500a800400120,0x002500d419300504,0x0065001400000d20\n"
".quad 0x4025002100002140,0x4062801000300d04,0x03e2801000f82120,0x000780d041500504\n"
".quad 0x20c7e83404c1fd20,0x0007800001140564,0x000780d4393c05c0,0x0047801400000120\n"
".quad 0x0007800001200540,0x00078004000201c0,0x00078000011405e0,0x000780d4393c05c0\n"
".quad 0x0007800400003520,0x0025000001080540,0x002500d4393c09c0,0x0065001800000120\n"
".quad 0x002500040c980140,0x000780d0415005e0,0x3007803401c03920,0x00c78014000001e4\n"
".quad 0x00c7e8307c1dfd44,0x002280102e00036c,0x0000031001801d00,0x000000861ffe0300\n"
".quad 0x00c7e8300a1dfd00,0x000000a02db00364,0x002280102db00300,0x0000032001980900\n"
".quad 0x01078040020e3d00,0x0000032002980900,0x00078000011e0500,0x01078040070409c0\n"
".quad 0x000780d4192c0900,0x0007800001040520,0x00478018000011c0,0x000780d4192c0940\n"
".quad 0x2107802800401120,0x010780040c960100,0x10078230011c39e0,0x0107e8307c1dfdec\n"
".quad 0x10078030010e1d6c,0x002280102cc003c4,0x000780102e100300,0x0000031001801d00\n"
".quad 0x40c7e8308301fd00,0x002280102f800364,0x0000031002803100,0x10078030010e1d00\n"
".quad 0x000000861ffe03e4,0xffffff203f980900,0x0187e8300215fd0f,0x000000a02f500364\n"
".quad 0x002280102f500300,0x0000032001940900,0x01078040020e3900,0x10078030010e0900\n"
".quad 0x00078000011c05e4,0x03878020000409c0,0x000780d4192c0904,0x0007800001040520\n"
".quad 0x00478018000011c0,0x000780d4192c0940,0x2107802800401120,0x010780040c960100\n"
".quad 0x10078230011831e0,0x0047e8300019fdc4,0x002280102e400364,0x000000861ffe0300\n"
".quad 0x000000a030a00300,0x0001001030a00300,0x000780d041480500,0x2007800401c00520\n"
".quad 0x000780d4192c09c0,0x200780a800403120,0x000780d411280904,0x2307800010580120\n"
".quad 0x200780a800401de4,0x000780d431380504,0x21c78000105a0120,0x200780a4004009e4\n"
".quad 0x00c78010001c0104,0xc00780d00e001d44,0x00c78010002001a0,0x20878000105c0144\n"
".quad 0xc00780d00e0031e4,0x000002f0000001a0,0x000000861ffe03e0,0x000780d041480500\n"
".quad 0x2107f03404c01d20,0x00c7841000000164,0x00c7801c00000944,0x0147e8a0000ffd44\n"
".quad 0x003680000208050c,0x003680d4012009c0,0x00f6801800006920,0x003680d421300544\n"
".quad 0x00f6801400006d20,0x000000a031f00344,0x0011001031b00300,0x0007800001240500\n"
".quad 0x200780a4004031c0,0x0007801031f00304,0x000780d041680900,0x0007800001220520\n"
".quad 0x200780a400401dc0,0x21c7802800c03104,0x0147f2307c121d04,0x0147d8a0000ffd64\n"
".quad 0x003680000120050c,0x00768014000039c0,0x4071001000303940,0x000000a033a00320\n"
".quad 0x0021001033800300,0x000000a033100300,0x0007800001080500,0x4147f830800dfdc0\n"
".quad 0x0032801032d00364,0x000780d411280900,0x200780a800401920,0x0007801033100304\n"
".quad 0x000780d431380900,0x200780a800401920,0x000780d041680904,0x2187802800c01920\n"
".quad 0x0087fa307c11fd04,0x0032801033600364,0x000780d4192c0500,0x0047801400003d20\n"
".quad 0x0007801033a00340,0x0000031000003d00,0x0007801033a00300,0x0000031000003d00\n"
".quad 0x03c7801000f81900,0x000002f000000104,0x000000861ffe03e0,0x0007800002180500\n"
".quad 0x20078004004801c0,0x20878004084c01e4,0x400780d0880601e4,0x0007800001180504\n"
".quad 0x400780d0880a09c0,0x0007800408940104,0x01078004189c01e0,0x001680a0001c09e0\n"
".quad 0x4356802100120104,0x0016800001040504,0x001680040c9801c0,0x009680041ca001e0\n"
".quad 0x000000a0359003e0,0x0021001035900300,0x00078000020c0500,0x26878004004801c0\n"
".quad 0x26c78004084c01e4,0x400780d0883001e4,0x00078000010c0504,0x400780d0883209c0\n"
".quad 0x0007800408940104,0x01078004189c01e0,0x0087d8307c11fde0,0x001500a0001e0964\n"
".quad 0x4355002100100104,0x0015000001040504,0x001500040c9801c0,0x00d500041ca001e0\n"
".quad 0x000002f0000001e0,0x000000861ffe03e0,0x000780d041600500,0x00c6801400040120\n"
".quad 0x2006800401c00544,0x000680040c9601c0,0x40468010003001e0,0x000680001c9e0120\n"
".quad 0x000000861ffe03e0,0x000780d041680500,0x20c7c8340ac1fd20,0x000000a038200364\n"
".quad 0x0002801037100300,0x00c7841000000100,0x22c7802000e40544,0xc00780d00e020104\n"
".quad 0x00c7801c000001a0,0x22c7802000e80544,0xc00780d00e020104,0x00078000012205a0\n"
".quad 0x200780a4004001c0,0x22c7802000ec0504,0xc00780d00e020104,0x00078010382003a0\n"
".quad 0x000780d041680500,0x2287803400c00520,0x00c7841000000104,0x1007803002020944\n"
".quad 0x2087802000f005c4,0xc00780d00e020104,0x00c7801c000001a0,0x2087802000f40544\n"
".quad 0xc00780d00e020104,0x00078000012405a0,0x200780a4004001c0,0x2087802000f80504\n"
".quad 0xc00780d00e020104,0x00078000012205a0,0x200780a4004001c0,0x2087802000fc0504\n"
".quad 0xc00780d00e020104,0x000782d0414805a0,0x20c7c83404c1fd20,0x000000a03ab00364\n"
".quad 0x000280103ab00300,0x0000c7200e880100,0x000780d041680500,0x0000032024880520\n"
".quad 0x0000432026880900,0x0007800001000d00,0x20c7c83404c1fdc0,0x0007800002020964\n"
".quad 0x00078000020405c0,0x10078030020809c0,0x0002801039a003c4,0x00c7801800000100\n"
".quad 0x2087802000e40544,0xc00780d00e020104,0x00c78014000001a0,0x2087802000e80544\n"
".quad 0xc00780d00e020104,0x2087802000ec05a0,0x200780ac00400104,0xc00780d00e020104\n"
".quad 0x000780103ab003a0,0x000780d041681100,0x2107843000c00520,0x00c7801800000104\n"
".quad 0x1007803002020944,0x2087802000f005c4,0xc00780d00e020104,0x00c78014000001a0\n"
".quad 0x2087802000f40544,0x0007800001080504,0x000780d4112805c0,0xc00780d00e020120\n"
".quad 0x200780a4004001a0,0x2087802000f80504,0xc00780d00e020104,0x200780ac004001a0\n"
".quad 0x2087802000fc0504,0xc00780d00e020104,0x000002f0000001a0,0x000780d0416005e0\n"
".quad 0x2047c8340ac1fd20,0x000000a03b900364,0x000280103b900300,0x000780d001000500\n"
".quad 0x0007800001200920,0x200780a8004001c0,0x22c7802400c00504,0xc00780d00e020104\n"
".quad 0x00078000001a09a0,0x200780a8004001c0,0x22c7802400c40504,0xc00780d00e020104\n"
".quad 0x000782d0416005a0,0x2047c83404c1fd20,0x0002803000000364,0x0007800001080900\n"
".quad 0x000780d0010005c0,0x1007803002080920,0x000780d8192c0dc4,0x2087802400c00520\n"
".quad 0x200780ac00400104,0x000780d8393c0904,0xc00780d00e020120,0x2087802400c405a0\n"
".quad 0x200780a800400104,0xc00781d00e020104,0x00000000000001a0,0x0000027e8000003f\n"
".quad 0x0000ff0080000000,0x0001000000020000,0x8000000000ffff00,0x0000184b8000003e\n"
".quad 0xffffff0000000000,0x000000004c0b04ff,0x0000100000000800,0x0000180000001400\n"
".quad 0x0000200000001c00,0x0000280000002400,0x0000380000003000,0x0000480000004000\n"
".quad 0x0000580000005000,0x0000680000006000,0x0000780000007000,0x0c17040080180300\n"
".quad 0x780012ffffffff00,0x0c17040023f00000,0x700011ffffffff00,0x0c17040023f00000\n"
".quad 0x680010ffffffff00,0x0c17040023f00000,0x60000fffffffff00,0x0c17040023f00000\n"
".quad 0x58000effffffff00,0x0c17040023f00000,0x50000dffffffff00,0x0c17040023f00000\n"
".quad 0x48000cffffffff00,0x0c17040023f00000,0x40000bffffffff00,0x0c17040023f00000\n"
".quad 0x38000affffffff00,0x0c17040023f00000,0x300009ffffffff00,0x0c17040023f00000\n"
".quad 0x280008ffffffff00,0x0c17040023f00000,0x240007ffffffff00,0x0c17040013f00000\n"
".quad 0x200006ffffffff00,0x0c17040013f00000,0x1c0005ffffffff00,0x0c17040013f00000\n"
".quad 0x180004ffffffff00,0x0c17040013f00000,0x140003ffffffff00,0x0c17040013f00000\n"
".quad 0x100002ffffffff00,0x0c17040013f00000,0x080001ffffffff00,0x0c17040023f00000\n"
".quad 0x000000ffffffff00,0x080d040023f00000,0x0000200021010800,0x03c7801000000900\n"
".quad 0x200780a000421904,0x000780a000082504,0x029228410c2c0804,0x2107d0300ad20920\n"
".quad 0x0147c8a00005fd64,0x000000a000e0030c,0x0011001000e00300,0x1007803002140100\n"
".quad 0x00f8082100f404c4,0x2007802000dc0d21,0xc00780d00e020104,0xc00780d00e040580\n"
".quad 0xc00780d00e062180,0x0147da307c13fd80,0x3f15000004220164,0x000000861ffe03e4\n"
".quad 0x03c7801000f82d00,0x2107d8307cd1fd06,0x03c7801000f80964,0x03c7801000f83104\n"
".quad 0x40c2801000002d06,0x008780307c180d24,0x400780d080061164,0x0000031001800d04\n"
".quad 0x0007e0d00b083500,0x20c7800004220104,0x000000a002b003e4,0x0021001002b00300\n"
".quad 0x000000a002600300,0x0047f8b07c03fd00,0x0047e8b07c01fd60,0x0031001002400360\n"
".quad 0x03c7801000f80900,0x40e2801000000904,0x0007801002600324,0x0000031001800900\n"
".quad 0x03e2801000f80900,0x000782b000021104,0x0147e8a00005fd00,0x000780b000020d2c\n"
".quad 0xf00003c000080908,0x402980e081060903,0x00c7821000100d00,0x0011001005d00344\n"
".quad 0x000000a005b00300,0x03c7801000f83900,0x03c7801000f83d06,0xf800031000801104\n"
".quad 0x000000861ffe0303,0x02478020001c1500,0x20c7e83005d1fd04,0x000000a004000364\n"
".quad 0x0022801004000300,0x10078030021c1d00,0x10078030021215c4,0x07ec442107e840c4\n"
".quad 0x118a1420108a1c21,0x0007800002120520,0xffffff203c8a15c0,0xc00780d00e0e1d0f\n"
".quad 0xc00780d00e0a1580,0x21c7800402220180,0x21478004002201e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x000000a005700300,0x0001001005700300,0x0007e03006061500\n"
".quad 0x00210010057003a4,0x10078030020a4500,0x03c7801000f841c4,0x0007800000200506\n"
".quad 0x5107e8b08209fdc0,0x000780d408880960,0x00c7801400221d20,0x4260481000881444\n"
".quad 0x200780c407e21db9,0x402680c0830e1d00,0x402680c083081500,0x00078090000a1100\n"
".quad 0x048780e0040e1100,0x004780b07c081504,0x01478020401e3d60,0x0000032004a04104\n"
".quad 0x0147e8301121fd00,0x0022801004800364,0x03878220000c3900,0x2107e8300ed1fd04\n"
".quad 0x0187802040060d64,0x0022801003100304,0x000002f000000100,0x0007801005e003e0\n"
".quad 0x03c7801000f83d00,0x000000861ffe0306,0x0087e8307c1bfd00,0x000000a00800036c\n"
".quad 0x0022801008000300,0x0147e8300f11fd00,0x03e5001000040d64,0x03e5001000040504\n"
".quad 0x03e5001000001106,0x03e2801000041104,0x03e2801000040106,0x03e2801000020d04\n"
".quad 0x180780b004061506,0x200780c005e01d80,0x010780b000061500,0x200780b007e01d08\n"
".quad 0x0047e8b0070bfda0,0x0021001007f00360,0x0047f8b07c07fd00,0x000000a007800360\n"
".quad 0x0047e8b07c09fd00,0x0031001007600360,0x03c7801000f80100,0x40e2801000000104\n"
".quad 0x0007801007800324,0x0000031001800100,0x03e2801000f80100,0x010782b000060504\n"
".quad 0x0147e8a00001fd00,0xf00003c00002052c,0x412980e0810a0503,0x0000031001803100\n"
".quad 0x03c7801000020100,0x0007801008000304,0x3f07800004220100,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x000780d010880500,0x6087e83480c1fd20,0x0022801008700364\n"
".quad 0x000000861ffe0300,0x0007801001600300,0x000000861ffe0300,0x0001003000000300\n"
".quad 0x1007803002140500,0x2047802000d405c4,0xc00781d00e020104,0x00000000000001a0\n"
".quad 0x8000007e8000003f,0x00000000200b043e,0x0000100000000800,0x0000180000001400\n"
".quad 0x0000280000002000,0x3418030000003000,0xffffff000c170400,0x13f00000300007ff\n"
".quad 0xffffff000c170400,0x23f00000280006ff,0xffffff000c170400,0x23f00000200005ff\n"
".quad 0xffffff000c170400,0x23f00000180004ff,0xffffff000c170400,0x13f00000140003ff\n"
".quad 0xffffff000c170400,0x13f00000100002ff,0xffffff000c170400,0x23f00000080001ff\n"
".quad 0xffffff000c170400,0x23f00000000000ff,0x22011000080d0400,0x0000150000002000\n"
".quad 0x027003040007d0a0,0x7c0bfd00000000a0,0x027003640087c830,0x00f4000000168010\n"
".quad 0x042c011100f81811,0x0e001d0000000361,0x042c1980c00780d0,0x0e0c190000000361\n"
".quad 0x04800180c00780d0,0x0e00010000000320,0x14380180c00780d0,0x143a01e421c78000\n"
".quad 0x000e01e420078000,0x143c010400078030,0x3f8019e421878000,0x143e010fffffff20\n"
".quad 0x0601fde420078000,0x003601040007d8d0,0x023003e43f078000,0x0000010000150010\n"
".quad 0x8101fd44014780a0,0x000019605047d8b0,0x870001c4104780a0,0x00101d00401680c0\n"
".quad 0x00f81d2440d68010,0x1700010603d10010,0x820001ec10078030,0x8201fd04400780d0\n"
".quad 0x400001644087d830,0x7c0dfd0401c78020,0x02800160009158b0,0x0180190ffffffb20\n"
".quad 0x00f8010000000310,0x000c010403d68010,0x144001c400078030,0x018001e420078000\n"
".quad 0x1442010000000310,0x144401e420078000,0x000001e43f078000,0x1ffe03e0000002f0\n"
".quad 0x50f8050000000086,0x05c1fd20000780d0,0x03d0036420c7d834,0x03d00300000000a0\n"
".quad 0x50e0050000128010,0x00c00120000780d0,0x0200010421478024,0x020a05c410078030\n"
".quad 0x00dc19c000078000,0x0e0c210420078020,0x00e01980c00780d0,0x0e0c1d0420078020\n"
".quad 0x00e41980c00780d0,0x0e0c190420078020,0x00e80180c00780d0,0x0e00010420078020\n"
".quad 0x0c380180c00780d0,0x043801e422078004,0x103801e421c78004,0x083801e421878004\n"
".quad 0x000001e420078004,0x1ffe03e0000002f0,0x00f8310000000086,0x00f8010603c78010\n"
".quad 0x50f8050403c78010,0x05c1fd20000780d0,0x06f0036420c7d834,0x06f00300000000a0\n"
".quad 0x020a050000128010,0x1c8a05c000078000,0x40e0110000006320,0x02020920000780d4\n"
".quad 0x10e00dc000078000,0x00000d20000780d4,0x20e0114400c78410,0x1c8a0920000780d4\n"
".quad 0x30e0050000002320,0x00000520000780d4,0x0000114400c7801c,0x0204114400c78410\n"
".quad 0x1c8a1dc000078000,0x01c1fd0000008320,0x1c8a19602347d8b4,0x0000090000004320\n"
".quad 0x020e0d4400c7801c,0x000005c000078000,0x020c054400c78014,0x06c003c000078000\n"
".quad 0x7cc1fd0000110010,0x062003602047ecb0,0x7cc1fd00000000a0,0x060003602047d8b8\n"
".quad 0x00f8210000210010,0x0006210603c78010,0x0620032440d28010,0x0180210000078010\n"
".quad 0x00f8210000000310,0x0000010403d28010,0x00001d4400c78218,0x00c0014400c78018\n"
".quad 0x00001908200784b0,0x0011fd4400c78410,0x8400012c0147d8a0,0x00c0190041c780e0\n"
".quad 0x840c0100218780b8,0x14420100401e00c0,0x06f003e43f078000,0x00e0180000078010\n"
".quad 0x830dfd2546e0181d,0x1442016440c7d830,0x000001e43f150000,0x1ffe03e0000002f0\n"
".quad 0x5108050000000086,0x83c1fd20000780d0,0x1ad003646087d834,0x7cd1fd0000128010\n"
".quad 0x001019642087d830,0x0a90034400c78010,0x50f8050000128010,0x020a3520000780d0\n"
".quad 0x004229c410078030,0x00f83904200780a0,0x00f82d0403c78010,0x00801d0603c78010\n"
".quad 0x05c1fd03f8000310,0x1ffe03642107d834,0x001c210000000086,0x08d1fd0401478020\n"
".quad 0x08c0036420c7e830,0x08c00300000000a0,0x021c210000228010,0x08ec24c410078030\n"
".quad 0x099a3c2108e82021,0x0e102520089a2020,0x001a0580c00780d0,0x3c9e21c000078000\n"
".quad 0x0e10210fffffff20,0x0c380180c00780d0,0x043801e422478004,0x000001e422078004\n"
".quad 0x1ffe03e0000002f0,0x0a40030000000086,0x0a400300000000a0,0x0a0c210000110010\n"
".quad 0x0a4003a40007e030,0x0210410000210010,0x00f83dc410078030,0x001e050403c78010\n"
".quad 0x10e009c000078000,0x850ffd20000780d4,0x30e005605107e8b0,0x00002520000780d4\n"
".quad 0x028e204400c78018,0x09c025b540604410,0x89122500200780c8,0x890e2100402680c0\n"
".quad 0x00101d00402680c0,0x07121d0000078090,0x7c0e2104044780e0,0x40162d60004780b0\n"
".quad 0x049e3d0402078020,0x101ffd0000000320,0x094003640147e830,0x0014390000228010\n"
".quad 0x0ed1fd0403878220,0x400c19642107e830,0x07e0030402878020,0x0ac0030000228010\n"
".quad 0x020a350000078010,0x004229c410078030,0x00f82d04200780a0,0x1ffe030403c78010\n"
".quad 0x50f8050000000086,0x05c1fd20000780d0,0x13b0036420c7d834,0x001a0500000000a0\n"
".quad 0x13b003c000078000,0x001a090000128010,0x0203fdc000078000,0x126003600347d8b0\n"
".quad 0x0316190000110010,0x04161d640147d030,0x830c216401478030,0x000e1904400780d0\n"
".quad 0x0611fd2c014780a0,0x000019040007e8d0,0x0e2003c4104780a0,0x0602190000210010\n"
".quad 0x06f41980100780b0,0x32802100200780c0,0x0480250932d2e710,0x000c190386544b10\n"
".quad 0x000031c4400780a0,0x080c2108004780b0,0x001819c0000780e0,0x103801c4500780a0\n"
".quad 0x080dfde420c78008,0x0dc003e000c7d8e0,0x08380100000000a0,0x0da003e422c78008\n"
".quad 0x7c02190000110010,0x7c01fd600047e0b0,0x0d3003600047f8b0,0x000dfd00000000a0\n"
".quad 0x0d10030c0147d8a0,0x00f8190000310010,0x0006190603c78010,0x0d30032440e28010\n"
".quad 0x0180190000078010,0x00f8190000000310,0x00021d0403d28010,0x000dfd00000782b0\n"
".quad 0x000e192c0147d8a0,0x84181903f00003c0,0x0c380100405980e0,0x043801e421878008\n"
".quad 0x0dc003e421878008,0x0c38010000078010,0x043801e420478008,0x000001e420078008\n"
".quad 0x018019e0000002f0,0x0038010000000310,0x144401e421878004,0x018031e421878000\n"
".quad 0x13b0030000000310,0x1240030000078010,0x00380100000000a0,0x105003e43f078004\n"
".quad 0x0602190000110010,0x06f41980100780b0,0x32802100200780c0,0x0480250932d2e710\n"
".quad 0x000c190386544b10,0x000031c4400780a0,0x080c2108004780b0,0x001819c0000780e0\n"
".quad 0x103801c4500780a0,0x080dfde420c78008,0x083801e000c7d8e0,0x102003e422c78008\n"
".quad 0x7c02190000110010,0x7c01fd600047e0b0,0x0fb003600047f8b0,0x000dfd00000000a0\n"
".quad 0x0f90030c0147d8a0,0x00f8190000310010,0x0006190403c78010,0x0fb0032440e28010\n"
".quad 0x0180190000078010,0x00f8190000000310,0x00021d0403d28010,0x000dfd00000782b0\n"
".quad 0x000e192c0147d8a0,0x84181903f00003c0,0x0c380100405980e0,0x043801e421878008\n"
".quad 0x124003e421878008,0x0c38010000078010,0x043801e420478008,0x124003e420078008\n"
".quad 0x0604190000078010,0x06f41980100780b0,0x32802100200780c0,0x0480250932d2e710\n"
".quad 0x000c190386544b10,0x000431c4400780a0,0x080c2108000780b0,0x001819c0000780e0\n"
".quad 0x103801c4500780a0,0x080dfde422c78008,0x083801e000c7d8e0,0x122003e421078008\n"
".quad 0x7c00190000110010,0x7c05fd600047e0b0,0x11b003600047f8b0,0x000dfd00000000a0\n"
".quad 0x1190030c0147d8a0,0x00f8190000310010,0x0006190603c78010,0x11b0032440e28010\n"
".quad 0x0180190000078010,0x00f8190000000310,0x00041d0403d28010,0x000dfd00000782b0\n"
".quad 0x000e192c0147d8a0,0x84181903f00003c0,0x0c380100401980e0,0x043801e421878008\n"
".quad 0x124003e421878008,0x0c38010000078010,0x043801e420078008,0x00f831e420878008\n"
".quad 0x13b0030403c78210,0x4008190000078010,0x830dfd0400c78020,0x130003644147d830\n"
".quad 0x0c38010000128010,0x043801e420478008,0x103801e420878008,0x083801e420c78008\n"
".quad 0x00f831e421078008,0x0038010603c78010,0x13b003e43f078004,0x0c38010000078010\n"
".quad 0x010c01e420478008,0x043801e410078030,0x00002de420878008,0x1038010400c78020\n"
".quad 0x018001e420c78008,0x0838010000000310,0x003801e422c78008,0x144401e420078004\n"
".quad 0x018031e420078000,0x0002010000000310,0x0000010403c78010,0x1ffe03e0000002f0\n"
".quad 0x5110090000000086,0x83c1fd20000780d0,0x187003646147d838,0x5100090000128010\n"
".quad 0x01c03520000780d0,0x7c1bfde430078038,0x0000256c00c7d830,0x1630034400c78018\n"
".quad 0x0180190000128010,0x1ffe030000000310,0x051bfd0000000086,0x15e0036400c7d830\n"
".quad 0x15e00300000000a0,0x010a210000128010,0x02901dc410078030,0x0d1c390000000320\n"
".quad 0x0c1e390000078040,0x0190210003878060,0x101c390000000320,0x0c1c1dc410078030\n"
".quad 0x101a39000387d060,0x1118390000078040,0x101c390003878060,0x101821c410078030\n"
".quad 0x3f9021000387e060,0x3f8e1d0fffffff20,0x00f8210fffffff20,0x00f81d0603e50010\n"
".quad 0x02100d0403d50010,0x020e09c000078000,0x00381dc000078000,0x00f81d4400c7801c\n"
".quad 0x0038010421c78028,0x011a35e421c78008,0x7c1bfdec10078230,0x010c196c0107d830\n"
".quad 0x146003c410078030,0x1640030000128010,0x0180190000078010,0x8613fd0000000310\n"
".quad 0x1780036440c7d830,0x0280210000128010,0x010c190000000310,0x1ffe03e410078030\n"
".quad 0x3f901d0000000086,0x070bfd0fffffff20,0x175003640187d830,0x17500300000000a0\n"
".quad 0x018a1d0000128010,0x010c350000000320,0x470c1ce410078030,0x020e0920079a3440\n"
".quad 0x021a0dc000078000,0x00361dc000078000,0x00f61d4400c78018,0x0036010421c7802c\n"
".quad 0x011021e421c7800c,0x0911fdc410078230,0x167003640047d830,0x1ffe030000128010\n"
".quad 0x8319fd0000000086,0x50f809644087d830,0x05c1fd20000780d0,0x186003642112d838\n"
".quad 0x18600300000000a0,0x50f8090000110010,0x00001920000780d0,0x00f6194400c78018\n"
".quad 0x020c090421878024,0x0c3801c000078000,0x043801e420078008,0x103801e420878008\n"
".quad 0x083801e422c78008,0x000001e421078008,0x1ffe03e0000002f0,0x1a50030000000086\n"
".quad 0x1a500300000000a0,0x50f8090000010010,0x00001920000780d0,0x02c0094400c78018\n"
".quad 0x00f619c020078008,0x3f8c1d0421878028,0x070dfd0fffffff20,0x143e01040007d8d0\n"
".quad 0x1a1003e421878000,0x000c190000150010,0x810dfd44014780a0,0x000c1d605047d8b0\n"
".quad 0x870c19c4104780a0,0x00102100401680c0,0x00f8212440d68010,0x170c190603d10010\n"
".quad 0x820c19ec10078030,0x820dfd04400780d0,0x400c19644087d830,0x7c0ffd0402078020\n"
".quad 0x028c1960009158b0,0x01801d0ffffffb20,0x00f8190000000310,0x060e190403d68010\n"
".quad 0x144001c400078030,0x018019e421878000,0x1444010000000310,0x144201e43f078000\n"
".quad 0x000001e421878000,0x1ffe03e0000002f0,0x0014190000000086,0x020c090401478020\n"
".quad 0x003801c000078000,0x003801e43f078004,0x1ffe03e43f078008,0x0410030000000086\n"
".quad 0x50f8050000078010,0x05c1fd20000780d0,0x0000036420c7c834,0x50f0050000028030\n"
".quad 0x020a0920000780d0,0x00c001c000078000,0x30e0050421478024,0x02000520000780d8\n"
".quad 0x000001c410078030,0x00ec094400c78014,0x20e0050420478020,0x0e040120000780d8\n"
".quad 0x000001a0c00780d0,0x00f0054400c78014,0x0e02010420478020,0x000004a0c00781d0\n"
".quad 0x0000ff0080000000,0x0000000000000100,0x0000027e8000003f,0x0000184b80000000\n"
".quad 0x300b043e80000000,0x0000080000000000,0x0000180000001000,0x0000280000002000\n"
".quad 0x0000380000003000,0x0000480000004000,0x0000580000005000,0x0c1704005c180300\n"
".quad 0x58000bffffffff00,0x0c17040013f00000,0x50000affffffff00,0x0c17040023f00000\n"
".quad 0x480009ffffffff00,0x0c17040023f00000,0x400008ffffffff00,0x0c17040023f00000\n"
".quad 0x380007ffffffff00,0x0c17040023f00000,0x300006ffffffff00,0x0c17040023f00000\n"
".quad 0x280005ffffffff00,0x0c17040023f00000,0x200004ffffffff00,0x0c17040023f00000\n"
".quad 0x180003ffffffff00,0x0c17040023f00000,0x100002ffffffff00,0x0c17040013f00000\n"
".quad 0x080001ffffffff00,0x0c17040023f00000,0x000000ffffffff00,0x080d040023f00000\n"
".quad 0x0000200021010800,0x0000000600000000,0x00003e6c00000005,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000018800000000,0x0000018800000000,0x0000000400000000\n"
".quad 0x6000000000000000,0x00000a3900001405,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000200000000000,0x0000200000000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x00002a3900001406,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x000020bc00000000,0x0000000400000000,0x6000000000000000,0x00002a3900001305\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000052400000000,0x0000052400000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x00002f5d00001306,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000084800000000,0x0000000400000000\n"
".quad 0x6000000000000000,0x00002f5d00001205,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000f0c00000000,0x00000f0c00000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x00003e6900001206,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000288c00000000,0x0000000400000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_13$[2047];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_13$:\n"
".quad 0x6f69737265762e09,0x2e090a342e31206e,0x7320746567726174,0x2f2f090a33315f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x2d2f2f090a0a3930,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f\n"
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f3631313330,0x372d303030303030\n"
".quad 0x5f7463657369625f,0x70632e656772616c,0x742f2820692e3370,0x23494263632f706d\n"
".quad 0x29556e754942782e,0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x0a2d2d2d2d2d2d2d,0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x0a2d2d2d2d2d2d2d,0x6974704f202f2f09,0x2f2f090a3a736e6f,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x202f2f090a2d2d2d,0x3a74656772615420\n"
".quad 0x415349202c787470,0x202c33315f6d733a,0x6c3a6e6169646e45,0x50202c656c747469\n"
".quad 0x53207265746e696f,0x090a34363a657a69,0x09334f2d20202f2f,0x7a696d6974704f28\n"
".quad 0x656c206e6f697461,0x2f2f090a296c6576,0x44280930672d2020,0x76656c2067756265\n"
".quad 0x202f2f090a296c65,0x65522809326d2d20,0x7664612074726f70,0x29736569726f7369\n"
".quad 0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d\n"
".quad 0x09656c69662e090a,0x6d6d6f633c220931,0x656e696c2d646e61,0x6c69662e090a223e\n"
".quad 0x6d742f2209320965,0x746678706d742f70,0x313133303030305f,0x3030303030305f36\n"
".quad 0x7369625f362d3030,0x6772616c5f746365,0x6566616475632e65,0x090a227570672e32\n"
".quad 0x093309656c69662e,0x696c2f7273752f22,0x36692f6363672f62,0x78756e696c2d3638\n"
".quad 0x342e342f756e672d,0x756c636e692f352e,0x65646474732f6564,0x662e090a22682e66\n"
".quad 0x2f22093409656c69,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x72632f6564756c63,0x6563697665642f74,0x656d69746e75725f,0x69662e090a22682e\n"
".quad 0x752f22093509656c,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x736f682f6564756c,0x656e696665645f74,0x662e090a22682e73,0x2f22093609656c69\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x75622f6564756c63\n"
".quad 0x79745f6e69746c69,0x090a22682e736570,0x093709656c69662e,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x745f656369766564\n"
".quad 0x0a22682e73657079,0x3809656c69662e09,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f7265766972642f,0x22682e7365707974\n"
".quad 0x09656c69662e090a,0x2f7273752f220939,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x6361667275732f65,0x2e73657079745f65,0x6c69662e090a2268\n"
".quad 0x752f220930310965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x7865742f6564756c,0x7079745f65727574,0x2e090a22682e7365,0x09313109656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x745f726f74636576,0x0a22682e73657079,0x3109656c69662e09,0x2f7273752f220932\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65\n"
".quad 0x5f68636e75616c5f,0x6574656d61726170,0x2e090a22682e7372,0x09333109656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x726f74732f747263,0x73616c635f656761,0x662e090a22682e73,0x2209343109656c69\n"
".quad 0x636e692f7273752f,0x7469622f6564756c,0x2e73657079742f73,0x6c69662e090a2268\n"
".quad 0x752f220935310965,0x756c636e692f7273,0x2e656d69742f6564,0x6c69662e090a2268\n"
".quad 0x682f220936310965,0x6d726f6e2f656d6f,0x6b636568632f6c61,0x6f7570672f74756f\n"
".quad 0x65742f746f6c6563,0x616475632f737473,0x747365742f322e32,0x766e656769652f73\n"
".quad 0x69622f7365756c61,0x6974755f74636573,0x2e090a2275632e6c,0x09373109656c6966\n"
".quad 0x6e2f656d6f682f22,0x68632f6c616d726f,0x672f74756f6b6365,0x746f6c65636f7570\n"
".quad 0x632f73747365742f,0x742f322e32616475,0x6769652f73747365,0x7365756c61766e65\n"
".quad 0x5f7463657369622f,0x6c5f6c656e72656b,0x2275632e65677261,0x09656c69662e090a\n"
".quad 0x6d6f682f22093831,0x6c616d726f6e2f65,0x756f6b636568632f,0x65636f7570672f74\n"
".quad 0x747365742f746f6c,0x2e32616475632f73,0x2f73747365742f32,0x6c61766e65676965\n"
".quad 0x657369622f736575,0x656e72656b5f7463,0x5f656772616c5f6c,0x2275632e69656e6f\n"
".quad 0x09656c69662e090a,0x7273752f22093931,0x6564756c636e692f,0x342e342f2b2b632f\n"
".quad 0x0a226874616d632f,0x3209656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6e6f6d6d6f632f65,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09313209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6e75665f6874616d,0x682e736e6f697463\n"
".quad 0x656c69662e090a22,0x73752f2209323209,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x6874616d2f656475,0x6e6174736e6f635f,0x2e090a22682e7374\n"
".quad 0x09333209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x665f656369766564,0x736e6f6974636e75,0x69662e090a22682e\n"
".quad 0x2f2209343209656c,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x6d732f6564756c63,0x6d6f74615f31315f,0x74636e75665f6369,0x0a22682e736e6f69\n"
".quad 0x3209656c69662e09,0x2f7273752f220935,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x5f32315f6d732f65,0x665f63696d6f7461,0x736e6f6974636e75\n"
".quad 0x69662e090a22682e,0x2f2209363209656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x6d732f6564756c63,0x62756f645f33315f,0x74636e75665f656c\n"
".quad 0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220937,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x5f30325f6d732f65,0x665f63696d6f7461\n"
".quad 0x736e6f6974636e75,0x69662e090a22682e,0x2f2209383209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6d732f6564756c63,0x72746e695f30325f\n"
".quad 0x682e736369736e69,0x656c69662e090a22,0x73752f2209393209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x667275732f656475,0x636e75665f656361\n"
".quad 0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093033,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x75747865742f6564,0x68637465665f6572\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09313309656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6e75665f6874616d\n"
".quad 0x645f736e6f697463,0x2e337874705f6c62,0x6c69662e090a2268,0x682f220932330965\n"
".quad 0x6d726f6e2f656d6f,0x6b636568632f6c61,0x6f7570672f74756f,0x65742f746f6c6563\n"
".quad 0x616475632f737473,0x747365742f322e32,0x766e656769652f73,0x69622f7365756c61\n"
".quad 0x72656b5f74636573,0x6772616c5f6c656e,0x2e69746c756d5f65,0x2e090a0a0a227563\n"
".quad 0x5a5f207972746e65,0x7463657369623731,0x614c6c656e72654b,0x6a5f536650656772\n"
".quad 0x536a50666a6a6666,0x30535f535f535f30,0x5f30535f535f535f,0x30535f30535f3053\n"
".quad 0x702e09090a28205f,0x36752e206d617261,0x616475635f5f2034,0x315a5f5f6d726170\n"
".quad 0x4b74636573696237,0x72614c6c656e7265,0x666a5f5366506567,0x30536a50666a6a66\n"
".quad 0x5f30535f535f535f,0x535f30535f535f53,0x5f30535f30535f30,0x09090a2c645f675f\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x636573696237315a\n"
".quad 0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053\n"
".quad 0x30535f535f535f30,0x535f30535f30535f,0x0a2c735f675f5f30,0x6d617261702e0909\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365\n"
".quad 0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f\n"
".quad 0x30535f30535f3053,0x0a2c6e5f5f30535f,0x6d617261702e0909,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c\n"
".quad 0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053\n"
".quad 0x2c676c5f5f30535f,0x617261702e09090a,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65,0x6a6a66666a5f5366\n"
".quad 0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f,0x67755f5f30535f30\n"
".quad 0x7261702e09090a2c,0x203233752e206d61,0x6170616475635f5f,0x6237315a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a\n"
".quad 0x5f535f30535f535f,0x5f30535f30535f53,0x6c5f5f30535f3053,0x6f635f6769655f67\n"
".quad 0x2e09090a2c746e75,0x752e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x7463657369623731,0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666\n"
".quad 0x30535f535f535f30,0x5f30535f535f535f,0x30535f30535f3053,0x6769655f67755f5f\n"
".quad 0x0a2c746e756f635f,0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53\n"
".quad 0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053,0x7370655f5f30535f\n"
".quad 0x09090a2c6e6f6c69,0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x6d756e5f675f5f30\n"
".quad 0x09090a2c656e6f5f,0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x6d756e5f675f5f30\n"
".quad 0x5f736b636f6c625f,0x09090a2c746c756d,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261\n"
".quad 0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f\n"
".quad 0x66656c5f675f5f30,0x090a2c656e6f5f74,0x206d617261702e09,0x635f5f203436752e\n"
".quad 0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c\n"
".quad 0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30\n"
".quad 0x69725f675f5f3053,0x2c656e6f5f746867,0x617261702e09090a,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65\n"
".quad 0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f\n"
".quad 0x5f675f5f30535f30,0x2c656e6f5f736f70,0x617261702e09090a,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65\n"
".quad 0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f\n"
".quad 0x5f675f5f30535f30,0x6c756d5f7466656c,0x61702e09090a2c74,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x37315a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53,0x30535f30535f535f\n"
".quad 0x5f5f30535f30535f,0x5f74686769725f67,0x09090a2c746c756d,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x66656c5f675f5f30,0x5f746e756f635f74,0x09090a2c746c756d\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x636573696237315a\n"
".quad 0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053\n"
".quad 0x30535f535f535f30,0x535f30535f30535f,0x6769725f675f5f30,0x746e756f635f7468\n"
".quad 0x090a2c746c756d5f,0x206d617261702e09,0x635f5f203436752e,0x5f6d726170616475\n"
".quad 0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f\n"
".quad 0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30,0x6c625f675f5f3053\n"
".quad 0x6c756d5f736b636f,0x61702e09090a2c74,0x3436752e206d6172,0x70616475635f5f20\n"
".quad 0x37315a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065\n"
".quad 0x5f30536a50666a6a,0x535f30535f535f53,0x30535f30535f535f,0x5f5f30535f30535f\n"
".quad 0x736b636f6c625f67,0x75735f746c756d5f,0x2e090a7b090a296d,0x3631752e20676572\n"
".quad 0x3e37353c68722520,0x206765722e090a3b,0x3c7225203233752e,0x2e090a3b3e323932\n"
".quad 0x3436752e20676572,0x3138313c64722520,0x6765722e090a3b3e,0x6625203233662e20\n"
".quad 0x2e090a3b3e32383c,0x3436662e20676572,0x3e34313c64662520,0x206765722e090a3b\n"
".quad 0x702520646572702e,0x2e090a3b3e39383c,0x2e20646572616873,0x2034206e67696c61\n"
".quad 0x75635f5f2038622e,0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x303836335f726176\n"
".quad 0x6e6f6e5f33335f36,0x735f74736e6f635f,0x3832317466656c5f,0x0a3b5d323530325b\n"
".quad 0x6465726168732e09,0x206e67696c612e20,0x5f5f2038622e2032,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f32345f313138,0x74736e6f635f6e6f\n"
".quad 0x5f7466656c5f735f,0x383132746e756f63,0x3b5d363230315b30,0x65726168732e090a\n"
".quad 0x6e67696c612e2064,0x5f2038622e203220,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f32345f35313836,0x736e6f635f6e6f6e,0x706d6f635f735f74\n"
".quad 0x6c5f6e6f69746361,0x5b36303233747369,0x090a3b5d36323031,0x206465726168732e\n"
".quad 0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3836335f7261765f,0x6f6e5f33335f3730,0x5f74736e6f635f6e,0x3474686769725f73\n"
".quad 0x323530325b323332,0x6168732e090a3b5d,0x696c612e20646572,0x38622e2032206e67\n"
".quad 0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f32313836335f\n"
".quad 0x6f635f6e6f6e5f32,0x69725f735f74736e,0x6e756f635f746867,0x30315b3438323674\n"
".quad 0x732e090a3b5d3632,0x612e206465726168,0x2e2032206e67696c,0x6475635f5f203862\n"
".quad 0x616475635f5f5f61,0x765f6c61636f6c5f,0x31313037335f7261,0x5f6e6f6e5f32345f\n"
".quad 0x5f735f74736e6f63,0x65706c65685f6c63,0x30315b3031333772,0x732e090a3b5d3632\n"
".quad 0x752e206465726168,0x6475635f5f203233,0x5f6c61636f6c5f61,0x323836335f726176\n"
".quad 0x6e6f6e5f30345f30,0x635f74736e6f635f,0x735f746361706d6f,0x68635f646e6f6365\n"
".quad 0x732e090a3b6b6e75,0x752e206465726168,0x6475635f5f203233,0x5f6c61636f6c5f61\n"
".quad 0x323836335f726176,0x6e6f6e5f30345f35,0x6e5f74736e6f635f,0x61657268745f6d75\n"
".quad 0x76697463615f7364,0x6168732e090a3b65,0x3233752e20646572,0x5f616475635f5f20\n"
".quad 0x61765f6c61636f6c,0x5f38323836335f72,0x635f6e6f6e5f3034,0x6d756e5f74736e6f\n"
".quad 0x736461657268745f,0x746361706d6f635f,0x732e090a3b6e6f69,0x752e206465726168\n"
".quad 0x6475635f5f203233,0x5f6c61636f6c5f61,0x323836335f726176,0x6e6f6e5f30345f32\n"
".quad 0x615f74736e6f635f,0x61657268745f6c6c,0x65766e6f635f7364,0x2e090a3b64656772\n"
".quad 0x2e20646572616873,0x75635f5f20323375,0x6c61636f6c5f6164,0x3037335f7261765f\n"
".quad 0x6f6e5f30345f3539,0x5f74736e6f635f6e,0x636f6c625f6d756e,0x3b746c756d5f736b\n"
".quad 0x65726168732e090a,0x5f203233752e2064,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3739303733,0x6e6f635f6e6f6e5f,0x657366666f5f7473,0x6c5f746c756d5f74\n"
".quad 0x090a3b6164626d61,0x206465726168732e,0x635f5f203233752e,0x61636f6c5f616475\n"
".quad 0x37335f7261765f6c,0x6e5f30345f363930,0x74736e6f635f6e6f,0x6c756d5f6d756e5f\n"
".quad 0x636f6c2e090a3b74,0x0937373109373109,0x656257444c240a30,0x37315a5f5f6e6967\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a\n"
".quad 0x535f30535f535f53,0x30535f30535f535f,0x3a5f30535f30535f,0x36752e766f6d090a\n"
".quad 0x2c31647225092034,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f36303836335f,0x6f635f6e6f6e5f33,0x656c5f735f74736e,0x090a3b3832317466\n"
".quad 0x203436752e766f6d,0x5f202c3264722509,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f32345f31313836,0x736e6f635f6e6f6e,0x7466656c5f735f74\n"
".quad 0x3132746e756f635f,0x766f6d090a3b3038,0x722509203436752e,0x75635f5f202c3364\n"
".quad 0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x313836335f726176,0x6e6f6e5f32345f35\n"
".quad 0x735f74736e6f635f,0x746361706d6f635f,0x7473696c5f6e6f69,0x6d090a3b36303233\n"
".quad 0x09203436752e766f,0x5f5f202c34647225,0x635f5f5f61647563,0x61636f6c5f616475\n"
".quad 0x36335f7261765f6c,0x6e5f33335f373038,0x74736e6f635f6e6f,0x74686769725f735f\n"
".quad 0x6d090a3b32333234,0x09203436752e766f,0x5f5f202c35647225,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f32345f323138,0x74736e6f635f6e6f\n"
".quad 0x74686769725f735f,0x3236746e756f635f,0x6f6c2e090a3b3438,0x3631320937310963\n"
".quad 0x2e766f6d090a3009,0x3172250920323375,0x6f6d090a3b30202c,0x2509203233732e76\n"
".quad 0x3b317225202c3272,0x3109636f6c2e090a,0x0a30093731320937,0x3233752e766f6d09\n"
".quad 0x30202c3372250920,0x732e766f6d090a3b,0x2c34722509203233,0x2e090a3b33722520\n"
".quad 0x3209373109636f6c,0x7663090a30093632,0x31752e3233752e74,0x202c357225092036\n"
".quad 0x0a3b782e64697425,0x3436752e74766309,0x722509203233752e,0x3b357225202c3664\n"
".quad 0x69772e6c756d090a,0x09203233752e6564,0x7225202c37647225,0x6d090a3b32202c35\n"
".quad 0x09203631752e766f,0x3b30202c31687225,0x36752e646461090a,0x2c38647225092034\n"
".quad 0x25202c3764722520,0x7473090a3b336472,0x2e6465726168732e,0x72255b0920363175\n"
".quad 0x25202c5d302b3864,0x6c2e090a3b316872,0x323209373109636f,0x6c756d090a300937\n"
".quad 0x33752e656469772e,0x2c39647225092032,0x3b34202c35722520,0x36752e646461090a\n"
".quad 0x3031647225092034,0x202c39647225202c,0x6d090a3b31647225,0x09203233662e766f\n"
".quad 0x306630202c316625,0x3b30303030303030,0x2f2f092020202020,0x732e7473090a3020\n"
".quad 0x33662e6465726168,0x316472255b092032,0x6625202c5d302b30,0x636f6c2e090a3b31\n"
".quad 0x0938323209373109,0x752e646461090a30,0x3164722509203436,0x2c39647225202c31\n"
".quad 0x090a3b3464722520,0x203233662e766f6d,0x6630202c32662509,0x3030303030303030\n"
".quad 0x2f0920202020203b,0x2e7473090a30202f,0x662e646572616873,0x6472255b09203233\n"
".quad 0x25202c5d302b3131,0x6f6c2e090a3b3266,0x3932320937310963,0x2e646461090a3009\n"
".quad 0x6472250920343675,0x37647225202c3231,0x0a3b32647225202c,0x3631752e766f6d09\n"
".quad 0x202c326872250920,0x732e7473090a3b30,0x31752e6465726168,0x316472255b092036\n"
".quad 0x7225202c5d302b32,0x6f6c2e090a3b3268,0x3033320937310963,0x2e646461090a3009\n"
".quad 0x6472250920343675,0x37647225202c3331,0x0a3b35647225202c,0x3631752e766f6d09\n"
".quad 0x202c336872250920,0x732e7473090a3b30,0x31752e6465726168,0x316472255b092036\n"
".quad 0x7225202c5d302b33,0x6f6c2e090a3b3368,0x3233320937310963,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x33752e766f6d090a,0x202c367225092032,0x70746573090a3b30\n"
".quad 0x203233752e71652e,0x7225202c31702509,0x0a3b367225202c35,0x6220317025214009\n"
".quad 0x5f744c2409206172,0x3b38373339365f30,0x3109636f6c2e090a,0x0a30093733320937\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3366,0x5f6d726170616475\n"
".quad 0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f\n"
".quad 0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30,0x3b5d676c5f5f3053\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x616475635f5f5b09,0x5f616475635f5f5f\n"
".quad 0x61765f6c61636f6c,0x5f36303836335f72,0x635f6e6f6e5f3333,0x6c5f735f74736e6f\n"
".quad 0x302b383231746665,0x0a3b336625202c5d,0x373109636f6c2e09,0x090a300938333209\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c34,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x0a3b5d67755f5f30\n"
".quad 0x726168732e747309,0x09203233662e6465,0x5f616475635f5f5b,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f37303836335f,0x6f635f6e6f6e5f33,0x69725f735f74736e\n"
".quad 0x2b32333234746867,0x3b346625202c5d30,0x3109636f6c2e090a,0x0a30093933320937\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3772,0x5f6d726170616475\n"
".quad 0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f\n"
".quad 0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30,0x655f676c5f5f3053\n"
".quad 0x746e756f635f6769,0x732e7473090a3b5d,0x31752e6465726168,0x75635f5f5b092036\n"
".quad 0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x313836335f726176,0x6e6f6e5f32345f31\n"
".quad 0x735f74736e6f635f,0x6f635f7466656c5f,0x2b30383132746e75,0x3b377225202c5d30\n"
".quad 0x3109636f6c2e090a,0x0a30093034320937,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x635f5f5b202c3872,0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x655f67755f5f3053,0x746e756f635f6769,0x732e7473090a3b5d\n"
".quad 0x31752e6465726168,0x75635f5f5b092036,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x313836335f726176,0x6e6f6e5f32345f32,0x735f74736e6f635f,0x635f74686769725f\n"
".quad 0x34383236746e756f,0x387225202c5d302b,0x09636f6c2e090a3b,0x3009323432093731\n"
".quad 0x33752e766f6d090a,0x202c397225092032,0x732e7473090a3b30,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3836335f7261765f,0x6f6e5f30345f3032\n"
".quad 0x5f74736e6f635f6e,0x5f746361706d6f63,0x635f646e6f636573,0x25202c5d6b6e7568\n"
".quad 0x6f6c2e090a3b3972,0x3334320937310963,0x2e766f6d090a3009,0x3172250920323375\n"
".quad 0x73090a3b31202c30,0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3532383633,0x6e6f635f6e6f6e5f,0x745f6d756e5f7473\n"
".quad 0x615f736461657268,0x202c5d6576697463,0x2e090a3b30317225,0x3209373109636f6c\n"
".quad 0x6f6d090a30093534,0x2509203233752e76,0x0a3b31202c313172,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38323836335f72\n"
".quad 0x635f6e6f6e5f3034,0x6d756e5f74736e6f,0x736461657268745f,0x746361706d6f635f\n"
".quad 0x7225202c5d6e6f69,0x6f6c2e090a3b3131,0x3734320937310963,0x2e766f6d090a3009\n"
".quad 0x3172250920323375,0x73090a3b31202c32,0x6465726168732e74,0x5f5b09203233752e\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3232383633,0x6e6f635f6e6f6e5f\n"
".quad 0x745f6c6c615f7473,0x635f736461657268,0x6465677265766e6f,0x3b32317225202c5d\n"
".quad 0x365f305f744c240a,0x2e090a3a38373339,0x3209373109636f6c,0x6162090a30093035\n"
".quad 0x0920636e79732e72,0x326c756d090a3b30,0x3233752e6f6c2e34,0x202c333172250920\n"
".quad 0x0a3b32202c357225,0x3436752e74766309,0x722509203233752e,0x317225202c343164\n"
".quad 0x326c756d090a3b33,0x3233752e6f6c2e34,0x202c343172250920,0x0a3b34202c357225\n"
".quad 0x3436752e74766309,0x722509203233752e,0x317225202c353164,0x2e646461090a3b34\n"
".quad 0x6472250920343675,0x31647225202c3631,0x3b32647225202c34,0x36752e646461090a\n"
".quad 0x3731647225092034,0x2c3431647225202c,0x090a3b3564722520,0x203436752e646461\n"
".quad 0x202c383164722509,0x25202c3431647225,0x6461090a3b336472,0x2509203436752e64\n"
".quad 0x7225202c39316472,0x647225202c353164,0x2e646461090a3b31,0x6472250920343675\n"
".quad 0x31647225202c3032,0x3b34647225202c35,0x33752e747663090a,0x2509203631752e32\n"
".quad 0x746e25202c353172,0x6d090a3b782e6469,0x09203233752e766f,0x3b30202c36317225\n"
".quad 0x33662e766f6d090a,0x202c356625092032,0x3030303030306630,0x20202020203b3030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x306630202c366625,0x3b30303030303030\n"
".quad 0x2f2f092020202020,0x2e766f6d090a3020,0x3766250920323366,0x303030306630202c\n"
".quad 0x2020203b30303030,0x0a30202f2f092020,0x35345f305f744c24,0x2f2f200a3a343133\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x353220656e696c20,0x09636f6c2e090a36\n"
".quad 0x3009363532093731,0x6168732e646c090a,0x203233732e646572,0x5b202c3731722509\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f35323836335f,0x6f635f6e6f6e5f30\n"
".quad 0x5f6d756e5f74736e,0x5f73646165726874,0x3b5d657669746361,0x6c2e70746573090a\n"
".quad 0x2509203233752e65,0x37317225202c3270,0x090a3b357225202c,0x6172622032702540\n"
".quad 0x5f305f744c240920,0x200a3b3632343137,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3431333534,0x3509363109636f6c,0x646c090a30093639\n"
".quad 0x2e6465726168732e,0x3766250920323366,0x39316472255b202c,0x6c2e090a3b5d302b\n"
".quad 0x393509363109636f,0x2e646c090a300937,0x662e646572616873,0x2c36662509203233\n"
".quad 0x2b30326472255b20,0x6f6c2e090a3b5d30,0x3839350936310963,0x732e646c090a3009\n"
".quad 0x31752e6465726168,0x202c317225092036,0x302b36316472255b,0x636f6c2e090a3b5d\n"
".quad 0x0939393509363109,0x68732e646c090a30,0x3631752e64657261,0x5b202c3372250920\n"
".quad 0x5d302b3731647225,0x2e70746573090a3b,0x203233662e75656e,0x6625202c33702509\n"
".quad 0x0a3b376625202c36,0x6220337025214009,0x5f744c2409206172,0x3b38353630375f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30\n"
".quad 0x3233662e766f6d09,0x30202c3866250920,0x3030303030303066,0x0920202020203b30\n"
".quad 0x6c2e090a30202f2f,0x393509363109636f,0x2e646c090a300936,0x662e646572616873\n"
".quad 0x2c37662509203233,0x2b39316472255b20,0x6f6c2e090a3b5d30,0x3939350936310963\n"
".quad 0x70746573090a3009,0x203233662e746c2e,0x6625202c34702509,0x0a3b386625202c37\n"
".quad 0x3233662e766f6d09,0x30202c3966250920,0x3030303030303066,0x0920202020203b30\n"
".quad 0x6c2e090a30202f2f,0x393509363109636f,0x2e646c090a300937,0x662e646572616873\n"
".quad 0x2c36662509203233,0x2b30326472255b20,0x6f6c2e090a3b5d30,0x3939350936310963\n"
".quad 0x70746573090a3009,0x203233662e746c2e,0x6625202c35702509,0x0a3b396625202c36\n"
".quad 0x6220357025214009,0x5f744c2409206172,0x3b30373131375f30,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30,0x363109636f6c2e09\n"
".quad 0x090a300934303609,0x3233732e706c6573,0x202c383172250920,0x7025202c30202c31\n"
".quad 0x2e617262090a3b34,0x744c240920696e75,0x34313930375f305f,0x5f305f744c240a3b\n"
".quad 0x200a3a3037313137,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c363532,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x73090a3431333534,0x203233732e706c65,0x30202c3831722509,0x347025202c31202c\n"
".quad 0x5f305f744c240a3b,0x200a3a3431393037,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3431333534,0x3509363109636f6c,0x646c090a30093739\n"
".quad 0x2e6465726168732e,0x3666250920323366,0x30326472255b202c,0x6c2e090a3b5d302b\n"
".quad 0x393509363109636f,0x2e646c090a300936,0x662e646572616873,0x2c37662509203233\n"
".quad 0x2b39316472255b20,0x6f6c2e090a3b5d30,0x3430360936310963,0x2e627573090a3009\n"
".quad 0x3166250920323366,0x202c366625202c30,0x6f6d090a3b376625,0x2509203233662e76\n"
".quad 0x336630202c313166,0x3b30303030303066,0x202f2f0920202020,0x64616d090a352e30\n"
".quad 0x662509203233662e,0x30316625202c3231,0x202c31316625202c,0x6461090a3b376625\n"
".quad 0x2509203233662e64,0x366625202c333166,0x090a3b376625202c,0x203233662e766f6d\n"
".quad 0x30202c3431662509,0x3030303030663366,0x2f09202020203b30,0x6d090a352e30202f\n"
".quad 0x09203233662e6c75,0x6625202c35316625,0x34316625202c3331,0x732e67656e090a3b\n"
".quad 0x3931722509203233,0x0a3b38317225202c,0x33662e74636c7309,0x2509203233732e32\n"
".quad 0x35316625202c3566,0x202c32316625202c,0x2e090a3b39317225,0x3609363109636f6c\n"
".quad 0x6f6d090a30093530,0x2509203233752e76,0x0a3b30202c303272,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f32323836335f72\n"
".quad 0x635f6e6f6e5f3034,0x6c6c615f74736e6f,0x736461657268745f,0x677265766e6f635f\n"
".quad 0x327225202c5d6465,0x2e617262090a3b30,0x744c240920696e75,0x36323431375f305f\n"
".quad 0x5f305f744c240a3b,0x200a3a3835363037,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3431333534,0x3509363109636f6c,0x646c090a30093939\n"
".quad 0x2e6465726168732e,0x3372250920363175,0x37316472255b202c,0x6c2e090a3b5d302b\n"
".quad 0x393509363109636f,0x2e646c090a300938,0x752e646572616873,0x2c31722509203631\n"
".quad 0x2b36316472255b20,0x6f6c2e090a3b5d30,0x3530360936310963,0x2e627573090a3009\n"
".quad 0x3272250920323375,0x202c337225202c31,0x6f6d090a3b317225,0x2509203233752e76\n"
".quad 0x0a3b31202c323272,0x656c2e7074657309,0x702509203233752e,0x2c31327225202c36\n"
".quad 0x090a3b3232722520,0x6172622036702540,0x5f305f744c240920,0x200a3b3632343137\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363532,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3431333534\n"
".quad 0x3609363109636f6c,0x6f6d090a30093031,0x2509203233752e76,0x0a3b30202c333272\n"
".quad 0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f32323836335f72,0x635f6e6f6e5f3034,0x6c6c615f74736e6f,0x736461657268745f\n"
".quad 0x677265766e6f635f,0x327225202c5d6465,0x305f744c240a3b33,0x0a3a36323431375f\n"
".quad 0x30375f305f744c24,0x744c240a3a323034,0x30393839365f305f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a\n"
".quad 0x0a30093136320937,0x6e79732e72616209,0x2e090a3b30092063,0x3209373109636f6c\n"
".quad 0x646c090a30093536,0x2e6465726168732e,0x3272250920323375,0x75635f5f5b202c34\n"
".quad 0x6c61636f6c5f6164,0x3836335f7261765f,0x6f6e5f30345f3232,0x5f74736e6f635f6e\n"
".quad 0x657268745f6c6c61,0x766e6f635f736461,0x0a3b5d6465677265,0x3233752e766f6d09\n"
".quad 0x202c353272250920,0x70746573090a3b31,0x203233752e71652e,0x7225202c37702509\n"
".quad 0x35327225202c3432,0x2037702540090a3b,0x744c240920617262,0x30383830315f305f\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36353220656e69,0x616c206461656820,0x4c242064656c6562,0x313335345f305f74\n"
".quad 0x09636f6c2e090a34,0x3009333732093731,0x6168732e646c090a,0x203233752e646572\n"
".quad 0x5b202c3632722509,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f35323836335f\n"
".quad 0x6f635f6e6f6e5f30,0x5f6d756e5f74736e,0x5f73646165726874,0x3b5d657669746361\n"
".quad 0x3109636f6c2e090a,0x0a30093833320936,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5f5b202c373272,0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365\n"
".quad 0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f\n"
".quad 0x30535f30535f3053,0x3b5d6e5f5f30535f,0x33732e766f6d090a,0x2c38327225092032\n"
".quad 0x090a3b3732722520,0x203233752e766f6d,0x30202c3932722509,0x2e70746573090a3b\n"
".quad 0x09203233752e7165,0x327225202c387025,0x3b39327225202c37,0x622038702540090a\n"
".quad 0x5f744c2409206172,0x3835303930315f30,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a,0x0a30093337320937\n"
".quad 0x726168732e646c09,0x09203233752e6465,0x5f5b202c36327225,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3532383633,0x6e6f635f6e6f6e5f,0x745f6d756e5f7473\n"
".quad 0x615f736461657268,0x0a3b5d6576697463,0x363109636f6c2e09,0x090a300938333209\n"
".quad 0x2e74672e70746573,0x3970250920323375,0x202c36327225202c,0x6f6d090a3b357225\n"
".quad 0x2509203233752e76,0x0a3b30202c303372,0x3233752e766f6d09,0x202c313372250920\n"
".quad 0x2e766f6d090a3b30,0x3166250920323366,0x3866336630202c36,0x20203b3030303030\n"
".quad 0x0a31202f2f092020,0x32375f305f744c24,0x2f2f200a3a303534,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x333220656e696c20,0x697473656e202c38,0x687470656420676e\n"
".quad 0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73\n"
".quad 0x636f6c2e090a6e77,0x0933343209363109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x3233752e64646109,0x202c323372250920,0x7225202c30337225,0x70746573090a3b35\n"
".quad 0x203233752e656c2e,0x25202c3031702509,0x337225202c373272,0x31702540090a3b32\n"
".quad 0x2409206172622030,0x3732375f305f744c,0x3c2f2f200a3b3630,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x38333220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3432375f305f744c,0x636f6c2e090a3035,0x0938343209363109\n"
".quad 0x6c2e6c756d090a30,0x2509203233752e6f,0x337225202c333372,0x63090a3b34202c30\n"
".quad 0x752e3436752e7476,0x3264722509203233,0x3b33337225202c31,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5b202c3232647225,0x6170616475635f5f,0x6237315a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a\n"
".quad 0x5f535f30535f535f,0x5f30535f30535f53,0x675f5f30535f3053,0x6461090a3b5d645f\n"
".quad 0x2509203436752e64,0x7225202c33326472,0x647225202c323264,0x646461090a3b3132\n"
".quad 0x722509203436752e,0x647225202c343264,0x32647225202c3531,0x672e646c090a3b33\n"
".quad 0x33662e6c61626f6c,0x2c37316625092032,0x2b34326472255b20,0x2e7473090a3b5d30\n"
".quad 0x662e646572616873,0x6472255b09203233,0x25202c5d302b3931,0x6c2e090a3b373166\n"
".quad 0x343209363109636f,0x2e646c090a300939,0x36752e6d61726170,0x3532647225092034\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623731,0x614c6c656e72654b\n"
".quad 0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30,0x5f30535f535f535f\n"
".quad 0x30535f30535f3053,0x0a3b5d735f675f5f,0x3436752e64646109,0x2c36326472250920\n"
".quad 0x202c353264722520,0x090a3b3132647225,0x203436752e646461,0x202c373264722509\n"
".quad 0x25202c3531647225,0x6c090a3b36326472,0x6c61626f6c672e64,0x662509203233662e\n"
".quad 0x6472255b202c3831,0x0a3b5d342d2b3732,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b30326472255b,0x3b38316625202c5d,0x375f305f744c240a,0x2f200a3a36303732\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3833,0x64656c6562616c20,0x375f305f744c2420,0x6c2e090a30353432\n"
".quad 0x353209363109636f,0x726162090a300932,0x300920636e79732e,0x3970252140090a3b\n"
".quad 0x4c24092061726220,0x333733375f305f74,0x6c3c2f2f200a3b30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x353432375f305f74,0x752e6e696d090a30,0x3433722509203233\n"
".quad 0x202c38327225202c,0x6d090a3b35317225,0x09203233752e766f,0x3b30202c35337225\n"
".quad 0x652e70746573090a,0x2509203233752e71,0x337225202c313170,0x3b35337225202c34\n"
".quad 0x203131702540090a,0x744c240920617262,0x30333733375f305f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c38333220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x30353432375f305f,0x33732e766f6d090a\n"
".quad 0x2c36337225092032,0x090a3b3433722520,0x203233752e766f6d,0x30202c3733722509\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x337225202c383372,0x2f200a3b34202c34\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3833,0x64656c6562616c20,0x375f305f744c2420,0x6f6d090a30353432\n"
".quad 0x2509203233732e76,0x337225202c393372,0x305f744c240a3b36,0x0a3a32343234375f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x656e202c32353220\n"
".quad 0x656420676e697473,0x202c32203a687470,0x6574616d69747365,0x7461726574692064\n"
".quad 0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3209363109636f6c,0x7663090a30093036\n"
".quad 0x33752e3436752e74,0x3832647225092032,0x0a3b37337225202c,0x3436752e64646109\n"
".quad 0x2c39326472250920,0x202c383264722520,0x6c090a3b34647225,0x6465726168732e64\n"
".quad 0x662509203233662e,0x6472255b202c3931,0x090a3b5d302b3932,0x203436752e646461\n"
".quad 0x202c303364722509,0x25202c3832647225,0x646c090a3b316472,0x2e6465726168732e\n"
".quad 0x3266250920323366,0x336472255b202c30,0x73090a3b5d302b30,0x09203233662e6275\n"
".quad 0x6625202c31326625,0x3b356625202c3032,0x33662e6c756d090a,0x2c32326625092032\n"
".quad 0x25202c3931662520,0x6964090a3b393166,0x662e6c6c75662e76,0x3332662509203233\n"
".quad 0x202c32326625202c,0x73090a3b36316625,0x09203233662e6275,0x6625202c36316625\n"
".quad 0x33326625202c3132,0x09636f6c2e090a3b,0x3009323632093631,0x33662e766f6d090a\n"
".quad 0x2c34326625092032,0x3030303030663020,0x202020203b303030,0x73090a30202f2f09\n"
".quad 0x33752e746c2e7465,0x2509203233662e32,0x316625202c303472,0x3b34326625202c36\n"
".quad 0x33732e67656e090a,0x2c31347225092032,0x090a3b3034722520,0x203233752e646461\n"
".quad 0x25202c3133722509,0x347225202c313372,0x2e646461090a3b31,0x3372250920323375\n"
".quad 0x2c37337225202c37,0x746573090a3b3420,0x3233752e656e2e70,0x202c323170250920\n"
".quad 0x7225202c37337225,0x702540090a3b3833,0x0920617262203231,0x34375f305f744c24\n"
".quad 0x744c240a3b323432,0x30333733375f305f,0x5f305f744c240a3a,0x200a3a3831323337\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383332,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3035343237\n"
".quad 0x3209363109636f6c,0x7573090a30093736,0x2509203233752e62,0x327225202c383272\n"
".quad 0x3b35317225202c38,0x33752e646461090a,0x2c30337225092032,0x25202c3033722520\n"
".quad 0x6573090a3b353172,0x33752e746c2e7074,0x2c33317025092032,0x25202c3033722520\n"
".quad 0x2540090a3b373272,0x2061726220333170,0x375f305f744c2409,0x2f200a3b30353432\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3635,0x64656c6562616c20,0x345f305f744c2420,0x7262090a34313335\n"
".quad 0x240920696e752e61,0x3931375f305f744c,0x5f744c240a3b3833,0x3835303930315f30\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36353220656e,0x62616c2064616568,0x744c242064656c65,0x34313335345f305f\n"
".quad 0x33752e766f6d090a,0x2c31337225092032,0x5f744c240a3b3020,0x3a38333931375f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30\n"
".quad 0x373109636f6c2e09,0x090a300937383209,0x636e79732e726162,0x646c090a3b300920\n"
".quad 0x2e6465726168732e,0x3472250920323375,0x75635f5f5b202c32,0x6c61636f6c5f6164\n"
".quad 0x3836335f7261765f,0x6f6e5f30345f3532,0x5f74736e6f635f6e,0x657268745f6d756e\n"
".quad 0x697463615f736461,0x6573090a3b5d6576,0x33752e656c2e7074,0x2c34317025092032\n"
".quad 0x25202c3234722520,0x702540090a3b3572,0x0920617262203431,0x35375f305f744c24\n"
".quad 0x2f2f200a3b323235,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x747663090a343133,0x3233752e3631752e,0x202c333472250920,0x7663090a3b337225\n"
".quad 0x33752e3631752e74,0x2c34347225092032,0x73090a3b31722520,0x2e75656e2e707465\n"
".quad 0x3170250920323366,0x202c366625202c35,0x2140090a3b376625,0x6172622035317025\n"
".quad 0x5f305f744c240920,0x200a3b3837373537,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3431333534,0x3309373109636f6c,0x7663090a30093430\n"
".quad 0x33752e3631752e74,0x2c35347225092032,0x090a3b3133722520,0x203233662e736261\n"
".quad 0x25202c3532662509,0x746573090a3b3566,0x3233752e656e2e70,0x202c363170250920\n"
".quad 0x7225202c34347225,0x2e646c090a3b3534,0x33662e6d61726170,0x2c36326625092032\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265\n"
".quad 0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53\n"
".quad 0x5f30535f30535f30,0x6e6f6c697370655f,0x706c6573090a3b5d,0x722509203233732e\n"
".quad 0x30202c31202c3634,0x0a3b36317025202c,0x2e656e2e74657309,0x203233752e323375\n"
".quad 0x25202c3734722509,0x347225202c353472,0x2e67656e090a3b33,0x3472250920323373\n"
".quad 0x3b37347225202c38,0x33622e646e61090a,0x2c39347225092032,0x25202c3634722520\n"
".quad 0x6f6d090a3b383472,0x2509203233752e76,0x0a3b30202c303572,0x71652e7074657309\n"
".quad 0x702509203233732e,0x39347225202c3731,0x0a3b30357225202c,0x6220373170254009\n"
".quad 0x5f744c2409206172,0x3b30393236375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x363109636f6c2e09,0x090a300937323109\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x5d302b3631647225,0x0a3b34347225202c\n"
".quad 0x363109636f6c2e09,0x090a300938323109,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x5d302b3731647225,0x0a3b35347225202c,0x3233662e62757309,0x202c373266250920\n"
".quad 0x376625202c356625,0x662e736261090a3b,0x3832662509203233,0x0a3b37326625202c\n"
".quad 0x3436662e74766309,0x662509203233662e,0x38326625202c3164,0x662e736261090a3b\n"
".quad 0x3932662509203233,0x090a3b376625202c,0x203233662e78616d,0x25202c3033662509\n"
".quad 0x326625202c353266,0x636f6c2e090a3b39,0x0934303309373109,0x61702e646c090a30\n"
".quad 0x203233662e6d6172,0x5b202c3632662509,0x6170616475635f5f,0x6237315a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a\n"
".quad 0x5f535f30535f535f,0x5f30535f30535f53,0x655f5f30535f3053,0x3b5d6e6f6c697370\n"
".quad 0x3109636f6c2e090a,0x0a30093832310936,0x3233662e6c756d09,0x202c313366250920\n"
".quad 0x6625202c36326625,0x747663090a3b3033,0x3233662e3436662e,0x202c326466250920\n"
".quad 0x6d090a3b31336625,0x09203436662e766f,0x6430202c33646625,0x3438343435363833\n"
".quad 0x3237653264323339,0x2d6535202f2f093b,0x2e78616d090a3733,0x6466250920343666\n"
".quad 0x2c32646625202c34,0x090a3b3364662520,0x2e656c2e70746573,0x3170250920343666\n"
".quad 0x2c31646625202c38,0x090a3b3464662520,0x6220383170252140,0x5f744c2409206172\n"
".quad 0x3b32303836375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34313335345f30,0x3233662e766f6d09,0x202c323366250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6573090a30202f2f,0x33662e746c2e7074,0x2c39317025092032\n"
".quad 0x6625202c37662520,0x766f6d090a3b3233,0x250920646572702e,0x39317025202c3470\n"
".quad 0x702e766f6d090a3b,0x3270250920646572,0x3b31327025202c30,0x33662e766f6d090a\n"
".quad 0x2c33336625092032,0x3030303030663020,0x202020203b303030,0x73090a30202f2f09\n"
".quad 0x662e746c2e707465,0x3232702509203233,0x25202c356625202c,0x2140090a3b333366\n"
".quad 0x6172622032327025,0x5f305f744c240920,0x200a3b3431333737,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532\n"
".quad 0x656c6562616c2064,0x5f305f744c242064,0x2e090a3431333534,0x3109363109636f6c\n"
".quad 0x6573090a30093633,0x09203233732e706c,0x2c31202c31357225,0x3b347025202c3020\n"
".quad 0x6e752e617262090a,0x305f744c24092069,0x0a3b38353037375f,0x37375f305f744c24\n"
".quad 0x2f2f200a3a343133,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6c6573090a343133,0x2509203233732e70,0x202c30202c313572,0x3b39317025202c31\n"
".quad 0x375f305f744c240a,0x2f200a3a38353037,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20\n"
".quad 0x345f305f744c2420,0x6c2e090a34313335,0x333109363109636f,0x646461090a300939\n"
".quad 0x662509203233662e,0x2c356625202c3433,0x6d090a3b37662520,0x09203233662e766f\n"
".quad 0x6630202c35336625,0x3030303030306633,0x2f2f09202020203b,0x616d090a352e3020\n"
".quad 0x2509203233662e64,0x326625202c363366,0x2c35336625202c37,0x6d090a3b37662520\n"
".quad 0x09203233662e766f,0x6630202c37336625,0x3030303030306633,0x2f2f09202020203b\n"
".quad 0x756d090a352e3020,0x2509203233662e6c,0x336625202c383366,0x3b37336625202c34\n"
".quad 0x33732e67656e090a,0x2c32357225092032,0x090a3b3135722520,0x3233662e74636c73\n"
".quad 0x662509203233732e,0x38336625202c3933,0x202c36336625202c,0x73090a3b32357225\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x2c5d302b39316472,0x090a3b3933662520\n"
".quad 0x09363109636f6c2e,0x73090a3009303431,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d302b30326472,0x090a3b3933662520,0x20696e752e617262,0x375f305f744c2409\n"
".quad 0x4c240a3b36343536,0x303836375f305f74,0x6c3c2f2f200a3a32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x3009353431093631\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x2b39316472255b09,0x3b376625202c5d30\n"
".quad 0x3109636f6c2e090a,0x0a30093634310936,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b30326472255b,0x0a3b356625202c5d,0x36375f305f744c24,0x2f2f200a3a363435\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133\n"
".quad 0x3531390937310963,0x2e766f6d090a3009,0x6872250920363175,0x73090a3b31202c34\n"
".quad 0x6465726168732e74,0x255b09203631752e,0x2c5d322b38316472,0x090a3b3468722520\n"
".quad 0x09373109636f6c2e,0x6d090a3009363139,0x09203233752e766f,0x3b31202c33357225\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x30323836335f7261,0x5f6e6f6e5f30345f,0x6f635f74736e6f63,0x65735f746361706d\n"
".quad 0x7568635f646e6f63,0x357225202c5d6b6e,0x2e766f6d090a3b33,0x3172250920323375\n"
".quad 0x62090a3b31202c36,0x0920696e752e6172,0x35375f305f744c24,0x744c240a3b323235\n"
".quad 0x30393236375f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313335345f305f,0x3109636f6c2e090a,0x0a30093432390937,0x3631752e766f6d09\n"
".quad 0x202c356872250920,0x732e7473090a3b30,0x31752e6465726168,0x316472255b092036\n"
".quad 0x7225202c5d322b38,0x252140090a3b3568,0x2061726220363170,0x375f305f744c2409\n"
".quad 0x2f200a3b36323837,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20,0x345f305f744c2420\n"
".quad 0x6c2e090a34313335,0x323109363109636f,0x2e7473090a300937,0x752e646572616873\n"
".quad 0x6472255b09203631,0x25202c5d302b3631,0x6c2e090a3b343472,0x323109363109636f\n"
".quad 0x2e7473090a300938,0x752e646572616873,0x6472255b09203631,0x25202c5d302b3731\n"
".quad 0x7573090a3b353472,0x2509203233662e62,0x356625202c373266,0x090a3b376625202c\n"
".quad 0x203233662e736261,0x25202c3034662509,0x7663090a3b373266,0x33662e3436662e74\n"
".quad 0x2c35646625092032,0x090a3b3034662520,0x203233662e736261,0x25202c3134662509\n"
".quad 0x78616d090a3b3766,0x662509203233662e,0x35326625202c3234,0x0a3b31346625202c\n"
".quad 0x373109636f6c2e09,0x090a300934303309,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x635f5f5b202c3632,0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x697370655f5f3053,0x2e090a3b5d6e6f6c,0x3109363109636f6c\n"
".quad 0x756d090a30093832,0x2509203233662e6c,0x326625202c333466,0x3b32346625202c36\n"
".quad 0x36662e747663090a,0x2509203233662e34,0x346625202c366466,0x2e766f6d090a3b33\n"
".quad 0x6466250920343666,0x3638336430202c37,0x3233393438343435,0x2f093b3237653264\n"
".quad 0x0a37332d6535202f,0x3436662e78616d09,0x202c386466250920,0x6625202c36646625\n"
".quad 0x746573090a3b3764,0x3436662e656c2e70,0x202c333270250920,0x6625202c35646625\n"
".quad 0x252140090a3b3864,0x2061726220333270,0x375f305f744c2409,0x2f200a3b38333338\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3635,0x64656c6562616c20,0x345f305f744c2420,0x6f6d090a34313335\n"
".quad 0x2509203233662e76,0x306630202c343466,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x2e70746573090a30,0x09203233662e746c,0x6625202c39317025,0x3b34346625202c37\n"
".quad 0x72702e766f6d090a,0x2c34702509206465,0x090a3b3931702520,0x646572702e766f6d\n"
".quad 0x202c343270250920,0x6d090a3b31327025,0x09203233662e766f,0x6630202c35346625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x70746573090a3020,0x203233662e746c2e\n"
".quad 0x25202c3532702509,0x35346625202c3566,0x3270252140090a3b,0x2409206172622035\n"
".quad 0x3838375f305f744c,0x3c2f2f200a3b3035,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x36353220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3335345f305f744c,0x636f6c2e090a3431,0x0936333109363109,0x2e706c6573090a30\n"
".quad 0x3572250920323373,0x2c30202c31202c34,0x62090a3b34702520,0x0920696e752e6172\n"
".quad 0x38375f305f744c24,0x744c240a3b343935,0x30353838375f305f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34313335345f305f,0x732e706c6573090a\n"
".quad 0x3435722509203233,0x202c31202c30202c,0x4c240a3b39317025,0x393538375f305f74\n"
".quad 0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36353220656e69,0x616c206461656820,0x4c242064656c6562,0x313335345f305f74\n"
".quad 0x09636f6c2e090a34,0x3009393331093631,0x33662e646461090a,0x2c36346625092032\n"
".quad 0x6625202c35662520,0x2e766f6d090a3b37,0x3466250920323366,0x3066336630202c37\n"
".quad 0x20203b3030303030,0x2e30202f2f092020,0x662e64616d090a35,0x3834662509203233\n"
".quad 0x202c37326625202c,0x6625202c37346625,0x2e766f6d090a3b37,0x3466250920323366\n"
".quad 0x3066336630202c39,0x20203b3030303030,0x2e30202f2f092020,0x662e6c756d090a35\n"
".quad 0x3035662509203233,0x202c36346625202c,0x6e090a3b39346625,0x09203233732e6765\n"
".quad 0x7225202c35357225,0x636c73090a3b3435,0x33732e3233662e74,0x2c31356625092032\n"
".quad 0x25202c3035662520,0x357225202c383466,0x732e7473090a3b35,0x33662e6465726168\n"
".quad 0x316472255b092032,0x6625202c5d302b39,0x6f6c2e090a3b3135,0x3034310936310963\n"
".quad 0x732e7473090a3009,0x33662e6465726168,0x326472255b092032,0x6625202c5d302b30\n"
".quad 0x617262090a3b3135,0x4c240920696e752e,0x303139375f305f74,0x305f744c240a3b36\n"
".quad 0x0a3a38333338375f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a34313335345f,0x09363109636f6c2e,0x73090a3009353431,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x2c5d302b39316472,0x2e090a3b37662520,0x3109363109636f6c\n"
".quad 0x7473090a30093634,0x2e6465726168732e,0x72255b0920323366,0x202c5d302b303264\n"
".quad 0x7262090a3b356625,0x240920696e752e61,0x3139375f305f744c,0x5f744c240a3b3630\n"
".quad 0x3a36323837375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34313335345f30,0x363109636f6c2e09,0x090a300937323109,0x65726168732e7473\n"
".quad 0x5b09203631752e64,0x5d302b3631647225,0x0a3b35347225202c,0x363109636f6c2e09\n"
".quad 0x090a300938323109,0x65726168732e7473,0x5b09203631752e64,0x5d302b3731647225\n"
".quad 0x0a3b33347225202c,0x3233662e62757309,0x202c323566250920,0x356625202c366625\n"
".quad 0x662e736261090a3b,0x3335662509203233,0x0a3b32356625202c,0x3436662e74766309\n"
".quad 0x662509203233662e,0x33356625202c3964,0x662e736261090a3b,0x3435662509203233\n"
".quad 0x090a3b366625202c,0x203233662e78616d,0x25202c3535662509,0x356625202c353266\n"
".quad 0x636f6c2e090a3b34,0x0934303309373109,0x61702e646c090a30,0x203233662e6d6172\n"
".quad 0x5b202c3632662509,0x6170616475635f5f,0x6237315a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f\n"
".quad 0x5f30535f30535f53,0x655f5f30535f3053,0x3b5d6e6f6c697370,0x3109636f6c2e090a\n"
".quad 0x0a30093832310936,0x3233662e6c756d09,0x202c363566250920,0x6625202c36326625\n"
".quad 0x747663090a3b3535,0x3233662e3436662e,0x2c30316466250920,0x090a3b3635662520\n"
".quad 0x203436662e766f6d,0x202c313164662509,0x3434353638336430,0x6532643233393438\n"
".quad 0x35202f2f093b3237,0x616d090a37332d65,0x2509203436662e78,0x6625202c32316466\n"
".quad 0x646625202c303164,0x746573090a3b3131,0x3436662e656c2e70,0x202c363270250920\n"
".quad 0x6625202c39646625,0x2140090a3b323164,0x6172622036327025,0x5f305f744c240920\n"
".quad 0x200a3b3236333937,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c363532,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x6d090a3431333534,0x09203233662e766f,0x6630202c37356625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x70746573090a3020,0x203233662e746c2e,0x25202c3732702509\n"
".quad 0x37356625202c3566,0x702e766f6d090a3b,0x3270250920646572,0x3b37327025202c38\n"
".quad 0x72702e766f6d090a,0x3932702509206465,0x0a3b30337025202c,0x3233662e766f6d09\n"
".quad 0x202c383566250920,0x3030303030306630,0x09202020203b3030,0x6573090a30202f2f\n"
".quad 0x33662e746c2e7074,0x2c31337025092032,0x6625202c36662520,0x252140090a3b3835\n"
".quad 0x2061726220313370,0x375f305f744c2409,0x2f200a3b34373839,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635\n"
".quad 0x64656c6562616c20,0x345f305f744c2420,0x6c2e090a34313335,0x333109363109636f\n"
".quad 0x6c6573090a300936,0x2509203233732e70,0x202c31202c363572,0x3b38327025202c30\n"
".quad 0x6e752e617262090a,0x305f744c24092069,0x0a3b38313639375f,0x39375f305f744c24\n"
".quad 0x2f2f200a3a343738,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6c6573090a343133,0x2509203233732e70,0x202c30202c363572,0x3b37327025202c31\n"
".quad 0x375f305f744c240a,0x2f200a3a38313639,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20\n"
".quad 0x345f305f744c2420,0x6c2e090a34313335,0x333109363109636f,0x646461090a300939\n"
".quad 0x662509203233662e,0x2c356625202c3935,0x6d090a3b36662520,0x09203233662e766f\n"
".quad 0x6630202c30366625,0x3030303030306633,0x2f2f09202020203b,0x616d090a352e3020\n"
".quad 0x2509203233662e64,0x356625202c313666,0x2c30366625202c32,0x6d090a3b35662520\n"
".quad 0x09203233662e766f,0x6630202c32366625,0x3030303030306633,0x2f2f09202020203b\n"
".quad 0x756d090a352e3020,0x2509203233662e6c,0x356625202c333666,0x3b32366625202c39\n"
".quad 0x33732e67656e090a,0x2c37357225092032,0x090a3b3635722520,0x3233662e74636c73\n"
".quad 0x662509203233732e,0x33366625202c3436,0x202c31366625202c,0x73090a3b37357225\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x2c5d302b39316472,0x090a3b3436662520\n"
".quad 0x09363109636f6c2e,0x73090a3009303431,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d302b30326472,0x090a3b3436662520,0x20696e752e617262,0x375f305f744c2409\n"
".quad 0x4c240a3b36303139,0x363339375f305f74,0x6c3c2f2f200a3a32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x3009353431093631\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x2b39316472255b09,0x3b356625202c5d30\n"
".quad 0x3109636f6c2e090a,0x0a30093634310936,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b30326472255b,0x0a3b366625202c5d,0x39375f305f744c24,0x744c240a3a363031\n"
".quad 0x30373537375f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313335345f305f,0x3109636f6c2e090a,0x0a30093233390937,0x3233752e766f6d09\n"
".quad 0x202c363172250920,0x2e617262090a3b30,0x744c240920696e75,0x32323535375f305f\n"
".quad 0x5f305f744c240a3b,0x200a3a3837373537,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3431333534,0x3309373109636f6c,0x7473090a30093831\n"
".quad 0x2e6465726168732e,0x72255b0920323366,0x202c5d302b303164,0x6c2e090a3b376625\n"
".quad 0x313309373109636f,0x2e7473090a300939,0x662e646572616873,0x6472255b09203233\n"
".quad 0x25202c5d302b3131,0x6f6c2e090a3b3766,0x3032330937310963,0x732e7473090a3009\n"
".quad 0x31752e6465726168,0x316472255b092036,0x7225202c5d302b32,0x6f6c2e090a3b3434\n"
".quad 0x3132330937310963,0x732e7473090a3009,0x31752e6465726168,0x316472255b092036\n"
".quad 0x7225202c5d302b33,0x6f6c2e090a3b3334,0x3332330937310963,0x2e766f6d090a3009\n"
".quad 0x3172250920323375,0x4c240a3b30202c36,0x323535375f305f74,0x305f744c240a3a32\n"
".quad 0x0a3a30313035375f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a34313335345f,0x09373109636f6c2e,0x62090a3009383233,0x20636e79732e7261\n"
".quad 0x2e646c090a3b3009,0x752e646572616873,0x3835722509203233,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x323836335f726176,0x6e6f6e5f30345f30,0x635f74736e6f635f\n"
".quad 0x735f746361706d6f,0x68635f646e6f6365,0x6d090a3b5d6b6e75,0x09203233752e766f\n"
".quad 0x3b30202c39357225,0x652e70746573090a,0x2509203233752e71,0x357225202c323370\n"
".quad 0x3b39357225202c38,0x203233702540090a,0x744c240920617262,0x34313733385f305f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36353220656e,0x62616c2064616568,0x744c242064656c65,0x34313335345f305f\n"
".quad 0x3109636f6c2e090a,0x0a30093633330937,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5f5b202c30367225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3832383633\n"
".quad 0x6e6f635f6e6f6e5f,0x745f6d756e5f7473,0x635f736461657268,0x6f69746361706d6f\n"
".quad 0x6f6c2e090a3b5d6e,0x3736330936310963,0x2e726873090a3009,0x3672250920323375\n"
".quad 0x2c30367225202c31,0x766f6d090a3b3120,0x722509203233732e,0x31367225202c3236\n"
".quad 0x752e766f6d090a3b,0x3336722509203233,0x6573090a3b30202c,0x33732e656c2e7074\n"
".quad 0x2c33337025092032,0x25202c3136722520,0x2540090a3b333672,0x2061726220333370\n"
".quad 0x315f305f744c2409,0x200a3b3037353930,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x6d090a3431333534,0x09203233752e766f,0x3b31202c34367225\n"
".quad 0x385f305f744c240a,0x2f200a3a34353131,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3320656e696c2079,0x636f6c2e090a3936,0x0939363309363109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x656c2e7074657309,0x702509203233752e,0x32367225202c3433\n"
".quad 0x090a3b357225202c,0x7262203433702540,0x305f744c24092061,0x0a3b30313431385f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39363320,0x6c6562616c206461,0x305f744c24206465,0x090a34353131385f\n"
".quad 0x09363109636f6c2e,0x61090a3009393733,0x09203233752e6464,0x7225202c35367225\n"
".quad 0x090a3b31202c3331,0x203233752e646461,0x25202c3636722509,0x0a3b32202c333172\n"
".quad 0x2e6f6c2e6c756d09,0x3672250920323375,0x2c35367225202c37,0x090a3b3436722520\n"
".quad 0x752e6f6c2e6c756d,0x3836722509203233,0x202c36367225202c,0x6d090a3b34367225\n"
".quad 0x09203233752e766f,0x3b30202c39367225,0x6e2e70746573090a,0x2509203233752e65\n"
".quad 0x367225202c353370,0x3b39367225202c38,0x33752e627573090a,0x2c30377225092032\n"
".quad 0x31202c3836722520,0x752e766f6d090a3b,0x3137722509203233,0x6573090a3b30202c\n"
".quad 0x09203233752e706c,0x7225202c32377225,0x31377225202c3037,0x0a3b35337025202c\n"
".quad 0x2e6f6c2e6c756d09,0x3772250920323375,0x2c32377225202c33,0x747663090a3b3220\n"
".quad 0x3233752e3436752e,0x2c31336472250920,0x090a3b3337722520,0x203436752e646461\n"
".quad 0x202c323364722509,0x25202c3133647225,0x646c090a3b336472,0x2e6465726168732e\n"
".quad 0x6872250920363175,0x336472255b202c36,0x73090a3b5d322b32,0x09203233752e6275\n"
".quad 0x7225202c34377225,0x090a3b31202c3736,0x203233752e766f6d,0x30202c3537722509\n"
".quad 0x752e766f6d090a3b,0x3637722509203233,0x6573090a3b30202c,0x33752e656e2e7074\n"
".quad 0x2c36337025092032,0x25202c3736722520,0x6573090a3b363772,0x09203233752e706c\n"
".quad 0x7225202c37377225,0x35377225202c3437,0x0a3b36337025202c,0x2e6f6c2e6c756d09\n"
".quad 0x3772250920323375,0x2c37377225202c38,0x747663090a3b3220,0x3233752e3436752e\n"
".quad 0x2c33336472250920,0x090a3b3837722520,0x203436752e646461,0x202c343364722509\n"
".quad 0x25202c3333647225,0x646c090a3b336472,0x2e6465726168732e,0x6872250920363175\n"
".quad 0x336472255b202c37,0x61090a3b5d322b34,0x09203631752e6464,0x7225202c38687225\n"
".quad 0x37687225202c3668,0x68732e7473090a3b,0x3631752e64657261,0x32336472255b0920\n"
".quad 0x687225202c5d322b,0x305f744c240a3b38,0x0a3a30313431385f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363320\n"
".quad 0x6c6562616c206461,0x305f744c24206465,0x090a34353131385f,0x09363109636f6c2e\n"
".quad 0x73090a3009333833,0x09203233622e6c68,0x7225202c34367225,0x090a3b31202c3436\n"
".quad 0x09363109636f6c2e,0x73090a3009373633,0x09203233732e7268,0x7225202c32367225\n"
".quad 0x090a3b31202c3236,0x203233752e766f6d,0x30202c3937722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x7225202c37337025,0x39377225202c3236,0x3733702540090a3b\n"
".quad 0x4c24092061726220,0x353131385f305f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x752e617262090a34,0x5f744c240920696e\n"
".quad 0x3b32343630385f30,0x315f305f744c240a,0x200a3a3037353930,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532\n"
".quad 0x656c6562616c2064,0x5f305f744c242064,0x6d090a3431333534,0x09203233752e766f\n"
".quad 0x3b31202c34367225,0x385f305f744c240a,0x2f200a3a32343630,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635\n"
".quad 0x64656c6562616c20,0x345f305f744c2420,0x6f6d090a34313335,0x2509203233752e76\n"
".quad 0x0a3b32202c303872,0x656c2e7074657309,0x702509203233752e,0x30367225202c3833\n"
".quad 0x0a3b30387225202c,0x6220383370254009,0x5f744c2409206172,0x3b38373132385f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30\n"
".quad 0x3233732e766f6d09,0x202c313872250920,0x305f744c240a3b32,0x0a3a30393632385f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x656e202c37363320\n"
".quad 0x656420676e697473,0x202c31203a687470,0x6574616d69747365,0x7461726574692064\n"
".quad 0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3309363109636f6c,0x6873090a30093938\n"
".quad 0x2509203233752e72,0x367225202c343672,0x2e090a3b31202c34,0x3309363109636f6c\n"
".quad 0x6162090a30093039,0x0920636e79732e72,0x2e627573090a3b30,0x3872250920323375\n"
".quad 0x2c31387225202c32,0x746573090a3b3120,0x3233752e65672e70,0x202c393370250920\n"
".quad 0x387225202c357225,0x33702540090a3b32,0x2409206172622039,0x3932385f305f744c\n"
".quad 0x3c2f2f200a3b3634,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x37363320656e696c,0x6c2064616568202c,0x242064656c656261,0x3632385f305f744c\n"
".quad 0x636f6c2e090a3039,0x0937393309363109,0x752e646461090a30,0x3338722509203233\n"
".quad 0x31202c357225202c,0x752e726873090a3b,0x3438722509203233,0x202c34367225202c\n"
".quad 0x2e6c756d090a3b31,0x09203233752e6f6c,0x7225202c35387225,0x34367225202c3338\n"
".quad 0x752e646461090a3b,0x3638722509203233,0x202c34387225202c,0x6d090a3b35387225\n"
".quad 0x33752e6f6c2e6c75,0x2c37387225092032,0x32202c3638722520,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3533647225,0x6461090a3b373872,0x2509203436752e64\n"
".quad 0x7225202c36336472,0x647225202c353364,0x732e646c090a3b33,0x31752e6465726168\n"
".quad 0x2c39687225092036,0x2b36336472255b20,0x6c756d090a3b5d30,0x203233752e6f6c2e\n"
".quad 0x25202c3838722509,0x0a3b32202c353872,0x3436752e74766309,0x722509203233752e\n"
".quad 0x387225202c373364,0x2e646461090a3b38,0x6472250920343675,0x33647225202c3833\n"
".quad 0x3b33647225202c37,0x6168732e646c090a,0x203631752e646572,0x202c303168722509\n"
".quad 0x302b38336472255b,0x2e646461090a3b5d,0x6872250920363175,0x39687225202c3131\n"
".quad 0x3b3031687225202c,0x6168732e7473090a,0x203631752e646572,0x2b36336472255b09\n"
".quad 0x31687225202c5d30,0x305f744c240a3b31,0x0a3a36343932385f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c37363320\n"
".quad 0x6c6562616c206461,0x305f744c24206465,0x090a30393632385f,0x09363109636f6c2e\n"
".quad 0x73090a3009373833,0x09203233622e6c68,0x7225202c31387225,0x090a3b31202c3138\n"
".quad 0x2e746c2e70746573,0x3470250920323375,0x2c31387225202c30,0x090a3b3036722520\n"
".quad 0x7262203034702540,0x305f744c24092061,0x0a3b30393632385f,0x32385f305f744c24\n"
".quad 0x2f2f200a3a383731,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6f6c2e090a343133,0x3230340936310963,0x2e726162090a3009,0x3b300920636e7973\n"
".quad 0x3109636f6c2e090a,0x0a30093833330937,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5f5b202c39387225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3532383633\n"
".quad 0x6e6f635f6e6f6e5f,0x745f6d756e5f7473,0x615f736461657268,0x0a3b5d6576697463\n"
".quad 0x3233752e766f6d09,0x202c303972250920,0x2e746573090a3b31,0x752e3233752e7165\n"
".quad 0x3139722509203233,0x202c36317225202c,0x6e090a3b30397225,0x09203233732e6765\n"
".quad 0x7225202c32397225,0x746573090a3b3139,0x2e3233752e74672e,0x3972250920323375\n"
".quad 0x2c39387225202c33,0x6e090a3b35722520,0x09203233732e6765,0x7225202c34397225\n"
".quad 0x646e61090a3b3339,0x722509203233622e,0x32397225202c3539,0x0a3b34397225202c\n"
".quad 0x3233752e766f6d09,0x202c363972250920,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x25202c3134702509,0x397225202c353972,0x34702540090a3b36,0x2409206172622031\n"
".quad 0x3733385f305f744c,0x3c2f2f200a3b3431,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x36353220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3335345f305f744c,0x636f6c2e090a3431,0x0930343409363109,0x68732e646c090a30\n"
".quad 0x3631752e64657261,0x202c373972250920,0x302b38316472255b,0x636f6c2e090a3b5d\n"
".quad 0x0938333309373109,0x68732e646c090a30,0x3233752e64657261,0x202c393872250920\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f35323836335f72,0x635f6e6f6e5f3034\n"
".quad 0x6d756e5f74736e6f,0x736461657268745f,0x5d6576697463615f,0x09636f6c2e090a3b\n"
".quad 0x3009303434093631,0x33752e646461090a,0x2c38397225092032,0x25202c3938722520\n"
".quad 0x6c2e090a3b373972,0x343409363109636f,0x6c756d090a300932,0x203233752e6f6c2e\n"
".quad 0x25202c3939722509,0x0a3b34202c383972,0x3436752e74766309,0x722509203233752e\n"
".quad 0x397225202c393364,0x2e646461090a3b39,0x6472250920343675,0x33647225202c3034\n"
".quad 0x3b31647225202c39,0x6168732e7473090a,0x203233662e646572,0x2b30346472255b09\n"
".quad 0x3b356625202c5d30,0x3109636f6c2e090a,0x0a30093334340936,0x3436752e64646109\n"
".quad 0x2c31346472250920,0x202c393364722520,0x73090a3b34647225,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x2c5d302b31346472,0x2e090a3b36662520,0x3409363109636f6c\n"
".quad 0x756d090a30093434,0x3233752e6f6c2e6c,0x2c30303172250920,0x32202c3839722520\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x25202c3234647225,0x63090a3b30303172\n"
".quad 0x752e3631752e7476,0x3031722509203233,0x3b31337225202c31,0x36752e646461090a\n"
".quad 0x3334647225092034,0x2c3234647225202c,0x090a3b3264722520,0x65726168732e7473\n"
".quad 0x5b09203631752e64,0x5d302b3334647225,0x3b3130317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093534340936,0x3631752e74766309,0x722509203233752e,0x337225202c323031\n"
".quad 0x752e646461090a3b,0x3464722509203436,0x3234647225202c34,0x0a3b35647225202c\n"
".quad 0x726168732e747309,0x09203631752e6465,0x302b34346472255b,0x3230317225202c5d\n"
".quad 0x5f305f744c240a3b,0x240a3a3431373338,0x3130385f305f744c,0x3c2f2f200a3a3033\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x36353220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3335345f305f744c,0x636f6c2e090a3431\n"
".quad 0x0934343309373109,0x732e726162090a30,0x0a3b300920636e79,0x6220317025214009\n"
".quad 0x5f744c2409206172,0x3b36323234385f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x373109636f6c2e09,0x090a300930353309\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5b202c33303172,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3532383633,0x6e6f635f6e6f6e5f,0x745f6d756e5f7473\n"
".quad 0x615f736461657268,0x0a3b5d6576697463,0x3436752e74766309,0x722509203233752e\n"
".quad 0x317225202c353464,0x6c756d090a3b3330,0x33752e656469772e,0x3634647225092032\n"
".quad 0x2c3330317225202c,0x646461090a3b3220,0x722509203436752e,0x647225202c373464\n"
".quad 0x3634647225202c33,0x68732e646c090a3b,0x3631752e64657261,0x2c34303172250920\n"
".quad 0x2b37346472255b20,0x646461090a3b5d30,0x722509203233752e,0x30317225202c3938\n"
".quad 0x3430317225202c33,0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920\n"
".quad 0x5f6c61636f6c5f61,0x323836335f726176,0x6e6f6e5f30345f35,0x6e5f74736e6f635f\n"
".quad 0x61657268745f6d75,0x76697463615f7364,0x39387225202c5d65,0x09636f6c2e090a3b\n"
".quad 0x3009313533093731,0x33732e627573090a,0x3530317225092032,0x202c39387225202c\n"
".quad 0x2e646e61090a3b31,0x3172250920323362,0x39387225202c3630,0x3b3530317225202c\n"
".quad 0x33752e766f6d090a,0x3730317225092032,0x6573090a3b30202c,0x33732e656e2e7074\n"
".quad 0x2c32347025092032,0x202c363031722520,0x090a3b3730317225,0x7262203234702540\n"
".quad 0x305f744c24092061,0x0a3b38333734385f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a34313335345f,0x09363109636f6c2e,0x6f6d090a30093337\n"
".quad 0x2509203233732e76,0x7225202c38303172,0x617262090a3b3938,0x4c240920696e752e\n"
".quad 0x665f69646e655744,0x32325f6670786572,0x744c240a3b325f33,0x38333734385f305f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36353220656e,0x62616c2064616568,0x744c242064656c65,0x34313335345f305f\n"
".quad 0x3109636f6c2e090a,0x0a30093538320939,0x2e6e722e74766309,0x203233732e323366\n"
".quad 0x25202c3536662509,0x6f6d090a3b393872,0x2509203233662e76,0x366625202c363666\n"
".quad 0x2e736261090a3b35,0x3666250920323366,0x3b35366625202c37,0x33662e766f6d090a\n"
".quad 0x2c38366625092032,0x3030383030663020,0x202020203b303030,0x37312e31202f2f09\n"
".quad 0x0a38332d65393435,0x746c2e7074657309,0x702509203233662e,0x37366625202c3334\n"
".quad 0x0a3b38366625202c,0x2033347025214009,0x744c240920617262,0x36303535385f305f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36353220656e,0x62616c2064616568,0x744c242064656c65,0x34313335345f305f\n"
".quad 0x3209636f6c2e090a,0x3009333633320931,0x33662e766f6d090a,0x2c39366625092032\n"
".quad 0x3030386234663020,0x202020203b303030,0x37362e31202f2f09,0x0a37302b65323737\n"
".quad 0x3233662e6c756d09,0x202c363666250920,0x6625202c35366625,0x766f6d090a3b3936\n"
".quad 0x722509203233752e,0x3b3432202c393031,0x6e752e617262090a,0x305f744c24092069\n"
".quad 0x0a3b30353235385f,0x35385f305f744c24,0x2f2f200a3a363035,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133,0x3633320931320963\n"
".quad 0x766f6d090a300936,0x722509203233752e,0x0a3b30202c393031,0x35385f305f744c24\n"
".quad 0x2f2f200a3a303532,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6f6c2e090a343133,0x0938370936310963,0x622e766f6d090a30,0x3131722509203233\n"
".quad 0x3b36366625202c30,0x33732e726873090a,0x3131317225092032,0x2c3031317225202c\n"
".quad 0x6e61090a3b333220,0x2509203233622e64,0x7225202c32313172,0x353532202c313131\n"
".quad 0x752e766f6d090a3b,0x3131722509203233,0x73090a3b30202c33,0x09203233752e6275\n"
".quad 0x25202c3431317225,0x7225202c32313172,0x7573090a3b393031,0x2509203233752e62\n"
".quad 0x7225202c35313172,0x363231202c343131,0x752e766f6d090a3b,0x3131722509203233\n"
".quad 0x0a3b353532202c36,0x2e71652e74657309,0x203233752e323375,0x202c373131722509\n"
".quad 0x25202c3231317225,0x6e090a3b36313172,0x09203233732e6765,0x25202c3831317225\n"
".quad 0x6d090a3b37313172,0x09203233662e766f,0x6630202c30376625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e746573090a3020,0x662e3233752e7165,0x3131722509203233\n"
".quad 0x2c37366625202c39,0x090a3b3037662520,0x203233732e67656e,0x202c303231722509\n"
".quad 0x090a3b3931317225,0x09203233622e726f,0x25202c3132317225,0x7225202c38313172\n"
".quad 0x656e090a3b303231,0x2509203233732e67,0x7225202c32323172,0x6c73090a3b313231\n"
".quad 0x732e3233752e7463,0x3231722509203233,0x3531317225202c33,0x2c3331317225202c\n"
".quad 0x0a3b323231722520,0x3233622e6c687309,0x2c38303172250920,0x32317225202c3120\n"
".quad 0x6557444c240a3b33,0x786572665f69646e,0x325f3332325f6670,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a\n"
".quad 0x0a30093135330937,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f38323836335f72,0x635f6e6f6e5f3034,0x6d756e5f74736e6f\n"
".quad 0x736461657268745f,0x746361706d6f635f,0x7225202c5d6e6f69,0x6c2e090a3b383031\n"
".quad 0x353309373109636f,0x766f6d090a300933,0x722509203233752e,0x0a3b30202c343231\n"
".quad 0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f30323836335f72,0x635f6e6f6e5f3034,0x6d6f635f74736e6f,0x6365735f74636170\n"
".quad 0x6e7568635f646e6f,0x32317225202c5d6b,0x636f6c2e090a3b34,0x0934353309373109\n"
".quad 0x752e766f6d090a30,0x3231722509203233,0x73090a3b31202c35,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3232383633\n"
".quad 0x6e6f635f6e6f6e5f,0x745f6c6c615f7473,0x635f736461657268,0x6465677265766e6f\n"
".quad 0x3532317225202c5d,0x5f305f744c240a3b,0x200a3a3632323438,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363532\n"
".quad 0x656c6562616c2064,0x5f305f744c242064,0x2e090a3431333534,0x3309373109636f6c\n"
".quad 0x6162090a30093735,0x0920636e79732e72,0x636f6c2e090a3b30,0x0930363309373109\n"
".quad 0x68732e646c090a30,0x3233752e64657261,0x2c36323172250920,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x38323836335f7261,0x5f6e6f6e5f30345f,0x756e5f74736e6f63\n"
".quad 0x6461657268745f6d,0x6361706d6f635f73,0x090a3b5d6e6f6974,0x2e74672e70746573\n"
".quad 0x3470250920323375,0x3632317225202c34,0x0a3b35317225202c,0x6220343470254009\n"
".quad 0x5f744c2409206172,0x3230383830315f30,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34313335345f305f,0x6e752e617262090a,0x305f744c24092069\n"
".quad 0x0a3b34313335345f,0x30315f305f744c24,0x4c240a3a32303838,0x3a3835325f305f74\n"
".quad 0x3109636f6c2e090a,0x0a30093436330937,0x6e79732e72616209,0x2e090a3b30092063\n"
".quad 0x3309373109636f6c,0x646c090a30093937,0x2e6465726168732e,0x3172250920363175\n"
".quad 0x32316472255b202c,0x6c2e090a3b5d302b,0x383309373109636f,0x2e646c090a300930\n"
".quad 0x752e646572616873,0x2c33722509203631,0x2b33316472255b20,0x646461090a3b5d30\n"
".quad 0x722509203233752e,0x317225202c373231,0x0a3b357225202c35,0x3436752e74766309\n"
".quad 0x722509203233752e,0x317225202c383464,0x6c756d090a3b3732,0x33752e656469772e\n"
".quad 0x3934647225092032,0x2c3732317225202c,0x2e646c090a3b3220,0x752e646572616873\n"
".quad 0x3231722509203233,0x75635f5f5b202c38,0x6c61636f6c5f6164,0x3836335f7261765f\n"
".quad 0x6f6e5f30345f3532,0x5f74736e6f635f6e,0x657268745f6d756e,0x697463615f736461\n"
".quad 0x6573090a3b5d6576,0x33752e656c2e7074,0x2c35347025092032,0x202c383231722520\n"
".quad 0x090a3b3732317225,0x7262203534702540,0x305f744c24092061,0x0a3b32363735385f\n"
".quad 0x373109636f6c2e09,0x090a300934383309,0x203436752e646461,0x202c303564722509\n"
".quad 0x25202c3934647225,0x646c090a3b326472,0x2e6465726168732e,0x3172250920363175\n"
".quad 0x6472255b202c3932,0x090a3b5d302b3035,0x203233732e766f6d,0x202c303331722509\n"
".quad 0x090a3b3932317225,0x09373109636f6c2e,0x61090a3009353833,0x09203436752e6464\n"
".quad 0x25202c3135647225,0x7225202c39346472,0x2e646c090a3b3564,0x752e646572616873\n"
".quad 0x3331722509203631,0x356472255b202c31,0x6d090a3b5d302b31,0x09203233732e766f\n"
".quad 0x25202c3233317225,0x4c240a3b31333172,0x363735385f305f74,0x70252140090a3a32\n"
".quad 0x2409206172622031,0x3236385f305f744c,0x6f6c2e090a3b3437,0x3130340937310963\n"
".quad 0x2e766f6d090a3009,0x6872250920363175,0x090a3b30202c3231,0x65726168732e7473\n"
".quad 0x5b09203631752e64,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32345f3131383633,0x6e6f635f6e6f6e5f,0x66656c5f735f7473,0x32746e756f635f74\n"
".quad 0x202c5d302b303831,0x090a3b3231687225,0x09373109636f6c2e,0x6d090a3009323034\n"
".quad 0x09203631752e766f,0x30202c3331687225,0x68732e7473090a3b,0x3631752e64657261\n"
".quad 0x6475635f5f5b0920,0x616475635f5f5f61,0x765f6c61636f6c5f,0x32313836335f7261\n"
".quad 0x5f6e6f6e5f32345f,0x5f735f74736e6f63,0x6f635f7468676972,0x2b34383236746e75\n"
".quad 0x31687225202c5d30,0x305f744c240a3b33,0x0a3a34373236385f,0x373109636f6c2e09\n"
".quad 0x090a300935303409,0x636e79732e726162,0x6f6d090a3b300920,0x2509203436752e76\n"
".quad 0x5f5f202c32356472,0x635f5f5f61647563,0x61636f6c5f616475,0x37335f7261765f6c\n"
".quad 0x6e5f32345f313130,0x74736e6f635f6e6f,0x65685f6c635f735f,0x303133377265706c\n"
".quad 0x09636f6c2e090a3b,0x3009353134093731,0x33752e627573090a,0x3333317225092032\n"
".quad 0x25202c337225202c,0x766f6d090a3b3172,0x722509203233752e,0x0a3b31202c343331\n"
".quad 0x71652e7074657309,0x702509203233752e,0x33317225202c3634,0x3433317225202c33\n"
".quad 0x2e706c6573090a3b,0x3172250920323373,0x30202c31202c3533,0x0a3b36347025202c\n"
".quad 0x726168732e747309,0x09203631752e6465,0x322b36316472255b,0x3533317225202c5d\n"
".quad 0x09636f6c2e090a3b,0x3009363134093731,0x33752e766f6d090a,0x3633317225092032\n"
".quad 0x6573090a3b31202c,0x33752e656e2e7074,0x2c37347025092032,0x202c333331722520\n"
".quad 0x090a3b3633317225,0x3233732e706c6573,0x2c37333172250920,0x25202c30202c3120\n"
".quad 0x7473090a3b373470,0x2e6465726168732e,0x72255b0920363175,0x202c5d322b373164\n"
".quad 0x090a3b3733317225,0x09373109636f6c2e,0x6d090a3009393134,0x09203233752e766f\n"
".quad 0x30202c3833317225,0x2e706c6573090a3b,0x3172250920323375,0x33317225202c3933\n"
".quad 0x3833317225202c33,0x0a3b37347025202c,0x726168732e747309,0x09203631752e6465\n"
".quad 0x322b38316472255b,0x3933317225202c5d,0x09636f6c2e090a3b,0x3009303234093731\n"
".quad 0x36752e646461090a,0x3335647225092034,0x202c37647225202c,0x090a3b3235647225\n"
".quad 0x203631752e766f6d,0x202c343168722509,0x732e7473090a3b30,0x31752e6465726168\n"
".quad 0x356472255b092036,0x7225202c5d302b33,0x6461090a3b343168,0x2509203436752e64\n"
".quad 0x7225202c34356472,0x647225202c393464,0x2e646c090a3b3235,0x752e646572616873\n"
".quad 0x3431722509203233,0x75635f5f5b202c30,0x6c61636f6c5f6164,0x3836335f7261765f\n"
".quad 0x6f6e5f30345f3532,0x5f74736e6f635f6e,0x657268745f6d756e,0x697463615f736461\n"
".quad 0x6573090a3b5d6576,0x33752e656c2e7074,0x2c38347025092032,0x202c303431722520\n"
".quad 0x090a3b3732317225,0x7262203834702540,0x305f744c24092061,0x0a3b32343037385f\n"
".quad 0x373109636f6c2e09,0x090a300935323409,0x203233732e766f6d,0x202c313431722509\n"
".quad 0x090a3b3233317225,0x203233732e766f6d,0x202c323431722509,0x090a3b3033317225\n"
".quad 0x203233752e627573,0x202c333431722509,0x25202c3134317225,0x6d090a3b32343172\n"
".quad 0x09203233752e766f,0x31202c3434317225,0x2e70746573090a3b,0x09203233752e7165\n"
".quad 0x7225202c39347025,0x317225202c333431,0x6c6573090a3b3434,0x2509203233732e70\n"
".quad 0x2c31202c35343172,0x39347025202c3020,0x732e766f6d090a3b,0x3431722509203233\n"
".quad 0x3534317225202c36,0x09636f6c2e090a3b,0x3009373234093731,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x317225202c373431,0x090a3b32202c3732,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x34317225202c3535,0x2e646461090a3b37,0x6472250920343675\n"
".quad 0x35647225202c3635,0x3b32647225202c35,0x6168732e7473090a,0x203631752e646572\n"
".quad 0x2b36356472255b09,0x34317225202c5d32,0x636f6c2e090a3b35,0x0938323409373109\n"
".quad 0x752e766f6d090a30,0x3431722509203233,0x73090a3b31202c38,0x752e656e2e707465\n"
".quad 0x3035702509203233,0x2c3334317225202c,0x0a3b383431722520,0x33732e706c657309\n"
".quad 0x3934317225092032,0x202c30202c31202c,0x61090a3b30357025,0x09203436752e6464\n"
".quad 0x25202c3735647225,0x7225202c35356472,0x2e7473090a3b3564,0x752e646572616873\n"
".quad 0x6472255b09203631,0x25202c5d322b3735,0x2e090a3b39343172,0x3409373109636f6c\n"
".quad 0x6f6d090a30093133,0x2509203233752e76,0x3b30202c30353172,0x752e706c6573090a\n"
".quad 0x3531722509203233,0x3334317225202c31,0x2c3035317225202c,0x090a3b3035702520\n"
".quad 0x203436752e646461,0x202c383564722509,0x25202c3535647225,0x7473090a3b336472\n"
".quad 0x2e6465726168732e,0x72255b0920363175,0x202c5d322b383564,0x090a3b3135317225\n"
".quad 0x09373109636f6c2e,0x6d090a3009323334,0x09203631752e766f,0x30202c3531687225\n"
".quad 0x68732e7473090a3b,0x3631752e64657261,0x34356472255b0920,0x687225202c5d302b\n"
".quad 0x617262090a3b3531,0x4c240920696e752e,0x383736385f305f74,0x305f744c240a3b36\n"
".quad 0x0a3a32343037385f,0x3233752e766f6d09,0x2c32353172250920,0x73090a3b32313520\n"
".quad 0x752e74672e707465,0x3135702509203233,0x2c3732317225202c,0x0a3b323531722520\n"
".quad 0x6220313570254009,0x5f744c2409206172,0x3b38393237385f30,0x3109636f6c2e090a\n"
".quad 0x0a30093733340937,0x3631752e766f6d09,0x2c36316872250920,0x6c756d090a3b3020\n"
".quad 0x203233752e6f6c2e,0x202c333531722509,0x32202c3732317225,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3935647225,0x61090a3b33353172,0x09203436752e6464\n"
".quad 0x25202c3036647225,0x7225202c39356472,0x2e7473090a3b3364,0x752e646572616873\n"
".quad 0x6472255b09203631,0x25202c5d322b3036,0x2e090a3b36316872,0x3409373109636f6c\n"
".quad 0x6f6d090a30093833,0x2509203631752e76,0x3b30202c37316872,0x6168732e7473090a\n"
".quad 0x203631752e646572,0x2b34356472255b09,0x31687225202c5d30,0x305f744c240a3b37\n"
".quad 0x0a3a38393237385f,0x3233752e766f6d09,0x2c36343172250920,0x5f744c240a3b3020\n"
".quad 0x3a36383736385f30,0x3109636f6c2e090a,0x0a30093234340937,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x5b202c3435317225,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f38323836335f,0x6f635f6e6f6e5f30,0x5f6d756e5f74736e,0x5f73646165726874\n"
".quad 0x69746361706d6f63,0x6c2e090a3b5d6e6f,0x313809373109636f,0x726873090a300936\n"
".quad 0x722509203233752e,0x35317225202c3136,0x6d090a3b31202c34,0x09203233732e766f\n"
".quad 0x25202c3535317225,0x6f6d090a3b313672,0x2509203233752e76,0x3b30202c36353172\n"
".quad 0x6c2e70746573090a,0x2509203233732e65,0x367225202c323570,0x3635317225202c31\n"
".quad 0x3235702540090a3b,0x4c24092061726220,0x333031315f305f74,0x766f6d090a3b3833\n"
".quad 0x722509203233752e,0x0a3b31202c373531,0x38385f305f744c24,0x2f2f200a3a323233\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x313820656e696c20,0x09636f6c2e090a38\n"
".quad 0x3009383138093731,0x79732e726162090a,0x090a3b300920636e,0x2e656c2e70746573\n"
".quad 0x3570250920323375,0x3535317225202c33,0x090a3b357225202c,0x7262203335702540\n"
".quad 0x305f744c24092061,0x0a3b34313130395f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c38313820,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a32323338385f,0x09373109636f6c2e,0x61090a3009353238\n"
".quad 0x09203233752e6464,0x25202c3835317225,0x0a3b31202c333172,0x3233752e64646109\n"
".quad 0x202c363672250920,0x3b32202c33317225,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x317225202c393531,0x35317225202c3835,0x2e6c756d090a3b37,0x09203233752e6f6c\n"
".quad 0x25202c3036317225,0x317225202c363672,0x6c756d090a3b3735,0x203233752e6f6c2e\n"
".quad 0x202c313631722509,0x32202c3935317225,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x25202c3136647225,0x6d090a3b31363172,0x33752e6f6c2e6c75,0x3236317225092032\n"
".quad 0x2c3036317225202c,0x747663090a3b3220,0x3233752e3436752e,0x2c32366472250920\n"
".quad 0x0a3b323631722520,0x3436752e64646109,0x2c33366472250920,0x202c323664722520\n"
".quad 0x6c090a3b32647225,0x6465726168732e64,0x722509203631752e,0x72255b202c383168\n"
".quad 0x0a3b5d302b333664,0x3436752e64646109,0x2c34366472250920,0x202c313664722520\n"
".quad 0x6c090a3b32647225,0x6465726168732e64,0x722509203631752e,0x72255b202c393168\n"
".quad 0x0a3b5d302b343664,0x3631752e64646109,0x2c30326872250920,0x202c383168722520\n"
".quad 0x090a3b3931687225,0x65726168732e7473,0x5b09203631752e64,0x5d302b3336647225\n"
".quad 0x3b3032687225202c,0x3109636f6c2e090a,0x0a30093632380937,0x3436752e64646109\n"
".quad 0x2c35366472250920,0x202c323664722520,0x6c090a3b35647225,0x6465726168732e64\n"
".quad 0x722509203631752e,0x72255b202c313268,0x0a3b5d302b353664,0x3436752e64646109\n"
".quad 0x2c36366472250920,0x202c313664722520,0x6c090a3b35647225,0x6465726168732e64\n"
".quad 0x722509203631752e,0x72255b202c323268,0x0a3b5d302b363664,0x3631752e64646109\n"
".quad 0x2c33326872250920,0x202c313268722520,0x090a3b3232687225,0x65726168732e7473\n"
".quad 0x5b09203631752e64,0x5d302b3536647225,0x3b3332687225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093232380937,0x3436752e64646109,0x2c37366472250920,0x202c313664722520\n"
".quad 0x090a3b3235647225,0x203436752e646461,0x202c383664722509,0x25202c3236647225\n"
".quad 0x6c090a3b32356472,0x6465726168732e64,0x722509203631752e,0x72255b202c333631\n"
".quad 0x3b5d322d2b373664,0x33752e766f6d090a,0x3436317225092032,0x6573090a3b31202c\n"
".quad 0x33752e656e2e7074,0x2c34357025092032,0x202c333631722520,0x090a3b3436317225\n"
".quad 0x7262203435702540,0x5f305f4c24092061,0x200a3b3232313936,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383138\n"
".quad 0x656c6562616c2064,0x5f305f744c242064,0x6c090a3232333838,0x6465726168732e64\n"
".quad 0x722509203631752e,0x72255b202c353631,0x3b5d322d2b383664,0x33752e766f6d090a\n"
".quad 0x3636317225092032,0x6573090a3b31202c,0x33752e71652e7074,0x2c35357025092032\n"
".quad 0x202c353631722520,0x090a3b3636317225,0x7262203535702540,0x305f744c24092061\n"
".quad 0x0a3b34313130395f,0x3139365f305f4c24,0x3c2f2f200a3a3232,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x38313820656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3338385f305f744c,0x2e766f6d090a3232,0x3172250920323375\n"
".quad 0x090a3b31202c3736,0x65726168732e646c,0x2509203631752e64,0x255b202c33363172\n"
".quad 0x5d322d2b37366472,0x2e70746573090a3b,0x09203233752e656e,0x7225202c36357025\n"
".quad 0x317225202c333631,0x702540090a3b3736,0x0920617262203635,0x39385f305f744c24\n"
".quad 0x2f2f200a3b363433,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x313820656e696c20,0x2064616568202c38,0x2064656c6562616c,0x38385f305f744c24\n"
".quad 0x6f6c2e090a323233,0x3933380937310963,0x2e766f6d090a3009,0x6872250920363175\n"
".quad 0x090a3b31202c3432,0x65726168732e7473,0x5b09203631752e64,0x322d2b3836647225\n"
".quad 0x3432687225202c5d,0x752e617262090a3b,0x5f744c240920696e,0x3b34313130395f30\n"
".quad 0x385f305f744c240a,0x2f200a3a36343339,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3820656e696c2079,0x64616568202c3831,0x64656c6562616c20\n"
".quad 0x385f305f744c2420,0x646c090a32323338,0x2e6465726168732e,0x3172250920363175\n"
".quad 0x6472255b202c3836,0x0a3b5d322d2b3836,0x3233752e766f6d09,0x2c39363172250920\n"
".quad 0x746573090a3b3120,0x3233752e656e2e70,0x202c373570250920,0x25202c3836317225\n"
".quad 0x40090a3b39363172,0x6172622037357025,0x5f305f744c240920,0x200a3b3835383938\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383138,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3232333838\n"
".quad 0x3809373109636f6c,0x6f6d090a30093334,0x2509203631752e76,0x3b31202c35326872\n"
".quad 0x6168732e7473090a,0x203631752e646572,0x2b37366472255b09,0x687225202c5d322d\n"
".quad 0x617262090a3b3532,0x4c240920696e752e,0x313130395f305f74,0x305f744c240a3b34\n"
".quad 0x0a3a38353839385f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c38313820,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a32323338385f,0x09373109636f6c2e,0x61090a3009373438,0x09203436752e6464\n"
".quad 0x25202c3936647225,0x7225202c31366472,0x646461090a3b3364,0x722509203436752e\n"
".quad 0x647225202c303764,0x33647225202c3236,0x68732e646c090a3b,0x3631752e64657261\n"
".quad 0x2c30373172250920,0x2b39366472255b20,0x2e646c090a3b5d30,0x752e646572616873\n"
".quad 0x3731722509203631,0x376472255b202c31,0x61090a3b5d302b30,0x09203233732e6464\n"
".quad 0x25202c3237317225,0x7225202c30373172,0x6f6d090a3b313731,0x2509203233752e76\n"
".quad 0x3532202c33373172,0x70746573090a3b36,0x203233752e656c2e,0x25202c3835702509\n"
".quad 0x7225202c32373172,0x2540090a3b333731,0x2061726220383570,0x395f305f744c2409\n"
".quad 0x2f200a3b30373330,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x64616568202c3831,0x64656c6562616c20,0x385f305f744c2420\n"
".quad 0x6c2e090a32323338,0x353809373109636f,0x766f6d090a300931,0x722509203631752e\n"
".quad 0x0a3b31202c363268,0x726168732e747309,0x09203631752e6465,0x2d2b37366472255b\n"
".quad 0x32687225202c5d32,0x636f6c2e090a3b36,0x0932353809373109,0x752e766f6d090a30\n"
".quad 0x3268722509203631,0x73090a3b31202c37,0x6465726168732e74,0x255b09203631752e\n"
".quad 0x5d322d2b38366472,0x3b3732687225202c,0x6e752e617262090a,0x305f744c24092069\n"
".quad 0x0a3b34313130395f,0x30395f305f744c24,0x2f2f200a3a303733,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x313820656e696c20,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x38385f305f744c24,0x6f6c2e090a323233,0x3635380937310963\n"
".quad 0x732e7473090a3009,0x31752e6465726168,0x376472255b092036,0x7225202c5d302b30\n"
".quad 0x6c2e090a3b323731,0x353809373109636f,0x766f6d090a300937,0x722509203631752e\n"
".quad 0x0a3b30202c383268,0x726168732e747309,0x09203631752e6465,0x302b39366472255b\n"
".quad 0x3832687225202c5d,0x5f305f744c240a3b,0x240a3a3431313039,0x3639385f305f744c\n"
".quad 0x5f744c240a3a3230,0x3a30393039385f30,0x38365f305f4c240a,0x744c240a3a363638\n"
".quad 0x38373538385f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c38313820656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32323338385f305f,0x3109636f6c2e090a,0x0a30093436380937,0x3233622e6c687309\n"
".quad 0x2c37353172250920,0x202c373531722520,0x636f6c2e090a3b31,0x0936313809373109\n"
".quad 0x732e726873090a30,0x3531722509203233,0x3535317225202c35,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x3b30202c34373172,0x672e70746573090a,0x2509203233732e74\n"
".quad 0x317225202c393570,0x37317225202c3535,0x35702540090a3b34,0x2409206172622039\n"
".quad 0x3338385f305f744c,0x617262090a3b3232,0x4c240920696e752e,0x313837385f305f74\n"
".quad 0x305f744c240a3b30,0x3a3833333031315f,0x33752e766f6d090a,0x3735317225092032\n"
".quad 0x744c240a3b31202c,0x30313837385f305f,0x752e766f6d090a3a,0x3731722509203233\n"
".quad 0x73090a3b32202c35,0x752e656c2e707465,0x3036702509203233,0x2c3435317225202c\n"
".quad 0x0a3b353731722520,0x6220303670254009,0x5f744c2409206172,0x3b32383830395f30\n"
".quad 0x33732e766f6d090a,0x3637317225092032,0x744c240a3b32202c,0x34393331395f305f\n"
".quad 0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220,0x202c36313820656e\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x373109636f6c2e09,0x090a300932373809\n"
".quad 0x203233752e726873,0x202c373531722509,0x31202c3735317225,0x09636f6c2e090a3b\n"
".quad 0x3009333738093731,0x79732e726162090a,0x090a3b300920636e,0x203233752e627573\n"
".quad 0x202c373731722509,0x31202c3637317225,0x2e70746573090a3b,0x09203233752e6567\n"
".quad 0x7225202c31367025,0x3737317225202c35,0x3136702540090a3b,0x4c24092061726220\n"
".quad 0x353631395f305f74,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36313820656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393331395f305f74,0x09636f6c2e090a34,0x3009313838093731,0x33752e646461090a\n"
".quad 0x2c33387225092032,0x3b31202c35722520,0x33752e726873090a,0x3837317225092032\n"
".quad 0x2c3735317225202c,0x6c756d090a3b3120,0x203233752e6f6c2e,0x202c393731722509\n"
".quad 0x7225202c33387225,0x6461090a3b373531,0x2509203233752e64,0x7225202c30383172\n"
".quad 0x317225202c383731,0x6c756d090a3b3937,0x203233752e6f6c2e,0x202c313831722509\n"
".quad 0x32202c3937317225,0x752e747663090a3b,0x09203233752e3436,0x25202c3137647225\n"
".quad 0x6d090a3b31383172,0x33752e6f6c2e6c75,0x3238317225092032,0x2c3038317225202c\n"
".quad 0x747663090a3b3220,0x3233752e3436752e,0x2c32376472250920,0x0a3b323831722520\n"
".quad 0x3436752e64646109,0x2c33376472250920,0x202c323764722520,0x6c090a3b32647225\n"
".quad 0x6465726168732e64,0x722509203631752e,0x72255b202c393268,0x0a3b5d302b333764\n"
".quad 0x3436752e64646109,0x2c34376472250920,0x202c313764722520,0x6c090a3b32647225\n"
".quad 0x6465726168732e64,0x722509203631752e,0x72255b202c303368,0x0a3b5d302b343764\n"
".quad 0x3631752e64646109,0x2c31336872250920,0x202c393268722520,0x090a3b3033687225\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x5d302b3337647225,0x3b3133687225202c\n"
".quad 0x3109636f6c2e090a,0x0a30093238380937,0x3436752e64646109,0x2c35376472250920\n"
".quad 0x202c323764722520,0x6c090a3b35647225,0x6465726168732e64,0x722509203631752e\n"
".quad 0x72255b202c323368,0x0a3b5d302b353764,0x3436752e64646109,0x2c36376472250920\n"
".quad 0x202c313764722520,0x6c090a3b35647225,0x6465726168732e64,0x722509203631752e\n"
".quad 0x72255b202c333368,0x0a3b5d302b363764,0x3631752e64646109,0x2c34336872250920\n"
".quad 0x202c323368722520,0x090a3b3333687225,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x5d302b3537647225,0x3b3433687225202c,0x395f305f744c240a,0x2f200a3a30353631\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079\n"
".quad 0x64616568202c3631,0x64656c6562616c20,0x395f305f744c2420,0x6c2e090a34393331\n"
".quad 0x373809373109636f,0x6c6873090a300930,0x722509203233622e,0x317225202c363731\n"
".quad 0x090a3b31202c3637,0x2e746c2e70746573,0x3670250920323375,0x3637317225202c32\n"
".quad 0x3b3435317225202c,0x203236702540090a,0x744c240920617262,0x34393331395f305f\n"
".quad 0x5f305f744c240a3b,0x090a3a3238383039,0x09373109636f6c2e,0x6c090a3009353434\n"
".quad 0x6465726168732e64,0x722509203233732e,0x5f5f5b202c333831,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f30345f35323836,0x736e6f635f6e6f6e,0x68745f6d756e5f74\n"
".quad 0x63615f7364616572,0x090a3b5d65766974,0x65726168732e646c,0x2509203233732e64\n"
".quad 0x5f5b202c34383172,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3832383633\n"
".quad 0x6e6f635f6e6f6e5f,0x745f6d756e5f7473,0x635f736461657268,0x6f69746361706d6f\n"
".quad 0x6f6c2e090a3b5d6e,0x3934370937310963,0x2e726873090a3009,0x3672250920323375\n"
".quad 0x3438317225202c31,0x6f6d090a3b31202c,0x2509203233732e76,0x7225202c35383172\n"
".quad 0x766f6d090a3b3136,0x722509203233752e,0x0a3b30202c363831,0x656c2e7074657309\n"
".quad 0x702509203233732e,0x31367225202c3336,0x3b3638317225202c,0x203336702540090a\n"
".quad 0x744c240920617262,0x36333131315f305f,0x2e766f6d090a3b32,0x3172250920323375\n"
".quad 0x240a3b31202c3738,0x3932395f305f744c,0x3c2f2f200a3a3033,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x31353720656e696c,0x3109636f6c2e090a,0x0a30093135370937\n"
".quad 0x6e79732e72616209,0x73090a3b30092063,0x752e656c2e707465,0x3436702509203233\n"
".quad 0x2c3538317225202c,0x40090a3b35722520,0x6172622034367025,0x5f305f744c240920\n"
".quad 0x200a3b3638313339,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313537,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x2e090a3033393239,0x3709373109636f6c,0x6461090a30093835,0x2509203233752e64\n"
".quad 0x317225202c363672,0x6d090a3b32202c33,0x33752e6f6c2e6c75,0x3838317225092032\n"
".quad 0x202c36367225202c,0x090a3b3738317225,0x752e6f6c2e6c756d,0x3831722509203233\n"
".quad 0x3838317225202c39,0x7663090a3b32202c,0x33752e3436752e74,0x3737647225092032\n"
".quad 0x3b3938317225202c,0x36752e646461090a,0x3837647225092034,0x2c3737647225202c\n"
".quad 0x090a3b3364722520,0x65726168732e646c,0x2509203631752e64,0x255b202c35336872\n"
".quad 0x3b5d302b38376472,0x33752e646461090a,0x3039317225092032,0x202c33317225202c\n"
".quad 0x2e6c756d090a3b31,0x09203233752e6f6c,0x25202c3139317225,0x7225202c37383172\n"
".quad 0x756d090a3b303931,0x3233752e6f6c2e6c,0x2c32393172250920,0x202c313931722520\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x202c393764722509,0x090a3b3239317225\n"
".quad 0x203436752e646461,0x202c303864722509,0x25202c3937647225,0x646c090a3b336472\n"
".quad 0x2e6465726168732e,0x6872250920363175,0x6472255b202c3633,0x090a3b5d302b3038\n"
".quad 0x203631752e646461,0x202c373368722509,0x25202c3533687225,0x73090a3b36336872\n"
".quad 0x6465726168732e74,0x255b09203631752e,0x2c5d302b38376472,0x0a3b373368722520\n"
".quad 0x33395f305f744c24,0x2f2f200a3a363831,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353720656e696c20,0x2064616568202c31,0x2064656c6562616c\n"
".quad 0x32395f305f744c24,0x6f6c2e090a303339,0x3136370937310963,0x2e6c756d090a3009\n"
".quad 0x09203233752e6f6c,0x25202c3738317225,0x3b32202c37383172,0x3109636f6c2e090a\n"
".quad 0x0a30093934370937,0x3233732e72687309,0x2c35383172250920,0x202c353831722520\n"
".quad 0x2e766f6d090a3b31,0x3172250920323375,0x090a3b30202c3339,0x2e74672e70746573\n"
".quad 0x3670250920323373,0x3538317225202c35,0x3b3339317225202c,0x203536702540090a\n"
".quad 0x744c240920617262,0x30333932395f305f,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b38313432395f30,0x315f305f744c240a,0x090a3a3236333131,0x203233752e766f6d\n"
".quad 0x202c373831722509,0x305f744c240a3b31,0x0a3a38313432395f,0x3233752e62757309\n"
".quad 0x2c34393172250920,0x202c343831722520,0x2e766f6d090a3b31,0x3172250920323375\n"
".quad 0x090a3b32202c3539,0x2e656c2e70746573,0x3670250920323375,0x3439317225202c36\n"
".quad 0x3b3539317225202c,0x203636702540090a,0x744c240920617262,0x34353933395f305f\n"
".quad 0x732e766f6d090a3b,0x3931722509203233,0x4c240a3b32202c36,0x363434395f305f74\n"
".quad 0x6c3c2f2f200a3a36,0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c39343720656e69\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6d69747365202c31,0x6574692064657461\n"
".quad 0x3a736e6f69746172,0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x0a30093836370937\n"
".quad 0x3233752e72687309,0x2c37383172250920,0x202c373831722520,0x636f6c2e090a3b31\n"
".quad 0x0939363709373109,0x732e726162090a30,0x0a3b300920636e79,0x3233752e62757309\n"
".quad 0x2c37393172250920,0x202c363931722520,0x70746573090a3b31,0x203233752e65672e\n"
".quad 0x25202c3736702509,0x39317225202c3572,0x36702540090a3b37,0x2409206172622037\n"
".quad 0x3734395f305f744c,0x3c2f2f200a3b3232,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39343720656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3434395f305f744c,0x636f6c2e090a3636,0x0936373709373109,0x752e646461090a30\n"
".quad 0x3338722509203233,0x31202c357225202c,0x752e726873090a3b,0x3931722509203233\n"
".quad 0x3738317225202c38,0x756d090a3b31202c,0x3233752e6f6c2e6c,0x2c39393172250920\n"
".quad 0x25202c3338722520,0x61090a3b37383172,0x09203233752e6464,0x25202c3030327225\n"
".quad 0x7225202c38393172,0x756d090a3b393931,0x3233752e6f6c2e6c,0x2c31303272250920\n"
".quad 0x202c303032722520,0x2e747663090a3b32,0x203233752e343675,0x202c313864722509\n"
".quad 0x090a3b3130327225,0x203436752e646461,0x202c323864722509,0x25202c3138647225\n"
".quad 0x646c090a3b336472,0x2e6465726168732e,0x6872250920363175,0x6472255b202c3833\n"
".quad 0x090a3b5d302b3238,0x752e6f6c2e6c756d,0x3032722509203233,0x3939317225202c32\n"
".quad 0x7663090a3b32202c,0x33752e3436752e74,0x3338647225092032,0x3b3230327225202c\n"
".quad 0x36752e646461090a,0x3438647225092034,0x2c3338647225202c,0x090a3b3364722520\n"
".quad 0x65726168732e646c,0x2509203631752e64,0x255b202c39336872,0x3b5d302b34386472\n"
".quad 0x31752e646461090a,0x3034687225092036,0x2c3833687225202c,0x0a3b393368722520\n"
".quad 0x726168732e747309,0x09203631752e6465,0x302b32386472255b,0x3034687225202c5d\n"
".quad 0x5f305f744c240a3b,0x200a3a3232373439,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393437,0x656c6562616c2064\n"
".quad 0x5f305f744c242064,0x2e090a3636343439,0x3709373109636f6c,0x6873090a30093636\n"
".quad 0x2509203233622e6c,0x7225202c36393172,0x0a3b31202c363931,0x746c2e7074657309\n"
".quad 0x702509203233752e,0x39317225202c3836,0x3439317225202c36,0x3836702540090a3b\n"
".quad 0x4c24092061726220,0x363434395f305f74,0x305f744c240a3b36,0x0a3a34353933395f\n"
".quad 0x373109636f6c2e09,0x090a300930383709,0x636e79732e726162,0x2140090a3b300920\n"
".quad 0x2061726220317025,0x395f305f744c2409,0x2e090a3b30393435,0x3709373109636f6c\n"
".quad 0x756d090a30093738,0x3233752e6f6c2e6c,0x2c33303272250920,0x202c343831722520\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x202c353864722509,0x090a3b3330327225\n"
".quad 0x752e6f6c2e6c756d,0x3032722509203233,0x3338317225202c34,0x7663090a3b32202c\n"
".quad 0x33752e3436752e74,0x3638647225092032,0x3b3430327225202c,0x36752e646461090a\n"
".quad 0x3738647225092034,0x2c3538647225202c,0x0a3b323564722520,0x726168732e646c09\n"
".quad 0x09203631752e6465,0x5b202c3134687225,0x322d2b3738647225,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x38647225202c3838,0x3235647225202c36,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x38386472255b0920,0x7225202c5d322d2b,0x6c2e090a3b313468\n"
".quad 0x383709373109636f,0x646461090a300939,0x722509203436752e,0x647225202c393864\n"
".quad 0x33647225202c3538,0x68732e646c090a3b,0x3631752e64657261,0x2c32346872250920\n"
".quad 0x2b39386472255b20,0x646461090a3b5d30,0x722509203436752e,0x647225202c303964\n"
".quad 0x33647225202c3638,0x68732e7473090a3b,0x3631752e64657261,0x30396472255b0920\n"
".quad 0x687225202c5d302b,0x5f744c240a3b3234,0x3a30393435395f30,0x3109636f6c2e090a\n"
".quad 0x0a30093934340937,0x6e79732e72616209,0x6c090a3b30092063,0x6465726168732e64\n"
".quad 0x722509203631752e,0x72255b202c353032,0x0a3b5d302b333564,0x3233752e766f6d09\n"
".quad 0x2c36303272250920,0x746573090a3b3120,0x3233752e656e2e70,0x202c393670250920\n"
".quad 0x25202c3530327225,0x40090a3b36303272,0x6172622039367025,0x5f305f744c240920\n"
".quad 0x090a3b3835323639,0x09373109636f6c2e,0x6c090a3009333634,0x6465726168732e64\n"
".quad 0x722509203631752e,0x72255b202c373032,0x0a3b5d322b373164,0x3233752e64646109\n"
".quad 0x2c38303272250920,0x202c373032722520,0x636f6c2e090a3b31,0x0934363409373109\n"
".quad 0x68732e646c090a30,0x3631752e64657261,0x2c33346872250920,0x2b38316472255b20\n"
".quad 0x617262090a3b5d32,0x4c240920696e752e,0x303036395f305f74,0x305f744c240a3b32\n"
".quad 0x0a3a38353236395f,0x3631752e766f6d09,0x2c33346872250920,0x766f6d090a3b3020\n"
".quad 0x722509203233752e,0x0a3b30202c383032,0x36395f305f744c24,0x646c090a3a323030\n"
".quad 0x2e6465726168732e,0x3272250920363175,0x6472255b202c3930,0x090a3b5d302b3435\n"
".quad 0x203233752e766f6d,0x202c303132722509,0x70746573090a3b31,0x203233752e656e2e\n"
".quad 0x25202c3037702509,0x7225202c39303272,0x2540090a3b303132,0x2061726220303770\n"
".quad 0x395f305f744c2409,0x2e090a3b30373736,0x3409373109636f6c,0x756d090a30093936\n"
".quad 0x3233752e6f6c2e6c,0x2c31313272250920,0x202c373231722520,0x2e747663090a3b32\n"
".quad 0x203233752e343675,0x202c353564722509,0x090a3b3131327225,0x203436752e646461\n"
".quad 0x202c313964722509,0x25202c3535647225,0x646c090a3b356472,0x2e6465726168732e\n"
".quad 0x3272250920363175,0x6472255b202c3231,0x090a3b5d322b3139,0x203233752e646461\n"
".quad 0x202c333132722509,0x31202c3231327225,0x09636f6c2e090a3b,0x3009303734093731\n"
".quad 0x36752e646461090a,0x3239647225092034,0x2c3535647225202c,0x090a3b3364722520\n"
".quad 0x65726168732e646c,0x2509203631752e64,0x255b202c34346872,0x3b5d322b32396472\n"
".quad 0x6e752e617262090a,0x305f744c24092069,0x0a3b34313536395f,0x36395f305f744c24\n"
".quad 0x6f6d090a3a303737,0x2509203631752e76,0x3b30202c34346872,0x33752e766f6d090a\n"
".quad 0x3331327225092032,0x744c240a3b30202c,0x34313536395f305f,0x09636f6c2e090a3a\n"
".quad 0x3009333734093731,0x6168732e646c090a,0x203233752e646572,0x202c343132722509\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38323836335f72,0x635f6e6f6e5f3034\n"
".quad 0x6d756e5f74736e6f,0x736461657268745f,0x746361706d6f635f,0x2e090a3b5d6e6f69\n"
".quad 0x3609373109636f6c,0x6461090a30093838,0x2509203436752e64,0x7225202c33396472\n"
".quad 0x647225202c343164,0x2e646c090a3b3235,0x752e646572616873,0x3468722509203631\n"
".quad 0x396472255b202c35,0x73090a3b5d302b33,0x6465726168732e74,0x255b09203631752e\n"
".quad 0x2c5d322b38316472,0x0a3b353468722520,0x65672e7074657309,0x702509203233752e\n"
".quad 0x32317225202c3137,0x3431327225202c37,0x3137702540090a3b,0x4c24092061726220\n"
".quad 0x323037395f305f74,0x636f6c2e090a3b36,0x0930393609373109,0x6c2e6c756d090a30\n"
".quad 0x2509203233752e6f,0x7225202c35313272,0x0a3b32202c373231,0x3436752e74766309\n"
".quad 0x722509203233752e,0x327225202c353564,0x646461090a3b3531,0x722509203436752e\n"
".quad 0x647225202c343964,0x35647225202c3535,0x732e646c090a3b32,0x31752e6465726168\n"
".quad 0x3634687225092036,0x34396472255b202c,0x6461090a3b5d302b,0x2509203436752e64\n"
".quad 0x7225202c35396472,0x647225202c353564,0x732e7473090a3b33,0x31752e6465726168\n"
".quad 0x396472255b092036,0x7225202c5d322b35,0x744c240a3b363468,0x36323037395f305f\n"
".quad 0x09636f6c2e090a3a,0x3009333734093731,0x6168732e646c090a,0x203233752e646572\n"
".quad 0x202c343132722509,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38323836335f72\n"
".quad 0x635f6e6f6e5f3034,0x6d756e5f74736e6f,0x736461657268745f,0x746361706d6f635f\n"
".quad 0x2e090a3b5d6e6f69,0x3709373109636f6c,0x6873090a30093330,0x2509203233752e72\n"
".quad 0x7225202c36313272,0x0a3b31202c343132,0x3233732e766f6d09,0x2c37313272250920\n"
".quad 0x0a3b363132722520,0x3233752e766f6d09,0x2c38313272250920,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x202c323770250920,0x25202c3631327225,0x40090a3b38313272\n"
".quad 0x6172622032377025,0x5f305f744c240920,0x0a3b343738313131,0x3233752e766f6d09\n"
".quad 0x2c39313272250920,0x5f744c240a3b3120,0x3a30353038395f30,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x2e090a3530372065,0x3709373109636f6c\n"
".quad 0x6162090a30093530,0x0920636e79732e72,0x70746573090a3b30,0x203233752e656c2e\n"
".quad 0x25202c3337702509,0x7225202c37313272,0x37702540090a3b35,0x2409206172622033\n"
".quad 0x3338395f305f744c,0x3c2f2f200a3b3630,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35303720656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3038395f305f744c,0x636f6c2e090a3035,0x0931313709373109,0x752e646461090a30\n"
".quad 0x3636722509203233,0x202c33317225202c,0x2e6c756d090a3b32,0x09203233752e6f6c\n"
".quad 0x25202c3032327225,0x327225202c363672,0x6c756d090a3b3931,0x203233752e6f6c2e\n"
".quad 0x202c313232722509,0x32202c3032327225,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x25202c3639647225,0x61090a3b31323272,0x09203436752e6464,0x25202c3739647225\n"
".quad 0x7225202c36396472,0x2e646c090a3b3364,0x752e646572616873,0x3468722509203631\n"
".quad 0x396472255b202c37,0x61090a3b5d302b37,0x09203233752e6464,0x25202c3232327225\n"
".quad 0x0a3b31202c333172,0x2e6f6c2e6c756d09,0x3272250920323375,0x31327225202c3332\n"
".quad 0x3232327225202c39,0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c34323272\n"
".quad 0x0a3b32202c333232,0x3436752e74766309,0x722509203233752e,0x327225202c383964\n"
".quad 0x646461090a3b3432,0x722509203436752e,0x647225202c393964,0x33647225202c3839\n"
".quad 0x68732e646c090a3b,0x3631752e64657261,0x2c38346872250920,0x2b39396472255b20\n"
".quad 0x646461090a3b5d30,0x722509203631752e,0x687225202c393468,0x34687225202c3734\n"
".quad 0x732e7473090a3b38,0x31752e6465726168,0x396472255b092036,0x7225202c5d302b37\n"
".quad 0x744c240a3b393468,0x36303338395f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35303720656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30353038395f305f,0x3109636f6c2e090a,0x0a30093431370937\n"
".quad 0x3233622e6c687309,0x2c39313272250920,0x202c393132722520,0x636f6c2e090a3b31\n"
".quad 0x0933303709373109,0x732e726873090a30,0x3132722509203233,0x3731327225202c37\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3b30202c35323272,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x327225202c343770,0x32327225202c3731,0x37702540090a3b35\n"
".quad 0x2409206172622034,0x3038395f305f744c,0x617262090a3b3035,0x4c240920696e752e\n"
".quad 0x333537395f305f74,0x305f744c240a3b38,0x3a3437383131315f,0x33752e766f6d090a\n"
".quad 0x3931327225092032,0x744c240a3b31202c,0x38333537395f305f,0x752e766f6d090a3a\n"
".quad 0x3232722509203233,0x73090a3b32202c36,0x752e656c2e707465,0x3537702509203233\n"
".quad 0x2c3431327225202c,0x0a3b363232722520,0x6220353770254009,0x5f744c2409206172\n"
".quad 0x3b34373039395f30,0x33732e766f6d090a,0x3732327225092032,0x744c240a3b32202c\n"
".quad 0x36383539395f305f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x202c33303720656e,0x20676e697473656e,0x31203a6874706564,0x616d69747365202c\n"
".quad 0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75,0x373109636f6c2e09\n"
".quad 0x090a300930323709,0x203233752e726873,0x202c393132722509,0x31202c3931327225\n"
".quad 0x09636f6c2e090a3b,0x3009313237093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x203233752e627573,0x202c383232722509,0x31202c3732327225,0x2e70746573090a3b\n"
".quad 0x09203233752e6567,0x7225202c36377025,0x3832327225202c35,0x3637702540090a3b\n"
".quad 0x4c24092061726220,0x343839395f305f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c33303720656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x383539395f305f74,0x09636f6c2e090a36,0x3009383237093731\n"
".quad 0x33752e726873090a,0x3932327225092032,0x2c3931327225202c,0x646461090a3b3120\n"
".quad 0x722509203233752e,0x2c357225202c3338,0x6c756d090a3b3120,0x203233752e6f6c2e\n"
".quad 0x202c303332722509,0x7225202c33387225,0x6461090a3b393132,0x2509203233752e64\n"
".quad 0x7225202c31333272,0x327225202c393232,0x6c756d090a3b3033,0x203233752e6f6c2e\n"
".quad 0x202c323332722509,0x32202c3133327225,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x202c303031647225,0x090a3b3233327225,0x203436752e646461,0x2c31303164722509\n"
".quad 0x2c30303164722520,0x090a3b3364722520,0x65726168732e646c,0x2509203631752e64\n"
".quad 0x255b202c30356872,0x5d302b3130316472,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c33333272,0x0a3b32202c303332,0x3436752e74766309,0x722509203233752e\n"
".quad 0x7225202c32303164,0x6461090a3b333332,0x2509203436752e64,0x25202c3330316472\n"
".quad 0x25202c3230316472,0x646c090a3b336472,0x2e6465726168732e,0x6872250920363175\n"
".quad 0x6472255b202c3135,0x0a3b5d302b333031,0x3631752e64646109,0x2c32356872250920\n"
".quad 0x202c303568722520,0x090a3b3135687225,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x302b313031647225,0x3235687225202c5d,0x5f305f744c240a3b,0x200a3a3234383939\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c333037,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3638353939\n"
".quad 0x3709373109636f6c,0x6873090a30093831,0x2509203233622e6c,0x7225202c37323272\n"
".quad 0x0a3b31202c373232,0x746c2e7074657309,0x702509203233752e,0x32327225202c3737\n"
".quad 0x3431327225202c37,0x3737702540090a3b,0x4c24092061726220,0x383539395f305f74\n"
".quad 0x305f744c240a3b36,0x0a3a34373039395f,0x373109636f6c2e09,0x090a300938373409\n"
".quad 0x636e79732e726162,0x2140090a3b300920,0x2061726220317025,0x315f305f744c2409\n"
".quad 0x090a3b3031363030,0x09373109636f6c2e,0x6c090a3009363834,0x6465726168732e64\n"
".quad 0x722509203233752e,0x5f5f5b202c343332,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f30345f35323836,0x736e6f635f6e6f6e,0x68745f6d756e5f74,0x63615f7364616572\n"
".quad 0x090a3b5d65766974,0x752e6f6c2e6c756d,0x3332722509203233,0x3433327225202c35\n"
".quad 0x7663090a3b32202c,0x33752e3436752e74,0x3031647225092032,0x3533327225202c34\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3530,0x33647225202c3430\n"
".quad 0x68732e646c090a3b,0x3631752e64657261,0x2c36333272250920,0x3530316472255b20\n"
".quad 0x7473090a3b5d302b,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f30345f35393037,0x736e6f635f6e6f6e,0x6c625f6d756e5f74\n"
".quad 0x6c756d5f736b636f,0x33327225202c5d74,0x636f6c2e090a3b36,0x0937383409373109\n"
".quad 0x752e646461090a30,0x3164722509203436,0x31647225202c3630,0x32647225202c3430\n"
".quad 0x68732e646c090a3b,0x3631752e64657261,0x2c37333272250920,0x3630316472255b20\n"
".quad 0x7473090a3b5d302b,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f30345f37393037,0x736e6f635f6e6f6e,0x74657366666f5f74\n"
".quad 0x616c5f746c756d5f,0x25202c5d6164626d,0x2e090a3b37333272,0x3409373109636f6c\n"
".quad 0x6461090a30093838,0x2509203436752e64,0x25202c3730316472,0x25202c3430316472\n"
".quad 0x646c090a3b356472,0x2e6465726168732e,0x3272250920363175,0x6472255b202c3833\n"
".quad 0x0a3b5d302b373031,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f36393037335f72,0x635f6e6f6e5f3034,0x6d756e5f74736e6f\n"
".quad 0x202c5d746c756d5f,0x090a3b3833327225,0x09373109636f6c2e,0x6c090a3009303934\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x5f5f5b202c383031,0x6d72617061647563\n"
".quad 0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53\n"
".quad 0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053,0x6e5f675f5f30535f\n"
".quad 0x3b5d656e6f5f6d75,0x6f6c672e7473090a,0x203233752e6c6162,0x3830316472255b09\n"
".quad 0x327225202c5d302b,0x6f6c2e090a3b3733,0x3139340937310963,0x702e646c090a3009\n"
".quad 0x3436752e6d617261,0x3930316472250920,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x7463657369623731,0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666\n"
".quad 0x30535f535f535f30,0x5f30535f535f535f,0x30535f30535f3053,0x5f6d756e5f675f5f\n"
".quad 0x6d5f736b636f6c62,0x73090a3b5d746c75,0x6c61626f6c672e74,0x255b09203233752e\n"
".quad 0x5d302b3930316472,0x3b3633327225202c,0x315f305f744c240a,0x090a3a3031363030\n"
".quad 0x09373109636f6c2e,0x62090a3009333934,0x20636e79732e7261,0x6f6c2e090a3b3009\n"
".quad 0x3231360937310963,0x732e646c090a3009,0x33662e6465726168,0x202c376625092032\n"
".quad 0x302b39316472255b,0x636f6c2e090a3b5d,0x0933313609373109,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x5b202c3666250920,0x5d302b3032647225,0x68732e646c090a3b\n"
".quad 0x3233752e64657261,0x2c39333272250920,0x616475635f5f5b20,0x765f6c61636f6c5f\n"
".quad 0x35323836335f7261,0x5f6e6f6e5f30345f,0x756e5f74736e6f63,0x6461657268745f6d\n"
".quad 0x6576697463615f73,0x70746573090a3b5d,0x203233752e74672e,0x25202c3837702509\n"
".quad 0x7225202c39333272,0x2140090a3b373231,0x6172622038377025,0x5f305f744c240920\n"
".quad 0x0a3b323231313031,0x373109636f6c2e09,0x090a300937313609,0x752e6f6c2e6c756d\n"
".quad 0x3432722509203233,0x3732317225202c30,0x7663090a3b34202c,0x33752e3436752e74\n"
".quad 0x3131647225092032,0x3034327225202c30,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3131,0x31647225202c3031,0x68732e646c090a3b,0x3233662e64657261\n"
".quad 0x202c313766250920,0x2b3131316472255b,0x766f6d090a3b5d30,0x662509203233662e\n"
".quad 0x31376625202c3237,0x09636f6c2e090a3b,0x3009383136093731,0x36752e646461090a\n"
".quad 0x3131647225092034,0x3131647225202c32,0x3b34647225202c30,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3337662509,0x302b323131647225,0x2e766f6d090a3b5d\n"
".quad 0x3766250920323366,0x3b33376625202c34,0x315f305f744c240a,0x090a3a3232313130\n"
".quad 0x09373109636f6c2e,0x40090a3009313236,0x7262203634702521,0x305f744c24092061\n"
".quad 0x3b3039383130315f,0x3109636f6c2e090a,0x0a30093433360937,0x726168732e646c09\n"
".quad 0x09203631752e6465,0x5b202c3134327225,0x5d302b3631647225,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3433363130315f30,0x5f305f744c240a3b,0x0a3a303938313031\n"
".quad 0x726168732e646c09,0x09203631752e6465,0x5b202c3234327225,0x5d302b3731647225\n"
".quad 0x68732e646c090a3b,0x3233752e64657261,0x2c33343272250920,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x37393037335f7261,0x5f6e6f6e5f30345f,0x666f5f74736e6f63\n"
".quad 0x6c756d5f74657366,0x6164626d616c5f74,0x2e646461090a3b5d,0x3272250920323375\n"
".quad 0x34327225202c3134,0x3334327225202c32,0x5f305f744c240a3b,0x0a3a343336313031\n"
".quad 0x3233752e766f6d09,0x2c34343272250920,0x746573090a3b3020,0x3233752e656e2e70\n"
".quad 0x202c393770250920,0x25202c3830327225,0x40090a3b34343272,0x7262203937702521\n"
".quad 0x305f744c24092061,0x3b3230343230315f,0x3109636f6c2e090a,0x0a30093733360937\n"
".quad 0x726168732e646c09,0x09203631752e6465,0x5b202c3335687225,0x5d302b3831647225\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3634313230315f30,0x5f305f744c240a3b\n"
".quad 0x0a3a323034323031,0x3631752e766f6d09,0x2c33356872250920,0x5f744c240a3b3020\n"
".quad 0x3634313230315f30,0x3770252140090a3a,0x2409206172622038,0x3230315f305f744c\n"
".quad 0x756d090a3b343139,0x3233752e6f6c2e6c,0x2c35343272250920,0x202c373231722520\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x202c353564722509,0x090a3b3534327225\n"
".quad 0x203233752e766f6d,0x202c363432722509,0x70746573090a3b31,0x203233752e656e2e\n"
".quad 0x25202c3038702509,0x7225202c36343172,0x2540090a3b363432,0x2061726220303870\n"
".quad 0x315f305f744c2409,0x090a3b3632343330,0x09373109636f6c2e,0x61090a3009313436\n"
".quad 0x09203436752e6464,0x202c333131647225,0x25202c3535647225,0x646c090a3b326472\n"
".quad 0x2e6465726168732e,0x3272250920363175,0x6472255b202c3734,0x0a3b5d302b333131\n"
".quad 0x696e752e61726209,0x5f305f744c240920,0x0a3b303731333031,0x30315f305f744c24\n"
".quad 0x61090a3a36323433,0x09203436752e6464,0x202c343131647225,0x25202c3535647225\n"
".quad 0x646c090a3b356472,0x2e6465726168732e,0x3272250920363175,0x6472255b202c3834\n"
".quad 0x0a3b5d302b343131,0x726168732e646c09,0x09203233752e6465,0x5b202c3934327225\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f37393037335f,0x6f635f6e6f6e5f30\n"
".quad 0x7366666f5f74736e,0x5f746c756d5f7465,0x3b5d6164626d616c,0x33752e646461090a\n"
".quad 0x3734327225092032,0x2c3834327225202c,0x0a3b393432722520,0x30315f305f744c24\n"
".quad 0x6d090a3a30373133,0x09203233732e766f,0x25202c3035327225,0x6d090a3b37343272\n"
".quad 0x09203233752e766f,0x30202c3135327225,0x2e70746573090a3b,0x09203233752e7165\n"
".quad 0x7225202c31387025,0x327225202c333132,0x702540090a3b3135,0x0920617262203138\n"
".quad 0x30315f305f744c24,0x2e090a3b38333933,0x3609373109636f6c,0x6461090a30093434\n"
".quad 0x2509203436752e64,0x25202c3531316472,0x7225202c35356472,0x2e646c090a3b3364\n"
".quad 0x752e646572616873,0x3568722509203631,0x316472255b202c34,0x090a3b5d302b3531\n"
".quad 0x20696e752e617262,0x315f305f744c2409,0x240a3b3835363230,0x3330315f305f744c\n"
".quad 0x6f6d090a3a383339,0x2509203631752e76,0x3b30202c34356872,0x6e752e617262090a\n"
".quad 0x305f744c24092069,0x3b3835363230315f,0x315f305f744c240a,0x090a3a3431393230\n"
".quad 0x203631752e766f6d,0x202c343568722509,0x2e766f6d090a3b30,0x3272250920323375\n"
".quad 0x240a3b30202c3035,0x3230315f305f744c,0x6c2e090a3a383536,0x343609373109636f\n"
".quad 0x726162090a300938,0x300920636e79732e,0x09636f6c2e090a3b,0x3009313536093731\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x327225202c323532,0x090a3b34202c3134\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x327225202c363131,0x646461090a3b3235\n"
".quad 0x722509203436752e,0x7225202c37313164,0x7225202c36313164,0x2e7473090a3b3164\n"
".quad 0x662e646572616873,0x6472255b09203233,0x202c5d302b373131,0x6c2e090a3b376625\n"
".quad 0x353609373109636f,0x646461090a300932,0x722509203436752e,0x7225202c38313164\n"
".quad 0x7225202c36313164,0x2e7473090a3b3464,0x662e646572616873,0x6472255b09203233\n"
".quad 0x202c5d302b383131,0x6c2e090a3b366625,0x353609373109636f,0x6c756d090a300933\n"
".quad 0x203233752e6f6c2e,0x202c333532722509,0x32202c3134327225,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x202c393131647225,0x090a3b3335327225,0x203233622e6c6873\n"
".quad 0x202c343532722509,0x3b3631202c317225,0x33752e726873090a,0x3535327225092032\n"
".quad 0x2c3435327225202c,0x6461090a3b363120,0x2509203436752e64,0x25202c3032316472\n"
".quad 0x25202c3931316472,0x7473090a3b326472,0x2e6465726168732e,0x72255b0920363175\n"
".quad 0x2c5d302b30323164,0x0a3b353532722520,0x373109636f6c2e09,0x090a300934353609\n"
".quad 0x203233622e6c6873,0x202c363532722509,0x3b3631202c337225,0x33752e726873090a\n"
".quad 0x3735327225092032,0x2c3635327225202c,0x6461090a3b363120,0x2509203436752e64\n"
".quad 0x25202c3132316472,0x25202c3931316472,0x7473090a3b356472,0x2e6465726168732e\n"
".quad 0x72255b0920363175,0x2c5d302b31323164,0x0a3b373532722520,0x2039377025214009\n"
".quad 0x744c240920617262,0x39313430315f305f,0x636f6c2e090a3b34,0x0936353609373109\n"
".quad 0x772e6c756d090a30,0x203631752e656469,0x202c383532722509,0x32202c3335687225\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x202c323231647225,0x090a3b3835327225\n"
".quad 0x203233752e627573,0x202c393532722509,0x31202c3830327225,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x31647225202c3332,0x33647225202c3232,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x32316472255b0920,0x7225202c5d322b33,0x6c2e090a3b393532\n"
".quad 0x353609373109636f,0x646461090a300937,0x722509203436752e,0x7225202c34323164\n"
".quad 0x7225202c32323164,0x7473090a3b323564,0x2e6465726168732e,0x72255b0920363175\n"
".quad 0x2c5d322b34323164,0x0a3b333468722520,0x30315f305f744c24,0x40090a3a34393134\n"
".quad 0x7262203837702521,0x305f744c24092061,0x3b3831323530315f,0x3109636f6c2e090a\n"
".quad 0x0a30093336360937,0x2e6f6c2e6c756d09,0x3272250920323375,0x35327225202c3036\n"
".quad 0x63090a3b34202c30,0x752e3436752e7476,0x3164722509203233,0x36327225202c3532\n"
".quad 0x2e766f6d090a3b30,0x3766250920323366,0x3b32376625202c35,0x36752e646461090a\n"
".quad 0x3231647225092034,0x3231647225202c36,0x3b31647225202c35,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x3632316472255b09,0x376625202c5d302b,0x636f6c2e090a3b35\n"
".quad 0x0934363609373109,0x662e766f6d090a30,0x3637662509203233,0x0a3b34376625202c\n"
".quad 0x3436752e64646109,0x3732316472250920,0x353231647225202c,0x0a3b34647225202c\n"
".quad 0x726168732e747309,0x09203233662e6465,0x2b3732316472255b,0x36376625202c5d30\n"
".quad 0x09636f6c2e090a3b,0x3009353636093731,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x327225202c313632,0x090a3b32202c3035,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x327225202c383231,0x766f6d090a3b3136,0x722509203233732e,0x317225202c323632\n"
".quad 0x6c6873090a3b3033,0x722509203233622e,0x327225202c333632,0x0a3b3631202c3236\n"
".quad 0x3233752e72687309,0x2c34363272250920,0x202c333632722520,0x646461090a3b3631\n"
".quad 0x722509203436752e,0x7225202c39323164,0x7225202c38323164,0x2e7473090a3b3264\n"
".quad 0x752e646572616873,0x6472255b09203631,0x202c5d302b393231,0x090a3b3436327225\n"
".quad 0x09373109636f6c2e,0x6d090a3009363636,0x09203233732e766f,0x25202c3536327225\n"
".quad 0x73090a3b32333172,0x09203233622e6c68,0x25202c3636327225,0x3631202c35363272\n"
".quad 0x752e726873090a3b,0x3632722509203233,0x3636327225202c37,0x61090a3b3631202c\n"
".quad 0x09203436752e6464,0x202c303331647225,0x202c383231647225,0x73090a3b35647225\n"
".quad 0x6465726168732e74,0x255b09203631752e,0x5d302b3033316472,0x3b3736327225202c\n"
".quad 0x33752e766f6d090a,0x3836327225092032,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x2c32387025092032,0x202c333132722520,0x090a3b3836327225,0x7262203238702540\n"
".quad 0x305f744c24092061,0x3b3831323530315f,0x3109636f6c2e090a,0x0a30093836360937\n"
".quad 0x6469772e6c756d09,0x2509203631752e65,0x7225202c39363272,0x0a3b32202c343568\n"
".quad 0x3436752e74766309,0x722509203233752e,0x7225202c31333164,0x7573090a3b393632\n"
".quad 0x2509203233752e62,0x7225202c30373272,0x0a3b31202c333132,0x3436752e64646109\n"
".quad 0x3233316472250920,0x313331647225202c,0x0a3b33647225202c,0x726168732e747309\n"
".quad 0x09203631752e6465,0x2b3233316472255b,0x37327225202c5d32,0x636f6c2e090a3b30\n"
".quad 0x0939363609373109,0x752e646461090a30,0x3164722509203436,0x31647225202c3333\n"
".quad 0x35647225202c3133,0x732e7473090a3b32,0x31752e6465726168,0x316472255b092036\n"
".quad 0x25202c5d322b3333,0x4c240a3b34346872,0x323530315f305f74,0x5f744c240a3a3831\n"
".quad 0x3630373430315f30,0x09636f6c2e090a3a,0x3009353035093731,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x7262203170252140,0x305f744c24092061,0x3b3033373530315f\n"
".quad 0x3109636f6c2e090a,0x0a30093930350937,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5b202c3137327225,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f36393037335f\n"
".quad 0x6f635f6e6f6e5f30,0x5f6d756e5f74736e,0x090a3b5d746c756d,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5b202c32373272,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3539303733,0x6e6f635f6e6f6e5f,0x625f6d756e5f7473,0x756d5f736b636f6c\n"
".quad 0x756d090a3b5d746c,0x3233752e6f6c2e6c,0x2c33373272250920,0x202c323732722520\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x2c34333164722509,0x0a3b333732722520\n"
".quad 0x3436752e64646109,0x3533316472250920,0x343331647225202c,0x0a3b33647225202c\n"
".quad 0x726168732e747309,0x09203631752e6465,0x2b3533316472255b,0x37327225202c5d30\n"
".quad 0x636f6c2e090a3b31,0x0930313509373109,0x752e766f6d090a30,0x3568722509203631\n"
".quad 0x73090a3b30202c35,0x6465726168732e74,0x5f5b09203631752e,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f32345f31313037,0x736e6f635f6e6f6e\n"
".quad 0x685f6c635f735f74,0x3133377265706c65,0x7225202c5d302b30,0x744c240a3b353568\n"
".quad 0x33373530315f305f,0x636f6c2e090a3a30,0x0933313509373109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x373109636f6c2e09,0x090a300936313509,0x65726168732e646c\n"
".quad 0x2509203631752e64,0x255b202c34373272,0x3b5d302b37316472,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3737662509,0x5d302b3931647225,0x68732e646c090a3b\n"
".quad 0x3233662e64657261,0x202c383766250920,0x302b30326472255b,0x732e646c090a3b5d\n"
".quad 0x33752e6465726168,0x3733327225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x393037335f726176,0x6e6f6e5f30345f37,0x6f5f74736e6f635f,0x756d5f7465736666\n"
".quad 0x64626d616c5f746c,0x746573090a3b5d61,0x3233752e656c2e70,0x202c333870250920\n"
".quad 0x25202c3733327225,0x702540090a3b3572,0x0920617262203338,0x30315f305f744c24\n"
".quad 0x2e090a3b38393436,0x3509373109636f6c,0x646c090a30093734,0x752e6d617261702e\n"
".quad 0x3164722509203436,0x635f5f5b202c3633,0x5f6d726170616475,0x6573696237315a5f\n"
".quad 0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a\n"
".quad 0x535f535f535f3053,0x5f30535f30535f30,0x656c5f675f5f3053,0x3b5d656e6f5f7466\n"
".quad 0x36752e646461090a,0x3331647225092034,0x3331647225202c37,0x3531647225202c36\n"
".quad 0x09636f6c2e090a3b,0x3009363135093731,0x6168732e646c090a,0x203233662e646572\n"
".quad 0x5b202c3737662509,0x5d302b3931647225,0x09636f6c2e090a3b,0x3009373435093731\n"
".quad 0x6f6c672e7473090a,0x203233662e6c6162,0x3733316472255b09,0x376625202c5d302b\n"
".quad 0x636f6c2e090a3b37,0x0938343509373109,0x61702e646c090a30,0x203436752e6d6172\n"
".quad 0x2c38333164722509,0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237\n"
".quad 0x72614c6c656e7265,0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f\n"
".quad 0x535f30535f535f53,0x5f30535f30535f30,0x74686769725f675f,0x090a3b5d656e6f5f\n"
".quad 0x203436752e646461,0x2c39333164722509,0x2c38333164722520,0x0a3b353164722520\n"
".quad 0x373109636f6c2e09,0x090a300936313509,0x65726168732e646c,0x2509203233662e64\n"
".quad 0x72255b202c383766,0x0a3b5d302b303264,0x373109636f6c2e09,0x090a300938343509\n"
".quad 0x61626f6c672e7473,0x5b09203233662e6c,0x302b393331647225,0x3b38376625202c5d\n"
".quad 0x3109636f6c2e090a,0x0a30093035350937,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5b202c3034316472,0x6170616475635f5f,0x6237315a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f\n"
".quad 0x5f30535f30535f53,0x675f5f30535f3053,0x656e6f5f736f705f,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x647225202c313431,0x647225202c303431,0x6f6c2e090a3b3531\n"
".quad 0x3631350937310963,0x732e646c090a3009,0x31752e6465726168,0x3437327225092036\n"
".quad 0x37316472255b202c,0x6c2e090a3b5d302b,0x353509373109636f,0x2e7473090a300930\n"
".quad 0x752e6c61626f6c67,0x6472255b09203233,0x202c5d302b313431,0x090a3b3437327225\n"
".quad 0x20696e752e617262,0x315f305f744c2409,0x240a3b3234323630,0x3630315f305f744c\n"
".quad 0x6c2e090a3a383934,0x313509373109636f,0x2e646c090a300936,0x752e646572616873\n"
".quad 0x3332722509203233,0x75635f5f5b202c37,0x6c61636f6c5f6164,0x3037335f7261765f\n"
".quad 0x6f6e5f30345f3739,0x5f74736e6f635f6e,0x6d5f74657366666f,0x626d616c5f746c75\n"
".quad 0x6c2e090a3b5d6164,0x353509373109636f,0x627573090a300934,0x722509203233752e\n"
".quad 0x357225202c353732,0x3b3733327225202c,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x327225202c363732,0x090a3b34202c3537,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x327225202c323431,0x2e646c090a3b3637,0x36752e6d61726170,0x3431647225092034\n"
".quad 0x75635f5f5b202c33,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x66656c5f675f5f30,0x3b5d746c756d5f74,0x36752e646461090a\n"
".quad 0x3431647225092034,0x3431647225202c34,0x3431647225202c33,0x636f6c2e090a3b32\n"
".quad 0x0936313509373109,0x68732e646c090a30,0x3233662e64657261,0x202c373766250920\n"
".quad 0x302b39316472255b,0x636f6c2e090a3b5d,0x0934353509373109,0x6c672e7473090a30\n"
".quad 0x3233662e6c61626f,0x34316472255b0920,0x6625202c5d302b34,0x6f6c2e090a3b3737\n"
".quad 0x3535350937310963,0x702e646c090a3009,0x3436752e6d617261,0x3534316472250920\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623731,0x614c6c656e72654b\n"
".quad 0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30,0x5f30535f535f535f\n"
".quad 0x30535f30535f3053,0x686769725f675f5f,0x3b5d746c756d5f74,0x36752e646461090a\n"
".quad 0x3431647225092034,0x3431647225202c36,0x3431647225202c35,0x636f6c2e090a3b32\n"
".quad 0x0936313509373109,0x68732e646c090a30,0x3233662e64657261,0x202c383766250920\n"
".quad 0x302b30326472255b,0x636f6c2e090a3b5d,0x0935353509373109,0x6c672e7473090a30\n"
".quad 0x3233662e6c61626f,0x34316472255b0920,0x6625202c5d302b36,0x6f6c2e090a3b3837\n"
".quad 0x3635350937310963,0x732e646c090a3009,0x31752e6465726168,0x3737327225092036\n"
".quad 0x36316472255b202c,0x646c090a3b5d302b,0x752e6d617261702e,0x3164722509203436\n"
".quad 0x635f5f5b202c3734,0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x656c5f675f5f3053,0x746e756f635f7466,0x0a3b5d746c756d5f\n"
".quad 0x3436752e64646109,0x3834316472250920,0x373431647225202c,0x323431647225202c\n"
".quad 0x6c672e7473090a3b,0x3233752e6c61626f,0x34316472255b0920,0x7225202c5d302b38\n"
".quad 0x6c2e090a3b373732,0x353509373109636f,0x2e646c090a300937,0x36752e6d61726170\n"
".quad 0x3431647225092034,0x75635f5f5b202c39,0x5f5f6d7261706164,0x636573696237315a\n"
".quad 0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053\n"
".quad 0x30535f535f535f30,0x535f30535f30535f,0x6769725f675f5f30,0x746e756f635f7468\n"
".quad 0x0a3b5d746c756d5f,0x3436752e64646109,0x3035316472250920,0x393431647225202c\n"
".quad 0x323431647225202c,0x09636f6c2e090a3b,0x3009363135093731,0x6168732e646c090a\n"
".quad 0x203631752e646572,0x202c343732722509,0x302b37316472255b,0x636f6c2e090a3b5d\n"
".quad 0x0937353509373109,0x6c672e7473090a30,0x3233752e6c61626f,0x35316472255b0920\n"
".quad 0x7225202c5d302b30,0x744c240a3b343732,0x34323630315f305f,0x732e646c090a3a32\n"
".quad 0x33752e6465726168,0x3837327225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x323836335f726176,0x6e6f6e5f30345f35,0x6e5f74736e6f635f,0x61657268745f6d75\n"
".quad 0x76697463615f7364,0x746573090a3b5d65,0x3233752e656c2e70,0x202c343870250920\n"
".quad 0x25202c3837327225,0x40090a3b37323172,0x6172622034387025,0x5f305f744c240920\n"
".quad 0x0a3b363632373031,0x2e6f6c2e6c756d09,0x3272250920323375,0x32317225202c3937\n"
".quad 0x6d090a3b32202c37,0x33752e6f6c2e6c75,0x3038327225092032,0x2c3732317225202c\n"
".quad 0x747663090a3b3420,0x3233752e3436752e,0x2c35356472250920,0x0a3b393732722520\n"
".quad 0x3436752e74766309,0x722509203233752e,0x7225202c30313164,0x6461090a3b303832\n"
".quad 0x2509203436752e64,0x25202c3135316472,0x7225202c35356472,0x646461090a3b3564\n"
".quad 0x722509203436752e,0x7225202c32353164,0x7225202c30313164,0x646461090a3b3164\n"
".quad 0x722509203436752e,0x7225202c33353164,0x7225202c30313164,0x2e646c090a3b3464\n"
".quad 0x752e646572616873,0x3832722509203631,0x316472255b202c31,0x090a3b5d302b3135\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c393766,0x3b5d302b32353164\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x5b202c3038662509,0x302b333531647225\n"
".quad 0x636f6c2e090a3b5d,0x0936313509373109,0x68732e646c090a30,0x3233752e64657261\n"
".quad 0x2c37333272250920,0x616475635f5f5b20,0x765f6c61636f6c5f,0x37393037335f7261\n"
".quad 0x5f6e6f6e5f30345f,0x666f5f74736e6f63,0x6c756d5f74657366,0x6164626d616c5f74\n"
".quad 0x636f6c2e090a3b5d,0x0937353509373109,0x2e70746573090a30,0x09203233752e6567\n"
".quad 0x7225202c35387025,0x327225202c373231,0x702540090a3b3733,0x0920617262203538\n"
".quad 0x30315f305f744c24,0x2e090a3b32323537,0x3509373109636f6c,0x646c090a30093436\n"
".quad 0x752e6d617261702e,0x3164722509203436,0x635f5f5b202c3435,0x5f6d726170616475\n"
".quad 0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f\n"
".quad 0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30,0x656c5f675f5f3053\n"
".quad 0x3b5d656e6f5f7466,0x36752e646461090a,0x3531647225092034,0x3531647225202c35\n"
".quad 0x3131647225202c34,0x636f6c2e090a3b30,0x0937353509373109,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x202c393766250920,0x2b3235316472255b,0x6f6c2e090a3b5d30\n"
".quad 0x3436350937310963,0x672e7473090a3009,0x33662e6c61626f6c,0x316472255b092032\n"
".quad 0x25202c5d302b3535,0x6c2e090a3b393766,0x363509373109636f,0x2e646c090a300935\n"
".quad 0x36752e6d61726170,0x3531647225092034,0x75635f5f5b202c36,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x6769725f675f5f30\n"
".quad 0x3b5d656e6f5f7468,0x36752e646461090a,0x3531647225092034,0x3531647225202c37\n"
".quad 0x3131647225202c36,0x636f6c2e090a3b30,0x0937353509373109,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x202c303866250920,0x2b3335316472255b,0x6f6c2e090a3b5d30\n"
".quad 0x3536350937310963,0x672e7473090a3009,0x33662e6c61626f6c,0x316472255b092032\n"
".quad 0x25202c5d302b3735,0x6c2e090a3b303866,0x363509373109636f,0x2e646c090a300937\n"
".quad 0x36752e6d61726170,0x3531647225092034,0x75635f5f5b202c38,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x736f705f675f5f30\n"
".quad 0x090a3b5d656e6f5f,0x203436752e646461,0x2c39353164722509,0x2c38353164722520\n"
".quad 0x3b30313164722520,0x3109636f6c2e090a,0x0a30093735350937,0x726168732e646c09\n"
".quad 0x09203631752e6465,0x5b202c3138327225,0x302b313531647225,0x636f6c2e090a3b5d\n"
".quad 0x0937363509373109,0x6c672e7473090a30,0x3233752e6c61626f,0x35316472255b0920\n"
".quad 0x7225202c5d302b39,0x7262090a3b313832,0x240920696e752e61,0x3730315f305f744c\n"
".quad 0x744c240a3b363632,0x32353730315f305f,0x636f6c2e090a3a32,0x0936313509373109\n"
".quad 0x68732e646c090a30,0x3233752e64657261,0x2c37333272250920,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x37393037335f7261,0x5f6e6f6e5f30345f,0x666f5f74736e6f63\n"
".quad 0x6c756d5f74657366,0x6164626d616c5f74,0x636f6c2e090a3b5d,0x0931373509373109\n"
".quad 0x752e627573090a30,0x3832722509203233,0x3732317225202c32,0x3b3733327225202c\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x327225202c333832,0x090a3b34202c3238\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x327225202c303631,0x2e646c090a3b3338\n"
".quad 0x36752e6d61726170,0x3631647225092034,0x75635f5f5b202c31,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x66656c5f675f5f30\n"
".quad 0x3b5d746c756d5f74,0x36752e646461090a,0x3631647225092034,0x3631647225202c32\n"
".quad 0x3631647225202c31,0x636f6c2e090a3b30,0x0937353509373109,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x202c393766250920,0x2b3235316472255b,0x6f6c2e090a3b5d30\n"
".quad 0x3137350937310963,0x672e7473090a3009,0x33662e6c61626f6c,0x316472255b092032\n"
".quad 0x25202c5d302b3236,0x6c2e090a3b393766,0x373509373109636f,0x2e646c090a300932\n"
".quad 0x36752e6d61726170,0x3631647225092034,0x75635f5f5b202c33,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x6769725f675f5f30\n"
".quad 0x5d746c756d5f7468,0x752e646461090a3b,0x3164722509203436,0x31647225202c3436\n"
".quad 0x31647225202c3336,0x6f6c2e090a3b3036,0x3735350937310963,0x732e646c090a3009\n"
".quad 0x33662e6465726168,0x2c30386625092032,0x3335316472255b20,0x6c2e090a3b5d302b\n"
".quad 0x373509373109636f,0x2e7473090a300932,0x662e6c61626f6c67,0x6472255b09203233\n"
".quad 0x202c5d302b343631,0x2e090a3b30386625,0x3509373109636f6c,0x6461090a30093337\n"
".quad 0x2509203436752e64,0x25202c3536316472,0x7225202c35356472,0x2e646c090a3b3264\n"
".quad 0x752e646572616873,0x3832722509203631,0x316472255b202c34,0x090a3b5d302b3536\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x5f5b202c36363164,0x726170616475635f\n"
".quad 0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65,0x6a6a66666a5f5366\n"
".quad 0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f,0x5f675f5f30535f30\n"
".quad 0x756f635f7466656c,0x5d746c756d5f746e,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3736,0x31647225202c3636,0x2e7473090a3b3036,0x752e6c61626f6c67\n"
".quad 0x6472255b09203233,0x202c5d302b373631,0x090a3b3438327225,0x09373109636f6c2e\n"
".quad 0x6c090a3009343735,0x2e6d617261702e64,0x6472250920343675,0x5f5f5b202c383631\n"
".quad 0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c\n"
".quad 0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053\n"
".quad 0x725f675f5f30535f,0x756f635f74686769,0x5d746c756d5f746e,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x31647225202c3936,0x31647225202c3836,0x6f6c2e090a3b3036\n"
".quad 0x3735350937310963,0x732e646c090a3009,0x31752e6465726168,0x3138327225092036\n"
".quad 0x35316472255b202c,0x2e090a3b5d302b31,0x3509373109636f6c,0x7473090a30093437\n"
".quad 0x2e6c61626f6c672e,0x72255b0920323375,0x2c5d302b39363164,0x0a3b313832722520\n"
".quad 0x30315f305f744c24,0x4c240a3a36363237,0x373630315f305f74,0x2e646c090a3a3435\n"
".quad 0x752e646572616873,0x3332722509203233,0x75635f5f5b202c36,0x6c61636f6c5f6164\n"
".quad 0x3037335f7261765f,0x6f6e5f30345f3539,0x5f74736e6f635f6e,0x636f6c625f6d756e\n"
".quad 0x5d746c756d5f736b,0x2e70746573090a3b,0x09203233752e746c,0x7225202c36387025\n"
".quad 0x357225202c363332,0x3638702540090a3b,0x4c24092061726220,0x373730315f305f74\n"
".quad 0x6f6c2e090a3b3837,0x3238350937310963,0x732e646c090a3009,0x31752e6465726168\n"
".quad 0x3538327225092036,0x38316472255b202c,0x646c090a3b5d302b,0x752e6d617261702e\n"
".quad 0x3164722509203436,0x635f5f5b202c3037,0x5f6d726170616475,0x6573696237315a5f\n"
".quad 0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a\n"
".quad 0x535f535f535f3053,0x5f30535f30535f30,0x6c625f675f5f3053,0x6c756d5f736b636f\n"
".quad 0x646461090a3b5d74,0x722509203436752e,0x7225202c31373164,0x7225202c30373164\n"
".quad 0x7473090a3b353164,0x2e6c61626f6c672e,0x72255b0920323375,0x2c5d302b31373164\n"
".quad 0x0a3b353832722520,0x373109636f6c2e09,0x090a300933383509,0x65726168732e646c\n"
".quad 0x2509203631752e64,0x255b202c36383272,0x3b5d302b33396472,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x202c323731647225,0x70616475635f5f5b,0x37315a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a\n"
".quad 0x535f30535f535f53,0x30535f30535f535f,0x5f5f30535f30535f,0x736b636f6c625f67\n"
".quad 0x75735f746c756d5f,0x646461090a3b5d6d,0x722509203436752e,0x7225202c33373164\n"
".quad 0x7225202c32373164,0x7473090a3b353164,0x2e6c61626f6c672e,0x72255b0920323375\n"
".quad 0x2c5d302b33373164,0x0a3b363832722520,0x30315f305f744c24,0x2e090a3a38373737\n"
".quad 0x3509373109636f6c,0x646c090a30093437,0x2e6465726168732e,0x3272250920323375\n"
".quad 0x635f5f5b202c3633,0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f30345f353930\n"
".quad 0x74736e6f635f6e6f,0x6f6c625f6d756e5f,0x746c756d5f736b63,0x636f6c2e090a3b5d\n"
".quad 0x0933383509373109,0x2e70746573090a30,0x09203233752e7467,0x7225202c37387025\n"
".quad 0x327225202c373231,0x702540090a3b3633,0x0920617262203738,0x30315f305f744c24\n"
".quad 0x2e090a3b30393238,0x3509373109636f6c,0x756d090a30093638,0x3233752e6f6c2e6c\n"
".quad 0x2c37383272250920,0x202c373231722520,0x2e6c756d090a3b32,0x09203233752e6f6c\n"
".quad 0x25202c3838327225,0x3b34202c37323172,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c35356472,0x7663090a3b373832,0x33752e3436752e74,0x3131647225092032\n"
".quad 0x3838327225202c30,0x752e646461090a3b,0x3164722509203436,0x35647225202c3437\n"
".quad 0x3b33647225202c35,0x6168732e646c090a,0x203631752e646572,0x202c393832722509\n"
".quad 0x2b3437316472255b,0x2e646c090a3b5d30,0x36752e6d61726170,0x3731647225092034\n"
".quad 0x75635f5f5b202c35,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x6f6c625f675f5f30,0x746c756d5f736b63,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x647225202c363731,0x647225202c353731,0x7473090a3b303131\n"
".quad 0x2e6c61626f6c672e,0x72255b0920323375,0x2c5d302b36373164,0x0a3b393832722520\n"
".quad 0x373109636f6c2e09,0x090a300937383509,0x203436752e646461,0x2c37373164722509\n"
".quad 0x202c353564722520,0x090a3b3235647225,0x65726168732e646c,0x2509203631752e64\n"
".quad 0x255b202c30393272,0x5d302b3737316472,0x61702e646c090a3b,0x203436752e6d6172\n"
".quad 0x2c38373164722509,0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237\n"
".quad 0x72614c6c656e7265,0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f\n"
".quad 0x535f30535f535f53,0x5f30535f30535f30,0x6b636f6c625f675f,0x735f746c756d5f73\n"
".quad 0x6461090a3b5d6d75,0x2509203436752e64,0x25202c3937316472,0x25202c3837316472\n"
".quad 0x090a3b3031316472,0x61626f6c672e7473,0x5b09203233752e6c,0x302b393731647225\n"
".quad 0x3039327225202c5d,0x5f305f744c240a3b,0x0a3a303932383031,0x373109636f6c2e09\n"
".quad 0x090a300932323509,0x4c240a3b74697865,0x5a5f5f646e655744,0x7463657369623731\n"
".quad 0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30\n"
".quad 0x5f30535f535f535f,0x30535f30535f3053,0x2f2f207d090a3a5f,0x73696237315a5f20\n"
".quad 0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50\n"
".quad 0x5f535f535f30535f,0x30535f30535f3053,0x2e090a0a5f30535f,0x5a5f207972746e65\n"
".quad 0x7463657369623033,0x614c6c656e72654b,0x49656e4f5f656772,0x736c61767265746e\n"
".quad 0x5f536a6a5f536650,0x0a2820666a505f53,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365,0x4f5f656772614c6c\n"
".quad 0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a,0x09090a2c645f675f\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x636573696230335a\n"
".quad 0x4c6c656e72654b74,0x656e4f5f65677261,0x6c61767265746e49,0x536a6a5f53665073\n"
".quad 0x675f666a505f535f,0x702e09090a2c735f,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x335a5f5f6d726170,0x4b74636573696230,0x72614c6c656e7265,0x6e49656e4f5f6567\n"
".quad 0x50736c6176726574,0x535f536a6a5f5366,0x0a2c6e5f666a505f,0x6d617261702e0909\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365\n"
".quad 0x4f5f656772614c6c,0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a\n"
".quad 0x746e695f6d756e5f,0x0a2c736c61767265,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365,0x4f5f656772614c6c\n"
".quad 0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a,0x2c7466656c5f675f\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x696230335a5f5f6d\n"
".quad 0x6e72654b74636573,0x5f656772614c6c65,0x7265746e49656e4f,0x5f536650736c6176\n"
".quad 0x6a505f535f536a6a,0x686769725f675f66,0x61702e09090a2c74,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x30335a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x746e49656e4f5f65,0x6650736c61767265,0x5f535f536a6a5f53,0x6f705f675f666a50\n"
".quad 0x61702e09090a2c73,0x3233662e206d6172,0x70616475635f5f20,0x30335a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x746e49656e4f5f65,0x6650736c61767265\n"
".quad 0x5f535f536a6a5f53,0x636572705f666a50,0x090a296e6f697369,0x206765722e090a7b\n"
".quad 0x3c7225203233752e,0x722e090a3b3e3634,0x203436752e206765,0x3b3e37323c647225\n"
".quad 0x2e206765722e090a,0x343c662520323366,0x65722e090a3b3e32,0x20646572702e2067\n"
".quad 0x0a3b3e38313c7025,0x6465726168732e09,0x206e67696c612e20,0x5f5f2038622e2034\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f33335f383337\n"
".quad 0x74736e6f635f6e6f,0x74686769725f735f,0x686374617263735f,0x3230315b38383338\n"
".quad 0x68732e090a3b5d34,0x6c612e2064657261,0x622e2034206e6769,0x616475635f5f2038\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f37333737335f72,0x635f6e6f6e5f3333\n"
".quad 0x6c5f735f74736e6f,0x617263735f746665,0x5b32313439686374,0x090a3b5d34323031\n"
".quad 0x206465726168732e,0x635f5f203233752e,0x61636f6c5f616475,0x37335f7261765f6c\n"
".quad 0x6e5f30345f323637,0x74736e6f635f6e6f,0x677265766e6f635f,0x745f6c6c615f6465\n"
".quad 0x0a3b736461657268,0x383109636f6c2e09,0x4c240a3009303709,0x5f6e696765625744\n"
".quad 0x6573696230335a5f,0x6c656e72654b7463,0x6e4f5f656772614c,0x61767265746e4965\n"
".quad 0x6a6a5f536650736c,0x3a666a505f535f53,0x33752e747663090a,0x2509203631752e32\n"
".quad 0x69746e25202c3172,0x7663090a3b782e64,0x31752e3233752e74,0x202c327225092036\n"
".quad 0x782e646961746325,0x6c2e6c756d090a3b,0x2509203233752e6f,0x2c327225202c3372\n"
".quad 0x63090a3b31722520,0x752e3233752e7476,0x2c34722509203631,0x3b782e6469742520\n"
".quad 0x33752e646461090a,0x202c357225092032,0x347225202c337225,0x61702e646c090a3b\n"
".quad 0x203233752e6d6172,0x5f5b202c36722509,0x726170616475635f,0x696230335a5f5f6d\n"
".quad 0x6e72654b74636573,0x5f656772614c6c65,0x7265746e49656e4f,0x5f536650736c6176\n"
".quad 0x6a505f535f536a6a,0x6e695f6d756e5f66,0x5d736c6176726574,0x2e70746573090a3b\n"
".quad 0x09203233752e7467,0x367225202c317025,0x090a3b357225202c,0x7262203170252140\n"
".quad 0x315f744c24092061,0x0a3b36383336315f,0x383109636f6c2e09,0x6d090a3009323909\n"
".quad 0x33752e6f6c2e6c75,0x202c377225092032,0x0a3b34202c357225,0x3436752e74766309\n"
".quad 0x722509203233752e,0x3b377225202c3164,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c32647225,0x726170616475635f,0x696230335a5f5f6d,0x6e72654b74636573\n"
".quad 0x5f656772614c6c65,0x7265746e49656e4f,0x5f536650736c6176,0x6a505f535f536a6a\n"
".quad 0x7466656c5f675f66,0x2e646461090a3b5d,0x6472250920343675,0x2c32647225202c33\n"
".quad 0x090a3b3164722520,0x61626f6c672e646c,0x2509203233662e6c,0x6472255b202c3166\n"
".quad 0x6d090a3b5d302b33,0x09203233662e766f,0x316625202c326625,0x09636f6c2e090a3b\n"
".quad 0x0a30093339093831,0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c346472\n"
".quad 0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365,0x4f5f656772614c6c\n"
".quad 0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a,0x74686769725f675f\n"
".quad 0x2e646461090a3b5d,0x6472250920343675,0x2c34647225202c35,0x090a3b3164722520\n"
".quad 0x61626f6c672e646c,0x2509203233662e6c,0x6472255b202c3366,0x6d090a3b5d302b35\n"
".quad 0x09203233662e766f,0x336625202c346625,0x09636f6c2e090a3b,0x0a30093439093831\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c366472,0x6d72617061647563\n"
".quad 0x73696230335a5f5f,0x656e72654b746365,0x4f5f656772614c6c,0x767265746e49656e\n"
".quad 0x6a5f536650736c61,0x666a505f535f536a,0x3b5d736f705f675f,0x36752e646461090a\n"
".quad 0x2c37647225092034,0x25202c3664722520,0x646c090a3b316472,0x2e6c61626f6c672e\n"
".quad 0x3872250920323375,0x2b376472255b202c,0x766f6d090a3b5d30,0x722509203233732e\n"
".quad 0x0a3b387225202c39,0x36315f315f744c24,0x6f6d090a3a363833,0x2509203233752e76\n"
".quad 0x0a3b30202c303172,0x656e2e7074657309,0x702509203233752e,0x202c347225202c32\n"
".quad 0x40090a3b30317225,0x2061726220327025,0x315f315f744c2409,0x2e090a3b38393836\n"
".quad 0x3109383109636f6c,0x6f6d090a30093330,0x2509203233752e76,0x0a3b30202c313172\n"
".quad 0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f32363737335f72,0x635f6e6f6e5f3034,0x6e6f635f74736e6f,0x615f646567726576\n"
".quad 0x61657268745f6c6c,0x317225202c5d7364,0x315f744c240a3b31,0x0a3a38393836315f\n"
".quad 0x383109636f6c2e09,0x090a300935303109,0x636e79732e726162,0x646c090a3b300920\n"
".quad 0x752e6d617261702e,0x3231722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x7463657369623033,0x614c6c656e72654b,0x49656e4f5f656772,0x736c61767265746e\n"
".quad 0x5f536a6a5f536650,0x5d6e5f666a505f53,0x752e766f6d090a3b,0x3331722509203233\n"
".quad 0x6573090a3b30202c,0x33752e74672e7074,0x202c337025092032,0x7225202c32317225\n"
".quad 0x6c6573090a3b3331,0x2509203233732e70,0x202c31202c343172,0x0a3b317025202c30\n"
".quad 0x3233662e766f6d09,0x30202c3566250920,0x3030303030303066,0x0920202020203b30\n"
".quad 0x6f6d090a30202f2f,0x2509203233752e76,0x0a3b30202c353172,0x3436752e766f6d09\n"
".quad 0x202c386472250920,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x33335f3833373733,0x6e6f635f6e6f6e5f,0x6769725f735f7473,0x74617263735f7468\n"
".quad 0x0a3b383833386863,0x3436752e766f6d09,0x202c396472250920,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3733373733,0x6e6f635f6e6f6e5f\n"
".quad 0x66656c5f735f7473,0x6374617263735f74,0x240a3b3231343968,0x3531315f315f744c\n"
".quad 0x3c2f2f200a3a3232,0x6f4c203e706f6f6c,0x2079646f6220706f,0x31313120656e696c\n"
".quad 0x3109636f6c2e090a,0x0a30093131310938,0x3233752e766f6d09,0x202c363172250920\n"
".quad 0x732e7473090a3b31,0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164\n"
".quad 0x3737335f7261765f,0x6f6e5f30345f3236,0x5f74736e6f635f6e,0x65677265766e6f63\n"
".quad 0x68745f6c6c615f64,0x202c5d7364616572,0x6d090a3b36317225,0x09203233752e766f\n"
".quad 0x3b30202c37317225,0x652e70746573090a,0x2509203233752e71,0x35317225202c3470\n"
".quad 0x0a3b37317225202c,0x33732e706c657309,0x2c38317225092032,0x25202c30202c3120\n"
".quad 0x646e61090a3b3470,0x722509203233622e,0x38317225202c3931,0x0a3b34317225202c\n"
".quad 0x3233752e766f6d09,0x202c303272250920,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x7225202c35702509,0x30327225202c3931,0x2035702540090a3b,0x744c240920617262\n"
".quad 0x30313437315f315f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c31313120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32323531315f315f,0x33662e766f6d090a,0x202c366625092032,0x6f6d090a3b326625\n"
".quad 0x2509203233662e76,0x30306630202c3766,0x203b303030303030,0x202f2f0920202020\n"
".quad 0x2e70746573090a30,0x09203233662e746c,0x366625202c367025,0x090a3b376625202c\n"
".quad 0x203233662e766f6d,0x6625202c38662509,0x2e766f6d090a3b34,0x3966250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x746c2e7074657309\n"
".quad 0x702509203233662e,0x202c386625202c37,0x2140090a3b396625,0x2061726220377025\n"
".quad 0x315f315f744c2409,0x2f200a3b38373138,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3131,0x64656c6562616c20\n"
".quad 0x315f315f744c2420,0x6c2e090a32323531,0x313109383109636f,0x6c6573090a300936\n"
".quad 0x2509203233732e70,0x202c31202c313272,0x0a3b367025202c30,0x696e752e61726209\n"
".quad 0x5f315f744c240920,0x240a3b3232393731,0x3138315f315f744c,0x3c2f2f200a3a3837\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x31313120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3531315f315f744c,0x706c6573090a3232\n"
".quad 0x722509203233732e,0x31202c30202c3132,0x240a3b367025202c,0x3937315f315f744c\n"
".quad 0x3c2f2f200a3a3232,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x31313120656e696c,0x6c2064616568202c,0x242064656c656261,0x3531315f315f744c\n"
".quad 0x2e627573090a3232,0x3166250920323366,0x202c386625202c30,0x6f6d090a3b366625\n"
".quad 0x2509203233662e76,0x336630202c313166,0x3b30303030303066,0x202f2f0920202020\n"
".quad 0x64616d090a352e30,0x662509203233662e,0x30316625202c3231,0x202c31316625202c\n"
".quad 0x6461090a3b366625,0x2509203233662e64,0x386625202c333166,0x090a3b366625202c\n"
".quad 0x203233662e766f6d,0x30202c3431662509,0x3030303030663366,0x2f09202020203b30\n"
".quad 0x6d090a352e30202f,0x09203233662e6c75,0x6625202c35316625,0x34316625202c3331\n"
".quad 0x732e67656e090a3b,0x3232722509203233,0x0a3b31327225202c,0x33662e74636c7309\n"
".quad 0x2509203233732e32,0x35316625202c3566,0x202c32316625202c,0x4c240a3b32327225\n"
".quad 0x313437315f315f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31313120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x323531315f315f74,0x09636f6c2e090a32,0x3009383332093631,0x33732e766f6d090a\n"
".quad 0x2c33327225092032,0x090a3b3231722520,0x7262203370252140,0x315f744c24092061\n"
".quad 0x0a3b36363034325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465\n"
".quad 0x090a32323531315f,0x203233752e766f6d,0x30202c3432722509,0x752e766f6d090a3b\n"
".quad 0x3532722509203233,0x6f6d090a3b30202c,0x2509203233662e76,0x336630202c363166\n"
".quad 0x3b30303030303866,0x202f2f0920202020,0x5f315f744c240a31,0x200a3a3634393831\n"
".quad 0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964,0x73656e202c383332\n"
".quad 0x70656420676e6974,0x65202c31203a6874,0x646574616d697473,0x6974617265746920\n"
".quad 0x6b6e75203a736e6f,0x6c2e090a6e776f6e,0x343209363109636f,0x726162090a300933\n"
".quad 0x300920636e79732e,0x752e646461090a3b,0x3632722509203233,0x202c34327225202c\n"
".quad 0x6573090a3b347225,0x33752e656c2e7074,0x202c387025092032,0x7225202c32317225\n"
".quad 0x702540090a3b3632,0x2409206172622038,0x3239315f315f744c,0x3c2f2f200a3b3230\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x38333220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3938315f315f744c,0x636f6c2e090a3634\n"
".quad 0x0938343209363109,0x34326c756d090a30,0x203233752e6f6c2e,0x25202c3732722509\n"
".quad 0x090a3b34202c3472,0x2e3436752e747663,0x6472250920323375,0x37327225202c3031\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x327225202c383272,0x63090a3b34202c34\n"
".quad 0x752e3436752e7476,0x3164722509203233,0x3b38327225202c31,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5b202c3231647225,0x6170616475635f5f,0x6230335a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x65746e49656e4f5f,0x536650736c617672\n"
".quad 0x505f535f536a6a5f,0x3b5d645f675f666a,0x36752e646461090a,0x3331647225092034\n"
".quad 0x2c3231647225202c,0x0a3b313164722520,0x3436752e64646109,0x2c34316472250920\n"
".quad 0x202c303164722520,0x090a3b3331647225,0x61626f6c672e646c,0x2509203233662e6c\n"
".quad 0x72255b202c373166,0x0a3b5d302b343164,0x3436752e64646109,0x2c35316472250920\n"
".quad 0x202c303164722520,0x73090a3b39647225,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d302b35316472,0x090a3b3731662520,0x09363109636f6c2e,0x6c090a3009393432\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x635f5f5b202c3631,0x5f6d726170616475\n"
".quad 0x6573696230335a5f,0x6c656e72654b7463,0x6e4f5f656772614c,0x61767265746e4965\n"
".quad 0x6a6a5f536650736c,0x5f666a505f535f53,0x61090a3b5d735f67,0x09203436752e6464\n"
".quad 0x25202c3731647225,0x7225202c36316472,0x6461090a3b313164,0x2509203436752e64\n"
".quad 0x7225202c38316472,0x647225202c303164,0x2e646c090a3b3731,0x662e6c61626f6c67\n"
".quad 0x3831662509203233,0x38316472255b202c,0x61090a3b5d342d2b,0x09203436752e6464\n"
".quad 0x25202c3931647225,0x7225202c30316472,0x2e7473090a3b3864,0x662e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3931,0x744c240a3b383166,0x32303239315f315f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c38333220656e,0x62616c2064616568,0x744c242064656c65,0x36343938315f315f\n"
".quad 0x3109636f6c2e090a,0x0a30093235320936,0x6e79732e72616209,0x40090a3b30092063\n"
".quad 0x6172622031702521,0x5f315f744c240920,0x200a3b3632323032,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x6d090a3634393831,0x09203233752e6e69\n"
".quad 0x7225202c39327225,0x3b317225202c3332,0x33752e766f6d090a,0x2c30337225092032\n"
".quad 0x746573090a3b3020,0x3233752e71652e70,0x25202c3970250920,0x337225202c393272\n"
".quad 0x39702540090a3b30,0x4c24092061726220,0x323230325f315f74,0x6c3c2f2f200a3b36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38333220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x343938315f315f74,0x732e766f6d090a36\n"
".quad 0x3133722509203233,0x0a3b39327225202c,0x3233752e766f6d09,0x202c323372250920\n"
".quad 0x2e6c756d090a3b30,0x09203233752e6f6c,0x7225202c33337225,0x200a3b34202c3932\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383332,0x656c6562616c2064,0x5f315f744c242064,0x6d090a3634393831\n"
".quad 0x09203233732e766f,0x7225202c34337225,0x5f744c240a3b3133,0x3a38333730325f31\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3235322065\n"
".quad 0x6420676e69747365,0x2c32203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09363109636f6c2e,0x63090a3009303632\n"
".quad 0x752e3436752e7476,0x3264722509203233,0x3b32337225202c30,0x36752e646461090a\n"
".quad 0x3132647225092034,0x2c3032647225202c,0x090a3b3864722520,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c393166,0x0a3b5d302b313264,0x3436752e64646109\n"
".quad 0x2c32326472250920,0x202c303264722520,0x6c090a3b39647225,0x6465726168732e64\n"
".quad 0x662509203233662e,0x6472255b202c3032,0x090a3b5d302b3232,0x203233662e627573\n"
".quad 0x25202c3132662509,0x356625202c303266,0x662e6c756d090a3b,0x3232662509203233\n"
".quad 0x202c39316625202c,0x64090a3b39316625,0x2e6c6c75662e7669,0x3266250920323366\n"
".quad 0x2c32326625202c33,0x090a3b3631662520,0x203233662e627573,0x25202c3631662509\n"
".quad 0x326625202c313266,0x636f6c2e090a3b33,0x0932363209363109,0x662e766f6d090a30\n"
".quad 0x3432662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x752e746c2e746573,0x09203233662e3233,0x6625202c35337225,0x34326625202c3631\n"
".quad 0x732e67656e090a3b,0x3633722509203233,0x0a3b35337225202c,0x3233752e64646109\n"
".quad 0x202c353272250920,0x7225202c35327225,0x646461090a3b3633,0x722509203233752e\n"
".quad 0x32337225202c3233,0x6573090a3b34202c,0x33752e656e2e7074,0x2c30317025092032\n"
".quad 0x25202c3233722520,0x2540090a3b333372,0x2061726220303170,0x325f315f744c2409\n"
".quad 0x4c240a3b38333730,0x323230325f315f74,0x315f744c240a3a36,0x0a3a34313739315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c38333220,0x6c6562616c206461,0x315f744c24206465,0x090a36343938315f\n"
".quad 0x09363109636f6c2e,0x73090a3009373632,0x09203233752e6275,0x7225202c33327225\n"
".quad 0x3b317225202c3332,0x33752e646461090a,0x2c34327225092032,0x25202c3432722520\n"
".quad 0x746573090a3b3172,0x3233752e746c2e70,0x202c313170250920,0x7225202c34327225\n"
".quad 0x702540090a3b3231,0x0920617262203131,0x38315f315f744c24,0x2f2f200a3b363439\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313120656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x31315f315f744c24,0x617262090a323235\n"
".quad 0x4c240920696e752e,0x333438315f315f74,0x315f744c240a3b34,0x0a3a36363034325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465,0x090a32323531315f\n"
".quad 0x203233752e766f6d,0x30202c3532722509,0x5f315f744c240a3b,0x200a3a3433343831\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313131,0x656c6562616c2064,0x5f315f744c242064,0x2e090a3232353131\n"
".quad 0x3109383109636f6c,0x6162090a30093632,0x0920636e79732e72,0x2e766f6d090a3b30\n"
".quad 0x3372250920323375,0x73090a3b30202c37,0x732e71652e707465,0x3231702509203233\n"
".quad 0x202c39317225202c,0x40090a3b37337225,0x6172622032317025,0x5f315f744c240920\n"
".quad 0x200a3b3033353232,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313131,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x6d090a3232353131,0x09203233732e766f,0x7225202c38337225,0x70746573090a3b39\n"
".quad 0x203233752e656e2e,0x25202c3331702509,0x327225202c383372,0x31702540090a3b35\n"
".quad 0x2409206172622033,0x3232325f315f744c,0x3c2f2f200a3b3437,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31313120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3531315f315f744c,0x636f6c2e090a3232,0x0933333109383109\n"
".quad 0x662e766f6d090a30,0x2c38662509203233,0x6d090a3b35662520,0x09203233662e766f\n"
".quad 0x386625202c346625,0x662e766f6d090a3b,0x2c36662509203233,0x62090a3b32662520\n"
".quad 0x0920696e752e6172,0x32325f315f744c24,0x744c240a3b383130,0x34373232325f315f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c31313120656e,0x62616c2064616568,0x744c242064656c65,0x32323531315f315f\n"
".quad 0x3109636f6c2e090a,0x0a30093633310938,0x3233662e766f6d09,0x25202c3666250920\n"
".quad 0x766f6d090a3b3566,0x662509203233662e,0x0a3b366625202c32,0x3233662e766f6d09\n"
".quad 0x25202c3866250920,0x5f744c240a3b3466,0x3a38313032325f31,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3131312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32323531315f31,0x3233662e62757309\n"
".quad 0x202c353266250920,0x366625202c386625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5b202c3632662509,0x6170616475635f5f,0x6230335a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x65746e49656e4f5f,0x536650736c617672,0x505f535f536a6a5f\n"
".quad 0x69636572705f666a,0x090a3b5d6e6f6973,0x203233662e736261,0x25202c3732662509\n"
".quad 0x736261090a3b3866,0x662509203233662e,0x3b366625202c3832,0x33662e78616d090a\n"
".quad 0x2c39326625092032,0x25202c3732662520,0x756d090a3b383266,0x2509203233662e6c\n"
".quad 0x326625202c303366,0x3b39326625202c36,0x33662e6e696d090a,0x2c31336625092032\n"
".quad 0x25202c3632662520,0x6573090a3b303366,0x33662e746c2e7074,0x2c34317025092032\n"
".quad 0x25202c3532662520,0x2140090a3b313366,0x6172622034317025,0x5f315f744c240920\n"
".quad 0x200a3b3638373232,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313131,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x6d090a3232353131,0x09203233662e766f,0x6630202c32336625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x70746573090a3020,0x203233662e746c2e,0x6625202c36702509\n"
".quad 0x3b32336625202c36,0x33662e766f6d090a,0x2c33336625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x73090a30202f2f09,0x662e746c2e707465,0x3531702509203233\n"
".quad 0x25202c386625202c,0x2140090a3b333366,0x6172622035317025,0x5f315f744c240920\n"
".quad 0x200a3b3839323332,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313131,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x2e090a3232353131,0x3109383109636f6c,0x6573090a30093434,0x09203233732e706c\n"
".quad 0x2c31202c39337225,0x3b367025202c3020,0x6e752e617262090a,0x315f744c24092069\n"
".quad 0x0a3b32343033325f,0x33325f315f744c24,0x2f2f200a3a383932,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x313120656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x31315f315f744c24,0x6c6573090a323235,0x2509203233732e70\n"
".quad 0x202c30202c393372,0x0a3b367025202c31,0x33325f315f744c24,0x2f2f200a3a323430\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313120656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x31315f315f744c24,0x646461090a323235\n"
".quad 0x662509203233662e,0x2c386625202c3433,0x6d090a3b36662520,0x09203233662e766f\n"
".quad 0x6630202c35336625,0x3030303030306633,0x2f2f09202020203b,0x616d090a352e3020\n"
".quad 0x2509203233662e64,0x326625202c363366,0x2c35336625202c35,0x6d090a3b36662520\n"
".quad 0x09203233662e766f,0x6630202c37336625,0x3030303030306633,0x2f2f09202020203b\n"
".quad 0x756d090a352e3020,0x2509203233662e6c,0x336625202c383366,0x3b37336625202c34\n"
".quad 0x33732e67656e090a,0x2c30347225092032,0x090a3b3933722520,0x3233662e74636c73\n"
".quad 0x662509203233732e,0x38336625202c3933,0x202c36336625202c,0x2e090a3b30347225\n"
".quad 0x3109383109636f6c,0x6f6d090a30093534,0x2509203233662e76,0x39336625202c3266\n"
".quad 0x09636f6c2e090a3b,0x3009363431093831,0x33662e766f6d090a,0x202c346625092032\n"
".quad 0x6d090a3b39336625,0x09203233752e766f,0x3b31202c35317225,0x6e752e617262090a\n"
".quad 0x315f744c24092069,0x0a3b30333532325f,0x32325f315f744c24,0x2f2f200a3a363837\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313120656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x31315f315f744c24,0x6f6c2e090a323235\n"
".quad 0x3135310938310963,0x2e766f6d090a3009,0x3472250920323375,0x73090a3b30202c31\n"
".quad 0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3236373733,0x6e6f635f6e6f6e5f,0x65766e6f635f7473,0x6c6c615f64656772\n"
".quad 0x736461657268745f,0x3b31347225202c5d,0x325f315f744c240a,0x4c240a3a30333532\n"
".quad 0x303531325f315f74,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31313120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x323531315f315f74,0x09636f6c2e090a32,0x3009353531093831,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x09383109636f6c2e,0x6c090a3009383531,0x6465726168732e64\n"
".quad 0x722509203233752e,0x635f5f5b202c3234,0x61636f6c5f616475,0x37335f7261765f6c\n"
".quad 0x6e5f30345f323637,0x74736e6f635f6e6f,0x677265766e6f635f,0x745f6c6c615f6465\n"
".quad 0x3b5d736461657268,0x33752e766f6d090a,0x2c33347225092032,0x746573090a3b3120\n"
".quad 0x3233752e71652e70,0x202c363170250920,0x7225202c32347225,0x702540090a3b3334\n"
".quad 0x0920617262203631,0x69646e6557444c24,0x656469766964665f,0x3b315f3432325f66\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3131312065,0x6562616c20646165,0x5f744c242064656c,0x0a32323531315f31\n"
".quad 0x383109636f6c2e09,0x090a300931363109,0x636e79732e726162,0x7262090a3b300920\n"
".quad 0x240920696e752e61,0x3531315f315f744c,0x57444c240a3b3232,0x6964665f69646e65\n"
".quad 0x32325f6665646976,0x6c2e090a3a315f34,0x363109383109636f,0x726162090a300935\n"
".quad 0x300920636e79732e,0x3170252140090a3b,0x4c24092061726220,0x353533325f315f74\n"
".quad 0x636f6c2e090a3b34,0x0939363109383109,0x662e766f6d090a30,0x3034662509203233\n"
".quad 0x090a3b326625202c,0x752e6f6c2e6c756d,0x3434722509203233,0x34202c357225202c\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x25202c3332647225,0x646c090a3b343472\n"
".quad 0x752e6d617261702e,0x3264722509203436,0x75635f5f5b202c34,0x5f5f6d7261706164\n"
".quad 0x636573696230335a,0x4c6c656e72654b74,0x656e4f5f65677261,0x6c61767265746e49\n"
".quad 0x536a6a5f53665073,0x675f666a505f535f,0x0a3b5d7466656c5f,0x3436752e64646109\n"
".quad 0x2c35326472250920,0x202c333264722520,0x090a3b3432647225,0x61626f6c672e7473\n"
".quad 0x5b09203233662e6c,0x5d302b3532647225,0x0a3b30346625202c,0x33325f315f744c24\n"
".quad 0x6c2e090a3a343535,0x373109383109636f,0x697865090a300932,0x6557444c240a3b74\n"
".quad 0x6230335a5f5f646e,0x72654b7463657369,0x656772614c6c656e,0x65746e49656e4f5f\n"
".quad 0x536650736c617672,0x505f535f536a6a5f,0x2f207d090a3a666a,0x696230335a5f202f\n"
".quad 0x6e72654b74636573,0x5f656772614c6c65,0x7265746e49656e4f,0x5f536650736c6176\n"
".quad 0x6a505f535f536a6a,0x746e652e090a0a66,0x6231335a5f207972,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53\n"
".quad 0x535f30535f535f53,0x665f30535f535f30,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x31335a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366,0x5f30535f535f535f\n"
".quad 0x5f30535f535f3053,0x090a2c645f675f66,0x206d617261702e09,0x635f5f203436752e\n"
".quad 0x5f6d726170616475,0x6573696231335a5f,0x6c656e72654b7463,0x754d5f656772614c\n"
".quad 0x767265746e49746c,0x6a5f536650736c61,0x535f535f30536a50,0x535f30535f30535f\n"
".quad 0x5f675f665f30535f,0x61702e09090a2c73,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x31335a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65\n"
".quad 0x50736c6176726574,0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053\n"
".quad 0x2e09090a2c6e5f66,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x7463657369623133,0x614c6c656e72654b,0x746c754d5f656772,0x6c61767265746e49\n"
".quad 0x6a506a5f53665073,0x535f535f535f3053,0x535f535f30535f30,0x636f6c625f665f30\n"
".quad 0x2c746c756d5f736b,0x617261702e09090a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x696231335a5f5f6d,0x6e72654b74636573,0x5f656772614c6c65,0x65746e49746c754d\n"
".quad 0x536650736c617672,0x535f30536a506a5f,0x30535f30535f535f,0x5f665f30535f535f\n"
".quad 0x6d5f736b636f6c62,0x2c6d75735f746c75,0x617261702e09090a,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x696231335a5f5f6d,0x6e72654b74636573,0x5f656772614c6c65\n"
".quad 0x65746e49746c754d,0x536650736c617672,0x535f30536a506a5f,0x30535f30535f535f\n"
".quad 0x5f665f30535f535f,0x0a2c7466656c5f67,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696231335a5f5f,0x656e72654b746365,0x4d5f656772614c6c\n"
".quad 0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a,0x5f30535f30535f53\n"
".quad 0x675f665f30535f53,0x0a2c74686769725f,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696231335a5f5f,0x656e72654b746365,0x4d5f656772614c6c\n"
".quad 0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a,0x5f30535f30535f53\n"
".quad 0x675f665f30535f53,0x6f635f7466656c5f,0x2e09090a2c746e75,0x752e206d61726170\n"
".quad 0x6475635f5f203436,0x5a5f5f6d72617061,0x7463657369623133,0x614c6c656e72654b\n"
".quad 0x746c754d5f656772,0x6c61767265746e49,0x6a506a5f53665073,0x535f535f535f3053\n"
".quad 0x535f535f30535f30,0x69725f675f665f30,0x6e756f635f746867,0x61702e09090a2c74\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x31335a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366\n"
".quad 0x5f30535f535f535f,0x5f30535f535f3053,0x626d616c5f675f66,0x702e09090a2c6164\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x335a5f5f6d726170,0x4b74636573696231\n"
".quad 0x72614c6c656e7265,0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650\n"
".quad 0x30535f535f535f30,0x30535f535f30535f,0x736f705f675f665f,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53\n"
".quad 0x535f30535f535f53,0x665f30535f535f30,0x697369636572705f,0x090a7b090a296e6f\n"
".quad 0x31752e206765722e,0x3e333c6872252036,0x206765722e090a3b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e353731,0x3436752e20676572,0x3e36373c64722520,0x206765722e090a3b\n"
".quad 0x3c6625203233662e,0x722e090a3b3e3937,0x203436662e206765,0x3b3e34313c646625\n"
".quad 0x2e206765722e090a,0x3c70252064657270,0x732e090a3b3e3035,0x612e206465726168\n"
".quad 0x2e2034206e67696c,0x6475635f5f203862,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x30343038335f7261,0x5f6e6f6e5f30345f,0x5f735f74736e6f63,0x69746361706d6f63\n"
".quad 0x317473696c5f6e6f,0x3530325b32333530,0x68732e090a3b5d32,0x6c612e2064657261\n"
".quad 0x622e2034206e6769,0x616475635f5f2038,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f33333038335f72,0x635f6e6f6e5f3333,0x725f735f74736e6f,0x3835323174686769\n"
".quad 0x3b5d383430325b34,0x65726168732e090a,0x6e67696c612e2064,0x5f2038622e203420\n"
".quad 0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61,0x5f30345f37333038\n"
".quad 0x736e6f635f6e6f6e,0x686769725f735f74,0x31746e756f635f74,0x3430325b32333634\n"
".quad 0x68732e090a3b5d38,0x6c612e2064657261,0x622e2034206e6769,0x616475635f5f2038\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f32333038335f72,0x635f6e6f6e5f3333\n"
".quad 0x6c5f735f74736e6f,0x3038363631746665,0x0a3b5d383430325b,0x6465726168732e09\n"
".quad 0x206e67696c612e20,0x5f5f2038622e2034,0x635f5f5f61647563,0x61636f6c5f616475\n"
".quad 0x38335f7261765f6c,0x6e5f30345f363330,0x74736e6f635f6e6f,0x5f7466656c5f735f\n"
".quad 0x373831746e756f63,0x5d383430325b3832,0x726168732e090a3b,0x203233752e206465\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f34353038335f,0x6f635f6e6f6e5f30\n"
".quad 0x6c625f635f74736e,0x726174735f6b636f,0x6168732e090a3b74,0x3233752e20646572\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f35353038335f72,0x635f6e6f6e5f3034\n"
".quad 0x625f635f74736e6f,0x646e655f6b636f6c,0x726168732e090a3b,0x203233752e206465\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f36353038335f,0x6f635f6e6f6e5f30\n"
".quad 0x6c625f635f74736e,0x7366666f5f6b636f,0x757074756f5f7465,0x6168732e090a3b74\n"
".quad 0x3233752e20646572,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f37343038335f72\n"
".quad 0x635f6e6f6e5f3034,0x6d756e5f74736e6f,0x736461657268745f,0x3b6576697463615f\n"
".quad 0x65726168732e090a,0x5f203233752e2064,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3934303833,0x6e6f635f6e6f6e5f,0x745f6d756e5f7473,0x635f736461657268\n"
".quad 0x6f69746361706d6f,0x6168732e090a3b6e,0x3233752e20646572,0x5f616475635f5f20\n"
".quad 0x61765f6c61636f6c,0x5f35343038335f72,0x635f6e6f6e5f3034,0x6c6c615f74736e6f\n"
".quad 0x736461657268745f,0x677265766e6f635f,0x68732e090a3b6465,0x33752e2064657261\n"
".quad 0x616475635f5f2032,0x765f6c61636f6c5f,0x31353038335f7261,0x5f6e6f6e5f30345f\n"
".quad 0x6f635f74736e6f63,0x65735f746361706d,0x7568635f646e6f63,0x6f6c2e090a3b6b6e\n"
".quad 0x0938370932330963,0x656257444c240a30,0x31335a5f5f6e6967,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366\n"
".quad 0x5f30535f535f535f,0x5f30535f535f3053,0x2e747663090a3a66,0x203631752e323375\n"
".quad 0x7425202c31722509,0x6d090a3b782e6469,0x09203233752e766f,0x0a3b30202c327225\n"
".quad 0x71652e7074657309,0x702509203233752e,0x202c317225202c31,0x2140090a3b327225\n"
".quad 0x2061726220317025,0x335f325f744c2409,0x2e090a3b38333939,0x3109323309636f6c\n"
".quad 0x6f6d090a30093532,0x2509203631752e76,0x746325202c316872,0x090a3b782e646961\n"
".quad 0x656469772e6c756d,0x722509203631752e,0x2c31687225202c33,0x747663090a3b3420\n"
".quad 0x3233752e3436752e,0x202c316472250920,0x646c090a3b337225,0x752e6d617261702e\n"
".quad 0x3264722509203436,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623133\n"
".quad 0x614c6c656e72654b,0x746c754d5f656772,0x6c61767265746e49,0x6a506a5f53665073\n"
".quad 0x535f535f535f3053,0x535f535f30535f30,0x636f6c625f665f30,0x5d746c756d5f736b\n"
".quad 0x752e646461090a3b,0x3364722509203436,0x202c32647225202c,0x6c090a3b31647225\n"
".quad 0x6c61626f6c672e64,0x722509203233752e,0x336472255b202c34,0x7473090a3b5d302b\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f30345f34353038,0x736e6f635f6e6f6e,0x636f6c625f635f74,0x5d74726174735f6b\n"
".quad 0x090a3b347225202c,0x09323309636f6c2e,0x6c090a3009363231,0x6c61626f6c672e64\n"
".quad 0x722509203233752e,0x336472255b202c35,0x7473090a3b5d342b,0x2e6465726168732e\n"
".quad 0x5f5f5b0920323375,0x636f6c5f61647563,0x335f7261765f6c61,0x5f30345f35353038\n"
".quad 0x736e6f635f6e6f6e,0x636f6c625f635f74,0x202c5d646e655f6b,0x6c2e090a3b357225\n"
".quad 0x323109323309636f,0x2e646c090a300937,0x36752e6d61726170,0x2c34647225092034\n"
".quad 0x616475635f5f5b20,0x335a5f5f6d726170,0x4b74636573696231,0x72614c6c656e7265\n"
".quad 0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650,0x30535f535f535f30\n"
".quad 0x30535f535f30535f,0x6b636f6c625f665f,0x735f746c756d5f73,0x6461090a3b5d6d75\n"
".quad 0x2509203436752e64,0x647225202c356472,0x3b31647225202c34,0x6f6c672e646c090a\n"
".quad 0x203233752e6c6162,0x255b202c36722509,0x0a3b5d302b356472,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f36353038335f72\n"
".quad 0x635f6e6f6e5f3034,0x625f635f74736e6f,0x66666f5f6b636f6c,0x7074756f5f746573\n"
".quad 0x367225202c5d7475,0x09636f6c2e090a3b,0x3009393231093233,0x33752e627573090a\n"
".quad 0x202c377225092032,0x347225202c357225,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x343038335f726176,0x6e6f6e5f30345f37\n"
".quad 0x6e5f74736e6f635f,0x61657268745f6d75,0x76697463615f7364,0x3b377225202c5d65\n"
".quad 0x3309636f6c2e090a,0x0a30093033310932,0x3233752e766f6d09,0x30202c3872250920\n"
".quad 0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x30343038335f7261,0x5f6e6f6e5f30345f,0x5f735f74736e6f63\n"
".quad 0x69746361706d6f63,0x317473696c5f6e6f,0x2c5d302b32333530,0x2e090a3b38722520\n"
".quad 0x3109323309636f6c,0x7573090a30093133,0x2509203233732e62,0x2c377225202c3972\n"
".quad 0x646e61090a3b3120,0x722509203233622e,0x2c377225202c3031,0x6d090a3b39722520\n"
".quad 0x09203233752e766f,0x3b30202c31317225,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x30317225202c3270,0x0a3b31317225202c,0x7262203270254009,0x325f744c24092061\n"
".quad 0x0a3b30353430345f,0x363109636f6c2e09,0x6d090a3009333709,0x09203233732e766f\n"
".quad 0x7225202c32317225,0x2e617262090a3b37,0x444c240920696e75,0x72665f69646e6557\n"
".quad 0x3532325f66707865,0x5f744c240a3b345f,0x3a30353430345f32,0x3109636f6c2e090a\n"
".quad 0x0a30093538320939,0x2e6e722e74766309,0x203233732e323366,0x7225202c31662509\n"
".quad 0x2e766f6d090a3b37,0x3266250920323366,0x090a3b316625202c,0x203233662e736261\n"
".quad 0x6625202c33662509,0x2e766f6d090a3b31,0x3466250920323366,0x303830306630202c\n"
".quad 0x2020203b30303030,0x2e31202f2f092020,0x332d653934353731,0x2e70746573090a38\n"
".quad 0x09203233662e746c,0x336625202c337025,0x090a3b346625202c,0x7262203370252140\n"
".quad 0x325f744c24092061,0x0a3b38313231345f,0x313209636f6c2e09,0x0a30093336333209\n"
".quad 0x3233662e766f6d09,0x30202c3566250920,0x3030303038623466,0x0920202020203b30\n"
".quad 0x3737362e31202f2f,0x090a37302b653237,0x203233662e6c756d,0x6625202c32662509\n"
".quad 0x0a3b356625202c31,0x3233752e766f6d09,0x202c333172250920,0x617262090a3b3432\n"
".quad 0x4c240920696e752e,0x363930345f325f74,0x325f744c240a3b32,0x0a3a38313231345f\n"
".quad 0x313209636f6c2e09,0x0a30093636333209,0x3233752e766f6d09,0x202c333172250920\n"
".quad 0x325f744c240a3b30,0x0a3a32363930345f,0x363109636f6c2e09,0x6d090a3009383709\n"
".quad 0x09203233622e766f,0x6625202c34317225,0x2e726873090a3b32,0x3172250920323373\n"
".quad 0x2c34317225202c35,0x6e61090a3b333220,0x2509203233622e64,0x317225202c363172\n"
".quad 0x0a3b353532202c35,0x3233752e766f6d09,0x202c373172250920,0x2e627573090a3b30\n"
".quad 0x3172250920323375,0x2c36317225202c38,0x090a3b3331722520,0x203233752e627573\n"
".quad 0x25202c3931722509,0x363231202c383172,0x752e766f6d090a3b,0x3032722509203233\n"
".quad 0x090a3b353532202c,0x752e71652e746573,0x09203233752e3233,0x7225202c31327225\n"
".quad 0x30327225202c3631,0x732e67656e090a3b,0x3232722509203233,0x0a3b31327225202c\n"
".quad 0x3233662e766f6d09,0x30202c3666250920,0x3030303030303066,0x0920202020203b30\n"
".quad 0x6573090a30202f2f,0x3233752e71652e74,0x722509203233662e,0x2c336625202c3332\n"
".quad 0x6e090a3b36662520,0x09203233732e6765,0x7225202c34327225,0x2e726f090a3b3332\n"
".quad 0x3272250920323362,0x2c32327225202c35,0x090a3b3432722520,0x203233732e67656e\n"
".quad 0x25202c3632722509,0x6c73090a3b353272,0x732e3233752e7463,0x3732722509203233\n"
".quad 0x202c39317225202c,0x7225202c37317225,0x6c6873090a3b3632,0x722509203233622e\n"
".quad 0x25202c31202c3231,0x444c240a3b373272,0x72665f69646e6557,0x3532325f66707865\n"
".quad 0x6f6c2e090a3a345f,0x3133310932330963,0x732e7473090a3009,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3038335f7261765f,0x6f6e5f30345f3934\n"
".quad 0x5f74736e6f635f6e,0x657268745f6d756e,0x706d6f635f736461,0x2c5d6e6f69746361\n"
".quad 0x090a3b3231722520,0x09323309636f6c2e,0x6d090a3009333331,0x09203233752e766f\n"
".quad 0x3b31202c38327225,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x35343038335f7261,0x5f6e6f6e5f30345f,0x6c615f74736e6f63\n"
".quad 0x6461657268745f6c,0x7265766e6f635f73,0x7225202c5d646567,0x6f6c2e090a3b3832\n"
".quad 0x3433310932330963,0x2e766f6d090a3009,0x3272250920323375,0x73090a3b30202c39\n"
".quad 0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3135303833,0x6e6f635f6e6f6e5f,0x61706d6f635f7473,0x6e6f6365735f7463\n"
".quad 0x5d6b6e7568635f64,0x0a3b39327225202c,0x39335f325f744c24,0x6c2e090a3a383339\n"
".quad 0x333109323309636f,0x726162090a300937,0x300920636e79732e,0x68732e646c090a3b\n"
".quad 0x3233752e64657261,0x202c303372250920,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f37343038335f72,0x635f6e6f6e5f3034,0x6d756e5f74736e6f,0x736461657268745f\n"
".quad 0x5d6576697463615f,0x2e70746573090a3b,0x09203233752e656c,0x337225202c347025\n"
".quad 0x0a3b317225202c30,0x7262203470254009,0x325f744c24092061,0x0a3b34373431345f\n"
".quad 0x323309636f6c2e09,0x090a300932343109,0x203436752e766f6d,0x5f202c3664722509\n"
".quad 0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61,0x5f33335f33333038\n"
".quad 0x736e6f635f6e6f6e,0x686769725f735f74,0x0a3b343835323174,0x3436752e766f6d09\n"
".quad 0x202c376472250920,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3733303833,0x6e6f635f6e6f6e5f,0x6769725f735f7473,0x746e756f635f7468\n"
".quad 0x090a3b3233363431,0x203436752e766f6d,0x5f202c3864722509,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f33335f32333038,0x736e6f635f6e6f6e\n"
".quad 0x7466656c5f735f74,0x090a3b3038363631,0x203436752e766f6d,0x5f202c3964722509\n"
".quad 0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61,0x5f30345f36333038\n"
".quad 0x736e6f635f6e6f6e,0x7466656c5f735f74,0x3831746e756f635f,0x7663090a3b383237\n"
".quad 0x33752e3436752e74,0x3031647225092032,0x090a3b317225202c,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5f5b202c313372,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f30345f34353038,0x736e6f635f6e6f6e,0x636f6c625f635f74,0x5d74726174735f6b\n"
".quad 0x752e646461090a3b,0x3233722509203233,0x202c31337225202c,0x756d090a3b317225\n"
".quad 0x752e656469772e6c,0x3164722509203233,0x202c317225202c31,0x2e6c756d090a3b34\n"
".quad 0x09203233752e6f6c,0x7225202c33337225,0x090a3b34202c3233,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x33337225202c3231,0x61702e646c090a3b,0x203436752e6d6172\n"
".quad 0x202c333164722509,0x70616475635f5f5b,0x31335a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366\n"
".quad 0x5f30535f535f535f,0x5f30535f535f3053,0x7466656c5f675f66,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x31647225202c3431,0x3231647225202c33,0x6c672e646c090a3b\n"
".quad 0x3233662e6c61626f,0x5b202c3766250920,0x5d302b3431647225,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x3131647225202c35,0x0a3b38647225202c,0x726168732e747309\n"
".quad 0x09203233662e6465,0x302b35316472255b,0x0a3b376625202c5d,0x323309636f6c2e09\n"
".quad 0x090a300933343109,0x6d617261702e646c,0x722509203436752e,0x5f5f5b202c363164\n"
".quad 0x6d72617061647563,0x73696231335a5f5f,0x656e72654b746365,0x4d5f656772614c6c\n"
".quad 0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a,0x5f30535f30535f53\n"
".quad 0x675f665f30535f53,0x3b5d74686769725f,0x36752e646461090a,0x3731647225092034\n"
".quad 0x2c3631647225202c,0x0a3b323164722520,0x626f6c672e646c09,0x09203233662e6c61\n"
".quad 0x72255b202c386625,0x0a3b5d302b373164,0x3436752e64646109,0x2c38316472250920\n"
".quad 0x202c313164722520,0x73090a3b36647225,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d302b38316472,0x2e090a3b38662520,0x3109323309636f6c,0x646c090a30093434\n"
".quad 0x752e6d617261702e,0x3164722509203436,0x75635f5f5b202c39,0x5f5f6d7261706164\n"
".quad 0x636573696231335a,0x4c6c656e72654b74,0x6c754d5f65677261,0x61767265746e4974\n"
".quad 0x506a5f536650736c,0x5f535f535f30536a,0x5f535f30535f3053,0x6c5f675f665f3053\n"
".quad 0x6e756f635f746665,0x646461090a3b5d74,0x722509203436752e,0x647225202c303264\n"
".quad 0x31647225202c3931,0x672e646c090a3b32,0x33752e6c61626f6c,0x2c34337225092032\n"
".quad 0x2b30326472255b20,0x646461090a3b5d30,0x722509203436752e,0x647225202c313264\n"
".quad 0x39647225202c3131,0x68732e7473090a3b,0x3233752e64657261,0x31326472255b0920\n"
".quad 0x337225202c5d302b,0x636f6c2e090a3b34,0x0935343109323309,0x61702e646c090a30\n"
".quad 0x203436752e6d6172,0x202c323264722509,0x70616475635f5f5b,0x31335a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574\n"
".quad 0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053,0x686769725f675f66\n"
".quad 0x5d746e756f635f74,0x752e646461090a3b,0x3264722509203436,0x3232647225202c33\n"
".quad 0x3b3231647225202c,0x6f6c672e646c090a,0x203233752e6c6162,0x5b202c3533722509\n"
".quad 0x5d302b3332647225,0x752e646461090a3b,0x3264722509203436,0x3131647225202c34\n"
".quad 0x0a3b37647225202c,0x726168732e747309,0x09203233752e6465,0x302b34326472255b\n"
".quad 0x3b35337225202c5d,0x345f325f744c240a,0x6d090a3a34373431,0x09203436752e766f\n"
".quad 0x5f5f202c36647225,0x635f5f5f61647563,0x61636f6c5f616475,0x38335f7261765f6c\n"
".quad 0x6e5f33335f333330,0x74736e6f635f6e6f,0x74686769725f735f,0x090a3b3438353231\n"
".quad 0x203436752e766f6d,0x5f202c3764722509,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f30345f37333038,0x736e6f635f6e6f6e,0x686769725f735f74\n"
".quad 0x31746e756f635f74,0x6d090a3b32333634,0x09203436752e766f,0x5f5f202c38647225\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f33335f323330\n"
".quad 0x74736e6f635f6e6f,0x317466656c5f735f,0x6d090a3b30383636,0x09203436752e766f\n"
".quad 0x5f5f202c39647225,0x635f5f5f61647563,0x61636f6c5f616475,0x38335f7261765f6c\n"
".quad 0x6e5f30345f363330,0x74736e6f635f6e6f,0x5f7466656c5f735f,0x373831746e756f63\n"
".quad 0x6f6c2e090a3b3832,0x3834310932330963,0x2e726162090a3009,0x3b300920636e7973\n"
".quad 0x33752e766f6d090a,0x2c36337225092032,0x766f6d090a3b3020,0x662509203233662e\n"
".quad 0x3030306630202c39,0x20203b3030303030,0x30202f2f09202020,0x36752e766f6d090a\n"
".quad 0x3532647225092034,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f30343038335f72,0x635f6e6f6e5f3034,0x635f735f74736e6f,0x6f69746361706d6f\n"
".quad 0x30317473696c5f6e,0x744c240a3b323335,0x32363138325f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x090a35353120656e,0x09323309636f6c2e\n"
".quad 0x6c090a3009353531,0x6465726168732e64,0x722509203233732e,0x635f5f5b202c3733\n"
".quad 0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f30345f373430,0x74736e6f635f6e6f\n"
".quad 0x7268745f6d756e5f,0x7463615f73646165,0x73090a3b5d657669,0x752e656c2e707465\n"
".quad 0x2c35702509203233,0x25202c3733722520,0x702540090a3b3172,0x2409206172622035\n"
".quad 0x3533345f325f744c,0x3c2f2f200a3b3232,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138325f325f744c,0x636f6c2e090a3236,0x0936393509363109,0x34326c756d090a30\n"
".quad 0x203233752e6f6c2e,0x25202c3833722509,0x090a3b34202c3172,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x38337225202c3632,0x752e646461090a3b,0x3264722509203436\n"
".quad 0x3632647225202c37,0x0a3b38647225202c,0x726168732e646c09,0x09203233662e6465\n"
".quad 0x255b202c30316625,0x3b5d302b37326472,0x33662e766f6d090a,0x2c31316625092032\n"
".quad 0x090a3b3031662520,0x09363109636f6c2e,0x61090a3009373935,0x09203436752e6464\n"
".quad 0x25202c3832647225,0x7225202c36326472,0x2e646c090a3b3664,0x662e646572616873\n"
".quad 0x3231662509203233,0x38326472255b202c,0x6f6d090a3b5d302b,0x2509203233662e76\n"
".quad 0x316625202c333166,0x636f6c2e090a3b32,0x0938393509363109,0x752e646461090a30\n"
".quad 0x3264722509203436,0x3632647225202c39,0x0a3b39647225202c,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x255b202c39337225,0x3b5d302b39326472,0x33732e766f6d090a\n"
".quad 0x2c30347225092032,0x090a3b3933722520,0x09363109636f6c2e,0x61090a3009393935\n"
".quad 0x09203436752e6464,0x25202c3033647225,0x7225202c36326472,0x2e646c090a3b3764\n"
".quad 0x752e646572616873,0x3134722509203233,0x30336472255b202c,0x6f6d090a3b5d302b\n"
".quad 0x2509203233732e76,0x347225202c323472,0x70746573090a3b31,0x3233662e75656e2e\n"
".quad 0x25202c3670250920,0x316625202c303166,0x70252140090a3b32,0x2409206172622036\n"
".quad 0x3732345f325f744c,0x3c2f2f200a3b3435,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138325f325f744c,0x2e766f6d090a3236,0x3166250920323366,0x3030306630202c34\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x363109636f6c2e09,0x090a300936393509\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c303166,0x0a3b5d302b373264\n"
".quad 0x363109636f6c2e09,0x090a300939393509,0x2e746c2e70746573,0x3770250920323366\n"
".quad 0x202c30316625202c,0x6d090a3b34316625,0x09203233662e766f,0x6630202c35316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x636f6c2e090a3020,0x0937393509363109\n"
".quad 0x68732e646c090a30,0x3233662e64657261,0x202c323166250920,0x302b38326472255b\n"
".quad 0x636f6c2e090a3b5d,0x0939393509363109,0x2e70746573090a30,0x09203233662e746c\n"
".quad 0x316625202c387025,0x3b35316625202c32,0x203870252140090a,0x744c240920617262\n"
".quad 0x36363233345f325f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32363138325f325f,0x3109636f6c2e090a,0x0a30093430360936,0x33732e706c657309\n"
".quad 0x2c33347225092032,0x25202c30202c3120,0x617262090a3b3770,0x4c240920696e752e\n"
".quad 0x313033345f325f74,0x325f744c240a3b30,0x0a3a36363233345f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f,0x3233732e706c6573\n"
".quad 0x202c333472250920,0x7025202c31202c30,0x325f744c240a3b37,0x0a3a30313033345f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f\n"
".quad 0x09363109636f6c2e,0x6c090a3009373935,0x6465726168732e64,0x662509203233662e\n"
".quad 0x6472255b202c3231,0x090a3b5d302b3832,0x09363109636f6c2e,0x6c090a3009363935\n"
".quad 0x6465726168732e64,0x662509203233662e,0x6472255b202c3031,0x090a3b5d302b3732\n"
".quad 0x09363109636f6c2e,0x73090a3009343036,0x09203233662e6275,0x6625202c36316625\n"
".quad 0x30316625202c3231,0x662e766f6d090a3b,0x3731662509203233,0x303066336630202c\n"
".quad 0x2020203b30303030,0x352e30202f2f0920,0x33662e64616d090a,0x2c38316625092032\n"
".quad 0x25202c3631662520,0x316625202c373166,0x2e646461090a3b30,0x3166250920323366\n"
".quad 0x2c30316625202c39,0x090a3b3231662520,0x203233662e766f6d,0x30202c3032662509\n"
".quad 0x3030303030663366,0x2f09202020203b30,0x6d090a352e30202f,0x09203233662e6c75\n"
".quad 0x6625202c31326625,0x30326625202c3931,0x732e67656e090a3b,0x3434722509203233\n"
".quad 0x0a3b33347225202c,0x33662e74636c7309,0x2509203233732e32,0x31326625202c3966\n"
".quad 0x202c38316625202c,0x2e090a3b34347225,0x3609363109636f6c,0x6f6d090a30093530\n"
".quad 0x2509203233752e76,0x0a3b30202c353472,0x726168732e747309,0x09203233752e6465\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f35343038335f72,0x635f6e6f6e5f3034\n"
".quad 0x6c6c615f74736e6f,0x736461657268745f,0x677265766e6f635f,0x347225202c5d6465\n"
".quad 0x2e617262090a3b35,0x744c240920696e75,0x32323533345f325f,0x5f325f744c240a3b\n"
".quad 0x200a3a3435373234,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353531,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x2e090a3236313832,0x3509363109636f6c,0x646c090a30093939,0x2e6465726168732e\n"
".quad 0x3472250920323375,0x336472255b202c31,0x2e090a3b5d302b30,0x3509363109636f6c\n"
".quad 0x646c090a30093839,0x2e6465726168732e,0x3372250920323375,0x326472255b202c39\n"
".quad 0x2e090a3b5d302b39,0x3609363109636f6c,0x7573090a30093530,0x2509203233752e62\n"
".quad 0x347225202c363472,0x3b39337225202c31,0x33752e766f6d090a,0x2c37347225092032\n"
".quad 0x746573090a3b3120,0x3233752e656c2e70,0x25202c3970250920,0x347225202c363472\n"
".quad 0x39702540090a3b37,0x4c24092061726220,0x323533345f325f74,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32\n"
".quad 0x3009303136093631,0x33752e766f6d090a,0x2c38347225092032,0x2e7473090a3b3020\n"
".quad 0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475,0x38335f7261765f6c\n"
".quad 0x6e5f30345f353430,0x74736e6f635f6e6f,0x7268745f6c6c615f,0x6e6f635f73646165\n"
".quad 0x2c5d646567726576,0x240a3b3834722520,0x3533345f325f744c,0x5f744c240a3a3232\n"
".quad 0x3a38393432345f32,0x345f325f744c240a,0x2f200a3a36383931,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535\n"
".quad 0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138,0x363109323309636f\n"
".quad 0x726162090a300931,0x300920636e79732e,0x09636f6c2e090a3b,0x3009353631093233\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x5b202c3934722509,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f35343038335f,0x6f635f6e6f6e5f30,0x5f6c6c615f74736e\n"
".quad 0x5f73646165726874,0x65677265766e6f63,0x766f6d090a3b5d64,0x722509203233752e\n"
".quad 0x090a3b31202c3035,0x2e71652e70746573,0x3170250920323375,0x2c39347225202c30\n"
".quad 0x090a3b3035722520,0x7262203031702540,0x325f744c24092061,0x2f200a3b3835325f\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138\n"
".quad 0x373109323309636f,0x2e646c090a300932,0x752e646572616873,0x3135722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x343038335f726176,0x6e6f6e5f30345f37\n"
".quad 0x6e5f74736e6f635f,0x61657268745f6d75,0x76697463615f7364,0x6f6c2e090a3b5d65\n"
".quad 0x3833320936310963,0x702e646c090a3009,0x3233752e6d617261,0x202c323572250920\n"
".quad 0x70616475635f5f5b,0x31335a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366,0x5f30535f535f535f\n"
".quad 0x5f30535f535f3053,0x6d090a3b5d6e5f66,0x09203233732e766f,0x7225202c33357225\n"
".quad 0x766f6d090a3b3235,0x722509203233752e,0x090a3b30202c3435,0x2e71652e70746573\n"
".quad 0x3170250920323375,0x2c32357225202c31,0x090a3b3435722520,0x7262203131702540\n"
".quad 0x325f744c24092061,0x0a3b32383838355f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a32363138325f,0x6f6c2e34326c756d,0x722509203233752e\n"
".quad 0x2c317225202c3535,0x6f6c2e090a3b3420,0x3237310932330963,0x732e646c090a3009\n"
".quad 0x33752e6465726168,0x2c31357225092032,0x616475635f5f5b20,0x765f6c61636f6c5f\n"
".quad 0x37343038335f7261,0x5f6e6f6e5f30345f,0x756e5f74736e6f63,0x6461657268745f6d\n"
".quad 0x6576697463615f73,0x636f6c2e090a3b5d,0x0938333209363109,0x2e70746573090a30\n"
".quad 0x09203233752e7467,0x7225202c32317025,0x3b317225202c3135,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x7225202c36326472,0x747663090a3b3535,0x3631752e3233752e\n"
".quad 0x202c363572250920,0x3b782e6469746e25,0x33752e766f6d090a,0x2c37357225092032\n"
".quad 0x766f6d090a3b3020,0x722509203233752e,0x090a3b30202c3835,0x203233662e766f6d\n"
".quad 0x30202c3232662509,0x3030303038663366,0x2f09202020203b30,0x5f744c240a31202f\n"
".quad 0x3a36343534345f32,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x6e202c3833322065,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09363109636f6c2e\n"
".quad 0x62090a3009333432,0x20636e79732e7261,0x646461090a3b3009,0x722509203233752e\n"
".quad 0x37357225202c3935,0x090a3b317225202c,0x2e656c2e70746573,0x3170250920323375\n"
".quad 0x2c32357225202c33,0x090a3b3935722520,0x7262203331702540,0x325f744c24092061\n"
".quad 0x0a3b32303834345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c38333220,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a36343534345f,0x09363109636f6c2e,0x6d090a3009383432,0x33752e6f6c2e6c75\n"
".quad 0x2c30367225092032,0x34202c3735722520,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x25202c3133647225,0x646c090a3b303672,0x752e6d617261702e,0x3364722509203436\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x636573696231335a,0x4c6c656e72654b74\n"
".quad 0x6c754d5f65677261,0x61767265746e4974,0x506a5f536650736c,0x5f535f535f30536a\n"
".quad 0x5f535f30535f3053,0x645f675f665f3053,0x2e646461090a3b5d,0x6472250920343675\n"
".quad 0x33647225202c3333,0x3133647225202c32,0x752e646461090a3b,0x3364722509203436\n"
".quad 0x3632647225202c34,0x3b3333647225202c,0x6f6c672e646c090a,0x203233662e6c6162\n"
".quad 0x5b202c3332662509,0x5d302b3433647225,0x752e646461090a3b,0x3364722509203436\n"
".quad 0x3632647225202c35,0x0a3b38647225202c,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b35336472255b,0x3b33326625202c5d,0x3109636f6c2e090a,0x0a30093934320936\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5f5b202c36336472,0x726170616475635f\n"
".quad 0x696231335a5f5f6d,0x6e72654b74636573,0x5f656772614c6c65,0x65746e49746c754d\n"
".quad 0x536650736c617672,0x535f30536a506a5f,0x30535f30535f535f,0x5f665f30535f535f\n"
".quad 0x61090a3b5d735f67,0x09203436752e6464,0x25202c3733647225,0x7225202c36336472\n"
".quad 0x6461090a3b313364,0x2509203436752e64,0x7225202c38336472,0x647225202c363264\n"
".quad 0x2e646c090a3b3733,0x662e6c61626f6c67,0x3432662509203233,0x38336472255b202c\n"
".quad 0x61090a3b5d342d2b,0x09203436752e6464,0x25202c3933647225,0x7225202c36326472\n"
".quad 0x2e7473090a3b3664,0x662e646572616873,0x6472255b09203233,0x25202c5d302b3933\n"
".quad 0x744c240a3b343266,0x32303834345f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c38333220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x36343534345f325f,0x3109636f6c2e090a,0x0a30093235320936\n"
".quad 0x6e79732e72616209,0x40090a3b30092063,0x7262203231702521,0x325f744c24092061\n"
".quad 0x0a3b36323835345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c38333220,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a36343534345f,0x203233752e6e696d,0x25202c3136722509,0x357225202c333572\n"
".quad 0x2e766f6d090a3b36,0x3672250920323375,0x73090a3b30202c32,0x752e71652e707465\n"
".quad 0x3431702509203233,0x202c31367225202c,0x40090a3b32367225,0x6172622034317025\n"
".quad 0x5f325f744c240920,0x200a3b3632383534,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332,0x656c6562616c2064\n"
".quad 0x5f325f744c242064,0x6d090a3634353434,0x09203233732e766f,0x7225202c33367225\n"
".quad 0x766f6d090a3b3136,0x722509203233752e,0x090a3b30202c3436,0x752e6f6c2e6c756d\n"
".quad 0x3536722509203233,0x202c31367225202c,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x343534345f325f74,0x732e766f6d090a36,0x3636722509203233\n"
".quad 0x0a3b33367225202c,0x36345f325f744c24,0x2f2f200a3a383333,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x697473656e202c32,0x687470656420676e\n"
".quad 0x747365202c32203a,0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73\n"
".quad 0x636f6c2e090a6e77,0x0930363209363109,0x752e747663090a30,0x09203233752e3436\n"
".quad 0x25202c3034647225,0x6461090a3b343672,0x2509203436752e64,0x7225202c31346472\n"
".quad 0x647225202c303464,0x732e646c090a3b36,0x33662e6465726168,0x2c35326625092032\n"
".quad 0x2b31346472255b20,0x646461090a3b5d30,0x722509203436752e,0x647225202c323464\n"
".quad 0x38647225202c3034,0x68732e646c090a3b,0x3233662e64657261,0x202c363266250920\n"
".quad 0x302b32346472255b,0x2e627573090a3b5d,0x3266250920323366,0x2c36326625202c37\n"
".quad 0x6d090a3b39662520,0x09203233662e6c75,0x6625202c38326625,0x35326625202c3532\n"
".quad 0x662e766964090a3b,0x203233662e6c6c75,0x25202c3932662509,0x326625202c383266\n"
".quad 0x2e627573090a3b32,0x3266250920323366,0x2c37326625202c32,0x090a3b3932662520\n"
".quad 0x09363109636f6c2e,0x6d090a3009323632,0x09203233662e766f,0x6630202c30336625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e746573090a3020,0x662e3233752e746c\n"
".quad 0x3736722509203233,0x202c32326625202c,0x6e090a3b30336625,0x09203233732e6765\n"
".quad 0x7225202c38367225,0x646461090a3b3736,0x722509203233752e,0x38357225202c3835\n"
".quad 0x0a3b38367225202c,0x3233752e64646109,0x202c343672250920,0x3b34202c34367225\n"
".quad 0x6e2e70746573090a,0x2509203233752e65,0x367225202c353170,0x3b35367225202c34\n"
".quad 0x203531702540090a,0x744c240920617262,0x38333336345f325f,0x5f325f744c240a3b\n"
".quad 0x240a3a3632383534,0x3335345f325f744c,0x3c2f2f200a3a3431,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x38333220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3534345f325f744c,0x636f6c2e090a3634,0x0937363209363109\n"
".quad 0x752e627573090a30,0x3335722509203233,0x202c33357225202c,0x61090a3b36357225\n"
".quad 0x09203233752e6464,0x7225202c37357225,0x37357225202c3635,0x2e70746573090a3b\n"
".quad 0x09203233752e746c,0x7225202c36317025,0x32357225202c3735,0x3631702540090a3b\n"
".quad 0x4c24092061726220,0x343534345f325f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363138325f325f74,0x752e617262090a32,0x5f744c240920696e\n"
".quad 0x3b34333034345f32,0x355f325f744c240a,0x2f200a3a32383838,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535\n"
".quad 0x64656c6562616c20,0x325f325f744c2420,0x756d090a32363138,0x752e6f6c2e34326c\n"
".quad 0x3936722509203233,0x34202c317225202c,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x25202c3632647225,0x7663090a3b393672,0x31752e3233752e74,0x2c36357225092036\n"
".quad 0x782e6469746e2520,0x752e766f6d090a3b,0x3835722509203233,0x744c240a3b30202c\n"
".quad 0x34333034345f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32363138325f325f,0x3309636f6c2e090a,0x0a30093237310932,0x3233732e766f6d09\n"
".quad 0x202c303772250920,0x2e090a3b38357225,0x3109323309636f6c,0x6162090a30093737\n"
".quad 0x0920636e79732e72,0x2e646461090a3b30,0x6472250920343675,0x32647225202c3334\n"
".quad 0x3532647225202c36,0x68732e646c090a3b,0x3233752e64657261,0x202c313772250920\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f37343038335f72,0x635f6e6f6e5f3034\n"
".quad 0x6d756e5f74736e6f,0x736461657268745f,0x5d6576697463615f,0x2e70746573090a3b\n"
".quad 0x09203233752e656c,0x7225202c37317025,0x3b317225202c3137,0x203731702540090a\n"
".quad 0x744c240920617262,0x36323232355f325f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363138325f325f,0x36752e646461090a,0x3434647225092034\n"
".quad 0x2c3632647225202c,0x090a3b3864722520,0x203436752e646461,0x202c353464722509\n"
".quad 0x25202c3632647225,0x6461090a3b366472,0x2509203436752e64,0x7225202c36346472\n"
".quad 0x647225202c363264,0x2e646461090a3b39,0x6472250920343675,0x32647225202c3734\n"
".quad 0x3b37647225202c36,0x33732e766f6d090a,0x2c39337225092032,0x090a3b3034722520\n"
".quad 0x203233662e766f6d,0x25202c3031662509,0x6f6d090a3b313166,0x2509203233732e76\n"
".quad 0x347225202c313472,0x2e766f6d090a3b32,0x3166250920323366,0x3b33316625202c32\n"
".quad 0x6e2e70746573090a,0x09203233662e7565,0x6625202c38317025,0x32316625202c3031\n"
".quad 0x3170252140090a3b,0x2409206172622038,0x3837345f325f744c,0x3c2f2f200a3b3437\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236\n"
".quad 0x0934383109323309,0x2e70746573090a30,0x09203233752e656e,0x7225202c39317025\n"
".quad 0x39337225202c3037,0x662e736261090a3b,0x3133662509203233,0x090a3b396625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x635f5f5b202c3233,0x5f6d726170616475\n"
".quad 0x6573696231335a5f,0x6c656e72654b7463,0x754d5f656772614c,0x767265746e49746c\n"
".quad 0x6a5f536650736c61,0x535f535f30536a50,0x535f30535f30535f,0x72705f665f30535f\n"
".quad 0x5d6e6f6973696365,0x2e706c6573090a3b,0x3772250920323373,0x2c30202c31202c32\n"
".quad 0x090a3b3931702520,0x752e656e2e746573,0x09203233752e3233,0x7225202c33377225\n"
".quad 0x31347225202c3037,0x732e67656e090a3b,0x3437722509203233,0x0a3b33377225202c\n"
".quad 0x3233622e646e6109,0x202c353772250920,0x7225202c32377225,0x766f6d090a3b3437\n"
".quad 0x722509203233752e,0x090a3b30202c3637,0x2e71652e70746573,0x3270250920323373\n"
".quad 0x2c35377225202c30,0x090a3b3637722520,0x7262203032702540,0x325f744c24092061\n"
".quad 0x0a3b36383338345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09363109636f6c2e,0x73090a3009373231,0x6465726168732e74\n"
".quad 0x255b09203233752e,0x2c5d302b36346472,0x090a3b3933722520,0x09363109636f6c2e\n"
".quad 0x73090a3009383231,0x6465726168732e74,0x255b09203233752e,0x2c5d302b37346472\n"
".quad 0x090a3b3037722520,0x203233662e627573,0x25202c3333662509,0x30316625202c3966\n"
".quad 0x662e736261090a3b,0x3433662509203233,0x0a3b33336625202c,0x3436662e74766309\n"
".quad 0x662509203233662e,0x34336625202c3164,0x662e736261090a3b,0x3533662509203233\n"
".quad 0x0a3b30316625202c,0x3233662e78616d09,0x202c363366250920,0x6625202c31336625\n"
".quad 0x6f6c2e090a3b3533,0x3438310932330963,0x702e646c090a3009,0x3233662e6d617261\n"
".quad 0x202c323366250920,0x70616475635f5f5b,0x31335a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366\n"
".quad 0x5f30535f535f535f,0x5f30535f535f3053,0x7369636572705f66,0x2e090a3b5d6e6f69\n"
".quad 0x3109363109636f6c,0x756d090a30093832,0x2509203233662e6c,0x336625202c373366\n"
".quad 0x3b36336625202c32,0x36662e747663090a,0x2509203233662e34,0x336625202c326466\n"
".quad 0x2e766f6d090a3b37,0x6466250920343666,0x3638336430202c33,0x3233393438343435\n"
".quad 0x2f093b3237653264,0x0a37332d6535202f,0x3436662e78616d09,0x202c346466250920\n"
".quad 0x6625202c32646625,0x746573090a3b3364,0x3436662e656c2e70,0x202c313270250920\n"
".quad 0x6625202c31646625,0x252140090a3b3464,0x2061726220313270,0x345f325f744c2409\n"
".quad 0x2f200a3b38393838,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420\n"
".quad 0x6f6d090a32363138,0x2509203233662e76,0x306630202c383366,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x2e70746573090a30,0x09203233662e746c,0x6625202c32327025\n"
".quad 0x38336625202c3031,0x702e766f6d090a3b,0x3770250920646572,0x0a3b32327025202c\n"
".quad 0x6572702e766f6d09,0x2c33327025092064,0x090a3b3432702520,0x203233662e766f6d\n"
".quad 0x30202c3933662509,0x3030303030303066,0x2f09202020203b30,0x746573090a30202f\n"
".quad 0x3233662e746c2e70,0x202c353270250920,0x336625202c396625,0x70252140090a3b39\n"
".quad 0x0920617262203532,0x39345f325f744c24,0x2f2f200a3b303134,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631,0x3633310936310963\n"
".quad 0x706c6573090a3009,0x722509203233732e,0x30202c31202c3737,0x090a3b377025202c\n"
".quad 0x20696e752e617262,0x345f325f744c2409,0x4c240a3b34353139,0x313439345f325f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562,0x363138325f325f74\n"
".quad 0x2e706c6573090a32,0x3772250920323373,0x2c31202c30202c37,0x240a3b3232702520\n"
".quad 0x3139345f325f744c,0x3c2f2f200a3a3435,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138325f325f744c,0x636f6c2e090a3236,0x0939333109363109,0x662e646461090a30\n"
".quad 0x3034662509203233,0x202c30316625202c,0x6f6d090a3b396625,0x2509203233662e76\n"
".quad 0x336630202c313466,0x3b30303030303066,0x202f2f0920202020,0x64616d090a352e30\n"
".quad 0x662509203233662e,0x33336625202c3234,0x202c31346625202c,0x6d090a3b30316625\n"
".quad 0x09203233662e766f,0x6630202c33346625,0x3030303030306633,0x2f2f09202020203b\n"
".quad 0x756d090a352e3020,0x2509203233662e6c,0x346625202c343466,0x3b33346625202c30\n"
".quad 0x33732e67656e090a,0x2c38377225092032,0x090a3b3737722520,0x3233662e74636c73\n"
".quad 0x662509203233732e,0x34346625202c3534,0x202c32346625202c,0x73090a3b38377225\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x2c5d302b34346472,0x090a3b3534662520\n"
".quad 0x09363109636f6c2e,0x73090a3009303431,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d302b35346472,0x090a3b3534662520,0x20696e752e617262,0x345f325f744c2409\n"
".quad 0x4c240a3b32343638,0x393838345f325f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32,0x3009353431093631\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x2b34346472255b09,0x30316625202c5d30\n"
".quad 0x09636f6c2e090a3b,0x3009363431093631,0x6168732e7473090a,0x203233662e646572\n"
".quad 0x2b35346472255b09,0x3b396625202c5d30,0x345f325f744c240a,0x2f200a3a32343638\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138\n"
".quad 0x323309363109636f,0x766f6d090a300934,0x722509203233752e,0x090a3b31202c3937\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x5d342b3334647225,0x0a3b39377225202c\n"
".quad 0x363109636f6c2e09,0x090a300935323309,0x203233752e766f6d,0x31202c3038722509\n"
".quad 0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61\n"
".quad 0x353038335f726176,0x6e6f6e5f30345f31,0x635f74736e6f635f,0x735f746361706d6f\n"
".quad 0x68635f646e6f6365,0x7225202c5d6b6e75,0x766f6d090a3b3038,0x722509203233752e\n"
".quad 0x090a3b31202c3633,0x20696e752e617262,0x355f325f744c2409,0x4c240a3b36323232\n"
".quad 0x383338345f325f74,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363138325f325f74,0x09636f6c2e090a32,0x3009333333093631,0x33752e766f6d090a\n"
".quad 0x2c31387225092032,0x2e7473090a3b3020,0x752e646572616873,0x6472255b09203233\n"
".quad 0x25202c5d342b3334,0x2140090a3b313872,0x6172622039317025,0x5f325f744c240920\n"
".quad 0x200a3b3232393934,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353531,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x2e090a3236313832,0x3109363109636f6c,0x7473090a30093732,0x2e6465726168732e\n"
".quad 0x72255b0920323375,0x202c5d302b363464,0x2e090a3b39337225,0x3109363109636f6c\n"
".quad 0x7473090a30093832,0x2e6465726168732e,0x72255b0920323375,0x202c5d302b373464\n"
".quad 0x73090a3b30377225,0x09203233662e6275,0x6625202c33336625,0x3b30316625202c39\n"
".quad 0x33662e736261090a,0x2c36346625092032,0x090a3b3333662520,0x2e3436662e747663\n"
".quad 0x6466250920323366,0x3b36346625202c35,0x33662e736261090a,0x2c37346625092032\n"
".quad 0x090a3b3031662520,0x203233662e78616d,0x25202c3834662509,0x346625202c313366\n"
".quad 0x636f6c2e090a3b37,0x0934383109323309,0x61702e646c090a30,0x203233662e6d6172\n"
".quad 0x5b202c3233662509,0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53\n"
".quad 0x535f30535f535f53,0x665f30535f535f30,0x697369636572705f,0x6c2e090a3b5d6e6f\n"
".quad 0x323109363109636f,0x6c756d090a300938,0x662509203233662e,0x32336625202c3934\n"
".quad 0x0a3b38346625202c,0x3436662e74766309,0x662509203233662e,0x39346625202c3664\n"
".quad 0x662e766f6d090a3b,0x3764662509203436,0x353638336430202c,0x6432333934383434\n"
".quad 0x2f2f093b32376532,0x090a37332d653520,0x203436662e78616d,0x25202c3864662509\n"
".quad 0x646625202c366466,0x70746573090a3b37,0x203436662e656c2e,0x25202c3632702509\n"
".quad 0x646625202c356466,0x70252140090a3b38,0x0920617262203632,0x30355f325f744c24\n"
".quad 0x2f2f200a3b343334,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24\n"
".quad 0x766f6d090a323631,0x662509203233662e,0x30306630202c3035,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x6c2e70746573090a,0x2509203233662e74,0x316625202c323270\n"
".quad 0x3b30356625202c30,0x72702e766f6d090a,0x2c37702509206465,0x090a3b3232702520\n"
".quad 0x646572702e766f6d,0x202c373270250920,0x6d090a3b34327025,0x09203233662e766f\n"
".quad 0x6630202c31356625,0x3030303030303030,0x2f2f09202020203b,0x70746573090a3020\n"
".quad 0x203233662e746c2e,0x25202c3832702509,0x31356625202c3966,0x3270252140090a3b\n"
".quad 0x2409206172622038,0x3930355f325f744c,0x3c2f2f200a3b3634,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236,0x0936333109363109\n"
".quad 0x2e706c6573090a30,0x3872250920323373,0x2c30202c31202c32,0x62090a3b37702520\n"
".quad 0x0920696e752e6172,0x30355f325f744c24,0x744c240a3b303936,0x36343930355f325f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c35353120656e,0x62616c2064616568,0x744c242064656c65,0x32363138325f325f\n"
".quad 0x732e706c6573090a,0x3238722509203233,0x202c31202c30202c,0x4c240a3b32327025\n"
".quad 0x393630355f325f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363138325f325f74,0x09636f6c2e090a32,0x3009393331093631,0x33662e646461090a\n"
".quad 0x2c32356625092032,0x25202c3031662520,0x766f6d090a3b3966,0x662509203233662e\n"
".quad 0x66336630202c3335,0x203b303030303030,0x30202f2f09202020,0x2e64616d090a352e\n"
".quad 0x3566250920323366,0x2c33336625202c34,0x25202c3335662520,0x6f6d090a3b303166\n"
".quad 0x2509203233662e76,0x336630202c353566,0x3b30303030303066,0x202f2f0920202020\n"
".quad 0x6c756d090a352e30,0x662509203233662e,0x32356625202c3635,0x0a3b35356625202c\n"
".quad 0x3233732e67656e09,0x202c333872250920,0x73090a3b32387225,0x2e3233662e74636c\n"
".quad 0x3566250920323373,0x2c36356625202c37,0x25202c3435662520,0x7473090a3b333872\n"
".quad 0x2e6465726168732e,0x72255b0920323366,0x202c5d302b343464,0x2e090a3b37356625\n"
".quad 0x3109363109636f6c,0x7473090a30093034,0x2e6465726168732e,0x72255b0920323366\n"
".quad 0x202c5d302b353464,0x62090a3b37356625,0x0920696e752e6172,0x31355f325f744c24\n"
".quad 0x744c240a3b323032,0x34333430355f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a,0x0a30093534310936\n"
".quad 0x726168732e747309,0x09203233662e6465,0x302b34346472255b,0x3b30316625202c5d\n"
".quad 0x3109636f6c2e090a,0x0a30093634310936,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b35346472255b,0x0a3b396625202c5d,0x696e752e61726209,0x5f325f744c240920\n"
".quad 0x240a3b3230323135,0x3939345f325f744c,0x3c2f2f200a3a3232,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236,0x0937323109363109\n"
".quad 0x68732e7473090a30,0x3233752e64657261,0x36346472255b0920,0x377225202c5d302b\n"
".quad 0x636f6c2e090a3b30,0x0938323109363109,0x68732e7473090a30,0x3233752e64657261\n"
".quad 0x37346472255b0920,0x347225202c5d302b,0x2e627573090a3b31,0x3566250920323366\n"
".quad 0x2c32316625202c38,0x61090a3b39662520,0x09203233662e7362,0x6625202c39356625\n"
".quad 0x747663090a3b3835,0x3233662e3436662e,0x202c396466250920,0x61090a3b39356625\n"
".quad 0x09203233662e7362,0x6625202c30366625,0x78616d090a3b3231,0x662509203233662e\n"
".quad 0x31336625202c3136,0x0a3b30366625202c,0x323309636f6c2e09,0x090a300934383109\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x635f5f5b202c3233,0x5f6d726170616475\n"
".quad 0x6573696231335a5f,0x6c656e72654b7463,0x754d5f656772614c,0x767265746e49746c\n"
".quad 0x6a5f536650736c61,0x535f535f30536a50,0x535f30535f30535f,0x72705f665f30535f\n"
".quad 0x5d6e6f6973696365,0x09636f6c2e090a3b,0x3009383231093631,0x33662e6c756d090a\n"
".quad 0x2c32366625092032,0x25202c3233662520,0x7663090a3b313666,0x33662e3436662e74\n"
".quad 0x3031646625092032,0x0a3b32366625202c,0x3436662e766f6d09,0x2c31316466250920\n"
".quad 0x3435363833643020,0x3264323339343834,0x202f2f093b323765,0x6d090a37332d6535\n"
".quad 0x09203436662e7861,0x25202c3231646625,0x6625202c30316466,0x6573090a3b313164\n"
".quad 0x36662e656c2e7074,0x2c39327025092034,0x25202c3964662520,0x40090a3b32316466\n"
".quad 0x7262203932702521,0x325f744c24092061,0x0a3b38353431355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f,0x203233662e766f6d\n"
".quad 0x30202c3336662509,0x3030303030303066,0x2f09202020203b30,0x746573090a30202f\n"
".quad 0x3233662e746c2e70,0x202c303370250920,0x366625202c396625,0x2e766f6d090a3b33\n"
".quad 0x7025092064657270,0x30337025202c3133,0x702e766f6d090a3b,0x3370250920646572\n"
".quad 0x3b33337025202c32,0x33662e766f6d090a,0x2c34366625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x73090a30202f2f09,0x662e746c2e707465,0x3433702509203233\n"
".quad 0x202c32316625202c,0x40090a3b34366625,0x7262203433702521,0x325f744c24092061\n"
".quad 0x0a3b30373931355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09363109636f6c2e,0x73090a3009363331,0x203233732e706c65\n"
".quad 0x31202c3438722509,0x337025202c30202c,0x2e617262090a3b31,0x744c240920696e75\n"
".quad 0x34313731355f325f,0x5f325f744c240a3b,0x200a3a3037393135,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353531\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x73090a3236313832,0x203233732e706c65\n"
".quad 0x30202c3438722509,0x337025202c31202c,0x325f744c240a3b30,0x0a3a34313731355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f\n"
".quad 0x09363109636f6c2e,0x61090a3009393331,0x09203233662e6464,0x6625202c35366625\n"
".quad 0x3b396625202c3231,0x33662e766f6d090a,0x2c36366625092032,0x3030306633663020\n"
".quad 0x202020203b303030,0x0a352e30202f2f09,0x3233662e64616d09,0x202c373666250920\n"
".quad 0x6625202c38356625,0x3b396625202c3636,0x33662e766f6d090a,0x2c38366625092032\n"
".quad 0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09,0x3233662e6c756d09\n"
".quad 0x202c393666250920,0x6625202c35366625,0x67656e090a3b3836,0x722509203233732e\n"
".quad 0x34387225202c3538,0x2e74636c73090a3b,0x203233732e323366,0x25202c3037662509\n"
".quad 0x366625202c393666,0x3b35387225202c37,0x6168732e7473090a,0x203233662e646572\n"
".quad 0x2b34346472255b09,0x30376625202c5d30,0x09636f6c2e090a3b,0x3009303431093631\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x2b35346472255b09,0x30376625202c5d30\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b32303231355f32,0x355f325f744c240a\n"
".quad 0x2f200a3a38353431,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420\n"
".quad 0x6c2e090a32363138,0x343109363109636f,0x2e7473090a300935,0x662e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3434,0x6f6c2e090a3b3966,0x3634310936310963\n"
".quad 0x732e7473090a3009,0x33662e6465726168,0x346472255b092032,0x6625202c5d302b35\n"
".quad 0x5f744c240a3b3231,0x3a32303231355f32,0x345f325f744c240a,0x2f200a3a36363639\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138\n"
".quad 0x343309363109636f,0x766f6d090a300931,0x722509203233752e,0x090a3b30202c3633\n"
".quad 0x20696e752e617262,0x355f325f744c2409,0x4c240a3b36323232,0x373837345f325f74\n"
".quad 0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562,0x363138325f325f74\n"
".quad 0x09636f6c2e090a32,0x3009343931093233,0x33752e627573090a,0x2c36387225092032\n"
".quad 0x25202c3134722520,0x6f6d090a3b393372,0x2509203233752e76,0x0a3b31202c373872\n"
".quad 0x656e2e7074657309,0x702509203233752e,0x36387225202c3533,0x0a3b37387225202c\n"
".quad 0x6220353370254009,0x5f744c2409206172,0x3b32383432355f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x363109636f6c2e09\n"
".quad 0x090a300936333509,0x65726168732e7473,0x5b09203233662e64,0x5d302b3434647225\n"
".quad 0x0a3b30316625202c,0x363109636f6c2e09,0x090a300937333509,0x65726168732e7473\n"
".quad 0x5b09203233662e64,0x5d302b3534647225,0x0a3b32316625202c,0x363109636f6c2e09\n"
".quad 0x090a300938333509,0x65726168732e7473,0x5b09203233752e64,0x5d302b3634647225\n"
".quad 0x0a3b39337225202c,0x363109636f6c2e09,0x090a300939333509,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x5d302b3734647225,0x0a3b31347225202c,0x363109636f6c2e09\n"
".quad 0x090a300933343509,0x203233752e766f6d,0x30202c3838722509,0x68732e7473090a3b\n"
".quad 0x3233752e64657261,0x33346472255b0920,0x387225202c5d342b,0x2e766f6d090a3b38\n"
".quad 0x3372250920323375,0x62090a3b30202c36,0x0920696e752e6172,0x32355f325f744c24\n"
".quad 0x744c240a3b363232,0x32383432355f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a,0x0a30093834350936\n"
".quad 0x3233752e72687309,0x202c393872250920,0x3b31202c36387225,0x33752e646461090a\n"
".quad 0x2c30397225092032,0x25202c3938722520,0x6f6d090a3b393372,0x2509203233732e76\n"
".quad 0x397225202c303772,0x636f6c2e090a3b30,0x0931353509363109,0x68732e7473090a30\n"
".quad 0x3233662e64657261,0x34346472255b0920,0x316625202c5d302b,0x636f6c2e090a3b30\n"
".quad 0x0932353509363109,0x68732e7473090a30,0x3233662e64657261,0x35346472255b0920\n"
".quad 0x316625202c5d302b,0x636f6c2e090a3b32,0x0933353509363109,0x68732e7473090a30\n"
".quad 0x3233752e64657261,0x36346472255b0920,0x337225202c5d302b,0x636f6c2e090a3b39\n"
".quad 0x0934353509363109,0x68732e7473090a30,0x3233752e64657261,0x37346472255b0920\n"
".quad 0x397225202c5d302b,0x636f6c2e090a3b30,0x0936353509363109,0x662e766f6d090a30\n"
".quad 0x2c39662509203233,0x090a3b3031662520,0x09363109636f6c2e,0x6d090a3009303635\n"
".quad 0x09203233752e766f,0x3b31202c31397225,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x2b33346472255b09,0x31397225202c5d34,0x09636f6c2e090a3b,0x3009313635093631\n"
".quad 0x33752e766f6d090a,0x2c32397225092032,0x2e7473090a3b3120,0x752e646572616873\n"
".quad 0x635f5f5b09203233,0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f30345f313530\n"
".quad 0x74736e6f635f6e6f,0x746361706d6f635f,0x5f646e6f6365735f,0x202c5d6b6e756863\n"
".quad 0x6d090a3b32397225,0x09203233752e766f,0x3b31202c36337225,0x355f325f744c240a\n"
".quad 0x4c240a3a36323232,0x313637345f325f74,0x325f744c240a3a38,0x0a3a36303137345f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f\n"
".quad 0x09323309636f6c2e,0x62090a3009343032,0x20636e79732e7261,0x2e646c090a3b3009\n"
".quad 0x752e646572616873,0x3339722509203233,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x353038335f726176,0x6e6f6e5f30345f31,0x635f74736e6f635f,0x735f746361706d6f\n"
".quad 0x68635f646e6f6365,0x6d090a3b5d6b6e75,0x09203233752e766f,0x3b31202c34397225\n"
".quad 0x6e2e70746573090a,0x2509203233752e65,0x397225202c363370,0x3b34397225202c33\n"
".quad 0x203633702540090a,0x744c240920617262,0x32323336355f325f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3309636f6c2e090a\n"
".quad 0x0a30093031320932,0x726168732e646c09,0x09203233752e6465,0x5f5b202c35397225\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3934303833,0x6e6f635f6e6f6e5f\n"
".quad 0x745f6d756e5f7473,0x635f736461657268,0x6f69746361706d6f,0x6f6c2e090a3b5d6e\n"
".quad 0x3736330936310963,0x2e726873090a3009,0x3972250920323375,0x2c35397225202c36\n"
".quad 0x766f6d090a3b3120,0x722509203233732e,0x36397225202c3739,0x752e766f6d090a3b\n"
".quad 0x3839722509203233,0x6573090a3b30202c,0x33732e656c2e7074,0x2c37337025092032\n"
".quad 0x25202c3639722520,0x2540090a3b383972,0x2061726220373370,0x355f325f744c2409\n"
".quad 0x2f200a3b34393339,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420\n"
".quad 0x6f6d090a32363138,0x2509203233752e76,0x0a3b31202c393972,0x33355f325f744c24\n"
".quad 0x2f2f200a3a323637,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x363320656e696c20\n"
".quad 0x09636f6c2e090a39,0x3009393633093631,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x2e656c2e70746573,0x3370250920323375,0x2c37397225202c38,0x40090a3b31722520\n"
".quad 0x6172622038337025,0x5f325f744c240920,0x200a3b3831303435,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393633\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3236373335,0x3309363109636f6c\n"
".quad 0x756d090a30093937,0x752e6f6c2e34326c,0x3031722509203233,0x202c317225202c30\n"
".quad 0x2e646461090a3b32,0x3172250920323375,0x30317225202c3130,0x61090a3b31202c30\n"
".quad 0x09203233752e6464,0x25202c3230317225,0x3b32202c30303172,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x317225202c333031,0x39397225202c3130,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x7225202c34303172,0x397225202c323031,0x2e766f6d090a3b39\n"
".quad 0x3172250920323375,0x090a3b30202c3530,0x2e656e2e70746573,0x3370250920323375\n"
".quad 0x3430317225202c39,0x3b3530317225202c,0x33752e627573090a,0x3630317225092032\n"
".quad 0x2c3430317225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c373031\n"
".quad 0x33752e706c657309,0x3830317225092032,0x2c3630317225202c,0x202c373031722520\n"
".quad 0x6d090a3b39337025,0x33752e6f6c2e6c75,0x3930317225092032,0x2c3830317225202c\n"
".quad 0x747663090a3b3420,0x3233752e3436752e,0x2c38346472250920,0x0a3b393031722520\n"
".quad 0x3436752e64646109,0x2c39346472250920,0x202c383464722520,0x090a3b3532647225\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x255b202c30313172,0x3b5d342b39346472\n"
".quad 0x33752e627573090a,0x3131317225092032,0x2c3330317225202c,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x0a3b30202c323131,0x3233752e766f6d09,0x2c33313172250920\n"
".quad 0x746573090a3b3020,0x3233752e656e2e70,0x202c303470250920,0x25202c3330317225\n"
".quad 0x73090a3b33313172,0x203233752e706c65,0x202c343131722509,0x25202c3131317225\n"
".quad 0x7025202c32313172,0x6c756d090a3b3034,0x203233752e6f6c2e,0x202c353131722509\n"
".quad 0x34202c3431317225,0x752e747663090a3b,0x09203233752e3436,0x25202c3035647225\n"
".quad 0x61090a3b35313172,0x09203436752e6464,0x25202c3135647225,0x7225202c30356472\n"
".quad 0x646c090a3b353264,0x2e6465726168732e,0x3172250920323375,0x6472255b202c3631\n"
".quad 0x090a3b5d342b3135,0x203233752e646461,0x202c373131722509,0x25202c3031317225\n"
".quad 0x73090a3b36313172,0x6465726168732e74,0x255b09203233752e,0x2c5d342b39346472\n"
".quad 0x0a3b373131722520,0x34355f325f744c24,0x2f2f200a3a383130,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363320656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x33355f325f744c24,0x6f6c2e090a323637,0x3338330936310963\n"
".quad 0x2e6c6873090a3009,0x3972250920323362,0x2c39397225202c39,0x6f6c2e090a3b3120\n"
".quad 0x3736330936310963,0x2e726873090a3009,0x3972250920323373,0x2c37397225202c37\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c383131,0x74672e7074657309\n"
".quad 0x702509203233732e,0x37397225202c3134,0x3b3831317225202c,0x203134702540090a\n"
".quad 0x744c240920617262,0x32363733355f325f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363138325f325f,0x6e752e617262090a,0x325f744c24092069\n"
".quad 0x0a3b30353233355f,0x39355f325f744c24,0x2f2f200a3a343933,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x38325f325f744c24,0x766f6d090a323631,0x722509203233752e\n"
".quad 0x240a3b31202c3939,0x3233355f325f744c,0x3c2f2f200a3a3035,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138325f325f744c,0x2e766f6d090a3236,0x3172250920323375\n"
".quad 0x090a3b32202c3931,0x2e656c2e70746573,0x3470250920323375,0x2c35397225202c32\n"
".quad 0x0a3b393131722520,0x6220323470254009,0x5f744c2409206172,0x3b36383734355f32\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3535312065,0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32\n"
".quad 0x3233732e766f6d09,0x2c30323172250920,0x5f744c240a3b3220,0x3a38393235355f32\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3736332065\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09363109636f6c2e,0x73090a3009393833\n"
".quad 0x09203233752e7268,0x7225202c39397225,0x090a3b31202c3939,0x09363109636f6c2e\n"
".quad 0x62090a3009303933,0x20636e79732e7261,0x627573090a3b3009,0x722509203233752e\n"
".quad 0x317225202c313231,0x090a3b31202c3032,0x2e65672e70746573,0x3470250920323375\n"
".quad 0x202c317225202c33,0x090a3b3132317225,0x7262203334702540,0x325f744c24092061\n"
".quad 0x0a3b34353535355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c37363320,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a38393235355f,0x09363109636f6c2e,0x73090a3009373933,0x09203233752e7268\n"
".quad 0x25202c3232317225,0x0a3b31202c393972,0x3233752e64646109,0x2c33323172250920\n"
".quad 0x3b31202c31722520,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c343231\n"
".quad 0x39397225202c3332,0x752e646461090a3b,0x3231722509203233,0x3232317225202c35\n"
".quad 0x3b3432317225202c,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c363231\n"
".quad 0x090a3b34202c3532,0x2e3436752e747663,0x6472250920323375,0x32317225202c3235\n"
".quad 0x2e646461090a3b36,0x6472250920343675,0x35647225202c3335,0x3532647225202c32\n"
".quad 0x68732e646c090a3b,0x3233752e64657261,0x2c37323172250920,0x2b33356472255b20\n"
".quad 0x6c756d090a3b5d30,0x203233752e6f6c2e,0x202c383231722509,0x34202c3432317225\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x25202c3435647225,0x61090a3b38323172\n"
".quad 0x09203436752e6464,0x25202c3535647225,0x7225202c34356472,0x646c090a3b353264\n"
".quad 0x2e6465726168732e,0x3172250920323375,0x6472255b202c3932,0x090a3b5d302b3535\n"
".quad 0x203233752e646461,0x202c303331722509,0x25202c3732317225,0x73090a3b39323172\n"
".quad 0x6465726168732e74,0x255b09203233752e,0x2c5d302b33356472,0x0a3b303331722520\n"
".quad 0x35355f325f744c24,0x2f2f200a3a343535,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363320656e696c20,0x2064616568202c37,0x2064656c6562616c\n"
".quad 0x35355f325f744c24,0x6f6c2e090a383932,0x3738330936310963,0x2e6c6873090a3009\n"
".quad 0x3172250920323362,0x32317225202c3032,0x73090a3b31202c30,0x752e746c2e707465\n"
".quad 0x3434702509203233,0x2c3032317225202c,0x090a3b3539722520,0x7262203434702540\n"
".quad 0x325f744c24092061,0x0a3b38393235355f,0x34355f325f744c24,0x2f2f200a3a363837\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631\n"
".quad 0x3230340936310963,0x2e726162090a3009,0x3b300920636e7973,0x3309636f6c2e090a\n"
".quad 0x0a30093231320932,0x726168732e646c09,0x09203233752e6465,0x5b202c3133317225\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f37343038335f,0x6f635f6e6f6e5f30\n"
".quad 0x5f6d756e5f74736e,0x5f73646165726874,0x3b5d657669746361,0x33752e766f6d090a\n"
".quad 0x3233317225092032,0x6573090a3b31202c,0x3233752e71652e74,0x722509203233752e\n"
".quad 0x337225202c333331,0x3233317225202c36,0x732e67656e090a3b,0x3331722509203233\n"
".quad 0x3333317225202c34,0x672e746573090a3b,0x33752e3233752e74,0x3533317225092032\n"
".quad 0x2c3133317225202c,0x6e090a3b31722520,0x09203233732e6765,0x25202c3633317225\n"
".quad 0x61090a3b35333172,0x09203233622e646e,0x25202c3733317225,0x7225202c34333172\n"
".quad 0x6f6d090a3b363331,0x2509203233752e76,0x3b30202c38333172,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x317225202c353470,0x33317225202c3733,0x34702540090a3b38\n"
".quad 0x2409206172622035,0x3336355f325f744c,0x3c2f2f200a3b3232,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236,0x0932343409363109\n"
".quad 0x68732e646c090a30,0x3233752e64657261,0x2c39333172250920,0x2b33346472255b20\n"
".quad 0x6f6c2e090a3b5d30,0x3231320932330963,0x732e646c090a3009,0x33752e6465726168\n"
".quad 0x3133317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x343038335f726176\n"
".quad 0x6e6f6e5f30345f37,0x6e5f74736e6f635f,0x61657268745f6d75,0x76697463615f7364\n"
".quad 0x6f6c2e090a3b5d65,0x3234340936310963,0x2e646461090a3009,0x3172250920323375\n"
".quad 0x33317225202c3034,0x3133317225202c39,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c31343172,0x0a3b34202c303431,0x3436752e74766309,0x722509203233752e\n"
".quad 0x317225202c363564,0x646461090a3b3134,0x722509203436752e,0x647225202c373564\n"
".quad 0x38647225202c3635,0x68732e7473090a3b,0x3233662e64657261,0x37356472255b0920\n"
".quad 0x396625202c5d302b,0x09636f6c2e090a3b,0x3009333434093631,0x33662e766f6d090a\n"
".quad 0x2c31376625092032,0x090a3b3331662520,0x203436752e646461,0x202c383564722509\n"
".quad 0x25202c3635647225,0x7473090a3b366472,0x2e6465726168732e,0x72255b0920323366\n"
".quad 0x202c5d302b383564,0x2e090a3b31376625,0x3409363109636f6c,0x6461090a30093434\n"
".quad 0x2509203436752e64,0x7225202c39356472,0x647225202c363564,0x732e7473090a3b39\n"
".quad 0x33752e6465726168,0x356472255b092032,0x7225202c5d302b39,0x6f6c2e090a3b3037\n"
".quad 0x3534340936310963,0x2e766f6d090a3009,0x3172250920323373,0x32347225202c3234\n"
".quad 0x752e646461090a3b,0x3664722509203436,0x3635647225202c30,0x0a3b37647225202c\n"
".quad 0x726168732e747309,0x09203233752e6465,0x302b30366472255b,0x3234317225202c5d\n"
".quad 0x5f325f744c240a3b,0x240a3a3232333635,0x3732355f325f744c,0x3c2f2f200a3a3833\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236\n"
".quad 0x0938313209323309,0x732e726162090a30,0x0a3b300920636e79,0x6220317025214009\n"
".quad 0x5f744c2409206172,0x3b34333836355f32,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363138325f32,0x323309636f6c2e09,0x090a300932323209\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5b202c33343172,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3734303833,0x6e6f635f6e6f6e5f,0x745f6d756e5f7473\n"
".quad 0x615f736461657268,0x0a3b5d6576697463,0x3436752e74766309,0x722509203233752e\n"
".quad 0x317225202c313664,0x6c756d090a3b3334,0x33752e656469772e,0x3236647225092032\n"
".quad 0x2c3334317225202c,0x646461090a3b3420,0x722509203436752e,0x647225202c333664\n"
".quad 0x36647225202c3532,0x732e646c090a3b32,0x33752e6465726168,0x3434317225092032\n"
".quad 0x33366472255b202c,0x6461090a3b5d302b,0x2509203233752e64,0x7225202c31333172\n"
".quad 0x317225202c343431,0x2e7473090a3b3334,0x752e646572616873,0x635f5f5b09203233\n"
".quad 0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f30345f373430,0x74736e6f635f6e6f\n"
".quad 0x7268745f6d756e5f,0x7463615f73646165,0x7225202c5d657669,0x6c2e090a3b313331\n"
".quad 0x323209323309636f,0x627573090a300933,0x722509203233732e,0x317225202c353431\n"
".quad 0x090a3b31202c3133,0x203233622e646e61,0x202c363431722509,0x25202c3133317225\n"
".quad 0x6d090a3b35343172,0x09203233752e766f,0x30202c3734317225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c36347025,0x317225202c363431,0x702540090a3b3734\n"
".quad 0x0920617262203634,0x37355f325f744c24,0x2f2f200a3b363433,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631,0x0933370936310963\n"
".quad 0x732e766f6d090a30,0x3431722509203233,0x3133317225202c38,0x752e617262090a3b\n"
".quad 0x57444c240920696e,0x6572665f69646e65,0x5f3532325f667078,0x325f744c240a3b32\n"
".quad 0x0a3a36343337355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09393109636f6c2e,0x63090a3009353832,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x317225202c323766,0x766f6d090a3b3133,0x662509203233662e\n"
".quad 0x3b32376625202c32,0x33662e736261090a,0x2c33376625092032,0x090a3b3237662520\n"
".quad 0x203233662e766f6d,0x30202c3437662509,0x3030303038303066,0x2f09202020203b30\n"
".quad 0x343537312e31202f,0x73090a38332d6539,0x662e746c2e707465,0x3734702509203233\n"
".quad 0x202c33376625202c,0x40090a3b34376625,0x7262203734702521,0x325f744c24092061\n"
".quad 0x0a3b34313138355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09313209636f6c2e,0x090a300933363332,0x203233662e766f6d\n"
".quad 0x30202c3537662509,0x3030303038623466,0x2f09202020203b30,0x373737362e31202f\n"
".quad 0x6d090a37302b6532,0x09203233662e6c75,0x376625202c326625,0x3b35376625202c32\n"
".quad 0x33752e766f6d090a,0x2c33317225092032,0x7262090a3b343220,0x240920696e752e61\n"
".quad 0x3837355f325f744c,0x5f744c240a3b3835,0x3a34313138355f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x313209636f6c2e09\n"
".quad 0x0a30093636333209,0x3233752e766f6d09,0x202c333172250920,0x325f744c240a3b30\n"
".quad 0x0a3a38353837355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09363109636f6c2e,0x6f6d090a30093837,0x2509203233622e76\n"
".quad 0x6625202c39343172,0x2e726873090a3b32,0x3172250920323373,0x34317225202c3035\n"
".quad 0x090a3b3332202c39,0x203233622e646e61,0x202c313531722509,0x32202c3035317225\n"
".quad 0x766f6d090a3b3535,0x722509203233752e,0x0a3b30202c323531,0x3233752e62757309\n"
".quad 0x2c33353172250920,0x202c313531722520,0x73090a3b33317225,0x09203233752e6275\n"
".quad 0x25202c3435317225,0x3231202c33353172,0x2e766f6d090a3b36,0x3172250920323375\n"
".quad 0x3b353532202c3535,0x71652e746573090a,0x3233752e3233752e,0x2c36353172250920\n"
".quad 0x202c313531722520,0x090a3b3535317225,0x203233732e67656e,0x202c373531722509\n"
".quad 0x090a3b3635317225,0x203233662e766f6d,0x30202c3637662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x746573090a30202f,0x2e3233752e71652e,0x3172250920323366\n"
".quad 0x33376625202c3835,0x0a3b36376625202c,0x3233732e67656e09,0x2c39353172250920\n"
".quad 0x0a3b383531722520,0x203233622e726f09,0x202c303631722509,0x25202c3735317225\n"
".quad 0x6e090a3b39353172,0x09203233732e6765,0x25202c3136317225,0x73090a3b30363172\n"
".quad 0x2e3233752e74636c,0x3172250920323373,0x35317225202c3236,0x3235317225202c34\n"
".quad 0x3b3136317225202c,0x33622e6c6873090a,0x3834317225092032,0x317225202c31202c\n"
".quad 0x57444c240a3b3236,0x6572665f69646e65,0x5f3532325f667078,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32\n"
".quad 0x3009333232093233,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x39343038335f7261,0x5f6e6f6e5f30345f,0x756e5f74736e6f63\n"
".quad 0x6461657268745f6d,0x6361706d6f635f73,0x25202c5d6e6f6974,0x2e090a3b38343172\n"
".quad 0x3209323309636f6c,0x6f6d090a30093532,0x2509203233752e76,0x3b30202c33363172\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x31353038335f7261,0x5f6e6f6e5f30345f,0x6f635f74736e6f63,0x65735f746361706d\n"
".quad 0x7568635f646e6f63,0x317225202c5d6b6e,0x6f6c2e090a3b3336,0x3632320932330963\n"
".quad 0x2e766f6d090a3009,0x3172250920323375,0x090a3b31202c3436,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f35343038335f\n"
".quad 0x6f635f6e6f6e5f30,0x5f6c6c615f74736e,0x5f73646165726874,0x65677265766e6f63\n"
".quad 0x36317225202c5d64,0x325f744c240a3b34,0x0a3a34333836355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f,0x09323309636f6c2e\n"
".quad 0x62090a3009393232,0x20636e79732e7261,0x6f6c2e090a3b3009,0x3233320932330963\n"
".quad 0x2e766f6d090a3009,0x3172250920323375,0x090a3b30202c3536,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x5d342b3334647225,0x3b3536317225202c,0x3309636f6c2e090a\n"
".quad 0x0a30093333320932,0x3233752e766f6d09,0x2c36363172250920,0x646461090a3b3020\n"
".quad 0x722509203233752e,0x357225202c373631,0x0a3b317225202c36,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x36317225202c3836,0x63090a3b34202c37,0x752e3436752e7476\n"
".quad 0x3664722509203233,0x3836317225202c34,0x752e646461090a3b,0x3664722509203436\n"
".quad 0x3436647225202c35,0x3b3532647225202c,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x2b35366472255b09,0x36317225202c5d34,0x636f6c2e090a3b36,0x0935333209323309\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x323309636f6c2e09,0x090a300939323209\n"
".quad 0x20696e752e617262,0x325f325f744c2409,0x4c240a3b32363138,0x3a3835325f325f74\n"
".quad 0x3309636f6c2e090a,0x0a30093733320932,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5b202c3936317225,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f37343038335f\n"
".quad 0x6f635f6e6f6e5f30,0x5f6d756e5f74736e,0x5f73646165726874,0x3b5d657669746361\n"
".quad 0x6c2e70746573090a,0x2509203233752e65,0x317225202c383470,0x3b317225202c3936\n"
".quad 0x203834702540090a,0x744c240920617262,0x30373338355f325f,0x09636f6c2e090a3b\n"
".quad 0x3009343432093233,0x36752e747663090a,0x2509203233752e34,0x7225202c36366472\n"
".quad 0x732e646c090a3b31,0x33752e6465726168,0x3037317225092032,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x353038335f726176,0x6e6f6e5f30345f36,0x635f74736e6f635f\n"
".quad 0x6f5f6b636f6c625f,0x756f5f7465736666,0x090a3b5d74757074,0x203233752e646461\n"
".quad 0x202c313731722509,0x25202c3037317225,0x6c756d090a3b3172,0x33752e656469772e\n"
".quad 0x3736647225092032,0x34202c317225202c,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c32373172,0x0a3b34202c313731,0x3436752e74766309,0x722509203233752e\n"
".quad 0x317225202c383664,0x646461090a3b3237,0x722509203436752e,0x647225202c393664\n"
".quad 0x38647225202c3736,0x68732e646c090a3b,0x3233662e64657261,0x202c373766250920\n"
".quad 0x302b39366472255b,0x702e646c090a3b5d,0x3436752e6d617261,0x2c30376472250920\n"
".quad 0x616475635f5f5b20,0x335a5f5f6d726170,0x4b74636573696231,0x72614c6c656e7265\n"
".quad 0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650,0x30535f535f535f30\n"
".quad 0x30535f535f30535f,0x6d616c5f675f665f,0x61090a3b5d616462,0x09203436752e6464\n"
".quad 0x25202c3137647225,0x7225202c30376472,0x7473090a3b383664,0x2e6c61626f6c672e\n"
".quad 0x72255b0920323366,0x202c5d302b313764,0x2e090a3b37376625,0x3209323309636f6c\n"
".quad 0x6461090a30093534,0x2509203436752e64,0x7225202c32376472,0x647225202c373664\n"
".quad 0x732e646c090a3b37,0x33752e6465726168,0x3337317225092032,0x32376472255b202c\n"
".quad 0x646c090a3b5d302b,0x752e6d617261702e,0x3764722509203436,0x75635f5f5b202c33\n"
".quad 0x5f5f6d7261706164,0x636573696231335a,0x4c6c656e72654b74,0x6c754d5f65677261\n"
".quad 0x61767265746e4974,0x506a5f536650736c,0x5f535f535f30536a,0x5f535f30535f3053\n"
".quad 0x705f675f665f3053,0x6461090a3b5d736f,0x2509203436752e64,0x7225202c34376472\n"
".quad 0x647225202c333764,0x2e7473090a3b3836,0x752e6c61626f6c67,0x6472255b09203233\n"
".quad 0x25202c5d302b3437,0x4c240a3b33373172,0x373338355f325f74,0x636f6c2e090a3a30\n"
".quad 0x0937343209323309,0x3b74697865090a30,0x646e6557444c240a,0x73696231335a5f5f\n"
".quad 0x656e72654b746365,0x4d5f656772614c6c,0x7265746e49746c75,0x5f536650736c6176\n"
".quad 0x5f535f30536a506a,0x5f30535f30535f53,0x0a3a665f30535f53,0x5a5f202f2f207d09\n"
".quad 0x7463657369623133,0x614c6c656e72654b,0x746c754d5f656772,0x6c61767265746e49\n"
".quad 0x6a506a5f53665073,0x535f535f535f3053,0x535f535f30535f30,0x0000000a0a665f30\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_13$[11500];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"670552cf2103f524",(char*)"/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_large.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xa5a9be29,&__elfEntries1};
# 3 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c" 2
struct __T20 {float *__par0;float *__par1;unsigned __par2;float __par3;float __par4;unsigned __par5;unsigned __par6;float __par7;unsigned *__par8;unsigned *__par9;float *__par10;float *__par11;unsigned *__par12;float *__par13;float *__par14;unsigned *__par15;unsigned *__par16;unsigned *__par17;unsigned *__par18;int __dummy_field;};
struct __T21 {float *__par0;float *__par1;unsigned __par2;unsigned __par3;float *__par4;float *__par5;unsigned *__par6;float __par7;int __dummy_field;};
struct __T22 {float *__par0;float *__par1;unsigned __par2;unsigned *__par3;unsigned *__par4;float *__par5;float *__par6;unsigned *__par7;unsigned *__par8;float *__par9;unsigned *__par10;float __par11;int __dummy_field;};
extern void __device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *);
extern void __device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float);
extern void __device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float);
static void __sti____cudaRegisterAll_47_tmpxft_00003116_00000000_4_bisect_large_cpp1_ii_155377b5(void) __attribute__((__constructor__));
void __device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_(float *__par0, float *__par1, const unsigned __par2, const float __par3, const float __par4, const unsigned __par5, const unsigned __par6, float __par7, unsigned *__par8, unsigned *__par9, float *__par10, float *__par11, unsigned *__par12, float *__par13, float *__par14, unsigned *__par15, unsigned *__par16, unsigned *__par17, unsigned *__par18){ struct __T20 *__T24 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T24->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T24->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T24->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T24->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T24->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T24->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T24->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T24->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T24->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T24->__par14) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T24->__par15) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T24->__par16) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par17, sizeof(__par17), (size_t)&__T24->__par17) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par18, sizeof(__par18), (size_t)&__T24->__par18) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge))); };}
void bisectKernelLarge( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,const float __cuda_3,const float __cuda_4,const unsigned __cuda_5,const unsigned __cuda_6,float __cuda_7,unsigned *__cuda_8,unsigned *__cuda_9,float *__cuda_10,float *__cuda_11,unsigned *__cuda_12,float *__cuda_13,float *__cuda_14,unsigned *__cuda_15,unsigned *__cuda_16,unsigned *__cuda_17,unsigned *__cuda_18)
# 179 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
{__device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16,__cuda_17,__cuda_18);
# 522 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large.cu"
}
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c"
void __device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf( float *__par0, float *__par1, const unsigned __par2, unsigned __par3, float *__par4, float *__par5, unsigned *__par6, float __par7) { struct __T21 *__T214 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T214->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T214->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T214->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T214->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T214->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T214->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T214->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T214->__par7) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals))); }; }
void bisectKernelLarge_OneIntervals( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,unsigned __cuda_3,float *__cuda_4,float *__cuda_5,unsigned *__cuda_6,float __cuda_7)
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
{__device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 172 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_onei.cu"
}
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c"
void __device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f( float *__par0, float *__par1, const unsigned __par2, unsigned *__par3, unsigned *__par4, float *__par5, float *__par6, unsigned *__par7, unsigned *__par8, float *__par9, unsigned *__par10, float __par11) { struct __T22 *__T215 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T215->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T215->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T215->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T215->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T215->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T215->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T215->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T215->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T215->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T215->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T215->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T215->__par11) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals))); }; }
void bisectKernelLarge_MultIntervals( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,unsigned *__cuda_3,unsigned *__cuda_4,float *__cuda_5,float *__cuda_6,unsigned *__cuda_7,unsigned *__cuda_8,float *__cuda_9,unsigned *__cuda_10,float __cuda_11)
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
{__device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11);
# 247 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/eigenvalues/bisect_kernel_large_multi.cu"
}
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c"
static void __sti____cudaRegisterAll_47_tmpxft_00003116_00000000_4_bisect_large_cpp1_ii_155377b5(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals), (char*)"_Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f", "_Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals), (char*)"_Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf", "_Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge), (char*)"_Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_", "_Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_00003116_00000000-1_bisect_large.cudafe1.stub.c" 2

# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
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
# 49 "sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 50 "sdk/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 85 "sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
# 86 "sdk/cutil_math.h"
{
# 87 "sdk/cutil_math.h"
return a + (t * (b - a));
# 88 "sdk/cutil_math.h"
}
# 91 "sdk/cutil_math.h"
inline float clamp(float f, float a, float b)
# 92 "sdk/cutil_math.h"
{
# 93 "sdk/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 94 "sdk/cutil_math.h"
}
# 100 "sdk/cutil_math.h"
inline int2 operator-(int2 &a)
# 101 "sdk/cutil_math.h"
{
# 102 "sdk/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 103 "sdk/cutil_math.h"
}
# 106 "sdk/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 107 "sdk/cutil_math.h"
{
# 108 "sdk/cutil_math.h"
return make_int2((a.x) + (b.x), (a.y) + (b.y));
# 109 "sdk/cutil_math.h"
}
# 110 "sdk/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 111 "sdk/cutil_math.h"
{
# 112 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 113 "sdk/cutil_math.h"
}
# 116 "sdk/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 117 "sdk/cutil_math.h"
{
# 118 "sdk/cutil_math.h"
return make_int2((a.x) - (b.x), (a.y) - (b.y));
# 119 "sdk/cutil_math.h"
}
# 120 "sdk/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 121 "sdk/cutil_math.h"
{
# 122 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 123 "sdk/cutil_math.h"
}
# 126 "sdk/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 127 "sdk/cutil_math.h"
{
# 128 "sdk/cutil_math.h"
return make_int2((a.x) * (b.x), (a.y) * (b.y));
# 129 "sdk/cutil_math.h"
}
# 130 "sdk/cutil_math.h"
inline int2 operator*(int2 a, int s)
# 131 "sdk/cutil_math.h"
{
# 132 "sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 133 "sdk/cutil_math.h"
}
# 134 "sdk/cutil_math.h"
inline int2 operator*(int s, int2 a)
# 135 "sdk/cutil_math.h"
{
# 136 "sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 137 "sdk/cutil_math.h"
}
# 138 "sdk/cutil_math.h"
inline void operator*=(int2 &a, int s)
# 139 "sdk/cutil_math.h"
{
# 140 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 141 "sdk/cutil_math.h"
}
# 147 "sdk/cutil_math.h"
inline float2 make_float2(float s)
# 148 "sdk/cutil_math.h"
{
# 149 "sdk/cutil_math.h"
return make_float2(s, s);
# 150 "sdk/cutil_math.h"
}
# 151 "sdk/cutil_math.h"
inline float2 make_float2(int2 a)
# 152 "sdk/cutil_math.h"
{
# 153 "sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 154 "sdk/cutil_math.h"
}
# 157 "sdk/cutil_math.h"
inline float2 operator-(float2 &a)
# 158 "sdk/cutil_math.h"
{
# 159 "sdk/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 160 "sdk/cutil_math.h"
}
# 163 "sdk/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 164 "sdk/cutil_math.h"
{
# 165 "sdk/cutil_math.h"
return make_float2((a.x) + (b.x), (a.y) + (b.y));
# 166 "sdk/cutil_math.h"
}
# 167 "sdk/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 168 "sdk/cutil_math.h"
{
# 169 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 170 "sdk/cutil_math.h"
}
# 173 "sdk/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 174 "sdk/cutil_math.h"
{
# 175 "sdk/cutil_math.h"
return make_float2((a.x) - (b.x), (a.y) - (b.y));
# 176 "sdk/cutil_math.h"
}
# 177 "sdk/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 178 "sdk/cutil_math.h"
{
# 179 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 180 "sdk/cutil_math.h"
}
# 183 "sdk/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 184 "sdk/cutil_math.h"
{
# 185 "sdk/cutil_math.h"
return make_float2((a.x) * (b.x), (a.y) * (b.y));
# 186 "sdk/cutil_math.h"
}
# 187 "sdk/cutil_math.h"
inline float2 operator*(float2 a, float s)
# 188 "sdk/cutil_math.h"
{
# 189 "sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 190 "sdk/cutil_math.h"
}
# 191 "sdk/cutil_math.h"
inline float2 operator*(float s, float2 a)
# 192 "sdk/cutil_math.h"
{
# 193 "sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 194 "sdk/cutil_math.h"
}
# 195 "sdk/cutil_math.h"
inline void operator*=(float2 &a, float s)
# 196 "sdk/cutil_math.h"
{
# 197 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 198 "sdk/cutil_math.h"
}
# 201 "sdk/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 202 "sdk/cutil_math.h"
{
# 203 "sdk/cutil_math.h"
return make_float2((a.x) / (b.x), (a.y) / (b.y));
# 204 "sdk/cutil_math.h"
}
# 205 "sdk/cutil_math.h"
inline float2 operator/(float2 a, float s)
# 206 "sdk/cutil_math.h"
{
# 207 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 208 "sdk/cutil_math.h"
return (a * inv);
# 209 "sdk/cutil_math.h"
}
# 210 "sdk/cutil_math.h"
inline float2 operator/(float s, float2 a)
# 211 "sdk/cutil_math.h"
{
# 212 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 213 "sdk/cutil_math.h"
return (a * inv);
# 214 "sdk/cutil_math.h"
}
# 215 "sdk/cutil_math.h"
inline void operator/=(float2 &a, float s)
# 216 "sdk/cutil_math.h"
{
# 217 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 218 "sdk/cutil_math.h"
((a) *= inv);
# 219 "sdk/cutil_math.h"
}
# 222 "sdk/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 223 "sdk/cutil_math.h"
{
# 224 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 225 "sdk/cutil_math.h"
}
# 228 "sdk/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 229 "sdk/cutil_math.h"
{
# 230 "sdk/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 231 "sdk/cutil_math.h"
}
# 233 "sdk/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 234 "sdk/cutil_math.h"
{
# 235 "sdk/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 236 "sdk/cutil_math.h"
}
# 239 "sdk/cutil_math.h"
inline float dot(float2 a, float2 b)
# 240 "sdk/cutil_math.h"
{
# 241 "sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 242 "sdk/cutil_math.h"
}
# 245 "sdk/cutil_math.h"
inline float length(float2 v)
# 246 "sdk/cutil_math.h"
{
# 247 "sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 248 "sdk/cutil_math.h"
}
# 251 "sdk/cutil_math.h"
inline float2 normalize(float2 v)
# 252 "sdk/cutil_math.h"
{
# 253 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 254 "sdk/cutil_math.h"
return (v * invLen);
# 255 "sdk/cutil_math.h"
}
# 258 "sdk/cutil_math.h"
inline float2 floor(const float2 v)
# 259 "sdk/cutil_math.h"
{
# 260 "sdk/cutil_math.h"
return make_float2(floor(v.x), floor(v.y));
# 261 "sdk/cutil_math.h"
}
# 264 "sdk/cutil_math.h"
inline float2 reflect(float2 i, float2 n)
# 265 "sdk/cutil_math.h"
{
# 266 "sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 267 "sdk/cutil_math.h"
}
# 270 "sdk/cutil_math.h"
inline float2 fabs(float2 v)
# 271 "sdk/cutil_math.h"
{
# 272 "sdk/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 273 "sdk/cutil_math.h"
}
# 279 "sdk/cutil_math.h"
inline float3 make_float3(float s)
# 280 "sdk/cutil_math.h"
{
# 281 "sdk/cutil_math.h"
return make_float3(s, s, s);
# 282 "sdk/cutil_math.h"
}
# 283 "sdk/cutil_math.h"
inline float3 make_float3(float2 a)
# 284 "sdk/cutil_math.h"
{
# 285 "sdk/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 286 "sdk/cutil_math.h"
}
# 287 "sdk/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 288 "sdk/cutil_math.h"
{
# 289 "sdk/cutil_math.h"
return make_float3(a.x, a.y, s);
# 290 "sdk/cutil_math.h"
}
# 291 "sdk/cutil_math.h"
inline float3 make_float3(float4 a)
# 292 "sdk/cutil_math.h"
{
# 293 "sdk/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 294 "sdk/cutil_math.h"
}
# 295 "sdk/cutil_math.h"
inline float3 make_float3(int3 a)
# 296 "sdk/cutil_math.h"
{
# 297 "sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 298 "sdk/cutil_math.h"
}
# 301 "sdk/cutil_math.h"
inline float3 operator-(float3 &a)
# 302 "sdk/cutil_math.h"
{
# 303 "sdk/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 304 "sdk/cutil_math.h"
}
# 307 "sdk/cutil_math.h"
static inline float3 fminf(float3 a, float3 b)
# 308 "sdk/cutil_math.h"
{
# 309 "sdk/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 310 "sdk/cutil_math.h"
}
# 313 "sdk/cutil_math.h"
static inline float3 fmaxf(float3 a, float3 b)
# 314 "sdk/cutil_math.h"
{
# 315 "sdk/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 316 "sdk/cutil_math.h"
}
# 319 "sdk/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 320 "sdk/cutil_math.h"
{
# 321 "sdk/cutil_math.h"
return make_float3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 322 "sdk/cutil_math.h"
}
# 323 "sdk/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 324 "sdk/cutil_math.h"
{
# 325 "sdk/cutil_math.h"
return make_float3((a.x) + b, (a.y) + b, (a.z) + b);
# 326 "sdk/cutil_math.h"
}
# 327 "sdk/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 328 "sdk/cutil_math.h"
{
# 329 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 330 "sdk/cutil_math.h"
}
# 333 "sdk/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 334 "sdk/cutil_math.h"
{
# 335 "sdk/cutil_math.h"
return make_float3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 336 "sdk/cutil_math.h"
}
# 337 "sdk/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 338 "sdk/cutil_math.h"
{
# 339 "sdk/cutil_math.h"
return make_float3((a.x) - b, (a.y) - b, (a.z) - b);
# 340 "sdk/cutil_math.h"
}
# 341 "sdk/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 342 "sdk/cutil_math.h"
{
# 343 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 344 "sdk/cutil_math.h"
}
# 347 "sdk/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 348 "sdk/cutil_math.h"
{
# 349 "sdk/cutil_math.h"
return make_float3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 350 "sdk/cutil_math.h"
}
# 351 "sdk/cutil_math.h"
inline float3 operator*(float3 a, float s)
# 352 "sdk/cutil_math.h"
{
# 353 "sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 354 "sdk/cutil_math.h"
}
# 355 "sdk/cutil_math.h"
inline float3 operator*(float s, float3 a)
# 356 "sdk/cutil_math.h"
{
# 357 "sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 358 "sdk/cutil_math.h"
}
# 359 "sdk/cutil_math.h"
inline void operator*=(float3 &a, float s)
# 360 "sdk/cutil_math.h"
{
# 361 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 362 "sdk/cutil_math.h"
}
# 365 "sdk/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 366 "sdk/cutil_math.h"
{
# 367 "sdk/cutil_math.h"
return make_float3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 368 "sdk/cutil_math.h"
}
# 369 "sdk/cutil_math.h"
inline float3 operator/(float3 a, float s)
# 370 "sdk/cutil_math.h"
{
# 371 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 372 "sdk/cutil_math.h"
return (a * inv);
# 373 "sdk/cutil_math.h"
}
# 374 "sdk/cutil_math.h"
inline float3 operator/(float s, float3 a)
# 375 "sdk/cutil_math.h"
{
# 376 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 377 "sdk/cutil_math.h"
return (a * inv);
# 378 "sdk/cutil_math.h"
}
# 379 "sdk/cutil_math.h"
inline void operator/=(float3 &a, float s)
# 380 "sdk/cutil_math.h"
{
# 381 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 382 "sdk/cutil_math.h"
((a) *= inv);
# 383 "sdk/cutil_math.h"
}
# 386 "sdk/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 387 "sdk/cutil_math.h"
{
# 388 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 389 "sdk/cutil_math.h"
}
# 392 "sdk/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 393 "sdk/cutil_math.h"
{
# 394 "sdk/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 395 "sdk/cutil_math.h"
}
# 397 "sdk/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 398 "sdk/cutil_math.h"
{
# 399 "sdk/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 400 "sdk/cutil_math.h"
}
# 403 "sdk/cutil_math.h"
inline float dot(float3 a, float3 b)
# 404 "sdk/cutil_math.h"
{
# 405 "sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 406 "sdk/cutil_math.h"
}
# 409 "sdk/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 410 "sdk/cutil_math.h"
{
# 411 "sdk/cutil_math.h"
return make_float3(((a.y) * (b.z)) - ((a.z) * (b.y)), ((a.z) * (b.x)) - ((a.x) * (b.z)), ((a.x) * (b.y)) - ((a.y) * (b.x)));
# 412 "sdk/cutil_math.h"
}
# 415 "sdk/cutil_math.h"
inline float length(float3 v)
# 416 "sdk/cutil_math.h"
{
# 417 "sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 418 "sdk/cutil_math.h"
}
# 421 "sdk/cutil_math.h"
inline float3 normalize(float3 v)
# 422 "sdk/cutil_math.h"
{
# 423 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 424 "sdk/cutil_math.h"
return (v * invLen);
# 425 "sdk/cutil_math.h"
}
# 428 "sdk/cutil_math.h"
inline float3 floor(const float3 v)
# 429 "sdk/cutil_math.h"
{
# 430 "sdk/cutil_math.h"
return make_float3(floor(v.x), floor(v.y), floor(v.z));
# 431 "sdk/cutil_math.h"
}
# 434 "sdk/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 435 "sdk/cutil_math.h"
{
# 436 "sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 437 "sdk/cutil_math.h"
}
# 440 "sdk/cutil_math.h"
inline float3 fabs(float3 v)
# 441 "sdk/cutil_math.h"
{
# 442 "sdk/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 443 "sdk/cutil_math.h"
}
# 449 "sdk/cutil_math.h"
inline float4 make_float4(float s)
# 450 "sdk/cutil_math.h"
{
# 451 "sdk/cutil_math.h"
return make_float4(s, s, s, s);
# 452 "sdk/cutil_math.h"
}
# 453 "sdk/cutil_math.h"
inline float4 make_float4(float3 a)
# 454 "sdk/cutil_math.h"
{
# 455 "sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 456 "sdk/cutil_math.h"
}
# 457 "sdk/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 458 "sdk/cutil_math.h"
{
# 459 "sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 460 "sdk/cutil_math.h"
}
# 461 "sdk/cutil_math.h"
inline float4 make_float4(int4 a)
# 462 "sdk/cutil_math.h"
{
# 463 "sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 464 "sdk/cutil_math.h"
}
# 467 "sdk/cutil_math.h"
inline float4 operator-(float4 &a)
# 468 "sdk/cutil_math.h"
{
# 469 "sdk/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 470 "sdk/cutil_math.h"
}
# 473 "sdk/cutil_math.h"
static inline float4 fminf(float4 a, float4 b)
# 474 "sdk/cutil_math.h"
{
# 475 "sdk/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 476 "sdk/cutil_math.h"
}
# 479 "sdk/cutil_math.h"
static inline float4 fmaxf(float4 a, float4 b)
# 480 "sdk/cutil_math.h"
{
# 481 "sdk/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 482 "sdk/cutil_math.h"
}
# 485 "sdk/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 486 "sdk/cutil_math.h"
{
# 487 "sdk/cutil_math.h"
return make_float4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 488 "sdk/cutil_math.h"
}
# 489 "sdk/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 490 "sdk/cutil_math.h"
{
# 491 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 492 "sdk/cutil_math.h"
}
# 495 "sdk/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 496 "sdk/cutil_math.h"
{
# 497 "sdk/cutil_math.h"
return make_float4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 498 "sdk/cutil_math.h"
}
# 499 "sdk/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 500 "sdk/cutil_math.h"
{
# 501 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 502 "sdk/cutil_math.h"
}
# 505 "sdk/cutil_math.h"
inline float4 operator*(float4 a, float s)
# 506 "sdk/cutil_math.h"
{
# 507 "sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 508 "sdk/cutil_math.h"
}
# 509 "sdk/cutil_math.h"
inline float4 operator*(float s, float4 a)
# 510 "sdk/cutil_math.h"
{
# 511 "sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 512 "sdk/cutil_math.h"
}
# 513 "sdk/cutil_math.h"
inline void operator*=(float4 &a, float s)
# 514 "sdk/cutil_math.h"
{
# 515 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
# 516 "sdk/cutil_math.h"
}
# 519 "sdk/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 520 "sdk/cutil_math.h"
{
# 521 "sdk/cutil_math.h"
return make_float4((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z), (a.w) / (b.w));
# 522 "sdk/cutil_math.h"
}
# 523 "sdk/cutil_math.h"
inline float4 operator/(float4 a, float s)
# 524 "sdk/cutil_math.h"
{
# 525 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 526 "sdk/cutil_math.h"
return (a * inv);
# 527 "sdk/cutil_math.h"
}
# 528 "sdk/cutil_math.h"
inline float4 operator/(float s, float4 a)
# 529 "sdk/cutil_math.h"
{
# 530 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 531 "sdk/cutil_math.h"
return (a * inv);
# 532 "sdk/cutil_math.h"
}
# 533 "sdk/cutil_math.h"
inline void operator/=(float4 &a, float s)
# 534 "sdk/cutil_math.h"
{
# 535 "sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 536 "sdk/cutil_math.h"
((a) *= inv);
# 537 "sdk/cutil_math.h"
}
# 540 "sdk/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 541 "sdk/cutil_math.h"
{
# 542 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 543 "sdk/cutil_math.h"
}
# 546 "sdk/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 547 "sdk/cutil_math.h"
{
# 548 "sdk/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 549 "sdk/cutil_math.h"
}
# 551 "sdk/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 552 "sdk/cutil_math.h"
{
# 553 "sdk/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 554 "sdk/cutil_math.h"
}
# 557 "sdk/cutil_math.h"
inline float dot(float4 a, float4 b)
# 558 "sdk/cutil_math.h"
{
# 559 "sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 560 "sdk/cutil_math.h"
}
# 563 "sdk/cutil_math.h"
inline float length(float4 r)
# 564 "sdk/cutil_math.h"
{
# 565 "sdk/cutil_math.h"
return sqrtf(dot(r, r));
# 566 "sdk/cutil_math.h"
}
# 569 "sdk/cutil_math.h"
inline float4 normalize(float4 v)
# 570 "sdk/cutil_math.h"
{
# 571 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 572 "sdk/cutil_math.h"
return (v * invLen);
# 573 "sdk/cutil_math.h"
}
# 576 "sdk/cutil_math.h"
inline float4 floor(const float4 v)
# 577 "sdk/cutil_math.h"
{
# 578 "sdk/cutil_math.h"
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
# 579 "sdk/cutil_math.h"
}
# 582 "sdk/cutil_math.h"
inline float4 fabs(float4 v)
# 583 "sdk/cutil_math.h"
{
# 584 "sdk/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 585 "sdk/cutil_math.h"
}
# 591 "sdk/cutil_math.h"
inline int3 make_int3(int s)
# 592 "sdk/cutil_math.h"
{
# 593 "sdk/cutil_math.h"
return make_int3(s, s, s);
# 594 "sdk/cutil_math.h"
}
# 595 "sdk/cutil_math.h"
inline int3 make_int3(float3 a)
# 596 "sdk/cutil_math.h"
{
# 597 "sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 598 "sdk/cutil_math.h"
}
# 601 "sdk/cutil_math.h"
inline int3 operator-(int3 &a)
# 602 "sdk/cutil_math.h"
{
# 603 "sdk/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 604 "sdk/cutil_math.h"
}
# 607 "sdk/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 608 "sdk/cutil_math.h"
{
# 609 "sdk/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 610 "sdk/cutil_math.h"
}
# 613 "sdk/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 614 "sdk/cutil_math.h"
{
# 615 "sdk/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 616 "sdk/cutil_math.h"
}
# 619 "sdk/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 620 "sdk/cutil_math.h"
{
# 621 "sdk/cutil_math.h"
return make_int3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 622 "sdk/cutil_math.h"
}
# 623 "sdk/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 624 "sdk/cutil_math.h"
{
# 625 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 626 "sdk/cutil_math.h"
}
# 629 "sdk/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 630 "sdk/cutil_math.h"
{
# 631 "sdk/cutil_math.h"
return make_int3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 632 "sdk/cutil_math.h"
}
# 634 "sdk/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 635 "sdk/cutil_math.h"
{
# 636 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 637 "sdk/cutil_math.h"
}
# 640 "sdk/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 641 "sdk/cutil_math.h"
{
# 642 "sdk/cutil_math.h"
return make_int3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 643 "sdk/cutil_math.h"
}
# 644 "sdk/cutil_math.h"
inline int3 operator*(int3 a, int s)
# 645 "sdk/cutil_math.h"
{
# 646 "sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 647 "sdk/cutil_math.h"
}
# 648 "sdk/cutil_math.h"
inline int3 operator*(int s, int3 a)
# 649 "sdk/cutil_math.h"
{
# 650 "sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 651 "sdk/cutil_math.h"
}
# 652 "sdk/cutil_math.h"
inline void operator*=(int3 &a, int s)
# 653 "sdk/cutil_math.h"
{
# 654 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 655 "sdk/cutil_math.h"
}
# 658 "sdk/cutil_math.h"
inline int3 operator/(int3 a, int3 b)
# 659 "sdk/cutil_math.h"
{
# 660 "sdk/cutil_math.h"
return make_int3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 661 "sdk/cutil_math.h"
}
# 662 "sdk/cutil_math.h"
inline int3 operator/(int3 a, int s)
# 663 "sdk/cutil_math.h"
{
# 664 "sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 665 "sdk/cutil_math.h"
}
# 666 "sdk/cutil_math.h"
inline int3 operator/(int s, int3 a)
# 667 "sdk/cutil_math.h"
{
# 668 "sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 669 "sdk/cutil_math.h"
}
# 670 "sdk/cutil_math.h"
inline void operator/=(int3 &a, int s)
# 671 "sdk/cutil_math.h"
{
# 672 "sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 673 "sdk/cutil_math.h"
}
# 676 "sdk/cutil_math.h"
inline int clamp(int f, int a, int b)
# 677 "sdk/cutil_math.h"
{
# 678 "sdk/cutil_math.h"
return max(a, min(f, b));
# 679 "sdk/cutil_math.h"
}
# 681 "sdk/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 682 "sdk/cutil_math.h"
{
# 683 "sdk/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 684 "sdk/cutil_math.h"
}
# 686 "sdk/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 687 "sdk/cutil_math.h"
{
# 688 "sdk/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 689 "sdk/cutil_math.h"
}
# 696 "sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
# 697 "sdk/cutil_math.h"
{
# 698 "sdk/cutil_math.h"
return make_uint3(s, s, s);
# 699 "sdk/cutil_math.h"
}
# 700 "sdk/cutil_math.h"
inline uint3 make_uint3(float3 a)
# 701 "sdk/cutil_math.h"
{
# 702 "sdk/cutil_math.h"
return make_uint3((uint)(a.x), (uint)(a.y), (uint)(a.z));
# 703 "sdk/cutil_math.h"
}
# 706 "sdk/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 707 "sdk/cutil_math.h"
{
# 708 "sdk/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 709 "sdk/cutil_math.h"
}
# 712 "sdk/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 713 "sdk/cutil_math.h"
{
# 714 "sdk/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 715 "sdk/cutil_math.h"
}
# 718 "sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 719 "sdk/cutil_math.h"
{
# 720 "sdk/cutil_math.h"
return make_uint3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 721 "sdk/cutil_math.h"
}
# 722 "sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 723 "sdk/cutil_math.h"
{
# 724 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 725 "sdk/cutil_math.h"
}
# 728 "sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 729 "sdk/cutil_math.h"
{
# 730 "sdk/cutil_math.h"
return make_uint3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 731 "sdk/cutil_math.h"
}
# 733 "sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 734 "sdk/cutil_math.h"
{
# 735 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 736 "sdk/cutil_math.h"
}
# 739 "sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 740 "sdk/cutil_math.h"
{
# 741 "sdk/cutil_math.h"
return make_uint3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 742 "sdk/cutil_math.h"
}
# 743 "sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint s)
# 744 "sdk/cutil_math.h"
{
# 745 "sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 746 "sdk/cutil_math.h"
}
# 747 "sdk/cutil_math.h"
inline uint3 operator*(uint s, uint3 a)
# 748 "sdk/cutil_math.h"
{
# 749 "sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 750 "sdk/cutil_math.h"
}
# 751 "sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint s)
# 752 "sdk/cutil_math.h"
{
# 753 "sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 754 "sdk/cutil_math.h"
}
# 757 "sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint3 b)
# 758 "sdk/cutil_math.h"
{
# 759 "sdk/cutil_math.h"
return make_uint3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 760 "sdk/cutil_math.h"
}
# 761 "sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint s)
# 762 "sdk/cutil_math.h"
{
# 763 "sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 764 "sdk/cutil_math.h"
}
# 765 "sdk/cutil_math.h"
inline uint3 operator/(uint s, uint3 a)
# 766 "sdk/cutil_math.h"
{
# 767 "sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 768 "sdk/cutil_math.h"
}
# 769 "sdk/cutil_math.h"
inline void operator/=(uint3 &a, uint s)
# 770 "sdk/cutil_math.h"
{
# 771 "sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 772 "sdk/cutil_math.h"
}
# 775 "sdk/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 776 "sdk/cutil_math.h"
{
# 777 "sdk/cutil_math.h"
return max(a, min(f, b));
# 778 "sdk/cutil_math.h"
}
# 780 "sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 781 "sdk/cutil_math.h"
{
# 782 "sdk/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 783 "sdk/cutil_math.h"
}
# 785 "sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 786 "sdk/cutil_math.h"
{
# 787 "sdk/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 788 "sdk/cutil_math.h"
}
# 44 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
inline float3 firstEigenVector(float matrix[6])
# 45 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
{
# 48 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float3 v = make_float3((1.0F), (1.0F), (1.0F));
# 49 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
for (int i = 0; i < 8; i++) {
# 50 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float x = ((((v.x) * (matrix[0])) + ((v.y) * (matrix[1]))) + ((v.z) * (matrix[2])));
# 51 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float y = ((((v.x) * (matrix[1])) + ((v.y) * (matrix[3]))) + ((v.z) * (matrix[4])));
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float z = ((((v.x) * (matrix[2])) + ((v.y) * (matrix[4]))) + ((v.z) * (matrix[5])));
# 53 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float m = max(max(x, y), z);
# 54 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
float iv = ((1.0F) / m);
# 58 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
v = make_float3(x * iv, y * iv, z * iv);
# 59 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
}
# 61 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
return v;
# 62 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
}
# 64 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
__attribute__((unused)) inline void colorSums(const float3 *colors, float3 *sums)
# 65 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
{int volatile ___ = 1;
# 88 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
exit(___);}
# 91 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
__attribute__((unused)) inline float3 bestFitLine(const float3 *colors, float3 color_sum)
# 92 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
{int volatile ___ = 1;
# 142 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/CudaMath.h"
exit(___);}
# 45 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
extern "C" { typedef unsigned uint; }
# 46 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
extern "C" { typedef unsigned short ushort; }
# 48 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
struct DDSPixelFormat {
# 49 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint size;
# 50 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint flags;
# 51 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint fourcc;
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint bitcount;
# 53 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint rmask;
# 54 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint gmask;
# 55 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint bmask;
# 56 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint amask;
# 57 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
};
# 59 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
struct DDSCaps {
# 60 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint caps1;
# 61 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint caps2;
# 62 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint caps3;
# 63 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint caps4;
# 64 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
};
# 67 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
struct DDSHeader {
# 68 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint fourcc;
# 69 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint size;
# 70 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint flags;
# 71 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint height;
# 72 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint width;
# 73 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint pitch;
# 74 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint depth;
# 75 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint mipmapcount;
# 76 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint reserved[11];
# 77 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
DDSPixelFormat pf;
# 78 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
DDSCaps caps;
# 79 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
uint notused;
# 80 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
};
# 82 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint FOURCC_DDS = (((((unsigned)'D') | (((unsigned)'D') << 8)) | (((unsigned)'S') << 16)) | (((unsigned)' ') << 24));
# 83 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint FOURCC_DXT1 = (((((unsigned)'D') | (((unsigned)'X') << 8)) | (((unsigned)'T') << 16)) | (((unsigned)'1') << 24));
# 84 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_WIDTH = 4U;
# 85 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_HEIGHT = 2U;
# 86 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_CAPS = 1U;
# 87 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_PIXELFORMAT = 4096U;
# 88 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSCAPS_TEXTURE = 4096U;
# 89 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDPF_FOURCC = 4U;
# 90 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_LINEARSIZE = 524288U;
# 42 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
static void computePermutations(uint permutations[1024])
# 43 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 44 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
int indices[16];
# 45 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
int num = 0;
# 50 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int m = 0; m < 16; ++m)
# 51 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 0;
# 53 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 54 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
const int imax = 15;
# 55 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int i = imax; i >= 0; --i)
# 56 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 58 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int m = i; m < 16; ++m)
# 59 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 60 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 2;
# 61 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 62 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 63 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int j = jmax; j >= i; --j)
# 64 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 66 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
if (j < 16)
# 67 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 68 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[j]) = 1;
# 69 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 71 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
uint permutation = (0);
# 73 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int p = 0; p < 16; p++) {
# 74 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 76 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 78 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = permutation;
# 80 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
num++;
# 81 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 82 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 83 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 151, (char *)("/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"), 83);
# 85 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int i = 0; i < 9; i++)
# 86 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 87 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = (697685);
# 88 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
num++;
# 89 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 90 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 160, (char *)("/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"), 90);
# 95 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int m = 0; m < 16; ++m)
# 96 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 97 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 0;
# 98 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 100 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int i = imax; i >= 0; --i)
# 101 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 103 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int m = i; m < 16; ++m)
# 104 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 105 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 2;
# 106 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 107 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 108 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int j = jmax; j >= i; --j)
# 109 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 111 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int m = j; m < 16; ++m)
# 112 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 113 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 3;
# 114 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 116 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
int kmax = ((j == 0) ? 15 : 16);
# 117 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int k = kmax; k >= j; --k)
# 118 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 120 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
if (k < 16)
# 121 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 122 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
((indices)[k]) = 1;
# 123 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 125 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
uint permutation = (0);
# 127 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
bool hasThree = false;
# 128 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int p = 0; p < 16; p++) {
# 129 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 132 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
if (((indices)[p]) == 3) { hasThree = true; }
# 133 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 135 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
if (hasThree) {
# 136 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = permutation;
# 137 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
num++;
# 138 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 139 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 140 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 141 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 142 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 975, (char *)("/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"), 142);
# 147 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
for (int i = 0; i < 49; i++)
# 148 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
{
# 149 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = (11206485);
# 150 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
num++;
# 151 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 153 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 1024, (char *)("/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"), 153);
# 154 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/permutations.h"
}
# 69 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
template< class T> __attribute__((unused)) inline void
# 70 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
swap(T &a, T &b)
# 71 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 75 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 79 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static float3 kColorMetric;
# 85 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void sortColors(const float *values, int *ranks)
# 86 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 130 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 136 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void loadColorBlock(const uint *image, float3 colors[16], float3 sums[16], int xrefs[16])
# 137 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 180 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 187 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) inline float3 roundAndExpand(float3 v, ushort *w)
# 188 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 198 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 201 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static float alphaTable4[4];
# 202 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static float alphaTable3[4];
# 203 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static int prods4[4];
# 204 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static int prods3[4];
# 211 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) static float evalPermutation4(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 212 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 270 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 272 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) static float evalPermutation3(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 273 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 330 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 334 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void evalAllPermutations(const float3 *colors, const uint *permutations, ushort &bestStart, ushort &bestEnd, uint &bestPermutation, float *errors, float3 color_sum)
# 335 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 393 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 399 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) int findMinError(float *errors)
# 400 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 475 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 481 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void saveBlockDXT1(ushort start, ushort end, uint permutation, int xrefs[16], uint2 *result)
# 482 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 503 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 509 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
void compress(const uint *permutations, const uint *image, uint2 *result) ;
# 545 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
union Color32 {
# 546 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
struct {
# 547 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char b, g, r, a;
# 548 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 549 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned u;
# 550 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 552 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
union Color16 {
# 553 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
struct {
# 554 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short b:5;
# 555 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short g:6;
# 556 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short r:5;
# 557 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 558 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short u;
# 559 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 561 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
struct BlockDXT1 {
# 563 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
Color16 col0;
# 564 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
Color16 col1;
# 565 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
union {
# 566 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char row[4];
# 567 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned indices;
# 568 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 570 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
void decompress(Color32 [16]) const;
# 571 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
};
# 573 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
void BlockDXT1::decompress(Color32 *colors) const
# 574 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 575 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
Color32 palette[4];
# 578 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).b) = ((((col0).b) << 3) | (((col0).b) >> 2));
# 579 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).g) = ((((col0).g) << 2) | (((col0).g) >> 4));
# 580 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).r) = ((((col0).r) << 3) | (((col0).r) >> 2));
# 581 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).a) = (255);
# 583 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).r) = ((((col1).r) << 3) | (((col1).r) >> 2));
# 584 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).g) = ((((col1).g) << 2) | (((col1).g) >> 4));
# 585 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).b) = ((((col1).b) << 3) | (((col1).b) >> 2));
# 586 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).a) = (255);
# 588 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (((col0).u) > ((col1).u)) {
# 590 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).r) = (((2 * (((palette)[0]).r)) + (((palette)[1]).r)) / 3);
# 591 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).g) = (((2 * (((palette)[0]).g)) + (((palette)[1]).g)) / 3);
# 592 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).b) = (((2 * (((palette)[0]).b)) + (((palette)[1]).b)) / 3);
# 593 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).a) = (255);
# 595 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).r) = (((2 * (((palette)[1]).r)) + (((palette)[0]).r)) / 3);
# 596 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).g) = (((2 * (((palette)[1]).g)) + (((palette)[0]).g)) / 3);
# 597 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).b) = (((2 * (((palette)[1]).b)) + (((palette)[0]).b)) / 3);
# 598 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).a) = (255);
# 599 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 600 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 602 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).r) = (((((palette)[0]).r) + (((palette)[1]).r)) / 2);
# 603 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).g) = (((((palette)[0]).g) + (((palette)[1]).g)) / 2);
# 604 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).b) = (((((palette)[0]).b) + (((palette)[1]).b)) / 2);
# 605 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).a) = (255);
# 607 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).r) = (0);
# 608 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).g) = (0);
# 609 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).b) = (0);
# 610 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).a) = (0);
# 611 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 613 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++)
# 614 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 615 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(colors[i]) = ((palette)[((indices) >> (2 * i)) & (3)]);
# 616 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 617 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 619 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static int compareColors(const Color32 *b0, const Color32 *b1)
# 620 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 621 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int sum = 0;
# 622 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++)
# 623 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 624 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int r = (((b0[i]).r) - ((b1[i]).r));
# 625 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int g = (((b0[i]).g) - ((b1[i]).g));
# 626 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int b = (((b0[i]).b) - ((b1[i]).b));
# 627 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
sum += (((r * r) + (g * g)) + (b * b));
# 628 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 629 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
return sum;
# 630 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 632 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
static int compareBlock(const BlockDXT1 *b0, const BlockDXT1 *b1)
# 633 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 634 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
Color32 colors0[16];
# 635 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
Color32 colors1[16];
# 637 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
# 638 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 639 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
return 0;
# 640 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 642 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 643 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
b0->decompress(colors0);
# 644 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
b1->decompress(colors1);
# 646 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
return compareColors(colors0, colors1);
# 647 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 648 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 654 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int main(int argc, char **argv)
# 655 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 657 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 658 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cutilDeviceInit(argc, argv); } else {
# 660 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 663 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char *data = (__null);
# 664 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint W, H;
# 666 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
char *image_path = cutFindFilePath("lena_std.ppm", argv[0]);
# 667 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (image_path == (0)) {
# 668 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to find source image\n");
# 669 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 670 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 671 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 673 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (!(cutLoadPPM4ub(image_path, &data, &W, &H))) {
# 674 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open source image\n");
# 675 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 676 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 677 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 679 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint w, h;
# 682 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
w = (W >> 4);
# 683 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
h = (H >> 4);
# 690 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
const uint memSize = ((w * h) * (4));
# 691 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCondition((0) != memSize, (char *)("/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"), 691);
# 693 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *image = ((uint *)malloc(memSize));
# 696 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (uint by = (0); by < (h / (4)); by++) {
# 697 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (uint bx = (0); bx < (w / (4)); bx++) {
# 698 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++) {
# 699 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
const int x = (i & 3);
# 700 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
const int y = (i / 4);
# 701 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(image[((((by * w) / (4)) + bx) * (16)) + i]) = (((uint *)data)[(((((by * (4)) + y) * (4)) * (W / (4))) + (bx * (4))) + x]);
# 703 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 704 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 705 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 708 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_data = (__null);
# 709 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_data), memSize), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 709);
# 712 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_result = (__null);
# 713 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
const uint compressedSize = (((w / (4)) * (h / (4))) * (8));
# 714 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_result), compressedSize), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 714);
# 715 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *result = ((uint *)malloc(compressedSize));
# 718 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint permutations[1024];
# 719 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
computePermutations(permutations);
# 722 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_permutations = (__null);
# 723 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_permutations), (1024) * sizeof(uint)), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 723);
# 724 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_permutations, permutations, (1024) * sizeof(uint), cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 725);
# 728 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint timer;
# 729 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutCreateTimer(&timer), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 729);
# 731 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 731);
# 732 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutStartTimer(timer), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 732);
# 735 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_data, image, memSize, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 735);
# 737 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint blocks = (((w + (3)) / (4)) * ((h + (3)) / (4)));
# 738 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaConfigureCall(blocks, 64) ? ((void)0) : compress(d_permutations, d_data, (uint2 *)d_result);
# 740 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckMsg("compress", "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 740);
# 742 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(result, d_result, compressedSize, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 742);
# 744 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 744);
# 745 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutStopTimer(timer), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 745);
# 747 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
float time = cutGetTimerValue(timer);
# 748 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Time %f msec\n", time);
# 750 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
char output_filename[1024];
# 751 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
strcpy(output_filename, image_path);
# 752 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
strcpy(((output_filename) + strlen(image_path)) - 3, "dds");
# 755 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
FILE *fp = fopen(output_filename, "wb");
# 756 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (fp == (0)) {
# 757 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open output image\n");
# 758 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 759 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 760 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 762 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
DDSHeader header;
# 763 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.fourcc) = FOURCC_DDS;
# 764 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.size) = (124);
# 765 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.flags) = ((((DDSD_WIDTH | DDSD_HEIGHT) | DDSD_CAPS) | DDSD_PIXELFORMAT) | DDSD_LINEARSIZE);
# 766 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.height) = h;
# 767 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.width) = w;
# 768 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.pitch) = compressedSize;
# 769 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.depth) = (0);
# 770 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.mipmapcount) = (0);
# 771 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
memset(header.reserved, 0, sizeof(header.reserved));
# 772 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).size) = (32);
# 773 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).flags) = DDPF_FOURCC;
# 774 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).fourcc) = FOURCC_DXT1;
# 775 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).bitcount) = (0);
# 776 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).rmask) = (0);
# 777 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).gmask) = (0);
# 778 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).bmask) = (0);
# 779 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).amask) = (0);
# 780 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps1) = DDSCAPS_TEXTURE;
# 781 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps2) = (0);
# 782 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps3) = (0);
# 783 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps4) = (0);
# 784 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
(header.notused) = (0);
# 786 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fwrite(&header, sizeof(DDSHeader), 1, fp);
# 787 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fwrite(result, compressedSize, 1, fp);
# 789 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fclose(fp);
# 792 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
const char *reference_image_path = (cutFindFilePath("lena_ref.dds", argv[0]));
# 793 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (reference_image_path == (0)) {
# 794 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to find reference image\n");
# 795 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 796 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 797 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 799 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fp = fopen(reference_image_path, "rb");
# 800 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (fp == (0)) {
# 801 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open reference image\n");
# 802 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 803 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 804 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 806 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fseek(fp, sizeof(DDSHeader), 0);
# 808 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint referenceSize = (((W / (4)) * (H / (4))) * (8));
# 809 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint *reference = ((uint *)malloc(referenceSize));
# 810 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fread(reference, referenceSize, 1, fp);
# 812 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
fclose(fp);
# 814 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
float rms = (0);
# 816 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (uint y = (0); y < h; y += (4))
# 817 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 818 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
for (uint x = (0); x < w; x += (4))
# 819 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 820 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint referenceBlockIdx = (((y / (4)) * (W / (4))) + (x / (4)));
# 821 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
uint resultBlockIdx = (((y / (4)) * (w / (4))) + (x / (4)));
# 823 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
int cmp = compareBlock(((BlockDXT1 *)result) + resultBlockIdx, ((BlockDXT1 *)reference) + referenceBlockIdx);
# 824 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (cmp != (0.0F)) {
# 825 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error at (%d, %d):\t%f rms\n", x / (4), y / (4), (((float)cmp) / (16)) / (3));
# 826 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 827 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
rms += cmp;
# 828 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 829 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 830 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
rms /= ((w * h) * (3));
# 832 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("RMS(reference, result) = %f\n", rms);
# 834 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
if (rms <= (0.1000000015F))
# 835 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 836 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Test PASSED\n");
# 837 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 839 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{
# 840 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
printf("Test FAILED\n");
# 841 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 844 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cutFree(image_path);
# 845 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cutFree(data);
# 846 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
free(image);
# 847 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_permutations), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 847);
# 848 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_data), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 848);
# 849 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_result), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 849);
# 850 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
free(result);
# 852 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutDeleteTimer(timer), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu", 852);
# 854 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 856 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
__cutilExit(argc, argv); return 0;
# 857 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c"
# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_000008a7_00000000-3_dxtc.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000008a7_00000000-3_dxtc.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x00000000000033bc,0x0000000000000040,0x0038004000140115,0x0001000b00400004\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000300\n"
".quad 0x0000000000000101,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000401\n"
".quad 0x0000000000000064,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000465\n"
".quad 0x00000000000001e0,0x0000000d00000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000036,0x0000000000100006,0x0000000000000000,0x0000000000000645\n"
".quad 0x0000000000002c60,0x3200000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000cc,0x0000000000000002,0x0000000000000000,0x00000000000032a5\n"
".quad 0x0000000000000038,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000a4,0x0000000000000002,0x0000000000000000,0x00000000000032dd\n"
".quad 0x0000000000000004,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000055,0x0000000000000002,0x0000000000000000,0x00000000000032e1\n"
".quad 0x000000000000005c,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000080,0x0000000000000003,0x0000000000000000,0x000000000000333d\n"
".quad 0x0000000000000800,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000f3,0x0000000000000002,0x0000000000000000,0x000000000000333d\n"
".quad 0x000000000000004c,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000077,0x0000000000000002,0x0000000000000000,0x0000000000003389\n"
".quad 0x0000000000000030,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x63385a5f2e747865\n"
".quad 0x5073736572706d6f,0x7535505f30536a4b,0x766e2e0032746e69,0x5a5f2e6f666e692e\n"
".quad 0x736572706d6f6338,0x505f30536a4b5073,0x2e0032746e697535,0x006f666e692e766e\n"
".quad 0x726168732e766e2e,0x6f63385a5f2e6465,0x4b5073736572706d,0x697535505f30536a\n"
".quad 0x2e766e2e0032746e,0x746e6174736e6f63,0x6f63385a5f2e3631,0x4b5073736572706d\n"
".quad 0x697535505f30536a,0x2e766e2e0032746e,0x746e6174736e6f63,0x6d6f63385a5f2e30\n"
".quad 0x6a4b507373657270,0x6e697535505f3053,0x632e766e2e003274,0x32746e6174736e6f\n"
".quad 0x6d6f63385a5f0000,0x6a4b507373657270,0x6e697535505f3053,0x6475635f5f003274\n"
".quad 0x725f30326d735f61,0x33665f6e725f7063,0x726f6c6f436b0032,0x700063697274654d\n"
".quad 0x7270003473646f72,0x706c61003373646f,0x34656c6261546168,0x61546168706c6100\n"
".quad 0x0000000033656c62,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000001000300,0x0000000000000000,0x0000000000000000,0x0000000002000300\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000003000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000300,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000300,0x0000000000000000,0x0000000000000000,0x0000000004000300\n"
".quad 0x002c600000000000,0x0000000000000000,0x0000000007000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x000000000a000300,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000008000300,0x0000000000000000,0x0000000000000000,0x0000000006000300\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000005000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000009000300,0x0000000000000000,0x0000010000000000\n"
".quad 0x0000000004101200,0x002a300000000000,0x00001a0000000000,0x002a300004001200\n"
".quad 0x0002300000000000,0x0000310000000000,0x0000000009001100,0x00000c0000000000\n"
".quad 0x00003e0000000000,0x00002c0009001100,0x0000100000000000,0x0000450000000000\n"
".quad 0x00003c0009001100,0x0000100000000000,0x00004c0000000000,0x00000c0009001100\n"
".quad 0x0000100000000000,0x0000580000000000,0x00001c0009001100,0x0000100000000000\n"
".quad 0x005de40000000000,0x051c042800440400,0x41dc232c00000084,0x00a1e7198ec0003d\n"
".quad 0x0081e440000002a0,0x00000428004000a0,0x0000832c00000094,0x0080034000000050\n"
".quad 0xf0c0432005c00010,0x20008548004000b3,0x00c0038400000000,0x0100036000c00040\n"
".quad 0x0080036000c00020,0x30c0036800c003fc,0x4100035800c00060,0x2080045800c00060\n"
".quad 0x20c0041800000009,0x400003180000000d,0x2100045000c00031,0x2080021800000011\n"
".quad 0x30c00230ee020204,0x41000230ee020204,0x00808530ee020204,0x00c085c900000000\n"
".quad 0x010085c900000010,0xffdc04c900000020,0x41dc2350ee0000ff,0x00a1e7198ec0003d\n"
".quad 0x41000340000000e0,0x40c0855000c00031,0x408085c100000000,0x400085c100000010\n"
".quad 0x40c085c100000020,0x408085c900000300,0x400085c900000310,0xffdc04c900000320\n"
".quad 0x41dc2350ee0000ff,0x00a1e7198ec0003d,0x40008340000001e0,0x4200036800c00021\n"
".quad 0x01c0035000c00031,0x80c0855000c00030,0x808085c100000300,0x710085c100000310\n"
".quad 0x718085c100000300,0x800085c100000310,0x714085c100000320,0x40c000c100000320\n"
".quad 0x208000500000000c,0x0000005000000018,0x80c0855000000014,0x808085c900000300\n"
".quad 0x800085c900000310,0xffdc04c900000320,0x41dc2350ee0000ff,0x00a1e7198ec0003d\n"
".quad 0x40008340000001e0,0x4200036800c00011,0x01c0035000c00031,0x80c0855000c00030\n"
".quad 0x808085c100000300,0x710085c100000310,0x718085c100000300,0x800085c100000310\n"
".quad 0x714085c100000320,0x40c000c100000320,0x208000500000000c,0x0000005000000018\n"
".quad 0x80c0855000000014,0x808085c900000300,0x800085c900000310,0xffdc04c900000320\n"
".quad 0x41dc2350ee0000ff,0x00a1e7198ec0003d,0x40008340000001e0,0x4200036800c00009\n"
".quad 0x01c0035000c00031,0x80c0855000c00030,0x808085c100000300,0x710085c100000310\n"
".quad 0x718085c100000300,0x800085c100000310,0x714085c100000320,0x40c000c100000320\n"
".quad 0x208000500000000c,0x0000005000000018,0x80c0855000000014,0x808085c900000300\n"
".quad 0x800085c900000310,0xffdc04c900000320,0x41dc2350ee0000ff,0x00a1e7198ec0003d\n"
".quad 0x40008340000001e0,0x4200036800c00005,0x01c0035000c00031,0x80c0855000c00030\n"
".quad 0x808085c100000300,0x710085c100000310,0x718085c100000300,0x800085c100000310\n"
".quad 0x714085c100000320,0x40c000c100000320,0x208000500000000c,0x0000005000000018\n"
".quad 0x80c0855000000014,0x808085c900000300,0x800085c900000310,0xffdc04c900000320\n"
".quad 0x41dc2350ee0000ff,0x000007198ec0003d,0x0021e760000002e0,0x411c0340000002a0\n"
".quad 0x41dc235000c00031,0xf21cc5198ec0003d,0x40dc85c100000303,0x409c85c100000000\n"
".quad 0x401c85c100000010,0x80dc00c100000020,0x909c003006ef6000,0xa01c003004ef6000\n"
".quad 0x00a1e73000ef6000,0x4100a34000000160,0x3180005000c00019,0x21c000580000000c\n"
".quad 0x020000580000000c,0x410203580000000c,0x2240006000c00008,0x0080005800000008\n"
".quad 0x00c0005800000008,0x4180a55800000000,0x4200a5c900000b00,0x4080a5c900000b20\n"
".quad 0x001df4c900000b40,0xffdc044000000000,0x001de250ee0000ff,0x01dc231800000020\n"
".quad 0x00a1e71a0e000050,0x00c0034000000120,0x4080a34800000050,0x30c0a35000c00019\n"
".quad 0x2102035000c00018,0x3082036000c00008,0x40c0856000c00008,0x208085c100000b00\n"
".quad 0x308000c100000b00,0x4080855000000008,0xffdc04c900000b00,0x00a1e750ee0000ff\n"
".quad 0x00c0034000000120,0x4080a34800000050,0x30c0a35000c00019,0x2102035000c00018\n"
".quad 0x3082036000c00008,0x40c0856000c00008,0x208085c100000b10,0x308000c100000b10\n"
".quad 0x4080855000000008,0xffdc04c900000b10,0x00a1e750ee0000ff,0x00c0034000000120\n"
".quad 0x4080a34800000050,0x30c0a35000c00019,0x2102035000c00018,0x3082036000c00008\n"
".quad 0x40c0856000c00008,0x208085c100000b20,0x308000c100000b20,0x4080855000000008\n"
".quad 0xffdc04c900000b20,0x00a1e750ee0000ff,0x00c0034000000120,0x4080a34800000050\n"
".quad 0x30c0a35000c00019,0x2102035000c00018,0x3082036000c00008,0x40c0856000c00008\n"
".quad 0x208085c100000b30,0x308000c100000b30,0x4080855000000008,0xffdc04c900000b30\n"
".quad 0x00a1e750ee0000ff,0x00c0034000000120,0x4080a34800000050,0x30c0a35000c00019\n"
".quad 0x2102035000c00018,0x3082036000c00008,0x40c0856000c00008,0x208085c100000b40\n"
".quad 0x308000c100000b40,0x4080855000000008,0xffdc04c900000b40,0x00a1e750ee0000ff\n"
".quad 0x00c0034000000120,0x4080a34800000050,0x30c0a35000c00019,0x2102035000c00018\n"
".quad 0x3082036000c00008,0x40c0856000c00008,0x208085c100000b50,0x308000c100000b50\n"
".quad 0x4080855000000008,0xffdc04c900000b50,0x001c2350ee0000ff,0x01dc235800c00004\n"
".quad 0x0001e71a0e0000fc,0xf55c854003fff740,0xf41cc5c100000b33,0xf09ca5c100000b03\n"
".quad 0x101c00c100000b43,0x015c005000000055,0x211c005000000045,0x24dc005000000009\n"
".quad 0x25dc005000000000,0x359c005000000015,0x301c005000000010,0x611c00081e00005d\n"
".quad 0x010007081e000001,0x301c005000008da0,0x715c005800000011,0x019c005800000011\n"
".quad 0x01dc005800000044,0x001c005800000054,0x611c005800000008,0x019c005800000011\n"
".quad 0x51dc00300c000015,0x501c00300e000044,0x259c003000000048,0x45dc00300c000011\n"
".quad 0x44dc00300e000008,0x601c00300000000c,0x311c00081e00005d,0x010007081e000001\n"
".quad 0x719c005000008bc0,0x615c005800000011,0x301c005800000011,0x61dc005800000011\n"
".quad 0x621c005800000044,0x625c005800000054,0x011c005800000008,0x519c00300e000015\n"
".quad 0x515c003010000044,0x24dc003012000048,0x059c003008000001,0x05dc00300c000008\n"
".quad 0x301c00300a00000c,0x011c00081e000059,0x010007081e00005c,0x415c0050000089e0\n"
".quad 0x401c005800000058,0x519c00580000004c,0x51dc005800000044,0x521c005800000054\n"
".quad 0x015c005800000008,0x411c00300c000001,0x019c00580000005c,0x24dc00300e000044\n"
".quad 0x001c00300a000011,0x459c003010000048,0x45dc00300c000008,0x601c00300000000c\n"
".quad 0x711c00081e00004d,0x010007081e000001,0x601c005000008800,0x415c005800000011\n"
".quad 0x019c00580000004c,0x01dc005800000044,0x001c005800000054,0x711c005800000008\n"
".quad 0x019c005800000011,0x51dc00300c000015,0x501c00300e000044,0x259c003000000048\n"
".quad 0x45dc00300c000011,0x44dc00300e000008,0x601c00300000000c,0x011c00081e00005d\n"
".quad 0x010007081e00004c,0x715c005000008620,0x601c005800000011,0x519c005800000011\n"
".quad 0x51dc005800000044,0x521c005800000054,0x015c005800000008,0x411c00300c000001\n"
".quad 0x019c00580000004c,0x24dc00300e000044,0x001c00300a000011,0x459c003010000048\n"
".quad 0x45dc00300c000008,0x301c00300000000c,0x011c00081e000059,0x010007081e00005c\n"
".quad 0x415c005000008440,0x401c005800000058,0x519c00580000004c,0x51dc005800000044\n"
".quad 0x521c005800000054,0x411c005800000008,0x015c00580000005c,0x019c00300c000001\n"
".quad 0x24dc00300e000044,0x001c00300a000011,0x459c003010000048,0x45dc00300c000008\n"
".quad 0x601c00300000000c,0x711c00081e00004d,0x010007081e000001,0x601c005000008260\n"
".quad 0x415c005800000011,0x019c00580000004c,0x01dc005800000044,0x001c005800000054\n"
".quad 0x711c005800000008,0x019c005800000011,0x51dc00300c000015,0x501c00300e000044\n"
".quad 0x241c003000000048,0x445c00300c000011,0x409c00300e000008,0x001c00300000000c\n"
".quad 0x011c00081e000045,0x010007081e000008,0x41dc235000008080,0x001c00198ec0003d\n"
".quad 0x10dc005800000011,0x455e035800000011,0x00a1e76000c00009,0x4200034000000120\n"
".quad 0x4080005000c00031,0x81c0855800000008,0x818085c100000010,0x814085c100000000\n"
".quad 0x70c000c100000020,0x600000580000000c,0x5000003006000000,0x5000853000000008\n"
".quad 0xffdc04c900001101,0x41dc2350ee0000ff,0x000007198ec0003d,0x0021f46000001c80\n"
".quad 0x41dc034000000000,0x0000071a8e0000fd,0x0001e76000001bc0,0xf41cc54000001b80\n"
".quad 0x001de4c100001103,0xf31cc528000000fc,0xf21cc5c100001143,0xf11cc5c100001183\n"
".quad 0x009ca5c1000011c3,0x261c00c100001100,0x265c00120e00001c,0x259c00120e000014\n"
".quad 0x26df84120e000018,0x269c001c00000061,0x265f84120e00002c,0x271c001c00000065\n"
".quad 0x25dc00120e000040,0x275c00120e000010,0x659e03120e00004c,0x261c00480000006d\n"
".quad 0x26df84120e000028,0x27df841c00000069,0x75de031c00000071,0x271f844800000065\n"
".quad 0x265c001c00000075,0x269c00120e000048,0x86de03120e000044,0x275c00480000006d\n"
".quad 0x261c00120e000034,0x965e03120e000024,0xa69e034800000071,0x275f84480000007d\n"
".quad 0x271c001c00000075,0x279c00120e000030,0x27df84120e00003c,0xc71e031c00000061\n"
".quad 0x261c004800000075,0x375c00120e000038,0x209c00120e00001c,0x279f84120e000020\n"
".quad 0x209e031c00000079,0x861e03480000007c,0x27df844800000079,0x379c001c00000075\n"
".quad 0x375c00120e000014,0x279f84120e000018,0xd75e031c00000079,0x809c03480000007d\n"
".quad 0x37dc004800000009,0x361c00120e000010,0xf79e03120e000028,0xc09c034800000079\n"
".quad 0x37dc004800000009,0x371c00120e00002c,0x27df84120e000044,0x909c031c0000007d\n"
".quad 0x861e034800000009,0x365c00480000007d,0x37dc00120e000048,0xa09c03120e000040\n"
".quad 0x27df844800000009,0x369c001c0000007d,0xc71e03120e000030,0xb09c03480000007d\n"
".quad 0x37dc004800000009,0x36dc00120e00004c,0x27df84120e000038,0x709c031c0000007d\n"
".quad 0x965e034800000009,0x609c03480000007d,0x37dc004800000009,0x27df84120e000034\n"
".quad 0xa69e031c0000007d,0x37dc00480000007d,0x27df84120e00003c,0xb6de031c0000007d\n"
".quad 0x37dc00480000007d,0x30dc00120e000024,0x27df84120e000020,0x30de031c0000007d\n"
".quad 0xb0dc03480000007c,0xa0dc03480000000d,0x90dc03480000000d,0xc0dc03480000000d\n"
".quad 0x80dc03480000000d,0xe0dc03480000000d,0xd0dc03480000000d,0x009ca5480000000d\n"
".quad 0x001c03c900000600,0x01dc234800c00020,0x0001e71a8ec00100,0x001de44003fff5a0\n"
".quad 0xf1dc2328000000fc,0x0001e7198e000003,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000603,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000603,0x0001e71b0ec00004,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000613,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000613,0x0001e71b0ec00008,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000623,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000623,0x0001e71b0ec0000c,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000633,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000633,0x0001e71b0ec00010,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000643,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000643,0x0001e71b0ec00014,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000653,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000653,0x0001e71b0ec00018,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000663,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000663,0x0001e71b0ec0001c,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000673,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000673,0x0001e71b0ec00020,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000683,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000683,0x0001e71b0ec00024,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c100000693,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c900000693,0x0001e71b0ec00028,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006a3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c9000006a3,0x0001e71b0ec0002c,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006b3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c9000006b3,0x0001e71b0ec00030,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006c3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c9000006c3,0x0001e71b0ec00034,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006d3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c9000006d3,0x0001e71b0ec00038,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006e3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x01dc23c9000006e3,0x0001e71b0ec0003c,0x00de0340000000c0,0xf09c856000c00008\n"
".quad 0x30dc85c1000006f3,0x31dc23c100000600,0x20a0031a8e000008,0xf0a0854800c00004\n"
".quad 0x001c03c9000006f3,0x01dc234800c00004,0x0001e71a8ec0003c,0x411c134003ffefa0\n"
".quad 0x401c855000c00031,0x409c85c100000000,0x40dc95c100000010,0xffdc04c100000020\n"
".quad 0x41dc2350ee0000ff,0x445e03198ec0003d,0x00a1e76000c00009,0x11008540000000a0\n"
".quad 0x410003c100000601,0x4000855000c00030,0x408085c900000000,0x40c085c900000010\n"
".quad 0xffdc04c900000020,0x00dde450ee0000ff,0x00000728000000fc,0x041de268000027c0\n"
".quad 0x301c0319fdfffffc,0x01dc234800000050,0x0001e71a0ec00f7c,0x011de4a800000000\n"
".quad 0x011c032800400080,0x01dc232009c00010,0xf15c431a0ec0027c,0x0022034800400093\n"
".quad 0x459c856000c00008,0x615c038400000000,0x05a0855800c00009,0x619c03c900001200\n"
".quad 0x611c035800c00011,0x61dc036800c0000d,0x515c035800c00019,0xf6dc856800c0000c\n"
".quad 0x601c03c100000003,0xf35c856800c0000c,0x479e03c100000013,0xf71c856000c00008\n"
".quad 0x539e03c100000023,0x711c036000c00008,0x615c036800c0000c,0xf21c855800c00021\n"
".quad 0x065e03c100000053,0xe5dc866000c00008,0x401e031400080031,0xf3dc856000c00008\n"
".quad 0x515c03c100000033,0xf11c856800c0000c,0x569e03c100000043,0xf25c856000c00008\n"
".quad 0xb6dc00c100000063,0xe19c86307e00005d,0xd35c001400080030,0xf31c85307e00005c\n"
".quad 0xc5dc00c100000073,0xf15c85307e00005d,0x821c00c100000083,0xf29c85302e000018\n"
".quad 0xf3dc00c100000093,0x91dc863036000018,0x435c001400080031,0xf5dc85301a000018\n"
".quad 0x611c03c1000000b3,0x02dc865800c00029,0x619c031400080030,0xf71c855800c00031\n"
".quad 0x93dc00c1000000a3,0xc7dc00301e00001c,0x575c00301a00001c,0xf25c85301000001c\n"
".quad 0x421c03c1000000c3,0xf31c856800c0000c,0x61dc03c1000000d3,0xf15c855800c00039\n"
".quad 0xa3dc00c1000000e3,0xf11c85301e00002c,0x635c03c1000000f3,0x829e036800c0000c\n"
".quad 0x721c036000c00008,0xa61c866800c0000c,0x775c001400080031,0xf19c85303a00002d\n"
".quad 0xc71c00c100000113,0xf6dc85303e00002d,0x82de03c100000103,0xa5dc866000c00008\n"
".quad 0xd35e031400080030,0xf1dc856000c00008,0x93dc00c100000123,0xf21c85301e000060\n"
".quad 0xc71c00c100000133,0xd25c863038000060,0x561c001400080030,0xf31c85303a000060\n"
".quad 0x43dc00c100000143,0x67dc00301e00005c,0xb71c00303000005c,0xf11c85303800005d\n"
".quad 0x619c03c100000153,0xf5dc855800c00041,0x775c00c100000163,0xf61c85301e000024\n"
".quad 0x61dc03c100000173,0xb15c865800c00049,0x619c031400080030,0x871c006800c0000c\n"
".quad 0x71dc033038000024,0xf6dc856800c0000c,0x619e03c100000183,0xf3dc856000c00008\n"
".quad 0xc7dc00c100000193,0xf21c85303e000024,0x731e03c1000001a3,0xf25c856000c00008\n"
".quad 0x475c00c1000001b3,0xe79c86303a000014,0x771c0014000800b1,0x611c863038000015\n"
".quad 0x861c001400080030,0xe39c86303e000015,0xb6dc0014000800b0,0xc15c86303a000011\n"
".quad 0xf3dc001400080030,0x965c863038000010,0x861c0014000800b1,0xe79c033030000010\n"
".quad 0x975c004800000078,0x011c863036000014,0x979c0314000800b0,0xa6dc864800000079\n"
".quad 0x621c0314000800b1,0xf1dc855800c00051,0x479c03c1000001c3,0xf5dc854800000078\n"
".quad 0x601c03c1000001d3,0xa29c865800c00059,0x821c0314000800b0,0xd71c866800c0000c\n"
".quad 0xb79c0314000800b0,0x625c034800000079,0x001c035800c00061,0xb2dc866800c0000c\n"
".quad 0x821e0314000800b0,0xa79c036000c00008,0x73dc004800000078,0x925c03301e000014\n"
".quad 0x61dc036800c0000c,0x619c865800c00069,0xc71c0314000800b0,0x001e034800000079\n"
".quad 0x77dc006000c00008,0x869c863030000015,0x935e031400080030,0xc61c866000c00008\n"
".quad 0xb71c0314000800b0,0x71dc034800000070,0x615c036800c0000c,0x025c865800c00071\n"
".quad 0x671c031400080030,0x821c864800000070,0x731e0314000800b0,0xd5dc866000c00008\n"
".quad 0x515c031400080030,0xd39c866800c0000c,0x861c0314000800b0,0xf6dc854800000071\n"
".quad 0x515e03c1000001e3,0x001c866000c00008,0x861c0314000800b0,0xc35c864800000060\n"
".quad 0x61dc031400080030,0xf2dc855800c00079,0x061c03c100000213,0xf29c854800000060\n"
".quad 0x71dc03c1000001f3,0xf79c856800c0000c,0xe39c03c100000203,0x565c864800000060\n"
".quad 0xb75c001400080030,0xf21c85303a000069,0x71de03c100000243,0xc31c866000c00008\n"
".quad 0xb75c0014000800b0,0xf19c85303a000024,0xc31c03c100000223,0xf71c854800000038\n"
".quad 0xa29c00c100000233,0xf01c85301e000068,0xe79c00c100000253,0x515c86303e000069\n"
".quad 0x875c0014000800b0,0xf61c85303a00005c,0x619c00c100000263,0xf39c853014000024\n"
".quad 0x515c03c100000273,0xf6dc854800000030,0xc71c00c100000283,0x711c86303c000025\n"
".quad 0x079c0014000800b0,0xf3dc85300c00005c,0x47dc03c100000293,0xf69c854800000014\n"
".quad 0xb6dc00c1000002a3,0xf31c85303c000035,0x721c86c1000002b3,0xf2dc851400080030\n"
".quad 0xf29c85c1000002c3,0xf25c85c1000002d3,0xf01c85c1000002e3,0xf11cc5c1000002f3\n"
".quad 0x81dc00c100000303,0xe61c00303800005d,0xf5dc23303a000034,0xf35c005800c00021\n"
".quad 0xa3dc00300e000034,0xf39c233030000065,0xc61c005800c00041,0xb2dc003036000064\n"
".quad 0x731c03301a000064,0xf1dc036800c003fd,0x26de046800c003fd,0xa65c001800000039\n"
".quad 0x961c00301e000020,0x05dc003030000020,0x271e043016000020,0x269e041800000031\n"
".quad 0x475d00180000001d,0x579d003032d04400,0xb01c003030d04400,0x6c5d005800000071\n"
".quad 0xcb9c00302ed04400,0xcbdc005800000065,0xcc1c005800000061,0xa7dc00580000005d\n"
".quad 0xa11e005800000075,0xab1c003000000069,0xab5c005800000079,0x01000758000000c5\n"
".quad 0xb1dc0050000044c0,0xb19c005800000079,0xf15d005800000075,0xe01d0050000000b2\n"
".quad 0xa1de00500000007e,0xa19e00300e000061,0x415c00300c000065,0x401c005800000014\n"
".quad 0x721c005800000000,0x61dc005800000010,0x225c245800000010,0x219c241000000021\n"
".quad 0x221c241000000015,0x215c24100000001d,0xb1dc001000000001,0x92dc0058000000c5\n"
".quad 0x619c005800d09f00,0x001d005800d09f00,0x515c0050000000b7,0xa25e005800d07e00\n"
".quad 0x829c00300e00005d,0x21dc845800d07e00,0x219c841000000019,0x421c001000000015\n"
".quad 0x215c845800000000,0x201c84100000002d,0x92dc001000000029,0x63dc025800000010\n"
".quad 0x211c2430f410d5c4,0x029c021000000021,0x735c0230f410d5c4,0x525c0230f206c464\n"
".quad 0x411c0030f206c464,0x239c245800d07e00,0xa2dc00100000002d,0x931c00580000003c\n"
".quad 0x221c845800000034,0xa31c001000000011,0xe11c005800000031,0xd31e005800d07e00\n"
".quad 0xa39c003018000060,0xd35c00580000002d,0x82dc025800000034,0x211c8430f410d5c4\n"
".quad 0xf39e001000000011,0xb35c00301c000064,0xf65c005800000035,0x461c02580000003c\n"
".quad 0xb3dc0030f410d5c4,0xb65c00580000002c,0xb3dc005800000065,0x21dc04580000003d\n"
".quad 0x86dc00140600001d,0x219c04580000002d,0xa6dc001406000019,0x211c04580000006d\n"
".quad 0x969c001406000011,0xb2de005800000024,0xe25e00303600005c,0xa5dc003018000025\n"
".quad 0xd29e005800000028,0xc31c00301c000029,0x939c00301a000069,0xc35c005000000024\n"
".quad 0x825c00303200005d,0x12de005800000061,0xa29c003016000063,0xc31c005000000028\n"
".quad 0xc25c005000000038,0xb2dc00301e000025,0xd35c00500000002c,0xc31c005000000028\n"
".quad 0x229c045800480010,0x92dc001406000015,0x715c03500000002c,0xd31c006000c00014\n"
".quad 0x225c043018480000,0xa1dc031406000001,0x601c036000c00014,0xb29c006000c0002c\n"
".quad 0x919c033018480020,0x001c436000c0002c,0xa25c026800000014,0x215c0430f78e38e4\n"
".quad 0x619c431406000021,0x91dc00680000001c,0x001c43208e000040,0x611c436800000014\n"
".quad 0x00a1e76800000010,0x1480044000000080,0x14c0041c00000001,0x0401e41c00000011\n"
".quad 0x0081e42800000024,0x30dc032800000058,0x31dc234800c00100,0x0021e71a8ec01000\n"
".quad 0x001de7a800000000,0xa01c044003ffd860,0xa59c041c0000004c,0x01dc031c00000048\n"
".quad 0x00dde4198e000058,0x0081e72800000000,0x00e1e44000000060,0x20a0822800000058\n"
".quad 0x05a1e43955555554,0x0000072800000000,0x049de468000028c0,0x201cc328000000fc\n"
".quad 0x01dc234000000051,0x0001e71a0ec0027c,0x001e03a800000000,0xf39c856000c00008\n"
".quad 0x04dc85c100000003,0xf65c85c100001200,0xf29c85c100000013,0xf3dc85c100000033\n"
".quad 0x31dc03c100000043,0xf75c856800c0000d,0x325c03c100000023,0x77de035800c00009\n"
".quad 0x91dc036000c00008,0xf79c866800c0000c,0x36dc031400080071,0xf31c855800c00011\n"
".quad 0x771e03c100000053,0xf2dc856000c00008,0xb6dc03c100000063,0xc1dc866800c0000d\n"
".quad 0xe39c001400080071,0x965c00307e000078,0xb6de03307e000079,0xf35c856000c00009\n"
".quad 0xd79c00c100000073,0xf69c85307e000079,0xa39c00c100000083,0xf3dc00301c00001c\n"
".quad 0x329c03303200001c,0xb65c865800c00019,0xc79c001400080071,0xf21c85303c00001c\n"
".quad 0xa31c03c100000093,0xf11c856800c0000c,0xc31e03c1000000a3,0xb39c006000c00008\n"
".quad 0x32dc03301c000064,0xd35c005800c00021,0xa79c00301e000064,0xf61c85303c000065\n"
".quad 0xb69c03c1000000b3,0xc65c866800c0000c,0x32dc031400080070,0xf15c855800c00029\n"
".quad 0xa69e03c1000000c3,0xf19c856000c00009,0xb2dc03c1000000d3,0xf5dc856800c0000c\n"
".quad 0x839c00c1000000e3,0x435c00301c000064,0x311c03301a000064,0xa21c865800c00031\n"
".quad 0xb2de031400080071,0xf01c856000c00008,0x411c03c1000000f3,0xf25c856800c0000c\n"
".quad 0x879c00c100000103,0xf75c85303c000065,0x561c00c100000113,0xf1dc85301c000020\n"
".quad 0x411e03c100000123,0xb65c866000c00008,0x315c031400080070,0x635c005800c00039\n"
".quad 0x779c00301a000020,0xf3dc85303c000021,0x515c03c100000143,0x421c866800c0000c\n"
".quad 0x061c001400080070,0xf29c853030000064,0x935c00c100000133,0xf7dc86301a000064\n"
".quad 0xd79c0014000800f1,0xc71c86303c000065,0x565e0314000800f1,0xf39c856000c00008\n"
".quad 0x315c03c100000153,0xf19c855800c00041,0x761c00c100000163,0xb6dc863030000020\n"
".quad 0xc7dc0314000800f1,0x91dc86480000007d,0x515c031400080071,0xf5dc856800c0000c\n"
".quad 0xf79c00c100000173,0xc31c86303c000020,0xb7dc0314000800f0,0xf01c85480000007d\n"
".quad 0xa35c00c100000183,0xa69c86301a000020,0x53de0314000800f1,0x321c036000c00008\n"
".quad 0xe61c005800c00049,0xb2dc86303000001c,0x639c0014000800f0,0xc7dc03301a00001c\n"
".quad 0x821c03480000007c,0xf25c856800c0000c,0xa7dc03c100000193,0xf35c86480000007d\n"
".quad 0x779c001400080070,0xf75c85303c00001d,0x821e03c1000001a3,0xf29c856000c00008\n"
".quad 0xb7dc03c1000001b3,0xf15c85480000007c,0x319c03c1000001c3,0xf5dc855800c00051\n"
".quad 0x061c00c1000001d3,0x42dc863030000034,0x619c0314000800f0,0x801c866800c0000c\n"
".quad 0x939c001400080070,0x311c03301c000034,0xd79c005800c00059,0xf1dc85303c000035\n"
".quad 0x619e03c1000001e3,0xf25c856000c00008,0x411c03c1000001f3,0xf75c856800c0000c\n"
".quad 0xa61c00c100000203,0x539c003030000000,0x779c00301c000000,0x965c86303c000001\n"
".quad 0x411e0314000800f1,0xf29c856000c00008,0xb7dc03c100000213,0xf15c85480000007c\n"
".quad 0x97dc03c100000223,0xf5dc85480000007d,0x635c86c100000233,0xf3dc861400080070\n"
".quad 0x761c0014000800f0,0x42dc863030000034,0x925c001400080070,0xf7dc03301c000034\n"
".quad 0xd75c00480000007c,0x821c86303c000035,0x33dc0314000800f0,0x619c865800c00061\n"
".quad 0xa29c0014000800f0,0x525c00303000002c,0x361c03301200002c,0x72dc005800c00069\n"
".quad 0xf3dc03303a00002d,0x45dc866800c0000c,0x315c0314000800f0,0x87dc035800c00071\n"
".quad 0x861c03480000007c,0xf3de036800c0000d,0x515c036000c00008,0x311c036800c0000c\n"
".quad 0x67dc035800c00079,0xf01c85480000007c,0x875e03c100000243,0x519e036000c00009\n"
".quad 0x415c036000c00008,0xf61c866800c0000c,0x77dc0314000800f0,0xf1dc85480000007d\n"
".quad 0x861c03c100000253,0xd11c86480000007d,0x411c0314000800f1,0xf5dc864800000060\n"
".quad 0x53de031400080070,0xf39c856000c00008,0x061c00c100000263,0x615c86301400005c\n"
".quad 0x781c0014000800f0,0xf79c85301200005c,0x525c03c100000283,0xf35c854800000010\n"
".quad 0xe2dc00c100000273,0xf71c85301600005c,0x629c86c100000293,0xf31c851400080070\n"
".quad 0xf6dc85c1000002b3,0xf69c85c1000002a3,0xd75c86c1000002c3,0xf7dc861400080071\n"
".quad 0xe39c0014000800f0,0xf11cc53040000075,0xf25c03c100000303,0xf1dc864800000025\n"
".quad 0xd35c001400080070,0xf65c853030000074,0xc31c00c1000002d3,0xf21c85301c000028\n"
".quad 0xc3dc00c1000002e3,0xf01c853016000075,0x92dc23c1000002f3,0xb35c005800c00020\n"
".quad 0xa39c00301a000029,0xb2dc03301e000029,0x929c036800c003fc,0x275e046800c003fc\n"
".quad 0x925c23180000002d,0x965c005800c00040,0x861c00301a00001d,0x05dc00301800001c\n"
".quad 0x26de04301c00001c,0x471d001800000025,0x269e043032d02000,0x579d001800000029\n"
".quad 0x6c5d003030d02000,0xb01c00302ed02000,0xdb9c005800000075,0xdbdc005800000065\n"
".quad 0xa7dc005800000061,0xab1c005800000071,0xab5c005800000079,0xdc1c0058000000c5\n"
".quad 0xa11e00580000005d,0x0100073000000069,0xb1dc005000001c80,0xb19c005800000079\n"
".quad 0xf15d005800000071,0xe01d0050000000b2,0xa1de00500000007e,0xa19e00300e000061\n"
".quad 0x415c00300c000065,0x401c005800000014,0x721c005800000000,0x0000075800000010\n"
".quad 0x61dc006000000c00,0x225c245800000010,0x219c241000000021,0x221c241000000015\n"
".quad 0x215c24100000001d,0xb1dc001000000001,0x001d0058000000c5,0x92dc0050000000b7\n"
".quad 0x619c005800d09f00,0x829c005800d09f00,0x515c005800d07e00,0xa25e005800d07e00\n"
".quad 0x421c00300e00005d,0x21dc845800000000,0x219c841000000019,0x201c84100000002d\n"
".quad 0x92dc001000000015,0x215c845800000010,0x211c241000000029,0x03dc021000000021\n"
".quad 0x529c0230f410d5c4,0x735c0230f410d5c4,0x625c0230f206c464,0x411c0030f206c464\n"
".quad 0x239c245800d07e00,0x221c84100000002d,0xa2dc001000000011,0x931c00580000003c\n"
".quad 0xe11c005800000034,0xa31c005800d07e00,0xa39c005800000031,0x211c84580000002d\n"
".quad 0x82dc021000000011,0xd31e0030f410d5c4,0xf39e003018000060,0xd35c00301c000064\n"
".quad 0xf65c005800000034,0x461c02580000003c,0xb3dc0030f410d5c4,0xb35c00580000002c\n"
".quad 0xb65c005800000035,0xb3dc005800000065,0x86dc00580000003d,0x21dc04580000002d\n"
".quad 0xa6dc00140600001d,0x201c04580000006d,0x969c001406000001,0xb2de005800000024\n"
".quad 0xe25e00303600005c,0xa5dc003018000025,0xd31c005800000028,0x12de00301a000069\n"
".quad 0xc35e003016000063,0xb2dc00301c000029,0x939c00500000002c,0x829c005000000024\n"
".quad 0xd25c005800000061,0xd35c00303200005d,0xc31c005000000034,0xd29c005000000038\n"
".quad 0x935c00301e000029,0xc31c005000000034,0x225c045800480010,0xa29c001406000019\n"
".quad 0x219c04500000002c,0xd2dc001406000015,0x715c033018480000,0x001c036000c00014\n"
".quad 0x91dc036000c0002c,0x619c036000c00014,0xa25c006000c0002c,0x001c433016480020\n"
".quad 0x619c436800000014,0x215c04680000001c,0x211c041406000021,0x91dc001406000011\n"
".quad 0x001c435800cfa000,0x611c436800000014,0x71dc006800000010,0xa01c04208e000040\n"
".quad 0xa11c041c00000000,0x0021f41c00000010,0x01dc034000000000,0x041de4198e000010\n"
".quad 0x059de4280000001c,0x00dde42800000000,0x0081e72800000010,0xf0a1c340000000e0\n"
".quad 0x00e1e4680000004f,0x20a0032800000000,0x05a1e45800c00004,0x20a0022800000010\n"
".quad 0x30a0833955555554,0x001de46800000009,0x0081e44000000000,0x001df4280000004c\n"
".quad 0x249c034000000000,0x21dc234800c00005,0x0021e71a8ec0000d,0x001de7a800000000\n"
".quad 0x11dc034003ffd760,0x141c854800c00701,0x521c03c900000701,0x551c854800c01c01\n"
".quad 0x001de2c900001c01,0xffdc041800000080,0x01dc2350ee0000ff,0x000007198e000050\n"
".quad 0x0001e76000000180,0x019c034000000140,0x711c854800000050,0x615e03c100000000\n"
".quad 0x515c856000c00008,0x41dc00c100000700,0x00a1e7220e000014,0x6102034000000080\n"
".quad 0x7140856000c00008,0x410085c900000000,0x810085c100001c00,0x001c33c900000000\n"
".quad 0x01dc235800c00004,0x0001e71a0e0000fc,0xffdc044003fffde0,0xf01c8550ee0000ff\n"
".quad 0xffdc04c100001c03,0x01dc2350ee0000ff,0x0001e71a8e000050,0x31dc038000000000\n"
".quad 0xf41cc5190e000058,0xf01c04c100000603,0xf31cc5200000000b,0xf21cc5c100000643\n"
".quad 0x145e03c100000683,0x249e036000c00005,0x34de036000c00005,0x041e036000c00005\n"
".quad 0xc51e036000c00005,0xd55e036000c00004,0xe5de036000c00004,0x031c036000c00004\n"
".quad 0x809e035800000044,0x035c036000c00004,0x039c035800000048,0x921e03580000004c\n"
".quad 0xf61e036000c00004,0x025c036000c00004,0xc31c035800000040,0x03dc036800c0000c\n"
".quad 0x041c035800000050,0xd35c035800000054,0xe39c036800c0000c,0x045c036800c0000c\n"
".quad 0xc31c03580000005c,0x925c036000c00008,0x049c036800c0000c,0xd35c035800000060\n"
".quad 0xe39c036000c00010,0xf3dc036000c00018,0x041c036800c0000c,0x145c036800c0000d\n"
".quad 0x925c436800c0000d,0xf11cc56800000030,0x249c03c1000006c3,0xf3dc036800c0000d\n"
".quad 0x041c036000c00020,0xd31c436000c00029,0x04dc036800000038,0x139c035800000008\n"
".quad 0x245c036000c00031,0x909c436000c00039,0xf35c436800000030,0xa31e036800000040\n"
".quad 0x029c036000c00004,0x325c035800000020,0xe21c436800c0000d,0x209c436800000044\n"
".quad 0xb35e036800000034,0x925c036000c00004,0x02dc036000c00040,0xa29c035800000030\n"
".quad 0x209c436800c0000c,0x439e036800000020,0x031c036000c00004,0xa11c035800000034\n"
".quad 0xb21c036000c00048,0x209c436800c0000c,0x52de036800000024,0x029c036000c00004\n"
".quad 0xc25c035800000038,0x815c036800c0000c,0x209c436000c00050,0x631e036800000010\n"
".quad 0x021c036000c00004,0xa19c03580000002c,0x911c036800c0000c,0x209c436000c00058\n"
".quad 0x025c036800000014,0x615c035800000030,0x821c036000c00060,0x209c436800c0000c\n"
".quad 0x71de036800000010,0x919c036000c00004,0x811c036800c0000c,0x209c436000c00068\n"
".quad 0x01dc036800000014,0x029c04580000001c,0x615c032c00000094,0x021de46000c00070\n"
".quad 0x201c4328004000c0,0x30dc036800000010,0x709c036000c00040,0xa19c036000c00078\n"
".quad 0x001c432011c00020,0x611c436800000014,0xf1dc43680000000d,0x015c4348004000d3\n"
".quad 0x611ca56800000008,0x001de79400000000,0x401c038000000000,0x001c036000c00004\n"
".quad 0x015c035800c00060,0x215c044800c0000c,0x51dc031c00000014,0x0001e7198ec0000c\n"
".quad 0x401c004000000080,0x411c00c800000010,0x011e003000800004,0x001de73000000010\n"
".quad 0x01dc034000000760,0x0001e71a8e0000fc,0x401c024000000300,0x015c033801fffffc\n"
".quad 0x515e037800000000,0x519c034800c0007c,0x61dc034800ffffdc,0x0001e7198ec00004\n"
".quad 0x411c004000000040,0x001de7c800000010,0x519c034000000620,0x411c024800ffffe0\n"
".quad 0x001c033a00000000,0x001c026000000018,0x001c423801fffffc,0x019c0038fe000000\n"
".quad 0x001c00c800000010,0x601e00300c800004,0x001c02300c000000,0x019c033801fffffc\n"
".quad 0x515d03110e0000fc,0x515c034800000018,0x515c034800c003d0,0x411c436000c0005c\n"
".quad 0x011c436800000014,0x001de76800000010,0x015c034000000420,0x51dc034800fffc0c\n"
".quad 0x0001e71a0ec00004,0x419c0240000003a0,0x02dde23801fffffc,0x61dc42180000000c\n"
".quad 0x721c0038fe000000,0xb2dc03c800000010,0x71dc006000000014,0x411c023010800004\n"
".quad 0x825e003a00000000,0x929c02309000001c,0x821e003801fffffc,0xa29c42311000001c\n"
".quad 0xb1dc033802000000,0x91dc006800000028,0x71dc032e8e000020,0xf21c045800000014\n"
".quad 0x515c032010c00007,0x725c036800000028,0x815c436800c00008,0x91dc036800000014\n"
".quad 0x021c031a8e0000fc,0x51dc034800fffc10,0x701c031aa00000fc,0xa15c036800c00004\n"
".quad 0x01dc235800000020,0x5140031a800000fc,0x501c034800c00004,0x001c036000c00004\n"
".quad 0x011c43310c000014,0x001de76800000010,0x411c004000000020,0x001de7c800000010\n"
".quad 0x0000009000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x8000000000000000\n"
".quad 0x000000000c0c04bf,0x0000100000000800,0x00000b00080a0400,0x1819030018002000\n"
".quad 0xffffff000c170400,0x21f00000100002ff,0xffffff000c170400,0x21f00000080001ff\n"
".quad 0xffffff000c170400,0x21f00000000000ff,0x22019800080d0400,0x8000000000002000\n"
".quad 0x8000003f8000003f,0x000000411000003f,0x40000040c0000000,0x0000004080000040\n"
".quad 0x0000004000000000,0x0009000009000040,0x0104020004010200,0x0004000004000000\n"
".quad 0x0104010004010100,0x00000e0008120400,0x0811040000000000,0x0000000000000e00\n"
".quad 0x00000d0008120400,0x0811040000000000,0x0000000000000d00,0x0000000600000000\n"
".quad 0x000033bc00000005,0x0000000000000000,0x0000000000000000,0x000000e000000000\n"
".quad 0x000000e000000000,0x0000000400000000,0x6000000000000000,0x0000064500000d05\n"
".quad 0x0000000000000000,0x0000000000000000,0x00002cf800000000,0x00002cf800000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x0000333d00000d06,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000080000000000,0x0000000400000000\n"
".quad 0x0000000100000000,0x0000333d00000005,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000004c00000000,0x0000004c00000000,0x0000000400000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[1684];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3930,0x662e20656c626973\n"
".quad 0x61702e2820636e75,0x696c612e206d6172,0x38622e2034206e67,0x72616475635f5f20\n"
".quad 0x36315a5f5f667465,0x6769457473726966,0x726f746365566e65,0x20295d32315b6650\n"
".quad 0x7372696636315a5f,0x65566e6567694574,0x28206650726f7463,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x31666d7261706164,0x72696636315a5f5f,0x566e656769457473\n"
".quad 0x296650726f746365,0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063\n"
".quad 0x6e67696c612e206d,0x5f2038622e203420,0x746572616475635f,0x656231315a5f5f66\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x5d32315b5f533374,0x656231315a5f2029\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x702e28205f533374,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x5f5f31666d726170,0x467473656231315a,0x4b50656e694c7469\n"
".quad 0x533374616f6c6636,0x617261702e202c5f,0x6e67696c612e206d,0x5f2038622e203420\n"
".quad 0x726170616475635f,0x31315a5f5f32666d,0x4c74694674736562,0x6c66364b50656e69\n"
".quad 0x315b5f533374616f,0x762e090a0a295d32,0x2e20656c62697369,0x315a5f20636e7566\n"
".quad 0x6c6f4374726f7330,0x6950664b5073726f,0x6d617261702e2820,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x7330315a5f5f3166,0x726f6c6f4374726f,0x202c6950664b5073\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x32666d7261706164,0x726f7330315a5f5f\n"
".quad 0x5073726f6c6f4374,0x090a0a296950664b,0x656c62697369762e,0x5f20636e75662e20\n"
".quad 0x4364616f6c34315a,0x636f6c42726f6c6f,0x6c6636506a4b506b,0x505f32533374616f\n"
".quad 0x617261702e282069,0x5f203436752e206d,0x726170616475635f,0x34315a5f5f31666d\n"
".quad 0x6f6c6f4364616f6c,0x4b506b636f6c4272,0x74616f6c6636506a,0x202c69505f325333\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x32666d7261706164,0x616f6c34315a5f5f\n"
".quad 0x6c42726f6c6f4364,0x36506a4b506b636f,0x32533374616f6c66,0x61702e202c69505f\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x6f4364616f6c3431\n"
".quad 0x6b636f6c42726f6c,0x6f6c6636506a4b50,0x69505f3253337461,0x6d617261702e202c\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x6c34315a5f5f3466,0x726f6c6f4364616f\n"
".quad 0x6a4b506b636f6c42,0x3374616f6c663650,0x0a0a2969505f3253,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x6c61766539315a5f,0x756d7265506c6c41,0x50736e6f69746174\n"
".quad 0x3374616f6c66364b,0x5f345374526a4b50,0x28205f5366506a52,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x31666d7261706164,0x61766539315a5f5f,0x6d7265506c6c416c\n"
".quad 0x736e6f6974617475,0x74616f6c66364b50,0x345374526a4b5033,0x2c5f5366506a525f\n"
".quad 0x206d617261702e20,0x635f5f203436752e,0x666d726170616475,0x766539315a5f5f32\n"
".quad 0x7265506c6c416c61,0x6e6f69746174756d,0x616f6c66364b5073,0x5374526a4b503374\n"
".quad 0x5f5366506a525f34,0x6d617261702e202c,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x6539315a5f5f3366,0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e\n"
".quad 0x74526a4b50337461,0x5366506a525f3453,0x617261702e202c5f,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x39315a5f5f34666d,0x506c6c416c617665,0x69746174756d7265\n"
".quad 0x6c66364b50736e6f,0x526a4b503374616f,0x66506a525f345374,0x7261702e202c5f53\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x315a5f5f35666d72,0x6c6c416c61766539\n"
".quad 0x746174756d726550,0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452\n"
".quad 0x61702e202c5f5366,0x3436752e206d6172,0x70616475635f5f20,0x5a5f5f36666d7261\n"
".quad 0x6c416c6176653931,0x6174756d7265506c,0x364b50736e6f6974,0x4b503374616f6c66\n"
".quad 0x6a525f345374526a,0x702e202c5f536650,0x6c612e206d617261,0x622e2034206e6769\n"
".quad 0x616475635f5f2038,0x5f5f37666d726170,0x416c61766539315a,0x74756d7265506c6c\n"
".quad 0x4b50736e6f697461,0x503374616f6c6636,0x525f345374526a4b,0x32315b5f5366506a\n"
".quad 0x69762e090a0a295d,0x662e20656c626973,0x73345a5f20636e75,0x5276457449706177\n"
".quad 0x2e28205f31535f54,0x752e206d61726170,0x6475635f5f203436,0x5f31666d72617061\n"
".quad 0x4970617773345a5f,0x31535f5452764574,0x617261702e202c5f,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x73345a5f5f32666d,0x5276457449706177,0x0a0a295f31535f54\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e\n"
".quad 0x5f66746572616475,0x646e696632315a5f,0x726f7272456e694d,0x32315a5f20296650\n"
".quad 0x456e694d646e6966,0x28206650726f7272,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x31666d7261706164,0x6e696632315a5f5f,0x6f7272456e694d64,0x2e090a0a29665072\n"
".quad 0x20656c6269736976,0x5a5f20636e75662e,0x6c42657661733331,0x74315458446b636f\n"
".quad 0x6975355069506a74,0x61702e282032746e,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f31666d7261,0x6c42657661733331,0x74315458446b636f,0x6975355069506a74\n"
".quad 0x61702e202c32746e,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261\n"
".quad 0x6c42657661733331,0x74315458446b636f,0x6975355069506a74,0x61702e202c32746e\n"
".quad 0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x6c42657661733331\n"
".quad 0x74315458446b636f,0x6975355069506a74,0x61702e202c32746e,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f34666d7261,0x6c42657661733331,0x74315458446b636f\n"
".quad 0x6975355069506a74,0x61702e202c32746e,0x3436752e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f35666d7261,0x6c42657661733331,0x74315458446b636f,0x6975355069506a74\n"
".quad 0x2f090a0a2932746e,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x696c69706d6f4320,0x2f706d742f20676e,0x305f746678706d74\n"
".quad 0x5f37613830303030,0x3030303030303030,0x2e637478645f372d,0x2820692e33707063\n"
".quad 0x4263632f706d742f,0x4e5a5a45472e2349,0x2d2d2f2f090a2949,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2f2f090a0a2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x704f202f2f090a2d,0x090a3a736e6f6974\n"
".quad 0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d\n"
".quad 0x656772615420202f,0x49202c7874703a74,0x30325f6d733a4153,0x6e6169646e45202c\n"
".quad 0x2c656c7474696c3a,0x7265746e696f5020,0x34363a657a695320,0x4f2d20202f2f090a\n"
".quad 0x6d6974704f280933,0x206e6f6974617a69,0x090a296c6576656c,0x0930672d20202f2f\n"
".quad 0x6c20677562654428,0x2f090a296c657665,0x2809326d2d20202f,0x612074726f706552\n"
".quad 0x6569726f73697664,0x2d2d2f2f090a2973,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x6c69662e090a0a2d,0x6f633c2209310965,0x696c2d646e616d6d\n"
".quad 0x662e090a223e656e,0x2f22093209656c69,0x78706d742f706d74,0x30303030305f7466\n"
".quad 0x303030305f376138,0x645f362d30303030,0x616475632e637478,0x227570672e326566\n"
".quad 0x09656c69662e090a,0x2f7273752f220933,0x2f6363672f62696c,0x6e696c2d36383669\n"
".quad 0x342f756e672d7875,0x636e692f352e342e,0x6474732f6564756c,0x090a22682e666564\n"
".quad 0x093409656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x697665642f747263,0x69746e75725f6563,0x2e090a22682e656d\n"
".quad 0x22093509656c6966,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x682f6564756c636e,0x696665645f74736f,0x090a22682e73656e,0x093609656c69662e\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x5f6e69746c697562,0x22682e7365707974,0x09656c69662e090a,0x2f7273752f220937\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65\n"
".quad 0x682e73657079745f,0x656c69662e090a22,0x7273752f22093809,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x65766972642f6564,0x2e73657079745f72\n"
".quad 0x6c69662e090a2268,0x73752f2209390965,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x667275732f656475,0x657079745f656361,0x662e090a22682e73\n"
".quad 0x2209303109656c69,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x742f6564756c636e,0x745f657275747865,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220931,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x726f746365762f65,0x682e73657079745f,0x656c69662e090a22,0x73752f2209323109\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x697665642f656475\n"
".quad 0x636e75616c5f6563,0x656d617261705f68,0x0a22682e73726574,0x3109656c69662e09\n"
".quad 0x2f7273752f220933,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x74732f7472632f65,0x6c635f656761726f,0x090a22682e737361,0x343109656c69662e\n"
".quad 0x692f7273752f2209,0x622f6564756c636e,0x657079742f737469,0x662e090a22682e73\n"
".quad 0x2209353109656c69,0x636e692f7273752f,0x6d69742f6564756c,0x662e090a22682e65\n"
".quad 0x2209363109656c69,0x6f6e2f656d6f682f,0x6568632f6c616d72,0x70672f74756f6b63\n"
".quad 0x2f746f6c65636f75,0x74702d7374736574,0x75632f312e322d78,0x65742f322e326164\n"
".quad 0x637478642f737473,0x74614d616475432f,0x662e090a22682e68,0x2209373109656c69\n"
".quad 0x6f6e2f656d6f682f,0x6568632f6c616d72,0x70672f74756f6b63,0x2f746f6c65636f75\n"
".quad 0x74702d7374736574,0x75632f312e322d78,0x65742f322e326164,0x637478642f737473\n"
".quad 0x75632e637478642f,0x656c69662e090a22,0x73752f2209383109,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x6d6d6f632f656475,0x74636e75665f6e6f\n"
".quad 0x0a22682e736e6f69,0x3109656c69662e09,0x2f7273752f220939,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x665f6874616d2f65,0x736e6f6974636e75\n"
".quad 0x69662e090a22682e,0x2f2209303209656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x616d2f6564756c63,0x74736e6f635f6874,0x0a22682e73746e61\n"
".quad 0x3209656c69662e09,0x2f7273752f220931,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x6563697665642f65,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09323209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x74615f31315f6d73,0x6e75665f63696d6f,0x682e736e6f697463\n"
".quad 0x656c69662e090a22,0x73752f2209333209,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x315f6d732f656475,0x63696d6f74615f32,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09343209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6f645f33315f6d73,0x6e75665f656c6275\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209353209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x325f6d732f656475,0x63696d6f74615f30\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09363209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6e695f30325f6d73\n"
".quad 0x736369736e697274,0x69662e090a22682e,0x2f2209373209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x75732f6564756c63,0x75665f6563616672\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220938320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x7865742f6564756c,0x7465665f65727574\n"
".quad 0x74636e75665f6863,0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220939\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x665f6874616d2f65\n"
".quad 0x736e6f6974636e75,0x7874705f6c62645f,0x090a0a0a22682e33,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x5f5f667465726164,0x747372696636315a,0x6365566e65676945,0x32315b6650726f74\n"
".quad 0x6636315a5f20295d,0x6567694574737269,0x50726f746365566e,0x617261702e282066\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x36315a5f5f31666d,0x6769457473726966\n"
".quad 0x726f746365566e65,0x090a7b090a296650,0x36752e206765722e,0x3e343c6472252034\n"
".quad 0x206765722e090a3b,0x3c6625203233662e,0x2e090a3b3e313331,0x3409363109636f6c\n"
".quad 0x57444c240a300935,0x5a5f5f6e69676562,0x4574737269663631,0x746365566e656769\n"
".quad 0x6c090a3a6650726f,0x2e6d617261702e64,0x6472250920343675,0x75635f5f5b202c31\n"
".quad 0x31666d7261706164,0x72696636315a5f5f,0x566e656769457473,0x5d6650726f746365\n"
".quad 0x732e766f6d090a3b,0x3264722509203436,0x0a3b31647225202c,0x363109636f6c2e09\n"
".quad 0x6c090a3009303509,0x2509203233662e64,0x6472255b202c3166,0x6c090a3b5d342b32\n"
".quad 0x2509203233662e64,0x6472255b202c3266,0x6c090a3b5d302b32,0x2509203233662e64\n"
".quad 0x6472255b202c3366,0x6d090a3b5d382b32,0x09203233662e766f,0x336630202c346625\n"
".quad 0x3b30303030303866,0x2f2f092020202020,0x2e616d66090a3120,0x09203233662e6e72\n"
".quad 0x326625202c356625,0x25202c346625202c,0x766f6d090a3b3166,0x662509203233662e\n"
".quad 0x3866336630202c36,0x20203b3030303030,0x31202f2f09202020,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x202c336625202c37,0x356625202c366625,0x09636f6c2e090a3b\n"
".quad 0x0a30093135093631,0x203233662e646c09,0x255b202c38662509,0x3b5d32312b326472\n"
".quad 0x3233662e646c090a,0x5b202c3966250920,0x5d36312b32647225,0x662e766f6d090a3b\n"
".quad 0x3031662509203233,0x303866336630202c,0x2020203b30303030,0x090a31202f2f0920\n"
".quad 0x662e6e722e616d66,0x3131662509203233,0x25202c316625202c,0x386625202c303166\n"
".quad 0x662e766f6d090a3b,0x3231662509203233,0x303866336630202c,0x2020203b30303030\n"
".quad 0x090a31202f2f0920,0x662e6e722e616d66,0x3331662509203233,0x25202c396625202c\n"
".quad 0x316625202c323166,0x636f6c2e090a3b31,0x3009323509363109,0x3233662e646c090a\n"
".quad 0x202c343166250920,0x30322b326472255b,0x2e766f6d090a3b5d,0x3166250920323366\n"
".quad 0x3866336630202c35,0x20203b3030303030,0x0a31202f2f092020,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x202c336625202c36,0x6625202c35316625,0x2e766f6d090a3b39\n"
".quad 0x3166250920323366,0x3866336630202c37,0x20203b3030303030,0x0a31202f2f092020\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x2c34316625202c38,0x25202c3731662520\n"
".quad 0x6c2e090a3b363166,0x383509363109636f,0x2e78616d090a3009,0x3166250920323366\n"
".quad 0x202c376625202c39,0x6d090a3b33316625,0x09203233662e7861,0x6625202c30326625\n"
".quad 0x38316625202c3931,0x722e706372090a3b,0x2509203233662e6e,0x326625202c313266\n"
".quad 0x2e6c756d090a3b30,0x3266250920323366,0x2c31326625202c32,0x6d090a3b37662520\n"
".quad 0x09203233662e6c75,0x6625202c33326625,0x33316625202c3132,0x662e6c756d090a3b\n"
".quad 0x3432662509203233,0x202c31326625202c,0x2e090a3b38316625,0x3509363109636f6c\n"
".quad 0x6c756d090a300930,0x662509203233662e,0x2c316625202c3532,0x090a3b3332662520\n"
".quad 0x662e6e722e616d66,0x3632662509203233,0x25202c326625202c,0x326625202c323266\n"
".quad 0x2e616d66090a3b35,0x09203233662e6e72,0x6625202c37326625,0x2c34326625202c33\n"
".quad 0x090a3b3632662520,0x09363109636f6c2e,0x756d090a30093135,0x2509203233662e6c\n"
".quad 0x386625202c383266,0x0a3b33326625202c,0x2e6e722e616d6609,0x3266250920323366\n"
".quad 0x202c316625202c39,0x6625202c32326625,0x616d66090a3b3832,0x203233662e6e722e\n"
".quad 0x25202c3033662509,0x34326625202c3966,0x0a3b39326625202c,0x363109636f6c2e09\n"
".quad 0x6d090a3009323509,0x09203233662e6c75,0x6625202c31336625,0x3b33326625202c39\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x2c336625202c3233,0x25202c3232662520\n"
".quad 0x6d66090a3b313366,0x3233662e6e722e61,0x202c333366250920,0x6625202c34316625\n"
".quad 0x32336625202c3432,0x09636f6c2e090a3b,0x0a30093835093631,0x3233662e78616d09\n"
".quad 0x202c343366250920,0x6625202c37326625,0x78616d090a3b3033,0x662509203233662e\n"
".quad 0x34336625202c3533,0x0a3b33336625202c,0x2e6e722e70637209,0x3366250920323366\n"
".quad 0x3b35336625202c36,0x33662e6c756d090a,0x2c37336625092032,0x25202c3633662520\n"
".quad 0x756d090a3b373266,0x2509203233662e6c,0x336625202c383366,0x3b30336625202c36\n"
".quad 0x33662e6c756d090a,0x2c39336625092032,0x25202c3633662520,0x6c2e090a3b333366\n"
".quad 0x303509363109636f,0x2e6c756d090a3009,0x3466250920323366,0x202c316625202c30\n"
".quad 0x66090a3b38336625,0x33662e6e722e616d,0x2c31346625092032,0x6625202c32662520\n"
".quad 0x30346625202c3733,0x722e616d66090a3b,0x2509203233662e6e,0x336625202c323466\n"
".quad 0x202c39336625202c,0x2e090a3b31346625,0x3509363109636f6c,0x6c756d090a300931\n"
".quad 0x662509203233662e,0x2c386625202c3334,0x090a3b3833662520,0x662e6e722e616d66\n"
".quad 0x3434662509203233,0x25202c316625202c,0x346625202c373366,0x2e616d66090a3b33\n"
".quad 0x09203233662e6e72,0x6625202c35346625,0x2c39336625202c39,0x090a3b3434662520\n"
".quad 0x09363109636f6c2e,0x756d090a30093235,0x2509203233662e6c,0x396625202c363466\n"
".quad 0x0a3b38336625202c,0x2e6e722e616d6609,0x3466250920323366,0x202c336625202c37\n"
".quad 0x6625202c37336625,0x616d66090a3b3634,0x203233662e6e722e,0x25202c3834662509\n"
".quad 0x336625202c343166,0x3b37346625202c39,0x3109636f6c2e090a,0x090a300938350936\n"
".quad 0x203233662e78616d,0x25202c3934662509,0x346625202c323466,0x2e78616d090a3b35\n"
".quad 0x3566250920323366,0x2c39346625202c30,0x090a3b3834662520,0x662e6e722e706372\n"
".quad 0x3135662509203233,0x0a3b30356625202c,0x3233662e6c756d09,0x202c323566250920\n"
".quad 0x6625202c31356625,0x6c756d090a3b3234,0x662509203233662e,0x31356625202c3335\n"
".quad 0x0a3b35346625202c,0x3233662e6c756d09,0x202c343566250920,0x6625202c31356625\n"
".quad 0x6f6c2e090a3b3834,0x0930350936310963,0x662e6c756d090a30,0x3535662509203233\n"
".quad 0x25202c316625202c,0x6d66090a3b333566,0x3233662e6e722e61,0x202c363566250920\n"
".quad 0x356625202c326625,0x3b35356625202c32,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x2c336625202c3735,0x25202c3435662520,0x6c2e090a3b363566,0x313509363109636f\n"
".quad 0x2e6c756d090a3009,0x3566250920323366,0x202c386625202c38,0x66090a3b33356625\n"
".quad 0x33662e6e722e616d,0x2c39356625092032,0x6625202c31662520,0x38356625202c3235\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x396625202c303666,0x202c34356625202c\n"
".quad 0x2e090a3b39356625,0x3509363109636f6c,0x6c756d090a300932,0x662509203233662e\n"
".quad 0x2c396625202c3136,0x090a3b3335662520,0x662e6e722e616d66,0x3236662509203233\n"
".quad 0x25202c336625202c,0x366625202c323566,0x2e616d66090a3b31,0x09203233662e6e72\n"
".quad 0x6625202c33366625,0x34356625202c3431,0x0a3b32366625202c,0x363109636f6c2e09\n"
".quad 0x6d090a3009383509,0x09203233662e7861,0x6625202c34366625,0x30366625202c3735\n"
".quad 0x662e78616d090a3b,0x3536662509203233,0x202c34366625202c,0x72090a3b33366625\n"
".quad 0x33662e6e722e7063,0x2c36366625092032,0x090a3b3536662520,0x203233662e6c756d\n"
".quad 0x25202c3736662509,0x356625202c363666,0x2e6c756d090a3b37,0x3666250920323366\n"
".quad 0x2c36366625202c38,0x090a3b3036662520,0x203233662e6c756d,0x25202c3936662509\n"
".quad 0x366625202c363666,0x636f6c2e090a3b33,0x3009303509363109,0x33662e6c756d090a\n"
".quad 0x2c30376625092032,0x6625202c31662520,0x616d66090a3b3836,0x203233662e6e722e\n"
".quad 0x25202c3137662509,0x37366625202c3266,0x0a3b30376625202c,0x2e6e722e616d6609\n"
".quad 0x3766250920323366,0x202c336625202c32,0x6625202c39366625,0x6f6c2e090a3b3137\n"
".quad 0x0931350936310963,0x662e6c756d090a30,0x3337662509203233,0x25202c386625202c\n"
".quad 0x6d66090a3b383666,0x3233662e6e722e61,0x202c343766250920,0x366625202c316625\n"
".quad 0x3b33376625202c37,0x6e722e616d66090a,0x662509203233662e,0x2c396625202c3537\n"
".quad 0x25202c3936662520,0x6c2e090a3b343766,0x323509363109636f,0x2e6c756d090a3009\n"
".quad 0x3766250920323366,0x202c396625202c36,0x66090a3b38366625,0x33662e6e722e616d\n"
".quad 0x2c37376625092032,0x6625202c33662520,0x36376625202c3736,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x316625202c383766,0x2c39366625202c34,0x090a3b3737662520\n"
".quad 0x09363109636f6c2e,0x616d090a30093835,0x2509203233662e78,0x376625202c393766\n"
".quad 0x3b35376625202c32,0x33662e78616d090a,0x2c30386625092032,0x25202c3937662520\n"
".quad 0x6372090a3b383766,0x3233662e6e722e70,0x202c313866250920,0x6d090a3b30386625\n"
".quad 0x09203233662e6c75,0x6625202c32386625,0x32376625202c3138,0x662e6c756d090a3b\n"
".quad 0x3338662509203233,0x202c31386625202c,0x6d090a3b35376625,0x09203233662e6c75\n"
".quad 0x6625202c34386625,0x38376625202c3138,0x09636f6c2e090a3b,0x0a30093035093631\n"
".quad 0x3233662e6c756d09,0x202c353866250920,0x386625202c316625,0x2e616d66090a3b33\n"
".quad 0x09203233662e6e72,0x6625202c36386625,0x2c32386625202c32,0x090a3b3538662520\n"
".quad 0x662e6e722e616d66,0x3738662509203233,0x25202c336625202c,0x386625202c343866\n"
".quad 0x636f6c2e090a3b36,0x3009313509363109,0x33662e6c756d090a,0x2c38386625092032\n"
".quad 0x6625202c38662520,0x616d66090a3b3338,0x203233662e6e722e,0x25202c3938662509\n"
".quad 0x32386625202c3166,0x0a3b38386625202c,0x2e6e722e616d6609,0x3966250920323366\n"
".quad 0x202c396625202c30,0x6625202c34386625,0x6f6c2e090a3b3938,0x0932350936310963\n"
".quad 0x662e6c756d090a30,0x3139662509203233,0x25202c396625202c,0x6d66090a3b333866\n"
".quad 0x3233662e6e722e61,0x202c323966250920,0x386625202c336625,0x3b31396625202c32\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x34316625202c3339,0x202c34386625202c\n"
".quad 0x2e090a3b32396625,0x3509363109636f6c,0x78616d090a300938,0x662509203233662e\n"
".quad 0x37386625202c3439,0x0a3b30396625202c,0x3233662e78616d09,0x202c353966250920\n"
".quad 0x6625202c34396625,0x706372090a3b3339,0x203233662e6e722e,0x25202c3639662509\n"
".quad 0x756d090a3b353966,0x2509203233662e6c,0x396625202c373966,0x3b37386625202c36\n"
".quad 0x33662e6c756d090a,0x2c38396625092032,0x25202c3639662520,0x756d090a3b303966\n"
".quad 0x2509203233662e6c,0x396625202c393966,0x3b33396625202c36,0x3109636f6c2e090a\n"
".quad 0x090a300930350936,0x203233662e6c756d,0x202c303031662509,0x396625202c316625\n"
".quad 0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3130316625,0x37396625202c3266\n"
".quad 0x3b3030316625202c,0x6e722e616d66090a,0x662509203233662e,0x336625202c323031\n"
".quad 0x202c39396625202c,0x090a3b3130316625,0x09363109636f6c2e,0x756d090a30093135\n"
".quad 0x2509203233662e6c,0x6625202c33303166,0x3b38396625202c38,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x316625202c343031,0x202c37396625202c,0x090a3b3330316625\n"
".quad 0x662e6e722e616d66,0x3031662509203233,0x202c396625202c35,0x6625202c39396625\n"
".quad 0x6c2e090a3b343031,0x323509363109636f,0x2e6c756d090a3009,0x3166250920323366\n"
".quad 0x2c396625202c3630,0x090a3b3839662520,0x662e6e722e616d66,0x3031662509203233\n"
".quad 0x202c336625202c37,0x6625202c37396625,0x6d66090a3b363031,0x3233662e6e722e61\n"
".quad 0x2c38303166250920,0x25202c3431662520,0x316625202c393966,0x6f6c2e090a3b3730\n"
".quad 0x0938350936310963,0x662e78616d090a30,0x3031662509203233,0x3230316625202c39\n"
".quad 0x3b3530316625202c,0x33662e78616d090a,0x3031316625092032,0x2c3930316625202c\n"
".quad 0x0a3b383031662520,0x2e6e722e70637209,0x3166250920323366,0x31316625202c3131\n"
".quad 0x2e6c756d090a3b30,0x3166250920323366,0x31316625202c3231,0x3230316625202c31\n"
".quad 0x662e6c756d090a3b,0x3131662509203233,0x3131316625202c33,0x3b3530316625202c\n"
".quad 0x33662e6c756d090a,0x3431316625092032,0x2c3131316625202c,0x0a3b383031662520\n"
".quad 0x363109636f6c2e09,0x6d090a3009303509,0x09203233662e6c75,0x25202c3531316625\n"
".quad 0x31316625202c3166,0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3631316625\n"
".quad 0x31316625202c3266,0x3531316625202c32,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c37313166,0x3431316625202c33,0x3b3631316625202c,0x3109636f6c2e090a\n"
".quad 0x090a300931350936,0x203233662e6c756d,0x202c383131662509,0x316625202c386625\n"
".quad 0x616d66090a3b3331,0x203233662e6e722e,0x202c393131662509,0x316625202c316625\n"
".quad 0x31316625202c3231,0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3032316625\n"
".quad 0x31316625202c3966,0x3931316625202c34,0x09636f6c2e090a3b,0x0a30093235093631\n"
".quad 0x3233662e6c756d09,0x2c31323166250920,0x6625202c39662520,0x6d66090a3b333131\n"
".quad 0x3233662e6e722e61,0x2c32323166250920,0x6625202c33662520,0x316625202c323131\n"
".quad 0x616d66090a3b3132,0x203233662e6e722e,0x202c333231662509,0x6625202c34316625\n"
".quad 0x316625202c343131,0x6f6c2e090a3b3232,0x0931360936310963,0x662e78616d090a30\n"
".quad 0x3231662509203233,0x3731316625202c34,0x3b3032316625202c,0x33662e78616d090a\n"
".quad 0x3532316625092032,0x2c3432316625202c,0x0a3b333231662520,0x2e6e722e70637209\n"
".quad 0x3166250920323366,0x32316625202c3632,0x2e6c756d090a3b35,0x3166250920323366\n"
".quad 0x32316625202c3732,0x3731316625202c36,0x61702e7473090a3b,0x203233662e6d6172\n"
".quad 0x616475635f5f5b09,0x315a5f5f66746572,0x6945747372696636,0x6f746365566e6567\n"
".quad 0x202c5d302b665072,0x090a3b3732316625,0x203233662e6c756d,0x202c383231662509\n"
".quad 0x25202c3632316625,0x73090a3b30323166,0x2e6d617261702e74,0x5f5f5b0920323366\n"
".quad 0x6674657261647563,0x72696636315a5f5f,0x566e656769457473,0x2b6650726f746365\n"
".quad 0x32316625202c5d34,0x2e6c756d090a3b38,0x3166250920323366,0x32316625202c3932\n"
".quad 0x3332316625202c36,0x61702e7473090a3b,0x203233662e6d6172,0x616475635f5f5b09\n"
".quad 0x315a5f5f66746572,0x6945747372696636,0x6f746365566e6567,0x202c5d382b665072\n"
".quad 0x090a3b3932316625,0x444c240a3b746572,0x315a5f5f646e6557,0x6945747372696636\n"
".quad 0x6f746365566e6567,0x207d090a3a665072,0x6636315a5f202f2f,0x6567694574737269\n"
".quad 0x50726f746365566e,0x726168732e090a66,0x67696c612e206465,0x38622e203631206e\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f38313037335f72,0x635f6e6f6e5f3533\n"
".quad 0x766f635f74736e6f,0x5f65636e61697261,0x3b5d3438335b305f,0x697369762e090a0a\n"
".quad 0x6e75662e20656c62,0x617261702e282063,0x6e67696c612e206d,0x5f2038622e203420\n"
".quad 0x746572616475635f,0x656231315a5f5f66,0x6e694c7469467473,0x616f6c66364b5065\n"
".quad 0x5d32315b5f533374,0x656231315a5f2029,0x6e694c7469467473,0x616f6c66364b5065\n"
".quad 0x702e28205f533374,0x36752e206d617261,0x616475635f5f2034,0x5f5f31666d726170\n"
".quad 0x467473656231315a,0x4b50656e694c7469,0x533374616f6c6636,0x617261702e202c5f\n"
".quad 0x6e67696c612e206d,0x5f2038622e203420,0x726170616475635f,0x31315a5f5f32666d\n"
".quad 0x4c74694674736562,0x6c66364b50656e69,0x315b5f533374616f,0x090a7b090a295d32\n"
".quad 0x33752e206765722e,0x3e36323c72252032,0x206765722e090a3b,0x647225203436752e\n"
".quad 0x2e090a3b3e30343c,0x3233662e20676572,0x3e3138313c662520,0x206765722e090a3b\n"
".quad 0x702520646572702e,0x2f2f090a3b3e353c,0x5f616475635f5f20,0x61765f6c61636f6c\n"
".quad 0x5f32313037335f72,0x635f6e6f6e5f3231,0x6669645f74736e6f,0x2e090a30203d2066\n"
".quad 0x3909363109636f6c,0x57444c240a300932,0x5a5f5f6e69676562,0x6946747365623131\n"
".quad 0x364b50656e694c74,0x5f533374616f6c66,0x61702e646c090a3a,0x203436752e6d6172\n"
".quad 0x5b202c3164722509,0x6170616475635f5f,0x315a5f5f31666d72,0x7469467473656231\n"
".quad 0x66364b50656e694c,0x5d5f533374616f6c,0x732e766f6d090a3b,0x3264722509203436\n"
".quad 0x0a3b31647225202c,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3166\n"
".quad 0x666d726170616475,0x656231315a5f5f32,0x6e694c7469467473,0x616f6c66364b5065\n"
".quad 0x3b5d302b5f533374,0x33662e766f6d090a,0x202c326625092032,0x646c090a3b316625\n"
".quad 0x662e6d617261702e,0x2c33662509203233,0x616475635f5f5b20,0x5f5f32666d726170\n"
".quad 0x467473656231315a,0x4b50656e694c7469,0x533374616f6c6636,0x6d090a3b5d342b5f\n"
".quad 0x09203233662e766f,0x336625202c346625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c35662509,0x726170616475635f,0x31315a5f5f32666d,0x4c74694674736562\n"
".quad 0x6c66364b50656e69,0x382b5f533374616f,0x2e766f6d090a3b5d,0x3666250920323366\n"
".quad 0x090a3b356625202c,0x2e3233732e747663,0x3172250920323375,0x782e64697425202c\n"
".quad 0x732e766f6d090a3b,0x2c32722509203233,0x6573090a3b353120,0x33732e656c2e7074\n"
".quad 0x202c317025092032,0x327225202c317225,0x3170252140090a3b,0x4c24092061726220\n"
".quad 0x303534385f315f74,0x09636f6c2e090a3b,0x3009323131093631,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x202c317225202c33,0x747663090a3b3231,0x3233752e3436752e\n"
".quad 0x202c336472250920,0x6461090a3b337225,0x2509203436752e64,0x647225202c346472\n"
".quad 0x3b32647225202c33,0x3233662e646c090a,0x5b202c3766250920,0x3b5d302b34647225\n"
".quad 0x33662e766f6d090a,0x202c386625092032,0x3030303864336630,0x20202020203b3030\n"
".quad 0x36302e30202f2f09,0x2e6c756d090a3532,0x3966250920323366,0x25202c386625202c\n"
".quad 0x627573090a3b3266,0x662509203233662e,0x2c376625202c3031,0x6d090a3b39662520\n"
".quad 0x09203233662e766f,0x6625202c31316625,0x2e646c090a3b3031,0x3166250920323366\n"
".quad 0x346472255b202c32,0x6f6d090a3b5d342b,0x2509203233662e76,0x336630202c333166\n"
".quad 0x3b30303030303864,0x202f2f0920202020,0x090a353236302e30,0x203233662e6c756d\n"
".quad 0x25202c3431662509,0x346625202c333166,0x662e627573090a3b,0x3531662509203233\n"
".quad 0x202c32316625202c,0x6d090a3b34316625,0x09203233662e766f,0x6625202c36316625\n"
".quad 0x2e646c090a3b3531,0x3166250920323366,0x346472255b202c37,0x6f6d090a3b5d382b\n"
".quad 0x2509203233662e76,0x336630202c383166,0x3b30303030303864,0x202f2f0920202020\n"
".quad 0x090a353236302e30,0x203233662e6c756d,0x25202c3931662509,0x366625202c383166\n"
".quad 0x662e627573090a3b,0x3032662509203233,0x202c37316625202c,0x6d090a3b39316625\n"
".quad 0x09203233662e766f,0x6625202c31326625,0x5f744c240a3b3032,0x0a3a303534385f31\n"
".quad 0x6220317025214009,0x5f744c2409206172,0x0a3b323639385f31,0x363109636f6c2e09\n"
".quad 0x090a300939313109,0x6168732e61747663,0x203436752e646572,0x5f202c3564722509\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x35335f3831303733,0x6e6f635f6e6f6e5f\n"
".quad 0x7261766f635f7473,0x305f5f65636e6169,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x2c317225202c3472,0x747663090a3b3620,0x3233732e3436732e,0x202c366472250920\n"
".quad 0x756d090a3b347225,0x732e656469772e6c,0x3764722509203233,0x34202c347225202c\n"
".quad 0x752e646461090a3b,0x3864722509203436,0x202c35647225202c,0x6d090a3b37647225\n"
".quad 0x09203233662e766f,0x6625202c32326625,0x6c756d090a3b3131,0x662509203233662e\n"
".quad 0x32326625202c3332,0x0a3b32326625202c,0x203233662e747309,0x302b386472255b09\n"
".quad 0x3b33326625202c5d,0x3109636f6c2e090a,0x0a30093032310936,0x3233662e766f6d09\n"
".quad 0x202c343266250920,0x6d090a3b36316625,0x09203233662e6c75,0x6625202c35326625\n"
".quad 0x32326625202c3432,0x33662e7473090a3b,0x386472255b092032,0x326625202c5d342b\n"
".quad 0x636f6c2e090a3b35,0x0931323109363109,0x662e766f6d090a30,0x3632662509203233\n"
".quad 0x0a3b31326625202c,0x3233662e6c756d09,0x202c373266250920,0x6625202c36326625\n"
".quad 0x2e7473090a3b3232,0x72255b0920323366,0x25202c5d382b3864,0x6c2e090a3b373266\n"
".quad 0x323109363109636f,0x6c756d090a300932,0x662509203233662e,0x34326625202c3832\n"
".quad 0x0a3b34326625202c,0x203233662e747309,0x312b386472255b09,0x38326625202c5d32\n"
".quad 0x09636f6c2e090a3b,0x3009333231093631,0x33662e6c756d090a,0x2c39326625092032\n"
".quad 0x25202c3632662520,0x7473090a3b343266,0x255b09203233662e,0x2c5d36312b386472\n"
".quad 0x090a3b3932662520,0x09363109636f6c2e,0x6d090a3009343231,0x09203233662e6c75\n"
".quad 0x6625202c30336625,0x36326625202c3632,0x33662e7473090a3b,0x386472255b092032\n"
".quad 0x6625202c5d30322b,0x5f744c240a3b3033,0x0a3a323639385f31,0x68732e6174766309\n"
".quad 0x3436752e64657261,0x202c356472250920,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f38313037335f,0x6f635f6e6f6e5f35,0x61766f635f74736e,0x5f5f65636e616972\n"
".quad 0x636f6c2e090a3b30,0x0936323109363109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x3233732e766f6d09,0x38202c3572250920,0x5f315f744c240a3b,0x2f200a3a36383939\n"
".quad 0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3120656e696c2079,0x7473656e202c3632\n"
".quad 0x7470656420676e69,0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469\n"
".quad 0x6e6b6e75203a736e,0x746573090a6e776f,0x3233732e74672e70,0x25202c3270250920\n"
".quad 0x3b317225202c3572,0x203270252140090a,0x744c240920617262,0x32343230315f315f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36323120656e,0x62616c2064616568,0x744c242064656c65,0x0a363839395f315f\n"
".quad 0x363109636f6c2e09,0x090a300930333109,0x732e6f6c2e6c756d,0x2c36722509203233\n"
".quad 0x3b36202c31722520,0x36732e747663090a,0x2509203233732e34,0x367225202c396472\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x202c303164722509,0x0a3b34202c367225\n"
".quad 0x3436752e64646109,0x202c386472250920,0x7225202c35647225,0x646c090a3b303164\n"
".quad 0x662509203233662e,0x6472255b202c3133,0x61090a3b5d302b38,0x09203233732e6464\n"
".quad 0x357225202c377225,0x090a3b317225202c,0x732e6f6c2e6c756d,0x2c38722509203233\n"
".quad 0x3b36202c37722520,0x36732e747663090a,0x2509203233732e34,0x7225202c31316472\n"
".quad 0x2e6c756d090a3b38,0x3233732e65646977,0x2c32316472250920,0x3b34202c38722520\n"
".quad 0x36752e646461090a,0x3331647225092034,0x202c35647225202c,0x090a3b3231647225\n"
".quad 0x09203233662e646c,0x255b202c32336625,0x3b5d302b33316472,0x33662e646461090a\n"
".quad 0x2c33336625092032,0x25202c3133662520,0x7473090a3b323366,0x255b09203233662e\n"
".quad 0x202c5d302b386472,0x4c240a3b33336625,0x343230315f315f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363839395f315f74,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x7262203270252140,0x315f744c24092061,0x0a3b34353730315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36323120,0x6c6562616c206461,0x315f744c24206465,0x2e090a363839395f\n"
".quad 0x3109363109636f6c,0x756d090a30093133,0x3233732e6f6c2e6c,0x25202c3972250920\n"
".quad 0x090a3b36202c3172,0x2e3436732e747663,0x6472250920323373,0x3b397225202c3431\n"
".quad 0x69772e6c756d090a,0x09203233732e6564,0x25202c3531647225,0x090a3b34202c3972\n"
".quad 0x203436752e646461,0x25202c3864722509,0x647225202c356472,0x2e646c090a3b3531\n"
".quad 0x3366250920323366,0x386472255b202c34,0x6461090a3b5d342b,0x2509203233732e64\n"
".quad 0x357225202c303172,0x090a3b317225202c,0x732e6f6c2e6c756d,0x3131722509203233\n"
".quad 0x202c30317225202c,0x2e747663090a3b36,0x203233732e343673,0x202c363164722509\n"
".quad 0x6d090a3b31317225,0x2e656469772e6c75,0x6472250920323373,0x31317225202c3731\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x7225202c38316472,0x31647225202c3564\n"
".quad 0x662e646c090a3b37,0x3533662509203233,0x38316472255b202c,0x6461090a3b5d342b\n"
".quad 0x2509203233662e64,0x336625202c363366,0x3b35336625202c34,0x3233662e7473090a\n"
".quad 0x2b386472255b0920,0x36336625202c5d34,0x5f315f744c240a3b,0x200a3a3435373031\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363231,0x656c6562616c2064,0x5f315f744c242064,0x6162090a36383939\n"
".quad 0x0920636e79732e72,0x70252140090a3b30,0x2409206172622032,0x3231315f315f744c\n"
".quad 0x3c2f2f200a3b3636,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3839395f315f744c\n"
".quad 0x09636f6c2e090a36,0x3009323331093631,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x2c317225202c3231,0x747663090a3b3620,0x3233732e3436732e,0x2c39316472250920\n"
".quad 0x090a3b3231722520,0x656469772e6c756d,0x722509203233732e,0x317225202c303264\n"
".quad 0x61090a3b34202c32,0x09203436752e6464,0x7225202c38647225,0x32647225202c3564\n"
".quad 0x662e646c090a3b30,0x3733662509203233,0x2b386472255b202c,0x646461090a3b5d38\n"
".quad 0x722509203233732e,0x2c357225202c3331,0x6d090a3b31722520,0x33732e6f6c2e6c75\n"
".quad 0x2c34317225092032,0x36202c3331722520,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x25202c3132647225,0x756d090a3b343172,0x732e656469772e6c,0x3264722509203233\n"
".quad 0x2c34317225202c32,0x646461090a3b3420,0x722509203436752e,0x647225202c333264\n"
".quad 0x3232647225202c35,0x33662e646c090a3b,0x2c38336625092032,0x2b33326472255b20\n"
".quad 0x646461090a3b5d38,0x662509203233662e,0x37336625202c3933,0x0a3b38336625202c\n"
".quad 0x203233662e747309,0x382b386472255b09,0x3b39336625202c5d,0x315f315f744c240a\n"
".quad 0x2f200a3a36363231,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3632,0x64656c6562616c20,0x395f315f744c2420\n"
".quad 0x726162090a363839,0x300920636e79732e,0x3270252140090a3b,0x4c24092061726220\n"
".quad 0x373731315f315f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36323120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363839395f315f74,0x3109636f6c2e090a,0x0a30093333310936,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323373,0x202c317225202c35,0x2e747663090a3b36,0x203233732e343673\n"
".quad 0x202c343264722509,0x6d090a3b35317225,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x35317225202c3532,0x6461090a3b34202c,0x2509203436752e64,0x647225202c386472\n"
".quad 0x3532647225202c35,0x33662e646c090a3b,0x2c30346625092032,0x312b386472255b20\n"
".quad 0x646461090a3b5d32,0x722509203233732e,0x2c357225202c3631,0x6d090a3b31722520\n"
".quad 0x33732e6f6c2e6c75,0x2c37317225092032,0x36202c3631722520,0x732e747663090a3b\n"
".quad 0x09203233732e3436,0x25202c3632647225,0x756d090a3b373172,0x732e656469772e6c\n"
".quad 0x3264722509203233,0x2c37317225202c37,0x646461090a3b3420,0x722509203436752e\n"
".quad 0x647225202c383264,0x3732647225202c35,0x33662e646c090a3b,0x2c31346625092032\n"
".quad 0x2b38326472255b20,0x6461090a3b5d3231,0x2509203233662e64,0x346625202c323466\n"
".quad 0x3b31346625202c30,0x3233662e7473090a,0x2b386472255b0920,0x346625202c5d3231\n"
".quad 0x315f744c240a3b32,0x0a3a38373731315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x62090a363839395f,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x0920617262203270,0x32315f315f744c24,0x2f2f200a3b303932,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x39395f315f744c24,0x636f6c2e090a3638,0x0934333109363109\n"
".quad 0x6c2e6c756d090a30,0x2509203233732e6f,0x317225202c383172,0x7663090a3b36202c\n"
".quad 0x33732e3436732e74,0x3932647225092032,0x0a3b38317225202c,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x7225202c30336472,0x090a3b34202c3831,0x203436752e646461\n"
".quad 0x25202c3864722509,0x647225202c356472,0x2e646c090a3b3033,0x3466250920323366\n"
".quad 0x386472255b202c33,0x61090a3b5d36312b,0x09203233732e6464,0x7225202c39317225\n"
".quad 0x0a3b317225202c35,0x2e6f6c2e6c756d09,0x3272250920323373,0x2c39317225202c30\n"
".quad 0x747663090a3b3620,0x3233732e3436732e,0x2c31336472250920,0x090a3b3032722520\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x327225202c323364,0x61090a3b34202c30\n"
".quad 0x09203436752e6464,0x25202c3333647225,0x647225202c356472,0x2e646c090a3b3233\n"
".quad 0x3466250920323366,0x336472255b202c34,0x090a3b5d36312b33,0x203233662e646461\n"
".quad 0x25202c3534662509,0x346625202c333466,0x662e7473090a3b34,0x6472255b09203233\n"
".quad 0x25202c5d36312b38,0x744c240a3b353466,0x30393232315f315f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a363839395f315f,0x6e79732e72616209\n"
".quad 0x40090a3b30092063,0x6172622032702521,0x5f315f744c240920,0x200a3b3230383231\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363231,0x656c6562616c2064,0x5f315f744c242064,0x6c2e090a36383939\n"
".quad 0x333109363109636f,0x6c756d090a300935,0x203233732e6f6c2e,0x25202c3132722509\n"
".quad 0x090a3b36202c3172,0x2e3436732e747663,0x6472250920323373,0x31327225202c3433\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x202c353364722509,0x3b34202c31327225\n"
".quad 0x36752e646461090a,0x2c38647225092034,0x25202c3564722520,0x6c090a3b35336472\n"
".quad 0x2509203233662e64,0x72255b202c363466,0x0a3b5d30322b3864,0x3233732e64646109\n"
".quad 0x202c323272250920,0x317225202c357225,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x327225202c333272,0x63090a3b36202c32,0x732e3436732e7476,0x3364722509203233\n"
".quad 0x3b33327225202c36,0x69772e6c756d090a,0x09203233732e6564,0x25202c3733647225\n"
".quad 0x0a3b34202c333272,0x3436752e64646109,0x2c38336472250920,0x25202c3564722520\n"
".quad 0x6c090a3b37336472,0x2509203233662e64,0x72255b202c373466,0x3b5d30322b383364\n"
".quad 0x33662e646461090a,0x2c38346625092032,0x25202c3634662520,0x7473090a3b373466\n"
".quad 0x255b09203233662e,0x2c5d30322b386472,0x240a3b3834662520,0x3832315f315f744c\n"
".quad 0x3c2f2f200a3a3230,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3839395f315f744c\n"
".quad 0x732e726162090a36,0x0a3b300920636e79,0x363109636f6c2e09,0x090a300938323109\n"
".quad 0x203233732e726873,0x7225202c35722509,0x6d090a3b31202c35,0x09203233752e766f\n"
".quad 0x3b30202c34327225,0x672e70746573090a,0x2509203233732e74,0x2c357225202c3370\n"
".quad 0x090a3b3432722520,0x6172622033702540,0x5f315f744c240920,0x6c090a3b36383939\n"
".quad 0x6465726168732e64,0x203233662e34762e,0x252c393466257b09,0x313566252c303566\n"
".quad 0x5f5f5b202c7d5f2c,0x636f6c5f61647563,0x335f7261765f6c61,0x5f35335f38313037\n"
".quad 0x736e6f635f6e6f6e,0x697261766f635f74,0x2b305f5f65636e61,0x6f6c2e090a3b5d30\n"
".quad 0x0934350936310963,0x68732e646c090a30,0x3233662e64657261,0x202c323566250920\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38313037335f72,0x635f6e6f6e5f3533\n"
".quad 0x766f635f74736e6f,0x5f65636e61697261,0x0a3b5d32312b305f,0x3233662e766f6d09\n"
".quad 0x202c333566250920,0x3030303866336630,0x09202020203b3030,0x6d66090a31202f2f\n"
".quad 0x3233662e6e722e61,0x202c343566250920,0x6625202c33356625,0x32356625202c3035\n"
".quad 0x68732e646c090a3b,0x2e32762e64657261,0x66257b0920323366,0x7d363566252c3535\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x313037335f726176,0x6e6f6e5f35335f38\n"
".quad 0x635f74736e6f635f,0x636e61697261766f,0x5d36312b305f5f65,0x662e766f6d090a3b\n"
".quad 0x3735662509203233,0x303866336630202c,0x2020203b30303030,0x090a31202f2f0920\n"
".quad 0x662e6e722e616d66,0x3835662509203233,0x202c37356625202c,0x6625202c31356625\n"
".quad 0x766f6d090a3b3535,0x662509203233662e,0x66336630202c3935,0x203b303030303038\n"
".quad 0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e,0x39346625202c3036\n"
".quad 0x202c39356625202c,0x6d090a3b30356625,0x09203233662e766f,0x6630202c31366625\n"
".quad 0x3030303030386633,0x2f2f09202020203b,0x2e616d66090a3120,0x09203233662e6e72\n"
".quad 0x6625202c32366625,0x35356625202c3136,0x0a3b34356625202c,0x3233662e766f6d09\n"
".quad 0x202c333666250920,0x3030303866336630,0x09202020203b3030,0x6d66090a31202f2f\n"
".quad 0x3233662e6e722e61,0x202c343666250920,0x6625202c33366625,0x38356625202c3635\n"
".quad 0x662e766f6d090a3b,0x3536662509203233,0x303866336630202c,0x2020203b30303030\n"
".quad 0x090a31202f2f0920,0x662e6e722e616d66,0x3636662509203233,0x202c31356625202c\n"
".quad 0x6625202c35366625,0x78616d090a3b3036,0x662509203233662e,0x32366625202c3736\n"
".quad 0x0a3b36366625202c,0x3233662e78616d09,0x202c383666250920,0x6625202c34366625\n"
".quad 0x706372090a3b3736,0x203233662e6e722e,0x25202c3936662509,0x756d090a3b383666\n"
".quad 0x2509203233662e6c,0x366625202c303766,0x3b39366625202c32,0x33662e6c756d090a\n"
".quad 0x2c31376625092032,0x25202c3636662520,0x756d090a3b393666,0x2509203233662e6c\n"
".quad 0x366625202c323766,0x3b39366625202c34,0x33662e6c756d090a,0x2c33376625092032\n"
".quad 0x25202c3037662520,0x756d090a3b353566,0x2509203233662e6c,0x376625202c343766\n"
".quad 0x3b30356625202c30,0x33662e6c756d090a,0x2c35376625092032,0x25202c3037662520\n"
".quad 0x6d66090a3b323566,0x3233662e6e722e61,0x202c363766250920,0x6625202c31376625\n"
".quad 0x33376625202c3135,0x722e616d66090a3b,0x2509203233662e6e,0x346625202c373766\n"
".quad 0x2c31376625202c39,0x090a3b3437662520,0x662e6e722e616d66,0x3837662509203233\n"
".quad 0x202c31376625202c,0x6625202c30356625,0x616d66090a3b3537,0x203233662e6e722e\n"
".quad 0x25202c3937662509,0x356625202c323766,0x3b36376625202c36,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x31356625202c3038,0x202c32376625202c,0x66090a3b37376625\n"
".quad 0x33662e6e722e616d,0x2c31386625092032,0x25202c3237662520,0x376625202c353566\n"
".quad 0x2e78616d090a3b38,0x3866250920323366,0x2c30386625202c32,0x090a3b3138662520\n"
".quad 0x203233662e78616d,0x25202c3338662509,0x386625202c393766,0x2e706372090a3b32\n"
".quad 0x09203233662e6e72,0x6625202c34386625,0x6f6c2e090a3b3338,0x0930350936310963\n"
".quad 0x662e6c756d090a30,0x3538662509203233,0x202c39376625202c,0x6d090a3b34386625\n"
".quad 0x09203233662e6c75,0x6625202c36386625,0x34386625202c3038,0x662e6c756d090a3b\n"
".quad 0x3738662509203233,0x202c31386625202c,0x6d090a3b34386625,0x09203233662e6c75\n"
".quad 0x6625202c38386625,0x30356625202c3738,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x346625202c393866,0x2c36386625202c39,0x090a3b3838662520,0x662e6e722e616d66\n"
".quad 0x3039662509203233,0x202c31356625202c,0x6625202c35386625,0x6f6c2e090a3b3938\n"
".quad 0x0931350936310963,0x662e6c756d090a30,0x3139662509203233,0x202c37386625202c\n"
".quad 0x66090a3b32356625,0x33662e6e722e616d,0x2c32396625092032,0x25202c3638662520\n"
".quad 0x396625202c303566,0x2e616d66090a3b31,0x09203233662e6e72,0x6625202c33396625\n"
".quad 0x35356625202c3538,0x0a3b32396625202c,0x363109636f6c2e09,0x6d090a3009323509\n"
".quad 0x09203233662e6c75,0x6625202c34396625,0x35356625202c3738,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x386625202c353966,0x2c31356625202c36,0x090a3b3439662520\n"
".quad 0x662e6e722e616d66,0x3639662509203233,0x202c35386625202c,0x6625202c36356625\n"
".quad 0x6f6c2e090a3b3539,0x0938350936310963,0x662e78616d090a30,0x3739662509203233\n"
".quad 0x202c30396625202c,0x6d090a3b33396625,0x09203233662e7861,0x6625202c38396625\n"
".quad 0x36396625202c3739,0x722e706372090a3b,0x2509203233662e6e,0x396625202c393966\n"
".quad 0x2e6c756d090a3b38,0x3166250920323366,0x39396625202c3030,0x0a3b30396625202c\n"
".quad 0x3233662e6c756d09,0x2c31303166250920,0x25202c3939662520,0x756d090a3b333966\n"
".quad 0x2509203233662e6c,0x6625202c32303166,0x36396625202c3939,0x09636f6c2e090a3b\n"
".quad 0x0a30093035093631,0x3233662e6c756d09,0x2c33303166250920,0x202c313031662520\n"
".quad 0x66090a3b30356625,0x33662e6e722e616d,0x3430316625092032,0x202c39346625202c\n"
".quad 0x25202c3030316625,0x66090a3b33303166,0x33662e6e722e616d,0x3530316625092032\n"
".quad 0x202c31356625202c,0x25202c3230316625,0x2e090a3b34303166,0x3509363109636f6c\n"
".quad 0x6c756d090a300938,0x662509203233662e,0x316625202c363031,0x32356625202c3130\n"
".quad 0x662e6c756d090a3b,0x3031662509203233,0x3130316625202c37,0x0a3b35356625202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x30316625202c3830,0x2c30356625202c30\n"
".quad 0x0a3b363031662520,0x2e6e722e616d6609,0x3166250920323366,0x30316625202c3930\n"
".quad 0x2c31356625202c30,0x0a3b373031662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x30316625202c3031,0x2c35356625202c32,0x0a3b383031662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x30316625202c3131,0x2c36356625202c32,0x0a3b393031662520\n"
".quad 0x3233662e78616d09,0x2c32313166250920,0x202c303131662520,0x090a3b3530316625\n"
".quad 0x203233662e78616d,0x202c333131662509,0x25202c3131316625,0x72090a3b32313166\n"
".quad 0x33662e6e722e7063,0x3431316625092032,0x3b3331316625202c,0x33662e6c756d090a\n"
".quad 0x3531316625092032,0x2c3031316625202c,0x0a3b343131662520,0x3233662e6c756d09\n"
".quad 0x2c36313166250920,0x202c313131662520,0x090a3b3431316625,0x203233662e6c756d\n"
".quad 0x202c373131662509,0x25202c3431316625,0x2e090a3b35303166,0x3509363109636f6c\n"
".quad 0x6c756d090a300932,0x662509203233662e,0x316625202c383131,0x35356625202c3531\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c39313166,0x356625202c373131\n"
".quad 0x3831316625202c31,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c30323166\n"
".quad 0x356625202c363131,0x3931316625202c36,0x09636f6c2e090a3b,0x0a30093435093631\n"
".quad 0x3233662e6c756d09,0x2c31323166250920,0x202c353131662520,0x6d090a3b30356625\n"
".quad 0x09203233662e6c75,0x25202c3232316625,0x6625202c35313166,0x616d66090a3b3235\n"
".quad 0x203233662e6e722e,0x202c333231662509,0x6625202c39346625,0x316625202c373131\n"
".quad 0x616d66090a3b3132,0x203233662e6e722e,0x202c343231662509,0x25202c3731316625\n"
".quad 0x316625202c303566,0x616d66090a3b3232,0x203233662e6e722e,0x202c353231662509\n"
".quad 0x6625202c31356625,0x316625202c363131,0x616d66090a3b3332,0x203233662e6e722e\n"
".quad 0x202c363231662509,0x25202c3631316625,0x316625202c353566,0x78616d090a3b3432\n"
".quad 0x662509203233662e,0x316625202c373231,0x32316625202c3532,0x2e78616d090a3b36\n"
".quad 0x3166250920323366,0x32316625202c3832,0x3032316625202c37,0x722e706372090a3b\n"
".quad 0x2509203233662e6e,0x6625202c39323166,0x6c2e090a3b383231,0x383509363109636f\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x32316625202c3033,0x3932316625202c35\n"
".quad 0x662e6c756d090a3b,0x3331662509203233,0x3632316625202c31,0x3b3932316625202c\n"
".quad 0x3109636f6c2e090a,0x090a300930350936,0x203233662e6c756d,0x202c323331662509\n"
".quad 0x25202c3932316625,0x6d090a3b30323166,0x09203233662e6c75,0x25202c3333316625\n"
".quad 0x6625202c31333166,0x616d66090a3b3035,0x203233662e6e722e,0x202c343331662509\n"
".quad 0x6625202c39346625,0x316625202c303331,0x616d66090a3b3333,0x203233662e6e722e\n"
".quad 0x202c353331662509,0x6625202c31356625,0x316625202c323331,0x6f6c2e090a3b3433\n"
".quad 0x0931350936310963,0x662e6c756d090a30,0x3331662509203233,0x3133316625202c36\n"
".quad 0x0a3b32356625202c,0x2e6e722e616d6609,0x3166250920323366,0x33316625202c3733\n"
".quad 0x2c30356625202c30,0x0a3b363331662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x33316625202c3833,0x2c35356625202c32,0x0a3b373331662520,0x363109636f6c2e09\n"
".quad 0x6d090a3009323509,0x09203233662e6c75,0x25202c3933316625,0x6625202c31333166\n"
".quad 0x616d66090a3b3535,0x203233662e6e722e,0x202c303431662509,0x25202c3033316625\n"
".quad 0x316625202c313566,0x616d66090a3b3933,0x203233662e6e722e,0x202c313431662509\n"
".quad 0x25202c3233316625,0x316625202c363566,0x6f6c2e090a3b3034,0x0938350936310963\n"
".quad 0x662e78616d090a30,0x3431662509203233,0x3533316625202c32,0x3b3833316625202c\n"
".quad 0x33662e78616d090a,0x3334316625092032,0x2c3234316625202c,0x0a3b313431662520\n"
".quad 0x2e6e722e70637209,0x3166250920323366,0x34316625202c3434,0x2e6c756d090a3b33\n"
".quad 0x3166250920323366,0x34316625202c3534,0x3533316625202c34,0x662e6c756d090a3b\n"
".quad 0x3431662509203233,0x3434316625202c36,0x3b3833316625202c,0x33662e6c756d090a\n"
".quad 0x3734316625092032,0x2c3434316625202c,0x0a3b313431662520,0x363109636f6c2e09\n"
".quad 0x6d090a3009303509,0x09203233662e6c75,0x25202c3834316625,0x6625202c36343166\n"
".quad 0x616d66090a3b3035,0x203233662e6e722e,0x202c393431662509,0x6625202c39346625\n"
".quad 0x316625202c353431,0x616d66090a3b3834,0x203233662e6e722e,0x202c303531662509\n"
".quad 0x6625202c31356625,0x316625202c373431,0x6f6c2e090a3b3934,0x0938350936310963\n"
".quad 0x662e6c756d090a30,0x3531662509203233,0x3634316625202c31,0x0a3b32356625202c\n"
".quad 0x3233662e6c756d09,0x2c32353166250920,0x202c363431662520,0x66090a3b35356625\n"
".quad 0x33662e6e722e616d,0x3335316625092032,0x2c3534316625202c,0x25202c3035662520\n"
".quad 0x66090a3b31353166,0x33662e6e722e616d,0x3435316625092032,0x2c3534316625202c\n"
".quad 0x25202c3135662520,0x66090a3b32353166,0x33662e6e722e616d,0x3535316625092032\n"
".quad 0x2c3734316625202c,0x25202c3535662520,0x66090a3b33353166,0x33662e6e722e616d\n"
".quad 0x3635316625092032,0x2c3734316625202c,0x25202c3635662520,0x6d090a3b34353166\n"
".quad 0x09203233662e7861,0x25202c3735316625,0x6625202c35353166,0x616d090a3b303531\n"
".quad 0x2509203233662e78,0x6625202c38353166,0x316625202c363531,0x706372090a3b3735\n"
".quad 0x203233662e6e722e,0x202c393531662509,0x090a3b3835316625,0x203233662e6c756d\n"
".quad 0x202c303631662509,0x25202c3535316625,0x6d090a3b39353166,0x09203233662e6c75\n"
".quad 0x25202c3136316625,0x6625202c36353166,0x756d090a3b393531,0x2509203233662e6c\n"
".quad 0x6625202c32363166,0x316625202c393531,0x6f6c2e090a3b3035,0x0932350936310963\n"
".quad 0x662e6c756d090a30,0x3631662509203233,0x3036316625202c33,0x0a3b35356625202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x36316625202c3436,0x2c31356625202c32\n"
".quad 0x0a3b333631662520,0x2e6e722e616d6609,0x3166250920323366,0x36316625202c3536\n"
".quad 0x2c36356625202c31,0x0a3b343631662520,0x363109636f6c2e09,0x6d090a3009343509\n"
".quad 0x09203233662e6c75,0x25202c3636316625,0x6625202c30363166,0x6c756d090a3b3035\n"
".quad 0x662509203233662e,0x316625202c373631,0x32356625202c3036,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c38363166,0x36316625202c3934,0x3636316625202c32\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c39363166,0x356625202c323631\n"
".quad 0x3736316625202c30,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c30373166\n"
".quad 0x36316625202c3135,0x3836316625202c31,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c31373166,0x356625202c313631,0x3936316625202c35,0x662e78616d090a3b\n"
".quad 0x3731662509203233,0x3037316625202c32,0x3b3137316625202c,0x33662e78616d090a\n"
".quad 0x3337316625092032,0x2c3237316625202c,0x0a3b353631662520,0x2e6e722e70637209\n"
".quad 0x3166250920323366,0x37316625202c3437,0x636f6c2e090a3b33,0x3009383509363109\n"
".quad 0x33662e6c756d090a,0x3537316625092032,0x2c3037316625202c,0x0a3b343731662520\n"
".quad 0x3233662e6c756d09,0x2c36373166250920,0x202c313731662520,0x090a3b3437316625\n"
".quad 0x09363109636f6c2e,0x6d090a3009313431,0x09203233662e766f,0x25202c3737316625\n"
".quad 0x73090a3b35373166,0x2e6d617261702e74,0x5f5f5b0920323366,0x6674657261647563\n"
".quad 0x73656231315a5f5f,0x656e694c74694674,0x74616f6c66364b50,0x202c5d302b5f5333\n"
".quad 0x090a3b3737316625,0x203233662e766f6d,0x202c383731662509,0x090a3b3637316625\n"
".quad 0x6d617261702e7473,0x5f5b09203233662e,0x746572616475635f,0x656231315a5f5f66\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x2c5d342b5f533374,0x0a3b383731662520\n"
".quad 0x3233662e6c756d09,0x2c39373166250920,0x202c343731662520,0x090a3b3536316625\n"
".quad 0x6d617261702e7473,0x5f5b09203233662e,0x746572616475635f,0x656231315a5f5f66\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x2c5d382b5f533374,0x0a3b393731662520\n"
".quad 0x4c240a3b74657209,0x5a5f5f646e655744,0x6946747365623131,0x364b50656e694c74\n"
".quad 0x5f533374616f6c66,0x202f2f207d090a3a,0x7473656231315a5f,0x50656e694c746946\n"
".quad 0x3374616f6c66364b,0x69762e090a0a5f53,0x662e20656c626973,0x30315a5f20636e75\n"
".quad 0x6f6c6f4374726f73,0x206950664b507372,0x206d617261702e28,0x635f5f203436752e\n"
".quad 0x666d726170616475,0x6f7330315a5f5f31,0x73726f6c6f437472,0x2e202c6950664b50\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5f32666d72617061,0x74726f7330315a5f\n"
".quad 0x4b5073726f6c6f43,0x0a7b090a29695066,0x752e206765722e09,0x32363c7225203233\n"
".quad 0x6765722e090a3b3e,0x7225203436752e20,0x090a3b3e33313c64,0x33662e206765722e\n"
".quad 0x3e39313c66252032,0x206765722e090a3b,0x702520646572702e,0x6c2e090a3b3e383c\n"
".quad 0x363809373109636f,0x6257444c240a3009,0x315a5f5f6e696765,0x6c6f4374726f7330\n"
".quad 0x6950664b5073726f,0x61702e646c090a3a,0x203436752e6d6172,0x5b202c3164722509\n"
".quad 0x6170616475635f5f,0x315a5f5f31666d72,0x6c6f4374726f7330,0x6950664b5073726f\n"
".quad 0x2e766f6d090a3b5d,0x6472250920343673,0x3b31647225202c32,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5f5b202c33647225,0x726170616475635f,0x30315a5f5f32666d\n"
".quad 0x6f6c6f4374726f73,0x5d6950664b507372,0x732e766f6d090a3b,0x3464722509203436\n"
".quad 0x0a3b33647225202c,0x3233752e766f6d09,0x25202c3172250920,0x090a3b782e646974\n"
".quad 0x203233752e766f6d,0x3b30202c32722509,0x6e2e70746573090a,0x2509203233752e65\n"
".quad 0x2c317225202c3170,0x40090a3b32722520,0x2061726220317025,0x375f325f744c2409\n"
".quad 0x6f6d090a3b303731,0x2509203233732e76,0x240a3b30202c3372,0x3931385f325f744c\n"
".quad 0x6c3c2f2f200a3a34,0x6f6f4c203e706f6f,0x6c2079646f622070,0x202c363820656e69\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x746172657469202c,0x3631203a736e6f69\n"
".quad 0x3109636f6c2e090a,0x090a300938390937,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x0a3b337225202c35,0x3436752e64646109,0x202c366472250920,0x7225202c35647225\n"
".quad 0x2e646c090a3b3264,0x3166250920323366,0x2b366472255b202c,0x2e646c090a3b5d30\n"
".quad 0x3266250920323366,0x2b326472255b202c,0x6573090a3b5d3635,0x3233752e746c2e74\n"
".quad 0x722509203233662e,0x202c326625202c34,0x656e090a3b316625,0x2509203233732e67\n"
".quad 0x3b347225202c3572,0x3233662e646c090a,0x5b202c3366250920,0x5d30362b32647225\n"
".quad 0x6c2e746573090a3b,0x33662e3233752e74,0x202c367225092032,0x316625202c336625\n"
".quad 0x732e67656e090a3b,0x2c37722509203233,0x61090a3b36722520,0x09203233732e6464\n"
".quad 0x357225202c387225,0x090a3b377225202c,0x09203233662e646c,0x72255b202c346625\n"
".quad 0x0a3b5d38342b3264,0x2e746c2e74657309,0x203233662e323375,0x6625202c39722509\n"
".quad 0x0a3b316625202c34,0x3233732e67656e09,0x202c303172250920,0x646c090a3b397225\n"
".quad 0x662509203233662e,0x326472255b202c35,0x73090a3b5d32352b,0x33752e746c2e7465\n"
".quad 0x2509203233662e32,0x356625202c313172,0x090a3b316625202c,0x203233732e67656e\n"
".quad 0x25202c3231722509,0x6461090a3b313172,0x2509203233732e64,0x317225202c333172\n"
".quad 0x3b32317225202c30,0x3233662e646c090a,0x5b202c3666250920,0x5d30342b32647225\n"
".quad 0x6c2e746573090a3b,0x33662e3233752e74,0x2c34317225092032,0x6625202c36662520\n"
".quad 0x2e67656e090a3b31,0x3172250920323373,0x3b34317225202c35,0x3233662e646c090a\n"
".quad 0x5b202c3766250920,0x5d34342b32647225,0x6c2e746573090a3b,0x33662e3233752e74\n"
".quad 0x2c36317225092032,0x6625202c37662520,0x2e67656e090a3b31,0x3172250920323373\n"
".quad 0x3b36317225202c37,0x33732e646461090a,0x2c38317225092032,0x25202c3531722520\n"
".quad 0x646c090a3b373172,0x662509203233662e,0x326472255b202c38,0x6573090a3b5d302b\n"
".quad 0x3233752e746c2e74,0x722509203233662e,0x2c386625202c3931,0x6e090a3b31662520\n"
".quad 0x09203233732e6765,0x7225202c30327225,0x2e646c090a3b3931,0x3966250920323366\n"
".quad 0x2b326472255b202c,0x746573090a3b5d34,0x2e3233752e746c2e,0x3272250920323366\n"
".quad 0x202c396625202c31,0x656e090a3b316625,0x2509203233732e67,0x327225202c323272\n"
".quad 0x2e646461090a3b31,0x3272250920323373,0x2c30327225202c33,0x090a3b3232722520\n"
".quad 0x09203233662e646c,0x255b202c30316625,0x0a3b5d382b326472,0x2e746c2e74657309\n"
".quad 0x203233662e323375,0x25202c3432722509,0x316625202c303166,0x732e67656e090a3b\n"
".quad 0x3532722509203233,0x0a3b34327225202c,0x203233662e646c09,0x5b202c3131662509\n"
".quad 0x5d32312b32647225,0x6c2e746573090a3b,0x33662e3233752e74,0x2c36327225092032\n"
".quad 0x25202c3131662520,0x67656e090a3b3166,0x722509203233732e,0x36327225202c3732\n"
".quad 0x732e646461090a3b,0x3832722509203233,0x202c35327225202c,0x6c090a3b37327225\n"
".quad 0x2509203233662e64,0x72255b202c323166,0x0a3b5d36312b3264,0x2e746c2e74657309\n"
".quad 0x203233662e323375,0x25202c3932722509,0x316625202c323166,0x732e67656e090a3b\n"
".quad 0x3033722509203233,0x0a3b39327225202c,0x203233662e646c09,0x5b202c3331662509\n"
".quad 0x5d30322b32647225,0x6c2e746573090a3b,0x33662e3233752e74,0x2c31337225092032\n"
".quad 0x25202c3331662520,0x67656e090a3b3166,0x722509203233732e,0x31337225202c3233\n"
".quad 0x732e646461090a3b,0x3333722509203233,0x202c30337225202c,0x6c090a3b32337225\n"
".quad 0x2509203233662e64,0x72255b202c343166,0x0a3b5d34322b3264,0x2e746c2e74657309\n"
".quad 0x203233662e323375,0x25202c3433722509,0x316625202c343166,0x732e67656e090a3b\n"
".quad 0x3533722509203233,0x0a3b34337225202c,0x203233662e646c09,0x5b202c3531662509\n"
".quad 0x5d38322b32647225,0x6c2e746573090a3b,0x33662e3233752e74,0x2c36337225092032\n"
".quad 0x25202c3531662520,0x67656e090a3b3166,0x722509203233732e,0x36337225202c3733\n"
".quad 0x732e646461090a3b,0x3833722509203233,0x202c35337225202c,0x6c090a3b37337225\n"
".quad 0x2509203233662e64,0x72255b202c363166,0x0a3b5d32332b3264,0x2e746c2e74657309\n"
".quad 0x203233662e323375,0x25202c3933722509,0x316625202c363166,0x732e67656e090a3b\n"
".quad 0x3034722509203233,0x0a3b39337225202c,0x203233662e646c09,0x5b202c3731662509\n"
".quad 0x5d36332b32647225,0x6c2e746573090a3b,0x33662e3233752e74,0x2c31347225092032\n"
".quad 0x25202c3731662520,0x67656e090a3b3166,0x722509203233732e,0x31347225202c3234\n"
".quad 0x732e646461090a3b,0x3334722509203233,0x202c30347225202c,0x61090a3b32347225\n"
".quad 0x09203233732e6464,0x7225202c34347225,0x33347225202c3833,0x732e646461090a3b\n"
".quad 0x3534722509203233,0x202c33337225202c,0x61090a3b34347225,0x09203233732e6464\n"
".quad 0x7225202c36347225,0x35347225202c3832,0x732e646461090a3b,0x3734722509203233\n"
".quad 0x202c33327225202c,0x61090a3b36347225,0x09203233732e6464,0x7225202c38347225\n"
".quad 0x37347225202c3831,0x732e646461090a3b,0x3934722509203233,0x202c33317225202c\n"
".quad 0x61090a3b38347225,0x09203233732e6464,0x7225202c30357225,0x3b39347225202c38\n"
".quad 0x36752e646461090a,0x2c37647225092034,0x25202c3564722520,0x7473090a3b346472\n"
".quad 0x255b09203233732e,0x202c5d302b376472,0x61090a3b30357225,0x09203233752e6464\n"
".quad 0x337225202c337225,0x6f6d090a3b34202c,0x2509203233752e76,0x3b3436202c313572\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x2c337225202c3270,0x090a3b3135722520\n"
".quad 0x6172622032702540,0x5f325f744c240920,0x6d090a3b34393138,0x09203233732e766f\n"
".quad 0x3b30202c32357225,0x395f325f744c240a,0x2f2f200a3a383132,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x383920656e696c20,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x72657469202c3120,0x203a736e6f697461,0x2e766f6d090a3531,0x3572250920323373\n"
".quad 0x4c240a3b30202c33,0x363839395f325f74,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x6e202c383920656e,0x6420676e69747365,0x2c32203a68747065\n"
".quad 0x6974617265746920,0x0a3631203a736e6f,0x373109636f6c2e09,0x090a300936303109\n"
".quad 0x2e656c2e70746573,0x3370250920323373,0x202c33357225202c,0x40090a3b32357225\n"
".quad 0x2061726220337025,0x315f325f744c2409,0x2f200a3b30313031,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3920656e696c2079,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x39395f325f744c24,0x2e6c756d090a3638,0x09203233752e6f6c\n"
".quad 0x7225202c34357225,0x090a3b34202c3335,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x3b34357225202c38,0x36752e646461090a,0x2c39647225092034,0x25202c3864722520\n"
".quad 0x646c090a3b346472,0x722509203233732e,0x6472255b202c3535,0x6d090a3b5d302b39\n"
".quad 0x33752e6f6c2e6c75,0x2c36357225092032,0x34202c3235722520,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3031647225,0x6461090a3b363572,0x2509203436752e64\n"
".quad 0x7225202c31316472,0x647225202c303164,0x732e646c090a3b34,0x3735722509203233\n"
".quad 0x31316472255b202c,0x6573090a3b5d302b,0x33732e656e2e7074,0x202c347025092032\n"
".quad 0x7225202c37357225,0x702540090a3b3535,0x2409206172622034,0x3031315f325f744c\n"
".quad 0x3c2f2f200a3b3031,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c383920656e696c,0x616c206461656820,0x4c242064656c6562,0x363839395f325f74\n"
".quad 0x33732e646461090a,0x2c38357225092032,0x31202c3535722520,0x33732e7473090a3b\n"
".quad 0x396472255b092032,0x357225202c5d302b,0x325f744c240a3b38,0x0a3a30313031315f\n"
".quad 0x3536365f325f4c24,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x0a363839395f325f,0x3233732e64646109,0x202c333572250920,0x3b31202c33357225\n"
".quad 0x33752e766f6d090a,0x2c39357225092032,0x6573090a3b363120,0x33732e656e2e7074\n"
".quad 0x202c357025092032,0x7225202c33357225,0x702540090a3b3935,0x2409206172622035\n"
".quad 0x3839395f325f744c,0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x0a383132395f325f,0x3233732e64646109,0x202c323572250920,0x3b31202c32357225\n"
".quad 0x33752e766f6d090a,0x2c30367225092032,0x6573090a3b353120,0x33732e656e2e7074\n"
".quad 0x202c367025092032,0x7225202c32357225,0x702540090a3b3036,0x2409206172622036\n"
".quad 0x3132395f325f744c,0x325f744c240a3b38,0x090a3a303731375f,0x09373109636f6c2e\n"
".quad 0x72090a3009303331,0x57444c240a3b7465,0x30315a5f5f646e65,0x6f6c6f4374726f73\n"
".quad 0x3a6950664b507372,0x5f202f2f207d090a,0x4374726f7330315a,0x664b5073726f6c6f\n"
".quad 0x6168732e090a6950,0x696c612e20646572,0x622e203631206e67,0x616475635f5f2038\n"
".quad 0x765f6c61636f6c5f,0x31343337335f7261,0x5f6e6f6e5f35335f,0x70645f74736e6f63\n"
".quad 0x5d34365b335f5f73,0x7369762e090a0a3b,0x75662e20656c6269,0x6c34315a5f20636e\n"
".quad 0x726f6c6f4364616f,0x6a4b506b636f6c42,0x3374616f6c663650,0x2e282069505f3253\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5f31666d72617061,0x64616f6c34315a5f\n"
".quad 0x6f6c42726f6c6f43,0x6636506a4b506b63,0x5f32533374616f6c,0x7261702e202c6950\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x315a5f5f32666d72,0x6c6f4364616f6c34\n"
".quad 0x506b636f6c42726f,0x616f6c6636506a4b,0x2c69505f32533374,0x206d617261702e20\n"
".quad 0x635f5f203436752e,0x666d726170616475,0x6f6c34315a5f5f33,0x42726f6c6f436461\n"
".quad 0x506a4b506b636f6c,0x533374616f6c6636,0x702e202c69505f32,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x5f5f34666d726170,0x4364616f6c34315a,0x636f6c42726f6c6f\n"
".quad 0x6c6636506a4b506b,0x505f32533374616f,0x2e090a7b090a2969,0x3233752e20676572\n"
".quad 0x3e3831313c722520,0x206765722e090a3b,0x647225203436752e,0x2e090a3b3e34383c\n"
".quad 0x3233662e20676572,0x3e3635323c662520,0x206765722e090a3b,0x702520646572702e\n"
".quad 0x2f090a3b3e31313c,0x616475635f5f202f,0x765f6c61636f6c5f,0x33343337335f7261\n"
".quad 0x5f6e6f6e5f32315f,0x6d745f74736e6f63,0x090a3231203d2070,0x6475635f5f202f2f\n"
".quad 0x5f6c61636f6c5f61,0x313037335f726176,0x6e6f6e5f32315f32,0x645f74736e6f635f\n"
".quad 0x0a30203d20666669,0x373109636f6c2e09,0x240a300937333109,0x6e6967656257444c\n"
".quad 0x616f6c34315a5f5f,0x6c42726f6c6f4364,0x36506a4b506b636f,0x32533374616f6c66\n"
".quad 0x646c090a3a69505f,0x752e6d617261702e,0x3164722509203436,0x6475635f5f5b202c\n"
".quad 0x5f31666d72617061,0x64616f6c34315a5f,0x6f6c42726f6c6f43,0x6636506a4b506b63\n"
".quad 0x5f32533374616f6c,0x6f6d090a3b5d6950,0x2509203436732e76,0x647225202c326472\n"
".quad 0x702e646c090a3b31,0x3436752e6d617261,0x202c336472250920,0x70616475635f5f5b\n"
".quad 0x5a5f5f32666d7261,0x6f4364616f6c3431,0x6b636f6c42726f6c,0x6f6c6636506a4b50\n"
".quad 0x69505f3253337461,0x2e766f6d090a3b5d,0x6472250920343673,0x3b33647225202c34\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x5f5b202c35647225,0x726170616475635f\n"
".quad 0x34315a5f5f33666d,0x6f6c6f4364616f6c,0x4b506b636f6c4272,0x74616f6c6636506a\n"
".quad 0x3b5d69505f325333,0x36732e766f6d090a,0x2c36647225092034,0x090a3b3564722520\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3764,0x666d726170616475\n"
".quad 0x6f6c34315a5f5f34,0x42726f6c6f436461,0x506a4b506b636f6c,0x533374616f6c6636\n"
".quad 0x090a3b5d69505f32,0x203436732e766f6d,0x25202c3864722509,0x7663090a3b376472\n"
".quad 0x33752e3233732e74,0x202c317225092032,0x0a3b782e64697425,0x3233732e766f6d09\n"
".quad 0x31202c3272250920,0x70746573090a3b35,0x203233732e656c2e,0x7225202c31702509\n"
".quad 0x0a3b327225202c31,0x6220317025214009,0x5f744c2409206172,0x3b34373232325f33\n"
".quad 0x3109636f6c2e090a,0x0a30093834310937,0x3233732e74766309,0x722509203233752e\n"
".quad 0x6961746325202c33,0x756d090a3b782e64,0x3233732e6f6c2e6c,0x25202c3472250920\n"
".quad 0x0a3b3631202c3372,0x3233732e64646109,0x25202c3572250920,0x3b347225202c3172\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x202c357225202c36,0x2e747663090a3b34\n"
".quad 0x203233752e343675,0x25202c3964722509,0x646461090a3b3672,0x722509203436752e\n"
".quad 0x647225202c303164,0x3b32647225202c39,0x3233752e646c090a,0x5b202c3772250920\n"
".quad 0x5d302b3031647225,0x09636f6c2e090a3b,0x3009303531093731,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x202c317225202c38,0x747663090a3b3231,0x3233752e3436752e\n"
".quad 0x2c31316472250920,0x61090a3b38722520,0x09203436752e6464,0x25202c3231647225\n"
".quad 0x7225202c31316472,0x646e61090a3b3464,0x722509203233622e,0x202c377225202c39\n"
".quad 0x7663090a3b353532,0x3233662e6e722e74,0x662509203233752e,0x0a3b397225202c31\n"
".quad 0x3233662e766f6d09,0x30202c3266250920,0x3830383038623366,0x0920202020203b31\n"
".quad 0x3330302e30202f2f,0x6d090a3735313239,0x09203233662e6c75,0x316625202c336625\n"
".quad 0x090a3b326625202c,0x09203233662e7473,0x302b32316472255b,0x0a3b336625202c5d\n"
".quad 0x373109636f6c2e09,0x090a300931353109,0x203233622e6c6873,0x25202c3031722509\n"
".quad 0x0a3b3631202c3772,0x3233752e72687309,0x202c313172250920,0x3432202c30317225\n"
".quad 0x722e747663090a3b,0x33752e3233662e6e,0x202c346625092032,0x6d090a3b31317225\n"
".quad 0x09203233662e766f,0x336630202c356625,0x3b31383038303862,0x2f2f092020202020\n"
".quad 0x32393330302e3020,0x6c756d090a373531,0x662509203233662e,0x202c346625202c36\n"
".quad 0x7473090a3b356625,0x255b09203233662e,0x2c5d342b32316472,0x2e090a3b36662520\n"
".quad 0x3109373109636f6c,0x6873090a30093235,0x2509203233622e6c,0x377225202c323172\n"
".quad 0x6873090a3b38202c,0x2509203233752e72,0x317225202c333172,0x090a3b3432202c32\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x317225202c376625,0x2e766f6d090a3b33\n"
".quad 0x3866250920323366,0x303862336630202c,0x2020203b31383038,0x2e30202f2f092020\n"
".quad 0x3735313239333030,0x33662e6c756d090a,0x202c396625092032,0x386625202c376625\n"
".quad 0x33662e7473090a3b,0x316472255b092032,0x6625202c5d382b32,0x335f744c240a3b39\n"
".quad 0x0a3a34373232325f,0x373109636f6c2e09,0x090a300936353109,0x636e79732e726162\n"
".quad 0x2140090a3b300920,0x2061726220317025,0x325f335f744c2409,0x2e090a3b36383732\n"
".quad 0x3109373109636f6c,0x756d090a30093036,0x3233752e6f6c2e6c,0x202c343172250920\n"
".quad 0x3b3231202c317225,0x36752e747663090a,0x2509203233752e34,0x7225202c33316472\n"
".quad 0x646461090a3b3431,0x722509203436752e,0x647225202c323164,0x34647225202c3331\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x3331647225202c34,0x0a3b36647225202c\n"
".quad 0x203233662e646c09,0x5b202c3031662509,0x5d302b3231647225,0x33662e7473090a3b\n"
".quad 0x316472255b092032,0x6625202c5d302b34,0x2e646c090a3b3031,0x3166250920323366\n"
".quad 0x316472255b202c31,0x73090a3b5d342b32,0x5b09203233662e74,0x5d342b3431647225\n"
".quad 0x0a3b31316625202c,0x203233662e646c09,0x5b202c3231662509,0x5d382b3231647225\n"
".quad 0x33662e7473090a3b,0x316472255b092032,0x6625202c5d382b34,0x5f744c240a3b3231\n"
".quad 0x3a36383732325f33,0x79732e726162090a,0x090a3b300920636e,0x7262203170252140\n"
".quad 0x335f744c24092061,0x0a3b38393233325f,0x3233622e726f7809,0x202c353172250920\n"
".quad 0x0a3b38202c317225,0x2e6f6c2e6c756d09,0x3172250920323375,0x2c35317225202c36\n"
".quad 0x7663090a3b323120,0x33752e3436752e74,0x3531647225092032,0x0a3b36317225202c\n"
".quad 0x3436752e64646109,0x2c36316472250920,0x202c353164722520,0x6c090a3b36647225\n"
".quad 0x2509203233662e64,0x72255b202c333166,0x0a3b5d342b363164,0x203233662e646c09\n"
".quad 0x5b202c3431662509,0x5d382b3631647225,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x317225202c373172,0x63090a3b3231202c,0x752e3436752e7476,0x3164722509203233\n"
".quad 0x3b37317225202c37,0x36752e646461090a,0x3431647225092034,0x2c3731647225202c\n"
".quad 0x090a3b3664722520,0x09203233662e646c,0x255b202c35316625,0x3b5d302b36316472\n"
".quad 0x3233662e646c090a,0x202c363166250920,0x302b34316472255b,0x2e646461090a3b5d\n"
".quad 0x3166250920323366,0x2c35316625202c37,0x090a3b3631662520,0x09203233662e7473\n"
".quad 0x302b34316472255b,0x3b37316625202c5d,0x3233662e646c090a,0x202c383166250920\n"
".quad 0x342b34316472255b,0x2e646461090a3b5d,0x3166250920323366,0x2c38316625202c39\n"
".quad 0x090a3b3331662520,0x09203233662e7473,0x342b34316472255b,0x3b39316625202c5d\n"
".quad 0x3233662e646c090a,0x202c303266250920,0x382b34316472255b,0x2e646461090a3b5d\n"
".quad 0x3266250920323366,0x2c30326625202c31,0x090a3b3431662520,0x09203233662e7473\n"
".quad 0x382b34316472255b,0x3b31326625202c5d,0x325f335f744c240a,0x62090a3a38393233\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x33325f335f744c24\n"
".quad 0x6f78090a3b303138,0x2509203233622e72,0x317225202c383172,0x756d090a3b34202c\n"
".quad 0x3233752e6f6c2e6c,0x202c393172250920,0x3231202c38317225,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3831647225,0x6461090a3b393172,0x2509203436752e64\n"
".quad 0x7225202c39316472,0x647225202c383164,0x662e646c090a3b36,0x3232662509203233\n"
".quad 0x39316472255b202c,0x646c090a3b5d342b,0x662509203233662e,0x6472255b202c3332\n"
".quad 0x090a3b5d382b3931,0x752e6f6c2e6c756d,0x3032722509203233,0x31202c317225202c\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x202c303264722509,0x61090a3b30327225\n"
".quad 0x09203436752e6464,0x25202c3431647225,0x7225202c30326472,0x2e646c090a3b3664\n"
".quad 0x3266250920323366,0x316472255b202c34,0x6c090a3b5d302b39,0x2509203233662e64\n"
".quad 0x72255b202c353266,0x0a3b5d302b343164,0x3233662e64646109,0x202c363266250920\n"
".quad 0x6625202c34326625,0x2e7473090a3b3532,0x72255b0920323366,0x202c5d302b343164\n"
".quad 0x6c090a3b36326625,0x2509203233662e64,0x72255b202c373266,0x0a3b5d342b343164\n"
".quad 0x3233662e64646109,0x202c383266250920,0x6625202c37326625,0x2e7473090a3b3232\n"
".quad 0x72255b0920323366,0x202c5d342b343164,0x6c090a3b38326625,0x2509203233662e64\n"
".quad 0x72255b202c393266,0x0a3b5d382b343164,0x3233662e64646109,0x202c303366250920\n"
".quad 0x6625202c39326625,0x2e7473090a3b3332,0x72255b0920323366,0x202c5d382b343164\n"
".quad 0x4c240a3b30336625,0x313833325f335f74,0x2e726162090a3a30,0x3b300920636e7973\n"
".quad 0x203170252140090a,0x744c240920617262,0x32323334325f335f,0x622e726f78090a3b\n"
".quad 0x3132722509203233,0x32202c317225202c,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x327225202c323272,0x090a3b3231202c31,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x32327225202c3132,0x752e646461090a3b,0x3264722509203436,0x3132647225202c32\n"
".quad 0x0a3b36647225202c,0x203233662e646c09,0x5b202c3133662509,0x5d342b3232647225\n"
".quad 0x33662e646c090a3b,0x2c32336625092032,0x2b32326472255b20,0x6c756d090a3b5d38\n"
".quad 0x203233752e6f6c2e,0x25202c3332722509,0x0a3b3231202c3172,0x3436752e74766309\n"
".quad 0x722509203233752e,0x327225202c333264,0x2e646461090a3b33,0x6472250920343675\n"
".quad 0x32647225202c3431,0x3b36647225202c33,0x3233662e646c090a,0x202c333366250920\n"
".quad 0x302b32326472255b,0x662e646c090a3b5d,0x3433662509203233,0x34316472255b202c\n"
".quad 0x6461090a3b5d302b,0x2509203233662e64,0x336625202c353366,0x3b34336625202c33\n"
".quad 0x3233662e7473090a,0x34316472255b0920,0x336625202c5d302b,0x662e646c090a3b35\n"
".quad 0x3633662509203233,0x34316472255b202c,0x6461090a3b5d342b,0x2509203233662e64\n"
".quad 0x336625202c373366,0x3b31336625202c36,0x3233662e7473090a,0x34316472255b0920\n"
".quad 0x336625202c5d342b,0x662e646c090a3b37,0x3833662509203233,0x34316472255b202c\n"
".quad 0x6461090a3b5d382b,0x2509203233662e64,0x336625202c393366,0x3b32336625202c38\n"
".quad 0x3233662e7473090a,0x34316472255b0920,0x336625202c5d382b,0x335f744c240a3b39\n"
".quad 0x0a3a32323334325f,0x6e79732e72616209,0x40090a3b30092063,0x6172622031702521\n"
".quad 0x5f335f744c240920,0x090a3b3433383432,0x203233622e726f78,0x25202c3432722509\n"
".quad 0x090a3b31202c3172,0x752e6f6c2e6c756d,0x3532722509203233,0x202c34327225202c\n"
".quad 0x747663090a3b3231,0x3233752e3436752e,0x2c34326472250920,0x090a3b3532722520\n"
".quad 0x203436752e646461,0x202c353264722509,0x25202c3432647225,0x646c090a3b366472\n"
".quad 0x662509203233662e,0x6472255b202c3034,0x090a3b5d342b3532,0x09203233662e646c\n"
".quad 0x255b202c31346625,0x3b5d382b35326472,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x2c317225202c3632,0x7663090a3b323120,0x33752e3436752e74,0x3632647225092032\n"
".quad 0x0a3b36327225202c,0x3436752e64646109,0x2c34316472250920,0x202c363264722520\n"
".quad 0x6c090a3b36647225,0x2509203233662e64,0x72255b202c323466,0x0a3b5d302b353264\n"
".quad 0x203233662e646c09,0x5b202c3334662509,0x5d302b3431647225,0x662e646461090a3b\n"
".quad 0x3434662509203233,0x202c32346625202c,0x73090a3b33346625,0x5b09203233662e74\n"
".quad 0x5d302b3431647225,0x0a3b34346625202c,0x203233662e646c09,0x5b202c3534662509\n"
".quad 0x5d342b3431647225,0x662e646461090a3b,0x3634662509203233,0x202c35346625202c\n"
".quad 0x73090a3b30346625,0x5b09203233662e74,0x5d342b3431647225,0x0a3b36346625202c\n"
".quad 0x203233662e646c09,0x5b202c3734662509,0x5d382b3431647225,0x662e646461090a3b\n"
".quad 0x3834662509203233,0x202c37346625202c,0x73090a3b31346625,0x5b09203233662e74\n"
".quad 0x5d382b3431647225,0x0a3b38346625202c,0x34325f335f744c24,0x6162090a3a343338\n"
".quad 0x0920636e79732e72,0x636f6c2e090a3b30,0x0931363109373109,0x3170252140090a30\n"
".quad 0x4c24092061726220,0x353835325f335f74,0x636f6c2e090a3b38,0x0932313109363109\n"
".quad 0x6c2e6c756d090a30,0x2509203233752e6f,0x317225202c373272,0x63090a3b3231202c\n"
".quad 0x752e3436752e7476,0x3264722509203233,0x3b37327225202c37,0x36752e646461090a\n"
".quad 0x3231647225092034,0x2c3732647225202c,0x090a3b3464722520,0x09203233662e646c\n"
".quad 0x255b202c39346625,0x3b5d302b32316472,0x3233662e646c090a,0x202c303566250920\n"
".quad 0x5d302b366472255b,0x662e766f6d090a3b,0x3135662509203233,0x303864336630202c\n"
".quad 0x2020203b30303030,0x302e30202f2f0920,0x6c756d090a353236,0x662509203233662e\n"
".quad 0x30356625202c3235,0x0a3b31356625202c,0x3233662e62757309,0x202c333566250920\n"
".quad 0x6625202c39346625,0x766f6d090a3b3235,0x662509203233662e,0x33356625202c3435\n"
".quad 0x33662e646c090a3b,0x2c35356625092032,0x2b32316472255b20,0x2e646c090a3b5d34\n"
".quad 0x3566250920323366,0x366472255b202c36,0x6f6d090a3b5d342b,0x2509203233662e76\n"
".quad 0x336630202c373566,0x3b30303030303864,0x202f2f0920202020,0x090a353236302e30\n"
".quad 0x203233662e6c756d,0x25202c3835662509,0x356625202c363566,0x2e627573090a3b37\n"
".quad 0x3566250920323366,0x2c35356625202c39,0x090a3b3835662520,0x203233662e766f6d\n"
".quad 0x25202c3036662509,0x646c090a3b393566,0x662509203233662e,0x6472255b202c3136\n"
".quad 0x090a3b5d382b3231,0x09203233662e646c,0x255b202c32366625,0x0a3b5d382b366472\n"
".quad 0x3233662e766f6d09,0x202c333666250920,0x3030303864336630,0x09202020203b3030\n"
".quad 0x3236302e30202f2f,0x662e6c756d090a35,0x3436662509203233,0x202c32366625202c\n"
".quad 0x73090a3b33366625,0x09203233662e6275,0x6625202c35366625,0x34366625202c3136\n"
".quad 0x662e766f6d090a3b,0x3636662509203233,0x0a3b35366625202c,0x35325f335f744c24\n"
".quad 0x2140090a3a363433,0x2061726220317025,0x325f335f744c2409,0x2e090a3b38353835\n"
".quad 0x3109363109636f6c,0x7663090a30093931,0x65726168732e6174,0x2509203436752e64\n"
".quad 0x5f5f202c38326472,0x636f6c5f61647563,0x335f7261765f6c61,0x5f35335f38313037\n"
".quad 0x736e6f635f6e6f6e,0x697261766f635f74,0x3b305f5f65636e61,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x2c317225202c3832,0x747663090a3b3620,0x3233732e3436732e\n"
".quad 0x2c39326472250920,0x090a3b3832722520,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x327225202c303364,0x61090a3b34202c38,0x09203436752e6464,0x25202c3133647225\n"
".quad 0x7225202c38326472,0x6f6d090a3b303364,0x2509203233662e76,0x356625202c373666\n"
".quad 0x2e6c756d090a3b34,0x3666250920323366,0x2c37366625202c38,0x090a3b3736662520\n"
".quad 0x09203233662e7473,0x302b31336472255b,0x3b38366625202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093032310936,0x3233662e766f6d09,0x202c393666250920,0x6d090a3b30366625\n"
".quad 0x09203233662e6c75,0x6625202c30376625,0x37366625202c3936,0x33662e7473090a3b\n"
".quad 0x336472255b092032,0x6625202c5d342b31,0x6f6c2e090a3b3037,0x3132310936310963\n"
".quad 0x2e766f6d090a3009,0x3766250920323366,0x3b36366625202c31,0x33662e6c756d090a\n"
".quad 0x2c32376625092032,0x25202c3137662520,0x7473090a3b373666,0x255b09203233662e\n"
".quad 0x2c5d382b31336472,0x090a3b3237662520,0x09363109636f6c2e,0x6d090a3009323231\n"
".quad 0x09203233662e6c75,0x6625202c33376625,0x39366625202c3936,0x33662e7473090a3b\n"
".quad 0x336472255b092032,0x25202c5d32312b31,0x6c2e090a3b333766,0x323109363109636f\n"
".quad 0x6c756d090a300933,0x662509203233662e,0x31376625202c3437,0x0a3b39366625202c\n"
".quad 0x203233662e747309,0x2b31336472255b09,0x376625202c5d3631,0x636f6c2e090a3b34\n"
".quad 0x0934323109363109,0x662e6c756d090a30,0x3537662509203233,0x202c31376625202c\n"
".quad 0x73090a3b31376625,0x5b09203233662e74,0x30322b3133647225,0x3b35376625202c5d\n"
".quad 0x325f335f744c240a,0x63090a3a38353835,0x726168732e617476,0x09203436752e6465\n"
".quad 0x5f202c3832647225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x35335f3831303733\n"
".quad 0x6e6f635f6e6f6e5f,0x7261766f635f7473,0x305f5f65636e6169,0x09636f6c2e090a3b\n"
".quad 0x3009363231093631,0x79732e726162090a,0x090a3b300920636e,0x203233732e766f6d\n"
".quad 0x38202c3932722509,0x5f335f744c240a3b,0x200a3a3238383632,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x73656e202c363231,0x70656420676e6974\n"
".quad 0x65202c31203a6874,0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f\n"
".quad 0x6573090a6e776f6e,0x33732e74672e7074,0x202c327025092032,0x7225202c39327225\n"
".quad 0x70252140090a3b31,0x2409206172622032,0x3137325f335f744c,0x3c2f2f200a3b3833\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x36323120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3836325f335f744c,0x636f6c2e090a3238\n"
".quad 0x0930333109363109,0x6c2e6c756d090a30,0x2509203233732e6f,0x317225202c303372\n"
".quad 0x7663090a3b36202c,0x33732e3436732e74,0x3233647225092032,0x0a3b30337225202c\n"
".quad 0x6469772e6c756d09,0x2509203233732e65,0x7225202c33336472,0x090a3b34202c3033\n"
".quad 0x203436752e646461,0x202c313364722509,0x25202c3832647225,0x6c090a3b33336472\n"
".quad 0x2509203233662e64,0x72255b202c363766,0x0a3b5d302b313364,0x3233732e64646109\n"
".quad 0x202c313372250920,0x7225202c39327225,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x7225202c32337225,0x090a3b36202c3133,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x32337225202c3433,0x772e6c756d090a3b,0x203233732e656469,0x202c353364722509\n"
".quad 0x3b34202c32337225,0x36752e646461090a,0x3633647225092034,0x2c3832647225202c\n"
".quad 0x0a3b353364722520,0x203233662e646c09,0x5b202c3737662509,0x5d302b3633647225\n"
".quad 0x662e646461090a3b,0x3837662509203233,0x202c36376625202c,0x73090a3b37376625\n"
".quad 0x5b09203233662e74,0x5d302b3133647225,0x0a3b38376625202c,0x37325f335f744c24\n"
".quad 0x2f2f200a3a383331,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323120656e696c20,0x2064616568202c36,0x2064656c6562616c,0x36325f335f744c24\n"
".quad 0x726162090a323838,0x300920636e79732e,0x3270252140090a3b,0x4c24092061726220\n"
".quad 0x353637325f335f74,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36323120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x383836325f335f74,0x09636f6c2e090a32,0x3009313331093631,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x2c317225202c3333,0x747663090a3b3620,0x3233732e3436732e\n"
".quad 0x2c37336472250920,0x090a3b3333722520,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x337225202c383364,0x61090a3b34202c33,0x09203436752e6464,0x25202c3133647225\n"
".quad 0x7225202c38326472,0x646c090a3b383364,0x662509203233662e,0x6472255b202c3937\n"
".quad 0x090a3b5d342b3133,0x203233732e646461,0x25202c3433722509,0x317225202c393272\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x337225202c353372,0x63090a3b36202c34\n"
".quad 0x732e3436732e7476,0x3364722509203233,0x3b35337225202c39,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3034647225,0x0a3b34202c353372,0x3436752e64646109\n"
".quad 0x2c31346472250920,0x202c383264722520,0x090a3b3034647225,0x09203233662e646c\n"
".quad 0x255b202c30386625,0x3b5d342b31346472,0x33662e646461090a,0x2c31386625092032\n"
".quad 0x25202c3937662520,0x7473090a3b303866,0x255b09203233662e,0x2c5d342b31336472\n"
".quad 0x240a3b3138662520,0x3637325f335f744c,0x3c2f2f200a3a3035,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36323120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836325f335f744c,0x2e726162090a3238,0x3b300920636e7973\n"
".quad 0x203270252140090a,0x744c240920617262,0x32363138325f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32383836325f335f,0x3109636f6c2e090a\n"
".quad 0x0a30093233310936,0x2e6f6c2e6c756d09,0x3372250920323373,0x202c317225202c36\n"
".quad 0x2e747663090a3b36,0x203233732e343673,0x202c323464722509,0x6d090a3b36337225\n"
".quad 0x2e656469772e6c75,0x6472250920323373,0x36337225202c3334,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x7225202c31336472,0x647225202c383264,0x2e646c090a3b3334\n"
".quad 0x3866250920323366,0x336472255b202c32,0x61090a3b5d382b31,0x09203233732e6464\n"
".quad 0x7225202c37337225,0x3b317225202c3932,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x37337225202c3833,0x7663090a3b36202c,0x33732e3436732e74,0x3434647225092032\n"
".quad 0x0a3b38337225202c,0x6469772e6c756d09,0x2509203233732e65,0x7225202c35346472\n"
".quad 0x090a3b34202c3833,0x203436752e646461,0x202c363464722509,0x25202c3832647225\n"
".quad 0x6c090a3b35346472,0x2509203233662e64,0x72255b202c333866,0x0a3b5d382b363464\n"
".quad 0x3233662e64646109,0x202c343866250920,0x6625202c32386625,0x2e7473090a3b3338\n"
".quad 0x72255b0920323366,0x202c5d382b313364,0x4c240a3b34386625,0x363138325f335f74\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36323120656e69,0x616c206461656820,0x4c242064656c6562,0x383836325f335f74\n"
".quad 0x732e726162090a32,0x0a3b300920636e79,0x6220327025214009,0x5f744c2409206172\n"
".quad 0x3b34373638325f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3632312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32383836325f33,0x363109636f6c2e09,0x090a300933333109,0x732e6f6c2e6c756d\n"
".quad 0x3933722509203233,0x36202c317225202c,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x25202c3734647225,0x756d090a3b393372,0x732e656469772e6c,0x3464722509203233\n"
".quad 0x2c39337225202c38,0x646461090a3b3420,0x722509203436752e,0x647225202c313364\n"
".quad 0x34647225202c3832,0x662e646c090a3b38,0x3538662509203233,0x31336472255b202c\n"
".quad 0x61090a3b5d32312b,0x09203233732e6464,0x7225202c30347225,0x3b317225202c3932\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x30347225202c3134,0x7663090a3b36202c\n"
".quad 0x33732e3436732e74,0x3934647225092032,0x0a3b31347225202c,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x7225202c30356472,0x090a3b34202c3134,0x203436752e646461\n"
".quad 0x202c313564722509,0x25202c3832647225,0x6c090a3b30356472,0x2509203233662e64\n"
".quad 0x72255b202c363866,0x3b5d32312b313564,0x33662e646461090a,0x2c37386625092032\n"
".quad 0x25202c3538662520,0x7473090a3b363866,0x255b09203233662e,0x5d32312b31336472\n"
".quad 0x0a3b37386625202c,0x38325f335f744c24,0x2f2f200a3a343736,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x36325f335f744c24,0x726162090a323838,0x300920636e79732e\n"
".quad 0x3270252140090a3b,0x4c24092061726220,0x383139325f335f74,0x6c3c2f2f200a3b36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x383836325f335f74,0x09636f6c2e090a32\n"
".quad 0x3009343331093631,0x6f6c2e6c756d090a,0x722509203233732e,0x2c317225202c3234\n"
".quad 0x747663090a3b3620,0x3233732e3436732e,0x2c32356472250920,0x090a3b3234722520\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x347225202c333564,0x61090a3b34202c32\n"
".quad 0x09203436752e6464,0x25202c3133647225,0x7225202c38326472,0x646c090a3b333564\n"
".quad 0x662509203233662e,0x6472255b202c3838,0x0a3b5d36312b3133,0x3233732e64646109\n"
".quad 0x202c333472250920,0x7225202c39327225,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x7225202c34347225,0x090a3b36202c3334,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x34347225202c3435,0x772e6c756d090a3b,0x203233732e656469,0x202c353564722509\n"
".quad 0x3b34202c34347225,0x36752e646461090a,0x3635647225092034,0x2c3832647225202c\n"
".quad 0x0a3b353564722520,0x203233662e646c09,0x5b202c3938662509,0x36312b3635647225\n"
".quad 0x2e646461090a3b5d,0x3966250920323366,0x2c38386625202c30,0x090a3b3938662520\n"
".quad 0x09203233662e7473,0x312b31336472255b,0x30396625202c5d36,0x5f335f744c240a3b\n"
".quad 0x200a3a3638313932,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c363231,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x62090a3238383632,0x20636e79732e7261,0x252140090a3b3009,0x0920617262203270\n"
".quad 0x39325f335f744c24,0x2f2f200a3b383936,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36,0x2064656c6562616c\n"
".quad 0x36325f335f744c24,0x6f6c2e090a323838,0x3533310936310963,0x2e6c756d090a3009\n"
".quad 0x09203233732e6f6c,0x7225202c35347225,0x63090a3b36202c31,0x732e3436732e7476\n"
".quad 0x3564722509203233,0x3b35347225202c37,0x69772e6c756d090a,0x09203233732e6564\n"
".quad 0x25202c3835647225,0x0a3b34202c353472,0x3436752e64646109,0x2c31336472250920\n"
".quad 0x202c383264722520,0x090a3b3835647225,0x09203233662e646c,0x255b202c31396625\n"
".quad 0x5d30322b31336472,0x732e646461090a3b,0x3634722509203233,0x202c39327225202c\n"
".quad 0x756d090a3b317225,0x3233732e6f6c2e6c,0x202c373472250920,0x3b36202c36347225\n"
".quad 0x36732e747663090a,0x2509203233732e34,0x7225202c39356472,0x6c756d090a3b3734\n"
".quad 0x33732e656469772e,0x3036647225092032,0x202c37347225202c,0x2e646461090a3b34\n"
".quad 0x6472250920343675,0x32647225202c3136,0x3036647225202c38,0x33662e646c090a3b\n"
".quad 0x2c32396625092032,0x2b31366472255b20,0x6461090a3b5d3032,0x2509203233662e64\n"
".quad 0x396625202c333966,0x3b32396625202c31,0x3233662e7473090a,0x31336472255b0920\n"
".quad 0x6625202c5d30322b,0x5f744c240a3b3339,0x3a38393639325f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3632312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32383836325f33,0x6e79732e72616209\n"
".quad 0x2e090a3b30092063,0x3109363109636f6c,0x6873090a30093832,0x2509203233732e72\n"
".quad 0x327225202c393272,0x6d090a3b31202c39,0x09203233752e766f,0x3b30202c38347225\n"
".quad 0x672e70746573090a,0x2509203233732e74,0x39327225202c3370,0x0a3b38347225202c\n"
".quad 0x7262203370254009,0x335f744c24092061,0x0a3b32383836325f,0x726168732e646c09\n"
".quad 0x33662e34762e6465,0x343966257b092032,0x66252c353966252c,0x5b202c7d5f2c3639\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f38313037335f,0x6f635f6e6f6e5f35\n"
".quad 0x61766f635f74736e,0x5f5f65636e616972,0x2e090a3b5d302b30,0x3509363109636f6c\n"
".quad 0x2e646c090a300934,0x662e646572616873,0x3739662509203233,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x313037335f726176,0x6e6f6e5f35335f38,0x635f74736e6f635f\n"
".quad 0x636e61697261766f,0x5d32312b305f5f65,0x662e766f6d090a3b,0x3839662509203233\n"
".quad 0x303866336630202c,0x2020203b30303030,0x090a31202f2f0920,0x662e6e722e616d66\n"
".quad 0x3939662509203233,0x202c38396625202c,0x6625202c35396625,0x2e646c090a3b3739\n"
".quad 0x762e646572616873,0x7b09203233662e32,0x66252c3030316625,0x5f5b202c7d313031\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x35335f3831303733,0x6e6f635f6e6f6e5f\n"
".quad 0x7261766f635f7473,0x305f5f65636e6169,0x6d090a3b5d36312b,0x09203233662e766f\n"
".quad 0x30202c3230316625,0x3030303038663366,0x2f2f092020203b30,0x2e616d66090a3120\n"
".quad 0x09203233662e6e72,0x25202c3330316625,0x6625202c32303166,0x30316625202c3639\n"
".quad 0x2e766f6d090a3b30,0x3166250920323366,0x66336630202c3430,0x203b303030303038\n"
".quad 0x0a31202f2f092020,0x2e6e722e616d6609,0x3166250920323366,0x34396625202c3530\n"
".quad 0x2c3430316625202c,0x090a3b3539662520,0x203233662e766f6d,0x202c363031662509\n"
".quad 0x3030303866336630,0x2f092020203b3030,0x616d66090a31202f,0x203233662e6e722e\n"
".quad 0x202c373031662509,0x25202c3630316625,0x6625202c30303166,0x766f6d090a3b3939\n"
".quad 0x662509203233662e,0x336630202c383031,0x3b30303030303866,0x31202f2f09202020\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c393031,0x30316625202c3830\n"
".quad 0x3330316625202c31,0x662e766f6d090a3b,0x3131662509203233,0x3866336630202c30\n"
".quad 0x20203b3030303030,0x090a31202f2f0920,0x662e6e722e616d66,0x3131662509203233\n"
".quad 0x2c36396625202c31,0x202c303131662520,0x090a3b3530316625,0x203233662e78616d\n"
".quad 0x202c323131662509,0x25202c3730316625,0x6d090a3b31313166,0x09203233662e7861\n"
".quad 0x25202c3331316625,0x6625202c39303166,0x6372090a3b323131,0x3233662e6e722e70\n"
".quad 0x2c34313166250920,0x0a3b333131662520,0x3233662e6c756d09,0x2c35313166250920\n"
".quad 0x202c373031662520,0x090a3b3431316625,0x203233662e6c756d,0x202c363131662509\n"
".quad 0x25202c3131316625,0x6d090a3b34313166,0x09203233662e6c75,0x25202c3731316625\n"
".quad 0x6625202c39303166,0x756d090a3b343131,0x2509203233662e6c,0x6625202c38313166\n"
".quad 0x316625202c353131,0x6c756d090a3b3030,0x662509203233662e,0x316625202c393131\n"
".quad 0x35396625202c3531,0x662e6c756d090a3b,0x3231662509203233,0x3531316625202c30\n"
".quad 0x0a3b37396625202c,0x2e6e722e616d6609,0x3166250920323366,0x31316625202c3132\n"
".quad 0x2c36396625202c36,0x0a3b383131662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x34396625202c3232,0x2c3631316625202c,0x0a3b393131662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x31316625202c3332,0x2c35396625202c36,0x0a3b303231662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x31316625202c3432,0x3130316625202c37\n"
".quad 0x3b3132316625202c,0x6e722e616d66090a,0x662509203233662e,0x396625202c353231\n"
".quad 0x3731316625202c36,0x3b3232316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c363231,0x30316625202c3731,0x3332316625202c30,0x662e78616d090a3b\n"
".quad 0x3231662509203233,0x3532316625202c37,0x3b3632316625202c,0x33662e78616d090a\n"
".quad 0x3832316625092032,0x2c3432316625202c,0x0a3b373231662520,0x2e6e722e70637209\n"
".quad 0x3166250920323366,0x32316625202c3932,0x636f6c2e090a3b38,0x3009303509363109\n"
".quad 0x33662e6c756d090a,0x3033316625092032,0x2c3432316625202c,0x0a3b393231662520\n"
".quad 0x3233662e6c756d09,0x2c31333166250920,0x202c353231662520,0x090a3b3932316625\n"
".quad 0x203233662e6c756d,0x202c323331662509,0x25202c3632316625,0x6d090a3b39323166\n"
".quad 0x09203233662e6c75,0x25202c3333316625,0x6625202c32333166,0x616d66090a3b3539\n"
".quad 0x203233662e6e722e,0x202c343331662509,0x6625202c34396625,0x316625202c313331\n"
".quad 0x616d66090a3b3333,0x203233662e6e722e,0x202c353331662509,0x6625202c36396625\n"
".quad 0x316625202c303331,0x6f6c2e090a3b3433,0x0931350936310963,0x662e6c756d090a30\n"
".quad 0x3331662509203233,0x3233316625202c36,0x0a3b37396625202c,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x33316625202c3733,0x2c35396625202c31,0x0a3b363331662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x33316625202c3833,0x3030316625202c30\n"
".quad 0x3b3733316625202c,0x3109636f6c2e090a,0x090a300932350936,0x203233662e6c756d\n"
".quad 0x202c393331662509,0x25202c3233316625,0x66090a3b30303166,0x33662e6e722e616d\n"
".quad 0x3034316625092032,0x2c3133316625202c,0x25202c3639662520,0x66090a3b39333166\n"
".quad 0x33662e6e722e616d,0x3134316625092032,0x2c3033316625202c,0x202c313031662520\n"
".quad 0x090a3b3034316625,0x09363109636f6c2e,0x616d090a30093835,0x2509203233662e78\n"
".quad 0x6625202c32343166,0x316625202c353331,0x78616d090a3b3833,0x662509203233662e\n"
".quad 0x316625202c333431,0x34316625202c3234,0x2e706372090a3b31,0x09203233662e6e72\n"
".quad 0x25202c3434316625,0x6d090a3b33343166,0x09203233662e6c75,0x25202c3534316625\n"
".quad 0x6625202c34343166,0x756d090a3b353331,0x2509203233662e6c,0x6625202c36343166\n"
".quad 0x316625202c343431,0x6c756d090a3b3833,0x662509203233662e,0x316625202c373431\n"
".quad 0x34316625202c3434,0x636f6c2e090a3b31,0x3009303509363109,0x33662e6c756d090a\n"
".quad 0x3834316625092032,0x2c3634316625202c,0x090a3b3539662520,0x662e6e722e616d66\n"
".quad 0x3431662509203233,0x2c34396625202c39,0x202c353431662520,0x090a3b3834316625\n"
".quad 0x662e6e722e616d66,0x3531662509203233,0x2c36396625202c30,0x202c373431662520\n"
".quad 0x090a3b3934316625,0x09363109636f6c2e,0x756d090a30093835,0x2509203233662e6c\n"
".quad 0x6625202c31353166,0x396625202c363431,0x2e6c756d090a3b37,0x3166250920323366\n"
".quad 0x34316625202c3235,0x3030316625202c36,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c33353166,0x396625202c353431,0x3135316625202c35,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c34353166,0x396625202c353431,0x3235316625202c36\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c35353166,0x316625202c373431\n"
".quad 0x35316625202c3030,0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3635316625\n"
".quad 0x6625202c37343166,0x316625202c313031,0x78616d090a3b3435,0x662509203233662e\n"
".quad 0x316625202c373531,0x35316625202c3535,0x2e78616d090a3b30,0x3166250920323366\n"
".quad 0x35316625202c3835,0x3735316625202c36,0x722e706372090a3b,0x2509203233662e6e\n"
".quad 0x6625202c39353166,0x756d090a3b383531,0x2509203233662e6c,0x6625202c30363166\n"
".quad 0x316625202c353531,0x6c756d090a3b3935,0x662509203233662e,0x316625202c313631\n"
".quad 0x35316625202c3635,0x2e6c756d090a3b39,0x3166250920323366,0x35316625202c3236\n"
".quad 0x3035316625202c39,0x09636f6c2e090a3b,0x0a30093235093631,0x3233662e6c756d09\n"
".quad 0x2c33363166250920,0x202c303631662520,0x090a3b3030316625,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x3236316625202c34,0x202c36396625202c,0x090a3b3336316625\n"
".quad 0x662e6e722e616d66,0x3631662509203233,0x3136316625202c35,0x2c3130316625202c\n"
".quad 0x0a3b343631662520,0x363109636f6c2e09,0x6d090a3009343509,0x09203233662e6c75\n"
".quad 0x25202c3636316625,0x6625202c30363166,0x6c756d090a3b3539,0x662509203233662e\n"
".quad 0x316625202c373631,0x37396625202c3036,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c38363166,0x36316625202c3439,0x3636316625202c32,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c39363166,0x396625202c323631,0x3736316625202c35\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c30373166,0x36316625202c3639\n"
".quad 0x3836316625202c31,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c31373166\n"
".quad 0x316625202c313631,0x36316625202c3030,0x2e78616d090a3b39,0x3166250920323366\n"
".quad 0x37316625202c3237,0x3137316625202c30,0x662e78616d090a3b,0x3731662509203233\n"
".quad 0x3237316625202c33,0x3b3536316625202c,0x6e722e706372090a,0x662509203233662e\n"
".quad 0x316625202c343731,0x6f6c2e090a3b3337,0x0938350936310963,0x662e6c756d090a30\n"
".quad 0x3731662509203233,0x3037316625202c35,0x3b3437316625202c,0x33662e6c756d090a\n"
".quad 0x3637316625092032,0x2c3137316625202c,0x0a3b343731662520,0x363109636f6c2e09\n"
".quad 0x6d090a3009303509,0x09203233662e6c75,0x25202c3737316625,0x6625202c34373166\n"
".quad 0x756d090a3b353631,0x2509203233662e6c,0x6625202c38373166,0x396625202c363731\n"
".quad 0x2e616d66090a3b35,0x09203233662e6e72,0x25202c3937316625,0x316625202c343966\n"
".quad 0x37316625202c3537,0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3038316625\n"
".quad 0x316625202c363966,0x37316625202c3737,0x636f6c2e090a3b39,0x3009313509363109\n"
".quad 0x33662e6c756d090a,0x3138316625092032,0x2c3637316625202c,0x090a3b3739662520\n"
".quad 0x662e6e722e616d66,0x3831662509203233,0x3537316625202c32,0x202c35396625202c\n"
".quad 0x090a3b3138316625,0x662e6e722e616d66,0x3831662509203233,0x3737316625202c33\n"
".quad 0x2c3030316625202c,0x0a3b323831662520,0x363109636f6c2e09,0x6d090a3009323509\n"
".quad 0x09203233662e6c75,0x25202c3438316625,0x6625202c36373166,0x6d66090a3b303031\n"
".quad 0x3233662e6e722e61,0x2c35383166250920,0x202c353731662520,0x6625202c36396625\n"
".quad 0x6d66090a3b343831,0x3233662e6e722e61,0x2c36383166250920,0x202c373731662520\n"
".quad 0x25202c3130316625,0x2e090a3b35383166,0x3509363109636f6c,0x78616d090a300938\n"
".quad 0x662509203233662e,0x316625202c373831,0x38316625202c3038,0x2e78616d090a3b33\n"
".quad 0x3166250920323366,0x38316625202c3838,0x3638316625202c37,0x722e706372090a3b\n"
".quad 0x2509203233662e6e,0x6625202c39383166,0x756d090a3b383831,0x2509203233662e6c\n"
".quad 0x6625202c30393166,0x316625202c393831,0x6c756d090a3b3038,0x662509203233662e\n"
".quad 0x316625202c313931,0x38316625202c3938,0x2e6c756d090a3b33,0x3166250920323366\n"
".quad 0x38316625202c3239,0x3638316625202c39,0x09636f6c2e090a3b,0x0a30093035093631\n"
".quad 0x3233662e6c756d09,0x2c33393166250920,0x202c313931662520,0x66090a3b35396625\n"
".quad 0x33662e6e722e616d,0x3439316625092032,0x202c34396625202c,0x25202c3039316625\n"
".quad 0x66090a3b33393166,0x33662e6e722e616d,0x3539316625092032,0x202c36396625202c\n"
".quad 0x25202c3239316625,0x2e090a3b34393166,0x3509363109636f6c,0x6c756d090a300938\n"
".quad 0x662509203233662e,0x316625202c363931,0x37396625202c3139,0x662e6c756d090a3b\n"
".quad 0x3931662509203233,0x3139316625202c37,0x3b3030316625202c,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x316625202c383931,0x35396625202c3039,0x3b3639316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c393931,0x36396625202c3039\n"
".quad 0x3b3739316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c303032\n"
".quad 0x30316625202c3239,0x3839316625202c30,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c31303266,0x316625202c323931,0x39316625202c3130,0x2e78616d090a3b39\n"
".quad 0x3266250920323366,0x30326625202c3230,0x3539316625202c30,0x662e78616d090a3b\n"
".quad 0x3032662509203233,0x3130326625202c33,0x3b3230326625202c,0x6e722e706372090a\n"
".quad 0x662509203233662e,0x326625202c343032,0x6c756d090a3b3330,0x662509203233662e\n"
".quad 0x326625202c353032,0x30326625202c3030,0x2e6c756d090a3b34,0x3266250920323366\n"
".quad 0x30326625202c3630,0x3430326625202c31,0x662e6c756d090a3b,0x3032662509203233\n"
".quad 0x3430326625202c37,0x3b3539316625202c,0x3109636f6c2e090a,0x090a300932350936\n"
".quad 0x203233662e6c756d,0x202c383032662509,0x25202c3530326625,0x66090a3b30303166\n"
".quad 0x33662e6e722e616d,0x3930326625092032,0x2c3730326625202c,0x25202c3639662520\n"
".quad 0x66090a3b38303266,0x33662e6e722e616d,0x3031326625092032,0x2c3630326625202c\n"
".quad 0x202c313031662520,0x090a3b3930326625,0x09363109636f6c2e,0x756d090a30093435\n"
".quad 0x2509203233662e6c,0x6625202c31313266,0x396625202c353032,0x2e6c756d090a3b35\n"
".quad 0x3266250920323366,0x30326625202c3231,0x3b37396625202c35,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x396625202c333132,0x3730326625202c34,0x3b3131326625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x326625202c343132,0x35396625202c3730\n"
".quad 0x3b3231326625202c,0x6e722e616d66090a,0x662509203233662e,0x396625202c353132\n"
".quad 0x3630326625202c36,0x3b3331326625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x326625202c363132,0x30316625202c3630,0x3431326625202c30,0x662e78616d090a3b\n"
".quad 0x3132662509203233,0x3531326625202c37,0x3b3631326625202c,0x33662e78616d090a\n"
".quad 0x3831326625092032,0x2c3731326625202c,0x0a3b303132662520,0x2e6e722e70637209\n"
".quad 0x3266250920323366,0x31326625202c3931,0x636f6c2e090a3b38,0x3009383509363109\n"
".quad 0x33662e6c756d090a,0x3032326625092032,0x2c3531326625202c,0x0a3b393132662520\n"
".quad 0x3233662e6c756d09,0x2c31323266250920,0x202c363132662520,0x090a3b3931326625\n"
".quad 0x09373109636f6c2e,0x40090a3009313631,0x6172622031702521,0x5f335f744c240920\n"
".quad 0x090a3b3636343033,0x09373109636f6c2e,0x63090a3009343631,0x726168732e617476\n"
".quad 0x09203436752e6465,0x5f202c3236647225,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x35335f3134333733,0x6e6f635f6e6f6e5f,0x5f5f7370645f7473,0x2e6c756d090a3b33\n"
".quad 0x09203233752e6f6c,0x7225202c39347225,0x090a3b3231202c31,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x39347225202c3336,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x3336647225202c32,0x0a3b34647225202c,0x203233662e646c09,0x202c323232662509\n"
".quad 0x342b32316472255b,0x2e6c756d090a3b5d,0x3266250920323366,0x32326625202c3332\n"
".quad 0x3132326625202c32,0x33662e646c090a3b,0x3432326625092032,0x32316472255b202c\n"
".quad 0x6d66090a3b5d302b,0x3233662e6e722e61,0x2c35323266250920,0x202c343232662520\n"
".quad 0x25202c3032326625,0x6c090a3b33323266,0x2509203233662e64,0x255b202c36323266\n"
".quad 0x3b5d382b32316472,0x33662e6c756d090a,0x3732326625092032,0x2c3931326625202c\n"
".quad 0x0a3b303132662520,0x2e6e722e616d6609,0x3266250920323366,0x32326625202c3832\n"
".quad 0x3732326625202c36,0x3b3532326625202c,0x36732e747663090a,0x2509203233732e34\n"
".quad 0x7225202c34366472,0x2e6c756d090a3b31,0x3233732e65646977,0x2c35366472250920\n"
".quad 0x3b34202c31722520,0x36752e646461090a,0x3636647225092034,0x2c3236647225202c\n"
".quad 0x0a3b353664722520,0x203233662e747309,0x2b36366472255b09,0x32326625202c5d30\n"
".quad 0x335f744c240a3b38,0x0a3a36363430335f,0x68732e6174766309,0x3436752e64657261\n"
".quad 0x2c32366472250920,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f31343337335f72\n"
".quad 0x635f6e6f6e5f3533,0x7370645f74736e6f,0x6c2e090a3b335f5f,0x363109373109636f\n"
".quad 0x726162090a300937,0x300920636e79732e,0x3170252140090a3b,0x4c24092061726220\n"
".quad 0x373930335f335f74,0x636f6c2e090a3b38,0x0930373109373109,0x752e766f6d090a30\n"
".quad 0x3035722509203233,0x6573090a3b30202c,0x33752e656e2e7074,0x202c347025092032\n"
".quad 0x357225202c317225,0x34702540090a3b30,0x4c24092061726220,0x393431335f335f74\n"
".quad 0x2e766f6d090a3b30,0x3572250920323373,0x4c240a3b30202c31,0x313532335f335f74\n"
".quad 0x6c3c2f2f200a3a34,0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c30373120656e69\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6172657469202c31,0x31203a736e6f6974\n"
".quad 0x09636f6c2e090a36,0x0a30093839093731,0x3436752e74766309,0x722509203233752e\n"
".quad 0x357225202c373664,0x2e646461090a3b31,0x6472250920343675,0x36647225202c3836\n"
".quad 0x3236647225202c37,0x33662e646c090a3b,0x3932326625092032,0x38366472255b202c\n"
".quad 0x646c090a3b5d302b,0x2e6465726168732e,0x09203233662e3476,0x30333266252c5f7b\n"
".quad 0x252c31333266252c,0x5b202c7d32333266,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f31343337335f,0x6f635f6e6f6e5f35,0x5f7370645f74736e,0x0a3b5d38342b335f\n"
".quad 0x2e746c2e74657309,0x203233662e323375,0x25202c3235722509,0x6625202c31333266\n"
".quad 0x656e090a3b393232,0x2509203233732e67,0x357225202c333572,0x2e746573090a3b32\n"
".quad 0x662e3233752e746c,0x3435722509203233,0x2c3233326625202c,0x0a3b393232662520\n"
".quad 0x3233732e67656e09,0x202c353572250920,0x61090a3b34357225,0x09203233732e6464\n"
".quad 0x7225202c36357225,0x35357225202c3335,0x68732e646c090a3b,0x3233662e64657261\n"
".quad 0x2c33333266250920,0x616475635f5f5b20,0x765f6c61636f6c5f,0x31343337335f7261\n"
".quad 0x5f6e6f6e5f35335f,0x70645f74736e6f63,0x5d38342b335f5f73,0x6c2e746573090a3b\n"
".quad 0x33662e3233752e74,0x2c37357225092032,0x202c333332662520,0x090a3b3932326625\n"
".quad 0x203233732e67656e,0x25202c3835722509,0x6573090a3b373572,0x3233752e746c2e74\n"
".quad 0x722509203233662e,0x33326625202c3935,0x3932326625202c30,0x732e67656e090a3b\n"
".quad 0x3036722509203233,0x0a3b39357225202c,0x3233732e64646109,0x202c313672250920\n"
".quad 0x7225202c38357225,0x2e646c090a3b3036,0x762e646572616873,0x7b09203233662e34\n"
".quad 0x2c34333266252c5f,0x66252c3533326625,0x5f5b202c7d363332,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x35335f3134333733,0x6e6f635f6e6f6e5f,0x5f5f7370645f7473\n"
".quad 0x090a3b5d32332b33,0x752e746c2e746573,0x09203233662e3233,0x6625202c32367225\n"
".quad 0x326625202c353332,0x67656e090a3b3932,0x722509203233732e,0x32367225202c3336\n"
".quad 0x6c2e746573090a3b,0x33662e3233752e74,0x2c34367225092032,0x202c363332662520\n"
".quad 0x090a3b3932326625,0x203233732e67656e,0x25202c3536722509,0x6461090a3b343672\n"
".quad 0x2509203233732e64,0x367225202c363672,0x3b35367225202c33,0x6168732e646c090a\n"
".quad 0x662e34762e646572,0x3266257b09203233,0x38333266252c3733,0x252c39333266252c\n"
".quad 0x5b202c7d30343266,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f31343337335f\n"
".quad 0x6f635f6e6f6e5f35,0x5f7370645f74736e,0x090a3b5d302b335f,0x752e746c2e746573\n"
".quad 0x09203233662e3233,0x6625202c37367225,0x326625202c373332,0x67656e090a3b3932\n"
".quad 0x722509203233732e,0x37367225202c3836,0x6c2e746573090a3b,0x33662e3233752e74\n"
".quad 0x2c39367225092032,0x202c383332662520,0x090a3b3932326625,0x203233732e67656e\n"
".quad 0x25202c3037722509,0x6461090a3b393672,0x2509203233732e64,0x367225202c313772\n"
".quad 0x3b30377225202c38,0x746c2e746573090a,0x3233662e3233752e,0x202c323772250920\n"
".quad 0x25202c3933326625,0x6e090a3b39323266,0x09203233732e6765,0x7225202c33377225\n"
".quad 0x746573090a3b3237,0x2e3233752e746c2e,0x3772250920323366,0x3034326625202c34\n"
".quad 0x3b3932326625202c,0x33732e67656e090a,0x2c35377225092032,0x090a3b3437722520\n"
".quad 0x203233732e646461,0x25202c3637722509,0x377225202c333772,0x732e646c090a3b35\n"
".quad 0x34762e6465726168,0x257b09203233662e,0x3266252c31343266,0x33343266252c3234\n"
".quad 0x2c7d34343266252c,0x616475635f5f5b20,0x765f6c61636f6c5f,0x31343337335f7261\n"
".quad 0x5f6e6f6e5f35335f,0x70645f74736e6f63,0x5d36312b335f5f73,0x6c2e746573090a3b\n"
".quad 0x33662e3233752e74,0x2c37377225092032,0x202c313432662520,0x090a3b3932326625\n"
".quad 0x203233732e67656e,0x25202c3837722509,0x6573090a3b373772,0x3233752e746c2e74\n"
".quad 0x722509203233662e,0x34326625202c3937,0x3932326625202c32,0x732e67656e090a3b\n"
".quad 0x3038722509203233,0x0a3b39377225202c,0x3233732e64646109,0x202c313872250920\n"
".quad 0x7225202c38377225,0x746573090a3b3038,0x2e3233752e746c2e,0x3872250920323366\n"
".quad 0x3334326625202c32,0x3b3932326625202c,0x33732e67656e090a,0x2c33387225092032\n"
".quad 0x090a3b3238722520,0x752e746c2e746573,0x09203233662e3233,0x6625202c34387225\n"
".quad 0x326625202c343432,0x67656e090a3b3932,0x722509203233732e,0x34387225202c3538\n"
".quad 0x732e646461090a3b,0x3638722509203233,0x202c33387225202c,0x6c090a3b35387225\n"
".quad 0x6465726168732e64,0x662509203233662e,0x5f5f5b202c353432,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f35335f31343337,0x736e6f635f6e6f6e,0x335f5f7370645f74\n"
".quad 0x73090a3b5d32332b,0x33752e746c2e7465,0x2509203233662e32,0x326625202c373872\n"
".quad 0x32326625202c3534,0x2e67656e090a3b39,0x3872250920323373,0x3b37387225202c38\n"
".quad 0x746c2e746573090a,0x3233662e3233752e,0x202c393872250920,0x25202c3433326625\n"
".quad 0x6e090a3b39323266,0x09203233732e6765,0x7225202c30397225,0x646461090a3b3938\n"
".quad 0x722509203233732e,0x38387225202c3139,0x0a3b30397225202c,0x3233732e64646109\n"
".quad 0x202c323972250920,0x7225202c36387225,0x646461090a3b3139,0x722509203233732e\n"
".quad 0x31387225202c3339,0x0a3b32397225202c,0x3233732e64646109,0x202c343972250920\n"
".quad 0x7225202c36377225,0x646461090a3b3339,0x722509203233732e,0x31377225202c3539\n"
".quad 0x0a3b34397225202c,0x3233732e64646109,0x202c363972250920,0x7225202c36367225\n"
".quad 0x646461090a3b3539,0x722509203233732e,0x31367225202c3739,0x0a3b36397225202c\n"
".quad 0x3233732e64646109,0x202c383972250920,0x7225202c36357225,0x646461090a3b3739\n"
".quad 0x722509203436752e,0x647225202c393664,0x38647225202c3736,0x33732e7473090a3b\n"
".quad 0x366472255b092032,0x7225202c5d302b39,0x646461090a3b3839,0x722509203233752e\n"
".quad 0x31357225202c3135,0x6f6d090a3b34202c,0x2509203233752e76,0x3b3436202c393972\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x31357225202c3570,0x0a3b39397225202c\n"
".quad 0x7262203570254009,0x335f744c24092061,0x0a3b34313532335f,0x3233732e766f6d09\n"
".quad 0x2c30303172250920,0x5f744c240a3b3020,0x3a38333533335f33,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x656e202c38392065,0x656420676e697473\n"
".quad 0x202c31203a687470,0x6f69746172657469,0x090a3531203a736e,0x203233732e766f6d\n"
".quad 0x202c313031722509,0x335f744c240a3b30,0x0a3a36303334335f,0x706f6f6c3c2f2f20\n"
".quad 0x6220706f6f4c203e,0x656e696c2079646f,0x73656e202c383920,0x70656420676e6974\n"
".quad 0x69202c32203a6874,0x6e6f697461726574,0x2e090a3631203a73,0x3109373109636f6c\n"
".quad 0x6573090a30093630,0x33732e656c2e7074,0x202c367025092032,0x25202c3130317225\n"
".quad 0x40090a3b30303172,0x2061726220367025,0x335f335f744c2409,0x2f200a3b32343835\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3920656e696c2079\n"
".quad 0x2064616568202c38,0x2064656c6562616c,0x34335f335f744c24,0x6c756d090a363033\n"
".quad 0x203233752e6f6c2e,0x202c323031722509,0x34202c3130317225,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3037647225,0x61090a3b32303172,0x09203436752e6464\n"
".quad 0x25202c3137647225,0x7225202c30376472,0x2e646c090a3b3864,0x3172250920323373\n"
".quad 0x6472255b202c3330,0x090a3b5d302b3137,0x752e6f6c2e6c756d,0x3031722509203233\n"
".quad 0x3030317225202c34,0x7663090a3b34202c,0x33752e3436752e74,0x3237647225092032\n"
".quad 0x3b3430317225202c,0x36752e646461090a,0x3337647225092034,0x2c3237647225202c\n"
".quad 0x090a3b3864722520,0x09203233732e646c,0x5b202c3530317225,0x5d302b3337647225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x317225202c377025,0x30317225202c3530\n"
".quad 0x37702540090a3b33,0x4c24092061726220,0x343835335f335f74,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383920656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x36303334335f335f,0x33732e646461090a\n"
".quad 0x3630317225092032,0x2c3330317225202c,0x2e7473090a3b3120,0x72255b0920323373\n"
".quad 0x202c5d302b313764,0x240a3b3630317225,0x3835335f335f744c,0x335f4c240a3a3234\n"
".quad 0x0a3a32363731325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c383920,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x61090a3630333433,0x09203233732e6464,0x25202c3130317225,0x3b31202c31303172\n"
".quad 0x33752e766f6d090a,0x3730317225092032,0x73090a3b3631202c,0x732e656e2e707465\n"
".quad 0x2c38702509203233,0x202c313031722520,0x090a3b3730317225,0x6172622038702540\n"
".quad 0x5f335f744c240920,0x200a3b3630333433,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3839,0x64656c6562616c20\n"
".quad 0x335f335f744c2420,0x6461090a38333533,0x2509203233732e64,0x7225202c30303172\n"
".quad 0x0a3b31202c303031,0x3233752e766f6d09,0x2c38303172250920,0x6573090a3b353120\n"
".quad 0x33732e656e2e7074,0x202c397025092032,0x25202c3030317225,0x40090a3b38303172\n"
".quad 0x2061726220397025,0x335f335f744c2409,0x4c240a3b38333533,0x393431335f335f74\n"
".quad 0x636f6c2e090a3a30,0x0932373109373109,0x6c2e6c756d090a30,0x2509203233752e6f\n"
".quad 0x7225202c39303172,0x090a3b3231202c31,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x30317225202c3437,0x2e646461090a3b39,0x6472250920343675,0x37647225202c3231\n"
".quad 0x3b34647225202c34,0x3233662e646c090a,0x2c36343266250920,0x2b32316472255b20\n"
".quad 0x766f6d090a3b5d30,0x662509203233662e,0x326625202c373432,0x2e646c090a3b3634\n"
".quad 0x3266250920323366,0x6472255b202c3834,0x090a3b5d342b3231,0x203233662e766f6d\n"
".quad 0x202c393432662509,0x090a3b3834326625,0x09203233662e646c,0x5b202c3035326625\n"
".quad 0x5d382b3231647225,0x662e766f6d090a3b,0x3532662509203233,0x3035326625202c31\n"
".quad 0x5f335f744c240a3b,0x090a3a3837393033,0x09373109636f6c2e,0x62090a3009353731\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x35335f335f744c24\n"
".quad 0x6c2e090a3b343730,0x373109373109636f,0x6c756d090a300938,0x203233752e6f6c2e\n"
".quad 0x202c303131722509,0x0a3b34202c317225,0x3436752e74766309,0x722509203233752e\n"
".quad 0x317225202c353764,0x646461090a3b3031,0x722509203436752e,0x647225202c363764\n"
".quad 0x38647225202c3537,0x662e766f6d090a3b,0x3532662509203233,0x3734326625202c32\n"
".quad 0x33752e646c090a3b,0x3131317225092032,0x36376472255b202c,0x756d090a3b5d302b\n"
".quad 0x3233752e6f6c2e6c,0x2c32313172250920,0x202c313131722520,0x747663090a3b3231\n"
".quad 0x3233752e3436752e,0x2c37376472250920,0x0a3b323131722520,0x3436752e64646109\n"
".quad 0x2c38376472250920,0x202c373764722520,0x73090a3b34647225,0x5b09203233662e74\n"
".quad 0x5d302b3837647225,0x3b3235326625202c,0x33662e766f6d090a,0x3335326625092032\n"
".quad 0x3b3934326625202c,0x3233752e646c090a,0x2c33313172250920,0x2b36376472255b20\n"
".quad 0x6c756d090a3b5d30,0x203233752e6f6c2e,0x202c343131722509,0x31202c3331317225\n"
".quad 0x2e747663090a3b32,0x203233752e343675,0x202c393764722509,0x090a3b3431317225\n"
".quad 0x203436752e646461,0x202c303864722509,0x25202c3937647225,0x7473090a3b346472\n"
".quad 0x255b09203233662e,0x2c5d342b30386472,0x0a3b333532662520,0x3233662e766f6d09\n"
".quad 0x2c34353266250920,0x0a3b313532662520,0x203233752e646c09,0x202c353131722509\n"
".quad 0x302b36376472255b,0x2e6c756d090a3b5d,0x09203233752e6f6c,0x25202c3631317225\n"
".quad 0x3231202c35313172,0x752e747663090a3b,0x09203233752e3436,0x25202c3138647225\n"
".quad 0x61090a3b36313172,0x09203436752e6464,0x25202c3238647225,0x7225202c31386472\n"
".quad 0x2e7473090a3b3464,0x72255b0920323366,0x202c5d382b323864,0x240a3b3435326625\n"
".quad 0x3035335f335f744c,0x6f6c2e090a3a3437,0x3038310937310963,0x3b746572090a3009\n"
".quad 0x646e6557444c240a,0x616f6c34315a5f5f,0x6c42726f6c6f4364,0x36506a4b506b636f\n"
".quad 0x32533374616f6c66,0x207d090a3a69505f,0x6c34315a5f202f2f,0x726f6c6f4364616f\n"
".quad 0x6a4b506b636f6c42,0x3374616f6c663650,0x2e090a69505f3253,0x2e20646572616873\n"
".quad 0x2034206e67696c61,0x75635f5f2038622e,0x6c61636f6c5f6164,0x3437335f7261765f\n"
".quad 0x6f6e5f34335f3439,0x5f74736e6f635f6e,0x74756d7265705f73,0x5f5f736e6f697461\n"
".quad 0x0a3b5d3034365b32,0x2074736e6f632e09,0x34206e67696c612e,0x6f436b2038622e20\n"
".quad 0x697274654d726f6c,0x203d205d32315b63,0x3832312c302c307b,0x2c302c302c33362c\n"
".quad 0x302c33362c383231,0x362c3832312c302c,0x6f632e090a3b7d33,0x696c612e2074736e\n"
".quad 0x38622e2034206e67,0x61546168706c6120,0x5d36315b34656c62,0x2c302c307b203d20\n"
".quad 0x2c302c35362c3631,0x2c302c302c302c30,0x34362c3239312c30,0x2c34362c302c302c\n"
".quad 0x632e090a3b7d3436,0x6c612e2074736e6f,0x622e2034206e6769,0x546168706c612038\n"
".quad 0x36315b33656c6261,0x302c307b203d205d,0x2c34362c3832312c,0x2c302c302c302c30\n"
".quad 0x34362c302c302c30,0x362c302c302c302c,0x6f632e090a3b7d34,0x696c612e2074736e\n"
".quad 0x38622e2034206e67,0x5b3473646f727020,0x307b203d205d3631,0x302c302c392c302c\n"
".quad 0x322c302c302c392c,0x322c302c342c312c,0x3b7d302c312c342c,0x74736e6f632e090a\n"
".quad 0x206e67696c612e20,0x72702038622e2034,0x5d36315b3373646f,0x2c302c307b203d20\n"
".quad 0x2c342c302c302c34,0x2c312c312c302c30,0x2c342c312c302c34,0x090a0a3b7d302c31\n"
".quad 0x656c62697369762e,0x5f20636e75662e20,0x416c61766539315a,0x74756d7265506c6c\n"
".quad 0x4b50736e6f697461,0x503374616f6c6636,0x525f345374526a4b,0x2e28205f5366506a\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5f31666d72617061,0x6c61766539315a5f\n"
".quad 0x756d7265506c6c41,0x50736e6f69746174,0x3374616f6c66364b,0x5f345374526a4b50\n"
".quad 0x202c5f5366506a52,0x2e206d617261702e,0x75635f5f20343675,0x32666d7261706164\n"
".quad 0x61766539315a5f5f,0x6d7265506c6c416c,0x736e6f6974617475,0x74616f6c66364b50\n"
".quad 0x345374526a4b5033,0x2c5f5366506a525f,0x206d617261702e20,0x635f5f203436752e\n"
".quad 0x666d726170616475,0x766539315a5f5f33,0x7265506c6c416c61,0x6e6f69746174756d\n"
".quad 0x616f6c66364b5073,0x5374526a4b503374,0x5f5366506a525f34,0x6d617261702e202c\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x6539315a5f5f3466,0x65506c6c416c6176\n"
".quad 0x6f69746174756d72,0x6f6c66364b50736e,0x74526a4b50337461,0x5366506a525f3453\n"
".quad 0x617261702e202c5f,0x5f203436752e206d,0x726170616475635f,0x39315a5f5f35666d\n"
".quad 0x506c6c416c617665,0x69746174756d7265,0x6c66364b50736e6f,0x526a4b503374616f\n"
".quad 0x66506a525f345374,0x7261702e202c5f53,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f36666d72,0x6c6c416c61766539,0x746174756d726550,0x66364b50736e6f69\n"
".quad 0x6a4b503374616f6c,0x506a525f34537452,0x61702e202c5f5366,0x696c612e206d6172\n"
".quad 0x38622e2034206e67,0x70616475635f5f20,0x5a5f5f37666d7261,0x6c416c6176653931\n"
".quad 0x6174756d7265506c,0x364b50736e6f6974,0x4b503374616f6c66,0x6a525f345374526a\n"
".quad 0x5d32315b5f536650,0x722e090a7b090a29,0x203233752e206765,0x0a3b3e39373c7225\n"
".quad 0x752e206765722e09,0x343c647225203436,0x65722e090a3b3e31,0x25203233662e2067\n"
".quad 0x0a3b3e3936323c66,0x702e206765722e09,0x313c702520646572,0x6f6c2e090a3b3e33\n"
".quad 0x3533330937310963,0x6257444c240a3009,0x315a5f5f6e696765,0x6c6c416c61766539\n"
".quad 0x746174756d726550,0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452\n"
".quad 0x646c090a3a5f5366,0x752e6d617261702e,0x3164722509203436,0x6475635f5f5b202c\n"
".quad 0x5f31666d72617061,0x6c61766539315a5f,0x756d7265506c6c41,0x50736e6f69746174\n"
".quad 0x3374616f6c66364b,0x5f345374526a4b50,0x3b5d5f5366506a52,0x36732e766f6d090a\n"
".quad 0x2c32647225092034,0x090a3b3164722520,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x635f5f5b202c3364,0x666d726170616475,0x766539315a5f5f32,0x7265506c6c416c61\n"
".quad 0x6e6f69746174756d,0x616f6c66364b5073,0x5374526a4b503374,0x5f5366506a525f34\n"
".quad 0x2e766f6d090a3b5d,0x6472250920343673,0x3b33647225202c34,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5f5b202c35647225,0x726170616475635f,0x39315a5f5f33666d\n"
".quad 0x506c6c416c617665,0x69746174756d7265,0x6c66364b50736e6f,0x526a4b503374616f\n"
".quad 0x66506a525f345374,0x6f6d090a3b5d5f53,0x2509203436732e76,0x647225202c366472\n"
".quad 0x702e646c090a3b35,0x3436752e6d617261,0x202c376472250920,0x70616475635f5f5b\n"
".quad 0x5a5f5f34666d7261,0x6c416c6176653931,0x6174756d7265506c,0x364b50736e6f6974\n"
".quad 0x4b503374616f6c66,0x6a525f345374526a,0x090a3b5d5f536650,0x203436732e766f6d\n"
".quad 0x25202c3864722509,0x646c090a3b376472,0x752e6d617261702e,0x3964722509203436\n"
".quad 0x6475635f5f5b202c,0x5f35666d72617061,0x6c61766539315a5f,0x756d7265506c6c41\n"
".quad 0x50736e6f69746174,0x3374616f6c66364b,0x5f345374526a4b50,0x3b5d5f5366506a52\n"
".quad 0x36732e766f6d090a,0x3031647225092034,0x0a3b39647225202c,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5b202c31316472,0x726170616475635f,0x39315a5f5f36666d\n"
".quad 0x506c6c416c617665,0x69746174756d7265,0x6c66364b50736e6f,0x526a4b503374616f\n"
".quad 0x66506a525f345374,0x6f6d090a3b5d5f53,0x2509203436732e76,0x7225202c32316472\n"
".quad 0x646c090a3b313164,0x662e6d617261702e,0x2c31662509203233,0x616475635f5f5b20\n"
".quad 0x5f5f37666d726170,0x416c61766539315a,0x74756d7265506c6c,0x4b50736e6f697461\n"
".quad 0x503374616f6c6636,0x525f345374526a4b,0x5d302b5f5366506a,0x662e766f6d090a3b\n"
".quad 0x2c32662509203233,0x6c090a3b31662520,0x2e6d617261702e64,0x3366250920323366\n"
".quad 0x6475635f5f5b202c,0x5f37666d72617061,0x6c61766539315a5f,0x756d7265506c6c41\n"
".quad 0x50736e6f69746174,0x3374616f6c66364b,0x5f345374526a4b50,0x342b5f5366506a52\n"
".quad 0x2e766f6d090a3b5d,0x3466250920323366,0x090a3b336625202c,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c35,0x37666d7261706164,0x61766539315a5f5f\n"
".quad 0x6d7265506c6c416c,0x736e6f6974617475,0x74616f6c66364b50,0x345374526a4b5033\n"
".quad 0x2b5f5366506a525f,0x766f6d090a3b5d38,0x662509203233662e,0x0a3b356625202c36\n"
".quad 0x3233732e766f6d09,0x30202c3172250920,0x732e747663090a3b,0x09203233752e3233\n"
".quad 0x697425202c327225,0x6f6d090a3b782e64,0x2509203233662e76,0x66376630202c3766\n"
".quad 0x203b666666666637,0x202f2f0920202020,0x6532383230342e33,0x766f6d090a38332b\n"
".quad 0x722509203436752e,0x6f7270202c333164,0x6f6d090a3b347364,0x2509203436752e76\n"
".quad 0x6c61202c34316472,0x656c626154616870,0x61747663090a3b34,0x2e6465726168732e\n"
".quad 0x6472250920343675,0x75635f5f202c3531,0x6c61636f6c5f6164,0x3437335f7261765f\n"
".quad 0x6f6e5f34335f3439,0x5f74736e6f635f6e,0x74756d7265705f73,0x5f5f736e6f697461\n"
".quad 0x345f744c240a3b32,0x200a3a303337395f,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x73656e202c353333,0x70656420676e6974,0x65202c31203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x0a3631203a736e6f,0x373109636f6c2e09\n"
".quad 0x090a300935343309,0x203233732e646461,0x7225202c33722509,0x0a3b327225202c31\n"
".quad 0x3233752e766f6d09,0x39202c3472250920,0x746573090a3b3139,0x3233732e74672e70\n"
".quad 0x25202c3170250920,0x3b347225202c3372,0x622031702540090a,0x5f744c2409206172\n"
".quad 0x200a3b3835325f34,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353333,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x6c2e090a30333739,0x343309373109636f,0x6c756d090a300938,0x203233752e6f6c2e\n"
".quad 0x7225202c35722509,0x63090a3b34202c33,0x752e3436752e7476,0x3164722509203233\n"
".quad 0x0a3b357225202c36,0x3436752e64646109,0x2c37316472250920,0x202c363164722520\n"
".quad 0x6c090a3b34647225,0x2509203233752e64,0x6472255b202c3672,0x090a3b5d302b3731\n"
".quad 0x203233752e766f6d,0x3531202c37722509,0x70746573090a3b39,0x203233732e74672e\n"
".quad 0x7225202c32702509,0x0a3b377225202c33,0x7262203270254009,0x345f744c24092061\n"
".quad 0x200a3b363839395f,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353333,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x6c2e090a30333739,0x343309373109636f,0x747663090a300939,0x3233732e3436732e\n"
".quad 0x2c38316472250920,0x6d090a3b33722520,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x2c337225202c3931,0x646461090a3b3420,0x722509203436752e,0x647225202c303264\n"
".quad 0x31647225202c3531,0x752e7473090a3b39,0x6472255b09203233,0x25202c5d302b3032\n"
".quad 0x5f744c240a3b3672,0x0a3a363839395f34,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35333320,0x6c6562616c206461\n"
".quad 0x345f744c24206465,0x2e090a303337395f,0x3309373109636f6c,0x6f6d090a30093135\n"
".quad 0x2509203233732e76,0x090a3b30202c3872,0x203233732e766f6d,0x3b30202c39722509\n"
".quad 0x33732e766f6d090a,0x2c30317225092032,0x766f6d090a3b3020,0x662509203233662e\n"
".quad 0x3030306630202c38,0x20203b3030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x202c396625092032,0x3030303030306630,0x20202020203b3030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c30316625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x345f744c240a3020,0x0a3a30313031315f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x656e202c31353320,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6f69746172657469,0x090a3631203a736e,0x09373109636f6c2e,0x73090a3009343232\n"
".quad 0x09203233752e7268,0x7225202c31317225,0x0a3b387225202c36,0x3233622e646e6109\n"
".quad 0x202c323172250920,0x3b33202c31317225,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c31326472,0x6c756d090a3b3231,0x33752e656469772e,0x3232647225092032\n"
".quad 0x202c32317225202c,0x2e646461090a3b34,0x6472250920343675,0x32647225202c3332\n"
".quad 0x3431647225202c32,0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3131662509\n"
".quad 0x5d302b3332647225,0x752e747663090a3b,0x09203233752e3436,0x25202c3432647225\n"
".quad 0x646461090a3b3972,0x722509203436752e,0x647225202c353264,0x32647225202c3432\n"
".quad 0x33662e646c090a3b,0x2c32316625092032,0x2b35326472255b20,0x616d66090a3b5d30\n"
".quad 0x203233662e6e722e,0x25202c3031662509,0x316625202c323166,0x3b30316625202c31\n"
".quad 0x3233662e646c090a,0x202c333166250920,0x342b35326472255b,0x2e616d66090a3b5d\n"
".quad 0x09203233662e6e72,0x316625202c396625,0x2c31316625202c33,0x6c090a3b39662520\n"
".quad 0x2509203233662e64,0x72255b202c343166,0x0a3b5d382b353264,0x2e6e722e616d6609\n"
".quad 0x3866250920323366,0x202c34316625202c,0x6625202c31316625,0x636f6c2e090a3b38\n"
".quad 0x0935323209373109,0x752e646461090a30,0x3264722509203436,0x3232647225202c36\n"
".quad 0x3b3331647225202c,0x6e6f632e646c090a,0x09203233732e7473,0x255b202c33317225\n"
".quad 0x3b5d302b36326472,0x33732e646461090a,0x2c30317225092032,0x25202c3331722520\n"
".quad 0x6461090a3b303172,0x2509203233752e64,0x2c397225202c3972,0x6461090a3b323120\n"
".quad 0x2509203233732e64,0x2c387225202c3872,0x766f6d090a3b3220,0x722509203233752e\n"
".quad 0x0a3b3233202c3431,0x656e2e7074657309,0x702509203233732e,0x202c387225202c33\n"
".quad 0x40090a3b34317225,0x2061726220337025,0x315f345f744c2409,0x2f200a3b30313031\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079\n"
".quad 0x64616568202c3533,0x64656c6562616c20,0x395f345f744c2420,0x6f6c2e090a303337\n"
".quad 0x3336320937310963,0x2e646e61090a3009,0x3172250920323362,0x2c30317225202c35\n"
".quad 0x73090a3b35353220,0x09203233732e7268,0x7225202c36317225,0x0a3b3631202c3031\n"
".quad 0x3233732e72687309,0x202c373172250920,0x3b38202c30317225,0x33662e766f6d090a\n"
".quad 0x2c35316625092032,0x3030313134663020,0x202020203b303030,0x6d090a39202f2f09\n"
".quad 0x09203233662e6c75,0x6625202c36316625,0x3b35316625202c32,0x33662e766f6d090a\n"
".quad 0x2c37316625092032,0x3030313134663020,0x202020203b303030,0x6d090a39202f2f09\n"
".quad 0x09203233662e6c75,0x6625202c38316625,0x3b37316625202c34,0x33662e766f6d090a\n"
".quad 0x2c39316625092032,0x3030313134663020,0x202020203b303030,0x6d090a39202f2f09\n"
".quad 0x09203233662e6c75,0x6625202c30326625,0x3b39316625202c36,0x6e722e747663090a\n"
".quad 0x3233732e3233662e,0x202c313266250920,0x63090a3b35317225,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x317225202c323266,0x2e646e61090a3b36,0x3172250920323362\n"
".quad 0x2c37317225202c38,0x73090a3b35353220,0x09203233662e6275,0x6625202c33326625\n"
".quad 0x30316625202c3631,0x662e627573090a3b,0x3432662509203233,0x202c38316625202c\n"
".quad 0x7573090a3b396625,0x2509203233662e62,0x326625202c353266,0x0a3b386625202c30\n"
".quad 0x3233662e6c756d09,0x202c363266250920,0x6625202c31326625,0x747663090a3b3132\n"
".quad 0x2e3233662e6e722e,0x3266250920323373,0x3b38317225202c37,0x33662e6c756d090a\n"
".quad 0x2c38326625092032,0x25202c3132662520,0x756d090a3b333266,0x2509203233662e6c\n"
".quad 0x326625202c393266,0x3b34326625202c31,0x33662e6c756d090a,0x2c30336625092032\n"
".quad 0x25202c3132662520,0x756d090a3b353266,0x2509203233662e6c,0x326625202c313366\n"
".quad 0x3b37326625202c32,0x33662e627573090a,0x2c32336625092032,0x25202c3133662520\n"
".quad 0x756d090a3b363266,0x2509203233662e6c,0x326625202c333366,0x3b30316625202c37\n"
".quad 0x33662e6c756d090a,0x2c34336625092032,0x25202c3732662520,0x6c756d090a3b3966\n"
".quad 0x662509203233662e,0x37326625202c3533,0x090a3b386625202c,0x662e6e722e706372\n"
".quad 0x3633662509203233,0x0a3b32336625202c,0x3233662e62757309,0x202c373366250920\n"
".quad 0x6625202c33336625,0x627573090a3b3832,0x662509203233662e,0x34336625202c3833\n"
".quad 0x0a3b39326625202c,0x3233662e62757309,0x202c393366250920,0x6625202c35336625\n"
".quad 0x6c756d090a3b3033,0x662509203233662e,0x36336625202c3034,0x0a3b37336625202c\n"
".quad 0x3233662e6c756d09,0x202c313466250920,0x6625202c36336625,0x6c756d090a3b3833\n"
".quad 0x662509203233662e,0x36336625202c3234,0x0a3b39336625202c,0x7461732e74766309\n"
".quad 0x3233662e3233662e,0x202c333466250920,0x63090a3b30346625,0x662e7461732e7476\n"
".quad 0x09203233662e3233,0x6625202c34346625,0x747663090a3b3134,0x3233662e7461732e\n"
".quad 0x662509203233662e,0x32346625202c3534,0x662e766f6d090a3b,0x3634662509203233\n"
".quad 0x386631346630202c,0x2020203b30303030,0x0a3133202f2f0920,0x3233662e6c756d09\n"
".quad 0x202c373466250920,0x6625202c33346625,0x766f6d090a3b3634,0x662509203233662e\n"
".quad 0x32346630202c3834,0x203b303030306337,0x36202f2f09202020,0x662e6c756d090a33\n"
".quad 0x3934662509203233,0x202c34346625202c,0x6d090a3b38346625,0x09203233662e766f\n"
".quad 0x6630202c30356625,0x3030303038663134,0x2f2f09202020203b,0x6c756d090a313320\n"
".quad 0x662509203233662e,0x35346625202c3135,0x0a3b30356625202c,0x696e722e74766309\n"
".quad 0x3233662e3233662e,0x202c323566250920,0x63090a3b37346625,0x662e696e722e7476\n"
".quad 0x09203233662e3233,0x6625202c33356625,0x747663090a3b3934,0x3233662e696e722e\n"
".quad 0x662509203233662e,0x31356625202c3435,0x722e747663090a3b,0x662e3233752e697a\n"
".quad 0x3931722509203233,0x0a3b32356625202c,0x3233622e6c687309,0x202c303272250920\n"
".quad 0x3131202c39317225,0x722e747663090a3b,0x662e3233752e697a,0x3132722509203233\n"
".quad 0x0a3b33356625202c,0x3233622e6c687309,0x202c323272250920,0x3b35202c31327225\n"
".quad 0x3233622e726f090a,0x202c333272250920,0x7225202c30327225,0x747663090a3b3232\n"
".quad 0x3233752e697a722e,0x722509203233662e,0x34356625202c3432,0x33622e726f090a3b\n"
".quad 0x2c35327225092032,0x25202c3332722520,0x6c2e090a3b343272,0x363209373109636f\n"
".quad 0x6c756d090a300934,0x662509203233662e,0x31326625202c3535,0x0a3b30316625202c\n"
".quad 0x3233662e6c756d09,0x202c363566250920,0x6625202c31326625,0x2e6c756d090a3b39\n"
".quad 0x3566250920323366,0x2c31326625202c37,0x6d090a3b38662520,0x09203233662e6c75\n"
".quad 0x6625202c38356625,0x33326625202c3232,0x662e6c756d090a3b,0x3935662509203233\n"
".quad 0x202c32326625202c,0x6d090a3b34326625,0x09203233662e6c75,0x6625202c30366625\n"
".quad 0x35326625202c3232,0x662e627573090a3b,0x3136662509203233,0x202c38356625202c\n"
".quad 0x73090a3b35356625,0x09203233662e6275,0x6625202c32366625,0x36356625202c3935\n"
".quad 0x662e627573090a3b,0x3336662509203233,0x202c30366625202c,0x6d090a3b37356625\n"
".quad 0x09203233662e6c75,0x6625202c34366625,0x36336625202c3136,0x662e6c756d090a3b\n"
".quad 0x3536662509203233,0x202c32366625202c,0x6d090a3b36336625,0x09203233662e6c75\n"
".quad 0x6625202c36366625,0x36336625202c3336,0x732e747663090a3b,0x662e3233662e7461\n"
".quad 0x3736662509203233,0x0a3b34366625202c,0x7461732e74766309,0x3233662e3233662e\n"
".quad 0x202c383666250920,0x63090a3b35366625,0x662e7461732e7476,0x09203233662e3233\n"
".quad 0x6625202c39366625,0x766f6d090a3b3636,0x662509203233662e,0x31346630202c3037\n"
".quad 0x203b303030303866,0x33202f2f09202020,0x662e6c756d090a31,0x3137662509203233\n"
".quad 0x202c37366625202c,0x6d090a3b30376625,0x09203233662e766f,0x6630202c32376625\n"
".quad 0x3030303063373234,0x2f2f09202020203b,0x6c756d090a333620,0x662509203233662e\n"
".quad 0x38366625202c3337,0x0a3b32376625202c,0x3233662e766f6d09,0x202c343766250920\n"
".quad 0x3030386631346630,0x09202020203b3030,0x6d090a3133202f2f,0x09203233662e6c75\n"
".quad 0x6625202c35376625,0x34376625202c3936,0x722e747663090a3b,0x662e3233662e696e\n"
".quad 0x3637662509203233,0x0a3b31376625202c,0x696e722e74766309,0x3233662e3233662e\n"
".quad 0x202c373766250920,0x63090a3b33376625,0x662e696e722e7476,0x09203233662e3233\n"
".quad 0x6625202c38376625,0x747663090a3b3537,0x3233752e697a722e,0x722509203233662e\n"
".quad 0x36376625202c3632,0x622e6c6873090a3b,0x3732722509203233,0x202c36327225202c\n"
".quad 0x747663090a3b3131,0x3233752e697a722e,0x722509203233662e,0x37376625202c3832\n"
".quad 0x622e6c6873090a3b,0x3932722509203233,0x202c38327225202c,0x622e726f090a3b35\n"
".quad 0x3033722509203233,0x202c37327225202c,0x63090a3b39327225,0x752e697a722e7476\n"
".quad 0x09203233662e3233,0x6625202c31337225,0x2e726f090a3b3837,0x3372250920323362\n"
".quad 0x2c30337225202c32,0x090a3b3133722520,0x09373109636f6c2e,0x6d090a3009373632\n"
".quad 0x09203233662e766f,0x6630202c39376625,0x3137353334306433,0x2f2f09202020203b\n"
".quad 0x37323233302e3020,0x2e6c756d090a3537,0x3866250920323366,0x2c32356625202c30\n"
".quad 0x090a3b3937662520,0x203233662e6c756d,0x25202c3138662509,0x386625202c303866\n"
".quad 0x2e766f6d090a3b30,0x3866250920323366,0x3863336630202c32,0x20203b3931316231\n"
".quad 0x2e30202f2f092020,0x0a35313338353130,0x3233662e6c756d09,0x202c333866250920\n"
".quad 0x6625202c33356625,0x6c756d090a3b3238,0x662509203233662e,0x33386625202c3438\n"
".quad 0x0a3b33386625202c,0x3233662e766f6d09,0x202c353866250920,0x3533343064336630\n"
".quad 0x09202020203b3137,0x3233302e30202f2f,0x756d090a35373732,0x2509203233662e6c\n"
".quad 0x356625202c363866,0x3b35386625202c34,0x33662e6c756d090a,0x2c37386625092032\n"
".quad 0x25202c3638662520,0x6f6d090a3b363866,0x2509203233662e76,0x336630202c383866\n"
".quad 0x3b31373533343064,0x202f2f0920202020,0x3737323233302e30,0x662e6c756d090a35\n"
".quad 0x3938662509203233,0x202c36376625202c,0x6d090a3b38386625,0x09203233662e6c75\n"
".quad 0x6625202c30396625,0x39386625202c3938,0x662e766f6d090a3b,0x3139662509203233\n"
".quad 0x313863336630202c,0x2020203b39313162,0x302e30202f2f0920,0x090a353133383531\n"
".quad 0x203233662e6c756d,0x25202c3239662509,0x396625202c373766,0x2e6c756d090a3b31\n"
".quad 0x3966250920323366,0x2c32396625202c33,0x090a3b3239662520,0x203233662e766f6d\n"
".quad 0x30202c3439662509,0x3735333430643366,0x2f09202020203b31,0x323233302e30202f\n"
".quad 0x6c756d090a353737,0x662509203233662e,0x38376625202c3539,0x0a3b34396625202c\n"
".quad 0x3233662e6c756d09,0x202c363966250920,0x6625202c35396625,0x6c756d090a3b3539\n"
".quad 0x662509203233662e,0x39386625202c3739,0x0a3b30386625202c,0x3233662e6c756d09\n"
".quad 0x202c383966250920,0x6625202c32396625,0x6c756d090a3b3338,0x662509203233662e\n"
".quad 0x35396625202c3939,0x0a3b36386625202c,0x3233662e6c756d09,0x2c30303166250920\n"
".quad 0x25202c3038662520,0x756d090a3b303166,0x2509203233662e6c,0x6625202c31303166\n"
".quad 0x3b396625202c3338,0x33662e6c756d090a,0x3230316625092032,0x202c36386625202c\n"
".quad 0x756d090a3b386625,0x2509203233662e6c,0x6625202c33303166,0x39386625202c3332\n"
".quad 0x662e6c756d090a3b,0x3031662509203233,0x2c34326625202c34,0x090a3b3239662520\n"
".quad 0x203233662e6c756d,0x202c353031662509,0x6625202c35326625,0x6f6c2e090a3b3539\n"
".quad 0x3135330937310963,0x2e6c756d090a3009,0x3166250920323366,0x31326625202c3630\n"
".quad 0x0a3b38396625202c,0x3233662e6c756d09,0x2c37303166250920,0x25202c3132662520\n"
".quad 0x756d090a3b373966,0x2509203233662e6c,0x6625202c38303166,0x39396625202c3132\n"
".quad 0x662e6c756d090a3b,0x3031662509203233,0x2c32326625202c39,0x090a3b3438662520\n"
".quad 0x203233662e6c756d,0x202c303131662509,0x6625202c32326625,0x6c756d090a3b3138\n"
".quad 0x662509203233662e,0x326625202c313131,0x3b37386625202c32,0x33662e627573090a\n"
".quad 0x3231316625092032,0x2c3630316625202c,0x0a3b313031662520,0x3233662e62757309\n"
".quad 0x2c33313166250920,0x202c373031662520,0x090a3b3030316625,0x203233662e627573\n"
".quad 0x202c343131662509,0x25202c3830316625,0x6d090a3b32303166,0x09203233662e6c75\n"
".quad 0x25202c3531316625,0x396625202c373266,0x2e6c756d090a3b33,0x3166250920323366\n"
".quad 0x37326625202c3631,0x0a3b30396625202c,0x3233662e6c756d09,0x2c37313166250920\n"
".quad 0x25202c3732662520,0x7573090a3b363966,0x2509203233662e62,0x6625202c38313166\n"
".quad 0x316625202c323131,0x627573090a3b3430,0x662509203233662e,0x316625202c393131\n"
".quad 0x30316625202c3331,0x2e627573090a3b33,0x3166250920323366,0x31316625202c3032\n"
".quad 0x3530316625202c34,0x662e646461090a3b,0x3231662509203233,0x3930316625202c31\n"
".quad 0x3b3531316625202c,0x33662e646461090a,0x3232316625092032,0x2c3031316625202c\n"
".quad 0x0a3b363131662520,0x3233662e64646109,0x2c33323166250920,0x202c313131662520\n"
".quad 0x090a3b3731316625,0x203233662e646461,0x202c343231662509,0x25202c3831316625\n"
".quad 0x61090a3b38313166,0x09203233662e6464,0x25202c3532316625,0x6625202c39313166\n"
".quad 0x6461090a3b393131,0x2509203233662e64,0x6625202c36323166,0x316625202c303231\n"
".quad 0x646461090a3b3032,0x662509203233662e,0x316625202c373231,0x32316625202c3132\n"
".quad 0x2e646461090a3b34,0x3166250920323366,0x32316625202c3832,0x3532316625202c32\n"
".quad 0x662e646461090a3b,0x3231662509203233,0x3332316625202c39,0x3b3632316625202c\n"
".quad 0x6e6f632e646c090a,0x09203233662e7473,0x5b202c3033316625,0x654d726f6c6f436b\n"
".quad 0x3b5d342b63697274,0x33662e6c756d090a,0x3133316625092032,0x2c3033316625202c\n"
".quad 0x0a3b373231662520,0x736e6f632e646c09,0x2509203233662e74,0x6b5b202c32333166\n"
".quad 0x74654d726f6c6f43,0x0a3b5d302b636972,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x32316625202c3333,0x3233316625202c38,0x3b3133316625202c,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x5b202c3433316625,0x654d726f6c6f436b,0x3b5d382b63697274\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c353331,0x33316625202c3932\n"
".quad 0x3333316625202c34,0x662e766f6d090a3b,0x3331662509203233,0x6564336630202c36\n"
".quad 0x20203b3933653833,0x312e30202f2f0920,0x6d090a3131313131,0x09203233662e6c75\n"
".quad 0x25202c3733316625,0x6625202c35333166,0x6573090a3b363331,0x33662e746c2e7074\n"
".quad 0x202c347025092032,0x25202c3733316625,0x252140090a3b3766,0x0920617262203470\n"
".quad 0x31315f345f744c24,0x2f2f200a3b323235,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x333320656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x37395f345f744c24,0x636f6c2e090a3033,0x0935353309373109,0x662e766f6d090a30\n"
".quad 0x2c37662509203233,0x0a3b373331662520,0x373109636f6c2e09,0x090a300936353309\n"
".quad 0x09203233752e7473,0x302b30316472255b,0x0a3b367225202c5d,0x373109636f6c2e09\n"
".quad 0x090a300937353309,0x09203631752e7473,0x5d302b366472255b,0x0a3b35327225202c\n"
".quad 0x373109636f6c2e09,0x090a300938353309,0x09203631752e7473,0x5d302b386472255b\n"
".quad 0x0a3b32337225202c,0x31315f345f744c24,0x2f2f200a3a323235,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x333320656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x37395f345f744c24,0x636f6c2e090a3033,0x0932343309373109\n"
".quad 0x732e646461090a30,0x2c31722509203233,0x3436202c31722520,0x752e766f6d090a3b\n"
".quad 0x3333722509203233,0x0a3b34323031202c,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x202c317225202c35,0x40090a3b33337225,0x2061726220357025,0x395f345f744c2409\n"
".quad 0x744c240a3b303337,0x0a3a3835325f345f,0x373109636f6c2e09,0x090a300930363309\n"
".quad 0x09203631752e646c,0x255b202c34337225,0x0a3b5d302b366472,0x203631752e646c09\n"
".quad 0x5b202c3533722509,0x3b5d302b38647225,0x672e70746573090a,0x2509203233752e65\n"
".quad 0x34337225202c3670,0x0a3b35337225202c,0x7262203670254009,0x345f744c24092061\n"
".quad 0x0a3b30393232315f,0x373109636f6c2e09,0x6d090a3009323709,0x09203233732e766f\n"
".quad 0x7225202c36337225,0x6f6c2e090a3b3533,0x0933370937310963,0x31752e7473090a30\n"
".quad 0x386472255b092036,0x337225202c5d302b,0x636f6c2e090a3b34,0x3009343709373109\n"
".quad 0x3631752e7473090a,0x2b366472255b0920,0x36337225202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009353633093731,0x3233752e646c090a,0x202c373372250920,0x302b30316472255b\n"
".quad 0x2e726f78090a3b5d,0x3372250920323362,0x2c37337225202c38,0x3535363133343120\n"
".quad 0x7473090a3b353637,0x255b09203233752e,0x2c5d302b30316472,0x240a3b3833722520\n"
".quad 0x3232315f345f744c,0x766f6d090a3a3039,0x722509203233732e,0x090a3b30202c3933\n"
".quad 0x203436752e766f6d,0x202c373264722509,0x0a3b3373646f7270,0x3436752e766f6d09\n"
".quad 0x2c38326472250920,0x61546168706c6120,0x4c240a3b33656c62,0x313333315f345f74\n"
".quad 0x6c3c2f2f200a3a34,0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c35363320656e69\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6d69747365202c31,0x6574692064657461\n"
".quad 0x3a736e6f69746172,0x636f6c2e090a3320,0x0931373309373109,0x6c2e6c756d090a30\n"
".quad 0x2509203233732e6f,0x337225202c303472,0x090a3b3436202c39,0x203233732e646461\n"
".quad 0x25202c3134722509,0x327225202c303472,0x752e766f6d090a3b,0x3234722509203233\n"
".quad 0x090a3b393531202c,0x2e74672e70746573,0x3770250920323373,0x202c31347225202c\n"
".quad 0x40090a3b32347225,0x2061726220377025,0x646e6557444c2409,0x5f66746e69725f69\n"
".quad 0x200a3b325f333831,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353633,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x2e090a3431333331,0x3309373109636f6c,0x7663090a30093437,0x33732e3436732e74\n"
".quad 0x3932647225092032,0x0a3b31347225202c,0x6469772e6c756d09,0x2509203233732e65\n"
".quad 0x7225202c30336472,0x090a3b34202c3134,0x203436752e646461,0x202c313364722509\n"
".quad 0x25202c3531647225,0x6c090a3b30336472,0x2509203233752e64,0x72255b202c333472\n"
".quad 0x0a3b5d302b313364,0x373109636f6c2e09,0x090a300935373309,0x203233732e766f6d\n"
".quad 0x30202c3434722509,0x732e766f6d090a3b,0x3534722509203233,0x6f6d090a3b30202c\n"
".quad 0x2509203233732e76,0x0a3b30202c363472,0x3233662e766f6d09,0x2c38333166250920\n"
".quad 0x3030303030663020,0x092020203b303030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x6630202c39333166,0x3030303030303030,0x202f2f092020203b,0x662e766f6d090a30\n"
".quad 0x3431662509203233,0x3030306630202c30,0x20203b3030303030,0x240a30202f2f0920\n"
".quad 0x3034315f345f744c,0x3c2f2f200a3a3238,0x6f4c203e706f6f6c,0x2079646f6220706f\n"
".quad 0x35373320656e696c,0x6e697473656e202c,0x3a68747065642067,0x72657469202c3120\n"
".quad 0x203a736e6f697461,0x636f6c2e090a3631,0x0935383209373109,0x752e726873090a30\n"
".quad 0x3734722509203233,0x202c33347225202c,0x61090a3b34347225,0x09203233622e646e\n"
".quad 0x7225202c38347225,0x090a3b33202c3734,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x38347225202c3233,0x772e6c756d090a3b,0x203233752e656469,0x202c333364722509\n"
".quad 0x3b34202c38347225,0x36752e646461090a,0x3433647225092034,0x2c3333647225202c\n"
".quad 0x0a3b383264722520,0x736e6f632e646c09,0x2509203233662e74,0x255b202c31343166\n"
".quad 0x3b5d302b34336472,0x36752e747663090a,0x2509203233752e34,0x7225202c35336472\n"
".quad 0x646461090a3b3534,0x722509203436752e,0x647225202c363364,0x32647225202c3533\n"
".quad 0x33662e646c090a3b,0x3234316625092032,0x36336472255b202c,0x6d66090a3b5d302b\n"
".quad 0x3233662e6e722e61,0x2c30343166250920,0x202c323431662520,0x25202c3134316625\n"
".quad 0x6c090a3b30343166,0x2509203233662e64,0x255b202c33343166,0x3b5d342b36336472\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c393331,0x34316625202c3334\n"
".quad 0x3933316625202c31,0x33662e646c090a3b,0x3434316625092032,0x36336472255b202c\n"
".quad 0x6d66090a3b5d382b,0x3233662e6e722e61,0x2c38333166250920,0x202c343431662520\n"
".quad 0x25202c3134316625,0x2e090a3b38333166,0x3209373109636f6c,0x6461090a30093638\n"
".quad 0x2509203436752e64,0x7225202c37336472,0x647225202c333364,0x2e646c090a3b3732\n"
".quad 0x33732e74736e6f63,0x2c39347225092032,0x2b37336472255b20,0x646461090a3b5d30\n"
".quad 0x722509203233732e,0x39347225202c3634,0x0a3b36347225202c,0x3233752e64646109\n"
".quad 0x202c353472250920,0x3231202c35347225,0x732e646461090a3b,0x3434722509203233\n"
".quad 0x202c34347225202c,0x2e766f6d090a3b32,0x3572250920323375,0x090a3b3233202c30\n"
".quad 0x2e656e2e70746573,0x3870250920323373,0x202c34347225202c,0x40090a3b30357225\n"
".quad 0x2061726220387025,0x315f345f744c2409,0x2f200a3b32383034,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x64616568202c3536\n"
".quad 0x64656c6562616c20,0x315f345f744c2420,0x6c2e090a34313333,0x323309373109636f\n"
".quad 0x646e61090a300933,0x722509203233622e,0x36347225202c3135,0x090a3b353532202c\n"
".quad 0x203233732e726873,0x25202c3235722509,0x3b3631202c363472,0x33732e726873090a\n"
".quad 0x2c33357225092032,0x38202c3634722520,0x662e766f6d090a3b,0x3431662509203233\n"
".quad 0x3830346630202c35,0x20203b3030303030,0x090a34202f2f0920,0x203233662e6c756d\n"
".quad 0x202c363431662509,0x316625202c326625,0x766f6d090a3b3534,0x662509203233662e\n"
".quad 0x346630202c373431,0x3b30303030303830,0x34202f2f09202020,0x33662e6c756d090a\n"
".quad 0x3834316625092032,0x25202c346625202c,0x6d090a3b37343166,0x09203233662e766f\n"
".quad 0x30202c3934316625,0x3030303038303466,0x2f2f092020203b30,0x2e6c756d090a3420\n"
".quad 0x3166250920323366,0x2c366625202c3035,0x0a3b393431662520,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x202c313531662509,0x63090a3b31357225,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x7225202c32353166,0x646e61090a3b3235,0x722509203233622e\n"
".quad 0x33357225202c3435,0x090a3b353532202c,0x203233662e627573,0x202c333531662509\n"
".quad 0x25202c3634316625,0x73090a3b30343166,0x09203233662e6275,0x25202c3435316625\n"
".quad 0x6625202c38343166,0x7573090a3b393331,0x2509203233662e62,0x6625202c35353166\n"
".quad 0x316625202c303531,0x6c756d090a3b3833,0x662509203233662e,0x316625202c363531\n"
".quad 0x35316625202c3135,0x2e747663090a3b31,0x732e3233662e6e72,0x3531662509203233\n"
".quad 0x3b34357225202c37,0x33662e6c756d090a,0x3835316625092032,0x2c3135316625202c\n"
".quad 0x0a3b333531662520,0x3233662e6c756d09,0x2c39353166250920,0x202c313531662520\n"
".quad 0x090a3b3435316625,0x203233662e6c756d,0x202c303631662509,0x25202c3135316625\n"
".quad 0x6d090a3b35353166,0x09203233662e6c75,0x25202c3136316625,0x6625202c32353166\n"
".quad 0x7573090a3b373531,0x2509203233662e62,0x6625202c32363166,0x316625202c313631\n"
".quad 0x6c756d090a3b3635,0x662509203233662e,0x316625202c333631,0x34316625202c3735\n"
".quad 0x2e6c756d090a3b30,0x3166250920323366,0x35316625202c3436,0x3933316625202c37\n"
".quad 0x662e6c756d090a3b,0x3631662509203233,0x3735316625202c35,0x3b3833316625202c\n"
".quad 0x6e722e706372090a,0x662509203233662e,0x316625202c363631,0x627573090a3b3236\n"
".quad 0x662509203233662e,0x316625202c373631,0x35316625202c3336,0x2e627573090a3b38\n"
".quad 0x3166250920323366,0x36316625202c3836,0x3935316625202c34,0x662e627573090a3b\n"
".quad 0x3631662509203233,0x3536316625202c39,0x3b3036316625202c,0x33662e6c756d090a\n"
".quad 0x3037316625092032,0x2c3636316625202c,0x0a3b373631662520,0x3233662e6c756d09\n"
".quad 0x2c31373166250920,0x202c363631662520,0x090a3b3836316625,0x203233662e6c756d\n"
".quad 0x202c323731662509,0x25202c3636316625,0x63090a3b39363166,0x662e7461732e7476\n"
".quad 0x09203233662e3233,0x25202c3337316625,0x63090a3b30373166,0x662e7461732e7476\n"
".quad 0x09203233662e3233,0x25202c3437316625,0x63090a3b31373166,0x662e7461732e7476\n"
".quad 0x09203233662e3233,0x25202c3537316625,0x6d090a3b32373166,0x09203233662e766f\n"
".quad 0x30202c3637316625,0x3030303866313466,0x2f2f092020203b30,0x6c756d090a313320\n"
".quad 0x662509203233662e,0x316625202c373731,0x37316625202c3337,0x2e766f6d090a3b36\n"
".quad 0x3166250920323366,0x32346630202c3837,0x203b303030306337,0x3336202f2f092020\n"
".quad 0x33662e6c756d090a,0x3937316625092032,0x2c3437316625202c,0x0a3b383731662520\n"
".quad 0x3233662e766f6d09,0x2c30383166250920,0x3038663134663020,0x092020203b303030\n"
".quad 0x6d090a3133202f2f,0x09203233662e6c75,0x25202c3138316625,0x6625202c35373166\n"
".quad 0x7663090a3b303831,0x33662e696e722e74,0x2509203233662e32,0x6625202c32383166\n"
".quad 0x7663090a3b373731,0x33662e696e722e74,0x2509203233662e32,0x6625202c33383166\n"
".quad 0x7663090a3b393731,0x33662e696e722e74,0x2509203233662e32,0x6625202c34383166\n"
".quad 0x7663090a3b313831,0x33752e697a722e74,0x2509203233662e32,0x316625202c353572\n"
".quad 0x6c6873090a3b3238,0x722509203233622e,0x35357225202c3635,0x63090a3b3131202c\n"
".quad 0x752e697a722e7476,0x09203233662e3233,0x6625202c37357225,0x6873090a3b333831\n"
".quad 0x2509203233622e6c,0x357225202c383572,0x6f090a3b35202c37,0x2509203233622e72\n"
".quad 0x357225202c393572,0x3b38357225202c36,0x7a722e747663090a,0x33662e3233752e69\n"
".quad 0x2c30367225092032,0x0a3b343831662520,0x203233622e726f09,0x25202c3136722509\n"
".quad 0x367225202c393572,0x636f6c2e090a3b30,0x0934323309373109,0x662e6c756d090a30\n"
".quad 0x3831662509203233,0x3135316625202c35,0x3b3034316625202c,0x33662e6c756d090a\n"
".quad 0x3638316625092032,0x2c3135316625202c,0x0a3b393331662520,0x3233662e6c756d09\n"
".quad 0x2c37383166250920,0x202c313531662520,0x090a3b3833316625,0x203233662e6c756d\n"
".quad 0x202c383831662509,0x25202c3235316625,0x6d090a3b33353166,0x09203233662e6c75\n"
".quad 0x25202c3938316625,0x6625202c32353166,0x756d090a3b343531,0x2509203233662e6c\n"
".quad 0x6625202c30393166,0x316625202c323531,0x627573090a3b3535,0x662509203233662e\n"
".quad 0x316625202c313931,0x38316625202c3838,0x2e627573090a3b35,0x3166250920323366\n"
".quad 0x38316625202c3239,0x3638316625202c39,0x662e627573090a3b,0x3931662509203233\n"
".quad 0x3039316625202c33,0x3b3738316625202c,0x33662e6c756d090a,0x3439316625092032\n"
".quad 0x2c3139316625202c,0x0a3b363631662520,0x3233662e6c756d09,0x2c35393166250920\n"
".quad 0x202c323931662520,0x090a3b3636316625,0x203233662e6c756d,0x202c363931662509\n"
".quad 0x25202c3339316625,0x63090a3b36363166,0x662e7461732e7476,0x09203233662e3233\n"
".quad 0x25202c3739316625,0x63090a3b34393166,0x662e7461732e7476,0x09203233662e3233\n"
".quad 0x25202c3839316625,0x63090a3b35393166,0x662e7461732e7476,0x09203233662e3233\n"
".quad 0x25202c3939316625,0x6d090a3b36393166,0x09203233662e766f,0x30202c3030326625\n"
".quad 0x3030303866313466,0x2f2f092020203b30,0x6c756d090a313320,0x662509203233662e\n"
".quad 0x316625202c313032,0x30326625202c3739,0x2e766f6d090a3b30,0x3266250920323366\n"
".quad 0x32346630202c3230,0x203b303030306337,0x3336202f2f092020,0x33662e6c756d090a\n"
".quad 0x3330326625092032,0x2c3839316625202c,0x0a3b323032662520,0x3233662e766f6d09\n"
".quad 0x2c34303266250920,0x3038663134663020,0x092020203b303030,0x6d090a3133202f2f\n"
".quad 0x09203233662e6c75,0x25202c3530326625,0x6625202c39393166,0x7663090a3b343032\n"
".quad 0x33662e696e722e74,0x2509203233662e32,0x6625202c36303266,0x7663090a3b313032\n"
".quad 0x33662e696e722e74,0x2509203233662e32,0x6625202c37303266,0x7663090a3b333032\n"
".quad 0x33662e696e722e74,0x2509203233662e32,0x6625202c38303266,0x7663090a3b353032\n"
".quad 0x33752e697a722e74,0x2509203233662e32,0x326625202c323672,0x6c6873090a3b3630\n"
".quad 0x722509203233622e,0x32367225202c3336,0x63090a3b3131202c,0x752e697a722e7476\n"
".quad 0x09203233662e3233,0x6625202c34367225,0x6873090a3b373032,0x2509203233622e6c\n"
".quad 0x367225202c353672,0x6f090a3b35202c34,0x2509203233622e72,0x367225202c363672\n"
".quad 0x3b35367225202c33,0x7a722e747663090a,0x33662e3233752e69,0x2c37367225092032\n"
".quad 0x0a3b383032662520,0x203233622e726f09,0x25202c3836722509,0x367225202c363672\n"
".quad 0x2e747663090a3b37,0x203233752e363175,0x25202c3936722509,0x6c2e090a3b383672\n"
".quad 0x323309373109636f,0x766f6d090a300937,0x662509203233662e,0x336630202c393032\n"
".quad 0x3b31373533343064,0x30202f2f09202020,0x353737323233302e,0x33662e6c756d090a\n"
".quad 0x3031326625092032,0x2c3238316625202c,0x0a3b393032662520,0x3233662e6c756d09\n"
".quad 0x2c31313266250920,0x202c303132662520,0x090a3b3031326625,0x203233662e766f6d\n"
".quad 0x202c323132662509,0x3162313863336630,0x2f092020203b3931,0x383531302e30202f\n"
".quad 0x6c756d090a353133,0x662509203233662e,0x316625202c333132,0x31326625202c3338\n"
".quad 0x2e6c756d090a3b32,0x3266250920323366,0x31326625202c3431,0x3331326625202c33\n"
".quad 0x662e766f6d090a3b,0x3132662509203233,0x3064336630202c35,0x20203b3137353334\n"
".quad 0x302e30202f2f0920,0x090a353737323233,0x203233662e6c756d,0x202c363132662509\n"
".quad 0x25202c3438316625,0x6d090a3b35313266,0x09203233662e6c75,0x25202c3731326625\n"
".quad 0x6625202c36313266,0x6f6d090a3b363132,0x2509203233662e76,0x6630202c38313266\n"
".quad 0x3137353334306433,0x202f2f092020203b,0x3737323233302e30,0x662e6c756d090a35\n"
".quad 0x3132662509203233,0x3630326625202c39,0x3b3831326625202c,0x33662e6c756d090a\n"
".quad 0x3032326625092032,0x2c3931326625202c,0x0a3b393132662520,0x3233662e766f6d09\n"
".quad 0x2c31323266250920,0x6231386333663020,0x092020203b393131,0x3531302e30202f2f\n"
".quad 0x756d090a35313338,0x2509203233662e6c,0x6625202c32323266,0x326625202c373032\n"
".quad 0x6c756d090a3b3132,0x662509203233662e,0x326625202c333232,0x32326625202c3232\n"
".quad 0x2e766f6d090a3b32,0x3266250920323366,0x64336630202c3432,0x203b313735333430\n"
".quad 0x2e30202f2f092020,0x0a35373732323330,0x3233662e6c756d09,0x2c35323266250920\n"
".quad 0x202c383032662520,0x090a3b3432326625,0x203233662e6c756d,0x202c363232662509\n"
".quad 0x25202c3532326625,0x6d090a3b35323266,0x09203233662e6c75,0x25202c3732326625\n"
".quad 0x6625202c39313266,0x756d090a3b303132,0x2509203233662e6c,0x6625202c38323266\n"
".quad 0x326625202c323232,0x6c756d090a3b3331,0x662509203233662e,0x326625202c393232\n"
".quad 0x31326625202c3532,0x2e6c756d090a3b36,0x3266250920323366,0x31326625202c3033\n"
".quad 0x3034316625202c30,0x662e6c756d090a3b,0x3332662509203233,0x3331326625202c31\n"
".quad 0x3b3933316625202c,0x33662e6c756d090a,0x3233326625092032,0x2c3631326625202c\n"
".quad 0x0a3b383331662520,0x3233662e6c756d09,0x2c33333266250920,0x202c333531662520\n"
".quad 0x090a3b3931326625,0x203233662e6c756d,0x202c343332662509,0x25202c3435316625\n"
".quad 0x6d090a3b32323266,0x09203233662e6c75,0x25202c3533326625,0x6625202c35353166\n"
".quad 0x6c2e090a3b353232,0x373309373109636f,0x6c756d090a300935,0x662509203233662e\n"
".quad 0x316625202c363332,0x32326625202c3135,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x35316625202c3733,0x3732326625202c31,0x662e6c756d090a3b,0x3332662509203233\n"
".quad 0x3135316625202c38,0x3b3932326625202c,0x33662e6c756d090a,0x3933326625092032\n"
".quad 0x2c3235316625202c,0x0a3b343132662520,0x3233662e6c756d09,0x2c30343266250920\n"
".quad 0x202c323531662520,0x090a3b3131326625,0x203233662e6c756d,0x202c313432662509\n"
".quad 0x25202c3235316625,0x73090a3b37313266,0x09203233662e6275,0x25202c3234326625\n"
".quad 0x6625202c36333266,0x7573090a3b313332,0x2509203233662e62,0x6625202c33343266\n"
".quad 0x326625202c373332,0x627573090a3b3033,0x662509203233662e,0x326625202c343432\n"
".quad 0x33326625202c3833,0x2e6c756d090a3b32,0x3266250920323366,0x35316625202c3534\n"
".quad 0x3332326625202c37,0x662e6c756d090a3b,0x3432662509203233,0x3735316625202c36\n"
".quad 0x3b3032326625202c,0x33662e6c756d090a,0x3734326625092032,0x2c3735316625202c\n"
".quad 0x0a3b363232662520,0x3233662e62757309,0x2c38343266250920,0x202c323432662520\n"
".quad 0x090a3b3433326625,0x203233662e627573,0x202c393432662509,0x25202c3334326625\n"
".quad 0x73090a3b33333266,0x09203233662e6275,0x25202c3035326625,0x6625202c34343266\n"
".quad 0x6461090a3b353332,0x2509203233662e64,0x6625202c31353266,0x326625202c393332\n"
".quad 0x646461090a3b3534,0x662509203233662e,0x326625202c323532,0x34326625202c3034\n"
".quad 0x2e646461090a3b36,0x3266250920323366,0x34326625202c3335,0x3734326625202c31\n"
".quad 0x662e646461090a3b,0x3532662509203233,0x3834326625202c34,0x3b3834326625202c\n"
".quad 0x33662e646461090a,0x3535326625092032,0x2c3934326625202c,0x0a3b393432662520\n"
".quad 0x3233662e64646109,0x2c36353266250920,0x202c303532662520,0x090a3b3035326625\n"
".quad 0x203233662e646461,0x202c373532662509,0x25202c3135326625,0x61090a3b34353266\n"
".quad 0x09203233662e6464,0x25202c3835326625,0x6625202c32353266,0x6461090a3b353532\n"
".quad 0x2509203233662e64,0x6625202c39353266,0x326625202c333532,0x2e646c090a3b3635\n"
".quad 0x33662e74736e6f63,0x3036326625092032,0x6f6c6f436b5b202c,0x2b63697274654d72\n"
".quad 0x6c756d090a3b5d34,0x662509203233662e,0x326625202c313632,0x35326625202c3036\n"
".quad 0x632e646c090a3b37,0x3233662e74736e6f,0x2c32363266250920,0x726f6c6f436b5b20\n"
".quad 0x302b63697274654d,0x2e616d66090a3b5d,0x09203233662e6e72,0x25202c3336326625\n"
".quad 0x6625202c38353266,0x326625202c323632,0x2e646c090a3b3136,0x33662e74736e6f63\n"
".quad 0x3436326625092032,0x6f6c6f436b5b202c,0x2b63697274654d72,0x616d66090a3b5d38\n"
".quad 0x203233662e6e722e,0x202c353632662509,0x25202c3935326625,0x6625202c34363266\n"
".quad 0x6f6d090a3b333632,0x2509203233662e76,0x6630202c36363266,0x3030303030386533\n"
".quad 0x202f2f092020203b,0x756d090a35322e30,0x2509203233662e6c,0x6625202c37363266\n"
".quad 0x326625202c353632,0x746573090a3b3636,0x3233662e746c2e70,0x25202c3970250920\n"
".quad 0x6625202c37363266,0x70252140090a3b37,0x2409206172622039,0x3534315f345f744c\n"
".quad 0x3c2f2f200a3b3439,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35363320656e696c,0x6c2064616568202c,0x242064656c656261,0x3333315f345f744c\n"
".quad 0x636f6c2e090a3431,0x0939373309373109,0x662e766f6d090a30,0x2c37662509203233\n"
".quad 0x0a3b373632662520,0x373109636f6c2e09,0x090a300930383309,0x09203233752e7473\n"
".quad 0x302b30316472255b,0x3b33347225202c5d,0x3109636f6c2e090a,0x0a30093138330937\n"
".quad 0x203631752e747309,0x302b366472255b09,0x3b31367225202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093238330937,0x203631752e747309,0x302b386472255b09,0x3b39367225202c5d\n"
".quad 0x3631752e646c090a,0x202c303772250920,0x5d302b366472255b,0x2e70746573090a3b\n"
".quad 0x09203233752e6567,0x7225202c30317025,0x30377225202c3936,0x3031702540090a3b\n"
".quad 0x4c24092061726220,0x303135315f345f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35363320656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313333315f345f74,0x09636f6c2e090a34,0x0a30093337093731\n"
".quad 0x203631752e747309,0x302b386472255b09,0x3b30377225202c5d,0x3109636f6c2e090a\n"
".quad 0x090a300934370937,0x09203631752e7473,0x5d302b366472255b,0x0a3b39367225202c\n"
".quad 0x373109636f6c2e09,0x090a300937383309,0x09203233752e646c,0x255b202c31377225\n"
".quad 0x3b5d302b30316472,0x33622e746f6e090a,0x2c32377225092032,0x090a3b3137722520\n"
".quad 0x203233752e726873,0x25202c3337722509,0x0a3b31202c323772,0x3233622e646e6109\n"
".quad 0x202c343772250920,0x3431202c33377225,0x3536373535363133,0x622e726f78090a3b\n"
".quad 0x3537722509203233,0x202c31377225202c,0x73090a3b34377225,0x5b09203233752e74\n"
".quad 0x5d302b3031647225,0x0a3b35377225202c,0x35315f345f744c24,0x744c240a3a363031\n"
".quad 0x34393534315f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35363320656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313333315f345f,0x3109636f6c2e090a,0x0a30093836330937,0x3233732e64646109\n"
".quad 0x202c393372250920,0x3b31202c39337225,0x33752e766f6d090a,0x2c36377225092032\n"
".quad 0x746573090a3b3320,0x3233732e656e2e70,0x202c313170250920,0x7225202c39337225\n"
".quad 0x702540090a3b3637,0x0920617262203131,0x33315f345f744c24,0x444c240a3b343133\n"
".quad 0x69725f69646e6557,0x5f3338315f66746e,0x636f6c2e090a3a32,0x0932393309373109\n"
".quad 0x6c2e6c756d090a30,0x2509203233752e6f,0x327225202c373772,0x7663090a3b34202c\n"
".quad 0x33752e3436752e74,0x3833647225092032,0x0a3b37377225202c,0x3436752e64646109\n"
".quad 0x2c39336472250920,0x202c383364722520,0x090a3b3231647225,0x09203233662e7473\n"
".quad 0x302b39336472255b,0x0a3b376625202c5d,0x373109636f6c2e09,0x090a300933393309\n"
".quad 0x444c240a3b746572,0x315a5f5f646e6557,0x6c6c416c61766539,0x746174756d726550\n"
".quad 0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452,0x207d090a3a5f5366\n"
".quad 0x6539315a5f202f2f,0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e\n"
".quad 0x74526a4b50337461,0x5366506a525f3453,0x7369762e090a0a5f,0x75662e20656c6269\n"
".quad 0x7773345a5f20636e,0x5452764574497061,0x702e28205f31535f,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x5f5f31666d726170,0x744970617773345a,0x5f31535f54527645\n"
".quad 0x6d617261702e202c,0x5f5f203436752e20,0x6d72617061647563,0x7773345a5f5f3266\n"
".quad 0x5452764574497061,0x7b090a295f31535f,0x2e206765722e090a,0x343c722520323375\n"
".quad 0x6765722e090a3b3e,0x7225203436752e20,0x2e090a3b3e363c64,0x3709373109636f6c\n"
".quad 0x57444c240a300931,0x5a5f5f6e69676562,0x4574497061777334,0x3a5f31535f545276\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x5f5b202c31647225,0x726170616475635f\n"
".quad 0x73345a5f5f31666d,0x5276457449706177,0x0a3b5d5f31535f54,0x3436732e766f6d09\n"
".quad 0x202c326472250920,0x6c090a3b31647225,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x75635f5f5b202c33,0x32666d7261706164,0x70617773345a5f5f,0x535f545276457449\n"
".quad 0x6f6d090a3b5d5f31,0x2509203436732e76,0x647225202c346472,0x636f6c2e090a3b33\n"
".quad 0x3009323709373109,0x3631752e646c090a,0x5b202c3172250920,0x3b5d302b32647225\n"
".quad 0x3109636f6c2e090a,0x090a300933370937,0x09203631752e646c,0x72255b202c327225\n"
".quad 0x090a3b5d302b3464,0x09203631752e7473,0x5d302b326472255b,0x090a3b327225202c\n"
".quad 0x09373109636f6c2e,0x7473090a30093437,0x255b09203631752e,0x202c5d302b346472\n"
".quad 0x6c2e090a3b317225,0x353709373109636f,0x3b746572090a3009,0x646e6557444c240a\n"
".quad 0x70617773345a5f5f,0x535f545276457449,0x2f207d090a3a5f31,0x617773345a5f202f\n"
".quad 0x5f54527645744970,0x68732e090a5f3153,0x6c612e2064657261,0x622e2034206e6769\n"
".quad 0x616475635f5f2038,0x765f6c61636f6c5f,0x37353537335f7261,0x5f6e6f6e5f33335f\n"
".quad 0x6e695f74736e6f63,0x315f5f7365636964,0x0a0a3b5d3635325b,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e,0x5f66746572616475\n"
".quad 0x646e696632315a5f,0x726f7272456e694d,0x32315a5f20296650,0x456e694d646e6966\n"
".quad 0x28206650726f7272,0x2e206d617261702e,0x75635f5f20343675,0x31666d7261706164\n"
".quad 0x6e696632315a5f5f,0x6f7272456e694d64,0x0a7b090a29665072,0x752e206765722e09\n"
".quad 0x30313c7225203233,0x6765722e090a3b3e,0x7225203436752e20,0x090a3b3e35313c64\n"
".quad 0x33662e206765722e,0x3b3e343c66252032,0x2e206765722e090a,0x3c70252064657270\n"
".quad 0x6f6c2e090a3b3e35,0x3030340937310963,0x6257444c240a3009,0x315a5f5f6e696765\n"
".quad 0x6e694d646e696632,0x3a6650726f727245,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c31647225,0x726170616475635f,0x32315a5f5f31666d,0x456e694d646e6966\n"
".quad 0x3b5d6650726f7272,0x36732e766f6d090a,0x2c32647225092034,0x090a3b3164722520\n"
".quad 0x6168732e61747663,0x203436752e646572,0x5f202c3364722509,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x33335f3735353733,0x6e6f635f6e6f6e5f,0x6369646e695f7473\n"
".quad 0x090a3b315f5f7365,0x09373109636f6c2e,0x63090a3009343034,0x752e3233732e7476\n"
".quad 0x2c31722509203233,0x3b782e6469742520,0x36732e747663090a,0x2509203233732e34\n"
".quad 0x317225202c346472,0x772e6c756d090a3b,0x203233732e656469,0x25202c3564722509\n"
".quad 0x090a3b34202c3172,0x203436752e646461,0x25202c3664722509,0x647225202c336472\n"
".quad 0x732e7473090a3b35,0x6472255b09203233,0x7225202c5d302b36,0x2e766f6d090a3b31\n"
".quad 0x3272250920323373,0x4c240a3b3233202c,0x303333335f365f74,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x202c34303420656e,0x20676e697473656e\n"
".quad 0x31203a6874706564,0x616d69747365202c,0x7265746920646574,0x203a736e6f697461\n"
".quad 0x0a6e776f6e6b6e75,0x373109636f6c2e09,0x090a300939303409,0x636e79732e726162\n"
".quad 0x6573090a3b300920,0x33732e656c2e7074,0x202c317025092032,0x317225202c327225\n"
".quad 0x2031702540090a3b,0x744c240920617262,0x3b363835335f365f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3430342065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x090a303333335f36,0x09373109636f6c2e\n"
".quad 0x61090a3009343134,0x09203233732e6464,0x327225202c337225,0x090a3b317225202c\n"
".quad 0x752e6f6c2e6c756d,0x2c34722509203233,0x3b34202c33722520,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x347225202c376472,0x752e646461090a3b,0x3864722509203436\n"
".quad 0x202c37647225202c,0x6c090a3b32647225,0x2509203233662e64,0x6472255b202c3166\n"
".quad 0x6d090a3b5d302b38,0x33752e6f6c2e6c75,0x202c357225092032,0x0a3b34202c317225\n"
".quad 0x3436752e74766309,0x722509203233752e,0x3b357225202c3964,0x36752e646461090a\n"
".quad 0x3031647225092034,0x202c39647225202c,0x6c090a3b32647225,0x2509203233662e64\n"
".quad 0x6472255b202c3266,0x090a3b5d302b3031,0x2e74672e70746573,0x3270250920323366\n"
".quad 0x25202c326625202c,0x252140090a3b3166,0x0920617262203270,0x30345f365f744c24\n"
".quad 0x3c2f2f200a3b3839,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x34303420656e696c,0x6c2064616568202c,0x242064656c656261,0x3333335f365f744c\n"
".quad 0x09636f6c2e090a30,0x3009373134093731,0x3233662e7473090a,0x30316472255b0920\n"
".quad 0x316625202c5d302b,0x09636f6c2e090a3b,0x3009383134093731,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x7225202c31316472,0x2e6c756d090a3b33,0x3233732e65646977\n"
".quad 0x2c32316472250920,0x3b34202c33722520,0x36752e646461090a,0x3331647225092034\n"
".quad 0x202c33647225202c,0x090a3b3231647225,0x09203233732e646c,0x72255b202c367225\n"
".quad 0x0a3b5d302b333164,0x203233732e747309,0x302b366472255b09,0x0a3b367225202c5d\n"
".quad 0x30345f365f744c24,0x5f744c240a3a3839,0x0a3a363835335f36,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c34303420\n"
".quad 0x6c6562616c206461,0x365f744c24206465,0x2e090a303333335f,0x3409373109636f6c\n"
".quad 0x6873090a30093730,0x2509203233732e72,0x2c327225202c3272,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x73090a3b30202c37,0x732e74672e707465,0x2c33702509203233\n"
".quad 0x7225202c32722520,0x33702540090a3b37,0x4c24092061726220,0x303333335f365f74\n"
".quad 0x09636f6c2e090a3b,0x3009323734093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x09373109636f6c2e,0x6c090a3009343734,0x6465726168732e64,0x722509203233732e\n"
".quad 0x75635f5f5b202c38,0x6c61636f6c5f6164,0x3537335f7261765f,0x6f6e5f33335f3735\n"
".quad 0x5f74736e6f635f6e,0x5f73656369646e69,0x090a3b5d302b315f,0x6d617261702e7473\n"
".quad 0x5f5b09203233732e,0x746572616475635f,0x696632315a5f5f66,0x7272456e694d646e\n"
".quad 0x25202c5d6650726f,0x746572090a3b3872,0x6e6557444c240a3b,0x696632315a5f5f64\n"
".quad 0x7272456e694d646e,0x7d090a3a6650726f,0x32315a5f202f2f20,0x456e694d646e6966\n"
".quad 0x0a0a6650726f7272,0x6c62697369762e09,0x20636e75662e2065,0x6576617333315a5f\n"
".quad 0x5458446b636f6c42,0x355069506a747431,0x2e282032746e6975,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5f31666d72617061,0x6576617333315a5f,0x5458446b636f6c42\n"
".quad 0x355069506a747431,0x2e202c32746e6975,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5f32666d72617061,0x6576617333315a5f,0x5458446b636f6c42,0x355069506a747431\n"
".quad 0x2e202c32746e6975,0x752e206d61726170,0x6475635f5f203233,0x5f33666d72617061\n"
".quad 0x6576617333315a5f,0x5458446b636f6c42,0x355069506a747431,0x2e202c32746e6975\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5f34666d72617061,0x6576617333315a5f\n"
".quad 0x5458446b636f6c42,0x355069506a747431,0x2e202c32746e6975,0x752e206d61726170\n"
".quad 0x6475635f5f203436,0x5f35666d72617061,0x6576617333315a5f,0x5458446b636f6c42\n"
".quad 0x355069506a747431,0x090a2932746e6975,0x206765722e090a7b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e373031,0x3436752e20676572,0x3b3e383c64722520,0x2e206765722e090a\n"
".quad 0x3c70252064657270,0x6f6c2e090a3b3e33,0x3238340937310963,0x6257444c240a3009\n"
".quad 0x315a5f5f6e696765,0x6f6c426576617333,0x7474315458446b63,0x6e6975355069506a\n"
".quad 0x2e646c090a3a3274,0x33752e6d61726170,0x202c317225092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f31666d7261,0x6c42657661733331,0x74315458446b636f,0x6975355069506a74\n"
".quad 0x63090a3b5d32746e,0x752e3631752e7476,0x2c32722509203233,0x6c090a3b31722520\n"
".quad 0x2e6d617261702e64,0x3372250920323375,0x6475635f5f5b202c,0x5f32666d72617061\n"
".quad 0x6576617333315a5f,0x5458446b636f6c42,0x355069506a747431,0x0a3b5d32746e6975\n"
".quad 0x3631752e74766309,0x722509203233752e,0x0a3b337225202c34,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x635f5f5b202c3572,0x666d726170616475,0x617333315a5f5f33\n"
".quad 0x446b636f6c426576,0x69506a7474315458,0x5d32746e69753550,0x732e766f6d090a3b\n"
".quad 0x2c36722509203233,0x6c090a3b35722520,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x75635f5f5b202c31,0x34666d7261706164,0x76617333315a5f5f,0x58446b636f6c4265\n"
".quad 0x5069506a74743154,0x3b5d32746e697535,0x36732e766f6d090a,0x2c32647225092034\n"
".quad 0x090a3b3164722520,0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3364\n"
".quad 0x666d726170616475,0x617333315a5f5f35,0x446b636f6c426576,0x69506a7474315458\n"
".quad 0x5d32746e69753550,0x732e766f6d090a3b,0x3464722509203436,0x0a3b33647225202c\n"
".quad 0x3233752e766f6d09,0x30202c3772250920,0x2e70746573090a3b,0x09203233752e7165\n"
".quad 0x327225202c317025,0x090a3b347225202c,0x3233752e706c6573,0x25202c3872250920\n"
".quad 0x2c367225202c3772,0x2e090a3b31702520,0x3409373109636f6c,0x646c090a30093539\n"
".quad 0x722509203233732e,0x326472255b202c39,0x756d090a3b5d302b,0x3233732e6f6c2e6c\n"
".quad 0x202c303172250920,0x0a3b32202c397225,0x3233752e72687309,0x202c313172250920\n"
".quad 0x317225202c387225,0x2e646e61090a3b30,0x3172250920323362,0x2c31317225202c32\n"
".quad 0x2e646c090a3b3320,0x3172250920323373,0x326472255b202c33,0x756d090a3b5d342b\n"
".quad 0x3233732e6f6c2e6c,0x202c343172250920,0x3b32202c33317225,0x33752e726873090a\n"
".quad 0x2c35317225092032,0x7225202c38722520,0x646e61090a3b3431,0x722509203233622e\n"
".quad 0x35317225202c3631,0x6873090a3b33202c,0x2509203233622e6c,0x317225202c373172\n"
".quad 0x6f090a3b32202c36,0x2509203233622e72,0x317225202c383172,0x3b37317225202c32\n"
".quad 0x3233732e646c090a,0x202c393172250920,0x5d382b326472255b,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x317225202c303272,0x73090a3b32202c39,0x09203233752e7268\n"
".quad 0x7225202c31327225,0x3b30327225202c38,0x33622e646e61090a,0x2c32327225092032\n"
".quad 0x33202c3132722520,0x622e6c6873090a3b,0x3332722509203233,0x202c32327225202c\n"
".quad 0x732e646c090a3b34,0x3432722509203233,0x2b326472255b202c,0x756d090a3b5d3231\n"
".quad 0x3233732e6f6c2e6c,0x202c353272250920,0x3b32202c34327225,0x33752e726873090a\n"
".quad 0x2c36327225092032,0x7225202c38722520,0x646e61090a3b3532,0x722509203233622e\n"
".quad 0x36327225202c3732,0x6873090a3b33202c,0x2509203233622e6c,0x327225202c383272\n"
".quad 0x6f090a3b36202c37,0x2509203233622e72,0x327225202c393272,0x3b38327225202c33\n"
".quad 0x3233622e726f090a,0x202c303372250920,0x7225202c38317225,0x2e646c090a3b3932\n"
".quad 0x3372250920323373,0x326472255b202c31,0x6d090a3b5d36312b,0x33732e6f6c2e6c75\n"
".quad 0x2c32337225092032,0x32202c3133722520,0x752e726873090a3b,0x3333722509203233\n"
".quad 0x25202c387225202c,0x6e61090a3b323372,0x2509203233622e64,0x337225202c343372\n"
".quad 0x73090a3b33202c33,0x09203233622e6c68,0x7225202c35337225,0x090a3b38202c3433\n"
".quad 0x09203233732e646c,0x255b202c36337225,0x3b5d30322b326472,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x36337225202c3733,0x6873090a3b32202c,0x2509203233752e72\n"
".quad 0x387225202c383372,0x0a3b37337225202c,0x3233622e646e6109,0x202c393372250920\n"
".quad 0x3b33202c38337225,0x33622e6c6873090a,0x2c30347225092032,0x31202c3933722520\n"
".quad 0x622e726f090a3b30,0x3134722509203233,0x202c35337225202c,0x6f090a3b30347225\n"
".quad 0x2509203233622e72,0x337225202c323472,0x3b31347225202c30,0x3233732e646c090a\n"
".quad 0x202c333472250920,0x34322b326472255b,0x2e6c756d090a3b5d,0x09203233732e6f6c\n"
".quad 0x7225202c34347225,0x090a3b32202c3334,0x203233752e726873,0x25202c3534722509\n"
".quad 0x34347225202c3872,0x622e646e61090a3b,0x3634722509203233,0x202c35347225202c\n"
".quad 0x2e6c6873090a3b33,0x3472250920323362,0x2c36347225202c37,0x646c090a3b323120\n"
".quad 0x722509203233732e,0x6472255b202c3834,0x090a3b5d38322b32,0x732e6f6c2e6c756d\n"
".quad 0x3934722509203233,0x202c38347225202c,0x2e726873090a3b32,0x3572250920323375\n"
".quad 0x202c387225202c30,0x61090a3b39347225,0x09203233622e646e,0x7225202c31357225\n"
".quad 0x090a3b33202c3035,0x203233622e6c6873,0x25202c3235722509,0x3b3431202c313572\n"
".quad 0x3233622e726f090a,0x202c333572250920,0x7225202c37347225,0x2e726f090a3b3235\n"
".quad 0x3572250920323362,0x2c32347225202c34,0x090a3b3335722520,0x09203233732e646c\n"
".quad 0x255b202c35357225,0x3b5d32332b326472,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x35357225202c3635,0x6873090a3b32202c,0x2509203233752e72,0x387225202c373572\n"
".quad 0x0a3b36357225202c,0x3233622e646e6109,0x202c383572250920,0x3b33202c37357225\n"
".quad 0x33622e6c6873090a,0x2c39357225092032,0x31202c3835722520,0x622e726f090a3b36\n"
".quad 0x3036722509203233,0x202c34357225202c,0x6c090a3b39357225,0x2509203233732e64\n"
".quad 0x72255b202c313672,0x0a3b5d36332b3264,0x2e6f6c2e6c756d09,0x3672250920323373\n"
".quad 0x2c31367225202c32,0x726873090a3b3220,0x722509203233752e,0x2c387225202c3336\n"
".quad 0x090a3b3236722520,0x203233622e646e61,0x25202c3436722509,0x0a3b33202c333672\n"
".quad 0x3233622e6c687309,0x202c353672250920,0x3831202c34367225,0x33622e726f090a3b\n"
".quad 0x2c36367225092032,0x25202c3036722520,0x646c090a3b353672,0x722509203233732e\n"
".quad 0x6472255b202c3736,0x090a3b5d30342b32,0x732e6f6c2e6c756d,0x3836722509203233\n"
".quad 0x202c37367225202c,0x2e726873090a3b32,0x3672250920323375,0x202c387225202c39\n"
".quad 0x61090a3b38367225,0x09203233622e646e,0x7225202c30377225,0x090a3b33202c3936\n"
".quad 0x203233622e6c6873,0x25202c3137722509,0x3b3032202c303772,0x3233622e726f090a\n"
".quad 0x202c323772250920,0x7225202c36367225,0x2e646c090a3b3137,0x3772250920323373\n"
".quad 0x326472255b202c33,0x6d090a3b5d34342b,0x33732e6f6c2e6c75,0x2c34377225092032\n"
".quad 0x32202c3337722520,0x752e726873090a3b,0x3537722509203233,0x25202c387225202c\n"
".quad 0x6e61090a3b343772,0x2509203233622e64,0x377225202c363772,0x73090a3b33202c35\n"
".quad 0x09203233622e6c68,0x7225202c37377225,0x0a3b3232202c3637,0x203233622e726f09\n"
".quad 0x25202c3837722509,0x377225202c323772,0x732e646c090a3b37,0x3937722509203233\n"
".quad 0x2b326472255b202c,0x756d090a3b5d3834,0x3233732e6f6c2e6c,0x202c303872250920\n"
".quad 0x3b32202c39377225,0x33752e726873090a,0x2c31387225092032,0x7225202c38722520\n"
".quad 0x646e61090a3b3038,0x722509203233622e,0x31387225202c3238,0x6873090a3b33202c\n"
".quad 0x2509203233622e6c,0x387225202c333872,0x090a3b3432202c32,0x09203233622e726f\n"
".quad 0x7225202c34387225,0x33387225202c3837,0x33732e646c090a3b,0x2c35387225092032\n"
".quad 0x352b326472255b20,0x6c756d090a3b5d32,0x203233732e6f6c2e,0x25202c3638722509\n"
".quad 0x0a3b32202c353872,0x3233752e72687309,0x202c373872250920,0x387225202c387225\n"
".quad 0x2e646e61090a3b36,0x3872250920323362,0x2c37387225202c38,0x6c6873090a3b3320\n"
".quad 0x722509203233622e,0x38387225202c3938,0x6f090a3b3632202c,0x2509203233622e72\n"
".quad 0x387225202c303972,0x3b39387225202c34,0x3233732e646c090a,0x202c313972250920\n"
".quad 0x36352b326472255b,0x2e6c756d090a3b5d,0x09203233732e6f6c,0x7225202c32397225\n"
".quad 0x090a3b32202c3139,0x203233752e726873,0x25202c3339722509,0x32397225202c3872\n"
".quad 0x622e646e61090a3b,0x3439722509203233,0x202c33397225202c,0x2e6c6873090a3b33\n"
".quad 0x3972250920323362,0x2c34397225202c35,0x726f090a3b383220,0x722509203233622e\n"
".quad 0x30397225202c3639,0x0a3b35397225202c,0x203233732e646c09,0x5b202c3739722509\n"
".quad 0x5d30362b32647225,0x6c2e6c756d090a3b,0x2509203233732e6f,0x397225202c383972\n"
".quad 0x73090a3b32202c37,0x09203233752e7268,0x7225202c39397225,0x3b38397225202c38\n"
".quad 0x33622e6c6873090a,0x3030317225092032,0x202c39397225202c,0x2e726f090a3b3033\n"
".quad 0x3172250920323362,0x36397225202c3130,0x3b3030317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093939340937,0x3233732e74766309,0x722509203233752e,0x746325202c323031\n"
".quad 0x090a3b782e646961,0x752e6f6c2e6c756d,0x3031722509203233,0x3230317225202c33\n"
".quad 0x7663090a3b38202c,0x33752e3436752e74,0x2c35647225092032,0x0a3b333031722520\n"
".quad 0x3436752e64646109,0x202c366472250920,0x7225202c35647225,0x6c6873090a3b3464\n"
".quad 0x722509203233622e,0x347225202c343031,0x6f090a3b3631202c,0x2509203233622e72\n"
".quad 0x7225202c35303172,0x3430317225202c32,0x32762e7473090a3b,0x255b09203233752e\n"
".quad 0x202c5d302b366472,0x252c35303172257b,0x090a3b7d31303172,0x09373109636f6c2e\n"
".quad 0x72090a3009333035,0x57444c240a3b7465,0x33315a5f5f646e65,0x636f6c4265766173\n"
".quad 0x6a7474315458446b,0x746e697535506950,0x2f2f207d090a3a32,0x76617333315a5f20\n"
".quad 0x58446b636f6c4265,0x5069506a74743154,0x0a0a32746e697535,0x207972746e652e09\n"
".quad 0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f,0x61702e09090a2820\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x63385a5f5f6d7261,0x5073736572706d6f\n"
".quad 0x7535505f30536a4b,0x7265705f32746e69,0x6e6f69746174756d,0x61702e09090a2c73\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x63385a5f5f6d7261,0x5073736572706d6f\n"
".quad 0x7535505f30536a4b,0x616d695f32746e69,0x702e09090a2c6567,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x385a5f5f6d726170,0x73736572706d6f63,0x35505f30536a4b50\n"
".quad 0x65725f32746e6975,0x7b090a29746c7573,0x2e206765722e090a,0x3c68722520363175\n"
".quad 0x65722e090a3b3e34,0x25203233752e2067,0x0a3b3e3739323c72,0x752e206765722e09\n"
".quad 0x313c647225203436,0x722e090a3b3e3431,0x203233662e206765,0x3b3e3532353c6625\n"
".quad 0x2e206765722e090a,0x3c70252064657270,0x732e090a3b3e3732,0x612e206465726168\n"
".quad 0x2e2034206e67696c,0x6475635f5f203862,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x38313637335f7261,0x5f6e6f6e5f36335f,0x6f635f74736e6f63,0x3836333173726f6c\n"
".quad 0x090a3b5d3239315b,0x206465726168732e,0x31206e67696c612e,0x5f5f2038622e2036\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f36335f393136\n"
".quad 0x74736e6f635f6e6f,0x363531736d75735f,0x0a3b5d3239315b30,0x6465726168732e09\n"
".quad 0x206e67696c612e20,0x5f2038622e203631,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f33335f30323637,0x736e6f635f6e6f6e,0x3173666572785f74\n"
".quad 0x3b5d34365b323537,0x65726168732e090a,0x6e67696c612e2064,0x5f2038622e203420\n"
".quad 0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61,0x5f35335f39323637\n"
".quad 0x736e6f635f6e6f6e,0x73726f7272655f74,0x3635325b36313831,0x5f202f2f090a3b5d\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x32315f3632363733,0x6e6f635f6e6f6e5f\n"
".quad 0x53747365625f7473,0x34203d2074726174,0x5f5f202f2f090a34,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f33325f36323637,0x736e6f635f6e6f6e,0x6e45747365625f74\n"
".quad 0x090a3634203d2064,0x6475635f5f202f2f,0x5f6c61636f6c5f61,0x323637335f726176\n"
".quad 0x6e6f6e5f30315f37,0x625f74736e6f635f,0x756d726550747365,0x3d206e6f69746174\n"
".quad 0x202f2f090a303420,0x6c5f616475635f5f,0x7261765f6c61636f,0x315f33343337335f\n"
".quad 0x6f635f6e6f6e5f32,0x20706d745f74736e,0x2f2f090a3832203d,0x5f616475635f5f20\n"
".quad 0x61765f6c61636f6c,0x5f32313037335f72,0x635f6e6f6e5f3231,0x6669645f74736e6f\n"
".quad 0x090a3631203d2066,0x09373109636f6c2e,0x4c240a3009393035,0x5f6e696765625744\n"
".quad 0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f,0x09636f6c2e090a3a\n"
".quad 0x3009373135093731,0x33732e747663090a,0x2509203233752e32,0x64697425202c3172\n"
".quad 0x766f6d090a3b782e,0x722509203233732e,0x090a3b3531202c32,0x2e656c2e70746573\n"
".quad 0x3170250920323373,0x25202c317225202c,0x252140090a3b3272,0x0920617262203170\n"
".quad 0x36335f385f744c24,0x6c2e090a3b343533,0x343109373109636f,0x766f6d090a300938\n"
".quad 0x722509203436752e,0x75635f5f202c3164,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x313637335f726176,0x6e6f6e5f36335f38,0x635f74736e6f635f,0x36333173726f6c6f\n"
".quad 0x2e747663090a3b38,0x203233752e323373,0x6325202c33722509,0x0a3b782e64696174\n"
".quad 0x2e6f6c2e6c756d09,0x3472250920323373,0x31202c337225202c,0x2e646461090a3b36\n"
".quad 0x3572250920323373,0x25202c317225202c,0x6c756d090a3b3472,0x203233752e6f6c2e\n"
".quad 0x7225202c36722509,0x63090a3b34202c35,0x752e3436752e7476,0x3264722509203233\n"
".quad 0x090a3b367225202c,0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3364\n"
".quad 0x5f6d726170616475,0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f\n"
".quad 0x3b5d6567616d695f,0x36752e646461090a,0x2c34647225092034,0x25202c3264722520\n"
".quad 0x646c090a3b336472,0x2e6c61626f6c672e,0x3772250920323375,0x2b346472255b202c\n"
".quad 0x6f6c2e090a3b5d30,0x3035310937310963,0x2e6c756d090a3009,0x09203233752e6f6c\n"
".quad 0x317225202c387225,0x63090a3b3231202c,0x752e3436752e7476,0x3564722509203233\n"
".quad 0x090a3b387225202c,0x203436752e646461,0x25202c3664722509,0x647225202c356472\n"
".quad 0x2e646e61090a3b31,0x3972250920323362,0x32202c377225202c,0x747663090a3b3535\n"
".quad 0x2e3233662e6e722e,0x3166250920323375,0x090a3b397225202c,0x203233662e766f6d\n"
".quad 0x6630202c32662509,0x3138303830386233,0x2f0920202020203b,0x393330302e30202f\n"
".quad 0x756d090a37353132,0x2509203233662e6c,0x2c316625202c3366,0x73090a3b32662520\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x202c5d302b366472,0x6c2e090a3b336625\n"
".quad 0x353109373109636f,0x6c6873090a300931,0x722509203233622e,0x2c377225202c3031\n"
".quad 0x6873090a3b363120,0x2509203233752e72,0x317225202c313172,0x090a3b3432202c30\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x317225202c346625,0x2e766f6d090a3b31\n"
".quad 0x3566250920323366,0x303862336630202c,0x2020203b31383038,0x2e30202f2f092020\n"
".quad 0x3735313239333030,0x33662e6c756d090a,0x202c366625092032,0x356625202c346625\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x2b366472255b0920,0x3b366625202c5d34\n"
".quad 0x3109636f6c2e090a,0x0a30093235310937,0x3233622e6c687309,0x202c323172250920\n"
".quad 0x0a3b38202c377225,0x3233752e72687309,0x202c333172250920,0x3432202c32317225\n"
".quad 0x722e747663090a3b,0x33752e3233662e6e,0x202c376625092032,0x6d090a3b33317225\n"
".quad 0x09203233662e766f,0x336630202c386625,0x3b31383038303862,0x2f2f092020202020\n"
".quad 0x32393330302e3020,0x6c756d090a373531,0x662509203233662e,0x202c376625202c39\n"
".quad 0x7473090a3b386625,0x2e6465726168732e,0x72255b0920323366,0x25202c5d382b3664\n"
".quad 0x5f744c240a3b3966,0x3a34353336335f38,0x36752e766f6d090a,0x2c31647225092034\n"
".quad 0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f38313637335f\n"
".quad 0x6f635f6e6f6e5f36,0x6f6c6f635f74736e,0x0a3b383633317372,0x373109636f6c2e09\n"
".quad 0x090a300936353109,0x636e79732e726162,0x2140090a3b300920,0x2061726220317025\n"
".quad 0x335f385f744c2409,0x2e090a3b36363836,0x3109373109636f6c,0x6f6d090a30093036\n"
".quad 0x2509203436752e76,0x635f5f202c376472,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3637335f7261765f,0x6f6e5f36335f3931,0x5f74736e6f635f6e,0x30363531736d7573\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c343172,0x63090a3b3231202c\n"
".quad 0x752e3436752e7476,0x3864722509203233,0x0a3b34317225202c,0x3436752e64646109\n"
".quad 0x202c366472250920,0x7225202c38647225,0x646461090a3b3164,0x722509203436752e\n"
".quad 0x38647225202c3964,0x0a3b37647225202c,0x726168732e646c09,0x09203233662e6465\n"
".quad 0x255b202c30316625,0x0a3b5d302b366472,0x726168732e747309,0x09203233662e6465\n"
".quad 0x5d302b396472255b,0x0a3b30316625202c,0x726168732e646c09,0x09203233662e6465\n"
".quad 0x255b202c31316625,0x0a3b5d342b366472,0x726168732e747309,0x09203233662e6465\n"
".quad 0x5d342b396472255b,0x0a3b31316625202c,0x726168732e646c09,0x09203233662e6465\n"
".quad 0x255b202c32316625,0x0a3b5d382b366472,0x726168732e747309,0x09203233662e6465\n"
".quad 0x5d382b396472255b,0x0a3b32316625202c,0x36335f385f744c24,0x6f6d090a3a363638\n"
".quad 0x2509203436752e76,0x635f5f202c376472,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3637335f7261765f,0x6f6e5f36335f3931,0x5f74736e6f635f6e,0x30363531736d7573\n"
".quad 0x732e726162090a3b,0x0a3b300920636e79,0x6220317025214009,0x5f744c2409206172\n"
".quad 0x3b38373337335f38,0x33622e726f78090a,0x2c35317225092032,0x3b38202c31722520\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x35317225202c3631,0x63090a3b3231202c\n"
".quad 0x752e3436752e7476,0x3164722509203233,0x3b36317225202c30,0x36752e646461090a\n"
".quad 0x3131647225092034,0x2c3031647225202c,0x090a3b3764722520,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c333166,0x0a3b5d342b313164,0x726168732e646c09\n"
".quad 0x09203233662e6465,0x255b202c34316625,0x3b5d382b31316472,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x2c317225202c3731,0x7663090a3b323120,0x33752e3436752e74\n"
".quad 0x3231647225092032,0x0a3b37317225202c,0x3436752e64646109,0x202c396472250920\n"
".quad 0x25202c3231647225,0x646c090a3b376472,0x2e6465726168732e,0x3166250920323366\n"
".quad 0x316472255b202c35,0x6c090a3b5d302b31,0x6465726168732e64,0x662509203233662e\n"
".quad 0x6472255b202c3631,0x61090a3b5d302b39,0x09203233662e6464,0x6625202c37316625\n"
".quad 0x36316625202c3531,0x68732e7473090a3b,0x3233662e64657261,0x2b396472255b0920\n"
".quad 0x37316625202c5d30,0x68732e646c090a3b,0x3233662e64657261,0x202c383166250920\n"
".quad 0x5d342b396472255b,0x662e646461090a3b,0x3931662509203233,0x202c38316625202c\n"
".quad 0x73090a3b33316625,0x6465726168732e74,0x255b09203233662e,0x202c5d342b396472\n"
".quad 0x6c090a3b39316625,0x6465726168732e64,0x662509203233662e,0x6472255b202c3032\n"
".quad 0x61090a3b5d382b39,0x09203233662e6464,0x6625202c31326625,0x34316625202c3032\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x2b396472255b0920,0x31326625202c5d38\n"
".quad 0x5f385f744c240a3b,0x090a3a3837333733,0x636e79732e726162,0x2140090a3b300920\n"
".quad 0x2061726220317025,0x335f385f744c2409,0x78090a3b30393837,0x09203233622e726f\n"
".quad 0x7225202c38317225,0x6d090a3b34202c31,0x33752e6f6c2e6c75,0x2c39317225092032\n"
".quad 0x31202c3831722520,0x2e747663090a3b32,0x203233752e343675,0x202c333164722509\n"
".quad 0x61090a3b39317225,0x09203436752e6464,0x25202c3431647225,0x7225202c33316472\n"
".quad 0x2e646c090a3b3764,0x662e646572616873,0x3232662509203233,0x34316472255b202c\n"
".quad 0x646c090a3b5d342b,0x2e6465726168732e,0x3266250920323366,0x316472255b202c33\n"
".quad 0x6d090a3b5d382b34,0x33752e6f6c2e6c75,0x2c30327225092032,0x3231202c31722520\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x25202c3531647225,0x6461090a3b303272\n"
".quad 0x2509203436752e64,0x647225202c396472,0x37647225202c3531,0x68732e646c090a3b\n"
".quad 0x3233662e64657261,0x202c343266250920,0x302b34316472255b,0x732e646c090a3b5d\n"
".quad 0x33662e6465726168,0x2c35326625092032,0x302b396472255b20,0x2e646461090a3b5d\n"
".quad 0x3266250920323366,0x2c34326625202c36,0x090a3b3532662520,0x65726168732e7473\n"
".quad 0x5b09203233662e64,0x2c5d302b39647225,0x090a3b3632662520,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c373266,0x090a3b5d342b3964,0x203233662e646461\n"
".quad 0x25202c3832662509,0x326625202c373266,0x732e7473090a3b32,0x33662e6465726168\n"
".quad 0x396472255b092032,0x326625202c5d342b,0x732e646c090a3b38,0x33662e6465726168\n"
".quad 0x2c39326625092032,0x382b396472255b20,0x2e646461090a3b5d,0x3366250920323366\n"
".quad 0x2c39326625202c30,0x090a3b3332662520,0x65726168732e7473,0x5b09203233662e64\n"
".quad 0x2c5d382b39647225,0x240a3b3033662520,0x3837335f385f744c,0x726162090a3a3039\n"
".quad 0x300920636e79732e,0x3170252140090a3b,0x4c24092061726220,0x303438335f385f74\n"
".quad 0x2e726f78090a3b32,0x3272250920323362,0x202c317225202c31,0x2e6c756d090a3b32\n"
".quad 0x09203233752e6f6c,0x7225202c32327225,0x0a3b3231202c3132,0x3436752e74766309\n"
".quad 0x722509203233752e,0x327225202c363164,0x2e646461090a3b32,0x6472250920343675\n"
".quad 0x31647225202c3731,0x3b37647225202c36,0x6168732e646c090a,0x203233662e646572\n"
".quad 0x5b202c3133662509,0x5d342b3731647225,0x68732e646c090a3b,0x3233662e64657261\n"
".quad 0x202c323366250920,0x382b37316472255b,0x2e6c756d090a3b5d,0x09203233752e6f6c\n"
".quad 0x7225202c33327225,0x090a3b3231202c31,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x33327225202c3831,0x752e646461090a3b,0x3964722509203436,0x2c3831647225202c\n"
".quad 0x090a3b3764722520,0x65726168732e646c,0x2509203233662e64,0x72255b202c333366\n"
".quad 0x0a3b5d302b373164,0x726168732e646c09,0x09203233662e6465,0x255b202c34336625\n"
".quad 0x0a3b5d302b396472,0x3233662e64646109,0x202c353366250920,0x6625202c33336625\n"
".quad 0x2e7473090a3b3433,0x662e646572616873,0x6472255b09203233,0x6625202c5d302b39\n"
".quad 0x2e646c090a3b3533,0x662e646572616873,0x3633662509203233,0x2b396472255b202c\n"
".quad 0x646461090a3b5d34,0x662509203233662e,0x36336625202c3733,0x0a3b31336625202c\n"
".quad 0x726168732e747309,0x09203233662e6465,0x5d342b396472255b,0x0a3b37336625202c\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x255b202c38336625,0x0a3b5d382b396472\n"
".quad 0x3233662e64646109,0x202c393366250920,0x6625202c38336625,0x2e7473090a3b3233\n"
".quad 0x662e646572616873,0x6472255b09203233,0x6625202c5d382b39,0x5f744c240a3b3933\n"
".quad 0x3a32303438335f38,0x79732e726162090a,0x090a3b300920636e,0x7262203170252140\n"
".quad 0x385f744c24092061,0x0a3b34313938335f,0x3233622e726f7809,0x202c343272250920\n"
".quad 0x0a3b31202c317225,0x2e6f6c2e6c756d09,0x3272250920323375,0x2c34327225202c35\n"
".quad 0x7663090a3b323120,0x33752e3436752e74,0x3931647225092032,0x0a3b35327225202c\n"
".quad 0x3436752e64646109,0x2c30326472250920,0x202c393164722520,0x6c090a3b37647225\n"
".quad 0x6465726168732e64,0x662509203233662e,0x6472255b202c3034,0x090a3b5d342b3032\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c313466,0x0a3b5d382b303264\n"
".quad 0x2e6f6c2e6c756d09,0x3272250920323375,0x202c317225202c36,0x747663090a3b3231\n"
".quad 0x3233752e3436752e,0x2c31326472250920,0x090a3b3632722520,0x203436752e646461\n"
".quad 0x25202c3964722509,0x7225202c31326472,0x2e646c090a3b3764,0x662e646572616873\n"
".quad 0x3234662509203233,0x30326472255b202c,0x646c090a3b5d302b,0x2e6465726168732e\n"
".quad 0x3466250920323366,0x396472255b202c33,0x6461090a3b5d302b,0x2509203233662e64\n"
".quad 0x346625202c343466,0x3b33346625202c32,0x6168732e7473090a,0x203233662e646572\n"
".quad 0x302b396472255b09,0x3b34346625202c5d,0x6168732e646c090a,0x203233662e646572\n"
".quad 0x5b202c3534662509,0x3b5d342b39647225,0x33662e646461090a,0x2c36346625092032\n"
".quad 0x25202c3534662520,0x7473090a3b303466,0x2e6465726168732e,0x72255b0920323366\n"
".quad 0x25202c5d342b3964,0x646c090a3b363466,0x2e6465726168732e,0x3466250920323366\n"
".quad 0x396472255b202c37,0x6461090a3b5d382b,0x2509203233662e64,0x346625202c383466\n"
".quad 0x3b31346625202c37,0x6168732e7473090a,0x203233662e646572,0x382b396472255b09\n"
".quad 0x3b38346625202c5d,0x335f385f744c240a,0x62090a3a34313938,0x20636e79732e7261\n"
".quad 0x6f6c2e090a3b3009,0x3136310937310963,0x70252140090a3009,0x2409206172622031\n"
".quad 0x3939335f385f744c,0x6f6c2e090a3b3833,0x3231310936310963,0x2e6c756d090a3009\n"
".quad 0x09203233752e6f6c,0x7225202c37327225,0x090a3b3231202c31,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x37327225202c3232,0x752e646461090a3b,0x3664722509203436\n"
".quad 0x2c3232647225202c,0x090a3b3164722520,0x65726168732e646c,0x2509203233662e64\n"
".quad 0x72255b202c393466,0x090a3b5d302b3664,0x203233662e766f6d,0x30202c3035662509\n"
".quad 0x3030303038643366,0x2f09202020203b30,0x353236302e30202f,0x6168732e646c090a\n"
".quad 0x662e34762e646572,0x3566257b09203233,0x252c323566252c31,0x202c7d5f2c333566\n"
".quad 0x5f616475635f5f5b,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f39313637335f\n"
".quad 0x6f635f6e6f6e5f36,0x736d75735f74736e,0x3b5d302b30363531,0x33662e6c756d090a\n"
".quad 0x2c34356625092032,0x25202c3035662520,0x7573090a3b313566,0x2509203233662e62\n"
".quad 0x346625202c353566,0x3b34356625202c39,0x33662e766f6d090a,0x2c36356625092032\n"
".quad 0x090a3b3535662520,0x65726168732e646c,0x2509203233662e64,0x72255b202c373566\n"
".quad 0x090a3b5d342b3664,0x203233662e766f6d,0x30202c3835662509,0x3030303038643366\n"
".quad 0x2f09202020203b30,0x353236302e30202f,0x33662e6c756d090a,0x2c39356625092032\n"
".quad 0x25202c3835662520,0x7573090a3b323566,0x2509203233662e62,0x356625202c303666\n"
".quad 0x3b39356625202c37,0x33662e766f6d090a,0x2c31366625092032,0x090a3b3036662520\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c323666,0x090a3b5d382b3664\n"
".quad 0x203233662e766f6d,0x30202c3336662509,0x3030303038643366,0x2f09202020203b30\n"
".quad 0x353236302e30202f,0x33662e6c756d090a,0x2c34366625092032,0x25202c3336662520\n"
".quad 0x7573090a3b333566,0x2509203233662e62,0x366625202c353666,0x3b34366625202c32\n"
".quad 0x33662e766f6d090a,0x2c36366625092032,0x240a3b3536662520,0x3439335f385f744c\n"
".quad 0x252140090a3a3632,0x0920617262203170,0x39335f385f744c24,0x6c2e090a3b383339\n"
".quad 0x313109363109636f,0x766f6d090a300939,0x722509203436752e,0x635f5f202c333264\n"
".quad 0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f35335f383130,0x74736e6f635f6e6f\n"
".quad 0x61697261766f635f,0x0a3b305f5f65636e,0x2e6f6c2e6c756d09,0x3272250920323373\n"
".quad 0x202c317225202c38,0x2e747663090a3b36,0x203233732e343673,0x202c343264722509\n"
".quad 0x6d090a3b38327225,0x2e656469772e6c75,0x6472250920323373,0x38327225202c3532\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x7225202c36326472,0x647225202c333264\n"
".quad 0x766f6d090a3b3532,0x662509203233662e,0x36356625202c3736,0x662e6c756d090a3b\n"
".quad 0x3836662509203233,0x202c37366625202c,0x73090a3b37366625,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x2c5d302b36326472,0x090a3b3836662520,0x09363109636f6c2e\n"
".quad 0x6d090a3009303231,0x09203233662e766f,0x6625202c39366625,0x6c756d090a3b3136\n"
".quad 0x662509203233662e,0x39366625202c3037,0x0a3b37366625202c,0x726168732e747309\n"
".quad 0x09203233662e6465,0x342b36326472255b,0x3b30376625202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093132310936,0x3233662e766f6d09,0x202c313766250920,0x6d090a3b36366625\n"
".quad 0x09203233662e6c75,0x6625202c32376625,0x37366625202c3137,0x68732e7473090a3b\n"
".quad 0x3233662e64657261,0x36326472255b0920,0x376625202c5d382b,0x636f6c2e090a3b32\n"
".quad 0x0932323109363109,0x662e6c756d090a30,0x3337662509203233,0x202c39366625202c\n"
".quad 0x73090a3b39366625,0x6465726168732e74,0x255b09203233662e,0x5d32312b36326472\n"
".quad 0x0a3b33376625202c,0x363109636f6c2e09,0x090a300933323109,0x203233662e6c756d\n"
".quad 0x25202c3437662509,0x366625202c313766,0x732e7473090a3b39,0x33662e6465726168\n"
".quad 0x326472255b092032,0x25202c5d36312b36,0x6c2e090a3b343766,0x323109363109636f\n"
".quad 0x6c756d090a300934,0x662509203233662e,0x31376625202c3537,0x0a3b31376625202c\n"
".quad 0x726168732e747309,0x09203233662e6465,0x322b36326472255b,0x35376625202c5d30\n"
".quad 0x5f385f744c240a3b,0x090a3a3833393933,0x203436752e766f6d,0x202c333264722509\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f38313037335f,0x6f635f6e6f6e5f35\n"
".quad 0x61766f635f74736e,0x5f5f65636e616972,0x636f6c2e090a3b30,0x0936323109363109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x3233732e766f6d09,0x202c393272250920\n"
".quad 0x385f744c240a3b38,0x0a3a32363930345f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x656e202c36323120,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6574616d69747365,0x7461726574692064,0x6e75203a736e6f69,0x73090a6e776f6e6b\n"
".quad 0x732e74672e707465,0x2c32702509203233,0x25202c3932722520,0x252140090a3b3172\n"
".quad 0x0920617262203270,0x31345f385f744c24,0x2f2f200a3b383132,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x30345f385f744c24,0x6f6c2e090a323639,0x3033310936310963\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c30337225,0x63090a3b36202c31\n"
".quad 0x732e3436732e7476,0x3264722509203233,0x3b30337225202c37,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3832647225,0x0a3b34202c303372,0x3436752e64646109\n"
".quad 0x2c36326472250920,0x202c333264722520,0x090a3b3832647225,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c363766,0x0a3b5d302b363264,0x3233732e64646109\n"
".quad 0x202c313372250920,0x7225202c39327225,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x7225202c32337225,0x090a3b36202c3133,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x32337225202c3932,0x772e6c756d090a3b,0x203233732e656469,0x202c303364722509\n"
".quad 0x3b34202c32337225,0x36752e646461090a,0x3133647225092034,0x2c3332647225202c\n"
".quad 0x0a3b303364722520,0x726168732e646c09,0x09203233662e6465,0x255b202c37376625\n"
".quad 0x3b5d302b31336472,0x33662e646461090a,0x2c38376625092032,0x25202c3637662520\n"
".quad 0x7473090a3b373766,0x2e6465726168732e,0x72255b0920323366,0x202c5d302b363264\n"
".quad 0x4c240a3b38376625,0x313231345f385f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363930345f385f74,0x732e726162090a32,0x0a3b300920636e79\n"
".quad 0x6220327025214009,0x5f744c2409206172,0x3b30333731345f38,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3632312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f38,0x363109636f6c2e09\n"
".quad 0x090a300931333109,0x732e6f6c2e6c756d,0x3333722509203233,0x36202c317225202c\n"
".quad 0x732e747663090a3b,0x09203233732e3436,0x25202c3233647225,0x756d090a3b333372\n"
".quad 0x732e656469772e6c,0x3364722509203233,0x2c33337225202c33,0x646461090a3b3420\n"
".quad 0x722509203436752e,0x647225202c363264,0x33647225202c3332,0x732e646c090a3b33\n"
".quad 0x33662e6465726168,0x2c39376625092032,0x2b36326472255b20,0x646461090a3b5d34\n"
".quad 0x722509203233732e,0x39327225202c3433,0x090a3b317225202c,0x732e6f6c2e6c756d\n"
".quad 0x3533722509203233,0x202c34337225202c,0x2e747663090a3b36,0x203233732e343673\n"
".quad 0x202c343364722509,0x6d090a3b35337225,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x35337225202c3533,0x6461090a3b34202c,0x2509203436752e64,0x7225202c36336472\n"
".quad 0x647225202c333264,0x2e646c090a3b3533,0x662e646572616873,0x3038662509203233\n"
".quad 0x36336472255b202c,0x6461090a3b5d342b,0x2509203233662e64,0x376625202c313866\n"
".quad 0x3b30386625202c39,0x6168732e7473090a,0x203233662e646572,0x2b36326472255b09\n"
".quad 0x31386625202c5d34,0x5f385f744c240a3b,0x200a3a3033373134,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363231\n"
".quad 0x656c6562616c2064,0x5f385f744c242064,0x62090a3236393034,0x20636e79732e7261\n"
".quad 0x252140090a3b3009,0x0920617262203270,0x32345f385f744c24,0x2f2f200a3b323432\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x30345f385f744c24,0x6f6c2e090a323639\n"
".quad 0x3233310936310963,0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c36337225\n"
".quad 0x63090a3b36202c31,0x732e3436732e7476,0x3364722509203233,0x3b36337225202c37\n"
".quad 0x69772e6c756d090a,0x09203233732e6564,0x25202c3833647225,0x0a3b34202c363372\n"
".quad 0x3436752e64646109,0x2c36326472250920,0x202c333264722520,0x090a3b3833647225\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c323866,0x0a3b5d382b363264\n"
".quad 0x3233732e64646109,0x202c373372250920,0x7225202c39327225,0x2e6c756d090a3b31\n"
".quad 0x09203233732e6f6c,0x7225202c38337225,0x090a3b36202c3733,0x2e3436732e747663\n"
".quad 0x6472250920323373,0x38337225202c3933,0x772e6c756d090a3b,0x203233732e656469\n"
".quad 0x202c303464722509,0x3b34202c38337225,0x36752e646461090a,0x3134647225092034\n"
".quad 0x2c3332647225202c,0x0a3b303464722520,0x726168732e646c09,0x09203233662e6465\n"
".quad 0x255b202c33386625,0x3b5d382b31346472,0x33662e646461090a,0x2c34386625092032\n"
".quad 0x25202c3238662520,0x7473090a3b333866,0x2e6465726168732e,0x72255b0920323366\n"
".quad 0x202c5d382b363264,0x4c240a3b34386625,0x343232345f385f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363930345f385f74,0x732e726162090a32\n"
".quad 0x0a3b300920636e79,0x6220327025214009,0x5f744c2409206172,0x3b34353732345f38\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3632312065,0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f38\n"
".quad 0x363109636f6c2e09,0x090a300933333109,0x732e6f6c2e6c756d,0x3933722509203233\n"
".quad 0x36202c317225202c,0x732e747663090a3b,0x09203233732e3436,0x25202c3234647225\n"
".quad 0x756d090a3b393372,0x732e656469772e6c,0x3464722509203233,0x2c39337225202c33\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c363264,0x34647225202c3332\n"
".quad 0x732e646c090a3b33,0x33662e6465726168,0x2c35386625092032,0x2b36326472255b20\n"
".quad 0x6461090a3b5d3231,0x2509203233732e64,0x327225202c303472,0x0a3b317225202c39\n"
".quad 0x2e6f6c2e6c756d09,0x3472250920323373,0x2c30347225202c31,0x747663090a3b3620\n"
".quad 0x3233732e3436732e,0x2c34346472250920,0x090a3b3134722520,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x347225202c353464,0x61090a3b34202c31,0x09203436752e6464\n"
".quad 0x25202c3634647225,0x7225202c33326472,0x646c090a3b353464,0x2e6465726168732e\n"
".quad 0x3866250920323366,0x346472255b202c36,0x090a3b5d32312b36,0x203233662e646461\n"
".quad 0x25202c3738662509,0x386625202c353866,0x732e7473090a3b36,0x33662e6465726168\n"
".quad 0x326472255b092032,0x25202c5d32312b36,0x744c240a3b373866,0x34353732345f385f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36323120656e,0x62616c2064616568,0x744c242064656c65,0x32363930345f385f\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x7262203270252140,0x385f744c24092061\n"
".quad 0x0a3b36363233345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461,0x385f744c24206465\n"
".quad 0x090a32363930345f,0x09363109636f6c2e,0x6d090a3009343331,0x33732e6f6c2e6c75\n"
".quad 0x2c32347225092032,0x3b36202c31722520,0x36732e747663090a,0x2509203233732e34\n"
".quad 0x7225202c37346472,0x6c756d090a3b3234,0x33732e656469772e,0x3834647225092032\n"
".quad 0x202c32347225202c,0x2e646461090a3b34,0x6472250920343675,0x32647225202c3632\n"
".quad 0x3834647225202c33,0x68732e646c090a3b,0x3233662e64657261,0x202c383866250920\n"
".quad 0x312b36326472255b,0x646461090a3b5d36,0x722509203233732e,0x39327225202c3334\n"
".quad 0x090a3b317225202c,0x732e6f6c2e6c756d,0x3434722509203233,0x202c33347225202c\n"
".quad 0x2e747663090a3b36,0x203233732e343673,0x202c393464722509,0x6d090a3b34347225\n"
".quad 0x2e656469772e6c75,0x6472250920323373,0x34347225202c3035,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x7225202c31356472,0x647225202c333264,0x2e646c090a3b3035\n"
".quad 0x662e646572616873,0x3938662509203233,0x31356472255b202c,0x61090a3b5d36312b\n"
".quad 0x09203233662e6464,0x6625202c30396625,0x39386625202c3838,0x68732e7473090a3b\n"
".quad 0x3233662e64657261,0x36326472255b0920,0x6625202c5d36312b,0x5f744c240a3b3039\n"
".quad 0x3a36363233345f38,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3632312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363930345f38,0x6e79732e72616209,0x40090a3b30092063,0x6172622032702521\n"
".quad 0x5f385f744c240920,0x200a3b3837373334,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363231,0x656c6562616c2064\n"
".quad 0x5f385f744c242064,0x2e090a3236393034,0x3109363109636f6c,0x756d090a30093533\n"
".quad 0x3233732e6f6c2e6c,0x202c353472250920,0x0a3b36202c317225,0x3436732e74766309\n"
".quad 0x722509203233732e,0x347225202c323564,0x2e6c756d090a3b35,0x3233732e65646977\n"
".quad 0x2c33356472250920,0x34202c3534722520,0x752e646461090a3b,0x3264722509203436\n"
".quad 0x3332647225202c36,0x3b3335647225202c,0x6168732e646c090a,0x203233662e646572\n"
".quad 0x5b202c3139662509,0x30322b3632647225,0x2e646461090a3b5d,0x3472250920323373\n"
".quad 0x2c39327225202c36,0x6d090a3b31722520,0x33732e6f6c2e6c75,0x2c37347225092032\n"
".quad 0x36202c3634722520,0x732e747663090a3b,0x09203233732e3436,0x25202c3435647225\n"
".quad 0x756d090a3b373472,0x732e656469772e6c,0x3564722509203233,0x2c37347225202c35\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c363564,0x35647225202c3332\n"
".quad 0x732e646c090a3b35,0x33662e6465726168,0x2c32396625092032,0x2b36356472255b20\n"
".quad 0x6461090a3b5d3032,0x2509203233662e64,0x396625202c333966,0x3b32396625202c31\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x2b36326472255b09,0x396625202c5d3032\n"
".quad 0x385f744c240a3b33,0x0a3a38373733345f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461\n"
".quad 0x385f744c24206465,0x090a32363930345f,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x323109363109636f,0x726873090a300938,0x722509203233732e,0x39327225202c3932\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x0a3b30202c383472,0x74672e7074657309\n"
".quad 0x702509203233732e,0x2c39327225202c33,0x090a3b3834722520,0x6172622033702540\n"
".quad 0x5f385f744c240920,0x090a3b3236393034,0x65726168732e646c,0x3233662e34762e64\n"
".quad 0x2c343966257b0920,0x3966252c35396625,0x5f5b202c7d5f2c36,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x35335f3831303733,0x6e6f635f6e6f6e5f,0x7261766f635f7473\n"
".quad 0x305f5f65636e6169,0x6c2e090a3b5d302b,0x343509363109636f,0x732e646c090a3009\n"
".quad 0x33662e6465726168,0x2c37396625092032,0x616475635f5f5b20,0x765f6c61636f6c5f\n"
".quad 0x38313037335f7261,0x5f6e6f6e5f35335f,0x6f635f74736e6f63,0x65636e6169726176\n"
".quad 0x3b5d32312b305f5f,0x33662e766f6d090a,0x2c38396625092032,0x3030386633663020\n"
".quad 0x202020203b303030,0x66090a31202f2f09,0x33662e6e722e616d,0x2c39396625092032\n"
".quad 0x25202c3839662520,0x396625202c353966,0x732e646c090a3b37,0x32762e6465726168\n"
".quad 0x257b09203233662e,0x3166252c30303166,0x5f5f5b202c7d3130,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f35335f38313037,0x736e6f635f6e6f6e,0x697261766f635f74\n"
".quad 0x2b305f5f65636e61,0x6f6d090a3b5d3631,0x2509203233662e76,0x6630202c32303166\n"
".quad 0x3030303030386633,0x202f2f092020203b,0x722e616d66090a31,0x2509203233662e6e\n"
".quad 0x6625202c33303166,0x396625202c323031,0x3030316625202c36,0x662e766f6d090a3b\n"
".quad 0x3031662509203233,0x3866336630202c34,0x20203b3030303030,0x090a31202f2f0920\n"
".quad 0x662e6e722e616d66,0x3031662509203233,0x2c34396625202c35,0x202c343031662520\n"
".quad 0x6d090a3b35396625,0x09203233662e766f,0x30202c3630316625,0x3030303038663366\n"
".quad 0x2f2f092020203b30,0x2e616d66090a3120,0x09203233662e6e72,0x25202c3730316625\n"
".quad 0x6625202c36303166,0x396625202c303031,0x2e766f6d090a3b39,0x3166250920323366\n"
".quad 0x66336630202c3830,0x203b303030303038,0x0a31202f2f092020,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x30316625202c3930,0x3130316625202c38,0x3b3330316625202c\n"
".quad 0x33662e766f6d090a,0x3031316625092032,0x303866336630202c,0x2020203b30303030\n"
".quad 0x66090a31202f2f09,0x33662e6e722e616d,0x3131316625092032,0x202c36396625202c\n"
".quad 0x25202c3031316625,0x6d090a3b35303166,0x09203233662e7861,0x25202c3231316625\n"
".quad 0x6625202c37303166,0x616d090a3b313131,0x2509203233662e78,0x6625202c33313166\n"
".quad 0x316625202c393031,0x706372090a3b3231,0x203233662e6e722e,0x202c343131662509\n"
".quad 0x090a3b3331316625,0x203233662e6c756d,0x202c353131662509,0x25202c3730316625\n"
".quad 0x6d090a3b34313166,0x09203233662e6c75,0x25202c3631316625,0x6625202c31313166\n"
".quad 0x756d090a3b343131,0x2509203233662e6c,0x6625202c37313166,0x316625202c393031\n"
".quad 0x6c756d090a3b3431,0x662509203233662e,0x316625202c383131,0x30316625202c3531\n"
".quad 0x2e6c756d090a3b30,0x3166250920323366,0x31316625202c3931,0x3b35396625202c35\n"
".quad 0x33662e6c756d090a,0x3032316625092032,0x2c3531316625202c,0x090a3b3739662520\n"
".quad 0x662e6e722e616d66,0x3231662509203233,0x3631316625202c31,0x202c36396625202c\n"
".quad 0x090a3b3831316625,0x662e6e722e616d66,0x3231662509203233,0x2c34396625202c32\n"
".quad 0x202c363131662520,0x090a3b3931316625,0x662e6e722e616d66,0x3231662509203233\n"
".quad 0x3631316625202c33,0x202c35396625202c,0x090a3b3032316625,0x662e6e722e616d66\n"
".quad 0x3231662509203233,0x3731316625202c34,0x2c3130316625202c,0x0a3b313231662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x36396625202c3532,0x2c3731316625202c\n"
".quad 0x0a3b323231662520,0x2e6e722e616d6609,0x3166250920323366,0x31316625202c3632\n"
".quad 0x3030316625202c37,0x3b3332316625202c,0x33662e78616d090a,0x3732316625092032\n"
".quad 0x2c3532316625202c,0x0a3b363231662520,0x3233662e78616d09,0x2c38323166250920\n"
".quad 0x202c343231662520,0x090a3b3732316625,0x662e6e722e706372,0x3231662509203233\n"
".quad 0x3832316625202c39,0x09636f6c2e090a3b,0x0a30093035093631,0x3233662e6c756d09\n"
".quad 0x2c30333166250920,0x202c343231662520,0x090a3b3932316625,0x203233662e6c756d\n"
".quad 0x202c313331662509,0x25202c3532316625,0x6d090a3b39323166,0x09203233662e6c75\n"
".quad 0x25202c3233316625,0x6625202c36323166,0x756d090a3b393231,0x2509203233662e6c\n"
".quad 0x6625202c33333166,0x396625202c323331,0x2e616d66090a3b35,0x09203233662e6e72\n"
".quad 0x25202c3433316625,0x316625202c343966,0x33316625202c3133,0x2e616d66090a3b33\n"
".quad 0x09203233662e6e72,0x25202c3533316625,0x316625202c363966,0x33316625202c3033\n"
".quad 0x636f6c2e090a3b34,0x3009313509363109,0x33662e6c756d090a,0x3633316625092032\n"
".quad 0x2c3233316625202c,0x090a3b3739662520,0x662e6e722e616d66,0x3331662509203233\n"
".quad 0x3133316625202c37,0x202c35396625202c,0x090a3b3633316625,0x662e6e722e616d66\n"
".quad 0x3331662509203233,0x3033316625202c38,0x2c3030316625202c,0x0a3b373331662520\n"
".quad 0x363109636f6c2e09,0x6d090a3009323509,0x09203233662e6c75,0x25202c3933316625\n"
".quad 0x6625202c32333166,0x6d66090a3b303031,0x3233662e6e722e61,0x2c30343166250920\n"
".quad 0x202c313331662520,0x6625202c36396625,0x6d66090a3b393331,0x3233662e6e722e61\n"
".quad 0x2c31343166250920,0x202c303331662520,0x25202c3130316625,0x2e090a3b30343166\n"
".quad 0x3509363109636f6c,0x78616d090a300938,0x662509203233662e,0x316625202c323431\n"
".quad 0x33316625202c3533,0x2e78616d090a3b38,0x3166250920323366,0x34316625202c3334\n"
".quad 0x3134316625202c32,0x722e706372090a3b,0x2509203233662e6e,0x6625202c34343166\n"
".quad 0x756d090a3b333431,0x2509203233662e6c,0x6625202c35343166,0x316625202c343431\n"
".quad 0x6c756d090a3b3533,0x662509203233662e,0x316625202c363431,0x33316625202c3434\n"
".quad 0x2e6c756d090a3b38,0x3166250920323366,0x34316625202c3734,0x3134316625202c34\n"
".quad 0x09636f6c2e090a3b,0x0a30093035093631,0x3233662e6c756d09,0x2c38343166250920\n"
".quad 0x202c363431662520,0x66090a3b35396625,0x33662e6e722e616d,0x3934316625092032\n"
".quad 0x202c34396625202c,0x25202c3534316625,0x66090a3b38343166,0x33662e6e722e616d\n"
".quad 0x3035316625092032,0x202c36396625202c,0x25202c3734316625,0x2e090a3b39343166\n"
".quad 0x3509363109636f6c,0x6c756d090a300938,0x662509203233662e,0x316625202c313531\n"
".quad 0x37396625202c3634,0x662e6c756d090a3b,0x3531662509203233,0x3634316625202c32\n"
".quad 0x3b3030316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c333531\n"
".quad 0x35396625202c3534,0x3b3135316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c343531,0x36396625202c3534,0x3b3235316625202c,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x316625202c353531,0x30316625202c3734,0x3335316625202c30\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36353166,0x316625202c373431\n"
".quad 0x35316625202c3130,0x2e78616d090a3b34,0x3166250920323366,0x35316625202c3735\n"
".quad 0x3035316625202c35,0x662e78616d090a3b,0x3531662509203233,0x3635316625202c38\n"
".quad 0x3b3735316625202c,0x6e722e706372090a,0x662509203233662e,0x316625202c393531\n"
".quad 0x6c756d090a3b3835,0x662509203233662e,0x316625202c303631,0x35316625202c3535\n"
".quad 0x2e6c756d090a3b39,0x3166250920323366,0x35316625202c3136,0x3935316625202c36\n"
".quad 0x662e6c756d090a3b,0x3631662509203233,0x3935316625202c32,0x3b3035316625202c\n"
".quad 0x3109636f6c2e090a,0x090a300932350936,0x203233662e6c756d,0x202c333631662509\n"
".quad 0x25202c3036316625,0x66090a3b30303166,0x33662e6e722e616d,0x3436316625092032\n"
".quad 0x2c3236316625202c,0x25202c3639662520,0x66090a3b33363166,0x33662e6e722e616d\n"
".quad 0x3536316625092032,0x2c3136316625202c,0x202c313031662520,0x090a3b3436316625\n"
".quad 0x09363109636f6c2e,0x756d090a30093435,0x2509203233662e6c,0x6625202c36363166\n"
".quad 0x396625202c303631,0x2e6c756d090a3b35,0x3166250920323366,0x36316625202c3736\n"
".quad 0x3b37396625202c30,0x6e722e616d66090a,0x662509203233662e,0x396625202c383631\n"
".quad 0x3236316625202c34,0x3b3636316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c393631,0x35396625202c3236,0x3b3736316625202c,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x396625202c303731,0x3136316625202c36,0x3b3836316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c313731,0x30316625202c3136\n"
".quad 0x3936316625202c30,0x662e78616d090a3b,0x3731662509203233,0x3037316625202c32\n"
".quad 0x3b3137316625202c,0x33662e78616d090a,0x3337316625092032,0x2c3237316625202c\n"
".quad 0x0a3b353631662520,0x2e6e722e70637209,0x3166250920323366,0x37316625202c3437\n"
".quad 0x636f6c2e090a3b33,0x3009383509363109,0x33662e6c756d090a,0x3537316625092032\n"
".quad 0x2c3037316625202c,0x0a3b343731662520,0x3233662e6c756d09,0x2c36373166250920\n"
".quad 0x202c313731662520,0x090a3b3437316625,0x09363109636f6c2e,0x756d090a30093035\n"
".quad 0x2509203233662e6c,0x6625202c37373166,0x316625202c343731,0x6c756d090a3b3536\n"
".quad 0x662509203233662e,0x316625202c383731,0x35396625202c3637,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c39373166,0x37316625202c3439,0x3837316625202c35\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c30383166,0x37316625202c3639\n"
".quad 0x3937316625202c37,0x09636f6c2e090a3b,0x0a30093135093631,0x3233662e6c756d09\n"
".quad 0x2c31383166250920,0x202c363731662520,0x66090a3b37396625,0x33662e6e722e616d\n"
".quad 0x3238316625092032,0x2c3537316625202c,0x25202c3539662520,0x66090a3b31383166\n"
".quad 0x33662e6e722e616d,0x3338316625092032,0x2c3737316625202c,0x202c303031662520\n"
".quad 0x090a3b3238316625,0x09363109636f6c2e,0x756d090a30093235,0x2509203233662e6c\n"
".quad 0x6625202c34383166,0x316625202c363731,0x616d66090a3b3030,0x203233662e6e722e\n"
".quad 0x202c353831662509,0x25202c3537316625,0x316625202c363966,0x616d66090a3b3438\n"
".quad 0x203233662e6e722e,0x202c363831662509,0x25202c3737316625,0x6625202c31303166\n"
".quad 0x6c2e090a3b353831,0x383509363109636f,0x2e78616d090a3009,0x3166250920323366\n"
".quad 0x38316625202c3738,0x3338316625202c30,0x662e78616d090a3b,0x3831662509203233\n"
".quad 0x3738316625202c38,0x3b3638316625202c,0x6e722e706372090a,0x662509203233662e\n"
".quad 0x316625202c393831,0x6c756d090a3b3838,0x662509203233662e,0x316625202c303931\n"
".quad 0x38316625202c3938,0x2e6c756d090a3b30,0x3166250920323366,0x38316625202c3139\n"
".quad 0x3338316625202c39,0x662e6c756d090a3b,0x3931662509203233,0x3938316625202c32\n"
".quad 0x3b3638316625202c,0x3109636f6c2e090a,0x090a300930350936,0x203233662e6c756d\n"
".quad 0x202c333931662509,0x25202c3139316625,0x6d66090a3b353966,0x3233662e6e722e61\n"
".quad 0x2c34393166250920,0x25202c3439662520,0x6625202c30393166,0x6d66090a3b333931\n"
".quad 0x3233662e6e722e61,0x2c35393166250920,0x25202c3639662520,0x6625202c32393166\n"
".quad 0x6c2e090a3b343931,0x383509363109636f,0x2e6c756d090a3009,0x3166250920323366\n"
".quad 0x39316625202c3639,0x3b37396625202c31,0x33662e6c756d090a,0x3739316625092032\n"
".quad 0x2c3139316625202c,0x0a3b303031662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x39316625202c3839,0x2c35396625202c30,0x0a3b363931662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x39316625202c3939,0x2c36396625202c30,0x0a3b373931662520\n"
".quad 0x2e6e722e616d6609,0x3266250920323366,0x39316625202c3030,0x3030316625202c32\n"
".quad 0x3b3839316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c313032\n"
".quad 0x30316625202c3239,0x3939316625202c31,0x662e78616d090a3b,0x3032662509203233\n"
".quad 0x3030326625202c32,0x3b3539316625202c,0x33662e78616d090a,0x3330326625092032\n"
".quad 0x2c3130326625202c,0x0a3b323032662520,0x2e6e722e70637209,0x3266250920323366\n"
".quad 0x30326625202c3430,0x2e6c756d090a3b33,0x3266250920323366,0x30326625202c3530\n"
".quad 0x3430326625202c30,0x662e6c756d090a3b,0x3032662509203233,0x3130326625202c36\n"
".quad 0x3b3430326625202c,0x33662e6c756d090a,0x3730326625092032,0x2c3430326625202c\n"
".quad 0x0a3b353931662520,0x363109636f6c2e09,0x6d090a3009323509,0x09203233662e6c75\n"
".quad 0x25202c3830326625,0x6625202c35303266,0x6d66090a3b303031,0x3233662e6e722e61\n"
".quad 0x2c39303266250920,0x202c373032662520,0x6625202c36396625,0x6d66090a3b383032\n"
".quad 0x3233662e6e722e61,0x2c30313266250920,0x202c363032662520,0x25202c3130316625\n"
".quad 0x2e090a3b39303266,0x3509363109636f6c,0x6c756d090a300934,0x662509203233662e\n"
".quad 0x326625202c313132,0x35396625202c3530,0x662e6c756d090a3b,0x3132662509203233\n"
".quad 0x3530326625202c32,0x0a3b37396625202c,0x2e6e722e616d6609,0x3266250920323366\n"
".quad 0x34396625202c3331,0x2c3730326625202c,0x0a3b313132662520,0x2e6e722e616d6609\n"
".quad 0x3266250920323366,0x30326625202c3431,0x2c35396625202c37,0x0a3b323132662520\n"
".quad 0x2e6e722e616d6609,0x3266250920323366,0x36396625202c3531,0x2c3630326625202c\n"
".quad 0x0a3b333132662520,0x2e6e722e616d6609,0x3266250920323366,0x30326625202c3631\n"
".quad 0x3030316625202c36,0x3b3431326625202c,0x33662e78616d090a,0x3731326625092032\n"
".quad 0x2c3531326625202c,0x0a3b363132662520,0x3233662e78616d09,0x2c38313266250920\n"
".quad 0x202c373132662520,0x090a3b3031326625,0x662e6e722e706372,0x3132662509203233\n"
".quad 0x3831326625202c39,0x09636f6c2e090a3b,0x0a30093835093631,0x3233662e6c756d09\n"
".quad 0x2c30323266250920,0x202c353132662520,0x090a3b3931326625,0x203233662e6c756d\n"
".quad 0x202c313232662509,0x25202c3631326625,0x2e090a3b39313266,0x3109373109636f6c\n"
".quad 0x7663090a30093136,0x33732e3436732e74,0x3735647225092032,0x090a3b317225202c\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x317225202c383564,0x2140090a3b34202c\n"
".quad 0x2061726220317025,0x345f385f744c2409,0x2e090a3b36343534,0x3109373109636f6c\n"
".quad 0x6f6d090a30093436,0x2509203436752e76,0x5f5f202c39356472,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f35335f31343337,0x736e6f635f6e6f6e,0x335f5f7370645f74\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c393472,0x63090a3b3231202c\n"
".quad 0x752e3436752e7476,0x3664722509203233,0x3b39347225202c30,0x36752e646461090a\n"
".quad 0x2c36647225092034,0x202c303664722520,0x6c090a3b31647225,0x6465726168732e64\n"
".quad 0x662509203233662e,0x72255b202c323232,0x090a3b5d342b3664,0x203233662e6c756d\n"
".quad 0x202c333232662509,0x25202c3232326625,0x6c090a3b31323266,0x6465726168732e64\n"
".quad 0x662509203233662e,0x72255b202c343232,0x090a3b5d302b3664,0x662e6e722e616d66\n"
".quad 0x3232662509203233,0x3432326625202c35,0x2c3032326625202c,0x0a3b333232662520\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x5b202c3632326625,0x3b5d382b36647225\n"
".quad 0x33662e6c756d090a,0x3732326625092032,0x2c3931326625202c,0x0a3b303132662520\n"
".quad 0x2e6e722e616d6609,0x3266250920323366,0x32326625202c3832,0x3732326625202c36\n"
".quad 0x3b3532326625202c,0x36752e646461090a,0x3136647225092034,0x2c3835647225202c\n"
".quad 0x0a3b393564722520,0x726168732e747309,0x09203233662e6465,0x302b31366472255b\n"
".quad 0x3832326625202c5d,0x5f385f744c240a3b,0x090a3a3634353434,0x203436752e766f6d\n"
".quad 0x202c393564722509,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f31343337335f\n"
".quad 0x6f635f6e6f6e5f35,0x5f7370645f74736e,0x6f6c2e090a3b335f,0x3736310937310963\n"
".quad 0x2e726162090a3009,0x3b300920636e7973,0x203170252140090a,0x744c240920617262\n"
".quad 0x38353035345f385f,0x09636f6c2e090a3b,0x3009303731093731,0x33752e766f6d090a\n"
".quad 0x2c30357225092032,0x746573090a3b3020,0x3233752e656e2e70,0x25202c3470250920\n"
".quad 0x30357225202c3172,0x2034702540090a3b,0x744c240920617262,0x30373535345f385f\n"
".quad 0x732e766f6d090a3b,0x3135722509203233,0x646c090a3b30202c,0x2e6465726168732e\n"
".quad 0x09203233662e3476,0x252c39323266257b,0x3266252c30333266,0x32333266252c3133\n"
".quad 0x75635f5f5b202c7d,0x6c61636f6c5f6164,0x3337335f7261765f,0x6f6e5f35335f3134\n"
".quad 0x5f74736e6f635f6e,0x302b335f5f737064,0x732e646c090a3b5d,0x34762e6465726168\n"
".quad 0x257b09203233662e,0x3266252c33333266,0x35333266252c3433,0x2c7d36333266252c\n"
".quad 0x616475635f5f5b20,0x765f6c61636f6c5f,0x31343337335f7261,0x5f6e6f6e5f35335f\n"
".quad 0x70645f74736e6f63,0x5d36312b335f5f73,0x68732e646c090a3b,0x2e34762e64657261\n"
".quad 0x66257b0920323366,0x333266252c373332,0x2c39333266252c38,0x202c7d3034326625\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f31343337335f72,0x635f6e6f6e5f3533\n"
".quad 0x7370645f74736e6f,0x3b5d32332b335f5f,0x6168732e646c090a,0x662e34762e646572\n"
".quad 0x3266257b09203233,0x32343266252c3134,0x252c33343266252c,0x5b202c7d34343266\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f31343337335f,0x6f635f6e6f6e5f35\n"
".quad 0x5f7370645f74736e,0x0a3b5d38342b335f,0x3436752e766f6d09,0x2c32366472250920\n"
".quad 0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f30323637335f\n"
".quad 0x6f635f6e6f6e5f33,0x666572785f74736e,0x240a3b3235373173,0x3536345f385f744c\n"
".quad 0x3c2f2f200a3a3439,0x6f4c203e706f6f6c,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x72657469202c3120,0x203a736e6f697461\n"
".quad 0x636f6c2e090a3631,0x3009383909373109,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c33366472,0x646461090a3b3135,0x722509203436752e,0x647225202c343664\n"
".quad 0x35647225202c3336,0x732e646c090a3b39,0x33662e6465726168,0x3534326625092032\n"
".quad 0x34366472255b202c,0x6573090a3b5d302b,0x3233752e74672e74,0x722509203233662e\n"
".quad 0x34326625202c3235,0x3334326625202c35,0x732e67656e090a3b,0x3335722509203233\n"
".quad 0x0a3b32357225202c,0x2e74672e74657309,0x203233662e323375,0x25202c3435722509\n"
".quad 0x6625202c35343266,0x656e090a3b343432,0x2509203233732e67,0x357225202c353572\n"
".quad 0x2e646461090a3b34,0x3572250920323373,0x2c33357225202c36,0x090a3b3535722520\n"
".quad 0x752e74672e746573,0x09203233662e3233,0x6625202c37357225,0x326625202c353432\n"
".quad 0x67656e090a3b3134,0x722509203233732e,0x37357225202c3835,0x672e746573090a3b\n"
".quad 0x33662e3233752e74,0x2c39357225092032,0x202c353432662520,0x090a3b3234326625\n"
".quad 0x203233732e67656e,0x25202c3036722509,0x6461090a3b393572,0x2509203233732e64\n"
".quad 0x357225202c313672,0x3b30367225202c38,0x74672e746573090a,0x3233662e3233752e\n"
".quad 0x202c323672250920,0x25202c3534326625,0x6e090a3b39333266,0x09203233732e6765\n"
".quad 0x7225202c33367225,0x746573090a3b3236,0x2e3233752e74672e,0x3672250920323366\n"
".quad 0x3534326625202c34,0x3b3034326625202c,0x33732e67656e090a,0x2c35367225092032\n"
".quad 0x090a3b3436722520,0x203233732e646461,0x25202c3636722509,0x367225202c333672\n"
".quad 0x2e746573090a3b35,0x662e3233752e7467,0x3736722509203233,0x2c3534326625202c\n"
".quad 0x0a3b303332662520,0x3233732e67656e09,0x202c383672250920,0x73090a3b37367225\n"
".quad 0x33752e74672e7465,0x2509203233662e32,0x326625202c393672,0x32326625202c3534\n"
".quad 0x2e67656e090a3b39,0x3772250920323373,0x3b39367225202c30,0x33732e646461090a\n"
".quad 0x2c31377225092032,0x25202c3836722520,0x6573090a3b303772,0x3233752e74672e74\n"
".quad 0x722509203233662e,0x34326625202c3237,0x3133326625202c35,0x732e67656e090a3b\n"
".quad 0x3337722509203233,0x0a3b32377225202c,0x2e74672e74657309,0x203233662e323375\n"
".quad 0x25202c3437722509,0x6625202c35343266,0x656e090a3b323332,0x2509203233732e67\n"
".quad 0x377225202c353772,0x2e646461090a3b34,0x3772250920323373,0x2c33377225202c36\n"
".quad 0x090a3b3537722520,0x752e74672e746573,0x09203233662e3233,0x6625202c37377225\n"
".quad 0x326625202c353432,0x67656e090a3b3333,0x722509203233732e,0x37377225202c3837\n"
".quad 0x672e746573090a3b,0x33662e3233752e74,0x2c39377225092032,0x202c353432662520\n"
".quad 0x090a3b3433326625,0x203233732e67656e,0x25202c3038722509,0x6461090a3b393772\n"
".quad 0x2509203233732e64,0x377225202c313872,0x3b30387225202c38,0x74672e746573090a\n"
".quad 0x3233662e3233752e,0x202c323872250920,0x25202c3534326625,0x6e090a3b35333266\n"
".quad 0x09203233732e6765,0x7225202c33387225,0x746573090a3b3238,0x2e3233752e74672e\n"
".quad 0x3872250920323366,0x3534326625202c34,0x3b3633326625202c,0x33732e67656e090a\n"
".quad 0x2c35387225092032,0x090a3b3438722520,0x203233732e646461,0x25202c3638722509\n"
".quad 0x387225202c333872,0x2e746573090a3b35,0x662e3233752e7467,0x3738722509203233\n"
".quad 0x2c3534326625202c,0x0a3b373332662520,0x3233732e67656e09,0x202c383872250920\n"
".quad 0x73090a3b37387225,0x33752e74672e7465,0x2509203233662e32,0x326625202c393872\n"
".quad 0x33326625202c3534,0x2e67656e090a3b38,0x3972250920323373,0x3b39387225202c30\n"
".quad 0x33732e646461090a,0x2c31397225092032,0x25202c3838722520,0x6461090a3b303972\n"
".quad 0x2509203233732e64,0x387225202c323972,0x3b31397225202c36,0x33732e646461090a\n"
".quad 0x2c33397225092032,0x25202c3138722520,0x6461090a3b323972,0x2509203233732e64\n"
".quad 0x377225202c343972,0x3b33397225202c36,0x33732e646461090a,0x2c35397225092032\n"
".quad 0x25202c3137722520,0x6461090a3b343972,0x2509203233732e64,0x367225202c363972\n"
".quad 0x3b35397225202c36,0x33732e646461090a,0x2c37397225092032,0x25202c3136722520\n"
".quad 0x6461090a3b363972,0x2509203233732e64,0x357225202c383972,0x3b37397225202c36\n"
".quad 0x36752e646461090a,0x3536647225092034,0x2c3336647225202c,0x0a3b323664722520\n"
".quad 0x726168732e747309,0x09203233732e6465,0x302b35366472255b,0x3b38397225202c5d\n"
".quad 0x33752e646461090a,0x2c31357225092032,0x34202c3135722520,0x752e766f6d090a3b\n"
".quad 0x3939722509203233,0x73090a3b3436202c,0x732e656e2e707465,0x2c35702509203233\n"
".quad 0x25202c3135722520,0x2540090a3b393972,0x0920617262203570,0x36345f385f744c24\n"
".quad 0x6f6d090a3b343935,0x2509203233732e76,0x3b30202c30303172,0x345f385f744c240a\n"
".quad 0x2f200a3a38313637,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3920656e696c2079\n"
".quad 0x697473656e202c38,0x687470656420676e,0x657469202c31203a,0x3a736e6f69746172\n"
".quad 0x766f6d090a353120,0x722509203233732e,0x0a3b30202c313031,0x38345f385f744c24\n"
".quad 0x2f2f200a3a363833,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x383920656e696c20\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x72657469202c3220,0x203a736e6f697461\n"
".quad 0x636f6c2e090a3631,0x0936303109373109,0x2e70746573090a30,0x09203233732e656c\n"
".quad 0x317225202c367025,0x30317225202c3130,0x36702540090a3b30,0x4c24092061726220\n"
".quad 0x333139355f385f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x36383338345f385f,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c323031\n"
".quad 0x090a3b34202c3130,0x2e3436752e747663,0x6472250920323375,0x30317225202c3636\n"
".quad 0x2e646461090a3b32,0x6472250920343675,0x36647225202c3736,0x3236647225202c36\n"
".quad 0x68732e646c090a3b,0x3233732e64657261,0x2c33303172250920,0x2b37366472255b20\n"
".quad 0x6c756d090a3b5d30,0x203233752e6f6c2e,0x202c343031722509,0x34202c3030317225\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x25202c3836647225,0x61090a3b34303172\n"
".quad 0x09203436752e6464,0x25202c3936647225,0x7225202c38366472,0x646c090a3b323664\n"
".quad 0x2e6465726168732e,0x3172250920323373,0x6472255b202c3530,0x090a3b5d302b3936\n"
".quad 0x2e656e2e70746573,0x3770250920323373,0x2c3530317225202c,0x0a3b333031722520\n"
".quad 0x7262203770254009,0x385f744c24092061,0x0a3b38333139355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383920\n"
".quad 0x656c6562616c2064,0x5f385f744c242064,0x61090a3638333834,0x09203233732e6464\n"
".quad 0x25202c3630317225,0x3b31202c33303172,0x6168732e7473090a,0x203233732e646572\n"
".quad 0x2b37366472255b09,0x30317225202c5d30,0x385f744c240a3b36,0x0a3a38333139355f\n"
".quad 0x3835335f385f4c24,0x3c2f2f200a3a3234,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c383920656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x383338345f385f74,0x732e646461090a36,0x3031722509203233,0x3130317225202c31\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3631202c37303172,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x317225202c387025,0x30317225202c3130,0x38702540090a3b37\n"
".quad 0x4c24092061726220,0x383338345f385f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38313637345f385f,0x33732e646461090a,0x3030317225092032\n"
".quad 0x2c3030317225202c,0x766f6d090a3b3120,0x722509203233752e,0x3b3531202c383031\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x30317225202c3970,0x3830317225202c30\n"
".quad 0x2039702540090a3b,0x744c240920617262,0x38313637345f385f,0x5f385f744c240a3b\n"
".quad 0x090a3a3037353534,0x09373109636f6c2e,0x6d090a3009303731,0x09203436752e766f\n"
".quad 0x5f202c3236647225,0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f33335f30323637,0x736e6f635f6e6f6e,0x3173666572785f74,0x6c2e090a3b323537\n"
".quad 0x373109373109636f,0x6c756d090a300932,0x203233752e6f6c2e,0x202c393031722509\n"
".quad 0x3b3231202c317225,0x36752e747663090a,0x2509203233752e34,0x7225202c30376472\n"
".quad 0x6461090a3b393031,0x2509203436752e64,0x647225202c366472,0x31647225202c3037\n"
".quad 0x68732e646c090a3b,0x3233662e64657261,0x2c36343266250920,0x302b366472255b20\n"
".quad 0x2e766f6d090a3b5d,0x3266250920323366,0x34326625202c3734,0x732e646c090a3b36\n"
".quad 0x33662e6465726168,0x3834326625092032,0x2b366472255b202c,0x766f6d090a3b5d34\n"
".quad 0x662509203233662e,0x326625202c393432,0x2e646c090a3b3834,0x662e646572616873\n"
".quad 0x3532662509203233,0x366472255b202c30,0x6f6d090a3b5d382b,0x2509203233662e76\n"
".quad 0x6625202c31353266,0x744c240a3b303532,0x38353035345f385f,0x752e766f6d090a3a\n"
".quad 0x3664722509203436,0x6475635f5f202c32,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x30323637335f7261,0x5f6e6f6e5f33335f,0x72785f74736e6f63,0x3b32353731736665\n"
".quad 0x3109636f6c2e090a,0x0a30093537310937,0x6e79732e72616209,0x6d090a3b30092063\n"
".quad 0x33752e6f6c2e6c75,0x3031317225092032,0x34202c317225202c,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3137647225,0x40090a3b30313172,0x6172622031702521\n"
".quad 0x5f385f744c240920,0x090a3b3435313934,0x09373109636f6c2e,0x61090a3009383731\n"
".quad 0x09203436752e6464,0x25202c3237647225,0x7225202c31376472,0x646c090a3b323664\n"
".quad 0x2e6465726168732e,0x3172250920323375,0x6472255b202c3131,0x090a3b5d302b3237\n"
".quad 0x752e6f6c2e6c756d,0x3131722509203233,0x3131317225202c32,0x63090a3b3231202c\n"
".quad 0x752e3436752e7476,0x3764722509203233,0x3231317225202c33,0x752e646461090a3b\n"
".quad 0x3764722509203436,0x3337647225202c34,0x0a3b31647225202c,0x3233662e766f6d09\n"
".quad 0x2c32353266250920,0x0a3b373432662520,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b34376472255b,0x3235326625202c5d,0x662e766f6d090a3b,0x3532662509203233\n"
".quad 0x3934326625202c33,0x68732e7473090a3b,0x3233662e64657261,0x34376472255b0920\n"
".quad 0x326625202c5d342b,0x766f6d090a3b3335,0x662509203233662e,0x326625202c343532\n"
".quad 0x2e7473090a3b3135,0x662e646572616873,0x6472255b09203233,0x25202c5d382b3437\n"
".quad 0x4c240a3b34353266,0x353139345f385f74,0x636f6c2e090a3a34,0x0939313509373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x373109636f6c2e09,0x090a300936323509\n"
".quad 0x203233732e766f6d,0x202c333131722509,0x2e766f6d090a3b30,0x3266250920323366\n"
".quad 0x66376630202c3535,0x203b666666666637,0x2e33202f2f092020,0x332b653238323034\n"
".quad 0x752e766f6d090a38,0x3764722509203436,0x73646f7270202c35,0x2e766f6d090a3b34\n"
".quad 0x6472250920343675,0x68706c61202c3637,0x3b34656c62615461,0x36752e766f6d090a\n"
".quad 0x3737647225092034,0x616475635f5f202c,0x765f6c61636f6c5f,0x34393437335f7261\n"
".quad 0x5f6e6f6e5f34335f,0x5f735f74736e6f63,0x746174756d726570,0x3b325f5f736e6f69\n"
".quad 0x355f385f744c240a,0x2f200a3a38373130,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3520656e696c2079,0x7473656e202c3632,0x7470656420676e69,0x7365202c31203a68\n"
".quad 0x20646574616d6974,0x6f69746172657469,0x090a3631203a736e,0x09373109636f6c2e\n"
".quad 0x61090a3009353433,0x09203233732e6464,0x25202c3431317225,0x7225202c33313172\n"
".quad 0x2e766f6d090a3b31,0x3172250920323375,0x3b313939202c3531,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c303170,0x31317225202c3431,0x31702540090a3b35\n"
".quad 0x2409206172622030,0x3835325f385f744c,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323520656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373130355f385f,0x3109636f6c2e090a,0x0a30093834330937\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323375,0x31317225202c3631,0x63090a3b34202c34\n"
".quad 0x752e3436752e7476,0x3764722509203233,0x3631317225202c38,0x61702e646c090a3b\n"
".quad 0x203436752e6d6172,0x202c393764722509,0x70616475635f5f5b,0x63385a5f5f6d7261\n"
".quad 0x5073736572706d6f,0x7535505f30536a4b,0x7265705f32746e69,0x6e6f69746174756d\n"
".quad 0x646461090a3b5d73,0x722509203436752e,0x647225202c303864,0x37647225202c3837\n"
".quad 0x672e646c090a3b39,0x33752e6c61626f6c,0x3731317225092032,0x30386472255b202c\n"
".quad 0x6f6d090a3b5d302b,0x2509203233752e76,0x3531202c38313172,0x70746573090a3b39\n"
".quad 0x203233732e74672e,0x25202c3131702509,0x7225202c34313172,0x2540090a3b383131\n"
".quad 0x2061726220313170,0x355f385f744c2409,0x2f200a3b34333430,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3520656e696c2079,0x64616568202c3632\n"
".quad 0x64656c6562616c20,0x355f385f744c2420,0x6c2e090a38373130,0x343309373109636f\n"
".quad 0x747663090a300939,0x3233732e3436732e,0x2c31386472250920,0x0a3b343131722520\n"
".quad 0x6469772e6c756d09,0x2509203233732e65,0x7225202c32386472,0x0a3b34202c343131\n"
".quad 0x3436752e64646109,0x2c33386472250920,0x202c373764722520,0x090a3b3238647225\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x5d302b3338647225,0x3b3731317225202c\n"
".quad 0x355f385f744c240a,0x2f200a3a34333430,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3520656e696c2079,0x64616568202c3632,0x64656c6562616c20\n"
".quad 0x355f385f744c2420,0x6c2e090a38373130,0x353309373109636f,0x766f6d090a300931\n"
".quad 0x722509203233732e,0x0a3b30202c393131,0x3233732e766f6d09,0x2c30323172250920\n"
".quad 0x766f6d090a3b3020,0x722509203233732e,0x0a3b30202c313231,0x3233662e766f6d09\n"
".quad 0x2c36353266250920,0x3030303030663020,0x092020203b303030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x6630202c37353266,0x3030303030303030,0x202f2f092020203b\n"
".quad 0x662e766f6d090a30,0x3532662509203233,0x3030306630202c38,0x20203b3030303030\n"
".quad 0x240a30202f2f0920,0x3431355f385f744c,0x3c2f2f200a3a3835,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x31353320656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x72657469202c3120,0x203a736e6f697461,0x636f6c2e090a3631,0x0934323209373109\n"
".quad 0x752e726873090a30,0x3231722509203233,0x3731317225202c32,0x3b3931317225202c\n"
".quad 0x33622e646e61090a,0x3332317225092032,0x2c3232317225202c,0x747663090a3b3320\n"
".quad 0x3233752e3436752e,0x2c34386472250920,0x0a3b333231722520,0x6469772e6c756d09\n"
".quad 0x2509203233752e65,0x7225202c35386472,0x0a3b34202c333231,0x3436752e64646109\n"
".quad 0x2c36386472250920,0x202c353864722520,0x090a3b3637647225,0x74736e6f632e646c\n"
".quad 0x662509203233662e,0x72255b202c393532,0x0a3b5d302b363864,0x3436752e74766309\n"
".quad 0x722509203233752e,0x317225202c373864,0x646461090a3b3032,0x722509203436752e\n"
".quad 0x647225202c383864,0x31647225202c3738,0x68732e646c090a3b,0x3233662e64657261\n"
".quad 0x2c30363266250920,0x2b38386472255b20,0x616d66090a3b5d30,0x203233662e6e722e\n"
".quad 0x202c383532662509,0x25202c3036326625,0x6625202c39353266,0x646c090a3b383532\n"
".quad 0x2e6465726168732e,0x3266250920323366,0x6472255b202c3136,0x090a3b5d342b3838\n"
".quad 0x662e6e722e616d66,0x3532662509203233,0x3136326625202c37,0x2c3935326625202c\n"
".quad 0x0a3b373532662520,0x726168732e646c09,0x09203233662e6465,0x5b202c3236326625\n"
".quad 0x5d382b3838647225,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36353266\n"
".quad 0x326625202c323632,0x35326625202c3935,0x636f6c2e090a3b36,0x0935323209373109\n"
".quad 0x752e646461090a30,0x3864722509203436,0x3538647225202c39,0x3b3537647225202c\n"
".quad 0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3432317225,0x5d302b3938647225\n"
".quad 0x732e646461090a3b,0x3231722509203233,0x3432317225202c31,0x3b3132317225202c\n"
".quad 0x33752e646461090a,0x3032317225092032,0x2c3032317225202c,0x6461090a3b323120\n"
".quad 0x2509203233732e64,0x7225202c39313172,0x0a3b32202c393131,0x3233752e766f6d09\n"
".quad 0x2c35323172250920,0x6573090a3b323320,0x33732e656e2e7074,0x2c32317025092032\n"
".quad 0x202c393131722520,0x090a3b3532317225,0x7262203231702540,0x385f744c24092061\n"
".quad 0x0a3b38353431355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36323520,0x6c6562616c206461,0x385f744c24206465\n"
".quad 0x090a38373130355f,0x09373109636f6c2e,0x61090a3009333632,0x09203233622e646e\n"
".quad 0x25202c3632317225,0x3532202c31323172,0x2e726873090a3b35,0x3172250920323373\n"
".quad 0x32317225202c3732,0x090a3b3631202c31,0x203233732e726873,0x202c383231722509\n"
".quad 0x38202c3132317225,0x68732e646c090a3b,0x2e34762e64657261,0x66257b0920323366\n"
".quad 0x363266252c333632,0x2c35363266252c34,0x635f5f5b202c7d5f,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3637335f7261765f,0x6f6e5f36335f3931,0x5f74736e6f635f6e\n"
".quad 0x30363531736d7573,0x6f6d090a3b5d302b,0x2509203233662e76,0x6630202c36363266\n"
".quad 0x3030303030313134,0x202f2f092020203b,0x662e6c756d090a39,0x3632662509203233\n"
".quad 0x3336326625202c37,0x3b3636326625202c,0x33662e766f6d090a,0x3836326625092032\n"
".quad 0x303131346630202c,0x2020203b30303030,0x6d090a39202f2f09,0x09203233662e6c75\n"
".quad 0x25202c3936326625,0x6625202c34363266,0x6f6d090a3b383632,0x2509203233662e76\n"
".quad 0x6630202c30373266,0x3030303030313134,0x202f2f092020203b,0x662e6c756d090a39\n"
".quad 0x3732662509203233,0x3536326625202c31,0x3b3037326625202c,0x6e722e747663090a\n"
".quad 0x3233732e3233662e,0x2c32373266250920,0x0a3b363231722520,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x202c333732662509,0x090a3b3732317225,0x203233622e646e61\n"
".quad 0x202c393231722509,0x32202c3832317225,0x627573090a3b3535,0x662509203233662e\n"
".quad 0x326625202c343732,0x35326625202c3736,0x2e627573090a3b38,0x3266250920323366\n"
".quad 0x36326625202c3537,0x3735326625202c39,0x662e627573090a3b,0x3732662509203233\n"
".quad 0x3137326625202c36,0x3b3635326625202c,0x33662e6c756d090a,0x3737326625092032\n"
".quad 0x2c3237326625202c,0x0a3b323732662520,0x2e6e722e74766309,0x203233732e323366\n"
".quad 0x202c383732662509,0x090a3b3932317225,0x203233662e6c756d,0x202c393732662509\n"
".quad 0x25202c3237326625,0x6d090a3b34373266,0x09203233662e6c75,0x25202c3038326625\n"
".quad 0x6625202c32373266,0x756d090a3b353732,0x2509203233662e6c,0x6625202c31383266\n"
".quad 0x326625202c323732,0x6c756d090a3b3637,0x662509203233662e,0x326625202c323832\n"
".quad 0x37326625202c3337,0x2e627573090a3b38,0x3266250920323366,0x38326625202c3338\n"
".quad 0x3737326625202c32,0x662e6c756d090a3b,0x3832662509203233,0x3837326625202c34\n"
".quad 0x3b3835326625202c,0x33662e6c756d090a,0x3538326625092032,0x2c3837326625202c\n"
".quad 0x0a3b373532662520,0x3233662e6c756d09,0x2c36383266250920,0x202c383732662520\n"
".quad 0x090a3b3635326625,0x662e6e722e706372,0x3832662509203233,0x3338326625202c37\n"
".quad 0x662e627573090a3b,0x3832662509203233,0x3438326625202c38,0x3b3937326625202c\n"
".quad 0x33662e627573090a,0x3938326625092032,0x2c3538326625202c,0x0a3b303832662520\n"
".quad 0x3233662e62757309,0x2c30393266250920,0x202c363832662520,0x090a3b3138326625\n"
".quad 0x203233662e6c756d,0x202c313932662509,0x25202c3738326625,0x6d090a3b38383266\n"
".quad 0x09203233662e6c75,0x25202c3239326625,0x6625202c37383266,0x756d090a3b393832\n"
".quad 0x2509203233662e6c,0x6625202c33393266,0x326625202c373832,0x747663090a3b3039\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x326625202c343932,0x747663090a3b3139\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x326625202c353932,0x747663090a3b3239\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x326625202c363932,0x766f6d090a3b3339\n"
".quad 0x662509203233662e,0x346630202c373932,0x3b30303030386631,0x33202f2f09202020\n"
".quad 0x662e6c756d090a31,0x3932662509203233,0x3439326625202c38,0x3b3739326625202c\n"
".quad 0x33662e766f6d090a,0x3939326625092032,0x633732346630202c,0x2020203b30303030\n"
".quad 0x090a3336202f2f09,0x203233662e6c756d,0x202c303033662509,0x25202c3539326625\n"
".quad 0x6d090a3b39393266,0x09203233662e766f,0x30202c3130336625,0x3030303866313466\n"
".quad 0x2f2f092020203b30,0x6c756d090a313320,0x662509203233662e,0x326625202c323033\n"
".quad 0x30336625202c3639,0x2e747663090a3b31,0x2e3233662e696e72,0x3366250920323366\n"
".quad 0x39326625202c3330,0x2e747663090a3b38,0x2e3233662e696e72,0x3366250920323366\n"
".quad 0x30336625202c3430,0x2e747663090a3b30,0x2e3233662e696e72,0x3366250920323366\n"
".quad 0x30336625202c3530,0x2e747663090a3b32,0x2e3233752e697a72,0x3172250920323366\n"
".quad 0x30336625202c3033,0x2e6c6873090a3b33,0x3172250920323362,0x33317225202c3133\n"
".quad 0x090a3b3131202c30,0x2e697a722e747663,0x203233662e323375,0x202c323331722509\n"
".quad 0x090a3b3430336625,0x203233622e6c6873,0x202c333331722509,0x35202c3233317225\n"
".quad 0x33622e726f090a3b,0x3433317225092032,0x2c3133317225202c,0x0a3b333331722520\n"
".quad 0x697a722e74766309,0x3233662e3233752e,0x2c35333172250920,0x0a3b353033662520\n"
".quad 0x203233622e726f09,0x202c363331722509,0x25202c3433317225,0x2e090a3b35333172\n"
".quad 0x3209373109636f6c,0x756d090a30093436,0x2509203233662e6c,0x6625202c36303366\n"
".quad 0x326625202c323732,0x6c756d090a3b3835,0x662509203233662e,0x326625202c373033\n"
".quad 0x35326625202c3237,0x2e6c756d090a3b37,0x3366250920323366,0x37326625202c3830\n"
".quad 0x3635326625202c32,0x662e6c756d090a3b,0x3033662509203233,0x3337326625202c39\n"
".quad 0x3b3437326625202c,0x33662e6c756d090a,0x3031336625092032,0x2c3337326625202c\n"
".quad 0x0a3b353732662520,0x3233662e6c756d09,0x2c31313366250920,0x202c333732662520\n"
".quad 0x090a3b3637326625,0x203233662e627573,0x202c323133662509,0x25202c3930336625\n"
".quad 0x73090a3b36303366,0x09203233662e6275,0x25202c3331336625,0x6625202c30313366\n"
".quad 0x7573090a3b373033,0x2509203233662e62,0x6625202c34313366,0x336625202c313133\n"
".quad 0x6c756d090a3b3830,0x662509203233662e,0x336625202c353133,0x38326625202c3231\n"
".quad 0x2e6c756d090a3b37,0x3366250920323366,0x31336625202c3631,0x3738326625202c33\n"
".quad 0x662e6c756d090a3b,0x3133662509203233,0x3431336625202c37,0x3b3738326625202c\n"
".quad 0x61732e747663090a,0x33662e3233662e74,0x3831336625092032,0x3b3531336625202c\n"
".quad 0x61732e747663090a,0x33662e3233662e74,0x3931336625092032,0x3b3631336625202c\n"
".quad 0x61732e747663090a,0x33662e3233662e74,0x3032336625092032,0x3b3731336625202c\n"
".quad 0x33662e766f6d090a,0x3132336625092032,0x386631346630202c,0x2020203b30303030\n"
".quad 0x090a3133202f2f09,0x203233662e6c756d,0x202c323233662509,0x25202c3831336625\n"
".quad 0x6d090a3b31323366,0x09203233662e766f,0x30202c3332336625,0x3030306337323466\n"
".quad 0x2f2f092020203b30,0x6c756d090a333620,0x662509203233662e,0x336625202c343233\n"
".quad 0x32336625202c3931,0x2e766f6d090a3b33,0x3366250920323366,0x31346630202c3532\n"
".quad 0x203b303030303866,0x3133202f2f092020,0x33662e6c756d090a,0x3632336625092032\n"
".quad 0x2c3032336625202c,0x0a3b353233662520,0x696e722e74766309,0x3233662e3233662e\n"
".quad 0x2c37323366250920,0x0a3b323233662520,0x696e722e74766309,0x3233662e3233662e\n"
".quad 0x2c38323366250920,0x0a3b343233662520,0x696e722e74766309,0x3233662e3233662e\n"
".quad 0x2c39323366250920,0x0a3b363233662520,0x697a722e74766309,0x3233662e3233752e\n"
".quad 0x2c37333172250920,0x0a3b373233662520,0x3233622e6c687309,0x2c38333172250920\n"
".quad 0x202c373331722520,0x747663090a3b3131,0x3233752e697a722e,0x722509203233662e\n"
".quad 0x336625202c393331,0x6c6873090a3b3832,0x722509203233622e,0x317225202c303431\n"
".quad 0x090a3b35202c3933,0x09203233622e726f,0x25202c3134317225,0x7225202c38333172\n"
".quad 0x7663090a3b303431,0x33752e697a722e74,0x2509203233662e32,0x6625202c32343172\n"
".quad 0x726f090a3b393233,0x722509203233622e,0x317225202c333431,0x34317225202c3134\n"
".quad 0x636f6c2e090a3b32,0x0937363209373109,0x662e766f6d090a30,0x3333662509203233\n"
".quad 0x3064336630202c30,0x20203b3137353334,0x302e30202f2f0920,0x090a353737323233\n"
".quad 0x203233662e6c756d,0x202c313333662509,0x25202c3330336625,0x6d090a3b30333366\n"
".quad 0x09203233662e6c75,0x25202c3233336625,0x6625202c31333366,0x6f6d090a3b313333\n"
".quad 0x2509203233662e76,0x6630202c33333366,0x3931316231386333,0x202f2f092020203b\n"
".quad 0x3133383531302e30,0x662e6c756d090a35,0x3333662509203233,0x3430336625202c34\n"
".quad 0x3b3333336625202c,0x33662e6c756d090a,0x3533336625092032,0x2c3433336625202c\n"
".quad 0x0a3b343333662520,0x3233662e766f6d09,0x2c36333366250920,0x3334306433663020\n"
".quad 0x092020203b313735,0x3233302e30202f2f,0x756d090a35373732,0x2509203233662e6c\n"
".quad 0x6625202c37333366,0x336625202c353033,0x6c756d090a3b3633,0x662509203233662e\n"
".quad 0x336625202c383333,0x33336625202c3733,0x2e766f6d090a3b37,0x3366250920323366\n"
".quad 0x64336630202c3933,0x203b313735333430,0x2e30202f2f092020,0x0a35373732323330\n"
".quad 0x3233662e6c756d09,0x2c30343366250920,0x202c373233662520,0x090a3b3933336625\n"
".quad 0x203233662e6c756d,0x202c313433662509,0x25202c3034336625,0x6d090a3b30343366\n"
".quad 0x09203233662e766f,0x30202c3234336625,0x3131623138633366,0x2f2f092020203b39\n"
".quad 0x33383531302e3020,0x2e6c756d090a3531,0x3366250920323366,0x32336625202c3334\n"
".quad 0x3234336625202c38,0x662e6c756d090a3b,0x3433662509203233,0x3334336625202c34\n"
".quad 0x3b3334336625202c,0x33662e766f6d090a,0x3534336625092032,0x343064336630202c\n"
".quad 0x2020203b31373533,0x33302e30202f2f09,0x6d090a3537373232,0x09203233662e6c75\n"
".quad 0x25202c3634336625,0x6625202c39323366,0x756d090a3b353433,0x2509203233662e6c\n"
".quad 0x6625202c37343366,0x336625202c363433,0x6c756d090a3b3634,0x662509203233662e\n"
".quad 0x336625202c383433,0x33336625202c3034,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x34336625202c3934,0x3433336625202c33,0x662e6c756d090a3b,0x3533662509203233\n"
".quad 0x3634336625202c30,0x3b3733336625202c,0x33662e6c756d090a,0x3135336625092032\n"
".quad 0x2c3133336625202c,0x0a3b383532662520,0x3233662e6c756d09,0x2c32353366250920\n"
".quad 0x202c343333662520,0x090a3b3735326625,0x203233662e6c756d,0x202c333533662509\n"
".quad 0x25202c3733336625,0x6d090a3b36353266,0x09203233662e6c75,0x25202c3435336625\n"
".quad 0x6625202c34373266,0x756d090a3b303433,0x2509203233662e6c,0x6625202c35353366\n"
".quad 0x336625202c353732,0x6c756d090a3b3334,0x662509203233662e,0x326625202c363533\n"
".quad 0x34336625202c3637,0x636f6c2e090a3b36,0x0931353309373109,0x662e6c756d090a30\n"
".quad 0x3533662509203233,0x3237326625202c37,0x3b3934336625202c,0x33662e6c756d090a\n"
".quad 0x3835336625092032,0x2c3237326625202c,0x0a3b383433662520,0x3233662e6c756d09\n"
".quad 0x2c39353366250920,0x202c323732662520,0x090a3b3035336625,0x203233662e6c756d\n"
".quad 0x202c303633662509,0x25202c3337326625,0x6d090a3b35333366,0x09203233662e6c75\n"
".quad 0x25202c3136336625,0x6625202c33373266,0x756d090a3b323333,0x2509203233662e6c\n"
".quad 0x6625202c32363366,0x336625202c333732,0x627573090a3b3833,0x662509203233662e\n"
".quad 0x336625202c333633,0x35336625202c3735,0x2e627573090a3b32,0x3366250920323366\n"
".quad 0x35336625202c3436,0x3135336625202c38,0x662e627573090a3b,0x3633662509203233\n"
".quad 0x3935336625202c35,0x3b3335336625202c,0x33662e6c756d090a,0x3636336625092032\n"
".quad 0x2c3837326625202c,0x0a3b343433662520,0x3233662e6c756d09,0x2c37363366250920\n"
".quad 0x202c383732662520,0x090a3b3134336625,0x203233662e6c756d,0x202c383633662509\n"
".quad 0x25202c3837326625,0x73090a3b37343366,0x09203233662e6275,0x25202c3936336625\n"
".quad 0x6625202c33363366,0x7573090a3b353533,0x2509203233662e62,0x6625202c30373366\n"
".quad 0x336625202c343633,0x627573090a3b3435,0x662509203233662e,0x336625202c313733\n"
".quad 0x35336625202c3536,0x2e646461090a3b36,0x3366250920323366,0x36336625202c3237\n"
".quad 0x3636336625202c30,0x662e646461090a3b,0x3733662509203233,0x3136336625202c33\n"
".quad 0x3b3736336625202c,0x33662e646461090a,0x3437336625092032,0x2c3236336625202c\n"
".quad 0x0a3b383633662520,0x3233662e64646109,0x2c35373366250920,0x202c393633662520\n"
".quad 0x090a3b3936336625,0x203233662e646461,0x202c363733662509,0x25202c3037336625\n"
".quad 0x61090a3b30373366,0x09203233662e6464,0x25202c3737336625,0x6625202c31373366\n"
".quad 0x6461090a3b313733,0x2509203233662e64,0x6625202c38373366,0x336625202c323733\n"
".quad 0x646461090a3b3537,0x662509203233662e,0x336625202c393733,0x37336625202c3337\n"
".quad 0x2e646461090a3b36,0x3366250920323366,0x37336625202c3038,0x3737336625202c34\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x202c313833662509,0x4d726f6c6f436b5b\n"
".quad 0x5d342b6369727465,0x662e6c756d090a3b,0x3833662509203233,0x3138336625202c32\n"
".quad 0x3b3837336625202c,0x6e6f632e646c090a,0x09203233662e7473,0x5b202c3338336625\n"
".quad 0x654d726f6c6f436b,0x3b5d302b63697274,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x336625202c343833,0x38336625202c3937,0x3238336625202c33,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x202c353833662509,0x4d726f6c6f436b5b,0x5d382b6369727465\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36383366,0x336625202c303833\n"
".quad 0x38336625202c3538,0x2e766f6d090a3b34,0x3366250920323366,0x64336630202c3738\n"
".quad 0x203b393365383365,0x2e30202f2f092020,0x090a313131313131,0x203233662e6c756d\n"
".quad 0x202c383833662509,0x25202c3638336625,0x73090a3b37383366,0x662e746c2e707465\n"
".quad 0x3331702509203233,0x2c3838336625202c,0x0a3b353532662520,0x2033317025214009\n"
".quad 0x744c240920617262,0x30373931355f385f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323520656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373130355f385f,0x3109636f6c2e090a,0x0a30093535330937\n"
".quad 0x3233662e766f6d09,0x2c35353266250920,0x0a3b383833662520,0x373109636f6c2e09\n"
".quad 0x090a300936353309,0x203233732e766f6d,0x202c343431722509,0x090a3b3731317225\n"
".quad 0x09373109636f6c2e,0x63090a3009373533,0x752e3631752e7476,0x3168722509203233\n"
".quad 0x3b3633317225202c,0x3109636f6c2e090a,0x0a30093835330937,0x3631752e74766309\n"
".quad 0x722509203233752e,0x34317225202c3268,0x385f744c240a3b33,0x0a3a30373931355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36323520,0x6c6562616c206461,0x385f744c24206465,0x090a38373130355f\n"
".quad 0x09373109636f6c2e,0x61090a3009323433,0x09203233732e6464,0x25202c3331317225\n"
".quad 0x3436202c33313172,0x752e766f6d090a3b,0x3431722509203233,0x3b34323031202c35\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x317225202c343170,0x34317225202c3331\n"
".quad 0x31702540090a3b35,0x2409206172622034,0x3130355f385f744c,0x5f744c240a3b3837\n"
".quad 0x090a3a3835325f38,0x09373109636f6c2e,0x63090a3009303633,0x752e3233752e7476\n"
".quad 0x3431722509203631,0x3b32687225202c36,0x33752e747663090a,0x2509203631752e32\n"
".quad 0x7225202c37343172,0x746573090a3b3168,0x3233752e656c2e70,0x202c353170250920\n"
".quad 0x25202c3634317225,0x40090a3b37343172,0x6172622035317025,0x5f385f744c240920\n"
".quad 0x090a3b3833373235,0x09373109636f6c2e,0x6f6d090a30093237,0x2509203233732e76\n"
".quad 0x7225202c38343172,0x6c2e090a3b363431,0x333709373109636f,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x34317225202c3634,0x636f6c2e090a3b37,0x3009343709373109\n"
".quad 0x33732e766f6d090a,0x3734317225092032,0x3b3834317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093536330937,0x3233732e766f6d09,0x2c39343172250920,0x0a3b343431722520\n"
".quad 0x3233622e726f7809,0x2c30353172250920,0x202c393431722520,0x3735353631333431\n"
".quad 0x766f6d090a3b3536,0x722509203233732e,0x317225202c343431,0x5f744c240a3b3035\n"
".quad 0x3a38333732355f38,0x33732e766f6d090a,0x3135317225092032,0x6f6d090a3b30202c\n"
".quad 0x2509203436752e76,0x7270202c30396472,0x6d090a3b3373646f,0x09203436752e766f\n"
".quad 0x61202c3139647225,0x6c6261546168706c,0x5f744c240a3b3365,0x3a32363733355f38\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3536332065\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x33203a736e6f6974,0x3109636f6c2e090a,0x0a30093137330937,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323373,0x35317225202c3235,0x090a3b3436202c31,0x203233732e646461\n"
".quad 0x202c333531722509,0x25202c3235317225,0x766f6d090a3b3172,0x722509203233752e\n"
".quad 0x393531202c343531,0x2e70746573090a3b,0x09203233732e7467,0x7225202c36317025\n"
".quad 0x317225202c333531,0x702540090a3b3435,0x0920617262203631,0x69646e6557444c24\n"
".quad 0x72696636315a5f5f,0x566e656769457473,0x5f6650726f746365,0x200a3b325f373831\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c353633,0x656c6562616c2064,0x5f385f744c242064,0x2e090a3236373335\n"
".quad 0x3309373109636f6c,0x7663090a30093437,0x33732e3436732e74,0x3239647225092032\n"
".quad 0x3b3335317225202c,0x69772e6c756d090a,0x09203233732e6564,0x25202c3339647225\n"
".quad 0x3b34202c33353172,0x36752e646461090a,0x3439647225092034,0x2c3737647225202c\n"
".quad 0x0a3b333964722520,0x726168732e646c09,0x09203233752e6465,0x5b202c3535317225\n"
".quad 0x5d302b3439647225,0x09636f6c2e090a3b,0x3009353733093731,0x33732e766f6d090a\n"
".quad 0x3635317225092032,0x6f6d090a3b30202c,0x2509203233732e76,0x3b30202c37353172\n"
".quad 0x33732e766f6d090a,0x3835317225092032,0x6f6d090a3b30202c,0x2509203233662e76\n"
".quad 0x6630202c39383366,0x3030303030303030,0x202f2f092020203b,0x662e766f6d090a30\n"
".quad 0x3933662509203233,0x3030306630202c30,0x20203b3030303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x202c313933662509,0x3030303030306630,0x2f092020203b3030\n"
".quad 0x5f744c240a30202f,0x3a30333534355f38,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x6e202c3537332065,0x6420676e69747365,0x2c31203a68747065\n"
".quad 0x6974617265746920,0x0a3631203a736e6f,0x373109636f6c2e09,0x090a300935383209\n"
".quad 0x203233752e726873,0x202c393531722509,0x25202c3535317225,0x61090a3b36353172\n"
".quad 0x09203233622e646e,0x25202c3036317225,0x3b33202c39353172,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x7225202c35396472,0x756d090a3b303631,0x752e656469772e6c\n"
".quad 0x3964722509203233,0x3036317225202c36,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x7225202c37396472,0x647225202c363964,0x2e646c090a3b3139,0x33662e74736e6f63\n"
".quad 0x3239336625092032,0x37396472255b202c,0x7663090a3b5d302b,0x33752e3436752e74\n"
".quad 0x3839647225092032,0x3b3735317225202c,0x36752e646461090a,0x3939647225092034\n"
".quad 0x2c3839647225202c,0x090a3b3164722520,0x65726168732e646c,0x2509203233662e64\n"
".quad 0x255b202c33393366,0x3b5d302b39396472,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x336625202c313933,0x39336625202c3339,0x3139336625202c32,0x68732e646c090a3b\n"
".quad 0x3233662e64657261,0x2c34393366250920,0x2b39396472255b20,0x616d66090a3b5d34\n"
".quad 0x203233662e6e722e,0x202c303933662509,0x25202c3439336625,0x6625202c32393366\n"
".quad 0x646c090a3b303933,0x2e6465726168732e,0x3366250920323366,0x6472255b202c3539\n"
".quad 0x090a3b5d382b3939,0x662e6e722e616d66,0x3833662509203233,0x3539336625202c39\n"
".quad 0x2c3239336625202c,0x0a3b393833662520,0x373109636f6c2e09,0x090a300936383209\n"
".quad 0x203436752e646461,0x2c30303164722509,0x202c363964722520,0x090a3b3039647225\n"
".quad 0x74736e6f632e646c,0x722509203233732e,0x72255b202c313631,0x3b5d302b30303164\n"
".quad 0x33732e646461090a,0x3835317225092032,0x2c3136317225202c,0x0a3b383531722520\n"
".quad 0x3233752e64646109,0x2c37353172250920,0x202c373531722520,0x646461090a3b3231\n"
".quad 0x722509203233732e,0x317225202c363531,0x090a3b32202c3635,0x203233752e766f6d\n"
".quad 0x202c323631722509,0x746573090a3b3233,0x3233732e656e2e70,0x202c373170250920\n"
".quad 0x25202c3635317225,0x40090a3b32363172,0x6172622037317025,0x5f385f744c240920\n"
".quad 0x200a3b3033353435,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353633,0x656c6562616c2064,0x5f385f744c242064\n"
".quad 0x2e090a3236373335,0x3309373109636f6c,0x6e61090a30093332,0x2509203233622e64\n"
".quad 0x7225202c33363172,0x353532202c383531,0x732e726873090a3b,0x3631722509203233\n"
".quad 0x3835317225202c34,0x73090a3b3631202c,0x09203233732e7268,0x25202c3536317225\n"
".quad 0x3b38202c38353172,0x6168732e646c090a,0x662e34762e646572,0x3366257b09203233\n"
".quad 0x37393366252c3639,0x5f2c38393366252c,0x75635f5f5b202c7d,0x6475635f5f5f6164\n"
".quad 0x5f6c61636f6c5f61,0x313637335f726176,0x6e6f6e5f36335f39,0x735f74736e6f635f\n"
".quad 0x2b30363531736d75,0x766f6d090a3b5d30,0x662509203233662e,0x346630202c393933\n"
".quad 0x3b30303030303830,0x34202f2f09202020,0x33662e6c756d090a,0x3030346625092032\n"
".quad 0x2c3639336625202c,0x0a3b393933662520,0x3233662e766f6d09,0x2c31303466250920\n"
".quad 0x3030383034663020,0x092020203b303030,0x756d090a34202f2f,0x2509203233662e6c\n"
".quad 0x6625202c32303466,0x346625202c373933,0x766f6d090a3b3130,0x662509203233662e\n"
".quad 0x346630202c333034,0x3b30303030303830,0x34202f2f09202020,0x33662e6c756d090a\n"
".quad 0x3430346625092032,0x2c3839336625202c,0x0a3b333034662520,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x202c353034662509,0x090a3b3336317225,0x662e6e722e747663\n"
".quad 0x09203233732e3233,0x25202c3630346625,0x61090a3b34363172,0x09203233622e646e\n"
".quad 0x25202c3636317225,0x3532202c35363172,0x2e627573090a3b35,0x3466250920323366\n"
".quad 0x30346625202c3730,0x3139336625202c30,0x662e627573090a3b,0x3034662509203233\n"
".quad 0x3230346625202c38,0x3b3039336625202c,0x33662e627573090a,0x3930346625092032\n"
".quad 0x2c3430346625202c,0x0a3b393833662520,0x3233662e6c756d09,0x2c30313466250920\n"
".quad 0x202c353034662520,0x090a3b3530346625,0x662e6e722e747663,0x09203233732e3233\n"
".quad 0x25202c3131346625,0x6d090a3b36363172,0x09203233662e6c75,0x25202c3231346625\n"
".quad 0x6625202c35303466,0x756d090a3b373034,0x2509203233662e6c,0x6625202c33313466\n"
".quad 0x346625202c353034,0x6c756d090a3b3830,0x662509203233662e,0x346625202c343134\n"
".quad 0x30346625202c3530,0x2e6c756d090a3b39,0x3466250920323366,0x30346625202c3531\n"
".quad 0x3131346625202c36,0x662e627573090a3b,0x3134662509203233,0x3531346625202c36\n"
".quad 0x3b3031346625202c,0x33662e6c756d090a,0x3731346625092032,0x2c3131346625202c\n"
".quad 0x0a3b313933662520,0x3233662e6c756d09,0x2c38313466250920,0x202c313134662520\n"
".quad 0x090a3b3039336625,0x203233662e6c756d,0x202c393134662509,0x25202c3131346625\n"
".quad 0x72090a3b39383366,0x33662e6e722e7063,0x3032346625092032,0x3b3631346625202c\n"
".quad 0x33662e627573090a,0x3132346625092032,0x2c3731346625202c,0x0a3b323134662520\n"
".quad 0x3233662e62757309,0x2c32323466250920,0x202c383134662520,0x090a3b3331346625\n"
".quad 0x203233662e627573,0x202c333234662509,0x25202c3931346625,0x6d090a3b34313466\n"
".quad 0x09203233662e6c75,0x25202c3432346625,0x6625202c30323466,0x756d090a3b313234\n"
".quad 0x2509203233662e6c,0x6625202c35323466,0x346625202c303234,0x6c756d090a3b3232\n"
".quad 0x662509203233662e,0x346625202c363234,0x32346625202c3032,0x2e747663090a3b33\n"
".quad 0x2e3233662e746173,0x3466250920323366,0x32346625202c3732,0x2e747663090a3b34\n"
".quad 0x2e3233662e746173,0x3466250920323366,0x32346625202c3832,0x2e747663090a3b35\n"
".quad 0x2e3233662e746173,0x3466250920323366,0x32346625202c3932,0x2e766f6d090a3b36\n"
".quad 0x3466250920323366,0x31346630202c3033,0x203b303030303866,0x3133202f2f092020\n"
".quad 0x33662e6c756d090a,0x3133346625092032,0x2c3732346625202c,0x0a3b303334662520\n"
".quad 0x3233662e766f6d09,0x2c32333466250920,0x3063373234663020,0x092020203b303030\n"
".quad 0x6d090a3336202f2f,0x09203233662e6c75,0x25202c3333346625,0x6625202c38323466\n"
".quad 0x6f6d090a3b323334,0x2509203233662e76,0x6630202c34333466,0x3030303038663134\n"
".quad 0x202f2f092020203b,0x2e6c756d090a3133,0x3466250920323366,0x32346625202c3533\n"
".quad 0x3433346625202c39,0x722e747663090a3b,0x662e3233662e696e,0x3334662509203233\n"
".quad 0x3133346625202c36,0x722e747663090a3b,0x662e3233662e696e,0x3334662509203233\n"
".quad 0x3333346625202c37,0x722e747663090a3b,0x662e3233662e696e,0x3334662509203233\n"
".quad 0x3533346625202c38,0x722e747663090a3b,0x662e3233752e697a,0x3631722509203233\n"
".quad 0x3633346625202c37,0x622e6c6873090a3b,0x3631722509203233,0x3736317225202c38\n"
".quad 0x63090a3b3131202c,0x752e697a722e7476,0x09203233662e3233,0x25202c3936317225\n"
".quad 0x73090a3b37333466,0x09203233622e6c68,0x25202c3037317225,0x3b35202c39363172\n"
".quad 0x3233622e726f090a,0x2c31373172250920,0x202c383631722520,0x090a3b3037317225\n"
".quad 0x2e697a722e747663,0x203233662e323375,0x202c323731722509,0x090a3b3833346625\n"
".quad 0x09203233622e726f,0x25202c3337317225,0x7225202c31373172,0x7663090a3b323731\n"
".quad 0x33752e3631752e74,0x3437317225092032,0x3b3337317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093432330937,0x3233662e6c756d09,0x2c39333466250920,0x202c353034662520\n"
".quad 0x090a3b3139336625,0x203233662e6c756d,0x202c303434662509,0x25202c3530346625\n"
".quad 0x6d090a3b30393366,0x09203233662e6c75,0x25202c3134346625,0x6625202c35303466\n"
".quad 0x756d090a3b393833,0x2509203233662e6c,0x6625202c32343466,0x346625202c363034\n"
".quad 0x6c756d090a3b3730,0x662509203233662e,0x346625202c333434,0x30346625202c3630\n"
".quad 0x2e6c756d090a3b38,0x3466250920323366,0x30346625202c3434,0x3930346625202c36\n"
".quad 0x662e627573090a3b,0x3434662509203233,0x3234346625202c35,0x3b3933346625202c\n"
".quad 0x33662e627573090a,0x3634346625092032,0x2c3334346625202c,0x0a3b303434662520\n"
".quad 0x3233662e62757309,0x2c37343466250920,0x202c343434662520,0x090a3b3134346625\n"
".quad 0x203233662e6c756d,0x202c383434662509,0x25202c3534346625,0x6d090a3b30323466\n"
".quad 0x09203233662e6c75,0x25202c3934346625,0x6625202c36343466,0x756d090a3b303234\n"
".quad 0x2509203233662e6c,0x6625202c30353466,0x346625202c373434,0x747663090a3b3032\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x346625202c313534,0x747663090a3b3834\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x346625202c323534,0x747663090a3b3934\n"
".quad 0x3233662e7461732e,0x662509203233662e,0x346625202c333534,0x766f6d090a3b3035\n"
".quad 0x662509203233662e,0x346630202c343534,0x3b30303030386631,0x33202f2f09202020\n"
".quad 0x662e6c756d090a31,0x3534662509203233,0x3135346625202c35,0x3b3435346625202c\n"
".quad 0x33662e766f6d090a,0x3635346625092032,0x633732346630202c,0x2020203b30303030\n"
".quad 0x090a3336202f2f09,0x203233662e6c756d,0x202c373534662509,0x25202c3235346625\n"
".quad 0x6d090a3b36353466,0x09203233662e766f,0x30202c3835346625,0x3030303866313466\n"
".quad 0x2f2f092020203b30,0x6c756d090a313320,0x662509203233662e,0x346625202c393534\n"
".quad 0x35346625202c3335,0x2e747663090a3b38,0x2e3233662e696e72,0x3466250920323366\n"
".quad 0x35346625202c3036,0x2e747663090a3b35,0x2e3233662e696e72,0x3466250920323366\n"
".quad 0x35346625202c3136,0x2e747663090a3b37,0x2e3233662e696e72,0x3466250920323366\n"
".quad 0x35346625202c3236,0x2e747663090a3b39,0x2e3233752e697a72,0x3172250920323366\n"
".quad 0x36346625202c3537,0x2e6c6873090a3b30,0x3172250920323362,0x37317225202c3637\n"
".quad 0x090a3b3131202c35,0x2e697a722e747663,0x203233662e323375,0x202c373731722509\n"
".quad 0x090a3b3136346625,0x203233622e6c6873,0x202c383731722509,0x35202c3737317225\n"
".quad 0x33622e726f090a3b,0x3937317225092032,0x2c3637317225202c,0x0a3b383731722520\n"
".quad 0x697a722e74766309,0x3233662e3233752e,0x2c30383172250920,0x0a3b323634662520\n"
".quad 0x203233622e726f09,0x202c313831722509,0x25202c3937317225,0x63090a3b30383172\n"
".quad 0x752e3631752e7476,0x3831722509203233,0x3138317225202c32,0x09636f6c2e090a3b\n"
".quad 0x3009373233093731,0x33662e766f6d090a,0x3336346625092032,0x343064336630202c\n"
".quad 0x2020203b31373533,0x33302e30202f2f09,0x6d090a3537373232,0x09203233662e6c75\n"
".quad 0x25202c3436346625,0x6625202c36333466,0x756d090a3b333634,0x2509203233662e6c\n"
".quad 0x6625202c35363466,0x346625202c343634,0x766f6d090a3b3436,0x662509203233662e\n"
".quad 0x336630202c363634,0x3b39313162313863,0x30202f2f09202020,0x353133383531302e\n"
".quad 0x33662e6c756d090a,0x3736346625092032,0x2c3733346625202c,0x0a3b363634662520\n"
".quad 0x3233662e6c756d09,0x2c38363466250920,0x202c373634662520,0x090a3b3736346625\n"
".quad 0x203233662e766f6d,0x202c393634662509,0x3533343064336630,0x2f092020203b3137\n"
".quad 0x323233302e30202f,0x6c756d090a353737,0x662509203233662e,0x346625202c303734\n"
".quad 0x36346625202c3833,0x2e6c756d090a3b39,0x3466250920323366,0x37346625202c3137\n"
".quad 0x3037346625202c30,0x662e766f6d090a3b,0x3734662509203233,0x3064336630202c32\n"
".quad 0x20203b3137353334,0x302e30202f2f0920,0x090a353737323233,0x203233662e6c756d\n"
".quad 0x202c333734662509,0x25202c3036346625,0x6d090a3b32373466,0x09203233662e6c75\n"
".quad 0x25202c3437346625,0x6625202c33373466,0x6f6d090a3b333734,0x2509203233662e76\n"
".quad 0x6630202c35373466,0x3931316231386333,0x202f2f092020203b,0x3133383531302e30\n"
".quad 0x662e6c756d090a35,0x3734662509203233,0x3136346625202c36,0x3b3537346625202c\n"
".quad 0x33662e6c756d090a,0x3737346625092032,0x2c3637346625202c,0x0a3b363734662520\n"
".quad 0x3233662e766f6d09,0x2c38373466250920,0x3334306433663020,0x092020203b313735\n"
".quad 0x3233302e30202f2f,0x756d090a35373732,0x2509203233662e6c,0x6625202c39373466\n"
".quad 0x346625202c323634,0x6c756d090a3b3837,0x662509203233662e,0x346625202c303834\n"
".quad 0x37346625202c3937,0x2e6c756d090a3b39,0x3466250920323366,0x37346625202c3138\n"
".quad 0x3436346625202c33,0x662e6c756d090a3b,0x3834662509203233,0x3637346625202c32\n"
".quad 0x3b3736346625202c,0x33662e6c756d090a,0x3338346625092032,0x2c3937346625202c\n"
".quad 0x0a3b303734662520,0x3233662e6c756d09,0x2c34383466250920,0x202c343634662520\n"
".quad 0x090a3b3139336625,0x203233662e6c756d,0x202c353834662509,0x25202c3736346625\n"
".quad 0x6d090a3b30393366,0x09203233662e6c75,0x25202c3638346625,0x6625202c30373466\n"
".quad 0x756d090a3b393833,0x2509203233662e6c,0x6625202c37383466,0x346625202c373034\n"
".quad 0x6c756d090a3b3337,0x662509203233662e,0x346625202c383834,0x37346625202c3830\n"
".quad 0x2e6c756d090a3b36,0x3466250920323366,0x30346625202c3938,0x3937346625202c39\n"
".quad 0x09636f6c2e090a3b,0x3009353733093731,0x33662e6c756d090a,0x3039346625092032\n"
".quad 0x2c3530346625202c,0x0a3b323834662520,0x3233662e6c756d09,0x2c31393466250920\n"
".quad 0x202c353034662520,0x090a3b3138346625,0x203233662e6c756d,0x202c323934662509\n"
".quad 0x25202c3530346625,0x6d090a3b33383466,0x09203233662e6c75,0x25202c3339346625\n"
".quad 0x6625202c36303466,0x756d090a3b383634,0x2509203233662e6c,0x6625202c34393466\n"
".quad 0x346625202c363034,0x6c756d090a3b3536,0x662509203233662e,0x346625202c353934\n"
".quad 0x37346625202c3630,0x2e627573090a3b31,0x3466250920323366,0x39346625202c3639\n"
".quad 0x3538346625202c30,0x662e627573090a3b,0x3934662509203233,0x3139346625202c37\n"
".quad 0x3b3438346625202c,0x33662e627573090a,0x3839346625092032,0x2c3239346625202c\n"
".quad 0x0a3b363834662520,0x3233662e6c756d09,0x2c39393466250920,0x202c313134662520\n"
".quad 0x090a3b3737346625,0x203233662e6c756d,0x202c303035662509,0x25202c3131346625\n"
".quad 0x6d090a3b34373466,0x09203233662e6c75,0x25202c3130356625,0x6625202c31313466\n"
".quad 0x7573090a3b303834,0x2509203233662e62,0x6625202c32303566,0x346625202c363934\n"
".quad 0x627573090a3b3838,0x662509203233662e,0x346625202c333035,0x38346625202c3739\n"
".quad 0x2e627573090a3b37,0x3566250920323366,0x39346625202c3430,0x3938346625202c38\n"
".quad 0x662e646461090a3b,0x3035662509203233,0x3339346625202c35,0x3b3939346625202c\n"
".quad 0x33662e646461090a,0x3630356625092032,0x2c3439346625202c,0x0a3b303035662520\n"
".quad 0x3233662e64646109,0x2c37303566250920,0x202c353934662520,0x090a3b3130356625\n"
".quad 0x203233662e646461,0x202c383035662509,0x25202c3230356625,0x61090a3b32303566\n"
".quad 0x09203233662e6464,0x25202c3930356625,0x6625202c33303566,0x6461090a3b333035\n"
".quad 0x2509203233662e64,0x6625202c30313566,0x356625202c343035,0x646461090a3b3430\n"
".quad 0x662509203233662e,0x356625202c313135,0x30356625202c3530,0x2e646461090a3b38\n"
".quad 0x3566250920323366,0x30356625202c3231,0x3930356625202c36,0x662e646461090a3b\n"
".quad 0x3135662509203233,0x3730356625202c33,0x3b3031356625202c,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x5b202c3431356625,0x654d726f6c6f436b,0x3b5d342b63697274\n"
".quad 0x33662e6c756d090a,0x3531356625092032,0x2c3431356625202c,0x0a3b313135662520\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x6b5b202c36313566,0x74654d726f6c6f43\n"
".quad 0x0a3b5d302b636972,0x2e6e722e616d6609,0x3566250920323366,0x31356625202c3731\n"
".quad 0x3631356625202c32,0x3b3531356625202c,0x6e6f632e646c090a,0x09203233662e7473\n"
".quad 0x5b202c3831356625,0x654d726f6c6f436b,0x3b5d382b63697274,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x356625202c393135,0x31356625202c3331,0x3731356625202c38\n"
".quad 0x662e766f6d090a3b,0x3235662509203233,0x3865336630202c30,0x20203b3030303030\n"
".quad 0x322e30202f2f0920,0x662e6c756d090a35,0x3235662509203233,0x3931356625202c31\n"
".quad 0x3b3032356625202c,0x6c2e70746573090a,0x2509203233662e74,0x356625202c383170\n"
".quad 0x35326625202c3132,0x70252140090a3b35,0x0920617262203831,0x35355f385f744c24\n"
".quad 0x2f2f200a3b343535,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363320656e696c20,0x2064616568202c35,0x2064656c6562616c,0x33355f385f744c24\n"
".quad 0x6f6c2e090a323637,0x3937330937310963,0x2e766f6d090a3009,0x3266250920323366\n"
".quad 0x32356625202c3535,0x636f6c2e090a3b31,0x0930383309373109,0x732e766f6d090a30\n"
".quad 0x3831722509203233,0x3535317225202c33,0x09636f6c2e090a3b,0x3009313833093731\n"
".quad 0x33732e766f6d090a,0x3734317225092032,0x3b3437317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093238330937,0x3233732e766f6d09,0x2c36343172250920,0x0a3b323831722520\n"
".quad 0x656c2e7074657309,0x702509203233752e,0x37317225202c3931,0x3238317225202c34\n"
".quad 0x3931702540090a3b,0x4c24092061726220,0x313835355f385f74,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35363320656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363733355f385f74,0x09636f6c2e090a32\n"
".quad 0x0a30093237093731,0x3233732e766f6d09,0x2c34383172250920,0x0a3b363431722520\n"
".quad 0x373109636f6c2e09,0x6d090a3009333709,0x09203233732e766f,0x25202c3634317225\n"
".quad 0x2e090a3b37343172,0x3709373109636f6c,0x766f6d090a300934,0x722509203233732e\n"
".quad 0x317225202c373431,0x6f6c2e090a3b3438,0x3738330937310963,0x2e746f6e090a3009\n"
".quad 0x3172250920323362,0x35317225202c3538,0x2e726873090a3b35,0x3172250920323375\n"
".quad 0x38317225202c3638,0x61090a3b31202c35,0x09203233622e646e,0x25202c3738317225\n"
".quad 0x3431202c36383172,0x3536373535363133,0x622e726f78090a3b,0x3831722509203233\n"
".quad 0x3535317225202c38,0x3b3738317225202c,0x33732e766f6d090a,0x3434317225092032\n"
".quad 0x3b3838317225202c,0x6e752e617262090a,0x385f744c24092069,0x0a3b34353535355f\n"
".quad 0x35355f385f744c24,0x2f2f200a3a303138,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363320656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x33355f385f744c24,0x766f6d090a323637,0x722509203233732e,0x317225202c343431\n"
".quad 0x5f744c240a3b3338,0x3a34353535355f38,0x355f385f744c240a,0x2f200a3a32343035\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079\n"
".quad 0x64616568202c3536,0x64656c6562616c20,0x355f385f744c2420,0x6c2e090a32363733\n"
".quad 0x363309373109636f,0x646461090a300938,0x722509203233732e,0x317225202c313531\n"
".quad 0x090a3b31202c3135,0x203233752e766f6d,0x202c393831722509,0x70746573090a3b33\n"
".quad 0x203233732e656e2e,0x25202c3032702509,0x7225202c31353172,0x2540090a3b393831\n"
".quad 0x2061726220303270,0x355f385f744c2409,0x4c240a3b32363733,0x5f5f69646e655744\n"
".quad 0x747372696636315a,0x6365566e65676945,0x38315f6650726f74,0x6c2e090a3a325f37\n"
".quad 0x393309373109636f,0x766f6d090a300930,0x722509203436752e,0x5f5f202c31303164\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f35335f393236\n"
".quad 0x74736e6f635f6e6f,0x3173726f7272655f,0x6f6d090a3b363138,0x2509203436752e76\n"
".quad 0x5f202c3230316472,0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3735353733\n"
".quad 0x6e6f635f6e6f6e5f,0x6369646e695f7473,0x090a3b315f5f7365,0x09373109636f6c2e\n"
".quad 0x61090a3009323933,0x09203436752e6464,0x202c333031647225,0x25202c3137647225\n"
".quad 0x090a3b3130316472,0x65726168732e7473,0x5b09203233662e64,0x302b333031647225\n"
".quad 0x3535326625202c5d,0x09636f6c2e090a3b,0x3009343034093731,0x36752e646461090a\n"
".quad 0x3031647225092034,0x3835647225202c34,0x323031647225202c,0x68732e7473090a3b\n"
".quad 0x3233732e64657261,0x30316472255b0920,0x7225202c5d302b34,0x2e766f6d090a3b31\n"
".quad 0x3172250920323373,0x0a3b3233202c3039,0x36355f385f744c24,0x2f2f200a3a343338\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x303420656e696c20,0x697473656e202c34\n"
".quad 0x687470656420676e,0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574\n"
".quad 0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0939303409373109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x656c2e7074657309,0x702509203233732e,0x39317225202c3132\n"
".quad 0x0a3b317225202c30,0x6220313270254009,0x5f744c2409206172,0x3b32303637355f38\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3430342065,0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f38\n"
".quad 0x373109636f6c2e09,0x090a300934313409,0x203233732e646461,0x202c313931722509\n"
".quad 0x25202c3039317225,0x6c756d090a3b3172,0x203233752e6f6c2e,0x202c323931722509\n"
".quad 0x34202c3139317225,0x752e747663090a3b,0x09203233752e3436,0x202c353031647225\n"
".quad 0x090a3b3239317225,0x203436752e646461,0x2c36303164722509,0x2c35303164722520\n"
".quad 0x3b31303164722520,0x6168732e646c090a,0x203233662e646572,0x202c323235662509\n"
".quad 0x2b3630316472255b,0x2e646c090a3b5d30,0x662e646572616873,0x3235662509203233\n"
".quad 0x316472255b202c33,0x090a3b5d302b3330,0x2e74672e70746573,0x3270250920323366\n"
".quad 0x3332356625202c32,0x3b3232356625202c,0x323270252140090a,0x4c24092061726220\n"
".quad 0x303637355f385f74,0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c34303420656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333836355f385f74,0x09636f6c2e090a34,0x3009373134093731,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x3330316472255b09,0x356625202c5d302b,0x6f6c2e090a3b3232\n"
".quad 0x3831340937310963,0x2e747663090a3009,0x203233732e343673,0x2c37303164722509\n"
".quad 0x0a3b313931722520,0x6469772e6c756d09,0x2509203233732e65,0x25202c3830316472\n"
".quad 0x3b34202c31393172,0x36752e646461090a,0x3031647225092034,0x3031647225202c39\n"
".quad 0x3031647225202c32,0x732e646c090a3b38,0x33732e6465726168,0x3339317225092032\n"
".quad 0x30316472255b202c,0x73090a3b5d302b39,0x6465726168732e74,0x255b09203233732e\n"
".quad 0x5d302b3430316472,0x3b3339317225202c,0x355f385f744c240a,0x4c240a3a32303637\n"
".quad 0x393037355f385f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c34303420656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333836355f385f74,0x09636f6c2e090a34,0x3009373034093731,0x33732e726873090a\n"
".quad 0x3039317225092032,0x2c3039317225202c,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x0a3b30202c343931,0x74672e7074657309,0x702509203233732e,0x39317225202c3332\n"
".quad 0x3439317225202c30,0x3332702540090a3b,0x4c24092061726220,0x333836355f385f74\n"
".quad 0x636f6c2e090a3b34,0x0932373409373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300934373409,0x65726168732e646c,0x2509203233732e64\n"
".quad 0x5f5b202c35393172,0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3735353733\n"
".quad 0x6e6f635f6e6f6e5f,0x6369646e695f7473,0x5d302b315f5f7365,0x09636f6c2e090a3b\n"
".quad 0x3009313335093731,0x79732e726162090a,0x090a3b300920636e,0x2e656e2e70746573\n"
".quad 0x3270250920323373,0x3539317225202c34,0x090a3b317225202c,0x7262203432702540\n"
".quad 0x385f744c24092061,0x0a3b30373338355f,0x373109636f6c2e09,0x090a300935393409\n"
".quad 0x2e71652e70746573,0x3270250920323375,0x3634317225202c35,0x3b3734317225202c\n"
".quad 0x33752e766f6d090a,0x3639317225092032,0x6f6d090a3b30202c,0x2509203233732e76\n"
".quad 0x7225202c37393172,0x6573090a3b343431,0x09203233752e706c,0x25202c3839317225\n"
".quad 0x7225202c36393172,0x327025202c373931,0x732e646c090a3b35,0x34762e6465726168\n"
".quad 0x257b09203233732e,0x3272252c39393172,0x31303272252c3030,0x2c7d32303272252c\n"
".quad 0x616475635f5f5b20,0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f30323637335f72\n"
".quad 0x635f6e6f6e5f3333,0x6572785f74736e6f,0x302b323537317366,0x2e6c756d090a3b5d\n"
".quad 0x09203233732e6f6c,0x25202c3330327225,0x3b32202c39393172,0x33752e726873090a\n"
".quad 0x3430327225092032,0x2c3839317225202c,0x0a3b333032722520,0x3233622e646e6109\n"
".quad 0x2c35303272250920,0x202c343032722520,0x2e6c756d090a3b33,0x09203233732e6f6c\n"
".quad 0x25202c3630327225,0x3b32202c30303272,0x33752e726873090a,0x3730327225092032\n"
".quad 0x2c3839317225202c,0x0a3b363032722520,0x3233622e646e6109,0x2c38303272250920\n"
".quad 0x202c373032722520,0x2e6c6873090a3b33,0x3272250920323362,0x30327225202c3930\n"
".quad 0x6f090a3b32202c38,0x2509203233622e72,0x7225202c30313272,0x327225202c353032\n"
".quad 0x6c756d090a3b3930,0x203233732e6f6c2e,0x202c313132722509,0x32202c3130327225\n"
".quad 0x752e726873090a3b,0x3132722509203233,0x3839317225202c32,0x3b3131327225202c\n"
".quad 0x33622e646e61090a,0x3331327225092032,0x2c3231327225202c,0x6c6873090a3b3320\n"
".quad 0x722509203233622e,0x327225202c343132,0x090a3b34202c3331,0x732e6f6c2e6c756d\n"
".quad 0x3132722509203233,0x3230327225202c35,0x6873090a3b32202c,0x2509203233752e72\n"
".quad 0x7225202c36313272,0x327225202c383931,0x646e61090a3b3531,0x722509203233622e\n"
".quad 0x327225202c373132,0x090a3b33202c3631,0x203233622e6c6873,0x202c383132722509\n"
".quad 0x36202c3731327225,0x33622e726f090a3b,0x3931327225092032,0x2c3431327225202c\n"
".quad 0x0a3b383132722520,0x203233622e726f09,0x202c303232722509,0x25202c3031327225\n"
".quad 0x6c090a3b39313272,0x6465726168732e64,0x203233732e34762e,0x2c31323272257b09\n"
".quad 0x72252c3232327225,0x323272252c333232,0x635f5f5b202c7d34,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3637335f7261765f,0x6f6e5f33335f3032,0x5f74736e6f635f6e\n"
".quad 0x3537317366657278,0x090a3b5d36312b32,0x732e6f6c2e6c756d,0x3232722509203233\n"
".quad 0x3132327225202c35,0x6873090a3b32202c,0x2509203233752e72,0x7225202c36323272\n"
".quad 0x327225202c383931,0x646e61090a3b3532,0x722509203233622e,0x327225202c373232\n"
".quad 0x090a3b33202c3632,0x203233622e6c6873,0x202c383232722509,0x38202c3732327225\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c39323272,0x0a3b32202c323232\n"
".quad 0x3233752e72687309,0x2c30333272250920,0x202c383931722520,0x090a3b3932327225\n"
".quad 0x203233622e646e61,0x202c313332722509,0x33202c3033327225,0x622e6c6873090a3b\n"
".quad 0x3332722509203233,0x3133327225202c32,0x6f090a3b3031202c,0x2509203233622e72\n"
".quad 0x7225202c33333272,0x327225202c383232,0x2e726f090a3b3233,0x3272250920323362\n"
".quad 0x32327225202c3433,0x3333327225202c30,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c35333272,0x0a3b32202c333232,0x3233752e72687309,0x2c36333272250920\n"
".quad 0x202c383931722520,0x090a3b3533327225,0x203233622e646e61,0x202c373332722509\n"
".quad 0x33202c3633327225,0x622e6c6873090a3b,0x3332722509203233,0x3733327225202c38\n"
".quad 0x6d090a3b3231202c,0x33732e6f6c2e6c75,0x3933327225092032,0x2c3432327225202c\n"
".quad 0x726873090a3b3220,0x722509203233752e,0x317225202c303432,0x33327225202c3839\n"
".quad 0x2e646e61090a3b39,0x3272250920323362,0x34327225202c3134,0x73090a3b33202c30\n"
".quad 0x09203233622e6c68,0x25202c3234327225,0x3431202c31343272,0x33622e726f090a3b\n"
".quad 0x3334327225092032,0x2c3833327225202c,0x0a3b323432722520,0x203233622e726f09\n"
".quad 0x202c343432722509,0x25202c3433327225,0x6c090a3b33343272,0x6465726168732e64\n"
".quad 0x203233732e34762e,0x2c35343272257b09,0x72252c3634327225,0x343272252c373432\n"
".quad 0x635f5f5b202c7d38,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3637335f7261765f\n"
".quad 0x6f6e5f33335f3032,0x5f74736e6f635f6e,0x3537317366657278,0x090a3b5d32332b32\n"
".quad 0x732e6f6c2e6c756d,0x3432722509203233,0x3534327225202c39,0x6873090a3b32202c\n"
".quad 0x2509203233752e72,0x7225202c30353272,0x327225202c383931,0x646e61090a3b3934\n"
".quad 0x722509203233622e,0x327225202c313532,0x090a3b33202c3035,0x203233622e6c6873\n"
".quad 0x202c323532722509,0x31202c3135327225,0x622e726f090a3b36,0x3532722509203233\n"
".quad 0x3434327225202c33,0x3b3235327225202c,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x327225202c343532,0x090a3b32202c3634,0x203233752e726873,0x202c353532722509\n"
".quad 0x25202c3839317225,0x61090a3b34353272,0x09203233622e646e,0x25202c3635327225\n"
".quad 0x3b33202c35353272,0x33622e6c6873090a,0x3735327225092032,0x2c3635327225202c\n"
".quad 0x726f090a3b383120,0x722509203233622e,0x327225202c383532,0x35327225202c3335\n"
".quad 0x2e6c756d090a3b37,0x09203233732e6f6c,0x25202c3935327225,0x3b32202c37343272\n"
".quad 0x33752e726873090a,0x3036327225092032,0x2c3839317225202c,0x0a3b393532722520\n"
".quad 0x3233622e646e6109,0x2c31363272250920,0x202c303632722520,0x2e6c6873090a3b33\n"
".quad 0x3272250920323362,0x36327225202c3236,0x090a3b3032202c31,0x09203233622e726f\n"
".quad 0x25202c3336327225,0x7225202c38353272,0x756d090a3b323632,0x3233732e6f6c2e6c\n"
".quad 0x2c34363272250920,0x202c383432722520,0x2e726873090a3b32,0x3272250920323375\n"
".quad 0x39317225202c3536,0x3436327225202c38,0x622e646e61090a3b,0x3632722509203233\n"
".quad 0x3536327225202c36,0x6873090a3b33202c,0x2509203233622e6c,0x7225202c37363272\n"
".quad 0x3b3232202c363632,0x3233622e726f090a,0x2c38363272250920,0x202c333632722520\n"
".quad 0x090a3b3736327225,0x65726168732e646c,0x3233732e34762e64,0x39363272257b0920\n"
".quad 0x252c30373272252c,0x3272252c31373272,0x5f5f5b202c7d3237,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f33335f303236,0x74736e6f635f6e6f\n"
".quad 0x373173666572785f,0x0a3b5d38342b3235,0x2e6f6c2e6c756d09,0x3272250920323373\n"
".quad 0x36327225202c3337,0x73090a3b32202c39,0x09203233752e7268,0x25202c3437327225\n"
".quad 0x7225202c38393172,0x6e61090a3b333732,0x2509203233622e64,0x7225202c35373272\n"
".quad 0x0a3b33202c343732,0x3233622e6c687309,0x2c36373272250920,0x202c353732722520\n"
".quad 0x2e726f090a3b3432,0x3272250920323362,0x36327225202c3737,0x3637327225202c38\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c38373272,0x0a3b32202c303732\n"
".quad 0x3233752e72687309,0x2c39373272250920,0x202c383931722520,0x090a3b3837327225\n"
".quad 0x203233622e646e61,0x202c303832722509,0x33202c3937327225,0x622e6c6873090a3b\n"
".quad 0x3832722509203233,0x3038327225202c31,0x6f090a3b3632202c,0x2509203233622e72\n"
".quad 0x7225202c32383272,0x327225202c373732,0x6c756d090a3b3138,0x203233732e6f6c2e\n"
".quad 0x202c333832722509,0x32202c3137327225,0x752e726873090a3b,0x3832722509203233\n"
".quad 0x3839317225202c34,0x3b3338327225202c,0x33622e646e61090a,0x3538327225092032\n"
".quad 0x2c3438327225202c,0x6c6873090a3b3320,0x722509203233622e,0x327225202c363832\n"
".quad 0x0a3b3832202c3538,0x203233622e726f09,0x202c373832722509,0x25202c3238327225\n"
".quad 0x6d090a3b36383272,0x33732e6f6c2e6c75,0x3838327225092032,0x2c3237327225202c\n"
".quad 0x726873090a3b3220,0x722509203233752e,0x317225202c393832,0x38327225202c3839\n"
".quad 0x2e6c6873090a3b38,0x3272250920323362,0x38327225202c3039,0x090a3b3033202c39\n"
".quad 0x09203233622e726f,0x25202c3139327225,0x7225202c37383272,0x6c2e090a3b303932\n"
".quad 0x393409373109636f,0x747663090a300939,0x3233752e3233732e,0x2c32393272250920\n"
".quad 0x2e64696174632520,0x2e6c756d090a3b78,0x09203233752e6f6c,0x25202c3339327225\n"
".quad 0x3b38202c32393272,0x36752e747663090a,0x2509203233752e34,0x25202c3031316472\n"
".quad 0x6c090a3b33393272,0x2e6d617261702e64,0x6472250920343675,0x5f5f5b202c313131\n"
".quad 0x6d72617061647563,0x706d6f63385a5f5f,0x536a4b5073736572,0x746e697535505f30\n"
".quad 0x746c757365725f32,0x2e646461090a3b5d,0x6472250920343675,0x647225202c323131\n"
".quad 0x647225202c303131,0x6873090a3b313131,0x2509203233622e6c,0x7225202c34393272\n"
".quad 0x3b3631202c363431,0x3233622e726f090a,0x2c35393272250920,0x202c373431722520\n"
".quad 0x090a3b3439327225,0x61626f6c672e7473,0x3233752e32762e6c,0x31316472255b0920\n"
".quad 0x257b202c5d302b32,0x3272252c35393272,0x744c240a3b7d3139,0x30373338355f385f\n"
".quad 0x09636f6c2e090a3a,0x3009383335093731,0x0a3b74697865090a,0x5f646e6557444c24\n"
".quad 0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f,0x202f2f207d090a3a\n"
".quad 0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f,0x0000000000000a0a\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[13280];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"31bfbbaacc21c0b1",(char*)"/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x8b7546ed,&__elfEntries1};
# 3 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c" 2
struct __T20 {const uint *__par0;const uint *__par1;uint2 *__par2;int __dummy_field;};
extern void __device_stub__Z8compressPKjS0_P5uint2(const uint *, const uint *, uint2 *);
static void __sti____cudaRegisterAll_39_tmpxft_000008a7_00000000_4_dxtc_cpp1_ii_b480a5a9(void) __attribute__((__constructor__));
void __device_stub__Z8compressPKjS0_P5uint2(const uint *__par0, const uint *__par1, uint2 *__par2){ struct __T20 *__T2324 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2324->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2324->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2324->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(const uint *, const uint *, uint2 *))compress)); (void)cudaLaunch(((char *)((void ( *)(const uint *, const uint *, uint2 *))compress))); };}
void compress( const uint *__cuda_0,const uint *__cuda_1,uint2 *__cuda_2)
# 510 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
{__device_stub__Z8compressPKjS0_P5uint2( __cuda_0,__cuda_1,__cuda_2);
# 538 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/dxtc/dxtc.cu"
}
# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c"
static void __sti____cudaRegisterAll_39_tmpxft_000008a7_00000000_4_dxtc_cpp1_ii_b480a5a9(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(const uint *, const uint *, uint2 *))compress), (char*)"_Z8compressPKjS0_P5uint2", "_Z8compressPKjS0_P5uint2", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&kColorMetric, (char*)"kColorMetric", "kColorMetric", 0, 12, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable4, (char*)"alphaTable4", "alphaTable4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable3, (char*)"alphaTable3", "alphaTable3", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods4, (char*)"prods4", "prods4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods3, (char*)"prods3", "prods3", 0, 16, 1, 0); }
# 1 "/tmp/tmpxft_000008a7_00000000-1_dxtc.cudafe1.stub.c" 2

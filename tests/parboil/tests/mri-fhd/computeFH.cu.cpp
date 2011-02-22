# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/stddef.h" 3
typedef int ptrdiff_t;
# 211 "/usr/lib/gcc/i686-linux-gnu/4.4.5/include/stddef.h" 3
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
# 327 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 328 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 330 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 333 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 334 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 336 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 340 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 345 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 346 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 351 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 352 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 360 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 364 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 367 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 368 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 375 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 376 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 380 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 687 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 688 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 693 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 694 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 696 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 700 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 702 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 705 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 706 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 708 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 711 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 712 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 716 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 719 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 720 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 724 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 727 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 728 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 732 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 735 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulong4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 736 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 740 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 1003 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1004 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1006 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1008 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1009 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1011 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1013 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1014 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1016 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1018 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1019 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1024 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1026 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1028 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1029 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1031 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1033 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1034 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1036 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1038 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1039 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1041 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 1296 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1297 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1302 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1304 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1306 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1307 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1309 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1311 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1314 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1316 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1317 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1319 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1321 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1322 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1324 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1326 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1327 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1329 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1331 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1332 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1334 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 279 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex1Dfetch(texture< long, 1, cudaReadModeElementType> t, int x)
# 280 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 286 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex1Dfetch(texture< unsigned long, 1, cudaReadModeElementType> t, int x)
# 287 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex1Dfetch(texture< long1, 1, cudaReadModeElementType> t, int x)
# 294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 298 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 300 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex1Dfetch(texture< ulong1, 1, cudaReadModeElementType> t, int x)
# 301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 305 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex1Dfetch(texture< long2, 1, cudaReadModeElementType> t, int x)
# 308 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 312 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex1Dfetch(texture< ulong2, 1, cudaReadModeElementType> t, int x)
# 315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 319 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 321 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex1Dfetch(texture< long4, 1, cudaReadModeElementType> t, int x)
# 322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 328 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex1Dfetch(texture< ulong4, 1, cudaReadModeElementType> t, int x)
# 329 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 734 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex1D(texture< long, 1, cudaReadModeElementType> t, float x)
# 735 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 741 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex1D(texture< unsigned long, 1, cudaReadModeElementType> t, float x)
# 742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 746 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex1D(texture< long1, 1, cudaReadModeElementType> t, float x)
# 749 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 753 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 755 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex1D(texture< ulong1, 1, cudaReadModeElementType> t, float x)
# 756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 760 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 762 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex1D(texture< long2, 1, cudaReadModeElementType> t, float x)
# 763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 769 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex1D(texture< ulong2, 1, cudaReadModeElementType> t, float x)
# 770 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 776 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex1D(texture< long4, 1, cudaReadModeElementType> t, float x)
# 777 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 781 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex1D(texture< ulong4, 1, cudaReadModeElementType> t, float x)
# 784 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 1183 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex2D(texture< long, 2, cudaReadModeElementType> t, float x, float y)
# 1184 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1190 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex2D(texture< unsigned long, 2, cudaReadModeElementType> t, float x, float y)
# 1191 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1197 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex2D(texture< long1, 2, cudaReadModeElementType> t, float x, float y)
# 1198 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex2D(texture< ulong1, 2, cudaReadModeElementType> t, float x, float y)
# 1205 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1209 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1211 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex2D(texture< long2, 2, cudaReadModeElementType> t, float x, float y)
# 1212 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1218 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex2D(texture< ulong2, 2, cudaReadModeElementType> t, float x, float y)
# 1219 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1225 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex2D(texture< long4, 2, cudaReadModeElementType> t, float x, float y)
# 1226 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1232 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex2D(texture< ulong4, 2, cudaReadModeElementType> t, float x, float y)
# 1233 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 1632 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex3D(texture< long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1633 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1639 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex3D(texture< unsigned long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1640 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1646 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex3D(texture< long1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1647 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1653 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex3D(texture< ulong1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1654 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1658 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1660 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex3D(texture< long2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1661 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1667 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex3D(texture< ulong2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1668 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1674 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex3D(texture< long4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1675 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1681 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex3D(texture< ulong4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1682 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 93 "/usr/include/c++/4.4/cstdio" 3
namespace std __attribute__((visibility("default"))) {
# 95 "/usr/include/c++/4.4/cstdio" 3
using ::FILE;
# 96 "/usr/include/c++/4.4/cstdio" 3
using ::fpos_t;
# 98 "/usr/include/c++/4.4/cstdio" 3
using ::clearerr;
# 99 "/usr/include/c++/4.4/cstdio" 3
using ::fclose;
# 100 "/usr/include/c++/4.4/cstdio" 3
using ::feof;
# 101 "/usr/include/c++/4.4/cstdio" 3
using ::ferror;
# 102 "/usr/include/c++/4.4/cstdio" 3
using ::fflush;
# 103 "/usr/include/c++/4.4/cstdio" 3
using ::fgetc;
# 104 "/usr/include/c++/4.4/cstdio" 3
using ::fgetpos;
# 105 "/usr/include/c++/4.4/cstdio" 3
using ::fgets;
# 106 "/usr/include/c++/4.4/cstdio" 3
using ::fopen;
# 107 "/usr/include/c++/4.4/cstdio" 3
using ::fprintf;
# 108 "/usr/include/c++/4.4/cstdio" 3
using ::fputc;
# 109 "/usr/include/c++/4.4/cstdio" 3
using ::fputs;
# 110 "/usr/include/c++/4.4/cstdio" 3
using ::fread;
# 111 "/usr/include/c++/4.4/cstdio" 3
using ::freopen;
# 112 "/usr/include/c++/4.4/cstdio" 3
using ::fscanf;
# 113 "/usr/include/c++/4.4/cstdio" 3
using ::fseek;
# 114 "/usr/include/c++/4.4/cstdio" 3
using ::fsetpos;
# 115 "/usr/include/c++/4.4/cstdio" 3
using ::ftell;
# 116 "/usr/include/c++/4.4/cstdio" 3
using ::fwrite;
# 117 "/usr/include/c++/4.4/cstdio" 3
using ::getc;
# 118 "/usr/include/c++/4.4/cstdio" 3
using ::getchar;
# 119 "/usr/include/c++/4.4/cstdio" 3
using ::gets;
# 120 "/usr/include/c++/4.4/cstdio" 3
using ::perror;
# 121 "/usr/include/c++/4.4/cstdio" 3
using ::printf;
# 122 "/usr/include/c++/4.4/cstdio" 3
using ::putc;
# 123 "/usr/include/c++/4.4/cstdio" 3
using ::putchar;
# 124 "/usr/include/c++/4.4/cstdio" 3
using ::puts;
# 125 "/usr/include/c++/4.4/cstdio" 3
using ::remove;
# 126 "/usr/include/c++/4.4/cstdio" 3
using ::rename;
# 127 "/usr/include/c++/4.4/cstdio" 3
using ::rewind;
# 128 "/usr/include/c++/4.4/cstdio" 3
using ::scanf;
# 129 "/usr/include/c++/4.4/cstdio" 3
using ::setbuf;
# 130 "/usr/include/c++/4.4/cstdio" 3
using ::setvbuf;
# 131 "/usr/include/c++/4.4/cstdio" 3
using ::sprintf;
# 132 "/usr/include/c++/4.4/cstdio" 3
using ::sscanf;
# 133 "/usr/include/c++/4.4/cstdio" 3
using ::tmpfile;
# 134 "/usr/include/c++/4.4/cstdio" 3
using ::tmpnam;
# 135 "/usr/include/c++/4.4/cstdio" 3
using ::ungetc;
# 136 "/usr/include/c++/4.4/cstdio" 3
using ::vfprintf;
# 137 "/usr/include/c++/4.4/cstdio" 3
using ::vprintf;
# 138 "/usr/include/c++/4.4/cstdio" 3
using ::vsprintf;
# 140 "/usr/include/c++/4.4/cstdio" 3
}
# 150 "/usr/include/c++/4.4/cstdio" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 165 "/usr/include/c++/4.4/cstdio" 3
using ::snprintf;
# 166 "/usr/include/c++/4.4/cstdio" 3
using ::vfscanf;
# 167 "/usr/include/c++/4.4/cstdio" 3
using ::vscanf;
# 168 "/usr/include/c++/4.4/cstdio" 3
using ::vsnprintf;
# 169 "/usr/include/c++/4.4/cstdio" 3
using ::vsscanf;
# 172 "/usr/include/c++/4.4/cstdio" 3
}
# 174 "/usr/include/c++/4.4/cstdio" 3
namespace std __attribute__((visibility("default"))) {
# 176 "/usr/include/c++/4.4/cstdio" 3
using __gnu_cxx::snprintf;
# 177 "/usr/include/c++/4.4/cstdio" 3
using __gnu_cxx::vfscanf;
# 178 "/usr/include/c++/4.4/cstdio" 3
using __gnu_cxx::vscanf;
# 179 "/usr/include/c++/4.4/cstdio" 3
using __gnu_cxx::vsnprintf;
# 180 "/usr/include/c++/4.4/cstdio" 3
using __gnu_cxx::vsscanf;
# 182 "/usr/include/c++/4.4/cstdio" 3
}
# 29 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
struct kValues {
# 30 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
float Kx;
# 31 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
float Ky;
# 32 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
float Kz;
# 33 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
float RhoPhiR;
# 34 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
float RhoPhiI;
# 35 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
};
# 37 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
static kValues c[512];
# 39 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
void createDataStructs(int numK, int numX, float *&
# 40 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
realRhoPhi, float *&imagRhoPhi, float *&
# 41 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
outR, float *&outI)
# 42 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{
# 43 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
realRhoPhi = ((float *)calloc(numK, sizeof(float)));
# 44 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
imagRhoPhi = ((float *)calloc(numK, sizeof(float)));
# 45 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
outR = ((float *)calloc(numX, sizeof(float)));
# 46 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
outI = ((float *)calloc(numX, sizeof(float)));
# 47 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 50 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
void ComputeRhoPhiGPU(int numK, float *
# 51 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
phiR, float *phiI, float *
# 52 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
dR, float *dI, float *
# 53 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
realRhoPhi, float *imagRhoPhi) ;
# 67 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
void ComputeFH_GPU(int numK, int kGlobalIndex, float *
# 68 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
x, float *y, float *z, float *
# 69 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
outR, float *outI) ;
# 142 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
void computeRhoPhi_GPU(int numK, float *
# 143 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
phiR_d, float *phiI_d, float *dR_d, float *dI_d, float *
# 144 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
realRhoPhi_d, float *imagRhoPhi_d)
# 145 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{
# 146 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
int rhoPhiBlocks = (numK / 512);
# 148 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
if (numK % 512) {
# 149 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
rhoPhiBlocks++; }
# 151 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
dim3 DimRhoPhiBlock(512, 1);
# 152 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
dim3 DimRhoPhiGrid(rhoPhiBlocks, 1);
# 153 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
printf("Launch RhoPhi Kernel on GPU: Blocks (%d, %d), Threads Per Block %d\n", rhoPhiBlocks, 1, 512);
# 156 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
cudaConfigureCall(DimRhoPhiGrid, DimRhoPhiBlock) ? ((void)0) : ComputeRhoPhiGPU(numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d);
# 158 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 160 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
void computeFH_GPU(int numK, int numX, float *
# 161 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
x_d, float *y_d, float *z_d, kValues *
# 162 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
kVals, float *
# 163 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
outR_d, float *outI_d)
# 164 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{
# 165 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
int FHGrids = (numK / 512);
# 166 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
if (numK % 512) {
# 167 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
FHGrids++; }
# 168 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
int FHBlocks = (numX / 256);
# 169 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
if (numX % 256) {
# 170 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
FHBlocks++; }
# 171 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
dim3 DimFHBlock(256, 1);
# 172 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
dim3 DimFHGrid(FHBlocks, 1);
# 174 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
printf("Launch GPU Kernel: Grids %d, Blocks Per Grid (%d, %d), Threads Per Block (%d, %d), K Elems Per Thread %d\n", FHGrids, DimFHGrid.x, DimFHGrid.y, DimFHBlock.x, DimFHBlock.y, 512);
# 177 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
for (int FHGrid = 0; FHGrid < FHGrids; FHGrid++) {
# 179 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
int FHGridBase = (FHGrid * 512);
# 181 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
kValues *kValsTile = (kVals + FHGridBase);
# 182 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
int numElems = ((512 < (numK - FHGridBase)) ? 512 : (numK - FHGridBase));
# 183 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
printf("Copying %d bytes to constant memory\n", numElems * sizeof(kValues));
# 184 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
cudaMemcpyToSymbol(c, kValsTile, numElems * sizeof(kValues), 0);
# 185 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{ cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 185, cudaGetErrorString(err)); exit(-1); } } ;
# 187 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
cudaConfigureCall(DimFHGrid, DimFHBlock) ? ((void)0) : ComputeFH_GPU(numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d);
# 189 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{ cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 189, cudaGetErrorString(err)); exit(-1); } } ;
# 190 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 191 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c"
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_000015aa_00000000-3_computeFH.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000015aa_00000000-3_computeFH.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x2d2f2f090a0a3930,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f\n"
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f6161353130,0x372d303030303030\n"
".quad 0x657475706d6f635f,0x2e337070632e4846,0x2f706d742f282069,0x48372e2349426363\n"
".quad 0x2f090a2941796a57,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f090a0a2d2d2d2d,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x736e6f6974704f20,0x2d2d2d2f2f090a3a,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x615420202f2f090a,0x7874703a74656772\n"
".quad 0x6d733a415349202c,0x646e45202c30325f,0x7474696c3a6e6169,0x6e696f50202c656c\n"
".quad 0x657a695320726574,0x202f2f090a32333a,0x704f2809334f2d20,0x6974617a696d6974\n"
".quad 0x6c6576656c206e6f,0x2d20202f2f090a29,0x7562654428093067,0x296c6576656c2067\n"
".quad 0x6d2d20202f2f090a,0x726f706552280932,0x6f73697664612074,0x2f090a2973656972\n"
".quad 0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2e090a0a2d2d2d2d\n"
".quad 0x22093109656c6966,0x646e616d6d6f633c,0x0a223e656e696c2d,0x3209656c69662e09\n"
".quad 0x742f706d742f2209,0x30305f746678706d,0x305f616135313030,0x2d30303030303030\n"
".quad 0x7475706d6f635f36,0x616475632e484665,0x227570672e326566,0x09656c69662e090a\n"
".quad 0x656d6f682f220933,0x2f6c616d726f6e2f,0x74756f6b63656863,0x6c65636f7570672f\n"
".quad 0x73747365742f746f,0x6c696f627261702f,0x6d2f73747365742f,0x632f6468662d6972\n"
".quad 0x4846657475706d6f,0x662e090a2275632e,0x2f22093409656c69,0x2f62696c2f727375\n"
".quad 0x363836692f636367,0x672d78756e696c2d,0x352e342e342f756e,0x6564756c636e692f\n"
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
".quad 0x682e656d69742f65,0x656c69662e090a22,0x73752f2209373109,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x6d6d6f632f656475,0x74636e75665f6e6f\n"
".quad 0x0a22682e736e6f69,0x3109656c69662e09,0x2f7273752f220938,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x665f6874616d2f65,0x736e6f6974636e75\n"
".quad 0x69662e090a22682e,0x2f2209393109656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x616d2f6564756c63,0x74736e6f635f6874,0x0a22682e73746e61\n"
".quad 0x3209656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x6563697665642f65,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09313209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x74615f31315f6d73,0x6e75665f63696d6f,0x682e736e6f697463\n"
".quad 0x656c69662e090a22,0x73752f2209323209,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x315f6d732f656475,0x63696d6f74615f32,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09333209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6f645f33315f6d73,0x6e75665f656c6275\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209343209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x325f6d732f656475,0x63696d6f74615f30\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09353209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6e695f30325f6d73\n"
".quad 0x736369736e697274,0x69662e090a22682e,0x2f2209363209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x75732f6564756c63,0x75665f6563616672\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220937320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x7865742f6564756c,0x7465665f65727574\n"
".quad 0x74636e75665f6863,0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220938\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x665f6874616d2f65\n"
".quad 0x736e6f6974636e75,0x7874705f6c62645f,0x090a0a0a22682e33,0x5f207972746e652e\n"
".quad 0x75706d6f4336315a,0x6968506f68526574,0x5f53665069555047,0x5f535f535f535f53\n"
".quad 0x61702e09090a2820,0x3233732e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x52657475706d6f43,0x5550476968506f68,0x535f535f53665069,0x756e5f5f535f535f\n"
".quad 0x702e09090a2c4b6d,0x33752e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4336,0x50476968506f6852,0x5f535f5366506955,0x705f5f535f535f53\n"
".quad 0x2e09090a2c526968,0x752e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x7475706d6f433631,0x476968506f685265,0x535f536650695550,0x5f5f535f535f535f\n"
".quad 0x09090a2c49696870,0x2e206d617261702e,0x75635f5f20323375,0x5f5f6d7261706164\n"
".quad 0x75706d6f4336315a,0x6968506f68526574,0x5f53665069555047,0x5f535f535f535f53\n"
".quad 0x2e09090a2c52645f,0x752e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x7475706d6f433631,0x476968506f685265,0x535f536650695550,0x5f5f535f535f535f\n"
".quad 0x702e09090a2c4964,0x33752e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4336,0x50476968506f6852,0x5f535f5366506955,0x725f5f535f535f53\n"
".quad 0x68506f68526c6165,0x61702e09090a2c69,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x52657475706d6f43,0x5550476968506f68,0x535f535f53665069\n"
".quad 0x6d695f5f535f535f,0x6968506f68526761,0x722e090a7b090a29,0x203233752e206765\n"
".quad 0x0a3b3e30323c7225,0x662e206765722e09,0x31313c6625203233,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x2e090a3b3e333c70,0x3335093309636f6c,0x6257444c240a3009\n"
".quad 0x315a5f5f6e696765,0x657475706d6f4336,0x50476968506f6852,0x5f535f5366506955\n"
".quad 0x0a3a5f535f535f53,0x3233752e766f6d09,0x25202c3172250920,0x3b782e6469617463\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x202c317225202c32,0x6f6d090a3b323135\n"
".quad 0x2509203233752e76,0x64697425202c3372,0x646461090a3b782e,0x722509203233752e\n"
".quad 0x202c337225202c34,0x646c090a3b327225,0x732e6d617261702e,0x2c35722509203233\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x657475706d6f4336,0x50476968506f6852\n"
".quad 0x5f535f5366506955,0x6e5f5f535f535f53,0x73090a3b5d4b6d75,0x732e656c2e707465\n"
".quad 0x2c31702509203233,0x7225202c35722520,0x31702540090a3b34,0x4c24092061726220\n"
".quad 0x363230315f305f74,0x09636f6c2e090a3b,0x090a300937350933,0x752e6f6c2e6c756d\n"
".quad 0x2c36722509203233,0x3b34202c34722520,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c377225,0x6d72617061647563,0x6d6f4336315a5f5f,0x506f685265747570\n"
".quad 0x6650695550476968,0x5f535f535f535f53,0x5d526968705f5f53,0x752e646461090a3b\n"
".quad 0x2c38722509203233,0x7225202c37722520,0x672e646c090a3b36,0x33662e6c61626f6c\n"
".quad 0x202c316625092032,0x3b5d302b3872255b,0x3309636f6c2e090a,0x6c090a3009383509\n"
".quad 0x2e6d617261702e64,0x3972250920323375,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x7475706d6f433631,0x476968506f685265,0x535f536650695550,0x5f5f535f535f535f\n"
".quad 0x090a3b5d49696870,0x203233752e646461,0x25202c3031722509,0x3b367225202c3972\n"
".quad 0x6f6c672e646c090a,0x203233662e6c6162,0x255b202c32662509,0x0a3b5d302b303172\n"
".quad 0x093309636f6c2e09,0x646c090a30093935,0x752e6d617261702e,0x3131722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7475706d6f433631,0x476968506f685265\n"
".quad 0x535f536650695550,0x5f5f535f535f535f,0x6461090a3b5d5264,0x2509203233752e64\n"
".quad 0x317225202c323172,0x0a3b367225202c31,0x626f6c672e646c09,0x09203233662e6c61\n"
".quad 0x72255b202c336625,0x090a3b5d302b3231,0x36093309636f6c2e,0x2e646c090a300930\n"
".quad 0x33752e6d61726170,0x2c33317225092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4336,0x50476968506f6852,0x5f535f5366506955,0x645f5f535f535f53\n"
".quad 0x646461090a3b5d49,0x722509203233752e,0x33317225202c3431,0x090a3b367225202c\n"
".quad 0x61626f6c672e646c,0x2509203233662e6c,0x3172255b202c3466,0x2e090a3b5d302b34\n"
".quad 0x3136093309636f6c,0x2e6c756d090a3009,0x3566250920323366,0x25202c326625202c\n"
".quad 0x616d66090a3b3466,0x203233662e6e722e,0x6625202c36662509,0x202c336625202c31\n"
".quad 0x646c090a3b356625,0x752e6d617261702e,0x3531722509203233,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x7475706d6f433631,0x476968506f685265,0x535f536650695550\n"
".quad 0x5f5f535f535f535f,0x506f68526c616572,0x6461090a3b5d6968,0x2509203233752e64\n"
".quad 0x317225202c363172,0x0a3b367225202c35,0x626f6c672e747309,0x09203233662e6c61\n"
".quad 0x5d302b363172255b,0x090a3b366625202c,0x36093309636f6c2e,0x6c756d090a300932\n"
".quad 0x662509203233662e,0x202c326625202c37,0x756d090a3b336625,0x2509203233662e6c\n"
".quad 0x2c316625202c3866,0x73090a3b34662520,0x09203233662e6275,0x386625202c396625\n"
".quad 0x090a3b376625202c,0x6d617261702e646c,0x722509203233752e,0x635f5f5b202c3731\n"
".quad 0x5f6d726170616475,0x706d6f4336315a5f,0x68506f6852657475,0x5366506955504769\n"
".quad 0x535f535f535f535f,0x685267616d695f5f,0x090a3b5d6968506f,0x203233752e646461\n"
".quad 0x25202c3831722509,0x367225202c373172,0x6c672e7473090a3b,0x3233662e6c61626f\n"
".quad 0x2b383172255b0920,0x3b396625202c5d30,0x315f305f744c240a,0x6c2e090a3a363230\n"
".quad 0x093436093309636f,0x3b74697865090a30,0x646e6557444c240a,0x6d6f4336315a5f5f\n"
".quad 0x506f685265747570,0x6650695550476968,0x5f535f535f535f53,0x2f207d090a3a5f53\n"
".quad 0x6f4336315a5f202f,0x6f6852657475706d,0x5069555047696850,0x535f535f535f5366\n"
".quad 0x6f632e090a5f535f,0x696c612e2074736e,0x38622e2034206e67,0x30343230315b6320\n"
".quad 0x6e6f632e090a3b5d,0x67696c612e207473,0x2038622e2034206e,0x7472616475635f5f\n"
".quad 0x665f69706f32695f,0x7b203d205d34325b,0x362c3434312c3536,0x3335312c30362c37\n"
".quad 0x2c38392c3934312c,0x2c3239312c393132,0x322c32352c313232,0x382c3930322c3534\n"
".quad 0x3235322c39332c37,0x362c31322c31342c,0x3031312c38372c38,0x3934322c3133312c\n"
".quad 0x0a0a3b7d3236312c,0x207972746e652e09,0x706d6f4333315a5f,0x50475f4846657475\n"
".quad 0x535f536650696955,0x0a28205f535f535f,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6d6f4333315a5f5f,0x475f484665747570,0x5f53665069695550\n"
".quad 0x6e5f5f535f535f53,0x2e09090a2c4b6d75,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6d72617061,0x7475706d6f433331,0x695550475f484665,0x535f535f53665069\n"
".quad 0x61765f5f5f5f535f,0x6b6d617261705f6c,0x6e496c61626f6c47,0x2e09090a2c786564\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x7475706d6f433331\n"
".quad 0x695550475f484665,0x535f535f53665069,0x090a2c785f5f535f,0x206d617261702e09\n"
".quad 0x635f5f203233752e,0x5f6d726170616475,0x706d6f4333315a5f,0x50475f4846657475\n"
".quad 0x535f536650696955,0x2c795f5f535f535f,0x617261702e09090a,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x6f4333315a5f5f6d,0x5f4846657475706d,0x5366506969555047\n"
".quad 0x5f5f535f535f535f,0x61702e09090a2c7a,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x33315a5f5f6d7261,0x46657475706d6f43,0x5069695550475f48,0x535f535f535f5366\n"
".quad 0x0a2c5274756f5f5f,0x6d617261702e0909,0x5f5f203233752e20,0x6d72617061647563\n"
".quad 0x6d6f4333315a5f5f,0x475f484665747570,0x5f53665069695550,0x6f5f5f535f535f53\n"
".quad 0x0a7b090a29497475,0x752e206765722e09,0x32373c7225203233,0x65722e090a3b3e37\n"
".quad 0x25203233662e2067,0x0a3b3e3237333c66,0x662e206765722e09,0x323c646625203436\n"
".quad 0x65722e090a3b3e32,0x20646572702e2067,0x3b3e3033313c7025,0x6c61636f6c2e090a\n"
".quad 0x206e67696c612e20,0x5f5f2038622e2034,0x635f5f5f61647563,0x757365725f616475\n"
".quad 0x32303136315f746c,0x0a3b5d38325b3639,0x206c61636f6c2e09,0x34206e67696c612e\n"
".quad 0x635f5f2038622e20,0x75635f5f5f616475,0x6c757365725f6164,0x3233303134345f74\n"
".quad 0x090a3b5d38325b34,0x36093309636f6c2e,0x57444c240a300939,0x5a5f5f6e69676562\n"
".quad 0x7475706d6f433331,0x695550475f484665,0x535f535f53665069,0x646c090a3a5f535f\n"
".quad 0x732e6d617261702e,0x2c31722509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4333,0x69695550475f4846,0x5f535f535f536650,0x6c61765f5f5f5f53\n"
".quad 0x476b6d617261705f,0x646e496c61626f6c,0x6f6d090a3b5d7865,0x2509203233732e76\n"
".quad 0x3b317225202c3272,0x3309636f6c2e090a,0x6d090a3009303809,0x09203233752e766f\n"
".quad 0x746325202c337225,0x090a3b782e646961,0x752e6f6c2e6c756d,0x2c34722509203233\n"
".quad 0x3532202c33722520,0x2e766f6d090a3b36,0x3572250920323375,0x782e64697425202c\n"
".quad 0x752e646461090a3b,0x2c36722509203233,0x7225202c35722520,0x2e6c756d090a3b34\n"
".quad 0x09203233752e6f6c,0x367225202c377225,0x646c090a3b34202c,0x752e6d617261702e\n"
".quad 0x2c38722509203233,0x616475635f5f5b20,0x315a5f5f6d726170,0x657475706d6f4333\n"
".quad 0x69695550475f4846,0x5f535f535f536650,0x090a3b5d785f5f53,0x203233752e646461\n"
".quad 0x7225202c39722509,0x0a3b377225202c38,0x626f6c672e646c09,0x09203233662e6c61\n"
".quad 0x72255b202c316625,0x2e090a3b5d302b39,0x3138093309636f6c,0x702e646c090a3009\n"
".quad 0x3233752e6d617261,0x202c303172250920,0x70616475635f5f5b,0x33315a5f5f6d7261\n"
".quad 0x46657475706d6f43,0x5069695550475f48,0x535f535f535f5366,0x61090a3b5d795f5f\n"
".quad 0x09203233752e6464,0x7225202c31317225,0x3b377225202c3031,0x6f6c672e646c090a\n"
".quad 0x203233662e6c6162,0x255b202c32662509,0x0a3b5d302b313172,0x093309636f6c2e09\n"
".quad 0x646c090a30093238,0x752e6d617261702e,0x3231722509203233,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x7475706d6f433331,0x695550475f484665,0x535f535f53665069\n"
".quad 0x0a3b5d7a5f5f535f,0x3233752e64646109,0x202c333172250920,0x7225202c32317225\n"
".quad 0x672e646c090a3b37,0x33662e6c61626f6c,0x202c336625092032,0x5d302b333172255b\n"
".quad 0x09636f6c2e090a3b,0x090a300933380933,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3431,0x5f6d726170616475,0x706d6f4333315a5f,0x50475f4846657475\n"
".quad 0x535f536650696955,0x756f5f5f535f535f,0x6461090a3b5d5274,0x2509203233752e64\n"
".quad 0x317225202c353172,0x0a3b377225202c34,0x626f6c672e646c09,0x09203233662e6c61\n"
".quad 0x72255b202c346625,0x090a3b5d302b3531,0x38093309636f6c2e,0x2e646c090a300934\n"
".quad 0x33752e6d61726170,0x2c36317225092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4333,0x69695550475f4846,0x5f535f535f536650,0x5d4974756f5f5f53\n"
".quad 0x752e646461090a3b,0x3731722509203233,0x202c36317225202c,0x646c090a3b377225\n"
".quad 0x2e6c61626f6c672e,0x3566250920323366,0x2b373172255b202c,0x2e646c090a3b5d30\n"
".quad 0x33732e6d61726170,0x2c38317225092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x657475706d6f4333,0x69695550475f4846,0x5f535f535f536650,0x5d4b6d756e5f5f53\n"
".quad 0x732e627573090a3b,0x3931722509203233,0x202c38317225202c,0x6f6d090a3b317225\n"
".quad 0x2509203233752e76,0x313135202c303272,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x317225202c317025,0x3b30327225202c39,0x622031702540090a,0x5f744c2409206172\n"
".quad 0x3037333232315f31,0x09636f6c2e090a3b,0x090a300931390933,0x203233732e726873\n"
".quad 0x25202c3132722509,0x3b3133202c393172,0x33732e766f6d090a,0x2c32327225092032\n"
".quad 0x646e61090a3b3320,0x722509203233622e,0x31327225202c3332,0x0a3b32327225202c\n"
".quad 0x3233732e64646109,0x202c343272250920,0x7225202c33327225,0x726873090a3b3931\n"
".quad 0x722509203233732e,0x34327225202c3532,0x756d090a3b32202c,0x3233732e6f6c2e6c\n"
".quad 0x202c363272250920,0x3b34202c35327225,0x33732e627573090a,0x2c37327225092032\n"
".quad 0x25202c3931722520,0x6f6d090a3b363272,0x2509203233752e76,0x0a3b30202c383272\n"
".quad 0x656c2e7074657309,0x702509203233732e,0x2c37327225202c32,0x090a3b3832722520\n"
".quad 0x6172622032702540,0x5f315f744c240920,0x0a3b363439383731,0x65672e7074657309\n"
".quad 0x702509203233732e,0x202c317225202c33,0x40090a3b38317225,0x2061726220337025\n"
".quad 0x315f315f744c2409,0x090a3b3230323937,0x203233732e766f6d,0x30202c3932722509\n"
".quad 0x752e766f6d090a3b,0x3033722509203233,0x616475635f5f202c,0x69706f32695f7472\n"
".quad 0x766f6d090a3b665f,0x722509203233752e,0x090a3b63202c3133,0x203233752e766f6d\n"
".quad 0x5f202c3233722509,0x5f5f5f616475635f,0x7365725f61647563,0x303136315f746c75\n"
".quad 0x6f6d090a3b363932,0x2509203233752e76,0x635f5f202c333372,0x75635f5f5f616475\n"
".quad 0x6c757365725f6164,0x3233303134345f74,0x5f315f4c240a3b34,0x0a3a363630303231\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x2e090a3230373120\n"
".quad 0x3109383109636f6c,0x6d090a3009323037,0x33752e6f6c2e6c75,0x2c34337225092032\n"
".quad 0x32202c3932722520,0x2e646461090a3b30,0x3372250920323375,0x2c34337225202c35\n"
".quad 0x090a3b3133722520,0x74736e6f632e646c,0x662509203233662e,0x353372255b202c36\n"
".quad 0x646c090a3b5d342b,0x662e74736e6f632e,0x2c37662509203233,0x302b353372255b20\n"
".quad 0x632e646c090a3b5d,0x3233662e74736e6f,0x5b202c3866250920,0x3b5d382b35337225\n"
".quad 0x33662e6c756d090a,0x202c396625092032,0x326625202c366625,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x376625202c303166,0x25202c316625202c,0x616d66090a3b3966\n"
".quad 0x203233662e6e722e,0x25202c3131662509,0x2c336625202c3866,0x090a3b3031662520\n"
".quad 0x2e3436662e747663,0x6466250920323366,0x3b31316625202c31,0x36662e766f6d090a\n"
".quad 0x2c32646625092034,0x3239313034643020,0x3234343435626631,0x202f2f093b383164\n"
".quad 0x0a39313338322e36,0x3436662e6c756d09,0x202c336466250920,0x6625202c31646625\n"
".quad 0x736261090a3b3264,0x662509203436662e,0x33646625202c3464,0x722e747663090a3b\n"
".quad 0x36662e3233662e6e,0x2c32316625092034,0x090a3b3364662520,0x662e6e722e747663\n"
".quad 0x09203436662e3233,0x6625202c33316625,0x766f6d090a3b3464,0x662509203233662e\n"
".quad 0x66376630202c3431,0x203b303030303038,0x28202f2f09202020,0x282f2946302e3128\n"
".quad 0x090a292946302e30,0x2e71652e70746573,0x3470250920323366,0x202c33316625202c\n"
".quad 0x40090a3b34316625,0x6172622034702521,0x5f315f744c240920,0x0a3b363236323231\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3636303032315f\n"
".quad 0x383109636f6c2e09,0x0a30093330373109,0x3233662e67656e09,0x202c353166250920\n"
".quad 0x61090a3b32316625,0x33662e6e722e6464,0x2c36316625092032,0x25202c3231662520\n"
".quad 0x7262090a3b353166,0x240920696e752e61,0x5f69646e6557444c,0x66666e6973695f5f\n"
".quad 0x3b37335f3837315f,0x315f315f744c240a,0x200a3a3632363232,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a363630303231,0x203233662e766f6d\n"
".quad 0x30202c3731662509,0x3037616233373466,0x2f09202020203b30,0x0a3933303834202f\n"
".quad 0x74672e7074657309,0x702509203233662e,0x2c33316625202c35,0x090a3b3731662520\n"
".quad 0x7262203570252140,0x315f744c24092061,0x3b3833313332315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3636303032315f31,0x3109636f6c2e090a\n"
".quad 0x3009363933310938,0x33622e766f6d090a,0x2c36337225092032,0x090a3b3231662520\n"
".quad 0x203233622e646e61,0x25202c3733722509,0x31322d202c363372,0x3834363338343734\n"
".quad 0x732e766f6d090a3b,0x3833722509203233,0x0a3b37337225202c,0x383109636f6c2e09\n"
".quad 0x0a30093230343109,0x3233622e6c687309,0x202c393372250920,0x3b31202c36337225\n"
".quad 0x33752e726873090a,0x2c30347225092032,0x32202c3933722520,0x2e627573090a3b34\n"
".quad 0x3472250920323375,0x2c30347225202c31,0x2e090a3b38323120,0x3209383109636f6c\n"
".quad 0x766f6d090a300934,0x722509203233732e,0x30337225202c3234,0x752e646461090a3b\n"
".quad 0x3334722509203233,0x202c30337225202c,0x766f6d090a3b3432,0x722509203233752e\n"
".quad 0x75635f5f202c3434,0x6475635f5f5f6164,0x746c757365725f61,0x343233303134345f\n"
".quad 0x622e6c6873090a3b,0x3534722509203233,0x202c36337225202c,0x622e726f090a3b38\n"
".quad 0x3634722509203233,0x202c35347225202c,0x333834373431322d,0x6f6d090a3b383436\n"
".quad 0x2509203233752e76,0x0a3b30202c373472,0x32315f315f744c24,0x2e090a3a32363134\n"
".quad 0x2220616d67617270,0x6c6c6f726e756f6e,0x6c3c2f2f200a3b22,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x202c343220656e69,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x746172657469202c,0x0a36203a736e6f69,0x383109636f6c2e09,0x0a30093031343109\n"
".quad 0x736e6f632e646c09,0x2509203233752e74,0x72255b202c383472,0x090a3b5d302b3234\n"
".quad 0x752e6f6c2e6c756d,0x3934722509203233,0x202c38347225202c,0x61090a3b36347225\n"
".quad 0x09203233752e6464,0x7225202c30357225,0x37347225202c3934,0x09636f6c2e090a3b\n"
".quad 0x0931313431093831,0x672e746573090a30,0x33752e3233752e74,0x2c31357225092032\n"
".quad 0x25202c3934722520,0x656e090a3b303572,0x2509203233732e67,0x357225202c323572\n"
".quad 0x2e6c756d090a3b31,0x09203233752e6968,0x7225202c33357225,0x36347225202c3834\n"
".quad 0x752e646461090a3b,0x3734722509203233,0x202c32357225202c,0x2e090a3b33357225\n"
".quad 0x3109383109636f6c,0x73090a3009323134,0x2e6c61636f6c2e74,0x72255b0920323375\n"
".quad 0x25202c5d302b3434,0x6461090a3b303572,0x2509203233752e64,0x347225202c343472\n"
".quad 0x61090a3b34202c34,0x09203233752e6464,0x7225202c32347225,0x090a3b34202c3234\n"
".quad 0x2e656e2e70746573,0x3670250920323375,0x202c32347225202c,0x40090a3b33347225\n"
".quad 0x2061726220367025,0x315f315f744c2409,0x200a3b3236313432,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a363630303231,0x09383109636f6c2e\n"
".quad 0x090a300934313431,0x6c61636f6c2e7473,0x5f5b09203233752e,0x5f5f5f616475635f\n"
".quad 0x7365725f61647563,0x303134345f746c75,0x2c5d34322b343233,0x090a3b3734722520\n"
".quad 0x09383109636f6c2e,0x090a300939313431,0x203233752e726873,0x25202c3435722509\n"
".quad 0x0a3b35202c313472,0x2e6f6c2e6c756d09,0x3572250920323375,0x2c34357225202c35\n"
".quad 0x627573090a3b3420,0x722509203233752e,0x33337225202c3635,0x0a3b35357225202c\n"
".quad 0x61636f6c2e646c09,0x2509203233752e6c,0x72255b202c373472,0x0a3b5d34322b3635\n"
".quad 0x383109636f6c2e09,0x0a30093032343109,0x61636f6c2e646c09,0x2509203233752e6c\n"
".quad 0x72255b202c373572,0x0a3b5d30322b3635,0x3233622e646e6109,0x202c383572250920\n"
".quad 0x3133202c31347225,0x752e766f6d090a3b,0x3935722509203233,0x6573090a3b30202c\n"
".quad 0x33752e71652e7074,0x202c377025092032,0x7225202c38357225,0x702540090a3b3935\n"
".quad 0x2409206172622037,0x3432315f315f744c,0x2f2f200a3b343736,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a36363030,0x343109383109636f\n"
".quad 0x6f6d090a30093332,0x2509203233732e76,0x3b3233202c303672,0x33732e627573090a\n"
".quad 0x2c31367225092032,0x25202c3036722520,0x6873090a3b383572,0x2509203233752e72\n"
".quad 0x357225202c323672,0x3b31367225202c37,0x33622e6c6873090a,0x2c33367225092032\n"
".quad 0x25202c3734722520,0x6461090a3b383572,0x2509203233752e64,0x367225202c373472\n"
".quad 0x3b33367225202c32,0x3109636f6c2e090a,0x3009343234310938,0x636f6c2e646c090a\n"
".quad 0x09203233752e6c61,0x255b202c34367225,0x3b5d36312b363572,0x33752e726873090a\n"
".quad 0x2c35367225092032,0x25202c3436722520,0x6873090a3b313672,0x2509203233622e6c\n"
".quad 0x357225202c363672,0x3b38357225202c37,0x33752e646461090a,0x2c37357225092032\n"
".quad 0x25202c3536722520,0x744c240a3b363672,0x37363432315f315f,0x6c3c2f2f200a3a34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303032315f315f4c,0x636f6c2e090a3636\n"
".quad 0x3632343109383109,0x2e726873090a3009,0x3672250920323375,0x2c37347225202c37\n"
".quad 0x6c2e090a3b303320,0x343109383109636f,0x6873090a30093832,0x2509203233752e72\n"
".quad 0x357225202c383672,0x090a3b3033202c37,0x203233622e6c6873,0x25202c3936722509\n"
".quad 0x0a3b32202c373472,0x3233752e64646109,0x202c373472250920,0x7225202c38367225\n"
".quad 0x6f6c2e090a3b3936,0x3234310938310963,0x6c6873090a300939,0x722509203233622e\n"
".quad 0x37357225202c3735,0x6f6d090a3b32202c,0x2509203233752e76,0x0a3b30202c303772\n"
".quad 0x71652e7074657309,0x702509203233752e,0x2c37357225202c38,0x090a3b3037722520\n"
".quad 0x6172622038702540,0x5f315f744c240920,0x0a3b323434353231,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3636303032315f,0x383109636f6c2e09\n"
".quad 0x0a30093033343109,0x3233752e64646109,0x202c313772250920,0x3b31202c37347225\n"
".quad 0x33752e766f6d090a,0x2c32377225092032,0x3834373431322d20,0x73090a3b38343633\n"
".quad 0x33752e74672e7465,0x2509203233752e32,0x377225202c333772,0x3b32377225202c31\n"
".quad 0x33732e67656e090a,0x2c34377225092032,0x090a3b3337722520,0x20696e752e617262\n"
".quad 0x315f315f744c2409,0x240a3b3638313532,0x3532315f315f744c,0x2f2f200a3a323434\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6f6d090a36363030\n"
".quad 0x2509203233752e76,0x31322d202c353772,0x3834363338343734,0x672e746573090a3b\n"
".quad 0x33752e3233752e74,0x2c36377225092032,0x25202c3734722520,0x656e090a3b353772\n"
".quad 0x2509203233732e67,0x377225202c343772,0x315f744c240a3b36,0x3a3638313532315f\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65,0x3636303032315f31\n"
".quad 0x3109636f6c2e090a,0x3009313334310938,0x33752e646461090a,0x2c37377225092032\n"
".quad 0x25202c3736722520,0x6c2e090a3b343772,0x343109383109636f,0x656e090a30093033\n"
".quad 0x2509203233732e67,0x377225202c383772,0x2e766f6d090a3b37,0x3772250920323375\n"
".quad 0x73090a3b30202c39,0x752e656e2e707465,0x2c39702509203233,0x25202c3733722520\n"
".quad 0x6573090a3b393772,0x09203233732e706c,0x7225202c37367225,0x37377225202c3837\n"
".quad 0x090a3b397025202c,0x203233752e766f6d,0x30202c3038722509,0x2e70746573090a3b\n"
".quad 0x09203233752e7165,0x7225202c30317025,0x30387225202c3437,0x3031702540090a3b\n"
".quad 0x4c24092061726220,0x363532315f315f74,0x3c2f2f200a3b3839,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3032315f315f4c24,0x6f6c2e090a363630,0x3334310938310963\n"
".quad 0x67656e090a300936,0x722509203233732e,0x37357225202c3735,0x09636f6c2e090a3b\n"
".quad 0x0938333431093831,0x752e766f6d090a30,0x3138722509203233,0x6573090a3b30202c\n"
".quad 0x3233752e71652e74,0x722509203233752e,0x37357225202c3238,0x0a3b31387225202c\n"
".quad 0x3233732e67656e09,0x202c333872250920,0x6e090a3b32387225,0x09203233622e746f\n"
".quad 0x7225202c34387225,0x646461090a3b3734,0x722509203233752e,0x33387225202c3734\n"
".quad 0x0a3b34387225202c,0x383109636f6c2e09,0x0a30093933343109,0x3233622e726f7809\n"
".quad 0x202c383372250920,0x322d202c37337225,0x3436333834373431,0x315f744c240a3b38\n"
".quad 0x3a3839363532315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3636303032315f31,0x3109636f6c2e090a,0x3009313434310938,0x33732e766f6d090a\n"
".quad 0x2c35387225092032,0x090a3b3736722520,0x203233752e766f6d,0x30202c3638722509\n"
".quad 0x2e70746573090a3b,0x09203233732e656c,0x7225202c31317025,0x36387225202c3734\n"
".quad 0x3131702540090a3b,0x4c24092061726220,0x343937315f315f74,0x3c2f2f200a3b3835\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24,0x766f6d090a363630\n"
".quad 0x722509203233752e,0x240a3b30202c3738,0x3632315f315f744c,0x2f2f200a3a323237\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x343120656e696c20,0x7473656e202c3134\n"
".quad 0x7470656420676e69,0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469\n"
".quad 0x6e6b6e75203a736e,0x6f6c2e090a6e776f,0x3434310938310963,0x726873090a300935\n"
".quad 0x722509203233752e,0x37357225202c3838,0x73090a3b3133202c,0x09203233622e6c68\n"
".quad 0x7225202c39387225,0x090a3b31202c3734,0x203233752e646461,0x25202c3734722509\n"
".quad 0x387225202c383872,0x636f6c2e090a3b39,0x3634343109383109,0x2e6c6873090a3009\n"
".quad 0x3572250920323362,0x2c37357225202c37,0x6f6c2e090a3b3120,0x3434310938310963\n"
".quad 0x627573090a300937,0x722509203233752e,0x37387225202c3738,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x0a3b30202c303972,0x74672e7074657309,0x702509203233732e\n"
".quad 0x37347225202c3231,0x0a3b30397225202c,0x6220323170254009,0x5f744c2409206172\n"
".quad 0x3232373632315f31,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x36303032315f315f,0x752e617262090a36,0x5f744c240920696e,0x3031323632315f31\n"
".quad 0x5f315f744c240a3b,0x0a3a383534393731,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3636303032315f,0x3233752e766f6d09,0x202c373872250920\n"
".quad 0x315f744c240a3b30,0x3a3031323632315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3636303032315f31,0x3109636f6c2e090a,0x3009393434310938\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x37347225202c3735,0x30373132392d202c\n"
".quad 0x2e090a3b30373837,0x3109383109636f6c,0x6d090a3009303534,0x09203233752e766f\n"
".quad 0x392d202c31397225,0x3037383730373132,0x682e6c756d090a3b,0x2509203233752e69\n"
".quad 0x347225202c373472,0x3b31397225202c37,0x33752e766f6d090a,0x2c32397225092032\n"
".quad 0x746573090a3b3020,0x3233732e656c2e70,0x202c333170250920,0x7225202c37347225\n"
".quad 0x702540090a3b3239,0x0920617262203331,0x32315f315f744c24,0x2f200a3b34333237\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064,0x2e090a3636303032\n"
".quad 0x3109383109636f6c,0x73090a3009323534,0x09203233752e7268,0x7225202c33397225\n"
".quad 0x0a3b3133202c3735,0x3233622e6c687309,0x202c343972250920,0x3b31202c37347225\n"
".quad 0x33752e646461090a,0x2c37347225092032,0x25202c3339722520,0x6c2e090a3b343972\n"
".quad 0x343109383109636f,0x6873090a30093335,0x2509203233622e6c,0x357225202c373572\n"
".quad 0x2e090a3b31202c37,0x3109383109636f6c,0x73090a3009343534,0x09203233752e6275\n"
".quad 0x7225202c37387225,0x240a3b31202c3738,0x3732315f315f744c,0x2f2f200a3a343332\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a36363030\n"
".quad 0x343109383109636f,0x6f6d090a30093635,0x2509203233752e76,0x0a3b30202c353972\n"
".quad 0x2e656e2e74657309,0x203233752e323375,0x25202c3639722509,0x397225202c373572\n"
".quad 0x2e67656e090a3b35,0x3972250920323373,0x3b36397225202c37,0x33752e646461090a\n"
".quad 0x2c37347225092032,0x25202c3739722520,0x6c2e090a3b373472,0x343109383109636f\n"
".quad 0x6873090a30093835,0x2509203233622e6c,0x347225202c383972,0x090a3b3432202c37\n"
".quad 0x203233732e766f6d,0x30202c3939722509,0x6c2e746573090a3b,0x33732e3233752e74\n"
".quad 0x3030317225092032,0x202c38397225202c,0x6e090a3b39397225,0x09203233732e6765\n"
".quad 0x25202c3130317225,0x73090a3b30303172,0x09203233752e7268,0x25202c3230317225\n"
".quad 0x0a3b38202c373472,0x3233752e64646109,0x2c33303172250920,0x31202c3738722520\n"
".quad 0x6c6873090a3b3632,0x722509203233622e,0x317225202c343031,0x0a3b3332202c3330\n"
".quad 0x3233752e64646109,0x2c35303172250920,0x202c323031722520,0x090a3b3430317225\n"
".quad 0x203233752e646461,0x202c363031722509,0x25202c3130317225,0x6f090a3b35303172\n"
".quad 0x2509203233622e72,0x7225202c37303172,0x30317225202c3833,0x2e766f6d090a3b36\n"
".quad 0x3166250920323362,0x3730317225202c38,0x752e617262090a3b,0x57444c240920696e\n"
".quad 0x695f5f5f69646e65,0x5f6c616e7265746e,0x3837315f64616d66,0x744c240a3b38335f\n"
".quad 0x33313332315f315f,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303032315f315f4c,0x636f6c2e090a3636,0x3036343109383109,0x2e766f6d090a3009\n"
".quad 0x3166250920323366,0x3266336630202c39,0x20203b3338396632,0x2e30202f2f092020\n"
".quad 0x6d090a3236363336,0x09203233662e6c75,0x6625202c30326625,0x39316625202c3231\n"
".quad 0x722e747663090a3b,0x662e3233732e696e,0x3031722509203233,0x3b30326625202c38\n"
".quad 0x3109636f6c2e090a,0x3009353634310938,0x6e722e747663090a,0x3233732e3233662e\n"
".quad 0x202c313266250920,0x090a3b3830317225,0x203233662e67656e,0x25202c3232662509\n"
".quad 0x6f6d090a3b313266,0x2509203233662e76,0x336630202c333266,0x3b30326161646639\n"
".quad 0x202f2f0920202020,0x3338343030302e30,0x766f6d090a373238,0x662509203233662e\n"
".quad 0x66336630202c3432,0x203b303030303963,0x31202f2f09202020,0x090a31333037352e\n"
".quad 0x662e6e722e616d66,0x3532662509203233,0x202c32326625202c,0x6625202c34326625\n"
".quad 0x616d66090a3b3231,0x203233662e6e722e,0x25202c3632662509,0x326625202c323266\n"
".quad 0x3b35326625202c33,0x3109636f6c2e090a,0x3009313734310938,0x33732e766f6d090a\n"
".quad 0x2c35387225092032,0x0a3b383031722520,0x383109636f6c2e09,0x0a30093237343109\n"
".quad 0x3233662e766f6d09,0x202c373266250920,0x3361353865326630,0x09202020203b3930\n"
".quad 0x3737302e36202f2f,0x66090a31312d6531,0x33662e6e722e616d,0x2c38316625092032\n"
".quad 0x25202c3232662520,0x326625202c373266,0x6557444c240a3b36,0x6e695f5f5f69646e\n"
".quad 0x665f6c616e726574,0x5f3837315f64616d,0x3c2f2f200a3a3833,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3032315f315f4c24,0x6f6c2e090a363630,0x3037310938310963\n"
".quad 0x646461090a300935,0x722509203233732e,0x387225202c393031,0x6d090a3b31202c35\n"
".quad 0x09203233662e766f,0x6625202c38326625,0x6c756d090a3b3831,0x662509203233662e\n"
".quad 0x38326625202c3932,0x0a3b38326625202c,0x3233622e646e6109,0x2c30313172250920\n"
".quad 0x202c393031722520,0x2e766f6d090a3b31,0x3172250920323375,0x090a3b30202c3131\n"
".quad 0x2e71652e70746573,0x3170250920323373,0x3031317225202c34,0x3b3131317225202c\n"
".quad 0x203431702540090a,0x744c240920617262,0x30303832315f315f,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303032315f315f4c,0x636f6c2e090a3636\n"
".quad 0x3930373109383109,0x2e766f6d090a3009,0x3366250920323366,0x6337336630202c30\n"
".quad 0x20203b6563356663,0x2e32202f2f092020,0x302d653233333434,0x662e766f6d090a35\n"
".quad 0x3133662509203233,0x366261626630202c,0x2020203b61313630,0x2e302d202f2f0920\n"
".quad 0x3337383833313030,0x6e722e616d66090a,0x662509203233662e,0x30336625202c3233\n"
".quad 0x202c39326625202c,0x6d090a3b31336625,0x09203233662e766f,0x6630202c33336625\n"
".quad 0x3561616161326433,0x2f2f09202020203b,0x36363134302e3020,0x2e616d66090a3636\n"
".quad 0x09203233662e6e72,0x6625202c34336625,0x39326625202c3233,0x0a3b33336625202c\n"
".quad 0x3233662e766f6d09,0x202c353366250920,0x3030303066626630,0x09202020203b3030\n"
".quad 0x0a352e302d202f2f,0x2e6e722e616d6609,0x3366250920323366,0x2c34336625202c36\n"
".quad 0x25202c3932662520,0x6f6d090a3b353366,0x2509203233662e76,0x336630202c373366\n"
".quad 0x3b30303030303866,0x202f2f0920202020,0x722e616d66090a31,0x2509203233662e6e\n"
".quad 0x336625202c383366,0x2c39326625202c36,0x090a3b3733662520,0x20696e752e617262\n"
".quad 0x315f315f744c2409,0x240a3b3634373732,0x3832315f315f744c,0x2f2f200a3a323030\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a36363030\n"
".quad 0x373109383109636f,0x6f6d090a30093131,0x2509203233662e76,0x626630202c393366\n"
".quad 0x3b39663161633439,0x202f2f0920202020,0x39313030302e302d,0x6f6d090a33353135\n"
".quad 0x2509203233662e76,0x336630202c303466,0x3b65393338383063,0x202f2f0920202020\n"
".quad 0x3233333830302e30,0x2e616d66090a3631,0x09203233662e6e72,0x6625202c31346625\n"
".quad 0x39326625202c3933,0x0a3b30346625202c,0x3233662e766f6d09,0x202c323466250920\n"
".quad 0x6161613265626630,0x09202020203b3361,0x36312e302d202f2f,0x6d66090a37363636\n"
".quad 0x3233662e6e722e61,0x202c333466250920,0x6625202c31346625,0x32346625202c3932\n"
".quad 0x662e6c756d090a3b,0x3434662509203233,0x202c39326625202c,0x66090a3b33346625\n"
".quad 0x33662e6e722e616d,0x2c38336625092032,0x25202c3434662520,0x326625202c383266\n"
".quad 0x315f744c240a3b38,0x3a3634373732315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3636303032315f31,0x3109636f6c2e090a,0x3009333137310938\n"
".quad 0x33662e67656e090a,0x2c35346625092032,0x090a3b3833662520,0x203233622e646e61\n"
".quad 0x202c323131722509,0x32202c3930317225,0x732e766f6d090a3b,0x3131722509203233\n"
".quad 0x73090a3b30202c33,0x732e656e2e707465,0x3531702509203233,0x2c3231317225202c\n"
".quad 0x0a3b333131722520,0x33662e706c657309,0x2c38336625092032,0x25202c3534662520\n"
".quad 0x317025202c383366,0x636f6c2e090a3b35,0x3631373109383109,0x2e766f6d090a3009\n"
".quad 0x3166250920323366,0x3b38336625202c36,0x646e6557444c240a,0x6e6973695f5f5f69\n"
".quad 0x335f3837315f6666,0x6c3c2f2f200a3a37,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303032315f315f4c,0x636f6c2e090a3636,0x3833363109383109,0x706c6573090a3009\n"
".quad 0x722509203233732e,0x202c31202c343131,0x0a3b347025202c30,0x3233662e766f6d09\n"
".quad 0x202c363466250920,0x3030303030306630,0x09202020203b3030,0x6573090a30202f2f\n"
".quad 0x3233752e71652e74,0x722509203233662e,0x316625202c353131,0x3b36346625202c32\n"
".quad 0x33732e67656e090a,0x3631317225092032,0x3b3531317225202c,0x3233622e726f090a\n"
".quad 0x2c37313172250920,0x202c343131722520,0x090a3b3631317225,0x203233752e766f6d\n"
".quad 0x202c383131722509,0x70746573090a3b30,0x203233732e71652e,0x25202c3631702509\n"
".quad 0x7225202c37313172,0x2540090a3b383131,0x2061726220363170,0x315f315f744c2409\n"
".quad 0x200a3b3835323832,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a363630303231,0x09383109636f6c2e,0x090a300939333631,0x203233662e766f6d\n"
".quad 0x30202c3734662509,0x3030303030303066,0x2f09202020203b30,0x6c756d090a30202f\n"
".quad 0x203233662e6e722e,0x25202c3834662509,0x346625202c323166,0x2e617262090a3b37\n"
".quad 0x444c240920696e75,0x5f5f5f69646e6557,0x315f66666e697369,0x240a3b33335f3837\n"
".quad 0x3832315f315f744c,0x2f2f200a3a383532,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6f6d090a36363030,0x2509203233662e76,0x346630202c393466\n"
".quad 0x3b30303761623337,0x202f2f0920202020,0x73090a3933303834,0x662e74672e707465\n"
".quad 0x3731702509203233,0x202c33316625202c,0x40090a3b39346625,0x7262203731702521\n"
".quad 0x315f744c24092061,0x3b3037373832315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3636303032315f31,0x3109636f6c2e090a,0x3009363933310938\n"
".quad 0x33622e766f6d090a,0x3931317225092032,0x0a3b32316625202c,0x3233622e646e6109\n"
".quad 0x202c373372250920,0x2d202c3931317225,0x3633383437343132,0x766f6d090a3b3834\n"
".quad 0x722509203233732e,0x337225202c303231,0x636f6c2e090a3b37,0x3230343109383109\n"
".quad 0x2e6c6873090a3009,0x3172250920323362,0x31317225202c3132,0x73090a3b31202c39\n"
".quad 0x09203233752e7268,0x25202c3232317225,0x3432202c31323172,0x752e627573090a3b\n"
".quad 0x3134722509203233,0x2c3232317225202c,0x2e090a3b38323120,0x3209383109636f6c\n"
".quad 0x766f6d090a300934,0x722509203233732e,0x337225202c333231,0x2e646461090a3b30\n"
".quad 0x3472250920323375,0x2c30337225202c33,0x6f6d090a3b343220,0x2509203233752e76\n"
".quad 0x5f5f202c34323172,0x635f5f5f61647563,0x757365725f616475,0x32303136315f746c\n"
".quad 0x6c6873090a3b3639,0x722509203233622e,0x317225202c353231,0x090a3b38202c3931\n"
".quad 0x09203233622e726f,0x7225202c36347225,0x31322d202c353231,0x3834363338343734\n"
".quad 0x752e766f6d090a3b,0x3231722509203233,0x4c240a3b30202c36,0x373932315f315f74\n"
".quad 0x72702e090a3a3439,0x6f6e2220616d6761,0x3b226c6c6f726e75,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x656e202c34322065,0x656420676e697473\n"
".quad 0x202c31203a687470,0x6f69746172657469,0x2e090a36203a736e,0x3109383109636f6c\n"
".quad 0x6c090a3009303134,0x2e74736e6f632e64,0x3172250920323375,0x3172255b202c3732\n"
".quad 0x090a3b5d302b3332,0x752e6f6c2e6c756d,0x3231722509203233,0x3732317225202c38\n"
".quad 0x0a3b36347225202c,0x3233752e64646109,0x2c39323172250920,0x202c383231722520\n"
".quad 0x090a3b3632317225,0x09383109636f6c2e,0x090a300931313431,0x752e74672e746573\n"
".quad 0x09203233752e3233,0x25202c3033317225,0x7225202c38323172,0x656e090a3b393231\n"
".quad 0x2509203233732e67,0x7225202c31333172,0x756d090a3b303331,0x3233752e69682e6c\n"
".quad 0x2c32333172250920,0x202c373231722520,0x61090a3b36347225,0x09203233752e6464\n"
".quad 0x25202c3632317225,0x7225202c31333172,0x6c2e090a3b323331,0x343109383109636f\n"
".quad 0x7473090a30093231,0x752e6c61636f6c2e,0x3172255b09203233,0x25202c5d302b3432\n"
".quad 0x61090a3b39323172,0x09203233752e6464,0x25202c3432317225,0x3b34202c34323172\n"
".quad 0x33752e646461090a,0x3332317225092032,0x2c3332317225202c,0x746573090a3b3420\n"
".quad 0x3233752e656e2e70,0x202c383170250920,0x25202c3332317225,0x2540090a3b333472\n"
".quad 0x2061726220383170,0x315f315f744c2409,0x200a3b3439373932,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a363630303231,0x09383109636f6c2e\n"
".quad 0x090a300934313431,0x6c61636f6c2e7473,0x5f5b09203233752e,0x5f5f5f616475635f\n"
".quad 0x7365725f61647563,0x303136315f746c75,0x2c5d34322b363932,0x0a3b363231722520\n"
".quad 0x383109636f6c2e09,0x0a30093931343109,0x3233752e72687309,0x2c33333172250920\n"
".quad 0x35202c3134722520,0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c34333172\n"
".quad 0x0a3b34202c333331,0x3233752e62757309,0x2c35333172250920,0x25202c3233722520\n"
".quad 0x6c090a3b34333172,0x2e6c61636f6c2e64,0x3172250920323375,0x3172255b202c3632\n"
".quad 0x0a3b5d34322b3533,0x383109636f6c2e09,0x0a30093032343109,0x61636f6c2e646c09\n"
".quad 0x2509203233752e6c,0x255b202c36333172,0x5d30322b35333172,0x622e646e61090a3b\n"
".quad 0x3835722509203233,0x202c31347225202c,0x766f6d090a3b3133,0x722509203233752e\n"
".quad 0x0a3b30202c373331,0x71652e7074657309,0x702509203233752e,0x38357225202c3931\n"
".quad 0x3b3733317225202c,0x203931702540090a,0x744c240920617262,0x30333033315f315f\n"
".quad 0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303032315f315f4c\n"
".quad 0x636f6c2e090a3636,0x3332343109383109,0x2e766f6d090a3009,0x3172250920323373\n"
".quad 0x0a3b3233202c3833,0x3233732e62757309,0x2c39333172250920,0x202c383331722520\n"
".quad 0x73090a3b38357225,0x09203233752e7268,0x25202c3034317225,0x7225202c36333172\n"
".quad 0x6873090a3b393331,0x2509203233622e6c,0x7225202c31343172,0x357225202c363231\n"
".quad 0x2e646461090a3b38,0x3172250920323375,0x34317225202c3632,0x3134317225202c30\n"
".quad 0x09636f6c2e090a3b,0x0934323431093831,0x6f6c2e646c090a30,0x203233752e6c6163\n"
".quad 0x202c323431722509,0x312b35333172255b,0x726873090a3b5d36,0x722509203233752e\n"
".quad 0x317225202c333431,0x33317225202c3234,0x2e6c6873090a3b39,0x3172250920323362\n"
".quad 0x33317225202c3434,0x3b38357225202c36,0x33752e646461090a,0x3633317225092032\n"
".quad 0x2c3334317225202c,0x0a3b343431722520,0x33315f315f744c24,0x2f200a3a36303330\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064,0x2e090a3636303032\n"
".quad 0x3109383109636f6c,0x73090a3009363234,0x09203233752e7268,0x25202c3534317225\n"
".quad 0x3033202c36323172,0x09636f6c2e090a3b,0x0938323431093831,0x752e726873090a30\n"
".quad 0x3431722509203233,0x3633317225202c36,0x73090a3b3033202c,0x09203233622e6c68\n"
".quad 0x25202c3734317225,0x3b32202c36323172,0x33752e646461090a,0x3632317225092032\n"
".quad 0x2c3634317225202c,0x0a3b373431722520,0x383109636f6c2e09,0x0a30093932343109\n"
".quad 0x3233622e6c687309,0x2c36333172250920,0x202c363331722520,0x2e766f6d090a3b32\n"
".quad 0x3172250920323375,0x090a3b30202c3834,0x2e71652e70746573,0x3270250920323375\n"
".quad 0x3633317225202c30,0x3b3834317225202c,0x203032702540090a,0x744c240920617262\n"
".quad 0x37303133315f315f,0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303032315f315f4c,0x636f6c2e090a3636,0x3033343109383109,0x2e646461090a3009\n"
".quad 0x3172250920323375,0x32317225202c3934,0x6d090a3b31202c36,0x09203233752e766f\n"
".quad 0x2d202c3035317225,0x3633383437343132,0x746573090a3b3834,0x2e3233752e74672e\n"
".quad 0x3172250920323375,0x34317225202c3135,0x3035317225202c39,0x732e67656e090a3b\n"
".quad 0x3531722509203233,0x3135317225202c32,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3831383033315f31,0x5f315f744c240a3b,0x0a3a343730313331,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3636303032315f,0x3233752e766f6d09\n"
".quad 0x2c33353172250920,0x3834373431322d20,0x73090a3b38343633,0x33752e74672e7465\n"
".quad 0x2509203233752e32,0x7225202c34353172,0x317225202c363231,0x67656e090a3b3335\n"
".quad 0x722509203233732e,0x317225202c323531,0x5f744c240a3b3435,0x3831383033315f31\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x36303032315f315f\n"
".quad 0x09636f6c2e090a36,0x0931333431093831,0x752e646461090a30,0x3531722509203233\n"
".quad 0x3534317225202c35,0x3b3235317225202c,0x3109636f6c2e090a,0x3009303334310938\n"
".quad 0x33732e67656e090a,0x3635317225092032,0x3b3535317225202c,0x33752e766f6d090a\n"
".quad 0x3735317225092032,0x6573090a3b30202c,0x33752e656e2e7074,0x2c31327025092032\n"
".quad 0x25202c3733722520,0x73090a3b37353172,0x203233732e706c65,0x202c353431722509\n"
".quad 0x25202c3635317225,0x7025202c35353172,0x766f6d090a3b3132,0x722509203233752e\n"
".quad 0x0a3b30202c383531,0x71652e7074657309,0x702509203233752e,0x35317225202c3232\n"
".quad 0x3835317225202c32,0x3232702540090a3b,0x4c24092061726220,0x333133315f315f74\n"
".quad 0x3c2f2f200a3b3033,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24\n"
".quad 0x6f6c2e090a363630,0x3334310938310963,0x67656e090a300936,0x722509203233732e\n"
".quad 0x317225202c363331,0x6f6c2e090a3b3633,0x3334310938310963,0x766f6d090a300938\n"
".quad 0x722509203233752e,0x0a3b30202c393531,0x2e71652e74657309,0x203233752e323375\n"
".quad 0x202c303631722509,0x25202c3633317225,0x6e090a3b39353172,0x09203233732e6765\n"
".quad 0x25202c3136317225,0x6e090a3b30363172,0x09203233622e746f,0x25202c3236317225\n"
".quad 0x61090a3b36323172,0x09203233752e6464,0x25202c3632317225,0x7225202c31363172\n"
".quad 0x6c2e090a3b323631,0x343109383109636f,0x6f78090a30093933,0x2509203233622e72\n"
".quad 0x7225202c30323172,0x3431322d202c3733,0x3b38343633383437,0x315f315f744c240a\n"
".quad 0x200a3a3033333133,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a363630303231,0x09383109636f6c2e,0x090a300931343431,0x203233732e766f6d\n"
".quad 0x202c333631722509,0x090a3b3534317225,0x203233752e766f6d,0x202c343631722509\n"
".quad 0x70746573090a3b30,0x203233732e656c2e,0x25202c3332702509,0x7225202c36323172\n"
".quad 0x2540090a3b343631,0x2061726220333270,0x315f315f744c2409,0x200a3b3431373937\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a363630303231\n"
".quad 0x203233752e766f6d,0x202c353631722509,0x315f744c240a3b30,0x3a3435333233315f\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x202c313434312065\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x383109636f6c2e09,0x0a30093534343109\n"
".quad 0x3233752e72687309,0x2c36363172250920,0x202c363331722520,0x6c6873090a3b3133\n"
".quad 0x722509203233622e,0x317225202c373631,0x090a3b31202c3632,0x203233752e646461\n"
".quad 0x202c363231722509,0x25202c3636317225,0x2e090a3b37363172,0x3109383109636f6c\n"
".quad 0x73090a3009363434,0x09203233622e6c68,0x25202c3633317225,0x3b31202c36333172\n"
".quad 0x3109636f6c2e090a,0x3009373434310938,0x33752e627573090a,0x3536317225092032\n"
".quad 0x2c3536317225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c383631\n"
".quad 0x74672e7074657309,0x702509203233732e,0x32317225202c3432,0x3836317225202c36\n"
".quad 0x3432702540090a3b,0x4c24092061726220,0x333233315f315f74,0x3c2f2f200a3b3435\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24,0x617262090a363630\n"
".quad 0x4c240920696e752e,0x383133315f315f74,0x5f744c240a3b3234,0x3431373937315f31\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x36303032315f315f\n"
".quad 0x752e766f6d090a36,0x3631722509203233,0x4c240a3b30202c35,0x383133315f315f74\n"
".quad 0x3c2f2f200a3a3234,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24\n"
".quad 0x6f6c2e090a363630,0x3434310938310963,0x6c756d090a300939,0x203233752e6f6c2e\n"
".quad 0x202c363331722509,0x2d202c3632317225,0x3738373037313239,0x636f6c2e090a3b30\n"
".quad 0x3035343109383109,0x2e766f6d090a3009,0x3172250920323375,0x3132392d202c3936\n"
".quad 0x0a3b303738373037,0x2e69682e6c756d09,0x3172250920323375,0x32317225202c3632\n"
".quad 0x3936317225202c36,0x752e766f6d090a3b,0x3731722509203233,0x73090a3b30202c30\n"
".quad 0x732e656c2e707465,0x3532702509203233,0x2c3632317225202c,0x0a3b303731722520\n"
".quad 0x6220353270254009,0x5f744c2409206172,0x3636383233315f31,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x36303032315f315f,0x09636f6c2e090a36\n"
".quad 0x0932353431093831,0x752e726873090a30,0x3731722509203233,0x3633317225202c31\n"
".quad 0x73090a3b3133202c,0x09203233622e6c68,0x25202c3237317225,0x3b31202c36323172\n"
".quad 0x33752e646461090a,0x3632317225092032,0x2c3137317225202c,0x0a3b323731722520\n"
".quad 0x383109636f6c2e09,0x0a30093335343109,0x3233622e6c687309,0x2c36333172250920\n"
".quad 0x202c363331722520,0x636f6c2e090a3b31,0x3435343109383109,0x2e627573090a3009\n"
".quad 0x3172250920323375,0x36317225202c3536,0x4c240a3b31202c35,0x383233315f315f74\n"
".quad 0x3c2f2f200a3a3636,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24\n"
".quad 0x6f6c2e090a363630,0x3534310938310963,0x766f6d090a300936,0x722509203233752e\n"
".quad 0x0a3b30202c333731,0x2e656e2e74657309,0x203233752e323375,0x202c343731722509\n"
".quad 0x25202c3633317225,0x6e090a3b33373172,0x09203233732e6765,0x25202c3537317225\n"
".quad 0x61090a3b34373172,0x09203233752e6464,0x25202c3632317225,0x7225202c35373172\n"
".quad 0x6c2e090a3b363231,0x343109383109636f,0x6873090a30093835,0x2509203233622e6c\n"
".quad 0x7225202c36373172,0x3b3432202c363231,0x33732e766f6d090a,0x3737317225092032\n"
".quad 0x6573090a3b30202c,0x3233752e746c2e74,0x722509203233732e,0x317225202c383731\n"
".quad 0x37317225202c3637,0x2e67656e090a3b37,0x3172250920323373,0x37317225202c3937\n"
".quad 0x2e726873090a3b38,0x3172250920323375,0x32317225202c3038,0x61090a3b38202c36\n"
".quad 0x09203233752e6464,0x25202c3138317225,0x3231202c35363172,0x2e6c6873090a3b36\n"
".quad 0x3172250920323362,0x38317225202c3238,0x090a3b3332202c31,0x203233752e646461\n"
".quad 0x202c333831722509,0x25202c3038317225,0x61090a3b32383172,0x09203233752e6464\n"
".quad 0x25202c3438317225,0x7225202c39373172,0x726f090a3b333831,0x722509203233622e\n"
".quad 0x317225202c353831,0x38317225202c3032,0x2e766f6d090a3b34,0x3566250920323362\n"
".quad 0x3538317225202c30,0x752e617262090a3b,0x57444c240920696e,0x695f5f5f69646e65\n"
".quad 0x5f6c616e7265746e,0x3837315f64616d66,0x744c240a3b34335f,0x37373832315f315f\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303032315f315f4c\n"
".quad 0x636f6c2e090a3636,0x3036343109383109,0x2e766f6d090a3009,0x3566250920323366\n"
".quad 0x3266336630202c31,0x20203b3338396632,0x2e30202f2f092020,0x6d090a3236363336\n"
".quad 0x09203233662e6c75,0x6625202c32356625,0x31356625202c3231,0x722e747663090a3b\n"
".quad 0x662e3233732e696e,0x3831722509203233,0x3b32356625202c36,0x3109636f6c2e090a\n"
".quad 0x3009353634310938,0x6e722e747663090a,0x3233732e3233662e,0x202c333566250920\n"
".quad 0x090a3b3638317225,0x203233662e67656e,0x25202c3435662509,0x6f6d090a3b333566\n"
".quad 0x2509203233662e76,0x336630202c353566,0x3b30326161646639,0x202f2f0920202020\n"
".quad 0x3338343030302e30,0x766f6d090a373238,0x662509203233662e,0x66336630202c3635\n"
".quad 0x203b303030303963,0x31202f2f09202020,0x090a31333037352e,0x662e6e722e616d66\n"
".quad 0x3735662509203233,0x202c34356625202c,0x6625202c36356625,0x616d66090a3b3231\n"
".quad 0x203233662e6e722e,0x25202c3835662509,0x356625202c343566,0x3b37356625202c35\n"
".quad 0x3109636f6c2e090a,0x3009313734310938,0x33732e766f6d090a,0x3336317225092032\n"
".quad 0x3b3638317225202c,0x3109636f6c2e090a,0x3009323734310938,0x33662e766f6d090a\n"
".quad 0x2c39356625092032,0x6135386532663020,0x202020203b393033,0x37302e36202f2f09\n"
".quad 0x090a31312d653137,0x662e6e722e616d66,0x3035662509203233,0x202c34356625202c\n"
".quad 0x6625202c39356625,0x57444c240a3b3835,0x695f5f5f69646e65,0x5f6c616e7265746e\n"
".quad 0x3837315f64616d66,0x2f2f200a3a34335f,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a36363030,0x363109383109636f,0x6f6d090a30093134\n"
".quad 0x2509203233662e76,0x356625202c303666,0x2e6c756d090a3b30,0x3666250920323366\n"
".quad 0x2c30366625202c31,0x090a3b3036662520,0x203233622e646e61,0x202c373831722509\n"
".quad 0x31202c3336317225,0x752e766f6d090a3b,0x3831722509203233,0x73090a3b30202c38\n"
".quad 0x732e71652e707465,0x3632702509203233,0x2c3738317225202c,0x0a3b383831722520\n"
".quad 0x6220363270254009,0x5f744c2409206172,0x3433363333315f31,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x36303032315f315f,0x09636f6c2e090a36\n"
".quad 0x0934343631093831,0x662e766f6d090a30,0x3236662509203233,0x636337336630202c\n"
".quad 0x2020203b65633566,0x342e32202f2f0920,0x35302d6532333334,0x33662e766f6d090a\n"
".quad 0x2c33366625092032,0x3036626162663020,0x202020203b613136,0x302e302d202f2f09\n"
".quad 0x0a33373838333130,0x2e6e722e616d6609,0x3666250920323366,0x2c32366625202c34\n"
".quad 0x25202c3136662520,0x6f6d090a3b333666,0x2509203233662e76,0x336630202c353666\n"
".quad 0x3b35616161613264,0x202f2f0920202020,0x3636363134302e30,0x722e616d66090a36\n"
".quad 0x2509203233662e6e,0x366625202c363666,0x2c31366625202c34,0x090a3b3536662520\n"
".quad 0x203233662e766f6d,0x30202c3736662509,0x3030303030666266,0x2f09202020203b30\n"
".quad 0x090a352e302d202f,0x662e6e722e616d66,0x3836662509203233,0x202c36366625202c\n"
".quad 0x6625202c31366625,0x766f6d090a3b3736,0x662509203233662e,0x66336630202c3936\n"
".quad 0x203b303030303038,0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x38366625202c3037,0x202c31366625202c,0x62090a3b39366625,0x0920696e752e6172\n"
".quad 0x33315f315f744c24,0x4c240a3b38373333,0x363333315f315f74,0x3c2f2f200a3a3433\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3032315f315f4c24,0x6f6c2e090a363630\n"
".quad 0x3436310938310963,0x766f6d090a300936,0x662509203233662e,0x39626630202c3137\n"
".quad 0x203b396631616334,0x2d202f2f09202020,0x3539313030302e30,0x766f6d090a333531\n"
".quad 0x662509203233662e,0x63336630202c3237,0x203b653933383830,0x30202f2f09202020\n"
".quad 0x313233333830302e,0x722e616d66090a36,0x2509203233662e6e,0x376625202c333766\n"
".quad 0x2c31366625202c31,0x090a3b3237662520,0x203233662e766f6d,0x30202c3437662509\n"
".quad 0x6161616132656266,0x2f09202020203b33,0x3636312e302d202f,0x616d66090a373636\n"
".quad 0x203233662e6e722e,0x25202c3537662509,0x366625202c333766,0x3b34376625202c31\n"
".quad 0x33662e6c756d090a,0x2c36376625092032,0x25202c3136662520,0x6d66090a3b353766\n"
".quad 0x3233662e6e722e61,0x202c303766250920,0x6625202c36376625,0x30366625202c3036\n"
".quad 0x5f315f744c240a3b,0x0a3a383733333331,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3636303032315f,0x383109636f6c2e09,0x0a30093834363109\n"
".quad 0x3233662e67656e09,0x202c373766250920,0x61090a3b30376625,0x09203233622e646e\n"
".quad 0x25202c3938317225,0x3b32202c33363172,0x33732e766f6d090a,0x3039317225092032\n"
".quad 0x6573090a3b30202c,0x33732e656e2e7074,0x2c37327025092032,0x202c393831722520\n"
".quad 0x090a3b3039317225,0x3233662e706c6573,0x202c303766250920,0x6625202c37376625\n"
".quad 0x37327025202c3037,0x09636f6c2e090a3b,0x0931353631093831,0x662e766f6d090a30\n"
".quad 0x3834662509203233,0x0a3b30376625202c,0x69646e6557444c24,0x666e6973695f5f5f\n"
".quad 0x33335f3837315f66,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x36303032315f315f,0x09636f6c2e090a36,0x090a300938390933,0x74736e6f632e646c\n"
".quad 0x662509203233662e,0x3372255b202c3837,0x090a3b5d36312b35,0x74736e6f632e646c\n"
".quad 0x662509203233662e,0x3372255b202c3937,0x090a3b5d32312b35,0x203233662e6c756d\n"
".quad 0x25202c3038662509,0x376625202c383466,0x2e6c756d090a3b38,0x3866250920323366\n"
".quad 0x2c39376625202c31,0x090a3b3631662520,0x203233662e627573,0x25202c3238662509\n"
".quad 0x386625202c313866,0x2e646461090a3b30,0x3466250920323366,0x25202c346625202c\n"
".quad 0x6c2e090a3b323866,0x093939093309636f,0x662e6c756d090a30,0x3338662509203233\n"
".quad 0x202c36316625202c,0x66090a3b38376625,0x33662e6e722e616d,0x2c34386625092032\n"
".quad 0x25202c3937662520,0x386625202c383466,0x2e646461090a3b33,0x3566250920323366\n"
".quad 0x25202c356625202c,0x6c2e090a3b343866,0x093139093309636f,0x732e646461090a30\n"
".quad 0x3932722509203233,0x202c39327225202c,0x2e646461090a3b31,0x3272250920323373\n"
".quad 0x31202c327225202c,0x2e70746573090a3b,0x09203233732e656c,0x7225202c38327025\n"
".quad 0x39327225202c3732,0x3832702540090a3b,0x4c24092061726220,0x32333032315f315f\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303032315f315f4c\n"
".quad 0x70746573090a3636,0x203233732e746c2e,0x25202c3932702509,0x38317225202c3272\n"
".quad 0x3932702540090a3b,0x4c24092061726220,0x36303032315f315f,0x2e617262090a3b36\n"
".quad 0x5f4c240920696e75,0x3232333032315f31,0x5f315f744c240a3b,0x0a3a363439383731\n"
".quad 0x3233732e766f6d09,0x202c393272250920,0x2e617262090a3b30,0x5f4c240920696e75\n"
".quad 0x3232333032315f31,0x5f315f744c240a3b,0x0a3a323032393731,0x3233732e766f6d09\n"
".quad 0x202c393272250920,0x5f315f4c240a3b30,0x0a3a323233303231,0x3233752e766f6d09\n"
".quad 0x202c333372250920,0x5f5f616475635f5f,0x65725f616475635f,0x3134345f746c7573\n"
".quad 0x6d090a3b34323330,0x09203233752e766f,0x5f5f202c32337225,0x635f5f5f61647563\n"
".quad 0x757365725f616475,0x32303136315f746c,0x766f6d090a3b3639,0x722509203233752e\n"
".quad 0x090a3b63202c3133,0x203233752e766f6d,0x5f202c3033722509,0x5f7472616475635f\n"
".quad 0x3b665f69706f3269,0x6e752e617262090a,0x315f744c24092069,0x3b3431313232315f\n"
".quad 0x315f315f744c240a,0x090a3a3037333232,0x203233732e766f6d,0x30202c3932722509\n"
".quad 0x752e766f6d090a3b,0x3033722509203233,0x616475635f5f202c,0x69706f32695f7472\n"
".quad 0x766f6d090a3b665f,0x722509203233752e,0x090a3b63202c3133,0x203233752e766f6d\n"
".quad 0x5f202c3233722509,0x5f5f5f616475635f,0x7365725f61647563,0x303136315f746c75\n"
".quad 0x6f6d090a3b363932,0x2509203233752e76,0x635f5f202c333372,0x75635f5f5f616475\n"
".quad 0x6c757365725f6164,0x3233303134345f74,0x315f744c240a3b34,0x3a3431313232315f\n"
".quad 0x3309636f6c2e090a,0x090a300933303109,0x203233752e766f6d,0x202c313931722509\n"
".quad 0x6573090a3b313135,0x33732e74672e7074,0x2c30337025092032,0x25202c3932722520\n"
".quad 0x40090a3b31393172,0x6172622030337025,0x5f315f744c240920,0x0a3b363232303831\n"
".quad 0x65672e7074657309,0x702509203233732e,0x2c327225202c3133,0x090a3b3831722520\n"
".quad 0x7262203133702540,0x315f744c24092061,0x3b3632323038315f,0x32315f315f4c240a\n"
".quad 0x2f200a3a30393031,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3120656e696c2079\n"
".quad 0x6f6c2e090a323037,0x3037310938310963,0x6c756d090a300932,0x203233752e6f6c2e\n"
".quad 0x202c323931722509,0x3032202c39327225,0x752e646461090a3b,0x3533722509203233\n"
".quad 0x2c3239317225202c,0x090a3b3133722520,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x3372255b202c3538,0x6c090a3b5d342b35,0x2e74736e6f632e64,0x3866250920323366\n"
".quad 0x353372255b202c36,0x646c090a3b5d302b,0x662e74736e6f632e,0x3738662509203233\n"
".quad 0x2b353372255b202c,0x6c756d090a3b5d38,0x662509203233662e,0x35386625202c3838\n"
".quad 0x090a3b326625202c,0x662e6e722e616d66,0x3938662509203233,0x202c36386625202c\n"
".quad 0x386625202c316625,0x2e616d66090a3b38,0x09203233662e6e72,0x6625202c30396625\n"
".quad 0x2c336625202c3738,0x090a3b3938662520,0x2e3436662e747663,0x6466250920323366\n"
".quad 0x3b30396625202c35,0x36662e766f6d090a,0x2c36646625092034,0x3239313034643020\n"
".quad 0x3234343435626631,0x202f2f093b383164,0x0a39313338322e36,0x3436662e6c756d09\n"
".quad 0x202c376466250920,0x6625202c35646625,0x736261090a3b3664,0x662509203436662e\n"
".quad 0x37646625202c3864,0x722e747663090a3b,0x36662e3233662e6e,0x2c32316625092034\n"
".quad 0x090a3b3764662520,0x662e6e722e747663,0x09203436662e3233,0x6625202c33316625\n"
".quad 0x766f6d090a3b3864,0x662509203233662e,0x66376630202c3139,0x203b303030303038\n"
".quad 0x28202f2f09202020,0x282f2946302e3128,0x090a292946302e30,0x2e71652e70746573\n"
".quad 0x3470250920323366,0x202c33316625202c,0x40090a3b31396625,0x6172622034702521\n"
".quad 0x5f315f744c240920,0x0a3b303938333331,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093330373109\n"
".quad 0x3233662e67656e09,0x202c323966250920,0x61090a3b32316625,0x33662e6e722e6464\n"
".quad 0x2c33396625092032,0x25202c3231662520,0x7262090a3b323966,0x240920696e752e61\n"
".quad 0x5f69646e6557444c,0x66666e6973695f5f,0x3b39325f3837315f,0x315f315f744c240a\n"
".quad 0x200a3a3039383333,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a303930313231,0x203233662e766f6d,0x30202c3439662509,0x3037616233373466\n"
".quad 0x2f09202020203b30,0x0a3933303834202f,0x74672e7074657309,0x702509203233662e\n"
".quad 0x33316625202c3233,0x0a3b34396625202c,0x2032337025214009,0x744c240920617262\n"
".quad 0x30343433315f315f,0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x636f6c2e090a3039,0x3639333109383109,0x2e766f6d090a3009\n"
".quad 0x3172250920323362,0x32316625202c3339,0x622e646e61090a3b,0x3931722509203233\n"
".quad 0x3339317225202c34,0x34373431322d202c,0x090a3b3834363338,0x203233732e766f6d\n"
".quad 0x25202c3833722509,0x2e090a3b34393172,0x3109383109636f6c,0x73090a3009323034\n"
".quad 0x09203233622e6c68,0x25202c3539317225,0x3b31202c33393172,0x33752e726873090a\n"
".quad 0x3639317225092032,0x2c3539317225202c,0x7573090a3b343220,0x2509203233752e62\n"
".quad 0x7225202c37393172,0x383231202c363931,0x09636f6c2e090a3b,0x0a30093432093831\n"
".quad 0x3233732e766f6d09,0x202c323472250920,0x61090a3b30337225,0x09203233752e6464\n"
".quad 0x7225202c33347225,0x0a3b3432202c3033,0x3233752e766f6d09,0x202c343472250920\n"
".quad 0x5f5f616475635f5f,0x65725f616475635f,0x3134345f746c7573,0x73090a3b34323330\n"
".quad 0x09203233622e6c68,0x25202c3839317225,0x3b38202c33393172,0x3233622e726f090a\n"
".quad 0x2c39393172250920,0x202c383931722520,0x333834373431322d,0x6f6d090a3b383436\n"
".quad 0x2509203233752e76,0x0a3b30202c373472,0x33315f315f744c24,0x2e090a3a36323435\n"
".quad 0x2220616d67617270,0x6c6c6f726e756f6e,0x6c3c2f2f200a3b22,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x202c343220656e69,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x746172657469202c,0x0a36203a736e6f69,0x383109636f6c2e09,0x0a30093031343109\n"
".quad 0x736e6f632e646c09,0x2509203233752e74,0x72255b202c383472,0x090a3b5d302b3234\n"
".quad 0x752e6f6c2e6c756d,0x3032722509203233,0x2c38347225202c30,0x0a3b393931722520\n"
".quad 0x3233752e64646109,0x2c31303272250920,0x202c303032722520,0x2e090a3b37347225\n"
".quad 0x3109383109636f6c,0x73090a3009313134,0x33752e74672e7465,0x2509203233752e32\n"
".quad 0x7225202c32303272,0x327225202c303032,0x67656e090a3b3130,0x722509203233732e\n"
".quad 0x327225202c333032,0x6c756d090a3b3230,0x203233752e69682e,0x202c343032722509\n"
".quad 0x7225202c38347225,0x6461090a3b393931,0x2509203233752e64,0x327225202c373472\n"
".quad 0x30327225202c3330,0x636f6c2e090a3b34,0x3231343109383109,0x6c2e7473090a3009\n"
".quad 0x3233752e6c61636f,0x2b343472255b0920,0x30327225202c5d30,0x2e646461090a3b31\n"
".quad 0x3472250920323375,0x2c34347225202c34,0x646461090a3b3420,0x722509203233752e\n"
".quad 0x32347225202c3234,0x6573090a3b34202c,0x33752e656e2e7074,0x2c33337025092032\n"
".quad 0x25202c3234722520,0x2540090a3b333472,0x2061726220333370,0x315f315f744c2409\n"
".quad 0x200a3b3632343533,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a303930313231,0x09383109636f6c2e,0x090a300934313431,0x6c61636f6c2e7473\n"
".quad 0x5f5b09203233752e,0x5f5f5f616475635f,0x7365725f61647563,0x303134345f746c75\n"
".quad 0x2c5d34322b343233,0x090a3b3734722520,0x09383109636f6c2e,0x090a300939313431\n"
".quad 0x203233752e726873,0x202c353032722509,0x35202c3739317225,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x7225202c36303272,0x0a3b34202c353032,0x3233752e62757309\n"
".quad 0x202c363572250920,0x7225202c33337225,0x646c090a3b363032,0x752e6c61636f6c2e\n"
".quad 0x3734722509203233,0x2b363572255b202c,0x6c2e090a3b5d3432,0x343109383109636f\n"
".quad 0x646c090a30093032,0x752e6c61636f6c2e,0x3735722509203233,0x2b363572255b202c\n"
".quad 0x6e61090a3b5d3032,0x2509203233622e64,0x7225202c37303272,0x3b3133202c373931\n"
".quad 0x33752e766f6d090a,0x3830327225092032,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x2c34337025092032,0x202c373032722520,0x090a3b3830327225,0x7262203433702540\n"
".quad 0x315f744c24092061,0x3b3833393533315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a,0x3009333234310938\n"
".quad 0x33732e766f6d090a,0x3930327225092032,0x73090a3b3233202c,0x09203233732e6275\n"
".quad 0x25202c3031327225,0x7225202c39303272,0x6873090a3b373032,0x2509203233752e72\n"
".quad 0x7225202c31313272,0x31327225202c3735,0x2e6c6873090a3b30,0x3272250920323362\n"
".quad 0x37347225202c3231,0x3b3730327225202c,0x33752e646461090a,0x2c37347225092032\n"
".quad 0x202c313132722520,0x090a3b3231327225,0x09383109636f6c2e,0x090a300934323431\n"
".quad 0x6c61636f6c2e646c,0x722509203233752e,0x72255b202c333132,0x0a3b5d36312b3635\n"
".quad 0x3233752e72687309,0x2c34313272250920,0x202c333132722520,0x090a3b3031327225\n"
".quad 0x203233622e6c6873,0x202c353132722509,0x7225202c37357225,0x6461090a3b373032\n"
".quad 0x2509203233752e64,0x327225202c373572,0x31327225202c3431,0x315f744c240a3b35\n"
".quad 0x3a3833393533315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009363234310938,0x33752e726873090a\n"
".quad 0x2c37367225092032,0x33202c3734722520,0x636f6c2e090a3b30,0x3832343109383109\n"
".quad 0x2e726873090a3009,0x3272250920323375,0x37357225202c3631,0x73090a3b3033202c\n"
".quad 0x09203233622e6c68,0x25202c3731327225,0x0a3b32202c373472,0x3233752e64646109\n"
".quad 0x202c373472250920,0x25202c3631327225,0x2e090a3b37313272,0x3109383109636f6c\n"
".quad 0x73090a3009393234,0x09203233622e6c68,0x7225202c37357225,0x090a3b32202c3735\n"
".quad 0x203233752e766f6d,0x202c383132722509,0x70746573090a3b30,0x203233752e71652e\n"
".quad 0x25202c3533702509,0x327225202c373572,0x702540090a3b3831,0x0920617262203533\n"
".quad 0x33315f315f744c24,0x2f200a3b36303736,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c,0x61090a3009303334\n"
".quad 0x09203233752e6464,0x25202c3931327225,0x0a3b31202c373472,0x3233752e766f6d09\n"
".quad 0x2c30323272250920,0x3834373431322d20,0x73090a3b38343633,0x33752e74672e7465\n"
".quad 0x2509203233752e32,0x7225202c31323272,0x327225202c393132,0x67656e090a3b3032\n"
".quad 0x722509203233732e,0x327225202c323232,0x617262090a3b3132,0x4c240920696e752e\n"
".quad 0x343633315f315f74,0x5f744c240a3b3035,0x3630373633315f31,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x39303132315f315f,0x752e766f6d090a30\n"
".quad 0x3232722509203233,0x373431322d202c33,0x0a3b383436333834,0x2e74672e74657309\n"
".quad 0x203233752e323375,0x202c343232722509,0x7225202c37347225,0x656e090a3b333232\n"
".quad 0x2509203233732e67,0x7225202c32323272,0x744c240a3b343232,0x35343633315f315f\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3133343109383109,0x2e646461090a3009,0x3272250920323375\n"
".quad 0x37367225202c3532,0x3b3232327225202c,0x3109636f6c2e090a,0x3009303334310938\n"
".quad 0x33732e67656e090a,0x3632327225092032,0x3b3532327225202c,0x33752e766f6d090a\n"
".quad 0x3732327225092032,0x6573090a3b30202c,0x33752e656e2e7074,0x2c36337025092032\n"
".quad 0x202c343931722520,0x090a3b3732327225,0x3233732e706c6573,0x202c373672250920\n"
".quad 0x25202c3632327225,0x7025202c35323272,0x766f6d090a3b3633,0x722509203233752e\n"
".quad 0x0a3b30202c383232,0x71652e7074657309,0x702509203233752e,0x32327225202c3733\n"
".quad 0x3832327225202c32,0x3733702540090a3b,0x4c24092061726220,0x393633315f315f74\n"
".quad 0x3c2f2f200a3b3236,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3334310938310963,0x67656e090a300936,0x722509203233732e\n"
".quad 0x37357225202c3735,0x09636f6c2e090a3b,0x0938333431093831,0x752e766f6d090a30\n"
".quad 0x3232722509203233,0x73090a3b30202c39,0x33752e71652e7465,0x2509203233752e32\n"
".quad 0x7225202c30333272,0x32327225202c3735,0x2e67656e090a3b39,0x3272250920323373\n"
".quad 0x33327225202c3133,0x2e746f6e090a3b30,0x3272250920323362,0x37347225202c3233\n"
".quad 0x752e646461090a3b,0x3734722509203233,0x2c3133327225202c,0x0a3b323332722520\n"
".quad 0x383109636f6c2e09,0x0a30093933343109,0x3233622e726f7809,0x202c383372250920\n"
".quad 0x2d202c3439317225,0x3633383437343132,0x5f744c240a3b3834,0x3236393633315f31\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x09636f6c2e090a30,0x0931343431093831,0x732e766f6d090a30,0x3538722509203233\n"
".quad 0x0a3b37367225202c,0x3233752e766f6d09,0x2c33333272250920,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x202c383370250920,0x7225202c37347225,0x2540090a3b333332\n"
".quad 0x2061726220383370,0x315f315f744c2409,0x200a3b3833373038,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231,0x203233752e766f6d\n"
".quad 0x30202c3738722509,0x5f315f744c240a3b,0x0a3a363839373331,0x706f6f6c3c2f2f20\n"
".quad 0x6220706f6f4c203e,0x656e696c2079646f,0x6e202c3134343120,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09383109636f6c2e,0x090a300935343431,0x203233752e726873\n"
".quad 0x202c343332722509,0x3133202c37357225,0x622e6c6873090a3b,0x3332722509203233\n"
".quad 0x2c37347225202c35,0x646461090a3b3120,0x722509203233752e,0x33327225202c3734\n"
".quad 0x3533327225202c34,0x09636f6c2e090a3b,0x0936343431093831,0x622e6c6873090a30\n"
".quad 0x3735722509203233,0x202c37357225202c,0x636f6c2e090a3b31,0x3734343109383109\n"
".quad 0x2e627573090a3009,0x3872250920323375,0x2c37387225202c37,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x0a3b30202c363332,0x74672e7074657309,0x702509203233732e\n"
".quad 0x37347225202c3933,0x3b3633327225202c,0x203933702540090a,0x744c240920617262\n"
".quad 0x38393733315f315f,0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x2e617262090a3039,0x744c240920696e75,0x37343733315f315f\n"
".quad 0x315f744c240a3b34,0x3a3833373038315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3039303132315f31,0x33752e766f6d090a,0x2c37387225092032\n"
".quad 0x5f744c240a3b3020,0x3437343733315f31,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x39303132315f315f,0x09636f6c2e090a30,0x0939343431093831\n"
".quad 0x6c2e6c756d090a30,0x2509203233752e6f,0x347225202c373572,0x373132392d202c37\n"
".quad 0x090a3b3037383730,0x09383109636f6c2e,0x090a300930353431,0x203233752e766f6d\n"
".quad 0x202c373332722509,0x383730373132392d,0x6c756d090a3b3037,0x203233752e69682e\n"
".quad 0x25202c3734722509,0x327225202c373472,0x766f6d090a3b3733,0x722509203233752e\n"
".quad 0x0a3b30202c383332,0x656c2e7074657309,0x702509203233732e,0x37347225202c3034\n"
".quad 0x3b3833327225202c,0x203034702540090a,0x744c240920617262,0x39343833315f315f\n"
".quad 0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3235343109383109,0x2e726873090a3009,0x3272250920323375\n"
".quad 0x37357225202c3933,0x73090a3b3133202c,0x09203233622e6c68,0x25202c3034327225\n"
".quad 0x0a3b31202c373472,0x3233752e64646109,0x202c373472250920,0x25202c3933327225\n"
".quad 0x2e090a3b30343272,0x3109383109636f6c,0x73090a3009333534,0x09203233622e6c68\n"
".quad 0x7225202c37357225,0x090a3b31202c3735,0x09383109636f6c2e,0x090a300934353431\n"
".quad 0x203233752e627573,0x25202c3738722509,0x0a3b31202c373872,0x33315f315f744c24\n"
".quad 0x2f200a3a38393438,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x2e090a3039303132,0x3109383109636f6c,0x6d090a3009363534,0x09203233752e766f\n"
".quad 0x30202c3134327225,0x6e2e746573090a3b,0x33752e3233752e65,0x3234327225092032\n"
".quad 0x202c37357225202c,0x090a3b3134327225,0x203233732e67656e,0x202c333432722509\n"
".quad 0x090a3b3234327225,0x203233752e646461,0x25202c3734722509,0x7225202c33343272\n"
".quad 0x6f6c2e090a3b3734,0x3534310938310963,0x6c6873090a300938,0x722509203233622e\n"
".quad 0x347225202c343432,0x090a3b3432202c37,0x203233732e766f6d,0x202c353432722509\n"
".quad 0x2e746573090a3b30,0x732e3233752e746c,0x3432722509203233,0x3434327225202c36\n"
".quad 0x3b3534327225202c,0x33732e67656e090a,0x3734327225092032,0x3b3634327225202c\n"
".quad 0x33752e726873090a,0x3834327225092032,0x202c37347225202c,0x2e646461090a3b38\n"
".quad 0x3272250920323375,0x37387225202c3934,0x090a3b363231202c,0x203233622e6c6873\n"
".quad 0x202c303532722509,0x32202c3934327225,0x2e646461090a3b33,0x3272250920323375\n"
".quad 0x34327225202c3135,0x3035327225202c38,0x752e646461090a3b,0x3532722509203233\n"
".quad 0x3734327225202c32,0x3b3135327225202c,0x3233622e726f090a,0x2c33353272250920\n"
".quad 0x25202c3833722520,0x6d090a3b32353272,0x09203233622e766f,0x7225202c38316625\n"
".quad 0x7262090a3b333532,0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f\n"
".quad 0x5f64616d665f6c61,0x0a3b30335f383731,0x33315f315f744c24,0x2f200a3a32303434\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132\n"
".quad 0x3109383109636f6c,0x6d090a3009303634,0x09203233662e766f,0x6630202c35396625\n"
".quad 0x3338396632326633,0x2f2f09202020203b,0x32363633362e3020,0x33662e6c756d090a\n"
".quad 0x2c36396625092032,0x25202c3231662520,0x7663090a3b353966,0x33732e696e722e74\n"
".quad 0x2509203233662e32,0x6625202c34353272,0x6f6c2e090a3b3639,0x3634310938310963\n"
".quad 0x747663090a300935,0x2e3233662e6e722e,0x3966250920323373,0x3435327225202c37\n"
".quad 0x662e67656e090a3b,0x3839662509203233,0x0a3b37396625202c,0x3233662e766f6d09\n"
".quad 0x202c393966250920,0x6161646639336630,0x09202020203b3032,0x3030302e30202f2f\n"
".quad 0x090a373238333834,0x203233662e766f6d,0x202c303031662509,0x3030396366336630\n"
".quad 0x2f092020203b3030,0x333037352e31202f,0x722e616d66090a31,0x2509203233662e6e\n"
".quad 0x6625202c31303166,0x30316625202c3839,0x3b32316625202c30,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x396625202c323031,0x2c39396625202c38,0x0a3b313031662520\n"
".quad 0x383109636f6c2e09,0x0a30093137343109,0x3233732e766f6d09,0x202c353872250920\n"
".quad 0x090a3b3435327225,0x09383109636f6c2e,0x090a300932373431,0x203233662e766f6d\n"
".quad 0x202c333031662509,0x3361353865326630,0x2f092020203b3930,0x313737302e36202f\n"
".quad 0x6d66090a31312d65,0x3233662e6e722e61,0x202c383166250920,0x6625202c38396625\n"
".quad 0x316625202c333031,0x57444c240a3b3230,0x695f5f5f69646e65,0x5f6c616e7265746e\n"
".quad 0x3837315f64616d66,0x2f2f200a3a30335f,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a30393031,0x373109383109636f,0x6461090a30093530\n"
".quad 0x2509203233732e64,0x7225202c39303172,0x090a3b31202c3538,0x203233662e766f6d\n"
".quad 0x202c343031662509,0x6d090a3b38316625,0x09203233662e6c75,0x6625202c39326625\n"
".quad 0x316625202c343031,0x646e61090a3b3430,0x722509203233622e,0x317225202c353532\n"
".quad 0x090a3b31202c3930,0x203233752e766f6d,0x202c363532722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3134702509,0x7225202c35353272,0x2540090a3b363532\n"
".quad 0x2061726220313470,0x315f315f744c2409,0x200a3b3636323933,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e\n"
".quad 0x090a300939303731,0x203233662e766f6d,0x202c353031662509,0x3566636337336630\n"
".quad 0x2f092020203b6563,0x333334342e32202f,0x6d090a35302d6532,0x09203233662e766f\n"
".quad 0x30202c3630316625,0x3136303662616266,0x2f2f092020203b61,0x333130302e302d20\n"
".quad 0x6d66090a33373838,0x3233662e6e722e61,0x2c37303166250920,0x202c353031662520\n"
".quad 0x6625202c39326625,0x6f6d090a3b363031,0x2509203233662e76,0x6630202c38303166\n"
".quad 0x3561616161326433,0x202f2f092020203b,0x3636363134302e30,0x722e616d66090a36\n"
".quad 0x2509203233662e6e,0x6625202c39303166,0x326625202c373031,0x3830316625202c39\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x3066626630202c30,0x20203b3030303030\n"
".quad 0x2e302d202f2f0920,0x722e616d66090a35,0x2509203233662e6e,0x6625202c31313166\n"
".quad 0x326625202c393031,0x3031316625202c39,0x662e766f6d090a3b,0x3131662509203233\n"
".quad 0x3866336630202c32,0x20203b3030303030,0x090a31202f2f0920,0x662e6e722e616d66\n"
".quad 0x3833662509203233,0x2c3131316625202c,0x25202c3932662520,0x62090a3b32313166\n"
".quad 0x0920696e752e6172,0x33315f315f744c24,0x4c240a3b30313039,0x323933315f315f74\n"
".quad 0x3c2f2f200a3a3636,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3137310938310963,0x766f6d090a300931,0x662509203233662e\n"
".quad 0x626630202c333131,0x3b39663161633439,0x2d202f2f09202020,0x3539313030302e30\n"
".quad 0x766f6d090a333531,0x662509203233662e,0x336630202c343131,0x3b65393338383063\n"
".quad 0x30202f2f09202020,0x313233333830302e,0x722e616d66090a36,0x2509203233662e6e\n"
".quad 0x6625202c35313166,0x326625202c333131,0x3431316625202c39,0x662e766f6d090a3b\n"
".quad 0x3131662509203233,0x3265626630202c36,0x20203b3361616161,0x2e302d202f2f0920\n"
".quad 0x090a373636363631,0x662e6e722e616d66,0x3131662509203233,0x3531316625202c37\n"
".quad 0x202c39326625202c,0x090a3b3631316625,0x203233662e6c756d,0x202c383131662509\n"
".quad 0x6625202c39326625,0x6d66090a3b373131,0x3233662e6e722e61,0x202c383366250920\n"
".quad 0x25202c3831316625,0x6625202c34303166,0x744c240a3b343031,0x31303933315f315f\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3331373109383109,0x2e67656e090a3009,0x3166250920323366\n"
".quad 0x38336625202c3931,0x622e646e61090a3b,0x3532722509203233,0x3930317225202c37\n"
".quad 0x6f6d090a3b32202c,0x2509203233732e76,0x3b30202c38353272,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x327225202c323470,0x35327225202c3735,0x706c6573090a3b38\n"
".quad 0x662509203233662e,0x31316625202c3833,0x2c38336625202c39,0x090a3b3234702520\n"
".quad 0x09383109636f6c2e,0x090a300936313731,0x203233662e766f6d,0x25202c3339662509\n"
".quad 0x444c240a3b383366,0x5f5f5f69646e6557,0x315f66666e697369,0x200a3a39325f3837\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300938333631,0x3233732e706c6573,0x2c39353272250920\n"
".quad 0x25202c30202c3120,0x766f6d090a3b3470,0x662509203233662e,0x306630202c303231\n"
".quad 0x3b30303030303030,0x30202f2f09202020,0x71652e746573090a,0x3233662e3233752e\n"
".quad 0x2c30363272250920,0x25202c3231662520,0x6e090a3b30323166,0x09203233732e6765\n"
".quad 0x25202c3136327225,0x6f090a3b30363272,0x2509203233622e72,0x7225202c32363272\n"
".quad 0x327225202c393532,0x766f6d090a3b3136,0x722509203233752e,0x0a3b30202c333632\n"
".quad 0x71652e7074657309,0x702509203233732e,0x36327225202c3334,0x3336327225202c32\n"
".quad 0x3334702540090a3b,0x4c24092061726220,0x353933315f315f74,0x3c2f2f200a3b3232\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930\n"
".quad 0x3336310938310963,0x766f6d090a300939,0x662509203233662e,0x306630202c313231\n"
".quad 0x3b30303030303030,0x30202f2f09202020,0x6e722e6c756d090a,0x662509203233662e\n"
".quad 0x32316625202c3834,0x3b3132316625202c,0x6e752e617262090a,0x6557444c24092069\n"
".quad 0x73695f5f5f69646e,0x3837315f66666e69,0x744c240a3b35325f,0x32353933315f315f\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x2e766f6d090a3039,0x3166250920323366,0x37346630202c3232,0x203b303037616233\n"
".quad 0x3834202f2f092020,0x746573090a393330,0x3233662e74672e70,0x202c343470250920\n"
".quad 0x6625202c33316625,0x2140090a3b323231,0x6172622034347025,0x5f315f744c240920\n"
".quad 0x0a3b343330303431,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c\n"
".quad 0x0a3039303132315f,0x383109636f6c2e09,0x0a30093639333109,0x3233622e766f6d09\n"
".quad 0x2c34363272250920,0x090a3b3231662520,0x203233622e646e61,0x202c343931722509\n"
".quad 0x2d202c3436327225,0x3633383437343132,0x766f6d090a3b3834,0x722509203233732e\n"
".quad 0x317225202c303231,0x6f6c2e090a3b3439,0x3034310938310963,0x6c6873090a300932\n"
".quad 0x722509203233622e,0x327225202c353632,0x090a3b31202c3436,0x203233752e726873\n"
".quad 0x202c363632722509,0x32202c3536327225,0x2e627573090a3b34,0x3172250920323375\n"
".quad 0x36327225202c3739,0x0a3b383231202c36,0x383109636f6c2e09,0x6d090a3009343209\n"
".quad 0x09203233732e766f,0x25202c3332317225,0x6461090a3b303372,0x2509203233752e64\n"
".quad 0x337225202c333472,0x090a3b3432202c30,0x203233752e766f6d,0x202c343231722509\n"
".quad 0x5f5f616475635f5f,0x65725f616475635f,0x3136315f746c7573,0x73090a3b36393230\n"
".quad 0x09203233622e6c68,0x25202c3736327225,0x3b38202c34363272,0x3233622e726f090a\n"
".quad 0x2c39393172250920,0x202c373632722520,0x333834373431322d,0x6f6d090a3b383436\n"
".quad 0x2509203233752e76,0x3b30202c36323172,0x315f315f744c240a,0x090a3a3835303134\n"
".quad 0x20616d676172702e,0x6c6f726e756f6e22,0x3c2f2f200a3b226c,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x2c343220656e696c,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6172657469202c31,0x36203a736e6f6974,0x3109636f6c2e090a,0x3009303134310938\n"
".quad 0x6e6f632e646c090a,0x09203233752e7473,0x5b202c3732317225,0x5d302b3332317225\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c38363272,0x317225202c373231\n"
".quad 0x646461090a3b3939,0x722509203233752e,0x327225202c393632,0x32317225202c3836\n"
".quad 0x636f6c2e090a3b36,0x3131343109383109,0x2e746573090a3009,0x752e3233752e7467\n"
".quad 0x3732722509203233,0x3836327225202c30,0x3b3936327225202c,0x33732e67656e090a\n"
".quad 0x3137327225092032,0x3b3037327225202c,0x69682e6c756d090a,0x722509203233752e\n"
".quad 0x317225202c323732,0x39317225202c3732,0x2e646461090a3b39,0x3172250920323375\n"
".quad 0x37327225202c3632,0x3237327225202c31,0x09636f6c2e090a3b,0x0932313431093831\n"
".quad 0x6f6c2e7473090a30,0x203233752e6c6163,0x2b34323172255b09,0x36327225202c5d30\n"
".quad 0x2e646461090a3b39,0x3172250920323375,0x32317225202c3432,0x61090a3b34202c34\n"
".quad 0x09203233752e6464,0x25202c3332317225,0x3b34202c33323172,0x6e2e70746573090a\n"
".quad 0x2509203233752e65,0x317225202c353470,0x33347225202c3332,0x3534702540090a3b\n"
".quad 0x4c24092061726220,0x303134315f315f74,0x3c2f2f200a3b3835,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930,0x3134310938310963\n"
".quad 0x2e7473090a300934,0x33752e6c61636f6c,0x75635f5f5b092032,0x6475635f5f5f6164\n"
".quad 0x746c757365725f61,0x363932303136315f,0x7225202c5d34322b,0x6c2e090a3b363231\n"
".quad 0x343109383109636f,0x6873090a30093931,0x2509203233752e72,0x7225202c33373272\n"
".quad 0x0a3b35202c373931,0x2e6f6c2e6c756d09,0x3272250920323375,0x37327225202c3437\n"
".quad 0x73090a3b34202c33,0x09203233752e6275,0x25202c3533317225,0x327225202c323372\n"
".quad 0x2e646c090a3b3437,0x33752e6c61636f6c,0x3632317225092032,0x35333172255b202c\n"
".quad 0x2e090a3b5d34322b,0x3109383109636f6c,0x6c090a3009303234,0x2e6c61636f6c2e64\n"
".quad 0x3172250920323375,0x3172255b202c3633,0x0a3b5d30322b3533,0x3233622e646e6109\n"
".quad 0x2c37303272250920,0x202c373931722520,0x766f6d090a3b3133,0x722509203233752e\n"
".quad 0x0a3b30202c353732,0x71652e7074657309,0x702509203233752e,0x30327225202c3634\n"
".quad 0x3537327225202c37,0x3634702540090a3b,0x4c24092061726220,0x353134315f315f74\n"
".quad 0x3c2f2f200a3b3037,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3234310938310963,0x766f6d090a300933,0x722509203233732e\n"
".quad 0x3b3233202c363732,0x33732e627573090a,0x3737327225092032,0x2c3637327225202c\n"
".quad 0x0a3b373032722520,0x3233752e72687309,0x2c38373272250920,0x202c363331722520\n"
".quad 0x090a3b3737327225,0x203233622e6c6873,0x202c393732722509,0x25202c3632317225\n"
".quad 0x61090a3b37303272,0x09203233752e6464,0x25202c3632317225,0x7225202c38373272\n"
".quad 0x6c2e090a3b393732,0x343109383109636f,0x646c090a30093432,0x752e6c61636f6c2e\n"
".quad 0x3832722509203233,0x333172255b202c30,0x090a3b5d36312b35,0x203233752e726873\n"
".quad 0x202c313832722509,0x25202c3038327225,0x73090a3b37373272,0x09203233622e6c68\n"
".quad 0x25202c3238327225,0x7225202c36333172,0x6461090a3b373032,0x2509203233752e64\n"
".quad 0x7225202c36333172,0x327225202c313832,0x5f744c240a3b3238,0x3037353134315f31\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x09636f6c2e090a30,0x0936323431093831,0x752e726873090a30,0x3431722509203233\n"
".quad 0x3632317225202c35,0x2e090a3b3033202c,0x3109383109636f6c,0x73090a3009383234\n"
".quad 0x09203233752e7268,0x25202c3338327225,0x3033202c36333172,0x622e6c6873090a3b\n"
".quad 0x3832722509203233,0x3632317225202c34,0x6461090a3b32202c,0x2509203233752e64\n"
".quad 0x7225202c36323172,0x327225202c333832,0x6f6c2e090a3b3438,0x3234310938310963\n"
".quad 0x6c6873090a300939,0x722509203233622e,0x317225202c363331,0x090a3b32202c3633\n"
".quad 0x203233752e766f6d,0x202c353832722509,0x70746573090a3b30,0x203233752e71652e\n"
".quad 0x25202c3734702509,0x7225202c36333172,0x2540090a3b353832,0x2061726220373470\n"
".quad 0x315f315f744c2409,0x200a3b3833333234,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e,0x090a300930333431\n"
".quad 0x203233752e646461,0x202c363832722509,0x31202c3632317225,0x752e766f6d090a3b\n"
".quad 0x3832722509203233,0x373431322d202c37,0x0a3b383436333834,0x2e74672e74657309\n"
".quad 0x203233752e323375,0x202c383832722509,0x25202c3638327225,0x6e090a3b37383272\n"
".quad 0x09203233732e6765,0x25202c3938327225,0x62090a3b38383272,0x0920696e752e6172\n"
".quad 0x34315f315f744c24,0x4c240a3b32383032,0x333234315f315f74,0x3c2f2f200a3a3833\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x766f6d090a303930\n"
".quad 0x722509203233752e,0x31322d202c303932,0x3834363338343734,0x672e746573090a3b\n"
".quad 0x33752e3233752e74,0x3139327225092032,0x2c3632317225202c,0x0a3b303932722520\n"
".quad 0x3233732e67656e09,0x2c39383272250920,0x0a3b313932722520,0x34315f315f744c24\n"
".quad 0x2f200a3a32383032,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x2e090a3039303132,0x3109383109636f6c,0x61090a3009313334,0x09203233752e6464\n"
".quad 0x25202c3239327225,0x7225202c35343172,0x6c2e090a3b393832,0x343109383109636f\n"
".quad 0x656e090a30093033,0x2509203233732e67,0x7225202c33393272,0x6f6d090a3b323932\n"
".quad 0x2509203233752e76,0x3b30202c34393272,0x6e2e70746573090a,0x2509203233752e65\n"
".quad 0x317225202c383470,0x39327225202c3439,0x706c6573090a3b34,0x722509203233732e\n"
".quad 0x327225202c353431,0x39327225202c3339,0x3b38347025202c32,0x33752e766f6d090a\n"
".quad 0x3539327225092032,0x6573090a3b30202c,0x33752e71652e7074,0x2c39347025092032\n"
".quad 0x202c393832722520,0x090a3b3539327225,0x7262203934702540,0x315f744c24092061\n"
".quad 0x3b3439353234315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009363334310938,0x33732e67656e090a\n"
".quad 0x3633317225092032,0x3b3633317225202c,0x3109636f6c2e090a,0x3009383334310938\n"
".quad 0x33752e766f6d090a,0x3639327225092032,0x6573090a3b30202c,0x3233752e71652e74\n"
".quad 0x722509203233752e,0x317225202c373932,0x39327225202c3633,0x2e67656e090a3b36\n"
".quad 0x3272250920323373,0x39327225202c3839,0x2e746f6e090a3b37,0x3272250920323362\n"
".quad 0x32317225202c3939,0x2e646461090a3b36,0x3172250920323375,0x39327225202c3632\n"
".quad 0x3939327225202c38,0x09636f6c2e090a3b,0x0939333431093831,0x622e726f78090a30\n"
".quad 0x3231722509203233,0x3439317225202c30,0x34373431322d202c,0x240a3b3834363338\n"
".quad 0x3234315f315f744c,0x2f2f200a3a343935,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f,0x6f6d090a30093134\n"
".quad 0x2509203233732e76,0x7225202c33363172,0x6f6d090a3b353431,0x2509203233752e76\n"
".quad 0x3b30202c30303372,0x6c2e70746573090a,0x2509203233732e65,0x317225202c303570\n"
".quad 0x30337225202c3632,0x35702540090a3b30,0x2409206172622030,0x3038315f315f744c\n"
".quad 0x2f2f200a3b343939,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6f6d090a30393031,0x2509203233752e76,0x3b30202c35363172,0x315f315f744c240a\n"
".quad 0x200a3a3831363334,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x656e202c31343431,0x656420676e697473,0x202c31203a687470,0x6574616d69747365\n"
".quad 0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3109383109636f6c\n"
".quad 0x73090a3009353434,0x09203233752e7268,0x25202c3130337225,0x3133202c36333172\n"
".quad 0x622e6c6873090a3b,0x3033722509203233,0x3632317225202c32,0x6461090a3b31202c\n"
".quad 0x2509203233752e64,0x7225202c36323172,0x337225202c313033,0x6f6c2e090a3b3230\n"
".quad 0x3434310938310963,0x6c6873090a300936,0x722509203233622e,0x317225202c363331\n"
".quad 0x090a3b31202c3633,0x09383109636f6c2e,0x090a300937343431,0x203233752e627573\n"
".quad 0x202c353631722509,0x31202c3536317225,0x752e766f6d090a3b,0x3033722509203233\n"
".quad 0x73090a3b30202c33,0x732e74672e707465,0x3135702509203233,0x2c3632317225202c\n"
".quad 0x0a3b333033722520,0x6220313570254009,0x5f744c2409206172,0x3831363334315f31\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x752e617262090a30,0x5f744c240920696e,0x3630313334315f31,0x5f315f744c240a3b\n"
".quad 0x0a3a343939303831,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c\n"
".quad 0x0a3039303132315f,0x3233752e766f6d09,0x2c35363172250920,0x5f744c240a3b3020\n"
".quad 0x3630313334315f31,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x39303132315f315f,0x09636f6c2e090a30,0x0939343431093831,0x6c2e6c756d090a30\n"
".quad 0x2509203233752e6f,0x7225202c36333172,0x32392d202c363231,0x3b30373837303731\n"
".quad 0x3109636f6c2e090a,0x3009303534310938,0x33752e766f6d090a,0x3430337225092032\n"
".quad 0x30373132392d202c,0x6d090a3b30373837,0x33752e69682e6c75,0x3632317225092032\n"
".quad 0x2c3632317225202c,0x0a3b343033722520,0x3233752e766f6d09,0x2c35303372250920\n"
".quad 0x746573090a3b3020,0x3233732e656c2e70,0x202c323570250920,0x25202c3632317225\n"
".quad 0x40090a3b35303372,0x6172622032357025,0x5f315f744c240920,0x0a3b303331343431\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093235343109,0x3233752e72687309,0x2c36303372250920\n"
".quad 0x202c363331722520,0x6c6873090a3b3133,0x722509203233622e,0x317225202c373033\n"
".quad 0x090a3b31202c3632,0x203233752e646461,0x202c363231722509,0x25202c3630337225\n"
".quad 0x2e090a3b37303372,0x3109383109636f6c,0x73090a3009333534,0x09203233622e6c68\n"
".quad 0x25202c3633317225,0x3b31202c36333172,0x3109636f6c2e090a,0x3009343534310938\n"
".quad 0x33752e627573090a,0x3536317225092032,0x2c3536317225202c,0x5f744c240a3b3120\n"
".quad 0x3033313434315f31,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x39303132315f315f,0x09636f6c2e090a30,0x0936353431093831,0x752e766f6d090a30\n"
".quad 0x3033722509203233,0x73090a3b30202c38,0x33752e656e2e7465,0x2509203233752e32\n"
".quad 0x7225202c39303372,0x337225202c363331,0x67656e090a3b3830,0x722509203233732e\n"
".quad 0x337225202c303133,0x646461090a3b3930,0x722509203233752e,0x337225202c363231\n"
".quad 0x32317225202c3031,0x636f6c2e090a3b36,0x3835343109383109,0x2e6c6873090a3009\n"
".quad 0x3372250920323362,0x32317225202c3131,0x090a3b3432202c36,0x203233732e766f6d\n"
".quad 0x202c323133722509,0x2e746573090a3b30,0x732e3233752e746c,0x3133722509203233\n"
".quad 0x3131337225202c33,0x3b3231337225202c,0x33732e67656e090a,0x3431337225092032\n"
".quad 0x3b3331337225202c,0x33752e726873090a,0x3531337225092032,0x2c3632317225202c\n"
".quad 0x646461090a3b3820,0x722509203233752e,0x317225202c363133,0x3b363231202c3536\n"
".quad 0x33622e6c6873090a,0x3731337225092032,0x2c3631337225202c,0x6461090a3b333220\n"
".quad 0x2509203233752e64,0x7225202c38313372,0x337225202c353133,0x646461090a3b3731\n"
".quad 0x722509203233752e,0x337225202c393133,0x31337225202c3431,0x622e726f090a3b38\n"
".quad 0x3233722509203233,0x3032317225202c30,0x3b3931337225202c,0x33622e766f6d090a\n"
".quad 0x2c30356625092032,0x0a3b303233722520,0x696e752e61726209,0x6e6557444c240920\n"
".quad 0x746e695f5f5f6964,0x6d665f6c616e7265,0x325f3837315f6461,0x315f744c240a3b36\n"
".quad 0x3a3433303034315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009303634310938,0x33662e766f6d090a\n"
".quad 0x3332316625092032,0x323266336630202c,0x2020203b33383966,0x33362e30202f2f09\n"
".quad 0x6c756d090a323636,0x662509203233662e,0x316625202c343231,0x3332316625202c32\n"
".quad 0x722e747663090a3b,0x662e3233732e696e,0x3233722509203233,0x3432316625202c31\n"
".quad 0x09636f6c2e090a3b,0x0935363431093831,0x722e747663090a30,0x33732e3233662e6e\n"
".quad 0x3532316625092032,0x3b3132337225202c,0x33662e67656e090a,0x3632316625092032\n"
".quad 0x3b3532316625202c,0x33662e766f6d090a,0x3732316625092032,0x646639336630202c\n"
".quad 0x2020203b30326161,0x30302e30202f2f09,0x0a37323833383430,0x3233662e766f6d09\n"
".quad 0x2c38323166250920,0x3039636633663020,0x092020203b303030,0x3037352e31202f2f\n"
".quad 0x2e616d66090a3133,0x09203233662e6e72,0x25202c3932316625,0x6625202c36323166\n"
".quad 0x316625202c383231,0x2e616d66090a3b32,0x09203233662e6e72,0x25202c3033316625\n"
".quad 0x6625202c36323166,0x316625202c373231,0x6f6c2e090a3b3932,0x3734310938310963\n"
".quad 0x766f6d090a300931,0x722509203233732e,0x337225202c333631,0x6f6c2e090a3b3132\n"
".quad 0x3734310938310963,0x766f6d090a300932,0x662509203233662e,0x326630202c313331\n"
".quad 0x3b39303361353865,0x36202f2f09202020,0x312d65313737302e,0x722e616d66090a31\n"
".quad 0x2509203233662e6e,0x316625202c303566,0x33316625202c3632,0x3033316625202c31\n"
".quad 0x6e6557444c240a3b,0x746e695f5f5f6964,0x6d665f6c616e7265,0x325f3837315f6461\n"
".quad 0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3134363109383109,0x2e766f6d090a3009,0x3166250920323366\n"
".quad 0x30356625202c3233,0x662e6c756d090a3b,0x3136662509203233,0x2c3233316625202c\n"
".quad 0x0a3b323331662520,0x3233622e646e6109,0x2c32323372250920,0x202c333631722520\n"
".quad 0x2e766f6d090a3b31,0x3372250920323375,0x090a3b30202c3332,0x2e71652e70746573\n"
".quad 0x3570250920323373,0x3232337225202c33,0x3b3332337225202c,0x203335702540090a\n"
".quad 0x744c240920617262,0x39383434315f315f,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039,0x3434363109383109\n"
".quad 0x2e766f6d090a3009,0x3166250920323366,0x37336630202c3333,0x203b656335666363\n"
".quad 0x2e32202f2f092020,0x302d653233333434,0x662e766f6d090a35,0x3331662509203233\n"
".quad 0x6261626630202c34,0x20203b6131363036,0x2e302d202f2f0920,0x3337383833313030\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c353331,0x31366625202c3333\n"
".quad 0x3b3433316625202c,0x33662e766f6d090a,0x3633316625092032,0x613264336630202c\n"
".quad 0x2020203b35616161,0x34302e30202f2f09,0x66090a3636363631,0x33662e6e722e616d\n"
".quad 0x3733316625092032,0x2c3533316625202c,0x25202c3136662520,0x6d090a3b36333166\n"
".quad 0x09203233662e766f,0x30202c3833316625,0x3030303030666266,0x2f2f092020203b30\n"
".quad 0x66090a352e302d20,0x33662e6e722e616d,0x3933316625092032,0x2c3733316625202c\n"
".quad 0x25202c3136662520,0x6d090a3b38333166,0x09203233662e766f,0x30202c3034316625\n"
".quad 0x3030303038663366,0x2f2f092020203b30,0x2e616d66090a3120,0x09203233662e6e72\n"
".quad 0x6625202c30376625,0x366625202c393331,0x3034316625202c31,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3234363434315f31,0x5f315f744c240a3b,0x0a3a383938343431\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093634363109,0x3233662e766f6d09,0x2c31343166250920\n"
".quad 0x6163343962663020,0x092020203b396631,0x30302e302d202f2f,0x0a33353135393130\n"
".quad 0x3233662e766f6d09,0x2c32343166250920,0x3838306333663020,0x092020203b653933\n"
".quad 0x3830302e30202f2f,0x66090a3631323333,0x33662e6e722e616d,0x3334316625092032\n"
".quad 0x2c3134316625202c,0x25202c3136662520,0x6d090a3b32343166,0x09203233662e766f\n"
".quad 0x30202c3434316625,0x6161616132656266,0x2f2f092020203b33,0x363636312e302d20\n"
".quad 0x2e616d66090a3736,0x09203233662e6e72,0x25202c3534316625,0x6625202c33343166\n"
".quad 0x34316625202c3136,0x2e6c756d090a3b34,0x3166250920323366,0x31366625202c3634\n"
".quad 0x3b3534316625202c,0x6e722e616d66090a,0x662509203233662e,0x34316625202c3037\n"
".quad 0x3233316625202c36,0x3b3233316625202c,0x315f315f744c240a,0x200a3a3234363434\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300938343631,0x203233662e67656e,0x202c373431662509\n"
".quad 0x61090a3b30376625,0x09203233622e646e,0x25202c3432337225,0x3b32202c33363172\n"
".quad 0x33732e766f6d090a,0x3532337225092032,0x6573090a3b30202c,0x33732e656e2e7074\n"
".quad 0x2c34357025092032,0x202c343233722520,0x090a3b3532337225,0x3233662e706c6573\n"
".quad 0x202c303766250920,0x25202c3734316625,0x357025202c303766,0x636f6c2e090a3b34\n"
".quad 0x3135363109383109,0x2e766f6d090a3009,0x3466250920323366,0x3b30376625202c38\n"
".quad 0x646e6557444c240a,0x6e6973695f5f5f69,0x325f3837315f6666,0x6c3c2f2f200a3a35\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039\n"
".quad 0x3009303131093309,0x6e6f632e646c090a,0x09203233662e7473,0x5b202c3834316625\n"
".quad 0x5d36312b35337225,0x6f632e646c090a3b,0x203233662e74736e,0x202c393431662509\n"
".quad 0x32312b353372255b,0x2e6c756d090a3b5d,0x3166250920323366,0x38346625202c3035\n"
".quad 0x3b3834316625202c,0x33662e6c756d090a,0x3135316625092032,0x2c3934316625202c\n"
".quad 0x090a3b3339662520,0x203233662e627573,0x202c323531662509,0x25202c3135316625\n"
".quad 0x61090a3b30353166,0x09203233662e6464,0x346625202c346625,0x3b3235316625202c\n"
".quad 0x3309636f6c2e090a,0x090a300931313109,0x203233662e6c756d,0x202c333531662509\n"
".quad 0x6625202c33396625,0x6d66090a3b383431,0x3233662e6e722e61,0x2c34353166250920\n"
".quad 0x202c393431662520,0x6625202c38346625,0x6461090a3b333531,0x2509203233662e64\n"
".quad 0x2c356625202c3566,0x0a3b343531662520,0x383109636f6c2e09,0x0a30093230373109\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x255b202c35353166,0x3b5d34322b353372\n"
".quad 0x6e6f632e646c090a,0x09203233662e7473,0x5b202c3635316625,0x5d30322b35337225\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x202c373531662509,0x38322b353372255b\n"
".quad 0x2e6c756d090a3b5d,0x3166250920323366,0x35316625202c3835,0x0a3b326625202c35\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x35316625202c3935,0x202c316625202c36\n"
".quad 0x090a3b3835316625,0x662e6e722e616d66,0x3631662509203233,0x3735316625202c30\n"
".quad 0x25202c336625202c,0x63090a3b39353166,0x662e3436662e7476,0x3964662509203233\n"
".quad 0x3b3036316625202c,0x36662e766f6d090a,0x3031646625092034,0x393130346430202c\n"
".quad 0x3434343562663132,0x2f2f093b38316432,0x39313338322e3620,0x36662e6c756d090a\n"
".quad 0x3131646625092034,0x202c39646625202c,0x090a3b3031646625,0x203436662e736261\n"
".quad 0x202c323164662509,0x090a3b3131646625,0x662e6e722e747663,0x09203436662e3233\n"
".quad 0x25202c3136316625,0x63090a3b31316466,0x33662e6e722e7476,0x2509203436662e32\n"
".quad 0x6625202c32363166,0x6f6d090a3b323164,0x2509203233662e76,0x6630202c33363166\n"
".quad 0x3030303030386637,0x202f2f092020203b,0x2f2946302e312828,0x0a292946302e3028\n"
".quad 0x71652e7074657309,0x702509203233662e,0x36316625202c3535,0x3336316625202c32\n"
".quad 0x3570252140090a3b,0x2409206172622035,0x3534315f315f744c,0x2f2f200a3b343531\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031\n"
".quad 0x373109383109636f,0x656e090a30093330,0x2509203233662e67,0x6625202c34363166\n"
".quad 0x6461090a3b313631,0x3233662e6e722e64,0x2c35363166250920,0x202c313631662520\n"
".quad 0x090a3b3436316625,0x20696e752e617262,0x646e6557444c2409,0x6e6973695f5f5f69\n"
".quad 0x325f3837315f6666,0x315f744c240a3b31,0x3a3435313534315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x33662e766f6d090a\n"
".quad 0x3636316625092032,0x623337346630202c,0x2020203b30303761,0x33303834202f2f09\n"
".quad 0x2e70746573090a39,0x09203233662e7467,0x6625202c36357025,0x316625202c323631\n"
".quad 0x252140090a3b3636,0x2061726220363570,0x315f315f744c2409,0x200a3b3636363534\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300936393331,0x203233622e766f6d,0x202c363233722509\n"
".quad 0x090a3b3136316625,0x203233622e646e61,0x202c373233722509,0x2d202c3632337225\n"
".quad 0x3633383437343132,0x766f6d090a3b3834,0x722509203233732e,0x32337225202c3833\n"
".quad 0x636f6c2e090a3b37,0x3230343109383109,0x2e6c6873090a3009,0x3372250920323362\n"
".quad 0x32337225202c3832,0x73090a3b31202c36,0x09203233752e7268,0x25202c3932337225\n"
".quad 0x3432202c38323372,0x752e627573090a3b,0x3333722509203233,0x3932337225202c30\n"
".quad 0x090a3b383231202c,0x09383109636f6c2e,0x6f6d090a30093432,0x2509203233732e76\n"
".quad 0x337225202c323472,0x2e646461090a3b30,0x3472250920323375,0x2c30337225202c33\n"
".quad 0x6f6d090a3b343220,0x2509203233752e76,0x635f5f202c343472,0x75635f5f5f616475\n"
".quad 0x6c757365725f6164,0x3233303134345f74,0x2e6c6873090a3b34,0x3372250920323362\n"
".quad 0x32337225202c3133,0x6f090a3b38202c36,0x2509203233622e72,0x7225202c32333372\n"
".quad 0x31322d202c313333,0x3834363338343734,0x752e766f6d090a3b,0x3734722509203233\n"
".quad 0x744c240a3b30202c,0x39363634315f315f,0x6172702e090a3a30,0x756f6e2220616d67\n"
".quad 0x0a3b226c6c6f726e,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x73656e202c343220,0x70656420676e6974,0x69202c31203a6874,0x6e6f697461726574\n"
".quad 0x6c2e090a36203a73,0x343109383109636f,0x646c090a30093031,0x752e74736e6f632e\n"
".quad 0x3834722509203233,0x2b323472255b202c,0x6c756d090a3b5d30,0x203233752e6f6c2e\n"
".quad 0x202c333333722509,0x7225202c38347225,0x6461090a3b323333,0x2509203233752e64\n"
".quad 0x7225202c34333372,0x347225202c333333,0x636f6c2e090a3b37,0x3131343109383109\n"
".quad 0x2e746573090a3009,0x752e3233752e7467,0x3333722509203233,0x3333337225202c35\n"
".quad 0x3b3433337225202c,0x33732e67656e090a,0x3633337225092032,0x3b3533337225202c\n"
".quad 0x69682e6c756d090a,0x722509203233752e,0x347225202c373333,0x3233337225202c38\n"
".quad 0x752e646461090a3b,0x3734722509203233,0x2c3633337225202c,0x0a3b373333722520\n"
".quad 0x383109636f6c2e09,0x0a30093231343109,0x61636f6c2e747309,0x5b09203233752e6c\n"
".quad 0x2c5d302b34347225,0x0a3b343333722520,0x3233752e64646109,0x202c343472250920\n"
".quad 0x3b34202c34347225,0x33752e646461090a,0x2c32347225092032,0x34202c3234722520\n"
".quad 0x2e70746573090a3b,0x09203233752e656e,0x7225202c37357025,0x33347225202c3234\n"
".quad 0x3735702540090a3b,0x4c24092061726220,0x363634315f315f74,0x3c2f2f200a3b3039\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930\n"
".quad 0x3134310938310963,0x2e7473090a300934,0x33752e6c61636f6c,0x75635f5f5b092032\n"
".quad 0x6475635f5f5f6164,0x746c757365725f61,0x343233303134345f,0x7225202c5d34322b\n"
".quad 0x6f6c2e090a3b3734,0x3134310938310963,0x726873090a300939,0x722509203233752e\n"
".quad 0x337225202c383333,0x090a3b35202c3033,0x752e6f6c2e6c756d,0x3333722509203233\n"
".quad 0x3833337225202c39,0x7573090a3b34202c,0x2509203233752e62,0x337225202c363572\n"
".quad 0x3933337225202c33,0x6f6c2e646c090a3b,0x203233752e6c6163,0x5b202c3734722509\n"
".quad 0x5d34322b36357225,0x09636f6c2e090a3b,0x0930323431093831,0x6f6c2e646c090a30\n"
".quad 0x203233752e6c6163,0x5b202c3735722509,0x5d30322b36357225,0x622e646e61090a3b\n"
".quad 0x3433722509203233,0x3033337225202c30,0x6d090a3b3133202c,0x09203233752e766f\n"
".quad 0x30202c3134337225,0x2e70746573090a3b,0x09203233752e7165,0x7225202c38357025\n"
".quad 0x337225202c303433,0x702540090a3b3134,0x0920617262203835,0x34315f315f744c24\n"
".quad 0x2f200a3b32303237,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x2e090a3039303132,0x3109383109636f6c,0x6d090a3009333234,0x09203233732e766f\n"
".quad 0x33202c3234337225,0x2e627573090a3b32,0x3372250920323373,0x34337225202c3334\n"
".quad 0x3034337225202c32,0x752e726873090a3b,0x3433722509203233,0x2c37357225202c34\n"
".quad 0x0a3b333433722520,0x3233622e6c687309,0x2c35343372250920,0x25202c3734722520\n"
".quad 0x61090a3b30343372,0x09203233752e6464,0x7225202c37347225,0x337225202c343433\n"
".quad 0x6f6c2e090a3b3534,0x3234310938310963,0x2e646c090a300934,0x33752e6c61636f6c\n"
".quad 0x3634337225092032,0x2b363572255b202c,0x6873090a3b5d3631,0x2509203233752e72\n"
".quad 0x7225202c37343372,0x337225202c363433,0x6c6873090a3b3334,0x722509203233622e\n"
".quad 0x357225202c383433,0x3034337225202c37,0x752e646461090a3b,0x3735722509203233\n"
".quad 0x2c3734337225202c,0x0a3b383433722520,0x34315f315f744c24,0x2f200a3a32303237\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132\n"
".quad 0x3109383109636f6c,0x73090a3009363234,0x09203233752e7268,0x7225202c37367225\n"
".quad 0x0a3b3033202c3734,0x383109636f6c2e09,0x0a30093832343109,0x3233752e72687309\n"
".quad 0x2c39343372250920,0x33202c3735722520,0x2e6c6873090a3b30,0x3372250920323362\n"
".quad 0x37347225202c3035,0x6461090a3b32202c,0x2509203233752e64,0x337225202c373472\n"
".quad 0x35337225202c3934,0x636f6c2e090a3b30,0x3932343109383109,0x2e6c6873090a3009\n"
".quad 0x3572250920323362,0x2c37357225202c37,0x766f6d090a3b3220,0x722509203233752e\n"
".quad 0x0a3b30202c313533,0x71652e7074657309,0x702509203233752e,0x37357225202c3935\n"
".quad 0x3b3135337225202c,0x203935702540090a,0x744c240920617262,0x37393734315f315f\n"
".quad 0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3033343109383109,0x2e646461090a3009,0x3372250920323375\n"
".quad 0x37347225202c3235,0x6f6d090a3b31202c,0x2509203233752e76,0x322d202c33353372\n"
".quad 0x3436333834373431,0x2e746573090a3b38,0x752e3233752e7467,0x3533722509203233\n"
".quad 0x3235337225202c34,0x3b3335337225202c,0x33732e67656e090a,0x3535337225092032\n"
".quad 0x3b3435337225202c,0x6e752e617262090a,0x315f744c24092069,0x3b3431373734315f\n"
".quad 0x315f315f744c240a,0x200a3a3037393734,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x203233752e766f6d,0x202c363533722509\n"
".quad 0x333834373431322d,0x6573090a3b383436,0x3233752e74672e74,0x722509203233752e\n"
".quad 0x347225202c373533,0x3635337225202c37,0x732e67656e090a3b,0x3533722509203233\n"
".quad 0x3735337225202c35,0x5f315f744c240a3b,0x0a3a343137373431,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09\n"
".quad 0x0a30093133343109,0x3233752e64646109,0x2c38353372250920,0x25202c3736722520\n"
".quad 0x2e090a3b35353372,0x3109383109636f6c,0x6e090a3009303334,0x09203233732e6765\n"
".quad 0x25202c3935337225,0x6d090a3b38353372,0x09203233752e766f,0x30202c3036337225\n"
".quad 0x2e70746573090a3b,0x09203233752e656e,0x7225202c30367025,0x337225202c373233\n"
".quad 0x6c6573090a3b3036,0x2509203233732e70,0x337225202c373672,0x35337225202c3935\n"
".quad 0x3b30367025202c38,0x33752e766f6d090a,0x3136337225092032,0x6573090a3b30202c\n"
".quad 0x33752e71652e7074,0x2c31367025092032,0x202c353533722520,0x090a3b3136337225\n"
".quad 0x7262203136702540,0x315f744c24092061,0x3b3632323834315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a\n"
".quad 0x3009363334310938,0x33732e67656e090a,0x2c37357225092032,0x090a3b3735722520\n"
".quad 0x09383109636f6c2e,0x090a300938333431,0x203233752e766f6d,0x202c323633722509\n"
".quad 0x2e746573090a3b30,0x752e3233752e7165,0x3633722509203233,0x2c37357225202c33\n"
".quad 0x0a3b323633722520,0x3233732e67656e09,0x2c34363372250920,0x0a3b333633722520\n"
".quad 0x3233622e746f6e09,0x2c35363372250920,0x090a3b3734722520,0x203233752e646461\n"
".quad 0x25202c3734722509,0x7225202c34363372,0x6c2e090a3b353633,0x343109383109636f\n"
".quad 0x6f78090a30093933,0x2509203233622e72,0x337225202c383372,0x3431322d202c3732\n"
".quad 0x3b38343633383437,0x315f315f744c240a,0x200a3a3632323834,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e\n"
".quad 0x090a300931343431,0x203233732e766f6d,0x25202c3538722509,0x6f6d090a3b373672\n"
".quad 0x2509203233752e76,0x3b30202c36363372,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x347225202c323670,0x3636337225202c37,0x3236702540090a3b,0x4c24092061726220\n"
".quad 0x323138315f315f74,0x3c2f2f200a3b3035,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x766f6d090a303930,0x722509203233752e,0x240a3b30202c3738\n"
".quad 0x3934315f315f744c,0x2f2f200a3a303532,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x343120656e696c20,0x7473656e202c3134,0x7470656420676e69,0x7365202c31203a68\n"
".quad 0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f\n"
".quad 0x3434310938310963,0x726873090a300935,0x722509203233752e,0x357225202c373633\n"
".quad 0x090a3b3133202c37,0x203233622e6c6873,0x202c383633722509,0x3b31202c37347225\n"
".quad 0x33752e646461090a,0x2c37347225092032,0x202c373633722520,0x090a3b3836337225\n"
".quad 0x09383109636f6c2e,0x090a300936343431,0x203233622e6c6873,0x25202c3735722509\n"
".quad 0x0a3b31202c373572,0x383109636f6c2e09,0x0a30093734343109,0x3233752e62757309\n"
".quad 0x202c373872250920,0x3b31202c37387225,0x33752e766f6d090a,0x3936337225092032\n"
".quad 0x6573090a3b30202c,0x33732e74672e7074,0x2c33367025092032,0x25202c3734722520\n"
".quad 0x40090a3b39363372,0x6172622033367025,0x5f315f744c240920,0x0a3b303532393431\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x696e752e61726209,0x5f315f744c240920,0x0a3b383337383431,0x38315f315f744c24\n"
".quad 0x2f200a3a30353231,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x6d090a3039303132,0x09203233752e766f,0x3b30202c37387225,0x315f315f744c240a\n"
".quad 0x200a3a3833373834,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a303930313231,0x09383109636f6c2e,0x090a300939343431,0x752e6f6c2e6c756d\n"
".quad 0x3735722509203233,0x202c37347225202c,0x383730373132392d,0x6f6c2e090a3b3037\n"
".quad 0x3534310938310963,0x766f6d090a300930,0x722509203233752e,0x32392d202c303733\n"
".quad 0x3b30373837303731,0x69682e6c756d090a,0x722509203233752e,0x37347225202c3734\n"
".quad 0x3b3037337225202c,0x33752e766f6d090a,0x3137337225092032,0x6573090a3b30202c\n"
".quad 0x33732e656c2e7074,0x2c34367025092032,0x25202c3734722520,0x40090a3b31373372\n"
".quad 0x6172622034367025,0x5f315f744c240920,0x0a3b323637393431,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09\n"
".quad 0x0a30093235343109,0x3233752e72687309,0x2c32373372250920,0x33202c3735722520\n"
".quad 0x2e6c6873090a3b31,0x3372250920323362,0x37347225202c3337,0x6461090a3b31202c\n"
".quad 0x2509203233752e64,0x337225202c373472,0x37337225202c3237,0x636f6c2e090a3b33\n"
".quad 0x3335343109383109,0x2e6c6873090a3009,0x3572250920323362,0x2c37357225202c37\n"
".quad 0x6f6c2e090a3b3120,0x3534310938310963,0x627573090a300934,0x722509203233752e\n"
".quad 0x37387225202c3738,0x744c240a3b31202c,0x36373934315f315f,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039\n"
".quad 0x3635343109383109,0x2e766f6d090a3009,0x3372250920323375,0x090a3b30202c3437\n"
".quad 0x752e656e2e746573,0x09203233752e3233,0x25202c3537337225,0x337225202c373572\n"
".quad 0x67656e090a3b3437,0x722509203233732e,0x337225202c363733,0x646461090a3b3537\n"
".quad 0x722509203233752e,0x37337225202c3734,0x3b37347225202c36,0x3109636f6c2e090a\n"
".quad 0x3009383534310938,0x33622e6c6873090a,0x3737337225092032,0x202c37347225202c\n"
".quad 0x766f6d090a3b3432,0x722509203233732e,0x0a3b30202c383733,0x2e746c2e74657309\n"
".quad 0x203233732e323375,0x202c393733722509,0x25202c3737337225,0x6e090a3b38373372\n"
".quad 0x09203233732e6765,0x25202c3038337225,0x73090a3b39373372,0x09203233752e7268\n"
".quad 0x25202c3138337225,0x0a3b38202c373472,0x3233752e64646109,0x2c32383372250920\n"
".quad 0x31202c3738722520,0x6c6873090a3b3632,0x722509203233622e,0x337225202c333833\n"
".quad 0x0a3b3332202c3238,0x3233752e64646109,0x2c34383372250920,0x202c313833722520\n"
".quad 0x090a3b3338337225,0x203233752e646461,0x202c353833722509,0x25202c3038337225\n"
".quad 0x6f090a3b34383372,0x2509203233622e72,0x7225202c36383372,0x38337225202c3833\n"
".quad 0x2e766f6d090a3b35,0x3166250920323362,0x3638337225202c38,0x752e617262090a3b\n"
".quad 0x57444c240920696e,0x695f5f5f69646e65,0x5f6c616e7265746e,0x3837315f64616d66\n"
".quad 0x744c240a3b32325f,0x36363534315f315f,0x6c3c2f2f200a3a36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039,0x3036343109383109\n"
".quad 0x2e766f6d090a3009,0x3166250920323366,0x66336630202c3736,0x203b333839663232\n"
".quad 0x2e30202f2f092020,0x6d090a3236363336,0x09203233662e6c75,0x25202c3836316625\n"
".quad 0x6625202c31363166,0x7663090a3b373631,0x33732e696e722e74,0x2509203233662e32\n"
".quad 0x6625202c37383372,0x6c2e090a3b383631,0x343109383109636f,0x7663090a30093536\n"
".quad 0x3233662e6e722e74,0x662509203233732e,0x337225202c393631,0x67656e090a3b3738\n"
".quad 0x662509203233662e,0x316625202c303731,0x766f6d090a3b3936,0x662509203233662e\n"
".quad 0x336630202c313731,0x3b30326161646639,0x30202f2f09202020,0x383338343030302e\n"
".quad 0x2e766f6d090a3732,0x3166250920323366,0x66336630202c3237,0x203b303030303963\n"
".quad 0x2e31202f2f092020,0x66090a3133303735,0x33662e6e722e616d,0x3337316625092032\n"
".quad 0x2c3037316625202c,0x202c323731662520,0x090a3b3136316625,0x662e6e722e616d66\n"
".quad 0x3731662509203233,0x3037316625202c34,0x2c3137316625202c,0x0a3b333731662520\n"
".quad 0x383109636f6c2e09,0x0a30093137343109,0x3233732e766f6d09,0x202c353872250920\n"
".quad 0x090a3b3738337225,0x09383109636f6c2e,0x090a300932373431,0x203233662e766f6d\n"
".quad 0x202c353731662509,0x3361353865326630,0x2f092020203b3930,0x313737302e36202f\n"
".quad 0x6d66090a31312d65,0x3233662e6e722e61,0x202c383166250920,0x25202c3037316625\n"
".quad 0x6625202c35373166,0x444c240a3b343731,0x5f5f5f69646e6557,0x6c616e7265746e69\n"
".quad 0x37315f64616d665f,0x2f200a3a32325f38,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c,0x61090a3009353037\n"
".quad 0x09203233732e6464,0x25202c3930317225,0x0a3b31202c353872,0x3233662e766f6d09\n"
".quad 0x2c36373166250920,0x090a3b3831662520,0x203233662e6c756d,0x25202c3932662509\n"
".quad 0x6625202c36373166,0x6e61090a3b363731,0x2509203233622e64,0x7225202c38383372\n"
".quad 0x0a3b31202c393031,0x3233752e766f6d09,0x2c39383372250920,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c353670250920,0x25202c3838337225,0x40090a3b39383372\n"
".quad 0x6172622035367025,0x5f315f744c240920,0x0a3b303335303531,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09\n"
".quad 0x0a30093930373109,0x3233662e766f6d09,0x2c37373166250920,0x6663633733663020\n"
".quad 0x092020203b656335,0x3334342e32202f2f,0x090a35302d653233,0x203233662e766f6d\n"
".quad 0x202c383731662509,0x3630366261626630,0x2f092020203b6131,0x3130302e302d202f\n"
".quad 0x66090a3337383833,0x33662e6e722e616d,0x3937316625092032,0x2c3737316625202c\n"
".quad 0x25202c3932662520,0x6d090a3b38373166,0x09203233662e766f,0x30202c3038316625\n"
".quad 0x6161616132643366,0x2f2f092020203b35,0x36363134302e3020,0x2e616d66090a3636\n"
".quad 0x09203233662e6e72,0x25202c3138316625,0x6625202c39373166,0x38316625202c3932\n"
".quad 0x2e766f6d090a3b30,0x3166250920323366,0x66626630202c3238,0x203b303030303030\n"
".quad 0x302d202f2f092020,0x2e616d66090a352e,0x09203233662e6e72,0x25202c3338316625\n"
".quad 0x6625202c31383166,0x38316625202c3932,0x2e766f6d090a3b32,0x3166250920323366\n"
".quad 0x66336630202c3438,0x203b303030303038,0x0a31202f2f092020,0x2e6e722e616d6609\n"
".quad 0x3366250920323366,0x3338316625202c38,0x202c39326625202c,0x090a3b3438316625\n"
".quad 0x20696e752e617262,0x315f315f744c2409,0x240a3b3437323035,0x3035315f315f744c\n"
".quad 0x2f2f200a3a303335,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6c2e090a30393031,0x373109383109636f,0x6f6d090a30093131,0x2509203233662e76\n"
".quad 0x6630202c35383166,0x3966316163343962,0x202f2f092020203b,0x39313030302e302d\n"
".quad 0x6f6d090a33353135,0x2509203233662e76,0x6630202c36383166,0x6539333838306333\n"
".quad 0x202f2f092020203b,0x3233333830302e30,0x2e616d66090a3631,0x09203233662e6e72\n"
".quad 0x25202c3738316625,0x6625202c35383166,0x38316625202c3932,0x2e766f6d090a3b36\n"
".quad 0x3166250920323366,0x65626630202c3838,0x203b336161616132,0x302d202f2f092020\n"
".quad 0x0a3736363636312e,0x2e6e722e616d6609,0x3166250920323366,0x38316625202c3938\n"
".quad 0x2c39326625202c37,0x0a3b383831662520,0x3233662e6c756d09,0x2c30393166250920\n"
".quad 0x25202c3932662520,0x66090a3b39383166,0x33662e6e722e616d,0x2c38336625092032\n"
".quad 0x202c303931662520,0x25202c3637316625,0x4c240a3b36373166,0x323035315f315f74\n"
".quad 0x3c2f2f200a3a3437,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3137310938310963,0x67656e090a300933,0x662509203233662e\n"
".quad 0x336625202c313931,0x2e646e61090a3b38,0x3372250920323362,0x30317225202c3039\n"
".quad 0x6d090a3b32202c39,0x09203233732e766f,0x30202c3139337225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c36367025,0x337225202c303933,0x6c6573090a3b3139\n"
".quad 0x2509203233662e70,0x316625202c383366,0x38336625202c3139,0x0a3b36367025202c\n"
".quad 0x383109636f6c2e09,0x0a30093631373109,0x3233662e766f6d09,0x2c35363166250920\n"
".quad 0x240a3b3833662520,0x5f69646e6557444c,0x66666e6973695f5f,0x3a31325f3837315f\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31\n"
".quad 0x3109636f6c2e090a,0x3009383336310938,0x732e706c6573090a,0x3933722509203233\n"
".quad 0x2c30202c31202c32,0x090a3b3535702520,0x203233662e766f6d,0x202c323931662509\n"
".quad 0x3030303030306630,0x2f092020203b3030,0x746573090a30202f,0x2e3233752e71652e\n"
".quad 0x3372250920323366,0x36316625202c3339,0x3239316625202c31,0x732e67656e090a3b\n"
".quad 0x3933722509203233,0x3339337225202c34,0x33622e726f090a3b,0x3539337225092032\n"
".quad 0x2c3239337225202c,0x0a3b343933722520,0x3233752e766f6d09,0x2c36393372250920\n"
".quad 0x746573090a3b3020,0x3233732e71652e70,0x202c373670250920,0x25202c3539337225\n"
".quad 0x40090a3b36393372,0x6172622037367025,0x5f315f744c240920,0x0a3b363837303531\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093933363109,0x3233662e766f6d09,0x2c33393166250920\n"
".quad 0x3030303030663020,0x092020203b303030,0x756d090a30202f2f,0x3233662e6e722e6c\n"
".quad 0x202c383466250920,0x25202c3136316625,0x62090a3b33393166,0x0920696e752e6172\n"
".quad 0x69646e6557444c24,0x666e6973695f5f5f,0x37315f3837315f66,0x5f315f744c240a3b\n"
".quad 0x0a3a363837303531,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c\n"
".quad 0x0a3039303132315f,0x3233662e766f6d09,0x2c34393166250920,0x6162333734663020\n"
".quad 0x092020203b303037,0x3933303834202f2f,0x672e70746573090a,0x2509203233662e74\n"
".quad 0x316625202c383670,0x39316625202c3236,0x70252140090a3b34,0x0920617262203836\n"
".quad 0x35315f315f744c24,0x2f200a3b38393231,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c,0x6d090a3009363933\n"
".quad 0x09203233622e766f,0x25202c3739337225,0x61090a3b31363166,0x09203233622e646e\n"
".quad 0x25202c3732337225,0x322d202c37393372,0x3436333834373431,0x2e766f6d090a3b38\n"
".quad 0x3172250920323373,0x32337225202c3032,0x636f6c2e090a3b37,0x3230343109383109\n"
".quad 0x2e6c6873090a3009,0x3372250920323362,0x39337225202c3839,0x73090a3b31202c37\n"
".quad 0x09203233752e7268,0x25202c3939337225,0x3432202c38393372,0x752e627573090a3b\n"
".quad 0x3333722509203233,0x3939337225202c30,0x090a3b383231202c,0x09383109636f6c2e\n"
".quad 0x6f6d090a30093432,0x2509203233732e76,0x7225202c33323172,0x646461090a3b3033\n"
".quad 0x722509203233752e,0x30337225202c3334,0x6d090a3b3432202c,0x09203233752e766f\n"
".quad 0x5f202c3432317225,0x5f5f5f616475635f,0x7365725f61647563,0x303136315f746c75\n"
".quad 0x6873090a3b363932,0x2509203233622e6c,0x7225202c30303472,0x0a3b38202c373933\n"
".quad 0x203233622e726f09,0x202c323333722509,0x2d202c3030347225,0x3633383437343132\n"
".quad 0x766f6d090a3b3834,0x722509203233752e,0x0a3b30202c363231,0x35315f315f744c24\n"
".quad 0x2e090a3a32323332,0x2220616d67617270,0x6c6c6f726e756f6e,0x6c3c2f2f200a3b22\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x202c343220656e69,0x20676e697473656e\n"
".quad 0x31203a6874706564,0x746172657469202c,0x0a36203a736e6f69,0x383109636f6c2e09\n"
".quad 0x0a30093031343109,0x736e6f632e646c09,0x2509203233752e74,0x255b202c37323172\n"
".quad 0x3b5d302b33323172,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c313034\n"
".quad 0x33337225202c3732,0x2e646461090a3b32,0x3472250920323375,0x30347225202c3230\n"
".quad 0x3632317225202c31,0x09636f6c2e090a3b,0x0931313431093831,0x672e746573090a30\n"
".quad 0x33752e3233752e74,0x3330347225092032,0x2c3130347225202c,0x0a3b323034722520\n"
".quad 0x3233732e67656e09,0x2c34303472250920,0x0a3b333034722520,0x2e69682e6c756d09\n"
".quad 0x3472250920323375,0x32317225202c3530,0x3233337225202c37,0x752e646461090a3b\n"
".quad 0x3231722509203233,0x3430347225202c36,0x3b3530347225202c,0x3109636f6c2e090a\n"
".quad 0x3009323134310938,0x636f6c2e7473090a,0x09203233752e6c61,0x302b34323172255b\n"
".quad 0x3230347225202c5d,0x752e646461090a3b,0x3231722509203233,0x3432317225202c34\n"
".quad 0x6461090a3b34202c,0x2509203233752e64,0x7225202c33323172,0x0a3b34202c333231\n"
".quad 0x656e2e7074657309,0x702509203233752e,0x32317225202c3936,0x3b33347225202c33\n"
".quad 0x203936702540090a,0x744c240920617262,0x32333235315f315f,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039\n"
".quad 0x3431343109383109,0x6c2e7473090a3009,0x3233752e6c61636f,0x6475635f5f5b0920\n"
".quad 0x616475635f5f5f61,0x5f746c757365725f,0x2b36393230313631,0x317225202c5d3432\n"
".quad 0x6f6c2e090a3b3632,0x3134310938310963,0x726873090a300939,0x722509203233752e\n"
".quad 0x337225202c363034,0x090a3b35202c3033,0x752e6f6c2e6c756d,0x3034722509203233\n"
".quad 0x3630347225202c37,0x7573090a3b34202c,0x2509203233752e62,0x7225202c35333172\n"
".quad 0x30347225202c3233,0x6c2e646c090a3b37,0x3233752e6c61636f,0x2c36323172250920\n"
".quad 0x2b35333172255b20,0x6c2e090a3b5d3432,0x343109383109636f,0x646c090a30093032\n"
".quad 0x752e6c61636f6c2e,0x3331722509203233,0x333172255b202c36,0x090a3b5d30322b35\n"
".quad 0x203233622e646e61,0x202c303433722509,0x33202c3033337225,0x2e766f6d090a3b31\n"
".quad 0x3472250920323375,0x090a3b30202c3830,0x2e71652e70746573,0x3770250920323375\n"
".quad 0x3034337225202c30,0x3b3830347225202c,0x203037702540090a,0x744c240920617262\n"
".quad 0x33383235315f315f,0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x636f6c2e090a3039,0x3332343109383109,0x2e766f6d090a3009\n"
".quad 0x3472250920323373,0x0a3b3233202c3930,0x3233732e62757309,0x2c30313472250920\n"
".quad 0x202c393034722520,0x090a3b3034337225,0x203233752e726873,0x202c313134722509\n"
".quad 0x25202c3633317225,0x73090a3b30313472,0x09203233622e6c68,0x25202c3231347225\n"
".quad 0x7225202c36323172,0x6461090a3b303433,0x2509203233752e64,0x7225202c36323172\n"
".quad 0x347225202c313134,0x6f6c2e090a3b3231,0x3234310938310963,0x2e646c090a300934\n"
".quad 0x33752e6c61636f6c,0x3331347225092032,0x35333172255b202c,0x73090a3b5d36312b\n"
".quad 0x09203233752e7268,0x25202c3431347225,0x7225202c33313472,0x6873090a3b303134\n"
".quad 0x2509203233622e6c,0x7225202c35313472,0x337225202c363331,0x646461090a3b3034\n"
".quad 0x722509203233752e,0x347225202c363331,0x31347225202c3431,0x315f744c240a3b35\n"
".quad 0x3a3433383235315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009363234310938,0x33752e726873090a\n"
".quad 0x3534317225092032,0x2c3632317225202c,0x6c2e090a3b303320,0x343109383109636f\n"
".quad 0x6873090a30093832,0x2509203233752e72,0x7225202c36313472,0x3b3033202c363331\n"
".quad 0x33622e6c6873090a,0x3731347225092032,0x2c3632317225202c,0x646461090a3b3220\n"
".quad 0x722509203233752e,0x347225202c363231,0x31347225202c3631,0x636f6c2e090a3b37\n"
".quad 0x3932343109383109,0x2e6c6873090a3009,0x3172250920323362,0x33317225202c3633\n"
".quad 0x6d090a3b32202c36,0x09203233752e766f,0x30202c3831347225,0x2e70746573090a3b\n"
".quad 0x09203233752e7165,0x7225202c31377025,0x347225202c363331,0x702540090a3b3831\n"
".quad 0x0920617262203137,0x35315f315f744c24,0x2f200a3b32303633,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037\n"
".quad 0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c\n"
".quad 0x61090a3009303334,0x09203233752e6464,0x25202c3931347225,0x3b31202c36323172\n"
".quad 0x33752e766f6d090a,0x3032347225092032,0x34373431322d202c,0x090a3b3834363338\n"
".quad 0x752e74672e746573,0x09203233752e3233,0x25202c3132347225,0x7225202c39313472\n"
".quad 0x656e090a3b303234,0x2509203233732e67,0x7225202c32323472,0x7262090a3b313234\n"
".quad 0x240920696e752e61,0x3335315f315f744c,0x744c240a3b363433,0x30363335315f315f\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x2e766f6d090a3039,0x3472250920323375,0x3431322d202c3332,0x3b38343633383437\n"
".quad 0x74672e746573090a,0x3233752e3233752e,0x2c34323472250920,0x202c363231722520\n"
".quad 0x090a3b3332347225,0x203233732e67656e,0x202c323234722509,0x240a3b3432347225\n"
".quad 0x3335315f315f744c,0x2f2f200a3a363433,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f,0x6461090a30093133\n"
".quad 0x2509203233752e64,0x7225202c35323472,0x347225202c353431,0x6f6c2e090a3b3232\n"
".quad 0x3334310938310963,0x67656e090a300930,0x722509203233732e,0x347225202c363234\n"
".quad 0x766f6d090a3b3532,0x722509203233752e,0x0a3b30202c373234,0x656e2e7074657309\n"
".quad 0x702509203233752e,0x32337225202c3237,0x3732347225202c37,0x2e706c6573090a3b\n"
".quad 0x3172250920323373,0x32347225202c3534,0x3532347225202c36,0x0a3b32377025202c\n"
".quad 0x3233752e766f6d09,0x2c38323472250920,0x746573090a3b3020,0x3233752e71652e70\n"
".quad 0x202c333770250920,0x25202c3232347225,0x40090a3b38323472,0x6172622033377025\n"
".quad 0x5f315f744c240920,0x0a3b383538333531,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093633343109\n"
".quad 0x3233732e67656e09,0x2c36333172250920,0x0a3b363331722520,0x383109636f6c2e09\n"
".quad 0x0a30093833343109,0x3233752e766f6d09,0x2c39323472250920,0x746573090a3b3020\n"
".quad 0x2e3233752e71652e,0x3472250920323375,0x33317225202c3033,0x3932347225202c36\n"
".quad 0x732e67656e090a3b,0x3334722509203233,0x3033347225202c31,0x622e746f6e090a3b\n"
".quad 0x3334722509203233,0x3632317225202c32,0x752e646461090a3b,0x3231722509203233\n"
".quad 0x3133347225202c36,0x3b3233347225202c,0x3109636f6c2e090a,0x3009393334310938\n"
".quad 0x33622e726f78090a,0x3032317225092032,0x2c3732337225202c,0x3834373431322d20\n"
".quad 0x4c240a3b38343633,0x383335315f315f74,0x3c2f2f200a3a3835,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930,0x3434310938310963\n"
".quad 0x766f6d090a300931,0x722509203233732e,0x317225202c333631,0x766f6d090a3b3534\n"
".quad 0x722509203233752e,0x0a3b30202c333334,0x656c2e7074657309,0x702509203233732e\n"
".quad 0x32317225202c3437,0x3333347225202c36,0x3437702540090a3b,0x4c24092061726220\n"
".quad 0x353138315f315f74,0x3c2f2f200a3b3630,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x766f6d090a303930,0x722509203233752e,0x0a3b30202c353631\n"
".quad 0x35315f315f744c24,0x2f200a3a32383834,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3120656e696c2079,0x73656e202c313434,0x70656420676e6974,0x65202c31203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e\n"
".quad 0x343109383109636f,0x6873090a30093534,0x2509203233752e72,0x7225202c34333472\n"
".quad 0x3b3133202c363331,0x33622e6c6873090a,0x3533347225092032,0x2c3632317225202c\n"
".quad 0x646461090a3b3120,0x722509203233752e,0x347225202c363231,0x33347225202c3433\n"
".quad 0x636f6c2e090a3b35,0x3634343109383109,0x2e6c6873090a3009,0x3172250920323362\n"
".quad 0x33317225202c3633,0x2e090a3b31202c36,0x3109383109636f6c,0x73090a3009373434\n"
".quad 0x09203233752e6275,0x25202c3536317225,0x3b31202c35363172,0x33752e766f6d090a\n"
".quad 0x3633347225092032,0x6573090a3b30202c,0x33732e74672e7074,0x2c35377025092032\n"
".quad 0x202c363231722520,0x090a3b3633347225,0x7262203537702540,0x315f744c24092061\n"
".quad 0x3b3238383435315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x6e752e617262090a,0x315f744c24092069,0x3b3037333435315f\n"
".quad 0x315f315f744c240a,0x200a3a3630353138,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x203233752e766f6d,0x202c353631722509\n"
".quad 0x315f744c240a3b30,0x3a3037333435315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a,0x3009393434310938\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c363331,0x3132392d202c3632\n"
".quad 0x0a3b303738373037,0x383109636f6c2e09,0x0a30093035343109,0x3233752e766f6d09\n"
".quad 0x2c37333472250920,0x3730373132392d20,0x756d090a3b303738,0x3233752e69682e6c\n"
".quad 0x2c36323172250920,0x202c363231722520,0x090a3b3733347225,0x203233752e766f6d\n"
".quad 0x202c383334722509,0x70746573090a3b30,0x203233732e656c2e,0x25202c3637702509\n"
".quad 0x7225202c36323172,0x2540090a3b383334,0x2061726220363770,0x315f315f744c2409\n"
".quad 0x200a3b3439333535,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a303930313231,0x09383109636f6c2e,0x090a300932353431,0x203233752e726873\n"
".quad 0x202c393334722509,0x33202c3633317225,0x2e6c6873090a3b31,0x3472250920323362\n"
".quad 0x32317225202c3034,0x61090a3b31202c36,0x09203233752e6464,0x25202c3632317225\n"
".quad 0x7225202c39333472,0x6c2e090a3b303434,0x343109383109636f,0x6873090a30093335\n"
".quad 0x2509203233622e6c,0x7225202c36333172,0x0a3b31202c363331,0x383109636f6c2e09\n"
".quad 0x0a30093435343109,0x3233752e62757309,0x2c35363172250920,0x202c353631722520\n"
".quad 0x315f744c240a3b31,0x3a3439333535315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a,0x3009363534310938\n"
".quad 0x33752e766f6d090a,0x3134347225092032,0x6573090a3b30202c,0x3233752e656e2e74\n"
".quad 0x722509203233752e,0x317225202c323434,0x34347225202c3633,0x2e67656e090a3b31\n"
".quad 0x3472250920323373,0x34347225202c3334,0x2e646461090a3b32,0x3172250920323375\n"
".quad 0x34347225202c3632,0x3632317225202c33,0x09636f6c2e090a3b,0x0938353431093831\n"
".quad 0x622e6c6873090a30,0x3434722509203233,0x3632317225202c34,0x6d090a3b3432202c\n"
".quad 0x09203233732e766f,0x30202c3534347225,0x6c2e746573090a3b,0x33732e3233752e74\n"
".quad 0x3634347225092032,0x2c3434347225202c,0x0a3b353434722520,0x3233732e67656e09\n"
".quad 0x2c37343472250920,0x0a3b363434722520,0x3233752e72687309,0x2c38343472250920\n"
".quad 0x202c363231722520,0x2e646461090a3b38,0x3472250920323375,0x36317225202c3934\n"
".quad 0x0a3b363231202c35,0x3233622e6c687309,0x2c30353472250920,0x202c393434722520\n"
".quad 0x646461090a3b3332,0x722509203233752e,0x347225202c313534,0x35347225202c3834\n"
".quad 0x2e646461090a3b30,0x3472250920323375,0x34347225202c3235,0x3135347225202c37\n"
".quad 0x33622e726f090a3b,0x3335347225092032,0x2c3032317225202c,0x0a3b323534722520\n"
".quad 0x3233622e766f6d09,0x202c303566250920,0x090a3b3335347225,0x20696e752e617262\n"
".quad 0x646e6557444c2409,0x65746e695f5f5f69,0x616d665f6c616e72,0x38315f3837315f64\n"
".quad 0x5f315f744c240a3b,0x0a3a383932313531,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093036343109\n"
".quad 0x3233662e766f6d09,0x2c35393166250920,0x6632326633663020,0x092020203b333839\n"
".quad 0x3633362e30202f2f,0x2e6c756d090a3236,0x3166250920323366,0x36316625202c3639\n"
".quad 0x3539316625202c31,0x722e747663090a3b,0x662e3233732e696e,0x3534722509203233\n"
".quad 0x3639316625202c34,0x09636f6c2e090a3b,0x0935363431093831,0x722e747663090a30\n"
".quad 0x33732e3233662e6e,0x3739316625092032,0x3b3435347225202c,0x33662e67656e090a\n"
".quad 0x3839316625092032,0x3b3739316625202c,0x33662e766f6d090a,0x3939316625092032\n"
".quad 0x646639336630202c,0x2020203b30326161,0x30302e30202f2f09,0x0a37323833383430\n"
".quad 0x3233662e766f6d09,0x2c30303266250920,0x3039636633663020,0x092020203b303030\n"
".quad 0x3037352e31202f2f,0x2e616d66090a3133,0x09203233662e6e72,0x25202c3130326625\n"
".quad 0x6625202c38393166,0x316625202c303032,0x616d66090a3b3136,0x203233662e6e722e\n"
".quad 0x202c323032662509,0x25202c3839316625,0x6625202c39393166,0x6c2e090a3b313032\n"
".quad 0x343109383109636f,0x6f6d090a30093137,0x2509203233732e76,0x7225202c33363172\n"
".quad 0x6c2e090a3b343534,0x343109383109636f,0x6f6d090a30093237,0x2509203233662e76\n"
".quad 0x6630202c33303266,0x3930336135386532,0x202f2f092020203b,0x2d65313737302e36\n"
".quad 0x2e616d66090a3131,0x09203233662e6e72,0x6625202c30356625,0x326625202c383931\n"
".quad 0x30326625202c3330,0x6557444c240a3b32,0x6e695f5f5f69646e,0x665f6c616e726574\n"
".quad 0x5f3837315f64616d,0x3c2f2f200a3a3831,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x6f6c2e090a303930,0x3436310938310963,0x766f6d090a300931\n"
".quad 0x662509203233662e,0x356625202c343032,0x2e6c756d090a3b30,0x3666250920323366\n"
".quad 0x3430326625202c31,0x3b3430326625202c,0x33622e646e61090a,0x3535347225092032\n"
".quad 0x2c3336317225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c363534\n"
".quad 0x71652e7074657309,0x702509203233732e,0x35347225202c3737,0x3635347225202c35\n"
".quad 0x3737702540090a3b,0x4c24092061726220,0x313635315f315f74,0x3c2f2f200a3b3236\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930\n"
".quad 0x3436310938310963,0x766f6d090a300934,0x662509203233662e,0x336630202c353032\n"
".quad 0x3b65633566636337,0x32202f2f09202020,0x2d6532333334342e,0x2e766f6d090a3530\n"
".quad 0x3266250920323366,0x61626630202c3630,0x203b613136303662,0x302d202f2f092020\n"
".quad 0x373838333130302e,0x722e616d66090a33,0x2509203233662e6e,0x6625202c37303266\n"
".quad 0x366625202c353032,0x3630326625202c31,0x662e766f6d090a3b,0x3032662509203233\n"
".quad 0x3264336630202c38,0x20203b3561616161,0x302e30202f2f0920,0x090a363636363134\n"
".quad 0x662e6e722e616d66,0x3032662509203233,0x3730326625202c39,0x202c31366625202c\n"
".quad 0x090a3b3830326625,0x203233662e766f6d,0x202c303132662509,0x3030303066626630\n"
".quad 0x2f092020203b3030,0x090a352e302d202f,0x662e6e722e616d66,0x3132662509203233\n"
".quad 0x3930326625202c31,0x202c31366625202c,0x090a3b3031326625,0x203233662e766f6d\n"
".quad 0x202c323132662509,0x3030303866336630,0x2f092020203b3030,0x616d66090a31202f\n"
".quad 0x203233662e6e722e,0x25202c3037662509,0x6625202c31313266,0x31326625202c3136\n"
".quad 0x2e617262090a3b32,0x744c240920696e75,0x30393535315f315f,0x315f744c240a3b36\n"
".quad 0x3a3236313635315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009363436310938,0x33662e766f6d090a\n"
".quad 0x3331326625092032,0x633439626630202c,0x2020203b39663161,0x302e302d202f2f09\n"
".quad 0x3335313539313030,0x33662e766f6d090a,0x3431326625092032,0x383063336630202c\n"
".quad 0x2020203b65393338,0x30302e30202f2f09,0x090a363132333338,0x662e6e722e616d66\n"
".quad 0x3132662509203233,0x3331326625202c35,0x202c31366625202c,0x090a3b3431326625\n"
".quad 0x203233662e766f6d,0x202c363132662509,0x6161613265626630,0x2f092020203b3361\n"
".quad 0x3636312e302d202f,0x616d66090a373636,0x203233662e6e722e,0x202c373132662509\n"
".quad 0x25202c3531326625,0x326625202c313666,0x6c756d090a3b3631,0x662509203233662e\n"
".quad 0x366625202c383132,0x3731326625202c31,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x326625202c303766,0x30326625202c3831,0x3430326625202c34,0x5f315f744c240a3b\n"
".quad 0x0a3a363039353531,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c\n"
".quad 0x0a3039303132315f,0x383109636f6c2e09,0x0a30093834363109,0x3233662e67656e09\n"
".quad 0x2c39313266250920,0x090a3b3037662520,0x203233622e646e61,0x202c373534722509\n"
".quad 0x32202c3336317225,0x732e766f6d090a3b,0x3534722509203233,0x73090a3b30202c38\n"
".quad 0x732e656e2e707465,0x3837702509203233,0x2c3735347225202c,0x0a3b383534722520\n"
".quad 0x33662e706c657309,0x2c30376625092032,0x202c393132662520,0x7025202c30376625\n"
".quad 0x6f6c2e090a3b3837,0x3536310938310963,0x766f6d090a300931,0x662509203233662e\n"
".quad 0x30376625202c3834,0x6e6557444c240a3b,0x6973695f5f5f6964,0x5f3837315f66666e\n"
".quad 0x3c2f2f200a3a3731,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x0938313109330963,0x6f632e646c090a30,0x203233662e74736e\n"
".quad 0x202c303232662509,0x36332b353372255b,0x632e646c090a3b5d,0x3233662e74736e6f\n"
".quad 0x2c31323266250920,0x332b353372255b20,0x6c756d090a3b5d32,0x662509203233662e\n"
".quad 0x346625202c323232,0x3032326625202c38,0x662e6c756d090a3b,0x3232662509203233\n"
".quad 0x3132326625202c33,0x3b3536316625202c,0x33662e627573090a,0x3432326625092032\n"
".quad 0x2c3332326625202c,0x0a3b323232662520,0x3233662e64646109,0x25202c3466250920\n"
".quad 0x32326625202c3466,0x636f6c2e090a3b34,0x3009393131093309,0x33662e6c756d090a\n"
".quad 0x3532326625092032,0x2c3536316625202c,0x0a3b303232662520,0x2e6e722e616d6609\n"
".quad 0x3266250920323366,0x32326625202c3632,0x2c38346625202c31,0x0a3b353232662520\n"
".quad 0x3233662e64646109,0x25202c3566250920,0x32326625202c3566,0x636f6c2e090a3b36\n"
".quad 0x3230373109383109,0x632e646c090a3009,0x3233662e74736e6f,0x2c37323266250920\n"
".quad 0x342b353372255b20,0x2e646c090a3b5d34,0x33662e74736e6f63,0x3832326625092032\n"
".quad 0x2b353372255b202c,0x646c090a3b5d3034,0x662e74736e6f632e,0x3232662509203233\n"
".quad 0x353372255b202c39,0x6d090a3b5d38342b,0x09203233662e6c75,0x25202c3033326625\n"
".quad 0x6625202c37323266,0x2e616d66090a3b32,0x09203233662e6e72,0x25202c3133326625\n"
".quad 0x6625202c38323266,0x3033326625202c31,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c32333266,0x336625202c393232,0x3b3133326625202c,0x36662e747663090a\n"
".quad 0x2509203233662e34,0x6625202c33316466,0x6f6d090a3b323332,0x2509203436662e76\n"
".quad 0x6430202c34316466,0x6266313239313034,0x3831643234343435,0x322e36202f2f093b\n"
".quad 0x756d090a39313338,0x2509203436662e6c,0x6625202c35316466,0x646625202c333164\n"
".quad 0x736261090a3b3431,0x662509203436662e,0x646625202c363164,0x747663090a3b3531\n"
".quad 0x2e3233662e6e722e,0x3266250920343666,0x31646625202c3333,0x2e747663090a3b35\n"
".quad 0x662e3233662e6e72,0x3332662509203436,0x3631646625202c34,0x662e766f6d090a3b\n"
".quad 0x3332662509203233,0x3866376630202c35,0x20203b3030303030,0x312828202f2f0920\n"
".quad 0x2e30282f2946302e,0x6573090a29294630,0x33662e71652e7074,0x2c39377025092032\n"
".quad 0x202c343332662520,0x090a3b3533326625,0x6220393770252140,0x5f744c2409206172\n"
".quad 0x3831343635315f31,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x39303132315f315f,0x09636f6c2e090a30,0x0933303731093831,0x662e67656e090a30\n"
".quad 0x3332662509203233,0x3333326625202c36,0x722e646461090a3b,0x2509203233662e6e\n"
".quad 0x6625202c37333266,0x326625202c333332,0x617262090a3b3633,0x4c240920696e752e\n"
".quad 0x5f5f69646e655744,0x5f66666e6973695f,0x0a3b33315f383731,0x35315f315f744c24\n"
".quad 0x2f200a3a38313436,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x6d090a3039303132,0x09203233662e766f,0x30202c3833326625,0x3037616233373466\n"
".quad 0x2f2f092020203b30,0x090a393330383420,0x2e74672e70746573,0x3870250920323366\n"
".quad 0x3433326625202c30,0x3b3833326625202c,0x303870252140090a,0x4c24092061726220\n"
".quad 0x393635315f315f74,0x3c2f2f200a3b3033,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x6f6c2e090a303930,0x3933310938310963,0x766f6d090a300936\n"
".quad 0x722509203233622e,0x326625202c393534,0x646e61090a3b3333,0x722509203233622e\n"
".quad 0x347225202c303634,0x3431322d202c3935,0x3b38343633383437,0x33732e766f6d090a\n"
".quad 0x2c38337225092032,0x0a3b303634722520,0x383109636f6c2e09,0x0a30093230343109\n"
".quad 0x3233622e6c687309,0x2c31363472250920,0x202c393534722520,0x2e726873090a3b31\n"
".quad 0x3472250920323375,0x36347225202c3236,0x090a3b3432202c31,0x203233752e627573\n"
".quad 0x202c333634722509,0x31202c3236347225,0x6f6c2e090a3b3832,0x0934320938310963\n"
".quad 0x732e766f6d090a30,0x3234722509203233,0x0a3b30337225202c,0x3233752e64646109\n"
".quad 0x202c333472250920,0x3432202c30337225,0x752e766f6d090a3b,0x3434722509203233\n"
".quad 0x616475635f5f202c,0x5f616475635f5f5f,0x345f746c75736572,0x0a3b343233303134\n"
".quad 0x3233622e6c687309,0x2c34363472250920,0x202c393534722520,0x622e726f090a3b38\n"
".quad 0x3634722509203233,0x3436347225202c35,0x34373431322d202c,0x090a3b3834363338\n"
".quad 0x203233752e766f6d,0x30202c3734722509,0x5f315f744c240a3b,0x0a3a343539373531\n"
".quad 0x616d676172702e09,0x6f726e756f6e2220,0x2f2f200a3b226c6c,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x343220656e696c20,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x72657469202c3120,0x203a736e6f697461,0x09636f6c2e090a36,0x0930313431093831\n"
".quad 0x6f632e646c090a30,0x203233752e74736e,0x5b202c3834722509,0x3b5d302b32347225\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x347225202c363634,0x3536347225202c38\n"
".quad 0x752e646461090a3b,0x3634722509203233,0x3636347225202c37,0x0a3b37347225202c\n"
".quad 0x383109636f6c2e09,0x0a30093131343109,0x2e74672e74657309,0x203233752e323375\n"
".quad 0x202c383634722509,0x25202c3636347225,0x6e090a3b37363472,0x09203233732e6765\n"
".quad 0x25202c3936347225,0x6d090a3b38363472,0x33752e69682e6c75,0x3037347225092032\n"
".quad 0x202c38347225202c,0x090a3b3536347225,0x203233752e646461,0x25202c3734722509\n"
".quad 0x7225202c39363472,0x6c2e090a3b303734,0x343109383109636f,0x7473090a30093231\n"
".quad 0x752e6c61636f6c2e,0x3472255b09203233,0x7225202c5d302b34,0x6461090a3b373634\n"
".quad 0x2509203233752e64,0x347225202c343472,0x61090a3b34202c34,0x09203233752e6464\n"
".quad 0x7225202c32347225,0x090a3b34202c3234,0x2e656e2e70746573,0x3870250920323375\n"
".quad 0x2c32347225202c31,0x090a3b3334722520,0x7262203138702540,0x315f744c24092061\n"
".quad 0x3b3435393735315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009343134310938,0x636f6c2e7473090a\n"
".quad 0x09203233752e6c61,0x5f616475635f5f5b,0x725f616475635f5f,0x34345f746c757365\n"
".quad 0x34322b3432333031,0x3b37347225202c5d,0x3109636f6c2e090a,0x3009393134310938\n"
".quad 0x33752e726873090a,0x3137347225092032,0x2c3336347225202c,0x6c756d090a3b3520\n"
".quad 0x203233752e6f6c2e,0x202c323734722509,0x34202c3137347225,0x752e627573090a3b\n"
".quad 0x3635722509203233,0x202c33337225202c,0x090a3b3237347225,0x6c61636f6c2e646c\n"
".quad 0x722509203233752e,0x3572255b202c3734,0x090a3b5d34322b36,0x09383109636f6c2e\n"
".quad 0x090a300930323431,0x6c61636f6c2e646c,0x722509203233752e,0x3572255b202c3735\n"
".quad 0x090a3b5d30322b36,0x203233622e646e61,0x202c333734722509,0x33202c3336347225\n"
".quad 0x2e766f6d090a3b31,0x3472250920323375,0x090a3b30202c3437,0x2e71652e70746573\n"
".quad 0x3870250920323375,0x3337347225202c32,0x3b3437347225202c,0x203238702540090a\n"
".quad 0x744c240920617262,0x36343835315f315f,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039,0x3332343109383109\n"
".quad 0x2e766f6d090a3009,0x3472250920323373,0x0a3b3233202c3537,0x3233732e62757309\n"
".quad 0x2c36373472250920,0x202c353734722520,0x090a3b3337347225,0x203233752e726873\n"
".quad 0x202c373734722509,0x7225202c37357225,0x6873090a3b363734,0x2509203233622e6c\n"
".quad 0x7225202c38373472,0x37347225202c3734,0x2e646461090a3b33,0x3472250920323375\n"
".quad 0x3737347225202c37,0x3b3837347225202c,0x3109636f6c2e090a,0x3009343234310938\n"
".quad 0x636f6c2e646c090a,0x09203233752e6c61,0x5b202c3937347225,0x5d36312b36357225\n"
".quad 0x752e726873090a3b,0x3834722509203233,0x3937347225202c30,0x3b3637347225202c\n"
".quad 0x33622e6c6873090a,0x3138347225092032,0x202c37357225202c,0x090a3b3337347225\n"
".quad 0x203233752e646461,0x25202c3735722509,0x7225202c30383472,0x744c240a3b313834\n"
".quad 0x36343835315f315f,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x636f6c2e090a3039,0x3632343109383109,0x2e726873090a3009\n"
".quad 0x3672250920323375,0x2c37347225202c37,0x6c2e090a3b303320,0x343109383109636f\n"
".quad 0x6873090a30093832,0x2509203233752e72,0x7225202c32383472,0x0a3b3033202c3735\n"
".quad 0x3233622e6c687309,0x2c33383472250920,0x32202c3734722520,0x752e646461090a3b\n"
".quad 0x3734722509203233,0x2c3238347225202c,0x0a3b333834722520,0x383109636f6c2e09\n"
".quad 0x0a30093932343109,0x3233622e6c687309,0x202c373572250920,0x3b32202c37357225\n"
".quad 0x33752e766f6d090a,0x3438347225092032,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x2c33387025092032,0x25202c3735722520,0x40090a3b34383472,0x6172622033387025\n"
".quad 0x5f315f744c240920,0x0a3b343332393531,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093033343109\n"
".quad 0x3233752e64646109,0x2c35383472250920,0x31202c3734722520,0x752e766f6d090a3b\n"
".quad 0x3834722509203233,0x373431322d202c36,0x0a3b383436333834,0x2e74672e74657309\n"
".quad 0x203233752e323375,0x202c373834722509,0x25202c3538347225,0x6e090a3b36383472\n"
".quad 0x09203233732e6765,0x25202c3838347225,0x62090a3b37383472,0x0920696e752e6172\n"
".quad 0x35315f315f744c24,0x4c240a3b38373938,0x323935315f315f74,0x3c2f2f200a3a3433\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x766f6d090a303930\n"
".quad 0x722509203233752e,0x31322d202c393834,0x3834363338343734,0x672e746573090a3b\n"
".quad 0x33752e3233752e74,0x3039347225092032,0x202c37347225202c,0x090a3b3938347225\n"
".quad 0x203233732e67656e,0x202c383834722509,0x240a3b3039347225,0x3835315f315f744c\n"
".quad 0x2f2f200a3a383739,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6c2e090a30393031,0x343109383109636f,0x6461090a30093133,0x2509203233752e64\n"
".quad 0x7225202c31393472,0x38347225202c3736,0x636f6c2e090a3b38,0x3033343109383109\n"
".quad 0x2e67656e090a3009,0x3472250920323373,0x39347225202c3239,0x2e766f6d090a3b31\n"
".quad 0x3472250920323375,0x090a3b30202c3339,0x2e656e2e70746573,0x3870250920323375\n"
".quad 0x3036347225202c34,0x3b3339347225202c,0x732e706c6573090a,0x3736722509203233\n"
".quad 0x2c3239347225202c,0x202c313934722520,0x6d090a3b34387025,0x09203233752e766f\n"
".quad 0x30202c3439347225,0x2e70746573090a3b,0x09203233752e7165,0x7225202c35387025\n"
".quad 0x347225202c383834,0x702540090a3b3439,0x0920617262203538,0x35315f315f744c24\n"
".quad 0x2f200a3b30393439,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064\n"
".quad 0x2e090a3039303132,0x3109383109636f6c,0x6e090a3009363334,0x09203233732e6765\n"
".quad 0x7225202c37357225,0x6f6c2e090a3b3735,0x3334310938310963,0x766f6d090a300938\n"
".quad 0x722509203233752e,0x0a3b30202c353934,0x2e71652e74657309,0x203233752e323375\n"
".quad 0x202c363934722509,0x7225202c37357225,0x656e090a3b353934,0x2509203233732e67\n"
".quad 0x7225202c37393472,0x6f6e090a3b363934,0x2509203233622e74,0x7225202c38393472\n"
".quad 0x646461090a3b3734,0x722509203233752e,0x39347225202c3734,0x3839347225202c37\n"
".quad 0x09636f6c2e090a3b,0x0939333431093831,0x622e726f78090a30,0x3833722509203233\n"
".quad 0x2c3036347225202c,0x3834373431322d20,0x4c240a3b38343633,0x343935315f315f74\n"
".quad 0x3c2f2f200a3a3039,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3434310938310963,0x766f6d090a300931,0x722509203233732e\n"
".quad 0x37367225202c3538,0x752e766f6d090a3b,0x3934722509203233,0x73090a3b30202c39\n"
".quad 0x732e656c2e707465,0x3638702509203233,0x202c37347225202c,0x090a3b3939347225\n"
".quad 0x7262203638702540,0x315f744c24092061,0x3b3236373138315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x33752e766f6d090a\n"
".quad 0x2c37387225092032,0x5f744c240a3b3020,0x3431353036315f31,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x2c3134343120656e,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x3009353434310938,0x33752e726873090a\n"
".quad 0x3030357225092032,0x202c37357225202c,0x6c6873090a3b3133,0x722509203233622e\n"
".quad 0x347225202c313035,0x61090a3b31202c37,0x09203233752e6464,0x7225202c37347225\n"
".quad 0x357225202c303035,0x6f6c2e090a3b3130,0x3434310938310963,0x6c6873090a300936\n"
".quad 0x722509203233622e,0x37357225202c3735,0x6c2e090a3b31202c,0x343109383109636f\n"
".quad 0x7573090a30093734,0x2509203233752e62,0x387225202c373872,0x6d090a3b31202c37\n"
".quad 0x09203233752e766f,0x30202c3230357225,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x7225202c37387025,0x30357225202c3734,0x38702540090a3b32,0x2409206172622037\n"
".quad 0x3036315f315f744c,0x2f2f200a3b343135,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x7262090a30393031,0x240920696e752e61,0x3036315f315f744c\n"
".quad 0x744c240a3b323030,0x36373138315f315f,0x6c3c2f2f200a3a32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x2e766f6d090a3039,0x3872250920323375\n"
".quad 0x4c240a3b30202c37,0x303036315f315f74,0x3c2f2f200a3a3230,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930,0x3434310938310963\n"
".quad 0x6c756d090a300939,0x203233752e6f6c2e,0x25202c3735722509,0x32392d202c373472\n"
".quad 0x3b30373837303731,0x3109636f6c2e090a,0x3009303534310938,0x33752e766f6d090a\n"
".quad 0x3330357225092032,0x30373132392d202c,0x6d090a3b30373837,0x33752e69682e6c75\n"
".quad 0x2c37347225092032,0x25202c3734722520,0x6d090a3b33303572,0x09203233752e766f\n"
".quad 0x30202c3430357225,0x2e70746573090a3b,0x09203233732e656c,0x7225202c38387025\n"
".quad 0x30357225202c3734,0x38702540090a3b34,0x2409206172622038,0x3136315f315f744c\n"
".quad 0x2f2f200a3b363230,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6c2e090a30393031,0x343109383109636f,0x6873090a30093235,0x2509203233752e72\n"
".quad 0x7225202c35303572,0x0a3b3133202c3735,0x3233622e6c687309,0x2c36303572250920\n"
".quad 0x31202c3734722520,0x752e646461090a3b,0x3734722509203233,0x2c3530357225202c\n"
".quad 0x0a3b363035722520,0x383109636f6c2e09,0x0a30093335343109,0x3233622e6c687309\n"
".quad 0x202c373572250920,0x3b31202c37357225,0x3109636f6c2e090a,0x3009343534310938\n"
".quad 0x33752e627573090a,0x2c37387225092032,0x31202c3738722520,0x5f315f744c240a3b\n"
".quad 0x0a3a363230313631,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c\n"
".quad 0x0a3039303132315f,0x383109636f6c2e09,0x0a30093635343109,0x3233752e766f6d09\n"
".quad 0x2c37303572250920,0x746573090a3b3020,0x2e3233752e656e2e,0x3572250920323375\n"
".quad 0x37357225202c3830,0x3b3730357225202c,0x33732e67656e090a,0x3930357225092032\n"
".quad 0x3b3830357225202c,0x33752e646461090a,0x2c37347225092032,0x202c393035722520\n"
".quad 0x2e090a3b37347225,0x3109383109636f6c,0x73090a3009383534,0x09203233622e6c68\n"
".quad 0x25202c3031357225,0x3b3432202c373472,0x33732e766f6d090a,0x3131357225092032\n"
".quad 0x6573090a3b30202c,0x3233752e746c2e74,0x722509203233732e,0x357225202c323135\n"
".quad 0x31357225202c3031,0x2e67656e090a3b31,0x3572250920323373,0x31357225202c3331\n"
".quad 0x2e726873090a3b32,0x3572250920323375,0x37347225202c3431,0x6461090a3b38202c\n"
".quad 0x2509203233752e64,0x7225202c35313572,0x3b363231202c3738,0x33622e6c6873090a\n"
".quad 0x3631357225092032,0x2c3531357225202c,0x6461090a3b333220,0x2509203233752e64\n"
".quad 0x7225202c37313572,0x357225202c343135,0x646461090a3b3631,0x722509203233752e\n"
".quad 0x357225202c383135,0x31357225202c3331,0x622e726f090a3b37,0x3135722509203233\n"
".quad 0x2c38337225202c39,0x0a3b383135722520,0x3233622e766f6d09,0x202c383166250920\n"
".quad 0x090a3b3931357225,0x20696e752e617262,0x646e6557444c2409,0x65746e695f5f5f69\n"
".quad 0x616d665f6c616e72,0x34315f3837315f64,0x5f315f744c240a3b,0x0a3a303339363531\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093036343109,0x3233662e766f6d09,0x2c39333266250920\n"
".quad 0x6632326633663020,0x092020203b333839,0x3633362e30202f2f,0x2e6c756d090a3236\n"
".quad 0x3266250920323366,0x33326625202c3034,0x3933326625202c33,0x722e747663090a3b\n"
".quad 0x662e3233732e696e,0x3235722509203233,0x3034326625202c30,0x09636f6c2e090a3b\n"
".quad 0x0935363431093831,0x722e747663090a30,0x33732e3233662e6e,0x3134326625092032\n"
".quad 0x3b3032357225202c,0x33662e67656e090a,0x3234326625092032,0x3b3134326625202c\n"
".quad 0x33662e766f6d090a,0x3334326625092032,0x646639336630202c,0x2020203b30326161\n"
".quad 0x30302e30202f2f09,0x0a37323833383430,0x3233662e766f6d09,0x2c34343266250920\n"
".quad 0x3039636633663020,0x092020203b303030,0x3037352e31202f2f,0x2e616d66090a3133\n"
".quad 0x09203233662e6e72,0x25202c3534326625,0x6625202c32343266,0x326625202c343432\n"
".quad 0x616d66090a3b3333,0x203233662e6e722e,0x202c363432662509,0x25202c3234326625\n"
".quad 0x6625202c33343266,0x6c2e090a3b353432,0x343109383109636f,0x6f6d090a30093137\n"
".quad 0x2509203233732e76,0x357225202c353872,0x6f6c2e090a3b3032,0x3734310938310963\n"
".quad 0x766f6d090a300932,0x662509203233662e,0x326630202c373432,0x3b39303361353865\n"
".quad 0x36202f2f09202020,0x312d65313737302e,0x722e616d66090a31,0x2509203233662e6e\n"
".quad 0x326625202c383166,0x34326625202c3234,0x3634326625202c37,0x6e6557444c240a3b\n"
".quad 0x746e695f5f5f6964,0x6d665f6c616e7265,0x315f3837315f6461,0x6c3c2f2f200a3a34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039\n"
".quad 0x3530373109383109,0x2e646461090a3009,0x3172250920323373,0x35387225202c3930\n"
".quad 0x6f6d090a3b31202c,0x2509203233662e76,0x6625202c38343266,0x6c756d090a3b3831\n"
".quad 0x662509203233662e,0x34326625202c3932,0x3834326625202c38,0x622e646e61090a3b\n"
".quad 0x3235722509203233,0x3930317225202c31,0x6f6d090a3b31202c,0x2509203233752e76\n"
".quad 0x3b30202c32323572,0x652e70746573090a,0x2509203233732e71,0x357225202c393870\n"
".quad 0x32357225202c3132,0x38702540090a3b32,0x2409206172622039,0x3136315f315f744c\n"
".quad 0x2f2f200a3b343937,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6c2e090a30393031,0x373109383109636f,0x6f6d090a30093930,0x2509203233662e76\n"
".quad 0x6630202c39343266,0x6563356663633733,0x202f2f092020203b,0x6532333334342e32\n"
".quad 0x766f6d090a35302d,0x662509203233662e,0x626630202c303532,0x3b61313630366261\n"
".quad 0x2d202f2f09202020,0x3838333130302e30,0x2e616d66090a3337,0x09203233662e6e72\n"
".quad 0x25202c3135326625,0x6625202c39343266,0x35326625202c3932,0x2e766f6d090a3b30\n"
".quad 0x3266250920323366,0x64336630202c3235,0x203b356161616132,0x2e30202f2f092020\n"
".quad 0x0a36363636313430,0x2e6e722e616d6609,0x3266250920323366,0x35326625202c3335\n"
".quad 0x2c39326625202c31,0x0a3b323532662520,0x3233662e766f6d09,0x2c34353266250920\n"
".quad 0x3030306662663020,0x092020203b303030,0x0a352e302d202f2f,0x2e6e722e616d6609\n"
".quad 0x3266250920323366,0x35326625202c3535,0x2c39326625202c33,0x0a3b343532662520\n"
".quad 0x3233662e766f6d09,0x2c36353266250920,0x3030386633663020,0x092020203b303030\n"
".quad 0x6d66090a31202f2f,0x3233662e6e722e61,0x202c383366250920,0x25202c3535326625\n"
".quad 0x326625202c393266,0x617262090a3b3635,0x4c240920696e752e,0x353136315f315f74\n"
".quad 0x5f744c240a3b3833,0x3439373136315f31,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x39303132315f315f,0x09636f6c2e090a30,0x0931313731093831\n"
".quad 0x662e766f6d090a30,0x3532662509203233,0x3439626630202c37,0x20203b3966316163\n"
".quad 0x2e302d202f2f0920,0x3531353931303030,0x662e766f6d090a33,0x3532662509203233\n"
".quad 0x3063336630202c38,0x20203b6539333838,0x302e30202f2f0920,0x0a36313233333830\n"
".quad 0x2e6e722e616d6609,0x3266250920323366,0x35326625202c3935,0x2c39326625202c37\n"
".quad 0x0a3b383532662520,0x3233662e766f6d09,0x2c30363266250920,0x6161326562663020\n"
".quad 0x092020203b336161,0x36312e302d202f2f,0x6d66090a37363636,0x3233662e6e722e61\n"
".quad 0x2c31363266250920,0x202c393532662520,0x6625202c39326625,0x756d090a3b303632\n"
".quad 0x2509203233662e6c,0x6625202c32363266,0x36326625202c3932,0x2e616d66090a3b31\n"
".quad 0x09203233662e6e72,0x6625202c38336625,0x326625202c323632,0x34326625202c3834\n"
".quad 0x315f744c240a3b38,0x3a3833353136315f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568\n"
".quad 0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a,0x3009333137310938\n"
".quad 0x33662e67656e090a,0x3336326625092032,0x0a3b38336625202c,0x3233622e646e6109\n"
".quad 0x2c33323572250920,0x202c393031722520,0x2e766f6d090a3b32,0x3572250920323373\n"
".quad 0x090a3b30202c3432,0x2e656e2e70746573,0x3970250920323373,0x3332357225202c30\n"
".quad 0x3b3432357225202c,0x662e706c6573090a,0x3833662509203233,0x2c3336326625202c\n"
".quad 0x25202c3833662520,0x6c2e090a3b303970,0x373109383109636f,0x6f6d090a30093631\n"
".quad 0x2509203233662e76,0x6625202c37333266,0x57444c240a3b3833,0x695f5f5f69646e65\n"
".quad 0x37315f66666e6973,0x2f200a3a33315f38,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c,0x73090a3009383336\n"
".quad 0x203233732e706c65,0x202c353235722509,0x7025202c30202c31,0x766f6d090a3b3937\n"
".quad 0x662509203233662e,0x306630202c343632,0x3b30303030303030,0x30202f2f09202020\n"
".quad 0x71652e746573090a,0x3233662e3233752e,0x2c36323572250920,0x202c333332662520\n"
".quad 0x090a3b3436326625,0x203233732e67656e,0x202c373235722509,0x090a3b3632357225\n"
".quad 0x09203233622e726f,0x25202c3832357225,0x7225202c35323572,0x6f6d090a3b373235\n"
".quad 0x2509203233752e76,0x3b30202c39323572,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x357225202c313970,0x32357225202c3832,0x39702540090a3b39,0x2409206172622031\n"
".quad 0x3236315f315f744c,0x2f2f200a3b303530,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a30393031,0x363109383109636f,0x6f6d090a30093933\n"
".quad 0x2509203233662e76,0x6630202c35363266,0x3030303030303030,0x202f2f092020203b\n"
".quad 0x722e6c756d090a30,0x2509203233662e6e,0x326625202c383466,0x36326625202c3333\n"
".quad 0x2e617262090a3b35,0x444c240920696e75,0x5f5f5f69646e6557,0x315f66666e697369\n"
".quad 0x4c240a3b395f3837,0x303236315f315f74,0x3c2f2f200a3a3035,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3132315f315f4c24,0x766f6d090a303930,0x662509203233662e\n"
".quad 0x346630202c363632,0x3b30303761623337,0x34202f2f09202020,0x6573090a39333038\n"
".quad 0x33662e74672e7074,0x2c32397025092032,0x202c343332662520,0x090a3b3636326625\n"
".quad 0x6220323970252140,0x5f744c2409206172,0x3236353236315f31,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x39303132315f315f,0x09636f6c2e090a30\n"
".quad 0x0936393331093831,0x622e766f6d090a30,0x3335722509203233,0x3333326625202c30\n"
".quad 0x622e646e61090a3b,0x3634722509203233,0x3033357225202c30,0x34373431322d202c\n"
".quad 0x090a3b3834363338,0x203233732e766f6d,0x202c303231722509,0x090a3b3036347225\n"
".quad 0x09383109636f6c2e,0x090a300932303431,0x203233622e6c6873,0x202c313335722509\n"
".quad 0x31202c3033357225,0x752e726873090a3b,0x3335722509203233,0x3133357225202c32\n"
".quad 0x73090a3b3432202c,0x09203233752e6275,0x25202c3336347225,0x3231202c32333572\n"
".quad 0x636f6c2e090a3b38,0x3009343209383109,0x33732e766f6d090a,0x3332317225092032\n"
".quad 0x0a3b30337225202c,0x3233752e64646109,0x202c333472250920,0x3432202c30337225\n"
".quad 0x752e766f6d090a3b,0x3231722509203233,0x6475635f5f202c34,0x616475635f5f5f61\n"
".quad 0x5f746c757365725f,0x3b36393230313631,0x33622e6c6873090a,0x3333357225092032\n"
".quad 0x2c3033357225202c,0x2e726f090a3b3820,0x3472250920323362,0x33357225202c3536\n"
".quad 0x373431322d202c33,0x0a3b383436333834,0x3233752e766f6d09,0x2c36323172250920\n"
".quad 0x5f744c240a3b3020,0x3638353336315f31,0x676172702e090a3a,0x6e756f6e2220616d\n"
".quad 0x200a3b226c6c6f72,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x7473656e202c3432,0x7470656420676e69,0x7469202c31203a68,0x736e6f6974617265\n"
".quad 0x6f6c2e090a36203a,0x3134310938310963,0x2e646c090a300930,0x33752e74736e6f63\n"
".quad 0x3732317225092032,0x33323172255b202c,0x756d090a3b5d302b,0x3233752e6f6c2e6c\n"
".quad 0x2c34333572250920,0x202c373231722520,0x090a3b3536347225,0x203233752e646461\n"
".quad 0x202c353335722509,0x25202c3433357225,0x2e090a3b36323172,0x3109383109636f6c\n"
".quad 0x73090a3009313134,0x33752e74672e7465,0x2509203233752e32,0x7225202c36333572\n"
".quad 0x357225202c343335,0x67656e090a3b3533,0x722509203233732e,0x357225202c373335\n"
".quad 0x6c756d090a3b3633,0x203233752e69682e,0x202c383335722509,0x25202c3732317225\n"
".quad 0x61090a3b35363472,0x09203233752e6464,0x25202c3632317225,0x7225202c37333572\n"
".quad 0x6c2e090a3b383335,0x343109383109636f,0x7473090a30093231,0x752e6c61636f6c2e\n"
".quad 0x3172255b09203233,0x25202c5d302b3432,0x61090a3b35333572,0x09203233752e6464\n"
".quad 0x25202c3432317225,0x3b34202c34323172,0x33752e646461090a,0x3332317225092032\n"
".quad 0x2c3332317225202c,0x746573090a3b3420,0x3233752e656e2e70,0x202c333970250920\n"
".quad 0x25202c3332317225,0x2540090a3b333472,0x2061726220333970,0x315f315f744c2409\n"
".quad 0x200a3b3638353336,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465\n"
".quad 0x090a303930313231,0x09383109636f6c2e,0x090a300934313431,0x6c61636f6c2e7473\n"
".quad 0x5f5b09203233752e,0x5f5f5f616475635f,0x7365725f61647563,0x303136315f746c75\n"
".quad 0x2c5d34322b363932,0x0a3b363231722520,0x383109636f6c2e09,0x0a30093931343109\n"
".quad 0x3233752e72687309,0x2c39333572250920,0x202c333634722520,0x2e6c756d090a3b35\n"
".quad 0x09203233752e6f6c,0x25202c3034357225,0x3b34202c39333572,0x33752e627573090a\n"
".quad 0x3533317225092032,0x202c32337225202c,0x090a3b3034357225,0x6c61636f6c2e646c\n"
".quad 0x722509203233752e,0x72255b202c363231,0x3b5d34322b353331,0x3109636f6c2e090a\n"
".quad 0x3009303234310938,0x636f6c2e646c090a,0x09203233752e6c61,0x5b202c3633317225\n"
".quad 0x30322b3533317225,0x2e646e61090a3b5d,0x3472250920323362,0x36347225202c3337\n"
".quad 0x090a3b3133202c33,0x203233752e766f6d,0x202c313435722509,0x70746573090a3b30\n"
".quad 0x203233752e71652e,0x25202c3439702509,0x7225202c33373472,0x2540090a3b313435\n"
".quad 0x2061726220343970,0x315f315f744c2409,0x200a3b3839303436,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e\n"
".quad 0x090a300933323431,0x203233732e766f6d,0x202c323435722509,0x627573090a3b3233\n"
".quad 0x722509203233732e,0x357225202c333435,0x37347225202c3234,0x2e726873090a3b33\n"
".quad 0x3572250920323375,0x33317225202c3434,0x3334357225202c36,0x622e6c6873090a3b\n"
".quad 0x3435722509203233,0x3632317225202c35,0x3b3337347225202c,0x33752e646461090a\n"
".quad 0x3632317225092032,0x2c3434357225202c,0x0a3b353435722520,0x383109636f6c2e09\n"
".quad 0x0a30093432343109,0x61636f6c2e646c09,0x2509203233752e6c,0x255b202c36343572\n"
".quad 0x5d36312b35333172,0x752e726873090a3b,0x3435722509203233,0x3634357225202c37\n"
".quad 0x3b3334357225202c,0x33622e6c6873090a,0x3834357225092032,0x2c3633317225202c\n"
".quad 0x0a3b333734722520,0x3233752e64646109,0x2c36333172250920,0x202c373435722520\n"
".quad 0x240a3b3834357225,0x3436315f315f744c,0x2f2f200a3a383930,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f\n"
".quad 0x6873090a30093632,0x2509203233752e72,0x7225202c35343172,0x3b3033202c363231\n"
".quad 0x3109636f6c2e090a,0x3009383234310938,0x33752e726873090a,0x3934357225092032\n"
".quad 0x2c3633317225202c,0x6873090a3b303320,0x2509203233622e6c,0x7225202c30353572\n"
".quad 0x0a3b32202c363231,0x3233752e64646109,0x2c36323172250920,0x202c393435722520\n"
".quad 0x090a3b3035357225,0x09383109636f6c2e,0x090a300939323431,0x203233622e6c6873\n"
".quad 0x202c363331722509,0x32202c3633317225,0x752e766f6d090a3b,0x3535722509203233\n"
".quad 0x73090a3b30202c31,0x752e71652e707465,0x3539702509203233,0x2c3633317225202c\n"
".quad 0x0a3b313535722520,0x6220353970254009,0x5f744c2409206172,0x3636383436315f31\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x09636f6c2e090a30,0x0930333431093831,0x752e646461090a30,0x3535722509203233\n"
".quad 0x3632317225202c32,0x6f6d090a3b31202c,0x2509203233752e76,0x322d202c33353572\n"
".quad 0x3436333834373431,0x2e746573090a3b38,0x752e3233752e7467,0x3535722509203233\n"
".quad 0x3235357225202c34,0x3b3335357225202c,0x33732e67656e090a,0x3535357225092032\n"
".quad 0x3b3435357225202c,0x6e752e617262090a,0x315f744c24092069,0x3b3031363436315f\n"
".quad 0x315f315f744c240a,0x200a3a3636383436,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x203233752e766f6d,0x202c363535722509\n"
".quad 0x333834373431322d,0x6573090a3b383436,0x3233752e74672e74,0x722509203233752e\n"
".quad 0x317225202c373535,0x35357225202c3632,0x2e67656e090a3b36,0x3572250920323373\n"
".quad 0x35357225202c3535,0x315f744c240a3b37,0x3a3031363436315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a\n"
".quad 0x3009313334310938,0x33752e646461090a,0x3835357225092032,0x2c3534317225202c\n"
".quad 0x0a3b353535722520,0x383109636f6c2e09,0x0a30093033343109,0x3233732e67656e09\n"
".quad 0x2c39353572250920,0x0a3b383535722520,0x3233752e766f6d09,0x2c30363572250920\n"
".quad 0x746573090a3b3020,0x3233752e656e2e70,0x202c363970250920,0x25202c3036347225\n"
".quad 0x73090a3b30363572,0x203233732e706c65,0x202c353431722509,0x25202c3935357225\n"
".quad 0x7025202c38353572,0x766f6d090a3b3639,0x722509203233752e,0x0a3b30202c313635\n"
".quad 0x71652e7074657309,0x702509203233752e,0x35357225202c3739,0x3136357225202c35\n"
".quad 0x3739702540090a3b,0x4c24092061726220,0x313536315f315f74,0x3c2f2f200a3b3232\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930\n"
".quad 0x3334310938310963,0x67656e090a300936,0x722509203233732e,0x317225202c363331\n"
".quad 0x6f6c2e090a3b3633,0x3334310938310963,0x766f6d090a300938,0x722509203233752e\n"
".quad 0x0a3b30202c323635,0x2e71652e74657309,0x203233752e323375,0x202c333635722509\n"
".quad 0x25202c3633317225,0x6e090a3b32363572,0x09203233732e6765,0x25202c3436357225\n"
".quad 0x6e090a3b33363572,0x09203233622e746f,0x25202c3536357225,0x61090a3b36323172\n"
".quad 0x09203233752e6464,0x25202c3632317225,0x7225202c34363572,0x6c2e090a3b353635\n"
".quad 0x343109383109636f,0x6f78090a30093933,0x2509203233622e72,0x7225202c30323172\n"
".quad 0x31322d202c303634,0x3834363338343734,0x5f315f744c240a3b,0x0a3a323231353631\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093134343109,0x3233732e766f6d09,0x2c33363172250920\n"
".quad 0x0a3b353431722520,0x3233752e766f6d09,0x2c36363572250920,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x202c383970250920,0x25202c3632317225,0x40090a3b36363572\n"
".quad 0x6172622038397025,0x5f315f744c240920,0x0a3b383130323831,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x3233752e766f6d09\n"
".quad 0x2c35363172250920,0x5f744c240a3b3020,0x3634313636315f31,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x2c3134343120656e,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x3009353434310938,0x33752e726873090a\n"
".quad 0x3736357225092032,0x2c3633317225202c,0x6873090a3b313320,0x2509203233622e6c\n"
".quad 0x7225202c38363572,0x0a3b31202c363231,0x3233752e64646109,0x2c36323172250920\n"
".quad 0x202c373635722520,0x090a3b3836357225,0x09383109636f6c2e,0x090a300936343431\n"
".quad 0x203233622e6c6873,0x202c363331722509,0x31202c3633317225,0x09636f6c2e090a3b\n"
".quad 0x0937343431093831,0x752e627573090a30,0x3631722509203233,0x3536317225202c35\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3b30202c39363572,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c393970,0x36357225202c3632,0x39702540090a3b39\n"
".quad 0x2409206172622039,0x3636315f315f744c,0x2f2f200a3b363431,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x7262090a30393031,0x240920696e752e61\n"
".quad 0x3536315f315f744c,0x744c240a3b343336,0x31303238315f315f,0x6c3c2f2f200a3a38\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c,0x2e766f6d090a3039\n"
".quad 0x3172250920323375,0x240a3b30202c3536,0x3536315f315f744c,0x2f2f200a3a343336\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031\n"
".quad 0x343109383109636f,0x756d090a30093934,0x3233752e6f6c2e6c,0x2c36333172250920\n"
".quad 0x202c363231722520,0x383730373132392d,0x6f6c2e090a3b3037,0x3534310938310963\n"
".quad 0x766f6d090a300930,0x722509203233752e,0x32392d202c303735,0x3b30373837303731\n"
".quad 0x69682e6c756d090a,0x722509203233752e,0x317225202c363231,0x37357225202c3632\n"
".quad 0x2e766f6d090a3b30,0x3572250920323375,0x090a3b30202c3137,0x2e656c2e70746573\n"
".quad 0x3170250920323373,0x32317225202c3030,0x3137357225202c36,0x3031702540090a3b\n"
".quad 0x2409206172622030,0x3636315f315f744c,0x2f2f200a3b383536,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f\n"
".quad 0x6873090a30093235,0x2509203233752e72,0x7225202c32373572,0x3b3133202c363331\n"
".quad 0x33622e6c6873090a,0x3337357225092032,0x2c3632317225202c,0x646461090a3b3120\n"
".quad 0x722509203233752e,0x357225202c363231,0x37357225202c3237,0x636f6c2e090a3b33\n"
".quad 0x3335343109383109,0x2e6c6873090a3009,0x3172250920323362,0x33317225202c3633\n"
".quad 0x2e090a3b31202c36,0x3109383109636f6c,0x73090a3009343534,0x09203233752e6275\n"
".quad 0x25202c3536317225,0x3b31202c35363172,0x315f315f744c240a,0x200a3a3835363636\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300936353431,0x203233752e766f6d,0x202c343735722509\n"
".quad 0x2e746573090a3b30,0x752e3233752e656e,0x3735722509203233,0x3633317225202c35\n"
".quad 0x3b3437357225202c,0x33732e67656e090a,0x3637357225092032,0x3b3537357225202c\n"
".quad 0x33752e646461090a,0x3632317225092032,0x2c3637357225202c,0x0a3b363231722520\n"
".quad 0x383109636f6c2e09,0x0a30093835343109,0x3233622e6c687309,0x2c37373572250920\n"
".quad 0x202c363231722520,0x766f6d090a3b3432,0x722509203233732e,0x0a3b30202c383735\n"
".quad 0x2e746c2e74657309,0x203233732e323375,0x202c393735722509,0x25202c3737357225\n"
".quad 0x6e090a3b38373572,0x09203233732e6765,0x25202c3038357225,0x73090a3b39373572\n"
".quad 0x09203233752e7268,0x25202c3138357225,0x3b38202c36323172,0x33752e646461090a\n"
".quad 0x3238357225092032,0x2c3536317225202c,0x73090a3b36323120,0x09203233622e6c68\n"
".quad 0x25202c3338357225,0x3332202c32383572,0x752e646461090a3b,0x3835722509203233\n"
".quad 0x3138357225202c34,0x3b3338357225202c,0x33752e646461090a,0x3538357225092032\n"
".quad 0x2c3038357225202c,0x0a3b343835722520,0x203233622e726f09,0x202c363835722509\n"
".quad 0x25202c3032317225,0x6d090a3b35383572,0x09203233622e766f,0x7225202c30356625\n"
".quad 0x7262090a3b363835,0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f\n"
".quad 0x5f64616d665f6c61,0x0a3b30315f383731,0x36315f315f744c24,0x2f200a3a32363532\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x616568202c323037,0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132\n"
".quad 0x3109383109636f6c,0x6d090a3009303634,0x09203233662e766f,0x30202c3736326625\n"
".quad 0x3839663232663366,0x2f2f092020203b33,0x32363633362e3020,0x33662e6c756d090a\n"
".quad 0x3836326625092032,0x2c3333326625202c,0x0a3b373632662520,0x696e722e74766309\n"
".quad 0x3233662e3233732e,0x2c37383572250920,0x0a3b383632662520,0x383109636f6c2e09\n"
".quad 0x0a30093536343109,0x2e6e722e74766309,0x203233732e323366,0x202c393632662509\n"
".quad 0x090a3b3738357225,0x203233662e67656e,0x202c303732662509,0x090a3b3936326625\n"
".quad 0x203233662e766f6d,0x202c313732662509,0x6161646639336630,0x2f092020203b3032\n"
".quad 0x343030302e30202f,0x6d090a3732383338,0x09203233662e766f,0x30202c3237326625\n"
".quad 0x3030303963663366,0x2f2f092020203b30,0x31333037352e3120,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x326625202c333732,0x37326625202c3037,0x3333326625202c32\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c34373266,0x326625202c303732\n"
".quad 0x37326625202c3137,0x636f6c2e090a3b33,0x3137343109383109,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x38357225202c3336,0x636f6c2e090a3b37,0x3237343109383109\n"
".quad 0x2e766f6d090a3009,0x3266250920323366,0x65326630202c3537,0x203b393033613538\n"
".quad 0x2e36202f2f092020,0x31312d6531373730,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x37326625202c3035,0x3537326625202c30,0x3b3437326625202c,0x646e6557444c240a\n"
".quad 0x65746e695f5f5f69,0x616d665f6c616e72,0x30315f3837315f64,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x39303132315f315f,0x09636f6c2e090a30\n"
".quad 0x0931343631093831,0x662e766f6d090a30,0x3732662509203233,0x3b30356625202c36\n"
".quad 0x33662e6c756d090a,0x2c31366625092032,0x202c363732662520,0x090a3b3637326625\n"
".quad 0x203233622e646e61,0x202c383835722509,0x31202c3336317225,0x752e766f6d090a3b\n"
".quad 0x3835722509203233,0x73090a3b30202c39,0x732e71652e707465,0x3031702509203233\n"
".quad 0x3838357225202c31,0x3b3938357225202c,0x313031702540090a,0x4c24092061726220\n"
".quad 0x343736315f315f74,0x3c2f2f200a3b3632,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x6f6c2e090a303930,0x3436310938310963,0x766f6d090a300934\n"
".quad 0x662509203233662e,0x336630202c373732,0x3b65633566636337,0x32202f2f09202020\n"
".quad 0x2d6532333334342e,0x2e766f6d090a3530,0x3266250920323366,0x61626630202c3837\n"
".quad 0x203b613136303662,0x302d202f2f092020,0x373838333130302e,0x722e616d66090a33\n"
".quad 0x2509203233662e6e,0x6625202c39373266,0x366625202c373732,0x3837326625202c31\n"
".quad 0x662e766f6d090a3b,0x3832662509203233,0x3264336630202c30,0x20203b3561616161\n"
".quad 0x302e30202f2f0920,0x090a363636363134,0x662e6e722e616d66,0x3832662509203233\n"
".quad 0x3937326625202c31,0x202c31366625202c,0x090a3b3038326625,0x203233662e766f6d\n"
".quad 0x202c323832662509,0x3030303066626630,0x2f092020203b3030,0x090a352e302d202f\n"
".quad 0x662e6e722e616d66,0x3832662509203233,0x3138326625202c33,0x202c31366625202c\n"
".quad 0x090a3b3238326625,0x203233662e766f6d,0x202c343832662509,0x3030303866336630\n"
".quad 0x2f092020203b3030,0x616d66090a31202f,0x203233662e6e722e,0x25202c3037662509\n"
".quad 0x6625202c33383266,0x38326625202c3136,0x2e617262090a3b34,0x744c240920696e75\n"
".quad 0x37313736315f315f,0x315f744c240a3b30,0x3a3632343736315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x3109636f6c2e090a\n"
".quad 0x3009363436310938,0x33662e766f6d090a,0x3538326625092032,0x633439626630202c\n"
".quad 0x2020203b39663161,0x302e302d202f2f09,0x3335313539313030,0x33662e766f6d090a\n"
".quad 0x3638326625092032,0x383063336630202c,0x2020203b65393338,0x30302e30202f2f09\n"
".quad 0x090a363132333338,0x662e6e722e616d66,0x3832662509203233,0x3538326625202c37\n"
".quad 0x202c31366625202c,0x090a3b3638326625,0x203233662e766f6d,0x202c383832662509\n"
".quad 0x6161613265626630,0x2f092020203b3361,0x3636312e302d202f,0x616d66090a373636\n"
".quad 0x203233662e6e722e,0x202c393832662509,0x25202c3738326625,0x326625202c313666\n"
".quad 0x6c756d090a3b3838,0x662509203233662e,0x366625202c303932,0x3938326625202c31\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x326625202c303766,0x37326625202c3039\n"
".quad 0x3637326625202c36,0x5f315f744c240a3b,0x0a3a303731373631,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09\n"
".quad 0x0a30093834363109,0x3233662e67656e09,0x2c31393266250920,0x090a3b3037662520\n"
".quad 0x203233622e646e61,0x202c303935722509,0x32202c3336317225,0x732e766f6d090a3b\n"
".quad 0x3935722509203233,0x73090a3b30202c31,0x732e656e2e707465,0x3031702509203233\n"
".quad 0x3039357225202c32,0x3b3139357225202c,0x662e706c6573090a,0x3037662509203233\n"
".quad 0x2c3139326625202c,0x25202c3037662520,0x2e090a3b32303170,0x3109383109636f6c\n"
".quad 0x6d090a3009313536,0x09203233662e766f,0x6625202c38346625,0x57444c240a3b3037\n"
".quad 0x695f5f5f69646e65,0x37315f66666e6973,0x2f2f200a3a395f38,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x363231093309636f\n"
".quad 0x632e646c090a3009,0x3233662e74736e6f,0x2c32393266250920,0x352b353372255b20\n"
".quad 0x2e646c090a3b5d36,0x33662e74736e6f63,0x3339326625092032,0x2b353372255b202c\n"
".quad 0x756d090a3b5d3235,0x2509203233662e6c,0x6625202c34393266,0x39326625202c3834\n"
".quad 0x2e6c756d090a3b32,0x3266250920323366,0x39326625202c3539,0x3733326625202c33\n"
".quad 0x662e627573090a3b,0x3932662509203233,0x3539326625202c36,0x3b3439326625202c\n"
".quad 0x33662e646461090a,0x202c346625092032,0x326625202c346625,0x6f6c2e090a3b3639\n"
".quad 0x0937323109330963,0x662e6c756d090a30,0x3932662509203233,0x3733326625202c37\n"
".quad 0x3b3239326625202c,0x6e722e616d66090a,0x662509203233662e,0x326625202c383932\n"
".quad 0x38346625202c3339,0x3b3739326625202c,0x33662e646461090a,0x202c356625092032\n"
".quad 0x326625202c356625,0x6f6c2e090a3b3839,0x3037310938310963,0x2e646c090a300932\n"
".quad 0x33662e74736e6f63,0x3939326625092032,0x2b353372255b202c,0x646c090a3b5d3436\n"
".quad 0x662e74736e6f632e,0x3033662509203233,0x353372255b202c30,0x6c090a3b5d30362b\n"
".quad 0x2e74736e6f632e64,0x3366250920323366,0x3372255b202c3130,0x090a3b5d38362b35\n"
".quad 0x203233662e6c756d,0x202c323033662509,0x25202c3939326625,0x616d66090a3b3266\n"
".quad 0x203233662e6e722e,0x202c333033662509,0x25202c3030336625,0x30336625202c3166\n"
".quad 0x2e616d66090a3b32,0x09203233662e6e72,0x25202c3430336625,0x6625202c31303366\n"
".quad 0x3330336625202c33,0x662e747663090a3b,0x09203233662e3436,0x25202c3731646625\n"
".quad 0x6d090a3b34303366,0x09203436662e766f,0x30202c3831646625,0x6631323931303464\n"
".quad 0x3164323434343562,0x2e36202f2f093b38,0x6d090a3931333832,0x09203436662e6c75\n"
".quad 0x25202c3931646625,0x6625202c37316466,0x6261090a3b383164,0x2509203436662e73\n"
".quad 0x6625202c30326466,0x7663090a3b393164,0x3233662e6e722e74,0x662509203436662e\n"
".quad 0x646625202c353033,0x747663090a3b3931,0x2e3233662e6e722e,0x3366250920343666\n"
".quad 0x32646625202c3630,0x2e766f6d090a3b30,0x3366250920323366,0x66376630202c3730\n"
".quad 0x203b303030303038,0x2828202f2f092020,0x30282f2946302e31,0x73090a292946302e\n"
".quad 0x662e71652e707465,0x3031702509203233,0x3630336625202c33,0x3b3730336625202c\n"
".quad 0x303170252140090a,0x2409206172622033,0x3736315f315f744c,0x2f2f200a3b323836\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031\n"
".quad 0x373109383109636f,0x656e090a30093330,0x2509203233662e67,0x6625202c38303366\n"
".quad 0x6461090a3b353033,0x3233662e6e722e64,0x2c39303366250920,0x202c353033662520\n"
".quad 0x090a3b3830336625,0x20696e752e617262,0x646e6557444c2409,0x6e6973695f5f5f69\n"
".quad 0x355f3837315f6666,0x5f315f744c240a3b,0x0a3a323836373631,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120\n"
".quad 0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f,0x3233662e766f6d09\n"
".quad 0x2c30313366250920,0x6162333734663020,0x092020203b303037,0x3933303834202f2f\n"
".quad 0x672e70746573090a,0x2509203233662e74,0x6625202c34303170,0x336625202c363033\n"
".quad 0x252140090a3b3031,0x6172622034303170,0x5f315f744c240920,0x0a3b343931383631\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x68202c3230373120,0x6562616c20646165,0x315f4c242064656c,0x0a3039303132315f\n"
".quad 0x383109636f6c2e09,0x0a30093639333109,0x3233622e766f6d09,0x2c32393572250920\n"
".quad 0x0a3b353033662520,0x3233622e646e6109,0x2c33393572250920,0x202c323935722520\n"
".quad 0x333834373431322d,0x6f6d090a3b383436,0x2509203233732e76,0x357225202c383372\n"
".quad 0x6f6c2e090a3b3339,0x3034310938310963,0x6c6873090a300932,0x722509203233622e\n"
".quad 0x357225202c343935,0x090a3b31202c3239,0x203233752e726873,0x202c353935722509\n"
".quad 0x32202c3439357225,0x2e627573090a3b34,0x3572250920323375,0x39357225202c3639\n"
".quad 0x0a3b383231202c35,0x383109636f6c2e09,0x6d090a3009343209,0x09203233732e766f\n"
".quad 0x7225202c32347225,0x646461090a3b3033,0x722509203233752e,0x30337225202c3334\n"
".quad 0x6d090a3b3432202c,0x09203233752e766f,0x5f5f202c34347225,0x635f5f5f61647563\n"
".quad 0x757365725f616475,0x33303134345f746c,0x6c6873090a3b3432,0x722509203233622e\n"
".quad 0x357225202c373935,0x090a3b38202c3239,0x09203233622e726f,0x25202c3839357225\n"
".quad 0x322d202c37393572,0x3436333834373431,0x2e766f6d090a3b38,0x3472250920323375\n"
".quad 0x4c240a3b30202c37,0x323936315f315f74,0x72702e090a3a3831,0x6f6e2220616d6761\n"
".quad 0x3b226c6c6f726e75,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x656e202c34322065,0x656420676e697473,0x202c31203a687470,0x6f69746172657469\n"
".quad 0x2e090a36203a736e,0x3109383109636f6c,0x6c090a3009303134,0x2e74736e6f632e64\n"
".quad 0x3472250920323375,0x323472255b202c38,0x756d090a3b5d302b,0x3233752e6f6c2e6c\n"
".quad 0x2c39393572250920,0x25202c3834722520,0x61090a3b38393572,0x09203233752e6464\n"
".quad 0x25202c3030367225,0x7225202c39393572,0x6f6c2e090a3b3734,0x3134310938310963\n"
".quad 0x746573090a300931,0x2e3233752e74672e,0x3672250920323375,0x39357225202c3130\n"
".quad 0x3030367225202c39,0x732e67656e090a3b,0x3036722509203233,0x3130367225202c32\n"
".quad 0x682e6c756d090a3b,0x2509203233752e69,0x7225202c33303672,0x39357225202c3834\n"
".quad 0x2e646461090a3b38,0x3472250920323375,0x3230367225202c37,0x3b3330367225202c\n"
".quad 0x3109636f6c2e090a,0x3009323134310938,0x636f6c2e7473090a,0x09203233752e6c61\n"
".quad 0x5d302b343472255b,0x3b3030367225202c,0x33752e646461090a,0x2c34347225092032\n"
".quad 0x34202c3434722520,0x752e646461090a3b,0x3234722509203233,0x202c32347225202c\n"
".quad 0x70746573090a3b34,0x203233752e656e2e,0x202c353031702509,0x7225202c32347225\n"
".quad 0x702540090a3b3334,0x2061726220353031,0x315f315f744c2409,0x200a3b3831323936\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300934313431,0x6c61636f6c2e7473,0x5f5b09203233752e\n"
".quad 0x5f5f5f616475635f,0x7365725f61647563,0x303134345f746c75,0x2c5d34322b343233\n"
".quad 0x090a3b3734722520,0x09383109636f6c2e,0x090a300939313431,0x203233752e726873\n"
".quad 0x202c343036722509,0x35202c3639357225,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c35303672,0x0a3b34202c343036,0x3233752e62757309,0x202c363572250920\n"
".quad 0x7225202c33337225,0x646c090a3b353036,0x752e6c61636f6c2e,0x3734722509203233\n"
".quad 0x2b363572255b202c,0x6c2e090a3b5d3432,0x343109383109636f,0x646c090a30093032\n"
".quad 0x752e6c61636f6c2e,0x3735722509203233,0x2b363572255b202c,0x6e61090a3b5d3032\n"
".quad 0x2509203233622e64,0x7225202c36303672,0x3b3133202c363935,0x33752e766f6d090a\n"
".quad 0x3730367225092032,0x6573090a3b30202c,0x33752e71652e7074,0x3630317025092032\n"
".quad 0x2c3630367225202c,0x0a3b373036722520,0x2036303170254009,0x744c240920617262\n"
".quad 0x33373936315f315f,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x636f6c2e090a3039,0x3332343109383109,0x2e766f6d090a3009\n"
".quad 0x3672250920323373,0x0a3b3233202c3830,0x3233732e62757309,0x2c39303672250920\n"
".quad 0x202c383036722520,0x090a3b3630367225,0x203233752e726873,0x202c303136722509\n"
".quad 0x7225202c37357225,0x6873090a3b393036,0x2509203233622e6c,0x7225202c31313672\n"
".quad 0x30367225202c3734,0x2e646461090a3b36,0x3472250920323375,0x3031367225202c37\n"
".quad 0x3b3131367225202c,0x3109636f6c2e090a,0x3009343234310938,0x636f6c2e646c090a\n"
".quad 0x09203233752e6c61,0x5b202c3231367225,0x5d36312b36357225,0x752e726873090a3b\n"
".quad 0x3136722509203233,0x3231367225202c33,0x3b3930367225202c,0x33622e6c6873090a\n"
".quad 0x3431367225092032,0x202c37357225202c,0x090a3b3630367225,0x203233752e646461\n"
".quad 0x25202c3735722509,0x7225202c33313672,0x744c240a3b343136,0x33373936315f315f\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3632343109383109,0x2e726873090a3009,0x3672250920323375\n"
".quad 0x2c37347225202c37,0x6c2e090a3b303320,0x343109383109636f,0x6873090a30093832\n"
".quad 0x2509203233752e72,0x7225202c35313672,0x0a3b3033202c3735,0x3233622e6c687309\n"
".quad 0x2c36313672250920,0x32202c3734722520,0x752e646461090a3b,0x3734722509203233\n"
".quad 0x2c3531367225202c,0x0a3b363136722520,0x383109636f6c2e09,0x0a30093932343109\n"
".quad 0x3233622e6c687309,0x202c373572250920,0x3b32202c37357225,0x33752e766f6d090a\n"
".quad 0x3731367225092032,0x6573090a3b30202c,0x33752e71652e7074,0x3730317025092032\n"
".quad 0x202c37357225202c,0x090a3b3731367225,0x6220373031702540,0x5f744c2409206172\n"
".quad 0x3839343037315f31,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x39303132315f315f,0x09636f6c2e090a30,0x0930333431093831,0x752e646461090a30\n"
".quad 0x3136722509203233,0x2c37347225202c38,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x31322d202c393136,0x3834363338343734,0x672e746573090a3b,0x33752e3233752e74\n"
".quad 0x3032367225092032,0x2c3831367225202c,0x0a3b393136722520,0x3233732e67656e09\n"
".quad 0x2c31323672250920,0x0a3b303236722520,0x696e752e61726209,0x5f315f744c240920\n"
".quad 0x0a3b323432303731,0x37315f315f744c24,0x2f200a3a38393430,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037\n"
".quad 0x656c6562616c2064,0x315f315f4c242064,0x6d090a3039303132,0x09203233752e766f\n"
".quad 0x2d202c3232367225,0x3633383437343132,0x746573090a3b3834,0x2e3233752e74672e\n"
".quad 0x3672250920323375,0x37347225202c3332,0x3b3232367225202c,0x33732e67656e090a\n"
".quad 0x3132367225092032,0x3b3332367225202c,0x315f315f744c240a,0x200a3a3234323037\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x09383109636f6c2e,0x090a300931333431,0x203233752e646461,0x202c343236722509\n"
".quad 0x7225202c37367225,0x6c2e090a3b313236,0x343109383109636f,0x656e090a30093033\n"
".quad 0x2509203233732e67,0x7225202c35323672,0x6f6d090a3b343236,0x2509203233752e76\n"
".quad 0x3b30202c36323672,0x6e2e70746573090a,0x2509203233752e65,0x7225202c38303170\n"
".quad 0x367225202c333935,0x6c6573090a3b3632,0x2509203233732e70,0x367225202c373672\n"
".quad 0x32367225202c3532,0x3830317025202c34,0x752e766f6d090a3b,0x3236722509203233\n"
".quad 0x73090a3b30202c37,0x752e71652e707465,0x3031702509203233,0x3132367225202c39\n"
".quad 0x3b3732367225202c,0x393031702540090a,0x4c24092061726220,0x373037315f315f74\n"
".quad 0x3c2f2f200a3b3435,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3334310938310963,0x67656e090a300936,0x722509203233732e\n"
".quad 0x37357225202c3735,0x09636f6c2e090a3b,0x0938333431093831,0x752e766f6d090a30\n"
".quad 0x3236722509203233,0x73090a3b30202c38,0x33752e71652e7465,0x2509203233752e32\n"
".quad 0x7225202c39323672,0x32367225202c3735,0x2e67656e090a3b38,0x3672250920323373\n"
".quad 0x32367225202c3033,0x2e746f6e090a3b39,0x3672250920323362,0x37347225202c3133\n"
".quad 0x752e646461090a3b,0x3734722509203233,0x2c3033367225202c,0x0a3b313336722520\n"
".quad 0x383109636f6c2e09,0x0a30093933343109,0x3233622e726f7809,0x202c383372250920\n"
".quad 0x2d202c3339357225,0x3633383437343132,0x5f744c240a3b3834,0x3435373037315f31\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x09636f6c2e090a30,0x0931343431093831,0x732e766f6d090a30,0x3538722509203233\n"
".quad 0x0a3b37367225202c,0x3233752e766f6d09,0x2c32333672250920,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x2c30313170250920,0x25202c3734722520,0x40090a3b32333672\n"
".quad 0x7262203031317025,0x315f744c24092061,0x3b3437323238315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x202c323037312065\n"
".quad 0x62616c2064616568,0x5f4c242064656c65,0x3039303132315f31,0x33752e766f6d090a\n"
".quad 0x2c37387225092032,0x5f744c240a3b3020,0x3837373137315f31,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x2c3134343120656e,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x3009353434310938,0x33752e726873090a\n"
".quad 0x3333367225092032,0x202c37357225202c,0x6c6873090a3b3133,0x722509203233622e\n"
".quad 0x347225202c343336,0x61090a3b31202c37,0x09203233752e6464,0x7225202c37347225\n"
".quad 0x367225202c333336,0x6f6c2e090a3b3433,0x3434310938310963,0x6c6873090a300936\n"
".quad 0x722509203233622e,0x37357225202c3735,0x6c2e090a3b31202c,0x343109383109636f\n"
".quad 0x7573090a30093734,0x2509203233752e62,0x387225202c373872,0x6d090a3b31202c37\n"
".quad 0x09203233752e766f,0x30202c3533367225,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x25202c3131317025,0x367225202c373472,0x702540090a3b3533,0x2061726220313131\n"
".quad 0x315f315f744c2409,0x200a3b3837373137,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x20696e752e617262,0x315f315f744c2409\n"
".quad 0x240a3b3636323137,0x3238315f315f744c,0x2f2f200a3a343732,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6f6d090a30393031,0x2509203233752e76\n"
".quad 0x0a3b30202c373872,0x37315f315f744c24,0x2f200a3a36363231,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037\n"
".quad 0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c\n"
".quad 0x6d090a3009393434,0x33752e6f6c2e6c75,0x2c37357225092032,0x2d202c3734722520\n"
".quad 0x3738373037313239,0x636f6c2e090a3b30,0x3035343109383109,0x2e766f6d090a3009\n"
".quad 0x3672250920323375,0x3132392d202c3633,0x0a3b303738373037,0x2e69682e6c756d09\n"
".quad 0x3472250920323375,0x2c37347225202c37,0x0a3b363336722520,0x3233752e766f6d09\n"
".quad 0x2c37333672250920,0x746573090a3b3020,0x3233732e656c2e70,0x2c32313170250920\n"
".quad 0x25202c3734722520,0x40090a3b37333672,0x7262203231317025,0x315f744c24092061\n"
".quad 0x3b3039323237315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009323534310938,0x33752e726873090a\n"
".quad 0x3833367225092032,0x202c37357225202c,0x6c6873090a3b3133,0x722509203233622e\n"
".quad 0x347225202c393336,0x61090a3b31202c37,0x09203233752e6464,0x7225202c37347225\n"
".quad 0x367225202c383336,0x6f6c2e090a3b3933,0x3534310938310963,0x6c6873090a300933\n"
".quad 0x722509203233622e,0x37357225202c3735,0x6c2e090a3b31202c,0x343109383109636f\n"
".quad 0x7573090a30093435,0x2509203233752e62,0x387225202c373872,0x4c240a3b31202c37\n"
".quad 0x323237315f315f74,0x3c2f2f200a3a3039,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x3132315f315f4c24,0x6f6c2e090a303930,0x3534310938310963,0x766f6d090a300936\n"
".quad 0x722509203233752e,0x0a3b30202c303436,0x2e656e2e74657309,0x203233752e323375\n"
".quad 0x202c313436722509,0x7225202c37357225,0x656e090a3b303436,0x2509203233732e67\n"
".quad 0x7225202c32343672,0x6461090a3b313436,0x2509203233752e64,0x367225202c373472\n"
".quad 0x37347225202c3234,0x09636f6c2e090a3b,0x0938353431093831,0x622e6c6873090a30\n"
".quad 0x3436722509203233,0x2c37347225202c33,0x6f6d090a3b343220,0x2509203233732e76\n"
".quad 0x3b30202c34343672,0x746c2e746573090a,0x3233732e3233752e,0x2c35343672250920\n"
".quad 0x202c333436722520,0x090a3b3434367225,0x203233732e67656e,0x202c363436722509\n"
".quad 0x090a3b3534367225,0x203233752e726873,0x202c373436722509,0x3b38202c37347225\n"
".quad 0x33752e646461090a,0x3834367225092032,0x202c37387225202c,0x6873090a3b363231\n"
".quad 0x2509203233622e6c,0x7225202c39343672,0x3b3332202c383436,0x33752e646461090a\n"
".quad 0x3035367225092032,0x2c3734367225202c,0x0a3b393436722520,0x3233752e64646109\n"
".quad 0x2c31353672250920,0x202c363436722520,0x090a3b3035367225,0x09203233622e726f\n"
".quad 0x25202c3235367225,0x367225202c383372,0x766f6d090a3b3135,0x662509203233622e\n"
".quad 0x35367225202c3831,0x2e617262090a3b32,0x444c240920696e75,0x5f5f5f69646e6557\n"
".quad 0x6c616e7265746e69,0x37315f64616d665f,0x744c240a3b365f38,0x39313836315f315f\n"
".quad 0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3036343109383109,0x2e766f6d090a3009,0x3366250920323366\n"
".quad 0x66336630202c3131,0x203b333839663232,0x2e30202f2f092020,0x6d090a3236363336\n"
".quad 0x09203233662e6c75,0x25202c3231336625,0x6625202c35303366,0x7663090a3b313133\n"
".quad 0x33732e696e722e74,0x2509203233662e32,0x6625202c33353672,0x6c2e090a3b323133\n"
".quad 0x343109383109636f,0x7663090a30093536,0x3233662e6e722e74,0x662509203233732e\n"
".quad 0x367225202c333133,0x67656e090a3b3335,0x662509203233662e,0x336625202c343133\n"
".quad 0x766f6d090a3b3331,0x662509203233662e,0x336630202c353133,0x3b30326161646639\n"
".quad 0x30202f2f09202020,0x383338343030302e,0x2e766f6d090a3732,0x3366250920323366\n"
".quad 0x66336630202c3631,0x203b303030303963,0x2e31202f2f092020,0x66090a3133303735\n"
".quad 0x33662e6e722e616d,0x3731336625092032,0x2c3431336625202c,0x202c363133662520\n"
".quad 0x090a3b3530336625,0x662e6e722e616d66,0x3133662509203233,0x3431336625202c38\n"
".quad 0x2c3531336625202c,0x0a3b373133662520,0x383109636f6c2e09,0x0a30093137343109\n"
".quad 0x3233732e766f6d09,0x202c353872250920,0x090a3b3335367225,0x09383109636f6c2e\n"
".quad 0x090a300932373431,0x203233662e766f6d,0x202c393133662509,0x3361353865326630\n"
".quad 0x2f092020203b3930,0x313737302e36202f,0x6d66090a31312d65,0x3233662e6e722e61\n"
".quad 0x202c383166250920,0x25202c3431336625,0x6625202c39313366,0x444c240a3b383133\n"
".quad 0x5f5f5f69646e6557,0x6c616e7265746e69,0x37315f64616d665f,0x2f2f200a3a365f38\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031\n"
".quad 0x373109383109636f,0x6461090a30093530,0x2509203233732e64,0x7225202c39303172\n"
".quad 0x090a3b31202c3538,0x203233662e766f6d,0x202c303233662509,0x6d090a3b38316625\n"
".quad 0x09203233662e6c75,0x6625202c39326625,0x336625202c303233,0x646e61090a3b3032\n"
".quad 0x722509203233622e,0x317225202c343536,0x090a3b31202c3930,0x203233752e766f6d\n"
".quad 0x202c353536722509,0x70746573090a3b30,0x203233732e71652e,0x202c333131702509\n"
".quad 0x25202c3435367225,0x40090a3b35353672,0x7262203331317025,0x315f744c24092061\n"
".quad 0x3b3835303337315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009393037310938,0x33662e766f6d090a\n"
".quad 0x3132336625092032,0x636337336630202c,0x2020203b65633566,0x34342e32202f2f09\n"
".quad 0x0a35302d65323333,0x3233662e766f6d09,0x2c32323366250920,0x3036626162663020\n"
".quad 0x092020203b613136,0x30302e302d202f2f,0x090a333738383331,0x662e6e722e616d66\n"
".quad 0x3233662509203233,0x3132336625202c33,0x202c39326625202c,0x090a3b3232336625\n"
".quad 0x203233662e766f6d,0x202c343233662509,0x6161613264336630,0x2f092020203b3561\n"
".quad 0x363134302e30202f,0x616d66090a363636,0x203233662e6e722e,0x202c353233662509\n"
".quad 0x25202c3332336625,0x336625202c393266,0x766f6d090a3b3432,0x662509203233662e\n"
".quad 0x626630202c363233,0x3b30303030303066,0x2d202f2f09202020,0x616d66090a352e30\n"
".quad 0x203233662e6e722e,0x202c373233662509,0x25202c3532336625,0x336625202c393266\n"
".quad 0x766f6d090a3b3632,0x662509203233662e,0x336630202c383233,0x3b30303030303866\n"
".quad 0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e,0x32336625202c3833\n"
".quad 0x2c39326625202c37,0x0a3b383233662520,0x696e752e61726209,0x5f315f744c240920\n"
".quad 0x0a3b323038323731,0x37315f315f744c24,0x2f200a3a38353033,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037\n"
".quad 0x656c6562616c2064,0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c\n"
".quad 0x6d090a3009313137,0x09203233662e766f,0x30202c3932336625,0x6631616334396266\n"
".quad 0x2f2f092020203b39,0x313030302e302d20,0x6d090a3335313539,0x09203233662e766f\n"
".quad 0x30202c3033336625,0x3933383830633366,0x2f2f092020203b65,0x33333830302e3020\n"
".quad 0x616d66090a363132,0x203233662e6e722e,0x202c313333662509,0x25202c3932336625\n"
".quad 0x336625202c393266,0x766f6d090a3b3033,0x662509203233662e,0x626630202c323333\n"
".quad 0x3b33616161613265,0x2d202f2f09202020,0x3736363636312e30,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x336625202c333333,0x39326625202c3133,0x3b3233336625202c\n"
".quad 0x33662e6c756d090a,0x3433336625092032,0x202c39326625202c,0x090a3b3333336625\n"
".quad 0x662e6e722e616d66,0x3833662509203233,0x2c3433336625202c,0x202c303233662520\n"
".quad 0x240a3b3032336625,0x3237315f315f744c,0x2f2f200a3a323038,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x373109383109636f\n"
".quad 0x656e090a30093331,0x2509203233662e67,0x6625202c35333366,0x646e61090a3b3833\n"
".quad 0x722509203233622e,0x317225202c363536,0x090a3b32202c3930,0x203233732e766f6d\n"
".quad 0x202c373536722509,0x70746573090a3b30,0x203233732e656e2e,0x202c343131702509\n"
".quad 0x25202c3635367225,0x73090a3b37353672,0x203233662e706c65,0x25202c3833662509\n"
".quad 0x6625202c35333366,0x31317025202c3833,0x636f6c2e090a3b34,0x3631373109383109\n"
".quad 0x2e766f6d090a3009,0x3366250920323366,0x38336625202c3930,0x6e6557444c240a3b\n"
".quad 0x6973695f5f5f6964,0x5f3837315f66666e,0x6c3c2f2f200a3a35,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039,0x3833363109383109\n"
".quad 0x706c6573090a3009,0x722509203233732e,0x202c31202c383536,0x3330317025202c30\n"
".quad 0x662e766f6d090a3b,0x3333662509203233,0x3030306630202c36,0x20203b3030303030\n"
".quad 0x090a30202f2f0920,0x752e71652e746573,0x09203233662e3233,0x25202c3935367225\n"
".quad 0x6625202c35303366,0x656e090a3b363333,0x2509203233732e67,0x7225202c30363672\n"
".quad 0x726f090a3b393536,0x722509203233622e,0x367225202c313636,0x36367225202c3835\n"
".quad 0x2e766f6d090a3b30,0x3672250920323375,0x090a3b30202c3236,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x36367225202c3531,0x3236367225202c31,0x3131702540090a3b\n"
".quad 0x2409206172622035,0x3337315f315f744c,0x2f2f200a3b343133,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x363109383109636f\n"
".quad 0x6f6d090a30093933,0x2509203233662e76,0x6630202c37333366,0x3030303030303030\n"
".quad 0x202f2f092020203b,0x722e6c756d090a30,0x2509203233662e6e,0x336625202c383466\n"
".quad 0x33336625202c3530,0x2e617262090a3b37,0x444c240920696e75,0x5f5f5f69646e6557\n"
".quad 0x315f66666e697369,0x4c240a3b315f3837,0x333337315f315f74,0x3c2f2f200a3a3431\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24,0x766f6d090a303930\n"
".quad 0x662509203233662e,0x346630202c383333,0x3b30303761623337,0x34202f2f09202020\n"
".quad 0x6573090a39333038,0x33662e74672e7074,0x3631317025092032,0x2c3630336625202c\n"
".quad 0x0a3b383333662520,0x3631317025214009,0x4c24092061726220,0x383337315f315f74\n"
".quad 0x3c2f2f200a3b3632,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30373120656e696c,0x2064616568202c32,0x2064656c6562616c,0x3132315f315f4c24\n"
".quad 0x6f6c2e090a303930,0x3933310938310963,0x766f6d090a300936,0x722509203233622e\n"
".quad 0x336625202c333636,0x646e61090a3b3530,0x722509203233622e,0x367225202c333935\n"
".quad 0x3431322d202c3336,0x3b38343633383437,0x33732e766f6d090a,0x3032317225092032\n"
".quad 0x3b3339357225202c,0x3109636f6c2e090a,0x3009323034310938,0x33622e6c6873090a\n"
".quad 0x3436367225092032,0x2c3336367225202c,0x726873090a3b3120,0x722509203233752e\n"
".quad 0x367225202c353636,0x0a3b3432202c3436,0x3233752e62757309,0x2c36393572250920\n"
".quad 0x202c353636722520,0x6c2e090a3b383231,0x343209383109636f,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x30337225202c3332,0x752e646461090a3b,0x3334722509203233\n"
".quad 0x202c30337225202c,0x766f6d090a3b3432,0x722509203233752e,0x635f5f202c343231\n"
".quad 0x75635f5f5f616475,0x6c757365725f6164,0x3932303136315f74,0x2e6c6873090a3b36\n"
".quad 0x3672250920323362,0x36367225202c3636,0x6f090a3b38202c33,0x2509203233622e72\n"
".quad 0x7225202c38393572,0x31322d202c363636,0x3834363338343734,0x752e766f6d090a3b\n"
".quad 0x3231722509203233,0x4c240a3b30202c36,0x383437315f315f74,0x72702e090a3a3035\n"
".quad 0x6f6e2220616d6761,0x3b226c6c6f726e75,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x656e202c34322065,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6f69746172657469,0x2e090a36203a736e,0x3109383109636f6c,0x6c090a3009303134\n"
".quad 0x2e74736e6f632e64,0x3172250920323375,0x3172255b202c3732,0x090a3b5d302b3332\n"
".quad 0x752e6f6c2e6c756d,0x3636722509203233,0x3732317225202c37,0x3b3839357225202c\n"
".quad 0x33752e646461090a,0x3836367225092032,0x2c3736367225202c,0x0a3b363231722520\n"
".quad 0x383109636f6c2e09,0x0a30093131343109,0x2e74672e74657309,0x203233752e323375\n"
".quad 0x202c393636722509,0x25202c3736367225,0x6e090a3b38363672,0x09203233732e6765\n"
".quad 0x25202c3037367225,0x6d090a3b39363672,0x33752e69682e6c75,0x3137367225092032\n"
".quad 0x2c3732317225202c,0x0a3b383935722520,0x3233752e64646109,0x2c36323172250920\n"
".quad 0x202c303736722520,0x090a3b3137367225,0x09383109636f6c2e,0x090a300932313431\n"
".quad 0x6c61636f6c2e7473,0x255b09203233752e,0x2c5d302b34323172,0x0a3b383636722520\n"
".quad 0x3233752e64646109,0x2c34323172250920,0x202c343231722520,0x2e646461090a3b34\n"
".quad 0x3172250920323375,0x32317225202c3332,0x73090a3b34202c33,0x752e656e2e707465\n"
".quad 0x3131702509203233,0x3332317225202c37,0x0a3b33347225202c,0x2037313170254009\n"
".quad 0x744c240920617262,0x35383437315f315f,0x6c3c2f2f200a3b30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x636f6c2e090a3039,0x3431343109383109\n"
".quad 0x6c2e7473090a3009,0x3233752e6c61636f,0x6475635f5f5b0920,0x616475635f5f5f61\n"
".quad 0x5f746c757365725f,0x2b36393230313631,0x317225202c5d3432,0x6f6c2e090a3b3632\n"
".quad 0x3134310938310963,0x726873090a300939,0x722509203233752e,0x357225202c323736\n"
".quad 0x090a3b35202c3639,0x752e6f6c2e6c756d,0x3736722509203233,0x3237367225202c33\n"
".quad 0x7573090a3b34202c,0x2509203233752e62,0x7225202c35333172,0x37367225202c3233\n"
".quad 0x6c2e646c090a3b33,0x3233752e6c61636f,0x2c36323172250920,0x2b35333172255b20\n"
".quad 0x6c2e090a3b5d3432,0x343109383109636f,0x646c090a30093032,0x752e6c61636f6c2e\n"
".quad 0x3331722509203233,0x333172255b202c36,0x090a3b5d30322b35,0x203233622e646e61\n"
".quad 0x202c363036722509,0x33202c3639357225,0x2e766f6d090a3b31,0x3672250920323375\n"
".quad 0x090a3b30202c3437,0x2e71652e70746573,0x3170250920323375,0x30367225202c3831\n"
".quad 0x3437367225202c36,0x3131702540090a3b,0x2409206172622038,0x3537315f315f744c\n"
".quad 0x2f2f200a3b323633,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20,0x32315f315f4c2420\n"
".quad 0x6c2e090a30393031,0x343109383109636f,0x6f6d090a30093332,0x2509203233732e76\n"
".quad 0x3233202c35373672,0x732e627573090a3b,0x3736722509203233,0x3537367225202c36\n"
".quad 0x3b3630367225202c,0x33752e726873090a,0x3737367225092032,0x2c3633317225202c\n"
".quad 0x0a3b363736722520,0x3233622e6c687309,0x2c38373672250920,0x202c363231722520\n"
".quad 0x090a3b3630367225,0x203233752e646461,0x202c363231722509,0x25202c3737367225\n"
".quad 0x2e090a3b38373672,0x3109383109636f6c,0x6c090a3009343234,0x2e6c61636f6c2e64\n"
".quad 0x3672250920323375,0x3172255b202c3937,0x0a3b5d36312b3533,0x3233752e72687309\n"
".quad 0x2c30383672250920,0x202c393736722520,0x090a3b3637367225,0x203233622e6c6873\n"
".quad 0x202c313836722509,0x25202c3633317225,0x61090a3b36303672,0x09203233752e6464\n"
".quad 0x25202c3633317225,0x7225202c30383672,0x744c240a3b313836,0x36333537315f315f\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x3230373120656e69,0x6c2064616568202c,0x242064656c656261,0x303132315f315f4c\n"
".quad 0x636f6c2e090a3039,0x3632343109383109,0x2e726873090a3009,0x3172250920323375\n"
".quad 0x32317225202c3534,0x090a3b3033202c36,0x09383109636f6c2e,0x090a300938323431\n"
".quad 0x203233752e726873,0x202c323836722509,0x33202c3633317225,0x2e6c6873090a3b30\n"
".quad 0x3672250920323362,0x32317225202c3338,0x61090a3b32202c36,0x09203233752e6464\n"
".quad 0x25202c3632317225,0x7225202c32383672,0x6c2e090a3b333836,0x343109383109636f\n"
".quad 0x6873090a30093932,0x2509203233622e6c,0x7225202c36333172,0x0a3b32202c363331\n"
".quad 0x3233752e766f6d09,0x2c34383672250920,0x746573090a3b3020,0x3233752e71652e70\n"
".quad 0x2c39313170250920,0x202c363331722520,0x090a3b3438367225,0x6220393131702540\n"
".quad 0x5f744c2409206172,0x3033313637315f31,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x2c3230373120656e,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x39303132315f315f,0x09636f6c2e090a30,0x0930333431093831\n"
".quad 0x752e646461090a30,0x3836722509203233,0x3632317225202c35,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x322d202c36383672,0x3436333834373431,0x2e746573090a3b38\n"
".quad 0x752e3233752e7467,0x3836722509203233,0x3538367225202c37,0x3b3638367225202c\n"
".quad 0x33732e67656e090a,0x3838367225092032,0x3b3738367225202c,0x6e752e617262090a\n"
".quad 0x315f744c24092069,0x3b3437383537315f,0x315f315f744c240a,0x200a3a3033313637\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x6568202c32303731,0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231\n"
".quad 0x203233752e766f6d,0x202c393836722509,0x333834373431322d,0x6573090a3b383436\n"
".quad 0x3233752e74672e74,0x722509203233752e,0x317225202c303936,0x38367225202c3632\n"
".quad 0x2e67656e090a3b39,0x3672250920323373,0x39367225202c3838,0x315f744c240a3b30\n"
".quad 0x3a3437383537315f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x202c323037312065,0x62616c2064616568,0x5f4c242064656c65\n"
".quad 0x3039303132315f31,0x3109636f6c2e090a,0x3009313334310938,0x33752e646461090a\n"
".quad 0x3139367225092032,0x2c3534317225202c,0x0a3b383836722520,0x383109636f6c2e09\n"
".quad 0x0a30093033343109,0x3233732e67656e09,0x2c32393672250920,0x0a3b313936722520\n"
".quad 0x3233752e766f6d09,0x2c33393672250920,0x746573090a3b3020,0x3233752e656e2e70\n"
".quad 0x2c30323170250920,0x202c333935722520,0x090a3b3339367225,0x3233732e706c6573\n"
".quad 0x2c35343172250920,0x202c323936722520,0x25202c3139367225,0x6d090a3b30323170\n"
".quad 0x09203233752e766f,0x30202c3439367225,0x2e70746573090a3b,0x09203233752e7165\n"
".quad 0x25202c3132317025,0x7225202c38383672,0x2540090a3b343936,0x6172622031323170\n"
".quad 0x5f315f744c240920,0x0a3b363833363731,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093633343109\n"
".quad 0x3233732e67656e09,0x2c36333172250920,0x0a3b363331722520,0x383109636f6c2e09\n"
".quad 0x0a30093833343109,0x3233752e766f6d09,0x2c35393672250920,0x746573090a3b3020\n"
".quad 0x2e3233752e71652e,0x3672250920323375,0x33317225202c3639,0x3539367225202c36\n"
".quad 0x732e67656e090a3b,0x3936722509203233,0x3639367225202c37,0x622e746f6e090a3b\n"
".quad 0x3936722509203233,0x3632317225202c38,0x752e646461090a3b,0x3231722509203233\n"
".quad 0x3739367225202c36,0x3b3839367225202c,0x3109636f6c2e090a,0x3009393334310938\n"
".quad 0x33622e726f78090a,0x3032317225092032,0x2c3339357225202c,0x3834373431322d20\n"
".quad 0x4c240a3b38343633,0x333637315f315f74,0x3c2f2f200a3a3638,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30373120656e696c,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x3132315f315f4c24,0x6f6c2e090a303930,0x3434310938310963\n"
".quad 0x766f6d090a300931,0x722509203233732e,0x317225202c333631,0x766f6d090a3b3534\n"
".quad 0x722509203233752e,0x0a3b30202c393936,0x656c2e7074657309,0x702509203233732e\n"
".quad 0x317225202c323231,0x39367225202c3632,0x31702540090a3b39,0x0920617262203232\n"
".quad 0x38315f315f744c24,0x2f200a3b30333532,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x6d090a3039303132,0x09203233752e766f,0x30202c3536317225\n"
".quad 0x5f315f744c240a3b,0x0a3a303134373731,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x6e202c3134343120,0x6420676e69747365,0x2c31203a68747065\n"
".quad 0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e\n"
".quad 0x09383109636f6c2e,0x090a300935343431,0x203233752e726873,0x202c303037722509\n"
".quad 0x33202c3633317225,0x2e6c6873090a3b31,0x3772250920323362,0x32317225202c3130\n"
".quad 0x61090a3b31202c36,0x09203233752e6464,0x25202c3632317225,0x7225202c30303772\n"
".quad 0x6c2e090a3b313037,0x343109383109636f,0x6873090a30093634,0x2509203233622e6c\n"
".quad 0x7225202c36333172,0x0a3b31202c363331,0x383109636f6c2e09,0x0a30093734343109\n"
".quad 0x3233752e62757309,0x2c35363172250920,0x202c353631722520,0x2e766f6d090a3b31\n"
".quad 0x3772250920323375,0x090a3b30202c3230,0x2e74672e70746573,0x3170250920323373\n"
".quad 0x32317225202c3332,0x3230377225202c36,0x3231702540090a3b,0x2409206172622033\n"
".quad 0x3737315f315f744c,0x2f2f200a3b303134,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x7262090a30393031,0x240920696e752e61,0x3637315f315f744c\n"
".quad 0x744c240a3b383938,0x33353238315f315f,0x6c3c2f2f200a3a30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x2e766f6d090a3039,0x3172250920323375\n"
".quad 0x240a3b30202c3536,0x3637315f315f744c,0x2f2f200a3a383938,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f\n"
".quad 0x756d090a30093934,0x3233752e6f6c2e6c,0x2c36333172250920,0x202c363231722520\n"
".quad 0x383730373132392d,0x6f6c2e090a3b3037,0x3534310938310963,0x766f6d090a300930\n"
".quad 0x722509203233752e,0x32392d202c333037,0x3b30373837303731,0x69682e6c756d090a\n"
".quad 0x722509203233752e,0x317225202c363231,0x30377225202c3632,0x2e766f6d090a3b33\n"
".quad 0x3772250920323375,0x090a3b30202c3430,0x2e656c2e70746573,0x3170250920323373\n"
".quad 0x32317225202c3432,0x3430377225202c36,0x3231702540090a3b,0x2409206172622034\n"
".quad 0x3737315f315f744c,0x2f2f200a3b323239,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230,0x64656c6562616c20\n"
".quad 0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f,0x6873090a30093235\n"
".quad 0x2509203233752e72,0x7225202c35303772,0x3b3133202c363331,0x33622e6c6873090a\n"
".quad 0x3630377225092032,0x2c3632317225202c,0x646461090a3b3120,0x722509203233752e\n"
".quad 0x377225202c363231,0x30377225202c3530,0x636f6c2e090a3b36,0x3335343109383109\n"
".quad 0x2e6c6873090a3009,0x3172250920323362,0x33317225202c3633,0x2e090a3b31202c36\n"
".quad 0x3109383109636f6c,0x73090a3009343534,0x09203233752e6275,0x25202c3536317225\n"
".quad 0x3b31202c35363172,0x315f315f744c240a,0x200a3a3232393737,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e\n"
".quad 0x090a300936353431,0x203233752e766f6d,0x202c373037722509,0x2e746573090a3b30\n"
".quad 0x752e3233752e656e,0x3037722509203233,0x3633317225202c38,0x3b3730377225202c\n"
".quad 0x33732e67656e090a,0x3930377225092032,0x3b3830377225202c,0x33752e646461090a\n"
".quad 0x3632317225092032,0x2c3930377225202c,0x0a3b363231722520,0x383109636f6c2e09\n"
".quad 0x0a30093835343109,0x3233622e6c687309,0x2c30313772250920,0x202c363231722520\n"
".quad 0x766f6d090a3b3432,0x722509203233732e,0x0a3b30202c313137,0x2e746c2e74657309\n"
".quad 0x203233732e323375,0x202c323137722509,0x25202c3031377225,0x6e090a3b31313772\n"
".quad 0x09203233732e6765,0x25202c3331377225,0x73090a3b32313772,0x09203233752e7268\n"
".quad 0x25202c3431377225,0x3b38202c36323172,0x33752e646461090a,0x3531377225092032\n"
".quad 0x2c3536317225202c,0x73090a3b36323120,0x09203233622e6c68,0x25202c3631377225\n"
".quad 0x3332202c35313772,0x752e646461090a3b,0x3137722509203233,0x3431377225202c37\n"
".quad 0x3b3631377225202c,0x33752e646461090a,0x3831377225092032,0x2c3331377225202c\n"
".quad 0x0a3b373137722520,0x203233622e726f09,0x202c393137722509,0x25202c3032317225\n"
".quad 0x6d090a3b38313772,0x09203233622e766f,0x7225202c30356625,0x7262090a3b393137\n"
".quad 0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f,0x5f64616d665f6c61\n"
".quad 0x240a3b325f383731,0x3337315f315f744c,0x2f2f200a3a363238,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20,0x64616568202c3230\n"
".quad 0x64656c6562616c20,0x32315f315f4c2420,0x6c2e090a30393031,0x343109383109636f\n"
".quad 0x6f6d090a30093036,0x2509203233662e76,0x6630202c39333366,0x3338396632326633\n"
".quad 0x202f2f092020203b,0x0a32363633362e30,0x3233662e6c756d09,0x2c30343366250920\n"
".quad 0x202c353033662520,0x090a3b3933336625,0x2e696e722e747663,0x203233662e323373\n"
".quad 0x202c303237722509,0x090a3b3034336625,0x09383109636f6c2e,0x090a300935363431\n"
".quad 0x662e6e722e747663,0x09203233732e3233,0x25202c3134336625,0x6e090a3b30323772\n"
".quad 0x09203233662e6765,0x25202c3234336625,0x6d090a3b31343366,0x09203233662e766f\n"
".quad 0x30202c3334336625,0x3261616466393366,0x2f2f092020203b30,0x38343030302e3020\n"
".quad 0x6f6d090a37323833,0x2509203233662e76,0x6630202c34343366,0x3030303039636633\n"
".quad 0x202f2f092020203b,0x0a31333037352e31,0x2e6e722e616d6609,0x3366250920323366\n"
".quad 0x34336625202c3534,0x3434336625202c32,0x3b3530336625202c,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x336625202c363433,0x34336625202c3234,0x3534336625202c33\n"
".quad 0x09636f6c2e090a3b,0x0931373431093831,0x732e766f6d090a30,0x3631722509203233\n"
".quad 0x3032377225202c33,0x09636f6c2e090a3b,0x0932373431093831,0x662e766f6d090a30\n"
".quad 0x3433662509203233,0x3865326630202c37,0x20203b3930336135,0x302e36202f2f0920\n"
".quad 0x0a31312d65313737,0x2e6e722e616d6609,0x3566250920323366,0x3234336625202c30\n"
".quad 0x2c3734336625202c,0x0a3b363433662520,0x69646e6557444c24,0x7265746e695f5f5f\n"
".quad 0x64616d665f6c616e,0x0a3a325f3837315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x68202c3230373120,0x6562616c20646165\n"
".quad 0x315f4c242064656c,0x0a3039303132315f,0x383109636f6c2e09,0x0a30093134363109\n"
".quad 0x3233662e766f6d09,0x2c38343366250920,0x090a3b3035662520,0x203233662e6c756d\n"
".quad 0x25202c3136662509,0x6625202c38343366,0x6e61090a3b383433,0x2509203233622e64\n"
".quad 0x7225202c31323772,0x0a3b31202c333631,0x3233752e766f6d09,0x2c32323772250920\n"
".quad 0x746573090a3b3020,0x3233732e71652e70,0x2c35323170250920,0x202c313237722520\n"
".quad 0x090a3b3232377225,0x6220353231702540,0x5f744c2409206172,0x3039363837315f31\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x2c3230373120656e,0x616c206461656820,0x4c242064656c6562,0x39303132315f315f\n"
".quad 0x09636f6c2e090a30,0x0934343631093831,0x662e766f6d090a30,0x3433662509203233\n"
".quad 0x6337336630202c39,0x20203b6563356663,0x342e32202f2f0920,0x35302d6532333334\n"
".quad 0x33662e766f6d090a,0x3035336625092032,0x366261626630202c,0x2020203b61313630\n"
".quad 0x302e302d202f2f09,0x0a33373838333130,0x2e6e722e616d6609,0x3366250920323366\n"
".quad 0x34336625202c3135,0x2c31366625202c39,0x0a3b303533662520,0x3233662e766f6d09\n"
".quad 0x2c32353366250920,0x6161326433663020,0x092020203b356161,0x3134302e30202f2f\n"
".quad 0x6d66090a36363636,0x3233662e6e722e61,0x2c33353366250920,0x202c313533662520\n"
".quad 0x6625202c31366625,0x6f6d090a3b323533,0x2509203233662e76,0x6630202c34353366\n"
".quad 0x3030303030306662,0x202f2f092020203b,0x6d66090a352e302d,0x3233662e6e722e61\n"
".quad 0x2c35353366250920,0x202c333533662520,0x6625202c31366625,0x6f6d090a3b343533\n"
".quad 0x2509203233662e76,0x6630202c36353366,0x3030303030386633,0x202f2f092020203b\n"
".quad 0x722e616d66090a31,0x2509203233662e6e,0x336625202c303766,0x31366625202c3535\n"
".quad 0x3b3635336625202c,0x6e752e617262090a,0x315f744c24092069,0x3b3433343837315f\n"
".quad 0x315f315f744c240a,0x200a3a3039363837,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x6568202c32303731,0x6c6562616c206461\n"
".quad 0x5f315f4c24206465,0x090a303930313231,0x09383109636f6c2e,0x090a300936343631\n"
".quad 0x203233662e766f6d,0x202c373533662509,0x3161633439626630,0x2f092020203b3966\n"
".quad 0x3030302e302d202f,0x090a333531353931,0x203233662e766f6d,0x202c383533662509\n"
".quad 0x3338383063336630,0x2f092020203b6539,0x333830302e30202f,0x6d66090a36313233\n"
".quad 0x3233662e6e722e61,0x2c39353366250920,0x202c373533662520,0x6625202c31366625\n"
".quad 0x6f6d090a3b383533,0x2509203233662e76,0x6630202c30363366,0x3361616161326562\n"
".quad 0x202f2f092020203b,0x36363636312e302d,0x722e616d66090a37,0x2509203233662e6e\n"
".quad 0x6625202c31363366,0x366625202c393533,0x3036336625202c31,0x662e6c756d090a3b\n"
".quad 0x3633662509203233,0x2c31366625202c32,0x0a3b313633662520,0x2e6e722e616d6609\n"
".quad 0x3766250920323366,0x3236336625202c30,0x2c3834336625202c,0x0a3b383433662520\n"
".quad 0x37315f315f744c24,0x2f200a3a34333438,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x616568202c323037,0x656c6562616c2064\n"
".quad 0x315f315f4c242064,0x2e090a3039303132,0x3109383109636f6c,0x6e090a3009383436\n"
".quad 0x09203233662e6765,0x25202c3336336625,0x6e61090a3b303766,0x2509203233622e64\n"
".quad 0x7225202c33323772,0x0a3b32202c333631,0x3233732e766f6d09,0x2c34323772250920\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x2c36323170250920,0x202c333237722520\n"
".quad 0x090a3b3432377225,0x3233662e706c6573,0x202c303766250920,0x25202c3336336625\n"
".quad 0x317025202c303766,0x6f6c2e090a3b3632,0x3536310938310963,0x766f6d090a300931\n"
".quad 0x662509203233662e,0x30376625202c3834,0x6e6557444c240a3b,0x6973695f5f5f6964\n"
".quad 0x5f3837315f66666e,0x6c3c2f2f200a3a31,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x303132315f315f4c,0x636f6c2e090a3039,0x3009343331093309,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x5b202c3436336625,0x5d36372b35337225,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x202c353633662509,0x32372b353372255b,0x2e6c756d090a3b5d\n"
".quad 0x3366250920323366,0x38346625202c3636,0x3b3436336625202c,0x33662e6c756d090a\n"
".quad 0x3736336625092032,0x2c3536336625202c,0x0a3b393033662520,0x3233662e62757309\n"
".quad 0x2c38363366250920,0x202c373633662520,0x090a3b3636336625,0x203233662e646461\n"
".quad 0x6625202c34662509,0x3836336625202c34,0x09636f6c2e090a3b,0x0a30093533310933\n"
".quad 0x3233662e6c756d09,0x2c39363366250920,0x202c393033662520,0x090a3b3436336625\n"
".quad 0x662e6e722e616d66,0x3733662509203233,0x3536336625202c30,0x202c38346625202c\n"
".quad 0x090a3b3936336625,0x203233662e646461,0x6625202c35662509,0x3037336625202c35\n"
".quad 0x09636f6c2e090a3b,0x0a30093330310933,0x3233732e64646109,0x202c393272250920\n"
".quad 0x3b34202c39327225,0x33732e646461090a,0x202c327225092032,0x0a3b34202c327225\n"
".quad 0x3233752e766f6d09,0x2c35323772250920,0x73090a3b31313520,0x732e74672e707465\n"
".quad 0x3231702509203233,0x2c39327225202c37,0x0a3b353237722520,0x2037323170254009\n"
".quad 0x744c240920617262,0x32323038315f315f,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x3230373120656e69,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x303132315f315f4c,0x70746573090a3039,0x203233732e746c2e\n"
".quad 0x202c383231702509,0x317225202c327225,0x31702540090a3b38,0x0920617262203832\n"
".quad 0x3132315f315f4c24,0x744c240a3b303930,0x32323038315f315f,0x5f315f4c240a3a36\n"
".quad 0x0a3a363433313231,0x093309636f6c2e09,0x73090a3009383331,0x6c61626f6c672e74\n"
".quad 0x255b09203233662e,0x202c5d302b353172,0x6c2e090a3b346625,0x393331093309636f\n"
".quad 0x672e7473090a3009,0x33662e6c61626f6c,0x373172255b092032,0x356625202c5d302b\n"
".quad 0x09636f6c2e090a3b,0x0a30093034310933,0x240a3b7469786509,0x5f5f646e6557444c\n"
".quad 0x75706d6f4333315a,0x5550475f48466574,0x5f535f5366506969,0x7d090a3a5f535f53\n"
".quad 0x33315a5f202f2f20,0x46657475706d6f43,0x5069695550475f48,0x535f535f535f5366\n"
".quad 0x00000000000a0a5f\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[11097];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010101464c457f,0x0000000000000004,0x0000000100be0002,0x00005adc00000000\n"
".quad 0x0014011500000034,0x0028000500200034,0x000000000001000e,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000100000000\n"
".quad 0x0000000000000003,0x0000026400000000,0x000000000000019c,0x0000000400000000\n"
".quad 0x0000000b00000000,0x0000000000000003,0x0000040000000000,0x0000000000000054\n"
".quad 0x0000000100000000,0x0000001300000000,0x0000000000000002,0x0000045400000000\n"
".quad 0x0000000200000140,0x0000000100000010,0x0000008a00000010,0x0000000600000001\n"
".quad 0x0000059400000000,0x00000003000000b8,0x0000000409000009,0x0000015e00000000\n"
".quad 0x0000000200000001,0x0000064c00000000,0x000000000000003c,0x0000000400000004\n"
".quad 0x000000b200000000,0x0000000200000001,0x0000068800000000,0x00000000000000ac\n"
".quad 0x0000000100000004,0x0000003600000000,0x0000000600000001,0x0000073400000000\n"
".quad 0x0000000300002a48,0x0000000418000006,0x0000013200000000,0x0000000200000001\n"
".quad 0x0000317c00000000,0x000000000000003c,0x0000000400000007,0x0000010500000000\n"
".quad 0x0000000200000001,0x000031b800000000,0x0000000000000030,0x0000000400000007\n"
".quad 0x0000005a00000000,0x0000000200000001,0x000031e800000000,0x00000000000000ac\n"
".quad 0x0000000100000007,0x000000dd00000000,0x0000000300000008,0x0000329400000000\n"
".quad 0x0000000000000004,0x0000000400000007,0x0000018e00000000,0x0000000200000001\n"
".quad 0x0000329400000000,0x0000000000002818,0x0000000400000000,0x0000008100000000\n"
".quad 0x0000000200000001,0x00005aac00000000,0x0000000000000030,0x0000000100000000\n"
".quad 0x68732e0000000000,0x2e00626174727473,0x2e00626174727473,0x2e006261746d7973\n"
".quad 0x61626f6c672e766e,0x2e0074696e692e6c,0x61626f6c672e766e,0x2e747865742e006c\n"
".quad 0x706d6f4333315a5f,0x50475f4846657475,0x535f536650696955,0x6e2e005f535f535f\n"
".quad 0x5f2e6f666e692e76,0x75706d6f4333315a,0x5550475f48466574,0x5f535f5366506969\n"
".quad 0x766e2e005f535f53,0x742e006f666e692e,0x36315a5f2e747865,0x52657475706d6f43\n"
".quad 0x5550476968506f68,0x535f535f53665069,0x6e2e005f535f535f,0x5f2e6f666e692e76\n"
".quad 0x75706d6f4336315a,0x6968506f68526574,0x5f53665069555047,0x5f535f535f535f53\n"
".quad 0x636f6c2e766e2e00,0x4333315a5f2e6c61,0x4846657475706d6f,0x665069695550475f\n"
".quad 0x5f535f535f535f53,0x6e6f632e766e2e00,0x2e3631746e617473,0x706d6f4333315a5f\n"
".quad 0x50475f4846657475,0x535f536650696955,0x6e2e005f535f535f,0x6174736e6f632e76\n"
".quad 0x33315a5f2e30746e,0x46657475706d6f43,0x5069695550475f48,0x535f535f535f5366\n"
".quad 0x6f632e766e2e005f,0x2e30746e6174736e,0x706d6f4336315a5f,0x68506f6852657475\n"
".quad 0x5366506955504769,0x535f535f535f535f,0x6f632e766e2e005f,0x0032746e6174736e\n"
".quad 0x6d6f4333315a5f00,0x475f484665747570,0x5f53665069695550,0x5f005f535f535f53\n"
".quad 0x75706d6f4336315a,0x6968506f68526574,0x5f53665069555047,0x5f535f535f535f53\n"
".quad 0x72616475635f5f00,0x5f69706f32695f74,0x0000000000630066,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000010003,0x0000000000000000\n"
".quad 0x0000000000020003,0x0000000000000000,0x0000000000030003,0x0000000000000000\n"
".quad 0x0000000000000003,0x0000000000000000,0x0000000000000003,0x00002a4800000000\n"
".quad 0x0000000000070003,0x0000000000000000,0x00000000000a0003,0x0000000000000000\n"
".quad 0x00000000000d0003,0x000000b800000000,0x0000000000040003,0x0000000000000000\n"
".quad 0x0000000000060003,0x0000000000000000,0x00000000000b0003,0x0000000000000000\n"
".quad 0x0000000000090003,0x0000000000000000,0x0000000000080003,0x0000000000000000\n"
".quad 0x0000000000050003,0x0000000000000000,0x00000001000c0003,0x00002a4800000000\n"
".quad 0x0000001f00071012,0x000000b800000000,0x0000004100041012,0x0000001800002800\n"
".quad 0x00000052000c0011,0x0000280000000000,0x00005de4000c0011,0x94001c0428004404\n"
".quad 0x84009c042c000000,0x08001d232c000000,0x8001dc2340000000,0x000001e71b0e4000\n"
".quad 0xa000dc4380000000,0x90015c4340004000,0xc0009c4340004000,0x00311c8540004000\n"
".quad 0xb0019c4380000000,0x00515c8540004000,0xe0021c4380000000,0x00209c8540004000\n"
".quad 0x0060dc8580000000,0x08419c0080000000,0x0851dc0058000000,0xd0009c4358000000\n"
".quad 0x0c501c0040004000,0x0c40de00300c0000,0x00201c85300e0000,0x0080dc8590000000\n"
".quad 0x00001de790000000,0x0000000080000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000001c0c04,0x0000000800000004,0x000000100000000c\n"
".quad 0x0000001800000014,0x0000000e00080a04,0x001c1903001c0020,0xffffffff000c1704\n"
".quad 0x0011f00000180006,0xffffffff000c1704,0x0011f00000140005,0xffffffff000c1704\n"
".quad 0x0011f00000100004,0xffffffff000c1704,0x0011f000000c0003,0xffffffff000c1704\n"
".quad 0x0011f00000080002,0xffffffff000c1704,0x0011f00000040001,0xffffffff000c1704\n"
".quad 0x0011f00000000000,0x0001000c00080d04,0x00005de400000001,0x94001c0428004404\n"
".quad 0x00105d032c000000,0x84009c044800c001,0x08001d032c000000,0xa0009c4340000000\n"
".quad 0xb000dc4340004000,0xc0011c4340004000,0xd0029c4340004000,0xe002dc4340004000\n"
".quad 0x80001de440004000,0x00225c8528004000,0x90009d0380000000,0x00321c8548004000\n"
".quad 0xfc21dc2380000000,0x0041dc851a0ec007,0x90001de480000000,0x00a3dc8528004000\n"
".quad 0x00b41c8580000000,0xe00001e780000000,0x7c20dc2340000023,0x0c30dc035800c000\n"
".quad 0x0830dc036800c000,0x0830dc2348000000,0x08331c435800c000,0xfcc1dc2341000000\n"
".quad 0x400001e7198e0000,0x90009de440000022,0x8021dc2328004000,0x200001e71b0e4000\n"
".quad 0x20135c0340000022,0x90139c034800c000,0xfc019de44800c000,0x00001de428000000\n"
".quad 0x50645c0340000000,0xec015de25000c000,0x11109c8619006487,0x20209c0014000800\n"
".quad 0x0110dc8658000000,0x21111c8614000800,0x24309c0014000800,0xa000000730040000\n"
".quad 0x1c409c006000000f,0x60011de230040000,0x09309c04195110b4,0x10209c0110000000\n"
".quad 0x09a11c4450000000,0x0041dc0010000000,0x09a09c04210edfe0,0x200021e710000000\n"
".quad 0x0820dd1040000000,0x1443dc0050000000,0xc0000007220e4000,0xe00025e76000000b\n"
".quad 0x0420dc034000000a,0x20249c036000c000,0x60315c036000c000,0x90155c035800c000\n"
".quad 0x0020dc024800c000,0x00051de23a000000,0xfc04dde4180000a0,0x01249c4228000000\n"
".quad 0x00515c033a000000,0x01459c864800fffe,0x4965dc0314000800,0x11451c0350000000\n"
".quad 0x4d74dc034800c000,0x6143dc0348000000,0x4d75dc031a8ec0a0,0x0154dc85120e0000\n"
".quad 0x4964dd43c8000000,0x11555c03202e0000,0xc00005e74800c000,0x14549c034003fffe\n"
".quad 0x7c555c035800c000,0xfd53dc036800c000,0xf014dc85190e0000,0x39259c43c8000000\n"
".quad 0x61649c8541000000,0x51651c85c0000000,0x200085e7c0000000,0x8154e60340000001\n"
".quad 0x416164854800c000,0x5524a403c0000000,0x5545640360000000,0x4d45240360000000\n"
".quad 0x4944a40358000000,0x4c51640348000000,0x5455240358000000,0x00001de448000000\n"
".quad 0x09415c0340000000,0x7924dc036000c000,0x79451c035800c000,0xfc53dc035800c000\n"
".quad 0x51249c43190e0000,0xc000000740000000,0x600005e760000000,0x05251c0340000000\n"
".quad 0x2543dc034800c000,0x07f51c141a0e4000,0x2523dc032012c000,0x07f51c141a0e4000\n"
".quad 0x5134dc032012c000,0x4d251f8448000000,0x4d44dc031c000000,0xa000a5e732860000\n"
".quad 0x1521478440000000,0x4bf505c31c000000,0xfc54840368000000,0x0030c482110e0000\n"
".quad 0x512486033a000000,0xfd23dc2348000000,0x60000007198e0000,0x200005e760000001\n"
".quad 0xfc051de440000001,0x00001de428000000,0x7c555c0340000000,0xfd451c035800c000\n"
".quad 0x55249c234800ffff,0x04515c0340000000,0xfd23dc236000c000,0x400005e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc051df440000000,0x35255c4328000000,0xfd53dc2350004000\n"
".quad 0x89249c02198e0000,0x800085e713243f6a,0x7d21640340000000,0xfd4524035800c000\n"
".quad 0x0524a4034800ffff,0x155564236000c000,0xfd215c0340000000,0xf9451c03128e0000\n"
".quad 0x54515e034800c001,0x20549c0348000000,0x60515c035800c000,0x49449ee36000c000\n"
".quad 0xfc515c2340000000,0x48515e03108e0000,0x14349c5348000000,0x0c20dc0268000000\n"
".quad 0x0d24dc8430fc8be6,0x4d20de0414000000,0x40315e0018000000,0x44315e003004cff2\n"
".quad 0x54349e10300a4000,0x0530dc03300a4000,0x04315c034800c000,0xfc53dc236800c000\n"
".quad 0x49215c001a8e0000,0xc000a5e758000000,0x680485e240000000,0x645484001aead818\n"
".quad 0x7524840030244000,0x85248400300a8000,0x95214400300a8000,0xc00085e7300a8000\n"
".quad 0x7804e5e240000000,0xa454e40018f0220e,0xb534e40030264000,0x4c516400300a8000\n"
".quad 0x4851640058000000,0x00001de430240000,0x0830dc0340000000,0x15249d046800c000\n"
".quad 0x1520dc3310000000,0xfc21dc0032860000,0xa000000721200000,0x200021e76000000e\n"
".quad 0xfc209c1040000000,0x1441dc0058000000,0xc0000007220e4000,0xe00021e76000000b\n"
".quad 0x04211c034000000a,0x2024dc036000c000,0x60451c036000c000,0x00209c025800c000\n"
".quad 0x20111c033a000000,0x00015de24800c000,0xfc049de4180000a0,0x0134dc4228000000\n"
".quad 0x01451c033a000000,0x00555c864800fffe,0x4d559c0314000800,0x10515c0350000000\n"
".quad 0x49649c034800c000,0x6051dc0348000000,0x49659c031a8ec0a0,0x00449c85120e0000\n"
".quad 0x4d549d43c8000000,0x10411c03202c0000,0xc00001e74800c000,0x15411c034003fffe\n"
".quad 0x80149c855800c000,0x7d451c03c8000000,0x3444dc436800c000,0xfd41dc0341000000\n"
".quad 0x61311c85190e0000,0x51315c85c0000000,0x200081e7c0000000,0x8145620340000001\n"
".quad 0x4134a0854800c000,0x5045a003c0000000,0x5055200360000000,0x5451200360000000\n"
".quad 0x5841200358000000,0x5521600348000000,0x5051600358000000,0x00001de448000000\n"
".quad 0x08549c0340000000,0x400000076000c000,0x78515c0360000001,0xfd21dc035800c000\n"
".quad 0x7844dc03190e0000,0x14415c435800c000,0x600001e740000000,0x04511c0340000000\n"
".quad 0x2441dc034800c000,0x07f11c141a0e4000,0x2451dc032010c000,0x07f11c141a0e4000\n"
".quad 0x11311c032010c000,0x1124df8448000000,0x11311c031c000000,0xa000a1e732840000\n"
".quad 0x4924838440000000,0x17f4c1c31c000000,0xfd21400368000000,0x00208082110e0000\n"
".quad 0x4c5142033a000000,0xfc51dc2348000000,0x60000007198e0000,0x200001e760000001\n"
".quad 0xfc04dde440000001,0x00001de428000000,0x7d251c0340000000,0xfd34dc035800c000\n"
".quad 0x50515c234800ffff,0x05249c0340000000,0xfc51dc236000c000,0x400001e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc04ddf440000000,0x34551c4328000000,0x88549c0250004000\n"
".quad 0xfd41dc2313243f6a,0x800081e7198e0000,0x7d21600340000000,0xfd34e0035800c000\n"
".quad 0x0524a0034800ffff,0x154520236000c000,0xfd215c0340000000,0xf934dc03128e0000\n"
".quad 0x50515e034800c001,0x20549c0348000000,0x60515c035800c000,0x49349ee36000c000\n"
".quad 0xfc515c2340000000,0x48515e03108e0000,0x14215c5348000000,0x0c211c0268000000\n"
".quad 0x11211c8430fc8be6,0x11215e0414000000,0x40509e0018000000,0x44509e003004cff2\n"
".quad 0x54515e1030044000,0x04409c0330044000,0xfc21dc236800c000,0x14509c001a8e0000\n"
".quad 0xc000a1e758000000,0x680141e240000000,0x642140001aead818,0x74514000300a4000\n"
".quad 0x8451400030048000,0x9450800030048000,0xc00081e730048000,0x7804a1e240000000\n"
".quad 0xa424a00018f0220e,0xb524a00030244000,0x4820a00030048000,0x1420a00058000000\n"
".quad 0x00001de4300a0000,0x08411c0340000000,0x09215d046800c000,0x08509c3310000000\n"
".quad 0x04619c0332880000,0x31115c864800c000,0x18c1dc2314000800,0x41111c86198e0000\n"
".quad 0x0c545c0014000800,0x10349c0058000000,0x1020de0058000000,0x04001c0330220000\n"
".quad 0x08509c004800c000,0x0cf3dc0030240000,0x09041c0050000000,0xc00001e750000000\n"
".quad 0x8001dc2340000000,0xa00001e7188e4000,0x60001de74003ffde,0xfc019de440000000\n"
".quad 0x20001de728000000,0xfc019de440000000,0x90135c0328000000,0x20139c034800c000\n"
".quad 0x60001de74800c000,0x20139c0340000000,0x90135c034800c000,0xfc019de44800c000\n"
".quad 0xfc61dc2328000000,0xc00001e71a0ec007,0x8001dc2340000081,0x800001e71b0e4000\n"
".quad 0x50631c0340000081,0xec015de25000c000,0x10c09c8619006487,0x20209c0014000800\n"
".quad 0x00c0dc8658000000,0x20c11c8614000800,0x24309c0014000800,0xa000000730040000\n"
".quad 0x1c409c006000000f,0x60011de230040000,0x09309c04195110b4,0x10209c0110000000\n"
".quad 0x09a11c4450000000,0x0041dc0010000000,0x09a09c04210edfe0,0x200021e710000000\n"
".quad 0x08245d1040000000,0x1443dc0050000000,0xc0000007220e4000,0xe00025e76000000b\n"
".quad 0x0420dc034000000a,0x20251c036000c000,0x6034dc036000c000,0x90145c035800c000\n"
".quad 0x0020dc024800c000,0x00049de23a000000,0xfc015de4180000a0,0x01451c4228000000\n"
".quad 0x0134dc033a000000,0x01255c864800fffe,0x51559c0314000800,0x11249c0350000000\n"
".quad 0x15615c034800c000,0x6123dc0348000000,0x15659c031a8ec0a0,0x01115c85120e0000\n"
".quad 0x51515d43c8000000,0x11145c03202c0000,0xc00005e74800c000,0x15345c034003fffe\n"
".quad 0xf0115c855800c000,0x7d34dc03c8000000,0x35151c436800c000,0xfd33dc0341000000\n"
".quad 0x61445c85190e0000,0x51449c85c0000000,0x200085e7c0000000,0x8135660340000001\n"
".quad 0x414164854800c000,0x4d15a403c0000000,0x4d24e40360000000,0x5524640360000000\n"
".quad 0x5914640358000000,0x5451640348000000,0x4c54a40358000000,0x00001de448000000\n"
".quad 0x09215c0340000000,0x400000076000c000,0x79249c0360000001,0xfc53dc035800c000\n"
".quad 0x79151c03190e0000,0x4914dc435800c000,0x600005e740000000,0x05345c0340000000\n"
".quad 0x2513dc034800c000,0x07f45c141a0e4000,0x2533dc032012c000,0x07f45c141a0e4000\n"
".quad 0x45445c032012c000,0x45249f8448000000,0x45245c031c000000,0xa000a5e732860000\n"
".quad 0x1521478440000000,0x4ff4c5c31c000000,0xfc54840368000000,0x0030c482110e0000\n"
".quad 0x4d24c6033a000000,0xfd33dc2348000000,0x60000007198e0000,0x200005e760000001\n"
".quad 0xfc049de440000001,0x00001de428000000,0x7c551c0340000000,0xfd249c035800c000\n"
".quad 0x5134dc234800ffff,0x04515c0340000000,0xfd33dc236000c000,0x400005e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc049df440000000,0x35351c4328000000,0xfd43dc2350004000\n"
".quad 0x8934dc02198e0000,0x800085e713243f6a,0x7d31640340000000,0xfd24a4035800c000\n"
".quad 0x0534e4034800ffff,0x154524236000c000,0xfd315c0340000000,0xf9249c03128e0000\n"
".quad 0x50515e034800c001,0x2054dc0348000000,0x60515c035800c000,0x4d249ee36000c000\n"
".quad 0xfc515c2340000000,0x48515e03108e0000,0x14349c5348000000,0x0c20dc0268000000\n"
".quad 0x0d245c8430fc8be6,0x4520de0414000000,0x40315e0018000000,0x44315e003004cff2\n"
".quad 0x54349e10300a4000,0x0510dc03300a4000,0x04315c034800c000,0xfc53dc236800c000\n"
".quad 0x49215c001a8e0000,0xc000a5e758000000,0x680445e240000000,0x645444001aead818\n"
".quad 0x7514440030224000,0x85144400300a8000,0x95114400300a8000,0xc00085e7300a8000\n"
".quad 0x780465e240000000,0xa454640018f0220e,0xb514640030224000,0x44516400300a8000\n"
".quad 0x4851640058000000,0x00001de430240000,0x0830dc0340000000,0x15245d046800c000\n"
".quad 0x15145c3310000000,0xfc21dc0032860000,0x8000000721200000,0x200021e76000000e\n"
".quad 0xfc251c1040000000,0x1441dc0058000000,0xc0000007220e4000,0xe00021e76000000b\n"
".quad 0x0420dc034000000a,0x20215c036000c000,0x60349c036000c000,0x00209c025800c000\n"
".quad 0x2010dc033a000000,0x00011de24800c000,0xfc04dde4180000a0,0x00515c4228000000\n"
".quad 0x01249c033a000000,0x00451c864800fffe,0x15455c0314000800,0x10411c0350000000\n"
".quad 0x4d54dc034800c000,0x6041dc0348000000,0x4d555c031a8ec0a0,0x0034dc85120e0000\n"
".quad 0x1544dd43c8000000,0x1030dc03202a0000,0xc00001e74800c000,0x1520dc034003fffe\n"
".quad 0x7d215c035800c000,0xfc51dc036800c000,0x8014dc85190e0000,0x38311c43c8000000\n"
".quad 0x6040dc8541000000,0x50451c85c0000000,0x200081e7c0000000,0x8054a20340000001\n"
".quad 0x404120854800c000,0x1434e003c0000000,0x1541600360000000,0x4940e00360000000\n"
".quad 0x4c30e00358000000,0x4841200348000000,0x1445200358000000,0x00001de448000000\n"
".quad 0x09411c0340000000,0x79415c036000c000,0xfc41dc035800c000,0x00000007190e0000\n"
".quad 0x7834dc0360000001,0x14349c435800c000,0x600001e740000000,0x0520dc0340000000\n"
".quad 0x2431dc034800c000,0x07f0dc141a0e4000,0x2521dc032010c000,0x07f0dc141a0e4000\n"
".quad 0x0d30dc032010c000,0x0d215f8448000000,0x0c50dc031c000000,0xa000a1e732840000\n"
".quad 0x1121038440000000,0x4bf481c31c000000,0xfc41400368000000,0x00208082110e0000\n"
".quad 0x485482033a000000,0xfd21dc2348000000,0x60000007198e0000,0x200001e760000001\n"
".quad 0xfc015de440000001,0x00001de428000000,0x7c44dc0340000000,0xfc515c035800c000\n"
".quad 0x4d249c234800ffff,0x04411c0340000000,0xfd21dc236000c000,0x400001e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc015df440000000,0x3524dc4328000000,0xfd31dc2350004000\n"
".quad 0x89249c02198e0000,0x800081e713243f6a,0x7d21200340000000,0xfc5160035800c000\n"
".quad 0x0524a0034800ffff,0x1134e0236000c000,0xfd211c0340000000,0xf8515c03128e0000\n"
".quad 0x4c411e034800c001,0x20449c0348000000,0x60411c035800c000,0x48515ee36000c000\n"
".quad 0xfc411c2340000000,0x14411e03108e0000,0x10215c5348000000,0x0c20dc0268000000\n"
".quad 0x0d20dc8430fc8be6,0x0d211e0414000000,0x40409e0018000000,0x44409e003004cff2\n"
".quad 0x54415e1030044000,0x04309c0330044000,0x14511c006800c000,0xfc21dc2358000000\n"
".quad 0xc000a1e71a8e0000,0x680081e240000000,0x644080001aead818,0x7420800030044000\n"
".quad 0x8420800030088000,0x9421000030088000,0xa00081e730088000,0x7800a1e240000000\n"
".quad 0xa440a00018f0220e,0xb420a00030044000,0x0840a00030088000,0x1421200058000000\n"
".quad 0x08309c03300a0000,0x1120dd046800c000,0x10351c3310000000,0xec015de232840000\n"
".quad 0x60c09c8619006487,0x50c0dc8614000800,0x20209c0014000800,0x70c11c8658000000\n"
".quad 0x24309c0014000800,0x30c4dc8630040000,0x1c409c0014000800,0x40c49c8630040000\n"
".quad 0x60011de214000800,0x09309c04195110b4,0x10209c0110000000,0x0000000750000000\n"
".quad 0x45315c0060000010,0x09a11c4458000000,0x49145c0010000000,0x49415e0058000000\n"
".quad 0x0041dc00300a0000,0x51349c00210edfe0,0x14f45c0030220000,0x09a09c0450000000\n"
".quad 0x4903dc0010000000,0x200021e750000000,0x08241d1040000000,0x1443dc0050000000\n"
".quad 0xe0000007220e4000,0x000025e76000000b,0x0420dc034000000b,0x20251c036000c000\n"
".quad 0x6034dc036000c000,0x90141c035800c000,0x0020dc024800c000,0x00049de23a000000\n"
".quad 0xfc015de4180000a0,0x01451c4228000000,0x0134dc033a000000,0x01255c864800fffe\n"
".quad 0x51559c0314000800,0x11249c0350000000,0x15615c034800c000,0x6123dc0348000000\n"
".quad 0x15659c031a8ec0a0,0x01015c85120e0000,0x51515d43c8000000,0x11041c03202c0000\n"
".quad 0xc00005e74800c000,0x15341c034003fffe,0xf0115c855800c000,0x7d34dc03c8000000\n"
".quad 0x35051c436800c000,0xfd33dc0341000000,0x61441c85190e0000,0x51449c85c0000000\n"
".quad 0x200085e7c0000000,0x8135660340000001,0x414164854800c000,0x4d05a403c0000000\n"
".quad 0x4d24e40360000000,0x5524240360000000,0x5904240358000000,0x5451640348000000\n"
".quad 0x4c54a40358000000,0x00001de448000000,0x09215c0340000000,0x400000076000c000\n"
".quad 0x79249c0360000001,0xfc53dc035800c000,0x79051c03190e0000,0x4904dc435800c000\n"
".quad 0x600005e740000000,0x05341c0340000000,0x2503dc034800c000,0x07f41c141a0e4000\n"
".quad 0x2533dc032012c000,0x07f41c141a0e4000,0x41441c032012c000,0x41249f8448000000\n"
".quad 0x41241c031c000000,0xc000a5e732860000,0x1521478440000000,0x4ff4c5c31c000000\n"
".quad 0xfc54840368000000,0x0030c482110e0000,0x4d24c6033a000000,0x00001de448000000\n"
".quad 0xfd33dc2340000000,0x60000007198e0000,0x200005e760000001,0xfc049de440000001\n"
".quad 0x00001de428000000,0x7c551c0340000000,0x5134dc235800c000,0xfd249c0340000000\n"
".quad 0xfd33dc234800ffff,0x04515c031a0e0000,0x400005e76000c000,0x00001df44003ffff\n"
".quad 0xfc049df440000000,0x35351c4328000000,0xfd43dc2350004000,0x8934dc02198e0000\n"
".quad 0x800085e713243f6a,0x7d31640340000000,0xfd24a4035800c000,0x0534e4034800ffff\n"
".quad 0x154524236000c000,0xfd315c0340000000,0x50515e03128e0000,0xf9249c0348000000\n"
".quad 0x2054dc034800c001,0x60515c035800c000,0x4d249ee36000c000,0xfc515c2340000000\n"
".quad 0x48515e03108e0000,0x14349c5348000000,0x0c20dc0268000000,0x0d241c8430fc8be6\n"
".quad 0x4120de0414000000,0x40315e0018000000,0x44315e003004cff2,0x54349e10300a4000\n"
".quad 0x0500dc03300a4000,0x04315c034800c000,0xfc53dc236800c000,0x49215c001a8e0000\n"
".quad 0xc000a5e758000000,0x680405e240000000,0x645404001aead818,0x7504040030204000\n"
".quad 0x85040400300a8000,0x95014400300a8000,0xc00085e7300a8000,0x780425e240000000\n"
".quad 0xa454240018f0220e,0xb504240030204000,0x40516400300a8000,0x4851640058000000\n"
".quad 0x00001de430240000,0x0830dc0340000000,0x15241d046800c000,0x15041c3310000000\n"
".quad 0xfc21dc0032860000,0x8000000721200000,0x200021e76000000e,0xfc251c1040000000\n"
".quad 0x1441dc0058000000,0xc0000007220e4000,0xe00021e76000000b,0x0420dc034000000a\n"
".quad 0x20215c036000c000,0x60349c036000c000,0x00209c025800c000,0x2010dc033a000000\n"
".quad 0x00011de24800c000,0xfc04dde4180000a0,0x00515c4228000000,0x01249c033a000000\n"
".quad 0x00451c864800fffe,0x15455c0314000800,0x10411c0350000000,0x4d54dc034800c000\n"
".quad 0x6041dc0348000000,0x0034dc851a8ec0a0,0x4d555c03c8000000,0x1030dc03120e0000\n"
".quad 0x1544dd434800c000,0xc00001e7202a0000,0x1520dc034003fffe,0x7d215c035800c000\n"
".quad 0xfc51dc036800c000,0x8014dc85190e0000,0x38311c43c8000000,0x6040dc8541000000\n"
".quad 0x50451c85c0000000,0x200081e7c0000000,0x8054a20340000001,0x404120854800c000\n"
".quad 0x1434e003c0000000,0x1541600360000000,0x4940e00360000000,0x4c30e00358000000\n"
".quad 0x4841200348000000,0x1445200358000000,0x00001de448000000,0x09411c0340000000\n"
".quad 0x79415c036000c000,0xfc41dc035800c000,0x7834dc03190e0000,0xe00000075800c000\n"
".quad 0x14349c4360000000,0x600001e740000000,0x0520dc0340000000,0x2431dc034800c000\n"
".quad 0x07f0dc141a0e4000,0x2521dc032010c000,0x07f0dc141a0e4000,0x0d30dc032010c000\n"
".quad 0x0d215f8448000000,0x0c50dc031c000000,0xa000a1e732840000,0x1121038440000000\n"
".quad 0x4bf481c31c000000,0xfc41400368000000,0x00208082110e0000,0x485482033a000000\n"
".quad 0xfd21dc2348000000,0x60000007198e0000,0x200001e760000001,0xfc015de440000001\n"
".quad 0x00001de428000000,0x7c44dc0340000000,0x4d249c235800c000,0xfc515c0340000000\n"
".quad 0xfd21dc234800ffff,0x04411c031a0e0000,0x400001e76000c000,0x00001df44003ffff\n"
".quad 0xfc015df440000000,0x3524dc4328000000,0xfd31dc2350004000,0x89249c02198e0000\n"
".quad 0x800081e713243f6a,0x7d21200340000000,0xfc5160035800c000,0x0524a0034800ffff\n"
".quad 0x1134e0236000c000,0xfd211c0340000000,0x4c411e03128e0000,0xf8515c0348000000\n"
".quad 0x20449c034800c001,0x60411c035800c000,0x48515ee36000c000,0xfc411c2340000000\n"
".quad 0x14411e03108e0000,0x10215c5348000000,0x0c20dc0268000000,0x0d20dc8430fc8be6\n"
".quad 0x0d211e0414000000,0x40409e0018000000,0x44409e003004cff2,0x54415e1030044000\n"
".quad 0x04309c0330044000,0x14511c006800c000,0xfc21dc2358000000,0xc000a1e71a8e0000\n"
".quad 0x680081e240000000,0x644080001aead818,0x7420800030044000,0x8420800030088000\n"
".quad 0x9421000030088000,0xa00081e730088000,0x7800a1e240000000,0xa440a00018f0220e\n"
".quad 0xb420a00030044000,0x0840a00030088000,0x1421200058000000,0x08309c03300a0000\n"
".quad 0x1120dd046800c000,0x10351c3310000000,0xec015de232840000,0xb0c09c8619006487\n"
".quad 0x20209c0014000800,0xa0c0dc8658000000,0x24309c0014000800,0xc0c11c8630040000\n"
".quad 0x1c409c0014000800,0x80c4dc8630040000,0x60011de214000800,0x09309c04195110b4\n"
".quad 0x10209c0110000000,0x90c49c8650000000,0x41315c0014000800,0x8000000758000000\n"
".quad 0x49041c006000000f,0x09a11c4458000000,0x49415e0010000000,0x0041dc00300a0000\n"
".quad 0x51349c00210edfe0,0x09a09c0430200000,0x15141c0010000000,0x48f3dc0050000000\n"
".quad 0x200021e750000000,0x08245d1040000000,0x1443dc0050000000,0xa0000007220e4000\n"
".quad 0xc00025e76000000b,0x0420dc034000000a,0x20251c036000c000,0x6034dc036000c000\n"
".quad 0x90145c035800c000,0x0020dc024800c000,0x00049de23a000000,0xfc015de4180000a0\n"
".quad 0x01451c4228000000,0x0134dc033a000000,0x01255c864800fffe,0x51559c0314000800\n"
".quad 0x11249c0350000000,0x15615c034800c000,0x6123dc0348000000,0x01115c851a8ec0a0\n"
".quad 0x15659c03c8000000,0x11145c03120e0000,0x51515d434800c000,0xc00005e7202c0000\n"
".quad 0x15345c034003fffe,0xf0115c855800c000,0x7d34dc03c8000000,0x35151c436800c000\n"
".quad 0xfd33dc0341000000,0x61445c85190e0000,0x51449c85c0000000,0x200085e7c0000000\n"
".quad 0x8135660340000001,0x414164854800c000,0x4d15a403c0000000,0x4d24e40360000000\n"
".quad 0x5524640360000000,0x5914640358000000,0x5451640348000000,0x4c54a40358000000\n"
".quad 0x00001de448000000,0x09215c0340000000,0x79249c036000c000,0xfc53dc035800c000\n"
".quad 0x79151c03190e0000,0xe00000075800c000,0x4914dc4360000000,0x600005e740000000\n"
".quad 0x05345c0340000000,0x2513dc034800c000,0x07f45c141a0e4000,0x2533dc032012c000\n"
".quad 0x07f45c141a0e4000,0x45445c032012c000,0x45249f8448000000,0x45245c031c000000\n"
".quad 0xa000a5e732860000,0x1521478440000000,0x4ff4c5c31c000000,0xfc54840368000000\n"
".quad 0x0030c482110e0000,0x4d24c6033a000000,0xfd33dc2348000000,0x40000007198e0000\n"
".quad 0x000005e760000001,0xfc049de440000001,0x7c551c0328000000,0xfd249c035800c000\n"
".quad 0x5134dc234800ffff,0x04515c0340000000,0xfd33dc236000c000,0x400005e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc049df440000000,0x35351c4328000000,0xfd43dc2350004000\n"
".quad 0x8934dc02198e0000,0x800085e713243f6a,0x7d31640340000000,0xfd24a4035800c000\n"
".quad 0x0534e4034800ffff,0x154524236000c000,0xfd315c0340000000,0xf9249c03128e0000\n"
".quad 0x50515e034800c001,0x2054dc0348000000,0x60515c035800c000,0x4d249ee36000c000\n"
".quad 0xfc515c2340000000,0x48515e03108e0000,0x14349c5348000000,0x0c20dc0268000000\n"
".quad 0x0d245c8430fc8be6,0x4520de0414000000,0x40315e0018000000,0x44315e003004cff2\n"
".quad 0x54349e10300a4000,0x0510dc03300a4000,0x04315c034800c000,0xfc53dc236800c000\n"
".quad 0x49215c001a8e0000,0xc000a5e758000000,0x680445e240000000,0x645444001aead818\n"
".quad 0x7514440030224000,0x85144400300a8000,0x95114400300a8000,0xa00085e7300a8000\n"
".quad 0x780465e240000000,0xa454640018f0220e,0xb514640030224000,0x44516400300a8000\n"
".quad 0x4851640058000000,0x0830dc0330240000,0x15245d046800c000,0x15145c3310000000\n"
".quad 0xfc21dc0032860000,0x8000000721200000,0x200021e76000000e,0xfc251c1040000000\n"
".quad 0x1441dc0058000000,0xc0000007220e4000,0xe00021e76000000b,0x0420dc034000000a\n"
".quad 0x20215c036000c000,0x60349c036000c000,0x00209c025800c000,0x2010dc033a000000\n"
".quad 0x00011de24800c000,0xfc04dde4180000a0,0x00515c4228000000,0x01249c033a000000\n"
".quad 0x00451c864800fffe,0x15455c0314000800,0x10411c0350000000,0x4d54dc034800c000\n"
".quad 0x6041dc0348000000,0x0034dc851a8ec0a0,0x4d555c03c8000000,0x1030dc03120e0000\n"
".quad 0x1544dd434800c000,0xc00001e7202a0000,0x1520dc034003fffe,0x7d215c035800c000\n"
".quad 0xfc51dc036800c000,0x8014dc85190e0000,0x38311c43c8000000,0x6040dc8541000000\n"
".quad 0x50451c85c0000000,0x200081e7c0000000,0x8054a20340000001,0x404120854800c000\n"
".quad 0x1434e003c0000000,0x1541600360000000,0x4940e00360000000,0x4c30e00358000000\n"
".quad 0x4841200348000000,0x1445200358000000,0x00001de448000000,0x09411c0340000000\n"
".quad 0x79415c036000c000,0xfc41dc035800c000,0x7834dc03190e0000,0xe00000075800c000\n"
".quad 0x14349c4360000000,0x600001e740000000,0x0520dc0340000000,0x2431dc034800c000\n"
".quad 0x07f0dc141a0e4000,0x2521dc032010c000,0x07f0dc141a0e4000,0x0d30dc032010c000\n"
".quad 0x0d215f8448000000,0x0c50dc031c000000,0xa000a1e732840000,0x1121038440000000\n"
".quad 0x4bf481c31c000000,0xfc41400368000000,0x00208082110e0000,0x485482033a000000\n"
".quad 0xfd21dc2348000000,0x60000007198e0000,0x200001e760000001,0xfc015de440000001\n"
".quad 0x00001de428000000,0x7c44dc0340000000,0x4d249c235800c000,0xfc515c0340000000\n"
".quad 0xfd21dc234800ffff,0x04411c031a0e0000,0x400001e76000c000,0x00001df44003ffff\n"
".quad 0xfc015df440000000,0x3524dc4328000000,0xfd31dc2350004000,0x89249c02198e0000\n"
".quad 0x800081e713243f6a,0x7d21200340000000,0xfc5160035800c000,0x0524a0034800ffff\n"
".quad 0x1134e0236000c000,0xfd211c0340000000,0x4c411e03128e0000,0xf8515c0348000000\n"
".quad 0x20449c034800c001,0x60411c035800c000,0x48515ee36000c000,0xfc411c2340000000\n"
".quad 0x14411e03108e0000,0x10215c5348000000,0x0c20dc0268000000,0x0d20dc8430fc8be6\n"
".quad 0x0d211e0414000000,0x40409e0018000000,0x44409e003004cff2,0x54415e1030044000\n"
".quad 0x04309c0330044000,0x14511c006800c000,0xfc21dc2358000000,0xc000a1e71a8e0000\n"
".quad 0x680081e240000000,0x644080001aead818,0x7420800030044000,0x8420800030088000\n"
".quad 0x9421000030088000,0xa00081e730088000,0x7800a1e240000000,0xa440a00018f0220e\n"
".quad 0xb420a00030044000,0x0840a00030088000,0x1421200058000000,0x08309c03300a0000\n"
".quad 0x1120dd046800c000,0x10351c3310000000,0xec015de232840000,0x00c09c8619006487\n"
".quad 0x20209c0014000801,0xf0c0dc8658000000,0x24309c0014000800,0x10c11c8630040000\n"
".quad 0x1c409c0014000801,0xd0c4dc8630040000,0x60011de214000800,0x09309c04195110b4\n"
".quad 0x10209c0110000000,0xe0c49c8650000000,0x45315c0014000800,0x8000000758000000\n"
".quad 0x49145c006000000f,0x09a11c4458000000,0x49415e0010000000,0x51345c00300a0000\n"
".quad 0x0041dc0030220000,0x09a09c04210edfe0,0x15041c0010000000,0x44f15c0050000000\n"
".quad 0x200021e750000000,0x0820dd1040000000,0x1443dc0050000000,0xa0000007220e4000\n"
".quad 0xc00025e76000000b,0x0420dc034000000a,0x20251c036000c000,0x6034dc036000c000\n"
".quad 0x90145c035800c000,0x0020dc024800c000,0x00049de23a000000,0xfc03dde4180000a0\n"
".quad 0x01451c4228000000,0x0134dc033a000000,0x01255c864800fffe,0x51559c0314000800\n"
".quad 0x11249c0350000000,0x3d63dc034800c000,0x6123dc0348000000,0x0113dc851a8ec0a0\n"
".quad 0x3d659c03c8000000,0x11145c03120e0000,0x5153dd434800c000,0xc00005e7202c0000\n"
".quad 0x15345c034003fffe,0xf013dc855800c000,0x7d34dc03c8000000,0x35151c436800c000\n"
".quad 0xfd33dc0341000000,0x61445c85190e0000,0x51449c85c0000000,0x200085e7c0000000\n"
".quad 0x8135660340000001,0x4143e4854800c000,0x4d15a403c0000000,0x4d24e40360000000\n"
".quad 0x5524640360000000,0x5914640358000000,0x54f3e40348000000,0x4cf4a40358000000\n"
".quad 0x00001de448000000,0x0923dc0340000000,0x79249c036000c000,0xfcf3dc035800c000\n"
".quad 0x79151c03190e0000,0xe00000075800c000,0x4914dc4360000000,0x600005e740000000\n"
".quad 0x05345c0340000000,0x2513dc034800c000,0x07f45c141a0e4000,0x2533dc032012c000\n"
".quad 0x07f45c141a0e4000,0x45445c032012c000,0x45249f8448000000,0x45245c031c000000\n"
".quad 0xa000a5e732860000,0x3d23c78440000000,0x4ff4c5c31c000000,0xfcf4840368000000\n"
".quad 0x0030c482110e0000,0x4d24c6033a000000,0xfd33dc2348000000,0x40000007198e0000\n"
".quad 0x000005e760000001,0xfc049de440000001,0x7cf51c0328000000,0xfd249c035800c000\n"
".quad 0x5134dc234800ffff,0x04f3dc0340000000,0xfd33dc236000c000,0x400005e71a0e0000\n"
".quad 0x00001df44003ffff,0xfc049df440000000,0x35351c4328000000,0xfd43dc2350004000\n"
".quad 0x8934dc02198e0000,0x800085e713243f6a,0x7d33e40340000000,0xfd24a4035800c000\n"
".quad 0x0534e4034800ffff,0x3d4524236000c000,0xfd33dc0340000000,0xf9249c03128e0000\n"
".quad 0x50f3de034800c001,0x20f4dc0348000000,0x60f3dc035800c000,0x4d249ee36000c000\n"
".quad 0xfcf3dc2340000000,0x48f3de03108e0000,0x3c349c5348000000,0x0c20dc0268000000\n"
".quad 0x0d245c8430fc8be6,0x4520de0414000000,0x4033de0018000000,0x4433de003004cff2\n"
".quad 0x54349e10301e4000,0x0510dc03301e4000,0x0433dc034800c000,0xfcf3dc236800c000\n"
".quad 0x4923dc001a8e0000,0xc000a5e758000000,0x680445e240000000,0x64f444001aead818\n"
".quad 0x7514440030224000,0x85144400301e8000,0x9513c400301e8000,0xa00085e7301e8000\n"
".quad 0x780465e240000000,0xa4f4640018f0220e,0xb514640030224000,0x44f3e400301e8000\n"
".quad 0x48f3e40058000000,0x0830dc0330240000,0x3d245d046800c000,0x3d10dc3310000000\n"
".quad 0xfc21dc0032860000,0x8000000721200000,0x200021e76000000e,0xfc23dc1040000000\n"
".quad 0x1441dc0058000000,0xc0000007220e4000,0xe00021e76000000b,0x04211c034000000a\n"
".quad 0x20245c036000c000,0x60449c036000c000,0x00209c025800c000,0x20111c033a000000\n"
".quad 0x0003dde24800c000,0xfc04dde4180000a0,0x01145c4228000000,0x01249c033a000000\n"
".quad 0x00f51c864800fffe,0x45455c0314000800,0x10f3dc0350000000,0x4d54dc034800c000\n"
".quad 0x60f1dc0348000000,0x0044dc851a8ec0a0,0x4d555c03c8000000,0x10411c03120e0000\n"
".quad 0x4544dd434800c000,0xc00001e7202a0000,0x15211c034003fffe,0x7d245c035800c000\n"
".quad 0xfd11dc036800c000,0x8014dc85190e0000,0x3843dc43c8000000,0x60f11c8541000000\n"
".quad 0x50f51c85c0000000,0x200081e7c0000000,0x8114a20340000001,0x40f3e0854800c000\n"
".quad 0x4444e003c0000000,0x4544600360000000,0x4941200360000000,0x4c41200358000000\n"
".quad 0x48f3e00348000000,0x44f5200358000000,0x00001de448000000,0x0943dc0340000000\n"
".quad 0x79445c036000c000,0xfcf1dc035800c000,0x7844dc03190e0000,0xe00000075800c000\n"
".quad 0x44449c4360000000,0x600001e740000000,0x05211c0340000000,0x2441dc034800c000\n"
".quad 0x07f11c141a0e4000,0x2521dc032010c000,0x07f11c141a0e4000,0x11311c032010c000\n"
".quad 0x11245f8448000000,0x11111c031c000000,0xa000a1e732840000,0x3d23c38440000000\n"
".quad 0x4bf481c31c000000,0xfcf4400368000000,0x00208082110e0000,0x491482033a000000\n"
".quad 0xfd21dc2348000000,0x60000007198e0000,0x200001e760000001,0xfc045de440000001\n"
".quad 0x00001de428000000,0x7cf4dc0340000000,0x4d249c235800c000,0xfd145c0340000000\n"
".quad 0xfd21dc234800ffff,0x04f3dc031a0e0000,0x400001e76000c000,0x00001df44003ffff\n"
".quad 0xfc045df440000000,0x3524dc4328000000,0xfd31dc2350004000,0x89249c02198e0000\n"
".quad 0x800081e713243f6a,0x7d23e00340000000,0xfd1460035800c000,0x0524a0034800ffff\n"
".quad 0x3d34e0236000c000,0xfd23dc0340000000,0x4cf3de03128e0000,0xf9145c0348000000\n"
".quad 0x20f49c034800c001,0x60f3dc035800c000,0x49145ee36000c000,0xfcf3dc2340000000\n"
".quad 0x44f3de03108e0000,0x3c245c5348000000,0x0c211c0268000000,0x11211c8430fc8be6\n"
".quad 0x1123de0414000000,0x40f09e0018000000,0x44f09e003004cff2,0x54f45e1030044000\n"
".quad 0x04409c0330044000,0x4513dc006800c000,0xfc21dc2358000000,0xc000a1e71a8e0000\n"
".quad 0x680081e240000000,0x64f080001aead818,0x7420800030044000,0x84208000301e8000\n"
".quad 0x9423c000301e8000,0xa00081e7301e8000,0x7800a1e240000000,0xa4f0a00018f0220e\n"
".quad 0xb420a00030044000,0x08f0a000301e8000,0x4423e00058000000,0x08409c0330220000\n"
".quad 0x3d211d046800c000,0x3c43dc3310000000,0x10619c0332840000,0x20c11c864800c000\n"
".quad 0xfc61dc2314000801,0x30c09c861a0ec007,0x0c431c0014000801,0x10001c0358000000\n"
".quad 0x0830dc004800c000,0x08f09e0058000000,0x3c40dc0030180000,0x0903dc0030060000\n"
".quad 0x0c541c0050000000,0x400001e750000000,0x8001dc2340000000,0x800001e7188e4000\n"
".quad 0x00a3dc854003ff7e,0x00b41c8590000000,0x00001de790000000,0x0000000080000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x473ba70000000001\n"
".quad 0xc90fdaa280000000,0x2e85a30939fdaa20,0x3d2aaaa537ccf5ce,0x3f800000bf000000\n"
".quad 0xbe2aaaa3b94ca1f9,0x00000000001c0c04,0x0000000800000004,0x000000100000000c\n"
".quad 0x0000001800000014,0x0000000d00080a04,0x001c1903001c0020,0xffffffff000c1704\n"
".quad 0x0011f00000180006,0xffffffff000c1704,0x0011f00000140005,0xffffffff000c1704\n"
".quad 0x0011f00000100004,0xffffffff000c1704,0x0011f000000c0003,0xffffffff000c1704\n"
".quad 0x0011f00000080002,0xffffffff000c1704,0x0011f00000040001,0xffffffff000c1704\n"
".quad 0x0011f00000000000,0x002301a400080d04,0x0000000000000020,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x3c43904100000000,0xf534ddc0db629599\n"
".quad 0x4e441529fc2757d1,0x00081204a2f9836e,0x0000000000000011,0x0000001100081104\n"
".quad 0x0008120400000000,0x0000004000000010,0x0000001000081104,0x0000000600000040\n"
".quad 0x0000000000005adc,0x000000a000000000,0x00000005000000a0,0x6000000000000004\n"
".quad 0x0000000000000594,0x000001a000000000,0x00001105000001a0,0x6000000000000004\n"
".quad 0x0000000000000734,0x00002b6000000000,0x0000100500002b60,0x6000000000000004\n"
".quad 0x0000000000003294,0x0000000000000000,0x0000100600000004,0x0000000100000004\n"
".quad 0x0000000000003294,0x0000281800000000,0x0000000500002818,0x0000000000000004\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[2928];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"77563a1f98a163cf",(char*)"/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x8f0c31bb,&__elfEntries1};
# 3 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c" 2
struct __T20 {int __par0;float *__par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;int __dummy_field;};
struct __T21 {int __par0;int __par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;int __dummy_field;};
extern void __device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_(int, float *, float *, float *, float *, float *, float *);
extern void __device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_(int, int, float *, float *, float *, float *, float *);
static void __sti____cudaRegisterAll_44_tmpxft_000015aa_00000000_4_computeFH_cpp1_ii_d1c9fc4c(void) __attribute__((__constructor__));
void __device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_(int __par0, float *__par1, float *__par2, float *__par3, float *__par4, float *__par5, float *__par6){ struct __T20 *__T22 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T22->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T22->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T22->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T22->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T22->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T22->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T22->__par6) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(int, float *, float *, float *, float *, float *, float *))ComputeRhoPhiGPU)); (void)cudaLaunch(((char *)((void ( *)(int, float *, float *, float *, float *, float *, float *))ComputeRhoPhiGPU))); };}
void ComputeRhoPhiGPU( int __cuda_0,float *__cuda_1,float *__cuda_2,float *__cuda_3,float *__cuda_4,float *__cuda_5,float *__cuda_6)
# 54 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{__device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 64 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c"
void __device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_( int __par0, int __par1, float *__par2, float *__par3, float *__par4, float *__par5, float *__par6) { struct __T21 *__T23 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T23->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T23->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T23->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T23->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T23->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T23->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T23->__par6) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(int, int, float *, float *, float *, float *, float *))ComputeFH_GPU)); (void)cudaLaunch(((char *)((void ( *)(int, int, float *, float *, float *, float *, float *))ComputeFH_GPU))); }; }
void ComputeFH_GPU( int __cuda_0,int __cuda_1,float *__cuda_2,float *__cuda_3,float *__cuda_4,float *__cuda_5,float *__cuda_6)
# 70 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
{__device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 140 "/home/normal/checkout/gpuocelot/tests/parboil/tests/mri-fhd/computeFH.cu"
}
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c"
static void __sti____cudaRegisterAll_44_tmpxft_000015aa_00000000_4_computeFH_cpp1_ii_d1c9fc4c(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(int, int, float *, float *, float *, float *, float *))ComputeFH_GPU), (char*)"_Z13ComputeFH_GPUiiPfS_S_S_S_", "_Z13ComputeFH_GPUiiPfS_S_S_S_", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(int, float *, float *, float *, float *, float *, float *))ComputeRhoPhiGPU), (char*)"_Z16ComputeRhoPhiGPUiPfS_S_S_S_S_", "_Z16ComputeRhoPhiGPUiPfS_S_S_S_S_", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&c, (char*)"c", "c", 0, 10240, 1, 0); }
# 1 "/tmp/tmpxft_000015aa_00000000-1_computeFH.cudafe1.stub.c" 2

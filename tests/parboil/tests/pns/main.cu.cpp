# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
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
# 268 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 275 "/usr/include/unistd.h" 3
extern "C" { typedef __socklen_t socklen_t; }
# 288 "/usr/include/unistd.h" 3
extern "C" int access(const char *, int) throw() __attribute__((nonnull(1)));
# 293 "/usr/include/unistd.h" 3
extern "C" int euidaccess(const char *, int) throw() __attribute__((nonnull(1)));
# 297 "/usr/include/unistd.h" 3
extern "C" int eaccess(const char *, int) throw() __attribute__((nonnull(1)));
# 305 "/usr/include/unistd.h" 3
extern "C" int faccessat(int, const char *, int, int) throw() __attribute__((nonnull(2)));
# 331 "/usr/include/unistd.h" 3
extern "C" __off_t lseek(int, __off_t, int) throw();
# 342 "/usr/include/unistd.h" 3
extern "C" __off64_t lseek64(int, __off64_t, int) throw();
# 350 "/usr/include/unistd.h" 3
extern "C" int close(int);
# 357 "/usr/include/unistd.h" 3
extern "C" ssize_t read(int, void *, size_t);
# 363 "/usr/include/unistd.h" 3
extern "C" ssize_t write(int, const void *, size_t);
# 373 "/usr/include/unistd.h" 3
extern "C" ssize_t pread(int, void *, size_t, __off_t);
# 381 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite(int, const void *, size_t, __off_t);
# 401 "/usr/include/unistd.h" 3
extern "C" ssize_t pread64(int, void *, size_t, __off64_t);
# 405 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite64(int, const void *, size_t, __off64_t);
# 414 "/usr/include/unistd.h" 3
extern "C" int pipe(int [2]) throw();
# 419 "/usr/include/unistd.h" 3
extern "C" int pipe2(int [2], int) throw();
# 429 "/usr/include/unistd.h" 3
extern "C" unsigned alarm(unsigned) throw();
# 441 "/usr/include/unistd.h" 3
extern "C" unsigned sleep(unsigned);
# 449 "/usr/include/unistd.h" 3
extern "C" __useconds_t ualarm(__useconds_t, __useconds_t) throw();
# 457 "/usr/include/unistd.h" 3
extern "C" int usleep(__useconds_t);
# 466 "/usr/include/unistd.h" 3
extern "C" int pause();
# 470 "/usr/include/unistd.h" 3
extern "C" int chown(const char *, __uid_t, __gid_t) throw() __attribute__((nonnull(1)));
# 475 "/usr/include/unistd.h" 3
extern "C" int fchown(int, __uid_t, __gid_t) throw();
# 480 "/usr/include/unistd.h" 3
extern "C" int lchown(const char *, __uid_t, __gid_t) throw() __attribute__((nonnull(1)));
# 488 "/usr/include/unistd.h" 3
extern "C" int fchownat(int, const char *, __uid_t, __gid_t, int) throw() __attribute__((nonnull(2)));
# 494 "/usr/include/unistd.h" 3
extern "C" int chdir(const char *) throw() __attribute__((nonnull(1)));
# 498 "/usr/include/unistd.h" 3
extern "C" int fchdir(int) throw();
# 508 "/usr/include/unistd.h" 3
extern "C" char *getcwd(char *, size_t) throw();
# 514 "/usr/include/unistd.h" 3
extern "C" char *get_current_dir_name() throw();
# 522 "/usr/include/unistd.h" 3
extern "C" char *getwd(char *) throw() __attribute__((__deprecated__)) __attribute__((nonnull(1)));
# 528 "/usr/include/unistd.h" 3
extern "C" int dup(int) throw();
# 531 "/usr/include/unistd.h" 3
extern "C" int dup2(int, int) throw();
# 536 "/usr/include/unistd.h" 3
extern "C" int dup3(int, int, int) throw();
# 540 "/usr/include/unistd.h" 3
extern "C" { extern char **__environ; }
# 542 "/usr/include/unistd.h" 3
extern "C" { extern char **environ; }
# 548 "/usr/include/unistd.h" 3
extern "C" int execve(const char *, char *const [], char *const []) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 554 "/usr/include/unistd.h" 3
extern "C" int fexecve(int, char *const [], char *const []) throw() __attribute__((nonnull(2)));
# 560 "/usr/include/unistd.h" 3
extern "C" int execv(const char *, char *const []) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 565 "/usr/include/unistd.h" 3
extern "C" int execle(const char *, const char *, ...) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 570 "/usr/include/unistd.h" 3
extern "C" int execl(const char *, const char *, ...) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 575 "/usr/include/unistd.h" 3
extern "C" int execvp(const char *, char *const []) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 581 "/usr/include/unistd.h" 3
extern "C" int execlp(const char *, const char *, ...) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 587 "/usr/include/unistd.h" 3
extern "C" int execvpe(const char *, char *const [], char *const []) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 595 "/usr/include/unistd.h" 3
extern "C" int nice(int) throw();
# 600 "/usr/include/unistd.h" 3
extern "C" void _exit(int) __attribute__((__noreturn__));
# 27 "/usr/include/bits/confname.h" 3
enum {
# 28 "/usr/include/bits/confname.h" 3
_PC_LINK_MAX,
# 30 "/usr/include/bits/confname.h" 3
_PC_MAX_CANON,
# 32 "/usr/include/bits/confname.h" 3
_PC_MAX_INPUT,
# 34 "/usr/include/bits/confname.h" 3
_PC_NAME_MAX,
# 36 "/usr/include/bits/confname.h" 3
_PC_PATH_MAX,
# 38 "/usr/include/bits/confname.h" 3
_PC_PIPE_BUF,
# 40 "/usr/include/bits/confname.h" 3
_PC_CHOWN_RESTRICTED,
# 42 "/usr/include/bits/confname.h" 3
_PC_NO_TRUNC,
# 44 "/usr/include/bits/confname.h" 3
_PC_VDISABLE,
# 46 "/usr/include/bits/confname.h" 3
_PC_SYNC_IO,
# 48 "/usr/include/bits/confname.h" 3
_PC_ASYNC_IO,
# 50 "/usr/include/bits/confname.h" 3
_PC_PRIO_IO,
# 52 "/usr/include/bits/confname.h" 3
_PC_SOCK_MAXBUF,
# 54 "/usr/include/bits/confname.h" 3
_PC_FILESIZEBITS,
# 56 "/usr/include/bits/confname.h" 3
_PC_REC_INCR_XFER_SIZE,
# 58 "/usr/include/bits/confname.h" 3
_PC_REC_MAX_XFER_SIZE,
# 60 "/usr/include/bits/confname.h" 3
_PC_REC_MIN_XFER_SIZE,
# 62 "/usr/include/bits/confname.h" 3
_PC_REC_XFER_ALIGN,
# 64 "/usr/include/bits/confname.h" 3
_PC_ALLOC_SIZE_MIN,
# 66 "/usr/include/bits/confname.h" 3
_PC_SYMLINK_MAX,
# 68 "/usr/include/bits/confname.h" 3
_PC_2_SYMLINKS
# 70 "/usr/include/bits/confname.h" 3
};
# 74 "/usr/include/bits/confname.h" 3
enum {
# 75 "/usr/include/bits/confname.h" 3
_SC_ARG_MAX,
# 77 "/usr/include/bits/confname.h" 3
_SC_CHILD_MAX,
# 79 "/usr/include/bits/confname.h" 3
_SC_CLK_TCK,
# 81 "/usr/include/bits/confname.h" 3
_SC_NGROUPS_MAX,
# 83 "/usr/include/bits/confname.h" 3
_SC_OPEN_MAX,
# 85 "/usr/include/bits/confname.h" 3
_SC_STREAM_MAX,
# 87 "/usr/include/bits/confname.h" 3
_SC_TZNAME_MAX,
# 89 "/usr/include/bits/confname.h" 3
_SC_JOB_CONTROL,
# 91 "/usr/include/bits/confname.h" 3
_SC_SAVED_IDS,
# 93 "/usr/include/bits/confname.h" 3
_SC_REALTIME_SIGNALS,
# 95 "/usr/include/bits/confname.h" 3
_SC_PRIORITY_SCHEDULING,
# 97 "/usr/include/bits/confname.h" 3
_SC_TIMERS,
# 99 "/usr/include/bits/confname.h" 3
_SC_ASYNCHRONOUS_IO,
# 101 "/usr/include/bits/confname.h" 3
_SC_PRIORITIZED_IO,
# 103 "/usr/include/bits/confname.h" 3
_SC_SYNCHRONIZED_IO,
# 105 "/usr/include/bits/confname.h" 3
_SC_FSYNC,
# 107 "/usr/include/bits/confname.h" 3
_SC_MAPPED_FILES,
# 109 "/usr/include/bits/confname.h" 3
_SC_MEMLOCK,
# 111 "/usr/include/bits/confname.h" 3
_SC_MEMLOCK_RANGE,
# 113 "/usr/include/bits/confname.h" 3
_SC_MEMORY_PROTECTION,
# 115 "/usr/include/bits/confname.h" 3
_SC_MESSAGE_PASSING,
# 117 "/usr/include/bits/confname.h" 3
_SC_SEMAPHORES,
# 119 "/usr/include/bits/confname.h" 3
_SC_SHARED_MEMORY_OBJECTS,
# 121 "/usr/include/bits/confname.h" 3
_SC_AIO_LISTIO_MAX,
# 123 "/usr/include/bits/confname.h" 3
_SC_AIO_MAX,
# 125 "/usr/include/bits/confname.h" 3
_SC_AIO_PRIO_DELTA_MAX,
# 127 "/usr/include/bits/confname.h" 3
_SC_DELAYTIMER_MAX,
# 129 "/usr/include/bits/confname.h" 3
_SC_MQ_OPEN_MAX,
# 131 "/usr/include/bits/confname.h" 3
_SC_MQ_PRIO_MAX,
# 133 "/usr/include/bits/confname.h" 3
_SC_VERSION,
# 135 "/usr/include/bits/confname.h" 3
_SC_PAGESIZE,
# 138 "/usr/include/bits/confname.h" 3
_SC_RTSIG_MAX,
# 140 "/usr/include/bits/confname.h" 3
_SC_SEM_NSEMS_MAX,
# 142 "/usr/include/bits/confname.h" 3
_SC_SEM_VALUE_MAX,
# 144 "/usr/include/bits/confname.h" 3
_SC_SIGQUEUE_MAX,
# 146 "/usr/include/bits/confname.h" 3
_SC_TIMER_MAX,
# 151 "/usr/include/bits/confname.h" 3
_SC_BC_BASE_MAX,
# 153 "/usr/include/bits/confname.h" 3
_SC_BC_DIM_MAX,
# 155 "/usr/include/bits/confname.h" 3
_SC_BC_SCALE_MAX,
# 157 "/usr/include/bits/confname.h" 3
_SC_BC_STRING_MAX,
# 159 "/usr/include/bits/confname.h" 3
_SC_COLL_WEIGHTS_MAX,
# 161 "/usr/include/bits/confname.h" 3
_SC_EQUIV_CLASS_MAX,
# 163 "/usr/include/bits/confname.h" 3
_SC_EXPR_NEST_MAX,
# 165 "/usr/include/bits/confname.h" 3
_SC_LINE_MAX,
# 167 "/usr/include/bits/confname.h" 3
_SC_RE_DUP_MAX,
# 169 "/usr/include/bits/confname.h" 3
_SC_CHARCLASS_NAME_MAX,
# 172 "/usr/include/bits/confname.h" 3
_SC_2_VERSION,
# 174 "/usr/include/bits/confname.h" 3
_SC_2_C_BIND,
# 176 "/usr/include/bits/confname.h" 3
_SC_2_C_DEV,
# 178 "/usr/include/bits/confname.h" 3
_SC_2_FORT_DEV,
# 180 "/usr/include/bits/confname.h" 3
_SC_2_FORT_RUN,
# 182 "/usr/include/bits/confname.h" 3
_SC_2_SW_DEV,
# 184 "/usr/include/bits/confname.h" 3
_SC_2_LOCALEDEF,
# 187 "/usr/include/bits/confname.h" 3
_SC_PII,
# 189 "/usr/include/bits/confname.h" 3
_SC_PII_XTI,
# 191 "/usr/include/bits/confname.h" 3
_SC_PII_SOCKET,
# 193 "/usr/include/bits/confname.h" 3
_SC_PII_INTERNET,
# 195 "/usr/include/bits/confname.h" 3
_SC_PII_OSI,
# 197 "/usr/include/bits/confname.h" 3
_SC_POLL,
# 199 "/usr/include/bits/confname.h" 3
_SC_SELECT,
# 201 "/usr/include/bits/confname.h" 3
_SC_UIO_MAXIOV,
# 203 "/usr/include/bits/confname.h" 3
_SC_IOV_MAX = 60,
# 205 "/usr/include/bits/confname.h" 3
_SC_PII_INTERNET_STREAM,
# 207 "/usr/include/bits/confname.h" 3
_SC_PII_INTERNET_DGRAM,
# 209 "/usr/include/bits/confname.h" 3
_SC_PII_OSI_COTS,
# 211 "/usr/include/bits/confname.h" 3
_SC_PII_OSI_CLTS,
# 213 "/usr/include/bits/confname.h" 3
_SC_PII_OSI_M,
# 215 "/usr/include/bits/confname.h" 3
_SC_T_IOV_MAX,
# 219 "/usr/include/bits/confname.h" 3
_SC_THREADS,
# 221 "/usr/include/bits/confname.h" 3
_SC_THREAD_SAFE_FUNCTIONS,
# 223 "/usr/include/bits/confname.h" 3
_SC_GETGR_R_SIZE_MAX,
# 225 "/usr/include/bits/confname.h" 3
_SC_GETPW_R_SIZE_MAX,
# 227 "/usr/include/bits/confname.h" 3
_SC_LOGIN_NAME_MAX,
# 229 "/usr/include/bits/confname.h" 3
_SC_TTY_NAME_MAX,
# 231 "/usr/include/bits/confname.h" 3
_SC_THREAD_DESTRUCTOR_ITERATIONS,
# 233 "/usr/include/bits/confname.h" 3
_SC_THREAD_KEYS_MAX,
# 235 "/usr/include/bits/confname.h" 3
_SC_THREAD_STACK_MIN,
# 237 "/usr/include/bits/confname.h" 3
_SC_THREAD_THREADS_MAX,
# 239 "/usr/include/bits/confname.h" 3
_SC_THREAD_ATTR_STACKADDR,
# 241 "/usr/include/bits/confname.h" 3
_SC_THREAD_ATTR_STACKSIZE,
# 243 "/usr/include/bits/confname.h" 3
_SC_THREAD_PRIORITY_SCHEDULING,
# 245 "/usr/include/bits/confname.h" 3
_SC_THREAD_PRIO_INHERIT,
# 247 "/usr/include/bits/confname.h" 3
_SC_THREAD_PRIO_PROTECT,
# 249 "/usr/include/bits/confname.h" 3
_SC_THREAD_PROCESS_SHARED,
# 252 "/usr/include/bits/confname.h" 3
_SC_NPROCESSORS_CONF,
# 254 "/usr/include/bits/confname.h" 3
_SC_NPROCESSORS_ONLN,
# 256 "/usr/include/bits/confname.h" 3
_SC_PHYS_PAGES,
# 258 "/usr/include/bits/confname.h" 3
_SC_AVPHYS_PAGES,
# 260 "/usr/include/bits/confname.h" 3
_SC_ATEXIT_MAX,
# 262 "/usr/include/bits/confname.h" 3
_SC_PASS_MAX,
# 265 "/usr/include/bits/confname.h" 3
_SC_XOPEN_VERSION,
# 267 "/usr/include/bits/confname.h" 3
_SC_XOPEN_XCU_VERSION,
# 269 "/usr/include/bits/confname.h" 3
_SC_XOPEN_UNIX,
# 271 "/usr/include/bits/confname.h" 3
_SC_XOPEN_CRYPT,
# 273 "/usr/include/bits/confname.h" 3
_SC_XOPEN_ENH_I18N,
# 275 "/usr/include/bits/confname.h" 3
_SC_XOPEN_SHM,
# 278 "/usr/include/bits/confname.h" 3
_SC_2_CHAR_TERM,
# 280 "/usr/include/bits/confname.h" 3
_SC_2_C_VERSION,
# 282 "/usr/include/bits/confname.h" 3
_SC_2_UPE,
# 285 "/usr/include/bits/confname.h" 3
_SC_XOPEN_XPG2,
# 287 "/usr/include/bits/confname.h" 3
_SC_XOPEN_XPG3,
# 289 "/usr/include/bits/confname.h" 3
_SC_XOPEN_XPG4,
# 292 "/usr/include/bits/confname.h" 3
_SC_CHAR_BIT,
# 294 "/usr/include/bits/confname.h" 3
_SC_CHAR_MAX,
# 296 "/usr/include/bits/confname.h" 3
_SC_CHAR_MIN,
# 298 "/usr/include/bits/confname.h" 3
_SC_INT_MAX,
# 300 "/usr/include/bits/confname.h" 3
_SC_INT_MIN,
# 302 "/usr/include/bits/confname.h" 3
_SC_LONG_BIT,
# 304 "/usr/include/bits/confname.h" 3
_SC_WORD_BIT,
# 306 "/usr/include/bits/confname.h" 3
_SC_MB_LEN_MAX,
# 308 "/usr/include/bits/confname.h" 3
_SC_NZERO,
# 310 "/usr/include/bits/confname.h" 3
_SC_SSIZE_MAX,
# 312 "/usr/include/bits/confname.h" 3
_SC_SCHAR_MAX,
# 314 "/usr/include/bits/confname.h" 3
_SC_SCHAR_MIN,
# 316 "/usr/include/bits/confname.h" 3
_SC_SHRT_MAX,
# 318 "/usr/include/bits/confname.h" 3
_SC_SHRT_MIN,
# 320 "/usr/include/bits/confname.h" 3
_SC_UCHAR_MAX,
# 322 "/usr/include/bits/confname.h" 3
_SC_UINT_MAX,
# 324 "/usr/include/bits/confname.h" 3
_SC_ULONG_MAX,
# 326 "/usr/include/bits/confname.h" 3
_SC_USHRT_MAX,
# 329 "/usr/include/bits/confname.h" 3
_SC_NL_ARGMAX,
# 331 "/usr/include/bits/confname.h" 3
_SC_NL_LANGMAX,
# 333 "/usr/include/bits/confname.h" 3
_SC_NL_MSGMAX,
# 335 "/usr/include/bits/confname.h" 3
_SC_NL_NMAX,
# 337 "/usr/include/bits/confname.h" 3
_SC_NL_SETMAX,
# 339 "/usr/include/bits/confname.h" 3
_SC_NL_TEXTMAX,
# 342 "/usr/include/bits/confname.h" 3
_SC_XBS5_ILP32_OFF32,
# 344 "/usr/include/bits/confname.h" 3
_SC_XBS5_ILP32_OFFBIG,
# 346 "/usr/include/bits/confname.h" 3
_SC_XBS5_LP64_OFF64,
# 348 "/usr/include/bits/confname.h" 3
_SC_XBS5_LPBIG_OFFBIG,
# 351 "/usr/include/bits/confname.h" 3
_SC_XOPEN_LEGACY,
# 353 "/usr/include/bits/confname.h" 3
_SC_XOPEN_REALTIME,
# 355 "/usr/include/bits/confname.h" 3
_SC_XOPEN_REALTIME_THREADS,
# 358 "/usr/include/bits/confname.h" 3
_SC_ADVISORY_INFO,
# 360 "/usr/include/bits/confname.h" 3
_SC_BARRIERS,
# 362 "/usr/include/bits/confname.h" 3
_SC_BASE,
# 364 "/usr/include/bits/confname.h" 3
_SC_C_LANG_SUPPORT,
# 366 "/usr/include/bits/confname.h" 3
_SC_C_LANG_SUPPORT_R,
# 368 "/usr/include/bits/confname.h" 3
_SC_CLOCK_SELECTION,
# 370 "/usr/include/bits/confname.h" 3
_SC_CPUTIME,
# 372 "/usr/include/bits/confname.h" 3
_SC_THREAD_CPUTIME,
# 374 "/usr/include/bits/confname.h" 3
_SC_DEVICE_IO,
# 376 "/usr/include/bits/confname.h" 3
_SC_DEVICE_SPECIFIC,
# 378 "/usr/include/bits/confname.h" 3
_SC_DEVICE_SPECIFIC_R,
# 380 "/usr/include/bits/confname.h" 3
_SC_FD_MGMT,
# 382 "/usr/include/bits/confname.h" 3
_SC_FIFO,
# 384 "/usr/include/bits/confname.h" 3
_SC_PIPE,
# 386 "/usr/include/bits/confname.h" 3
_SC_FILE_ATTRIBUTES,
# 388 "/usr/include/bits/confname.h" 3
_SC_FILE_LOCKING,
# 390 "/usr/include/bits/confname.h" 3
_SC_FILE_SYSTEM,
# 392 "/usr/include/bits/confname.h" 3
_SC_MONOTONIC_CLOCK,
# 394 "/usr/include/bits/confname.h" 3
_SC_MULTI_PROCESS,
# 396 "/usr/include/bits/confname.h" 3
_SC_SINGLE_PROCESS,
# 398 "/usr/include/bits/confname.h" 3
_SC_NETWORKING,
# 400 "/usr/include/bits/confname.h" 3
_SC_READER_WRITER_LOCKS,
# 402 "/usr/include/bits/confname.h" 3
_SC_SPIN_LOCKS,
# 404 "/usr/include/bits/confname.h" 3
_SC_REGEXP,
# 406 "/usr/include/bits/confname.h" 3
_SC_REGEX_VERSION,
# 408 "/usr/include/bits/confname.h" 3
_SC_SHELL,
# 410 "/usr/include/bits/confname.h" 3
_SC_SIGNALS,
# 412 "/usr/include/bits/confname.h" 3
_SC_SPAWN,
# 414 "/usr/include/bits/confname.h" 3
_SC_SPORADIC_SERVER,
# 416 "/usr/include/bits/confname.h" 3
_SC_THREAD_SPORADIC_SERVER,
# 418 "/usr/include/bits/confname.h" 3
_SC_SYSTEM_DATABASE,
# 420 "/usr/include/bits/confname.h" 3
_SC_SYSTEM_DATABASE_R,
# 422 "/usr/include/bits/confname.h" 3
_SC_TIMEOUTS,
# 424 "/usr/include/bits/confname.h" 3
_SC_TYPED_MEMORY_OBJECTS,
# 426 "/usr/include/bits/confname.h" 3
_SC_USER_GROUPS,
# 428 "/usr/include/bits/confname.h" 3
_SC_USER_GROUPS_R,
# 430 "/usr/include/bits/confname.h" 3
_SC_2_PBS,
# 432 "/usr/include/bits/confname.h" 3
_SC_2_PBS_ACCOUNTING,
# 434 "/usr/include/bits/confname.h" 3
_SC_2_PBS_LOCATE,
# 436 "/usr/include/bits/confname.h" 3
_SC_2_PBS_MESSAGE,
# 438 "/usr/include/bits/confname.h" 3
_SC_2_PBS_TRACK,
# 440 "/usr/include/bits/confname.h" 3
_SC_SYMLOOP_MAX,
# 442 "/usr/include/bits/confname.h" 3
_SC_STREAMS,
# 444 "/usr/include/bits/confname.h" 3
_SC_2_PBS_CHECKPOINT,
# 447 "/usr/include/bits/confname.h" 3
_SC_V6_ILP32_OFF32,
# 449 "/usr/include/bits/confname.h" 3
_SC_V6_ILP32_OFFBIG,
# 451 "/usr/include/bits/confname.h" 3
_SC_V6_LP64_OFF64,
# 453 "/usr/include/bits/confname.h" 3
_SC_V6_LPBIG_OFFBIG,
# 456 "/usr/include/bits/confname.h" 3
_SC_HOST_NAME_MAX,
# 458 "/usr/include/bits/confname.h" 3
_SC_TRACE,
# 460 "/usr/include/bits/confname.h" 3
_SC_TRACE_EVENT_FILTER,
# 462 "/usr/include/bits/confname.h" 3
_SC_TRACE_INHERIT,
# 464 "/usr/include/bits/confname.h" 3
_SC_TRACE_LOG,
# 467 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_ICACHE_SIZE,
# 469 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_ICACHE_ASSOC,
# 471 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_ICACHE_LINESIZE,
# 473 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_DCACHE_SIZE,
# 475 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_DCACHE_ASSOC,
# 477 "/usr/include/bits/confname.h" 3
_SC_LEVEL1_DCACHE_LINESIZE,
# 479 "/usr/include/bits/confname.h" 3
_SC_LEVEL2_CACHE_SIZE,
# 481 "/usr/include/bits/confname.h" 3
_SC_LEVEL2_CACHE_ASSOC,
# 483 "/usr/include/bits/confname.h" 3
_SC_LEVEL2_CACHE_LINESIZE,
# 485 "/usr/include/bits/confname.h" 3
_SC_LEVEL3_CACHE_SIZE,
# 487 "/usr/include/bits/confname.h" 3
_SC_LEVEL3_CACHE_ASSOC,
# 489 "/usr/include/bits/confname.h" 3
_SC_LEVEL3_CACHE_LINESIZE,
# 491 "/usr/include/bits/confname.h" 3
_SC_LEVEL4_CACHE_SIZE,
# 493 "/usr/include/bits/confname.h" 3
_SC_LEVEL4_CACHE_ASSOC,
# 495 "/usr/include/bits/confname.h" 3
_SC_LEVEL4_CACHE_LINESIZE,
# 499 "/usr/include/bits/confname.h" 3
_SC_IPV6 = 235,
# 501 "/usr/include/bits/confname.h" 3
_SC_RAW_SOCKETS,
# 504 "/usr/include/bits/confname.h" 3
_SC_V7_ILP32_OFF32,
# 506 "/usr/include/bits/confname.h" 3
_SC_V7_ILP32_OFFBIG,
# 508 "/usr/include/bits/confname.h" 3
_SC_V7_LP64_OFF64,
# 510 "/usr/include/bits/confname.h" 3
_SC_V7_LPBIG_OFFBIG,
# 513 "/usr/include/bits/confname.h" 3
_SC_SS_REPL_MAX,
# 516 "/usr/include/bits/confname.h" 3
_SC_TRACE_EVENT_NAME_MAX,
# 518 "/usr/include/bits/confname.h" 3
_SC_TRACE_NAME_MAX,
# 520 "/usr/include/bits/confname.h" 3
_SC_TRACE_SYS_MAX,
# 522 "/usr/include/bits/confname.h" 3
_SC_TRACE_USER_EVENT_MAX,
# 525 "/usr/include/bits/confname.h" 3
_SC_XOPEN_STREAMS,
# 528 "/usr/include/bits/confname.h" 3
_SC_THREAD_ROBUST_PRIO_INHERIT,
# 530 "/usr/include/bits/confname.h" 3
_SC_THREAD_ROBUST_PRIO_PROTECT
# 532 "/usr/include/bits/confname.h" 3
};
# 536 "/usr/include/bits/confname.h" 3
enum {
# 537 "/usr/include/bits/confname.h" 3
_CS_PATH,
# 540 "/usr/include/bits/confname.h" 3
_CS_V6_WIDTH_RESTRICTED_ENVS,
# 544 "/usr/include/bits/confname.h" 3
_CS_GNU_LIBC_VERSION,
# 546 "/usr/include/bits/confname.h" 3
_CS_GNU_LIBPTHREAD_VERSION,
# 549 "/usr/include/bits/confname.h" 3
_CS_V5_WIDTH_RESTRICTED_ENVS,
# 553 "/usr/include/bits/confname.h" 3
_CS_V7_WIDTH_RESTRICTED_ENVS,
# 557 "/usr/include/bits/confname.h" 3
_CS_LFS_CFLAGS = 1000,
# 559 "/usr/include/bits/confname.h" 3
_CS_LFS_LDFLAGS,
# 561 "/usr/include/bits/confname.h" 3
_CS_LFS_LIBS,
# 563 "/usr/include/bits/confname.h" 3
_CS_LFS_LINTFLAGS,
# 565 "/usr/include/bits/confname.h" 3
_CS_LFS64_CFLAGS,
# 567 "/usr/include/bits/confname.h" 3
_CS_LFS64_LDFLAGS,
# 569 "/usr/include/bits/confname.h" 3
_CS_LFS64_LIBS,
# 571 "/usr/include/bits/confname.h" 3
_CS_LFS64_LINTFLAGS,
# 574 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
# 576 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFF32_LDFLAGS,
# 578 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFF32_LIBS,
# 580 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFF32_LINTFLAGS,
# 582 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFFBIG_CFLAGS,
# 584 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFFBIG_LDFLAGS,
# 586 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFFBIG_LIBS,
# 588 "/usr/include/bits/confname.h" 3
_CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
# 590 "/usr/include/bits/confname.h" 3
_CS_XBS5_LP64_OFF64_CFLAGS,
# 592 "/usr/include/bits/confname.h" 3
_CS_XBS5_LP64_OFF64_LDFLAGS,
# 594 "/usr/include/bits/confname.h" 3
_CS_XBS5_LP64_OFF64_LIBS,
# 596 "/usr/include/bits/confname.h" 3
_CS_XBS5_LP64_OFF64_LINTFLAGS,
# 598 "/usr/include/bits/confname.h" 3
_CS_XBS5_LPBIG_OFFBIG_CFLAGS,
# 600 "/usr/include/bits/confname.h" 3
_CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
# 602 "/usr/include/bits/confname.h" 3
_CS_XBS5_LPBIG_OFFBIG_LIBS,
# 604 "/usr/include/bits/confname.h" 3
_CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
# 607 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFF32_CFLAGS,
# 609 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
# 611 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFF32_LIBS,
# 613 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
# 615 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
# 617 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
# 619 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFFBIG_LIBS,
# 621 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
# 623 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LP64_OFF64_CFLAGS,
# 625 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LP64_OFF64_LDFLAGS,
# 627 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LP64_OFF64_LIBS,
# 629 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
# 631 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
# 633 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
# 635 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
# 637 "/usr/include/bits/confname.h" 3
_CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
# 640 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFF32_CFLAGS,
# 642 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
# 644 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFF32_LIBS,
# 646 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
# 648 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
# 650 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
# 652 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFFBIG_LIBS,
# 654 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
# 656 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LP64_OFF64_CFLAGS,
# 658 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LP64_OFF64_LDFLAGS,
# 660 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LP64_OFF64_LIBS,
# 662 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
# 664 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
# 666 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
# 668 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
# 670 "/usr/include/bits/confname.h" 3
_CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
# 673 "/usr/include/bits/confname.h" 3
_CS_V6_ENV,
# 675 "/usr/include/bits/confname.h" 3
_CS_V7_ENV
# 677 "/usr/include/bits/confname.h" 3
};
# 609 "/usr/include/unistd.h" 3
extern "C" long pathconf(const char *, int) throw() __attribute__((nonnull(1)));
# 613 "/usr/include/unistd.h" 3
extern "C" long fpathconf(int, int) throw();
# 616 "/usr/include/unistd.h" 3
extern "C" long sysconf(int) throw();
# 620 "/usr/include/unistd.h" 3
extern "C" size_t confstr(int, char *, size_t) throw();
# 625 "/usr/include/unistd.h" 3
extern "C" __pid_t getpid() throw();
# 628 "/usr/include/unistd.h" 3
extern "C" __pid_t getppid() throw();
# 633 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgrp() throw();
# 643 "/usr/include/unistd.h" 3
extern "C" __pid_t __getpgid(__pid_t) throw();
# 645 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgid(__pid_t) throw();
# 652 "/usr/include/unistd.h" 3
extern "C" int setpgid(__pid_t, __pid_t) throw();
# 669 "/usr/include/unistd.h" 3
extern "C" int setpgrp() throw();
# 686 "/usr/include/unistd.h" 3
extern "C" __pid_t setsid() throw();
# 690 "/usr/include/unistd.h" 3
extern "C" __pid_t getsid(__pid_t) throw();
# 694 "/usr/include/unistd.h" 3
extern "C" __uid_t getuid() throw();
# 697 "/usr/include/unistd.h" 3
extern "C" __uid_t geteuid() throw();
# 700 "/usr/include/unistd.h" 3
extern "C" __gid_t getgid() throw();
# 703 "/usr/include/unistd.h" 3
extern "C" __gid_t getegid() throw();
# 708 "/usr/include/unistd.h" 3
extern "C" int getgroups(int, __gid_t []) throw();
# 712 "/usr/include/unistd.h" 3
extern "C" int group_member(__gid_t) throw();
# 719 "/usr/include/unistd.h" 3
extern "C" int setuid(__uid_t) throw();
# 724 "/usr/include/unistd.h" 3
extern "C" int setreuid(__uid_t, __uid_t) throw();
# 729 "/usr/include/unistd.h" 3
extern "C" int seteuid(__uid_t) throw();
# 736 "/usr/include/unistd.h" 3
extern "C" int setgid(__gid_t) throw();
# 741 "/usr/include/unistd.h" 3
extern "C" int setregid(__gid_t, __gid_t) throw();
# 746 "/usr/include/unistd.h" 3
extern "C" int setegid(__gid_t) throw();
# 752 "/usr/include/unistd.h" 3
extern "C" int getresuid(__uid_t *, __uid_t *, __uid_t *) throw();
# 757 "/usr/include/unistd.h" 3
extern "C" int getresgid(__gid_t *, __gid_t *, __gid_t *) throw();
# 762 "/usr/include/unistd.h" 3
extern "C" int setresuid(__uid_t, __uid_t, __uid_t) throw();
# 767 "/usr/include/unistd.h" 3
extern "C" int setresgid(__gid_t, __gid_t, __gid_t) throw();
# 775 "/usr/include/unistd.h" 3
extern "C" __pid_t fork() throw();
# 783 "/usr/include/unistd.h" 3
extern "C" __pid_t vfork() throw();
# 789 "/usr/include/unistd.h" 3
extern "C" char *ttyname(int) throw();
# 793 "/usr/include/unistd.h" 3
extern "C" int ttyname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 798 "/usr/include/unistd.h" 3
extern "C" int isatty(int) throw();
# 804 "/usr/include/unistd.h" 3
extern "C" int ttyslot() throw();
# 809 "/usr/include/unistd.h" 3
extern "C" int link(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 815 "/usr/include/unistd.h" 3
extern "C" int linkat(int, const char *, int, const char *, int) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 822 "/usr/include/unistd.h" 3
extern "C" int symlink(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 828 "/usr/include/unistd.h" 3
extern "C" ssize_t readlink(const char *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 835 "/usr/include/unistd.h" 3
extern "C" int symlinkat(const char *, int, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 839 "/usr/include/unistd.h" 3
extern "C" ssize_t readlinkat(int, const char *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 845 "/usr/include/unistd.h" 3
extern "C" int unlink(const char *) throw() __attribute__((nonnull(1)));
# 849 "/usr/include/unistd.h" 3
extern "C" int unlinkat(int, const char *, int) throw() __attribute__((nonnull(2)));
# 854 "/usr/include/unistd.h" 3
extern "C" int rmdir(const char *) throw() __attribute__((nonnull(1)));
# 858 "/usr/include/unistd.h" 3
extern "C" __pid_t tcgetpgrp(int) throw();
# 861 "/usr/include/unistd.h" 3
extern "C" int tcsetpgrp(int, __pid_t) throw();
# 868 "/usr/include/unistd.h" 3
extern "C" char *getlogin();
# 876 "/usr/include/unistd.h" 3
extern "C" int getlogin_r(char *, size_t) __attribute__((nonnull(1)));
# 881 "/usr/include/unistd.h" 3
extern "C" int setlogin(const char *) throw() __attribute__((nonnull(1)));
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; }
# 73 "/usr/include/getopt.h" 3
extern "C" { extern int optind; }
# 78 "/usr/include/getopt.h" 3
extern "C" { extern int opterr; }
# 82 "/usr/include/getopt.h" 3
extern "C" { extern int optopt; }
# 152 "/usr/include/getopt.h" 3
extern "C" int getopt(int, char *const *, const char *) throw();
# 898 "/usr/include/unistd.h" 3
extern "C" int gethostname(char *, size_t) throw() __attribute__((nonnull(1)));
# 905 "/usr/include/unistd.h" 3
extern "C" int sethostname(const char *, size_t) throw() __attribute__((nonnull(1)));
# 910 "/usr/include/unistd.h" 3
extern "C" int sethostid(long) throw();
# 916 "/usr/include/unistd.h" 3
extern "C" int getdomainname(char *, size_t) throw() __attribute__((nonnull(1)));
# 918 "/usr/include/unistd.h" 3
extern "C" int setdomainname(const char *, size_t) throw() __attribute__((nonnull(1)));
# 925 "/usr/include/unistd.h" 3
extern "C" int vhangup() throw();
# 928 "/usr/include/unistd.h" 3
extern "C" int revoke(const char *) throw() __attribute__((nonnull(1)));
# 936 "/usr/include/unistd.h" 3
extern "C" int profil(unsigned short *, size_t, size_t, unsigned) throw() __attribute__((nonnull(1)));
# 944 "/usr/include/unistd.h" 3
extern "C" int acct(const char *) throw();
# 948 "/usr/include/unistd.h" 3
extern "C" char *getusershell() throw();
# 949 "/usr/include/unistd.h" 3
extern "C" void endusershell() throw();
# 950 "/usr/include/unistd.h" 3
extern "C" void setusershell() throw();
# 956 "/usr/include/unistd.h" 3
extern "C" int daemon(int, int) throw();
# 963 "/usr/include/unistd.h" 3
extern "C" int chroot(const char *) throw() __attribute__((nonnull(1)));
# 967 "/usr/include/unistd.h" 3
extern "C" char *getpass(const char *) __attribute__((nonnull(1)));
# 976 "/usr/include/unistd.h" 3
extern "C" int fsync(int);
# 983 "/usr/include/unistd.h" 3
extern "C" long gethostid();
# 986 "/usr/include/unistd.h" 3
extern "C" void sync() throw();
# 992 "/usr/include/unistd.h" 3
extern "C" int getpagesize() throw() __attribute__((__const__));
# 997 "/usr/include/unistd.h" 3
extern "C" int getdtablesize() throw();
# 1007 "/usr/include/unistd.h" 3
extern "C" int truncate(const char *, __off_t) throw() __attribute__((nonnull(1)));
# 1019 "/usr/include/unistd.h" 3
extern "C" int truncate64(const char *, __off64_t) throw() __attribute__((nonnull(1)));
# 1026 "/usr/include/unistd.h" 3
extern "C" int ftruncate(int, __off_t) throw();
# 1036 "/usr/include/unistd.h" 3
extern "C" int ftruncate64(int, __off64_t) throw();
# 1047 "/usr/include/unistd.h" 3
extern "C" int brk(void *) throw();
# 1053 "/usr/include/unistd.h" 3
extern "C" void *sbrk(intptr_t) throw();
# 1068 "/usr/include/unistd.h" 3
extern "C" long syscall(long, ...) throw();
# 1091 "/usr/include/unistd.h" 3
extern "C" int lockf(int, int, __off_t);
# 1101 "/usr/include/unistd.h" 3
extern "C" int lockf64(int, int, __off64_t);
# 1122 "/usr/include/unistd.h" 3
extern "C" int fdatasync(int);
# 1130 "/usr/include/unistd.h" 3
extern "C" char *crypt(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 1135 "/usr/include/unistd.h" 3
extern "C" void encrypt(char *, int) throw() __attribute__((nonnull(1)));
# 1142 "/usr/include/unistd.h" 3
extern "C" void swab(const void *__restrict__, void *__restrict__, ssize_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 1151 "/usr/include/unistd.h" 3
extern "C" char *ctermid(char *) throw();
# 12 "parboil/parboil.h"
extern "C" { struct pb_Parameters {
# 13 "parboil/parboil.h"
char *outFile;
# 16 "parboil/parboil.h"
char **inpFiles;
# 20 "parboil/parboil.h"
int synchronizeGpu;
# 27 "parboil/parboil.h"
}; }
# 39 "parboil/parboil.h"
extern "C" pb_Parameters *pb_ReadParameters(int *, char **);
# 44 "parboil/parboil.h"
extern "C" void pb_FreeParameters(pb_Parameters *);
# 49 "parboil/parboil.h"
extern "C" int pb_Parameters_CountInputs(pb_Parameters *);
# 53 "parboil/parboil.h"
extern "C" { typedef unsigned long long pb_Timestamp; }
# 58 "parboil/parboil.h"
enum pb_TimerState {
# 59 "parboil/parboil.h"
pb_Timer_STOPPED,
# 60 "parboil/parboil.h"
pb_Timer_RUNNING
# 61 "parboil/parboil.h"
};
# 63 "parboil/parboil.h"
extern "C" { struct pb_Timer {
# 64 "parboil/parboil.h"
pb_TimerState state;
# 65 "parboil/parboil.h"
pb_Timestamp elapsed;
# 66 "parboil/parboil.h"
pb_Timestamp init;
# 69 "parboil/parboil.h"
}; }
# 76 "parboil/parboil.h"
extern "C" void pb_ResetTimer(pb_Timer *);
# 84 "parboil/parboil.h"
extern "C" void pb_StartTimer(pb_Timer *);
# 91 "parboil/parboil.h"
extern "C" void pb_StopTimer(pb_Timer *);
# 95 "parboil/parboil.h"
extern "C" double pb_GetElapsedTime(pb_Timer *);
# 98 "parboil/parboil.h"
enum pb_TimerID {
# 99 "parboil/parboil.h"
pb_TimerID_NONE,
# 100 "parboil/parboil.h"
pb_TimerID_IO,
# 101 "parboil/parboil.h"
pb_TimerID_GPU,
# 102 "parboil/parboil.h"
pb_TimerID_COPY,
# 104 "parboil/parboil.h"
pb_TimerID_COMPUTE,
# 107 "parboil/parboil.h"
pb_TimerID_LAST
# 108 "parboil/parboil.h"
};
# 111 "parboil/parboil.h"
extern "C" { struct pb_TimerSet {
# 112 "parboil/parboil.h"
pb_TimerID current;
# 113 "parboil/parboil.h"
pb_Timer timers[pb_TimerID_LAST];
# 114 "parboil/parboil.h"
}; }
# 118 "parboil/parboil.h"
extern "C" void pb_InitializeTimerSet(pb_TimerSet *);
# 124 "parboil/parboil.h"
extern "C" void pb_SwitchToTimer(pb_TimerSet *, pb_TimerID);
# 128 "parboil/parboil.h"
extern "C" void pb_PrintTimerSet(pb_TimerSet *);
# 132 "parboil/parboil.h"
extern "C" int pb_compareFiles(const char *, const char *, double);
# 136 "parboil/parboil.h"
extern "C" int pb_compareFilesBin(const char *, const char *, double);
# 71 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char *, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 76 "/usr/include/assert.h" 3
extern "C" void __assert_perror_fail(int, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 84 "/usr/include/assert.h" 3
extern "C" void __assert(const char *, const char *, int) throw() __attribute__((__noreturn__));
# 18 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/randomc.h"
typedef signed int int32;
# 19 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/randomc.h"
typedef unsigned uint32;
# 33 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/randomc.h"
__attribute__((unused)) void RandomInit(uint32);
# 34 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/randomc.h"
__attribute__((unused)) void BRandom();
# 36 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/randomc.h"
__attribute__((unused)) static uint32 mt[624];
# 50 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
__attribute__((unused)) void RandomInit(uint32 seed)
# 51 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
{int volatile ___ = 1;
# 63 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
exit(___);}
# 66 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
__attribute__((unused)) void BRandom()
# 67 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
{int volatile ___ = 1;
# 128 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/rand_gen.cuh"
exit(___);}
# 13 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri.h"
void PetrinetKernel(int *, int, int, int);
# 18 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
__attribute__((unused)) void fire_transition(char *g_places, int *conflict_array, int tr, int
# 19 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
tc, int step, int N, int thd_thrd)
# 20 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
{int volatile ___ = 1;
# 64 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
exit(___);}
# 68 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
__attribute__((unused)) void initialize_grid(int *g_places, int NSQUARE2, int seed)
# 69 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
{int volatile ___ = 1;
# 85 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
exit(___);}
# 88 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
__attribute__((unused)) void run_trajectory(int *g_places, int N, int max_steps)
# 89 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
{int volatile ___ = 1;
# 121 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
exit(___);}
# 125 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
__attribute__((unused)) void compute_reward_stat(int *g_places, float *g_vars, int *g_maxs, int
# 126 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
NSQUARE2)
# 127 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
{int volatile ___ = 1;
# 194 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
exit(___);}
# 201 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
void PetrinetKernel(int *g_s, float *g_v, int *g_m, int n, int s, int seed) ;
# 51 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
static int N, s, t, N2, NSQUARE2;
# 52 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
uint32 host_mt[624];
# 55 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void *AllocateDeviceMemory(int);
# 56 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void CopyFromDeviceMemory(void *, void *, int);
# 57 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void CopyFromHostMemory(void *, void *, int);
# 58 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void FreeDeviceMemory(void *);
# 59 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void PetrinetOnDevice(pb_TimerSet *, pb_Parameters *);
# 61 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void compute_statistics();
# 63 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float results[4];
# 64 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float *h_vars;
# 65 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int *h_maxs;
# 67 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int main(int argc, char **argv)
# 68 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 69 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_TimerSet timers;
# 70 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_Parameters *params;
# 72 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_InitializeTimerSet(&timers);
# 73 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
params = pb_ReadParameters(&argc, argv);
# 75 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (argc < 4)
# 76 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 77 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("Usage: petri n s t\nn: the place-transition grid is 2nX2n\ns: the maximum steps in a trajectory\nt: number of trajectories\n");
# 81 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return -1;
# 82 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 84 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
# 85 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
N = atoi(argv[1]);
# 86 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (N < 1) {
# 87 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return -1; }
# 88 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
s = atoi(argv[2]);
# 89 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (s < 1) {
# 90 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return -1; }
# 92 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
t = atoi(argv[3]);
# 93 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (t < 1) {
# 94 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return -1; }
# 96 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
N2 = (N + N);
# 97 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
NSQUARE2 = (N * N2);
# 99 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
h_vars = ((float *)malloc(t * sizeof(float)));
# 100 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
h_maxs = ((int *)malloc(t * sizeof(int)));
# 103 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
PetrinetOnDevice(&timers, params);
# 104 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
# 106 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
compute_statistics();
# 108 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
free(h_vars);
# 109 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
free(h_maxs);
# 111 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(&timers, pb_TimerID_IO);
# 113 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("petri N=%d s=%d t=%d\n", N, s, t);
# 114 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("mean_vars: %f    var_vars: %f\n", (results)[0], (results)[1]);
# 115 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("mean_maxs: %f    var_maxs: %f\n", (results)[2], (results)[3]);
# 117 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (params->outFile)
# 118 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 119 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
FILE *out;
# 120 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
out = fopen(params->outFile, "w");
# 121 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
fprintf(out, "%f %f %f %f\n", (results)[0], (results)[1], (results)[2], (results)[3]);
# 123 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
fclose(out);
# 124 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 126 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (pb_compareFiles(params->outFile, "data/pns.out", 1))
# 127 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 128 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("TEST PASSED\n");
# 129 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
} else
# 131 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 132 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
printf("TEST FAILED\n");
# 133 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 135 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(&timers, pb_TimerID_NONE);
# 136 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_PrintTimerSet(&timers);
# 137 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_FreeParameters(params);
# 139 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return 0;
# 140 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 142 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void compute_statistics()
# 143 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 144 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float sum = (0);
# 145 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float sum_vars = (0);
# 146 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float sum_max = (0);
# 147 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float sum_max_vars = (0);
# 148 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int i;
# 149 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
for (i = 0; i < t; i++)
# 150 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 151 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
sum += (h_vars[i]);
# 152 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
sum_vars += ((h_vars[i]) * (h_vars[i]));
# 153 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
sum_max += (h_maxs[i]);
# 154 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
sum_max_vars += ((h_maxs[i]) * (h_maxs[i]));
# 155 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 156 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
((results)[0]) = (sum / t);
# 157 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
((results)[1]) = ((sum_vars / t) - (((results)[0]) * ((results)[0])));
# 158 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
((results)[2]) = (sum_max / t);
# 159 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
((results)[3]) = ((sum_max_vars / t) - (((results)[2]) * ((results)[2])));
# 160 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 162 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void PetrinetOnDevice(pb_TimerSet *timers, pb_Parameters *
# 163 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
params)
# 164 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 166 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int i;
# 167 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int unit_size = (((NSQUARE2 * (sizeof(int) + sizeof(char))) + sizeof(float)) + sizeof(int));
# 169 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int block_num = (750000000 / unit_size);
# 170 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int *p_hmaxs;
# 171 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float *p_hvars;
# 172 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int *g_places;
# 173 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
float *g_vars;
# 174 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int *g_maxs;
# 176 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_COPY);
# 177 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
g_places = ((int *)AllocateDeviceMemory(((unit_size - sizeof(float)) - sizeof(int)) * block_num));
# 179 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 180 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
g_vars = ((float *)AllocateDeviceMemory(block_num * sizeof(float)));
# 181 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 182 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
g_maxs = ((int *)AllocateDeviceMemory(block_num * sizeof(int)));
# 183 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 186 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
dim3 grid(block_num);
# 187 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
dim3 threads(256);
# 189 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
p_hmaxs = h_maxs;
# 190 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
p_hvars = h_vars;
# 193 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
for (i = 0; i < (t - block_num); i += block_num)
# 194 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 195 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (params->synchronizeGpu) { cudaThreadSynchronize(); }
# 196 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_GPU);
# 197 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : (PetrinetKernel)(g_places, g_vars, g_maxs, N, s, 5489 * (i + 1));
# 199 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 201 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (params->synchronizeGpu) { cudaThreadSynchronize(); }
# 202 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_COPY);
# 203 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
CopyFromDeviceMemory(p_hmaxs, g_maxs, block_num * sizeof(int));
# 204 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 205 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
CopyFromDeviceMemory(p_hvars, g_vars, block_num * sizeof(float));
# 206 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 207 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (params->synchronizeGpu) { cudaThreadSynchronize(); }
# 209 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
# 210 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
p_hmaxs += block_num;
# 211 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
p_hvars += block_num;
# 212 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 214 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
dim3 grid1(t - i);
# 215 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_GPU);
# 216 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaConfigureCall(grid1, threads) ? ((void)0) : (PetrinetKernel)(g_places, g_vars, g_maxs, N, s, time(__null));
# 218 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 221 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (params->synchronizeGpu) { cudaThreadSynchronize(); }
# 222 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
pb_SwitchToTimer(timers, pb_TimerID_COPY);
# 223 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
CopyFromDeviceMemory(p_hmaxs, g_maxs, (t - i) * sizeof(int));
# 224 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 225 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
CopyFromDeviceMemory(p_hvars, g_vars, (t - i) * sizeof(float));
# 226 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 229 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
FreeDeviceMemory(g_places);
# 230 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 231 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
FreeDeviceMemory(g_vars);
# 232 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 233 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
FreeDeviceMemory(g_maxs);
# 234 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{ cudaError_t err = cudaGetLastError(); if (err) { fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); } }
# 235 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 238 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void *AllocateDeviceMemory(int size)
# 239 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 240 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
int *mem;
# 241 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaMalloc((void **)(&mem), size);
# 242 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
return mem;
# 243 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 246 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void CopyFromDeviceMemory(void *h_p, void *d_p, int size)
# 247 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 248 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
# 249 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 252 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void CopyFromHostMemory(void *d_p, void *h_p, int size)
# 253 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 254 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
# 255 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 258 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
void FreeDeviceMemory(void *mem)
# 259 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
{
# 260 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
if (mem != (__null)) {
# 261 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
cudaFree(mem); }
# 262 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu"
}
# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c"
# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_0000171f_00000000-3_main.fatbin.c" 1
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
# 2 "/tmp/tmpxft_0000171f_00000000-3_main.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3930,0x662e20656c626973\n"
".quad 0x30315a5f20636e75,0x6e496d6f646e6152,0x61702e28206a7469,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f31666d7261,0x6d6f646e61523031,0x0a0a296a74696e49\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x646e615242375a5f,0x0a0a292820766d6f\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x6572696635315a5f,0x7469736e6172745f\n"
".quad 0x69695063506e6f69,0x702e282069696969,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f31666d726170,0x5f6572696635315a,0x697469736e617274,0x6969695063506e6f\n"
".quad 0x61702e202c696969,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261\n"
".quad 0x745f657269663531,0x6f697469736e6172,0x696969695063506e,0x7261702e202c6969\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x315a5f5f33666d72,0x72745f6572696635\n"
".quad 0x6e6f697469736e61,0x6969696969506350,0x617261702e202c69,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x35315a5f5f34666d,0x6172745f65726966,0x506e6f697469736e\n"
".quad 0x6969696969695063,0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6635315a5f5f3566,0x6e6172745f657269,0x63506e6f69746973,0x2c69696969696950\n"
".quad 0x206d617261702e20,0x635f5f203233732e,0x666d726170616475,0x696635315a5f5f36\n"
".quad 0x736e6172745f6572,0x5063506e6f697469,0x202c696969696969,0x2e206d617261702e\n"
".quad 0x75635f5f20323373,0x37666d7261706164,0x72696635315a5f5f,0x69736e6172745f65\n"
".quad 0x695063506e6f6974,0x0a0a296969696969,0x6c62697369762e09,0x20636e75662e2065\n"
".quad 0x74696e6935315a5f,0x675f657a696c6169,0x2069696950646972,0x206d617261702e28\n"
".quad 0x635f5f203233752e,0x666d726170616475,0x6e6935315a5f5f31,0x657a696c61697469\n"
".quad 0x696950646972675f,0x617261702e202c69,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x35315a5f5f32666d,0x696c616974696e69,0x50646972675f657a,0x61702e202c696969\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x616974696e693531\n"
".quad 0x6972675f657a696c,0x0a0a296969695064,0x6c62697369762e09,0x20636e75662e2065\n"
".quad 0x5f6e757234315a5f,0x6f7463656a617274,0x2820696969507972,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x31666d7261706164,0x6e757234315a5f5f,0x7463656a6172745f\n"
".quad 0x2c6969695079726f,0x206d617261702e20,0x635f5f203233732e,0x666d726170616475\n"
".quad 0x757234315a5f5f32,0x63656a6172745f6e,0x6969695079726f74,0x6d617261702e202c\n"
".quad 0x5f5f203233732e20,0x6d72617061647563,0x7234315a5f5f3366,0x656a6172745f6e75\n"
".quad 0x69695079726f7463,0x69762e090a0a2969,0x662e20656c626973,0x39315a5f20636e75\n"
".quad 0x5f657475706d6f63,0x735f647261776572,0x5366506950746174,0x7261702e2820695f\n"
".quad 0x203233752e206d61,0x6170616475635f5f,0x315a5f5f31666d72,0x657475706d6f6339\n"
".quad 0x5f6472617765725f,0x6650695074617473,0x61702e202c695f53,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f32666d7261,0x7475706d6f633931,0x6472617765725f65\n"
".quad 0x506950746174735f,0x702e202c695f5366,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f33666d726170,0x75706d6f6339315a,0x72617765725f6574,0x6950746174735f64\n"
".quad 0x2e202c695f536650,0x732e206d61726170,0x6475635f5f203233,0x5f34666d72617061\n"
".quad 0x706d6f6339315a5f,0x617765725f657475,0x50746174735f6472,0x0a29695f53665069\n"
".quad 0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d\n"
".quad 0x706d6f43202f2f09,0x742f20676e696c69,0x6678706d742f706d,0x3731303030305f74\n"
".quad 0x30303030305f6631,0x616d5f372d303030,0x2e337070632e6e69,0x2f706d742f282069\n"
".quad 0x6d552e2349426363,0x2f090a296c797932,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2f090a0a2d2d2d2d,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2f2f090a2d2d2d2d,0x736e6f6974704f20,0x2d2d2d2f2f090a3a\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x615420202f2f090a\n"
".quad 0x7874703a74656772,0x6d733a415349202c,0x646e45202c30325f,0x7474696c3a6e6169\n"
".quad 0x6e696f50202c656c,0x657a695320726574,0x202f2f090a32333a,0x704f2809334f2d20\n"
".quad 0x6974617a696d6974,0x6c6576656c206e6f,0x2d20202f2f090a29,0x7562654428093067\n"
".quad 0x296c6576656c2067,0x6d2d20202f2f090a,0x726f706552280932,0x6f73697664612074\n"
".quad 0x2f090a2973656972,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2e090a0a2d2d2d2d,0x22093109656c6966,0x646e616d6d6f633c,0x0a223e656e696c2d\n"
".quad 0x3209656c69662e09,0x742f706d742f2209,0x30305f746678706d,0x305f663137313030\n"
".quad 0x2d30303030303030,0x632e6e69616d5f36,0x672e326566616475,0x69662e090a227570\n"
".quad 0x752f22093309656c,0x672f62696c2f7273,0x2d363836692f6363,0x6e672d78756e696c\n"
".quad 0x2f352e342e342f75,0x2f6564756c636e69,0x682e666564647473,0x656c69662e090a22\n"
".quad 0x7273752f22093409,0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x642f7472632f6564,0x75725f6563697665,0x22682e656d69746e,0x09656c69662e090a\n"
".quad 0x2f7273752f220935,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x645f74736f682f65,0x682e73656e696665,0x656c69662e090a22,0x7273752f22093609\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x746c6975622f6564\n"
".quad 0x73657079745f6e69,0x69662e090a22682e,0x752f22093709656c,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x7665642f6564756c,0x657079745f656369\n"
".quad 0x662e090a22682e73,0x2f22093809656c69,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x72642f6564756c63,0x7079745f72657669,0x2e090a22682e7365\n"
".quad 0x22093909656c6966,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x732f6564756c636e,0x745f656361667275,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220930,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x7275747865742f65,0x2e73657079745f65,0x6c69662e090a2268,0x752f220931310965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x6365762f6564756c\n"
".quad 0x657079745f726f74,0x662e090a22682e73,0x2209323109656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x642f6564756c636e,0x616c5f6563697665\n"
".quad 0x7261705f68636e75,0x2e73726574656d61,0x6c69662e090a2268,0x752f220933310965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x7472632f6564756c\n"
".quad 0x656761726f74732f,0x682e7373616c635f,0x656c69662e090a22,0x73752f2209343109\n"
".quad 0x64756c636e692f72,0x742f737469622f65,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220935,0x2f6564756c636e69,0x0a22682e656d6974,0x3109656c69662e09\n"
".quad 0x656d6f682f220936,0x2f6c616d726f6e2f,0x74756f6b63656863,0x6c65636f7570672f\n"
".quad 0x73747365742f746f,0x6c696f627261702f,0x702f73747365742f,0x6f646e61722f736e\n"
".quad 0x2e090a22682e636d,0x09373109656c6966,0x6e2f656d6f682f22,0x68632f6c616d726f\n"
".quad 0x672f74756f6b6365,0x746f6c65636f7570,0x702f73747365742f,0x742f6c696f627261\n"
".quad 0x736e702f73747365,0x65675f646e61722f,0x090a226875632e6e,0x383109656c69662e\n"
".quad 0x2f656d6f682f2209,0x632f6c616d726f6e,0x2f74756f6b636568,0x6f6c65636f757067\n"
".quad 0x2f73747365742f74,0x2f6c696f62726170,0x6e702f7374736574,0x5f69727465702f73\n"
".quad 0x632e6c656e72656b,0x69662e090a226875,0x2f2209393109656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6f632f6564756c63,0x6e75665f6e6f6d6d\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209303209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x6874616d2f656475,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09313209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6e6f635f6874616d,0x682e73746e617473\n"
".quad 0x656c69662e090a22,0x73752f2209323209,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x697665642f656475,0x74636e75665f6563,0x0a22682e736e6f69\n"
".quad 0x3209656c69662e09,0x2f7273752f220933,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x5f31315f6d732f65,0x665f63696d6f7461,0x736e6f6974636e75\n"
".quad 0x69662e090a22682e,0x2f2209343209656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x6d732f6564756c63,0x6d6f74615f32315f,0x74636e75665f6369\n"
".quad 0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220935,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x5f33315f6d732f65,0x665f656c62756f64\n"
".quad 0x736e6f6974636e75,0x69662e090a22682e,0x2f2209363209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6d732f6564756c63,0x6d6f74615f30325f\n"
".quad 0x74636e75665f6369,0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220937\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x5f30325f6d732f65\n"
".quad 0x69736e6972746e69,0x2e090a22682e7363,0x09383209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x5f65636166727573\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209393209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x742f6564756c636e,0x665f657275747865\n"
".quad 0x6e75665f68637465,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209303309\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x6874616d2f656475\n"
".quad 0x6f6974636e75665f,0x705f6c62645f736e,0x0a0a22682e337874,0x6465726168732e09\n"
".quad 0x206e67696c612e20,0x746d2038622e2034,0x0a3b5d363934325b,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x6e615230315a5f20,0x6a74696e496d6f64,0x6d617261702e2820\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x5230315a5f5f3166,0x696e496d6f646e61\n"
".quad 0x090a7b090a296a74,0x33752e206765722e,0x3e35313c72252032,0x206765722e090a3b\n"
".quad 0x702520646572702e,0x6c2e090a3b3e343c,0x313509373109636f,0x6257444c240a3009\n"
".quad 0x315a5f5f6e696765,0x496d6f646e615230,0x6c090a3a6a74696e,0x2e6d617261702e64\n"
".quad 0x3172250920323375,0x6475635f5f5b202c,0x5f31666d72617061,0x646e615230315a5f\n"
".quad 0x5d6a74696e496d6f,0x732e766f6d090a3b,0x2c32722509203233,0x6d090a3b31722520\n"
".quad 0x09203233752e766f,0x697425202c337225,0x6f6d090a3b782e64,0x2509203233752e76\n"
".quad 0x090a3b30202c3472,0x2e656e2e70746573,0x3170250920323375,0x25202c337225202c\n"
".quad 0x702540090a3b3472,0x2409206172622031,0x3530325f305f744c,0x636f6c2e090a3b30\n"
".quad 0x3009363509373109,0x33752e766f6d090a,0x202c357225092032,0x2e7473090a3b746d\n"
".quad 0x752e646572616873,0x2b746d5b09203233,0x3b327225202c5d30,0x33752e646461090a\n"
".quad 0x202c367225092032,0x0a3b34202c357225,0x3233752e64646109,0x25202c3772250920\n"
".quad 0x36393432202c3572,0x732e766f6d090a3b,0x2c38722509203233,0x5f744c240a3b3120\n"
".quad 0x0a3a343730335f30,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x73656e202c363520,0x70656420676e6974,0x69202c31203a6874,0x6e6f697461726574\n"
".quad 0x090a333236203a73,0x09373109636f6c2e,0x646c090a30093935,0x2e6465726168732e\n"
".quad 0x3972250920323375,0x2d2b3672255b202c,0x726873090a3b5d34,0x722509203233752e\n"
".quad 0x2c397225202c3031,0x6f78090a3b303320,0x2509203233622e72,0x397225202c313172\n"
".quad 0x0a3b30317225202c,0x2e6f6c2e6c756d09,0x3172250920323375,0x2c31317225202c32\n"
".quad 0x3333343231383120,0x6461090a3b333532,0x2509203233752e64,0x387225202c333172\n"
".quad 0x0a3b32317225202c,0x726168732e747309,0x09203233752e6465,0x2c5d302b3672255b\n"
".quad 0x090a3b3331722520,0x203233732e646461,0x7225202c38722509,0x61090a3b31202c38\n"
".quad 0x09203233752e6464,0x367225202c367225,0x6573090a3b34202c,0x33752e656e2e7074\n"
".quad 0x202c327025092032,0x377225202c367225,0x2032702540090a3b,0x744c240920617262\n"
".quad 0x3b343730335f305f,0x325f305f744c240a,0x6c2e090a3a303530,0x333609373109636f\n"
".quad 0x3b746572090a3009,0x646e6557444c240a,0x6e615230315a5f5f,0x6a74696e496d6f64\n"
".quad 0x202f2f207d090a3a,0x646e615230315a5f,0x0a6a74696e496d6f,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x6e615242375a5f20,0x0a292820766d6f64,0x6765722e090a7b09\n"
".quad 0x7225203233752e20,0x2e090a3b3e38363c,0x6572702e20676572,0x3b3e353c70252064\n"
".quad 0x635f5f202f2f090a,0x61636f6c5f616475,0x31335f7261765f6c,0x6e5f30315f323032\n"
".quad 0x74736e6f635f6e6f,0x090a30203d20795f,0x09373109636f6c2e,0x444c240a30093736\n"
".quad 0x5f5f6e6967656257,0x6f646e615242375a,0x766f6d090a3a766d,0x722509203233752e\n"
".quad 0x2e64697425202c31,0x2e766f6d090a3b78,0x3272250920323375,0x090a3b363232202c\n"
".quad 0x2e656c2e70746573,0x3170250920323375,0x25202c317225202c,0x252140090a3b3272\n"
".quad 0x0920617262203170,0x37385f315f744c24,0x6f6c2e090a3b3630,0x0937370937310963\n"
".quad 0x752e766f6d090a30,0x2c33722509203233,0x756d090a3b746d20,0x3233752e6f6c2e6c\n"
".quad 0x25202c3472250920,0x090a3b34202c3172,0x203233752e646461,0x7225202c35722509\n"
".quad 0x0a3b337225202c34,0x726168732e646c09,0x09203233752e6465,0x72255b202c367225\n"
".quad 0x6c090a3b5d302b35,0x6465726168732e64,0x722509203233752e,0x2b3572255b202c37\n"
".quad 0x2e646c090a3b5d34,0x752e646572616873,0x2c38722509203233,0x35312b3572255b20\n"
".quad 0x6e61090a3b5d3838,0x2509203233622e64,0x2c367225202c3972,0x3834373431322d20\n"
".quad 0x61090a3b38343633,0x09203233622e646e,0x7225202c30317225,0x3437343132202c37\n"
".quad 0x090a3b3734363338,0x09203233622e726f,0x7225202c31317225,0x3b30317225202c39\n"
".quad 0x33752e726873090a,0x2c32317225092032,0x31202c3131722520,0x622e726f78090a3b\n"
".quad 0x3331722509203233,0x25202c387225202c,0x6f78090a3b323172,0x2509203233622e72\n"
".quad 0x317225202c343172,0x373237312d202c33,0x0a3b313836333834,0x3233622e646e6109\n"
".quad 0x202c353172250920,0x3b31202c31317225,0x33732e67656e090a,0x2c36317225092032\n"
".quad 0x090a3b3531722520,0x3233752e74636c73,0x722509203233732e,0x33317225202c3731\n"
".quad 0x202c34317225202c,0x6d090a3b36317225,0x09203233732e766f,0x7225202c38317225\n"
".quad 0x5f744c240a3b3731,0x0a3a363037385f31,0x3233752e766f6d09,0x6d202c3372250920\n"
".quad 0x636f6c2e090a3b74,0x3009393709373109,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x7262203170252140,0x315f744c24092061,0x090a3b383132395f,0x09373109636f6c2e\n"
".quad 0x6f6d090a30093238,0x2509203233732e76,0x317225202c393172,0x2e6c756d090a3b38\n"
".quad 0x09203233752e6f6c,0x7225202c30327225,0x61090a3b34202c31,0x09203233752e6464\n"
".quad 0x7225202c31327225,0x3b30327225202c33,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x302b313272255b09,0x3b39317225202c5d,0x395f315f744c240a,0x6c2e090a3a383132\n"
".quad 0x343809373109636f,0x2e726162090a3009,0x3b300920636e7973,0x203170252140090a\n"
".quad 0x744c240920617262,0x3b303337395f315f,0x3109636f6c2e090a,0x090a300931390937\n"
".quad 0x752e6f6c2e6c756d,0x2c34722509203233,0x3b34202c31722520,0x33752e646461090a\n"
".quad 0x202c357225092032,0x337225202c347225,0x68732e646c090a3b,0x3233752e64657261\n"
".quad 0x202c323272250920,0x3830392b3572255b,0x732e646c090a3b5d,0x33752e6465726168\n"
".quad 0x2c33327225092032,0x31392b3572255b20,0x2e646c090a3b5d32,0x752e646572616873\n"
".quad 0x3432722509203233,0x302b3572255b202c,0x2e646e61090a3b5d,0x3272250920323362\n"
".quad 0x2c32327225202c35,0x3834373431322d20,0x61090a3b38343633,0x09203233622e646e\n"
".quad 0x7225202c36327225,0x37343132202c3332,0x0a3b373436333834,0x203233622e726f09\n"
".quad 0x25202c3732722509,0x327225202c353272,0x2e726873090a3b36,0x3272250920323375\n"
".quad 0x2c37327225202c38,0x726f78090a3b3120,0x722509203233622e,0x34327225202c3932\n"
".quad 0x0a3b38327225202c,0x3233622e726f7809,0x202c303372250920,0x312d202c39327225\n"
".quad 0x3836333834373237,0x2e646e61090a3b31,0x3372250920323362,0x2c37327225202c31\n"
".quad 0x67656e090a3b3120,0x722509203233732e,0x31337225202c3233,0x2e74636c73090a3b\n"
".quad 0x203233732e323375,0x25202c3333722509,0x337225202c393272,0x3b32337225202c30\n"
".quad 0x33732e766f6d090a,0x2c38317225092032,0x240a3b3333722520,0x3337395f315f744c\n"
".quad 0x636f6c2e090a3a30,0x3009333909373109,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x7262203170252140,0x315f744c24092061,0x0a3b32343230315f,0x373109636f6c2e09\n"
".quad 0x6d090a3009363909,0x09203233732e766f,0x7225202c34337225,0x6c756d090a3b3831\n"
".quad 0x203233752e6f6c2e,0x25202c3533722509,0x090a3b34202c3172,0x203233752e646461\n"
".quad 0x25202c3633722509,0x35337225202c3372,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x2b363372255b0920,0x7225202c5d383039,0x5f744c240a3b3433,0x3a32343230315f31\n"
".quad 0x3109636f6c2e090a,0x090a300938390937,0x636e79732e726162,0x6461090a3b300920\n"
".quad 0x2509203233732e64,0x317225202c373372,0x090a3b343534202c,0x203233732e766f6d\n"
".quad 0x36202c3833722509,0x746573090a3b3232,0x3233732e656c2e70,0x25202c3270250920\n"
".quad 0x337225202c373372,0x70252140090a3b38,0x2409206172622032,0x3730315f315f744c\n"
".quad 0x6f6c2e090a3b3435,0x3530310937310963,0x2e6c756d090a3009,0x09203233752e6f6c\n"
".quad 0x317225202c347225,0x6461090a3b34202c,0x2509203233752e64,0x2c347225202c3572\n"
".quad 0x6c090a3b33722520,0x6465726168732e64,0x722509203233752e,0x3572255b202c3933\n"
".quad 0x0a3b5d363138312b,0x726168732e646c09,0x09203233752e6465,0x255b202c30347225\n"
".quad 0x5d303238312b3572,0x68732e646c090a3b,0x3233752e64657261,0x202c313472250920\n"
".quad 0x3830392b3572255b,0x2e646e61090a3b5d,0x3472250920323362,0x2c39337225202c32\n"
".quad 0x3834373431322d20,0x61090a3b38343633,0x09203233622e646e,0x7225202c33347225\n"
".quad 0x37343132202c3034,0x0a3b373436333834,0x203233622e726f09,0x25202c3434722509\n"
".quad 0x347225202c323472,0x2e726873090a3b33,0x3472250920323375,0x2c34347225202c35\n"
".quad 0x726f78090a3b3120,0x722509203233622e,0x31347225202c3634,0x0a3b35347225202c\n"
".quad 0x3233622e726f7809,0x202c373472250920,0x312d202c36347225,0x3836333834373237\n"
".quad 0x2e646e61090a3b31,0x3472250920323362,0x2c34347225202c38,0x67656e090a3b3120\n"
".quad 0x722509203233732e,0x38347225202c3934,0x2e74636c73090a3b,0x203233732e323375\n"
".quad 0x25202c3035722509,0x347225202c363472,0x3b39347225202c37,0x33732e766f6d090a\n"
".quad 0x2c38317225092032,0x240a3b3035722520,0x3730315f315f744c,0x6f6c2e090a3a3435\n"
".quad 0x3730310937310963,0x2e726162090a3009,0x3b300920636e7973,0x203270252140090a\n"
".quad 0x744c240920617262,0x36363231315f315f,0x09636f6c2e090a3b,0x3009303131093731\n"
".quad 0x33732e766f6d090a,0x2c31357225092032,0x090a3b3831722520,0x752e6f6c2e6c756d\n"
".quad 0x3235722509203233,0x34202c317225202c,0x752e646461090a3b,0x3335722509203233\n"
".quad 0x25202c337225202c,0x7473090a3b323572,0x2e6465726168732e,0x72255b0920323375\n"
".quad 0x5d363138312b3335,0x0a3b31357225202c,0x31315f315f744c24,0x6c2e090a3a363632\n"
".quad 0x313109373109636f,0x726162090a300932,0x300920636e79732e,0x752e766f6d090a3b\n"
".quad 0x3435722509203233,0x6573090a3b30202c,0x33752e656e2e7074,0x202c337025092032\n"
".quad 0x357225202c317225,0x33702540090a3b34,0x4c24092061726220,0x373731315f315f74\n"
".quad 0x636f6c2e090a3b38,0x0938313109373109,0x68732e646c090a30,0x3233752e64657261\n"
".quad 0x202c353572250920,0x0a3b5d302b746d5b,0x3233622e646e6109,0x202c363572250920\n"
".quad 0x3132202c35357225,0x3734363338343734,0x68732e646c090a3b,0x3233752e64657261\n"
".quad 0x202c373572250920,0x323934322b746d5b,0x2e646e61090a3b5d,0x3572250920323362\n"
".quad 0x2c37357225202c38,0x3834373431322d20,0x6f090a3b38343633,0x2509203233622e72\n"
".quad 0x357225202c393572,0x3b38357225202c36,0x33752e726873090a,0x2c30367225092032\n"
".quad 0x31202c3935722520,0x68732e646c090a3b,0x3233752e64657261,0x202c313672250920\n"
".quad 0x343835312b746d5b,0x2e726f78090a3b5d,0x3672250920323362,0x2c30367225202c32\n"
".quad 0x090a3b3136722520,0x203233622e726f78,0x25202c3336722509,0x37312d202c323672\n"
".quad 0x3138363338343732,0x622e646e61090a3b,0x3436722509203233,0x202c39357225202c\n"
".quad 0x2e67656e090a3b31,0x3672250920323373,0x3b34367225202c35,0x752e74636c73090a\n"
".quad 0x09203233732e3233,0x7225202c36367225,0x33367225202c3236,0x0a3b35367225202c\n"
".quad 0x726168732e747309,0x09203233752e6465,0x323934322b746d5b,0x3b36367225202c5d\n"
".quad 0x315f315f744c240a,0x2e090a3a38373731,0x3109373109636f6c,0x6572090a30093832\n"
".quad 0x6557444c240a3b74,0x5242375a5f5f646e,0x0a3a766d6f646e61,0x5a5f202f2f207d09\n"
".quad 0x6d6f646e61524237,0x7369762e090a0a76,0x75662e20656c6269,0x6635315a5f20636e\n"
".quad 0x6e6172745f657269,0x63506e6f69746973,0x2069696969696950,0x206d617261702e28\n"
".quad 0x635f5f203233752e,0x666d726170616475,0x696635315a5f5f31,0x736e6172745f6572\n"
".quad 0x5063506e6f697469,0x202c696969696969,0x2e206d617261702e,0x75635f5f20323375\n"
".quad 0x32666d7261706164,0x72696635315a5f5f,0x69736e6172745f65,0x695063506e6f6974\n"
".quad 0x2e202c6969696969,0x732e206d61726170,0x6475635f5f203233,0x5f33666d72617061\n"
".quad 0x6572696635315a5f,0x7469736e6172745f,0x69695063506e6f69,0x702e202c69696969\n"
".quad 0x33732e206d617261,0x616475635f5f2032,0x5f5f34666d726170,0x5f6572696635315a\n"
".quad 0x697469736e617274,0x6969695063506e6f,0x61702e202c696969,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f35666d7261,0x745f657269663531,0x6f697469736e6172\n"
".quad 0x696969695063506e,0x7261702e202c6969,0x203233732e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f36666d72,0x72745f6572696635,0x6e6f697469736e61,0x6969696969506350\n"
".quad 0x617261702e202c69,0x5f203233732e206d,0x726170616475635f,0x35315a5f5f37666d\n"
".quad 0x6172745f65726966,0x506e6f697469736e,0x6969696969695063,0x722e090a7b090a29\n"
".quad 0x203233752e206765,0x3b3e3630313c7225,0x2e206765722e090a,0x3c70252064657270\n"
".quad 0x2f2f090a3b3e3431,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f37323331335f72\n"
".quad 0x6f635f6e6f6e5f37,0x316c61765f74736e,0x2f2f090a30203d20,0x5f616475635f5f20\n"
".quad 0x61765f6c61636f6c,0x5f37323331335f72,0x635f6e6f6e5f3331,0x6c61765f74736e6f\n"
".quad 0x2f090a34203d2032,0x616475635f5f202f,0x765f6c61636f6c5f,0x37323331335f7261\n"
".quad 0x5f6e6f6e5f39315f,0x61765f74736e6f63,0x090a38203d20336c,0x6475635f5f202f2f\n"
".quad 0x5f6c61636f6c5f61,0x323331335f726176,0x5f6e6f6e5f375f38,0x616d5f74736e6f63\n"
".quad 0x3231203d20316b72,0x635f5f202f2f090a,0x61636f6c5f616475,0x31335f7261765f6c\n"
".quad 0x6e5f34315f383233,0x74736e6f635f6e6f,0x3d20326b72616d5f,0x6f6c2e090a363120\n"
".quad 0x0930320938310963,0x656257444c240a30,0x35315a5f5f6e6967,0x6172745f65726966\n"
".quad 0x506e6f697469736e,0x6969696969695063,0x61702e646c090a3a,0x203233752e6d6172\n"
".quad 0x5f5b202c31722509,0x726170616475635f,0x35315a5f5f31666d,0x6172745f65726966\n"
".quad 0x506e6f697469736e,0x6969696969695063,0x2e766f6d090a3b5d,0x3272250920323373\n"
".quad 0x090a3b317225202c,0x6d617261702e646c,0x722509203233752e,0x75635f5f5b202c33\n"
".quad 0x32666d7261706164,0x72696635315a5f5f,0x69736e6172745f65,0x695063506e6f6974\n"
".quad 0x0a3b5d6969696969,0x3233732e766f6d09,0x25202c3472250920,0x2e646c090a3b3372\n"
".quad 0x33752e6d61726170,0x202c357225092032,0x70616475635f5f5b,0x5a5f5f33666d7261\n"
".quad 0x745f657269663531,0x6f697469736e6172,0x696969695063506e,0x6f6d090a3b5d6969\n"
".quad 0x2509203233732e76,0x3b357225202c3672,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c377225,0x6d72617061647563,0x6635315a5f5f3466,0x6e6172745f657269\n"
".quad 0x63506e6f69746973,0x5d69696969696950,0x732e766f6d090a3b,0x2c38722509203233\n"
".quad 0x6c090a3b37722520,0x2e6d617261702e64,0x3972250920323375,0x6475635f5f5b202c\n"
".quad 0x5f35666d72617061,0x6572696635315a5f,0x7469736e6172745f,0x69695063506e6f69\n"
".quad 0x090a3b5d69696969,0x203233732e766f6d,0x25202c3031722509,0x2e646c090a3b3972\n"
".quad 0x33752e6d61726170,0x2c31317225092032,0x616475635f5f5b20,0x5f5f36666d726170\n"
".quad 0x5f6572696635315a,0x697469736e617274,0x6969695063506e6f,0x6d090a3b5d696969\n"
".quad 0x09203233732e766f,0x7225202c32317225,0x2e646c090a3b3131,0x33752e6d61726170\n"
".quad 0x2c33317225092032,0x616475635f5f5b20,0x5f5f37666d726170,0x5f6572696635315a\n"
".quad 0x697469736e617274,0x6969695063506e6f,0x6d090a3b5d696969,0x09203233732e766f\n"
".quad 0x7225202c34317225,0x766f6d090a3b3331,0x722509203233752e,0x64697425202c3531\n"
".quad 0x746573090a3b782e,0x3233752e656c2e70,0x25202c3170250920,0x317225202c343172\n"
".quad 0x31702540090a3b35,0x4c24092061726220,0x393430315f325f74,0x636f6c2e090a3b38\n"
".quad 0x3009383209383109,0x33732e766f6d090a,0x2c36317225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x25202c3270250920,0x36317225202c3672,0x732e646461090a3b\n"
".quad 0x3731722509203233,0x202c32317225202c,0x73090a3b32317225,0x09203233732e6275\n"
".quad 0x7225202c38317225,0x73090a3b31202c36,0x09203233732e6275,0x7225202c39317225\n"
".quad 0x090a3b31202c3731,0x3233732e706c6573,0x202c303272250920,0x7225202c39317225\n"
".quad 0x3b327025202c3831,0x33732e766f6d090a,0x2c31327225092032,0x090a3b3032722520\n"
".quad 0x203233622e646e61,0x25202c3232722509,0x090a3b31202c3672,0x203233752e766f6d\n"
".quad 0x30202c3332722509,0x2e70746573090a3b,0x09203233732e7165,0x327225202c337025\n"
".quad 0x3b33327225202c32,0x622033702540090a,0x5f744c2409206172,0x3b30313031315f32\n"
".quad 0x3109636f6c2e090a,0x090a300939320938,0x203233732e646461,0x25202c3432722509\n"
".quad 0x090a3b31202c3872,0x203233732e766f6d,0x30202c3532722509,0x732e627573090a3b\n"
".quad 0x3632722509203233,0x202c32317225202c,0x70746573090a3b31,0x203233732e656e2e\n"
".quad 0x7225202c34702509,0x3b36327225202c38,0x732e706c6573090a,0x3732722509203233\n"
".quad 0x202c34327225202c,0x7025202c35327225,0x2e617262090a3b34,0x744c240920696e75\n"
".quad 0x34353730315f325f,0x5f325f744c240a3b,0x090a3a3031303131,0x203233732e766f6d\n"
".quad 0x25202c3732722509,0x5f744c240a3b3872,0x3a34353730315f32,0x33732e766f6d090a\n"
".quad 0x2c38327225092032,0x090a3b3732722520,0x09383109636f6c2e,0x6461090a30093033\n"
".quad 0x2509203233732e64,0x367225202c393272,0x6f6d090a3b31202c,0x2509203233732e76\n"
".quad 0x0a3b30202c303372,0x656e2e7074657309,0x702509203233732e,0x2c39317225202c35\n"
".quad 0x73090a3b36722520,0x203233732e706c65,0x25202c3133722509,0x337225202c393272\n"
".quad 0x0a3b357025202c30,0x3233732e766f6d09,0x202c323372250920,0x2e090a3b31337225\n"
".quad 0x3309383109636f6c,0x6c756d090a300931,0x203233732e6f6c2e,0x25202c3333722509\n"
".quad 0x317225202c303272,0x2e646461090a3b32,0x3372250920323373,0x2c37327225202c34\n"
".quad 0x090a3b3333722520,0x203233752e646461,0x25202c3533722509,0x34337225202c3272\n"
".quad 0x38732e646c090a3b,0x202c363372250920,0x5d302b353372255b,0x732e766f6d090a3b\n"
".quad 0x3733722509203233,0x0a3b36337225202c,0x383109636f6c2e09,0x6d090a3009323309\n"
".quad 0x33732e6f6c2e6c75,0x2c38337225092032,0x7225202c36722520,0x646461090a3b3231\n"
".quad 0x722509203233732e,0x38337225202c3933,0x090a3b387225202c,0x203233752e646461\n"
".quad 0x25202c3034722509,0x327225202c393372,0x38732e646c090a3b,0x202c313472250920\n"
".quad 0x5d302b303472255b,0x732e766f6d090a3b,0x3234722509203233,0x0a3b31347225202c\n"
".quad 0x3233732e766f6d09,0x202c333472250920,0x2e746573090a3b30,0x732e3233752e7467\n"
".quad 0x3434722509203233,0x202c31347225202c,0x6e090a3b33347225,0x09203233732e6765\n"
".quad 0x7225202c35347225,0x766f6d090a3b3434,0x722509203233732e,0x090a3b30202c3634\n"
".quad 0x752e74672e746573,0x09203233732e3233,0x7225202c37347225,0x36347225202c3633\n"
".quad 0x732e67656e090a3b,0x3834722509203233,0x0a3b37347225202c,0x3233622e646e6109\n"
".quad 0x202c393472250920,0x7225202c35347225,0x766f6d090a3b3834,0x722509203233752e\n"
".quad 0x090a3b30202c3035,0x2e71652e70746573,0x3670250920323373,0x202c39347225202c\n"
".quad 0x40090a3b30357225,0x2061726220367025,0x315f325f744c2409,0x2e090a3b32323531\n"
".quad 0x3309383109636f6c,0x6c756d090a300936,0x203233752e6f6c2e,0x25202c3135722509\n"
".quad 0x0a3b34202c393372,0x3233752e64646109,0x202c323572250920,0x357225202c347225\n"
".quad 0x732e7473090a3b31,0x3572255b09203233,0x7225202c5d302b32,0x766f6d090a3b3031\n"
".quad 0x722509203233732e,0x090a3b31202c3335,0x20696e752e617262,0x315f325f744c2409\n"
".quad 0x4c240a3b32343230,0x323531315f325f74,0x2e766f6d090a3a32,0x3572250920323373\n"
".quad 0x62090a3b30202c33,0x0920696e752e6172,0x30315f325f744c24,0x744c240a3b323432\n"
".quad 0x38393430315f325f,0x732e766f6d090a3a,0x3335722509203233,0x744c240a3b30202c\n"
".quad 0x32343230315f325f,0x09636f6c2e090a3a,0x0a30093933093831,0x6e79732e72616209\n"
".quad 0x6d090a3b30092063,0x09203233732e766f,0x3b30202c34357225,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x33357225202c3770,0x0a3b34357225202c,0x6220377025214009\n"
".quad 0x5f744c2409206172,0x3b38373731315f32,0x3109636f6c2e090a,0x090a300935340938\n"
".quad 0x203233622e646e61,0x25202c3535722509,0x090a3b31202c3672,0x203233622e646e61\n"
".quad 0x25202c3635722509,0x0a3b31202c303172,0x71652e7074657309,0x702509203233732e\n"
".quad 0x2c35357225202c38,0x090a3b3635722520,0x6172622038702540,0x5f325f744c240920\n"
".quad 0x6d090a3b36383533,0x09203233732e766f,0x7225202c37357225,0x766f6d090a3b3832\n"
".quad 0x722509203233732e,0x31327225202c3835,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x357225202c393572,0x3b32317225202c38,0x33732e646461090a,0x2c30367225092032\n"
".quad 0x25202c3735722520,0x756d090a3b393572,0x3233752e6f6c2e6c,0x202c313672250920\n"
".quad 0x3b34202c30367225,0x33752e646461090a,0x2c32367225092032,0x7225202c34722520\n"
".quad 0x2e646c090a3b3136,0x3672250920323373,0x323672255b202c33,0x6573090a3b5d302b\n"
".quad 0x33732e71652e7074,0x202c397025092032,0x7225202c33367225,0x702540090a3b3031\n"
".quad 0x2409206172622039,0x3533315f325f744c,0x766f6d090a3b3037,0x722509203233732e\n"
".quad 0x32337225202c3436,0x6c2e6c756d090a3b,0x2509203233732e6f,0x367225202c353672\n"
".quad 0x3b32317225202c34,0x33732e646461090a,0x2c36367225092032,0x25202c3536722520\n"
".quad 0x756d090a3b323172,0x3233752e6f6c2e6c,0x202c373672250920,0x3b34202c36367225\n"
".quad 0x33752e627573090a,0x2c38367225092032,0x34202c3736722520,0x732e646461090a3b\n"
".quad 0x3936722509203233,0x202c35367225202c,0x6d090a3b37357225,0x33752e6f6c2e6c75\n"
".quad 0x2c30377225092032,0x34202c3936722520,0x752e627573090a3b,0x3137722509203233\n"
".quad 0x202c30377225202c,0x2e766f6d090a3b34,0x3772250920323373,0x73090a3b30202c32\n"
".quad 0x732e71652e707465,0x3031702509203233,0x202c37357225202c,0x73090a3b32377225\n"
".quad 0x203233752e706c65,0x25202c3337722509,0x377225202c383672,0x3b30317025202c31\n"
".quad 0x33752e646461090a,0x2c34377225092032,0x25202c3337722520,0x2e646c090a3b3472\n"
".quad 0x3772250920323373,0x343772255b202c35,0x6573090a3b5d302b,0x33732e71652e7074\n"
".quad 0x2c31317025092032,0x25202c3537722520,0x2540090a3b303172,0x2061726220313170\n"
".quad 0x315f325f744c2409,0x4c240a3b30373533,0x363835335f325f74,0x732e766f6d090a3a\n"
".quad 0x3637722509203233,0x7262090a3b31202c,0x240920696e752e61,0x3231355f325f744c\n"
".quad 0x325f744c240a3b32,0x0a3a30373533315f,0x38335f325f744c24,0x766f6d090a3a3234\n"
".quad 0x722509203233732e,0x240a3b30202c3637,0x3231355f325f744c,0x2e766f6d090a3a32\n"
".quad 0x3572250920323373,0x3b36377225202c33,0x33732e766f6d090a,0x2c37377225092032\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x25202c3770250920,0x377225202c333572\n"
".quad 0x325f744c240a3b37,0x0a3a38373731315f,0x6220377025214009,0x5f744c2409206172\n"
".quad 0x3b30393232315f32,0x3109636f6c2e090a,0x090a300934350938,0x203233732e766f6d\n"
".quad 0x25202c3837722509,0x7573090a3b373372,0x2509203233732e62,0x377225202c393772\n"
".quad 0x6d090a3b31202c38,0x09203233732e766f,0x7225202c30387225,0x766f6d090a3b3832\n"
".quad 0x722509203233732e,0x31327225202c3138,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x387225202c323872,0x3b32317225202c31,0x33732e646461090a,0x2c33387225092032\n"
".quad 0x25202c3038722520,0x6461090a3b323872,0x2509203233752e64,0x327225202c343872\n"
".quad 0x0a3b33387225202c,0x092038732e747309,0x5d302b343872255b,0x0a3b39377225202c\n"
".quad 0x383109636f6c2e09,0x6d090a3009353509,0x09203233732e766f,0x7225202c35387225\n"
".quad 0x627573090a3b3234,0x722509203233732e,0x35387225202c3638,0x756d090a3b31202c\n"
".quad 0x3233732e6f6c2e6c,0x202c373872250920,0x317225202c367225,0x2e646461090a3b32\n"
".quad 0x3872250920323373,0x202c387225202c38,0x61090a3b37387225,0x09203233752e6464\n"
".quad 0x7225202c39387225,0x3b38387225202c32,0x2038732e7473090a,0x302b393872255b09\n"
".quad 0x3b36387225202c5d,0x315f325f744c240a,0x2e090a3a30393232,0x3509383109636f6c\n"
".quad 0x726162090a300937,0x300920636e79732e,0x3770252140090a3b,0x4c24092061726220\n"
".quad 0x303832315f325f74,0x636f6c2e090a3b32,0x3009303609383109,0x33732e766f6d090a\n"
".quad 0x2c30397225092032,0x090a3b3233722520,0x732e6f6c2e6c756d,0x3139722509203233\n"
".quad 0x202c30397225202c,0x6d090a3b32317225,0x09203233732e766f,0x7225202c32397225\n"
".quad 0x646461090a3b3832,0x722509203233732e,0x32397225202c3339,0x0a3b31397225202c\n"
".quad 0x3233752e64646109,0x202c343972250920,0x7225202c33397225,0x732e646c090a3b32\n"
".quad 0x2c35397225092038,0x302b343972255b20,0x2e646461090a3b5d,0x3972250920323373\n"
".quad 0x2c35397225202c36,0x2e7473090a3b3120,0x3972255b09203873,0x7225202c5d302b34\n"
".quad 0x6f6c2e090a3b3639,0x0931360938310963,0x732e627573090a30,0x3739722509203233\n"
".quad 0x202c32317225202c,0x2e6c756d090a3b31,0x09203233732e6f6c,0x7225202c38397225\n"
".quad 0x3b32317225202c36,0x6e2e70746573090a,0x2509203233732e65,0x397225202c323170\n"
".quad 0x0a3b387225202c37,0x3233732e64646109,0x202c393972250920,0x7225202c38397225\n"
".quad 0x2e646461090a3b38,0x3172250920323375,0x39397225202c3030,0x6573090a3b31202c\n"
".quad 0x09203233752e706c,0x25202c3130317225,0x7225202c30303172,0x32317025202c3839\n"
".quad 0x752e646461090a3b,0x3031722509203233,0x3130317225202c32,0x090a3b327225202c\n"
".quad 0x25092038732e646c,0x255b202c33303172,0x3b5d302b32303172,0x33732e646461090a\n"
".quad 0x3430317225092032,0x2c3330317225202c,0x2e7473090a3b3120,0x3172255b09203873\n"
".quad 0x25202c5d302b3230,0x4c240a3b34303172,0x303832315f325f74,0x636f6c2e090a3a32\n"
".quad 0x3009343609383109,0x240a3b746572090a,0x5f5f646e6557444c,0x5f6572696635315a\n"
".quad 0x697469736e617274,0x6969695063506e6f,0x207d090a3a696969,0x6635315a5f202f2f\n"
".quad 0x6e6172745f657269,0x63506e6f69746973,0x0a69696969696950,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x696e6935315a5f20,0x5f657a696c616974,0x6969695064697267\n"
".quad 0x6d617261702e2820,0x5f5f203233752e20,0x6d72617061647563,0x6935315a5f5f3166\n"
".quad 0x7a696c616974696e,0x6950646972675f65,0x7261702e202c6969,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x315a5f5f32666d72,0x6c616974696e6935,0x646972675f657a69\n"
".quad 0x702e202c69696950,0x33732e206d617261,0x616475635f5f2032,0x5f5f33666d726170\n"
".quad 0x6974696e6935315a,0x72675f657a696c61,0x0a29696969506469,0x6765722e090a7b09\n"
".quad 0x7225203233752e20,0x2e090a3b3e39333c,0x6572702e20676572,0x3b3e373c70252064\n"
".quad 0x3109636f6c2e090a,0x240a300939360938,0x6e6967656257444c,0x696e6935315a5f5f\n"
".quad 0x5f657a696c616974,0x6969695064697267,0x61702e646c090a3a,0x203233752e6d6172\n"
".quad 0x5f5b202c31722509,0x726170616475635f,0x35315a5f5f31666d,0x696c616974696e69\n"
".quad 0x50646972675f657a,0x6d090a3b5d696969,0x09203233732e766f,0x317225202c327225\n"
".quad 0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c33722509,0x726170616475635f\n"
".quad 0x35315a5f5f32666d,0x696c616974696e69,0x50646972675f657a,0x6d090a3b5d696969\n"
".quad 0x09203233732e766f,0x337225202c347225,0x61702e646c090a3b,0x203233752e6d6172\n"
".quad 0x5f5b202c35722509,0x726170616475635f,0x35315a5f5f33666d,0x696c616974696e69\n"
".quad 0x50646972675f657a,0x6d090a3b5d696969,0x09203233732e766f,0x357225202c367225\n"
".quad 0x732e726873090a3b,0x2c37722509203233,0x3031202c34722520,0x752e766f6d090a3b\n"
".quad 0x2c38722509203233,0x3b782e6469742520,0x33752e766f6d090a,0x202c397225092032\n"
".quad 0x70746573090a3b30,0x203233732e656c2e,0x7225202c31702509,0x0a3b397225202c37\n"
".quad 0x7262203170254009,0x335f744c24092061,0x090a3b323438335f,0x203233732e766f6d\n"
".quad 0x25202c3031722509,0x6c756d090a3b3772,0x203233752e6f6c2e,0x25202c3131722509\n"
".quad 0x090a3b34202c3872,0x203233732e646461,0x25202c3231722509,0x327225202c313172\n"
".quad 0x732e766f6d090a3b,0x3331722509203233,0x6f6d090a3b30202c,0x2509203233732e76\n"
".quad 0x317225202c343172,0x335f744c240a3b30,0x200a3a343533345f,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x7473656e202c3936,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x6f6c2e090a6e776f,0x0936370938310963,0x732e766f6d090a30,0x3531722509203233\n"
".quad 0x303334383631202c,0x6c6873090a3b3930,0x722509203233622e,0x33317225202c3631\n"
".quad 0x756d090a3b38202c,0x3233752e6f6c2e6c,0x202c373172250920,0x3b34202c36317225\n"
".quad 0x33732e646461090a,0x2c38317225092032,0x25202c3231722520,0x7473090a3b373172\n"
".quad 0x255b09203233732e,0x202c5d302b383172,0x61090a3b35317225,0x09203233732e6464\n"
".quad 0x7225202c33317225,0x090a3b31202c3331,0x2e656e2e70746573,0x3270250920323373\n"
".quad 0x25202c377225202c,0x2540090a3b333172,0x0920617262203270,0x33345f335f744c24\n"
".quad 0x5f744c240a3b3435,0x0a3a323438335f33,0x3233622e6c687309,0x202c393172250920\n"
".quad 0x0a3b38202c377225,0x3233732e72687309,0x202c303272250920,0x0a3b32202c347225\n"
".quad 0x3233732e62757309,0x202c313272250920,0x7225202c30327225,0x746573090a3b3931\n"
".quad 0x3233752e65672e70,0x25202c3370250920,0x31327225202c3872,0x2033702540090a3b\n"
".quad 0x744c240920617262,0x3b363638345f335f,0x3109636f6c2e090a,0x090a300931380938\n"
".quad 0x203233732e766f6d,0x31202c3232722509,0x3b39303033343836,0x33752e646461090a\n"
".quad 0x2c33327225092032,0x25202c3931722520,0x6c756d090a3b3872,0x203233752e6f6c2e\n"
".quad 0x25202c3432722509,0x0a3b34202c333272,0x3233752e64646109,0x202c353272250920\n"
".quad 0x327225202c327225,0x732e7473090a3b34,0x3272255b09203233,0x7225202c5d302b35\n"
".quad 0x5f744c240a3b3232,0x0a3a363638345f33,0x383109636f6c2e09,0x6d090a3009343809\n"
".quad 0x09203233752e766f,0x3b30202c36327225,0x6e2e70746573090a,0x2509203233752e65\n"
".quad 0x2c387225202c3470,0x090a3b3632722520,0x6172622034702540,0x5f335f744c240920\n"
".quad 0x2e090a3b38373335,0x3509373109636f6c,0x747663090a300936,0x6465726168732e61\n"
".quad 0x722509203233752e,0x0a3b746d202c3732,0x3233752e766f6d09,0x202c383272250920\n"
".quad 0x782e646961746325,0x752e646461090a3b,0x3932722509203233,0x25202c367225202c\n"
".quad 0x7473090a3b383272,0x2e6465726168732e,0x746d5b0920323375,0x327225202c5d302b\n"
".quad 0x2e646461090a3b39,0x3372250920323375,0x2c37327225202c30,0x646461090a3b3420\n"
".quad 0x722509203233752e,0x37327225202c3133,0x0a3b36393432202c,0x3233732e766f6d09\n"
".quad 0x202c323372250920,0x335f744c240a3b31,0x200a3a323034365f,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x7473656e202c3635,0x7470656420676e69\n"
".quad 0x7469202c31203a68,0x736e6f6974617265,0x2e090a333236203a,0x3509373109636f6c\n"
".quad 0x2e646c090a300939,0x3372250920323375,0x303372255b202c33,0x73090a3b5d342d2b\n"
".quad 0x09203233752e7268,0x7225202c34337225,0x0a3b3033202c3333,0x3233622e726f7809\n"
".quad 0x202c353372250920,0x7225202c33337225,0x6c756d090a3b3433,0x203233752e6f6c2e\n"
".quad 0x25202c3633722509,0x313831202c353372,0x3b33353233333432,0x33752e646461090a\n"
".quad 0x2c37337225092032,0x25202c3233722520,0x7473090a3b363372,0x255b09203233752e\n"
".quad 0x202c5d302b303372,0x61090a3b37337225,0x09203233732e6464,0x7225202c32337225\n"
".quad 0x090a3b31202c3233,0x203233752e646461,0x25202c3033722509,0x0a3b34202c303372\n"
".quad 0x656e2e7074657309,0x702509203233752e,0x2c30337225202c35,0x090a3b3133722520\n"
".quad 0x6172622035702540,0x5f335f744c240920,0x4c240a3b32303436,0x383733355f335f74\n"
".quad 0x09636f6c2e090a3a,0x0a30093538093831,0x4c240a3b74657209,0x5a5f5f646e655744\n"
".quad 0x616974696e693531,0x6972675f657a696c,0x090a3a6969695064,0x315a5f202f2f207d\n"
".quad 0x6c616974696e6935,0x646972675f657a69,0x2e090a0a69696950,0x20656c6269736976\n"
".quad 0x5a5f20636e75662e,0x72745f6e75723431,0x79726f7463656a61,0x702e282069696950\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x5f5f31666d726170,0x745f6e757234315a\n"
".quad 0x726f7463656a6172,0x2e202c6969695079,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5f32666d72617061,0x5f6e757234315a5f,0x6f7463656a617274,0x202c696969507972\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x33666d7261706164,0x6e757234315a5f5f\n"
".quad 0x7463656a6172745f,0x296969695079726f,0x65722e090a7b090a,0x25203233752e2067\n"
".quad 0x0a3b3e3835333c72,0x702e206765722e09,0x343c702520646572,0x202f2f090a3b3e30\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x375f37323331335f,0x6e6f635f6e6f6e5f\n"
".quad 0x20316c61765f7473,0x202f2f090a34203d,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x315f37323331335f,0x6f635f6e6f6e5f33,0x326c61765f74736e,0x2f2f090a38203d20\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f37323331335f72,0x635f6e6f6e5f3931\n"
".quad 0x6c61765f74736e6f,0x090a3231203d2033,0x6475635f5f202f2f,0x5f6c61636f6c5f61\n"
".quad 0x323331335f726176,0x5f6e6f6e5f375f38,0x616d5f74736e6f63,0x3631203d20316b72\n"
".quad 0x635f5f202f2f090a,0x61636f6c5f616475,0x31335f7261765f6c,0x6e5f34315f383233\n"
".quad 0x74736e6f635f6e6f,0x3d20326b72616d5f,0x202f2f090a303220,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x315f32303231335f,0x6f635f6e6f6e5f30,0x203d20795f74736e\n"
".quad 0x09636f6c2e090a30,0x0a30093938093831,0x6967656257444c24,0x757234315a5f5f6e\n"
".quad 0x63656a6172745f6e,0x6969695079726f74,0x61702e646c090a3a,0x203233752e6d6172\n"
".quad 0x5f5b202c31722509,0x726170616475635f,0x34315a5f5f31666d,0x6a6172745f6e7572\n"
".quad 0x695079726f746365,0x6f6d090a3b5d6969,0x2509203233732e76,0x3b317225202c3272\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5f5b202c337225,0x6d72617061647563\n"
".quad 0x7234315a5f5f3266,0x656a6172745f6e75,0x69695079726f7463,0x766f6d090a3b5d69\n"
".quad 0x722509203233732e,0x0a3b337225202c34,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x635f5f5b202c3572,0x666d726170616475,0x757234315a5f5f33,0x63656a6172745f6e\n"
".quad 0x6969695079726f74,0x2e766f6d090a3b5d,0x3672250920323373,0x090a3b357225202c\n"
".quad 0x203233752e766f6d,0x3b30202c37722509,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x2c367225202c3170,0x40090a3b37722520,0x2061726220317025,0x345f345f744c2409\n"
".quad 0x61090a3b30353430,0x09203233732e6464,0x347225202c387225,0x090a3b347225202c\n"
".quad 0x732e6f6c2e6c756d,0x2c39722509203233,0x7225202c38722520,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x202c367225202c30,0x6f6d090a3b313133,0x2509203233732e76\n"
".quad 0x35312d202c313172,0x3133313338373134,0x732e766f6d090a3b,0x3231722509203233\n"
".quad 0x6573090a3b30202c,0x33732e746c2e7074,0x202c327025092032,0x7225202c30317225\n"
".quad 0x736261090a3b3231,0x722509203233732e,0x30317225202c3331,0x682e6c756d090a3b\n"
".quad 0x2509203233752e69,0x317225202c343172,0x3b31317225202c33,0x33752e627573090a\n"
".quad 0x2c35317225092032,0x25202c3331722520,0x6873090a3b343172,0x2509203233752e72\n"
".quad 0x317225202c363172,0x61090a3b31202c35,0x09203233752e6464,0x7225202c37317225\n"
".quad 0x34317225202c3631,0x732e726873090a3b,0x3831722509203233,0x202c37317225202c\n"
".quad 0x32702540090a3b38,0x3233732e62757320,0x202c383172250920,0x7225202c32317225\n"
".quad 0x766f6d090a3b3831,0x722509203233732e,0x38317225202c3931,0x752e766f6d090a3b\n"
".quad 0x3032722509203233,0x782e64697425202c,0x752e766f6d090a3b,0x3132722509203233\n"
".quad 0x090a3b363232202c,0x2e656c2e70746573,0x3370250920323375,0x202c30327225202c\n"
".quad 0x61090a3b31327225,0x09203233732e6464,0x7225202c32327225,0x3b343534202c3032\n"
".quad 0x33752e766f6d090a,0x2c33327225092032,0x746573090a3b3020,0x3233752e71652e70\n"
".quad 0x25202c3470250920,0x327225202c303272,0x2e6c756d090a3b33,0x09203233752e6f6c\n"
".quad 0x7225202c34327225,0x090a3b34202c3032,0x203233752e766f6d,0x32202c3532722509\n"
".quad 0x746573090a3b3635,0x3233752e746c2e70,0x25202c3570250920,0x327225202c303272\n"
".quad 0x2e766f6d090a3b35,0x3272250920323375,0x0a3b313131202c36,0x656c2e7074657309\n"
".quad 0x702509203233752e,0x2c30327225202c36,0x090a3b3632722520,0x203233752e766f6d\n"
".quad 0x31202c3732722509,0x746573090a3b3231,0x3233752e746c2e70,0x25202c3770250920\n"
".quad 0x327225202c303272,0x2e766f6d090a3b37,0x3272250920323373,0x0a3b323236202c38\n"
".quad 0x656c2e7074657309,0x702509203233732e,0x2c32327225202c38,0x090a3b3832722520\n"
".quad 0x6168732e61747663,0x203233752e646572,0x6d202c3932722509,0x2e646461090a3b74\n"
".quad 0x3372250920323375,0x2c34327225202c30,0x090a3b3932722520,0x203233732e766f6d\n"
".quad 0x30202c3133722509,0x732e766f6d090a3b,0x3233722509203233,0x0a3b39317225202c\n"
".quad 0x30345f345f744c24,0x2f2f200a3a323639,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x393820656e696c20,0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120\n"
".quad 0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e\n"
".quad 0x0a30093739093831,0x6220337025214009,0x5f744c2409206172,0x3b38313231345f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39382065,0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f\n"
".quad 0x09373109636f6c2e,0x646c090a30093637,0x722509203233752e,0x3372255b202c3333\n"
".quad 0x61090a3b5d302b30,0x09203233622e646e,0x7225202c34337225,0x3431322d202c3333\n"
".quad 0x3b38343633383437,0x3233752e646c090a,0x202c353372250920,0x5d342b303372255b\n"
".quad 0x622e646e61090a3b,0x3633722509203233,0x202c35337225202c,0x3633383437343132\n"
".quad 0x2e726f090a3b3734,0x3372250920323362,0x2c34337225202c37,0x090a3b3633722520\n"
".quad 0x09373109636f6c2e,0x646c090a30093737,0x722509203233752e,0x3372255b202c3833\n"
".quad 0x3b5d383835312b30,0x33752e726873090a,0x2c39337225092032,0x31202c3733722520\n"
".quad 0x622e726f78090a3b,0x3034722509203233,0x202c38337225202c,0x78090a3b39337225\n"
".quad 0x09203233622e726f,0x7225202c31347225,0x3237312d202c3034,0x3b31383633383437\n"
".quad 0x33622e646e61090a,0x2c32347225092032,0x31202c3733722520,0x732e67656e090a3b\n"
".quad 0x3334722509203233,0x0a3b32347225202c,0x33752e74636c7309,0x2509203233732e32\n"
".quad 0x347225202c343472,0x2c31347225202c30,0x090a3b3334722520,0x203233732e766f6d\n"
".quad 0x25202c3534722509,0x744c240a3b343472,0x38313231345f345f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f34,0x373109636f6c2e09\n"
".quad 0x62090a3009393709,0x20636e79732e7261,0x252140090a3b3009,0x0920617262203370\n"
".quad 0x31345f345f744c24,0x2f2f200a3b303337,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3930345f345f744c,0x636f6c2e090a3236,0x3009323809373109,0x33732e766f6d090a\n"
".quad 0x2c36347225092032,0x090a3b3534722520,0x09203233752e7473,0x5d302b303372255b\n"
".quad 0x0a3b36347225202c,0x31345f345f744c24,0x2f2f200a3a303337,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f345f744c,0x636f6c2e090a3236,0x3009343809373109\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x7262203370252140,0x345f744c24092061\n"
".quad 0x0a3b32343232345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x2e090a3236393034,0x3909373109636f6c,0x2e646c090a300930,0x3472250920323375\n"
".quad 0x303372255b202c37,0x090a3b5d3830392b,0x203233622e646e61,0x25202c3834722509\n"
".quad 0x31322d202c373472,0x3834363338343734,0x33752e646c090a3b,0x2c39347225092032\n"
".quad 0x392b303372255b20,0x6e61090a3b5d3231,0x2509203233622e64,0x347225202c303572\n"
".quad 0x3437343132202c39,0x090a3b3734363338,0x09203233622e726f,0x7225202c37337225\n"
".quad 0x30357225202c3834,0x09636f6c2e090a3b,0x0a30093139093731,0x203233752e646c09\n"
".quad 0x5b202c3135722509,0x3b5d302b30337225,0x33752e726873090a,0x2c32357225092032\n"
".quad 0x31202c3733722520,0x622e726f78090a3b,0x3335722509203233,0x202c31357225202c\n"
".quad 0x78090a3b32357225,0x09203233622e726f,0x7225202c34357225,0x3237312d202c3335\n"
".quad 0x3b31383633383437,0x33622e646e61090a,0x2c35357225092032,0x31202c3733722520\n"
".quad 0x732e67656e090a3b,0x3635722509203233,0x0a3b35357225202c,0x33752e74636c7309\n"
".quad 0x2509203233732e32,0x357225202c373572,0x2c34357225202c33,0x090a3b3635722520\n"
".quad 0x203233732e766f6d,0x25202c3534722509,0x744c240a3b373572,0x32343232345f345f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c393820656e,0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f34\n"
".quad 0x373109636f6c2e09,0x62090a3009333909,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x0920617262203370,0x32345f345f744c24,0x2f2f200a3b343537,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f345f744c,0x636f6c2e090a3236,0x3009363909373109\n"
".quad 0x33732e766f6d090a,0x2c38357225092032,0x090a3b3534722520,0x09203233752e7473\n"
".quad 0x30392b303372255b,0x38357225202c5d38,0x5f345f744c240a3b,0x200a3a3435373234\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3938,0x64656c6562616c20,0x345f345f744c2420,0x6c2e090a32363930\n"
".quad 0x383909373109636f,0x2e726162090a3009,0x3b300920636e7973,0x203870252140090a\n"
".quad 0x744c240920617262,0x36363233345f345f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363930345f34,0x373109636f6c2e09,0x090a300934303109\n"
".quad 0x09203233752e646c,0x255b202c39357225,0x363138312b303372,0x2e646e61090a3b5d\n"
".quad 0x3672250920323362,0x2c39357225202c30,0x3834373431322d20,0x6c090a3b38343633\n"
".quad 0x2509203233752e64,0x72255b202c313672,0x5d303238312b3033,0x622e646e61090a3b\n"
".quad 0x3236722509203233,0x202c31367225202c,0x3633383437343132,0x2e726f090a3b3734\n"
".quad 0x3372250920323362,0x2c30367225202c37,0x090a3b3236722520,0x09373109636f6c2e\n"
".quad 0x6c090a3009353031,0x2509203233752e64,0x72255b202c333672,0x3b5d3830392b3033\n"
".quad 0x33752e726873090a,0x2c34367225092032,0x31202c3733722520,0x622e726f78090a3b\n"
".quad 0x3536722509203233,0x202c33367225202c,0x78090a3b34367225,0x09203233622e726f\n"
".quad 0x7225202c36367225,0x3237312d202c3536,0x3b31383633383437,0x33622e646e61090a\n"
".quad 0x2c37367225092032,0x31202c3733722520,0x732e67656e090a3b,0x3836722509203233\n"
".quad 0x0a3b37367225202c,0x33752e74636c7309,0x2509203233732e32,0x367225202c393672\n"
".quad 0x2c36367225202c35,0x090a3b3836722520,0x203233732e766f6d,0x25202c3534722509\n"
".quad 0x744c240a3b393672,0x36363233345f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363930345f34,0x373109636f6c2e09,0x090a300937303109\n"
".quad 0x636e79732e726162,0x2140090a3b300920,0x2061726220387025,0x345f345f744c2409\n"
".quad 0x2f200a3b38373733,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24\n"
".quad 0x6f6c2e090a323639,0x3031310937310963,0x2e766f6d090a3009,0x3772250920323373\n"
".quad 0x3b35347225202c30,0x3233752e7473090a,0x2b303372255b0920,0x25202c5d36313831\n"
".quad 0x744c240a3b303772,0x38373733345f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363930345f34,0x373109636f6c2e09,0x090a300932313109\n"
".quad 0x636e79732e726162,0x2140090a3b300920,0x2061726220347025,0x345f345f744c2409\n"
".quad 0x2f200a3b36343534,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24\n"
".quad 0x6f6c2e090a323639,0x3731310937310963,0x732e646c090a3009,0x33752e6465726168\n"
".quad 0x2c31377225092032,0x3b5d302b746d5b20,0x33622e646e61090a,0x2c32377225092032\n"
".quad 0x32202c3137722520,0x3436333834373431,0x732e646c090a3b37,0x33752e6465726168\n"
".quad 0x2c33377225092032,0x3934322b746d5b20,0x646e61090a3b5d32,0x722509203233622e\n"
".quad 0x33377225202c3437,0x34373431322d202c,0x090a3b3834363338,0x09203233622e726f\n"
".quad 0x7225202c35377225,0x34377225202c3237,0x732e766f6d090a3b,0x3733722509203233\n"
".quad 0x0a3b35377225202c,0x373109636f6c2e09,0x090a300938313109,0x203233752e726873\n"
".quad 0x25202c3637722509,0x0a3b31202c353772,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x6d5b202c37377225,0x3b5d343835312b74,0x33622e726f78090a,0x2c38377225092032\n"
".quad 0x25202c3637722520,0x6f78090a3b373772,0x2509203233622e72,0x377225202c393772\n"
".quad 0x373237312d202c38,0x0a3b313836333834,0x3233622e646e6109,0x202c303872250920\n"
".quad 0x3b31202c35377225,0x33732e67656e090a,0x2c31387225092032,0x090a3b3038722520\n"
".quad 0x3233752e74636c73,0x722509203233732e,0x38377225202c3238,0x202c39377225202c\n"
".quad 0x73090a3b31387225,0x6465726168732e74,0x6d5b09203233752e,0x2c5d323934322b74\n"
".quad 0x090a3b3238722520,0x20696e752e617262,0x345f345f744c2409,0x4c240a3b30393234\n"
".quad 0x343534345f345f74,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c393820656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32363930345f345f,0x33732e766f6d090a,0x2c37337225092032,0x240a3b3534722520\n"
".quad 0x3234345f345f744c,0x3c2f2f200a3a3039,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363930345f345f74,0x09636f6c2e090a32,0x3009303231093731,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x09373109636f6c2e,0x73090a3009363231,0x09203233752e7268\n"
".quad 0x7225202c33387225,0x0a3b3131202c3733,0x3233622e726f7809,0x202c343872250920\n"
".quad 0x7225202c33387225,0x6c6873090a3b3733,0x722509203233622e,0x34387225202c3538\n"
".quad 0x6e61090a3b37202c,0x2509203233622e64,0x387225202c363872,0x383536312d202c35\n"
".quad 0x0a3b363536383330,0x3233622e726f7809,0x202c373872250920,0x7225202c34387225\n"
".quad 0x6c6873090a3b3638,0x722509203233622e,0x37387225202c3838,0x61090a3b3531202c\n"
".quad 0x09203233622e646e,0x7225202c39387225,0x3237322d202c3838,0x0a3b343435363332\n"
".quad 0x3233622e726f7809,0x202c303972250920,0x7225202c37387225,0x726873090a3b3938\n"
".quad 0x722509203233752e,0x30397225202c3139,0x78090a3b3831202c,0x09203233622e726f\n"
".quad 0x7225202c32397225,0x31397225202c3039,0x732e766f6d090a3b,0x3534722509203233\n"
".quad 0x0a3b32397225202c,0x383109636f6c2e09,0x090a300930303109,0x09203233752e646c\n"
".quad 0x255b202c33397225,0x0a3b5d302b303372,0x3233752e6d657209,0x202c343972250920\n"
".quad 0x7225202c33397225,0x636f6c2e090a3b39,0x0931303109383109,0x3570252140090a30\n"
".quad 0x4c24092061726220,0x353035345f345f74,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393820656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363930345f345f,0x3109636f6c2e090a,0x090a300938320938\n"
".quad 0x203233732e766964,0x25202c3539722509,0x347225202c343972,0x732e627573090a3b\n"
".quad 0x3639722509203233,0x31202c387225202c,0x732e766f6d090a3b,0x3739722509203233\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x202c397025092032,0x7225202c35397225\n"
".quad 0x627573090a3b3739,0x722509203233732e,0x35397225202c3839,0x6573090a3b31202c\n"
".quad 0x09203233732e706c,0x7225202c39397225,0x38397225202c3639,0x090a3b397025202c\n"
".quad 0x203233732e766f6d,0x202c303031722509,0x72090a3b39397225,0x09203233732e6d65\n"
".quad 0x25202c3130317225,0x347225202c343972,0x622e646e61090a3b,0x3031722509203233\n"
".quad 0x2c35397225202c32,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c333031\n"
".quad 0x71652e7074657309,0x702509203233732e,0x30317225202c3031,0x3330317225202c32\n"
".quad 0x3031702540090a3b,0x4c24092061726220,0x373535345f345f74,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393820656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363930345f345f,0x3109636f6c2e090a\n"
".quad 0x090a300939320938,0x203233732e646461,0x202c343031722509,0x31202c3130317225\n"
".quad 0x732e766f6d090a3b,0x3031722509203233,0x73090a3b30202c35,0x09203233732e6275\n"
".quad 0x25202c3630317225,0x090a3b31202c3472,0x2e656e2e70746573,0x3170250920323373\n"
".quad 0x3130317225202c31,0x3b3630317225202c,0x732e706c6573090a,0x3031722509203233\n"
".quad 0x3430317225202c37,0x2c3530317225202c,0x090a3b3131702520,0x20696e752e617262\n"
".quad 0x345f345f744c2409,0x4c240a3b34313335,0x373535345f345f74,0x6c3c2f2f200a3a30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393820656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363930345f345f,0x33732e766f6d090a\n"
".quad 0x3730317225092032,0x3b3130317225202c,0x345f345f744c240a,0x2f200a3a34313335\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24,0x766f6d090a323639\n"
".quad 0x722509203233732e,0x317225202c383031,0x6f6c2e090a3b3730,0x0930330938310963\n"
".quad 0x732e646461090a30,0x3031722509203233,0x2c35397225202c39,0x766f6d090a3b3120\n"
".quad 0x722509203233732e,0x0a3b30202c303131,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x36397225202c3231,0x0a3b35397225202c,0x33732e706c657309,0x3131317225092032\n"
".quad 0x2c3930317225202c,0x202c303131722520,0x6d090a3b32317025,0x09203233732e766f\n"
".quad 0x25202c3231317225,0x2e090a3b31313172,0x3309383109636f6c,0x6c756d090a300931\n"
".quad 0x203233732e6f6c2e,0x202c333131722509,0x7225202c39397225,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x30317225202c3431,0x3331317225202c37,0x752e646461090a3b\n"
".quad 0x3131722509203233,0x202c327225202c35,0x090a3b3431317225,0x25092038732e646c\n"
".quad 0x255b202c36313172,0x3b5d302b35313172,0x33732e766f6d090a,0x3731317225092032\n"
".quad 0x3b3631317225202c,0x3109636f6c2e090a,0x090a300932330938,0x732e6f6c2e6c756d\n"
".quad 0x3131722509203233,0x2c35397225202c38,0x61090a3b34722520,0x09203233732e6464\n"
".quad 0x25202c3931317225,0x7225202c38313172,0x6461090a3b313031,0x2509203233752e64\n"
".quad 0x7225202c30323172,0x327225202c393131,0x38732e646c090a3b,0x2c31323172250920\n"
".quad 0x2b30323172255b20,0x766f6d090a3b5d30,0x722509203233732e,0x317225202c323231\n"
".quad 0x766f6d090a3b3132,0x722509203233732e,0x0a3b30202c333231,0x2e74672e74657309\n"
".quad 0x203233732e323375,0x202c343231722509,0x25202c3132317225,0x6e090a3b33323172\n"
".quad 0x09203233732e6765,0x25202c3532317225,0x6d090a3b34323172,0x09203233732e766f\n"
".quad 0x30202c3632317225,0x672e746573090a3b,0x33732e3233752e74,0x3732317225092032\n"
".quad 0x2c3631317225202c,0x0a3b363231722520,0x3233732e67656e09,0x2c38323172250920\n"
".quad 0x0a3b373231722520,0x3233622e646e6109,0x2c39323172250920,0x202c353231722520\n"
".quad 0x090a3b3832317225,0x203233752e766f6d,0x202c303331722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3331702509,0x7225202c39323172,0x2540090a3b303331\n"
".quad 0x2061726220333170,0x345f345f744c2409,0x2f200a3b32383036,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x30345f345f744c24,0x6f6c2e090a323639,0x0936330938310963\n"
".quad 0x732e646461090a30,0x3331722509203233,0x2c31337225202c31,0x726873090a3b3720\n"
".quad 0x722509203233732e,0x397225202c323331,0x756d090a3b32202c,0x3233752e6f6c2e6c\n"
".quad 0x2c33333172250920,0x202c323331722520,0x2e646461090a3b34,0x3172250920323375\n"
".quad 0x2c327225202c3433,0x0a3b333331722520,0x2e6f6c2e6c756d09,0x3172250920323375\n"
".quad 0x31317225202c3533,0x61090a3b34202c39,0x09203233752e6464,0x25202c3633317225\n"
".quad 0x7225202c34333172,0x7473090a3b353331,0x255b09203233732e,0x2c5d302b36333172\n"
".quad 0x0a3b313331722520,0x3233732e766f6d09,0x2c37333172250920,0x617262090a3b3120\n"
".quad 0x4c240920696e752e,0x303834345f345f74,0x345f744c240a3b32,0x0a3a32383036345f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064,0x6d090a3236393034\n"
".quad 0x09203233732e766f,0x30202c3733317225,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b32303834345f34,0x345f345f744c240a,0x2f200a3a38353035,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x30345f345f744c24,0x766f6d090a323639,0x722509203233732e\n"
".quad 0x0a3b30202c373331,0x34345f345f744c24,0x2f2f200a3a323038,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f345f744c,0x636f6c2e090a3236,0x3009393309383109\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x203233732e766f6d,0x202c383331722509\n"
".quad 0x70746573090a3b30,0x203233732e656e2e,0x25202c3431702509,0x7225202c37333172\n"
".quad 0x2140090a3b383331,0x6172622034317025,0x5f345f744c240920,0x200a3b3833333634\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3938,0x64656c6562616c20,0x345f345f744c2420,0x6c2e090a32363930\n"
".quad 0x353409383109636f,0x2e646461090a3009,0x3172250920323373,0x31337225202c3933\n"
".quad 0x6e61090a3b37202c,0x2509203233622e64,0x7225202c30343172,0x0a3b31202c393331\n"
".quad 0x3233732e76696409,0x2c31343172250920,0x25202c3439722520,0x646e61090a3b3472\n"
".quad 0x722509203233622e,0x317225202c323431,0x090a3b31202c3134,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x3034317225202c35,0x3b3234317225202c,0x203531702540090a\n"
".quad 0x744c240920617262,0x3b383132395f345f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c39382065,0x6c6562616c206461\n"
".quad 0x345f744c24206465,0x090a32363930345f,0x203233732e726873,0x202c333431722509\n"
".quad 0x0a3b32202c397225,0x2e6f6c2e6c756d09,0x3172250920323375,0x34317225202c3434\n"
".quad 0x61090a3b34202c33,0x09203233752e6464,0x25202c3534317225,0x7225202c34343172\n"
".quad 0x2e766f6d090a3b32,0x3172250920323373,0x30317225202c3634,0x2e766f6d090a3b38\n"
".quad 0x3172250920323373,0x30317225202c3734,0x2e6c756d090a3b30,0x09203233732e6f6c\n"
".quad 0x25202c3834317225,0x7225202c37343172,0x2e646461090a3b34,0x3172250920323373\n"
".quad 0x34317225202c3934,0x3834317225202c36,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c30353172,0x0a3b34202c393431,0x3233752e64646109,0x2c31353172250920\n"
".quad 0x202c353431722520,0x090a3b3035317225,0x09203233732e646c,0x5b202c3235317225\n"
".quad 0x5d302b3135317225,0x2e70746573090a3b,0x09203233732e7165,0x7225202c36317025\n"
".quad 0x317225202c323531,0x702540090a3b3933,0x0920617262203631,0x35355f345f744c24\n"
".quad 0x2f2f200a3b383932,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x393820656e696c20,0x6c2064616568202c,0x242064656c656261,0x3930345f345f744c\n"
".quad 0x2e766f6d090a3236,0x3172250920323373,0x31317225202c3335,0x2e6c756d090a3b32\n"
".quad 0x09203233732e6f6c,0x25202c3435317225,0x7225202c33353172,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x35317225202c3535,0x0a3b347225202c34,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x35317225202c3635,0x73090a3b34202c35,0x09203233752e6275\n"
".quad 0x25202c3735317225,0x3b34202c36353172,0x33732e646461090a,0x3835317225092032\n"
".quad 0x2c3435317225202c,0x0a3b363431722520,0x2e6f6c2e6c756d09,0x3172250920323375\n"
".quad 0x35317225202c3935,0x73090a3b34202c38,0x09203233752e6275,0x25202c3036317225\n"
".quad 0x3b34202c39353172,0x33732e766f6d090a,0x3136317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c37317025092032,0x202c363431722520,0x090a3b3136317225\n"
".quad 0x3233752e706c6573,0x2c32363172250920,0x202c373531722520,0x25202c3036317225\n"
".quad 0x6461090a3b373170,0x2509203233752e64,0x7225202c33363172,0x317225202c323631\n"
".quad 0x2e646c090a3b3534,0x3172250920323373,0x3172255b202c3436,0x090a3b5d302b3336\n"
".quad 0x2e71652e70746573,0x3170250920323373,0x3436317225202c38,0x3b3933317225202c\n"
".quad 0x203831702540090a,0x744c240920617262,0x38393235355f345f,0x5f345f744c240a3b\n"
".quad 0x2f200a3a38313239,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24\n"
".quad 0x766f6d090a323639,0x722509203233732e,0x0a3b31202c353631,0x696e752e61726209\n"
".quad 0x5f345f744c240920,0x240a3b3435373031,0x3235355f345f744c,0x5f744c240a3a3839\n"
".quad 0x0a3a343734395f34,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x6d090a3236393034,0x09203233732e766f,0x30202c3536317225,0x5f345f744c240a3b\n"
".quad 0x200a3a3435373031,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3938,0x64656c6562616c20,0x345f345f744c2420\n"
".quad 0x6f6d090a32363930,0x2509203233732e76,0x3b30202c36363172,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x317225202c343170,0x36317225202c3536,0x345f744c240a3b36\n"
".quad 0x0a3a38333336345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x40090a3236393034,0x7262203431702521,0x345f744c24092061,0x0a3b30353836345f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064,0x2e090a3236393034\n"
".quad 0x3509383109636f6c,0x766f6d090a300934,0x722509203233732e,0x317225202c373631\n"
".quad 0x627573090a3b3731,0x722509203233732e,0x317225202c383631,0x090a3b31202c3736\n"
".quad 0x203233732e766f6d,0x202c393631722509,0x090a3b3830317225,0x203233732e766f6d\n"
".quad 0x202c303731722509,0x090a3b3030317225,0x732e6f6c2e6c756d,0x3731722509203233\n"
".quad 0x3037317225202c31,0x090a3b347225202c,0x203233732e646461,0x202c323731722509\n"
".quad 0x25202c3936317225,0x61090a3b31373172,0x09203233752e6464,0x25202c3337317225\n"
".quad 0x37317225202c3272,0x732e7473090a3b32,0x373172255b092038,0x7225202c5d302b33\n"
".quad 0x6c2e090a3b383631,0x353509383109636f,0x2e766f6d090a3009,0x3172250920323373\n"
".quad 0x32317225202c3437,0x2e627573090a3b32,0x3172250920323373,0x37317225202c3537\n"
".quad 0x64090a3b31202c34,0x09203233732e7669,0x25202c3637317225,0x347225202c343972\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c37373172,0x3637317225202c34\n"
".quad 0x732e6d6572090a3b,0x3731722509203233,0x2c34397225202c38,0x61090a3b34722520\n"
".quad 0x09203233732e6464,0x25202c3937317225,0x7225202c37373172,0x6461090a3b383731\n"
".quad 0x2509203233752e64,0x7225202c30383172,0x3937317225202c32,0x38732e7473090a3b\n"
".quad 0x30383172255b0920,0x317225202c5d302b,0x5f744c240a3b3537,0x3a30353836345f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39382065,0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f\n"
".quad 0x09383109636f6c2e,0x6162090a30093735,0x0920636e79732e72,0x70252140090a3b30\n"
".quad 0x0920617262203431,0x37345f345f744c24,0x2f2f200a3b323633,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f345f744c,0x636f6c2e090a3236,0x3009303609383109\n"
".quad 0x33732e766f6d090a,0x3138317225092032,0x3b3231317225202c,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x317225202c323831,0x3b347225202c3138,0x33732e766f6d090a\n"
".quad 0x3338317225092032,0x3b3830317225202c,0x33732e646461090a,0x3438317225092032\n"
".quad 0x2c3338317225202c,0x0a3b323831722520,0x3233752e64646109,0x2c35383172250920\n"
".quad 0x202c343831722520,0x646c090a3b327225,0x317225092038732e,0x3172255b202c3638\n"
".quad 0x090a3b5d302b3538,0x203233732e646461,0x202c373831722509,0x31202c3638317225\n"
".quad 0x38732e7473090a3b,0x35383172255b0920,0x317225202c5d302b,0x6f6c2e090a3b3738\n"
".quad 0x0931360938310963,0x732e6d6572090a30,0x3031722509203233,0x2c34397225202c31\n"
".quad 0x73090a3b34722520,0x09203233732e6275,0x25202c3838317225,0x090a3b31202c3472\n"
".quad 0x203233732e766964,0x25202c3539722509,0x347225202c343972,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c39317025,0x317225202c383831,0x6c756d090a3b3130\n"
".quad 0x203233732e6f6c2e,0x202c393831722509,0x7225202c35397225,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x38317225202c3931,0x3130317225202c39,0x752e646461090a3b\n"
".quad 0x3931722509203233,0x3931317225202c30,0x6573090a3b31202c,0x09203233752e706c\n"
".quad 0x25202c3139317225,0x7225202c30393172,0x317025202c393831,0x2e646461090a3b39\n"
".quad 0x3172250920323375,0x39317225202c3239,0x0a3b327225202c31,0x092038732e646c09\n"
".quad 0x5b202c3339317225,0x5d302b3239317225,0x732e646461090a3b,0x3931722509203233\n"
".quad 0x3339317225202c34,0x7473090a3b31202c,0x72255b092038732e,0x202c5d302b323931\n"
".quad 0x240a3b3439317225,0x3337345f345f744c,0x3c2f2f200a3a3236,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363930345f345f74,0x09636f6c2e090a32,0x0a30093336093831\n"
".quad 0x6e79732e72616209,0x2e090a3b30092063,0x3109383109636f6c,0x646c090a30093530\n"
".quad 0x722509203233752e,0x72255b202c353931,0x5d343230312b3033,0x752e6d6572090a3b\n"
".quad 0x3439722509203233,0x2c3539317225202c,0x2e090a3b39722520,0x3109383109636f6c\n"
".quad 0x2140090a30093630,0x2061726220357025,0x345f345f744c2409,0x2f200a3b30333138\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24,0x6f6c2e090a323639\n"
".quad 0x0938320938310963,0x732e766964090a30,0x3931722509203233,0x2c34397225202c36\n"
".quad 0x73090a3b34722520,0x09203233732e6275,0x7225202c36397225,0x6d090a3b31202c38\n"
".quad 0x09203233732e766f,0x30202c3739317225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x317225202c397025,0x39317225202c3639,0x2e627573090a3b37,0x3972250920323373\n"
".quad 0x3639317225202c38,0x6573090a3b31202c,0x09203233732e706c,0x7225202c39397225\n"
".quad 0x38397225202c3639,0x090a3b397025202c,0x203233732e766f6d,0x202c303031722509\n"
".quad 0x72090a3b39397225,0x09203233732e6d65,0x25202c3839317225,0x347225202c343972\n"
".quad 0x622e646e61090a3b,0x3931722509203233,0x3639317225202c39,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x3b30202c30303272,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x317225202c303270,0x30327225202c3939,0x32702540090a3b30,0x2409206172622030\n"
".quad 0x3638345f345f744c,0x3c2f2f200a3b3234,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363930345f345f74,0x09636f6c2e090a32,0x0a30093932093831,0x3233732e64646109\n"
".quad 0x2c31303272250920,0x202c383931722520,0x2e766f6d090a3b31,0x3272250920323373\n"
".quad 0x090a3b30202c3230,0x203233732e627573,0x202c333032722509,0x0a3b31202c347225\n"
".quad 0x656e2e7074657309,0x702509203233732e,0x39317225202c3132,0x3330327225202c38\n"
".quad 0x2e706c6573090a3b,0x3272250920323373,0x30327225202c3430,0x3230327225202c31\n"
".quad 0x0a3b31327025202c,0x696e752e61726209,0x5f345f744c240920,0x240a3b3638333834\n"
".quad 0x3638345f345f744c,0x3c2f2f200a3a3234,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363930345f345f74,0x732e766f6d090a32,0x3032722509203233,0x3839317225202c34\n"
".quad 0x5f345f744c240a3b,0x200a3a3638333834,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3938,0x64656c6562616c20\n"
".quad 0x345f345f744c2420,0x6f6d090a32363930,0x2509203233732e76,0x7225202c38303172\n"
".quad 0x6c2e090a3b343032,0x303309383109636f,0x2e646461090a3009,0x3272250920323373\n"
".quad 0x39317225202c3530,0x6d090a3b31202c36,0x09203233732e766f,0x30202c3630327225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x7225202c32327025,0x397225202c363931\n"
".quad 0x706c6573090a3b36,0x722509203233732e,0x327225202c373032,0x30327225202c3530\n"
".quad 0x3b32327025202c36,0x33732e766f6d090a,0x3231317225092032,0x3b3730327225202c\n"
".quad 0x3109636f6c2e090a,0x090a300931330938,0x732e6f6c2e6c756d,0x3032722509203233\n"
".quad 0x2c39397225202c38,0x61090a3b34722520,0x09203233732e6464,0x25202c3930327225\n"
".quad 0x7225202c34303272,0x6461090a3b383032,0x2509203233752e64,0x7225202c30313272\n"
".quad 0x3930327225202c32,0x38732e646c090a3b,0x2c36313172250920,0x2b30313272255b20\n"
".quad 0x766f6d090a3b5d30,0x722509203233732e,0x317225202c373131,0x6f6c2e090a3b3631\n"
".quad 0x0932330938310963,0x6c2e6c756d090a30,0x2509203233732e6f,0x7225202c31313272\n"
".quad 0x347225202c363931,0x732e646461090a3b,0x3132722509203233,0x3131327225202c32\n"
".quad 0x3b3839317225202c,0x33752e646461090a,0x3331327225092032,0x2c3231327225202c\n"
".quad 0x6c090a3b32722520,0x7225092038732e64,0x72255b202c313231,0x0a3b5d302b333132\n"
".quad 0x3233732e766f6d09,0x2c32323172250920,0x0a3b313231722520,0x3233732e766f6d09\n"
".quad 0x2c34313272250920,0x746573090a3b3020,0x2e3233752e74672e,0x3272250920323373\n"
".quad 0x32317225202c3531,0x3431327225202c31,0x732e67656e090a3b,0x3132722509203233\n"
".quad 0x3531327225202c36,0x732e766f6d090a3b,0x3132722509203233,0x73090a3b30202c37\n"
".quad 0x33752e74672e7465,0x2509203233732e32,0x7225202c38313272,0x327225202c363131\n"
".quad 0x67656e090a3b3731,0x722509203233732e,0x327225202c393132,0x646e61090a3b3831\n"
".quad 0x722509203233622e,0x327225202c303232,0x31327225202c3631,0x2e766f6d090a3b39\n"
".quad 0x3272250920323375,0x090a3b30202c3132,0x2e71652e70746573,0x3270250920323373\n"
".quad 0x3032327225202c33,0x3b3132327225202c,0x203332702540090a,0x744c240920617262\n"
".quad 0x34353139345f345f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363930345f34,0x383109636f6c2e09,0x61090a3009363309,0x09203233732e6464\n"
".quad 0x25202c3232327225,0x3b3131202c313372,0x33732e726873090a,0x3332327225092032\n"
".quad 0x32202c397225202c,0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c34323272\n"
".quad 0x0a3b34202c333232,0x3233752e64646109,0x2c35323272250920,0x7225202c32722520\n"
".quad 0x756d090a3b343232,0x3233752e6f6c2e6c,0x2c36323272250920,0x202c323132722520\n"
".quad 0x2e646461090a3b34,0x3272250920323375,0x32327225202c3732,0x3632327225202c35\n"
".quad 0x33732e7473090a3b,0x323272255b092032,0x7225202c5d302b37,0x6f6d090a3b323232\n"
".quad 0x2509203233732e76,0x3b31202c37333172,0x6e752e617262090a,0x345f744c24092069\n"
".quad 0x0a3b34373837345f,0x39345f345f744c24,0x2f2f200a3a343531,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f345f744c,0x2e766f6d090a3236,0x3172250920323373\n"
".quad 0x090a3b30202c3733,0x20696e752e617262,0x345f345f744c2409,0x4c240a3b34373837\n"
".quad 0x333138345f345f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c393820656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32363930345f345f,0x33732e766f6d090a,0x3733317225092032,0x744c240a3b30202c\n"
".quad 0x34373837345f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363930345f34,0x383109636f6c2e09,0x62090a3009393309,0x20636e79732e7261\n"
".quad 0x766f6d090a3b3009,0x722509203233732e,0x0a3b30202c383232,0x656e2e7074657309\n"
".quad 0x702509203233732e,0x33317225202c3431,0x3832327225202c37,0x3170252140090a3b\n"
".quad 0x2409206172622034,0x3439345f345f744c,0x3c2f2f200a3b3031,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363930345f345f74,0x09636f6c2e090a32,0x0a30093534093831\n"
".quad 0x3233732e64646109,0x2c39323272250920,0x31202c3133722520,0x2e646e61090a3b31\n"
".quad 0x3272250920323362,0x32327225202c3033,0x64090a3b31202c39,0x09203233732e7669\n"
".quad 0x25202c3133327225,0x347225202c343972,0x622e646e61090a3b,0x3332722509203233\n"
".quad 0x3133327225202c32,0x6573090a3b31202c,0x33732e71652e7074,0x2c34327025092032\n"
".quad 0x202c303332722520,0x090a3b3233327225,0x7262203432702540,0x345f744c24092061\n"
".quad 0x0a3b36383336315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x73090a3236393034,0x09203233732e7268,0x25202c3334317225,0x090a3b32202c3972\n"
".quad 0x752e6f6c2e6c756d,0x3431722509203233,0x3334317225202c34,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x7225202c35343172,0x327225202c343431,0x732e766f6d090a3b\n"
".quad 0x3431722509203233,0x3830317225202c36,0x732e766f6d090a3b,0x3332722509203233\n"
".quad 0x3030317225202c33,0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c34333272\n"
".quad 0x347225202c333332,0x732e646461090a3b,0x3332722509203233,0x3634317225202c35\n"
".quad 0x3b3433327225202c,0x6f6c2e6c756d090a,0x722509203233752e,0x327225202c363332\n"
".quad 0x090a3b34202c3533,0x203233752e646461,0x202c373332722509,0x25202c3534317225\n"
".quad 0x6c090a3b36333272,0x2509203233732e64,0x255b202c38333272,0x3b5d302b37333272\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x327225202c353270,0x32327225202c3833\n"
".quad 0x32702540090a3b39,0x2409206172622035,0x3036355f345f744c,0x3c2f2f200a3b3636\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c393820656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363930345f345f74,0x732e766f6d090a32\n"
".quad 0x3332722509203233,0x3231317225202c39,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c30343272,0x347225202c393332,0x732e646461090a3b,0x3432722509203233\n"
".quad 0x3034327225202c31,0x090a3b347225202c,0x752e6f6c2e6c756d,0x3432722509203233\n"
".quad 0x3134327225202c32,0x7573090a3b34202c,0x2509203233752e62,0x7225202c33343272\n"
".quad 0x0a3b34202c323432,0x3233732e64646109,0x2c34343272250920,0x202c303432722520\n"
".quad 0x090a3b3634317225,0x752e6f6c2e6c756d,0x3432722509203233,0x3434327225202c35\n"
".quad 0x7573090a3b34202c,0x2509203233752e62,0x7225202c36343272,0x0a3b34202c353432\n"
".quad 0x3233732e766f6d09,0x2c37343272250920,0x746573090a3b3020,0x3233732e71652e70\n"
".quad 0x202c363270250920,0x25202c3634317225,0x73090a3b37343272,0x203233752e706c65\n"
".quad 0x202c383432722509,0x25202c3334327225,0x7025202c36343272,0x646461090a3b3632\n"
".quad 0x722509203233752e,0x327225202c393432,0x34317225202c3834,0x732e646c090a3b35\n"
".quad 0x3532722509203233,0x343272255b202c30,0x73090a3b5d302b39,0x732e71652e707465\n"
".quad 0x3732702509203233,0x2c3035327225202c,0x0a3b393232722520,0x6220373270254009\n"
".quad 0x5f744c2409206172,0x3b36363036355f34,0x315f345f744c240a,0x2f200a3a36383336\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24,0x766f6d090a323639\n"
".quad 0x722509203233732e,0x0a3b31202c313532,0x696e752e61726209,0x5f345f744c240920\n"
".quad 0x240a3b3232393731,0x3036355f345f744c,0x5f744c240a3a3636,0x3a32343636315f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39382065,0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f\n"
".quad 0x203233732e766f6d,0x202c313532722509,0x345f744c240a3b30,0x0a3a32323937315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064,0x6d090a3236393034\n"
".quad 0x09203233732e766f,0x30202c3235327225,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x7225202c34317025,0x327225202c313532,0x5f744c240a3b3235,0x3a30313439345f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39382065,0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f\n"
".quad 0x6220343170252140,0x5f744c2409206172,0x3b32323939345f34,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c39382065\n"
".quad 0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f,0x09383109636f6c2e\n"
".quad 0x6f6d090a30093435,0x2509203233732e76,0x7225202c33353272,0x7573090a3b373131\n"
".quad 0x2509203233732e62,0x7225202c34353272,0x0a3b31202c333532,0x3233732e766f6d09\n"
".quad 0x2c35353272250920,0x0a3b383031722520,0x3233732e766f6d09,0x2c36353272250920\n"
".quad 0x0a3b303031722520,0x2e6f6c2e6c756d09,0x3272250920323373,0x35327225202c3735\n"
".quad 0x0a3b347225202c36,0x3233732e64646109,0x2c38353272250920,0x202c353532722520\n"
".quad 0x090a3b3735327225,0x203233752e646461,0x202c393532722509,0x327225202c327225\n"
".quad 0x2e7473090a3b3835,0x3272255b09203873,0x25202c5d302b3935,0x2e090a3b34353272\n"
".quad 0x3509383109636f6c,0x766f6d090a300935,0x722509203233732e,0x317225202c303632\n"
".quad 0x627573090a3b3232,0x722509203233732e,0x327225202c313632,0x090a3b31202c3036\n"
".quad 0x203233732e766964,0x202c323632722509,0x7225202c34397225,0x2e6c756d090a3b34\n"
".quad 0x09203233732e6f6c,0x25202c3336327225,0x36327225202c3472,0x2e6d6572090a3b32\n"
".quad 0x3272250920323373,0x34397225202c3436,0x090a3b347225202c,0x203233732e646461\n"
".quad 0x202c353632722509,0x25202c3336327225,0x61090a3b34363272,0x09203233752e6464\n"
".quad 0x25202c3636327225,0x36327225202c3272,0x732e7473090a3b35,0x363272255b092038\n"
".quad 0x7225202c5d302b36,0x744c240a3b313632,0x32323939345f345f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f34,0x383109636f6c2e09\n"
".quad 0x62090a3009373509,0x20636e79732e7261,0x252140090a3b3009,0x2061726220343170\n"
".quad 0x355f345f744c2409,0x2f200a3b34333430,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3820656e696c2079,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x30345f345f744c24,0x6f6c2e090a323639,0x0930360938310963,0x732e766f6d090a30\n"
".quad 0x3632722509203233,0x3231317225202c37,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c38363272,0x347225202c373632,0x732e766f6d090a3b,0x3632722509203233\n"
".quad 0x3830317225202c39,0x732e646461090a3b,0x3732722509203233,0x3936327225202c30\n"
".quad 0x3b3836327225202c,0x33752e646461090a,0x3538317225092032,0x2c3037327225202c\n"
".quad 0x6c090a3b32722520,0x7225092038732e64,0x72255b202c313732,0x0a3b5d302b353831\n"
".quad 0x3233732e64646109,0x2c32373272250920,0x202c313732722520,0x732e7473090a3b31\n"
".quad 0x383172255b092038,0x7225202c5d302b35,0x6c2e090a3b323732,0x313609383109636f\n"
".quad 0x2e6d6572090a3009,0x3172250920323373,0x34397225202c3839,0x090a3b347225202c\n"
".quad 0x203233732e627573,0x202c383831722509,0x0a3b31202c347225,0x3233732e76696409\n"
".quad 0x2c36393172250920,0x25202c3439722520,0x746573090a3b3472,0x3233732e656e2e70\n"
".quad 0x202c383270250920,0x25202c3839317225,0x6d090a3b38383172,0x33732e6f6c2e6c75\n"
".quad 0x3337327225092032,0x2c3639317225202c,0x61090a3b34722520,0x09203233732e6464\n"
".quad 0x25202c3231327225,0x7225202c33373272,0x6461090a3b383931,0x2509203233752e64\n"
".quad 0x7225202c30393172,0x0a3b31202c323132,0x33752e706c657309,0x3139317225092032\n"
".quad 0x2c3039317225202c,0x202c333732722520,0x61090a3b38327025,0x09203233752e6464\n"
".quad 0x25202c3239317225,0x7225202c31393172,0x732e646c090a3b32,0x3437327225092038\n"
".quad 0x32393172255b202c,0x6461090a3b5d302b,0x2509203233732e64,0x7225202c35373272\n"
".quad 0x0a3b31202c343732,0x092038732e747309,0x302b32393172255b,0x3537327225202c5d\n"
".quad 0x5f345f744c240a3b,0x200a3a3433343035,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3938,0x64656c6562616c20\n"
".quad 0x345f345f744c2420,0x6c2e090a32363930,0x333609383109636f,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x3109636f6c2e090a,0x0a30093630310938,0x6220367025214009\n"
".quad 0x5f744c2409206172,0x3b36343930355f34,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c39382065,0x6c6562616c206461\n"
".quad 0x345f744c24206465,0x090a32363930345f,0x09383109636f6c2e,0x6c090a3009323131\n"
".quad 0x2509203233752e64,0x255b202c36373272,0x383430322b303372,0x2e6d6572090a3b5d\n"
".quad 0x3972250920323375,0x3637327225202c34,0x240a3b397225202c,0x3930355f345f744c\n"
".quad 0x3c2f2f200a3a3634,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c393820656e696c,0x616c206461656820,0x4c242064656c6562,0x363930345f345f74\n"
".quad 0x09636f6c2e090a32,0x3009343131093831,0x203770252140090a,0x744c240920617262\n"
".quad 0x34313731355f345f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363930345f34,0x383109636f6c2e09,0x64090a3009383209,0x09203233732e7669\n"
".quad 0x25202c3737327225,0x347225202c343972,0x732e627573090a3b,0x3639722509203233\n"
".quad 0x31202c387225202c,0x732e766f6d090a3b,0x3732722509203233,0x73090a3b30202c38\n"
".quad 0x732e71652e707465,0x2c39702509203233,0x202c373732722520,0x090a3b3837327225\n"
".quad 0x203233732e627573,0x25202c3839722509,0x3b31202c37373272,0x732e706c6573090a\n"
".quad 0x3939722509203233,0x202c36397225202c,0x7025202c38397225,0x2e766f6d090a3b39\n"
".quad 0x3172250920323373,0x39397225202c3030,0x732e6d6572090a3b,0x3732722509203233\n"
".quad 0x2c34397225202c39,0x61090a3b34722520,0x09203233622e646e,0x25202c3038327225\n"
".quad 0x3b31202c37373272,0x33752e766f6d090a,0x3138327225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c39327025092032,0x202c303832722520,0x090a3b3138327225\n"
".quad 0x7262203932702540,0x345f744c24092061,0x0a3b36323232355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c393820\n"
".quad 0x656c6562616c2064,0x5f345f744c242064,0x2e090a3236393034,0x3209383109636f6c\n"
".quad 0x646461090a300939,0x722509203233732e,0x327225202c323832,0x090a3b31202c3937\n"
".quad 0x203233732e766f6d,0x202c333832722509,0x2e627573090a3b30,0x3272250920323373\n"
".quad 0x2c347225202c3438,0x746573090a3b3120,0x3233732e656e2e70,0x202c303370250920\n"
".quad 0x25202c3937327225,0x73090a3b34383272,0x203233732e706c65,0x202c353832722509\n"
".quad 0x25202c3238327225,0x7025202c33383272,0x617262090a3b3033,0x4c240920696e752e\n"
".quad 0x373931355f345f74,0x345f744c240a3b30,0x0a3a36323232355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c393820\n"
".quad 0x656c6562616c2064,0x5f345f744c242064,0x6d090a3236393034,0x09203233732e766f\n"
".quad 0x25202c3538327225,0x4c240a3b39373272,0x373931355f345f74,0x6c3c2f2f200a3a30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393820656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363930345f345f,0x33732e766f6d090a\n"
".quad 0x3830317225092032,0x3b3538327225202c,0x3109636f6c2e090a,0x090a300930330938\n"
".quad 0x203233732e646461,0x202c363832722509,0x31202c3737327225,0x732e766f6d090a3b\n"
".quad 0x3832722509203233,0x73090a3b30202c37,0x732e656e2e707465,0x3133702509203233\n"
".quad 0x2c3737327225202c,0x090a3b3639722520,0x3233732e706c6573,0x2c38383272250920\n"
".quad 0x202c363832722520,0x25202c3738327225,0x6f6d090a3b313370,0x2509203233732e76\n"
".quad 0x7225202c32313172,0x6c2e090a3b383832,0x313309383109636f,0x2e6c756d090a3009\n"
".quad 0x09203233732e6f6c,0x25202c3938327225,0x347225202c393972,0x732e646461090a3b\n"
".quad 0x3932722509203233,0x3538327225202c30,0x3b3938327225202c,0x33752e646461090a\n"
".quad 0x3139327225092032,0x25202c327225202c,0x6c090a3b30393272,0x7225092038732e64\n"
".quad 0x72255b202c363131,0x0a3b5d302b313932,0x3233732e766f6d09,0x2c37313172250920\n"
".quad 0x0a3b363131722520,0x383109636f6c2e09,0x6d090a3009323309,0x33732e6f6c2e6c75\n"
".quad 0x3239327225092032,0x2c3737327225202c,0x61090a3b34722520,0x09203233732e6464\n"
".quad 0x25202c3339327225,0x7225202c32393272,0x6461090a3b393732,0x2509203233752e64\n"
".quad 0x7225202c34393272,0x327225202c333932,0x38732e646c090a3b,0x2c31323172250920\n"
".quad 0x2b34393272255b20,0x766f6d090a3b5d30,0x722509203233732e,0x317225202c323231\n"
".quad 0x766f6d090a3b3132,0x722509203233732e,0x0a3b30202c353932,0x2e74672e74657309\n"
".quad 0x203233732e323375,0x202c363932722509,0x25202c3132317225,0x6e090a3b35393272\n"
".quad 0x09203233732e6765,0x25202c3739327225,0x6d090a3b36393272,0x09203233732e766f\n"
".quad 0x30202c3839327225,0x672e746573090a3b,0x33732e3233752e74,0x3939327225092032\n"
".quad 0x2c3631317225202c,0x0a3b383932722520,0x3233732e67656e09,0x2c30303372250920\n"
".quad 0x0a3b393932722520,0x3233622e646e6109,0x2c31303372250920,0x202c373932722520\n"
".quad 0x090a3b3030337225,0x203233752e766f6d,0x202c323033722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3233702509,0x7225202c31303372,0x2540090a3b323033\n"
".quad 0x2061726220323370,0x355f345f744c2409,0x2f200a3b38333732,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x30345f345f744c24,0x6f6c2e090a323639,0x0936330938310963\n"
".quad 0x732e646461090a30,0x3033722509203233,0x2c31337225202c33,0x6873090a3b333120\n"
".quad 0x2509203233732e72,0x7225202c34303372,0x6d090a3b32202c39,0x33752e6f6c2e6c75\n"
".quad 0x3530337225092032,0x2c3430337225202c,0x646461090a3b3420,0x722509203233752e\n"
".quad 0x327225202c363033,0x3b3530337225202c,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x327225202c373033,0x090a3b34202c3339,0x203233752e646461,0x202c383033722509\n"
".quad 0x25202c3630337225,0x73090a3b37303372,0x5b09203233732e74,0x5d302b3830337225\n"
".quad 0x3b3330337225202c,0x33732e766f6d090a,0x3733317225092032,0x7262090a3b31202c\n"
".quad 0x240920696e752e61,0x3431355f345f744c,0x5f744c240a3b3835,0x3a38333732355f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39382065,0x6c6562616c206461,0x345f744c24206465,0x090a32363930345f\n"
".quad 0x203233732e766f6d,0x202c373331722509,0x2e617262090a3b30,0x744c240920696e75\n"
".quad 0x38353431355f345f,0x5f345f744c240a3b,0x200a3a3431373135,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3938\n"
".quad 0x64656c6562616c20,0x345f345f744c2420,0x6f6d090a32363930,0x2509203233732e76\n"
".quad 0x3b30202c37333172,0x355f345f744c240a,0x2f200a3a38353431,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x30345f345f744c24,0x6f6c2e090a323639,0x0939330938310963\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x3233732e766f6d09,0x2c39303372250920\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x202c343170250920,0x25202c3733317225\n"
".quad 0x40090a3b39303372,0x7262203431702521,0x345f744c24092061,0x0a3b34393932355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064,0x2e090a3236393034\n"
".quad 0x3409383109636f6c,0x646461090a300935,0x722509203233732e,0x337225202c303133\n"
".quad 0x090a3b3331202c31,0x203233622e646e61,0x202c313133722509,0x31202c3031337225\n"
".quad 0x732e766964090a3b,0x3133722509203233,0x2c34397225202c32,0x61090a3b34722520\n"
".quad 0x09203233622e646e,0x25202c3331337225,0x3b31202c32313372,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x337225202c333370,0x31337225202c3131,0x33702540090a3b33\n"
".quad 0x2409206172622033,0x3034325f345f744c,0x3c2f2f200a3b3636,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363930345f345f74,0x732e726873090a32,0x3431722509203233\n"
".quad 0x202c397225202c33,0x2e6c756d090a3b32,0x09203233752e6f6c,0x25202c3434317225\n"
".quad 0x3b34202c33343172,0x33752e646461090a,0x3534317225092032,0x2c3434317225202c\n"
".quad 0x6d090a3b32722520,0x09203233732e766f,0x25202c3634317225,0x6d090a3b38303172\n"
".quad 0x09203233732e766f,0x25202c3431337225,0x6d090a3b30303172,0x33732e6f6c2e6c75\n"
".quad 0x3531337225092032,0x2c3431337225202c,0x61090a3b34722520,0x09203233732e6464\n"
".quad 0x25202c3631337225,0x7225202c36343172,0x756d090a3b353133,0x3233752e6f6c2e6c\n"
".quad 0x2c37313372250920,0x202c363133722520,0x2e646461090a3b34,0x3372250920323375\n"
".quad 0x34317225202c3831,0x3731337225202c35,0x33732e646c090a3b,0x3931337225092032\n"
".quad 0x38313372255b202c,0x6573090a3b5d302b,0x33732e71652e7074,0x2c34337025092032\n"
".quad 0x202c393133722520,0x090a3b3031337225,0x7262203433702540,0x345f744c24092061\n"
".quad 0x0a3b34333836355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393820,0x656c6562616c2064,0x5f345f744c242064\n"
".quad 0x6d090a3236393034,0x09203233732e766f,0x25202c3032337225,0x6d090a3b32313172\n"
".quad 0x33732e6f6c2e6c75,0x3132337225092032,0x2c3032337225202c,0x61090a3b34722520\n"
".quad 0x09203233732e6464,0x25202c3232337225,0x7225202c31323372,0x2e6c756d090a3b34\n"
".quad 0x09203233752e6f6c,0x25202c3332337225,0x3b34202c32323372,0x33752e627573090a\n"
".quad 0x3432337225092032,0x2c3332337225202c,0x646461090a3b3420,0x722509203233732e\n"
".quad 0x337225202c353233,0x34317225202c3132,0x2e6c756d090a3b36,0x09203233752e6f6c\n"
".quad 0x25202c3632337225,0x3b34202c35323372,0x33752e627573090a,0x3732337225092032\n"
".quad 0x2c3632337225202c,0x766f6d090a3b3420,0x722509203233732e,0x0a3b30202c383233\n"
".quad 0x71652e7074657309,0x702509203233732e,0x34317225202c3533,0x3832337225202c36\n"
".quad 0x2e706c6573090a3b,0x3372250920323375,0x32337225202c3932,0x3732337225202c34\n"
".quad 0x0a3b35337025202c,0x3233752e64646109,0x2c30333372250920,0x202c393233722520\n"
".quad 0x090a3b3534317225,0x09203233732e646c,0x5b202c3133337225,0x5d302b3033337225\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x7225202c36337025,0x337225202c313333\n"
".quad 0x702540090a3b3031,0x0920617262203633,0x36355f345f744c24,0x744c240a3b343338\n"
".quad 0x36363034325f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c393820656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363930345f34,0x3233732e766f6d09,0x2c32333372250920,0x617262090a3b3120\n"
".quad 0x4c240920696e752e,0x303635325f345f74,0x345f744c240a3b32,0x0a3a34333836355f\n"
".quad 0x34325f345f744c24,0x2f2f200a3a323233,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3930345f345f744c,0x2e766f6d090a3236,0x3372250920323373,0x240a3b30202c3233\n"
".quad 0x3635325f345f744c,0x3c2f2f200a3a3230,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393820656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363930345f345f74,0x732e766f6d090a32,0x3333722509203233,0x73090a3b30202c33\n"
".quad 0x732e656e2e707465,0x3431702509203233,0x2c3233337225202c,0x0a3b333333722520\n"
".quad 0x32355f345f744c24,0x2f2f200a3a343939,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393820656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3930345f345f744c,0x70252140090a3236,0x0920617262203431,0x33355f345f744c24\n"
".quad 0x2f2f200a3b363035,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x393820656e696c20,0x6c2064616568202c,0x242064656c656261,0x3930345f345f744c\n"
".quad 0x636f6c2e090a3236,0x3009343509383109,0x33732e766f6d090a,0x3433337225092032\n"
".quad 0x3b3731317225202c,0x33732e627573090a,0x3533337225092032,0x2c3433337225202c\n"
".quad 0x766f6d090a3b3120,0x722509203233732e,0x317225202c363333,0x766f6d090a3b3830\n"
".quad 0x722509203233732e,0x317225202c373333,0x6c756d090a3b3030,0x203233732e6f6c2e\n"
".quad 0x202c383333722509,0x25202c3733337225,0x646461090a3b3472,0x722509203233732e\n"
".quad 0x337225202c393333,0x33337225202c3633,0x2e646461090a3b38,0x3372250920323375\n"
".quad 0x2c327225202c3034,0x0a3b393333722520,0x092038732e747309,0x302b30343372255b\n"
".quad 0x3533337225202c5d,0x09636f6c2e090a3b,0x0a30093535093831,0x3233732e766f6d09\n"
".quad 0x2c31343372250920,0x0a3b323231722520,0x3233732e62757309,0x2c32343372250920\n"
".quad 0x202c313433722520,0x2e766964090a3b31,0x3372250920323373,0x34397225202c3334\n"
".quad 0x090a3b347225202c,0x732e6f6c2e6c756d,0x3433722509203233,0x202c347225202c34\n"
".quad 0x090a3b3334337225,0x203233732e6d6572,0x202c353433722509,0x7225202c34397225\n"
".quad 0x2e646461090a3b34,0x3372250920323373,0x34337225202c3634,0x3534337225202c34\n"
".quad 0x752e646461090a3b,0x3433722509203233,0x202c327225202c37,0x090a3b3634337225\n"
".quad 0x5b092038732e7473,0x5d302b3734337225,0x3b3234337225202c,0x355f345f744c240a\n"
".quad 0x2f200a3a36303533,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x30345f345f744c24\n"
".quad 0x6f6c2e090a323639,0x0937350938310963,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x2034317025214009,0x744c240920617262,0x38313034355f345f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393820656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f34,0x383109636f6c2e09\n"
".quad 0x6d090a3009303609,0x09203233732e766f,0x25202c3834337225,0x6d090a3b32313172\n"
".quad 0x33732e6f6c2e6c75,0x3934337225092032,0x2c3834337225202c,0x6d090a3b34722520\n"
".quad 0x09203233732e766f,0x25202c3035337225,0x61090a3b38303172,0x09203233732e6464\n"
".quad 0x25202c3135337225,0x7225202c30353372,0x6461090a3b393433,0x2509203233752e64\n"
".quad 0x7225202c35383172,0x327225202c313533,0x38732e646c090a3b,0x2c32353372250920\n"
".quad 0x2b35383172255b20,0x646461090a3b5d30,0x722509203233732e,0x337225202c333533\n"
".quad 0x090a3b31202c3235,0x5b092038732e7473,0x5d302b3538317225,0x3b3335337225202c\n"
".quad 0x3109636f6c2e090a,0x090a300931360938,0x203233732e6d6572,0x202c393732722509\n"
".quad 0x7225202c34397225,0x2e627573090a3b34,0x3172250920323373,0x2c347225202c3838\n"
".quad 0x766964090a3b3120,0x722509203233732e,0x397225202c373732,0x0a3b347225202c34\n"
".quad 0x656e2e7074657309,0x702509203233732e,0x37327225202c3733,0x3838317225202c39\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c34353372,0x347225202c373732\n"
".quad 0x732e646461090a3b,0x3932722509203233,0x3435337225202c33,0x3b3937327225202c\n"
".quad 0x33752e646461090a,0x3039317225092032,0x2c3339327225202c,0x6c6573090a3b3120\n"
".quad 0x2509203233752e70,0x7225202c31393172,0x337225202c303931,0x37337025202c3435\n"
".quad 0x752e646461090a3b,0x3931722509203233,0x3139317225202c32,0x090a3b327225202c\n"
".quad 0x25092038732e646c,0x255b202c35353372,0x3b5d302b32393172,0x33732e646461090a\n"
".quad 0x3635337225092032,0x2c3535337225202c,0x2e7473090a3b3120,0x3172255b09203873\n"
".quad 0x25202c5d302b3239,0x4c240a3b36353372,0x313034355f345f74,0x6c3c2f2f200a3a38\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393820656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363930345f345f,0x3109636f6c2e090a\n"
".quad 0x090a300933360938,0x636e79732e726162,0x6c2e090a3b300920,0x313109383109636f\n"
".quad 0x646461090a300934,0x722509203233732e,0x31337225202c3133,0x090a3b323133202c\n"
".quad 0x2e74672e70746573,0x3370250920323373,0x202c367225202c38,0x40090a3b31337225\n"
".quad 0x6172622038337025,0x5f345f744c240920,0x240a3b3236393034,0x3430345f345f744c\n"
".quad 0x6f6c2e090a3a3035,0x3132310938310963,0x3b746572090a3009,0x646e6557444c240a\n"
".quad 0x6e757234315a5f5f,0x7463656a6172745f,0x3a6969695079726f,0x5f202f2f207d090a\n"
".quad 0x745f6e757234315a,0x726f7463656a6172,0x090a0a6969695079,0x656c62697369762e\n"
".quad 0x5f20636e75662e20,0x75706d6f6339315a,0x72617765725f6574,0x6950746174735f64\n"
".quad 0x2e2820695f536650,0x752e206d61726170,0x6475635f5f203233,0x5f31666d72617061\n"
".quad 0x706d6f6339315a5f,0x617765725f657475,0x50746174735f6472,0x202c695f53665069\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x32666d7261706164,0x6d6f6339315a5f5f\n"
".quad 0x7765725f65747570,0x746174735f647261,0x2c695f5366506950,0x206d617261702e20\n"
".quad 0x635f5f203233752e,0x666d726170616475,0x6f6339315a5f5f33,0x65725f657475706d\n"
".quad 0x6174735f64726177,0x695f536650695074,0x6d617261702e202c,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6339315a5f5f3466,0x725f657475706d6f,0x74735f6472617765\n"
".quad 0x5f53665069507461,0x2e090a7b090a2969,0x3233752e20676572,0x3b3e34373c722520\n"
".quad 0x2e206765722e090a,0x323c662520323366,0x65722e090a3b3e35,0x20646572702e2067\n"
".quad 0x090a3b3e393c7025,0x09383109636f6c2e,0x4c240a3009373231,0x5f6e696765625744\n"
".quad 0x706d6f6339315a5f,0x617765725f657475,0x50746174735f6472,0x0a3a695f53665069\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3172,0x666d726170616475\n"
".quad 0x6f6339315a5f5f31,0x65725f657475706d,0x6174735f64726177,0x695f536650695074\n"
".quad 0x2e766f6d090a3b5d,0x3272250920323373,0x090a3b317225202c,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x75635f5f5b202c33,0x32666d7261706164,0x6d6f6339315a5f5f\n"
".quad 0x7765725f65747570,0x746174735f647261,0x5d695f5366506950,0x732e766f6d090a3b\n"
".quad 0x2c34722509203233,0x6c090a3b33722520,0x2e6d617261702e64,0x3572250920323375\n"
".quad 0x6475635f5f5b202c,0x5f33666d72617061,0x706d6f6339315a5f,0x617765725f657475\n"
".quad 0x50746174735f6472,0x3b5d695f53665069,0x33732e766f6d090a,0x202c367225092032\n"
".quad 0x646c090a3b357225,0x752e6d617261702e,0x2c37722509203233,0x616475635f5f5b20\n"
".quad 0x5f5f34666d726170,0x75706d6f6339315a,0x72617765725f6574,0x6950746174735f64\n"
".quad 0x0a3b5d695f536650,0x3233732e766f6d09,0x25202c3872250920,0x726873090a3b3772\n"
".quad 0x722509203233732e,0x202c387225202c39,0x766f6d090a3b3031,0x722509203233752e\n"
".quad 0x64697425202c3031,0x627573090a3b782e,0x722509203233732e,0x2c397225202c3131\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x090a3b30202c3231,0x2e746c2e70746573\n"
".quad 0x3170250920323373,0x202c31317225202c,0x40090a3b32317225,0x2061726220317025\n"
".quad 0x395f355f744c2409,0x6f6d090a3b343734,0x2509203233732e76,0x397225202c333172\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c343172,0x61090a3b34202c30\n"
".quad 0x09203233732e6464,0x7225202c35317225,0x3b327225202c3431,0x33732e766f6d090a\n"
".quad 0x2c36317225092032,0x766f6d090a3b3020,0x722509203233732e,0x090a3b30202c3731\n"
".quad 0x203233662e766f6d,0x6630202c31662509,0x3030303030303030,0x2f0920202020203b\n"
".quad 0x766f6d090a30202f,0x722509203233732e,0x33317225202c3831,0x5f355f744c240a3b\n"
".quad 0x2f200a3a30393835,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3120656e696c2079\n"
".quad 0x7473656e202c3732,0x7470656420676e69,0x7365202c31203a68,0x20646574616d6974\n"
".quad 0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f,0x3533310938310963\n"
".quad 0x2e6c6873090a3009,0x3172250920323362,0x2c36317225202c39,0x6c756d090a3b3820\n"
".quad 0x203233752e6f6c2e,0x25202c3032722509,0x0a3b34202c393172,0x3233732e64646109\n"
".quad 0x202c313272250920,0x7225202c35317225,0x2e646c090a3b3032,0x3272250920323373\n"
".quad 0x313272255b202c32,0x6c2e090a3b5d302b,0x333109383109636f,0x646e61090a300938\n"
".quad 0x722509203233622e,0x32327225202c3332,0x090a3b353532202c,0x732e6f6c2e6c756d\n"
".quad 0x3432722509203233,0x202c33327225202c,0x63090a3b33327225,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x34327225202c3266,0x662e646461090a3b,0x2c33662509203233\n"
".quad 0x6625202c32662520,0x636f6c2e090a3b31,0x0939333109383109,0x732e78616d090a30\n"
".quad 0x3532722509203233,0x202c33327225202c,0x2e090a3b37317225,0x3109383109636f6c\n"
".quad 0x6873090a30093134,0x2509203233732e72,0x327225202c363272,0x61090a3b38202c32\n"
".quad 0x09203233622e646e,0x7225202c37327225,0x3b353532202c3632,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x37327225202c3832,0x0a3b37327225202c,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x7225202c34662509,0x646461090a3b3832,0x662509203233662e\n"
".quad 0x202c346625202c35,0x6c2e090a3b336625,0x343109383109636f,0x78616d090a300932\n"
".quad 0x722509203233732e,0x37327225202c3932,0x0a3b35327225202c,0x383109636f6c2e09\n"
".quad 0x090a300934343109,0x203233732e726873,0x25202c3033722509,0x3b3631202c323272\n"
".quad 0x33622e646e61090a,0x2c31337225092032,0x32202c3033722520,0x6c756d090a3b3535\n"
".quad 0x203233732e6f6c2e,0x25202c3233722509,0x337225202c313372,0x2e747663090a3b31\n"
".quad 0x732e3233662e6e72,0x2c36662509203233,0x090a3b3233722520,0x203233662e646461\n"
".quad 0x6625202c37662509,0x0a3b356625202c36,0x383109636f6c2e09,0x090a300935343109\n"
".quad 0x203233732e78616d,0x25202c3333722509,0x327225202c313372,0x636f6c2e090a3b39\n"
".quad 0x0937343109383109,0x732e726873090a30,0x3433722509203233,0x202c32327225202c\n"
".quad 0x646e61090a3b3432,0x722509203233622e,0x34337225202c3533,0x090a3b353532202c\n"
".quad 0x732e6f6c2e6c756d,0x3633722509203233,0x202c35337225202c,0x63090a3b35337225\n"
".quad 0x33662e6e722e7476,0x2509203233732e32,0x36337225202c3866,0x662e646461090a3b\n"
".quad 0x2c31662509203233,0x6625202c38662520,0x636f6c2e090a3b37,0x0938343109383109\n"
".quad 0x732e78616d090a30,0x3731722509203233,0x202c35337225202c,0x61090a3b33337225\n"
".quad 0x09203233732e6464,0x7225202c36317225,0x090a3b31202c3631,0x2e656e2e70746573\n"
".quad 0x3270250920323373,0x25202c397225202c,0x2540090a3b363172,0x0920617262203270\n"
".quad 0x38355f355f744c24,0x617262090a3b3039,0x4c240920696e752e,0x383733355f355f74\n"
".quad 0x5f355f744c240a3b,0x6d090a3a34373439,0x33752e6f6c2e6c75,0x2c34317225092032\n"
".quad 0x34202c3031722520,0x732e766f6d090a3b,0x3731722509203233,0x6f6d090a3b30202c\n"
".quad 0x2509203233662e76,0x30306630202c3166,0x203b303030303030,0x202f2f0920202020\n"
".quad 0x5f355f744c240a30,0x73090a3a38373335,0x09203233732e7268,0x7225202c37337225\n"
".quad 0x61090a3b32202c38,0x09203233622e646e,0x7225202c38337225,0x3b353532202c3733\n"
".quad 0x33752e627573090a,0x2c39337225092032,0x31202c3833722520,0x2e70746573090a3b\n"
".quad 0x09203233752e7467,0x317225202c337025,0x3b39337225202c30,0x622033702540090a\n"
".quad 0x5f744c2409206172,0x0a3b323034365f35,0x383109636f6c2e09,0x090a300937353109\n"
".quad 0x732e6f6c2e6c756d,0x3034722509203233,0x32202c397225202c,0x646461090a3b3635\n"
".quad 0x722509203233752e,0x30317225202c3134,0x0a3b30347225202c,0x2e6f6c2e6c756d09\n"
".quad 0x3472250920323375,0x2c31347225202c32,0x646461090a3b3420,0x722509203233752e\n"
".quad 0x2c327225202c3334,0x090a3b3234722520,0x09203233732e646c,0x255b202c34347225\n"
".quad 0x0a3b5d302b333472,0x383109636f6c2e09,0x090a300930363109,0x203233622e646e61\n"
".quad 0x25202c3534722509,0x353532202c343472,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x347225202c363472,0x3b35347225202c35,0x6e722e747663090a,0x3233732e3233662e\n"
".quad 0x25202c3966250920,0x6461090a3b363472,0x2509203233662e64,0x396625202c303166\n"
".quad 0x090a3b316625202c,0x09383109636f6c2e,0x6d090a3009313631,0x09203233732e7861\n"
".quad 0x7225202c37347225,0x37317225202c3534,0x09636f6c2e090a3b,0x3009333631093831\n"
".quad 0x33732e726873090a,0x2c38347225092032,0x38202c3434722520,0x622e646e61090a3b\n"
".quad 0x3934722509203233,0x202c38347225202c,0x756d090a3b353532,0x3233732e6f6c2e6c\n"
".quad 0x202c303572250920,0x7225202c39347225,0x747663090a3b3934,0x2e3233662e6e722e\n"
".quad 0x3166250920323373,0x3b30357225202c31,0x33662e646461090a,0x2c32316625092032\n"
".quad 0x25202c3131662520,0x6c2e090a3b303166,0x363109383109636f,0x78616d090a300934\n"
".quad 0x722509203233732e,0x39347225202c3135,0x0a3b37347225202c,0x383109636f6c2e09\n"
".quad 0x090a300936363109,0x203233732e726873,0x25202c3235722509,0x3b3631202c343472\n"
".quad 0x33622e646e61090a,0x2c33357225092032,0x32202c3235722520,0x6c756d090a3b3535\n"
".quad 0x203233732e6f6c2e,0x25202c3435722509,0x357225202c333572,0x2e747663090a3b33\n"
".quad 0x732e3233662e6e72,0x3331662509203233,0x0a3b34357225202c,0x3233662e64646109\n"
".quad 0x202c343166250920,0x6625202c33316625,0x6f6c2e090a3b3231,0x3736310938310963\n"
".quad 0x2e78616d090a3009,0x3572250920323373,0x2c33357225202c35,0x090a3b3135722520\n"
".quad 0x09383109636f6c2e,0x73090a3009393631,0x09203233732e7268,0x7225202c36357225\n"
".quad 0x0a3b3432202c3434,0x3233622e646e6109,0x202c373572250920,0x3532202c36357225\n"
".quad 0x2e6c756d090a3b35,0x09203233732e6f6c,0x7225202c38357225,0x37357225202c3735\n"
".quad 0x722e747663090a3b,0x33732e3233662e6e,0x2c35316625092032,0x090a3b3835722520\n"
".quad 0x203233662e646461,0x6625202c31662509,0x34316625202c3531,0x09636f6c2e090a3b\n"
".quad 0x3009303731093831,0x33732e78616d090a,0x2c37317225092032,0x25202c3735722520\n"
".quad 0x744c240a3b353572,0x3a323034365f355f,0x732e61747663090a,0x33752e6465726168\n"
".quad 0x2c39357225092032,0x6c2e090a3b746d20,0x373109383109636f,0x646461090a300933\n"
".quad 0x722509203233752e,0x34317225202c3036,0x0a3b39357225202c,0x203233662e747309\n"
".quad 0x302b303672255b09,0x0a3b316625202c5d,0x383109636f6c2e09,0x090a300934373109\n"
".quad 0x09203233752e7473,0x30312b303672255b,0x317225202c5d3432,0x636f6c2e090a3b37\n"
".quad 0x0935373109383109,0x732e726162090a30,0x0a3b300920636e79,0x3233732e766f6d09\n"
".quad 0x202c363172250920,0x744c240a3b383231,0x3a363234375f355f,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3537312065,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x2e656c2e70746573,0x3470250920323375,0x202c36317225202c\n"
".quad 0x40090a3b30317225,0x2061726220347025,0x385f355f744c2409,0x2f2f200a3b343931\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x373120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x34375f355f744c24,0x636f6c2e090a3632\n"
".quad 0x0931383109383109,0x752e646461090a30,0x3136722509203233,0x202c36317225202c\n"
".quad 0x6d090a3b30317225,0x33752e6f6c2e6c75,0x2c32367225092032,0x34202c3136722520\n"
".quad 0x752e646461090a3b,0x3336722509203233,0x202c32367225202c,0x6c090a3b39357225\n"
".quad 0x2509203233662e64,0x72255b202c363166,0x090a3b5d302b3036,0x09203233662e646c\n"
".quad 0x255b202c37316625,0x0a3b5d302b333672,0x3233662e64646109,0x202c383166250920\n"
".quad 0x6625202c36316625,0x2e7473090a3b3731,0x72255b0920323366,0x25202c5d302b3036\n"
".quad 0x646c090a3b383166,0x722509203233752e,0x3672255b202c3436,0x3b5d343230312b33\n"
".quad 0x3233752e646c090a,0x202c353672250920,0x30312b303672255b,0x6573090a3b5d3432\n"
".quad 0x33752e65672e7074,0x202c357025092032,0x7225202c35367225,0x702540090a3b3436\n"
".quad 0x2409206172622035,0x3931385f355f744c,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35373120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363234375f355f74,0x3109636f6c2e090a,0x0a30093338310938\n"
".quad 0x203233752e747309,0x312b303672255b09,0x7225202c5d343230,0x5f744c240a3b3436\n"
".quad 0x0a3a343931385f35,0x36375f355f744c24,0x3c2f2f200a3a3238,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35373120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3234375f355f744c,0x09636f6c2e090a36,0x3009353831093831\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x09383109636f6c2e,0x73090a3009373731\n"
".quad 0x09203233732e7268,0x7225202c36317225,0x090a3b31202c3631,0x203233752e766f6d\n"
".quad 0x30202c3636722509,0x2e70746573090a3b,0x09203233732e7467,0x317225202c367025\n"
".quad 0x3b36367225202c36,0x622036702540090a,0x5f744c2409206172,0x0a3b363234375f35\n"
".quad 0x3233752e766f6d09,0x202c373672250920,0x70746573090a3b30,0x203233752e656e2e\n"
".quad 0x7225202c37702509,0x37367225202c3031,0x2037702540090a3b,0x744c240920617262\n"
".quad 0x3b323639385f355f,0x3109636f6c2e090a,0x0a30093039310938,0x3233752e766f6d09\n"
".quad 0x202c383672250920,0x782e646961746325,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x367225202c393672,0x6c090a3b34202c38,0x6465726168732e64,0x662509203233662e\n"
".quad 0x2b746d5b202c3931,0x747663090a3b5d30,0x2e3233662e6e722e,0x3266250920323373\n"
".quad 0x0a3b387225202c30,0x2e6e722e76696409,0x3266250920323366,0x2c39316625202c31\n"
".quad 0x090a3b3032662520,0x203233662e766f6d,0x30202c3232662509,0x3030303038666266\n"
".quad 0x2f09202020203b30,0x6461090a312d202f,0x2509203233662e64,0x326625202c333266\n"
".quad 0x3b32326625202c31,0x33752e646461090a,0x2c30377225092032,0x25202c3936722520\n"
".quad 0x2e7473090a3b3472,0x72255b0920323366,0x25202c5d302b3037,0x6c2e090a3b333266\n"
".quad 0x393109383109636f,0x2e646c090a300932,0x732e646572616873,0x3137722509203233\n"
".quad 0x30312b746d5b202c,0x6461090a3b5d3432,0x2509203233752e64,0x367225202c323772\n"
".quad 0x0a3b367225202c39,0x203233732e747309,0x302b323772255b09,0x3b31377225202c5d\n"
".quad 0x385f355f744c240a,0x6c2e090a3a323639,0x393109383109636f,0x746572090a300934\n"
".quad 0x6e6557444c240a3b,0x6f6339315a5f5f64,0x65725f657475706d,0x6174735f64726177\n"
".quad 0x695f536650695074,0x202f2f207d090a3a,0x706d6f6339315a5f,0x617765725f657475\n"
".quad 0x50746174735f6472,0x0a0a695f53665069,0x207972746e652e09,0x7274655034315a5f\n"
".quad 0x6e72654b74656e69,0x5f53665069506c65,0x09090a2820696969,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x5f5f6d7261706164,0x697274655034315a,0x656e72654b74656e\n"
".quad 0x695f53665069506c,0x0a2c735f675f6969,0x6d617261702e0909,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x74655034315a5f5f,0x72654b74656e6972,0x53665069506c656e\n"
".quad 0x765f675f6969695f,0x7261702e09090a2c,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x5034315a5f5f6d72,0x4b74656e69727465,0x5069506c656e7265,0x675f6969695f5366\n"
".quad 0x702e09090a2c6d5f,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x656e697274655034,0x506c656e72654b74,0x6969695f53665069,0x702e09090a2c6e5f\n"
".quad 0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170,0x656e697274655034\n"
".quad 0x506c656e72654b74,0x6969695f53665069,0x702e09090a2c735f,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x656e697274655034,0x506c656e72654b74\n"
".quad 0x6969695f53665069,0x090a29646565735f,0x206765722e090a7b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e323734,0x3233662e20676572,0x3b3e35323c662520,0x2e206765722e090a\n"
".quad 0x3c70252064657270,0x2f2f090a3b3e3235,0x5f616475635f5f20,0x61765f6c61636f6c\n"
".quad 0x5f37323331335f72,0x6f635f6e6f6e5f37,0x316c61765f74736e,0x2f2f090a34203d20\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f37323331335f72,0x635f6e6f6e5f3331\n"
".quad 0x6c61765f74736e6f,0x2f090a38203d2032,0x616475635f5f202f,0x765f6c61636f6c5f\n"
".quad 0x37323331335f7261,0x5f6e6f6e5f39315f,0x61765f74736e6f63,0x0a3231203d20336c\n"
".quad 0x75635f5f202f2f09,0x6c61636f6c5f6164,0x3331335f7261765f,0x6e6f6e5f375f3832\n"
".quad 0x6d5f74736e6f635f,0x31203d20316b7261,0x5f5f202f2f090a36,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f34315f38323331,0x736e6f635f6e6f6e,0x20326b72616d5f74\n"
".quad 0x2f2f090a3032203d,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f32303231335f72\n"
".quad 0x635f6e6f6e5f3031,0x3d20795f74736e6f,0x636f6c2e090a3020,0x0931303209383109\n"
".quad 0x656257444c240a30,0x34315a5f5f6e6967,0x74656e6972746550,0x69506c656e72654b\n"
".quad 0x3a6969695f536650,0x3109636f6c2e090a,0x0a30093830320938,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x635f5f5b202c3172,0x5f6d726170616475,0x7274655034315a5f\n"
".quad 0x6e72654b74656e69,0x5f53665069506c65,0x0a3b5d6e5f696969,0x2e6f6c2e6c756d09\n"
".quad 0x3272250920323373,0x25202c317225202c,0x6c756d090a3b3172,0x203233732e6f6c2e\n"
".quad 0x7225202c33722509,0x73090a3b32202c32,0x09203233732e7268,0x337225202c347225\n"
".quad 0x6d090a3b3031202c,0x09203233752e766f,0x697425202c357225,0x6f6d090a3b782e64\n"
".quad 0x2509203233752e76,0x090a3b30202c3672,0x2e656c2e70746573,0x3170250920323373\n"
".quad 0x25202c347225202c,0x702540090a3b3672,0x2409206172622031,0x3630375f365f744c\n"
".quad 0x766f6d090a3b3835,0x722509203233732e,0x0a3b347225202c37,0x2e6f6c2e6c756d09\n"
".quad 0x3872250920323375,0x34202c357225202c,0x732e726873090a3b,0x2c39722509203233\n"
".quad 0x3b32202c33722520,0x33732e646461090a,0x2c30317225092032,0x7225202c33722520\n"
".quad 0x2e766f6d090a3b39,0x3172250920323375,0x6961746325202c31,0x756d090a3b782e64\n"
".quad 0x3233752e6f6c2e6c,0x202c323172250920,0x7225202c30317225,0x6c756d090a3b3131\n"
".quad 0x203233752e6f6c2e,0x25202c3331722509,0x0a3b34202c323172,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x5f5f5b202c343172,0x6d72617061647563,0x74655034315a5f5f\n"
".quad 0x72654b74656e6972,0x53665069506c656e,0x735f675f6969695f,0x2e646461090a3b5d\n"
".quad 0x3172250920323375,0x2c34317225202c35,0x090a3b3331722520,0x203233732e766f6d\n"
".quad 0x30202c3631722509,0x732e766f6d090a3b,0x3731722509203233,0x240a3b377225202c\n"
".quad 0x3639345f365f744c,0x3c2f2f200a3a3636,0x6f4c203e706f6f6c,0x2079646f6220706f\n"
".quad 0x38303220656e696c,0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120\n"
".quad 0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e\n"
".quad 0x0a30093637093831,0x3233732e766f6d09,0x202c383172250920,0x3930303334383631\n"
".quad 0x622e6c6873090a3b,0x3931722509203233,0x202c36317225202c,0x2e6c756d090a3b38\n"
".quad 0x09203233752e6f6c,0x7225202c30327225,0x090a3b34202c3931,0x203233752e646461\n"
".quad 0x25202c3132722509,0x30327225202c3872,0x752e646461090a3b,0x3232722509203233\n"
".quad 0x202c35317225202c,0x73090a3b31327225,0x6c61626f6c672e74,0x255b09203233732e\n"
".quad 0x202c5d302b323272,0x61090a3b38317225,0x09203233732e6464,0x7225202c36317225\n"
".quad 0x090a3b31202c3631,0x2e656e2e70746573,0x3270250920323373,0x25202c347225202c\n"
".quad 0x2540090a3b363172,0x0920617262203270,0x39345f365f744c24,0x7262090a3b363636\n"
".quad 0x240920696e752e61,0x3139345f365f744c,0x5f744c240a3b3435,0x3a38353630375f36\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x202c357225202c38,0x2e726873090a3b34\n"
".quad 0x3972250920323373,0x32202c337225202c,0x5f365f744c240a3b,0x090a3a3435313934\n"
".quad 0x203233622e6c6873,0x25202c3332722509,0x090a3b38202c3472,0x203233732e627573\n"
".quad 0x25202c3432722509,0x33327225202c3972,0x2e70746573090a3b,0x09203233752e6567\n"
".quad 0x357225202c337025,0x0a3b34327225202c,0x7262203370254009,0x365f744c24092061\n"
".quad 0x0a3b38373130355f,0x383109636f6c2e09,0x6d090a3009313809,0x09203233732e766f\n"
".quad 0x3631202c35327225,0x0a3b393030333438,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5f5b202c363272,0x6d72617061647563,0x74655034315a5f5f,0x72654b74656e6972\n"
".quad 0x53665069506c656e,0x735f675f6969695f,0x2e766f6d090a3b5d,0x3272250920323375\n"
".quad 0x6961746325202c37,0x6461090a3b782e64,0x2509203233732e64,0x337225202c383272\n"
".quad 0x090a3b397225202c,0x752e6f6c2e6c756d,0x3932722509203233,0x202c37327225202c\n"
".quad 0x6d090a3b38327225,0x33752e6f6c2e6c75,0x2c30337225092032,0x34202c3932722520\n"
".quad 0x752e646461090a3b,0x3133722509203233,0x202c36327225202c,0x61090a3b30337225\n"
".quad 0x09203233752e6464,0x7225202c32337225,0x3b357225202c3332,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x32337225202c3333,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x337225202c343372,0x3b33337225202c31,0x6f6c672e7473090a,0x203233732e6c6162\n"
".quad 0x302b343372255b09,0x3b35327225202c5d,0x355f365f744c240a,0x2e090a3a38373130\n"
".quad 0x3809383109636f6c,0x766f6d090a300934,0x722509203233752e,0x090a3b30202c3533\n"
".quad 0x2e71652e70746573,0x3470250920323375,0x25202c357225202c,0x2140090a3b353372\n"
".quad 0x2061726220347025,0x355f365f744c2409,0x2e090a3b30393630,0x3509373109636f6c\n"
".quad 0x766f6d090a300936,0x722509203233752e,0x0a3b746d202c3633,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x5f5f5b202c373372,0x6d72617061647563,0x74655034315a5f5f\n"
".quad 0x72654b74656e6972,0x53665069506c656e,0x6565735f6969695f,0x766f6d090a3b5d64\n"
".quad 0x722509203233752e,0x61746325202c3833,0x61090a3b782e6469,0x09203233752e6464\n"
".quad 0x7225202c39337225,0x38337225202c3733,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x5d302b746d5b0920,0x0a3b39337225202c,0x3233752e64646109,0x202c303472250920\n"
".quad 0x3b34202c36337225,0x33752e646461090a,0x2c31347225092032,0x32202c3633722520\n"
".quad 0x6f6d090a3b363934,0x2509203233732e76,0x0a3b31202c323472,0x31355f365f744c24\n"
".quad 0x2f2f200a3a343137,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x363520656e696c20\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x72657469202c3120,0x203a736e6f697461\n"
".quad 0x6f6c2e090a333236,0x0939350937310963,0x68732e646c090a30,0x3233752e64657261\n"
".quad 0x202c333472250920,0x342d2b303472255b,0x2e726873090a3b5d,0x3472250920323375\n"
".quad 0x2c33347225202c34,0x6f78090a3b303320,0x2509203233622e72,0x347225202c353472\n"
".quad 0x3b34347225202c33,0x6f6c2e6c756d090a,0x722509203233752e,0x35347225202c3634\n"
".quad 0x333432313831202c,0x61090a3b33353233,0x09203233752e6464,0x7225202c37347225\n"
".quad 0x36347225202c3234,0x68732e7473090a3b,0x3233752e64657261,0x2b303472255b0920\n"
".quad 0x37347225202c5d30,0x732e646461090a3b,0x3234722509203233,0x202c32347225202c\n"
".quad 0x2e646461090a3b31,0x3472250920323375,0x2c30347225202c30,0x746573090a3b3420\n"
".quad 0x3233752e656e2e70,0x25202c3570250920,0x347225202c303472,0x35702540090a3b31\n"
".quad 0x4c24092061726220,0x313731355f365f74,0x365f744c240a3b34,0x0a3a30393630355f\n"
".quad 0x3233752e766f6d09,0x202c363372250920,0x6f6c2e090a3b746d,0x0932360937310963\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x383109636f6c2e09,0x090a300930313209\n"
".quad 0x6d617261702e646c,0x722509203233732e,0x635f5f5b202c3834,0x5f6d726170616475\n"
".quad 0x7274655034315a5f,0x6e72654b74656e69,0x5f53665069506c65,0x0a3b5d735f696969\n"
".quad 0x3233752e766f6d09,0x202c393472250920,0x70746573090a3b30,0x203233732e656c2e\n"
".quad 0x7225202c36702509,0x39347225202c3834,0x2036702540090a3b,0x744c240920617262\n"
".quad 0x34313930375f365f,0x732e646461090a3b,0x3031722509203233,0x25202c337225202c\n"
".quad 0x766f6d090a3b3972,0x722509203233752e,0x61746325202c3035,0x6d090a3b782e6469\n"
".quad 0x33752e6f6c2e6c75,0x2c32317225092032,0x25202c3031722520,0x756d090a3b303572\n"
".quad 0x3233752e6f6c2e6c,0x202c333172250920,0x3b34202c32317225,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5b202c31357225,0x726170616475635f,0x655034315a5f5f6d\n"
".quad 0x654b74656e697274,0x665069506c656e72,0x5f675f6969695f53,0x646461090a3b5d73\n"
".quad 0x722509203233752e,0x31357225202c3531,0x0a3b33317225202c,0x3233732e64646109\n"
".quad 0x202c323572250920,0x317225202c317225,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x357225202c333572,0x0a3b317225202c32,0x3233732e64646109,0x202c343572250920\n"
".quad 0x3133202c38347225,0x2e766f6d090a3b31,0x3572250920323373,0x313435312d202c35\n"
".quad 0x0a3b313331333837,0x3233732e766f6d09,0x202c363572250920,0x70746573090a3b30\n"
".quad 0x203233732e746c2e,0x7225202c37702509,0x36357225202c3435,0x732e736261090a3b\n"
".quad 0x3735722509203233,0x0a3b34357225202c,0x2e69682e6c756d09,0x3572250920323375\n"
".quad 0x2c37357225202c38,0x090a3b3535722520,0x203233752e627573,0x25202c3935722509\n"
".quad 0x357225202c373572,0x2e726873090a3b38,0x3672250920323375,0x2c39357225202c30\n"
".quad 0x646461090a3b3120,0x722509203233752e,0x30367225202c3136,0x0a3b38357225202c\n"
".quad 0x3233732e72687309,0x202c323672250920,0x3b38202c31367225,0x732037702540090a\n"
".quad 0x09203233732e6275,0x7225202c32367225,0x32367225202c3635,0x732e766f6d090a3b\n"
".quad 0x3336722509203233,0x0a3b32367225202c,0x3233752e766f6d09,0x202c343672250920\n"
".quad 0x6573090a3b363232,0x33752e656c2e7074,0x202c387025092032,0x367225202c357225\n"
".quad 0x2e646461090a3b34,0x3672250920323373,0x202c357225202c35,0x6f6d090a3b343534\n"
".quad 0x2509203233752e76,0x363532202c363672,0x2e70746573090a3b,0x09203233752e746c\n"
".quad 0x357225202c397025,0x0a3b36367225202c,0x3233752e766f6d09,0x202c373672250920\n"
".quad 0x6573090a3b313131,0x33752e656c2e7074,0x2c30317025092032,0x7225202c35722520\n"
".quad 0x766f6d090a3b3736,0x722509203233752e,0x3b323131202c3836,0x6c2e70746573090a\n"
".quad 0x2509203233752e74,0x357225202c313170,0x0a3b38367225202c,0x3233752e64646109\n"
".quad 0x202c393672250920,0x337225202c387225,0x2e766f6d090a3b36,0x3772250920323373\n"
".quad 0x0a3b323236202c30,0x656c2e7074657309,0x702509203233732e,0x35367225202c3231\n"
".quad 0x0a3b30377225202c,0x3233732e766f6d09,0x202c313772250920,0x2e766f6d090a3b30\n"
".quad 0x3772250920323373,0x3b33367225202c32,0x355f365f744c240a,0x2f200a3a38333732\n"
".quad 0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3220656e696c2079,0x7473656e202c3031\n"
".quad 0x7470656420676e69,0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469\n"
".quad 0x6e6b6e75203a736e,0x6f6c2e090a6e776f,0x0937390938310963,0x3870252140090a30\n"
".quad 0x4c24092061726220,0x393932355f365f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333732355f365f74,0x09636f6c2e090a38,0x0a30093737093731\n"
".quad 0x726168732e646c09,0x09203233752e6465,0x255b202c33377225,0x0a3b5d302b393672\n"
".quad 0x726168732e646c09,0x09203233752e6465,0x255b202c34377225,0x0a3b5d342b393672\n"
".quad 0x726168732e646c09,0x09203233752e6465,0x255b202c35377225,0x383835312b393672\n"
".quad 0x2e646e61090a3b5d,0x3772250920323362,0x2c33377225202c36,0x3834373431322d20\n"
".quad 0x61090a3b38343633,0x09203233622e646e,0x7225202c37377225,0x37343132202c3437\n"
".quad 0x0a3b373436333834,0x203233622e726f09,0x25202c3837722509,0x377225202c363772\n"
".quad 0x2e726873090a3b37,0x3772250920323375,0x2c38377225202c39,0x726f78090a3b3120\n"
".quad 0x722509203233622e,0x35377225202c3038,0x0a3b39377225202c,0x3233622e726f7809\n"
".quad 0x202c313872250920,0x312d202c30387225,0x3836333834373237,0x2e646e61090a3b31\n"
".quad 0x3872250920323362,0x2c38377225202c32,0x67656e090a3b3120,0x722509203233732e\n"
".quad 0x32387225202c3338,0x2e74636c73090a3b,0x203233732e323375,0x25202c3438722509\n"
".quad 0x387225202c303872,0x3b33387225202c31,0x33732e766f6d090a,0x2c35387225092032\n"
".quad 0x240a3b3438722520,0x3932355f365f744c,0x3c2f2f200a3a3439,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3732355f365f744c,0x636f6c2e090a3833,0x3009393709373109\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x7262203870252140,0x365f744c24092061\n"
".quad 0x0a3b36303533355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a38333732355f,0x09373109636f6c2e,0x6f6d090a30093238,0x2509203233732e76\n"
".quad 0x387225202c363872,0x732e7473090a3b35,0x33752e6465726168,0x393672255b092032\n"
".quad 0x387225202c5d302b,0x365f744c240a3b36,0x0a3a36303533355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220\n"
".quad 0x6c6562616c206461,0x365f744c24206465,0x090a38333732355f,0x09373109636f6c2e\n"
".quad 0x6162090a30093438,0x0920636e79732e72,0x70252140090a3b30,0x2409206172622038\n"
".quad 0x3034355f365f744c,0x3c2f2f200a3b3831,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x636f6c2e090a3833,0x3009313909373109,0x6168732e646c090a\n"
".quad 0x203233752e646572,0x5b202c3337722509,0x3b5d302b39367225,0x6168732e646c090a\n"
".quad 0x203233752e646572,0x5b202c3738722509,0x3830392b39367225,0x732e646c090a3b5d\n"
".quad 0x33752e6465726168,0x2c38387225092032,0x392b393672255b20,0x6e61090a3b5d3231\n"
".quad 0x2509203233622e64,0x387225202c393872,0x373431322d202c37,0x0a3b383436333834\n"
".quad 0x3233622e646e6109,0x202c303972250920,0x3132202c38387225,0x3734363338343734\n"
".quad 0x33622e726f090a3b,0x2c31397225092032,0x25202c3938722520,0x6873090a3b303972\n"
".quad 0x2509203233752e72,0x397225202c323972,0x78090a3b31202c31,0x09203233622e726f\n"
".quad 0x7225202c33397225,0x32397225202c3337,0x622e726f78090a3b,0x3439722509203233\n"
".quad 0x202c33397225202c,0x333834373237312d,0x6e61090a3b313836,0x2509203233622e64\n"
".quad 0x397225202c353972,0x6e090a3b31202c31,0x09203233732e6765,0x7225202c36397225\n"
".quad 0x636c73090a3b3539,0x33732e3233752e74,0x2c37397225092032,0x25202c3339722520\n"
".quad 0x397225202c343972,0x2e766f6d090a3b36,0x3872250920323373,0x3b37397225202c35\n"
".quad 0x355f365f744c240a,0x2f200a3a38313034,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3031,0x64656c6562616c20\n"
".quad 0x355f365f744c2420,0x6c2e090a38333732,0x333909373109636f,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x203870252140090a,0x744c240920617262,0x30333534355f365f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30313220656e,0x62616c2064616568,0x744c242064656c65,0x38333732355f365f\n"
".quad 0x3109636f6c2e090a,0x090a300936390937,0x203233732e766f6d,0x25202c3839722509\n"
".quad 0x7473090a3b353872,0x2e6465726168732e,0x72255b0920323375,0x2c5d3830392b3936\n"
".quad 0x240a3b3839722520,0x3534355f365f744c,0x3c2f2f200a3a3033,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3732355f365f744c,0x636f6c2e090a3833,0x3009383909373109\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x6220323170252140,0x5f744c2409206172\n"
".quad 0x3b32343035355f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333732355f36,0x373109636f6c2e09,0x090a300935303109,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x72255b202c393972,0x5d363138312b3936,0x68732e646c090a3b\n"
".quad 0x3233752e64657261,0x2c30303172250920,0x312b393672255b20,0x6c090a3b5d303238\n"
".quad 0x6465726168732e64,0x722509203233752e,0x72255b202c313031,0x3b5d3830392b3936\n"
".quad 0x33622e646e61090a,0x3230317225092032,0x202c39397225202c,0x333834373431322d\n"
".quad 0x6e61090a3b383436,0x2509203233622e64,0x7225202c33303172,0x343132202c303031\n"
".quad 0x3b37343633383437,0x3233622e726f090a,0x2c34303172250920,0x202c323031722520\n"
".quad 0x090a3b3330317225,0x203233752e726873,0x202c353031722509,0x31202c3430317225\n"
".quad 0x622e726f78090a3b,0x3031722509203233,0x3130317225202c36,0x3b3530317225202c\n"
".quad 0x33622e726f78090a,0x3730317225092032,0x2c3630317225202c,0x3834373237312d20\n"
".quad 0x61090a3b31383633,0x09203233622e646e,0x25202c3830317225,0x3b31202c34303172\n"
".quad 0x33732e67656e090a,0x3930317225092032,0x3b3830317225202c,0x752e74636c73090a\n"
".quad 0x09203233732e3233,0x25202c3031317225,0x7225202c36303172,0x317225202c373031\n"
".quad 0x766f6d090a3b3930,0x722509203233732e,0x31317225202c3538,0x365f744c240a3b30\n"
".quad 0x0a3a32343035355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a38333732355f,0x09373109636f6c2e,0x62090a3009373031,0x20636e79732e7261\n"
".quad 0x252140090a3b3009,0x2061726220323170,0x355f365f744c2409,0x2f200a3b34353535\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3031,0x64656c6562616c20,0x355f365f744c2420,0x6c2e090a38333732\n"
".quad 0x313109373109636f,0x766f6d090a300930,0x722509203233732e,0x387225202c313131\n"
".quad 0x732e7473090a3b35,0x33752e6465726168,0x393672255b092032,0x202c5d363138312b\n"
".quad 0x240a3b3131317225,0x3535355f365f744c,0x3c2f2f200a3a3435,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3732355f365f744c,0x636f6c2e090a3833,0x0932313109373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x6220347025214009,0x5f744c2409206172\n"
".quad 0x3b32323336355f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333732355f36,0x373109636f6c2e09,0x090a300937313109,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x6d5b202c32313172,0x61090a3b5d302b74,0x09203233622e646e\n"
".quad 0x25202c3331317225,0x3132202c32313172,0x3734363338343734,0x68732e646c090a3b\n"
".quad 0x3233752e64657261,0x2c34313172250920,0x3934322b746d5b20,0x646e61090a3b5d32\n"
".quad 0x722509203233622e,0x317225202c353131,0x3431322d202c3431,0x3b38343633383437\n"
".quad 0x3233622e726f090a,0x2c36313172250920,0x202c333131722520,0x090a3b3531317225\n"
".quad 0x203233732e766f6d,0x202c373131722509,0x090a3b3631317225,0x09373109636f6c2e\n"
".quad 0x73090a3009383131,0x09203233752e7268,0x25202c3831317225,0x3b31202c36313172\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x202c393131722509,0x343835312b746d5b\n"
".quad 0x2e726f78090a3b5d,0x3172250920323362,0x31317225202c3032,0x3931317225202c38\n"
".quad 0x622e726f78090a3b,0x3231722509203233,0x3032317225202c31,0x34373237312d202c\n"
".quad 0x090a3b3138363338,0x203233622e646e61,0x202c323231722509,0x31202c3631317225\n"
".quad 0x732e67656e090a3b,0x3231722509203233,0x3232317225202c33,0x2e74636c73090a3b\n"
".quad 0x203233732e323375,0x202c343231722509,0x25202c3032317225,0x7225202c31323172\n"
".quad 0x7473090a3b333231,0x2e6465726168732e,0x746d5b0920323375,0x202c5d323934322b\n"
".quad 0x090a3b3432317225,0x20696e752e617262,0x355f365f744c2409,0x4c240a3b36363036\n"
".quad 0x323336355f365f74,0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333732355f365f74,0x732e766f6d090a38,0x3131722509203233,0x3b35387225202c37\n"
".quad 0x355f365f744c240a,0x2f200a3a36363036,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3031,0x64656c6562616c20\n"
".quad 0x355f365f744c2420,0x6c2e090a38333732,0x323109373109636f,0x726162090a300930\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x3009363231093731,0x33752e726873090a\n"
".quad 0x3532317225092032,0x2c3731317225202c,0x6f78090a3b313120,0x2509203233622e72\n"
".quad 0x7225202c36323172,0x317225202c353231,0x6c6873090a3b3731,0x722509203233622e\n"
".quad 0x317225202c373231,0x090a3b37202c3632,0x203233622e646e61,0x202c383231722509\n"
".quad 0x2d202c3732317225,0x3638333038353631,0x726f78090a3b3635,0x722509203233622e\n"
".quad 0x317225202c393231,0x32317225202c3632,0x2e6c6873090a3b38,0x3172250920323362\n"
".quad 0x32317225202c3033,0x090a3b3531202c39,0x203233622e646e61,0x202c313331722509\n"
".quad 0x2d202c3033317225,0x3435363332323732,0x2e726f78090a3b34,0x3172250920323362\n"
".quad 0x32317225202c3233,0x3133317225202c39,0x752e726873090a3b,0x3331722509203233\n"
".quad 0x3233317225202c33,0x78090a3b3831202c,0x09203233622e726f,0x25202c3433317225\n"
".quad 0x7225202c32333172,0x6f6d090a3b333331,0x2509203233732e76,0x317225202c353872\n"
".quad 0x6f6c2e090a3b3433,0x3130310938310963,0x732e646c090a3009,0x33752e6465726168\n"
".quad 0x2c33377225092032,0x302b393672255b20,0x2e6d6572090a3b5d,0x3172250920323375\n"
".quad 0x33377225202c3533,0x0a3b33357225202c,0x3233732e76696409,0x2c36333172250920\n"
".quad 0x202c353331722520,0x6572090a3b317225,0x2509203233732e6d,0x7225202c37333172\n"
".quad 0x317225202c353331,0x3970252140090a3b,0x4c24092061726220,0x333836355f365f74\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562,0x333732355f365f74\n"
".quad 0x09636f6c2e090a38,0x0a30093832093831,0x3233732e62757309,0x2c38333172250920\n"
".quad 0x31202c3235722520,0x732e766f6d090a3b,0x3331722509203233,0x73090a3b30202c39\n"
".quad 0x732e71652e707465,0x3331702509203233,0x2c3633317225202c,0x0a3b393331722520\n"
".quad 0x3233732e62757309,0x2c30343172250920,0x202c363331722520,0x706c6573090a3b31\n"
".quad 0x722509203233732e,0x317225202c313431,0x34317225202c3833,0x3b33317025202c30\n"
".quad 0x33732e766f6d090a,0x3234317225092032,0x3b3134317225202c,0x33622e646e61090a\n"
".quad 0x3334317225092032,0x2c3633317225202c,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x0a3b30202c343431,0x71652e7074657309,0x702509203233732e,0x34317225202c3431\n"
".quad 0x3434317225202c33,0x3431702540090a3b,0x4c24092061726220,0x343337355f365f74\n"
".quad 0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562,0x333732355f365f74\n"
".quad 0x09636f6c2e090a38,0x0a30093932093831,0x3233732e64646109,0x2c35343172250920\n"
".quad 0x202c373331722520,0x2e766f6d090a3b31,0x3172250920323373,0x090a3b30202c3634\n"
".quad 0x203233732e627573,0x202c373431722509,0x0a3b31202c317225,0x656e2e7074657309\n"
".quad 0x702509203233732e,0x33317225202c3531,0x3734317225202c37,0x2e706c6573090a3b\n"
".quad 0x3172250920323373,0x34317225202c3834,0x3634317225202c35,0x0a3b35317025202c\n"
".quad 0x696e752e61726209,0x5f365f744c240920,0x240a3b3039303735,0x3337355f365f744c\n"
".quad 0x3c2f2f200a3a3634,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30313220656e696c,0x6c2064616568202c,0x242064656c656261,0x3732355f365f744c\n"
".quad 0x2e766f6d090a3833,0x3172250920323373,0x33317225202c3834,0x365f744c240a3b37\n"
".quad 0x0a3a30393037355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a38333732355f,0x203233732e766f6d,0x202c393431722509,0x090a3b3834317225\n"
".quad 0x09383109636f6c2e,0x6461090a30093033,0x2509203233732e64,0x7225202c30353172\n"
".quad 0x0a3b31202c363331,0x3233732e766f6d09,0x2c31353172250920,0x746573090a3b3020\n"
".quad 0x3233732e656e2e70,0x202c363170250920,0x25202c3833317225,0x73090a3b36333172\n"
".quad 0x203233732e706c65,0x202c323531722509,0x25202c3035317225,0x7025202c31353172\n"
".quad 0x766f6d090a3b3631,0x722509203233732e,0x317225202c333531,0x6f6c2e090a3b3235\n"
".quad 0x0931330938310963,0x6c2e6c756d090a30,0x2509203233732e6f,0x7225202c34353172\n"
".quad 0x317225202c313431,0x732e646461090a3b,0x3531722509203233,0x3834317225202c35\n"
".quad 0x3b3435317225202c,0x33752e646461090a,0x3635317225092032,0x202c35317225202c\n"
".quad 0x090a3b3535317225,0x61626f6c672e646c,0x7225092038732e6c,0x72255b202c373531\n"
".quad 0x0a3b5d302b363531,0x3233732e766f6d09,0x2c38353172250920,0x0a3b373531722520\n"
".quad 0x383109636f6c2e09,0x6d090a3009323309,0x33732e6f6c2e6c75,0x3935317225092032\n"
".quad 0x2c3633317225202c,0x61090a3b31722520,0x09203233732e6464,0x25202c3036317225\n"
".quad 0x7225202c39353172,0x6461090a3b373331,0x2509203233752e64,0x7225202c31363172\n"
".quad 0x317225202c303631,0x672e646c090a3b35,0x38732e6c61626f6c,0x2c32363172250920\n"
".quad 0x2b31363172255b20,0x766f6d090a3b5d30,0x722509203233732e,0x317225202c333631\n"
".quad 0x766f6d090a3b3236,0x722509203233732e,0x0a3b30202c343631,0x2e74672e74657309\n"
".quad 0x203233732e323375,0x202c353631722509,0x25202c3236317225,0x6e090a3b34363172\n"
".quad 0x09203233732e6765,0x25202c3636317225,0x6d090a3b35363172,0x09203233732e766f\n"
".quad 0x30202c3736317225,0x672e746573090a3b,0x33732e3233752e74,0x3836317225092032\n"
".quad 0x2c3735317225202c,0x0a3b373631722520,0x3233732e67656e09,0x2c39363172250920\n"
".quad 0x0a3b383631722520,0x3233622e646e6109,0x2c30373172250920,0x202c363631722520\n"
".quad 0x090a3b3936317225,0x203233752e766f6d,0x202c313731722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3731702509,0x7225202c30373172,0x2540090a3b313731\n"
".quad 0x2061726220373170,0x355f365f744c2409,0x2f200a3b38353837,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3031\n"
".quad 0x64656c6562616c20,0x355f365f744c2420,0x6c2e090a38333732,0x363309383109636f\n"
".quad 0x2e646461090a3009,0x3172250920323373,0x31377225202c3237,0x6873090a3b37202c\n"
".quad 0x2509203233732e72,0x7225202c33373172,0x090a3b32202c3335,0x752e6f6c2e6c756d\n"
".quad 0x3731722509203233,0x3337317225202c34,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x7225202c35373172,0x37317225202c3531,0x2e6c756d090a3b34,0x09203233752e6f6c\n"
".quad 0x25202c3637317225,0x3b34202c30363172,0x33752e646461090a,0x3737317225092032\n"
".quad 0x2c3537317225202c,0x0a3b363731722520,0x626f6c672e747309,0x09203233732e6c61\n"
".quad 0x302b37373172255b,0x3237317225202c5d,0x732e766f6d090a3b,0x3731722509203233\n"
".quad 0x62090a3b31202c38,0x0920696e752e6172,0x36355f365f744c24,0x744c240a3b383735\n"
".quad 0x38353837355f365f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38333732355f365f,0x33732e766f6d090a,0x3837317225092032,0x7262090a3b30202c\n"
".quad 0x240920696e752e61,0x3536355f365f744c,0x5f744c240a3b3837,0x3a34333836355f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c,0x0a38333732355f36\n"
".quad 0x3233732e766f6d09,0x2c38373172250920,0x5f744c240a3b3020,0x3a38373536355f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c,0x0a38333732355f36\n"
".quad 0x383109636f6c2e09,0x62090a3009393309,0x20636e79732e7261,0x766f6d090a3b3009\n"
".quad 0x722509203233732e,0x0a3b30202c393731,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x37317225202c3831,0x3937317225202c38,0x3170252140090a3b,0x2409206172622038\n"
".quad 0x3138355f365f744c,0x3c2f2f200a3b3431,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x636f6c2e090a3833,0x3009353409383109,0x33732e646461090a\n"
".quad 0x3038317225092032,0x202c31377225202c,0x2e646e61090a3b37,0x3172250920323362\n"
".quad 0x38317225202c3138,0x61090a3b31202c30,0x09203233622e646e,0x25202c3238317225\n"
".quad 0x3b31202c36333172,0x652e70746573090a,0x2509203233732e71,0x317225202c393170\n"
".quad 0x38317225202c3138,0x31702540090a3b32,0x2409206172622039,0x3231315f365f744c\n"
".quad 0x3c2f2f200a3b3636,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30313220656e696c,0x6c2064616568202c,0x242064656c656261,0x3732355f365f744c\n"
".quad 0x2e726873090a3833,0x3172250920323373,0x33357225202c3338,0x756d090a3b32202c\n"
".quad 0x3233752e6f6c2e6c,0x2c34383172250920,0x202c333831722520,0x2e646461090a3b34\n"
".quad 0x3172250920323375,0x38317225202c3538,0x3b35317225202c34,0x33732e766f6d090a\n"
".quad 0x3638317225092032,0x3b3934317225202c,0x33732e766f6d090a,0x3738317225092032\n"
".quad 0x3b3234317225202c,0x6f6c2e6c756d090a,0x722509203233732e,0x317225202c383831\n"
".quad 0x3b317225202c3738,0x33732e646461090a,0x3938317225092032,0x2c3638317225202c\n"
".quad 0x0a3b383831722520,0x2e6f6c2e6c756d09,0x3172250920323375,0x38317225202c3039\n"
".quad 0x61090a3b34202c39,0x09203233752e6464,0x25202c3139317225,0x7225202c35383172\n"
".quad 0x646c090a3b303931,0x2e6c61626f6c672e,0x3172250920323373,0x3172255b202c3239\n"
".quad 0x090a3b5d302b3139,0x2e71652e70746573,0x3270250920323373,0x3239317225202c30\n"
".quad 0x3b3038317225202c,0x203032702540090a,0x744c240920617262,0x36323431375f365f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30313220656e,0x62616c2064616568,0x744c242064656c65,0x38333732355f365f\n"
".quad 0x33732e766f6d090a,0x3339317225092032,0x3b3335317225202c,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x317225202c343931,0x3b317225202c3339,0x33732e646461090a\n"
".quad 0x3539317225092032,0x2c3439317225202c,0x6d090a3b31722520,0x33752e6f6c2e6c75\n"
".quad 0x3639317225092032,0x2c3539317225202c,0x627573090a3b3420,0x722509203233752e\n"
".quad 0x317225202c373931,0x090a3b34202c3639,0x203233732e646461,0x202c383931722509\n"
".quad 0x25202c3439317225,0x6d090a3b36383172,0x33752e6f6c2e6c75,0x3939317225092032\n"
".quad 0x2c3839317225202c,0x627573090a3b3420,0x722509203233752e,0x317225202c303032\n"
".quad 0x090a3b34202c3939,0x203233732e766f6d,0x202c313032722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3132702509,0x7225202c36383172,0x6573090a3b313032\n"
".quad 0x09203233752e706c,0x25202c3230327225,0x7225202c37393172,0x327025202c303032\n"
".quad 0x2e646461090a3b31,0x3272250920323375,0x30327225202c3330,0x3538317225202c32\n"
".quad 0x6c672e646c090a3b,0x3233732e6c61626f,0x2c34303272250920,0x2b33303272255b20\n"
".quad 0x746573090a3b5d30,0x3233732e71652e70,0x202c323270250920,0x25202c3430327225\n"
".quad 0x40090a3b30383172,0x6172622032327025,0x5f365f744c240920,0x240a3b3632343137\n"
".quad 0x3231315f365f744c,0x3c2f2f200a3a3636,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x2e766f6d090a3833,0x3272250920323373,0x090a3b31202c3530\n"
".quad 0x20696e752e617262,0x315f365f744c2409,0x4c240a3b32303832,0x323431375f365f74\n"
".quad 0x365f744c240a3a36,0x0a3a32323531315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461\n"
".quad 0x365f744c24206465,0x090a38333732355f,0x203233732e766f6d,0x202c353032722509\n"
".quad 0x365f744c240a3b30,0x0a3a32303832315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461\n"
".quad 0x365f744c24206465,0x090a38333732355f,0x203233732e766f6d,0x202c363032722509\n"
".quad 0x70746573090a3b30,0x203233732e656e2e,0x25202c3831702509,0x7225202c35303272\n"
".quad 0x744c240a3b363032,0x34313138355f365f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333732355f365f,0x383170252140090a,0x4c24092061726220\n"
".quad 0x323638355f365f74,0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333732355f365f74,0x09636f6c2e090a38,0x0a30093435093831,0x3233732e766f6d09\n"
".quad 0x2c37303272250920,0x0a3b383531722520,0x3233732e62757309,0x2c38303272250920\n"
".quad 0x202c373032722520,0x2e766f6d090a3b31,0x3272250920323373,0x34317225202c3930\n"
".quad 0x2e766f6d090a3b39,0x3272250920323373,0x34317225202c3031,0x2e6c756d090a3b32\n"
".quad 0x09203233732e6f6c,0x25202c3131327225,0x7225202c30313272,0x2e646461090a3b31\n"
".quad 0x3272250920323373,0x30327225202c3231,0x3131327225202c39,0x752e646461090a3b\n"
".quad 0x3132722509203233,0x2c35317225202c33,0x0a3b323132722520,0x626f6c672e747309\n"
".quad 0x5b092038732e6c61,0x5d302b3331327225,0x3b3830327225202c,0x3109636f6c2e090a\n"
".quad 0x090a300935350938,0x203233732e766f6d,0x202c343132722509,0x090a3b3336317225\n"
".quad 0x203233732e627573,0x202c353132722509,0x31202c3431327225,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x7225202c36313272,0x317225202c363331,0x732e646461090a3b\n"
".quad 0x3132722509203233,0x3733317225202c37,0x3b3631327225202c,0x33752e646461090a\n"
".quad 0x3831327225092032,0x202c35317225202c,0x090a3b3731327225,0x61626f6c672e7473\n"
".quad 0x255b092038732e6c,0x2c5d302b38313272,0x0a3b353132722520,0x38355f365f744c24\n"
".quad 0x2f2f200a3a363236,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x313220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x32355f365f744c24\n"
".quad 0x6f6c2e090a383337,0x0937350938310963,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x2038317025214009,0x744c240920617262,0x38333139355f365f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x38333732355f365f,0x3109636f6c2e090a\n"
".quad 0x090a300930360938,0x203233732e766f6d,0x202c393132722509,0x090a3b3335317225\n"
".quad 0x732e6f6c2e6c756d,0x3232722509203233,0x3931327225202c30,0x090a3b317225202c\n"
".quad 0x203233732e766f6d,0x202c313232722509,0x090a3b3934317225,0x203233732e646461\n"
".quad 0x202c323232722509,0x25202c3132327225,0x61090a3b30323272,0x09203233752e6464\n"
".quad 0x25202c3332327225,0x7225202c32323272,0x2e646c090a3b3531,0x732e6c61626f6c67\n"
".quad 0x3432327225092038,0x33323272255b202c,0x6461090a3b5d302b,0x2509203233732e64\n"
".quad 0x7225202c35323272,0x0a3b31202c343232,0x626f6c672e747309,0x5b092038732e6c61\n"
".quad 0x5d302b3332327225,0x3b3532327225202c,0x3109636f6c2e090a,0x090a300931360938\n"
".quad 0x203233732e627573,0x202c363232722509,0x0a3b31202c317225,0x2e6f6c2e6c756d09\n"
".quad 0x3272250920323373,0x33317225202c3732,0x0a3b317225202c36,0x656e2e7074657309\n"
".quad 0x702509203233732e,0x32327225202c3332,0x3733317225202c36,0x732e646461090a3b\n"
".quad 0x3631722509203233,0x3732327225202c30,0x3b3733317225202c,0x33752e646461090a\n"
".quad 0x3832327225092032,0x2c3036317225202c,0x6c6573090a3b3120,0x2509203233752e70\n"
".quad 0x7225202c39323272,0x327225202c383232,0x33327025202c3732,0x752e646461090a3b\n"
".quad 0x3332722509203233,0x3932327225202c30,0x0a3b35317225202c,0x626f6c672e646c09\n"
".quad 0x25092038732e6c61,0x255b202c31333272,0x3b5d302b30333272,0x33732e646461090a\n"
".quad 0x3233327225092032,0x2c3133327225202c,0x2e7473090a3b3120,0x732e6c61626f6c67\n"
".quad 0x333272255b092038,0x7225202c5d302b30,0x744c240a3b323332,0x38333139355f365f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30313220656e,0x62616c2064616568,0x744c242064656c65,0x38333732355f365f\n"
".quad 0x3109636f6c2e090a,0x090a300933360938,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x303109383109636f,0x2e646c090a300935,0x752e646572616873,0x3332722509203233\n"
".quad 0x393672255b202c33,0x0a3b5d343230312b,0x3233752e6d657209,0x2c34333272250920\n"
".quad 0x202c333332722520,0x6d090a3b33357225,0x09203233732e766f,0x25202c3533327225\n"
".quad 0x2e090a3b34333272,0x3109383109636f6c,0x6964090a30093630,0x2509203233732e76\n"
".quad 0x7225202c36333272,0x317225202c343332,0x732e6d6572090a3b,0x3332722509203233\n"
".quad 0x3433327225202c37,0x090a3b317225202c,0x7262203970252140,0x365f744c24092061\n"
".quad 0x0a3b36303939355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a38333732355f,0x09383109636f6c2e,0x7573090a30093832,0x2509203233732e62\n"
".quad 0x7225202c38333172,0x090a3b31202c3235,0x203233732e766f6d,0x202c383332722509\n"
".quad 0x70746573090a3b30,0x203233732e71652e,0x25202c3432702509,0x7225202c36333272\n"
".quad 0x7573090a3b383332,0x2509203233732e62,0x7225202c39333272,0x0a3b31202c363332\n"
".quad 0x33732e706c657309,0x3034327225092032,0x2c3833317225202c,0x202c393332722520\n"
".quad 0x6d090a3b34327025,0x09203233732e766f,0x25202c3234317225,0x61090a3b30343272\n"
".quad 0x09203233622e646e,0x25202c3134327225,0x3b31202c36333272,0x33752e766f6d090a\n"
".quad 0x3234327225092032,0x6573090a3b30202c,0x33732e71652e7074,0x2c35327025092032\n"
".quad 0x202c313432722520,0x090a3b3234327225,0x7262203532702540,0x365f744c24092061\n"
".quad 0x0a3b38313430365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a38333732355f,0x09383109636f6c2e,0x6461090a30093932,0x2509203233732e64\n"
".quad 0x7225202c33343272,0x0a3b31202c373332,0x3233732e766f6d09,0x2c34343272250920\n"
".quad 0x627573090a3b3020,0x722509203233732e,0x317225202c353432,0x6573090a3b31202c\n"
".quad 0x33732e656e2e7074,0x2c36327025092032,0x202c373332722520,0x090a3b3534327225\n"
".quad 0x3233732e706c6573,0x2c36343272250920,0x202c333432722520,0x25202c3434327225\n"
".quad 0x7262090a3b363270,0x240920696e752e61,0x3130365f365f744c,0x5f744c240a3b3236\n"
".quad 0x3a38313430365f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333732355f36,0x3233732e766f6d09,0x2c36343272250920,0x0a3b373332722520\n"
".quad 0x30365f365f744c24,0x2f2f200a3a323631,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x313220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x32355f365f744c24,0x766f6d090a383337,0x722509203233732e,0x327225202c393431\n"
".quad 0x6f6c2e090a3b3634,0x0930330938310963,0x732e646461090a30,0x3432722509203233\n"
".quad 0x3633327225202c37,0x6f6d090a3b31202c,0x2509203233732e76,0x3b30202c38343272\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x327225202c373270,0x33317225202c3633\n"
".quad 0x706c6573090a3b38,0x722509203233732e,0x327225202c393432,0x34327225202c3734\n"
".quad 0x3b37327025202c38,0x33732e766f6d090a,0x3335317225092032,0x3b3934327225202c\n"
".quad 0x3109636f6c2e090a,0x090a300931330938,0x732e6f6c2e6c756d,0x3532722509203233\n"
".quad 0x3034327225202c30,0x090a3b317225202c,0x203233732e646461,0x202c313532722509\n"
".quad 0x25202c3634327225,0x61090a3b30353272,0x09203233752e6464,0x25202c3235327225\n"
".quad 0x327225202c353172,0x2e646c090a3b3135,0x732e6c61626f6c67,0x3735317225092038\n"
".quad 0x32353272255b202c,0x6f6d090a3b5d302b,0x2509203233732e76,0x7225202c38353172\n"
".quad 0x6c2e090a3b373531,0x323309383109636f,0x2e6c756d090a3009,0x09203233732e6f6c\n"
".quad 0x25202c3335327225,0x7225202c36333272,0x2e646461090a3b31,0x3272250920323373\n"
".quad 0x35327225202c3435,0x3733327225202c33,0x752e646461090a3b,0x3532722509203233\n"
".quad 0x3435327225202c35,0x0a3b35317225202c,0x626f6c672e646c09,0x25092038732e6c61\n"
".quad 0x255b202c32363172,0x3b5d302b35353272,0x33732e766f6d090a,0x3336317225092032\n"
".quad 0x3b3236317225202c,0x33732e766f6d090a,0x3635327225092032,0x6573090a3b30202c\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x317225202c373532,0x35327225202c3236\n"
".quad 0x2e67656e090a3b36,0x3272250920323373,0x35327225202c3835,0x2e766f6d090a3b37\n"
".quad 0x3272250920323373,0x090a3b30202c3935,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x25202c3036327225,0x7225202c37353172,0x656e090a3b393532,0x2509203233732e67\n"
".quad 0x7225202c31363272,0x6e61090a3b303632,0x2509203233622e64,0x7225202c32363272\n"
".quad 0x327225202c383532,0x766f6d090a3b3136,0x722509203233752e,0x0a3b30202c333632\n"
".quad 0x71652e7074657309,0x702509203233732e,0x36327225202c3832,0x3336327225202c32\n"
".quad 0x3832702540090a3b,0x4c24092061726220,0x333930365f365f74,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30313220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333732355f365f74,0x09636f6c2e090a38\n"
".quad 0x0a30093633093831,0x3233732e64646109,0x2c34363272250920,0x31202c3137722520\n"
".quad 0x2e726873090a3b31,0x3272250920323373,0x33357225202c3536,0x756d090a3b32202c\n"
".quad 0x3233752e6f6c2e6c,0x2c36363272250920,0x202c353632722520,0x2e646461090a3b34\n"
".quad 0x3272250920323375,0x35317225202c3736,0x3b3636327225202c,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x327225202c383632,0x090a3b34202c3435,0x203233752e646461\n"
".quad 0x202c393632722509,0x25202c3736327225,0x73090a3b38363272,0x6c61626f6c672e74\n"
".quad 0x255b09203233732e,0x2c5d302b39363272,0x0a3b343632722520,0x3233732e766f6d09\n"
".quad 0x2c38373172250920,0x617262090a3b3120,0x4c240920696e752e,0x353639355f365f74\n"
".quad 0x365f744c240a3b30,0x0a3a30333930365f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220,0x6c6562616c206461\n"
".quad 0x365f744c24206465,0x090a38333732355f,0x203233732e766f6d,0x202c383731722509\n"
".quad 0x2e617262090a3b30,0x744c240920696e75,0x30353639355f365f,0x5f365f744c240a3b\n"
".quad 0x200a3a3630393935,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303132,0x656c6562616c2064,0x5f365f744c242064\n"
".quad 0x6d090a3833373235,0x09203233732e766f,0x30202c3837317225,0x5f365f744c240a3b\n"
".quad 0x200a3a3035363935,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303132,0x656c6562616c2064,0x5f365f744c242064\n"
".quad 0x2e090a3833373235,0x3309383109636f6c,0x726162090a300939,0x300920636e79732e\n"
".quad 0x732e766f6d090a3b,0x3732722509203233,0x73090a3b30202c30,0x732e656e2e707465\n"
".quad 0x3831702509203233,0x2c3837317225202c,0x0a3b303732722520,0x2038317025214009\n"
".quad 0x744c240920617262,0x36383131365f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333732355f365f,0x3109636f6c2e090a,0x090a300935340938\n"
".quad 0x203233732e646461,0x202c313732722509,0x3131202c31377225,0x622e646e61090a3b\n"
".quad 0x3732722509203233,0x3137327225202c32,0x6e61090a3b31202c,0x2509203233622e64\n"
".quad 0x7225202c33373272,0x0a3b31202c363332,0x71652e7074657309,0x702509203233732e\n"
".quad 0x37327225202c3932,0x3337327225202c32,0x3932702540090a3b,0x4c24092061726220\n"
".quad 0x333438315f365f74,0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333732355f365f74,0x732e726873090a38,0x3831722509203233,0x2c33357225202c33\n"
".quad 0x6c756d090a3b3220,0x203233752e6f6c2e,0x202c343831722509,0x34202c3338317225\n"
".quad 0x752e646461090a3b,0x3831722509203233,0x3438317225202c35,0x0a3b35317225202c\n"
".quad 0x3233732e766f6d09,0x2c36383172250920,0x0a3b393431722520,0x3233732e766f6d09\n"
".quad 0x2c34373272250920,0x0a3b323431722520,0x2e6f6c2e6c756d09,0x3272250920323373\n"
".quad 0x37327225202c3537,0x0a3b317225202c34,0x3233732e64646109,0x2c36373272250920\n"
".quad 0x202c363831722520,0x090a3b3537327225,0x752e6f6c2e6c756d,0x3732722509203233\n"
".quad 0x3637327225202c37,0x6461090a3b34202c,0x2509203233752e64,0x7225202c38373272\n"
".quad 0x327225202c353831,0x2e646c090a3b3737,0x732e6c61626f6c67,0x3732722509203233\n"
".quad 0x373272255b202c39,0x73090a3b5d302b38,0x732e71652e707465,0x3033702509203233\n"
".quad 0x2c3937327225202c,0x0a3b313732722520,0x6220303370254009,0x5f744c2409206172\n"
".quad 0x3b34393132375f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333732355f36,0x3233732e766f6d09,0x2c30383272250920,0x0a3b333531722520\n"
".quad 0x2e6f6c2e6c756d09,0x3272250920323373,0x38327225202c3138,0x0a3b317225202c30\n"
".quad 0x3233732e64646109,0x2c32383272250920,0x202c313832722520,0x756d090a3b317225\n"
".quad 0x3233752e6f6c2e6c,0x2c33383272250920,0x202c323832722520,0x2e627573090a3b34\n"
".quad 0x3272250920323375,0x38327225202c3438,0x61090a3b34202c33,0x09203233732e6464\n"
".quad 0x25202c3538327225,0x7225202c31383272,0x756d090a3b363831,0x3233752e6f6c2e6c\n"
".quad 0x2c36383272250920,0x202c353832722520,0x2e627573090a3b34,0x3272250920323375\n"
".quad 0x38327225202c3738,0x6d090a3b34202c36,0x09203233732e766f,0x30202c3838327225\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x7225202c31337025,0x327225202c363831\n"
".quad 0x6c6573090a3b3838,0x2509203233752e70,0x7225202c39383272,0x327225202c343832\n"
".quad 0x31337025202c3738,0x752e646461090a3b,0x3932722509203233,0x3938327225202c30\n"
".quad 0x3b3538317225202c,0x6f6c672e646c090a,0x203233732e6c6162,0x202c313932722509\n"
".quad 0x302b30393272255b,0x70746573090a3b5d,0x203233732e71652e,0x25202c3233702509\n"
".quad 0x7225202c31393272,0x2540090a3b313732,0x2061726220323370,0x375f365f744c2409\n"
".quad 0x4c240a3b34393132,0x333438315f365f74,0x6c3c2f2f200a3a34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333732355f365f74,0x732e766f6d090a38,0x3932722509203233\n"
".quad 0x62090a3b31202c32,0x0920696e752e6172,0x39315f365f744c24,0x744c240a3b303739\n"
".quad 0x34393132375f365f,0x5f365f744c240a3a,0x200a3a3039363831,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c303132\n"
".quad 0x656c6562616c2064,0x5f365f744c242064,0x6d090a3833373235,0x09203233732e766f\n"
".quad 0x30202c3239327225,0x5f365f744c240a3b,0x200a3a3037393931,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c303132\n"
".quad 0x656c6562616c2064,0x5f365f744c242064,0x6d090a3833373235,0x09203233732e766f\n"
".quad 0x30202c3339327225,0x2e70746573090a3b,0x09203233732e656e,0x7225202c38317025\n"
".quad 0x327225202c323932,0x5f744c240a3b3339,0x3a36383131365f36,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3031322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38333732355f36,0x2038317025214009\n"
".quad 0x744c240920617262,0x38393631365f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333732355f365f,0x3109636f6c2e090a,0x090a300934350938\n"
".quad 0x203233732e766f6d,0x202c343932722509,0x090a3b3835317225,0x203233732e627573\n"
".quad 0x202c353932722509,0x31202c3439327225,0x732e766f6d090a3b,0x3932722509203233\n"
".quad 0x3934317225202c36,0x732e766f6d090a3b,0x3932722509203233,0x3234317225202c37\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c38393272,0x317225202c373932\n"
".quad 0x732e646461090a3b,0x3932722509203233,0x3639327225202c39,0x3b3839327225202c\n"
".quad 0x33752e646461090a,0x3030337225092032,0x202c35317225202c,0x090a3b3939327225\n"
".quad 0x61626f6c672e7473,0x255b092038732e6c,0x2c5d302b30303372,0x0a3b353932722520\n"
".quad 0x383109636f6c2e09,0x6d090a3009353509,0x09203233732e766f,0x25202c3130337225\n"
".quad 0x73090a3b33363172,0x09203233732e6275,0x25202c3230337225,0x3b31202c31303372\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x327225202c333033,0x3b317225202c3633\n"
".quad 0x33732e646461090a,0x3430337225092032,0x2c3733327225202c,0x0a3b333033722520\n"
".quad 0x3233752e64646109,0x2c35303372250920,0x25202c3531722520,0x73090a3b34303372\n"
".quad 0x6c61626f6c672e74,0x72255b092038732e,0x202c5d302b353033,0x240a3b3230337225\n"
".quad 0x3631365f365f744c,0x3c2f2f200a3a3839,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x636f6c2e090a3833,0x3009373509383109,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x6220383170252140,0x5f744c2409206172,0x3b30313232365f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c,0x0a38333732355f36\n"
".quad 0x383109636f6c2e09,0x6d090a3009303609,0x09203233732e766f,0x25202c3630337225\n"
".quad 0x6d090a3b33353172,0x33732e6f6c2e6c75,0x3730337225092032,0x2c3630337225202c\n"
".quad 0x6d090a3b31722520,0x09203233732e766f,0x25202c3830337225,0x61090a3b39343172\n"
".quad 0x09203233732e6464,0x25202c3930337225,0x7225202c38303372,0x6461090a3b373033\n"
".quad 0x2509203233752e64,0x7225202c33323272,0x317225202c393033,0x672e646c090a3b35\n"
".quad 0x38732e6c61626f6c,0x2c30313372250920,0x2b33323272255b20,0x646461090a3b5d30\n"
".quad 0x722509203233732e,0x337225202c313133,0x090a3b31202c3031,0x61626f6c672e7473\n"
".quad 0x255b092038732e6c,0x2c5d302b33323272,0x0a3b313133722520,0x383109636f6c2e09\n"
".quad 0x73090a3009313609,0x09203233732e6275,0x25202c3632327225,0x090a3b31202c3172\n"
".quad 0x732e6f6c2e6c756d,0x3133722509203233,0x3633327225202c32,0x090a3b317225202c\n"
".quad 0x2e656e2e70746573,0x3370250920323373,0x3733327225202c33,0x3b3632327225202c\n"
".quad 0x33732e646461090a,0x3435327225092032,0x2c3231337225202c,0x0a3b373332722520\n"
".quad 0x3233752e64646109,0x2c33313372250920,0x202c343532722520,0x706c6573090a3b31\n"
".quad 0x722509203233752e,0x337225202c343133,0x31337225202c3331,0x3b33337025202c32\n"
".quad 0x33752e646461090a,0x3531337225092032,0x2c3431337225202c,0x090a3b3531722520\n"
".quad 0x61626f6c672e646c,0x7225092038732e6c,0x72255b202c363133,0x0a3b5d302b353133\n"
".quad 0x3233732e64646109,0x2c37313372250920,0x202c363133722520,0x672e7473090a3b31\n"
".quad 0x38732e6c61626f6c,0x35313372255b0920,0x337225202c5d302b,0x5f744c240a3b3731\n"
".quad 0x3a30313232365f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333732355f36,0x383109636f6c2e09,0x62090a3009333609,0x20636e79732e7261\n"
".quad 0x6f6c2e090a3b3009,0x3630310938310963,0x70252140090a3009,0x0920617262203031\n"
".quad 0x32365f365f744c24,0x2f2f200a3b323237,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x313220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x32355f365f744c24,0x6f6c2e090a383337,0x3231310938310963,0x732e646c090a3009\n"
".quad 0x33752e6465726168,0x3831337225092032,0x2b393672255b202c,0x090a3b5d38343032\n"
".quad 0x203233752e6d6572,0x202c353332722509,0x25202c3831337225,0x744c240a3b333572\n"
".quad 0x32323732365f365f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38333732355f365f,0x3109636f6c2e090a,0x0a30093431310938,0x2031317025214009\n"
".quad 0x744c240920617262,0x30393433365f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333732355f365f,0x3109636f6c2e090a,0x090a300938320938\n"
".quad 0x203233732e766964,0x202c393133722509,0x25202c3533327225,0x627573090a3b3172\n"
".quad 0x722509203233732e,0x357225202c383331,0x6d090a3b31202c32,0x09203233732e766f\n"
".quad 0x30202c3032337225,0x2e70746573090a3b,0x09203233732e7165,0x7225202c34337025\n"
".quad 0x337225202c393133,0x627573090a3b3032,0x722509203233732e,0x337225202c313233\n"
".quad 0x090a3b31202c3931,0x3233732e706c6573,0x2c32323372250920,0x202c383331722520\n"
".quad 0x25202c3132337225,0x6f6d090a3b343370,0x2509203233732e76,0x7225202c32343172\n"
".quad 0x6572090a3b323233,0x2509203233732e6d,0x7225202c33323372,0x317225202c353332\n"
".quad 0x622e646e61090a3b,0x3233722509203233,0x3931337225202c34,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x3b30202c35323372,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x337225202c353370,0x32337225202c3432,0x33702540090a3b35,0x2409206172622035\n"
".quad 0x3034365f365f744c,0x3c2f2f200a3b3230,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x636f6c2e090a3833,0x3009393209383109,0x33732e646461090a\n"
".quad 0x3632337225092032,0x2c3332337225202c,0x766f6d090a3b3120,0x722509203233732e\n"
".quad 0x0a3b30202c373233,0x3233732e62757309,0x2c38323372250920,0x3b31202c31722520\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x337225202c363370,0x32337225202c3332\n"
".quad 0x706c6573090a3b38,0x722509203233732e,0x337225202c393233,0x32337225202c3632\n"
".quad 0x3b36337025202c37,0x6e752e617262090a,0x365f744c24092069,0x0a3b36343733365f\n"
".quad 0x34365f365f744c24,0x2f2f200a3a323030,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x313220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x32355f365f744c24,0x766f6d090a383337,0x722509203233732e,0x337225202c393233\n"
".quad 0x5f744c240a3b3332,0x3a36343733365f36,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3031322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a38333732355f36,0x3233732e766f6d09,0x2c39343172250920\n"
".quad 0x0a3b393233722520,0x383109636f6c2e09,0x61090a3009303309,0x09203233732e6464\n"
".quad 0x25202c3033337225,0x3b31202c39313372,0x33732e766f6d090a,0x3133337225092032\n"
".quad 0x6573090a3b30202c,0x33732e656e2e7074,0x2c37337025092032,0x202c393133722520\n"
".quad 0x090a3b3833317225,0x3233732e706c6573,0x2c32333372250920,0x202c303333722520\n"
".quad 0x25202c3133337225,0x6f6d090a3b373370,0x2509203233732e76,0x7225202c33353172\n"
".quad 0x6c2e090a3b323333,0x313309383109636f,0x2e6c756d090a3009,0x09203233732e6f6c\n"
".quad 0x25202c3333337225,0x7225202c32323372,0x2e646461090a3b31,0x3372250920323373\n"
".quad 0x32337225202c3433,0x3333337225202c39,0x752e646461090a3b,0x3333722509203233\n"
".quad 0x2c35317225202c35,0x0a3b343333722520,0x626f6c672e646c09,0x25092038732e6c61\n"
".quad 0x255b202c37353172,0x3b5d302b35333372,0x33732e766f6d090a,0x3835317225092032\n"
".quad 0x3b3735317225202c,0x3109636f6c2e090a,0x090a300932330938,0x732e6f6c2e6c756d\n"
".quad 0x3333722509203233,0x3931337225202c36,0x090a3b317225202c,0x203233732e646461\n"
".quad 0x202c373333722509,0x25202c3633337225,0x61090a3b33323372,0x09203233752e6464\n"
".quad 0x25202c3833337225,0x7225202c37333372,0x2e646c090a3b3531,0x732e6c61626f6c67\n"
".quad 0x3236317225092038,0x38333372255b202c,0x6f6d090a3b5d302b,0x2509203233732e76\n"
".quad 0x7225202c33363172,0x6f6d090a3b323631,0x2509203233732e76,0x3b30202c39333372\n"
".quad 0x74672e746573090a,0x3233732e3233752e,0x2c30343372250920,0x202c323631722520\n"
".quad 0x090a3b3933337225,0x203233732e67656e,0x202c313433722509,0x090a3b3034337225\n"
".quad 0x203233732e766f6d,0x202c323433722509,0x2e746573090a3b30,0x732e3233752e7467\n"
".quad 0x3433722509203233,0x3735317225202c33,0x3b3234337225202c,0x33732e67656e090a\n"
".quad 0x3434337225092032,0x3b3334337225202c,0x33622e646e61090a,0x3534337225092032\n"
".quad 0x2c3134337225202c,0x0a3b343433722520,0x3233752e766f6d09,0x2c36343372250920\n"
".quad 0x746573090a3b3020,0x3233732e71652e70,0x202c383370250920,0x25202c3534337225\n"
".quad 0x40090a3b36343372,0x6172622038337025,0x5f365f744c240920,0x200a3b3431353436\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c303132,0x656c6562616c2064,0x5f365f744c242064,0x2e090a3833373235\n"
".quad 0x3309383109636f6c,0x646461090a300936,0x722509203233732e,0x377225202c373433\n"
".quad 0x090a3b3331202c31,0x203233732e726873,0x202c383433722509,0x3b32202c33357225\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x337225202c393433,0x090a3b34202c3834\n"
".quad 0x203233752e646461,0x202c303533722509,0x7225202c35317225,0x756d090a3b393433\n"
".quad 0x3233752e6f6c2e6c,0x2c31353372250920,0x202c373333722520,0x2e646461090a3b34\n"
".quad 0x3372250920323375,0x35337225202c3235,0x3135337225202c30,0x6c672e7473090a3b\n"
".quad 0x3233732e6c61626f,0x32353372255b0920,0x337225202c5d302b,0x766f6d090a3b3734\n"
".quad 0x722509203233732e,0x0a3b31202c383731,0x696e752e61726209,0x5f365f744c240920\n"
".quad 0x240a3b3433323336,0x3534365f365f744c,0x3c2f2f200a3a3431,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3732355f365f744c,0x2e766f6d090a3833,0x3172250920323373\n"
".quad 0x090a3b30202c3837,0x20696e752e617262,0x365f365f744c2409,0x4c240a3b34333233\n"
".quad 0x393433365f365f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333732355f365f74,0x732e766f6d090a38,0x3731722509203233,0x4c240a3b30202c38\n"
".quad 0x333233365f365f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333732355f365f74,0x09636f6c2e090a38,0x0a30093933093831,0x6e79732e72616209\n"
".quad 0x6d090a3b30092063,0x09203233732e766f,0x30202c3335337225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c38317025,0x337225202c383731,0x252140090a3b3335\n"
".quad 0x2061726220383170,0x365f365f744c2409,0x2f200a3b30373734,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3031\n"
".quad 0x64656c6562616c20,0x355f365f744c2420,0x6c2e090a38333732,0x353409383109636f\n"
".quad 0x2e646461090a3009,0x3372250920323373,0x31377225202c3435,0x61090a3b3331202c\n"
".quad 0x09203233622e646e,0x25202c3535337225,0x3b31202c34353372,0x33732e766964090a\n"
".quad 0x3635337225092032,0x2c3533327225202c,0x61090a3b31722520,0x09203233622e646e\n"
".quad 0x25202c3735337225,0x3b31202c36353372,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x337225202c393370,0x35337225202c3535,0x33702540090a3b37,0x2409206172622039\n"
".quad 0x3136325f365f744c,0x3c2f2f200a3b3431,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3732355f365f744c,0x2e726873090a3833,0x3172250920323373,0x33357225202c3338\n"
".quad 0x756d090a3b32202c,0x3233752e6f6c2e6c,0x2c34383172250920,0x202c333831722520\n"
".quad 0x2e646461090a3b34,0x3172250920323375,0x38317225202c3538,0x3b35317225202c34\n"
".quad 0x33732e766f6d090a,0x3638317225092032,0x3b3934317225202c,0x33732e766f6d090a\n"
".quad 0x3835337225092032,0x3b3234317225202c,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x337225202c393533,0x3b317225202c3835,0x33732e646461090a,0x3036337225092032\n"
".quad 0x2c3638317225202c,0x0a3b393533722520,0x2e6f6c2e6c756d09,0x3372250920323375\n"
".quad 0x36337225202c3136,0x61090a3b34202c30,0x09203233752e6464,0x25202c3236337225\n"
".quad 0x7225202c35383172,0x646c090a3b313633,0x2e6c61626f6c672e,0x3372250920323373\n"
".quad 0x3372255b202c3336,0x090a3b5d302b3236,0x2e71652e70746573,0x3470250920323373\n"
".quad 0x3336337225202c30,0x3b3435337225202c,0x203034702540090a,0x744c240920617262\n"
".quad 0x32363932375f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c30313220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38333732355f365f,0x33732e766f6d090a,0x3436337225092032,0x3b3335317225202c\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x337225202c353633,0x3b317225202c3436\n"
".quad 0x33732e646461090a,0x3636337225092032,0x2c3536337225202c,0x6d090a3b31722520\n"
".quad 0x33752e6f6c2e6c75,0x3736337225092032,0x2c3636337225202c,0x627573090a3b3420\n"
".quad 0x722509203233752e,0x337225202c383633,0x090a3b34202c3736,0x203233732e646461\n"
".quad 0x202c393633722509,0x25202c3536337225,0x6d090a3b36383172,0x33752e6f6c2e6c75\n"
".quad 0x3037337225092032,0x2c3936337225202c,0x627573090a3b3420,0x722509203233752e\n"
".quad 0x337225202c313733,0x090a3b34202c3037,0x203233732e766f6d,0x202c323733722509\n"
".quad 0x70746573090a3b30,0x203233732e71652e,0x25202c3134702509,0x7225202c36383172\n"
".quad 0x6573090a3b323733,0x09203233752e706c,0x25202c3337337225,0x7225202c38363372\n"
".quad 0x347025202c313733,0x2e646461090a3b31,0x3372250920323375,0x37337225202c3437\n"
".quad 0x3538317225202c33,0x6c672e646c090a3b,0x3233732e6c61626f,0x2c35373372250920\n"
".quad 0x2b34373372255b20,0x746573090a3b5d30,0x3233732e71652e70,0x202c323470250920\n"
".quad 0x25202c3537337225,0x40090a3b34353372,0x6172622032347025,0x5f365f744c240920\n"
".quad 0x240a3b3236393237,0x3136325f365f744c,0x3c2f2f200a3a3431,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3732355f365f744c,0x2e766f6d090a3833,0x3372250920323373\n"
".quad 0x090a3b31202c3637,0x20696e752e617262,0x325f365f744c2409,0x4c240a3b30353637\n"
".quad 0x363932375f365f74,0x365f744c240a3a32,0x0a3a30373336325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220\n"
".quad 0x6c6562616c206461,0x365f744c24206465,0x090a38333732355f,0x203233732e766f6d\n"
".quad 0x202c363733722509,0x365f744c240a3b30,0x0a3a30353637325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30313220\n"
".quad 0x6c6562616c206461,0x365f744c24206465,0x090a38333732355f,0x203233732e766f6d\n"
".quad 0x202c373733722509,0x70746573090a3b30,0x203233732e656e2e,0x25202c3831702509\n"
".quad 0x7225202c36373372,0x744c240a3b373733,0x30373734365f365f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30313220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x38333732355f365f,0x383170252140090a\n"
".quad 0x4c24092061726220,0x383235365f365f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30313220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333732355f365f74,0x09636f6c2e090a38,0x0a30093435093831\n"
".quad 0x3233732e766f6d09,0x2c38373372250920,0x0a3b383531722520,0x3233732e62757309\n"
".quad 0x2c39373372250920,0x202c383733722520,0x2e766f6d090a3b31,0x3372250920323373\n"
".quad 0x34317225202c3038,0x2e766f6d090a3b39,0x3372250920323373,0x34317225202c3138\n"
".quad 0x2e6c756d090a3b32,0x09203233732e6f6c,0x25202c3238337225,0x7225202c31383372\n"
".quad 0x2e646461090a3b31,0x3372250920323373,0x38337225202c3338,0x3238337225202c30\n"
".quad 0x752e646461090a3b,0x3833722509203233,0x2c35317225202c34,0x0a3b333833722520\n"
".quad 0x626f6c672e747309,0x5b092038732e6c61,0x5d302b3438337225,0x3b3937337225202c\n"
".quad 0x3109636f6c2e090a,0x090a300935350938,0x203233732e766f6d,0x202c353833722509\n"
".quad 0x090a3b3336317225,0x203233732e627573,0x202c363833722509,0x31202c3538337225\n"
".quad 0x732e766964090a3b,0x3833722509203233,0x3533327225202c37,0x090a3b317225202c\n"
".quad 0x732e6f6c2e6c756d,0x3833722509203233,0x202c317225202c38,0x090a3b3738337225\n"
".quad 0x203233732e6d6572,0x202c393833722509,0x25202c3533327225,0x646461090a3b3172\n"
".quad 0x722509203233732e,0x337225202c303933,0x38337225202c3838,0x2e646461090a3b39\n"
".quad 0x3372250920323375,0x35317225202c3139,0x3b3039337225202c,0x6f6c672e7473090a\n"
".quad 0x092038732e6c6162,0x302b31393372255b,0x3638337225202c5d,0x5f365f744c240a3b\n"
".quad 0x200a3a3238323536,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303132,0x656c6562616c2064,0x5f365f744c242064\n"
".quad 0x2e090a3833373235,0x3509383109636f6c,0x726162090a300937,0x300920636e79732e\n"
".quad 0x3170252140090a3b,0x2409206172622038,0x3735365f365f744c,0x3c2f2f200a3b3439\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30313220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3732355f365f744c,0x636f6c2e090a3833\n"
".quad 0x3009303609383109,0x33732e766f6d090a,0x3239337225092032,0x3b3335317225202c\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x337225202c333933,0x3b317225202c3239\n"
".quad 0x33732e766f6d090a,0x3439337225092032,0x3b3934317225202c,0x33732e646461090a\n"
".quad 0x3539337225092032,0x2c3439337225202c,0x0a3b333933722520,0x3233752e64646109\n"
".quad 0x2c33323272250920,0x202c353933722520,0x6c090a3b35317225,0x6c61626f6c672e64\n"
".quad 0x337225092038732e,0x3272255b202c3639,0x090a3b5d302b3332,0x203233732e646461\n"
".quad 0x202c373933722509,0x31202c3639337225,0x6c672e7473090a3b,0x2038732e6c61626f\n"
".quad 0x2b33323272255b09,0x39337225202c5d30,0x636f6c2e090a3b37,0x3009313609383109\n"
".quad 0x33732e6d6572090a,0x3332337225092032,0x2c3533327225202c,0x73090a3b31722520\n"
".quad 0x09203233732e6275,0x25202c3632327225,0x090a3b31202c3172,0x203233732e766964\n"
".quad 0x202c393133722509,0x25202c3533327225,0x746573090a3b3172,0x3233732e656e2e70\n"
".quad 0x202c333470250920,0x25202c3332337225,0x6d090a3b36323272,0x33732e6f6c2e6c75\n"
".quad 0x3839337225092032,0x2c3931337225202c,0x61090a3b31722520,0x09203233732e6464\n"
".quad 0x25202c3733337225,0x7225202c38393372,0x6461090a3b333233,0x2509203233752e64\n"
".quad 0x7225202c39393372,0x0a3b31202c373333,0x33752e706c657309,0x3030347225092032\n"
".quad 0x2c3939337225202c,0x202c383933722520,0x61090a3b33347025,0x09203233752e6464\n"
".quad 0x25202c3130347225,0x7225202c30303472,0x2e646c090a3b3531,0x732e6c61626f6c67\n"
".quad 0x3230347225092038,0x31303472255b202c,0x6461090a3b5d302b,0x2509203233732e64\n"
".quad 0x7225202c33303472,0x0a3b31202c323034,0x626f6c672e747309,0x5b092038732e6c61\n"
".quad 0x5d302b3130347225,0x3b3330347225202c,0x365f365f744c240a,0x2f200a3a34393735\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3031,0x64656c6562616c20,0x355f365f744c2420,0x6c2e090a38333732\n"
".quad 0x333609383109636f,0x2e726162090a3009,0x3b300920636e7973,0x3109636f6c2e090a\n"
".quad 0x0a30093431310938,0x3233732e64646109,0x202c313772250920,0x3133202c31377225\n"
".quad 0x70746573090a3b32,0x203233732e74672e,0x25202c3434702509,0x377225202c383472\n"
".quad 0x34702540090a3b31,0x2409206172622034,0x3732355f365f744c,0x617262090a3b3833\n"
".quad 0x4c240920696e752e,0x323232355f365f74,0x365f744c240a3b36,0x0a3a34313930375f\n"
".quad 0x3233752e64646109,0x202c393672250920,0x337225202c387225,0x365f744c240a3b36\n"
".quad 0x0a3a36323232355f,0x383109636f6c2e09,0x090a300931313209,0x203233732e627573\n"
".quad 0x202c343034722509,0x0a3b31202c347225,0x3233752e766f6d09,0x2c35303472250920\n"
".quad 0x746573090a3b3020,0x3233732e746c2e70,0x202c353470250920,0x25202c3430347225\n"
".quad 0x40090a3b35303472,0x6172622035347025,0x5f365f744c240920,0x090a3b3437343337\n"
".quad 0x203233732e766f6d,0x202c363034722509,0x6461090a3b347225,0x2509203233732e64\n"
".quad 0x337225202c303172,0x090a3b397225202c,0x203233752e766f6d,0x202c373034722509\n"
".quad 0x782e646961746325,0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c323172\n"
".quad 0x3730347225202c30,0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c333172\n"
".quad 0x6c090a3b34202c32,0x2e6d617261702e64,0x3472250920323375,0x635f5f5b202c3830\n"
".quad 0x5f6d726170616475,0x7274655034315a5f,0x6e72654b74656e69,0x5f53665069506c65\n"
".quad 0x5d735f675f696969,0x752e646461090a3b,0x3531722509203233,0x2c3830347225202c\n"
".quad 0x090a3b3331722520,0x203233732e766f6d,0x202c393034722509,0x2e766f6d090a3b30\n"
".quad 0x3472250920323373,0x090a3b30202c3031,0x203233662e766f6d,0x6630202c31662509\n"
".quad 0x3030303030303030,0x2f0920202020203b,0x766f6d090a30202f,0x722509203233732e\n"
".quad 0x347225202c313134,0x5f744c240a3b3630,0x3a34373037365f36,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3131322065,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09383109636f6c2e,0x73090a3009353331,0x09203233622e6c68\n"
".quad 0x25202c3231347225,0x3b38202c39303472,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x347225202c333134,0x090a3b34202c3231,0x203233752e646461,0x202c343134722509\n"
".quad 0x347225202c387225,0x646461090a3b3331,0x722509203233752e,0x317225202c353134\n"
".quad 0x3431347225202c35,0x6c672e646c090a3b,0x3233732e6c61626f,0x2c36313472250920\n"
".quad 0x2b35313472255b20,0x6f6c2e090a3b5d30,0x3833310938310963,0x2e646e61090a3009\n"
".quad 0x3472250920323362,0x31347225202c3731,0x0a3b353532202c36,0x2e6f6c2e6c756d09\n"
".quad 0x3472250920323373,0x31347225202c3831,0x3731347225202c37,0x722e747663090a3b\n"
".quad 0x33732e3233662e6e,0x202c326625092032,0x090a3b3831347225,0x203233662e646461\n"
".quad 0x6625202c33662509,0x0a3b316625202c32,0x383109636f6c2e09,0x090a300939333109\n"
".quad 0x203233732e78616d,0x202c393134722509,0x25202c3731347225,0x2e090a3b30313472\n"
".quad 0x3109383109636f6c,0x6873090a30093134,0x2509203233732e72,0x7225202c30323472\n"
".quad 0x0a3b38202c363134,0x3233622e646e6109,0x2c31323472250920,0x202c303234722520\n"
".quad 0x756d090a3b353532,0x3233732e6f6c2e6c,0x2c32323472250920,0x202c313234722520\n"
".quad 0x090a3b3132347225,0x662e6e722e747663,0x09203233732e3233,0x347225202c346625\n"
".quad 0x646461090a3b3232,0x662509203233662e,0x202c346625202c35,0x6c2e090a3b336625\n"
".quad 0x343109383109636f,0x78616d090a300932,0x722509203233732e,0x347225202c333234\n"
".quad 0x31347225202c3132,0x636f6c2e090a3b39,0x0934343109383109,0x732e726873090a30\n"
".quad 0x3234722509203233,0x3631347225202c34,0x61090a3b3631202c,0x09203233622e646e\n"
".quad 0x25202c3532347225,0x3532202c34323472,0x2e6c756d090a3b35,0x09203233732e6f6c\n"
".quad 0x25202c3632347225,0x7225202c35323472,0x7663090a3b353234,0x3233662e6e722e74\n"
".quad 0x662509203233732e,0x3632347225202c36,0x662e646461090a3b,0x2c37662509203233\n"
".quad 0x6625202c36662520,0x636f6c2e090a3b35,0x0935343109383109,0x732e78616d090a30\n"
".quad 0x3234722509203233,0x3532347225202c37,0x3b3332347225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093734310938,0x3233732e72687309,0x2c38323472250920,0x202c363134722520\n"
".quad 0x646e61090a3b3432,0x722509203233622e,0x347225202c393234,0x3b353532202c3832\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x347225202c303334,0x32347225202c3932\n"
".quad 0x2e747663090a3b39,0x732e3233662e6e72,0x2c38662509203233,0x0a3b303334722520\n"
".quad 0x3233662e64646109,0x25202c3166250920,0x3b376625202c3866,0x3109636f6c2e090a\n"
".quad 0x0a30093834310938,0x3233732e78616d09,0x2c30313472250920,0x202c393234722520\n"
".quad 0x090a3b3732347225,0x203233732e646461,0x202c393034722509,0x31202c3930347225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x7225202c36347025,0x3930347225202c34\n"
".quad 0x3634702540090a3b,0x4c24092061726220,0x373037365f365f74,0x2e617262090a3b34\n"
".quad 0x744c240920696e75,0x32363536365f365f,0x5f365f744c240a3b,0x090a3a3437343337\n"
".quad 0x203233732e766f6d,0x202c303134722509,0x2e766f6d090a3b30,0x3166250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x36365f365f744c24\n"
".quad 0x6e61090a3a323635,0x2509203233622e64,0x7225202c31333472,0x0a3b353532202c39\n"
".quad 0x3233752e62757309,0x2c32333472250920,0x202c313334722520,0x70746573090a3b31\n"
".quad 0x203233752e74672e,0x25202c3734702509,0x33347225202c3572,0x34702540090a3b32\n"
".quad 0x2409206172622037,0x3537365f365f744c,0x6f6c2e090a3b3638,0x3735310938310963\n"
".quad 0x702e646c090a3009,0x3233752e6d617261,0x2c33333472250920,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x656e697274655034,0x506c656e72654b74,0x6969695f53665069\n"
".quad 0x090a3b5d735f675f,0x203233752e766f6d,0x202c343334722509,0x782e646961746325\n"
".quad 0x732e646461090a3b,0x3334722509203233,0x202c337225202c35,0x756d090a3b397225\n"
".quad 0x3233752e6f6c2e6c,0x2c36333472250920,0x202c343334722520,0x090a3b3533347225\n"
".quad 0x752e6f6c2e6c756d,0x3334722509203233,0x3633347225202c37,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x7225202c38333472,0x347225202c333334,0x6c756d090a3b3733\n"
".quad 0x203233732e6f6c2e,0x202c393334722509,0x363532202c347225,0x752e646461090a3b\n"
".quad 0x3434722509203233,0x202c357225202c30,0x090a3b3933347225,0x752e6f6c2e6c756d\n"
".quad 0x3434722509203233,0x3034347225202c31,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x7225202c32343472,0x347225202c383334,0x2e646c090a3b3134,0x732e6c61626f6c67\n"
".quad 0x3434722509203233,0x343472255b202c33,0x2e090a3b5d302b32,0x3109383109636f6c\n"
".quad 0x6e61090a30093036,0x2509203233622e64,0x7225202c34343472,0x353532202c333434\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c35343472,0x347225202c343434\n"
".quad 0x747663090a3b3434,0x2e3233662e6e722e,0x3966250920323373,0x3b3534347225202c\n"
".quad 0x33662e646461090a,0x2c30316625092032,0x6625202c39662520,0x636f6c2e090a3b31\n"
".quad 0x0931363109383109,0x732e78616d090a30,0x3434722509203233,0x3434347225202c36\n"
".quad 0x3b3031347225202c,0x3109636f6c2e090a,0x0a30093336310938,0x3233732e72687309\n"
".quad 0x2c37343472250920,0x202c333434722520,0x2e646e61090a3b38,0x3472250920323362\n"
".quad 0x34347225202c3834,0x0a3b353532202c37,0x2e6f6c2e6c756d09,0x3472250920323373\n"
".quad 0x34347225202c3934,0x3834347225202c38,0x722e747663090a3b,0x33732e3233662e6e\n"
".quad 0x2c31316625092032,0x0a3b393434722520,0x3233662e64646109,0x202c323166250920\n"
".quad 0x6625202c31316625,0x6f6c2e090a3b3031,0x3436310938310963,0x2e78616d090a3009\n"
".quad 0x3472250920323373,0x34347225202c3035,0x3634347225202c38,0x09636f6c2e090a3b\n"
".quad 0x3009363631093831,0x33732e726873090a,0x3135347225092032,0x2c3334347225202c\n"
".quad 0x6e61090a3b363120,0x2509203233622e64,0x7225202c32353472,0x353532202c313534\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c33353472,0x347225202c323534\n"
".quad 0x747663090a3b3235,0x2e3233662e6e722e,0x3166250920323373,0x3335347225202c33\n"
".quad 0x662e646461090a3b,0x3431662509203233,0x202c33316625202c,0x2e090a3b32316625\n"
".quad 0x3109383109636f6c,0x616d090a30093736,0x2509203233732e78,0x7225202c34353472\n"
".quad 0x347225202c323534,0x6f6c2e090a3b3035,0x3936310938310963,0x2e726873090a3009\n"
".quad 0x3472250920323373,0x34347225202c3535,0x090a3b3432202c33,0x203233622e646e61\n"
".quad 0x202c363534722509,0x32202c3535347225,0x6c756d090a3b3535,0x203233732e6f6c2e\n"
".quad 0x202c373534722509,0x25202c3635347225,0x63090a3b36353472,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x347225202c353166,0x646461090a3b3735,0x662509203233662e\n"
".quad 0x2c35316625202c31,0x090a3b3431662520,0x09383109636f6c2e,0x6d090a3009303731\n"
".quad 0x09203233732e7861,0x25202c3031347225,0x7225202c36353472,0x744c240a3b343534\n"
".quad 0x36383537365f365f,0x09636f6c2e090a3a,0x3009333731093831,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x302b393672255b09,0x0a3b316625202c5d,0x383109636f6c2e09\n"
".quad 0x090a300934373109,0x65726168732e7473,0x5b09203233752e64,0x3230312b39367225\n"
".quad 0x31347225202c5d34,0x636f6c2e090a3b30,0x0935373109383109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x3233732e766f6d09,0x2c39303472250920,0x4c240a3b38323120\n"
".quad 0x313638365f365f74,0x6c3c2f2f200a3a30,0x6f6f4c203e706f6f,0x6c2079646f622070\n"
".quad 0x2c35373120656e69,0x676e697473656e20,0x203a687470656420,0x6d69747365202c31\n"
".quad 0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520,0x6c2e70746573090a\n"
".quad 0x2509203233752e65,0x347225202c383470,0x3b357225202c3930,0x203834702540090a\n"
".quad 0x744c240920617262,0x38373339365f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35373120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30313638365f365f,0x3109636f6c2e090a,0x0a30093138310938\n"
".quad 0x3233752e64646109,0x2c38353472250920,0x202c393034722520,0x756d090a3b357225\n"
".quad 0x3233752e6f6c2e6c,0x2c39353472250920,0x202c383534722520,0x2e646461090a3b34\n"
".quad 0x3472250920323375,0x35347225202c3036,0x3b36337225202c39,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3631662509,0x5d302b3036347225,0x68732e646c090a3b\n"
".quad 0x3233662e64657261,0x202c373166250920,0x5d302b393672255b,0x662e646461090a3b\n"
".quad 0x3831662509203233,0x202c36316625202c,0x73090a3b37316625,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x202c5d302b393672,0x6c090a3b38316625,0x6465726168732e64\n"
".quad 0x722509203233752e,0x72255b202c313634,0x343230312b303634,0x732e646c090a3b5d\n"
".quad 0x33752e6465726168,0x3236347225092032,0x2b393672255b202c,0x090a3b5d34323031\n"
".quad 0x2e65672e70746573,0x3470250920323375,0x3236347225202c39,0x3b3136347225202c\n"
".quad 0x203934702540090a,0x744c240920617262,0x38373339365f365f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35373120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x30313638365f365f,0x3109636f6c2e090a\n"
".quad 0x0a30093338310938,0x726168732e747309,0x09203233752e6465,0x30312b393672255b\n"
".quad 0x347225202c5d3432,0x5f744c240a3b3136,0x3a38373339365f36,0x365f365f744c240a\n"
".quad 0x2f200a3a36363838,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3537,0x64656c6562616c20,0x365f365f744c2420\n"
".quad 0x6c2e090a30313638,0x383109383109636f,0x726162090a300935,0x300920636e79732e\n"
".quad 0x09636f6c2e090a3b,0x3009373731093831,0x33732e726873090a,0x3930347225092032\n"
".quad 0x2c3930347225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c333634\n"
".quad 0x74672e7074657309,0x702509203233732e,0x30347225202c3035,0x3336347225202c39\n"
".quad 0x3035702540090a3b,0x4c24092061726220,0x313638365f365f74,0x70252140090a3b30\n"
".quad 0x2409206172622034,0x3130375f365f744c,0x6f6c2e090a3b3634,0x3039310938310963\n"
".quad 0x2e766f6d090a3009,0x3472250920323375,0x61746325202c3436,0x6d090a3b782e6469\n"
".quad 0x33752e6f6c2e6c75,0x3536347225092032,0x2c3436347225202c,0x2e646c090a3b3420\n"
".quad 0x662e646572616873,0x3931662509203233,0x5d302b746d5b202c,0x722e747663090a3b\n"
".quad 0x33732e3233662e6e,0x2c30326625092032,0x64090a3b33722520,0x33662e6e722e7669\n"
".quad 0x2c31326625092032,0x25202c3931662520,0x6f6d090a3b303266,0x2509203233662e76\n"
".quad 0x626630202c323266,0x3b30303030303866,0x202f2f0920202020,0x2e646461090a312d\n"
".quad 0x3266250920323366,0x2c31326625202c33,0x090a3b3232662520,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x5f5f5b202c363634,0x6d72617061647563,0x74655034315a5f5f\n"
".quad 0x72654b74656e6972,0x53665069506c656e,0x765f675f6969695f,0x2e646461090a3b5d\n"
".quad 0x3472250920323375,0x36347225202c3736,0x3536347225202c36,0x6c672e7473090a3b\n"
".quad 0x3233662e6c61626f,0x37363472255b0920,0x326625202c5d302b,0x636f6c2e090a3b33\n"
".quad 0x0932393109383109,0x68732e646c090a30,0x3233732e64657261,0x2c38363472250920\n"
".quad 0x3230312b746d5b20,0x2e646c090a3b5d34,0x33752e6d61726170,0x3936347225092032\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6e69727465503431,0x6c656e72654b7465\n"
".quad 0x69695f5366506950,0x0a3b5d6d5f675f69,0x3233752e64646109,0x2c30373472250920\n"
".quad 0x202c393634722520,0x090a3b3536347225,0x61626f6c672e7473,0x5b09203233732e6c\n"
".quad 0x5d302b3037347225,0x3b3836347225202c,0x375f365f744c240a,0x2e090a3a36343130\n"
".quad 0x3209383109636f6c,0x7865090a30093231,0x57444c240a3b7469,0x34315a5f5f646e65\n"
".quad 0x74656e6972746550,0x69506c656e72654b,0x3a6969695f536650,0x5f202f2f207d090a\n"
".quad 0x697274655034315a,0x656e72654b74656e,0x695f53665069506c,0x000000000a0a6969\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[8924];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010101464c457f,0x0000000000000004,0x0000000100be0002,0x000021c800000000\n"
".quad 0x0014011500000034,0x0028000300200034,0x000000000001000a,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000100000000\n"
".quad 0x0000000000000003,0x000001c400000000,0x0000000000000102,0x0000000400000000\n"
".quad 0x0000000b00000000,0x0000000000000003,0x000002c600000000,0x0000000000000034\n"
".quad 0x0000000100000000,0x0000001300000000,0x0000000000000002,0x000002fa00000000\n"
".quad 0x00000002000000e0,0x000000010000000c,0x0000003600000010,0x0010000600000001\n"
".quad 0x000003da00000000,0x0000000300001ce8,0x000000041a000006,0x000000d800000000\n"
".quad 0x0000000200000001,0x000020c200000000,0x0000000000000038,0x0000000400000004\n"
".quad 0x000000ad00000000,0x0000000200000001,0x000020fa00000000,0x0000000000000004\n"
".quad 0x0000000400000004,0x0000005800000000,0x0000000200000001,0x000020fe00000000\n"
".quad 0x0000000000000098,0x0000000100000004,0x0000008600000000,0x0000000300000008\n"
".quad 0x0000219600000000,0x00000000000009c0,0x0000000400000004,0x0000007d00000000\n"
".quad 0x0000000200000001,0x0000219600000000,0x0000000000000030,0x0000000100000000\n"
".quad 0x68732e0000000000,0x2e00626174727473,0x2e00626174727473,0x2e006261746d7973\n"
".quad 0x61626f6c672e766e,0x2e0074696e692e6c,0x61626f6c672e766e,0x2e747865742e006c\n"
".quad 0x7274655034315a5f,0x6e72654b74656e69,0x5f53665069506c65,0x2e766e2e00696969\n"
".quad 0x315a5f2e6f666e69,0x656e697274655034,0x506c656e72654b74,0x6969695f53665069\n"
".quad 0x666e692e766e2e00,0x68732e766e2e006f,0x315a5f2e64657261,0x656e697274655034\n"
".quad 0x506c656e72654b74,0x6969695f53665069,0x6e6f632e766e2e00,0x2e3631746e617473\n"
".quad 0x7274655034315a5f,0x6e72654b74656e69,0x5f53665069506c65,0x2e766e2e00696969\n"
".quad 0x746e6174736e6f63,0x655034315a5f2e30,0x654b74656e697274,0x665069506c656e72\n"
".quad 0x5f00006969695f53,0x697274655034315a,0x656e72654b74656e,0x695f53665069506c\n"
".quad 0x6475635f5f006969,0x645f30326d735f61,0x33665f6e725f7669,0x0000000000000032\n"
".quad 0x0000000000000000,0x0000000000000000,0x0003000000000000,0x0000000000000001\n"
".quad 0x0003000000000000,0x0000000000000002,0x0003000000000000,0x0000000000000003\n"
".quad 0x0003000000000000,0x0000000000000000,0x0003000000000000,0x0000000000000000\n"
".quad 0x000300001ce80000,0x0000000000000004,0x0003000000000000,0x0000000000000007\n"
".quad 0x0003000000000000,0x0000000000000009,0x0003000000000000,0x0000000000000008\n"
".quad 0x0003000000000000,0x0000000000000006,0x0003000000000000,0x0000000000010005\n"
".quad 0x1012000019780000,0x19780000001d0004,0x0012000003700000,0x440400005de40004\n"
".quad 0x000000001de42800,0x4000b0001de44000,0x000084035c042800,0x4000b0001ca32c00\n"
".quad 0xc00004001e035000,0xc00028031c236000,0x0000fcc1dc235800,0x0002000001e7198e\n"
".quad 0xc00008009c234000,0x000094011c045800,0x00000800dc032c00,0x0000fc015de44800\n"
".quad 0x00001030dc032800,0xc00008d11e035000,0x40008030dc436000,0xc00020519c034000\n"
".quad 0x04040401dde26000,0xc00004515c031804,0x000010619c434800,0x000014c1dc234000\n"
".quad 0x000018319c031a8e,0x00000061dc854800,0xffff000001e79000,0x000040001de74003\n"
".quad 0xc00008d11e034000,0xc00008009c236000,0xc00020c0dc035800,0x00000c215d036000\n"
".quad 0x000014d1dc034800,0x0001000081e71b0e,0x0000940160044000,0x00000801a0032c00\n"
".quad 0x00003430e0034800,0x0000185160034800,0x4000805160435000,0x00001430e0434000\n"
".quad 0x0404040161e24000,0x0000003160851804,0x0000fcd1dc039000,0x000200000007190e\n"
".quad 0x0001c00021e76000,0x000004015de24000,0x00009400dc041800,0x4000d0319c032c00\n"
".quad 0x00001000dde24800,0x000003f19c851800,0xfffff0319c85c900,0xc0007861dc03c103\n"
".quad 0x00001c619c835800,0x400004619c036800,0xc00004515c03200a,0x000000319c854800\n"
".quad 0xc0001030dc03c900,0xc0270033dc034800,0xfffee00005e71a8e,0x000000001df44003\n"
".quad 0x0000ffffdc044000,0x4000c3f3dc2350ee,0x0050600005e71b0e,0x00000800dc034000\n"
".quad 0x000094015c044800,0x4000b001dde42c00,0xc00718d19c032800,0x00001430dc034800\n"
".quad 0x4000b0739c035000,0xc00388d3dc034800,0xc00400d5dc03198e,0x40008033dc43188e\n"
".quad 0xc001bcd7dc034000,0x0000fc015de4198e,0xc009b869dc232800,0x4000b0e0dca3198e\n"
".quad 0x00016000a5e75000,0x0000004444854000,0x000010440485c100,0x0018d0418485c100\n"
".quad 0x000001144402c100,0xfffffd0404023a00,0x00004114044339ff,0xc000050444036800\n"
".quad 0x0000446184835800,0xc000050444036800,0x22c37c6404826800,0x0000406184233a64\n"
".quad 0x0000ffffdc0431a2,0x00000041848550ee,0x0000ffffdc04c900,0x00016000a5e750ee\n"
".quad 0x000e304404854000,0x000e40418485c100,0x000000444485c100,0x000001040402c100\n"
".quad 0xfffffc6184023a00,0x00001901844339ff,0xc000046404036800,0x0000411404835800\n"
".quad 0xc000046444036800,0x22c37d0184826800,0x0000190184233a64,0x0000ffffdc0431a2\n"
".quad 0x000e3041848550ee,0x0000ffffdc04c900,0x00016000b1e750ee,0x001c604450854000\n"
".quad 0x001c70441085c100,0x000e30419085c100,0x000001145002c100,0xfffffd0410023a00\n"
".quad 0x00004114104339ff,0xc000050450036800,0x0000446190835800,0xc000050450036800\n"
".quad 0x22c37c6410826800,0x0000406190233a64,0x0000ffffdc0431a2,0x001c6041908550ee\n"
".quad 0x0000ffffdc04c900,0x00018000a1e750ee,0x000003f440854000,0x0026f3f18085c100\n"
".quad 0x0018c3f40085c100,0xfffffd144002c100,0x00000061800239ff,0x0000191180433a00\n"
".quad 0xc000046440036800,0xc000046480035800,0x0000411400836800,0x22c37d0440826800\n"
".quad 0x0000450400233a64,0x0026f3f4008531a4,0x0000ffffdc04c900,0x00000d241c0450ee\n"
".quad 0x000000449c851804,0x000011041c00c100,0x00000ff59dc3c800,0xfffff9041c026800\n"
".quad 0x000c20000007083f,0x000041241c046000,0x00000d045c031486,0x000045245f845000\n"
".quad 0x000045041c431c00,0x4000b1245ec42020,0x000049041c431c00,0x00000d049e035000\n"
".quad 0x000045241c042024,0x00000d2bdc031804,0x00001104dc001b0e,0x00000d249503c800\n"
".quad 0x4000b1241ec44800,0xfffff934dc021c00,0x00000d2bdc03083f,0x000041251c041b0e\n"
".quad 0x00004d24dc041804,0x00000d2495031486,0x000011451c004800,0x00004d155c03c800\n"
".quad 0x000049649c035000,0xfffff9451c023106,0x000055259f84083f,0x000049255ec41c00\n"
".quad 0x000051251c041c00,0x000059359c431486,0x00005104dc032026,0x00005565dc435000\n"
".quad 0x00004d259f845000,0x00005d14de031c00,0x000059451c43202a,0x00004925dec42028\n"
".quad 0x00004d1bdc031c00,0x00004534d503198e,0x00005d451c434800,0xc0002c655c035000\n"
".quad 0x00004d1bdc035800,0x000051059e03198e,0x00004534d503202e,0x000019519c834800\n"
".quad 0x0000590bdc036800,0xc0001c645c03198e,0x0000416595036000,0xc000054514034800\n"
".quad 0xb15a01145c024800,0x0000416bdc033a74,0x000044619c831b0e,0x4000b1241c836800\n"
".quad 0xc000054514036800,0x0000fd0bdc234800,0xc0003c641c031b0e,0x0000512537846000\n"
".quad 0x0000fd2bdc231c00,0x180001041c021b0e,0x00004d24f7843bbf,0x000040619c831c00\n"
".quad 0x4000b3fbdc236800,0x4000b3f41dc31a8e,0x4000b3f49dc36800,0xc00048645c036800\n"
".quad 0x000051041c045800,0x4000b3fbdc23201a,0x000044619c831a8e,0x00004d245c046800\n"
".quad 0x0004000029e7201a,0xc0000501dc034000,0xfffffce25c036800,0x0000fc7bdc234800\n"
".quad 0xfffffd01dc031a8e,0x00001c91dc234800,0x0000c000b5e73120,0x4000b00215e44000\n"
".quad 0xfffffc8294032800,0xc000051214034800,0x0000291dd4234800,0x0000fc8214041a8e\n"
".quad 0x000000001de4200c,0x0000440235e44000,0x4000b1049ca32800,0x4000b0729ca32022\n"
".quad 0x00003d22dc032010,0x000028f29c034800,0x000000b2dc254800,0x0000409bdc238000\n"
".quad 0x000000a29c251a8e,0xc00005025c038000,0x0000fc925c044800,0x0000fcbbdc23200a\n"
".quad 0x0000fcabdc231a0e,0x0000c00035e71a0a,0xc0000834dc234000,0x00003d34dc435800\n"
".quad 0x00004d24dc434000,0xc0001c549c034000,0x000001349c854800,0x00001c7bdc149000\n"
".quad 0x00001cfbdc140c0e,0x00001cfbdc140c0e,0x0000ffffdc040c0e,0x00034000000750ee\n"
".quad 0x0000000035f46000,0xc0001c549c034000,0xc00005051c034800,0xc0000524dc036800\n"
".quad 0x0000513bdc236800,0x0002400015e7190e,0xc0000834dc234000,0x4000b0751ca35800\n"
".quad 0x00003d34dc432010,0x00004d451c434000,0x000001451c854000,0x0000494bdc238000\n"
".quad 0x0001800015e7190e,0x4000b0051de44000,0x4000b0955ca32800,0x4000b0951ca32010\n"
".quad 0x0000fc8bdc232028,0xc00009451e03190e,0xfffff1555c436000,0xfffff14554034000\n"
".quad 0x00004d54dc034800,0x00000134dc854800,0x0000493bdc238000,0x0000200015e7190e\n"
".quad 0x00001c7bdc144000,0x00001cfbdc140c0e,0x00010000b5e70c0e,0x4000b074d4a34000\n"
".quad 0x4000b10554a32010,0xfffffca494032022,0xfffffcb514034800,0x00004cf4d4034800\n"
".quad 0x000054f554034800,0x0000013494254800,0x0000015514259000,0x0000ffffdc049000\n"
".quad 0x00020000000750ee,0x0000000035f46000,0x4000b0949ca34000,0x4000b0051de42010\n"
".quad 0x00003d249c032800,0x4000b1055ca34800,0x00000124dc255000,0xfffffd441c038000\n"
".quad 0x000045551c034800,0x0000450bdc234800,0xc000054554031a8e,0x00003d545c034800\n"
".quad 0xc00005341c034800,0x000001241c254800,0x00000114dc259000,0xc00005341c038000\n"
".quad 0x000001141c354800,0x0000ffffdc049000,0x00000d241c0450ee,0x00100044dc851804\n"
".quad 0x000011041c00c100,0x4000b1249ec4c800,0xfffff9041c021c00,0x000041241c04083f\n"
".quad 0x000049251c041486,0x00000d045c031804,0x000011451c005000,0x000045245f84c800\n"
".quad 0xfffff9451c021c00,0x000045041c43083f,0x000051251c042020,0x00004d041c431486\n"
".quad 0x4000b1245ec45000,0x00000d041e031c00,0x00000ff55dc32026,0x00004524dc046800\n"
".quad 0x00000d0bdc031804,0x00001134dc001b0e,0x00000d041503c800,0x00000d0bdc034800\n"
".quad 0xfffff934dc021b0e,0x00000d041503083f,0x00004d24dc044800,0x000051259c031486\n"
".quad 0x000041541c035000,0x00004d155c033106,0x00005925df845000,0x000055259f841c00\n"
".quad 0x00005d45dc431c00,0x000041255ec42028,0x000041251ec41c00,0x000059359c431c00\n"
".quad 0x0007400000072026,0x00005574dc436000,0x00004d24de035000,0x000051655c43202a\n"
".quad 0x00004d2bdc035000,0x000055151e03198e,0x00004934d5032028,0x0000511bdc034800\n"
".quad 0xc00005555403198e,0x0000454515034800,0x00004d2bdc034800,0x00004934d503198e\n"
".quad 0x0000454bdc034800,0x4000b3f49dc31b0e,0x4000b1045c836800,0xc000055554036800\n"
".quad 0x0000fd1bdc234800,0x0000552577841b0e,0x4000b3f45dc31c00,0x0000fd0bdc236800\n"
".quad 0x00004d24f7841b0e,0x4000b3fbdc231c00,0x000055145c041a8e,0x4000b3fbdc23201a\n"
".quad 0x00004d249c041a8e,0x0004000029e7201a,0xc0000511dc034000,0xfffffce25c036800\n"
".quad 0x0000fc7bdc234800,0xfffffd11dc031a8e,0x00001c91dc234800,0x0000c000b5e73122\n"
".quad 0x4000b00215e44000,0xfffffc8294032800,0xc000052214034800,0x0000292dd4234800\n"
".quad 0x0000fc8214041a8e,0x000000001de4200c,0x0000480235e44000,0x4000b114dca32800\n"
".quad 0x4000b0729ca32024,0x00003d32dc032010,0x000000b2dc254800,0x000028f29c038000\n"
".quad 0x0000251bdc234800,0xc00005125c031a8e,0x000000a29c254800,0x0000fc925c048000\n"
".quad 0x0000fcbbdc23200a,0x0000fcabdc231a0e,0x0000c00035e71a0a,0xc00008351c234000\n"
".quad 0x00003d451c435800,0x000051351c434000,0xc0002c54dc034000,0x00000144dc854800\n"
".quad 0x00001c7bdc149000,0x00001cfbdc140c0e,0x00001cfbdc140c0e,0x0000ffffdc040c0e\n"
".quad 0x00034000000750ee,0x0000000035f46000,0xc0002c54dc034000,0xc00005155c034800\n"
".quad 0xc00005351c036800,0x0000554bdc236800,0x0002400015e7190e,0xc00008351c234000\n"
".quad 0x4000b0755ca35800,0x00003d451c432010,0x000051555c434000,0x000001555c854000\n"
".quad 0x00004d5bdc238000,0x0001800015e7190e,0x4000b0055de44000,0x4000b0955ca32800\n"
".quad 0x4000b0959ca3202a,0x0000fc8bdc232010,0xc00009555e03190e,0xfffff1659c436000\n"
".quad 0xfffff15594034000,0x000051651c034800,0x000001451c854800,0x00004d4bdc238000\n"
".quad 0x0000200015e7190e,0x00001c7bdc144000,0x00001cfbdc140c0e,0x00010000b5e70c0e\n"
".quad 0x4000b07514a34000,0x4000b11594a32010,0xfffffca4d4032024,0x000050f514034800\n"
".quad 0xfffffcb554034800,0x000058f594034800,0x00000144d4254800,0x0000016554259000\n"
".quad 0x0000ffffdc049000,0x00020000000750ee,0x0000000035f46000,0x4000b094dca34000\n"
".quad 0x4000b0059de42010,0x00003d34dc032800,0x4000b1155ca34800,0xfffffd645c035000\n"
".quad 0x000001351c254800,0x0000452bdc238000,0x000049545c031a8e,0xc000051554034800\n"
".quad 0x00003d549c034800,0xc00005445c034800,0x000001345c254800,0x000001251c259000\n"
".quad 0xc00005445c038000,0x000001245c354800,0x0000ffffdc049000,0x00022000000750ee\n"
".quad 0x000000002df46000,0x00000d241c044000,0x002000449c851804,0x000011041c00c100\n"
".quad 0xfffff9041c02c800,0x000041241c04083f,0x00000d045c031486,0x000045245f845000\n"
".quad 0x000045041c431c00,0x000049041c432020,0x00000ff45dc35000,0x00000d041e036800\n"
".quad 0x00000d0bdc032024,0x00000d0415031b0e,0x00000d0bdc034800,0x00000d0415031b0e\n"
".quad 0x000041141c134800,0xc001c0dbdc033106,0x000980000007188e,0x0009400035e76000\n"
".quad 0x4000b1221ec44000,0x4000b121dec41c00,0x000021229c041c00,0x00001d225c041804\n"
".quad 0x000010a29c001804,0x000010925c00c800,0xfffff8a29c02c800,0x00002922dc04083f\n"
".quad 0xfffff8925c021486,0x000025225c04083f,0x00002c845c031486,0x000024729c035000\n"
".quad 0x000045245f845000,0x000041249ec41c00,0x000029229f841c00,0x000044b45c431c00\n"
".quad 0x000028925c432016,0x00004122dec42012,0x000049129c431c00,0x000028829e035000\n"
".quad 0x00002c925c432024,0x0000288bdc035000,0x00002472de03198e,0x000020a295032016\n"
".quad 0x4000b1045c834800,0x00002c7bdc036800,0xc00004925403198e,0x00001cb2d5034800\n"
".quad 0x0000288bdc034800,0x000020a29503198e,0x00001cbbdc034800,0x4000b3f21dc31b0e\n"
".quad 0xc000049254036800,0x4000b3f1ddc34800,0x0000fd1bdc236800,0x0000252277841b0e\n"
".quad 0xfffffce45c031c00,0x4000b3fbdc234800,0x000024725c041a8e,0x0000fd0bdc23201a\n"
".quad 0xc0000491dc031b0e,0x00002922b7846800,0x4000b3fbdc231c00,0x000028829c041a8e\n"
".quad 0x0000fc7bdc23201a,0xfffffc91dc031a8e,0x00001d11dc234800,0x0000c000b5e73112\n"
".quad 0x4000b00215e44000,0xfffffc82d4032800,0xc00004a214034800,0x00002cadd4234800\n"
".quad 0x0000fc8214041a8e,0x000000001de4200c,0x0000280235e44000,0x4000b0949ca32800\n"
".quad 0x4000b0729ca32014,0x00003d22dc032010,0x000000b2dc254800,0x000028f29c038000\n"
".quad 0x0000449bdc234800,0xc00004925c031a8e,0x000000a29c254800,0x0000fc925c048000\n"
".quad 0x0000fcbbdc23200a,0x0000fcabdc231a0e,0x0000c00035e71a0a,0xc00008345c234000\n"
".quad 0x00003d145c435800,0x000045249c434000,0xc00034545c034000,0x000001245c854800\n"
".quad 0x00001c7bdc149000,0x00001cfbdc140c0e,0x00001cfbdc140c0e,0x0000ffffdc040c0e\n"
".quad 0x00060000000750ee,0x0000000035f46000,0x4000b1245ec44000,0x000041251ec41c00\n"
".quad 0x000045249c041c00,0x000011249c001804,0xfffff9249c02c800,0x000049249c04083f\n"
".quad 0x00004914dc031486,0x00004d24df845000,0x00004d249c431c00,0x000051249c432024\n"
".quad 0x00004914de035000,0x00004d1bdc032028,0x4000b1051c83198e,0x00004534d5036800\n"
".quad 0xc000052494034800,0x0000453bdc034800,0xc000052494031b0e,0x4000b3f45dc34800\n"
".quad 0x0000fd4bdc236800,0x00004924b7841b0e,0x4000b3fbdc231c00,0x00004914dc041a8e\n"
".quad 0xc00034545c03201a,0xc0000534dc034800,0xc00005149c036800,0x00004d2bdc236800\n"
".quad 0x0002400015e7190e,0xc00008349c234000,0x4000b074dca35800,0x00003d249c432010\n"
".quad 0x00004934dc434000,0x00000134dc854000,0x0000453bdc238000,0x0001800015e7190e\n"
".quad 0x4000b004dde44000,0x4000b0951ca32800,0x4000b094dca32010,0x0000fc8bdc232026\n"
".quad 0xc0000934de03190e,0xfffff1451c436000,0xfffff13514034000,0x000049449c034800\n"
".quad 0x000001249c854800,0x0000452bdc238000,0x0000200015e7190e,0x00001c7bdc144000\n"
".quad 0x00001cfbdc140c0e,0x0006800000070c0e,0x0000000035f46000,0x4000b1245ec44000\n"
".quad 0x000041251ec41c00,0x000045249c041c00,0x4000b1055c831804,0x000011249c006800\n"
".quad 0x000041259ec4c800,0xfffff9249c021c00,0x000049249c04083f,0x00004914dc031486\n"
".quad 0x00004d24df845000,0x00004d249c431c00,0x000051249c432024,0x00004914de035000\n"
".quad 0x00004d1ddc032028,0x00004534d903198e,0xc000052498034800,0x0000453ddc034800\n"
".quad 0x4000b0745ca31b0e,0xfffffca4dc032010,0x000044f51c034800,0xc000052498034800\n"
".quad 0x00000144dc254800,0x4000b124dec49000,0x0000fd5ddc231c00,0x00004d251c041b0e\n"
".quad 0x00004924bb841804,0x000011451c001c00,0xfffffcb45c03c800,0xfffff9451c024800\n"
".quad 0x000051251c04083f,0x000051355c031486,0x000055255f845000,0x000055451c431c00\n"
".quad 0x000059451c432028,0x4000b3f55dc35000,0x000051351e036800,0x0000513ddc03202c\n"
".quad 0x00004d451903198e,0x4000b3fddc234800,0x000049549c041a8e,0x0000513ddc03201c\n"
".quad 0x4000b1249ca3198e,0x00004d4519035000,0x0000fd0ddc234800,0x4000b3f4ddc31b0e\n"
".quad 0x000051253b846800,0x4000b3fddc231c00,0x00005134dc041a8e,0x00004d249c03201c\n"
".quad 0x000048f49c034800,0x000001245c354800,0x0000ffffdc049000,0x00074000000750ee\n"
".quad 0x0000000035f46000,0x4000b0945ca34000,0x4000b124dec42010,0x00003d145c031c00\n"
".quad 0x00004d251c044800,0x000011455c001804,0x000001149c25c800,0x4000b1251ec48000\n"
".quad 0xfffff9555c021c00,0x00005525dc04083f,0x000051259c041486,0x000011659c001804\n"
".quad 0x00005d355c03c800,0x000055261f845000,0xfffff9665c021c00,0x000041259ec4083f\n"
".quad 0x00006175dc431c00,0x000065255c04202e,0x000059761c431486,0x000055465c035000\n"
".quad 0x000061359e035000,0x00006525df84202c,0x0000593bdc031c00,0x000041261ec4198e\n"
".quad 0x00005d555c431c00,0x00004d659503202a,0x000061555c434800,0x0000593bdc035000\n"
".quad 0x00005545de03198e,0x00004d6595032030,0x00005d4bdc034800,0x00005175d503198e\n"
".quad 0xc000055554034800,0x0000517bdc034800,0xc000055554031b0e,0x0000fd0bdc234800\n"
".quad 0x4000b1041c831b0e,0x00005925b7846800,0x0000fd0bdc231c00,0x4000b3f41dc31b0e\n"
".quad 0x0000552577846800,0x4000b3fbdc231c00,0x000055051c041a8e,0x4000b3fbdc23201a\n"
".quad 0x4000b3f41dc31a8e,0x4000b0055de46800,0x00005904dc042800,0x4000b1451ca3201a\n"
".quad 0xfffffd541c035000,0x0000413bdc234800,0x00004d441c031a8e,0xc000050514034800\n"
".quad 0xc00005241c034800,0x00003d449c034800,0x000001141c254800,0x00000124dc259000\n"
".quad 0xc00005341c038000,0x000001241c354800,0x0000ffffdc049000,0xc004e0515c0350ee\n"
".quad 0x4000c05bdc234800,0xffb1400015e7188e,0xfffffcc0dc034003,0x0000fc33dc234800\n"
".quad 0x0004c00005e7188e,0x00000800dc034000,0x000094015c044800,0x000014315c032c00\n"
".quad 0x0000fc01dde45000,0x0000fc00dde42800,0x0000fc019de42800,0x400080515c432800\n"
".quad 0xc00020321c034000,0x000010821c436000,0xc0000430dc034000,0x000020521c034800\n"
".quad 0x00000cc3dc234800,0x000000821c851a8e,0xc003fc825c038000,0xc0002082dc236800\n"
".quad 0xc00040839c235800,0x000024929ca35800,0xc0006083dc235000,0xc003fcb2dc035800\n"
".quad 0xc003fce39c036800,0x000029221e046800,0x00001c91dc231800,0x00002cb29ca3081e\n"
".quad 0xc003fcf3dc035000,0x000018819c006800,0x000038e25ca35000,0x000029221e045000\n"
".quad 0x00001cb1dc231800,0x00003cf29ca3081e,0x000025225e045000,0x000018819c001800\n"
".quad 0x00001ce1dc235000,0x000029221e04081e,0x000018919c001800,0x00001cf1dc235000\n"
".quad 0x000018819c00081e,0xfffc400005e75000,0x000040001de74003,0x0000fc01dde44000\n"
".quad 0x0000fc019de42800,0xc003fc20dc032800,0xfffffc30dc036800,0x00000cd3dc034800\n"
".quad 0x0003c00085e71a0e,0x00000800a4034000,0x00009400e4044800,0x00000830a4032c00\n"
".quad 0x000034c0e5035000,0x40008020a4434000,0x00000830a4434000,0x00000020a4854000\n"
".quad 0xc003fc20e4038000,0xc000202224236800,0xc000402264235800,0x00000c3164a35800\n"
".quad 0xc003fc8224035000,0xc0006022a4236800,0xc003fc9264035800,0x00001520a6046800\n"
".quad 0x00001c30e4231800,0x0000208164a3081e,0x00002491e4a35000,0xc003fca2a4035000\n"
".quad 0x00001820a4006800,0x0000152166045000,0x00000c80e4231800,0x00001d21a604081e\n"
".quad 0x000028a224a31800,0x00000850a4005000,0x00000c90e4235000,0x000021216604081e\n"
".quad 0x00000860a4001800,0x00000ca1e4235000,0x00000851a400081e,0x000000419c855000\n"
".quad 0x00100041dc85c900,0x0000ffffdc04c900,0x00020001dde250ee,0x00003473dc031800\n"
".quad 0x000180000007198e,0x0000000005f46000,0x000034709c034000,0xc00008215e034800\n"
".quad 0x000000409c856000,0x00000050dc85c100,0x000008319c00c100,0x001000409c855000\n"
".quad 0x000000419c85c100,0x00100050dc85c900,0x00000c23dc03c100,0x00100040e4851b0e\n"
".quad 0x000000001df4c900,0x0000ffffdc044000,0xc0000471dc2350ee,0x0000fc73dc235800\n"
".quad 0xfffdc00005e71a0e,0x0000000021e74003,0x000001215e048000,0x000094009c041800\n"
".quad 0xc00008209e032c00,0x000003f11c856000,0x0000e0010007c100,0xefe00040dc005000\n"
".quad 0x001003f01c855000,0x400090211c03c100,0x4000a0209c034800,0x00000040dc854800\n"
".quad 0x000000201c859000,0x000000001de79000,0xc00004401c038000,0xc00004519c036000\n"
".quad 0xc00060001c036000,0xc00060619c035800,0xfffffc01dc035800,0xc003f471dc034800\n"
".quad 0xfffffc621c031a0e,0xc003f481dc034800,0x0005200021e71a20,0xdfe00041dc804000\n"
".quad 0x000011201c44298e,0x0000600021e71080,0xdfe00051dc804000,0x000015219c44298e\n"
".quad 0x0000400001e71080,0x000014411c204000,0x000b80001de75000,0xc00004425c034000\n"
".quad 0xc00004529c036000,0x0000fc93dc036000,0x0000fca5dc03190e,0x00000811dc04190e\n"
".quad 0x0000800001e70c0e,0xdfe00007dc004000,0xdfe00061dc00290e,0x000080002de7290e\n"
".quad 0x0000600021e74000,0x000000001de24000,0x000014011c001bff,0x0009e0001de7c800\n"
".quad 0x00004401dc044000,0x0000600021e70c0e,0x000010501c834000,0x000000011c026800\n"
".quad 0x000940001de73a00,0x00004831dc044000,0x0000800021e70c0e,0x000010501c834000\n"
".quad 0x000000001c026800,0x000000011c423a00,0x000880001de739fe,0x0000fc73dc234000\n"
".quad 0x0000fc81dc231b0e,0xffff000025e21b0e,0xd7e0004124001bff,0x0000fc0005e4307e\n"
".quad 0x0000800001e72800,0xd7e000515c004000,0xc00100001c03307e,0x000020001de74800\n"
".quad 0x0000fc001de44000,0xfffe08819c032800,0x000014619ee34800,0xfffe08715c034100\n"
".quad 0x000010625c004800,0x000010511ee3c800,0x00002071dd034100,0x000024415c004800\n"
".quad 0x000014629e00307e,0x000024a15c003008,0x000014619e00300a,0x000024611c003008\n"
".quad 0xc00004429c03300a,0xc00060a29c036000,0x00002871dc035800,0x00001c01dc034800\n"
".quad 0xfffffc701c034800,0xc003f401dc034800,0x0000600001e71a0e,0x000028701d034000\n"
".quad 0x000010011ee34800,0x0004a0001de74000,0xc003f871dc234000,0x0000600001e7198e\n"
".quad 0x000000401c024000,0x000000011c423a00,0x000400001de739fe,0x0000fc71dc234000\n"
".quad 0x0003c00001e71a0e,0xffffa071dc234000,0x0000400001e71b0e,0x000000411c024000\n"
".quad 0x000340001de73a00,0x000024629c004000,0x000024621c00310a,0x000024601c00308a\n"
".quad 0x00001d225f84318a,0x000020a15c001c00,0xfffffc019c021e8e,0x0000fc91dc233801\n"
".quad 0x000000401c02190e,0x00001d221f843a00,0x000015211f841c00,0x000000625c421c00\n"
".quad 0x0000a00081e73802,0xc000807160034000,0x0000149160034800,0xc00007f160036000\n"
".quad 0x000020926003310a,0x0000144120435800,0xc00078915c036800,0xc0007c519c036000\n"
".quad 0xc00004915c035800,0x000018411c436800,0x000010511c036800,0xc00004915c036800\n"
".quad 0x0000fc41dc035800,0xc000045140031a8e,0x000014011c434800,0x000000001de76800\n"
".quad 0x0000000000009000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0c046c0789650000\n"
".quad 0x0004000000000018,0x000c000000080000,0x0014000000100000,0x000b00080a040000\n"
".quad 0x1903001800200000,0xffff000c17040018,0xf00000140005ffff,0xffff000c17040011\n"
".quad 0xf00000100004ffff,0xffff000c17040011,0xf000000c0003ffff,0xffff000c17040011\n"
".quad 0xf00000080002ffff,0xffff000c17040011,0xf00000040001ffff,0xffff000c17040011\n"
".quad 0xf00000000000ffff,0x00b400080d040011,0x12040000000d000f,0x00000000000d0008\n"
".quad 0x000d000811040000,0x1204000000000000,0x00000000000c0008,0x000c000811040000\n"
".quad 0x0000000000000000,0x000021c800000006,0x0000000000000000,0x0000006000000060\n"
".quad 0x0000000400000005,0x000003da60000000,0x0000000000000000,0x00001dbc00001dbc\n"
".quad 0x0000000400000c05,0x0000219660000000,0x0000000000000000,0x000009c000000000\n"
".quad 0x0000000400000c06,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[1094];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"98b85310819e481b",(char*)"/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/main.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x83fc65a0,&__elfEntries1};
# 3 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c" 2
struct __T20 {int *__par0;float *__par1;int *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
extern void __device_stub__Z14PetrinetKernelPiPfS_iii(int *, float *, int *, int, int, int);
static void __sti____cudaRegisterAll_39_tmpxft_0000171f_00000000_4_main_cpp1_ii_0e7396a7(void) __attribute__((__constructor__));
void __device_stub__Z14PetrinetKernelPiPfS_iii(int *__par0, float *__par1, int *__par2, int __par3, int __par4, int __par5){ struct __T20 *__T21 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T21->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T21->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T21->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T21->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T21->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T21->__par5) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(int *, float *, int *, int, int, int))PetrinetKernel)); (void)cudaLaunch(((char *)((void ( *)(int *, float *, int *, int, int, int))PetrinetKernel))); };}
void PetrinetKernel( int *__cuda_0,float *__cuda_1,int *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5)
# 202 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
{__device_stub__Z14PetrinetKernelPiPfS_iii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 212 "/home/normal/checkout/gpuocelot/tests/parboil/tests/pns/petri_kernel.cuh"
}
# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c"
static void __sti____cudaRegisterAll_39_tmpxft_0000171f_00000000_4_main_cpp1_ii_0e7396a7(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(int *, float *, int *, int, int, int))PetrinetKernel), (char*)"_Z14PetrinetKernelPiPfS_iii", "_Z14PetrinetKernelPiPfS_iii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_0000171f_00000000-1_main.cudafe1.stub.c" 2

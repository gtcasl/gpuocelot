# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
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
# 130 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
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
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
enum CUTBoolean {
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
CUTFalse,
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
CUTTrue
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
};
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" void cutFree(void *);
# 94 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 154 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 169 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 185 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 201 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 215 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 229 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 241 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 253 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 265 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 277 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 293 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 306 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 320 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 336 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 352 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 367 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 379 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 391 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 404 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 416 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 428 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 440 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 461 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 475 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 489 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 503 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 518 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 532 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 544 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 557 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 584 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 599 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 613 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 627 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 642 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 657 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 672 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 685 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 694 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 702 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 710 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 718 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 727 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 738 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 19 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 20 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 21 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 22 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
{
# 23 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 24 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_bankchecker.h"
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
# 22 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 23 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 24 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 25 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(1);
# 26 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 27 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 29 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 30 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 31 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 32 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 33 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fflush(stdout);
# 34 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fflush(stderr);
# 35 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
getchar();
# 36 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 37 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(0);
# 38 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 41 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 42 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 43 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int device_count = 0;
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaDeviceProp device_properties;
# 47 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int max_gflops_device = 0;
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int max_gflops = 0;
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int current_device = 0;
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
max_gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 53 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
++current_device;
# 55 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
while (current_device < device_count)
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 57 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if (gflops > max_gflops)
# 60 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
max_gflops = gflops;
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
max_gflops_device = current_device;
# 63 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
++current_device;
# 65 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
return max_gflops_device;
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 82 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 84 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 89 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 92 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 94 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 95 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 96 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 98 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 99 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 101 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 103 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 104 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 105 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 108 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 109 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 112 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 114 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 116 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 118 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 119 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 120 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 132 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 133 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 134 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 140 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 145 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 146 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 147 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int deviceCount;
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h", 148);
# 149 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 150 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 151 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 152 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 153 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
int dev = 0;
# 154 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 155 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 157 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 158 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h", 158);
# 159 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 160 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 161 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1); }
# 163 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 164 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 165 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h", 165);
# 166 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 171 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 172 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
{
# 173 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 174 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 175 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 177 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 178 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 179 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 180 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 183 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 185 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_runtime.h"
}
# 16 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 17 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 18 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 19 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 21 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 22 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 23 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 24 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 25 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 26 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 27 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 29 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 30 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 31 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 32 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 33 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 35 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 36 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 37 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 39 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 40 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 41 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 42 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 43 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 47 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 55 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
cuDevice = 0;
# 57 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 60 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h", 60); }
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 63 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 65 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
int dev = 0;
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h", 69);
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
char name[100];
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
{
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 82 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 84 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 87 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
exit(-1);
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 92 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline_drvapi.h"
}
# 12 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 13 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
{
# 14 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 3020 / 1000, 3020 % 100);
# 15 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_inline.h"
}
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 87 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return a + (t * (b - a));
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float clamp(float f, float a, float b)
# 92 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 93 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 94 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator-(int2 &a)
# 101 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 102 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 103 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 106 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 108 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2((a.x) + (b.x), (a.y) + (b.y));
# 109 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 112 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 116 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 118 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2((a.x) - (b.x), (a.y) - (b.y));
# 119 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 120 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 121 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 126 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 127 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 128 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2((a.x) * (b.x), (a.y) * (b.y));
# 129 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 130 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator*(int2 a, int s)
# 131 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 132 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 133 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 134 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int2 operator*(int s, int2 a)
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(int2 &a, int s)
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 140 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 141 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 147 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 make_float2(float s)
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 149 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(s, s);
# 150 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 151 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 make_float2(int2 a)
# 152 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 153 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 154 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 157 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator-(float2 &a)
# 158 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 159 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 160 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 163 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 164 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 165 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) + (b.x), (a.y) + (b.y));
# 166 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 167 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 168 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 169 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 170 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 173 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 174 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 175 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) - (b.x), (a.y) - (b.y));
# 176 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 177 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 178 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 179 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 180 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 183 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 184 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 185 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) * (b.x), (a.y) * (b.y));
# 186 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 187 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator*(float2 a, float s)
# 188 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 189 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 190 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 191 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator*(float s, float2 a)
# 192 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 193 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 194 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 195 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(float2 &a, float s)
# 196 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 197 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 198 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 201 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 202 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 203 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2((a.x) / (b.x), (a.y) / (b.y));
# 204 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 205 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator/(float2 a, float s)
# 206 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 207 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 208 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 209 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 210 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 operator/(float s, float2 a)
# 211 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 212 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 213 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 214 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 215 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator/=(float2 &a, float s)
# 216 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 217 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 218 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
((a) *= inv);
# 219 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 222 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 223 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 224 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 225 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 228 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 229 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 230 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 231 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 233 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 234 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 235 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 236 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 239 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float dot(float2 a, float2 b)
# 240 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 241 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 242 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 245 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float length(float2 v)
# 246 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 247 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 248 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 251 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 normalize(float2 v)
# 252 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 253 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 254 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (v * invLen);
# 255 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 258 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 floor(const float2 v)
# 259 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 260 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(floor(v.x), floor(v.y));
# 261 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 264 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 reflect(float2 i, float2 n)
# 265 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 266 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 267 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 270 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float2 fabs(float2 v)
# 271 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 272 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 273 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 279 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 make_float3(float s)
# 280 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 281 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(s, s, s);
# 282 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 283 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 make_float3(float2 a)
# 284 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 285 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 286 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 287 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 288 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 289 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(a.x, a.y, s);
# 290 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 291 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 make_float3(float4 a)
# 292 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 293 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 294 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 295 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 make_float3(int3 a)
# 296 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 297 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 298 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 301 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator-(float3 &a)
# 302 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 303 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 304 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 307 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
static inline float3 fminf(float3 a, float3 b)
# 308 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 309 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 310 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 313 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
static inline float3 fmaxf(float3 a, float3 b)
# 314 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 315 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 316 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 319 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 320 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 321 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 322 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 323 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 324 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 325 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) + b, (a.y) + b, (a.z) + b);
# 326 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 327 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 328 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 329 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 330 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 333 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 334 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 335 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 336 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 337 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 338 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 339 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) - b, (a.y) - b, (a.z) - b);
# 340 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 341 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 342 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 343 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 344 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 347 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 348 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 349 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 350 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 351 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator*(float3 a, float s)
# 352 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 353 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 354 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 355 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator*(float s, float3 a)
# 356 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 357 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 358 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 359 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(float3 &a, float s)
# 360 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 361 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 362 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 365 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 366 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 367 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 368 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 369 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator/(float3 a, float s)
# 370 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 371 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 372 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 373 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 374 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 operator/(float s, float3 a)
# 375 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 376 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 377 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 378 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 379 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator/=(float3 &a, float s)
# 380 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 381 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 382 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
((a) *= inv);
# 383 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 386 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 387 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 388 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 389 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 392 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 393 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 394 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 395 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 397 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 398 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 399 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 400 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 403 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float dot(float3 a, float3 b)
# 404 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 405 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 406 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 409 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 410 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 411 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(((a.y) * (b.z)) - ((a.z) * (b.y)), ((a.z) * (b.x)) - ((a.x) * (b.z)), ((a.x) * (b.y)) - ((a.y) * (b.x)));
# 412 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 415 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float length(float3 v)
# 416 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 417 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 418 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 421 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 normalize(float3 v)
# 422 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 423 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 424 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (v * invLen);
# 425 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 428 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 floor(const float3 v)
# 429 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 430 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(floor(v.x), floor(v.y), floor(v.z));
# 431 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 434 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 435 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 436 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 437 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 440 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float3 fabs(float3 v)
# 441 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 442 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 443 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 449 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 make_float4(float s)
# 450 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 451 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(s, s, s, s);
# 452 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 453 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 make_float4(float3 a)
# 454 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 455 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 456 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 457 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 458 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 459 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 460 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 461 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 make_float4(int4 a)
# 462 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 463 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 464 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 467 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator-(float4 &a)
# 468 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 469 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 470 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 473 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
static inline float4 fminf(float4 a, float4 b)
# 474 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 475 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 476 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 479 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
static inline float4 fmaxf(float4 a, float4 b)
# 480 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 481 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 482 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 485 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 486 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 487 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 488 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 489 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 490 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 491 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 492 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 495 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 496 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 497 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 498 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 499 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 500 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 501 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 502 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 505 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator*(float4 a, float s)
# 506 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 507 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 508 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 509 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator*(float s, float4 a)
# 510 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 511 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 512 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 513 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(float4 &a, float s)
# 514 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 515 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
# 516 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 519 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 520 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 521 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z), (a.w) / (b.w));
# 522 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 523 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator/(float4 a, float s)
# 524 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 525 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 526 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 527 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 528 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 operator/(float s, float4 a)
# 529 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 530 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 531 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a * inv);
# 532 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 533 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator/=(float4 &a, float s)
# 534 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 535 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 536 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
((a) *= inv);
# 537 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 540 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 541 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 542 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 543 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 546 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 547 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 548 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 549 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 551 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 552 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 553 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 554 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 557 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float dot(float4 a, float4 b)
# 558 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 559 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 560 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 563 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float length(float4 r)
# 564 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 565 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return sqrtf(dot(r, r));
# 566 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 569 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 normalize(float4 v)
# 570 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 571 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 572 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return (v * invLen);
# 573 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 576 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 floor(const float4 v)
# 577 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 578 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
# 579 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 582 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline float4 fabs(float4 v)
# 583 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 584 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 585 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 591 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 make_int3(int s)
# 592 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 593 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(s, s, s);
# 594 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 595 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 make_int3(float3 a)
# 596 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 597 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 598 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 601 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator-(int3 &a)
# 602 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 603 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 604 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 607 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 608 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 609 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 610 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 613 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 614 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 615 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 616 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 619 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 620 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 621 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 622 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 623 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 624 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 625 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 626 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 629 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 630 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 631 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 632 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 634 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 635 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 636 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 637 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 640 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 641 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 642 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 643 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 644 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator*(int3 a, int s)
# 645 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 646 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 647 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 648 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator*(int s, int3 a)
# 649 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 650 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 651 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 652 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(int3 &a, int s)
# 653 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 654 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 655 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 658 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator/(int3 a, int3 b)
# 659 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 660 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 661 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 662 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator/(int3 a, int s)
# 663 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 664 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 665 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 666 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 operator/(int s, int3 a)
# 667 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 668 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 669 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 670 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator/=(int3 &a, int s)
# 671 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 672 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 673 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 676 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int clamp(int f, int a, int b)
# 677 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 678 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return max(a, min(f, b));
# 679 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 681 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 682 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 683 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 684 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 686 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 687 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 688 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 689 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 696 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
# 697 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 698 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3(s, s, s);
# 699 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 700 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 make_uint3(float3 a)
# 701 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 702 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((uint)(a.x), (uint)(a.y), (uint)(a.z));
# 703 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 706 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 707 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 708 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 709 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 712 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 713 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 714 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 715 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 718 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 719 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 720 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 721 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 722 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 723 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 724 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 725 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 728 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 729 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 730 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 731 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 733 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 734 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 735 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 736 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 739 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 740 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 741 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 742 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 743 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint s)
# 744 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 745 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 746 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 747 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator*(uint s, uint3 a)
# 748 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 749 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 750 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 751 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint s)
# 752 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 753 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 754 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 757 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint3 b)
# 758 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 759 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 760 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 761 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint s)
# 762 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 763 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 764 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 765 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 operator/(uint s, uint3 a)
# 766 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 767 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 768 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 769 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline void operator/=(uint3 &a, uint s)
# 770 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 771 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 772 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 775 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 776 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 777 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return max(a, min(f, b));
# 778 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 780 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 781 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 782 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 783 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 785 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 786 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
{
# 787 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 788 "/home/normal/checkout/gpuocelot/tests/cuda2.2/sdk/cutil_math.h"
}
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
inline float3 firstEigenVector(float matrix[6])
# 45 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
{
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float3 v = make_float3((1.0F), (1.0F), (1.0F));
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
for (int i = 0; i < 8; i++) {
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float x = ((((v.x) * (matrix[0])) + ((v.y) * (matrix[1]))) + ((v.z) * (matrix[2])));
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float y = ((((v.x) * (matrix[1])) + ((v.y) * (matrix[3]))) + ((v.z) * (matrix[4])));
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float z = ((((v.x) * (matrix[2])) + ((v.y) * (matrix[4]))) + ((v.z) * (matrix[5])));
# 53 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float m = max(max(x, y), z);
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
float iv = ((1.0F) / m);
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
v = make_float3(x * iv, y * iv, z * iv);
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
}
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
return v;
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
}
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
__attribute__((unused)) inline void colorSums(const float3 *colors, float3 *sums)
# 65 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
{int volatile ___ = 1;
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
exit(___);}
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
__attribute__((unused)) inline float3 bestFitLine(const float3 *colors, float3 color_sum)
# 92 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
{int volatile ___ = 1;
# 142 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/CudaMath.h"
exit(___);}
# 45 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
extern "C" { typedef unsigned uint; }
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
extern "C" { typedef unsigned short ushort; }
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
struct DDSPixelFormat {
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint size;
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint flags;
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint fourcc;
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint bitcount;
# 53 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint rmask;
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint gmask;
# 55 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint bmask;
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint amask;
# 57 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
};
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
struct DDSCaps {
# 60 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint caps1;
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint caps2;
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint caps3;
# 63 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint caps4;
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
};
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
struct DDSHeader {
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint fourcc;
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint size;
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint flags;
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint height;
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint width;
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint pitch;
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint depth;
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint mipmapcount;
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint reserved[11];
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
DDSPixelFormat pf;
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
DDSCaps caps;
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
uint notused;
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
};
# 82 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint FOURCC_DDS = (((((unsigned)'D') | (((unsigned)'D') << 8)) | (((unsigned)'S') << 16)) | (((unsigned)' ') << 24));
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint FOURCC_DXT1 = (((((unsigned)'D') | (((unsigned)'X') << 8)) | (((unsigned)'T') << 16)) | (((unsigned)'1') << 24));
# 84 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_WIDTH = 4U;
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_HEIGHT = 2U;
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_CAPS = 1U;
# 87 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_PIXELFORMAT = 4096U;
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSCAPS_TEXTURE = 4096U;
# 89 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDPF_FOURCC = 4U;
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dds.h"
static const uint DDSD_LINEARSIZE = 524288U;
# 42 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
static void computePermutations(uint permutations[1024])
# 43 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
int indices[16];
# 45 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
int num = 0;
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int m = 0; m < 16; ++m)
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 0;
# 53 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
const int imax = 15;
# 55 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int i = imax; i >= 0; --i)
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int m = i; m < 16; ++m)
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 60 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 2;
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 62 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 63 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int j = jmax; j >= i; --j)
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
if (j < 16)
# 67 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[j]) = 1;
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
uint permutation = (0);
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int p = 0; p < 16; p++) {
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = permutation;
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
num++;
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 82 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 83 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 151, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"), 83);
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int i = 0; i < 9; i++)
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 87 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = (697685);
# 88 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
num++;
# 89 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 90 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 160, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"), 90);
# 95 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int m = 0; m < 16; ++m)
# 96 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 97 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 0;
# 98 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 100 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int i = imax; i >= 0; --i)
# 101 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 103 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int m = i; m < 16; ++m)
# 104 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 105 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 2;
# 106 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 107 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 108 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int j = jmax; j >= i; --j)
# 109 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int m = j; m < 16; ++m)
# 112 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[m]) = 3;
# 114 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 116 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
int kmax = ((j == 0) ? 15 : 16);
# 117 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int k = kmax; k >= j; --k)
# 118 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 120 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
if (k < 16)
# 121 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 122 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
((indices)[k]) = 1;
# 123 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 125 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
uint permutation = (0);
# 127 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
bool hasThree = false;
# 128 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int p = 0; p < 16; p++) {
# 129 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 132 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
if (((indices)[p]) == 3) { hasThree = true; }
# 133 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 135 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
if (hasThree) {
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = permutation;
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
num++;
# 138 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 139 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 140 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 141 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 142 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 975, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"), 142);
# 147 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
for (int i = 0; i < 49; i++)
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
{
# 149 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
(permutations[num]) = (11206485);
# 150 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
num++;
# 151 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 153 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
__cutilCondition(num == 1024, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"), 153);
# 154 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/permutations.h"
}
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
template< class T> __attribute__((unused)) inline void
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
swap(T &a, T &b)
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static float3 kColorMetric;
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void sortColors(const float *values, int *ranks)
# 86 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 130 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void loadColorBlock(const uint *image, float3 colors[16], float3 sums[16], int xrefs[16])
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 180 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 187 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) inline float3 roundAndExpand(float3 v, ushort *w)
# 188 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 198 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 201 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static float alphaTable4[4];
# 202 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static float alphaTable3[4];
# 203 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static int prods4[4];
# 204 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static int prods3[4];
# 211 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) static float evalPermutation4(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 212 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 270 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 272 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) static float evalPermutation3(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 273 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 330 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 334 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void evalAllPermutations(const float3 *colors, const uint *permutations, ushort &bestStart, ushort &bestEnd, uint &bestPermutation, float *errors, float3 color_sum)
# 335 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 393 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 399 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) int findMinError(float *errors)
# 400 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 475 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 481 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__attribute__((unused)) void saveBlockDXT1(ushort start, ushort end, uint permutation, int xrefs[16], uint2 *result)
# 482 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{int volatile ___ = 1;
# 503 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(___);}
# 509 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
void compress(const uint *permutations, const uint *image, uint2 *result) ;
# 545 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
union Color32 {
# 546 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
struct {
# 547 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char b, g, r, a;
# 548 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 549 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned u;
# 550 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 552 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
union Color16 {
# 553 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
struct {
# 554 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short b:5;
# 555 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short g:6;
# 556 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short r:5;
# 557 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 558 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned short u;
# 559 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 561 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
struct BlockDXT1 {
# 563 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
Color16 col0;
# 564 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
Color16 col1;
# 565 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
union {
# 566 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char row[4];
# 567 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned indices;
# 568 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 570 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
void decompress(Color32 [16]) const;
# 571 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
};
# 573 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
void BlockDXT1::decompress(Color32 *colors) const
# 574 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 575 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
Color32 palette[4];
# 578 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).b) = ((((col0).b) << 3) | (((col0).b) >> 2));
# 579 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).g) = ((((col0).g) << 2) | (((col0).g) >> 4));
# 580 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).r) = ((((col0).r) << 3) | (((col0).r) >> 2));
# 581 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[0]).a) = (255);
# 583 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).r) = ((((col1).r) << 3) | (((col1).r) >> 2));
# 584 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).g) = ((((col1).g) << 2) | (((col1).g) >> 4));
# 585 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).b) = ((((col1).b) << 3) | (((col1).b) >> 2));
# 586 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[1]).a) = (255);
# 588 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (((col0).u) > ((col1).u)) {
# 590 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).r) = (((2 * (((palette)[0]).r)) + (((palette)[1]).r)) / 3);
# 591 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).g) = (((2 * (((palette)[0]).g)) + (((palette)[1]).g)) / 3);
# 592 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).b) = (((2 * (((palette)[0]).b)) + (((palette)[1]).b)) / 3);
# 593 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).a) = (255);
# 595 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).r) = (((2 * (((palette)[1]).r)) + (((palette)[0]).r)) / 3);
# 596 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).g) = (((2 * (((palette)[1]).g)) + (((palette)[0]).g)) / 3);
# 597 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).b) = (((2 * (((palette)[1]).b)) + (((palette)[0]).b)) / 3);
# 598 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).a) = (255);
# 599 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 600 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 602 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).r) = (((((palette)[0]).r) + (((palette)[1]).r)) / 2);
# 603 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).g) = (((((palette)[0]).g) + (((palette)[1]).g)) / 2);
# 604 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).b) = (((((palette)[0]).b) + (((palette)[1]).b)) / 2);
# 605 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[2]).a) = (255);
# 607 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).r) = (0);
# 608 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).g) = (0);
# 609 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).b) = (0);
# 610 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(((palette)[3]).a) = (0);
# 611 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 613 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++)
# 614 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 615 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(colors[i]) = ((palette)[((indices) >> (2 * i)) & (3)]);
# 616 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 617 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 619 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static int compareColors(const Color32 *b0, const Color32 *b1)
# 620 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 621 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int sum = 0;
# 622 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++)
# 623 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 624 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int r = (((b0[i]).r) - ((b1[i]).r));
# 625 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int g = (((b0[i]).g) - ((b1[i]).g));
# 626 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int b = (((b0[i]).b) - ((b1[i]).b));
# 627 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
sum += (((r * r) + (g * g)) + (b * b));
# 628 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 629 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
return sum;
# 630 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 632 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
static int compareBlock(const BlockDXT1 *b0, const BlockDXT1 *b1)
# 633 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 634 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
Color32 colors0[16];
# 635 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
Color32 colors1[16];
# 637 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
# 638 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 639 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
return 0;
# 640 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 642 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 643 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
b0->decompress(colors0);
# 644 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
b1->decompress(colors1);
# 646 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
return compareColors(colors0, colors1);
# 647 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 648 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 654 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int main(int argc, char **argv)
# 655 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 657 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 658 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cutilDeviceInit(argc, argv); } else {
# 660 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 663 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
unsigned char *data = (__null);
# 664 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint W, H;
# 666 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
char *image_path = cutFindFilePath("lena_std.ppm", argv[0]);
# 667 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (image_path == (0)) {
# 668 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to find source image\n");
# 669 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 670 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 671 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 673 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (!(cutLoadPPM4ub(image_path, &data, &W, &H))) {
# 674 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open source image\n");
# 675 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 676 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 677 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 679 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint w, h;
# 682 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
w = (W >> 4);
# 683 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
h = (H >> 4);
# 690 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
const uint memSize = ((w * h) * (4));
# 691 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCondition((0) != memSize, (char *)("/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"), 691);
# 693 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *image = ((uint *)malloc(memSize));
# 696 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (uint by = (0); by < (h / (4)); by++) {
# 697 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (uint bx = (0); bx < (w / (4)); bx++) {
# 698 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (int i = 0; i < 16; i++) {
# 699 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
const int x = (i & 3);
# 700 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
const int y = (i / 4);
# 701 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(image[((((by * w) / (4)) + bx) * (16)) + i]) = (((uint *)data)[(((((by * (4)) + y) * (4)) * (W / (4))) + (bx * (4))) + x]);
# 703 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 704 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 705 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 708 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_data = (__null);
# 709 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_data), memSize), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 709);
# 712 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_result = (__null);
# 713 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
const uint compressedSize = (((w / (4)) * (h / (4))) * (8));
# 714 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_result), compressedSize), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 714);
# 715 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *result = ((uint *)malloc(compressedSize));
# 718 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint permutations[1024];
# 719 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
computePermutations(permutations);
# 722 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *d_permutations = (__null);
# 723 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_permutations), (1024) * sizeof(uint)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 723);
# 724 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_permutations, permutations, (1024) * sizeof(uint), cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 725);
# 728 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint timer;
# 729 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutCreateTimer(&timer), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 729);
# 731 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 731);
# 732 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutStartTimer(timer), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 732);
# 735 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_data, image, memSize, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 735);
# 737 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint blocks = (((w + (3)) / (4)) * ((h + (3)) / (4)));
# 738 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaConfigureCall(blocks, 64) ? ((void)0) : compress(d_permutations, d_data, (uint2 *)d_result);
# 740 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckMsg("compress", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 740);
# 742 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaMemcpy(result, d_result, compressedSize, cudaMemcpyDeviceToHost), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 742);
# 744 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 744);
# 745 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutStopTimer(timer), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 745);
# 747 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
float time = cutGetTimerValue(timer);
# 748 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Time %f msec\n", time);
# 750 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
char output_filename[1024];
# 751 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
strcpy(output_filename, image_path);
# 752 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
strcpy(((output_filename) + strlen(image_path)) - 3, "dds");
# 755 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
FILE *fp = fopen(output_filename, "wb");
# 756 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (fp == (0)) {
# 757 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open output image\n");
# 758 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 759 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 760 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 762 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
DDSHeader header;
# 763 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.fourcc) = FOURCC_DDS;
# 764 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.size) = (124);
# 765 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.flags) = ((((DDSD_WIDTH | DDSD_HEIGHT) | DDSD_CAPS) | DDSD_PIXELFORMAT) | DDSD_LINEARSIZE);
# 766 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.height) = h;
# 767 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.width) = w;
# 768 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.pitch) = compressedSize;
# 769 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.depth) = (0);
# 770 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.mipmapcount) = (0);
# 771 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
memset(header.reserved, 0, sizeof(header.reserved));
# 772 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).size) = (32);
# 773 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).flags) = DDPF_FOURCC;
# 774 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).fourcc) = FOURCC_DXT1;
# 775 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).bitcount) = (0);
# 776 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).rmask) = (0);
# 777 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).gmask) = (0);
# 778 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).bmask) = (0);
# 779 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.pf).amask) = (0);
# 780 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps1) = DDSCAPS_TEXTURE;
# 781 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps2) = (0);
# 782 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps3) = (0);
# 783 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
((header.caps).caps4) = (0);
# 784 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
(header.notused) = (0);
# 786 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fwrite(&header, sizeof(DDSHeader), 1, fp);
# 787 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fwrite(result, compressedSize, 1, fp);
# 789 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fclose(fp);
# 792 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
const char *reference_image_path = (cutFindFilePath("lena_ref.dds", argv[0]));
# 793 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (reference_image_path == (0)) {
# 794 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to find reference image\n");
# 795 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 796 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 797 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 799 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fp = fopen(reference_image_path, "rb");
# 800 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (fp == (0)) {
# 801 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error, unable to open reference image\n");
# 802 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 803 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
exit(1);
# 804 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 806 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fseek(fp, sizeof(DDSHeader), 0);
# 808 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint referenceSize = (((W / (4)) * (H / (4))) * (8));
# 809 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint *reference = ((uint *)malloc(referenceSize));
# 810 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fread(reference, referenceSize, 1, fp);
# 812 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
fclose(fp);
# 814 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
float rms = (0);
# 816 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (uint y = (0); y < h; y += (4))
# 817 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 818 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
for (uint x = (0); x < w; x += (4))
# 819 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 820 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint referenceBlockIdx = (((y / (4)) * (W / (4))) + (x / (4)));
# 821 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
uint resultBlockIdx = (((y / (4)) * (w / (4))) + (x / (4)));
# 823 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
int cmp = compareBlock(((BlockDXT1 *)result) + resultBlockIdx, ((BlockDXT1 *)reference) + referenceBlockIdx);
# 824 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (cmp != (0.0F)) {
# 825 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Error at (%d, %d):\t%f rms\n", x / (4), y / (4), (((float)cmp) / (16)) / (3));
# 826 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 827 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
rms += cmp;
# 828 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 829 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 830 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
rms /= ((w * h) * (3));
# 832 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("RMS(reference, result) = %f\n", rms);
# 834 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
if (rms <= (0.1000000015F))
# 835 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 836 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Test PASSED\n");
# 837 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
} else
# 839 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{
# 840 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
printf("Test FAILED\n");
# 841 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 844 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cutFree(image_path);
# 845 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cutFree(data);
# 846 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
free(image);
# 847 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_permutations), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 847);
# 848 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_data), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 848);
# 849 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cudaSafeCall(cudaFree(d_result), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 849);
# 850 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
free(result);
# 852 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilCheckError(cutDeleteTimer(timer), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu", 852);
# 854 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
cudaThreadExit();
# 856 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
__cutilExit(argc, argv); return 0;
# 857 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00005e9a_00000000-3_dxtc.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00005e9a_00000000-3_dxtc.fatbin.c" 2

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
".quad 0x75635f5f20323375,0x31666d7261706164,0x72696636315a5f5f,0x566e656769457473\n"
".quad 0x296650726f746365,0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063\n"
".quad 0x6e67696c612e206d,0x5f2038622e203420,0x746572616475635f,0x656231315a5f5f66\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x5d32315b5f533374,0x656231315a5f2029\n"
".quad 0x6e694c7469467473,0x616f6c66364b5065,0x702e28205f533374,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f31666d726170,0x467473656231315a,0x4b50656e694c7469\n"
".quad 0x533374616f6c6636,0x617261702e202c5f,0x6e67696c612e206d,0x5f2038622e203420\n"
".quad 0x726170616475635f,0x31315a5f5f32666d,0x4c74694674736562,0x6c66364b50656e69\n"
".quad 0x315b5f533374616f,0x762e090a0a295d32,0x2e20656c62697369,0x315a5f20636e7566\n"
".quad 0x6c6f4374726f7330,0x6950664b5073726f,0x6d617261702e2820,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x7330315a5f5f3166,0x726f6c6f4374726f,0x202c6950664b5073\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x32666d7261706164,0x726f7330315a5f5f\n"
".quad 0x5073726f6c6f4374,0x090a0a296950664b,0x656c62697369762e,0x5f20636e75662e20\n"
".quad 0x4364616f6c34315a,0x636f6c42726f6c6f,0x6c6636506a4b506b,0x505f32533374616f\n"
".quad 0x617261702e282069,0x5f203233752e206d,0x726170616475635f,0x34315a5f5f31666d\n"
".quad 0x6f6c6f4364616f6c,0x4b506b636f6c4272,0x74616f6c6636506a,0x202c69505f325333\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x32666d7261706164,0x616f6c34315a5f5f\n"
".quad 0x6c42726f6c6f4364,0x36506a4b506b636f,0x32533374616f6c66,0x61702e202c69505f\n"
".quad 0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x6f4364616f6c3431\n"
".quad 0x6b636f6c42726f6c,0x6f6c6636506a4b50,0x69505f3253337461,0x6d617261702e202c\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x6c34315a5f5f3466,0x726f6c6f4364616f\n"
".quad 0x6a4b506b636f6c42,0x3374616f6c663650,0x0a0a2969505f3253,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x6c61766539315a5f,0x756d7265506c6c41,0x50736e6f69746174\n"
".quad 0x3374616f6c66364b,0x5f345374526a4b50,0x28205f5366506a52,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x31666d7261706164,0x61766539315a5f5f,0x6d7265506c6c416c\n"
".quad 0x736e6f6974617475,0x74616f6c66364b50,0x345374526a4b5033,0x2c5f5366506a525f\n"
".quad 0x206d617261702e20,0x635f5f203233752e,0x666d726170616475,0x766539315a5f5f32\n"
".quad 0x7265506c6c416c61,0x6e6f69746174756d,0x616f6c66364b5073,0x5374526a4b503374\n"
".quad 0x5f5366506a525f34,0x6d617261702e202c,0x5f5f203233752e20,0x6d72617061647563\n"
".quad 0x6539315a5f5f3366,0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e\n"
".quad 0x74526a4b50337461,0x5366506a525f3453,0x617261702e202c5f,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x39315a5f5f34666d,0x506c6c416c617665,0x69746174756d7265\n"
".quad 0x6c66364b50736e6f,0x526a4b503374616f,0x66506a525f345374,0x7261702e202c5f53\n"
".quad 0x203233752e206d61,0x6170616475635f5f,0x315a5f5f35666d72,0x6c6c416c61766539\n"
".quad 0x746174756d726550,0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452\n"
".quad 0x61702e202c5f5366,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f36666d7261\n"
".quad 0x6c416c6176653931,0x6174756d7265506c,0x364b50736e6f6974,0x4b503374616f6c66\n"
".quad 0x6a525f345374526a,0x702e202c5f536650,0x6c612e206d617261,0x622e2034206e6769\n"
".quad 0x616475635f5f2038,0x5f5f37666d726170,0x416c61766539315a,0x74756d7265506c6c\n"
".quad 0x4b50736e6f697461,0x503374616f6c6636,0x525f345374526a4b,0x32315b5f5366506a\n"
".quad 0x69762e090a0a295d,0x662e20656c626973,0x73345a5f20636e75,0x5276457449706177\n"
".quad 0x2e28205f31535f54,0x752e206d61726170,0x6475635f5f203233,0x5f31666d72617061\n"
".quad 0x4970617773345a5f,0x31535f5452764574,0x617261702e202c5f,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x73345a5f5f32666d,0x5276457449706177,0x0a0a295f31535f54\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e\n"
".quad 0x5f66746572616475,0x646e696632315a5f,0x726f7272456e694d,0x32315a5f20296650\n"
".quad 0x456e694d646e6966,0x28206650726f7272,0x2e206d617261702e,0x75635f5f20323375\n"
".quad 0x31666d7261706164,0x6e696632315a5f5f,0x6f7272456e694d64,0x2e090a0a29665072\n"
".quad 0x20656c6269736976,0x5a5f20636e75662e,0x6c42657661733331,0x74315458446b636f\n"
".quad 0x6975355069506a74,0x61702e282032746e,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f31666d7261,0x6c42657661733331,0x74315458446b636f,0x6975355069506a74\n"
".quad 0x61702e202c32746e,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261\n"
".quad 0x6c42657661733331,0x74315458446b636f,0x6975355069506a74,0x61702e202c32746e\n"
".quad 0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x6c42657661733331\n"
".quad 0x74315458446b636f,0x6975355069506a74,0x61702e202c32746e,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f34666d7261,0x6c42657661733331,0x74315458446b636f\n"
".quad 0x6975355069506a74,0x61702e202c32746e,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f35666d7261,0x6c42657661733331,0x74315458446b636f,0x6975355069506a74\n"
".quad 0x2f090a0a2932746e,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x696c69706d6f4320,0x2f706d742f20676e,0x305f746678706d74\n"
".quad 0x5f61396535303030,0x3030303030303030,0x2e637478645f372d,0x2820692e33707063\n"
".quad 0x4263632f706d742f,0x484d3736362e2349,0x2d2d2f2f090a2933,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2f2f090a0a2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x704f202f2f090a2d,0x090a3a736e6f6974\n"
".quad 0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d\n"
".quad 0x656772615420202f,0x49202c7874703a74,0x30325f6d733a4153,0x6e6169646e45202c\n"
".quad 0x2c656c7474696c3a,0x7265746e696f5020,0x32333a657a695320,0x4f2d20202f2f090a\n"
".quad 0x6d6974704f280933,0x206e6f6974617a69,0x090a296c6576656c,0x0930672d20202f2f\n"
".quad 0x6c20677562654428,0x2f090a296c657665,0x2809326d2d20202f,0x612074726f706552\n"
".quad 0x6569726f73697664,0x2d2d2f2f090a2973,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x6c69662e090a0a2d,0x6f633c2209310965,0x696c2d646e616d6d\n"
".quad 0x662e090a223e656e,0x2f22093209656c69,0x78706d742f706d74,0x35303030305f7466\n"
".quad 0x303030305f613965,0x645f362d30303030,0x616475632e637478,0x227570672e326566\n"
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
".quad 0x2f746f6c65636f75,0x75632f7374736574,0x65742f322e326164,0x637478642f737473\n"
".quad 0x74614d616475432f,0x662e090a22682e68,0x2209373109656c69,0x6f6e2f656d6f682f\n"
".quad 0x6568632f6c616d72,0x70672f74756f6b63,0x2f746f6c65636f75,0x75632f7374736574\n"
".quad 0x65742f322e326164,0x637478642f737473,0x75632e637478642f,0x656c69662e090a22\n"
".quad 0x73752f2209383109,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x6d6d6f632f656475,0x74636e75665f6e6f,0x0a22682e736e6f69,0x3109656c69662e09\n"
".quad 0x2f7273752f220939,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x665f6874616d2f65,0x736e6f6974636e75,0x69662e090a22682e,0x2f2209303209656c\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x616d2f6564756c63\n"
".quad 0x74736e6f635f6874,0x0a22682e73746e61,0x3209656c69662e09,0x2f7273752f220931\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09323209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x74615f31315f6d73\n"
".quad 0x6e75665f63696d6f,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209333209\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x315f6d732f656475\n"
".quad 0x63696d6f74615f32,0x6f6974636e75665f,0x2e090a22682e736e,0x09343209656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x6f645f33315f6d73,0x6e75665f656c6275,0x682e736e6f697463,0x656c69662e090a22\n"
".quad 0x73752f2209353209,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x325f6d732f656475,0x63696d6f74615f30,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09363209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x6e695f30325f6d73,0x736369736e697274,0x69662e090a22682e\n"
".quad 0x2f2209373209656c,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x75732f6564756c63,0x75665f6563616672,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220938320965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x7865742f6564756c,0x7465665f65727574,0x74636e75665f6863,0x0a22682e736e6f69\n"
".quad 0x3209656c69662e09,0x2f7273752f220939,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x665f6874616d2f65,0x736e6f6974636e75,0x7874705f6c62645f\n"
".quad 0x090a0a0a22682e33,0x656c62697369762e,0x2820636e75662e20,0x2e206d617261702e\n"
".quad 0x2034206e67696c61,0x75635f5f2038622e,0x5f5f667465726164,0x747372696636315a\n"
".quad 0x6365566e65676945,0x32315b6650726f74,0x6636315a5f20295d,0x6567694574737269\n"
".quad 0x50726f746365566e,0x617261702e282066,0x5f203233752e206d,0x726170616475635f\n"
".quad 0x36315a5f5f31666d,0x6769457473726966,0x726f746365566e65,0x090a7b090a296650\n"
".quad 0x33752e206765722e,0x3b3e343c72252032,0x2e206765722e090a,0x313c662520323366\n"
".quad 0x6c2e090a3b3e3133,0x353409363109636f,0x6257444c240a3009,0x315a5f5f6e696765\n"
".quad 0x6945747372696636,0x6f746365566e6567,0x646c090a3a665072,0x752e6d617261702e\n"
".quad 0x2c31722509203233,0x616475635f5f5b20,0x5f5f31666d726170,0x747372696636315a\n"
".quad 0x6365566e65676945,0x0a3b5d6650726f74,0x3233732e766f6d09,0x25202c3272250920\n"
".quad 0x6f6c2e090a3b3172,0x0930350936310963,0x33662e646c090a30,0x202c316625092032\n"
".quad 0x3b5d342b3272255b,0x3233662e646c090a,0x5b202c3266250920,0x0a3b5d302b327225\n"
".quad 0x203233662e646c09,0x255b202c33662509,0x090a3b5d382b3272,0x203233662e766f6d\n"
".quad 0x6630202c34662509,0x3030303030386633,0x2f0920202020203b,0x616d66090a31202f\n"
".quad 0x203233662e6e722e,0x6625202c35662509,0x202c346625202c32,0x6f6d090a3b316625\n"
".quad 0x2509203233662e76,0x66336630202c3666,0x203b303030303038,0x202f2f0920202020\n"
".quad 0x722e616d66090a31,0x2509203233662e6e,0x2c336625202c3766,0x6625202c36662520\n"
".quad 0x636f6c2e090a3b35,0x3009313509363109,0x3233662e646c090a,0x5b202c3866250920\n"
".quad 0x3b5d32312b327225,0x3233662e646c090a,0x5b202c3966250920,0x3b5d36312b327225\n"
".quad 0x33662e766f6d090a,0x2c30316625092032,0x3030386633663020,0x202020203b303030\n"
".quad 0x66090a31202f2f09,0x33662e6e722e616d,0x2c31316625092032,0x6625202c31662520\n"
".quad 0x3b386625202c3031,0x33662e766f6d090a,0x2c32316625092032,0x3030386633663020\n"
".quad 0x202020203b303030,0x66090a31202f2f09,0x33662e6e722e616d,0x2c33316625092032\n"
".quad 0x6625202c39662520,0x31316625202c3231,0x09636f6c2e090a3b,0x0a30093235093631\n"
".quad 0x203233662e646c09,0x5b202c3431662509,0x3b5d30322b327225,0x33662e766f6d090a\n"
".quad 0x2c35316625092032,0x3030386633663020,0x202020203b303030,0x66090a31202f2f09\n"
".quad 0x33662e6e722e616d,0x2c36316625092032,0x6625202c33662520,0x3b396625202c3531\n"
".quad 0x33662e766f6d090a,0x2c37316625092032,0x3030386633663020,0x202020203b303030\n"
".quad 0x66090a31202f2f09,0x33662e6e722e616d,0x2c38316625092032,0x25202c3431662520\n"
".quad 0x316625202c373166,0x636f6c2e090a3b36,0x3009383509363109,0x33662e78616d090a\n"
".quad 0x2c39316625092032,0x6625202c37662520,0x78616d090a3b3331,0x662509203233662e\n"
".quad 0x39316625202c3032,0x0a3b38316625202c,0x2e6e722e70637209,0x3266250920323366\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x2c32326625092032,0x25202c3132662520\n"
".quad 0x6c756d090a3b3766,0x662509203233662e,0x31326625202c3332,0x0a3b33316625202c\n"
".quad 0x3233662e6c756d09,0x202c343266250920,0x6625202c31326625,0x6f6c2e090a3b3831\n"
".quad 0x0930350936310963,0x662e6c756d090a30,0x3532662509203233,0x25202c316625202c\n"
".quad 0x6d66090a3b333266,0x3233662e6e722e61,0x202c363266250920,0x326625202c326625\n"
".quad 0x3b35326625202c32,0x6e722e616d66090a,0x662509203233662e,0x2c336625202c3732\n"
".quad 0x25202c3432662520,0x6c2e090a3b363266,0x313509363109636f,0x2e6c756d090a3009\n"
".quad 0x3266250920323366,0x202c386625202c38,0x66090a3b33326625,0x33662e6e722e616d\n"
".quad 0x2c39326625092032,0x6625202c31662520,0x38326625202c3232,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x396625202c303366,0x202c34326625202c,0x2e090a3b39326625\n"
".quad 0x3509363109636f6c,0x6c756d090a300932,0x662509203233662e,0x2c396625202c3133\n"
".quad 0x090a3b3332662520,0x662e6e722e616d66,0x3233662509203233,0x25202c336625202c\n"
".quad 0x336625202c323266,0x2e616d66090a3b31,0x09203233662e6e72,0x6625202c33336625\n"
".quad 0x34326625202c3431,0x0a3b32336625202c,0x363109636f6c2e09,0x6d090a3009383509\n"
".quad 0x09203233662e7861,0x6625202c34336625,0x30336625202c3732,0x662e78616d090a3b\n"
".quad 0x3533662509203233,0x202c34336625202c,0x72090a3b33336625,0x33662e6e722e7063\n"
".quad 0x2c36336625092032,0x090a3b3533662520,0x203233662e6c756d,0x25202c3733662509\n"
".quad 0x326625202c363366,0x2e6c756d090a3b37,0x3366250920323366,0x2c36336625202c38\n"
".quad 0x090a3b3033662520,0x203233662e6c756d,0x25202c3933662509,0x336625202c363366\n"
".quad 0x636f6c2e090a3b33,0x3009303509363109,0x33662e6c756d090a,0x2c30346625092032\n"
".quad 0x6625202c31662520,0x616d66090a3b3833,0x203233662e6e722e,0x25202c3134662509\n"
".quad 0x37336625202c3266,0x0a3b30346625202c,0x2e6e722e616d6609,0x3466250920323366\n"
".quad 0x202c336625202c32,0x6625202c39336625,0x6f6c2e090a3b3134,0x0931350936310963\n"
".quad 0x662e6c756d090a30,0x3334662509203233,0x25202c386625202c,0x6d66090a3b383366\n"
".quad 0x3233662e6e722e61,0x202c343466250920,0x336625202c316625,0x3b33346625202c37\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x2c396625202c3534,0x25202c3933662520\n"
".quad 0x6c2e090a3b343466,0x323509363109636f,0x2e6c756d090a3009,0x3466250920323366\n"
".quad 0x202c396625202c36,0x66090a3b38336625,0x33662e6e722e616d,0x2c37346625092032\n"
".quad 0x6625202c33662520,0x36346625202c3733,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x316625202c383466,0x2c39336625202c34,0x090a3b3734662520,0x09363109636f6c2e\n"
".quad 0x616d090a30093835,0x2509203233662e78,0x346625202c393466,0x3b35346625202c32\n"
".quad 0x33662e78616d090a,0x2c30356625092032,0x25202c3934662520,0x6372090a3b383466\n"
".quad 0x3233662e6e722e70,0x202c313566250920,0x6d090a3b30356625,0x09203233662e6c75\n"
".quad 0x6625202c32356625,0x32346625202c3135,0x662e6c756d090a3b,0x3335662509203233\n"
".quad 0x202c31356625202c,0x6d090a3b35346625,0x09203233662e6c75,0x6625202c34356625\n"
".quad 0x38346625202c3135,0x09636f6c2e090a3b,0x0a30093035093631,0x3233662e6c756d09\n"
".quad 0x202c353566250920,0x356625202c316625,0x2e616d66090a3b33,0x09203233662e6e72\n"
".quad 0x6625202c36356625,0x2c32356625202c32,0x090a3b3535662520,0x662e6e722e616d66\n"
".quad 0x3735662509203233,0x25202c336625202c,0x356625202c343566,0x636f6c2e090a3b36\n"
".quad 0x3009313509363109,0x33662e6c756d090a,0x2c38356625092032,0x6625202c38662520\n"
".quad 0x616d66090a3b3335,0x203233662e6e722e,0x25202c3935662509,0x32356625202c3166\n"
".quad 0x0a3b38356625202c,0x2e6e722e616d6609,0x3666250920323366,0x202c396625202c30\n"
".quad 0x6625202c34356625,0x6f6c2e090a3b3935,0x0932350936310963,0x662e6c756d090a30\n"
".quad 0x3136662509203233,0x25202c396625202c,0x6d66090a3b333566,0x3233662e6e722e61\n"
".quad 0x202c323666250920,0x356625202c336625,0x3b31366625202c32,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x34316625202c3336,0x202c34356625202c,0x2e090a3b32366625\n"
".quad 0x3509363109636f6c,0x78616d090a300938,0x662509203233662e,0x37356625202c3436\n"
".quad 0x0a3b30366625202c,0x3233662e78616d09,0x202c353666250920,0x6625202c34366625\n"
".quad 0x706372090a3b3336,0x203233662e6e722e,0x25202c3636662509,0x756d090a3b353666\n"
".quad 0x2509203233662e6c,0x366625202c373666,0x3b37356625202c36,0x33662e6c756d090a\n"
".quad 0x2c38366625092032,0x25202c3636662520,0x756d090a3b303666,0x2509203233662e6c\n"
".quad 0x366625202c393666,0x3b33366625202c36,0x3109636f6c2e090a,0x090a300930350936\n"
".quad 0x203233662e6c756d,0x25202c3037662509,0x38366625202c3166,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x326625202c313766,0x202c37366625202c,0x66090a3b30376625\n"
".quad 0x33662e6e722e616d,0x2c32376625092032,0x6625202c33662520,0x31376625202c3936\n"
".quad 0x09636f6c2e090a3b,0x0a30093135093631,0x3233662e6c756d09,0x202c333766250920\n"
".quad 0x366625202c386625,0x2e616d66090a3b38,0x09203233662e6e72,0x6625202c34376625\n"
".quad 0x2c37366625202c31,0x090a3b3337662520,0x662e6e722e616d66,0x3537662509203233\n"
".quad 0x25202c396625202c,0x376625202c393666,0x636f6c2e090a3b34,0x3009323509363109\n"
".quad 0x33662e6c756d090a,0x2c36376625092032,0x6625202c39662520,0x616d66090a3b3836\n"
".quad 0x203233662e6e722e,0x25202c3737662509,0x37366625202c3366,0x0a3b36376625202c\n"
".quad 0x2e6e722e616d6609,0x3766250920323366,0x2c34316625202c38,0x25202c3936662520\n"
".quad 0x6c2e090a3b373766,0x383509363109636f,0x2e78616d090a3009,0x3766250920323366\n"
".quad 0x2c32376625202c39,0x090a3b3537662520,0x203233662e78616d,0x25202c3038662509\n"
".quad 0x376625202c393766,0x2e706372090a3b38,0x09203233662e6e72,0x6625202c31386625\n"
".quad 0x6c756d090a3b3038,0x662509203233662e,0x31386625202c3238,0x0a3b32376625202c\n"
".quad 0x3233662e6c756d09,0x202c333866250920,0x6625202c31386625,0x6c756d090a3b3537\n"
".quad 0x662509203233662e,0x31386625202c3438,0x0a3b38376625202c,0x363109636f6c2e09\n"
".quad 0x6d090a3009303509,0x09203233662e6c75,0x6625202c35386625,0x3b33386625202c31\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x2c326625202c3638,0x25202c3238662520\n"
".quad 0x6d66090a3b353866,0x3233662e6e722e61,0x202c373866250920,0x386625202c336625\n"
".quad 0x3b36386625202c34,0x3109636f6c2e090a,0x090a300931350936,0x203233662e6c756d\n"
".quad 0x25202c3838662509,0x33386625202c3866,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x316625202c393866,0x202c32386625202c,0x66090a3b38386625,0x33662e6e722e616d\n"
".quad 0x2c30396625092032,0x6625202c39662520,0x39386625202c3438,0x09636f6c2e090a3b\n"
".quad 0x0a30093235093631,0x3233662e6c756d09,0x202c313966250920,0x386625202c396625\n"
".quad 0x2e616d66090a3b33,0x09203233662e6e72,0x6625202c32396625,0x2c32386625202c33\n"
".quad 0x090a3b3139662520,0x662e6e722e616d66,0x3339662509203233,0x202c34316625202c\n"
".quad 0x6625202c34386625,0x6f6c2e090a3b3239,0x0938350936310963,0x662e78616d090a30\n"
".quad 0x3439662509203233,0x202c37386625202c,0x6d090a3b30396625,0x09203233662e7861\n"
".quad 0x6625202c35396625,0x33396625202c3439,0x722e706372090a3b,0x2509203233662e6e\n"
".quad 0x396625202c363966,0x2e6c756d090a3b35,0x3966250920323366,0x2c36396625202c37\n"
".quad 0x090a3b3738662520,0x203233662e6c756d,0x25202c3839662509,0x396625202c363966\n"
".quad 0x2e6c756d090a3b30,0x3966250920323366,0x2c36396625202c39,0x090a3b3339662520\n"
".quad 0x09363109636f6c2e,0x756d090a30093035,0x2509203233662e6c,0x6625202c30303166\n"
".quad 0x3b38396625202c31,0x6e722e616d66090a,0x662509203233662e,0x326625202c313031\n"
".quad 0x202c37396625202c,0x090a3b3030316625,0x662e6e722e616d66,0x3031662509203233\n"
".quad 0x202c336625202c32,0x6625202c39396625,0x6c2e090a3b313031,0x313509363109636f\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x2c386625202c3330,0x090a3b3839662520\n"
".quad 0x662e6e722e616d66,0x3031662509203233,0x202c316625202c34,0x6625202c37396625\n"
".quad 0x6d66090a3b333031,0x3233662e6e722e61,0x2c35303166250920,0x6625202c39662520\n"
".quad 0x30316625202c3939,0x636f6c2e090a3b34,0x3009323509363109,0x33662e6c756d090a\n"
".quad 0x3630316625092032,0x25202c396625202c,0x6d66090a3b383966,0x3233662e6e722e61\n"
".quad 0x2c37303166250920,0x6625202c33662520,0x30316625202c3739,0x2e616d66090a3b36\n"
".quad 0x09203233662e6e72,0x25202c3830316625,0x396625202c343166,0x3730316625202c39\n"
".quad 0x09636f6c2e090a3b,0x0a30093835093631,0x3233662e78616d09,0x2c39303166250920\n"
".quad 0x202c323031662520,0x090a3b3530316625,0x203233662e78616d,0x202c303131662509\n"
".quad 0x25202c3930316625,0x72090a3b38303166,0x33662e6e722e7063,0x3131316625092032\n"
".quad 0x3b3031316625202c,0x33662e6c756d090a,0x3231316625092032,0x2c3131316625202c\n"
".quad 0x0a3b323031662520,0x3233662e6c756d09,0x2c33313166250920,0x202c313131662520\n"
".quad 0x090a3b3530316625,0x203233662e6c756d,0x202c343131662509,0x25202c3131316625\n"
".quad 0x2e090a3b38303166,0x3509363109636f6c,0x6c756d090a300930,0x662509203233662e\n"
".quad 0x316625202c353131,0x3b3331316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x326625202c363131,0x2c3231316625202c,0x0a3b353131662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x2c336625202c3731,0x202c343131662520,0x090a3b3631316625\n"
".quad 0x09363109636f6c2e,0x756d090a30093135,0x2509203233662e6c,0x6625202c38313166\n"
".quad 0x3331316625202c38,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c39313166\n"
".quad 0x3231316625202c31,0x3b3831316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x396625202c303231,0x2c3431316625202c,0x0a3b393131662520,0x363109636f6c2e09\n"
".quad 0x6d090a3009323509,0x09203233662e6c75,0x25202c3132316625,0x31316625202c3966\n"
".quad 0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3232316625,0x31316625202c3366\n"
".quad 0x3132316625202c32,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c33323166\n"
".quad 0x31316625202c3431,0x3232316625202c34,0x09636f6c2e090a3b,0x0a30093136093631\n"
".quad 0x3233662e78616d09,0x2c34323166250920,0x202c373131662520,0x090a3b3032316625\n"
".quad 0x203233662e78616d,0x202c353231662509,0x25202c3432316625,0x72090a3b33323166\n"
".quad 0x33662e6e722e7063,0x3632316625092032,0x3b3532316625202c,0x33662e6c756d090a\n"
".quad 0x3732316625092032,0x2c3632316625202c,0x0a3b373131662520,0x617261702e747309\n"
".quad 0x5b09203233662e6d,0x6572616475635f5f,0x6636315a5f5f6674,0x6567694574737269\n"
".quad 0x50726f746365566e,0x6625202c5d302b66,0x756d090a3b373231,0x2509203233662e6c\n"
".quad 0x6625202c38323166,0x316625202c363231,0x2e7473090a3b3032,0x33662e6d61726170\n"
".quad 0x75635f5f5b092032,0x5f5f667465726164,0x747372696636315a,0x6365566e65676945\n"
".quad 0x5d342b6650726f74,0x3b3832316625202c,0x33662e6c756d090a,0x3932316625092032\n"
".quad 0x2c3632316625202c,0x0a3b333231662520,0x617261702e747309,0x5b09203233662e6d\n"
".quad 0x6572616475635f5f,0x6636315a5f5f6674,0x6567694574737269,0x50726f746365566e\n"
".quad 0x6625202c5d382b66,0x6572090a3b393231,0x6557444c240a3b74,0x6636315a5f5f646e\n"
".quad 0x6567694574737269,0x50726f746365566e,0x2f2f207d090a3a66,0x72696636315a5f20\n"
".quad 0x566e656769457473,0x0a6650726f746365,0x6465726168732e09,0x206e67696c612e20\n"
".quad 0x5f2038622e203631,0x6f6c5f616475635f,0x5f7261765f6c6163,0x35335f3136353733\n"
".quad 0x6e6f635f6e6f6e5f,0x7261766f635f7473,0x305f5f65636e6169,0x0a0a3b5d3438335b\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28,0x34206e67696c612e\n"
".quad 0x635f5f2038622e20,0x5f66746572616475,0x7473656231315a5f,0x50656e694c746946\n"
".quad 0x3374616f6c66364b,0x20295d32315b5f53,0x7473656231315a5f,0x50656e694c746946\n"
".quad 0x3374616f6c66364b,0x7261702e28205f53,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f31666d72,0x7469467473656231,0x66364b50656e694c,0x2c5f533374616f6c\n"
".quad 0x206d617261702e20,0x34206e67696c612e,0x635f5f2038622e20,0x666d726170616475\n"
".quad 0x656231315a5f5f32,0x6e694c7469467473,0x616f6c66364b5065,0x5d32315b5f533374\n"
".quad 0x722e090a7b090a29,0x203233752e206765,0x0a3b3e38333c7225,0x662e206765722e09\n"
".quad 0x38313c6625203233,0x65722e090a3b3e31,0x20646572702e2067,0x090a3b3e353c7025\n"
".quad 0x6475635f5f202f2f,0x5f6c61636f6c5f61,0x353537335f726176,0x6e6f6e5f32315f35\n"
".quad 0x645f74736e6f635f,0x0a30203d20666669,0x363109636f6c2e09,0x4c240a3009323909\n"
".quad 0x5f6e696765625744,0x7473656231315a5f,0x50656e694c746946,0x3374616f6c66364b\n"
".quad 0x2e646c090a3a5f53,0x33752e6d61726170,0x202c317225092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f31666d7261,0x6946747365623131,0x364b50656e694c74,0x5f533374616f6c66\n"
".quad 0x2e766f6d090a3b5d,0x3272250920323373,0x090a3b317225202c,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c31,0x32666d7261706164,0x73656231315a5f5f\n"
".quad 0x656e694c74694674,0x74616f6c66364b50,0x0a3b5d302b5f5333,0x3233662e766f6d09\n"
".quad 0x25202c3266250920,0x2e646c090a3b3166,0x33662e6d61726170,0x202c336625092032\n"
".quad 0x70616475635f5f5b,0x5a5f5f32666d7261,0x6946747365623131,0x364b50656e694c74\n"
".quad 0x5f533374616f6c66,0x6f6d090a3b5d342b,0x2509203233662e76,0x3b336625202c3466\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c356625,0x6d72617061647563\n"
".quad 0x6231315a5f5f3266,0x694c746946747365,0x6f6c66364b50656e,0x5d382b5f53337461\n"
".quad 0x662e766f6d090a3b,0x2c36662509203233,0x63090a3b35662520,0x752e3233732e7476\n"
".quad 0x2c33722509203233,0x3b782e6469742520,0x33732e766f6d090a,0x202c347225092032\n"
".quad 0x746573090a3b3531,0x3233732e656c2e70,0x25202c3170250920,0x3b347225202c3372\n"
".quad 0x203170252140090a,0x744c240920617262,0x3b303534385f315f,0x3109636f6c2e090a\n"
".quad 0x0a30093231310936,0x2e6f6c2e6c756d09,0x3572250920323375,0x31202c337225202c\n"
".quad 0x2e646461090a3b32,0x3672250920323375,0x25202c357225202c,0x2e646c090a3b3272\n"
".quad 0x3766250920323366,0x302b3672255b202c,0x2e766f6d090a3b5d,0x3866250920323366\n"
".quad 0x303864336630202c,0x2020203b30303030,0x2e30202f2f092020,0x756d090a35323630\n"
".quad 0x2509203233662e6c,0x2c386625202c3966,0x73090a3b32662520,0x09203233662e6275\n"
".quad 0x6625202c30316625,0x0a3b396625202c37,0x3233662e766f6d09,0x202c313166250920\n"
".quad 0x6c090a3b30316625,0x2509203233662e64,0x72255b202c323166,0x6d090a3b5d342b36\n"
".quad 0x09203233662e766f,0x6630202c33316625,0x3030303030386433,0x2f2f09202020203b\n"
".quad 0x0a353236302e3020,0x3233662e6c756d09,0x202c343166250920,0x6625202c33316625\n"
".quad 0x2e627573090a3b34,0x3166250920323366,0x2c32316625202c35,0x090a3b3431662520\n"
".quad 0x203233662e766f6d,0x25202c3631662509,0x646c090a3b353166,0x662509203233662e\n"
".quad 0x3672255b202c3731,0x6f6d090a3b5d382b,0x2509203233662e76,0x336630202c383166\n"
".quad 0x3b30303030303864,0x202f2f0920202020,0x090a353236302e30,0x203233662e6c756d\n"
".quad 0x25202c3931662509,0x366625202c383166,0x662e627573090a3b,0x3032662509203233\n"
".quad 0x202c37316625202c,0x6d090a3b39316625,0x09203233662e766f,0x6625202c31326625\n"
".quad 0x5f744c240a3b3032,0x0a3a303534385f31,0x6220317025214009,0x5f744c2409206172\n"
".quad 0x0a3b323639385f31,0x363109636f6c2e09,0x090a300939313109,0x6168732e61747663\n"
".quad 0x203233752e646572,0x5f5f202c37722509,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f35335f31363537,0x736e6f635f6e6f6e,0x697261766f635f74,0x3b305f5f65636e61\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x202c337225202c38,0x2e6c756d090a3b36\n"
".quad 0x09203233752e6f6c,0x387225202c397225,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x397225202c303172,0x090a3b377225202c,0x203233662e766f6d,0x25202c3232662509\n"
".quad 0x756d090a3b313166,0x2509203233662e6c,0x326625202c333266,0x3b32326625202c32\n"
".quad 0x3233662e7473090a,0x2b303172255b0920,0x33326625202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009303231093631,0x33662e766f6d090a,0x2c34326625092032,0x090a3b3631662520\n"
".quad 0x203233662e6c756d,0x25202c3532662509,0x326625202c343266,0x662e7473090a3b32\n"
".quad 0x3172255b09203233,0x6625202c5d342b30,0x6f6c2e090a3b3532,0x3132310936310963\n"
".quad 0x2e766f6d090a3009,0x3266250920323366,0x3b31326625202c36,0x33662e6c756d090a\n"
".quad 0x2c37326625092032,0x25202c3632662520,0x7473090a3b323266,0x255b09203233662e\n"
".quad 0x202c5d382b303172,0x2e090a3b37326625,0x3109363109636f6c,0x756d090a30093232\n"
".quad 0x2509203233662e6c,0x326625202c383266,0x3b34326625202c34,0x3233662e7473090a\n"
".quad 0x2b303172255b0920,0x326625202c5d3231,0x636f6c2e090a3b38,0x0933323109363109\n"
".quad 0x662e6c756d090a30,0x3932662509203233,0x202c36326625202c,0x73090a3b34326625\n"
".quad 0x5b09203233662e74,0x5d36312b30317225,0x0a3b39326625202c,0x363109636f6c2e09\n"
".quad 0x090a300934323109,0x203233662e6c756d,0x25202c3033662509,0x326625202c363266\n"
".quad 0x662e7473090a3b36,0x3172255b09203233,0x25202c5d30322b30,0x744c240a3b303366\n"
".quad 0x3a323639385f315f,0x732e61747663090a,0x33752e6465726168,0x202c377225092032\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f31363537335f,0x6f635f6e6f6e5f35\n"
".quad 0x61766f635f74736e,0x5f5f65636e616972,0x636f6c2e090a3b30,0x0936323109363109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x3233732e766f6d09,0x202c313172250920\n"
".quad 0x315f744c240a3b38,0x200a3a363839395f,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x73656e202c363231,0x70656420676e6974,0x65202c31203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f,0x6573090a6e776f6e\n"
".quad 0x33732e74672e7074,0x202c327025092032,0x7225202c31317225,0x70252140090a3b33\n"
".quad 0x2409206172622032,0x3230315f315f744c,0x3c2f2f200a3b3234,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36323120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3839395f315f744c,0x09636f6c2e090a36,0x3009303331093631\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x202c337225202c38,0x2e6c756d090a3b36\n"
".quad 0x09203233752e6f6c,0x387225202c397225,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x397225202c303172,0x090a3b377225202c,0x09203233662e646c,0x255b202c31336625\n"
".quad 0x0a3b5d302b303172,0x3233732e64646109,0x202c323172250920,0x7225202c31317225\n"
".quad 0x2e6c756d090a3b33,0x09203233732e6f6c,0x7225202c33317225,0x090a3b36202c3231\n"
".quad 0x752e6f6c2e6c756d,0x3431722509203233,0x202c33317225202c,0x2e646461090a3b34\n"
".quad 0x3172250920323375,0x202c377225202c35,0x6c090a3b34317225,0x2509203233662e64\n"
".quad 0x72255b202c323366,0x090a3b5d302b3531,0x203233662e646461,0x25202c3333662509\n"
".quad 0x336625202c313366,0x662e7473090a3b32,0x3172255b09203233,0x6625202c5d302b30\n"
".quad 0x5f744c240a3b3333,0x3a32343230315f31,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3632312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x090a363839395f31,0x636e79732e726162,0x2140090a3b300920\n"
".quad 0x2061726220327025,0x315f315f744c2409,0x2f200a3b34353730,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3632\n"
".quad 0x64656c6562616c20,0x395f315f744c2420,0x6f6c2e090a363839,0x3133310936310963\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x337225202c387225,0x756d090a3b36202c\n"
".quad 0x3233752e6f6c2e6c,0x25202c3972250920,0x090a3b34202c3872,0x203233752e646461\n"
".quad 0x25202c3031722509,0x3b377225202c3972,0x3233662e646c090a,0x202c343366250920\n"
".quad 0x5d342b303172255b,0x732e646461090a3b,0x3631722509203233,0x202c31317225202c\n"
".quad 0x756d090a3b337225,0x3233732e6f6c2e6c,0x202c373172250920,0x3b36202c36317225\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x37317225202c3831,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x377225202c393172,0x0a3b38317225202c,0x203233662e646c09\n"
".quad 0x5b202c3533662509,0x3b5d342b39317225,0x33662e646461090a,0x2c36336625092032\n"
".quad 0x25202c3433662520,0x7473090a3b353366,0x255b09203233662e,0x202c5d342b303172\n"
".quad 0x4c240a3b36336625,0x353730315f315f74,0x6c3c2f2f200a3a34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363839395f315f74,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x7262203270252140,0x315f744c24092061,0x0a3b36363231315f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x2e090a363839395f,0x3109363109636f6c\n"
".quad 0x756d090a30093233,0x3233732e6f6c2e6c,0x25202c3872250920,0x090a3b36202c3372\n"
".quad 0x752e6f6c2e6c756d,0x2c39722509203233,0x3b34202c38722520,0x33752e646461090a\n"
".quad 0x2c30317225092032,0x7225202c39722520,0x662e646c090a3b37,0x3733662509203233\n"
".quad 0x2b303172255b202c,0x646461090a3b5d38,0x722509203233732e,0x31317225202c3032\n"
".quad 0x090a3b337225202c,0x732e6f6c2e6c756d,0x3132722509203233,0x202c30327225202c\n"
".quad 0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c32327225,0x090a3b34202c3132\n"
".quad 0x203233752e646461,0x25202c3332722509,0x32327225202c3772,0x33662e646c090a3b\n"
".quad 0x2c38336625092032,0x382b333272255b20,0x2e646461090a3b5d,0x3366250920323366\n"
".quad 0x2c37336625202c39,0x090a3b3833662520,0x09203233662e7473,0x5d382b303172255b\n"
".quad 0x0a3b39336625202c,0x31315f315f744c24,0x2f2f200a3a363632,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x39395f315f744c24,0x2e726162090a3638,0x3b300920636e7973\n"
".quad 0x203270252140090a,0x744c240920617262,0x38373731315f315f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a363839395f315f,0x363109636f6c2e09\n"
".quad 0x090a300933333109,0x732e6f6c2e6c756d,0x2c38722509203233,0x3b36202c33722520\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x202c387225202c39,0x2e646461090a3b34\n"
".quad 0x3172250920323375,0x202c397225202c30,0x646c090a3b377225,0x662509203233662e\n"
".quad 0x3172255b202c3034,0x090a3b5d32312b30,0x203233732e646461,0x25202c3432722509\n"
".quad 0x337225202c313172,0x6c2e6c756d090a3b,0x2509203233732e6f,0x327225202c353272\n"
".quad 0x6d090a3b36202c34,0x33752e6f6c2e6c75,0x2c36327225092032,0x34202c3532722520\n"
".quad 0x752e646461090a3b,0x3732722509203233,0x25202c377225202c,0x646c090a3b363272\n"
".quad 0x662509203233662e,0x3272255b202c3134,0x090a3b5d32312b37,0x203233662e646461\n"
".quad 0x25202c3234662509,0x346625202c303466,0x662e7473090a3b31,0x3172255b09203233\n"
".quad 0x25202c5d32312b30,0x744c240a3b323466,0x38373731315f315f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a363839395f315f,0x6e79732e72616209\n"
".quad 0x40090a3b30092063,0x6172622032702521,0x5f315f744c240920,0x200a3b3039323231\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363231,0x656c6562616c2064,0x5f315f744c242064,0x6c2e090a36383939\n"
".quad 0x333109363109636f,0x6c756d090a300934,0x203233732e6f6c2e,0x7225202c38722509\n"
".quad 0x6d090a3b36202c33,0x33752e6f6c2e6c75,0x202c397225092032,0x0a3b34202c387225\n"
".quad 0x3233752e64646109,0x202c303172250920,0x377225202c397225,0x33662e646c090a3b\n"
".quad 0x2c33346625092032,0x312b303172255b20,0x646461090a3b5d36,0x722509203233732e\n"
".quad 0x31317225202c3832,0x090a3b337225202c,0x732e6f6c2e6c756d,0x3932722509203233\n"
".quad 0x202c38327225202c,0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c30337225\n"
".quad 0x090a3b34202c3932,0x203233752e646461,0x25202c3133722509,0x30337225202c3772\n"
".quad 0x33662e646c090a3b,0x2c34346625092032,0x312b313372255b20,0x646461090a3b5d36\n"
".quad 0x662509203233662e,0x33346625202c3534,0x0a3b34346625202c,0x203233662e747309\n"
".quad 0x312b303172255b09,0x35346625202c5d36,0x5f315f744c240a3b,0x200a3a3039323231\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363231,0x656c6562616c2064,0x5f315f744c242064,0x6162090a36383939\n"
".quad 0x0920636e79732e72,0x70252140090a3b30,0x2409206172622032,0x3832315f315f744c\n"
".quad 0x3c2f2f200a3b3230,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3839395f315f744c\n"
".quad 0x09636f6c2e090a36,0x3009353331093631,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x202c337225202c38,0x2e6c756d090a3b36,0x09203233752e6f6c,0x387225202c397225\n"
".quad 0x6461090a3b34202c,0x2509203233752e64,0x397225202c303172,0x090a3b377225202c\n"
".quad 0x09203233662e646c,0x255b202c36346625,0x3b5d30322b303172,0x33732e646461090a\n"
".quad 0x2c32337225092032,0x25202c3131722520,0x6c756d090a3b3372,0x203233732e6f6c2e\n"
".quad 0x25202c3333722509,0x0a3b36202c323372,0x2e6f6c2e6c756d09,0x3372250920323375\n"
".quad 0x2c33337225202c34,0x646461090a3b3420,0x722509203233752e,0x2c377225202c3533\n"
".quad 0x090a3b3433722520,0x09203233662e646c,0x255b202c37346625,0x3b5d30322b353372\n"
".quad 0x33662e646461090a,0x2c38346625092032,0x25202c3634662520,0x7473090a3b373466\n"
".quad 0x255b09203233662e,0x2c5d30322b303172,0x240a3b3834662520,0x3832315f315f744c\n"
".quad 0x3c2f2f200a3a3230,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3839395f315f744c\n"
".quad 0x732e726162090a36,0x0a3b300920636e79,0x363109636f6c2e09,0x090a300938323109\n"
".quad 0x203233732e726873,0x25202c3131722509,0x0a3b31202c313172,0x3233752e766f6d09\n"
".quad 0x202c363372250920,0x70746573090a3b30,0x203233732e74672e,0x7225202c33702509\n"
".quad 0x36337225202c3131,0x2033702540090a3b,0x744c240920617262,0x3b363839395f315f\n"
".quad 0x6168732e646c090a,0x662e34762e646572,0x3466257b09203233,0x252c303566252c39\n"
".quad 0x202c7d5f2c313566,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f31363537335f72\n"
".quad 0x635f6e6f6e5f3533,0x766f635f74736e6f,0x5f65636e61697261,0x090a3b5d302b305f\n"
".quad 0x09363109636f6c2e,0x646c090a30093435,0x2e6465726168732e,0x3566250920323366\n"
".quad 0x75635f5f5b202c32,0x6c61636f6c5f6164,0x3537335f7261765f,0x6f6e5f35335f3136\n"
".quad 0x5f74736e6f635f6e,0x6e61697261766f63,0x32312b305f5f6563,0x2e766f6d090a3b5d\n"
".quad 0x3566250920323366,0x3866336630202c33,0x20203b3030303030,0x0a31202f2f092020\n"
".quad 0x2e6e722e616d6609,0x3566250920323366,0x2c33356625202c34,0x25202c3035662520\n"
".quad 0x646c090a3b323566,0x2e6465726168732e,0x09203233662e3276,0x66252c353566257b\n"
".quad 0x5f5f5b202c7d3635,0x636f6c5f61647563,0x335f7261765f6c61,0x5f35335f31363537\n"
".quad 0x736e6f635f6e6f6e,0x697261766f635f74,0x2b305f5f65636e61,0x6f6d090a3b5d3631\n"
".quad 0x2509203233662e76,0x336630202c373566,0x3b30303030303866,0x202f2f0920202020\n"
".quad 0x722e616d66090a31,0x2509203233662e6e,0x356625202c383566,0x2c31356625202c37\n"
".quad 0x090a3b3535662520,0x203233662e766f6d,0x30202c3935662509,0x3030303038663366\n"
".quad 0x2f09202020203b30,0x616d66090a31202f,0x203233662e6e722e,0x25202c3036662509\n"
".quad 0x356625202c393466,0x3b30356625202c39,0x33662e766f6d090a,0x2c31366625092032\n"
".quad 0x3030386633663020,0x202020203b303030,0x66090a31202f2f09,0x33662e6e722e616d\n"
".quad 0x2c32366625092032,0x25202c3136662520,0x356625202c353566,0x2e766f6d090a3b34\n"
".quad 0x3666250920323366,0x3866336630202c33,0x20203b3030303030,0x0a31202f2f092020\n"
".quad 0x2e6e722e616d6609,0x3666250920323366,0x2c33366625202c34,0x25202c3635662520\n"
".quad 0x6f6d090a3b383566,0x2509203233662e76,0x336630202c353666,0x3b30303030303866\n"
".quad 0x202f2f0920202020,0x722e616d66090a31,0x2509203233662e6e,0x356625202c363666\n"
".quad 0x2c35366625202c31,0x090a3b3036662520,0x203233662e78616d,0x25202c3736662509\n"
".quad 0x366625202c323666,0x2e78616d090a3b36,0x3666250920323366,0x2c34366625202c38\n"
".quad 0x090a3b3736662520,0x662e6e722e706372,0x3936662509203233,0x0a3b38366625202c\n"
".quad 0x3233662e6c756d09,0x202c303766250920,0x6625202c32366625,0x6c756d090a3b3936\n"
".quad 0x662509203233662e,0x36366625202c3137,0x0a3b39366625202c,0x3233662e6c756d09\n"
".quad 0x202c323766250920,0x6625202c34366625,0x6c756d090a3b3936,0x662509203233662e\n"
".quad 0x30376625202c3337,0x0a3b35356625202c,0x3233662e6c756d09,0x202c343766250920\n"
".quad 0x6625202c30376625,0x6c756d090a3b3035,0x662509203233662e,0x30376625202c3537\n"
".quad 0x0a3b32356625202c,0x2e6e722e616d6609,0x3766250920323366,0x2c31376625202c36\n"
".quad 0x25202c3135662520,0x6d66090a3b333766,0x3233662e6e722e61,0x202c373766250920\n"
".quad 0x6625202c39346625,0x34376625202c3137,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x376625202c383766,0x2c30356625202c31,0x090a3b3537662520,0x662e6e722e616d66\n"
".quad 0x3937662509203233,0x202c32376625202c,0x6625202c36356625,0x616d66090a3b3637\n"
".quad 0x203233662e6e722e,0x25202c3038662509,0x376625202c313566,0x3b37376625202c32\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x32376625202c3138,0x202c35356625202c\n"
".quad 0x6d090a3b38376625,0x09203233662e7861,0x6625202c32386625,0x31386625202c3038\n"
".quad 0x662e78616d090a3b,0x3338662509203233,0x202c39376625202c,0x72090a3b32386625\n"
".quad 0x33662e6e722e7063,0x2c34386625092032,0x090a3b3338662520,0x09363109636f6c2e\n"
".quad 0x756d090a30093035,0x2509203233662e6c,0x376625202c353866,0x3b34386625202c39\n"
".quad 0x33662e6c756d090a,0x2c36386625092032,0x25202c3038662520,0x756d090a3b343866\n"
".quad 0x2509203233662e6c,0x386625202c373866,0x3b34386625202c31,0x33662e6c756d090a\n"
".quad 0x2c38386625092032,0x25202c3738662520,0x6d66090a3b303566,0x3233662e6e722e61\n"
".quad 0x202c393866250920,0x6625202c39346625,0x38386625202c3638,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x356625202c303966,0x2c35386625202c31,0x090a3b3938662520\n"
".quad 0x09363109636f6c2e,0x756d090a30093135,0x2509203233662e6c,0x386625202c313966\n"
".quad 0x3b32356625202c37,0x6e722e616d66090a,0x662509203233662e,0x36386625202c3239\n"
".quad 0x202c30356625202c,0x66090a3b31396625,0x33662e6e722e616d,0x2c33396625092032\n"
".quad 0x25202c3538662520,0x396625202c353566,0x636f6c2e090a3b32,0x3009323509363109\n"
".quad 0x33662e6c756d090a,0x2c34396625092032,0x25202c3738662520,0x6d66090a3b353566\n"
".quad 0x3233662e6e722e61,0x202c353966250920,0x6625202c36386625,0x34396625202c3135\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x386625202c363966,0x2c36356625202c35\n"
".quad 0x090a3b3539662520,0x09363109636f6c2e,0x616d090a30093835,0x2509203233662e78\n"
".quad 0x396625202c373966,0x3b33396625202c30,0x33662e78616d090a,0x2c38396625092032\n"
".quad 0x25202c3739662520,0x6372090a3b363966,0x3233662e6e722e70,0x202c393966250920\n"
".quad 0x6d090a3b38396625,0x09203233662e6c75,0x25202c3030316625,0x396625202c393966\n"
".quad 0x2e6c756d090a3b30,0x3166250920323366,0x39396625202c3130,0x0a3b33396625202c\n"
".quad 0x3233662e6c756d09,0x2c32303166250920,0x25202c3939662520,0x6c2e090a3b363966\n"
".quad 0x303509363109636f,0x2e6c756d090a3009,0x3166250920323366,0x30316625202c3330\n"
".quad 0x3b30356625202c31,0x6e722e616d66090a,0x662509203233662e,0x346625202c343031\n"
".quad 0x3030316625202c39,0x3b3330316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x356625202c353031,0x3230316625202c31,0x3b3430316625202c,0x3109636f6c2e090a\n"
".quad 0x090a300938350936,0x203233662e6c756d,0x202c363031662509,0x25202c3130316625\n"
".quad 0x756d090a3b323566,0x2509203233662e6c,0x6625202c37303166,0x356625202c313031\n"
".quad 0x2e616d66090a3b35,0x09203233662e6e72,0x25202c3830316625,0x6625202c30303166\n"
".quad 0x30316625202c3035,0x2e616d66090a3b36,0x09203233662e6e72,0x25202c3930316625\n"
".quad 0x6625202c30303166,0x30316625202c3135,0x2e616d66090a3b37,0x09203233662e6e72\n"
".quad 0x25202c3031316625,0x6625202c32303166,0x30316625202c3535,0x2e616d66090a3b38\n"
".quad 0x09203233662e6e72,0x25202c3131316625,0x6625202c32303166,0x30316625202c3635\n"
".quad 0x2e78616d090a3b39,0x3166250920323366,0x31316625202c3231,0x3530316625202c30\n"
".quad 0x662e78616d090a3b,0x3131662509203233,0x3131316625202c33,0x3b3231316625202c\n"
".quad 0x6e722e706372090a,0x662509203233662e,0x316625202c343131,0x6c756d090a3b3331\n"
".quad 0x662509203233662e,0x316625202c353131,0x31316625202c3031,0x2e6c756d090a3b34\n"
".quad 0x3166250920323366,0x31316625202c3631,0x3431316625202c31,0x662e6c756d090a3b\n"
".quad 0x3131662509203233,0x3431316625202c37,0x3b3530316625202c,0x3109636f6c2e090a\n"
".quad 0x090a300932350936,0x203233662e6c756d,0x202c383131662509,0x25202c3531316625\n"
".quad 0x6d66090a3b353566,0x3233662e6e722e61,0x2c39313166250920,0x202c373131662520\n"
".quad 0x6625202c31356625,0x6d66090a3b383131,0x3233662e6e722e61,0x2c30323166250920\n"
".quad 0x202c363131662520,0x6625202c36356625,0x6c2e090a3b393131,0x343509363109636f\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x31316625202c3132,0x3b30356625202c35\n"
".quad 0x33662e6c756d090a,0x3232316625092032,0x2c3531316625202c,0x090a3b3235662520\n"
".quad 0x662e6e722e616d66,0x3231662509203233,0x2c39346625202c33,0x202c373131662520\n"
".quad 0x090a3b3132316625,0x662e6e722e616d66,0x3231662509203233,0x3731316625202c34\n"
".quad 0x202c30356625202c,0x090a3b3232316625,0x662e6e722e616d66,0x3231662509203233\n"
".quad 0x2c31356625202c35,0x202c363131662520,0x090a3b3332316625,0x662e6e722e616d66\n"
".quad 0x3231662509203233,0x3631316625202c36,0x202c35356625202c,0x090a3b3432316625\n"
".quad 0x203233662e78616d,0x202c373231662509,0x25202c3532316625,0x6d090a3b36323166\n"
".quad 0x09203233662e7861,0x25202c3832316625,0x6625202c37323166,0x6372090a3b303231\n"
".quad 0x3233662e6e722e70,0x2c39323166250920,0x0a3b383231662520,0x363109636f6c2e09\n"
".quad 0x6d090a3009383509,0x09203233662e6c75,0x25202c3033316625,0x6625202c35323166\n"
".quad 0x756d090a3b393231,0x2509203233662e6c,0x6625202c31333166,0x316625202c363231\n"
".quad 0x6f6c2e090a3b3932,0x0930350936310963,0x662e6c756d090a30,0x3331662509203233\n"
".quad 0x3932316625202c32,0x3b3032316625202c,0x33662e6c756d090a,0x3333316625092032\n"
".quad 0x2c3133316625202c,0x090a3b3035662520,0x662e6e722e616d66,0x3331662509203233\n"
".quad 0x2c39346625202c34,0x202c303331662520,0x090a3b3333316625,0x662e6e722e616d66\n"
".quad 0x3331662509203233,0x2c31356625202c35,0x202c323331662520,0x090a3b3433316625\n"
".quad 0x09363109636f6c2e,0x756d090a30093135,0x2509203233662e6c,0x6625202c36333166\n"
".quad 0x356625202c313331,0x2e616d66090a3b32,0x09203233662e6e72,0x25202c3733316625\n"
".quad 0x6625202c30333166,0x33316625202c3035,0x2e616d66090a3b36,0x09203233662e6e72\n"
".quad 0x25202c3833316625,0x6625202c32333166,0x33316625202c3535,0x636f6c2e090a3b37\n"
".quad 0x3009323509363109,0x33662e6c756d090a,0x3933316625092032,0x2c3133316625202c\n"
".quad 0x090a3b3535662520,0x662e6e722e616d66,0x3431662509203233,0x3033316625202c30\n"
".quad 0x202c31356625202c,0x090a3b3933316625,0x662e6e722e616d66,0x3431662509203233\n"
".quad 0x3233316625202c31,0x202c36356625202c,0x090a3b3034316625,0x09363109636f6c2e\n"
".quad 0x616d090a30093835,0x2509203233662e78,0x6625202c32343166,0x316625202c353331\n"
".quad 0x78616d090a3b3833,0x662509203233662e,0x316625202c333431,0x34316625202c3234\n"
".quad 0x2e706372090a3b31,0x09203233662e6e72,0x25202c3434316625,0x6d090a3b33343166\n"
".quad 0x09203233662e6c75,0x25202c3534316625,0x6625202c34343166,0x756d090a3b353331\n"
".quad 0x2509203233662e6c,0x6625202c36343166,0x316625202c343431,0x6c756d090a3b3833\n"
".quad 0x662509203233662e,0x316625202c373431,0x34316625202c3434,0x636f6c2e090a3b31\n"
".quad 0x3009303509363109,0x33662e6c756d090a,0x3834316625092032,0x2c3634316625202c\n"
".quad 0x090a3b3035662520,0x662e6e722e616d66,0x3431662509203233,0x2c39346625202c39\n"
".quad 0x202c353431662520,0x090a3b3834316625,0x662e6e722e616d66,0x3531662509203233\n"
".quad 0x2c31356625202c30,0x202c373431662520,0x090a3b3934316625,0x09363109636f6c2e\n"
".quad 0x756d090a30093835,0x2509203233662e6c,0x6625202c31353166,0x356625202c363431\n"
".quad 0x2e6c756d090a3b32,0x3166250920323366,0x34316625202c3235,0x3b35356625202c36\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c333531,0x30356625202c3534\n"
".quad 0x3b3135316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c343531\n"
".quad 0x31356625202c3534,0x3b3235316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c353531,0x35356625202c3734,0x3b3335316625202c,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x316625202c363531,0x36356625202c3734,0x3b3435316625202c\n"
".quad 0x33662e78616d090a,0x3735316625092032,0x2c3535316625202c,0x0a3b303531662520\n"
".quad 0x3233662e78616d09,0x2c38353166250920,0x202c363531662520,0x090a3b3735316625\n"
".quad 0x662e6e722e706372,0x3531662509203233,0x3835316625202c39,0x662e6c756d090a3b\n"
".quad 0x3631662509203233,0x3535316625202c30,0x3b3935316625202c,0x33662e6c756d090a\n"
".quad 0x3136316625092032,0x2c3635316625202c,0x0a3b393531662520,0x3233662e6c756d09\n"
".quad 0x2c32363166250920,0x202c393531662520,0x090a3b3035316625,0x09363109636f6c2e\n"
".quad 0x756d090a30093235,0x2509203233662e6c,0x6625202c33363166,0x356625202c303631\n"
".quad 0x2e616d66090a3b35,0x09203233662e6e72,0x25202c3436316625,0x6625202c32363166\n"
".quad 0x36316625202c3135,0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3536316625\n"
".quad 0x6625202c31363166,0x36316625202c3635,0x636f6c2e090a3b34,0x3009343509363109\n"
".quad 0x33662e6c756d090a,0x3636316625092032,0x2c3036316625202c,0x090a3b3035662520\n"
".quad 0x203233662e6c756d,0x202c373631662509,0x25202c3036316625,0x6d66090a3b323566\n"
".quad 0x3233662e6e722e61,0x2c38363166250920,0x25202c3934662520,0x6625202c32363166\n"
".quad 0x6d66090a3b363631,0x3233662e6e722e61,0x2c39363166250920,0x202c323631662520\n"
".quad 0x6625202c30356625,0x6d66090a3b373631,0x3233662e6e722e61,0x2c30373166250920\n"
".quad 0x25202c3135662520,0x6625202c31363166,0x6d66090a3b383631,0x3233662e6e722e61\n"
".quad 0x2c31373166250920,0x202c313631662520,0x6625202c35356625,0x616d090a3b393631\n"
".quad 0x2509203233662e78,0x6625202c32373166,0x316625202c303731,0x78616d090a3b3137\n"
".quad 0x662509203233662e,0x316625202c333731,0x36316625202c3237,0x2e706372090a3b35\n"
".quad 0x09203233662e6e72,0x25202c3437316625,0x2e090a3b33373166,0x3509363109636f6c\n"
".quad 0x6c756d090a300938,0x662509203233662e,0x316625202c353731,0x37316625202c3037\n"
".quad 0x2e6c756d090a3b34,0x3166250920323366,0x37316625202c3637,0x3437316625202c31\n"
".quad 0x09636f6c2e090a3b,0x3009313431093631,0x33662e766f6d090a,0x3737316625092032\n"
".quad 0x3b3537316625202c,0x7261702e7473090a,0x09203233662e6d61,0x72616475635f5f5b\n"
".quad 0x31315a5f5f667465,0x4c74694674736562,0x6c66364b50656e69,0x302b5f533374616f\n"
".quad 0x3737316625202c5d,0x662e766f6d090a3b,0x3731662509203233,0x3637316625202c38\n"
".quad 0x61702e7473090a3b,0x203233662e6d6172,0x616475635f5f5b09,0x315a5f5f66746572\n"
".quad 0x7469467473656231,0x66364b50656e694c,0x2b5f533374616f6c,0x37316625202c5d34\n"
".quad 0x2e6c756d090a3b38,0x3166250920323366,0x37316625202c3937,0x3536316625202c34\n"
".quad 0x61702e7473090a3b,0x203233662e6d6172,0x616475635f5f5b09,0x315a5f5f66746572\n"
".quad 0x7469467473656231,0x66364b50656e694c,0x2b5f533374616f6c,0x37316625202c5d38\n"
".quad 0x3b746572090a3b39,0x646e6557444c240a,0x73656231315a5f5f,0x656e694c74694674\n"
".quad 0x74616f6c66364b50,0x207d090a3a5f5333,0x6231315a5f202f2f,0x694c746946747365\n"
".quad 0x6f6c66364b50656e,0x090a0a5f53337461,0x656c62697369762e,0x5f20636e75662e20\n"
".quad 0x4374726f7330315a,0x664b5073726f6c6f,0x7261702e28206950,0x203233752e206d61\n"
".quad 0x6170616475635f5f,0x315a5f5f31666d72,0x6c6f4374726f7330,0x6950664b5073726f\n"
".quad 0x6d617261702e202c,0x5f5f203233752e20,0x6d72617061647563,0x7330315a5f5f3266\n"
".quad 0x726f6c6f4374726f,0x0a296950664b5073,0x6765722e090a7b09,0x7225203233752e20\n"
".quad 0x2e090a3b3e39363c,0x3233662e20676572,0x3b3e39313c662520,0x2e206765722e090a\n"
".quad 0x3c70252064657270,0x6f6c2e090a3b3e38,0x0936380937310963,0x656257444c240a30\n"
".quad 0x30315a5f5f6e6967,0x6f6c6f4374726f73,0x3a6950664b507372,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563,0x7330315a5f5f3166\n"
".quad 0x726f6c6f4374726f,0x3b5d6950664b5073,0x33732e766f6d090a,0x202c327225092032\n"
".quad 0x646c090a3b317225,0x752e6d617261702e,0x2c33722509203233,0x616475635f5f5b20\n"
".quad 0x5f5f32666d726170,0x4374726f7330315a,0x664b5073726f6c6f,0x6f6d090a3b5d6950\n"
".quad 0x2509203233732e76,0x3b337225202c3472,0x33752e766f6d090a,0x202c357225092032\n"
".quad 0x0a3b782e64697425,0x3233752e766f6d09,0x30202c3672250920,0x2e70746573090a3b\n"
".quad 0x09203233752e656e,0x357225202c317025,0x090a3b367225202c,0x6172622031702540\n"
".quad 0x5f325f744c240920,0x6d090a3b30373137,0x09203233732e766f,0x327225202c377225\n"
".quad 0x752e646461090a3b,0x2c38722509203233,0x3436202c32722520,0x732e766f6d090a3b\n"
".quad 0x2c39722509203233,0x4c240a3b34722520,0x343931385f325f74,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x6e202c363820656e,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x6974617265746920,0x0a3631203a736e6f,0x373109636f6c2e09\n"
".quad 0x6c090a3009383909,0x2509203233662e64,0x3772255b202c3166,0x646c090a3b5d302b\n"
".quad 0x662509203233662e,0x2b3272255b202c32,0x6573090a3b5d3635,0x3233752e746c2e74\n"
".quad 0x722509203233662e,0x2c326625202c3031,0x6e090a3b31662520,0x09203233732e6765\n"
".quad 0x7225202c31317225,0x2e646c090a3b3031,0x3366250920323366,0x362b3272255b202c\n"
".quad 0x746573090a3b5d30,0x2e3233752e746c2e,0x3172250920323366,0x202c336625202c32\n"
".quad 0x656e090a3b316625,0x2509203233732e67,0x317225202c333172,0x2e646461090a3b32\n"
".quad 0x3172250920323373,0x2c31317225202c34,0x090a3b3331722520,0x09203233662e646c\n"
".quad 0x72255b202c346625,0x090a3b5d38342b32,0x752e746c2e746573,0x09203233662e3233\n"
".quad 0x6625202c35317225,0x0a3b316625202c34,0x3233732e67656e09,0x202c363172250920\n"
".quad 0x6c090a3b35317225,0x2509203233662e64,0x3272255b202c3566,0x73090a3b5d32352b\n"
".quad 0x33752e746c2e7465,0x2509203233662e32,0x356625202c373172,0x090a3b316625202c\n"
".quad 0x203233732e67656e,0x25202c3831722509,0x6461090a3b373172,0x2509203233732e64\n"
".quad 0x317225202c393172,0x3b38317225202c36,0x3233662e646c090a,0x5b202c3666250920\n"
".quad 0x0a3b5d302b327225,0x2e746c2e74657309,0x203233662e323375,0x25202c3032722509\n"
".quad 0x3b316625202c3666,0x33732e67656e090a,0x2c31327225092032,0x090a3b3032722520\n"
".quad 0x09203233662e646c,0x72255b202c376625,0x090a3b5d34342b32,0x752e746c2e746573\n"
".quad 0x09203233662e3233,0x6625202c32327225,0x0a3b316625202c37,0x3233732e67656e09\n"
".quad 0x202c333272250920,0x61090a3b32327225,0x09203233732e6464,0x7225202c34327225\n"
".quad 0x33327225202c3132,0x33662e646c090a3b,0x202c386625092032,0x3b5d342b3272255b\n"
".quad 0x746c2e746573090a,0x3233662e3233752e,0x202c353272250920,0x316625202c386625\n"
".quad 0x732e67656e090a3b,0x3632722509203233,0x0a3b35327225202c,0x203233662e646c09\n"
".quad 0x255b202c39662509,0x090a3b5d382b3272,0x752e746c2e746573,0x09203233662e3233\n"
".quad 0x6625202c37327225,0x0a3b316625202c39,0x3233732e67656e09,0x202c383272250920\n"
".quad 0x61090a3b37327225,0x09203233732e6464,0x7225202c39327225,0x38327225202c3632\n"
".quad 0x33662e646c090a3b,0x2c30316625092032,0x32312b3272255b20,0x2e746573090a3b5d\n"
".quad 0x662e3233752e746c,0x3033722509203233,0x202c30316625202c,0x656e090a3b316625\n"
".quad 0x2509203233732e67,0x337225202c313372,0x662e646c090a3b30,0x3131662509203233\n"
".quad 0x312b3272255b202c,0x746573090a3b5d36,0x2e3233752e746c2e,0x3372250920323366\n"
".quad 0x2c31316625202c32,0x6e090a3b31662520,0x09203233732e6765,0x7225202c33337225\n"
".quad 0x646461090a3b3233,0x722509203233732e,0x31337225202c3433,0x0a3b33337225202c\n"
".quad 0x203233662e646c09,0x5b202c3231662509,0x3b5d30322b327225,0x746c2e746573090a\n"
".quad 0x3233662e3233752e,0x202c353372250920,0x6625202c32316625,0x2e67656e090a3b31\n"
".quad 0x3372250920323373,0x3b35337225202c36,0x3233662e646c090a,0x202c333166250920\n"
".quad 0x5d34322b3272255b,0x6c2e746573090a3b,0x33662e3233752e74,0x2c37337225092032\n"
".quad 0x25202c3331662520,0x67656e090a3b3166,0x722509203233732e,0x37337225202c3833\n"
".quad 0x732e646461090a3b,0x3933722509203233,0x202c36337225202c,0x6c090a3b38337225\n"
".quad 0x2509203233662e64,0x72255b202c343166,0x090a3b5d38322b32,0x752e746c2e746573\n"
".quad 0x09203233662e3233,0x6625202c30347225,0x3b316625202c3431,0x33732e67656e090a\n"
".quad 0x2c31347225092032,0x090a3b3034722520,0x09203233662e646c,0x255b202c35316625\n"
".quad 0x0a3b5d32332b3272,0x2e746c2e74657309,0x203233662e323375,0x25202c3234722509\n"
".quad 0x316625202c353166,0x732e67656e090a3b,0x3334722509203233,0x0a3b32347225202c\n"
".quad 0x3233732e64646109,0x202c343472250920,0x7225202c31347225,0x2e646c090a3b3334\n"
".quad 0x3166250920323366,0x2b3272255b202c36,0x6573090a3b5d3633,0x3233752e746c2e74\n"
".quad 0x722509203233662e,0x36316625202c3534,0x090a3b316625202c,0x203233732e67656e\n"
".quad 0x25202c3634722509,0x646c090a3b353472,0x662509203233662e,0x3272255b202c3731\n"
".quad 0x73090a3b5d30342b,0x33752e746c2e7465,0x2509203233662e32,0x316625202c373472\n"
".quad 0x0a3b316625202c37,0x3233732e67656e09,0x202c383472250920,0x61090a3b37347225\n"
".quad 0x09203233732e6464,0x7225202c39347225,0x38347225202c3634,0x732e646461090a3b\n"
".quad 0x3035722509203233,0x202c34347225202c,0x61090a3b39347225,0x09203233732e6464\n"
".quad 0x7225202c31357225,0x30357225202c3933,0x732e646461090a3b,0x3235722509203233\n"
".quad 0x202c34337225202c,0x61090a3b31357225,0x09203233732e6464,0x7225202c33357225\n"
".quad 0x32357225202c3932,0x732e646461090a3b,0x3435722509203233,0x202c34327225202c\n"
".quad 0x61090a3b33357225,0x09203233732e6464,0x7225202c35357225,0x34357225202c3931\n"
".quad 0x732e646461090a3b,0x3635722509203233,0x202c34317225202c,0x73090a3b35357225\n"
".quad 0x5b09203233732e74,0x202c5d302b397225,0x61090a3b36357225,0x09203233752e6464\n"
".quad 0x397225202c397225,0x6461090a3b34202c,0x2509203233752e64,0x2c377225202c3772\n"
".quad 0x746573090a3b3420,0x3233752e656e2e70,0x25202c3270250920,0x3b387225202c3772\n"
".quad 0x622032702540090a,0x5f744c2409206172,0x0a3b343931385f32,0x3233732e766f6d09\n"
".quad 0x202c373572250920,0x325f744c240a3b30,0x200a3a383132395f,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x7473656e202c3839,0x7470656420676e69\n"
".quad 0x7469202c31203a68,0x736e6f6974617265,0x6f6d090a3531203a,0x2509203233732e76\n"
".quad 0x0a3b30202c383572,0x39395f325f744c24,0x3c2f2f200a3a3638,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x2c383920656e696c,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6172657469202c32,0x31203a736e6f6974,0x09636f6c2e090a36,0x3009363031093731\n"
".quad 0x6c2e70746573090a,0x2509203233732e65,0x38357225202c3370,0x0a3b37357225202c\n"
".quad 0x7262203370254009,0x325f744c24092061,0x0a3b30313031315f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383920\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x756d090a36383939,0x3233752e6f6c2e6c\n"
".quad 0x202c393572250920,0x3b34202c38357225,0x33752e646461090a,0x2c30367225092032\n"
".quad 0x25202c3935722520,0x2e646c090a3b3472,0x3672250920323373,0x303672255b202c31\n"
".quad 0x756d090a3b5d302b,0x3233752e6f6c2e6c,0x202c323672250920,0x3b34202c37357225\n"
".quad 0x33752e646461090a,0x2c33367225092032,0x7225202c34722520,0x2e646c090a3b3236\n"
".quad 0x3672250920323373,0x333672255b202c34,0x6573090a3b5d302b,0x33732e656e2e7074\n"
".quad 0x202c347025092032,0x7225202c34367225,0x702540090a3b3136,0x2409206172622034\n"
".quad 0x3031315f325f744c,0x3c2f2f200a3b3031,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c383920656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363839395f325f74,0x33732e646461090a,0x2c35367225092032,0x31202c3136722520\n"
".quad 0x33732e7473090a3b,0x303672255b092032,0x367225202c5d302b,0x325f744c240a3b35\n"
".quad 0x0a3a30313031315f,0x3536365f325f4c24,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a363839395f325f,0x3233732e64646109,0x202c383572250920\n"
".quad 0x3b31202c38357225,0x33752e766f6d090a,0x2c36367225092032,0x6573090a3b363120\n"
".quad 0x33732e656e2e7074,0x202c357025092032,0x7225202c38357225,0x702540090a3b3636\n"
".quad 0x2409206172622035,0x3839395f325f744c,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383920656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a383132395f325f,0x3233732e64646109,0x202c373572250920\n"
".quad 0x3b31202c37357225,0x33752e766f6d090a,0x2c37367225092032,0x6573090a3b353120\n"
".quad 0x33732e656e2e7074,0x202c367025092032,0x7225202c37357225,0x702540090a3b3736\n"
".quad 0x2409206172622036,0x3132395f325f744c,0x325f744c240a3b38,0x090a3a303731375f\n"
".quad 0x09373109636f6c2e,0x72090a3009303331,0x57444c240a3b7465,0x30315a5f5f646e65\n"
".quad 0x6f6c6f4374726f73,0x3a6950664b507372,0x5f202f2f207d090a,0x4374726f7330315a\n"
".quad 0x664b5073726f6c6f,0x6168732e090a6950,0x696c612e20646572,0x622e203631206e67\n"
".quad 0x616475635f5f2038,0x765f6c61636f6c5f,0x34383837335f7261,0x5f6e6f6e5f35335f\n"
".quad 0x70645f74736e6f63,0x5d34365b335f5f73,0x7369762e090a0a3b,0x75662e20656c6269\n"
".quad 0x6c34315a5f20636e,0x726f6c6f4364616f,0x6a4b506b636f6c42,0x3374616f6c663650\n"
".quad 0x2e282069505f3253,0x752e206d61726170,0x6475635f5f203233,0x5f31666d72617061\n"
".quad 0x64616f6c34315a5f,0x6f6c42726f6c6f43,0x6636506a4b506b63,0x5f32533374616f6c\n"
".quad 0x7261702e202c6950,0x203233752e206d61,0x6170616475635f5f,0x315a5f5f32666d72\n"
".quad 0x6c6f4364616f6c34,0x506b636f6c42726f,0x616f6c6636506a4b,0x2c69505f32533374\n"
".quad 0x206d617261702e20,0x635f5f203233752e,0x666d726170616475,0x6f6c34315a5f5f33\n"
".quad 0x42726f6c6f436461,0x506a4b506b636f6c,0x533374616f6c6636,0x702e202c69505f32\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x5f5f34666d726170,0x4364616f6c34315a\n"
".quad 0x636f6c42726f6c6f,0x6c6636506a4b506b,0x505f32533374616f,0x2e090a7b090a2969\n"
".quad 0x3233752e20676572,0x3e3434313c722520,0x206765722e090a3b,0x3c6625203233662e\n"
".quad 0x2e090a3b3e363532,0x6572702e20676572,0x3e31313c70252064,0x5f5f202f2f090a3b\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f32315f36383837,0x736e6f635f6e6f6e\n"
".quad 0x203d20706d745f74,0x5f202f2f090a3231,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32315f3535353733,0x6e6f635f6e6f6e5f,0x20666669645f7473,0x6f6c2e090a30203d\n"
".quad 0x3733310937310963,0x6257444c240a3009,0x315a5f5f6e696765,0x6c6f4364616f6c34\n"
".quad 0x506b636f6c42726f,0x616f6c6636506a4b,0x3a69505f32533374,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563,0x6c34315a5f5f3166\n"
".quad 0x726f6c6f4364616f,0x6a4b506b636f6c42,0x3374616f6c663650,0x0a3b5d69505f3253\n"
".quad 0x3233732e766f6d09,0x25202c3272250920,0x2e646c090a3b3172,0x33752e6d61726170\n"
".quad 0x202c337225092032,0x70616475635f5f5b,0x5a5f5f32666d7261,0x6f4364616f6c3431\n"
".quad 0x6b636f6c42726f6c,0x6f6c6636506a4b50,0x69505f3253337461,0x2e766f6d090a3b5d\n"
".quad 0x3472250920323373,0x090a3b337225202c,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x75635f5f5b202c35,0x33666d7261706164,0x616f6c34315a5f5f,0x6c42726f6c6f4364\n"
".quad 0x36506a4b506b636f,0x32533374616f6c66,0x6d090a3b5d69505f,0x09203233732e766f\n"
".quad 0x357225202c367225,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c37722509\n"
".quad 0x726170616475635f,0x34315a5f5f34666d,0x6f6c6f4364616f6c,0x4b506b636f6c4272\n"
".quad 0x74616f6c6636506a,0x3b5d69505f325333,0x33732e766f6d090a,0x202c387225092032\n"
".quad 0x7663090a3b377225,0x33752e3233732e74,0x202c397225092032,0x0a3b782e64697425\n"
".quad 0x3233732e766f6d09,0x202c303172250920,0x746573090a3b3531,0x3233732e656c2e70\n"
".quad 0x25202c3170250920,0x30317225202c3972,0x3170252140090a3b,0x4c24092061726220\n"
".quad 0x373232325f335f74,0x636f6c2e090a3b34,0x0938343109373109,0x732e747663090a30\n"
".quad 0x09203233752e3233,0x6325202c31317225,0x0a3b782e64696174,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323373,0x2c31317225202c32,0x6461090a3b363120,0x2509203233732e64\n"
".quad 0x397225202c333172,0x0a3b32317225202c,0x2e6f6c2e6c756d09,0x3172250920323375\n"
".quad 0x2c33317225202c34,0x646461090a3b3420,0x722509203233752e,0x2c327225202c3531\n"
".quad 0x090a3b3431722520,0x09203233752e646c,0x255b202c36317225,0x0a3b5d302b353172\n"
".quad 0x373109636f6c2e09,0x090a300930353109,0x752e6f6c2e6c756d,0x3731722509203233\n"
".quad 0x31202c397225202c,0x2e646461090a3b32,0x3172250920323375,0x2c37317225202c38\n"
".quad 0x61090a3b34722520,0x09203233622e646e,0x7225202c39317225,0x3b353532202c3631\n"
".quad 0x6e722e747663090a,0x3233752e3233662e,0x25202c3166250920,0x6f6d090a3b393172\n"
".quad 0x2509203233662e76,0x62336630202c3266,0x203b313830383038,0x202f2f0920202020\n"
".quad 0x3132393330302e30,0x2e6c756d090a3735,0x3366250920323366,0x25202c316625202c\n"
".quad 0x2e7473090a3b3266,0x72255b0920323366,0x25202c5d302b3831,0x6f6c2e090a3b3366\n"
".quad 0x3135310937310963,0x2e6c6873090a3009,0x3272250920323362,0x2c36317225202c30\n"
".quad 0x6873090a3b363120,0x2509203233752e72,0x327225202c313272,0x090a3b3432202c30\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x327225202c346625,0x2e766f6d090a3b31\n"
".quad 0x3566250920323366,0x303862336630202c,0x2020203b31383038,0x2e30202f2f092020\n"
".quad 0x3735313239333030,0x33662e6c756d090a,0x202c366625092032,0x356625202c346625\n"
".quad 0x33662e7473090a3b,0x383172255b092032,0x366625202c5d342b,0x09636f6c2e090a3b\n"
".quad 0x3009323531093731,0x33622e6c6873090a,0x2c32327225092032,0x38202c3631722520\n"
".quad 0x752e726873090a3b,0x3332722509203233,0x202c32327225202c,0x747663090a3b3432\n"
".quad 0x2e3233662e6e722e,0x3766250920323375,0x0a3b33327225202c,0x3233662e766f6d09\n"
".quad 0x30202c3866250920,0x3830383038623366,0x0920202020203b31,0x3330302e30202f2f\n"
".quad 0x6d090a3735313239,0x09203233662e6c75,0x376625202c396625,0x090a3b386625202c\n"
".quad 0x09203233662e7473,0x5d382b383172255b,0x240a3b396625202c,0x3232325f335f744c\n"
".quad 0x6f6c2e090a3a3437,0x3635310937310963,0x2e726162090a3009,0x3b300920636e7973\n"
".quad 0x203170252140090a,0x744c240920617262,0x36383732325f335f,0x09636f6c2e090a3b\n"
".quad 0x3009303631093731,0x6f6c2e6c756d090a,0x722509203233752e,0x2c397225202c3731\n"
".quad 0x6461090a3b323120,0x2509203233752e64,0x317225202c383172,0x0a3b347225202c37\n"
".quad 0x3233752e64646109,0x202c343272250920,0x7225202c37317225,0x662e646c090a3b36\n"
".quad 0x3031662509203233,0x2b383172255b202c,0x2e7473090a3b5d30,0x72255b0920323366\n"
".quad 0x25202c5d302b3432,0x646c090a3b303166,0x662509203233662e,0x3172255b202c3131\n"
".quad 0x73090a3b5d342b38,0x5b09203233662e74,0x2c5d342b34327225,0x090a3b3131662520\n"
".quad 0x09203233662e646c,0x255b202c32316625,0x0a3b5d382b383172,0x203233662e747309\n"
".quad 0x382b343272255b09,0x3b32316625202c5d,0x325f335f744c240a,0x62090a3a36383732\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x33325f335f744c24\n"
".quad 0x6f78090a3b383932,0x2509203233622e72,0x397225202c353272,0x756d090a3b38202c\n"
".quad 0x3233752e6f6c2e6c,0x202c363272250920,0x3231202c35327225,0x752e646461090a3b\n"
".quad 0x3732722509203233,0x202c36327225202c,0x646c090a3b367225,0x662509203233662e\n"
".quad 0x3272255b202c3331,0x6c090a3b5d342b37,0x2509203233662e64,0x72255b202c343166\n"
".quad 0x090a3b5d382b3732,0x752e6f6c2e6c756d,0x3731722509203233,0x31202c397225202c\n"
".quad 0x2e646461090a3b32,0x3272250920323375,0x2c37317225202c34,0x6c090a3b36722520\n"
".quad 0x2509203233662e64,0x72255b202c353166,0x090a3b5d302b3732,0x09203233662e646c\n"
".quad 0x255b202c36316625,0x0a3b5d302b343272,0x3233662e64646109,0x202c373166250920\n"
".quad 0x6625202c35316625,0x2e7473090a3b3631,0x72255b0920323366,0x25202c5d302b3432\n"
".quad 0x646c090a3b373166,0x662509203233662e,0x3272255b202c3831,0x61090a3b5d342b34\n"
".quad 0x09203233662e6464,0x6625202c39316625,0x33316625202c3831,0x33662e7473090a3b\n"
".quad 0x343272255b092032,0x316625202c5d342b,0x662e646c090a3b39,0x3032662509203233\n"
".quad 0x2b343272255b202c,0x646461090a3b5d38,0x662509203233662e,0x30326625202c3132\n"
".quad 0x0a3b34316625202c,0x203233662e747309,0x382b343272255b09,0x3b31326625202c5d\n"
".quad 0x325f335f744c240a,0x62090a3a38393233,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x0920617262203170,0x33325f335f744c24,0x6f78090a3b303138,0x2509203233622e72\n"
".quad 0x397225202c383272,0x756d090a3b34202c,0x3233752e6f6c2e6c,0x202c393272250920\n"
".quad 0x3231202c38327225,0x752e646461090a3b,0x3033722509203233,0x202c39327225202c\n"
".quad 0x646c090a3b367225,0x662509203233662e,0x3372255b202c3232,0x6c090a3b5d342b30\n"
".quad 0x2509203233662e64,0x72255b202c333266,0x090a3b5d382b3033,0x752e6f6c2e6c756d\n"
".quad 0x3731722509203233,0x31202c397225202c,0x2e646461090a3b32,0x3272250920323375\n"
".quad 0x2c37317225202c34,0x6c090a3b36722520,0x2509203233662e64,0x72255b202c343266\n"
".quad 0x090a3b5d302b3033,0x09203233662e646c,0x255b202c35326625,0x0a3b5d302b343272\n"
".quad 0x3233662e64646109,0x202c363266250920,0x6625202c34326625,0x2e7473090a3b3532\n"
".quad 0x72255b0920323366,0x25202c5d302b3432,0x646c090a3b363266,0x662509203233662e\n"
".quad 0x3272255b202c3732,0x61090a3b5d342b34,0x09203233662e6464,0x6625202c38326625\n"
".quad 0x32326625202c3732,0x33662e7473090a3b,0x343272255b092032,0x326625202c5d342b\n"
".quad 0x662e646c090a3b38,0x3932662509203233,0x2b343272255b202c,0x646461090a3b5d38\n"
".quad 0x662509203233662e,0x39326625202c3033,0x0a3b33326625202c,0x203233662e747309\n"
".quad 0x382b343272255b09,0x3b30336625202c5d,0x325f335f744c240a,0x62090a3a30313833\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x34325f335f744c24\n"
".quad 0x6f78090a3b323233,0x2509203233622e72,0x397225202c313372,0x756d090a3b32202c\n"
".quad 0x3233752e6f6c2e6c,0x202c323372250920,0x3231202c31337225,0x752e646461090a3b\n"
".quad 0x3333722509203233,0x202c32337225202c,0x646c090a3b367225,0x662509203233662e\n"
".quad 0x3372255b202c3133,0x6c090a3b5d342b33,0x2509203233662e64,0x72255b202c323366\n"
".quad 0x090a3b5d382b3333,0x752e6f6c2e6c756d,0x3731722509203233,0x31202c397225202c\n"
".quad 0x2e646461090a3b32,0x3272250920323375,0x2c37317225202c34,0x6c090a3b36722520\n"
".quad 0x2509203233662e64,0x72255b202c333366,0x090a3b5d302b3333,0x09203233662e646c\n"
".quad 0x255b202c34336625,0x0a3b5d302b343272,0x3233662e64646109,0x202c353366250920\n"
".quad 0x6625202c33336625,0x2e7473090a3b3433,0x72255b0920323366,0x25202c5d302b3432\n"
".quad 0x646c090a3b353366,0x662509203233662e,0x3272255b202c3633,0x61090a3b5d342b34\n"
".quad 0x09203233662e6464,0x6625202c37336625,0x31336625202c3633,0x33662e7473090a3b\n"
".quad 0x343272255b092032,0x336625202c5d342b,0x662e646c090a3b37,0x3833662509203233\n"
".quad 0x2b343272255b202c,0x646461090a3b5d38,0x662509203233662e,0x38336625202c3933\n"
".quad 0x0a3b32336625202c,0x203233662e747309,0x382b343272255b09,0x3b39336625202c5d\n"
".quad 0x325f335f744c240a,0x62090a3a32323334,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x0920617262203170,0x34325f335f744c24,0x6f78090a3b343338,0x2509203233622e72\n"
".quad 0x397225202c343372,0x756d090a3b31202c,0x3233752e6f6c2e6c,0x202c353372250920\n"
".quad 0x3231202c34337225,0x752e646461090a3b,0x3633722509203233,0x202c35337225202c\n"
".quad 0x646c090a3b367225,0x662509203233662e,0x3372255b202c3034,0x6c090a3b5d342b36\n"
".quad 0x2509203233662e64,0x72255b202c313466,0x090a3b5d382b3633,0x752e6f6c2e6c756d\n"
".quad 0x3731722509203233,0x31202c397225202c,0x2e646461090a3b32,0x3272250920323375\n"
".quad 0x2c37317225202c34,0x6c090a3b36722520,0x2509203233662e64,0x72255b202c323466\n"
".quad 0x090a3b5d302b3633,0x09203233662e646c,0x255b202c33346625,0x0a3b5d302b343272\n"
".quad 0x3233662e64646109,0x202c343466250920,0x6625202c32346625,0x2e7473090a3b3334\n"
".quad 0x72255b0920323366,0x25202c5d302b3432,0x646c090a3b343466,0x662509203233662e\n"
".quad 0x3272255b202c3534,0x61090a3b5d342b34,0x09203233662e6464,0x6625202c36346625\n"
".quad 0x30346625202c3534,0x33662e7473090a3b,0x343272255b092032,0x346625202c5d342b\n"
".quad 0x662e646c090a3b36,0x3734662509203233,0x2b343272255b202c,0x646461090a3b5d38\n"
".quad 0x662509203233662e,0x37346625202c3834,0x0a3b31346625202c,0x203233662e747309\n"
".quad 0x382b343272255b09,0x3b38346625202c5d,0x325f335f744c240a,0x62090a3a34333834\n"
".quad 0x20636e79732e7261,0x6f6c2e090a3b3009,0x3136310937310963,0x70252140090a3009\n"
".quad 0x2409206172622031,0x3835325f335f744c,0x6f6c2e090a3b3835,0x3231310936310963\n"
".quad 0x2e6c756d090a3009,0x09203233752e6f6c,0x7225202c37317225,0x090a3b3231202c39\n"
".quad 0x203233752e646461,0x25202c3831722509,0x347225202c373172,0x33662e646c090a3b\n"
".quad 0x2c39346625092032,0x302b383172255b20,0x662e646c090a3b5d,0x3035662509203233\n"
".quad 0x302b3672255b202c,0x2e766f6d090a3b5d,0x3566250920323366,0x3864336630202c31\n"
".quad 0x20203b3030303030,0x2e30202f2f092020,0x756d090a35323630,0x2509203233662e6c\n"
".quad 0x356625202c323566,0x3b31356625202c30,0x33662e627573090a,0x2c33356625092032\n"
".quad 0x25202c3934662520,0x6f6d090a3b323566,0x2509203233662e76,0x356625202c343566\n"
".quad 0x662e646c090a3b33,0x3535662509203233,0x2b383172255b202c,0x2e646c090a3b5d34\n"
".quad 0x3566250920323366,0x2b3672255b202c36,0x766f6d090a3b5d34,0x662509203233662e\n"
".quad 0x64336630202c3735,0x203b303030303038,0x30202f2f09202020,0x6d090a353236302e\n"
".quad 0x09203233662e6c75,0x6625202c38356625,0x37356625202c3635,0x662e627573090a3b\n"
".quad 0x3935662509203233,0x202c35356625202c,0x6d090a3b38356625,0x09203233662e766f\n"
".quad 0x6625202c30366625,0x2e646c090a3b3935,0x3666250920323366,0x383172255b202c31\n"
".quad 0x646c090a3b5d382b,0x662509203233662e,0x3672255b202c3236,0x6f6d090a3b5d382b\n"
".quad 0x2509203233662e76,0x336630202c333666,0x3b30303030303864,0x202f2f0920202020\n"
".quad 0x090a353236302e30,0x203233662e6c756d,0x25202c3436662509,0x366625202c323666\n"
".quad 0x2e627573090a3b33,0x3666250920323366,0x2c31366625202c35,0x090a3b3436662520\n"
".quad 0x203233662e766f6d,0x25202c3636662509,0x744c240a3b353666,0x36343335325f335f\n"
".quad 0x3170252140090a3a,0x4c24092061726220,0x353835325f335f74,0x636f6c2e090a3b38\n"
".quad 0x0939313109363109,0x2e61747663090a30,0x752e646572616873,0x3733722509203233\n"
".quad 0x616475635f5f202c,0x765f6c61636f6c5f,0x31363537335f7261,0x5f6e6f6e5f35335f\n"
".quad 0x6f635f74736e6f63,0x65636e6169726176,0x756d090a3b305f5f,0x3233732e6f6c2e6c\n"
".quad 0x202c383372250920,0x0a3b36202c397225,0x2e6f6c2e6c756d09,0x3372250920323375\n"
".quad 0x2c38337225202c39,0x646461090a3b3420,0x722509203233752e,0x39337225202c3034\n"
".quad 0x0a3b37337225202c,0x3233662e766f6d09,0x202c373666250920,0x6d090a3b34356625\n"
".quad 0x09203233662e6c75,0x6625202c38366625,0x37366625202c3736,0x33662e7473090a3b\n"
".quad 0x303472255b092032,0x366625202c5d302b,0x636f6c2e090a3b38,0x0930323109363109\n"
".quad 0x662e766f6d090a30,0x3936662509203233,0x0a3b30366625202c,0x3233662e6c756d09\n"
".quad 0x202c303766250920,0x6625202c39366625,0x2e7473090a3b3736,0x72255b0920323366\n"
".quad 0x25202c5d342b3034,0x6c2e090a3b303766,0x323109363109636f,0x766f6d090a300931\n"
".quad 0x662509203233662e,0x36366625202c3137,0x662e6c756d090a3b,0x3237662509203233\n"
".quad 0x202c31376625202c,0x73090a3b37366625,0x5b09203233662e74,0x2c5d382b30347225\n"
".quad 0x090a3b3237662520,0x09363109636f6c2e,0x6d090a3009323231,0x09203233662e6c75\n"
".quad 0x6625202c33376625,0x39366625202c3936,0x33662e7473090a3b,0x303472255b092032\n"
".quad 0x6625202c5d32312b,0x6f6c2e090a3b3337,0x3332310936310963,0x2e6c756d090a3009\n"
".quad 0x3766250920323366,0x2c31376625202c34,0x090a3b3936662520,0x09203233662e7473\n"
".quad 0x36312b303472255b,0x3b34376625202c5d,0x3109636f6c2e090a,0x0a30093432310936\n"
".quad 0x3233662e6c756d09,0x202c353766250920,0x6625202c31376625,0x2e7473090a3b3137\n"
".quad 0x72255b0920323366,0x202c5d30322b3034,0x4c240a3b35376625,0x353835325f335f74\n"
".quad 0x61747663090a3a38,0x2e6465726168732e,0x3372250920323375,0x6475635f5f202c37\n"
".quad 0x5f6c61636f6c5f61,0x363537335f726176,0x6e6f6e5f35335f31,0x635f74736e6f635f\n"
".quad 0x636e61697261766f,0x2e090a3b305f5f65,0x3109363109636f6c,0x6162090a30093632\n"
".quad 0x0920636e79732e72,0x2e766f6d090a3b30,0x3472250920323373,0x4c240a3b38202c31\n"
".quad 0x383836325f335f74,0x6c3c2f2f200a3a32,0x6f6f4c203e706f6f,0x6c2079646f622070\n"
".quad 0x2c36323120656e69,0x676e697473656e20,0x203a687470656420,0x6d69747365202c31\n"
".quad 0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x31347225202c3270,0x090a3b397225202c,0x7262203270252140\n"
".quad 0x335f744c24092061,0x0a3b38333137325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a32383836325f,0x09363109636f6c2e,0x6d090a3009303331\n"
".quad 0x33732e6f6c2e6c75,0x2c38337225092032,0x3b36202c39722520,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x38337225202c3933,0x6461090a3b34202c,0x2509203233752e64\n"
".quad 0x337225202c303472,0x3b37337225202c39,0x3233662e646c090a,0x202c363766250920\n"
".quad 0x5d302b303472255b,0x732e646461090a3b,0x3234722509203233,0x202c31347225202c\n"
".quad 0x756d090a3b397225,0x3233732e6f6c2e6c,0x202c333472250920,0x3b36202c32347225\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x33347225202c3434,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x337225202c353472,0x3b34347225202c37,0x3233662e646c090a\n"
".quad 0x202c373766250920,0x5d302b353472255b,0x662e646461090a3b,0x3837662509203233\n"
".quad 0x202c36376625202c,0x73090a3b37376625,0x5b09203233662e74,0x2c5d302b30347225\n"
".quad 0x240a3b3837662520,0x3137325f335f744c,0x3c2f2f200a3a3833,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36323120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836325f335f744c,0x2e726162090a3238,0x3b300920636e7973\n"
".quad 0x203270252140090a,0x744c240920617262,0x30353637325f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32383836325f335f,0x3109636f6c2e090a\n"
".quad 0x0a30093133310936,0x2e6f6c2e6c756d09,0x3372250920323373,0x202c397225202c38\n"
".quad 0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c39337225,0x090a3b34202c3833\n"
".quad 0x203233752e646461,0x25202c3034722509,0x337225202c393372,0x662e646c090a3b37\n"
".quad 0x3937662509203233,0x2b303472255b202c,0x646461090a3b5d34,0x722509203233732e\n"
".quad 0x31347225202c3634,0x090a3b397225202c,0x732e6f6c2e6c756d,0x3734722509203233\n"
".quad 0x202c36347225202c,0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c38347225\n"
".quad 0x090a3b34202c3734,0x203233752e646461,0x25202c3934722509,0x347225202c373372\n"
".quad 0x662e646c090a3b38,0x3038662509203233,0x2b393472255b202c,0x646461090a3b5d34\n"
".quad 0x662509203233662e,0x39376625202c3138,0x0a3b30386625202c,0x203233662e747309\n"
".quad 0x342b303472255b09,0x3b31386625202c5d,0x325f335f744c240a,0x2f200a3a30353637\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3632,0x64656c6562616c20,0x325f335f744c2420,0x6162090a32383836\n"
".quad 0x0920636e79732e72,0x70252140090a3b30,0x2409206172622032,0x3138325f335f744c\n"
".quad 0x3c2f2f200a3b3236,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3836325f335f744c\n"
".quad 0x636f6c2e090a3238,0x0932333109363109,0x6c2e6c756d090a30,0x2509203233732e6f\n"
".quad 0x397225202c383372,0x756d090a3b36202c,0x3233752e6f6c2e6c,0x202c393372250920\n"
".quad 0x3b34202c38337225,0x33752e646461090a,0x2c30347225092032,0x25202c3933722520\n"
".quad 0x646c090a3b373372,0x662509203233662e,0x3472255b202c3238,0x61090a3b5d382b30\n"
".quad 0x09203233732e6464,0x7225202c30357225,0x3b397225202c3134,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x30357225202c3135,0x756d090a3b36202c,0x3233752e6f6c2e6c\n"
".quad 0x202c323572250920,0x3b34202c31357225,0x33752e646461090a,0x2c33357225092032\n"
".quad 0x25202c3733722520,0x646c090a3b323572,0x662509203233662e,0x3572255b202c3338\n"
".quad 0x61090a3b5d382b33,0x09203233662e6464,0x6625202c34386625,0x33386625202c3238\n"
".quad 0x33662e7473090a3b,0x303472255b092032,0x386625202c5d382b,0x335f744c240a3b34\n"
".quad 0x0a3a32363138325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a32383836325f,0x636e79732e726162,0x2140090a3b300920,0x2061726220327025\n"
".quad 0x325f335f744c2409,0x2f200a3b34373638,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3632,0x64656c6562616c20\n"
".quad 0x325f335f744c2420,0x6c2e090a32383836,0x333109363109636f,0x6c756d090a300933\n"
".quad 0x203233732e6f6c2e,0x25202c3833722509,0x090a3b36202c3972,0x752e6f6c2e6c756d\n"
".quad 0x3933722509203233,0x202c38337225202c,0x2e646461090a3b34,0x3472250920323375\n"
".quad 0x2c39337225202c30,0x090a3b3733722520,0x09203233662e646c,0x255b202c35386625\n"
".quad 0x3b5d32312b303472,0x33732e646461090a,0x2c34357225092032,0x25202c3134722520\n"
".quad 0x6c756d090a3b3972,0x203233732e6f6c2e,0x25202c3535722509,0x0a3b36202c343572\n"
".quad 0x2e6f6c2e6c756d09,0x3572250920323375,0x2c35357225202c36,0x646461090a3b3420\n"
".quad 0x722509203233752e,0x37337225202c3735,0x0a3b36357225202c,0x203233662e646c09\n"
".quad 0x5b202c3638662509,0x5d32312b37357225,0x662e646461090a3b,0x3738662509203233\n"
".quad 0x202c35386625202c,0x73090a3b36386625,0x5b09203233662e74,0x5d32312b30347225\n"
".quad 0x0a3b37386625202c,0x38325f335f744c24,0x2f2f200a3a343736,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x36325f335f744c24,0x726162090a323838,0x300920636e79732e\n"
".quad 0x3270252140090a3b,0x4c24092061726220,0x383139325f335f74,0x6c3c2f2f200a3b36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x383836325f335f74,0x09636f6c2e090a32\n"
".quad 0x3009343331093631,0x6f6c2e6c756d090a,0x722509203233732e,0x2c397225202c3833\n"
".quad 0x6c756d090a3b3620,0x203233752e6f6c2e,0x25202c3933722509,0x0a3b34202c383372\n"
".quad 0x3233752e64646109,0x202c303472250920,0x7225202c39337225,0x2e646c090a3b3733\n"
".quad 0x3866250920323366,0x303472255b202c38,0x61090a3b5d36312b,0x09203233732e6464\n"
".quad 0x7225202c38357225,0x3b397225202c3134,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x38357225202c3935,0x756d090a3b36202c,0x3233752e6f6c2e6c,0x202c303672250920\n"
".quad 0x3b34202c39357225,0x33752e646461090a,0x2c31367225092032,0x25202c3733722520\n"
".quad 0x646c090a3b303672,0x662509203233662e,0x3672255b202c3938,0x090a3b5d36312b31\n"
".quad 0x203233662e646461,0x25202c3039662509,0x386625202c383866,0x662e7473090a3b39\n"
".quad 0x3472255b09203233,0x25202c5d36312b30,0x744c240a3b303966,0x36383139325f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36323120656e,0x62616c2064616568,0x744c242064656c65,0x32383836325f335f\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x7262203270252140,0x335f744c24092061\n"
".quad 0x0a3b38393639325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a32383836325f,0x09363109636f6c2e,0x6d090a3009353331,0x33732e6f6c2e6c75\n"
".quad 0x2c38337225092032,0x3b36202c39722520,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x38337225202c3933,0x6461090a3b34202c,0x2509203233752e64,0x337225202c303472\n"
".quad 0x3b37337225202c39,0x3233662e646c090a,0x202c313966250920,0x30322b303472255b\n"
".quad 0x2e646461090a3b5d,0x3672250920323373,0x2c31347225202c32,0x6d090a3b39722520\n"
".quad 0x33732e6f6c2e6c75,0x2c33367225092032,0x36202c3236722520,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x367225202c343672,0x61090a3b34202c33,0x09203233752e6464\n"
".quad 0x7225202c35367225,0x34367225202c3733,0x33662e646c090a3b,0x2c32396625092032\n"
".quad 0x322b353672255b20,0x646461090a3b5d30,0x662509203233662e,0x31396625202c3339\n"
".quad 0x0a3b32396625202c,0x203233662e747309,0x322b303472255b09,0x33396625202c5d30\n"
".quad 0x5f335f744c240a3b,0x200a3a3839363932,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363231,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x62090a3238383632,0x20636e79732e7261,0x6f6c2e090a3b3009\n"
".quad 0x3832310936310963,0x2e726873090a3009,0x3472250920323373,0x2c31347225202c31\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x090a3b30202c3636,0x2e74672e70746573\n"
".quad 0x3370250920323373,0x202c31347225202c,0x40090a3b36367225,0x2061726220337025\n"
".quad 0x325f335f744c2409,0x6c090a3b32383836,0x6465726168732e64,0x203233662e34762e\n"
".quad 0x252c343966257b09,0x363966252c353966,0x5f5f5b202c7d5f2c,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f35335f31363537,0x736e6f635f6e6f6e,0x697261766f635f74\n"
".quad 0x2b305f5f65636e61,0x6f6c2e090a3b5d30,0x0934350936310963,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x202c373966250920,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f31363537335f72,0x635f6e6f6e5f3533,0x766f635f74736e6f,0x5f65636e61697261\n"
".quad 0x0a3b5d32312b305f,0x3233662e766f6d09,0x202c383966250920,0x3030303866336630\n"
".quad 0x09202020203b3030,0x6d66090a31202f2f,0x3233662e6e722e61,0x202c393966250920\n"
".quad 0x6625202c38396625,0x37396625202c3539,0x68732e646c090a3b,0x2e32762e64657261\n"
".quad 0x66257b0920323366,0x303166252c303031,0x635f5f5b202c7d31,0x61636f6c5f616475\n"
".quad 0x37335f7261765f6c,0x6e5f35335f313635,0x74736e6f635f6e6f,0x61697261766f635f\n"
".quad 0x312b305f5f65636e,0x766f6d090a3b5d36,0x662509203233662e,0x336630202c323031\n"
".quad 0x3b30303030303866,0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c333031,0x36396625202c3230,0x3b3030316625202c,0x33662e766f6d090a\n"
".quad 0x3430316625092032,0x303866336630202c,0x2020203b30303030,0x66090a31202f2f09\n"
".quad 0x33662e6e722e616d,0x3530316625092032,0x202c34396625202c,0x25202c3430316625\n"
".quad 0x6f6d090a3b353966,0x2509203233662e76,0x6630202c36303166,0x3030303030386633\n"
".quad 0x202f2f092020203b,0x722e616d66090a31,0x2509203233662e6e,0x6625202c37303166\n"
".quad 0x316625202c363031,0x39396625202c3030,0x662e766f6d090a3b,0x3031662509203233\n"
".quad 0x3866336630202c38,0x20203b3030303030,0x090a31202f2f0920,0x662e6e722e616d66\n"
".quad 0x3031662509203233,0x3830316625202c39,0x2c3130316625202c,0x0a3b333031662520\n"
".quad 0x3233662e766f6d09,0x2c30313166250920,0x3030386633663020,0x092020203b303030\n"
".quad 0x6d66090a31202f2f,0x3233662e6e722e61,0x2c31313166250920,0x25202c3639662520\n"
".quad 0x6625202c30313166,0x616d090a3b353031,0x2509203233662e78,0x6625202c32313166\n"
".quad 0x316625202c373031,0x78616d090a3b3131,0x662509203233662e,0x316625202c333131\n"
".quad 0x31316625202c3930,0x2e706372090a3b32,0x09203233662e6e72,0x25202c3431316625\n"
".quad 0x6d090a3b33313166,0x09203233662e6c75,0x25202c3531316625,0x6625202c37303166\n"
".quad 0x756d090a3b343131,0x2509203233662e6c,0x6625202c36313166,0x316625202c313131\n"
".quad 0x6c756d090a3b3431,0x662509203233662e,0x316625202c373131,0x31316625202c3930\n"
".quad 0x2e6c756d090a3b34,0x3166250920323366,0x31316625202c3831,0x3030316625202c35\n"
".quad 0x662e6c756d090a3b,0x3131662509203233,0x3531316625202c39,0x0a3b35396625202c\n"
".quad 0x3233662e6c756d09,0x2c30323166250920,0x202c353131662520,0x66090a3b37396625\n"
".quad 0x33662e6e722e616d,0x3132316625092032,0x2c3631316625202c,0x25202c3639662520\n"
".quad 0x66090a3b38313166,0x33662e6e722e616d,0x3232316625092032,0x202c34396625202c\n"
".quad 0x25202c3631316625,0x66090a3b39313166,0x33662e6e722e616d,0x3332316625092032\n"
".quad 0x2c3631316625202c,0x25202c3539662520,0x66090a3b30323166,0x33662e6e722e616d\n"
".quad 0x3432316625092032,0x2c3731316625202c,0x202c313031662520,0x090a3b3132316625\n"
".quad 0x662e6e722e616d66,0x3231662509203233,0x2c36396625202c35,0x202c373131662520\n"
".quad 0x090a3b3232316625,0x662e6e722e616d66,0x3231662509203233,0x3731316625202c36\n"
".quad 0x2c3030316625202c,0x0a3b333231662520,0x3233662e78616d09,0x2c37323166250920\n"
".quad 0x202c353231662520,0x090a3b3632316625,0x203233662e78616d,0x202c383231662509\n"
".quad 0x25202c3432316625,0x72090a3b37323166,0x33662e6e722e7063,0x3932316625092032\n"
".quad 0x3b3832316625202c,0x3109636f6c2e090a,0x090a300930350936,0x203233662e6c756d\n"
".quad 0x202c303331662509,0x25202c3432316625,0x6d090a3b39323166,0x09203233662e6c75\n"
".quad 0x25202c3133316625,0x6625202c35323166,0x756d090a3b393231,0x2509203233662e6c\n"
".quad 0x6625202c32333166,0x316625202c363231,0x6c756d090a3b3932,0x662509203233662e\n"
".quad 0x316625202c333331,0x35396625202c3233,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c34333166,0x33316625202c3439,0x3333316625202c31,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c35333166,0x33316625202c3639,0x3433316625202c30\n"
".quad 0x09636f6c2e090a3b,0x0a30093135093631,0x3233662e6c756d09,0x2c36333166250920\n"
".quad 0x202c323331662520,0x66090a3b37396625,0x33662e6e722e616d,0x3733316625092032\n"
".quad 0x2c3133316625202c,0x25202c3539662520,0x66090a3b36333166,0x33662e6e722e616d\n"
".quad 0x3833316625092032,0x2c3033316625202c,0x202c303031662520,0x090a3b3733316625\n"
".quad 0x09363109636f6c2e,0x756d090a30093235,0x2509203233662e6c,0x6625202c39333166\n"
".quad 0x316625202c323331,0x616d66090a3b3030,0x203233662e6e722e,0x202c303431662509\n"
".quad 0x25202c3133316625,0x316625202c363966,0x616d66090a3b3933,0x203233662e6e722e\n"
".quad 0x202c313431662509,0x25202c3033316625,0x6625202c31303166,0x6c2e090a3b303431\n"
".quad 0x383509363109636f,0x2e78616d090a3009,0x3166250920323366,0x33316625202c3234\n"
".quad 0x3833316625202c35,0x662e78616d090a3b,0x3431662509203233,0x3234316625202c33\n"
".quad 0x3b3134316625202c,0x6e722e706372090a,0x662509203233662e,0x316625202c343431\n"
".quad 0x6c756d090a3b3334,0x662509203233662e,0x316625202c353431,0x33316625202c3434\n"
".quad 0x2e6c756d090a3b35,0x3166250920323366,0x34316625202c3634,0x3833316625202c34\n"
".quad 0x662e6c756d090a3b,0x3431662509203233,0x3434316625202c37,0x3b3134316625202c\n"
".quad 0x3109636f6c2e090a,0x090a300930350936,0x203233662e6c756d,0x202c383431662509\n"
".quad 0x25202c3634316625,0x6d66090a3b353966,0x3233662e6e722e61,0x2c39343166250920\n"
".quad 0x25202c3439662520,0x6625202c35343166,0x6d66090a3b383431,0x3233662e6e722e61\n"
".quad 0x2c30353166250920,0x25202c3639662520,0x6625202c37343166,0x6c2e090a3b393431\n"
".quad 0x383509363109636f,0x2e6c756d090a3009,0x3166250920323366,0x34316625202c3135\n"
".quad 0x3b37396625202c36,0x33662e6c756d090a,0x3235316625092032,0x2c3634316625202c\n"
".quad 0x0a3b303031662520,0x2e6e722e616d6609,0x3166250920323366,0x34316625202c3335\n"
".quad 0x2c35396625202c35,0x0a3b313531662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x34316625202c3435,0x2c36396625202c35,0x0a3b323531662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x34316625202c3535,0x3030316625202c37,0x3b3335316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c363531,0x30316625202c3734\n"
".quad 0x3435316625202c31,0x662e78616d090a3b,0x3531662509203233,0x3535316625202c37\n"
".quad 0x3b3035316625202c,0x33662e78616d090a,0x3835316625092032,0x2c3635316625202c\n"
".quad 0x0a3b373531662520,0x2e6e722e70637209,0x3166250920323366,0x35316625202c3935\n"
".quad 0x2e6c756d090a3b38,0x3166250920323366,0x35316625202c3036,0x3935316625202c35\n"
".quad 0x662e6c756d090a3b,0x3631662509203233,0x3635316625202c31,0x3b3935316625202c\n"
".quad 0x33662e6c756d090a,0x3236316625092032,0x2c3935316625202c,0x0a3b303531662520\n"
".quad 0x363109636f6c2e09,0x6d090a3009323509,0x09203233662e6c75,0x25202c3336316625\n"
".quad 0x6625202c30363166,0x6d66090a3b303031,0x3233662e6e722e61,0x2c34363166250920\n"
".quad 0x202c323631662520,0x6625202c36396625,0x6d66090a3b333631,0x3233662e6e722e61\n"
".quad 0x2c35363166250920,0x202c313631662520,0x25202c3130316625,0x2e090a3b34363166\n"
".quad 0x3509363109636f6c,0x6c756d090a300934,0x662509203233662e,0x316625202c363631\n"
".quad 0x35396625202c3036,0x662e6c756d090a3b,0x3631662509203233,0x3036316625202c37\n"
".quad 0x0a3b37396625202c,0x2e6e722e616d6609,0x3166250920323366,0x34396625202c3836\n"
".quad 0x2c3236316625202c,0x0a3b363631662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x36316625202c3936,0x2c35396625202c32,0x0a3b373631662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x36396625202c3037,0x2c3136316625202c,0x0a3b383631662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x36316625202c3137,0x3030316625202c31\n"
".quad 0x3b3936316625202c,0x33662e78616d090a,0x3237316625092032,0x2c3037316625202c\n"
".quad 0x0a3b313731662520,0x3233662e78616d09,0x2c33373166250920,0x202c323731662520\n"
".quad 0x090a3b3536316625,0x662e6e722e706372,0x3731662509203233,0x3337316625202c34\n"
".quad 0x09636f6c2e090a3b,0x0a30093835093631,0x3233662e6c756d09,0x2c35373166250920\n"
".quad 0x202c303731662520,0x090a3b3437316625,0x203233662e6c756d,0x202c363731662509\n"
".quad 0x25202c3137316625,0x2e090a3b34373166,0x3509363109636f6c,0x6c756d090a300930\n"
".quad 0x662509203233662e,0x316625202c373731,0x36316625202c3437,0x2e6c756d090a3b35\n"
".quad 0x3166250920323366,0x37316625202c3837,0x3b35396625202c36,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x396625202c393731,0x3537316625202c34,0x3b3837316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x396625202c303831,0x3737316625202c36\n"
".quad 0x3b3937316625202c,0x3109636f6c2e090a,0x090a300931350936,0x203233662e6c756d\n"
".quad 0x202c313831662509,0x25202c3637316625,0x6d66090a3b373966,0x3233662e6e722e61\n"
".quad 0x2c32383166250920,0x202c353731662520,0x6625202c35396625,0x6d66090a3b313831\n"
".quad 0x3233662e6e722e61,0x2c33383166250920,0x202c373731662520,0x25202c3030316625\n"
".quad 0x2e090a3b32383166,0x3509363109636f6c,0x6c756d090a300932,0x662509203233662e\n"
".quad 0x316625202c343831,0x30316625202c3637,0x2e616d66090a3b30,0x09203233662e6e72\n"
".quad 0x25202c3538316625,0x6625202c35373166,0x38316625202c3639,0x2e616d66090a3b34\n"
".quad 0x09203233662e6e72,0x25202c3638316625,0x6625202c37373166,0x316625202c313031\n"
".quad 0x6f6c2e090a3b3538,0x0938350936310963,0x662e78616d090a30,0x3831662509203233\n"
".quad 0x3038316625202c37,0x3b3338316625202c,0x33662e78616d090a,0x3838316625092032\n"
".quad 0x2c3738316625202c,0x0a3b363831662520,0x2e6e722e70637209,0x3166250920323366\n"
".quad 0x38316625202c3938,0x2e6c756d090a3b38,0x3166250920323366,0x38316625202c3039\n"
".quad 0x3038316625202c39,0x662e6c756d090a3b,0x3931662509203233,0x3938316625202c31\n"
".quad 0x3b3338316625202c,0x33662e6c756d090a,0x3239316625092032,0x2c3938316625202c\n"
".quad 0x0a3b363831662520,0x363109636f6c2e09,0x6d090a3009303509,0x09203233662e6c75\n"
".quad 0x25202c3339316625,0x6625202c31393166,0x616d66090a3b3539,0x203233662e6e722e\n"
".quad 0x202c343931662509,0x6625202c34396625,0x316625202c303931,0x616d66090a3b3339\n"
".quad 0x203233662e6e722e,0x202c353931662509,0x6625202c36396625,0x316625202c323931\n"
".quad 0x6f6c2e090a3b3439,0x0938350936310963,0x662e6c756d090a30,0x3931662509203233\n"
".quad 0x3139316625202c36,0x0a3b37396625202c,0x3233662e6c756d09,0x2c37393166250920\n"
".quad 0x202c313931662520,0x090a3b3030316625,0x662e6e722e616d66,0x3931662509203233\n"
".quad 0x3039316625202c38,0x202c35396625202c,0x090a3b3639316625,0x662e6e722e616d66\n"
".quad 0x3931662509203233,0x3039316625202c39,0x202c36396625202c,0x090a3b3739316625\n"
".quad 0x662e6e722e616d66,0x3032662509203233,0x3239316625202c30,0x2c3030316625202c\n"
".quad 0x0a3b383931662520,0x2e6e722e616d6609,0x3266250920323366,0x39316625202c3130\n"
".quad 0x3130316625202c32,0x3b3939316625202c,0x33662e78616d090a,0x3230326625092032\n"
".quad 0x2c3030326625202c,0x0a3b353931662520,0x3233662e78616d09,0x2c33303266250920\n"
".quad 0x202c313032662520,0x090a3b3230326625,0x662e6e722e706372,0x3032662509203233\n"
".quad 0x3330326625202c34,0x662e6c756d090a3b,0x3032662509203233,0x3030326625202c35\n"
".quad 0x3b3430326625202c,0x33662e6c756d090a,0x3630326625092032,0x2c3130326625202c\n"
".quad 0x0a3b343032662520,0x3233662e6c756d09,0x2c37303266250920,0x202c343032662520\n"
".quad 0x090a3b3539316625,0x09363109636f6c2e,0x756d090a30093235,0x2509203233662e6c\n"
".quad 0x6625202c38303266,0x316625202c353032,0x616d66090a3b3030,0x203233662e6e722e\n"
".quad 0x202c393032662509,0x25202c3730326625,0x326625202c363966,0x616d66090a3b3830\n"
".quad 0x203233662e6e722e,0x202c303132662509,0x25202c3630326625,0x6625202c31303166\n"
".quad 0x6c2e090a3b393032,0x343509363109636f,0x2e6c756d090a3009,0x3266250920323366\n"
".quad 0x30326625202c3131,0x3b35396625202c35,0x33662e6c756d090a,0x3231326625092032\n"
".quad 0x2c3530326625202c,0x090a3b3739662520,0x662e6e722e616d66,0x3132662509203233\n"
".quad 0x2c34396625202c33,0x202c373032662520,0x090a3b3131326625,0x662e6e722e616d66\n"
".quad 0x3132662509203233,0x3730326625202c34,0x202c35396625202c,0x090a3b3231326625\n"
".quad 0x662e6e722e616d66,0x3132662509203233,0x2c36396625202c35,0x202c363032662520\n"
".quad 0x090a3b3331326625,0x662e6e722e616d66,0x3132662509203233,0x3630326625202c36\n"
".quad 0x2c3030316625202c,0x0a3b343132662520,0x3233662e78616d09,0x2c37313266250920\n"
".quad 0x202c353132662520,0x090a3b3631326625,0x203233662e78616d,0x202c383132662509\n"
".quad 0x25202c3731326625,0x72090a3b30313266,0x33662e6e722e7063,0x3931326625092032\n"
".quad 0x3b3831326625202c,0x3109636f6c2e090a,0x090a300938350936,0x203233662e6c756d\n"
".quad 0x202c303232662509,0x25202c3531326625,0x6d090a3b39313266,0x09203233662e6c75\n"
".quad 0x25202c3132326625,0x6625202c36313266,0x6c2e090a3b393132,0x363109373109636f\n"
".quad 0x252140090a300931,0x0920617262203170,0x30335f335f744c24,0x6c2e090a3b363634\n"
".quad 0x363109373109636f,0x747663090a300934,0x6465726168732e61,0x722509203233752e\n"
".quad 0x75635f5f202c3736,0x6c61636f6c5f6164,0x3837335f7261765f,0x6f6e5f35335f3438\n"
".quad 0x5f74736e6f635f6e,0x0a3b335f5f737064,0x2e6f6c2e6c756d09,0x3172250920323375\n"
".quad 0x202c397225202c37,0x646461090a3b3231,0x722509203233752e,0x37317225202c3831\n"
".quad 0x090a3b347225202c,0x09203233662e646c,0x5b202c3232326625,0x3b5d342b38317225\n"
".quad 0x33662e6c756d090a,0x3332326625092032,0x2c3232326625202c,0x0a3b313232662520\n"
".quad 0x203233662e646c09,0x202c343232662509,0x5d302b383172255b,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c35323266,0x326625202c343232,0x32326625202c3032\n"
".quad 0x662e646c090a3b33,0x3232662509203233,0x383172255b202c36,0x756d090a3b5d382b\n"
".quad 0x2509203233662e6c,0x6625202c37323266,0x326625202c393132,0x616d66090a3b3031\n"
".quad 0x203233662e6e722e,0x202c383232662509,0x25202c3632326625,0x6625202c37323266\n"
".quad 0x756d090a3b353232,0x3233752e6f6c2e6c,0x202c383672250920,0x0a3b34202c397225\n"
".quad 0x3233752e64646109,0x202c393672250920,0x7225202c37367225,0x2e7473090a3b3836\n"
".quad 0x72255b0920323366,0x25202c5d302b3936,0x4c240a3b38323266,0x363430335f335f74\n"
".quad 0x61747663090a3a36,0x2e6465726168732e,0x3672250920323375,0x6475635f5f202c37\n"
".quad 0x5f6c61636f6c5f61,0x383837335f726176,0x6e6f6e5f35335f34,0x645f74736e6f635f\n"
".quad 0x090a3b335f5f7370,0x09373109636f6c2e,0x62090a3009373631,0x20636e79732e7261\n"
".quad 0x252140090a3b3009,0x0920617262203170,0x30335f335f744c24,0x6c2e090a3b383739\n"
".quad 0x373109373109636f,0x766f6d090a300930,0x722509203233752e,0x090a3b30202c3037\n"
".quad 0x2e656e2e70746573,0x3470250920323375,0x25202c397225202c,0x2540090a3b303772\n"
".quad 0x0920617262203470,0x31335f335f744c24,0x6f6d090a3b303934,0x2509203233732e76\n"
".quad 0x367225202c313772,0x2e646461090a3b37,0x3772250920323375,0x2c37367225202c32\n"
".quad 0x6f6d090a3b343620,0x2509203233732e76,0x387225202c333772,0x5f335f744c240a3b\n"
".quad 0x200a3a3431353233,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x73656e202c303731,0x70656420676e6974,0x69202c31203a6874,0x6e6f697461726574\n"
".quad 0x2e090a3631203a73,0x3909373109636f6c,0x2e646c090a300938,0x3266250920323366\n"
".quad 0x3772255b202c3932,0x6c090a3b5d302b31,0x6465726168732e64,0x203233662e34762e\n"
".quad 0x333266252c5f7b09,0x2c31333266252c30,0x202c7d3233326625,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f34383837335f72,0x635f6e6f6e5f3533,0x7370645f74736e6f\n"
".quad 0x3b5d38342b335f5f,0x746c2e746573090a,0x3233662e3233752e,0x202c343772250920\n"
".quad 0x25202c3133326625,0x6e090a3b39323266,0x09203233732e6765,0x7225202c35377225\n"
".quad 0x746573090a3b3437,0x2e3233752e746c2e,0x3772250920323366,0x3233326625202c36\n"
".quad 0x3b3932326625202c,0x33732e67656e090a,0x2c37377225092032,0x090a3b3637722520\n"
".quad 0x203233732e646461,0x25202c3837722509,0x377225202c353772,0x732e646c090a3b37\n"
".quad 0x33662e6465726168,0x3333326625092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x383837335f726176,0x6e6f6e5f35335f34,0x645f74736e6f635f,0x38342b335f5f7370\n"
".quad 0x2e746573090a3b5d,0x662e3233752e746c,0x3937722509203233,0x2c3333326625202c\n"
".quad 0x0a3b393232662520,0x3233732e67656e09,0x202c303872250920,0x73090a3b39377225\n"
".quad 0x33752e746c2e7465,0x2509203233662e32,0x326625202c313872,0x32326625202c3033\n"
".quad 0x2e67656e090a3b39,0x3872250920323373,0x3b31387225202c32,0x33732e646461090a\n"
".quad 0x2c33387225092032,0x25202c3038722520,0x646c090a3b323872,0x2e6465726168732e\n"
".quad 0x09203233662e3476,0x252c34333266257b,0x3266252c35333266,0x37333266252c3633\n"
".quad 0x75635f5f5b202c7d,0x6c61636f6c5f6164,0x3837335f7261765f,0x6f6e5f35335f3438\n"
".quad 0x5f74736e6f635f6e,0x302b335f5f737064,0x2e746573090a3b5d,0x662e3233752e746c\n"
".quad 0x3438722509203233,0x2c3533326625202c,0x0a3b393232662520,0x3233732e67656e09\n"
".quad 0x202c353872250920,0x6c090a3b34387225,0x6465726168732e64,0x203233662e32762e\n"
".quad 0x2c38333266257b09,0x202c7d3933326625,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f34383837335f72,0x635f6e6f6e5f3533,0x7370645f74736e6f,0x3b5d30342b335f5f\n"
".quad 0x746c2e746573090a,0x3233662e3233752e,0x202c363872250920,0x25202c3933326625\n"
".quad 0x6e090a3b39323266,0x09203233732e6765,0x7225202c37387225,0x646461090a3b3638\n"
".quad 0x722509203233732e,0x35387225202c3838,0x0a3b37387225202c,0x2e746c2e74657309\n"
".quad 0x203233662e323375,0x25202c3938722509,0x6625202c34333266,0x656e090a3b393232\n"
".quad 0x2509203233732e67,0x387225202c303972,0x2e746573090a3b39,0x662e3233752e746c\n"
".quad 0x3139722509203233,0x2c3633326625202c,0x0a3b393232662520,0x3233732e67656e09\n"
".quad 0x202c323972250920,0x61090a3b31397225,0x09203233732e6464,0x7225202c33397225\n"
".quad 0x32397225202c3039,0x6c2e746573090a3b,0x33662e3233752e74,0x2c34397225092032\n"
".quad 0x202c373332662520,0x090a3b3932326625,0x203233732e67656e,0x25202c3539722509\n"
".quad 0x646c090a3b343972,0x2e6465726168732e,0x09203233662e3476,0x252c30343266257b\n"
".quad 0x3266252c31343266,0x33343266252c3234,0x75635f5f5b202c7d,0x6c61636f6c5f6164\n"
".quad 0x3837335f7261765f,0x6f6e5f35335f3438,0x5f74736e6f635f6e,0x312b335f5f737064\n"
".quad 0x746573090a3b5d36,0x2e3233752e746c2e,0x3972250920323366,0x3034326625202c36\n"
".quad 0x3b3932326625202c,0x33732e67656e090a,0x2c37397225092032,0x090a3b3639722520\n"
".quad 0x203233732e646461,0x25202c3839722509,0x397225202c353972,0x2e746573090a3b37\n"
".quad 0x662e3233752e746c,0x3939722509203233,0x2c3134326625202c,0x0a3b393232662520\n"
".quad 0x3233732e67656e09,0x2c30303172250920,0x090a3b3939722520,0x752e746c2e746573\n"
".quad 0x09203233662e3233,0x25202c3130317225,0x6625202c32343266,0x656e090a3b393232\n"
".quad 0x2509203233732e67,0x7225202c32303172,0x6461090a3b313031,0x2509203233732e64\n"
".quad 0x7225202c33303172,0x317225202c303031,0x746573090a3b3230,0x2e3233752e746c2e\n"
".quad 0x3172250920323366,0x34326625202c3430,0x3932326625202c33,0x732e67656e090a3b\n"
".quad 0x3031722509203233,0x3430317225202c35,0x68732e646c090a3b,0x2e32762e64657261\n"
".quad 0x66257b0920323366,0x343266252c343432,0x635f5f5b202c7d35,0x61636f6c5f616475\n"
".quad 0x37335f7261765f6c,0x6e5f35335f343838,0x74736e6f635f6e6f,0x2b335f5f7370645f\n"
".quad 0x6573090a3b5d3233,0x3233752e746c2e74,0x722509203233662e,0x326625202c363031\n"
".quad 0x32326625202c3434,0x2e67656e090a3b39,0x3172250920323373,0x30317225202c3730\n"
".quad 0x2e646461090a3b36,0x3172250920323373,0x30317225202c3830,0x3730317225202c35\n"
".quad 0x6c2e746573090a3b,0x33662e3233752e74,0x3930317225092032,0x2c3534326625202c\n"
".quad 0x0a3b393232662520,0x3233732e67656e09,0x2c30313172250920,0x0a3b393031722520\n"
".quad 0x2e746c2e74657309,0x203233662e323375,0x202c313131722509,0x25202c3833326625\n"
".quad 0x6e090a3b39323266,0x09203233732e6765,0x25202c3231317225,0x61090a3b31313172\n"
".quad 0x09203233732e6464,0x25202c3331317225,0x7225202c30313172,0x6461090a3b323131\n"
".quad 0x2509203233732e64,0x7225202c34313172,0x317225202c383031,0x646461090a3b3331\n"
".quad 0x722509203233732e,0x317225202c353131,0x31317225202c3330,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x38397225202c3631,0x3b3531317225202c,0x33732e646461090a\n"
".quad 0x3731317225092032,0x202c33397225202c,0x090a3b3631317225,0x203233732e646461\n"
".quad 0x202c383131722509,0x7225202c38387225,0x6461090a3b373131,0x2509203233732e64\n"
".quad 0x7225202c39313172,0x31317225202c3338,0x2e646461090a3b38,0x3172250920323373\n"
".quad 0x38377225202c3032,0x3b3931317225202c,0x3233732e7473090a,0x2b333772255b0920\n"
".quad 0x32317225202c5d30,0x2e646461090a3b30,0x3772250920323375,0x2c33377225202c33\n"
".quad 0x646461090a3b3420,0x722509203233752e,0x31377225202c3137,0x6573090a3b34202c\n"
".quad 0x33752e656e2e7074,0x202c357025092032,0x7225202c31377225,0x702540090a3b3237\n"
".quad 0x2409206172622035,0x3532335f335f744c,0x766f6d090a3b3431,0x722509203233732e\n"
".quad 0x0a3b30202c313231,0x33335f335f744c24,0x2f2f200a3a383335,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x383920656e696c20,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x72657469202c3120,0x203a736e6f697461,0x2e766f6d090a3531,0x3172250920323373\n"
".quad 0x240a3b30202c3232,0x3334335f335f744c,0x3c2f2f200a3a3630,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x2c383920656e696c,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6172657469202c32,0x31203a736e6f6974,0x09636f6c2e090a36,0x3009363031093731\n"
".quad 0x6c2e70746573090a,0x2509203233732e65,0x32317225202c3670,0x3132317225202c32\n"
".quad 0x2036702540090a3b,0x744c240920617262,0x32343835335f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383920656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a36303334335f33,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x32317225202c3332,0x61090a3b34202c32,0x09203233752e6464\n"
".quad 0x25202c3432317225,0x7225202c33323172,0x732e646c090a3b38,0x3231722509203233\n"
".quad 0x323172255b202c35,0x6d090a3b5d302b34,0x33752e6f6c2e6c75,0x3632317225092032\n"
".quad 0x2c3132317225202c,0x646461090a3b3420,0x722509203233752e,0x387225202c373231\n"
".quad 0x3b3632317225202c,0x3233732e646c090a,0x2c38323172250920,0x2b37323172255b20\n"
".quad 0x746573090a3b5d30,0x3233732e656e2e70,0x25202c3770250920,0x7225202c38323172\n"
".quad 0x2540090a3b353231,0x0920617262203770,0x35335f335f744c24,0x2f2f200a3b323438\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383920656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3334335f335f744c,0x2e646461090a3630\n"
".quad 0x3172250920323373,0x32317225202c3932,0x73090a3b31202c35,0x5b09203233732e74\n"
".quad 0x5d302b3432317225,0x3b3932317225202c,0x335f335f744c240a,0x4c240a3a32343835\n"
".quad 0x32363731325f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c383920656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a36303334335f33,0x3233732e64646109,0x2c32323172250920,0x202c323231722520\n"
".quad 0x2e766f6d090a3b31,0x3172250920323375,0x0a3b3631202c3033,0x656e2e7074657309\n"
".quad 0x702509203233732e,0x3232317225202c38,0x3b3033317225202c,0x622038702540090a\n"
".quad 0x5f744c2409206172,0x3b36303334335f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38392065,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a38333533335f,0x203233732e646461,0x202c313231722509\n"
".quad 0x31202c3132317225,0x752e766f6d090a3b,0x3331722509203233,0x090a3b3531202c31\n"
".quad 0x2e656e2e70746573,0x3970250920323373,0x2c3132317225202c,0x0a3b313331722520\n"
".quad 0x7262203970254009,0x335f744c24092061,0x0a3b38333533335f,0x31335f335f744c24\n"
".quad 0x6c2e090a3a303934,0x373109373109636f,0x6c756d090a300932,0x203233752e6f6c2e\n"
".quad 0x25202c3731722509,0x0a3b3231202c3972,0x3233752e64646109,0x202c383172250920\n"
".quad 0x7225202c37317225,0x662e646c090a3b34,0x3432662509203233,0x383172255b202c36\n"
".quad 0x6f6d090a3b5d302b,0x2509203233662e76,0x6625202c37343266,0x646c090a3b363432\n"
".quad 0x662509203233662e,0x72255b202c383432,0x090a3b5d342b3831,0x203233662e766f6d\n"
".quad 0x202c393432662509,0x090a3b3834326625,0x09203233662e646c,0x5b202c3035326625\n"
".quad 0x3b5d382b38317225,0x33662e766f6d090a,0x3135326625092032,0x3b3035326625202c\n"
".quad 0x335f335f744c240a,0x2e090a3a38373930,0x3109373109636f6c,0x6162090a30093537\n"
".quad 0x0920636e79732e72,0x70252140090a3b30,0x2409206172622031,0x3035335f335f744c\n"
".quad 0x6f6c2e090a3b3437,0x3837310937310963,0x2e6c756d090a3009,0x09203233752e6f6c\n"
".quad 0x25202c3233317225,0x090a3b34202c3972,0x203233752e646461,0x202c333331722509\n"
".quad 0x25202c3233317225,0x766f6d090a3b3872,0x662509203233662e,0x326625202c323532\n"
".quad 0x2e646c090a3b3734,0x3172250920323375,0x3172255b202c3433,0x090a3b5d302b3333\n"
".quad 0x752e6f6c2e6c756d,0x3331722509203233,0x3433317225202c35,0x61090a3b3231202c\n"
".quad 0x09203233752e6464,0x25202c3633317225,0x33317225202c3472,0x662e7473090a3b35\n"
".quad 0x3172255b09203233,0x25202c5d302b3633,0x6d090a3b32353266,0x09203233662e766f\n"
".quad 0x25202c3335326625,0x6c090a3b39343266,0x2509203233752e64,0x255b202c37333172\n"
".quad 0x3b5d302b33333172,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c383331\n"
".quad 0x0a3b3231202c3733,0x3233752e64646109,0x2c39333172250920,0x7225202c34722520\n"
".quad 0x7473090a3b383331,0x255b09203233662e,0x2c5d342b39333172,0x0a3b333532662520\n"
".quad 0x3233662e766f6d09,0x2c34353266250920,0x0a3b313532662520,0x203233752e646c09\n"
".quad 0x202c303431722509,0x302b33333172255b,0x2e6c756d090a3b5d,0x09203233752e6f6c\n"
".quad 0x25202c3134317225,0x3231202c30343172,0x752e646461090a3b,0x3431722509203233\n"
".quad 0x202c347225202c32,0x090a3b3134317225,0x09203233662e7473,0x382b32343172255b\n"
".quad 0x3435326625202c5d,0x5f335f744c240a3b,0x090a3a3437303533,0x09373109636f6c2e\n"
".quad 0x72090a3009303831,0x57444c240a3b7465,0x34315a5f5f646e65,0x6f6c6f4364616f6c\n"
".quad 0x4b506b636f6c4272,0x74616f6c6636506a,0x0a3a69505f325333,0x5a5f202f2f207d09\n"
".quad 0x6f4364616f6c3431,0x6b636f6c42726f6c,0x6f6c6636506a4b50,0x69505f3253337461\n"
".quad 0x65726168732e090a,0x6e67696c612e2064,0x5f2038622e203420,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x34335f3733303833,0x6e6f635f6e6f6e5f,0x7265705f735f7473\n"
".quad 0x6e6f69746174756d,0x3034365b325f5f73,0x6e6f632e090a3b5d,0x67696c612e207473\n"
".quad 0x2038622e2034206e,0x654d726f6c6f436b,0x5d32315b63697274,0x2c302c307b203d20\n"
".quad 0x302c33362c383231,0x362c3832312c302c,0x32312c302c302c33,0x090a3b7d33362c38\n"
".quad 0x2e2074736e6f632e,0x2034206e67696c61,0x68706c612038622e,0x5b34656c62615461\n"
".quad 0x307b203d205d3631,0x35362c36312c302c,0x302c302c302c302c,0x3239312c302c302c\n"
".quad 0x2c302c302c34362c,0x0a3b7d34362c3436,0x2074736e6f632e09,0x34206e67696c612e\n"
".quad 0x706c612038622e20,0x33656c6261546168,0x7b203d205d36315b,0x2c3832312c302c30\n"
".quad 0x302c302c302c3436,0x302c302c302c302c,0x2c302c302c34362c,0x090a3b7d34362c30\n"
".quad 0x2e2074736e6f632e,0x2034206e67696c61,0x646f72702038622e,0x3d205d36315b3473\n"
".quad 0x2c392c302c307b20,0x2c302c392c302c30,0x2c342c312c322c30,0x2c312c342c322c30\n"
".quad 0x6f632e090a3b7d30,0x696c612e2074736e,0x38622e2034206e67,0x5b3373646f727020\n"
".quad 0x307b203d205d3631,0x302c302c342c302c,0x312c302c302c342c,0x312c302c342c312c\n"
".quad 0x3b7d302c312c342c,0x697369762e090a0a,0x6e75662e20656c62,0x766539315a5f2063\n"
".quad 0x7265506c6c416c61,0x6e6f69746174756d,0x616f6c66364b5073,0x5374526a4b503374\n"
".quad 0x5f5366506a525f34,0x6d617261702e2820,0x5f5f203233752e20,0x6d72617061647563\n"
".quad 0x6539315a5f5f3166,0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e\n"
".quad 0x74526a4b50337461,0x5366506a525f3453,0x617261702e202c5f,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x39315a5f5f32666d,0x506c6c416c617665,0x69746174756d7265\n"
".quad 0x6c66364b50736e6f,0x526a4b503374616f,0x66506a525f345374,0x7261702e202c5f53\n"
".quad 0x203233752e206d61,0x6170616475635f5f,0x315a5f5f33666d72,0x6c6c416c61766539\n"
".quad 0x746174756d726550,0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452\n"
".quad 0x61702e202c5f5366,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261\n"
".quad 0x6c416c6176653931,0x6174756d7265506c,0x364b50736e6f6974,0x4b503374616f6c66\n"
".quad 0x6a525f345374526a,0x702e202c5f536650,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f35666d726170,0x416c61766539315a,0x74756d7265506c6c,0x4b50736e6f697461\n"
".quad 0x503374616f6c6636,0x525f345374526a4b,0x2e202c5f5366506a,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5f36666d72617061,0x6c61766539315a5f,0x756d7265506c6c41\n"
".quad 0x50736e6f69746174,0x3374616f6c66364b,0x5f345374526a4b50,0x202c5f5366506a52\n"
".quad 0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e,0x37666d7261706164\n"
".quad 0x61766539315a5f5f,0x6d7265506c6c416c,0x736e6f6974617475,0x74616f6c66364b50\n"
".quad 0x345374526a4b5033,0x5b5f5366506a525f,0x0a7b090a295d3231,0x752e206765722e09\n"
".quad 0x30313c7225203233,0x65722e090a3b3e37,0x25203233662e2067,0x0a3b3e3936323c66\n"
".quad 0x702e206765722e09,0x313c702520646572,0x6f6c2e090a3b3e33,0x3533330937310963\n"
".quad 0x6257444c240a3009,0x315a5f5f6e696765,0x6c6c416c61766539,0x746174756d726550\n"
".quad 0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452,0x646c090a3a5f5366\n"
".quad 0x752e6d617261702e,0x2c31722509203233,0x616475635f5f5b20,0x5f5f31666d726170\n"
".quad 0x416c61766539315a,0x74756d7265506c6c,0x4b50736e6f697461,0x503374616f6c6636\n"
".quad 0x525f345374526a4b,0x0a3b5d5f5366506a,0x3233732e766f6d09,0x25202c3272250920\n"
".quad 0x2e646c090a3b3172,0x33752e6d61726170,0x202c337225092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f32666d7261,0x6c416c6176653931,0x6174756d7265506c,0x364b50736e6f6974\n"
".quad 0x4b503374616f6c66,0x6a525f345374526a,0x090a3b5d5f536650,0x203233732e766f6d\n"
".quad 0x7225202c34722509,0x702e646c090a3b33,0x3233752e6d617261,0x5b202c3572250920\n"
".quad 0x6170616475635f5f,0x315a5f5f33666d72,0x6c6c416c61766539,0x746174756d726550\n"
".quad 0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452,0x6d090a3b5d5f5366\n"
".quad 0x09203233732e766f,0x357225202c367225,0x61702e646c090a3b,0x203233752e6d6172\n"
".quad 0x5f5b202c37722509,0x726170616475635f,0x39315a5f5f34666d,0x506c6c416c617665\n"
".quad 0x69746174756d7265,0x6c66364b50736e6f,0x526a4b503374616f,0x66506a525f345374\n"
".quad 0x6f6d090a3b5d5f53,0x2509203233732e76,0x3b377225202c3872,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c397225,0x6d72617061647563,0x6539315a5f5f3566\n"
".quad 0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e,0x74526a4b50337461\n"
".quad 0x5366506a525f3453,0x766f6d090a3b5d5f,0x722509203233732e,0x3b397225202c3031\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c31317225,0x726170616475635f\n"
".quad 0x39315a5f5f36666d,0x506c6c416c617665,0x69746174756d7265,0x6c66364b50736e6f\n"
".quad 0x526a4b503374616f,0x66506a525f345374,0x6f6d090a3b5d5f53,0x2509203233732e76\n"
".quad 0x317225202c323172,0x702e646c090a3b31,0x3233662e6d617261,0x5b202c3166250920\n"
".quad 0x6170616475635f5f,0x315a5f5f37666d72,0x6c6c416c61766539,0x746174756d726550\n"
".quad 0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452,0x0a3b5d302b5f5366\n"
".quad 0x3233662e766f6d09,0x25202c3266250920,0x2e646c090a3b3166,0x33662e6d61726170\n"
".quad 0x202c336625092032,0x70616475635f5f5b,0x5a5f5f37666d7261,0x6c416c6176653931\n"
".quad 0x6174756d7265506c,0x364b50736e6f6974,0x4b503374616f6c66,0x6a525f345374526a\n"
".quad 0x3b5d342b5f536650,0x33662e766f6d090a,0x202c346625092032,0x646c090a3b336625\n"
".quad 0x662e6d617261702e,0x2c35662509203233,0x616475635f5f5b20,0x5f5f37666d726170\n"
".quad 0x416c61766539315a,0x74756d7265506c6c,0x4b50736e6f697461,0x503374616f6c6636\n"
".quad 0x525f345374526a4b,0x5d382b5f5366506a,0x662e766f6d090a3b,0x2c36662509203233\n"
".quad 0x6d090a3b35662520,0x09203233732e766f,0x3b30202c33317225,0x33732e747663090a\n"
".quad 0x2509203233752e32,0x697425202c343172,0x6f6d090a3b782e64,0x2509203233662e76\n"
".quad 0x66376630202c3766,0x203b666666666637,0x202f2f0920202020,0x6532383230342e33\n"
".quad 0x747663090a38332b,0x6465726168732e61,0x722509203233752e,0x75635f5f202c3531\n"
".quad 0x6c61636f6c5f6164,0x3038335f7261765f,0x6f6e5f34335f3733,0x5f74736e6f635f6e\n"
".quad 0x74756d7265705f73,0x5f5f736e6f697461,0x2e766f6d090a3b32,0x3172250920323375\n"
".quad 0x73646f7270202c36,0x2e766f6d090a3b34,0x3172250920323375,0x6168706c61202c37\n"
".quad 0x0a3b34656c626154,0x37395f345f744c24,0x3c2f2f200a3a3033,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x35333320656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x6c2e090a3631203a\n"
".quad 0x343309373109636f,0x646461090a300935,0x722509203233732e,0x33317225202c3831\n"
".quad 0x0a3b34317225202c,0x3233752e766f6d09,0x202c393172250920,0x6573090a3b313939\n"
".quad 0x33732e74672e7074,0x202c317025092032,0x7225202c38317225,0x702540090a3b3931\n"
".quad 0x2409206172622031,0x3835325f345f744c,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35333320656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a303337395f345f,0x373109636f6c2e09,0x090a300938343309\n"
".quad 0x752e6f6c2e6c756d,0x3032722509203233,0x202c38317225202c,0x2e646461090a3b34\n"
".quad 0x3272250920323375,0x2c30327225202c31,0x6c090a3b34722520,0x2509203233752e64\n"
".quad 0x72255b202c323272,0x090a3b5d302b3132,0x203233752e766f6d,0x31202c3332722509\n"
".quad 0x746573090a3b3935,0x3233732e74672e70,0x25202c3270250920,0x327225202c383172\n"
".quad 0x32702540090a3b33,0x4c24092061726220,0x363839395f345f74,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35333320656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a303337395f345f,0x373109636f6c2e09\n"
".quad 0x090a300939343309,0x203233752e646461,0x25202c3432722509,0x317225202c303272\n"
".quad 0x752e7473090a3b35,0x3272255b09203233,0x7225202c5d302b34,0x5f744c240a3b3232\n"
".quad 0x0a3a363839395f34,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35333320,0x6c6562616c206461,0x345f744c24206465\n"
".quad 0x2e090a303337395f,0x3309373109636f6c,0x6f6d090a30093135,0x2509203233732e76\n"
".quad 0x0a3b30202c353272,0x3233732e766f6d09,0x202c363272250920,0x6f6d090a3b327225\n"
".quad 0x2509203233732e76,0x0a3b30202c373272,0x3233662e766f6d09,0x30202c3866250920\n"
".quad 0x3030303030303066,0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x30306630202c3966,0x203b303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3031662509203233,0x303030306630202c,0x2020203b30303030,0x240a30202f2f0920\n"
".quad 0x3031315f345f744c,0x3c2f2f200a3a3031,0x6f4c203e706f6f6c,0x2079646f6220706f\n"
".quad 0x31353320656e696c,0x6e697473656e202c,0x3a68747065642067,0x72657469202c3120\n"
".quad 0x203a736e6f697461,0x636f6c2e090a3631,0x0934323209373109,0x752e726873090a30\n"
".quad 0x3832722509203233,0x202c32327225202c,0x61090a3b35327225,0x09203233622e646e\n"
".quad 0x7225202c39327225,0x090a3b33202c3832,0x752e6f6c2e6c756d,0x3033722509203233\n"
".quad 0x202c39327225202c,0x2e646461090a3b34,0x3372250920323375,0x2c30337225202c31\n"
".quad 0x090a3b3731722520,0x74736e6f632e646c,0x662509203233662e,0x3372255b202c3131\n"
".quad 0x6c090a3b5d302b31,0x2509203233662e64,0x72255b202c323166,0x090a3b5d302b3632\n"
".quad 0x662e6e722e616d66,0x3031662509203233,0x202c32316625202c,0x6625202c31316625\n"
".quad 0x2e646c090a3b3031,0x3166250920323366,0x363272255b202c33,0x6d66090a3b5d342b\n"
".quad 0x3233662e6e722e61,0x25202c3966250920,0x316625202c333166,0x0a3b396625202c31\n"
".quad 0x203233662e646c09,0x5b202c3431662509,0x3b5d382b36327225,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x2c34316625202c38,0x25202c3131662520,0x6f6c2e090a3b3866\n"
".quad 0x3532320937310963,0x2e646461090a3009,0x3372250920323375,0x2c30337225202c32\n"
".quad 0x090a3b3631722520,0x74736e6f632e646c,0x722509203233732e,0x3372255b202c3333\n"
".quad 0x61090a3b5d302b32,0x09203233732e6464,0x7225202c37327225,0x37327225202c3333\n"
".quad 0x752e646461090a3b,0x3632722509203233,0x202c36327225202c,0x646461090a3b3231\n"
".quad 0x722509203233732e,0x35327225202c3532,0x6f6d090a3b32202c,0x2509203233752e76\n"
".quad 0x3b3233202c343372,0x6e2e70746573090a,0x2509203233732e65,0x35327225202c3370\n"
".quad 0x0a3b34337225202c,0x7262203370254009,0x345f744c24092061,0x0a3b30313031315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35333320,0x6c6562616c206461,0x345f744c24206465,0x2e090a303337395f\n"
".quad 0x3209373109636f6c,0x6e61090a30093336,0x2509203233622e64,0x327225202c353372\n"
".quad 0x0a3b353532202c37,0x3233732e72687309,0x202c363372250920,0x3631202c37327225\n"
".quad 0x732e726873090a3b,0x3733722509203233,0x202c37327225202c,0x2e766f6d090a3b38\n"
".quad 0x3166250920323366,0x3131346630202c35,0x20203b3030303030,0x0a39202f2f092020\n"
".quad 0x3233662e6c756d09,0x202c363166250920,0x316625202c326625,0x2e766f6d090a3b35\n"
".quad 0x3166250920323366,0x3131346630202c37,0x20203b3030303030,0x0a39202f2f092020\n"
".quad 0x3233662e6c756d09,0x202c383166250920,0x316625202c346625,0x2e766f6d090a3b37\n"
".quad 0x3166250920323366,0x3131346630202c39,0x20203b3030303030,0x0a39202f2f092020\n"
".quad 0x3233662e6c756d09,0x202c303266250920,0x316625202c366625,0x2e747663090a3b39\n"
".quad 0x732e3233662e6e72,0x3132662509203233,0x0a3b35337225202c,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x25202c3232662509,0x6e61090a3b363372,0x2509203233622e64\n"
".quad 0x337225202c383372,0x0a3b353532202c37,0x3233662e62757309,0x202c333266250920\n"
".quad 0x6625202c36316625,0x627573090a3b3031,0x662509203233662e,0x38316625202c3432\n"
".quad 0x090a3b396625202c,0x203233662e627573,0x25202c3532662509,0x386625202c303266\n"
".quad 0x662e6c756d090a3b,0x3632662509203233,0x202c31326625202c,0x63090a3b31326625\n"
".quad 0x33662e6e722e7476,0x2509203233732e32,0x337225202c373266,0x2e6c756d090a3b38\n"
".quad 0x3266250920323366,0x2c31326625202c38,0x090a3b3332662520,0x203233662e6c756d\n"
".quad 0x25202c3932662509,0x326625202c313266,0x2e6c756d090a3b34,0x3366250920323366\n"
".quad 0x2c31326625202c30,0x090a3b3532662520,0x203233662e6c756d,0x25202c3133662509\n"
".quad 0x326625202c323266,0x2e627573090a3b37,0x3366250920323366,0x2c31336625202c32\n"
".quad 0x090a3b3632662520,0x203233662e6c756d,0x25202c3333662509,0x316625202c373266\n"
".quad 0x2e6c756d090a3b30,0x3366250920323366,0x2c37326625202c34,0x6d090a3b39662520\n"
".quad 0x09203233662e6c75,0x6625202c35336625,0x3b386625202c3732,0x6e722e706372090a\n"
".quad 0x662509203233662e,0x32336625202c3633,0x662e627573090a3b,0x3733662509203233\n"
".quad 0x202c33336625202c,0x73090a3b38326625,0x09203233662e6275,0x6625202c38336625\n"
".quad 0x39326625202c3433,0x662e627573090a3b,0x3933662509203233,0x202c35336625202c\n"
".quad 0x6d090a3b30336625,0x09203233662e6c75,0x6625202c30346625,0x37336625202c3633\n"
".quad 0x662e6c756d090a3b,0x3134662509203233,0x202c36336625202c,0x6d090a3b38336625\n"
".quad 0x09203233662e6c75,0x6625202c32346625,0x39336625202c3633,0x732e747663090a3b\n"
".quad 0x662e3233662e7461,0x3334662509203233,0x0a3b30346625202c,0x7461732e74766309\n"
".quad 0x3233662e3233662e,0x202c343466250920,0x63090a3b31346625,0x662e7461732e7476\n"
".quad 0x09203233662e3233,0x6625202c35346625,0x766f6d090a3b3234,0x662509203233662e\n"
".quad 0x31346630202c3634,0x203b303030303866,0x33202f2f09202020,0x662e6c756d090a31\n"
".quad 0x3734662509203233,0x202c33346625202c,0x6d090a3b36346625,0x09203233662e766f\n"
".quad 0x6630202c38346625,0x3030303063373234,0x2f2f09202020203b,0x6c756d090a333620\n"
".quad 0x662509203233662e,0x34346625202c3934,0x0a3b38346625202c,0x3233662e766f6d09\n"
".quad 0x202c303566250920,0x3030386631346630,0x09202020203b3030,0x6d090a3133202f2f\n"
".quad 0x09203233662e6c75,0x6625202c31356625,0x30356625202c3534,0x722e747663090a3b\n"
".quad 0x662e3233662e696e,0x3235662509203233,0x0a3b37346625202c,0x696e722e74766309\n"
".quad 0x3233662e3233662e,0x202c333566250920,0x63090a3b39346625,0x662e696e722e7476\n"
".quad 0x09203233662e3233,0x6625202c34356625,0x747663090a3b3135,0x3233752e697a722e\n"
".quad 0x722509203233662e,0x32356625202c3933,0x622e6c6873090a3b,0x3034722509203233\n"
".quad 0x202c39337225202c,0x747663090a3b3131,0x3233752e697a722e,0x722509203233662e\n"
".quad 0x33356625202c3134,0x622e6c6873090a3b,0x3234722509203233,0x202c31347225202c\n"
".quad 0x622e726f090a3b35,0x3334722509203233,0x202c30347225202c,0x63090a3b32347225\n"
".quad 0x752e697a722e7476,0x09203233662e3233,0x6625202c34347225,0x2e726f090a3b3435\n"
".quad 0x3472250920323362,0x2c33347225202c35,0x090a3b3434722520,0x09373109636f6c2e\n"
".quad 0x6d090a3009343632,0x09203233662e6c75,0x6625202c35356625,0x30316625202c3132\n"
".quad 0x662e6c756d090a3b,0x3635662509203233,0x202c31326625202c,0x756d090a3b396625\n"
".quad 0x2509203233662e6c,0x326625202c373566,0x0a3b386625202c31,0x3233662e6c756d09\n"
".quad 0x202c383566250920,0x6625202c32326625,0x6c756d090a3b3332,0x662509203233662e\n"
".quad 0x32326625202c3935,0x0a3b34326625202c,0x3233662e6c756d09,0x202c303666250920\n"
".quad 0x6625202c32326625,0x627573090a3b3532,0x662509203233662e,0x38356625202c3136\n"
".quad 0x0a3b35356625202c,0x3233662e62757309,0x202c323666250920,0x6625202c39356625\n"
".quad 0x627573090a3b3635,0x662509203233662e,0x30366625202c3336,0x0a3b37356625202c\n"
".quad 0x3233662e6c756d09,0x202c343666250920,0x6625202c31366625,0x6c756d090a3b3633\n"
".quad 0x662509203233662e,0x32366625202c3536,0x0a3b36336625202c,0x3233662e6c756d09\n"
".quad 0x202c363666250920,0x6625202c33366625,0x747663090a3b3633,0x3233662e7461732e\n"
".quad 0x662509203233662e,0x34366625202c3736,0x732e747663090a3b,0x662e3233662e7461\n"
".quad 0x3836662509203233,0x0a3b35366625202c,0x7461732e74766309,0x3233662e3233662e\n"
".quad 0x202c393666250920,0x6d090a3b36366625,0x09203233662e766f,0x6630202c30376625\n"
".quad 0x3030303038663134,0x2f2f09202020203b,0x6c756d090a313320,0x662509203233662e\n"
".quad 0x37366625202c3137,0x0a3b30376625202c,0x3233662e766f6d09,0x202c323766250920\n"
".quad 0x3030633732346630,0x09202020203b3030,0x6d090a3336202f2f,0x09203233662e6c75\n"
".quad 0x6625202c33376625,0x32376625202c3836,0x662e766f6d090a3b,0x3437662509203233\n"
".quad 0x386631346630202c,0x2020203b30303030,0x0a3133202f2f0920,0x3233662e6c756d09\n"
".quad 0x202c353766250920,0x6625202c39366625,0x747663090a3b3437,0x3233662e696e722e\n"
".quad 0x662509203233662e,0x31376625202c3637,0x722e747663090a3b,0x662e3233662e696e\n"
".quad 0x3737662509203233,0x0a3b33376625202c,0x696e722e74766309,0x3233662e3233662e\n"
".quad 0x202c383766250920,0x63090a3b35376625,0x752e697a722e7476,0x09203233662e3233\n"
".quad 0x6625202c36347225,0x6c6873090a3b3637,0x722509203233622e,0x36347225202c3734\n"
".quad 0x63090a3b3131202c,0x752e697a722e7476,0x09203233662e3233,0x6625202c38347225\n"
".quad 0x6c6873090a3b3737,0x722509203233622e,0x38347225202c3934,0x726f090a3b35202c\n"
".quad 0x722509203233622e,0x37347225202c3035,0x0a3b39347225202c,0x697a722e74766309\n"
".quad 0x3233662e3233752e,0x202c313572250920,0x6f090a3b38376625,0x2509203233622e72\n"
".quad 0x357225202c323572,0x3b31357225202c30,0x3109636f6c2e090a,0x0a30093736320937\n"
".quad 0x3233662e766f6d09,0x202c393766250920,0x3533343064336630,0x09202020203b3137\n"
".quad 0x3233302e30202f2f,0x756d090a35373732,0x2509203233662e6c,0x356625202c303866\n"
".quad 0x3b39376625202c32,0x33662e6c756d090a,0x2c31386625092032,0x25202c3038662520\n"
".quad 0x6f6d090a3b303866,0x2509203233662e76,0x336630202c323866,0x3b39313162313863\n"
".quad 0x202f2f0920202020,0x3133383531302e30,0x662e6c756d090a35,0x3338662509203233\n"
".quad 0x202c33356625202c,0x6d090a3b32386625,0x09203233662e6c75,0x6625202c34386625\n"
".quad 0x33386625202c3338,0x662e766f6d090a3b,0x3538662509203233,0x343064336630202c\n"
".quad 0x2020203b31373533,0x302e30202f2f0920,0x090a353737323233,0x203233662e6c756d\n"
".quad 0x25202c3638662509,0x386625202c343566,0x2e6c756d090a3b35,0x3866250920323366\n"
".quad 0x2c36386625202c37,0x090a3b3638662520,0x203233662e766f6d,0x30202c3838662509\n"
".quad 0x3735333430643366,0x2f09202020203b31,0x323233302e30202f,0x6c756d090a353737\n"
".quad 0x662509203233662e,0x36376625202c3938,0x0a3b38386625202c,0x3233662e6c756d09\n"
".quad 0x202c303966250920,0x6625202c39386625,0x766f6d090a3b3938,0x662509203233662e\n"
".quad 0x63336630202c3139,0x203b393131623138,0x30202f2f09202020,0x353133383531302e\n"
".quad 0x33662e6c756d090a,0x2c32396625092032,0x25202c3737662520,0x756d090a3b313966\n"
".quad 0x2509203233662e6c,0x396625202c333966,0x3b32396625202c32,0x33662e766f6d090a\n"
".quad 0x2c34396625092032,0x3334306433663020,0x202020203b313735,0x33302e30202f2f09\n"
".quad 0x6d090a3537373232,0x09203233662e6c75,0x6625202c35396625,0x34396625202c3837\n"
".quad 0x662e6c756d090a3b,0x3639662509203233,0x202c35396625202c,0x6d090a3b35396625\n"
".quad 0x09203233662e6c75,0x6625202c37396625,0x30386625202c3938,0x662e6c756d090a3b\n"
".quad 0x3839662509203233,0x202c32396625202c,0x6d090a3b33386625,0x09203233662e6c75\n"
".quad 0x6625202c39396625,0x36386625202c3539,0x662e6c756d090a3b,0x3031662509203233\n"
".quad 0x2c30386625202c30,0x090a3b3031662520,0x203233662e6c756d,0x202c313031662509\n"
".quad 0x6625202c33386625,0x2e6c756d090a3b39,0x3166250920323366,0x36386625202c3230\n"
".quad 0x090a3b386625202c,0x203233662e6c756d,0x202c333031662509,0x6625202c33326625\n"
".quad 0x6c756d090a3b3938,0x662509203233662e,0x326625202c343031,0x3b32396625202c34\n"
".quad 0x33662e6c756d090a,0x3530316625092032,0x202c35326625202c,0x2e090a3b35396625\n"
".quad 0x3309373109636f6c,0x756d090a30093135,0x2509203233662e6c,0x6625202c36303166\n"
".quad 0x38396625202c3132,0x662e6c756d090a3b,0x3031662509203233,0x2c31326625202c37\n"
".quad 0x090a3b3739662520,0x203233662e6c756d,0x202c383031662509,0x6625202c31326625\n"
".quad 0x6c756d090a3b3939,0x662509203233662e,0x326625202c393031,0x3b34386625202c32\n"
".quad 0x33662e6c756d090a,0x3031316625092032,0x202c32326625202c,0x6d090a3b31386625\n"
".quad 0x09203233662e6c75,0x25202c3131316625,0x386625202c323266,0x2e627573090a3b37\n"
".quad 0x3166250920323366,0x30316625202c3231,0x3130316625202c36,0x662e627573090a3b\n"
".quad 0x3131662509203233,0x3730316625202c33,0x3b3030316625202c,0x33662e627573090a\n"
".quad 0x3431316625092032,0x2c3830316625202c,0x0a3b323031662520,0x3233662e6c756d09\n"
".quad 0x2c35313166250920,0x25202c3732662520,0x756d090a3b333966,0x2509203233662e6c\n"
".quad 0x6625202c36313166,0x30396625202c3732,0x662e6c756d090a3b,0x3131662509203233\n"
".quad 0x2c37326625202c37,0x090a3b3639662520,0x203233662e627573,0x202c383131662509\n"
".quad 0x25202c3231316625,0x73090a3b34303166,0x09203233662e6275,0x25202c3931316625\n"
".quad 0x6625202c33313166,0x7573090a3b333031,0x2509203233662e62,0x6625202c30323166\n"
".quad 0x316625202c343131,0x646461090a3b3530,0x662509203233662e,0x316625202c313231\n"
".quad 0x31316625202c3930,0x2e646461090a3b35,0x3166250920323366,0x31316625202c3232\n"
".quad 0x3631316625202c30,0x662e646461090a3b,0x3231662509203233,0x3131316625202c33\n"
".quad 0x3b3731316625202c,0x33662e646461090a,0x3432316625092032,0x2c3831316625202c\n"
".quad 0x0a3b383131662520,0x3233662e64646109,0x2c35323166250920,0x202c393131662520\n"
".quad 0x090a3b3931316625,0x203233662e646461,0x202c363231662509,0x25202c3032316625\n"
".quad 0x61090a3b30323166,0x09203233662e6464,0x25202c3732316625,0x6625202c31323166\n"
".quad 0x6461090a3b343231,0x2509203233662e64,0x6625202c38323166,0x316625202c323231\n"
".quad 0x646461090a3b3532,0x662509203233662e,0x316625202c393231,0x32316625202c3332\n"
".quad 0x632e646c090a3b36,0x3233662e74736e6f,0x2c30333166250920,0x726f6c6f436b5b20\n"
".quad 0x342b63697274654d,0x2e6c756d090a3b5d,0x3166250920323366,0x33316625202c3133\n"
".quad 0x3732316625202c30,0x6f632e646c090a3b,0x203233662e74736e,0x202c323331662509\n"
".quad 0x4d726f6c6f436b5b,0x5d302b6369727465,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c33333166,0x316625202c383231,0x33316625202c3233,0x632e646c090a3b31\n"
".quad 0x3233662e74736e6f,0x2c34333166250920,0x726f6c6f436b5b20,0x382b63697274654d\n"
".quad 0x2e616d66090a3b5d,0x09203233662e6e72,0x25202c3533316625,0x6625202c39323166\n"
".quad 0x316625202c343331,0x766f6d090a3b3333,0x662509203233662e,0x336630202c363331\n"
".quad 0x3b39336538336564,0x30202f2f09202020,0x0a3131313131312e,0x3233662e6c756d09\n"
".quad 0x2c37333166250920,0x202c353331662520,0x090a3b3633316625,0x2e746c2e70746573\n"
".quad 0x3470250920323366,0x2c3733316625202c,0x40090a3b37662520,0x6172622034702521\n"
".quad 0x5f345f744c240920,0x200a3b3232353131,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353333,0x656c6562616c2064\n"
".quad 0x5f345f744c242064,0x6c2e090a30333739,0x353309373109636f,0x766f6d090a300935\n"
".quad 0x662509203233662e,0x3733316625202c37,0x09636f6c2e090a3b,0x3009363533093731\n"
".quad 0x3233752e7473090a,0x2b303172255b0920,0x32327225202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009373533093731,0x3631752e7473090a,0x302b3672255b0920,0x3b35347225202c5d\n"
".quad 0x3109636f6c2e090a,0x0a30093835330937,0x203631752e747309,0x5d302b3872255b09\n"
".quad 0x0a3b32357225202c,0x31315f345f744c24,0x2f2f200a3a323235,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x333320656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x37395f345f744c24,0x636f6c2e090a3033,0x0932343309373109\n"
".quad 0x732e646461090a30,0x3331722509203233,0x202c33317225202c,0x766f6d090a3b3436\n"
".quad 0x722509203233752e,0x34323031202c3335,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x317225202c357025,0x3b33357225202c33,0x622035702540090a,0x5f744c2409206172\n"
".quad 0x0a3b303337395f34,0x35325f345f744c24,0x636f6c2e090a3a38,0x0930363309373109\n"
".quad 0x31752e646c090a30,0x2c34357225092036,0x5d302b3672255b20,0x31752e646c090a3b\n"
".quad 0x2c35357225092036,0x5d302b3872255b20,0x2e70746573090a3b,0x09203233752e6567\n"
".quad 0x357225202c367025,0x3b35357225202c34,0x622036702540090a,0x5f744c2409206172\n"
".quad 0x3b30393232315f34,0x3109636f6c2e090a,0x090a300932370937,0x203233732e766f6d\n"
".quad 0x25202c3635722509,0x6c2e090a3b353572,0x333709373109636f,0x752e7473090a3009\n"
".quad 0x3872255b09203631,0x357225202c5d302b,0x636f6c2e090a3b34,0x3009343709373109\n"
".quad 0x3631752e7473090a,0x302b3672255b0920,0x3b36357225202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093536330937,0x203233752e646c09,0x5b202c3735722509,0x3b5d302b30317225\n"
".quad 0x33622e726f78090a,0x2c38357225092032,0x31202c3735722520,0x3637353536313334\n"
".quad 0x752e7473090a3b35,0x3172255b09203233,0x7225202c5d302b30,0x5f744c240a3b3835\n"
".quad 0x3a30393232315f34,0x33732e766f6d090a,0x2c39357225092032,0x766f6d090a3b3020\n"
".quad 0x722509203233752e,0x646f7270202c3036,0x766f6d090a3b3373,0x722509203233752e\n"
".quad 0x68706c61202c3136,0x3b33656c62615461,0x315f345f744c240a,0x2f200a3a34313333\n"
".quad 0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3320656e696c2079,0x7473656e202c3536\n"
".quad 0x7470656420676e69,0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469\n"
".quad 0x2e090a33203a736e,0x3309373109636f6c,0x756d090a30093137,0x3233732e6f6c2e6c\n"
".quad 0x202c323672250920,0x3436202c39357225,0x732e646461090a3b,0x3336722509203233\n"
".quad 0x202c32367225202c,0x6d090a3b34317225,0x09203233752e766f,0x3531202c34367225\n"
".quad 0x70746573090a3b39,0x203233732e74672e,0x7225202c37702509,0x34367225202c3336\n"
".quad 0x2037702540090a3b,0x444c240920617262,0x69725f69646e6557,0x5f3338315f66746e\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35363320656e69,0x616c206461656820,0x4c242064656c6562,0x313333315f345f74\n"
".quad 0x09636f6c2e090a34,0x3009343733093731,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x33367225202c3536,0x6461090a3b34202c,0x2509203233752e64,0x317225202c363672\n"
".quad 0x3b35367225202c35,0x3233752e646c090a,0x202c373672250920,0x5d302b363672255b\n"
".quad 0x09636f6c2e090a3b,0x3009353733093731,0x33732e766f6d090a,0x2c38367225092032\n"
".quad 0x766f6d090a3b3020,0x722509203233732e,0x3b327225202c3936,0x33732e766f6d090a\n"
".quad 0x2c30377225092032,0x766f6d090a3b3020,0x662509203233662e,0x306630202c383331\n"
".quad 0x3b30303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x3933316625092032\n"
".quad 0x303030306630202c,0x2020203b30303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x30202c3034316625,0x3030303030303066,0x2f2f092020203b30,0x345f744c240a3020\n"
".quad 0x0a3a32383034315f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x656e202c35373320,0x656420676e697473,0x202c31203a687470,0x6f69746172657469\n"
".quad 0x090a3631203a736e,0x09373109636f6c2e,0x73090a3009353832,0x09203233752e7268\n"
".quad 0x7225202c31377225,0x38367225202c3736,0x622e646e61090a3b,0x3237722509203233\n"
".quad 0x202c31377225202c,0x2e6c756d090a3b33,0x09203233752e6f6c,0x7225202c33377225\n"
".quad 0x090a3b34202c3237,0x203233752e646461,0x25202c3437722509,0x367225202c333772\n"
".quad 0x632e646c090a3b31,0x3233662e74736e6f,0x2c31343166250920,0x302b343772255b20\n"
".quad 0x662e646c090a3b5d,0x3431662509203233,0x393672255b202c32,0x6d66090a3b5d302b\n"
".quad 0x3233662e6e722e61,0x2c30343166250920,0x202c323431662520,0x25202c3134316625\n"
".quad 0x6c090a3b30343166,0x2509203233662e64,0x255b202c33343166,0x0a3b5d342b393672\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x34316625202c3933,0x3134316625202c33\n"
".quad 0x3b3933316625202c,0x3233662e646c090a,0x2c34343166250920,0x382b393672255b20\n"
".quad 0x2e616d66090a3b5d,0x09203233662e6e72,0x25202c3833316625,0x6625202c34343166\n"
".quad 0x316625202c313431,0x6f6c2e090a3b3833,0x3638320937310963,0x2e646461090a3009\n"
".quad 0x3772250920323375,0x2c33377225202c35,0x090a3b3036722520,0x74736e6f632e646c\n"
".quad 0x722509203233732e,0x3772255b202c3637,0x61090a3b5d302b35,0x09203233732e6464\n"
".quad 0x7225202c30377225,0x30377225202c3637,0x752e646461090a3b,0x3936722509203233\n"
".quad 0x202c39367225202c,0x646461090a3b3231,0x722509203233732e,0x38367225202c3836\n"
".quad 0x6f6d090a3b32202c,0x2509203233752e76,0x3b3233202c373772,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x38367225202c3870,0x0a3b37377225202c,0x7262203870254009\n"
".quad 0x345f744c24092061,0x0a3b32383034315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35363320,0x6c6562616c206461\n"
".quad 0x345f744c24206465,0x090a34313333315f,0x09373109636f6c2e,0x61090a3009333233\n"
".quad 0x09203233622e646e,0x7225202c38377225,0x3b353532202c3037,0x33732e726873090a\n"
".quad 0x2c39377225092032,0x31202c3037722520,0x2e726873090a3b36,0x3872250920323373\n"
".quad 0x2c30377225202c30,0x766f6d090a3b3820,0x662509203233662e,0x346630202c353431\n"
".quad 0x3b30303030303830,0x34202f2f09202020,0x33662e6c756d090a,0x3634316625092032\n"
".quad 0x25202c326625202c,0x6d090a3b35343166,0x09203233662e766f,0x30202c3734316625\n"
".quad 0x3030303038303466,0x2f2f092020203b30,0x2e6c756d090a3420,0x3166250920323366\n"
".quad 0x2c346625202c3834,0x0a3b373431662520,0x3233662e766f6d09,0x2c39343166250920\n"
".quad 0x3030383034663020,0x092020203b303030,0x756d090a34202f2f,0x2509203233662e6c\n"
".quad 0x6625202c30353166,0x3934316625202c36,0x722e747663090a3b,0x33732e3233662e6e\n"
".quad 0x3135316625092032,0x0a3b38377225202c,0x2e6e722e74766309,0x203233732e323366\n"
".quad 0x202c323531662509,0x61090a3b39377225,0x09203233622e646e,0x7225202c31387225\n"
".quad 0x3b353532202c3038,0x33662e627573090a,0x3335316625092032,0x2c3634316625202c\n"
".quad 0x0a3b303431662520,0x3233662e62757309,0x2c34353166250920,0x202c383431662520\n"
".quad 0x090a3b3933316625,0x203233662e627573,0x202c353531662509,0x25202c3035316625\n"
".quad 0x6d090a3b38333166,0x09203233662e6c75,0x25202c3635316625,0x6625202c31353166\n"
".quad 0x7663090a3b313531,0x3233662e6e722e74,0x662509203233732e,0x387225202c373531\n"
".quad 0x2e6c756d090a3b31,0x3166250920323366,0x35316625202c3835,0x3335316625202c31\n"
".quad 0x662e6c756d090a3b,0x3531662509203233,0x3135316625202c39,0x3b3435316625202c\n"
".quad 0x33662e6c756d090a,0x3036316625092032,0x2c3135316625202c,0x0a3b353531662520\n"
".quad 0x3233662e6c756d09,0x2c31363166250920,0x202c323531662520,0x090a3b3735316625\n"
".quad 0x203233662e627573,0x202c323631662509,0x25202c3136316625,0x6d090a3b36353166\n"
".quad 0x09203233662e6c75,0x25202c3336316625,0x6625202c37353166,0x756d090a3b303431\n"
".quad 0x2509203233662e6c,0x6625202c34363166,0x316625202c373531,0x6c756d090a3b3933\n"
".quad 0x662509203233662e,0x316625202c353631,0x33316625202c3735,0x2e706372090a3b38\n"
".quad 0x09203233662e6e72,0x25202c3636316625,0x73090a3b32363166,0x09203233662e6275\n"
".quad 0x25202c3736316625,0x6625202c33363166,0x7573090a3b383531,0x2509203233662e62\n"
".quad 0x6625202c38363166,0x316625202c343631,0x627573090a3b3935,0x662509203233662e\n"
".quad 0x316625202c393631,0x36316625202c3536,0x2e6c756d090a3b30,0x3166250920323366\n"
".quad 0x36316625202c3037,0x3736316625202c36,0x662e6c756d090a3b,0x3731662509203233\n"
".quad 0x3636316625202c31,0x3b3836316625202c,0x33662e6c756d090a,0x3237316625092032\n"
".quad 0x2c3636316625202c,0x0a3b393631662520,0x7461732e74766309,0x3233662e3233662e\n"
".quad 0x2c33373166250920,0x0a3b303731662520,0x7461732e74766309,0x3233662e3233662e\n"
".quad 0x2c34373166250920,0x0a3b313731662520,0x7461732e74766309,0x3233662e3233662e\n"
".quad 0x2c35373166250920,0x0a3b323731662520,0x3233662e766f6d09,0x2c36373166250920\n"
".quad 0x3038663134663020,0x092020203b303030,0x6d090a3133202f2f,0x09203233662e6c75\n"
".quad 0x25202c3737316625,0x6625202c33373166,0x6f6d090a3b363731,0x2509203233662e76\n"
".quad 0x6630202c38373166,0x3030303063373234,0x202f2f092020203b,0x2e6c756d090a3336\n"
".quad 0x3166250920323366,0x37316625202c3937,0x3837316625202c34,0x662e766f6d090a3b\n"
".quad 0x3831662509203233,0x6631346630202c30,0x20203b3030303038,0x0a3133202f2f0920\n"
".quad 0x3233662e6c756d09,0x2c31383166250920,0x202c353731662520,0x090a3b3038316625\n"
".quad 0x2e696e722e747663,0x203233662e323366,0x202c323831662509,0x090a3b3737316625\n"
".quad 0x2e696e722e747663,0x203233662e323366,0x202c333831662509,0x090a3b3937316625\n"
".quad 0x2e696e722e747663,0x203233662e323366,0x202c343831662509,0x090a3b3138316625\n"
".quad 0x2e697a722e747663,0x203233662e323375,0x25202c3238722509,0x73090a3b32383166\n"
".quad 0x09203233622e6c68,0x7225202c33387225,0x0a3b3131202c3238,0x697a722e74766309\n"
".quad 0x3233662e3233752e,0x202c343872250920,0x090a3b3338316625,0x203233622e6c6873\n"
".quad 0x25202c3538722509,0x0a3b35202c343872,0x203233622e726f09,0x25202c3638722509\n"
".quad 0x387225202c333872,0x2e747663090a3b35,0x2e3233752e697a72,0x3872250920323366\n"
".quad 0x3438316625202c37,0x33622e726f090a3b,0x2c38387225092032,0x25202c3638722520\n"
".quad 0x6c2e090a3b373872,0x323309373109636f,0x6c756d090a300934,0x662509203233662e\n"
".quad 0x316625202c353831,0x34316625202c3135,0x2e6c756d090a3b30,0x3166250920323366\n"
".quad 0x35316625202c3638,0x3933316625202c31,0x662e6c756d090a3b,0x3831662509203233\n"
".quad 0x3135316625202c37,0x3b3833316625202c,0x33662e6c756d090a,0x3838316625092032\n"
".quad 0x2c3235316625202c,0x0a3b333531662520,0x3233662e6c756d09,0x2c39383166250920\n"
".quad 0x202c323531662520,0x090a3b3435316625,0x203233662e6c756d,0x202c303931662509\n"
".quad 0x25202c3235316625,0x73090a3b35353166,0x09203233662e6275,0x25202c3139316625\n"
".quad 0x6625202c38383166,0x7573090a3b353831,0x2509203233662e62,0x6625202c32393166\n"
".quad 0x316625202c393831,0x627573090a3b3638,0x662509203233662e,0x316625202c333931\n"
".quad 0x38316625202c3039,0x2e6c756d090a3b37,0x3166250920323366,0x39316625202c3439\n"
".quad 0x3636316625202c31,0x662e6c756d090a3b,0x3931662509203233,0x3239316625202c35\n"
".quad 0x3b3636316625202c,0x33662e6c756d090a,0x3639316625092032,0x2c3339316625202c\n"
".quad 0x0a3b363631662520,0x7461732e74766309,0x3233662e3233662e,0x2c37393166250920\n"
".quad 0x0a3b343931662520,0x7461732e74766309,0x3233662e3233662e,0x2c38393166250920\n"
".quad 0x0a3b353931662520,0x7461732e74766309,0x3233662e3233662e,0x2c39393166250920\n"
".quad 0x0a3b363931662520,0x3233662e766f6d09,0x2c30303266250920,0x3038663134663020\n"
".quad 0x092020203b303030,0x6d090a3133202f2f,0x09203233662e6c75,0x25202c3130326625\n"
".quad 0x6625202c37393166,0x6f6d090a3b303032,0x2509203233662e76,0x6630202c32303266\n"
".quad 0x3030303063373234,0x202f2f092020203b,0x2e6c756d090a3336,0x3266250920323366\n"
".quad 0x39316625202c3330,0x3230326625202c38,0x662e766f6d090a3b,0x3032662509203233\n"
".quad 0x6631346630202c34,0x20203b3030303038,0x0a3133202f2f0920,0x3233662e6c756d09\n"
".quad 0x2c35303266250920,0x202c393931662520,0x090a3b3430326625,0x2e696e722e747663\n"
".quad 0x203233662e323366,0x202c363032662509,0x090a3b3130326625,0x2e696e722e747663\n"
".quad 0x203233662e323366,0x202c373032662509,0x090a3b3330326625,0x2e696e722e747663\n"
".quad 0x203233662e323366,0x202c383032662509,0x090a3b3530326625,0x2e697a722e747663\n"
".quad 0x203233662e323375,0x25202c3938722509,0x73090a3b36303266,0x09203233622e6c68\n"
".quad 0x7225202c30397225,0x0a3b3131202c3938,0x697a722e74766309,0x3233662e3233752e\n"
".quad 0x202c313972250920,0x090a3b3730326625,0x203233622e6c6873,0x25202c3239722509\n"
".quad 0x0a3b35202c313972,0x203233622e726f09,0x25202c3339722509,0x397225202c303972\n"
".quad 0x2e747663090a3b32,0x2e3233752e697a72,0x3972250920323366,0x3830326625202c34\n"
".quad 0x33622e726f090a3b,0x2c35397225092032,0x25202c3339722520,0x7663090a3b343972\n"
".quad 0x33752e3631752e74,0x2c36397225092032,0x090a3b3539722520,0x09373109636f6c2e\n"
".quad 0x6d090a3009373233,0x09203233662e766f,0x30202c3930326625,0x3735333430643366\n"
".quad 0x2f2f092020203b31,0x37323233302e3020,0x2e6c756d090a3537,0x3266250920323366\n"
".quad 0x38316625202c3031,0x3930326625202c32,0x662e6c756d090a3b,0x3132662509203233\n"
".quad 0x3031326625202c31,0x3b3031326625202c,0x33662e766f6d090a,0x3231326625092032\n"
".quad 0x313863336630202c,0x2020203b39313162,0x31302e30202f2f09,0x6d090a3531333835\n"
".quad 0x09203233662e6c75,0x25202c3331326625,0x6625202c33383166,0x756d090a3b323132\n"
".quad 0x2509203233662e6c,0x6625202c34313266,0x326625202c333132,0x766f6d090a3b3331\n"
".quad 0x662509203233662e,0x336630202c353132,0x3b31373533343064,0x30202f2f09202020\n"
".quad 0x353737323233302e,0x33662e6c756d090a,0x3631326625092032,0x2c3438316625202c\n"
".quad 0x0a3b353132662520,0x3233662e6c756d09,0x2c37313266250920,0x202c363132662520\n"
".quad 0x090a3b3631326625,0x203233662e766f6d,0x202c383132662509,0x3533343064336630\n"
".quad 0x2f092020203b3137,0x323233302e30202f,0x6c756d090a353737,0x662509203233662e\n"
".quad 0x326625202c393132,0x31326625202c3630,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x31326625202c3032,0x3931326625202c39,0x662e766f6d090a3b,0x3232662509203233\n"
".quad 0x3863336630202c31,0x20203b3931316231,0x302e30202f2f0920,0x090a353133383531\n"
".quad 0x203233662e6c756d,0x202c323232662509,0x25202c3730326625,0x6d090a3b31323266\n"
".quad 0x09203233662e6c75,0x25202c3332326625,0x6625202c32323266,0x6f6d090a3b323232\n"
".quad 0x2509203233662e76,0x6630202c34323266,0x3137353334306433,0x202f2f092020203b\n"
".quad 0x3737323233302e30,0x662e6c756d090a35,0x3232662509203233,0x3830326625202c35\n"
".quad 0x3b3432326625202c,0x33662e6c756d090a,0x3632326625092032,0x2c3532326625202c\n"
".quad 0x0a3b353232662520,0x3233662e6c756d09,0x2c37323266250920,0x202c393132662520\n"
".quad 0x090a3b3031326625,0x203233662e6c756d,0x202c383232662509,0x25202c3232326625\n"
".quad 0x6d090a3b33313266,0x09203233662e6c75,0x25202c3932326625,0x6625202c35323266\n"
".quad 0x756d090a3b363132,0x2509203233662e6c,0x6625202c30333266,0x316625202c303132\n"
".quad 0x6c756d090a3b3034,0x662509203233662e,0x326625202c313332,0x33316625202c3331\n"
".quad 0x2e6c756d090a3b39,0x3266250920323366,0x31326625202c3233,0x3833316625202c36\n"
".quad 0x662e6c756d090a3b,0x3332662509203233,0x3335316625202c33,0x3b3931326625202c\n"
".quad 0x33662e6c756d090a,0x3433326625092032,0x2c3435316625202c,0x0a3b323232662520\n"
".quad 0x3233662e6c756d09,0x2c35333266250920,0x202c353531662520,0x090a3b3532326625\n"
".quad 0x09373109636f6c2e,0x6d090a3009353733,0x09203233662e6c75,0x25202c3633326625\n"
".quad 0x6625202c31353166,0x756d090a3b383232,0x2509203233662e6c,0x6625202c37333266\n"
".quad 0x326625202c313531,0x6c756d090a3b3732,0x662509203233662e,0x316625202c383332\n"
".quad 0x32326625202c3135,0x2e6c756d090a3b39,0x3266250920323366,0x35316625202c3933\n"
".quad 0x3431326625202c32,0x662e6c756d090a3b,0x3432662509203233,0x3235316625202c30\n"
".quad 0x3b3131326625202c,0x33662e6c756d090a,0x3134326625092032,0x2c3235316625202c\n"
".quad 0x0a3b373132662520,0x3233662e62757309,0x2c32343266250920,0x202c363332662520\n"
".quad 0x090a3b3133326625,0x203233662e627573,0x202c333432662509,0x25202c3733326625\n"
".quad 0x73090a3b30333266,0x09203233662e6275,0x25202c3434326625,0x6625202c38333266\n"
".quad 0x756d090a3b323332,0x2509203233662e6c,0x6625202c35343266,0x326625202c373531\n"
".quad 0x6c756d090a3b3332,0x662509203233662e,0x316625202c363432,0x32326625202c3735\n"
".quad 0x2e6c756d090a3b30,0x3266250920323366,0x35316625202c3734,0x3632326625202c37\n"
".quad 0x662e627573090a3b,0x3432662509203233,0x3234326625202c38,0x3b3433326625202c\n"
".quad 0x33662e627573090a,0x3934326625092032,0x2c3334326625202c,0x0a3b333332662520\n"
".quad 0x3233662e62757309,0x2c30353266250920,0x202c343432662520,0x090a3b3533326625\n"
".quad 0x203233662e646461,0x202c313532662509,0x25202c3933326625,0x61090a3b35343266\n"
".quad 0x09203233662e6464,0x25202c3235326625,0x6625202c30343266,0x6461090a3b363432\n"
".quad 0x2509203233662e64,0x6625202c33353266,0x326625202c313432,0x646461090a3b3734\n"
".quad 0x662509203233662e,0x326625202c343532,0x34326625202c3834,0x2e646461090a3b38\n"
".quad 0x3266250920323366,0x34326625202c3535,0x3934326625202c39,0x662e646461090a3b\n"
".quad 0x3532662509203233,0x3035326625202c36,0x3b3035326625202c,0x33662e646461090a\n"
".quad 0x3735326625092032,0x2c3135326625202c,0x0a3b343532662520,0x3233662e64646109\n"
".quad 0x2c38353266250920,0x202c323532662520,0x090a3b3535326625,0x203233662e646461\n"
".quad 0x202c393532662509,0x25202c3335326625,0x6c090a3b36353266,0x2e74736e6f632e64\n"
".quad 0x3266250920323366,0x6f436b5b202c3036,0x697274654d726f6c,0x6d090a3b5d342b63\n"
".quad 0x09203233662e6c75,0x25202c3136326625,0x6625202c30363266,0x646c090a3b373532\n"
".quad 0x662e74736e6f632e,0x3632662509203233,0x6c6f436b5b202c32,0x63697274654d726f\n"
".quad 0x6d66090a3b5d302b,0x3233662e6e722e61,0x2c33363266250920,0x202c383532662520\n"
".quad 0x25202c3236326625,0x6c090a3b31363266,0x2e74736e6f632e64,0x3266250920323366\n"
".quad 0x6f436b5b202c3436,0x697274654d726f6c,0x66090a3b5d382b63,0x33662e6e722e616d\n"
".quad 0x3536326625092032,0x2c3935326625202c,0x202c343632662520,0x090a3b3336326625\n"
".quad 0x203233662e766f6d,0x202c363632662509,0x3030303865336630,0x2f092020203b3030\n"
".quad 0x090a35322e30202f,0x203233662e6c756d,0x202c373632662509,0x25202c3536326625\n"
".quad 0x73090a3b36363266,0x662e746c2e707465,0x2c39702509203233,0x202c373632662520\n"
".quad 0x2140090a3b376625,0x2061726220397025,0x315f345f744c2409,0x2f200a3b34393534\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079\n"
".quad 0x64616568202c3536,0x64656c6562616c20,0x315f345f744c2420,0x6c2e090a34313333\n"
".quad 0x373309373109636f,0x766f6d090a300939,0x662509203233662e,0x3736326625202c37\n"
".quad 0x09636f6c2e090a3b,0x3009303833093731,0x3233752e7473090a,0x2b303172255b0920\n"
".quad 0x37367225202c5d30,0x09636f6c2e090a3b,0x3009313833093731,0x3631752e7473090a\n"
".quad 0x302b3672255b0920,0x3b38387225202c5d,0x3109636f6c2e090a,0x0a30093238330937\n"
".quad 0x203631752e747309,0x5d302b3872255b09,0x0a3b36397225202c,0x203631752e646c09\n"
".quad 0x5b202c3739722509,0x0a3b5d302b367225,0x65672e7074657309,0x702509203233752e\n"
".quad 0x36397225202c3031,0x0a3b37397225202c,0x6220303170254009,0x5f744c2409206172\n"
".quad 0x3b36303135315f34,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3536332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34313333315f34,0x373109636f6c2e09,0x73090a3009333709,0x5b09203631752e74\n"
".quad 0x202c5d302b387225,0x2e090a3b37397225,0x3709373109636f6c,0x2e7473090a300934\n"
".quad 0x72255b0920363175,0x7225202c5d302b36,0x6f6c2e090a3b3639,0x3738330937310963\n"
".quad 0x752e646c090a3009,0x3839722509203233,0x2b303172255b202c,0x746f6e090a3b5d30\n"
".quad 0x722509203233622e,0x38397225202c3939,0x752e726873090a3b,0x3031722509203233\n"
".quad 0x2c39397225202c30,0x646e61090a3b3120,0x722509203233622e,0x317225202c313031\n"
".quad 0x31333431202c3030,0x0a3b353637353536,0x3233622e726f7809,0x2c32303172250920\n"
".quad 0x25202c3839722520,0x73090a3b31303172,0x5b09203233752e74,0x2c5d302b30317225\n"
".quad 0x0a3b323031722520,0x35315f345f744c24,0x744c240a3a363031,0x34393534315f345f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c35363320656e,0x62616c2064616568,0x744c242064656c65,0x34313333315f345f\n"
".quad 0x3109636f6c2e090a,0x0a30093836330937,0x3233732e64646109,0x202c393572250920\n"
".quad 0x3b31202c39357225,0x33752e766f6d090a,0x3330317225092032,0x6573090a3b33202c\n"
".quad 0x33732e656e2e7074,0x2c31317025092032,0x25202c3935722520,0x40090a3b33303172\n"
".quad 0x6172622031317025,0x5f345f744c240920,0x240a3b3431333331,0x5f69646e6557444c\n"
".quad 0x38315f66746e6972,0x6c2e090a3a325f33,0x393309373109636f,0x6c756d090a300932\n"
".quad 0x203233752e6f6c2e,0x202c343031722509,0x3b34202c34317225,0x33752e646461090a\n"
".quad 0x3530317225092032,0x202c32317225202c,0x090a3b3430317225,0x09203233662e7473\n"
".quad 0x302b35303172255b,0x0a3b376625202c5d,0x373109636f6c2e09,0x090a300933393309\n"
".quad 0x444c240a3b746572,0x315a5f5f646e6557,0x6c6c416c61766539,0x746174756d726550\n"
".quad 0x66364b50736e6f69,0x6a4b503374616f6c,0x506a525f34537452,0x207d090a3a5f5366\n"
".quad 0x6539315a5f202f2f,0x65506c6c416c6176,0x6f69746174756d72,0x6f6c66364b50736e\n"
".quad 0x74526a4b50337461,0x5366506a525f3453,0x7369762e090a0a5f,0x75662e20656c6269\n"
".quad 0x7773345a5f20636e,0x5452764574497061,0x702e28205f31535f,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f31666d726170,0x744970617773345a,0x5f31535f54527645\n"
".quad 0x6d617261702e202c,0x5f5f203233752e20,0x6d72617061647563,0x7773345a5f5f3266\n"
".quad 0x5452764574497061,0x7b090a295f31535f,0x2e206765722e090a,0x383c722520323375\n"
".quad 0x636f6c2e090a3b3e,0x3009313709373109,0x67656257444c240a,0x7773345a5f5f6e69\n"
".quad 0x5452764574497061,0x6c090a3a5f31535f,0x2e6d617261702e64,0x3172250920323375\n"
".quad 0x6475635f5f5b202c,0x5f31666d72617061,0x4970617773345a5f,0x31535f5452764574\n"
".quad 0x766f6d090a3b5d5f,0x722509203233732e,0x0a3b317225202c32,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x635f5f5b202c3372,0x666d726170616475,0x617773345a5f5f32\n"
".quad 0x5f54527645744970,0x6d090a3b5d5f3153,0x09203233732e766f,0x337225202c347225\n"
".quad 0x09636f6c2e090a3b,0x0a30093237093731,0x203631752e646c09,0x255b202c35722509\n"
".quad 0x090a3b5d302b3272,0x09373109636f6c2e,0x646c090a30093337,0x722509203631752e\n"
".quad 0x2b3472255b202c36,0x2e7473090a3b5d30,0x72255b0920363175,0x7225202c5d302b32\n"
".quad 0x636f6c2e090a3b36,0x3009343709373109,0x3631752e7473090a,0x302b3472255b0920\n"
".quad 0x0a3b357225202c5d,0x373109636f6c2e09,0x72090a3009353709,0x57444c240a3b7465\n"
".quad 0x73345a5f5f646e65,0x5276457449706177,0x090a3a5f31535f54,0x345a5f202f2f207d\n"
".quad 0x7645744970617773,0x090a5f31535f5452,0x206465726168732e,0x34206e67696c612e\n"
".quad 0x635f5f2038622e20,0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f33335f303031\n"
".quad 0x74736e6f635f6e6f,0x73656369646e695f,0x5d3635325b315f5f,0x7369762e090a0a3b\n"
".quad 0x75662e20656c6269,0x7261702e2820636e,0x203233732e206d61,0x6572616475635f5f\n"
".quad 0x6632315a5f5f6674,0x72456e694d646e69,0x5f20296650726f72,0x4d646e696632315a\n"
".quad 0x50726f7272456e69,0x617261702e282066,0x5f203233752e206d,0x726170616475635f\n"
".quad 0x32315a5f5f31666d,0x456e694d646e6966,0x0a296650726f7272,0x6765722e090a7b09\n"
".quad 0x7225203233752e20,0x2e090a3b3e37313c,0x3233662e20676572,0x0a3b3e343c662520\n"
".quad 0x702e206765722e09,0x353c702520646572,0x636f6c2e090a3b3e,0x0930303409373109\n"
".quad 0x656257444c240a30,0x32315a5f5f6e6967,0x456e694d646e6966,0x0a3a6650726f7272\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3172,0x666d726170616475\n"
".quad 0x696632315a5f5f31,0x7272456e694d646e,0x090a3b5d6650726f,0x203233732e766f6d\n"
".quad 0x7225202c32722509,0x61747663090a3b31,0x2e6465726168732e,0x3372250920323375\n"
".quad 0x616475635f5f202c,0x765f6c61636f6c5f,0x30303138335f7261,0x5f6e6f6e5f33335f\n"
".quad 0x6e695f74736e6f63,0x315f5f7365636964,0x09636f6c2e090a3b,0x3009343034093731\n"
".quad 0x33732e747663090a,0x2509203233752e32,0x64697425202c3472,0x6c756d090a3b782e\n"
".quad 0x203233752e6f6c2e,0x7225202c35722509,0x61090a3b34202c34,0x09203233752e6464\n"
".quad 0x357225202c367225,0x090a3b337225202c,0x09203233732e7473,0x2c5d302b3672255b\n"
".quad 0x6d090a3b34722520,0x09203233732e766f,0x3b3233202c377225,0x335f365f744c240a\n"
".quad 0x2f2f200a3a303333,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x303420656e696c20\n"
".quad 0x697473656e202c34,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0939303409373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x656c2e7074657309,0x702509203233732e\n"
".quad 0x202c377225202c31,0x2540090a3b347225,0x0920617262203170,0x35335f365f744c24\n"
".quad 0x3c2f2f200a3b3638,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x34303420656e696c,0x6c2064616568202c,0x242064656c656261,0x3333335f365f744c\n"
".quad 0x09636f6c2e090a30,0x3009343134093731,0x33732e646461090a,0x202c387225092032\n"
".quad 0x347225202c377225,0x6c2e6c756d090a3b,0x2509203233752e6f,0x2c387225202c3972\n"
".quad 0x646461090a3b3420,0x722509203233752e,0x2c397225202c3031,0x6c090a3b32722520\n"
".quad 0x2509203233662e64,0x3172255b202c3166,0x61090a3b5d302b30,0x09203233752e6464\n"
".quad 0x7225202c31317225,0x0a3b327225202c35,0x203233662e646c09,0x255b202c32662509\n"
".quad 0x0a3b5d302b313172,0x74672e7074657309,0x702509203233662e,0x202c326625202c32\n"
".quad 0x2140090a3b316625,0x2061726220327025,0x345f365f744c2409,0x2f2f200a3b383930\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x303420656e696c20\n"
".quad 0x2064616568202c34,0x2064656c6562616c,0x33335f365f744c24,0x636f6c2e090a3033\n"
".quad 0x0937313409373109,0x33662e7473090a30,0x313172255b092032,0x316625202c5d302b\n"
".quad 0x09636f6c2e090a3b,0x3009383134093731,0x33752e646461090a,0x2c32317225092032\n"
".quad 0x7225202c39722520,0x732e646c090a3b33,0x3331722509203233,0x2b323172255b202c\n"
".quad 0x2e7473090a3b5d30,0x72255b0920323373,0x7225202c5d302b36,0x5f744c240a3b3331\n"
".quad 0x0a3a383930345f36,0x35335f365f744c24,0x3c2f2f200a3a3638,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x34303420656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3333335f365f744c,0x09636f6c2e090a30,0x3009373034093731\n"
".quad 0x33732e726873090a,0x202c377225092032,0x0a3b31202c377225,0x3233752e766f6d09\n"
".quad 0x202c343172250920,0x70746573090a3b30,0x203233732e74672e,0x7225202c33702509\n"
".quad 0x3b34317225202c37,0x622033702540090a,0x5f744c2409206172,0x0a3b303333335f36\n"
".quad 0x373109636f6c2e09,0x090a300932373409,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x373409373109636f,0x2e646c090a300934,0x732e646572616873,0x3531722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x303138335f726176,0x6e6f6e5f33335f30\n"
".quad 0x695f74736e6f635f,0x5f5f73656369646e,0x73090a3b5d302b31,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323373,0x6674657261647563,0x6e696632315a5f5f,0x6f7272456e694d64\n"
".quad 0x7225202c5d665072,0x746572090a3b3531,0x6e6557444c240a3b,0x696632315a5f5f64\n"
".quad 0x7272456e694d646e,0x7d090a3a6650726f,0x32315a5f202f2f20,0x456e694d646e6966\n"
".quad 0x0a0a6650726f7272,0x6c62697369762e09,0x20636e75662e2065,0x6576617333315a5f\n"
".quad 0x5458446b636f6c42,0x355069506a747431,0x2e282032746e6975,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5f31666d72617061,0x6576617333315a5f,0x5458446b636f6c42\n"
".quad 0x355069506a747431,0x2e202c32746e6975,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5f32666d72617061,0x6576617333315a5f,0x5458446b636f6c42,0x355069506a747431\n"
".quad 0x2e202c32746e6975,0x752e206d61726170,0x6475635f5f203233,0x5f33666d72617061\n"
".quad 0x6576617333315a5f,0x5458446b636f6c42,0x355069506a747431,0x2e202c32746e6975\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5f34666d72617061,0x6576617333315a5f\n"
".quad 0x5458446b636f6c42,0x355069506a747431,0x2e202c32746e6975,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5f35666d72617061,0x6576617333315a5f,0x5458446b636f6c42\n"
".quad 0x355069506a747431,0x090a2932746e6975,0x206765722e090a7b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e323131,0x6572702e20676572,0x3b3e333c70252064,0x3109636f6c2e090a\n"
".quad 0x0a30093238340937,0x6967656257444c24,0x617333315a5f5f6e,0x446b636f6c426576\n"
".quad 0x69506a7474315458,0x3a32746e69753550,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c317225,0x6d72617061647563,0x7333315a5f5f3166,0x6b636f6c42657661\n"
".quad 0x506a747431545844,0x32746e6975355069,0x2e747663090a3b5d,0x203233752e363175\n"
".quad 0x7225202c32722509,0x702e646c090a3b31,0x3233752e6d617261,0x5b202c3372250920\n"
".quad 0x6170616475635f5f,0x315a5f5f32666d72,0x6f6c426576617333,0x7474315458446b63\n"
".quad 0x6e6975355069506a,0x7663090a3b5d3274,0x33752e3631752e74,0x202c347225092032\n"
".quad 0x646c090a3b337225,0x752e6d617261702e,0x2c35722509203233,0x616475635f5f5b20\n"
".quad 0x5f5f33666d726170,0x426576617333315a,0x315458446b636f6c,0x75355069506a7474\n"
".quad 0x090a3b5d32746e69,0x203233732e766f6d,0x7225202c36722509,0x702e646c090a3b35\n"
".quad 0x3233752e6d617261,0x5b202c3772250920,0x6170616475635f5f,0x315a5f5f34666d72\n"
".quad 0x6f6c426576617333,0x7474315458446b63,0x6e6975355069506a,0x6f6d090a3b5d3274\n"
".quad 0x2509203233732e76,0x3b377225202c3872,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c397225,0x6d72617061647563,0x7333315a5f5f3566,0x6b636f6c42657661\n"
".quad 0x506a747431545844,0x32746e6975355069,0x2e766f6d090a3b5d,0x3172250920323373\n"
".quad 0x0a3b397225202c30,0x3233752e766f6d09,0x202c313172250920,0x70746573090a3b30\n"
".quad 0x203233752e71652e,0x7225202c31702509,0x0a3b347225202c32,0x33752e706c657309\n"
".quad 0x2c32317225092032,0x25202c3131722520,0x3b317025202c3672,0x3109636f6c2e090a\n"
".quad 0x0a30093539340937,0x203233732e646c09,0x5b202c3331722509,0x0a3b5d302b387225\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323373,0x2c33317225202c34,0x726873090a3b3220\n"
".quad 0x722509203233752e,0x32317225202c3531,0x0a3b34317225202c,0x3233622e646e6109\n"
".quad 0x202c363172250920,0x3b33202c35317225,0x3233732e646c090a,0x202c373172250920\n"
".quad 0x3b5d342b3872255b,0x6f6c2e6c756d090a,0x722509203233732e,0x37317225202c3831\n"
".quad 0x6873090a3b32202c,0x2509203233752e72,0x317225202c393172,0x3b38317225202c32\n"
".quad 0x33622e646e61090a,0x2c30327225092032,0x33202c3931722520,0x622e6c6873090a3b\n"
".quad 0x3132722509203233,0x202c30327225202c,0x622e726f090a3b32,0x3232722509203233\n"
".quad 0x202c36317225202c,0x6c090a3b31327225,0x2509203233732e64,0x72255b202c333272\n"
".quad 0x6d090a3b5d382b38,0x33732e6f6c2e6c75,0x2c34327225092032,0x32202c3332722520\n"
".quad 0x752e726873090a3b,0x3532722509203233,0x202c32317225202c,0x61090a3b34327225\n"
".quad 0x09203233622e646e,0x7225202c36327225,0x090a3b33202c3532,0x203233622e6c6873\n"
".quad 0x25202c3732722509,0x0a3b34202c363272,0x203233732e646c09,0x5b202c3832722509\n"
".quad 0x3b5d32312b387225,0x6f6c2e6c756d090a,0x722509203233732e,0x38327225202c3932\n"
".quad 0x6873090a3b32202c,0x2509203233752e72,0x317225202c303372,0x3b39327225202c32\n"
".quad 0x33622e646e61090a,0x2c31337225092032,0x33202c3033722520,0x622e6c6873090a3b\n"
".quad 0x3233722509203233,0x202c31337225202c,0x622e726f090a3b36,0x3333722509203233\n"
".quad 0x202c37327225202c,0x6f090a3b32337225,0x2509203233622e72,0x327225202c343372\n"
".quad 0x3b33337225202c32,0x3233732e646c090a,0x202c353372250920,0x5d36312b3872255b\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x337225202c363372,0x73090a3b32202c35\n"
".quad 0x09203233752e7268,0x7225202c37337225,0x36337225202c3231,0x622e646e61090a3b\n"
".quad 0x3833722509203233,0x202c37337225202c,0x2e6c6873090a3b33,0x3372250920323362\n"
".quad 0x2c38337225202c39,0x2e646c090a3b3820,0x3472250920323373,0x2b3872255b202c30\n"
".quad 0x756d090a3b5d3032,0x3233732e6f6c2e6c,0x202c313472250920,0x3b32202c30347225\n"
".quad 0x33752e726873090a,0x2c32347225092032,0x25202c3231722520,0x6e61090a3b313472\n"
".quad 0x2509203233622e64,0x347225202c333472,0x73090a3b33202c32,0x09203233622e6c68\n"
".quad 0x7225202c34347225,0x0a3b3031202c3334,0x203233622e726f09,0x25202c3534722509\n"
".quad 0x347225202c393372,0x622e726f090a3b34,0x3634722509203233,0x202c34337225202c\n"
".quad 0x6c090a3b35347225,0x2509203233732e64,0x72255b202c373472,0x090a3b5d34322b38\n"
".quad 0x732e6f6c2e6c756d,0x3834722509203233,0x202c37347225202c,0x2e726873090a3b32\n"
".quad 0x3472250920323375,0x2c32317225202c39,0x090a3b3834722520,0x203233622e646e61\n"
".quad 0x25202c3035722509,0x0a3b33202c393472,0x3233622e6c687309,0x202c313572250920\n"
".quad 0x3231202c30357225,0x33732e646c090a3b,0x2c32357225092032,0x38322b3872255b20\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x7225202c33357225,0x090a3b32202c3235\n"
".quad 0x203233752e726873,0x25202c3435722509,0x357225202c323172,0x2e646e61090a3b33\n"
".quad 0x3572250920323362,0x2c34357225202c35,0x6c6873090a3b3320,0x722509203233622e\n"
".quad 0x35357225202c3635,0x6f090a3b3431202c,0x2509203233622e72,0x357225202c373572\n"
".quad 0x3b36357225202c31,0x3233622e726f090a,0x202c383572250920,0x7225202c36347225\n"
".quad 0x2e646c090a3b3735,0x3572250920323373,0x2b3872255b202c39,0x756d090a3b5d3233\n"
".quad 0x3233732e6f6c2e6c,0x202c303672250920,0x3b32202c39357225,0x33752e726873090a\n"
".quad 0x2c31367225092032,0x25202c3231722520,0x6e61090a3b303672,0x2509203233622e64\n"
".quad 0x367225202c323672,0x73090a3b33202c31,0x09203233622e6c68,0x7225202c33367225\n"
".quad 0x0a3b3631202c3236,0x203233622e726f09,0x25202c3436722509,0x367225202c383572\n"
".quad 0x732e646c090a3b33,0x3536722509203233,0x332b3872255b202c,0x6c756d090a3b5d36\n"
".quad 0x203233732e6f6c2e,0x25202c3636722509,0x0a3b32202c353672,0x3233752e72687309\n"
".quad 0x202c373672250920,0x7225202c32317225,0x646e61090a3b3636,0x722509203233622e\n"
".quad 0x37367225202c3836,0x6873090a3b33202c,0x2509203233622e6c,0x367225202c393672\n"
".quad 0x090a3b3831202c38,0x09203233622e726f,0x7225202c30377225,0x39367225202c3436\n"
".quad 0x33732e646c090a3b,0x2c31377225092032,0x30342b3872255b20,0x2e6c756d090a3b5d\n"
".quad 0x09203233732e6f6c,0x7225202c32377225,0x090a3b32202c3137,0x203233752e726873\n"
".quad 0x25202c3337722509,0x377225202c323172,0x2e646e61090a3b32,0x3772250920323362\n"
".quad 0x2c33377225202c34,0x6c6873090a3b3320,0x722509203233622e,0x34377225202c3537\n"
".quad 0x6f090a3b3032202c,0x2509203233622e72,0x377225202c363772,0x3b35377225202c30\n"
".quad 0x3233732e646c090a,0x202c373772250920,0x5d34342b3872255b,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x377225202c383772,0x73090a3b32202c37,0x09203233752e7268\n"
".quad 0x7225202c39377225,0x38377225202c3231,0x622e646e61090a3b,0x3038722509203233\n"
".quad 0x202c39377225202c,0x2e6c6873090a3b33,0x3872250920323362,0x2c30387225202c31\n"
".quad 0x726f090a3b323220,0x722509203233622e,0x36377225202c3238,0x0a3b31387225202c\n"
".quad 0x203233732e646c09,0x5b202c3338722509,0x3b5d38342b387225,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x33387225202c3438,0x6873090a3b32202c,0x2509203233752e72\n"
".quad 0x317225202c353872,0x3b34387225202c32,0x33622e646e61090a,0x2c36387225092032\n"
".quad 0x33202c3538722520,0x622e6c6873090a3b,0x3738722509203233,0x202c36387225202c\n"
".quad 0x2e726f090a3b3432,0x3872250920323362,0x2c32387225202c38,0x090a3b3738722520\n"
".quad 0x09203233732e646c,0x255b202c39387225,0x0a3b5d32352b3872,0x2e6f6c2e6c756d09\n"
".quad 0x3972250920323373,0x2c39387225202c30,0x726873090a3b3220,0x722509203233752e\n"
".quad 0x32317225202c3139,0x0a3b30397225202c,0x3233622e646e6109,0x202c323972250920\n"
".quad 0x3b33202c31397225,0x33622e6c6873090a,0x2c33397225092032,0x32202c3239722520\n"
".quad 0x622e726f090a3b36,0x3439722509203233,0x202c38387225202c,0x6c090a3b33397225\n"
".quad 0x2509203233732e64,0x72255b202c353972,0x090a3b5d36352b38,0x732e6f6c2e6c756d\n"
".quad 0x3639722509203233,0x202c35397225202c,0x2e726873090a3b32,0x3972250920323375\n"
".quad 0x2c32317225202c37,0x090a3b3639722520,0x203233622e646e61,0x25202c3839722509\n"
".quad 0x0a3b33202c373972,0x3233622e6c687309,0x202c393972250920,0x3832202c38397225\n"
".quad 0x33622e726f090a3b,0x3030317225092032,0x202c34397225202c,0x6c090a3b39397225\n"
".quad 0x2509203233732e64,0x255b202c31303172,0x0a3b5d30362b3872,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323373,0x30317225202c3230,0x73090a3b32202c31,0x09203233752e7268\n"
".quad 0x25202c3330317225,0x317225202c323172,0x6c6873090a3b3230,0x722509203233622e\n"
".quad 0x317225202c343031,0x0a3b3033202c3330,0x203233622e726f09,0x202c353031722509\n"
".quad 0x25202c3030317225,0x2e090a3b34303172,0x3409373109636f6c,0x7663090a30093939\n"
".quad 0x33752e3233732e74,0x3630317225092032,0x646961746325202c,0x6c756d090a3b782e\n"
".quad 0x203233752e6f6c2e,0x202c373031722509,0x38202c3630317225,0x752e646461090a3b\n"
".quad 0x3031722509203233,0x3730317225202c38,0x0a3b30317225202c,0x3233622e6c687309\n"
".quad 0x2c39303172250920,0x3631202c34722520,0x33622e726f090a3b,0x3031317225092032\n"
".quad 0x25202c327225202c,0x73090a3b39303172,0x3233752e32762e74,0x38303172255b0920\n"
".quad 0x72257b202c5d302b,0x303172252c303131,0x6f6c2e090a3b7d35,0x3330350937310963\n"
".quad 0x3b746572090a3009,0x646e6557444c240a,0x76617333315a5f5f,0x58446b636f6c4265\n"
".quad 0x5069506a74743154,0x0a3a32746e697535,0x5a5f202f2f207d09,0x6c42657661733331\n"
".quad 0x74315458446b636f,0x6975355069506a74,0x652e090a0a32746e,0x385a5f207972746e\n"
".quad 0x73736572706d6f63,0x35505f30536a4b50,0x0a282032746e6975,0x6d617261702e0909\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x706d6f63385a5f5f,0x536a4b5073736572\n"
".quad 0x746e697535505f30,0x74756d7265705f32,0x0a2c736e6f697461,0x6d617261702e0909\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x706d6f63385a5f5f,0x536a4b5073736572\n"
".quad 0x746e697535505f30,0x2c6567616d695f32,0x617261702e09090a,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x6d6f63385a5f5f6d,0x6a4b507373657270,0x6e697535505f3053\n"
".quad 0x6c757365725f3274,0x2e090a7b090a2974,0x3631752e20676572,0x3b3e343c68722520\n"
".quad 0x2e206765722e090a,0x333c722520323375,0x722e090a3b3e3034,0x203233662e206765\n"
".quad 0x3b3e3532353c6625,0x2e206765722e090a,0x3c70252064657270,0x732e090a3b3e3732\n"
".quad 0x612e206465726168,0x2e2034206e67696c,0x6475635f5f203862,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x31363138335f7261,0x5f6e6f6e5f36335f,0x6f635f74736e6f63\n"
".quad 0x3635333173726f6c,0x090a3b5d3239315b,0x206465726168732e,0x31206e67696c612e\n"
".quad 0x5f5f2038622e2036,0x635f5f5f61647563,0x61636f6c5f616475,0x38335f7261765f6c\n"
".quad 0x6e5f36335f323631,0x74736e6f635f6e6f,0x343531736d75735f,0x0a3b5d3239315b38\n"
".quad 0x6465726168732e09,0x206e67696c612e20,0x5f2038622e203631,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f33335f33363138,0x736e6f635f6e6f6e\n"
".quad 0x3173666572785f74,0x3b5d34365b303437,0x65726168732e090a,0x6e67696c612e2064\n"
".quad 0x5f2038622e203420,0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f35335f32373138,0x736e6f635f6e6f6e,0x73726f7272655f74,0x3635325b34303831\n"
".quad 0x5f202f2f090a3b5d,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32315f3936313833\n"
".quad 0x6e6f635f6e6f6e5f,0x53747365625f7473,0x34203d2074726174,0x5f5f202f2f090a34\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f33325f39363138,0x736e6f635f6e6f6e\n"
".quad 0x6e45747365625f74,0x090a3634203d2064,0x6475635f5f202f2f,0x5f6c61636f6c5f61\n"
".quad 0x373138335f726176,0x6e6f6e5f30315f30,0x625f74736e6f635f,0x756d726550747365\n"
".quad 0x3d206e6f69746174,0x202f2f090a303420,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x315f36383837335f,0x6f635f6e6f6e5f32,0x20706d745f74736e,0x2f2f090a3832203d\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f35353537335f72,0x635f6e6f6e5f3231\n"
".quad 0x6669645f74736e6f,0x090a3631203d2066,0x09373109636f6c2e,0x4c240a3009393035\n"
".quad 0x5f6e696765625744,0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f\n"
".quad 0x09636f6c2e090a3a,0x3009373135093731,0x33732e747663090a,0x2509203233752e32\n"
".quad 0x64697425202c3172,0x766f6d090a3b782e,0x722509203233732e,0x090a3b3531202c32\n"
".quad 0x2e656c2e70746573,0x3170250920323373,0x25202c317225202c,0x252140090a3b3272\n"
".quad 0x0920617262203170,0x36335f385f744c24,0x6c2e090a3b343533,0x343109373109636f\n"
".quad 0x766f6d090a300938,0x722509203233752e,0x6475635f5f202c33,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x31363138335f7261,0x5f6e6f6e5f36335f,0x6f635f74736e6f63\n"
".quad 0x3635333173726f6c,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c34722509\n"
".quad 0x726170616475635f,0x6d6f63385a5f5f6d,0x6a4b507373657270,0x6e697535505f3053\n"
".quad 0x6567616d695f3274,0x2e747663090a3b5d,0x203233752e323373,0x6325202c35722509\n"
".quad 0x0a3b782e64696174,0x2e6f6c2e6c756d09,0x3672250920323373,0x31202c357225202c\n"
".quad 0x2e646461090a3b36,0x3772250920323373,0x25202c317225202c,0x6c756d090a3b3672\n"
".quad 0x203233752e6f6c2e,0x7225202c38722509,0x61090a3b34202c37,0x09203233752e6464\n"
".quad 0x347225202c397225,0x090a3b387225202c,0x61626f6c672e646c,0x2509203233752e6c\n"
".quad 0x72255b202c303172,0x2e090a3b5d302b39,0x3109373109636f6c,0x756d090a30093035\n"
".quad 0x3233752e6f6c2e6c,0x202c313172250920,0x3b3231202c317225,0x33752e646461090a\n"
".quad 0x2c32317225092032,0x25202c3131722520,0x646e61090a3b3372,0x722509203233622e\n"
".quad 0x30317225202c3331,0x090a3b353532202c,0x662e6e722e747663,0x09203233752e3233\n"
".quad 0x317225202c316625,0x2e766f6d090a3b33,0x3266250920323366,0x303862336630202c\n"
".quad 0x2020203b31383038,0x2e30202f2f092020,0x3735313239333030,0x33662e6c756d090a\n"
".quad 0x202c336625092032,0x326625202c316625,0x68732e7473090a3b,0x3233662e64657261\n"
".quad 0x2b323172255b0920,0x3b336625202c5d30,0x3109636f6c2e090a,0x0a30093135310937\n"
".quad 0x3233622e6c687309,0x202c343172250920,0x3631202c30317225,0x752e726873090a3b\n"
".quad 0x3531722509203233,0x202c34317225202c,0x747663090a3b3432,0x2e3233662e6e722e\n"
".quad 0x3466250920323375,0x0a3b35317225202c,0x3233662e766f6d09,0x30202c3566250920\n"
".quad 0x3830383038623366,0x0920202020203b31,0x3330302e30202f2f,0x6d090a3735313239\n"
".quad 0x09203233662e6c75,0x346625202c366625,0x090a3b356625202c,0x65726168732e7473\n"
".quad 0x5b09203233662e64,0x2c5d342b32317225,0x2e090a3b36662520,0x3109373109636f6c\n"
".quad 0x6873090a30093235,0x2509203233622e6c,0x317225202c363172,0x73090a3b38202c30\n"
".quad 0x09203233752e7268,0x7225202c37317225,0x0a3b3432202c3631,0x2e6e722e74766309\n"
".quad 0x203233752e323366,0x7225202c37662509,0x766f6d090a3b3731,0x662509203233662e\n"
".quad 0x3862336630202c38,0x20203b3138303830,0x30202f2f09202020,0x353132393330302e\n"
".quad 0x662e6c756d090a37,0x2c39662509203233,0x6625202c37662520,0x732e7473090a3b38\n"
".quad 0x33662e6465726168,0x323172255b092032,0x396625202c5d382b,0x5f385f744c240a3b\n"
".quad 0x090a3a3435333633,0x203233752e766f6d,0x5f5f202c33722509,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f36335f313631,0x74736e6f635f6e6f\n"
".quad 0x3173726f6c6f635f,0x6c2e090a3b363533,0x353109373109636f,0x726162090a300936\n"
".quad 0x300920636e79732e,0x3170252140090a3b,0x4c24092061726220,0x363836335f385f74\n"
".quad 0x636f6c2e090a3b36,0x0930363109373109,0x752e766f6d090a30,0x3831722509203233\n"
".quad 0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f32363138335f72\n"
".quad 0x635f6e6f6e5f3633,0x6d75735f74736e6f,0x090a3b3834353173,0x752e6f6c2e6c756d\n"
".quad 0x3131722509203233,0x31202c317225202c,0x2e646461090a3b32,0x3172250920323375\n"
".quad 0x2c31317225202c32,0x61090a3b33722520,0x09203233752e6464,0x7225202c39317225\n"
".quad 0x38317225202c3131,0x68732e646c090a3b,0x3233662e64657261,0x202c303166250920\n"
".quad 0x5d302b323172255b,0x68732e7473090a3b,0x3233662e64657261,0x2b393172255b0920\n"
".quad 0x30316625202c5d30,0x68732e646c090a3b,0x3233662e64657261,0x202c313166250920\n"
".quad 0x5d342b323172255b,0x68732e7473090a3b,0x3233662e64657261,0x2b393172255b0920\n"
".quad 0x31316625202c5d34,0x68732e646c090a3b,0x3233662e64657261,0x202c323166250920\n"
".quad 0x5d382b323172255b,0x68732e7473090a3b,0x3233662e64657261,0x2b393172255b0920\n"
".quad 0x32316625202c5d38,0x5f385f744c240a3b,0x090a3a3636383633,0x203233752e766f6d\n"
".quad 0x5f202c3831722509,0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f36335f32363138,0x736e6f635f6e6f6e,0x3531736d75735f74,0x726162090a3b3834\n"
".quad 0x300920636e79732e,0x3170252140090a3b,0x4c24092061726220,0x373337335f385f74\n"
".quad 0x2e726f78090a3b38,0x3272250920323362,0x202c317225202c30,0x2e6c756d090a3b38\n"
".quad 0x09203233752e6f6c,0x7225202c31327225,0x0a3b3231202c3032,0x3233752e64646109\n"
".quad 0x202c323272250920,0x7225202c31327225,0x2e646c090a3b3831,0x662e646572616873\n"
".quad 0x3331662509203233,0x2b323272255b202c,0x2e646c090a3b5d34,0x662e646572616873\n"
".quad 0x3431662509203233,0x2b323272255b202c,0x6c756d090a3b5d38,0x203233752e6f6c2e\n"
".quad 0x25202c3131722509,0x0a3b3231202c3172,0x3233752e64646109,0x202c393172250920\n"
".quad 0x7225202c31317225,0x2e646c090a3b3831,0x662e646572616873,0x3531662509203233\n"
".quad 0x2b323272255b202c,0x2e646c090a3b5d30,0x662e646572616873,0x3631662509203233\n"
".quad 0x2b393172255b202c,0x646461090a3b5d30,0x662509203233662e,0x35316625202c3731\n"
".quad 0x0a3b36316625202c,0x726168732e747309,0x09203233662e6465,0x5d302b393172255b\n"
".quad 0x0a3b37316625202c,0x726168732e646c09,0x09203233662e6465,0x255b202c38316625\n"
".quad 0x0a3b5d342b393172,0x3233662e64646109,0x202c393166250920,0x6625202c38316625\n"
".quad 0x2e7473090a3b3331,0x662e646572616873,0x3172255b09203233,0x6625202c5d342b39\n"
".quad 0x2e646c090a3b3931,0x662e646572616873,0x3032662509203233,0x2b393172255b202c\n"
".quad 0x646461090a3b5d38,0x662509203233662e,0x30326625202c3132,0x0a3b34316625202c\n"
".quad 0x726168732e747309,0x09203233662e6465,0x5d382b393172255b,0x0a3b31326625202c\n"
".quad 0x37335f385f744c24,0x6162090a3a383733,0x0920636e79732e72,0x70252140090a3b30\n"
".quad 0x2409206172622031,0x3837335f385f744c,0x726f78090a3b3039,0x722509203233622e\n"
".quad 0x2c317225202c3332,0x6c756d090a3b3420,0x203233752e6f6c2e,0x25202c3432722509\n"
".quad 0x3b3231202c333272,0x33752e646461090a,0x2c35327225092032,0x25202c3432722520\n"
".quad 0x646c090a3b383172,0x2e6465726168732e,0x3266250920323366,0x353272255b202c32\n"
".quad 0x646c090a3b5d342b,0x2e6465726168732e,0x3266250920323366,0x353272255b202c33\n"
".quad 0x756d090a3b5d382b,0x3233752e6f6c2e6c,0x202c313172250920,0x3b3231202c317225\n"
".quad 0x33752e646461090a,0x2c39317225092032,0x25202c3131722520,0x646c090a3b383172\n"
".quad 0x2e6465726168732e,0x3266250920323366,0x353272255b202c34,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x3266250920323366,0x393172255b202c35,0x6461090a3b5d302b\n"
".quad 0x2509203233662e64,0x326625202c363266,0x3b35326625202c34,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x302b393172255b09,0x3b36326625202c5d,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3732662509,0x3b5d342b39317225,0x33662e646461090a\n"
".quad 0x2c38326625092032,0x25202c3732662520,0x7473090a3b323266,0x2e6465726168732e\n"
".quad 0x72255b0920323366,0x25202c5d342b3931,0x646c090a3b383266,0x2e6465726168732e\n"
".quad 0x3266250920323366,0x393172255b202c39,0x6461090a3b5d382b,0x2509203233662e64\n"
".quad 0x326625202c303366,0x3b33326625202c39,0x6168732e7473090a,0x203233662e646572\n"
".quad 0x382b393172255b09,0x3b30336625202c5d,0x335f385f744c240a,0x62090a3a30393837\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x38335f385f744c24\n"
".quad 0x6f78090a3b323034,0x2509203233622e72,0x317225202c363272,0x756d090a3b32202c\n"
".quad 0x3233752e6f6c2e6c,0x202c373272250920,0x3231202c36327225,0x752e646461090a3b\n"
".quad 0x3832722509203233,0x202c37327225202c,0x6c090a3b38317225,0x6465726168732e64\n"
".quad 0x662509203233662e,0x3272255b202c3133,0x6c090a3b5d342b38,0x6465726168732e64\n"
".quad 0x662509203233662e,0x3272255b202c3233,0x6d090a3b5d382b38,0x33752e6f6c2e6c75\n"
".quad 0x2c31317225092032,0x3231202c31722520,0x752e646461090a3b,0x3931722509203233\n"
".quad 0x202c31317225202c,0x6c090a3b38317225,0x6465726168732e64,0x662509203233662e\n"
".quad 0x3272255b202c3333,0x6c090a3b5d302b38,0x6465726168732e64,0x662509203233662e\n"
".quad 0x3172255b202c3433,0x61090a3b5d302b39,0x09203233662e6464,0x6625202c35336625\n"
".quad 0x34336625202c3333,0x68732e7473090a3b,0x3233662e64657261,0x2b393172255b0920\n"
".quad 0x35336625202c5d30,0x68732e646c090a3b,0x3233662e64657261,0x202c363366250920\n"
".quad 0x5d342b393172255b,0x662e646461090a3b,0x3733662509203233,0x202c36336625202c\n"
".quad 0x73090a3b31336625,0x6465726168732e74,0x255b09203233662e,0x202c5d342b393172\n"
".quad 0x6c090a3b37336625,0x6465726168732e64,0x662509203233662e,0x3172255b202c3833\n"
".quad 0x61090a3b5d382b39,0x09203233662e6464,0x6625202c39336625,0x32336625202c3833\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x2b393172255b0920,0x39336625202c5d38\n"
".quad 0x5f385f744c240a3b,0x090a3a3230343833,0x636e79732e726162,0x2140090a3b300920\n"
".quad 0x2061726220317025,0x335f385f744c2409,0x78090a3b34313938,0x09203233622e726f\n"
".quad 0x7225202c39327225,0x6d090a3b31202c31,0x33752e6f6c2e6c75,0x2c30337225092032\n"
".quad 0x31202c3932722520,0x2e646461090a3b32,0x3372250920323375,0x2c30337225202c31\n"
".quad 0x090a3b3831722520,0x65726168732e646c,0x2509203233662e64,0x72255b202c303466\n"
".quad 0x090a3b5d342b3133,0x65726168732e646c,0x2509203233662e64,0x72255b202c313466\n"
".quad 0x090a3b5d382b3133,0x752e6f6c2e6c756d,0x3131722509203233,0x31202c317225202c\n"
".quad 0x2e646461090a3b32,0x3172250920323375,0x2c31317225202c39,0x090a3b3831722520\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c323466,0x090a3b5d302b3133\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x72255b202c333466,0x090a3b5d302b3931\n"
".quad 0x203233662e646461,0x25202c3434662509,0x346625202c323466,0x732e7473090a3b33\n"
".quad 0x33662e6465726168,0x393172255b092032,0x346625202c5d302b,0x732e646c090a3b34\n"
".quad 0x33662e6465726168,0x2c35346625092032,0x342b393172255b20,0x2e646461090a3b5d\n"
".quad 0x3466250920323366,0x2c35346625202c36,0x090a3b3034662520,0x65726168732e7473\n"
".quad 0x5b09203233662e64,0x2c5d342b39317225,0x090a3b3634662520,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c373466,0x090a3b5d382b3931,0x203233662e646461\n"
".quad 0x25202c3834662509,0x346625202c373466,0x732e7473090a3b31,0x33662e6465726168\n"
".quad 0x393172255b092032,0x346625202c5d382b,0x385f744c240a3b38,0x0a3a34313938335f\n"
".quad 0x6e79732e72616209,0x2e090a3b30092063,0x3109373109636f6c,0x2140090a30093136\n"
".quad 0x2061726220317025,0x335f385f744c2409,0x2e090a3b38333939,0x3109363109636f6c\n"
".quad 0x756d090a30093231,0x3233752e6f6c2e6c,0x202c313172250920,0x3b3231202c317225\n"
".quad 0x33752e646461090a,0x2c32317225092032,0x25202c3131722520,0x2e646c090a3b3372\n"
".quad 0x662e646572616873,0x3934662509203233,0x2b323172255b202c,0x766f6d090a3b5d30\n"
".quad 0x662509203233662e,0x64336630202c3035,0x203b303030303038,0x30202f2f09202020\n"
".quad 0x6c090a353236302e,0x6465726168732e64,0x203233662e34762e,0x252c313566257b09\n"
".quad 0x333566252c323566,0x5f5f5b202c7d5f2c,0x635f5f5f61647563,0x61636f6c5f616475\n"
".quad 0x38335f7261765f6c,0x6e5f36335f323631,0x74736e6f635f6e6f,0x343531736d75735f\n"
".quad 0x6d090a3b5d302b38,0x09203233662e6c75,0x6625202c34356625,0x31356625202c3035\n"
".quad 0x662e627573090a3b,0x3535662509203233,0x202c39346625202c,0x6d090a3b34356625\n"
".quad 0x09203233662e766f,0x6625202c36356625,0x2e646c090a3b3535,0x662e646572616873\n"
".quad 0x3735662509203233,0x2b323172255b202c,0x766f6d090a3b5d34,0x662509203233662e\n"
".quad 0x64336630202c3835,0x203b303030303038,0x30202f2f09202020,0x6d090a353236302e\n"
".quad 0x09203233662e6c75,0x6625202c39356625,0x32356625202c3835,0x662e627573090a3b\n"
".quad 0x3036662509203233,0x202c37356625202c,0x6d090a3b39356625,0x09203233662e766f\n"
".quad 0x6625202c31366625,0x2e646c090a3b3036,0x662e646572616873,0x3236662509203233\n"
".quad 0x2b323172255b202c,0x766f6d090a3b5d38,0x662509203233662e,0x64336630202c3336\n"
".quad 0x203b303030303038,0x30202f2f09202020,0x6d090a353236302e,0x09203233662e6c75\n"
".quad 0x6625202c34366625,0x33356625202c3336,0x662e627573090a3b,0x3536662509203233\n"
".quad 0x202c32366625202c,0x6d090a3b34366625,0x09203233662e766f,0x6625202c36366625\n"
".quad 0x5f744c240a3b3536,0x3a36323439335f38,0x203170252140090a,0x744c240920617262\n"
".quad 0x38333939335f385f,0x09636f6c2e090a3b,0x3009393131093631,0x33752e766f6d090a\n"
".quad 0x2c32337225092032,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f31363537335f72\n"
".quad 0x635f6e6f6e5f3533,0x766f635f74736e6f,0x5f65636e61697261,0x6c756d090a3b305f\n"
".quad 0x203233732e6f6c2e,0x25202c3333722509,0x090a3b36202c3172,0x752e6f6c2e6c756d\n"
".quad 0x3433722509203233,0x202c33337225202c,0x2e646461090a3b34,0x3372250920323375\n"
".quad 0x2c34337225202c35,0x090a3b3233722520,0x203233662e766f6d,0x25202c3736662509\n"
".quad 0x756d090a3b363566,0x2509203233662e6c,0x366625202c383666,0x3b37366625202c37\n"
".quad 0x6168732e7473090a,0x203233662e646572,0x302b353372255b09,0x3b38366625202c5d\n"
".quad 0x3109636f6c2e090a,0x0a30093032310936,0x3233662e766f6d09,0x202c393666250920\n"
".quad 0x6d090a3b31366625,0x09203233662e6c75,0x6625202c30376625,0x37366625202c3936\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x2b353372255b0920,0x30376625202c5d34\n"
".quad 0x09636f6c2e090a3b,0x3009313231093631,0x33662e766f6d090a,0x2c31376625092032\n"
".quad 0x090a3b3636662520,0x203233662e6c756d,0x25202c3237662509,0x366625202c313766\n"
".quad 0x732e7473090a3b37,0x33662e6465726168,0x353372255b092032,0x376625202c5d382b\n"
".quad 0x636f6c2e090a3b32,0x0932323109363109,0x662e6c756d090a30,0x3337662509203233\n"
".quad 0x202c39366625202c,0x73090a3b39366625,0x6465726168732e74,0x255b09203233662e\n"
".quad 0x2c5d32312b353372,0x090a3b3337662520,0x09363109636f6c2e,0x6d090a3009333231\n"
".quad 0x09203233662e6c75,0x6625202c34376625,0x39366625202c3137,0x68732e7473090a3b\n"
".quad 0x3233662e64657261,0x2b353372255b0920,0x376625202c5d3631,0x636f6c2e090a3b34\n"
".quad 0x0934323109363109,0x662e6c756d090a30,0x3537662509203233,0x202c31376625202c\n"
".quad 0x73090a3b31376625,0x6465726168732e74,0x255b09203233662e,0x2c5d30322b353372\n"
".quad 0x240a3b3537662520,0x3939335f385f744c,0x766f6d090a3a3833,0x722509203233752e\n"
".quad 0x75635f5f202c3233,0x6c61636f6c5f6164,0x3537335f7261765f,0x6f6e5f35335f3136\n"
".quad 0x5f74736e6f635f6e,0x6e61697261766f63,0x090a3b305f5f6563,0x09363109636f6c2e\n"
".quad 0x62090a3009363231,0x20636e79732e7261,0x766f6d090a3b3009,0x722509203233732e\n"
".quad 0x240a3b38202c3633,0x3930345f385f744c,0x3c2f2f200a3a3236,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x36323120656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x2e70746573090a6e,0x09203233732e7467,0x337225202c327025,0x0a3b317225202c36\n"
".quad 0x6220327025214009,0x5f744c2409206172,0x3b38313231345f38,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3632312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363930345f38,0x363109636f6c2e09\n"
".quad 0x090a300930333109,0x732e6f6c2e6c756d,0x3333722509203233,0x36202c317225202c\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x337225202c343372,0x61090a3b34202c33\n"
".quad 0x09203233752e6464,0x7225202c35337225,0x32337225202c3433,0x68732e646c090a3b\n"
".quad 0x3233662e64657261,0x202c363766250920,0x5d302b353372255b,0x732e646461090a3b\n"
".quad 0x3733722509203233,0x202c36337225202c,0x756d090a3b317225,0x3233732e6f6c2e6c\n"
".quad 0x202c383372250920,0x3b36202c37337225,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x38337225202c3933,0x6461090a3b34202c,0x2509203233752e64,0x337225202c303472\n"
".quad 0x3b39337225202c32,0x6168732e646c090a,0x203233662e646572,0x5b202c3737662509\n"
".quad 0x3b5d302b30347225,0x33662e646461090a,0x2c38376625092032,0x25202c3637662520\n"
".quad 0x7473090a3b373766,0x2e6465726168732e,0x72255b0920323366,0x25202c5d302b3533\n"
".quad 0x744c240a3b383766,0x38313231345f385f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363930345f385f,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x7262203270252140,0x385f744c24092061,0x0a3b30333731345f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120\n"
".quad 0x6c6562616c206461,0x385f744c24206465,0x090a32363930345f,0x09363109636f6c2e\n"
".quad 0x6d090a3009313331,0x33732e6f6c2e6c75,0x2c33337225092032,0x3b36202c31722520\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x33337225202c3433,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x337225202c353372,0x3b32337225202c34,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3937662509,0x3b5d342b35337225,0x33732e646461090a\n"
".quad 0x2c31347225092032,0x25202c3633722520,0x6c756d090a3b3172,0x203233732e6f6c2e\n"
".quad 0x25202c3234722509,0x0a3b36202c313472,0x2e6f6c2e6c756d09,0x3472250920323375\n"
".quad 0x2c32347225202c33,0x646461090a3b3420,0x722509203233752e,0x32337225202c3434\n"
".quad 0x0a3b33347225202c,0x726168732e646c09,0x09203233662e6465,0x255b202c30386625\n"
".quad 0x0a3b5d342b343472,0x3233662e64646109,0x202c313866250920,0x6625202c39376625\n"
".quad 0x2e7473090a3b3038,0x662e646572616873,0x3372255b09203233,0x6625202c5d342b35\n"
".quad 0x5f744c240a3b3138,0x3a30333731345f38,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3632312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363930345f38,0x6e79732e72616209,0x40090a3b30092063\n"
".quad 0x6172622032702521,0x5f385f744c240920,0x200a3b3234323234,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363231\n"
".quad 0x656c6562616c2064,0x5f385f744c242064,0x2e090a3236393034,0x3109363109636f6c\n"
".quad 0x756d090a30093233,0x3233732e6f6c2e6c,0x202c333372250920,0x0a3b36202c317225\n"
".quad 0x2e6f6c2e6c756d09,0x3372250920323375,0x2c33337225202c34,0x646461090a3b3420\n"
".quad 0x722509203233752e,0x34337225202c3533,0x0a3b32337225202c,0x726168732e646c09\n"
".quad 0x09203233662e6465,0x255b202c32386625,0x0a3b5d382b353372,0x3233732e64646109\n"
".quad 0x202c353472250920,0x7225202c36337225,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x7225202c36347225,0x090a3b36202c3534,0x752e6f6c2e6c756d,0x3734722509203233\n"
".quad 0x202c36347225202c,0x2e646461090a3b34,0x3472250920323375,0x2c32337225202c38\n"
".quad 0x090a3b3734722520,0x65726168732e646c,0x2509203233662e64,0x72255b202c333866\n"
".quad 0x090a3b5d382b3834,0x203233662e646461,0x25202c3438662509,0x386625202c323866\n"
".quad 0x732e7473090a3b33,0x33662e6465726168,0x353372255b092032,0x386625202c5d382b\n"
".quad 0x385f744c240a3b34,0x0a3a32343232345f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120,0x6c6562616c206461\n"
".quad 0x385f744c24206465,0x090a32363930345f,0x636e79732e726162,0x2140090a3b300920\n"
".quad 0x2061726220327025,0x345f385f744c2409,0x2f200a3b34353732,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3632\n"
".quad 0x64656c6562616c20,0x345f385f744c2420,0x6c2e090a32363930,0x333109363109636f\n"
".quad 0x6c756d090a300933,0x203233732e6f6c2e,0x25202c3333722509,0x090a3b36202c3172\n"
".quad 0x752e6f6c2e6c756d,0x3433722509203233,0x202c33337225202c,0x2e646461090a3b34\n"
".quad 0x3372250920323375,0x2c34337225202c35,0x090a3b3233722520,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c353866,0x0a3b5d32312b3533,0x3233732e64646109\n"
".quad 0x202c393472250920,0x7225202c36337225,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x7225202c30357225,0x090a3b36202c3934,0x752e6f6c2e6c756d,0x3135722509203233\n"
".quad 0x202c30357225202c,0x2e646461090a3b34,0x3572250920323375,0x2c32337225202c32\n"
".quad 0x090a3b3135722520,0x65726168732e646c,0x2509203233662e64,0x72255b202c363866\n"
".quad 0x0a3b5d32312b3235,0x3233662e64646109,0x202c373866250920,0x6625202c35386625\n"
".quad 0x2e7473090a3b3638,0x662e646572616873,0x3372255b09203233,0x25202c5d32312b35\n"
".quad 0x744c240a3b373866,0x34353732345f385f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x32363930345f385f,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x7262203270252140,0x385f744c24092061,0x0a3b36363233345f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36323120\n"
".quad 0x6c6562616c206461,0x385f744c24206465,0x090a32363930345f,0x09363109636f6c2e\n"
".quad 0x6d090a3009343331,0x33732e6f6c2e6c75,0x2c33337225092032,0x3b36202c31722520\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x33337225202c3433,0x6461090a3b34202c\n"
".quad 0x2509203233752e64,0x337225202c353372,0x3b32337225202c34,0x6168732e646c090a\n"
".quad 0x203233662e646572,0x5b202c3838662509,0x5d36312b35337225,0x732e646461090a3b\n"
".quad 0x3335722509203233,0x202c36337225202c,0x756d090a3b317225,0x3233732e6f6c2e6c\n"
".quad 0x202c343572250920,0x3b36202c33357225,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x34357225202c3535,0x6461090a3b34202c,0x2509203233752e64,0x337225202c363572\n"
".quad 0x3b35357225202c32,0x6168732e646c090a,0x203233662e646572,0x5b202c3938662509\n"
".quad 0x5d36312b36357225,0x662e646461090a3b,0x3039662509203233,0x202c38386625202c\n"
".quad 0x73090a3b39386625,0x6465726168732e74,0x255b09203233662e,0x2c5d36312b353372\n"
".quad 0x240a3b3039662520,0x3233345f385f744c,0x3c2f2f200a3a3636,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36323120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3930345f385f744c,0x2e726162090a3236,0x3b300920636e7973\n"
".quad 0x203270252140090a,0x744c240920617262,0x38373733345f385f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36323120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363930345f385f,0x3109636f6c2e090a\n"
".quad 0x0a30093533310936,0x2e6f6c2e6c756d09,0x3372250920323373,0x202c317225202c33\n"
".quad 0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c34337225,0x090a3b34202c3333\n"
".quad 0x203233752e646461,0x25202c3533722509,0x337225202c343372,0x732e646c090a3b32\n"
".quad 0x33662e6465726168,0x2c31396625092032,0x322b353372255b20,0x646461090a3b5d30\n"
".quad 0x722509203233732e,0x36337225202c3735,0x090a3b317225202c,0x732e6f6c2e6c756d\n"
".quad 0x3835722509203233,0x202c37357225202c,0x2e6c756d090a3b36,0x09203233752e6f6c\n"
".quad 0x7225202c39357225,0x090a3b34202c3835,0x203233752e646461,0x25202c3036722509\n"
".quad 0x357225202c323372,0x732e646c090a3b39,0x33662e6465726168,0x2c32396625092032\n"
".quad 0x322b303672255b20,0x646461090a3b5d30,0x662509203233662e,0x31396625202c3339\n"
".quad 0x0a3b32396625202c,0x726168732e747309,0x09203233662e6465,0x30322b353372255b\n"
".quad 0x3b33396625202c5d,0x345f385f744c240a,0x2f200a3a38373733,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3632\n"
".quad 0x64656c6562616c20,0x345f385f744c2420,0x6162090a32363930,0x0920636e79732e72\n"
".quad 0x636f6c2e090a3b30,0x0938323109363109,0x732e726873090a30,0x3633722509203233\n"
".quad 0x202c36337225202c,0x2e766f6d090a3b31,0x3672250920323375,0x73090a3b30202c31\n"
".quad 0x732e74672e707465,0x2c33702509203233,0x25202c3633722520,0x2540090a3b313672\n"
".quad 0x0920617262203370,0x30345f385f744c24,0x646c090a3b323639,0x2e6465726168732e\n"
".quad 0x09203233662e3476,0x66252c343966257b,0x2c363966252c3539,0x635f5f5b202c7d5f\n"
".quad 0x61636f6c5f616475,0x37335f7261765f6c,0x6e5f35335f313635,0x74736e6f635f6e6f\n"
".quad 0x61697261766f635f,0x302b305f5f65636e,0x636f6c2e090a3b5d,0x3009343509363109\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x5b202c3739662509,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f31363537335f,0x6f635f6e6f6e5f35,0x61766f635f74736e\n"
".quad 0x5f5f65636e616972,0x090a3b5d32312b30,0x203233662e766f6d,0x30202c3839662509\n"
".quad 0x3030303038663366,0x2f09202020203b30,0x616d66090a31202f,0x203233662e6e722e\n"
".quad 0x25202c3939662509,0x396625202c383966,0x3b37396625202c35,0x6168732e646c090a\n"
".quad 0x662e32762e646572,0x3166257b09203233,0x31303166252c3030,0x75635f5f5b202c7d\n"
".quad 0x6c61636f6c5f6164,0x3537335f7261765f,0x6f6e5f35335f3136,0x5f74736e6f635f6e\n"
".quad 0x6e61697261766f63,0x36312b305f5f6563,0x2e766f6d090a3b5d,0x3166250920323366\n"
".quad 0x66336630202c3230,0x203b303030303038,0x0a31202f2f092020,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x30316625202c3330,0x2c36396625202c32,0x0a3b303031662520\n"
".quad 0x3233662e766f6d09,0x2c34303166250920,0x3030386633663020,0x092020203b303030\n"
".quad 0x6d66090a31202f2f,0x3233662e6e722e61,0x2c35303166250920,0x25202c3439662520\n"
".quad 0x6625202c34303166,0x766f6d090a3b3539,0x662509203233662e,0x336630202c363031\n"
".quad 0x3b30303030303866,0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c373031,0x30316625202c3630,0x3b39396625202c30,0x33662e766f6d090a\n"
".quad 0x3830316625092032,0x303866336630202c,0x2020203b30303030,0x66090a31202f2f09\n"
".quad 0x33662e6e722e616d,0x3930316625092032,0x2c3830316625202c,0x202c313031662520\n"
".quad 0x090a3b3330316625,0x203233662e766f6d,0x202c303131662509,0x3030303866336630\n"
".quad 0x2f092020203b3030,0x616d66090a31202f,0x203233662e6e722e,0x202c313131662509\n"
".quad 0x6625202c36396625,0x316625202c303131,0x78616d090a3b3530,0x662509203233662e\n"
".quad 0x316625202c323131,0x31316625202c3730,0x2e78616d090a3b31,0x3166250920323366\n"
".quad 0x30316625202c3331,0x3231316625202c39,0x722e706372090a3b,0x2509203233662e6e\n"
".quad 0x6625202c34313166,0x756d090a3b333131,0x2509203233662e6c,0x6625202c35313166\n"
".quad 0x316625202c373031,0x6c756d090a3b3431,0x662509203233662e,0x316625202c363131\n"
".quad 0x31316625202c3131,0x2e6c756d090a3b34,0x3166250920323366,0x30316625202c3731\n"
".quad 0x3431316625202c39,0x662e6c756d090a3b,0x3131662509203233,0x3531316625202c38\n"
".quad 0x3b3030316625202c,0x33662e6c756d090a,0x3931316625092032,0x2c3531316625202c\n"
".quad 0x090a3b3539662520,0x203233662e6c756d,0x202c303231662509,0x25202c3531316625\n"
".quad 0x6d66090a3b373966,0x3233662e6e722e61,0x2c31323166250920,0x202c363131662520\n"
".quad 0x6625202c36396625,0x6d66090a3b383131,0x3233662e6e722e61,0x2c32323166250920\n"
".quad 0x25202c3439662520,0x6625202c36313166,0x6d66090a3b393131,0x3233662e6e722e61\n"
".quad 0x2c33323166250920,0x202c363131662520,0x6625202c35396625,0x6d66090a3b303231\n"
".quad 0x3233662e6e722e61,0x2c34323166250920,0x202c373131662520,0x25202c3130316625\n"
".quad 0x66090a3b31323166,0x33662e6e722e616d,0x3532316625092032,0x202c36396625202c\n"
".quad 0x25202c3731316625,0x66090a3b32323166,0x33662e6e722e616d,0x3632316625092032\n"
".quad 0x2c3731316625202c,0x202c303031662520,0x090a3b3332316625,0x203233662e78616d\n"
".quad 0x202c373231662509,0x25202c3532316625,0x6d090a3b36323166,0x09203233662e7861\n"
".quad 0x25202c3832316625,0x6625202c34323166,0x6372090a3b373231,0x3233662e6e722e70\n"
".quad 0x2c39323166250920,0x0a3b383231662520,0x363109636f6c2e09,0x6d090a3009303509\n"
".quad 0x09203233662e6c75,0x25202c3033316625,0x6625202c34323166,0x756d090a3b393231\n"
".quad 0x2509203233662e6c,0x6625202c31333166,0x316625202c353231,0x6c756d090a3b3932\n"
".quad 0x662509203233662e,0x316625202c323331,0x32316625202c3632,0x2e6c756d090a3b39\n"
".quad 0x3166250920323366,0x33316625202c3333,0x3b35396625202c32,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x396625202c343331,0x3133316625202c34,0x3b3333316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x396625202c353331,0x3033316625202c36\n"
".quad 0x3b3433316625202c,0x3109636f6c2e090a,0x090a300931350936,0x203233662e6c756d\n"
".quad 0x202c363331662509,0x25202c3233316625,0x6d66090a3b373966,0x3233662e6e722e61\n"
".quad 0x2c37333166250920,0x202c313331662520,0x6625202c35396625,0x6d66090a3b363331\n"
".quad 0x3233662e6e722e61,0x2c38333166250920,0x202c303331662520,0x25202c3030316625\n"
".quad 0x2e090a3b37333166,0x3509363109636f6c,0x6c756d090a300932,0x662509203233662e\n"
".quad 0x316625202c393331,0x30316625202c3233,0x2e616d66090a3b30,0x09203233662e6e72\n"
".quad 0x25202c3034316625,0x6625202c31333166,0x33316625202c3639,0x2e616d66090a3b39\n"
".quad 0x09203233662e6e72,0x25202c3134316625,0x6625202c30333166,0x316625202c313031\n"
".quad 0x6f6c2e090a3b3034,0x0938350936310963,0x662e78616d090a30,0x3431662509203233\n"
".quad 0x3533316625202c32,0x3b3833316625202c,0x33662e78616d090a,0x3334316625092032\n"
".quad 0x2c3234316625202c,0x0a3b313431662520,0x2e6e722e70637209,0x3166250920323366\n"
".quad 0x34316625202c3434,0x2e6c756d090a3b33,0x3166250920323366,0x34316625202c3534\n"
".quad 0x3533316625202c34,0x662e6c756d090a3b,0x3431662509203233,0x3434316625202c36\n"
".quad 0x3b3833316625202c,0x33662e6c756d090a,0x3734316625092032,0x2c3434316625202c\n"
".quad 0x0a3b313431662520,0x363109636f6c2e09,0x6d090a3009303509,0x09203233662e6c75\n"
".quad 0x25202c3834316625,0x6625202c36343166,0x616d66090a3b3539,0x203233662e6e722e\n"
".quad 0x202c393431662509,0x6625202c34396625,0x316625202c353431,0x616d66090a3b3834\n"
".quad 0x203233662e6e722e,0x202c303531662509,0x6625202c36396625,0x316625202c373431\n"
".quad 0x6f6c2e090a3b3934,0x0938350936310963,0x662e6c756d090a30,0x3531662509203233\n"
".quad 0x3634316625202c31,0x0a3b37396625202c,0x3233662e6c756d09,0x2c32353166250920\n"
".quad 0x202c363431662520,0x090a3b3030316625,0x662e6e722e616d66,0x3531662509203233\n"
".quad 0x3534316625202c33,0x202c35396625202c,0x090a3b3135316625,0x662e6e722e616d66\n"
".quad 0x3531662509203233,0x3534316625202c34,0x202c36396625202c,0x090a3b3235316625\n"
".quad 0x662e6e722e616d66,0x3531662509203233,0x3734316625202c35,0x2c3030316625202c\n"
".quad 0x0a3b333531662520,0x2e6e722e616d6609,0x3166250920323366,0x34316625202c3635\n"
".quad 0x3130316625202c37,0x3b3435316625202c,0x33662e78616d090a,0x3735316625092032\n"
".quad 0x2c3535316625202c,0x0a3b303531662520,0x3233662e78616d09,0x2c38353166250920\n"
".quad 0x202c363531662520,0x090a3b3735316625,0x662e6e722e706372,0x3531662509203233\n"
".quad 0x3835316625202c39,0x662e6c756d090a3b,0x3631662509203233,0x3535316625202c30\n"
".quad 0x3b3935316625202c,0x33662e6c756d090a,0x3136316625092032,0x2c3635316625202c\n"
".quad 0x0a3b393531662520,0x3233662e6c756d09,0x2c32363166250920,0x202c393531662520\n"
".quad 0x090a3b3035316625,0x09363109636f6c2e,0x756d090a30093235,0x2509203233662e6c\n"
".quad 0x6625202c33363166,0x316625202c303631,0x616d66090a3b3030,0x203233662e6e722e\n"
".quad 0x202c343631662509,0x25202c3236316625,0x316625202c363966,0x616d66090a3b3336\n"
".quad 0x203233662e6e722e,0x202c353631662509,0x25202c3136316625,0x6625202c31303166\n"
".quad 0x6c2e090a3b343631,0x343509363109636f,0x2e6c756d090a3009,0x3166250920323366\n"
".quad 0x36316625202c3636,0x3b35396625202c30,0x33662e6c756d090a,0x3736316625092032\n"
".quad 0x2c3036316625202c,0x090a3b3739662520,0x662e6e722e616d66,0x3631662509203233\n"
".quad 0x2c34396625202c38,0x202c323631662520,0x090a3b3636316625,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x3236316625202c39,0x202c35396625202c,0x090a3b3736316625\n"
".quad 0x662e6e722e616d66,0x3731662509203233,0x2c36396625202c30,0x202c313631662520\n"
".quad 0x090a3b3836316625,0x662e6e722e616d66,0x3731662509203233,0x3136316625202c31\n"
".quad 0x2c3030316625202c,0x0a3b393631662520,0x3233662e78616d09,0x2c32373166250920\n"
".quad 0x202c303731662520,0x090a3b3137316625,0x203233662e78616d,0x202c333731662509\n"
".quad 0x25202c3237316625,0x72090a3b35363166,0x33662e6e722e7063,0x3437316625092032\n"
".quad 0x3b3337316625202c,0x3109636f6c2e090a,0x090a300938350936,0x203233662e6c756d\n"
".quad 0x202c353731662509,0x25202c3037316625,0x6d090a3b34373166,0x09203233662e6c75\n"
".quad 0x25202c3637316625,0x6625202c31373166,0x6c2e090a3b343731,0x303509363109636f\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x37316625202c3737,0x3536316625202c34\n"
".quad 0x662e6c756d090a3b,0x3731662509203233,0x3637316625202c38,0x0a3b35396625202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x34396625202c3937,0x2c3537316625202c\n"
".quad 0x0a3b383731662520,0x2e6e722e616d6609,0x3166250920323366,0x36396625202c3038\n"
".quad 0x2c3737316625202c,0x0a3b393731662520,0x363109636f6c2e09,0x6d090a3009313509\n"
".quad 0x09203233662e6c75,0x25202c3138316625,0x6625202c36373166,0x616d66090a3b3739\n"
".quad 0x203233662e6e722e,0x202c323831662509,0x25202c3537316625,0x316625202c353966\n"
".quad 0x616d66090a3b3138,0x203233662e6e722e,0x202c333831662509,0x25202c3737316625\n"
".quad 0x6625202c30303166,0x6c2e090a3b323831,0x323509363109636f,0x2e6c756d090a3009\n"
".quad 0x3166250920323366,0x37316625202c3438,0x3030316625202c36,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c35383166,0x396625202c353731,0x3438316625202c36\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36383166,0x316625202c373731\n"
".quad 0x38316625202c3130,0x636f6c2e090a3b35,0x3009383509363109,0x33662e78616d090a\n"
".quad 0x3738316625092032,0x2c3038316625202c,0x0a3b333831662520,0x3233662e78616d09\n"
".quad 0x2c38383166250920,0x202c373831662520,0x090a3b3638316625,0x662e6e722e706372\n"
".quad 0x3831662509203233,0x3838316625202c39,0x662e6c756d090a3b,0x3931662509203233\n"
".quad 0x3938316625202c30,0x3b3038316625202c,0x33662e6c756d090a,0x3139316625092032\n"
".quad 0x2c3938316625202c,0x0a3b333831662520,0x3233662e6c756d09,0x2c32393166250920\n"
".quad 0x202c393831662520,0x090a3b3638316625,0x09363109636f6c2e,0x756d090a30093035\n"
".quad 0x2509203233662e6c,0x6625202c33393166,0x396625202c313931,0x2e616d66090a3b35\n"
".quad 0x09203233662e6e72,0x25202c3439316625,0x316625202c343966,0x39316625202c3039\n"
".quad 0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3539316625,0x316625202c363966\n"
".quad 0x39316625202c3239,0x636f6c2e090a3b34,0x3009383509363109,0x33662e6c756d090a\n"
".quad 0x3639316625092032,0x2c3139316625202c,0x090a3b3739662520,0x203233662e6c756d\n"
".quad 0x202c373931662509,0x25202c3139316625,0x66090a3b30303166,0x33662e6e722e616d\n"
".quad 0x3839316625092032,0x2c3039316625202c,0x25202c3539662520,0x66090a3b36393166\n"
".quad 0x33662e6e722e616d,0x3939316625092032,0x2c3039316625202c,0x25202c3639662520\n"
".quad 0x66090a3b37393166,0x33662e6e722e616d,0x3030326625092032,0x2c3239316625202c\n"
".quad 0x202c303031662520,0x090a3b3839316625,0x662e6e722e616d66,0x3032662509203233\n"
".quad 0x3239316625202c31,0x2c3130316625202c,0x0a3b393931662520,0x3233662e78616d09\n"
".quad 0x2c32303266250920,0x202c303032662520,0x090a3b3539316625,0x203233662e78616d\n"
".quad 0x202c333032662509,0x25202c3130326625,0x72090a3b32303266,0x33662e6e722e7063\n"
".quad 0x3430326625092032,0x3b3330326625202c,0x33662e6c756d090a,0x3530326625092032\n"
".quad 0x2c3030326625202c,0x0a3b343032662520,0x3233662e6c756d09,0x2c36303266250920\n"
".quad 0x202c313032662520,0x090a3b3430326625,0x203233662e6c756d,0x202c373032662509\n"
".quad 0x25202c3430326625,0x2e090a3b35393166,0x3509363109636f6c,0x6c756d090a300932\n"
".quad 0x662509203233662e,0x326625202c383032,0x30316625202c3530,0x2e616d66090a3b30\n"
".quad 0x09203233662e6e72,0x25202c3930326625,0x6625202c37303266,0x30326625202c3639\n"
".quad 0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3031326625,0x6625202c36303266\n"
".quad 0x326625202c313031,0x6f6c2e090a3b3930,0x0934350936310963,0x662e6c756d090a30\n"
".quad 0x3132662509203233,0x3530326625202c31,0x0a3b35396625202c,0x3233662e6c756d09\n"
".quad 0x2c32313266250920,0x202c353032662520,0x66090a3b37396625,0x33662e6e722e616d\n"
".quad 0x3331326625092032,0x202c34396625202c,0x25202c3730326625,0x66090a3b31313266\n"
".quad 0x33662e6e722e616d,0x3431326625092032,0x2c3730326625202c,0x25202c3539662520\n"
".quad 0x66090a3b32313266,0x33662e6e722e616d,0x3531326625092032,0x202c36396625202c\n"
".quad 0x25202c3630326625,0x66090a3b33313266,0x33662e6e722e616d,0x3631326625092032\n"
".quad 0x2c3630326625202c,0x202c303031662520,0x090a3b3431326625,0x203233662e78616d\n"
".quad 0x202c373132662509,0x25202c3531326625,0x6d090a3b36313266,0x09203233662e7861\n"
".quad 0x25202c3831326625,0x6625202c37313266,0x6372090a3b303132,0x3233662e6e722e70\n"
".quad 0x2c39313266250920,0x0a3b383132662520,0x363109636f6c2e09,0x6d090a3009383509\n"
".quad 0x09203233662e6c75,0x25202c3032326625,0x6625202c35313266,0x756d090a3b393132\n"
".quad 0x2509203233662e6c,0x6625202c31323266,0x326625202c363132,0x6f6c2e090a3b3931\n"
".quad 0x3136310937310963,0x2e6c756d090a3009,0x09203233752e6f6c,0x7225202c32367225\n"
".quad 0x40090a3b34202c31,0x6172622031702521,0x5f385f744c240920,0x090a3b3634353434\n"
".quad 0x09373109636f6c2e,0x6d090a3009343631,0x09203233752e766f,0x5f5f202c33367225\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f35335f34383837,0x736e6f635f6e6f6e\n"
".quad 0x335f5f7370645f74,0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c313172\n"
".quad 0x61090a3b3231202c,0x09203233752e6464,0x7225202c32317225,0x3b337225202c3131\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x202c323232662509,0x5d342b323172255b\n"
".quad 0x662e6c756d090a3b,0x3232662509203233,0x3232326625202c33,0x3b3132326625202c\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x202c343232662509,0x5d302b323172255b\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c35323266,0x326625202c343232\n"
".quad 0x32326625202c3032,0x732e646c090a3b33,0x33662e6465726168,0x3632326625092032\n"
".quad 0x2b323172255b202c,0x6c756d090a3b5d38,0x662509203233662e,0x326625202c373232\n"
".quad 0x31326625202c3931,0x2e616d66090a3b30,0x09203233662e6e72,0x25202c3832326625\n"
".quad 0x6625202c36323266,0x326625202c373232,0x646461090a3b3532,0x722509203233752e\n"
".quad 0x32367225202c3436,0x0a3b33367225202c,0x726168732e747309,0x09203233662e6465\n"
".quad 0x5d302b343672255b,0x3b3832326625202c,0x345f385f744c240a,0x6d090a3a36343534\n"
".quad 0x09203233752e766f,0x5f5f202c33367225,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f35335f34383837,0x736e6f635f6e6f6e,0x335f5f7370645f74,0x09636f6c2e090a3b\n"
".quad 0x3009373631093731,0x79732e726162090a,0x090a3b300920636e,0x7262203170252140\n"
".quad 0x385f744c24092061,0x0a3b38353035345f,0x373109636f6c2e09,0x090a300930373109\n"
".quad 0x203233752e766f6d,0x30202c3536722509,0x2e70746573090a3b,0x09203233752e656e\n"
".quad 0x317225202c347025,0x0a3b35367225202c,0x7262203470254009,0x385f744c24092061\n"
".quad 0x0a3b30373535345f,0x3233752e766f6d09,0x202c363672250920,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3336313833,0x6e6f635f6e6f6e5f\n"
".quad 0x73666572785f7473,0x6d090a3b30343731,0x09203233732e766f,0x7225202c37367225\n"
".quad 0x646461090a3b3336,0x722509203233752e,0x33367225202c3836,0x6d090a3b3436202c\n"
".quad 0x09203233732e766f,0x7225202c39367225,0x2e646c090a3b3636,0x762e646572616873\n"
".quad 0x7b09203233662e34,0x66252c3932326625,0x333266252c303332,0x7d32333266252c31\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x383837335f726176,0x6e6f6e5f35335f34\n"
".quad 0x645f74736e6f635f,0x5d302b335f5f7370,0x68732e646c090a3b,0x2e34762e64657261\n"
".quad 0x66257b0920323366,0x333266252c333332,0x2c35333266252c34,0x202c7d3633326625\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34383837335f72,0x635f6e6f6e5f3533\n"
".quad 0x7370645f74736e6f,0x3b5d36312b335f5f,0x6168732e646c090a,0x662e34762e646572\n"
".quad 0x3266257b09203233,0x38333266252c3733,0x252c39333266252c,0x5b202c7d30343266\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f34383837335f,0x6f635f6e6f6e5f35\n"
".quad 0x5f7370645f74736e,0x0a3b5d32332b335f,0x726168732e646c09,0x33662e34762e6465\n"
".quad 0x343266257b092032,0x2c32343266252c31,0x66252c3334326625,0x5f5b202c7d343432\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x35335f3438383733,0x6e6f635f6e6f6e5f\n"
".quad 0x5f5f7370645f7473,0x240a3b5d38342b33,0x3536345f385f744c,0x3c2f2f200a3a3439\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x30373120656e696c,0x6e697473656e202c\n"
".quad 0x3a68747065642067,0x72657469202c3120,0x203a736e6f697461,0x636f6c2e090a3631\n"
".quad 0x3009383909373109,0x6168732e646c090a,0x203233662e646572,0x202c353432662509\n"
".quad 0x5d302b373672255b,0x672e746573090a3b,0x33662e3233752e74,0x2c30377225092032\n"
".quad 0x202c353432662520,0x090a3b3334326625,0x203233732e67656e,0x25202c3137722509\n"
".quad 0x6573090a3b303772,0x3233752e74672e74,0x722509203233662e,0x34326625202c3237\n"
".quad 0x3434326625202c35,0x732e67656e090a3b,0x3337722509203233,0x0a3b32377225202c\n"
".quad 0x3233732e64646109,0x202c343772250920,0x7225202c31377225,0x746573090a3b3337\n"
".quad 0x2e3233752e74672e,0x3772250920323366,0x3534326625202c35,0x3b3134326625202c\n"
".quad 0x33732e67656e090a,0x2c36377225092032,0x090a3b3537722520,0x752e74672e746573\n"
".quad 0x09203233662e3233,0x6625202c37377225,0x326625202c353432,0x67656e090a3b3234\n"
".quad 0x722509203233732e,0x37377225202c3837,0x732e646461090a3b,0x3937722509203233\n"
".quad 0x202c36377225202c,0x73090a3b38377225,0x33752e74672e7465,0x2509203233662e32\n"
".quad 0x326625202c303872,0x33326625202c3534,0x2e67656e090a3b30,0x3872250920323373\n"
".quad 0x3b30387225202c31,0x74672e746573090a,0x3233662e3233752e,0x202c323872250920\n"
".quad 0x25202c3534326625,0x6e090a3b30343266,0x09203233732e6765,0x7225202c33387225\n"
".quad 0x646461090a3b3238,0x722509203233732e,0x31387225202c3438,0x0a3b33387225202c\n"
".quad 0x2e74672e74657309,0x203233662e323375,0x25202c3538722509,0x6625202c35343266\n"
".quad 0x656e090a3b393232,0x2509203233732e67,0x387225202c363872,0x2e746573090a3b35\n"
".quad 0x662e3233752e7467,0x3738722509203233,0x2c3534326625202c,0x0a3b313332662520\n"
".quad 0x3233732e67656e09,0x202c383872250920,0x61090a3b37387225,0x09203233732e6464\n"
".quad 0x7225202c39387225,0x38387225202c3638,0x672e746573090a3b,0x33662e3233752e74\n"
".quad 0x2c30397225092032,0x202c353432662520,0x090a3b3233326625,0x203233732e67656e\n"
".quad 0x25202c3139722509,0x6573090a3b303972,0x3233752e74672e74,0x722509203233662e\n"
".quad 0x34326625202c3239,0x3333326625202c35,0x732e67656e090a3b,0x3339722509203233\n"
".quad 0x0a3b32397225202c,0x3233732e64646109,0x202c343972250920,0x7225202c31397225\n"
".quad 0x746573090a3b3339,0x2e3233752e74672e,0x3972250920323366,0x3534326625202c35\n"
".quad 0x3b3433326625202c,0x33732e67656e090a,0x2c36397225092032,0x090a3b3539722520\n"
".quad 0x752e74672e746573,0x09203233662e3233,0x6625202c37397225,0x326625202c353432\n"
".quad 0x67656e090a3b3533,0x722509203233732e,0x37397225202c3839,0x732e646461090a3b\n"
".quad 0x3939722509203233,0x202c36397225202c,0x73090a3b38397225,0x33752e74672e7465\n"
".quad 0x2509203233662e32,0x6625202c30303172,0x326625202c353432,0x67656e090a3b3633\n"
".quad 0x722509203233732e,0x317225202c313031,0x746573090a3b3030,0x2e3233752e74672e\n"
".quad 0x3172250920323366,0x34326625202c3230,0x3733326625202c35,0x732e67656e090a3b\n"
".quad 0x3031722509203233,0x3230317225202c33,0x732e646461090a3b,0x3031722509203233\n"
".quad 0x3130317225202c34,0x3b3330317225202c,0x74672e746573090a,0x3233662e3233752e\n"
".quad 0x2c35303172250920,0x202c353432662520,0x090a3b3833326625,0x203233732e67656e\n"
".quad 0x202c363031722509,0x090a3b3530317225,0x752e74672e746573,0x09203233662e3233\n"
".quad 0x25202c3730317225,0x6625202c35343266,0x656e090a3b393332,0x2509203233732e67\n"
".quad 0x7225202c38303172,0x6461090a3b373031,0x2509203233732e64,0x7225202c39303172\n"
".quad 0x317225202c363031,0x646461090a3b3830,0x722509203233732e,0x317225202c303131\n"
".quad 0x30317225202c3430,0x2e646461090a3b39,0x3172250920323373,0x39397225202c3131\n"
".quad 0x3b3031317225202c,0x33732e646461090a,0x3231317225092032,0x202c34397225202c\n"
".quad 0x090a3b3131317225,0x203233732e646461,0x202c333131722509,0x7225202c39387225\n"
".quad 0x6461090a3b323131,0x2509203233732e64,0x7225202c34313172,0x31317225202c3438\n"
".quad 0x2e646461090a3b33,0x3172250920323373,0x39377225202c3531,0x3b3431317225202c\n"
".quad 0x33732e646461090a,0x3631317225092032,0x202c34377225202c,0x090a3b3531317225\n"
".quad 0x65726168732e7473,0x5b09203233732e64,0x2c5d302b39367225,0x0a3b363131722520\n"
".quad 0x3233752e64646109,0x202c393672250920,0x3b34202c39367225,0x33752e646461090a\n"
".quad 0x2c37367225092032,0x34202c3736722520,0x2e70746573090a3b,0x09203233752e656e\n"
".quad 0x367225202c357025,0x3b38367225202c37,0x622035702540090a,0x5f744c2409206172\n"
".quad 0x3b34393536345f38,0x33732e766f6d090a,0x3731317225092032,0x744c240a3b30202c\n"
".quad 0x38313637345f385f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x6e202c383920656e,0x6420676e69747365,0x2c31203a68747065,0x6974617265746920\n"
".quad 0x0a3531203a736e6f,0x3233732e766f6d09,0x2c38313172250920,0x5f744c240a3b3020\n"
".quad 0x3a36383338345f38,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x656e202c38392065,0x656420676e697473,0x202c32203a687470,0x6f69746172657469\n"
".quad 0x090a3631203a736e,0x09373109636f6c2e,0x73090a3009363031,0x732e656c2e707465\n"
".quad 0x2c36702509203233,0x202c383131722520,0x090a3b3731317225,0x6172622036702540\n"
".quad 0x5f385f744c240920,0x200a3b3833313935,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3839,0x64656c6562616c20\n"
".quad 0x345f385f744c2420,0x756d090a36383338,0x3233752e6f6c2e6c,0x2c39313172250920\n"
".quad 0x202c383131722520,0x2e646461090a3b34,0x3172250920323375,0x31317225202c3032\n"
".quad 0x3b36367225202c39,0x6168732e646c090a,0x203233732e646572,0x202c313231722509\n"
".quad 0x302b30323172255b,0x2e6c756d090a3b5d,0x09203233752e6f6c,0x25202c3232317225\n"
".quad 0x3b34202c37313172,0x33752e646461090a,0x3332317225092032,0x202c36367225202c\n"
".quad 0x090a3b3232317225,0x65726168732e646c,0x2509203233732e64,0x255b202c34323172\n"
".quad 0x3b5d302b33323172,0x6e2e70746573090a,0x2509203233732e65,0x32317225202c3770\n"
".quad 0x3132317225202c34,0x2037702540090a3b,0x744c240920617262,0x38333139355f385f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c383920656e,0x6562616c20646165,0x5f744c242064656c,0x0a36383338345f38\n"
".quad 0x3233732e64646109,0x2c35323172250920,0x202c313231722520,0x732e7473090a3b31\n"
".quad 0x33732e6465726168,0x323172255b092032,0x7225202c5d302b30,0x744c240a3b353231\n"
".quad 0x38333139355f385f,0x335f385f4c240a3a,0x2f200a3a32343835,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3920656e696c2079,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x38345f385f744c24,0x646461090a363833,0x722509203233732e\n"
".quad 0x317225202c383131,0x090a3b31202c3831,0x203233752e766f6d,0x202c363231722509\n"
".quad 0x746573090a3b3631,0x3233732e656e2e70,0x25202c3870250920,0x7225202c38313172\n"
".quad 0x2540090a3b363231,0x0920617262203870,0x38345f385f744c24,0x2f2f200a3b363833\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383920656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3637345f385f744c,0x2e646461090a3831\n"
".quad 0x3172250920323373,0x31317225202c3731,0x6d090a3b31202c37,0x09203233752e766f\n"
".quad 0x31202c3732317225,0x70746573090a3b35,0x203233732e656e2e,0x7225202c39702509\n"
".quad 0x317225202c373131,0x702540090a3b3732,0x2409206172622039,0x3637345f385f744c\n"
".quad 0x5f744c240a3b3831,0x3a30373535345f38,0x3109636f6c2e090a,0x0a30093037310937\n"
".quad 0x3233752e766f6d09,0x202c363672250920,0x5f5f616475635f5f,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x33335f3336313833,0x6e6f635f6e6f6e5f,0x73666572785f7473\n"
".quad 0x2e090a3b30343731,0x3109373109636f6c,0x756d090a30093237,0x3233752e6f6c2e6c\n"
".quad 0x202c313172250920,0x3b3231202c317225,0x33752e646461090a,0x2c32317225092032\n"
".quad 0x25202c3131722520,0x2e646c090a3b3372,0x662e646572616873,0x3432662509203233\n"
".quad 0x323172255b202c36,0x6f6d090a3b5d302b,0x2509203233662e76,0x6625202c37343266\n"
".quad 0x646c090a3b363432,0x2e6465726168732e,0x3266250920323366,0x3172255b202c3834\n"
".quad 0x6d090a3b5d342b32,0x09203233662e766f,0x25202c3934326625,0x6c090a3b38343266\n"
".quad 0x6465726168732e64,0x662509203233662e,0x72255b202c303532,0x090a3b5d382b3231\n"
".quad 0x203233662e766f6d,0x202c313532662509,0x240a3b3035326625,0x3035345f385f744c\n"
".quad 0x766f6d090a3a3835,0x722509203233752e,0x75635f5f202c3636,0x6475635f5f5f6164\n"
".quad 0x5f6c61636f6c5f61,0x363138335f726176,0x6e6f6e5f33335f33,0x785f74736e6f635f\n"
".quad 0x3034373173666572,0x09636f6c2e090a3b,0x3009353731093731,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x7262203170252140,0x385f744c24092061,0x0a3b34353139345f\n"
".quad 0x373109636f6c2e09,0x090a300938373109,0x203233752e646461,0x202c383231722509\n"
".quad 0x7225202c32367225,0x2e646c090a3b3636,0x752e646572616873,0x3231722509203233\n"
".quad 0x323172255b202c39,0x6d090a3b5d302b38,0x33752e6f6c2e6c75,0x3033317225092032\n"
".quad 0x2c3932317225202c,0x6461090a3b323120,0x2509203233752e64,0x7225202c31333172\n"
".quad 0x337225202c303331,0x662e766f6d090a3b,0x3532662509203233,0x3734326625202c32\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x31333172255b0920,0x326625202c5d302b\n"
".quad 0x766f6d090a3b3235,0x662509203233662e,0x326625202c333532,0x2e7473090a3b3934\n"
".quad 0x662e646572616873,0x3172255b09203233,0x25202c5d342b3133,0x6d090a3b33353266\n"
".quad 0x09203233662e766f,0x25202c3435326625,0x73090a3b31353266,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x2c5d382b31333172,0x0a3b343532662520,0x39345f385f744c24\n"
".quad 0x6c2e090a3a343531,0x313509373109636f,0x726162090a300939,0x300920636e79732e\n"
".quad 0x09636f6c2e090a3b,0x3009363235093731,0x33732e766f6d090a,0x3233317225092032\n"
".quad 0x6f6d090a3b30202c,0x2509203233662e76,0x6630202c35353266,0x6666666666376637\n"
".quad 0x202f2f092020203b,0x6532383230342e33,0x766f6d090a38332b,0x722509203233752e\n"
".quad 0x635f5f202c333331,0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f34335f373330\n"
".quad 0x74736e6f635f6e6f,0x756d7265705f735f,0x5f736e6f69746174,0x766f6d090a3b325f\n"
".quad 0x722509203233752e,0x6f7270202c343331,0x6f6d090a3b347364,0x2509203233752e76\n"
".quad 0x6c61202c35333172,0x656c626154616870,0x385f744c240a3b34,0x0a3a38373130355f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x656e202c36323520\n"
".quad 0x656420676e697473,0x202c31203a687470,0x6574616d69747365,0x7461726574692064\n"
".quad 0x3631203a736e6f69,0x3109636f6c2e090a,0x0a30093534330937,0x3233732e64646109\n"
".quad 0x2c36333172250920,0x202c323331722520,0x6f6d090a3b317225,0x2509203233752e76\n"
".quad 0x3939202c37333172,0x70746573090a3b31,0x203233732e74672e,0x25202c3031702509\n"
".quad 0x7225202c36333172,0x2540090a3b373331,0x2061726220303170,0x325f385f744c2409\n"
".quad 0x3c2f2f200a3b3835,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323520656e696c,0x6c2064616568202c,0x242064656c656261,0x3130355f385f744c\n"
".quad 0x636f6c2e090a3837,0x0938343309373109,0x6c2e6c756d090a30,0x2509203233752e6f\n"
".quad 0x7225202c38333172,0x0a3b34202c363331,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5b202c39333172,0x726170616475635f,0x6d6f63385a5f5f6d,0x6a4b507373657270\n"
".quad 0x6e697535505f3053,0x756d7265705f3274,0x5d736e6f69746174,0x752e646461090a3b\n"
".quad 0x3431722509203233,0x3933317225202c30,0x3b3833317225202c,0x6f6c672e646c090a\n"
".quad 0x203233752e6c6162,0x202c313431722509,0x302b30343172255b,0x2e766f6d090a3b5d\n"
".quad 0x3172250920323375,0x3b393531202c3234,0x672e70746573090a,0x2509203233732e74\n"
".quad 0x317225202c313170,0x34317225202c3633,0x31702540090a3b32,0x2409206172622031\n"
".quad 0x3430355f385f744c,0x3c2f2f200a3b3433,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x36323520656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3130355f385f744c,0x636f6c2e090a3837,0x0939343309373109,0x752e646461090a30\n"
".quad 0x3431722509203233,0x3833317225202c33,0x3b3333317225202c,0x6168732e7473090a\n"
".quad 0x203233752e646572,0x2b33343172255b09,0x34317225202c5d30,0x385f744c240a3b31\n"
".quad 0x0a3a34333430355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36323520,0x6c6562616c206461,0x385f744c24206465\n"
".quad 0x090a38373130355f,0x09373109636f6c2e,0x6d090a3009313533,0x09203233732e766f\n"
".quad 0x30202c3434317225,0x732e766f6d090a3b,0x3431722509203233,0x0a3b337225202c35\n"
".quad 0x3233732e766f6d09,0x2c36343172250920,0x766f6d090a3b3020,0x662509203233662e\n"
".quad 0x306630202c363532,0x3b30303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x3735326625092032,0x303030306630202c,0x2020203b30303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x30202c3835326625,0x3030303030303066,0x2f2f092020203b30\n"
".quad 0x385f744c240a3020,0x0a3a38353431355f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x656e202c31353320,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6f69746172657469,0x090a3631203a736e,0x09373109636f6c2e,0x73090a3009343232\n"
".quad 0x09203233752e7268,0x25202c3734317225,0x7225202c31343172,0x6e61090a3b343431\n"
".quad 0x2509203233622e64,0x7225202c38343172,0x0a3b33202c373431,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x34317225202c3934,0x61090a3b34202c38,0x09203233752e6464\n"
".quad 0x25202c3035317225,0x7225202c39343172,0x646c090a3b353331,0x662e74736e6f632e\n"
".quad 0x3532662509203233,0x353172255b202c39,0x6c090a3b5d302b30,0x6465726168732e64\n"
".quad 0x662509203233662e,0x72255b202c303632,0x0a3b5d302b353431,0x2e6e722e616d6609\n"
".quad 0x3266250920323366,0x36326625202c3835,0x3935326625202c30,0x3b3835326625202c\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x202c313632662509,0x342b35343172255b\n"
".quad 0x2e616d66090a3b5d,0x09203233662e6e72,0x25202c3735326625,0x6625202c31363266\n"
".quad 0x326625202c393532,0x2e646c090a3b3735,0x662e646572616873,0x3632662509203233\n"
".quad 0x343172255b202c32,0x66090a3b5d382b35,0x33662e6e722e616d,0x3635326625092032\n"
".quad 0x2c3236326625202c,0x202c393532662520,0x090a3b3635326625,0x09373109636f6c2e\n"
".quad 0x61090a3009353232,0x09203233752e6464,0x25202c3135317225,0x7225202c39343172\n"
".quad 0x646c090a3b343331,0x732e74736e6f632e,0x3531722509203233,0x353172255b202c32\n"
".quad 0x61090a3b5d302b31,0x09203233732e6464,0x25202c3634317225,0x7225202c32353172\n"
".quad 0x6461090a3b363431,0x2509203233752e64,0x7225202c35343172,0x3b3231202c353431\n"
".quad 0x33732e646461090a,0x3434317225092032,0x2c3434317225202c,0x766f6d090a3b3220\n"
".quad 0x722509203233752e,0x3b3233202c333531,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x317225202c323170,0x35317225202c3434,0x31702540090a3b33,0x2409206172622032\n"
".quad 0x3431355f385f744c,0x3c2f2f200a3b3835,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x36323520656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3130355f385f744c,0x636f6c2e090a3837,0x0933363209373109,0x622e646e61090a30\n"
".quad 0x3531722509203233,0x3634317225202c34,0x090a3b353532202c,0x203233732e726873\n"
".quad 0x202c353531722509,0x31202c3634317225,0x2e726873090a3b36,0x3172250920323373\n"
".quad 0x34317225202c3635,0x6c090a3b38202c36,0x6465726168732e64,0x203233662e34762e\n"
".quad 0x2c33363266257b09,0x66252c3436326625,0x202c7d5f2c353632,0x5f616475635f5f5b\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f32363138335f,0x6f635f6e6f6e5f36\n"
".quad 0x736d75735f74736e,0x3b5d302b38343531,0x33662e766f6d090a,0x3636326625092032\n"
".quad 0x303131346630202c,0x2020203b30303030,0x6d090a39202f2f09,0x09203233662e6c75\n"
".quad 0x25202c3736326625,0x6625202c33363266,0x6f6d090a3b363632,0x2509203233662e76\n"
".quad 0x6630202c38363266,0x3030303030313134,0x202f2f092020203b,0x662e6c756d090a39\n"
".quad 0x3632662509203233,0x3436326625202c39,0x3b3836326625202c,0x33662e766f6d090a\n"
".quad 0x3037326625092032,0x303131346630202c,0x2020203b30303030,0x6d090a39202f2f09\n"
".quad 0x09203233662e6c75,0x25202c3137326625,0x6625202c35363266,0x7663090a3b303732\n"
".quad 0x3233662e6e722e74,0x662509203233732e,0x317225202c323732,0x747663090a3b3435\n"
".quad 0x2e3233662e6e722e,0x3266250920323373,0x35317225202c3337,0x2e646e61090a3b35\n"
".quad 0x3172250920323362,0x35317225202c3735,0x0a3b353532202c36,0x3233662e62757309\n"
".quad 0x2c34373266250920,0x202c373632662520,0x090a3b3835326625,0x203233662e627573\n"
".quad 0x202c353732662509,0x25202c3936326625,0x73090a3b37353266,0x09203233662e6275\n"
".quad 0x25202c3637326625,0x6625202c31373266,0x756d090a3b363532,0x2509203233662e6c\n"
".quad 0x6625202c37373266,0x326625202c323732,0x747663090a3b3237,0x2e3233662e6e722e\n"
".quad 0x3266250920323373,0x35317225202c3837,0x2e6c756d090a3b37,0x3266250920323366\n"
".quad 0x37326625202c3937,0x3437326625202c32,0x662e6c756d090a3b,0x3832662509203233\n"
".quad 0x3237326625202c30,0x3b3537326625202c,0x33662e6c756d090a,0x3138326625092032\n"
".quad 0x2c3237326625202c,0x0a3b363732662520,0x3233662e6c756d09,0x2c32383266250920\n"
".quad 0x202c333732662520,0x090a3b3837326625,0x203233662e627573,0x202c333832662509\n"
".quad 0x25202c3238326625,0x6d090a3b37373266,0x09203233662e6c75,0x25202c3438326625\n"
".quad 0x6625202c38373266,0x756d090a3b383532,0x2509203233662e6c,0x6625202c35383266\n"
".quad 0x326625202c383732,0x6c756d090a3b3735,0x662509203233662e,0x326625202c363832\n"
".quad 0x35326625202c3837,0x2e706372090a3b36,0x09203233662e6e72,0x25202c3738326625\n"
".quad 0x73090a3b33383266,0x09203233662e6275,0x25202c3838326625,0x6625202c34383266\n"
".quad 0x7573090a3b393732,0x2509203233662e62,0x6625202c39383266,0x326625202c353832\n"
".quad 0x627573090a3b3038,0x662509203233662e,0x326625202c303932,0x38326625202c3638\n"
".quad 0x2e6c756d090a3b31,0x3266250920323366,0x38326625202c3139,0x3838326625202c37\n"
".quad 0x662e6c756d090a3b,0x3932662509203233,0x3738326625202c32,0x3b3938326625202c\n"
".quad 0x33662e6c756d090a,0x3339326625092032,0x2c3738326625202c,0x0a3b303932662520\n"
".quad 0x7461732e74766309,0x3233662e3233662e,0x2c34393266250920,0x0a3b313932662520\n"
".quad 0x7461732e74766309,0x3233662e3233662e,0x2c35393266250920,0x0a3b323932662520\n"
".quad 0x7461732e74766309,0x3233662e3233662e,0x2c36393266250920,0x0a3b333932662520\n"
".quad 0x3233662e766f6d09,0x2c37393266250920,0x3038663134663020,0x092020203b303030\n"
".quad 0x6d090a3133202f2f,0x09203233662e6c75,0x25202c3839326625,0x6625202c34393266\n"
".quad 0x6f6d090a3b373932,0x2509203233662e76,0x6630202c39393266,0x3030303063373234\n"
".quad 0x202f2f092020203b,0x2e6c756d090a3336,0x3366250920323366,0x39326625202c3030\n"
".quad 0x3939326625202c35,0x662e766f6d090a3b,0x3033662509203233,0x6631346630202c31\n"
".quad 0x20203b3030303038,0x0a3133202f2f0920,0x3233662e6c756d09,0x2c32303366250920\n"
".quad 0x202c363932662520,0x090a3b3130336625,0x2e696e722e747663,0x203233662e323366\n"
".quad 0x202c333033662509,0x090a3b3839326625,0x2e696e722e747663,0x203233662e323366\n"
".quad 0x202c343033662509,0x090a3b3030336625,0x2e696e722e747663,0x203233662e323366\n"
".quad 0x202c353033662509,0x090a3b3230336625,0x2e697a722e747663,0x203233662e323375\n"
".quad 0x202c383531722509,0x090a3b3330336625,0x203233622e6c6873,0x202c393531722509\n"
".quad 0x31202c3835317225,0x2e747663090a3b31,0x2e3233752e697a72,0x3172250920323366\n"
".quad 0x30336625202c3036,0x2e6c6873090a3b34,0x3172250920323362,0x36317225202c3136\n"
".quad 0x6f090a3b35202c30,0x2509203233622e72,0x7225202c32363172,0x317225202c393531\n"
".quad 0x747663090a3b3136,0x3233752e697a722e,0x722509203233662e,0x336625202c333631\n"
".quad 0x2e726f090a3b3530,0x3172250920323362,0x36317225202c3436,0x3336317225202c32\n"
".quad 0x09636f6c2e090a3b,0x3009343632093731,0x33662e6c756d090a,0x3630336625092032\n"
".quad 0x2c3237326625202c,0x0a3b383532662520,0x3233662e6c756d09,0x2c37303366250920\n"
".quad 0x202c323732662520,0x090a3b3735326625,0x203233662e6c756d,0x202c383033662509\n"
".quad 0x25202c3237326625,0x6d090a3b36353266,0x09203233662e6c75,0x25202c3930336625\n"
".quad 0x6625202c33373266,0x756d090a3b343732,0x2509203233662e6c,0x6625202c30313366\n"
".quad 0x326625202c333732,0x6c756d090a3b3537,0x662509203233662e,0x326625202c313133\n"
".quad 0x37326625202c3337,0x2e627573090a3b36,0x3366250920323366,0x30336625202c3231\n"
".quad 0x3630336625202c39,0x662e627573090a3b,0x3133662509203233,0x3031336625202c33\n"
".quad 0x3b3730336625202c,0x33662e627573090a,0x3431336625092032,0x2c3131336625202c\n"
".quad 0x0a3b383033662520,0x3233662e6c756d09,0x2c35313366250920,0x202c323133662520\n"
".quad 0x090a3b3738326625,0x203233662e6c756d,0x202c363133662509,0x25202c3331336625\n"
".quad 0x6d090a3b37383266,0x09203233662e6c75,0x25202c3731336625,0x6625202c34313366\n"
".quad 0x7663090a3b373832,0x33662e7461732e74,0x2509203233662e32,0x6625202c38313366\n"
".quad 0x7663090a3b353133,0x33662e7461732e74,0x2509203233662e32,0x6625202c39313366\n"
".quad 0x7663090a3b363133,0x33662e7461732e74,0x2509203233662e32,0x6625202c30323366\n"
".quad 0x6f6d090a3b373133,0x2509203233662e76,0x6630202c31323366,0x3030303038663134\n"
".quad 0x202f2f092020203b,0x2e6c756d090a3133,0x3366250920323366,0x31336625202c3232\n"
".quad 0x3132336625202c38,0x662e766f6d090a3b,0x3233662509203233,0x3732346630202c33\n"
".quad 0x20203b3030303063,0x0a3336202f2f0920,0x3233662e6c756d09,0x2c34323366250920\n"
".quad 0x202c393133662520,0x090a3b3332336625,0x203233662e766f6d,0x202c353233662509\n"
".quad 0x3030386631346630,0x2f092020203b3030,0x756d090a3133202f,0x2509203233662e6c\n"
".quad 0x6625202c36323366,0x336625202c303233,0x747663090a3b3532,0x3233662e696e722e\n"
".quad 0x662509203233662e,0x336625202c373233,0x747663090a3b3232,0x3233662e696e722e\n"
".quad 0x662509203233662e,0x336625202c383233,0x747663090a3b3432,0x3233662e696e722e\n"
".quad 0x662509203233662e,0x336625202c393233,0x747663090a3b3632,0x3233752e697a722e\n"
".quad 0x722509203233662e,0x336625202c353631,0x6c6873090a3b3732,0x722509203233622e\n"
".quad 0x317225202c363631,0x0a3b3131202c3536,0x697a722e74766309,0x3233662e3233752e\n"
".quad 0x2c37363172250920,0x0a3b383233662520,0x3233622e6c687309,0x2c38363172250920\n"
".quad 0x202c373631722520,0x622e726f090a3b35,0x3631722509203233,0x3636317225202c39\n"
".quad 0x3b3836317225202c,0x7a722e747663090a,0x33662e3233752e69,0x3037317225092032\n"
".quad 0x3b3932336625202c,0x3233622e726f090a,0x2c31373172250920,0x202c393631722520\n"
".quad 0x090a3b3037317225,0x09373109636f6c2e,0x6d090a3009373632,0x09203233662e766f\n"
".quad 0x30202c3033336625,0x3735333430643366,0x2f2f092020203b31,0x37323233302e3020\n"
".quad 0x2e6c756d090a3537,0x3366250920323366,0x30336625202c3133,0x3033336625202c33\n"
".quad 0x662e6c756d090a3b,0x3333662509203233,0x3133336625202c32,0x3b3133336625202c\n"
".quad 0x33662e766f6d090a,0x3333336625092032,0x313863336630202c,0x2020203b39313162\n"
".quad 0x31302e30202f2f09,0x6d090a3531333835,0x09203233662e6c75,0x25202c3433336625\n"
".quad 0x6625202c34303366,0x756d090a3b333333,0x2509203233662e6c,0x6625202c35333366\n"
".quad 0x336625202c343333,0x766f6d090a3b3433,0x662509203233662e,0x336630202c363333\n"
".quad 0x3b31373533343064,0x30202f2f09202020,0x353737323233302e,0x33662e6c756d090a\n"
".quad 0x3733336625092032,0x2c3530336625202c,0x0a3b363333662520,0x3233662e6c756d09\n"
".quad 0x2c38333366250920,0x202c373333662520,0x090a3b3733336625,0x203233662e766f6d\n"
".quad 0x202c393333662509,0x3533343064336630,0x2f092020203b3137,0x323233302e30202f\n"
".quad 0x6c756d090a353737,0x662509203233662e,0x336625202c303433,0x33336625202c3732\n"
".quad 0x2e6c756d090a3b39,0x3366250920323366,0x34336625202c3134,0x3034336625202c30\n"
".quad 0x662e766f6d090a3b,0x3433662509203233,0x3863336630202c32,0x20203b3931316231\n"
".quad 0x302e30202f2f0920,0x090a353133383531,0x203233662e6c756d,0x202c333433662509\n"
".quad 0x25202c3832336625,0x6d090a3b32343366,0x09203233662e6c75,0x25202c3434336625\n"
".quad 0x6625202c33343366,0x6f6d090a3b333433,0x2509203233662e76,0x6630202c35343366\n"
".quad 0x3137353334306433,0x202f2f092020203b,0x3737323233302e30,0x662e6c756d090a35\n"
".quad 0x3433662509203233,0x3932336625202c36,0x3b3534336625202c,0x33662e6c756d090a\n"
".quad 0x3734336625092032,0x2c3634336625202c,0x0a3b363433662520,0x3233662e6c756d09\n"
".quad 0x2c38343366250920,0x202c303433662520,0x090a3b3133336625,0x203233662e6c756d\n"
".quad 0x202c393433662509,0x25202c3334336625,0x6d090a3b34333366,0x09203233662e6c75\n"
".quad 0x25202c3035336625,0x6625202c36343366,0x756d090a3b373333,0x2509203233662e6c\n"
".quad 0x6625202c31353366,0x326625202c313333,0x6c756d090a3b3835,0x662509203233662e\n"
".quad 0x336625202c323533,0x35326625202c3433,0x2e6c756d090a3b37,0x3366250920323366\n"
".quad 0x33336625202c3335,0x3635326625202c37,0x662e6c756d090a3b,0x3533662509203233\n"
".quad 0x3437326625202c34,0x3b3034336625202c,0x33662e6c756d090a,0x3535336625092032\n"
".quad 0x2c3537326625202c,0x0a3b333433662520,0x3233662e6c756d09,0x2c36353366250920\n"
".quad 0x202c363732662520,0x090a3b3634336625,0x09373109636f6c2e,0x6d090a3009313533\n"
".quad 0x09203233662e6c75,0x25202c3735336625,0x6625202c32373266,0x756d090a3b393433\n"
".quad 0x2509203233662e6c,0x6625202c38353366,0x336625202c323732,0x6c756d090a3b3834\n"
".quad 0x662509203233662e,0x326625202c393533,0x35336625202c3237,0x2e6c756d090a3b30\n"
".quad 0x3366250920323366,0x37326625202c3036,0x3533336625202c33,0x662e6c756d090a3b\n"
".quad 0x3633662509203233,0x3337326625202c31,0x3b3233336625202c,0x33662e6c756d090a\n"
".quad 0x3236336625092032,0x2c3337326625202c,0x0a3b383333662520,0x3233662e62757309\n"
".quad 0x2c33363366250920,0x202c373533662520,0x090a3b3235336625,0x203233662e627573\n"
".quad 0x202c343633662509,0x25202c3835336625,0x73090a3b31353366,0x09203233662e6275\n"
".quad 0x25202c3536336625,0x6625202c39353366,0x756d090a3b333533,0x2509203233662e6c\n"
".quad 0x6625202c36363366,0x336625202c383732,0x6c756d090a3b3434,0x662509203233662e\n"
".quad 0x326625202c373633,0x34336625202c3837,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x37326625202c3836,0x3734336625202c38,0x662e627573090a3b,0x3633662509203233\n"
".quad 0x3336336625202c39,0x3b3535336625202c,0x33662e627573090a,0x3037336625092032\n"
".quad 0x2c3436336625202c,0x0a3b343533662520,0x3233662e62757309,0x2c31373366250920\n"
".quad 0x202c353633662520,0x090a3b3635336625,0x203233662e646461,0x202c323733662509\n"
".quad 0x25202c3036336625,0x61090a3b36363366,0x09203233662e6464,0x25202c3337336625\n"
".quad 0x6625202c31363366,0x6461090a3b373633,0x2509203233662e64,0x6625202c34373366\n"
".quad 0x336625202c323633,0x646461090a3b3836,0x662509203233662e,0x336625202c353733\n"
".quad 0x36336625202c3936,0x2e646461090a3b39,0x3366250920323366,0x37336625202c3637\n"
".quad 0x3037336625202c30,0x662e646461090a3b,0x3733662509203233,0x3137336625202c37\n"
".quad 0x3b3137336625202c,0x33662e646461090a,0x3837336625092032,0x2c3237336625202c\n"
".quad 0x0a3b353733662520,0x3233662e64646109,0x2c39373366250920,0x202c333733662520\n"
".quad 0x090a3b3637336625,0x203233662e646461,0x202c303833662509,0x25202c3437336625\n"
".quad 0x6c090a3b37373366,0x2e74736e6f632e64,0x3366250920323366,0x6f436b5b202c3138\n"
".quad 0x697274654d726f6c,0x6d090a3b5d342b63,0x09203233662e6c75,0x25202c3238336625\n"
".quad 0x6625202c31383366,0x646c090a3b383733,0x662e74736e6f632e,0x3833662509203233\n"
".quad 0x6c6f436b5b202c33,0x63697274654d726f,0x6d66090a3b5d302b,0x3233662e6e722e61\n"
".quad 0x2c34383366250920,0x202c393733662520,0x25202c3338336625,0x6c090a3b32383366\n"
".quad 0x2e74736e6f632e64,0x3366250920323366,0x6f436b5b202c3538,0x697274654d726f6c\n"
".quad 0x66090a3b5d382b63,0x33662e6e722e616d,0x3638336625092032,0x2c3038336625202c\n"
".quad 0x202c353833662520,0x090a3b3438336625,0x203233662e766f6d,0x202c373833662509\n"
".quad 0x6538336564336630,0x2f092020203b3933,0x313131312e30202f,0x2e6c756d090a3131\n"
".quad 0x3366250920323366,0x38336625202c3838,0x3738336625202c36,0x2e70746573090a3b\n"
".quad 0x09203233662e746c,0x6625202c33317025,0x326625202c383833,0x252140090a3b3535\n"
".quad 0x2061726220333170,0x355f385f744c2409,0x2f200a3b30373931,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3520656e696c2079,0x64616568202c3632\n"
".quad 0x64656c6562616c20,0x355f385f744c2420,0x6c2e090a38373130,0x353309373109636f\n"
".quad 0x766f6d090a300935,0x662509203233662e,0x336625202c353532,0x6f6c2e090a3b3838\n"
".quad 0x3635330937310963,0x2e766f6d090a3009,0x3172250920323373,0x34317225202c3237\n"
".quad 0x636f6c2e090a3b31,0x0937353309373109,0x752e747663090a30,0x09203233752e3631\n"
".quad 0x7225202c31687225,0x6c2e090a3b343631,0x353309373109636f,0x747663090a300938\n"
".quad 0x3233752e3631752e,0x202c326872250920,0x240a3b3137317225,0x3931355f385f744c\n"
".quad 0x3c2f2f200a3a3037,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36323520656e696c,0x6c2064616568202c,0x242064656c656261,0x3130355f385f744c\n"
".quad 0x636f6c2e090a3837,0x0932343309373109,0x732e646461090a30,0x3331722509203233\n"
".quad 0x3233317225202c32,0x6d090a3b3436202c,0x09203233752e766f,0x31202c3337317225\n"
".quad 0x6573090a3b343230,0x33732e656e2e7074,0x2c34317025092032,0x202c323331722520\n"
".quad 0x090a3b3337317225,0x7262203431702540,0x385f744c24092061,0x0a3b38373130355f\n"
".quad 0x35325f385f744c24,0x636f6c2e090a3a38,0x0930363309373109,0x752e747663090a30\n"
".quad 0x09203631752e3233,0x25202c3437317225,0x7663090a3b326872,0x31752e3233752e74\n"
".quad 0x3537317225092036,0x0a3b31687225202c,0x656c2e7074657309,0x702509203233752e\n"
".quad 0x37317225202c3531,0x3537317225202c34,0x3531702540090a3b,0x4c24092061726220\n"
".quad 0x333732355f385f74,0x636f6c2e090a3b38,0x3009323709373109,0x33732e766f6d090a\n"
".quad 0x3637317225092032,0x3b3437317225202c,0x3109636f6c2e090a,0x090a300933370937\n"
".quad 0x203233732e766f6d,0x202c343731722509,0x090a3b3537317225,0x09373109636f6c2e\n"
".quad 0x6f6d090a30093437,0x2509203233732e76,0x7225202c35373172,0x6c2e090a3b363731\n"
".quad 0x363309373109636f,0x766f6d090a300935,0x722509203233732e,0x317225202c373731\n"
".quad 0x726f78090a3b3237,0x722509203233622e,0x317225202c383731,0x31333431202c3737\n"
".quad 0x0a3b353637353536,0x3233732e766f6d09,0x2c32373172250920,0x0a3b383731722520\n"
".quad 0x32355f385f744c24,0x6f6d090a3a383337,0x2509203233732e76,0x3b30202c39373172\n"
".quad 0x33752e766f6d090a,0x3038317225092032,0x3373646f7270202c,0x752e766f6d090a3b\n"
".quad 0x3831722509203233,0x6168706c61202c31,0x0a3b33656c626154,0x33355f385f744c24\n"
".quad 0x2f2f200a3a323637,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x363320656e696c20\n"
".quad 0x697473656e202c35,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6c2e090a33203a73,0x373309373109636f,0x6c756d090a300931\n"
".quad 0x203233732e6f6c2e,0x202c323831722509,0x36202c3937317225,0x2e646461090a3b34\n"
".quad 0x3172250920323373,0x38317225202c3338,0x0a3b317225202c32,0x3233752e766f6d09\n"
".quad 0x2c34383172250920,0x73090a3b39353120,0x732e74672e707465,0x3631702509203233\n"
".quad 0x2c3338317225202c,0x0a3b343831722520,0x6220363170254009,0x57444c2409206172\n"
".quad 0x315a5f5f69646e65,0x6945747372696636,0x6f746365566e6567,0x5f3738315f665072\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35363320656e69,0x616c206461656820,0x4c242064656c6562,0x363733355f385f74\n"
".quad 0x09636f6c2e090a32,0x3009343733093731,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x317225202c353831,0x090a3b34202c3338,0x203233752e646461,0x202c363831722509\n"
".quad 0x25202c3333317225,0x6c090a3b35383172,0x6465726168732e64,0x722509203233752e\n"
".quad 0x72255b202c373831,0x0a3b5d302b363831,0x373109636f6c2e09,0x090a300935373309\n"
".quad 0x203233732e766f6d,0x202c383831722509,0x2e766f6d090a3b30,0x3172250920323373\n"
".quad 0x3b337225202c3938,0x33732e766f6d090a,0x3039317225092032,0x6f6d090a3b30202c\n"
".quad 0x2509203233662e76,0x6630202c39383366,0x3030303030303030,0x202f2f092020203b\n"
".quad 0x662e766f6d090a30,0x3933662509203233,0x3030306630202c30,0x20203b3030303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x202c313933662509,0x3030303030306630\n"
".quad 0x2f092020203b3030,0x5f744c240a30202f,0x3a30333534355f38,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3537332065,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x6974617265746920,0x0a3631203a736e6f,0x373109636f6c2e09\n"
".quad 0x090a300935383209,0x203233752e726873,0x202c313931722509,0x25202c3738317225\n"
".quad 0x61090a3b38383172,0x09203233622e646e,0x25202c3239317225,0x3b33202c31393172\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c333931,0x090a3b34202c3239\n"
".quad 0x203233752e646461,0x202c343931722509,0x25202c3339317225,0x6c090a3b31383172\n"
".quad 0x2e74736e6f632e64,0x3366250920323366,0x3172255b202c3239,0x090a3b5d302b3439\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x255b202c33393366,0x3b5d302b39383172\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x336625202c313933,0x39336625202c3339\n"
".quad 0x3139336625202c32,0x68732e646c090a3b,0x3233662e64657261,0x2c34393366250920\n"
".quad 0x2b39383172255b20,0x616d66090a3b5d34,0x203233662e6e722e,0x202c303933662509\n"
".quad 0x25202c3439336625,0x6625202c32393366,0x646c090a3b303933,0x2e6465726168732e\n"
".quad 0x3366250920323366,0x3172255b202c3539,0x090a3b5d382b3938,0x662e6e722e616d66\n"
".quad 0x3833662509203233,0x3539336625202c39,0x2c3239336625202c,0x0a3b393833662520\n"
".quad 0x373109636f6c2e09,0x090a300936383209,0x203233752e646461,0x202c353931722509\n"
".quad 0x25202c3339317225,0x6c090a3b30383172,0x2e74736e6f632e64,0x3172250920323373\n"
".quad 0x3172255b202c3639,0x090a3b5d302b3539,0x203233732e646461,0x202c303931722509\n"
".quad 0x25202c3639317225,0x61090a3b30393172,0x09203233752e6464,0x25202c3938317225\n"
".quad 0x3231202c39383172,0x732e646461090a3b,0x3831722509203233,0x3838317225202c38\n"
".quad 0x6f6d090a3b32202c,0x2509203233752e76,0x3233202c37393172,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c37317025,0x317225202c383831,0x702540090a3b3739\n"
".quad 0x0920617262203731,0x34355f385f744c24,0x2f2f200a3b303335,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363320656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x33355f385f744c24,0x6f6c2e090a323637,0x3332330937310963\n"
".quad 0x2e646e61090a3009,0x3172250920323362,0x39317225202c3839,0x0a3b353532202c30\n"
".quad 0x3233732e72687309,0x2c39393172250920,0x202c303931722520,0x726873090a3b3631\n"
".quad 0x722509203233732e,0x317225202c303032,0x090a3b38202c3039,0x65726168732e646c\n"
".quad 0x3233662e34762e64,0x36393366257b0920,0x252c37393366252c,0x2c7d5f2c38393366\n"
".quad 0x616475635f5f5b20,0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f32363138335f72\n"
".quad 0x635f6e6f6e5f3633,0x6d75735f74736e6f,0x5d302b3834353173,0x662e766f6d090a3b\n"
".quad 0x3933662509203233,0x3830346630202c39,0x20203b3030303030,0x090a34202f2f0920\n"
".quad 0x203233662e6c756d,0x202c303034662509,0x25202c3639336625,0x6d090a3b39393366\n"
".quad 0x09203233662e766f,0x30202c3130346625,0x3030303038303466,0x2f2f092020203b30\n"
".quad 0x2e6c756d090a3420,0x3466250920323366,0x39336625202c3230,0x3130346625202c37\n"
".quad 0x662e766f6d090a3b,0x3034662509203233,0x3830346630202c33,0x20203b3030303030\n"
".quad 0x090a34202f2f0920,0x203233662e6c756d,0x202c343034662509,0x25202c3839336625\n"
".quad 0x63090a3b33303466,0x33662e6e722e7476,0x2509203233732e32,0x7225202c35303466\n"
".quad 0x7663090a3b383931,0x3233662e6e722e74,0x662509203233732e,0x317225202c363034\n"
".quad 0x646e61090a3b3939,0x722509203233622e,0x327225202c313032,0x3b353532202c3030\n"
".quad 0x33662e627573090a,0x3730346625092032,0x2c3030346625202c,0x0a3b313933662520\n"
".quad 0x3233662e62757309,0x2c38303466250920,0x202c323034662520,0x090a3b3039336625\n"
".quad 0x203233662e627573,0x202c393034662509,0x25202c3430346625,0x6d090a3b39383366\n"
".quad 0x09203233662e6c75,0x25202c3031346625,0x6625202c35303466,0x7663090a3b353034\n"
".quad 0x3233662e6e722e74,0x662509203233732e,0x327225202c313134,0x6c756d090a3b3130\n"
".quad 0x662509203233662e,0x346625202c323134,0x30346625202c3530,0x2e6c756d090a3b37\n"
".quad 0x3466250920323366,0x30346625202c3331,0x3830346625202c35,0x662e6c756d090a3b\n"
".quad 0x3134662509203233,0x3530346625202c34,0x3b3930346625202c,0x33662e6c756d090a\n"
".quad 0x3531346625092032,0x2c3630346625202c,0x0a3b313134662520,0x3233662e62757309\n"
".quad 0x2c36313466250920,0x202c353134662520,0x090a3b3031346625,0x203233662e6c756d\n"
".quad 0x202c373134662509,0x25202c3131346625,0x6d090a3b31393366,0x09203233662e6c75\n"
".quad 0x25202c3831346625,0x6625202c31313466,0x756d090a3b303933,0x2509203233662e6c\n"
".quad 0x6625202c39313466,0x336625202c313134,0x706372090a3b3938,0x203233662e6e722e\n"
".quad 0x202c303234662509,0x090a3b3631346625,0x203233662e627573,0x202c313234662509\n"
".quad 0x25202c3731346625,0x73090a3b32313466,0x09203233662e6275,0x25202c3232346625\n"
".quad 0x6625202c38313466,0x7573090a3b333134,0x2509203233662e62,0x6625202c33323466\n"
".quad 0x346625202c393134,0x6c756d090a3b3431,0x662509203233662e,0x346625202c343234\n"
".quad 0x32346625202c3032,0x2e6c756d090a3b31,0x3466250920323366,0x32346625202c3532\n"
".quad 0x3232346625202c30,0x662e6c756d090a3b,0x3234662509203233,0x3032346625202c36\n"
".quad 0x3b3332346625202c,0x61732e747663090a,0x33662e3233662e74,0x3732346625092032\n"
".quad 0x3b3432346625202c,0x61732e747663090a,0x33662e3233662e74,0x3832346625092032\n"
".quad 0x3b3532346625202c,0x61732e747663090a,0x33662e3233662e74,0x3932346625092032\n"
".quad 0x3b3632346625202c,0x33662e766f6d090a,0x3033346625092032,0x386631346630202c\n"
".quad 0x2020203b30303030,0x090a3133202f2f09,0x203233662e6c756d,0x202c313334662509\n"
".quad 0x25202c3732346625,0x6d090a3b30333466,0x09203233662e766f,0x30202c3233346625\n"
".quad 0x3030306337323466,0x2f2f092020203b30,0x6c756d090a333620,0x662509203233662e\n"
".quad 0x346625202c333334,0x33346625202c3832,0x2e766f6d090a3b32,0x3466250920323366\n"
".quad 0x31346630202c3433,0x203b303030303866,0x3133202f2f092020,0x33662e6c756d090a\n"
".quad 0x3533346625092032,0x2c3932346625202c,0x0a3b343334662520,0x696e722e74766309\n"
".quad 0x3233662e3233662e,0x2c36333466250920,0x0a3b313334662520,0x696e722e74766309\n"
".quad 0x3233662e3233662e,0x2c37333466250920,0x0a3b333334662520,0x696e722e74766309\n"
".quad 0x3233662e3233662e,0x2c38333466250920,0x0a3b353334662520,0x697a722e74766309\n"
".quad 0x3233662e3233752e,0x2c32303272250920,0x0a3b363334662520,0x3233622e6c687309\n"
".quad 0x2c33303272250920,0x202c323032722520,0x747663090a3b3131,0x3233752e697a722e\n"
".quad 0x722509203233662e,0x346625202c343032,0x6c6873090a3b3733,0x722509203233622e\n"
".quad 0x327225202c353032,0x090a3b35202c3430,0x09203233622e726f,0x25202c3630327225\n"
".quad 0x7225202c33303272,0x7663090a3b353032,0x33752e697a722e74,0x2509203233662e32\n"
".quad 0x6625202c37303272,0x726f090a3b383334,0x722509203233622e,0x327225202c383032\n"
".quad 0x30327225202c3630,0x2e747663090a3b37,0x203233752e363175,0x202c393032722509\n"
".quad 0x090a3b3830327225,0x09373109636f6c2e,0x6d090a3009343233,0x09203233662e6c75\n"
".quad 0x25202c3933346625,0x6625202c35303466,0x756d090a3b313933,0x2509203233662e6c\n"
".quad 0x6625202c30343466,0x336625202c353034,0x6c756d090a3b3039,0x662509203233662e\n"
".quad 0x346625202c313434,0x38336625202c3530,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x30346625202c3234,0x3730346625202c36,0x662e6c756d090a3b,0x3434662509203233\n"
".quad 0x3630346625202c33,0x3b3830346625202c,0x33662e6c756d090a,0x3434346625092032\n"
".quad 0x2c3630346625202c,0x0a3b393034662520,0x3233662e62757309,0x2c35343466250920\n"
".quad 0x202c323434662520,0x090a3b3933346625,0x203233662e627573,0x202c363434662509\n"
".quad 0x25202c3334346625,0x73090a3b30343466,0x09203233662e6275,0x25202c3734346625\n"
".quad 0x6625202c34343466,0x756d090a3b313434,0x2509203233662e6c,0x6625202c38343466\n"
".quad 0x346625202c353434,0x6c756d090a3b3032,0x662509203233662e,0x346625202c393434\n"
".quad 0x32346625202c3634,0x2e6c756d090a3b30,0x3466250920323366,0x34346625202c3035\n"
".quad 0x3032346625202c37,0x732e747663090a3b,0x662e3233662e7461,0x3534662509203233\n"
".quad 0x3834346625202c31,0x732e747663090a3b,0x662e3233662e7461,0x3534662509203233\n"
".quad 0x3934346625202c32,0x732e747663090a3b,0x662e3233662e7461,0x3534662509203233\n"
".quad 0x3035346625202c33,0x662e766f6d090a3b,0x3534662509203233,0x6631346630202c34\n"
".quad 0x20203b3030303038,0x0a3133202f2f0920,0x3233662e6c756d09,0x2c35353466250920\n"
".quad 0x202c313534662520,0x090a3b3435346625,0x203233662e766f6d,0x202c363534662509\n"
".quad 0x3030633732346630,0x2f092020203b3030,0x756d090a3336202f,0x2509203233662e6c\n"
".quad 0x6625202c37353466,0x346625202c323534,0x766f6d090a3b3635,0x662509203233662e\n"
".quad 0x346630202c383534,0x3b30303030386631,0x33202f2f09202020,0x662e6c756d090a31\n"
".quad 0x3534662509203233,0x3335346625202c39,0x3b3835346625202c,0x6e722e747663090a\n"
".quad 0x33662e3233662e69,0x3036346625092032,0x3b3535346625202c,0x6e722e747663090a\n"
".quad 0x33662e3233662e69,0x3136346625092032,0x3b3735346625202c,0x6e722e747663090a\n"
".quad 0x33662e3233662e69,0x3236346625092032,0x3b3935346625202c,0x7a722e747663090a\n"
".quad 0x33662e3233752e69,0x3031327225092032,0x3b3036346625202c,0x33622e6c6873090a\n"
".quad 0x3131327225092032,0x2c3031327225202c,0x7663090a3b313120,0x33752e697a722e74\n"
".quad 0x2509203233662e32,0x6625202c32313272,0x6873090a3b313634,0x2509203233622e6c\n"
".quad 0x7225202c33313272,0x0a3b35202c323132,0x203233622e726f09,0x202c343132722509\n"
".quad 0x25202c3131327225,0x63090a3b33313272,0x752e697a722e7476,0x09203233662e3233\n"
".quad 0x25202c3531327225,0x6f090a3b32363466,0x2509203233622e72,0x7225202c36313272\n"
".quad 0x327225202c343132,0x747663090a3b3531,0x3233752e3631752e,0x2c37313272250920\n"
".quad 0x0a3b363132722520,0x373109636f6c2e09,0x090a300937323309,0x203233662e766f6d\n"
".quad 0x202c333634662509,0x3533343064336630,0x2f092020203b3137,0x323233302e30202f\n"
".quad 0x6c756d090a353737,0x662509203233662e,0x346625202c343634,0x36346625202c3633\n"
".quad 0x2e6c756d090a3b33,0x3466250920323366,0x36346625202c3536,0x3436346625202c34\n"
".quad 0x662e766f6d090a3b,0x3634662509203233,0x3863336630202c36,0x20203b3931316231\n"
".quad 0x302e30202f2f0920,0x090a353133383531,0x203233662e6c756d,0x202c373634662509\n"
".quad 0x25202c3733346625,0x6d090a3b36363466,0x09203233662e6c75,0x25202c3836346625\n"
".quad 0x6625202c37363466,0x6f6d090a3b373634,0x2509203233662e76,0x6630202c39363466\n"
".quad 0x3137353334306433,0x202f2f092020203b,0x3737323233302e30,0x662e6c756d090a35\n"
".quad 0x3734662509203233,0x3833346625202c30,0x3b3936346625202c,0x33662e6c756d090a\n"
".quad 0x3137346625092032,0x2c3037346625202c,0x0a3b303734662520,0x3233662e766f6d09\n"
".quad 0x2c32373466250920,0x3334306433663020,0x092020203b313735,0x3233302e30202f2f\n"
".quad 0x756d090a35373732,0x2509203233662e6c,0x6625202c33373466,0x346625202c303634\n"
".quad 0x6c756d090a3b3237,0x662509203233662e,0x346625202c343734,0x37346625202c3337\n"
".quad 0x2e766f6d090a3b33,0x3466250920323366,0x63336630202c3537,0x203b393131623138\n"
".quad 0x2e30202f2f092020,0x0a35313338353130,0x3233662e6c756d09,0x2c36373466250920\n"
".quad 0x202c313634662520,0x090a3b3537346625,0x203233662e6c756d,0x202c373734662509\n"
".quad 0x25202c3637346625,0x6d090a3b36373466,0x09203233662e766f,0x30202c3837346625\n"
".quad 0x3735333430643366,0x2f2f092020203b31,0x37323233302e3020,0x2e6c756d090a3537\n"
".quad 0x3466250920323366,0x36346625202c3937,0x3837346625202c32,0x662e6c756d090a3b\n"
".quad 0x3834662509203233,0x3937346625202c30,0x3b3937346625202c,0x33662e6c756d090a\n"
".quad 0x3138346625092032,0x2c3337346625202c,0x0a3b343634662520,0x3233662e6c756d09\n"
".quad 0x2c32383466250920,0x202c363734662520,0x090a3b3736346625,0x203233662e6c756d\n"
".quad 0x202c333834662509,0x25202c3937346625,0x6d090a3b30373466,0x09203233662e6c75\n"
".quad 0x25202c3438346625,0x6625202c34363466,0x756d090a3b313933,0x2509203233662e6c\n"
".quad 0x6625202c35383466,0x336625202c373634,0x6c756d090a3b3039,0x662509203233662e\n"
".quad 0x346625202c363834,0x38336625202c3037,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x30346625202c3738,0x3337346625202c37,0x662e6c756d090a3b,0x3834662509203233\n"
".quad 0x3830346625202c38,0x3b3637346625202c,0x33662e6c756d090a,0x3938346625092032\n"
".quad 0x2c3930346625202c,0x0a3b393734662520,0x373109636f6c2e09,0x090a300935373309\n"
".quad 0x203233662e6c756d,0x202c303934662509,0x25202c3530346625,0x6d090a3b32383466\n"
".quad 0x09203233662e6c75,0x25202c3139346625,0x6625202c35303466,0x756d090a3b313834\n"
".quad 0x2509203233662e6c,0x6625202c32393466,0x346625202c353034,0x6c756d090a3b3338\n"
".quad 0x662509203233662e,0x346625202c333934,0x36346625202c3630,0x2e6c756d090a3b38\n"
".quad 0x3466250920323366,0x30346625202c3439,0x3536346625202c36,0x662e6c756d090a3b\n"
".quad 0x3934662509203233,0x3630346625202c35,0x3b3137346625202c,0x33662e627573090a\n"
".quad 0x3639346625092032,0x2c3039346625202c,0x0a3b353834662520,0x3233662e62757309\n"
".quad 0x2c37393466250920,0x202c313934662520,0x090a3b3438346625,0x203233662e627573\n"
".quad 0x202c383934662509,0x25202c3239346625,0x6d090a3b36383466,0x09203233662e6c75\n"
".quad 0x25202c3939346625,0x6625202c31313466,0x756d090a3b373734,0x2509203233662e6c\n"
".quad 0x6625202c30303566,0x346625202c313134,0x6c756d090a3b3437,0x662509203233662e\n"
".quad 0x346625202c313035,0x38346625202c3131,0x2e627573090a3b30,0x3566250920323366\n"
".quad 0x39346625202c3230,0x3838346625202c36,0x662e627573090a3b,0x3035662509203233\n"
".quad 0x3739346625202c33,0x3b3738346625202c,0x33662e627573090a,0x3430356625092032\n"
".quad 0x2c3839346625202c,0x0a3b393834662520,0x3233662e64646109,0x2c35303566250920\n"
".quad 0x202c333934662520,0x090a3b3939346625,0x203233662e646461,0x202c363035662509\n"
".quad 0x25202c3439346625,0x61090a3b30303566,0x09203233662e6464,0x25202c3730356625\n"
".quad 0x6625202c35393466,0x6461090a3b313035,0x2509203233662e64,0x6625202c38303566\n"
".quad 0x356625202c323035,0x646461090a3b3230,0x662509203233662e,0x356625202c393035\n"
".quad 0x30356625202c3330,0x2e646461090a3b33,0x3566250920323366,0x30356625202c3031\n"
".quad 0x3430356625202c34,0x662e646461090a3b,0x3135662509203233,0x3530356625202c31\n"
".quad 0x3b3830356625202c,0x33662e646461090a,0x3231356625092032,0x2c3630356625202c\n"
".quad 0x0a3b393035662520,0x3233662e64646109,0x2c33313566250920,0x202c373035662520\n"
".quad 0x090a3b3031356625,0x74736e6f632e646c,0x662509203233662e,0x436b5b202c343135\n"
".quad 0x7274654d726f6c6f,0x090a3b5d342b6369,0x203233662e6c756d,0x202c353135662509\n"
".quad 0x25202c3431356625,0x6c090a3b31313566,0x2e74736e6f632e64,0x3566250920323366\n"
".quad 0x6f436b5b202c3631,0x697274654d726f6c,0x66090a3b5d302b63,0x33662e6e722e616d\n"
".quad 0x3731356625092032,0x2c3231356625202c,0x202c363135662520,0x090a3b3531356625\n"
".quad 0x74736e6f632e646c,0x662509203233662e,0x436b5b202c383135,0x7274654d726f6c6f\n"
".quad 0x090a3b5d382b6369,0x662e6e722e616d66,0x3135662509203233,0x3331356625202c39\n"
".quad 0x2c3831356625202c,0x0a3b373135662520,0x3233662e766f6d09,0x2c30323566250920\n"
".quad 0x3030386533663020,0x092020203b303030,0x0a35322e30202f2f,0x3233662e6c756d09\n"
".quad 0x2c31323566250920,0x202c393135662520,0x090a3b3032356625,0x2e746c2e70746573\n"
".quad 0x3170250920323366,0x3132356625202c38,0x3b3535326625202c,0x383170252140090a\n"
".quad 0x4c24092061726220,0x353535355f385f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35363320656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363733355f385f74,0x09636f6c2e090a32,0x3009393733093731\n"
".quad 0x33662e766f6d090a,0x3535326625092032,0x3b3132356625202c,0x3109636f6c2e090a\n"
".quad 0x0a30093038330937,0x3233732e766f6d09,0x2c38313272250920,0x0a3b373831722520\n"
".quad 0x373109636f6c2e09,0x090a300931383309,0x203233732e766f6d,0x202c353731722509\n"
".quad 0x090a3b3930327225,0x09373109636f6c2e,0x6d090a3009323833,0x09203233732e766f\n"
".quad 0x25202c3437317225,0x73090a3b37313272,0x752e656c2e707465,0x3931702509203233\n"
".quad 0x2c3930327225202c,0x0a3b373132722520,0x6220393170254009,0x5f744c2409206172\n"
".quad 0x3b30313835355f38,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3536332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363733355f38,0x373109636f6c2e09,0x6d090a3009323709,0x09203233732e766f\n"
".quad 0x25202c3931327225,0x2e090a3b34373172,0x3709373109636f6c,0x766f6d090a300933\n"
".quad 0x722509203233732e,0x317225202c343731,0x6f6c2e090a3b3537,0x0934370937310963\n"
".quad 0x732e766f6d090a30,0x3731722509203233,0x3931327225202c35,0x09636f6c2e090a3b\n"
".quad 0x3009373833093731,0x33622e746f6e090a,0x3032327225092032,0x3b3738317225202c\n"
".quad 0x33752e726873090a,0x3132327225092032,0x2c3032327225202c,0x646e61090a3b3120\n"
".quad 0x722509203233622e,0x327225202c323232,0x31333431202c3132,0x0a3b353637353536\n"
".quad 0x3233622e726f7809,0x2c33323272250920,0x202c373831722520,0x090a3b3232327225\n"
".quad 0x203233732e766f6d,0x202c323731722509,0x090a3b3332327225,0x20696e752e617262\n"
".quad 0x355f385f744c2409,0x4c240a3b34353535,0x313835355f385f74,0x6c3c2f2f200a3a30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35363320656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363733355f385f74,0x732e766f6d090a32\n"
".quad 0x3731722509203233,0x3831327225202c32,0x5f385f744c240a3b,0x240a3a3435353535\n"
".quad 0x3035355f385f744c,0x3c2f2f200a3a3234,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35363320656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3733355f385f744c,0x636f6c2e090a3236,0x0938363309373109,0x732e646461090a30\n"
".quad 0x3731722509203233,0x3937317225202c39,0x6f6d090a3b31202c,0x2509203233752e76\n"
".quad 0x3b33202c34323272,0x6e2e70746573090a,0x2509203233732e65,0x317225202c303270\n"
".quad 0x32327225202c3937,0x32702540090a3b34,0x2409206172622030,0x3733355f385f744c\n"
".quad 0x57444c240a3b3236,0x315a5f5f69646e65,0x6945747372696636,0x6f746365566e6567\n"
".quad 0x5f3738315f665072,0x636f6c2e090a3a32,0x0930393309373109,0x752e766f6d090a30\n"
".quad 0x3232722509203233,0x6475635f5f202c35,0x5f6c61636f6c5f61,0x303138335f726176\n"
".quad 0x6e6f6e5f33335f30,0x695f74736e6f635f,0x5f5f73656369646e,0x2e766f6d090a3b31\n"
".quad 0x3272250920323375,0x75635f5f202c3632,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x373138335f726176,0x6e6f6e5f35335f32,0x655f74736e6f635f,0x30383173726f7272\n"
".quad 0x636f6c2e090a3b34,0x0932393309373109,0x752e646461090a30,0x3232722509203233\n"
".quad 0x2c32367225202c37,0x0a3b363232722520,0x726168732e747309,0x09203233662e6465\n"
".quad 0x302b37323272255b,0x3535326625202c5d,0x09636f6c2e090a3b,0x3009343034093731\n"
".quad 0x33752e646461090a,0x3832327225092032,0x202c32367225202c,0x090a3b3532327225\n"
".quad 0x65726168732e7473,0x5b09203233732e64,0x5d302b3832327225,0x090a3b317225202c\n"
".quad 0x203233732e766f6d,0x202c393232722509,0x5f744c240a3b3233,0x3a34333836355f38\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3430342065\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09373109636f6c2e,0x62090a3009393034\n"
".quad 0x20636e79732e7261,0x746573090a3b3009,0x3233732e656c2e70,0x202c313270250920\n"
".quad 0x25202c3932327225,0x702540090a3b3172,0x0920617262203132,0x37355f385f744c24\n"
".quad 0x2f2f200a3b323036,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x303420656e696c20,0x2064616568202c34,0x2064656c6562616c,0x36355f385f744c24\n"
".quad 0x6f6c2e090a343338,0x3431340937310963,0x2e646461090a3009,0x3272250920323373\n"
".quad 0x32327225202c3033,0x0a3b317225202c39,0x2e6f6c2e6c756d09,0x3272250920323375\n"
".quad 0x33327225202c3133,0x61090a3b34202c30,0x09203233752e6464,0x25202c3233327225\n"
".quad 0x7225202c31333272,0x646c090a3b363232,0x2e6465726168732e,0x3566250920323366\n"
".quad 0x3272255b202c3232,0x090a3b5d302b3233,0x65726168732e646c,0x2509203233662e64\n"
".quad 0x255b202c33323566,0x3b5d302b37323272,0x672e70746573090a,0x2509203233662e74\n"
".quad 0x356625202c323270,0x32356625202c3332,0x70252140090a3b32,0x0920617262203232\n"
".quad 0x37355f385f744c24,0x2f2f200a3b323036,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x303420656e696c20,0x2064616568202c34,0x2064656c6562616c\n"
".quad 0x36355f385f744c24,0x6f6c2e090a343338,0x3731340937310963,0x732e7473090a3009\n"
".quad 0x33662e6465726168,0x323272255b092032,0x6625202c5d302b37,0x6c2e090a3b323235\n"
".quad 0x313409373109636f,0x646461090a300938,0x722509203233752e,0x327225202c333332\n"
".quad 0x32327225202c3133,0x732e646c090a3b35,0x33732e6465726168,0x3433327225092032\n"
".quad 0x33333272255b202c,0x7473090a3b5d302b,0x2e6465726168732e,0x72255b0920323373\n"
".quad 0x202c5d302b383232,0x240a3b3433327225,0x3637355f385f744c,0x5f744c240a3a3230\n"
".quad 0x3a30393037355f38,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3430342065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f38,0x373109636f6c2e09,0x090a300937303409,0x203233732e726873\n"
".quad 0x202c393232722509,0x31202c3932327225,0x752e766f6d090a3b,0x3332722509203233\n"
".quad 0x73090a3b30202c35,0x732e74672e707465,0x3332702509203233,0x2c3932327225202c\n"
".quad 0x0a3b353332722520,0x6220333270254009,0x5f744c2409206172,0x3b34333836355f38\n"
".quad 0x3109636f6c2e090a,0x0a30093237340937,0x6e79732e72616209,0x2e090a3b30092063\n"
".quad 0x3409373109636f6c,0x646c090a30093437,0x2e6465726168732e,0x3272250920323373\n"
".quad 0x635f5f5b202c3633,0x61636f6c5f616475,0x38335f7261765f6c,0x6e5f33335f303031\n"
".quad 0x74736e6f635f6e6f,0x73656369646e695f,0x0a3b5d302b315f5f,0x373109636f6c2e09\n"
".quad 0x090a300931333509,0x636e79732e726162,0x6573090a3b300920,0x33732e656e2e7074\n"
".quad 0x2c34327025092032,0x202c363332722520,0x2540090a3b317225,0x2061726220343270\n"
".quad 0x355f385f744c2409,0x2e090a3b30373338,0x3409373109636f6c,0x6573090a30093539\n"
".quad 0x33752e71652e7074,0x2c35327025092032,0x202c343731722520,0x090a3b3537317225\n"
".quad 0x203233752e766f6d,0x202c373332722509,0x2e766f6d090a3b30,0x3272250920323373\n"
".quad 0x37317225202c3833,0x706c6573090a3b32,0x722509203233752e,0x327225202c393332\n"
".quad 0x33327225202c3733,0x3b35327025202c38,0x6168732e646c090a,0x732e34762e646572\n"
".quad 0x3272257b09203233,0x31343272252c3034,0x252c32343272252c,0x5b202c7d33343272\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3336313833\n"
".quad 0x6e6f635f6e6f6e5f,0x73666572785f7473,0x3b5d302b30343731,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x327225202c343432,0x090a3b32202c3034,0x203233752e726873\n"
".quad 0x202c353432722509,0x25202c3933327225,0x61090a3b34343272,0x09203233622e646e\n"
".quad 0x25202c3634327225,0x3b33202c35343272,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x327225202c373432,0x090a3b32202c3134,0x203233752e726873,0x202c383432722509\n"
".quad 0x25202c3933327225,0x61090a3b37343272,0x09203233622e646e,0x25202c3934327225\n"
".quad 0x3b33202c38343272,0x33622e6c6873090a,0x3035327225092032,0x2c3934327225202c\n"
".quad 0x2e726f090a3b3220,0x3272250920323362,0x34327225202c3135,0x3035327225202c36\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c32353272,0x0a3b32202c323432\n"
".quad 0x3233752e72687309,0x2c33353272250920,0x202c393332722520,0x090a3b3235327225\n"
".quad 0x203233622e646e61,0x202c343532722509,0x33202c3335327225,0x622e6c6873090a3b\n"
".quad 0x3532722509203233,0x3435327225202c35,0x756d090a3b34202c,0x3233732e6f6c2e6c\n"
".quad 0x2c36353272250920,0x202c333432722520,0x2e726873090a3b32,0x3272250920323375\n"
".quad 0x33327225202c3735,0x3635327225202c39,0x622e646e61090a3b,0x3532722509203233\n"
".quad 0x3735327225202c38,0x6873090a3b33202c,0x2509203233622e6c,0x7225202c39353272\n"
".quad 0x0a3b36202c383532,0x203233622e726f09,0x202c303632722509,0x25202c3535327225\n"
".quad 0x6f090a3b39353272,0x2509203233622e72,0x7225202c31363272,0x327225202c313532\n"
".quad 0x2e646c090a3b3036,0x762e646572616873,0x7b09203233732e34,0x72252c3236327225\n"
".quad 0x363272252c333632,0x7d35363272252c34,0x6475635f5f5b202c,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x33363138335f7261,0x5f6e6f6e5f33335f,0x72785f74736e6f63\n"
".quad 0x2b30343731736665,0x756d090a3b5d3631,0x3233732e6f6c2e6c,0x2c36363272250920\n"
".quad 0x202c323632722520,0x2e726873090a3b32,0x3272250920323375,0x33327225202c3736\n"
".quad 0x3636327225202c39,0x622e646e61090a3b,0x3632722509203233,0x3736327225202c38\n"
".quad 0x6873090a3b33202c,0x2509203233622e6c,0x7225202c39363272,0x0a3b38202c383632\n"
".quad 0x2e6f6c2e6c756d09,0x3272250920323373,0x36327225202c3037,0x73090a3b32202c33\n"
".quad 0x09203233752e7268,0x25202c3137327225,0x7225202c39333272,0x6e61090a3b303732\n"
".quad 0x2509203233622e64,0x7225202c32373272,0x0a3b33202c313732,0x3233622e6c687309\n"
".quad 0x2c33373272250920,0x202c323732722520,0x2e726f090a3b3031,0x3272250920323362\n"
".quad 0x36327225202c3437,0x3337327225202c39,0x33622e726f090a3b,0x3537327225092032\n"
".quad 0x2c3136327225202c,0x0a3b343732722520,0x2e6f6c2e6c756d09,0x3272250920323373\n"
".quad 0x36327225202c3637,0x73090a3b32202c34,0x09203233752e7268,0x25202c3737327225\n"
".quad 0x7225202c39333272,0x6e61090a3b363732,0x2509203233622e64,0x7225202c38373272\n"
".quad 0x0a3b33202c373732,0x3233622e6c687309,0x2c39373272250920,0x202c383732722520\n"
".quad 0x6c756d090a3b3231,0x203233732e6f6c2e,0x202c303832722509,0x32202c3536327225\n"
".quad 0x752e726873090a3b,0x3832722509203233,0x3933327225202c31,0x3b3038327225202c\n"
".quad 0x33622e646e61090a,0x3238327225092032,0x2c3138327225202c,0x6c6873090a3b3320\n"
".quad 0x722509203233622e,0x327225202c333832,0x0a3b3431202c3238,0x203233622e726f09\n"
".quad 0x202c343832722509,0x25202c3937327225,0x6f090a3b33383272,0x2509203233622e72\n"
".quad 0x7225202c35383272,0x327225202c353732,0x2e646c090a3b3438,0x762e646572616873\n"
".quad 0x7b09203233732e34,0x72252c3638327225,0x383272252c373832,0x7d39383272252c38\n"
".quad 0x6475635f5f5b202c,0x616475635f5f5f61,0x765f6c61636f6c5f,0x33363138335f7261\n"
".quad 0x5f6e6f6e5f33335f,0x72785f74736e6f63,0x2b30343731736665,0x756d090a3b5d3233\n"
".quad 0x3233732e6f6c2e6c,0x2c30393272250920,0x202c363832722520,0x2e726873090a3b32\n"
".quad 0x3272250920323375,0x33327225202c3139,0x3039327225202c39,0x622e646e61090a3b\n"
".quad 0x3932722509203233,0x3139327225202c32,0x6873090a3b33202c,0x2509203233622e6c\n"
".quad 0x7225202c33393272,0x3b3631202c323932,0x3233622e726f090a,0x2c34393272250920\n"
".quad 0x202c353832722520,0x090a3b3339327225,0x732e6f6c2e6c756d,0x3932722509203233\n"
".quad 0x3738327225202c35,0x6873090a3b32202c,0x2509203233752e72,0x7225202c36393272\n"
".quad 0x327225202c393332,0x646e61090a3b3539,0x722509203233622e,0x327225202c373932\n"
".quad 0x090a3b33202c3639,0x203233622e6c6873,0x202c383932722509,0x31202c3739327225\n"
".quad 0x622e726f090a3b38,0x3932722509203233,0x3439327225202c39,0x3b3839327225202c\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x327225202c303033,0x090a3b32202c3838\n"
".quad 0x203233752e726873,0x202c313033722509,0x25202c3933327225,0x61090a3b30303372\n"
".quad 0x09203233622e646e,0x25202c3230337225,0x3b33202c31303372,0x33622e6c6873090a\n"
".quad 0x3330337225092032,0x2c3230337225202c,0x726f090a3b303220,0x722509203233622e\n"
".quad 0x327225202c343033,0x30337225202c3939,0x2e6c756d090a3b33,0x09203233732e6f6c\n"
".quad 0x25202c3530337225,0x3b32202c39383272,0x33752e726873090a,0x3630337225092032\n"
".quad 0x2c3933327225202c,0x0a3b353033722520,0x3233622e646e6109,0x2c37303372250920\n"
".quad 0x202c363033722520,0x2e6c6873090a3b33,0x3372250920323362,0x30337225202c3830\n"
".quad 0x090a3b3232202c37,0x09203233622e726f,0x25202c3930337225,0x7225202c34303372\n"
".quad 0x646c090a3b383033,0x2e6465726168732e,0x09203233732e3476,0x252c30313372257b\n"
".quad 0x3372252c31313372,0x33313372252c3231,0x75635f5f5b202c7d,0x6475635f5f5f6164\n"
".quad 0x5f6c61636f6c5f61,0x363138335f726176,0x6e6f6e5f33335f33,0x785f74736e6f635f\n"
".quad 0x3034373173666572,0x6d090a3b5d38342b,0x33732e6f6c2e6c75,0x3431337225092032\n"
".quad 0x2c3031337225202c,0x726873090a3b3220,0x722509203233752e,0x327225202c353133\n"
".quad 0x31337225202c3933,0x2e646e61090a3b34,0x3372250920323362,0x31337225202c3631\n"
".quad 0x73090a3b33202c35,0x09203233622e6c68,0x25202c3731337225,0x3432202c36313372\n"
".quad 0x33622e726f090a3b,0x3831337225092032,0x2c3930337225202c,0x0a3b373133722520\n"
".quad 0x2e6f6c2e6c756d09,0x3372250920323373,0x31337225202c3931,0x73090a3b32202c31\n"
".quad 0x09203233752e7268,0x25202c3032337225,0x7225202c39333272,0x6e61090a3b393133\n"
".quad 0x2509203233622e64,0x7225202c31323372,0x0a3b33202c303233,0x3233622e6c687309\n"
".quad 0x2c32323372250920,0x202c313233722520,0x2e726f090a3b3632,0x3372250920323362\n"
".quad 0x31337225202c3332,0x3232337225202c38,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c34323372,0x0a3b32202c323133,0x3233752e72687309,0x2c35323372250920\n"
".quad 0x202c393332722520,0x090a3b3432337225,0x203233622e646e61,0x202c363233722509\n"
".quad 0x33202c3532337225,0x622e6c6873090a3b,0x3233722509203233,0x3632337225202c37\n"
".quad 0x6f090a3b3832202c,0x2509203233622e72,0x7225202c38323372,0x337225202c333233\n"
".quad 0x6c756d090a3b3732,0x203233732e6f6c2e,0x202c393233722509,0x32202c3331337225\n"
".quad 0x752e726873090a3b,0x3333722509203233,0x3933327225202c30,0x3b3932337225202c\n"
".quad 0x33622e6c6873090a,0x3133337225092032,0x2c3033337225202c,0x726f090a3b303320\n"
".quad 0x722509203233622e,0x337225202c323333,0x33337225202c3832,0x636f6c2e090a3b31\n"
".quad 0x0939393409373109,0x732e747663090a30,0x09203233752e3233,0x25202c3333337225\n"
".quad 0x3b782e6469617463,0x6f6c2e6c756d090a,0x722509203233752e,0x337225202c343333\n"
".quad 0x090a3b38202c3333,0x6d617261702e646c,0x722509203233752e,0x5f5f5b202c353333\n"
".quad 0x6d72617061647563,0x706d6f63385a5f5f,0x536a4b5073736572,0x746e697535505f30\n"
".quad 0x746c757365725f32,0x2e646461090a3b5d,0x3372250920323375,0x33337225202c3633\n"
".quad 0x3433337225202c35,0x622e6c6873090a3b,0x3333722509203233,0x3437317225202c37\n"
".quad 0x6f090a3b3631202c,0x2509203233622e72,0x7225202c38333372,0x337225202c353731\n"
".quad 0x2e7473090a3b3733,0x762e6c61626f6c67,0x5b09203233752e32,0x5d302b3633337225\n"
".quad 0x38333372257b202c,0x3b7d32333372252c,0x355f385f744c240a,0x2e090a3a30373338\n"
".quad 0x3509373109636f6c,0x7865090a30093833,0x57444c240a3b7469,0x63385a5f5f646e65\n"
".quad 0x5073736572706d6f,0x7535505f30536a4b,0x7d090a3a32746e69,0x63385a5f202f2f20\n"
".quad 0x5073736572706d6f,0x7535505f30536a4b,0x00000a0a32746e69\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[12791];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_20$:\n"
".quad 0x33010101464c457f,0x0000000000000004,0x0000000100be0002,0x0000415c00000000\n"
".quad 0x0014011400000034,0x0028000400200034,0x000000000001000b,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000100000000\n"
".quad 0x0000000000000003,0x000001ec00000000,0x0000000000000101,0x0000000400000000\n"
".quad 0x0000000b00000000,0x0000000000000003,0x000002ed00000000,0x0000000000000064\n"
".quad 0x0000000100000000,0x0000001300000000,0x0000000000000002,0x0000035100000000\n"
".quad 0x0000000200000140,0x000000010000000d,0x0000003600000010,0x0010000600000001\n"
".quad 0x0000049100000000,0x0000000300003bc0,0x0000000431000006,0x000000cc00000000\n"
".quad 0x0000000200000001,0x0000405100000000,0x000000000000002c,0x0000000400000004\n"
".quad 0x000000a400000000,0x0000000200000001,0x0000407d00000000,0x0000000000000004\n"
".quad 0x0000000400000004,0x0000005500000000,0x0000000200000001,0x0000408100000000\n"
".quad 0x000000000000005c,0x0000000100000004,0x0000008000000000,0x0000000300000008\n"
".quad 0x000040dd00000000,0x0000000000000800,0x0000000400000004,0x000000f300000000\n"
".quad 0x0000000200000001,0x000040dd00000000,0x000000000000004c,0x0000000400000000\n"
".quad 0x0000007700000000,0x0000000200000001,0x0000412900000000,0x0000000000000030\n"
".quad 0x0000000100000000,0x68732e0000000000,0x2e00626174727473,0x2e00626174727473\n"
".quad 0x2e006261746d7973,0x61626f6c672e766e,0x2e0074696e692e6c,0x61626f6c672e766e\n"
".quad 0x2e747865742e006c,0x72706d6f63385a5f,0x30536a4b50737365,0x32746e697535505f\n"
".quad 0x666e692e766e2e00,0x6d6f63385a5f2e6f,0x6a4b507373657270,0x6e697535505f3053\n"
".quad 0x692e766e2e003274,0x2e766e2e006f666e,0x5f2e646572616873,0x6572706d6f63385a\n"
".quad 0x5f30536a4b507373,0x0032746e69753550,0x736e6f632e766e2e,0x5f2e3631746e6174\n"
".quad 0x6572706d6f63385a,0x5f30536a4b507373,0x0032746e69753550,0x736e6f632e766e2e\n"
".quad 0x5a5f2e30746e6174,0x736572706d6f6338,0x505f30536a4b5073,0x2e0032746e697535\n"
".quad 0x74736e6f632e766e,0x5a5f000032746e61,0x736572706d6f6338,0x505f30536a4b5073\n"
".quad 0x5f0032746e697535,0x6d735f616475635f,0x725f7063725f3032,0x436b003233665f6e\n"
".quad 0x7274654d726f6c6f,0x73646f7270006369,0x3373646f72700034,0x61546168706c6100\n"
".quad 0x706c610034656c62,0x33656c6261546168,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0100030000000000,0x0000000000000000,0x0200030000000000\n"
".quad 0x0000000000000000,0x0300030000000000,0x0000000000000000,0x0000030000000000\n"
".quad 0x0000000000000000,0x0000030000000000,0x0000000000000000,0x04000300003bc000\n"
".quad 0x0000000000000000,0x0700030000000000,0x0000000000000000,0x0a00030000000000\n"
".quad 0x0000000000000000,0x0800030000000000,0x0000000000000000,0x0600030000000000\n"
".quad 0x0000000000000000,0x0500030000000000,0x0000000000000000,0x0900030000000000\n"
".quad 0x0000000000000100,0x0410120000399000,0x0039900000001a00,0x0400120000023000\n"
".quad 0x0000000000003100,0x0900110000000c00,0x00002c0000003e00,0x0900110000001000\n"
".quad 0x00003c0000004500,0x0900110000001000,0x00000c0000004c00,0x0900110000001000\n"
".quad 0x00001c0000005800,0x0900110000001000,0x00440400005de400,0x00000084051c0428\n"
".quad 0x8ec0003d41dc232c,0x0000026000a1e719,0x0000009400000440,0x00c000314080032c\n"
".quad 0x0000005000008350,0x0040009000004340,0x0000000000008540,0x00c0004000c00380\n"
".quad 0x00c0002001000360,0x00c003fc00000360,0x00c0006030c00368,0x00c0006041000358\n"
".quad 0x0000000120000458,0x0000000d20c00418,0x0000001121000418,0xee02020400000218\n"
".quad 0xee02020430c00230,0xee02020441000230,0x0000000020008530,0x0000001020c085c9\n"
".quad 0x00000020210085c9,0x7e0000fc1fdc03c9,0xee0000ffffdc0420,0x8ec0003d41dc2350\n"
".quad 0x000000e000a1e719,0x00c0003141000340,0x0000000040c08550,0x00000010408085c1\n"
".quad 0x00000020400085c1,0x0000030040c085c1,0x00000310408085c9,0x00000320400085c9\n"
".quad 0xee0000ffffdc04c9,0x8ec0003d41dc2350,0x000001e000a1e719,0x00c0002140008340\n"
".quad 0x00c0003142000368,0x00c0003001c00350,0x0000030080c08550,0x00000310808085c1\n"
".quad 0x00000300710085c1,0x00000310718085c1,0x00000320800085c1,0x00000320714085c1\n"
".quad 0x0000000c40c000c1,0x0000001820800050,0x0000001400000050,0x0000030080c08550\n"
".quad 0x00000310808085c9,0x00000320800085c9,0xee0000ffffdc04c9,0x8ec0003d41dc2350\n"
".quad 0x000001e000a1e719,0x00c0001140008340,0x00c0003142000368,0x00c0003001c00350\n"
".quad 0x0000030080c08550,0x00000310808085c1,0x00000300710085c1,0x00000310718085c1\n"
".quad 0x00000320800085c1,0x00000320714085c1,0x0000000c40c000c1,0x0000001820800050\n"
".quad 0x0000001400000050,0x0000030080c08550,0x00000310808085c9,0x00000320800085c9\n"
".quad 0xee0000ffffdc04c9,0x8ec0003d41dc2350,0x000001e000a1e719,0x00c0000940008340\n"
".quad 0x00c0003142000368,0x00c0003001c00350,0x0000030080c08550,0x00000310808085c1\n"
".quad 0x00000300710085c1,0x00000310718085c1,0x00000320800085c1,0x00000320714085c1\n"
".quad 0x0000000c40c000c1,0x0000001820800050,0x0000001400000050,0x0000030080c08550\n"
".quad 0x00000310808085c9,0x00000320800085c9,0xee0000ffffdc04c9,0x8ec0003d41dc2350\n"
".quad 0x000001e000a1e719,0x00c0000540008340,0x00c0003142000368,0x00c0003001c00350\n"
".quad 0x0000030080c08550,0x00000310808085c1,0x00000300710085c1,0x00000310718085c1\n"
".quad 0x00000320800085c1,0x00000320714085c1,0x0000000c40c000c1,0x0000001820800050\n"
".quad 0x0000001400000050,0x0000030080c08550,0x00000310808085c9,0x00000320800085c9\n"
".quad 0x00000320000007c9,0xee0000ffffdc0460,0x8ec0003d41dc2350,0x000002a00021e719\n"
".quad 0x00c00031411c0340,0x00000303f21cc550,0x8ec0003d41dc23c1,0x0000000040dc8519\n"
".quad 0x00000010409c85c1,0x00000020401c85c1,0x06ef600080dc00c1,0x04ef6000909c0030\n"
".quad 0x00ef6000a01c0030,0x0000016000a1e730,0x00c000194100a340,0x0000000c31800050\n"
".quad 0x0000000c21c00058,0x0000000c02000058,0x00c0000840c20358,0x0000000822400060\n"
".quad 0x0000000801000058,0x0000000001400058,0x00000b003180a558,0x00000b203200a5c9\n"
".quad 0x00000b403100a5c9,0x00000000001df4c9,0xee0000ffffdc0440,0x00000020001de250\n"
".quad 0x0e00005001dc2318,0x0000012000a1e71a,0x0000005000c00340,0x00c000194080a348\n"
".quad 0x00c0001830c0a350,0x00c0000821020350,0x00c0000830820360,0x00000b0040c08560\n"
".quad 0x00000b00208085c1,0x00000008308000c1,0x00000b0040808550,0xee0000ffffdc04c9\n"
".quad 0x0000012000a1e750,0x0000005000c00340,0x00c000194080a348,0x00c0001830c0a350\n"
".quad 0x00c0000821020350,0x00c0000830820360,0x00000b1040c08560,0x00000b10208085c1\n"
".quad 0x00000008308000c1,0x00000b1040808550,0xee0000ffffdc04c9,0x0000012000a1e750\n"
".quad 0x0000005000c00340,0x00c000194080a348,0x00c0001830c0a350,0x00c0000821020350\n"
".quad 0x00c0000830820360,0x00000b2040c08560,0x00000b20208085c1,0x00000008308000c1\n"
".quad 0x00000b2040808550,0xee0000ffffdc04c9,0x0000012000a1e750,0x0000005000c00340\n"
".quad 0x00c000194080a348,0x00c0001830c0a350,0x00c0000821020350,0x00c0000830820360\n"
".quad 0x00000b3040c08560,0x00000b30208085c1,0x00000008308000c1,0x00000b3040808550\n"
".quad 0xee0000ffffdc04c9,0x0000012000a1e750,0x0000005000c00340,0x00c000194080a348\n"
".quad 0x00c0001830c0a350,0x00c0000821020350,0x00c0000830820360,0x00000b4040c08560\n"
".quad 0x00000b40208085c1,0x00000008308000c1,0x00000b4040808550,0xee0000ffffdc04c9\n"
".quad 0x0000012000a1e750,0x0000005000c00340,0x00c000194080a348,0x00c0001830c0a350\n"
".quad 0x00c0000821020350,0x00c0000830820360,0x00000b5040c08560,0x00000b50208085c1\n"
".quad 0x00000008308000c1,0x00000b5040808550,0xee0000ffffdc04c9,0x00c00004001c2350\n"
".quad 0x0e0000fc01dc2358,0x03fff7400001e71a,0x00000b33f55c8540,0x00000b03f41cc5c1\n"
".quad 0x00000b43f09ca5c1,0x00000055101c00c1,0x00000045015c0050,0x00000009211c0050\n"
".quad 0x0000000024dc0050,0x0000001525dc0050,0x00000010359c0050,0x1e00005d301c0050\n"
".quad 0x1e000001611c0008,0x0000cb4001000708,0x00000011301c0050,0x00000011715c0058\n"
".quad 0x00000011611c0058,0x00000044019c0058,0x0000005401dc0058,0x00000008001c0058\n"
".quad 0x0c000015019c0058,0x0e00004451dc0030,0x00000048501c0030,0x0c000011259c0030\n"
".quad 0x0e00000845dc0030,0x0000000c44dc0030,0x1e00005d601c0030,0x1e000001311c0008\n"
".quad 0x0000c96001000708,0x00000011715c0050,0x00000011301c0058,0x00000011611c0058\n"
".quad 0x00000044519c0058,0x0000005451dc0058,0x00000008521c0058,0x0c000011015c0058\n"
".quad 0x0e000044419c0030,0x10000048411c0030,0x0a00000124dc0030,0x0c000008059c0030\n"
".quad 0x0800000c05dc0030,0x1e000059301c0030,0x1e00005c011c0008,0x0000c78001000708\n"
".quad 0x00000058415c0050,0x0000004c401c0058,0x0000005c411c0058,0x00000044519c0058\n"
".quad 0x0000005451dc0058,0x00000008521c0058,0x0c000001015c0058,0x0e000044019c0030\n"
".quad 0x10000048001c0030,0x0a00001124dc0030,0x0c000008459c0030,0x0000000c45dc0030\n"
".quad 0x1e00004d601c0030,0x1e000001711c0008,0x0000c5a001000708,0x00000011601c0050\n"
".quad 0x00000011715c0058,0x0000004c411c0058,0x00000044019c0058,0x0000005401dc0058\n"
".quad 0x00000008001c0058,0x0c000011019c0058,0x0e00004441dc0030,0x00000048401c0030\n"
".quad 0x0c000015259c0030,0x0e00000855dc0030,0x0000000c54dc0030,0x1e00005d601c0030\n"
".quad 0x1e00004c011c0008,0x0000c3c001000708,0x00000011715c0050,0x00000011601c0058\n"
".quad 0x0000004c411c0058,0x00000044519c0058,0x0000005451dc0058,0x00000008521c0058\n"
".quad 0x0c000001015c0058,0x0e000044019c0030,0x10000048001c0030,0x0a00001124dc0030\n"
".quad 0x0c000008459c0030,0x0000000c45dc0030,0x1e000059301c0030,0x1e00005c011c0008\n"
".quad 0x0000c1e001000708,0x00000058415c0050,0x0000004c401c0058,0x0000005c411c0058\n"
".quad 0x00000044519c0058,0x0000005451dc0058,0x00000008521c0058,0x0c000001015c0058\n"
".quad 0x0e000044019c0030,0x10000048001c0030,0x0a00001124dc0030,0x0c000008459c0030\n"
".quad 0x0000000c45dc0030,0x1e00004d601c0030,0x1e000001711c0008,0x0000c00001000708\n"
".quad 0x00000011601c0050,0x00000011715c0058,0x0000004c411c0058,0x00000044019c0058\n"
".quad 0x0000005401dc0058,0x00000008001c0058,0x0c000011019c0058,0x0e00004441dc0030\n"
".quad 0x00000048401c0030,0x0c000015241c0030,0x0e000008509c0030,0x0000000c50dc0030\n"
".quad 0x1e000009001c0030,0x1e00000c011c0008,0x0000be2001000708,0x8ec0003d41dc2350\n"
".quad 0x00000010215c0019,0x00000011001c0058,0x00c00009409e0358,0x0000012000a1e760\n"
".quad 0x00c0003142000340,0x0000000c40c00050,0x0000001081c08558,0x00000000818085c1\n"
".quad 0x0000001471c000c1,0x0000002081408558,0x0e000000600000c1,0x0000000c50000030\n"
".quad 0x0000110020008530,0x00006440000007c9,0xee0000ffffdc0460,0x8ec0003d41dc2350\n"
".quad 0x000000000021f419,0x8e0000fd41dc0340,0x000063400000071a,0x000063000001e760\n"
".quad 0x00001103f5dc8540,0x000011c3f41cc5c1,0x00001183f31cc5c1,0x00001103f21cc5c1\n"
".quad 0x00001143f11cc5c1,0x00001113f01c85c1,0x0e00004d761c00c1,0x0e000045765c0012\n"
".quad 0x0e00003d769c0012,0x0000006126df8412,0x0e000029761c001c,0x0e00004170dc0012\n"
".quad 0x00000065271f8412,0x0e000025759c001c,0x00000069269f8412,0x0e000021765c001c\n"
".quad 0x00000061261f8412,0x0e000049755c001c,0x0000007030de0312,0x0e000031775c0048\n"
".quad 0x0e000011771c0012,0x00000069659e0312,0x00000061969e0348,0x0000006d555e0348\n"
".quad 0x0e00001977dc0048,0x0e00001d761c0012,0x00000075275f8412,0x0e00002d76dc001c\n"
".quad 0x00000071279f8412,0x0e000015765c001c,0x0000007d271f8412,0x00000075861e031c\n"
".quad 0x00000079b6de0348,0x0e000039775c0048,0x0e00004c079c0012,0x00000071965e0312\n"
".quad 0x0e000035771c0048,0x00000075275f8412,0x0e00004805dc001c,0x0000007927df8412\n"
".quad 0x0e000044079c001c,0x00000075c75e0312,0x0000007d771e0348,0x0e00004005dc0048\n"
".quad 0x00000079279f8412,0x00000075875c031c,0x0e000024061c0048,0x0000007975de0312\n"
".quad 0x0e00003c079c0048,0x00000075975c0312,0x0e000020065c0048,0x00000079279f8412\n"
".quad 0x00000075b6dc031c,0x0e00002c075c0048,0x00000079861e0312,0x0e000028079c0048\n"
".quad 0x0000006da6dc0312,0x0e000014069c0048,0x00000079279f8412,0x0000006d66dc031c\n"
".quad 0x0e00001c059c0048,0x00000079965e0312,0x0e000010079c0048,0x0000006c36dc0312\n"
".quad 0x00000079279f8448,0x0000006d555c031c,0x00000079d75e0348,0x0e000018079c0048\n"
".quad 0x00000603f55c8512,0x00000079279f84c9,0x00000079a69e031c,0x0e000030079c0048\n"
".quad 0x00000079279f8412,0x00000079679e031c,0x0e000038059c0048,0x0e000034001c0012\n"
".quad 0x00000059259f8412,0x00000058001e031c,0x00001123f59c8548,0x00000001e79c03c1\n"
".quad 0x00000079a69c0348,0x0e00004d601c0048,0x0e000049679c0012,0x00000069d75c0312\n"
".quad 0x00000001201f8448,0x0e000041669c001c,0x00000075975c0312,0x00000001e01e0348\n"
".quad 0x0e000045679c0048,0x0e000025665c0012,0x0e00002967dc0012,0x00000079279f8412\n"
".quad 0x0e00002d60dc001c,0x0e00001d66dc0012,0x00000079a69e0312,0x0e00003d679c0048\n"
".quad 0x00000079279f8412,0x00000079965e031c,0x00000075879c0348,0x0e000021661c0048\n"
".quad 0x0000007d275f8412,0x0e00001967dc001c,0x00000075861e0312,0x0e000011675c0048\n"
".quad 0x00000075275f8412,0x00000074375e031c,0x0000007970dc0348,0x0e00001565dc0048\n"
".quad 0x0000007d279f8412,0x0000000dc0dc031c,0x0000007975de0348,0x0e000031679c0048\n"
".quad 0x00000613f0dc8512,0x00000079279f84c9,0x00000079b79e031c,0x0e00003966dc0048\n"
".quad 0x0e000035659c0012,0x0000006d26df8412,0x0000006d659e031c,0x00001133f6dc8548\n"
".quad 0x00000059e79c03c1,0x0000007975dc0348,0x0e00004db59c0048,0x0e000049b79c0012\n"
".quad 0x0000005dd75c0312,0x00000059259f8448,0x0e000041b5dc001c,0x00000075875c0312\n"
".quad 0x00000059e59e0348,0x0e000045b79c0048,0x0e000025b61c0012,0x00000075975c0312\n"
".quad 0x00000079279f8448,0x0e000021b65c001c,0x00000075a75c0312,0x0000007975de0348\n"
".quad 0x0e00003db79c0048,0x0e00002db69c0012,0x0e000015b71c0012,0x00000079279f8412\n"
".quad 0x00000074001c031c,0x0e00001db75c0048,0x00000079861e0312,0x0e000029b79c0048\n"
".quad 0x00000623f01c8512,0x00000079279f84c9,0x00000079965e031c,0x0e000011b79c0048\n"
".quad 0x00000079279f8412,0x00000079a69e031c,0x0e000019b79c0048,0x00000079279f8412\n"
".quad 0x00000079c79e031c,0x0e000031b71c0048,0x00000071271f8412,0x00000071d75e031c\n"
".quad 0x0e000039b71c0048,0x0e000035b6dc0012,0x00000071271f8412,0x00000071b6de031c\n"
".quad 0x00001143f71c8548,0x0000006dd75c03c1,0x00000075e75c0348,0x0e00004dc6dc0048\n"
".quad 0x0e000049c79c0012,0x00000075a75c0312,0x0000006d26df8448,0x0e000041c69c001c\n"
".quad 0x00000075975c0312,0x0000006de6de0348,0x0e000045c79c0048,0x0e000025c65c0012\n"
".quad 0x00000075861c0312,0x00000079279f8448,0x0e000021c75c001c,0x0000006175dc0312\n"
".quad 0x00000079a69e0348,0x0e00003dc79c0048,0x0e00002dc61c0012,0x0000005d659c0312\n"
".quad 0x00000079279f8448,0x0e000015c5dc001c,0x0e000031c7dc0012,0x00000079965e0312\n"
".quad 0x0e000029c79c0048,0x0000007d27df8412,0x00000633f59c851c,0x00000079279f84c9\n"
".quad 0x00000079d75e031c,0x0e000011c79c0048,0x00000079279f8412,0x00000079861e031c\n"
".quad 0x0e000019c79c0048,0x00000079279f8412,0x0000007975de031c,0x0e00001dc79c0048\n"
".quad 0x0000007de55e0312,0x0e000039c79c0048,0x0e000035c71c0012,0x00000079279f8412\n"
".quad 0x00000079c71e031c,0x00001153f79c8548,0x00000071555c03c1,0x00000055755c0348\n"
".quad 0x0e00004de71c0048,0x0e000049e5dc0012,0x00000055855c0312,0x00000071271f8448\n"
".quad 0x0e000041e61c001c,0x00000055d55c0312,0x0000007175de0348,0x0e000045e71c0048\n"
".quad 0x0e000025e75c0012,0x00000055955c0312,0x00000071271f8448,0x0e000021e65c001c\n"
".quad 0x00000055a55c0312,0x00000071861e0348,0x0e00003de71c0048,0x0e00002de69c0012\n"
".quad 0x00000055b55c0312,0x00000071271f8448,0x0e000015e6dc001c,0x0e000031e7dc0012\n"
".quad 0x00000071d71e0312,0x0e000029e75c0048,0x0000007d27df8412,0x00000643f55c851c\n"
".quad 0x00000075275f84c9,0x00000075975e031c,0x0e000011e65c0048,0x00000065265f8412\n"
".quad 0x00000065a69e031c,0x0e000019e65c0048,0x00000065265f8412,0x00000065b65e031c\n"
".quad 0x0e00001de6dc0048,0x0000007db0de0312,0x0e000039e7dc0048,0x0e000035e6dc0012\n"
".quad 0x0000007d279f8412,0x00000079b6de031c,0x00001163f79c8548,0x0000006c30dc03c1\n"
".quad 0x0000000d90dc0348,0x0e00004de6dc0048,0x0e000049e65c0012,0x0000000da0dc0312\n"
".quad 0x0000006d26df8448,0x0e000041e69c001c,0x0000000dd0dc0312,0x0000006d965e0348\n"
".quad 0x0e000045e6dc0048,0x0e000025e75c0012,0x0000000dc0dc0312,0x0000006d26df8448\n"
".quad 0x0e000021e71c001c,0x0000000d80dc0312,0x0000006da69e0348,0x0e00003de6dc0048\n"
".quad 0x0e00002de61c0012,0x0000000d70dc0312,0x0000006d26df8448,0x0e000015e5dc001c\n"
".quad 0x0e000031e7dc0012,0x0000006dd6de0312,0x0e000029e75c0048,0x0000007d27df8412\n"
".quad 0x00000653f0dc851c,0x00000075275f84c9,0x00000075c71e031c,0x0e000011e75c0048\n"
".quad 0x00000075275f8412,0x00000075861e031c,0x0e000019e75c0048,0x00000075275f8412\n"
".quad 0x0000007575de031c,0x0e00001de75c0048,0x0000007dd01e0312,0x0e000039e7dc0048\n"
".quad 0x0e000035e75c0012,0x0000007d279f8412,0x00000079d79e031c,0x00001173f75c8548\n"
".quad 0x00000078001c03c1,0x00000001701c0348,0x0e00004dd79c0048,0x0e000049d5dc0012\n"
".quad 0x00000001801c0312,0x00000079279f8448,0x0e000041d61c001c,0x00000001c01c0312\n"
".quad 0x0000007975de0348,0x0e000045d79c0048,0x0e000025d71c0012,0x00000001b01c0312\n"
".quad 0x00000079279f8448,0x0e000021d6dc001c,0x00000001a01c0312,0x00000079861e0348\n"
".quad 0x0e00003dd79c0048,0x0e00002dd69c0012,0x00000001901c0312,0x00000079279f8448\n"
".quad 0x0e000015d65c001c,0x0e000031d7dc0012,0x00000079c71e0312,0x0e000029d79c0048\n"
".quad 0x0000007d27df8412,0x00000663f01c851c,0x00000079279f84c9,0x00000079b6de031c\n"
".quad 0x0e000011d79c0048,0x00000079279f8412,0x00000079a69e031c,0x0e000019d79c0048\n"
".quad 0x00000079279f8412,0x00000079965e031c,0x0e00001dd79c0048,0x0000007de59e0312\n"
".quad 0x0e000039d79c0048,0x0e000035d75c0012,0x00000079279f8412,0x00000079d79e031c\n"
".quad 0x00001183f75c8548,0x00000079659c03c1,0x00000059959c0348,0x0e00004dd79c0048\n"
".quad 0x0e000049d65c0012,0x00000059a59c0312,0x00000079279f8448,0x0e000041d69c001c\n"
".quad 0x00000059b59c0312,0x00000079965e0348,0x0e000045d79c0048,0x0e000025d6dc0012\n"
".quad 0x00000059c59c0312,0x00000079279f8448,0x0e000021d71c001c,0x00000059859c0312\n"
".quad 0x00000079a69e0348,0x0e00003dd79c0048,0x0e00002dd61c0012,0x00000059759c0312\n"
".quad 0x00000079279f8448,0x0e000015d5dc001c,0x0e000031d7dc0012,0x00000079b6de0312\n"
".quad 0x0e000029d79c0048,0x0000007d27df8412,0x00000673f59c851c,0x00000079279f84c9\n"
".quad 0x00000079c71e031c,0x0e000011d79c0048,0x00000079279f8412,0x00000079861e031c\n"
".quad 0x0e000019d79c0048,0x00000079279f8412,0x0000007975de031c,0x0e00001dd79c0048\n"
".quad 0x0000007de55e0312,0x0e000039d79c0048,0x0e000035d75c0012,0x00000079279f8412\n"
".quad 0x00000079d79e031c,0x00001193f75c8548,0x00000079555c03c1,0x00000055755c0348\n"
".quad 0x0e00004dd79c0048,0x0e000049d5dc0012,0x00000055855c0312,0x00000079279f8448\n"
".quad 0x0e000041d61c001c,0x00000055c55c0312,0x0000007975de0348,0x0e000045d79c0048\n"
".quad 0x0e000025d71c0012,0x00000055b55c0312,0x00000079279f8448,0x0e000021d6dc001c\n"
".quad 0x00000055a55c0312,0x00000079861e0348,0x0e00003dd79c0048,0x0e00002dd69c0012\n"
".quad 0x00000055955c0312,0x00000079279f8448,0x0e000015d65c001c,0x0e000031d7dc0012\n"
".quad 0x00000079c71e0312,0x0e000029d79c0048,0x0000007d27df8412,0x00000683f55c851c\n"
".quad 0x00000079279f84c9,0x00000079b6de031c,0x0e000011d79c0048,0x00000079279f8412\n"
".quad 0x00000079a69e031c,0x0e000019d79c0048,0x00000079279f8412,0x00000079965e031c\n"
".quad 0x0e00001dd79c0048,0x0000007de0de0312,0x0e000039d79c0048,0x0e000035d75c0012\n"
".quad 0x00000079279f8412,0x00000079d79e031c,0x000011a3f75c8548,0x0000007830dc03c1\n"
".quad 0x0000000d90dc0348,0x0e00004dd79c0048,0x0e000049d65c0012,0x0000000da0dc0312\n"
".quad 0x00000079279f8448,0x0e000041d69c001c,0x0000000db0dc0312,0x00000079965e0348\n"
".quad 0x0e000045d79c0048,0x0e000025d6dc0012,0x0000000dc0dc0312,0x00000079279f8448\n"
".quad 0x0e000021d71c001c,0x0000000d80dc0312,0x00000079a69e0348,0x0e00003dd79c0048\n"
".quad 0x0e00002dd61c0012,0x0000000d70dc0312,0x00000079279f8448,0x0e000015d5dc001c\n"
".quad 0x0e000031d7dc0012,0x00000079b6de0312,0x0e000029d79c0048,0x0000007d27df8412\n"
".quad 0x00000693f0dc851c,0x00000079279f84c9,0x00000079c71e031c,0x0e000011d79c0048\n"
".quad 0x00000079279f8412,0x00000079861e031c,0x0e000019d79c0048,0x00000079279f8412\n"
".quad 0x0000007975de031c,0x0e00001dd79c0048,0x0000007de01e0312,0x0e000039d79c0048\n"
".quad 0x0e000035d75c0012,0x00000079279f8412,0x00000079d79e031c,0x000011b3f75c8548\n"
".quad 0x00000078001c03c1,0x00000001701c0348,0x0e00004dd79c0048,0x0e000049d5dc0012\n"
".quad 0x00000001801c0312,0x00000079279f8448,0x0e000041d61c001c,0x00000001c01c0312\n"
".quad 0x0000007975de0348,0x0e000045d79c0048,0x0e000025d71c0012,0x00000001b01c0312\n"
".quad 0x00000079279f8448,0x0e000021d6dc001c,0x00000001a01c0312,0x00000079861e0348\n"
".quad 0x0e00003dd79c0048,0x0e00002dd69c0012,0x00000001901c0312,0x00000079279f8448\n"
".quad 0x0e000015d65c001c,0x0e000031d7dc0012,0x00000079c71e0312,0x0e000029d79c0048\n"
".quad 0x0000007d27df8412,0x000006a3f01c851c,0x00000079279f84c9,0x00000079b6de031c\n"
".quad 0x0e000011d79c0048,0x00000079279f8412,0x00000079a69e031c,0x0e000019d79c0048\n"
".quad 0x00000079279f8412,0x00000079965e031c,0x0e00001dd79c0048,0x0000007de59e0312\n"
".quad 0x0e000039d79c0048,0x0e000035d75c0012,0x00000079279f8412,0x00000079d79e031c\n"
".quad 0x000011c3f75c8548,0x00000079659c03c1,0x00000059959c0348,0x0e00004dd79c0048\n"
".quad 0x0e000049d65c0012,0x00000059a59c0312,0x00000079279f8448,0x0e000041d69c001c\n"
".quad 0x00000059b59c0312,0x00000079965e0348,0x0e000045d79c0048,0x0e000025d6dc0012\n"
".quad 0x00000059c59c0312,0x00000079279f8448,0x0e000021d71c001c,0x00000059859c0312\n"
".quad 0x00000079a69e0348,0x0e00003dd79c0048,0x0e00002dd61c0012,0x00000059759c0312\n"
".quad 0x00000079279f8448,0x0e000015d5dc001c,0x0e000031d7dc0012,0x00000079b6de0312\n"
".quad 0x0e000029d79c0048,0x0000007d27df8412,0x000006b3f59c851c,0x00000079279f84c9\n"
".quad 0x00000079c71e031c,0x0e000011d79c0048,0x00000079279f8412,0x00000079861e031c\n"
".quad 0x0e000019d79c0048,0x00000079279f8412,0x0000007975de031c,0x0e00001dd79c0048\n"
".quad 0x0000007de55e0312,0x0e000039d79c0048,0x0e000035d75c0012,0x00000079279f8412\n"
".quad 0x00000079d79e031c,0x000011d3f75c8548,0x00000079579c03c1,0x0000007975dc0348\n"
".quad 0x0e00004dd55c0048,0x0e000049d79c0012,0x0000005d861c0312,0x00000055255f8448\n"
".quad 0x0e000041d5dc001c,0x00000061c71c0312,0x00000055e55e0348,0x0e000045d79c0048\n"
".quad 0x0e000025d61c0012,0x00000071b6dc0312,0x00000079279f8448,0x0e000021d71c001c\n"
".quad 0x0000006da69c0312,0x0000007975de0348,0x0e00003dd79c0048,0x0e00002dd6dc0012\n"
".quad 0x00000069965c0312,0x00000079279f8448,0x0e000015d69c001c,0x0e000031d7dc0012\n"
".quad 0x00000079861e0312,0x0e000029d79c0048,0x0000007d27df8412,0x0e000035d0dc001c\n"
".quad 0x00000079279f8412,0x000006c3f65c851c,0x00000079c71e03c9,0x0e000011d79c0048\n"
".quad 0x00000079279f8412,0x00000079b6de031c,0x0e000019d79c0048,0x00000079279f8412\n"
".quad 0x00000079a69e031c,0x0e00001dd79c0048,0x0000007de79e0312,0x0e000039d7dc0048\n"
".quad 0x0000007d275f8412,0x00000074375e031c,0x000011e3f0dc8548,0x00000075e75c03c1\n"
".quad 0x00000075a75c0348,0x0e00004c379c0048,0x0e000048369c0012,0x00000075b75c0312\n"
".quad 0x00000079279f8448,0x0e00004036dc001c,0x00000075c75c0312,0x00000079a69e0348\n"
".quad 0x0e000044379c0048,0x0e000024371c0012,0x00000075875c0312,0x00000079279f8448\n"
".quad 0x0e000020361c001c,0x00000075775c0312,0x00000079b6de0348,0x0e00003c379c0048\n"
".quad 0x0e00002c35dc0012,0x00000075555c0312,0x00000079279f8448,0x0e000014375c001c\n"
".quad 0x0e00003037dc0012,0x00000079c71e0312,0x0e000028379c0048,0x0000007d27df8412\n"
".quad 0x000006d3f55c851c,0x00000079279f84c9,0x00000079861e031c,0x0e000010379c0048\n"
".quad 0x00000079279f8412,0x0000007975de031c,0x0e000018379c0048,0x00000079279f8412\n"
".quad 0x00000079d75e031c,0x0e00001c379c0048,0x0000007de01e0312,0x0e000038379c0048\n"
".quad 0x0e00003430dc0012,0x00000079279f8412,0x00000078379e031c,0x000011f3f0dc8548\n"
".quad 0x00000078001c03c1,0x00000001d01c0348,0x0e000044345c0048,0x0e00004c34dc0012\n"
".quad 0x0e000030359c0012,0x0e00003c33dc0012,0x0e000038375c0012,0x0e000048349c0012\n"
".quad 0x0e000040341c0012,0x0e000024325c0012,0x0e000020321c0012,0x0e000028329c0012\n"
".quad 0x0e00002c32dc0012,0x0e000010311c0012,0x0e000014315c0012,0x0e000018319c0012\n"
".quad 0x0e00001c31dc0012,0x0e000034335c0012,0x00000045231f8412,0x0000004d20df841c\n"
".quad 0x00000059245f841c,0x0000003d239f841c,0x0000007524df841c,0x0000001923df841c\n"
".quad 0x00000044719e031c,0x0000004cd1de0348,0x00000011211f8448,0x0000003c515e031c\n"
".quad 0x0000001c619c0348,0x0000002921df8448,0x00000010b11e031c,0x00000018519c0348\n"
".quad 0x0000001c815e0348,0x00000001701c0348,0x00000018419c0348,0x00000038911e0348\n"
".quad 0x00000001801c0348,0x00000018519c0348,0x00000031015e0348,0x00000001c01c0348\n"
".quad 0x00000018419c0348,0x0000000d211e0348,0x00000001b01c0348,0x00000018515c0348\n"
".quad 0x00000001a0dc0348,0x00000014411c0348,0x000000fc001de448,0x000006e3f0dc8528\n"
".quad 0x000006f3f11c85c9,0x8e000003f1dc23c9,0x000000c00001e719,0x00c00008011e0340\n"
".quad 0x00000603f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000603f0e08548,0x0ec0000401dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000613f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000613f0e08548,0x0ec0000801dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000623f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000623f0e08548,0x0ec0000c01dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000633f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000633f0e08548,0x0ec0001001dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000643f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000643f0e08548,0x0ec0001401dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000653f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000653f0e08548,0x0ec0001801dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000663f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000663f0e08548,0x0ec0001c01dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000673f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000673f0e08548,0x0ec0002001dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000683f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000683f0e08548,0x0ec0002401dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x00000693f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x00000693f0e08548,0x0ec0002801dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006a3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006a3f0e08548,0x0ec0002c01dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006b3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006b3f0e08548,0x0ec0003001dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006c3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006c3f0e08548,0x0ec0003401dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006d3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006d3f0e08548,0x0ec0003801dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006e3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006e3f0e08548,0x0ec0003c01dc23c9,0x000000c00001e71b,0x00c00008011e0340\n"
".quad 0x000006f3f0dc8560,0x00000600411c85c1,0x8e00000c41dc23c1,0x00c0000430e0031a\n"
".quad 0x000006f3f0e08548,0x00c00004001c03c9,0x8ec0003c01dc2348,0x03ffefa00001e71a\n"
".quad 0x00c00031415c1340,0x00000000501c8550,0x0000001050dc85c1,0x00000020511c95c1\n"
".quad 0xee0000ffffdc04c1,0x8ec0003d41dc2350,0x000000a000a1e719,0x0000060021408540\n"
".quad 0x00c00030514003c1,0x0000000050008550,0x0000001050c085c9,0x00000020510085c9\n"
".quad 0x00002340000007c9,0xee0000ffffdc0468,0x000000fc041de450,0xfdfffffc055de228\n"
".quad 0x00000051001c0319,0x0ec00f7c01dc2348,0x000000000001e71a,0x00c00008011e03a8\n"
".quad 0x0ec0027c01dc2360,0x00400080415c031a,0x0000000054dc8548,0x00c0000d301c0380\n"
".quad 0x00c00009315c0368,0x0000120044e08558,0x00c00011319c03c9,0x00c0001931dc0358\n"
".quad 0x00c00008001e0358,0x00c0000c521c0360,0x00c00021325c0368,0x00c0000c635c0358\n"
".quad 0x00c0000c73dc0368,0x00000003f11cc568,0x00c00008831e03c1,0x00080030069c8660\n"
".quad 0x00c0000c959c0314,0x00000043f21cc568,0x00080030c65c86c1,0x00c00008d35e0314\n"
".quad 0x7e000068515c0060,0x7e000068671c0030,0x7e000068411c0030,0x0a00006486dc0030\n"
".quad 0x00c00029361c0330,0x38000064921c0058,0x00080030d25c8630,0x00c00008f3de0314\n"
".quad 0x08000064769c0060,0x00000083f11cc530,0x00c0000d865c03c1,0x00080030f61c8668\n"
".quad 0x34000024a69c0014,0x00c00009659e0330,0x00c0003135dc0360,0x36000024b6dc0058\n"
".quad 0x10000024411c0030,0x34000060515c0030,0x000000c3f21cc530,0x00080031669c86c1\n"
".quad 0x00c0000d771c0314,0x00c0000995de0368,0x36000060665c0060,0x0800006076dc0030\n"
".quad 0x0a000068821c0030,0x32000068975c0030,0x00000103f11cc530,0x00080031725c86c1\n"
".quad 0x36000068a29c0014,0x00c00009c61e0330,0x000800b0001c8660,0x000800b0c31c8614\n"
".quad 0x10000024b71c0014,0x3a000024475c0030,0x14000024569c0030,0x00080031865c8630\n"
".quad 0x00000143f21cc514,0x000800b0d35c86c1,0x00c00039339c0314,0x00c0004136dc0358\n"
".quad 0x3a000064715c0058,0x38000064611c0030,0x34000064875c0030,0x00000000c65c0330\n"
".quad 0x000800b0f31c8648,0x00c0000ce39c0314,0x00c00049319c0368,0x00c0005131dc0358\n"
".quad 0x00000064d3dc0358,0x00c00008e65e0348,0x000800b1635c8660,0x0000003cc3dc0314\n"
".quad 0x00c0000db31c0348,0x0008003196dc8668,0x00c0000c639c0314,0x00c00008c31e0368\n"
".quad 0x0000003cd3dc0360,0x00c0000c735c0348,0x0800006c925c0068,0x0a00006ca29c0030\n"
".quad 0x000800b175dc8630,0x3a00006cb2dc0014,0x00000183f11cc530,0x00080030c75c86c1\n"
".quad 0x00c00061321c0314,0x00c00059371c0358,0x00c00008e39e0358,0x0000003d76dc0360\n"
".quad 0x000800b1861c8648,0x00c0000c85dc0314,0x12000074411c0068,0x14000074515c0030\n"
".quad 0x16000074619c0030,0x00c0000dc3dc0330,0x000001c3f21cc568,0x00080030e71c86c1\n"
".quad 0x00c00069301c0314,0x00c00071369c0358,0x000800b1965c8658,0x0000006d86dc0314\n"
".quad 0x00c0000c061c0348,0x00c00008d35e0368,0x00c0000da01c0360,0x0a000070879c0068\n"
".quad 0x000800b0c31c8630,0x00c00008f69e0314,0x0c000070921c0060,0x0000006d93dc0330\n"
".quad 0x00080030d25c8648,0x000800b0e39c8614,0x08000070775c0014,0x00000203f11cc530\n"
".quad 0x0000003cc31c03c1,0x00080031a65c8648,0x000800b0d7dc8614,0x3a000024a29c0014\n"
".quad 0x00000030e71c0330,0x000800b1a75c8648,0x00c0000975de0314,0x3c000024b6dc0060\n"
".quad 0x00000303f31cc530,0x10000024411c00c1,0x14000064515c0030,0x00000071f71c0330\n"
".quad 0x00000243f21cc548,0x00c0000983de03c1,0x00080031769c8660,0x000800b1761c8614\n"
".quad 0x36000064619c0014,0x00000071d71c0330,0x0800006476dc0048,0x0a000068821c0030\n"
".quad 0x0c000068965c0030,0x00000071861c0330,0x00000283f11cc548,0x00c00079359c03c1\n"
".quad 0x00c00008071e0358,0x00080030f5dc8660,0x000800b0f01c8614,0x00c0000d659c0314\n"
".quad 0x36000068a69c0068,0x1000005cb6dc0030,0x3200005c43dc0030,0x00c00009659e0330\n"
".quad 0x00080031c11c8660,0x000800b1c65c8614,0x3400005c569c0014,0x000002c3f21cc530\n"
".quad 0x00000060001c03c1,0x00080031615c8648,0x000800b165dc8614,0x36000010619c0014\n"
".quad 0x00000001901c0330,0x1e00001071dc0048,0x34000010811c0030,0x0c000014959c0030\n"
".quad 0x00000001719c0330,0x0e000014a5dc0048,0x08000014b61c0030,0x00c00020615c2330\n"
".quad 0x00c00040611c2358,0x00c003fc601c0358,0x00c003fc515c0368,0x000000112b9e0468\n"
".quad 0x000000012b5e0418,0x000000152c1e0418,0x2cd04400c65d0018,0x2ed04400d69d0030\n"
".quad 0x30d04400ebdd0030,0x000000c2e01c0030,0x00000066d6dc0058,0x0000006ad71c0058\n"
".quad 0x000000bed75c0058,0x0000005b079c0058,0x0000005f07dc0058,0x000000630b1c0058\n"
".quad 0x000000b6d11e0058,0x00003fc001000730,0x0000006ae21c0050,0x00000076c19d0058\n"
".quad 0x00000071f15d0050,0x00000066e1dc0050,0x1000005ed21e0058,0x000000bee29c0030\n"
".quad 0x00000018425c0058,0x00000014415c0058,0x0e00005ad19e0058,0x0000001081dc0030\n"
".quad 0x0000006de01d0058,0x14000062d29e0050,0x00000015215c2430,0x0000001d21dc2410\n"
".quad 0x00000000401c0010,0x00000010a2dc0058,0x00000010619c0058,0x00d09f00511c0058\n"
".quad 0x00d09f00715c0058,0x00000001201c2458,0x0000001921dc2410,0x00000025225c2410\n"
".quad 0x00d07e00001c0010,0x00d07e0071dc0058,0x0000002d22dc2458,0x00000001201c8410\n"
".quad 0x0000001d221c8410,0x00d07e00925c0010,0xf410d5c4039c0258,0xf410d5c481dc0230\n"
".quad 0x00d07e00b2dc0030,0x00000011211c8458,0x00000038731c0010,0x00000015215c8458\n"
".quad 0x00000025225c8410,0x00000032d31c0010,0x0000002d22dc8458,0xf206c46443dc0210\n"
".quad 0xf206c464519c0230,0x18000058e35e0030,0x00000038e59c0030,0xf410d5c4931c0258\n"
".quad 0xf410d5c4b39c0230,0x0000003c629c0030,0x0000005ae59c0058,0x00000030e6dc0058\n"
".quad 0x0000002ad29c0058,0x06000001201c0458,0x0000006ed6dc0014,0x1400005cf29e0058\n"
".quad 0x00000030c5dc0030,0x36000060c31e0058,0x0000003cf3dc0030,0x06000011261c0458\n"
".quad 0x06000015211c0414,0x14000019a29e0014,0x0000003ee3dc0030,0x00000018619c0058\n"
".quad 0x00c00015815c0358,0x0000001c761c0060,0x1a00001d91de0058,0x1e00001b03dc0030\n"
".quad 0x00000028a35c0030,0x0000005ee5dc0050,0x00000038e69c0058,0x06000021219c0458\n"
".quad 0x1800003af29e0014,0x2c000063021c0030,0x0000001c71dc0030,0x00000034f31c0050\n"
".quad 0x2e00006b059c0050,0x00000028a29c0030,0x0000001c81dc0050,0x00480010c31c0050\n"
".quad 0x00000029621c0058,0x00c0002c001c0350,0x18480000729c0060,0x00c0001441dc0330\n"
".quad 0x00c0002c611c0360,0x14480020819c0060,0x00000014001c4330,0x0000001c415c4368\n"
".quad 0xf78e38e461dc0268,0x06000025211c0430,0x0600002d219c0414,0x8e00005471dc0014\n"
".quad 0x00000010001c4320,0x00000018511c4368,0x0000008000a1e768,0x0000000114400440\n"
".quad 0x000000111480041c,0x0000001c0541e41c,0x0000004c00c1e428,0x00c00101041c0328\n"
".quad 0x8ec0100101dc2348,0x000000000021e71a,0x03ffdd20001de7a8,0x00000048a01c0440\n"
".quad 0x00000044a59c041c,0x0000000005dde41c,0x8e00005801dc0328,0x000000600081e719\n"
".quad 0x0000005805e1e440,0x0000000005a1e428,0x5555555430e08228,0x000000fc061de439\n"
".quad 0x0000240000000728,0x00000051801cc368,0x0ec0027c01dc2340,0x000000000001e71a\n"
".quad 0x00c00008001e03a8,0x00000003f21cc560,0x00000043f11cc5c1,0x00001200065c85c1\n"
".quad 0x00c0000d901c03c1,0x00c00009931c0368,0x00c00011935c0358,0x00c00008001e0358\n"
".quad 0x00c0000cc31c0360,0x00c0000cd35c0368,0x00080070069c8668,0x00c00008c41e0314\n"
".quad 0x00c00008d45e0360,0x00000083f31cc560,0x00080071049c86c1,0x7e000068821c0014\n"
".quad 0x7e000068925c0030,0x7e000068a69c0030,0x0008007114dc8630,0x10000048b6dc0014\n"
".quad 0x12000048411c0030,0x34000048571c0030,0x00c00019949c0330,0x00c00021969c0358\n"
".quad 0x3600004c615c0058,0x00c0000d249c0330,0x00c0000da69c0368,0x00c0002996dc0368\n"
".quad 0x00c00009249e0358,0x0800004c711c0060,0x3800004cc79c0030,0x0008007121dc8630\n"
".quad 0x00c00009a69e0314,0x00c0000db31c0360,0x000000c3f21cc568,0x00080071a4dc86c1\n"
".quad 0x00c00031919c0314,0x00c00008c6de0358,0x0a00001cd15c0060,0x0800001ce11c0030\n"
".quad 0x00c00039971c0330,0x00c0000c675c0358,0x00080071b31c8668,0x3c00001cf3dc0014\n"
".quad 0x0a00004c821c0030,0x0800004c935c0030,0x00c0000dc39c0330,0x00000103f11cc568\n"
".quad 0x00c00009d71e03c1,0x1e00004ca75c0060,0x10000030b79c0030,0x00080071c3dc8630\n"
".quad 0x00000143f21cc514,0x1a000030411c00c1,0x3a000030515c0030,0x00c00008e4de0330\n"
".quad 0x3c00003c639c0060,0x0800003c735c0030,0x0a00003c83dc0030,0x000800f1021c8630\n"
".quad 0x000800f0001c8614,0x00080071331c8614,0x00000183f11cc514,0x000800f1141c86c1\n"
".quad 0x1c000030925c0014,0x1a000030a29c0030,0x00000000845c0330,0x00c00041921c0348\n"
".quad 0x000800f1201c8658,0x00000045045c0314,0x00c0000c841c0348,0x000800f1a21c8668\n"
".quad 0x00c00049949c0314,0x00000044075c0358,0x00c00009001e0348,0x000800f1b69c8660\n"
".quad 0x00c0000d249c0314,0x00c00051945c0368,0x1e000030b2dc0058,0x0000007486dc0330\n"
".quad 0x00080070021c8648,0x00c00009241e0314,0x00c0000d149c0360,0x0000006da45c0368\n"
".quad 0x000001c3f31cc548,0x00080071069c86c1,0x000800f1c6dc8614,0x12000020411c0014\n"
".quad 0x14000020515c0030,0x16000020619c0030,0x00c00009249e0330,0x08000068771c0060\n"
".quad 0x0a000068c31c0030,0x0c000068d35c0030,0x00000303f11cc530,0x00080071275c86c1\n"
".quad 0x000800f131dc8614,0x00000045b45c0314,0x00c0005996dc0348,0x00000203f21cc558\n"
".quad 0x38000074e4dc00c1,0x00c0000db71c0330,0x000800f106dc8668,0x0000004471dc0314\n"
".quad 0x18000074f69c0048,0x1a000074821c0030,0x000800f0045c8630,0x00c00061975c0314\n"
".quad 0x00c00009c41e0358,0x00000243f31cc560,0x00c0000dd01c03c1,0x0000001d145c0368\n"
".quad 0x00080071075c8648,0x000800f121dc8614,0x00000045b45c0314,0x00c00008001e0348\n"
".quad 0x000800f106dc8660,0x26000074971c0014,0x0000004471dc0330,0x10000074b25c0048\n"
".quad 0x00c0006992dc0330,0x00080070021c8658,0x34000074a69c0014,0x0000001db29c0330\n"
".quad 0x00c0000cb1dc0348,0x00c00071975c0368,0x38000020c2dc0058,0x000800f006dc8630\n"
".quad 0x00c00079971c0314,0x00c0000871de0358,0x34000020d31c0060,0x00c0000dd35c0330\n"
".quad 0x00000283f41cc568,0x00080070701c86c1,0x00c0000dc69c0314,0x12000020e39c0068\n"
".quad 0x00c00008d71e0330,0x00c00009a35e0360,0x000800f071dc8660,0x16000000f3dc0014\n"
".quad 0x18000001041c0030,0x1c000001139c0030,0x00000029b6dc0330,0x00080070d01c8648\n"
".quad 0x000800f1c69c8614,0x00080071c31c8614,0x000002c3f21cc514,0x0000006c71dc03c1\n"
".quad 0x000800f0d35c8648,0x1e00003123dc0014,0x0000001da1dc0330,0x20000031345c0048\n"
".quad 0x1c000030831c0030,0x0000001cd21c0330,0x1e000000941c0048,0x22000000a45c0030\n"
".quad 0x18000000b49c0030,0x00c003fc801c0330,0x00c0004081dc2368,0x00c00020821c2358\n"
".quad 0x20d0200044dd0058,0x0000001d2b9e0430,0x00c003fc811c0318,0x000000012b5e0468\n"
".quad 0x22d02000569d0018,0x000000112c1e0430,0x24d020006bdd0018,0x0000004ed6dc0030\n"
".quad 0x000000c2e01c0058,0x0000006ad71c0058,0x000000bed75c0058,0x00000043079c0058\n"
".quad 0x0000004707dc0058,0x0000004b0b1c0058,0x000000b6d11e0058,0x00001c0001000730\n"
".quad 0x00000071f15d0050,0x0000006ae21c0050,0x00000076c19d0058,0x0000004ee1dc0050\n"
".quad 0x00000014415c0058,0x10000046d21e0058,0x00000018425c0030,0x000000bee29c0058\n"
".quad 0x0e000042d19e0058,0x0000006de01d0030,0x0000001081dc0050,0x00000015215c2458\n"
".quad 0x1400004ad29e0010,0x00000000401c0030,0x0000001d21dc2458,0x00d09f00515c0010\n"
".quad 0x00000010619c0058,0x00000010a2dc0058,0x00d09f0071dc0058,0x00000001211c2458\n"
".quad 0x00000015221c8410,0x00000019215c2410,0x0000001d201c8410,0x00d07e00411c0010\n"
".quad 0x00d07e0051dc0058,0x00000025225c2458,0x00000011215c8410,0x0000001d211c8410\n"
".quad 0x0000002d22dc2410,0xf410d5c4539c0210,0xf410d5c441dc0230,0x00d07e00925c0030\n"
".quad 0x00d07e00b2dc0058,0x00000038731c0058,0x00000025225c8458,0x0000002d22dc8410\n"
".quad 0x00000032d31c0010,0xf206c46483dc0258,0xf206c464019c0230,0x18000040e35e0030\n"
".quad 0x00000038e41c0030,0xf410d5c4931c0258,0xf410d5c4b39c0230,0x0000003c629c0030\n"
".quad 0x00000042e41c0058,0x00000030e6dc0058,0x0000002ad29c0058,0x06000011211c0458\n"
".quad 0x0000006ed71c0014,0x14000044f29e0058,0x0600002126dc0430,0x0000003cf3dc0014\n"
".quad 0x38000048c21e0058,0x06000015249c0430,0x00000030c45c0014,0x14000019a29e0058\n"
".quad 0x0000003ee3dc0030,0x06000001231c0458,0x00000018619c0014,0x00c0002d201c0358\n"
".quad 0x0000001c749c0060,0x1e00001b03dc0058,0x1a00001d31de0030,0x00000028a29c0030\n"
".quad 0x00c00014c19c0350,0x00000046e45c0060,0x00000038e69c0058,0x2000004b031c0058\n"
".quad 0x1000003af21e0030,0x0000001c71dc0030,0x00000028f29c0050,0x2200006b041c0050\n"
".quad 0x00000020821c0030,0x0000001cc1dc0050,0x00480010a29c0050,0x00c00015b15c0358\n"
".quad 0x00000021021c0060,0x1448000071dc0050,0x00c0002c411c0330,0x00000014001c4360\n"
".quad 0x0e48002081dc0068,0x00000018415c4330,0x06000025211c0468,0x0600002d219c0414\n"
".quad 0x00cfa00071dc0014,0x00000010001c4358,0x00000018511c4368,0x8e00005471dc0068\n"
".quad 0x00000000a01c0420,0x00000010a11c041c,0x000001c00000071c,0x000000000021f460\n"
".quad 0x8e00001001dc0340,0x0000001c055de419,0x00000000059de428,0x0000001005dde428\n"
".quad 0x000000c00081e728,0x00000067f0e1c340,0x0000000005e1e468,0x0000001005a1e428\n"
".quad 0x00c0000430e00328,0x5555555430e00258,0x0000000d90e08339,0x0000006400c1e468\n"
".quad 0x00000000001df428,0x00c00005861c0340,0x8ec0000d81dc2348,0x000000000021e71a\n"
".quad 0x03ffdc00001de7a8,0x00000700255c8540,0x00001c00251c85c9,0x00c00700211c03c9\n"
".quad 0x00c01c00215c0348,0x00000080001de248,0x000001a000000718,0xee0000ffffdc0460\n"
".quad 0x8e00005001dc2350,0x000001200001e719,0x00000050009c0340,0x00c0000821de0348\n"
".quad 0x00000000409c8560,0x00000700719c85c1,0x0e00001821dc00c1,0x0000006000a1e722\n"
".quad 0x0000000041808540,0x00001c00708085c9,0x00000000508085c1,0x00c00004001c33c9\n"
".quad 0x0e0000fc01dc2358,0x03fffe000001e71a,0xee0000ffffdc0440,0x00001c03f01c8550\n"
".quad 0xee0000ffffdc04c1,0x8e00005001dc2350,0x000000000001e71a,0x00000603f41cc580\n"
".quad 0x0e00005971dc03c1,0x00000643f31cc519,0x00000683f21cc5c1,0x0000000ff09c04c1\n"
".quad 0x00c00041701c0320,0x00c0000500de0360,0x00c00005141e0360,0x00c00005245e0360\n"
".quad 0x00c00005349e0360,0x00c00004c31e0360,0x00c00004d35e0360,0x00c00004e39e0360\n"
".quad 0x00000040241c0360,0x00000044245c0358,0x00000048249c0358,0x00000030231c0358\n"
".quad 0x00c00004f3de0358,0x0000000c20dc0360,0x00000034235c0358,0x00000038239c0358\n"
".quad 0x00c0000d041c0358,0x00c0000d145c0368,0x00c0000d249c0368,0x00c0000cc4dc0368\n"
".quad 0x0000003c23dc0368,0x00c0000c30dc0358,0x00c0000cd51c0368,0x00c0000ce55c0368\n"
".quad 0x00c00009031c0368,0x00c00011135c0360,0x00c00019239c0360,0x00c00004821e0360\n"
".quad 0x00c0000cf5dc0360,0x0000003030dc4368,0x00c0002133dc0368,0x00c00029441c0360\n"
".quad 0x00000038d31c4360,0x00c00004925e0368,0x00000020221c0360,0x00c00031545c0358\n"
".quad 0x00c00039739c0360,0x00000040f35c4360,0x0000003030dc4368,0x00000024225c0368\n"
".quad 0x00c0000c831c0358,0x000006c3f11cc568,0x00c00004a29e03c1,0x00000039121c4360\n"
".quad 0x0000003430dc4368,0x00c0000c935c0368,0x00c00004b2de0368,0x00000028229c0360\n"
".quad 0x00c00040c25c0358,0x0000002030dc4360,0x00c00004411e0368,0x0000002c22dc0360\n"
".quad 0x00c0000ca29c0358,0x00c00048d21c0368,0x0000002430dc4360,0x00c00004515e0368\n"
".quad 0x00000010211c0360,0x00c0000cb2dc0358,0x00c00050a25c0368,0x0000002030dc4360\n"
".quad 0x00000014215c0368,0x00c0000c421c0358,0x00c00004619e0368,0x00c00058b11c0360\n"
".quad 0x0000002430dc4360,0x00c0000c525c0368,0x00000018219c0368,0x00c00060815c0358\n"
".quad 0x0000001030dc4360,0x00c0000471de0368,0x00c0000c619c0360,0x00c00068911c0368\n"
".quad 0x0000001430dc4360,0x0000001c21dc0368,0x00c00070615c0358,0x00000010309c4360\n"
".quad 0x00000094011c0468,0x00c0007870dc032c,0x00000014209c4360,0x00000001619c4368\n"
".quad 0x004000a0401c6368,0x0000000c21dc4340,0x00000000019ca568,0x00000000001de790\n"
".quad 0x00c00004401c0380,0x00c00060001c0360,0x00c0000c015c0358,0x00000014215c0448\n"
".quad 0x8ec0000c51dc031c,0x000000800001e719,0x00000010401c0040,0x00800004411c00c8\n"
".quad 0x00000010011e0030,0x00000760001de730,0x8e0000fc01dc0340,0x000003000001e71a\n"
".quad 0x01fffffc401c0240,0x00000000015c0338,0x00c0007c515e0378,0x00ffffdc519c0348\n"
".quad 0x8ec0000461dc0348,0x000000400001e719,0x00000010411c0040,0x00000620001de7c8\n"
".quad 0x00ffffe0519c0340,0x00000000411c0248,0x00000018001c033a,0x01fffffc001c0260\n"
".quad 0xfe000000001c4238,0x00000010019c0038,0x0c800004001c00c8,0x0c000000601e0030\n"
".quad 0x01fffffc001c0230,0x0e0000fc019c0338,0x00000018515d0311,0x00c003d0515c0348\n"
".quad 0x00c0005c515c0348,0x00000014411c4360,0x00000010011c4368,0x00000420001de768\n"
".quad 0x00fffc0c015c0340,0x0ec0000451dc0348,0x000003a00001e71a,0x01fffffc419c0240\n"
".quad 0x0000000c02dde238,0x00000000411c0218,0xfe00000061dc423a,0x00000014b2dc0338\n"
".quad 0x00000010721c0060,0x1080000471dc00c8,0x9000001c825e0030,0x1000001c821e0030\n"
".quad 0x01fffffc929c0231,0x8e00002091dc0038,0x02000000a29c422e,0x10c00007f21c0438\n"
".quad 0x00000028b1dc0320,0x0000001471dc0368,0x00000028515c0358,0x00c00008725c0368\n"
".quad 0x00000014815c4368,0x00fffc10021c0368,0x8e0000fc91dc0348,0x00c00004701c031a\n"
".quad 0xa00000fc51dc0368,0x00000020a15c031a,0x800000fc01dc2358,0x00c000045140031a\n"
".quad 0x00c00004501c0348,0x0c000014001c0360,0x00000010011c4331,0x00000020001de768\n"
".quad 0x00000010411c0040,0x00000000001de7c8,0x0000000000000090,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x8000000000000000\n"
".quad 0x000000000c0c04bf,0x0000080000000400,0x00000b00080a0400,0x0c1903000c002000\n"
".quad 0xffffff000c170400,0x11f00000080002ff,0xffffff000c170400,0x11f00000040001ff\n"
".quad 0xffffff000c170400,0x11f00000000000ff,0x22019800080d0400,0x8000000000002000\n"
".quad 0x8000003f8000003f,0x000000411000003f,0x40000040c0000000,0x0000004080000040\n"
".quad 0x0000004000000000,0x0009000009000040,0x0104020004010200,0x0004000004000000\n"
".quad 0x0104010004010100,0x00000e0008120400,0x0811040000000000,0x0000000000000e00\n"
".quad 0x00000d0008120400,0x0811040000000000,0x0000000000000d00,0x0000000600000000\n"
".quad 0x000000000000415c,0x0000008000000000,0x0000000500000080,0x6000000000000004\n"
".quad 0x0000000000000491,0x00003c4c00000000,0x00000d0500003c4c,0x6000000000000004\n"
".quad 0x00000000000040dd,0x0000000000000000,0x00000d0600000800,0x0000000100000004\n"
".quad 0x00000000000040dd,0x0000004c00000000,0x000000050000004c,0x0000000000000004\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_20$[2108];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_20", (char*)__deviceText_$sm_20$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_20$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"211b0c560853284f",(char*)"/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x363193e1,&__elfEntries1};
# 3 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c" 2
struct __T20 {const uint *__par0;const uint *__par1;uint2 *__par2;int __dummy_field;};
extern void __device_stub__Z8compressPKjS0_P5uint2(const uint *, const uint *, uint2 *);
static void __sti____cudaRegisterAll_39_tmpxft_00005e9a_00000000_4_dxtc_cpp1_ii_b480a5a9(void) __attribute__((__constructor__));
void __device_stub__Z8compressPKjS0_P5uint2(const uint *__par0, const uint *__par1, uint2 *__par2){ struct __T20 *__T2324 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2324->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2324->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2324->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(const uint *, const uint *, uint2 *))compress)); (void)cudaLaunch(((char *)((void ( *)(const uint *, const uint *, uint2 *))compress))); };}
void compress( const uint *__cuda_0,const uint *__cuda_1,uint2 *__cuda_2)
# 510 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
{__device_stub__Z8compressPKjS0_P5uint2( __cuda_0,__cuda_1,__cuda_2);
# 538 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/dxtc/dxtc.cu"
}
# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c"
static void __sti____cudaRegisterAll_39_tmpxft_00005e9a_00000000_4_dxtc_cpp1_ii_b480a5a9(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(const uint *, const uint *, uint2 *))compress), (char*)"_Z8compressPKjS0_P5uint2", "_Z8compressPKjS0_P5uint2", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&kColorMetric, (char*)"kColorMetric", "kColorMetric", 0, 12, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable4, (char*)"alphaTable4", "alphaTable4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable3, (char*)"alphaTable3", "alphaTable3", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods4, (char*)"prods4", "prods4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods3, (char*)"prods3", "prods3", 0, 16, 1, 0); }
# 1 "/tmp/tmpxft_00005e9a_00000000-1_dxtc.cudafe1.stub.c" 2

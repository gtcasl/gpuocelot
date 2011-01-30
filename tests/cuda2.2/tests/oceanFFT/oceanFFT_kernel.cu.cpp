# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
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
# 41 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
int cuda_iDivUp(int a, int b)
# 42 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{
# 43 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
return (a + (b - 1)) / b;
# 44 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
}
# 49 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
__attribute__((unused)) float2 conjugate(float2 arg)
# 50 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{int volatile ___ = 1;
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
exit(___);}
# 55 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
__attribute__((unused)) float2 complex_exp(float arg)
# 56 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{int volatile ___ = 1;
# 58 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
exit(___);}
# 61 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
__attribute__((unused)) float2 complex_add(float2 a, float2 b)
# 62 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{int volatile ___ = 1;
# 64 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
exit(___);}
# 67 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
__attribute__((unused)) float2 complex_mult(float2 ab, float2 cd)
# 68 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{int volatile ___ = 1;
# 70 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
exit(___);}
# 73 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
void generateSpectrumKernel(float2 *h0, float2 *ht, unsigned width, unsigned height, float t, float patchSize) ;
# 103 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
void calculateSlopeKernel(float *h, float2 *slopeOut, unsigned width, unsigned height) ;
# 120 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
extern "C" void cudaGenerateSpectrumKernel(float2 *d_h0, float2 *d_ht, unsigned
# 121 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
width, unsigned height, float
# 122 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
animTime, float patchSize)
# 123 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{
# 124 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
dim3 block(8, 8, 1);
# 125 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
dim3 grid(cuda_iDivUp(width, block.x), cuda_iDivUp(height, block.y), 1);
# 126 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
cudaConfigureCall(grid, block) ? ((void)0) : generateSpectrumKernel(d_h0, d_ht, width, height, animTime, patchSize);
# 127 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
}
# 130 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
extern "C" void cudaCalculateSlopeKernel(float *hptr, float2 *slopeOut, unsigned
# 131 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
width, unsigned height)
# 132 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{
# 133 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
dim3 block(8, 8, 1);
# 134 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
dim3 grid2(cuda_iDivUp(width, block.x), cuda_iDivUp(height, block.y), 1);
# 135 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
cudaConfigureCall(grid2, block) ? ((void)0) : calculateSlopeKernel(hptr, slopeOut, width, height);
# 136 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
}
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000dcd_00000000-3_oceanFFT_kernel.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000dcd_00000000-3_oceanFFT_kernel.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000002190,0x0000000000000040,0x0038004000140115,0x0001000f00400005\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000400\n"
".quad 0x0000000000000215,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000615\n"
".quad 0x0000000000000090,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x00000000000006a5\n"
".quad 0x0000000000000210,0x0000001100000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000098,0x0000000000000006,0x0000000000000000,0x00000000000008b5\n"
".quad 0x0000000000001548,0x1500000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001cf,0x0000000000000002,0x0000000000000000,0x0000000000001dfd\n"
".quad 0x0000000000000040,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000196,0x0000000000000002,0x0000000000000000,0x0000000000001e3d\n"
".quad 0x0000000000000034,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000c8,0x0000000000000002,0x0000000000000000,0x0000000000001e71\n"
".quad 0x0000000000000098,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000162,0x0000000000000003,0x0000000000000000,0x0000000000001f09\n"
".quad 0x0000000000000004,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x0000000000001f09\n"
".quad 0x0000000000000160,0x0c00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000012f,0x0000000000000002,0x0000000000000000,0x0000000000002069\n"
".quad 0x0000000000000038,0x0000000900000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000fb,0x0000000000000002,0x0000000000000000,0x00000000000020a1\n"
".quad 0x0000000000000004,0x0000000900000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000061,0x0000000000000002,0x0000000000000000,0x00000000000020a5\n"
".quad 0x0000000000000070,0x0000000900000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000207,0x0000000000000002,0x0000000000000000,0x0000000000002115\n"
".quad 0x0000000000000018,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000008f,0x0000000000000002,0x0000000000000000,0x000000000000212d\n"
".quad 0x0000000000000060,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x30325a5f2e747865\n"
".quad 0x74616c75636c6163,0x654b65706f6c5365,0x365066506c656e72,0x6a6a3274616f6c66\n"
".quad 0x666e692e766e2e00,0x616330325a5f2e6f,0x536574616c75636c,0x6e72654b65706f6c\n"
".quad 0x6c66365066506c65,0x2e006a6a3274616f,0x006f666e692e766e,0x5a5f2e747865742e\n"
".quad 0x6172656e65673232,0x7274636570536574,0x6c656e72654b6d75,0x3274616f6c663650\n"
".quad 0x0066666a6a5f3053,0x6f666e692e766e2e,0x6e656732325a5f2e,0x6570536574617265\n"
".quad 0x72654b6d75727463,0x6f6c6636506c656e,0x6a6a5f3053327461,0x632e766e2e006666\n"
".quad 0x31746e6174736e6f,0x616330325a5f2e36,0x536574616c75636c,0x6e72654b65706f6c\n"
".quad 0x6c66365066506c65,0x2e006a6a3274616f,0x74736e6f632e766e,0x325a5f2e30746e61\n"
".quad 0x616c75636c616330,0x4b65706f6c536574,0x5066506c656e7265,0x6a3274616f6c6636\n"
".quad 0x6f6c2e766e2e006a,0x32325a5f2e6c6163,0x65746172656e6567,0x6d75727463657053\n"
".quad 0x36506c656e72654b,0x30533274616f6c66,0x6e2e0066666a6a5f,0x6174736e6f632e76\n"
".quad 0x325a5f2e3631746e,0x746172656e656732,0x7572746365705365,0x506c656e72654b6d\n"
".quad 0x533274616f6c6636,0x2e0066666a6a5f30,0x74736e6f632e766e,0x325a5f2e30746e61\n"
".quad 0x746172656e656732,0x7572746365705365,0x506c656e72654b6d,0x533274616f6c6636\n"
".quad 0x2e0066666a6a5f30,0x74736e6f632e766e,0x5a5f000032746e61,0x6c75636c61633032\n"
".quad 0x65706f6c53657461,0x66506c656e72654b,0x3274616f6c663650,0x6732325a5f006a6a\n"
".quad 0x5365746172656e65,0x4b6d757274636570,0x6636506c656e7265,0x5f30533274616f6c\n"
".quad 0x635f5f0066666a6a,0x30326d735f616475,0x5f6e725f7669645f,0x75635f5f00323366\n"
".quad 0x5f30326d735f6164,0x5f6e725f74727173,0x75635f5f00323366,0x6f32695f74726164\n"
".quad 0x00000000665f6970,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000001000300,0x0000000000000000,0x0000000000000000,0x0000000002000300\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000003000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000300,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000300,0x0000000000000000,0x0000000000000000,0x0000000009000300\n"
".quad 0x0001600000000000,0x0000000000000000,0x000000000c000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x000000000e000300,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000004000300,0x0015480000000000,0x0000000000000000,0x0000000007000300\n"
".quad 0x0000000000000000,0x0000000000000000,0x000000000b000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x000000000a000300,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000008000300,0x0000000000000000,0x0000000000000000,0x0000000006000300\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000005000300,0x0000000000000000\n"
".quad 0x0000000000000000,0x000000000d000300,0x0000000000000000,0x0000010000000000\n"
".quad 0x0000000009101200,0x0001600000000000,0x0000260000000000,0x0000000004101200\n"
".quad 0x0010e00000000000,0x0000500000000000,0x0010e00004001200,0x0003700000000000\n"
".quad 0x0000670000000000,0x0014500004001200,0x0000f80000000000,0x00007f0000000000\n"
".quad 0x000000000d001100,0x0000180000000000,0x005de40000000000,0x009c042800440400\n"
".quad 0x105d032c00000098,0x011c044800c00100,0x221c032c00000088,0x001c042008400030\n"
".quad 0x81dc032c00000094,0x00dc04188e4000d0,0x001c032c00000084,0x01dc032006400020\n"
".quad 0x0021e718804000c0,0x809c038000000000,0x80de0320004000c0,0x251e0348004000d0\n"
".quad 0x30dc036000c0000c,0x309c034800fffffc,0x411c0320004000c0,0x00dde44801400081\n"
".quad 0xf15c432800400080,0x201c044800400093,0x219c031800000001,0x221c042007c00020\n"
".quad 0xf1dc431800000021,0x441ca54800400093,0x849c028400000000,0x609ca53103243f6c\n"
".quad 0x015de48400000000,0x011c0228004000f0,0x0100073101243f6c,0x04dde45000003fe0\n"
".quad 0x015de42800000010,0x011de428004000f0,0x0100072800000048,0x301c005000003f60\n"
".quad 0x411c00580000004d,0x0100073000000010,0x411c025000004cc0,0x010007310473d70c\n"
".quad 0x411c005000004c80,0x00000758004000e0,0x41dc806000000f60,0x201d04210edfe000\n"
".quad 0x0021e71000000011,0x115c034000000040,0x41dd104800c00020,0x43dc805000000010\n"
".quad 0x000007220e400004,0x0025e76000000c20,0x415c034000000b20,0x135c036000c00020\n"
".quad 0x419c024800c00020,0x031de43a00000000,0x021de428000000fc,0x01dde428000000fc\n"
".quad 0x515c4228000000fc,0xc25c863a00000000,0x821c031400080000,0x929c034800c00004\n"
".quad 0xa2dc035000000014,0x83dc23480000001c,0xa1dc031a8ec00018,0xd2dc85120e00002c\n"
".quad 0xc31c03c800000000,0x91dd434800c00010,0xd35c03200e000014,0x0005e74800c00010\n"
".quad 0x415c034003fffea0,0x11dc856000c00004,0x515c03c800000080,0x525c035800c00060\n"
".quad 0x921c034800fffe00,0x115c035800c00014,0x929c034800c00020,0x821e036800c0007c\n"
".quad 0x835c434800c00010,0xa3dc034000000014,0xd21c85190e0000fc,0xd25c85c000000020\n"
".quad 0x0085e7c000000010,0xd1e4854000000100,0xa2e603c000000000,0x8324034800c00080\n"
".quad 0x92a4036000000028,0x9224036000000028,0x822403580000002c,0x71e4034800000030\n"
".quad 0x726403580000002c,0x91dc034800000028,0x925c036000c00008,0x73dc035800c00078\n"
".quad 0x82dc03190e0000fc,0x0000075800c00078,0x829c4360000000e0,0x0005e74000000024\n"
".quad 0xa21c034000000060,0x83dc034800c00004,0xf21c141a0e400014,0xa3dc032012c00007\n"
".quad 0xf21c141a0e400014,0xb21c032012c00007,0x225f844800000020,0x921c031c00000021\n"
".quad 0x00a5e7328c000020,0x21c78440000000a0,0xf285c31c0000001d,0x724403680000002b\n"
".quad 0x618482110e0000fc,0x9286033a00000000,0xa3dc234800000028,0x000007198e0000fc\n"
".quad 0x0005e76000000140,0x025de44000000100,0x72dc0328000000fc,0x925c035800c0007c\n"
".quad 0xa29c234800fffffc,0x71dc03400000002c,0xa3dc236000c00004,0x0005e71a0e0000fc\n"
".quad 0x001df44003ffff40,0x025df44000000000,0xa2dc4328000000fc,0xb3dc235000400024\n"
".quad 0xa29c02198e0000fc,0x0085e713243f6a88,0xa1e4034000000080,0x9264035800c0007c\n"
".quad 0xa2a4034800fffffc,0xb2e4236000c00004,0xa1dc03400000001c,0x925c03128e0000fc\n"
".quad 0x71de034800c001f8,0x729c03480000002c,0x71dc035800c00020,0x925ee36000c00060\n"
".quad 0x71dc234000000028,0x71de03108e0000fc,0x61dc534800000024,0x415c02680000001c\n"
".quad 0x221c8430fc8be60c,0x219e041400000015,0x615e001800000021,0x61de003008cff240\n"
".quad 0x115c03300a400034,0x61de104800c00020,0x819c03300e400044,0x621c034800c00004\n"
".quad 0x83dc236800c00004,0x721c001a8e0000fc,0x00a5e7580000001c,0x01c5e240000000c0\n"
".quad 0x81c4001aead81868,0x71c400300e400054,0x71c4003010800064,0x71c4003010800074\n"
".quad 0x0085e73010800084,0x0265e240000000a0,0x82640018f0220e78,0x9264003012400094\n"
".quad 0x82240030108000a4,0x81e4005800000024,0x619c03300e00001c,0x221d046800c00008\n"
".quad 0x81dc33100000001d,0x41dc00328c00001c,0x00000721200000fc,0x0021e76000000f20\n"
".quad 0x119c034000000040,0x421c104800c00090,0x41dc8058000000fc,0x000007220e400004\n"
".quad 0x0021e76000000c40,0x431c034000000b40,0x12dc036000c00020,0x421c024800c00090\n"
".quad 0x029de43a00000000,0x019de428000000fc,0x025de428000000fc,0xc3dc4228000000fc\n"
".quad 0x619c033a00000000,0xa31c864800c00004,0xc35c031400080000,0x61dc23500000003c\n"
".quad 0xd39c031a8ec00018,0xa29c034800000024,0xd25c034800c00010,0xb39c85120e000038\n"
".quad 0xc25d43c800000000,0xb2dc03201200003c,0x0001e74800c00010,0x419c034003fffea0\n"
".quad 0x125c856000c00004,0x619c03c8000000f0,0x629c035800c00060,0xa2dc034800fffe00\n"
".quad 0x119c035800c00014,0xa31c034800c00090,0xb2de036800c0007c,0xb39c434800c00010\n"
".quad 0xc1dc034000000018,0xe2dc85190e0000fc,0xe29c85c000000020,0x0081e7c000000010\n"
".quad 0xc362034000000100,0xe260854800c00080,0xb2e003c000000000,0x93a0036000000030\n"
".quad 0xa260035800000034,0xa2a0035800000034,0x92e0036000000030,0xe2a003480000002c\n"
".quad 0xa25c034800000028,0x0000076000c00008,0xa29c036000000140,0x91dc035800c00078\n"
".quad 0xb35c03190e0000fc,0xb31c435800c00078,0x0001e74000000028,0xc29c034000000060\n"
".quad 0xa1dc034800c00004,0xf29c141a0e400014,0xc1dc032010c00007,0xf29c141a0e400014\n"
".quad 0xd29c032010c00007,0x22df844800000028,0xb29c031c00000029,0x00a1e73290000028\n"
".quad 0x22438440000000a0,0xf301c31c00000025,0x92c0036800000033,0x820082110e0000fc\n"
".quad 0xb302033a00000000,0xc1dc234800000030,0x000007198e0000fc,0x0001e76000000160\n"
".quad 0x02dde44000000120,0x001de428000000fc,0x935c034000000000,0xb2dc035800c0007c\n"
".quad 0xc31c234800fffffc,0x925c034000000034,0xc1dc236000c00004,0x0001e71a0e0000fc\n"
".quad 0x001df44003ffff40,0x02ddf44000000000,0xc35c4328000000fc,0xd1dc235000400024\n"
".quad 0xc31c02198e0000fc,0x0081e713243f6a88,0xc260034000000080,0xb2e0035800c0007c\n"
".quad 0xc320034800fffffc,0xd360236000c00004,0xc25c034000000024,0xb2dc03128e0000fc\n"
".quad 0x925e034800c001f8,0x931c034800000034,0x925c035800c00020,0xb2dee36000c00060\n"
".quad 0x925c234000000030,0x925e03108e0000fc,0x825c53480000002c,0x419c026800000024\n"
".quad 0x229c8430fc8be60c,0x221e041400000019,0x819e001800000029,0x825e003008cff240\n"
".quad 0x119c03300c400034,0x825e104800c00090,0xa21c033012400044,0x81dc236800c00004\n"
".quad 0x921c001a8e0000fc,0x00a1e75800000024,0x0241e240000000c0,0x8240001aead81868\n"
".quad 0x9240003012400054,0x9240003010800064,0x9200003010800074,0x0081e73010800084\n"
".quad 0x02e1e240000000a0,0x82e00018f0220e78,0xb2e0003016400094,0x82200030108000a4\n"
".quad 0x822000580000002c,0xa25c033012000024,0x229d046800c00008,0xa21c331000000021\n"
".quad 0x025c003292000020,0x729c00580000001d,0x41dc805800000044,0x000007210edfe000\n"
".quad 0x81de006000000f00,0x021c003012000044,0x0021e73014000021,0x415e104000000020\n"
".quad 0x43dc805000000010,0x000007220e400004,0x0025e76000000be0,0x039c034000000b00\n"
".quad 0x12dc036000c00020,0x025c024800c00020,0x031de43a00000000,0x029de428000000fc\n"
".quad 0x035de428000000fc,0xe39c4228000000fc,0xa29c033a00000000,0xc3dc864800c00004\n"
".quad 0xf41c031400080000,0xa3dc235000000038,0x045c031a8ec00018,0xc31c034800000035\n"
".quad 0x035c034800c00010,0xb45c85120e000045,0xf35d43c800000000,0xb2dc03201a000038\n"
".quad 0x0005e74800c00010,0x029c034003fffea0,0x135c856000c00004,0xa29c03c800000080\n"
".quad 0xa2dc035800c00060,0xb29c034800fffe00,0xa29e035800c00014,0xa3dc434800c00010\n"
".quad 0xb15c034000000014,0xf29c856800c0007c,0x53dc03c000000020,0xf39c85190e0000fc\n"
".quad 0x0085e7c000000010,0xf2e4854000000100,0x532603c000000000,0xa2a4034800c00080\n"
".quad 0xe364036000000014,0xe164036000000014,0xb2e4035800000030,0x52a4035800000030\n"
".quad 0xb3a4034800000028,0xe15c034800000034,0xe2dc036000c00008,0x53dc035800c00078\n"
".quad 0xa35c03190e0000fc,0x0000075800c00078,0xa31c4360000000e0,0x0005e7400000002c\n"
".quad 0xc29c034000000060,0xa3dc034800c00004,0xf29c141a0e400014,0xc3dc032012c00007\n"
".quad 0xf29c141a0e400014,0xd29c032012c00007,0x22df844800000028,0xb29c031c00000029\n"
".quad 0x00a5e73292000028,0x21478440000000a0,0xf305c31c00000015,0x52c4036800000033\n"
".quad 0x924482110e0000fc,0xb306033a00000000,0xc3dc234800000030,0x000007198e0000fc\n"
".quad 0x0005e76000000140,0x02dde44000000100,0x535c0328000000fc,0xb2dc035800c0007c\n"
".quad 0xc31c234800fffffc,0x515c034000000034,0xc3dc236000c00004,0x0005e71a0e0000fc\n"
".quad 0x001df44003ffff40,0x02ddf44000000000,0xc35c4328000000fc,0xd3dc235000400024\n"
".quad 0xc31c02198e0000fc,0x0085e713243f6a88,0xc164034000000080,0xb2e4035800c0007c\n"
".quad 0xc324034800fffffc,0xd364236000c00004,0xc15c034000000014,0xb2dc03128e0000fc\n"
".quad 0x515e034800c001f8,0x531c034800000034,0x515c035800c00020,0xb2dee36000c00060\n"
".quad 0x515c234000000030,0x515e03108e0000fc,0x92dc53480000002c,0x415c026800000014\n"
".quad 0x229c8432fc8be60c,0x215e041400000015,0x525f001800000029,0x525e003008cff240\n"
".quad 0x52de103012400034,0xa15c033012400044,0x525c034800c00004,0xb29c006800c00004\n"
".quad 0x93dc23580000002c,0x00a5e71a8e0000fc,0x0245e240000000c0,0xa244001aead81868\n"
".quad 0x9244003012400054,0x9244003014800064,0x9244003014800074,0x0085e73014800084\n"
".quad 0x0265e240000000a0,0xa2640018f0220e78,0x9264003012400094,0xa2640030148000a4\n"
".quad 0x9264005800000024,0x515c03301600002c,0x229d046800c00008,0xa15c331000000025\n"
".quad 0x41de00328a000024,0x00000721200000fc,0x0021e76000000ec0,0x411c104000000020\n"
".quad 0x41dc805a000000fc,0x000007220e400004,0x0021e76000000be0,0x029c034000000b00\n"
".quad 0x13dc036000c00020,0x011c024800c00090,0x041de43a00000000,0x039de428000000fc\n"
".quad 0x025de428000000fc,0xa35c4228000000fc,0xe39c033a00000000,0x029c864800c00004\n"
".quad 0xa2dc031400080001,0xe1dc235000000034,0xb31c031a8ec00018,0x041c034800000024\n"
".quad 0xb25c034800c00011,0xf31c85120e000030,0xa25d43c800000000,0xf3dc032012000034\n"
".quad 0x0001e74800c00010,0x001c034003fffea0,0x125c856000c00004,0x001c03c8000000f0\n"
".quad 0x001c035800c00060,0x029c034800fffe00,0x001c035800c00014,0xa29e036800c0007c\n"
".quad 0xa19c434800c00010,0x01dc034000000018,0x629c85190e0000fc,0x631c85c000000020\n"
".quad 0x0081e7c000000010,0x61a0854000000100,0x026203c000000000,0xa2a0034800c00080\n"
".quad 0xc2e0036000000000,0xc020036000000000,0x61a0035800000024,0x02a0035800000024\n"
".quad 0x6320034800000028,0xc19c03480000002c,0xc01c036000c00008,0x61dc035800c00078\n"
".quad 0xa25c03190e0000fc,0x0000075800c00078,0xa31c4360000000e0,0x0001e74000000000\n"
".quad 0xc01c034000000060,0x01dc034800c00004,0xf01c141a0e400014,0xc1dc032010c00007\n"
".quad 0xf01c141a0e400014,0x901c032010c00007,0x225f844800000000,0x901c031c00000001\n"
".quad 0x00a1e73288000000,0x21838440000000a0,0xf281c31c00000019,0x6240036800000033\n"
".quad 0x410082110e0000fc,0x9302033a00000000,0xc1dc234800000028,0x000007198e0000fc\n"
".quad 0x0001e76000000140,0x029de44000000100,0x625c0328000000fc,0xa29c035800c0007c\n"
".quad 0xc31c234800fffffc,0x619c034000000024,0xc1dc236000c00004,0x0001e71a0e0000fc\n"
".quad 0x001df44003ffff40,0x029df44000000000,0xc2dc4328000000fc,0xc25c025000400024\n"
".quad 0xb1dc2313243f6a88,0x0081e7198e0000fc,0x91a0034000000080,0xa2a0035800c0007c\n"
".quad 0x9260034800fffffc,0xb2e0236000c00004,0x919c034000000018,0xa29c03128e0000fc\n"
".quad 0x619e034800c001f8,0x625c03480000002c,0x619c035800c00020,0xa25ee36000c00060\n"
".quad 0x619c234000000024,0x619e03108e0000fc,0x425c534800000024,0x401c026800000018\n"
".quad 0x201c8432fc8be60c,0x219e041400000001,0x611f001800000001,0x611e003008cff240\n"
".quad 0x625e103008400034,0x011c033008400044,0x41dc236800c00004,0x919c001a8e0000fc\n"
".quad 0x00a1e75800000024,0x0101e240000000c0,0x6100001aead81868,0x4100003008400054\n"
".quad 0x410000300c800064,0x410000300c800074,0x0081e7300c800084,0x0121e240000000c0\n"
".quad 0x61200018f0220e78,0x4120003008400094,0x612000300c8000a4,0x4120005800000010\n"
".quad 0x001de43012000024,0x001c034000000000,0x219d046800c00008,0x611c331000000011\n"
".quad 0x401c003280000010,0x429c03580000000c,0x211c0048014000a1,0x201c005800000010\n"
".quad 0x509e003000000014,0xf2dc43300800000c,0x711c0048004000b3,0x815c005000000000\n"
".quad 0xa11ca55000000008,0x001de79400000000,0x401c038000000000,0x519c036000c00004\n"
".quad 0x001c036000c00004,0x619c035800c00060,0x001c035800c00060,0x619c034800fffffc\n"
".quad 0x01dc034800fffffc,0x61dc031a0ec003f4,0x0021e71a20c003f4,0x41dc804000000520\n"
".quad 0x21dc44298edfe000,0x0021e71080000011,0x51dc804000000060,0x221c44298edfe000\n"
".quad 0x0001e71080000015,0x411c204000000040,0x001de75000000014,0x425c034000000b80\n"
".quad 0x529c036000c00004,0x93dc036000c00004,0xa5dc03190e0000fc,0x11dc04190e0000fc\n"
".quad 0x0001e70c0e000008,0x77dc004000000080,0x81dc00290edfe000,0x002de7290edfe000\n"
".quad 0x0021e74000000080,0x001de24000000060,0x011c001bff000000,0x001de7c800000014\n"
".quad 0x01dc0440000009e0,0x0021e70c0e000044,0x501c834000000060,0x011c026800000010\n"
".quad 0x001de73a00000000,0x31dc044000000940,0x0021e70c0e000048,0x501c834000000080\n"
".quad 0x001c026800000010,0x011c423a00000000,0x001de739fe000000,0x01dc234000000880\n"
".quad 0x63dc231b0e0000fc,0x01e1e21b0e0000fc,0x4120001bffffff00,0x01c1e4307ed7e000\n"
".quad 0x0005e728000000fc,0x515c004000000080,0x71dc03307ed7e000,0x001de74800c00100\n"
".quad 0x01dde44000000020,0x621c0328000000fc,0x825ee34800fffe08,0x021c034100000014\n"
".quad 0x915c004800fffe08,0x811ee3c800000010,0x001d034100000010,0x421c004800000018\n"
".quad 0x929e00307e000014,0xa21c003008000020,0x925e003010000014,0x911c003008000020\n"
".quad 0x429c033010000014,0xa29c036000c00004,0x001c035800c00060,0x719c034800000028\n"
".quad 0x601c034800000000,0x01dc034800fffffc,0x0001e71a0ec003f4,0x601d034000000060\n"
".quad 0x011ee34800000028,0x001de74000000010,0x61dc2340000004a0,0x0001e7198ec003f8\n"
".quad 0x401c024000000060,0x011c423a00000000,0x001de739fe000000,0x61dc234000000400\n"
".quad 0x0001e71a0e0000fc,0x61dc2340000003c0,0x0001e71b0effffa0,0x411c024000000040\n"
".quad 0x001de73a00000000,0x929c004000000340,0x91dc003110000014,0x901c003090000014\n"
".quad 0x221f843190000014,0xa15c001c00000019,0x01dc021e8e00001c,0x81dc233801fffffc\n"
".quad 0x401c02190e0000fc,0x221f843a00000000,0x211f841c00000019,0x71dc421c00000015\n"
".quad 0x0081e73802000000,0x61600340000000a0,0x7160034800c00080,0xf160036000000014\n"
".quad 0x71e003310ac00007,0x4120435800000020,0x715c036800000014,0x519c036000c00078\n"
".quad 0x715c035800c0007c,0x411c436800c00004,0x511c036800000018,0x715c036800000010\n"
".quad 0x41dc035800c00004,0x5140031a8e0000fc,0x011c434800c00004,0x001de76800000014\n"
".quad 0x401c029000000000,0x01dc030bcc000000,0x0001e7198e4000b4,0x401c024000000220\n"
".quad 0x01dc2339fffffffc,0x0021e71a8e0000fc,0x41dc004000000300,0x0021e7288e0000fc\n"
".quad 0x011de24000000040,0x001de719fffffffc,0x41dc804000000280,0x201c44298edfe000\n"
".quad 0x0001e71080000011,0x411c204000000040,0x001de75000cfe000,0x01dc0040000001e0\n"
".quad 0x0001e7290edfe000,0x411c0040000001a0,0x71dc04307ed7e000,0x001de70c0e00001c\n"
".quad 0xf1dc044000000020,0x401c000c0e00001c,0x015c40c800000014,0x001c405800000010\n"
".quad 0x519e005800cfc000,0x515c0030008000c4,0x019c00300a000018,0x501e003000000018\n"
".quad 0x011c003008000014,0x410040300a000018,0x001de75800cbe000,0x0000009000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x3ba7000000000000\n"
".quad 0x0fdaa28000000047,0x85a30939fdaa20c9,0x2aaaa537ccf5ce2e,0x800000bf0000003d\n"
".quad 0x2aaaa3b94ca1f93f,0x000000727fffffbe,0x00000000180c043f,0x0000100000000800\n"
".quad 0x0000180000001400,0x080a040000001c00,0x2000200000000f00,0x0c17040020190300\n"
".quad 0x1c0005ffffffff00,0x0c17040011f00000,0x180004ffffffff00,0x0c17040011f00000\n"
".quad 0x140003ffffffff00,0x0c17040011f00000,0x100002ffffffff00,0x0c17040011f00000\n"
".quad 0x080001ffffffff00,0x0c17040021f00000,0x000000ffffffff00,0x080d040021f00000\n"
".quad 0x000020002301a400,0x00440400005de400,0x00000094001c0428,0x0000008400dc042c\n"
".quad 0x0640002000dc032c,0x00000098009c0420,0x0e0000fc31dc032c,0x00000088001c0419\n"
".quad 0x000003e00000072c,0x00400030201c0360,0x000003400001e720,0x0e0000fc01dc0340\n"
".quad 0x000003000001e719,0x004000c0009de440,0x00fffffc209c0328,0x0e00000831dc0348\n"
".quad 0x000002800001e71b,0x004000d0009de440,0x00fffffc209c0328,0x0e00000801dc0348\n"
".quad 0x000002000001e71b,0x064000c0001c0340,0x00400080015de420,0x004000c0009c0328\n"
".quad 0x0bc00010021c0348,0x00400093f25c4320,0x0bc00010209c0348,0x004000c0011d0320\n"
".quad 0x00400093f0dc4348,0x00000010819c8548,0x0bc00010429c0384,0x0000000020dc8520\n"
".quad 0x00400093f2dc4384,0xfffffff0815c8548,0x00000000a11c8587,0x00000014609d0084\n"
".quad 0x0000001030dd1050,0x064000c0001c0350,0x000000fc00dde420,0x000000fc009df428\n"
".quad 0x004000a0011de428,0x09c00020011c0328,0x004000b3f15c4320,0x00000000409ca548\n"
".quad 0x00000000001de794,0x0000000000000080,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x100c040000000100,0x0000080000000000,0x0000140000001000,0x00000c00080a0400\n"
".quad 0x1819030018002000,0xffffff000c170400,0x11f00000140003ff,0xffffff000c170400\n"
".quad 0x11f00000100002ff,0xffffff000c170400,0x21f00000080001ff,0xffffff000c170400\n"
".quad 0x21f00000000000ff,0x05003c00080d0400,0x4390410000000400,0x34ddc0db6295993c\n"
".quad 0x441529fc2757d1f5,0x081204a2f9836e4e,0x0000000000001400,0x0000140008110400\n"
".quad 0x0812040000000000,0x0000000000001300,0x0000130008110400,0x0812040000000000\n"
".quad 0x0000400000001200,0x0000120008110400,0x0812040000004000,0x0000000000001100\n"
".quad 0x0000110008110400,0x0000000000000000,0x0000000500000006,0x0000000000002190\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000118,0x0000000000000118\n"
".quad 0x0000000000000004,0x0000120560000000,0x00000000000008b5,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000001654,0x0000000000001654,0x0000000000000004\n"
".quad 0x0000120660000000,0x0000000000001f09,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000004,0x0000000000000004,0x0000110560000000\n"
".quad 0x0000000000001f09,0x0000000000000000,0x0000000000000000,0x000000000000020c\n"
".quad 0x000000000000020c,0x0000000000000004,0x0000000500000001,0x0000000000002115\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000018,0x0000000000000018\n"
".quad 0x0000000000000004,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[1110];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3930,0x662e20656c626973\n"
".quad 0x61702e2820636e75,0x696c612e206d6172,0x38622e2038206e67,0x72616475635f5f20\n"
".quad 0x63395a5f5f667465,0x65746167756a6e6f,0x5b3274616f6c6636,0x63395a5f20295d38\n"
".quad 0x65746167756a6e6f,0x203274616f6c6636,0x206d617261702e28,0x38206e67696c612e\n"
".quad 0x635f5f2038622e20,0x666d726170616475,0x6e6f63395a5f5f31,0x663665746167756a\n"
".quad 0x5d385b3274616f6c,0x7369762e090a0a29,0x75662e20656c6269,0x7261702e2820636e\n"
".quad 0x67696c612e206d61,0x2038622e2038206e,0x6572616475635f5f,0x6331315a5f5f6674\n"
".quad 0x655f78656c706d6f,0x20295d385b667078,0x706d6f6331315a5f,0x667078655f78656c\n"
".quad 0x6d617261702e2820,0x5f5f203233662e20,0x6d72617061647563,0x6331315a5f5f3166\n"
".quad 0x655f78656c706d6f,0x2e090a0a29667078,0x20656c6269736976,0x2e2820636e75662e\n"
".quad 0x612e206d61726170,0x2e2038206e67696c,0x6475635f5f203862,0x5a5f5f6674657261\n"
".quad 0x656c706d6f633131,0x6c66366464615f78,0x385b5f533274616f,0x6331315a5f20295d\n"
".quad 0x615f78656c706d6f,0x74616f6c66366464,0x61702e28205f5332,0x696c612e206d6172\n"
".quad 0x38622e2038206e67,0x70616475635f5f20,0x5a5f5f31666d7261,0x656c706d6f633131\n"
".quad 0x6c66366464615f78,0x385b5f533274616f,0x617261702e202c5d,0x6e67696c612e206d\n"
".quad 0x5f2038622e203820,0x726170616475635f,0x31315a5f5f32666d,0x5f78656c706d6f63\n"
".quad 0x616f6c6636646461,0x295d385b5f533274,0x697369762e090a0a,0x6e75662e20656c62\n"
".quad 0x617261702e282063,0x6e67696c612e206d,0x5f2038622e203820,0x746572616475635f\n"
".quad 0x6f6332315a5f5f66,0x756d5f78656c706d,0x74616f6c6636746c,0x20295d385b5f5332\n"
".quad 0x706d6f6332315a5f,0x746c756d5f78656c,0x533274616f6c6636,0x617261702e28205f\n"
".quad 0x6e67696c612e206d,0x5f2038622e203820,0x726170616475635f,0x32315a5f5f31666d\n"
".quad 0x5f78656c706d6f63,0x6f6c6636746c756d,0x5d385b5f53327461,0x6d617261702e202c\n"
".quad 0x206e67696c612e20,0x5f5f2038622e2038,0x6d72617061647563,0x6332315a5f5f3266\n"
".quad 0x6d5f78656c706d6f,0x616f6c6636746c75,0x295d385b5f533274,0x2d2d2d2f2f090a0a\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x6d6f43202f2f090a\n"
".quad 0x2f20676e696c6970,0x78706d742f706d74,0x30303030305f7466,0x303030305f646364\n"
".quad 0x6f5f372d30303030,0x5f5446466e616563,0x632e6c656e72656b,0x2f2820692e337070\n"
".quad 0x494263632f706d74,0x765032305a6b2e23,0x2d2d2d2f2f090a29,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2f2f090a0a,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x74704f202f2f090a,0x2f090a3a736e6f69\n"
".quad 0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f2f090a2d2d2d2d\n"
".quad 0x7465677261542020,0x5349202c7874703a,0x2c30325f6d733a41,0x3a6e6169646e4520\n"
".quad 0x202c656c7474696c,0x207265746e696f50,0x0a34363a657a6953,0x334f2d20202f2f09\n"
".quad 0x696d6974704f2809,0x6c206e6f6974617a,0x2f090a296c657665,0x280930672d20202f\n"
".quad 0x656c206775626544,0x2f2f090a296c6576,0x522809326d2d2020,0x64612074726f7065\n"
".quad 0x736569726f736976,0x2d2d2d2f2f090a29,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x656c69662e090a0a,0x6d6f633c22093109,0x6e696c2d646e616d\n"
".quad 0x69662e090a223e65,0x742f22093209656c,0x6678706d742f706d,0x6430303030305f74\n"
".quad 0x30303030305f6463,0x636f5f362d303030,0x6b5f5446466e6165,0x75632e6c656e7265\n"
".quad 0x70672e3265666164,0x6c69662e090a2275,0x73752f2209330965,0x63672f62696c2f72\n"
".quad 0x6c2d363836692f63,0x756e672d78756e69,0x692f352e342e342f,0x732f6564756c636e\n"
".quad 0x22682e6665646474,0x09656c69662e090a,0x2f7273752f220934,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x65642f7472632f65,0x6e75725f65636976\n"
".quad 0x0a22682e656d6974,0x3509656c69662e09,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x65645f74736f682f,0x22682e73656e6966\n"
".quad 0x09656c69662e090a,0x2f7273752f220936,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x69746c6975622f65,0x2e73657079745f6e,0x6c69662e090a2268\n"
".quad 0x73752f2209370965,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x697665642f656475,0x73657079745f6563,0x69662e090a22682e,0x752f22093809656c\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x6972642f6564756c\n"
".quad 0x657079745f726576,0x662e090a22682e73,0x2f22093909656c69,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x75732f6564756c63,0x79745f6563616672\n"
".quad 0x090a22682e736570,0x303109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x657275747865742f,0x682e73657079745f\n"
".quad 0x656c69662e090a22,0x73752f2209313109,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x746365762f656475,0x73657079745f726f,0x69662e090a22682e\n"
".quad 0x2f2209323109656c,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x65642f6564756c63,0x75616c5f65636976,0x617261705f68636e,0x682e73726574656d\n"
".quad 0x656c69662e090a22,0x73752f2209333109,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x2f7472632f656475,0x5f656761726f7473,0x22682e7373616c63\n"
".quad 0x09656c69662e090a,0x7273752f22093431,0x6564756c636e692f,0x79742f737469622f\n"
".quad 0x090a22682e736570,0x353109656c69662e,0x692f7273752f2209,0x742f6564756c636e\n"
".quad 0x090a22682e656d69,0x363109656c69662e,0x2f656d6f682f2209,0x632f6c616d726f6e\n"
".quad 0x2f74756f6b636568,0x6f6c65636f757067,0x2d73747365742f74,0x2f312e322d787470\n"
".quad 0x2f322e3261647563,0x636f2f7374736574,0x6f2f5446466e6165,0x5f5446466e616563\n"
".quad 0x632e6c656e72656b,0x6c69662e090a2275,0x752f220937310965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x6d6f632f6564756c,0x636e75665f6e6f6d\n"
".quad 0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093831,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x5f6874616d2f6564,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209393109656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x736e6f635f687461,0x22682e73746e6174\n"
".quad 0x09656c69662e090a,0x7273752f22093032,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x63697665642f6564,0x6974636e75665f65,0x090a22682e736e6f\n"
".quad 0x313209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x615f31315f6d732f,0x75665f63696d6f74,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220932320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x696d6f74615f3231,0x6974636e75665f63\n"
".quad 0x090a22682e736e6f,0x333209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x645f33315f6d732f,0x75665f656c62756f\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220934320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x696d6f74615f3032\n"
".quad 0x6974636e75665f63,0x090a22682e736e6f,0x353209656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x695f30325f6d732f\n"
".quad 0x6369736e6972746e,0x662e090a22682e73,0x2209363209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x732f6564756c636e,0x665f656361667275\n"
".quad 0x736e6f6974636e75,0x69662e090a22682e,0x2f2209373209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x65742f6564756c63,0x65665f6572757478\n"
".quad 0x636e75665f686374,0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093832\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x5f6874616d2f6564\n"
".quad 0x6e6f6974636e7566,0x74705f6c62645f73,0x0a0a0a22682e3378,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x206d617261702e28,0x38206e67696c612e,0x635f5f2038622e20\n"
".quad 0x5f66746572616475,0x756a6e6f63395a5f,0x6f6c663665746167,0x20295d385b327461\n"
".quad 0x756a6e6f63395a5f,0x6f6c663665746167,0x61702e2820327461,0x696c612e206d6172\n"
".quad 0x38622e2038206e67,0x70616475635f5f20,0x5a5f5f31666d7261,0x6167756a6e6f6339\n"
".quad 0x74616f6c66366574,0x7b090a295d385b32,0x2e206765722e090a,0x383c662520323366\n"
".quad 0x636f6c2e090a3b3e,0x3009303509363109,0x67656257444c240a,0x6f63395a5f5f6e69\n"
".quad 0x3665746167756a6e,0x0a3a3274616f6c66,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x635f5f5b202c3166,0x666d726170616475,0x6e6f63395a5f5f31,0x663665746167756a\n"
".quad 0x5d302b3274616f6c,0x662e766f6d090a3b,0x2c32662509203233,0x6c090a3b31662520\n"
".quad 0x2e6d617261702e64,0x3366250920323366,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x756a6e6f63395a5f,0x6f6c663665746167,0x0a3b5d342b327461,0x3233662e766f6d09\n"
".quad 0x25202c3466250920,0x6f6c2e090a3b3366,0x0931350936310963,0x662e766f6d090a30\n"
".quad 0x2c35662509203233,0x73090a3b32662520,0x2e6d617261702e74,0x5f5f5b0920323366\n"
".quad 0x6674657261647563,0x6a6e6f63395a5f5f,0x6c66366574616775,0x2c5d302b3274616f\n"
".quad 0x6e090a3b35662520,0x09203233662e6765,0x346625202c366625,0x61702e7473090a3b\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x395a5f5f66746572,0x746167756a6e6f63\n"
".quad 0x3274616f6c663665,0x366625202c5d342b,0x0a3b746572090a3b,0x5f646e6557444c24\n"
".quad 0x756a6e6f63395a5f,0x6f6c663665746167,0x207d090a3a327461,0x6f63395a5f202f2f\n"
".quad 0x3665746167756a6e,0x090a3274616f6c66,0x2e2074736e6f632e,0x2034206e67696c61\n"
".quad 0x75635f5f2038622e,0x6f32695f74726164,0x5d34325b665f6970,0x312c35367b203d20\n"
".quad 0x30362c37362c3434,0x3934312c3335312c,0x2c3931322c38392c,0x2c3132322c323931\n"
".quad 0x322c3534322c3235,0x39332c37382c3930,0x2c31342c3235322c,0x38372c38362c3132\n"
".quad 0x3133312c3031312c,0x3236312c3934322c,0x69762e090a0a3b7d,0x662e20656c626973\n"
".quad 0x61702e2820636e75,0x696c612e206d6172,0x38622e2038206e67,0x72616475635f5f20\n"
".quad 0x31315a5f5f667465,0x5f78656c706d6f63,0x295d385b66707865,0x6d6f6331315a5f20\n"
".quad 0x7078655f78656c70,0x617261702e282066,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x31315a5f5f31666d,0x5f78656c706d6f63,0x7b090a2966707865,0x2e206765722e090a\n"
".quad 0x313c722520323375,0x722e090a3b3e3435,0x203436752e206765,0x3b3e35313c647225\n"
".quad 0x2e206765722e090a,0x373c662520323366,0x65722e090a3b3e31,0x20646572702e2067\n"
".quad 0x0a3b3e36323c7025,0x206c61636f6c2e09,0x34206e67696c612e,0x635f5f2038622e20\n"
".quad 0x75635f5f5f616475,0x6c757365725f6164,0x38325b3032335f74,0x636f6c2e090a3b5d\n"
".quad 0x67696c612e206c61,0x2038622e2034206e,0x5f5f616475635f5f,0x65725f616475635f\n"
".quad 0x3230365f746c7573,0x090a3b5d38325b38,0x09363109636f6c2e,0x444c240a30093635\n"
".quad 0x5f5f6e6967656257,0x6c706d6f6331315a,0x3a667078655f7865,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5f5b202c316625,0x6d72617061647563,0x6331315a5f5f3166\n"
".quad 0x655f78656c706d6f,0x6d090a3b5d667078,0x09203233662e766f,0x316625202c326625\n"
".quad 0x09636f6c2e090a3b,0x0932303731093831,0x662e736261090a30,0x2c33662509203233\n"
".quad 0x6d090a3b32662520,0x09203233662e766f,0x376630202c346625,0x3b30303030303866\n"
".quad 0x2f2f092020202020,0x2946302e31282820,0x292946302e30282f,0x652e70746573090a\n"
".quad 0x2509203233662e71,0x2c336625202c3170,0x40090a3b34662520,0x6172622031702521\n"
".quad 0x5f315f744c240920,0x090a3b3435353332,0x09383109636f6c2e,0x090a300933303731\n"
".quad 0x203233662e67656e,0x6625202c35662509,0x2e646461090a3b32,0x09203233662e6e72\n"
".quad 0x326625202c366625,0x090a3b356625202c,0x203436752e766f6d,0x5f202c3164722509\n"
".quad 0x5f7472616475635f,0x3b665f69706f3269,0x6e752e617262090a,0x6557444c24092069\n"
".quad 0x73695f5f5f69646e,0x3837315f66666e69,0x5f744c240a3b355f,0x3a34353533325f31\n"
".quad 0x33662e766f6d090a,0x202c376625092032,0x3761623337346630,0x20202020203b3030\n"
".quad 0x33303834202f2f09,0x2e70746573090a39,0x09203233662e7467,0x336625202c327025\n"
".quad 0x090a3b376625202c,0x7262203270252140,0x315f744c24092061,0x0a3b36363034325f\n"
".quad 0x383109636f6c2e09,0x0a30093639333109,0x3436752e766f6d09,0x202c316472250920\n"
".quad 0x7472616475635f5f,0x665f69706f32695f,0x622e766f6d090a3b,0x2c31722509203233\n"
".quad 0x61090a3b32662520,0x09203233622e646e,0x317225202c327225,0x34373431322d202c\n"
".quad 0x090a3b3834363338,0x203233732e766f6d,0x7225202c33722509,0x636f6c2e090a3b32\n"
".quad 0x3009343209383109,0x33622e6c6873090a,0x202c347225092032,0x0a3b38202c317225\n"
".quad 0x203233622e726f09,0x7225202c35722509,0x373431322d202c34,0x0a3b383436333834\n"
".quad 0x3436732e766f6d09,0x202c326472250920,0x6d090a3b31647225,0x09203436752e766f\n"
".quad 0x5f5f202c33647225,0x635f5f5f61647563,0x757365725f616475,0x0a3b3032335f746c\n"
".quad 0x3233732e766f6d09,0x30202c3672250920,0x752e766f6d090a3b,0x2c37722509203233\n"
".quad 0x5f744c240a3b3020,0x3a30393035325f31,0x6d676172702e090a,0x726e756f6e222061\n"
".quad 0x2f200a3b226c6c6f,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3220656e696c2079\n"
".quad 0x697473656e202c34,0x687470656420676e,0x657469202c31203a,0x3a736e6f69746172\n"
".quad 0x636f6c2e090a3620,0x3031343109383109,0x632e646c090a3009,0x3233752e74736e6f\n"
".quad 0x5b202c3872250920,0x3b5d302b32647225,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x202c387225202c39,0x6461090a3b357225,0x2509203233752e64,0x397225202c303172\n"
".quad 0x090a3b377225202c,0x09383109636f6c2e,0x090a300931313431,0x752e74672e746573\n"
".quad 0x09203233752e3233,0x7225202c31317225,0x3b30317225202c39,0x33732e67656e090a\n"
".quad 0x2c32317225092032,0x090a3b3131722520,0x752e69682e6c756d,0x3331722509203233\n"
".quad 0x25202c387225202c,0x646461090a3b3572,0x722509203233752e,0x2c32317225202c37\n"
".quad 0x090a3b3331722520,0x09383109636f6c2e,0x090a300932313431,0x6c61636f6c2e7473\n"
".quad 0x255b09203233752e,0x202c5d302b336472,0x61090a3b30317225,0x09203233732e6464\n"
".quad 0x367225202c367225,0x6461090a3b31202c,0x2509203436752e64,0x647225202c336472\n"
".quad 0x61090a3b34202c33,0x09203436752e6464,0x7225202c32647225,0x090a3b34202c3264\n"
".quad 0x203233752e766f6d,0x36202c3431722509,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x367225202c337025,0x0a3b34317225202c,0x7262203370254009,0x315f744c24092061\n"
".quad 0x0a3b30393035325f,0x383109636f6c2e09,0x0a30093431343109,0x61636f6c2e747309\n"
".quad 0x5b09203233752e6c,0x5f5f616475635f5f,0x65725f616475635f,0x3032335f746c7573\n"
".quad 0x7225202c5d34322b,0x636f6c2e090a3b37,0x3931343109383109,0x2e6c6873090a3009\n"
".quad 0x3172250920323362,0x202c317225202c35,0x2e726873090a3b31,0x3172250920323375\n"
".quad 0x2c35317225202c36,0x7573090a3b343220,0x2509203233752e62,0x317225202c373172\n"
".quad 0x0a3b383231202c36,0x3436752e766f6d09,0x202c346472250920,0x5f5f616475635f5f\n"
".quad 0x65725f616475635f,0x3032335f746c7573,0x752e726873090a3b,0x3831722509203233\n"
".quad 0x202c37317225202c,0x2e766f6d090a3b35,0x3172250920323373,0x73090a3b34202c39\n"
".quad 0x09203233732e6275,0x7225202c30327225,0x38317225202c3931,0x732e747663090a3b\n"
".quad 0x09203233732e3436,0x7225202c35647225,0x6c756d090a3b3032,0x33732e656469772e\n"
".quad 0x2c36647225092032,0x34202c3032722520,0x752e646461090a3b,0x3764722509203436\n"
".quad 0x202c34647225202c,0x6c090a3b36647225,0x2e6c61636f6c2e64,0x3772250920323375\n"
".quad 0x2b376472255b202c,0x6f6c2e090a3b5d38,0x3234310938310963,0x2e646c090a300930\n"
".quad 0x33752e6c61636f6c,0x2c31327225092032,0x342b376472255b20,0x2e646e61090a3b5d\n"
".quad 0x3272250920323362,0x2c37317225202c32,0x6f6d090a3b313320,0x2509203233752e76\n"
".quad 0x0a3b30202c333272,0x71652e7074657309,0x702509203233752e,0x2c32327225202c34\n"
".quad 0x090a3b3332722520,0x6172622034702540,0x5f315f744c240920,0x090a3b3230363532\n"
".quad 0x09383109636f6c2e,0x090a300933323431,0x203233732e766f6d,0x33202c3432722509\n"
".quad 0x2e627573090a3b32,0x3272250920323373,0x2c34327225202c35,0x090a3b3232722520\n"
".quad 0x203233752e726873,0x25202c3632722509,0x327225202c313272,0x2e6c6873090a3b35\n"
".quad 0x3272250920323362,0x202c377225202c37,0x61090a3b32327225,0x09203233752e6464\n"
".quad 0x327225202c377225,0x3b37327225202c36,0x3109636f6c2e090a,0x3009343234310938\n"
".quad 0x636f6c2e646c090a,0x09203233752e6c61,0x255b202c38327225,0x0a3b5d302b376472\n"
".quad 0x3233752e72687309,0x202c393272250920,0x7225202c38327225,0x6c6873090a3b3532\n"
".quad 0x722509203233622e,0x31327225202c3033,0x0a3b32327225202c,0x3233752e64646109\n"
".quad 0x202c313272250920,0x7225202c39327225,0x5f744c240a3b3033,0x3a32303635325f31\n"
".quad 0x3109636f6c2e090a,0x3009363234310938,0x33752e726873090a,0x202c367225092032\n"
".quad 0x3b3033202c377225,0x3109636f6c2e090a,0x3009383234310938,0x33752e726873090a\n"
".quad 0x2c31337225092032,0x33202c3132722520,0x2e6c6873090a3b30,0x3372250920323362\n"
".quad 0x202c377225202c32,0x2e646461090a3b32,0x3772250920323375,0x202c31337225202c\n"
".quad 0x2e090a3b32337225,0x3109383109636f6c,0x73090a3009393234,0x09203233622e6c68\n"
".quad 0x7225202c31327225,0x090a3b32202c3132,0x203233752e766f6d,0x30202c3333722509\n"
".quad 0x2e70746573090a3b,0x09203233752e7165,0x327225202c357025,0x3b33337225202c31\n"
".quad 0x622035702540090a,0x5f744c2409206172,0x3b30373336325f31,0x3109636f6c2e090a\n"
".quad 0x3009303334310938,0x33752e646461090a,0x2c34337225092032,0x3b31202c37722520\n"
".quad 0x33752e766f6d090a,0x2c35337225092032,0x3834373431322d20,0x73090a3b38343633\n"
".quad 0x33752e74672e7465,0x2509203233752e32,0x337225202c363372,0x3b35337225202c34\n"
".quad 0x33732e67656e090a,0x2c37337225092032,0x090a3b3633722520,0x20696e752e617262\n"
".quad 0x325f315f744c2409,0x4c240a3b34313136,0x373336325f315f74,0x2e766f6d090a3a30\n"
".quad 0x3372250920323375,0x373431322d202c38,0x0a3b383436333834,0x2e74672e74657309\n"
".quad 0x203233752e323375,0x25202c3933722509,0x38337225202c3772,0x732e67656e090a3b\n"
".quad 0x3733722509203233,0x0a3b39337225202c,0x36325f315f744c24,0x6c2e090a3a343131\n"
".quad 0x343109383109636f,0x6461090a30093133,0x2509203233752e64,0x367225202c303472\n"
".quad 0x0a3b37337225202c,0x383109636f6c2e09,0x0a30093033343109,0x3233732e67656e09\n"
".quad 0x202c313472250920,0x6d090a3b30347225,0x09203233752e766f,0x3b30202c32347225\n"
".quad 0x6e2e70746573090a,0x2509203233752e65,0x2c327225202c3670,0x090a3b3234722520\n"
".quad 0x3233732e706c6573,0x25202c3672250920,0x347225202c313472,0x0a3b367025202c30\n"
".quad 0x3233752e766f6d09,0x202c333472250920,0x70746573090a3b30,0x203233752e71652e\n"
".quad 0x7225202c37702509,0x33347225202c3733,0x2037702540090a3b,0x744c240920617262\n"
".quad 0x36323636325f315f,0x09636f6c2e090a3b,0x0936333431093831,0x732e67656e090a30\n"
".quad 0x3132722509203233,0x0a3b31327225202c,0x383109636f6c2e09,0x0a30093833343109\n"
".quad 0x3233752e766f6d09,0x202c343472250920,0x2e746573090a3b30,0x752e3233752e7165\n"
".quad 0x3534722509203233,0x202c31327225202c,0x6e090a3b34347225,0x09203233732e6765\n"
".quad 0x7225202c36347225,0x746f6e090a3b3534,0x722509203233622e,0x3b377225202c3734\n"
".quad 0x33752e646461090a,0x202c377225092032,0x7225202c36347225,0x6f6c2e090a3b3734\n"
".quad 0x3334310938310963,0x726f78090a300939,0x722509203233622e,0x202c327225202c33\n"
".quad 0x333834373431322d,0x744c240a3b383436,0x36323636325f315f,0x09636f6c2e090a3a\n"
".quad 0x0931343431093831,0x732e766f6d090a30,0x3834722509203233,0x090a3b367225202c\n"
".quad 0x203233752e766f6d,0x30202c3934722509,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x377225202c387025,0x0a3b39347225202c,0x7262203870254009,0x315f744c24092061\n"
".quad 0x0a3b38313834335f,0x3233752e766f6d09,0x202c303572250920,0x315f744c240a3b30\n"
".quad 0x0a3a30353637325f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x6e202c3134343120,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09383109636f6c2e\n"
".quad 0x090a300935343431,0x203233752e726873,0x25202c3135722509,0x3b3133202c313272\n"
".quad 0x33622e6c6873090a,0x2c32357225092032,0x3b31202c37722520,0x33752e646461090a\n"
".quad 0x202c377225092032,0x7225202c31357225,0x6f6c2e090a3b3235,0x3434310938310963\n"
".quad 0x6c6873090a300936,0x722509203233622e,0x31327225202c3132,0x6c2e090a3b31202c\n"
".quad 0x343109383109636f,0x7573090a30093734,0x2509203233752e62,0x357225202c303572\n"
".quad 0x6d090a3b31202c30,0x09203233752e766f,0x3b30202c33357225,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x2c377225202c3970,0x090a3b3335722520,0x6172622039702540\n"
".quad 0x5f315f744c240920,0x090a3b3035363732,0x20696e752e617262,0x325f315f744c2409\n"
".quad 0x4c240a3b38333137,0x313834335f315f74,0x2e766f6d090a3a38,0x3572250920323375\n"
".quad 0x4c240a3b30202c30,0x333137325f315f74,0x636f6c2e090a3a38,0x3934343109383109\n"
".quad 0x2e6c756d090a3009,0x09203233752e6f6c,0x7225202c31327225,0x373132392d202c37\n"
".quad 0x090a3b3037383730,0x09383109636f6c2e,0x090a300930353431,0x203233752e766f6d\n"
".quad 0x2d202c3435722509,0x3738373037313239,0x2e6c756d090a3b30,0x09203233752e6968\n"
".quad 0x377225202c377225,0x0a3b34357225202c,0x3233752e766f6d09,0x202c353572250920\n"
".quad 0x70746573090a3b30,0x203233732e656c2e,0x25202c3031702509,0x35357225202c3772\n"
".quad 0x3031702540090a3b,0x4c24092061726220,0x363138325f315f74,0x636f6c2e090a3b32\n"
".quad 0x3235343109383109,0x2e726873090a3009,0x3572250920323375,0x2c31327225202c36\n"
".quad 0x6873090a3b313320,0x2509203233622e6c,0x377225202c373572,0x6461090a3b31202c\n"
".quad 0x2509203233752e64,0x36357225202c3772,0x0a3b37357225202c,0x383109636f6c2e09\n"
".quad 0x0a30093335343109,0x3233622e6c687309,0x202c313272250920,0x3b31202c31327225\n"
".quad 0x3109636f6c2e090a,0x3009343534310938,0x33752e627573090a,0x2c30357225092032\n"
".quad 0x31202c3035722520,0x5f315f744c240a3b,0x090a3a3236313832,0x09383109636f6c2e\n"
".quad 0x090a300936353431,0x203233752e766f6d,0x30202c3835722509,0x6e2e746573090a3b\n"
".quad 0x33752e3233752e65,0x2c39357225092032,0x25202c3132722520,0x656e090a3b383572\n"
".quad 0x2509203233732e67,0x357225202c303672,0x2e646461090a3b39,0x3772250920323375\n"
".quad 0x202c30367225202c,0x6c2e090a3b377225,0x343109383109636f,0x6873090a30093835\n"
".quad 0x2509203233622e6c,0x377225202c313672,0x6d090a3b3432202c,0x09203233732e766f\n"
".quad 0x3b30202c32367225,0x746c2e746573090a,0x3233732e3233752e,0x202c333672250920\n"
".quad 0x7225202c31367225,0x67656e090a3b3236,0x722509203233732e,0x33367225202c3436\n"
".quad 0x752e726873090a3b,0x3536722509203233,0x38202c377225202c,0x752e646461090a3b\n"
".quad 0x3636722509203233,0x202c30357225202c,0x6873090a3b363231,0x2509203233622e6c\n"
".quad 0x367225202c373672,0x090a3b3332202c36,0x203233752e646461,0x25202c3836722509\n"
".quad 0x367225202c353672,0x2e646461090a3b37,0x3672250920323375,0x2c34367225202c39\n"
".quad 0x090a3b3836722520,0x09203233622e726f,0x7225202c30377225,0x3b39367225202c33\n"
".quad 0x33622e766f6d090a,0x202c386625092032,0x62090a3b30377225,0x0920696e752e6172\n"
".quad 0x69646e6557444c24,0x7265746e695f5f5f,0x64616d665f6c616e,0x0a3b365f3837315f\n"
".quad 0x34325f315f744c24,0x6c2e090a3a363630,0x343109383109636f,0x6f6d090a30093137\n"
".quad 0x2509203233662e76,0x66336630202c3966,0x203b333839663232,0x202f2f0920202020\n"
".quad 0x0a32363633362e30,0x3233662e6c756d09,0x202c303166250920,0x396625202c326625\n"
".quad 0x722e747663090a3b,0x662e3233732e696e,0x3137722509203233,0x0a3b30316625202c\n"
".quad 0x3233732e766f6d09,0x202c383472250920,0x2e090a3b31377225,0x3109383109636f6c\n"
".quad 0x63090a3009323734,0x33662e6e722e7476,0x2509203233732e32,0x377225202c313166\n"
".quad 0x2e67656e090a3b31,0x3166250920323366,0x3b31316625202c32,0x33662e766f6d090a\n"
".quad 0x2c33316625092032,0x6135386532663020,0x202020203b393033,0x37302e36202f2f09\n"
".quad 0x090a31312d653137,0x203233662e766f6d,0x30202c3431662509,0x3261616466393366\n"
".quad 0x2f09202020203b30,0x343030302e30202f,0x6d090a3732383338,0x09203233662e766f\n"
".quad 0x6630202c35316625,0x3030303039636633,0x2f2f09202020203b,0x31333037352e3120\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x32316625202c3631,0x202c35316625202c\n"
".quad 0x6d66090a3b326625,0x3233662e6e722e61,0x202c373166250920,0x6625202c32316625\n"
".quad 0x36316625202c3431,0x722e616d66090a3b,0x2509203233662e6e,0x32316625202c3866\n"
".quad 0x202c33316625202c,0x6d090a3b37316625,0x09203436752e766f,0x5f5f202c31647225\n"
".quad 0x695f747261647563,0x0a3b665f69706f32,0x69646e6557444c24,0x7265746e695f5f5f\n"
".quad 0x64616d665f6c616e,0x0a3a365f3837315f,0x383109636f6c2e09,0x0a30093530373109\n"
".quad 0x3233732e64646109,0x202c323772250920,0x3b31202c38347225,0x33662e766f6d090a\n"
".quad 0x2c38316625092032,0x6d090a3b38662520,0x09203233662e6c75,0x6625202c39316625\n"
".quad 0x38316625202c3831,0x622e646e61090a3b,0x3337722509203233,0x202c32377225202c\n"
".quad 0x2e766f6d090a3b31,0x3772250920323375,0x73090a3b30202c34,0x732e71652e707465\n"
".quad 0x3131702509203233,0x202c33377225202c,0x40090a3b34377225,0x6172622031317025\n"
".quad 0x5f315f744c240920,0x090a3b3033393832,0x09383109636f6c2e,0x090a300939303731\n"
".quad 0x203233662e766f6d,0x30202c3032662509,0x6335666363373366,0x2f09202020203b65\n"
".quad 0x333334342e32202f,0x6d090a35302d6532,0x09203233662e766f,0x6630202c31326625\n"
".quad 0x6131363036626162,0x2f2f09202020203b,0x333130302e302d20,0x6d66090a33373838\n"
".quad 0x3233662e6e722e61,0x202c323266250920,0x6625202c30326625,0x31326625202c3931\n"
".quad 0x662e766f6d090a3b,0x3332662509203233,0x613264336630202c,0x2020203b35616161\n"
".quad 0x302e30202f2f0920,0x090a363636363134,0x662e6e722e616d66,0x3432662509203233\n"
".quad 0x202c32326625202c,0x6625202c39316625,0x766f6d090a3b3332,0x662509203233662e\n"
".quad 0x66626630202c3532,0x203b303030303030,0x2d202f2f09202020,0x616d66090a352e30\n"
".quad 0x203233662e6e722e,0x25202c3632662509,0x316625202c343266,0x3b35326625202c39\n"
".quad 0x33662e766f6d090a,0x2c37326625092032,0x3030386633663020,0x202020203b303030\n"
".quad 0x66090a31202f2f09,0x33662e6e722e616d,0x2c38326625092032,0x25202c3632662520\n"
".quad 0x326625202c393166,0x2e617262090a3b37,0x744c240920696e75,0x34373638325f315f\n"
".quad 0x5f315f744c240a3b,0x090a3a3033393832,0x09383109636f6c2e,0x090a300931313731\n"
".quad 0x203233662e766f6d,0x30202c3932662509,0x6631616334396266,0x2f09202020203b39\n"
".quad 0x3030302e302d202f,0x090a333531353931,0x203233662e766f6d,0x30202c3033662509\n"
".quad 0x3933383830633366,0x2f09202020203b65,0x333830302e30202f,0x6d66090a36313233\n"
".quad 0x3233662e6e722e61,0x202c313366250920,0x6625202c39326625,0x30336625202c3931\n"
".quad 0x662e766f6d090a3b,0x3233662509203233,0x613265626630202c,0x2020203b33616161\n"
".quad 0x2e302d202f2f0920,0x090a373636363631,0x662e6e722e616d66,0x3333662509203233\n"
".quad 0x202c31336625202c,0x6625202c39316625,0x6c756d090a3b3233,0x662509203233662e\n"
".quad 0x39316625202c3433,0x0a3b33336625202c,0x2e6e722e616d6609,0x3266250920323366\n"
".quad 0x2c34336625202c38,0x25202c3831662520,0x744c240a3b383166,0x34373638325f315f\n"
".quad 0x09636f6c2e090a3a,0x0933313731093831,0x662e67656e090a30,0x3533662509203233\n"
".quad 0x0a3b38326625202c,0x3233622e646e6109,0x202c353772250920,0x3b32202c32377225\n"
".quad 0x33732e766f6d090a,0x2c36377225092032,0x746573090a3b3020,0x3233732e656e2e70\n"
".quad 0x202c323170250920,0x7225202c35377225,0x6c6573090a3b3637,0x2509203233662e70\n"
".quad 0x336625202c383266,0x2c38326625202c35,0x090a3b3231702520,0x09383109636f6c2e\n"
".quad 0x090a300936313731,0x203233662e766f6d,0x6625202c36662509,0x57444c240a3b3832\n"
".quad 0x695f5f5f69646e65,0x37315f66666e6973,0x6c2e090a3a355f38,0x363109383109636f\n"
".quad 0x6573090a30093833,0x09203233732e706c,0x2c31202c37377225,0x3b317025202c3020\n"
".quad 0x33662e766f6d090a,0x2c36336625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x73090a30202f2f09,0x33752e71652e7465,0x2509203233662e32,0x326625202c383772\n"
".quad 0x0a3b36336625202c,0x3233732e67656e09,0x202c393772250920,0x6f090a3b38377225\n"
".quad 0x2509203233622e72,0x377225202c303872,0x3b39377225202c37,0x33752e766f6d090a\n"
".quad 0x2c31387225092032,0x746573090a3b3020,0x3233732e71652e70,0x202c333170250920\n"
".quad 0x7225202c30387225,0x702540090a3b3138,0x0920617262203331,0x39325f315f744c24\n"
".quad 0x6c2e090a3b363831,0x363109383109636f,0x6f6d090a30093933,0x2509203233662e76\n"
".quad 0x306630202c373366,0x3b30303030303030,0x202f2f0920202020,0x722e6c756d090a30\n"
".quad 0x2509203233662e6e,0x326625202c383366,0x0a3b37336625202c,0x696e752e61726209\n"
".quad 0x6e6557444c240920,0x6973695f5f5f6964,0x5f3837315f66666e,0x315f744c240a3b31\n"
".quad 0x0a3a36383139325f,0x3233662e766f6d09,0x202c393366250920,0x3761623337346630\n"
".quad 0x09202020203b3030,0x3933303834202f2f,0x672e70746573090a,0x2509203233662e74\n"
".quad 0x336625202c343170,0x0a3b39336625202c,0x2034317025214009,0x744c240920617262\n"
".quad 0x38393639325f315f,0x09636f6c2e090a3b,0x0936393331093831,0x622e766f6d090a30\n"
".quad 0x2c31722509203233,0x61090a3b32662520,0x09203233622e646e,0x317225202c327225\n"
".quad 0x34373431322d202c,0x090a3b3834363338,0x203233732e766f6d,0x25202c3238722509\n"
".quad 0x6f6c2e090a3b3272,0x0934320938310963,0x622e6c6873090a30,0x3338722509203233\n"
".quad 0x38202c317225202c,0x33622e726f090a3b,0x202c357225092032,0x322d202c33387225\n"
".quad 0x3436333834373431,0x2e766f6d090a3b38,0x6472250920343673,0x3b31647225202c38\n"
".quad 0x36752e766f6d090a,0x2c39647225092034,0x5f616475635f5f20,0x725f616475635f5f\n"
".quad 0x30365f746c757365,0x766f6d090a3b3832,0x722509203233732e,0x090a3b30202c3438\n"
".quad 0x203233752e766f6d,0x30202c3538722509,0x5f315f744c240a3b,0x090a3a3232373033\n"
".quad 0x20616d676172702e,0x6c6f726e756f6e22,0x3c2f2f200a3b226c,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x2c343220656e696c,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6172657469202c31,0x36203a736e6f6974,0x3109636f6c2e090a,0x3009303134310938\n"
".quad 0x6e6f632e646c090a,0x09203233752e7473,0x255b202c36387225,0x0a3b5d302b386472\n"
".quad 0x2e6f6c2e6c756d09,0x3872250920323375,0x2c36387225202c37,0x61090a3b35722520\n"
".quad 0x09203233752e6464,0x7225202c38387225,0x35387225202c3738,0x09636f6c2e090a3b\n"
".quad 0x0931313431093831,0x672e746573090a30,0x33752e3233752e74,0x2c39387225092032\n"
".quad 0x25202c3738722520,0x656e090a3b383872,0x2509203233732e67,0x387225202c303972\n"
".quad 0x2e6c756d090a3b39,0x09203233752e6968,0x7225202c31397225,0x3b357225202c3638\n"
".quad 0x33752e646461090a,0x2c35387225092032,0x25202c3039722520,0x6c2e090a3b313972\n"
".quad 0x343109383109636f,0x7473090a30093231,0x752e6c61636f6c2e,0x6472255b09203233\n"
".quad 0x7225202c5d302b39,0x646461090a3b3838,0x722509203233732e,0x34387225202c3438\n"
".quad 0x6461090a3b31202c,0x2509203436752e64,0x647225202c396472,0x61090a3b34202c39\n"
".quad 0x09203436752e6464,0x7225202c38647225,0x090a3b34202c3864,0x203233752e766f6d\n"
".quad 0x36202c3239722509,0x2e70746573090a3b,0x09203233732e656e,0x7225202c35317025\n"
".quad 0x32397225202c3438,0x3531702540090a3b,0x4c24092061726220,0x323730335f315f74\n"
".quad 0x636f6c2e090a3b32,0x3431343109383109,0x6c2e7473090a3009,0x3233752e6c61636f\n"
".quad 0x6475635f5f5b0920,0x616475635f5f5f61,0x5f746c757365725f,0x5d34322b38323036\n"
".quad 0x0a3b35387225202c,0x383109636f6c2e09,0x0a30093931343109,0x3233622e6c687309\n"
".quad 0x202c333972250920,0x0a3b31202c317225,0x3233752e72687309,0x202c343972250920\n"
".quad 0x3432202c33397225,0x752e627573090a3b,0x3539722509203233,0x202c34397225202c\n"
".quad 0x6f6d090a3b383231,0x2509203436752e76,0x5f5f202c30316472,0x635f5f5f61647563\n"
".quad 0x757365725f616475,0x3b383230365f746c,0x33752e726873090a,0x2c36397225092032\n"
".quad 0x35202c3539722520,0x732e766f6d090a3b,0x3739722509203233,0x7573090a3b34202c\n"
".quad 0x2509203233732e62,0x397225202c383972,0x3b36397225202c37,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x7225202c31316472,0x6c756d090a3b3839,0x33732e656469772e\n"
".quad 0x3231647225092032,0x202c38397225202c,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x31647225202c3331,0x3231647225202c30,0x6f6c2e646c090a3b,0x203233752e6c6163\n"
".quad 0x5b202c3538722509,0x5d382b3331647225,0x09636f6c2e090a3b,0x0930323431093831\n"
".quad 0x6f6c2e646c090a30,0x203233752e6c6163,0x5b202c3939722509,0x5d342b3331647225\n"
".quad 0x622e646e61090a3b,0x3232722509203233,0x202c35397225202c,0x766f6d090a3b3133\n"
".quad 0x722509203233752e,0x0a3b30202c303031,0x71652e7074657309,0x702509203233752e\n"
".quad 0x32327225202c3631,0x3b3030317225202c,0x203631702540090a,0x744c240920617262\n"
".quad 0x34333231335f315f,0x09636f6c2e090a3b,0x0933323431093831,0x732e766f6d090a30\n"
".quad 0x3031722509203233,0x090a3b3233202c31,0x203233732e627573,0x202c323031722509\n"
".quad 0x25202c3130317225,0x6873090a3b323272,0x2509203233752e72,0x7225202c33303172\n"
".quad 0x30317225202c3939,0x2e6c6873090a3b32,0x3172250920323362,0x35387225202c3430\n"
".quad 0x0a3b32327225202c,0x3233752e64646109,0x202c353872250920,0x25202c3330317225\n"
".quad 0x2e090a3b34303172,0x3109383109636f6c,0x6c090a3009343234,0x2e6c61636f6c2e64\n"
".quad 0x3172250920323375,0x6472255b202c3530,0x090a3b5d302b3331,0x203233752e726873\n"
".quad 0x202c363031722509,0x25202c3530317225,0x73090a3b32303172,0x09203233622e6c68\n"
".quad 0x25202c3730317225,0x327225202c393972,0x2e646461090a3b32,0x3972250920323375\n"
".quad 0x3630317225202c39,0x3b3730317225202c,0x335f315f744c240a,0x2e090a3a34333231\n"
".quad 0x3109383109636f6c,0x73090a3009363234,0x09203233752e7268,0x7225202c34387225\n"
".quad 0x0a3b3033202c3538,0x383109636f6c2e09,0x0a30093832343109,0x3233752e72687309\n"
".quad 0x2c38303172250920,0x33202c3939722520,0x2e6c6873090a3b30,0x3172250920323362\n"
".quad 0x35387225202c3930,0x6461090a3b32202c,0x2509203233752e64,0x317225202c353872\n"
".quad 0x30317225202c3830,0x636f6c2e090a3b39,0x3932343109383109,0x2e6c6873090a3009\n"
".quad 0x3972250920323362,0x2c39397225202c39,0x766f6d090a3b3220,0x722509203233752e\n"
".quad 0x0a3b30202c303131,0x71652e7074657309,0x702509203233752e,0x39397225202c3731\n"
".quad 0x3b3031317225202c,0x203731702540090a,0x744c240920617262,0x32303032335f315f\n"
".quad 0x09636f6c2e090a3b,0x0930333431093831,0x752e646461090a30,0x3131722509203233\n"
".quad 0x2c35387225202c31,0x766f6d090a3b3120,0x722509203233752e,0x31322d202c323131\n"
".quad 0x3834363338343734,0x672e746573090a3b,0x33752e3233752e74,0x3331317225092032\n"
".quad 0x2c3131317225202c,0x0a3b323131722520,0x3233732e67656e09,0x2c34313172250920\n"
".quad 0x0a3b333131722520,0x696e752e61726209,0x5f315f744c240920,0x240a3b3634373133\n"
".quad 0x3032335f315f744c,0x766f6d090a3a3230,0x722509203233752e,0x31322d202c353131\n"
".quad 0x3834363338343734,0x672e746573090a3b,0x33752e3233752e74,0x3631317225092032\n"
".quad 0x202c35387225202c,0x090a3b3531317225,0x203233732e67656e,0x202c343131722509\n"
".quad 0x240a3b3631317225,0x3731335f315f744c,0x6f6c2e090a3a3634,0x3334310938310963\n"
".quad 0x646461090a300931,0x722509203233752e,0x387225202c373131,0x3431317225202c34\n"
".quad 0x09636f6c2e090a3b,0x0930333431093831,0x732e67656e090a30,0x3131722509203233\n"
".quad 0x3731317225202c38,0x752e766f6d090a3b,0x3131722509203233,0x73090a3b30202c39\n"
".quad 0x752e656e2e707465,0x3831702509203233,0x25202c327225202c,0x73090a3b39313172\n"
".quad 0x203233732e706c65,0x25202c3438722509,0x7225202c38313172,0x317025202c373131\n"
".quad 0x2e766f6d090a3b38,0x3172250920323375,0x090a3b30202c3032,0x2e71652e70746573\n"
".quad 0x3170250920323375,0x3431317225202c39,0x3b3032317225202c,0x203931702540090a\n"
".quad 0x744c240920617262,0x38353232335f315f,0x09636f6c2e090a3b,0x0936333431093831\n"
".quad 0x732e67656e090a30,0x3939722509203233,0x0a3b39397225202c,0x383109636f6c2e09\n"
".quad 0x0a30093833343109,0x3233752e766f6d09,0x2c31323172250920,0x746573090a3b3020\n"
".quad 0x2e3233752e71652e,0x3172250920323375,0x39397225202c3232,0x3b3132317225202c\n"
".quad 0x33732e67656e090a,0x3332317225092032,0x3b3232317225202c,0x33622e746f6e090a\n"
".quad 0x3432317225092032,0x0a3b35387225202c,0x3233752e64646109,0x202c353872250920\n"
".quad 0x25202c3332317225,0x2e090a3b34323172,0x3109383109636f6c,0x78090a3009393334\n"
".quad 0x09203233622e726f,0x7225202c32387225,0x373431322d202c32,0x0a3b383436333834\n"
".quad 0x32335f315f744c24,0x6c2e090a3a383532,0x343109383109636f,0x6f6d090a30093134\n"
".quad 0x2509203233732e76,0x7225202c35323172,0x766f6d090a3b3438,0x722509203233752e\n"
".quad 0x0a3b30202c363231,0x656c2e7074657309,0x702509203233732e,0x35387225202c3032\n"
".quad 0x3b3632317225202c,0x203032702540090a,0x744c240920617262,0x34373035335f315f\n"
".quad 0x752e766f6d090a3b,0x3231722509203233,0x4c240a3b30202c37,0x383233335f315f74\n"
".quad 0x6c3c2f2f200a3a32,0x6f6f4c203e706f6f,0x6c2079646f622070,0x3134343120656e69\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x0935343431093831\n"
".quad 0x752e726873090a30,0x3231722509203233,0x2c39397225202c38,0x6873090a3b313320\n"
".quad 0x2509203233622e6c,0x7225202c39323172,0x090a3b31202c3538,0x203233752e646461\n"
".quad 0x25202c3538722509,0x7225202c38323172,0x6c2e090a3b393231,0x343109383109636f\n"
".quad 0x6873090a30093634,0x2509203233622e6c,0x397225202c393972,0x2e090a3b31202c39\n"
".quad 0x3109383109636f6c,0x73090a3009373434,0x09203233752e6275,0x25202c3732317225\n"
".quad 0x3b31202c37323172,0x33752e766f6d090a,0x3033317225092032,0x6573090a3b30202c\n"
".quad 0x33732e74672e7074,0x2c31327025092032,0x25202c3538722520,0x40090a3b30333172\n"
".quad 0x6172622031327025,0x5f315f744c240920,0x090a3b3238323333,0x20696e752e617262\n"
".quad 0x335f315f744c2409,0x4c240a3b30373732,0x373035335f315f74,0x2e766f6d090a3a34\n"
".quad 0x3172250920323375,0x240a3b30202c3732,0x3732335f315f744c,0x6f6c2e090a3a3037\n"
".quad 0x3434310938310963,0x6c756d090a300939,0x203233752e6f6c2e,0x25202c3939722509\n"
".quad 0x32392d202c353872,0x3b30373837303731,0x3109636f6c2e090a,0x3009303534310938\n"
".quad 0x33752e766f6d090a,0x3133317225092032,0x30373132392d202c,0x6d090a3b30373837\n"
".quad 0x33752e69682e6c75,0x2c35387225092032,0x25202c3538722520,0x6d090a3b31333172\n"
".quad 0x09203233752e766f,0x30202c3233317225,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x7225202c32327025,0x33317225202c3538,0x32702540090a3b32,0x2409206172622032\n"
".quad 0x3733335f315f744c,0x6f6c2e090a3b3439,0x3534310938310963,0x726873090a300932\n"
".quad 0x722509203233752e,0x397225202c333331,0x090a3b3133202c39,0x203233622e6c6873\n"
".quad 0x202c343331722509,0x3b31202c35387225,0x33752e646461090a,0x2c35387225092032\n"
".quad 0x202c333331722520,0x090a3b3433317225,0x09383109636f6c2e,0x090a300933353431\n"
".quad 0x203233622e6c6873,0x25202c3939722509,0x0a3b31202c393972,0x383109636f6c2e09\n"
".quad 0x0a30093435343109,0x3233752e62757309,0x2c37323172250920,0x202c373231722520\n"
".quad 0x315f744c240a3b31,0x0a3a34393733335f,0x383109636f6c2e09,0x0a30093635343109\n"
".quad 0x3233752e766f6d09,0x2c35333172250920,0x746573090a3b3020,0x2e3233752e656e2e\n"
".quad 0x3172250920323375,0x39397225202c3633,0x3b3533317225202c,0x33732e67656e090a\n"
".quad 0x3733317225092032,0x3b3633317225202c,0x33752e646461090a,0x2c35387225092032\n"
".quad 0x202c373331722520,0x2e090a3b35387225,0x3109383109636f6c,0x73090a3009383534\n"
".quad 0x09203233622e6c68,0x25202c3833317225,0x3b3432202c353872,0x33732e766f6d090a\n"
".quad 0x3933317225092032,0x6573090a3b30202c,0x3233752e746c2e74,0x722509203233732e\n"
".quad 0x317225202c303431,0x33317225202c3833,0x2e67656e090a3b39,0x3172250920323373\n"
".quad 0x34317225202c3134,0x2e726873090a3b30,0x3172250920323375,0x35387225202c3234\n"
".quad 0x6461090a3b38202c,0x2509203233752e64,0x7225202c33343172,0x363231202c373231\n"
".quad 0x622e6c6873090a3b,0x3431722509203233,0x3334317225202c34,0x61090a3b3332202c\n"
".quad 0x09203233752e6464,0x25202c3534317225,0x7225202c32343172,0x6461090a3b343431\n"
".quad 0x2509203233752e64,0x7225202c36343172,0x317225202c313431,0x2e726f090a3b3534\n"
".quad 0x3172250920323362,0x32387225202c3734,0x3b3634317225202c,0x33622e766f6d090a\n"
".quad 0x2c30346625092032,0x0a3b373431722520,0x696e752e61726209,0x6e6557444c240920\n"
".quad 0x746e695f5f5f6964,0x6d665f6c616e7265,0x325f3837315f6461,0x5f315f744c240a3b\n"
".quad 0x090a3a3839363932,0x09383109636f6c2e,0x090a300931373431,0x203233662e766f6d\n"
".quad 0x30202c3134662509,0x3839663232663366,0x2f09202020203b33,0x363633362e30202f\n"
".quad 0x662e6c756d090a32,0x3234662509203233,0x25202c326625202c,0x7663090a3b313466\n"
".quad 0x33732e696e722e74,0x2509203233662e32,0x6625202c38343172,0x766f6d090a3b3234\n"
".quad 0x722509203233732e,0x317225202c353231,0x6f6c2e090a3b3834,0x3734310938310963\n"
".quad 0x747663090a300932,0x2e3233662e6e722e,0x3466250920323373,0x3834317225202c33\n"
".quad 0x662e67656e090a3b,0x3434662509203233,0x0a3b33346625202c,0x3233662e766f6d09\n"
".quad 0x202c353466250920,0x3361353865326630,0x09202020203b3930,0x3737302e36202f2f\n"
".quad 0x6d090a31312d6531,0x09203233662e766f,0x6630202c36346625,0x3032616164663933\n"
".quad 0x2f2f09202020203b,0x38343030302e3020,0x6f6d090a37323833,0x2509203233662e76\n"
".quad 0x336630202c373466,0x3b30303030396366,0x202f2f0920202020,0x0a31333037352e31\n"
".quad 0x2e6e722e616d6609,0x3466250920323366,0x2c34346625202c38,0x25202c3734662520\n"
".quad 0x616d66090a3b3266,0x203233662e6e722e,0x25202c3934662509,0x346625202c343466\n"
".quad 0x3b38346625202c36,0x6e722e616d66090a,0x662509203233662e,0x34346625202c3034\n"
".quad 0x202c35346625202c,0x4c240a3b39346625,0x5f5f69646e655744,0x616e7265746e695f\n"
".quad 0x315f64616d665f6c,0x2e090a3a325f3837,0x3109383109636f6c,0x6d090a3009313436\n"
".quad 0x09203233662e766f,0x6625202c30356625,0x6c756d090a3b3034,0x662509203233662e\n"
".quad 0x30356625202c3135,0x0a3b30356625202c,0x3233622e646e6109,0x2c39343172250920\n"
".quad 0x202c353231722520,0x2e766f6d090a3b31,0x3172250920323375,0x090a3b30202c3035\n"
".quad 0x2e71652e70746573,0x3270250920323373,0x3934317225202c33,0x3b3035317225202c\n"
".quad 0x203332702540090a,0x744c240920617262,0x32363534335f315f,0x09636f6c2e090a3b\n"
".quad 0x0934343631093831,0x662e766f6d090a30,0x3235662509203233,0x636337336630202c\n"
".quad 0x2020203b65633566,0x342e32202f2f0920,0x35302d6532333334,0x33662e766f6d090a\n"
".quad 0x2c33356625092032,0x3036626162663020,0x202020203b613136,0x302e302d202f2f09\n"
".quad 0x0a33373838333130,0x2e6e722e616d6609,0x3566250920323366,0x2c32356625202c34\n"
".quad 0x25202c3135662520,0x6f6d090a3b333566,0x2509203233662e76,0x336630202c353566\n"
".quad 0x3b35616161613264,0x202f2f0920202020,0x3636363134302e30,0x722e616d66090a36\n"
".quad 0x2509203233662e6e,0x356625202c363566,0x2c31356625202c34,0x090a3b3535662520\n"
".quad 0x203233662e766f6d,0x30202c3735662509,0x3030303030666266,0x2f09202020203b30\n"
".quad 0x090a352e302d202f,0x662e6e722e616d66,0x3835662509203233,0x202c36356625202c\n"
".quad 0x6625202c31356625,0x766f6d090a3b3735,0x662509203233662e,0x66336630202c3935\n"
".quad 0x203b303030303038,0x31202f2f09202020,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x38356625202c3036,0x202c31356625202c,0x62090a3b39356625,0x0920696e752e6172\n"
".quad 0x34335f315f744c24,0x744c240a3b363033,0x32363534335f315f,0x09636f6c2e090a3a\n"
".quad 0x0936343631093831,0x662e766f6d090a30,0x3136662509203233,0x633439626630202c\n"
".quad 0x2020203b39663161,0x2e302d202f2f0920,0x3531353931303030,0x662e766f6d090a33\n"
".quad 0x3236662509203233,0x383063336630202c,0x2020203b65393338,0x302e30202f2f0920\n"
".quad 0x0a36313233333830,0x2e6e722e616d6609,0x3666250920323366,0x2c31366625202c33\n"
".quad 0x25202c3135662520,0x6f6d090a3b323666,0x2509203233662e76,0x626630202c343666\n"
".quad 0x3b33616161613265,0x202f2f0920202020,0x36363636312e302d,0x722e616d66090a37\n"
".quad 0x2509203233662e6e,0x366625202c353666,0x2c31356625202c33,0x090a3b3436662520\n"
".quad 0x203233662e6c756d,0x25202c3636662509,0x366625202c313566,0x2e616d66090a3b35\n"
".quad 0x09203233662e6e72,0x6625202c30366625,0x30356625202c3636,0x0a3b30356625202c\n"
".quad 0x34335f315f744c24,0x6c2e090a3a363033,0x363109383109636f,0x656e090a30093834\n"
".quad 0x2509203233662e67,0x366625202c373666,0x2e646e61090a3b30,0x3172250920323362\n"
".quad 0x32317225202c3135,0x6d090a3b32202c35,0x09203233732e766f,0x30202c3235317225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x7225202c34327025,0x317225202c313531\n"
".quad 0x6c6573090a3b3235,0x2509203233662e70,0x366625202c303666,0x2c30366625202c37\n"
".quad 0x090a3b3432702520,0x09383109636f6c2e,0x090a300931353631,0x203233662e766f6d\n"
".quad 0x25202c3833662509,0x444c240a3b303666,0x5f5f5f69646e6557,0x315f66666e697369\n"
".quad 0x2e090a3a315f3837,0x3509363109636f6c,0x766f6d090a300937,0x662509203233662e\n"
".quad 0x3b366625202c3836,0x7261702e7473090a,0x09203233662e6d61,0x72616475635f5f5b\n"
".quad 0x31315a5f5f667465,0x5f78656c706d6f63,0x2c5d302b66707865,0x090a3b3836662520\n"
".quad 0x203233662e766f6d,0x25202c3936662509,0x7473090a3b383366,0x662e6d617261702e\n"
".quad 0x635f5f5b09203233,0x5f66746572616475,0x706d6f6331315a5f,0x667078655f78656c\n"
".quad 0x366625202c5d342b,0x3b746572090a3b39,0x646e6557444c240a,0x6d6f6331315a5f5f\n"
".quad 0x7078655f78656c70,0x2f2f207d090a3a66,0x6d6f6331315a5f20,0x7078655f78656c70\n"
".quad 0x7369762e090a0a66,0x75662e20656c6269,0x7261702e2820636e,0x67696c612e206d61\n"
".quad 0x2038622e2038206e,0x6572616475635f5f,0x6331315a5f5f6674,0x615f78656c706d6f\n"
".quad 0x74616f6c66366464,0x20295d385b5f5332,0x706d6f6331315a5f,0x366464615f78656c\n"
".quad 0x5f533274616f6c66,0x6d617261702e2820,0x206e67696c612e20,0x5f5f2038622e2038\n"
".quad 0x6d72617061647563,0x6331315a5f5f3166,0x615f78656c706d6f,0x74616f6c66366464\n"
".quad 0x202c5d385b5f5332,0x2e206d617261702e,0x2038206e67696c61,0x75635f5f2038622e\n"
".quad 0x32666d7261706164,0x6d6f6331315a5f5f,0x6464615f78656c70,0x533274616f6c6636\n"
".quad 0x7b090a295d385b5f,0x2e206765722e090a,0x313c662520323366,0x6f6c2e090a3b3e32\n"
".quad 0x0932360936310963,0x656257444c240a30,0x31315a5f5f6e6967,0x5f78656c706d6f63\n"
".quad 0x616f6c6636646461,0x6c090a3a5f533274,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x6475635f5f5b202c,0x5f31666d72617061,0x706d6f6331315a5f,0x366464615f78656c\n"
".quad 0x5f533274616f6c66,0x6f6d090a3b5d302b,0x2509203233662e76,0x3b316625202c3266\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c336625,0x6d72617061647563\n"
".quad 0x6331315a5f5f3166,0x615f78656c706d6f,0x74616f6c66366464,0x0a3b5d342b5f5332\n"
".quad 0x3233662e766f6d09,0x25202c3466250920,0x2e646c090a3b3366,0x33662e6d61726170\n"
".quad 0x202c356625092032,0x70616475635f5f5b,0x5a5f5f32666d7261,0x656c706d6f633131\n"
".quad 0x6c66366464615f78,0x302b5f533274616f,0x2e766f6d090a3b5d,0x3666250920323366\n"
".quad 0x090a3b356625202c,0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c37\n"
".quad 0x32666d7261706164,0x6d6f6331315a5f5f,0x6464615f78656c70,0x533274616f6c6636\n"
".quad 0x6d090a3b5d342b5f,0x09203233662e766f,0x376625202c386625,0x09636f6c2e090a3b\n"
".quad 0x0a30093336093631,0x3233662e64646109,0x25202c3966250920,0x3b366625202c3266\n"
".quad 0x7261702e7473090a,0x09203233662e6d61,0x72616475635f5f5b,0x31315a5f5f667465\n"
".quad 0x5f78656c706d6f63,0x616f6c6636646461,0x2c5d302b5f533274,0x61090a3b39662520\n"
".quad 0x09203233662e6464,0x6625202c30316625,0x0a3b386625202c34,0x617261702e747309\n"
".quad 0x5b09203233662e6d,0x6572616475635f5f,0x6331315a5f5f6674,0x615f78656c706d6f\n"
".quad 0x74616f6c66366464,0x202c5d342b5f5332,0x72090a3b30316625,0x57444c240a3b7465\n"
".quad 0x31315a5f5f646e65,0x5f78656c706d6f63,0x616f6c6636646461,0x7d090a3a5f533274\n"
".quad 0x31315a5f202f2f20,0x5f78656c706d6f63,0x616f6c6636646461,0x2e090a0a5f533274\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x612e206d61726170,0x2e2038206e67696c\n"
".quad 0x6475635f5f203862,0x5a5f5f6674657261,0x656c706d6f633231,0x6636746c756d5f78\n"
".quad 0x5b5f533274616f6c,0x32315a5f20295d38,0x5f78656c706d6f63,0x6f6c6636746c756d\n"
".quad 0x2e28205f53327461,0x612e206d61726170,0x2e2038206e67696c,0x6475635f5f203862\n"
".quad 0x5f31666d72617061,0x706d6f6332315a5f,0x746c756d5f78656c,0x533274616f6c6636\n"
".quad 0x702e202c5d385b5f,0x6c612e206d617261,0x622e2038206e6769,0x616475635f5f2038\n"
".quad 0x5f5f32666d726170,0x6c706d6f6332315a,0x36746c756d5f7865,0x5f533274616f6c66\n"
".quad 0x0a7b090a295d385b,0x662e206765722e09,0x35313c6625203233,0x636f6c2e090a3b3e\n"
".quad 0x3009383609363109,0x67656257444c240a,0x6332315a5f5f6e69,0x6d5f78656c706d6f\n"
".quad 0x616f6c6636746c75,0x6c090a3a5f533274,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x6475635f5f5b202c,0x5f31666d72617061,0x706d6f6332315a5f,0x746c756d5f78656c\n"
".quad 0x533274616f6c6636,0x6d090a3b5d302b5f,0x09203233662e766f,0x316625202c326625\n"
".quad 0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c33662509,0x726170616475635f\n"
".quad 0x32315a5f5f31666d,0x5f78656c706d6f63,0x6f6c6636746c756d,0x5d342b5f53327461\n"
".quad 0x662e766f6d090a3b,0x2c34662509203233,0x6c090a3b33662520,0x2e6d617261702e64\n"
".quad 0x3566250920323366,0x6475635f5f5b202c,0x5f32666d72617061,0x706d6f6332315a5f\n"
".quad 0x746c756d5f78656c,0x533274616f6c6636,0x6d090a3b5d302b5f,0x09203233662e766f\n"
".quad 0x356625202c366625,0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c37662509\n"
".quad 0x726170616475635f,0x32315a5f5f32666d,0x5f78656c706d6f63,0x6f6c6636746c756d\n"
".quad 0x5d342b5f53327461,0x662e766f6d090a3b,0x2c38662509203233,0x2e090a3b37662520\n"
".quad 0x3609363109636f6c,0x6c756d090a300939,0x662509203233662e,0x202c346625202c39\n"
".quad 0x756d090a3b386625,0x2509203233662e6c,0x326625202c303166,0x090a3b366625202c\n"
".quad 0x203233662e627573,0x25202c3131662509,0x396625202c303166,0x61702e7473090a3b\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x315a5f5f66746572,0x78656c706d6f6332\n"
".quad 0x6c6636746c756d5f,0x302b5f533274616f,0x3b31316625202c5d,0x33662e6c756d090a\n"
".quad 0x2c32316625092032,0x6625202c36662520,0x2e616d66090a3b34,0x09203233662e6e72\n"
".quad 0x6625202c33316625,0x202c386625202c32,0x73090a3b32316625,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323366,0x6674657261647563,0x6d6f6332315a5f5f,0x6c756d5f78656c70\n"
".quad 0x3274616f6c663674,0x25202c5d342b5f53,0x6572090a3b333166,0x6557444c240a3b74\n"
".quad 0x6332315a5f5f646e,0x6d5f78656c706d6f,0x616f6c6636746c75,0x7d090a3a5f533274\n"
".quad 0x32315a5f202f2f20,0x5f78656c706d6f63,0x6f6c6636746c756d,0x090a0a5f53327461\n"
".quad 0x5f207972746e652e,0x72656e656732325a,0x7463657053657461,0x656e72654b6d7572\n"
".quad 0x74616f6c6636506c,0x66666a6a5f305332,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x32325a5f5f6d7261,0x65746172656e6567,0x6d75727463657053\n"
".quad 0x36506c656e72654b,0x30533274616f6c66,0x30685f66666a6a5f,0x7261702e09090a2c\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x6732325a5f5f6d72,0x5365746172656e65\n"
".quad 0x4b6d757274636570,0x6636506c656e7265,0x5f30533274616f6c,0x2c74685f66666a6a\n"
".quad 0x617261702e09090a,0x5f203233752e206d,0x726170616475635f,0x656732325a5f5f6d\n"
".quad 0x705365746172656e,0x654b6d7572746365,0x6c6636506c656e72,0x6a5f30533274616f\n"
".quad 0x746469775f66666a,0x61702e09090a2c68,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x32325a5f5f6d7261,0x65746172656e6567,0x6d75727463657053,0x36506c656e72654b\n"
".quad 0x30533274616f6c66,0x65685f66666a6a5f,0x09090a2c74686769,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x5f5f6d7261706164,0x72656e656732325a,0x7463657053657461\n"
".quad 0x656e72654b6d7572,0x74616f6c6636506c,0x66666a6a5f305332,0x702e09090a2c745f\n"
".quad 0x33662e206d617261,0x616475635f5f2032,0x325a5f5f6d726170,0x746172656e656732\n"
".quad 0x7572746365705365,0x506c656e72654b6d,0x533274616f6c6636,0x705f66666a6a5f30\n"
".quad 0x657a695368637461,0x722e090a7b090a29,0x203233752e206765,0x3b3e3132333c7225\n"
".quad 0x2e206765722e090a,0x3c64722520343675,0x722e090a3b3e3832,0x203233662e206765\n"
".quad 0x3b3e3735313c6625,0x2e206765722e090a,0x3c70252064657270,0x6c2e090a3b3e3235\n"
".quad 0x6c612e206c61636f,0x622e2034206e6769,0x616475635f5f2038,0x5f616475635f5f5f\n"
".quad 0x335f746c75736572,0x3b5d38325b383832,0x6c61636f6c2e090a,0x206e67696c612e20\n"
".quad 0x5f5f2038622e2034,0x635f5f5f61647563,0x757365725f616475,0x36313130365f746c\n"
".quad 0x2e090a3b5d38325b,0x3709363109636f6c,0x57444c240a300933,0x5a5f5f6e69676562\n"
".quad 0x6172656e65673232,0x7274636570536574,0x6c656e72654b6d75,0x3274616f6c663650\n"
".quad 0x3a66666a6a5f3053,0x3109636f6c2e090a,0x090a300932380936,0x203233752e766f6d\n"
".quad 0x6325202c31722509,0x0a3b782e64696174,0x3233752e766f6d09,0x25202c3272250920\n"
".quad 0x0a3b782e6469746e,0x2e6f6c2e6c756d09,0x3372250920323375,0x25202c317225202c\n"
".quad 0x766f6d090a3b3272,0x722509203233752e,0x6961746325202c34,0x6f6d090a3b792e64\n"
".quad 0x2509203233752e76,0x69746e25202c3572,0x756d090a3b792e64,0x3233752e6f6c2e6c\n"
".quad 0x25202c3672250920,0x3b357225202c3472,0x33752e766f6d090a,0x202c377225092032\n"
".quad 0x0a3b782e64697425,0x3233752e64646109,0x25202c3872250920,0x3b337225202c3772\n"
".quad 0x33752e766f6d090a,0x202c397225092032,0x0a3b792e64697425,0x3233752e64646109\n"
".quad 0x202c303172250920,0x367225202c397225,0x61702e646c090a3b,0x203233752e6d6172\n"
".quad 0x5b202c3131722509,0x6170616475635f5f,0x6732325a5f5f6d72,0x5365746172656e65\n"
".quad 0x4b6d757274636570,0x6636506c656e7265,0x5f30533274616f6c,0x6965685f66666a6a\n"
".quad 0x6c090a3b5d746867,0x2e6d617261702e64,0x3172250920323375,0x75635f5f5b202c32\n"
".quad 0x5f5f6d7261706164,0x72656e656732325a,0x7463657053657461,0x656e72654b6d7572\n"
".quad 0x74616f6c6636506c,0x66666a6a5f305332,0x3b5d68746469775f,0x746c2e746573090a\n"
".quad 0x3233752e3233752e,0x202c333172250920,0x317225202c387225,0x2e67656e090a3b32\n"
".quad 0x3172250920323373,0x3b33317225202c34,0x746c2e746573090a,0x3233752e3233752e\n"
".quad 0x202c353172250920,0x7225202c30317225,0x67656e090a3b3131,0x722509203233732e\n"
".quad 0x35317225202c3631,0x622e646e61090a3b,0x3731722509203233,0x202c34317225202c\n"
".quad 0x6d090a3b36317225,0x09203233752e766f,0x3b30202c38317225,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x37317225202c3170,0x0a3b38317225202c,0x7262203170254009\n"
".quad 0x345f744c24092061,0x0a3b34373837345f,0x363109636f6c2e09,0x6d090a3009393809\n"
".quad 0x33752e6f6c2e6c75,0x2c39317225092032,0x25202c3031722520,0x6461090a3b323172\n"
".quad 0x2509203233752e64,0x387225202c303272,0x0a3b39317225202c,0x2e6f6c2e6c756d09\n"
".quad 0x3272250920323375,0x2c30327225202c31,0x747663090a3b3820,0x3233752e3436752e\n"
".quad 0x202c316472250920,0x6c090a3b31327225,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x72656e656732325a,0x7463657053657461\n"
".quad 0x656e72654b6d7572,0x74616f6c6636506c,0x66666a6a5f305332,0x61090a3b5d30685f\n"
".quad 0x09203436752e6464,0x7225202c33647225,0x32647225202c3164,0x6c672e646c090a3b\n"
".quad 0x2e32762e6c61626f,0x66257b0920323366,0x202c7d3266252c31,0x5d302b336472255b\n"
".quad 0x09636f6c2e090a3b,0x0a30093039093631,0x3233752e62757309,0x202c323272250920\n"
".quad 0x7225202c31317225,0x627573090a3b3031,0x722509203233752e,0x32327225202c3332\n"
".quad 0x756d090a3b31202c,0x3233752e6f6c2e6c,0x202c343272250920,0x7225202c33327225\n"
".quad 0x646461090a3b3231,0x722509203233752e,0x2c387225202c3532,0x090a3b3432722520\n"
".quad 0x752e6f6c2e6c756d,0x3632722509203233,0x202c35327225202c,0x2e747663090a3b38\n"
".quad 0x203233752e343675,0x25202c3464722509,0x6461090a3b363272,0x2509203436752e64\n"
".quad 0x647225202c356472,0x3b32647225202c34,0x6f6c672e646c090a,0x662e32762e6c6162\n"
".quad 0x3366257b09203233,0x5b202c7d3466252c,0x3b5d302b35647225,0x3109636f6c2e090a\n"
".quad 0x3009343530310938,0x6e722e747663090a,0x3233752e3233662e,0x25202c3566250920\n"
".quad 0x747663090a3b3872,0x2e3233662e6e722e,0x3666250920323375,0x0a3b30317225202c\n"
".quad 0x3233662e766f6d09,0x30202c3766250920,0x6466303934303466,0x0920202020203b62\n"
".quad 0x3134312e33202f2f,0x2e6c756d090a3935,0x3866250920323366,0x25202c356625202c\n"
".quad 0x766f6d090a3b3766,0x662509203233662e,0x6330346630202c39,0x20203b6264663039\n"
".quad 0x36202f2f09202020,0x090a39313338322e,0x203233662e6c756d,0x25202c3031662509\n"
".quad 0x3b396625202c3666,0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c31316625\n"
".quad 0x726170616475635f,0x656732325a5f5f6d,0x705365746172656e,0x654b6d7572746365\n"
".quad 0x6c6636506c656e72,0x6a5f30533274616f,0x637461705f66666a,0x0a3b5d657a695368\n"
".quad 0x2e6e722e76696409,0x3166250920323366,0x202c386625202c32,0x64090a3b31316625\n"
".quad 0x33662e6e722e7669,0x2c33316625092032,0x25202c3031662520,0x756d090a3b313166\n"
".quad 0x2509203233662e6c,0x316625202c343166,0x3b32316625202c32,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x33316625202c3531,0x202c33316625202c,0x73090a3b34316625\n"
".quad 0x662e6e722e747271,0x3631662509203233,0x0a3b35316625202c,0x3233662e766f6d09\n"
".quad 0x202c373166250920,0x3566633131346630,0x09202020203b3363,0x0a31382e39202f2f\n"
".quad 0x3233662e6c756d09,0x202c383166250920,0x6625202c36316625,0x727173090a3b3731\n"
".quad 0x3233662e6e722e74,0x202c393166250920,0x6c090a3b38316625,0x2e6d617261702e64\n"
".quad 0x3266250920323366,0x75635f5f5b202c30,0x5f5f6d7261706164,0x72656e656732325a\n"
".quad 0x7463657053657461,0x656e72654b6d7572,0x74616f6c6636506c,0x66666a6a5f305332\n"
".quad 0x756d090a3b5d745f,0x2509203233662e6c,0x326625202c313266,0x3b39316625202c30\n"
".quad 0x33662e736261090a,0x2c32326625092032,0x090a3b3132662520,0x203233662e766f6d\n"
".quad 0x30202c3332662509,0x3030303038663766,0x2f09202020203b30,0x46302e312828202f\n"
".quad 0x2946302e30282f29,0x2e70746573090a29,0x09203233662e7165,0x326625202c327025\n"
".quad 0x3b33326625202c32,0x732e706c6573090a,0x3732722509203233,0x202c30202c31202c\n"
".quad 0x6c2e090a3b327025,0x373109383109636f,0x656e090a30093230,0x2509203233662e67\n"
".quad 0x326625202c343266,0x2e766f6d090a3b31,0x3272250920323373,0x73090a3b30202c38\n"
".quad 0x732e656e2e707465,0x2c33702509203233,0x25202c3732722520,0x2140090a3b383272\n"
".quad 0x2061726220337025,0x345f345f744c2409,0x2e090a3b36383338,0x3109383109636f6c\n"
".quad 0x61090a3009333037,0x33662e6e722e6464,0x2c35326625092032,0x25202c3132662520\n"
".quad 0x6f6d090a3b343266,0x2509203436752e76,0x635f5f202c366472,0x32695f7472616475\n"
".quad 0x090a3b665f69706f,0x203436752e766f6d,0x5f202c3764722509,0x5f5f5f616475635f\n"
".quad 0x7365725f61647563,0x383832335f746c75,0x752e617262090a3b,0x57444c240920696e\n"
".quad 0x695f5f5f69646e65,0x38315f66666e6973,0x4c240a3b33315f31,0x383338345f345f74\n"
".quad 0x2e766f6d090a3a36,0x3266250920323366,0x3337346630202c36,0x20203b3030376162\n"
".quad 0x3834202f2f092020,0x746573090a393330,0x3233662e74672e70,0x25202c3470250920\n"
".quad 0x326625202c323266,0x70252140090a3b36,0x2409206172622034,0x3838345f345f744c\n"
".quad 0x6f6c2e090a3b3839,0x3933310938310963,0x766f6d090a300935,0x722509203436752e\n"
".quad 0x75635f5f202c3664,0x6f32695f74726164,0x6d090a3b665f6970,0x09203233622e766f\n"
".quad 0x6625202c39327225,0x6f6c2e090a3b3132,0x3933310938310963,0x646e61090a300936\n"
".quad 0x722509203233622e,0x39327225202c3033,0x34373431322d202c,0x090a3b3834363338\n"
".quad 0x203233732e766f6d,0x25202c3133722509,0x6c2e090a3b303372,0x343209383109636f\n"
".quad 0x2e766f6d090a3009,0x6472250920343673,0x3b36647225202c38,0x36752e766f6d090a\n"
".quad 0x2c39647225092034,0x5f616475635f5f20,0x725f616475635f5f,0x32335f746c757365\n"
".quad 0x6c6873090a3b3838,0x722509203233622e,0x39327225202c3233,0x726f090a3b38202c\n"
".quad 0x722509203233622e,0x32337225202c3333,0x34373431322d202c,0x090a3b3834363338\n"
".quad 0x203233732e766f6d,0x30202c3433722509,0x752e766f6d090a3b,0x3533722509203233\n"
".quad 0x744c240a3b30202c,0x32323939345f345f,0x676172702e090a3a,0x6e756f6e2220616d\n"
".quad 0x200a3b226c6c6f72,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x7473656e202c3432,0x7470656420676e69,0x7469202c31203a68,0x736e6f6974617265\n"
".quad 0x6f6c2e090a36203a,0x3134310938310963,0x2e646c090a300930,0x33752e74736e6f63\n"
".quad 0x2c36337225092032,0x302b386472255b20,0x2e6c756d090a3b5d,0x09203233752e6f6c\n"
".quad 0x7225202c37337225,0x33337225202c3633,0x752e646461090a3b,0x3833722509203233\n"
".quad 0x202c37337225202c,0x2e090a3b35337225,0x3109383109636f6c,0x73090a3009313134\n"
".quad 0x33752e74672e7465,0x2509203233752e32,0x337225202c393372,0x3b38337225202c37\n"
".quad 0x33732e67656e090a,0x2c30347225092032,0x090a3b3933722520,0x752e69682e6c756d\n"
".quad 0x3134722509203233,0x202c36337225202c,0x61090a3b33337225,0x09203233752e6464\n"
".quad 0x7225202c35337225,0x31347225202c3034,0x09636f6c2e090a3b,0x0932313431093831\n"
".quad 0x6f6c2e7473090a30,0x203233752e6c6163,0x302b396472255b09,0x3b38337225202c5d\n"
".quad 0x33732e646461090a,0x2c34337225092032,0x31202c3433722520,0x752e646461090a3b\n"
".quad 0x3964722509203436,0x202c39647225202c,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x2c38647225202c38,0x766f6d090a3b3420,0x722509203233752e,0x090a3b36202c3234\n"
".quad 0x2e656e2e70746573,0x3570250920323373,0x202c34337225202c,0x40090a3b32347225\n"
".quad 0x2061726220357025,0x345f345f744c2409,0x2e090a3b32323939,0x3109383109636f6c\n"
".quad 0x6d090a3009343134,0x09203436752e766f,0x5f5f202c37647225,0x635f5f5f61647563\n"
".quad 0x757365725f616475,0x3b383832335f746c,0x636f6c2e7473090a,0x09203233752e6c61\n"
".quad 0x5f616475635f5f5b,0x725f616475635f5f,0x32335f746c757365,0x202c5d34322b3838\n"
".quad 0x2e090a3b35337225,0x3109383109636f6c,0x73090a3009393134,0x09203233622e6c68\n"
".quad 0x7225202c33347225,0x090a3b31202c3932,0x203233752e726873,0x25202c3434722509\n"
".quad 0x3b3432202c333472,0x33752e627573090a,0x2c35347225092032,0x31202c3434722520\n"
".quad 0x726873090a3b3832,0x722509203233752e,0x35347225202c3634,0x6f6d090a3b35202c\n"
".quad 0x2509203233732e76,0x0a3b34202c373472,0x3233732e62757309,0x202c383472250920\n"
".quad 0x7225202c37347225,0x747663090a3b3634,0x3233732e3436732e,0x2c30316472250920\n"
".quad 0x090a3b3834722520,0x656469772e6c756d,0x722509203233732e,0x347225202c313164\n"
".quad 0x61090a3b34202c38,0x09203436752e6464,0x25202c3231647225,0x647225202c376472\n"
".quad 0x2e646c090a3b3131,0x33752e6c61636f6c,0x2c35337225092032,0x2b32316472255b20\n"
".quad 0x6f6c2e090a3b5d38,0x3234310938310963,0x2e646c090a300930,0x33752e6c61636f6c\n"
".quad 0x2c39347225092032,0x2b32316472255b20,0x646e61090a3b5d34,0x722509203233622e\n"
".quad 0x35347225202c3035,0x6d090a3b3133202c,0x09203233752e766f,0x3b30202c31357225\n"
".quad 0x652e70746573090a,0x2509203233752e71,0x30357225202c3670,0x0a3b31357225202c\n"
".quad 0x7262203670254009,0x345f744c24092061,0x0a3b34333430355f,0x383109636f6c2e09\n"
".quad 0x0a30093332343109,0x3233732e766f6d09,0x202c323572250920,0x627573090a3b3233\n"
".quad 0x722509203233732e,0x32357225202c3335,0x0a3b30357225202c,0x3233752e72687309\n"
".quad 0x202c343572250920,0x7225202c39347225,0x6c6873090a3b3335,0x722509203233622e\n"
".quad 0x35337225202c3535,0x0a3b30357225202c,0x3233752e64646109,0x202c353372250920\n"
".quad 0x7225202c34357225,0x6f6c2e090a3b3535,0x3234310938310963,0x2e646c090a300934\n"
".quad 0x33752e6c61636f6c,0x2c36357225092032,0x2b32316472255b20,0x726873090a3b5d30\n"
".quad 0x722509203233752e,0x36357225202c3735,0x0a3b33357225202c,0x3233622e6c687309\n"
".quad 0x202c383572250920,0x7225202c39347225,0x646461090a3b3035,0x722509203233752e\n"
".quad 0x37357225202c3934,0x0a3b38357225202c,0x30355f345f744c24,0x6c2e090a3a343334\n"
".quad 0x343109383109636f,0x6873090a30093632,0x2509203233752e72,0x337225202c343372\n"
".quad 0x090a3b3033202c35,0x09383109636f6c2e,0x090a300938323431,0x203233752e726873\n"
".quad 0x25202c3935722509,0x3b3033202c393472,0x33622e6c6873090a,0x2c30367225092032\n"
".quad 0x32202c3533722520,0x752e646461090a3b,0x3533722509203233,0x202c39357225202c\n"
".quad 0x2e090a3b30367225,0x3109383109636f6c,0x73090a3009393234,0x09203233622e6c68\n"
".quad 0x7225202c39347225,0x090a3b32202c3934,0x203233752e766f6d,0x30202c3136722509\n"
".quad 0x2e70746573090a3b,0x09203233752e7165,0x347225202c377025,0x3b31367225202c39\n"
".quad 0x622037702540090a,0x5f744c2409206172,0x3b32303231355f34,0x3109636f6c2e090a\n"
".quad 0x3009303334310938,0x33752e646461090a,0x2c32367225092032,0x31202c3533722520\n"
".quad 0x752e766f6d090a3b,0x3336722509203233,0x34373431322d202c,0x090a3b3834363338\n"
".quad 0x752e74672e746573,0x09203233752e3233,0x7225202c34367225,0x33367225202c3236\n"
".quad 0x732e67656e090a3b,0x3536722509203233,0x0a3b34367225202c,0x696e752e61726209\n"
".quad 0x5f345f744c240920,0x240a3b3634393035,0x3231355f345f744c,0x766f6d090a3a3230\n"
".quad 0x722509203233752e,0x3431322d202c3636,0x3b38343633383437,0x74672e746573090a\n"
".quad 0x3233752e3233752e,0x202c373672250920,0x7225202c35337225,0x67656e090a3b3636\n"
".quad 0x722509203233732e,0x37367225202c3536,0x5f345f744c240a3b,0x090a3a3634393035\n"
".quad 0x09383109636f6c2e,0x090a300931333431,0x203233752e646461,0x25202c3836722509\n"
".quad 0x367225202c343372,0x636f6c2e090a3b35,0x3033343109383109,0x2e67656e090a3009\n"
".quad 0x3672250920323373,0x3b38367225202c39,0x33752e766f6d090a,0x2c30377225092032\n"
".quad 0x746573090a3b3020,0x3233752e656e2e70,0x25202c3870250920,0x377225202c303372\n"
".quad 0x706c6573090a3b30,0x722509203233732e,0x39367225202c3433,0x202c38367225202c\n"
".quad 0x6f6d090a3b387025,0x2509203233752e76,0x0a3b30202c313772,0x71652e7074657309\n"
".quad 0x702509203233752e,0x2c35367225202c39,0x090a3b3137722520,0x6172622039702540\n"
".quad 0x5f345f744c240920,0x090a3b3835343135,0x09383109636f6c2e,0x090a300936333431\n"
".quad 0x203233732e67656e,0x25202c3934722509,0x6c2e090a3b393472,0x343109383109636f\n"
".quad 0x6f6d090a30093833,0x2509203233752e76,0x0a3b30202c323772,0x2e71652e74657309\n"
".quad 0x203233752e323375,0x25202c3337722509,0x377225202c393472,0x2e67656e090a3b32\n"
".quad 0x3772250920323373,0x3b33377225202c34,0x33622e746f6e090a,0x2c35377225092032\n"
".quad 0x090a3b3533722520,0x203233752e646461,0x25202c3533722509,0x377225202c343772\n"
".quad 0x636f6c2e090a3b35,0x3933343109383109,0x2e726f78090a3009,0x3372250920323362\n"
".quad 0x2c30337225202c31,0x3834373431322d20,0x4c240a3b38343633,0x353431355f345f74\n"
".quad 0x636f6c2e090a3a38,0x3134343109383109,0x2e766f6d090a3009,0x3772250920323373\n"
".quad 0x3b34337225202c36,0x33752e766f6d090a,0x2c37377225092032,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x202c303170250920,0x7225202c35337225,0x702540090a3b3737\n"
".quad 0x0920617262203031,0x30375f345f744c24,0x6f6d090a3b343139,0x2509203233752e76\n"
".quad 0x0a3b30202c383772,0x32355f345f744c24,0x2f2f200a3a323834,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x343120656e696c20,0x7473656e202c3134,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x6f6c2e090a6e776f,0x3434310938310963,0x726873090a300935,0x722509203233752e\n"
".quad 0x39347225202c3937,0x73090a3b3133202c,0x09203233622e6c68,0x7225202c30387225\n"
".quad 0x090a3b31202c3533,0x203233752e646461,0x25202c3533722509,0x387225202c393772\n"
".quad 0x636f6c2e090a3b30,0x3634343109383109,0x2e6c6873090a3009,0x3472250920323362\n"
".quad 0x2c39347225202c39,0x6f6c2e090a3b3120,0x3434310938310963,0x627573090a300937\n"
".quad 0x722509203233752e,0x38377225202c3837,0x6f6d090a3b31202c,0x2509203233752e76\n"
".quad 0x0a3b30202c313872,0x74672e7074657309,0x702509203233732e,0x35337225202c3131\n"
".quad 0x0a3b31387225202c,0x6220313170254009,0x5f744c2409206172,0x3b32383432355f34\n"
".quad 0x6e752e617262090a,0x345f744c24092069,0x0a3b30373931355f,0x30375f345f744c24\n"
".quad 0x6f6d090a3a343139,0x2509203233752e76,0x0a3b30202c383772,0x31355f345f744c24\n"
".quad 0x6c2e090a3a303739,0x343109383109636f,0x756d090a30093934,0x3233752e6f6c2e6c\n"
".quad 0x202c393472250920,0x392d202c35337225,0x3037383730373132,0x09636f6c2e090a3b\n"
".quad 0x0930353431093831,0x752e766f6d090a30,0x3238722509203233,0x30373132392d202c\n"
".quad 0x6d090a3b30373837,0x33752e69682e6c75,0x2c35337225092032,0x25202c3533722520\n"
".quad 0x6f6d090a3b323872,0x2509203233752e76,0x0a3b30202c333872,0x656c2e7074657309\n"
".quad 0x702509203233732e,0x35337225202c3231,0x0a3b33387225202c,0x6220323170254009\n"
".quad 0x5f744c2409206172,0x3b34393932355f34,0x3109636f6c2e090a,0x3009323534310938\n"
".quad 0x33752e726873090a,0x2c34387225092032,0x33202c3934722520,0x2e6c6873090a3b31\n"
".quad 0x3872250920323362,0x2c35337225202c35,0x646461090a3b3120,0x722509203233752e\n"
".quad 0x34387225202c3533,0x0a3b35387225202c,0x383109636f6c2e09,0x0a30093335343109\n"
".quad 0x3233622e6c687309,0x202c393472250920,0x3b31202c39347225,0x3109636f6c2e090a\n"
".quad 0x3009343534310938,0x33752e627573090a,0x2c38377225092032,0x31202c3837722520\n"
".quad 0x5f345f744c240a3b,0x090a3a3439393235,0x09383109636f6c2e,0x090a300936353431\n"
".quad 0x203233752e766f6d,0x30202c3638722509,0x6e2e746573090a3b,0x33752e3233752e65\n"
".quad 0x2c37387225092032,0x25202c3934722520,0x656e090a3b363872,0x2509203233732e67\n"
".quad 0x387225202c383872,0x2e646461090a3b37,0x3372250920323375,0x2c38387225202c35\n"
".quad 0x090a3b3533722520,0x09383109636f6c2e,0x090a300938353431,0x203233622e6c6873\n"
".quad 0x25202c3938722509,0x3b3432202c353372,0x33732e766f6d090a,0x2c30397225092032\n"
".quad 0x746573090a3b3020,0x2e3233752e746c2e,0x3972250920323373,0x2c39387225202c31\n"
".quad 0x090a3b3039722520,0x203233732e67656e,0x25202c3239722509,0x6873090a3b313972\n"
".quad 0x2509203233752e72,0x337225202c333972,0x61090a3b38202c35,0x09203233752e6464\n"
".quad 0x7225202c34397225,0x3b363231202c3837,0x33622e6c6873090a,0x2c35397225092032\n"
".quad 0x32202c3439722520,0x2e646461090a3b33,0x3972250920323375,0x2c33397225202c36\n"
".quad 0x090a3b3539722520,0x203233752e646461,0x25202c3739722509,0x397225202c323972\n"
".quad 0x622e726f090a3b36,0x3839722509203233,0x202c31337225202c,0x6d090a3b37397225\n"
".quad 0x09203233622e766f,0x7225202c37326625,0x617262090a3b3839,0x4c240920696e752e\n"
".quad 0x5f5f69646e655744,0x616e7265746e695f,0x315f64616d665f6c,0x240a3b34315f3138\n"
".quad 0x3838345f345f744c,0x6f6c2e090a3a3839,0x3634310938310963,0x766f6d090a300930\n"
".quad 0x662509203233662e,0x66336630202c3832,0x203b333839663232,0x30202f2f09202020\n"
".quad 0x090a32363633362e,0x203233662e6c756d,0x25202c3932662509,0x326625202c313266\n"
".quad 0x2e747663090a3b38,0x2e3233732e696e72,0x3972250920323366,0x3b39326625202c39\n"
".quad 0x3109636f6c2e090a,0x3009333731310938,0x6e722e747663090a,0x3233732e3233662e\n"
".quad 0x202c303366250920,0x6e090a3b39397225,0x09203233662e6765,0x6625202c31336625\n"
".quad 0x766f6d090a3b3033,0x662509203233662e,0x66336630202c3233,0x203b303030303963\n"
".quad 0x31202f2f09202020,0x090a31333037352e,0x662e6e722e616d66,0x3333662509203233\n"
".quad 0x202c31336625202c,0x6625202c32336625,0x6f6c2e090a3b3132,0x3734310938310963\n"
".quad 0x766f6d090a300931,0x722509203233732e,0x39397225202c3637,0x09636f6c2e090a3b\n"
".quad 0x0932373431093831,0x662e766f6d090a30,0x3433662509203233,0x353865326630202c\n"
".quad 0x2020203b39303361,0x302e36202f2f0920,0x0a31312d65313737,0x3233662e766f6d09\n"
".quad 0x202c353366250920,0x6161646639336630,0x09202020203b3032,0x3030302e30202f2f\n"
".quad 0x090a373238333834,0x662e6e722e616d66,0x3633662509203233,0x202c31336625202c\n"
".quad 0x6625202c35336625,0x616d66090a3b3333,0x203233662e6e722e,0x25202c3732662509\n"
".quad 0x336625202c313366,0x3b36336625202c34,0x36752e766f6d090a,0x2c36647225092034\n"
".quad 0x72616475635f5f20,0x5f69706f32695f74,0x2e766f6d090a3b66,0x6472250920343675\n"
".quad 0x6475635f5f202c37,0x616475635f5f5f61,0x5f746c757365725f,0x4c240a3b38383233\n"
".quad 0x5f5f69646e655744,0x616e7265746e695f,0x315f64616d665f6c,0x090a3a34315f3138\n"
".quad 0x09383109636f6c2e,0x090a300935303731,0x203233732e646461,0x202c303031722509\n"
".quad 0x3b31202c36377225,0x33662e766f6d090a,0x2c37336625092032,0x090a3b3732662520\n"
".quad 0x203233662e6c756d,0x25202c3833662509,0x336625202c373366,0x2e646e61090a3b37\n"
".quad 0x3172250920323362,0x30317225202c3130,0x6d090a3b31202c30,0x09203233752e766f\n"
".quad 0x30202c3230317225,0x2e70746573090a3b,0x09203233732e7165,0x7225202c33317025\n"
".quad 0x317225202c313031,0x702540090a3b3230,0x0920617262203331,0x33355f345f744c24\n"
".quad 0x6c2e090a3b323637,0x373109383109636f,0x6f6d090a30093930,0x2509203233662e76\n"
".quad 0x336630202c393366,0x3b65633566636337,0x202f2f0920202020,0x6532333334342e32\n"
".quad 0x766f6d090a35302d,0x662509203233662e,0x61626630202c3034,0x203b613136303662\n"
".quad 0x2d202f2f09202020,0x3838333130302e30,0x2e616d66090a3337,0x09203233662e6e72\n"
".quad 0x6625202c31346625,0x38336625202c3933,0x0a3b30346625202c,0x3233662e766f6d09\n"
".quad 0x202c323466250920,0x6161613264336630,0x09202020203b3561,0x3134302e30202f2f\n"
".quad 0x6d66090a36363636,0x3233662e6e722e61,0x202c333466250920,0x6625202c31346625\n"
".quad 0x32346625202c3833,0x662e766f6d090a3b,0x3434662509203233,0x303066626630202c\n"
".quad 0x2020203b30303030,0x2e302d202f2f0920,0x722e616d66090a35,0x2509203233662e6e\n"
".quad 0x346625202c353466,0x2c38336625202c33,0x090a3b3434662520,0x203233662e766f6d\n"
".quad 0x30202c3634662509,0x3030303038663366,0x2f09202020203b30,0x616d66090a31202f\n"
".quad 0x203233662e6e722e,0x25202c3734662509,0x336625202c353466,0x3b36346625202c38\n"
".quad 0x6e752e617262090a,0x345f744c24092069,0x0a3b36303533355f,0x33355f345f744c24\n"
".quad 0x6c2e090a3a323637,0x373109383109636f,0x6f6d090a30093131,0x2509203233662e76\n"
".quad 0x626630202c383466,0x3b39663161633439,0x202f2f0920202020,0x39313030302e302d\n"
".quad 0x6f6d090a33353135,0x2509203233662e76,0x336630202c393466,0x3b65393338383063\n"
".quad 0x202f2f0920202020,0x3233333830302e30,0x2e616d66090a3631,0x09203233662e6e72\n"
".quad 0x6625202c30356625,0x38336625202c3834,0x0a3b39346625202c,0x3233662e766f6d09\n"
".quad 0x202c313566250920,0x6161613265626630,0x09202020203b3361,0x36312e302d202f2f\n"
".quad 0x6d66090a37363636,0x3233662e6e722e61,0x202c323566250920,0x6625202c30356625\n"
".quad 0x31356625202c3833,0x662e6c756d090a3b,0x3335662509203233,0x202c38336625202c\n"
".quad 0x66090a3b32356625,0x33662e6e722e616d,0x2c37346625092032,0x25202c3335662520\n"
".quad 0x336625202c373366,0x345f744c240a3b37,0x0a3a36303533355f,0x383109636f6c2e09\n"
".quad 0x0a30093331373109,0x3233662e67656e09,0x202c343566250920,0x61090a3b37346625\n"
".quad 0x09203233622e646e,0x25202c3330317225,0x3b32202c30303172,0x33732e766f6d090a\n"
".quad 0x3430317225092032,0x6573090a3b30202c,0x33732e656e2e7074,0x2c34317025092032\n"
".quad 0x202c333031722520,0x090a3b3430317225,0x3233662e706c6573,0x202c373466250920\n"
".quad 0x6625202c34356625,0x34317025202c3734,0x09636f6c2e090a3b,0x0936313731093831\n"
".quad 0x662e766f6d090a30,0x3532662509203233,0x0a3b37346625202c,0x69646e6557444c24\n"
".quad 0x666e6973695f5f5f,0x33315f3138315f66,0x09636f6c2e090a3a,0x0938333631093831\n"
".quad 0x2e706c6573090a30,0x3172250920323373,0x30202c31202c3530,0x090a3b337025202c\n"
".quad 0x203233662e766f6d,0x30202c3535662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x746573090a30202f,0x2e3233752e71652e,0x3172250920323366,0x31326625202c3630\n"
".quad 0x0a3b35356625202c,0x3233732e67656e09,0x2c37303172250920,0x0a3b363031722520\n"
".quad 0x203233622e726f09,0x202c383031722509,0x25202c3530317225,0x6d090a3b37303172\n"
".quad 0x09203233752e766f,0x30202c3930317225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c35317025,0x317225202c383031,0x702540090a3b3930,0x0920617262203531\n"
".quad 0x34355f345f744c24,0x6c2e090a3b383130,0x363109383109636f,0x6f6d090a30093933\n"
".quad 0x2509203233662e76,0x306630202c363566,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x722e6c756d090a30,0x2509203233662e6e,0x326625202c373566,0x3b36356625202c31\n"
".quad 0x36752e766f6d090a,0x3331647225092034,0x616475635f5f202c,0x5f616475635f5f5f\n"
".quad 0x365f746c75736572,0x62090a3b36313130,0x0920696e752e6172,0x69646e6557444c24\n"
".quad 0x666e6973695f5f5f,0x3b395f3138315f66,0x355f345f744c240a,0x6d090a3a38313034\n"
".quad 0x09203233662e766f,0x6630202c38356625,0x3030376162333734,0x2f2f09202020203b\n"
".quad 0x090a393330383420,0x2e74672e70746573,0x3170250920323366,0x2c32326625202c36\n"
".quad 0x090a3b3835662520,0x6220363170252140,0x5f744c2409206172,0x3b30333534355f34\n"
".quad 0x3109636f6c2e090a,0x3009353933310938,0x33622e766f6d090a,0x2c39327225092032\n"
".quad 0x090a3b3132662520,0x09383109636f6c2e,0x090a300936393331,0x203233622e646e61\n"
".quad 0x25202c3033722509,0x31322d202c393272,0x3834363338343734,0x732e766f6d090a3b\n"
".quad 0x3131722509203233,0x3b30337225202c30,0x3109636f6c2e090a,0x090a300934320938\n"
".quad 0x203436732e766f6d,0x202c343164722509,0x6d090a3b36647225,0x09203436752e766f\n"
".quad 0x5f202c3531647225,0x5f5f5f616475635f,0x7365725f61647563,0x313130365f746c75\n"
".quad 0x2e6c6873090a3b36,0x3172250920323362,0x39327225202c3131,0x726f090a3b38202c\n"
".quad 0x722509203233622e,0x31317225202c3333,0x373431322d202c31,0x0a3b383436333834\n"
".quad 0x3233732e766f6d09,0x2c32313172250920,0x766f6d090a3b3020,0x722509203233752e\n"
".quad 0x0a3b30202c333131,0x35355f345f744c24,0x702e090a3a343535,0x6e2220616d676172\n"
".quad 0x226c6c6f726e756f,0x6f6c3c2f2f200a3b,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x6e202c343220656e,0x6420676e69747365,0x2c31203a68747065,0x6974617265746920\n"
".quad 0x090a36203a736e6f,0x09383109636f6c2e,0x090a300930313431,0x74736e6f632e646c\n"
".quad 0x722509203233752e,0x72255b202c343131,0x0a3b5d302b343164,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x31317225202c3531,0x3b33337225202c34,0x33752e646461090a\n"
".quad 0x3631317225092032,0x2c3531317225202c,0x0a3b333131722520,0x383109636f6c2e09\n"
".quad 0x0a30093131343109,0x2e74672e74657309,0x203233752e323375,0x202c373131722509\n"
".quad 0x25202c3531317225,0x6e090a3b36313172,0x09203233732e6765,0x25202c3831317225\n"
".quad 0x6d090a3b37313172,0x33752e69682e6c75,0x3931317225092032,0x2c3431317225202c\n"
".quad 0x090a3b3333722520,0x203233752e646461,0x202c333131722509,0x25202c3831317225\n"
".quad 0x2e090a3b39313172,0x3109383109636f6c,0x73090a3009323134,0x2e6c61636f6c2e74\n"
".quad 0x72255b0920323375,0x202c5d302b353164,0x090a3b3631317225,0x203233732e646461\n"
".quad 0x202c323131722509,0x31202c3231317225,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x3531647225202c35,0x6461090a3b34202c,0x2509203436752e64,0x7225202c34316472\n"
".quad 0x0a3b34202c343164,0x3233752e766f6d09,0x2c30323172250920,0x746573090a3b3620\n"
".quad 0x3233732e656e2e70,0x202c373170250920,0x25202c3231317225,0x40090a3b30323172\n"
".quad 0x6172622037317025,0x5f345f744c240920,0x090a3b3435353535,0x09383109636f6c2e\n"
".quad 0x090a300934313431,0x203436752e766f6d,0x202c333164722509,0x5f5f616475635f5f\n"
".quad 0x65725f616475635f,0x3130365f746c7573,0x2e7473090a3b3631,0x33752e6c61636f6c\n"
".quad 0x75635f5f5b092032,0x6475635f5f5f6164,0x746c757365725f61,0x322b36313130365f\n"
".quad 0x31317225202c5d34,0x636f6c2e090a3b33,0x3931343109383109,0x2e6c6873090a3009\n"
".quad 0x3172250920323362,0x39327225202c3132,0x6873090a3b31202c,0x2509203233752e72\n"
".quad 0x7225202c32323172,0x3b3432202c313231,0x33752e627573090a,0x3332317225092032\n"
".quad 0x2c3232317225202c,0x73090a3b38323120,0x09203233752e7268,0x25202c3432317225\n"
".quad 0x3b35202c33323172,0x33732e766f6d090a,0x3532317225092032,0x7573090a3b34202c\n"
".quad 0x2509203233732e62,0x7225202c36323172,0x317225202c353231,0x747663090a3b3432\n"
".quad 0x3233732e3436732e,0x2c36316472250920,0x0a3b363231722520,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x7225202c37316472,0x0a3b34202c363231,0x3436752e64646109\n"
".quad 0x2c38316472250920,0x202c333164722520,0x090a3b3731647225,0x6c61636f6c2e646c\n"
".quad 0x722509203233752e,0x72255b202c333131,0x0a3b5d382b383164,0x383109636f6c2e09\n"
".quad 0x0a30093032343109,0x61636f6c2e646c09,0x2509203233752e6c,0x255b202c37323172\n"
".quad 0x3b5d342b38316472,0x33622e646e61090a,0x2c30357225092032,0x202c333231722520\n"
".quad 0x766f6d090a3b3133,0x722509203233752e,0x0a3b30202c383231,0x71652e7074657309\n"
".quad 0x702509203233752e,0x30357225202c3831,0x3b3832317225202c,0x203831702540090a\n"
".quad 0x744c240920617262,0x36363036355f345f,0x09636f6c2e090a3b,0x0933323431093831\n"
".quad 0x732e766f6d090a30,0x3231722509203233,0x090a3b3233202c39,0x203233732e627573\n"
".quad 0x202c303331722509,0x25202c3932317225,0x6873090a3b303572,0x2509203233752e72\n"
".quad 0x7225202c31333172,0x317225202c373231,0x6c6873090a3b3033,0x722509203233622e\n"
".quad 0x317225202c323331,0x30357225202c3331,0x752e646461090a3b,0x3131722509203233\n"
".quad 0x3133317225202c33,0x3b3233317225202c,0x3109636f6c2e090a,0x3009343234310938\n"
".quad 0x636f6c2e646c090a,0x09203233752e6c61,0x5b202c3333317225,0x5d302b3831647225\n"
".quad 0x752e726873090a3b,0x3331722509203233,0x3333317225202c34,0x3b3033317225202c\n"
".quad 0x33622e6c6873090a,0x3533317225092032,0x2c3732317225202c,0x090a3b3035722520\n"
".quad 0x203233752e646461,0x202c373231722509,0x25202c3433317225,0x4c240a3b35333172\n"
".quad 0x363036355f345f74,0x636f6c2e090a3a36,0x3632343109383109,0x2e726873090a3009\n"
".quad 0x3172250920323375,0x31317225202c3231,0x090a3b3033202c33,0x09383109636f6c2e\n"
".quad 0x090a300938323431,0x203233752e726873,0x202c363331722509,0x33202c3732317225\n"
".quad 0x2e6c6873090a3b30,0x3172250920323362,0x31317225202c3733,0x61090a3b32202c33\n"
".quad 0x09203233752e6464,0x25202c3331317225,0x7225202c36333172,0x6c2e090a3b373331\n"
".quad 0x343109383109636f,0x6873090a30093932,0x2509203233622e6c,0x7225202c37323172\n"
".quad 0x0a3b32202c373231,0x3233752e766f6d09,0x2c38333172250920,0x746573090a3b3020\n"
".quad 0x3233752e71652e70,0x202c393170250920,0x25202c3732317225,0x40090a3b38333172\n"
".quad 0x6172622039317025,0x5f345f744c240920,0x090a3b3433383635,0x09383109636f6c2e\n"
".quad 0x090a300930333431,0x203233752e646461,0x202c393331722509,0x31202c3331317225\n"
".quad 0x752e766f6d090a3b,0x3431722509203233,0x373431322d202c30,0x0a3b383436333834\n"
".quad 0x2e74672e74657309,0x203233752e323375,0x202c313431722509,0x25202c3933317225\n"
".quad 0x6e090a3b30343172,0x09203233732e6765,0x25202c3234317225,0x62090a3b31343172\n"
".quad 0x0920696e752e6172,0x36355f345f744c24,0x744c240a3b383735,0x34333836355f345f\n"
".quad 0x752e766f6d090a3a,0x3431722509203233,0x373431322d202c33,0x0a3b383436333834\n"
".quad 0x2e74672e74657309,0x203233752e323375,0x202c343431722509,0x25202c3331317225\n"
".quad 0x6e090a3b33343172,0x09203233732e6765,0x25202c3234317225,0x4c240a3b34343172\n"
".quad 0x373536355f345f74,0x636f6c2e090a3a38,0x3133343109383109,0x2e646461090a3009\n"
".quad 0x3172250920323375,0x31317225202c3534,0x3234317225202c32,0x09636f6c2e090a3b\n"
".quad 0x0930333431093831,0x732e67656e090a30,0x3431722509203233,0x3534317225202c36\n"
".quad 0x752e766f6d090a3b,0x3431722509203233,0x73090a3b30202c37,0x752e656e2e707465\n"
".quad 0x3032702509203233,0x202c30337225202c,0x090a3b3734317225,0x3233732e706c6573\n"
".quad 0x2c32313172250920,0x202c363431722520,0x25202c3534317225,0x6f6d090a3b303270\n"
".quad 0x2509203233752e76,0x3b30202c38343172,0x652e70746573090a,0x2509203233752e71\n"
".quad 0x317225202c313270,0x34317225202c3234,0x32702540090a3b38,0x2409206172622031\n"
".quad 0x3037355f345f744c,0x6f6c2e090a3b3039,0x3334310938310963,0x67656e090a300936\n"
".quad 0x722509203233732e,0x317225202c373231,0x6f6c2e090a3b3732,0x3334310938310963\n"
".quad 0x766f6d090a300938,0x722509203233752e,0x0a3b30202c393431,0x2e71652e74657309\n"
".quad 0x203233752e323375,0x202c303531722509,0x25202c3732317225,0x6e090a3b39343172\n"
".quad 0x09203233732e6765,0x25202c3135317225,0x6e090a3b30353172,0x09203233622e746f\n"
".quad 0x25202c3235317225,0x61090a3b33313172,0x09203233752e6464,0x25202c3331317225\n"
".quad 0x7225202c31353172,0x6c2e090a3b323531,0x343109383109636f,0x6f78090a30093933\n"
".quad 0x2509203233622e72,0x7225202c30313172,0x3431322d202c3033,0x3b38343633383437\n"
".quad 0x355f345f744c240a,0x2e090a3a30393037,0x3109383109636f6c,0x6d090a3009313434\n"
".quad 0x09203233732e766f,0x25202c3335317225,0x6d090a3b32313172,0x09203233752e766f\n"
".quad 0x30202c3435317225,0x2e70746573090a3b,0x09203233732e656c,0x7225202c32327025\n"
".quad 0x317225202c333131,0x702540090a3b3435,0x0920617262203232,0x31375f345f744c24\n"
".quad 0x6f6d090a3b303731,0x2509203233752e76,0x3b30202c35353172,0x355f345f744c240a\n"
".quad 0x2f200a3a34313138,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3120656e696c2079\n"
".quad 0x73656e202c313434,0x70656420676e6974,0x65202c31203a6874,0x646574616d697473\n"
".quad 0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e,0x343109383109636f\n"
".quad 0x6873090a30093534,0x2509203233752e72,0x7225202c36353172,0x3b3133202c373231\n"
".quad 0x33622e6c6873090a,0x3735317225092032,0x2c3331317225202c,0x646461090a3b3120\n"
".quad 0x722509203233752e,0x317225202c333131,0x35317225202c3635,0x636f6c2e090a3b37\n"
".quad 0x3634343109383109,0x2e6c6873090a3009,0x3172250920323362,0x32317225202c3732\n"
".quad 0x2e090a3b31202c37,0x3109383109636f6c,0x73090a3009373434,0x09203233752e6275\n"
".quad 0x25202c3535317225,0x3b31202c35353172,0x33752e766f6d090a,0x3835317225092032\n"
".quad 0x6573090a3b30202c,0x33732e74672e7074,0x2c33327025092032,0x202c333131722520\n"
".quad 0x090a3b3835317225,0x7262203332702540,0x345f744c24092061,0x0a3b34313138355f\n"
".quad 0x696e752e61726209,0x5f345f744c240920,0x240a3b3230363735,0x3131375f345f744c\n"
".quad 0x766f6d090a3a3037,0x722509203233752e,0x0a3b30202c353531,0x37355f345f744c24\n"
".quad 0x6c2e090a3a323036,0x343109383109636f,0x756d090a30093934,0x3233752e6f6c2e6c\n"
".quad 0x2c37323172250920,0x202c333131722520,0x383730373132392d,0x6f6c2e090a3b3037\n"
".quad 0x3534310938310963,0x766f6d090a300930,0x722509203233752e,0x32392d202c393531\n"
".quad 0x3b30373837303731,0x69682e6c756d090a,0x722509203233752e,0x317225202c333131\n"
".quad 0x35317225202c3331,0x2e766f6d090a3b39,0x3172250920323375,0x090a3b30202c3036\n"
".quad 0x2e656c2e70746573,0x3270250920323373,0x3331317225202c34,0x3b3036317225202c\n"
".quad 0x203432702540090a,0x744c240920617262,0x36323638355f345f,0x09636f6c2e090a3b\n"
".quad 0x0932353431093831,0x752e726873090a30,0x3631722509203233,0x3732317225202c31\n"
".quad 0x73090a3b3133202c,0x09203233622e6c68,0x25202c3236317225,0x3b31202c33313172\n"
".quad 0x33752e646461090a,0x3331317225092032,0x2c3136317225202c,0x0a3b323631722520\n"
".quad 0x383109636f6c2e09,0x0a30093335343109,0x3233622e6c687309,0x2c37323172250920\n"
".quad 0x202c373231722520,0x636f6c2e090a3b31,0x3435343109383109,0x2e627573090a3009\n"
".quad 0x3172250920323375,0x35317225202c3535,0x4c240a3b31202c35,0x323638355f345f74\n"
".quad 0x636f6c2e090a3a36,0x3635343109383109,0x2e766f6d090a3009,0x3172250920323375\n"
".quad 0x090a3b30202c3336,0x752e656e2e746573,0x09203233752e3233,0x25202c3436317225\n"
".quad 0x7225202c37323172,0x656e090a3b333631,0x2509203233732e67,0x7225202c35363172\n"
".quad 0x6461090a3b343631,0x2509203233752e64,0x7225202c33313172,0x317225202c353631\n"
".quad 0x6f6c2e090a3b3331,0x3534310938310963,0x6c6873090a300938,0x722509203233622e\n"
".quad 0x317225202c363631,0x0a3b3432202c3331,0x3233732e766f6d09,0x2c37363172250920\n"
".quad 0x746573090a3b3020,0x2e3233752e746c2e,0x3172250920323373,0x36317225202c3836\n"
".quad 0x3736317225202c36,0x732e67656e090a3b,0x3631722509203233,0x3836317225202c39\n"
".quad 0x752e726873090a3b,0x3731722509203233,0x3331317225202c30,0x6461090a3b38202c\n"
".quad 0x2509203233752e64,0x7225202c31373172,0x363231202c353531,0x622e6c6873090a3b\n"
".quad 0x3731722509203233,0x3137317225202c32,0x61090a3b3332202c,0x09203233752e6464\n"
".quad 0x25202c3337317225,0x7225202c30373172,0x6461090a3b323731,0x2509203233752e64\n"
".quad 0x7225202c34373172,0x317225202c393631,0x2e726f090a3b3337,0x3172250920323362\n"
".quad 0x31317225202c3537,0x3437317225202c30,0x622e766f6d090a3b,0x3935662509203233\n"
".quad 0x3b3537317225202c,0x6e752e617262090a,0x6557444c24092069,0x6e695f5f5f69646e\n"
".quad 0x665f6c616e726574,0x5f3138315f64616d,0x5f744c240a3b3031,0x3a30333534355f34\n"
".quad 0x3109636f6c2e090a,0x3009303634310938,0x33662e766f6d090a,0x2c30366625092032\n"
".quad 0x6632326633663020,0x202020203b333839,0x33362e30202f2f09,0x6c756d090a323636\n"
".quad 0x662509203233662e,0x31326625202c3136,0x0a3b30366625202c,0x696e722e74766309\n"
".quad 0x3233662e3233732e,0x2c36373172250920,0x090a3b3136662520,0x09383109636f6c2e\n"
".quad 0x090a300933373131,0x662e6e722e747663,0x09203233732e3233,0x7225202c32366625\n"
".quad 0x656e090a3b363731,0x2509203233662e67,0x366625202c333666,0x2e766f6d090a3b32\n"
".quad 0x3666250920323366,0x6366336630202c34,0x20203b3030303039,0x2e31202f2f092020\n"
".quad 0x66090a3133303735,0x33662e6e722e616d,0x2c35366625092032,0x25202c3336662520\n"
".quad 0x326625202c343666,0x636f6c2e090a3b31,0x3137343109383109,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x37317225202c3335,0x636f6c2e090a3b36,0x3237343109383109\n"
".quad 0x2e766f6d090a3009,0x3666250920323366,0x3865326630202c36,0x20203b3930336135\n"
".quad 0x2e36202f2f092020,0x31312d6531373730,0x33662e766f6d090a,0x2c37366625092032\n"
".quad 0x6164663933663020,0x202020203b303261,0x30302e30202f2f09,0x0a37323833383430\n"
".quad 0x2e6e722e616d6609,0x3666250920323366,0x2c33366625202c38,0x25202c3736662520\n"
".quad 0x6d66090a3b353666,0x3233662e6e722e61,0x202c393566250920,0x6625202c33366625\n"
".quad 0x38366625202c3636,0x752e766f6d090a3b,0x3164722509203436,0x6475635f5f202c33\n"
".quad 0x616475635f5f5f61,0x5f746c757365725f,0x240a3b3631313036,0x5f69646e6557444c\n"
".quad 0x6e7265746e695f5f,0x5f64616d665f6c61,0x0a3a30315f313831,0x383109636f6c2e09\n"
".quad 0x0a30093134363109,0x3233662e766f6d09,0x202c393666250920,0x6d090a3b39356625\n"
".quad 0x09203233662e6c75,0x6625202c30376625,0x39366625202c3936,0x622e646e61090a3b\n"
".quad 0x3731722509203233,0x3335317225202c37,0x6f6d090a3b31202c,0x2509203233752e76\n"
".quad 0x3b30202c38373172,0x652e70746573090a,0x2509203233732e71,0x317225202c353270\n"
".quad 0x37317225202c3737,0x32702540090a3b38,0x2409206172622035,0x3339355f345f744c\n"
".quad 0x6f6c2e090a3b3439,0x3436310938310963,0x766f6d090a300934,0x662509203233662e\n"
".quad 0x37336630202c3137,0x203b656335666363,0x32202f2f09202020,0x2d6532333334342e\n"
".quad 0x2e766f6d090a3530,0x3766250920323366,0x6261626630202c32,0x20203b6131363036\n"
".quad 0x302d202f2f092020,0x373838333130302e,0x722e616d66090a33,0x2509203233662e6e\n"
".quad 0x376625202c333766,0x2c30376625202c31,0x090a3b3237662520,0x203233662e766f6d\n"
".quad 0x30202c3437662509,0x6161616132643366,0x2f09202020203b35,0x363134302e30202f\n"
".quad 0x616d66090a363636,0x203233662e6e722e,0x25202c3537662509,0x376625202c333766\n"
".quad 0x3b34376625202c30,0x33662e766f6d090a,0x2c36376625092032,0x3030306662663020\n"
".quad 0x202020203b303030,0x352e302d202f2f09,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x35376625202c3737,0x202c30376625202c,0x6d090a3b36376625,0x09203233662e766f\n"
".quad 0x6630202c38376625,0x3030303030386633,0x2f2f09202020203b,0x2e616d66090a3120\n"
".quad 0x09203233662e6e72,0x6625202c39376625,0x30376625202c3737,0x0a3b38376625202c\n"
".quad 0x696e752e61726209,0x5f345f744c240920,0x240a3b3833313935,0x3339355f345f744c\n"
".quad 0x6f6c2e090a3a3439,0x3436310938310963,0x766f6d090a300936,0x662509203233662e\n"
".quad 0x39626630202c3038,0x203b396631616334,0x2d202f2f09202020,0x3539313030302e30\n"
".quad 0x766f6d090a333531,0x662509203233662e,0x63336630202c3138,0x203b653933383830\n"
".quad 0x30202f2f09202020,0x313233333830302e,0x722e616d66090a36,0x2509203233662e6e\n"
".quad 0x386625202c323866,0x2c30376625202c30,0x090a3b3138662520,0x203233662e766f6d\n"
".quad 0x30202c3338662509,0x6161616132656266,0x2f09202020203b33,0x3636312e302d202f\n"
".quad 0x616d66090a373636,0x203233662e6e722e,0x25202c3438662509,0x376625202c323866\n"
".quad 0x3b33386625202c30,0x33662e6c756d090a,0x2c35386625092032,0x25202c3037662520\n"
".quad 0x6d66090a3b343866,0x3233662e6e722e61,0x202c393766250920,0x6625202c35386625\n"
".quad 0x39366625202c3936,0x5f345f744c240a3b,0x090a3a3833313935,0x09383109636f6c2e\n"
".quad 0x090a300938343631,0x203233662e67656e,0x25202c3638662509,0x6e61090a3b393766\n"
".quad 0x2509203233622e64,0x7225202c39373172,0x0a3b32202c333531,0x3233732e766f6d09\n"
".quad 0x2c30383172250920,0x746573090a3b3020,0x3233732e656e2e70,0x202c363270250920\n"
".quad 0x25202c3937317225,0x73090a3b30383172,0x203233662e706c65,0x25202c3937662509\n"
".quad 0x376625202c363866,0x3b36327025202c39,0x3109636f6c2e090a,0x3009313536310938\n"
".quad 0x33662e766f6d090a,0x2c37356625092032,0x240a3b3937662520,0x5f69646e6557444c\n"
".quad 0x66666e6973695f5f,0x0a3a395f3138315f,0x363109636f6c2e09,0x6d090a3009323909\n"
".quad 0x09203233662e6c75,0x6625202c37386625,0x3b326625202c3735,0x33662e6c756d090a\n"
".quad 0x2c38386625092032,0x6625202c31662520,0x627573090a3b3532,0x662509203233662e\n"
".quad 0x38386625202c3938,0x0a3b37386625202c,0x3233662e6c756d09,0x202c303966250920\n"
".quad 0x6625202c35326625,0x2e616d66090a3b32,0x09203233662e6e72,0x6625202c31396625\n"
".quad 0x2c37356625202c31,0x090a3b3039662520,0x09383109636f6c2e,0x090a300932303731\n"
".quad 0x203233662e736261,0x25202c3239662509,0x6f6d090a3b343266,0x2509203233662e76\n"
".quad 0x376630202c333966,0x3b30303030303866,0x202f2f0920202020,0x2f2946302e312828\n"
".quad 0x0a292946302e3028,0x71652e7074657309,0x702509203233662e,0x32396625202c3732\n"
".quad 0x0a3b33396625202c,0x2037327025214009,0x744c240920617262,0x30353639355f345f\n"
".quad 0x09636f6c2e090a3b,0x0933303731093831,0x662e67656e090a30,0x3439662509203233\n"
".quad 0x0a3b34326625202c,0x2e6e722e64646109,0x3266250920323366,0x2c34326625202c35\n"
".quad 0x090a3b3439662520,0x20696e752e617262,0x646e6557444c2409,0x6e6973695f5f5f69\n"
".quad 0x355f3138315f6666,0x5f345f744c240a3b,0x090a3a3035363935,0x203233662e766f6d\n"
".quad 0x30202c3539662509,0x3037616233373466,0x2f09202020203b30,0x0a3933303834202f\n"
".quad 0x74672e7074657309,0x702509203233662e,0x32396625202c3832,0x0a3b35396625202c\n"
".quad 0x2038327025214009,0x744c240920617262,0x32363130365f345f,0x09636f6c2e090a3b\n"
".quad 0x0936393331093831,0x622e766f6d090a30,0x3831722509203233,0x3b34326625202c31\n"
".quad 0x33622e646e61090a,0x3238317225092032,0x2c3138317225202c,0x3834373431322d20\n"
".quad 0x6d090a3b38343633,0x09203233732e766f,0x7225202c31337225,0x6c2e090a3b323831\n"
".quad 0x343209383109636f,0x2e6c6873090a3009,0x3172250920323362,0x38317225202c3338\n"
".quad 0x6d090a3b38202c31,0x09203436732e766f,0x7225202c38647225,0x766f6d090a3b3664\n"
".quad 0x722509203436752e,0x75635f5f202c3964,0x6475635f5f5f6164,0x746c757365725f61\n"
".quad 0x090a3b383832335f,0x09203233622e726f,0x25202c3438317225,0x322d202c33383172\n"
".quad 0x3436333834373431,0x2e766f6d090a3b38,0x3372250920323373,0x6d090a3b30202c34\n"
".quad 0x09203233752e766f,0x3b30202c35337225,0x365f345f744c240a,0x2e090a3a36383131\n"
".quad 0x2220616d67617270,0x6c6c6f726e756f6e,0x6c3c2f2f200a3b22,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x202c343220656e69,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x746172657469202c,0x0a36203a736e6f69,0x383109636f6c2e09,0x0a30093031343109\n"
".quad 0x736e6f632e646c09,0x2509203233752e74,0x255b202c35383172,0x0a3b5d302b386472\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323375,0x38317225202c3638,0x3438317225202c35\n"
".quad 0x752e646461090a3b,0x3831722509203233,0x3638317225202c37,0x0a3b35337225202c\n"
".quad 0x383109636f6c2e09,0x0a30093131343109,0x2e74672e74657309,0x203233752e323375\n"
".quad 0x202c383831722509,0x25202c3638317225,0x6e090a3b37383172,0x09203233732e6765\n"
".quad 0x25202c3938317225,0x6d090a3b38383172,0x33752e69682e6c75,0x3039317225092032\n"
".quad 0x2c3538317225202c,0x0a3b343831722520,0x3233752e64646109,0x202c353372250920\n"
".quad 0x25202c3938317225,0x2e090a3b30393172,0x3109383109636f6c,0x73090a3009323134\n"
".quad 0x2e6c61636f6c2e74,0x72255b0920323375,0x25202c5d302b3964,0x61090a3b37383172\n"
".quad 0x09203233732e6464,0x7225202c34337225,0x090a3b31202c3433,0x203436752e646461\n"
".quad 0x25202c3964722509,0x0a3b34202c396472,0x3436752e64646109,0x202c386472250920\n"
".quad 0x3b34202c38647225,0x33752e766f6d090a,0x3139317225092032,0x6573090a3b36202c\n"
".quad 0x33732e656e2e7074,0x2c39327025092032,0x25202c3433722520,0x40090a3b31393172\n"
".quad 0x6172622039327025,0x5f345f744c240920,0x090a3b3638313136,0x09383109636f6c2e\n"
".quad 0x090a300934313431,0x6c61636f6c2e7473,0x5f5b09203233752e,0x5f5f5f616475635f\n"
".quad 0x7365725f61647563,0x383832335f746c75,0x7225202c5d34322b,0x6f6c2e090a3b3533\n"
".quad 0x3134310938310963,0x6c6873090a300939,0x722509203233622e,0x317225202c323931\n"
".quad 0x090a3b31202c3138,0x203233752e726873,0x202c333931722509,0x32202c3239317225\n"
".quad 0x2e627573090a3b34,0x3172250920323375,0x39317225202c3439,0x0a3b383231202c33\n"
".quad 0x3233752e72687309,0x2c35393172250920,0x202c343931722520,0x2e766f6d090a3b35\n"
".quad 0x3172250920323373,0x090a3b34202c3639,0x203233732e627573,0x202c373931722509\n"
".quad 0x25202c3639317225,0x63090a3b35393172,0x732e3436732e7476,0x3164722509203233\n"
".quad 0x3739317225202c39,0x772e6c756d090a3b,0x203233732e656469,0x202c303264722509\n"
".quad 0x34202c3739317225,0x752e646461090a3b,0x3264722509203436,0x2c37647225202c31\n"
".quad 0x0a3b303264722520,0x61636f6c2e646c09,0x2509203233752e6c,0x72255b202c353372\n"
".quad 0x0a3b5d382b313264,0x383109636f6c2e09,0x0a30093032343109,0x61636f6c2e646c09\n"
".quad 0x2509203233752e6c,0x72255b202c393472,0x0a3b5d342b313264,0x3233622e646e6109\n"
".quad 0x2c38393172250920,0x202c343931722520,0x766f6d090a3b3133,0x722509203233752e\n"
".quad 0x0a3b30202c393931,0x71652e7074657309,0x702509203233752e,0x39317225202c3033\n"
".quad 0x3939317225202c38,0x3033702540090a3b,0x4c24092061726220,0x393631365f345f74\n"
".quad 0x636f6c2e090a3b38,0x3332343109383109,0x2e766f6d090a3009,0x3272250920323373\n"
".quad 0x0a3b3233202c3030,0x3233732e62757309,0x2c31303272250920,0x202c303032722520\n"
".quad 0x090a3b3839317225,0x203233752e726873,0x202c323032722509,0x7225202c39347225\n"
".quad 0x6873090a3b313032,0x2509203233622e6c,0x7225202c33303272,0x39317225202c3533\n"
".quad 0x2e646461090a3b38,0x3372250920323375,0x3230327225202c35,0x3b3330327225202c\n"
".quad 0x3109636f6c2e090a,0x3009343234310938,0x636f6c2e646c090a,0x09203233752e6c61\n"
".quad 0x5b202c3430327225,0x5d302b3132647225,0x752e726873090a3b,0x3032722509203233\n"
".quad 0x3430327225202c35,0x3b3130327225202c,0x33622e6c6873090a,0x3630327225092032\n"
".quad 0x202c39347225202c,0x090a3b3839317225,0x203233752e646461,0x25202c3934722509\n"
".quad 0x7225202c35303272,0x744c240a3b363032,0x38393631365f345f,0x09636f6c2e090a3a\n"
".quad 0x0936323431093831,0x752e726873090a30,0x3433722509203233,0x202c35337225202c\n"
".quad 0x6f6c2e090a3b3033,0x3234310938310963,0x726873090a300938,0x722509203233752e\n"
".quad 0x347225202c373032,0x090a3b3033202c39,0x203233622e6c6873,0x202c383032722509\n"
".quad 0x3b32202c35337225,0x33752e646461090a,0x2c35337225092032,0x202c373032722520\n"
".quad 0x090a3b3830327225,0x09383109636f6c2e,0x090a300939323431,0x203233622e6c6873\n"
".quad 0x25202c3934722509,0x0a3b32202c393472,0x3233752e766f6d09,0x2c39303272250920\n"
".quad 0x746573090a3b3020,0x3233752e71652e70,0x202c313370250920,0x7225202c39347225\n"
".quad 0x2540090a3b393032,0x2061726220313370,0x365f345f744c2409,0x2e090a3b36363432\n"
".quad 0x3109383109636f6c,0x61090a3009303334,0x09203233752e6464,0x25202c3031327225\n"
".quad 0x0a3b31202c353372,0x3233752e766f6d09,0x2c31313272250920,0x3834373431322d20\n"
".quad 0x73090a3b38343633,0x33752e74672e7465,0x2509203233752e32,0x7225202c32313272\n"
".quad 0x327225202c303132,0x67656e090a3b3131,0x722509203233732e,0x327225202c333132\n"
".quad 0x617262090a3b3231,0x4c240920696e752e,0x313232365f345f74,0x345f744c240a3b30\n"
".quad 0x0a3a36363432365f,0x3233752e766f6d09,0x2c34313272250920,0x3834373431322d20\n"
".quad 0x73090a3b38343633,0x33752e74672e7465,0x2509203233752e32,0x7225202c35313272\n"
".quad 0x31327225202c3533,0x2e67656e090a3b34,0x3272250920323373,0x31327225202c3331\n"
".quad 0x345f744c240a3b35,0x0a3a30313232365f,0x383109636f6c2e09,0x0a30093133343109\n"
".quad 0x3233752e64646109,0x2c36313272250920,0x25202c3433722520,0x2e090a3b33313272\n"
".quad 0x3109383109636f6c,0x6e090a3009303334,0x09203233732e6765,0x25202c3731327225\n"
".quad 0x6d090a3b36313272,0x09203233752e766f,0x30202c3831327225,0x2e70746573090a3b\n"
".quad 0x09203233752e656e,0x7225202c32337025,0x327225202c323831,0x6c6573090a3b3831\n"
".quad 0x2509203233732e70,0x327225202c343372,0x31327225202c3731,0x3b32337025202c36\n"
".quad 0x33752e766f6d090a,0x3931327225092032,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x2c33337025092032,0x202c333132722520,0x090a3b3931327225,0x7262203333702540\n"
".quad 0x345f744c24092061,0x0a3b32323732365f,0x383109636f6c2e09,0x0a30093633343109\n"
".quad 0x3233732e67656e09,0x202c393472250920,0x2e090a3b39347225,0x3109383109636f6c\n"
".quad 0x6d090a3009383334,0x09203233752e766f,0x30202c3032327225,0x652e746573090a3b\n"
".quad 0x33752e3233752e71,0x3132327225092032,0x202c39347225202c,0x090a3b3032327225\n"
".quad 0x203233732e67656e,0x202c323232722509,0x090a3b3132327225,0x203233622e746f6e\n"
".quad 0x202c333232722509,0x61090a3b35337225,0x09203233752e6464,0x7225202c35337225\n"
".quad 0x327225202c323232,0x6f6c2e090a3b3332,0x3334310938310963,0x726f78090a300939\n"
".quad 0x722509203233622e,0x38317225202c3133,0x373431322d202c32,0x0a3b383436333834\n"
".quad 0x32365f345f744c24,0x6c2e090a3a323237,0x343109383109636f,0x6f6d090a30093134\n"
".quad 0x2509203233732e76,0x337225202c363772,0x2e766f6d090a3b34,0x3272250920323375\n"
".quad 0x090a3b30202c3432,0x2e656c2e70746573,0x3370250920323373,0x2c35337225202c34\n"
".quad 0x0a3b343232722520,0x6220343370254009,0x5f744c2409206172,0x3b36323431375f34\n"
".quad 0x33752e766f6d090a,0x2c38377225092032,0x5f744c240a3b3020,0x3a36343733365f34\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x202c313434312065\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x383109636f6c2e09,0x0a30093534343109\n"
".quad 0x3233752e72687309,0x2c35323272250920,0x33202c3934722520,0x2e6c6873090a3b31\n"
".quad 0x3272250920323362,0x35337225202c3632,0x6461090a3b31202c,0x2509203233752e64\n"
".quad 0x327225202c353372,0x32327225202c3532,0x636f6c2e090a3b36,0x3634343109383109\n"
".quad 0x2e6c6873090a3009,0x3472250920323362,0x2c39347225202c39,0x6f6c2e090a3b3120\n"
".quad 0x3434310938310963,0x627573090a300937,0x722509203233752e,0x38377225202c3837\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3b30202c37323272,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x337225202c353370,0x3732327225202c35,0x3533702540090a3b\n"
".quad 0x4c24092061726220,0x343733365f345f74,0x2e617262090a3b36,0x744c240920696e75\n"
".quad 0x34333233365f345f,0x5f345f744c240a3b,0x090a3a3632343137,0x203233752e766f6d\n"
".quad 0x30202c3837722509,0x5f345f744c240a3b,0x090a3a3433323336,0x09383109636f6c2e\n"
".quad 0x090a300939343431,0x752e6f6c2e6c756d,0x3934722509203233,0x202c35337225202c\n"
".quad 0x383730373132392d,0x6f6c2e090a3b3037,0x3534310938310963,0x766f6d090a300930\n"
".quad 0x722509203233752e,0x32392d202c383232,0x3b30373837303731,0x69682e6c756d090a\n"
".quad 0x722509203233752e,0x35337225202c3533,0x3b3832327225202c,0x33752e766f6d090a\n"
".quad 0x3932327225092032,0x6573090a3b30202c,0x33732e656c2e7074,0x2c36337025092032\n"
".quad 0x25202c3533722520,0x40090a3b39323272,0x6172622036337025,0x5f345f744c240920\n"
".quad 0x090a3b3835323436,0x09383109636f6c2e,0x090a300932353431,0x203233752e726873\n"
".quad 0x202c303332722509,0x3133202c39347225,0x622e6c6873090a3b,0x3332722509203233\n"
".quad 0x2c35337225202c31,0x646461090a3b3120,0x722509203233752e,0x33327225202c3533\n"
".quad 0x3133327225202c30,0x09636f6c2e090a3b,0x0933353431093831,0x622e6c6873090a30\n"
".quad 0x3934722509203233,0x202c39347225202c,0x636f6c2e090a3b31,0x3435343109383109\n"
".quad 0x2e627573090a3009,0x3772250920323375,0x2c38377225202c38,0x5f744c240a3b3120\n"
".quad 0x3a38353234365f34,0x3109636f6c2e090a,0x3009363534310938,0x33752e766f6d090a\n"
".quad 0x3233327225092032,0x6573090a3b30202c,0x3233752e656e2e74,0x722509203233752e\n"
".quad 0x347225202c333332,0x3233327225202c39,0x732e67656e090a3b,0x3332722509203233\n"
".quad 0x3333327225202c34,0x752e646461090a3b,0x3533722509203233,0x2c3433327225202c\n"
".quad 0x090a3b3533722520,0x09383109636f6c2e,0x090a300938353431,0x203233622e6c6873\n"
".quad 0x202c353332722509,0x3432202c35337225,0x732e766f6d090a3b,0x3332722509203233\n"
".quad 0x73090a3b30202c36,0x33752e746c2e7465,0x2509203233732e32,0x7225202c37333272\n"
".quad 0x327225202c353332,0x67656e090a3b3633,0x722509203233732e,0x327225202c383332\n"
".quad 0x726873090a3b3733,0x722509203233752e,0x337225202c393332,0x61090a3b38202c35\n"
".quad 0x09203233752e6464,0x25202c3034327225,0x363231202c383772,0x622e6c6873090a3b\n"
".quad 0x3432722509203233,0x3034327225202c31,0x61090a3b3332202c,0x09203233752e6464\n"
".quad 0x25202c3234327225,0x7225202c39333272,0x6461090a3b313432,0x2509203233752e64\n"
".quad 0x7225202c33343272,0x327225202c383332,0x2e726f090a3b3234,0x3272250920323362\n"
".quad 0x31337225202c3434,0x3b3334327225202c,0x33622e766f6d090a,0x2c37326625092032\n"
".quad 0x0a3b343432722520,0x696e752e61726209,0x6e6557444c240920,0x746e695f5f5f6964\n"
".quad 0x6d665f6c616e7265,0x365f3138315f6461,0x5f345f744c240a3b,0x090a3a3236313036\n"
".quad 0x09383109636f6c2e,0x090a300931373431,0x203233662e766f6d,0x30202c3639662509\n"
".quad 0x3839663232663366,0x2f09202020203b33,0x363633362e30202f,0x662e6c756d090a32\n"
".quad 0x3739662509203233,0x202c34326625202c,0x63090a3b36396625,0x732e696e722e7476\n"
".quad 0x09203233662e3233,0x25202c3534327225,0x6f6d090a3b373966,0x2509203233732e76\n"
".quad 0x327225202c363772,0x6f6c2e090a3b3534,0x3734310938310963,0x747663090a300932\n"
".quad 0x2e3233662e6e722e,0x3966250920323373,0x3534327225202c38,0x662e67656e090a3b\n"
".quad 0x3939662509203233,0x0a3b38396625202c,0x3233662e766f6d09,0x2c30303166250920\n"
".quad 0x6135386532663020,0x092020203b393033,0x3737302e36202f2f,0x6d090a31312d6531\n"
".quad 0x09203233662e766f,0x30202c3130316625,0x3261616466393366,0x2f2f092020203b30\n"
".quad 0x38343030302e3020,0x6f6d090a37323833,0x2509203233662e76,0x6630202c32303166\n"
".quad 0x3030303039636633,0x202f2f092020203b,0x0a31333037352e31,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x39396625202c3330,0x2c3230316625202c,0x090a3b3432662520\n"
".quad 0x662e6e722e616d66,0x3031662509203233,0x2c39396625202c34,0x202c313031662520\n"
".quad 0x090a3b3330316625,0x662e6e722e616d66,0x3732662509203233,0x202c39396625202c\n"
".quad 0x25202c3030316625,0x4c240a3b34303166,0x5f5f69646e655744,0x616e7265746e695f\n"
".quad 0x315f64616d665f6c,0x2e090a3a365f3138,0x3109383109636f6c,0x61090a3009353037\n"
".quad 0x09203233732e6464,0x25202c3030317225,0x0a3b31202c363772,0x3233662e766f6d09\n"
".quad 0x2c35303166250920,0x090a3b3732662520,0x203233662e6c756d,0x25202c3833662509\n"
".quad 0x6625202c35303166,0x6e61090a3b353031,0x2509203233622e64,0x7225202c36343272\n"
".quad 0x0a3b31202c303031,0x3233752e766f6d09,0x2c37343272250920,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c373370250920,0x25202c3634327225,0x40090a3b37343272\n"
".quad 0x6172622037337025,0x5f345f744c240920,0x090a3b3632303536,0x09383109636f6c2e\n"
".quad 0x090a300939303731,0x203233662e766f6d,0x202c363031662509,0x3566636337336630\n"
".quad 0x2f092020203b6563,0x333334342e32202f,0x6d090a35302d6532,0x09203233662e766f\n"
".quad 0x30202c3730316625,0x3136303662616266,0x2f2f092020203b61,0x333130302e302d20\n"
".quad 0x6d66090a33373838,0x3233662e6e722e61,0x2c38303166250920,0x202c363031662520\n"
".quad 0x6625202c38336625,0x6f6d090a3b373031,0x2509203233662e76,0x6630202c39303166\n"
".quad 0x3561616161326433,0x202f2f092020203b,0x3636363134302e30,0x722e616d66090a36\n"
".quad 0x2509203233662e6e,0x6625202c30313166,0x336625202c383031,0x3930316625202c38\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x3066626630202c31,0x20203b3030303030\n"
".quad 0x2e302d202f2f0920,0x722e616d66090a35,0x2509203233662e6e,0x6625202c32313166\n"
".quad 0x336625202c303131,0x3131316625202c38,0x662e766f6d090a3b,0x3131662509203233\n"
".quad 0x3866336630202c33,0x20203b3030303030,0x090a31202f2f0920,0x662e6e722e616d66\n"
".quad 0x3734662509203233,0x2c3231316625202c,0x25202c3833662520,0x62090a3b33313166\n"
".quad 0x0920696e752e6172,0x34365f345f744c24,0x744c240a3b303737,0x36323035365f345f\n"
".quad 0x09636f6c2e090a3a,0x0931313731093831,0x662e766f6d090a30,0x3131662509203233\n"
".quad 0x3439626630202c34,0x20203b3966316163,0x2e302d202f2f0920,0x3531353931303030\n"
".quad 0x662e766f6d090a33,0x3131662509203233,0x3063336630202c35,0x20203b6539333838\n"
".quad 0x302e30202f2f0920,0x0a36313233333830,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x31316625202c3631,0x2c38336625202c34,0x0a3b353131662520,0x3233662e766f6d09\n"
".quad 0x2c37313166250920,0x6161326562663020,0x092020203b336161,0x36312e302d202f2f\n"
".quad 0x6d66090a37363636,0x3233662e6e722e61,0x2c38313166250920,0x202c363131662520\n"
".quad 0x6625202c38336625,0x756d090a3b373131,0x2509203233662e6c,0x6625202c39313166\n"
".quad 0x31316625202c3833,0x2e616d66090a3b38,0x09203233662e6e72,0x6625202c37346625\n"
".quad 0x316625202c393131,0x30316625202c3530,0x345f744c240a3b35,0x0a3a30373734365f\n"
".quad 0x383109636f6c2e09,0x0a30093331373109,0x3233662e67656e09,0x2c30323166250920\n"
".quad 0x090a3b3734662520,0x203233622e646e61,0x202c383432722509,0x32202c3030317225\n"
".quad 0x732e766f6d090a3b,0x3432722509203233,0x73090a3b30202c39,0x732e656e2e707465\n"
".quad 0x3833702509203233,0x2c3834327225202c,0x0a3b393432722520,0x33662e706c657309\n"
".quad 0x2c37346625092032,0x202c303231662520,0x7025202c37346625,0x6f6c2e090a3b3833\n"
".quad 0x3137310938310963,0x766f6d090a300936,0x662509203233662e,0x37346625202c3532\n"
".quad 0x6e6557444c240a3b,0x6973695f5f5f6964,0x5f3138315f66666e,0x636f6c2e090a3a35\n"
".quad 0x3833363109383109,0x706c6573090a3009,0x722509203233732e,0x202c31202c303532\n"
".quad 0x3b37327025202c30,0x33662e766f6d090a,0x3132316625092032,0x303030306630202c\n"
".quad 0x2020203b30303030,0x73090a30202f2f09,0x33752e71652e7465,0x2509203233662e32\n"
".quad 0x6625202c31353272,0x32316625202c3432,0x2e67656e090a3b31,0x3272250920323373\n"
".quad 0x35327225202c3235,0x622e726f090a3b31,0x3532722509203233,0x3035327225202c33\n"
".quad 0x3b3235327225202c,0x33752e766f6d090a,0x3435327225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c39337025092032,0x202c333532722520,0x090a3b3435327225\n"
".quad 0x7262203933702540,0x345f744c24092061,0x0a3b32383235365f,0x383109636f6c2e09\n"
".quad 0x0a30093933363109,0x3233662e766f6d09,0x2c32323166250920,0x3030303030663020\n"
".quad 0x092020203b303030,0x756d090a30202f2f,0x3233662e6e722e6c,0x202c373566250920\n"
".quad 0x6625202c34326625,0x7262090a3b323231,0x240920696e752e61,0x5f69646e6557444c\n"
".quad 0x66666e6973695f5f,0x0a3b315f3138315f,0x35365f345f744c24,0x6f6d090a3a323832\n"
".quad 0x2509203233662e76,0x6630202c33323166,0x3030376162333734,0x202f2f092020203b\n"
".quad 0x73090a3933303834,0x662e74672e707465,0x3034702509203233,0x202c32396625202c\n"
".quad 0x090a3b3332316625,0x6220303470252140,0x5f744c2409206172,0x3b34393735365f34\n"
".quad 0x3109636f6c2e090a,0x3009363933310938,0x33622e766f6d090a,0x3138317225092032\n"
".quad 0x0a3b34326625202c,0x3233622e646e6109,0x2c32383172250920,0x202c313831722520\n"
".quad 0x333834373431322d,0x6f6d090a3b383436,0x2509203233732e76,0x7225202c30313172\n"
".quad 0x6c2e090a3b323831,0x343209383109636f,0x2e6c6873090a3009,0x3272250920323362\n"
".quad 0x38317225202c3535,0x6d090a3b38202c31,0x09203436732e766f,0x25202c3431647225\n"
".quad 0x6f6d090a3b366472,0x2509203436752e76,0x5f5f202c35316472,0x635f5f5f61647563\n"
".quad 0x757365725f616475,0x36313130365f746c,0x33622e726f090a3b,0x3438317225092032\n"
".quad 0x2c3535327225202c,0x3834373431322d20,0x6d090a3b38343633,0x09203233732e766f\n"
".quad 0x30202c3231317225,0x752e766f6d090a3b,0x3131722509203233,0x4c240a3b30202c33\n"
".quad 0x313836365f345f74,0x6172702e090a3a38,0x756f6e2220616d67,0x0a3b226c6c6f726e\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x73656e202c343220\n"
".quad 0x70656420676e6974,0x69202c31203a6874,0x6e6f697461726574,0x6c2e090a36203a73\n"
".quad 0x343109383109636f,0x646c090a30093031,0x752e74736e6f632e,0x3532722509203233\n"
".quad 0x316472255b202c36,0x6d090a3b5d302b34,0x33752e6f6c2e6c75,0x3735327225092032\n"
".quad 0x2c3635327225202c,0x0a3b343831722520,0x3233752e64646109,0x2c38353272250920\n"
".quad 0x202c373532722520,0x090a3b3331317225,0x09383109636f6c2e,0x090a300931313431\n"
".quad 0x752e74672e746573,0x09203233752e3233,0x25202c3935327225,0x7225202c37353272\n"
".quad 0x656e090a3b383532,0x2509203233732e67,0x7225202c30363272,0x756d090a3b393532\n"
".quad 0x3233752e69682e6c,0x2c31363272250920,0x202c363532722520,0x090a3b3438317225\n"
".quad 0x203233752e646461,0x202c333131722509,0x25202c3036327225,0x2e090a3b31363272\n"
".quad 0x3109383109636f6c,0x73090a3009323134,0x2e6c61636f6c2e74,0x72255b0920323375\n"
".quad 0x202c5d302b353164,0x090a3b3835327225,0x203233732e646461,0x202c323131722509\n"
".quad 0x31202c3231317225,0x752e646461090a3b,0x3164722509203436,0x3531647225202c35\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x7225202c34316472,0x0a3b34202c343164\n"
".quad 0x3233752e766f6d09,0x2c32363272250920,0x746573090a3b3620,0x3233732e656e2e70\n"
".quad 0x202c313470250920,0x25202c3231317225,0x40090a3b32363272,0x6172622031347025\n"
".quad 0x5f345f744c240920,0x090a3b3831383636,0x09383109636f6c2e,0x090a300934313431\n"
".quad 0x6c61636f6c2e7473,0x5f5b09203233752e,0x5f5f5f616475635f,0x7365725f61647563\n"
".quad 0x313130365f746c75,0x25202c5d34322b36,0x2e090a3b33313172,0x3109383109636f6c\n"
".quad 0x73090a3009393134,0x09203233622e6c68,0x25202c3336327225,0x3b31202c31383172\n"
".quad 0x33752e726873090a,0x3436327225092032,0x2c3336327225202c,0x7573090a3b343220\n"
".quad 0x2509203233752e62,0x7225202c35363272,0x383231202c343632,0x752e726873090a3b\n"
".quad 0x3632722509203233,0x3536327225202c36,0x6f6d090a3b35202c,0x2509203233732e76\n"
".quad 0x3b34202c37363272,0x33732e627573090a,0x3836327225092032,0x2c3736327225202c\n"
".quad 0x0a3b363632722520,0x3436732e74766309,0x722509203233732e,0x327225202c323264\n"
".quad 0x6c756d090a3b3836,0x33732e656469772e,0x3332647225092032,0x2c3836327225202c\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c343264,0x32647225202c3331\n"
".quad 0x6c2e646c090a3b33,0x3233752e6c61636f,0x2c33313172250920,0x2b34326472255b20\n"
".quad 0x6f6c2e090a3b5d38,0x3234310938310963,0x2e646c090a300930,0x33752e6c61636f6c\n"
".quad 0x3732317225092032,0x34326472255b202c,0x6e61090a3b5d342b,0x2509203233622e64\n"
".quad 0x7225202c38393172,0x3b3133202c353632,0x33752e766f6d090a,0x3936327225092032\n"
".quad 0x6573090a3b30202c,0x33752e71652e7074,0x2c32347025092032,0x202c383931722520\n"
".quad 0x090a3b3936327225,0x7262203234702540,0x345f744c24092061,0x0a3b30333337365f\n"
".quad 0x383109636f6c2e09,0x0a30093332343109,0x3233732e766f6d09,0x2c30373272250920\n"
".quad 0x7573090a3b323320,0x2509203233732e62,0x7225202c31373272,0x317225202c303732\n"
".quad 0x726873090a3b3839,0x722509203233752e,0x317225202c323732,0x37327225202c3732\n"
".quad 0x2e6c6873090a3b31,0x3272250920323362,0x31317225202c3337,0x3839317225202c33\n"
".quad 0x752e646461090a3b,0x3131722509203233,0x3237327225202c33,0x3b3337327225202c\n"
".quad 0x3109636f6c2e090a,0x3009343234310938,0x636f6c2e646c090a,0x09203233752e6c61\n"
".quad 0x5b202c3437327225,0x5d302b3432647225,0x752e726873090a3b,0x3732722509203233\n"
".quad 0x3437327225202c35,0x3b3137327225202c,0x33622e6c6873090a,0x3637327225092032\n"
".quad 0x2c3732317225202c,0x0a3b383931722520,0x3233752e64646109,0x2c37323172250920\n"
".quad 0x202c353732722520,0x240a3b3637327225,0x3337365f345f744c,0x6f6c2e090a3a3033\n"
".quad 0x3234310938310963,0x726873090a300936,0x722509203233752e,0x317225202c323131\n"
".quad 0x0a3b3033202c3331,0x383109636f6c2e09,0x0a30093832343109,0x3233752e72687309\n"
".quad 0x2c37373272250920,0x202c373231722520,0x6c6873090a3b3033,0x722509203233622e\n"
".quad 0x317225202c383732,0x090a3b32202c3331,0x203233752e646461,0x202c333131722509\n"
".quad 0x25202c3737327225,0x2e090a3b38373272,0x3109383109636f6c,0x73090a3009393234\n"
".quad 0x09203233622e6c68,0x25202c3732317225,0x3b32202c37323172,0x33752e766f6d090a\n"
".quad 0x3937327225092032,0x6573090a3b30202c,0x33752e71652e7074,0x2c33347025092032\n"
".quad 0x202c373231722520,0x090a3b3937327225,0x7262203334702540,0x345f744c24092061\n"
".quad 0x0a3b38393038365f,0x383109636f6c2e09,0x0a30093033343109,0x3233752e64646109\n"
".quad 0x2c30383272250920,0x202c333131722520,0x2e766f6d090a3b31,0x3272250920323375\n"
".quad 0x3431322d202c3138,0x3b38343633383437,0x74672e746573090a,0x3233752e3233752e\n"
".quad 0x2c32383272250920,0x202c303832722520,0x090a3b3138327225,0x203233732e67656e\n"
".quad 0x202c333832722509,0x090a3b3238327225,0x20696e752e617262,0x365f345f744c2409\n"
".quad 0x4c240a3b32343837,0x393038365f345f74,0x2e766f6d090a3a38,0x3272250920323375\n"
".quad 0x3431322d202c3438,0x3b38343633383437,0x74672e746573090a,0x3233752e3233752e\n"
".quad 0x2c35383272250920,0x202c333131722520,0x090a3b3438327225,0x203233732e67656e\n"
".quad 0x202c333832722509,0x240a3b3538327225,0x3837365f345f744c,0x6f6c2e090a3a3234\n"
".quad 0x3334310938310963,0x646461090a300931,0x722509203233752e,0x317225202c363832\n"
".quad 0x38327225202c3231,0x636f6c2e090a3b33,0x3033343109383109,0x2e67656e090a3009\n"
".quad 0x3272250920323373,0x38327225202c3738,0x2e766f6d090a3b36,0x3272250920323375\n"
".quad 0x090a3b30202c3838,0x2e656e2e70746573,0x3470250920323375,0x3238317225202c34\n"
".quad 0x3b3838327225202c,0x732e706c6573090a,0x3131722509203233,0x3738327225202c32\n"
".quad 0x2c3638327225202c,0x090a3b3434702520,0x203233752e766f6d,0x202c393832722509\n"
".quad 0x70746573090a3b30,0x203233752e71652e,0x25202c3534702509,0x7225202c33383272\n"
".quad 0x2540090a3b393832,0x2061726220353470,0x365f345f744c2409,0x2e090a3b34353338\n"
".quad 0x3109383109636f6c,0x6e090a3009363334,0x09203233732e6765,0x25202c3732317225\n"
".quad 0x2e090a3b37323172,0x3109383109636f6c,0x6d090a3009383334,0x09203233752e766f\n"
".quad 0x30202c3039327225,0x652e746573090a3b,0x33752e3233752e71,0x3139327225092032\n"
".quad 0x2c3732317225202c,0x0a3b303932722520,0x3233732e67656e09,0x2c32393272250920\n"
".quad 0x0a3b313932722520,0x3233622e746f6e09,0x2c33393272250920,0x0a3b333131722520\n"
".quad 0x3233752e64646109,0x2c33313172250920,0x202c323932722520,0x090a3b3339327225\n"
".quad 0x09383109636f6c2e,0x090a300939333431,0x203233622e726f78,0x202c303131722509\n"
".quad 0x2d202c3238317225,0x3633383437343132,0x5f744c240a3b3834,0x3a34353338365f34\n"
".quad 0x3109636f6c2e090a,0x3009313434310938,0x33732e766f6d090a,0x3335317225092032\n"
".quad 0x3b3231317225202c,0x33752e766f6d090a,0x3439327225092032,0x6573090a3b30202c\n"
".quad 0x33732e656c2e7074,0x2c36347025092032,0x202c333131722520,0x090a3b3439327225\n"
".quad 0x7262203634702540,0x345f744c24092061,0x0a3b32383631375f,0x3233752e766f6d09\n"
".quad 0x2c35353172250920,0x5f744c240a3b3020,0x3a38373339365f34,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x202c313434312065,0x20676e697473656e\n"
".quad 0x31203a6874706564,0x616d69747365202c,0x7265746920646574,0x203a736e6f697461\n"
".quad 0x0a6e776f6e6b6e75,0x383109636f6c2e09,0x0a30093534343109,0x3233752e72687309\n"
".quad 0x2c35393272250920,0x202c373231722520,0x6c6873090a3b3133,0x722509203233622e\n"
".quad 0x317225202c363932,0x090a3b31202c3331,0x203233752e646461,0x202c333131722509\n"
".quad 0x25202c3539327225,0x2e090a3b36393272,0x3109383109636f6c,0x73090a3009363434\n"
".quad 0x09203233622e6c68,0x25202c3732317225,0x3b31202c37323172,0x3109636f6c2e090a\n"
".quad 0x3009373434310938,0x33752e627573090a,0x3535317225092032,0x2c3535317225202c\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c373932,0x74672e7074657309\n"
".quad 0x702509203233732e,0x31317225202c3734,0x3739327225202c33,0x3734702540090a3b\n"
".quad 0x4c24092061726220,0x373339365f345f74,0x2e617262090a3b38,0x744c240920696e75\n"
".quad 0x36363838365f345f,0x5f345f744c240a3b,0x090a3a3238363137,0x203233752e766f6d\n"
".quad 0x202c353531722509,0x345f744c240a3b30,0x0a3a36363838365f,0x383109636f6c2e09\n"
".quad 0x0a30093934343109,0x2e6f6c2e6c756d09,0x3172250920323375,0x31317225202c3732\n"
".quad 0x373132392d202c33,0x090a3b3037383730,0x09383109636f6c2e,0x090a300930353431\n"
".quad 0x203233752e766f6d,0x202c383932722509,0x383730373132392d,0x6c756d090a3b3037\n"
".quad 0x203233752e69682e,0x202c333131722509,0x25202c3331317225,0x6d090a3b38393272\n"
".quad 0x09203233752e766f,0x30202c3939327225,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x7225202c38347025,0x327225202c333131,0x702540090a3b3939,0x0920617262203834\n"
".quad 0x39365f345f744c24,0x6c2e090a3b303938,0x343109383109636f,0x6873090a30093235\n"
".quad 0x2509203233752e72,0x7225202c30303372,0x3b3133202c373231,0x33622e6c6873090a\n"
".quad 0x3130337225092032,0x2c3331317225202c,0x646461090a3b3120,0x722509203233752e\n"
".quad 0x337225202c333131,0x30337225202c3030,0x636f6c2e090a3b31,0x3335343109383109\n"
".quad 0x2e6c6873090a3009,0x3172250920323362,0x32317225202c3732,0x2e090a3b31202c37\n"
".quad 0x3109383109636f6c,0x73090a3009343534,0x09203233752e6275,0x25202c3535317225\n"
".quad 0x3b31202c35353172,0x365f345f744c240a,0x2e090a3a30393839,0x3109383109636f6c\n"
".quad 0x6d090a3009363534,0x09203233752e766f,0x30202c3230337225,0x6e2e746573090a3b\n"
".quad 0x33752e3233752e65,0x3330337225092032,0x2c3732317225202c,0x0a3b323033722520\n"
".quad 0x3233732e67656e09,0x2c34303372250920,0x0a3b333033722520,0x3233752e64646109\n"
".quad 0x2c33313172250920,0x202c343033722520,0x090a3b3331317225,0x09383109636f6c2e\n"
".quad 0x090a300938353431,0x203233622e6c6873,0x202c353033722509,0x32202c3331317225\n"
".quad 0x2e766f6d090a3b34,0x3372250920323373,0x090a3b30202c3630,0x752e746c2e746573\n"
".quad 0x09203233732e3233,0x25202c3730337225,0x7225202c35303372,0x656e090a3b363033\n"
".quad 0x2509203233732e67,0x7225202c38303372,0x6873090a3b373033,0x2509203233752e72\n"
".quad 0x7225202c39303372,0x0a3b38202c333131,0x3233752e64646109,0x2c30313372250920\n"
".quad 0x202c353531722520,0x6873090a3b363231,0x2509203233622e6c,0x7225202c31313372\n"
".quad 0x3b3332202c303133,0x33752e646461090a,0x3231337225092032,0x2c3930337225202c\n"
".quad 0x0a3b313133722520,0x3233752e64646109,0x2c33313372250920,0x202c383033722520\n"
".quad 0x090a3b3231337225,0x09203233622e726f,0x25202c3431337225,0x7225202c30313172\n"
".quad 0x6f6d090a3b333133,0x2509203233622e76,0x337225202c393566,0x617262090a3b3431\n"
".quad 0x4c240920696e752e,0x5f5f69646e655744,0x616e7265746e695f,0x315f64616d665f6c\n"
".quad 0x4c240a3b325f3138,0x393735365f345f74,0x636f6c2e090a3a34,0x3137343109383109\n"
".quad 0x2e766f6d090a3009,0x3166250920323366,0x66336630202c3432,0x203b333839663232\n"
".quad 0x2e30202f2f092020,0x6d090a3236363336,0x09203233662e6c75,0x25202c3532316625\n"
".quad 0x316625202c343266,0x747663090a3b3432,0x3233732e696e722e,0x722509203233662e\n"
".quad 0x316625202c353133,0x766f6d090a3b3532,0x722509203233732e,0x337225202c333531\n"
".quad 0x6f6c2e090a3b3531,0x3734310938310963,0x747663090a300932,0x2e3233662e6e722e\n"
".quad 0x3166250920323373,0x31337225202c3632,0x2e67656e090a3b35,0x3166250920323366\n"
".quad 0x32316625202c3732,0x2e766f6d090a3b36,0x3166250920323366,0x65326630202c3832\n"
".quad 0x203b393033613538,0x2e36202f2f092020,0x31312d6531373730,0x33662e766f6d090a\n"
".quad 0x3932316625092032,0x646639336630202c,0x2020203b30326161,0x30302e30202f2f09\n"
".quad 0x0a37323833383430,0x3233662e766f6d09,0x2c30333166250920,0x3039636633663020\n"
".quad 0x092020203b303030,0x3037352e31202f2f,0x2e616d66090a3133,0x09203233662e6e72\n"
".quad 0x25202c3133316625,0x6625202c37323166,0x326625202c303331,0x2e616d66090a3b34\n"
".quad 0x09203233662e6e72,0x25202c3233316625,0x6625202c37323166,0x316625202c393231\n"
".quad 0x616d66090a3b3133,0x203233662e6e722e,0x25202c3935662509,0x6625202c37323166\n"
".quad 0x316625202c383231,0x57444c240a3b3233,0x695f5f5f69646e65,0x5f6c616e7265746e\n"
".quad 0x3138315f64616d66,0x6f6c2e090a3a325f,0x3436310938310963,0x766f6d090a300931\n"
".quad 0x662509203233662e,0x356625202c333331,0x2e6c756d090a3b39,0x3766250920323366\n"
".quad 0x3333316625202c30,0x3b3333316625202c,0x33622e646e61090a,0x3631337225092032\n"
".quad 0x2c3335317225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c373133\n"
".quad 0x71652e7074657309,0x702509203233732e,0x31337225202c3934,0x3731337225202c36\n"
".quad 0x3934702540090a3b,0x4c24092061726220,0x353630375f345f74,0x636f6c2e090a3b38\n"
".quad 0x3434363109383109,0x2e766f6d090a3009,0x3166250920323366,0x37336630202c3433\n"
".quad 0x203b656335666363,0x2e32202f2f092020,0x302d653233333434,0x662e766f6d090a35\n"
".quad 0x3331662509203233,0x6261626630202c35,0x20203b6131363036,0x2e302d202f2f0920\n"
".quad 0x3337383833313030,0x6e722e616d66090a,0x662509203233662e,0x316625202c363331\n"
".quad 0x30376625202c3433,0x3b3533316625202c,0x33662e766f6d090a,0x3733316625092032\n"
".quad 0x613264336630202c,0x2020203b35616161,0x34302e30202f2f09,0x66090a3636363631\n"
".quad 0x33662e6e722e616d,0x3833316625092032,0x2c3633316625202c,0x25202c3037662520\n"
".quad 0x6d090a3b37333166,0x09203233662e766f,0x30202c3933316625,0x3030303030666266\n"
".quad 0x2f2f092020203b30,0x66090a352e302d20,0x33662e6e722e616d,0x3034316625092032\n"
".quad 0x2c3833316625202c,0x25202c3037662520,0x6d090a3b39333166,0x09203233662e766f\n"
".quad 0x30202c3134316625,0x3030303038663366,0x2f2f092020203b30,0x2e616d66090a3120\n"
".quad 0x09203233662e6e72,0x6625202c39376625,0x376625202c303431,0x3134316625202c30\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b32303430375f34,0x375f345f744c240a\n"
".quad 0x2e090a3a38353630,0x3109383109636f6c,0x6d090a3009363436,0x09203233662e766f\n"
".quad 0x30202c3234316625,0x6631616334396266,0x2f2f092020203b39,0x313030302e302d20\n"
".quad 0x6d090a3335313539,0x09203233662e766f,0x30202c3334316625,0x3933383830633366\n"
".quad 0x2f2f092020203b65,0x33333830302e3020,0x616d66090a363132,0x203233662e6e722e\n"
".quad 0x202c343431662509,0x25202c3234316625,0x316625202c303766,0x766f6d090a3b3334\n"
".quad 0x662509203233662e,0x626630202c353431,0x3b33616161613265,0x2d202f2f09202020\n"
".quad 0x3736363636312e30,0x6e722e616d66090a,0x662509203233662e,0x316625202c363431\n"
".quad 0x30376625202c3434,0x3b3534316625202c,0x33662e6c756d090a,0x3734316625092032\n"
".quad 0x202c30376625202c,0x090a3b3634316625,0x662e6e722e616d66,0x3937662509203233\n"
".quad 0x2c3734316625202c,0x202c333331662520,0x240a3b3333316625,0x3430375f345f744c\n"
".quad 0x6f6c2e090a3a3230,0x3436310938310963,0x67656e090a300938,0x662509203233662e\n"
".quad 0x376625202c383431,0x2e646e61090a3b39,0x3372250920323362,0x35317225202c3831\n"
".quad 0x6d090a3b32202c33,0x09203233732e766f,0x30202c3931337225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c30357025,0x337225202c383133,0x6c6573090a3b3931\n"
".quad 0x2509203233662e70,0x316625202c393766,0x39376625202c3834,0x0a3b30357025202c\n"
".quad 0x383109636f6c2e09,0x0a30093135363109,0x3233662e766f6d09,0x202c373566250920\n"
".quad 0x4c240a3b39376625,0x5f5f69646e655744,0x5f66666e6973695f,0x090a3a315f313831\n"
".quad 0x09363109636f6c2e,0x646c090a30093739,0x752e6d617261702e,0x3264722509203436\n"
".quad 0x75635f5f5b202c35,0x5f5f6d7261706164,0x72656e656732325a,0x7463657053657461\n"
".quad 0x656e72654b6d7572,0x74616f6c6636506c,0x66666a6a5f305332,0x61090a3b5d74685f\n"
".quad 0x09203436752e6464,0x25202c3632647225,0x7225202c35326472,0x6c756d090a3b3164\n"
".quad 0x662509203233662e,0x356625202c393431,0x0a3b346625202c37,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x2c336625202c3035,0x25202c3532662520,0x61090a3b39343166\n"
".quad 0x09203233662e6464,0x25202c3135316625,0x316625202c393866,0x6c756d090a3b3035\n"
".quad 0x662509203233662e,0x326625202c323531,0x0a3b346625202c35,0x3233662e6c756d09\n"
".quad 0x2c33353166250920,0x6625202c33662520,0x627573090a3b3735,0x662509203233662e\n"
".quad 0x316625202c343531,0x35316625202c3335,0x2e646461090a3b32,0x3166250920323366\n"
".quad 0x31396625202c3535,0x3b3435316625202c,0x6f6c672e7473090a,0x662e32762e6c6162\n"
".quad 0x6472255b09203233,0x7b202c5d302b3632,0x66252c3135316625,0x4c240a3b7d353531\n"
".quad 0x373837345f345f74,0x636f6c2e090a3a34,0x3009393909363109,0x0a3b74697865090a\n"
".quad 0x5f646e6557444c24,0x656e656732325a5f,0x6365705365746172,0x6e72654b6d757274\n"
".quad 0x616f6c6636506c65,0x666a6a5f30533274,0x2f2f207d090a3a66,0x6e656732325a5f20\n"
".quad 0x6570536574617265,0x72654b6d75727463,0x6f6c6636506c656e,0x6a6a5f3053327461\n"
".quad 0x6e652e090a0a6666,0x30325a5f20797274,0x74616c75636c6163,0x654b65706f6c5365\n"
".quad 0x365066506c656e72,0x6a6a3274616f6c66,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x30325a5f5f6d7261,0x74616c75636c6163,0x654b65706f6c5365\n"
".quad 0x365066506c656e72,0x6a6a3274616f6c66,0x702e09090a2c685f,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x325a5f5f6d726170,0x616c75636c616330,0x4b65706f6c536574\n"
".quad 0x5066506c656e7265,0x6a3274616f6c6636,0x4f65706f6c735f6a,0x702e09090a2c7475\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x325a5f5f6d726170,0x616c75636c616330\n"
".quad 0x4b65706f6c536574,0x5066506c656e7265,0x6a3274616f6c6636,0x2c68746469775f6a\n"
".quad 0x617261702e09090a,0x5f203233752e206d,0x726170616475635f,0x616330325a5f5f6d\n"
".quad 0x536574616c75636c,0x6e72654b65706f6c,0x6c66365066506c65,0x685f6a6a3274616f\n"
".quad 0x090a297468676965,0x206765722e090a7b,0x3c7225203233752e,0x722e090a3b3e3732\n"
".quad 0x203436752e206765,0x3b3e32313c647225,0x2e206765722e090a,0x383c662520323366\n"
".quad 0x6765722e090a3b3e,0x2520646572702e20,0x2e090a3b3e363c70,0x3109363109636f6c\n"
".quad 0x444c240a30093330,0x5f5f6e6967656257,0x75636c616330325a,0x706f6c536574616c\n"
".quad 0x506c656e72654b65,0x74616f6c66365066,0x6f6d090a3a6a6a32,0x2509203233752e76\n"
".quad 0x61746325202c3172,0x6d090a3b782e6469,0x09203233752e766f,0x746e25202c327225\n"
".quad 0x6d090a3b782e6469,0x33752e6f6c2e6c75,0x202c337225092032,0x327225202c317225\n"
".quad 0x752e766f6d090a3b,0x2c34722509203233,0x2e64696174632520,0x2e766f6d090a3b79\n"
".quad 0x3572250920323375,0x2e6469746e25202c,0x2e6c756d090a3b79,0x09203233752e6f6c\n"
".quad 0x347225202c367225,0x090a3b357225202c,0x203233752e766f6d,0x7425202c37722509\n"
".quad 0x61090a3b782e6469,0x09203233752e6464,0x377225202c387225,0x090a3b337225202c\n"
".quad 0x203233752e766f6d,0x7425202c39722509,0x61090a3b792e6469,0x09203233752e6464\n"
".quad 0x7225202c30317225,0x0a3b367225202c39,0x3233752e766f6d09,0x202c313172250920\n"
".quad 0x70746573090a3b30,0x203233752e71652e,0x7225202c31702509,0x3b31317225202c38\n"
".quad 0x622031702540090a,0x5f744c2409206172,0x0a3b343730335f35,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x5f5f5b202c323172,0x6d72617061647563,0x6c616330325a5f5f\n"
".quad 0x6c536574616c7563,0x656e72654b65706f,0x6f6c66365066506c,0x69775f6a6a327461\n"
".quad 0x6d090a3b5d687464,0x09203233752e766f,0x3b30202c33317225,0x652e70746573090a\n"
".quad 0x2509203233752e71,0x30317225202c3270,0x0a3b33317225202c,0x7262203270254009\n"
".quad 0x355f744c24092061,0x090a3b363835335f,0x203233752e627573,0x25202c3431722509\n"
".quad 0x0a3b31202c323172,0x65672e7074657309,0x702509203233752e,0x202c387225202c33\n"
".quad 0x40090a3b34317225,0x2061726220337025,0x335f355f744c2409,0x646c090a3b363835\n"
".quad 0x752e6d617261702e,0x3531722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c75636c61633032,0x65706f6c53657461,0x66506c656e72654b,0x3274616f6c663650\n"
".quad 0x68676965685f6a6a,0x627573090a3b5d74,0x722509203233752e,0x35317225202c3631\n"
".quad 0x6573090a3b31202c,0x33752e65672e7074,0x202c347025092032,0x7225202c30317225\n"
".quad 0x702540090a3b3631,0x2409206172622034,0x3835335f355f744c,0x636f6c2e090a3b36\n"
".quad 0x0931313109363109,0x6c2e6c756d090a30,0x2509203233752e6f,0x317225202c373172\n"
".quad 0x3b32317225202c30,0x33752e646461090a,0x2c38317225092032,0x7225202c38722520\n"
".quad 0x2e646c090a3b3731,0x36752e6d61726170,0x2c31647225092034,0x616475635f5f5b20\n"
".quad 0x325a5f5f6d726170,0x616c75636c616330,0x4b65706f6c536574,0x5066506c656e7265\n"
".quad 0x6a3274616f6c6636,0x6d090a3b5d685f6a,0x33752e6f6c2e6c75,0x2c39317225092032\n"
".quad 0x34202c3831722520,0x752e747663090a3b,0x09203233752e3436,0x7225202c32647225\n"
".quad 0x646461090a3b3931,0x722509203436752e,0x32647225202c3364,0x0a3b31647225202c\n"
".quad 0x626f6c672e646c09,0x09203233662e6c61,0x72255b202c316625,0x090a3b5d342b3364\n"
".quad 0x61626f6c672e646c,0x2509203233662e6c,0x6472255b202c3266,0x090a3b5d342d2b33\n"
".quad 0x203233662e627573,0x6625202c33662509,0x0a3b326625202c31,0x363109636f6c2e09\n"
".quad 0x090a300932313109,0x203233752e646461,0x25202c3032722509,0x317225202c383172\n"
".quad 0x2e6c756d090a3b32,0x09203233752e6f6c,0x7225202c31327225,0x090a3b34202c3032\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x3b31327225202c34,0x36752e646461090a\n"
".quad 0x2c35647225092034,0x25202c3464722520,0x646c090a3b316472,0x2e6c61626f6c672e\n"
".quad 0x3466250920323366,0x2b356472255b202c,0x627573090a3b5d30,0x722509203233752e\n"
".quad 0x38317225202c3232,0x0a3b32317225202c,0x2e6f6c2e6c756d09,0x3272250920323375\n"
".quad 0x2c32327225202c33,0x747663090a3b3420,0x3233752e3436752e,0x202c366472250920\n"
".quad 0x61090a3b33327225,0x09203436752e6464,0x7225202c37647225,0x31647225202c3664\n"
".quad 0x6c672e646c090a3b,0x3233662e6c61626f,0x5b202c3566250920,0x3b5d302b37647225\n"
".quad 0x33662e627573090a,0x202c366625092032,0x356625202c346625,0x752e617262090a3b\n"
".quad 0x355f4c240920696e,0x240a3b343937315f,0x3730335f355f744c,0x702e646c090a3a34\n"
".quad 0x3233752e6d617261,0x202c323172250920,0x70616475635f5f5b,0x30325a5f5f6d7261\n"
".quad 0x74616c75636c6163,0x654b65706f6c5365,0x365066506c656e72,0x6a6a3274616f6c66\n"
".quad 0x3b5d68746469775f,0x335f355f744c240a,0x5f4c240a3a363835,0x0a3a303530325f35\n"
".quad 0x363109636f6c2e09,0x090a300934313109,0x752e6f6c2e6c756d,0x3432722509203233\n"
".quad 0x202c30317225202c,0x61090a3b32317225,0x09203233752e6464,0x7225202c38317225\n"
".quad 0x3b34327225202c38,0x33662e766f6d090a,0x202c366625092032,0x3030303030306630\n"
".quad 0x20202020203b3030,0x6d090a30202f2f09,0x09203233662e766f,0x306630202c336625\n"
".quad 0x3b30303030303030,0x2f2f092020202020,0x5f355f4c240a3020,0x2e090a3a34393731\n"
".quad 0x3109363109636f6c,0x756d090a30093631,0x3233752e6f6c2e6c,0x202c353272250920\n"
".quad 0x3b38202c38317225,0x36752e747663090a,0x2509203233752e34,0x327225202c386472\n"
".quad 0x702e646c090a3b35,0x3436752e6d617261,0x202c396472250920,0x70616475635f5f5b\n"
".quad 0x30325a5f5f6d7261,0x74616c75636c6163,0x654b65706f6c5365,0x365066506c656e72\n"
".quad 0x6a6a3274616f6c66,0x754f65706f6c735f,0x646461090a3b5d74,0x722509203436752e\n"
".quad 0x647225202c303164,0x3b39647225202c38,0x6f6c672e7473090a,0x662e32762e6c6162\n"
".quad 0x6472255b09203233,0x7b202c5d302b3031,0x7d3666252c336625,0x09636f6c2e090a3b\n"
".quad 0x3009373131093631,0x0a3b74697865090a,0x5f646e6557444c24,0x636c616330325a5f\n"
".quad 0x6f6c536574616c75,0x6c656e72654b6570,0x616f6c6636506650,0x7d090a3a6a6a3274\n"
".quad 0x30325a5f202f2f20,0x74616c75636c6163,0x654b65706f6c5365,0x365066506c656e72\n"
".quad 0x6a6a3274616f6c66,0x0000000000000a0a\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[6218];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"00fd80471c232174",(char*)"/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x0db7ceb0,&__elfEntries1};
# 3 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c" 2
struct __T20 {float2 *__par0;float2 *__par1;unsigned __par2;unsigned __par3;float __par4;float __par5;int __dummy_field;};
struct __T21 {float *__par0;float2 *__par1;unsigned __par2;unsigned __par3;int __dummy_field;};
extern void __device_stub__Z22generateSpectrumKernelP6float2S0_jjff(float2 *, float2 *, unsigned, unsigned, float, float);
extern void __device_stub__Z20calculateSlopeKernelPfP6float2jj(float *, float2 *, unsigned, unsigned);
static void __sti____cudaRegisterAll_50_tmpxft_00000dcd_00000000_4_oceanFFT_kernel_cpp1_ii_48fce8a0(void) __attribute__((__constructor__));
void __device_stub__Z22generateSpectrumKernelP6float2S0_jjff(float2 *__par0, float2 *__par1, unsigned __par2, unsigned __par3, float __par4, float __par5){ struct __T20 *__T214 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T214->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T214->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T214->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T214->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T214->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T214->__par5) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float2 *, float2 *, unsigned, unsigned, float, float))generateSpectrumKernel)); (void)cudaLaunch(((char *)((void ( *)(float2 *, float2 *, unsigned, unsigned, float, float))generateSpectrumKernel))); };}
void generateSpectrumKernel( float2 *__cuda_0,float2 *__cuda_1,unsigned __cuda_2,unsigned __cuda_3,float __cuda_4,float __cuda_5)
# 74 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{__device_stub__Z22generateSpectrumKernelP6float2S0_jjff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 99 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
}
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c"
void __device_stub__Z20calculateSlopeKernelPfP6float2jj( float *__par0, float2 *__par1, unsigned __par2, unsigned __par3) { struct __T21 *__T215 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T215->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T215->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T215->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T215->__par3) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float2 *, unsigned, unsigned))calculateSlopeKernel)); (void)cudaLaunch(((char *)((void ( *)(float *, float2 *, unsigned, unsigned))calculateSlopeKernel))); }; }
void calculateSlopeKernel( float *__cuda_0,float2 *__cuda_1,unsigned __cuda_2,unsigned __cuda_3)
# 104 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
{__device_stub__Z20calculateSlopeKernelPfP6float2jj( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 117 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/oceanFFT/oceanFFT_kernel.cu"
}
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c"
static void __sti____cudaRegisterAll_50_tmpxft_00000dcd_00000000_4_oceanFFT_kernel_cpp1_ii_48fce8a0(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float2 *, unsigned, unsigned))calculateSlopeKernel), (char*)"_Z20calculateSlopeKernelPfP6float2jj", "_Z20calculateSlopeKernelPfP6float2jj", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float2 *, float2 *, unsigned, unsigned, float, float))generateSpectrumKernel), (char*)"_Z22generateSpectrumKernelP6float2S0_jjff", "_Z22generateSpectrumKernelP6float2S0_jjff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_00000dcd_00000000-1_oceanFFT_kernel.cudafe1.stub.c" 2

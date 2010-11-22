# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
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
# 18 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
extern "C" { typedef unsigned uint; }
# 20 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
struct SimParams {
# 21 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float4 colliderPos;
# 22 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float colliderRadius;
# 24 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float3 gravity;
# 25 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float globalDamping;
# 26 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float particleRadius;
# 28 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
uint3 gridSize;
# 29 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
uint numCells;
# 30 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float3 worldOrigin;
# 31 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float3 cellSize;
# 33 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
uint numBodies;
# 34 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
uint maxParticlesPerCell;
# 36 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float spring;
# 37 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float damping;
# 38 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float shear;
# 39 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float attraction;
# 40 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
float boundaryDamping;
# 41 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cuh"
};
# 45 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< float4, 1, cudaReadModeElementType> oldPosTex;
# 46 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< float4, 1, cudaReadModeElementType> oldVelTex;
# 48 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< uint2, 1, cudaReadModeElementType> particleHashTex;
# 49 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< unsigned, 1, cudaReadModeElementType> cellStartTex;
# 51 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< unsigned, 1, cudaReadModeElementType> gridCountersTex;
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static texture< unsigned, 1, cudaReadModeElementType> gridCellsTex;
# 55 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
static SimParams params;
# 59 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
void integrate(float4 *newPos, float4 *newVel, float4 *
# 60 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldPos, float4 *oldVel, float
# 61 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
deltaTime) ;
# 90 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) int3 calcGridPos(float4 p)
# 91 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 97 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 100 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) uint calcGridHash(int3 gridPos)
# 101 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 106 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 109 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) void addParticleToCell(int3 gridPos, uint
# 110 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
index, uint *
# 111 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCounters, uint *
# 112 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCells)
# 113 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 127 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 132 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
void updateGridD(float4 *pos, uint *
# 133 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCounters, uint *
# 134 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCells) ;
# 147 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
void calcHashD(float4 *pos, uint2 *
# 148 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
particleHash) ;
# 164 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
void reorderDataAndFindCellStartD(uint2 *particleHash, float4 *
# 165 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 166 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldVel, float4 *
# 167 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
sortedPos, float4 *
# 168 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
sortedVel, uint *
# 169 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
cellStart) ;
# 205 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) float3 collideSpheres(float4 posA, float4 posB, float4
# 206 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
velA, float4 velB, float
# 207 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
radiusA, float radiusB, float
# 208 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
attraction)
# 209 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 243 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 249 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) float3 collideCell(int3 gridPos, uint
# 250 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
index, float4
# 251 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
pos, float4
# 252 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
vel, float4 *
# 253 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 254 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldVel, uint *
# 255 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCounters, uint *
# 256 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
gridCells)
# 257 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 286 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 291 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) float3 collideCell2(int3 gridPos, uint
# 292 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
index, float4
# 293 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
pos, float4
# 294 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
vel, float4 *
# 295 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 296 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldVel, uint2 *
# 297 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
particleHash, uint *
# 298 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
cellStart)
# 299 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 332 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
exit(___);}
# 336 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
void collideD(float4 *newPos, float4 *newVel, float4 *
# 337 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
oldPos, float4 *oldVel, uint2 *
# 339 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
particleHash, uint *
# 340 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
cellStart) ;
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000aee_00000000-3_particles_kernel.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000aee_00000000-3_particles_kernel.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000002f20,0x0000000000000040,0x0038004000140115,0x0001001700400008\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000600\n"
".quad 0x0000000000000384,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000984\n"
".quad 0x0000000000000155,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000ad9\n"
".quad 0x00000000000003c0,0x0000001900000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x00000001000001af,0x0000000000000006,0x0000000000000000,0x0000000000000e99\n"
".quad 0x00000000000001a8,0x0f00000f00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000031f,0x0000000000000002,0x0000000000000000,0x0000000000001041\n"
".quad 0x0000000000000044,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001d4,0x0000000000000002,0x0000000000000000,0x0000000000001085\n"
".quad 0x0000000000000084,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000166,0x0000000000000006,0x0000000000000000,0x0000000000001109\n"
".quad 0x0000000000000550,0x1400000d00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001fc,0x0000000000000002,0x0000000000000000,0x0000000000001659\n"
".quad 0x0000000000000038,0x0000000700000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000189,0x0000000000000002,0x0000000000000000,0x0000000000001691\n"
".quad 0x000000000000005c,0x0000000700000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000011f,0x0000000000000006,0x0000000000000000,0x00000000000016ed\n"
".quad 0x0000000000000518,0x1400000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000034c,0x0000000000000002,0x0000000000000000,0x0000000000001c05\n"
".quad 0x0000000000000030,0x0000000a00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000141,0x0000000000000002,0x0000000000000000,0x0000000000001c35\n"
".quad 0x0000000000000048,0x0000000a00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000009a,0x0000000000100006,0x0000000000000000,0x0000000000001c7d\n"
".quad 0x0000000000000138,0x0e00000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000002d6,0x0000000000000002,0x0000000000000000,0x0000000000001db5\n"
".quad 0x0000000000000050,0x0000000d00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000db,0x0000000000000002,0x0000000000000000,0x0000000000001e05\n"
".quad 0x00000000000000b0,0x0000000d00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000290,0x0000000000000003,0x0000000000000000,0x0000000000001eb5\n"
".quad 0x0000000000000404,0x0000000d00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x0000000000001eb5\n"
".quad 0x0000000000000d68,0x3a00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000025c,0x0000000000000002,0x0000000000000000,0x0000000000002c1d\n"
".quad 0x0000000000000050,0x0000001100000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000227,0x0000000000000002,0x0000000000000000,0x0000000000002c6d\n"
".quad 0x0000000000000010,0x0000001100000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000062,0x0000000000000002,0x0000000000000000,0x0000000000002c7d\n"
".quad 0x00000000000000c8,0x0000001100000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000376,0x0000000000000002,0x0000000000000000,0x0000000000002d45\n"
".quad 0x0000000000000070,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000091,0x0000000000000002,0x0000000000000000,0x0000000000002db5\n"
".quad 0x0000000000000168,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x63385a5f2e747865\n"
".quad 0x50446564696c6c6f,0x533474616f6c6636,0x5f30535f30535f30,0x5032746e69753550\n"
".quad 0x6e692e766e2e006a,0x6f63385a5f2e6f66,0x3650446564696c6c,0x30533474616f6c66\n"
".quad 0x505f30535f30535f,0x6a5032746e697535,0x666e692e766e2e00,0x2e747865742e006f\n"
".quad 0x726f657238325a5f,0x4161746144726564,0x6543646e6946646e,0x4474726174536c6c\n"
".quad 0x5032746e69753550,0x533474616f6c6636,0x5f32535f32535f32,0x692e766e2e006a50\n"
".quad 0x38325a5f2e6f666e,0x44726564726f6572,0x6946646e41617461,0x74536c6c6543646e\n"
".quad 0x6975355044747261,0x6f6c66365032746e,0x32535f3253347461,0x2e006a505f32535f\n"
".quad 0x395a5f2e74786574,0x68736148636c6163,0x74616f6c66365044,0x32746e6975355034\n"
".quad 0x666e692e766e2e00,0x6c6163395a5f2e6f,0x3650446873614863,0x35503474616f6c66\n"
".quad 0x742e0032746e6975,0x31315a5f2e747865,0x7247657461647075,0x6f6c663650446469\n"
".quad 0x5f31536a50347461,0x666e692e766e2e00,0x707531315a5f2e6f,0x6469724765746164\n"
".quad 0x74616f6c66365044,0x2e005f31536a5034,0x395a5f2e74786574,0x7461726765746e69\n"
".quad 0x74616f6c66365065,0x535f30535f305334,0x2e766e2e00665f30,0x395a5f2e6f666e69\n"
".quad 0x7461726765746e69,0x74616f6c66365065,0x535f30535f305334,0x2e766e2e00665f30\n"
".quad 0x746e6174736e6f63,0x707531315a5f2e30,0x6469724765746164,0x74616f6c66365044\n"
".quad 0x2e005f31536a5034,0x74736e6f632e766e,0x5a5f2e3631746e61,0x6564696c6c6f6338\n"
".quad 0x74616f6c66365044,0x535f30535f305334,0x746e697535505f30,0x2e766e2e006a5032\n"
".quad 0x746e6174736e6f63,0x6c6f63385a5f2e30,0x663650446564696c,0x5f30533474616f6c\n"
".quad 0x35505f30535f3053,0x006a5032746e6975,0x726168732e766e2e,0x7238325a5f2e6465\n"
".quad 0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364,0x6e69753550447472\n"
".quad 0x616f6c6636503274,0x5f32535f32533474,0x6e2e006a505f3253,0x6174736e6f632e76\n"
".quad 0x38325a5f2e30746e,0x44726564726f6572,0x6946646e41617461,0x74536c6c6543646e\n"
".quad 0x6975355044747261,0x6f6c66365032746e,0x32535f3253347461,0x2e006a505f32535f\n"
".quad 0x74736e6f632e766e,0x395a5f2e30746e61,0x7461726765746e69,0x74616f6c66365065\n"
".quad 0x535f30535f305334,0x2e766e2e00665f30,0x746e6174736e6f63,0x6c6163395a5f2e30\n"
".quad 0x3650446873614863,0x35503474616f6c66,0x6e2e0032746e6975,0x6174736e6f632e76\n"
".quad 0x385a5f000032746e,0x446564696c6c6f63,0x3474616f6c663650,0x30535f30535f3053\n"
".quad 0x32746e697535505f,0x6475635f5f006a50,0x645f30326d735f61,0x33665f6e725f7669\n"
".quad 0x616475635f5f0032,0x63725f30326d735f,0x3233665f6e725f70,0x5f616475635f5f00\n"
".quad 0x7271735f30326d73,0x3233665f6e725f74,0x6f657238325a5f00,0x6174614472656472\n"
".quad 0x43646e6946646e41,0x74726174536c6c65,0x32746e6975355044,0x3474616f6c663650\n"
".quad 0x32535f32535f3253,0x63395a5f006a505f,0x4468736148636c61,0x3474616f6c663650\n"
".quad 0x0032746e69753550,0x6164707531315a5f,0x5044646972476574,0x503474616f6c6636\n"
".quad 0x395a5f005f31536a,0x7461726765746e69,0x74616f6c66365065,0x535f30535f305334\n"
".quad 0x50646c6f00665f30,0x6c6f00786554736f,0x007865546c655664,0x6e756f4364697267\n"
".quad 0x0078655473726574,0x6c6c654364697267,0x7261700078655473,0x736148656c636974\n"
".quad 0x6c65630078655468,0x655474726174536c,0x736d617261700078,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0100030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0200030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0300030000000000,0x0000000000000000,0x0000000000000000,0x0000030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x1100030000000000,0x0000000000000000,0x00000000000d6800\n"
".quad 0x1400030000000000,0x0000000000000000,0x0000000000000000,0x1600030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0d00030000000000,0x0000000000000000\n"
".quad 0x0000000000013800,0x0f00030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0a00030000000000,0x0000000000000000,0x0000000000051800,0x0c00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0700030000000000,0x0000000000000000\n"
".quad 0x0000000000055000,0x0900030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0400030000000000,0x0000000000000000,0x000000000001a800,0x0600030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0800030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x1300030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x1200030000000000,0x0000000000000000,0x0000000000000000,0x1000030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0e00030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0500030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0b00030000000000,0x0000000000000000,0x0000000000000000,0x1500030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x1110120000000100,0x0000000000000000\n"
".quad 0x000000000006d000,0x1100120000002700,0x000000000001e000,0x0000000000037000\n"
".quad 0x1100120000003e00,0x00000000000a4000,0x0000000000023000,0x1100120000005500\n"
".quad 0x00000000000c7000,0x000000000000f800,0x0d10120000006d00,0x0000000000000000\n"
".quad 0x0000000000013800,0x0a1012000000a800,0x0000000000000000,0x000000000001a800\n"
".quad 0x071012000000c400,0x0000000000000000,0x000000000001e000,0x041012000000e100\n"
".quad 0x0000000000000000,0x000000000001a800,0x00001a0000010000,0x0000000000000000\n"
".quad 0x0000000000000000,0x00001a0000010a00,0x0000000000000000,0x0000000000000000\n"
".quad 0x00001a0000011400,0x0000000000000000,0x0000000000000000,0x00001a0000012400\n"
".quad 0x0000000000000000,0x0000000000000000,0x00001a0000013100,0x0000000000000000\n"
".quad 0x0000000000000000,0x00001a0000014100,0x0000000000000000,0x0000000000000000\n"
".quad 0x1500110000014e00,0x0000000000000000,0x0000000000007000,0x00440400005de400\n"
".quad 0x00000094001c0428,0x00400020009de42c,0x0000008400dc0428,0x00c06000001c232c\n"
".quad 0x00c06000209c2370,0x06000008001ca370,0x00400100039de420,0x00c00010001e0328\n"
".quad 0x014000e0009c0360,0x004000f3f0dc4348,0x014000c0031c0348,0x00000000211cc548\n"
".quad 0x004000d3f35c4384,0x01400080009c0348,0x00000000c21cc548,0x00480090031de484\n"
".quad 0x00cfe000c35e0028,0x08480050e0dc0050,0x0a480060e15c0030,0x0c480070e19c0030\n"
".quad 0x00480080311c0030,0x00480080515c0058,0x00480080619c0058,0x10400100421c0058\n"
".quad 0x12400100525c0030,0x14400100629c0030,0x8e000020d1dc0030,0x0048009000dde420\n"
".quad 0x8e000024d5dc0028,0x8e000028d9dc0020,0x000000340201e420,0x00efe000339c0028\n"
".quad 0x000000340249e450,0x000000340291e428,0x004801a041000028,0x00400093f0dc4358\n"
".quad 0x0e000020e3dc0048,0x0e000024e7dc0022,0x0e000028e1dc0022,0x014000a0031c0322\n"
".quad 0x000000380205e448,0x004801a051480028,0x004801a061900058,0x00000038024de458\n"
".quad 0x000000380281e428,0x004000b3f35c4328,0x004801a041040048,0x004801a0514c0058\n"
".quad 0x004801a061800058,0x00000000221cc558,0x00000000c11cc594,0x00000000001de794\n"
".quad 0x0000000000000080,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x140c040000000000,0x0000080000000000,0x0000180000001000,0x080a040000002000\n"
".quad 0x2400200000001600,0x0c17040024190300,0x200004ffffffff00,0x0c17040011f00000\n"
".quad 0x180003ffffffff00,0x0c17040021f00000,0x100002ffffffff00,0x0c17040021f00000\n"
".quad 0x080001ffffffff00,0x0c17040021f00000,0x000000ffffffff00,0x080d040021f00000\n"
".quad 0x0000010002001800,0x00440400005de400,0x00000094001c0428,0x00400020009de42c\n"
".quad 0x0000008400dc0428,0x00c06000001c232c,0x00c06000209c2370,0x00400080011de470\n"
".quad 0x06000008009ca328,0x09c00040219c0320,0x00480130015de420,0x00400093f1dc4328\n"
".quad 0x00000000641cc548,0x00480101211d0084,0x000005c001000750,0x004800c000dde450\n"
".quad 0x02000011201c8428,0x00fffffc30dc0310,0x06000001201c8448,0x004800b0011de414\n"
".quad 0x0e00000c001c0328,0x00c0600040dc2308,0x00c06000001c2370,0x004800a0011de470\n"
".quad 0x0000000c001ca328,0x00c0600040dc2350,0x00c06000001c2370,0x00480120015de470\n"
".quad 0x0000000c00dca328,0x004800f1111d0050,0x000003c001000750,0x004800b0015de450\n"
".quad 0x02000011201c8428,0x00fffffc511c0310,0x06000001201c8448,0x004800a0015de414\n"
".quad 0x0e000010001c0328,0x00c06000519c2308,0x00c06000001c2370,0x00480110015de470\n"
".quad 0x0600001800dca328,0x004800e1011d0020,0x0000024001000750,0x02000011201c8450\n"
".quad 0xfffffffc019de210,0x06000001201c841b,0x004800a0611c0314,0x0e000010001c0348\n"
".quad 0x0000001001dde208,0x00000000301c0318,0x0f8000a0011c0348,0x0000000400dde220\n"
".quad 0x004000b3f15c4318,0x7e18000040dc0548,0x00480150611c0354,0x0e00001030dc0348\n"
".quad 0x06480150001c0308,0x0f8000c0011c0320,0x004000d3f15c4320,0x00000000409c8548\n"
".quad 0x00000000001de794,0x00c00004401c0380,0x00c00004519c0360,0x00c00060001c0360\n"
".quad 0x00c00060619c0358,0x00fffffc001c0358,0x00fffffc619c0348,0x0ec003f401dc0348\n"
".quad 0x20c003f461dc031a,0x000005200021e71a,0x8edfe00041dc8040,0x8000001121dc4429\n"
".quad 0x000000600021e710,0x8edfe00051dc8040,0x80000015221c4429,0x000000400001e710\n"
".quad 0x00000014411c2040,0x00000b80001de750,0x00c00004425c0340,0x00c00004529c0360\n"
".quad 0x0e0000fc93dc0360,0x0e0000fca5dc0319,0x0e00000811dc0419,0x000000800001e70c\n"
".quad 0x0edfe00077dc0040,0x0edfe00081dc0029,0x00000080002de729,0x000000600021e740\n"
".quad 0xff000000001de240,0x00000014011c001b,0x000009e0001de7c8,0x0e00004401dc0440\n"
".quad 0x000000600021e70c,0x00000010501c8340,0x00000000011c0268,0x00000940001de73a\n"
".quad 0x0e00004831dc0440,0x000000800021e70c,0x00000010501c8340,0x00000000001c0268\n"
".quad 0xfe000000011c423a,0x00000880001de739,0x0e0000fc01dc2340,0x0e0000fc63dc231b\n"
".quad 0xffffff0001e1e21b,0x7ed7e0004120001b,0x000000fc01c1e430,0x000000800005e728\n"
".quad 0x7ed7e000515c0040,0x00c0010071dc0330,0x00000020001de748,0x000000fc01dde440\n"
".quad 0x00fffe08621c0328,0x00000014825ee348,0x00fffe08021c0341,0x00000010915c0048\n"
".quad 0x00000010811ee3c8,0x00000018001d0341,0x7e000014421c0048,0x08000020929e0030\n"
".quad 0x10000014a21c0030,0x08000020925e0030,0x10000014911c0030,0x00c00004429c0330\n"
".quad 0x00c00060a29c0360,0x00000028001c0358,0x00000000719c0348,0x00fffffc601c0348\n"
".quad 0x0ec003f401dc0348,0x000000600001e71a,0x00000028601d0340,0x00000010011ee348\n"
".quad 0x000004a0001de740,0x8ec003f861dc2340,0x000000600001e719,0x00000000401c0240\n"
".quad 0xfe000000011c423a,0x00000400001de739,0x0e0000fc61dc2340,0x000003c00001e71a\n"
".quad 0x0effffa061dc2340,0x000000400001e71b,0x00000000411c0240,0x00000340001de73a\n"
".quad 0x10000014929c0040,0x9000001491dc0031,0x90000014901c0030,0x00000019221f8431\n"
".quad 0x8e00001ca15c001c,0x01fffffc01dc021e,0x0e0000fc81dc2338,0x00000000401c0219\n"
".quad 0x00000019221f843a,0x00000015211f841c,0x0200000071dc421c,0x000000a00081e738\n"
".quad 0x00c0008061600340,0x0000001471600348,0x0ac00007f1600360,0x0000002071e00331\n"
".quad 0x0000001441204358,0x00c00078715c0368,0x00c0007c519c0360,0x00c00004715c0358\n"
".quad 0x00000018411c4368,0x00000010511c0368,0x00c00004715c0368,0x8e0000fc41dc0358\n"
".quad 0x00c000045140031a,0x00000014011c4348,0x00000000001de768,0x0000000000000090\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x000000000c0c0400,0x0000100000000800\n"
".quad 0x00001100080a0400,0x1819030018002000,0xffffff000c170400,0x21f00000100002ff\n"
".quad 0xffffff000c170400,0x21f00000080001ff,0xffffff000c170400,0x21f00000000000ff\n"
".quad 0x0e00a800080d0400,0x005de40000000c00,0x001c042800440400,0x009de42c00000094\n"
".quad 0x00dc042800400020,0x001c232c00000084,0x209c237000c06000,0x011de47000c06000\n"
".quad 0x00dca32800400080,0x319c032006000008,0x015de42009c00040,0xf1dc432800480130\n"
".quad 0x641cc54800400093,0x211d008400000000,0x0100075000480101,0x009de450000004e0\n"
".quad 0x201c8428004800c0,0x209c031002000011,0x201c844800fffffc,0x011de41406000001\n"
".quad 0x001c0328004800b0,0x409c23080e000008,0x001c237000c06000,0x011de47000c06000\n"
".quad 0x001ca328004800a0,0x409c235000000008,0x001c237000c06000,0x015de47000c06000\n"
".quad 0x009ca32800480120,0x111d005000000008,0x01000750004800f1,0x015de450000002e0\n"
".quad 0x201c8428004800b0,0x511c031002000011,0x201c844800fffffc,0x015de41406000001\n"
".quad 0x001c0328004800a0,0x519c23080e000010,0x001c237000c06000,0x015de47000c06000\n"
".quad 0x009ca32800480110,0x011d002004000018,0x01000750004800e1,0x201c845000000160\n"
".quad 0x015de41002000011,0x011de428004000a0,0x201c8428004800a0,0x411c031406000001\n"
".quad 0x001c034800fffffc,0x311c03080e000010,0x209c03200bc00020,0xf15c434800000000\n"
".quad 0x409ca548004000b3,0x001de79400000000,0x401c038000000000,0x519c036000c00004\n"
".quad 0x001c036000c00004,0x619c035800c00060,0x001c035800c00060,0x01dc034800fffffc\n"
".quad 0x619c031a0ec003f4,0x61dc034800fffffc,0x0021e71a20c003f4,0x41dc804000000520\n"
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
".quad 0x0000009000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x080c040000000000,0x0000080000000000\n"
".quad 0x00001700080a0400,0x1019030010002000,0xffffff000c170400,0x21f00000080001ff\n"
".quad 0xffffff000c170400,0x21f00000000000ff,0x0e00a800080d0400,0x005de40000000c00\n"
".quad 0x001c042800440400,0x009de42c00000094,0x011c042800400020,0x001c232c00000084\n"
".quad 0x209c237000c06000,0x00dde47000c06000,0x001ca32800400080,0x41dc032008000008\n"
".quad 0x021c03190e0000fc,0xf25c432007c00020,0x01dc234800400093,0x411e031a000000fc\n"
".quad 0x809ca56000c00008,0x8180a58400000000,0x409c8587ffffffe0,0xf18085c900000010\n"
".quad 0xffdc04c900000003,0x01dc2350ee0000ff,0x000007190e0000fc,0x0001e76000000100\n"
".quad 0x411c854000000060,0x41dc03c100000000,0x0001f4190e000008,0x011de44000000000\n"
".quad 0x211c032800400120,0xf15c432009c00010,0x401c954800400133,0x311c869400000000\n"
".quad 0x321d069003c000fc,0xffdc049003c101fc,0x031de250ee0000ff,0x009c031800000040\n"
".quad 0xf0dc4320198000e0,0x031c0348004000f3,0xf35c432019800100,0x211cc54800400113\n"
".quad 0xc21cc59400000000,0x001de79400000000,0x0000008000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x180c040000000000,0x0000080000000000,0x0000180000001000,0x0000280000002000\n"
".quad 0x0000220008020400,0x0802040000000100,0x0000000000002100,0x00001500080a0400\n"
".quad 0x3019030030002000,0xffffff000c170400,0x21f00000280005ff,0xffffff000c170400\n"
".quad 0x21f00000200004ff,0xffffff000c170400,0x21f00000180003ff,0xffffff000c170400\n"
".quad 0x21f00000100002ff,0xffffff000c170400,0x21f00000080001ff,0xffffff000c170400\n"
".quad 0x21f00000000000ff,0x03002400080d0400,0x005de40000000200,0x001c042800440400\n"
".quad 0x009de42c00000094,0x00dc042800400020,0x001c232c00000084,0x209c237000c06000\n"
".quad 0x0c9ca37000c06000,0x015de42006000008,0x251c862800480110,0x241d069001c000ff\n"
".quad 0x411d009003c101ff,0x01000750004800e1,0x201c8450000019c0,0x015de41002000011\n"
".quad 0x511d002800480120,0x209c8450004800f1,0x0100071406000001,0x201c845000001920\n"
".quad 0x015de41002000011,0x611d002800480130,0x20dc845000480101,0x0100071406000001\n"
".quad 0x201c845000001880,0x25dc031002000011,0x26dc034800fffffc,0x071de24800c00008\n"
".quad 0x075de41bfffffffc,0x079de428000000fc,0x07dde428000000fc,0x209c8428000000fc\n"
".quad 0x0b1de21406000001,0x0000071bfffffffc,0x0b5de46000000f60,0x001de4280000005c\n"
".quad 0xd1dc234000000000,0x000007188e0000fe,0x0001e76000000e00,0x001de44000000240\n"
".quad 0x001c0328004800a0,0xd1dc034800fffffc,0x0001e71a0e000002,0x311c0340000001c0\n"
".quad 0x41dc2348000000b0,0x0001e7188e0000fc,0x015de44000000160,0x515c0328004800b0\n"
".quad 0x41dc034800fffffc,0x0001e71a0e000014,0x219c0340000000e0,0x61dc234800000070\n"
".quad 0x0001e7188e0000fc,0x01dde44000000080,0x71dc0328004800c0,0x61dc034800fffffc\n"
".quad 0x0001e7198e00001c,0x0b9de44000000060,0x0bdde428000000fc,0x0c1df428000000fc\n"
".quad 0x619c0328000000fc,0x021de4080e00001c,0x81dc2328004800b0,0x619c237000c06000\n"
".quad 0x021de47000c06000,0x619ca328004800a0,0x41dc03500000001c,0x815c23080e000014\n"
".quad 0x611c237000c06000,0x719c237000c06000,0x411ca37000c06000,0xd1dc035000000014\n"
".quad 0x601ca3080e000002,0x0cdc032008000014,0x3d1d06480000001c,0x41dc0390004202ff\n"
".quad 0x0001e71a8effffff,0x0b9de44000000060,0x0bdde428000000fc,0x0c1df428000000fc\n"
".quad 0xf1dc0328000000fc,0x0001e7190e480153,0x0c5de44000000800,0x00000728000000d0\n"
".quad 0x0b9de46800000820,0x0bdde428000000fc,0x0c1de428000000fc,0x101d0628000000fc\n"
".quad 0x31dc0390004303ff,0x0001e71a8e000003,0x11dc03a800000000,0x000007190e0000cb\n"
".quad 0x0001f46000000620,0x111c864000000000,0x161d069001c000ff,0x5d5d009001c101ff\n"
".quad 0x4d9d005000000054,0x011de45000000050,0x501c002800480090,0x6e5d0058000000d7\n"
".quad 0x4ddc005000000058,0x601c005000480090,0x911c0030000000db,0x01000730000000e7\n"
".quad 0x71dc005000002500,0x000007220e000013,0x0e1de46000000400,0x0021e72800000010\n"
".quad 0x861d004000000360,0x965d005000000041,0xa69d005000000045,0x0100075000000049\n"
".quad 0x501c005000001b40,0x615c005800000013,0x721d005800000013,0x919c0050000000e3\n"
".quad 0x911c005800000001,0x829c005800000013,0x51dc005800480171,0x92dc00300c000060\n"
".quad 0x819c005800480171,0x425c005800480160,0xa1dc00300e000068,0x521e005800480171\n"
".quad 0x029e003014000018,0x515e003016000018,0x001e003030000024,0x419e003032000024\n"
".quad 0x425e00300e000018,0x511c003034000024,0x015c003010480180,0x919c003014480180\n"
".quad 0x601c00300c480180,0x511c003008480193,0x915c10300a480193,0x015de4300c480193\n"
".quad 0x011de428000000fc,0x001df428000000fc,0x0c1c0028000000fc,0x4bdc0050000000c0\n"
".quad 0x5b9c1050000000bc,0x1c5c0350000000b8,0x401c034800c00007,0x11dc034800480153\n"
".quad 0x0021e71a8e000003,0x001de7a800000000,0x0b9de44003fff8a0,0x0bdde428000000fc\n"
".quad 0x0c1df428000000fc,0x001df428000000fc,0xdb5c034000000000,0x07dc004800c00006\n"
".quad 0xd1dc23500000007f,0xf79c001a8e00006e,0xe75c00500000007a,0x0001e75000000076\n"
".quad 0xcb1c134003fff100,0xc1dc234800c00006,0x0001e71a8ec0000a,0xc71c034003fff040\n"
".quad 0xc1dc234800c00005,0x0001e71a8ec00009,0x509e004003ffefc0,0x40de005000480011\n"
".quad 0x011de45000480001,0x201c002800480040,0x651e005800000008,0x301c005000480021\n"
".quad 0x455c00300000000c,0x411c005000480090,0x0100073000000051,0x51dc005000001ca0\n"
".quad 0x000007220e000011,0x059de460000003a0,0x0021e72800000010,0x0100074000000300\n"
".quad 0x201c005000001340,0x519d005800000010,0x309c005000000059,0x015c005800000010\n"
".quad 0x40dc005800000044,0x619c005800000011,0x211f005800480160,0x01dc00300a000040\n"
".quad 0x215c005800000018,0x321c005800000018,0x311e005800000018,0x119c003008000048\n"
".quad 0x015c00300e480171,0x221c00300a480171,0x209c003010480171,0x01dc003020000010\n"
".quad 0x30dc003022000010,0x201c003024000010,0x709c00300a480180,0x30dc00300c480180\n"
".quad 0x201d043010480180,0x209d041000000001,0x20dd141000000009,0x00dde4100000000d\n"
".quad 0x009de428000000fc,0x001df428000000fc,0x011de428000000fc,0x001c002800400100\n"
".quad 0x219c03500000007c,0x209c002009c00023,0xf1dc435000000078,0x109c004800400113\n"
".quad 0x611ca55000000009,0x011de48400000000,0x519c0328004000a0,0x011c002009c00040\n"
".quad 0xf1dc435000000001,0x301c0048004000b3,0x611c855000000074,0x201c009400000000\n"
".quad 0x609c855000000001,0x601c859400000010,0x64dc859400000020,0x001de79400000030\n"
".quad 0x401c038000000000,0x519c036000c00004,0x001c036000c00004,0x619c035800c00060\n"
".quad 0x01dc035800c00060,0x621c034800fffffc,0x71dc034800fffffc,0x81dc031a0ec003f4\n"
".quad 0x0021e71a20c003f4,0x41dc804000000520,0x201c44298edfe000,0x0021e71080000011\n"
".quad 0x51dc804000000060,0x219c44298edfe000,0x0001e71080000015,0x411c204000000040\n"
".quad 0x001de75000000014,0x425c034000000b80,0x529c036000c00004,0x93dc036000c00004\n"
".quad 0xa5dc03190e0000fc,0x11dc04190e0000fc,0x0001e70c0e000008,0x07dc004000000080\n"
".quad 0x61dc00290edfe000,0x002de7290edfe000,0x0021e74000000080,0x001de24000000060\n"
".quad 0x011c001bff000000,0x001de7c800000014,0x01dc0440000009e0,0x0021e70c0e000044\n"
".quad 0x501c834000000060,0x011c026800000010,0x001de73a00000000,0x31dc044000000940\n"
".quad 0x0021e70c0e000048,0x501c834000000080,0x001c026800000010,0x011c423a00000000\n"
".quad 0x001de739fe000000,0x71dc234000000880,0x83dc231b0e0000fc,0x0021e21b0e0000fc\n"
".quad 0x4120001bffffff00,0x0001e4307ed7e000,0x0005e728000000fc,0x515c004000000080\n"
".quad 0x001c03307ed7e000,0x001de74800c00100,0x001de44000000020,0x819c0328000000fc\n"
".quad 0x619ee34800fffe08,0x715c034100000014,0x625c004800fffe08,0x511ee3c800000010\n"
".quad 0x415c004100000010,0x71dd03307e000024,0x629e004800000020,0xa15c003008000014\n"
".quad 0x619e00300a000024,0x611c003008000014,0x429c03300a000024,0xa29c036000c00004\n"
".quad 0x71dc035800c00060,0x01dc034800000028,0x701c03480000001c,0x01dc034800fffffc\n"
".quad 0x0001e71a0ec003f4,0x701d034000000060,0x011ee34800000028,0x001de74000000010\n"
".quad 0x71dc2340000004a0,0x0001e7198ec003f8,0x401c024000000060,0x011c423a00000000\n"
".quad 0x001de739fe000000,0x71dc234000000400,0x0001e71a0e0000fc,0x71dc2340000003c0\n"
".quad 0x0001e71b0effffa0,0x411c024000000040,0x001de73a00000000,0x629c004000000340\n"
".quad 0x621c00310a000024,0x601c00308a000024,0x225f84318a000024,0xa15c001c0000001d\n"
".quad 0x019c021e8e000020,0x91dc233801fffffc,0x401c02190e0000fc,0x221f843a00000000\n"
".quad 0x211f841c0000001d,0x625c421c00000015,0x0081e73802000000,0x71600340000000a0\n"
".quad 0x9160034800c00080,0xf160036000000014,0x926003310ac00007,0x4120435800000020\n"
".quad 0x915c036800000014,0x519c036000c00078,0x915c035800c0007c,0x411c436800c00004\n"
".quad 0x511c036800000018,0x915c036800000010,0x41dc035800c00004,0x5140031a8e0000fc\n"
".quad 0x011c434800c00004,0x001de76800000014,0x401c039000000000,0x001c036000c00004\n"
".quad 0x015c035800c00060,0x215c044800c0000c,0x51dc031c00000014,0x0001e7198ec0000c\n"
".quad 0x401c004000000080,0x411c00c800000010,0x011e003000800014,0x001de73000000010\n"
".quad 0x01dc034000000760,0x0001e71a8e0000fc,0x401c024000000300,0x015c033801fffffc\n"
".quad 0x515e037800000000,0x519c034800c0007c,0x61dc034800ffffdc,0x0001e7198ec00004\n"
".quad 0x411c004000000040,0x001de7c800000010,0x519c034000000620,0x411c024800ffffe0\n"
".quad 0x001c033a00000000,0x001c026000000018,0x001c423801fffffc,0x019c0038fe000000\n"
".quad 0x001c00c800000010,0x601e00300c800014,0x001c02300c000000,0x019c033801fffffc\n"
".quad 0x515d03110e0000fc,0x515c034800000018,0x515c034800c003d0,0x411c436000c0005c\n"
".quad 0x011c436800000014,0x001de76800000010,0x015c034000000420,0x51dc034800fffc0c\n"
".quad 0x0001e71a0ec00004,0x419c0240000003a0,0x61dc423801fffffc,0x02dde238fe000000\n"
".quad 0x721c00180000000c,0xb2dc03c800000010,0x71dc006000000014,0x411c023010800014\n"
".quad 0x825e003a00000000,0x929c02309000001c,0x821e003801fffffc,0xa29c42311000001c\n"
".quad 0xb1dc033802000000,0x91dc006800000028,0x71dc032e8e000020,0xf21c045800000014\n"
".quad 0x515c032010c00007,0x725c036800000028,0x815c436800c00008,0x91dc036800000014\n"
".quad 0x021c031a8e0000fc,0x51dc034800fffc10,0x701c031aa00000fc,0xa15c036800c00004\n"
".quad 0x01dc235800000020,0x5140031a800000fc,0x501c034800c00004,0x001c036000c00004\n"
".quad 0x011c43310c000014,0x001de76800000010,0x411c004000000020,0x001de7c800000010\n"
".quad 0x401c029000000000,0x01dc030bcc000000,0x0001e7198e400024,0x401c024000000220\n"
".quad 0x01dc2339fffffffc,0x0021e71a8e0000fc,0x41dc004000000300,0x0021e7288e0000fc\n"
".quad 0x011de24000000040,0x001de719fffffffc,0x41dc804000000280,0x201c44298edfe000\n"
".quad 0x0001e71080000011,0x411c204000000040,0x001de75000cfe000,0x01dc0040000001e0\n"
".quad 0x0001e7290edfe000,0x411c0040000001a0,0x71dc04307ed7e000,0x001de70c0e00001c\n"
".quad 0xf1dc044000000020,0x401c000c0e00001c,0x015c40c800000014,0x001c405800000010\n"
".quad 0x519e005800cfc000,0x515c003000800034,0x019c00300a000018,0x501e003000000018\n"
".quad 0x011c003008000014,0x410040300a000018,0x001de75800cbe000,0x0000009000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000010000000000,0x7fffffbf80000000,0x180c043f00000072\n"
".quad 0x0000080000000000,0x0000180000001000,0x0000280000002000,0x0000220008020400\n"
".quad 0x0802040000000100,0x0000030000002500,0x0000260008020400,0x0802040000000200\n"
".quad 0x0000000000002100,0x00001300080a0400,0x3019030030002000,0xffffff000c170400\n"
".quad 0x21f00000280005ff,0xffffff000c170400,0x21f00000200004ff,0xffffff000c170400\n"
".quad 0x21f00000180003ff,0xffffff000c170400,0x21f00000100002ff,0xffffff000c170400\n"
".quad 0x21f00000080001ff,0xffffff000c170400,0x21f00000000000ff,0x2601c800080d0400\n"
".quad 0x0000000000002000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x1007040000000000,0xffffff0000002600\n"
".quad 0xffffffffffffffff,0x00002500100704ff,0xffffffffffffff00,0x100704ffffffffff\n"
".quad 0xffffff0000002400,0xffffffffffffffff,0x00002300100704ff,0xffffffffffffff00\n"
".quad 0x100704ffffffffff,0xffffff0000002200,0xffffffffffffffff,0x00002100100704ff\n"
".quad 0xffffffffffffff00,0x081204ffffffffff,0x0000000000002000,0x0000200008110400\n"
".quad 0x0812040000000000,0x0000000000001a00,0x00001a0008110400,0x0812040000000000\n"
".quad 0x0000000000001f00,0x00001f0008110400,0x0812040000000000,0x0000000000001a00\n"
".quad 0x00001a0008110400,0x0812040000000000,0x0000000000001e00,0x00001e0008110400\n"
".quad 0x0812040000000000,0x0000000000001d00,0x00001d0008110400,0x0812040000000000\n"
".quad 0x0000000000001c00,0x00001c0008110400,0x0812040000000000,0x0000000000001b00\n"
".quad 0x00001b0008110400,0x0812040000000000,0x0000000000001a00,0x00001a0008110400\n"
".quad 0x0812040000000000,0x0000000000001900,0x0000190008110400,0x0000000000000000\n"
".quad 0x0000000500000006,0x0000000000002f20,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000001c0,0x00000000000001c0,0x0000000000000004,0x0000200560000000\n"
".quad 0x0000000000000e99,0x0000000000000000,0x0000000000000000,0x0000000000000270\n"
".quad 0x0000000000000270,0x0000000000000004,0x00001f0560000000,0x0000000000001109\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000000000005e4,0x00000000000005e4\n"
".quad 0x0000000000000004,0x00001e0560000000,0x00000000000016ed,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000590,0x0000000000000590,0x0000000000000004\n"
".quad 0x00001d0560000000,0x0000000000001c7d,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000238,0x0000000000000238,0x0000000000000004,0x00001d0660000000\n"
".quad 0x0000000000001eb5,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000404,0x0000000000000004,0x0000190560000000,0x0000000000001eb5\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000e90,0x0000000000000e90\n"
".quad 0x0000000000000004,0x0000000500000001,0x0000000000002d45,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000070,0x0000000000000070,0x0000000000000004\n"
".quad 0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[1565];

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
".quad 0x31315a5f5f667465,0x64697247636c6163,0x616f6c6636736f50,0x20295d32315b3474\n"
".quad 0x636c616331315a5f,0x36736f5064697247,0x28203474616f6c66,0x2e206d617261702e\n"
".quad 0x3631206e67696c61,0x635f5f2038622e20,0x666d726170616475,0x616331315a5f5f31\n"
".quad 0x6f5064697247636c,0x3474616f6c663673,0x090a0a295d36315b,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323375,0x5f5f667465726164\n"
".quad 0x47636c616332315a,0x3468736148646972,0x5a5f202933746e69,0x7247636c61633231\n"
".quad 0x6934687361486469,0x61702e282033746e,0x696c612e206d6172,0x38622e2034206e67\n"
".quad 0x70616475635f5f20,0x5a5f5f31666d7261,0x7247636c61633231,0x6934687361486469\n"
".quad 0x295d32315b33746e,0x697369762e090a0a,0x6e75662e20656c62,0x646137315a5f2063\n"
".quad 0x6c63697472615064,0x346c6c65436f5465,0x536a506a33746e69,0x7261702e28205f30\n"
".quad 0x67696c612e206d61,0x2038622e2034206e,0x6170616475635f5f,0x315a5f5f31666d72\n"
".quad 0x7472615064646137,0x65436f54656c6369,0x6a33746e69346c6c,0x32315b5f30536a50\n"
".quad 0x617261702e202c5d,0x5f203233752e206d,0x726170616475635f,0x37315a5f5f32666d\n"
".quad 0x6974726150646461,0x6c65436f54656c63,0x506a33746e69346c,0x702e202c5f30536a\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x5f5f33666d726170,0x615064646137315a\n"
".quad 0x6f54656c63697472,0x746e69346c6c6543,0x2c5f30536a506a33,0x206d617261702e20\n"
".quad 0x635f5f203436752e,0x666d726170616475,0x646137315a5f5f34,0x6c63697472615064\n"
".quad 0x346c6c65436f5465,0x536a506a33746e69,0x762e090a0a295f30,0x2e20656c62697369\n"
".quad 0x702e2820636e7566,0x6c612e206d617261,0x622e2034206e6769,0x616475635f5f2038\n"
".quad 0x315a5f5f66746572,0x6564696c6c6f6334,0x3673657265687053,0x5f533474616f6c66\n"
".quad 0x5b6666665f535f53,0x315a5f20295d3231,0x6564696c6c6f6334,0x3673657265687053\n"
".quad 0x5f533474616f6c66,0x206666665f535f53,0x206d617261702e28,0x31206e67696c612e\n"
".quad 0x5f5f2038622e2036,0x6d72617061647563,0x6334315a5f5f3166,0x70536564696c6c6f\n"
".quad 0x6c66367365726568,0x5f535f533474616f,0x36315b6666665f53,0x617261702e202c5d\n"
".quad 0x6e67696c612e206d,0x2038622e20363120,0x6170616475635f5f,0x315a5f5f32666d72\n"
".quad 0x6564696c6c6f6334,0x3673657265687053,0x5f533474616f6c66,0x5b6666665f535f53\n"
".quad 0x61702e202c5d3631,0x696c612e206d6172,0x622e203631206e67,0x616475635f5f2038\n"
".quad 0x5f5f33666d726170,0x696c6c6f6334315a,0x6572656870536564,0x3474616f6c663673\n"
".quad 0x66665f535f535f53,0x2e202c5d36315b66,0x612e206d61726170,0x203631206e67696c\n"
".quad 0x75635f5f2038622e,0x34666d7261706164,0x6c6f6334315a5f5f,0x656870536564696c\n"
".quad 0x616f6c6636736572,0x5f535f535f533474,0x2c5d36315b666666,0x206d617261702e20\n"
".quad 0x635f5f203233662e,0x666d726170616475,0x6f6334315a5f5f35,0x6870536564696c6c\n"
".quad 0x6f6c663673657265,0x535f535f53347461,0x702e202c6666665f,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f36666d726170,0x696c6c6f6334315a,0x6572656870536564\n"
".quad 0x3474616f6c663673,0x66665f535f535f53,0x617261702e202c66,0x5f203233662e206d\n"
".quad 0x726170616475635f,0x34315a5f5f37666d,0x536564696c6c6f63,0x6636736572656870\n"
".quad 0x535f533474616f6c,0x0a296666665f535f,0x62697369762e090a,0x636e75662e20656c\n"
".quad 0x6d617261702e2820,0x206e67696c612e20,0x5f5f2038622e2034,0x6674657261647563\n"
".quad 0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934,0x5f30533474616f6c\n"
".quad 0x505f31535f305350,0x5d32315b5f32536a,0x6f6331315a5f2029,0x6c65436564696c6c\n"
".quad 0x366a33746e69346c,0x30533474616f6c66,0x5f31535f3053505f,0x2e28205f32536a50\n"
".quad 0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862,0x5f31666d72617061\n"
".quad 0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69,0x505f30533474616f\n"
".quad 0x6a505f31535f3053,0x2c5d32315b5f3253,0x206d617261702e20,0x635f5f203233752e\n"
".quad 0x666d726170616475,0x6f6331315a5f5f32,0x6c65436564696c6c,0x366a33746e69346c\n"
".quad 0x30533474616f6c66,0x5f31535f3053505f,0x2e202c5f32536a50,0x612e206d61726170\n"
".quad 0x203631206e67696c,0x75635f5f2038622e,0x33666d7261706164,0x6c6f6331315a5f5f\n"
".quad 0x6c6c65436564696c,0x66366a33746e6934,0x5f30533474616f6c,0x505f31535f305350\n"
".quad 0x5d36315b5f32536a,0x6d617261702e202c,0x206e67696c612e20,0x5f2038622e203631\n"
".quad 0x726170616475635f,0x31315a5f5f34666d,0x436564696c6c6f63,0x33746e69346c6c65\n"
".quad 0x3474616f6c66366a,0x535f3053505f3053,0x5b5f32536a505f31,0x61702e202c5d3631\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x5a5f5f35666d7261,0x64696c6c6f633131\n"
".quad 0x6e69346c6c654365,0x616f6c66366a3374,0x3053505f30533474,0x32536a505f31535f\n"
".quad 0x617261702e202c5f,0x5f203436752e206d,0x726170616475635f,0x31315a5f5f36666d\n"
".quad 0x436564696c6c6f63,0x33746e69346c6c65,0x3474616f6c66366a,0x535f3053505f3053\n"
".quad 0x2c5f32536a505f31,0x206d617261702e20,0x635f5f203436752e,0x666d726170616475\n"
".quad 0x6f6331315a5f5f37,0x6c65436564696c6c,0x366a33746e69346c,0x30533474616f6c66\n"
".quad 0x5f31535f3053505f,0x2e202c5f32536a50,0x752e206d61726170,0x6475635f5f203436\n"
".quad 0x5f38666d72617061,0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69\n"
".quad 0x505f30533474616f,0x6a505f31535f3053,0x2e090a0a295f3253,0x20656c6269736976\n"
".quad 0x2e2820636e75662e,0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862\n"
".quad 0x5a5f5f6674657261,0x64696c6c6f633231,0x6934326c6c654365,0x6f6c66366a33746e\n"
".quad 0x53505f3053347461,0x7535505f31535f30,0x315b6a5032746e69,0x32315a5f20295d32\n"
".quad 0x436564696c6c6f63,0x746e6934326c6c65,0x74616f6c66366a33,0x5f3053505f305334\n"
".quad 0x6e697535505f3153,0x702e28206a503274,0x6c612e206d617261,0x622e2034206e6769\n"
".quad 0x616475635f5f2038,0x5f5f31666d726170,0x696c6c6f6332315a,0x34326c6c65436564\n"
".quad 0x6c66366a33746e69,0x505f30533474616f,0x35505f31535f3053,0x5b6a5032746e6975\n"
".quad 0x61702e202c5d3231,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261\n"
".quad 0x64696c6c6f633231,0x6934326c6c654365,0x6f6c66366a33746e,0x53505f3053347461\n"
".quad 0x7535505f31535f30,0x202c6a5032746e69,0x2e206d617261702e,0x3631206e67696c61\n"
".quad 0x635f5f2038622e20,0x666d726170616475,0x6f6332315a5f5f33,0x6c65436564696c6c\n"
".quad 0x6a33746e6934326c,0x533474616f6c6636,0x31535f3053505f30,0x32746e697535505f\n"
".quad 0x202c5d36315b6a50,0x2e206d617261702e,0x3631206e67696c61,0x635f5f2038622e20\n"
".quad 0x666d726170616475,0x6f6332315a5f5f34,0x6c65436564696c6c,0x6a33746e6934326c\n"
".quad 0x533474616f6c6636,0x31535f3053505f30,0x32746e697535505f,0x202c5d36315b6a50\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x35666d7261706164,0x6c6f6332315a5f5f\n"
".quad 0x6c6c65436564696c,0x366a33746e693432,0x30533474616f6c66,0x5f31535f3053505f\n"
".quad 0x5032746e69753550,0x617261702e202c6a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x32315a5f5f36666d,0x436564696c6c6f63,0x746e6934326c6c65,0x74616f6c66366a33\n"
".quad 0x5f3053505f305334,0x6e697535505f3153,0x702e202c6a503274,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x5f5f37666d726170,0x696c6c6f6332315a,0x34326c6c65436564\n"
".quad 0x6c66366a33746e69,0x505f30533474616f,0x35505f31535f3053,0x2c6a5032746e6975\n"
".quad 0x206d617261702e20,0x635f5f203436752e,0x666d726170616475,0x6f6332315a5f5f38\n"
".quad 0x6c65436564696c6c,0x6a33746e6934326c,0x533474616f6c6636,0x31535f3053505f30\n"
".quad 0x32746e697535505f,0x2f2f090a0a296a50,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x202f2f090a2d2d2d,0x6e696c69706d6f43,0x742f706d742f2067\n"
".quad 0x30305f746678706d,0x305f656561303030,0x2d30303030303030,0x6369747261705f37\n"
".quad 0x6e72656b5f73656c,0x2e337070632e6c65,0x2f706d742f282069,0x75332e2349426363\n"
".quad 0x2f090a296f484136,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f090a0a2d2d2d2d,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x736e6f6974704f20,0x2d2d2d2f2f090a3a,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x615420202f2f090a,0x7874703a74656772\n"
".quad 0x6d733a415349202c,0x646e45202c30325f,0x7474696c3a6e6169,0x6e696f50202c656c\n"
".quad 0x657a695320726574,0x202f2f090a34363a,0x704f2809334f2d20,0x6974617a696d6974\n"
".quad 0x6c6576656c206e6f,0x2d20202f2f090a29,0x7562654428093067,0x296c6576656c2067\n"
".quad 0x6d2d20202f2f090a,0x726f706552280932,0x6f73697664612074,0x2f090a2973656972\n"
".quad 0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2e090a0a2d2d2d2d\n"
".quad 0x22093109656c6966,0x646e616d6d6f633c,0x0a223e656e696c2d,0x3209656c69662e09\n"
".quad 0x742f706d742f2209,0x30305f746678706d,0x305f656561303030,0x2d30303030303030\n"
".quad 0x6369747261705f36,0x6e72656b5f73656c,0x66616475632e6c65,0x0a227570672e3265\n"
".quad 0x3309656c69662e09,0x2f656d6f682f2209,0x632f6c616d726f6e,0x2f74756f6b636568\n"
".quad 0x6f6c65636f757067,0x2d73747365742f74,0x2f312e322d787470,0x2f322e3261647563\n"
".quad 0x61702f7374736574,0x2f73656c63697472,0x656c636974726170,0x6c656e72656b5f73\n"
".quad 0x2e090a226875632e,0x22093409656c6966,0x62696c2f7273752f,0x3836692f6363672f\n"
".quad 0x2d78756e696c2d36,0x2e342e342f756e67,0x64756c636e692f35,0x6665646474732f65\n"
".quad 0x69662e090a22682e,0x752f22093509656c,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x7472632f6564756c,0x5f6563697665642f,0x2e656d69746e7572\n"
".quad 0x6c69662e090a2268,0x73752f2209360965,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x74736f682f656475,0x73656e696665645f,0x69662e090a22682e\n"
".quad 0x752f22093709656c,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x6975622f6564756c,0x7079745f6e69746c,0x2e090a22682e7365,0x22093809656c6966\n"
".quad 0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962,0x642f6564756c636e\n"
".quad 0x79745f6563697665,0x090a22682e736570,0x093909656c69662e,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x745f726576697264\n"
".quad 0x0a22682e73657079,0x3109656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6361667275732f65,0x2e73657079745f65\n"
".quad 0x6c69662e090a2268,0x752f220931310965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x7865742f6564756c,0x7079745f65727574,0x2e090a22682e7365\n"
".quad 0x09323109656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x745f726f74636576,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220933,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x6563697665642f65,0x5f68636e75616c5f,0x6574656d61726170,0x2e090a22682e7372\n"
".quad 0x09343109656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x726f74732f747263,0x73616c635f656761,0x662e090a22682e73\n"
".quad 0x2209353109656c69,0x636e692f7273752f,0x7469622f6564756c,0x2e73657079742f73\n"
".quad 0x6c69662e090a2268,0x752f220936310965,0x756c636e692f7273,0x2e656d69742f6564\n"
".quad 0x6c69662e090a2268,0x682f220937310965,0x6d726f6e2f656d6f,0x6b636568632f6c61\n"
".quad 0x6f7570672f74756f,0x65742f746f6c6563,0x2d7874702d737473,0x616475632f312e32\n"
".quad 0x747365742f322e32,0x6369747261702f73,0x747261702f73656c,0x656b5f73656c6369\n"
".quad 0x2275632e6c656e72,0x09656c69662e090a,0x7273752f22093831,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x6f6d6d6f632f6564,0x6974636e75665f6e\n"
".quad 0x090a22682e736e6f,0x393109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x75665f6874616d2f,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220930320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x74616d2f6564756c,0x6174736e6f635f68,0x090a22682e73746e\n"
".quad 0x313209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x5f6563697665642f,0x6e6f6974636e7566,0x662e090a22682e73\n"
".quad 0x2209323209656c69,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x732f6564756c636e,0x6f74615f31315f6d,0x636e75665f63696d,0x22682e736e6f6974\n"
".quad 0x09656c69662e090a,0x7273752f22093332,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x32315f6d732f6564,0x5f63696d6f74615f,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209343209656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x732f6564756c636e,0x756f645f33315f6d,0x636e75665f656c62\n"
".quad 0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093532,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x30325f6d732f6564,0x5f63696d6f74615f\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209363209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x732f6564756c636e,0x746e695f30325f6d\n"
".quad 0x2e736369736e6972,0x6c69662e090a2268,0x752f220937320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x7275732f6564756c,0x6e75665f65636166\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209383209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x747865742f656475,0x637465665f657275\n"
".quad 0x6974636e75665f68,0x090a22682e736e6f,0x393209656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x75665f6874616d2f\n"
".quad 0x5f736e6f6974636e,0x337874705f6c6264,0x632e090a0a22682e,0x6c612e2074736e6f\n"
".quad 0x2e203631206e6769,0x6d61726170203862,0x0a3b5d3231315b73,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x6d617261702e2820,0x206e67696c612e20,0x5f5f2038622e2034\n"
".quad 0x6674657261647563,0x6c616331315a5f5f,0x736f506469724763,0x5b3474616f6c6636\n"
".quad 0x315a5f20295d3231,0x697247636c616331,0x6f6c6636736f5064,0x61702e2820347461\n"
".quad 0x696c612e206d6172,0x622e203631206e67,0x616475635f5f2038,0x5f5f31666d726170\n"
".quad 0x47636c616331315a,0x6636736f50646972,0x36315b3474616f6c,0x2e090a7b090a295d\n"
".quad 0x3233752e20676572,0x0a3b3e373c722520,0x662e206765722e09,0x33323c6625203233\n"
".quad 0x636f6c2e090a3b3e,0x3009313909373109,0x67656257444c240a,0x6331315a5f5f6e69\n"
".quad 0x5064697247636c61,0x74616f6c6636736f,0x702e646c090a3a34,0x3233662e6d617261\n"
".quad 0x5b202c3166250920,0x6170616475635f5f,0x315a5f5f31666d72,0x697247636c616331\n"
".quad 0x6f6c6636736f5064,0x0a3b5d302b347461,0x3233662e766f6d09,0x25202c3266250920\n"
".quad 0x2e646c090a3b3166,0x33662e6d61726170,0x202c336625092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f31666d7261,0x7247636c61633131,0x6c6636736f506469,0x3b5d342b3474616f\n"
".quad 0x33662e766f6d090a,0x202c346625092032,0x646c090a3b336625,0x662e6d617261702e\n"
".quad 0x2c35662509203233,0x616475635f5f5b20,0x5f5f31666d726170,0x47636c616331315a\n"
".quad 0x6636736f50646972,0x5d382b3474616f6c,0x662e766f6d090a3b,0x2c36662509203233\n"
".quad 0x2e090a3b35662520,0x3909373109636f6c,0x2e646c090a300934,0x33662e74736e6f63\n"
".quad 0x202c376625092032,0x2b736d617261705b,0x7573090a3b5d3036,0x2509203233662e62\n"
".quad 0x2c346625202c3866,0x6c090a3b37662520,0x2e74736e6f632e64,0x3966250920323366\n"
".quad 0x6d617261705b202c,0x090a3b5d32372b73,0x662e6e722e766964,0x3031662509203233\n"
".quad 0x25202c386625202c,0x747663090a3b3966,0x3233662e696d722e,0x662509203233662e\n"
".quad 0x30316625202c3131,0x722e747663090a3b,0x662e3233732e697a,0x2c31722509203233\n"
".quad 0x090a3b3131662520,0x09373109636f6c2e,0x646c090a30093539,0x662e74736e6f632e\n"
".quad 0x3231662509203233,0x6d617261705b202c,0x090a3b5d34362b73,0x203233662e627573\n"
".quad 0x25202c3331662509,0x32316625202c3666,0x6f632e646c090a3b,0x203233662e74736e\n"
".quad 0x5b202c3431662509,0x372b736d61726170,0x766964090a3b5d36,0x203233662e6e722e\n"
".quad 0x25202c3531662509,0x316625202c333166,0x2e747663090a3b34,0x2e3233662e696d72\n"
".quad 0x3166250920323366,0x3b35316625202c36,0x7a722e747663090a,0x33662e3233732e69\n"
".quad 0x202c327225092032,0x2e090a3b36316625,0x3909373109636f6c,0x2e646c090a300936\n"
".quad 0x33662e74736e6f63,0x2c37316625092032,0x736d617261705b20,0x73090a3b5d36352b\n"
".quad 0x09203233662e6275,0x6625202c38316625,0x3b37316625202c32,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c39316625,0x38362b736d617261,0x2e766964090a3b5d\n"
".quad 0x09203233662e6e72,0x6625202c30326625,0x39316625202c3831,0x722e747663090a3b\n"
".quad 0x662e3233662e696d,0x3132662509203233,0x0a3b30326625202c,0x697a722e74766309\n"
".quad 0x3233662e3233732e,0x25202c3372250920,0x7473090a3b313266,0x732e6d617261702e\n"
".quad 0x635f5f5b09203233,0x5f66746572616475,0x636c616331315a5f,0x36736f5064697247\n"
".quad 0x302b3474616f6c66,0x0a3b337225202c5d,0x3233732e766f6d09,0x25202c3472250920\n"
".quad 0x2e7473090a3b3172,0x33732e6d61726170,0x75635f5f5b092032,0x5f5f667465726164\n"
".quad 0x47636c616331315a,0x6636736f50646972,0x5d342b3474616f6c,0x090a3b347225202c\n"
".quad 0x203233732e766f6d,0x7225202c35722509,0x702e7473090a3b32,0x3233732e6d617261\n"
".quad 0x6475635f5f5b0920,0x5a5f5f6674657261,0x7247636c61633131,0x6c6636736f506469\n"
".quad 0x2c5d382b3474616f,0x72090a3b35722520,0x57444c240a3b7465,0x31315a5f5f646e65\n"
".quad 0x64697247636c6163,0x616f6c6636736f50,0x2f207d090a3a3474,0x616331315a5f202f\n"
".quad 0x6f5064697247636c,0x3474616f6c663673,0x697369762e090a0a,0x6e75662e20656c62\n"
".quad 0x617261702e282063,0x5f203233752e206d,0x746572616475635f,0x616332315a5f5f66\n"
".quad 0x614864697247636c,0x2933746e69346873,0x6c616332315a5f20,0x7361486469724763\n"
".quad 0x282033746e693468,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x31666d7261706164,0x6c616332315a5f5f,0x7361486469724763,0x315b33746e693468\n"
".quad 0x090a7b090a295d32,0x33752e206765722e,0x3e32323c72252032,0x09636f6c2e090a3b\n"
".quad 0x3009313031093731,0x67656257444c240a,0x6332315a5f5f6e69,0x4864697247636c61\n"
".quad 0x33746e6934687361,0x61702e646c090a3a,0x203233752e6d6172,0x5f5b202c31722509\n"
".quad 0x726170616475635f,0x32315a5f5f31666d,0x64697247636c6163,0x746e693468736148\n"
".quad 0x6d090a3b5d302b33,0x09203233732e766f,0x317225202c327225,0x61702e646c090a3b\n"
".quad 0x203233752e6d6172,0x5f5b202c33722509,0x726170616475635f,0x32315a5f5f31666d\n"
".quad 0x64697247636c6163,0x746e693468736148,0x6d090a3b5d342b33,0x09203233732e766f\n"
".quad 0x337225202c347225,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c35722509\n"
".quad 0x726170616475635f,0x32315a5f5f31666d,0x64697247636c6163,0x746e693468736148\n"
".quad 0x6d090a3b5d382b33,0x09203233732e766f,0x357225202c367225,0x09636f6c2e090a3b\n"
".quad 0x3009353031093731,0x6e6f632e646c090a,0x09203233752e7473,0x61705b202c377225\n"
".quad 0x5d34342b736d6172,0x6f632e646c090a3b,0x203233752e74736e,0x705b202c38722509\n"
".quad 0x30342b736d617261,0x632e646c090a3b5d,0x3233752e74736e6f,0x5b202c3972250920\n"
".quad 0x342b736d61726170,0x627573090a3b5d38,0x722509203233752e,0x2c397225202c3031\n"
".quad 0x6e696d090a3b3120,0x722509203233752e,0x2c367225202c3131,0x090a3b3031722520\n"
".quad 0x6f6c2e34326c756d,0x722509203233732e,0x31317225202c3231,0x090a3b377225202c\n"
".quad 0x6f6c2e34326c756d,0x722509203233732e,0x32317225202c3331,0x090a3b387225202c\n"
".quad 0x203233752e627573,0x25202c3431722509,0x090a3b31202c3772,0x203233752e6e696d\n"
".quad 0x25202c3531722509,0x34317225202c3472,0x34326c756d090a3b,0x203233732e6f6c2e\n"
".quad 0x25202c3631722509,0x387225202c353172,0x732e646461090a3b,0x3731722509203233\n"
".quad 0x202c33317225202c,0x73090a3b36317225,0x09203233752e6275,0x7225202c38317225\n"
".quad 0x6d090a3b31202c38,0x09203233752e6e69,0x7225202c39317225,0x3b38317225202c32\n"
".quad 0x33732e646461090a,0x2c30327225092032,0x25202c3731722520,0x7473090a3b393172\n"
".quad 0x752e6d617261702e,0x635f5f5b09203233,0x5f66746572616475,0x636c616332315a5f\n"
".quad 0x6873614864697247,0x202c5d33746e6934,0x72090a3b30327225,0x57444c240a3b7465\n"
".quad 0x32315a5f5f646e65,0x64697247636c6163,0x746e693468736148,0x2f2f207d090a3a33\n"
".quad 0x6c616332315a5f20,0x7361486469724763,0x0a0a33746e693468,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x5064646137315a5f,0x54656c6369747261,0x6e69346c6c65436f\n"
".quad 0x5f30536a506a3374,0x6d617261702e2820,0x206e67696c612e20,0x5f5f2038622e2034\n"
".quad 0x6d72617061647563,0x6137315a5f5f3166,0x6369747261506464,0x6c6c65436f54656c\n"
".quad 0x6a506a33746e6934,0x2c5d32315b5f3053,0x206d617261702e20,0x635f5f203233752e\n"
".quad 0x666d726170616475,0x646137315a5f5f32,0x6c63697472615064,0x346c6c65436f5465\n"
".quad 0x536a506a33746e69,0x7261702e202c5f30,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f33666d72,0x7472615064646137,0x65436f54656c6369,0x6a33746e69346c6c\n"
".quad 0x2e202c5f30536a50,0x752e206d61726170,0x6475635f5f203436,0x5f34666d72617061\n"
".quad 0x5064646137315a5f,0x54656c6369747261,0x6e69346c6c65436f,0x5f30536a506a3374\n"
".quad 0x722e090a7b090a29,0x203233752e206765,0x0a3b3e34333c7225,0x752e206765722e09\n"
".quad 0x313c647225203436,0x6f6c2e090a3b3e30,0x3331310937310963,0x6257444c240a3009\n"
".quad 0x315a5f5f6e696765,0x7472615064646137,0x65436f54656c6369,0x6a33746e69346c6c\n"
".quad 0x090a3a5f30536a50,0x6d617261702e646c,0x722509203233752e,0x75635f5f5b202c31\n"
".quad 0x31666d7261706164,0x64646137315a5f5f,0x656c636974726150,0x69346c6c65436f54\n"
".quad 0x30536a506a33746e,0x6d090a3b5d302b5f,0x09203233732e766f,0x317225202c327225\n"
".quad 0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c33722509,0x726170616475635f\n"
".quad 0x37315a5f5f31666d,0x6974726150646461,0x6c65436f54656c63,0x506a33746e69346c\n"
".quad 0x3b5d342b5f30536a,0x33732e766f6d090a,0x202c347225092032,0x646c090a3b337225\n"
".quad 0x752e6d617261702e,0x2c35722509203233,0x616475635f5f5b20,0x5f5f31666d726170\n"
".quad 0x615064646137315a,0x6f54656c63697472,0x746e69346c6c6543,0x2b5f30536a506a33\n"
".quad 0x766f6d090a3b5d38,0x722509203233732e,0x0a3b357225202c36,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x635f5f5b202c3772,0x666d726170616475,0x646137315a5f5f32\n"
".quad 0x6c63697472615064,0x346c6c65436f5465,0x536a506a33746e69,0x6f6d090a3b5d5f30\n"
".quad 0x2509203233732e76,0x3b377225202c3872,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c31647225,0x726170616475635f,0x37315a5f5f33666d,0x6974726150646461\n"
".quad 0x6c65436f54656c63,0x506a33746e69346c,0x090a3b5d5f30536a,0x203436732e766f6d\n"
".quad 0x25202c3264722509,0x646c090a3b316472,0x752e6d617261702e,0x3364722509203436\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x5064646137315a5f,0x54656c6369747261\n"
".quad 0x6e69346c6c65436f,0x5f30536a506a3374,0x2e766f6d090a3b5d,0x6472250920343673\n"
".quad 0x3b33647225202c34,0x3109636f6c2e090a,0x0a30093132310937,0x736e6f632e646c09\n"
".quad 0x2509203233752e74,0x7261705b202c3972,0x3b5d34342b736d61,0x33752e627573090a\n"
".quad 0x2c30317225092032,0x3b31202c39722520,0x6e6f632e646c090a,0x09203233752e7473\n"
".quad 0x705b202c31317225,0x38342b736d617261,0x2e627573090a3b5d,0x3172250920323375\n"
".quad 0x2c31317225202c32,0x2e646c090a3b3120,0x33752e74736e6f63,0x2c33317225092032\n"
".quad 0x736d617261705b20,0x73090a3b5d30342b,0x09203233752e6275,0x7225202c34317225\n"
".quad 0x090a3b31202c3331,0x203233752e6e696d,0x25202c3531722509,0x30317225202c3472\n"
".quad 0x752e6e696d090a3b,0x3631722509203233,0x25202c367225202c,0x696d090a3b323172\n"
".quad 0x2509203233752e6e,0x327225202c373172,0x0a3b34317225202c,0x6c2e34326c756d09\n"
".quad 0x2509203233732e6f,0x317225202c383172,0x3b33317225202c35,0x2e34326c756d090a\n"
".quad 0x09203233732e6f6c,0x7225202c39317225,0x3b397225202c3631,0x2e34326c756d090a\n"
".quad 0x09203233732e6f6c,0x7225202c30327225,0x33317225202c3931,0x732e646461090a3b\n"
".quad 0x3132722509203233,0x202c38317225202c,0x61090a3b30327225,0x09203233732e6464\n"
".quad 0x7225202c32327225,0x37317225202c3132,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x327225202c333272,0x63090a3b34202c32,0x752e3436752e7476,0x3564722509203233\n"
".quad 0x0a3b33327225202c,0x3436752e64646109,0x202c366472250920,0x7225202c35647225\n"
".quad 0x766f6d090a3b3264,0x722509203233752e,0x090a3b31202c3432,0x6464612e6d6f7461\n"
".quad 0x722509203233752e,0x6472255b202c3532,0x34327225202c5d36,0x732e766f6d090a3b\n"
".quad 0x3632722509203233,0x0a3b35327225202c,0x373109636f6c2e09,0x090a300936323109\n"
".quad 0x74736e6f632e646c,0x722509203233752e,0x7261705b202c3732,0x3b5d34382b736d61\n"
".quad 0x33752e627573090a,0x2c38327225092032,0x31202c3732722520,0x752e6e696d090a3b\n"
".quad 0x3932722509203233,0x202c36327225202c,0x6d090a3b38327225,0x33752e6f6c2e6c75\n"
".quad 0x2c30337225092032,0x25202c3232722520,0x6461090a3b373272,0x2509203233752e64\n"
".quad 0x327225202c313372,0x3b30337225202c39,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x31337225202c3233,0x7663090a3b34202c,0x33752e3436752e74,0x2c37647225092032\n"
".quad 0x090a3b3233722520,0x203436752e646461,0x25202c3864722509,0x647225202c376472\n"
".quad 0x752e7473090a3b34,0x6472255b09203233,0x7225202c5d302b38,0x636f6c2e090a3b38\n"
".quad 0x0937323109373109,0x0a3b746572090a30,0x5f646e6557444c24,0x5064646137315a5f\n"
".quad 0x54656c6369747261,0x6e69346c6c65436f,0x5f30536a506a3374,0x202f2f207d090a3a\n"
".quad 0x5064646137315a5f,0x54656c6369747261,0x6e69346c6c65436f,0x5f30536a506a3374\n"
".quad 0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063,0x6e67696c612e206d\n"
".quad 0x5f2038622e203420,0x746572616475635f,0x6f6334315a5f5f66,0x6870536564696c6c\n"
".quad 0x6f6c663673657265,0x535f535f53347461,0x5d32315b6666665f,0x6f6334315a5f2029\n"
".quad 0x6870536564696c6c,0x6f6c663673657265,0x535f535f53347461,0x702e28206666665f\n"
".quad 0x6c612e206d617261,0x2e203631206e6769,0x6475635f5f203862,0x5f31666d72617061\n"
".quad 0x6c6c6f6334315a5f,0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334\n"
".quad 0x202c5d36315b6666,0x2e206d617261702e,0x3631206e67696c61,0x635f5f2038622e20\n"
".quad 0x666d726170616475,0x6f6334315a5f5f32,0x6870536564696c6c,0x6f6c663673657265\n"
".quad 0x535f535f53347461,0x5d36315b6666665f,0x6d617261702e202c,0x206e67696c612e20\n"
".quad 0x5f2038622e203631,0x726170616475635f,0x34315a5f5f33666d,0x536564696c6c6f63\n"
".quad 0x6636736572656870,0x535f533474616f6c,0x315b6666665f535f,0x7261702e202c5d36\n"
".quad 0x67696c612e206d61,0x38622e203631206e,0x70616475635f5f20,0x5a5f5f34666d7261\n"
".quad 0x64696c6c6f633431,0x7365726568705365,0x533474616f6c6636,0x6666665f535f535f\n"
".quad 0x702e202c5d36315b,0x33662e206d617261,0x616475635f5f2032,0x5f5f35666d726170\n"
".quad 0x696c6c6f6334315a,0x6572656870536564,0x3474616f6c663673,0x66665f535f535f53\n"
".quad 0x617261702e202c66,0x5f203233662e206d,0x726170616475635f,0x34315a5f5f36666d\n"
".quad 0x536564696c6c6f63,0x6636736572656870,0x535f533474616f6c,0x202c6666665f535f\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x37666d7261706164,0x6c6f6334315a5f5f\n"
".quad 0x656870536564696c,0x616f6c6636736572,0x5f535f535f533474,0x0a7b090a29666666\n"
".quad 0x662e206765722e09,0x39373c6625203233,0x6765722e090a3b3e,0x2520646572702e20\n"
".quad 0x2e090a3b3e333c70,0x3209373109636f6c,0x444c240a30093930,0x5f5f6e6967656257\n"
".quad 0x696c6c6f6334315a,0x6572656870536564,0x3474616f6c663673,0x66665f535f535f53\n"
".quad 0x702e646c090a3a66,0x3233662e6d617261,0x5b202c3166250920,0x6170616475635f5f\n"
".quad 0x315a5f5f31666d72,0x6564696c6c6f6334,0x3673657265687053,0x5f533474616f6c66\n"
".quad 0x2b6666665f535f53,0x766f6d090a3b5d30,0x662509203233662e,0x0a3b316625202c32\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3366,0x666d726170616475\n"
".quad 0x6f6334315a5f5f31,0x6870536564696c6c,0x6f6c663673657265,0x535f535f53347461\n"
".quad 0x3b5d342b6666665f,0x33662e766f6d090a,0x202c346625092032,0x646c090a3b336625\n"
".quad 0x662e6d617261702e,0x2c35662509203233,0x616475635f5f5b20,0x5f5f31666d726170\n"
".quad 0x696c6c6f6334315a,0x6572656870536564,0x3474616f6c663673,0x66665f535f535f53\n"
".quad 0x6d090a3b5d382b66,0x09203233662e766f,0x356625202c366625,0x61702e646c090a3b\n"
".quad 0x203233662e6d6172,0x5f5b202c37662509,0x726170616475635f,0x34315a5f5f32666d\n"
".quad 0x536564696c6c6f63,0x6636736572656870,0x535f533474616f6c,0x302b6666665f535f\n"
".quad 0x2e766f6d090a3b5d,0x3866250920323366,0x090a3b376625202c,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c39,0x32666d7261706164,0x6c6f6334315a5f5f\n"
".quad 0x656870536564696c,0x616f6c6636736572,0x5f535f535f533474,0x0a3b5d342b666666\n"
".quad 0x3233662e766f6d09,0x202c303166250920,0x646c090a3b396625,0x662e6d617261702e\n"
".quad 0x3131662509203233,0x6475635f5f5b202c,0x5f32666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d382b6666\n"
".quad 0x203233662e766f6d,0x25202c3231662509,0x646c090a3b313166,0x662e6d617261702e\n"
".quad 0x3331662509203233,0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d302b6666\n"
".quad 0x203233662e766f6d,0x25202c3431662509,0x646c090a3b333166,0x662e6d617261702e\n"
".quad 0x3531662509203233,0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d342b6666\n"
".quad 0x203233662e766f6d,0x25202c3631662509,0x646c090a3b353166,0x662e6d617261702e\n"
".quad 0x3731662509203233,0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d382b6666\n"
".quad 0x203233662e766f6d,0x25202c3831662509,0x646c090a3b373166,0x662e6d617261702e\n"
".quad 0x3931662509203233,0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d302b6666\n"
".quad 0x203233662e766f6d,0x25202c3032662509,0x646c090a3b393166,0x662e6d617261702e\n"
".quad 0x3132662509203233,0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d342b6666\n"
".quad 0x203233662e766f6d,0x25202c3232662509,0x646c090a3b313266,0x662e6d617261702e\n"
".quad 0x3332662509203233,0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x090a3b5d382b6666\n"
".quad 0x203233662e766f6d,0x25202c3432662509,0x646c090a3b333266,0x662e6d617261702e\n"
".quad 0x3532662509203233,0x6475635f5f5b202c,0x5f35666d72617061,0x6c6c6f6334315a5f\n"
".quad 0x7265687053656469,0x74616f6c66367365,0x665f535f535f5334,0x6f6d090a3b5d6666\n"
".quad 0x2509203233662e76,0x326625202c363266,0x702e646c090a3b35,0x3233662e6d617261\n"
".quad 0x202c373266250920,0x70616475635f5f5b,0x5a5f5f36666d7261,0x64696c6c6f633431\n"
".quad 0x7365726568705365,0x533474616f6c6636,0x6666665f535f535f,0x2e766f6d090a3b5d\n"
".quad 0x3266250920323366,0x3b37326625202c38,0x7261702e646c090a,0x09203233662e6d61\n"
".quad 0x5f5b202c39326625,0x726170616475635f,0x34315a5f5f37666d,0x536564696c6c6f63\n"
".quad 0x6636736572656870,0x535f533474616f6c,0x3b5d6666665f535f,0x33662e766f6d090a\n"
".quad 0x2c30336625092032,0x090a3b3932662520,0x203233662e646461,0x25202c3133662509\n"
".quad 0x326625202c363266,0x2e627573090a3b38,0x3366250920323366,0x2c30316625202c32\n"
".quad 0x73090a3b34662520,0x09203233662e6275,0x6625202c33336625,0x0a3b326625202c38\n"
".quad 0x3233662e62757309,0x202c343366250920,0x6625202c32316625,0x2e6c756d090a3b36\n"
".quad 0x3366250920323366,0x2c32336625202c35,0x090a3b3233662520,0x662e6e722e616d66\n"
".quad 0x3633662509203233,0x202c33336625202c,0x6625202c33336625,0x616d66090a3b3533\n"
".quad 0x203233662e6e722e,0x25202c3733662509,0x336625202c343366,0x3b36336625202c34\n"
".quad 0x722e74727173090a,0x2509203233662e6e,0x336625202c383366,0x70746573090a3b37\n"
".quad 0x203233662e74672e,0x6625202c31702509,0x38336625202c3133,0x3170252140090a3b\n"
".quad 0x4c24092061726220,0x323832315f335f74,0x09636f6c2e090a3b,0x3009303332093731\n"
".quad 0x33662e627573090a,0x2c39336625092032,0x25202c3032662520,0x7573090a3b343166\n"
".quad 0x2509203233662e62,0x326625202c303466,0x3b36316625202c32,0x33662e627573090a\n"
".quad 0x2c31346625092032,0x25202c3432662520,0x6372090a3b383166,0x3233662e6e722e70\n"
".quad 0x202c323466250920,0x6d090a3b38336625,0x09203233662e6c75,0x6625202c33346625\n"
".quad 0x32346625202c3233,0x662e6c756d090a3b,0x3434662509203233,0x202c33336625202c\n"
".quad 0x6d090a3b32346625,0x09203233662e6c75,0x6625202c35346625,0x32346625202c3433\n"
".quad 0x662e6c756d090a3b,0x3634662509203233,0x202c30346625202c,0x66090a3b33346625\n"
".quad 0x33662e6e722e616d,0x2c37346625092032,0x25202c3434662520,0x346625202c393366\n"
".quad 0x2e616d66090a3b36,0x09203233662e6e72,0x6625202c38346625,0x31346625202c3534\n"
".quad 0x0a3b37346625202c,0x3233662e6c756d09,0x202c393466250920,0x6625202c34346625\n"
".quad 0x627573090a3b3834,0x662509203233662e,0x39336625202c3035,0x0a3b39346625202c\n"
".quad 0x3233662e6c756d09,0x202c313566250920,0x6625202c33346625,0x627573090a3b3834\n"
".quad 0x662509203233662e,0x30346625202c3235,0x0a3b31356625202c,0x3233662e6c756d09\n"
".quad 0x202c333566250920,0x6625202c35346625,0x627573090a3b3834,0x662509203233662e\n"
".quad 0x31346625202c3435,0x0a3b33356625202c,0x373109636f6c2e09,0x090a300939333209\n"
".quad 0x203233662e627573,0x25202c3535662509,0x336625202c313366,0x632e646c090a3b38\n"
".quad 0x3233662e74736e6f,0x202c363566250920,0x2b736d617261705b,0x756d090a3b5d3838\n"
".quad 0x2509203233662e6c,0x356625202c373566,0x3b35356625202c36,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c38356625,0x32392b736d617261,0x632e646c090a3b5d\n"
".quad 0x3233662e74736e6f,0x202c393566250920,0x2b736d617261705b,0x756d090a3b5d3639\n"
".quad 0x2509203233662e6c,0x346625202c303666,0x3b37356625202c34,0x33662e6c756d090a\n"
".quad 0x2c31366625092032,0x25202c3933662520,0x7573090a3b383566,0x2509203233662e62\n"
".quad 0x366625202c323666,0x3b30366625202c31,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x30356625202c3336,0x202c39356625202c,0x66090a3b32366625,0x33662e6e722e616d\n"
".quad 0x2c34366625092032,0x25202c3033662520,0x366625202c333366,0x2e6c756d090a3b33\n"
".quad 0x3666250920323366,0x2c33346625202c35,0x090a3b3735662520,0x203233662e6c756d\n"
".quad 0x25202c3636662509,0x356625202c303466,0x2e627573090a3b38,0x3666250920323366\n"
".quad 0x2c36366625202c37,0x090a3b3536662520,0x662e6e722e616d66,0x3836662509203233\n"
".quad 0x202c32356625202c,0x6625202c39356625,0x616d66090a3b3736,0x203233662e6e722e\n"
".quad 0x25202c3936662509,0x336625202c303366,0x3b38366625202c32,0x33662e6c756d090a\n"
".quad 0x2c30376625092032,0x25202c3534662520,0x756d090a3b373566,0x2509203233662e6c\n"
".quad 0x346625202c313766,0x3b38356625202c31,0x33662e627573090a,0x2c32376625092032\n"
".quad 0x25202c3137662520,0x6d66090a3b303766,0x3233662e6e722e61,0x202c333766250920\n"
".quad 0x6625202c34356625,0x32376625202c3935,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x336625202c343766,0x2c34336625202c30,0x090a3b3337662520,0x20696e752e617262\n"
".quad 0x315f335f744c2409,0x744c240a3b363230,0x3a323832315f335f,0x33662e766f6d090a\n"
".quad 0x2c34376625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c39366625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3666250920323366,0x3030306630202c34,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x30315f335f744c24,0x6f6c2e090a3a3632,0x3234320937310963\n"
".quad 0x2e766f6d090a3009,0x3766250920323366,0x3b34366625202c35,0x7261702e7473090a\n"
".quad 0x09203233662e6d61,0x72616475635f5f5b,0x34315a5f5f667465,0x536564696c6c6f63\n"
".quad 0x6636736572656870,0x535f533474616f6c,0x302b6666665f535f,0x3b35376625202c5d\n"
".quad 0x33662e766f6d090a,0x2c36376625092032,0x090a3b3936662520,0x6d617261702e7473\n"
".quad 0x5f5b09203233662e,0x746572616475635f,0x6f6334315a5f5f66,0x6870536564696c6c\n"
".quad 0x6f6c663673657265,0x535f535f53347461,0x2c5d342b6666665f,0x090a3b3637662520\n"
".quad 0x203233662e766f6d,0x25202c3737662509,0x7473090a3b343766,0x662e6d617261702e\n"
".quad 0x635f5f5b09203233,0x5f66746572616475,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5334,0x25202c5d382b6666,0x6572090a3b373766\n"
".quad 0x6557444c240a3b74,0x6334315a5f5f646e,0x70536564696c6c6f,0x6c66367365726568\n"
".quad 0x5f535f533474616f,0x090a3a6666665f53,0x315a5f202f2f207d,0x6564696c6c6f6334\n"
".quad 0x3673657265687053,0x5f533474616f6c66,0x0a6666665f535f53,0x6c61626f6c672e09\n"
".quad 0x6665727865742e20,0x54736f50646c6f20,0x6c672e090a3b7865,0x65742e206c61626f\n"
".quad 0x646c6f2066657278,0x0a3b7865546c6556,0x6c61626f6c672e09,0x6665727865742e20\n"
".quad 0x756f436469726720,0x786554737265746e,0x626f6c672e090a3b,0x727865742e206c61\n"
".quad 0x4364697267206665,0x3b786554736c6c65,0x697369762e090a0a,0x6e75662e20656c62\n"
".quad 0x617261702e282063,0x6e67696c612e206d,0x5f2038622e203420,0x746572616475635f\n"
".quad 0x6f6331315a5f5f66,0x6c65436564696c6c,0x366a33746e69346c,0x30533474616f6c66\n"
".quad 0x5f31535f3053505f,0x32315b5f32536a50,0x6331315a5f20295d,0x65436564696c6c6f\n"
".quad 0x6a33746e69346c6c,0x533474616f6c6636,0x31535f3053505f30,0x28205f32536a505f\n"
".quad 0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e,0x31666d7261706164\n"
".quad 0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934,0x5f30533474616f6c\n"
".quad 0x505f31535f305350,0x5d32315b5f32536a,0x6d617261702e202c,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x6331315a5f5f3266,0x65436564696c6c6f,0x6a33746e69346c6c\n"
".quad 0x533474616f6c6636,0x31535f3053505f30,0x202c5f32536a505f,0x2e206d617261702e\n"
".quad 0x3631206e67696c61,0x635f5f2038622e20,0x666d726170616475,0x6f6331315a5f5f33\n"
".quad 0x6c65436564696c6c,0x366a33746e69346c,0x30533474616f6c66,0x5f31535f3053505f\n"
".quad 0x36315b5f32536a50,0x617261702e202c5d,0x6e67696c612e206d,0x2038622e20363120\n"
".quad 0x6170616475635f5f,0x315a5f5f34666d72,0x6564696c6c6f6331,0x746e69346c6c6543\n"
".quad 0x74616f6c66366a33,0x5f3053505f305334,0x5f32536a505f3153,0x702e202c5d36315b\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x5f5f35666d726170,0x696c6c6f6331315a\n"
".quad 0x69346c6c65436564,0x6f6c66366a33746e,0x53505f3053347461,0x536a505f31535f30\n"
".quad 0x7261702e202c5f32,0x203436752e206d61,0x6170616475635f5f,0x315a5f5f36666d72\n"
".quad 0x6564696c6c6f6331,0x746e69346c6c6543,0x74616f6c66366a33,0x5f3053505f305334\n"
".quad 0x5f32536a505f3153,0x6d617261702e202c,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x6331315a5f5f3766,0x65436564696c6c6f,0x6a33746e69346c6c,0x533474616f6c6636\n"
".quad 0x31535f3053505f30,0x202c5f32536a505f,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x38666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934\n"
".quad 0x5f30533474616f6c,0x505f31535f305350,0x7b090a295f32536a,0x2e206765722e090a\n"
".quad 0x373c722520323375,0x65722e090a3b3e34,0x25203233662e2067,0x090a3b3e33383c66\n"
".quad 0x72702e206765722e,0x32313c7025206465,0x636f6c2e090a3b3e,0x0937353209373109\n"
".quad 0x656257444c240a30,0x31315a5f5f6e6967,0x436564696c6c6f63,0x33746e69346c6c65\n"
".quad 0x3474616f6c66366a,0x535f3053505f3053,0x3a5f32536a505f31,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563,0x6331315a5f5f3166\n"
".quad 0x65436564696c6c6f,0x6a33746e69346c6c,0x533474616f6c6636,0x31535f3053505f30\n"
".quad 0x302b5f32536a505f,0x2e766f6d090a3b5d,0x3272250920323373,0x090a3b317225202c\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x75635f5f5b202c33,0x31666d7261706164\n"
".quad 0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934,0x5f30533474616f6c\n"
".quad 0x505f31535f305350,0x3b5d342b5f32536a,0x33732e766f6d090a,0x202c347225092032\n"
".quad 0x646c090a3b337225,0x752e6d617261702e,0x2c35722509203233,0x616475635f5f5b20\n"
".quad 0x5f5f31666d726170,0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e\n"
".quad 0x53505f3053347461,0x536a505f31535f30,0x090a3b5d382b5f32,0x203233732e766f6d\n"
".quad 0x7225202c36722509,0x702e646c090a3b35,0x3233752e6d617261,0x5b202c3772250920\n"
".quad 0x6170616475635f5f,0x315a5f5f32666d72,0x6564696c6c6f6331,0x746e69346c6c6543\n"
".quad 0x74616f6c66366a33,0x5f3053505f305334,0x5f32536a505f3153,0x2e766f6d090a3b5d\n"
".quad 0x3872250920323373,0x090a3b377225202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c31,0x33666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c\n"
".quad 0x66366a33746e6934,0x5f30533474616f6c,0x505f31535f305350,0x3b5d302b5f32536a\n"
".quad 0x33662e766f6d090a,0x202c326625092032,0x646c090a3b316625,0x662e6d617261702e\n"
".quad 0x2c33662509203233,0x616475635f5f5b20,0x5f5f33666d726170,0x696c6c6f6331315a\n"
".quad 0x69346c6c65436564,0x6f6c66366a33746e,0x53505f3053347461,0x536a505f31535f30\n"
".quad 0x090a3b5d342b5f32,0x203233662e766f6d,0x6625202c34662509,0x702e646c090a3b33\n"
".quad 0x3233662e6d617261,0x5b202c3566250920,0x6170616475635f5f,0x315a5f5f33666d72\n"
".quad 0x6564696c6c6f6331,0x746e69346c6c6543,0x74616f6c66366a33,0x5f3053505f305334\n"
".quad 0x5f32536a505f3153,0x6f6d090a3b5d382b,0x2509203233662e76,0x3b356625202c3666\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c376625,0x6d72617061647563\n"
".quad 0x6331315a5f5f3466,0x65436564696c6c6f,0x6a33746e69346c6c,0x533474616f6c6636\n"
".quad 0x31535f3053505f30,0x302b5f32536a505f,0x2e766f6d090a3b5d,0x3866250920323366\n"
".quad 0x090a3b376625202c,0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c39\n"
".quad 0x34666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934\n"
".quad 0x5f30533474616f6c,0x505f31535f305350,0x3b5d342b5f32536a,0x33662e766f6d090a\n"
".quad 0x2c30316625092032,0x6c090a3b39662520,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x75635f5f5b202c31,0x34666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c\n"
".quad 0x66366a33746e6934,0x5f30533474616f6c,0x505f31535f305350,0x3b5d382b5f32536a\n"
".quad 0x33662e766f6d090a,0x2c32316625092032,0x090a3b3131662520,0x203233752e766f6d\n"
".quad 0x3b30202c39722509,0x6c2e70746573090a,0x2509203233732e74,0x2c327225202c3170\n"
".quad 0x40090a3b39722520,0x2061726220317025,0x395f345f744c2409,0x646c090a3b383132\n"
".quad 0x752e74736e6f632e,0x3031722509203233,0x6d617261705b202c,0x090a3b5d30342b73\n"
".quad 0x203233752e627573,0x25202c3131722509,0x0a3b31202c303172,0x74672e7074657309\n"
".quad 0x702509203233752e,0x202c327225202c32,0x40090a3b31317225,0x2061726220327025\n"
".quad 0x395f345f744c2409,0x6f6d090a3b383132,0x2509203233752e76,0x0a3b30202c323172\n"
".quad 0x746c2e7074657309,0x702509203233732e,0x202c347225202c33,0x40090a3b32317225\n"
".quad 0x2061726220337025,0x395f345f744c2409,0x646c090a3b383132,0x752e74736e6f632e\n"
".quad 0x3331722509203233,0x6d617261705b202c,0x090a3b5d34342b73,0x203233752e627573\n"
".quad 0x25202c3431722509,0x0a3b31202c333172,0x74672e7074657309,0x702509203233752e\n"
".quad 0x202c347225202c34,0x40090a3b34317225,0x2061726220347025,0x395f345f744c2409\n"
".quad 0x6f6d090a3b383132,0x2509203233752e76,0x0a3b30202c353172,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x202c367225202c35,0x40090a3b35317225,0x2061726220357025\n"
".quad 0x395f345f744c2409,0x646c090a3b383132,0x752e74736e6f632e,0x3631722509203233\n"
".quad 0x6d617261705b202c,0x090a3b5d38342b73,0x203233752e627573,0x25202c3731722509\n"
".quad 0x0a3b31202c363172,0x656c2e7074657309,0x702509203233752e,0x202c367225202c36\n"
".quad 0x40090a3b37317225,0x2061726220367025,0x38345f345f4c2409,0x5f744c240a3b3636\n"
".quad 0x0a3a383132395f34,0x3231355f345f4c24,0x636f6c2e090a3a32,0x0933363209373109\n"
".quad 0x662e766f6d090a30,0x3331662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x30202c3431662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30306630202c3531\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x6e752e617262090a,0x3242424c24092069\n"
".quad 0x6f6331315a5f5f38,0x6c65436564696c6c,0x366a33746e69346c,0x30533474616f6c66\n"
".quad 0x5f31535f3053505f,0x240a3b5f32536a50,0x363638345f345f4c,0x09636f6c2e090a3a\n"
".quad 0x3009363632093731,0x33752e6e696d090a,0x2c38317225092032,0x7225202c34722520\n"
".quad 0x6e696d090a3b3431,0x722509203233752e,0x2c367225202c3931,0x090a3b3731722520\n"
".quad 0x6f6c2e34326c756d,0x722509203233732e,0x38317225202c3032,0x0a3b30317225202c\n"
".quad 0x6c2e34326c756d09,0x2509203233732e6f,0x317225202c313272,0x3b33317225202c39\n"
".quad 0x2e34326c756d090a,0x09203233732e6f6c,0x7225202c32327225,0x30317225202c3132\n"
".quad 0x732e646461090a3b,0x3332722509203233,0x202c30327225202c,0x6d090a3b32327225\n"
".quad 0x09203233752e6e69,0x7225202c34327225,0x3b31317225202c32,0x33732e646461090a\n"
".quad 0x2c35327225092032,0x25202c3332722520,0x6f6d090a3b343272,0x2509203233752e76\n"
".quad 0x327225202c363272,0x2e766f6d090a3b35,0x3272250920323373,0x6d090a3b30202c37\n"
".quad 0x09203233752e766f,0x7225202c38327225,0x766f6d090a3b3732,0x722509203233732e\n"
".quad 0x090a3b30202c3932,0x203233752e766f6d,0x25202c3033722509,0x6f6d090a3b393272\n"
".quad 0x2509203233732e76,0x0a3b30202c313372,0x3233752e766f6d09,0x202c323372250920\n"
".quad 0x74090a3b31337225,0x34762e64312e7865,0x3233732e3233752e,0x252c333372257b20\n"
".quad 0x353372252c343372,0x5b2c7d363372252c,0x6e756f4364697267,0x2c78655473726574\n"
".quad 0x72252c363272257b,0x2c303372252c3832,0x0a3b5d7d32337225,0x373109636f6c2e09\n"
".quad 0x090a300939363209,0x203233732e766f6d,0x25202c3733722509,0x646c090a3b333372\n"
".quad 0x752e74736e6f632e,0x3833722509203233,0x6d617261705b202c,0x090a3b5d34382b73\n"
".quad 0x203233752e627573,0x25202c3933722509,0x0a3b31202c383372,0x3233752e6e696d09\n"
".quad 0x202c303472250920,0x7225202c39337225,0x766f6d090a3b3733,0x722509203233752e\n"
".quad 0x090a3b30202c3134,0x2e71652e70746573,0x3770250920323375,0x202c30347225202c\n"
".quad 0x40090a3b31347225,0x2061726220377025,0x395f345f744c2409,0x6f6d090a3b303337\n"
".quad 0x2509203233732e76,0x347225202c323472,0x2e6c756d090a3b30,0x09203233752e6f6c\n"
".quad 0x7225202c33347225,0x38337225202c3532,0x732e766f6d090a3b,0x3434722509203233\n"
".quad 0x0a3b33347225202c,0x3233752e64646109,0x202c353472250920,0x7225202c30347225\n"
".quad 0x766f6d090a3b3334,0x662509203233662e,0x30306630202c3631,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c37316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c38316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3472250920323373\n"
".quad 0x3b32347225202c36,0x365f345f744c240a,0x2f2f200a3a343139,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x697473656e202c39,0x687470656420676e\n"
".quad 0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73\n"
".quad 0x2e766f6d090a6e77,0x3472250920323375,0x3b34347225202c37,0x33732e766f6d090a\n"
".quad 0x2c38347225092032,0x766f6d090a3b3020,0x722509203233752e,0x38347225202c3934\n"
".quad 0x732e766f6d090a3b,0x3035722509203233,0x6f6d090a3b30202c,0x2509203233752e76\n"
".quad 0x357225202c313572,0x2e766f6d090a3b30,0x3572250920323373,0x6d090a3b30202c32\n"
".quad 0x09203233752e766f,0x7225202c33357225,0x786574090a3b3235,0x752e34762e64312e\n"
".quad 0x7b203233732e3233,0x3572252c34357225,0x252c363572252c35,0x72675b2c7d373572\n"
".quad 0x54736c6c65436469,0x373472257b2c7865,0x72252c393472252c,0x7d333572252c3135\n"
".quad 0x6c3c2f2f200a3b5d,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x343139365f345f74\n"
".quad 0x3109636f6c2e090a,0x0a30093337320937,0x3233732e766f6d09,0x202c383572250920\n"
".quad 0x73090a3b34357225,0x752e71652e707465,0x2c38702509203233,0x7225202c38722520\n"
".quad 0x702540090a3b3835,0x2409206172622038,0x3731375f345f744c,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x343139365f345f74,0x33752e766f6d090a\n"
".quad 0x2c39357225092032,0x090a3b3835722520,0x203233732e766f6d,0x30202c3036722509\n"
".quad 0x752e766f6d090a3b,0x3136722509203233,0x0a3b30367225202c,0x3233732e766f6d09\n"
".quad 0x202c323672250920,0x2e766f6d090a3b30,0x3672250920323375,0x3b32367225202c33\n"
".quad 0x33732e766f6d090a,0x2c34367225092032,0x766f6d090a3b3020,0x722509203233752e\n"
".quad 0x34367225202c3536,0x312e786574090a3b,0x3233662e34762e64,0x66257b203233732e\n"
".quad 0x2c303266252c3931,0x3266252c31326625,0x50646c6f5b2c7d32,0x257b2c786554736f\n"
".quad 0x313672252c393572,0x72252c333672252c,0x2f200a3b5d7d3536,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3936\n"
".quad 0x64656c6562616c20,0x365f345f744c2420,0x6f6c2e090a343139,0x3637320937310963\n"
".quad 0x2e766f6d090a3009,0x3266250920323366,0x3b39316625202c33,0x33662e766f6d090a\n"
".quad 0x2c34326625092032,0x090a3b3032662520,0x203233662e766f6d,0x25202c3532662509\n"
".quad 0x6f6d090a3b313266,0x2509203233752e76,0x357225202c363672,0x2e766f6d090a3b38\n"
".quad 0x3672250920323373,0x6d090a3b30202c37,0x09203233752e766f,0x7225202c38367225\n"
".quad 0x766f6d090a3b3736,0x722509203233732e,0x090a3b30202c3936,0x203233752e766f6d\n"
".quad 0x25202c3037722509,0x6f6d090a3b393672,0x2509203233732e76,0x0a3b30202c313772\n"
".quad 0x3233752e766f6d09,0x202c323772250920,0x74090a3b31377225,0x34762e64312e7865\n"
".quad 0x3233732e3233662e,0x252c363266257b20,0x383266252c373266,0x5b2c7d393266252c\n"
".quad 0x65546c6556646c6f,0x2c363672257b2c78,0x3772252c38367225,0x5d7d323772252c30\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363220656e,0x62616c2064616568,0x744c242064656c65,0x0a343139365f345f\n"
".quad 0x373109636f6c2e09,0x090a300937373209,0x203233662e766f6d,0x25202c3033662509\n"
".quad 0x6f6d090a3b363266,0x2509203233662e76,0x326625202c313366,0x2e766f6d090a3b37\n"
".quad 0x3366250920323366,0x3b38326625202c32,0x3109636f6c2e090a,0x0a30093038320937\n"
".quad 0x3233662e62757309,0x202c333366250920,0x6625202c34326625,0x2e627573090a3b34\n"
".quad 0x3366250920323366,0x2c33326625202c34,0x73090a3b32662520,0x09203233662e6275\n"
".quad 0x6625202c35336625,0x3b366625202c3532,0x6e6f632e646c090a,0x09203233662e7473\n"
".quad 0x705b202c36336625,0x36332b736d617261,0x2e646461090a3b5d,0x3366250920323366\n"
".quad 0x2c36336625202c37,0x090a3b3633662520,0x203233662e6c756d,0x25202c3833662509\n"
".quad 0x336625202c333366,0x2e616d66090a3b33,0x09203233662e6e72,0x6625202c39336625\n"
".quad 0x34336625202c3433,0x0a3b38336625202c,0x2e6e722e616d6609,0x3466250920323366\n"
".quad 0x2c35336625202c30,0x25202c3533662520,0x7173090a3b393366,0x33662e6e722e7472\n"
".quad 0x2c31346625092032,0x090a3b3034662520,0x2e74672e70746573,0x3970250920323366\n"
".quad 0x202c37336625202c,0x40090a3b31346625,0x6172622039702521,0x5f345f744c240920\n"
".quad 0x2f200a3b38333937,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3936,0x64656c6562616c20,0x365f345f744c2420\n"
".quad 0x6f6c2e090a343139,0x3033320937310963,0x2e627573090a3009,0x3466250920323366\n"
".quad 0x2c30336625202c32,0x73090a3b38662520,0x09203233662e6275,0x6625202c33346625\n"
".quad 0x30316625202c3133,0x662e627573090a3b,0x3434662509203233,0x202c32336625202c\n"
".quad 0x72090a3b32316625,0x33662e6e722e7063,0x2c35346625092032,0x090a3b3134662520\n"
".quad 0x203233662e6c756d,0x25202c3634662509,0x346625202c333366,0x2e6c756d090a3b35\n"
".quad 0x3466250920323366,0x2c34336625202c37,0x090a3b3534662520,0x203233662e6c756d\n"
".quad 0x25202c3834662509,0x346625202c353366,0x2e6c756d090a3b35,0x3466250920323366\n"
".quad 0x2c33346625202c39,0x090a3b3634662520,0x662e6e722e616d66,0x3035662509203233\n"
".quad 0x202c37346625202c,0x6625202c32346625,0x616d66090a3b3934,0x203233662e6e722e\n"
".quad 0x25202c3135662509,0x346625202c383466,0x3b30356625202c34,0x33662e6c756d090a\n"
".quad 0x2c32356625092032,0x25202c3734662520,0x7573090a3b313566,0x2509203233662e62\n"
".quad 0x346625202c333566,0x3b32356625202c32,0x33662e6c756d090a,0x2c34356625092032\n"
".quad 0x25202c3634662520,0x7573090a3b313566,0x2509203233662e62,0x346625202c353566\n"
".quad 0x3b34356625202c33,0x33662e6c756d090a,0x2c36356625092032,0x25202c3834662520\n"
".quad 0x7573090a3b313566,0x2509203233662e62,0x346625202c373566,0x3b36356625202c34\n"
".quad 0x3109636f6c2e090a,0x0a30093933320937,0x3233662e62757309,0x202c383566250920\n"
".quad 0x6625202c37336625,0x2e646c090a3b3134,0x33662e74736e6f63,0x2c39356625092032\n"
".quad 0x736d617261705b20,0x6d090a3b5d38382b,0x09203233662e6c75,0x6625202c30366625\n"
".quad 0x38356625202c3935,0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3136662509\n"
".quad 0x312b736d61726170,0x646c090a3b5d3030,0x662e74736e6f632e,0x3236662509203233\n"
".quad 0x6d617261705b202c,0x090a3b5d32392b73,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x7261705b202c3336,0x3b5d36392b736d61,0x33662e6c756d090a,0x2c34366625092032\n"
".quad 0x25202c3734662520,0x756d090a3b303666,0x2509203233662e6c,0x346625202c353666\n"
".quad 0x3b32366625202c32,0x33662e627573090a,0x2c36366625092032,0x25202c3536662520\n"
".quad 0x6d66090a3b343666,0x3233662e6e722e61,0x202c373666250920,0x6625202c33356625\n"
".quad 0x36366625202c3336,0x722e616d66090a3b,0x2509203233662e6e,0x336625202c383666\n"
".quad 0x2c31366625202c34,0x090a3b3736662520,0x203233662e6c756d,0x25202c3936662509\n"
".quad 0x366625202c363466,0x2e6c756d090a3b30,0x3766250920323366,0x2c33346625202c30\n"
".quad 0x090a3b3236662520,0x203233662e627573,0x25202c3137662509,0x366625202c303766\n"
".quad 0x2e616d66090a3b39,0x09203233662e6e72,0x6625202c32376625,0x33366625202c3535\n"
".quad 0x0a3b31376625202c,0x2e6e722e616d6609,0x3766250920323366,0x2c33336625202c33\n"
".quad 0x25202c3136662520,0x756d090a3b323766,0x2509203233662e6c,0x346625202c343766\n"
".quad 0x3b30366625202c38,0x33662e6c756d090a,0x2c35376625092032,0x25202c3434662520\n"
".quad 0x7573090a3b323666,0x2509203233662e62,0x376625202c363766,0x3b34376625202c35\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x37356625202c3737,0x202c33366625202c\n"
".quad 0x66090a3b36376625,0x33662e6e722e616d,0x2c38376625092032,0x25202c3533662520\n"
".quad 0x376625202c313666,0x2e617262090a3b37,0x744c240920696e75,0x3b323836375f345f\n"
".quad 0x375f345f744c240a,0x2f2f200a3a383339,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x39365f345f744c24,0x2e766f6d090a3431,0x3766250920323366,0x3030306630202c38\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c333766250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x306630202c383666,0x3b30303030303030,0x202f2f0920202020,0x5f345f744c240a30\n"
".quad 0x2f200a3a32383637,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3936,0x64656c6562616c20,0x365f345f744c2420\n"
".quad 0x6f6c2e090a343139,0x3138320937310963,0x2e646461090a3009,0x3166250920323366\n"
".quad 0x2c38366625202c38,0x090a3b3831662520,0x203233662e646461,0x25202c3731662509\n"
".quad 0x316625202c333766,0x2e646461090a3b37,0x3166250920323366,0x2c38376625202c36\n"
".quad 0x240a3b3631662520,0x3731375f345f744c,0x6c3c2f2f200a3a30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x343139365f345f74,0x33752e646461090a,0x2c34347225092032\n"
".quad 0x31202c3434722520,0x2e70746573090a3b,0x09203233752e656e,0x7225202c30317025\n"
".quad 0x35347225202c3434,0x3031702540090a3b,0x4c24092061726220,0x343139365f345f74\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x0a3b323034365f34,0x37395f345f744c24\n"
".quad 0x766f6d090a3a3033,0x662509203233662e,0x30306630202c3631,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c37316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c38316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x345f744c240a3020,0x090a3a323034365f\n"
".quad 0x09373109636f6c2e,0x6d090a3009353832,0x09203233662e766f,0x6625202c33316625\n"
".quad 0x766f6d090a3b3831,0x662509203233662e,0x37316625202c3431,0x662e766f6d090a3b\n"
".quad 0x3531662509203233,0x0a3b36316625202c,0x5f5f383242424c24,0x696c6c6f6331315a\n"
".quad 0x69346c6c65436564,0x6f6c66366a33746e,0x53505f3053347461,0x536a505f31535f30\n"
".quad 0x766f6d090a3a5f32,0x662509203233662e,0x33316625202c3937,0x61702e7473090a3b\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x315a5f5f66746572,0x6564696c6c6f6331\n"
".quad 0x746e69346c6c6543,0x74616f6c66366a33,0x5f3053505f305334,0x5f32536a505f3153\n"
".quad 0x376625202c5d302b,0x2e766f6d090a3b39,0x3866250920323366,0x3b34316625202c30\n"
".quad 0x7261702e7473090a,0x09203233662e6d61,0x72616475635f5f5b,0x31315a5f5f667465\n"
".quad 0x436564696c6c6f63,0x33746e69346c6c65,0x3474616f6c66366a,0x535f3053505f3053\n"
".quad 0x2b5f32536a505f31,0x30386625202c5d34,0x662e766f6d090a3b,0x3138662509203233\n"
".quad 0x0a3b35316625202c,0x617261702e747309,0x5b09203233662e6d,0x6572616475635f5f\n"
".quad 0x6331315a5f5f6674,0x65436564696c6c6f,0x6a33746e69346c6c,0x533474616f6c6636\n"
".quad 0x31535f3053505f30,0x382b5f32536a505f,0x3b31386625202c5d,0x240a3b746572090a\n"
".quad 0x5f5f646e6557444c,0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e\n"
".quad 0x53505f3053347461,0x536a505f31535f30,0x2f207d090a3a5f32,0x6f6331315a5f202f\n"
".quad 0x6c65436564696c6c,0x366a33746e69346c,0x30533474616f6c66,0x5f31535f3053505f\n"
".quad 0x2e090a5f32536a50,0x2e206c61626f6c67,0x7020666572786574,0x48656c6369747261\n"
".quad 0x0a3b786554687361,0x6c61626f6c672e09,0x6665727865742e20,0x6174536c6c656320\n"
".quad 0x0a0a3b7865547472,0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28\n"
".quad 0x34206e67696c612e,0x635f5f2038622e20,0x5f66746572616475,0x6c6c6f6332315a5f\n"
".quad 0x326c6c6543656469,0x66366a33746e6934,0x5f30533474616f6c,0x505f31535f305350\n"
".quad 0x6a5032746e697535,0x5a5f20295d32315b,0x64696c6c6f633231,0x6934326c6c654365\n"
".quad 0x6f6c66366a33746e,0x53505f3053347461,0x7535505f31535f30,0x28206a5032746e69\n"
".quad 0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e,0x31666d7261706164\n"
".quad 0x6c6f6332315a5f5f,0x6c6c65436564696c,0x366a33746e693432,0x30533474616f6c66\n"
".quad 0x5f31535f3053505f,0x5032746e69753550,0x2e202c5d32315b6a,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5f32666d72617061,0x6c6c6f6332315a5f,0x326c6c6543656469\n"
".quad 0x66366a33746e6934,0x5f30533474616f6c,0x505f31535f305350,0x6a5032746e697535\n"
".quad 0x6d617261702e202c,0x206e67696c612e20,0x5f2038622e203631,0x726170616475635f\n"
".quad 0x32315a5f5f33666d,0x436564696c6c6f63,0x746e6934326c6c65,0x74616f6c66366a33\n"
".quad 0x5f3053505f305334,0x6e697535505f3153,0x5d36315b6a503274,0x6d617261702e202c\n"
".quad 0x206e67696c612e20,0x5f2038622e203631,0x726170616475635f,0x32315a5f5f34666d\n"
".quad 0x436564696c6c6f63,0x746e6934326c6c65,0x74616f6c66366a33,0x5f3053505f305334\n"
".quad 0x6e697535505f3153,0x5d36315b6a503274,0x6d617261702e202c,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x6332315a5f5f3566,0x65436564696c6c6f,0x33746e6934326c6c\n"
".quad 0x3474616f6c66366a,0x535f3053505f3053,0x746e697535505f31,0x61702e202c6a5032\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x5a5f5f36666d7261,0x64696c6c6f633231\n"
".quad 0x6934326c6c654365,0x6f6c66366a33746e,0x53505f3053347461,0x7535505f31535f30\n"
".quad 0x202c6a5032746e69,0x2e206d617261702e,0x75635f5f20343675,0x37666d7261706164\n"
".quad 0x6c6f6332315a5f5f,0x6c6c65436564696c,0x366a33746e693432,0x30533474616f6c66\n"
".quad 0x5f31535f3053505f,0x5032746e69753550,0x617261702e202c6a,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x32315a5f5f38666d,0x436564696c6c6f63,0x746e6934326c6c65\n"
".quad 0x74616f6c66366a33,0x5f3053505f305334,0x6e697535505f3153,0x7b090a296a503274\n"
".quad 0x2e206765722e090a,0x373c722520323375,0x65722e090a3b3e32,0x25203233662e2067\n"
".quad 0x090a3b3e33383c66,0x72702e206765722e,0x34313c7025206465,0x636f6c2e090a3b3e\n"
".quad 0x0939393209373109,0x656257444c240a30,0x32315a5f5f6e6967,0x436564696c6c6f63\n"
".quad 0x746e6934326c6c65,0x74616f6c66366a33,0x5f3053505f305334,0x6e697535505f3153\n"
".quad 0x6c090a3a6a503274,0x2e6d617261702e64,0x3172250920323375,0x6475635f5f5b202c\n"
".quad 0x5f31666d72617061,0x6c6c6f6332315a5f,0x326c6c6543656469,0x66366a33746e6934\n"
".quad 0x5f30533474616f6c,0x505f31535f305350,0x6a5032746e697535,0x6f6d090a3b5d302b\n"
".quad 0x2509203233732e76,0x3b317225202c3272,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c337225,0x6d72617061647563,0x6332315a5f5f3166,0x65436564696c6c6f\n"
".quad 0x33746e6934326c6c,0x3474616f6c66366a,0x535f3053505f3053,0x746e697535505f31\n"
".quad 0x0a3b5d342b6a5032,0x3233732e766f6d09,0x25202c3472250920,0x2e646c090a3b3372\n"
".quad 0x33752e6d61726170,0x202c357225092032,0x70616475635f5f5b,0x5a5f5f31666d7261\n"
".quad 0x64696c6c6f633231,0x6934326c6c654365,0x6f6c66366a33746e,0x53505f3053347461\n"
".quad 0x7535505f31535f30,0x382b6a5032746e69,0x2e766f6d090a3b5d,0x3672250920323373\n"
".quad 0x090a3b357225202c,0x6d617261702e646c,0x722509203233752e,0x75635f5f5b202c37\n"
".quad 0x32666d7261706164,0x6c6f6332315a5f5f,0x6c6c65436564696c,0x366a33746e693432\n"
".quad 0x30533474616f6c66,0x5f31535f3053505f,0x5032746e69753550,0x766f6d090a3b5d6a\n"
".quad 0x722509203233732e,0x0a3b377225202c38,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x635f5f5b202c3166,0x666d726170616475,0x6f6332315a5f5f33,0x6c65436564696c6c\n"
".quad 0x6a33746e6934326c,0x533474616f6c6636,0x31535f3053505f30,0x32746e697535505f\n"
".quad 0x090a3b5d302b6a50,0x203233662e766f6d,0x6625202c32662509,0x702e646c090a3b31\n"
".quad 0x3233662e6d617261,0x5b202c3366250920,0x6170616475635f5f,0x315a5f5f33666d72\n"
".quad 0x6564696c6c6f6332,0x6e6934326c6c6543,0x616f6c66366a3374,0x3053505f30533474\n"
".quad 0x697535505f31535f,0x5d342b6a5032746e,0x662e766f6d090a3b,0x2c34662509203233\n"
".quad 0x6c090a3b33662520,0x2e6d617261702e64,0x3566250920323366,0x6475635f5f5b202c\n"
".quad 0x5f33666d72617061,0x6c6c6f6332315a5f,0x326c6c6543656469,0x66366a33746e6934\n"
".quad 0x5f30533474616f6c,0x505f31535f305350,0x6a5032746e697535,0x6f6d090a3b5d382b\n"
".quad 0x2509203233662e76,0x3b356625202c3666,0x7261702e646c090a,0x09203233662e6d61\n"
".quad 0x5f5f5b202c376625,0x6d72617061647563,0x6332315a5f5f3466,0x65436564696c6c6f\n"
".quad 0x33746e6934326c6c,0x3474616f6c66366a,0x535f3053505f3053,0x746e697535505f31\n"
".quad 0x0a3b5d302b6a5032,0x3233662e766f6d09,0x25202c3866250920,0x2e646c090a3b3766\n"
".quad 0x33662e6d61726170,0x202c396625092032,0x70616475635f5f5b,0x5a5f5f34666d7261\n"
".quad 0x64696c6c6f633231,0x6934326c6c654365,0x6f6c66366a33746e,0x53505f3053347461\n"
".quad 0x7535505f31535f30,0x342b6a5032746e69,0x2e766f6d090a3b5d,0x3166250920323366\n"
".quad 0x0a3b396625202c30,0x617261702e646c09,0x2509203233662e6d,0x5f5f5b202c313166\n"
".quad 0x6d72617061647563,0x6332315a5f5f3466,0x65436564696c6c6f,0x33746e6934326c6c\n"
".quad 0x3474616f6c66366a,0x535f3053505f3053,0x746e697535505f31,0x0a3b5d382b6a5032\n"
".quad 0x3233662e766f6d09,0x202c323166250920,0x6d090a3b31316625,0x09203233752e766f\n"
".quad 0x0a3b30202c397225,0x746c2e7074657309,0x702509203233732e,0x202c327225202c31\n"
".quad 0x2540090a3b397225,0x0920617262203170,0x31315f355f744c24,0x646c090a3b303130\n"
".quad 0x752e74736e6f632e,0x3031722509203233,0x6d617261705b202c,0x090a3b5d30342b73\n"
".quad 0x203233752e627573,0x25202c3131722509,0x0a3b31202c303172,0x74672e7074657309\n"
".quad 0x702509203233752e,0x202c327225202c32,0x40090a3b31317225,0x2061726220327025\n"
".quad 0x315f355f744c2409,0x6d090a3b30313031,0x09203233752e766f,0x3b30202c32317225\n"
".quad 0x6c2e70746573090a,0x2509203233732e74,0x2c347225202c3370,0x090a3b3231722520\n"
".quad 0x6172622033702540,0x5f355f744c240920,0x090a3b3031303131,0x74736e6f632e646c\n"
".quad 0x722509203233752e,0x7261705b202c3331,0x3b5d34342b736d61,0x33752e627573090a\n"
".quad 0x2c34317225092032,0x31202c3331722520,0x2e70746573090a3b,0x09203233752e7467\n"
".quad 0x347225202c347025,0x0a3b34317225202c,0x7262203470254009,0x355f744c24092061\n"
".quad 0x0a3b30313031315f,0x3233752e766f6d09,0x202c353172250920,0x70746573090a3b30\n"
".quad 0x203233732e746c2e,0x7225202c35702509,0x3b35317225202c36,0x622035702540090a\n"
".quad 0x5f744c2409206172,0x3b30313031315f35,0x6e6f632e646c090a,0x09203233752e7473\n"
".quad 0x705b202c36317225,0x38342b736d617261,0x2e627573090a3b5d,0x3172250920323375\n"
".quad 0x2c36317225202c37,0x746573090a3b3120,0x3233752e656c2e70,0x25202c3670250920\n"
".quad 0x37317225202c3672,0x2036702540090a3b,0x5f4c240920617262,0x0a3b363431365f35\n"
".quad 0x31315f355f744c24,0x5f4c240a3a303130,0x0a3a323034365f35,0x373109636f6c2e09\n"
".quad 0x090a300935303309,0x203233662e766f6d,0x30202c3331662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30306630202c3431\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c35316625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x62090a30202f2f09,0x0920696e752e6172\n"
".quad 0x5f5f313342424c24,0x696c6c6f6332315a,0x34326c6c65436564,0x6c66366a33746e69\n"
".quad 0x505f30533474616f,0x35505f31535f3053,0x3b6a5032746e6975,0x31365f355f4c240a\n"
".quad 0x6f6c2e090a3a3634,0x3830330937310963,0x2e6e696d090a3009,0x3172250920323375\n"
".quad 0x202c347225202c38,0x6d090a3b34317225,0x09203233752e6e69,0x7225202c39317225\n"
".quad 0x3b37317225202c36,0x2e34326c756d090a,0x09203233732e6f6c,0x7225202c30327225\n"
".quad 0x30317225202c3831,0x34326c756d090a3b,0x203233732e6f6c2e,0x25202c3132722509\n"
".quad 0x317225202c393172,0x326c756d090a3b33,0x3233732e6f6c2e34,0x202c323272250920\n"
".quad 0x7225202c31327225,0x646461090a3b3031,0x722509203233732e,0x30327225202c3332\n"
".quad 0x0a3b32327225202c,0x3233752e6e696d09,0x202c343272250920,0x317225202c327225\n"
".quad 0x2e646461090a3b31,0x3272250920323373,0x2c33327225202c35,0x090a3b3432722520\n"
".quad 0x203233752e766f6d,0x25202c3632722509,0x6f6d090a3b353272,0x2509203233732e76\n"
".quad 0x0a3b30202c373272,0x3233752e766f6d09,0x202c383272250920,0x6d090a3b37327225\n"
".quad 0x09203233732e766f,0x3b30202c39327225,0x33752e766f6d090a,0x2c30337225092032\n"
".quad 0x090a3b3932722520,0x203233732e766f6d,0x30202c3133722509,0x752e766f6d090a3b\n"
".quad 0x3233722509203233,0x0a3b31337225202c,0x2e64312e78657409,0x732e3233752e3476\n"
".quad 0x333372257b203233,0x72252c343372252c,0x7d363372252c3533,0x74536c6c65635b2c\n"
".quad 0x7b2c786554747261,0x3272252c36327225,0x252c303372252c38,0x090a3b5d7d323372\n"
".quad 0x09373109636f6c2e,0x6d090a3009313133,0x09203233732e766f,0x7225202c37337225\n"
".quad 0x766f6d090a3b3333,0x722509203233752e,0x0a3b312d202c3833,0x656e2e7074657309\n"
".quad 0x702509203233752e,0x2c37337225202c37,0x090a3b3833722520,0x6172622037702540\n"
".quad 0x5f355f744c240920,0x2e090a3b32383637,0x3309373109636f6c,0x6f6d090a30093331\n"
".quad 0x2509203233662e76,0x306630202c333166,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3431662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x30202c3531662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x617262090a30202f,0x4c240920696e752e,0x315a5f5f31334242\n"
".quad 0x6564696c6c6f6332,0x6e6934326c6c6543,0x616f6c66366a3374,0x3053505f30533474\n"
".quad 0x697535505f31535f,0x240a3b6a5032746e,0x3836375f355f744c,0x632e646c090a3a32\n"
".quad 0x3233752e74736e6f,0x202c393372250920,0x2b736d617261705b,0x6f6d090a3b5d3438\n"
".quad 0x2509203233752e76,0x0a3b30202c303472,0x71652e7074657309,0x702509203233752e\n"
".quad 0x2c39337225202c38,0x090a3b3034722520,0x6172622038702540,0x5f355f744c240920\n"
".quad 0x090a3b3232353131,0x203233732e766f6d,0x25202c3134722509,0x6f6d090a3b393372\n"
".quad 0x2509203233732e76,0x337225202c323472,0x2e766f6d090a3b37,0x3166250920323366\n"
".quad 0x3030306630202c36,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c373166250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x306630202c383166,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x732e766f6d090a30,0x3334722509203233,0x0a3b31347225202c,0x37385f355f744c24\n"
".quad 0x3c2f2f200a3a3630,0x6f4c203e706f6f6c,0x2079646f6220706f,0x33313320656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x752e766f6d090a6e,0x3434722509203233\n"
".quad 0x0a3b32347225202c,0x3233732e766f6d09,0x202c353472250920,0x2e766f6d090a3b30\n"
".quad 0x3472250920323375,0x3b35347225202c36,0x33732e766f6d090a,0x2c37347225092032\n"
".quad 0x766f6d090a3b3020,0x722509203233752e,0x37347225202c3834,0x732e766f6d090a3b\n"
".quad 0x3934722509203233,0x6f6d090a3b30202c,0x2509203233752e76,0x347225202c303572\n"
".quad 0x2e786574090a3b39,0x33752e34762e6431,0x257b203233732e32,0x323572252c313572\n"
".quad 0x72252c333572252c,0x7261705b2c7d3435,0x736148656c636974,0x72257b2c78655468\n"
".quad 0x2c363472252c3434,0x3572252c38347225,0x2f2f200a3b5d7d30,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x313320656e696c20,0x2064616568202c33\n"
".quad 0x2064656c6562616c,0x37385f355f744c24,0x636f6c2e090a3630,0x0938313309373109\n"
".quad 0x732e766f6d090a30,0x3535722509203233,0x0a3b31357225202c,0x373109636f6c2e09\n"
".quad 0x090a300939313309,0x2e656e2e70746573,0x3970250920323375,0x202c35327225202c\n"
".quad 0x40090a3b35357225,0x2061726220397025,0x385f355f744c2409,0x2f2f200a3b343931\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313320656e696c20\n"
".quad 0x2064616568202c33,0x2064656c6562616c,0x37385f355f744c24,0x70746573090a3630\n"
".quad 0x203233752e71652e,0x25202c3031702509,0x387225202c323472,0x3031702540090a3b\n"
".quad 0x4c24092061726220,0x323639385f355f74,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c33313320656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a363037385f355f,0x3233752e766f6d09,0x202c363572250920\n"
".quad 0x6d090a3b32347225,0x09203233732e766f,0x3b30202c37357225,0x33752e766f6d090a\n"
".quad 0x2c38357225092032,0x090a3b3735722520,0x203233732e766f6d,0x30202c3935722509\n"
".quad 0x752e766f6d090a3b,0x3036722509203233,0x0a3b39357225202c,0x3233732e766f6d09\n"
".quad 0x202c313672250920,0x2e766f6d090a3b30,0x3672250920323375,0x3b31367225202c32\n"
".quad 0x64312e786574090a,0x2e3233662e34762e,0x3166257b20323373,0x252c303266252c39\n"
".quad 0x323266252c313266,0x6f50646c6f5b2c7d,0x72257b2c78655473,0x2c383572252c3635\n"
".quad 0x3672252c30367225,0x2f2f200a3b5d7d32,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x313320656e696c20,0x2064616568202c33,0x2064656c6562616c\n"
".quad 0x37385f355f744c24,0x636f6c2e090a3630,0x0932323309373109,0x662e766f6d090a30\n"
".quad 0x3332662509203233,0x0a3b39316625202c,0x3233662e766f6d09,0x202c343266250920\n"
".quad 0x6d090a3b30326625,0x09203233662e766f,0x6625202c35326625,0x766f6d090a3b3132\n"
".quad 0x722509203233752e,0x32347225202c3336,0x732e766f6d090a3b,0x3436722509203233\n"
".quad 0x6f6d090a3b30202c,0x2509203233752e76,0x367225202c353672,0x2e766f6d090a3b34\n"
".quad 0x3672250920323373,0x6d090a3b30202c36,0x09203233752e766f,0x7225202c37367225\n"
".quad 0x766f6d090a3b3636,0x722509203233732e,0x090a3b30202c3836,0x203233752e766f6d\n"
".quad 0x25202c3936722509,0x6574090a3b383672,0x2e34762e64312e78,0x203233732e323366\n"
".quad 0x66252c363266257b,0x2c383266252c3732,0x6f5b2c7d39326625,0x7865546c6556646c\n"
".quad 0x252c333672257b2c,0x373672252c353672,0x3b5d7d393672252c,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3331332065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x090a363037385f35,0x09373109636f6c2e\n"
".quad 0x6d090a3009333233,0x09203233662e766f,0x6625202c30336625,0x766f6d090a3b3632\n"
".quad 0x662509203233662e,0x37326625202c3133,0x662e766f6d090a3b,0x3233662509203233\n"
".quad 0x0a3b38326625202c,0x373109636f6c2e09,0x090a300936323309,0x203233662e627573\n"
".quad 0x25202c3333662509,0x346625202c343266,0x662e627573090a3b,0x3433662509203233\n"
".quad 0x202c33326625202c,0x7573090a3b326625,0x2509203233662e62,0x326625202c353366\n"
".quad 0x0a3b366625202c35,0x736e6f632e646c09,0x2509203233662e74,0x61705b202c363366\n"
".quad 0x5d36332b736d6172,0x662e646461090a3b,0x3733662509203233,0x202c36336625202c\n"
".quad 0x6d090a3b36336625,0x09203233662e6c75,0x6625202c38336625,0x33336625202c3333\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x336625202c393366,0x2c34336625202c34\n"
".quad 0x090a3b3833662520,0x662e6e722e616d66,0x3034662509203233,0x202c35336625202c\n"
".quad 0x6625202c35336625,0x727173090a3b3933,0x3233662e6e722e74,0x202c313466250920\n"
".quad 0x73090a3b30346625,0x662e74672e707465,0x3131702509203233,0x202c37336625202c\n"
".quad 0x40090a3b31346625,0x7262203131702521,0x355f744c24092061,0x200a3b303337395f\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c333133,0x656c6562616c2064,0x5f355f744c242064,0x6c2e090a36303738\n"
".quad 0x333209373109636f,0x627573090a300930,0x662509203233662e,0x30336625202c3234\n"
".quad 0x090a3b386625202c,0x203233662e627573,0x25202c3334662509,0x316625202c313366\n"
".quad 0x2e627573090a3b30,0x3466250920323366,0x2c32336625202c34,0x090a3b3231662520\n"
".quad 0x662e6e722e706372,0x3534662509203233,0x0a3b31346625202c,0x3233662e6c756d09\n"
".quad 0x202c363466250920,0x6625202c33336625,0x6c756d090a3b3534,0x662509203233662e\n"
".quad 0x34336625202c3734,0x0a3b35346625202c,0x3233662e6c756d09,0x202c383466250920\n"
".quad 0x6625202c35336625,0x6c756d090a3b3534,0x662509203233662e,0x33346625202c3934\n"
".quad 0x0a3b36346625202c,0x2e6e722e616d6609,0x3566250920323366,0x2c37346625202c30\n"
".quad 0x25202c3234662520,0x6d66090a3b393466,0x3233662e6e722e61,0x202c313566250920\n"
".quad 0x6625202c38346625,0x30356625202c3434,0x662e6c756d090a3b,0x3235662509203233\n"
".quad 0x202c37346625202c,0x73090a3b31356625,0x09203233662e6275,0x6625202c33356625\n"
".quad 0x32356625202c3234,0x662e6c756d090a3b,0x3435662509203233,0x202c36346625202c\n"
".quad 0x73090a3b31356625,0x09203233662e6275,0x6625202c35356625,0x34356625202c3334\n"
".quad 0x662e6c756d090a3b,0x3635662509203233,0x202c38346625202c,0x73090a3b31356625\n"
".quad 0x09203233662e6275,0x6625202c37356625,0x36356625202c3434,0x09636f6c2e090a3b\n"
".quad 0x3009393332093731,0x33662e627573090a,0x2c38356625092032,0x25202c3733662520\n"
".quad 0x646c090a3b313466,0x662e74736e6f632e,0x3935662509203233,0x6d617261705b202c\n"
".quad 0x090a3b5d38382b73,0x203233662e6c756d,0x25202c3036662509,0x356625202c393566\n"
".quad 0x632e646c090a3b38,0x3233662e74736e6f,0x202c313666250920,0x2b736d617261705b\n"
".quad 0x6c090a3b5d303031,0x2e74736e6f632e64,0x3666250920323366,0x617261705b202c32\n"
".quad 0x0a3b5d32392b736d,0x736e6f632e646c09,0x2509203233662e74,0x61705b202c333666\n"
".quad 0x5d36392b736d6172,0x662e6c756d090a3b,0x3436662509203233,0x202c37346625202c\n"
".quad 0x6d090a3b30366625,0x09203233662e6c75,0x6625202c35366625,0x32366625202c3234\n"
".quad 0x662e627573090a3b,0x3636662509203233,0x202c35366625202c,0x66090a3b34366625\n"
".quad 0x33662e6e722e616d,0x2c37366625092032,0x25202c3335662520,0x366625202c333666\n"
".quad 0x2e616d66090a3b36,0x09203233662e6e72,0x6625202c38366625,0x31366625202c3433\n"
".quad 0x0a3b37366625202c,0x3233662e6c756d09,0x202c393666250920,0x6625202c36346625\n"
".quad 0x6c756d090a3b3036,0x662509203233662e,0x33346625202c3037,0x0a3b32366625202c\n"
".quad 0x3233662e62757309,0x202c313766250920,0x6625202c30376625,0x616d66090a3b3936\n"
".quad 0x203233662e6e722e,0x25202c3237662509,0x366625202c353566,0x3b31376625202c33\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x33336625202c3337,0x202c31366625202c\n"
".quad 0x6d090a3b32376625,0x09203233662e6c75,0x6625202c34376625,0x30366625202c3834\n"
".quad 0x662e6c756d090a3b,0x3537662509203233,0x202c34346625202c,0x73090a3b32366625\n"
".quad 0x09203233662e6275,0x6625202c36376625,0x34376625202c3537,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x356625202c373766,0x2c33366625202c37,0x090a3b3637662520\n"
".quad 0x662e6e722e616d66,0x3837662509203233,0x202c35336625202c,0x6625202c31366625\n"
".quad 0x617262090a3b3737,0x4c240920696e752e,0x343734395f355f74,0x5f355f744c240a3b\n"
".quad 0x2f200a3a30333739,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3320656e696c2079,0x64616568202c3331,0x64656c6562616c20,0x385f355f744c2420\n"
".quad 0x766f6d090a363037,0x662509203233662e,0x30306630202c3837,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c33376625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c38366625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x355f744c240a3020,0x200a3a343734395f\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c333133,0x656c6562616c2064,0x5f355f744c242064,0x6c2e090a36303738\n"
".quad 0x323309373109636f,0x646461090a300937,0x662509203233662e,0x38366625202c3831\n"
".quad 0x0a3b38316625202c,0x3233662e64646109,0x202c373166250920,0x6625202c33376625\n"
".quad 0x646461090a3b3731,0x662509203233662e,0x38376625202c3631,0x0a3b36316625202c\n"
".quad 0x39385f355f744c24,0x3c2f2f200a3a3236,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x33313320656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3037385f355f744c,0x09636f6c2e090a36,0x3009363133093731,0x33752e646461090a\n"
".quad 0x2c32347225092032,0x31202c3234722520,0x752e646461090a3b,0x3037722509203233\n"
".quad 0x202c37337225202c,0x73090a3b39337225,0x752e656e2e707465,0x3231702509203233\n"
".quad 0x202c32347225202c,0x40090a3b30377225,0x6172622032317025,0x5f355f744c240920\n"
".quad 0x62090a3b36303738,0x0920696e752e6172,0x31385f355f744c24,0x5f744c240a3b3439\n"
".quad 0x3a32323531315f35,0x33662e766f6d090a,0x2c36316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c37316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366\n"
".quad 0x3030306630202c38,0x20203b3030303030,0x0a30202f2f092020,0x31385f355f744c24\n"
".quad 0x5f744c240a3a3439,0x090a3a3835325f35,0x09373109636f6c2e,0x6d090a3009313333\n"
".quad 0x09203233662e766f,0x6625202c33316625,0x766f6d090a3b3831,0x662509203233662e\n"
".quad 0x37316625202c3431,0x662e766f6d090a3b,0x3531662509203233,0x0a3b36316625202c\n"
".quad 0x5f5f313342424c24,0x696c6c6f6332315a,0x34326c6c65436564,0x6c66366a33746e69\n"
".quad 0x505f30533474616f,0x35505f31535f3053,0x3a6a5032746e6975,0x33662e766f6d090a\n"
".quad 0x2c39376625092032,0x090a3b3331662520,0x6d617261702e7473,0x5f5b09203233662e\n"
".quad 0x746572616475635f,0x6f6332315a5f5f66,0x6c65436564696c6c,0x6a33746e6934326c\n"
".quad 0x533474616f6c6636,0x31535f3053505f30,0x32746e697535505f,0x25202c5d302b6a50\n"
".quad 0x6f6d090a3b393766,0x2509203233662e76,0x316625202c303866,0x702e7473090a3b34\n"
".quad 0x3233662e6d617261,0x6475635f5f5b0920,0x5a5f5f6674657261,0x64696c6c6f633231\n"
".quad 0x6934326c6c654365,0x6f6c66366a33746e,0x53505f3053347461,0x7535505f31535f30\n"
".quad 0x342b6a5032746e69,0x3b30386625202c5d,0x33662e766f6d090a,0x2c31386625092032\n"
".quad 0x090a3b3531662520,0x6d617261702e7473,0x5f5b09203233662e,0x746572616475635f\n"
".quad 0x6f6332315a5f5f66,0x6c65436564696c6c,0x6a33746e6934326c,0x533474616f6c6636\n"
".quad 0x31535f3053505f30,0x32746e697535505f,0x25202c5d382b6a50,0x6572090a3b313866\n"
".quad 0x6557444c240a3b74,0x6332315a5f5f646e,0x65436564696c6c6f,0x33746e6934326c6c\n"
".quad 0x3474616f6c66366a,0x535f3053505f3053,0x746e697535505f31,0x207d090a3a6a5032\n"
".quad 0x6332315a5f202f2f,0x65436564696c6c6f,0x33746e6934326c6c,0x3474616f6c66366a\n"
".quad 0x535f3053505f3053,0x746e697535505f31,0x652e090a0a6a5032,0x395a5f207972746e\n"
".quad 0x7461726765746e69,0x74616f6c66365065,0x535f30535f305334,0x09090a2820665f30\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x656e5f665f30535f,0x09090a2c736f5077\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x656e5f665f30535f,0x09090a2c6c655677\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x6c6f5f665f30535f,0x09090a2c736f5064\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x6c6f5f665f30535f,0x09090a2c6c655664\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x65645f665f30535f,0x29656d695461746c\n"
".quad 0x65722e090a7b090a,0x25203233752e2067,0x2e090a3b3e383c72,0x3436752e20676572\n"
".quad 0x3e31313c64722520,0x206765722e090a3b,0x3c6625203233662e,0x722e090a3b3e3734\n"
".quad 0x646572702e206765,0x0a3b3e383c702520,0x373109636f6c2e09,0x4c240a3009313609\n"
".quad 0x5f6e696765625744,0x6765746e69395a5f,0x6c66365065746172,0x535f30533474616f\n"
".quad 0x0a3a665f30535f30,0x373109636f6c2e09,0x63090a3009353609,0x752e3233732e7476\n"
".quad 0x2c31722509203233,0x2e64696174632520,0x2e747663090a3b78,0x203233752e323373\n"
".quad 0x6e25202c32722509,0x090a3b782e646974,0x6f6c2e34326c756d,0x722509203233732e\n"
".quad 0x202c317225202c33,0x6f6d090a3b327225,0x2509203233752e76,0x64697425202c3472\n"
".quad 0x646461090a3b782e,0x722509203233752e,0x202c337225202c35,0x756d090a3b347225\n"
".quad 0x3233752e6f6c2e6c,0x25202c3672250920,0x0a3b3631202c3572,0x3436752e74766309\n"
".quad 0x722509203233752e,0x3b367225202c3164,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c32647225,0x726170616475635f,0x746e69395a5f5f6d,0x3650657461726765\n"
".quad 0x30533474616f6c66,0x665f30535f30535f,0x5d736f50646c6f5f,0x752e646461090a3b\n"
".quad 0x3364722509203436,0x202c32647225202c,0x6c090a3b31647225,0x6c61626f6c672e64\n"
".quad 0x203233662e34762e,0x66252c3166257b09,0x66252c3366252c32,0x6472255b202c7d34\n"
".quad 0x2e090a3b5d302b33,0x3609373109636f6c,0x2e646c090a300936,0x36752e6d61726170\n"
".quad 0x2c34647225092034,0x616475635f5f5b20,0x395a5f5f6d726170,0x7461726765746e69\n"
".quad 0x74616f6c66365065,0x535f30535f305334,0x56646c6f5f665f30,0x6461090a3b5d6c65\n"
".quad 0x2509203436752e64,0x647225202c356472,0x3b31647225202c34,0x6f6c672e646c090a\n"
".quad 0x662e34762e6c6162,0x3566257b09203233,0x3766252c3666252c,0x5b202c7d3866252c\n"
".quad 0x3b5d302b35647225,0x3109636f6c2e090a,0x090a300931370937,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c39,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x30535f3053347461,0x65645f665f30535f,0x5d656d695461746c\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3031662509,0x322b736d61726170\n"
".quad 0x6c756d090a3b5d30,0x662509203233662e,0x30316625202c3131,0x090a3b396625202c\n"
".quad 0x203233662e646461,0x25202c3231662509,0x356625202c313166,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x5b202c3331662509,0x332b736d61726170,0x6c756d090a3b5d32\n"
".quad 0x662509203233662e,0x32316625202c3431,0x0a3b33316625202c,0x3233662e766f6d09\n"
".quad 0x202c353166250920,0x6c090a3b34316625,0x2e74736e6f632e64,0x3166250920323366\n"
".quad 0x617261705b202c36,0x0a3b5d34322b736d,0x3233662e6c756d09,0x202c373166250920\n"
".quad 0x6625202c36316625,0x2e646461090a3b39,0x3166250920323366,0x2c37316625202c38\n"
".quad 0x6d090a3b36662520,0x09203233662e6c75,0x6625202c39316625,0x33316625202c3831\n"
".quad 0x662e766f6d090a3b,0x3032662509203233,0x0a3b39316625202c,0x736e6f632e646c09\n"
".quad 0x2509203233662e74,0x61705b202c313266,0x5d38322b736d6172,0x662e6c756d090a3b\n"
".quad 0x3232662509203233,0x202c31326625202c,0x6461090a3b396625,0x2509203233662e64\n"
".quad 0x326625202c333266,0x0a3b376625202c32,0x3233662e6c756d09,0x202c343266250920\n"
".quad 0x6625202c33326625,0x766f6d090a3b3331,0x662509203233662e,0x34326625202c3532\n"
".quad 0x09636f6c2e090a3b,0x0a30093437093731,0x3233662e6c756d09,0x202c363266250920\n"
".quad 0x6625202c34316625,0x2e646461090a3b39,0x3266250920323366,0x2c36326625202c37\n"
".quad 0x6d090a3b31662520,0x09203233662e766f,0x6625202c38326625,0x6c756d090a3b3732\n"
".quad 0x662509203233662e,0x39316625202c3932,0x090a3b396625202c,0x203233662e646461\n"
".quad 0x25202c3033662509,0x326625202c393266,0x662e766f6d090a3b,0x3133662509203233\n"
".quad 0x0a3b30336625202c,0x3233662e6c756d09,0x202c323366250920,0x6625202c34326625\n"
".quad 0x2e646461090a3b39,0x3366250920323366,0x2c32336625202c33,0x6d090a3b33662520\n"
".quad 0x09203233662e766f,0x6625202c34336625,0x2e646c090a3b3333,0x33662e74736e6f63\n"
".quad 0x2c35336625092032,0x736d617261705b20,0x6d090a3b5d36332b,0x09203233662e766f\n"
".quad 0x6630202c36336625,0x3030303030386633,0x2f2f09202020203b,0x2e627573090a3120\n"
".quad 0x3366250920323366,0x2c36336625202c37,0x090a3b3533662520,0x2e746c2e70746573\n"
".quad 0x3170250920323366,0x202c37336625202c,0x40090a3b37326625,0x6172622031702521\n"
".quad 0x5f365f744c240920,0x2e090a3b36363834,0x3709373109636f6c,0x766f6d090a300937\n"
".quad 0x662509203233662e,0x37336625202c3832,0x6f632e646c090a3b,0x203233662e74736e\n"
".quad 0x5b202c3833662509,0x312b736d61726170,0x756d090a3b5d3430,0x2509203233662e6c\n"
".quad 0x336625202c353166,0x3b34316625202c38,0x345f365f744c240a,0x6f6d090a3a363638\n"
".quad 0x2509203233662e76,0x626630202c393366,0x3b30303030303866,0x202f2f0920202020\n"
".quad 0x2e646461090a312d,0x3466250920323366,0x2c35336625202c30,0x090a3b3933662520\n"
".quad 0x2e74672e70746573,0x3270250920323366,0x202c30346625202c,0x40090a3b38326625\n"
".quad 0x6172622032702521,0x5f365f744c240920,0x2e090a3b38373335,0x3709373109636f6c\n"
".quad 0x766f6d090a300938,0x662509203233662e,0x30346625202c3832,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x5b202c3134662509,0x312b736d61726170,0x756d090a3b5d3430\n"
".quad 0x2509203233662e6c,0x346625202c353166,0x3b35316625202c31,0x355f365f744c240a\n"
".quad 0x6573090a3a383733,0x33662e746c2e7074,0x202c337025092032,0x6625202c37336625\n"
".quad 0x252140090a3b3033,0x0920617262203370,0x38355f365f744c24,0x6f6c2e090a3b3039\n"
".quad 0x0939370937310963,0x662e766f6d090a30,0x3133662509203233,0x0a3b37336625202c\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x61705b202c323466,0x3430312b736d6172\n"
".quad 0x2e6c756d090a3b5d,0x3266250920323366,0x2c32346625202c30,0x240a3b3931662520\n"
".quad 0x3938355f365f744c,0x70746573090a3a30,0x203233662e74672e,0x6625202c34702509\n"
".quad 0x31336625202c3034,0x3470252140090a3b,0x4c24092061726220,0x323034365f365f74\n"
".quad 0x09636f6c2e090a3b,0x0a30093038093731,0x3233662e766f6d09,0x202c313366250920\n"
".quad 0x6c090a3b30346625,0x2e74736e6f632e64,0x3466250920323366,0x617261705b202c33\n"
".quad 0x3b5d3430312b736d,0x33662e6c756d090a,0x2c30326625092032,0x25202c3334662520\n"
".quad 0x744c240a3b303266,0x3a323034365f365f,0x6c2e70746573090a,0x2509203233662e74\n"
".quad 0x37336625202c3570,0x0a3b33336625202c,0x6220357025214009,0x5f744c2409206172\n"
".quad 0x0a3b343139365f36,0x373109636f6c2e09,0x6d090a3009313809,0x09203233662e766f\n"
".quad 0x6625202c34336625,0x2e646c090a3b3733,0x33662e74736e6f63,0x2c34346625092032\n"
".quad 0x736d617261705b20,0x090a3b5d3430312b,0x203233662e6c756d,0x25202c3532662509\n"
".quad 0x326625202c343466,0x365f744c240a3b34,0x090a3a343139365f,0x2e74672e70746573\n"
".quad 0x3670250920323366,0x202c30346625202c,0x40090a3b34336625,0x6172622036702521\n"
".quad 0x5f365f744c240920,0x2e090a3b36323437,0x3809373109636f6c,0x766f6d090a300932\n"
".quad 0x662509203233662e,0x30346625202c3433,0x6f632e646c090a3b,0x203233662e74736e\n"
".quad 0x5b202c3534662509,0x312b736d61726170,0x756d090a3b5d3430,0x2509203233662e6c\n"
".quad 0x346625202c353266,0x3b35326625202c35,0x375f365f744c240a,0x6c2e090a3a363234\n"
".quad 0x353809373109636f,0x702e646c090a3009,0x3436752e6d617261,0x202c366472250920\n"
".quad 0x70616475635f5f5b,0x69395a5f5f6d7261,0x657461726765746e,0x3474616f6c663650\n"
".quad 0x30535f30535f3053,0x6f5077656e5f665f,0x646461090a3b5d73,0x722509203436752e\n"
".quad 0x36647225202c3764,0x0a3b31647225202c,0x626f6c672e747309,0x33662e34762e6c61\n"
".quad 0x376472255b092032,0x66257b202c5d302b,0x2c313366252c3832,0x3466252c34336625\n"
".quad 0x636f6c2e090a3b7d,0x3009363809373109,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c38647225,0x726170616475635f,0x746e69395a5f5f6d,0x3650657461726765\n"
".quad 0x30533474616f6c66,0x665f30535f30535f,0x5d6c655677656e5f,0x752e646461090a3b\n"
".quad 0x3964722509203436,0x202c38647225202c,0x73090a3b31647225,0x6c61626f6c672e74\n"
".quad 0x203233662e34762e,0x302b396472255b09,0x353166257b202c5d,0x66252c303266252c\n"
".quad 0x3b7d3866252c3532,0x3109636f6c2e090a,0x090a300937380937,0x4c240a3b74697865\n"
".quad 0x5a5f5f646e655744,0x61726765746e6939,0x616f6c6636506574,0x5f30535f30533474\n"
".quad 0x7d090a3a665f3053,0x69395a5f202f2f20,0x657461726765746e,0x3474616f6c663650\n"
".quad 0x30535f30535f3053,0x6e652e090a0a665f,0x31315a5f20797274,0x7247657461647075\n"
".quad 0x6f6c663650446469,0x5f31536a50347461,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x31315a5f5f6d7261,0x7247657461647075,0x6f6c663650446469\n"
".quad 0x5f31536a50347461,0x09090a2c736f705f,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x746164707531315a,0x3650446469724765,0x6a503474616f6c66\n"
".quad 0x646972675f5f3153,0x737265746e756f43,0x7261702e09090a2c,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x7531315a5f5f6d72,0x6972476574616470,0x616f6c6636504464\n"
".quad 0x5f5f31536a503474,0x6c6c654364697267,0x2e090a7b090a2973,0x3233752e20676572\n"
".quad 0x3b3e35333c722520,0x2e206765722e090a,0x3c64722520343675,0x722e090a3b3e3131\n"
".quad 0x203233662e206765,0x0a3b3e30323c6625,0x373109636f6c2e09,0x240a300934333109\n"
".quad 0x6e6967656257444c,0x64707531315a5f5f,0x4464697247657461,0x3474616f6c663650\n"
".quad 0x090a3a5f31536a50,0x09373109636f6c2e,0x63090a3009373331,0x752e3233732e7476\n"
".quad 0x2c31722509203233,0x2e64696174632520,0x2e747663090a3b78,0x203233752e323373\n"
".quad 0x6e25202c32722509,0x090a3b782e646974,0x6f6c2e34326c756d,0x722509203233732e\n"
".quad 0x202c317225202c33,0x6f6d090a3b327225,0x2509203233752e76,0x64697425202c3472\n"
".quad 0x646461090a3b782e,0x722509203233752e,0x202c337225202c35,0x756d090a3b347225\n"
".quad 0x3233752e6f6c2e6c,0x25202c3672250920,0x0a3b3631202c3572,0x3436752e74766309\n"
".quad 0x722509203233752e,0x3b367225202c3164,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c32647225,0x726170616475635f,0x707531315a5f5f6d,0x6469724765746164\n"
".quad 0x74616f6c66365044,0x705f5f31536a5034,0x6461090a3b5d736f,0x2509203436752e64\n"
".quad 0x647225202c336472,0x3b32647225202c31,0x6f6c672e646c090a,0x662e34762e6c6162\n"
".quad 0x3166257b09203233,0x3366252c3266252c,0x72255b202c7d5f2c,0x090a3b5d302b3364\n"
".quad 0x09373109636f6c2e,0x6c090a3009353031,0x2e74736e6f632e64,0x3772250920323375\n"
".quad 0x6d617261705b202c,0x090a3b5d34342b73,0x74736e6f632e646c,0x722509203233752e\n"
".quad 0x617261705b202c38,0x0a3b5d30342b736d,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x7261705b202c3466,0x3b5d34362b736d61,0x33662e627573090a,0x202c356625092032\n"
".quad 0x346625202c336625,0x6f632e646c090a3b,0x203233662e74736e,0x705b202c36662509\n"
".quad 0x36372b736d617261,0x2e766964090a3b5d,0x09203233662e6e72,0x356625202c376625\n"
".quad 0x090a3b366625202c,0x2e696d722e747663,0x203233662e323366,0x6625202c38662509\n"
".quad 0x2e747663090a3b37,0x2e3233732e697a72,0x3972250920323366,0x090a3b386625202c\n"
".quad 0x74736e6f632e646c,0x722509203233752e,0x7261705b202c3031,0x3b5d38342b736d61\n"
".quad 0x33752e627573090a,0x2c31317225092032,0x31202c3031722520,0x752e6e696d090a3b\n"
".quad 0x3231722509203233,0x25202c397225202c,0x756d090a3b313172,0x732e6f6c2e34326c\n"
".quad 0x3331722509203233,0x202c32317225202c,0x756d090a3b377225,0x732e6f6c2e34326c\n"
".quad 0x3431722509203233,0x202c33317225202c,0x646c090a3b387225,0x662e74736e6f632e\n"
".quad 0x2c39662509203233,0x736d617261705b20,0x73090a3b5d30362b,0x09203233662e6275\n"
".quad 0x6625202c30316625,0x0a3b396625202c32,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x61705b202c313166,0x5d32372b736d6172,0x722e766964090a3b,0x2509203233662e6e\n"
".quad 0x316625202c323166,0x3b31316625202c30,0x6d722e747663090a,0x33662e3233662e69\n"
".quad 0x2c33316625092032,0x090a3b3231662520,0x2e697a722e747663,0x203233662e323373\n"
".quad 0x25202c3531722509,0x7573090a3b333166,0x2509203233752e62,0x377225202c363172\n"
".quad 0x696d090a3b31202c,0x2509203233752e6e,0x317225202c373172,0x3b36317225202c35\n"
".quad 0x2e34326c756d090a,0x09203233732e6f6c,0x7225202c38317225,0x3b387225202c3731\n"
".quad 0x33732e646461090a,0x2c39317225092032,0x25202c3431722520,0x646c090a3b383172\n"
".quad 0x662e74736e6f632e,0x3431662509203233,0x6d617261705b202c,0x090a3b5d36352b73\n"
".quad 0x203233662e627573,0x25202c3531662509,0x34316625202c3166,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x5b202c3631662509,0x362b736d61726170,0x766964090a3b5d38\n"
".quad 0x203233662e6e722e,0x25202c3731662509,0x316625202c353166,0x2e747663090a3b36\n"
".quad 0x2e3233662e696d72,0x3166250920323366,0x3b37316625202c38,0x7a722e747663090a\n"
".quad 0x33662e3233732e69,0x2c30327225092032,0x090a3b3831662520,0x203233752e627573\n"
".quad 0x25202c3132722509,0x090a3b31202c3872,0x203233752e6e696d,0x25202c3232722509\n"
".quad 0x327225202c303272,0x2e646461090a3b31,0x3272250920323373,0x2c39317225202c33\n"
".quad 0x090a3b3232722520,0x09373109636f6c2e,0x6d090a3009313231,0x33752e6f6c2e6c75\n"
".quad 0x2c34327225092032,0x34202c3332722520,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x7225202c34647225,0x2e646c090a3b3432,0x36752e6d61726170,0x2c35647225092034\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x4765746164707531,0x6c66365044646972\n"
".quad 0x31536a503474616f,0x6f43646972675f5f,0x3b5d737265746e75,0x36752e646461090a\n"
".quad 0x2c36647225092034,0x25202c3464722520,0x6f6d090a3b356472,0x2509203233752e76\n"
".quad 0x0a3b31202c353272,0x6c672e6d6f746109,0x6464612e6c61626f,0x722509203233752e\n"
".quad 0x6472255b202c3632,0x35327225202c5d36,0x732e766f6d090a3b,0x3732722509203233\n"
".quad 0x0a3b36327225202c,0x373109636f6c2e09,0x090a300936323109,0x74736e6f632e646c\n"
".quad 0x722509203233752e,0x7261705b202c3832,0x3b5d34382b736d61,0x33752e627573090a\n"
".quad 0x2c39327225092032,0x31202c3832722520,0x752e6e696d090a3b,0x3033722509203233\n"
".quad 0x202c37327225202c,0x6d090a3b39327225,0x33752e6f6c2e6c75,0x2c31337225092032\n"
".quad 0x25202c3332722520,0x6461090a3b383272,0x2509203233752e64,0x337225202c323372\n"
".quad 0x3b31337225202c30,0x6f6c2e6c756d090a,0x722509203233752e,0x32337225202c3333\n"
".quad 0x7663090a3b34202c,0x33752e3436752e74,0x2c37647225092032,0x090a3b3333722520\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3864,0x5f6d726170616475\n"
".quad 0x6164707531315a5f,0x5044646972476574,0x503474616f6c6636,0x6972675f5f31536a\n"
".quad 0x3b5d736c6c654364,0x36752e646461090a,0x2c39647225092034,0x25202c3764722520\n"
".quad 0x7473090a3b386472,0x2e6c61626f6c672e,0x72255b0920323375,0x25202c5d302b3964\n"
".quad 0x6f6c2e090a3b3572,0x3334310937310963,0x74697865090a3009,0x6e6557444c240a3b\n"
".quad 0x707531315a5f5f64,0x6469724765746164,0x74616f6c66365044,0x0a3a5f31536a5034\n"
".quad 0x5a5f202f2f207d09,0x6574616470753131,0x6636504464697247,0x536a503474616f6c\n"
".quad 0x6e652e090a0a5f31,0x63395a5f20797274,0x4468736148636c61,0x3474616f6c663650\n"
".quad 0x2032746e69753550,0x7261702e09090a28,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x6163395a5f5f6d72,0x504468736148636c,0x503474616f6c6636,0x705f32746e697535\n"
".quad 0x702e09090a2c736f,0x36752e206d617261,0x616475635f5f2034,0x395a5f5f6d726170\n"
".quad 0x68736148636c6163,0x74616f6c66365044,0x32746e6975355034,0x6c6369747261705f\n"
".quad 0x090a296873614865,0x206765722e090a7b,0x3c7225203233752e,0x722e090a3b3e3632\n"
".quad 0x203436752e206765,0x0a3b3e383c647225,0x662e206765722e09,0x30323c6625203233\n"
".quad 0x636f6c2e090a3b3e,0x0938343109373109,0x656257444c240a30,0x63395a5f5f6e6967\n"
".quad 0x4468736148636c61,0x3474616f6c663650,0x3a32746e69753550,0x3109636f6c2e090a\n"
".quad 0x0a30093135310937,0x3233732e74766309,0x722509203233752e,0x6961746325202c31\n"
".quad 0x7663090a3b782e64,0x33752e3233732e74,0x202c327225092032,0x3b782e6469746e25\n"
".quad 0x2e34326c756d090a,0x09203233732e6f6c,0x317225202c337225,0x090a3b327225202c\n"
".quad 0x203233752e766f6d,0x7425202c34722509,0x61090a3b782e6469,0x09203233752e6464\n"
".quad 0x337225202c357225,0x090a3b347225202c,0x752e6f6c2e6c756d,0x2c36722509203233\n"
".quad 0x3631202c35722520,0x752e747663090a3b,0x09203233752e3436,0x7225202c31647225\n"
".quad 0x702e646c090a3b36,0x3436752e6d617261,0x202c326472250920,0x70616475635f5f5b\n"
".quad 0x63395a5f5f6d7261,0x4468736148636c61,0x3474616f6c663650,0x5f32746e69753550\n"
".quad 0x61090a3b5d736f70,0x09203436752e6464,0x7225202c33647225,0x32647225202c3164\n"
".quad 0x6c672e646c090a3b,0x2e34762e6c61626f,0x66257b0920323366,0x66252c3266252c31\n"
".quad 0x255b202c7d5f2c33,0x0a3b5d302b336472,0x373109636f6c2e09,0x090a300935303109\n"
".quad 0x74736e6f632e646c,0x722509203233752e,0x617261705b202c37,0x0a3b5d34342b736d\n"
".quad 0x736e6f632e646c09,0x2509203233752e74,0x7261705b202c3872,0x3b5d30342b736d61\n"
".quad 0x6e6f632e646c090a,0x09203233662e7473,0x61705b202c346625,0x5d34362b736d6172\n"
".quad 0x662e627573090a3b,0x2c35662509203233,0x6625202c33662520,0x632e646c090a3b34\n"
".quad 0x3233662e74736e6f,0x5b202c3666250920,0x372b736d61726170,0x766964090a3b5d36\n"
".quad 0x203233662e6e722e,0x6625202c37662509,0x0a3b366625202c35,0x696d722e74766309\n"
".quad 0x3233662e3233662e,0x25202c3866250920,0x747663090a3b3766,0x3233732e697a722e\n"
".quad 0x722509203233662e,0x0a3b386625202c39,0x736e6f632e646c09,0x2509203233752e74\n"
".quad 0x61705b202c303172,0x5d38342b736d6172,0x752e627573090a3b,0x3131722509203233\n"
".quad 0x202c30317225202c,0x2e6e696d090a3b31,0x3172250920323375,0x202c397225202c32\n"
".quad 0x6d090a3b31317225,0x2e6f6c2e34326c75,0x3172250920323373,0x2c32317225202c33\n"
".quad 0x6d090a3b37722520,0x2e6f6c2e34326c75,0x3172250920323373,0x2c33317225202c34\n"
".quad 0x6c090a3b38722520,0x2e74736e6f632e64,0x3966250920323366,0x6d617261705b202c\n"
".quad 0x090a3b5d30362b73,0x203233662e627573,0x25202c3031662509,0x3b396625202c3266\n"
".quad 0x6e6f632e646c090a,0x09203233662e7473,0x705b202c31316625,0x32372b736d617261\n"
".quad 0x2e766964090a3b5d,0x09203233662e6e72,0x6625202c32316625,0x31316625202c3031\n"
".quad 0x722e747663090a3b,0x662e3233662e696d,0x3331662509203233,0x0a3b32316625202c\n"
".quad 0x697a722e74766309,0x3233662e3233732e,0x202c353172250920,0x73090a3b33316625\n"
".quad 0x09203233752e6275,0x7225202c36317225,0x6d090a3b31202c37,0x09203233752e6e69\n"
".quad 0x7225202c37317225,0x36317225202c3531,0x34326c756d090a3b,0x203233732e6f6c2e\n"
".quad 0x25202c3831722509,0x387225202c373172,0x732e646461090a3b,0x3931722509203233\n"
".quad 0x202c34317225202c,0x6c090a3b38317225,0x2e74736e6f632e64,0x3166250920323366\n"
".quad 0x617261705b202c34,0x0a3b5d36352b736d,0x3233662e62757309,0x202c353166250920\n"
".quad 0x316625202c316625,0x632e646c090a3b34,0x3233662e74736e6f,0x202c363166250920\n"
".quad 0x2b736d617261705b,0x6964090a3b5d3836,0x3233662e6e722e76,0x202c373166250920\n"
".quad 0x6625202c35316625,0x747663090a3b3631,0x3233662e696d722e,0x662509203233662e\n"
".quad 0x37316625202c3831,0x722e747663090a3b,0x662e3233732e697a,0x3032722509203233\n"
".quad 0x0a3b38316625202c,0x3233752e62757309,0x202c313272250920,0x0a3b31202c387225\n"
".quad 0x3233752e6e696d09,0x202c323272250920,0x7225202c30327225,0x646461090a3b3132\n"
".quad 0x722509203233732e,0x39317225202c3332,0x0a3b32327225202c,0x373109636f6c2e09\n"
".quad 0x090a300938353109,0x752e6f6c2e6c756d,0x3432722509203233,0x38202c357225202c\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x7225202c34647225,0x2e646c090a3b3432\n"
".quad 0x36752e6d61726170,0x2c35647225092034,0x616475635f5f5b20,0x395a5f5f6d726170\n"
".quad 0x68736148636c6163,0x74616f6c66365044,0x32746e6975355034,0x6c6369747261705f\n"
".quad 0x0a3b5d6873614865,0x3436752e64646109,0x202c366472250920,0x7225202c34647225\n"
".quad 0x2e7473090a3b3564,0x762e6c61626f6c67,0x5b09203233752e32,0x2c5d302b36647225\n"
".quad 0x252c333272257b20,0x6c2e090a3b7d3572,0x353109373109636f,0x697865090a300939\n"
".quad 0x6557444c240a3b74,0x6163395a5f5f646e,0x504468736148636c,0x503474616f6c6636\n"
".quad 0x0a3a32746e697535,0x5a5f202f2f207d09,0x736148636c616339,0x616f6c6636504468\n"
".quad 0x746e697535503474,0x746e652e090a0a32,0x7238325a5f207972,0x6144726564726f65\n"
".quad 0x6e6946646e416174,0x6174536c6c654364,0x6e69753550447472,0x616f6c6636503274\n"
".quad 0x5f32535f32533474,0x0a28206a505f3253,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x6f657238325a5f5f,0x6174614472656472,0x43646e6946646e41\n"
".quad 0x74726174536c6c65,0x32746e6975355044,0x3474616f6c663650,0x32535f32535f3253\n"
".quad 0x747261705f6a505f,0x68736148656c6369,0x7261702e09090a2c,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x7238325a5f5f6d72,0x6144726564726f65,0x6e6946646e416174\n"
".quad 0x6174536c6c654364,0x6e69753550447472,0x616f6c6636503274,0x5f32535f32533474\n"
".quad 0x6c6f5f6a505f3253,0x09090a2c736f5064,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x64726f657238325a,0x6e41617461447265,0x6c6543646e694664\n"
".quad 0x504474726174536c,0x365032746e697535,0x32533474616f6c66,0x505f32535f32535f\n"
".quad 0x6c6556646c6f5f6a,0x7261702e09090a2c,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x7238325a5f5f6d72,0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364\n"
".quad 0x6e69753550447472,0x616f6c6636503274,0x5f32535f32533474,0x6f735f6a505f3253\n"
".quad 0x2c736f5064657472,0x617261702e09090a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x657238325a5f5f6d,0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543\n"
".quad 0x746e697535504474,0x74616f6c66365032,0x535f32535f325334,0x726f735f6a505f32\n"
".quad 0x0a2c6c6556646574,0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x6f657238325a5f5f,0x6174614472656472,0x43646e6946646e41,0x74726174536c6c65\n"
".quad 0x32746e6975355044,0x3474616f6c663650,0x32535f32535f3253,0x6c6c65635f6a505f\n"
".quad 0x090a297472617453,0x206765722e090a7b,0x3c7225203233752e,0x722e090a3b3e3134\n"
".quad 0x203436752e206765,0x3b3e37313c647225,0x2e206765722e090a,0x313c662520323366\n"
".quad 0x65722e090a3b3e38,0x20646572702e2067,0x090a3b3e353c7025,0x206465726168732e\n"
".quad 0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3039325f7261765f,0x6f6e5f31335f3239,0x5f74736e6f635f6e,0x6148646572616873\n"
".quad 0x30315b3034326873,0x2f2f090a3b5d3832,0x5f616475635f5f20,0x61765f6c61636f6c\n"
".quad 0x5f37393039325f72,0x635f6e6f6e5f3831,0x6572705f74736e6f,0x203d206174614476\n"
".quad 0x636f6c2e090a3631,0x0939363109373109,0x656257444c240a30,0x38325a5f5f6e6967\n"
".quad 0x44726564726f6572,0x6946646e41617461,0x74536c6c6543646e,0x6975355044747261\n"
".quad 0x6f6c66365032746e,0x32535f3253347461,0x0a3a6a505f32535f,0x373109636f6c2e09\n"
".quad 0x090a300933373109,0x2e3233732e747663,0x3172250920323375,0x646961746325202c\n"
".quad 0x747663090a3b782e,0x3233752e3233732e,0x25202c3272250920,0x0a3b782e6469746e\n"
".quad 0x6c2e34326c756d09,0x2509203233732e6f,0x2c317225202c3372,0x6d090a3b32722520\n"
".quad 0x09203233752e766f,0x697425202c347225,0x6461090a3b782e64,0x2509203233752e64\n"
".quad 0x2c337225202c3572,0x6d090a3b34722520,0x33752e6f6c2e6c75,0x202c367225092032\n"
".quad 0x0a3b38202c357225,0x3436752e74766309,0x722509203233752e,0x3b367225202c3164\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x5f5b202c32647225,0x726170616475635f\n"
".quad 0x657238325a5f5f6d,0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543\n"
".quad 0x746e697535504474,0x74616f6c66365032,0x535f32535f325334,0x7261705f6a505f32\n"
".quad 0x736148656c636974,0x646461090a3b5d68,0x722509203436752e,0x31647225202c3364\n"
".quad 0x0a3b32647225202c,0x626f6c672e646c09,0x33752e32762e6c61,0x2c3772257b092032\n"
".quad 0x255b202c7d387225,0x0a3b5d302b336472,0x373109636f6c2e09,0x090a300939373109\n"
".quad 0x203436752e766f6d,0x5f202c3464722509,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f31335f32393039,0x736e6f635f6e6f6e,0x6465726168735f74\n"
".quad 0x3b30343268736148,0x36752e747663090a,0x2509203233752e34,0x347225202c356472\n"
".quad 0x772e6c756d090a3b,0x203233752e656469,0x25202c3664722509,0x090a3b34202c3472\n"
".quad 0x203436752e646461,0x25202c3764722509,0x647225202c346472,0x732e7473090a3b36\n"
".quad 0x33752e6465726168,0x376472255b092032,0x377225202c5d342b,0x732e766f6d090a3b\n"
".quad 0x2c39722509203233,0x746573090a3b3020,0x2e3233752e74672e,0x3172250920323373\n"
".quad 0x202c357225202c30,0x656e090a3b397225,0x2509203233732e67,0x317225202c313172\n"
".quad 0x2e766f6d090a3b30,0x3172250920323375,0x73090a3b30202c32,0x33752e71652e7465\n"
".quad 0x2509203233752e32,0x347225202c333172,0x0a3b32317225202c,0x3233732e67656e09\n"
".quad 0x202c343172250920,0x61090a3b33317225,0x09203233622e646e,0x7225202c35317225\n"
".quad 0x34317225202c3131,0x752e766f6d090a3b,0x3631722509203233,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x202c317025092032,0x7225202c35317225,0x702540090a3b3631\n"
".quad 0x2409206172622031,0x3138325f395f744c,0x672e646c090a3b38,0x32762e6c61626f6c\n"
".quad 0x257b09203233752e,0x383172252c373172,0x336472255b202c7d,0x2e090a3b5d382d2b\n"
".quad 0x3109373109636f6c,0x6f6d090a30093338,0x2509203233732e76,0x317225202c393172\n"
".quad 0x2e766f6d090a3b37,0x3272250920323373,0x3b38317225202c30,0x3109636f6c2e090a\n"
".quad 0x0a30093438310937,0x3233732e766f6d09,0x202c313272250920,0x73090a3b39317225\n"
".quad 0x6465726168732e74,0x5f5b09203233752e,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f31335f32393039,0x736e6f635f6e6f6e,0x6465726168735f74\n"
".quad 0x2b30343268736148,0x31327225202c5d30,0x5f395f744c240a3b,0x2e090a3a38313832\n"
".quad 0x3109373109636f6c,0x6162090a30093738,0x0920636e79732e72,0x2e766f6d090a3b30\n"
".quad 0x3272250920323375,0x73090a3b30202c32,0x732e71652e707465,0x2c32702509203233\n"
".quad 0x7225202c35722520,0x702540090a3b3232,0x2409206172622032,0x323635325f395f4c\n"
".quad 0x68732e646c090a3b,0x3233752e64657261,0x202c333272250920,0x5d302b376472255b\n"
".quad 0x2e70746573090a3b,0x09203233752e7165,0x327225202c337025,0x0a3b377225202c33\n"
".quad 0x7262203370254009,0x5f395f4c24092061,0x4c240a3b36303332,0x3a323635325f395f\n"
".quad 0x3109636f6c2e090a,0x0a30093039310937,0x2e6f6c2e6c756d09,0x3272250920323375\n"
".quad 0x202c377225202c34,0x2e747663090a3b34,0x203233752e343675,0x25202c3864722509\n"
".quad 0x646c090a3b343272,0x752e6d617261702e,0x3964722509203436,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6564726f65723832,0x646e416174614472,0x6c6c6543646e6946\n"
".quad 0x3550447472617453,0x66365032746e6975,0x5f32533474616f6c,0x6a505f32535f3253\n"
".quad 0x6174536c6c65635f,0x6461090a3b5d7472,0x2509203436752e64,0x7225202c30316472\n"
".quad 0x39647225202c3864,0x6c672e7473090a3b,0x3233752e6c61626f,0x30316472255b0920\n"
".quad 0x357225202c5d302b,0x325f395f4c240a3b,0x6f6d090a3a363033,0x2509203233752e76\n"
".quad 0x387225202c353272,0x732e766f6d090a3b,0x3632722509203233,0x6f6d090a3b30202c\n"
".quad 0x2509203233752e76,0x327225202c373272,0x2e766f6d090a3b36,0x3272250920323373\n"
".quad 0x6d090a3b30202c38,0x09203233752e766f,0x7225202c39327225,0x766f6d090a3b3832\n"
".quad 0x722509203233732e,0x090a3b30202c3033,0x203233752e766f6d,0x25202c3133722509\n"
".quad 0x6574090a3b303372,0x2e34762e64312e78,0x203233732e323366,0x3266252c3166257b\n"
".quad 0x3466252c3366252c,0x6f50646c6f5b2c7d,0x72257b2c78655473,0x2c373272252c3532\n"
".quad 0x3372252c39327225,0x6c2e090a3b5d7d31,0x393109373109636f,0x766f6d090a300934\n"
".quad 0x662509203233662e,0x0a3b316625202c35,0x3233662e766f6d09,0x25202c3666250920\n"
".quad 0x766f6d090a3b3266,0x662509203233662e,0x0a3b336625202c37,0x3233662e766f6d09\n"
".quad 0x25202c3866250920,0x766f6d090a3b3466,0x722509203233752e,0x3b387225202c3233\n"
".quad 0x33732e766f6d090a,0x2c33337225092032,0x766f6d090a3b3020,0x722509203233752e\n"
".quad 0x33337225202c3433,0x732e766f6d090a3b,0x3533722509203233,0x6f6d090a3b30202c\n"
".quad 0x2509203233752e76,0x337225202c363372,0x2e766f6d090a3b35,0x3372250920323373\n"
".quad 0x6d090a3b30202c37,0x09203233752e766f,0x7225202c38337225,0x786574090a3b3733\n"
".quad 0x662e34762e64312e,0x7b203233732e3233,0x303166252c396625,0x66252c313166252c\n"
".quad 0x646c6f5b2c7d3231,0x7b2c7865546c6556,0x3372252c32337225,0x252c363372252c34\n"
".quad 0x090a3b5d7d383372,0x09373109636f6c2e,0x6d090a3009353931,0x09203233662e766f\n"
".quad 0x6625202c33316625,0x2e766f6d090a3b39,0x3166250920323366,0x3b30316625202c34\n"
".quad 0x33662e766f6d090a,0x2c35316625092032,0x090a3b3131662520,0x203233662e766f6d\n"
".quad 0x25202c3631662509,0x6c2e090a3b323166,0x393109373109636f,0x726162090a300937\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x3009393931093731,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x2c357225202c3933,0x7663090a3b363120,0x33752e3436752e74\n"
".quad 0x3131647225092032,0x0a3b39337225202c,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5b202c32316472,0x726170616475635f,0x657238325a5f5f6d,0x746144726564726f\n"
".quad 0x646e6946646e4161,0x726174536c6c6543,0x746e697535504474,0x74616f6c66365032\n"
".quad 0x535f32535f325334,0x726f735f6a505f32,0x3b5d736f50646574,0x36752e646461090a\n"
".quad 0x3331647225092034,0x2c3231647225202c,0x0a3b313164722520,0x626f6c672e747309\n"
".quad 0x33662e34762e6c61,0x316472255b092032,0x257b202c5d302b33,0x252c3666252c3566\n"
".quad 0x3b7d3866252c3766,0x3109636f6c2e090a,0x0a30093030320937,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5b202c34316472,0x726170616475635f,0x657238325a5f5f6d\n"
".quad 0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543,0x746e697535504474\n"
".quad 0x74616f6c66365032,0x535f32535f325334,0x726f735f6a505f32,0x3b5d6c6556646574\n"
".quad 0x36752e646461090a,0x3531647225092034,0x2c3431647225202c,0x0a3b313164722520\n"
".quad 0x626f6c672e747309,0x33662e34762e6c61,0x316472255b092032,0x257b202c5d302b35\n"
".quad 0x343166252c333166,0x66252c353166252c,0x6c2e090a3b7d3631,0x303209373109636f\n"
".quad 0x697865090a300932,0x6557444c240a3b74,0x7238325a5f5f646e,0x6144726564726f65\n"
".quad 0x6e6946646e416174,0x6174536c6c654364,0x6e69753550447472,0x616f6c6636503274\n"
".quad 0x5f32535f32533474,0x090a3a6a505f3253,0x325a5f202f2f207d,0x726564726f657238\n"
".quad 0x46646e4161746144,0x536c6c6543646e69,0x7535504474726174,0x6c66365032746e69\n"
".quad 0x535f32533474616f,0x0a6a505f32535f32,0x7972746e652e090a,0x6c6c6f63385a5f20\n"
".quad 0x6c66365044656469,0x535f30533474616f,0x7535505f30535f30,0x28206a5032746e69\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x6c6f63385a5f5f6d\n"
".quad 0x663650446564696c,0x5f30533474616f6c,0x35505f30535f3053,0x5f6a5032746e6975\n"
".quad 0x0a2c736f5077656e,0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x6c6c6f63385a5f5f,0x6c66365044656469,0x535f30533474616f,0x7535505f30535f30\n"
".quad 0x6e5f6a5032746e69,0x090a2c6c65567765,0x206d617261702e09,0x635f5f203436752e\n"
".quad 0x5f6d726170616475,0x696c6c6f63385a5f,0x6f6c663650446564,0x30535f3053347461\n"
".quad 0x697535505f30535f,0x6c6f5f6a5032746e,0x09090a2c736f5064,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x5f5f6d7261706164,0x64696c6c6f63385a,0x616f6c6636504465\n"
".quad 0x5f30535f30533474,0x6e697535505f3053,0x646c6f5f6a503274,0x2e09090a2c6c6556\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061,0x6564696c6c6f6338\n"
".quad 0x74616f6c66365044,0x535f30535f305334,0x746e697535505f30,0x747261705f6a5032\n"
".quad 0x68736148656c6369,0x7261702e09090a2c,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x6f63385a5f5f6d72,0x3650446564696c6c,0x30533474616f6c66,0x505f30535f30535f\n"
".quad 0x6a5032746e697535,0x6174536c6c65635f,0x090a7b090a297472,0x33752e206765722e\n"
".quad 0x3830313c72252032,0x6765722e090a3b3e,0x7225203436752e20,0x090a3b3e34313c64\n"
".quad 0x33662e206765722e,0x3934313c66252032,0x6765722e090a3b3e,0x2520646572702e20\n"
".quad 0x090a3b3e38313c70,0x6475635f5f202f2f,0x5f6c61636f6c5f61,0x393239325f726176\n"
".quad 0x6e6f6e5f30325f30,0x735f74736e6f635f,0x746144646574726f,0x090a3631203d2061\n"
".quad 0x09373109636f6c2e,0x4c240a3009303433,0x5f6e696765625744,0x696c6c6f63385a5f\n"
".quad 0x6f6c663650446564,0x30535f3053347461,0x697535505f30535f,0x090a3a6a5032746e\n"
".quad 0x2e3233732e747663,0x3172250920323375,0x646961746325202c,0x747663090a3b782e\n"
".quad 0x3233752e3233732e,0x25202c3272250920,0x0a3b782e6469746e,0x6c2e34326c756d09\n"
".quad 0x2509203233732e6f,0x2c317225202c3372,0x6d090a3b32722520,0x09203233752e766f\n"
".quad 0x697425202c347225,0x6461090a3b782e64,0x2509203233752e64,0x2c337225202c3572\n"
".quad 0x6d090a3b34722520,0x09203233752e766f,0x357225202c367225,0x732e766f6d090a3b\n"
".quad 0x2c37722509203233,0x766f6d090a3b3020,0x722509203233752e,0x0a3b377225202c38\n"
".quad 0x3233732e766f6d09,0x30202c3972250920,0x752e766f6d090a3b,0x3031722509203233\n"
".quad 0x090a3b397225202c,0x203233732e766f6d,0x30202c3131722509,0x752e766f6d090a3b\n"
".quad 0x3231722509203233,0x0a3b31317225202c,0x2e64312e78657409,0x732e3233662e3476\n"
".quad 0x2c3166257b203233,0x2c3366252c326625,0x6c6f5b2c7d346625,0x2c786554736f5064\n"
".quad 0x3872252c3672257b,0x72252c303172252c,0x2e090a3b5d7d3231,0x3309373109636f6c\n"
".quad 0x6f6d090a30093035,0x2509203233662e76,0x3b316625202c3566,0x33662e766f6d090a\n"
".quad 0x202c366625092032,0x6f6d090a3b326625,0x2509203233662e76,0x3b336625202c3766\n"
".quad 0x33752e766f6d090a,0x2c33317225092032,0x6d090a3b35722520,0x09203233732e766f\n"
".quad 0x3b30202c34317225,0x33752e766f6d090a,0x2c35317225092032,0x090a3b3431722520\n"
".quad 0x203233732e766f6d,0x30202c3631722509,0x752e766f6d090a3b,0x3731722509203233\n"
".quad 0x0a3b36317225202c,0x3233732e766f6d09,0x202c383172250920,0x2e766f6d090a3b30\n"
".quad 0x3172250920323375,0x3b38317225202c39,0x64312e786574090a,0x2e3233662e34762e\n"
".quad 0x3866257b20323373,0x3166252c3966252c,0x2c7d313166252c30,0x546c6556646c6f5b\n"
".quad 0x333172257b2c7865,0x72252c353172252c,0x7d393172252c3731,0x636f6c2e090a3b5d\n"
".quad 0x0931353309373109,0x662e766f6d090a30,0x3231662509203233,0x090a3b386625202c\n"
".quad 0x203233662e766f6d,0x25202c3331662509,0x766f6d090a3b3966,0x662509203233662e\n"
".quad 0x30316625202c3431,0x662e766f6d090a3b,0x3531662509203233,0x0a3b31316625202c\n"
".quad 0x373109636f6c2e09,0x090a300934353309,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x7261705b202c3631,0x3b5d36352b736d61,0x33662e627573090a,0x2c37316625092032\n"
".quad 0x6625202c35662520,0x2e646c090a3b3631,0x33662e74736e6f63,0x2c38316625092032\n"
".quad 0x736d617261705b20,0x64090a3b5d38362b,0x33662e6e722e7669,0x2c39316625092032\n"
".quad 0x25202c3731662520,0x7663090a3b383166,0x33662e696d722e74,0x2509203233662e32\n"
".quad 0x316625202c303266,0x2e747663090a3b39,0x2e3233732e697a72,0x3272250920323366\n"
".quad 0x3b30326625202c30,0x6e6f632e646c090a,0x09203233662e7473,0x705b202c31326625\n"
".quad 0x30362b736d617261,0x2e627573090a3b5d,0x3266250920323366,0x202c366625202c32\n"
".quad 0x6c090a3b31326625,0x2e74736e6f632e64,0x3266250920323366,0x617261705b202c33\n"
".quad 0x0a3b5d32372b736d,0x2e6e722e76696409,0x3266250920323366,0x2c32326625202c34\n"
".quad 0x090a3b3332662520,0x2e696d722e747663,0x203233662e323366,0x25202c3532662509\n"
".quad 0x7663090a3b343266,0x33732e697a722e74,0x2509203233662e32,0x326625202c313272\n"
".quad 0x632e646c090a3b35,0x3233662e74736e6f,0x202c363266250920,0x2b736d617261705b\n"
".quad 0x7573090a3b5d3436,0x2509203233662e62,0x376625202c373266,0x0a3b36326625202c\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x61705b202c383266,0x5d36372b736d6172\n"
".quad 0x722e766964090a3b,0x2509203233662e6e,0x326625202c393266,0x3b38326625202c37\n"
".quad 0x6d722e747663090a,0x33662e3233662e69,0x2c30336625092032,0x090a3b3932662520\n"
".quad 0x2e697a722e747663,0x203233662e323373,0x25202c3232722509,0x7573090a3b303366\n"
".quad 0x2509203233732e62,0x327225202c333272,0x61090a3b31202c30,0x09203233732e6464\n"
".quad 0x7225202c34327225,0x090a3b32202c3032,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x7261705b202c3133,0x3b5d36332b736d61,0x33732e766f6d090a,0x2c35327225092032\n"
".quad 0x6f6d090a3b312d20,0x2509203233662e76,0x306630202c323366,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3333662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3433662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x5f744c240a30202f,0x36343532315f3031\n"
".quad 0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220,0x202c34353320656e\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x746172657469202c,0x0a33203a736e6f69\n"
".quad 0x3233732e766f6d09,0x202c363272250920,0x5f744c240a3b312d,0x34313333315f3031\n"
".quad 0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220,0x202c34353320656e\n"
".quad 0x20676e697473656e,0x32203a6874706564,0x746172657469202c,0x0a33203a736e6f69\n"
".quad 0x3233732e766f6d09,0x202c373272250920,0x4c240a3b33327225,0x3034315f30315f74\n"
".quad 0x3c2f2f200a3a3238,0x6f4c203e706f6f6c,0x2079646f6220706f,0x34353320656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x72657469202c3320,0x203a736e6f697461\n"
".quad 0x09636f6c2e090a33,0x3009303033093731,0x33752e766f6d090a,0x2c38327225092032\n"
".quad 0x746573090a3b3020,0x3233732e746c2e70,0x25202c3170250920,0x327225202c373272\n"
".quad 0x31702540090a3b38,0x4c24092061726220,0x3938315f30315f74,0x3c2f2f200a3b3634\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x34353320656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x34315f30315f744c,0x2e646c090a323830\n"
".quad 0x33752e74736e6f63,0x2c39327225092032,0x736d617261705b20,0x73090a3b5d30342b\n"
".quad 0x09203233752e6275,0x7225202c30337225,0x090a3b31202c3932,0x2e74672e70746573\n"
".quad 0x3270250920323375,0x202c37327225202c,0x40090a3b30337225,0x2061726220327025\n"
".quad 0x5f30315f744c2409,0x200a3b3634393831,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c343533,0x656c6562616c2064\n"
".quad 0x30315f744c242064,0x090a32383034315f,0x203233732e646461,0x25202c3133722509\n"
".quad 0x327225202c313272,0x2e766f6d090a3b36,0x3372250920323375,0x73090a3b30202c32\n"
".quad 0x732e746c2e707465,0x2c33702509203233,0x25202c3133722520,0x2540090a3b323372\n"
".quad 0x0920617262203370,0x315f30315f744c24,0x2f200a3b36343938,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x64616568202c3435\n"
".quad 0x64656c6562616c20,0x5f30315f744c2420,0x6c090a3238303431,0x2e74736e6f632e64\n"
".quad 0x3372250920323375,0x617261705b202c33,0x0a3b5d34342b736d,0x3233752e62757309\n"
".quad 0x202c343372250920,0x3b31202c33337225,0x672e70746573090a,0x2509203233752e74\n"
".quad 0x31337225202c3470,0x0a3b34337225202c,0x7262203470254009,0x315f744c24092061\n"
".quad 0x3b36343938315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3435332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x32383034315f3031,0x33732e646461090a,0x2c35337225092032,0x25202c3232722520\n"
".quad 0x6f6d090a3b353272,0x2509203233752e76,0x0a3b30202c363372,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x2c35337225202c35,0x090a3b3633722520,0x6172622035702540\n"
".quad 0x30315f744c240920,0x0a3b36343938315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c34353320,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x0a32383034315f30,0x736e6f632e646c09,0x2509203233752e74\n"
".quad 0x61705b202c373372,0x5d38342b736d6172,0x752e627573090a3b,0x3833722509203233\n"
".quad 0x202c37337225202c,0x70746573090a3b31,0x203233752e656c2e,0x7225202c36702509\n"
".quad 0x38337225202c3533,0x2036702540090a3b,0x5f4c240920617262,0x38393430315f3031\n"
".quad 0x30315f744c240a3b,0x0a3a36343938315f,0x30315f30315f4c24,0x2f2f200a3a343537\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353320656e696c20\n"
".quad 0x2064616568202c34,0x2064656c6562616c,0x315f30315f744c24,0x6f6d090a32383034\n"
".quad 0x2509203233662e76,0x306630202c353366,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3633662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x30202c3733662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x617262090a30202f,0x4c240920696e752e,0x5f5f69646e655744\n"
".quad 0x47636c616332315a,0x3468736148646972,0x3738315f33746e69,0x315f4c240a3b315f\n"
".quad 0x3a38393430315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3435332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x32383034315f3031,0x3109636f6c2e090a,0x0a30093530310937,0x3233752e6e696d09\n"
".quad 0x202c393372250920,0x7225202c35337225,0x6c756d090a3b3833,0x33732e6f6c2e3432\n"
".quad 0x2c30347225092032,0x25202c3933722520,0x756d090a3b333372,0x732e6f6c2e34326c\n"
".quad 0x3134722509203233,0x202c30347225202c,0x6d090a3b39327225,0x09203233752e6e69\n"
".quad 0x7225202c32347225,0x34337225202c3133,0x34326c756d090a3b,0x203233732e6f6c2e\n"
".quad 0x25202c3334722509,0x327225202c323472,0x2e646461090a3b39,0x3472250920323373\n"
".quad 0x2c31347225202c34,0x090a3b3334722520,0x203233752e6e696d,0x25202c3534722509\n"
".quad 0x337225202c373272,0x2e646461090a3b30,0x3472250920323373,0x2c34347225202c36\n"
".quad 0x090a3b3534722520,0x09373109636f6c2e,0x6d090a3009383033,0x09203233752e766f\n"
".quad 0x7225202c37347225,0x766f6d090a3b3634,0x722509203233732e,0x090a3b30202c3834\n"
".quad 0x203233752e766f6d,0x25202c3934722509,0x6f6d090a3b383472,0x2509203233732e76\n"
".quad 0x0a3b30202c303572,0x3233752e766f6d09,0x202c313572250920,0x6d090a3b30357225\n"
".quad 0x09203233732e766f,0x3b30202c32357225,0x33752e766f6d090a,0x2c33357225092032\n"
".quad 0x090a3b3235722520,0x762e64312e786574,0x33732e3233752e34,0x2c343572257b2032\n"
".quad 0x3572252c35357225,0x2c7d373572252c36,0x6174536c6c65635b,0x257b2c7865547472\n"
".quad 0x393472252c373472,0x72252c313572252c,0x2f200a3b5d7d3335,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x64616568202c3435\n"
".quad 0x64656c6562616c20,0x5f30315f744c2420,0x2e090a3238303431,0x3309373109636f6c\n"
".quad 0x6f6d090a30093131,0x2509203233732e76,0x357225202c383572,0x2e766f6d090a3b34\n"
".quad 0x3572250920323375,0x090a3b312d202c39,0x2e656e2e70746573,0x3770250920323375\n"
".quad 0x202c38357225202c,0x40090a3b39357225,0x2061726220377025,0x5f30315f744c2409\n"
".quad 0x200a3b3833333431,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c343533,0x656c6562616c2064,0x30315f744c242064\n"
".quad 0x090a32383034315f,0x203233662e766f6d,0x30202c3533662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30306630202c3633\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c37336625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x62090a30202f2f09,0x0920696e752e6172\n"
".quad 0x69646e6557444c24,0x6c616332315a5f5f,0x7361486469724763,0x315f33746e693468\n"
".quad 0x4c240a3b315f3738,0x3334315f30315f74,0x3c2f2f200a3a3833,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x34353320656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x34315f30315f744c,0x2e646c090a323830,0x33752e74736e6f63\n"
".quad 0x2c30367225092032,0x736d617261705b20,0x6d090a3b5d34382b,0x09203233752e766f\n"
".quad 0x3b30202c31367225,0x652e70746573090a,0x2509203233752e71,0x30367225202c3870\n"
".quad 0x0a3b31367225202c,0x7262203870254009,0x315f744c24092061,0x3b38353439315f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3435332065,0x6562616c20646165,0x5f744c242064656c,0x32383034315f3031\n"
".quad 0x33732e766f6d090a,0x2c32367225092032,0x090a3b3036722520,0x203233732e766f6d\n"
".quad 0x25202c3336722509,0x6f6d090a3b383572,0x2509203233662e76,0x306630202c383366\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3933662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x30202c3034662509,0x3030303030303066,0x2f09202020203b30,0x3c2f2f200a30202f\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x34353320656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x34315f30315f744c,0x766f6d090a323830\n"
".quad 0x722509203233732e,0x32367225202c3436,0x30315f744c240a3b,0x0a3a32363335315f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x656e202c31313320\n"
".quad 0x656420676e697473,0x202c34203a687470,0x6574616d69747365,0x7461726574692064\n"
".quad 0x6e75203a736e6f69,0x6d090a6e776f6e6b,0x09203233752e766f,0x7225202c35367225\n"
".quad 0x766f6d090a3b3336,0x722509203233732e,0x090a3b30202c3636,0x203233752e766f6d\n"
".quad 0x25202c3736722509,0x6f6d090a3b363672,0x2509203233732e76,0x0a3b30202c383672\n"
".quad 0x3233752e766f6d09,0x202c393672250920,0x6d090a3b38367225,0x09203233732e766f\n"
".quad 0x3b30202c30377225,0x33752e766f6d090a,0x2c31377225092032,0x090a3b3037722520\n"
".quad 0x762e64312e786574,0x33732e3233752e34,0x2c323772257b2032,0x3772252c33377225\n"
".quad 0x2c7d353772252c34,0x6c6369747261705b,0x7865546873614865,0x252c353672257b2c\n"
".quad 0x393672252c373672,0x3b5d7d313772252c,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3131332065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x32363335315f3031,0x3109636f6c2e090a,0x0a30093831330937\n"
".quad 0x3233732e766f6d09,0x202c363772250920,0x2e090a3b32377225,0x3309373109636f6c\n"
".quad 0x6573090a30093931,0x33752e656e2e7074,0x202c397025092032,0x7225202c36347225\n"
".quad 0x702540090a3b3637,0x2409206172622039,0x34315f30315f744c,0x2f2f200a3b303538\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313320656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x315f30315f744c24,0x6573090a32363335\n"
".quad 0x33752e71652e7074,0x2c30317025092032,0x25202c3336722520,0x702540090a3b3572\n"
".quad 0x0920617262203031,0x315f30315f744c24,0x2f200a3b38313635,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x64616568202c3131\n"
".quad 0x64656c6562616c20,0x5f30315f744c2420,0x6d090a3236333531,0x09203233752e766f\n"
".quad 0x7225202c37377225,0x766f6d090a3b3336,0x722509203233732e,0x090a3b30202c3837\n"
".quad 0x203233752e766f6d,0x25202c3937722509,0x6f6d090a3b383772,0x2509203233732e76\n"
".quad 0x0a3b30202c303872,0x3233752e766f6d09,0x202c313872250920,0x6d090a3b30387225\n"
".quad 0x09203233732e766f,0x3b30202c32387225,0x33752e766f6d090a,0x2c33387225092032\n"
".quad 0x090a3b3238722520,0x762e64312e786574,0x33732e3233662e34,0x2c313466257b2032\n"
".quad 0x3466252c32346625,0x2c7d343466252c33,0x54736f50646c6f5b,0x373772257b2c7865\n"
".quad 0x72252c393772252c,0x7d333872252c3138,0x6c3c2f2f200a3b5d,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31313320656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x3335315f30315f74,0x636f6c2e090a3236,0x0932323309373109\n"
".quad 0x662e766f6d090a30,0x3534662509203233,0x0a3b31346625202c,0x3233662e766f6d09\n"
".quad 0x202c363466250920,0x6d090a3b32346625,0x09203233662e766f,0x6625202c37346625\n"
".quad 0x766f6d090a3b3334,0x722509203233752e,0x33367225202c3438,0x732e766f6d090a3b\n"
".quad 0x3538722509203233,0x6f6d090a3b30202c,0x2509203233752e76,0x387225202c363872\n"
".quad 0x2e766f6d090a3b35,0x3872250920323373,0x6d090a3b30202c37,0x09203233752e766f\n"
".quad 0x7225202c38387225,0x766f6d090a3b3738,0x722509203233732e,0x090a3b30202c3938\n"
".quad 0x203233752e766f6d,0x25202c3039722509,0x6574090a3b393872,0x2e34762e64312e78\n"
".quad 0x203233732e323366,0x66252c383466257b,0x2c303566252c3934,0x6f5b2c7d31356625\n"
".quad 0x7865546c6556646c,0x252c343872257b2c,0x383872252c363872,0x3b5d7d303972252c\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3131332065,0x6562616c20646165,0x5f744c242064656c,0x32363335315f3031\n"
".quad 0x3109636f6c2e090a,0x0a30093332330937,0x3233662e766f6d09,0x202c323566250920\n"
".quad 0x6d090a3b38346625,0x09203233662e766f,0x6625202c33356625,0x766f6d090a3b3934\n"
".quad 0x662509203233662e,0x30356625202c3435,0x09636f6c2e090a3b,0x3009363233093731\n"
".quad 0x33662e627573090a,0x2c35356625092032,0x25202c3634662520,0x627573090a3b3666\n"
".quad 0x662509203233662e,0x35346625202c3635,0x090a3b356625202c,0x203233662e627573\n"
".quad 0x25202c3735662509,0x376625202c373466,0x662e646461090a3b,0x3835662509203233\n"
".quad 0x202c31336625202c,0x6d090a3b31336625,0x09203233662e6c75,0x6625202c39356625\n"
".quad 0x35356625202c3535,0x722e616d66090a3b,0x2509203233662e6e,0x356625202c303666\n"
".quad 0x2c36356625202c36,0x090a3b3935662520,0x662e6e722e616d66,0x3136662509203233\n"
".quad 0x202c37356625202c,0x6625202c37356625,0x727173090a3b3036,0x3233662e6e722e74\n"
".quad 0x202c323666250920,0x73090a3b31366625,0x662e74672e707465,0x3131702509203233\n"
".quad 0x202c38356625202c,0x40090a3b32366625,0x7262203131702521,0x315f744c24092061\n"
".quad 0x3b36383336315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3131332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x32363335315f3031,0x3109636f6c2e090a,0x0a30093033320937,0x3233662e62757309\n"
".quad 0x202c333666250920,0x6625202c32356625,0x627573090a3b3231,0x662509203233662e\n"
".quad 0x33356625202c3436,0x0a3b33316625202c,0x3233662e62757309,0x202c353666250920\n"
".quad 0x6625202c34356625,0x706372090a3b3431,0x203233662e6e722e,0x25202c3636662509\n"
".quad 0x756d090a3b323666,0x2509203233662e6c,0x356625202c373666,0x3b36366625202c35\n"
".quad 0x33662e6c756d090a,0x2c38366625092032,0x25202c3635662520,0x756d090a3b363666\n"
".quad 0x2509203233662e6c,0x356625202c393666,0x3b36366625202c37,0x33662e6c756d090a\n"
".quad 0x2c30376625092032,0x25202c3436662520,0x6d66090a3b373666,0x3233662e6e722e61\n"
".quad 0x202c313766250920,0x6625202c38366625,0x30376625202c3336,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x366625202c323766,0x2c35366625202c39,0x090a3b3137662520\n"
".quad 0x203233662e6c756d,0x25202c3337662509,0x376625202c383666,0x2e627573090a3b32\n"
".quad 0x3766250920323366,0x2c33366625202c34,0x090a3b3337662520,0x203233662e6c756d\n"
".quad 0x25202c3537662509,0x376625202c373666,0x2e627573090a3b32,0x3766250920323366\n"
".quad 0x2c34366625202c36,0x090a3b3537662520,0x203233662e6c756d,0x25202c3737662509\n"
".quad 0x376625202c393666,0x2e627573090a3b32,0x3766250920323366,0x2c35366625202c38\n"
".quad 0x090a3b3737662520,0x09373109636f6c2e,0x73090a3009393332,0x09203233662e6275\n"
".quad 0x6625202c39376625,0x32366625202c3835,0x6f632e646c090a3b,0x203233662e74736e\n"
".quad 0x5b202c3038662509,0x382b736d61726170,0x6c756d090a3b5d38,0x662509203233662e\n"
".quad 0x30386625202c3138,0x0a3b39376625202c,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x61705b202c323866,0x3030312b736d6172,0x632e646c090a3b5d,0x3233662e74736e6f\n"
".quad 0x202c333866250920,0x2b736d617261705b,0x646c090a3b5d3639,0x662e74736e6f632e\n"
".quad 0x3438662509203233,0x6d617261705b202c,0x090a3b5d32392b73,0x203233662e6c756d\n"
".quad 0x25202c3538662509,0x386625202c383666,0x2e6c756d090a3b31,0x3866250920323366\n"
".quad 0x2c33366625202c36,0x090a3b3438662520,0x203233662e627573,0x25202c3738662509\n"
".quad 0x386625202c363866,0x2e616d66090a3b35,0x09203233662e6e72,0x6625202c38386625\n"
".quad 0x33386625202c3437,0x0a3b37386625202c,0x2e6e722e616d6609,0x3866250920323366\n"
".quad 0x2c36356625202c39,0x25202c3238662520,0x756d090a3b383866,0x2509203233662e6c\n"
".quad 0x366625202c303966,0x3b31386625202c37,0x33662e6c756d090a,0x2c31396625092032\n"
".quad 0x25202c3436662520,0x7573090a3b343866,0x2509203233662e62,0x396625202c323966\n"
".quad 0x3b30396625202c31,0x6e722e616d66090a,0x662509203233662e,0x36376625202c3339\n"
".quad 0x202c33386625202c,0x66090a3b32396625,0x33662e6e722e616d,0x2c34396625092032\n"
".quad 0x25202c3535662520,0x396625202c323866,0x2e6c756d090a3b33,0x3966250920323366\n"
".quad 0x2c39366625202c35,0x090a3b3138662520,0x203233662e6c756d,0x25202c3639662509\n"
".quad 0x386625202c353666,0x2e627573090a3b34,0x3966250920323366,0x2c36396625202c37\n"
".quad 0x090a3b3539662520,0x662e6e722e616d66,0x3839662509203233,0x202c38376625202c\n"
".quad 0x6625202c33386625,0x616d66090a3b3739,0x203233662e6e722e,0x25202c3939662509\n"
".quad 0x386625202c373566,0x3b38396625202c32,0x6e752e617262090a,0x315f744c24092069\n"
".quad 0x3b30333136315f30,0x5f30315f744c240a,0x200a3a3638333631,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313133\n"
".quad 0x656c6562616c2064,0x30315f744c242064,0x090a32363335315f,0x203233662e766f6d\n"
".quad 0x30202c3939662509,0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x30306630202c3439,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x2c39386625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x4c240a30202f2f09,0x3136315f30315f74,0x3c2f2f200a3a3033,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31313320656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x35315f30315f744c,0x6f6c2e090a323633,0x3732330937310963\n"
".quad 0x2e646461090a3009,0x3466250920323366,0x2c39386625202c30,0x090a3b3034662520\n"
".quad 0x203233662e646461,0x25202c3933662509,0x336625202c343966,0x2e646461090a3b39\n"
".quad 0x3366250920323366,0x2c39396625202c38,0x240a3b3833662520,0x35315f30315f744c\n"
".quad 0x2f2f200a3a383136,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x313320656e696c20,0x2064616568202c31,0x2064656c6562616c,0x315f30315f744c24\n"
".quad 0x6c2e090a32363335,0x313309373109636f,0x646461090a300936,0x722509203233752e\n"
".quad 0x33367225202c3336,0x6461090a3b31202c,0x2509203233752e64,0x357225202c313972\n"
".quad 0x3b30367225202c38,0x6e2e70746573090a,0x2509203233752e65,0x367225202c323170\n"
".quad 0x3b31397225202c33,0x203231702540090a,0x744c240920617262,0x363335315f30315f\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c34353320656e69,0x616c206461656820,0x4c242064656c6562,0x3034315f30315f74\n"
".quad 0x2e617262090a3238,0x744c240920696e75,0x353834315f30315f,0x315f744c240a3b30\n"
".quad 0x3a38353439315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3435332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x32383034315f3031,0x33662e766f6d090a,0x2c38336625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c39336625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3466250920323366\n"
".quad 0x3030306630202c30,0x20203b3030303030,0x0a30202f2f092020,0x315f30315f744c24\n"
".quad 0x4c240a3a30353834,0x3431355f30315f74,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c34353320656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x383034315f30315f,0x09636f6c2e090a32,0x3009313333093731\n"
".quad 0x33662e766f6d090a,0x2c37336625092032,0x090a3b3034662520,0x203233662e766f6d\n"
".quad 0x25202c3633662509,0x6f6d090a3b393366,0x2509203233662e76,0x336625202c353366\n"
".quad 0x6557444c240a3b38,0x32315a5f5f69646e,0x64697247636c6163,0x746e693468736148\n"
".quad 0x3a315f3738315f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3435332065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x32383034315f3031,0x3109636f6c2e090a,0x0a30093336330937,0x3233662e64646109\n"
".quad 0x202c343366250920,0x6625202c37336625,0x646461090a3b3433,0x662509203233662e\n"
".quad 0x36336625202c3333,0x0a3b33336625202c,0x3233662e64646109,0x202c323366250920\n"
".quad 0x6625202c35336625,0x646461090a3b3233,0x722509203233732e,0x37327225202c3732\n"
".quad 0x6573090a3b31202c,0x33732e656e2e7074,0x2c33317025092032,0x25202c3732722520\n"
".quad 0x2540090a3b343272,0x2061726220333170,0x5f30315f744c2409,0x200a3b3238303431\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c343533,0x656c6562616c2064,0x30315f744c242064,0x090a34313333315f\n"
".quad 0x203233732e646461,0x25202c3632722509,0x0a3b31202c363272,0x3233752e766f6d09\n"
".quad 0x202c323972250920,0x70746573090a3b32,0x203233732e656e2e,0x25202c3431702509\n"
".quad 0x397225202c363272,0x31702540090a3b32,0x2409206172622034,0x33315f30315f744c\n"
".quad 0x2f2f200a3b343133,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353320656e696c20,0x2064616568202c34,0x2064656c6562616c,0x315f30315f744c24\n"
".quad 0x6461090a36343532,0x2509203233732e64,0x327225202c353272,0x6d090a3b31202c35\n"
".quad 0x09203233752e766f,0x3b32202c33397225,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x327225202c353170,0x3b33397225202c35,0x203531702540090a,0x744c240920617262\n"
".quad 0x343532315f30315f,0x636f6c2e090a3b36,0x0931373309373109,0x6f632e646c090a30\n"
".quad 0x203233662e74736e,0x202c303031662509,0x2b736d617261705b,0x6461090a3b5d3631\n"
".quad 0x2509203233662e64,0x6625202c31303166,0x336625202c303031,0x632e646c090a3b31\n"
".quad 0x3233662e74736e6f,0x2c32303166250920,0x736d617261705b20,0x7573090a3b5d342b\n"
".quad 0x2509203233662e62,0x6625202c33303166,0x366625202c323031,0x6f632e646c090a3b\n"
".quad 0x203233662e74736e,0x202c343031662509,0x2b736d617261705b,0x627573090a3b5d30\n"
".quad 0x662509203233662e,0x316625202c353031,0x3b356625202c3430,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x5b202c3630316625,0x382b736d61726170,0x2e627573090a3b5d\n"
".quad 0x3166250920323366,0x30316625202c3730,0x0a3b376625202c36,0x3233662e6c756d09\n"
".quad 0x2c38303166250920,0x202c333031662520,0x090a3b3330316625,0x662e6e722e616d66\n"
".quad 0x3031662509203233,0x3530316625202c39,0x2c3530316625202c,0x0a3b383031662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x30316625202c3031,0x3730316625202c37\n"
".quad 0x3b3930316625202c,0x722e74727173090a,0x2509203233662e6e,0x6625202c31313166\n"
".quad 0x6573090a3b303131,0x33662e74672e7074,0x2c36317025092032,0x202c313031662520\n"
".quad 0x090a3b3131316625,0x6220363170252140,0x5f744c2409206172,0x32323937315f3031\n"
".quad 0x09636f6c2e090a3b,0x3009303332093731,0x33662e67656e090a,0x3231316625092032\n"
".quad 0x0a3b32316625202c,0x3233662e67656e09,0x2c33313166250920,0x090a3b3431662520\n"
".quad 0x662e6e722e706372,0x3131662509203233,0x3131316625202c34,0x662e6c756d090a3b\n"
".quad 0x3131662509203233,0x3330316625202c35,0x3b3431316625202c,0x33662e6c756d090a\n"
".quad 0x3631316625092032,0x2c3530316625202c,0x0a3b343131662520,0x3233662e6c756d09\n"
".quad 0x2c37313166250920,0x202c373031662520,0x090a3b3431316625,0x203233662e6c756d\n"
".quad 0x202c383131662509,0x25202c3531316625,0x656e090a3b333166,0x2509203233662e67\n"
".quad 0x6625202c39313166,0x6d66090a3b383131,0x3233662e6e722e61,0x2c30323166250920\n"
".quad 0x202c363131662520,0x25202c3231316625,0x66090a3b39313166,0x33662e6e722e616d\n"
".quad 0x3132316625092032,0x2c3731316625202c,0x202c333131662520,0x090a3b3032316625\n"
".quad 0x203233662e6c756d,0x202c323231662509,0x25202c3631316625,0x6d090a3b31323166\n"
".quad 0x09203233662e6c75,0x25202c3332316625,0x6625202c35313166,0x756d090a3b313231\n"
".quad 0x2509203233662e6c,0x6625202c34323166,0x316625202c373131,0x6f6c2e090a3b3132\n"
".quad 0x3733320937310963,0x2e627573090a3009,0x3166250920323366,0x30316625202c3532\n"
".quad 0x3131316625202c31,0x6f632e646c090a3b,0x203233662e74736e,0x202c363231662509\n"
".quad 0x2b736d617261705b,0x756d090a3b5d3838,0x2509203233662e6c,0x6625202c37323166\n"
".quad 0x316625202c363231,0x2e646c090a3b3532,0x33662e74736e6f63,0x3832316625092032\n"
".quad 0x6d617261705b202c,0x090a3b5d36392b73,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x61705b202c393231,0x5d32392b736d6172,0x662e6c756d090a3b,0x3331662509203233\n"
".quad 0x3631316625202c30,0x3b3732316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c313331,0x3932316625202c32,0x3b3033316625202c,0x33662e646461090a\n"
".quad 0x3233316625092032,0x202c32316625202c,0x090a3b3232316625,0x662e6e722e616d66\n"
".quad 0x3331662509203233,0x3832316625202c33,0x2c3233316625202c,0x0a3b313331662520\n"
".quad 0x3233662e67656e09,0x2c34333166250920,0x0a3b333331662520,0x3233662e6c756d09\n"
".quad 0x2c35333166250920,0x202c353131662520,0x090a3b3732316625,0x662e6e722e616d66\n"
".quad 0x3331662509203233,0x2c33316625202c36,0x202c393231662520,0x090a3b3533316625\n"
".quad 0x203233662e646461,0x202c373331662509,0x25202c3332316625,0x6d66090a3b333166\n"
".quad 0x3233662e6e722e61,0x2c38333166250920,0x202c383231662520,0x25202c3733316625\n"
".quad 0x6e090a3b36333166,0x09203233662e6765,0x25202c3933316625,0x6d090a3b38333166\n"
".quad 0x09203233662e6c75,0x25202c3034316625,0x6625202c37313166,0x6d66090a3b373231\n"
".quad 0x3233662e6e722e61,0x2c31343166250920,0x25202c3431662520,0x6625202c39323166\n"
".quad 0x6461090a3b303431,0x2509203233662e64,0x6625202c32343166,0x316625202c343231\n"
".quad 0x2e616d66090a3b34,0x09203233662e6e72,0x25202c3334316625,0x6625202c38323166\n"
".quad 0x316625202c323431,0x67656e090a3b3134,0x662509203233662e,0x316625202c343431\n"
".quad 0x617262090a3b3334,0x4c240920696e752e,0x3637315f30315f74,0x5f744c240a3b3636\n"
".quad 0x32323937315f3031,0x662e766f6d090a3a,0x3431662509203233,0x3030306630202c34\n"
".quad 0x20203b3030303030,0x090a30202f2f0920,0x203233662e766f6d,0x202c393331662509\n"
".quad 0x3030303030306630,0x2f092020203b3030,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x306630202c343331,0x3b30303030303030,0x30202f2f09202020,0x5f30315f744c240a\n"
".quad 0x090a3a3636363731,0x09373109636f6c2e,0x61090a3009323733,0x09203233662e6464\n"
".quad 0x6625202c34336625,0x336625202c343331,0x2e646461090a3b34,0x3366250920323366\n"
".quad 0x3933316625202c33,0x0a3b33336625202c,0x3233662e64646109,0x202c323366250920\n"
".quad 0x25202c3434316625,0x6c2e090a3b323366,0x373309373109636f,0x6c756d090a300936\n"
".quad 0x203233752e6f6c2e,0x25202c3439722509,0x090a3b38202c3572,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x3b34397225202c31,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c32647225,0x726170616475635f,0x6c6f63385a5f5f6d,0x663650446564696c\n"
".quad 0x5f30533474616f6c,0x35505f30535f3053,0x5f6a5032746e6975,0x656c636974726170\n"
".quad 0x090a3b5d68736148,0x203436752e646461,0x25202c3364722509,0x647225202c316472\n"
".quad 0x672e646c090a3b32,0x32762e6c61626f6c,0x257b09203233752e,0x363972252c353972\n"
".quad 0x336472255b202c7d,0x6f6d090a3b5d302b,0x2509203233732e76,0x397225202c373972\n"
".quad 0x2e766f6d090a3b35,0x3972250920323373,0x3b36397225202c38,0x3109636f6c2e090a\n"
".quad 0x0a30093737330937,0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c346472\n"
".quad 0x6d72617061647563,0x6c6c6f63385a5f5f,0x6c66365044656469,0x535f30533474616f\n"
".quad 0x7535505f30535f30,0x6e5f6a5032746e69,0x0a3b5d6c65567765,0x3233662e64646109\n"
".quad 0x2c35343166250920,0x25202c3231662520,0x6f6d090a3b343366,0x2509203233732e76\n"
".quad 0x397225202c393972,0x2e6c756d090a3b38,0x09203233752e6f6c,0x25202c3030317225\n"
".quad 0x3b3631202c393972,0x36752e747663090a,0x2509203233752e34,0x317225202c356472\n"
".quad 0x646461090a3b3030,0x722509203436752e,0x35647225202c3664,0x0a3b34647225202c\n"
".quad 0x626f6c672e747309,0x09203233662e6c61,0x5d302b366472255b,0x3b3534316625202c\n"
".quad 0x33662e646461090a,0x3634316625092032,0x202c33316625202c,0x6d090a3b33336625\n"
".quad 0x09203233732e766f,0x25202c3130317225,0x756d090a3b383972,0x3233752e6f6c2e6c\n"
".quad 0x2c32303172250920,0x202c313031722520,0x747663090a3b3631,0x3233752e3436752e\n"
".quad 0x202c376472250920,0x090a3b3230317225,0x203436752e646461,0x25202c3864722509\n"
".quad 0x647225202c376472,0x672e7473090a3b34,0x33662e6c61626f6c,0x386472255b092032\n"
".quad 0x316625202c5d342b,0x646461090a3b3634,0x662509203233662e,0x316625202c373431\n"
".quad 0x3b32336625202c34,0x33732e766f6d090a,0x3330317225092032,0x0a3b38397225202c\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323375,0x30317225202c3430,0x090a3b3631202c33\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x3430317225202c39,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x2c39647225202c30,0x090a3b3464722520,0x61626f6c672e7473\n"
".quad 0x5b09203233662e6c,0x5d382b3031647225,0x3b3734316625202c,0x33732e766f6d090a\n"
".quad 0x3530317225092032,0x0a3b38397225202c,0x2e6f6c2e6c756d09,0x3172250920323375\n"
".quad 0x30317225202c3630,0x090a3b3631202c35,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x30317225202c3131,0x2e646461090a3b36,0x6472250920343675,0x31647225202c3231\n"
".quad 0x3b34647225202c31,0x6f6c672e7473090a,0x203233662e6c6162,0x2b32316472255b09\n"
".quad 0x316625202c5d3231,0x636f6c2e090a3b35,0x0931383309373109,0x3b74697865090a30\n"
".quad 0x646e6557444c240a,0x6c6c6f63385a5f5f,0x6c66365044656469,0x535f30533474616f\n"
".quad 0x7535505f30535f30,0x0a3a6a5032746e69,0x5a5f202f2f207d09,0x6564696c6c6f6338\n"
".quad 0x74616f6c66365044,0x535f30535f305334,0x746e697535505f30,0x0000000a0a6a5032\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[6708];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"b94070212e540715",(char*)"/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x62916fad,&__elfEntries1};
# 3 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c" 2
struct __T20 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float __par4;int __dummy_field;};
struct __T21 {float4 *__par0;uint *__par1;uint *__par2;int __dummy_field;};
struct __T22 {float4 *__par0;uint2 *__par1;int __dummy_field;};
struct __T23 {uint2 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float4 *__par4;uint *__par5;int __dummy_field;};
struct __T24 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;uint2 *__par4;uint *__par5;int __dummy_field;};
extern void __device_stub__Z9integrateP6float4S0_S0_S0_f(float4 *, float4 *, float4 *, float4 *, float);
extern void __device_stub__Z11updateGridDP6float4PjS1_(float4 *, uint *, uint *);
extern void __device_stub__Z9calcHashDP6float4P5uint2(float4 *, uint2 *);
extern void __device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *);
extern void __device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *);
static void __sti____cudaRegisterAll_51_tmpxft_00000aee_00000000_4_particles_kernel_cpp1_ii_dee98040(void) __attribute__((__constructor__));
void __device_stub__Z9integrateP6float4S0_S0_S0_f(float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float __par4){ struct __T20 *__T25 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate))); };}
void integrate( float4 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,float __cuda_4)
# 62 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{__device_stub__Z9integrateP6float4S0_S0_S0_f( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);
# 87 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
void __device_stub__Z11updateGridDP6float4PjS1_( float4 *__par0, uint *__par1, uint *__par2) { struct __T21 *__T219 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T219->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T219->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T219->__par2) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint *, uint *))updateGridD)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint *, uint *))updateGridD))); }; }
void updateGridD( float4 *__cuda_0,uint *__cuda_1,uint *__cuda_2)
# 135 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{__device_stub__Z11updateGridDP6float4PjS1_( __cuda_0,__cuda_1,__cuda_2);
# 143 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
void __device_stub__Z9calcHashDP6float4P5uint2( float4 *__par0, uint2 *__par1) { struct __T22 *__T220 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T220->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T220->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint2 *))calcHashD)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint2 *))calcHashD))); }; }
void calcHashD( float4 *__cuda_0,uint2 *__cuda_1)
# 149 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{__device_stub__Z9calcHashDP6float4P5uint2( __cuda_0,__cuda_1);
# 159 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
void __device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj( uint2 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float4 *__par4, uint *__par5) { struct __T23 *__T221 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T221->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T221->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T221->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T221->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T221->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T221->__par5) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD)); (void)cudaLaunch(((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD))); }; }
void reorderDataAndFindCellStartD( uint2 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,float4 *__cuda_4,uint *__cuda_5)
# 170 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{__device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 202 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
void __device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj( float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, uint2 *__par4, uint *__par5) { struct __T24 *__T2134 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2134->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2134->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2134->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2134->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2134->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2134->__par5) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD))); }; }
void collideD( float4 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,uint2 *__cuda_4,uint *__cuda_5)
# 346 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
{__device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 381 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_00000aee_00000000_4_particles_kernel_cpp1_ii_dee98040(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD), (char*)"_Z8collideDP6float4S0_S0_S0_P5uint2Pj", "_Z8collideDP6float4S0_S0_S0_P5uint2Pj", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD), (char*)"_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", "_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint2 *))calcHashD), (char*)"_Z9calcHashDP6float4P5uint2", "_Z9calcHashDP6float4P5uint2", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint *, uint *))updateGridD), (char*)"_Z11updateGridDP6float4PjS1_", "_Z11updateGridDP6float4PjS1_", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate), (char*)"_Z9integrateP6float4S0_S0_S0_f", "_Z9integrateP6float4S0_S0_S0_f", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldPosTex, (const void**)"oldPosTex", "oldPosTex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldVelTex, (const void**)"oldVelTex", "oldVelTex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&particleHashTex, (const void**)"particleHashTex", "particleHashTex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&cellStartTex, (const void**)"cellStartTex", "cellStartTex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCountersTex, (const void**)"gridCountersTex", "gridCountersTex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCellsTex, (const void**)"gridCellsTex", "gridCellsTex", 1, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&params, (char*)"params", "params", 0, 112, 1, 0); }
# 1 "/tmp/tmpxft_00000aee_00000000-1_particles_kernel.cudafe1.stub.c" 2

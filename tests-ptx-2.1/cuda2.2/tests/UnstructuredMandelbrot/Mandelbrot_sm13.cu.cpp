# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
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
# 6 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);
# 9 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.h"
extern "C" void RunMandelbrot1_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);
# 13 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);
# 16 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.h"
extern "C" void RunMandelbrot1_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);
# 20 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.h"
extern "C" int inEmulationMode();
# 15 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
inline void dsdeq(float &a0, float &a1, double b)
# 16 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{
# 17 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
a0 = ((float)b);
# 18 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
a1 = ((float)(b - a0));
# 19 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
}
# 22 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsfeq(float &a0, float &a1, float b)
# 23 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 26 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 29 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsadd(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 30 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 39 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 42 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dssub(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 43 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 52 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 57 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsmul(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 58 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 82 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 126 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
template< class T> __attribute__((unused)) inline void
# 127 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
CalcMandelbrot(int *
# 128 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
output, const T *
# 129 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xPos, const T
# 130 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yPos, const T
# 131 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xJParam, const T
# 132 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yJParam, const int
# 133 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
crunch, const bool
# 134 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
isJulia, const int
# 135 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
points)
# 136 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 190 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 194 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
template< class T> __attribute__((unused)) inline int
# 195 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
CalcMandelbrot(const T
# 196 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xPos, const T
# 197 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yPos, const T
# 198 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xJParam, const T
# 199 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yJParam, const int
# 200 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
crunch, const bool
# 201 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
isJulia)
# 202 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 230 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 234 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline int CalcMandelbrotDS(const float
# 235 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xPos0, const float
# 236 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xPos1, const float
# 237 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yPos0, const float
# 238 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yPos1, const float
# 239 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
xJParam, const float
# 240 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
yJParam, const int
# 241 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
crunch, const bool
# 242 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
isJulia)
# 243 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 293 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 297 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
__attribute__((unused)) inline int CheckColors(const uchar4 &color0, const uchar4 &color1)
# 298 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 303 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
exit(___);}
# 308 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
inline int iDivUp(int a, int b)
# 309 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
{
# 310 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
return ((a % b) != 0) ? ((a / b) + 1) : (a / b);
# 311 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_kernel.cu"
}
# 21 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
static unsigned blockCounter;
# 23 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
template< class T, const int pointsPerThread> static void
# 24 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__wrapper__device_stub_Mandelbrot0_sm13(uchar4 *&dst, const int &imageW, const int &
# 25 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 26 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &
# 27 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
frame, const int &animationFrame, const int &gridWidth, const int &
# 28 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
numBlocks, const bool &isJ) ;
# 23 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
template< class T, const int pointsPerThread> void
# 24 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
Mandelbrot0_sm13(uchar4 *dst, const int imageW, const int
# 25 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
imageH, const int crunch, const T xOff, const T yOff, const T
# 26 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int
# 27 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
frame, const int animationFrame, const int gridWidth, const int
# 28 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
numBlocks, const bool isJ)
# 29 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{__wrapper__device_stub_Mandelbrot0_sm13<T,pointsPerThread>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,gridWidth,numBlocks,isJ);
# 107 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 111 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
void MandelbrotDS0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float
# 112 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
yOff0, const float yOff1, const float xJP, const float yJP, const float scale, const uchar4
# 113 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
colors, const int frame, const int animationFrame, const int gridWidth, const int
# 114 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
numBlocks, const bool isJ) ;
# 186 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
template< class T> static void
# 187 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__wrapper__device_stub_Mandelbrot1_sm13(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 188 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
# 189 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
animationFrame, const int &gridWidth, const int &numBlocks, const bool &isJ) ;
# 186 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
template< class T> void
# 187 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
Mandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
# 188 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
# 189 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
animationFrame, const int gridWidth, const int numBlocks, const bool isJ)
# 190 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{__wrapper__device_stub_Mandelbrot1_sm13<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,gridWidth,numBlocks,isJ);
# 267 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 270 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
void MandelbrotDS1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float
# 271 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xOff0, const float xOff1, const float yOff0, const float yOff1, const float
# 272 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xJP, const float yJP, const float scale, const uchar4 colors, const int
# 273 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
frame, const int animationFrame, const int gridWidth, const int numBlocks, const bool isJ) ;
# 362 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
void RunMandelbrot0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double
# 363 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xjp, const double yjp, const double scale, const uchar4 colors, const int frame, const int
# 364 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
animationFrame, const int mode, const int numSMs, const bool isJ)
# 365 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{
# 366 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dim3 threads(16, 16);
# 367 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dim3 grid(iDivUp(iDivUp(imageW, 16), 16), iDivUp(imageH, 16));
# 370 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
unsigned hBlockCounter = (0);
# 371 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__cudaSafeCall(cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned), 0, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu", 371);
# 373 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
int numWorkerBlocks = numSMs;
# 375 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
switch (mode) {
# 376 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
default:
# 377 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 0:
# 378 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot0_sm13< float, 16> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 380 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 381 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 1:
# 382 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
float x0, x1, y0, y1;
# 383 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dsdeq(x0, x1, xOff);
# 384 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dsdeq(y0, y1, yOff);
# 385 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : MandelbrotDS0_sm13(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 387 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 388 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 2:
# 389 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot0_sm13< double, 16> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 391 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 392 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 393 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__cutilCheckMsg("Mandelbrot0_sm13 kernel execution failed.\n", "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu", 393);
# 394 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 397 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
void RunMandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double
# 398 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
xjp, const double yjp, const double scale, const uchar4 colors, const int frame, const int
# 399 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
animationFrame, const int mode, const int numSMs, const bool isJ)
# 400 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{
# 401 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dim3 threads(16, 16);
# 402 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));
# 405 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
unsigned hBlockCounter = (0);
# 406 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__cudaSafeCall(cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned), 0, cudaMemcpyHostToDevice), "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu", 406);
# 408 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
int numWorkerBlocks = numSMs;
# 410 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
switch (mode) {
# 411 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
default:
# 412 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 0:
# 413 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot1_sm13< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 415 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 416 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 1:
# 417 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
float x0, x1, y0, y1;
# 418 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dsdeq(x0, x1, xOff);
# 419 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
dsdeq(y0, y1, yOff);
# 420 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : MandelbrotDS1_sm13(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 422 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 423 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
case 2:
# 424 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot1_sm13< double> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 426 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
break;
# 427 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 429 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
__cutilCheckMsg("Mandelbrot1_sm13 kernel execution failed.\n", "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu", 429);
# 430 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 434 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
int inEmulationMode()
# 435 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{
# 437 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
return 1;
# 441 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000ed1_00000000-3_Mandelbrot_sm13.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000ed1_00000000-3_Mandelbrot_sm13.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220322e33206363\n"
".quad 0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3930,0x662e20656c626973\n"
".quad 0x61702e2820636e75,0x3233732e206d6172,0x72616475635f5f20,0x36315a5f5f667465\n"
".quad 0x646e614d636c6143,0x5344746f72626c65,0x6269666666666666,0x614336315a5f2029\n"
".quad 0x6c65646e614d636c,0x66665344746f7262,0x2820626966666666,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x31666d7261706164,0x6c614336315a5f5f,0x626c65646e614d63\n"
".quad 0x6666665344746f72,0x2e202c6269666666,0x662e206d61726170,0x6475635f5f203233\n"
".quad 0x5f32666d72617061,0x636c614336315a5f,0x72626c65646e614d,0x666666665344746f\n"
".quad 0x702e202c62696666,0x33662e206d617261,0x616475635f5f2032,0x5f5f33666d726170\n"
".quad 0x4d636c614336315a,0x6f72626c65646e61,0x6666666666534474,0x61702e202c626966\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261,0x614d636c61433631\n"
".quad 0x746f72626c65646e,0x6666666666665344,0x7261702e202c6269,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x315a5f5f35666d72,0x6e614d636c614336,0x44746f72626c6564\n"
".quad 0x6966666666666653,0x617261702e202c62,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x36315a5f5f36666d,0x646e614d636c6143,0x5344746f72626c65,0x6269666666666666\n"
".quad 0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563,0x4336315a5f5f3766\n"
".quad 0x65646e614d636c61,0x665344746f72626c,0x2c62696666666666,0x206d617261702e20\n"
".quad 0x635f5f203233732e,0x666d726170616475,0x614336315a5f5f38,0x6c65646e614d636c\n"
".quad 0x66665344746f7262,0x0a29626966666666,0x62697369762e090a,0x636e75662e20656c\n"
".quad 0x6c614334315a5f20,0x626c65646e614d63,0x5076456649746f72,0x5f31535f544b5069\n"
".quad 0x62695f31535f3153,0x617261702e282069,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x34315a5f5f31666d,0x646e614d636c6143,0x6649746f72626c65,0x5f544b5069507645\n"
".quad 0x31535f31535f3153,0x702e202c6962695f,0x36752e206d617261,0x616475635f5f2034\n"
".quad 0x5f5f32666d726170,0x4d636c614334315a,0x6f72626c65646e61,0x5069507645664974\n"
".quad 0x31535f31535f544b,0x2c6962695f31535f,0x206d617261702e20,0x635f5f203233662e\n"
".quad 0x666d726170616475,0x614334315a5f5f33,0x6c65646e614d636c,0x76456649746f7262\n"
".quad 0x31535f544b506950,0x695f31535f31535f,0x7261702e202c6962,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x315a5f5f34666d72,0x6e614d636c614334,0x49746f72626c6564\n"
".quad 0x544b506950764566,0x535f31535f31535f,0x2e202c6962695f31,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5f35666d72617061,0x636c614334315a5f,0x72626c65646e614d\n"
".quad 0x695076456649746f,0x535f31535f544b50,0x6962695f31535f31,0x6d617261702e202c\n"
".quad 0x5f5f203233732e20,0x6d72617061647563,0x4334315a5f5f3666,0x65646e614d636c61\n"
".quad 0x456649746f72626c,0x535f544b50695076,0x5f31535f31535f31,0x61702e202c696269\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x5a5f5f37666d7261,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x4b50695076456649,0x5f31535f31535f54,0x202c6962695f3153\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x38666d7261706164,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5076456649746f72,0x5f31535f544b5069,0x62695f31535f3153\n"
".quad 0x69762e090a0a2969,0x662e20656c626973,0x34315a5f20636e75,0x646e614d636c6143\n"
".quad 0x6449746f72626c65,0x5f544b5069507645,0x31535f31535f3153,0x702e28206962695f\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x5f5f31666d726170,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x5069507645644974,0x31535f31535f544b,0x2c6962695f31535f\n"
".quad 0x206d617261702e20,0x635f5f203436752e,0x666d726170616475,0x614334315a5f5f32\n"
".quad 0x6c65646e614d636c,0x76456449746f7262,0x31535f544b506950,0x695f31535f31535f\n"
".quad 0x7261702e202c6962,0x203436662e206d61,0x6170616475635f5f,0x315a5f5f33666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x544b506950764564,0x535f31535f31535f\n"
".quad 0x2e202c6962695f31,0x662e206d61726170,0x6475635f5f203436,0x5f34666d72617061\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x695076456449746f,0x535f31535f544b50\n"
".quad 0x6962695f31535f31,0x6d617261702e202c,0x5f5f203436662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3566,0x65646e614d636c61,0x456449746f72626c,0x535f544b50695076\n"
".quad 0x5f31535f31535f31,0x61702e202c696269,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f36666d7261,0x614d636c61433431,0x746f72626c65646e,0x4b50695076456449\n"
".quad 0x5f31535f31535f54,0x202c6962695f3153,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x37666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5076456449746f72\n"
".quad 0x5f31535f544b5069,0x62695f31535f3153,0x617261702e202c69,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x34315a5f5f38666d,0x646e614d636c6143,0x6449746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x090a0a296962695f,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323373,0x5f5f667465726164\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945664974,0x5f30535f30535f30\n"
".quad 0x34315a5f20296269,0x646e614d636c6143,0x6649746f72626c65,0x535f30535f546945\n"
".quad 0x2062695f30535f30,0x206d617261702e28,0x635f5f203233662e,0x666d726170616475\n"
".quad 0x614334315a5f5f31,0x6c65646e614d636c,0x69456649746f7262,0x5f30535f30535f54\n"
".quad 0x2e202c62695f3053,0x662e206d61726170,0x6475635f5f203233,0x5f32666d72617061\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053\n"
".quad 0x61702e202c62695f,0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261\n"
".quad 0x614d636c61433431,0x746f72626c65646e,0x30535f5469456649,0x695f30535f30535f\n"
".quad 0x617261702e202c62,0x5f203233662e206d,0x726170616475635f,0x34315a5f5f34666d\n"
".quad 0x646e614d636c6143,0x6649746f72626c65,0x535f30535f546945,0x2c62695f30535f30\n"
".quad 0x206d617261702e20,0x635f5f203233732e,0x666d726170616475,0x614334315a5f5f35\n"
".quad 0x6c65646e614d636c,0x69456649746f7262,0x5f30535f30535f54,0x2e202c62695f3053\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5f36666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053,0x2e090a0a2962695f\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6674657261,0x614d636c61433431,0x746f72626c65646e,0x30535f5469456449\n"
".quad 0x695f30535f30535f,0x4334315a5f202962,0x65646e614d636c61,0x456449746f72626c\n"
".quad 0x30535f30535f5469,0x282062695f30535f,0x2e206d617261702e,0x75635f5f20343666\n"
".quad 0x31666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5469456449746f72\n"
".quad 0x535f30535f30535f,0x702e202c62695f30,0x36662e206d617261,0x616475635f5f2034\n"
".quad 0x5f5f32666d726170,0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974\n"
".quad 0x5f30535f30535f30,0x7261702e202c6269,0x203436662e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f33666d72,0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564\n"
".quad 0x62695f30535f3053,0x6d617261702e202c,0x5f5f203436662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3466,0x65646e614d636c61,0x456449746f72626c,0x30535f30535f5469\n"
".quad 0x202c62695f30535f,0x2e206d617261702e,0x75635f5f20323373,0x35666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456449746f72,0x535f30535f30535f\n"
".quad 0x702e202c62695f30,0x33732e206d617261,0x616475635f5f2032,0x5f5f36666d726170\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30\n"
".quad 0x2f2f090a0a296269,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x202f2f090a2d2d2d,0x6e696c69706d6f43,0x742f706d742f2067,0x30305f746678706d\n"
".quad 0x305f316465303030,0x2d30303030303030,0x6c65646e614d5f37,0x316d735f746f7262\n"
".quad 0x692e337070632e33,0x632f706d742f2820,0x58356e2e23494263,0x2f2f090a29695876\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f2f090a0a2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x202f2f090a2d2d2d\n"
".quad 0x3a736e6f6974704f,0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x0a2d2d2d2d2d2d2d,0x72615420202f2f09,0x2c7874703a746567,0x5f6d733a41534920\n"
".quad 0x69646e45202c3032,0x6c7474696c3a6e61,0x746e696f50202c65,0x3a657a6953207265\n"
".quad 0x20202f2f090a3436,0x74704f2809334f2d,0x6f6974617a696d69,0x296c6576656c206e\n"
".quad 0x672d20202f2f090a,0x6775626544280930,0x0a296c6576656c20,0x326d2d20202f2f09\n"
".quad 0x74726f7065522809,0x726f736976646120,0x2f2f090a29736569,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x662e090a0a2d2d2d,0x3c22093109656c69\n"
".quad 0x2d646e616d6d6f63,0x090a223e656e696c,0x093209656c69662e,0x6d742f706d742f22\n"
".quad 0x3030305f74667870,0x30305f3164653030,0x362d303030303030,0x626c65646e614d5f\n"
".quad 0x33316d735f746f72,0x326566616475632e,0x2e090a227570672e,0x22093309656c6966\n"
".quad 0x62696c2f7273752f,0x3836692f6363672f,0x2d78756e696c2d36,0x2e342e342f756e67\n"
".quad 0x64756c636e692f35,0x6665646474732f65,0x69662e090a22682e,0x752f22093409656c\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x7472632f6564756c\n"
".quad 0x5f6563697665642f,0x2e656d69746e7572,0x6c69662e090a2268,0x73752f2209350965\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x74736f682f656475\n"
".quad 0x73656e696665645f,0x69662e090a22682e,0x752f22093609656c,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x6975622f6564756c,0x7079745f6e69746c\n"
".quad 0x2e090a22682e7365,0x22093709656c6966,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x642f6564756c636e,0x79745f6563697665,0x090a22682e736570\n"
".quad 0x093809656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x745f726576697264,0x0a22682e73657079,0x3909656c69662e09\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x656361667275732f,0x682e73657079745f,0x656c69662e090a22,0x73752f2209303109\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x747865742f656475\n"
".quad 0x657079745f657275,0x662e090a22682e73,0x2209313109656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x762f6564756c636e,0x79745f726f746365\n"
".quad 0x090a22682e736570,0x323109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f6563697665642f,0x705f68636e75616c\n"
".quad 0x726574656d617261,0x662e090a22682e73,0x2209333109656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x632f6564756c636e,0x61726f74732f7472\n"
".quad 0x7373616c635f6567,0x69662e090a22682e,0x2f2209343109656c,0x6c636e692f727375\n"
".quad 0x737469622f656475,0x682e73657079742f,0x656c69662e090a22,0x73752f2209353109\n"
".quad 0x64756c636e692f72,0x682e656d69742f65,0x656c69662e090a22,0x6f682f2209363109\n"
".quad 0x616d726f6e2f656d,0x6f6b636568632f6c,0x636f7570672f7475,0x7365742f746f6c65\n"
".quad 0x322d7874702d7374,0x32616475632f312e,0x73747365742f322e,0x63757274736e552f\n"
".quad 0x6e614d6465727574,0x2f746f72626c6564,0x72626c65646e614d,0x656e72656b5f746f\n"
".quad 0x2e090a2275632e6c,0x09373109656c6966,0x6e2f656d6f682f22,0x68632f6c616d726f\n"
".quad 0x672f74756f6b6365,0x746f6c65636f7570,0x702d73747365742f,0x632f312e322d7874\n"
".quad 0x742f322e32616475,0x736e552f73747365,0x6572757463757274,0x626c65646e614d64\n"
".quad 0x646e614d2f746f72,0x735f746f72626c65,0x0a2275632e33316d,0x3109656c69662e09\n"
".quad 0x2f7273752f220938,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x6e6f6d6d6f632f65,0x6f6974636e75665f,0x2e090a22682e736e,0x09393109656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x6e75665f6874616d,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209303209\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x6874616d2f656475\n"
".quad 0x6e6174736e6f635f,0x2e090a22682e7374,0x09313209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x665f656369766564\n"
".quad 0x736e6f6974636e75,0x69662e090a22682e,0x2f2209323209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6d732f6564756c63,0x6d6f74615f31315f\n"
".quad 0x74636e75665f6369,0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220933\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x5f32315f6d732f65\n"
".quad 0x665f63696d6f7461,0x736e6f6974636e75,0x69662e090a22682e,0x2f2209343209656c\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6d732f6564756c63\n"
".quad 0x62756f645f33315f,0x74636e75665f656c,0x0a22682e736e6f69,0x3209656c69662e09\n"
".quad 0x2f7273752f220935,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x5f30325f6d732f65,0x665f63696d6f7461,0x736e6f6974636e75,0x69662e090a22682e\n"
".quad 0x2f2209363209656c,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x6d732f6564756c63,0x72746e695f30325f,0x682e736369736e69,0x656c69662e090a22\n"
".quad 0x73752f2209373209,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x667275732f656475,0x636e75665f656361,0x22682e736e6f6974,0x09656c69662e090a\n"
".quad 0x7273752f22093832,0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x75747865742f6564,0x68637465665f6572,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09393209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x6e75665f6874616d,0x645f736e6f697463,0x2e337874705f6c62\n"
".quad 0x762e090a0a0a2268,0x2e20656c62697369,0x702e2820636e7566,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f66746572,0x6e614d636c614336,0x44746f72626c6564\n"
".quad 0x6966666666666653,0x4336315a5f202962,0x65646e614d636c61,0x665344746f72626c\n"
".quad 0x2062696666666666,0x206d617261702e28,0x635f5f203233662e,0x666d726170616475\n"
".quad 0x614336315a5f5f31,0x6c65646e614d636c,0x66665344746f7262,0x202c626966666666\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x32666d7261706164,0x6c614336315a5f5f\n"
".quad 0x626c65646e614d63,0x6666665344746f72,0x2e202c6269666666,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5f33666d72617061,0x636c614336315a5f,0x72626c65646e614d\n"
".quad 0x666666665344746f,0x702e202c62696666,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f34666d726170,0x4d636c614336315a,0x6f72626c65646e61,0x6666666666534474\n"
".quad 0x61702e202c626966,0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f35666d7261\n"
".quad 0x614d636c61433631,0x746f72626c65646e,0x6666666666665344,0x7261702e202c6269\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x315a5f5f36666d72,0x6e614d636c614336\n"
".quad 0x44746f72626c6564,0x6966666666666653,0x617261702e202c62,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x36315a5f5f37666d,0x646e614d636c6143,0x5344746f72626c65\n"
".quad 0x6269666666666666,0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x4336315a5f5f3866,0x65646e614d636c61,0x665344746f72626c,0x2962696666666666\n"
".quad 0x65722e090a7b090a,0x25203233752e2067,0x090a3b3e31313c72,0x33662e206765722e\n"
".quad 0x3131323c66252032,0x6765722e090a3b3e,0x2520646572702e20,0x2e090a3b3e373c70\n"
".quad 0x3209363109636f6c,0x444c240a30093334,0x5f5f6e6967656257,0x4d636c614336315a\n"
".quad 0x6f72626c65646e61,0x6666666666534474,0x646c090a3a626966,0x662e6d617261702e\n"
".quad 0x2c31662509203233,0x616475635f5f5b20,0x5f5f31666d726170,0x4d636c614336315a\n"
".quad 0x6f72626c65646e61,0x6666666666534474,0x6d090a3b5d626966,0x09203233662e766f\n"
".quad 0x316625202c326625,0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c33662509\n"
".quad 0x726170616475635f,0x36315a5f5f32666d,0x646e614d636c6143,0x5344746f72626c65\n"
".quad 0x6269666666666666,0x2e766f6d090a3b5d,0x3466250920323366,0x090a3b336625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c35,0x33666d7261706164\n"
".quad 0x6c614336315a5f5f,0x626c65646e614d63,0x6666665344746f72,0x0a3b5d6269666666\n"
".quad 0x3233662e766f6d09,0x25202c3666250920,0x2e646c090a3b3566,0x33662e6d61726170\n"
".quad 0x202c376625092032,0x70616475635f5f5b,0x5a5f5f34666d7261,0x614d636c61433631\n"
".quad 0x746f72626c65646e,0x6666666666665344,0x6f6d090a3b5d6269,0x2509203233662e76\n"
".quad 0x3b376625202c3866,0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c396625\n"
".quad 0x6d72617061647563,0x4336315a5f5f3566,0x65646e614d636c61,0x665344746f72626c\n"
".quad 0x5d62696666666666,0x662e766f6d090a3b,0x3031662509203233,0x090a3b396625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x635f5f5b202c3131,0x666d726170616475\n"
".quad 0x614336315a5f5f36,0x6c65646e614d636c,0x66665344746f7262,0x3b5d626966666666\n"
".quad 0x33662e766f6d090a,0x2c32316625092032,0x090a3b3131662520,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x75635f5f5b202c31,0x37666d7261706164,0x6c614336315a5f5f\n"
".quad 0x626c65646e614d63,0x6666665344746f72,0x0a3b5d6269666666,0x3233732e766f6d09\n"
".quad 0x25202c3272250920,0x2e646c090a3b3172,0x33752e6d61726170,0x202c337225092032\n"
".quad 0x70616475635f5f5b,0x5a5f5f38666d7261,0x614d636c61433631,0x746f72626c65646e\n"
".quad 0x6666666666665344,0x7663090a3b5d6269,0x3233732e38732e74,0x25202c3472250920\n"
".quad 0x766f6d090a3b3372,0x722509203233752e,0x73090a3b30202c35,0x732e71652e707465\n"
".quad 0x2c31702509203233,0x7225202c34722520,0x31702540090a3b35,0x4c24092061726220\n"
".quad 0x323438335f305f74,0x09636f6c2e090a3b,0x3009333532093631,0x33662e766f6d090a\n"
".quad 0x2c33316625092032,0x090a3b3031662520,0x09363109636f6c2e,0x6d090a3009353532\n"
".quad 0x09203233662e766f,0x6625202c34316625,0x6f6c2e090a3b3231,0x3735320936310963\n"
".quad 0x2e766f6d090a3009,0x3166250920323366,0x0a3b366625202c35,0x363109636f6c2e09\n"
".quad 0x090a300938353209,0x203233662e766f6d,0x25202c3631662509,0x6f6c2e090a3b3866\n"
".quad 0x3935320936310963,0x2e766f6d090a3009,0x3166250920323366,0x0a3b326625202c37\n"
".quad 0x363109636f6c2e09,0x090a300930363209,0x203233662e766f6d,0x25202c3831662509\n"
".quad 0x6f6c2e090a3b3466,0x3136320936310963,0x2e6c756d090a3009,0x3166250920323366\n"
".quad 0x202c366625202c39,0x756d090a3b386625,0x2509203233662e6c,0x366625202c303266\n"
".quad 0x090a3b366625202c,0x203233662e766f6d,0x30202c3132662509,0x3034303030363466\n"
".quad 0x2f09202020203b30,0x090a33393138202f,0x203233662e6c756d,0x25202c3232662509\n"
".quad 0x31326625202c3666,0x722e616d66090a3b,0x2509203233662e6e,0x366625202c333266\n"
".quad 0x25202c386625202c,0x7573090a3b393166,0x2509203233662e62,0x326625202c343266\n"
".quad 0x0a3b366625202c32,0x3233662e64646109,0x202c353266250920,0x6625202c30326625\n"
".quad 0x627573090a3b3332,0x662509203233662e,0x32326625202c3632,0x0a3b34326625202c\n"
".quad 0x3233662e62757309,0x202c373266250920,0x6625202c35326625,0x6c756d090a3b3032\n"
".quad 0x662509203233662e,0x36326625202c3832,0x0a3b36326625202c,0x3233662e62757309\n"
".quad 0x202c393266250920,0x6625202c38326625,0x627573090a3b3032,0x662509203233662e\n"
".quad 0x2c366625202c3033,0x090a3b3632662520,0x203233662e627573,0x25202c3133662509\n"
".quad 0x326625202c333266,0x2e627573090a3b37,0x3366250920323366,0x2c35326625202c32\n"
".quad 0x090a3b3732662520,0x662e6e722e616d66,0x3333662509203233,0x202c36326625202c\n"
".quad 0x6625202c30336625,0x627573090a3b3932,0x662509203233662e,0x30326625202c3433\n"
".quad 0x0a3b32336625202c,0x2e6e722e616d6609,0x3366250920323366,0x2c36326625202c35\n"
".quad 0x25202c3033662520,0x6461090a3b333366,0x2509203233662e64,0x336625202c363366\n"
".quad 0x3b34336625202c31,0x6e722e616d66090a,0x662509203233662e,0x30336625202c3733\n"
".quad 0x202c30336625202c,0x61090a3b35336625,0x09203233662e6464,0x6625202c38336625\n"
".quad 0x37336625202c3633,0x722e616d66090a3b,0x2509203233662e6e,0x386625202c393366\n"
".quad 0x25202c386625202c,0x6461090a3b383366,0x2509203233662e64,0x326625202c303466\n"
".quad 0x3b39336625202c35,0x33662e766f6d090a,0x2c31346625092032,0x090a3b3034662520\n"
".quad 0x203233662e627573,0x25202c3234662509,0x326625202c303466,0x2e627573090a3b35\n"
".quad 0x3466250920323366,0x2c39336625202c33,0x090a3b3234662520,0x09363109636f6c2e\n"
".quad 0x6d090a3009323632,0x09203233662e6c75,0x6625202c34346625,0x0a3b346625202c32\n"
".quad 0x3233662e6c756d09,0x202c353466250920,0x326625202c326625,0x662e766f6d090a3b\n"
".quad 0x3634662509203233,0x303036346630202c,0x2020203b30303430,0x393138202f2f0920\n"
".quad 0x662e6c756d090a33,0x3734662509203233,0x25202c326625202c,0x6d66090a3b363466\n"
".quad 0x3233662e6e722e61,0x202c383466250920,0x346625202c326625,0x0a3b34346625202c\n"
".quad 0x3233662e62757309,0x202c393466250920,0x6625202c37346625,0x2e646461090a3b32\n"
".quad 0x3566250920323366,0x2c35346625202c30,0x090a3b3834662520,0x203233662e627573\n"
".quad 0x25202c3135662509,0x346625202c373466,0x2e627573090a3b39,0x3566250920323366\n"
".quad 0x2c30356625202c32,0x090a3b3534662520,0x203233662e6c756d,0x25202c3335662509\n"
".quad 0x356625202c313566,0x2e627573090a3b31,0x3566250920323366,0x2c33356625202c34\n"
".quad 0x090a3b3534662520,0x203233662e627573,0x25202c3535662509,0x31356625202c3266\n"
".quad 0x662e627573090a3b,0x3635662509203233,0x202c38346625202c,0x73090a3b32356625\n"
".quad 0x09203233662e6275,0x6625202c37356625,0x32356625202c3035,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x356625202c383566,0x2c35356625202c31,0x090a3b3435662520\n"
".quad 0x203233662e627573,0x25202c3935662509,0x356625202c353466,0x2e616d66090a3b37\n"
".quad 0x09203233662e6e72,0x6625202c30366625,0x35356625202c3135,0x0a3b38356625202c\n"
".quad 0x3233662e64646109,0x202c313666250920,0x6625202c36356625,0x616d66090a3b3935\n"
".quad 0x203233662e6e722e,0x25202c3236662509,0x356625202c353566,0x3b30366625202c35\n"
".quad 0x33662e646461090a,0x2c33366625092032,0x25202c3136662520,0x6d66090a3b323666\n"
".quad 0x3233662e6e722e61,0x202c343666250920,0x346625202c346625,0x0a3b33366625202c\n"
".quad 0x3233662e64646109,0x202c353666250920,0x6625202c30356625,0x766f6d090a3b3436\n"
".quad 0x662509203233662e,0x35366625202c3636,0x662e627573090a3b,0x3736662509203233\n"
".quad 0x202c35366625202c,0x73090a3b30356625,0x09203233662e6275,0x6625202c38366625\n"
".quad 0x37366625202c3436,0x662e766f6d090a3b,0x3936662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3037662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x617262090a30202f,0x4c240920696e752e\n"
".quad 0x363835335f305f74,0x5f305f744c240a3b,0x2e090a3a32343833,0x3209363109636f6c\n"
".quad 0x6f6d090a30093536,0x2509203233662e76,0x326625202c333166,0x09636f6c2e090a3b\n"
".quad 0x3009363632093631,0x33662e766f6d090a,0x2c30376625092032,0x2e090a3b34662520\n"
".quad 0x3209363109636f6c,0x6f6d090a30093736,0x2509203233662e76,0x366625202c343166\n"
".quad 0x09636f6c2e090a3b,0x3009383632093631,0x33662e766f6d090a,0x2c39366625092032\n"
".quad 0x2e090a3b38662520,0x3209363109636f6c,0x6f6d090a30093637,0x2509203233662e76\n"
".quad 0x306630202c383666,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3636662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x30202c3334662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x30306630202c3134,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c38316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6630202c37316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366\n"
".quad 0x3030306630202c36,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c353166250920,0x3030303030306630,0x09202020203b3030,0x744c240a30202f2f\n"
".quad 0x3a363835335f305f,0x3109636f6c2e090a,0x0a30093038320936,0x3233732e62757309\n"
".quad 0x25202c3672250920,0x090a3b31202c3272,0x203233752e766f6d,0x3b31202c37722509\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x2c327225202c3270,0x40090a3b37722520\n"
".quad 0x2061726220327025,0x345f305f744c2409,0x6461090a3b383930,0x2509203233662e64\n"
".quad 0x366625202c313766,0x3b31346625202c36,0x33662e627573090a,0x2c32376625092032\n"
".quad 0x25202c3137662520,0x7573090a3b363666,0x2509203233662e62,0x376625202c333766\n"
".quad 0x3b32376625202c31,0x33662e627573090a,0x2c34376625092032,0x25202c3134662520\n"
".quad 0x7573090a3b323766,0x2509203233662e62,0x366625202c353766,0x3b33376625202c36\n"
".quad 0x33662e646461090a,0x2c36376625092032,0x25202c3437662520,0x6461090a3b353766\n"
".quad 0x2509203233662e64,0x376625202c373766,0x3b38366625202c36,0x33662e646461090a\n"
".quad 0x2c38376625092032,0x25202c3737662520,0x6461090a3b333466,0x2509203233662e64\n"
".quad 0x376625202c393766,0x3b38376625202c31,0x33662e627573090a,0x2c30386625092032\n"
".quad 0x25202c3937662520,0x7573090a3b313766,0x2509203233662e62,0x376625202c313866\n"
".quad 0x3b30386625202c38,0x33662e646461090a,0x2c32386625092032,0x25202c3937662520\n"
".quad 0x6f6d090a3b313866,0x2509203233662e76,0x346630202c333866,0x3b30303030303830\n"
".quad 0x202f2f0920202020,0x2e70746573090a34,0x09203233662e746c,0x386625202c337025\n"
".quad 0x3b33386625202c32,0x203370252140090a,0x744c240920617262,0x3b383930345f305f\n"
".quad 0x33662e766f6d090a,0x2c34386625092032,0x3030303634663020,0x202020203b303034\n"
".quad 0x33393138202f2f09,0x33662e6c756d090a,0x2c35386625092032,0x25202c3731662520\n"
".quad 0x6f6d090a3b343866,0x2509203233662e76,0x346630202c363866,0x3b30303430303036\n"
".quad 0x202f2f0920202020,0x756d090a33393138,0x2509203233662e6c,0x316625202c373866\n"
".quad 0x3b36386625202c35,0x33662e627573090a,0x2c38386625092032,0x25202c3538662520\n"
".quad 0x7573090a3b373166,0x2509203233662e62,0x386625202c393866,0x3b35316625202c37\n"
".quad 0x33662e627573090a,0x2c30396625092032,0x25202c3538662520,0x7573090a3b383866\n"
".quad 0x2509203233662e62,0x386625202c313966,0x3b39386625202c37,0x33662e627573090a\n"
".quad 0x2c32396625092032,0x25202c3731662520,0x7573090a3b303966,0x2509203233662e62\n"
".quad 0x316625202c333966,0x3b31396625202c35,0x35325f305f4c240a,0x3c2f2f200a3a3236\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x31383220656e696c,0x3109636f6c2e090a\n"
".quad 0x0a30093138320936,0x3233662e6c756d09,0x202c343966250920,0x6625202c38316625\n"
".quad 0x6c756d090a3b3531,0x662509203233662e,0x37316625202c3539,0x0a3b35316625202c\n"
".quad 0x2e6e722e616d6609,0x3966250920323366,0x2c37316625202c36,0x25202c3631662520\n"
".quad 0x6461090a3b343966,0x2509203233662e64,0x396625202c373966,0x3b36396625202c35\n"
".quad 0x33662e627573090a,0x2c38396625092032,0x25202c3739662520,0x756d090a3b353966\n"
".quad 0x2509203233662e6c,0x396625202c393966,0x3b31396625202c30,0x33662e627573090a\n"
".quad 0x3030316625092032,0x202c39396625202c,0x73090a3b35396625,0x09203233662e6275\n"
".quad 0x25202c3130316625,0x396625202c363966,0x2e627573090a3b38,0x3166250920323366\n"
".quad 0x37396625202c3230,0x0a3b38396625202c,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x30396625202c3330,0x202c33396625202c,0x090a3b3030316625,0x203233662e627573\n"
".quad 0x202c343031662509,0x6625202c35396625,0x6d66090a3b323031,0x3233662e6e722e61\n"
".quad 0x2c35303166250920,0x25202c3139662520,0x316625202c323966,0x646461090a3b3330\n"
".quad 0x662509203233662e,0x316625202c363031,0x30316625202c3130,0x2e616d66090a3b34\n"
".quad 0x09203233662e6e72,0x25202c3730316625,0x396625202c323966,0x3530316625202c33\n"
".quad 0x662e646461090a3b,0x3031662509203233,0x3630316625202c38,0x3b3730316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c393031,0x2c36316625202c38\n"
".quad 0x0a3b383031662520,0x3233662e64646109,0x2c30313166250920,0x25202c3739662520\n"
".quad 0x73090a3b39303166,0x09203233662e6275,0x25202c3131316625,0x6625202c30313166\n"
".quad 0x627573090a3b3739,0x662509203233662e,0x316625202c323131,0x31316625202c3930\n"
".quad 0x636f6c2e090a3b31,0x0932383209363109,0x662e646461090a30,0x3131662509203233\n"
".quad 0x3031316625202c33,0x3b3031316625202c,0x33662e627573090a,0x3431316625092032\n"
".quad 0x2c3331316625202c,0x0a3b303131662520,0x3233662e62757309,0x2c35313166250920\n"
".quad 0x202c303131662520,0x090a3b3431316625,0x203233662e627573,0x202c363131662509\n"
".quad 0x25202c3331316625,0x73090a3b34313166,0x09203233662e6275,0x25202c3731316625\n"
".quad 0x6625202c30313166,0x6461090a3b363131,0x2509203233662e64,0x6625202c38313166\n"
".quad 0x316625202c353131,0x646461090a3b3731,0x662509203233662e,0x316625202c393131\n"
".quad 0x31316625202c3831,0x2e646461090a3b32,0x3166250920323366,0x31316625202c3032\n"
".quad 0x3231316625202c39,0x662e646461090a3b,0x3231662509203233,0x3331316625202c31\n"
".quad 0x3b3032316625202c,0x33662e627573090a,0x3232316625092032,0x2c3132316625202c\n"
".quad 0x0a3b333131662520,0x3233662e62757309,0x2c33323166250920,0x202c303231662520\n"
".quad 0x090a3b3232316625,0x09363109636f6c2e,0x61090a3009333832,0x09203233662e6464\n"
".quad 0x25202c3432316625,0x6625202c31323166,0x627573090a3b3431,0x662509203233662e\n"
".quad 0x316625202c353231,0x32316625202c3432,0x2e627573090a3b31,0x3166250920323366\n"
".quad 0x32316625202c3632,0x3532316625202c34,0x662e627573090a3b,0x3231662509203233\n"
".quad 0x2c34316625202c37,0x0a3b353231662520,0x3233662e62757309,0x2c38323166250920\n"
".quad 0x202c313231662520,0x090a3b3632316625,0x203233662e646461,0x202c393231662509\n"
".quad 0x25202c3732316625,0x61090a3b38323166,0x09203233662e6464,0x25202c3033316625\n"
".quad 0x6625202c39323166,0x6461090a3b333231,0x2509203233662e64,0x6625202c31333166\n"
".quad 0x366625202c303331,0x2e646461090a3b39,0x3166250920323366,0x32316625202c3233\n"
".quad 0x3133316625202c34,0x662e766f6d090a3b,0x3531662509203233,0x3b3233316625202c\n"
".quad 0x33662e627573090a,0x3333316625092032,0x2c3233316625202c,0x0a3b343231662520\n"
".quad 0x3233662e62757309,0x202c363166250920,0x25202c3133316625,0x2e090a3b33333166\n"
".quad 0x3209363109636f6c,0x7573090a30093638,0x2509203233662e62,0x6625202c34333166\n"
".quad 0x31346625202c3636,0x662e627573090a3b,0x3331662509203233,0x3433316625202c35\n"
".quad 0x0a3b36366625202c,0x3233662e62757309,0x2c36333166250920,0x202c343331662520\n"
".quad 0x090a3b3533316625,0x203233662e646461,0x202c373331662509,0x25202c3533316625\n"
".quad 0x7573090a3b313466,0x2509203233662e62,0x6625202c38333166,0x33316625202c3636\n"
".quad 0x2e627573090a3b36,0x3166250920323366,0x33316625202c3933,0x3733316625202c38\n"
".quad 0x662e646461090a3b,0x3431662509203233,0x3933316625202c30,0x0a3b38366625202c\n"
".quad 0x3233662e62757309,0x2c31343166250920,0x202c303431662520,0x61090a3b33346625\n"
".quad 0x09203233662e6464,0x25202c3234316625,0x6625202c34333166,0x6461090a3b313431\n"
".quad 0x2509203233662e64,0x6625202c33343166,0x316625202c323431,0x2e627573090a3b33\n"
".quad 0x3166250920323366,0x34316625202c3434,0x3234316625202c33,0x662e627573090a3b\n"
".quad 0x3431662509203233,0x3334316625202c35,0x3b3434316625202c,0x33662e627573090a\n"
".quad 0x3634316625092032,0x2c3234316625202c,0x0a3b353431662520,0x3233662e62757309\n"
".quad 0x2c37343166250920,0x25202c3331662520,0x61090a3b34343166,0x09203233662e6464\n"
".quad 0x25202c3834316625,0x6625202c36343166,0x7573090a3b373431,0x2509203233662e62\n"
".quad 0x6625202c39343166,0x316625202c323431,0x627573090a3b3433,0x662509203233662e\n"
".quad 0x316625202c303531,0x34316625202c3134,0x2e646461090a3b39,0x3166250920323366\n"
".quad 0x34316625202c3135,0x3035316625202c38,0x662e646461090a3b,0x3531662509203233\n"
".quad 0x2c30376625202c32,0x0a3b313531662520,0x3233662e64646109,0x2c33353166250920\n"
".quad 0x202c333431662520,0x090a3b3235316625,0x203233662e766f6d,0x25202c3731662509\n"
".quad 0x73090a3b33353166,0x09203233662e6275,0x25202c3435316625,0x6625202c33353166\n"
".quad 0x7573090a3b333431,0x2509203233662e62,0x316625202c383166,0x35316625202c3235\n"
".quad 0x636f6c2e090a3b34,0x0938383209363109,0x662e766f6d090a30,0x3531662509203233\n"
".quad 0x3036346630202c35,0x20203b3030343030,0x393138202f2f0920,0x662e6c756d090a33\n"
".quad 0x3531662509203233,0x3233316625202c36,0x3b3535316625202c,0x33662e6c756d090a\n"
".quad 0x3735316625092032,0x2c3233316625202c,0x090a3b3631662520,0x203233662e6c756d\n"
".quad 0x202c383531662509,0x25202c3233316625,0x73090a3b32333166,0x09203233662e6275\n"
".quad 0x25202c3935316625,0x6625202c36353166,0x6d66090a3b323331,0x3233662e6e722e61\n"
".quad 0x2c30363166250920,0x202c323331662520,0x6625202c36316625,0x7573090a3b373531\n"
".quad 0x2509203233662e62,0x316625202c313966,0x35316625202c3635,0x2e646461090a3b39\n"
".quad 0x3166250920323366,0x35316625202c3136,0x3036316625202c38,0x662e627573090a3b\n"
".quad 0x3339662509203233,0x2c3233316625202c,0x090a3b3139662520,0x203233662e6c756d\n"
".quad 0x202c323631662509,0x6625202c31396625,0x627573090a3b3139,0x662509203233662e\n"
".quad 0x316625202c333631,0x35316625202c3236,0x2e627573090a3b38,0x3166250920323366\n"
".quad 0x36316625202c3436,0x3835316625202c31,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c35363166,0x33396625202c3139,0x3b3336316625202c,0x33662e627573090a\n"
".quad 0x3636316625092032,0x2c3036316625202c,0x0a3b343631662520,0x3233662e62757309\n"
".quad 0x2c37363166250920,0x202c313631662520,0x090a3b3436316625,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x2c31396625202c38,0x25202c3339662520,0x73090a3b35363166\n"
".quad 0x09203233662e6275,0x25202c3936316625,0x6625202c38353166,0x6d66090a3b373631\n"
".quad 0x3233662e6e722e61,0x2c30373166250920,0x25202c3339662520,0x316625202c333966\n"
".quad 0x646461090a3b3836,0x662509203233662e,0x316625202c313731,0x36316625202c3636\n"
".quad 0x2e646461090a3b39,0x3166250920323366,0x37316625202c3237,0x3137316625202c30\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c33373166,0x36316625202c3631\n"
".quad 0x3b3237316625202c,0x33662e646461090a,0x3437316625092032,0x2c3136316625202c\n"
".quad 0x0a3b333731662520,0x3233662e766f6d09,0x202c313466250920,0x090a3b3437316625\n"
".quad 0x203233662e627573,0x202c353731662509,0x25202c3437316625,0x73090a3b31363166\n"
".quad 0x09203233662e6275,0x6625202c33346625,0x316625202c333731,0x6f6c2e090a3b3537\n"
".quad 0x3938320936310963,0x2e766f6d090a3009,0x3166250920323366,0x36346630202c3637\n"
".quad 0x203b303034303030,0x3138202f2f092020,0x2e6c756d090a3339,0x3166250920323366\n"
".quad 0x35316625202c3737,0x3637316625202c33,0x662e6c756d090a3b,0x3731662509203233\n"
".quad 0x3335316625202c38,0x0a3b38316625202c,0x3233662e6c756d09,0x2c39373166250920\n"
".quad 0x202c333531662520,0x090a3b3335316625,0x203233662e627573,0x202c303831662509\n"
".quad 0x25202c3737316625,0x66090a3b33353166,0x33662e6e722e616d,0x3138316625092032\n"
".quad 0x2c3335316625202c,0x25202c3831662520,0x73090a3b38373166,0x09203233662e6275\n"
".quad 0x6625202c30396625,0x316625202c373731,0x646461090a3b3038,0x662509203233662e\n"
".quad 0x316625202c323831,0x38316625202c3937,0x2e627573090a3b31,0x3966250920323366\n"
".quad 0x3335316625202c32,0x0a3b30396625202c,0x3233662e6c756d09,0x2c33383166250920\n"
".quad 0x25202c3039662520,0x7573090a3b303966,0x2509203233662e62,0x6625202c34383166\n"
".quad 0x316625202c333831,0x627573090a3b3937,0x662509203233662e,0x316625202c353831\n"
".quad 0x37316625202c3238,0x2e616d66090a3b39,0x09203233662e6e72,0x25202c3638316625\n"
".quad 0x396625202c303966,0x3438316625202c32,0x662e627573090a3b,0x3831662509203233\n"
".quad 0x3138316625202c37,0x3b3538316625202c,0x33662e627573090a,0x3838316625092032\n"
".quad 0x2c3238316625202c,0x0a3b353831662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x30396625202c3938,0x202c32396625202c,0x090a3b3638316625,0x203233662e627573\n"
".quad 0x202c303931662509,0x25202c3937316625,0x66090a3b38383166,0x33662e6e722e616d\n"
".quad 0x3139316625092032,0x202c32396625202c,0x6625202c32396625,0x6461090a3b393831\n"
".quad 0x2509203233662e64,0x6625202c32393166,0x316625202c373831,0x646461090a3b3039\n"
".quad 0x662509203233662e,0x316625202c333931,0x39316625202c3139,0x2e616d66090a3b32\n"
".quad 0x09203233662e6e72,0x25202c3439316625,0x316625202c383166,0x3339316625202c38\n"
".quad 0x662e646461090a3b,0x3931662509203233,0x3238316625202c35,0x3b3439316625202c\n"
".quad 0x33662e766f6d090a,0x2c36366625092032,0x0a3b353931662520,0x3233662e62757309\n"
".quad 0x2c36393166250920,0x202c353931662520,0x090a3b3238316625,0x203233662e627573\n"
".quad 0x25202c3836662509,0x6625202c34393166,0x6c2e090a3b363931,0x393209363109636f\n"
".quad 0x646461090a300930,0x662509203233662e,0x316625202c373931,0x39316625202c3437\n"
".quad 0x2e627573090a3b35,0x3166250920323366,0x39316625202c3839,0x3539316625202c37\n"
".quad 0x662e627573090a3b,0x3931662509203233,0x3437316625202c39,0x3b3839316625202c\n"
".quad 0x33662e627573090a,0x3030326625092032,0x2c3739316625202c,0x0a3b383931662520\n"
".quad 0x3233662e62757309,0x2c31303266250920,0x202c353931662520,0x090a3b3030326625\n"
".quad 0x203233662e646461,0x202c323032662509,0x25202c3939316625,0x61090a3b31303266\n"
".quad 0x09203233662e6464,0x25202c3330326625,0x326625202c383666,0x646461090a3b3230\n"
".quad 0x662509203233662e,0x346625202c343032,0x3330326625202c33,0x662e646461090a3b\n"
".quad 0x3032662509203233,0x3739316625202c35,0x3b3430326625202c,0x33662e627573090a\n"
".quad 0x3630326625092032,0x2c3530326625202c,0x0a3b373931662520,0x3233662e62757309\n"
".quad 0x2c37303266250920,0x202c343032662520,0x090a3b3630326625,0x09363109636f6c2e\n"
".quad 0x73090a3009303832,0x09203233732e6275,0x367225202c367225,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x090a3b30202c3872,0x2e71652e70746573,0x3470250920323373\n"
".quad 0x25202c367225202c,0x702540090a3b3872,0x2409206172622034,0x3930345f305f744c\n"
".quad 0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31383220656e69,0x616c206461656820,0x4c242064656c6562,0x0a323635325f305f\n"
".quad 0x3233662e64646109,0x2c38303266250920,0x202c373032662520,0x090a3b3530326625\n"
".quad 0x203233662e766f6d,0x202c393032662509,0x3030303830346630,0x2f092020203b3030\n"
".quad 0x746573090a34202f,0x3233662e746c2e70,0x25202c3570250920,0x6625202c38303266\n"
".quad 0x2540090a3b393032,0x0920617262203570,0x3635325f305f4c24,0x305f744c240a3b32\n"
".quad 0x240a3a383930345f,0x383138325f305f4c,0x09636f6c2e090a3a,0x3009323932093631\n"
".quad 0x33732e766f6d090a,0x202c397225092032,0x7473090a3b367225,0x732e6d617261702e\n"
".quad 0x635f5f5b09203233,0x5f66746572616475,0x636c614336315a5f,0x72626c65646e614d\n"
".quad 0x666666665344746f,0x25202c5d62696666,0x746572090a3b3972,0x6e6557444c240a3b\n"
".quad 0x614336315a5f5f64,0x6c65646e614d636c,0x66665344746f7262,0x0a3a626966666666\n"
".quad 0x5a5f202f2f207d09,0x614d636c61433631,0x746f72626c65646e,0x6666666666665344\n"
".quad 0x69762e090a0a6269,0x662e20656c626973,0x34315a5f20636e75,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x5f544b5069507645,0x31535f31535f3153,0x702e28206962695f\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x5f5f31666d726170,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x5069507645664974,0x31535f31535f544b,0x2c6962695f31535f\n"
".quad 0x206d617261702e20,0x635f5f203436752e,0x666d726170616475,0x614334315a5f5f32\n"
".quad 0x6c65646e614d636c,0x76456649746f7262,0x31535f544b506950,0x695f31535f31535f\n"
".quad 0x7261702e202c6962,0x203233662e206d61,0x6170616475635f5f,0x315a5f5f33666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x544b506950764566,0x535f31535f31535f\n"
".quad 0x2e202c6962695f31,0x662e206d61726170,0x6475635f5f203233,0x5f34666d72617061\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x695076456649746f,0x535f31535f544b50\n"
".quad 0x6962695f31535f31,0x6d617261702e202c,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3566,0x65646e614d636c61,0x456649746f72626c,0x535f544b50695076\n"
".quad 0x5f31535f31535f31,0x61702e202c696269,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f36666d7261,0x614d636c61433431,0x746f72626c65646e,0x4b50695076456649\n"
".quad 0x5f31535f31535f54,0x202c6962695f3153,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x37666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5076456649746f72\n"
".quad 0x5f31535f544b5069,0x62695f31535f3153,0x617261702e202c69,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x34315a5f5f38666d,0x646e614d636c6143,0x6649746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x7b090a296962695f,0x2e206765722e090a\n"
".quad 0x313c722520323375,0x65722e090a3b3e35,0x25203436752e2067,0x0a3b3e30313c6472\n"
".quad 0x662e206765722e09,0x31323c6625203233,0x6765722e090a3b3e,0x2520646572702e20\n"
".quad 0x2e090a3b3e383c70,0x3109363109636f6c,0x444c240a30093633,0x5f5f6e6967656257\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x5069507645664974,0x31535f31535f544b\n"
".quad 0x3a6962695f31535f,0x7261702e646c090a,0x09203436752e6d61,0x5f5b202c31647225\n"
".quad 0x726170616475635f,0x34315a5f5f31666d,0x646e614d636c6143,0x6649746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x090a3b5d6962695f,0x203436732e766f6d\n"
".quad 0x25202c3264722509,0x646c090a3b316472,0x752e6d617261702e,0x3364722509203436\n"
".quad 0x6475635f5f5b202c,0x5f32666d72617061,0x636c614334315a5f,0x72626c65646e614d\n"
".quad 0x695076456649746f,0x535f31535f544b50,0x6962695f31535f31,0x2e766f6d090a3b5d\n"
".quad 0x6472250920343673,0x3b33647225202c34,0x7261702e646c090a,0x09203233662e6d61\n"
".quad 0x5f5f5b202c316625,0x6d72617061647563,0x4334315a5f5f3366,0x65646e614d636c61\n"
".quad 0x456649746f72626c,0x535f544b50695076,0x5f31535f31535f31,0x6d090a3b5d696269\n"
".quad 0x09203233662e766f,0x316625202c326625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c33662509,0x726170616475635f,0x34315a5f5f34666d,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x5f544b5069507645,0x31535f31535f3153,0x090a3b5d6962695f\n"
".quad 0x203233662e766f6d,0x6625202c34662509,0x702e646c090a3b33,0x3233662e6d617261\n"
".quad 0x5b202c3566250920,0x6170616475635f5f,0x315a5f5f35666d72,0x6e614d636c614334\n"
".quad 0x49746f72626c6564,0x544b506950764566,0x535f31535f31535f,0x0a3b5d6962695f31\n"
".quad 0x3233662e766f6d09,0x25202c3666250920,0x2e646c090a3b3566,0x33752e6d61726170\n"
".quad 0x202c317225092032,0x70616475635f5f5b,0x5a5f5f36666d7261,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x4b50695076456649,0x5f31535f31535f54,0x3b5d6962695f3153\n"
".quad 0x33732e766f6d090a,0x202c327225092032,0x646c090a3b317225,0x752e6d617261702e\n"
".quad 0x2c33722509203233,0x616475635f5f5b20,0x5f5f37666d726170,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x5069507645664974,0x31535f31535f544b,0x5d6962695f31535f\n"
".quad 0x732e747663090a3b,0x2509203233732e38,0x3b337225202c3472,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c357225,0x6d72617061647563,0x4334315a5f5f3866\n"
".quad 0x65646e614d636c61,0x456649746f72626c,0x535f544b50695076,0x5f31535f31535f31\n"
".quad 0x6d090a3b5d696269,0x09203233732e766f,0x357225202c367225,0x09636f6c2e090a3b\n"
".quad 0x3009383331093631,0x33732e766f6d090a,0x202c377225092032,0x6f6d090a3b327225\n"
".quad 0x2509203233732e76,0x090a3b30202c3872,0x2e656e2e70746573,0x3170250920323373\n"
".quad 0x25202c347225202c,0x2e646c090a3b3872,0x3766250920323366,0x2b346472255b202c\n"
".quad 0x252140090a3b5d30,0x0920617262203170,0x33355f315f744c24,0x6f6c2e090a3b3837\n"
".quad 0x3434310936310963,0x2e766f6d090a3009,0x3866250920323366,0x090a3b346625202c\n"
".quad 0x09363109636f6c2e,0x6d090a3009353431,0x09203233662e766f,0x366625202c396625\n"
".quad 0x09636f6c2e090a3b,0x3009363431093631,0x33662e766f6d090a,0x2c30316625092032\n"
".quad 0x2e090a3b32662520,0x3109363109636f6c,0x6f6d090a30093734,0x2509203233662e76\n"
".quad 0x376625202c313166,0x09636f6c2e090a3b,0x3009383431093631,0x33662e6c756d090a\n"
".quad 0x2c32316625092032,0x6625202c32662520,0x636f6c2e090a3b32,0x0939343109363109\n"
".quad 0x662e6c756d090a30,0x3331662509203233,0x25202c376625202c,0x617262090a3b3766\n"
".quad 0x4c240920696e752e,0x323231355f315f74,0x5f315f744c240a3b,0x2e090a3a38373335\n"
".quad 0x3109363109636f6c,0x6f6d090a30093335,0x2509203233662e76,0x3b376625202c3866\n"
".quad 0x3109636f6c2e090a,0x0a30093435310936,0x3233662e766f6d09,0x25202c3966250920\n"
".quad 0x6f6c2e090a3b3266,0x3835310936310963,0x2e766f6d090a3009,0x3166250920323366\n"
".quad 0x3030306630202c33,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c323166250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x306630202c313166,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3031662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x240a30202f2f0920,0x3231355f315f744c,0x2e766f6d090a3a32,0x3972250920323375\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x202c327025092032,0x397225202c367225\n"
".quad 0x2032702540090a3b,0x424c240920617262,0x34315a5f5f363142,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x5f544b5069507645,0x31535f31535f3153,0x6d090a3b6962695f\n"
".quad 0x09203233732e766f,0x3b30202c30317225,0x365f315f744c240a,0x2f2f200a3a363431\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x353120656e696c20,0x697473656e202c38\n"
".quad 0x687470656420676e,0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574\n"
".quad 0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0932363109363109,0x732e627573090a30\n"
".quad 0x2c37722509203233,0x3b31202c37722520,0x33752e766f6d090a,0x2c31317225092032\n"
".quad 0x746573090a3b3020,0x3233732e656c2e70,0x25202c3370250920,0x31317225202c3772\n"
".quad 0x2033702540090a3b,0x5f4c240920617262,0x0a3b363638345f31,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c38353120\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x61090a363431365f,0x09203233662e6464\n"
".quad 0x6625202c34316625,0x32316625202c3331,0x662e766f6d090a3b,0x3531662509203233\n"
".quad 0x303830346630202c,0x2020203b30303030,0x090a34202f2f0920,0x2e74672e70746573\n"
".quad 0x3470250920323366,0x202c34316625202c,0x40090a3b35316625,0x6172622034702521\n"
".quad 0x345f315f4c240920,0x5f4c240a3b303136,0x0a3a363638345f31,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c38353120\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x2e090a363431365f,0x3109363109636f6c\n"
".quad 0x756d090a30093336,0x3233752e6f6c2e6c,0x202c323172250920,0x3b34202c30317225\n"
".quad 0x36752e747663090a,0x2509203233752e34,0x317225202c356472,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x2c35647225202c36,0x090a3b3264722520,0x09203233732e7473\n"
".quad 0x5d302b366472255b,0x090a3b377225202c,0x09363109636f6c2e,0x61090a3009353631\n"
".quad 0x09203233732e6464,0x7225202c30317225,0x090a3b31202c3031,0x2e656e2e70746573\n"
".quad 0x3570250920323373,0x25202c367225202c,0x2540090a3b303172,0x0920617262203570\n"
".quad 0x34365f315f744c24,0x617262090a3b3230,0x4c240920696e752e,0x315a5f5f36314242\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x544b506950764566,0x535f31535f31535f\n"
".quad 0x240a3b6962695f31,0x3034365f315f744c,0x6c3c2f2f200a3a32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363431365f315f74,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x30317225202c3331,0x7663090a3b34202c,0x33752e3436752e74,0x2c37647225092032\n"
".quad 0x090a3b3331722520,0x203436752e646461,0x25202c3864722509,0x647225202c376472\n"
".quad 0x662e646c090a3b34,0x3631662509203233,0x2b386472255b202c,0x252140090a3b5d30\n"
".quad 0x0920617262203170,0x31375f315f744c24,0x3c2f2f200a3b3037,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x38353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3431365f315f744c,0x09636f6c2e090a36,0x3009373631093631\n"
".quad 0x33662e766f6d090a,0x202c386625092032,0x6c2e090a3b346625,0x363109363109636f\n"
".quad 0x766f6d090a300938,0x662509203233662e,0x0a3b366625202c39,0x363109636f6c2e09\n"
".quad 0x090a300939363109,0x203233662e766f6d,0x25202c3031662509,0x6f6c2e090a3b3266\n"
".quad 0x3037310936310963,0x2e766f6d090a3009,0x3166250920323366,0x3b36316625202c31\n"
".quad 0x3109636f6c2e090a,0x0a30093137310936,0x3233662e6c756d09,0x202c323166250920\n"
".quad 0x326625202c326625,0x09636f6c2e090a3b,0x3009323731093631,0x33662e6c756d090a\n"
".quad 0x2c33316625092032,0x25202c3631662520,0x7262090a3b363166,0x240920696e752e61\n"
".quad 0x3139365f315f744c,0x315f744c240a3b34,0x200a3a303731375f,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383531\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x6c2e090a36343136,0x373109363109636f\n"
".quad 0x766f6d090a300935,0x662509203233662e,0x3b36316625202c38,0x3109636f6c2e090a\n"
".quad 0x0a30093637310936,0x3233662e766f6d09,0x25202c3966250920,0x6f6c2e090a3b3266\n"
".quad 0x3038310936310963,0x2e766f6d090a3009,0x3166250920323366,0x3030306630202c33\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c323166250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x306630202c313166,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3031662509203233,0x303030306630202c,0x2020203b30303030,0x240a30202f2f0920\n"
".quad 0x3139365f315f744c,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363431365f315f74,0x3109636f6c2e090a,0x0a30093338310936,0x3233732e766f6d09\n"
".quad 0x25202c3772250920,0x315f4c240a3b3272,0x200a3a303136345f,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383531\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x6c2e090a36343136,0x383109363109636f\n"
".quad 0x6c756d090a300935,0x662509203233662e,0x31316625202c3731,0x0a3b30316625202c\n"
".quad 0x3233662e64646109,0x202c383166250920,0x6625202c37316625,0x646461090a3b3731\n"
".quad 0x662509203233662e,0x2c396625202c3031,0x090a3b3831662520,0x09363109636f6c2e\n"
".quad 0x73090a3009363831,0x09203233662e6275,0x6625202c39316625,0x32316625202c3331\n"
".quad 0x662e646461090a3b,0x3131662509203233,0x25202c386625202c,0x6c2e090a3b393166\n"
".quad 0x383109363109636f,0x6c756d090a300937,0x662509203233662e,0x30316625202c3231\n"
".quad 0x0a3b30316625202c,0x363109636f6c2e09,0x090a300938383109,0x203233662e6c756d\n"
".quad 0x25202c3331662509,0x316625202c313166,0x70746573090a3b31,0x203233732e656e2e\n"
".quad 0x7225202c36702509,0x3b30317225202c36,0x622036702540090a,0x5f744c2409206172\n"
".quad 0x0a3b363431365f31,0x5f5f363142424c24,0x4d636c614334315a,0x6f72626c65646e61\n"
".quad 0x5069507645664974,0x31535f31535f544b,0x3a6962695f31535f,0x3109636f6c2e090a\n"
".quad 0x0a30093039310936,0x4c240a3b74657209,0x5a5f5f646e655744,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x4b50695076456649,0x5f31535f31535f54,0x0a3a6962695f3153\n"
".quad 0x5a5f202f2f207d09,0x614d636c61433431,0x746f72626c65646e,0x4b50695076456649\n"
".quad 0x5f31535f31535f54,0x0a0a6962695f3153,0x6c62697369762e09,0x20636e75662e2065\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x695076456449746f,0x535f31535f544b50\n"
".quad 0x6962695f31535f31,0x6d617261702e2820,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3166,0x65646e614d636c61,0x456449746f72626c,0x535f544b50695076\n"
".quad 0x5f31535f31535f31,0x61702e202c696269,0x3436752e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f32666d7261,0x614d636c61433431,0x746f72626c65646e,0x4b50695076456449\n"
".quad 0x5f31535f31535f54,0x202c6962695f3153,0x2e206d617261702e,0x75635f5f20343666\n"
".quad 0x33666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5076456449746f72\n"
".quad 0x5f31535f544b5069,0x62695f31535f3153,0x617261702e202c69,0x5f203436662e206d\n"
".quad 0x726170616475635f,0x34315a5f5f34666d,0x646e614d636c6143,0x6449746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x702e202c6962695f,0x36662e206d617261\n"
".quad 0x616475635f5f2034,0x5f5f35666d726170,0x4d636c614334315a,0x6f72626c65646e61\n"
".quad 0x5069507645644974,0x31535f31535f544b,0x2c6962695f31535f,0x206d617261702e20\n"
".quad 0x635f5f203233732e,0x666d726170616475,0x614334315a5f5f36,0x6c65646e614d636c\n"
".quad 0x76456449746f7262,0x31535f544b506950,0x695f31535f31535f,0x7261702e202c6962\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x315a5f5f37666d72,0x6e614d636c614334\n"
".quad 0x49746f72626c6564,0x544b506950764564,0x535f31535f31535f,0x2e202c6962695f31\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5f38666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x695076456449746f,0x535f31535f544b50,0x6962695f31535f31\n"
".quad 0x722e090a7b090a29,0x203233752e206765,0x0a3b3e35313c7225,0x752e206765722e09\n"
".quad 0x313c647225203436,0x65722e090a3b3e30,0x25203436662e2067,0x0a3b3e31323c6466\n"
".quad 0x702e206765722e09,0x383c702520646572,0x636f6c2e090a3b3e,0x0936333109363109\n"
".quad 0x656257444c240a30,0x34315a5f5f6e6967,0x646e614d636c6143,0x6449746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x6c090a3a6962695f,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x75635f5f5b202c31,0x31666d7261706164,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5076456449746f72,0x5f31535f544b5069,0x62695f31535f3153\n"
".quad 0x766f6d090a3b5d69,0x722509203436732e,0x31647225202c3264,0x61702e646c090a3b\n"
".quad 0x203436752e6d6172,0x5b202c3364722509,0x6170616475635f5f,0x315a5f5f32666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x544b506950764564,0x535f31535f31535f\n"
".quad 0x0a3b5d6962695f31,0x3436732e766f6d09,0x202c346472250920,0x6c090a3b33647225\n"
".quad 0x2e6d617261702e64,0x6466250920343666,0x75635f5f5b202c31,0x33666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5076456449746f72,0x5f31535f544b5069\n"
".quad 0x62695f31535f3153,0x766f6d090a3b5d69,0x662509203436662e,0x31646625202c3264\n"
".quad 0x61702e646c090a3b,0x203436662e6d6172,0x5b202c3364662509,0x6170616475635f5f\n"
".quad 0x315a5f5f34666d72,0x6e614d636c614334,0x49746f72626c6564,0x544b506950764564\n"
".quad 0x535f31535f31535f,0x0a3b5d6962695f31,0x3436662e766f6d09,0x202c346466250920\n"
".quad 0x6c090a3b33646625,0x2e6d617261702e64,0x6466250920343666,0x75635f5f5b202c35\n"
".quad 0x35666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5076456449746f72\n"
".quad 0x5f31535f544b5069,0x62695f31535f3153,0x766f6d090a3b5d69,0x662509203436662e\n"
".quad 0x35646625202c3664,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c31722509\n"
".quad 0x726170616475635f,0x34315a5f5f36666d,0x646e614d636c6143,0x6449746f72626c65\n"
".quad 0x5f544b5069507645,0x31535f31535f3153,0x090a3b5d6962695f,0x203233732e766f6d\n"
".quad 0x7225202c32722509,0x702e646c090a3b31,0x3233752e6d617261,0x5b202c3372250920\n"
".quad 0x6170616475635f5f,0x315a5f5f37666d72,0x6e614d636c614334,0x49746f72626c6564\n"
".quad 0x544b506950764564,0x535f31535f31535f,0x0a3b5d6962695f31,0x2e38732e74766309\n"
".quad 0x3472250920323373,0x090a3b337225202c,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x75635f5f5b202c35,0x38666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63\n"
".quad 0x5076456449746f72,0x5f31535f544b5069,0x62695f31535f3153,0x766f6d090a3b5d69\n"
".quad 0x722509203233732e,0x0a3b357225202c36,0x363109636f6c2e09,0x090a300938333109\n"
".quad 0x203233732e766f6d,0x7225202c37722509,0x2e766f6d090a3b32,0x3872250920323373\n"
".quad 0x6573090a3b30202c,0x33732e656e2e7074,0x202c317025092032,0x387225202c347225\n"
".quad 0x36662e646c090a3b,0x2c37646625092034,0x302b346472255b20,0x70252140090a3b5d\n"
".quad 0x2409206172622031,0x3733355f325f744c,0x636f6c2e090a3b38,0x0934343109363109\n"
".quad 0x662e766f6d090a30,0x3864662509203436,0x0a3b34646625202c,0x363109636f6c2e09\n"
".quad 0x090a300935343109,0x203436662e766f6d,0x25202c3964662509,0x6c2e090a3b366466\n"
".quad 0x343109363109636f,0x766f6d090a300936,0x662509203436662e,0x646625202c303164\n"
".quad 0x636f6c2e090a3b32,0x0937343109363109,0x662e766f6d090a30,0x3164662509203436\n"
".quad 0x3b37646625202c31,0x3109636f6c2e090a,0x0a30093834310936,0x3436662e6c756d09\n"
".quad 0x2c32316466250920,0x25202c3264662520,0x6c2e090a3b326466,0x343109363109636f\n"
".quad 0x6c756d090a300939,0x662509203436662e,0x646625202c333164,0x3b37646625202c37\n"
".quad 0x6e752e617262090a,0x325f744c24092069,0x240a3b323231355f,0x3733355f325f744c\n"
".quad 0x636f6c2e090a3a38,0x0933353109363109,0x662e766f6d090a30,0x3864662509203436\n"
".quad 0x0a3b37646625202c,0x363109636f6c2e09,0x090a300934353109,0x203436662e766f6d\n"
".quad 0x25202c3964662509,0x6c2e090a3b326466,0x353109363109636f,0x766f6d090a300938\n"
".quad 0x662509203436662e,0x306430202c333164,0x3030303030303030,0x3b30303030303030\n"
".quad 0x6d090a30202f2f09,0x09203436662e766f,0x30202c3231646625,0x3030303030303064\n"
".quad 0x3030303030303030,0x0a30202f2f093b30,0x3436662e766f6d09,0x2c31316466250920\n"
".quad 0x3030303030643020,0x3030303030303030,0x202f2f093b303030,0x662e766f6d090a30\n"
".quad 0x3164662509203436,0x3030306430202c30,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x5f744c240a30202f,0x0a3a323231355f32,0x3233752e766f6d09,0x30202c3972250920\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x367225202c327025,0x090a3b397225202c\n"
".quad 0x6172622032702540,0x363142424c240920,0x6c614334315a5f5f,0x626c65646e614d63\n"
".quad 0x5076456449746f72,0x5f31535f544b5069,0x62695f31535f3153,0x2e766f6d090a3b69\n"
".quad 0x3172250920323373,0x4c240a3b30202c30,0x363431365f325f74,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x202c38353120656e,0x20676e697473656e\n"
".quad 0x31203a6874706564,0x616d69747365202c,0x7265746920646574,0x203a736e6f697461\n"
".quad 0x0a6e776f6e6b6e75,0x363109636f6c2e09,0x090a300932363109,0x203233732e627573\n"
".quad 0x7225202c37722509,0x6d090a3b31202c37,0x09203233752e766f,0x3b30202c31317225\n"
".quad 0x6c2e70746573090a,0x2509203233732e65,0x2c377225202c3370,0x090a3b3131722520\n"
".quad 0x6172622033702540,0x345f325f4c240920,0x2f2f200a3b363638,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x31365f325f744c24,0x2e646461090a3634,0x6466250920343666\n"
".quad 0x31646625202c3431,0x3231646625202c33,0x662e766f6d090a3b,0x3164662509203436\n"
".quad 0x3130346430202c35,0x3030303030303030,0x2f093b3030303030,0x746573090a34202f\n"
".quad 0x3436662e74672e70,0x25202c3470250920,0x6625202c34316466,0x2140090a3b353164\n"
".quad 0x2061726220347025,0x36345f325f4c2409,0x325f4c240a3b3031,0x200a3a363638345f\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383531,0x656c6562616c2064,0x5f325f744c242064,0x6c2e090a36343136\n"
".quad 0x363109363109636f,0x6c756d090a300933,0x203233752e6f6c2e,0x25202c3231722509\n"
".quad 0x0a3b34202c303172,0x3436752e74766309,0x722509203233752e,0x32317225202c3564\n"
".quad 0x752e646461090a3b,0x3664722509203436,0x202c35647225202c,0x73090a3b32647225\n"
".quad 0x5b09203233732e74,0x2c5d302b36647225,0x2e090a3b37722520,0x3109363109636f6c\n"
".quad 0x6461090a30093536,0x2509203233732e64,0x317225202c303172,0x73090a3b31202c30\n"
".quad 0x732e656e2e707465,0x2c35702509203233,0x7225202c36722520,0x702540090a3b3031\n"
".quad 0x2409206172622035,0x3034365f325f744c,0x2e617262090a3b32,0x424c240920696e75\n"
".quad 0x34315a5f5f363142,0x646e614d636c6143,0x6449746f72626c65,0x5f544b5069507645\n"
".quad 0x31535f31535f3153,0x4c240a3b6962695f,0x323034365f325f74,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c38353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a363431365f325f,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x2c30317225202c33,0x747663090a3b3820,0x3233752e3436752e\n"
".quad 0x202c376472250920,0x61090a3b33317225,0x09203436752e6464,0x7225202c38647225\n"
".quad 0x34647225202c3764,0x36662e646c090a3b,0x3631646625092034,0x2b386472255b202c\n"
".quad 0x252140090a3b5d30,0x0920617262203170,0x31375f325f744c24,0x3c2f2f200a3b3037\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x38353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3431365f325f744c,0x09636f6c2e090a36\n"
".quad 0x3009373631093631,0x36662e766f6d090a,0x2c38646625092034,0x090a3b3464662520\n"
".quad 0x09363109636f6c2e,0x6d090a3009383631,0x09203436662e766f,0x6625202c39646625\n"
".quad 0x6f6c2e090a3b3664,0x3936310936310963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x32646625202c3031,0x09636f6c2e090a3b,0x3009303731093631,0x36662e766f6d090a\n"
".quad 0x3131646625092034,0x3b3631646625202c,0x3109636f6c2e090a,0x0a30093137310936\n"
".quad 0x3436662e6c756d09,0x2c32316466250920,0x25202c3264662520,0x6c2e090a3b326466\n"
".quad 0x373109363109636f,0x6c756d090a300932,0x662509203436662e,0x646625202c333164\n"
".quad 0x31646625202c3631,0x2e617262090a3b36,0x744c240920696e75,0x3b343139365f325f\n"
".quad 0x375f325f744c240a,0x2f2f200a3a303731,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c38,0x2064656c6562616c\n"
".quad 0x31365f325f744c24,0x636f6c2e090a3634,0x0935373109363109,0x662e766f6d090a30\n"
".quad 0x3864662509203436,0x3b3631646625202c,0x3109636f6c2e090a,0x0a30093637310936\n"
".quad 0x3436662e766f6d09,0x202c396466250920,0x2e090a3b32646625,0x3109363109636f6c\n"
".quad 0x6f6d090a30093038,0x2509203436662e76,0x6430202c33316466,0x3030303030303030\n"
".quad 0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d,0x202c323164662509\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x36662e766f6d090a\n"
".quad 0x3131646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e766f6d090a3020,0x6466250920343666,0x30306430202c3031,0x3030303030303030\n"
".quad 0x093b303030303030,0x744c240a30202f2f,0x3a343139365f325f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3835312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x090a363431365f32,0x09363109636f6c2e\n"
".quad 0x6d090a3009333831,0x09203233732e766f,0x327225202c377225,0x345f325f4c240a3b\n"
".quad 0x2f2f200a3a303136,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x2064616568202c38,0x2064656c6562616c,0x31365f325f744c24\n"
".quad 0x636f6c2e090a3634,0x0935383109363109,0x662e6c756d090a30,0x3164662509203436\n"
".quad 0x3131646625202c37,0x3b3031646625202c,0x36662e646461090a,0x3831646625092034\n"
".quad 0x2c3731646625202c,0x0a3b373164662520,0x3436662e64646109,0x2c30316466250920\n"
".quad 0x25202c3964662520,0x2e090a3b38316466,0x3109363109636f6c,0x7573090a30093638\n"
".quad 0x2509203436662e62,0x6625202c39316466,0x646625202c333164,0x646461090a3b3231\n"
".quad 0x662509203436662e,0x646625202c313164,0x3931646625202c38,0x09636f6c2e090a3b\n"
".quad 0x3009373831093631,0x36662e6c756d090a,0x3231646625092034,0x2c3031646625202c\n"
".quad 0x0a3b303164662520,0x363109636f6c2e09,0x090a300938383109,0x203436662e6c756d\n"
".quad 0x202c333164662509,0x25202c3131646625,0x73090a3b31316466,0x732e656e2e707465\n"
".quad 0x2c36702509203233,0x7225202c36722520,0x702540090a3b3031,0x2409206172622036\n"
".quad 0x3431365f325f744c,0x3142424c240a3b36,0x614334315a5f5f36,0x6c65646e614d636c\n"
".quad 0x76456449746f7262,0x31535f544b506950,0x695f31535f31535f,0x6f6c2e090a3a6962\n"
".quad 0x3039310936310963,0x3b746572090a3009,0x646e6557444c240a,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5076456449746f72,0x5f31535f544b5069,0x62695f31535f3153\n"
".quad 0x2f2f207d090a3a69,0x6c614334315a5f20,0x626c65646e614d63,0x5076456449746f72\n"
".quad 0x5f31535f544b5069,0x62695f31535f3153,0x7369762e090a0a69,0x75662e20656c6269\n"
".quad 0x7261702e2820636e,0x203233732e206d61,0x6572616475635f5f,0x4334315a5f5f6674\n"
".quad 0x65646e614d636c61,0x456649746f72626c,0x30535f30535f5469,0x202962695f30535f\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053\n"
".quad 0x61702e282062695f,0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f31666d7261\n"
".quad 0x614d636c61433431,0x746f72626c65646e,0x30535f5469456649,0x695f30535f30535f\n"
".quad 0x617261702e202c62,0x5f203233662e206d,0x726170616475635f,0x34315a5f5f32666d\n"
".quad 0x646e614d636c6143,0x6649746f72626c65,0x535f30535f546945,0x2c62695f30535f30\n"
".quad 0x206d617261702e20,0x635f5f203233662e,0x666d726170616475,0x614334315a5f5f33\n"
".quad 0x6c65646e614d636c,0x69456649746f7262,0x5f30535f30535f54,0x2e202c62695f3053\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5f34666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053,0x61702e202c62695f\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x5a5f5f35666d7261,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x30535f5469456649,0x695f30535f30535f,0x617261702e202c62\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x34315a5f5f36666d,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x535f30535f546945,0x2962695f30535f30,0x65722e090a7b090a\n"
".quad 0x25203233752e2067,0x090a3b3e31313c72,0x33662e206765722e,0x3e35323c66252032\n"
".quad 0x206765722e090a3b,0x702520646572702e,0x6c2e090a3b3e373c,0x303209363109636f\n"
".quad 0x57444c240a300932,0x5a5f5f6e69676562,0x614d636c61433431,0x746f72626c65646e\n"
".quad 0x30535f5469456649,0x695f30535f30535f,0x702e646c090a3a62,0x3233662e6d617261\n"
".quad 0x5b202c3166250920,0x6170616475635f5f,0x315a5f5f31666d72,0x6e614d636c614334\n"
".quad 0x49746f72626c6564,0x5f30535f54694566,0x62695f30535f3053,0x2e766f6d090a3b5d\n"
".quad 0x3266250920323366,0x090a3b316625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c33,0x32666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63\n"
".quad 0x5469456649746f72,0x535f30535f30535f,0x090a3b5d62695f30,0x203233662e766f6d\n"
".quad 0x6625202c34662509,0x702e646c090a3b33,0x3233662e6d617261,0x5b202c3566250920\n"
".quad 0x6170616475635f5f,0x315a5f5f33666d72,0x6e614d636c614334,0x49746f72626c6564\n"
".quad 0x5f30535f54694566,0x62695f30535f3053,0x2e766f6d090a3b5d,0x3666250920323366\n"
".quad 0x090a3b356625202c,0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c37\n"
".quad 0x34666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5469456649746f72\n"
".quad 0x535f30535f30535f,0x090a3b5d62695f30,0x203233662e766f6d,0x6625202c38662509\n"
".quad 0x702e646c090a3b37,0x3233752e6d617261,0x5b202c3172250920,0x6170616475635f5f\n"
".quad 0x315a5f5f35666d72,0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694566\n"
".quad 0x62695f30535f3053,0x2e766f6d090a3b5d,0x3272250920323373,0x090a3b317225202c\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x75635f5f5b202c33,0x36666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456649746f72,0x535f30535f30535f\n"
".quad 0x090a3b5d62695f30,0x732e38732e747663,0x2c34722509203233,0x6d090a3b33722520\n"
".quad 0x09203233752e766f,0x0a3b30202c357225,0x71652e7074657309,0x702509203233732e\n"
".quad 0x202c347225202c31,0x2540090a3b357225,0x0920617262203170,0x38335f335f744c24\n"
".quad 0x6f6c2e090a3b3234,0x3530320936310963,0x2e766f6d090a3009,0x3966250920323366\n"
".quad 0x090a3b366625202c,0x09363109636f6c2e,0x6d090a3009363032,0x09203233662e766f\n"
".quad 0x6625202c30316625,0x636f6c2e090a3b38,0x0937303209363109,0x662e766f6d090a30\n"
".quad 0x3131662509203233,0x090a3b346625202c,0x09363109636f6c2e,0x6d090a3009383032\n"
".quad 0x09203233662e766f,0x6625202c32316625,0x636f6c2e090a3b32,0x0939303209363109\n"
".quad 0x662e6c756d090a30,0x3331662509203233,0x25202c346625202c,0x6f6c2e090a3b3466\n"
".quad 0x3031320936310963,0x2e6c756d090a3009,0x3166250920323366,0x202c326625202c34\n"
".quad 0x7262090a3b326625,0x240920696e752e61,0x3835335f335f744c,0x335f744c240a3b36\n"
".quad 0x090a3a323438335f,0x09363109636f6c2e,0x6d090a3009343132,0x09203233662e766f\n"
".quad 0x326625202c396625,0x09636f6c2e090a3b,0x3009353132093631,0x33662e766f6d090a\n"
".quad 0x2c30316625092032,0x2e090a3b34662520,0x3209363109636f6c,0x6f6d090a30093931\n"
".quad 0x2509203233662e76,0x306630202c343166,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3331662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x30202c3231662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30306630202c3131\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x335f335f744c240a,0x6c2e090a3a363835\n"
".quad 0x323209363109636f,0x627573090a300933,0x722509203233732e,0x202c327225202c36\n"
".quad 0x2e766f6d090a3b31,0x3772250920323375,0x6573090a3b31202c,0x33732e71652e7074\n"
".quad 0x202c327025092032,0x377225202c327225,0x2032702540090a3b,0x744c240920617262\n"
".quad 0x3b383930345f335f,0x33662e646461090a,0x2c35316625092032,0x25202c3431662520\n"
".quad 0x6f6d090a3b333166,0x2509203233662e76,0x346630202c363166,0x3b30303030303830\n"
".quad 0x202f2f0920202020,0x2e70746573090a34,0x09203233662e746c,0x316625202c337025\n"
".quad 0x3b36316625202c35,0x203370252140090a,0x744c240920617262,0x3b383930345f335f\n"
".quad 0x35325f335f4c240a,0x3c2f2f200a3a3236,0x6f4c203e706f6f6c,0x2079646f6220706f\n"
".quad 0x34323220656e696c,0x3109636f6c2e090a,0x0a30093432320936,0x3233662e6c756d09\n"
".quad 0x202c373166250920,0x6625202c32316625,0x646461090a3b3131,0x662509203233662e\n"
".quad 0x37316625202c3831,0x0a3b37316625202c,0x3233662e64646109,0x202c313166250920\n"
".quad 0x6625202c30316625,0x6f6c2e090a3b3831,0x3532320936310963,0x2e627573090a3009\n"
".quad 0x3166250920323366,0x2c34316625202c39,0x090a3b3331662520,0x203233662e646461\n"
".quad 0x25202c3231662509,0x39316625202c3966,0x09636f6c2e090a3b,0x3009363232093631\n"
".quad 0x33662e6c756d090a,0x2c30326625092032,0x25202c3131662520,0x6f6d090a3b313166\n"
".quad 0x2509203233662e76,0x326625202c333166,0x636f6c2e090a3b30,0x0937323209363109\n"
".quad 0x662e6c756d090a30,0x3132662509203233,0x202c32316625202c,0x6d090a3b32316625\n"
".quad 0x09203233662e766f,0x6625202c34316625,0x6f6c2e090a3b3132,0x3332320936310963\n"
".quad 0x2e627573090a3009,0x3672250920323373,0x31202c367225202c,0x752e766f6d090a3b\n"
".quad 0x2c38722509203233,0x746573090a3b3020,0x3233732e71652e70,0x25202c3470250920\n"
".quad 0x3b387225202c3672,0x622034702540090a,0x5f744c2409206172,0x0a3b383930345f33\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c34323220,0x6c6562616c206461,0x5f335f4c24206465,0x6461090a32363532\n"
".quad 0x2509203233662e64,0x326625202c323266,0x3b31326625202c30,0x33662e766f6d090a\n"
".quad 0x2c33326625092032,0x3030383034663020,0x202020203b303030,0x73090a34202f2f09\n"
".quad 0x662e746c2e707465,0x2c35702509203233,0x25202c3232662520,0x2540090a3b333266\n"
".quad 0x0920617262203570,0x3635325f335f4c24,0x335f744c240a3b32,0x240a3a383930345f\n"
".quad 0x383138325f335f4c,0x09636f6c2e090a3a,0x3009393232093631,0x33732e766f6d090a\n"
".quad 0x202c397225092032,0x7473090a3b367225,0x732e6d617261702e,0x635f5f5b09203233\n"
".quad 0x5f66746572616475,0x636c614334315a5f,0x72626c65646e614d,0x5f5469456649746f\n"
".quad 0x30535f30535f3053,0x7225202c5d62695f,0x3b746572090a3b39,0x646e6557444c240a\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456649746f72,0x535f30535f30535f\n"
".quad 0x7d090a3a62695f30,0x34315a5f202f2f20,0x646e614d636c6143,0x6649746f72626c65\n"
".quad 0x535f30535f546945,0x0a62695f30535f30,0x62697369762e090a,0x636e75662e20656c\n"
".quad 0x6d617261702e2820,0x5f5f203233732e20,0x6674657261647563,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5469456449746f72,0x535f30535f30535f,0x5a5f202962695f30\n"
".quad 0x614d636c61433431,0x746f72626c65646e,0x30535f5469456449,0x695f30535f30535f\n"
".quad 0x617261702e282062,0x5f203436662e206d,0x726170616475635f,0x34315a5f5f31666d\n"
".quad 0x646e614d636c6143,0x6449746f72626c65,0x535f30535f546945,0x2c62695f30535f30\n"
".quad 0x206d617261702e20,0x635f5f203436662e,0x666d726170616475,0x614334315a5f5f32\n"
".quad 0x6c65646e614d636c,0x69456449746f7262,0x5f30535f30535f54,0x2e202c62695f3053\n"
".quad 0x662e206d61726170,0x6475635f5f203436,0x5f33666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456449746f,0x30535f30535f3053,0x61702e202c62695f\n"
".quad 0x3436662e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x30535f5469456449,0x695f30535f30535f,0x617261702e202c62\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x34315a5f5f35666d,0x646e614d636c6143\n"
".quad 0x6449746f72626c65,0x535f30535f546945,0x2c62695f30535f30,0x206d617261702e20\n"
".quad 0x635f5f203233732e,0x666d726170616475,0x614334315a5f5f36,0x6c65646e614d636c\n"
".quad 0x69456449746f7262,0x5f30535f30535f54,0x090a2962695f3053,0x206765722e090a7b\n"
".quad 0x3c7225203233752e,0x722e090a3b3e3131,0x203436662e206765,0x3b3e35323c646625\n"
".quad 0x2e206765722e090a,0x3c70252064657270,0x6f6c2e090a3b3e37,0x3230320936310963\n"
".quad 0x6257444c240a3009,0x315a5f5f6e696765,0x6e614d636c614334,0x49746f72626c6564\n"
".quad 0x5f30535f54694564,0x62695f30535f3053,0x61702e646c090a3a,0x203436662e6d6172\n"
".quad 0x5b202c3164662509,0x6170616475635f5f,0x315a5f5f31666d72,0x6e614d636c614334\n"
".quad 0x49746f72626c6564,0x5f30535f54694564,0x62695f30535f3053,0x2e766f6d090a3b5d\n"
".quad 0x6466250920343666,0x3b31646625202c32,0x7261702e646c090a,0x09203436662e6d61\n"
".quad 0x5f5b202c33646625,0x726170616475635f,0x34315a5f5f32666d,0x646e614d636c6143\n"
".quad 0x6449746f72626c65,0x535f30535f546945,0x5d62695f30535f30,0x662e766f6d090a3b\n"
".quad 0x3464662509203436,0x0a3b33646625202c,0x617261702e646c09,0x2509203436662e6d\n"
".quad 0x5f5f5b202c356466,0x6d72617061647563,0x4334315a5f5f3366,0x65646e614d636c61\n"
".quad 0x456449746f72626c,0x30535f30535f5469,0x3b5d62695f30535f,0x36662e766f6d090a\n"
".quad 0x2c36646625092034,0x090a3b3564662520,0x6d617261702e646c,0x662509203436662e\n"
".quad 0x635f5f5b202c3764,0x666d726170616475,0x614334315a5f5f34,0x6c65646e614d636c\n"
".quad 0x69456449746f7262,0x5f30535f30535f54,0x0a3b5d62695f3053,0x3436662e766f6d09\n"
".quad 0x202c386466250920,0x6c090a3b37646625,0x2e6d617261702e64,0x3172250920323375\n"
".quad 0x6475635f5f5b202c,0x5f35666d72617061,0x636c614334315a5f,0x72626c65646e614d\n"
".quad 0x5f5469456449746f,0x30535f30535f3053,0x6d090a3b5d62695f,0x09203233732e766f\n"
".quad 0x317225202c327225,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c33722509\n"
".quad 0x726170616475635f,0x34315a5f5f36666d,0x646e614d636c6143,0x6449746f72626c65\n"
".quad 0x535f30535f546945,0x5d62695f30535f30,0x732e747663090a3b,0x2509203233732e38\n"
".quad 0x3b337225202c3472,0x33752e766f6d090a,0x202c357225092032,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x7225202c31702509,0x0a3b357225202c34,0x7262203170254009\n"
".quad 0x345f744c24092061,0x090a3b323438335f,0x09363109636f6c2e,0x6d090a3009353032\n"
".quad 0x09203436662e766f,0x6625202c39646625,0x6f6c2e090a3b3664,0x3630320936310963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x38646625202c3031,0x09636f6c2e090a3b\n"
".quad 0x3009373032093631,0x36662e766f6d090a,0x3131646625092034,0x0a3b34646625202c\n"
".quad 0x363109636f6c2e09,0x090a300938303209,0x203436662e766f6d,0x202c323164662509\n"
".quad 0x2e090a3b32646625,0x3209363109636f6c,0x756d090a30093930,0x2509203436662e6c\n"
".quad 0x6625202c33316466,0x34646625202c3464,0x09636f6c2e090a3b,0x3009303132093631\n"
".quad 0x36662e6c756d090a,0x3431646625092034,0x202c32646625202c,0x62090a3b32646625\n"
".quad 0x0920696e752e6172,0x35335f345f744c24,0x5f744c240a3b3638,0x0a3a323438335f34\n"
".quad 0x363109636f6c2e09,0x090a300934313209,0x203436662e766f6d,0x25202c3964662509\n"
".quad 0x6c2e090a3b326466,0x313209363109636f,0x766f6d090a300935,0x662509203436662e\n"
".quad 0x646625202c303164,0x636f6c2e090a3b34,0x0939313209363109,0x662e766f6d090a30\n"
".quad 0x3164662509203436,0x3030306430202c34,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x766f6d090a30202f,0x662509203436662e,0x306430202c333164,0x3030303030303030\n"
".quad 0x3b30303030303030,0x6d090a30202f2f09,0x09203436662e766f,0x30202c3231646625\n"
".quad 0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30,0x3436662e766f6d09\n"
".quad 0x2c31316466250920,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x5f345f744c240a30,0x2e090a3a36383533,0x3209363109636f6c,0x7573090a30093332\n"
".quad 0x2509203233732e62,0x2c327225202c3672,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x73090a3b31202c37,0x732e71652e707465,0x2c32702509203233,0x7225202c32722520\n"
".quad 0x32702540090a3b37,0x4c24092061726220,0x383930345f345f74,0x662e646461090a3b\n"
".quad 0x3164662509203436,0x3431646625202c35,0x3b3331646625202c,0x36662e766f6d090a\n"
".quad 0x3631646625092034,0x303130346430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x70746573090a3420,0x203436662e746c2e,0x6625202c33702509,0x646625202c353164\n"
".quad 0x252140090a3b3631,0x0920617262203370,0x30345f345f744c24,0x345f4c240a3b3839\n"
".quad 0x200a3a323635325f,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x6f6c2e090a343232,0x3432320936310963,0x2e6c756d090a3009,0x6466250920343666\n"
".quad 0x31646625202c3731,0x3131646625202c32,0x662e646461090a3b,0x3164662509203436\n"
".quad 0x3731646625202c38,0x3b3731646625202c,0x36662e646461090a,0x3131646625092034\n"
".quad 0x2c3031646625202c,0x0a3b383164662520,0x363109636f6c2e09,0x090a300935323209\n"
".quad 0x203436662e627573,0x202c393164662509,0x25202c3431646625,0x61090a3b33316466\n"
".quad 0x09203436662e6464,0x25202c3231646625,0x646625202c396466,0x6f6c2e090a3b3931\n"
".quad 0x3632320936310963,0x2e6c756d090a3009,0x6466250920343666,0x31646625202c3032\n"
".quad 0x3131646625202c31,0x662e766f6d090a3b,0x3164662509203436,0x3032646625202c33\n"
".quad 0x09636f6c2e090a3b,0x3009373232093631,0x36662e6c756d090a,0x3132646625092034\n"
".quad 0x2c3231646625202c,0x0a3b323164662520,0x3436662e766f6d09,0x2c34316466250920\n"
".quad 0x0a3b313264662520,0x363109636f6c2e09,0x090a300933323209,0x203233732e627573\n"
".quad 0x7225202c36722509,0x6d090a3b31202c36,0x09203233752e766f,0x0a3b30202c387225\n"
".quad 0x71652e7074657309,0x702509203233732e,0x202c367225202c34,0x2540090a3b387225\n"
".quad 0x0920617262203470,0x30345f345f744c24,0x3c2f2f200a3b3839,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x34323220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x323635325f345f4c,0x36662e646461090a,0x3232646625092034\n"
".quad 0x2c3032646625202c,0x0a3b313264662520,0x3436662e766f6d09,0x2c33326466250920\n"
".quad 0x3030313034643020,0x3030303030303030,0x202f2f093b303030,0x2e70746573090a34\n"
".quad 0x09203436662e746c,0x646625202c357025,0x32646625202c3232,0x35702540090a3b33\n"
".quad 0x4c24092061726220,0x3b323635325f345f,0x345f345f744c240a,0x5f4c240a3a383930\n"
".quad 0x0a3a383138325f34,0x363109636f6c2e09,0x090a300939323209,0x203233732e766f6d\n"
".quad 0x7225202c39722509,0x702e7473090a3b36,0x3233732e6d617261,0x6475635f5f5b0920\n"
".quad 0x5a5f5f6674657261,0x614d636c61433431,0x746f72626c65646e,0x30535f5469456449\n"
".quad 0x695f30535f30535f,0x3b397225202c5d62,0x240a3b746572090a,0x5f5f646e6557444c\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30\n"
".quad 0x2f207d090a3a6269,0x614334315a5f202f,0x6c65646e614d636c,0x69456449746f7262\n"
".quad 0x5f30535f30535f54,0x2e090a62695f3053,0x2e206c61626f6c67,0x636f6c6220323375\n"
".quad 0x7265746e756f436b,0x746e652e090a0a3b,0x4d38315a5f207972,0x6f72626c65646e61\n"
".quad 0x316d735f30534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x2e09090a28206269,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3831,0x5f305344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x73645f6269696969,0x61702e09090a2c74,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x67616d695f626969\n"
".quad 0x702e09090a2c5765,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f305344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x616d695f62696969,0x2e09090a2c486567,0x732e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x72635f6269696969\n"
".quad 0x09090a2c68636e75,0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x785f62696969695f,0x09090a2c3066664f,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c\n"
".quad 0x75365033316d735f,0x6969693472616863,0x5366666666666666,0x785f62696969695f\n"
".quad 0x09090a2c3166664f,0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x795f62696969695f,0x09090a2c3066664f,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c\n"
".quad 0x75365033316d735f,0x6969693472616863,0x5366666666666666,0x795f62696969695f\n"
".quad 0x09090a2c3166664f,0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x785f62696969695f,0x702e09090a2c504a,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72\n"
".quad 0x686375365033316d,0x6666696969347261,0x695f536666666666,0x504a795f62696969\n"
".quad 0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f30534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x656c6163735f6269,0x7261702e09090a2c,0x67696c612e206d61\n"
".quad 0x2038622e2034206e,0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x316d735f30534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x726f6c6f635f6269,0x09090a2c5d345b73,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x665f62696969695f,0x09090a2c656d6172\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x305344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x615f62696969695f,0x6e6f6974616d696e,0x090a2c656d617246,0x206d617261702e09\n"
".quad 0x635f5f203233732e,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x7464695764697267,0x61702e09090a2c68,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x426d756e5f626969,0x090a2c736b636f6c\n"
".quad 0x206d617261702e09,0x75635f5f2038732e,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x305344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x695f62696969695f,0x090a7b090a294a73,0x33752e206765722e,0x3e31393c72252032\n"
".quad 0x206765722e090a3b,0x647225203436752e,0x722e090a3b3e373c,0x203233662e206765\n"
".quad 0x3b3e3832323c6625,0x2e206765722e090a,0x3c70252064657270,0x732e090a3b3e3731\n"
".quad 0x752e206465726168,0x6475635f5f203233,0x5f6c61636f6c5f61,0x353336335f726176\n"
".quad 0x6e6f6e5f32345f38,0x625f74736e6f635f,0x65646e496b636f6c,0x6168732e090a3b78\n"
".quad 0x3233752e20646572,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f39353336335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x732e090a3b586b63,0x752e206465726168\n"
".quad 0x6475635f5f203233,0x5f6c61636f6c5f61,0x353336335f726176,0x6e6f6e5f30355f39\n"
".quad 0x625f74736e6f635f,0x090a3b596b636f6c,0x09373109636f6c2e,0x4c240a3009343131\n"
".quad 0x5f6e696765625744,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30\n"
".quad 0x6969347261686375,0x6666666666666669,0x3a62696969695f53,0x33752e766f6d090a\n"
".quad 0x202c317225092032,0x0a3b782e64697425,0x3233752e766f6d09,0x30202c3272250920\n"
".quad 0x2e70746573090a3b,0x09203233752e7165,0x317225202c317025,0x090a3b327225202c\n"
".quad 0x203233752e766f6d,0x7425202c33722509,0x6d090a3b792e6469,0x09203233752e766f\n"
".quad 0x0a3b30202c347225,0x71652e7074657309,0x702509203233752e,0x202c337225202c32\n"
".quad 0x6573090a3b347225,0x09203233732e706c,0x202c31202c357225,0x0a3b317025202c30\n"
".quad 0x33732e706c657309,0x202c367225092032,0x7025202c30202c31,0x2e646e61090a3b32\n"
".quad 0x3772250920323362,0x25202c357225202c,0x766f6d090a3b3672,0x722509203233752e\n"
".quad 0x73090a3b30202c38,0x732e71652e707465,0x2c33702509203233,0x7225202c37722520\n"
".quad 0x33702540090a3b38,0x4c24092061726220,0x363839395f355f74,0x09636f6c2e090a3b\n"
".quad 0x3009313231093731,0x36752e766f6d090a,0x2c31647225092034,0x6f436b636f6c6220\n"
".quad 0x090a3b7265746e75,0x203233752e766f6d,0x3b31202c39722509,0x672e6d6f7461090a\n"
".quad 0x64612e6c61626f6c,0x2509203233752e64,0x72255b202c303172,0x397225202c5d3164\n"
".quad 0x732e766f6d090a3b,0x3131722509203233,0x0a3b30317225202c,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38353336335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x5d7865646e496b63,0x0a3b31317225202c\n"
".quad 0x373109636f6c2e09,0x090a300932323109,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3231,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x7464695764697267,0x6d6572090a3b5d68,0x722509203233752e,0x31317225202c3331\n"
".quad 0x0a3b32317225202c,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f39353336335f72,0x635f6e6f6e5f3234,0x6f6c625f74736e6f\n"
".quad 0x7225202c5d586b63,0x6f6c2e090a3b3331,0x3332310937310963,0x2e766964090a3009\n"
".quad 0x3172250920323375,0x2c31317225202c34,0x090a3b3231722520,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f,0x355f39353336335f\n"
".quad 0x6f635f6e6f6e5f30,0x636f6c625f74736e,0x317225202c5d596b,0x355f744c240a3b34\n"
".quad 0x090a3a363839395f,0x09373109636f6c2e,0x62090a3009353231,0x20636e79732e7261\n"
".quad 0x2e646c090a3b3009,0x33752e6d61726170,0x2c35317225092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x6d756e5f62696969,0x3b5d736b636f6c42\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x5b202c3631722509,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f38353336335f,0x6f635f6e6f6e5f32,0x636f6c625f74736e\n"
".quad 0x3b5d7865646e496b,0x672e70746573090a,0x2509203233752e65,0x36317225202c3470\n"
".quad 0x0a3b35317225202c,0x7262203470254009,0x355f744c24092061,0x0a3b38393430315f\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c373172,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5033316d735f3053,0x6934726168637536\n"
".quad 0x6666666666666969,0x62696969695f5366,0x5d486567616d695f,0x61702e646c090a3b\n"
".quad 0x203233732e6d6172,0x5b202c3831722509,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f30534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x6567616d695f6269,0x766f6d090a3b5d57,0x722509203233752e\n"
".quad 0x69746e25202c3931,0x6f6d090a3b792e64,0x2509203233752e76,0x746e25202c303272\n"
".quad 0x4c240a3b782e6469,0x313031315f355f74,0x6c3c2f2f200a3a30,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x0a35323120656e69,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5f5b202c31327225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32345f3935333633\n"
".quad 0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x6c756d090a3b5d58,0x203233752e6f6c2e\n"
".quad 0x25202c3232722509,0x327225202c313272,0x732e646c090a3b30,0x33752e6465726168\n"
".quad 0x2c33327225092032,0x616475635f5f5b20,0x765f6c61636f6c5f,0x39353336335f7261\n"
".quad 0x5f6e6f6e5f30355f,0x6c625f74736e6f63,0x090a3b5d596b636f,0x752e6f6c2e6c756d\n"
".quad 0x3432722509203233,0x202c33327225202c,0x61090a3b39317225,0x09203233752e6464\n"
".quad 0x7225202c35327225,0x3b317225202c3232,0x33752e646461090a,0x2c36327225092032\n"
".quad 0x25202c3432722520,0x746573090a3b3372,0x2e3233752e74672e,0x3272250920323373\n"
".quad 0x2c37317225202c37,0x090a3b3632722520,0x203233732e67656e,0x25202c3832722509\n"
".quad 0x6573090a3b373272,0x3233752e74672e74,0x722509203233732e,0x38317225202c3932\n"
".quad 0x0a3b35327225202c,0x3233732e67656e09,0x202c303372250920,0x61090a3b39327225\n"
".quad 0x09203233622e646e,0x7225202c31337225,0x30337225202c3832,0x752e766f6d090a3b\n"
".quad 0x3233722509203233,0x6573090a3b30202c,0x33732e71652e7074,0x202c357025092032\n"
".quad 0x7225202c31337225,0x702540090a3b3233,0x2409206172622035,0x3832315f355f744c\n"
".quad 0x3c2f2f200a3b3230,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3031315f355f744c\n"
".quad 0x636f6c2e090a3031,0x0930343109373109,0x722e747663090a30,0x33732e3233662e6e\n"
".quad 0x202c316625092032,0x6c090a3b35327225,0x2e6d617261702e64,0x3266250920323366\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x63735f6269696969\n"
".quad 0x6d090a3b5d656c61,0x09203233662e6c75,0x316625202c336625,0x090a3b326625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c34,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x785f62696969695f,0x090a3b5d3066664f,0x203233662e646461\n"
".quad 0x6625202c35662509,0x0a3b346625202c33,0x3233662e62757309,0x25202c3666250920\n"
".quad 0x3b336625202c3566,0x33662e627573090a,0x202c376625092032,0x366625202c346625\n"
".quad 0x662e627573090a3b,0x2c38662509203233,0x6625202c35662520,0x2e627573090a3b36\n"
".quad 0x3966250920323366,0x25202c336625202c,0x646461090a3b3866,0x662509203233662e\n"
".quad 0x2c376625202c3031,0x6c090a3b39662520,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x75635f5f5b202c31,0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c\n"
".quad 0x75365033316d735f,0x6969693472616863,0x5366666666666666,0x785f62696969695f\n"
".quad 0x090a3b5d3166664f,0x203233662e646461,0x25202c3231662509,0x316625202c313166\n"
".quad 0x2e646461090a3b30,0x3166250920323366,0x202c356625202c33,0x73090a3b32316625\n"
".quad 0x09203233662e6275,0x6625202c34316625,0x3b356625202c3331,0x33662e627573090a\n"
".quad 0x2c35316625092032,0x25202c3231662520,0x6c2e090a3b343166,0x343109373109636f\n"
".quad 0x747663090a300931,0x2e3233662e6e722e,0x3166250920323373,0x3b36327225202c36\n"
".quad 0x33662e6c756d090a,0x2c37316625092032,0x25202c3631662520,0x2e646c090a3b3266\n"
".quad 0x33662e6d61726170,0x2c38316625092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f305344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x664f795f62696969,0x6461090a3b5d3066,0x2509203233662e64\n"
".quad 0x316625202c393166,0x3b38316625202c37,0x33662e627573090a,0x2c30326625092032\n"
".quad 0x25202c3931662520,0x7573090a3b373166,0x2509203233662e62,0x316625202c313266\n"
".quad 0x3b30326625202c38,0x33662e627573090a,0x2c32326625092032,0x25202c3931662520\n"
".quad 0x7573090a3b303266,0x2509203233662e62,0x316625202c333266,0x3b32326625202c37\n"
".quad 0x33662e646461090a,0x2c34326625092032,0x25202c3132662520,0x646c090a3b333266\n"
".quad 0x662e6d617261702e,0x3532662509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3831,0x5f305344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x4f795f6269696969,0x61090a3b5d316666,0x09203233662e6464\n"
".quad 0x6625202c36326625,0x34326625202c3532,0x662e646461090a3b,0x3732662509203233\n"
".quad 0x202c39316625202c,0x73090a3b36326625,0x09203233662e6275,0x6625202c38326625\n"
".quad 0x39316625202c3732,0x662e627573090a3b,0x3932662509203233,0x202c36326625202c\n"
".quad 0x2e090a3b38326625,0x3109373109636f6c,0x646c090a30093434,0x732e6d617261702e\n"
".quad 0x2c33337225092038,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x4a73695f62696969,0x2e766f6d090a3b5d,0x3372250920323375,0x73090a3b30202c34\n"
".quad 0x732e71652e707465,0x2c36702509203233,0x25202c3333722520,0x2540090a3b343372\n"
".quad 0x0920617262203670,0x32315f355f744c24,0x2f2f200a3b343330,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x31315f355f744c24,0x6f6c2e090a303130,0x3335320936310963\n"
".quad 0x702e646c090a3009,0x3233662e6d617261,0x202c303366250920,0x70616475635f5f5b\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x5d504a785f626969,0x09636f6c2e090a3b\n"
".quad 0x3009353532093631,0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c31336625\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f305344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x0a3b5d504a795f62\n"
".quad 0x363109636f6c2e09,0x090a300937353209,0x203233662e766f6d,0x25202c3233662509\n"
".quad 0x6c2e090a3b373266,0x353209363109636f,0x766f6d090a300938,0x662509203233662e\n"
".quad 0x39326625202c3333,0x09636f6c2e090a3b,0x3009393532093631,0x33662e766f6d090a\n"
".quad 0x2c34336625092032,0x090a3b3331662520,0x09363109636f6c2e,0x6d090a3009303632\n"
".quad 0x09203233662e766f,0x6625202c35336625,0x6f6c2e090a3b3531,0x3136320936310963\n"
".quad 0x2e766f6d090a3009,0x3366250920323366,0x3036346630202c36,0x20203b3030343030\n"
".quad 0x3138202f2f092020,0x2e6c756d090a3339,0x3366250920323366,0x2c37326625202c37\n"
".quad 0x090a3b3633662520,0x203233662e627573,0x25202c3833662509,0x326625202c373366\n"
".quad 0x2e627573090a3b37,0x3366250920323366,0x2c37336625202c39,0x090a3b3833662520\n"
".quad 0x203233662e627573,0x25202c3034662509,0x336625202c373266,0x2e6c756d090a3b39\n"
".quad 0x3466250920323366,0x2c37326625202c31,0x090a3b3732662520,0x203233662e6c756d\n"
".quad 0x25202c3234662509,0x326625202c373266,0x2e616d66090a3b39,0x09203233662e6e72\n"
".quad 0x6625202c33346625,0x39326625202c3732,0x0a3b32346625202c,0x3233662e64646109\n"
".quad 0x202c343466250920,0x6625202c31346625,0x6c756d090a3b3334,0x662509203233662e\n"
".quad 0x39336625202c3534,0x0a3b39336625202c,0x3233662e62757309,0x202c363466250920\n"
".quad 0x6625202c35346625,0x627573090a3b3134,0x662509203233662e,0x34346625202c3734\n"
".quad 0x0a3b31346625202c,0x2e6e722e616d6609,0x3466250920323366,0x2c39336625202c38\n"
".quad 0x25202c3034662520,0x7573090a3b363466,0x2509203233662e62,0x346625202c393466\n"
".quad 0x3b37346625202c34,0x33662e627573090a,0x2c30356625092032,0x25202c3334662520\n"
".quad 0x6d66090a3b373466,0x3233662e6e722e61,0x202c313566250920,0x6625202c39336625\n"
".quad 0x38346625202c3034,0x662e627573090a3b,0x3235662509203233,0x202c31346625202c\n"
".quad 0x66090a3b39346625,0x33662e6e722e616d,0x2c33356625092032,0x25202c3034662520\n"
".quad 0x356625202c303466,0x2e646461090a3b31,0x3566250920323366,0x2c30356625202c34\n"
".quad 0x090a3b3235662520,0x203233662e646461,0x25202c3535662509,0x356625202c333566\n"
".quad 0x2e616d66090a3b34,0x09203233662e6e72,0x6625202c36356625,0x39326625202c3932\n"
".quad 0x0a3b35356625202c,0x3233662e64646109,0x202c373566250920,0x6625202c34346625\n"
".quad 0x766f6d090a3b3635,0x662509203233662e,0x37356625202c3835,0x662e627573090a3b\n"
".quad 0x3935662509203233,0x202c37356625202c,0x73090a3b34346625,0x09203233662e6275\n"
".quad 0x6625202c30366625,0x39356625202c3635,0x09636f6c2e090a3b,0x3009323632093631\n"
".quad 0x33662e766f6d090a,0x2c31366625092032,0x3030303634663020,0x202020203b303034\n"
".quad 0x33393138202f2f09,0x33662e6c756d090a,0x2c32366625092032,0x25202c3331662520\n"
".quad 0x7573090a3b313666,0x2509203233662e62,0x366625202c333666,0x3b33316625202c32\n"
".quad 0x33662e627573090a,0x2c34366625092032,0x25202c3236662520,0x7573090a3b333666\n"
".quad 0x2509203233662e62,0x316625202c353666,0x3b34366625202c33,0x33662e6c756d090a\n"
".quad 0x2c36366625092032,0x25202c3331662520,0x756d090a3b333166,0x2509203233662e6c\n"
".quad 0x316625202c373666,0x3b35316625202c33,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x33316625202c3836,0x202c35316625202c,0x61090a3b37366625,0x09203233662e6464\n"
".quad 0x6625202c39366625,0x38366625202c3636,0x662e6c756d090a3b,0x3037662509203233\n"
".quad 0x202c34366625202c,0x73090a3b34366625,0x09203233662e6275,0x6625202c31376625\n"
".quad 0x36366625202c3037,0x662e627573090a3b,0x3237662509203233,0x202c39366625202c\n"
".quad 0x66090a3b36366625,0x33662e6e722e616d,0x2c33376625092032,0x25202c3436662520\n"
".quad 0x376625202c353666,0x2e627573090a3b31,0x3766250920323366,0x2c39366625202c34\n"
".quad 0x090a3b3237662520,0x203233662e627573,0x25202c3537662509,0x376625202c383666\n"
".quad 0x2e616d66090a3b32,0x09203233662e6e72,0x6625202c36376625,0x35366625202c3436\n"
".quad 0x0a3b33376625202c,0x3233662e62757309,0x202c373766250920,0x6625202c36366625\n"
".quad 0x616d66090a3b3437,0x203233662e6e722e,0x25202c3837662509,0x366625202c353666\n"
".quad 0x3b36376625202c35,0x33662e646461090a,0x2c39376625092032,0x25202c3537662520\n"
".quad 0x6461090a3b373766,0x2509203233662e64,0x376625202c303866,0x3b39376625202c38\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x35316625202c3138,0x202c35316625202c\n"
".quad 0x61090a3b30386625,0x09203233662e6464,0x6625202c32386625,0x31386625202c3936\n"
".quad 0x662e766f6d090a3b,0x3338662509203233,0x0a3b32386625202c,0x3233662e62757309\n"
".quad 0x202c343866250920,0x6625202c32386625,0x627573090a3b3936,0x662509203233662e\n"
".quad 0x31386625202c3538,0x0a3b34386625202c,0x3233662e766f6d09,0x202c363866250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x306630202c373866,0x3b30303030303030,0x202f2f0920202020,0x752e617262090a30\n"
".quad 0x5f744c240920696e,0x3b38373731315f35,0x315f355f744c240a,0x2f200a3a34333032\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3532,0x64656c6562616c20,0x315f355f744c2420,0x6c2e090a30313031\n"
".quad 0x363209363109636f,0x766f6d090a300935,0x662509203233662e,0x33316625202c3033\n"
".quad 0x09636f6c2e090a3b,0x3009363632093631,0x33662e766f6d090a,0x2c37386625092032\n"
".quad 0x090a3b3531662520,0x09363109636f6c2e,0x6d090a3009373632,0x09203233662e766f\n"
".quad 0x6625202c31336625,0x6f6c2e090a3b3732,0x3836320936310963,0x2e766f6d090a3009\n"
".quad 0x3866250920323366,0x3b39326625202c36,0x3109636f6c2e090a,0x0a30093637320936\n"
".quad 0x3233662e766f6d09,0x202c353866250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c333866,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3036662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3835662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x30306630202c3533,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c34336625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c33336625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3366250920323366,0x3030306630202c32,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x31315f355f744c24,0x2f2f200a3a383737,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x31315f355f744c24,0x6f6c2e090a303130,0x3038320936310963\n"
".quad 0x702e646c090a3009,0x3233732e6d617261,0x202c353372250920,0x70616475635f5f5b\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x6e7572635f626969,0x7573090a3b5d6863\n"
".quad 0x2509203233732e62,0x337225202c363372,0x6d090a3b31202c35,0x09203233752e766f\n"
".quad 0x3b31202c37337225,0x652e70746573090a,0x2509203233732e71,0x35337225202c3770\n"
".quad 0x0a3b37337225202c,0x7262203770254009,0x355f744c24092061,0x0a3b38333334315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35323120,0x6c6562616c206461,0x355f744c24206465,0x090a30313031315f\n"
".quad 0x203233662e646461,0x25202c3838662509,0x356625202c333866,0x2e627573090a3b38\n"
".quad 0x3866250920323366,0x2c38386625202c39,0x090a3b3338662520,0x203233662e627573\n"
".quad 0x25202c3039662509,0x386625202c383866,0x2e627573090a3b39,0x3966250920323366\n"
".quad 0x2c38356625202c31,0x090a3b3938662520,0x203233662e627573,0x25202c3239662509\n"
".quad 0x396625202c333866,0x2e646461090a3b30,0x3966250920323366,0x2c31396625202c33\n"
".quad 0x090a3b3239662520,0x203233662e646461,0x25202c3439662509,0x386625202c333966\n"
".quad 0x2e646461090a3b35,0x3966250920323366,0x2c34396625202c35,0x090a3b3036662520\n"
".quad 0x203233662e646461,0x25202c3639662509,0x396625202c383866,0x2e627573090a3b35\n"
".quad 0x3966250920323366,0x2c36396625202c37,0x090a3b3838662520,0x203233662e627573\n"
".quad 0x25202c3839662509,0x396625202c353966,0x2e646461090a3b37,0x3966250920323366\n"
".quad 0x2c36396625202c39,0x090a3b3839662520,0x203233662e766f6d,0x202c303031662509\n"
".quad 0x3030303830346630,0x2f092020203b3030,0x746573090a34202f,0x3233662e746c2e70\n"
".quad 0x25202c3870250920,0x316625202c393966,0x252140090a3b3030,0x0920617262203870\n"
".quad 0x34315f355f744c24,0x2f2f200a3b383333,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x323120656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x31315f355f744c24,0x766f6d090a303130,0x662509203233662e,0x346630202c313031\n"
".quad 0x3b30303430303036,0x38202f2f09202020,0x6c756d090a333931,0x662509203233662e\n"
".quad 0x336625202c323031,0x3130316625202c34,0x662e766f6d090a3b,0x3031662509203233\n"
".quad 0x3036346630202c33,0x20203b3030343030,0x393138202f2f0920,0x662e6c756d090a33\n"
".quad 0x3031662509203233,0x2c32336625202c34,0x0a3b333031662520,0x3233662e62757309\n"
".quad 0x2c35303166250920,0x202c323031662520,0x73090a3b34336625,0x09203233662e6275\n"
".quad 0x25202c3630316625,0x6625202c34303166,0x627573090a3b3233,0x662509203233662e\n"
".quad 0x316625202c373031,0x30316625202c3230,0x2e627573090a3b35,0x3166250920323366\n"
".quad 0x30316625202c3830,0x3630316625202c34,0x662e627573090a3b,0x3031662509203233\n"
".quad 0x2c34336625202c39,0x0a3b373031662520,0x3233662e62757309,0x2c30313166250920\n"
".quad 0x25202c3233662520,0x4c240a3b38303166,0x3a323639385f355f,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x2e090a3138322065,0x3209363109636f6c\n"
".quad 0x756d090a30093138,0x2509203233662e6c,0x6625202c31313166,0x32336625202c3533\n"
".quad 0x662e6c756d090a3b,0x3131662509203233,0x2c34336625202c32,0x090a3b3233662520\n"
".quad 0x662e6e722e616d66,0x3131662509203233,0x2c34336625202c33,0x25202c3333662520\n"
".quad 0x61090a3b31313166,0x09203233662e6464,0x25202c3431316625,0x6625202c32313166\n"
".quad 0x7573090a3b333131,0x2509203233662e62,0x6625202c35313166,0x316625202c343131\n"
".quad 0x6c756d090a3b3231,0x662509203233662e,0x316625202c363131,0x30316625202c3730\n"
".quad 0x2e627573090a3b38,0x3166250920323366,0x31316625202c3731,0x3231316625202c36\n"
".quad 0x662e627573090a3b,0x3131662509203233,0x3331316625202c38,0x3b3531316625202c\n"
".quad 0x33662e627573090a,0x3931316625092032,0x2c3431316625202c,0x0a3b353131662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x30316625202c3032,0x3031316625202c37\n"
".quad 0x3b3731316625202c,0x33662e627573090a,0x3132316625092032,0x2c3231316625202c\n"
".quad 0x0a3b393131662520,0x2e6e722e616d6609,0x3166250920323366,0x30316625202c3232\n"
".quad 0x3930316625202c38,0x3b3032316625202c,0x33662e646461090a,0x3332316625092032\n"
".quad 0x2c3831316625202c,0x0a3b313231662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x30316625202c3432,0x3031316625202c39,0x3b3232316625202c,0x33662e646461090a\n"
".quad 0x3532316625092032,0x2c3332316625202c,0x0a3b343231662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x35336625202c3632,0x202c33336625202c,0x090a3b3532316625\n"
".quad 0x203233662e646461,0x202c373231662509,0x25202c3431316625,0x73090a3b36323166\n"
".quad 0x09203233662e6275,0x25202c3832316625,0x6625202c37323166,0x7573090a3b343131\n"
".quad 0x2509203233662e62,0x6625202c39323166,0x316625202c363231,0x6f6c2e090a3b3832\n"
".quad 0x3238320936310963,0x2e646461090a3009,0x3166250920323366,0x32316625202c3033\n"
".quad 0x3732316625202c37,0x662e627573090a3b,0x3331662509203233,0x3033316625202c31\n"
".quad 0x3b3732316625202c,0x33662e627573090a,0x3233316625092032,0x2c3732316625202c\n"
".quad 0x0a3b313331662520,0x3233662e62757309,0x2c33333166250920,0x202c303331662520\n"
".quad 0x090a3b3133316625,0x203233662e627573,0x202c343331662509,0x25202c3732316625\n"
".quad 0x61090a3b33333166,0x09203233662e6464,0x25202c3533316625,0x6625202c32333166\n"
".quad 0x6461090a3b343331,0x2509203233662e64,0x6625202c36333166,0x316625202c353331\n"
".quad 0x646461090a3b3932,0x662509203233662e,0x316625202c373331,0x32316625202c3633\n"
".quad 0x2e646461090a3b39,0x3166250920323366,0x33316625202c3833,0x3733316625202c30\n"
".quad 0x662e627573090a3b,0x3331662509203233,0x3833316625202c39,0x3b3033316625202c\n"
".quad 0x33662e627573090a,0x3034316625092032,0x2c3733316625202c,0x0a3b393331662520\n"
".quad 0x363109636f6c2e09,0x090a300933383209,0x203233662e646461,0x202c313431662509\n"
".quad 0x25202c3833316625,0x7573090a3b313366,0x2509203233662e62,0x6625202c32343166\n"
".quad 0x316625202c313431,0x627573090a3b3833,0x662509203233662e,0x316625202c333431\n"
".quad 0x34316625202c3134,0x2e627573090a3b32,0x3166250920323366,0x31336625202c3434\n"
".quad 0x3b3234316625202c,0x33662e627573090a,0x3534316625092032,0x2c3833316625202c\n"
".quad 0x0a3b333431662520,0x3233662e64646109,0x2c36343166250920,0x202c343431662520\n"
".quad 0x090a3b3534316625,0x203233662e646461,0x202c373431662509,0x25202c3634316625\n"
".quad 0x61090a3b30343166,0x09203233662e6464,0x25202c3834316625,0x6625202c37343166\n"
".quad 0x646461090a3b3638,0x662509203233662e,0x316625202c393431,0x34316625202c3134\n"
".quad 0x2e766f6d090a3b38,0x3366250920323366,0x3934316625202c32,0x662e627573090a3b\n"
".quad 0x3531662509203233,0x3934316625202c30,0x3b3134316625202c,0x33662e627573090a\n"
".quad 0x2c33336625092032,0x202c383431662520,0x090a3b3035316625,0x09363109636f6c2e\n"
".quad 0x73090a3009363832,0x09203233662e6275,0x25202c3135316625,0x356625202c333866\n"
".quad 0x2e627573090a3b38,0x3166250920323366,0x35316625202c3235,0x3b33386625202c31\n"
".quad 0x33662e627573090a,0x3335316625092032,0x2c3135316625202c,0x0a3b323531662520\n"
".quad 0x3233662e64646109,0x2c34353166250920,0x202c323531662520,0x73090a3b38356625\n"
".quad 0x09203233662e6275,0x25202c3535316625,0x316625202c333866,0x627573090a3b3335\n"
".quad 0x662509203233662e,0x316625202c363531,0x35316625202c3535,0x2e646461090a3b34\n"
".quad 0x3166250920323366,0x35316625202c3735,0x3b35386625202c36,0x33662e627573090a\n"
".quad 0x3835316625092032,0x2c3735316625202c,0x090a3b3036662520,0x203233662e646461\n"
".quad 0x202c393531662509,0x25202c3135316625,0x61090a3b38353166,0x09203233662e6464\n"
".quad 0x25202c3036316625,0x6625202c39353166,0x627573090a3b3033,0x662509203233662e\n"
".quad 0x316625202c313631,0x35316625202c3036,0x2e627573090a3b39,0x3166250920323366\n"
".quad 0x36316625202c3236,0x3136316625202c30,0x662e627573090a3b,0x3631662509203233\n"
".quad 0x3935316625202c33,0x3b3236316625202c,0x33662e627573090a,0x3436316625092032\n"
".quad 0x202c30336625202c,0x090a3b3136316625,0x203233662e646461,0x202c353631662509\n"
".quad 0x25202c3336316625,0x73090a3b34363166,0x09203233662e6275,0x25202c3636316625\n"
".quad 0x6625202c39353166,0x7573090a3b313531,0x2509203233662e62,0x6625202c37363166\n"
".quad 0x316625202c383531,0x646461090a3b3636,0x662509203233662e,0x316625202c383631\n"
".quad 0x36316625202c3536,0x2e646461090a3b37,0x3166250920323366,0x37386625202c3936\n"
".quad 0x3b3836316625202c,0x33662e646461090a,0x3037316625092032,0x2c3036316625202c\n"
".quad 0x0a3b393631662520,0x3233662e766f6d09,0x202c343366250920,0x090a3b3037316625\n"
".quad 0x203233662e627573,0x202c313731662509,0x25202c3037316625,0x73090a3b30363166\n"
".quad 0x09203233662e6275,0x6625202c35336625,0x316625202c393631,0x6f6c2e090a3b3137\n"
".quad 0x3838320936310963,0x2e766f6d090a3009,0x3166250920323366,0x36346630202c3237\n"
".quad 0x203b303034303030,0x3138202f2f092020,0x2e6c756d090a3339,0x3166250920323366\n"
".quad 0x34316625202c3337,0x3237316625202c39,0x662e6c756d090a3b,0x3731662509203233\n"
".quad 0x3934316625202c34,0x0a3b33336625202c,0x3233662e6c756d09,0x2c35373166250920\n"
".quad 0x202c393431662520,0x090a3b3934316625,0x203233662e627573,0x202c363731662509\n"
".quad 0x25202c3337316625,0x66090a3b39343166,0x33662e6e722e616d,0x3737316625092032\n"
".quad 0x2c3934316625202c,0x25202c3333662520,0x73090a3b34373166,0x09203233662e6275\n"
".quad 0x25202c3830316625,0x6625202c33373166,0x6461090a3b363731,0x2509203233662e64\n"
".quad 0x6625202c38373166,0x316625202c353731,0x627573090a3b3737,0x662509203233662e\n"
".quad 0x316625202c303131,0x30316625202c3934,0x2e6c756d090a3b38,0x3166250920323366\n"
".quad 0x30316625202c3937,0x3830316625202c38,0x662e627573090a3b,0x3831662509203233\n"
".quad 0x3937316625202c30,0x3b3537316625202c,0x33662e627573090a,0x3138316625092032\n"
".quad 0x2c3837316625202c,0x0a3b353731662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x30316625202c3238,0x3031316625202c38,0x3b3038316625202c,0x33662e627573090a\n"
".quad 0x3338316625092032,0x2c3737316625202c,0x0a3b313831662520,0x3233662e62757309\n"
".quad 0x2c34383166250920,0x202c383731662520,0x090a3b3138316625,0x662e6e722e616d66\n"
".quad 0x3831662509203233,0x3830316625202c35,0x2c3031316625202c,0x0a3b323831662520\n"
".quad 0x3233662e62757309,0x2c36383166250920,0x202c353731662520,0x090a3b3438316625\n"
".quad 0x662e6e722e616d66,0x3831662509203233,0x3031316625202c37,0x2c3031316625202c\n"
".quad 0x0a3b353831662520,0x3233662e64646109,0x2c38383166250920,0x202c333831662520\n"
".quad 0x090a3b3638316625,0x203233662e646461,0x202c393831662509,0x25202c3738316625\n"
".quad 0x66090a3b38383166,0x33662e6e722e616d,0x3039316625092032,0x202c33336625202c\n"
".quad 0x6625202c33336625,0x6461090a3b393831,0x2509203233662e64,0x6625202c31393166\n"
".quad 0x316625202c383731,0x766f6d090a3b3039,0x662509203233662e,0x39316625202c3835\n"
".quad 0x2e627573090a3b31,0x3166250920323366,0x39316625202c3239,0x3837316625202c31\n"
".quad 0x662e627573090a3b,0x3036662509203233,0x2c3039316625202c,0x0a3b323931662520\n"
".quad 0x363109636f6c2e09,0x090a300939383209,0x203233662e766f6d,0x202c333931662509\n"
".quad 0x3430303036346630,0x2f092020203b3030,0x090a33393138202f,0x203233662e6c756d\n"
".quad 0x202c343931662509,0x25202c3037316625,0x6d090a3b33393166,0x09203233662e6c75\n"
".quad 0x25202c3539316625,0x6625202c30373166,0x6c756d090a3b3533,0x662509203233662e\n"
".quad 0x316625202c363931,0x37316625202c3037,0x2e627573090a3b30,0x3166250920323366\n"
".quad 0x39316625202c3739,0x3037316625202c34,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c38393166,0x336625202c303731,0x3539316625202c35,0x662e627573090a3b\n"
".quad 0x3031662509203233,0x3439316625202c37,0x3b3739316625202c,0x33662e646461090a\n"
".quad 0x3939316625092032,0x2c3639316625202c,0x0a3b383931662520,0x3233662e62757309\n"
".quad 0x2c39303166250920,0x202c303731662520,0x090a3b3730316625,0x203233662e6c756d\n"
".quad 0x202c303032662509,0x25202c3730316625,0x73090a3b37303166,0x09203233662e6275\n"
".quad 0x25202c3130326625,0x6625202c30303266,0x7573090a3b363931,0x2509203233662e62\n"
".quad 0x6625202c32303266,0x316625202c393931,0x616d66090a3b3639,0x203233662e6e722e\n"
".quad 0x202c333032662509,0x25202c3730316625,0x6625202c39303166,0x7573090a3b313032\n"
".quad 0x2509203233662e62,0x6625202c34303266,0x326625202c383931,0x627573090a3b3230\n"
".quad 0x662509203233662e,0x316625202c353032,0x30326625202c3939,0x2e616d66090a3b32\n"
".quad 0x09203233662e6e72,0x25202c3630326625,0x6625202c37303166,0x326625202c393031\n"
".quad 0x627573090a3b3330,0x662509203233662e,0x316625202c373032,0x30326625202c3639\n"
".quad 0x2e616d66090a3b35,0x09203233662e6e72,0x25202c3830326625,0x6625202c39303166\n"
".quad 0x326625202c393031,0x646461090a3b3630,0x662509203233662e,0x326625202c393032\n"
".quad 0x30326625202c3430,0x2e646461090a3b37,0x3266250920323366,0x30326625202c3031\n"
".quad 0x3930326625202c38,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c31313266\n"
".quad 0x35336625202c3533,0x3b3031326625202c,0x33662e646461090a,0x3231326625092032\n"
".quad 0x2c3939316625202c,0x0a3b313132662520,0x3233662e766f6d09,0x202c333866250920\n"
".quad 0x090a3b3231326625,0x203233662e627573,0x202c333132662509,0x25202c3231326625\n"
".quad 0x73090a3b39393166,0x09203233662e6275,0x6625202c35386625,0x326625202c313132\n"
".quad 0x6f6c2e090a3b3331,0x3039320936310963,0x2e646461090a3009,0x3266250920323366\n"
".quad 0x39316625202c3431,0x3231326625202c31,0x662e627573090a3b,0x3132662509203233\n"
".quad 0x3431326625202c35,0x3b3231326625202c,0x33662e627573090a,0x3631326625092032\n"
".quad 0x2c3139316625202c,0x0a3b353132662520,0x3233662e62757309,0x2c37313266250920\n"
".quad 0x202c343132662520,0x090a3b3531326625,0x203233662e627573,0x202c383132662509\n"
".quad 0x25202c3231326625,0x61090a3b37313266,0x09203233662e6464,0x25202c3931326625\n"
".quad 0x6625202c36313266,0x6461090a3b383132,0x2509203233662e64,0x6625202c30323266\n"
".quad 0x31326625202c3538,0x2e646461090a3b39,0x3266250920323366,0x30366625202c3132\n"
".quad 0x3b3032326625202c,0x33662e646461090a,0x3232326625092032,0x2c3431326625202c\n"
".quad 0x0a3b313232662520,0x3233662e62757309,0x2c33323266250920,0x202c323232662520\n"
".quad 0x090a3b3431326625,0x203233662e627573,0x202c343232662509,0x25202c3132326625\n"
".quad 0x2e090a3b33323266,0x3209363109636f6c,0x7573090a30093038,0x2509203233732e62\n"
".quad 0x337225202c363372,0x6d090a3b31202c36,0x09203233752e766f,0x3b30202c38337225\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x36337225202c3970,0x0a3b38337225202c\n"
".quad 0x7262203970254009,0x355f744c24092061,0x0a3b38333334315f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31383220\n"
".quad 0x6c6562616c206461,0x5f355f4c24206465,0x6461090a32363938,0x2509203233662e64\n"
".quad 0x6625202c35323266,0x326625202c343232,0x766f6d090a3b3232,0x662509203233662e\n"
".quad 0x346630202c363232,0x3b30303030303830,0x34202f2f09202020,0x6c2e70746573090a\n"
".quad 0x2509203233662e74,0x326625202c303170,0x32326625202c3532,0x31702540090a3b36\n"
".quad 0x2409206172622030,0x323639385f355f4c,0x5f355f744c240a3b,0x240a3a3833333431\n"
".quad 0x383132395f355f4c,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35323120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313031315f355f,0x3109636f6c2e090a,0x0a30093434310937,0x3233732e766f6d09\n"
".quad 0x202c393372250920,0x70746573090a3b30,0x203233732e74672e,0x25202c3131702509\n"
".quad 0x337225202c363372,0x2e627573090a3b39,0x3472250920323373,0x2c35337225202c30\n"
".quad 0x090a3b3633722520,0x203233732e766f6d,0x30202c3134722509,0x2e706c6573090a3b\n"
".quad 0x3472250920323373,0x2c30347225202c32,0x25202c3134722520,0x6f6d090a3b313170\n"
".quad 0x2509203233752e76,0x0a3b30202c333472,0x71652e7074657309,0x702509203233732e\n"
".quad 0x32347225202c3231,0x0a3b33347225202c,0x6220323170254009,0x5f744c2409206172\n"
".quad 0x3b36343532315f35,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3532312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30313031315f35,0x373109636f6c2e09,0x090a300931353109,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x635f5f5b202c3434,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365033316d735f30,0x6969347261686375,0x6666666666666669\n"
".quad 0x5f62696969695f53,0x6f6974616d696e61,0x3b5d656d6172466e,0x33732e646461090a\n"
".quad 0x2c35347225092032,0x25202c3434722520,0x646c090a3b323472,0x752e6d617261702e\n"
".quad 0x2c36347225092038,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x6c6f635f62696969,0x0a3b5d302b73726f,0x2e6f6c2e6c756d09,0x3472250920323373\n"
".quad 0x2c35347225202c37,0x090a3b3634722520,0x752e38752e747663,0x3834722509203233\n"
".quad 0x0a3b37347225202c,0x373109636f6c2e09,0x090a300932353109,0x6d617261702e646c\n"
".quad 0x347225092038752e,0x75635f5f5b202c39,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x305344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x635f62696969695f,0x5d312b73726f6c6f,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x347225202c303572,0x3b39347225202c35,0x38752e747663090a,0x722509203233752e\n"
".quad 0x30357225202c3135,0x09636f6c2e090a3b,0x3009333531093731,0x7261702e646c090a\n"
".quad 0x25092038752e6d61,0x5f5f5b202c323572,0x6d72617061647563,0x6e614d38315a5f5f\n"
".quad 0x44746f72626c6564,0x5033316d735f3053,0x6934726168637536,0x6666666666666969\n"
".quad 0x62696969695f5366,0x2b73726f6c6f635f,0x6c756d090a3b5d32,0x203233732e6f6c2e\n"
".quad 0x25202c3335722509,0x357225202c353472,0x2e747663090a3b32,0x09203233752e3875\n"
".quad 0x7225202c34357225,0x617262090a3b3335,0x4c240920696e752e,0x393232315f355f74\n"
".quad 0x355f744c240a3b30,0x0a3a36343532315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35323120,0x6c6562616c206461\n"
".quad 0x355f744c24206465,0x090a30313031315f,0x09373109636f6c2e,0x6d090a3009373531\n"
".quad 0x09203233752e766f,0x3b30202c34357225,0x33752e766f6d090a,0x2c31357225092032\n"
".quad 0x766f6d090a3b3020,0x722509203233752e,0x240a3b30202c3834,0x3232315f355f744c\n"
".quad 0x3c2f2f200a3a3039,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3031315f355f744c\n"
".quad 0x2e6c756d090a3031,0x09203233732e6f6c,0x7225202c35357225,0x36327225202c3831\n"
".quad 0x732e646461090a3b,0x3635722509203233,0x202c35357225202c,0x6d090a3b35327225\n"
".quad 0x33752e6f6c2e6c75,0x2c37357225092032,0x34202c3635722520,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x7225202c32647225,0x2e646c090a3b3735,0x36752e6d61726170\n"
".quad 0x2c33647225092034,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x7473645f62696969,0x2e646461090a3b5d,0x6472250920343675,0x2c32647225202c34\n"
".quad 0x090a3b3364722520,0x6d617261702e646c,0x722509203233732e,0x635f5f5b202c3835\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x0a3b5d656d617266\n"
".quad 0x3233752e766f6d09,0x202c393572250920,0x70746573090a3b30,0x203233732e656e2e\n"
".quad 0x25202c3331702509,0x357225202c383572,0x31702540090a3b39,0x2409206172622033\n"
".quad 0x3033315f355f744c,0x3c2f2f200a3b3835,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35323120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3031315f355f744c,0x636f6c2e090a3031,0x0934363109373109,0x752e766f6d090a30\n"
".quad 0x3036722509203233,0x7473090a3b30202c,0x2e6c61626f6c672e,0x5b092038752e3476\n"
".quad 0x2c5d302b34647225,0x252c383472257b20,0x343572252c313572,0x0a3b7d303672252c\n"
".quad 0x696e752e61726209,0x5f355f744c240920,0x240a3b3230383231,0x3033315f355f744c\n"
".quad 0x3c2f2f200a3a3835,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3031315f355f744c\n"
".quad 0x636f6c2e090a3031,0x0938363109373109,0x732e646461090a30,0x3136722509203233\n"
".quad 0x202c38357225202c,0x2e726873090a3b31,0x3672250920323373,0x2c31367225202c32\n"
".quad 0x6f6d090a3b313320,0x2509203233732e76,0x0a3b31202c333672,0x3233622e646e6109\n"
".quad 0x202c343672250920,0x7225202c32367225,0x646461090a3b3336,0x722509203233732e\n"
".quad 0x34367225202c3536,0x0a3b31367225202c,0x3233732e72687309,0x202c363672250920\n"
".quad 0x3b31202c35367225,0x6f6c672e646c090a,0x752e34762e6c6162,0x373672257b092038\n"
".quad 0x72252c383672252c,0x5b202c7d5f2c3936,0x3b5d302b34647225,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x38357225202c3037,0x0a3b37367225202c,0x3233732e64646109\n"
".quad 0x202c313772250920,0x7225202c38347225,0x646461090a3b3037,0x722509203233732e\n"
".quad 0x36367225202c3237,0x0a3b31377225202c,0x3233732e76696409,0x202c333772250920\n"
".quad 0x7225202c32377225,0x6f6c2e090a3b3136,0x3936310937310963,0x2e6c756d090a3009\n"
".quad 0x09203233732e6f6c,0x7225202c34377225,0x38367225202c3835,0x732e646461090a3b\n"
".quad 0x3537722509203233,0x202c31357225202c,0x61090a3b34377225,0x09203233732e6464\n"
".quad 0x7225202c36377225,0x35377225202c3636,0x732e766964090a3b,0x3737722509203233\n"
".quad 0x202c36377225202c,0x73090a3b31367225,0x6c61626f6c672e74,0x092038752e32762e\n"
".quad 0x5d302b346472255b,0x2c333772257b202c,0x090a3b7d37377225,0x09373109636f6c2e\n"
".quad 0x6d090a3009303731,0x33732e6f6c2e6c75,0x2c38377225092032,0x25202c3835722520\n"
".quad 0x6461090a3b393672,0x2509203233732e64,0x357225202c393772,0x3b38377225202c34\n"
".quad 0x33732e646461090a,0x2c30387225092032,0x25202c3636722520,0x6964090a3b393772\n"
".quad 0x2509203233732e76,0x387225202c313872,0x3b31367225202c30,0x6f6c672e7473090a\n"
".quad 0x092038752e6c6162,0x5d322b346472255b,0x0a3b31387225202c,0x32315f355f744c24\n"
".quad 0x744c240a3a323038,0x36363231315f355f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35323120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30313031315f355f,0x3109636f6c2e090a,0x0a30093337310937\n"
".quad 0x6e79732e72616209,0x6d090a3b30092063,0x09203233752e766f,0x3b30202c32387225\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x377225202c343170,0x0a3b32387225202c\n"
".quad 0x6220343170254009,0x5f744c2409206172,0x3b34313333315f35,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3532312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a30313031315f35,0x373109636f6c2e09\n"
".quad 0x090a300936373109,0x203436752e766f6d,0x62202c3564722509,0x6e756f436b636f6c\n"
".quad 0x6f6d090a3b726574,0x2509203233752e76,0x0a3b31202c333872,0x6c672e6d6f746109\n"
".quad 0x6464612e6c61626f,0x722509203233752e,0x6472255b202c3438,0x33387225202c5d35\n"
".quad 0x732e766f6d090a3b,0x3538722509203233,0x0a3b34387225202c,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38353336335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x5d7865646e496b63,0x0a3b35387225202c\n"
".quad 0x373109636f6c2e09,0x090a300937373109,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3638,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x7464695764697267,0x6d6572090a3b5d68,0x722509203233752e,0x35387225202c3738\n"
".quad 0x0a3b36387225202c,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f39353336335f72,0x635f6e6f6e5f3234,0x6f6c625f74736e6f\n"
".quad 0x7225202c5d586b63,0x6f6c2e090a3b3738,0x3837310937310963,0x2e766964090a3009\n"
".quad 0x3872250920323375,0x2c35387225202c38,0x090a3b3638722520,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f,0x355f39353336335f\n"
".quad 0x6f635f6e6f6e5f30,0x636f6c625f74736e,0x387225202c5d596b,0x355f744c240a3b38\n"
".quad 0x0a3a34313333315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35323120,0x6c6562616c206461,0x355f744c24206465\n"
".quad 0x090a30313031315f,0x09373109636f6c2e,0x62090a3009303831,0x20636e79732e7261\n"
".quad 0x2e646c090a3b3009,0x752e646572616873,0x3938722509203233,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x353336335f726176,0x6e6f6e5f32345f38,0x625f74736e6f635f\n"
".quad 0x65646e496b636f6c,0x746573090a3b5d78,0x3233752e746c2e70,0x202c353170250920\n"
".quad 0x7225202c39387225,0x702540090a3b3531,0x0920617262203531,0x31315f355f744c24\n"
".quad 0x744c240a3b303130,0x38393430315f355f,0x09636f6c2e090a3a,0x3009333831093731\n"
".quad 0x0a3b74697865090a,0x5f646e6557444c24,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x3a62696969695f53\n"
".quad 0x5f202f2f207d090a,0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x0a0a62696969695f,0x207972746e652e09\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31,0x6969347261686375\n"
".quad 0x6666666666666669,0x2062696969695f53,0x7261702e09090a28,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474\n"
".quad 0x7261686375365033,0x6666666669696934,0x6969695f53666666,0x0a2c7473645f6269\n"
".quad 0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563,0x6e614d38315a5f5f\n"
".quad 0x44746f72626c6564,0x5033316d735f3153,0x6934726168637536,0x6666666666666969\n"
".quad 0x62696969695f5366,0x2c576567616d695f,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x486567616d695f62\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x636e7572635f6269,0x61702e09090a2c68,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x66664f785f626969\n"
".quad 0x61702e09090a2c30,0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x66664f785f626969,0x61702e09090a2c31,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x66664f795f626969\n"
".quad 0x61702e09090a2c30,0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x66664f795f626969,0x61702e09090a2c31,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x2c504a785f626969\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x614d38315a5f5f6d\n"
".quad 0x746f72626c65646e,0x33316d735f315344,0x3472616863753650,0x6666666666696969\n"
".quad 0x696969695f536666,0x090a2c504a795f62,0x206d617261702e09,0x635f5f203233662e\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x090a2c656c616373\n"
".quad 0x206d617261702e09,0x34206e67696c612e,0x635f5f2038622e20,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x345b73726f6c6f63,0x61702e09090a2c5d\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x6d735f315344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x6d6172665f626969,0x61702e09090a2c65,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x6d696e615f626969,0x6172466e6f697461\n"
".quad 0x702e09090a2c656d,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x6972675f62696969,0x0a2c687464695764,0x6d617261702e0909\n"
".quad 0x5f5f203233732e20,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5033316d735f3153,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x636f6c426d756e5f,0x702e09090a2c736b,0x38732e206d617261,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x294a73695f626969,0x65722e090a7b090a\n"
".quad 0x25203233752e2067,0x0a3b3e3837313c72,0x752e206765722e09,0x313c647225203436\n"
".quad 0x65722e090a3b3e31,0x25203233662e2067,0x0a3b3e3832323c66,0x702e206765722e09\n"
".quad 0x323c702520646572,0x68732e090a3b3e31,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x37313536335f7261,0x5f6e6f6e5f32345f,0x6c625f74736e6f63\n"
".quad 0x7865646e496b636f,0x726168732e090a3b,0x203233752e206465,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f38313536335f,0x6f635f6e6f6e5f32,0x636f6c625f74736e\n"
".quad 0x68732e090a3b586b,0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f\n"
".quad 0x38313536335f7261,0x5f6e6f6e5f30355f,0x6c625f74736e6f63,0x2e090a3b596b636f\n"
".quad 0x3209373109636f6c,0x444c240a30093337,0x5f5f6e6967656257,0x65646e614d38315a\n"
".quad 0x315344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x0a3a62696969695f,0x3233752e766f6d09,0x25202c3172250920,0x090a3b782e646974\n"
".quad 0x203233752e766f6d,0x3b30202c32722509,0x652e70746573090a,0x2509203233752e71\n"
".quad 0x2c317225202c3170,0x6d090a3b32722520,0x09203233752e766f,0x697425202c337225\n"
".quad 0x6f6d090a3b792e64,0x2509203233752e76,0x090a3b30202c3472,0x2e71652e70746573\n"
".quad 0x3270250920323375,0x25202c337225202c,0x6c6573090a3b3472,0x2509203233732e70\n"
".quad 0x30202c31202c3572,0x090a3b317025202c,0x3233732e706c6573,0x31202c3672250920\n"
".quad 0x327025202c30202c,0x622e646e61090a3b,0x2c37722509203233,0x7225202c35722520\n"
".quad 0x2e766f6d090a3b36,0x3872250920323375,0x6573090a3b30202c,0x33732e71652e7074\n"
".quad 0x202c337025092032,0x387225202c377225,0x2033702540090a3b,0x744c240920617262\n"
".quad 0x36363637315f365f,0x09636f6c2e090a3b,0x3009313832093731,0x36752e766f6d090a\n"
".quad 0x2c31647225092034,0x6f436b636f6c6220,0x090a3b7265746e75,0x203233752e766f6d\n"
".quad 0x3b31202c39722509,0x672e6d6f7461090a,0x64612e6c61626f6c,0x2509203233752e64\n"
".quad 0x72255b202c303172,0x397225202c5d3164,0x732e766f6d090a3b,0x3131722509203233\n"
".quad 0x0a3b30317225202c,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f37313536335f72,0x635f6e6f6e5f3234,0x6f6c625f74736e6f\n"
".quad 0x5d7865646e496b63,0x0a3b31317225202c,0x373109636f6c2e09,0x090a300932383209\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x635f5f5b202c3231,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x7464695764697267,0x6d6572090a3b5d68\n"
".quad 0x722509203233752e,0x31317225202c3331,0x0a3b32317225202c,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38313536335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x7225202c5d586b63,0x6f6c2e090a3b3331\n"
".quad 0x3338320937310963,0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34\n"
".quad 0x090a3b3231722520,0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x355f38313536335f,0x6f635f6e6f6e5f30,0x636f6c625f74736e\n"
".quad 0x317225202c5d596b,0x365f744c240a3b34,0x0a3a36363637315f,0x373109636f6c2e09\n"
".quad 0x090a300936383209,0x636e79732e726162,0x646c090a3b300920,0x752e6d617261702e\n"
".quad 0x3531722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f315344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x756e5f6269696969,0x5d736b636f6c426d,0x68732e646c090a3b,0x3233752e64657261\n"
".quad 0x202c363172250920,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f37313536335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x5d7865646e496b63,0x2e70746573090a3b\n"
".quad 0x09203233752e6567,0x317225202c347025,0x3b35317225202c36,0x622034702540090a\n"
".quad 0x5f744c2409206172,0x3b38373138315f36,0x7261702e646c090a,0x09203233732e6d61\n"
".quad 0x5f5b202c37317225,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x33316d735f315344,0x3472616863753650,0x6666666666696969,0x696969695f536666\n"
".quad 0x486567616d695f62,0x702e646c090a3b5d,0x3233732e6d617261,0x202c383172250920\n"
".quad 0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x67616d695f626969\n"
".quad 0x6f6d090a3b5d5765,0x2509203233752e76,0x746e25202c393172,0x6d090a3b792e6469\n"
".quad 0x09203233752e766f,0x6e25202c30327225,0x240a3b782e646974,0x3638315f365f744c\n"
".quad 0x3c2f2f200a3a3039,0x6f4c203e706f6f6c,0x2079646f6220706f,0x36383220656e696c\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x5b202c3132722509,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f38313536335f,0x6f635f6e6f6e5f32,0x636f6c625f74736e\n"
".quad 0x756d090a3b5d586b,0x3233752e6f6c2e6c,0x202c323272250920,0x7225202c31327225\n"
".quad 0x2e646c090a3b3032,0x752e646572616873,0x3332722509203233,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x313536335f726176,0x6e6f6e5f30355f38,0x625f74736e6f635f\n"
".quad 0x0a3b5d596b636f6c,0x2e6f6c2e6c756d09,0x3272250920323375,0x2c33327225202c34\n"
".quad 0x090a3b3931722520,0x203233752e646461,0x25202c3532722509,0x317225202c323272\n"
".quad 0x752e646461090a3b,0x3632722509203233,0x202c34327225202c,0x6573090a3b337225\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x37317225202c3732,0x0a3b36327225202c\n"
".quad 0x3233732e67656e09,0x202c383272250920,0x73090a3b37327225,0x33752e74672e7465\n"
".quad 0x2509203233732e32,0x317225202c393272,0x3b35327225202c38,0x33732e67656e090a\n"
".quad 0x2c30337225092032,0x090a3b3932722520,0x203233622e646e61,0x25202c3133722509\n"
".quad 0x337225202c383272,0x2e766f6d090a3b30,0x3372250920323375,0x73090a3b30202c32\n"
".quad 0x732e71652e707465,0x2c35702509203233,0x25202c3133722520,0x2540090a3b323372\n"
".quad 0x0920617262203570,0x31325f365f744c24,0x2f2f200a3b363035,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x383220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x38315f365f744c24,0x6f6c2e090a303936,0x3030330937310963\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c33337225,0x36327225202c3831\n"
".quad 0x732e646461090a3b,0x3433722509203233,0x202c33337225202c,0x6c090a3b35327225\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x75635f5f5b202c32,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x315344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x645f62696969695f,0x756d090a3b5d7473,0x3233752e6f6c2e6c\n"
".quad 0x202c353372250920,0x3b34202c34337225,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x337225202c336472,0x2e646461090a3b35,0x6472250920343675,0x2c33647225202c34\n"
".quad 0x090a3b3264722520,0x61626f6c672e646c,0x2038752e34762e6c,0x252c363372257b09\n"
".quad 0x383372252c373372,0x72255b202c7d5f2c,0x090a3b5d302b3464,0x203233752e766f6d\n"
".quad 0x30202c3933722509,0x2e70746573090a3b,0x09203233732e656c,0x327225202c367025\n"
".quad 0x3b39337225202c35,0x622036702540090a,0x5f744c2409206172,0x3b34313739315f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3638322065,0x6562616c20646165,0x5f744c242064656c,0x0a30393638315f36\n"
".quad 0x626f6c672e646c09,0x38752e34762e6c61,0x2c303472257b0920,0x3472252c31347225\n"
".quad 0x255b202c7d5f2c32,0x3b5d342d2b346472,0x3109636f6c2e090a,0x0a30093530330937\n"
".quad 0x3233732e62757309,0x202c333472250920,0x7225202c32347225,0x736261090a3b3833\n"
".quad 0x722509203233732e,0x33347225202c3434,0x732e766f6d090a3b,0x3534722509203233\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x347225202c363472\n"
".quad 0x3b35347225202c34,0x33732e67656e090a,0x2c37347225092032,0x090a3b3634722520\n"
".quad 0x203233732e627573,0x25202c3834722509,0x337225202c303472,0x2e736261090a3b36\n"
".quad 0x3472250920323373,0x3b38347225202c39,0x33732e766f6d090a,0x2c30357225092032\n"
".quad 0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e,0x39347225202c3135\n"
".quad 0x0a3b30357225202c,0x3233732e67656e09,0x202c323572250920,0x73090a3b31357225\n"
".quad 0x09203233732e6275,0x7225202c33357225,0x37337225202c3134,0x732e736261090a3b\n"
".quad 0x3435722509203233,0x0a3b33357225202c,0x3233732e766f6d09,0x202c353572250920\n"
".quad 0x746573090a3b3031,0x2e3233752e74672e,0x3572250920323373,0x2c34357225202c36\n"
".quad 0x090a3b3535722520,0x203233732e67656e,0x25202c3735722509,0x726f090a3b363572\n"
".quad 0x722509203233622e,0x32357225202c3835,0x0a3b37357225202c,0x203233622e726f09\n"
".quad 0x25202c3935722509,0x357225202c373472,0x2e617262090a3b38,0x744c240920696e75\n"
".quad 0x38353439315f365f,0x5f365f744c240a3b,0x200a3a3431373931,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832\n"
".quad 0x656c6562616c2064,0x5f365f744c242064,0x6d090a3039363831,0x09203233732e766f\n"
".quad 0x3b30202c39357225,0x315f365f744c240a,0x2f200a3a38353439,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3638\n"
".quad 0x64656c6562616c20,0x315f365f744c2420,0x6461090a30393638,0x2509203233732e64\n"
".quad 0x327225202c303672,0x73090a3b31202c35,0x732e656c2e707465,0x2c37702509203233\n"
".quad 0x25202c3831722520,0x2540090a3b303672,0x0920617262203770,0x39315f365f744c24\n"
".quad 0x2f2f200a3b303739,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x383220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x38315f365f744c24\n"
".quad 0x2e646c090a303936,0x762e6c61626f6c67,0x257b092038752e34,0x323672252c313672\n"
".quad 0x7d5f2c333672252c,0x2b346472255b202c,0x6f6c2e090a3b5d34,0x3730330937310963\n"
".quad 0x2e627573090a3009,0x3672250920323373,0x2c33367225202c34,0x090a3b3833722520\n"
".quad 0x203233732e736261,0x25202c3536722509,0x6f6d090a3b343672,0x2509203233732e76\n"
".quad 0x3b3031202c363672,0x74672e746573090a,0x3233732e3233752e,0x202c373672250920\n"
".quad 0x7225202c35367225,0x67656e090a3b3636,0x722509203233732e,0x37367225202c3836\n"
".quad 0x732e627573090a3b,0x3936722509203233,0x202c31367225202c,0x61090a3b36337225\n"
".quad 0x09203233732e7362,0x7225202c30377225,0x766f6d090a3b3936,0x722509203233732e\n"
".quad 0x0a3b3031202c3137,0x2e74672e74657309,0x203233732e323375,0x25202c3237722509\n"
".quad 0x377225202c303772,0x2e67656e090a3b31,0x3772250920323373,0x3b32377225202c33\n"
".quad 0x33732e627573090a,0x2c34377225092032,0x25202c3236722520,0x6261090a3b373372\n"
".quad 0x2509203233732e73,0x377225202c353772,0x2e766f6d090a3b34,0x3772250920323373\n"
".quad 0x090a3b3031202c36,0x752e74672e746573,0x09203233732e3233,0x7225202c37377225\n"
".quad 0x36377225202c3537,0x732e67656e090a3b,0x3837722509203233,0x0a3b37377225202c\n"
".quad 0x203233622e726f09,0x25202c3937722509,0x377225202c333772,0x622e726f090a3b38\n"
".quad 0x3038722509203233,0x202c38367225202c,0x61090a3b39377225,0x09203233732e6464\n"
".quad 0x7225202c39357225,0x30387225202c3935,0x5f365f744c240a3b,0x200a3a3037393931\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363832,0x656c6562616c2064,0x5f365f744c242064,0x6d090a3039363831\n"
".quad 0x09203233752e766f,0x3b30202c31387225,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x36327225202c3870,0x0a3b31387225202c,0x7262203870254009,0x365f744c24092061\n"
".quad 0x0a3b32383430325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36383220,0x6c6562616c206461,0x365f744c24206465\n"
".quad 0x090a30393638315f,0x09373109636f6c2e,0x73090a3009393033,0x09203233732e6275\n"
".quad 0x7225202c32387225,0x38317225202c3433,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x387225202c333872,0x63090a3b34202c32,0x752e3436752e7476,0x3564722509203233\n"
".quad 0x0a3b33387225202c,0x3436752e64646109,0x202c366472250920,0x7225202c35647225\n"
".quad 0x2e646c090a3b3264,0x762e6c61626f6c67,0x257b092038752e34,0x353872252c343872\n"
".quad 0x7d5f2c363872252c,0x2b366472255b202c,0x627573090a3b5d30,0x722509203233732e\n"
".quad 0x36387225202c3738,0x0a3b38337225202c,0x3233732e73626109,0x202c383872250920\n"
".quad 0x6d090a3b37387225,0x09203233732e766f,0x3031202c39387225,0x672e746573090a3b\n"
".quad 0x33732e3233752e74,0x2c30397225092032,0x25202c3838722520,0x656e090a3b393872\n"
".quad 0x2509203233732e67,0x397225202c313972,0x2e627573090a3b30,0x3972250920323373\n"
".quad 0x2c34387225202c32,0x090a3b3633722520,0x203233732e736261,0x25202c3339722509\n"
".quad 0x6f6d090a3b323972,0x2509203233732e76,0x3b3031202c343972,0x74672e746573090a\n"
".quad 0x3233732e3233752e,0x202c353972250920,0x7225202c33397225,0x67656e090a3b3439\n"
".quad 0x722509203233732e,0x35397225202c3639,0x732e627573090a3b,0x3739722509203233\n"
".quad 0x202c35387225202c,0x61090a3b37337225,0x09203233732e7362,0x7225202c38397225\n"
".quad 0x766f6d090a3b3739,0x722509203233732e,0x0a3b3031202c3939,0x2e74672e74657309\n"
".quad 0x203233732e323375,0x202c303031722509,0x7225202c38397225,0x67656e090a3b3939\n"
".quad 0x722509203233732e,0x317225202c313031,0x2e726f090a3b3030,0x3172250920323362\n"
".quad 0x36397225202c3230,0x3b3130317225202c,0x3233622e726f090a,0x2c33303172250920\n"
".quad 0x25202c3139722520,0x61090a3b32303172,0x09203233732e6464,0x7225202c39357225\n"
".quad 0x30317225202c3935,0x365f744c240a3b33,0x0a3a32383430325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36383220\n"
".quad 0x6c6562616c206461,0x365f744c24206465,0x090a30393638315f,0x203233732e646461\n"
".quad 0x202c343031722509,0x3b31202c36327225,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x37317225202c3970,0x3b3430317225202c,0x622039702540090a,0x5f744c2409206172\n"
".quad 0x3b34393930325f36,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3638322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30393638315f36,0x373109636f6c2e09,0x090a300931313309,0x203233732e646461\n"
".quad 0x202c353031722509,0x7225202c34337225,0x6c756d090a3b3831,0x203233752e6f6c2e\n"
".quad 0x202c363031722509,0x34202c3530317225,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x7225202c37647225,0x6461090a3b363031,0x2509203436752e64,0x647225202c386472\n"
".quad 0x3b32647225202c37,0x6f6c672e646c090a,0x752e34762e6c6162,0x303172257b092038\n"
".quad 0x2c38303172252c37,0x7d5f2c3930317225,0x2b386472255b202c,0x627573090a3b5d30\n"
".quad 0x722509203233732e,0x317225202c303131,0x38337225202c3930,0x732e736261090a3b\n"
".quad 0x3131722509203233,0x3031317225202c31,0x732e766f6d090a3b,0x3131722509203233\n"
".quad 0x090a3b3031202c32,0x752e74672e746573,0x09203233732e3233,0x25202c3331317225\n"
".quad 0x7225202c31313172,0x656e090a3b323131,0x2509203233732e67,0x7225202c34313172\n"
".quad 0x7573090a3b333131,0x2509203233732e62,0x7225202c35313172,0x337225202c373031\n"
".quad 0x2e736261090a3b36,0x3172250920323373,0x31317225202c3631,0x2e766f6d090a3b35\n"
".quad 0x3172250920323373,0x0a3b3031202c3731,0x2e74672e74657309,0x203233732e323375\n"
".quad 0x202c383131722509,0x25202c3631317225,0x6e090a3b37313172,0x09203233732e6765\n"
".quad 0x25202c3931317225,0x73090a3b38313172,0x09203233732e6275,0x25202c3032317225\n"
".quad 0x7225202c38303172,0x736261090a3b3733,0x722509203233732e,0x317225202c313231\n"
".quad 0x766f6d090a3b3032,0x722509203233732e,0x3b3031202c323231,0x74672e746573090a\n"
".quad 0x3233732e3233752e,0x2c33323172250920,0x202c313231722520,0x090a3b3232317225\n"
".quad 0x203233732e67656e,0x202c343231722509,0x090a3b3332317225,0x09203233622e726f\n"
".quad 0x25202c3532317225,0x7225202c39313172,0x726f090a3b343231,0x722509203233622e\n"
".quad 0x317225202c363231,0x32317225202c3431,0x2e646461090a3b35,0x3572250920323373\n"
".quad 0x2c39357225202c39,0x0a3b363231722520,0x30325f365f744c24,0x2f2f200a3a343939\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383220656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x38315f365f744c24,0x766f6d090a303936\n"
".quad 0x722509203233752e,0x0a3b30202c373231,0x71652e7074657309,0x702509203233732e\n"
".quad 0x39357225202c3031,0x3b3732317225202c,0x203031702540090a,0x744c240920617262\n"
".quad 0x36303531325f365f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36383220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30393638315f365f,0x3109636f6c2e090a,0x0a30093831330937,0x2e6e722e74766309\n"
".quad 0x203233732e323366,0x7225202c31662509,0x2e646c090a3b3532,0x33662e6d61726170\n"
".quad 0x202c326625092032,0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x6d735f315344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x6c6163735f626969,0x6c756d090a3b5d65,0x662509203233662e,0x202c316625202c33\n"
".quad 0x646c090a3b326625,0x662e6d617261702e,0x2c34662509203233,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f315344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x664f785f62696969,0x6461090a3b5d3066\n"
".quad 0x2509203233662e64,0x2c336625202c3566,0x73090a3b34662520,0x09203233662e6275\n"
".quad 0x356625202c366625,0x090a3b336625202c,0x203233662e627573,0x6625202c37662509\n"
".quad 0x0a3b366625202c34,0x3233662e62757309,0x25202c3866250920,0x3b366625202c3566\n"
".quad 0x33662e627573090a,0x202c396625092032,0x386625202c336625,0x662e646461090a3b\n"
".quad 0x3031662509203233,0x25202c376625202c,0x2e646c090a3b3966,0x33662e6d61726170\n"
".quad 0x2c31316625092032,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f315344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x664f785f62696969,0x6461090a3b5d3166,0x2509203233662e64,0x316625202c323166\n"
".quad 0x3b30316625202c31,0x33662e646461090a,0x2c33316625092032,0x6625202c35662520\n"
".quad 0x627573090a3b3231,0x662509203233662e,0x33316625202c3431,0x090a3b356625202c\n"
".quad 0x203233662e627573,0x25202c3531662509,0x316625202c323166,0x636f6c2e090a3b34\n"
".quad 0x0939313309373109,0x722e747663090a30,0x33732e3233662e6e,0x2c36316625092032\n"
".quad 0x090a3b3632722520,0x203233662e6c756d,0x25202c3731662509,0x326625202c363166\n"
".quad 0x61702e646c090a3b,0x203233662e6d6172,0x5b202c3831662509,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x3066664f795f6269,0x2e646461090a3b5d\n"
".quad 0x3166250920323366,0x2c37316625202c39,0x090a3b3831662520,0x203233662e627573\n"
".quad 0x25202c3032662509,0x316625202c393166,0x2e627573090a3b37,0x3266250920323366\n"
".quad 0x2c38316625202c31,0x090a3b3032662520,0x203233662e627573,0x25202c3232662509\n"
".quad 0x326625202c393166,0x2e627573090a3b30,0x3266250920323366,0x2c37316625202c33\n"
".quad 0x090a3b3232662520,0x203233662e646461,0x25202c3432662509,0x326625202c313266\n"
".quad 0x702e646c090a3b33,0x3233662e6d617261,0x202c353266250920,0x70616475635f5f5b\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x66664f795f626969,0x646461090a3b5d31\n"
".quad 0x662509203233662e,0x35326625202c3632,0x0a3b34326625202c,0x3233662e64646109\n"
".quad 0x202c373266250920,0x6625202c39316625,0x627573090a3b3632,0x662509203233662e\n"
".quad 0x37326625202c3832,0x0a3b39316625202c,0x3233662e62757309,0x202c393266250920\n"
".quad 0x6625202c36326625,0x6f6c2e090a3b3832,0x3232330937310963,0x702e646c090a3009\n"
".quad 0x2038732e6d617261,0x202c383231722509,0x70616475635f5f5b,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x5d4a73695f626969,0x752e766f6d090a3b,0x3231722509203233\n"
".quad 0x73090a3b30202c39,0x732e71652e707465,0x3131702509203233,0x2c3832317225202c\n"
".quad 0x0a3b393231722520,0x6220313170254009,0x5f744c2409206172,0x3b34373232325f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3638322065,0x6562616c20646165,0x5f744c242064656c,0x0a30393638315f36\n"
".quad 0x363109636f6c2e09,0x090a300933353209,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x635f5f5b202c3033,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f31,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x2e090a3b5d504a78,0x3209363109636f6c,0x646c090a30093535,0x662e6d617261702e\n"
".quad 0x3133662509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f315344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x4a795f6269696969,0x6f6c2e090a3b5d50,0x3735320936310963,0x2e766f6d090a3009\n"
".quad 0x3366250920323366,0x3b37326625202c32,0x3109636f6c2e090a,0x0a30093835320936\n"
".quad 0x3233662e766f6d09,0x202c333366250920,0x2e090a3b39326625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093935,0x2509203233662e76,0x316625202c343366,0x636f6c2e090a3b33\n"
".quad 0x0930363209363109,0x662e766f6d090a30,0x3533662509203233,0x0a3b35316625202c\n"
".quad 0x363109636f6c2e09,0x090a300931363209,0x203233662e766f6d,0x30202c3633662509\n"
".quad 0x3034303030363466,0x2f09202020203b30,0x090a33393138202f,0x203233662e6c756d\n"
".quad 0x25202c3733662509,0x336625202c373266,0x2e627573090a3b36,0x3366250920323366\n"
".quad 0x2c37336625202c38,0x090a3b3732662520,0x203233662e627573,0x25202c3933662509\n"
".quad 0x336625202c373366,0x2e627573090a3b38,0x3466250920323366,0x2c37326625202c30\n"
".quad 0x090a3b3933662520,0x203233662e6c756d,0x25202c3134662509,0x326625202c373266\n"
".quad 0x2e6c756d090a3b37,0x3466250920323366,0x2c37326625202c32,0x090a3b3932662520\n"
".quad 0x662e6e722e616d66,0x3334662509203233,0x202c37326625202c,0x6625202c39326625\n"
".quad 0x646461090a3b3234,0x662509203233662e,0x31346625202c3434,0x0a3b33346625202c\n"
".quad 0x3233662e6c756d09,0x202c353466250920,0x6625202c39336625,0x627573090a3b3933\n"
".quad 0x662509203233662e,0x35346625202c3634,0x0a3b31346625202c,0x3233662e62757309\n"
".quad 0x202c373466250920,0x6625202c34346625,0x616d66090a3b3134,0x203233662e6e722e\n"
".quad 0x25202c3834662509,0x346625202c393366,0x3b36346625202c30,0x33662e627573090a\n"
".quad 0x2c39346625092032,0x25202c3434662520,0x7573090a3b373466,0x2509203233662e62\n"
".quad 0x346625202c303566,0x3b37346625202c33,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x39336625202c3135,0x202c30346625202c,0x73090a3b38346625,0x09203233662e6275\n"
".quad 0x6625202c32356625,0x39346625202c3134,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x346625202c333566,0x2c30346625202c30,0x090a3b3135662520,0x203233662e646461\n"
".quad 0x25202c3435662509,0x356625202c303566,0x2e646461090a3b32,0x3566250920323366\n"
".quad 0x2c33356625202c35,0x090a3b3435662520,0x662e6e722e616d66,0x3635662509203233\n"
".quad 0x202c39326625202c,0x6625202c39326625,0x646461090a3b3535,0x662509203233662e\n"
".quad 0x34346625202c3735,0x0a3b36356625202c,0x3233662e766f6d09,0x202c383566250920\n"
".quad 0x73090a3b37356625,0x09203233662e6275,0x6625202c39356625,0x34346625202c3735\n"
".quad 0x662e627573090a3b,0x3036662509203233,0x202c36356625202c,0x2e090a3b39356625\n"
".quad 0x3209363109636f6c,0x6f6d090a30093236,0x2509203233662e76,0x346630202c313666\n"
".quad 0x3b30303430303036,0x202f2f0920202020,0x756d090a33393138,0x2509203233662e6c\n"
".quad 0x316625202c323666,0x3b31366625202c33,0x33662e627573090a,0x2c33366625092032\n"
".quad 0x25202c3236662520,0x7573090a3b333166,0x2509203233662e62,0x366625202c343666\n"
".quad 0x3b33366625202c32,0x33662e627573090a,0x2c35366625092032,0x25202c3331662520\n"
".quad 0x756d090a3b343666,0x2509203233662e6c,0x316625202c363666,0x3b33316625202c33\n"
".quad 0x33662e6c756d090a,0x2c37366625092032,0x25202c3331662520,0x6d66090a3b353166\n"
".quad 0x3233662e6e722e61,0x202c383666250920,0x6625202c33316625,0x37366625202c3531\n"
".quad 0x662e646461090a3b,0x3936662509203233,0x202c36366625202c,0x6d090a3b38366625\n"
".quad 0x09203233662e6c75,0x6625202c30376625,0x34366625202c3436,0x662e627573090a3b\n"
".quad 0x3137662509203233,0x202c30376625202c,0x73090a3b36366625,0x09203233662e6275\n"
".quad 0x6625202c32376625,0x36366625202c3936,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x366625202c333766,0x2c35366625202c34,0x090a3b3137662520,0x203233662e627573\n"
".quad 0x25202c3437662509,0x376625202c393666,0x2e627573090a3b32,0x3766250920323366\n"
".quad 0x2c38366625202c35,0x090a3b3237662520,0x662e6e722e616d66,0x3637662509203233\n"
".quad 0x202c34366625202c,0x6625202c35366625,0x627573090a3b3337,0x662509203233662e\n"
".quad 0x36366625202c3737,0x0a3b34376625202c,0x2e6e722e616d6609,0x3766250920323366\n"
".quad 0x2c35366625202c38,0x25202c3536662520,0x6461090a3b363766,0x2509203233662e64\n"
".quad 0x376625202c393766,0x3b37376625202c35,0x33662e646461090a,0x2c30386625092032\n"
".quad 0x25202c3837662520,0x6d66090a3b393766,0x3233662e6e722e61,0x202c313866250920\n"
".quad 0x6625202c35316625,0x30386625202c3531,0x662e646461090a3b,0x3238662509203233\n"
".quad 0x202c39366625202c,0x6d090a3b31386625,0x09203233662e766f,0x6625202c33386625\n"
".quad 0x627573090a3b3238,0x662509203233662e,0x32386625202c3438,0x0a3b39366625202c\n"
".quad 0x3233662e62757309,0x202c353866250920,0x6625202c31386625,0x766f6d090a3b3438\n"
".quad 0x662509203233662e,0x30306630202c3638,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x2c37386625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x62090a30202f2f09,0x0920696e752e6172,0x32325f365f744c24,0x744c240a3b383130\n"
".quad 0x34373232325f365f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36383220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30393638315f365f,0x3109636f6c2e090a,0x0a30093536320936,0x3233662e766f6d09\n"
".quad 0x202c303366250920,0x2e090a3b33316625,0x3209363109636f6c,0x6f6d090a30093636\n"
".quad 0x2509203233662e76,0x316625202c373866,0x636f6c2e090a3b35,0x0937363209363109\n"
".quad 0x662e766f6d090a30,0x3133662509203233,0x0a3b37326625202c,0x363109636f6c2e09\n"
".quad 0x090a300938363209,0x203233662e766f6d,0x25202c3638662509,0x6c2e090a3b393266\n"
".quad 0x373209363109636f,0x766f6d090a300936,0x662509203233662e,0x30306630202c3538\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c33386625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6630202c30366625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3566250920323366,0x3030306630202c38,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c353366250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c343366,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3333662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3233662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x5f744c240a30202f,0x3a38313032325f36\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3638322065,0x6562616c20646165,0x5f744c242064656c,0x0a30393638315f36\n"
".quad 0x363109636f6c2e09,0x090a300930383209,0x6d617261702e646c,0x722509203233732e\n"
".quad 0x5f5f5b202c303331,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5033316d735f3153,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x5d68636e7572635f,0x732e627573090a3b,0x3331722509203233,0x3033317225202c31\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3b31202c32333172,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x317225202c323170,0x33317225202c3033,0x31702540090a3b32\n"
".quad 0x2409206172622032,0x3034325f365f744c,0x3c2f2f200a3b3636,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36383220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3638315f365f744c,0x2e646461090a3039,0x3866250920323366\n"
".quad 0x2c33386625202c38,0x090a3b3835662520,0x203233662e627573,0x25202c3938662509\n"
".quad 0x386625202c383866,0x2e627573090a3b33,0x3966250920323366,0x2c38386625202c30\n"
".quad 0x090a3b3938662520,0x203233662e627573,0x25202c3139662509,0x386625202c383566\n"
".quad 0x2e627573090a3b39,0x3966250920323366,0x2c33386625202c32,0x090a3b3039662520\n"
".quad 0x203233662e646461,0x25202c3339662509,0x396625202c313966,0x2e646461090a3b32\n"
".quad 0x3966250920323366,0x2c33396625202c34,0x090a3b3538662520,0x203233662e646461\n"
".quad 0x25202c3539662509,0x366625202c343966,0x2e646461090a3b30,0x3966250920323366\n"
".quad 0x2c38386625202c36,0x090a3b3539662520,0x203233662e627573,0x25202c3739662509\n"
".quad 0x386625202c363966,0x2e627573090a3b38,0x3966250920323366,0x2c35396625202c38\n"
".quad 0x090a3b3739662520,0x203233662e646461,0x25202c3939662509,0x396625202c363966\n"
".quad 0x2e766f6d090a3b38,0x3166250920323366,0x30346630202c3030,0x203b303030303038\n"
".quad 0x0a34202f2f092020,0x746c2e7074657309,0x702509203233662e,0x39396625202c3331\n"
".quad 0x3b3030316625202c,0x333170252140090a,0x4c24092061726220,0x363034325f365f74\n"
".quad 0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36383220656e69,0x616c206461656820,0x4c242064656c6562,0x393638315f365f74\n"
".quad 0x662e766f6d090a30,0x3031662509203233,0x3036346630202c31,0x20203b3030343030\n"
".quad 0x393138202f2f0920,0x662e6c756d090a33,0x3031662509203233,0x2c34336625202c32\n"
".quad 0x0a3b313031662520,0x3233662e766f6d09,0x2c33303166250920,0x3030303634663020\n"
".quad 0x092020203b303034,0x0a33393138202f2f,0x3233662e6c756d09,0x2c34303166250920\n"
".quad 0x25202c3233662520,0x73090a3b33303166,0x09203233662e6275,0x25202c3530316625\n"
".quad 0x6625202c32303166,0x627573090a3b3433,0x662509203233662e,0x316625202c363031\n"
".quad 0x32336625202c3430,0x662e627573090a3b,0x3031662509203233,0x3230316625202c37\n"
".quad 0x3b3530316625202c,0x33662e627573090a,0x3830316625092032,0x2c3430316625202c\n"
".quad 0x0a3b363031662520,0x3233662e62757309,0x2c39303166250920,0x25202c3433662520\n"
".quad 0x73090a3b37303166,0x09203233662e6275,0x25202c3031316625,0x316625202c323366\n"
".quad 0x365f4c240a3b3830,0x0a3a32343636315f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x6c2e090a31383220,0x383209363109636f,0x6c756d090a300931\n"
".quad 0x662509203233662e,0x336625202c313131,0x3b32336625202c35,0x33662e6c756d090a\n"
".quad 0x3231316625092032,0x202c34336625202c,0x66090a3b32336625,0x33662e6e722e616d\n"
".quad 0x3331316625092032,0x202c34336625202c,0x6625202c33336625,0x6461090a3b313131\n"
".quad 0x2509203233662e64,0x6625202c34313166,0x316625202c323131,0x627573090a3b3331\n"
".quad 0x662509203233662e,0x316625202c353131,0x31316625202c3431,0x2e6c756d090a3b32\n"
".quad 0x3166250920323366,0x30316625202c3631,0x3830316625202c37,0x662e627573090a3b\n"
".quad 0x3131662509203233,0x3631316625202c37,0x3b3231316625202c,0x33662e627573090a\n"
".quad 0x3831316625092032,0x2c3331316625202c,0x0a3b353131662520,0x3233662e62757309\n"
".quad 0x2c39313166250920,0x202c343131662520,0x090a3b3531316625,0x662e6e722e616d66\n"
".quad 0x3231662509203233,0x3730316625202c30,0x2c3031316625202c,0x0a3b373131662520\n"
".quad 0x3233662e62757309,0x2c31323166250920,0x202c323131662520,0x090a3b3931316625\n"
".quad 0x662e6e722e616d66,0x3231662509203233,0x3830316625202c32,0x2c3930316625202c\n"
".quad 0x0a3b303231662520,0x3233662e64646109,0x2c33323166250920,0x202c383131662520\n"
".quad 0x090a3b3132316625,0x662e6e722e616d66,0x3231662509203233,0x3930316625202c34\n"
".quad 0x2c3031316625202c,0x0a3b323231662520,0x3233662e64646109,0x2c35323166250920\n"
".quad 0x202c333231662520,0x090a3b3432316625,0x662e6e722e616d66,0x3231662509203233\n"
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
".quad 0x6d66090a3b393431,0x3233662e6e722e61,0x2c37373166250920,0x202c393431662520\n"
".quad 0x6625202c33336625,0x7573090a3b343731,0x2509203233662e62,0x6625202c38303166\n"
".quad 0x316625202c333731,0x646461090a3b3637,0x662509203233662e,0x316625202c383731\n"
".quad 0x37316625202c3537,0x2e627573090a3b37,0x3166250920323366,0x34316625202c3031\n"
".quad 0x3830316625202c39,0x662e6c756d090a3b,0x3731662509203233,0x3830316625202c39\n"
".quad 0x3b3830316625202c,0x33662e627573090a,0x3038316625092032,0x2c3937316625202c\n"
".quad 0x0a3b353731662520,0x3233662e62757309,0x2c31383166250920,0x202c383731662520\n"
".quad 0x090a3b3537316625,0x662e6e722e616d66,0x3831662509203233,0x3830316625202c32\n"
".quad 0x2c3031316625202c,0x0a3b303831662520,0x3233662e62757309,0x2c33383166250920\n"
".quad 0x202c373731662520,0x090a3b3138316625,0x203233662e627573,0x202c343831662509\n"
".quad 0x25202c3837316625,0x66090a3b31383166,0x33662e6e722e616d,0x3538316625092032\n"
".quad 0x2c3830316625202c,0x202c303131662520,0x090a3b3238316625,0x203233662e627573\n"
".quad 0x202c363831662509,0x25202c3537316625,0x66090a3b34383166,0x33662e6e722e616d\n"
".quad 0x3738316625092032,0x2c3031316625202c,0x202c303131662520,0x090a3b3538316625\n"
".quad 0x203233662e646461,0x202c383831662509,0x25202c3338316625,0x61090a3b36383166\n"
".quad 0x09203233662e6464,0x25202c3938316625,0x6625202c37383166,0x6d66090a3b383831\n"
".quad 0x3233662e6e722e61,0x2c30393166250920,0x25202c3333662520,0x316625202c333366\n"
".quad 0x646461090a3b3938,0x662509203233662e,0x316625202c313931,0x39316625202c3837\n"
".quad 0x2e766f6d090a3b30,0x3566250920323366,0x3139316625202c38,0x662e627573090a3b\n"
".quad 0x3931662509203233,0x3139316625202c32,0x3b3837316625202c,0x33662e627573090a\n"
".quad 0x2c30366625092032,0x202c303931662520,0x090a3b3239316625,0x09363109636f6c2e\n"
".quad 0x6d090a3009393832,0x09203233662e766f,0x30202c3339316625,0x3034303030363466\n"
".quad 0x2f2f092020203b30,0x6d090a3339313820,0x09203233662e6c75,0x25202c3439316625\n"
".quad 0x6625202c30373166,0x756d090a3b333931,0x2509203233662e6c,0x6625202c35393166\n"
".quad 0x336625202c303731,0x2e6c756d090a3b35,0x3166250920323366,0x37316625202c3639\n"
".quad 0x3037316625202c30,0x662e627573090a3b,0x3931662509203233,0x3439316625202c37\n"
".quad 0x3b3037316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c383931\n"
".quad 0x35336625202c3037,0x3b3539316625202c,0x33662e627573090a,0x3730316625092032\n"
".quad 0x2c3439316625202c,0x0a3b373931662520,0x3233662e64646109,0x2c39393166250920\n"
".quad 0x202c363931662520,0x090a3b3839316625,0x203233662e627573,0x202c393031662509\n"
".quad 0x25202c3037316625,0x6d090a3b37303166,0x09203233662e6c75,0x25202c3030326625\n"
".quad 0x6625202c37303166,0x7573090a3b373031,0x2509203233662e62,0x6625202c31303266\n"
".quad 0x316625202c303032,0x627573090a3b3639,0x662509203233662e,0x316625202c323032\n"
".quad 0x39316625202c3939,0x2e616d66090a3b36,0x09203233662e6e72,0x25202c3330326625\n"
".quad 0x6625202c37303166,0x326625202c393031,0x627573090a3b3130,0x662509203233662e\n"
".quad 0x316625202c343032,0x30326625202c3839,0x2e627573090a3b32,0x3266250920323366\n"
".quad 0x39316625202c3530,0x3230326625202c39,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c36303266,0x316625202c373031,0x30326625202c3930,0x2e627573090a3b33\n"
".quad 0x3266250920323366,0x39316625202c3730,0x3530326625202c36,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c38303266,0x316625202c393031,0x30326625202c3930\n"
".quad 0x2e646461090a3b36,0x3266250920323366,0x30326625202c3930,0x3730326625202c34\n"
".quad 0x662e646461090a3b,0x3132662509203233,0x3830326625202c30,0x3b3930326625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x336625202c313132,0x2c35336625202c35\n"
".quad 0x0a3b303132662520,0x3233662e64646109,0x2c32313266250920,0x202c393931662520\n"
".quad 0x090a3b3131326625,0x203233662e766f6d,0x25202c3338662509,0x73090a3b32313266\n"
".quad 0x09203233662e6275,0x25202c3331326625,0x6625202c32313266,0x7573090a3b393931\n"
".quad 0x2509203233662e62,0x326625202c353866,0x31326625202c3131,0x636f6c2e090a3b33\n"
".quad 0x0930393209363109,0x662e646461090a30,0x3132662509203233,0x3139316625202c34\n"
".quad 0x3b3231326625202c,0x33662e627573090a,0x3531326625092032,0x2c3431326625202c\n"
".quad 0x0a3b323132662520,0x3233662e62757309,0x2c36313266250920,0x202c313931662520\n"
".quad 0x090a3b3531326625,0x203233662e627573,0x202c373132662509,0x25202c3431326625\n"
".quad 0x73090a3b35313266,0x09203233662e6275,0x25202c3831326625,0x6625202c32313266\n"
".quad 0x6461090a3b373132,0x2509203233662e64,0x6625202c39313266,0x326625202c363132\n"
".quad 0x646461090a3b3831,0x662509203233662e,0x386625202c303232,0x3931326625202c35\n"
".quad 0x662e646461090a3b,0x3232662509203233,0x2c30366625202c31,0x0a3b303232662520\n"
".quad 0x3233662e64646109,0x2c32323266250920,0x202c343132662520,0x090a3b3132326625\n"
".quad 0x203233662e627573,0x202c333232662509,0x25202c3232326625,0x73090a3b34313266\n"
".quad 0x09203233662e6275,0x25202c3432326625,0x6625202c31323266,0x6c2e090a3b333232\n"
".quad 0x383209363109636f,0x627573090a300930,0x722509203233732e,0x317225202c313331\n"
".quad 0x090a3b31202c3133,0x203233752e766f6d,0x202c333331722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3431702509,0x7225202c31333172,0x2540090a3b333331\n"
".quad 0x2061726220343170,0x325f365f744c2409,0x2f200a3b36363034,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3138\n"
".quad 0x64656c6562616c20,0x36315f365f4c2420,0x646461090a323436,0x662509203233662e\n"
".quad 0x326625202c353232,0x32326625202c3432,0x2e766f6d090a3b32,0x3266250920323366\n"
".quad 0x30346630202c3632,0x203b303030303038,0x0a34202f2f092020,0x746c2e7074657309\n"
".quad 0x702509203233662e,0x32326625202c3531,0x3632326625202c35,0x3531702540090a3b\n"
".quad 0x4c24092061726220,0x32343636315f365f,0x5f365f744c240a3b,0x240a3a3636303432\n"
".quad 0x393836315f365f4c,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36383220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393638315f365f74,0x09636f6c2e090a30,0x3009323233093731,0x33732e766f6d090a\n"
".quad 0x3433317225092032,0x6573090a3b30202c,0x33732e74672e7074,0x2c36317025092032\n"
".quad 0x202c313331722520,0x090a3b3433317225,0x203233732e627573,0x202c353331722509\n"
".quad 0x25202c3033317225,0x6d090a3b31333172,0x09203233732e766f,0x30202c3633317225\n"
".quad 0x2e706c6573090a3b,0x3172250920323373,0x33317225202c3733,0x3633317225202c35\n"
".quad 0x0a3b36317025202c,0x3233752e766f6d09,0x2c38333172250920,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c373170250920,0x25202c3733317225,0x40090a3b38333172\n"
".quad 0x6172622037317025,0x5f365f744c240920,0x200a3b3638373232,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832\n"
".quad 0x656c6562616c2064,0x5f365f744c242064,0x2e090a3039363831,0x3309373109636f6c\n"
".quad 0x646c090a30093932,0x732e6d617261702e,0x3331722509203233,0x75635f5f5b202c39\n"
".quad 0x5f5f6d7261706164,0x65646e614d38315a,0x315344746f72626c,0x75365033316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x615f62696969695f,0x6e6f6974616d696e\n"
".quad 0x0a3b5d656d617246,0x3233732e64646109,0x2c30343172250920,0x202c393331722520\n"
".quad 0x090a3b3733317225,0x6d617261702e646c,0x317225092038752e,0x635f5f5b202c3134\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x302b73726f6c6f63\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x25202c3234317225,0x7225202c30343172\n"
".quad 0x7663090a3b313431,0x3233752e38752e74,0x2c33343172250920,0x0a3b323431722520\n"
".quad 0x373109636f6c2e09,0x090a300930333309,0x6d617261702e646c,0x317225092038752e\n"
".quad 0x635f5f5b202c3434,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f31,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x312b73726f6c6f63,0x2e6c756d090a3b5d,0x09203233732e6f6c,0x25202c3534317225\n"
".quad 0x7225202c30343172,0x7663090a3b343431,0x3233752e38752e74,0x2c36343172250920\n"
".quad 0x0a3b353431722520,0x373109636f6c2e09,0x090a300931333309,0x6d617261702e646c\n"
".quad 0x317225092038752e,0x635f5f5b202c3734,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365033316d735f31,0x6969347261686375,0x6666666666666669\n"
".quad 0x5f62696969695f53,0x322b73726f6c6f63,0x2e6c756d090a3b5d,0x09203233732e6f6c\n"
".quad 0x25202c3834317225,0x7225202c30343172,0x7663090a3b373431,0x3233752e38752e74\n"
".quad 0x2c39343172250920,0x0a3b383431722520,0x696e752e61726209,0x5f365f744c240920\n"
".quad 0x240a3b3033353232,0x3732325f365f744c,0x3c2f2f200a3a3638,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36383220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3638315f365f744c,0x636f6c2e090a3039,0x0935333309373109\n"
".quad 0x752e766f6d090a30,0x3431722509203233,0x6d090a3b30202c39,0x09203233752e766f\n"
".quad 0x30202c3634317225,0x752e766f6d090a3b,0x3431722509203233,0x4c240a3b30202c33\n"
".quad 0x333532325f365f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36383220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393638315f365f74,0x09636f6c2e090a30,0x3009313433093731,0x7261702e646c090a\n"
".quad 0x09203233732e6d61,0x5b202c3035317225,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x656d6172665f6269,0x2e646461090a3b5d,0x3172250920323373\n"
".quad 0x35317225202c3135,0x73090a3b31202c30,0x09203233732e7268,0x25202c3235317225\n"
".quad 0x3133202c31353172,0x732e766f6d090a3b,0x3531722509203233,0x61090a3b31202c33\n"
".quad 0x09203233622e646e,0x25202c3435317225,0x7225202c32353172,0x6461090a3b333531\n"
".quad 0x2509203233732e64,0x7225202c35353172,0x317225202c343531,0x726873090a3b3135\n"
".quad 0x722509203233732e,0x317225202c363531,0x090a3b31202c3535,0x732e6f6c2e6c756d\n"
".quad 0x3531722509203233,0x3035317225202c37,0x0a3b36337225202c,0x3233732e64646109\n"
".quad 0x2c38353172250920,0x202c333431722520,0x090a3b3735317225,0x203233732e646461\n"
".quad 0x202c393531722509,0x25202c3635317225,0x64090a3b38353172,0x09203233732e7669\n"
".quad 0x25202c3036317225,0x7225202c39353172,0x6c2e090a3b313531,0x343309373109636f\n"
".quad 0x6c756d090a300932,0x203233732e6f6c2e,0x202c313631722509,0x25202c3035317225\n"
".quad 0x6461090a3b373372,0x2509203233732e64,0x7225202c32363172,0x317225202c363431\n"
".quad 0x646461090a3b3136,0x722509203233732e,0x317225202c333631,0x36317225202c3635\n"
".quad 0x2e766964090a3b32,0x3172250920323373,0x36317225202c3436,0x3135317225202c33\n"
".quad 0x6c672e7473090a3b,0x2e32762e6c61626f,0x6472255b09203875,0x257b202c5d302b34\n"
".quad 0x3172252c30363172,0x6c2e090a3b7d3436,0x343309373109636f,0x6c756d090a300933\n"
".quad 0x203233732e6f6c2e,0x202c353631722509,0x25202c3035317225,0x6461090a3b383372\n"
".quad 0x2509203233732e64,0x7225202c36363172,0x317225202c393431,0x646461090a3b3536\n"
".quad 0x722509203233732e,0x317225202c373631,0x36317225202c3635,0x2e766964090a3b36\n"
".quad 0x3172250920323373,0x36317225202c3836,0x3135317225202c37,0x6c672e7473090a3b\n"
".quad 0x2038752e6c61626f,0x322b346472255b09,0x3836317225202c5d,0x5f365f744c240a3b\n"
".quad 0x240a3a3630353132,0x3938315f365f744c,0x3c2f2f200a3a3634,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36383220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3638315f365f744c,0x636f6c2e090a3039,0x0937343309373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x3233752e766f6d09,0x2c39363172250920\n"
".quad 0x746573090a3b3020,0x3233732e71652e70,0x202c383170250920,0x317225202c377225\n"
".quad 0x702540090a3b3936,0x0920617262203831,0x33325f365f744c24,0x2f2f200a3b323430\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383220656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x38315f365f744c24,0x6f6c2e090a303936\n"
".quad 0x3135330937310963,0x2e766f6d090a3009,0x6472250920343675,0x6b636f6c62202c39\n"
".quad 0x3b7265746e756f43,0x33752e766f6d090a,0x3037317225092032,0x7461090a3b31202c\n"
".quad 0x61626f6c672e6d6f,0x33752e6464612e6c,0x3137317225092032,0x5d396472255b202c\n"
".quad 0x3b3037317225202c,0x33732e766f6d090a,0x3237317225092032,0x3b3137317225202c\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x37313536335f7261,0x5f6e6f6e5f32345f,0x6c625f74736e6f63,0x7865646e496b636f\n"
".quad 0x3237317225202c5d,0x09636f6c2e090a3b,0x3009323533093731,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5b202c3337317225,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x57646972675f6269,0x090a3b5d68746469,0x203233752e6d6572\n"
".quad 0x202c343731722509,0x25202c3237317225,0x73090a3b33373172,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32345f3831353633\n"
".quad 0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x37317225202c5d58,0x636f6c2e090a3b34\n"
".quad 0x0933353309373109,0x752e766964090a30,0x3731722509203233,0x3237317225202c35\n"
".quad 0x3b3337317225202c,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x38313536335f7261,0x5f6e6f6e5f30355f,0x6c625f74736e6f63\n"
".quad 0x25202c5d596b636f,0x4c240a3b35373172,0x343033325f365f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36383220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x393638315f365f74,0x09636f6c2e090a30\n"
".quad 0x3009363533093731,0x79732e726162090a,0x090a3b300920636e,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5b202c36373172,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32345f3731353633,0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x0a3b5d7865646e49\n"
".quad 0x746c2e7074657309,0x702509203233752e,0x37317225202c3931,0x3b35317225202c36\n"
".quad 0x203931702540090a,0x744c240920617262,0x30393638315f365f,0x5f365f744c240a3b\n"
".quad 0x090a3a3837313831,0x09373109636f6c2e,0x65090a3009393533,0x444c240a3b746978\n"
".quad 0x315a5f5f646e6557,0x626c65646e614d38,0x735f315344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x7d090a3a62696969,0x38315a5f202f2f20\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x652e090a0a626969,0x315a5f207972746e,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c664933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x09090a2820626969,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c664933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x73645f6269696969,0x61702e09090a2c74,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6567616d695f6269,0x61702e09090a2c57,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6567616d695f6269,0x61702e09090a2c48,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x636e7572635f6269,0x61702e09090a2c68,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x2c66664f785f6269,0x617261702e09090a,0x5f203233662e206d\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x090a2c66664f795f,0x206d617261702e09,0x635f5f203233662e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x785f62696969695f,0x702e09090a2c504a,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c664933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x2c504a795f626969,0x617261702e09090a,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x0a2c656c6163735f,0x6d617261702e0909,0x206e67696c612e20,0x5f5f2038622e2034\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x345b73726f6c6f63,0x61702e09090a2c5d,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x656d6172665f6269,0x7261702e09090a2c,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c66,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x74616d696e615f62,0x656d6172466e6f69,0x7261702e09090a2c\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4933316d735f3074,0x7645453631694c66,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x6957646972675f62,0x2e09090a2c687464\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x6d756e5f62696969,0x0a2c736b636f6c42\n"
".quad 0x6d617261702e0909,0x635f5f2038732e20,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f,0x090a7b090a294a73\n"
".quad 0x33752e206765722e,0x3930313c72252032,0x6765722e090a3b3e,0x7225203436752e20\n"
".quad 0x090a3b3e35313c64,0x33662e206765722e,0x3e32323c66252032,0x206765722e090a3b\n"
".quad 0x702520646572702e,0x2e090a3b3e31323c,0x2e20646572616873,0x75635f5f20323375\n"
".quad 0x6c61636f6c5f6164,0x3236335f7261765f,0x6f6e5f32345f3237,0x5f74736e6f635f6e\n"
".quad 0x646e496b636f6c62,0x68732e090a3b7865,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x33373236335f7261,0x5f6e6f6e5f32345f,0x6c625f74736e6f63\n"
".quad 0x2e090a3b586b636f,0x2e20646572616873,0x75635f5f20323375,0x6c61636f6c5f6164\n"
".quad 0x3236335f7261765f,0x6f6e5f30355f3337,0x5f74736e6f635f6e,0x0a3b596b636f6c62\n"
".quad 0x206c61636f6c2e09,0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3236335f7261765f,0x6f6e5f31315f3739,0x5f74736e6f635f6e\n"
".quad 0x5b38303236315f6d,0x6c2e090a3b5d3436,0x6c612e206c61636f,0x622e2034206e6769\n"
".quad 0x616475635f5f2038,0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f36393236335f72\n"
".quad 0x6f635f6e6f6e5f36,0x736f50785f74736e,0x365b32373230385f,0x6f6c2e090a3b5d34\n"
".quad 0x0938320937310963,0x656257444c240a30,0x36315a5f5f6e6967,0x72626c65646e614d\n"
".quad 0x33316d735f30746f,0x45453631694c6649,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x766f6d090a3a6269,0x722509203233752e\n"
".quad 0x2e64697425202c31,0x2e766f6d090a3b78,0x3272250920323375,0x6573090a3b30202c\n"
".quad 0x33752e71652e7074,0x202c317025092032,0x327225202c317225,0x752e766f6d090a3b\n"
".quad 0x2c33722509203233,0x3b792e6469742520,0x33752e766f6d090a,0x202c347225092032\n"
".quad 0x70746573090a3b30,0x203233752e71652e,0x7225202c32702509,0x0a3b347225202c33\n"
".quad 0x33732e706c657309,0x202c357225092032,0x7025202c30202c31,0x706c6573090a3b31\n"
".quad 0x722509203233732e,0x2c30202c31202c36,0x61090a3b32702520,0x09203233622e646e\n"
".quad 0x357225202c377225,0x090a3b367225202c,0x203233752e766f6d,0x3b30202c38722509\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x2c377225202c3370,0x40090a3b38722520\n"
".quad 0x2061726220337025,0x315f375f744c2409,0x2e090a3b30373533,0x3309373109636f6c\n"
".quad 0x766f6d090a300935,0x722509203436752e,0x636f6c62202c3164,0x7265746e756f436b\n"
".quad 0x752e766f6d090a3b,0x2c39722509203233,0x6f7461090a3b3120,0x6c61626f6c672e6d\n"
".quad 0x3233752e6464612e,0x202c303172250920,0x202c5d316472255b,0x6f6d090a3b397225\n"
".quad 0x2509203233732e76,0x317225202c313172,0x732e7473090a3b30,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3236335f7261765f,0x6f6e5f32345f3237\n"
".quad 0x5f74736e6f635f6e,0x646e496b636f6c62,0x317225202c5d7865,0x636f6c2e090a3b31\n"
".quad 0x3009363309373109,0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c32317225\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x646957646972675f,0x6572090a3b5d6874,0x2509203233752e6d\n"
".quad 0x317225202c333172,0x3b32317225202c31,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x616475635f5f5b09,0x765f6c61636f6c5f,0x33373236335f7261,0x5f6e6f6e5f32345f\n"
".quad 0x6c625f74736e6f63,0x25202c5d586b636f,0x6c2e090a3b333172,0x373309373109636f\n"
".quad 0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34,0x090a3b3231722520\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x355f33373236335f,0x6f635f6e6f6e5f30,0x636f6c625f74736e,0x317225202c5d596b\n"
".quad 0x375f744c240a3b34,0x0a3a30373533315f,0x373109636f6c2e09,0x62090a3009393309\n"
".quad 0x20636e79732e7261,0x2e646c090a3b3009,0x33752e6d61726170,0x2c35317225092032\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72\n"
".quad 0x453631694c664933,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x426d756e5f626969,0x0a3b5d736b636f6c,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x5f5b202c36317225,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32345f3237323633,0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x0a3b5d7865646e49\n"
".quad 0x65672e7074657309,0x702509203233752e,0x2c36317225202c34,0x090a3b3531722520\n"
".quad 0x6172622034702540,0x5f375f744c240920,0x090a3b3238303431,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x635f5f5b202c3731,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f,0x0a3b5d486567616d\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c383172,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x3b5d576567616d69,0x33752e766f6d090a,0x2c39317225092032,0x792e6469746e2520\n"
".quad 0x752e766f6d090a3b,0x3032722509203233,0x2e6469746e25202c,0x2e766f6d090a3b78\n"
".quad 0x6472250920343675,0x6475635f5f202c32,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x37393236335f7261,0x5f6e6f6e5f31315f,0x5f6d5f74736e6f63,0x090a3b3830323631\n"
".quad 0x203436752e766f6d,0x5f202c3364722509,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x6e5f365f36393236,0x74736e6f635f6e6f,0x30385f736f50785f\n"
".quad 0x744c240a3b323732,0x34393534315f375f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x6c090a393320656e,0x6465726168732e64,0x722509203233752e\n"
".quad 0x635f5f5b202c3132,0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f32345f333732\n"
".quad 0x74736e6f635f6e6f,0x5d586b636f6c625f,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x327225202c323272,0x3b30327225202c31,0x6168732e646c090a,0x203233752e646572\n"
".quad 0x5b202c3332722509,0x6c5f616475635f5f,0x7261765f6c61636f,0x355f33373236335f\n"
".quad 0x6f635f6e6f6e5f30,0x636f6c625f74736e,0x756d090a3b5d596b,0x3233752e6f6c2e6c\n"
".quad 0x202c343272250920,0x7225202c33327225,0x646461090a3b3931,0x722509203233752e\n"
".quad 0x32327225202c3532,0x090a3b317225202c,0x203233752e646461,0x25202c3632722509\n"
".quad 0x337225202c343272,0x6c2e6c756d090a3b,0x2509203233752e6f,0x327225202c373272\n"
".quad 0x090a3b3631202c35,0x203233732e646461,0x25202c3832722509,0x3b3631202c373272\n"
".quad 0x33732e6e696d090a,0x2c39327225092032,0x25202c3831722520,0x696d090a3b373272\n"
".quad 0x2509203233732e6e,0x327225202c303372,0x3b38317225202c38,0x33732e627573090a\n"
".quad 0x2c31337225092032,0x25202c3033722520,0x6f6d090a3b393272,0x2509203233732e76\n"
".quad 0x0a3b30202c323372,0x74672e7074657309,0x702509203233732e,0x2c31337225202c35\n"
".quad 0x090a3b3233722520,0x3233732e706c6573,0x202c333372250920,0x7025202c30202c31\n"
".quad 0x2e746573090a3b35,0x732e3233752e7467,0x3433722509203233,0x202c37317225202c\n"
".quad 0x6e090a3b36327225,0x09203233732e6765,0x7225202c35337225,0x646e61090a3b3433\n"
".quad 0x722509203233622e,0x33337225202c3633,0x0a3b35337225202c,0x3233752e766f6d09\n"
".quad 0x202c373372250920,0x70746573090a3b30,0x203233732e71652e,0x7225202c36702509\n"
".quad 0x37337225202c3633,0x2036702540090a3b,0x744c240920617262,0x34333438315f375f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c393320656e,0x6562616c20646165,0x5f744c242064656c,0x0a34393534315f37\n"
".quad 0x6220357025214009,0x5f744c2409206172,0x3b38313032325f37,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c39332065\n"
".quad 0x6c6562616c206461,0x375f744c24206465,0x090a34393534315f,0x203233732e766f6d\n"
".quad 0x25202c3833722509,0x756d090a3b313372,0x3233752e6f6c2e6c,0x202c393372250920\n"
".quad 0x3b3631202c317225,0x6f6c2e6c756d090a,0x722509203233752e,0x32327225202c3034\n"
".quad 0x61090a3b3631202c,0x09203233732e6464,0x7225202c31347225,0x30347225202c3933\n"
".quad 0x752e766f6d090a3b,0x3464722509203436,0x616475635f5f202c,0x5f616475635f5f5f\n"
".quad 0x61765f6c61636f6c,0x5f36393236335f72,0x6f635f6e6f6e5f36,0x736f50785f74736e\n"
".quad 0x0a3b32373230385f,0x3233732e766f6d09,0x202c323472250920,0x61090a3b31347225\n"
".quad 0x09203233732e6464,0x7225202c33347225,0x31337225202c3134,0x61702e646c090a3b\n"
".quad 0x203233662e6d6172,0x5f5b202c31662509,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x0a3b5d66664f785f\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3266,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x735f62696969695f\n"
".quad 0x200a3b5d656c6163,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20,0x315f375f744c2420\n"
".quad 0x6f6d090a34393534,0x2509203233732e76,0x337225202c343472,0x375f744c240a3b38\n"
".quad 0x0a3a34373835315f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x73656e202c393320,0x70656420676e6974,0x65202c31203a6874,0x646574616d697473\n"
".quad 0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e,0x383509373109636f\n"
".quad 0x2e747663090a3009,0x732e3233662e6e72,0x2c33662509203233,0x090a3b3234722520\n"
".quad 0x662e6e722e616d66,0x2c34662509203233,0x6625202c33662520,0x0a3b316625202c32\n"
".quad 0x61636f6c2e747309,0x5b09203233662e6c,0x2c5d302b34647225,0x61090a3b34662520\n"
".quad 0x09203233732e6464,0x7225202c32347225,0x090a3b31202c3234,0x203436752e646461\n"
".quad 0x25202c3464722509,0x0a3b34202c346472,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x2c32347225202c37,0x090a3b3334722520,0x6172622037702540,0x5f375f744c240920\n"
".quad 0x200a3b3437383531,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20,0x315f375f744c2420\n"
".quad 0x7262090a34393534,0x240920696e752e61,0x3335315f375f744c,0x5f744c240a3b3236\n"
".quad 0x3a38313032325f37,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c39332065,0x6c6562616c206461,0x375f744c24206465\n"
".quad 0x090a34393534315f,0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c32\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x31694c664933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x63735f6269696969,0x4c240a3b5d656c61,0x363335315f375f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34393534315f375f,0x3109636f6c2e090a\n"
".quad 0x0a30093833310936,0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c353472\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x3b5d68636e757263,0x33732e766f6d090a,0x2c36347225092032\n"
".quad 0x090a3b3534722520,0x6d617261702e646c,0x347225092038732e,0x75635f5f5b202c37\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x31694c664933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x73695f6269696969,0x766f6d090a3b5d4a,0x722509203233732e,0x090a3b30202c3834\n"
".quad 0x2e656e2e70746573,0x3870250920323373,0x202c37347225202c,0x63090a3b38347225\n"
".quad 0x33662e6e722e7476,0x2509203233732e32,0x36327225202c3566,0x61702e646c090a3b\n"
".quad 0x203233662e6d6172,0x5f5b202c36662509,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x0a3b5d66664f795f\n"
".quad 0x2e6e722e616d6609,0x3766250920323366,0x25202c356625202c,0x3b366625202c3266\n"
".quad 0x636f6c2e646c090a,0x09203233662e6c61,0x5f5f5b202c386625,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x36335f7261765f6c,0x6f6e5f365f363932,0x5f74736e6f635f6e\n"
".quad 0x3230385f736f5078,0x090a3b5d302b3237,0x7262203870252140,0x375f744c24092061\n"
".quad 0x0a3b32343636315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064,0x5f375f744c242064\n"
".quad 0x2e090a3439353431,0x3109363109636f6c,0x646c090a30093434,0x662e6d617261702e\n"
".quad 0x2c39662509203233,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c664933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x5d504a785f626969,0x09636f6c2e090a3b\n"
".quad 0x3009353431093631,0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c30316625\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x090a3b5d504a795f,0x09363109636f6c2e,0x6d090a3009363431\n"
".quad 0x09203233662e766f,0x6625202c31316625,0x636f6c2e090a3b37,0x0937343109363109\n"
".quad 0x662e766f6d090a30,0x3231662509203233,0x090a3b386625202c,0x09363109636f6c2e\n"
".quad 0x6d090a3009383431,0x09203233662e6c75,0x6625202c33316625,0x0a3b376625202c37\n"
".quad 0x363109636f6c2e09,0x090a300939343109,0x203233662e6c756d,0x25202c3431662509\n"
".quad 0x3b386625202c3866,0x6e752e617262090a,0x375f744c24092069,0x0a3b36383336315f\n"
".quad 0x36315f375f744c24,0x2f2f200a3a323436,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f375f744c,0x636f6c2e090a3439,0x0933353109363109,0x662e766f6d090a30\n"
".quad 0x2c39662509203233,0x2e090a3b38662520,0x3109363109636f6c,0x6f6d090a30093435\n"
".quad 0x2509203233662e76,0x376625202c303166,0x09636f6c2e090a3b,0x3009383531093631\n"
".quad 0x33662e766f6d090a,0x2c34316625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6630202c33316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c32\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c313166250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x744c240a30202f2f,0x36383336315f375f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c393320656e,0x6562616c20646165,0x5f744c242064656c,0x0a34393534315f37\n"
".quad 0x3233752e766f6d09,0x202c393472250920,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x7225202c39702509,0x39347225202c3133,0x2039702540090a3b,0x744c240920617262\n"
".quad 0x38393836315f375f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c393320656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34393534315f37,0x3233732e766f6d09,0x202c303572250920,0x375f744c240a3b30\n"
".quad 0x0a3a30313437315f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x656e202c38353120,0x656420676e697473,0x202c32203a687470,0x6574616d69747365\n"
".quad 0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3109363109636f6c\n"
".quad 0x7573090a30093236,0x2509203233732e62,0x347225202c363472,0x6d090a3b31202c36\n"
".quad 0x09203233752e766f,0x3b30202c31357225,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x347225202c303170,0x3b31357225202c36,0x203031702540090a,0x5f4c240920617262\n"
".quad 0x3b34313333315f37,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3835312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30313437315f37,0x3233662e64646109,0x202c353166250920,0x6625202c34316625\n"
".quad 0x766f6d090a3b3331,0x662509203233662e,0x30346630202c3631,0x203b303030303038\n"
".quad 0x34202f2f09202020,0x672e70746573090a,0x2509203233662e74,0x316625202c313170\n"
".quad 0x3b36316625202c35,0x313170252140090a,0x4c24092061726220,0x38353033315f375f\n"
".quad 0x315f375f4c240a3b,0x2f200a3a34313333,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3835,0x64656c6562616c20\n"
".quad 0x315f375f744c2420,0x6c2e090a30313437,0x363109363109636f,0x6c756d090a300933\n"
".quad 0x203233752e6f6c2e,0x25202c3235722509,0x0a3b34202c303572,0x3436752e74766309\n"
".quad 0x722509203233752e,0x32357225202c3564,0x752e646461090a3b,0x3664722509203436\n"
".quad 0x202c35647225202c,0x73090a3b32647225,0x2e6c61636f6c2e74,0x72255b0920323373\n"
".quad 0x25202c5d302b3664,0x6c2e090a3b363472,0x363109363109636f,0x646461090a300935\n"
".quad 0x722509203233732e,0x30357225202c3035,0x6573090a3b31202c,0x33732e71652e7074\n"
".quad 0x2c32317025092032,0x25202c3133722520,0x2540090a3b303572,0x2061726220323170\n"
".quad 0x315f375f744c2409,0x2f200a3b38393836,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3835,0x64656c6562616c20\n"
".quad 0x315f375f744c2420,0x756d090a30313437,0x3233752e6f6c2e6c,0x202c333572250920\n"
".quad 0x3b34202c30357225,0x36752e747663090a,0x2509203233752e34,0x357225202c376472\n"
".quad 0x2e646461090a3b33,0x6472250920343675,0x2c37647225202c38,0x090a3b3364722520\n"
".quad 0x6c61636f6c2e646c,0x662509203233662e,0x6472255b202c3731,0x40090a3b5d302b38\n"
".quad 0x6172622038702521,0x5f375f744c240920,0x200a3b3232393731,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383531\n"
".quad 0x656c6562616c2064,0x5f375f744c242064,0x2e090a3031343731,0x3109363109636f6c\n"
".quad 0x646c090a30093736,0x662e6d617261702e,0x2c39662509203233,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c664933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x5d504a785f626969,0x09636f6c2e090a3b,0x3009383631093631,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5b202c30316625,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x090a3b5d504a795f\n"
".quad 0x09363109636f6c2e,0x6d090a3009393631,0x09203233662e766f,0x6625202c31316625\n"
".quad 0x636f6c2e090a3b37,0x0930373109363109,0x662e766f6d090a30,0x3231662509203233\n"
".quad 0x0a3b37316625202c,0x363109636f6c2e09,0x090a300931373109,0x203233662e6c756d\n"
".quad 0x25202c3331662509,0x3b376625202c3766,0x3109636f6c2e090a,0x0a30093237310936\n"
".quad 0x3233662e6c756d09,0x202c343166250920,0x6625202c37316625,0x617262090a3b3731\n"
".quad 0x4c240920696e752e,0x363637315f375f74,0x375f744c240a3b36,0x0a3a32323937315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c38353120,0x6c6562616c206461,0x375f744c24206465,0x090a30313437315f\n"
".quad 0x09363109636f6c2e,0x6d090a3009353731,0x09203233662e766f,0x316625202c396625\n"
".quad 0x636f6c2e090a3b37,0x0936373109363109,0x662e766f6d090a30,0x3031662509203233\n"
".quad 0x090a3b376625202c,0x09363109636f6c2e,0x6d090a3009303831,0x09203233662e766f\n"
".quad 0x6630202c34316625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3166250920323366,0x3030306630202c33,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c323166250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c313166,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x5f375f744c240a30,0x200a3a3636363731,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383531\n"
".quad 0x656c6562616c2064,0x5f375f744c242064,0x2e090a3031343731,0x3109363109636f6c\n"
".quad 0x6f6d090a30093338,0x2509203233732e76,0x347225202c363472,0x5f375f4c240a3b35\n"
".quad 0x200a3a3835303331,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c383531,0x656c6562616c2064,0x5f375f744c242064\n"
".quad 0x2e090a3031343731,0x3109363109636f6c,0x756d090a30093538,0x2509203233662e6c\n"
".quad 0x316625202c383166,0x3b31316625202c32,0x33662e646461090a,0x2c39316625092032\n"
".quad 0x25202c3831662520,0x6461090a3b383166,0x2509203233662e64,0x316625202c313166\n"
".quad 0x3b39316625202c30,0x3109636f6c2e090a,0x0a30093638310936,0x3233662e62757309\n"
".quad 0x202c303266250920,0x6625202c34316625,0x646461090a3b3331,0x662509203233662e\n"
".quad 0x2c396625202c3231,0x090a3b3032662520,0x09363109636f6c2e,0x6d090a3009373831\n"
".quad 0x09203233662e6c75,0x6625202c33316625,0x31316625202c3131,0x09636f6c2e090a3b\n"
".quad 0x3009383831093631,0x33662e6c756d090a,0x2c34316625092032,0x25202c3231662520\n"
".quad 0x6573090a3b323166,0x33732e656e2e7074,0x2c33317025092032,0x25202c3133722520\n"
".quad 0x2540090a3b303572,0x2061726220333170,0x315f375f744c2409,0x4c240a3b30313437\n"
".quad 0x393836315f375f74,0x6557444c240a3a38,0x34315a5f5f69646e,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x5f544b5069507645,0x31535f31535f3153,0x3438315f6962695f\n"
".quad 0x3c2f2f200a3a315f,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c393320656e696c,0x616c206461656820,0x4c242064656c6562,0x393534315f375f74\n"
".quad 0x09636f6c2e090a34,0x0a30093236093731,0x6220357025214009,0x5f744c2409206172\n"
".quad 0x3b34333438315f37,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c39332065,0x6c6562616c206461,0x375f744c24206465\n"
".quad 0x090a34393534315f,0x203233732e766f6d,0x25202c3435722509,0x646c090a3b313372\n"
".quad 0x732e6d617261702e,0x3535722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x6172665f62696969\n"
".quad 0x6f6d090a3b5d656d,0x2509203233732e76,0x0a3b30202c363572,0x71652e7074657309\n"
".quad 0x702509203233732e,0x35357225202c3431,0x0a3b36357225202c,0x2e6f6c2e6c756d09\n"
".quad 0x3572250920323373,0x2c38317225202c37,0x090a3b3632722520,0x203436752e766f6d\n"
".quad 0x5f202c3964722509,0x5f5f5f616475635f,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f31315f37393236,0x736e6f635f6e6f6e,0x303236315f6d5f74,0x2e646461090a3b38\n"
".quad 0x3572250920323373,0x2c37357225202c38,0x090a3b3732722520,0x752e6f6c2e6c756d\n"
".quad 0x3935722509203233,0x202c38357225202c,0x2e646461090a3b34,0x3672250920323373\n"
".quad 0x2c38357225202c30,0x090a3b3133722520,0x752e6f6c2e6c756d,0x3136722509203233\n"
".quad 0x202c30367225202c,0x702e646c090a3b34,0x3436752e6d617261,0x2c30316472250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72\n"
".quad 0x453631694c664933,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x5d7473645f626969,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393320656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34393534315f37,0x3233732e766f6d09,0x202c323672250920\n"
".quad 0x4c240a3b34357225,0x343938315f375f74,0x6c3c2f2f200a3a36,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x202c323620656e69,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x616d69747365202c,0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75\n"
".quad 0x61636f6c2e646c09,0x2509203233732e6c,0x72255b202c333672,0x090a3b5d302b3964\n"
".quad 0x203233752e766f6d,0x30202c3436722509,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x7225202c35317025,0x34367225202c3336,0x3531702540090a3b,0x4c24092061726220\n"
".quad 0x353439315f375f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c323620656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x36343938315f375f,0x3109636f6c2e090a,0x090a300935360937,0x203233732e627573\n"
".quad 0x25202c3536722509,0x367225202c353472,0x2e617262090a3b33,0x744c240920696e75\n"
".quad 0x32303239315f375f,0x5f375f744c240a3b,0x200a3a3835343931,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3236\n"
".quad 0x64656c6562616c20,0x315f375f744c2420,0x6f6d090a36343938,0x2509203233732e76\n"
".quad 0x0a3b30202c353672,0x39315f375f744c24,0x2f2f200a3a323032,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323620656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3938315f375f744c,0x6c2e7473090a3634,0x3233732e6c61636f\n"
".quad 0x2b396472255b0920,0x35367225202c5d30,0x752e766f6d090a3b,0x3636722509203233\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x2c36317025092032,0x25202c3536722520\n"
".quad 0x2540090a3b363672,0x2061726220363170,0x315f375f744c2409,0x2f200a3b30373939\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3620656e696c2079\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x38315f375f744c24,0x6f6c2e090a363439\n"
".quad 0x0930370937310963,0x61702e646c090a30,0x203233732e6d6172,0x5b202c3736722509\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c66,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x74616d696e615f62,0x656d6172466e6f69,0x2e646461090a3b5d\n"
".quad 0x3672250920323373,0x2c37367225202c38,0x090a3b3536722520,0x6c61636f6c2e7473\n"
".quad 0x255b09203233732e,0x202c5d302b396472,0x2e090a3b38367225,0x3709373109636f6c\n"
".quad 0x2e646c090a300931,0x38752e6d61726170,0x202c393672250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x726f6c6f635f6269,0x6d090a3b5d302b73,0x33732e6f6c2e6c75,0x2c30377225092032\n"
".quad 0x25202c3836722520,0x7663090a3b393672,0x3233752e38752e74,0x202c313772250920\n"
".quad 0x2e090a3b30377225,0x3709373109636f6c,0x2e646c090a300932,0x38752e6d61726170\n"
".quad 0x202c323772250920,0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x33316d735f30746f,0x45453631694c6649,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x726f6c6f635f6269,0x6d090a3b5d312b73\n"
".quad 0x33732e6f6c2e6c75,0x2c33377225092032,0x25202c3836722520,0x7663090a3b323772\n"
".quad 0x3233752e38752e74,0x202c343772250920,0x2e090a3b33377225,0x3709373109636f6c\n"
".quad 0x2e646c090a300933,0x38752e6d61726170,0x202c353772250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x726f6c6f635f6269,0x6d090a3b5d322b73,0x33732e6f6c2e6c75,0x2c36377225092032\n"
".quad 0x25202c3836722520,0x7663090a3b353772,0x3233752e38752e74,0x202c373772250920\n"
".quad 0x62090a3b36377225,0x0920696e752e6172,0x39315f375f744c24,0x744c240a3b343137\n"
".quad 0x30373939315f375f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c323620656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a36343938315f37,0x373109636f6c2e09,0x6d090a3009373709,0x09203233752e766f\n"
".quad 0x3b30202c37377225,0x33752e766f6d090a,0x2c34377225092032,0x766f6d090a3b3020\n"
".quad 0x722509203233752e,0x240a3b30202c3137,0x3739315f375f744c,0x3c2f2f200a3a3431\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c323620656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x343938315f375f74,0x752e747663090a36\n"
".quad 0x09203233752e3436,0x25202c3131647225,0x6461090a3b393572,0x2509203436752e64\n"
".quad 0x7225202c32316472,0x647225202c313164,0x252140090a3b3031,0x2061726220343170\n"
".quad 0x325f375f744c2409,0x2f200a3b32383430,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3620656e696c2079,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x38315f375f744c24,0x6f6c2e090a363439,0x0934380937310963,0x752e766f6d090a30\n"
".quad 0x3837722509203233,0x7473090a3b30202c,0x2e6c61626f6c672e,0x5b092038752e3476\n"
".quad 0x5d302b3231647225,0x2c313772257b202c,0x3772252c34377225,0x3b7d383772252c37\n"
".quad 0x6e752e617262090a,0x375f744c24092069,0x0a3b36323230325f,0x30325f375f744c24\n"
".quad 0x2f2f200a3a323834,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323620656e696c20,0x6c2064616568202c,0x242064656c656261,0x3938315f375f744c\n"
".quad 0x636f6c2e090a3634,0x3009383809373109,0x33732e646461090a,0x2c39377225092032\n"
".quad 0x31202c3535722520,0x732e726873090a3b,0x3038722509203233,0x202c39377225202c\n"
".quad 0x766f6d090a3b3133,0x722509203233732e,0x090a3b31202c3138,0x203233622e646e61\n"
".quad 0x25202c3238722509,0x387225202c303872,0x2e646461090a3b31,0x3872250920323373\n"
".quad 0x2c32387225202c33,0x090a3b3937722520,0x203233732e726873,0x25202c3438722509\n"
".quad 0x0a3b31202c333872,0x626f6c672e646c09,0x38752e34762e6c61,0x2c353872257b0920\n"
".quad 0x3872252c36387225,0x255b202c7d5f2c37,0x3b5d302b32316472,0x6f6c2e6c756d090a\n"
".quad 0x722509203233732e,0x35357225202c3838,0x0a3b35387225202c,0x3233732e64646109\n"
".quad 0x202c393872250920,0x7225202c31377225,0x646461090a3b3838,0x722509203233732e\n"
".quad 0x34387225202c3039,0x0a3b39387225202c,0x3233732e76696409,0x202c313972250920\n"
".quad 0x7225202c30397225,0x6f6c2e090a3b3937,0x0939380937310963,0x6c2e6c756d090a30\n"
".quad 0x2509203233732e6f,0x357225202c323972,0x3b36387225202c35,0x33732e646461090a\n"
".quad 0x2c33397225092032,0x25202c3437722520,0x6461090a3b323972,0x2509203233732e64\n"
".quad 0x387225202c343972,0x3b33397225202c34,0x33732e766964090a,0x2c35397225092032\n"
".quad 0x25202c3439722520,0x7473090a3b393772,0x2e6c61626f6c672e,0x5b092038752e3276\n"
".quad 0x5d302b3231647225,0x2c313972257b202c,0x090a3b7d35397225,0x09373109636f6c2e\n"
".quad 0x756d090a30093039,0x3233732e6f6c2e6c,0x202c363972250920,0x7225202c35357225\n"
".quad 0x646461090a3b3738,0x722509203233732e,0x37377225202c3739,0x0a3b36397225202c\n"
".quad 0x3233732e64646109,0x202c383972250920,0x7225202c34387225,0x766964090a3b3739\n"
".quad 0x722509203233732e,0x38397225202c3939,0x0a3b39377225202c,0x626f6c672e747309\n"
".quad 0x5b092038752e6c61,0x5d322b3231647225,0x0a3b39397225202c,0x30325f375f744c24\n"
".quad 0x2f2f200a3a363232,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323620656e696c20,0x6c2064616568202c,0x242064656c656261,0x3938315f375f744c\n"
".quad 0x2e646461090a3634,0x3572250920323375,0x2c39357225202c39,0x646461090a3b3420\n"
".quad 0x722509203436752e,0x39647225202c3964,0x6573090a3b34202c,0x33732e656e2e7074\n"
".quad 0x2c37317025092032,0x25202c3935722520,0x2540090a3b313672,0x2061726220373170\n"
".quad 0x315f375f744c2409,0x4c240a3b36343938,0x333438315f375f74,0x375f744c240a3a34\n"
".quad 0x0a3a30353834315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064,0x5f375f744c242064\n"
".quad 0x2e090a3439353431,0x3909373109636f6c,0x726162090a300935,0x300920636e79732e\n"
".quad 0x752e766f6d090a3b,0x3031722509203233,0x73090a3b30202c30,0x732e71652e707465\n"
".quad 0x3831702509203233,0x25202c377225202c,0x40090a3b30303172,0x6172622038317025\n"
".quad 0x5f375f744c240920,0x200a3b3439393032,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20\n"
".quad 0x315f375f744c2420,0x6c2e090a34393534,0x383909373109636f,0x2e766f6d090a3009\n"
".quad 0x6472250920343675,0x636f6c62202c3331,0x7265746e756f436b,0x752e766f6d090a3b\n"
".quad 0x3031722509203233,0x61090a3b31202c31,0x626f6c672e6d6f74,0x752e6464612e6c61\n"
".quad 0x3031722509203233,0x316472255b202c32,0x30317225202c5d33,0x2e766f6d090a3b31\n"
".quad 0x3172250920323373,0x30317225202c3330,0x732e7473090a3b32,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3236335f7261765f,0x6f6e5f32345f3237\n"
".quad 0x5f74736e6f635f6e,0x646e496b636f6c62,0x317225202c5d7865,0x6f6c2e090a3b3330\n"
".quad 0x0939390937310963,0x61702e646c090a30,0x203233752e6d6172,0x202c343031722509\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x57646972675f6269,0x090a3b5d68746469,0x203233752e6d6572\n"
".quad 0x202c353031722509,0x25202c3330317225,0x73090a3b34303172,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32345f3337323633\n"
".quad 0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x30317225202c5d58,0x636f6c2e090a3b35\n"
".quad 0x0930303109373109,0x752e766964090a30,0x3031722509203233,0x3330317225202c36\n"
".quad 0x3b3430317225202c,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x33373236335f7261,0x5f6e6f6e5f30355f,0x6c625f74736e6f63\n"
".quad 0x25202c5d596b636f,0x4c240a3b36303172,0x393930325f375f74,0x6c3c2f2f200a3a34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34393534315f375f,0x3109636f6c2e090a\n"
".quad 0x0a30093230310937,0x6e79732e72616209,0x6c090a3b30092063,0x6465726168732e64\n"
".quad 0x722509203233752e,0x5f5f5b202c373031,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f32345f32373236,0x736e6f635f6e6f6e,0x496b636f6c625f74,0x090a3b5d7865646e\n"
".quad 0x2e746c2e70746573,0x3170250920323375,0x3730317225202c39,0x0a3b35317225202c\n"
".quad 0x6220393170254009,0x5f744c2409206172,0x3b34393534315f37,0x315f375f744c240a\n"
".quad 0x2e090a3a32383034,0x3109373109636f6c,0x7865090a30093730,0x57444c240a3b7469\n"
".quad 0x36315a5f5f646e65,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x2f207d090a3a6269,0x614d36315a5f202f,0x746f72626c65646e,0x664933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x72746e652e090a0a,0x614d36315a5f2079,0x746f72626c65646e\n"
".quad 0x644933316d735f30,0x507645453631694c,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x62696969695f3053,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6449,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x0a2c7473645f6269,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x0a2c576567616d69,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x0a2c486567616d69,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x0a2c68636e757263,0x6d617261702e0909,0x5f5f203436662e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x09090a2c66664f78,0x2e206d617261702e,0x75635f5f20343666\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x4f795f6269696969,0x702e09090a2c6666,0x36662e206d617261,0x616475635f5f2034\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x2c504a785f626969,0x617261702e09090a,0x5f203436662e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x09090a2c504a795f,0x2e206d617261702e,0x75635f5f20343666,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d,0x6375365076454536\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x63735f6269696969\n"
".quad 0x2e09090a2c656c61,0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331\n"
".quad 0x6863753650764545,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x6c6f635f62696969,0x0a2c5d345b73726f,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x090a2c656d617266,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x615f62696969695f,0x6e6f6974616d696e,0x090a2c656d617246,0x206d617261702e09\n"
".quad 0x635f5f203233732e,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x694c644933316d73,0x7536507645453631,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x675f62696969695f,0x6874646957646972,0x7261702e09090a2c\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4933316d735f3074,0x7645453631694c64,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x6f6c426d756e5f62,0x2e09090a2c736b63\n"
".quad 0x732e206d61726170,0x616475635f5f2038,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c644933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x294a73695f626969,0x65722e090a7b090a\n"
".quad 0x25203233752e2067,0x0a3b3e3930313c72,0x752e206765722e09,0x313c647225203436\n"
".quad 0x65722e090a3b3e35,0x25203436662e2067,0x0a3b3e32323c6466,0x702e206765722e09\n"
".quad 0x323c702520646572,0x68732e090a3b3e31,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x32373236335f7261,0x5f6e6f6e5f32345f,0x6c625f74736e6f63\n"
".quad 0x7865646e496b636f,0x726168732e090a3b,0x203233752e206465,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f33373236335f,0x6f635f6e6f6e5f32,0x636f6c625f74736e\n"
".quad 0x68732e090a3b586b,0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f\n"
".quad 0x33373236335f7261,0x5f6e6f6e5f30355f,0x6c625f74736e6f63,0x2e090a3b596b636f\n"
".quad 0x612e206c61636f6c,0x2e2034206e67696c,0x6475635f5f203862,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x37393236335f7261,0x5f6e6f6e5f31315f,0x5f6d5f74736e6f63\n"
".quad 0x34365b3432343631,0x636f6c2e090a3b5d,0x67696c612e206c61,0x2038622e2038206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x5f365f3639323633\n"
".quad 0x736e6f635f6e6f6e,0x385f736f50785f74,0x3832315b38383430,0x636f6c2e090a3b5d\n"
".quad 0x3009383209373109,0x67656257444c240a,0x4d36315a5f5f6e69,0x6f72626c65646e61\n"
".quad 0x4933316d735f3074,0x7645453631694c64,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x2e766f6d090a3a62,0x3172250920323375\n"
".quad 0x782e64697425202c,0x752e766f6d090a3b,0x2c32722509203233,0x746573090a3b3020\n"
".quad 0x3233752e71652e70,0x25202c3170250920,0x3b327225202c3172,0x33752e766f6d090a\n"
".quad 0x202c337225092032,0x0a3b792e64697425,0x3233752e766f6d09,0x30202c3472250920\n"
".quad 0x2e70746573090a3b,0x09203233752e7165,0x337225202c327025,0x090a3b347225202c\n"
".quad 0x3233732e706c6573,0x31202c3572250920,0x317025202c30202c,0x2e706c6573090a3b\n"
".quad 0x3672250920323373,0x202c30202c31202c,0x6e61090a3b327025,0x2509203233622e64\n"
".quad 0x2c357225202c3772,0x6d090a3b36722520,0x09203233752e766f,0x0a3b30202c387225\n"
".quad 0x71652e7074657309,0x702509203233732e,0x202c377225202c33,0x2540090a3b387225\n"
".quad 0x0920617262203370,0x33315f385f744c24,0x6c2e090a3b303735,0x353309373109636f\n"
".quad 0x2e766f6d090a3009,0x6472250920343675,0x6b636f6c62202c31,0x3b7265746e756f43\n"
".quad 0x33752e766f6d090a,0x202c397225092032,0x6d6f7461090a3b31,0x2e6c61626f6c672e\n"
".quad 0x203233752e646461,0x5b202c3031722509,0x25202c5d31647225,0x766f6d090a3b3972\n"
".quad 0x722509203233732e,0x30317225202c3131,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x373236335f726176,0x6e6f6e5f32345f32\n"
".quad 0x625f74736e6f635f,0x65646e496b636f6c,0x31317225202c5d78,0x09636f6c2e090a3b\n"
".quad 0x0a30093633093731,0x617261702e646c09,0x2509203233752e6d,0x5f5f5b202c323172\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x7464695764697267,0x6d6572090a3b5d68,0x722509203233752e\n"
".quad 0x31317225202c3331,0x0a3b32317225202c,0x726168732e747309,0x09203233752e6465\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f33373236335f72,0x635f6e6f6e5f3234\n"
".quad 0x6f6c625f74736e6f,0x7225202c5d586b63,0x6f6c2e090a3b3331,0x0937330937310963\n"
".quad 0x752e766964090a30,0x3431722509203233,0x202c31317225202c,0x73090a3b32317225\n"
".quad 0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30355f3337323633,0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x34317225202c5d59\n"
".quad 0x5f385f744c240a3b,0x090a3a3037353331,0x09373109636f6c2e,0x6162090a30093933\n"
".quad 0x0920636e79732e72,0x702e646c090a3b30,0x3233752e6d617261,0x202c353172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6449,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6c426d756e5f6269,0x090a3b5d736b636f,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5f5b202c363172,0x636f6c5f61647563,0x335f7261765f6c61\n"
".quad 0x5f32345f32373236,0x736e6f635f6e6f6e,0x496b636f6c625f74,0x090a3b5d7865646e\n"
".quad 0x2e65672e70746573,0x3470250920323375,0x202c36317225202c,0x40090a3b35317225\n"
".quad 0x2061726220347025,0x315f385f744c2409,0x6c090a3b32383034,0x2e6d617261702e64\n"
".quad 0x3172250920323373,0x75635f5f5b202c37,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x31694c644933316d,0x6375365076454536,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6d695f6269696969,0x090a3b5d48656761\n"
".quad 0x6d617261702e646c,0x722509203233732e,0x635f5f5b202c3831,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f\n"
".quad 0x0a3b5d576567616d,0x3233752e766f6d09,0x202c393172250920,0x3b792e6469746e25\n"
".quad 0x33752e766f6d090a,0x2c30327225092032,0x782e6469746e2520,0x752e766f6d090a3b\n"
".quad 0x3264722509203436,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f37393236335f72,0x635f6e6f6e5f3131,0x315f6d5f74736e6f,0x6d090a3b34323436\n"
".quad 0x09203436752e766f,0x5f5f202c33647225,0x635f5f5f61647563,0x61636f6c5f616475\n"
".quad 0x36335f7261765f6c,0x6f6e5f365f363932,0x5f74736e6f635f6e,0x3430385f736f5078\n"
".quad 0x5f744c240a3b3838,0x3a34393534315f38,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x646c090a39332065,0x2e6465726168732e,0x3272250920323375\n"
".quad 0x75635f5f5b202c31,0x6c61636f6c5f6164,0x3236335f7261765f,0x6f6e5f32345f3337\n"
".quad 0x5f74736e6f635f6e,0x3b5d586b636f6c62,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x31327225202c3232,0x0a3b30327225202c,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5f5b202c33327225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30355f3337323633\n"
".quad 0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x6c756d090a3b5d59,0x203233752e6f6c2e\n"
".quad 0x25202c3432722509,0x317225202c333272,0x2e646461090a3b39,0x3272250920323375\n"
".quad 0x2c32327225202c35,0x61090a3b31722520,0x09203233752e6464,0x7225202c36327225\n"
".quad 0x3b337225202c3432,0x6f6c2e6c756d090a,0x722509203233752e,0x35327225202c3732\n"
".quad 0x61090a3b3631202c,0x09203233732e6464,0x7225202c38327225,0x0a3b3631202c3732\n"
".quad 0x3233732e6e696d09,0x202c393272250920,0x7225202c38317225,0x6e696d090a3b3732\n"
".quad 0x722509203233732e,0x38327225202c3033,0x0a3b38317225202c,0x3233732e62757309\n"
".quad 0x202c313372250920,0x7225202c30337225,0x766f6d090a3b3932,0x722509203233732e\n"
".quad 0x090a3b30202c3233,0x2e74672e70746573,0x3570250920323373,0x202c31337225202c\n"
".quad 0x73090a3b32337225,0x203233732e706c65,0x31202c3333722509,0x357025202c30202c\n"
".quad 0x672e746573090a3b,0x33732e3233752e74,0x2c34337225092032,0x25202c3731722520\n"
".quad 0x656e090a3b363272,0x2509203233732e67,0x337225202c353372,0x2e646e61090a3b34\n"
".quad 0x3372250920323362,0x2c33337225202c36,0x090a3b3533722520,0x203233752e766f6d\n"
".quad 0x30202c3733722509,0x2e70746573090a3b,0x09203233732e7165,0x337225202c367025\n"
".quad 0x3b37337225202c36,0x622036702540090a,0x5f744c2409206172,0x3b34333438315f38\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c39332065,0x6c6562616c206461,0x385f744c24206465,0x090a34393534315f\n"
".quad 0x7262203570252140,0x385f744c24092061,0x0a3b38313032325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c393320\n"
".quad 0x656c6562616c2064,0x5f385f744c242064,0x6d090a3439353431,0x09203233732e766f\n"
".quad 0x7225202c38337225,0x6c756d090a3b3133,0x203233752e6f6c2e,0x25202c3933722509\n"
".quad 0x0a3b3631202c3172,0x2e6f6c2e6c756d09,0x3472250920323375,0x2c32327225202c30\n"
".quad 0x6461090a3b363120,0x2509203233732e64,0x337225202c313472,0x3b30347225202c39\n"
".quad 0x36752e766f6d090a,0x2c34647225092034,0x5f616475635f5f20,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x365f36393236335f,0x6e6f635f6e6f6e5f,0x5f736f50785f7473\n"
".quad 0x090a3b3838343038,0x203233732e766f6d,0x25202c3234722509,0x6461090a3b313472\n"
".quad 0x2509203233732e64,0x347225202c333472,0x3b31337225202c31,0x7261702e646c090a\n"
".quad 0x09203436662e6d61,0x5f5b202c31646625,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x0a3b5d66664f785f\n"
".quad 0x617261702e646c09,0x2509203436662e6d,0x5f5f5b202c326466,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x0a3b5d656c616373,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064,0x5f385f744c242064\n"
".quad 0x6d090a3439353431,0x09203233732e766f,0x7225202c34347225,0x5f744c240a3b3833\n"
".quad 0x3a34373835315f38,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x656e202c39332065,0x656420676e697473,0x202c31203a687470,0x6574616d69747365\n"
".quad 0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3509373109636f6c\n"
".quad 0x747663090a300938,0x2e3436662e6e722e,0x6466250920323373,0x3b32347225202c33\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x33646625202c3464,0x202c32646625202c\n"
".quad 0x73090a3b31646625,0x2e6c61636f6c2e74,0x72255b0920343666,0x25202c5d302b3464\n"
".quad 0x6461090a3b346466,0x2509203233732e64,0x347225202c323472,0x61090a3b31202c32\n"
".quad 0x09203436752e6464,0x7225202c34647225,0x090a3b38202c3464,0x2e656e2e70746573\n"
".quad 0x3770250920323373,0x202c32347225202c,0x40090a3b33347225,0x2061726220377025\n"
".quad 0x315f385f744c2409,0x2f200a3b34373835,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3320656e696c2079,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x34315f385f744c24,0x617262090a343935,0x4c240920696e752e,0x363335315f385f74\n"
".quad 0x385f744c240a3b32,0x0a3a38313032325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064\n"
".quad 0x5f385f744c242064,0x6c090a3439353431,0x2e6d617261702e64,0x6466250920343666\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c644933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x63735f6269696969,0x4c240a3b5d656c61,0x363335315f385f74\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x202c393320656e69,0x62616c2064616568,0x744c242064656c65,0x34393534315f385f\n"
".quad 0x3109636f6c2e090a,0x0a30093833310936,0x617261702e646c09,0x2509203233732e6d\n"
".quad 0x5f5f5b202c353472,0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564\n"
".quad 0x4c644933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x3b5d68636e757263,0x33732e766f6d090a\n"
".quad 0x2c36347225092032,0x090a3b3534722520,0x6d617261702e646c,0x347225092038732e\n"
".quad 0x75635f5f5b202c37,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c644933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x73695f6269696969,0x766f6d090a3b5d4a,0x722509203233732e\n"
".quad 0x090a3b30202c3834,0x2e656e2e70746573,0x3870250920323373,0x202c37347225202c\n"
".quad 0x6c090a3b38347225,0x2e6d617261702e64,0x6466250920343666,0x75635f5f5b202c35\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x4f795f6269696969,0x7663090a3b5d6666,0x3436662e6e722e74,0x662509203233732e\n"
".quad 0x36327225202c3664,0x722e64616d090a3b,0x2509203436662e6e,0x646625202c376466\n"
".quad 0x2c32646625202c36,0x090a3b3564662520,0x6c61636f6c2e646c,0x662509203436662e\n"
".quad 0x635f5f5b202c3864,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3236335f7261765f\n"
".quad 0x6e6f6e5f365f3639,0x785f74736e6f635f,0x383430385f736f50,0x40090a3b5d302b38\n"
".quad 0x6172622038702521,0x5f385f744c240920,0x200a3b3234363631,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3933\n"
".quad 0x64656c6562616c20,0x315f385f744c2420,0x6c2e090a34393534,0x343109363109636f\n"
".quad 0x2e646c090a300934,0x36662e6d61726170,0x2c39646625092034,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x5d504a785f626969,0x09636f6c2e090a3b,0x3009353431093631,0x7261702e646c090a\n"
".quad 0x09203436662e6d61,0x5b202c3031646625,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x0a3b5d504a795f62\n"
".quad 0x363109636f6c2e09,0x090a300936343109,0x203436662e766f6d,0x202c313164662509\n"
".quad 0x2e090a3b37646625,0x3109363109636f6c,0x6f6d090a30093734,0x2509203436662e76\n"
".quad 0x6625202c32316466,0x6f6c2e090a3b3864,0x3834310936310963,0x2e6c756d090a3009\n"
".quad 0x6466250920343666,0x37646625202c3331,0x0a3b37646625202c,0x363109636f6c2e09\n"
".quad 0x090a300939343109,0x203436662e6c756d,0x202c343164662509,0x6625202c38646625\n"
".quad 0x617262090a3b3864,0x4c240920696e752e,0x383336315f385f74,0x385f744c240a3b36\n"
".quad 0x0a3a32343636315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064,0x5f385f744c242064\n"
".quad 0x2e090a3439353431,0x3109363109636f6c,0x6f6d090a30093335,0x2509203436662e76\n"
".quad 0x646625202c396466,0x636f6c2e090a3b38,0x0934353109363109,0x662e766f6d090a30\n"
".quad 0x3164662509203436,0x3b37646625202c30,0x3109636f6c2e090a,0x0a30093835310936\n"
".quad 0x3436662e766f6d09,0x2c34316466250920,0x3030303030643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x662e766f6d090a30,0x3164662509203436,0x3030306430202c33\n"
".quad 0x3030303030303030,0x2f093b3030303030,0x766f6d090a30202f,0x662509203436662e\n"
".quad 0x306430202c323164,0x3030303030303030,0x3b30303030303030,0x6d090a30202f2f09\n"
".quad 0x09203436662e766f,0x30202c3131646625,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x36315f385f744c24,0x2f2f200a3a363833,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3534315f385f744c,0x2e766f6d090a3439,0x3472250920323375\n"
".quad 0x73090a3b30202c39,0x732e71652e707465,0x2c39702509203233,0x25202c3133722520\n"
".quad 0x2540090a3b393472,0x0920617262203970,0x36315f385f744c24,0x2f2f200a3b383938\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x393320656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3534315f385f744c,0x2e766f6d090a3439\n"
".quad 0x3572250920323373,0x4c240a3b30202c30,0x313437315f385f74,0x6c3c2f2f200a3a30\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c38353120656e69,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c32,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x0a30093236310936,0x3233732e62757309\n"
".quad 0x202c363472250920,0x3b31202c36347225,0x33752e766f6d090a,0x2c31357225092032\n"
".quad 0x746573090a3b3020,0x3233732e656c2e70,0x202c303170250920,0x7225202c36347225\n"
".quad 0x702540090a3b3135,0x0920617262203031,0x3333315f385f4c24,0x3c2f2f200a3b3431\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x38353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3437315f385f744c,0x2e646461090a3031\n"
".quad 0x6466250920343666,0x31646625202c3531,0x3331646625202c34,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x3130346430202c36,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x746573090a34202f,0x3436662e74672e70,0x202c313170250920,0x25202c3531646625\n"
".quad 0x40090a3b36316466,0x7262203131702521,0x5f385f4c24092061,0x240a3b3835303331\n"
".quad 0x313333315f385f4c,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313437315f385f74,0x09636f6c2e090a30,0x3009333631093631,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x30357225202c3235,0x7663090a3b34202c,0x33752e3436752e74\n"
".quad 0x2c35647225092032,0x090a3b3235722520,0x203436752e646461,0x25202c3664722509\n"
".quad 0x647225202c356472,0x6c2e7473090a3b32,0x3233732e6c61636f,0x2b366472255b0920\n"
".quad 0x36347225202c5d30,0x09636f6c2e090a3b,0x3009353631093631,0x33732e646461090a\n"
".quad 0x2c30357225092032,0x31202c3035722520,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c32317025,0x30357225202c3133,0x3231702540090a3b,0x4c24092061726220\n"
".quad 0x393836315f385f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313437315f385f74,0x6c2e6c756d090a30,0x2509203233752e6f,0x357225202c333572\n"
".quad 0x63090a3b38202c30,0x752e3436752e7476,0x3764722509203233,0x0a3b33357225202c\n"
".quad 0x3436752e64646109,0x202c386472250920,0x7225202c37647225,0x2e646c090a3b3364\n"
".quad 0x36662e6c61636f6c,0x3731646625092034,0x2b386472255b202c,0x252140090a3b5d30\n"
".quad 0x0920617262203870,0x37315f385f744c24,0x2f2f200a3b323239,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x37315f385f744c24,0x6f6c2e090a303134,0x3736310936310963\n"
".quad 0x702e646c090a3009,0x3436662e6d617261,0x202c396466250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6449\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x3b5d504a785f6269,0x3109636f6c2e090a,0x0a30093836310936,0x617261702e646c09\n"
".quad 0x2509203436662e6d,0x5f5b202c30316466,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x090a3b5d504a795f\n"
".quad 0x09363109636f6c2e,0x6d090a3009393631,0x09203436662e766f,0x25202c3131646625\n"
".quad 0x6c2e090a3b376466,0x373109363109636f,0x766f6d090a300930,0x662509203436662e\n"
".quad 0x646625202c323164,0x6f6c2e090a3b3731,0x3137310936310963,0x2e6c756d090a3009\n"
".quad 0x6466250920343666,0x37646625202c3331,0x0a3b37646625202c,0x363109636f6c2e09\n"
".quad 0x090a300932373109,0x203436662e6c756d,0x202c343164662509,0x25202c3731646625\n"
".quad 0x62090a3b37316466,0x0920696e752e6172,0x37315f385f744c24,0x744c240a3b363636\n"
".quad 0x32323937315f385f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c38353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313437315f385f,0x3109636f6c2e090a,0x0a30093537310936,0x3436662e766f6d09\n"
".quad 0x202c396466250920,0x090a3b3731646625,0x09363109636f6c2e,0x6d090a3009363731\n"
".quad 0x09203436662e766f,0x25202c3031646625,0x6c2e090a3b376466,0x383109363109636f\n"
".quad 0x766f6d090a300930,0x662509203436662e,0x306430202c343164,0x3030303030303030\n"
".quad 0x3b30303030303030,0x6d090a30202f2f09,0x09203436662e766f,0x30202c3331646625\n"
".quad 0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30,0x3436662e766f6d09\n"
".quad 0x2c32316466250920,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x662e766f6d090a30,0x3164662509203436,0x3030306430202c31,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x5f744c240a30202f,0x3a36363637315f38,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3835312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a30313437315f38,0x363109636f6c2e09\n"
".quad 0x090a300933383109,0x203233732e766f6d,0x25202c3634722509,0x5f4c240a3b353472\n"
".quad 0x3a38353033315f38,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3835312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30313437315f38,0x363109636f6c2e09,0x090a300935383109,0x203436662e6c756d\n"
".quad 0x202c383164662509,0x25202c3231646625,0x61090a3b31316466,0x09203436662e6464\n"
".quad 0x25202c3931646625,0x6625202c38316466,0x6461090a3b383164,0x2509203436662e64\n"
".quad 0x6625202c31316466,0x646625202c303164,0x6f6c2e090a3b3931,0x3638310936310963\n"
".quad 0x2e627573090a3009,0x6466250920343666,0x31646625202c3032,0x3331646625202c34\n"
".quad 0x662e646461090a3b,0x3164662509203436,0x2c39646625202c32,0x0a3b303264662520\n"
".quad 0x363109636f6c2e09,0x090a300937383109,0x203436662e6c756d,0x202c333164662509\n"
".quad 0x25202c3131646625,0x2e090a3b31316466,0x3109363109636f6c,0x756d090a30093838\n"
".quad 0x2509203436662e6c,0x6625202c34316466,0x646625202c323164,0x746573090a3b3231\n"
".quad 0x3233732e656e2e70,0x202c333170250920,0x7225202c31337225,0x702540090a3b3035\n"
".quad 0x0920617262203331,0x37315f385f744c24,0x744c240a3b303134,0x38393836315f385f\n"
".quad 0x6e6557444c240a3a,0x4334315a5f5f6964,0x65646e614d636c61,0x456449746f72626c\n"
".quad 0x535f544b50695076,0x5f31535f31535f31,0x5f3538315f696269,0x6c3c2f2f200a3a31\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34393534315f385f,0x3109636f6c2e090a\n"
".quad 0x090a300932360937,0x7262203570252140,0x385f744c24092061,0x0a3b34333438315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c393320,0x656c6562616c2064,0x5f385f744c242064,0x6d090a3439353431\n"
".quad 0x09203233732e766f,0x7225202c34357225,0x2e646c090a3b3133,0x33732e6d61726170\n"
".quad 0x2c35357225092032,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c644933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x6d6172665f626969,0x766f6d090a3b5d65\n"
".quad 0x722509203233732e,0x090a3b30202c3635,0x2e71652e70746573,0x3170250920323373\n"
".quad 0x2c35357225202c34,0x090a3b3635722520,0x732e6f6c2e6c756d,0x3735722509203233\n"
".quad 0x202c38317225202c,0x6d090a3b36327225,0x09203436752e766f,0x5f5f202c39647225\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f31315f373932\n"
".quad 0x74736e6f635f6e6f,0x34323436315f6d5f,0x732e646461090a3b,0x3835722509203233\n"
".quad 0x202c37357225202c,0x6d090a3b37327225,0x33752e6f6c2e6c75,0x2c39357225092032\n"
".quad 0x34202c3835722520,0x732e646461090a3b,0x3036722509203233,0x202c38357225202c\n"
".quad 0x6d090a3b31337225,0x33752e6f6c2e6c75,0x2c31367225092032,0x34202c3036722520\n"
".quad 0x61702e646c090a3b,0x203436752e6d6172,0x202c303164722509,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6449\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x3b5d7473645f6269,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c39332065,0x6c6562616c206461,0x385f744c24206465\n"
".quad 0x090a34393534315f,0x203233732e766f6d,0x25202c3236722509,0x744c240a3b343572\n"
".quad 0x36343938315f385f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x6e202c323620656e,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x6c61636f6c2e646c\n"
".quad 0x722509203233732e,0x6472255b202c3336,0x6d090a3b5d302b39,0x09203233752e766f\n"
".quad 0x3b30202c34367225,0x6c2e70746573090a,0x2509203233732e65,0x367225202c353170\n"
".quad 0x3b34367225202c33,0x203531702540090a,0x744c240920617262,0x38353439315f385f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c323620656e,0x6562616c20646165,0x5f744c242064656c,0x0a36343938315f38\n"
".quad 0x373109636f6c2e09,0x73090a3009353609,0x09203233732e6275,0x7225202c35367225\n"
".quad 0x33367225202c3534,0x752e617262090a3b,0x5f744c240920696e,0x3b32303239315f38\n"
".quad 0x315f385f744c240a,0x2f200a3a38353439,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3620656e696c2079,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x38315f385f744c24,0x766f6d090a363439,0x722509203233732e,0x240a3b30202c3536\n"
".quad 0x3239315f385f744c,0x3c2f2f200a3a3230,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c323620656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x343938315f385f74,0x6f6c2e7473090a36,0x203233732e6c6163,0x302b396472255b09\n"
".quad 0x3b35367225202c5d,0x33752e766f6d090a,0x2c36367225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c363170250920,0x7225202c35367225,0x702540090a3b3636\n"
".quad 0x0920617262203631,0x39315f385f744c24,0x2f2f200a3b303739,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x323620656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3938315f385f744c,0x636f6c2e090a3634,0x3009303709373109\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c37367225,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x6974616d696e615f,0x5d656d6172466e6f,0x732e646461090a3b,0x3836722509203233\n"
".quad 0x202c37367225202c,0x73090a3b35367225,0x2e6c61636f6c2e74,0x72255b0920323373\n"
".quad 0x25202c5d302b3964,0x6c2e090a3b383672,0x313709373109636f,0x702e646c090a3009\n"
".quad 0x2038752e6d617261,0x5b202c3936722509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x73726f6c6f635f62\n"
".quad 0x756d090a3b5d302b,0x3233732e6f6c2e6c,0x202c303772250920,0x7225202c38367225\n"
".quad 0x747663090a3b3936,0x203233752e38752e,0x25202c3137722509,0x6c2e090a3b303772\n"
".quad 0x323709373109636f,0x702e646c090a3009,0x2038752e6d617261,0x5b202c3237722509\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c64,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x73726f6c6f635f62,0x756d090a3b5d312b,0x3233732e6f6c2e6c\n"
".quad 0x202c333772250920,0x7225202c38367225,0x747663090a3b3237,0x203233752e38752e\n"
".quad 0x25202c3437722509,0x6c2e090a3b333772,0x333709373109636f,0x702e646c090a3009\n"
".quad 0x2038752e6d617261,0x5b202c3537722509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x73726f6c6f635f62\n"
".quad 0x756d090a3b5d322b,0x3233732e6f6c2e6c,0x202c363772250920,0x7225202c38367225\n"
".quad 0x747663090a3b3537,0x203233752e38752e,0x25202c3737722509,0x7262090a3b363772\n"
".quad 0x240920696e752e61,0x3739315f385f744c,0x5f744c240a3b3431,0x3a30373939315f38\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c32362065,0x6c6562616c206461,0x385f744c24206465,0x090a36343938315f\n"
".quad 0x09373109636f6c2e,0x6f6d090a30093737,0x2509203233752e76,0x0a3b30202c373772\n"
".quad 0x3233752e766f6d09,0x202c343772250920,0x2e766f6d090a3b30,0x3772250920323375\n"
".quad 0x4c240a3b30202c31,0x313739315f385f74,0x6c3c2f2f200a3a34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c323620656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x36343938315f385f,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c31316472,0x646461090a3b3935,0x722509203436752e,0x647225202c323164\n"
".quad 0x31647225202c3131,0x70252140090a3b30,0x0920617262203431,0x30325f385f744c24\n"
".quad 0x2f2f200a3b323834,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323620656e696c20,0x6c2064616568202c,0x242064656c656261,0x3938315f385f744c\n"
".quad 0x636f6c2e090a3634,0x3009343809373109,0x33752e766f6d090a,0x2c38377225092032\n"
".quad 0x2e7473090a3b3020,0x762e6c61626f6c67,0x255b092038752e34,0x2c5d302b32316472\n"
".quad 0x252c313772257b20,0x373772252c343772,0x0a3b7d383772252c,0x696e752e61726209\n"
".quad 0x5f385f744c240920,0x240a3b3632323032,0x3430325f385f744c,0x3c2f2f200a3a3238\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c323620656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x343938315f385f74,0x09636f6c2e090a36\n"
".quad 0x0a30093838093731,0x3233732e64646109,0x202c393772250920,0x3b31202c35357225\n"
".quad 0x33732e726873090a,0x2c30387225092032,0x33202c3937722520,0x2e766f6d090a3b31\n"
".quad 0x3872250920323373,0x61090a3b31202c31,0x09203233622e646e,0x7225202c32387225\n"
".quad 0x31387225202c3038,0x732e646461090a3b,0x3338722509203233,0x202c32387225202c\n"
".quad 0x73090a3b39377225,0x09203233732e7268,0x7225202c34387225,0x090a3b31202c3338\n"
".quad 0x61626f6c672e646c,0x2038752e34762e6c,0x252c353872257b09,0x373872252c363872\n"
".quad 0x72255b202c7d5f2c,0x0a3b5d302b323164,0x2e6f6c2e6c756d09,0x3872250920323373\n"
".quad 0x2c35357225202c38,0x090a3b3538722520,0x203233732e646461,0x25202c3938722509\n"
".quad 0x387225202c313772,0x2e646461090a3b38,0x3972250920323373,0x2c34387225202c30\n"
".quad 0x090a3b3938722520,0x203233732e766964,0x25202c3139722509,0x377225202c303972\n"
".quad 0x636f6c2e090a3b39,0x3009393809373109,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x35357225202c3239,0x0a3b36387225202c,0x3233732e64646109,0x202c333972250920\n"
".quad 0x7225202c34377225,0x646461090a3b3239,0x722509203233732e,0x34387225202c3439\n"
".quad 0x0a3b33397225202c,0x3233732e76696409,0x202c353972250920,0x7225202c34397225\n"
".quad 0x2e7473090a3b3937,0x762e6c61626f6c67,0x255b092038752e32,0x2c5d302b32316472\n"
".quad 0x252c313972257b20,0x2e090a3b7d353972,0x3909373109636f6c,0x6c756d090a300930\n"
".quad 0x203233732e6f6c2e,0x25202c3639722509,0x387225202c353572,0x2e646461090a3b37\n"
".quad 0x3972250920323373,0x2c37377225202c37,0x090a3b3639722520,0x203233732e646461\n"
".quad 0x25202c3839722509,0x397225202c343872,0x2e766964090a3b37,0x3972250920323373\n"
".quad 0x2c38397225202c39,0x090a3b3937722520,0x61626f6c672e7473,0x255b092038752e6c\n"
".quad 0x2c5d322b32316472,0x240a3b3939722520,0x3230325f385f744c,0x3c2f2f200a3a3632\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c323620656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x343938315f385f74,0x752e646461090a36\n"
".quad 0x3935722509203233,0x202c39357225202c,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x2c39647225202c39,0x746573090a3b3420,0x3233732e656e2e70,0x202c373170250920\n"
".quad 0x7225202c39357225,0x702540090a3b3136,0x0920617262203731,0x38315f385f744c24\n"
".quad 0x744c240a3b363439,0x34333438315f385f,0x5f385f744c240a3a,0x200a3a3035383431\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3933,0x64656c6562616c20,0x315f385f744c2420,0x6c2e090a34393534\n"
".quad 0x353909373109636f,0x2e726162090a3009,0x3b300920636e7973,0x33752e766f6d090a\n"
".quad 0x3030317225092032,0x6573090a3b30202c,0x33732e71652e7074,0x2c38317025092032\n"
".quad 0x7225202c37722520,0x2540090a3b303031,0x2061726220383170,0x325f385f744c2409\n"
".quad 0x2f200a3b34393930,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3320656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x34315f385f744c24\n"
".quad 0x6f6c2e090a343935,0x0938390937310963,0x752e766f6d090a30,0x3164722509203436\n"
".quad 0x6b636f6c62202c33,0x3b7265746e756f43,0x33752e766f6d090a,0x3130317225092032\n"
".quad 0x7461090a3b31202c,0x61626f6c672e6d6f,0x33752e6464612e6c,0x3230317225092032\n"
".quad 0x33316472255b202c,0x3130317225202c5d,0x732e766f6d090a3b,0x3031722509203233\n"
".quad 0x3230317225202c33,0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920\n"
".quad 0x5f6c61636f6c5f61,0x373236335f726176,0x6e6f6e5f32345f32,0x625f74736e6f635f\n"
".quad 0x65646e496b636f6c,0x30317225202c5d78,0x636f6c2e090a3b33,0x3009393909373109\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5b202c3430317225,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x6957646972675f62,0x72090a3b5d687464,0x09203233752e6d65,0x25202c3530317225\n"
".quad 0x7225202c33303172,0x7473090a3b343031,0x2e6465726168732e,0x5f5f5b0920323375\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f32345f33373236,0x736e6f635f6e6f6e\n"
".quad 0x586b636f6c625f74,0x3530317225202c5d,0x09636f6c2e090a3b,0x3009303031093731\n"
".quad 0x33752e766964090a,0x3630317225092032,0x2c3330317225202c,0x0a3b343031722520\n"
".quad 0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f33373236335f72,0x635f6e6f6e5f3035,0x6f6c625f74736e6f,0x7225202c5d596b63\n"
".quad 0x744c240a3b363031,0x34393930325f385f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393320656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34393534315f38,0x373109636f6c2e09,0x090a300932303109\n"
".quad 0x636e79732e726162,0x646c090a3b300920,0x2e6465726168732e,0x3172250920323375\n"
".quad 0x635f5f5b202c3730,0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f32345f323732\n"
".quad 0x74736e6f635f6e6f,0x6e496b636f6c625f,0x73090a3b5d786564,0x752e746c2e707465\n"
".quad 0x3931702509203233,0x2c3730317225202c,0x090a3b3531722520,0x7262203931702540\n"
".quad 0x385f744c24092061,0x0a3b34393534315f,0x34315f385f744c24,0x6c2e090a3a323830\n"
".quad 0x303109373109636f,0x697865090a300937,0x6557444c240a3b74,0x4d36315a5f5f646e\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x2f2f207d090a3a62\n"
".quad 0x6e614d36315a5f20,0x30746f72626c6564,0x4c644933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x0a62696969695f30\n"
".quad 0x7972746e652e090a,0x6e614d36315a5f20,0x31746f72626c6564,0x45664933316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x2e09090a28206269,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x2e09090a2c747364\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x0a2c576567616d69,0x6d617261702e0909\n"
".quad 0x5f5f203233732e20,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45664933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6567616d695f6269,0x61702e09090a2c48,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f\n"
".quad 0x6375365076456649,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x72635f6269696969,0x09090a2c68636e75,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x090a2c66664f785f,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645664933316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x0a2c66664f795f62\n"
".quad 0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x31746f72626c6564,0x45664933316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x0a2c504a785f6269,0x6d617261702e0909\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45664933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x0a2c504a795f6269,0x6d617261702e0909,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564,0x45664933316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x656c6163735f6269,0x7261702e09090a2c,0x67696c612e206d61,0x2038622e2034206e\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174\n"
".quad 0x6863753650764566,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x6c6f635f62696969,0x0a2c5d345b73726f,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564,0x45664933316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x656d6172665f6269,0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764566\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x696e615f62696969\n"
".quad 0x72466e6f6974616d,0x2e09090a2c656d61,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x7464695764697267,0x61702e09090a2c68,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x756e5f6269696969\n"
".quad 0x2c736b636f6c426d,0x617261702e09090a,0x5f5f2038732e206d,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x31746f72626c6564,0x45664933316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x0a294a73695f6269\n"
".quad 0x6765722e090a7b09,0x7225203233752e20,0x090a3b3e3837313c,0x36752e206765722e\n"
".quad 0x31313c6472252034,0x6765722e090a3b3e,0x6625203233662e20,0x2e090a3b3e34323c\n"
".quad 0x6572702e20676572,0x3e31323c70252064,0x726168732e090a3b,0x203233752e206465\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f33333436335f,0x6f635f6e6f6e5f32\n"
".quad 0x636f6c625f74736e,0x0a3b7865646e496b,0x6465726168732e09,0x5f5f203233752e20\n"
".quad 0x636f6c5f61647563,0x335f7261765f6c61,0x5f32345f34333436,0x736e6f635f6e6f6e\n"
".quad 0x586b636f6c625f74,0x726168732e090a3b,0x203233752e206465,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x355f34333436335f,0x6f635f6e6f6e5f30,0x636f6c625f74736e\n"
".quad 0x6f6c2e090a3b596b,0x3938310937310963,0x6257444c240a3009,0x315a5f5f6e696765\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x0a3a62696969695f,0x3233752e766f6d09\n"
".quad 0x25202c3172250920,0x090a3b782e646974,0x203233752e766f6d,0x3b30202c32722509\n"
".quad 0x652e70746573090a,0x2509203233752e71,0x2c317225202c3170,0x6d090a3b32722520\n"
".quad 0x09203233752e766f,0x697425202c337225,0x6f6d090a3b792e64,0x2509203233752e76\n"
".quad 0x090a3b30202c3472,0x2e71652e70746573,0x3270250920323375,0x25202c337225202c\n"
".quad 0x6c6573090a3b3472,0x2509203233732e70,0x30202c31202c3572,0x090a3b317025202c\n"
".quad 0x3233732e706c6573,0x31202c3672250920,0x327025202c30202c,0x622e646e61090a3b\n"
".quad 0x2c37722509203233,0x7225202c35722520,0x2e766f6d090a3b36,0x3872250920323375\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x202c337025092032,0x387225202c377225\n"
".quad 0x2033702540090a3b,0x744c240920617262,0x34353137315f395f,0x09636f6c2e090a3b\n"
".quad 0x3009363931093731,0x36752e766f6d090a,0x2c31647225092034,0x6f436b636f6c6220\n"
".quad 0x090a3b7265746e75,0x203233752e766f6d,0x3b31202c39722509,0x672e6d6f7461090a\n"
".quad 0x64612e6c61626f6c,0x2509203233752e64,0x72255b202c303172,0x397225202c5d3164\n"
".quad 0x732e766f6d090a3b,0x3131722509203233,0x0a3b30317225202c,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f33333436335f72\n"
".quad 0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x5d7865646e496b63,0x0a3b31317225202c\n"
".quad 0x373109636f6c2e09,0x090a300937393109,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3231,0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65\n"
".quad 0x7645664933316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x6957646972675f62,0x72090a3b5d687464,0x09203233752e6d65\n"
".quad 0x7225202c33317225,0x32317225202c3131,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x333436335f726176,0x6e6f6e5f32345f34\n"
".quad 0x625f74736e6f635f,0x202c5d586b636f6c,0x2e090a3b33317225,0x3109373109636f6c\n"
".quad 0x6964090a30093839,0x2509203233752e76,0x317225202c343172,0x3b32317225202c31\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x34333436335f7261,0x5f6e6f6e5f30355f,0x6c625f74736e6f63,0x25202c5d596b636f\n"
".quad 0x744c240a3b343172,0x34353137315f395f,0x09636f6c2e090a3a,0x3009313032093731\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3531,0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65\n"
".quad 0x7645664933316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x6f6c426d756e5f62,0x6c090a3b5d736b63,0x6465726168732e64\n"
".quad 0x722509203233752e,0x635f5f5b202c3631,0x61636f6c5f616475,0x36335f7261765f6c\n"
".quad 0x6e5f32345f333334,0x74736e6f635f6e6f,0x6e496b636f6c625f,0x73090a3b5d786564\n"
".quad 0x752e65672e707465,0x2c34702509203233,0x25202c3631722520,0x2540090a3b353172\n"
".quad 0x0920617262203470,0x37315f395f744c24,0x646c090a3b363636,0x732e6d617261702e\n"
".quad 0x3731722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x3b5d486567616d69,0x7261702e646c090a\n"
".quad 0x09203233732e6d61,0x5f5b202c38317225,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x67616d695f626969,0x6f6d090a3b5d5765\n"
".quad 0x2509203233752e76,0x746e25202c393172,0x6d090a3b792e6469,0x09203233752e766f\n"
".quad 0x6e25202c30327225,0x240a3b782e646974,0x3138315f395f744c,0x3c2f2f200a3a3837\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x31303220656e696c,0x6168732e646c090a\n"
".quad 0x203233752e646572,0x5b202c3132722509,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f34333436335f,0x6f635f6e6f6e5f32,0x636f6c625f74736e,0x756d090a3b5d586b\n"
".quad 0x3233752e6f6c2e6c,0x202c323272250920,0x7225202c31327225,0x2e646c090a3b3032\n"
".quad 0x752e646572616873,0x3332722509203233,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x333436335f726176,0x6e6f6e5f30355f34,0x625f74736e6f635f,0x0a3b5d596b636f6c\n"
".quad 0x2e6f6c2e6c756d09,0x3272250920323375,0x2c33327225202c34,0x090a3b3931722520\n"
".quad 0x203233752e646461,0x25202c3532722509,0x317225202c323272,0x752e646461090a3b\n"
".quad 0x3632722509203233,0x202c34327225202c,0x6573090a3b337225,0x3233752e74672e74\n"
".quad 0x722509203233732e,0x37317225202c3732,0x0a3b36327225202c,0x3233732e67656e09\n"
".quad 0x202c383272250920,0x73090a3b37327225,0x33752e74672e7465,0x2509203233732e32\n"
".quad 0x317225202c393272,0x3b35327225202c38,0x33732e67656e090a,0x2c30337225092032\n"
".quad 0x090a3b3932722520,0x203233622e646e61,0x25202c3133722509,0x337225202c383272\n"
".quad 0x2e766f6d090a3b30,0x3372250920323375,0x73090a3b30202c32,0x732e71652e707465\n"
".quad 0x2c35702509203233,0x25202c3133722520,0x2540090a3b323372,0x0920617262203570\n"
".quad 0x30325f395f744c24,0x2f2f200a3b343939,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31,0x2064656c6562616c\n"
".quad 0x38315f395f744c24,0x6f6c2e090a383731,0x3331320937310963,0x2e6c756d090a3009\n"
".quad 0x09203233732e6f6c,0x7225202c33337225,0x36327225202c3831,0x732e646461090a3b\n"
".quad 0x3433722509203233,0x202c33337225202c,0x6c090a3b35327225,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x75635f5f5b202c32,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f31746f72626c,0x507645664933316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x62696969695f3053,0x090a3b5d7473645f,0x752e6f6c2e6c756d\n"
".quad 0x3533722509203233,0x202c34337225202c,0x2e747663090a3b34,0x203233752e343675\n"
".quad 0x25202c3364722509,0x6461090a3b353372,0x2509203436752e64,0x647225202c346472\n"
".quad 0x3b32647225202c33,0x6f6c672e646c090a,0x752e34762e6c6162,0x363372257b092038\n"
".quad 0x72252c373372252c,0x5b202c7d5f2c3833,0x3b5d302b34647225,0x33752e766f6d090a\n"
".quad 0x2c39337225092032,0x746573090a3b3020,0x3233732e656c2e70,0x25202c3670250920\n"
".quad 0x337225202c353272,0x36702540090a3b39,0x4c24092061726220,0x303239315f395f74\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562,0x373138315f395f74\n"
".quad 0x6c672e646c090a38,0x2e34762e6c61626f,0x3472257b09203875,0x252c313472252c30\n"
".quad 0x202c7d5f2c323472,0x342d2b346472255b,0x636f6c2e090a3b5d,0x0938313209373109\n"
".quad 0x732e627573090a30,0x3334722509203233,0x202c32347225202c,0x61090a3b38337225\n"
".quad 0x09203233732e7362,0x7225202c34347225,0x766f6d090a3b3334,0x722509203233732e\n"
".quad 0x0a3b3031202c3534,0x2e74672e74657309,0x203233732e323375,0x25202c3634722509\n"
".quad 0x347225202c343472,0x2e67656e090a3b35,0x3472250920323373,0x3b36347225202c37\n"
".quad 0x33732e627573090a,0x2c38347225092032,0x25202c3034722520,0x6261090a3b363372\n"
".quad 0x2509203233732e73,0x347225202c393472,0x2e766f6d090a3b38,0x3572250920323373\n"
".quad 0x090a3b3031202c30,0x752e74672e746573,0x09203233732e3233,0x7225202c31357225\n"
".quad 0x30357225202c3934,0x732e67656e090a3b,0x3235722509203233,0x0a3b31357225202c\n"
".quad 0x3233732e62757309,0x202c333572250920,0x7225202c31347225,0x736261090a3b3733\n"
".quad 0x722509203233732e,0x33357225202c3435,0x732e766f6d090a3b,0x3535722509203233\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x357225202c363572\n"
".quad 0x3b35357225202c34,0x33732e67656e090a,0x2c37357225092032,0x090a3b3635722520\n"
".quad 0x09203233622e726f,0x7225202c38357225,0x37357225202c3235,0x33622e726f090a3b\n"
".quad 0x2c39357225092032,0x25202c3734722520,0x7262090a3b383572,0x240920696e752e61\n"
".quad 0x3938315f395f744c,0x5f744c240a3b3634,0x3a32303239315f39,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3130322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f39,0x3233732e766f6d09\n"
".quad 0x202c393572250920,0x395f744c240a3b30,0x0a3a36343938315f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220\n"
".quad 0x6c6562616c206461,0x395f744c24206465,0x090a38373138315f,0x203233732e646461\n"
".quad 0x25202c3036722509,0x0a3b31202c353272,0x656c2e7074657309,0x702509203233732e\n"
".quad 0x2c38317225202c37,0x090a3b3036722520,0x6172622037702540,0x5f395f744c240920\n"
".quad 0x200a3b3835343931,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313032,0x656c6562616c2064,0x5f395f744c242064\n"
".quad 0x6c090a3837313831,0x6c61626f6c672e64,0x092038752e34762e,0x72252c313672257b\n"
".quad 0x2c333672252c3236,0x6472255b202c7d5f,0x2e090a3b5d342b34,0x3209373109636f6c\n"
".quad 0x7573090a30093032,0x2509203233732e62,0x367225202c343672,0x3b38337225202c33\n"
".quad 0x33732e736261090a,0x2c35367225092032,0x090a3b3436722520,0x203233732e766f6d\n"
".quad 0x31202c3636722509,0x2e746573090a3b30,0x732e3233752e7467,0x3736722509203233\n"
".quad 0x202c35367225202c,0x6e090a3b36367225,0x09203233732e6765,0x7225202c38367225\n"
".quad 0x627573090a3b3736,0x722509203233732e,0x31367225202c3936,0x0a3b36337225202c\n"
".quad 0x3233732e73626109,0x202c303772250920,0x6d090a3b39367225,0x09203233732e766f\n"
".quad 0x3031202c31377225,0x672e746573090a3b,0x33732e3233752e74,0x2c32377225092032\n"
".quad 0x25202c3037722520,0x656e090a3b313772,0x2509203233732e67,0x377225202c333772\n"
".quad 0x2e627573090a3b32,0x3772250920323373,0x2c32367225202c34,0x090a3b3733722520\n"
".quad 0x203233732e736261,0x25202c3537722509,0x6f6d090a3b343772,0x2509203233732e76\n"
".quad 0x3b3031202c363772,0x74672e746573090a,0x3233732e3233752e,0x202c373772250920\n"
".quad 0x7225202c35377225,0x67656e090a3b3637,0x722509203233732e,0x37377225202c3837\n"
".quad 0x33622e726f090a3b,0x2c39377225092032,0x25202c3337722520,0x726f090a3b383772\n"
".quad 0x722509203233622e,0x38367225202c3038,0x0a3b39377225202c,0x3233732e64646109\n"
".quad 0x202c393572250920,0x7225202c39357225,0x5f744c240a3b3038,0x3a38353439315f39\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f39\n"
".quad 0x3233752e766f6d09,0x202c313872250920,0x70746573090a3b30,0x203233732e656c2e\n"
".quad 0x7225202c38702509,0x31387225202c3632,0x2038702540090a3b,0x744c240920617262\n"
".quad 0x30373939315f395f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38373138315f395f,0x3109636f6c2e090a,0x0a30093232320937,0x3233732e62757309\n"
".quad 0x202c323872250920,0x7225202c34337225,0x6c756d090a3b3831,0x203233752e6f6c2e\n"
".quad 0x25202c3338722509,0x0a3b34202c323872,0x3436752e74766309,0x722509203233752e\n"
".quad 0x33387225202c3564,0x752e646461090a3b,0x3664722509203436,0x202c35647225202c\n"
".quad 0x6c090a3b32647225,0x6c61626f6c672e64,0x092038752e34762e,0x72252c343872257b\n"
".quad 0x2c363872252c3538,0x6472255b202c7d5f,0x73090a3b5d302b36,0x09203233732e6275\n"
".quad 0x7225202c37387225,0x38337225202c3638,0x732e736261090a3b,0x3838722509203233\n"
".quad 0x0a3b37387225202c,0x3233732e766f6d09,0x202c393872250920,0x746573090a3b3031\n"
".quad 0x2e3233752e74672e,0x3972250920323373,0x2c38387225202c30,0x090a3b3938722520\n"
".quad 0x203233732e67656e,0x25202c3139722509,0x7573090a3b303972,0x2509203233732e62\n"
".quad 0x387225202c323972,0x3b36337225202c34,0x33732e736261090a,0x2c33397225092032\n"
".quad 0x090a3b3239722520,0x203233732e766f6d,0x31202c3439722509,0x2e746573090a3b30\n"
".quad 0x732e3233752e7467,0x3539722509203233,0x202c33397225202c,0x6e090a3b34397225\n"
".quad 0x09203233732e6765,0x7225202c36397225,0x627573090a3b3539,0x722509203233732e\n"
".quad 0x35387225202c3739,0x0a3b37337225202c,0x3233732e73626109,0x202c383972250920\n"
".quad 0x6d090a3b37397225,0x09203233732e766f,0x3031202c39397225,0x672e746573090a3b\n"
".quad 0x33732e3233752e74,0x3030317225092032,0x202c38397225202c,0x6e090a3b39397225\n"
".quad 0x09203233732e6765,0x25202c3130317225,0x6f090a3b30303172,0x2509203233622e72\n"
".quad 0x7225202c32303172,0x30317225202c3639,0x622e726f090a3b31,0x3031722509203233\n"
".quad 0x2c31397225202c33,0x0a3b323031722520,0x3233732e64646109,0x202c393572250920\n"
".quad 0x7225202c39357225,0x744c240a3b333031,0x30373939315f395f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x38373138315f395f,0x33732e646461090a\n"
".quad 0x3430317225092032,0x202c36327225202c,0x70746573090a3b31,0x203233732e656c2e\n"
".quad 0x7225202c39702509,0x30317225202c3731,0x39702540090a3b34,0x4c24092061726220\n"
".quad 0x383430325f395f74,0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x373138315f395f74,0x09636f6c2e090a38,0x3009343232093731,0x33732e646461090a\n"
".quad 0x3530317225092032,0x202c34337225202c,0x6d090a3b38317225,0x33752e6f6c2e6c75\n"
".quad 0x3630317225092032,0x2c3530317225202c,0x747663090a3b3420,0x3233752e3436752e\n"
".quad 0x202c376472250920,0x090a3b3630317225,0x203436752e646461,0x25202c3864722509\n"
".quad 0x647225202c376472,0x672e646c090a3b32,0x34762e6c61626f6c,0x72257b092038752e\n"
".quad 0x303172252c373031,0x2c39303172252c38,0x6472255b202c7d5f,0x73090a3b5d302b38\n"
".quad 0x09203233732e6275,0x25202c3031317225,0x7225202c39303172,0x736261090a3b3833\n"
".quad 0x722509203233732e,0x317225202c313131,0x766f6d090a3b3031,0x722509203233732e\n"
".quad 0x3b3031202c323131,0x74672e746573090a,0x3233732e3233752e,0x2c33313172250920\n"
".quad 0x202c313131722520,0x090a3b3231317225,0x203233732e67656e,0x202c343131722509\n"
".quad 0x090a3b3331317225,0x203233732e627573,0x202c353131722509,0x25202c3730317225\n"
".quad 0x6261090a3b363372,0x2509203233732e73,0x7225202c36313172,0x6f6d090a3b353131\n"
".quad 0x2509203233732e76,0x3031202c37313172,0x672e746573090a3b,0x33732e3233752e74\n"
".quad 0x3831317225092032,0x2c3631317225202c,0x0a3b373131722520,0x3233732e67656e09\n"
".quad 0x2c39313172250920,0x0a3b383131722520,0x3233732e62757309,0x2c30323172250920\n"
".quad 0x202c383031722520,0x61090a3b37337225,0x09203233732e7362,0x25202c3132317225\n"
".quad 0x6d090a3b30323172,0x09203233732e766f,0x31202c3232317225,0x2e746573090a3b30\n"
".quad 0x732e3233752e7467,0x3231722509203233,0x3132317225202c33,0x3b3232317225202c\n"
".quad 0x33732e67656e090a,0x3432317225092032,0x3b3332317225202c,0x3233622e726f090a\n"
".quad 0x2c35323172250920,0x202c393131722520,0x090a3b3432317225,0x09203233622e726f\n"
".quad 0x25202c3632317225,0x7225202c34313172,0x6461090a3b353231,0x2509203233732e64\n"
".quad 0x357225202c393572,0x3632317225202c39,0x5f395f744c240a3b,0x200a3a3238343032\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313032,0x656c6562616c2064,0x5f395f744c242064,0x6d090a3837313831\n"
".quad 0x09203233752e766f,0x30202c3732317225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c30317025,0x32317225202c3935,0x31702540090a3b37,0x2409206172622030\n"
".quad 0x3930325f395f744c,0x3c2f2f200a3b3439,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x31303220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138315f395f744c,0x636f6c2e090a3837,0x0931333209373109,0x722e747663090a30\n"
".quad 0x33732e3233662e6e,0x202c316625092032,0x63090a3b35327225,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x36327225202c3266,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c33662509,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x664933316d735f31,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x6c6163735f626969,0x2e646c090a3b5d65,0x33662e6d61726170\n"
".quad 0x202c346625092032,0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x33316d735f31746f,0x6375365076456649,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x4f785f6269696969,0x6d66090a3b5d6666,0x3233662e6e722e61\n"
".quad 0x25202c3566250920,0x2c336625202c3166,0x6c090a3b34662520,0x2e6d617261702e64\n"
".quad 0x3666250920323366,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x090a3b5d66664f79,0x662e6e722e616d66\n"
".quad 0x2c37662509203233,0x6625202c32662520,0x0a3b366625202c33,0x617261702e646c09\n"
".quad 0x7225092038732e6d,0x5f5f5b202c383231,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x31746f72626c6564,0x45664933316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x3b5d4a73695f6269,0x33752e766f6d090a\n"
".quad 0x3932317225092032,0x6573090a3b30202c,0x33732e71652e7074,0x2c31317025092032\n"
".quad 0x202c383231722520,0x090a3b3932317225,0x7262203131702540,0x395f744c24092061\n"
".quad 0x0a3b32363731325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461,0x395f744c24206465\n"
".quad 0x090a38373138315f,0x09363109636f6c2e,0x6c090a3009353032,0x2e6d617261702e64\n"
".quad 0x3866250920323366,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x2e090a3b5d504a78,0x3209363109636f6c\n"
".quad 0x646c090a30093630,0x662e6d617261702e,0x2c39662509203233,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x795f62696969695f\n"
".quad 0x6c2e090a3b5d504a,0x303209363109636f,0x766f6d090a300937,0x662509203233662e\n"
".quad 0x3b376625202c3031,0x3109636f6c2e090a,0x0a30093830320936,0x3233662e766f6d09\n"
".quad 0x202c313166250920,0x6c2e090a3b356625,0x303209363109636f,0x6c756d090a300939\n"
".quad 0x662509203233662e,0x2c376625202c3231,0x2e090a3b37662520,0x3209363109636f6c\n"
".quad 0x756d090a30093031,0x2509203233662e6c,0x356625202c333166,0x090a3b356625202c\n"
".quad 0x20696e752e617262,0x325f395f744c2409,0x4c240a3b36303531,0x363731325f395f74\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562,0x373138315f395f74\n"
".quad 0x09636f6c2e090a38,0x3009343132093631,0x33662e766f6d090a,0x202c386625092032\n"
".quad 0x6c2e090a3b356625,0x313209363109636f,0x766f6d090a300935,0x662509203233662e\n"
".quad 0x0a3b376625202c39,0x363109636f6c2e09,0x090a300939313209,0x203233662e766f6d\n"
".quad 0x30202c3331662509,0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x30306630202c3231,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x2c31316625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6630202c30316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x395f744c240a3020,0x0a3a36303531325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220\n"
".quad 0x6c6562616c206461,0x395f744c24206465,0x090a38373138315f,0x09363109636f6c2e\n"
".quad 0x6c090a3009333232,0x2e6d617261702e64,0x3172250920323373,0x635f5f5b202c3033\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645664933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x68636e7572635f62,0x2e627573090a3b5d,0x3172250920323373,0x33317225202c3133\n"
".quad 0x6d090a3b31202c30,0x09203233752e766f,0x31202c3233317225,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x7225202c32317025,0x317225202c303331,0x702540090a3b3233\n"
".quad 0x0920617262203231,0x33325f395f744c24,0x2f2f200a3b343535,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x38315f395f744c24,0x646461090a383731,0x662509203233662e\n"
".quad 0x33316625202c3431,0x0a3b32316625202c,0x3233662e766f6d09,0x202c353166250920\n"
".quad 0x3030303830346630,0x09202020203b3030,0x6573090a34202f2f,0x33662e746c2e7074\n"
".quad 0x2c33317025092032,0x25202c3431662520,0x2140090a3b353166,0x6172622033317025\n"
".quad 0x5f395f744c240920,0x240a3b3435353332,0x333136315f395f4c,0x6c3c2f2f200a3a30\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x0a34323220656e69,0x363109636f6c2e09\n"
".quad 0x090a300934323209,0x203233662e6c756d,0x25202c3631662509,0x316625202c313166\n"
".quad 0x2e646461090a3b30,0x3166250920323366,0x2c36316625202c37,0x090a3b3631662520\n"
".quad 0x203233662e646461,0x25202c3031662509,0x37316625202c3966,0x09636f6c2e090a3b\n"
".quad 0x3009353232093631,0x33662e627573090a,0x2c38316625092032,0x25202c3331662520\n"
".quad 0x6461090a3b323166,0x2509203233662e64,0x386625202c313166,0x0a3b38316625202c\n"
".quad 0x363109636f6c2e09,0x090a300936323209,0x203233662e6c756d,0x25202c3931662509\n"
".quad 0x316625202c303166,0x2e766f6d090a3b30,0x3166250920323366,0x3b39316625202c32\n"
".quad 0x3109636f6c2e090a,0x0a30093732320936,0x3233662e6c756d09,0x202c303266250920\n"
".quad 0x6625202c31316625,0x766f6d090a3b3131,0x662509203233662e,0x30326625202c3331\n"
".quad 0x09636f6c2e090a3b,0x3009333232093631,0x33732e627573090a,0x3133317225092032\n"
".quad 0x2c3133317225202c,0x766f6d090a3b3120,0x722509203233752e,0x0a3b30202c333331\n"
".quad 0x71652e7074657309,0x702509203233732e,0x33317225202c3431,0x3333317225202c31\n"
".quad 0x3431702540090a3b,0x4c24092061726220,0x353533325f395f74,0x6c3c2f2f200a3b34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c34323220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x30333136315f395f,0x33662e646461090a\n"
".quad 0x2c31326625092032,0x25202c3931662520,0x6f6d090a3b303266,0x2509203233662e76\n"
".quad 0x346630202c323266,0x3b30303030303830,0x202f2f0920202020,0x2e70746573090a34\n"
".quad 0x09203233662e746c,0x6625202c35317025,0x32326625202c3132,0x3531702540090a3b\n"
".quad 0x4c24092061726220,0x30333136315f395f,0x5f395f744c240a3b,0x240a3a3435353332\n"
".quad 0x383336315f395f4c,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x373138315f395f74,0x09636f6c2e090a38,0x3009313332093731,0x33732e766f6d090a\n"
".quad 0x3433317225092032,0x6573090a3b30202c,0x33732e74672e7074,0x2c36317025092032\n"
".quad 0x202c313331722520,0x090a3b3433317225,0x203233732e627573,0x202c353331722509\n"
".quad 0x25202c3033317225,0x6d090a3b31333172,0x09203233732e766f,0x30202c3633317225\n"
".quad 0x2e706c6573090a3b,0x3172250920323373,0x33317225202c3733,0x3633317225202c35\n"
".quad 0x0a3b36317025202c,0x3233752e766f6d09,0x2c38333172250920,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c373170250920,0x25202c3733317225,0x40090a3b38333172\n"
".quad 0x6172622037317025,0x5f395f744c240920,0x200a3b3437323232,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032\n"
".quad 0x656c6562616c2064,0x5f395f744c242064,0x2e090a3837313831,0x3209373109636f6c\n"
".quad 0x646c090a30093833,0x732e6d617261702e,0x3331722509203233,0x75635f5f5b202c39\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x6974616d696e615f,0x5d656d6172466e6f,0x732e646461090a3b,0x3431722509203233\n"
".quad 0x3933317225202c30,0x3b3733317225202c,0x7261702e646c090a,0x25092038752e6d61\n"
".quad 0x5f5b202c31343172,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x664933316d735f31,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x6f6c6f635f626969,0x090a3b5d302b7372,0x732e6f6c2e6c756d\n"
".quad 0x3431722509203233,0x3034317225202c32,0x3b3134317225202c,0x38752e747663090a\n"
".quad 0x722509203233752e,0x317225202c333431,0x6f6c2e090a3b3234,0x3933320937310963\n"
".quad 0x702e646c090a3009,0x2038752e6d617261,0x202c343431722509,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6f635f6269696969\n"
".quad 0x3b5d312b73726f6c,0x6f6c2e6c756d090a,0x722509203233732e,0x317225202c353431\n"
".quad 0x34317225202c3034,0x2e747663090a3b34,0x09203233752e3875,0x25202c3634317225\n"
".quad 0x2e090a3b35343172,0x3209373109636f6c,0x646c090a30093034,0x752e6d617261702e\n"
".quad 0x3734317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x322b73726f6c6f63,0x2e6c756d090a3b5d\n"
".quad 0x09203233732e6f6c,0x25202c3834317225,0x7225202c30343172,0x7663090a3b373431\n"
".quad 0x3233752e38752e74,0x2c39343172250920,0x0a3b383431722520,0x696e752e61726209\n"
".quad 0x5f395f744c240920,0x240a3b3831303232,0x3232325f395f744c,0x3c2f2f200a3a3437\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x31303220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3138315f395f744c,0x636f6c2e090a3837\n"
".quad 0x0934343209373109,0x752e766f6d090a30,0x3431722509203233,0x6d090a3b30202c39\n"
".quad 0x09203233752e766f,0x30202c3634317225,0x752e766f6d090a3b,0x3431722509203233\n"
".quad 0x4c240a3b30202c33,0x313032325f395f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x373138315f395f74,0x09636f6c2e090a38,0x3009303532093731\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5b202c3035317225,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764566\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x6172665f62696969\n"
".quad 0x6461090a3b5d656d,0x2509203233732e64,0x7225202c31353172,0x0a3b31202c303531\n"
".quad 0x3233732e72687309,0x2c32353172250920,0x202c313531722520,0x766f6d090a3b3133\n"
".quad 0x722509203233732e,0x0a3b31202c333531,0x3233622e646e6109,0x2c34353172250920\n"
".quad 0x202c323531722520,0x090a3b3335317225,0x203233732e646461,0x202c353531722509\n"
".quad 0x25202c3435317225,0x73090a3b31353172,0x09203233732e7268,0x25202c3635317225\n"
".quad 0x3b31202c35353172,0x6f6c2e6c756d090a,0x722509203233732e,0x317225202c373531\n"
".quad 0x36337225202c3035,0x732e646461090a3b,0x3531722509203233,0x3334317225202c38\n"
".quad 0x3b3735317225202c,0x33732e646461090a,0x3935317225092032,0x2c3635317225202c\n"
".quad 0x0a3b383531722520,0x3233732e76696409,0x2c30363172250920,0x202c393531722520\n"
".quad 0x090a3b3135317225,0x09373109636f6c2e,0x6d090a3009313532,0x33732e6f6c2e6c75\n"
".quad 0x3136317225092032,0x2c3035317225202c,0x090a3b3733722520,0x203233732e646461\n"
".quad 0x202c323631722509,0x25202c3634317225,0x61090a3b31363172,0x09203233732e6464\n"
".quad 0x25202c3336317225,0x7225202c36353172,0x6964090a3b323631,0x2509203233732e76\n"
".quad 0x7225202c34363172,0x317225202c333631,0x2e7473090a3b3135,0x762e6c61626f6c67\n"
".quad 0x255b092038752e32,0x202c5d302b346472,0x252c30363172257b,0x090a3b7d34363172\n"
".quad 0x09373109636f6c2e,0x6d090a3009323532,0x33732e6f6c2e6c75,0x3536317225092032\n"
".quad 0x2c3035317225202c,0x090a3b3833722520,0x203233732e646461,0x202c363631722509\n"
".quad 0x25202c3934317225,0x61090a3b35363172,0x09203233732e6464,0x25202c3736317225\n"
".quad 0x7225202c36353172,0x6964090a3b363631,0x2509203233732e76,0x7225202c38363172\n"
".quad 0x317225202c373631,0x2e7473090a3b3135,0x752e6c61626f6c67,0x346472255b092038\n"
".quad 0x317225202c5d322b,0x5f744c240a3b3836,0x3a34393930325f39,0x315f395f744c240a\n"
".quad 0x2f200a3a34333438,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20,0x315f395f744c2420\n"
".quad 0x6c2e090a38373138,0x353209373109636f,0x726162090a300935,0x300920636e79732e\n"
".quad 0x752e766f6d090a3b,0x3631722509203233,0x73090a3b30202c39,0x732e71652e707465\n"
".quad 0x3831702509203233,0x25202c377225202c,0x40090a3b39363172,0x6172622038317025\n"
".quad 0x5f395f744c240920,0x200a3b3033353232,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032,0x656c6562616c2064\n"
".quad 0x5f395f744c242064,0x2e090a3837313831,0x3209373109636f6c,0x6f6d090a30093935\n"
".quad 0x2509203436752e76,0x6f6c62202c396472,0x65746e756f436b63,0x2e766f6d090a3b72\n"
".quad 0x3172250920323375,0x090a3b31202c3037,0x6f6c672e6d6f7461,0x2e6464612e6c6162\n"
".quad 0x3172250920323375,0x6472255b202c3137,0x37317225202c5d39,0x2e766f6d090a3b30\n"
".quad 0x3172250920323373,0x37317225202c3237,0x732e7473090a3b31,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3436335f7261765f,0x6f6e5f32345f3333\n"
".quad 0x5f74736e6f635f6e,0x646e496b636f6c62,0x317225202c5d7865,0x6f6c2e090a3b3237\n"
".quad 0x3036320937310963,0x702e646c090a3009,0x3233752e6d617261,0x2c33373172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x675f62696969695f,0x6874646957646972,0x2e6d6572090a3b5d,0x3172250920323375\n"
".quad 0x37317225202c3437,0x3337317225202c32,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x333436335f726176,0x6e6f6e5f32345f34\n"
".quad 0x625f74736e6f635f,0x202c5d586b636f6c,0x090a3b3437317225,0x09373109636f6c2e\n"
".quad 0x64090a3009313632,0x09203233752e7669,0x25202c3537317225,0x7225202c32373172\n"
".quad 0x7473090a3b333731,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f30355f34333436,0x736e6f635f6e6f6e,0x596b636f6c625f74\n"
".quad 0x3537317225202c5d,0x5f395f744c240a3b,0x200a3a3033353232,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032\n"
".quad 0x656c6562616c2064,0x5f395f744c242064,0x2e090a3837313831,0x3209373109636f6c\n"
".quad 0x6162090a30093436,0x0920636e79732e72,0x732e646c090a3b30,0x33752e6465726168\n"
".quad 0x3637317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x333436335f726176\n"
".quad 0x6e6f6e5f32345f33,0x625f74736e6f635f,0x65646e496b636f6c,0x746573090a3b5d78\n"
".quad 0x3233752e746c2e70,0x202c393170250920,0x25202c3637317225,0x2540090a3b353172\n"
".quad 0x2061726220393170,0x315f395f744c2409,0x4c240a3b38373138,0x363637315f395f74\n"
".quad 0x636f6c2e090a3a36,0x0937363209373109,0x3b74697865090a30,0x646e6557444c240a\n"
".quad 0x6e614d36315a5f5f,0x31746f72626c6564,0x45664933316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x2f207d090a3a6269\n"
".quad 0x614d36315a5f202f,0x746f72626c65646e,0x664933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x652e090a0a626969\n"
".quad 0x315a5f207972746e,0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x282062696969695f\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x2c7473645f626969,0x617261702e09090a\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x644933316d735f31,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x67616d695f626969,0x702e09090a2c5765,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x695f62696969695f,0x090a2c486567616d,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x68636e7572635f62,0x7261702e09090a2c,0x203436662e206d61,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x664f785f62696969\n"
".quad 0x61702e09090a2c66,0x3436662e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x4f795f6269696969,0x702e09090a2c6666\n"
".quad 0x36662e206d617261,0x616475635f5f2034,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f31746f72,0x7536507645644933,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x785f62696969695f,0x702e09090a2c504a,0x36662e206d617261\n"
".quad 0x616475635f5f2034,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x795f62696969695f,0x702e09090a2c504a,0x36662e206d617261,0x616475635f5f2034\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x735f62696969695f\n"
".quad 0x09090a2c656c6163,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x5b73726f6c6f635f,0x702e09090a2c5d34,0x33732e206d617261,0x616475635f5f2032\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x665f62696969695f\n"
".quad 0x09090a2c656d6172,0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x6974616d696e615f\n"
".quad 0x2c656d6172466e6f,0x617261702e09090a,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x646972675f626969\n"
".quad 0x090a2c6874646957,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x6f6c426d756e5f62\n"
".quad 0x2e09090a2c736b63,0x732e206d61726170,0x616475635f5f2038,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f,0x090a7b090a294a73\n"
".quad 0x33752e206765722e,0x3837313c72252032,0x6765722e090a3b3e,0x7225203436752e20\n"
".quad 0x090a3b3e31313c64,0x36662e206765722e,0x34323c6466252034,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x090a3b3e31323c70,0x206465726168732e,0x635f5f203233752e\n"
".quad 0x61636f6c5f616475,0x36335f7261765f6c,0x6e5f32345f333334,0x74736e6f635f6e6f\n"
".quad 0x6e496b636f6c625f,0x732e090a3b786564,0x752e206465726168,0x6475635f5f203233\n"
".quad 0x5f6c61636f6c5f61,0x333436335f726176,0x6e6f6e5f32345f34,0x625f74736e6f635f\n"
".quad 0x090a3b586b636f6c,0x206465726168732e,0x635f5f203233752e,0x61636f6c5f616475\n"
".quad 0x36335f7261765f6c,0x6e5f30355f343334,0x74736e6f635f6e6f,0x3b596b636f6c625f\n"
".quad 0x3109636f6c2e090a,0x0a30093938310937,0x6967656257444c24,0x614d36315a5f5f6e\n"
".quad 0x746f72626c65646e,0x644933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x6f6d090a3a626969,0x2509203233752e76\n"
".quad 0x64697425202c3172,0x766f6d090a3b782e,0x722509203233752e,0x73090a3b30202c32\n"
".quad 0x752e71652e707465,0x2c31702509203233,0x7225202c31722520,0x2e766f6d090a3b32\n"
".quad 0x3372250920323375,0x792e64697425202c,0x752e766f6d090a3b,0x2c34722509203233\n"
".quad 0x746573090a3b3020,0x3233752e71652e70,0x25202c3270250920,0x3b347225202c3372\n"
".quad 0x732e706c6573090a,0x2c35722509203233,0x25202c30202c3120,0x6c6573090a3b3170\n"
".quad 0x2509203233732e70,0x30202c31202c3672,0x090a3b327025202c,0x203233622e646e61\n"
".quad 0x7225202c37722509,0x0a3b367225202c35,0x3233752e766f6d09,0x30202c3872250920\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x377225202c337025,0x090a3b387225202c\n"
".quad 0x6172622033702540,0x30315f744c240920,0x0a3b34353137315f,0x373109636f6c2e09\n"
".quad 0x090a300936393109,0x203436752e766f6d,0x62202c3164722509,0x6e756f436b636f6c\n"
".quad 0x6f6d090a3b726574,0x2509203233752e76,0x090a3b31202c3972,0x6f6c672e6d6f7461\n"
".quad 0x2e6464612e6c6162,0x3172250920323375,0x316472255b202c30,0x0a3b397225202c5d\n"
".quad 0x3233732e766f6d09,0x202c313172250920,0x73090a3b30317225,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32345f3333343633\n"
".quad 0x6e6f635f6e6f6e5f,0x6b636f6c625f7473,0x202c5d7865646e49,0x2e090a3b31317225\n"
".quad 0x3109373109636f6c,0x646c090a30093739,0x752e6d617261702e,0x3231722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764564493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x7464695764697267,0x6d6572090a3b5d68,0x722509203233752e\n"
".quad 0x31317225202c3331,0x0a3b32317225202c,0x726168732e747309,0x09203233752e6465\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34333436335f72,0x635f6e6f6e5f3234\n"
".quad 0x6f6c625f74736e6f,0x7225202c5d586b63,0x6f6c2e090a3b3331,0x3839310937310963\n"
".quad 0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34,0x090a3b3231722520\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x355f34333436335f,0x6f635f6e6f6e5f30,0x636f6c625f74736e,0x317225202c5d596b\n"
".quad 0x315f744c240a3b34,0x3a34353137315f30,0x3109636f6c2e090a,0x0a30093130320937\n"
".quad 0x6e79732e72616209,0x6c090a3b30092063,0x2e6d617261702e64,0x3172250920323375\n"
".quad 0x75635f5f5b202c35,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x636f6c426d756e5f,0x646c090a3b5d736b,0x2e6465726168732e\n"
".quad 0x3172250920323375,0x75635f5f5b202c36,0x6c61636f6c5f6164,0x3436335f7261765f\n"
".quad 0x6f6e5f32345f3333,0x5f74736e6f635f6e,0x646e496b636f6c62,0x6573090a3b5d7865\n"
".quad 0x33752e65672e7074,0x202c347025092032,0x7225202c36317225,0x702540090a3b3531\n"
".quad 0x2409206172622034,0x37315f30315f744c,0x646c090a3b363636,0x732e6d617261702e\n"
".quad 0x3731722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764564493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x3b5d486567616d69,0x7261702e646c090a\n"
".quad 0x09203233732e6d61,0x5f5b202c38317225,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x67616d695f626969,0x6f6d090a3b5d5765\n"
".quad 0x2509203233752e76,0x746e25202c393172,0x6d090a3b792e6469,0x09203233752e766f\n"
".quad 0x6e25202c30327225,0x240a3b782e646974,0x38315f30315f744c,0x2f2f200a3a383731\n"
".quad 0x4c203e706f6f6c3c,0x79646f6220706f6f,0x303220656e696c20,0x68732e646c090a31\n"
".quad 0x3233752e64657261,0x202c313272250920,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f34333436335f72,0x635f6e6f6e5f3234,0x6f6c625f74736e6f,0x6d090a3b5d586b63\n"
".quad 0x33752e6f6c2e6c75,0x2c32327225092032,0x25202c3132722520,0x646c090a3b303272\n"
".quad 0x2e6465726168732e,0x3272250920323375,0x75635f5f5b202c33,0x6c61636f6c5f6164\n"
".quad 0x3436335f7261765f,0x6f6e5f30355f3433,0x5f74736e6f635f6e,0x3b5d596b636f6c62\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x33327225202c3432,0x0a3b39317225202c\n"
".quad 0x3233752e64646109,0x202c353272250920,0x7225202c32327225,0x2e646461090a3b31\n"
".quad 0x3272250920323375,0x2c34327225202c36,0x73090a3b33722520,0x33752e74672e7465\n"
".quad 0x2509203233732e32,0x317225202c373272,0x3b36327225202c37,0x33732e67656e090a\n"
".quad 0x2c38327225092032,0x090a3b3732722520,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c39327225,0x35327225202c3831,0x732e67656e090a3b,0x3033722509203233\n"
".quad 0x0a3b39327225202c,0x3233622e646e6109,0x202c313372250920,0x7225202c38327225\n"
".quad 0x766f6d090a3b3033,0x722509203233752e,0x090a3b30202c3233,0x2e71652e70746573\n"
".quad 0x3570250920323373,0x202c31337225202c,0x40090a3b32337225,0x2061726220357025\n"
".quad 0x5f30315f744c2409,0x200a3b3439393032,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032,0x656c6562616c2064\n"
".quad 0x30315f744c242064,0x090a38373138315f,0x09373109636f6c2e,0x6d090a3009333132\n"
".quad 0x33732e6f6c2e6c75,0x2c33337225092032,0x25202c3831722520,0x6461090a3b363272\n"
".quad 0x2509203233732e64,0x337225202c343372,0x3b35327225202c33,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5f5b202c32647225,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x5d7473645f626969,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x337225202c353372,0x63090a3b34202c34,0x752e3436752e7476\n"
".quad 0x3364722509203233,0x0a3b35337225202c,0x3436752e64646109,0x202c346472250920\n"
".quad 0x7225202c33647225,0x2e646c090a3b3264,0x762e6c61626f6c67,0x257b092038752e34\n"
".quad 0x373372252c363372,0x7d5f2c383372252c,0x2b346472255b202c,0x766f6d090a3b5d30\n"
".quad 0x722509203233752e,0x090a3b30202c3933,0x2e656c2e70746573,0x3670250920323373\n"
".quad 0x202c35327225202c,0x40090a3b39337225,0x2061726220367025,0x5f30315f744c2409\n"
".quad 0x200a3b3230323931,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313032,0x656c6562616c2064,0x30315f744c242064\n"
".quad 0x090a38373138315f,0x61626f6c672e646c,0x2038752e34762e6c,0x252c303472257b09\n"
".quad 0x323472252c313472,0x72255b202c7d5f2c,0x0a3b5d342d2b3464,0x373109636f6c2e09\n"
".quad 0x090a300938313209,0x203233732e627573,0x25202c3334722509,0x337225202c323472\n"
".quad 0x2e736261090a3b38,0x3472250920323373,0x3b33347225202c34,0x33732e766f6d090a\n"
".quad 0x2c35347225092032,0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e\n"
".quad 0x34347225202c3634,0x0a3b35347225202c,0x3233732e67656e09,0x202c373472250920\n"
".quad 0x73090a3b36347225,0x09203233732e6275,0x7225202c38347225,0x36337225202c3034\n"
".quad 0x732e736261090a3b,0x3934722509203233,0x0a3b38347225202c,0x3233732e766f6d09\n"
".quad 0x202c303572250920,0x746573090a3b3031,0x2e3233752e74672e,0x3572250920323373\n"
".quad 0x2c39347225202c31,0x090a3b3035722520,0x203233732e67656e,0x25202c3235722509\n"
".quad 0x7573090a3b313572,0x2509203233732e62,0x347225202c333572,0x3b37337225202c31\n"
".quad 0x33732e736261090a,0x2c34357225092032,0x090a3b3335722520,0x203233732e766f6d\n"
".quad 0x31202c3535722509,0x2e746573090a3b30,0x732e3233752e7467,0x3635722509203233\n"
".quad 0x202c34357225202c,0x6e090a3b35357225,0x09203233732e6765,0x7225202c37357225\n"
".quad 0x2e726f090a3b3635,0x3572250920323362,0x2c32357225202c38,0x090a3b3735722520\n"
".quad 0x09203233622e726f,0x7225202c39357225,0x38357225202c3734,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x36343938315f3031,0x30315f744c240a3b,0x0a3a32303239315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31303220,0x6c6562616c206461,0x315f744c24206465,0x0a38373138315f30\n"
".quad 0x3233732e766f6d09,0x202c393572250920,0x315f744c240a3b30,0x3a36343938315f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x38373138315f3031\n"
".quad 0x33732e646461090a,0x2c30367225092032,0x31202c3532722520,0x2e70746573090a3b\n"
".quad 0x09203233732e656c,0x317225202c377025,0x3b30367225202c38,0x622037702540090a\n"
".quad 0x5f744c2409206172,0x38353439315f3031,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x373138315f30315f,0x6c672e646c090a38,0x2e34762e6c61626f\n"
".quad 0x3672257b09203875,0x252c323672252c31,0x202c7d5f2c333672,0x5d342b346472255b\n"
".quad 0x09636f6c2e090a3b,0x3009303232093731,0x33732e627573090a,0x2c34367225092032\n"
".quad 0x25202c3336722520,0x6261090a3b383372,0x2509203233732e73,0x367225202c353672\n"
".quad 0x2e766f6d090a3b34,0x3672250920323373,0x090a3b3031202c36,0x752e74672e746573\n"
".quad 0x09203233732e3233,0x7225202c37367225,0x36367225202c3536,0x732e67656e090a3b\n"
".quad 0x3836722509203233,0x0a3b37367225202c,0x3233732e62757309,0x202c393672250920\n"
".quad 0x7225202c31367225,0x736261090a3b3633,0x722509203233732e,0x39367225202c3037\n"
".quad 0x732e766f6d090a3b,0x3137722509203233,0x73090a3b3031202c,0x33752e74672e7465\n"
".quad 0x2509203233732e32,0x377225202c323772,0x3b31377225202c30,0x33732e67656e090a\n"
".quad 0x2c33377225092032,0x090a3b3237722520,0x203233732e627573,0x25202c3437722509\n"
".quad 0x337225202c323672,0x2e736261090a3b37,0x3772250920323373,0x3b34377225202c35\n"
".quad 0x33732e766f6d090a,0x2c36377225092032,0x6573090a3b303120,0x3233752e74672e74\n"
".quad 0x722509203233732e,0x35377225202c3737,0x0a3b36377225202c,0x3233732e67656e09\n"
".quad 0x202c383772250920,0x6f090a3b37377225,0x2509203233622e72,0x377225202c393772\n"
".quad 0x3b38377225202c33,0x3233622e726f090a,0x202c303872250920,0x7225202c38367225\n"
".quad 0x646461090a3b3937,0x722509203233732e,0x39357225202c3935,0x0a3b30387225202c\n"
".quad 0x315f30315f744c24,0x2f200a3a38353439,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20\n"
".quad 0x5f30315f744c2420,0x6d090a3837313831,0x09203233752e766f,0x3b30202c31387225\n"
".quad 0x6c2e70746573090a,0x2509203233732e65,0x36327225202c3870,0x0a3b31387225202c\n"
".quad 0x7262203870254009,0x315f744c24092061,0x3b30373939315f30,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3130322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x38373138315f3031,0x3109636f6c2e090a\n"
".quad 0x0a30093232320937,0x3233732e62757309,0x202c323872250920,0x7225202c34337225\n"
".quad 0x6c756d090a3b3831,0x203233752e6f6c2e,0x25202c3338722509,0x0a3b34202c323872\n"
".quad 0x3436752e74766309,0x722509203233752e,0x33387225202c3564,0x752e646461090a3b\n"
".quad 0x3664722509203436,0x202c35647225202c,0x6c090a3b32647225,0x6c61626f6c672e64\n"
".quad 0x092038752e34762e,0x72252c343872257b,0x2c363872252c3538,0x6472255b202c7d5f\n"
".quad 0x73090a3b5d302b36,0x09203233732e6275,0x7225202c37387225,0x38337225202c3638\n"
".quad 0x732e736261090a3b,0x3838722509203233,0x0a3b37387225202c,0x3233732e766f6d09\n"
".quad 0x202c393872250920,0x746573090a3b3031,0x2e3233752e74672e,0x3972250920323373\n"
".quad 0x2c38387225202c30,0x090a3b3938722520,0x203233732e67656e,0x25202c3139722509\n"
".quad 0x7573090a3b303972,0x2509203233732e62,0x387225202c323972,0x3b36337225202c34\n"
".quad 0x33732e736261090a,0x2c33397225092032,0x090a3b3239722520,0x203233732e766f6d\n"
".quad 0x31202c3439722509,0x2e746573090a3b30,0x732e3233752e7467,0x3539722509203233\n"
".quad 0x202c33397225202c,0x6e090a3b34397225,0x09203233732e6765,0x7225202c36397225\n"
".quad 0x627573090a3b3539,0x722509203233732e,0x35387225202c3739,0x0a3b37337225202c\n"
".quad 0x3233732e73626109,0x202c383972250920,0x6d090a3b37397225,0x09203233732e766f\n"
".quad 0x3031202c39397225,0x672e746573090a3b,0x33732e3233752e74,0x3030317225092032\n"
".quad 0x202c38397225202c,0x6e090a3b39397225,0x09203233732e6765,0x25202c3130317225\n"
".quad 0x6f090a3b30303172,0x2509203233622e72,0x7225202c32303172,0x30317225202c3639\n"
".quad 0x622e726f090a3b31,0x3031722509203233,0x2c31397225202c33,0x0a3b323031722520\n"
".quad 0x3233732e64646109,0x202c393572250920,0x7225202c39357225,0x744c240a3b333031\n"
".quad 0x373939315f30315f,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x3138315f30315f74,0x2e646461090a3837,0x3172250920323373,0x36327225202c3430\n"
".quad 0x6573090a3b31202c,0x33732e656c2e7074,0x202c397025092032,0x7225202c37317225\n"
".quad 0x2540090a3b343031,0x0920617262203970,0x325f30315f744c24,0x2f200a3b32383430\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3130,0x64656c6562616c20,0x5f30315f744c2420,0x2e090a3837313831\n"
".quad 0x3209373109636f6c,0x6461090a30093432,0x2509203233732e64,0x7225202c35303172\n"
".quad 0x38317225202c3433,0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c36303172\n"
".quad 0x0a3b34202c353031,0x3436752e74766309,0x722509203233752e,0x30317225202c3764\n"
".quad 0x2e646461090a3b36,0x6472250920343675,0x2c37647225202c38,0x090a3b3264722520\n"
".quad 0x61626f6c672e646c,0x2038752e34762e6c,0x2c37303172257b09,0x72252c3830317225\n"
".quad 0x202c7d5f2c393031,0x5d302b386472255b,0x732e627573090a3b,0x3131722509203233\n"
".quad 0x3930317225202c30,0x0a3b38337225202c,0x3233732e73626109,0x2c31313172250920\n"
".quad 0x0a3b303131722520,0x3233732e766f6d09,0x2c32313172250920,0x6573090a3b303120\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x317225202c333131,0x31317225202c3131\n"
".quad 0x2e67656e090a3b32,0x3172250920323373,0x31317225202c3431,0x2e627573090a3b33\n"
".quad 0x3172250920323373,0x30317225202c3531,0x3b36337225202c37,0x33732e736261090a\n"
".quad 0x3631317225092032,0x3b3531317225202c,0x33732e766f6d090a,0x3731317225092032\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x7225202c38313172\n"
".quad 0x317225202c363131,0x67656e090a3b3731,0x722509203233732e,0x317225202c393131\n"
".quad 0x627573090a3b3831,0x722509203233732e,0x317225202c303231,0x37337225202c3830\n"
".quad 0x732e736261090a3b,0x3231722509203233,0x3032317225202c31,0x732e766f6d090a3b\n"
".quad 0x3231722509203233,0x090a3b3031202c32,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x25202c3332317225,0x7225202c31323172,0x656e090a3b323231,0x2509203233732e67\n"
".quad 0x7225202c34323172,0x726f090a3b333231,0x722509203233622e,0x317225202c353231\n"
".quad 0x32317225202c3931,0x622e726f090a3b34,0x3231722509203233,0x3431317225202c36\n"
".quad 0x3b3532317225202c,0x33732e646461090a,0x2c39357225092032,0x25202c3935722520\n"
".quad 0x4c240a3b36323172,0x3430325f30315f74,0x3c2f2f200a3a3238,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31303220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x38315f30315f744c,0x766f6d090a383731,0x722509203233752e\n"
".quad 0x0a3b30202c373231,0x71652e7074657309,0x702509203233732e,0x39357225202c3031\n"
".quad 0x3b3732317225202c,0x203031702540090a,0x744c240920617262,0x393930325f30315f\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562,0x3138315f30315f74\n"
".quad 0x636f6c2e090a3837,0x0931333209373109,0x61702e646c090a30,0x203436662e6d6172\n"
".quad 0x5b202c3164662509,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4933316d735f3174,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x6163735f62696969,0x646c090a3b5d656c,0x662e6d617261702e\n"
".quad 0x3264662509203436,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764564493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x090a3b5d66664f78,0x662e6e722e747663\n"
".quad 0x09203233732e3436,0x7225202c33646625,0x64616d090a3b3532,0x203436662e6e722e\n"
".quad 0x25202c3464662509,0x646625202c336466,0x3b32646625202c31,0x7261702e646c090a\n"
".quad 0x09203436662e6d61,0x5f5b202c35646625,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x66664f795f626969,0x2e747663090a3b5d\n"
".quad 0x732e3436662e6e72,0x3664662509203233,0x0a3b36327225202c,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x2c36646625202c37,0x25202c3164662520,0x646c090a3b356466\n"
".quad 0x732e6d617261702e,0x3832317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x6d090a3b5d4a7369\n"
".quad 0x09203233752e766f,0x30202c3932317225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c31317025,0x317225202c383231,0x702540090a3b3932,0x0920617262203131\n"
".quad 0x325f30315f744c24,0x2f200a3b32363731,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20\n"
".quad 0x5f30315f744c2420,0x2e090a3837313831,0x3209363109636f6c,0x646c090a30093530\n"
".quad 0x662e6d617261702e,0x3864662509203436,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x2e090a3b5d504a78\n"
".quad 0x3209363109636f6c,0x646c090a30093630,0x662e6d617261702e,0x3964662509203436\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764564493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x2e090a3b5d504a79,0x3209363109636f6c,0x6f6d090a30093730\n"
".quad 0x2509203436662e76,0x6625202c30316466,0x6f6c2e090a3b3764,0x3830320936310963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x34646625202c3131,0x09636f6c2e090a3b\n"
".quad 0x3009393032093631,0x36662e6c756d090a,0x3231646625092034,0x202c37646625202c\n"
".quad 0x2e090a3b37646625,0x3209363109636f6c,0x756d090a30093031,0x2509203436662e6c\n"
".quad 0x6625202c33316466,0x34646625202c3464,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x36303531325f3031,0x30315f744c240a3b,0x0a3a32363731325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x0a38373138315f30,0x363109636f6c2e09\n"
".quad 0x090a300934313209,0x203436662e766f6d,0x25202c3864662509,0x6c2e090a3b346466\n"
".quad 0x313209363109636f,0x766f6d090a300935,0x662509203436662e,0x37646625202c3964\n"
".quad 0x09636f6c2e090a3b,0x3009393132093631,0x36662e766f6d090a,0x3331646625092034\n"
".quad 0x303030306430202c,0x3030303030303030,0x2f2f093b30303030,0x2e766f6d090a3020\n"
".quad 0x6466250920343666,0x30306430202c3231,0x3030303030303030,0x093b303030303030\n"
".quad 0x6f6d090a30202f2f,0x2509203436662e76,0x6430202c31316466,0x3030303030303030\n"
".quad 0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d,0x202c303164662509\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x5f30315f744c240a\n"
".quad 0x200a3a3630353132,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313032,0x656c6562616c2064,0x30315f744c242064\n"
".quad 0x090a38373138315f,0x09363109636f6c2e,0x6c090a3009333232,0x2e6d617261702e64\n"
".quad 0x3172250920323373,0x635f5f5b202c3033,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x68636e7572635f62,0x2e627573090a3b5d\n"
".quad 0x3172250920323373,0x33317225202c3133,0x6d090a3b31202c30,0x09203233752e766f\n"
".quad 0x31202c3233317225,0x2e70746573090a3b,0x09203233732e7165,0x7225202c32317025\n"
".quad 0x317225202c303331,0x702540090a3b3233,0x0920617262203231,0x325f30315f744c24\n"
".quad 0x2f200a3b34353533,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20,0x5f30315f744c2420\n"
".quad 0x61090a3837313831,0x09203436662e6464,0x25202c3431646625,0x6625202c33316466\n"
".quad 0x6f6d090a3b323164,0x2509203436662e76,0x6430202c35316466,0x3030303030313034\n"
".quad 0x3030303030303030,0x090a34202f2f093b,0x2e746c2e70746573,0x3170250920343666\n"
".quad 0x3431646625202c33,0x3b3531646625202c,0x333170252140090a,0x4c24092061726220\n"
".quad 0x3533325f30315f74,0x315f4c240a3b3435,0x3a30333136315f30,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x2e090a3432322065,0x3209363109636f6c\n"
".quad 0x756d090a30093432,0x2509203436662e6c,0x6625202c36316466,0x646625202c313164\n"
".quad 0x646461090a3b3031,0x662509203436662e,0x646625202c373164,0x31646625202c3631\n"
".quad 0x2e646461090a3b36,0x6466250920343666,0x39646625202c3031,0x3b3731646625202c\n"
".quad 0x3109636f6c2e090a,0x0a30093532320936,0x3436662e62757309,0x2c38316466250920\n"
".quad 0x202c333164662520,0x090a3b3231646625,0x203436662e646461,0x202c313164662509\n"
".quad 0x6625202c38646625,0x6c2e090a3b383164,0x323209363109636f,0x6c756d090a300936\n"
".quad 0x662509203436662e,0x646625202c393164,0x31646625202c3031,0x2e766f6d090a3b30\n"
".quad 0x6466250920343666,0x31646625202c3231,0x636f6c2e090a3b39,0x0937323209363109\n"
".quad 0x662e6c756d090a30,0x3264662509203436,0x3131646625202c30,0x3b3131646625202c\n"
".quad 0x36662e766f6d090a,0x3331646625092034,0x3b3032646625202c,0x3109636f6c2e090a\n"
".quad 0x0a30093332320936,0x3233732e62757309,0x2c31333172250920,0x202c313331722520\n"
".quad 0x2e766f6d090a3b31,0x3172250920323375,0x090a3b30202c3333,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x3133317225202c34,0x3b3333317225202c,0x203431702540090a\n"
".quad 0x744c240920617262,0x353533325f30315f,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c34323220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333136315f30315f,0x662e646461090a30,0x3264662509203436\n"
".quad 0x3931646625202c31,0x3b3032646625202c,0x36662e766f6d090a,0x3232646625092034\n"
".quad 0x303130346430202c,0x3030303030303030,0x2f2f093b30303030,0x70746573090a3420\n"
".quad 0x203436662e746c2e,0x25202c3531702509,0x6625202c31326466,0x2540090a3b323264\n"
".quad 0x2061726220353170,0x315f30315f4c2409,0x4c240a3b30333136,0x3533325f30315f74\n"
".quad 0x315f4c240a3a3435,0x3a36383336315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3130322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x38373138315f3031,0x3109636f6c2e090a,0x0a30093133320937\n"
".quad 0x3233732e766f6d09,0x2c34333172250920,0x746573090a3b3020,0x3233732e74672e70\n"
".quad 0x202c363170250920,0x25202c3133317225,0x73090a3b34333172,0x09203233732e6275\n"
".quad 0x25202c3533317225,0x7225202c30333172,0x6f6d090a3b313331,0x2509203233732e76\n"
".quad 0x3b30202c36333172,0x732e706c6573090a,0x3331722509203233,0x3533317225202c37\n"
".quad 0x2c3633317225202c,0x090a3b3631702520,0x203233752e766f6d,0x202c383331722509\n"
".quad 0x70746573090a3b30,0x203233732e71652e,0x25202c3731702509,0x7225202c37333172\n"
".quad 0x2540090a3b383331,0x2061726220373170,0x5f30315f744c2409,0x200a3b3437323232\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313032,0x656c6562616c2064,0x30315f744c242064,0x090a38373138315f\n"
".quad 0x09373109636f6c2e,0x6c090a3009383332,0x2e6d617261702e64,0x3172250920323373\n"
".quad 0x635f5f5b202c3933,0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65\n"
".quad 0x7645644933316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x74616d696e615f62,0x656d6172466e6f69,0x2e646461090a3b5d\n"
".quad 0x3172250920323373,0x33317225202c3034,0x3733317225202c39,0x61702e646c090a3b\n"
".quad 0x092038752e6d6172,0x5b202c3134317225,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x6c6f635f62696969,0x0a3b5d302b73726f\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323373,0x34317225202c3234,0x3134317225202c30\n"
".quad 0x752e747663090a3b,0x2509203233752e38,0x7225202c33343172,0x6c2e090a3b323431\n"
".quad 0x333209373109636f,0x2e646c090a300939,0x38752e6d61726170,0x2c34343172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x635f62696969695f,0x5d312b73726f6c6f,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c35343172,0x317225202c303431,0x747663090a3b3434,0x203233752e38752e\n"
".quad 0x202c363431722509,0x090a3b3534317225,0x09373109636f6c2e,0x6c090a3009303432\n"
".quad 0x2e6d617261702e64,0x3431722509203875,0x75635f5f5b202c37,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x2b73726f6c6f635f\n"
".quad 0x6c756d090a3b5d32,0x203233732e6f6c2e,0x202c383431722509,0x25202c3034317225\n"
".quad 0x63090a3b37343172,0x33752e38752e7476,0x3934317225092032,0x3b3834317225202c\n"
".quad 0x6e752e617262090a,0x315f744c24092069,0x3b38313032325f30,0x5f30315f744c240a\n"
".quad 0x200a3a3437323232,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c313032,0x656c6562616c2064,0x30315f744c242064\n"
".quad 0x090a38373138315f,0x09373109636f6c2e,0x6d090a3009343432,0x09203233752e766f\n"
".quad 0x30202c3934317225,0x752e766f6d090a3b,0x3431722509203233,0x6d090a3b30202c36\n"
".quad 0x09203233752e766f,0x30202c3334317225,0x30315f744c240a3b,0x0a3a38313032325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31303220,0x6c6562616c206461,0x315f744c24206465,0x0a38373138315f30\n"
".quad 0x373109636f6c2e09,0x090a300930353209,0x6d617261702e646c,0x722509203233732e\n"
".quad 0x5f5f5b202c303531,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45644933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x656d6172665f6269,0x2e646461090a3b5d,0x3172250920323373\n"
".quad 0x35317225202c3135,0x73090a3b31202c30,0x09203233732e7268,0x25202c3235317225\n"
".quad 0x3133202c31353172,0x732e766f6d090a3b,0x3531722509203233,0x61090a3b31202c33\n"
".quad 0x09203233622e646e,0x25202c3435317225,0x7225202c32353172,0x6461090a3b333531\n"
".quad 0x2509203233732e64,0x7225202c35353172,0x317225202c343531,0x726873090a3b3135\n"
".quad 0x722509203233732e,0x317225202c363531,0x090a3b31202c3535,0x732e6f6c2e6c756d\n"
".quad 0x3531722509203233,0x3035317225202c37,0x0a3b36337225202c,0x3233732e64646109\n"
".quad 0x2c38353172250920,0x202c333431722520,0x090a3b3735317225,0x203233732e646461\n"
".quad 0x202c393531722509,0x25202c3635317225,0x64090a3b38353172,0x09203233732e7669\n"
".quad 0x25202c3036317225,0x7225202c39353172,0x6c2e090a3b313531,0x353209373109636f\n"
".quad 0x6c756d090a300931,0x203233732e6f6c2e,0x202c313631722509,0x25202c3035317225\n"
".quad 0x6461090a3b373372,0x2509203233732e64,0x7225202c32363172,0x317225202c363431\n"
".quad 0x646461090a3b3136,0x722509203233732e,0x317225202c333631,0x36317225202c3635\n"
".quad 0x2e766964090a3b32,0x3172250920323373,0x36317225202c3436,0x3135317225202c33\n"
".quad 0x6c672e7473090a3b,0x2e32762e6c61626f,0x6472255b09203875,0x257b202c5d302b34\n"
".quad 0x3172252c30363172,0x6c2e090a3b7d3436,0x353209373109636f,0x6c756d090a300932\n"
".quad 0x203233732e6f6c2e,0x202c353631722509,0x25202c3035317225,0x6461090a3b383372\n"
".quad 0x2509203233732e64,0x7225202c36363172,0x317225202c393431,0x646461090a3b3536\n"
".quad 0x722509203233732e,0x317225202c373631,0x36317225202c3635,0x2e766964090a3b36\n"
".quad 0x3172250920323373,0x36317225202c3836,0x3135317225202c37,0x6c672e7473090a3b\n"
".quad 0x2038752e6c61626f,0x322b346472255b09,0x3836317225202c5d,0x30315f744c240a3b\n"
".quad 0x0a3a34393930325f,0x315f30315f744c24,0x2f200a3a34333438,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3130\n"
".quad 0x64656c6562616c20,0x5f30315f744c2420,0x2e090a3837313831,0x3209373109636f6c\n"
".quad 0x6162090a30093535,0x0920636e79732e72,0x2e766f6d090a3b30,0x3172250920323375\n"
".quad 0x090a3b30202c3936,0x2e71652e70746573,0x3170250920323373,0x202c377225202c38\n"
".quad 0x090a3b3936317225,0x7262203831702540,0x315f744c24092061,0x3b30333532325f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x38373138315f3031\n"
".quad 0x3109636f6c2e090a,0x0a30093935320937,0x3436752e766f6d09,0x202c396472250920\n"
".quad 0x756f436b636f6c62,0x6d090a3b7265746e,0x09203233752e766f,0x31202c3037317225\n"
".quad 0x2e6d6f7461090a3b,0x612e6c61626f6c67,0x09203233752e6464,0x5b202c3137317225\n"
".quad 0x25202c5d39647225,0x6d090a3b30373172,0x09203233732e766f,0x25202c3237317225\n"
".quad 0x73090a3b31373172,0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x32345f3333343633,0x6e6f635f6e6f6e5f,0x6b636f6c625f7473\n"
".quad 0x202c5d7865646e49,0x090a3b3237317225,0x09373109636f6c2e,0x6c090a3009303632\n"
".quad 0x2e6d617261702e64,0x3172250920323375,0x635f5f5b202c3337,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x6957646972675f62\n"
".quad 0x72090a3b5d687464,0x09203233752e6d65,0x25202c3437317225,0x7225202c32373172\n"
".quad 0x7473090a3b333731,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x335f7261765f6c61,0x5f32345f34333436,0x736e6f635f6e6f6e,0x586b636f6c625f74\n"
".quad 0x3437317225202c5d,0x09636f6c2e090a3b,0x3009313632093731,0x33752e766964090a\n"
".quad 0x3537317225092032,0x2c3237317225202c,0x0a3b333731722520,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34333436335f72\n"
".quad 0x635f6e6f6e5f3035,0x6f6c625f74736e6f,0x7225202c5d596b63,0x744c240a3b353731\n"
".quad 0x333532325f30315f,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x3138315f30315f74,0x636f6c2e090a3837,0x0934363209373109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x726168732e646c09,0x09203233752e6465,0x5b202c3637317225\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f33333436335f,0x6f635f6e6f6e5f32\n"
".quad 0x636f6c625f74736e,0x3b5d7865646e496b,0x6c2e70746573090a,0x2509203233752e74\n"
".quad 0x317225202c393170,0x35317225202c3637,0x3931702540090a3b,0x4c24092061726220\n"
".quad 0x3138315f30315f74,0x5f744c240a3b3837,0x36363637315f3031,0x09636f6c2e090a3a\n"
".quad 0x3009373632093731,0x0a3b74697865090a,0x5f646e6557444c24,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x2f2f207d090a3a62,0x6e614d36315a5f20\n"
".quad 0x31746f72626c6564,0x45644933316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x000000000a0a6269\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[15127];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000006678,0x0000000000000040,0x0038004000140115,0x000100250040000f\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000980\n"
".quad 0x00000000000007f2,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000001172\n"
".quad 0x0000000000000160,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x00000000000012d2\n"
".quad 0x0000000000000438,0x0000002600000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x00000001000002ce,0x0000000000100006,0x0000000000000000,0x000000000000170a\n"
".quad 0x0000000000000d60,0x1b00001100000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000705,0x0000000000000002,0x0000000000000000,0x000000000000246a\n"
".quad 0x0000000000000065,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000006c6,0x0000000000000002,0x0000000000000000,0x00000000000024cf\n"
".quad 0x0000000000000004,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000304,0x0000000000000002,0x0000000000000000,0x00000000000024d3\n"
".quad 0x0000000000000174,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000068b,0x0000000000000003,0x0000000000000000,0x0000000000002647\n"
".quad 0x000000000000000c,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000025f,0x0000000000100006,0x0000000000000000,0x0000000000002647\n"
".quad 0x0000000000000fb8,0x1e00000f00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000064d,0x0000000000000002,0x0000000000000000,0x00000000000035ff\n"
".quad 0x0000000000000065,0x0000000900000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000060e,0x0000000000000002,0x0000000000000000,0x0000000000003664\n"
".quad 0x0000000000000004,0x0000000900000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000295,0x0000000000000002,0x0000000000000000,0x0000000000003668\n"
".quad 0x0000000000000174,0x0000000900000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000005d3,0x0000000000000003,0x0000000000000000,0x00000000000037dc\n"
".quad 0x000000000000000c,0x0000000900000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001d2,0x0000000000100006,0x0000000000000000,0x00000000000037dc\n"
".quad 0x0000000000000960,0x1600000d00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000003d0,0x0000000000000002,0x0000000000000000,0x000000000000413c\n"
".quad 0x000000000000005d,0x0000000e00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000217,0x0000000000000002,0x0000000000000000,0x0000000000004199\n"
".quad 0x000000000000014c,0x0000000e00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000033d,0x0000000000000003,0x0000000000000000,0x00000000000042e5\n"
".quad 0x000000000000000c,0x0000000e00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000800000387,0x0000000000000003,0x0000000000000000,0x00000000000042e5\n"
".quad 0x0000000000000004,0x0000000e00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000145,0x0000000000100006,0x0000000000000000,0x00000000000042e5\n"
".quad 0x0000000000000a08,0x1a00000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000004b0,0x0000000000000002,0x0000000000000000,0x0000000000004ced\n"
".quad 0x0000000000000075,0x0000001300000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000018a,0x0000000000000002,0x0000000000000000,0x0000000000004d62\n"
".quad 0x000000000000014c,0x0000001300000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000041d,0x0000000000000003,0x0000000000000000,0x0000000000004eae\n"
".quad 0x000000000000000c,0x0000001300000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000800000467,0x0000000000000003,0x0000000000000000,0x0000000000004eae\n"
".quad 0x0000000000000008,0x0000001300000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000c2,0x0000000000100006,0x0000000000000000,0x0000000000004eae\n"
".quad 0x00000000000009a8,0x1400000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000788,0x0000000000000002,0x0000000000000000,0x0000000000005856\n"
".quad 0x000000000000005d,0x0000001800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000102,0x0000000000000002,0x0000000000000000,0x00000000000058b3\n"
".quad 0x000000000000014c,0x0000001800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000743,0x0000000000000003,0x0000000000000000,0x00000000000059ff\n"
".quad 0x000000000000000c,0x0000001800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000100006,0x0000000000000000,0x00000000000059ff\n"
".quad 0x0000000000000a10,0x1700000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000058b,0x0000000000000002,0x0000000000000000,0x000000000000640f\n"
".quad 0x0000000000000075,0x0000001c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000542,0x0000000000000002,0x0000000000000000,0x0000000000006484\n"
".quad 0x0000000000000004,0x0000001c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000076,0x0000000000000002,0x0000000000000000,0x0000000000006488\n"
".quad 0x000000000000014c,0x0000001c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000004fd,0x0000000000000003,0x0000000000000000,0x00000000000065d4\n"
".quad 0x000000000000000c,0x0000001c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000007d0,0x0000000000000002,0x0000000000000000,0x00000000000065d4\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000000000008,0x0000000000000000\n"
".quad 0x00000009000007df,0x0000000000000000,0x0000000000000000,0x00000000000065d8\n"
".quad 0x0000000000000010,0x0000002100000003,0x0000000000000004,0x0000000000000010\n"
".quad 0x000000080000002b,0x0000000000000003,0x0000000000000000,0x00000000000065e8\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000b9,0x0000000000000002,0x0000000000000000,0x00000000000065e8\n"
".quad 0x0000000000000090,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x36315a5f2e747865\n"
".quad 0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6e2e006269696969,0x5f2e6f666e692e76\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x666e692e766e2e00\n"
".quad 0x2e747865742e006f,0x646e614d36315a5f,0x5f31746f72626c65,0x7645664933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x6e692e766e2e0062,0x4d36315a5f2e6f66,0x6f72626c65646e61,0x4933316d735f3174\n"
".quad 0x6863753650764566,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x65742e0062696969,0x4d36315a5f2e7478,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c64,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x6e692e766e2e0062,0x4d36315a5f2e6f66,0x6f72626c65646e61\n"
".quad 0x4933316d735f3074,0x7645453631694c64,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x696969695f30535f,0x2e747865742e0062,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x2e0062696969695f,0x2e6f666e692e766e\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x2e0062696969695f\n"
".quad 0x315a5f2e74786574,0x626c65646e614d38,0x735f315344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x766e2e0062696969,0x5a5f2e6f666e692e\n"
".quad 0x6c65646e614d3831,0x5f315344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x742e006269696969,0x38315a5f2e747865,0x72626c65646e614d\n"
".quad 0x6d735f305344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x2e766e2e00626969,0x315a5f2e6f666e69,0x626c65646e614d38,0x735f305344746f72\n"
".quad 0x686375365033316d,0x6666696969347261,0x695f536666666666,0x766e2e0062696969\n"
".quad 0x2e6465726168732e,0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x2e0062696969695f,0x6c61636f6c2e766e,0x6e614d36315a5f2e,0x30746f72626c6564\n"
".quad 0x4c664933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x0062696969695f30,0x736e6f632e766e2e,0x5a5f2e30746e6174\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x766e2e0062696969\n"
".quad 0x2e6465726168732e,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x2e0062696969695f,0x6c61636f6c2e766e,0x6e614d36315a5f2e,0x30746f72626c6564\n"
".quad 0x4c644933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x0062696969695f30,0x736e6f632e766e2e,0x5a5f2e30746e6174\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x766e2e0062696969\n"
".quad 0x2e6465726168732e,0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x6f632e766e2e0062,0x3631746e6174736e,0x6e614d36315a5f2e,0x31746f72626c6564\n"
".quad 0x45644933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x632e766e2e006269,0x30746e6174736e6f,0x6e614d36315a5f2e\n"
".quad 0x31746f72626c6564,0x45644933316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x732e766e2e006269,0x5a5f2e6465726168\n"
".quad 0x6c65646e614d3831,0x5f315344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x6e2e006269696969,0x6174736e6f632e76,0x315a5f2e3631746e\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x766e2e0062696969,0x6e6174736e6f632e,0x4d38315a5f2e3074\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x732e766e2e006269,0x5a5f2e6465726168,0x6c65646e614d3831\n"
".quad 0x5f305344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x6e2e006269696969,0x6174736e6f632e76,0x315a5f2e3631746e,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x766e2e0062696969,0x6e6174736e6f632e,0x4d38315a5f2e3074,0x6f72626c65646e61\n"
".quad 0x316d735f30534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x732e766e2e006269,0x5a5f2e6465726168,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764566493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x0062696969695f30,0x736e6f632e766e2e,0x5a5f2e30746e6174,0x6c65646e614d3631\n"
".quad 0x6d735f31746f7262,0x3650764566493331,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x0062696969695f30,0x736e6f632e766e2e,0x2e003431746e6174\n"
".quad 0x632e766e2e6c6572,0x31746e6174736e6f,0x4d36315a5f000034,0x6f72626c65646e61\n"
".quad 0x4933316d735f3174,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x315a5f0062696969,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x5f0062696969695f,0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x5a5f006269696969,0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c66493331\n"
".quad 0x6863753650764545,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x315a5f0062696969,0x626c65646e614d38,0x735f315344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x315a5f0062696969,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x6f6c620062696969,0x65746e756f436b63,0x0000000000000072,0x0000000000000000\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000002,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000003,0x0000000000000000,0x0003000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000023,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000001c,0x000000000a100000,0x0003000000000000\n"
".quad 0x000000000000001f,0x0000000000000000,0x0003000000000000,0x0000000000000024\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000018,0x0000000009a80000\n"
".quad 0x0003000000000000,0x000000000000001a,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000013,0x000000000a080000,0x0003000000000000,0x0000000000000015\n"
".quad 0x0000000000000000,0x0003000000000000,0x000000000000000e,0x0000000009600000\n"
".quad 0x0003000000000000,0x0000000000000010,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000009,0x000000000fb80000,0x0003000000000000,0x000000000000000c\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000004,0x000000000d600000\n"
".quad 0x0003000000000000,0x0000000000000007,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000011,0x0000000000000000,0x0003000000000000,0x0000000000000012\n"
".quad 0x0000000000000000,0x0003000000000000,0x000000000000000f,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000016,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000017,0x0000000000000000,0x0003000000000000,0x0000000000000014\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000020,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000001e,0x0000000000000000,0x0003000000000000\n"
".quad 0x000000000000001d,0x0000000000000000,0x0003000000000000,0x000000000000000d\n"
".quad 0x0000000000000000,0x0003000000000000,0x000000000000000b,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000000a,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000008,0x0000000000000000,0x0003000000000000,0x0000000000000006\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000005,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000001b,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000019,0x0000000000000000,0x0003000000000000,0x0000000000000021\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000022,0x0000000000000000\n"
".quad 0x1012000000010000,0x000000000000001c,0x000000000a100000,0x10120000003b0000\n"
".quad 0x0000000000000018,0x0000000009a80000,0x1012000000750000,0x0000000000000013\n"
".quad 0x000000000a080000,0x1012000000b40000,0x000000000000000e,0x0000000009600000\n"
".quad 0x1012000000f30000,0x0000000000000009,0x000000000fb80000,0x1012000001230000\n"
".quad 0x0000000000000004,0x000000000d600000,0x0011000001530000,0x0000000000000023\n"
".quad 0x0000000000040000,0x440400005de40000,0x00008803dc042800,0x0000fcf1dc032c00\n"
".quad 0x000084039c04190e,0x0000fce1dc032c00,0x0003400000071900,0x0000000021f46000\n"
".quad 0x780000009de44000,0x0000fc00dde42800,0x000004001de22800,0x200000201c051800\n"
".quad 0x400171201c04547e,0x400173f5dc031804,0x000010001c001a8e,0x400173f0ddc3c800\n"
".quad 0xfffff8001c026800,0x000001201c04083f,0x400170009c031486,0x000009209f845000\n"
".quad 0x000008001c431c00,0x000010009c432000,0x400170201e035000,0x40017003dc032008\n"
".quad 0x4001700005031b0e,0xc000042084034800,0x40017003dc034800,0xc000042084031b0e\n"
".quad 0x4001700005034800,0x000008309c044800,0x000000315c042014,0x000023f09c852014\n"
".quad 0x000003f11cb5c900,0x0000ffffdc04c900,0x000003f01c8550ee,0x40018003dc03c100\n"
".quad 0x0000000005e71b0e,0x000013f09c858000,0x000023f01c85c100,0x002c80000007c100\n"
".quad 0x400020241c036000,0x400030045c03201c,0x4000a103dc23201e,0x4000b113dc23188e\n"
".quad 0x0000000025f41882,0x000041201e044000,0x40013000dde41800,0x000045215e042800\n"
".quad 0x8000d0009c001800,0x8000f0519c003006,0x40013000de003006,0x40013051de003004\n"
".quad 0x4000d0311e00300c,0x4000f0721e005000,0x00000c20dd005000,0x00001c61dd005000\n"
".quad 0x400130001d005000,0x40013050dd003006,0x000000401c00300e,0x00000c80dc005000\n"
".quad 0x000193f25c265000,0x4000e0001c001400,0x00002421de845000,0x400100311c001c00\n"
".quad 0x000000215c005000,0x0000fc73dc235000,0x00001060dc00190e,0x000008509d005000\n"
".quad 0x00001831dd005000,0x000008019d005000,0x00001c411d005000,0x0005e00085e75000\n"
".quad 0x4000043025004000,0x40000451e5003006,0x00001030a400300a,0x0000185264005800\n"
".quad 0x4000043225005800,0x40000452a5003000,0x00001032e400300e,0x0000208324003004\n"
".quad 0x00001854e4005800,0x000028a364003012,0x00000c3024005800,0x0000203265003016\n"
".quad 0x00000c3326005000,0x00001450a4003018,0x00002851e5003026,0x00001454a6005000\n"
".quad 0x000024832400301a,0x00000c3366003018,0x0000145526003000,0x00001ca564003004\n"
".quad 0x0000248224003024,0x00003404a5003018,0x000034b2e5005000,0x0000502365005000\n"
".quad 0x00001ca324005000,0x00000c32a500302a,0x00005134e5003024,0x0000249224005000\n"
".quad 0x0000145365003010,0x000028b26400301a,0x00001c72a4005000,0x00003532e4003018\n"
".quad 0x00002481e4005000,0x00002ca224005000,0x0000104264005000,0x00001862e400300e\n"
".quad 0x0000240564003010,0x00002c2524005000,0x00000152a5005000,0x0000094325005000\n"
".quad 0x4001100025e45000,0x40012000a5e42800,0x0000fc01e5e42800,0x0000fc0225e42800\n"
".quad 0x00002894a5002800,0x000030b4e5005000,0x00018000a5e75000,0x0000140005e44000\n"
".quad 0x0000180205e42800,0x00000c0085e42800,0x00001001c5e42800,0x0000fc04c5e42800\n"
".quad 0x0000fc0505e42800,0x0000fc0485e42800,0x0000fc0545e42800,0x0000fc0185e42800\n"
".quad 0x0000fc0145e42800,0x0000fc0105e42800,0x0000fc00c5e42800,0x4000c0025de42800\n"
".quad 0x0012600000072800,0xc0000493dc236000,0xfffffc925c03190e,0x0000000005f44800\n"
".quad 0x000055429c004000,0x000050a2dd005000,0x00002ca31d005000,0x00002d52dd005000\n"
".quad 0x000031431d005000,0x000030b2dc005000,0x00004cb2dc005000,0x000048b2dc005000\n"
".quad 0x00002ca31c005000,0x000028c29d005000,0x000028b29d005000,0x000028c29c005000\n"
".quad 0xd02000a3dc005000,0x0000000025f4208e,0x400004529d004000,0x40000432dd00300a\n"
".quad 0x400004529d003006,0x40000432dd003014,0x000f800000073016,0x000028531d006800\n"
".quad 0x00002c335d005000,0x00000c659c005000,0x00002ca61c005800,0x00001055dc005800\n"
".quad 0x00000c565e00302c,0x00000c559c003030,0x000034a29c00302e,0x00000c561e003032\n"
".quad 0x000030b2dc00302c,0x000061665d003014,0x000061729d005000,0x00000c50dd005000\n"
".quad 0xfffffc925c033032,0x000034c15c004800,0x00000ca0dc003016,0x00001430dc005000\n"
".quad 0x0000fc93dc235000,0x000010615c00190e,0x000055411d003006,0x000015619c005000\n"
".quad 0x00001860dc005000,0x000050429d005000,0x00001832dd005000,0x000028435d005000\n"
".quad 0x00002c331d005000,0x000054a55c005000,0x00002c62dd005000,0x000058629d005000\n"
".quad 0x000035435d005000,0x000030631d005000,0x000054d35d005000,0x000028519d005000\n"
".quad 0x000030b15c005000,0x00004cd2dc005000,0x000018529c005000,0x000048b15d005000\n"
".quad 0x000018a2dc005000,0x00001444dc005000,0x00002c331c005000,0x000001329c005000\n"
".quad 0x000008c19c005000,0x00004ca51d005000,0x000030635d005000,0x000011359d005000\n"
".quad 0x000050a55d005000,0x000034649d005000,0x000050051d005000,0x00000cc0dd005000\n"
".quad 0x000034211d005000,0x00005534dd005000,0x000058535d005000,0x000048c31d005000\n"
".quad 0x00000cb0dd005000,0x000051315c005000,0x000030411c005000,0x000034515c005000\n"
".quad 0x00000c40dc005000,0x00001482dc005000,0x00001c311c005000,0x00002ca15c005000\n"
".quad 0x00001060dc005000,0x000028531d005000,0x400004549d005000,0x000018329d00300a\n"
".quad 0x000030b19d005000,0x000028411d005000,0x400004331d005000,0x00001032dc003006\n"
".quad 0x000018535c005800,0x400004529d005800,0x000010369c003024,0x000018551c003016\n"
".quad 0x40000432dd00301a,0x000028a35c003018,0x00000c349c005800,0x00001454dc003034\n"
".quad 0x00002cb55c003028,0x000028531d005800,0x000014559e005000,0x00001455de00301a\n"
".quad 0x00000c361e003026,0x00000c365e00302a,0x000030a55c003024,0x00005d459d00302c\n"
".quad 0x00002c335d005000,0x00005d35dd005000,0x000065251d005000,0x000065a65d005000\n"
".quad 0x000034b61c005000,0x00000c369d003030,0x00001455dd003028,0x000030a51c00302e\n"
".quad 0x000034b55c00302a,0x00005d661c003030,0x000030c5dc005000,0x000069959c003028\n"
".quad 0x000034d51c005000,0x000061755c00302a,0x000059451c005000,0x000018661c005000\n"
".quad 0x00001045dc00302a,0x000061351c003028,0x00005d255c005000,0x000051559c005000\n"
".quad 0x00004d44dd005000,0x000051669d005000,0x00004d84dd005000,0x000069665d005000\n"
".quad 0x000049549d005000,0x000069569d005000,0x000065465d005000,0x000049749d005000\n"
".quad 0x000065a61c005000,0x00006135dc005000,0x00005d25dc005000,0x00005d661c005000\n"
".quad 0x000059859d005000,0x000059759d005000,0x0000000005e75000,0x000061659c00a800\n"
".quad 0xd0200163dc005000,0x0000000025e7208e,0xfff0c0001de7a800,0x000000001df44003\n"
".quad 0x4000c0901e034000,0x0000fc001c234800,0x0000fc03dc233212,0x0001c00085e7190e\n"
".quad 0x4001600024034000,0x000143f0a4064800,0x00000820a4041400,0x000147f0e4061c00\n"
".quad 0x00014bf124061400,0x00000c20e4041400,0x0000102124041c00,0x00000800a4a31c00\n"
".quad 0x00000c00e4a35000,0x0000100024a35000,0x0000082264045000,0x00000c2224041c00\n"
".quad 0x00000021e4041c00,0x00008000a5e71c00,0x0000fc01c5e44000,0x0000fc0205e42800\n"
".quad 0x0000fc0245e42800,0x000000001de42800,0x4000a1101ca34000,0x400080009de42020\n"
".quad 0x400153f3dc232800,0xc00010009c031a8e,0x400093f0dc432005,0x0000a00005e74800\n"
".quad 0x000025001c044000,0xc02020801c031c00,0xc02040701c032800,0xc02063f01c032800\n"
".quad 0x000000201c952800,0x400150001de49400,0x00000022dc852800,0xc00004001c038400\n"
".quad 0x000001211ec44800,0x000001215ec41c00,0x000001219ec41c00,0xc0007c029c231c00\n"
".quad 0x000011231c045800,0x000015235c041804,0x000019241c041804,0x000010c31c001804\n"
".quad 0xc00004a29c03c800,0x000010d35c006800,0x000011045c00c800,0xfffff8c31c02c800\n"
".quad 0x000000a29c03083f,0xfffff8d49c024800,0xfffff914dc02083f,0x000031235c04083f\n"
".quad 0xc00004a31c231486,0x000049229c045800,0x000034449c031486,0x00002c241c045000\n"
".quad 0x00002c245c041c00,0x400151041ca31c80,0x00002c22dc042012,0x400151145ca31d00\n"
".quad 0x00004d225c042010,0x000040c21c031486,0x00002854dc034800,0x000049241f845000\n"
".quad 0x000024651c031c00,0x400150b49ca35000,0x000040d35c43200e,0x000044c1dc03201a\n"
".quad 0x00002122dec44800,0x00004d245f841c00,0x000048c31c031c00,0x00005124df844800\n"
".quad 0x00001d249ec41c00,0x000044a41c431c00,0x00004c925c432014,0x00002cd29c432012\n"
".quad 0x000031245ec45000,0x000049035c431c00,0x00002842de035000,0x000044925c432016\n"
".quad 0x00002c45dc035000,0x000034541e03198e,0x000024645e032024,0x000010b2c9032022\n"
".quad 0xc00004a288034800,0x00004057dc034800,0x00004463dc03198e,0x000000821c83198e\n"
".quad 0x000010b5dc036800,0x000015040d031b0e,0xc00004d34c034800,0x0000191445034800\n"
".quad 0x0000fc87dc234800,0xc00004a288031b0e,0x00000071dc834800,0x00001509dc036800\n"
".quad 0xc000049244031b0e,0x000000c11c834800,0x00001913dc036800,0x00002922af841b0e\n"
".quad 0x0000fc75dc231c00,0xc00004d350031b0e,0x000003f15dc34800,0x0000fc47dc236800\n"
".quad 0xc000049244031b0e,0x000003f19dc34800,0x000035236b846800,0x000028511c231c00\n"
".quad 0x000025226f843100,0x000003f1ddc31c00,0x000034615c236800,0x000011011c043100\n"
".quad 0x000024719c231c00,0xc02020501c033100,0x000008219c052808,0x000000201c559400\n"
".quad 0x0000ffffdc049400,0x00034000000750ee,0x0000000021f46000,0x780000009de44000\n"
".quad 0x0000fc00dde42800,0x000004001de22800,0x400173f5dc031800,0x200000201c051a8e\n"
".quad 0x400171201c04547e,0x400173f0ddc31804,0x000010001c006800,0xfffff8001c02c800\n"
".quad 0x000001201c04083f,0x400170009c031486,0x000009209f845000,0x000008001c431c00\n"
".quad 0x000010009c432000,0x400170201e035000,0x40017003dc032008,0x4001700005031b0e\n"
".quad 0xc000042084034800,0x40017003dc034800,0xc000042084031b0e,0x4001700005034800\n"
".quad 0x000008309c044800,0x000000315c042014,0x000023f09c852014,0x000003f11cb5c900\n"
".quad 0x0000ffffdc04c900,0x000003f01c8550ee,0x40018003dc03c100,0xffcf200005e7188e\n"
".quad 0x000000001de74003,0x0000000000008000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000440c04460004,0x0c00000008000000\n"
".quad 0x1400000010000000,0x1c00000018000000,0x2400000020000000,0x2c00000028000000\n"
".quad 0x3400000030000000,0x3c00000038000000,0x4400000040000000,0x2100080a04000000\n"
".quad 0x0300450020000000,0xff000c1704004519,0x0000440010ffffff,0xff000c17040005f0\n"
".quad 0x000040000fffffff,0xff000c17040011f0,0x00003c000effffff,0xff000c17040011f0\n"
".quad 0x000038000dffffff,0xff000c17040011f0,0x000034000cffffff,0xff000c17040011f0\n"
".quad 0x000030000bffffff,0xff000c17040011f0,0x00002c000affffff,0xff000c17040011f0\n"
".quad 0x0000280009ffffff,0xff000c17040011f0,0x0000240008ffffff,0xff000c17040011f0\n"
".quad 0x0000200007ffffff,0xff000c17040011f0,0x00001c0006ffffff,0xff000c17040011f0\n"
".quad 0x0000180005ffffff,0xff000c17040011f0,0x0000140004ffffff,0xff000c17040011f0\n"
".quad 0x0000100003ffffff,0xff000c17040011f0,0x00000c0002ffffff,0xff000c17040011f0\n"
".quad 0x0000080001ffffff,0xff000c17040011f0,0x0000000000ffffff,0xa400080d040021f0\n"
".quad 0xe400000020002301,0x042800440400005d,0x032c00000088059c,0x04190e0000fd61dc\n"
".quad 0x032c00000084055c,0x0719000000fd51dc,0xf460000003400000,0xe440000000000021\n"
".quad 0xe42800780000009d,0xe228000000fc00dd,0x051800000004001d,0x04547e200000201c\n"
".quad 0x031804400171201c,0x001a8e400173f5dc,0xc3c800000010001c,0x026800400173f0dd\n"
".quad 0x04083ffffff8001c,0x031486000001201c,0x845000400170009c,0x431c00000009209f\n"
".quad 0x432000000008001c,0x035000000010009c,0x032008400170201e,0x031b0e40017003dc\n"
".quad 0x0348004001700005,0x034800c000042084,0x031b0e40017003dc,0x034800c000042084\n"
".quad 0x0448004001700005,0x042014000008309c,0x852014000000315c,0xb5c900000023f09c\n"
".quad 0x04c900000003f11c,0x8550ee0000ffffdc,0x03c100000003f01c,0xe71b0e40018003dc\n"
".quad 0x8580000000000005,0x85c100000013f09c,0x07c100000023f01c,0x0360000035e00000\n"
".quad 0x03202a400020211c,0x23202c400030015c,0x23188e4000a043dc,0xf418824000b053dc\n"
".quad 0xa340000000000025,0xe420084000a0519c,0x032800400080001d,0x232001c00010609c\n"
".quad 0x43198e0000fc43dc,0x854800400093f0dc,0x04840000000021dc,0x041c0000001c201c\n"
".quad 0x041c8000001c25dc,0xe71d0000001c261c,0x8540000001e00085,0x0487fffffff021e4\n"
".quad 0x041c8000001c2264,0x031c0000001c2224,0x04480000005c9265,0xc41d0000001c21e4\n"
".quad 0x031c000000252266,0x0348000000008225,0x23480000006071e5,0xc41a0ec0002895e4\n"
".quad 0xc41c000000212226,0x231c0000001d21e6,0x231a24c0002885e4,0x041a24c0002875e4\n"
".quad 0xe42014c00007f1e4,0x034000000000001d,0xe44800c00004421c,0x2328000000fc01c5\n"
".quad 0xe71b0e4000a083dc,0x8540000001e00085,0x0484000000102224,0x041c8000002022a4\n"
".quad 0x031c000000202264,0x04480000005ca2a5,0x031d000000202224,0xc448000000009265\n"
".quad 0x031c0000002922a6,0xc448000000608225,0x231c000000252266,0xc41a0ec00028a5e4\n"
".quad 0x231c000000212226,0x231a24c0002895e4,0x041a24c0002885e4,0x032014c00007f224\n"
".quad 0x23480000002071e4,0xe7198e0000fc53dc,0x0340000002600085,0xe448004000a06225\n"
".quad 0x0328004000800265,0x432013c000108224,0x854800400093f264,0x0484000000008224\n"
".quad 0x041c8000002022a4,0x031c000000202264,0x04480000005ca2a5,0xc41d000000202224\n"
".quad 0x031c0000002922a6,0x0348000000009265,0x2348000000608225,0xc41a0ec00028a5e4\n"
".quad 0xc41c000000252266,0x231c000000212226,0x231a24c0002895e4,0x041a24c0002885e4\n"
".quad 0x032014c00007f224,0x03480000002071e4,0x234800c00004521c,0xe71b0e4000b083dc\n"
".quad 0x0340000002600085,0xe448004000a061a4,0x0328004000800225,0x432011c000106224\n"
".quad 0x854800400093f264,0x04840000000081a4,0x041c800000182264,0x031c000000182224\n"
".quad 0x04480000005c9265,0x031d0000001821a4,0xc448000000008225,0xc41c000000252266\n"
".quad 0x031c000000212226,0x23480000006061a5,0xc41a0ec0002895e4,0x231c0000001921a6\n"
".quad 0x231a24c0002885e4,0x041a24c0002865e4,0x032014c00007f1a4,0x23480000001871e4\n"
".quad 0xf4190e0000fc73dc,0x0440000000000005,0xe41800000011211e,0x042800400130019d\n"
".quad 0x001800000015221e,0x00300c8000d0415c,0x00300c8000f0825c,0x00300a400130419e\n"
".quad 0x003012400130829e,0x0050004000d061de,0x0050004000f0a2de,0x005000000018519d\n"
".quad 0x005000000028929d,0x00300c400130411d,0x003014400130819d,0x005000000010711c\n"
".quad 0x265000000018b19c,0x001400000193f31c,0x8450004000e0411c,0x001c00000030229e\n"
".quad 0x00500040010061dc,0x005000000010521c,0x23500000001c919c,0x00190e0000fca3dc\n"
".quad 0x005000000014815d,0x005000000024629d,0x005000000014425d,0xe7500000002871dd\n"
".quad 0x0040000005e00085,0x00300c4000046125,0x00301040000482a5,0x00580000001c6164\n"
".quad 0x0058000000248324,0x00300840000462e5,0x0030144000048365,0x00300a00001c63a4\n"
".quad 0x00301800002483e4,0x00580000002cb424,0x005800000034d464,0x00301c0000186124\n"
".quad 0x00500000002c6325,0x00301e0000208164,0x0030200000186426,0x00500000003482a5\n"
".quad 0x00302200002084a6,0x0030080000186466,0x003020000030b424,0x00300a00002084e6\n"
".quad 0x003024000028d524,0x00500000004444a5,0x005000000044e3a5,0x003020000030b2e4\n"
".quad 0x00500000004c5465,0x003028000028d424,0x00500000004cf3e5,0x0030240000186365\n"
".quad 0x0030220000208465,0x003016000030c2e4,0x005000000034e324,0x003020000028a364\n"
".quad 0x005000000044f3a4,0xe45000000030b2a4,0x0028000000fc03e5,0x005000000038d324\n"
".quad 0x00301400001c72e4,0x0030180000249424,0x00500000002c42a4,0x0050000000405324\n"
".quad 0x005000000010a365,0x005000000014c465,0xe45000000034b2e5,0xe428004001100125\n"
".quad 0xe428004001200165,0x0028000000fc03a5,0xe750000000450365,0xe440000001a000a5\n"
".quad 0xe428000000200105,0xe4280000002403c5,0xe428000000180145,0xe4280000001c0385\n"
".quad 0xe428000000fc0345,0xe428000000fc0305,0xe428000000fc02c5,0xe428000000fc0285\n"
".quad 0xe428000000fc0245,0xe428000000fc0205,0xe428000000fc01c5,0xe428000000fc0185\n"
".quad 0xe44000000000001d,0x0728004000c0041d,0x2360000012600000,0x03190ec0000503dc\n"
".quad 0xf44800fffffd065c,0x0040000000000005,0x005000000028c41c,0x005000000031045d\n"
".quad 0x005000000045049d,0x005000000044a45d,0x005000000048c49d,0x005000000049145c\n"
".quad 0x005000000035145c,0x00500000002d145c,0x005000000045049c,0x005000000041241d\n"
".quad 0x005000000041141d,0x005000000041241c,0xf4208ed0200103dc,0x0040000000000025\n"
".quad 0x003010400004841d,0x00300c400004645d,0x003020400004841d,0x073022400004645d\n"
".quad 0x006800000f800000,0x005000000040849d,0x00500000004464dd,0x005800000018951c\n"
".quad 0x00580000004506dc,0x00302800001c869c,0x003036000018871e,0x003034000018851c\n"
".quad 0x00303800004d071c,0x00302800001886de,0x003038000049171c,0x00500000006d441d\n"
".quad 0x00500000006da45d,0x033020000018819d,0x004800fffffd965c,0x00303800004d221c\n"
".quad 0x005000000019119c,0x235000000020619c,0x00190e0000fd93dc,0x00300c00001c921c\n"
".quad 0x005000000028c1dd,0x005000000021425c,0x005000000030749d,0x005000000024919c\n"
".quad 0x00500000004874dd,0x005000000024641d,0x005000000029249c,0x00500000004cc4dd\n"
".quad 0x005000000050929d,0x005000000040645d,0x005000000040931d,0x005000000044941d\n"
".quad 0x005000000049345d,0x005000000028825d,0x005000000040c21c,0x005000000035131c\n"
".quad 0x005000000024829c,0x00500000002cc21d,0x005000000024a2dc,0x005000000020745c\n"
".quad 0x00500000002c631c,0x005000000011129c,0x005000000014c25c,0x005000000044a49d\n"
".quad 0x005000000030935d,0x005000000048a4dd,0x00500000001d151d,0x005000000034941d\n"
".quad 0x005000000048449d,0x00500000004d145d,0x005000000018c19d,0x00500000003451dd\n"
".quad 0x005000000040c31d,0x005000000050835d,0x005000000018b19d,0x005000000049121c\n"
".quad 0x00500000003071dc,0x005000000034821c,0x005000000018719c,0x005000000020f2dc\n"
".quad 0x00500000003861dc,0x00500000002ca21c,0x00500000001c919c,0x005000000028831d\n"
".quad 0x003010400004835d,0x005000000024629d,0x00301a400004841d,0x005000000030b25d\n"
".quad 0x00500000002871dd,0x00300c40000462dd,0x005800000024831c,0x00580000001c629c\n"
".quad 0x003018000024831c,0x003016400004645d,0x00580000004104dc,0x00301400001c671c\n"
".quad 0x003018000020835c,0x005800000045129c,0x003026000020851e,0x00303800001862dc\n"
".quad 0x00301a00002086de,0x005000000040849d,0x00500000004464dd,0x003014000018629e\n"
".quad 0x003016000018675e,0x00500000006cc69d,0x003028000049051c,0x00500000006cd6dd\n"
".quad 0x005000000074b31d,0x00301400004d129c,0x005000000075c71d,0x003028000049051c\n"
".quad 0x00303600002086dd,0x003018000018631d,0x00301400004d129c,0x00500000006da69c\n"
".quad 0x003028000049251c,0x005000000031c31c,0x00301400004d329c,0x005000000069451c\n"
".quad 0x005000000030a29c,0x00302800002496dc,0x00301400001c769c,0x00500000006cd31c\n"
".quad 0x005000000068b29c,0x005000000030a51c,0x005000000034c35d,0x005000000031475d\n"
".quad 0x005000000035b35d,0x005000000075471d,0x00500000002ca2dd,0x005000000074a75d\n"
".quad 0x005000000070c71d,0x00500000002da2dd,0x005000000071d6dc,0x00500000006cd69c\n"
".quad 0x005000000068b69c,0x00500000006946dc,0x005000000051b51d,0xe75000000051a51d\n"
".quad 0x00a8000000000005,0x00500000006d451c,0xe7208ed0200143dc,0xe7a8000000000025\n"
".quad 0xf44003fff0c0001d,0x034000000000001d,0x2348004000c1911e,0x2332320000fc411c\n"
".quad 0xe7190e0000fc43dc,0x0340000001c00085,0x0648004001604124,0x061400000143f164\n"
".quad 0x041400000147f1a4,0x061c000000142164,0x04140000014bf1e4,0xa31c0000001821a4\n"
".quad 0x0450000000144164,0xa31c0000001c21e4,0xa3500000001841a4,0x04500000001c4124\n"
".quad 0x041c0000001422e4,0x041c000000182264,0xe71c000000102224,0xe4400000008000a5\n"
".quad 0xe428000000fc0205,0xe428000000fc0245,0xe428000000fc02c5,0xe44000000000001d\n"
".quad 0x032800400150011d,0xa34800c00004411c,0xc42016400150001c,0xc41c00000011215e\n"
".quad 0xc41c00000011219e,0x231c0000001121de,0x045800c0007c429c,0x041804000015231c\n"
".quad 0x041804000019235c,0x00180400001d23dc,0x03c800000010c31c,0x006800c00004a29c\n"
".quad 0x00c800000010d39c,0x02c800000010f3dc,0x03083ffffff8c35c,0x024800000010a31c\n"
".quad 0x04083ffffff8e39c,0x021486000035229c,0x23083ffffff8f3dc,0x045800c00004c35c\n"
".quad 0x04148600003d22dc,0xa31486000039231c,0x03201240015173dc,0xa35000000028539c\n"
".quad 0x032010400151845c,0x034800000000d01c,0x845000000030641c,0x031c00000039225f\n"
".quad 0x03480000003cd21c,0xc4500000002c749c,0x841c00000001239e,0x431c0000004123df\n"
".quad 0x032014000024a25c,0x844800000044d45c,0xc41c00000049241f,0x431c00000021235e\n"
".quad 0x435000000038925c,0x43201800003cc29c,0xc42016000040b2dc,0x031c0000004523de\n"
".quad 0x43201c000024531e,0x035000000034a29c,0x43198e00003055dc,0x03500000003cb2dc\n"
".quad 0x03201a000028635e,0x034800000014c309,0x03201e00002c739e,0x03198e00003467dc\n"
".quad 0x834800c000049248,0x036800000010001c,0x03198e00003873dc,0x031b0e000014c5dc\n"
".quad 0x034800000018d34d,0x834800c00004a28c,0x036800000010821c,0x23480000001ce385\n"
".quad 0x031b0e0000fc07dc,0x034800c000049248,0x031b0e000018d9dc,0x834800c00004b2c4\n"
".quad 0x036800000011115c,0x231b0e00001ce3dc,0x841b0e0000fc85dc,0x031c00000025226f\n"
".quad 0xc34800c00004a290,0x236800000013f01d,0x031b0e0000fc57dc,0xc34800c00004b2c4\n"
".quad 0x846800000013f19d,0x231c0000002922ab,0x843108000024001c,0xc31c0000002d22ef\n"
".quad 0x236800000013f1dd,0x043108000028615c,0x231c00000001001c,0x03310800002c711c\n"
".quad 0x052800c02020501c,0x559400000008211c,0x049400000000201c,0x0750ee0000ffffdc\n"
".quad 0xf460000003400000,0xe440000000000021,0xe42800780000009d,0xe228000000fc00dd\n"
".quad 0x031800000004001d,0x051a8e400173f5dc,0x04547e200000201c,0xc31804400171201c\n"
".quad 0x006800400173f0dd,0x02c800000010001c,0x04083ffffff8001c,0x031486000001201c\n"
".quad 0x845000400170009c,0x431c00000009209f,0x432000000008001c,0x035000000010009c\n"
".quad 0x032008400170201e,0x031b0e40017003dc,0x0348004001700005,0x034800c000042084\n"
".quad 0x031b0e40017003dc,0x034800c000042084,0x0448004001700005,0x042014000008309c\n"
".quad 0x852014000000315c,0xb5c900000023f09c,0x04c900000003f11c,0x8550ee0000ffffdc\n"
".quad 0x03c100000003f01c,0xe7188e40018003dc,0xe74003ffc5c00005,0x008000000000001d\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x4600040000000000,0x0000000000440c04,0x0000000c00000008,0x0000001400000010\n"
".quad 0x0000001c00000018,0x0000002400000020,0x0000002c00000028,0x0000003400000030\n"
".quad 0x0000003c00000038,0x0000004400000040,0x0000001e00080a04,0x0045190300450020\n"
".quad 0xffffffff000c1704,0x0005f00000440010,0xffffffff000c1704,0x0011f0000040000f\n"
".quad 0xffffffff000c1704,0x0011f000003c000e,0xffffffff000c1704,0x0011f0000038000d\n"
".quad 0xffffffff000c1704,0x0011f0000034000c,0xffffffff000c1704,0x0011f0000030000b\n"
".quad 0xffffffff000c1704,0x0011f000002c000a,0xffffffff000c1704,0x0011f00000280009\n"
".quad 0xffffffff000c1704,0x0011f00000240008,0xffffffff000c1704,0x0011f00000200007\n"
".quad 0xffffffff000c1704,0x0011f000001c0006,0xffffffff000c1704,0x0011f00000180005\n"
".quad 0xffffffff000c1704,0x0011f00000140004,0xffffffff000c1704,0x0011f00000100003\n"
".quad 0xffffffff000c1704,0x0011f000000c0002,0xffffffff000c1704,0x0011f00000080001\n"
".quad 0xffffffff000c1704,0x0021f00000000000,0x002301a400080d04,0x00005de400000020\n"
".quad 0x8801dc0428004404,0xfc71dc032c000000,0x84019c04190e0000,0xfc61dc032c000000\n"
".quad 0x6000000719000000,0x00105d0360000003,0x000021f44800c002,0x00009de440000000\n"
".quad 0xfc00dde428007800,0x04001de228000000,0x53f5dc0318000000,0x00201c051a8e4001\n"
".quad 0x51201c04547e2000,0x53f0ddc318044001,0x10001c0068004001,0xf8001c02c8000000\n"
".quad 0x01201c04083fffff,0x50009c0314860000,0x09209f8450004001,0x08001c431c000000\n"
".quad 0x10009c4320000000,0x50201e0350000000,0x5003dc0320084001,0x500005031b0e4001\n"
".quad 0x0420840348004001,0x5003dc034800c000,0x042084031b0e4001,0x500005034800c000\n"
".quad 0x08309c0448004001,0x00315c0420140000,0x23f09c8520140000,0x03f11cb5c9000000\n"
".quad 0xffffdc04c9000000,0x03f01c8550ee0000,0x6003dc03c1000000,0x000005e71b0e4001\n"
".quad 0x00121c0380000000,0x00125c034800c000,0x13f01c854800c001,0x23f0dc85c1000000\n"
".quad 0x20011c03c1000000,0x3030dc0350004000,0x18401c03200e4000,0xc000000748000000\n"
".quad 0x10001e036000001b,0x40009c036000c000,0xa0015c234800c000,0xa0209c23080e4000\n"
".quad 0x14209d03080e4000,0xfc23dc2348000000,0xb035dc231a0e0000,0xa00029e718824000\n"
".quad 0xe00000074000001a,0xa00025e760000001,0x10615e0340000001,0x14411c836000c000\n"
".quad 0x0012dc0340000000,0x08415c034800c001,0x00001de448000000,0x11229e0440000000\n"
".quad 0xd0031de418000000,0x04411c0328004000,0x10a29c004800c000,0x1445dc2330184001\n"
".quad 0x00b29c851a8e0000,0x10b2dc03c8000000,0x000009e74800c000,0x73f11c364003ffff\n"
".quad 0x10211e8414000001,0x0d215e041c000000,0xe0029de418000000,0xfc45dc2328004000\n"
".quad 0x00139c851a8e0000,0xc0011de4c0000001,0x10515c0028004000,0xc000a9e730144001\n"
".quad 0xf002c9e440000000,0x140349e428004000,0x000309e428000000,0x1453c80028004001\n"
".quad 0x38e4080058000000,0xe00089e758000000,0x3802e9e440000000,0x140329e428000000\n"
".quad 0xfc0429e428000000,0xfc03e9e428000000,0xfc0369e428000000,0xfc03a9e428000000\n"
".quad 0x00001de428000000,0xfc27dc2340000000,0xa0000007190e0000,0x00000df460000005\n"
".quad 0xfc029de440000000,0x2000000728000000,0xc000000768000005,0xfc411c0370000003\n"
".quad 0xc00000074800ffff,0xfc47dc2360000000,0x60000de7198e0000,0x3d045c0040000000\n"
".quad 0x0117dc0050000000,0x00002de7220ed020,0x20a2dc53b0000000,0x04a29c0340000000\n"
".quad 0x00b11c854800c000,0x2827dc23c8000000,0x00000de7190e0000,0x24a11c43a8000000\n"
".quad 0x00439c8540000000,0xc000a9e7c0000000,0xf002c9e440000000,0x000309e428004000\n"
".quad 0x140349e428004001,0x1453c80028000000,0x38e4080058000000,0xe00089e758000000\n"
".quad 0x3802e9e440000000,0x140329e428000000,0xfc0429e428000000,0xfc03e9e428000000\n"
".quad 0xfc0369e428000000,0xfc03a9e428000000,0x00001de428000000,0xc0011de440000000\n"
".quad 0x00001de728004000,0x34e35c00b0000000,0x2827dc2358000000,0x3d039d001a8e0000\n"
".quad 0x34d35c0050000000,0x38b39c0050000000,0x34c35c0050000000,0x38e41c0050000000\n"
".quad 0x34d3dc0058000000,0x00002de758000000,0xe0001de7a8000000,0x00001df44003fffa\n"
".quad 0x000025e740000000,0xa0301ca340000010,0x0013dc0320004000,0x08009c034800c000\n"
".quad 0x08011e0348000000,0x33f3dc236000c000,0x08215e03190e4001,0x00f01c856000c000\n"
".quad 0xfc05dc23c0000000,0xc0002a03198e0000,0xfc0009e448004000,0xfc05dc2328000000\n"
".quad 0x00f01c85190e0000,0xe00089e7c8000000,0x23f0a80640000001,0x0820a80414000001\n"
".quad 0x27f0e8061c000000,0x0c20e80414000001,0x2bf2a8061c000000,0x4000280314000001\n"
".quad 0x2822a80448004001,0x0800a8a31c000000,0x00f0288550000000,0x0c00e8a3c8000000\n"
".quad 0x2802a8a350000000,0x0c24e80450000000,0x282428041c000000,0x082028041c000000\n"
".quad 0x8000a9e71c000000,0xfc0409e440000000,0xfc04c9e428000000,0xfc0009e428000000\n"
".quad 0x00001de428000000,0x80409c0340000000,0x93f0dc4348014000,0xc00025e748004000\n"
".quad 0x01001c0440000000,0x21301c031c000000,0x41001c032800c020,0x63f01c032800c020\n"
".quad 0x00201c852800c020,0x60001de794000000,0x30029de44000000a,0x00249c8528004001\n"
".quad 0x04a29c0384000000,0x29231ec44800c000,0x7ca2dc231c000000,0x31235c045800c000\n"
".quad 0x04b2dc0318040000,0x10d35c006800c000,0x28b2dc03c8000000,0xf8d35c0248000000\n"
".quad 0x04b45c23083fffff,0x35235c045800c000,0x34c2dc0314860000,0x2d255f8450000000\n"
".quad 0x2922dec41c000000,0x48239c041c000000,0x30e01ca31c000000,0x01139c0320004001\n"
".quad 0x54d01c4348000000,0x39251ec4201a0000,0x2d235c041c000000,0x50001c4318040000\n"
".quad 0x10d55c0050000000,0x00c35e03c8000000,0x28e39c8320280000,0xf9551c0268000000\n"
".quad 0x34c5dc03083fffff,0x30d34903198e0000,0x51251c0448000000,0x30dbdc0314860000\n"
".quad 0x040008031b0e0000,0x50b31c034800c000,0x29235ec450000000,0x31231f841c000000\n"
".quad 0xfce7dc231c000000,0x31431c431b0e0000,0x0400140320280000,0x48251c044800c000\n"
".quad 0x01202f841c800000,0x31451ca31c000000,0x48249c0420264001,0x3524dc041d000000\n"
".quad 0x31249ca318040000,0x1134dc0020204001,0x51141c03c8000000,0xf934dc0248000000\n"
".quad 0x49149c03083fffff,0x4d24dc0448000000,0x41245ec414860000,0x4cd55c031c000000\n"
".quad 0x44c31c4350000000,0x55251f8450000000,0x30b45e031c000000,0x5134dc4320220000\n"
".quad 0x44bddc0320260000,0x49251ec4198e0000,0x2d1459031c000000,0x5134dc4348000000\n"
".quad 0x2d15dc0350000000,0x4cd51e031b0e0000,0x2902dc8320280000,0x50d9dc0368000000\n"
".quad 0x04c31803198e0000,0x354511034800c000,0x0534d00348000000,0xfcbbdc234800c000\n"
".quad 0x29239c831b0e0000,0x04c3080368000000,0x2bf2ddc34800c000,0x3549dc0368000000\n"
".quad 0xfce5dc231b0e0000,0x312337841b0e0000,0x00b01c231c000000,0x0534d00331140000\n"
".quad 0x2bf35dc34800c000,0x2bf39dc368000000,0x01001c0468000000,0x4d24eb841c000000\n"
".quad 0x30d2dc231c000000,0x4ce29c2331140000,0x20b01c0331140000,0x08229c052800c020\n"
".quad 0x00201c4594000000,0x10411c0394000000,0x10f3dc034800c000,0x1445dc234800c000\n"
".quad 0xc00009e71a8e0000,0x00001df44003fff0,0xffffdc0440000000,0x4000000750ee0000\n"
".quad 0x000021f460000003,0x00009de440000000,0xfc00dde428007800,0x04001de228000000\n"
".quad 0x53f5dc0318000000,0x00201c051a8e4001,0x51201c04547e1000,0x53f15dc318044001\n"
".quad 0x10001c0068004001,0xf8001c02c8000000,0x01201c04083fffff,0x5000dc0314860000\n"
".quad 0x0d20df8450004001,0x0c001c431c000000,0x0800dc4320000000,0x50301e0350000000\n"
".quad 0x5003dc0320044001,0x500005031b0e4001,0x0430c40348004001,0x5003dc034800c000\n"
".quad 0x0430c4031b0e4001,0x500005034800c000,0x0c511c0448004001,0x0050dc0420140000\n"
".quad 0x23f11c8520140000,0x03f09cb5c9000000,0xffffdc04c9000000,0x03f01c8550ee0000\n"
".quad 0x6003dc03c1000000,0x800005e7188e4001,0x00001de74003ffdf,0x0000000080000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x000000003c0c0400\n"
".quad 0x00000c0000000800,0x0000140000001000,0x00001c0000001800,0x0000240000002000\n"
".quad 0x00002c0000002800,0x0000340000003000,0x00003c0000003800,0x00001500080a0400\n"
".quad 0x3d1903003d002000,0xffffff000c170400,0x05f000003c000eff,0xffffff000c170400\n"
".quad 0x11f0000038000dff,0xffffff000c170400,0x11f0000034000cff,0xffffff000c170400\n"
".quad 0x11f0000030000bff,0xffffff000c170400,0x11f000002c000aff,0xffffff000c170400\n"
".quad 0x11f00000280009ff,0xffffff000c170400,0x11f00000240008ff,0xffffff000c170400\n"
".quad 0x11f00000200007ff,0xffffff000c170400,0x11f000001c0006ff,0xffffff000c170400\n"
".quad 0x11f00000180005ff,0xffffff000c170400,0x11f00000140004ff,0xffffff000c170400\n"
".quad 0x11f00000100003ff,0xffffff000c170400,0x11f000000c0002ff,0xffffff000c170400\n"
".quad 0x11f00000080001ff,0xffffff000c170400,0x21f00000000000ff,0x2501bc00080d0400\n"
".quad 0x005de40000002000,0x051c042800440400,0x41dc032c00000088,0x04dc04190e0000fd\n"
".quad 0x31dc032c00000084,0x00000719000000fd,0x105d036000000360,0x0021f44800c00300\n"
".quad 0x009de44000000000,0x00dde42800780000,0x001de228000000fc,0xf5dc031800000004\n"
".quad 0x201c051a8e4001b3,0x201c04547e200000,0xf0ddc318044001b1,0x001c0068004001b3\n"
".quad 0x001c02c800000010,0x201c04083ffffff8,0x009c031486000001,0x209f8450004001b0\n"
".quad 0x001c431c00000009,0x009c432000000008,0x201e035000000010,0x03dc0320084001b0\n"
".quad 0x0005031b0e4001b0,0x20840348004001b0,0x03dc034800c00004,0x2084031b0e4001b0\n"
".quad 0x0005034800c00004,0x309c0448004001b0,0x315c042014000008,0xf09c852014000000\n"
".quad 0xf11cb5c900000023,0xffdc04c900000003,0xf01c8550ee0000ff,0x03dc03c100000003\n"
".quad 0x0005e71b0e4001c0,0x155c038000000000,0x159c034800c00000,0xf01c854800c00100\n"
".quad 0x009c03c100000013,0x0000075000400020,0x201c036000001ec0,0x061e03480000004c\n"
".quad 0x80dc036000c00010,0xf01c854800c00041,0x811c23c100000023,0x30dc23080e4000a1\n"
".quad 0x365d03080e4000a0,0x05dc034800000010,0x93dc232028400030,0x75dc231a0e0000fd\n"
".quad 0x0029e718824000b1,0x0000074000001d40,0x0025e76000000220,0x301e0340000001e0\n"
".quad 0x201c836000c00011,0x125c034000000000,0x021c034800c00100,0xf11c864800000064\n"
".quad 0x309e041400000163,0xf15c861800000001,0x001c031400000173,0xf19c864800c00004\n"
".quad 0x05dc2314000000e3,0xf1dc861a8e000020,0x209c0114000000f3,0x909ca5200c000010\n"
".quad 0x925c03c800000000,0x0009e74800c00020,0xf01c364003fffea0,0xf11c8614000001d3\n"
".quad 0x201e841400000163,0xf15c861c00000000,0x309e041400000173,0xf19c86180000005d\n"
".quad 0x05dc231400000103,0xf1dc861a8e0000fc,0x001de41400000113,0x131ca528004000c0\n"
".quad 0x211c01c000000100,0x00a9e7200c000010,0x0189e44000000120,0x01c9e42800400120\n"
".quad 0x0209e42800400130,0x0249e42800400140,0x0289e42800400150,0x4088012800000010\n"
".quad 0xc388015000000010,0x02c9e45000000030,0x0089e72800000014,0x01a9e44000000180\n"
".quad 0x01e9e42800000030,0x0229e42800000034,0x0269e42800000010,0x03a9e42800000014\n"
".quad 0x03e9e428000000fc,0x00a9e428000000fc,0x00e9e428000000fc,0x02a9e428000000fc\n"
".quad 0x02e9e428000000fc,0x0329e428000000fc,0x0369e428000000fc,0x97dc2328000000fc\n"
".quad 0x000007190e0000fd,0x000df460000006c0,0x049de44000000000,0x00000728000000fc\n"
".quad 0x0000076800000640,0x001c0370000004e0,0x0000074800fffffc,0x07dc2360000000c0\n"
".quad 0x000de7198e0000fc,0xe41c014000000060,0x07dc014800000008,0x002de71a0ed00401\n"
".quad 0x209c53b000000000,0x249c034000000055,0x201c854800c00005,0x97dc23c800000000\n"
".quad 0x000de7190e000049,0x201c63a800000000,0x031ca54000000059,0x00a9e7c000000000\n"
".quad 0x0189e44000000120,0x01c9e42800400120,0x0209e42800400130,0x0249e42800400140\n"
".quad 0x0289e42800400150,0x4088012800000010,0xc388015000000010,0x02c9e45000000030\n"
".quad 0x0089e72800000014,0x01a9e440000001a0,0x01e9e42800000030,0x0229e42800000034\n"
".quad 0x0269e42800000010,0x03a9e42800000014,0x03e9e428000000fc,0x00a9e428000000fc\n"
".quad 0x00e9e428000000fc,0x02a9e428000000fc,0x02e9e428000000fc,0x0329e428000000fc\n"
".quad 0x0369e428000000fc,0x001de428000000fc,0x001de44000000000,0x001de728004000c0\n"
".quad 0xc29c01b000000000,0x97dc235000000028,0xe31d011a8e000049,0xa09c014800000008\n"
".quad 0x631c014800000028,0x829c014800000030,0xc39c014800000008,0xa09c015000000030\n"
".quad 0x002de75000000028,0x001de7a800000000,0x001df44003fff9c0,0x0025e74000000000\n"
".quad 0x701ca34000000fe0,0x145c0320304000a1,0x009c034800c00000,0xf3dc234800000064\n"
".quad 0x001e03190e400193,0x211e036000c00008,0x109c856000c00008,0x25dc23c000000001\n"
".quad 0x20aa03198e0000fc,0x0089e448004000c0,0x25dc2328000000fc,0x109c85190e0000fc\n"
".quad 0x0089e7c800000001,0x20a80340000001e0,0xf0e80648004001a0,0xf168061400000183\n"
".quad 0x20e8041400000187,0xf1a8061c0000000c,0x216804140000018b,0x10a8851c00000014\n"
".quad 0x20e8a3c800000001,0x21a804500000000c,0x2168a31c00000018,0x20a8a35000000014\n"
".quad 0x21a8045000000018,0x2428041c0000000c,0x2628041c00000014,0x00a9e71c00000008\n"
".quad 0x0609e44000000060,0x0409e428000000fc,0x0189e428000000fc,0x009c0328000000fc\n"
".quad 0xf0dc434801400080,0x0025e74800400093,0x015c0440000000c0,0x015c031c00000019\n"
".quad 0x815c03280ac02021,0xf15c03280ac02041,0x215c85280ac02063,0x001de79400000000\n"
".quad 0x015de44000000a60,0x249c852800400190,0x51dc038400000000,0x235ec44800c00004\n"
".quad 0x231ec41c0000001d,0x22dec41c0000001d,0x715c231c0000001d,0x221c045800c0007c\n"
".quad 0x229c041804000035,0x225c041804000031,0x821c00180400002d,0x515c03c800000010\n"
".quad 0xa29c006800c00004,0x925c00c800000010,0x83dc02c800000010,0xa29c02083ffffff8\n"
".quad 0x521c03083ffffff8,0x925c02480000001c,0x215c04083ffffff8,0x225c04148600003d\n"
".quad 0x83dc231486000025,0x239c045800c00004,0x221c041c00000048,0x25dc041c80000048\n"
".quad 0xe19ca31d00000048,0x849ca3200c400190,0x239c042020400190,0xb41c031486000029\n"
".quad 0xd29c035000000024,0xf21c035000000014,0xc19c034800000018,0x75dca35000000038\n"
".quad 0x229f842030400191,0xf49c031c00000029,0x261f844800000048,0x219f841c00000041\n"
".quad 0x241ec41c00000019,0x565c431c00000021,0xf29c03200a000028,0x215ec4480000005c\n"
".quad 0x93dc431c00000049,0xe39c432012000060,0x925c43201c000018,0x25dec45000000041\n"
".quad 0xf19c431c00000029,0xe39c435000000014,0xd3de03500000005c,0xb15e032020000024\n"
".quad 0xd7dc03200a000018,0xc5de03198e00003c,0xb9dc03202e000038,0xf3cd03198e000014\n"
".quad 0xc5dc034800000034,0x821c83198e00005c,0x924c03680000001c,0xfbdc034800c00004\n"
".quad 0x5151031b0e000034,0x619003480000002c,0x75c9034800c00004,0x87dc234800000031\n"
".quad 0x9254031b0e0000fc,0x241c834800c00004,0x59dc03680000001d,0xe388031b0e00002c\n"
".quad 0xa29c834800c00004,0x75dc03680000001c,0x226f841b0e000031,0x0bdc231c00000025\n"
".quad 0x6190031b0e0000fd,0xf15dc34800c00004,0xa7dc23680000001f,0xe388031b0e0000fc\n"
".quad 0xf21dc34800c00004,0x21b784680000001f,0x515c231c00000019,0x23af84310e000024\n"
".quad 0xf25dc31c00000039,0x819c23680000001f,0x015c04310e000018,0x91dc231c00000015\n"
".quad 0x615c03310e000038,0x21dc05280ac02020,0x215c459400000008,0x001c039400000000\n"
".quad 0x145c034800c00010,0x05dc234800c00011,0x0009e71a8e000010,0x001df44003fff0e0\n"
".quad 0xffdc044000000000,0x00000750ee0000ff,0x0021f46000000340,0x009de44000000000\n"
".quad 0x00dde42800780000,0x001de228000000fc,0xf5dc031800000004,0x201c051a8e4001b3\n"
".quad 0x201c04547e200000,0xf0ddc318044001b1,0x001c0068004001b3,0x001c02c800000010\n"
".quad 0x201c04083ffffff8,0x009c031486000001,0x209f8450004001b0,0x001c431c00000009\n"
".quad 0x009c432000000008,0x201e035000000010,0x03dc0320084001b0,0x0005031b0e4001b0\n"
".quad 0x20840348004001b0,0x03dc034800c00004,0x2084031b0e4001b0,0x0005034800c00004\n"
".quad 0x309c0448004001b0,0x315c042014000008,0xf09c852014000000,0xf11cb5c900000023\n"
".quad 0xffdc04c900000003,0xf01c8550ee0000ff,0x03dc03c100000003,0x0005e7188e4001c0\n"
".quad 0x001de74003ffdce0,0x0000008000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000003c0c040000,0x000c000000080000,0x0018000000100000,0x0028000000200000\n"
".quad 0x0038000000300000,0x0044000000400000,0x004c000000480000,0x0054000000500000\n"
".quad 0x001800080a040000,0x1903005500200000,0xffff000c17040055,0xf0000054000effff\n"
".quad 0xffff000c17040005,0xf0000050000dffff,0xffff000c17040011,0xf000004c000cffff\n"
".quad 0xffff000c17040011,0xf0000048000bffff,0xffff000c17040011,0xf0000044000affff\n"
".quad 0xffff000c17040011,0xf00000400009ffff,0xffff000c17040011,0xf00000380008ffff\n"
".quad 0xffff000c17040021,0xf00000300007ffff,0xffff000c17040021,0xf00000280006ffff\n"
".quad 0xffff000c17040021,0xf00000200005ffff,0xffff000c17040021,0xf00000180004ffff\n"
".quad 0xffff000c17040021,0xf00000100003ffff,0xffff000c17040011,0xf000000c0002ffff\n"
".quad 0xffff000c17040011,0xf00000080001ffff,0xffff000c17040011,0xf00000000000ffff\n"
".quad 0x01bc00080d040021,0x5de4000000200025,0x1c04280044040000,0xdc032c0000008801\n"
".quad 0x1c04190e0000fc41,0xdc032c0000008400,0x000719000000fc01,0x21f4600000034000\n"
".quad 0x9de4400000000000,0xdde4280078000000,0x5de228000000fc00,0x5c05180000000401\n"
".quad 0x9c04547e30000021,0xdc03180440015120,0x9c001a8e400153f5,0x5dc3c80000001020\n"
".quad 0x9c026800400153f1,0x9c04083ffffff820,0xdc03148600000920,0xdf84500040015020\n"
".quad 0x9c431c0000000d20,0xdc43200400000c20,0x9e03500000001820,0xdc03200c40015030\n"
".quad 0x85031b0e40015023,0xc403480040015020,0xdc034800c0000430,0xc4031b0e40015023\n"
".quad 0x85034800c0000430,0xdc04480040015020,0xdc04201400000c50,0xdc85201400000851\n"
".quad 0x9cb5c900000023f0,0xdc04c900000003f1,0x9c8550ee0000ffff,0xdc03c100000003f0\n"
".quad 0x05e71b0e40016023,0xdc85800000000000,0x9c85c100000013f0,0x0007c100000023f0\n"
".quad 0x5c036000001da000,0x9c03200040002031,0xdc23200840003022,0xdc23188e4000a053\n"
".quad 0x25f418824000b0a3,0xdca3400000000000,0x9de4200a4000a0a2,0x9c03280040008000\n"
".quad 0xdc232005c00010b0,0xdc43198e0000fc53,0x9c854800400093f0,0x9c04840000000021\n"
".quad 0x1c041c0000001824,0x5c041c8000001822,0x85e71d0000001822,0xa48540000001e000\n"
".quad 0x240487fffffff021,0xe4041c8000001823,0x25031c0000001821,0xa4044800000020c3\n"
".quad 0x26c41d0000001821,0xe5031c0000003123,0xa503480000004871,0xe423480000002461\n"
".quad 0xe6c41a0ec00028c5,0xa6c41c0000001d21,0xe4231c0000001921,0xe4231a24c0002875\n"
".quad 0x24041a24c0002865,0x1de42014c00007f3,0x9c03400000000000,0x05e44800c0000451\n"
".quad 0xdc2328000000fc03,0x85e71b0e4000a063,0xa48540000001e000,0x6404840000001021\n"
".quad 0xe4041c8000001823,0x65031c0000001821,0xa4044800000020d3,0xe5031d0000001821\n"
".quad 0x66c4480000004871,0xa5031c0000003523,0xe6c4480000002461,0xe4231c0000001d21\n"
".quad 0xa6c41a0ec00028d5,0xe4231c0000001921,0xe4231a24c0002875,0xa4041a24c0002865\n"
".quad 0x24032014c00007f1,0xdc234800000018c3,0x85e7198e0000fca3,0xa503400000026000\n"
".quad 0xe5e448004000a0b1,0xa403280040008001,0xe443200fc0001061,0xa4854800400093f1\n"
".quad 0x6404840000000061,0xe4041c8000001823,0x65031c0000001821,0xa4044800000020d3\n"
".quad 0x66c41d0000001821,0xe5031c0000003523,0xa503480000004871,0xe423480000002461\n"
".quad 0xe6c41a0ec00028d5,0xa6c41c0000001d21,0xe4231c0000001921,0xe4231a24c0002875\n"
".quad 0xa4041a24c0002865,0x24032014c00007f1,0x9c034800000018c3,0xdc234800c00004a1\n"
".quad 0x85e71b0e4000b063,0xa403400000026000,0xe5e448004000a0b1,0xa403280040008001\n"
".quad 0xe443200fc0001061,0xa4854800400093f1,0xe404840000000061,0xe4041c8000001822\n"
".quad 0xe5031c0000001821,0xa4044800000020b2,0xe5031d0000001821,0xe6c4480000004871\n"
".quad 0xe6c41c0000002d22,0xa5031c0000001d21,0xe423480000002461,0xa6c41a0ec00028b5\n"
".quad 0xe4231c0000001921,0xe4231a24c0002875,0xa4041a24c0002865,0x24032014c00007f1\n"
".quad 0xdc234800000018c3,0x05f4190e0000fcc3,0x5e04400000000000,0x9c26180000001521\n"
".quad 0xdde41400000173f1,0xde84280040011002,0x9e041c0000001821,0xdc23180000002921\n"
".quad 0x9c00190e0000fc73,0xdc0030168000d052,0x85e730168000e062,0xa5e440000000a000\n"
".quad 0x240028004000f001,0xe5e4580000002cb3,0x6400280040010001,0xa5e75800000028a3\n"
".quad 0x85e440000000c000,0xc5e4280000002801,0x45e4280000002c01,0x05e428000000fc03\n"
".quad 0x85e428000000fc03,0xc5e428000000fc02,0x5de428000000fc02,0xdc2328004000c001\n"
".quad 0x5c03190ec0000453,0x05e74800fffffc51,0x9c00400000024000,0x00075000000030d3\n"
".quad 0xdc00680000020000,0x25e7208ed02000e3,0x9c00a80000000000,0x1d00580000002ca2\n"
".quad 0x5c035000000030d3,0xdc004800fffffc51,0x9c005000000028a2,0xdc23500000003062\n"
".quad 0xdc00190e0000fc53,0x5c00500000002c72,0x1c005800000028a3,0x05e7580000002cb3\n"
".quad 0x9c00a80000000000,0xdc005000000034c3,0x25e7208ed02000e3,0x1de7a80000000000\n"
".quad 0x9e034003fffe4000,0x5c2348004000c051,0xdc23320a0000fc61,0x85e7190e0000fc53\n"
".quad 0xa40640000001c000,0xa4041400000123f1,0xe4061c0000001821,0xe4041400000127f1\n"
".quad 0xa4061c0000001c21,0x6403140000012bf2,0xa404480040014051,0xa4a31c0000002822\n"
".quad 0xe4a3500000001851,0xa4a3500000001c51,0xe404500000002852,0x64041c0000001823\n"
".quad 0xa4041c0000001c21,0xa5e71c0000002822,0x85e4400000008000,0x45e428000000fc02\n"
".quad 0xc5e428000000fc01,0x1de428000000fc03,0x9de4400000000000,0xdca3280040013001\n"
".quad 0x9c03201e40013123,0xdec44800c0000461,0x5ec41c0000001921,0x1ec41c0000001923\n"
".quad 0xdc041c0000001924,0x1c23180400001d22,0x9c045800c0007c63,0xdc00180400003523\n"
".quad 0x5c04c800000010b2,0x1c03180400004124,0x9c006800c00004c3,0x5c00c800000010e3\n"
".quad 0xdc02c80000001114,0x1c03083ffffff8b2,0x9c024800000018c3,0xdc04083ffffff8e3\n"
".quad 0x5c02148600002d22,0x1c23083ffffff914,0x9c045800c00004c3,0xdc03148600003923\n"
".quad 0x5c04500000002c74,0x9c03148600004524,0x5ca3480000003cc4,0xdf84200a40013081\n"
".quad 0xdc031c0000004d24,0x9ca35000000038d3,0x1c03201440013092,0x5ec4500000004502\n"
".quad 0x5c031c0000004922,0xdc434800000014c1,0xdf84201600004cb2,0x1f841c0000003d23\n"
".quad 0x9c031c0000002122,0xdc434800000028c2,0x1ec45000000024b2,0x9c431c0000001523\n"
".quad 0x5e03201c00003ce3,0xdc43201200002c72,0x9c43202200002113,0x1ec45000000030e3\n"
".quad 0xdc031c0000002922,0x1e03198e00002475,0xdc432018000038d3,0x49035000000020f3\n"
".quad 0x1e03480000001c92,0xdc03201000003d02,0xc803198e000030d9,0xdc034800c00004b2\n"
".quad 0xdc031b0e00001c97,0xdc83198e00002103,0x1103680000001921,0x5c834800000034c3\n"
".quad 0x9003680000001851,0x05034800c00004e3,0xcc03480000004082,0xdc234800c00004b2\n"
".quad 0xdc031b0e0000fc75,0xc4031b0e000034c9,0xdc234800c00004f3,0x5c831b0e0000fc57\n"
".quad 0xdc036800000018a2,0xeb841b0e00004083,0x90031c0000002d22,0x5dc34800c00004e3\n"
".quad 0xdc23680000001bf1,0xc4031b0e0000fc95,0xaf844800c00004f3,0xddc31c0000003923\n"
".quad 0x5c23680000001bf1,0xeb84310c00002c51,0x1dc31c0000003d23,0xdc23680000001bf2\n"
".quad 0x5c04310c00003871,0x9c231c0000001501,0x5c03310c00003c81,0x9c05280ac0202071\n"
".quad 0x5c55940000000821,0xdc04940000000021,0x000750ee0000ffff,0x21f4600000034000\n"
".quad 0x9de4400000000000,0xdde4280078000000,0x5de228000000fc00,0x5c05180000000401\n"
".quad 0x9c04547e30000021,0xdc03180440015120,0x9c001a8e400153f5,0x5dc3c80000001020\n"
".quad 0x9c026800400153f1,0x9c04083ffffff820,0xdc03148600000920,0xdf84500040015020\n"
".quad 0x9c431c0000000d20,0xdc43200400000c20,0x9e03500000001820,0xdc03200c40015030\n"
".quad 0x85031b0e40015023,0xc403480040015020,0xdc034800c0000430,0xc4031b0e40015023\n"
".quad 0x85034800c0000430,0xdc04480040015020,0xdc04201400000c50,0xdc85201400000851\n"
".quad 0x9cb5c900000023f0,0xdc04c900000003f1,0x9c8550ee0000ffff,0xdc03c100000003f0\n"
".quad 0x05e7188e40016023,0x1de74003ffde0000,0x0000800000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x00003c0c04000000,0x0c00000008000000\n"
".quad 0x1400000010000000,0x1c00000018000000,0x2400000020000000,0x2c00000028000000\n"
".quad 0x3400000030000000,0x3c00000038000000,0x2300080a04000000,0x03003d0020000000\n"
".quad 0xff000c1704003d19,0x00003c000effffff,0xff000c17040005f0,0x000038000dffffff\n"
".quad 0xff000c17040011f0,0x000034000cffffff,0xff000c17040011f0,0x000030000bffffff\n"
".quad 0xff000c17040011f0,0x00002c000affffff,0xff000c17040011f0,0x0000280009ffffff\n"
".quad 0xff000c17040011f0,0x0000240008ffffff,0xff000c17040011f0,0x0000200007ffffff\n"
".quad 0xff000c17040011f0,0x00001c0006ffffff,0xff000c17040011f0,0x0000180005ffffff\n"
".quad 0xff000c17040011f0,0x0000140004ffffff,0xff000c17040011f0,0x0000100003ffffff\n"
".quad 0xff000c17040011f0,0x00000c0002ffffff,0xff000c17040011f0,0x0000080001ffffff\n"
".quad 0xff000c17040011f0,0x0000000000ffffff,0x9800080d040021f0,0xe400000020002201\n"
".quad 0x042800440400005d,0x032c0000008804dc,0x04190e0000fd31dc,0x032c00000084049c\n"
".quad 0x0719000000fd21dc,0xf460000003400000,0xe440000000000021,0xe42800780000009d\n"
".quad 0xe228000000fc00dd,0x051800000004001d,0x04547e200000201c,0x0318044001b1201c\n"
".quad 0x001a8e4001b3f5dc,0xc3c800000010001c,0x0268004001b3f0dd,0x04083ffffff8001c\n"
".quad 0x031486000001201c,0x8450004001b0009c,0x431c00000009209f,0x432000000008001c\n"
".quad 0x035000000010009c,0x0320084001b0201e,0x031b0e4001b003dc,0x0348004001b00005\n"
".quad 0x034800c000042084,0x031b0e4001b003dc,0x034800c000042084,0x0448004001b00005\n"
".quad 0x042014000008309c,0x852014000000315c,0xb5c900000023f09c,0x04c900000003f11c\n"
".quad 0x8550ee0000ffffdc,0x03c100000003f01c,0xe71b0e4001c003dc,0x8580000000000005\n"
".quad 0x85c100000013f09c,0x07c100000023f01c,0x036000001f400000,0x032024400020221c\n"
".quad 0x232026400030031c,0x23188e4000a083dc,0xf418824000b0c3dc,0xa340000000000025\n"
".quad 0xe420104000a0c11c,0x032800400080001d,0x232001c00010439c,0x43198e0000fc83dc\n"
".quad 0x854800400093f3dc,0x048400000000e09c,0x041c00000008201c,0x041c80000008251c\n"
".quad 0xe71d00000008255c,0x8540000001e00085,0x0487fffffff0e0a4,0x041c800000082164\n"
".quad 0x031c0000000820e4,0x0448000000505165,0xc41d0000000820a4,0x031c000000152166\n"
".quad 0x03480000000030e5,0x23480000005420a5,0xc41a0ec0002855e4,0xc41c0000000d20e6\n"
".quad 0x231c0000000920a6,0x231a24c0002835e4,0x041a24c0002825e4,0xe42014c00007f164\n"
".quad 0x034000000000001d,0xe44800c00004809c,0x2328000000fc0145,0xe71b0e4000a023dc\n"
".quad 0x8540000001e00085,0x048400000010e0a4,0x041c8000000821a4,0x031c0000000820e4\n"
".quad 0x04480000005061a5,0x031d0000000820a4,0xc4480000000030e5,0x031c0000001921a6\n"
".quad 0xc4480000005420a5,0x231c0000000d20e6,0xc41a0ec0002865e4,0x231c0000000920a6\n"
".quad 0x231a24c0002835e4,0x041a24c0002825e4,0x032014c00007f0a4,0x2348000000085164\n"
".quad 0xe7198e0000fcc3dc,0x0340000002600085,0xe448004000a040a5,0x03280040008000e5\n"
".quad 0x432007c0001020a4,0x854800400093f0e4,0x04840000000020a4,0x041c8000000821a4\n"
".quad 0x031c0000000820e4,0x04480000005061a5,0xc41d0000000820a4,0x031c0000001921a6\n"
".quad 0x03480000000030e5,0x23480000005420a5,0xc41a0ec0002865e4,0xc41c0000000d20e6\n"
".quad 0x231c0000000920a6,0x231a24c0002835e4,0x041a24c0002825e4,0x032014c00007f0a4\n"
".quad 0x0348000000085164,0x234800c00004c09c,0xe71b0e4000b023dc,0x0340000002600085\n"
".quad 0xe448004000a040a4,0x03280040008000e5,0x432007c0001020a4,0x854800400093f0e4\n"
".quad 0x04840000000020a4,0x041c800000082124,0x031c0000000820e4,0x0448000000504125\n"
".quad 0x031d0000000820a4,0xc4480000000030e5,0xc41c000000112126,0x031c0000000d20e6\n"
".quad 0x23480000005420a5,0xc41a0ec0002845e4,0x231c0000000920a6,0x231a24c0002835e4\n"
".quad 0x041a24c0002825e4,0x032014c00007f0a4,0x2348000000085164,0xf4190e0000fc53dc\n"
".quad 0x0440000000000005,0x261800000021321e,0x8614000001d3f09c,0x841400000163f11c\n"
".quad 0x861c00000008235e,0x041400000173f15c,0x861800000031309e,0x2314000000e3f29c\n"
".quad 0x86190e0000fcd3dc,0x0114000000f3f2dc,0x862014000010821c,0x861400000103f19c\n"
".quad 0x011400000113f1dc,0xe7200c000010219c,0xe440000000e00085,0xe428004001200325\n"
".quad 0xe428004001300365,0x01280040014002a5,0x01500000001860a4,0xe450000000208124\n"
".quad 0xe7280040015002e5,0xe4400000018000a5,0xe428000000200305,0xe428000000240345\n"
".quad 0xe428000000180285,0xe4280000001c02c5,0xe428000000fc0105,0xe428000000fc0145\n"
".quad 0xe428000000fc0085,0xe428000000fc00c5,0xe428000000fc0205,0xe428000000fc0245\n"
".quad 0xe428000000fc0185,0xe428000000fc01c5,0x2328004000c0041d,0x03190ec0000503dc\n"
".quad 0xe74800fffffd059c,0x0140000002400005,0x074800000008441c,0x0168000002000000\n"
".quad 0xe7188ed0040103dc,0x01a8000000000025,0x015000000018819c,0x014800000008411d\n"
".quad 0x014800000018609c,0x034800000010c21c,0x014800fffffd659c,0x234800000008a19c\n"
".quad 0x01190e0000fd63dc,0x015000000020811c,0xe75000000018609c,0x01a8000000000005\n"
".quad 0x014800000010241c,0xe7188ed0040103dc,0xe7a8000000000025,0x034003fffe40001d\n"
".quad 0x2348004000c1609e,0x23322c0000fc209c,0xe7190e0000fc23dc,0x0340000001c00085\n"
".quad 0x0648004001a020a4,0x041400000183f0e4,0x061c0000000c20e4,0x041400000187f124\n"
".quad 0x061c000000102124,0xa3140000018bf164,0xa3500000000c20e4,0x0450000000102124\n"
".quad 0x041c000000142164,0xa31c0000000c21e4,0x04500000001420a4,0x041c000000102224\n"
".quad 0xe71c000000082264,0xe4400000008000a5,0xe428000000fc0245,0xe428000000fc0205\n"
".quad 0xe428000000fc01c5,0xe44000000000001d,0xa32800400190009d,0x032010400191441c\n"
".quad 0xa34800c00004209c,0xc42012400191551c,0xc41c00000009211e,0xc41c00000009215e\n"
".quad 0x041c0000000920de,0x041804000011229c,0x23180400001522dc,0x005800c0007c219c\n"
".quad 0x04c800000010a29c,0x00180400000d235c,0x03c800000010b31c,0x026800c00004619c\n"
".quad 0x00083ffffff8a2dc,0x03c800000010d35c,0x024800000008629c,0x04083ffffff8c31c\n"
".quad 0x02148600002d219c,0xa3083ffffff8d35c,0x23200e40019002dc,0x045800c00004a29c\n"
".quad 0x041486000031201c,0x03148600003521dc,0x035000000018431c,0x03480000002ca21c\n"
".quad 0x035000000000545c,0x844800000040a25c,0x031c00000031231f,0x84500000001c335c\n"
".quad 0xc41c00000045241f,0x431c0000002122de,0x84200c000030631c,0x031c00000035235f\n"
".quad 0x434800000050a19c,0xc42000000040041c,0x431c00000025229e,0x43500000002cc01c\n"
".quad 0xc4200e00003471dc,0x031c00000019245e,0x43201600000042de,0x435000000029031c\n"
".quad 0x03500000004471dc,0x03198e00002c45dc,0x032014000030529e,0x03202200001c335e\n"
".quad 0x034800000010b2c9,0x034800c000040008,0x03198e00002857dc,0x83198e00003433dc\n"
".quad 0x036800000008821c,0x031b0e000010b5dc,0x034800000014a28d,0x034800c00004c30c\n"
".quad 0x23480000000cd345,0x031b0e0000fc87dc,0x834800c000040008,0x036800000008925c\n"
".quad 0x031b0e000014a9dc,0x034800c0000471c4,0x831b0e00000cd3dc,0x846800000008611c\n"
".quad 0x231c00000001202f,0x031b0e0000fc95dc,0xc34800c00004c310,0x23680000000bf0dd\n"
".quad 0x031b0e0000fc47dc,0xc34800c0000471c4,0x84680000000bf15d,0x231c00000031232b\n"
".quad 0x843104000000301c,0xc31c0000001d21ef,0x23680000000bf11d,0x04310400003050dc\n"
".quad 0x231c00000001001c,0x03310400001c409c,0x052800c02020301c,0x559400000008e09c\n"
".quad 0x049400000000e01c,0x0750ee0000ffffdc,0xf460000003400000,0xe440000000000021\n"
".quad 0xe42800780000009d,0xe228000000fc00dd,0x031800000004001d,0x051a8e4001b3f5dc\n"
".quad 0x04547e200000201c,0xc318044001b1201c,0x0068004001b3f0dd,0x02c800000010001c\n"
".quad 0x04083ffffff8001c,0x031486000001201c,0x8450004001b0009c,0x431c00000009209f\n"
".quad 0x432000000008001c,0x035000000010009c,0x0320084001b0201e,0x031b0e4001b003dc\n"
".quad 0x0348004001b00005,0x034800c000042084,0x031b0e4001b003dc,0x034800c000042084\n"
".quad 0x0448004001b00005,0x042014000008309c,0x852014000000315c,0xb5c900000023f09c\n"
".quad 0x04c900000003f11c,0x8550ee0000ffffdc,0x03c100000003f01c,0xe7188e4001c003dc\n"
".quad 0xe74003ffdc600005,0x008000000000001d,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000100000000,0x00000000003c0c04,0x0000000c00000008,0x0000001800000010\n"
".quad 0x0000002800000020,0x0000003800000030,0x0000004400000040,0x0000004c00000048\n"
".quad 0x0000005400000050,0x0000001b00080a04,0x0055190300550020,0xffffffff000c1704\n"
".quad 0x0005f0000054000e,0xffffffff000c1704,0x0011f0000050000d,0xffffffff000c1704\n"
".quad 0x0011f000004c000c,0xffffffff000c1704,0x0011f0000048000b,0xffffffff000c1704\n"
".quad 0x0011f0000044000a,0xffffffff000c1704,0x0011f00000400009,0xffffffff000c1704\n"
".quad 0x0021f00000380008,0xffffffff000c1704,0x0021f00000300007,0xffffffff000c1704\n"
".quad 0x0021f00000280006,0xffffffff000c1704,0x0021f00000200005,0xffffffff000c1704\n"
".quad 0x0021f00000180004,0xffffffff000c1704,0x0011f00000100003,0xffffffff000c1704\n"
".quad 0x0011f000000c0002,0xffffffff000c1704,0x0011f00000080001,0xffffffff000c1704\n"
".quad 0x0021f00000000000,0x0022019800080d04,0x0000000000000020,0x0000000000000000\n"
".quad 0x0000002c00000001,0x0000002b00081204,0x0008110400000000,0x000000000000002b\n"
".quad 0x0000002a00081204,0x0008110400000000,0x000000000000002a,0x0000002900081204\n"
".quad 0x0008110400000080,0x0000008000000029,0x0000002800081204,0x00081104000000c0\n"
".quad 0x000000c000000028,0x0000002700081204,0x0008110400000000,0x0000000000000027\n"
".quad 0x0000002600081204,0x0008110400000000,0x0000000000000026,0x0000000500000006\n"
".quad 0x0000000000006678,0x0000000000000000,0x0000000000000000,0x0000000000000348\n"
".quad 0x0000000000000348,0x0000000000000004,0x00002b0560000000,0x000000000000170a\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000f3d,0x0000000000000f3d\n"
".quad 0x0000000000000004,0x00002b0660000000,0x0000000000002647,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x000000000000000c,0x0000000000000004\n"
".quad 0x00002a0560000000,0x0000000000002647,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000001195,0x0000000000001195,0x0000000000000004,0x00002a0660000000\n"
".quad 0x00000000000037dc,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x000000000000000c,0x0000000000000004,0x0000290560000000,0x00000000000037dc\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000b09,0x0000000000000b09\n"
".quad 0x0000000000000004,0x0000290660000000,0x00000000000042e5,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000010,0x0000000000000004\n"
".quad 0x0000280560000000,0x00000000000042e5,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000bc9,0x0000000000000bc9,0x0000000000000004,0x0000280660000000\n"
".quad 0x0000000000004eae,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000014,0x0000000000000004,0x0000270560000000,0x0000000000004eae\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000b51,0x0000000000000b51\n"
".quad 0x0000000000000004,0x0000270660000000,0x00000000000059ff,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x000000000000000c,0x0000000000000004\n"
".quad 0x0000260560000000,0x00000000000059ff,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000bd5,0x0000000000000bd5,0x0000000000000004,0x0000260660000000\n"
".quad 0x00000000000065d4,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x000000000000000c,0x0000000000000004,0x0000000500000001,0x00000000000065d4\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000014,0x0000000000000014\n"
".quad 0x0000000000000004,0x0000000600000001,0x00000000000065e8,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000004,0x0000000000000004\n"
".quad 0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[3385];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"bf1089044499387e",(char*)"/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x5e279dd6,&__elfEntries1};
# 3 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2
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
static void __sti____cudaRegisterAll_50_tmpxft_00000ed1_00000000_4_Mandelbrot_sm13_cpp1_ii_35da923b(void) __attribute__((__constructor__));
void __device_stub__Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const int __par14, const int __par15, const bool __par16){ struct __T20 *__T2124 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2124->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2124->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2124->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2124->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2124->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2124->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2124->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2124->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2124->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2124->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2124->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2124->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2124->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2124->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2124->__par14) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T2124->__par15) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T2124->__par16) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13))); };}
void MandelbrotDS0_sm13( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const int __cuda_14,const int __cuda_15,const bool __cuda_16)
# 115 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{__device_stub__Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16);
# 183 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
void __device_stub__Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const int __par14, const int __par15, const bool __par16) { struct __T21 *__T2125 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2125->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2125->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2125->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2125->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2125->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2125->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2125->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2125->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2125->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2125->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2125->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2125->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2125->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2125->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2125->__par14) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T2125->__par15) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T2125->__par16) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13))); }; }
void MandelbrotDS1_sm13( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const int __cuda_14,const int __cuda_15,const bool __cuda_16)
# 274 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
{__device_stub__Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16);
# 359 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
static void __device_stub__Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T22 *__T2141 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2141->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2141->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2141->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2141->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2141->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2141->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2141->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2141->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2141->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2141->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2141->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2141->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2141->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2141->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2141->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm13<float,16>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T23 *__T2142 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2142->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2142->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2142->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2142->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2142->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2142->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2142->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2142->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2142->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2142->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2142->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2142->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2142->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2142->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2142->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm13<double,16>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T24 *__T2157 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2157->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2157->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2157->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2157->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2157->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2157->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2157->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2157->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2157->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2157->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2157->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2157->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2157->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2157->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2157->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm13<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T25 *__T2158 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2158->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2158->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2158->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2158->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2158->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2158->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2158->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2158->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2158->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2158->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2158->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2158->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2158->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2158->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2158->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm13<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __sti____cudaRegisterAll_50_tmpxft_00000ed1_00000000_4_Mandelbrot_sm13_cpp1_ii_35da923b(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> ), (char*)"_Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> ), (char*)"_Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> ), (char*)"_Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> ), (char*)"_Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13), (char*)"_Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib", "_Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13), (char*)"_Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib", "_Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&blockCounter, (char*)"blockCounter", "blockCounter", 0, 4, 0, 0); }
# 1 "/tmp/tmpxft_00000ed1_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2

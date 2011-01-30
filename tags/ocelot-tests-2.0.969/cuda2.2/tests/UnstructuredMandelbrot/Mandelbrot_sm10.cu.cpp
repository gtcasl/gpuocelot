# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
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
# 7 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
template< class T> static void
# 8 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
__wrapper__device_stub_Mandelbrot0_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 9 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
# 10 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
animationFrame, const bool &isJ) ;
# 7 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
template< class T> void
# 8 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
Mandelbrot0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
# 9 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
# 10 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
animationFrame, const bool isJ)
# 11 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{__wrapper__device_stub_Mandelbrot0_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,isJ);
# 50 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 53 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
void MandelbrotDS0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float
# 54 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
yOff0, const float yOff1, const float xJP, const float yJP, const float scale, const uchar4
# 55 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
colors, const int frame, const int animationFrame, const bool isJ) ;
# 102 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
template< class T> static void
# 103 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
__wrapper__device_stub_Mandelbrot1_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 104 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
# 105 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
animationFrame, const bool &isJ) ;
# 102 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
template< class T> void
# 103 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
Mandelbrot1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
# 104 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
# 105 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
animationFrame, const bool isJ)
# 106 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{__wrapper__device_stub_Mandelbrot1_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,isJ);
# 155 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 158 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
void MandelbrotDS1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float
# 159 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xOff0, const float xOff1, const float yOff0, const float yOff1, const float
# 160 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xJP, const float yJP, const float scale, const uchar4 colors, const int
# 161 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
frame, const int animationFrame, const bool isJ) ;
# 218 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
void RunMandelbrot0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const float
# 219 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xjp, const float yjp, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int
# 220 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
mode, const bool isJ)
# 221 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{
# 222 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dim3 threads(16, 16);
# 223 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));
# 225 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
switch (mode) {
# 226 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
default:
# 227 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 0:
# 228 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);
# 230 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 231 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 1:
# 232 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
float x0, x1, y0, y1;
# 233 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dsdeq(x0, x1, xOff);
# 234 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dsdeq(y0, y1, yOff);
# 235 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS0_sm10(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);
# 237 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 238 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 2:
# 239 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10< double> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, isJ);
# 241 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 242 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 244 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 247 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
void RunMandelbrot1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const float
# 248 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
xjp, const float yjp, const double scale, const uchar4 colors, const int
# 249 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
frame, const int animationFrame, const int mode, const bool isJ)
# 250 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{
# 251 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dim3 threads(16, 16);
# 252 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));
# 254 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
switch (mode) {
# 255 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
default:
# 256 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 0:
# 257 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);
# 259 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 260 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 1:
# 261 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
float x0, x1, y0, y1;
# 262 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dsdeq(x0, x1, xOff);
# 263 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
dsdeq(y0, y1, yOff);
# 264 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS1_sm10(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);
# 266 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 267 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
case 2:
# 268 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10< double> )(dst, imageW, imageH, crunch, xOff, yOff, yjp, yjp, scale, colors, frame, animationFrame, isJ);
# 270 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
break;
# 271 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 273 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
__cutilCheckMsg("Mandelbrot1_sm10 kernel execution failed.\n", "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu", 273);
# 274 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000e9d_00000000-3_Mandelbrot_sm10.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000e9d_00000000-3_Mandelbrot_sm10.fatbin.c" 2

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
".quad 0x6d617261702e2820,0x5f5f203233732e20,0x6674657261647563,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5469456649746f72,0x535f30535f30535f,0x5a5f202962695f30\n"
".quad 0x614d636c61433431,0x746f72626c65646e,0x30535f5469456649,0x695f30535f30535f\n"
".quad 0x617261702e282062,0x5f203233662e206d,0x726170616475635f,0x34315a5f5f31666d\n"
".quad 0x646e614d636c6143,0x6649746f72626c65,0x535f30535f546945,0x2c62695f30535f30\n"
".quad 0x206d617261702e20,0x635f5f203233662e,0x666d726170616475,0x614334315a5f5f32\n"
".quad 0x6c65646e614d636c,0x69456649746f7262,0x5f30535f30535f54,0x2e202c62695f3053\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5f33666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053,0x61702e202c62695f\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261,0x614d636c61433431\n"
".quad 0x746f72626c65646e,0x30535f5469456649,0x695f30535f30535f,0x617261702e202c62\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x34315a5f5f35666d,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x535f30535f546945,0x2c62695f30535f30,0x206d617261702e20\n"
".quad 0x635f5f203233732e,0x666d726170616475,0x614334315a5f5f36,0x6c65646e614d636c\n"
".quad 0x69456649746f7262,0x5f30535f30535f54,0x0a0a2962695f3053,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e,0x5f66746572616475\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x5f5469456449746f,0x30535f30535f3053\n"
".quad 0x315a5f202962695f,0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564\n"
".quad 0x62695f30535f3053,0x6d617261702e2820,0x5f5f203436662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3166,0x65646e614d636c61,0x456449746f72626c,0x30535f30535f5469\n"
".quad 0x202c62695f30535f,0x2e206d617261702e,0x75635f5f20343666,0x32666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456449746f72,0x535f30535f30535f\n"
".quad 0x702e202c62695f30,0x36662e206d617261,0x616475635f5f2034,0x5f5f33666d726170\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30\n"
".quad 0x7261702e202c6269,0x203436662e206d61,0x6170616475635f5f,0x315a5f5f34666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564,0x62695f30535f3053\n"
".quad 0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563,0x4334315a5f5f3566\n"
".quad 0x65646e614d636c61,0x456449746f72626c,0x30535f30535f5469,0x202c62695f30535f\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x36666d7261706164,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5469456449746f72,0x535f30535f30535f,0x090a0a2962695f30\n"
".quad 0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d\n"
".quad 0x6c69706d6f43202f,0x706d742f20676e69,0x5f746678706d742f,0x6439653030303030\n"
".quad 0x303030303030305f,0x646e614d5f372d30,0x735f746f72626c65,0x337070632e30316d\n"
".quad 0x706d742f2820692e,0x4e2e23494263632f,0x090a29635454494b,0x2d2d2d2d2d2d2f2f\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x090a0a2d2d2d2d2d,0x2d2d2d2d2d2d2f2f\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d,0x6e6f6974704f202f\n"
".quad 0x2d2d2f2f090a3a73,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x5420202f2f090a2d,0x74703a7465677261,0x733a415349202c78,0x6e45202c30325f6d\n"
".quad 0x74696c3a6e616964,0x696f50202c656c74,0x7a6953207265746e,0x2f2f090a34363a65\n"
".quad 0x4f2809334f2d2020,0x74617a696d697470,0x6576656c206e6f69,0x20202f2f090a296c\n"
".quad 0x626544280930672d,0x6c6576656c206775,0x2d20202f2f090a29,0x6f7065522809326d\n"
".quad 0x7369766461207472,0x090a29736569726f,0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x090a0a2d2d2d2d2d,0x093109656c69662e,0x6e616d6d6f633c22\n"
".quad 0x223e656e696c2d64,0x09656c69662e090a,0x2f706d742f220932,0x305f746678706d74\n"
".quad 0x5f64396530303030,0x3030303030303030,0x65646e614d5f362d,0x6d735f746f72626c\n"
".quad 0x66616475632e3031,0x0a227570672e3265,0x3309656c69662e09,0x6c2f7273752f2209\n"
".quad 0x692f6363672f6269,0x756e696c2d363836,0x2e342f756e672d78,0x6c636e692f352e34\n"
".quad 0x646474732f656475,0x2e090a22682e6665,0x22093409656c6966,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x632f6564756c636e,0x63697665642f7472\n"
".quad 0x6d69746e75725f65,0x662e090a22682e65,0x2f22093509656c69,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x6f682f6564756c63,0x6e696665645f7473\n"
".quad 0x2e090a22682e7365,0x22093609656c6966,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x622f6564756c636e,0x745f6e69746c6975,0x0a22682e73657079\n"
".quad 0x3709656c69662e09,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x5f6563697665642f,0x22682e7365707974,0x09656c69662e090a\n"
".quad 0x2f7273752f220938,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x7265766972642f65,0x682e73657079745f,0x656c69662e090a22,0x7273752f22093909\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x61667275732f6564\n"
".quad 0x73657079745f6563,0x69662e090a22682e,0x2f2209303109656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x65742f6564756c63,0x79745f6572757478\n"
".quad 0x090a22682e736570,0x313109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f726f746365762f,0x22682e7365707974\n"
".quad 0x09656c69662e090a,0x7273752f22093231,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x63697665642f6564,0x68636e75616c5f65,0x74656d617261705f\n"
".quad 0x090a22682e737265,0x333109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x6f74732f7472632f,0x616c635f65676172\n"
".quad 0x2e090a22682e7373,0x09343109656c6966,0x6e692f7273752f22,0x69622f6564756c63\n"
".quad 0x73657079742f7374,0x69662e090a22682e,0x2f2209353109656c,0x6c636e692f727375\n"
".quad 0x656d69742f656475,0x69662e090a22682e,0x2f2209363109656c,0x726f6e2f656d6f68\n"
".quad 0x636568632f6c616d,0x7570672f74756f6b,0x742f746f6c65636f,0x7874702d73747365\n"
".quad 0x6475632f312e322d,0x7365742f322e3261,0x7274736e552f7374,0x4d64657275746375\n"
".quad 0x6f72626c65646e61,0x6c65646e614d2f74,0x72656b5f746f7262,0x0a2275632e6c656e\n"
".quad 0x3109656c69662e09,0x656d6f682f220937,0x2f6c616d726f6e2f,0x74756f6b63656863\n"
".quad 0x6c65636f7570672f,0x73747365742f746f,0x312e322d7874702d,0x322e32616475632f\n"
".quad 0x552f73747365742f,0x757463757274736e,0x65646e614d646572,0x614d2f746f72626c\n"
".quad 0x746f72626c65646e,0x75632e30316d735f,0x656c69662e090a22,0x73752f2209383109\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x6d6d6f632f656475\n"
".quad 0x74636e75665f6e6f,0x0a22682e736e6f69,0x3109656c69662e09,0x2f7273752f220939\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x665f6874616d2f65\n"
".quad 0x736e6f6974636e75,0x69662e090a22682e,0x2f2209303209656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x616d2f6564756c63,0x74736e6f635f6874\n"
".quad 0x0a22682e73746e61,0x3209656c69662e09,0x2f7273752f220931,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09323209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x74615f31315f6d73,0x6e75665f63696d6f\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209333209,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x315f6d732f656475,0x63696d6f74615f32\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09343209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6f645f33315f6d73\n"
".quad 0x6e75665f656c6275,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209353209\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x325f6d732f656475\n"
".quad 0x63696d6f74615f30,0x6f6974636e75665f,0x2e090a22682e736e,0x09363209656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x6e695f30325f6d73,0x736369736e697274,0x69662e090a22682e,0x2f2209373209656c\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x75732f6564756c63\n"
".quad 0x75665f6563616672,0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220938320965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x7865742f6564756c\n"
".quad 0x7465665f65727574,0x74636e75665f6863,0x0a22682e736e6f69,0x3209656c69662e09\n"
".quad 0x2f7273752f220939,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x665f6874616d2f65,0x736e6f6974636e75,0x7874705f6c62645f,0x090a0a0a22682e33\n"
".quad 0x656c62697369762e,0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x5f5f667465726164,0x4d636c614336315a,0x6f72626c65646e61,0x6666666666534474\n"
".quad 0x315a5f2029626966,0x6e614d636c614336,0x44746f72626c6564,0x6966666666666653\n"
".quad 0x617261702e282062,0x5f203233662e206d,0x726170616475635f,0x36315a5f5f31666d\n"
".quad 0x646e614d636c6143,0x5344746f72626c65,0x6269666666666666,0x6d617261702e202c\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x4336315a5f5f3266,0x65646e614d636c61\n"
".quad 0x665344746f72626c,0x2c62696666666666,0x206d617261702e20,0x635f5f203233662e\n"
".quad 0x666d726170616475,0x614336315a5f5f33,0x6c65646e614d636c,0x66665344746f7262\n"
".quad 0x202c626966666666,0x2e206d617261702e,0x75635f5f20323366,0x34666d7261706164\n"
".quad 0x6c614336315a5f5f,0x626c65646e614d63,0x6666665344746f72,0x2e202c6269666666\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5f35666d72617061,0x636c614336315a5f\n"
".quad 0x72626c65646e614d,0x666666665344746f,0x702e202c62696666,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f36666d726170,0x4d636c614336315a,0x6f72626c65646e61\n"
".quad 0x6666666666534474,0x61702e202c626966,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f37666d7261,0x614d636c61433631,0x746f72626c65646e,0x6666666666665344\n"
".quad 0x7261702e202c6269,0x203233732e206d61,0x6170616475635f5f,0x315a5f5f38666d72\n"
".quad 0x6e614d636c614336,0x44746f72626c6564,0x6966666666666653,0x2e090a7b090a2962\n"
".quad 0x3233752e20676572,0x3b3e31313c722520,0x2e206765722e090a,0x323c662520323366\n"
".quad 0x722e090a3b3e3131,0x646572702e206765,0x0a3b3e373c702520,0x363109636f6c2e09\n"
".quad 0x240a300933343209,0x6e6967656257444c,0x6c614336315a5f5f,0x626c65646e614d63\n"
".quad 0x6666665344746f72,0x090a3a6269666666,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c31,0x31666d7261706164,0x6c614336315a5f5f,0x626c65646e614d63\n"
".quad 0x6666665344746f72,0x0a3b5d6269666666,0x3233662e766f6d09,0x25202c3266250920\n"
".quad 0x2e646c090a3b3166,0x33662e6d61726170,0x202c336625092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f32666d7261,0x614d636c61433631,0x746f72626c65646e,0x6666666666665344\n"
".quad 0x6f6d090a3b5d6269,0x2509203233662e76,0x3b336625202c3466,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5f5b202c356625,0x6d72617061647563,0x4336315a5f5f3366\n"
".quad 0x65646e614d636c61,0x665344746f72626c,0x5d62696666666666,0x662e766f6d090a3b\n"
".quad 0x2c36662509203233,0x6c090a3b35662520,0x2e6d617261702e64,0x3766250920323366\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x636c614336315a5f,0x72626c65646e614d\n"
".quad 0x666666665344746f,0x090a3b5d62696666,0x203233662e766f6d,0x6625202c38662509\n"
".quad 0x702e646c090a3b37,0x3233662e6d617261,0x5b202c3966250920,0x6170616475635f5f\n"
".quad 0x315a5f5f35666d72,0x6e614d636c614336,0x44746f72626c6564,0x6966666666666653\n"
".quad 0x766f6d090a3b5d62,0x662509203233662e,0x3b396625202c3031,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5b202c31316625,0x726170616475635f,0x36315a5f5f36666d\n"
".quad 0x646e614d636c6143,0x5344746f72626c65,0x6269666666666666,0x2e766f6d090a3b5d\n"
".quad 0x3166250920323366,0x3b31316625202c32,0x7261702e646c090a,0x09203233752e6d61\n"
".quad 0x5f5f5b202c317225,0x6d72617061647563,0x4336315a5f5f3766,0x65646e614d636c61\n"
".quad 0x665344746f72626c,0x5d62696666666666,0x732e766f6d090a3b,0x2c32722509203233\n"
".quad 0x6c090a3b31722520,0x2e6d617261702e64,0x3372250920323375,0x6475635f5f5b202c\n"
".quad 0x5f38666d72617061,0x636c614336315a5f,0x72626c65646e614d,0x666666665344746f\n"
".quad 0x090a3b5d62696666,0x732e38732e747663,0x2c34722509203233,0x6d090a3b33722520\n"
".quad 0x09203233752e766f,0x0a3b30202c357225,0x71652e7074657309,0x702509203233732e\n"
".quad 0x202c347225202c31,0x2540090a3b357225,0x0920617262203170,0x38335f305f744c24\n"
".quad 0x6f6c2e090a3b3234,0x3335320936310963,0x2e766f6d090a3009,0x3166250920323366\n"
".quad 0x3b30316625202c33,0x3109636f6c2e090a,0x0a30093535320936,0x3233662e766f6d09\n"
".quad 0x202c343166250920,0x2e090a3b32316625,0x3209363109636f6c,0x6f6d090a30093735\n"
".quad 0x2509203233662e76,0x366625202c353166,0x09636f6c2e090a3b,0x3009383532093631\n"
".quad 0x33662e766f6d090a,0x2c36316625092032,0x2e090a3b38662520,0x3209363109636f6c\n"
".quad 0x6f6d090a30093935,0x2509203233662e76,0x326625202c373166,0x09636f6c2e090a3b\n"
".quad 0x3009303632093631,0x33662e766f6d090a,0x2c38316625092032,0x2e090a3b34662520\n"
".quad 0x3209363109636f6c,0x756d090a30093136,0x2509203233662e6c,0x366625202c393166\n"
".quad 0x090a3b386625202c,0x203233662e6c756d,0x25202c3032662509,0x3b366625202c3666\n"
".quad 0x33662e766f6d090a,0x2c31326625092032,0x3030303634663020,0x202020203b303034\n"
".quad 0x33393138202f2f09,0x33662e6c756d090a,0x2c32326625092032,0x6625202c36662520\n"
".quad 0x616d66090a3b3132,0x203233662e6e722e,0x25202c3332662509,0x2c386625202c3666\n"
".quad 0x090a3b3931662520,0x203233662e627573,0x25202c3432662509,0x366625202c323266\n"
".quad 0x662e646461090a3b,0x3532662509203233,0x202c30326625202c,0x73090a3b33326625\n"
".quad 0x09203233662e6275,0x6625202c36326625,0x34326625202c3232,0x662e627573090a3b\n"
".quad 0x3732662509203233,0x202c35326625202c,0x6d090a3b30326625,0x09203233662e6c75\n"
".quad 0x6625202c38326625,0x36326625202c3632,0x662e627573090a3b,0x3932662509203233\n"
".quad 0x202c38326625202c,0x73090a3b30326625,0x09203233662e6275,0x6625202c30336625\n"
".quad 0x3b36326625202c36,0x33662e627573090a,0x2c31336625092032,0x25202c3332662520\n"
".quad 0x7573090a3b373266,0x2509203233662e62,0x326625202c323366,0x3b37326625202c35\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x36326625202c3333,0x202c30336625202c\n"
".quad 0x73090a3b39326625,0x09203233662e6275,0x6625202c34336625,0x32336625202c3032\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x326625202c353366,0x2c30336625202c36\n"
".quad 0x090a3b3333662520,0x203233662e646461,0x25202c3633662509,0x336625202c313366\n"
".quad 0x2e616d66090a3b34,0x09203233662e6e72,0x6625202c37336625,0x30336625202c3033\n"
".quad 0x0a3b35336625202c,0x3233662e64646109,0x202c383366250920,0x6625202c36336625\n"
".quad 0x616d66090a3b3733,0x203233662e6e722e,0x25202c3933662509,0x2c386625202c3866\n"
".quad 0x090a3b3833662520,0x203233662e646461,0x25202c3034662509,0x336625202c353266\n"
".quad 0x2e766f6d090a3b39,0x3466250920323366,0x3b30346625202c31,0x33662e627573090a\n"
".quad 0x2c32346625092032,0x25202c3034662520,0x7573090a3b353266,0x2509203233662e62\n"
".quad 0x336625202c333466,0x3b32346625202c39,0x3109636f6c2e090a,0x0a30093236320936\n"
".quad 0x3233662e6c756d09,0x202c343466250920,0x346625202c326625,0x662e6c756d090a3b\n"
".quad 0x3534662509203233,0x25202c326625202c,0x766f6d090a3b3266,0x662509203233662e\n"
".quad 0x36346630202c3634,0x203b303034303030,0x38202f2f09202020,0x6c756d090a333931\n"
".quad 0x662509203233662e,0x2c326625202c3734,0x090a3b3634662520,0x662e6e722e616d66\n"
".quad 0x3834662509203233,0x25202c326625202c,0x34346625202c3466,0x662e627573090a3b\n"
".quad 0x3934662509203233,0x202c37346625202c,0x6461090a3b326625,0x2509203233662e64\n"
".quad 0x346625202c303566,0x3b38346625202c35,0x33662e627573090a,0x2c31356625092032\n"
".quad 0x25202c3734662520,0x7573090a3b393466,0x2509203233662e62,0x356625202c323566\n"
".quad 0x3b35346625202c30,0x33662e6c756d090a,0x2c33356625092032,0x25202c3135662520\n"
".quad 0x7573090a3b313566,0x2509203233662e62,0x356625202c343566,0x3b35346625202c33\n"
".quad 0x33662e627573090a,0x2c35356625092032,0x6625202c32662520,0x627573090a3b3135\n"
".quad 0x662509203233662e,0x38346625202c3635,0x0a3b32356625202c,0x3233662e62757309\n"
".quad 0x202c373566250920,0x6625202c30356625,0x616d66090a3b3235,0x203233662e6e722e\n"
".quad 0x25202c3835662509,0x356625202c313566,0x3b34356625202c35,0x33662e627573090a\n"
".quad 0x2c39356625092032,0x25202c3534662520,0x6d66090a3b373566,0x3233662e6e722e61\n"
".quad 0x202c303666250920,0x6625202c31356625,0x38356625202c3535,0x662e646461090a3b\n"
".quad 0x3136662509203233,0x202c36356625202c,0x66090a3b39356625,0x33662e6e722e616d\n"
".quad 0x2c32366625092032,0x25202c3535662520,0x366625202c353566,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x2c31366625202c33,0x090a3b3236662520,0x662e6e722e616d66\n"
".quad 0x3436662509203233,0x25202c346625202c,0x33366625202c3466,0x662e646461090a3b\n"
".quad 0x3536662509203233,0x202c30356625202c,0x6d090a3b34366625,0x09203233662e766f\n"
".quad 0x6625202c36366625,0x627573090a3b3536,0x662509203233662e,0x35366625202c3736\n"
".quad 0x0a3b30356625202c,0x3233662e62757309,0x202c383666250920,0x6625202c34366625\n"
".quad 0x766f6d090a3b3736,0x662509203233662e,0x30306630202c3936,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c30376625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x62090a30202f2f09,0x0920696e752e6172,0x35335f305f744c24\n"
".quad 0x5f744c240a3b3638,0x0a3a323438335f30,0x363109636f6c2e09,0x090a300935363209\n"
".quad 0x203233662e766f6d,0x25202c3331662509,0x6f6c2e090a3b3266,0x3636320936310963\n"
".quad 0x2e766f6d090a3009,0x3766250920323366,0x0a3b346625202c30,0x363109636f6c2e09\n"
".quad 0x090a300937363209,0x203233662e766f6d,0x25202c3431662509,0x6f6c2e090a3b3666\n"
".quad 0x3836320936310963,0x2e766f6d090a3009,0x3666250920323366,0x0a3b386625202c39\n"
".quad 0x363109636f6c2e09,0x090a300936373209,0x203233662e766f6d,0x30202c3836662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x30306630202c3636,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c33346625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c31346625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c38,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c373166250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c363166\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3531662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x240a30202f2f0920,0x3835335f305f744c\n"
".quad 0x636f6c2e090a3a36,0x0930383209363109,0x732e627573090a30,0x2c36722509203233\n"
".quad 0x3b31202c32722520,0x33752e766f6d090a,0x202c377225092032,0x70746573090a3b31\n"
".quad 0x203233732e71652e,0x7225202c32702509,0x0a3b377225202c32,0x7262203270254009\n"
".quad 0x305f744c24092061,0x090a3b383930345f,0x203233662e646461,0x25202c3137662509\n"
".quad 0x346625202c363666,0x2e627573090a3b31,0x3766250920323366,0x2c31376625202c32\n"
".quad 0x090a3b3636662520,0x203233662e627573,0x25202c3337662509,0x376625202c313766\n"
".quad 0x2e627573090a3b32,0x3766250920323366,0x2c31346625202c34,0x090a3b3237662520\n"
".quad 0x203233662e627573,0x25202c3537662509,0x376625202c363666,0x2e646461090a3b33\n"
".quad 0x3766250920323366,0x2c34376625202c36,0x090a3b3537662520,0x203233662e646461\n"
".quad 0x25202c3737662509,0x366625202c363766,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x2c37376625202c38,0x090a3b3334662520,0x203233662e646461,0x25202c3937662509\n"
".quad 0x376625202c313766,0x2e627573090a3b38,0x3866250920323366,0x2c39376625202c30\n"
".quad 0x090a3b3137662520,0x203233662e627573,0x25202c3138662509,0x386625202c383766\n"
".quad 0x2e646461090a3b30,0x3866250920323366,0x2c39376625202c32,0x090a3b3138662520\n"
".quad 0x203233662e766f6d,0x30202c3338662509,0x3030303038303466,0x2f09202020203b30\n"
".quad 0x746573090a34202f,0x3233662e746c2e70,0x25202c3370250920,0x386625202c323866\n"
".quad 0x70252140090a3b33,0x2409206172622033,0x3930345f305f744c,0x2e766f6d090a3b38\n"
".quad 0x3866250920323366,0x3036346630202c34,0x20203b3030343030,0x3138202f2f092020\n"
".quad 0x2e6c756d090a3339,0x3866250920323366,0x2c37316625202c35,0x090a3b3438662520\n"
".quad 0x203233662e766f6d,0x30202c3638662509,0x3034303030363466,0x2f09202020203b30\n"
".quad 0x090a33393138202f,0x203233662e6c756d,0x25202c3738662509,0x386625202c353166\n"
".quad 0x2e627573090a3b36,0x3866250920323366,0x2c35386625202c38,0x090a3b3731662520\n"
".quad 0x203233662e627573,0x25202c3938662509,0x316625202c373866,0x2e627573090a3b35\n"
".quad 0x3966250920323366,0x2c35386625202c30,0x090a3b3838662520,0x203233662e627573\n"
".quad 0x25202c3139662509,0x386625202c373866,0x2e627573090a3b39,0x3966250920323366\n"
".quad 0x2c37316625202c32,0x090a3b3039662520,0x203233662e627573,0x25202c3339662509\n"
".quad 0x396625202c353166,0x5f305f4c240a3b31,0x2f200a3a32363532,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3220656e696c2079,0x636f6c2e090a3138,0x0931383209363109\n"
".quad 0x662e6c756d090a30,0x3439662509203233,0x202c38316625202c,0x6d090a3b35316625\n"
".quad 0x09203233662e6c75,0x6625202c35396625,0x35316625202c3731,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x316625202c363966,0x2c36316625202c37,0x090a3b3439662520\n"
".quad 0x203233662e646461,0x25202c3739662509,0x396625202c353966,0x2e627573090a3b36\n"
".quad 0x3966250920323366,0x2c37396625202c38,0x090a3b3539662520,0x203233662e6c756d\n"
".quad 0x25202c3939662509,0x396625202c303966,0x2e627573090a3b31,0x3166250920323366\n"
".quad 0x39396625202c3030,0x0a3b35396625202c,0x3233662e62757309,0x2c31303166250920\n"
".quad 0x25202c3639662520,0x7573090a3b383966,0x2509203233662e62,0x6625202c32303166\n"
".quad 0x38396625202c3739,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c33303166\n"
".quad 0x33396625202c3039,0x3b3030316625202c,0x33662e627573090a,0x3430316625092032\n"
".quad 0x202c35396625202c,0x090a3b3230316625,0x662e6e722e616d66,0x3031662509203233\n"
".quad 0x2c31396625202c35,0x25202c3239662520,0x61090a3b33303166,0x09203233662e6464\n"
".quad 0x25202c3630316625,0x6625202c31303166,0x6d66090a3b343031,0x3233662e6e722e61\n"
".quad 0x2c37303166250920,0x25202c3239662520,0x316625202c333966,0x646461090a3b3530\n"
".quad 0x662509203233662e,0x316625202c383031,0x30316625202c3630,0x2e616d66090a3b37\n"
".quad 0x09203233662e6e72,0x25202c3930316625,0x316625202c383166,0x3830316625202c36\n"
".quad 0x662e646461090a3b,0x3131662509203233,0x2c37396625202c30,0x0a3b393031662520\n"
".quad 0x3233662e62757309,0x2c31313166250920,0x202c303131662520,0x73090a3b37396625\n"
".quad 0x09203233662e6275,0x25202c3231316625,0x6625202c39303166,0x6c2e090a3b313131\n"
".quad 0x383209363109636f,0x646461090a300932,0x662509203233662e,0x316625202c333131\n"
".quad 0x31316625202c3031,0x2e627573090a3b30,0x3166250920323366,0x31316625202c3431\n"
".quad 0x3031316625202c33,0x662e627573090a3b,0x3131662509203233,0x3031316625202c35\n"
".quad 0x3b3431316625202c,0x33662e627573090a,0x3631316625092032,0x2c3331316625202c\n"
".quad 0x0a3b343131662520,0x3233662e62757309,0x2c37313166250920,0x202c303131662520\n"
".quad 0x090a3b3631316625,0x203233662e646461,0x202c383131662509,0x25202c3531316625\n"
".quad 0x61090a3b37313166,0x09203233662e6464,0x25202c3931316625,0x6625202c38313166\n"
".quad 0x6461090a3b323131,0x2509203233662e64,0x6625202c30323166,0x316625202c393131\n"
".quad 0x646461090a3b3231,0x662509203233662e,0x316625202c313231,0x32316625202c3331\n"
".quad 0x2e627573090a3b30,0x3166250920323366,0x32316625202c3232,0x3331316625202c31\n"
".quad 0x662e627573090a3b,0x3231662509203233,0x3032316625202c33,0x3b3232316625202c\n"
".quad 0x3109636f6c2e090a,0x0a30093338320936,0x3233662e64646109,0x2c34323166250920\n"
".quad 0x202c313231662520,0x73090a3b34316625,0x09203233662e6275,0x25202c3532316625\n"
".quad 0x6625202c34323166,0x7573090a3b313231,0x2509203233662e62,0x6625202c36323166\n"
".quad 0x316625202c343231,0x627573090a3b3532,0x662509203233662e,0x316625202c373231\n"
".quad 0x3532316625202c34,0x662e627573090a3b,0x3231662509203233,0x3132316625202c38\n"
".quad 0x3b3632316625202c,0x33662e646461090a,0x3932316625092032,0x2c3732316625202c\n"
".quad 0x0a3b383231662520,0x3233662e64646109,0x2c30333166250920,0x202c393231662520\n"
".quad 0x090a3b3332316625,0x203233662e646461,0x202c313331662509,0x25202c3033316625\n"
".quad 0x6461090a3b393666,0x2509203233662e64,0x6625202c32333166,0x316625202c343231\n"
".quad 0x766f6d090a3b3133,0x662509203233662e,0x33316625202c3531,0x2e627573090a3b32\n"
".quad 0x3166250920323366,0x33316625202c3333,0x3432316625202c32,0x662e627573090a3b\n"
".quad 0x3631662509203233,0x2c3133316625202c,0x0a3b333331662520,0x363109636f6c2e09\n"
".quad 0x090a300936383209,0x203233662e627573,0x202c343331662509,0x6625202c36366625\n"
".quad 0x627573090a3b3134,0x662509203233662e,0x316625202c353331,0x36366625202c3433\n"
".quad 0x662e627573090a3b,0x3331662509203233,0x3433316625202c36,0x3b3533316625202c\n"
".quad 0x33662e646461090a,0x3733316625092032,0x2c3533316625202c,0x090a3b3134662520\n"
".quad 0x203233662e627573,0x202c383331662509,0x6625202c36366625,0x7573090a3b363331\n"
".quad 0x2509203233662e62,0x6625202c39333166,0x316625202c383331,0x646461090a3b3733\n"
".quad 0x662509203233662e,0x316625202c303431,0x38366625202c3933,0x662e627573090a3b\n"
".quad 0x3431662509203233,0x3034316625202c31,0x0a3b33346625202c,0x3233662e64646109\n"
".quad 0x2c32343166250920,0x202c343331662520,0x090a3b3134316625,0x203233662e646461\n"
".quad 0x202c333431662509,0x25202c3234316625,0x7573090a3b333166,0x2509203233662e62\n"
".quad 0x6625202c34343166,0x316625202c333431,0x627573090a3b3234,0x662509203233662e\n"
".quad 0x316625202c353431,0x34316625202c3334,0x2e627573090a3b34,0x3166250920323366\n"
".quad 0x34316625202c3634,0x3534316625202c32,0x662e627573090a3b,0x3431662509203233\n"
".quad 0x2c33316625202c37,0x0a3b343431662520,0x3233662e64646109,0x2c38343166250920\n"
".quad 0x202c363431662520,0x090a3b3734316625,0x203233662e627573,0x202c393431662509\n"
".quad 0x25202c3234316625,0x73090a3b34333166,0x09203233662e6275,0x25202c3035316625\n"
".quad 0x6625202c31343166,0x6461090a3b393431,0x2509203233662e64,0x6625202c31353166\n"
".quad 0x316625202c383431,0x646461090a3b3035,0x662509203233662e,0x376625202c323531\n"
".quad 0x3135316625202c30,0x662e646461090a3b,0x3531662509203233,0x3334316625202c33\n"
".quad 0x3b3235316625202c,0x33662e766f6d090a,0x2c37316625092032,0x0a3b333531662520\n"
".quad 0x3233662e62757309,0x2c34353166250920,0x202c333531662520,0x090a3b3334316625\n"
".quad 0x203233662e627573,0x25202c3831662509,0x6625202c32353166,0x6c2e090a3b343531\n"
".quad 0x383209363109636f,0x766f6d090a300938,0x662509203233662e,0x346630202c353531\n"
".quad 0x3b30303430303036,0x38202f2f09202020,0x6c756d090a333931,0x662509203233662e\n"
".quad 0x316625202c363531,0x35316625202c3233,0x2e6c756d090a3b35,0x3166250920323366\n"
".quad 0x33316625202c3735,0x3b36316625202c32,0x33662e6c756d090a,0x3835316625092032\n"
".quad 0x2c3233316625202c,0x0a3b323331662520,0x3233662e62757309,0x2c39353166250920\n"
".quad 0x202c363531662520,0x090a3b3233316625,0x662e6e722e616d66,0x3631662509203233\n"
".quad 0x3233316625202c30,0x202c36316625202c,0x090a3b3735316625,0x203233662e627573\n"
".quad 0x25202c3139662509,0x6625202c36353166,0x6461090a3b393531,0x2509203233662e64\n"
".quad 0x6625202c31363166,0x316625202c383531,0x627573090a3b3036,0x662509203233662e\n"
".quad 0x33316625202c3339,0x3b31396625202c32,0x33662e6c756d090a,0x3236316625092032\n"
".quad 0x202c31396625202c,0x73090a3b31396625,0x09203233662e6275,0x25202c3336316625\n"
".quad 0x6625202c32363166,0x7573090a3b383531,0x2509203233662e62,0x6625202c34363166\n"
".quad 0x316625202c313631,0x616d66090a3b3835,0x203233662e6e722e,0x202c353631662509\n"
".quad 0x6625202c31396625,0x36316625202c3339,0x2e627573090a3b33,0x3166250920323366\n"
".quad 0x36316625202c3636,0x3436316625202c30,0x662e627573090a3b,0x3631662509203233\n"
".quad 0x3136316625202c37,0x3b3436316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x396625202c383631,0x2c33396625202c31,0x0a3b353631662520,0x3233662e62757309\n"
".quad 0x2c39363166250920,0x202c383531662520,0x090a3b3736316625,0x662e6e722e616d66\n"
".quad 0x3731662509203233,0x2c33396625202c30,0x25202c3339662520,0x61090a3b38363166\n"
".quad 0x09203233662e6464,0x25202c3137316625,0x6625202c36363166,0x6461090a3b393631\n"
".quad 0x2509203233662e64,0x6625202c32373166,0x316625202c303731,0x616d66090a3b3137\n"
".quad 0x203233662e6e722e,0x202c333731662509,0x6625202c36316625,0x37316625202c3631\n"
".quad 0x2e646461090a3b32,0x3166250920323366,0x36316625202c3437,0x3337316625202c31\n"
".quad 0x662e766f6d090a3b,0x3134662509203233,0x3b3437316625202c,0x33662e627573090a\n"
".quad 0x3537316625092032,0x2c3437316625202c,0x0a3b313631662520,0x3233662e62757309\n"
".quad 0x202c333466250920,0x25202c3337316625,0x2e090a3b35373166,0x3209363109636f6c\n"
".quad 0x6f6d090a30093938,0x2509203233662e76,0x6630202c36373166,0x3030343030303634\n"
".quad 0x202f2f092020203b,0x756d090a33393138,0x2509203233662e6c,0x6625202c37373166\n"
".quad 0x316625202c333531,0x6c756d090a3b3637,0x662509203233662e,0x316625202c383731\n"
".quad 0x38316625202c3335,0x662e6c756d090a3b,0x3731662509203233,0x3335316625202c39\n"
".quad 0x3b3335316625202c,0x33662e627573090a,0x3038316625092032,0x2c3737316625202c\n"
".quad 0x0a3b333531662520,0x2e6e722e616d6609,0x3166250920323366,0x35316625202c3138\n"
".quad 0x2c38316625202c33,0x0a3b383731662520,0x3233662e62757309,0x202c303966250920\n"
".quad 0x25202c3737316625,0x61090a3b30383166,0x09203233662e6464,0x25202c3238316625\n"
".quad 0x6625202c39373166,0x7573090a3b313831,0x2509203233662e62,0x316625202c323966\n"
".quad 0x30396625202c3335,0x662e6c756d090a3b,0x3831662509203233,0x2c30396625202c33\n"
".quad 0x090a3b3039662520,0x203233662e627573,0x202c343831662509,0x25202c3338316625\n"
".quad 0x73090a3b39373166,0x09203233662e6275,0x25202c3538316625,0x6625202c32383166\n"
".quad 0x6d66090a3b393731,0x3233662e6e722e61,0x2c36383166250920,0x25202c3039662520\n"
".quad 0x316625202c323966,0x627573090a3b3438,0x662509203233662e,0x316625202c373831\n"
".quad 0x38316625202c3138,0x2e627573090a3b35,0x3166250920323366,0x38316625202c3838\n"
".quad 0x3538316625202c32,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c39383166\n"
".quad 0x32396625202c3039,0x3b3638316625202c,0x33662e627573090a,0x3039316625092032\n"
".quad 0x2c3937316625202c,0x0a3b383831662520,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x32396625202c3139,0x202c32396625202c,0x090a3b3938316625,0x203233662e646461\n"
".quad 0x202c323931662509,0x25202c3738316625,0x61090a3b30393166,0x09203233662e6464\n"
".quad 0x25202c3339316625,0x6625202c31393166,0x6d66090a3b323931,0x3233662e6e722e61\n"
".quad 0x2c34393166250920,0x25202c3831662520,0x316625202c383166,0x646461090a3b3339\n"
".quad 0x662509203233662e,0x316625202c353931,0x39316625202c3238,0x2e766f6d090a3b34\n"
".quad 0x3666250920323366,0x3539316625202c36,0x662e627573090a3b,0x3931662509203233\n"
".quad 0x3539316625202c36,0x3b3238316625202c,0x33662e627573090a,0x2c38366625092032\n"
".quad 0x202c343931662520,0x090a3b3639316625,0x09363109636f6c2e,0x61090a3009303932\n"
".quad 0x09203233662e6464,0x25202c3739316625,0x6625202c34373166,0x7573090a3b353931\n"
".quad 0x2509203233662e62,0x6625202c38393166,0x316625202c373931,0x627573090a3b3539\n"
".quad 0x662509203233662e,0x316625202c393931,0x39316625202c3437,0x2e627573090a3b38\n"
".quad 0x3266250920323366,0x39316625202c3030,0x3839316625202c37,0x662e627573090a3b\n"
".quad 0x3032662509203233,0x3539316625202c31,0x3b3030326625202c,0x33662e646461090a\n"
".quad 0x3230326625092032,0x2c3939316625202c,0x0a3b313032662520,0x3233662e64646109\n"
".quad 0x2c33303266250920,0x25202c3836662520,0x61090a3b32303266,0x09203233662e6464\n"
".quad 0x25202c3430326625,0x326625202c333466,0x646461090a3b3330,0x662509203233662e\n"
".quad 0x316625202c353032,0x30326625202c3739,0x2e627573090a3b34,0x3266250920323366\n"
".quad 0x30326625202c3630,0x3739316625202c35,0x662e627573090a3b,0x3032662509203233\n"
".quad 0x3430326625202c37,0x3b3630326625202c,0x3109636f6c2e090a,0x0a30093038320936\n"
".quad 0x3233732e62757309,0x25202c3672250920,0x090a3b31202c3672,0x203233752e766f6d\n"
".quad 0x3b30202c38722509,0x652e70746573090a,0x2509203233732e71,0x2c367225202c3470\n"
".quad 0x40090a3b38722520,0x2061726220347025,0x345f305f744c2409,0x2f2f200a3b383930\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383220656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x3635325f305f4c24,0x662e646461090a32\n"
".quad 0x3032662509203233,0x3730326625202c38,0x3b3530326625202c,0x33662e766f6d090a\n"
".quad 0x3930326625092032,0x303830346630202c,0x2020203b30303030,0x73090a34202f2f09\n"
".quad 0x662e746c2e707465,0x2c35702509203233,0x202c383032662520,0x090a3b3930326625\n"
".quad 0x6172622035702540,0x325f305f4c240920,0x744c240a3b323635,0x3a383930345f305f\n"
".quad 0x38325f305f4c240a,0x6f6c2e090a3a3831,0x3239320936310963,0x2e766f6d090a3009\n"
".quad 0x3972250920323373,0x090a3b367225202c,0x6d617261702e7473,0x5f5b09203233732e\n"
".quad 0x746572616475635f,0x614336315a5f5f66,0x6c65646e614d636c,0x66665344746f7262\n"
".quad 0x2c5d626966666666,0x72090a3b39722520,0x57444c240a3b7465,0x36315a5f5f646e65\n"
".quad 0x646e614d636c6143,0x5344746f72626c65,0x6269666666666666,0x202f2f207d090a3a\n"
".quad 0x636c614336315a5f,0x72626c65646e614d,0x666666665344746f,0x2e090a0a62696666\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6674657261,0x614d636c61433431,0x746f72626c65646e,0x30535f5469456649\n"
".quad 0x695f30535f30535f,0x4334315a5f202962,0x65646e614d636c61,0x456649746f72626c\n"
".quad 0x30535f30535f5469,0x282062695f30535f,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x31666d7261706164,0x6c614334315a5f5f,0x626c65646e614d63,0x5469456649746f72\n"
".quad 0x535f30535f30535f,0x702e202c62695f30,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f32666d726170,0x4d636c614334315a,0x6f72626c65646e61,0x535f546945664974\n"
".quad 0x5f30535f30535f30,0x7261702e202c6269,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f33666d72,0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694566\n"
".quad 0x62695f30535f3053,0x6d617261702e202c,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3466,0x65646e614d636c61,0x456649746f72626c,0x30535f30535f5469\n"
".quad 0x202c62695f30535f,0x2e206d617261702e,0x75635f5f20323373,0x35666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456649746f72,0x535f30535f30535f\n"
".quad 0x702e202c62695f30,0x33732e206d617261,0x616475635f5f2032,0x5f5f36666d726170\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945664974,0x5f30535f30535f30\n"
".quad 0x090a7b090a296269,0x33752e206765722e,0x3e31313c72252032,0x206765722e090a3b\n"
".quad 0x3c6625203233662e,0x722e090a3b3e3532,0x646572702e206765,0x0a3b3e373c702520\n"
".quad 0x363109636f6c2e09,0x240a300932303209,0x6e6967656257444c,0x6c614334315a5f5f\n"
".quad 0x626c65646e614d63,0x5469456649746f72,0x535f30535f30535f,0x6c090a3a62695f30\n"
".quad 0x2e6d617261702e64,0x3166250920323366,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053\n"
".quad 0x6d090a3b5d62695f,0x09203233662e766f,0x316625202c326625,0x61702e646c090a3b\n"
".quad 0x203233662e6d6172,0x5f5b202c33662509,0x726170616475635f,0x34315a5f5f32666d\n"
".quad 0x646e614d636c6143,0x6649746f72626c65,0x535f30535f546945,0x5d62695f30535f30\n"
".quad 0x662e766f6d090a3b,0x2c34662509203233,0x6c090a3b33662520,0x2e6d617261702e64\n"
".quad 0x3566250920323366,0x6475635f5f5b202c,0x5f33666d72617061,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456649746f,0x30535f30535f3053,0x6d090a3b5d62695f\n"
".quad 0x09203233662e766f,0x356625202c366625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c37662509,0x726170616475635f,0x34315a5f5f34666d,0x646e614d636c6143\n"
".quad 0x6649746f72626c65,0x535f30535f546945,0x5d62695f30535f30,0x662e766f6d090a3b\n"
".quad 0x2c38662509203233,0x6c090a3b37662520,0x2e6d617261702e64,0x3172250920323375\n"
".quad 0x6475635f5f5b202c,0x5f35666d72617061,0x636c614334315a5f,0x72626c65646e614d\n"
".quad 0x5f5469456649746f,0x30535f30535f3053,0x6d090a3b5d62695f,0x09203233732e766f\n"
".quad 0x317225202c327225,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c33722509\n"
".quad 0x726170616475635f,0x34315a5f5f36666d,0x646e614d636c6143,0x6649746f72626c65\n"
".quad 0x535f30535f546945,0x5d62695f30535f30,0x732e747663090a3b,0x2509203233732e38\n"
".quad 0x3b337225202c3472,0x33752e766f6d090a,0x202c357225092032,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x7225202c31702509,0x0a3b357225202c34,0x7262203170254009\n"
".quad 0x315f744c24092061,0x090a3b323438335f,0x09363109636f6c2e,0x6d090a3009353032\n"
".quad 0x09203233662e766f,0x366625202c396625,0x09636f6c2e090a3b,0x3009363032093631\n"
".quad 0x33662e766f6d090a,0x2c30316625092032,0x2e090a3b38662520,0x3209363109636f6c\n"
".quad 0x6f6d090a30093730,0x2509203233662e76,0x346625202c313166,0x09636f6c2e090a3b\n"
".quad 0x3009383032093631,0x33662e766f6d090a,0x2c32316625092032,0x2e090a3b32662520\n"
".quad 0x3209363109636f6c,0x756d090a30093930,0x2509203233662e6c,0x346625202c333166\n"
".quad 0x090a3b346625202c,0x09363109636f6c2e,0x6d090a3009303132,0x09203233662e6c75\n"
".quad 0x6625202c34316625,0x0a3b326625202c32,0x696e752e61726209,0x5f315f744c240920\n"
".quad 0x4c240a3b36383533,0x323438335f315f74,0x09636f6c2e090a3a,0x3009343132093631\n"
".quad 0x33662e766f6d090a,0x202c396625092032,0x6c2e090a3b326625,0x313209363109636f\n"
".quad 0x766f6d090a300935,0x662509203233662e,0x3b346625202c3031,0x3109636f6c2e090a\n"
".quad 0x0a30093931320936,0x3233662e766f6d09,0x202c343166250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c333166\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3231662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x30202c3131662509,0x3030303030303066,0x2f09202020203b30,0x5f744c240a30202f\n"
".quad 0x0a3a363835335f31,0x363109636f6c2e09,0x090a300933323209,0x203233732e627573\n"
".quad 0x7225202c36722509,0x6d090a3b31202c32,0x09203233752e766f,0x0a3b31202c377225\n"
".quad 0x71652e7074657309,0x702509203233732e,0x202c327225202c32,0x2540090a3b377225\n"
".quad 0x0920617262203270,0x30345f315f744c24,0x646461090a3b3839,0x662509203233662e\n"
".quad 0x34316625202c3531,0x0a3b33316625202c,0x3233662e766f6d09,0x202c363166250920\n"
".quad 0x3030303830346630,0x09202020203b3030,0x6573090a34202f2f,0x33662e746c2e7074\n"
".quad 0x202c337025092032,0x6625202c35316625,0x252140090a3b3631,0x0920617262203370\n"
".quad 0x30345f315f744c24,0x315f4c240a3b3839,0x200a3a323635325f,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x6f6c2e090a343232,0x3432320936310963\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x2c32316625202c37,0x090a3b3131662520\n"
".quad 0x203233662e646461,0x25202c3831662509,0x316625202c373166,0x2e646461090a3b37\n"
".quad 0x3166250920323366,0x2c30316625202c31,0x090a3b3831662520,0x09363109636f6c2e\n"
".quad 0x73090a3009353232,0x09203233662e6275,0x6625202c39316625,0x33316625202c3431\n"
".quad 0x662e646461090a3b,0x3231662509203233,0x25202c396625202c,0x6c2e090a3b393166\n"
".quad 0x323209363109636f,0x6c756d090a300936,0x662509203233662e,0x31316625202c3032\n"
".quad 0x0a3b31316625202c,0x3233662e766f6d09,0x202c333166250920,0x2e090a3b30326625\n"
".quad 0x3209363109636f6c,0x756d090a30093732,0x2509203233662e6c,0x316625202c313266\n"
".quad 0x3b32316625202c32,0x33662e766f6d090a,0x2c34316625092032,0x090a3b3132662520\n"
".quad 0x09363109636f6c2e,0x73090a3009333232,0x09203233732e6275,0x367225202c367225\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x090a3b30202c3872,0x2e71652e70746573\n"
".quad 0x3470250920323373,0x25202c367225202c,0x702540090a3b3872,0x2409206172622034\n"
".quad 0x3930345f315f744c,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c34323220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x0a323635325f315f,0x3233662e64646109,0x202c323266250920,0x6625202c30326625\n"
".quad 0x766f6d090a3b3132,0x662509203233662e,0x30346630202c3332,0x203b303030303038\n"
".quad 0x34202f2f09202020,0x6c2e70746573090a,0x2509203233662e74,0x32326625202c3570\n"
".quad 0x0a3b33326625202c,0x7262203570254009,0x5f315f4c24092061,0x4c240a3b32363532\n"
".quad 0x383930345f315f74,0x325f315f4c240a3a,0x6c2e090a3a383138,0x323209363109636f\n"
".quad 0x766f6d090a300939,0x722509203233732e,0x0a3b367225202c39,0x617261702e747309\n"
".quad 0x5b09203233732e6d,0x6572616475635f5f,0x4334315a5f5f6674,0x65646e614d636c61\n"
".quad 0x456649746f72626c,0x30535f30535f5469,0x2c5d62695f30535f,0x72090a3b39722520\n"
".quad 0x57444c240a3b7465,0x34315a5f5f646e65,0x646e614d636c6143,0x6649746f72626c65\n"
".quad 0x535f30535f546945,0x3a62695f30535f30,0x5f202f2f207d090a,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x535f546945664974,0x5f30535f30535f30,0x69762e090a0a6269\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233732e206d6172,0x72616475635f5f20\n"
".quad 0x34315a5f5f667465,0x646e614d636c6143,0x6449746f72626c65,0x535f30535f546945\n"
".quad 0x2962695f30535f30,0x6c614334315a5f20,0x626c65646e614d63,0x5469456449746f72\n"
".quad 0x535f30535f30535f,0x702e282062695f30,0x36662e206d617261,0x616475635f5f2034\n"
".quad 0x5f5f31666d726170,0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974\n"
".quad 0x5f30535f30535f30,0x7261702e202c6269,0x203436662e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f32666d72,0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564\n"
".quad 0x62695f30535f3053,0x6d617261702e202c,0x5f5f203436662e20,0x6d72617061647563\n"
".quad 0x4334315a5f5f3366,0x65646e614d636c61,0x456449746f72626c,0x30535f30535f5469\n"
".quad 0x202c62695f30535f,0x2e206d617261702e,0x75635f5f20343666,0x34666d7261706164\n"
".quad 0x6c614334315a5f5f,0x626c65646e614d63,0x5469456449746f72,0x535f30535f30535f\n"
".quad 0x702e202c62695f30,0x33732e206d617261,0x616475635f5f2032,0x5f5f35666d726170\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30\n"
".quad 0x7261702e202c6269,0x203233732e206d61,0x6170616475635f5f,0x315a5f5f36666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564,0x62695f30535f3053\n"
".quad 0x722e090a7b090a29,0x203233752e206765,0x0a3b3e31313c7225,0x662e206765722e09\n"
".quad 0x323c646625203436,0x65722e090a3b3e35,0x20646572702e2067,0x090a3b3e373c7025\n"
".quad 0x09363109636f6c2e,0x4c240a3009323032,0x5f6e696765625744,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x5f5469456449746f,0x30535f30535f3053,0x646c090a3a62695f\n"
".quad 0x662e6d617261702e,0x3164662509203436,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x636c614334315a5f,0x72626c65646e614d,0x5f5469456449746f,0x30535f30535f3053\n"
".quad 0x6d090a3b5d62695f,0x09203436662e766f,0x6625202c32646625,0x2e646c090a3b3164\n"
".quad 0x36662e6d61726170,0x2c33646625092034,0x616475635f5f5b20,0x5f5f32666d726170\n"
".quad 0x4d636c614334315a,0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30\n"
".quad 0x6f6d090a3b5d6269,0x2509203436662e76,0x646625202c346466,0x702e646c090a3b33\n"
".quad 0x3436662e6d617261,0x202c356466250920,0x70616475635f5f5b,0x5a5f5f33666d7261\n"
".quad 0x614d636c61433431,0x746f72626c65646e,0x30535f5469456449,0x695f30535f30535f\n"
".quad 0x766f6d090a3b5d62,0x662509203436662e,0x35646625202c3664,0x61702e646c090a3b\n"
".quad 0x203436662e6d6172,0x5b202c3764662509,0x6170616475635f5f,0x315a5f5f34666d72\n"
".quad 0x6e614d636c614334,0x49746f72626c6564,0x5f30535f54694564,0x62695f30535f3053\n"
".quad 0x2e766f6d090a3b5d,0x6466250920343666,0x3b37646625202c38,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563,0x4334315a5f5f3566\n"
".quad 0x65646e614d636c61,0x456449746f72626c,0x30535f30535f5469,0x3b5d62695f30535f\n"
".quad 0x33732e766f6d090a,0x202c327225092032,0x646c090a3b317225,0x752e6d617261702e\n"
".quad 0x2c33722509203233,0x616475635f5f5b20,0x5f5f36666d726170,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x535f546945644974,0x5f30535f30535f30,0x7663090a3b5d6269\n"
".quad 0x3233732e38732e74,0x25202c3472250920,0x766f6d090a3b3372,0x722509203233752e\n"
".quad 0x73090a3b30202c35,0x732e71652e707465,0x2c31702509203233,0x7225202c34722520\n"
".quad 0x31702540090a3b35,0x4c24092061726220,0x323438335f325f74,0x09636f6c2e090a3b\n"
".quad 0x3009353032093631,0x36662e766f6d090a,0x2c39646625092034,0x090a3b3664662520\n"
".quad 0x09363109636f6c2e,0x6d090a3009363032,0x09203436662e766f,0x25202c3031646625\n"
".quad 0x6c2e090a3b386466,0x303209363109636f,0x766f6d090a300937,0x662509203436662e\n"
".quad 0x646625202c313164,0x636f6c2e090a3b34,0x0938303209363109,0x662e766f6d090a30\n"
".quad 0x3164662509203436,0x3b32646625202c32,0x3109636f6c2e090a,0x0a30093930320936\n"
".quad 0x3436662e6c756d09,0x2c33316466250920,0x25202c3464662520,0x6c2e090a3b346466\n"
".quad 0x313209363109636f,0x6c756d090a300930,0x662509203436662e,0x646625202c343164\n"
".quad 0x3b32646625202c32,0x6e752e617262090a,0x325f744c24092069,0x240a3b363835335f\n"
".quad 0x3438335f325f744c,0x636f6c2e090a3a32,0x0934313209363109,0x662e766f6d090a30\n"
".quad 0x3964662509203436,0x0a3b32646625202c,0x363109636f6c2e09,0x090a300935313209\n"
".quad 0x203436662e766f6d,0x202c303164662509,0x2e090a3b34646625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093931,0x2509203436662e76,0x6430202c34316466,0x3030303030303030\n"
".quad 0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d,0x202c333164662509\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x36662e766f6d090a\n"
".quad 0x3231646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e766f6d090a3020,0x6466250920343666,0x30306430202c3131,0x3030303030303030\n"
".quad 0x093b303030303030,0x744c240a30202f2f,0x3a363835335f325f,0x3109636f6c2e090a\n"
".quad 0x0a30093332320936,0x3233732e62757309,0x25202c3672250920,0x090a3b31202c3272\n"
".quad 0x203233752e766f6d,0x3b31202c37722509,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x2c327225202c3270,0x40090a3b37722520,0x2061726220327025,0x345f325f744c2409\n"
".quad 0x6461090a3b383930,0x2509203436662e64,0x6625202c35316466,0x646625202c343164\n"
".quad 0x766f6d090a3b3331,0x662509203436662e,0x346430202c363164,0x3030303030303130\n"
".quad 0x3b30303030303030,0x73090a34202f2f09,0x662e746c2e707465,0x2c33702509203436\n"
".quad 0x202c353164662520,0x090a3b3631646625,0x7262203370252140,0x325f744c24092061\n"
".quad 0x240a3b383930345f,0x323635325f325f4c,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x090a34323220656e,0x09363109636f6c2e,0x6d090a3009343232\n"
".quad 0x09203436662e6c75,0x25202c3731646625,0x6625202c32316466,0x6461090a3b313164\n"
".quad 0x2509203436662e64,0x6625202c38316466,0x646625202c373164,0x646461090a3b3731\n"
".quad 0x662509203436662e,0x646625202c313164,0x31646625202c3031,0x636f6c2e090a3b38\n"
".quad 0x0935323209363109,0x662e627573090a30,0x3164662509203436,0x3431646625202c39\n"
".quad 0x3b3331646625202c,0x36662e646461090a,0x3231646625092034,0x202c39646625202c\n"
".quad 0x090a3b3931646625,0x09363109636f6c2e,0x6d090a3009363232,0x09203436662e6c75\n"
".quad 0x25202c3032646625,0x6625202c31316466,0x6f6d090a3b313164,0x2509203436662e76\n"
".quad 0x6625202c33316466,0x6c2e090a3b303264,0x323209363109636f,0x6c756d090a300937\n"
".quad 0x662509203436662e,0x646625202c313264,0x31646625202c3231,0x2e766f6d090a3b32\n"
".quad 0x6466250920343666,0x32646625202c3431,0x636f6c2e090a3b31,0x0933323209363109\n"
".quad 0x732e627573090a30,0x2c36722509203233,0x3b31202c36722520,0x33752e766f6d090a\n"
".quad 0x202c387225092032,0x70746573090a3b30,0x203233732e71652e,0x7225202c34702509\n"
".quad 0x0a3b387225202c36,0x7262203470254009,0x325f744c24092061,0x200a3b383930345f\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c343232,0x656c6562616c2064,0x325f325f4c242064,0x646461090a323635\n"
".quad 0x662509203436662e,0x646625202c323264,0x32646625202c3032,0x2e766f6d090a3b31\n"
".quad 0x6466250920343666,0x30346430202c3332,0x3030303030303031,0x093b303030303030\n"
".quad 0x6573090a34202f2f,0x36662e746c2e7074,0x202c357025092034,0x25202c3232646625\n"
".quad 0x40090a3b33326466,0x2061726220357025,0x35325f325f4c2409,0x5f744c240a3b3236\n"
".quad 0x0a3a383930345f32,0x3138325f325f4c24,0x636f6c2e090a3a38,0x0939323209363109\n"
".quad 0x732e766f6d090a30,0x2c39722509203233,0x73090a3b36722520,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323373,0x6674657261647563,0x6c614334315a5f5f,0x626c65646e614d63\n"
".quad 0x5469456449746f72,0x535f30535f30535f,0x25202c5d62695f30,0x746572090a3b3972\n"
".quad 0x6e6557444c240a3b,0x614334315a5f5f64,0x6c65646e614d636c,0x69456449746f7262\n"
".quad 0x5f30535f30535f54,0x090a3a62695f3053,0x315a5f202f2f207d,0x6e614d636c614334\n"
".quad 0x49746f72626c6564,0x5f30535f54694564,0x62695f30535f3053,0x72746e652e090a0a\n"
".quad 0x614d38315a5f2079,0x746f72626c65646e,0x30316d735f305344,0x3472616863753650\n"
".quad 0x6666666666696969,0x206269695f536666,0x7261702e09090a28,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f30534474\n"
".quad 0x7261686375365030,0x6666666669696934,0x6269695f53666666,0x09090a2c7473645f\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x305344746f72626c,0x75365030316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x616d695f6269695f,0x2e09090a2c576567,0x732e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262,0x6375365030316d73\n"
".quad 0x6669696934726168,0x5f53666666666666,0x67616d695f626969,0x702e09090a2c4865\n"
".quad 0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365030316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x636e7572635f6269,0x61702e09090a2c68,0x3233662e206d6172,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031\n"
".quad 0x6666666969693472,0x69695f5366666666,0x2c3066664f785f62,0x617261702e09090a\n"
".quad 0x5f203233662e206d,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x30316d735f305344,0x3472616863753650,0x6666666666696969,0x5f6269695f536666\n"
".quad 0x090a2c3166664f78,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f30,0x6969347261686375\n"
".quad 0x6666666666666669,0x4f795f6269695f53,0x2e09090a2c306666,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365030316d73,0x6669696934726168,0x5f53666666666666,0x66664f795f626969\n"
".quad 0x61702e09090a2c31,0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x090a2c504a785f62,0x206d617261702e09,0x635f5f203233662e\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f30\n"
".quad 0x6969347261686375,0x6666666666666669,0x4a795f6269695f53,0x61702e09090a2c50\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x6d735f305344746f,0x6168637536503031,0x6666666969693472,0x69695f5366666666\n"
".quad 0x2c656c6163735f62,0x617261702e09090a,0x6e67696c612e206d,0x5f2038622e203420\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x30316d735f305344\n"
".quad 0x3472616863753650,0x6666666666696969,0x5f6269695f536666,0x345b73726f6c6f63\n"
".quad 0x61702e09090a2c5d,0x3233732e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x2c656d6172665f62,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x30316d735f305344\n"
".quad 0x3472616863753650,0x6666666666696969,0x5f6269695f536666,0x6f6974616d696e61\n"
".quad 0x0a2c656d6172466e,0x6d617261702e0909,0x635f5f2038732e20,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f30,0x6969347261686375\n"
".quad 0x6666666666666669,0x73695f6269695f53,0x2e090a7b090a294a,0x3233752e20676572\n"
".quad 0x3b3e39363c722520,0x2e206765722e090a,0x3c64722520343675,0x65722e090a3b3e35\n"
".quad 0x25203233662e2067,0x0a3b3e3832323c66,0x702e206765722e09,0x313c702520646572\n"
".quad 0x6f6c2e090a3b3e31,0x0935350937310963,0x656257444c240a30,0x38315a5f5f6e6967\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x2e766f6d090a3a62,0x3172250920323375,0x646961746325202c\n"
".quad 0x766f6d090a3b782e,0x722509203233752e,0x6469746e25202c32,0x6c756d090a3b782e\n"
".quad 0x203233752e6f6c2e,0x7225202c33722509,0x0a3b327225202c31,0x3233752e766f6d09\n"
".quad 0x25202c3472250920,0x3b792e6469617463,0x33752e766f6d090a,0x202c357225092032\n"
".quad 0x3b792e6469746e25,0x6f6c2e6c756d090a,0x722509203233752e,0x202c347225202c36\n"
".quad 0x6f6d090a3b357225,0x2509203233752e76,0x64697425202c3772,0x646461090a3b782e\n"
".quad 0x722509203233752e,0x202c377225202c38,0x6f6d090a3b337225,0x2509203233752e76\n"
".quad 0x64697425202c3972,0x646461090a3b792e,0x722509203233752e,0x2c397225202c3031\n"
".quad 0x6c090a3b36722520,0x2e6d617261702e64,0x3172250920323373,0x75635f5f5b202c31\n"
".quad 0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c,0x75365030316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x616d695f6269695f,0x6c090a3b5d576567\n"
".quad 0x2e6d617261702e64,0x3172250920323373,0x75635f5f5b202c32,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365030316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x616d695f6269695f,0x73090a3b5d486567,0x33752e74672e7465\n"
".quad 0x2509203233732e32,0x317225202c333172,0x3b30317225202c32,0x33732e67656e090a\n"
".quad 0x2c34317225092032,0x090a3b3331722520,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c35317225,0x3b387225202c3131,0x33732e67656e090a,0x2c36317225092032\n"
".quad 0x090a3b3531722520,0x203233622e646e61,0x25202c3731722509,0x317225202c343172\n"
".quad 0x2e766f6d090a3b36,0x3172250920323375,0x73090a3b30202c38,0x732e71652e707465\n"
".quad 0x2c31702509203233,0x25202c3731722520,0x2540090a3b383172,0x0920617262203170\n"
".quad 0x34385f335f744c24,0x6f6c2e090a3b3035,0x0936360937310963,0x722e747663090a30\n"
".quad 0x33732e3233662e6e,0x202c316625092032,0x646c090a3b387225,0x662e6d617261702e\n"
".quad 0x2c32662509203233,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365030316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x656c6163735f6269,0x2e6c756d090a3b5d,0x3366250920323366,0x25202c316625202c\n"
".quad 0x2e646c090a3b3266,0x33662e6d61726170,0x202c346625092032,0x70616475635f5f5b\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031\n"
".quad 0x6666666969693472,0x69695f5366666666,0x5d3066664f785f62,0x662e646461090a3b\n"
".quad 0x2c35662509203233,0x6625202c33662520,0x2e627573090a3b34,0x3666250920323366\n"
".quad 0x25202c356625202c,0x627573090a3b3366,0x662509203233662e,0x202c346625202c37\n"
".quad 0x7573090a3b366625,0x2509203233662e62,0x2c356625202c3866,0x73090a3b36662520\n"
".quad 0x09203233662e6275,0x336625202c396625,0x090a3b386625202c,0x203233662e646461\n"
".quad 0x25202c3031662509,0x3b396625202c3766,0x7261702e646c090a,0x09203233662e6d61\n"
".quad 0x5f5b202c31316625,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x30316d735f305344,0x3472616863753650,0x6666666666696969,0x5f6269695f536666\n"
".quad 0x0a3b5d3166664f78,0x3233662e64646109,0x202c323166250920,0x6625202c31316625\n"
".quad 0x646461090a3b3031,0x662509203233662e,0x2c356625202c3331,0x090a3b3231662520\n"
".quad 0x203233662e627573,0x25202c3431662509,0x356625202c333166,0x662e627573090a3b\n"
".quad 0x3531662509203233,0x202c32316625202c,0x2e090a3b34316625,0x3609373109636f6c\n"
".quad 0x747663090a300937,0x2e3233662e6e722e,0x3166250920323373,0x3b30317225202c36\n"
".quad 0x33662e6c756d090a,0x2c37316625092032,0x25202c3631662520,0x2e646c090a3b3266\n"
".quad 0x33662e6d61726170,0x2c38316625092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f305344746f72,0x686375365030316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x3066664f795f6269,0x2e646461090a3b5d,0x3166250920323366\n"
".quad 0x2c37316625202c39,0x090a3b3831662520,0x203233662e627573,0x25202c3032662509\n"
".quad 0x316625202c393166,0x2e627573090a3b37,0x3266250920323366,0x2c38316625202c31\n"
".quad 0x090a3b3032662520,0x203233662e627573,0x25202c3232662509,0x326625202c393166\n"
".quad 0x2e627573090a3b30,0x3266250920323366,0x2c37316625202c33,0x090a3b3232662520\n"
".quad 0x203233662e646461,0x25202c3432662509,0x326625202c313266,0x702e646c090a3b33\n"
".quad 0x3233662e6d617261,0x202c353266250920,0x70616475635f5f5b,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x5d3166664f795f62,0x662e646461090a3b,0x3632662509203233\n"
".quad 0x202c35326625202c,0x61090a3b34326625,0x09203233662e6464,0x6625202c37326625\n"
".quad 0x36326625202c3931,0x662e627573090a3b,0x3832662509203233,0x202c37326625202c\n"
".quad 0x73090a3b39316625,0x09203233662e6275,0x6625202c39326625,0x38326625202c3632\n"
".quad 0x09636f6c2e090a3b,0x0a30093037093731,0x617261702e646c09,0x7225092038732e6d\n"
".quad 0x635f5f5b202c3931,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365030316d735f30,0x6969347261686375,0x6666666666666669,0x73695f6269695f53\n"
".quad 0x766f6d090a3b5d4a,0x722509203233752e,0x090a3b30202c3032,0x2e71652e70746573\n"
".quad 0x3270250920323373,0x202c39317225202c,0x40090a3b30327225,0x2061726220327025\n"
".quad 0x375f335f744c2409,0x6c2e090a3b323836,0x353209363109636f,0x2e646c090a300933\n"
".quad 0x33662e6d61726170,0x2c30336625092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f305344746f72,0x686375365030316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x3b5d504a785f6269,0x3109636f6c2e090a,0x0a30093535320936\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x5f5f5b202c313366,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5030316d735f3053,0x6934726168637536\n"
".quad 0x6666666666666969,0x795f6269695f5366,0x6c2e090a3b5d504a,0x353209363109636f\n"
".quad 0x766f6d090a300937,0x662509203233662e,0x37326625202c3233,0x09636f6c2e090a3b\n"
".quad 0x3009383532093631,0x33662e766f6d090a,0x2c33336625092032,0x090a3b3932662520\n"
".quad 0x09363109636f6c2e,0x6d090a3009393532,0x09203233662e766f,0x6625202c34336625\n"
".quad 0x6f6c2e090a3b3331,0x3036320936310963,0x2e766f6d090a3009,0x3366250920323366\n"
".quad 0x3b35316625202c35,0x3109636f6c2e090a,0x0a30093136320936,0x3233662e766f6d09\n"
".quad 0x202c363366250920,0x3430303036346630,0x09202020203b3030,0x0a33393138202f2f\n"
".quad 0x3233662e6c756d09,0x202c373366250920,0x6625202c37326625,0x627573090a3b3633\n"
".quad 0x662509203233662e,0x37336625202c3833,0x0a3b37326625202c,0x3233662e62757309\n"
".quad 0x202c393366250920,0x6625202c37336625,0x627573090a3b3833,0x662509203233662e\n"
".quad 0x37326625202c3034,0x0a3b39336625202c,0x3233662e6c756d09,0x202c313466250920\n"
".quad 0x6625202c37326625,0x6c756d090a3b3732,0x662509203233662e,0x37326625202c3234\n"
".quad 0x0a3b39326625202c,0x2e6e722e616d6609,0x3466250920323366,0x2c37326625202c33\n"
".quad 0x25202c3932662520,0x6461090a3b323466,0x2509203233662e64,0x346625202c343466\n"
".quad 0x3b33346625202c31,0x33662e6c756d090a,0x2c35346625092032,0x25202c3933662520\n"
".quad 0x7573090a3b393366,0x2509203233662e62,0x346625202c363466,0x3b31346625202c35\n"
".quad 0x33662e627573090a,0x2c37346625092032,0x25202c3434662520,0x6d66090a3b313466\n"
".quad 0x3233662e6e722e61,0x202c383466250920,0x6625202c39336625,0x36346625202c3034\n"
".quad 0x662e627573090a3b,0x3934662509203233,0x202c34346625202c,0x73090a3b37346625\n"
".quad 0x09203233662e6275,0x6625202c30356625,0x37346625202c3334,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x336625202c313566,0x2c30346625202c39,0x090a3b3834662520\n"
".quad 0x203233662e627573,0x25202c3235662509,0x346625202c313466,0x2e616d66090a3b39\n"
".quad 0x09203233662e6e72,0x6625202c33356625,0x30346625202c3034,0x0a3b31356625202c\n"
".quad 0x3233662e64646109,0x202c343566250920,0x6625202c30356625,0x646461090a3b3235\n"
".quad 0x662509203233662e,0x33356625202c3535,0x0a3b34356625202c,0x2e6e722e616d6609\n"
".quad 0x3566250920323366,0x2c39326625202c36,0x25202c3932662520,0x6461090a3b353566\n"
".quad 0x2509203233662e64,0x346625202c373566,0x3b36356625202c34,0x33662e766f6d090a\n"
".quad 0x2c38356625092032,0x090a3b3735662520,0x203233662e627573,0x25202c3935662509\n"
".quad 0x346625202c373566,0x2e627573090a3b34,0x3666250920323366,0x2c36356625202c30\n"
".quad 0x090a3b3935662520,0x09363109636f6c2e,0x6d090a3009323632,0x09203233662e766f\n"
".quad 0x6630202c31366625,0x3030343030303634,0x2f2f09202020203b,0x6d090a3339313820\n"
".quad 0x09203233662e6c75,0x6625202c32366625,0x31366625202c3331,0x662e627573090a3b\n"
".quad 0x3336662509203233,0x202c32366625202c,0x73090a3b33316625,0x09203233662e6275\n"
".quad 0x6625202c34366625,0x33366625202c3236,0x662e627573090a3b,0x3536662509203233\n"
".quad 0x202c33316625202c,0x6d090a3b34366625,0x09203233662e6c75,0x6625202c36366625\n"
".quad 0x33316625202c3331,0x662e6c756d090a3b,0x3736662509203233,0x202c33316625202c\n"
".quad 0x66090a3b35316625,0x33662e6e722e616d,0x2c38366625092032,0x25202c3331662520\n"
".quad 0x366625202c353166,0x2e646461090a3b37,0x3666250920323366,0x2c36366625202c39\n"
".quad 0x090a3b3836662520,0x203233662e6c756d,0x25202c3037662509,0x366625202c343666\n"
".quad 0x2e627573090a3b34,0x3766250920323366,0x2c30376625202c31,0x090a3b3636662520\n"
".quad 0x203233662e627573,0x25202c3237662509,0x366625202c393666,0x2e616d66090a3b36\n"
".quad 0x09203233662e6e72,0x6625202c33376625,0x35366625202c3436,0x0a3b31376625202c\n"
".quad 0x3233662e62757309,0x202c343766250920,0x6625202c39366625,0x627573090a3b3237\n"
".quad 0x662509203233662e,0x38366625202c3537,0x0a3b32376625202c,0x2e6e722e616d6609\n"
".quad 0x3766250920323366,0x2c34366625202c36,0x25202c3536662520,0x7573090a3b333766\n"
".quad 0x2509203233662e62,0x366625202c373766,0x3b34376625202c36,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x35366625202c3837,0x202c35366625202c,0x61090a3b36376625\n"
".quad 0x09203233662e6464,0x6625202c39376625,0x37376625202c3537,0x662e646461090a3b\n"
".quad 0x3038662509203233,0x202c38376625202c,0x66090a3b39376625,0x33662e6e722e616d\n"
".quad 0x2c31386625092032,0x25202c3531662520,0x386625202c353166,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x2c39366625202c32,0x090a3b3138662520,0x203233662e766f6d\n"
".quad 0x25202c3338662509,0x7573090a3b323866,0x2509203233662e62,0x386625202c343866\n"
".quad 0x3b39366625202c32,0x33662e627573090a,0x2c35386625092032,0x25202c3138662520\n"
".quad 0x6f6d090a3b343866,0x2509203233662e76,0x306630202c363866,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3738662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x20696e752e617262,0x375f335f744c2409\n"
".quad 0x744c240a3b363234,0x3a323836375f335f,0x3109636f6c2e090a,0x0a30093536320936\n"
".quad 0x3233662e766f6d09,0x202c303366250920,0x2e090a3b33316625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093636,0x2509203233662e76,0x316625202c373866,0x636f6c2e090a3b35\n"
".quad 0x0937363209363109,0x662e766f6d090a30,0x3133662509203233,0x0a3b37326625202c\n"
".quad 0x363109636f6c2e09,0x090a300938363209,0x203233662e766f6d,0x25202c3638662509\n"
".quad 0x6c2e090a3b393266,0x373209363109636f,0x766f6d090a300936,0x662509203233662e\n"
".quad 0x30306630202c3538,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c33386625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c30366625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3566250920323366,0x3030306630202c38,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c353366250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c343366\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3333662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x30202c3233662509,0x3030303030303066,0x2f09202020203b30,0x5f744c240a30202f\n"
".quad 0x0a3a363234375f33,0x363109636f6c2e09,0x090a300930383209,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x635f5f5b202c3132,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365030316d735f30,0x6969347261686375,0x6666666666666669\n"
".quad 0x72635f6269695f53,0x090a3b5d68636e75,0x203233732e627573,0x25202c3232722509\n"
".quad 0x0a3b31202c313272,0x3233752e766f6d09,0x202c333272250920,0x70746573090a3b31\n"
".quad 0x203233732e71652e,0x7225202c33702509,0x33327225202c3132,0x2033702540090a3b\n"
".quad 0x744c240920617262,0x3b323639385f335f,0x33662e646461090a,0x2c38386625092032\n"
".quad 0x25202c3338662520,0x7573090a3b383566,0x2509203233662e62,0x386625202c393866\n"
".quad 0x3b33386625202c38,0x33662e627573090a,0x2c30396625092032,0x25202c3838662520\n"
".quad 0x7573090a3b393866,0x2509203233662e62,0x356625202c313966,0x3b39386625202c38\n"
".quad 0x33662e627573090a,0x2c32396625092032,0x25202c3338662520,0x6461090a3b303966\n"
".quad 0x2509203233662e64,0x396625202c333966,0x3b32396625202c31,0x33662e646461090a\n"
".quad 0x2c34396625092032,0x25202c3339662520,0x6461090a3b353866,0x2509203233662e64\n"
".quad 0x396625202c353966,0x3b30366625202c34,0x33662e646461090a,0x2c36396625092032\n"
".quad 0x25202c3838662520,0x7573090a3b353966,0x2509203233662e62,0x396625202c373966\n"
".quad 0x3b38386625202c36,0x33662e627573090a,0x2c38396625092032,0x25202c3539662520\n"
".quad 0x6461090a3b373966,0x2509203233662e64,0x396625202c393966,0x3b38396625202c36\n"
".quad 0x33662e766f6d090a,0x3030316625092032,0x303830346630202c,0x2020203b30303030\n"
".quad 0x73090a34202f2f09,0x662e746c2e707465,0x2c34702509203233,0x25202c3939662520\n"
".quad 0x40090a3b30303166,0x6172622034702521,0x5f335f744c240920,0x6d090a3b32363938\n"
".quad 0x09203233662e766f,0x30202c3130316625,0x3034303030363466,0x2f2f092020203b30\n"
".quad 0x6d090a3339313820,0x09203233662e6c75,0x25202c3230316625,0x316625202c343366\n"
".quad 0x766f6d090a3b3130,0x662509203233662e,0x346630202c333031,0x3b30303430303036\n"
".quad 0x38202f2f09202020,0x6c756d090a333931,0x662509203233662e,0x336625202c343031\n"
".quad 0x3330316625202c32,0x662e627573090a3b,0x3031662509203233,0x3230316625202c35\n"
".quad 0x0a3b34336625202c,0x3233662e62757309,0x2c36303166250920,0x202c343031662520\n"
".quad 0x73090a3b32336625,0x09203233662e6275,0x25202c3730316625,0x6625202c32303166\n"
".quad 0x7573090a3b353031,0x2509203233662e62,0x6625202c38303166,0x316625202c343031\n"
".quad 0x627573090a3b3630,0x662509203233662e,0x336625202c393031,0x3730316625202c34\n"
".quad 0x662e627573090a3b,0x3131662509203233,0x2c32336625202c30,0x0a3b383031662520\n"
".quad 0x3938355f335f4c24,0x6c3c2f2f200a3a30,0x6f6f4c203e706f6f,0x6c2079646f622070\n"
".quad 0x0a31383220656e69,0x363109636f6c2e09,0x090a300931383209,0x203233662e6c756d\n"
".quad 0x202c313131662509,0x6625202c35336625,0x6c756d090a3b3233,0x662509203233662e\n"
".quad 0x336625202c323131,0x3b32336625202c34,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x336625202c333131,0x2c33336625202c34,0x0a3b313131662520,0x3233662e64646109\n"
".quad 0x2c34313166250920,0x202c323131662520,0x090a3b3331316625,0x203233662e627573\n"
".quad 0x202c353131662509,0x25202c3431316625,0x6d090a3b32313166,0x09203233662e6c75\n"
".quad 0x25202c3631316625,0x6625202c37303166,0x7573090a3b383031,0x2509203233662e62\n"
".quad 0x6625202c37313166,0x316625202c363131,0x627573090a3b3231,0x662509203233662e\n"
".quad 0x316625202c383131,0x31316625202c3331,0x2e627573090a3b35,0x3166250920323366\n"
".quad 0x31316625202c3931,0x3531316625202c34,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x6625202c30323166,0x316625202c373031,0x31316625202c3031,0x2e627573090a3b37\n"
".quad 0x3166250920323366,0x31316625202c3132,0x3931316625202c32,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x6625202c32323166,0x316625202c383031,0x32316625202c3930\n"
".quad 0x2e646461090a3b30,0x3166250920323366,0x31316625202c3332,0x3132316625202c38\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c34323166,0x316625202c393031\n"
".quad 0x32316625202c3031,0x2e646461090a3b32,0x3166250920323366,0x32316625202c3532\n"
".quad 0x3432316625202c33,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36323166\n"
".quad 0x33336625202c3533,0x3b3532316625202c,0x33662e646461090a,0x3732316625092032\n"
".quad 0x2c3431316625202c,0x0a3b363231662520,0x3233662e62757309,0x2c38323166250920\n"
".quad 0x202c373231662520,0x090a3b3431316625,0x203233662e627573,0x202c393231662509\n"
".quad 0x25202c3632316625,0x2e090a3b38323166,0x3209363109636f6c,0x6461090a30093238\n"
".quad 0x2509203233662e64,0x6625202c30333166,0x316625202c373231,0x627573090a3b3732\n"
".quad 0x662509203233662e,0x316625202c313331,0x32316625202c3033,0x2e627573090a3b37\n"
".quad 0x3166250920323366,0x32316625202c3233,0x3133316625202c37,0x662e627573090a3b\n"
".quad 0x3331662509203233,0x3033316625202c33,0x3b3133316625202c,0x33662e627573090a\n"
".quad 0x3433316625092032,0x2c3732316625202c,0x0a3b333331662520,0x3233662e64646109\n"
".quad 0x2c35333166250920,0x202c323331662520,0x090a3b3433316625,0x203233662e646461\n"
".quad 0x202c363331662509,0x25202c3533316625,0x61090a3b39323166,0x09203233662e6464\n"
".quad 0x25202c3733316625,0x6625202c36333166,0x6461090a3b393231,0x2509203233662e64\n"
".quad 0x6625202c38333166,0x316625202c303331,0x627573090a3b3733,0x662509203233662e\n"
".quad 0x316625202c393331,0x33316625202c3833,0x2e627573090a3b30,0x3166250920323366\n"
".quad 0x33316625202c3034,0x3933316625202c37,0x09636f6c2e090a3b,0x3009333832093631\n"
".quad 0x33662e646461090a,0x3134316625092032,0x2c3833316625202c,0x090a3b3133662520\n"
".quad 0x203233662e627573,0x202c323431662509,0x25202c3134316625,0x73090a3b38333166\n"
".quad 0x09203233662e6275,0x25202c3334316625,0x6625202c31343166,0x7573090a3b323431\n"
".quad 0x2509203233662e62,0x6625202c34343166,0x34316625202c3133,0x2e627573090a3b32\n"
".quad 0x3166250920323366,0x33316625202c3534,0x3334316625202c38,0x662e646461090a3b\n"
".quad 0x3431662509203233,0x3434316625202c36,0x3b3534316625202c,0x33662e646461090a\n"
".quad 0x3734316625092032,0x2c3634316625202c,0x0a3b303431662520,0x3233662e64646109\n"
".quad 0x2c38343166250920,0x202c373431662520,0x61090a3b36386625,0x09203233662e6464\n"
".quad 0x25202c3934316625,0x6625202c31343166,0x6f6d090a3b383431,0x2509203233662e76\n"
".quad 0x316625202c323366,0x627573090a3b3934,0x662509203233662e,0x316625202c303531\n"
".quad 0x34316625202c3934,0x2e627573090a3b31,0x3366250920323366,0x3834316625202c33\n"
".quad 0x3b3035316625202c,0x3109636f6c2e090a,0x0a30093638320936,0x3233662e62757309\n"
".quad 0x2c31353166250920,0x25202c3338662520,0x7573090a3b383566,0x2509203233662e62\n"
".quad 0x6625202c32353166,0x386625202c313531,0x2e627573090a3b33,0x3166250920323366\n"
".quad 0x35316625202c3335,0x3235316625202c31,0x662e646461090a3b,0x3531662509203233\n"
".quad 0x3235316625202c34,0x0a3b38356625202c,0x3233662e62757309,0x2c35353166250920\n"
".quad 0x25202c3338662520,0x73090a3b33353166,0x09203233662e6275,0x25202c3635316625\n"
".quad 0x6625202c35353166,0x6461090a3b343531,0x2509203233662e64,0x6625202c37353166\n"
".quad 0x386625202c363531,0x2e627573090a3b35,0x3166250920323366,0x35316625202c3835\n"
".quad 0x3b30366625202c37,0x33662e646461090a,0x3935316625092032,0x2c3135316625202c\n"
".quad 0x0a3b383531662520,0x3233662e64646109,0x2c30363166250920,0x202c393531662520\n"
".quad 0x73090a3b30336625,0x09203233662e6275,0x25202c3136316625,0x6625202c30363166\n"
".quad 0x7573090a3b393531,0x2509203233662e62,0x6625202c32363166,0x316625202c303631\n"
".quad 0x627573090a3b3136,0x662509203233662e,0x316625202c333631,0x36316625202c3935\n"
".quad 0x2e627573090a3b32,0x3166250920323366,0x30336625202c3436,0x3b3136316625202c\n"
".quad 0x33662e646461090a,0x3536316625092032,0x2c3336316625202c,0x0a3b343631662520\n"
".quad 0x3233662e62757309,0x2c36363166250920,0x202c393531662520,0x090a3b3135316625\n"
".quad 0x203233662e627573,0x202c373631662509,0x25202c3835316625,0x61090a3b36363166\n"
".quad 0x09203233662e6464,0x25202c3836316625,0x6625202c35363166,0x6461090a3b373631\n"
".quad 0x2509203233662e64,0x6625202c39363166,0x36316625202c3738,0x2e646461090a3b38\n"
".quad 0x3166250920323366,0x36316625202c3037,0x3936316625202c30,0x662e766f6d090a3b\n"
".quad 0x3433662509203233,0x3b3037316625202c,0x33662e627573090a,0x3137316625092032\n"
".quad 0x2c3037316625202c,0x0a3b303631662520,0x3233662e62757309,0x202c353366250920\n"
".quad 0x25202c3936316625,0x2e090a3b31373166,0x3209363109636f6c,0x6f6d090a30093838\n"
".quad 0x2509203233662e76,0x6630202c32373166,0x3030343030303634,0x202f2f092020203b\n"
".quad 0x756d090a33393138,0x2509203233662e6c,0x6625202c33373166,0x316625202c393431\n"
".quad 0x6c756d090a3b3237,0x662509203233662e,0x316625202c343731,0x33336625202c3934\n"
".quad 0x662e6c756d090a3b,0x3731662509203233,0x3934316625202c35,0x3b3934316625202c\n"
".quad 0x33662e627573090a,0x3637316625092032,0x2c3337316625202c,0x0a3b393431662520\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x34316625202c3737,0x2c33336625202c39\n"
".quad 0x0a3b343731662520,0x3233662e62757309,0x2c38303166250920,0x202c333731662520\n"
".quad 0x090a3b3637316625,0x203233662e646461,0x202c383731662509,0x25202c3537316625\n"
".quad 0x73090a3b37373166,0x09203233662e6275,0x25202c3031316625,0x6625202c39343166\n"
".quad 0x756d090a3b383031,0x2509203233662e6c,0x6625202c39373166,0x316625202c383031\n"
".quad 0x627573090a3b3830,0x662509203233662e,0x316625202c303831,0x37316625202c3937\n"
".quad 0x2e627573090a3b35,0x3166250920323366,0x37316625202c3138,0x3537316625202c38\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c32383166,0x316625202c383031\n"
".quad 0x38316625202c3031,0x2e627573090a3b30,0x3166250920323366,0x37316625202c3338\n"
".quad 0x3138316625202c37,0x662e627573090a3b,0x3831662509203233,0x3837316625202c34\n"
".quad 0x3b3138316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c353831\n"
".quad 0x31316625202c3830,0x3238316625202c30,0x662e627573090a3b,0x3831662509203233\n"
".quad 0x3537316625202c36,0x3b3438316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x316625202c373831,0x31316625202c3031,0x3538316625202c30,0x662e646461090a3b\n"
".quad 0x3831662509203233,0x3338316625202c38,0x3b3638316625202c,0x33662e646461090a\n"
".quad 0x3938316625092032,0x2c3738316625202c,0x0a3b383831662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x33336625202c3039,0x202c33336625202c,0x090a3b3938316625\n"
".quad 0x203233662e646461,0x202c313931662509,0x25202c3837316625,0x6d090a3b30393166\n"
".quad 0x09203233662e766f,0x6625202c38356625,0x7573090a3b313931,0x2509203233662e62\n"
".quad 0x6625202c32393166,0x316625202c313931,0x627573090a3b3837,0x662509203233662e\n"
".quad 0x39316625202c3036,0x3239316625202c30,0x09636f6c2e090a3b,0x3009393832093631\n"
".quad 0x33662e766f6d090a,0x3339316625092032,0x303036346630202c,0x2020203b30303430\n"
".quad 0x33393138202f2f09,0x33662e6c756d090a,0x3439316625092032,0x2c3037316625202c\n"
".quad 0x0a3b333931662520,0x3233662e6c756d09,0x2c35393166250920,0x202c303731662520\n"
".quad 0x6d090a3b35336625,0x09203233662e6c75,0x25202c3639316625,0x6625202c30373166\n"
".quad 0x7573090a3b303731,0x2509203233662e62,0x6625202c37393166,0x316625202c343931\n"
".quad 0x616d66090a3b3037,0x203233662e6e722e,0x202c383931662509,0x25202c3037316625\n"
".quad 0x316625202c353366,0x627573090a3b3539,0x662509203233662e,0x316625202c373031\n"
".quad 0x39316625202c3439,0x2e646461090a3b37,0x3166250920323366,0x39316625202c3939\n"
".quad 0x3839316625202c36,0x662e627573090a3b,0x3031662509203233,0x3037316625202c39\n"
".quad 0x3b3730316625202c,0x33662e6c756d090a,0x3030326625092032,0x2c3730316625202c\n"
".quad 0x0a3b373031662520,0x3233662e62757309,0x2c31303266250920,0x202c303032662520\n"
".quad 0x090a3b3639316625,0x203233662e627573,0x202c323032662509,0x25202c3939316625\n"
".quad 0x66090a3b36393166,0x33662e6e722e616d,0x3330326625092032,0x2c3730316625202c\n"
".quad 0x202c393031662520,0x090a3b3130326625,0x203233662e627573,0x202c343032662509\n"
".quad 0x25202c3839316625,0x73090a3b32303266,0x09203233662e6275,0x25202c3530326625\n"
".quad 0x6625202c39393166,0x6d66090a3b323032,0x3233662e6e722e61,0x2c36303266250920\n"
".quad 0x202c373031662520,0x25202c3930316625,0x73090a3b33303266,0x09203233662e6275\n"
".quad 0x25202c3730326625,0x6625202c36393166,0x6d66090a3b353032,0x3233662e6e722e61\n"
".quad 0x2c38303266250920,0x202c393031662520,0x25202c3930316625,0x61090a3b36303266\n"
".quad 0x09203233662e6464,0x25202c3930326625,0x6625202c34303266,0x6461090a3b373032\n"
".quad 0x2509203233662e64,0x6625202c30313266,0x326625202c383032,0x616d66090a3b3930\n"
".quad 0x203233662e6e722e,0x202c313132662509,0x6625202c35336625,0x31326625202c3533\n"
".quad 0x2e646461090a3b30,0x3266250920323366,0x39316625202c3231,0x3131326625202c39\n"
".quad 0x662e766f6d090a3b,0x3338662509203233,0x3b3231326625202c,0x33662e627573090a\n"
".quad 0x3331326625092032,0x2c3231326625202c,0x0a3b393931662520,0x3233662e62757309\n"
".quad 0x202c353866250920,0x25202c3131326625,0x2e090a3b33313266,0x3209363109636f6c\n"
".quad 0x6461090a30093039,0x2509203233662e64,0x6625202c34313266,0x326625202c313931\n"
".quad 0x627573090a3b3231,0x662509203233662e,0x326625202c353132,0x31326625202c3431\n"
".quad 0x2e627573090a3b32,0x3266250920323366,0x39316625202c3631,0x3531326625202c31\n"
".quad 0x662e627573090a3b,0x3132662509203233,0x3431326625202c37,0x3b3531326625202c\n"
".quad 0x33662e627573090a,0x3831326625092032,0x2c3231326625202c,0x0a3b373132662520\n"
".quad 0x3233662e64646109,0x2c39313266250920,0x202c363132662520,0x090a3b3831326625\n"
".quad 0x203233662e646461,0x202c303232662509,0x6625202c35386625,0x6461090a3b393132\n"
".quad 0x2509203233662e64,0x6625202c31323266,0x32326625202c3036,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x31326625202c3232,0x3132326625202c34,0x662e627573090a3b\n"
".quad 0x3232662509203233,0x3232326625202c33,0x3b3431326625202c,0x33662e627573090a\n"
".quad 0x3432326625092032,0x2c3132326625202c,0x0a3b333232662520,0x363109636f6c2e09\n"
".quad 0x090a300930383209,0x203233732e627573,0x25202c3232722509,0x0a3b31202c323272\n"
".quad 0x3233752e766f6d09,0x202c343272250920,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x7225202c35702509,0x34327225202c3232,0x2035702540090a3b,0x744c240920617262\n"
".quad 0x3b323639385f335f,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3138322065,0x6562616c20646165,0x335f4c242064656c\n"
".quad 0x61090a303938355f,0x09203233662e6464,0x25202c3532326625,0x6625202c34323266\n"
".quad 0x6f6d090a3b323232,0x2509203233662e76,0x6630202c36323266,0x3030303030383034\n"
".quad 0x202f2f092020203b,0x2e70746573090a34,0x09203233662e746c,0x326625202c367025\n"
".quad 0x32326625202c3532,0x36702540090a3b36,0x4c24092061726220,0x3b303938355f335f\n"
".quad 0x385f335f744c240a,0x5f4c240a3a323639,0x0a3a363431365f33,0x373109636f6c2e09\n"
".quad 0x6d090a3009303709,0x09203233732e766f,0x3b30202c35327225,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x32327225202c3770,0x0a3b35327225202c,0x3233732e62757309\n"
".quad 0x202c363272250920,0x7225202c31327225,0x766f6d090a3b3232,0x722509203233732e\n"
".quad 0x090a3b30202c3732,0x3233732e706c6573,0x202c383272250920,0x7225202c36327225\n"
".quad 0x3b377025202c3732,0x33752e766f6d090a,0x2c39327225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x25202c3870250920,0x327225202c383272,0x38702540090a3b39\n"
".quad 0x4c24092061726220,0x343931385f335f74,0x09636f6c2e090a3b,0x0a30093737093731\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c303372,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5030316d735f3053,0x6934726168637536\n"
".quad 0x6666666666666969,0x615f6269695f5366,0x6e6f6974616d696e,0x0a3b5d656d617246\n"
".quad 0x3233732e64646109,0x202c313372250920,0x7225202c30337225,0x2e646c090a3b3832\n"
".quad 0x38752e6d61726170,0x202c323372250920,0x70616475635f5f5b,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x73726f6c6f635f62,0x756d090a3b5d302b,0x3233732e6f6c2e6c\n"
".quad 0x202c333372250920,0x7225202c31337225,0x747663090a3b3233,0x203233752e38752e\n"
".quad 0x25202c3433722509,0x6c2e090a3b333372,0x383709373109636f,0x702e646c090a3009\n"
".quad 0x2038752e6d617261,0x5b202c3533722509,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f30534474,0x7261686375365030,0x6666666669696934\n"
".quad 0x6269695f53666666,0x2b73726f6c6f635f,0x6c756d090a3b5d31,0x203233732e6f6c2e\n"
".quad 0x25202c3633722509,0x337225202c313372,0x2e747663090a3b35,0x09203233752e3875\n"
".quad 0x7225202c37337225,0x6f6c2e090a3b3633,0x0939370937310963,0x61702e646c090a30\n"
".quad 0x092038752e6d6172,0x5f5b202c38337225,0x726170616475635f,0x614d38315a5f5f6d\n"
".quad 0x746f72626c65646e,0x30316d735f305344,0x3472616863753650,0x6666666666696969\n"
".quad 0x5f6269695f536666,0x322b73726f6c6f63,0x2e6c756d090a3b5d,0x09203233732e6f6c\n"
".quad 0x7225202c39337225,0x38337225202c3133,0x752e747663090a3b,0x2509203233752e38\n"
".quad 0x337225202c303472,0x2e617262090a3b39,0x744c240920696e75,0x3b383339375f335f\n"
".quad 0x385f335f744c240a,0x6c2e090a3a343931,0x333809373109636f,0x2e766f6d090a3009\n"
".quad 0x3472250920323375,0x6d090a3b30202c30,0x09203233752e766f,0x3b30202c37337225\n"
".quad 0x33752e766f6d090a,0x2c34337225092032,0x5f744c240a3b3020,0x0a3a383339375f33\n"
".quad 0x2e6f6c2e6c756d09,0x3472250920323373,0x2c31317225202c31,0x090a3b3031722520\n"
".quad 0x203233732e646461,0x25202c3234722509,0x387225202c313472,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x347225202c333472,0x63090a3b34202c32,0x752e3436752e7476\n"
".quad 0x3164722509203233,0x0a3b33347225202c,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5f5b202c326472,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5030316d735f3053,0x6934726168637536,0x6666666666666969,0x645f6269695f5366\n"
".quad 0x6461090a3b5d7473,0x2509203436752e64,0x647225202c336472,0x3b32647225202c31\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c34347225,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x30316d735f305344,0x3472616863753650\n"
".quad 0x6666666666696969,0x5f6269695f536666,0x0a3b5d656d617266,0x3233752e766f6d09\n"
".quad 0x202c353472250920,0x70746573090a3b30,0x203233732e656e2e,0x7225202c39702509\n"
".quad 0x35347225202c3434,0x2039702540090a3b,0x744c240920617262,0x3b363037385f335f\n"
".quad 0x3109636f6c2e090a,0x090a300930390937,0x203233752e766f6d,0x30202c3634722509\n"
".quad 0x6c672e7473090a3b,0x2e34762e6c61626f,0x6472255b09203875,0x257b202c5d302b33\n"
".quad 0x373372252c343372,0x72252c303472252c,0x7262090a3b7d3634,0x240920696e752e61\n"
".quad 0x3534385f335f744c,0x335f744c240a3b30,0x090a3a363037385f,0x09373109636f6c2e\n"
".quad 0x6461090a30093439,0x2509203233732e64,0x347225202c373472,0x73090a3b31202c34\n"
".quad 0x09203233732e7268,0x7225202c38347225,0x0a3b3133202c3734,0x3233732e766f6d09\n"
".quad 0x202c393472250920,0x2e646e61090a3b31,0x3572250920323362,0x2c38347225202c30\n"
".quad 0x090a3b3934722520,0x203233732e646461,0x25202c3135722509,0x347225202c303572\n"
".quad 0x2e726873090a3b37,0x3572250920323373,0x2c31357225202c32,0x2e646c090a3b3120\n"
".quad 0x762e6c61626f6c67,0x257b092038752e34,0x343572252c333572,0x7d5f2c353572252c\n"
".quad 0x2b336472255b202c,0x6c756d090a3b5d30,0x203233732e6f6c2e,0x25202c3635722509\n"
".quad 0x357225202c343472,0x2e646461090a3b33,0x3572250920323373,0x2c34337225202c37\n"
".quad 0x090a3b3635722520,0x203233732e646461,0x25202c3835722509,0x357225202c323572\n"
".quad 0x2e766964090a3b37,0x3572250920323373,0x2c38357225202c39,0x090a3b3734722520\n"
".quad 0x09373109636f6c2e,0x756d090a30093539,0x3233732e6f6c2e6c,0x202c303672250920\n"
".quad 0x7225202c34347225,0x646461090a3b3435,0x722509203233732e,0x37337225202c3136\n"
".quad 0x0a3b30367225202c,0x3233732e64646109,0x202c323672250920,0x7225202c32357225\n"
".quad 0x766964090a3b3136,0x722509203233732e,0x32367225202c3336,0x0a3b37347225202c\n"
".quad 0x626f6c672e747309,0x38752e32762e6c61,0x2b336472255b0920,0x3572257b202c5d30\n"
".quad 0x3b7d333672252c39,0x3109636f6c2e090a,0x090a300936390937,0x732e6f6c2e6c756d\n"
".quad 0x3436722509203233,0x202c34347225202c,0x61090a3b35357225,0x09203233732e6464\n"
".quad 0x7225202c35367225,0x34367225202c3034,0x732e646461090a3b,0x3636722509203233\n"
".quad 0x202c32357225202c,0x64090a3b35367225,0x09203233732e7669,0x7225202c37367225\n"
".quad 0x37347225202c3636,0x6c672e7473090a3b,0x2038752e6c61626f,0x322b336472255b09\n"
".quad 0x3b37367225202c5d,0x385f335f744c240a,0x744c240a3a303534,0x3a343139365f335f\n"
".quad 0x3109636f6c2e090a,0x090a300939390937,0x4c240a3b74697865,0x5a5f5f646e655744\n"
".quad 0x6c65646e614d3831,0x5f305344746f7262,0x6375365030316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x207d090a3a626969,0x4d38315a5f202f2f,0x6f72626c65646e61\n"
".quad 0x316d735f30534474,0x7261686375365030,0x6666666669696934,0x6269695f53666666\n"
".quad 0x72746e652e090a0a,0x614d38315a5f2079,0x746f72626c65646e,0x30316d735f315344\n"
".quad 0x3472616863753650,0x6666666666696969,0x206269695f536666,0x7261702e09090a28\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x316d735f31534474,0x7261686375365030,0x6666666669696934,0x6269695f53666666\n"
".quad 0x09090a2c7473645f,0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x315344746f72626c,0x75365030316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x616d695f6269695f,0x2e09090a2c576567,0x732e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f315344746f7262\n"
".quad 0x6375365030316d73,0x6669696934726168,0x5f53666666666666,0x67616d695f626969\n"
".quad 0x702e09090a2c4865,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365030316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x636e7572635f6269,0x61702e09090a2c68,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503031,0x6666666969693472,0x69695f5366666666,0x2c3066664f785f62\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x614d38315a5f5f6d\n"
".quad 0x746f72626c65646e,0x30316d735f315344,0x3472616863753650,0x6666666666696969\n"
".quad 0x5f6269695f536666,0x090a2c3166664f78,0x206d617261702e09,0x635f5f203233662e\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x4f795f6269695f53,0x2e09090a2c306666\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f315344746f7262,0x6375365030316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x66664f795f626969,0x61702e09090a2c31,0x3233662e206d6172,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503031\n"
".quad 0x6666666969693472,0x69695f5366666666,0x090a2c504a785f62,0x206d617261702e09\n"
".quad 0x635f5f203233662e,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365030316d735f31,0x6969347261686375,0x6666666666666669,0x4a795f6269695f53\n"
".quad 0x61702e09090a2c50,0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503031,0x6666666969693472\n"
".quad 0x69695f5366666666,0x2c656c6163735f62,0x617261702e09090a,0x6e67696c612e206d\n"
".quad 0x5f2038622e203420,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x30316d735f315344,0x3472616863753650,0x6666666666696969,0x5f6269695f536666\n"
".quad 0x345b73726f6c6f63,0x61702e09090a2c5d,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503031\n"
".quad 0x6666666969693472,0x69695f5366666666,0x2c656d6172665f62,0x617261702e09090a\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x30316d735f315344,0x3472616863753650,0x6666666666696969,0x5f6269695f536666\n"
".quad 0x6f6974616d696e61,0x0a2c656d6172466e,0x6d617261702e0909,0x635f5f2038732e20\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x73695f6269695f53,0x2e090a7b090a294a\n"
".quad 0x3233752e20676572,0x3e3635313c722520,0x206765722e090a3b,0x647225203436752e\n"
".quad 0x722e090a3b3e393c,0x203233662e206765,0x3b3e3832323c6625,0x2e206765722e090a\n"
".quad 0x3c70252064657270,0x6c2e090a3b3e3531,0x363109373109636f,0x57444c240a300931\n"
".quad 0x5a5f5f6e69676562,0x6c65646e614d3831,0x5f315344746f7262,0x6375365030316d73\n"
".quad 0x6669696934726168,0x5f53666666666666,0x6f6d090a3a626969,0x2509203233752e76\n"
".quad 0x61746325202c3172,0x6d090a3b782e6469,0x09203233752e766f,0x746e25202c327225\n"
".quad 0x6d090a3b782e6469,0x33752e6f6c2e6c75,0x202c337225092032,0x327225202c317225\n"
".quad 0x752e766f6d090a3b,0x2c34722509203233,0x2e64696174632520,0x2e766f6d090a3b79\n"
".quad 0x3572250920323375,0x2e6469746e25202c,0x2e6c756d090a3b79,0x09203233752e6f6c\n"
".quad 0x347225202c367225,0x090a3b357225202c,0x203233752e766f6d,0x7425202c37722509\n"
".quad 0x61090a3b782e6469,0x09203233752e6464,0x377225202c387225,0x090a3b337225202c\n"
".quad 0x203233752e766f6d,0x7425202c39722509,0x61090a3b792e6469,0x09203233752e6464\n"
".quad 0x7225202c30317225,0x0a3b367225202c39,0x617261702e646c09,0x2509203233732e6d\n"
".quad 0x5f5f5b202c313172,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5030316d735f3153,0x6934726168637536,0x6666666666666969,0x695f6269695f5366\n"
".quad 0x0a3b5d486567616d,0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c323172\n"
".quad 0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564,0x5030316d735f3153\n"
".quad 0x6934726168637536,0x6666666666666969,0x695f6269695f5366,0x0a3b5d576567616d\n"
".quad 0x2e74672e74657309,0x203233732e323375,0x25202c3331722509,0x317225202c313172\n"
".quad 0x2e67656e090a3b30,0x3172250920323373,0x3b33317225202c34,0x74672e746573090a\n"
".quad 0x3233732e3233752e,0x202c353172250920,0x7225202c32317225,0x2e67656e090a3b38\n"
".quad 0x3172250920323373,0x3b35317225202c36,0x33622e646e61090a,0x2c37317225092032\n"
".quad 0x25202c3431722520,0x6f6d090a3b363172,0x2509203233752e76,0x0a3b30202c383172\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c37317225202c31,0x090a3b3831722520\n"
".quad 0x6172622031702540,0x5f345f744c240920,0x090a3b3234363631,0x09373109636f6c2e\n"
".quad 0x6d090a3009393631,0x33732e6f6c2e6c75,0x2c39317225092032,0x25202c3231722520\n"
".quad 0x6461090a3b303172,0x2509203233732e64,0x317225202c303272,0x0a3b387225202c39\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c316472,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5030316d735f3153,0x6934726168637536\n"
".quad 0x6666666666666969,0x645f6269695f5366,0x756d090a3b5d7473,0x3233752e6f6c2e6c\n"
".quad 0x202c313272250920,0x3b34202c30327225,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x327225202c326472,0x2e646461090a3b31,0x6472250920343675,0x2c32647225202c33\n"
".quad 0x090a3b3164722520,0x61626f6c672e646c,0x2038752e34762e6c,0x252c323272257b09\n"
".quad 0x343272252c333272,0x72255b202c7d5f2c,0x090a3b5d302b3364,0x203233752e766f6d\n"
".quad 0x30202c3532722509,0x2e70746573090a3b,0x09203233732e656c,0x387225202c327025\n"
".quad 0x0a3b35327225202c,0x7262203270254009,0x345f744c24092061,0x0a3b30353834315f\n"
".quad 0x626f6c672e646c09,0x38752e34762e6c61,0x2c363272257b0920,0x3272252c37327225\n"
".quad 0x255b202c7d5f2c38,0x3b5d342d2b336472,0x3109636f6c2e090a,0x0a30093437310937\n"
".quad 0x3233732e62757309,0x202c393272250920,0x7225202c38327225,0x736261090a3b3432\n"
".quad 0x722509203233732e,0x39327225202c3033,0x732e766f6d090a3b,0x3133722509203233\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x337225202c323372\n"
".quad 0x3b31337225202c30,0x33732e67656e090a,0x2c33337225092032,0x090a3b3233722520\n"
".quad 0x203233732e627573,0x25202c3433722509,0x327225202c363272,0x2e736261090a3b32\n"
".quad 0x3372250920323373,0x3b34337225202c35,0x33732e766f6d090a,0x2c36337225092032\n"
".quad 0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e,0x35337225202c3733\n"
".quad 0x0a3b36337225202c,0x3233732e67656e09,0x202c383372250920,0x73090a3b37337225\n"
".quad 0x09203233732e6275,0x7225202c39337225,0x33327225202c3732,0x732e736261090a3b\n"
".quad 0x3034722509203233,0x0a3b39337225202c,0x3233732e766f6d09,0x202c313472250920\n"
".quad 0x746573090a3b3031,0x2e3233752e74672e,0x3472250920323373,0x2c30347225202c32\n"
".quad 0x090a3b3134722520,0x203233732e67656e,0x25202c3334722509,0x726f090a3b323472\n"
".quad 0x722509203233622e,0x38337225202c3434,0x0a3b33347225202c,0x203233622e726f09\n"
".quad 0x25202c3534722509,0x347225202c333372,0x2e617262090a3b34,0x744c240920696e75\n"
".quad 0x34393534315f345f,0x5f345f744c240a3b,0x090a3a3035383431,0x203233732e766f6d\n"
".quad 0x30202c3534722509,0x5f345f744c240a3b,0x090a3a3439353431,0x203233732e646461\n"
".quad 0x25202c3634722509,0x090a3b31202c3872,0x2e656c2e70746573,0x3370250920323373\n"
".quad 0x202c32317225202c,0x40090a3b36347225,0x2061726220337025,0x315f345f744c2409\n"
".quad 0x6c090a3b36303135,0x6c61626f6c672e64,0x092038752e34762e,0x72252c373472257b\n"
".quad 0x2c393472252c3834,0x6472255b202c7d5f,0x2e090a3b5d342b33,0x3109373109636f6c\n"
".quad 0x7573090a30093637,0x2509203233732e62,0x347225202c303572,0x3b34327225202c39\n"
".quad 0x33732e736261090a,0x2c31357225092032,0x090a3b3035722520,0x203233732e766f6d\n"
".quad 0x31202c3235722509,0x2e746573090a3b30,0x732e3233752e7467,0x3335722509203233\n"
".quad 0x202c31357225202c,0x6e090a3b32357225,0x09203233732e6765,0x7225202c34357225\n"
".quad 0x627573090a3b3335,0x722509203233732e,0x37347225202c3535,0x0a3b32327225202c\n"
".quad 0x3233732e73626109,0x202c363572250920,0x6d090a3b35357225,0x09203233732e766f\n"
".quad 0x3031202c37357225,0x672e746573090a3b,0x33732e3233752e74,0x2c38357225092032\n"
".quad 0x25202c3635722520,0x656e090a3b373572,0x2509203233732e67,0x357225202c393572\n"
".quad 0x2e627573090a3b38,0x3672250920323373,0x2c38347225202c30,0x090a3b3332722520\n"
".quad 0x203233732e736261,0x25202c3136722509,0x6f6d090a3b303672,0x2509203233732e76\n"
".quad 0x3b3031202c323672,0x74672e746573090a,0x3233732e3233752e,0x202c333672250920\n"
".quad 0x7225202c31367225,0x67656e090a3b3236,0x722509203233732e,0x33367225202c3436\n"
".quad 0x33622e726f090a3b,0x2c35367225092032,0x25202c3935722520,0x726f090a3b343672\n"
".quad 0x722509203233622e,0x34357225202c3636,0x0a3b35367225202c,0x3233732e64646109\n"
".quad 0x202c353472250920,0x7225202c35347225,0x5f744c240a3b3636,0x3a36303135315f34\n"
".quad 0x33752e766f6d090a,0x2c37367225092032,0x746573090a3b3020,0x3233732e656c2e70\n"
".quad 0x25202c3470250920,0x367225202c303172,0x34702540090a3b37,0x4c24092061726220\n"
".quad 0x313635315f345f74,0x636f6c2e090a3b38,0x0938373109373109,0x732e627573090a30\n"
".quad 0x3836722509203233,0x202c30327225202c,0x6d090a3b32317225,0x33752e6f6c2e6c75\n"
".quad 0x2c39367225092032,0x34202c3836722520,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x7225202c34647225,0x646461090a3b3936,0x722509203436752e,0x34647225202c3564\n"
".quad 0x0a3b31647225202c,0x626f6c672e646c09,0x38752e34762e6c61,0x2c303772257b0920\n"
".quad 0x3772252c31377225,0x255b202c7d5f2c32,0x0a3b5d302b356472,0x3233732e62757309\n"
".quad 0x202c333772250920,0x7225202c32377225,0x736261090a3b3432,0x722509203233732e\n"
".quad 0x33377225202c3437,0x732e766f6d090a3b,0x3537722509203233,0x73090a3b3031202c\n"
".quad 0x33752e74672e7465,0x2509203233732e32,0x377225202c363772,0x3b35377225202c34\n"
".quad 0x33732e67656e090a,0x2c37377225092032,0x090a3b3637722520,0x203233732e627573\n"
".quad 0x25202c3837722509,0x327225202c303772,0x2e736261090a3b32,0x3772250920323373\n"
".quad 0x3b38377225202c39,0x33732e766f6d090a,0x2c30387225092032,0x6573090a3b303120\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x39377225202c3138,0x0a3b30387225202c\n"
".quad 0x3233732e67656e09,0x202c323872250920,0x73090a3b31387225,0x09203233732e6275\n"
".quad 0x7225202c33387225,0x33327225202c3137,0x732e736261090a3b,0x3438722509203233\n"
".quad 0x0a3b33387225202c,0x3233732e766f6d09,0x202c353872250920,0x746573090a3b3031\n"
".quad 0x2e3233752e74672e,0x3872250920323373,0x2c34387225202c36,0x090a3b3538722520\n"
".quad 0x203233732e67656e,0x25202c3738722509,0x726f090a3b363872,0x722509203233622e\n"
".quad 0x32387225202c3838,0x0a3b37387225202c,0x203233622e726f09,0x25202c3938722509\n"
".quad 0x387225202c373772,0x2e646461090a3b38,0x3472250920323373,0x2c35347225202c35\n"
".quad 0x240a3b3938722520,0x3635315f345f744c,0x646461090a3a3831,0x722509203233732e\n"
".quad 0x30317225202c3039,0x6573090a3b31202c,0x33732e656c2e7074,0x202c357025092032\n"
".quad 0x7225202c31317225,0x702540090a3b3039,0x2409206172622035,0x3136315f345f744c\n"
".quad 0x6f6c2e090a3b3033,0x3038310937310963,0x2e646461090a3009,0x3972250920323373\n"
".quad 0x2c30327225202c31,0x090a3b3231722520,0x752e6f6c2e6c756d,0x3239722509203233\n"
".quad 0x202c31397225202c,0x2e747663090a3b34,0x203233752e343675,0x25202c3664722509\n"
".quad 0x6461090a3b323972,0x2509203436752e64,0x647225202c376472,0x3b31647225202c36\n"
".quad 0x6f6c672e646c090a,0x752e34762e6c6162,0x333972257b092038,0x72252c343972252c\n"
".quad 0x5b202c7d5f2c3539,0x3b5d302b37647225,0x33732e627573090a,0x2c36397225092032\n"
".quad 0x25202c3539722520,0x6261090a3b343272,0x2509203233732e73,0x397225202c373972\n"
".quad 0x2e766f6d090a3b36,0x3972250920323373,0x090a3b3031202c38,0x752e74672e746573\n"
".quad 0x09203233732e3233,0x7225202c39397225,0x38397225202c3739,0x732e67656e090a3b\n"
".quad 0x3031722509203233,0x3b39397225202c30,0x33732e627573090a,0x3130317225092032\n"
".quad 0x202c33397225202c,0x61090a3b32327225,0x09203233732e7362,0x25202c3230317225\n"
".quad 0x6d090a3b31303172,0x09203233732e766f,0x31202c3330317225,0x2e746573090a3b30\n"
".quad 0x732e3233752e7467,0x3031722509203233,0x3230317225202c34,0x3b3330317225202c\n"
".quad 0x33732e67656e090a,0x3530317225092032,0x3b3430317225202c,0x33732e627573090a\n"
".quad 0x3630317225092032,0x202c34397225202c,0x61090a3b33327225,0x09203233732e7362\n"
".quad 0x25202c3730317225,0x6d090a3b36303172,0x09203233732e766f,0x31202c3830317225\n"
".quad 0x2e746573090a3b30,0x732e3233752e7467,0x3031722509203233,0x3730317225202c39\n"
".quad 0x3b3830317225202c,0x33732e67656e090a,0x3031317225092032,0x3b3930317225202c\n"
".quad 0x3233622e726f090a,0x2c31313172250920,0x202c353031722520,0x090a3b3031317225\n"
".quad 0x09203233622e726f,0x25202c3231317225,0x7225202c30303172,0x6461090a3b313131\n"
".quad 0x2509203233732e64,0x347225202c353472,0x3231317225202c35,0x5f345f744c240a3b\n"
".quad 0x090a3a3033313631,0x203233752e766f6d,0x202c333131722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x7225202c36702509,0x31317225202c3534,0x36702540090a3b33\n"
".quad 0x4c24092061726220,0x343636315f345f74,0x636f6c2e090a3b32,0x0937383109373109\n"
".quad 0x722e747663090a30,0x33732e3233662e6e,0x202c316625092032,0x646c090a3b387225\n"
".quad 0x662e6d617261702e,0x2c32662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365030316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x656c6163735f6269,0x2e6c756d090a3b5d,0x3366250920323366\n"
".quad 0x25202c316625202c,0x2e646c090a3b3266,0x33662e6d61726170,0x202c346625092032\n"
".quad 0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503031,0x6666666969693472,0x69695f5366666666,0x5d3066664f785f62\n"
".quad 0x662e646461090a3b,0x2c35662509203233,0x6625202c33662520,0x2e627573090a3b34\n"
".quad 0x3666250920323366,0x25202c356625202c,0x627573090a3b3366,0x662509203233662e\n"
".quad 0x202c346625202c37,0x7573090a3b366625,0x2509203233662e62,0x2c356625202c3866\n"
".quad 0x73090a3b36662520,0x09203233662e6275,0x336625202c396625,0x090a3b386625202c\n"
".quad 0x203233662e646461,0x25202c3031662509,0x3b396625202c3766,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5b202c31316625,0x726170616475635f,0x614d38315a5f5f6d\n"
".quad 0x746f72626c65646e,0x30316d735f315344,0x3472616863753650,0x6666666666696969\n"
".quad 0x5f6269695f536666,0x0a3b5d3166664f78,0x3233662e64646109,0x202c323166250920\n"
".quad 0x6625202c31316625,0x646461090a3b3031,0x662509203233662e,0x2c356625202c3331\n"
".quad 0x090a3b3231662520,0x203233662e627573,0x25202c3431662509,0x356625202c333166\n"
".quad 0x662e627573090a3b,0x3531662509203233,0x202c32316625202c,0x2e090a3b34316625\n"
".quad 0x3109373109636f6c,0x7663090a30093838,0x3233662e6e722e74,0x662509203233732e\n"
".quad 0x30317225202c3631,0x662e6c756d090a3b,0x3731662509203233,0x202c36316625202c\n"
".quad 0x646c090a3b326625,0x662e6d617261702e,0x3831662509203233,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f315344746f7262,0x6375365030316d73\n"
".quad 0x6669696934726168,0x5f53666666666666,0x66664f795f626969,0x646461090a3b5d30\n"
".quad 0x662509203233662e,0x37316625202c3931,0x0a3b38316625202c,0x3233662e62757309\n"
".quad 0x202c303266250920,0x6625202c39316625,0x627573090a3b3731,0x662509203233662e\n"
".quad 0x38316625202c3132,0x0a3b30326625202c,0x3233662e62757309,0x202c323266250920\n"
".quad 0x6625202c39316625,0x627573090a3b3032,0x662509203233662e,0x37316625202c3332\n"
".quad 0x0a3b32326625202c,0x3233662e64646109,0x202c343266250920,0x6625202c31326625\n"
".quad 0x2e646c090a3b3332,0x33662e6d61726170,0x2c35326625092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f315344746f72,0x686375365030316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x3166664f795f6269,0x2e646461090a3b5d\n"
".quad 0x3266250920323366,0x2c35326625202c36,0x090a3b3432662520,0x203233662e646461\n"
".quad 0x25202c3732662509,0x326625202c393166,0x2e627573090a3b36,0x3266250920323366\n"
".quad 0x2c37326625202c38,0x090a3b3931662520,0x203233662e627573,0x25202c3932662509\n"
".quad 0x326625202c363266,0x636f6c2e090a3b38,0x0931393109373109,0x61702e646c090a30\n"
".quad 0x092038732e6d6172,0x5b202c3431317225,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365030,0x6666666669696934\n"
".quad 0x6269695f53666666,0x090a3b5d4a73695f,0x203233752e766f6d,0x202c353131722509\n"
".quad 0x70746573090a3b30,0x203233732e71652e,0x7225202c37702509,0x317225202c343131\n"
".quad 0x702540090a3b3531,0x2409206172622037,0x3437315f345f744c,0x6f6c2e090a3b3031\n"
".quad 0x3335320936310963,0x702e646c090a3009,0x3233662e6d617261,0x202c303366250920\n"
".quad 0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503031,0x6666666969693472,0x69695f5366666666,0x0a3b5d504a785f62\n"
".quad 0x363109636f6c2e09,0x090a300935353209,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x635f5f5b202c3133,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365030316d735f31,0x6969347261686375,0x6666666666666669,0x4a795f6269695f53\n"
".quad 0x6f6c2e090a3b5d50,0x3735320936310963,0x2e766f6d090a3009,0x3366250920323366\n"
".quad 0x3b37326625202c32,0x3109636f6c2e090a,0x0a30093835320936,0x3233662e766f6d09\n"
".quad 0x202c333366250920,0x2e090a3b39326625,0x3209363109636f6c,0x6f6d090a30093935\n"
".quad 0x2509203233662e76,0x316625202c343366,0x636f6c2e090a3b33,0x0930363209363109\n"
".quad 0x662e766f6d090a30,0x3533662509203233,0x0a3b35316625202c,0x363109636f6c2e09\n"
".quad 0x090a300931363209,0x203233662e766f6d,0x30202c3633662509,0x3034303030363466\n"
".quad 0x2f09202020203b30,0x090a33393138202f,0x203233662e6c756d,0x25202c3733662509\n"
".quad 0x336625202c373266,0x2e627573090a3b36,0x3366250920323366,0x2c37336625202c38\n"
".quad 0x090a3b3732662520,0x203233662e627573,0x25202c3933662509,0x336625202c373366\n"
".quad 0x2e627573090a3b38,0x3466250920323366,0x2c37326625202c30,0x090a3b3933662520\n"
".quad 0x203233662e6c756d,0x25202c3134662509,0x326625202c373266,0x2e6c756d090a3b37\n"
".quad 0x3466250920323366,0x2c37326625202c32,0x090a3b3932662520,0x662e6e722e616d66\n"
".quad 0x3334662509203233,0x202c37326625202c,0x6625202c39326625,0x646461090a3b3234\n"
".quad 0x662509203233662e,0x31346625202c3434,0x0a3b33346625202c,0x3233662e6c756d09\n"
".quad 0x202c353466250920,0x6625202c39336625,0x627573090a3b3933,0x662509203233662e\n"
".quad 0x35346625202c3634,0x0a3b31346625202c,0x3233662e62757309,0x202c373466250920\n"
".quad 0x6625202c34346625,0x616d66090a3b3134,0x203233662e6e722e,0x25202c3834662509\n"
".quad 0x346625202c393366,0x3b36346625202c30,0x33662e627573090a,0x2c39346625092032\n"
".quad 0x25202c3434662520,0x7573090a3b373466,0x2509203233662e62,0x346625202c303566\n"
".quad 0x3b37346625202c33,0x6e722e616d66090a,0x662509203233662e,0x39336625202c3135\n"
".quad 0x202c30346625202c,0x73090a3b38346625,0x09203233662e6275,0x6625202c32356625\n"
".quad 0x39346625202c3134,0x722e616d66090a3b,0x2509203233662e6e,0x346625202c333566\n"
".quad 0x2c30346625202c30,0x090a3b3135662520,0x203233662e646461,0x25202c3435662509\n"
".quad 0x356625202c303566,0x2e646461090a3b32,0x3566250920323366,0x2c33356625202c35\n"
".quad 0x090a3b3435662520,0x662e6e722e616d66,0x3635662509203233,0x202c39326625202c\n"
".quad 0x6625202c39326625,0x646461090a3b3535,0x662509203233662e,0x34346625202c3735\n"
".quad 0x0a3b36356625202c,0x3233662e766f6d09,0x202c383566250920,0x73090a3b37356625\n"
".quad 0x09203233662e6275,0x6625202c39356625,0x34346625202c3735,0x662e627573090a3b\n"
".quad 0x3036662509203233,0x202c36356625202c,0x2e090a3b39356625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093236,0x2509203233662e76,0x346630202c313666,0x3b30303430303036\n"
".quad 0x202f2f0920202020,0x756d090a33393138,0x2509203233662e6c,0x316625202c323666\n"
".quad 0x3b31366625202c33,0x33662e627573090a,0x2c33366625092032,0x25202c3236662520\n"
".quad 0x7573090a3b333166,0x2509203233662e62,0x366625202c343666,0x3b33366625202c32\n"
".quad 0x33662e627573090a,0x2c35366625092032,0x25202c3331662520,0x756d090a3b343666\n"
".quad 0x2509203233662e6c,0x316625202c363666,0x3b33316625202c33,0x33662e6c756d090a\n"
".quad 0x2c37366625092032,0x25202c3331662520,0x6d66090a3b353166,0x3233662e6e722e61\n"
".quad 0x202c383666250920,0x6625202c33316625,0x37366625202c3531,0x662e646461090a3b\n"
".quad 0x3936662509203233,0x202c36366625202c,0x6d090a3b38366625,0x09203233662e6c75\n"
".quad 0x6625202c30376625,0x34366625202c3436,0x662e627573090a3b,0x3137662509203233\n"
".quad 0x202c30376625202c,0x73090a3b36366625,0x09203233662e6275,0x6625202c32376625\n"
".quad 0x36366625202c3936,0x722e616d66090a3b,0x2509203233662e6e,0x366625202c333766\n"
".quad 0x2c35366625202c34,0x090a3b3137662520,0x203233662e627573,0x25202c3437662509\n"
".quad 0x376625202c393666,0x2e627573090a3b32,0x3766250920323366,0x2c38366625202c35\n"
".quad 0x090a3b3237662520,0x662e6e722e616d66,0x3637662509203233,0x202c34366625202c\n"
".quad 0x6625202c35366625,0x627573090a3b3337,0x662509203233662e,0x36366625202c3737\n"
".quad 0x0a3b34376625202c,0x2e6e722e616d6609,0x3766250920323366,0x2c35366625202c38\n"
".quad 0x25202c3536662520,0x6461090a3b363766,0x2509203233662e64,0x376625202c393766\n"
".quad 0x3b37376625202c35,0x33662e646461090a,0x2c30386625092032,0x25202c3837662520\n"
".quad 0x6d66090a3b393766,0x3233662e6e722e61,0x202c313866250920,0x6625202c35316625\n"
".quad 0x30386625202c3531,0x662e646461090a3b,0x3238662509203233,0x202c39366625202c\n"
".quad 0x6d090a3b31386625,0x09203233662e766f,0x6625202c33386625,0x627573090a3b3238\n"
".quad 0x662509203233662e,0x32386625202c3438,0x0a3b39366625202c,0x3233662e62757309\n"
".quad 0x202c353866250920,0x6625202c31386625,0x766f6d090a3b3438,0x662509203233662e\n"
".quad 0x30306630202c3638,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c37386625092032,0x3030303030663020,0x202020203b303030,0x62090a30202f2f09\n"
".quad 0x0920696e752e6172,0x37315f345f744c24,0x744c240a3b343531,0x30313437315f345f\n"
".quad 0x09636f6c2e090a3a,0x3009353632093631,0x33662e766f6d090a,0x2c30336625092032\n"
".quad 0x090a3b3331662520,0x09363109636f6c2e,0x6d090a3009363632,0x09203233662e766f\n"
".quad 0x6625202c37386625,0x6f6c2e090a3b3531,0x3736320936310963,0x2e766f6d090a3009\n"
".quad 0x3366250920323366,0x3b37326625202c31,0x3109636f6c2e090a,0x0a30093836320936\n"
".quad 0x3233662e766f6d09,0x202c363866250920,0x2e090a3b39326625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093637,0x2509203233662e76,0x306630202c353866,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3338662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3036662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x30306630202c3835,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c35336625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c34336625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3366250920323366,0x3030306630202c33,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c323366250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x744c240a30202f2f,0x34353137315f345f,0x09636f6c2e090a3a\n"
".quad 0x3009303832093631,0x7261702e646c090a,0x09203233732e6d61,0x5b202c3631317225\n"
".quad 0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474\n"
".quad 0x7261686375365030,0x6666666669696934,0x6269695f53666666,0x5d68636e7572635f\n"
".quad 0x732e627573090a3b,0x3131722509203233,0x3631317225202c37,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x3b31202c38313172,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x31317225202c3870,0x3831317225202c36,0x2038702540090a3b,0x744c240920617262\n"
".quad 0x38373138315f345f,0x662e646461090a3b,0x3838662509203233,0x202c33386625202c\n"
".quad 0x73090a3b38356625,0x09203233662e6275,0x6625202c39386625,0x33386625202c3838\n"
".quad 0x662e627573090a3b,0x3039662509203233,0x202c38386625202c,0x73090a3b39386625\n"
".quad 0x09203233662e6275,0x6625202c31396625,0x39386625202c3835,0x662e627573090a3b\n"
".quad 0x3239662509203233,0x202c33386625202c,0x61090a3b30396625,0x09203233662e6464\n"
".quad 0x6625202c33396625,0x32396625202c3139,0x662e646461090a3b,0x3439662509203233\n"
".quad 0x202c33396625202c,0x61090a3b35386625,0x09203233662e6464,0x6625202c35396625\n"
".quad 0x30366625202c3439,0x662e646461090a3b,0x3639662509203233,0x202c38386625202c\n"
".quad 0x73090a3b35396625,0x09203233662e6275,0x6625202c37396625,0x38386625202c3639\n"
".quad 0x662e627573090a3b,0x3839662509203233,0x202c35396625202c,0x61090a3b37396625\n"
".quad 0x09203233662e6464,0x6625202c39396625,0x38396625202c3639,0x662e766f6d090a3b\n"
".quad 0x3031662509203233,0x3830346630202c30,0x20203b3030303030,0x090a34202f2f0920\n"
".quad 0x2e746c2e70746573,0x3970250920323366,0x202c39396625202c,0x090a3b3030316625\n"
".quad 0x7262203970252140,0x345f744c24092061,0x0a3b38373138315f,0x3233662e766f6d09\n"
".quad 0x2c31303166250920,0x3030303634663020,0x092020203b303034,0x0a33393138202f2f\n"
".quad 0x3233662e6c756d09,0x2c32303166250920,0x25202c3433662520,0x6d090a3b31303166\n"
".quad 0x09203233662e766f,0x30202c3330316625,0x3034303030363466,0x2f2f092020203b30\n"
".quad 0x6d090a3339313820,0x09203233662e6c75,0x25202c3430316625,0x316625202c323366\n"
".quad 0x627573090a3b3330,0x662509203233662e,0x316625202c353031,0x34336625202c3230\n"
".quad 0x662e627573090a3b,0x3031662509203233,0x3430316625202c36,0x0a3b32336625202c\n"
".quad 0x3233662e62757309,0x2c37303166250920,0x202c323031662520,0x090a3b3530316625\n"
".quad 0x203233662e627573,0x202c383031662509,0x25202c3430316625,0x73090a3b36303166\n"
".quad 0x09203233662e6275,0x25202c3930316625,0x316625202c343366,0x627573090a3b3730\n"
".quad 0x662509203233662e,0x336625202c303131,0x3830316625202c32,0x315f345f4c240a3b\n"
".quad 0x2f200a3a38353033,0x203e706f6f6c3c2f,0x646f6220706f6f4c,0x3220656e696c2079\n"
".quad 0x636f6c2e090a3138,0x0931383209363109,0x662e6c756d090a30,0x3131662509203233\n"
".quad 0x2c35336625202c31,0x090a3b3233662520,0x203233662e6c756d,0x202c323131662509\n"
".quad 0x6625202c34336625,0x616d66090a3b3233,0x203233662e6e722e,0x202c333131662509\n"
".quad 0x6625202c34336625,0x31316625202c3333,0x2e646461090a3b31,0x3166250920323366\n"
".quad 0x31316625202c3431,0x3331316625202c32,0x662e627573090a3b,0x3131662509203233\n"
".quad 0x3431316625202c35,0x3b3231316625202c,0x33662e6c756d090a,0x3631316625092032\n"
".quad 0x2c3730316625202c,0x0a3b383031662520,0x3233662e62757309,0x2c37313166250920\n"
".quad 0x202c363131662520,0x090a3b3231316625,0x203233662e627573,0x202c383131662509\n"
".quad 0x25202c3331316625,0x73090a3b35313166,0x09203233662e6275,0x25202c3931316625\n"
".quad 0x6625202c34313166,0x6d66090a3b353131,0x3233662e6e722e61,0x2c30323166250920\n"
".quad 0x202c373031662520,0x25202c3031316625,0x73090a3b37313166,0x09203233662e6275\n"
".quad 0x25202c3132316625,0x6625202c32313166,0x6d66090a3b393131,0x3233662e6e722e61\n"
".quad 0x2c32323166250920,0x202c383031662520,0x25202c3930316625,0x61090a3b30323166\n"
".quad 0x09203233662e6464,0x25202c3332316625,0x6625202c38313166,0x6d66090a3b313231\n"
".quad 0x3233662e6e722e61,0x2c34323166250920,0x202c393031662520,0x25202c3031316625\n"
".quad 0x61090a3b32323166,0x09203233662e6464,0x25202c3532316625,0x6625202c33323166\n"
".quad 0x6d66090a3b343231,0x3233662e6e722e61,0x2c36323166250920,0x25202c3533662520\n"
".quad 0x316625202c333366,0x646461090a3b3532,0x662509203233662e,0x316625202c373231\n"
".quad 0x32316625202c3431,0x2e627573090a3b36,0x3166250920323366,0x32316625202c3832\n"
".quad 0x3431316625202c37,0x662e627573090a3b,0x3231662509203233,0x3632316625202c39\n"
".quad 0x3b3832316625202c,0x3109636f6c2e090a,0x0a30093238320936,0x3233662e64646109\n"
".quad 0x2c30333166250920,0x202c373231662520,0x090a3b3732316625,0x203233662e627573\n"
".quad 0x202c313331662509,0x25202c3033316625,0x73090a3b37323166,0x09203233662e6275\n"
".quad 0x25202c3233316625,0x6625202c37323166,0x7573090a3b313331,0x2509203233662e62\n"
".quad 0x6625202c33333166,0x316625202c303331,0x627573090a3b3133,0x662509203233662e\n"
".quad 0x316625202c343331,0x33316625202c3732,0x2e646461090a3b33,0x3166250920323366\n"
".quad 0x33316625202c3533,0x3433316625202c32,0x662e646461090a3b,0x3331662509203233\n"
".quad 0x3533316625202c36,0x3b3932316625202c,0x33662e646461090a,0x3733316625092032\n"
".quad 0x2c3633316625202c,0x0a3b393231662520,0x3233662e64646109,0x2c38333166250920\n"
".quad 0x202c303331662520,0x090a3b3733316625,0x203233662e627573,0x202c393331662509\n"
".quad 0x25202c3833316625,0x73090a3b30333166,0x09203233662e6275,0x25202c3034316625\n"
".quad 0x6625202c37333166,0x6c2e090a3b393331,0x383209363109636f,0x646461090a300933\n"
".quad 0x662509203233662e,0x316625202c313431,0x31336625202c3833,0x662e627573090a3b\n"
".quad 0x3431662509203233,0x3134316625202c32,0x3b3833316625202c,0x33662e627573090a\n"
".quad 0x3334316625092032,0x2c3134316625202c,0x0a3b323431662520,0x3233662e62757309\n"
".quad 0x2c34343166250920,0x25202c3133662520,0x73090a3b32343166,0x09203233662e6275\n"
".quad 0x25202c3534316625,0x6625202c38333166,0x6461090a3b333431,0x2509203233662e64\n"
".quad 0x6625202c36343166,0x316625202c343431,0x646461090a3b3534,0x662509203233662e\n"
".quad 0x316625202c373431,0x34316625202c3634,0x2e646461090a3b30,0x3166250920323366\n"
".quad 0x34316625202c3834,0x3b36386625202c37,0x33662e646461090a,0x3934316625092032\n"
".quad 0x2c3134316625202c,0x0a3b383431662520,0x3233662e766f6d09,0x202c323366250920\n"
".quad 0x090a3b3934316625,0x203233662e627573,0x202c303531662509,0x25202c3934316625\n"
".quad 0x73090a3b31343166,0x09203233662e6275,0x6625202c33336625,0x316625202c383431\n"
".quad 0x6f6c2e090a3b3035,0x3638320936310963,0x2e627573090a3009,0x3166250920323366\n"
".quad 0x33386625202c3135,0x0a3b38356625202c,0x3233662e62757309,0x2c32353166250920\n"
".quad 0x202c313531662520,0x73090a3b33386625,0x09203233662e6275,0x25202c3335316625\n"
".quad 0x6625202c31353166,0x6461090a3b323531,0x2509203233662e64,0x6625202c34353166\n"
".quad 0x356625202c323531,0x2e627573090a3b38,0x3166250920323366,0x33386625202c3535\n"
".quad 0x3b3335316625202c,0x33662e627573090a,0x3635316625092032,0x2c3535316625202c\n"
".quad 0x0a3b343531662520,0x3233662e64646109,0x2c37353166250920,0x202c363531662520\n"
".quad 0x73090a3b35386625,0x09203233662e6275,0x25202c3835316625,0x6625202c37353166\n"
".quad 0x646461090a3b3036,0x662509203233662e,0x316625202c393531,0x35316625202c3135\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x35316625202c3036,0x3b30336625202c39\n"
".quad 0x33662e627573090a,0x3136316625092032,0x2c3036316625202c,0x0a3b393531662520\n"
".quad 0x3233662e62757309,0x2c32363166250920,0x202c303631662520,0x090a3b3136316625\n"
".quad 0x203233662e627573,0x202c333631662509,0x25202c3935316625,0x73090a3b32363166\n"
".quad 0x09203233662e6275,0x25202c3436316625,0x316625202c303366,0x646461090a3b3136\n"
".quad 0x662509203233662e,0x316625202c353631,0x36316625202c3336,0x2e627573090a3b34\n"
".quad 0x3166250920323366,0x35316625202c3636,0x3135316625202c39,0x662e627573090a3b\n"
".quad 0x3631662509203233,0x3835316625202c37,0x3b3636316625202c,0x33662e646461090a\n"
".quad 0x3836316625092032,0x2c3536316625202c,0x0a3b373631662520,0x3233662e64646109\n"
".quad 0x2c39363166250920,0x25202c3738662520,0x61090a3b38363166,0x09203233662e6464\n"
".quad 0x25202c3037316625,0x6625202c30363166,0x6f6d090a3b393631,0x2509203233662e76\n"
".quad 0x316625202c343366,0x627573090a3b3037,0x662509203233662e,0x316625202c313731\n"
".quad 0x36316625202c3037,0x2e627573090a3b30,0x3366250920323366,0x3936316625202c35\n"
".quad 0x3b3137316625202c,0x3109636f6c2e090a,0x0a30093838320936,0x3233662e766f6d09\n"
".quad 0x2c32373166250920,0x3030303634663020,0x092020203b303034,0x0a33393138202f2f\n"
".quad 0x3233662e6c756d09,0x2c33373166250920,0x202c393431662520,0x090a3b3237316625\n"
".quad 0x203233662e6c756d,0x202c343731662509,0x25202c3934316625,0x756d090a3b333366\n"
".quad 0x2509203233662e6c,0x6625202c35373166,0x316625202c393431,0x627573090a3b3934\n"
".quad 0x662509203233662e,0x316625202c363731,0x34316625202c3337,0x2e616d66090a3b39\n"
".quad 0x09203233662e6e72,0x25202c3737316625,0x6625202c39343166,0x37316625202c3333\n"
".quad 0x2e627573090a3b34,0x3166250920323366,0x37316625202c3830,0x3637316625202c33\n"
".quad 0x662e646461090a3b,0x3731662509203233,0x3537316625202c38,0x3b3737316625202c\n"
".quad 0x33662e627573090a,0x3031316625092032,0x2c3934316625202c,0x0a3b383031662520\n"
".quad 0x3233662e6c756d09,0x2c39373166250920,0x202c383031662520,0x090a3b3830316625\n"
".quad 0x203233662e627573,0x202c303831662509,0x25202c3937316625,0x73090a3b35373166\n"
".quad 0x09203233662e6275,0x25202c3138316625,0x6625202c38373166,0x6d66090a3b353731\n"
".quad 0x3233662e6e722e61,0x2c32383166250920,0x202c383031662520,0x25202c3031316625\n"
".quad 0x73090a3b30383166,0x09203233662e6275,0x25202c3338316625,0x6625202c37373166\n"
".quad 0x7573090a3b313831,0x2509203233662e62,0x6625202c34383166,0x316625202c383731\n"
".quad 0x616d66090a3b3138,0x203233662e6e722e,0x202c353831662509,0x25202c3830316625\n"
".quad 0x6625202c30313166,0x7573090a3b323831,0x2509203233662e62,0x6625202c36383166\n"
".quad 0x316625202c353731,0x616d66090a3b3438,0x203233662e6e722e,0x202c373831662509\n"
".quad 0x25202c3031316625,0x6625202c30313166,0x6461090a3b353831,0x2509203233662e64\n"
".quad 0x6625202c38383166,0x316625202c333831,0x646461090a3b3638,0x662509203233662e\n"
".quad 0x316625202c393831,0x38316625202c3738,0x2e616d66090a3b38,0x09203233662e6e72\n"
".quad 0x25202c3039316625,0x336625202c333366,0x3938316625202c33,0x662e646461090a3b\n"
".quad 0x3931662509203233,0x3837316625202c31,0x3b3039316625202c,0x33662e766f6d090a\n"
".quad 0x2c38356625092032,0x0a3b313931662520,0x3233662e62757309,0x2c32393166250920\n"
".quad 0x202c313931662520,0x090a3b3837316625,0x203233662e627573,0x25202c3036662509\n"
".quad 0x6625202c30393166,0x6c2e090a3b323931,0x383209363109636f,0x766f6d090a300939\n"
".quad 0x662509203233662e,0x346630202c333931,0x3b30303430303036,0x38202f2f09202020\n"
".quad 0x6c756d090a333931,0x662509203233662e,0x316625202c343931,0x39316625202c3037\n"
".quad 0x2e6c756d090a3b33,0x3166250920323366,0x37316625202c3539,0x3b35336625202c30\n"
".quad 0x33662e6c756d090a,0x3639316625092032,0x2c3037316625202c,0x0a3b303731662520\n"
".quad 0x3233662e62757309,0x2c37393166250920,0x202c343931662520,0x090a3b3037316625\n"
".quad 0x662e6e722e616d66,0x3931662509203233,0x3037316625202c38,0x202c35336625202c\n"
".quad 0x090a3b3539316625,0x203233662e627573,0x202c373031662509,0x25202c3439316625\n"
".quad 0x61090a3b37393166,0x09203233662e6464,0x25202c3939316625,0x6625202c36393166\n"
".quad 0x7573090a3b383931,0x2509203233662e62,0x6625202c39303166,0x316625202c303731\n"
".quad 0x6c756d090a3b3730,0x662509203233662e,0x316625202c303032,0x30316625202c3730\n"
".quad 0x2e627573090a3b37,0x3266250920323366,0x30326625202c3130,0x3639316625202c30\n"
".quad 0x662e627573090a3b,0x3032662509203233,0x3939316625202c32,0x3b3639316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c333032,0x30316625202c3730\n"
".quad 0x3130326625202c39,0x662e627573090a3b,0x3032662509203233,0x3839316625202c34\n"
".quad 0x3b3230326625202c,0x33662e627573090a,0x3530326625092032,0x2c3939316625202c\n"
".quad 0x0a3b323032662520,0x2e6e722e616d6609,0x3266250920323366,0x30316625202c3630\n"
".quad 0x3930316625202c37,0x3b3330326625202c,0x33662e627573090a,0x3730326625092032\n"
".quad 0x2c3639316625202c,0x0a3b353032662520,0x2e6e722e616d6609,0x3266250920323366\n"
".quad 0x30316625202c3830,0x3930316625202c39,0x3b3630326625202c,0x33662e646461090a\n"
".quad 0x3930326625092032,0x2c3430326625202c,0x0a3b373032662520,0x3233662e64646109\n"
".quad 0x2c30313266250920,0x202c383032662520,0x090a3b3930326625,0x662e6e722e616d66\n"
".quad 0x3132662509203233,0x2c35336625202c31,0x25202c3533662520,0x61090a3b30313266\n"
".quad 0x09203233662e6464,0x25202c3231326625,0x6625202c39393166,0x6f6d090a3b313132\n"
".quad 0x2509203233662e76,0x326625202c333866,0x627573090a3b3231,0x662509203233662e\n"
".quad 0x326625202c333132,0x39316625202c3231,0x2e627573090a3b39,0x3866250920323366\n"
".quad 0x3131326625202c35,0x3b3331326625202c,0x3109636f6c2e090a,0x0a30093039320936\n"
".quad 0x3233662e64646109,0x2c34313266250920,0x202c313931662520,0x090a3b3231326625\n"
".quad 0x203233662e627573,0x202c353132662509,0x25202c3431326625,0x73090a3b32313266\n"
".quad 0x09203233662e6275,0x25202c3631326625,0x6625202c31393166,0x7573090a3b353132\n"
".quad 0x2509203233662e62,0x6625202c37313266,0x326625202c343132,0x627573090a3b3531\n"
".quad 0x662509203233662e,0x326625202c383132,0x31326625202c3231,0x2e646461090a3b37\n"
".quad 0x3266250920323366,0x31326625202c3931,0x3831326625202c36,0x662e646461090a3b\n"
".quad 0x3232662509203233,0x2c35386625202c30,0x0a3b393132662520,0x3233662e64646109\n"
".quad 0x2c31323266250920,0x25202c3036662520,0x61090a3b30323266,0x09203233662e6464\n"
".quad 0x25202c3232326625,0x6625202c34313266,0x7573090a3b313232,0x2509203233662e62\n"
".quad 0x6625202c33323266,0x326625202c323232,0x627573090a3b3431,0x662509203233662e\n"
".quad 0x326625202c343232,0x32326625202c3132,0x636f6c2e090a3b33,0x0930383209363109\n"
".quad 0x732e627573090a30,0x3131722509203233,0x3731317225202c37,0x6f6d090a3b31202c\n"
".quad 0x2509203233752e76,0x3b30202c39313172,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x317225202c303170,0x31317225202c3731,0x31702540090a3b39,0x2409206172622030\n"
".quad 0x3138315f345f744c,0x3c2f2f200a3b3837,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x31383220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x353033315f345f4c,0x662e646461090a38,0x3232662509203233,0x3432326625202c35\n"
".quad 0x3b3232326625202c,0x33662e766f6d090a,0x3632326625092032,0x303830346630202c\n"
".quad 0x2020203b30303030,0x73090a34202f2f09,0x662e746c2e707465,0x3131702509203233\n"
".quad 0x2c3532326625202c,0x0a3b363232662520,0x6220313170254009,0x345f4c2409206172\n"
".quad 0x0a3b38353033315f,0x38315f345f744c24,0x5f4c240a3a383731,0x3a34313333315f34\n"
".quad 0x3109636f6c2e090a,0x0a30093139310937,0x3233732e766f6d09,0x2c30323172250920\n"
".quad 0x746573090a3b3020,0x3233732e74672e70,0x202c323170250920,0x25202c3731317225\n"
".quad 0x73090a3b30323172,0x09203233732e6275,0x25202c3132317225,0x7225202c36313172\n"
".quad 0x6f6d090a3b373131,0x2509203233732e76,0x3b30202c32323172,0x732e706c6573090a\n"
".quad 0x3231722509203233,0x3132317225202c33,0x2c3232317225202c,0x090a3b3231702520\n"
".quad 0x203233752e766f6d,0x202c343231722509,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x25202c3331702509,0x7225202c33323172,0x2540090a3b343231,0x2061726220333170\n"
".quad 0x315f345f744c2409,0x2e090a3b32323937,0x3109373109636f6c,0x646c090a30093839\n"
".quad 0x732e6d617261702e,0x3231722509203233,0x75635f5f5b202c35,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x315344746f72626c,0x75365030316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x696e615f6269695f,0x72466e6f6974616d,0x61090a3b5d656d61\n"
".quad 0x09203233732e6464,0x25202c3632317225,0x7225202c35323172,0x646c090a3b333231\n"
".quad 0x752e6d617261702e,0x3732317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3831,0x5f315344746f7262,0x6375365030316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x6f6c6f635f626969,0x090a3b5d302b7372,0x732e6f6c2e6c756d\n"
".quad 0x3231722509203233,0x3632317225202c38,0x3b3732317225202c,0x38752e747663090a\n"
".quad 0x722509203233752e,0x317225202c393231,0x6f6c2e090a3b3832,0x3939310937310963\n"
".quad 0x702e646c090a3009,0x2038752e6d617261,0x202c303331722509,0x70616475635f5f5b\n"
".quad 0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f315344746f,0x6168637536503031\n"
".quad 0x6666666969693472,0x69695f5366666666,0x73726f6c6f635f62,0x756d090a3b5d312b\n"
".quad 0x3233732e6f6c2e6c,0x2c31333172250920,0x202c363231722520,0x090a3b3033317225\n"
".quad 0x752e38752e747663,0x3331722509203233,0x3133317225202c32,0x09636f6c2e090a3b\n"
".quad 0x3009303032093731,0x7261702e646c090a,0x25092038752e6d61,0x5f5b202c33333172\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x30316d735f315344\n"
".quad 0x3472616863753650,0x6666666666696969,0x5f6269695f536666,0x322b73726f6c6f63\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x25202c3433317225,0x7225202c36323172\n"
".quad 0x7663090a3b333331,0x3233752e38752e74,0x2c35333172250920,0x0a3b343331722520\n"
".quad 0x696e752e61726209,0x5f345f744c240920,0x240a3b3636363731,0x3937315f345f744c\n"
".quad 0x6f6c2e090a3a3232,0x3430320937310963,0x2e766f6d090a3009,0x3172250920323375\n"
".quad 0x090a3b30202c3533,0x203233752e766f6d,0x202c323331722509,0x2e766f6d090a3b30\n"
".quad 0x3172250920323375,0x240a3b30202c3932,0x3637315f345f744c,0x6f6c2e090a3a3636\n"
".quad 0x3031320937310963,0x702e646c090a3009,0x3233732e6d617261,0x2c36333172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38,0x735f315344746f72\n"
".quad 0x686375365030316d,0x6666696969347261,0x695f536666666666,0x656d6172665f6269\n"
".quad 0x2e646461090a3b5d,0x3172250920323373,0x33317225202c3733,0x73090a3b31202c36\n"
".quad 0x09203233732e7268,0x25202c3833317225,0x3133202c37333172,0x732e766f6d090a3b\n"
".quad 0x3331722509203233,0x61090a3b31202c39,0x09203233622e646e,0x25202c3034317225\n"
".quad 0x7225202c38333172,0x6461090a3b393331,0x2509203233732e64,0x7225202c31343172\n"
".quad 0x317225202c303431,0x726873090a3b3733,0x722509203233732e,0x317225202c323431\n"
".quad 0x090a3b31202c3134,0x732e6f6c2e6c756d,0x3431722509203233,0x3633317225202c33\n"
".quad 0x0a3b32327225202c,0x3233732e64646109,0x2c34343172250920,0x202c393231722520\n"
".quad 0x090a3b3334317225,0x203233732e646461,0x202c353431722509,0x25202c3234317225\n"
".quad 0x64090a3b34343172,0x09203233732e7669,0x25202c3634317225,0x7225202c35343172\n"
".quad 0x6c2e090a3b373331,0x313209373109636f,0x6c756d090a300931,0x203233732e6f6c2e\n"
".quad 0x202c373431722509,0x25202c3633317225,0x6461090a3b333272,0x2509203233732e64\n"
".quad 0x7225202c38343172,0x317225202c323331,0x646461090a3b3734,0x722509203233732e\n"
".quad 0x317225202c393431,0x34317225202c3234,0x2e766964090a3b38,0x3172250920323373\n"
".quad 0x34317225202c3035,0x3733317225202c39,0x6c672e7473090a3b,0x2e32762e6c61626f\n"
".quad 0x6472255b09203875,0x257b202c5d302b33,0x3172252c36343172,0x6c2e090a3b7d3035\n"
".quad 0x313209373109636f,0x6c756d090a300932,0x203233732e6f6c2e,0x202c313531722509\n"
".quad 0x25202c3633317225,0x6461090a3b343272,0x2509203233732e64,0x7225202c32353172\n"
".quad 0x317225202c353331,0x646461090a3b3135,0x722509203233732e,0x317225202c333531\n"
".quad 0x35317225202c3234,0x2e766964090a3b32,0x3172250920323373,0x35317225202c3435\n"
".quad 0x3733317225202c33,0x6c672e7473090a3b,0x2038752e6c61626f,0x322b336472255b09\n"
".quad 0x3435317225202c5d,0x5f345f744c240a3b,0x240a3a3234363631,0x3034315f345f744c\n"
".quad 0x6f6c2e090a3a3238,0x3531320937310963,0x74697865090a3009,0x6e6557444c240a3b\n"
".quad 0x614d38315a5f5f64,0x746f72626c65646e,0x30316d735f315344,0x3472616863753650\n"
".quad 0x6666666666696969,0x3a6269695f536666,0x5f202f2f207d090a,0x65646e614d38315a\n"
".quad 0x315344746f72626c,0x75365030316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x2e090a0a6269695f,0x5a5f207972746e65,0x6c65646e614d3631,0x6d735f30746f7262\n"
".quad 0x3650764566493031,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x0a28206269695f30,0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x45664930316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6269695f30535f32,0x09090a2c7473645f\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x507645664930316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x695f6269695f3053,0x090a2c576567616d,0x206d617261702e09\n"
".quad 0x635f5f203233732e,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x7645664930316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x5f6269695f30535f,0x0a2c486567616d69,0x6d617261702e0909,0x5f5f203233732e20\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x45664930316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6269695f30535f32\n"
".quad 0x2c68636e7572635f,0x617261702e09090a,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x664930316d735f30,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x0a2c66664f785f62\n"
".quad 0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x45664930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x090a2c66664f795f,0x206d617261702e09\n"
".quad 0x635f5f203233662e,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x7645664930316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x5f6269695f30535f,0x2e09090a2c504a78,0x662e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262,0x3650764566493031\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x4a795f6269695f30\n"
".quad 0x61702e09090a2c50,0x3233662e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x30316d735f30746f,0x6375365076456649,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6c6163735f626969,0x61702e09090a2c65\n"
".quad 0x696c612e206d6172,0x38622e2034206e67,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x30316d735f30746f,0x6375365076456649,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6f6c6f635f626969,0x090a2c5d345b7372\n"
".quad 0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x7645664930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x5f6269695f30535f,0x090a2c656d617266,0x206d617261702e09\n"
".quad 0x635f5f203233732e,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x7645664930316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x5f6269695f30535f,0x6f6974616d696e61,0x0a2c656d6172466e,0x6d617261702e0909\n"
".quad 0x635f5f2038732e20,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x7645664930316d73,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x5f6269695f30535f,0x0a7b090a294a7369,0x752e206765722e09,0x39363c7225203233\n"
".quad 0x6765722e090a3b3e,0x7225203436752e20,0x2e090a3b3e353c64,0x3233662e20676572\n"
".quad 0x3b3e34323c662520,0x2e206765722e090a,0x3c70252064657270,0x6c2e090a3b3e3131\n"
".quad 0x303109373109636f,0x6257444c240a3009,0x315a5f5f6e696765,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x7536507645664930,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x6d090a3a6269695f,0x09203233752e766f,0x746325202c317225\n"
".quad 0x090a3b782e646961,0x203233752e766f6d,0x6e25202c32722509,0x090a3b782e646974\n"
".quad 0x752e6f6c2e6c756d,0x2c33722509203233,0x7225202c31722520,0x2e766f6d090a3b32\n"
".quad 0x3472250920323375,0x646961746325202c,0x766f6d090a3b792e,0x722509203233752e\n"
".quad 0x6469746e25202c35,0x6c756d090a3b792e,0x203233752e6f6c2e,0x7225202c36722509\n"
".quad 0x0a3b357225202c34,0x3233752e766f6d09,0x25202c3772250920,0x090a3b782e646974\n"
".quad 0x203233752e646461,0x7225202c38722509,0x0a3b337225202c37,0x3233752e766f6d09\n"
".quad 0x25202c3972250920,0x090a3b792e646974,0x203233752e646461,0x25202c3031722509\n"
".quad 0x3b367225202c3972,0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c31317225\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664930316d735f30\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x576567616d695f62,0x702e646c090a3b5d,0x3233732e6d617261,0x202c323172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f30746f\n"
".quad 0x6375365076456649,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x67616d695f626969,0x6573090a3b5d4865,0x3233752e74672e74,0x722509203233732e\n"
".quad 0x32317225202c3331,0x0a3b30317225202c,0x3233732e67656e09,0x202c343172250920\n"
".quad 0x73090a3b33317225,0x33752e74672e7465,0x2509203233732e32,0x317225202c353172\n"
".quad 0x0a3b387225202c31,0x3233732e67656e09,0x202c363172250920,0x61090a3b35317225\n"
".quad 0x09203233622e646e,0x7225202c37317225,0x36317225202c3431,0x752e766f6d090a3b\n"
".quad 0x3831722509203233,0x6573090a3b30202c,0x33732e71652e7074,0x202c317025092032\n"
".quad 0x7225202c37317225,0x702540090a3b3831,0x2409206172622031,0x3534385f355f744c\n"
".quad 0x636f6c2e090a3b30,0x3009313209373109,0x6e722e747663090a,0x3233732e3233662e\n"
".quad 0x25202c3166250920,0x747663090a3b3872,0x2e3233662e6e722e,0x3266250920323373\n"
".quad 0x0a3b30317225202c,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3366\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x7645664930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x0a3b5d656c616373,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3466\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x7645664930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x090a3b5d66664f78,0x662e6e722e616d66,0x2c35662509203233,0x6625202c31662520\n"
".quad 0x0a3b346625202c33,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3666\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x7645664930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x090a3b5d66664f79,0x662e6e722e616d66,0x2c37662509203233,0x6625202c32662520\n"
".quad 0x0a3b366625202c33,0x617261702e646c09,0x7225092038732e6d,0x635f5f5b202c3931\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x7645664930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x6d090a3b5d4a7369,0x09203233752e766f,0x3b30202c30327225,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x39317225202c3270,0x0a3b30327225202c,0x7262203270254009\n"
".quad 0x355f744c24092061,0x090a3b323836375f,0x09363109636f6c2e,0x6c090a3009353032\n"
".quad 0x2e6d617261702e64,0x3866250920323366,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3650764566493031,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x4a785f6269695f30,0x6f6c2e090a3b5d50\n"
".quad 0x3630320936310963,0x702e646c090a3009,0x3233662e6d617261,0x5b202c3966250920\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4930316d735f3074\n"
".quad 0x6863753650764566,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x3b5d504a795f6269,0x3109636f6c2e090a,0x0a30093730320936,0x3233662e766f6d09\n"
".quad 0x202c303166250920,0x6c2e090a3b376625,0x303209363109636f,0x766f6d090a300938\n"
".quad 0x662509203233662e,0x3b356625202c3131,0x3109636f6c2e090a,0x0a30093930320936\n"
".quad 0x3233662e6c756d09,0x202c323166250920,0x376625202c376625,0x09636f6c2e090a3b\n"
".quad 0x3009303132093631,0x33662e6c756d090a,0x2c33316625092032,0x6625202c35662520\n"
".quad 0x2e617262090a3b35,0x744c240920696e75,0x3b363234375f355f,0x375f355f744c240a\n"
".quad 0x6c2e090a3a323836,0x313209363109636f,0x766f6d090a300934,0x662509203233662e\n"
".quad 0x0a3b356625202c38,0x363109636f6c2e09,0x090a300935313209,0x203233662e766f6d\n"
".quad 0x6625202c39662509,0x636f6c2e090a3b37,0x0939313209363109,0x662e766f6d090a30\n"
".quad 0x3331662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x30202c3231662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x30306630202c3131,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c30316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x4c240a30202f2f09,0x363234375f355f74,0x09636f6c2e090a3a\n"
".quad 0x3009333232093631,0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c31327225\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664930316d735f30\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x68636e7572635f62,0x2e627573090a3b5d,0x3272250920323373,0x2c31327225202c32\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x090a3b31202c3332,0x2e71652e70746573\n"
".quad 0x3370250920323373,0x202c31327225202c,0x40090a3b33327225,0x2061726220337025\n"
".quad 0x385f355f744c2409,0x6461090a3b323639,0x2509203233662e64,0x316625202c343166\n"
".quad 0x3b32316625202c33,0x33662e766f6d090a,0x2c35316625092032,0x3030383034663020\n"
".quad 0x202020203b303030,0x73090a34202f2f09,0x662e746c2e707465,0x2c34702509203233\n"
".quad 0x25202c3431662520,0x2140090a3b353166,0x2061726220347025,0x385f355f744c2409\n"
".quad 0x5f4c240a3b323639,0x0a3a303938355f35,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x6c2e090a34323220,0x323209363109636f,0x6c756d090a300934\n"
".quad 0x662509203233662e,0x31316625202c3631,0x0a3b30316625202c,0x3233662e64646109\n"
".quad 0x202c373166250920,0x6625202c36316625,0x646461090a3b3631,0x662509203233662e\n"
".quad 0x2c396625202c3031,0x090a3b3731662520,0x09363109636f6c2e,0x73090a3009353232\n"
".quad 0x09203233662e6275,0x6625202c38316625,0x32316625202c3331,0x662e646461090a3b\n"
".quad 0x3131662509203233,0x25202c386625202c,0x6c2e090a3b383166,0x323209363109636f\n"
".quad 0x6c756d090a300936,0x662509203233662e,0x30316625202c3931,0x0a3b30316625202c\n"
".quad 0x3233662e766f6d09,0x202c323166250920,0x2e090a3b39316625,0x3209363109636f6c\n"
".quad 0x756d090a30093732,0x2509203233662e6c,0x316625202c303266,0x3b31316625202c31\n"
".quad 0x33662e766f6d090a,0x2c33316625092032,0x090a3b3032662520,0x09363109636f6c2e\n"
".quad 0x73090a3009333232,0x09203233732e6275,0x7225202c32327225,0x090a3b31202c3232\n"
".quad 0x203233752e766f6d,0x30202c3432722509,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x327225202c357025,0x3b34327225202c32,0x622035702540090a,0x5f744c2409206172\n"
".quad 0x0a3b323639385f35,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c34323220,0x6c6562616c206461,0x5f355f4c24206465\n"
".quad 0x6461090a30393835,0x2509203233662e64,0x316625202c313266,0x3b30326625202c39\n"
".quad 0x33662e766f6d090a,0x2c32326625092032,0x3030383034663020,0x202020203b303030\n"
".quad 0x73090a34202f2f09,0x662e746c2e707465,0x2c36702509203233,0x25202c3132662520\n"
".quad 0x2540090a3b323266,0x0920617262203670,0x3938355f355f4c24,0x355f744c240a3b30\n"
".quad 0x240a3a323639385f,0x363431365f355f4c,0x09636f6c2e090a3a,0x0a30093132093731\n"
".quad 0x3233732e766f6d09,0x202c353272250920,0x70746573090a3b30,0x203233732e74672e\n"
".quad 0x7225202c37702509,0x35327225202c3232,0x732e627573090a3b,0x3632722509203233\n"
".quad 0x202c31327225202c,0x6d090a3b32327225,0x09203233732e766f,0x3b30202c37327225\n"
".quad 0x732e706c6573090a,0x3832722509203233,0x202c36327225202c,0x7025202c37327225\n"
".quad 0x2e766f6d090a3b37,0x3272250920323375,0x73090a3b30202c39,0x732e71652e707465\n"
".quad 0x2c38702509203233,0x25202c3832722520,0x2540090a3b393272,0x0920617262203870\n"
".quad 0x31385f355f744c24,0x6f6c2e090a3b3439,0x0938320937310963,0x61702e646c090a30\n"
".quad 0x203233732e6d6172,0x5b202c3033722509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3074,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x616d696e615f6269,0x6d6172466e6f6974\n"
".quad 0x646461090a3b5d65,0x722509203233732e,0x30337225202c3133,0x0a3b38327225202c\n"
".quad 0x617261702e646c09,0x7225092038752e6d,0x635f5f5b202c3233,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x7645664930316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f,0x302b73726f6c6f63\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x7225202c33337225,0x32337225202c3133\n"
".quad 0x752e747663090a3b,0x2509203233752e38,0x337225202c343372,0x636f6c2e090a3b33\n"
".quad 0x3009393209373109,0x7261702e646c090a,0x25092038752e6d61,0x5f5f5b202c353372\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564,0x45664930316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6269695f30535f32\n"
".quad 0x2b73726f6c6f635f,0x6c756d090a3b5d31,0x203233732e6f6c2e,0x25202c3633722509\n"
".quad 0x337225202c313372,0x2e747663090a3b35,0x09203233752e3875,0x7225202c37337225\n"
".quad 0x6f6c2e090a3b3633,0x0930330937310963,0x61702e646c090a30,0x092038752e6d6172\n"
".quad 0x5f5b202c38337225,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x664930316d735f30,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x73726f6c6f635f62,0x756d090a3b5d322b,0x3233732e6f6c2e6c\n"
".quad 0x202c393372250920,0x7225202c31337225,0x747663090a3b3833,0x203233752e38752e\n"
".quad 0x25202c3034722509,0x7262090a3b393372,0x240920696e752e61,0x3339375f355f744c\n"
".quad 0x355f744c240a3b38,0x090a3a343931385f,0x09373109636f6c2e,0x6f6d090a30093433\n"
".quad 0x2509203233752e76,0x0a3b30202c303472,0x3233752e766f6d09,0x202c373372250920\n"
".quad 0x2e766f6d090a3b30,0x3372250920323375,0x4c240a3b30202c34,0x383339375f355f74\n"
".quad 0x6c2e6c756d090a3a,0x2509203233732e6f,0x317225202c313472,0x3b30317225202c31\n"
".quad 0x33732e646461090a,0x2c32347225092032,0x25202c3134722520,0x6c756d090a3b3872\n"
".quad 0x203233752e6f6c2e,0x25202c3334722509,0x0a3b34202c323472,0x3436752e74766309\n"
".quad 0x722509203233752e,0x33347225202c3164,0x61702e646c090a3b,0x203436752e6d6172\n"
".quad 0x5b202c3264722509,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764566,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x3b5d7473645f6269,0x36752e646461090a,0x2c33647225092034\n"
".quad 0x25202c3164722520,0x646c090a3b326472,0x732e6d617261702e,0x3434722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262\n"
".quad 0x3650764566493031,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x72665f6269695f30,0x6d090a3b5d656d61,0x09203233752e766f,0x3b30202c35347225\n"
".quad 0x6e2e70746573090a,0x2509203233732e65,0x34347225202c3970,0x0a3b35347225202c\n"
".quad 0x7262203970254009,0x355f744c24092061,0x090a3b363037385f,0x09373109636f6c2e\n"
".quad 0x6f6d090a30093134,0x2509203233752e76,0x0a3b30202c363472,0x626f6c672e747309\n"
".quad 0x38752e34762e6c61,0x2b336472255b0920,0x3372257b202c5d30,0x252c373372252c34\n"
".quad 0x363472252c303472,0x2e617262090a3b7d,0x744c240920696e75,0x3b303534385f355f\n"
".quad 0x385f355f744c240a,0x6c2e090a3a363037,0x353409373109636f,0x2e646461090a3009\n"
".quad 0x3472250920323373,0x2c34347225202c37,0x726873090a3b3120,0x722509203233732e\n"
".quad 0x37347225202c3834,0x6d090a3b3133202c,0x09203233732e766f,0x3b31202c39347225\n"
".quad 0x33622e646e61090a,0x2c30357225092032,0x25202c3834722520,0x6461090a3b393472\n"
".quad 0x2509203233732e64,0x357225202c313572,0x3b37347225202c30,0x33732e726873090a\n"
".quad 0x2c32357225092032,0x31202c3135722520,0x6c672e646c090a3b,0x2e34762e6c61626f\n"
".quad 0x3572257b09203875,0x252c343572252c33,0x202c7d5f2c353572,0x5d302b336472255b\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x347225202c363572,0x3b33357225202c34\n"
".quad 0x33732e646461090a,0x2c37357225092032,0x25202c3433722520,0x6461090a3b363572\n"
".quad 0x2509203233732e64,0x357225202c383572,0x3b37357225202c32,0x33732e766964090a\n"
".quad 0x2c39357225092032,0x25202c3835722520,0x6c2e090a3b373472,0x363409373109636f\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c30367225,0x34357225202c3434\n"
".quad 0x732e646461090a3b,0x3136722509203233,0x202c37337225202c,0x61090a3b30367225\n"
".quad 0x09203233732e6464,0x7225202c32367225,0x31367225202c3235,0x732e766964090a3b\n"
".quad 0x3336722509203233,0x202c32367225202c,0x73090a3b37347225,0x6c61626f6c672e74\n"
".quad 0x092038752e32762e,0x5d302b336472255b,0x2c393572257b202c,0x090a3b7d33367225\n"
".quad 0x09373109636f6c2e,0x756d090a30093734,0x3233732e6f6c2e6c,0x202c343672250920\n"
".quad 0x7225202c34347225,0x646461090a3b3535,0x722509203233732e,0x30347225202c3536\n"
".quad 0x0a3b34367225202c,0x3233732e64646109,0x202c363672250920,0x7225202c32357225\n"
".quad 0x766964090a3b3536,0x722509203233732e,0x36367225202c3736,0x0a3b37347225202c\n"
".quad 0x626f6c672e747309,0x5b092038752e6c61,0x2c5d322b33647225,0x240a3b3736722520\n"
".quad 0x3534385f355f744c,0x355f744c240a3a30,0x090a3a343139365f,0x09373109636f6c2e\n"
".quad 0x7865090a30093035,0x57444c240a3b7469,0x36315a5f5f646e65,0x72626c65646e614d\n"
".quad 0x30316d735f30746f,0x6375365076456649,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x207d090a3a626969,0x4d36315a5f202f2f,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764566,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x6e652e090a0a6269,0x36315a5f20797274,0x72626c65646e614d\n"
".quad 0x30316d735f30746f,0x6375365076456449,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x09090a2820626969,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x507645644930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x645f6269695f3053\n"
".quad 0x702e09090a2c7473,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f30746f72,0x7536507645644930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x616d695f6269695f,0x2e09090a2c576567\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3650764564493031,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x6d695f6269695f30,0x09090a2c48656761,0x2e206d617261702e\n"
".quad 0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x507645644930316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x635f6269695f3053,0x090a2c68636e7572,0x206d617261702e09,0x635f5f203436662e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x7645644930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x09090a2c66664f78,0x2e206d617261702e,0x75635f5f20343666,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x507645644930316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x795f6269695f3053,0x2e09090a2c66664f\n"
".quad 0x662e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3650764564493031,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x4a785f6269695f30,0x61702e09090a2c50,0x3436662e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f30746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x2c504a795f626969,0x617261702e09090a,0x5f203436662e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644930316d735f30,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x2c656c6163735f62\n"
".quad 0x617261702e09090a,0x6e67696c612e206d,0x5f2038622e203420,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644930316d735f30,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x73726f6c6f635f62\n"
".quad 0x2e09090a2c5d345b,0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3650764564493031,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x72665f6269695f30,0x2e09090a2c656d61\n"
".quad 0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3650764564493031,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x6e615f6269695f30,0x466e6f6974616d69,0x09090a2c656d6172\n"
".quad 0x2e206d617261702e,0x6475635f5f203873,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3650764564493031,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x73695f6269695f30,0x2e090a7b090a294a,0x3233752e20676572\n"
".quad 0x3b3e39363c722520,0x2e206765722e090a,0x3c64722520343675,0x65722e090a3b3e35\n"
".quad 0x25203436662e2067,0x0a3b3e34323c6466,0x702e206765722e09,0x313c702520646572\n"
".quad 0x6f6c2e090a3b3e31,0x0930310937310963,0x656257444c240a30,0x36315a5f5f6e6967\n"
".quad 0x72626c65646e614d,0x30316d735f30746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6f6d090a3a626969,0x2509203233752e76\n"
".quad 0x61746325202c3172,0x6d090a3b782e6469,0x09203233752e766f,0x746e25202c327225\n"
".quad 0x6d090a3b782e6469,0x33752e6f6c2e6c75,0x202c337225092032,0x327225202c317225\n"
".quad 0x752e766f6d090a3b,0x2c34722509203233,0x2e64696174632520,0x2e766f6d090a3b79\n"
".quad 0x3572250920323375,0x2e6469746e25202c,0x2e6c756d090a3b79,0x09203233752e6f6c\n"
".quad 0x347225202c367225,0x090a3b357225202c,0x203233752e766f6d,0x7425202c37722509\n"
".quad 0x61090a3b782e6469,0x09203233752e6464,0x377225202c387225,0x090a3b337225202c\n"
".quad 0x203233752e766f6d,0x7425202c39722509,0x61090a3b792e6469,0x09203233752e6464\n"
".quad 0x7225202c30317225,0x0a3b367225202c39,0x617261702e646c09,0x2509203233732e6d\n"
".quad 0x5f5f5b202c313172,0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564\n"
".quad 0x45644930316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6269695f30535f32,0x5d576567616d695f,0x61702e646c090a3b,0x203233732e6d6172\n"
".quad 0x5b202c3231722509,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x6567616d695f6269,0x746573090a3b5d48,0x2e3233752e74672e\n"
".quad 0x3172250920323373,0x2c32317225202c33,0x090a3b3031722520,0x203233732e67656e\n"
".quad 0x25202c3431722509,0x6573090a3b333172,0x3233752e74672e74,0x722509203233732e\n"
".quad 0x31317225202c3531,0x090a3b387225202c,0x203233732e67656e,0x25202c3631722509\n"
".quad 0x6e61090a3b353172,0x2509203233622e64,0x317225202c373172,0x3b36317225202c34\n"
".quad 0x33752e766f6d090a,0x2c38317225092032,0x746573090a3b3020,0x3233732e71652e70\n"
".quad 0x25202c3170250920,0x317225202c373172,0x31702540090a3b38,0x4c24092061726220\n"
".quad 0x303534385f365f74,0x09636f6c2e090a3b,0x0a30093132093731,0x617261702e646c09\n"
".quad 0x2509203436662e6d,0x5f5f5b202c316466,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x45644930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x3b5d656c6163735f,0x7261702e646c090a\n"
".quad 0x09203436662e6d61,0x5f5b202c32646625,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644930316d735f30,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x3b5d66664f785f62,0x6e722e747663090a\n"
".quad 0x3233732e3436662e,0x202c336466250920,0x616d090a3b387225,0x3436662e6e722e64\n"
".quad 0x202c346466250920,0x6625202c33646625,0x32646625202c3164,0x61702e646c090a3b\n"
".quad 0x203436662e6d6172,0x5b202c3564662509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3074,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x5d66664f795f6269,0x722e747663090a3b\n"
".quad 0x33732e3436662e6e,0x2c36646625092032,0x090a3b3031722520,0x662e6e722e64616d\n"
".quad 0x3764662509203436,0x202c36646625202c,0x6625202c31646625,0x2e646c090a3b3564\n"
".quad 0x38732e6d61726170,0x202c393172250920,0x70616475635f5f5b,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x30316d735f30746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x5d4a73695f626969,0x752e766f6d090a3b\n"
".quad 0x3032722509203233,0x6573090a3b30202c,0x33732e71652e7074,0x202c327025092032\n"
".quad 0x7225202c39317225,0x702540090a3b3032,0x2409206172622032,0x3836375f365f744c\n"
".quad 0x636f6c2e090a3b32,0x0935303209363109,0x61702e646c090a30,0x203436662e6d6172\n"
".quad 0x5b202c3864662509,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x3b5d504a785f6269,0x3109636f6c2e090a,0x0a30093630320936\n"
".quad 0x617261702e646c09,0x2509203436662e6d,0x5f5f5b202c396466,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x45644930316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6269695f30535f32,0x090a3b5d504a795f\n"
".quad 0x09363109636f6c2e,0x6d090a3009373032,0x09203436662e766f,0x25202c3031646625\n"
".quad 0x6c2e090a3b376466,0x303209363109636f,0x766f6d090a300938,0x662509203436662e\n"
".quad 0x646625202c313164,0x636f6c2e090a3b34,0x0939303209363109,0x662e6c756d090a30\n"
".quad 0x3164662509203436,0x2c37646625202c32,0x090a3b3764662520,0x09363109636f6c2e\n"
".quad 0x6d090a3009303132,0x09203436662e6c75,0x25202c3331646625,0x646625202c346466\n"
".quad 0x2e617262090a3b34,0x744c240920696e75,0x3b363234375f365f,0x375f365f744c240a\n"
".quad 0x6c2e090a3a323836,0x313209363109636f,0x766f6d090a300934,0x662509203436662e\n"
".quad 0x34646625202c3864,0x09636f6c2e090a3b,0x3009353132093631,0x36662e766f6d090a\n"
".quad 0x2c39646625092034,0x090a3b3764662520,0x09363109636f6c2e,0x6d090a3009393132\n"
".quad 0x09203436662e766f,0x30202c3331646625,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e766f6d09,0x2c32316466250920,0x3030303030643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x662e766f6d090a30,0x3164662509203436\n"
".quad 0x3030306430202c31,0x3030303030303030,0x2f093b3030303030,0x766f6d090a30202f\n"
".quad 0x662509203436662e,0x306430202c303164,0x3030303030303030,0x3b30303030303030\n"
".quad 0x4c240a30202f2f09,0x363234375f365f74,0x09636f6c2e090a3a,0x3009333232093631\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c31327225,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644930316d735f30,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x68636e7572635f62\n"
".quad 0x2e627573090a3b5d,0x3272250920323373,0x2c31327225202c32,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x090a3b31202c3332,0x2e71652e70746573,0x3370250920323373\n"
".quad 0x202c31327225202c,0x40090a3b33327225,0x2061726220337025,0x385f365f744c2409\n"
".quad 0x6461090a3b323639,0x2509203436662e64,0x6625202c34316466,0x646625202c333164\n"
".quad 0x766f6d090a3b3231,0x662509203436662e,0x346430202c353164,0x3030303030303130\n"
".quad 0x3b30303030303030,0x73090a34202f2f09,0x662e746c2e707465,0x2c34702509203436\n"
".quad 0x202c343164662520,0x090a3b3531646625,0x7262203470252140,0x365f744c24092061\n"
".quad 0x240a3b323639385f,0x303938355f365f4c,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x090a34323220656e,0x09363109636f6c2e,0x6d090a3009343232\n"
".quad 0x09203436662e6c75,0x25202c3631646625,0x6625202c31316466,0x6461090a3b303164\n"
".quad 0x2509203436662e64,0x6625202c37316466,0x646625202c363164,0x646461090a3b3631\n"
".quad 0x662509203436662e,0x646625202c303164,0x3731646625202c39,0x09636f6c2e090a3b\n"
".quad 0x3009353232093631,0x36662e627573090a,0x3831646625092034,0x2c3331646625202c\n"
".quad 0x0a3b323164662520,0x3436662e64646109,0x2c31316466250920,0x25202c3864662520\n"
".quad 0x2e090a3b38316466,0x3209363109636f6c,0x756d090a30093632,0x2509203436662e6c\n"
".quad 0x6625202c39316466,0x646625202c303164,0x766f6d090a3b3031,0x662509203436662e\n"
".quad 0x646625202c323164,0x6f6c2e090a3b3931,0x3732320936310963,0x2e6c756d090a3009\n"
".quad 0x6466250920343666,0x31646625202c3032,0x3131646625202c31,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x3032646625202c33,0x09636f6c2e090a3b,0x3009333232093631\n"
".quad 0x33732e627573090a,0x2c32327225092032,0x31202c3232722520,0x752e766f6d090a3b\n"
".quad 0x3432722509203233,0x6573090a3b30202c,0x33732e71652e7074,0x202c357025092032\n"
".quad 0x7225202c32327225,0x702540090a3b3432,0x2409206172622035,0x3639385f365f744c\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c34323220656e69,0x616c206461656820,0x4c242064656c6562,0x0a303938355f365f\n"
".quad 0x3436662e64646109,0x2c31326466250920,0x202c393164662520,0x090a3b3032646625\n"
".quad 0x203436662e766f6d,0x202c323264662509,0x3030303130346430,0x3030303030303030\n"
".quad 0x34202f2f093b3030,0x6c2e70746573090a,0x2509203436662e74,0x32646625202c3670\n"
".quad 0x3232646625202c31,0x2036702540090a3b,0x5f4c240920617262,0x0a3b303938355f36\n"
".quad 0x39385f365f744c24,0x365f4c240a3a3236,0x090a3a363431365f,0x09373109636f6c2e\n"
".quad 0x6f6d090a30093132,0x2509203233732e76,0x0a3b30202c353272,0x74672e7074657309\n"
".quad 0x702509203233732e,0x2c32327225202c37,0x090a3b3532722520,0x203233732e627573\n"
".quad 0x25202c3632722509,0x327225202c313272,0x2e766f6d090a3b32,0x3272250920323373\n"
".quad 0x73090a3b30202c37,0x203233732e706c65,0x25202c3832722509,0x327225202c363272\n"
".quad 0x0a3b377025202c37,0x3233752e766f6d09,0x202c393272250920,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x7225202c38702509,0x39327225202c3832,0x2038702540090a3b\n"
".quad 0x744c240920617262,0x3b343931385f365f,0x3109636f6c2e090a,0x090a300938320937\n"
".quad 0x6d617261702e646c,0x722509203233732e,0x635f5f5b202c3033,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x7645644930316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f,0x6f6974616d696e61\n"
".quad 0x3b5d656d6172466e,0x33732e646461090a,0x2c31337225092032,0x25202c3033722520\n"
".quad 0x646c090a3b383272,0x752e6d617261702e,0x2c32337225092038,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x7536507645644930\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x6c6f635f6269695f\n"
".quad 0x0a3b5d302b73726f,0x2e6f6c2e6c756d09,0x3372250920323373,0x2c31337225202c33\n"
".quad 0x090a3b3233722520,0x752e38752e747663,0x3433722509203233,0x0a3b33337225202c\n"
".quad 0x373109636f6c2e09,0x6c090a3009393209,0x2e6d617261702e64,0x3533722509203875\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262\n"
".quad 0x3650764564493031,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x6f635f6269695f30,0x3b5d312b73726f6c,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x31337225202c3633,0x0a3b35337225202c,0x2e38752e74766309,0x3372250920323375\n"
".quad 0x3b36337225202c37,0x3109636f6c2e090a,0x090a300930330937,0x6d617261702e646c\n"
".quad 0x337225092038752e,0x75635f5f5b202c38,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x507645644930316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x635f6269695f3053,0x5d322b73726f6c6f,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x337225202c393372,0x3b38337225202c31,0x38752e747663090a\n"
".quad 0x722509203233752e,0x39337225202c3034,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x0a3b383339375f36,0x31385f365f744c24,0x6f6c2e090a3a3439,0x0934330937310963\n"
".quad 0x752e766f6d090a30,0x3034722509203233,0x6f6d090a3b30202c,0x2509203233752e76\n"
".quad 0x0a3b30202c373372,0x3233752e766f6d09,0x202c343372250920,0x365f744c240a3b30\n"
".quad 0x090a3a383339375f,0x732e6f6c2e6c756d,0x3134722509203233,0x202c31317225202c\n"
".quad 0x61090a3b30317225,0x09203233732e6464,0x7225202c32347225,0x3b387225202c3134\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x32347225202c3334,0x7663090a3b34202c\n"
".quad 0x33752e3436752e74,0x2c31647225092032,0x090a3b3334722520,0x6d617261702e646c\n"
".quad 0x722509203436752e,0x635f5f5b202c3264,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x7645644930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x5f6269695f30535f,0x61090a3b5d747364,0x09203436752e6464\n"
".quad 0x7225202c33647225,0x32647225202c3164,0x61702e646c090a3b,0x203233732e6d6172\n"
".quad 0x5b202c3434722509,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x656d6172665f6269,0x2e766f6d090a3b5d,0x3472250920323375\n"
".quad 0x73090a3b30202c35,0x732e656e2e707465,0x2c39702509203233,0x25202c3434722520\n"
".quad 0x2540090a3b353472,0x0920617262203970,0x37385f365f744c24,0x6f6c2e090a3b3630\n"
".quad 0x0931340937310963,0x752e766f6d090a30,0x3634722509203233,0x7473090a3b30202c\n"
".quad 0x2e6c61626f6c672e,0x5b092038752e3476,0x2c5d302b33647225,0x252c343372257b20\n"
".quad 0x303472252c373372,0x0a3b7d363472252c,0x696e752e61726209,0x5f365f744c240920\n"
".quad 0x4c240a3b30353438,0x363037385f365f74,0x09636f6c2e090a3a,0x0a30093534093731\n"
".quad 0x3233732e64646109,0x202c373472250920,0x3b31202c34347225,0x33732e726873090a\n"
".quad 0x2c38347225092032,0x33202c3734722520,0x2e766f6d090a3b31,0x3472250920323373\n"
".quad 0x61090a3b31202c39,0x09203233622e646e,0x7225202c30357225,0x39347225202c3834\n"
".quad 0x732e646461090a3b,0x3135722509203233,0x202c30357225202c,0x73090a3b37347225\n"
".quad 0x09203233732e7268,0x7225202c32357225,0x090a3b31202c3135,0x61626f6c672e646c\n"
".quad 0x2038752e34762e6c,0x252c333572257b09,0x353572252c343572,0x72255b202c7d5f2c\n"
".quad 0x090a3b5d302b3364,0x732e6f6c2e6c756d,0x3635722509203233,0x202c34347225202c\n"
".quad 0x61090a3b33357225,0x09203233732e6464,0x7225202c37357225,0x36357225202c3433\n"
".quad 0x732e646461090a3b,0x3835722509203233,0x202c32357225202c,0x64090a3b37357225\n"
".quad 0x09203233732e7669,0x7225202c39357225,0x37347225202c3835,0x09636f6c2e090a3b\n"
".quad 0x0a30093634093731,0x2e6f6c2e6c756d09,0x3672250920323373,0x2c34347225202c30\n"
".quad 0x090a3b3435722520,0x203233732e646461,0x25202c3136722509,0x367225202c373372\n"
".quad 0x2e646461090a3b30,0x3672250920323373,0x2c32357225202c32,0x090a3b3136722520\n"
".quad 0x203233732e766964,0x25202c3336722509,0x347225202c323672,0x672e7473090a3b37\n"
".quad 0x32762e6c61626f6c,0x72255b092038752e,0x7b202c5d302b3364,0x3672252c39357225\n"
".quad 0x6f6c2e090a3b7d33,0x0937340937310963,0x6c2e6c756d090a30,0x2509203233732e6f\n"
".quad 0x347225202c343672,0x3b35357225202c34,0x33732e646461090a,0x2c35367225092032\n"
".quad 0x25202c3034722520,0x6461090a3b343672,0x2509203233732e64,0x357225202c363672\n"
".quad 0x3b35367225202c32,0x33732e766964090a,0x2c37367225092032,0x25202c3636722520\n"
".quad 0x7473090a3b373472,0x2e6c61626f6c672e,0x6472255b09203875,0x7225202c5d322b33\n"
".quad 0x5f744c240a3b3736,0x0a3a303534385f36,0x39365f365f744c24,0x6f6c2e090a3a3431\n"
".quad 0x0930350937310963,0x3b74697865090a30,0x646e6557444c240a,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x45644930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x202f2f207d090a3a,0x646e614d36315a5f\n"
".quad 0x5f30746f72626c65,0x7645644930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x0a6269695f30535f,0x7972746e652e090a,0x6e614d36315a5f20\n"
".quad 0x31746f72626c6564,0x45664930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f\n"
".quad 0x6375365076456649,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x2c7473645f626969,0x617261702e09090a,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x664930316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x576567616d695f62\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x6567616d695f6269,0x61702e09090a2c48\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x30316d735f31746f,0x6375365076456649,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x6e7572635f626969,0x702e09090a2c6863,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664930,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x664f785f6269695f,0x61702e09090a2c66,0x3233662e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x66664f795f626969\n"
".quad 0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x0a2c504a785f6269,0x6d617261702e0909\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45664930316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6269695f30535f32,0x09090a2c504a795f,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645664930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x735f6269695f3053\n"
".quad 0x09090a2c656c6163,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645664930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x635f6269695f3053\n"
".quad 0x5d345b73726f6c6f,0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x656d6172665f6269\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x616d696e615f6269,0x6d6172466e6f6974\n"
".quad 0x61702e09090a2c65,0x2038732e206d6172,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x0a294a73695f6269,0x6765722e090a7b09\n"
".quad 0x7225203233752e20,0x090a3b3e3635313c,0x36752e206765722e,0x3e393c6472252034\n"
".quad 0x206765722e090a3b,0x3c6625203233662e,0x722e090a3b3e3432,0x646572702e206765\n"
".quad 0x3b3e35313c702520,0x3109636f6c2e090a,0x0a30093530310937,0x6967656257444c24\n"
".quad 0x614d36315a5f5f6e,0x746f72626c65646e,0x664930316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x2e766f6d090a3a62\n"
".quad 0x3172250920323375,0x646961746325202c,0x766f6d090a3b782e,0x722509203233752e\n"
".quad 0x6469746e25202c32,0x6c756d090a3b782e,0x203233752e6f6c2e,0x7225202c33722509\n"
".quad 0x0a3b327225202c31,0x3233752e766f6d09,0x25202c3472250920,0x3b792e6469617463\n"
".quad 0x33752e766f6d090a,0x202c357225092032,0x3b792e6469746e25,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x202c347225202c36,0x6f6d090a3b357225,0x2509203233752e76\n"
".quad 0x64697425202c3772,0x646461090a3b782e,0x722509203233752e,0x202c377225202c38\n"
".quad 0x6f6d090a3b337225,0x2509203233752e76,0x64697425202c3972,0x646461090a3b792e\n"
".quad 0x722509203233752e,0x2c397225202c3031,0x6c090a3b36722520,0x2e6d617261702e64\n"
".quad 0x3172250920323373,0x75635f5f5b202c31,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f31746f72626c,0x507645664930316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x695f6269695f3053,0x0a3b5d486567616d,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x5f5f5b202c323172,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x31746f72626c6564,0x45664930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x5d576567616d695f,0x672e746573090a3b\n"
".quad 0x33732e3233752e74,0x2c33317225092032,0x25202c3131722520,0x656e090a3b303172\n"
".quad 0x2509203233732e67,0x317225202c343172,0x2e746573090a3b33,0x732e3233752e7467\n"
".quad 0x3531722509203233,0x202c32317225202c,0x656e090a3b387225,0x2509203233732e67\n"
".quad 0x317225202c363172,0x2e646e61090a3b35,0x3172250920323362,0x2c34317225202c37\n"
".quad 0x090a3b3631722520,0x203233752e766f6d,0x30202c3831722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x317225202c317025,0x3b38317225202c37,0x622031702540090a\n"
".quad 0x5f744c2409206172,0x3b32343636315f37,0x3109636f6c2e090a,0x0a30093331310937\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323373,0x2c32317225202c39,0x090a3b3031722520\n"
".quad 0x203233732e646461,0x25202c3032722509,0x387225202c393172,0x61702e646c090a3b\n"
".quad 0x203436752e6d6172,0x5b202c3164722509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x3b5d7473645f6269,0x6f6c2e6c756d090a\n"
".quad 0x722509203233752e,0x30327225202c3132,0x7663090a3b34202c,0x33752e3436752e74\n"
".quad 0x2c32647225092032,0x090a3b3132722520,0x203436752e646461,0x25202c3364722509\n"
".quad 0x647225202c326472,0x672e646c090a3b31,0x34762e6c61626f6c,0x72257b092038752e\n"
".quad 0x2c333272252c3232,0x2c7d5f2c34327225,0x302b336472255b20,0x2e766f6d090a3b5d\n"
".quad 0x3272250920323375,0x73090a3b30202c35,0x732e656c2e707465,0x2c32702509203233\n"
".quad 0x7225202c38722520,0x702540090a3b3532,0x2409206172622032,0x3834315f375f744c\n"
".quad 0x2e646c090a3b3035,0x762e6c61626f6c67,0x257b092038752e34,0x373272252c363272\n"
".quad 0x7d5f2c383272252c,0x2b336472255b202c,0x6c2e090a3b5d342d,0x313109373109636f\n"
".quad 0x627573090a300938,0x722509203233732e,0x38327225202c3932,0x0a3b34327225202c\n"
".quad 0x3233732e73626109,0x202c303372250920,0x6d090a3b39327225,0x09203233732e766f\n"
".quad 0x3031202c31337225,0x672e746573090a3b,0x33732e3233752e74,0x2c32337225092032\n"
".quad 0x25202c3033722520,0x656e090a3b313372,0x2509203233732e67,0x337225202c333372\n"
".quad 0x2e627573090a3b32,0x3372250920323373,0x2c36327225202c34,0x090a3b3232722520\n"
".quad 0x203233732e736261,0x25202c3533722509,0x6f6d090a3b343372,0x2509203233732e76\n"
".quad 0x3b3031202c363372,0x74672e746573090a,0x3233732e3233752e,0x202c373372250920\n"
".quad 0x7225202c35337225,0x67656e090a3b3633,0x722509203233732e,0x37337225202c3833\n"
".quad 0x732e627573090a3b,0x3933722509203233,0x202c37327225202c,0x61090a3b33327225\n"
".quad 0x09203233732e7362,0x7225202c30347225,0x766f6d090a3b3933,0x722509203233732e\n"
".quad 0x0a3b3031202c3134,0x2e74672e74657309,0x203233732e323375,0x25202c3234722509\n"
".quad 0x347225202c303472,0x2e67656e090a3b31,0x3472250920323373,0x3b32347225202c33\n"
".quad 0x3233622e726f090a,0x202c343472250920,0x7225202c38337225,0x2e726f090a3b3334\n"
".quad 0x3472250920323362,0x2c33337225202c35,0x090a3b3434722520,0x20696e752e617262\n"
".quad 0x315f375f744c2409,0x4c240a3b34393534,0x353834315f375f74,0x2e766f6d090a3a30\n"
".quad 0x3472250920323373,0x4c240a3b30202c35,0x393534315f375f74,0x2e646461090a3a34\n"
".quad 0x3472250920323373,0x202c387225202c36,0x70746573090a3b31,0x203233732e656c2e\n"
".quad 0x7225202c33702509,0x36347225202c3231,0x2033702540090a3b,0x744c240920617262\n"
".quad 0x36303135315f375f,0x6c672e646c090a3b,0x2e34762e6c61626f,0x3472257b09203875\n"
".quad 0x252c383472252c37,0x202c7d5f2c393472,0x5d342b336472255b,0x09636f6c2e090a3b\n"
".quad 0x3009303231093731,0x33732e627573090a,0x2c30357225092032,0x25202c3934722520\n"
".quad 0x6261090a3b343272,0x2509203233732e73,0x357225202c313572,0x2e766f6d090a3b30\n"
".quad 0x3572250920323373,0x090a3b3031202c32,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c33357225,0x32357225202c3135,0x732e67656e090a3b,0x3435722509203233\n"
".quad 0x0a3b33357225202c,0x3233732e62757309,0x202c353572250920,0x7225202c37347225\n"
".quad 0x736261090a3b3232,0x722509203233732e,0x35357225202c3635,0x732e766f6d090a3b\n"
".quad 0x3735722509203233,0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32\n"
".quad 0x357225202c383572,0x3b37357225202c36,0x33732e67656e090a,0x2c39357225092032\n"
".quad 0x090a3b3835722520,0x203233732e627573,0x25202c3036722509,0x327225202c383472\n"
".quad 0x2e736261090a3b33,0x3672250920323373,0x3b30367225202c31,0x33732e766f6d090a\n"
".quad 0x2c32367225092032,0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e\n"
".quad 0x31367225202c3336,0x0a3b32367225202c,0x3233732e67656e09,0x202c343672250920\n"
".quad 0x6f090a3b33367225,0x2509203233622e72,0x357225202c353672,0x3b34367225202c39\n"
".quad 0x3233622e726f090a,0x202c363672250920,0x7225202c34357225,0x646461090a3b3536\n"
".quad 0x722509203233732e,0x35347225202c3534,0x0a3b36367225202c,0x35315f375f744c24\n"
".quad 0x6f6d090a3a363031,0x2509203233752e76,0x0a3b30202c373672,0x656c2e7074657309\n"
".quad 0x702509203233732e,0x2c30317225202c34,0x090a3b3736722520,0x6172622034702540\n"
".quad 0x5f375f744c240920,0x090a3b3831363531,0x09373109636f6c2e,0x73090a3009323231\n"
".quad 0x09203233732e6275,0x7225202c38367225,0x32317225202c3032,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x367225202c393672,0x63090a3b34202c38,0x752e3436752e7476\n"
".quad 0x3464722509203233,0x0a3b39367225202c,0x3436752e64646109,0x202c356472250920\n"
".quad 0x7225202c34647225,0x2e646c090a3b3164,0x762e6c61626f6c67,0x257b092038752e34\n"
".quad 0x313772252c303772,0x7d5f2c323772252c,0x2b356472255b202c,0x627573090a3b5d30\n"
".quad 0x722509203233732e,0x32377225202c3337,0x0a3b34327225202c,0x3233732e73626109\n"
".quad 0x202c343772250920,0x6d090a3b33377225,0x09203233732e766f,0x3031202c35377225\n"
".quad 0x672e746573090a3b,0x33732e3233752e74,0x2c36377225092032,0x25202c3437722520\n"
".quad 0x656e090a3b353772,0x2509203233732e67,0x377225202c373772,0x2e627573090a3b36\n"
".quad 0x3772250920323373,0x2c30377225202c38,0x090a3b3232722520,0x203233732e736261\n"
".quad 0x25202c3937722509,0x6f6d090a3b383772,0x2509203233732e76,0x3b3031202c303872\n"
".quad 0x74672e746573090a,0x3233732e3233752e,0x202c313872250920,0x7225202c39377225\n"
".quad 0x67656e090a3b3038,0x722509203233732e,0x31387225202c3238,0x732e627573090a3b\n"
".quad 0x3338722509203233,0x202c31377225202c,0x61090a3b33327225,0x09203233732e7362\n"
".quad 0x7225202c34387225,0x766f6d090a3b3338,0x722509203233732e,0x0a3b3031202c3538\n"
".quad 0x2e74672e74657309,0x203233732e323375,0x25202c3638722509,0x387225202c343872\n"
".quad 0x2e67656e090a3b35,0x3872250920323373,0x3b36387225202c37,0x3233622e726f090a\n"
".quad 0x202c383872250920,0x7225202c32387225,0x2e726f090a3b3738,0x3872250920323362\n"
".quad 0x2c37377225202c39,0x090a3b3838722520,0x203233732e646461,0x25202c3534722509\n"
".quad 0x387225202c353472,0x375f744c240a3b39,0x0a3a38313635315f,0x3233732e64646109\n"
".quad 0x202c303972250920,0x3b31202c30317225,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x31317225202c3570,0x0a3b30397225202c,0x7262203570254009,0x375f744c24092061\n"
".quad 0x0a3b30333136315f,0x373109636f6c2e09,0x090a300934323109,0x203233732e646461\n"
".quad 0x25202c3139722509,0x317225202c303272,0x2e6c756d090a3b32,0x09203233752e6f6c\n"
".quad 0x7225202c32397225,0x090a3b34202c3139,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x3b32397225202c36,0x36752e646461090a,0x2c37647225092034,0x25202c3664722520\n"
".quad 0x646c090a3b316472,0x2e6c61626f6c672e,0x7b092038752e3476,0x3972252c33397225\n"
".quad 0x5f2c353972252c34,0x376472255b202c7d,0x7573090a3b5d302b,0x2509203233732e62\n"
".quad 0x397225202c363972,0x3b34327225202c35,0x33732e736261090a,0x2c37397225092032\n"
".quad 0x090a3b3639722520,0x203233732e766f6d,0x31202c3839722509,0x2e746573090a3b30\n"
".quad 0x732e3233752e7467,0x3939722509203233,0x202c37397225202c,0x6e090a3b38397225\n"
".quad 0x09203233732e6765,0x25202c3030317225,0x7573090a3b393972,0x2509203233732e62\n"
".quad 0x7225202c31303172,0x32327225202c3339,0x732e736261090a3b,0x3031722509203233\n"
".quad 0x3130317225202c32,0x732e766f6d090a3b,0x3031722509203233,0x090a3b3031202c33\n"
".quad 0x752e74672e746573,0x09203233732e3233,0x25202c3430317225,0x7225202c32303172\n"
".quad 0x656e090a3b333031,0x2509203233732e67,0x7225202c35303172,0x7573090a3b343031\n"
".quad 0x2509203233732e62,0x7225202c36303172,0x33327225202c3439,0x732e736261090a3b\n"
".quad 0x3031722509203233,0x3630317225202c37,0x732e766f6d090a3b,0x3031722509203233\n"
".quad 0x090a3b3031202c38,0x752e74672e746573,0x09203233732e3233,0x25202c3930317225\n"
".quad 0x7225202c37303172,0x656e090a3b383031,0x2509203233732e67,0x7225202c30313172\n"
".quad 0x726f090a3b393031,0x722509203233622e,0x317225202c313131,0x31317225202c3530\n"
".quad 0x622e726f090a3b30,0x3131722509203233,0x3030317225202c32,0x3b3131317225202c\n"
".quad 0x33732e646461090a,0x2c35347225092032,0x25202c3534722520,0x4c240a3b32313172\n"
".quad 0x333136315f375f74,0x2e766f6d090a3a30,0x3172250920323375,0x090a3b30202c3331\n"
".quad 0x2e71652e70746573,0x3670250920323373,0x202c35347225202c,0x090a3b3331317225\n"
".quad 0x6172622036702540,0x5f375f744c240920,0x090a3b3234363631,0x09373109636f6c2e\n"
".quad 0x63090a3009313331,0x33662e6e722e7476,0x2509203233732e32,0x3b387225202c3166\n"
".quad 0x6e722e747663090a,0x3233732e3233662e,0x25202c3266250920,0x646c090a3b303172\n"
".quad 0x662e6d617261702e,0x2c33662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x6163735f6269695f,0x646c090a3b5d656c\n"
".quad 0x662e6d617261702e,0x2c34662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x664f785f6269695f,0x616d66090a3b5d66\n"
".quad 0x203233662e6e722e,0x6625202c35662509,0x202c336625202c31,0x646c090a3b346625\n"
".quad 0x662e6d617261702e,0x2c36662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x664f795f6269695f,0x616d66090a3b5d66\n"
".quad 0x203233662e6e722e,0x6625202c37662509,0x202c336625202c32,0x646c090a3b366625\n"
".quad 0x732e6d617261702e,0x3431317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493031,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x73695f6269695f30,0x766f6d090a3b5d4a\n"
".quad 0x722509203233752e,0x0a3b30202c353131,0x71652e7074657309,0x702509203233732e\n"
".quad 0x3431317225202c37,0x3b3531317225202c,0x622037702540090a,0x5f744c2409206172\n"
".quad 0x3b30313437315f37,0x3109636f6c2e090a,0x0a30093530320936,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x635f5f5b202c3866,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645664930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x5f6269695f30535f,0x2e090a3b5d504a78,0x3209363109636f6c\n"
".quad 0x646c090a30093630,0x662e6d617261702e,0x2c39662509203233,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x504a795f6269695f\n"
".quad 0x636f6c2e090a3b5d,0x0937303209363109,0x662e766f6d090a30,0x3031662509203233\n"
".quad 0x090a3b376625202c,0x09363109636f6c2e,0x6d090a3009383032,0x09203233662e766f\n"
".quad 0x6625202c31316625,0x636f6c2e090a3b35,0x0939303209363109,0x662e6c756d090a30\n"
".quad 0x3231662509203233,0x25202c376625202c,0x6f6c2e090a3b3766,0x3031320936310963\n"
".quad 0x2e6c756d090a3009,0x3166250920323366,0x202c356625202c33,0x7262090a3b356625\n"
".quad 0x240920696e752e61,0x3137315f375f744c,0x5f744c240a3b3435,0x3a30313437315f37\n"
".quad 0x3109636f6c2e090a,0x0a30093431320936,0x3233662e766f6d09,0x25202c3866250920\n"
".quad 0x6f6c2e090a3b3566,0x3531320936310963,0x2e766f6d090a3009,0x3966250920323366\n"
".quad 0x090a3b376625202c,0x09363109636f6c2e,0x6d090a3009393132,0x09203233662e766f\n"
".quad 0x6630202c33316625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3166250920323366,0x3030306630202c32,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c313166250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c303166,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x5f375f744c240a30,0x090a3a3435313731,0x09363109636f6c2e\n"
".quad 0x6c090a3009333232,0x2e6d617261702e64,0x3172250920323373,0x635f5f5b202c3631\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645664930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x3b5d68636e757263,0x33732e627573090a,0x3731317225092032,0x2c3631317225202c\n"
".quad 0x766f6d090a3b3120,0x722509203233752e,0x0a3b31202c383131,0x71652e7074657309\n"
".quad 0x702509203233732e,0x3631317225202c38,0x3b3831317225202c,0x622038702540090a\n"
".quad 0x5f744c2409206172,0x3b38373138315f37,0x33662e646461090a,0x2c34316625092032\n"
".quad 0x25202c3331662520,0x6f6d090a3b323166,0x2509203233662e76,0x346630202c353166\n"
".quad 0x3b30303030303830,0x202f2f0920202020,0x2e70746573090a34,0x09203233662e746c\n"
".quad 0x316625202c397025,0x3b35316625202c34,0x203970252140090a,0x744c240920617262\n"
".quad 0x38373138315f375f,0x315f375f4c240a3b,0x2f200a3a38353033,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3220656e696c2079,0x636f6c2e090a3432,0x0934323209363109\n"
".quad 0x662e6c756d090a30,0x3631662509203233,0x202c31316625202c,0x61090a3b30316625\n"
".quad 0x09203233662e6464,0x6625202c37316625,0x36316625202c3631,0x662e646461090a3b\n"
".quad 0x3031662509203233,0x25202c396625202c,0x6c2e090a3b373166,0x323209363109636f\n"
".quad 0x627573090a300935,0x662509203233662e,0x33316625202c3831,0x0a3b32316625202c\n"
".quad 0x3233662e64646109,0x202c313166250920,0x316625202c386625,0x636f6c2e090a3b38\n"
".quad 0x0936323209363109,0x662e6c756d090a30,0x3931662509203233,0x202c30316625202c\n"
".quad 0x6d090a3b30316625,0x09203233662e766f,0x6625202c32316625,0x6f6c2e090a3b3931\n"
".quad 0x3732320936310963,0x2e6c756d090a3009,0x3266250920323366,0x2c31316625202c30\n"
".quad 0x090a3b3131662520,0x203233662e766f6d,0x25202c3331662509,0x6c2e090a3b303266\n"
".quad 0x323209363109636f,0x627573090a300933,0x722509203233732e,0x317225202c373131\n"
".quad 0x090a3b31202c3731,0x203233752e766f6d,0x202c393131722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3031702509,0x7225202c37313172,0x2540090a3b393131\n"
".quad 0x2061726220303170,0x315f375f744c2409,0x2f200a3b38373138,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3432\n"
".quad 0x64656c6562616c20,0x33315f375f4c2420,0x646461090a383530,0x662509203233662e\n"
".quad 0x39316625202c3132,0x0a3b30326625202c,0x3233662e766f6d09,0x202c323266250920\n"
".quad 0x3030303830346630,0x09202020203b3030,0x6573090a34202f2f,0x33662e746c2e7074\n"
".quad 0x2c31317025092032,0x25202c3132662520,0x2540090a3b323266,0x2061726220313170\n"
".quad 0x33315f375f4c2409,0x744c240a3b383530,0x38373138315f375f,0x315f375f4c240a3a\n"
".quad 0x2e090a3a34313333,0x3109373109636f6c,0x6f6d090a30093133,0x2509203233732e76\n"
".quad 0x3b30202c30323172,0x672e70746573090a,0x2509203233732e74,0x317225202c323170\n"
".quad 0x32317225202c3731,0x2e627573090a3b30,0x3172250920323373,0x31317225202c3132\n"
".quad 0x3731317225202c36,0x732e766f6d090a3b,0x3231722509203233,0x73090a3b30202c32\n"
".quad 0x203233732e706c65,0x202c333231722509,0x25202c3132317225,0x7025202c32323172\n"
".quad 0x766f6d090a3b3231,0x722509203233752e,0x0a3b30202c343231,0x71652e7074657309\n"
".quad 0x702509203233732e,0x32317225202c3331,0x3432317225202c33,0x3331702540090a3b\n"
".quad 0x4c24092061726220,0x323937315f375f74,0x636f6c2e090a3b32,0x0938333109373109\n"
".quad 0x61702e646c090a30,0x203233732e6d6172,0x202c353231722509,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6d696e615f626969\n"
".quad 0x6172466e6f697461,0x6461090a3b5d656d,0x2509203233732e64,0x7225202c36323172\n"
".quad 0x317225202c353231,0x2e646c090a3b3332,0x38752e6d61726170,0x2c37323172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664930,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x6c6f635f6269695f,0x0a3b5d302b73726f,0x2e6f6c2e6c756d09,0x3172250920323373\n"
".quad 0x32317225202c3832,0x3732317225202c36,0x752e747663090a3b,0x2509203233752e38\n"
".quad 0x7225202c39323172,0x6c2e090a3b383231,0x333109373109636f,0x2e646c090a300939\n"
".quad 0x38752e6d61726170,0x2c30333172250920,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x6c6f635f6269695f,0x0a3b5d312b73726f\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323373,0x32317225202c3133,0x3033317225202c36\n"
".quad 0x752e747663090a3b,0x2509203233752e38,0x7225202c32333172,0x6c2e090a3b313331\n"
".quad 0x343109373109636f,0x2e646c090a300930,0x38752e6d61726170,0x2c33333172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664930,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x6c6f635f6269695f,0x0a3b5d322b73726f,0x2e6f6c2e6c756d09,0x3172250920323373\n"
".quad 0x32317225202c3433,0x3333317225202c36,0x752e747663090a3b,0x2509203233752e38\n"
".quad 0x7225202c35333172,0x7262090a3b343331,0x240920696e752e61,0x3637315f375f744c\n"
".quad 0x5f744c240a3b3636,0x3a32323937315f37,0x3109636f6c2e090a,0x0a30093434310937\n"
".quad 0x3233752e766f6d09,0x2c35333172250920,0x766f6d090a3b3020,0x722509203233752e\n"
".quad 0x0a3b30202c323331,0x3233752e766f6d09,0x2c39323172250920,0x5f744c240a3b3020\n"
".quad 0x3a36363637315f37,0x3109636f6c2e090a,0x0a30093035310937,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x5f5b202c36333172,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664930316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x5d656d6172665f62,0x732e646461090a3b\n"
".quad 0x3331722509203233,0x3633317225202c37,0x6873090a3b31202c,0x2509203233732e72\n"
".quad 0x7225202c38333172,0x3b3133202c373331,0x33732e766f6d090a,0x3933317225092032\n"
".quad 0x6e61090a3b31202c,0x2509203233622e64,0x7225202c30343172,0x317225202c383331\n"
".quad 0x646461090a3b3933,0x722509203233732e,0x317225202c313431,0x33317225202c3034\n"
".quad 0x2e726873090a3b37,0x3172250920323373,0x34317225202c3234,0x6d090a3b31202c31\n"
".quad 0x33732e6f6c2e6c75,0x3334317225092032,0x2c3633317225202c,0x090a3b3232722520\n"
".quad 0x203233732e646461,0x202c343431722509,0x25202c3932317225,0x61090a3b33343172\n"
".quad 0x09203233732e6464,0x25202c3534317225,0x7225202c32343172,0x6964090a3b343431\n"
".quad 0x2509203233732e76,0x7225202c36343172,0x317225202c353431,0x6f6c2e090a3b3733\n"
".quad 0x3135310937310963,0x2e6c756d090a3009,0x09203233732e6f6c,0x25202c3734317225\n"
".quad 0x7225202c36333172,0x646461090a3b3332,0x722509203233732e,0x317225202c383431\n"
".quad 0x34317225202c3233,0x2e646461090a3b37,0x3172250920323373,0x34317225202c3934\n"
".quad 0x3834317225202c32,0x732e766964090a3b,0x3531722509203233,0x3934317225202c30\n"
".quad 0x3b3733317225202c,0x6f6c672e7473090a,0x752e32762e6c6162,0x336472255b092038\n"
".quad 0x72257b202c5d302b,0x353172252c363431,0x6f6c2e090a3b7d30,0x3235310937310963\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x25202c3135317225,0x7225202c36333172\n"
".quad 0x646461090a3b3432,0x722509203233732e,0x317225202c323531,0x35317225202c3533\n"
".quad 0x2e646461090a3b31,0x3172250920323373,0x34317225202c3335,0x3235317225202c32\n"
".quad 0x732e766964090a3b,0x3531722509203233,0x3335317225202c34,0x3b3733317225202c\n"
".quad 0x6f6c672e7473090a,0x092038752e6c6162,0x5d322b336472255b,0x3b3435317225202c\n"
".quad 0x315f375f744c240a,0x4c240a3a32343636,0x383034315f375f74,0x636f6c2e090a3a32\n"
".quad 0x0935353109373109,0x3b74697865090a30,0x646e6557444c240a,0x6e614d36315a5f5f\n"
".quad 0x31746f72626c6564,0x45664930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x202f2f207d090a3a,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645664930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x0a6269695f30535f,0x7972746e652e090a,0x6e614d36315a5f20\n"
".quad 0x31746f72626c6564,0x45644930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x61702e09090a2820,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x2c7473645f626969,0x617261702e09090a,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644930316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x576567616d695f62\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x6567616d695f6269,0x61702e09090a2c48\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x30316d735f31746f,0x6375365076456449,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x6e7572635f626969,0x702e09090a2c6863,0x36662e206d617261\n"
".quad 0x616475635f5f2034,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644930,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x664f785f6269695f,0x61702e09090a2c66,0x3436662e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f,0x6375365076456449\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x66664f795f626969\n"
".quad 0x7261702e09090a2c,0x203436662e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x0a2c504a785f6269,0x6d617261702e0909\n"
".quad 0x5f5f203436662e20,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45644930316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6269695f30535f32,0x09090a2c504a795f,0x2e206d617261702e,0x75635f5f20343666\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x735f6269695f3053\n"
".quad 0x09090a2c656c6163,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x635f6269695f3053\n"
".quad 0x5d345b73726f6c6f,0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x656d6172665f6269\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x616d696e615f6269,0x6d6172466e6f6974\n"
".quad 0x61702e09090a2c65,0x2038732e206d6172,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x0a294a73695f6269,0x6765722e090a7b09\n"
".quad 0x7225203233752e20,0x090a3b3e3635313c,0x36752e206765722e,0x3e393c6472252034\n"
".quad 0x206765722e090a3b,0x646625203436662e,0x2e090a3b3e34323c,0x6572702e20676572\n"
".quad 0x3e35313c70252064,0x09636f6c2e090a3b,0x3009353031093731,0x67656257444c240a\n"
".quad 0x4d36315a5f5f6e69,0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x766f6d090a3a6269\n"
".quad 0x722509203233752e,0x6961746325202c31,0x6f6d090a3b782e64,0x2509203233752e76\n"
".quad 0x69746e25202c3272,0x756d090a3b782e64,0x3233752e6f6c2e6c,0x25202c3372250920\n"
".quad 0x3b327225202c3172,0x33752e766f6d090a,0x202c347225092032,0x792e646961746325\n"
".quad 0x752e766f6d090a3b,0x2c35722509203233,0x792e6469746e2520,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x2c347225202c3672,0x6d090a3b35722520,0x09203233752e766f\n"
".quad 0x697425202c377225,0x6461090a3b782e64,0x2509203233752e64,0x2c377225202c3872\n"
".quad 0x6d090a3b33722520,0x09203233752e766f,0x697425202c397225,0x6461090a3b792e64\n"
".quad 0x2509203233752e64,0x397225202c303172,0x090a3b367225202c,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x635f5f5b202c3131,0x5f6d726170616475,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645644930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x5f6269695f30535f,0x3b5d486567616d69,0x7261702e646c090a\n"
".quad 0x09203233732e6d61,0x5f5b202c32317225,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644930316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x576567616d695f62,0x2e746573090a3b5d\n"
".quad 0x732e3233752e7467,0x3331722509203233,0x202c31317225202c,0x6e090a3b30317225\n"
".quad 0x09203233732e6765,0x7225202c34317225,0x746573090a3b3331,0x2e3233752e74672e\n"
".quad 0x3172250920323373,0x2c32317225202c35,0x6e090a3b38722520,0x09203233732e6765\n"
".quad 0x7225202c36317225,0x646e61090a3b3531,0x722509203233622e,0x34317225202c3731\n"
".quad 0x0a3b36317225202c,0x3233752e766f6d09,0x202c383172250920,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x7225202c31702509,0x38317225202c3731,0x2031702540090a3b\n"
".quad 0x744c240920617262,0x32343636315f385f,0x09636f6c2e090a3b,0x3009333131093731\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x32317225202c3931,0x0a3b30317225202c\n"
".quad 0x3233732e64646109,0x202c303272250920,0x7225202c39317225,0x702e646c090a3b38\n"
".quad 0x3436752e6d617261,0x202c316472250920,0x70616475635f5f5b,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x30316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x5d7473645f626969,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x327225202c313272,0x63090a3b34202c30,0x752e3436752e7476\n"
".quad 0x3264722509203233,0x0a3b31327225202c,0x3436752e64646109,0x202c336472250920\n"
".quad 0x7225202c32647225,0x2e646c090a3b3164,0x762e6c61626f6c67,0x257b092038752e34\n"
".quad 0x333272252c323272,0x7d5f2c343272252c,0x2b336472255b202c,0x766f6d090a3b5d30\n"
".quad 0x722509203233752e,0x090a3b30202c3532,0x2e656c2e70746573,0x3270250920323373\n"
".quad 0x25202c387225202c,0x2540090a3b353272,0x0920617262203270,0x34315f385f744c24\n"
".quad 0x646c090a3b303538,0x2e6c61626f6c672e,0x7b092038752e3476,0x3272252c36327225\n"
".quad 0x5f2c383272252c37,0x336472255b202c7d,0x2e090a3b5d342d2b,0x3109373109636f6c\n"
".quad 0x7573090a30093831,0x2509203233732e62,0x327225202c393272,0x3b34327225202c38\n"
".quad 0x33732e736261090a,0x2c30337225092032,0x090a3b3932722520,0x203233732e766f6d\n"
".quad 0x31202c3133722509,0x2e746573090a3b30,0x732e3233752e7467,0x3233722509203233\n"
".quad 0x202c30337225202c,0x6e090a3b31337225,0x09203233732e6765,0x7225202c33337225\n"
".quad 0x627573090a3b3233,0x722509203233732e,0x36327225202c3433,0x0a3b32327225202c\n"
".quad 0x3233732e73626109,0x202c353372250920,0x6d090a3b34337225,0x09203233732e766f\n"
".quad 0x3031202c36337225,0x672e746573090a3b,0x33732e3233752e74,0x2c37337225092032\n"
".quad 0x25202c3533722520,0x656e090a3b363372,0x2509203233732e67,0x337225202c383372\n"
".quad 0x2e627573090a3b37,0x3372250920323373,0x2c37327225202c39,0x090a3b3332722520\n"
".quad 0x203233732e736261,0x25202c3034722509,0x6f6d090a3b393372,0x2509203233732e76\n"
".quad 0x3b3031202c313472,0x74672e746573090a,0x3233732e3233752e,0x202c323472250920\n"
".quad 0x7225202c30347225,0x67656e090a3b3134,0x722509203233732e,0x32347225202c3334\n"
".quad 0x33622e726f090a3b,0x2c34347225092032,0x25202c3833722520,0x726f090a3b333472\n"
".quad 0x722509203233622e,0x33337225202c3534,0x0a3b34347225202c,0x696e752e61726209\n"
".quad 0x5f385f744c240920,0x240a3b3439353431,0x3834315f385f744c,0x766f6d090a3a3035\n"
".quad 0x722509203233732e,0x240a3b30202c3534,0x3534315f385f744c,0x646461090a3a3439\n"
".quad 0x722509203233732e,0x2c387225202c3634,0x746573090a3b3120,0x3233732e656c2e70\n"
".quad 0x25202c3370250920,0x347225202c323172,0x33702540090a3b36,0x4c24092061726220\n"
".quad 0x303135315f385f74,0x672e646c090a3b36,0x34762e6c61626f6c,0x72257b092038752e\n"
".quad 0x2c383472252c3734,0x2c7d5f2c39347225,0x342b336472255b20,0x636f6c2e090a3b5d\n"
".quad 0x0930323109373109,0x732e627573090a30,0x3035722509203233,0x202c39347225202c\n"
".quad 0x61090a3b34327225,0x09203233732e7362,0x7225202c31357225,0x766f6d090a3b3035\n"
".quad 0x722509203233732e,0x0a3b3031202c3235,0x2e74672e74657309,0x203233732e323375\n"
".quad 0x25202c3335722509,0x357225202c313572,0x2e67656e090a3b32,0x3572250920323373\n"
".quad 0x3b33357225202c34,0x33732e627573090a,0x2c35357225092032,0x25202c3734722520\n"
".quad 0x6261090a3b323272,0x2509203233732e73,0x357225202c363572,0x2e766f6d090a3b35\n"
".quad 0x3572250920323373,0x090a3b3031202c37,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c38357225,0x37357225202c3635,0x732e67656e090a3b,0x3935722509203233\n"
".quad 0x0a3b38357225202c,0x3233732e62757309,0x202c303672250920,0x7225202c38347225\n"
".quad 0x736261090a3b3332,0x722509203233732e,0x30367225202c3136,0x732e766f6d090a3b\n"
".quad 0x3236722509203233,0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32\n"
".quad 0x367225202c333672,0x3b32367225202c31,0x33732e67656e090a,0x2c34367225092032\n"
".quad 0x090a3b3336722520,0x09203233622e726f,0x7225202c35367225,0x34367225202c3935\n"
".quad 0x33622e726f090a3b,0x2c36367225092032,0x25202c3435722520,0x6461090a3b353672\n"
".quad 0x2509203233732e64,0x347225202c353472,0x3b36367225202c35,0x315f385f744c240a\n"
".quad 0x6d090a3a36303135,0x09203233752e766f,0x3b30202c37367225,0x6c2e70746573090a\n"
".quad 0x2509203233732e65,0x30317225202c3470,0x0a3b37367225202c,0x7262203470254009\n"
".quad 0x385f744c24092061,0x0a3b38313635315f,0x373109636f6c2e09,0x090a300932323109\n"
".quad 0x203233732e627573,0x25202c3836722509,0x317225202c303272,0x2e6c756d090a3b32\n"
".quad 0x09203233752e6f6c,0x7225202c39367225,0x090a3b34202c3836,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x3b39367225202c34,0x36752e646461090a,0x2c35647225092034\n"
".quad 0x25202c3464722520,0x646c090a3b316472,0x2e6c61626f6c672e,0x7b092038752e3476\n"
".quad 0x3772252c30377225,0x5f2c323772252c31,0x356472255b202c7d,0x7573090a3b5d302b\n"
".quad 0x2509203233732e62,0x377225202c333772,0x3b34327225202c32,0x33732e736261090a\n"
".quad 0x2c34377225092032,0x090a3b3337722520,0x203233732e766f6d,0x31202c3537722509\n"
".quad 0x2e746573090a3b30,0x732e3233752e7467,0x3637722509203233,0x202c34377225202c\n"
".quad 0x6e090a3b35377225,0x09203233732e6765,0x7225202c37377225,0x627573090a3b3637\n"
".quad 0x722509203233732e,0x30377225202c3837,0x0a3b32327225202c,0x3233732e73626109\n"
".quad 0x202c393772250920,0x6d090a3b38377225,0x09203233732e766f,0x3031202c30387225\n"
".quad 0x672e746573090a3b,0x33732e3233752e74,0x2c31387225092032,0x25202c3937722520\n"
".quad 0x656e090a3b303872,0x2509203233732e67,0x387225202c323872,0x2e627573090a3b31\n"
".quad 0x3872250920323373,0x2c31377225202c33,0x090a3b3332722520,0x203233732e736261\n"
".quad 0x25202c3438722509,0x6f6d090a3b333872,0x2509203233732e76,0x3b3031202c353872\n"
".quad 0x74672e746573090a,0x3233732e3233752e,0x202c363872250920,0x7225202c34387225\n"
".quad 0x67656e090a3b3538,0x722509203233732e,0x36387225202c3738,0x33622e726f090a3b\n"
".quad 0x2c38387225092032,0x25202c3238722520,0x726f090a3b373872,0x722509203233622e\n"
".quad 0x37377225202c3938,0x0a3b38387225202c,0x3233732e64646109,0x202c353472250920\n"
".quad 0x7225202c35347225,0x5f744c240a3b3938,0x3a38313635315f38,0x33732e646461090a\n"
".quad 0x2c30397225092032,0x31202c3031722520,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x317225202c357025,0x3b30397225202c31,0x622035702540090a,0x5f744c2409206172\n"
".quad 0x3b30333136315f38,0x3109636f6c2e090a,0x0a30093432310937,0x3233732e64646109\n"
".quad 0x202c313972250920,0x7225202c30327225,0x6c756d090a3b3231,0x203233752e6f6c2e\n"
".quad 0x25202c3239722509,0x0a3b34202c313972,0x3436752e74766309,0x722509203233752e\n"
".quad 0x32397225202c3664,0x752e646461090a3b,0x3764722509203436,0x202c36647225202c\n"
".quad 0x6c090a3b31647225,0x6c61626f6c672e64,0x092038752e34762e,0x72252c333972257b\n"
".quad 0x2c353972252c3439,0x6472255b202c7d5f,0x73090a3b5d302b37,0x09203233732e6275\n"
".quad 0x7225202c36397225,0x34327225202c3539,0x732e736261090a3b,0x3739722509203233\n"
".quad 0x0a3b36397225202c,0x3233732e766f6d09,0x202c383972250920,0x746573090a3b3031\n"
".quad 0x2e3233752e74672e,0x3972250920323373,0x2c37397225202c39,0x090a3b3839722520\n"
".quad 0x203233732e67656e,0x202c303031722509,0x73090a3b39397225,0x09203233732e6275\n"
".quad 0x25202c3130317225,0x327225202c333972,0x2e736261090a3b32,0x3172250920323373\n"
".quad 0x30317225202c3230,0x2e766f6d090a3b31,0x3172250920323373,0x0a3b3031202c3330\n"
".quad 0x2e74672e74657309,0x203233732e323375,0x202c343031722509,0x25202c3230317225\n"
".quad 0x6e090a3b33303172,0x09203233732e6765,0x25202c3530317225,0x73090a3b34303172\n"
".quad 0x09203233732e6275,0x25202c3630317225,0x327225202c343972,0x2e736261090a3b33\n"
".quad 0x3172250920323373,0x30317225202c3730,0x2e766f6d090a3b36,0x3172250920323373\n"
".quad 0x0a3b3031202c3830,0x2e74672e74657309,0x203233732e323375,0x202c393031722509\n"
".quad 0x25202c3730317225,0x6e090a3b38303172,0x09203233732e6765,0x25202c3031317225\n"
".quad 0x6f090a3b39303172,0x2509203233622e72,0x7225202c31313172,0x317225202c353031\n"
".quad 0x2e726f090a3b3031,0x3172250920323362,0x30317225202c3231,0x3131317225202c30\n"
".quad 0x732e646461090a3b,0x3534722509203233,0x202c35347225202c,0x240a3b3231317225\n"
".quad 0x3136315f385f744c,0x766f6d090a3a3033,0x722509203233752e,0x0a3b30202c333131\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c35347225202c36,0x0a3b333131722520\n"
".quad 0x7262203670254009,0x385f744c24092061,0x0a3b32343636315f,0x373109636f6c2e09\n"
".quad 0x090a300931333109,0x6d617261702e646c,0x662509203436662e,0x635f5f5b202c3164\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645644930316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x5f6269695f30535f\n"
".quad 0x0a3b5d656c616373,0x617261702e646c09,0x2509203436662e6d,0x5f5f5b202c326466\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564,0x45644930316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6269695f30535f32\n"
".quad 0x0a3b5d66664f785f,0x2e6e722e74766309,0x203233732e343666,0x25202c3364662509\n"
".quad 0x64616d090a3b3872,0x203436662e6e722e,0x25202c3464662509,0x646625202c336466\n"
".quad 0x3b32646625202c31,0x7261702e646c090a,0x09203436662e6d61,0x5f5b202c35646625\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x644930316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x3b5d66664f795f62,0x6e722e747663090a,0x3233732e3436662e,0x202c366466250920\n"
".quad 0x6d090a3b30317225,0x36662e6e722e6461,0x2c37646625092034,0x25202c3664662520\n"
".quad 0x646625202c316466,0x702e646c090a3b35,0x2038732e6d617261,0x202c343131722509\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x5d4a73695f626969,0x752e766f6d090a3b,0x3131722509203233,0x73090a3b30202c35\n"
".quad 0x732e71652e707465,0x2c37702509203233,0x202c343131722520,0x090a3b3531317225\n"
".quad 0x6172622037702540,0x5f385f744c240920,0x090a3b3031343731,0x09363109636f6c2e\n"
".quad 0x6c090a3009353032,0x2e6d617261702e64,0x6466250920343666,0x75635f5f5b202c38\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644930316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x785f6269695f3053\n"
".quad 0x6c2e090a3b5d504a,0x303209363109636f,0x2e646c090a300936,0x36662e6d61726170\n"
".quad 0x2c39646625092034,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f31746f72,0x7536507645644930,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x504a795f6269695f,0x636f6c2e090a3b5d,0x0937303209363109\n"
".quad 0x662e766f6d090a30,0x3164662509203436,0x3b37646625202c30,0x3109636f6c2e090a\n"
".quad 0x0a30093830320936,0x3436662e766f6d09,0x2c31316466250920,0x090a3b3464662520\n"
".quad 0x09363109636f6c2e,0x6d090a3009393032,0x09203436662e6c75,0x25202c3231646625\n"
".quad 0x646625202c376466,0x636f6c2e090a3b37,0x0930313209363109,0x662e6c756d090a30\n"
".quad 0x3164662509203436,0x2c34646625202c33,0x090a3b3464662520,0x20696e752e617262\n"
".quad 0x315f385f744c2409,0x4c240a3b34353137,0x313437315f385f74,0x636f6c2e090a3a30\n"
".quad 0x0934313209363109,0x662e766f6d090a30,0x3864662509203436,0x0a3b34646625202c\n"
".quad 0x363109636f6c2e09,0x090a300935313209,0x203436662e766f6d,0x25202c3964662509\n"
".quad 0x6c2e090a3b376466,0x313209363109636f,0x766f6d090a300939,0x662509203436662e\n"
".quad 0x306430202c333164,0x3030303030303030,0x3b30303030303030,0x6d090a30202f2f09\n"
".quad 0x09203436662e766f,0x30202c3231646625,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e766f6d09,0x2c31316466250920,0x3030303030643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x662e766f6d090a30,0x3164662509203436\n"
".quad 0x3030306430202c30,0x3030303030303030,0x2f093b3030303030,0x5f744c240a30202f\n"
".quad 0x3a34353137315f38,0x3109636f6c2e090a,0x0a30093332320936,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x5f5b202c36313172,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x644930316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x68636e7572635f62,0x2e627573090a3b5d\n"
".quad 0x3172250920323373,0x31317225202c3731,0x6d090a3b31202c36,0x09203233752e766f\n"
".quad 0x31202c3831317225,0x2e70746573090a3b,0x09203233732e7165,0x317225202c387025\n"
".quad 0x31317225202c3631,0x38702540090a3b38,0x4c24092061726220,0x373138315f385f74\n"
".quad 0x2e646461090a3b38,0x6466250920343666,0x31646625202c3431,0x3231646625202c33\n"
".quad 0x662e766f6d090a3b,0x3164662509203436,0x3130346430202c35,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x746573090a34202f,0x3436662e746c2e70,0x25202c3970250920\n"
".quad 0x6625202c34316466,0x2140090a3b353164,0x2061726220397025,0x315f385f744c2409\n"
".quad 0x4c240a3b38373138,0x38353033315f385f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x090a34323220656e,0x09363109636f6c2e,0x6d090a3009343232\n"
".quad 0x09203436662e6c75,0x25202c3631646625,0x6625202c31316466,0x6461090a3b303164\n"
".quad 0x2509203436662e64,0x6625202c37316466,0x646625202c363164,0x646461090a3b3631\n"
".quad 0x662509203436662e,0x646625202c303164,0x3731646625202c39,0x09636f6c2e090a3b\n"
".quad 0x3009353232093631,0x36662e627573090a,0x3831646625092034,0x2c3331646625202c\n"
".quad 0x0a3b323164662520,0x3436662e64646109,0x2c31316466250920,0x25202c3864662520\n"
".quad 0x2e090a3b38316466,0x3209363109636f6c,0x756d090a30093632,0x2509203436662e6c\n"
".quad 0x6625202c39316466,0x646625202c303164,0x766f6d090a3b3031,0x662509203436662e\n"
".quad 0x646625202c323164,0x6f6c2e090a3b3931,0x3732320936310963,0x2e6c756d090a3009\n"
".quad 0x6466250920343666,0x31646625202c3032,0x3131646625202c31,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x3032646625202c33,0x09636f6c2e090a3b,0x3009333232093631\n"
".quad 0x33732e627573090a,0x3731317225092032,0x2c3731317225202c,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x0a3b30202c393131,0x71652e7074657309,0x702509203233732e\n"
".quad 0x31317225202c3031,0x3931317225202c37,0x3031702540090a3b,0x4c24092061726220\n"
".quad 0x373138315f385f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c34323220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x38353033315f385f,0x36662e646461090a,0x3132646625092034,0x2c3931646625202c\n"
".quad 0x0a3b303264662520,0x3436662e766f6d09,0x2c32326466250920,0x3030313034643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x2e70746573090a34,0x09203436662e746c\n"
".quad 0x6625202c31317025,0x646625202c313264,0x702540090a3b3232,0x0920617262203131\n"
".quad 0x3033315f385f4c24,0x5f744c240a3b3835,0x3a38373138315f38,0x33315f385f4c240a\n"
".quad 0x6c2e090a3a343133,0x333109373109636f,0x766f6d090a300931,0x722509203233732e\n"
".quad 0x0a3b30202c303231,0x74672e7074657309,0x702509203233732e,0x31317225202c3231\n"
".quad 0x3032317225202c37,0x732e627573090a3b,0x3231722509203233,0x3631317225202c31\n"
".quad 0x3b3731317225202c,0x33732e766f6d090a,0x3232317225092032,0x6573090a3b30202c\n"
".quad 0x09203233732e706c,0x25202c3332317225,0x7225202c31323172,0x317025202c323231\n"
".quad 0x2e766f6d090a3b32,0x3172250920323375,0x090a3b30202c3432,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x3332317225202c33,0x3b3432317225202c,0x203331702540090a\n"
".quad 0x744c240920617262,0x32323937315f385f,0x09636f6c2e090a3b,0x3009383331093731\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5b202c3532317225,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x616d696e615f6269\n"
".quad 0x6d6172466e6f6974,0x646461090a3b5d65,0x722509203233732e,0x317225202c363231\n"
".quad 0x32317225202c3532,0x702e646c090a3b33,0x2038752e6d617261,0x202c373231722509\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x6f6c6f635f626969,0x090a3b5d302b7372,0x732e6f6c2e6c756d,0x3231722509203233\n"
".quad 0x3632317225202c38,0x3b3732317225202c,0x38752e747663090a,0x722509203233752e\n"
".quad 0x317225202c393231,0x6f6c2e090a3b3832,0x3933310937310963,0x702e646c090a3009\n"
".quad 0x2038752e6d617261,0x202c303331722509,0x70616475635f5f5b,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x30316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6f6c6f635f626969,0x090a3b5d312b7372\n"
".quad 0x732e6f6c2e6c756d,0x3331722509203233,0x3632317225202c31,0x3b3033317225202c\n"
".quad 0x38752e747663090a,0x722509203233752e,0x317225202c323331,0x6f6c2e090a3b3133\n"
".quad 0x3034310937310963,0x702e646c090a3009,0x2038752e6d617261,0x202c333331722509\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x30316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x6f6c6f635f626969,0x090a3b5d322b7372,0x732e6f6c2e6c756d,0x3331722509203233\n"
".quad 0x3632317225202c34,0x3b3333317225202c,0x38752e747663090a,0x722509203233752e\n"
".quad 0x317225202c353331,0x617262090a3b3433,0x4c240920696e752e,0x363637315f385f74\n"
".quad 0x385f744c240a3b36,0x0a3a32323937315f,0x373109636f6c2e09,0x090a300934343109\n"
".quad 0x203233752e766f6d,0x202c353331722509,0x2e766f6d090a3b30,0x3172250920323375\n"
".quad 0x090a3b30202c3233,0x203233752e766f6d,0x202c393231722509,0x385f744c240a3b30\n"
".quad 0x0a3a36363637315f,0x373109636f6c2e09,0x090a300930353109,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x5f5f5b202c363331,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x31746f72626c6564,0x45644930316d735f,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6269695f30535f32,0x3b5d656d6172665f,0x33732e646461090a\n"
".quad 0x3733317225092032,0x2c3633317225202c,0x726873090a3b3120,0x722509203233732e\n"
".quad 0x317225202c383331,0x0a3b3133202c3733,0x3233732e766f6d09,0x2c39333172250920\n"
".quad 0x646e61090a3b3120,0x722509203233622e,0x317225202c303431,0x33317225202c3833\n"
".quad 0x2e646461090a3b39,0x3172250920323373,0x34317225202c3134,0x3733317225202c30\n"
".quad 0x732e726873090a3b,0x3431722509203233,0x3134317225202c32,0x756d090a3b31202c\n"
".quad 0x3233732e6f6c2e6c,0x2c33343172250920,0x202c363331722520,0x61090a3b32327225\n"
".quad 0x09203233732e6464,0x25202c3434317225,0x7225202c39323172,0x6461090a3b333431\n"
".quad 0x2509203233732e64,0x7225202c35343172,0x317225202c323431,0x766964090a3b3434\n"
".quad 0x722509203233732e,0x317225202c363431,0x33317225202c3534,0x636f6c2e090a3b37\n"
".quad 0x0931353109373109,0x6c2e6c756d090a30,0x2509203233732e6f,0x7225202c37343172\n"
".quad 0x327225202c363331,0x2e646461090a3b33,0x3172250920323373,0x33317225202c3834\n"
".quad 0x3734317225202c32,0x732e646461090a3b,0x3431722509203233,0x3234317225202c39\n"
".quad 0x3b3834317225202c,0x33732e766964090a,0x3035317225092032,0x2c3934317225202c\n"
".quad 0x0a3b373331722520,0x626f6c672e747309,0x38752e32762e6c61,0x2b336472255b0920\n"
".quad 0x3172257b202c5d30,0x30353172252c3634,0x636f6c2e090a3b7d,0x0932353109373109\n"
".quad 0x6c2e6c756d090a30,0x2509203233732e6f,0x7225202c31353172,0x327225202c363331\n"
".quad 0x2e646461090a3b34,0x3172250920323373,0x33317225202c3235,0x3135317225202c35\n"
".quad 0x732e646461090a3b,0x3531722509203233,0x3234317225202c33,0x3b3235317225202c\n"
".quad 0x33732e766964090a,0x3435317225092032,0x2c3335317225202c,0x0a3b373331722520\n"
".quad 0x626f6c672e747309,0x5b092038752e6c61,0x2c5d322b33647225,0x0a3b343531722520\n"
".quad 0x36315f385f744c24,0x744c240a3a323436,0x32383034315f385f,0x09636f6c2e090a3a\n"
".quad 0x3009353531093731,0x0a3b74697865090a,0x5f646e6557444c24,0x646e614d36315a5f\n"
".quad 0x5f31746f72626c65,0x7645644930316d73,0x3472616863753650,0x5f32535f54696969\n"
".quad 0x32535f32535f3253,0x3a6269695f30535f,0x5f202f2f207d090a,0x65646e614d36315a\n"
".quad 0x735f31746f72626c,0x507645644930316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x0a0a6269695f3053,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[10091];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_21$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000004e1c,0x0000000000000040,0x0038004000140115,0x0001001a00400007\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x00000000000006c0\n"
".quad 0x0000000000000562,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000c22\n"
".quad 0x000000000000013d,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000d5f\n"
".quad 0x0000000000000330,0x0000001c00000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x00000001000002a6,0x0000000000000006,0x0000000000000000,0x000000000000108f\n"
".quad 0x0000000000000b50,0x1900001100000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000049a,0x0000000000000002,0x0000000000000000,0x0000000000001bdf\n"
".quad 0x000000000000005d,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000045d,0x0000000000000002,0x0000000000000000,0x0000000000001c3c\n"
".quad 0x0000000000000004,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000002da,0x0000000000000002,0x0000000000000000,0x0000000000001c40\n"
".quad 0x000000000000014c,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000023b,0x0000000000000006,0x0000000000000000,0x0000000000001d8c\n"
".quad 0x0000000000000da8,0x1c00000f00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000003db,0x0000000000000002,0x0000000000000000,0x0000000000002b34\n"
".quad 0x000000000000005d,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000039e,0x0000000000000002,0x0000000000000000,0x0000000000002b91\n"
".quad 0x0000000000000004,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000026f,0x0000000000000002,0x0000000000000000,0x0000000000002b95\n"
".quad 0x000000000000014c,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000001000001bc,0x0000000000000006,0x0000000000000000,0x0000000000002ce1\n"
".quad 0x0000000000000550,0x1300000d00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000051c,0x0000000000000002,0x0000000000000000,0x0000000000003231\n"
".quad 0x0000000000000055,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001fa,0x0000000000000002,0x0000000000000000,0x0000000000003286\n"
".quad 0x0000000000000124,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000013d,0x0000000000000006,0x0000000000000000,0x00000000000033aa\n"
".quad 0x00000000000005b8,0x1300000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000417,0x0000000000000002,0x0000000000000000,0x0000000000003962\n"
".quad 0x000000000000006d,0x0000000f00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000017b,0x0000000000000002,0x0000000000000000,0x00000000000039cf\n"
".quad 0x0000000000000124,0x0000000f00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000001000000be,0x0000000000000006,0x0000000000000000,0x0000000000003af3\n"
".quad 0x0000000000000790,0x1300000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000004d6,0x0000000000000002,0x0000000000000000,0x0000000000004283\n"
".quad 0x0000000000000055,0x0000001200000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000fc,0x0000000000000002,0x0000000000000000,0x00000000000042d8\n"
".quad 0x0000000000000124,0x0000001200000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x00000000000043fc\n"
".quad 0x00000000000007f8,0x1500000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000358,0x0000000000000002,0x0000000000000000,0x0000000000004bf4\n"
".quad 0x000000000000006d,0x0000001500000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000311,0x0000000000000002,0x0000000000000000,0x0000000000004c61\n"
".quad 0x0000000000000004,0x0000001500000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000074,0x0000000000000002,0x0000000000000000,0x0000000000004c65\n"
".quad 0x0000000000000124,0x0000001500000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000001000000b5,0x0000000000000002,0x0000000000000000,0x0000000000004d89\n"
".quad 0x0000000000000090,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x36315a5f2e747865\n"
".quad 0x72626c65646e614d,0x30316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x2e766e2e00626969,0x315a5f2e6f666e69\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645644930,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x766e2e006269695f,0x742e006f666e692e\n"
".quad 0x36315a5f2e747865,0x72626c65646e614d,0x30316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x2e766e2e00626969\n"
".quad 0x315a5f2e6f666e69,0x626c65646e614d36,0x316d735f31746f72,0x7536507645664930\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x65742e006269695f\n"
".quad 0x4d36315a5f2e7478,0x6f72626c65646e61,0x4930316d735f3074,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x692e766e2e006269\n"
".quad 0x36315a5f2e6f666e,0x72626c65646e614d,0x30316d735f30746f,0x6375365076456449\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x7865742e00626969\n"
".quad 0x614d36315a5f2e74,0x746f72626c65646e,0x664930316d735f30,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x6e692e766e2e0062\n"
".quad 0x4d36315a5f2e6f66,0x6f72626c65646e61,0x4930316d735f3074,0x6863753650764566\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x747865742e006269\n"
".quad 0x6e614d38315a5f2e,0x44746f72626c6564,0x5030316d735f3153,0x6934726168637536\n"
".quad 0x6666666666666969,0x2e006269695f5366,0x2e6f666e692e766e,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365030316d735f31,0x6969347261686375,0x6666666666666669\n"
".quad 0x742e006269695f53,0x38315a5f2e747865,0x72626c65646e614d,0x6d735f305344746f\n"
".quad 0x6168637536503031,0x6666666969693472,0x69695f5366666666,0x6e692e766e2e0062\n"
".quad 0x4d38315a5f2e6f66,0x6f72626c65646e61,0x316d735f30534474,0x7261686375365030\n"
".quad 0x6666666669696934,0x6269695f53666666,0x6e6f632e766e2e00,0x2e3631746e617473\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645644930316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x006269695f30535f,0x736e6f632e766e2e\n"
".quad 0x5a5f2e30746e6174,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493031\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x6e2e006269695f30\n"
".quad 0x6174736e6f632e76,0x315a5f2e3631746e,0x626c65646e614d38,0x735f315344746f72\n"
".quad 0x686375365030316d,0x6666696969347261,0x695f536666666666,0x632e766e2e006269\n"
".quad 0x30746e6174736e6f,0x6e614d38315a5f2e,0x44746f72626c6564,0x5030316d735f3153\n"
".quad 0x6934726168637536,0x6666666666666969,0x2e006269695f5366,0x74736e6f632e766e\n"
".quad 0x315a5f2e30746e61,0x626c65646e614d36,0x316d735f30746f72,0x7536507645644930\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x766e2e006269695f\n"
".quad 0x6e6174736e6f632e,0x38315a5f2e363174,0x72626c65646e614d,0x6d735f305344746f\n"
".quad 0x6168637536503031,0x6666666969693472,0x69695f5366666666,0x6f632e766e2e0062\n"
".quad 0x2e30746e6174736e,0x646e614d38315a5f,0x5344746f72626c65,0x365030316d735f30\n"
".quad 0x6969347261686375,0x6666666666666669,0x6e2e006269695f53,0x6174736e6f632e76\n"
".quad 0x36315a5f2e30746e,0x72626c65646e614d,0x30316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x2e766e2e00626969\n"
".quad 0x746e6174736e6f63,0x614d36315a5f2e30,0x746f72626c65646e,0x664930316d735f30\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x4d36315a5f000062,0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x4d36315a5f006269\n"
".quad 0x6f72626c65646e61,0x4930316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x4d36315a5f006269,0x6f72626c65646e61\n"
".quad 0x4930316d735f3074,0x6863753650764564,0x5f54696969347261,0x32535f32535f3253\n"
".quad 0x695f30535f32535f,0x4d36315a5f006269,0x6f72626c65646e61,0x4930316d735f3074\n"
".quad 0x6863753650764566,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x4d38315a5f006269,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365030\n"
".quad 0x6666666669696934,0x6269695f53666666,0x6e614d38315a5f00,0x44746f72626c6564\n"
".quad 0x5030316d735f3053,0x6934726168637536,0x6666666666666969,0x00006269695f5366\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000010003000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000020003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000030003000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000003000000,0x0000000000000000,0x0000000000000000,0x0000000003000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000150003000000,0xf800000000000000\n"
".quad 0x0000000000000007,0x0000180003000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000190003000000,0x0000000000000000,0x0000000000000000,0x0000120003000000\n"
".quad 0x9000000000000000,0x0000000000000007,0x0000140003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000f0003000000,0xb800000000000000,0x0000000000000005\n"
".quad 0x0000110003000000,0x0000000000000000,0x0000000000000000,0x00000c0003000000\n"
".quad 0x5000000000000000,0x0000000000000005,0x00000e0003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000080003000000,0xa800000000000000,0x000000000000000d\n"
".quad 0x00000b0003000000,0x0000000000000000,0x0000000000000000,0x0000040003000000\n"
".quad 0x5000000000000000,0x000000000000000b,0x0000070003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000170003000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000160003000000,0x0000000000000000,0x0000000000000000,0x00000a0003000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000090003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000100003000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000060003000000,0x0000000000000000,0x0000000000000000,0x0000050003000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000130003000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000d0003000000,0x0000000000000000,0x0100000000000000\n"
".quad 0x0000151012000000,0xf800000000000000,0x3900000000000007,0x0000121012000000\n"
".quad 0x9000000000000000,0x7100000000000007,0x00000f1012000000,0xb800000000000000\n"
".quad 0xa900000000000005,0x00000c1012000000,0x5000000000000000,0xe100000000000005\n"
".quad 0x0000081012000000,0xa800000000000000,0x0f0000000000000d,0x0000041012000001\n"
".quad 0x5000000000000000,0xe40000000000000b,0x042800440400005d,0x042c00000094001c\n"
".quad 0x032c0000008400dc,0x042006400020039c,0x232c00000098009c,0x04188e4000a0e1dc\n"
".quad 0x032c00000088011c,0x23200840003023dc,0xe718804000b0f1dc,0x0480000000000021\n"
".quad 0xe41800000039201e,0x04280040013000dd,0x00180000003d215e,0x0030068000d0009c\n"
".quad 0x0030068000f0519c,0x00300440013000de,0x00300c40013051de,0x0050004000d0311e\n"
".quad 0x0050004000f0721e,0x00500000000c20dd,0x00500000001c61dd,0x003006400130001d\n"
".quad 0x00300e40013050dd,0x005000000000401c,0x26500000000c80dc,0x001400000173f25c\n"
".quad 0x8450004000e0001c,0x001c0000002421de,0x005000400100311c,0x235000000000215c\n"
".quad 0x00190e0000fc71dc,0x00500000001060dc,0x005000000008509d,0x00500000001831dd\n"
".quad 0x005000000008019d,0xe7500000001c411d,0x0040000005e00081,0x0030064000043021\n"
".quad 0x00300a40000451e1,0x00580000001030a0,0x0058000000185260,0x0030004000043221\n"
".quad 0x00300e40000452a1,0x00300400001032e0,0x0058000000208320,0x0030120000185460\n"
".quad 0x005800000028a360,0x00301600000c3020,0x0050000000203261,0x00301800000c3322\n"
".quad 0x00302200001450a0,0x00500000002851e1,0x00301a0000145422,0x0030180000248320\n"
".quad 0x00300000000c3362,0x00300400001454a2,0x00302000001ca4e0,0x0030180000248220\n"
".quad 0x0050000000340421,0x005000000034b2e1,0x0050000000482361,0x00302600001ca320\n"
".quad 0x00302000000c32a1,0x0050000000491461,0x0030100000249220,0x00301a0000145361\n"
".quad 0x005000000028b260,0x00301800001c72a0,0x00500000003512e0,0x00500000002481e0\n"
".quad 0x00500000002ca220,0x00300e0000104260,0x00301000001862e0,0x00500000002404e0\n"
".quad 0x00500000002c24a0,0x00500000000132a1,0xe450000000092321,0xe428004001100021\n"
".quad 0xe4280040012000a1,0xe428000000fc01e1,0x0028000000fc0221,0x0050000000289421\n"
".quad 0xe75000000030b461,0xe4400000018000a1,0xe428000000140001,0xe428000000180201\n"
".quad 0xe4280000000c0081,0xe4280000001001c1,0xe428000000fc0441,0xe428000000fc0481\n"
".quad 0xe428000000fc0401,0xe428000000fc04c1,0xe428000000fc0181,0xe428000000fc0141\n"
".quad 0xe428000000fc0101,0xe428000000fc00c1,0x0728004000c0025d,0x2360000012600000\n"
".quad 0x03190ec0000491dc,0xf44800fffffc925c,0x0040000000000001,0x00500000004d229c\n"
".quad 0x005000000048a2dd,0x00500000002ca31d,0x00500000002d32dd,0x005000000031231d\n"
".quad 0x005000000030b2dc,0x005000000044b2dc,0x005000000040b2dc,0x00500000002ca31c\n"
".quad 0x005000000028c29d,0x005000000028b29d,0x005000000028c29c,0xf4208ed02000a1dc\n"
".quad 0x0040000000000021,0x00300a400004529d,0x00300640000432dd,0x003014400004529d\n"
".quad 0x07301640000432dd,0x006800000f800000,0x005000000028531d,0x00500000002c335d\n"
".quad 0x00580000000c651c,0x00580000002ca59c,0x003028000010555c,0x00302c00000c55de\n"
".quad 0x00302a00000c551c,0x00302e000034a29c,0x00302800000c559e,0x003014000030b2dc\n"
".quad 0x00500000005945dd,0x005000000059529d,0x03302e00000c50dd,0x004800fffffc925c\n"
".quad 0x003016000034c15c,0x00500000000ca0dc,0x23500000001430dc,0x00190e0000fc91dc\n"
".quad 0x003006000010615c,0x00500000004d211d,0x005000000015419c,0x00500000001860dc\n"
".quad 0x005000000048429d,0x00500000001832dd,0x005000000028435d,0x00500000004ca4dc\n"
".quad 0x00500000002c331d,0x005000000050629d,0x005000000035235d,0x00500000002c62dd\n"
".quad 0x005000000030631d,0x00500000004cd35d,0x005000000028519d,0x005000000030b15c\n"
".quad 0x005000000044d2dc,0x005000000018529c,0x005000000040b15d,0x005000000018a2dc\n"
".quad 0x005000000014445c,0x00500000002c331c,0x005000000001129c,0x005000000008c19c\n"
".quad 0x005000000044a49d,0x005000000030635d,0x005000000011151d,0x005000000048a4dd\n"
".quad 0x005000000034641d,0x005000000048049d,0x00500000000cc0dd,0x005000000034211d\n"
".quad 0x00500000004d145d,0x005000000050535d,0x005000000040c31d,0x00500000000cb0dd\n"
".quad 0x005000000049115c,0x005000000030411c,0x005000000034515c,0x00500000000c40dc\n"
".quad 0x00500000001482dc,0x00500000001c311c,0x00500000002ca15c,0x00500000001060dc\n"
".quad 0x005000000028531d,0x00300a400004541d,0x005000000018329d,0x005000000030b19d\n"
".quad 0x005000000028411d,0x003006400004331d,0x00580000001032dc,0x005800000018535c\n"
".quad 0x003020400004529d,0x003016000010361c,0x00301a000018549c,0x00301840000432dd\n"
".quad 0x005800000028a35c,0x005000000028531d,0x003024000014545c,0x00580000002cb4dc\n"
".quad 0x00303000000c341c,0x00301a000014551e,0x003022000014555e,0x00302600000c359e\n"
".quad 0x00302000000c35de,0x003028000030a4dc,0x00500000002c335d,0x005000000055251d\n"
".quad 0x00500000005d049d,0x005000000055155d,0x00500000005d85dd,0x00302c000034b59c\n"
".quad 0x00302400000c361d,0x00302a000014555d,0x003026000030a49c,0x00302c000034b4dc\n"
".quad 0x005000000055459c,0x003024000030c55c,0x005000000061751c,0x003026000034d49c\n"
".quad 0x00500000005954dc,0x005000000051249c,0x003026000018659c,0x003024000010455c\n"
".quad 0x005000000059149c,0x00500000005504dc,0x005000000049351c,0x005000000045245d\n"
".quad 0x005000000049461d,0x005000000045645d,0x00500000006145dd,0x005000000041341d\n"
".quad 0x005000000061361d,0x00500000005d25dd,0x005000000041541d,0x00500000005d859c\n"
".quad 0x005000000059155c,0x005000000055055c,0x005000000055459c,0x005000000051651d\n"
".quad 0xe75000000051551d,0x00a8000000000001,0x005000000059451c,0xe7208ed0200141dc\n"
".quad 0xe7a8000000000021,0xf44003fff0c0001d,0x034000000000001d,0x2348004000c0901e\n"
".quad 0x2332120000fc001c,0xe7190e0000fc01dc,0x0340000001c00081,0x0648004001600020\n"
".quad 0x041400000143f0a0,0x061c0000000820a0,0x041400000147f0e0,0x061c0000000c20e0\n"
".quad 0xa3140000014bf120,0xa3500000000800a0,0x04500000000c00e0,0xa31c000000102120\n"
".quad 0x0450000000100020,0x041c000000082260,0x041c0000000c2220,0xe71c0000000021e0\n"
".quad 0xe4400000006000a1,0xe428000000fc01c1,0xe428000000fc0201,0xa328000000fc0241\n"
".quad 0xe4201c4000a0f01c,0x232800400080009d,0x031a8e400153f1dc,0x432005c00010009c\n"
".quad 0xe74800400093f0dc,0x0440000000c00001,0x031c00000025001c,0x032800c02020801c\n"
".quad 0x032800c02040701c,0x852800c02063f01c,0xe79400000000201c,0xe44000000a60001d\n"
".quad 0x852800400150001d,0x03840000000022dc,0xc44800c00004001c,0xc41c00000001211e\n"
".quad 0xc41c00000001215e,0x231c00000001219e,0x045800c0007c029c,0x041804000011231c\n"
".quad 0x041804000015235c,0x001804000019239c,0x03c800000010c31c,0x006800c00004a29c\n"
".quad 0x00c800000010d35c,0x02c800000010e3dc,0x03083ffffff8c31c,0x024800000000a29c\n"
".quad 0x02083ffffff8d41c,0x04083ffffff8f45c,0x231486000031235c,0x045800c00004a31c\n"
".quad 0x031486000041229c,0x045000000034441c,0x041c0000002c239c,0xa31c8000002c23dc\n"
".quad 0x042012400150e39c,0xa31d0000002c22dc,0x042010400150f3dc,0x031486000045225c\n"
".quad 0x034800000038c21c,0x845000000028545c,0x031c00000041239f,0xa35000000024649c\n"
".quad 0x43200e400150b41c,0x03201a000038d35c,0xc4480000003cc1dc,0x841c0000002122de\n"
".quad 0x031c0000004523df,0x844800000040c31c,0xc41c00000049245f,0x431c0000001d241e\n"
".quad 0x43201400003ca39c,0x432012000044925c,0xc4500000002cd29c,0x431c0000003123de\n"
".quad 0x035000000040e35c,0x43201600002842de,0x03500000003c925c,0x03198e00002c41dc\n"
".quad 0x032020000034539e,0x03201e00002463de,0x034800000010b2c1,0x034800c00004a280\n"
".quad 0x03198e00003853dc,0x83198e00003c67dc,0x036800000000821c,0x031b0e000010b1dc\n"
".quad 0x034800000014e385,0x034800c00004d344,0x234800000018f3cd,0x031b0e0000fc83dc\n"
".quad 0x834800c00004a280,0x03680000000071dc,0x031b0e000014e5dc,0x834800c00004924c\n"
".quad 0x036800000000c11c,0x841b0e000018f7dc,0x231c0000002922a7,0x031b0e0000fc71dc\n"
".quad 0xc34800c00004d348,0x236800000003f15d,0x031b0e0000fc43dc,0xc34800c00004924c\n"
".quad 0x846800000003f19d,0x231c000000352363,0x843100000028511c,0xc31c000000252267\n"
".quad 0x236800000003f1dd,0x043100000034615c,0x231c00000011011c,0x033100000024719c\n"
".quad 0x052808c02020501c,0x459400000008219c,0xe79400000000201c,0x008000000000001d\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x4600040000000000\n"
".quad 0x00000000003c0c04,0x0000000c00000008,0x0000001400000010,0x0000001c00000018\n"
".quad 0x0000002400000020,0x0000002c00000028,0x0000003400000030,0x0000003c00000038\n"
".quad 0x0000001900080a04,0x003d1903003d0020,0xffffffff000c1704,0x0005f000003c000e\n"
".quad 0xffffffff000c1704,0x0011f0000038000d,0xffffffff000c1704,0x0011f0000034000c\n"
".quad 0xffffffff000c1704,0x0011f0000030000b,0xffffffff000c1704,0x0011f000002c000a\n"
".quad 0xffffffff000c1704,0x0011f00000280009,0xffffffff000c1704,0x0011f00000240008\n"
".quad 0xffffffff000c1704,0x0011f00000200007,0xffffffff000c1704,0x0011f000001c0006\n"
".quad 0xffffffff000c1704,0x0011f00000180005,0xffffffff000c1704,0x0011f00000140004\n"
".quad 0xffffffff000c1704,0x0011f00000100003,0xffffffff000c1704,0x0011f000000c0002\n"
".quad 0xffffffff000c1704,0x0011f00000080001,0xffffffff000c1704,0x0021f00000000000\n"
".quad 0x0022019800080d04,0x00005de400000020,0x94001c0428004404,0x8400dc042c000000\n"
".quad 0x20011c032c000000,0x98009c0420064000,0xa041dc232c000000,0x88015c04188e4000\n"
".quad 0x30215c032c000000,0xb051dc23200a4000,0x000021e718804000,0xa0519ca380000000\n"
".quad 0x80001de420084000,0x10609c0328004000,0xfc41dc232001c000,0x93f0dc43198e0000\n"
".quad 0x0021dc8548004000,0x1c201c0484000000,0x1c255c041c000000,0x1c259c041c800000\n"
".quad 0xe00081e71d000000,0xf021e08540000001,0x1c22600487ffffff,0x1c2220041c800000\n"
".quad 0x549261031c000000,0x1c21e00448000000,0x008221031d000000,0x252262c448000000\n"
".quad 0x212222c41c000000,0x5871e1031c000000,0x2893e02348000000,0x1d21e2c41a0ec000\n"
".quad 0x2883e0231c000000,0x2873e0231a22c000,0x07f1e0041a22c000,0x00001de42012c000\n"
".quad 0x04421c0340000000,0xfc01c1e44800c000,0xa081dc2328000000,0xe00081e71b0e4000\n"
".quad 0x1022208540000001,0x2022a00484000000,0x202260041c800000,0x54a2a1031c000000\n"
".quad 0x2022200448000000,0x009261031d000000,0x2922a2c448000000,0x588221031c000000\n"
".quad 0x252262c448000000,0x28a3e0231c000000,0x212222c41a0ec000,0x2893e0231c000000\n"
".quad 0x2883e0231a22c000,0x07f220041a22c000,0x2071e0032012c000,0xfc51dc2348000000\n"
".quad 0x600081e7198e0000,0xa062210340000002,0x800261e448004000,0x1082200328004000\n"
".quad 0x93f260432013c000,0x0082208548004000,0x2022a00484000000,0x202260041c800000\n"
".quad 0x54a2a1031c000000,0x2022200448000000,0x009261031d000000,0x2922a2c448000000\n"
".quad 0x252262c41c000000,0x588221031c000000,0x28a3e02348000000,0x212222c41a0ec000\n"
".quad 0x2893e0231c000000,0x2883e0231a22c000,0x07f220041a22c000,0x2071e0032012c000\n"
".quad 0x04521c0348000000,0xb081dc234800c000,0x600081e71b0e4000,0xa061a00340000002\n"
".quad 0x800221e448004000,0x1062200328004000,0x93f260432011c000,0x0081a08548004000\n"
".quad 0x1822600484000000,0x182220041c800000,0x549261031c000000,0x1821a00448000000\n"
".quad 0x008221031d000000,0x252262c448000000,0x5861a1031c000000,0x212222c448000000\n"
".quad 0x2893e0231c000000,0x1921a2c41a0ec000,0x2883e0231c000000,0x2863e0231a22c000\n"
".quad 0x07f1a0041a22c000,0x1871e0032012c000,0xfc71dc2348000000,0x000001e7190e0000\n"
".quad 0x11211e0480000000,0x30019de418000000,0x15221e0428004001,0x73f31c2618000000\n"
".quad 0xd0415c0014000001,0xf0825c00300c8000,0x30419e00300c8000,0x30829e00300a4001\n"
".quad 0xd061de0030124001,0xf0a2de0050004000,0x18519d0050004000,0x28929d0050000000\n"
".quad 0x30411d0050000000,0x30819d00300c4001,0x10711c0030144001,0x18b19c0050000000\n"
".quad 0xe0411c0050000000,0x30229e8450004000,0x0061dc001c000000,0x10521c0050004001\n"
".quad 0x1c919c0050000000,0xfca1dc2350000000,0x14815d00190e0000,0x24629d0050000000\n"
".quad 0x14425d0050000000,0x2871dd0050000000,0xe00081e750000000,0x0461210040000005\n"
".quad 0x0482a100300c4000,0x1c61600030104000,0x2483200058000000,0x0462e10058000000\n"
".quad 0x0483610030084000,0x1c63a00030144000,0x2483e000300a0000,0x2cb4200030180000\n"
".quad 0x34d4600058000000,0x1861200058000000,0x2c632100301c0000,0x2081600050000000\n"
".quad 0x18642200301e0000,0x3482a10030200000,0x2084a20050000000,0x1864620030220000\n"
".quad 0x30b4200030080000,0x2084e20030200000,0x28d52000300a0000,0x4444a10030240000\n"
".quad 0x44e3a10050000000,0x30b2e00050000000,0x4c54610030200000,0x28d4200050000000\n"
".quad 0x4cf3e10030280000,0x1863610050000000,0x2084610030240000,0x30c2e00030220000\n"
".quad 0x34e3200030160000,0x28a3600050000000,0x44f3a00030200000,0x30b2a00050000000\n"
".quad 0xfc03e1e450000000,0x38d3200028000000,0x1c72e00050000000,0x2494200030140000\n"
".quad 0x2c42a00030180000,0x4053200050000000,0x10a3610050000000,0x14c4610050000000\n"
".quad 0x34b2e10050000000,0x100121e450000000,0x200161e428004001,0xfc03a1e428004001\n"
".quad 0x4503610028000000,0xa000a1e750000000,0x200101e440000001,0x2403c1e428000000\n"
".quad 0x180141e428000000,0x1c0381e428000000,0xfc0341e428000000,0xfc0301e428000000\n"
".quad 0xfc02c1e428000000,0xfc0281e428000000,0xfc0241e428000000,0xfc0201e428000000\n"
".quad 0xfc01c1e428000000,0xfc0181e428000000,0x00001de428000000,0xc0041de440000000\n"
".quad 0x6000000728004000,0x0501dc2360000012,0xfd05dc03190ec000,0x000001f44800ffff\n"
".quad 0x28c41c0040000000,0x31045d0050000000,0x45049d0050000000,0x44a45d0050000000\n"
".quad 0x48c49d0050000000,0x49145c0050000000,0x35145c0050000000,0x2d145c0050000000\n"
".quad 0x45049c0050000000,0x41241d0050000000,0x41141d0050000000,0x41241c0050000000\n"
".quad 0x0101dc0050000000,0x000021f4208ed020,0x04841d0040000000,0x04645d0030104000\n"
".quad 0x04841d00300c4000,0x04645d0030204000,0x8000000730224000,0x40849d006800000f\n"
".quad 0x4464dd0050000000,0x18951c0050000000,0x45065c0058000000,0x1c861c0058000000\n"
".quad 0x18869e0030280000,0x18851c0030320000,0x4d069c0030300000,0x18865e0030340000\n"
".quad 0x49169c0030280000,0x65441d0030340000,0x65845d0050000000,0x18819d0050000000\n"
".quad 0xfd75dc0330200000,0x4d221c004800ffff,0x19119c0030340000,0x20619c0050000000\n"
".quad 0xfd71dc2350000000,0x1c921c00190e0000,0x28c1dd00300c0000,0x21425c0050000000\n"
".quad 0x24919c0050000000,0x30749d0050000000,0x24641d0050000000,0x4874dd0050000000\n"
".quad 0x40645d0050000000,0x29249c0050000000,0x4cc4dd0050000000,0x50929d0050000000\n"
".quad 0x40931d0050000000,0x44941d0050000000,0x49345d0050000000,0x28825d0050000000\n"
".quad 0x40c21c0050000000,0x35131c0050000000,0x24829c0050000000,0x2cc21d0050000000\n"
".quad 0x24a2dc0050000000,0x20745c0050000000,0x2c631c0050000000,0x11129c0050000000\n"
".quad 0x14c25c0050000000,0x44a49d0050000000,0x30935d0050000000,0x1d151d0050000000\n"
".quad 0x48a4dd0050000000,0x34941d0050000000,0x48449d0050000000,0x18c19d0050000000\n"
".quad 0x3451dd0050000000,0x4d145d0050000000,0x50835d0050000000,0x40c31d0050000000\n"
".quad 0x18b19d0050000000,0x49121c0050000000,0x3071dc0050000000,0x34821c0050000000\n"
".quad 0x18719c0050000000,0x20f2dc0050000000,0x3861dc0050000000,0x2ca21c0050000000\n"
".quad 0x1c919c0050000000,0x28831d0050000000,0x04835d0050000000,0x24629d0030104000\n"
".quad 0x04841d0050000000,0x30b25d00301a4000,0x2871dd0050000000,0x0462dd0050000000\n"
".quad 0x24831c00300c4000,0x1c629c0058000000,0x24831c0058000000,0x04645d0030180000\n"
".quad 0x4104dc0030164000,0x1c669c0058000000,0x20835c0030140000,0x45129c0030180000\n"
".quad 0x20851e0058000000,0x1862dc0030260000,0x20865e0030340000,0x40849d00301a0000\n"
".quad 0x4464dd0050000000,0x18629e0050000000,0x1866de0030140000,0x64c61d0030160000\n"
".quad 0x49051c0050000000,0x64d65d0030280000,0x6cb31d0050000000,0x4d129c0050000000\n"
".quad 0x6da69d0030140000,0x49051c0050000000,0x20865d0030280000,0x18631d0030320000\n"
".quad 0x4d129c0030180000,0x65861c0030140000,0x49251c0050000000,0x31a31c0030280000\n"
".quad 0x4d329c0050000000,0x61451c0030140000,0x30a29c0050000000,0x24965c0050000000\n"
".quad 0x1c761c0030280000,0x64d31c0030140000,0x60b29c0050000000,0x30a51c0050000000\n"
".quad 0x34c35d0050000000,0x3146dd0050000000,0x35935d0050000000,0x6d469d0050000000\n"
".quad 0x2ca2dd0050000000,0x6ca6dd0050000000,0x68c69d0050000000,0x2d82dd0050000000\n"
".quad 0x69b65c0050000000,0x64d61c0050000000,0x60b61c0050000000,0x61465c0050000000\n"
".quad 0x51951d0050000000,0x51851d0050000000,0x000001e750000000,0x65451c00a8000000\n"
".quad 0x0141dc0050000000,0x000021e7208ed020,0xc0001de7a8000000,0x00001df44003fff0\n"
".quad 0xc1711e0340000000,0xfc411c2348004000,0xfc41dc23322e0000,0xc00081e7190e0000\n"
".quad 0x6041200340000001,0x43f1600648004001,0x1421600414000001,0x47f1a0061c000000\n"
".quad 0x4bf1e00614000001,0x1821a00414000001,0x1c21e0041c000000,0x144160a31c000000\n"
".quad 0x1841a0a350000000,0x1c4120a350000000,0x1422e00450000000,0x182260041c000000\n"
".quad 0x102220041c000000,0x8000a1e71c000000,0xfc0201e440000000,0xfc0241e428000000\n"
".quad 0xfc02c1e428000000,0x00001de428000000,0x50011de440000000,0x50001ca328004001\n"
".quad 0x04411c0320164001,0x11215ec44800c000,0x11219ec41c000000,0x1121dec41c000000\n"
".quad 0x7c429c231c000000,0x15231c045800c000,0x19235c0418040000,0x1d23dc0418040000\n"
".quad 0x10c31c0018040000,0x04a29c03c8000000,0x10d39c006800c000,0x10f3dc00c8000000\n"
".quad 0xf8c35c02c8000000,0x10a31c03083fffff,0xf8e39c0248000000,0x35229c04083fffff\n"
".quad 0xf8f3dc0214860000,0x04c35c23083fffff,0x3d22dc045800c000,0x39231c0414860000\n"
".quad 0x5153dca314860000,0x28539c0320124001,0x51645ca350000000,0x00d01c0320104001\n"
".quad 0x30641c0348000000,0x39225f8450000000,0x3cd21c031c000000,0x2c749c0348000000\n"
".quad 0x01239ec450000000,0x4123df841c000000,0x24a25c431c000000,0x44d45c0320140000\n"
".quad 0x49241f8448000000,0x21235ec41c000000,0x38925c431c000000,0x3cc29c4350000000\n"
".quad 0x40b2dc4320180000,0x4523dec420160000,0x24531e031c000000,0x34a29c43201c0000\n"
".quad 0x3051dc0350000000,0x3cb2dc43198e0000,0x28635e0350000000,0x14c30103201a0000\n"
".quad 0x2c739e0348000000,0x3463dc03201e0000,0x04924003198e0000,0x10001c834800c000\n"
".quad 0x3877dc0368000000,0x14c1dc03198e0000,0x18d345031b0e0000,0x04a2840348000000\n"
".quad 0x10821c834800c000,0x1ce38d0368000000,0xfc03dc2348000000,0x049240031b0e0000\n"
".quad 0x18d5dc034800c000,0x04b2cc031b0e0000,0x11115c834800c000,0x1ce7dc0368000000\n"
".quad 0xfc81dc231b0e0000,0x252267841b0e0000,0x04a288031c000000,0x13f01dc34800c000\n"
".quad 0xfc53dc2368000000,0x04b2cc031b0e0000,0x13f19dc34800c000,0x2922a38468000000\n"
".quad 0x24001c231c000000,0x2d22e78431080000,0x13f1ddc31c000000,0x28615c2368000000\n"
".quad 0x01001c0431080000,0x2c711c231c000000,0x20501c0331080000,0x08211c052800c020\n"
".quad 0x00201c4594000000,0x00001de794000000,0x0000000080000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x3c0c044600040000,0x0000080000000000\n"
".quad 0x0000100000000c00,0x0000180000001400,0x0000200000001c00,0x0000280000002400\n"
".quad 0x0000300000002c00,0x0000380000003400,0x080a040000003c00,0x3d00200000001600\n"
".quad 0x0c1704003d190300,0x3c000effffffff00,0x0c17040005f00000,0x38000dffffffff00\n"
".quad 0x0c17040011f00000,0x34000cffffffff00,0x0c17040011f00000,0x30000bffffffff00\n"
".quad 0x0c17040011f00000,0x2c000affffffff00,0x0c17040011f00000,0x280009ffffffff00\n"
".quad 0x0c17040011f00000,0x240008ffffffff00,0x0c17040011f00000,0x200007ffffffff00\n"
".quad 0x0c17040011f00000,0x1c0006ffffffff00,0x0c17040011f00000,0x180005ffffffff00\n"
".quad 0x0c17040011f00000,0x140004ffffffff00,0x0c17040011f00000,0x100003ffffffff00\n"
".quad 0x0c17040011f00000,0x0c0002ffffffff00,0x0c17040011f00000,0x080001ffffffff00\n"
".quad 0x0c17040011f00000,0x000000ffffffff00,0x080d040021f00000,0x0000200022019800\n"
".quad 0x00440400005de400,0x00000094001c0428,0x0000008400dc042c,0x06400020001c032c\n"
".quad 0x00000098009c0420,0x8e4000a001dc232c,0x00000088011c0418,0x08400030209c032c\n"
".quad 0x804000b021dc2320,0x000000000021e718,0x00000009211e0480,0x00000153f0dc2618\n"
".quad 0x0040011001dde414,0x0000000c215e8428,0x0000000120de041c,0x0e0000fc51dc2318\n"
".quad 0x0e8000e0415c0019,0x0e8000d0319c0030,0x000000a00081e730,0x004000f000e1e440\n"
".quad 0x0000001451e00028,0x004001000121e458,0x0000001862200028,0x000000c000a1e758\n"
".quad 0x0000001800c1e440,0x000000140101e428,0x000000fc0201e428,0x000000fc01c1e428\n"
".quad 0x000000fc0181e428,0x000000fc0141e428,0x004000c0025de428,0x0ec0000491dc2328\n"
".quad 0x00fffffc925c0319,0x000002400001e748,0x0000001c829c0040,0x0000020000000750\n"
".quad 0x8ed02000a1dc0068,0x000000000021e720,0x00000014615c00a8,0x00fffffc925c0358\n"
".quad 0x0000001c819d0048,0x00000014515c0050,0x0e0000fc91dc2350,0x00000018319c0019\n"
".quad 0x00000014415c0050,0x00000018621c0050,0x0000001451dc0058,0x000000000001e758\n"
".quad 0x00000020729c00a8,0x8ed02000a1dc0050,0x000000000021e720,0x03fffe40001de7a8\n"
".quad 0x004000c090de0340,0x120000fc30dc2348,0x0e0000fc31dc2332,0x000001c00081e719\n"
".quad 0x00000123f1200640,0x0000001021200414,0x00000127f160061c,0x0000001421600414\n"
".quad 0x0000012bf1a0061c,0x0040014030e00314,0x0000001821a00448,0x000000103120a31c\n"
".quad 0x000000143160a350,0x0000001022a00450,0x0000001830e0a31c,0x0000001423600450\n"
".quad 0x0000000c2320041c,0x0000008000a1e71c,0x000000fc0301e440,0x000000fc0341e428\n"
".quad 0x000000fc0281e428,0x00000000001de428,0x004000a0201ca340,0x00400080009de420\n"
".quad 0x8e400133f1dc2328,0x05c00010009c031a,0x00400093f0dc4320,0x000000c00001e748\n"
".quad 0x00000029001c0440,0x00c02020d01c031c,0x00c02040c01c0328,0x00c02063f01c0328\n"
".quad 0x00000000201c8528,0x00000a60001de794,0x00400130001de440,0x0000000022dc8528\n"
".quad 0x00c00004001c0384,0x00000001215ec448,0x0000000121dec41c,0x00000001225ec41c\n"
".quad 0x04000015219c041c,0x0400001d221c0418,0x00c0007c011c2318,0x04000025239c0458\n"
".quad 0x00000010619c0018,0x00000010821c00c8,0x00000010e3dc00c8,0x00c00004411c03c8\n"
".quad 0x3ffffff8619c0268,0x3ffffff8821c0208,0x3ffffff8f41c0208,0x00000000411c0308\n"
".quad 0x86000019219c0448,0x86000021221c0414,0x00c00004411c2314,0x0000002c239c0458\n"
".quad 0x8000002c23dc041c,0x14400130e39ca31c,0x86000041229c0420,0x0000002c22dc0414\n"
".quad 0x00000018541c031d,0x1a400130f45ca350,0x00000020735c0320,0x0000003843dc0350\n"
".quad 0x00000041241f8448,0x18400130b49ca31c,0x00000035235f8420,0x00000028939c031c\n"
".quad 0x0000003d231ec450,0x0000004442dc031c,0x0c000040641c4348,0x00000039239f8420\n"
".quad 0x00000048419c031c,0x10000034835c4348,0x0000002d211ec420,0x00000031021c431c\n"
".quad 0x00000019241ec450,0x14000038a29c431c,0x18000020531e0320,0x00000010d35c4320\n"
".quad 0x00000040a29c4350,0x8e00003051dc0350,0x08000034739e0319,0x20000028941e0320\n"
".quad 0x00000014c3010320,0x00c0000482000348,0x8e00003873dc0348,0x8e00004097dc0319\n"
".quad 0x00000000f11c8319,0x0e000014c1dc0368,0x0000001ce385031b,0x00c00004d3440348\n"
".quad 0x00000025040d0348,0x0e0000fc43dc2348,0x00c000048200031b,0x00000000b2dc8348\n"
".quad 0x0e00001ce5dc0368,0x00c00004a28c031b,0x00000000615c8348,0x0e00002507dc0368\n"
".quad 0x000000212227841b,0x0e0000fcb1dc231c,0x00c00004d348031b,0x00000003f11dc348\n"
".quad 0x0e0000fc53dc2368,0x00c00004a28c031b,0x00000003f19dc348,0x0000003523638468\n"
".quad 0x00000020411c231c,0x0000002922a78431,0x00000003f1ddc31c,0x00000034615c2368\n"
".quad 0x00000011011c0431,0x00000028719c231c,0x08c02020501c0331,0x00000008219c0528\n"
".quad 0x00000000201c4594,0x00000000001de794,0x0000000000000080,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0c04000000000000,0x0008000000000034,0x00100000000c0000,0x0018000000140000\n"
".quad 0x00200000001c0000,0x0028000000240000,0x00300000002c0000,0x0a04000000340000\n"
".quad 0x00200000001b0008,0x1704003519030035,0x000cffffffff000c,0x17040005f0000034\n"
".quad 0x000bffffffff000c,0x17040011f0000030,0x000affffffff000c,0x17040011f000002c\n"
".quad 0x0009ffffffff000c,0x17040011f0000028,0x0008ffffffff000c,0x17040011f0000024\n"
".quad 0x0007ffffffff000c,0x17040011f0000020,0x0006ffffffff000c,0x17040011f000001c\n"
".quad 0x0005ffffffff000c,0x17040011f0000018,0x0004ffffffff000c,0x17040011f0000014\n"
".quad 0x0003ffffffff000c,0x17040011f0000010,0x0002ffffffff000c,0x17040011f000000c\n"
".quad 0x0001ffffffff000c,0x17040011f0000008,0x0000ffffffff000c,0x0d040021f0000000\n"
".quad 0x00200021018c0008,0x440400005de40000,0x000094001c042800,0x00008400dc042c00\n"
".quad 0x400020041c032c00,0x000098009c042006,0x4000a101dc232c00,0x000088011c04188e\n"
".quad 0x400030245c032c00,0x4000b111dc232008,0x0000000021e71880,0x000041321e048000\n"
".quad 0x0001b3f01c261800,0x000045309e041400,0x000163f11c861800,0x000000201e841400\n"
".quad 0x000173f15c861c00,0x0000fc01dc231400,0x0000e3f29c86190e,0x0000f3f2dc861400\n"
".quad 0x000010829c011400,0x000103f19c862014,0x000113f1dc861400,0x000010221c011400\n"
".quad 0x0000e00081e7200c,0x4001200121e44000,0x4001300161e42800,0x40014001a1e42800\n"
".quad 0x00002080a0012800,0x000028a320015000,0x40015001e1e45000,0x00018000a1e72800\n"
".quad 0x0000280101e44000,0x00002c0141e42800,0x0000200181e42800,0x00002401c1e42800\n"
".quad 0x0000fc0301e42800,0x0000fc0341e42800,0x0000fc0081e42800,0x0000fc00c1e42800\n"
".quad 0x0000fc0281e42800,0x0000fc02c1e42800,0x0000fc0201e42800,0x0000fc0241e42800\n"
".quad 0x4000c0001de42800,0xc0000401dc232800,0xfffffc001c03190e,0x0002400001e74800\n"
".quad 0x000008c39c014000,0xd00400e1dc014800,0x0001e0000007188e,0x0000000021e76800\n"
".quad 0x000020a21c01a800,0xfffffc001c035000,0x000008c29d014800,0x0000fc01dc234800\n"
".quad 0x000020809c01190e,0x000028429c014800,0x000008621c014800,0x000028a31c014800\n"
".quad 0x000020809c015000,0x0000000001e75000,0x000030239c01a800,0xd00400e1dc014800\n"
".quad 0x0000000021e7188e,0xfffe40001de7a800,0x4000c0009e034003,0x0000fc201c234800\n"
".quad 0x0000fc01dc233200,0x0001c00081e7190e,0x4001a00020034000,0x000183f0a0064800\n"
".quad 0x000187f0e0061400,0x00000820a0041400,0x00018bf120061c00,0x00000c20e0041400\n"
".quad 0x00000800a0a31c00,0x0000102120045000,0x00000c00e0a31c00,0x0000100020a35000\n"
".quad 0x00000822e0045000,0x00000c2360041c00,0x0000002020041c00,0x00008000a1e71c00\n"
".quad 0x0000fc0001e44000,0x0000fc0341e42800,0x0000fc02c1e42800,0x000000001de42800\n"
".quad 0x4000a1109ca34000,0x40008000dde42020,0x400193f1dc232800,0xc00010209c031a8e\n"
".quad 0x400093f0dc432007,0x0000c00001e74800,0x00002d011c044000,0xc02020d11c031c00\n"
".quad 0xc02040001c032808,0xc02063f01c032808,0x000000201c852800,0x000a60001de79400\n"
".quad 0x400190011de44000,0x000000231c852800,0xc00004411c038400,0x000011219ec44800\n"
".quad 0x000011221ec41c00,0x000011229ec41c00,0x00001921dc041c00,0x000021225c041804\n"
".quad 0xc0007c415c231804,0x000029239c045800,0x00001071dc001804,0x000010925c00c800\n"
".quad 0x000010e3dc00c800,0xc00004515c03c800,0xfffff871dc026800,0xfffff8925c02083f\n"
".quad 0xfffff8f41c02083f,0x000010515c03083f,0x00001d21dc044800,0x000025225c041486\n"
".quad 0xc00004515c231486,0x000030239c045800,0x00003023dc041c00,0x400190e39ca31c80\n"
".quad 0x400190f45ca32016,0x00004122dc04201a,0x000030231c041486,0x00001c641c031d00\n"
".quad 0x000024835c035000,0x00003853dc035000,0x000041241f844800,0x400190c49ca31c00\n"
".quad 0x000035235f842000,0x00002ca39c031c00,0x000044501c035000,0x00003d231ec44800\n"
".quad 0x000040741c431c00,0x00004851dc03200e,0x000034935c434800,0x000039239f842012\n"
".quad 0x000001215ec41c00,0x000031025c431c00,0x000038b2dc435000,0x00001d241ec42016\n"
".quad 0x000014d35c431c00,0x000024631e035000,0x000040b2dc432018,0x000034839e035000\n"
".quad 0x00003061dc03200a,0x00002ca41e03198e,0x000018c301032020,0x00003883dc034800\n"
".quad 0xc00004924003198e,0x000010f15c834800,0x000040a7dc036800,0x000018c1dc03198e\n"
".quad 0x000020e385031b0e,0xc00004d344034800,0x000010001c834800,0x000029040d036800\n"
".quad 0x0000fc53dc234800,0xc000049240031b0e,0x000020e5dc034800,0xc00004b2cc031b0e\n"
".quad 0x0000fc01dc234800,0x000010719c831b0e,0x00002907dc036800,0x0000252267841b0e\n"
".quad 0xc00004d348031c00,0x000013f01dc34800,0x0000fc63dc236800,0xc00004b2cc031b0e\n"
".quad 0x0000352363844800,0x000013f15dc31c00,0x000024001c236800,0x00002d22e7843108\n"
".quad 0x000013f19dc31c00,0x000034515c236800,0x000001001c043108,0x00002c611c231c00\n"
".quad 0xc02020501c033108,0x000008211c052800,0x000000201c459400,0x000000001de79400\n"
".quad 0x0000000000008000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0400000000000000,0x080000000000340c,0x100000000c000000\n"
".quad 0x2000000018000000,0x3000000028000000,0x4000000038000000,0x4800000044000000\n"
".quad 0x040000004c000000,0x200000001700080a,0x04004d1903004d00,0x0cffffffff000c17\n"
".quad 0x040005f000004c00,0x0bffffffff000c17,0x040011f000004800,0x0affffffff000c17\n"
".quad 0x040011f000004400,0x09ffffffff000c17,0x040011f000004000,0x08ffffffff000c17\n"
".quad 0x040021f000003800,0x07ffffffff000c17,0x040021f000003000,0x06ffffffff000c17\n"
".quad 0x040021f000002800,0x05ffffffff000c17,0x040021f000002000,0x04ffffffff000c17\n"
".quad 0x040021f000001800,0x03ffffffff000c17,0x040011f000001000,0x02ffffffff000c17\n"
".quad 0x040011f000000c00,0x01ffffffff000c17,0x040011f000000800,0x00ffffffff000c17\n"
".quad 0x040021f000000000,0x200021018c00080d,0x0400005de4000000,0x0094001c04280044\n"
".quad 0x008400dc042c0000,0x002001dc032c0000,0x0098009c04200640,0x00a071dc232c0000\n"
".quad 0x0088011c04188e40,0x0030221c032c0000,0x00b081dc23200840,0x00000021e7188040\n"
".quad 0x00a0825ca3800000,0x0080001de4200e40,0x0010909c03280040,0x00fc71dc232001c0\n"
".quad 0x0093f0dc43198e00,0x0000211c85480040,0x0010219c04840000,0x0010201c041c0000\n"
".quad 0x0010239c041c8000,0x01e00081e71d0000,0xfff0212085400000,0x001022a00487ffff\n"
".quad 0x00102160041c8000,0x0000a2a1031c0000,0x0010212004480000,0x00185161031d0000\n"
".quad 0x002922a2c4480000,0x00152162c41c0000,0x00384121031c0000,0x0028a3e023480000\n"
".quad 0x00112122c41a0ec0,0x002853e0231c0000,0x002843e0231a22c0,0x0007f2a0041a22c0\n"
".quad 0x0000001de42012c0,0x0004711c03400000,0x00fc0281e44800c0,0x00a041dc23280000\n"
".quad 0x01e00081e71b0e40,0x0010212085400000,0x001022e004840000,0x00102160041c8000\n"
".quad 0x0000b2e1031c0000,0x0010212004480000,0x00185161031d0000,0x002d22e2c4480000\n"
".quad 0x00384121031c0000,0x00152162c4480000,0x0028b3e0231c0000,0x00112122c41a0ec0\n"
".quad 0x002853e0231c0000,0x002843e0231a22c0,0x0007f120041a22c0,0x0010a2a0032012c0\n"
".quad 0x00fc81dc23480000,0x02600081e7198e00,0x00a0912103400000,0x00800161e4480040\n"
".quad 0x0010412003280040,0x0093f16043200bc0,0x0000412085480040,0x001022e004840000\n"
".quad 0x00102160041c8000,0x0000b2e1031c0000,0x0010212004480000,0x00185161031d0000\n"
".quad 0x002d22e2c4480000,0x00152162c41c0000,0x00384121031c0000,0x0028b3e023480000\n"
".quad 0x00112122c41a0ec0,0x002853e0231c0000,0x002843e0231a22c0,0x0007f120041a22c0\n"
".quad 0x0010a2a0032012c0,0x0004811c03480000,0x00b041dc234800c0,0x02600081e71b0e40\n"
".quad 0x00a0912003400000,0x00800161e4480040,0x0010412003280040,0x0093f16043200bc0\n"
".quad 0x0000412085480040,0x0010226004840000,0x00102160041c8000,0x00009261031c0000\n"
".quad 0x0010212004480000,0x00185161031d0000,0x00252262c4480000,0x00384121031c0000\n"
".quad 0x00152162c4480000,0x002893e0231c0000,0x00112122c41a0ec0,0x002853e0231c0000\n"
".quad 0x002843e0231a22c0,0x0007f120041a22c0,0x0010a2a0032012c0,0x00fca1dc23480000\n"
".quad 0x00000001e7190e00,0x0021215e04800000,0x0153f11c26180000,0x0010225e84140000\n"
".quad 0x001d211e041c0000,0x00fc91dc23180000,0x011001dde4190e00,0x00d0421c00280040\n"
".quad 0x00e051dc00300e80,0x00a00081e7300e80,0x00f00121e4400000,0x001c726000280040\n"
".quad 0x01000161e4580000,0x002082a000280040,0x00c000a1e7580000,0x00200101e4400000\n"
".quad 0x001c0141e4280000,0x00fc0281e4280000,0x00fc0241e4280000,0x00fc0201e4280000\n"
".quad 0x00fc01c1e4280000,0x00c002dde4280000,0x0004b1dc23280040,0xfffcb2dc03190ec0\n"
".quad 0x02400001e74800ff,0x0024a31c00400000,0x0200000007500000,0x2000c1dc00680000\n"
".quad 0x00000021e7208ed0,0x001c81dc00a80000,0x0024a21d00580000,0xfffcb2dc03500000\n"
".quad 0x001c71dc004800ff,0x00fcb1dc23500000,0x0020421c00190e00,0x001c51dc00500000\n"
".quad 0x0020829c00500000,0x001c725c00580000,0x00000001e7580000,0x0028931c00a80000\n"
".quad 0x2000c1dc00500000,0x00000021e7208ed0,0xfe40001de7a80000,0x00c0b11e034003ff\n"
".quad 0x00fc411c23480040,0x00fc41dc23321600,0x01c00081e7190e00,0x0123f16006400000\n"
".quad 0x0014216004140000,0x0127f1e0061c0000,0x001c21e004140000,0x012bf220061c0000\n"
".quad 0x0140412003140000,0x0020226004480040,0x00144160a31c0000,0x001c4220a3500000\n"
".quad 0x00244120a3500000,0x001421e004500000,0x00202160041c0000,0x001023e0041c0000\n"
".quad 0x006000a1e71c0000,0x00fc03c1e4400000,0x00fc0141e4280000,0x00fc01c1e4280000\n"
".quad 0x0130011de4280000,0x013061dca3280040,0x0004411c03200e40,0x0130e49ca34800c0\n"
".quad 0x0011229ec4201e40,0x0011221ec41c0000,0x0011225ec41c0000,0x002922dc041c0000\n"
".quad 0x0021241c04180400,0x007c431c23180400,0x0010b35c005800c0,0x0025245c04c80000\n"
".quad 0x001102dc00180400,0x0004c31c03c80000,0x0011145c006800c0,0xfff8d35c02c80000\n"
".quad 0xfff8b41c02083fff,0x0010c31c03083fff,0x0035235c04480000,0xfff912dc02148600\n"
".quad 0x0041219c04083fff,0x0004c31c23148600,0x0130045ca35800c0,0x0034a41c03200a40\n"
".quad 0x0018801c03500000,0x002d22dc04500000,0x001cc15c03148600,0x0041241f84480000\n"
".quad 0x0001201f841c0000,0x002c91dc031c0000,0x0044c3dc03500000,0x0015239ec4480000\n"
".quad 0x0040d35c431c0000,0x0048c31c03201a00,0x001d241f84480000,0x0000619c431c0000\n"
".quad 0x003d21dec4200c00,0x0038d01c431c0000,0x0031245ec4500000,0x0040b41c431c0000\n"
".quad 0x0000a35e03201600,0x001c62dc43201c00,0x0045019c43500000,0x0034a1dc03500000\n"
".quad 0x002c81de03198e00,0x0018941e03200e00,0x0028d34103202200,0x0004000003480000\n"
".quad 0x001c83dc034800c0,0x004097dc03198e00,0x0010515c83198e00,0x0028d1dc03680000\n"
".quad 0x002071c5031b0e00,0x0004b2c403480000,0x0025040d034800c0,0x00fc53dc23480000\n"
".quad 0x00040000031b0e00,0x0010f39c834800c0,0x002075dc03680000,0x0004618c031b0e00\n"
".quad 0x0010c29c834800c0,0x002507dc03680000,0x00012027841b0e00,0x00fce1dc231c0000\n"
".quad 0x0004b2c8031b0e00,0x0013f15dc34800c0,0x00fca3dc23680000,0x0004618c031b0e00\n"
".quad 0x0013f1ddc34800c0,0x002d22e384680000,0x0000501c231c0000,0x001921a784310800\n"
".quad 0x0013f21dc31c0000,0x002c715c23680000,0x0001001c04310800,0x0018811c231c0000\n"
".quad 0x2020501c03310800,0x0008211c052800c0,0x0000201c45940000,0x0000001de7940000\n"
".quad 0x0000000000800000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000340c04\n"
".quad 0x0000000c00000008,0x0000001400000010,0x0000001c00000018,0x0000002400000020\n"
".quad 0x0000002c00000028,0x0000003400000030,0x0000001a00080a04,0x0035190300350020\n"
".quad 0xffffffff000c1704,0x0005f0000034000c,0xffffffff000c1704,0x0011f0000030000b\n"
".quad 0xffffffff000c1704,0x0011f000002c000a,0xffffffff000c1704,0x0011f00000280009\n"
".quad 0xffffffff000c1704,0x0011f00000240008,0xffffffff000c1704,0x0011f00000200007\n"
".quad 0xffffffff000c1704,0x0011f000001c0006,0xffffffff000c1704,0x0011f00000180005\n"
".quad 0xffffffff000c1704,0x0011f00000140004,0xffffffff000c1704,0x0011f00000100003\n"
".quad 0xffffffff000c1704,0x0011f000000c0002,0xffffffff000c1704,0x0011f00000080001\n"
".quad 0xffffffff000c1704,0x0021f00000000000,0x0021018c00080d04,0x00005de400000020\n"
".quad 0x94001c0428004404,0x84009c042c000000,0x20009c032c000000,0x9800dc0420044000\n"
".quad 0xa021dc232c000000,0x88011c04188e4000,0x3030dc032c000000,0xb031dc2320084000\n"
".quad 0x000021e718804000,0xa0311ca380000000,0x80001de420044000,0x10439c0328004000\n"
".quad 0xfc21dc232001c000,0x93f3dc43198e0000,0x00e15c8548004000,0x14201c0484000000\n"
".quad 0x1424dc041c000000,0x14251c041c800000,0xe00081e71d000000,0xf0e1608540000001\n"
".quad 0x1421e00487ffffff,0x1421a0041c800000,0x4c71e1031c000000,0x1421600448000000\n"
".quad 0x0061a1031d000000,0x1d21e2c448000000,0x1921a2c41c000000,0x505161031c000000\n"
".quad 0x2873e02348000000,0x152162c41a0ec000,0x2863e0231c000000,0x2853e0231a22c000\n"
".quad 0x07f160041a22c000,0x00001de42012c000,0x04219c0340000000,0xfc0141e44800c000\n"
".quad 0xa061dc2328000000,0xe00081e71b0e4000,0x10e1a08540000001,0x1822200484000000\n"
".quad 0x1821e0041c800000,0x4c8221031c000000,0x1821a00448000000,0x0071e1031d000000\n"
".quad 0x212222c448000000,0x5061a1031c000000,0x1d21e2c448000000,0x2883e0231c000000\n"
".quad 0x1921a2c41a0ec000,0x2873e0231c000000,0x2863e0231a22c000,0x07f1a0041a22c000\n"
".quad 0x185160032012c000,0xfc31dc2348000000,0x600081e7198e0000,0xa041a10340000002\n"
".quad 0x8001e1e448004000,0x1061a00328004000,0x93f1e043200fc000,0x0061a08548004000\n"
".quad 0x1822200484000000,0x1821e0041c800000,0x4c8221031c000000,0x1821a00448000000\n"
".quad 0x0071e1031d000000,0x212222c448000000,0x1d21e2c41c000000,0x5061a1031c000000\n"
".quad 0x2883e02348000000,0x1921a2c41a0ec000,0x2873e0231c000000,0x2863e0231a22c000\n"
".quad 0x07f1a0041a22c000,0x185160032012c000,0x04319c0348000000,0xb061dc234800c000\n"
".quad 0x600081e71b0e4000,0xa041200340000002,0x8001a1e448004000,0x1041a00328004000\n"
".quad 0x93f1e043200dc000,0x0061208548004000,0x1021e00484000000,0x1021a0041c800000\n"
".quad 0x4c71e1031c000000,0x1021200448000000,0x0061a1031d000000,0x1d21e2c448000000\n"
".quad 0x504121031c000000,0x1921a2c448000000,0x2873e0231c000000,0x112122c41a0ec000\n"
".quad 0x2863e0231c000000,0x2843e0231a22c000,0x07f120041a22c000,0x105160032012c000\n"
".quad 0xfc51dc2348000000,0x000001e7190e0000,0xb3f21c2680000000,0x20231e8414000001\n"
".quad 0x63f11c861c000000,0x09321e0414000001,0x73f15c8618000000,0x0d309e0414000001\n"
".quad 0xe3f29c8618000000,0xfcc1dc2314000000,0xf3f2dc86190e0000,0x10829c0114000000\n"
".quad 0x03f19c8620140000,0x13f1dc8614000001,0x10221c0114000001,0xe00081e7200c0000\n"
".quad 0x200121e440000000,0x300161e428004001,0x4001a1e428004001,0x2080a00128004001\n"
".quad 0x28a3200150000000,0x5001e1e450000000,0x8000a1e728004001,0x280101e440000001\n"
".quad 0x2c0141e428000000,0x200181e428000000,0x2401c1e428000000,0xfc0301e428000000\n"
".quad 0xfc0341e428000000,0xfc0081e428000000,0xfc00c1e428000000,0xfc0281e428000000\n"
".quad 0xfc02c1e428000000,0xfc0201e428000000,0xfc0241e428000000,0xc0041de428000000\n"
".quad 0x0501dc2328004000,0xfd049c03190ec000,0x400001e74800ffff,0x08c41c0140000002\n"
".quad 0x0000000748000000,0x0101dc0168000002,0x000021e7188ed004,0x20a21c01a8000000\n"
".quad 0xfd249c0350000000,0x08c29d014800ffff,0xfd21dc2348000000,0x20809c01190e0000\n"
".quad 0x28429c0148000000,0x08621c0148000000,0x28a31c0148000000,0x20809c0150000000\n"
".quad 0x000001e750000000,0x30241c01a8000000,0x0101dc0148000000,0x000021e7188ed004\n"
".quad 0x40001de7a8000000,0xc1209e034003fffe,0xfc209c2348004000,0xfc21dc2332240000\n"
".quad 0xc00081e7190e0000,0xa020a00340000001,0x83f0e00648004001,0x0c20e00414000001\n"
".quad 0x87f120061c000000,0x1021200414000001,0x8bf160061c000000,0x0c20e0a314000001\n"
".quad 0x102120a350000000,0x1421600450000000,0x0c21e0041c000000,0x1420a0a31c000000\n"
".quad 0x1022200450000000,0x082260041c000000,0x6000a1e71c000000,0xfc0241e440000000\n"
".quad 0xfc0201e428000000,0xfc01c1e428000000,0x90009de428000000,0x04209c0328004001\n"
".quad 0x91341ca34800c000,0x09211ec420104001,0x09215ec41c000000,0x0920dec41c000000\n"
".quad 0x11229c041c000000,0x1522dc0418040000,0x7c219c2318040000,0x10a29c005800c000\n"
".quad 0x0d235c04c8000000,0x10b31c0018040000,0x04619c03c8000000,0xf8a2dc026800c000\n"
".quad 0x10d35c00083fffff,0x08629c03c8000000,0xf8c31c0248000000,0x2d219c04083fffff\n"
".quad 0xf8d35c0214860000,0x9002dca3083fffff,0x04a29c23200e4001,0x31201c045800c000\n"
".quad 0x91449ca314860000,0x18431c0320124001,0x3521dc0450000000,0x00545c0314860000\n"
".quad 0x2ca21c0350000000,0x31231f8448000000,0x40a25c031c000000,0x1c335c0348000000\n"
".quad 0x45241f8450000000,0x2122dec41c000000,0x30631c431c000000,0x48a19c03200c0000\n"
".quad 0x35235f8448000000,0x40041c431c000000,0x25229ec420000000,0x2cc01c431c000000\n"
".quad 0x19245ec450000000,0x3471dc431c000000,0x29031c43200e0000,0x0042de0350000000\n"
".quad 0x4471dc4320160000,0x30529e0350000000,0x2c41dc0320140000,0x1c335e03198e0000\n"
".quad 0x10b2c10320220000,0x2853dc0348000000,0x04000003198e0000,0x08821c834800c000\n"
".quad 0x3437dc0368000000,0x10b1dc03198e0000,0x14a285031b0e0000,0x04c3040348000000\n"
".quad 0x0cd34d034800c000,0xfc83dc2348000000,0x040000031b0e0000,0x08925c834800c000\n"
".quad 0x14a5dc0368000000,0x0471cc031b0e0000,0x08611c834800c000,0x0cd7dc0368000000\n"
".quad 0x012027841b0e0000,0xfc91dc231c000000,0x04c308031b0e0000,0x0bf0ddc34800c000\n"
".quad 0xfc43dc2368000000,0x0471cc031b0e0000,0x0bf15dc34800c000,0x3123238468000000\n"
".quad 0x00301c231c000000,0x1d21e78431040000,0x0bf11dc31c000000,0x3050dc2368000000\n"
".quad 0x01001c0431040000,0x1c409c231c000000,0x20301c0331040000,0x08e09c052800c020\n"
".quad 0x00e01c4594000000,0x00001de794000000,0x0000000080000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x340c040000000100,0x0000080000000000,0x0000100000000c00,0x0000200000001800\n"
".quad 0x0000300000002800,0x0000400000003800,0x0000480000004400,0x080a040000004c00\n"
".quad 0x4d00200000001400,0x0c1704004d190300,0x4c000cffffffff00,0x0c17040005f00000\n"
".quad 0x48000bffffffff00,0x0c17040011f00000,0x44000affffffff00,0x0c17040011f00000\n"
".quad 0x400009ffffffff00,0x0c17040011f00000,0x380008ffffffff00,0x0c17040021f00000\n"
".quad 0x300007ffffffff00,0x0c17040021f00000,0x280006ffffffff00,0x0c17040021f00000\n"
".quad 0x200005ffffffff00,0x0c17040021f00000,0x180004ffffffff00,0x0c17040021f00000\n"
".quad 0x100003ffffffff00,0x0c17040011f00000,0x0c0002ffffffff00,0x0c17040011f00000\n"
".quad 0x080001ffffffff00,0x0c17040011f00000,0x000000ffffffff00,0x080d040021f00000\n"
".quad 0x0000200021018c00,0x0000210008120400,0x0811040000000000,0x0000000000002100\n"
".quad 0x0000200008120400,0x0811040000000000,0x0000000000002000,0x00001f0008120400\n"
".quad 0x0811040000000000,0x0000000000001f00,0x00001e0008120400,0x0811040000000000\n"
".quad 0x0000000000001e00,0x00001d0008120400,0x0811040000000000,0x0000000000001d00\n"
".quad 0x00001c0008120400,0x0811040000000000,0x0000000000001c00,0x0000000600000000\n"
".quad 0x00004e1c00000005,0x0000000000000000,0x0000000000000000,0x0000018800000000\n"
".quad 0x0000018800000000,0x0000000400000000,0x6000000000000000,0x0000108f00002105\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000cfd00000000,0x00000cfd00000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x00001d8c00002005,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000f5500000000,0x00000f5500000000,0x0000000400000000\n"
".quad 0x6000000000000000,0x00002ce100001f05,0x0000000000000000,0x0000000000000000\n"
".quad 0x000006c900000000,0x000006c900000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x000033aa00001e05,0x0000000000000000,0x0000000000000000,0x0000074900000000\n"
".quad 0x0000074900000000,0x0000000400000000,0x6000000000000000,0x00003af300001d05\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000090900000000,0x0000090900000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x000043fc00001c05,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000098d00000000,0x0000098d00000000,0x0000000400000000\n"
".quad 0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_21$[2549];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_21", (char*)__deviceText_$sm_21$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_21$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"d0a715f1dcf45ac8",(char*)"/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xc696324e,&__elfEntries1};
# 3 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;char __par14;int __dummy_field;};
struct __T21 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;char __par14;int __dummy_field;};
struct __T22 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};
struct __T23 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};
struct __T24 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};
struct __T25 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};
extern void __device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const bool);
extern void __device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4&, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4&, const int, const int, const bool);
static void __sti____cudaRegisterAll_50_tmpxft_00000e9d_00000000_4_Mandelbrot_sm10_cpp1_ii_2099b970(void) __attribute__((__constructor__));
void __device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const bool __par14){ struct __T20 *__T2124 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2124->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2124->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2124->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2124->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2124->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2124->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2124->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2124->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2124->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2124->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2124->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2124->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2124->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2124->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2124->__par14) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10))); };}
void MandelbrotDS0_sm10( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const bool __cuda_14)
# 56 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{__device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);
# 99 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c"
void __device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const bool __par14) { struct __T21 *__T2125 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2125->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2125->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2125->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2125->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2125->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2125->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2125->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2125->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2125->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2125->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2125->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2125->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2125->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2125->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2125->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10))); }; }
void MandelbrotDS1_sm10( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const bool __cuda_14)
# 162 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
{__device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);
# 215 "/home/normal/checkout/gpuocelot/tests-ptx-2.1/cuda2.2/tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu"
}
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c"
static void __device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const bool __par12) { struct __T22 *__T2129 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2129->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2129->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2129->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2129->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2129->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2129->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2129->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2129->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2129->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2129->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2129->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2129->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2129->__par12) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<float> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12){__device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
static void __device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const bool __par12) { struct __T23 *__T2130 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2130->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2130->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2130->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2130->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2130->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2130->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2130->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2130->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2130->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2130->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2130->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2130->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2130->__par12) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<double> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12){__device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
static void __device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const bool __par12) { struct __T24 *__T2137 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2137->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2137->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2137->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2137->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2137->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2137->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2137->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2137->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2137->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2137->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2137->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2137->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2137->__par12) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<float> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12){__device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
static void __device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const bool __par12) { struct __T25 *__T2138 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2138->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2138->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2138->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2138->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2138->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2138->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2138->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2138->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2138->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2138->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2138->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2138->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2138->__par12) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<double> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12){__device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
static void __sti____cudaRegisterAll_50_tmpxft_00000e9d_00000000_4_Mandelbrot_sm10_cpp1_ii_2099b970(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<double> ), (char*)"_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10<float> ), (char*)"_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<double> ), (char*)"_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10<float> ), (char*)"_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10), (char*)"_Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib", "_Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10), (char*)"_Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib", "_Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_00000e9d_00000000-1_Mandelbrot_sm10.cudafe1.stub.c" 2

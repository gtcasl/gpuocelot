# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
# 46 "/usr/local/cuda3.2/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/device_types.h" 1 3
# 46 "/usr/local/cuda3.2/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 1 3
# 96 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
enum cudaError
{





  cudaSuccess = 0,





  cudaErrorMissingConfiguration = 1,





  cudaErrorMemoryAllocation = 2,





  cudaErrorInitializationError = 3,
# 131 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchFailure = 4,
# 140 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorPriorLaunchFailure = 5,
# 150 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchTimeout = 6,
# 159 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchOutOfResources = 7,





  cudaErrorInvalidDeviceFunction = 8,
# 174 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
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
# 255 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorAddressOfConstant = 22,
# 264 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureFetchFailed = 23,
# 273 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureNotBound = 24,
# 282 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorSynchronizationError = 25,





  cudaErrorInvalidFilterSetting = 26,





  cudaErrorInvalidNormSetting = 27,







  cudaErrorMixedDeviceExecution = 28,







  cudaErrorCudartUnloading = 29,




  cudaErrorUnknown = 30,





  cudaErrorNotYetImplemented = 31,
# 330 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorMemoryValueTooLarge = 32,






  cudaErrorInvalidResourceHandle = 33,







  cudaErrorNotReady = 34,






  cudaErrorInsufficientDriver = 35,
# 365 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
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
# 426 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
  cudaErrorDevicesUnavailable = 46,




  cudaErrorInvalidKernelImage = 47,







  cudaErrorNoKernelImageForDevice = 48,
# 448 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
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
# 768 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct cudaGraphicsResource *cudaGraphicsResource_t;





typedef struct CUuuid_st cudaUUID_t;
# 44 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/surface_types.h" 1 3
# 63 "/usr/local/cuda3.2/cuda/bin/../include/surface_types.h" 3
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
# 45 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h" 1 3
# 63 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h" 3
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
# 46 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 1 3
# 45 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 1 3
# 46 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 1 3
# 46 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 46 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/host_defines.h" 1 3
# 47 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 2 3
# 75 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 3
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
# 229 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 3
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
# 366 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 3
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
# 469 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/usr/local/cuda3.2/cuda/bin/../include/builtin_types.h" 2 3
# 70 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 2 3
# 96 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 466 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 478 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 491 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 497 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 510 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 523 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 535 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 546 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 564 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 570 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 579 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 590 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 603 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 656 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 667 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 678 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 689 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 768 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 774 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 780 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 786 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 792 "/usr/local/cuda3.2/cuda/bin/../include/driver_types.h"
# 63 "/usr/local/cuda3.2/cuda/bin/../include/surface_types.h"
# 74 "/usr/local/cuda3.2/cuda/bin/../include/surface_types.h"
# 84 "/usr/local/cuda3.2/cuda/bin/../include/surface_types.h"
# 63 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h"
# 85 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h"
# 95 "/usr/local/cuda3.2/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 81 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 87 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 93 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 99 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 105 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 111 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 123 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 129 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 135 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 141 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 147 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 153 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 162 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 165 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 171 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 177 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 189 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 195 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 201 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 207 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 229 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 235 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 243 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 249 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 255 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 261 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 267 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 273 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 276 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 282 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 288 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 294 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 300 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 312 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 318 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 324 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 336 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 342 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 348 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 354 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 366 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 368 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 370 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 372 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 374 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 376 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 378 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 380 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 382 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 384 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 386 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 388 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 390 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 392 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 394 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 396 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 398 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 400 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 402 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 404 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 406 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 408 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 410 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 412 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 414 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 416 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 418 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 420 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 424 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 426 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 428 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 430 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 432 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 434 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 436 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 438 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 440 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 442 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 444 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 446 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 448 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 450 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 452 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 454 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 456 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 458 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 460 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 469 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda3.2/cuda/bin/../include/vector_types.h"
# 115 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 131 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 183 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t);
# 207 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit);
# 237 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetCacheConfig(cudaFuncCache *);
# 278 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetCacheConfig(cudaFuncCache);
# 330 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 373 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 387 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 418 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 536 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 555 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 579 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 597 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 626 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 677 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(unsigned);
# 703 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 719 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 753 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t, cudaEvent_t, unsigned);
# 771 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 789 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 821 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 852 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, unsigned);
# 885 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0);
# 914 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 946 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 966 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 1007 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 1046 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 1073 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 1119 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache);
# 1154 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 1187 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 1209 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 1231 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 1263 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 1292 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 1331 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 1370 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0));
# 1394 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 1414 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 1436 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 1495 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 1522 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 1541 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 1576 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 1626 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0));
# 1723 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 1828 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0);
# 1847 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 1880 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 1913 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 1946 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 1981 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2023 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2064 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2105 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 2144 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2179 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 2213 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 2256 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2298 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2340 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2391 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2441 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2491 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2535 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2578 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2600 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 2626 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 2665 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 2692 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemsetAsync(void *, int, size_t, cudaStream_t = 0);
# 2724 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2DAsync(void *, size_t, int, size_t, size_t, cudaStream_t = 0);
# 2769 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3DAsync(cudaPitchedPtr, int, cudaExtent, cudaStream_t = 0);
# 2796 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 2819 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 2865 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t);
# 2897 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t, unsigned);
# 2932 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2963 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2992 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource_t);
# 3026 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource_t, unsigned, unsigned);
# 3059 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 3094 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 3136 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 3179 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 3207 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3228 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 3253 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 3277 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 3310 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3328 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 3355 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 3372 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 3377 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *);
# 93 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 94 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 95 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 96 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 98 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 99 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 100 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 102 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 103 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 105 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 106 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 107 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 109 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 110 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 113 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 120 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 127 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 133 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 135 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 138 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 141 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 142 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 145 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 148 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 149 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 152 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 159 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 166 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 173 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 180 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 187 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 194 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 197 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 201 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 204 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 208 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 215 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 222 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 229 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 236 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 243 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 250 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 253 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 257 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 260 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 264 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 271 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 278 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 285 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 292 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 299 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 365 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 366 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 367 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 369 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 370 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 372 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 373 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 374 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 376 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 377 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 380 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 387 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda3.2/cuda/bin/../include/channel_descriptor.h"
}
# 65 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 66 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
{
# 67 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 69 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 70 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 71 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 72 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 74 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
return s;
# 75 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
}
# 92 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 93 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
{
# 94 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 96 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 97 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 98 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 100 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
return p;
# 101 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
}
# 118 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 119 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
{
# 120 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 122 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 123 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 124 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 126 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
return e;
# 127 "/usr/local/cuda3.2/cuda/bin/../include/driver_functions.h"
}
# 55 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 56 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 57 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 58 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 60 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 61 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 62 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 63 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 65 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 66 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 67 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 68 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 70 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 71 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 72 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 73 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 75 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 76 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 77 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 78 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 80 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 81 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 82 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 83 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 85 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 86 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 87 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 88 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 90 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 91 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 92 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 93 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 95 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 96 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 97 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 98 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 100 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 101 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 102 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 103 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 105 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 106 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 107 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 108 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 110 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 111 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 112 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 113 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 115 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 116 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 117 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 118 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 120 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 121 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 122 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 123 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 125 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 126 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 127 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 128 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 130 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 131 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 132 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 133 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 135 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 136 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 137 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 138 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 140 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 141 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 142 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 143 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 145 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 146 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 147 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 148 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 150 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 151 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 152 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 153 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 155 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 156 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 157 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 158 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 160 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 161 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 162 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 163 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 165 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 166 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 167 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 168 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 170 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 171 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 172 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 173 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 175 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 176 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 177 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 178 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 180 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 181 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 182 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 183 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 185 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 186 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 187 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 188 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 190 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 191 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 192 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 193 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 195 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 196 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 197 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 198 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 200 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 201 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 202 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 203 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 205 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 206 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 207 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 208 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 210 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 211 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 212 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 213 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 215 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 216 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 217 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 218 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 220 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 221 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 222 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 223 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 225 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 226 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 227 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 228 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 230 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 231 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 232 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 233 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 235 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 236 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 237 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 238 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 240 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 241 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 242 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 243 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 245 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 246 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 247 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 248 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 250 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 251 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 252 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 253 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 255 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 256 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 257 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 258 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 260 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 261 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 262 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 263 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 265 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 266 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 267 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 268 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 270 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 271 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 272 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 273 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 275 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 276 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 277 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 278 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 280 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 281 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 282 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 283 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 285 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 286 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 287 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 288 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
}
# 290 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 291 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
{
# 292 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 293 "/usr/local/cuda3.2/cuda/bin/../include/vector_functions.h"
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
# 57 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) clock_t clock() throw();
# 59 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
# 61 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memcpy(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 66 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 68 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 70 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 72 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fabs(double) throw() __attribute__((__const__));
# 74 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__));
# 77 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int min(int, int);
# 79 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umin(unsigned, unsigned);
# 81 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmin(long long, long long);
# 83 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 85 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fminf(float, float) throw();
# 87 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmin(double, double) throw();
# 90 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int max(int, int);
# 92 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umax(unsigned, unsigned);
# 94 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmax(long long, long long);
# 96 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 98 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaxf(float, float) throw();
# 100 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmax(double, double) throw();
# 103 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sin(double) throw();
# 105 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinf(float) throw();
# 108 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cos(double) throw();
# 110 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cosf(float) throw();
# 113 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincos(double, double *, double *) throw();
# 115 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincosf(float, float *, float *) throw();
# 118 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tan(double) throw();
# 120 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanf(float) throw();
# 123 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sqrt(double) throw();
# 125 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sqrtf(float) throw();
# 128 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rsqrt(double);
# 130 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rsqrtf(float);
# 133 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp2(double) throw();
# 135 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp2f(float) throw();
# 138 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp10(double) throw();
# 140 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp10f(float) throw();
# 143 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double expm1(double) throw();
# 145 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expm1f(float) throw();
# 148 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log2(double) throw();
# 150 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log2f(float) throw();
# 153 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log10(double) throw();
# 155 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log10f(float) throw();
# 158 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log(double) throw();
# 160 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logf(float) throw();
# 163 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log1p(double) throw();
# 165 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log1pf(float) throw();
# 168 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double floor(double) throw() __attribute__((__const__));
# 170 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float floorf(float) throw() __attribute__((__const__));
# 173 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp(double) throw();
# 175 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expf(float) throw();
# 178 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cosh(double) throw();
# 180 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float coshf(float) throw();
# 183 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinh(double) throw();
# 185 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinhf(float) throw();
# 188 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tanh(double) throw();
# 190 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanhf(float) throw();
# 193 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acosh(double) throw();
# 195 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acoshf(float) throw();
# 198 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asinh(double) throw();
# 200 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinhf(float) throw();
# 203 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atanh(double) throw();
# 205 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanhf(float) throw();
# 208 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ldexp(double, int) throw();
# 210 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ldexpf(float, int) throw();
# 213 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double logb(double) throw();
# 215 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logbf(float) throw();
# 218 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogb(double) throw();
# 220 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogbf(float) throw();
# 223 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbn(double, int) throw();
# 225 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalbnf(float, int) throw();
# 228 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbln(double, long) throw();
# 230 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalblnf(float, long) throw();
# 233 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double frexp(double, int *) throw();
# 235 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float frexpf(float, int *) throw();
# 238 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double round(double) throw() __attribute__((__const__));
# 240 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float roundf(float) throw() __attribute__((__const__));
# 243 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lround(double) throw();
# 245 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lroundf(float) throw();
# 248 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llround(double) throw();
# 250 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llroundf(float) throw();
# 253 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rint(double) throw();
# 255 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rintf(float) throw();
# 258 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrint(double) throw();
# 260 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrintf(float) throw();
# 263 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrint(double) throw();
# 265 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrintf(float) throw();
# 268 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nearbyint(double) throw();
# 270 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nearbyintf(float) throw();
# 273 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ceil(double) throw() __attribute__((__const__));
# 275 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__));
# 278 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double trunc(double) throw() __attribute__((__const__));
# 280 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float truncf(float) throw() __attribute__((__const__));
# 283 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fdim(double, double) throw();
# 285 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fdimf(float, float) throw();
# 288 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan2(double, double) throw();
# 290 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atan2f(float, float) throw();
# 293 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan(double) throw();
# 295 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanf(float) throw();
# 298 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asin(double) throw();
# 300 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinf(float) throw();
# 303 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acos(double) throw();
# 305 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acosf(float) throw();
# 308 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double hypot(double, double) throw();
# 310 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float hypotf(float, float) throw();
# 313 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cbrt(double) throw();
# 315 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cbrtf(float) throw();
# 318 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rcbrt(double);
# 320 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rcbrtf(float);
# 323 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinpi(double);
# 325 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinpif(float);
# 328 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double pow(double, double) throw();
# 330 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float powf(float, float) throw();
# 333 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double modf(double, double *) throw();
# 335 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float modff(float, float *) throw();
# 338 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmod(double, double) throw();
# 340 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmodf(float, float) throw();
# 343 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remainder(double, double) throw();
# 345 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remainderf(float, float) throw();
# 348 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remquo(double, double, int *) throw();
# 350 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remquof(float, float, int *) throw();
# 353 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erf(double) throw();
# 355 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erff(float) throw();
# 358 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfinv(double);
# 360 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfinvf(float);
# 363 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfc(double) throw();
# 365 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcf(float) throw();
# 368 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfcinv(double);
# 370 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcinvf(float);
# 373 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double lgamma(double) throw();
# 375 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float lgammaf(float) throw();
# 378 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tgamma(double) throw();
# 380 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tgammaf(float) throw();
# 383 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__));
# 385 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__));
# 388 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__));
# 390 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__));
# 393 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__));
# 395 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__));
# 398 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__));
# 400 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__));
# 403 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__));
# 405 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__));
# 419 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finite(double) throw() __attribute__((__const__));
# 421 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__));
# 423 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__));
# 428 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__));
# 431 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fma(double, double, double) throw();
# 433 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaf(float, float, float) throw();
# 441 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__));
# 443 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__));
# 445 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__));
# 455 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
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
extern "C" { typedef long register_t; }
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
# 497 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 499 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 500 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 502 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
namespace std {
# 504 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __pow_helper(T, int);
# 505 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __cmath_power(T, unsigned);
# 506 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 508 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::abs;
# 509 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::fabs;
# 510 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::ceil;
# 511 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::floor;
# 512 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 513 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::pow;
# 514 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::log;
# 515 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::log10;
# 516 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::fmod;
# 517 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::modf;
# 518 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::exp;
# 519 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::frexp;
# 520 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 521 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::asin;
# 522 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::sin;
# 523 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::sinh;
# 524 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::acos;
# 525 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::cos;
# 526 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::cosh;
# 527 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::atan;
# 528 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::atan2;
# 529 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::tan;
# 530 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
using std::tanh;
# 584 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
namespace std {
# 587 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 588 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 589 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 590 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 591 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 592 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 593 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 594 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 595 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 596 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 597 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 598 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 599 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 600 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 601 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 602 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 603 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 604 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 605 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 606 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 607 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 608 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 609 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 610 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 611 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 612 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 613 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 616 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 619 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 620 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 621 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return logbf(a);
# 622 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 624 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 625 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 626 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 627 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 629 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 630 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 631 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 632 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 634 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 635 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 636 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 637 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 639 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 640 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 641 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 642 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 644 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 645 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 646 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 647 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 649 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 650 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 651 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 652 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 654 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 655 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 656 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return log2f(a);
# 657 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 659 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 660 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 661 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 662 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 664 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 665 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 666 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 667 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 669 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 670 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 671 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 672 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 674 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 675 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 676 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 677 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 679 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 680 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 681 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 682 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 684 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 685 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 686 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 687 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 689 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 690 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 691 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 692 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 694 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 695 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 696 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 697 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 699 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 700 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 701 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 702 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 704 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 705 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 706 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 707 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 709 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 710 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 711 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return erff(a);
# 712 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 714 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 715 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 716 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 717 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 719 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 720 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 721 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 722 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 724 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 725 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 726 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 727 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 729 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 730 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 731 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 732 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 734 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 735 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 736 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 737 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 739 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 740 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 741 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 742 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 744 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 745 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 746 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 747 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 749 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 750 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 751 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 752 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 754 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 755 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 756 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 757 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 759 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 760 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 761 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 762 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 764 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 765 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 766 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 767 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 769 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 770 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 771 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return roundf(a);
# 772 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 774 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 775 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 776 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 777 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 779 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 780 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 781 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 782 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 784 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 785 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 786 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return truncf(a);
# 787 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 789 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 790 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 791 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return rintf(a);
# 792 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 794 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 795 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 796 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 797 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 799 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 800 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 801 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 802 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 804 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 805 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 806 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 807 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 809 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 810 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 811 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 812 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 814 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 815 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 816 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 817 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 819 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 820 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 821 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 822 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 824 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 825 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 826 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 827 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 829 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 830 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 831 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 832 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 834 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 835 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 836 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 837 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 839 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 840 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 841 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 842 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 844 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 845 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 846 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 847 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 849 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 850 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 851 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 852 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 854 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 855 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 856 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 857 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 859 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 860 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 861 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 862 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 864 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 865 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 866 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 867 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 869 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 870 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 871 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 872 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 874 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 875 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 876 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 877 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 879 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 880 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 881 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 882 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 884 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 885 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 886 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 887 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 889 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 890 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 891 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 892 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 894 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 895 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 896 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 897 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 899 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 900 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 901 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 902 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 904 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 905 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 906 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 907 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 909 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 910 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 911 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 912 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 914 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 915 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 916 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 917 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 919 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 920 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 921 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 922 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 924 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 925 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 926 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 927 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 929 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 930 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 931 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 932 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 934 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 935 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
{
# 936 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 937 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h"
}
# 60 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
template< class T, int dim = 1>
# 61 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 63 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
surface()
# 64 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
{
# 65 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 66 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
}
# 68 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 69 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
{
# 70 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 71 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
}
# 72 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
};
# 75 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
template< int dim>
# 76 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 78 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
surface()
# 79 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
{
# 80 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 81 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
}
# 82 "/usr/local/cuda3.2/cuda/bin/../include/cuda_surface_types.h"
};
# 60 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
template< class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 61 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 63 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 64 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 65 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 66 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
{
# 67 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 68 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 69 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 70 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 71 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 72 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 73 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
}
# 75 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 76 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 77 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 78 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
desc)
# 79 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
{
# 80 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 81 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 82 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 83 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 84 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 85 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 86 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
}
# 87 "/usr/local/cuda3.2/cuda/bin/../include/cuda_texture_types.h"
};
# 324 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mulhi(int a, int b)
# 325 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 327 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 329 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b)
# 330 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 332 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 334 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b)
# 335 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 337 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 339 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b)
# 340 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 344 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b)
# 345 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 347 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 349 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 350 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 352 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 354 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 355 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 357 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 359 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 360 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 364 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float_as_int(float a)
# 365 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 367 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 369 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int_as_float(int a)
# 370 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 374 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float saturate(float a)
# 375 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 377 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 379 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mul24(int a, int b)
# 380 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 382 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 384 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b)
# 385 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 389 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void trap()
# 390 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 392 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 394 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void brkpt(int c)
# 395 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 397 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 399 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void syncthreads()
# 400 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 404 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void prof_trigger(int e)
# 405 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 422 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 424 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void threadfence(bool global = true)
# 425 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 429 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 430 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 437 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 438 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 445 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 446 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 453 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 454 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 459 "/usr/local/cuda3.2/cuda/bin/../include/device_functions.h"
exit(___);}
# 102 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val)
# 103 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 105 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 107 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 108 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 112 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val)
# 113 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 115 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 117 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val)
# 118 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 120 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 122 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val)
# 123 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 125 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 127 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val)
# 128 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 130 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 132 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val)
# 133 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 135 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 137 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val)
# 138 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 142 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val)
# 143 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 147 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val)
# 148 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 150 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 152 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val)
# 153 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 155 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 157 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val)
# 158 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 162 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val)
# 163 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 167 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val)
# 168 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 170 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 172 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 173 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 175 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 177 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val)
# 178 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 182 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val)
# 183 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 185 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 187 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val)
# 188 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 190 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 192 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val)
# 193 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 195 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 197 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val)
# 198 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 203 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 205 "/usr/local/cuda3.2/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 75 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 76 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 78 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 80 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 81 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 83 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 85 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 86 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 88 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 90 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond)
# 91 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 93 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 95 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond)
# 96 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 98 "/usr/local/cuda3.2/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 170 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 171 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 176 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 178 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 179 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 184 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 186 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 187 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 194 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 195 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 203 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 208 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 210 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 211 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 216 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 218 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 219 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 224 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 226 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 227 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 234 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 235 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 240 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 242 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 243 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 245 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 247 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 248 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 252 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 253 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda3.2/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 66 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val)
# 67 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;
# 69 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 124 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned ballot(bool pred)
# 125 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 127 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 129 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred)
# 130 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 132 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 134 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred)
# 135 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 137 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 139 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred)
# 140 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 142 "/usr/local/cuda3.2/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 97 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 98 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 99 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 106 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 108 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 109 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 110 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 116 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 118 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 119 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 120 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 122 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 125 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 126 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 128 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 131 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 132 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 134 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 137 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 138 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 143 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 144 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 146 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 149 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 150 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 152 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 155 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 156 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 166 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 174 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 189 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 190 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 195 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 196 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 198 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 201 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 202 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 204 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 207 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 208 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 212 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 218 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 226 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 238 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 241 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 242 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 244 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 247 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 248 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 253 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 254 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 256 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 259 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 260 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 264 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 270 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 278 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 290 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 293 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 294 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 296 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 299 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 300 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 302 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 305 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 306 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 308 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 311 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 312 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 316 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 322 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 385 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 386 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 388 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 391 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 392 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 394 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 397 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 398 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 410 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 457 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 458 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 459 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 466 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 469 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 470 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 476 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 478 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 479 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 480 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 482 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 485 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 486 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 488 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 491 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 492 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 494 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 497 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 498 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 500 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 503 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 504 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 506 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 509 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 510 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 512 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 515 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 516 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 520 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 526 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 534 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 540 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 546 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 549 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 550 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 555 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 556 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 558 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 561 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 562 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 564 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 567 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 568 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 572 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 578 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 586 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 592 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 598 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 601 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 602 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 604 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 607 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 608 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 610 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 613 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 614 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 616 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 619 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 620 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 624 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 630 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 638 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 644 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 650 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 653 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 654 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 659 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 660 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 662 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 665 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 666 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 668 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 671 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 672 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 682 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 745 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 746 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 748 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 751 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 752 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 754 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 757 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 758 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 762 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 770 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 817 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 818 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 819 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 837 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 839 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 840 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 841 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 843 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 846 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 847 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 849 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 851 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 852 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 854 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 856 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 857 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 859 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 862 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 864 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 866 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 867 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 869 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 871 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 872 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 876 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 877 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 879 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 882 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 884 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 886 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 887 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 889 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 891 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 892 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 894 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 896 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 897 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 899 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 901 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 902 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 904 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 906 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 907 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 909 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 911 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 912 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 914 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 916 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 917 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 919 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 921 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 922 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 924 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 926 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 927 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 929 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 931 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 932 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 934 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 936 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 937 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 939 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 941 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 942 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 946 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 947 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 949 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 952 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 954 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 956 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 957 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 959 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 961 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 962 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 964 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 966 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 967 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 969 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 972 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 974 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 976 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 977 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 979 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 981 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 982 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 984 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 986 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 987 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 989 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 992 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 994 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 996 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 997 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 999 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1045 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1046 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1048 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1050 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1051 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1053 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1055 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1056 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1058 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1060 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1061 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1063 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1110 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1111 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1112 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1130 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1132 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1133 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1134 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1136 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1139 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1140 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1142 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1144 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1145 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1147 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1149 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1150 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1155 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1157 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1159 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1160 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1162 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1165 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1167 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1169 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1170 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1172 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1174 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1175 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1177 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1179 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1180 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1184 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1185 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1187 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1190 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1192 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1194 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1195 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1197 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1199 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1200 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1204 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1205 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1207 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1210 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1212 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1214 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1215 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1217 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1219 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1220 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1222 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1224 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1225 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1227 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1230 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1232 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1234 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1235 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1239 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1240 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1242 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1244 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1245 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1247 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1249 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1250 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1254 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1255 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1257 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1259 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1260 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1262 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1264 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1265 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1267 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1269 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1270 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1272 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1274 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1275 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1277 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1279 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1280 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1282 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1284 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1285 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1287 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1289 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1290 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1292 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1338 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1339 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1341 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1343 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1344 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1346 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1348 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1349 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1351 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1353 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1354 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1356 "/usr/local/cuda3.2/cuda/bin/../include/surface_functions.h"
exit(___);}
# 61 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 63 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 65 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 68 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetch(texture< T, dim, readMode> , float4, int = dim);
# 70 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetch(texture< T, dim, readMode> , float4, int = dim);
# 72 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetch(texture< T, dim, readMode> , float4, int = dim);
# 80 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 81 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 89 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 91 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 92 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 96 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 98 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 99 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 103 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 105 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 106 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 117 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 124 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 131 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 138 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 153 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 154 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 158 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 160 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 161 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 167 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 168 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 172 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 179 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 193 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 207 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 215 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 216 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 220 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 222 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 223 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 227 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 229 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 230 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 234 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 241 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 248 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 262 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 269 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 343 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 344 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 350 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 351 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 355 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 357 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 358 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 369 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 377 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 378 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 389 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 390 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 395 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 397 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 398 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 403 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 411 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 419 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 459 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 460 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 465 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 467 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 468 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 473 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 481 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 489 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 497 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 505 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 513 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 521 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 529 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 530 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 538 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 540 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 541 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 545 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 547 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 548 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 554 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 555 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 559 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 566 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 573 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 580 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 587 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 594 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 602 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 603 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 607 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 609 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 610 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 614 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 616 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 617 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 621 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 628 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 635 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 642 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 649 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 664 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 665 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 669 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 671 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 672 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 678 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 679 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 683 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 697 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 704 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 711 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 718 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 798 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 799 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 803 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 805 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 806 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 810 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 812 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 813 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 817 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 824 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 832 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 833 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 842 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 844 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 845 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 850 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 852 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 853 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 858 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 866 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 882 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 890 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 898 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 906 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 914 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 915 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 920 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 922 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 923 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 928 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 936 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 952 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 960 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 968 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 976 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 984 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 985 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 993 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 995 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 996 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1000 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1002 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1003 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1007 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1009 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1010 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1014 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1028 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1035 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1042 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1049 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1057 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1058 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1062 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1064 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1065 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1069 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1071 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1072 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1076 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1083 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1090 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1097 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1104 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1111 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1119 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1120 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1124 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1126 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1127 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1131 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1133 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1134 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1138 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1145 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1159 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1166 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1173 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1247 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1248 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1254 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1255 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1259 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1261 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1262 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1266 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1273 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1281 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1282 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1291 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1293 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1294 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1301 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1302 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1307 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1315 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1323 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1331 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1339 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1347 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1355 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1363 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1364 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1369 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1371 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1372 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1377 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1385 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1393 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1401 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1409 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1417 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1425 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1433 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1434 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1442 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1444 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1445 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1449 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1451 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1452 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1456 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1458 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1459 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1463 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1466 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1470 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1473 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1477 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1480 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1484 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1487 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1491 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1494 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1498 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1506 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1507 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1511 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1513 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1514 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1518 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1520 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1521 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1525 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1528 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1532 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1535 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1539 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1542 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1546 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1549 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1553 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1556 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1560 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1568 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1569 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1573 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1575 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1576 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1580 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1582 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1583 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1587 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1590 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1594 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1597 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1601 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1604 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1608 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1611 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1615 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1618 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1622 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1696 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1697 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1701 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1703 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1704 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1708 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1710 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1711 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1715 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1718 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1722 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1730 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1731 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1740 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1742 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1743 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1748 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1750 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1751 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1756 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1759 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1764 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1767 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1772 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1775 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1780 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1783 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1788 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1791 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1796 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1799 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1804 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1812 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1813 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1818 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1820 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1821 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1826 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1829 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1834 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1837 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1842 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1845 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1850 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1853 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1858 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1861 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1866 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1869 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1874 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1930 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern int4 __itex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1932 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern uint4 __utex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1934 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern float4 __ftex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1954 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1955 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1957 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1959 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< signed char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1960 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1962 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1964 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1965 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1967 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1969 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1970 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1972 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1974 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1975 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1977 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1979 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1980 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1982 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1984 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1985 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1987 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1989 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1990 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1992 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1994 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1995 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1997 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1999 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2000 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2002 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2004 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2005 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2007 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2009 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2010 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2012 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2014 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2015 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2017 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2019 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2020 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2022 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2024 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2025 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2027 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2029 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2030 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2032 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2034 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2035 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2037 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2039 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2040 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2042 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2044 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2045 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2047 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2049 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2050 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2052 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2054 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2055 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2057 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2059 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2060 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2062 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2064 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2065 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2067 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2069 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2070 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2072 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2074 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2075 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2077 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2079 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2080 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2082 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2084 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2085 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2087 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2089 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2090 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2092 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2094 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2095 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2097 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2099 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2100 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2102 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2104 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2105 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2107 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2109 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2110 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2112 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2114 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2115 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2117 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2119 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2120 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2122 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2124 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2125 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2127 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2129 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2130 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2132 "/usr/local/cuda3.2/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 53 "/usr/local/cuda3.2/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 threadIdx; }
# 55 "/usr/local/cuda3.2/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 blockIdx; }
# 57 "/usr/local/cuda3.2/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 blockDim; }
# 59 "/usr/local/cuda3.2/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 gridDim; }
# 61 "/usr/local/cuda3.2/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const int warpSize; }
# 106 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 107 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 108 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 109 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset)
# 111 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 112 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 113 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 145 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 146 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
event, unsigned
# 147 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
flags)
# 149 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 150 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaEventCreateWithFlags(event, 0);
# 151 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 209 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 210 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 211 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
flags)
# 213 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 214 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc(ptr, size, flags);
# 215 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 217 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 218 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 219 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 220 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 221 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
flags)
# 223 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 224 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 225 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 228 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 229 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 230 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 231 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
flags)
# 233 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 234 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 235 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 237 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 238 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 239 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 240 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size)
# 242 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 243 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 244 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 246 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 247 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 248 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 249 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 250 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
flags = (0))
# 252 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 253 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size, flags);
# 254 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 256 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 257 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 258 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 259 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 260 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 261 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
height)
# 263 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 264 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 265 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 276 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 277 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 278 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 279 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 280 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 282 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 283 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 284 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 286 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 287 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 288 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 289 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 290 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 291 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 292 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 294 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 295 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 296 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 298 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 299 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 300 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 301 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 302 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 303 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 304 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 306 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 307 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 308 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 310 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 311 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 312 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 313 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 314 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 315 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 316 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 317 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 319 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 320 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 321 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 329 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 330 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 331 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 332 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 333 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 334 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 336 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 337 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 338 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 340 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 341 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 342 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 343 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 344 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 345 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 346 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 348 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 349 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 350 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 352 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 353 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 354 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 355 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 356 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 357 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 358 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 360 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 361 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 362 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 364 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 365 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 366 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 367 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 368 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 369 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 370 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 371 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 373 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 374 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 375 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 377 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 378 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 379 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol)
# 381 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 382 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 383 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 410 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 411 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 412 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 413 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol)
# 415 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 416 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 417 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 425 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 426 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size, char *
# 427 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol)
# 429 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 430 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 431 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 458 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 459 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 460 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 461 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
symbol)
# 463 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 464 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 465 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 507 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 508 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 509 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 510 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 511 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 512 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 513 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 515 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 516 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 517 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 552 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 553 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 554 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 555 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 556 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 557 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 559 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 560 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 561 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 608 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 609 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 610 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 611 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 612 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 613 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 614 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 615 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 616 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
pitch)
# 618 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 619 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 620 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 666 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 667 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 668 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 669 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 670 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 671 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 672 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 673 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
pitch)
# 675 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 676 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &(tex.texture< T, dim, readMode> ::channelDesc), width, height, pitch);
# 677 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 708 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 709 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 710 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 711 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 712 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
desc)
# 714 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 715 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 716 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 746 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 747 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 748 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 749 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
array)
# 751 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 752 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 753 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 755 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 756 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 785 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 786 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 787 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex)
# 789 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 790 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 791 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 825 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 826 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 827 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 828 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
tex)
# 830 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 831 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 832 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 886 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 887 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 888 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 889 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 891 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 892 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 893 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 930 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 931 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 932 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
entry)
# 934 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 935 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 936 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 970 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 971 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 972 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 973 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
entry)
# 975 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 976 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 977 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 999 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1000 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1001 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1002 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 1003 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
desc)
# 1005 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 1006 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 1007 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
}
# 1028 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1029 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1030 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1031 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
array)
# 1033 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
{
# 1034 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 1035 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 1037 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 1038 "/usr/local/cuda3.2/cuda/bin/../include/cuda_runtime.h"
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/va.h" 3
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
# 128 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned long long CUdeviceptr; }
# 135 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 136 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 137 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 138 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 139 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 140 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 141 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 142 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 143 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 144 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 148 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 146 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUuuid_st {
# 147 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
char bytes[16];
# 148 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUuuid; }
# 162 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 153 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 154 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 155 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 156 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 157 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 158 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 159 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 160 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 161 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 162 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 171 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 167 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 168 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 169 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 170 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_EVENT_DISABLE_TIMING
# 171 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 185 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 176 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 177 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 178 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 179 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 180 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 181 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 182 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 183 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 184 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 185 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 195 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 191 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 192 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 193 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 194 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER
# 195 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 203 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 200 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 201 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 202 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 203 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 246 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 208 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 209 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 210 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 211 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 212 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 213 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 214 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 215 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 216 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 217 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 218 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 219 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 220 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 221 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 222 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 223 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 224 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 225 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 226 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 227 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 228 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 229 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 230 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 231 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 232 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 233 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 234 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 235 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 236 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 237 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 238 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 239 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 240 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 241 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 242 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 243 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 244 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 245 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER
# 246 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 262 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 251 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 252 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 253 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 254 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 255 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 256 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 257 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 258 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int memPitch;
# 259 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 260 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int clockRate;
# 261 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
int textureAlign;
# 262 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 317 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 267 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 273 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 280 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 286 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 291 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 296 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 305 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 314 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 316 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 317 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 326 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 322 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 323 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 324 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 325 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 326 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 335 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 331 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 332 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 333 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 334 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 335 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 344 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 340 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 341 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 342 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 343 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 344 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 436 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 349 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 355 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 368 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 375 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 383 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 391 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 399 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 407 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 414 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 421 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 427 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 434 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 436 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 449 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 441 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 443 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 444 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 445 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 446 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 447 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20,
# 448 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_21
# 449 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 460 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 454 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 456 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 458 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 460 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 467 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 465 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 466 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 467 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 476 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 472 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 473 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 474 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 475 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 476 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 488 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 481 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 482 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 483 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 484 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 485 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 486 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 487 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 488 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 497 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 493 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 494 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 495 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 496 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE
# 497 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUlimit; }
# 728 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 502 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 508 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 514 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 520 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 526 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 531 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 538 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 544 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 551 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 561 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 570 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 575 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 580 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 586 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 591 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 599 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 604 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 609 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 615 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 621 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 627 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 633 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 639 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 644 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 649 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 654 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 659 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 666 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 673 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 682 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 693 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 704 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 715 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 721 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 727 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 728 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUresult; }
# 777 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 756 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 757 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 758 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcY;
# 760 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 761 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
const void *srcHost;
# 762 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 763 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 764 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 766 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 767 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstY;
# 769 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 770 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
void *dstHost;
# 771 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 772 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 773 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 775 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 776 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Height;
# 777 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 810 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 782 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 783 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 784 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcY;
# 785 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcZ;
# 786 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcLOD;
# 787 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 788 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
const void *srcHost;
# 789 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 790 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 791 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
void *reserved0;
# 792 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 793 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 795 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 796 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstY;
# 797 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstZ;
# 798 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstLOD;
# 799 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 800 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
void *dstHost;
# 801 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 802 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 803 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
void *reserved1;
# 804 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 805 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 807 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 808 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Height;
# 809 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Depth;
# 810 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 822 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 815 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR_st {
# 817 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Width;
# 818 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Height;
# 820 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 821 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 822 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 836 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 827 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR_st {
# 829 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Width;
# 830 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Height;
# 831 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
size_t Depth;
# 833 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 834 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 835 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
unsigned Flags;
# 836 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 917 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 944 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 982 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 1008 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 1037 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 1066 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 1094 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem_v2(size_t *, CUdevice);
# 1154 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 1235 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 1333 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate_v2(CUcontext *, unsigned, CUdevice);
# 1367 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 1403 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 1435 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 1473 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 1515 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 1545 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 1575 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 1638 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit, size_t);
# 1673 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t *, CUlimit);
# 1716 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetCacheConfig(CUfunc_cache *);
# 1766 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetCacheConfig(CUfunc_cache);
# 1803 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetApiVersion(CUcontext, unsigned *);
# 1851 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 1885 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 1963 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 2000 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 2025 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 2055 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 2089 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal_v2(CUdeviceptr *, size_t *, CUmodule, const char *);
# 2123 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 2154 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref *, CUmodule, const char *);
# 2197 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo_v2(size_t *, size_t *);
# 2230 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc_v2(CUdeviceptr *, size_t);
# 2291 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch_v2(CUdeviceptr *, size_t *, size_t, size_t, unsigned);
# 2320 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree_v2(CUdeviceptr);
# 2353 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange_v2(CUdeviceptr *, size_t *, CUdeviceptr);
# 2392 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost_v2(void **, size_t);
# 2422 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 2494 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 2532 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *, void *, unsigned);
# 2557 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 2591 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD_v2(CUdeviceptr, const void *, size_t);
# 2624 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH_v2(void *, CUdeviceptr, size_t);
# 2657 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD_v2(CUdeviceptr, CUdeviceptr, size_t);
# 2691 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA_v2(CUarray, size_t, CUdeviceptr, size_t);
# 2727 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD_v2(CUdeviceptr, CUarray, size_t, size_t);
# 2761 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA_v2(CUarray, size_t, const void *, size_t);
# 2795 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH_v2(void *, CUarray, size_t, size_t);
# 2833 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA_v2(CUarray, size_t, CUarray, size_t, size_t);
# 2978 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *);
# 3121 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *);
# 3273 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *);
# 3313 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr, const void *, size_t, CUstream);
# 3353 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync_v2(void *, CUdeviceptr, size_t, CUstream);
# 3390 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr, CUdeviceptr, size_t, CUstream);
# 3432 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync_v2(CUarray, size_t, const void *, size_t, CUstream);
# 3474 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync_v2(void *, CUarray, size_t, size_t, CUstream);
# 3630 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *, CUstream);
# 3790 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *, CUstream);
# 3823 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8_v2(CUdeviceptr, unsigned char, size_t);
# 3856 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16_v2(CUdeviceptr, unsigned short, size_t);
# 3889 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32_v2(CUdeviceptr, unsigned, size_t);
# 3927 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8_v2(CUdeviceptr, size_t, unsigned char, size_t, size_t);
# 3965 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16_v2(CUdeviceptr, size_t, unsigned short, size_t, size_t);
# 4003 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32_v2(CUdeviceptr, size_t, unsigned, size_t, size_t);
# 4040 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8Async(CUdeviceptr, unsigned char, size_t, CUstream);
# 4077 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16Async(CUdeviceptr, unsigned short, size_t, CUstream);
# 4113 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32Async(CUdeviceptr, unsigned, size_t, CUstream);
# 4155 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8Async(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);
# 4197 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16Async(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream);
# 4239 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32Async(CUdeviceptr, size_t, unsigned, size_t, size_t, CUstream);
# 4342 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate_v2(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 4375 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 4406 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 4508 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate_v2(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 4544 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 4582 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 4622 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamWaitEvent(CUstream, CUevent, unsigned);
# 4646 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 4671 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 4693 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 4741 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 4777 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 4809 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 4843 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 4866 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 4909 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 4954 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 4985 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 5042 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 5090 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction, CUfunc_cache);
# 5119 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 5149 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 5179 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 5211 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 5245 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 5281 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 5321 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 5354 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 5395 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 5433 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress_v2(size_t *, CUtexref, CUdeviceptr, size_t);
# 5474 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D_v2(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);
# 5503 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 5541 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 5574 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 5606 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 5632 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress_v2(CUdeviceptr *, CUtexref);
# 5658 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 5684 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 5708 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 5734 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 5757 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 5791 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 5811 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 5849 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref, CUarray, unsigned);
# 5870 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray *, CUsurfref);
# 5911 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 5949 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 5983 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr *, size_t *, CUgraphicsResource);
# 6024 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 6062 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 6097 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 6101 "/usr/local/cuda3.2/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void **, const CUuuid *);
# 60 "sdk/cutil.h"
enum CUTBoolean {
# 62 "sdk/cutil.h"
CUTFalse,
# 63 "sdk/cutil.h"
CUTTrue
# 64 "sdk/cutil.h"
};
# 72 "sdk/cutil.h"
extern "C" void cutFree(void *);
# 90 "sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 103 "sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 118 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 134 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 150 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 165 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 181 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 197 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 211 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 225 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 237 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 249 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 261 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 273 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 289 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 302 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 316 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 332 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 348 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 363 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 375 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 387 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 400 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 412 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 424 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 436 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 457 "sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 471 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 485 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 499 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 514 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 528 "sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 540 "sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 553 "sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 567 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 580 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 595 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 609 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 623 "sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 638 "sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 653 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 668 "sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 681 "sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 690 "sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 698 "sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 706 "sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 714 "sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 723 "sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 734 "sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 30 "sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 31 "sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 32 "sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 33 "sdk/cutil_inline_bankchecker.h"
{
# 34 "sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 35 "sdk/cutil_inline_bankchecker.h"
}
# 46 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 48 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 49 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 50 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return x.x;
# 51 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 53 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 54 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 55 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return x.y;
# 56 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 58 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 59 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
r, float i)
# 60 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 61 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuFloatComplex res;
# 62 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 63 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 64 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return res;
# 65 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 67 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 68 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 69 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 70 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 71 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 72 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 73 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 74 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 76 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 78 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 79 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 80 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 81 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 83 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 90 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 91 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 92 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 93 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuFloatComplex prod;
# 94 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
prod = make_cuFloatComplex((cuCrealf(x) * cuCrealf(y)) - (cuCimagf(x) * cuCimagf(y)), (cuCrealf(x) * cuCimagf(y)) + (cuCimagf(x) * cuCrealf(y)));
# 98 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return prod;
# 99 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 106 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 107 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 108 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 109 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuFloatComplex quot;
# 110 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float s = (fabsf(cuCrealf(y)) + fabsf(cuCimagf(y)));
# 111 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float oos = ((1.0F) / s);
# 112 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float ars = (cuCrealf(x) * oos);
# 113 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float ais = (cuCimagf(x) * oos);
# 114 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float brs = (cuCrealf(y) * oos);
# 115 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float bis = (cuCimagf(y) * oos);
# 116 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 117 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
oos = ((1.0F) / s);
# 118 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
quot = make_cuFloatComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 120 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return quot;
# 121 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 131 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 132 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 133 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float a = cuCrealf(x);
# 134 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float b = cuCimagf(x);
# 135 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float v, w, t;
# 136 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
a = fabsf(a);
# 137 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
b = fabsf(b);
# 138 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 139 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
v = a;
# 140 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
w = b;
# 141 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} else {
# 142 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
v = b;
# 143 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
w = a;
# 144 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 145 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 146 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = ((1.0F) + (t * t));
# 147 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (v * sqrtf(t));
# 148 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 149 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 150 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 151 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return t;
# 152 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 155 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 157 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 158 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 159 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return x.x;
# 160 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 162 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 163 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 164 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return x.y;
# 165 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 167 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 168 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
r, double i)
# 169 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 170 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuDoubleComplex res;
# 171 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 172 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 173 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return res;
# 174 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 176 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 177 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 178 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 179 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 181 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 182 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 183 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 184 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 186 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 188 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 189 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 190 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 191 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 193 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 200 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 201 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 202 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 203 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuDoubleComplex prod;
# 204 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
prod = make_cuDoubleComplex((cuCreal(x) * cuCreal(y)) - (cuCimag(x) * cuCimag(y)), (cuCreal(x) * cuCimag(y)) + (cuCimag(x) * cuCreal(y)));
# 208 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return prod;
# 209 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 216 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 217 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 218 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 219 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
cuDoubleComplex quot;
# 220 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 221 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double oos = ((1.0) / s);
# 222 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double ars = (cuCreal(x) * oos);
# 223 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double ais = (cuCimag(x) * oos);
# 224 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double brs = (cuCreal(y) * oos);
# 225 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double bis = (cuCimag(y) * oos);
# 226 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 227 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
oos = ((1.0) / s);
# 228 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
quot = make_cuDoubleComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 230 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return quot;
# 231 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 239 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 240 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 241 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double a = cuCreal(x);
# 242 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double b = cuCimag(x);
# 243 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double v, w, t;
# 244 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
a = fabs(a);
# 245 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
b = fabs(b);
# 246 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 247 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
v = a;
# 248 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
w = b;
# 249 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} else {
# 250 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
v = b;
# 251 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
w = a;
# 252 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 253 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 254 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = ((1.0) + (t * t));
# 255 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (v * sqrt(t));
# 256 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 257 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 258 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 259 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 260 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return t;
# 261 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
} }
# 268 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 269 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 270 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
y)
# 271 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 272 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 273 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 276 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 277 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
c)
# 278 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 279 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 280 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 282 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 283 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
c)
# 284 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 285 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 286 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 289 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
static inline cuComplex cuCfmaf(cuComplex x, cuComplex y, cuComplex d)
# 290 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 291 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float real_res;
# 292 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
float imag_res;
# 294 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
real_res = ((cuCrealf(x) * cuCrealf(y)) + cuCrealf(d));
# 295 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCrealf(x) * cuCimagf(y)) + cuCimagf(d));
# 297 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimagf(x) * cuCimagf(y))) + real_res);
# 298 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimagf(x) * cuCrealf(y)) + imag_res);
# 300 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuComplex(real_res, imag_res);
# 301 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 303 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuCfma(cuDoubleComplex x, cuDoubleComplex y, cuDoubleComplex d)
# 304 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
{
# 305 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double real_res;
# 306 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
double imag_res;
# 308 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
real_res = ((cuCreal(x) * cuCreal(y)) + cuCreal(d));
# 309 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCreal(x) * cuCimag(y)) + cuCimag(d));
# 311 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimag(x) * cuCimag(y))) + real_res);
# 312 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimag(x) * cuCreal(y)) + imag_res);
# 314 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(real_res, imag_res);
# 315 "/usr/local/cuda3.2/cuda/bin/../include/cuComplex.h"
}
# 72 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 61 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
enum cufftResult_t {
# 62 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_SUCCESS,
# 63 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_INVALID_PLAN,
# 64 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_ALLOC_FAILED,
# 65 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_INVALID_TYPE,
# 66 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_INVALID_VALUE,
# 67 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_INTERNAL_ERROR,
# 68 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_EXEC_FAILED,
# 69 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_SETUP_FAILED,
# 70 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_INVALID_SIZE,
# 71 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_UNALIGNED_DATA
# 72 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
} cufftResult; }
# 77 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 81 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 82 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef double cufftDoubleReal; }
# 87 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 88 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 102 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 95 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
enum cufftType_t {
# 96 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_R2C = 42,
# 97 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_C2R = 44,
# 98 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_C2C = 41,
# 99 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_D2Z = 106,
# 100 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_Z2D = 108,
# 101 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_Z2Z = 105
# 102 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
} cufftType; }
# 131 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 126 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
enum cufftCompatibility_t {
# 127 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_NATIVE,
# 128 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_PADDING,
# 129 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ASYMMETRIC,
# 130 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ALL
# 131 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
} cufftCompatibility; }
# 135 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 140 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 144 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 148 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int);
# 156 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 158 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 163 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 167 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 171 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);
# 176 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);
# 180 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);
# 184 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 187 "/usr/local/cuda3.2/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetCompatibilityMode(cufftHandle, cufftCompatibility);
# 43 "sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 44 "sdk/cutil_inline_runtime.h"
{
# 45 "sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 46 "sdk/cutil_inline_runtime.h"
exit(1);
# 47 "sdk/cutil_inline_runtime.h"
}
# 48 "sdk/cutil_inline_runtime.h"
}
# 50 "sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 51 "sdk/cutil_inline_runtime.h"
{
# 52 "sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 53 "sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 54 "sdk/cutil_inline_runtime.h"
fflush(stdout);
# 55 "sdk/cutil_inline_runtime.h"
fflush(stderr);
# 56 "sdk/cutil_inline_runtime.h"
getchar();
# 57 "sdk/cutil_inline_runtime.h"
}
# 58 "sdk/cutil_inline_runtime.h"
exit(0);
# 59 "sdk/cutil_inline_runtime.h"
}
# 65 "sdk/cutil_inline_runtime.h"
inline int _ConvertSMVer2Cores(int major, int minor)
# 66 "sdk/cutil_inline_runtime.h"
{
# 71 "sdk/cutil_inline_runtime.h"
typedef
# 68 "sdk/cutil_inline_runtime.h"
struct {
# 69 "sdk/cutil_inline_runtime.h"
int SM;
# 70 "sdk/cutil_inline_runtime.h"
int Cores;
# 71 "sdk/cutil_inline_runtime.h"
} sSMtoCores;
# 73 "sdk/cutil_inline_runtime.h"
sSMtoCores nGpuArchCoresPerSM[] = {{16, 8}, {17, 8}, {18, 8}, {19, 8}, {32, 32}, {33, 48}, {(-1), (-1)}};
# 83 "sdk/cutil_inline_runtime.h"
int index = 0;
# 84 "sdk/cutil_inline_runtime.h"
while ((((nGpuArchCoresPerSM)[index]).SM) != (-1)) {
# 85 "sdk/cutil_inline_runtime.h"
if ((((nGpuArchCoresPerSM)[index]).SM) == ((major << 4) + minor)) {
# 86 "sdk/cutil_inline_runtime.h"
return ((nGpuArchCoresPerSM)[index]).Cores;
# 87 "sdk/cutil_inline_runtime.h"
}
# 88 "sdk/cutil_inline_runtime.h"
index++;
# 89 "sdk/cutil_inline_runtime.h"
}
# 90 "sdk/cutil_inline_runtime.h"
printf("MapSMtoCores undefined SMversion %d.%d!\n", major, minor);
# 91 "sdk/cutil_inline_runtime.h"
return -1;
# 92 "sdk/cutil_inline_runtime.h"
}
# 96 "sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 97 "sdk/cutil_inline_runtime.h"
{
# 98 "sdk/cutil_inline_runtime.h"
int current_device = 0, sm_per_multiproc = 0;
# 99 "sdk/cutil_inline_runtime.h"
int max_compute_perf = 0, max_perf_device = 0;
# 100 "sdk/cutil_inline_runtime.h"
int device_count = 0, best_SM_arch = 0;
# 101 "sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 103 "sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 105 "sdk/cutil_inline_runtime.h"
while (current_device < device_count) {
# 106 "sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&deviceProp, current_device);
# 107 "sdk/cutil_inline_runtime.h"
if (((deviceProp.major) > 0) && ((deviceProp.major) < 9999)) {
# 108 "sdk/cutil_inline_runtime.h"
best_SM_arch = ((best_SM_arch > (deviceProp.major)) ? best_SM_arch : (deviceProp.major));
# 109 "sdk/cutil_inline_runtime.h"
}
# 110 "sdk/cutil_inline_runtime.h"
current_device++;
# 111 "sdk/cutil_inline_runtime.h"
}
# 114 "sdk/cutil_inline_runtime.h"
current_device = 0;
# 115 "sdk/cutil_inline_runtime.h"
while (current_device < device_count) {
# 116 "sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&deviceProp, current_device);
# 117 "sdk/cutil_inline_runtime.h"
if (((deviceProp.major) == 9999) && ((deviceProp.minor) == 9999)) {
# 118 "sdk/cutil_inline_runtime.h"
sm_per_multiproc = 1;
# 119 "sdk/cutil_inline_runtime.h"
} else {
# 120 "sdk/cutil_inline_runtime.h"
sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
# 121 "sdk/cutil_inline_runtime.h"
}
# 123 "sdk/cutil_inline_runtime.h"
int compute_perf = (((deviceProp.multiProcessorCount) * sm_per_multiproc) * (deviceProp.clockRate));
# 124 "sdk/cutil_inline_runtime.h"
if (compute_perf > max_compute_perf) {
# 126 "sdk/cutil_inline_runtime.h"
if (best_SM_arch > 2) {
# 128 "sdk/cutil_inline_runtime.h"
if ((deviceProp.major) == best_SM_arch) {
# 129 "sdk/cutil_inline_runtime.h"
max_compute_perf = compute_perf;
# 130 "sdk/cutil_inline_runtime.h"
max_perf_device = current_device;
# 131 "sdk/cutil_inline_runtime.h"
}
# 132 "sdk/cutil_inline_runtime.h"
} else {
# 133 "sdk/cutil_inline_runtime.h"
max_compute_perf = compute_perf;
# 134 "sdk/cutil_inline_runtime.h"
max_perf_device = current_device;
# 135 "sdk/cutil_inline_runtime.h"
}
# 136 "sdk/cutil_inline_runtime.h"
}
# 137 "sdk/cutil_inline_runtime.h"
++current_device;
# 138 "sdk/cutil_inline_runtime.h"
}
# 139 "sdk/cutil_inline_runtime.h"
return max_perf_device;
# 140 "sdk/cutil_inline_runtime.h"
}
# 178 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 179 "sdk/cutil_inline_runtime.h"
{
# 180 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaSafeCallNoSync() Runtime API error : %s.\n", file, line, cudaGetErrorString(err));
# 183 "sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "sdk/cutil_inline_runtime.h"
}
# 185 "sdk/cutil_inline_runtime.h"
}
# 187 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 188 "sdk/cutil_inline_runtime.h"
{
# 189 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 190 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaSafeCall() Runtime API error : %s.\n", file, line, cudaGetErrorString(err));
# 192 "sdk/cutil_inline_runtime.h"
exit(-1);
# 193 "sdk/cutil_inline_runtime.h"
}
# 194 "sdk/cutil_inline_runtime.h"
}
# 196 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 197 "sdk/cutil_inline_runtime.h"
{
# 198 "sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 199 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 200 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaThreadSynchronize() Driver API error : %s.\n", file, line, cudaGetErrorString(err));
# 202 "sdk/cutil_inline_runtime.h"
exit(-1);
# 203 "sdk/cutil_inline_runtime.h"
}
# 204 "sdk/cutil_inline_runtime.h"
}
# 206 "sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 207 "sdk/cutil_inline_runtime.h"
{
# 208 "sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 209 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cufftSafeCall() CUFFT error.\n", file, line);
# 211 "sdk/cutil_inline_runtime.h"
exit(-1);
# 212 "sdk/cutil_inline_runtime.h"
}
# 213 "sdk/cutil_inline_runtime.h"
}
# 215 "sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 216 "sdk/cutil_inline_runtime.h"
{
# 217 "sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 218 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CUTIL CUDA error.\n", file, line);
# 220 "sdk/cutil_inline_runtime.h"
exit(-1);
# 221 "sdk/cutil_inline_runtime.h"
}
# 222 "sdk/cutil_inline_runtime.h"
}
# 224 "sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 225 "sdk/cutil_inline_runtime.h"
{
# 226 "sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 227 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 228 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cutilCheckMsg() CUTIL CUDA error : %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 230 "sdk/cutil_inline_runtime.h"
exit(-1);
# 231 "sdk/cutil_inline_runtime.h"
}
# 240 "sdk/cutil_inline_runtime.h"
}
# 241 "sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 242 "sdk/cutil_inline_runtime.h"
{
# 243 "sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 244 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cutilSafeMalloc host malloc failure\n", file, line);
# 246 "sdk/cutil_inline_runtime.h"
exit(-1);
# 247 "sdk/cutil_inline_runtime.h"
}
# 248 "sdk/cutil_inline_runtime.h"
}
# 254 "sdk/cutil_inline_runtime.h"
inline int cutilDeviceInit(int ARGC, char **ARGV)
# 255 "sdk/cutil_inline_runtime.h"
{
# 256 "sdk/cutil_inline_runtime.h"
int deviceCount;
# 257 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "sdk/cutil_inline_runtime.h", 257);
# 258 "sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 259 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 260 "sdk/cutil_inline_runtime.h"
exit(-1);
# 261 "sdk/cutil_inline_runtime.h"
}
# 262 "sdk/cutil_inline_runtime.h"
int dev = 0;
# 263 "sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 264 "sdk/cutil_inline_runtime.h"
if (dev < 0) {
# 265 "sdk/cutil_inline_runtime.h"
dev = 0; }
# 266 "sdk/cutil_inline_runtime.h"
if (dev > (deviceCount - 1)) {
# 267 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilDeviceInit (Device=%d) invalid GPU device.  %d GPU device(s) detected.\n\n", dev, deviceCount);
# 268 "sdk/cutil_inline_runtime.h"
return -dev;
# 269 "sdk/cutil_inline_runtime.h"
}
# 270 "sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 271 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "sdk/cutil_inline_runtime.h", 271);
# 272 "sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 273 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: GPU device does not support CUDA.\n");
# 274 "sdk/cutil_inline_runtime.h"
exit(-1); }
# 276 "sdk/cutil_inline_runtime.h"
printf("> Using CUDA device [%d]: %s\n", dev, deviceProp.name);
# 277 "sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "sdk/cutil_inline_runtime.h", 277);
# 279 "sdk/cutil_inline_runtime.h"
return dev;
# 280 "sdk/cutil_inline_runtime.h"
}
# 283 "sdk/cutil_inline_runtime.h"
inline int cutilChooseCudaDevice(int argc, char **argv)
# 284 "sdk/cutil_inline_runtime.h"
{
# 285 "sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 286 "sdk/cutil_inline_runtime.h"
int devID = 0;
# 288 "sdk/cutil_inline_runtime.h"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 289 "sdk/cutil_inline_runtime.h"
devID = cutilDeviceInit(argc, argv);
# 290 "sdk/cutil_inline_runtime.h"
if (devID < 0) {
# 291 "sdk/cutil_inline_runtime.h"
printf("exiting...\n");
# 292 "sdk/cutil_inline_runtime.h"
__cutilExit(argc, argv);
# 293 "sdk/cutil_inline_runtime.h"
exit(0);
# 294 "sdk/cutil_inline_runtime.h"
}
# 295 "sdk/cutil_inline_runtime.h"
} else {
# 297 "sdk/cutil_inline_runtime.h"
devID = cutGetMaxGflopsDeviceId();
# 298 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaSetDevice(devID), "sdk/cutil_inline_runtime.h", 298);
# 299 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, devID), "sdk/cutil_inline_runtime.h", 299);
# 300 "sdk/cutil_inline_runtime.h"
printf("> Using CUDA device [%d]: %s\n", devID, deviceProp.name);
# 301 "sdk/cutil_inline_runtime.h"
}
# 302 "sdk/cutil_inline_runtime.h"
return devID;
# 303 "sdk/cutil_inline_runtime.h"
}
# 308 "sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 309 "sdk/cutil_inline_runtime.h"
{
# 310 "sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 311 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 312 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CUDA error: %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 314 "sdk/cutil_inline_runtime.h"
exit(-1);
# 315 "sdk/cutil_inline_runtime.h"
}
# 316 "sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 317 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 318 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CCUDA error: %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 320 "sdk/cutil_inline_runtime.h"
exit(-1);
# 321 "sdk/cutil_inline_runtime.h"
}
# 322 "sdk/cutil_inline_runtime.h"
}
# 325 "sdk/cutil_inline_runtime.h"
inline bool cutilCudaCapabilities(int major_version, int minor_version)
# 326 "sdk/cutil_inline_runtime.h"
{
# 327 "sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 328 "sdk/cutil_inline_runtime.h"
(deviceProp.major) = 0;
# 329 "sdk/cutil_inline_runtime.h"
(deviceProp.minor) = 0;
# 330 "sdk/cutil_inline_runtime.h"
int dev;
# 336 "sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaGetDevice(&dev), "sdk/cutil_inline_runtime.h", 336);
# 337 "sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaGetDeviceProperties(&deviceProp, dev), "sdk/cutil_inline_runtime.h", 337);
# 339 "sdk/cutil_inline_runtime.h"
if (((deviceProp.major) > major_version) || (((deviceProp.major) == major_version) && ((deviceProp.minor) >= minor_version)))
# 341 "sdk/cutil_inline_runtime.h"
{
# 342 "sdk/cutil_inline_runtime.h"
printf("> Device %d: <%16s >, Compute SM %d.%d detected\n", dev, deviceProp.name, deviceProp.major, deviceProp.minor);
# 343 "sdk/cutil_inline_runtime.h"
return true;
# 344 "sdk/cutil_inline_runtime.h"
} else
# 346 "sdk/cutil_inline_runtime.h"
{
# 347 "sdk/cutil_inline_runtime.h"
printf("There is no device supporting CUDA compute capability %d.%d.\n", major_version, minor_version);
# 348 "sdk/cutil_inline_runtime.h"
printf("PASSED\n");
# 349 "sdk/cutil_inline_runtime.h"
return false;
# 350 "sdk/cutil_inline_runtime.h"
}
# 351 "sdk/cutil_inline_runtime.h"
}
# 32 "sdk/cutil_inline_drvapi.h"
inline int _ConvertSMVer2CoresDrvApi(int major, int minor)
# 33 "sdk/cutil_inline_drvapi.h"
{
# 38 "sdk/cutil_inline_drvapi.h"
typedef
# 35 "sdk/cutil_inline_drvapi.h"
struct {
# 36 "sdk/cutil_inline_drvapi.h"
int SM;
# 37 "sdk/cutil_inline_drvapi.h"
int Cores;
# 38 "sdk/cutil_inline_drvapi.h"
} sSMtoCores;
# 40 "sdk/cutil_inline_drvapi.h"
sSMtoCores nGpuArchCoresPerSM[] = {{16, 8}, {17, 8}, {18, 8}, {19, 8}, {32, 32}, {33, 48}, {(-1), (-1)}};
# 50 "sdk/cutil_inline_drvapi.h"
int index = 0;
# 51 "sdk/cutil_inline_drvapi.h"
while ((((nGpuArchCoresPerSM)[index]).SM) != (-1)) {
# 52 "sdk/cutil_inline_drvapi.h"
if ((((nGpuArchCoresPerSM)[index]).SM) == ((major << 4) + minor)) {
# 53 "sdk/cutil_inline_drvapi.h"
return ((nGpuArchCoresPerSM)[index]).Cores;
# 54 "sdk/cutil_inline_drvapi.h"
}
# 55 "sdk/cutil_inline_drvapi.h"
index++;
# 56 "sdk/cutil_inline_drvapi.h"
}
# 57 "sdk/cutil_inline_drvapi.h"
printf("MapSMtoCores undefined SMversion %d.%d!\n", major, minor);
# 58 "sdk/cutil_inline_drvapi.h"
return -1;
# 59 "sdk/cutil_inline_drvapi.h"
}
# 63 "sdk/cutil_inline_drvapi.h"
inline int cutilDrvGetMaxGflopsDeviceId()
# 64 "sdk/cutil_inline_drvapi.h"
{
# 65 "sdk/cutil_inline_drvapi.h"
CUdevice current_device = 0, max_perf_device = 0;
# 66 "sdk/cutil_inline_drvapi.h"
int device_count = 0, sm_per_multiproc = 0;
# 67 "sdk/cutil_inline_drvapi.h"
int max_compute_perf = 0, best_SM_arch = 0;
# 68 "sdk/cutil_inline_drvapi.h"
int major = 0, minor = 0, multiProcessorCount, clockRate;
# 70 "sdk/cutil_inline_drvapi.h"
cuInit(0);
# 71 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetCount(&device_count); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 71); exit(1); } } ;
# 74 "sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 75 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 75); exit(1); } } ;
# 76 "sdk/cutil_inline_drvapi.h"
if ((major > 0) && (major < 9999)) {
# 77 "sdk/cutil_inline_drvapi.h"
best_SM_arch = ((best_SM_arch > major) ? best_SM_arch : major);
# 78 "sdk/cutil_inline_drvapi.h"
}
# 79 "sdk/cutil_inline_drvapi.h"
current_device++;
# 80 "sdk/cutil_inline_drvapi.h"
}
# 83 "sdk/cutil_inline_drvapi.h"
current_device = 0;
# 84 "sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 85 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 87); exit(1); } } ;
# 88 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 90); exit(1); } } ;
# 91 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 91); exit(1); } } ;
# 93 "sdk/cutil_inline_drvapi.h"
if ((major == 9999) && (minor == 9999)) {
# 94 "sdk/cutil_inline_drvapi.h"
sm_per_multiproc = 1;
# 95 "sdk/cutil_inline_drvapi.h"
} else {
# 96 "sdk/cutil_inline_drvapi.h"
sm_per_multiproc = _ConvertSMVer2CoresDrvApi(major, minor);
# 97 "sdk/cutil_inline_drvapi.h"
}
# 99 "sdk/cutil_inline_drvapi.h"
int compute_perf = ((multiProcessorCount * sm_per_multiproc) * clockRate);
# 100 "sdk/cutil_inline_drvapi.h"
if (compute_perf > max_compute_perf) {
# 102 "sdk/cutil_inline_drvapi.h"
if (best_SM_arch > 2) {
# 104 "sdk/cutil_inline_drvapi.h"
if (major == best_SM_arch) {
# 105 "sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 106 "sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 107 "sdk/cutil_inline_drvapi.h"
}
# 108 "sdk/cutil_inline_drvapi.h"
} else {
# 109 "sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 110 "sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 111 "sdk/cutil_inline_drvapi.h"
}
# 112 "sdk/cutil_inline_drvapi.h"
}
# 113 "sdk/cutil_inline_drvapi.h"
++current_device;
# 114 "sdk/cutil_inline_drvapi.h"
}
# 115 "sdk/cutil_inline_drvapi.h"
return max_perf_device;
# 116 "sdk/cutil_inline_drvapi.h"
}
# 119 "sdk/cutil_inline_drvapi.h"
inline int cutilDrvGetMaxGflopsGraphicsDeviceId()
# 120 "sdk/cutil_inline_drvapi.h"
{
# 121 "sdk/cutil_inline_drvapi.h"
CUdevice current_device = 0, max_perf_device = 0;
# 122 "sdk/cutil_inline_drvapi.h"
int device_count = 0, sm_per_multiproc = 0;
# 123 "sdk/cutil_inline_drvapi.h"
int max_compute_perf = 0, best_SM_arch = 0;
# 124 "sdk/cutil_inline_drvapi.h"
int major = 0, minor = 0, multiProcessorCount, clockRate;
# 125 "sdk/cutil_inline_drvapi.h"
int bTCC = 0;
# 126 "sdk/cutil_inline_drvapi.h"
char deviceName[256];
# 128 "sdk/cutil_inline_drvapi.h"
cuInit(0);
# 129 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetCount(&device_count); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 129); exit(1); } } ;
# 132 "sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 133 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetName(deviceName, 256, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 133); exit(1); } } ;
# 134 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 134); exit(1); } } ;
# 136 "sdk/cutil_inline_drvapi.h"
if ((major > 0) && (major < 9999)) {
# 137 "sdk/cutil_inline_drvapi.h"
best_SM_arch = ((best_SM_arch > major) ? best_SM_arch : major);
# 138 "sdk/cutil_inline_drvapi.h"
}
# 139 "sdk/cutil_inline_drvapi.h"
current_device++;
# 140 "sdk/cutil_inline_drvapi.h"
}
# 143 "sdk/cutil_inline_drvapi.h"
current_device = 0;
# 144 "sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 145 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 147); exit(1); } } ;
# 148 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 150); exit(1); } } ;
# 151 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 151); exit(1); } } ;
# 154 "sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&bTCC, CU_DEVICE_ATTRIBUTE_TCC_DRIVER, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "sdk/cutil_inline_drvapi.h", 154); exit(1); } } ;
# 160 "sdk/cutil_inline_drvapi.h"
if ((major == 9999) && (minor == 9999)) {
# 161 "sdk/cutil_inline_drvapi.h"
sm_per_multiproc = 1;
# 162 "sdk/cutil_inline_drvapi.h"
} else {
# 163 "sdk/cutil_inline_drvapi.h"
sm_per_multiproc = _ConvertSMVer2CoresDrvApi(major, minor);
# 164 "sdk/cutil_inline_drvapi.h"
}
# 167 "sdk/cutil_inline_drvapi.h"
if ((major >= 2) && (!(bTCC)))
# 168 "sdk/cutil_inline_drvapi.h"
{
# 169 "sdk/cutil_inline_drvapi.h"
int compute_perf = ((multiProcessorCount * sm_per_multiproc) * clockRate);
# 170 "sdk/cutil_inline_drvapi.h"
if (compute_perf > max_compute_perf) {
# 172 "sdk/cutil_inline_drvapi.h"
if (best_SM_arch > 2) {
# 174 "sdk/cutil_inline_drvapi.h"
if (major == best_SM_arch) {
# 175 "sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 176 "sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 177 "sdk/cutil_inline_drvapi.h"
}
# 178 "sdk/cutil_inline_drvapi.h"
} else {
# 179 "sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 180 "sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 181 "sdk/cutil_inline_drvapi.h"
}
# 182 "sdk/cutil_inline_drvapi.h"
}
# 183 "sdk/cutil_inline_drvapi.h"
}
# 184 "sdk/cutil_inline_drvapi.h"
++current_device;
# 185 "sdk/cutil_inline_drvapi.h"
}
# 186 "sdk/cutil_inline_drvapi.h"
return max_perf_device;
# 187 "sdk/cutil_inline_drvapi.h"
}
# 190 "sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 191 "sdk/cutil_inline_drvapi.h"
{
# 192 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 193 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 195 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 196 "sdk/cutil_inline_drvapi.h"
}
# 197 "sdk/cutil_inline_drvapi.h"
}
# 198 "sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 199 "sdk/cutil_inline_drvapi.h"
{
# 200 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 201 "sdk/cutil_inline_drvapi.h"
}
# 203 "sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 204 "sdk/cutil_inline_drvapi.h"
{
# 205 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 206 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 207 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 209 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 210 "sdk/cutil_inline_drvapi.h"
}
# 211 "sdk/cutil_inline_drvapi.h"
}
# 213 "sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 214 "sdk/cutil_inline_drvapi.h"
{
# 215 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 216 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 217 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 218 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 220 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 221 "sdk/cutil_inline_drvapi.h"
}
# 222 "sdk/cutil_inline_drvapi.h"
}
# 228 "sdk/cutil_inline_drvapi.h"
inline int cutilDeviceInitDrv(int ARGC, char **ARGV)
# 229 "sdk/cutil_inline_drvapi.h"
{
# 230 "sdk/cutil_inline_drvapi.h"
int cuDevice = 0;
# 231 "sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 232 "sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 233 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 234 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "sdk/cutil_inline_drvapi.h", 234); }
# 235 "sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 236 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 237 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 238 "sdk/cutil_inline_drvapi.h"
}
# 239 "sdk/cutil_inline_drvapi.h"
int dev = 0;
# 240 "sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 241 "sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 242 "sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) {
# 243 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDeviceInitDrv (Device=%d) invalid GPU device.  %d GPU device(s) detected.\n\n", dev, deviceCount);
# 244 "sdk/cutil_inline_drvapi.h"
return -dev;
# 245 "sdk/cutil_inline_drvapi.h"
}
# 246 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "sdk/cutil_inline_drvapi.h", 246);
# 247 "sdk/cutil_inline_drvapi.h"
char name[100];
# 248 "sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 249 "sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 250 "sdk/cutil_inline_drvapi.h"
printf("> Using CUDA Device [%d]: %s\n", dev, name);
# 251 "sdk/cutil_inline_drvapi.h"
}
# 252 "sdk/cutil_inline_drvapi.h"
return dev;
# 253 "sdk/cutil_inline_drvapi.h"
}
# 260 "sdk/cutil_inline_drvapi.h"
inline CUdevice cutilChooseCudaDeviceDrv(int argc, char **argv, int *p_devID)
# 261 "sdk/cutil_inline_drvapi.h"
{
# 262 "sdk/cutil_inline_drvapi.h"
CUdevice cuDevice;
# 263 "sdk/cutil_inline_drvapi.h"
int devID = 0;
# 265 "sdk/cutil_inline_drvapi.h"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 266 "sdk/cutil_inline_drvapi.h"
devID = cutilDeviceInitDrv(argc, argv);
# 267 "sdk/cutil_inline_drvapi.h"
if (devID < 0) {
# 268 "sdk/cutil_inline_drvapi.h"
printf("exiting...\n");
# 269 "sdk/cutil_inline_drvapi.h"
exit(0);
# 270 "sdk/cutil_inline_drvapi.h"
}
# 271 "sdk/cutil_inline_drvapi.h"
} else {
# 273 "sdk/cutil_inline_drvapi.h"
char name[100];
# 274 "sdk/cutil_inline_drvapi.h"
devID = cutilDrvGetMaxGflopsDeviceId();
# 275 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, devID), "sdk/cutil_inline_drvapi.h", 275);
# 276 "sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 277 "sdk/cutil_inline_drvapi.h"
printf("> Using CUDA Device [%d]: %s\n", devID, name);
# 278 "sdk/cutil_inline_drvapi.h"
}
# 279 "sdk/cutil_inline_drvapi.h"
cuDeviceGet(&cuDevice, devID);
# 280 "sdk/cutil_inline_drvapi.h"
if (p_devID) { (*p_devID) = devID; }
# 281 "sdk/cutil_inline_drvapi.h"
return cuDevice;
# 282 "sdk/cutil_inline_drvapi.h"
}
# 287 "sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 288 "sdk/cutil_inline_drvapi.h"
{
# 289 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 290 "sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 291 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 293 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 294 "sdk/cutil_inline_drvapi.h"
}
# 295 "sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 296 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 297 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 299 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 300 "sdk/cutil_inline_drvapi.h"
}
# 301 "sdk/cutil_inline_drvapi.h"
}
# 304 "sdk/cutil_inline_drvapi.h"
inline bool cutilDrvCudaDevCapabilities(int major_version, int minor_version, int deviceNum)
# 305 "sdk/cutil_inline_drvapi.h"
{
# 306 "sdk/cutil_inline_drvapi.h"
int major, minor, dev;
# 307 "sdk/cutil_inline_drvapi.h"
char device_name[256];
# 313 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&dev, deviceNum), "sdk/cutil_inline_drvapi.h", 313);
# 314 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceComputeCapability(&major, &minor, dev), "sdk/cutil_inline_drvapi.h", 314);
# 315 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetName(device_name, 256, dev), "sdk/cutil_inline_drvapi.h", 315);
# 317 "sdk/cutil_inline_drvapi.h"
if ((major > major_version) || ((major == major_version) && (minor >= minor_version)))
# 319 "sdk/cutil_inline_drvapi.h"
{
# 320 "sdk/cutil_inline_drvapi.h"
printf("> Device %d: < %s >, Compute SM %d.%d detected\n", dev, device_name, major, minor);
# 321 "sdk/cutil_inline_drvapi.h"
return true;
# 322 "sdk/cutil_inline_drvapi.h"
} else
# 324 "sdk/cutil_inline_drvapi.h"
{
# 325 "sdk/cutil_inline_drvapi.h"
printf("There is no device supporting CUDA compute capability %d.%d.\n", major_version, minor_version);
# 326 "sdk/cutil_inline_drvapi.h"
printf("PASSED\n");
# 327 "sdk/cutil_inline_drvapi.h"
return false;
# 328 "sdk/cutil_inline_drvapi.h"
}
# 329 "sdk/cutil_inline_drvapi.h"
}
# 332 "sdk/cutil_inline_drvapi.h"
inline bool cutilDrvCudaCapabilities(int major_version, int minor_version)
# 333 "sdk/cutil_inline_drvapi.h"
{
# 334 "sdk/cutil_inline_drvapi.h"
return cutilDrvCudaDevCapabilities(major_version, minor_version, 0);
# 335 "sdk/cutil_inline_drvapi.h"
}
# 23 "sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 24 "sdk/cutil_inline.h"
{
# 25 "sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 3020 / 1000, 3020 % 100);
# 26 "sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 27 "sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 28 "sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 29 "sdk/cutil_inline.h"
}
# 28 "sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 29 "sdk/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 68 "sdk/cutil_math.h"
inline float2 make_float2(float s)
# 69 "sdk/cutil_math.h"
{
# 70 "sdk/cutil_math.h"
return make_float2(s, s);
# 71 "sdk/cutil_math.h"
}
# 72 "sdk/cutil_math.h"
inline float2 make_float2(float3 a)
# 73 "sdk/cutil_math.h"
{
# 74 "sdk/cutil_math.h"
return make_float2(a.x, a.y);
# 75 "sdk/cutil_math.h"
}
# 76 "sdk/cutil_math.h"
inline float2 make_float2(int2 a)
# 77 "sdk/cutil_math.h"
{
# 78 "sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 79 "sdk/cutil_math.h"
}
# 80 "sdk/cutil_math.h"
inline float2 make_float2(uint2 a)
# 81 "sdk/cutil_math.h"
{
# 82 "sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 83 "sdk/cutil_math.h"
}
# 85 "sdk/cutil_math.h"
inline int2 make_int2(int s)
# 86 "sdk/cutil_math.h"
{
# 87 "sdk/cutil_math.h"
return make_int2(s, s);
# 88 "sdk/cutil_math.h"
}
# 89 "sdk/cutil_math.h"
inline int2 make_int2(int3 a)
# 90 "sdk/cutil_math.h"
{
# 91 "sdk/cutil_math.h"
return make_int2(a.x, a.y);
# 92 "sdk/cutil_math.h"
}
# 93 "sdk/cutil_math.h"
inline int2 make_int2(uint2 a)
# 94 "sdk/cutil_math.h"
{
# 95 "sdk/cutil_math.h"
return make_int2((int)(a.x), (int)(a.y));
# 96 "sdk/cutil_math.h"
}
# 97 "sdk/cutil_math.h"
inline int2 make_int2(float2 a)
# 98 "sdk/cutil_math.h"
{
# 99 "sdk/cutil_math.h"
return make_int2((int)(a.x), (int)(a.y));
# 100 "sdk/cutil_math.h"
}
# 102 "sdk/cutil_math.h"
inline uint2 make_uint2(uint s)
# 103 "sdk/cutil_math.h"
{
# 104 "sdk/cutil_math.h"
return make_uint2(s, s);
# 105 "sdk/cutil_math.h"
}
# 106 "sdk/cutil_math.h"
inline uint2 make_uint2(uint3 a)
# 107 "sdk/cutil_math.h"
{
# 108 "sdk/cutil_math.h"
return make_uint2(a.x, a.y);
# 109 "sdk/cutil_math.h"
}
# 110 "sdk/cutil_math.h"
inline uint2 make_uint2(int2 a)
# 111 "sdk/cutil_math.h"
{
# 112 "sdk/cutil_math.h"
return make_uint2((uint)(a.x), (uint)(a.y));
# 113 "sdk/cutil_math.h"
}
# 115 "sdk/cutil_math.h"
inline float3 make_float3(float s)
# 116 "sdk/cutil_math.h"
{
# 117 "sdk/cutil_math.h"
return make_float3(s, s, s);
# 118 "sdk/cutil_math.h"
}
# 119 "sdk/cutil_math.h"
inline float3 make_float3(float2 a)
# 120 "sdk/cutil_math.h"
{
# 121 "sdk/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 122 "sdk/cutil_math.h"
}
# 123 "sdk/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 124 "sdk/cutil_math.h"
{
# 125 "sdk/cutil_math.h"
return make_float3(a.x, a.y, s);
# 126 "sdk/cutil_math.h"
}
# 127 "sdk/cutil_math.h"
inline float3 make_float3(float4 a)
# 128 "sdk/cutil_math.h"
{
# 129 "sdk/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 130 "sdk/cutil_math.h"
}
# 131 "sdk/cutil_math.h"
inline float3 make_float3(int3 a)
# 132 "sdk/cutil_math.h"
{
# 133 "sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 134 "sdk/cutil_math.h"
}
# 135 "sdk/cutil_math.h"
inline float3 make_float3(uint3 a)
# 136 "sdk/cutil_math.h"
{
# 137 "sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 138 "sdk/cutil_math.h"
}
# 140 "sdk/cutil_math.h"
inline int3 make_int3(int s)
# 141 "sdk/cutil_math.h"
{
# 142 "sdk/cutil_math.h"
return make_int3(s, s, s);
# 143 "sdk/cutil_math.h"
}
# 144 "sdk/cutil_math.h"
inline int3 make_int3(int2 a)
# 145 "sdk/cutil_math.h"
{
# 146 "sdk/cutil_math.h"
return make_int3(a.x, a.y, 0);
# 147 "sdk/cutil_math.h"
}
# 148 "sdk/cutil_math.h"
inline int3 make_int3(int2 a, int s)
# 149 "sdk/cutil_math.h"
{
# 150 "sdk/cutil_math.h"
return make_int3(a.x, a.y, s);
# 151 "sdk/cutil_math.h"
}
# 152 "sdk/cutil_math.h"
inline int3 make_int3(uint3 a)
# 153 "sdk/cutil_math.h"
{
# 154 "sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 155 "sdk/cutil_math.h"
}
# 156 "sdk/cutil_math.h"
inline int3 make_int3(float3 a)
# 157 "sdk/cutil_math.h"
{
# 158 "sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 159 "sdk/cutil_math.h"
}
# 161 "sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
# 162 "sdk/cutil_math.h"
{
# 163 "sdk/cutil_math.h"
return make_uint3(s, s, s);
# 164 "sdk/cutil_math.h"
}
# 165 "sdk/cutil_math.h"
inline uint3 make_uint3(uint2 a)
# 166 "sdk/cutil_math.h"
{
# 167 "sdk/cutil_math.h"
return make_uint3(a.x, a.y, 0);
# 168 "sdk/cutil_math.h"
}
# 169 "sdk/cutil_math.h"
inline uint3 make_uint3(uint2 a, uint s)
# 170 "sdk/cutil_math.h"
{
# 171 "sdk/cutil_math.h"
return make_uint3(a.x, a.y, s);
# 172 "sdk/cutil_math.h"
}
# 173 "sdk/cutil_math.h"
inline uint3 make_uint3(uint4 a)
# 174 "sdk/cutil_math.h"
{
# 175 "sdk/cutil_math.h"
return make_uint3(a.x, a.y, a.z);
# 176 "sdk/cutil_math.h"
}
# 177 "sdk/cutil_math.h"
inline uint3 make_uint3(int3 a)
# 178 "sdk/cutil_math.h"
{
# 179 "sdk/cutil_math.h"
return make_uint3((uint)(a.x), (uint)(a.y), (uint)(a.z));
# 180 "sdk/cutil_math.h"
}
# 182 "sdk/cutil_math.h"
inline float4 make_float4(float s)
# 183 "sdk/cutil_math.h"
{
# 184 "sdk/cutil_math.h"
return make_float4(s, s, s, s);
# 185 "sdk/cutil_math.h"
}
# 186 "sdk/cutil_math.h"
inline float4 make_float4(float3 a)
# 187 "sdk/cutil_math.h"
{
# 188 "sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 189 "sdk/cutil_math.h"
}
# 190 "sdk/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 191 "sdk/cutil_math.h"
{
# 192 "sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 193 "sdk/cutil_math.h"
}
# 194 "sdk/cutil_math.h"
inline float4 make_float4(int4 a)
# 195 "sdk/cutil_math.h"
{
# 196 "sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 197 "sdk/cutil_math.h"
}
# 198 "sdk/cutil_math.h"
inline float4 make_float4(uint4 a)
# 199 "sdk/cutil_math.h"
{
# 200 "sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 201 "sdk/cutil_math.h"
}
# 203 "sdk/cutil_math.h"
inline int4 make_int4(int s)
# 204 "sdk/cutil_math.h"
{
# 205 "sdk/cutil_math.h"
return make_int4(s, s, s, s);
# 206 "sdk/cutil_math.h"
}
# 207 "sdk/cutil_math.h"
inline int4 make_int4(int3 a)
# 208 "sdk/cutil_math.h"
{
# 209 "sdk/cutil_math.h"
return make_int4(a.x, a.y, a.z, 0);
# 210 "sdk/cutil_math.h"
}
# 211 "sdk/cutil_math.h"
inline int4 make_int4(int3 a, int w)
# 212 "sdk/cutil_math.h"
{
# 213 "sdk/cutil_math.h"
return make_int4(a.x, a.y, a.z, w);
# 214 "sdk/cutil_math.h"
}
# 215 "sdk/cutil_math.h"
inline int4 make_int4(uint4 a)
# 216 "sdk/cutil_math.h"
{
# 217 "sdk/cutil_math.h"
return make_int4((int)(a.x), (int)(a.y), (int)(a.z), (int)(a.w));
# 218 "sdk/cutil_math.h"
}
# 219 "sdk/cutil_math.h"
inline int4 make_int4(float4 a)
# 220 "sdk/cutil_math.h"
{
# 221 "sdk/cutil_math.h"
return make_int4((int)(a.x), (int)(a.y), (int)(a.z), (int)(a.w));
# 222 "sdk/cutil_math.h"
}
# 225 "sdk/cutil_math.h"
inline uint4 make_uint4(uint s)
# 226 "sdk/cutil_math.h"
{
# 227 "sdk/cutil_math.h"
return make_uint4(s, s, s, s);
# 228 "sdk/cutil_math.h"
}
# 229 "sdk/cutil_math.h"
inline uint4 make_uint4(uint3 a)
# 230 "sdk/cutil_math.h"
{
# 231 "sdk/cutil_math.h"
return make_uint4(a.x, a.y, a.z, 0);
# 232 "sdk/cutil_math.h"
}
# 233 "sdk/cutil_math.h"
inline uint4 make_uint4(uint3 a, uint w)
# 234 "sdk/cutil_math.h"
{
# 235 "sdk/cutil_math.h"
return make_uint4(a.x, a.y, a.z, w);
# 236 "sdk/cutil_math.h"
}
# 237 "sdk/cutil_math.h"
inline uint4 make_uint4(int4 a)
# 238 "sdk/cutil_math.h"
{
# 239 "sdk/cutil_math.h"
return make_uint4((uint)(a.x), (uint)(a.y), (uint)(a.z), (uint)(a.w));
# 240 "sdk/cutil_math.h"
}
# 246 "sdk/cutil_math.h"
inline float2 operator-(float2 &a)
# 247 "sdk/cutil_math.h"
{
# 248 "sdk/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 249 "sdk/cutil_math.h"
}
# 250 "sdk/cutil_math.h"
inline int2 operator-(int2 &a)
# 251 "sdk/cutil_math.h"
{
# 252 "sdk/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 253 "sdk/cutil_math.h"
}
# 254 "sdk/cutil_math.h"
inline float3 operator-(float3 &a)
# 255 "sdk/cutil_math.h"
{
# 256 "sdk/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 257 "sdk/cutil_math.h"
}
# 258 "sdk/cutil_math.h"
inline int3 operator-(int3 &a)
# 259 "sdk/cutil_math.h"
{
# 260 "sdk/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 261 "sdk/cutil_math.h"
}
# 262 "sdk/cutil_math.h"
inline float4 operator-(float4 &a)
# 263 "sdk/cutil_math.h"
{
# 264 "sdk/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 265 "sdk/cutil_math.h"
}
# 266 "sdk/cutil_math.h"
inline int4 operator-(int4 &a)
# 267 "sdk/cutil_math.h"
{
# 268 "sdk/cutil_math.h"
return make_int4(-(a.x), -(a.y), -(a.z), -(a.w));
# 269 "sdk/cutil_math.h"
}
# 275 "sdk/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 276 "sdk/cutil_math.h"
{
# 277 "sdk/cutil_math.h"
return make_float2((a.x) + (b.x), (a.y) + (b.y));
# 278 "sdk/cutil_math.h"
}
# 279 "sdk/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 280 "sdk/cutil_math.h"
{
# 281 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 282 "sdk/cutil_math.h"
}
# 283 "sdk/cutil_math.h"
inline float2 operator+(float2 a, float b)
# 284 "sdk/cutil_math.h"
{
# 285 "sdk/cutil_math.h"
return make_float2((a.x) + b, (a.y) + b);
# 286 "sdk/cutil_math.h"
}
# 287 "sdk/cutil_math.h"
inline float2 operator+(float b, float2 a)
# 288 "sdk/cutil_math.h"
{
# 289 "sdk/cutil_math.h"
return make_float2((a.x) + b, (a.y) + b);
# 290 "sdk/cutil_math.h"
}
# 291 "sdk/cutil_math.h"
inline void operator+=(float2 &a, float b)
# 292 "sdk/cutil_math.h"
{
# 293 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b;
# 294 "sdk/cutil_math.h"
}
# 296 "sdk/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 297 "sdk/cutil_math.h"
{
# 298 "sdk/cutil_math.h"
return make_int2((a.x) + (b.x), (a.y) + (b.y));
# 299 "sdk/cutil_math.h"
}
# 300 "sdk/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 301 "sdk/cutil_math.h"
{
# 302 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 303 "sdk/cutil_math.h"
}
# 304 "sdk/cutil_math.h"
inline int2 operator+(int2 a, int b)
# 305 "sdk/cutil_math.h"
{
# 306 "sdk/cutil_math.h"
return make_int2((a.x) + b, (a.y) + b);
# 307 "sdk/cutil_math.h"
}
# 308 "sdk/cutil_math.h"
inline int2 operator+(int b, int2 a)
# 309 "sdk/cutil_math.h"
{
# 310 "sdk/cutil_math.h"
return make_int2((a.x) + b, (a.y) + b);
# 311 "sdk/cutil_math.h"
}
# 312 "sdk/cutil_math.h"
inline void operator+=(int2 &a, int b)
# 313 "sdk/cutil_math.h"
{
# 314 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b;
# 315 "sdk/cutil_math.h"
}
# 317 "sdk/cutil_math.h"
inline uint2 operator+(uint2 a, uint2 b)
# 318 "sdk/cutil_math.h"
{
# 319 "sdk/cutil_math.h"
return make_uint2((a.x) + (b.x), (a.y) + (b.y));
# 320 "sdk/cutil_math.h"
}
# 321 "sdk/cutil_math.h"
inline void operator+=(uint2 &a, uint2 b)
# 322 "sdk/cutil_math.h"
{
# 323 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 324 "sdk/cutil_math.h"
}
# 325 "sdk/cutil_math.h"
inline uint2 operator+(uint2 a, uint b)
# 326 "sdk/cutil_math.h"
{
# 327 "sdk/cutil_math.h"
return make_uint2((a.x) + b, (a.y) + b);
# 328 "sdk/cutil_math.h"
}
# 329 "sdk/cutil_math.h"
inline uint2 operator+(uint b, uint2 a)
# 330 "sdk/cutil_math.h"
{
# 331 "sdk/cutil_math.h"
return make_uint2((a.x) + b, (a.y) + b);
# 332 "sdk/cutil_math.h"
}
# 333 "sdk/cutil_math.h"
inline void operator+=(uint2 &a, uint b)
# 334 "sdk/cutil_math.h"
{
# 335 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b;
# 336 "sdk/cutil_math.h"
}
# 339 "sdk/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 340 "sdk/cutil_math.h"
{
# 341 "sdk/cutil_math.h"
return make_float3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 342 "sdk/cutil_math.h"
}
# 343 "sdk/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 344 "sdk/cutil_math.h"
{
# 345 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 346 "sdk/cutil_math.h"
}
# 347 "sdk/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 348 "sdk/cutil_math.h"
{
# 349 "sdk/cutil_math.h"
return make_float3((a.x) + b, (a.y) + b, (a.z) + b);
# 350 "sdk/cutil_math.h"
}
# 351 "sdk/cutil_math.h"
inline void operator+=(float3 &a, float b)
# 352 "sdk/cutil_math.h"
{
# 353 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b;
# 354 "sdk/cutil_math.h"
}
# 356 "sdk/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 357 "sdk/cutil_math.h"
{
# 358 "sdk/cutil_math.h"
return make_int3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 359 "sdk/cutil_math.h"
}
# 360 "sdk/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 361 "sdk/cutil_math.h"
{
# 362 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 363 "sdk/cutil_math.h"
}
# 364 "sdk/cutil_math.h"
inline int3 operator+(int3 a, int b)
# 365 "sdk/cutil_math.h"
{
# 366 "sdk/cutil_math.h"
return make_int3((a.x) + b, (a.y) + b, (a.z) + b);
# 367 "sdk/cutil_math.h"
}
# 368 "sdk/cutil_math.h"
inline void operator+=(int3 &a, int b)
# 369 "sdk/cutil_math.h"
{
# 370 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b;
# 371 "sdk/cutil_math.h"
}
# 373 "sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 374 "sdk/cutil_math.h"
{
# 375 "sdk/cutil_math.h"
return make_uint3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 376 "sdk/cutil_math.h"
}
# 377 "sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 378 "sdk/cutil_math.h"
{
# 379 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 380 "sdk/cutil_math.h"
}
# 381 "sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint b)
# 382 "sdk/cutil_math.h"
{
# 383 "sdk/cutil_math.h"
return make_uint3((a.x) + b, (a.y) + b, (a.z) + b);
# 384 "sdk/cutil_math.h"
}
# 385 "sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint b)
# 386 "sdk/cutil_math.h"
{
# 387 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b;
# 388 "sdk/cutil_math.h"
}
# 390 "sdk/cutil_math.h"
inline int3 operator+(int b, int3 a)
# 391 "sdk/cutil_math.h"
{
# 392 "sdk/cutil_math.h"
return make_int3((a.x) + b, (a.y) + b, (a.z) + b);
# 393 "sdk/cutil_math.h"
}
# 394 "sdk/cutil_math.h"
inline uint3 operator+(uint b, uint3 a)
# 395 "sdk/cutil_math.h"
{
# 396 "sdk/cutil_math.h"
return make_uint3((a.x) + b, (a.y) + b, (a.z) + b);
# 397 "sdk/cutil_math.h"
}
# 398 "sdk/cutil_math.h"
inline float3 operator+(float b, float3 a)
# 399 "sdk/cutil_math.h"
{
# 400 "sdk/cutil_math.h"
return make_float3((a.x) + b, (a.y) + b, (a.z) + b);
# 401 "sdk/cutil_math.h"
}
# 403 "sdk/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 404 "sdk/cutil_math.h"
{
# 405 "sdk/cutil_math.h"
return make_float4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 406 "sdk/cutil_math.h"
}
# 407 "sdk/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 408 "sdk/cutil_math.h"
{
# 409 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 410 "sdk/cutil_math.h"
}
# 411 "sdk/cutil_math.h"
inline float4 operator+(float4 a, float b)
# 412 "sdk/cutil_math.h"
{
# 413 "sdk/cutil_math.h"
return make_float4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 414 "sdk/cutil_math.h"
}
# 415 "sdk/cutil_math.h"
inline float4 operator+(float b, float4 a)
# 416 "sdk/cutil_math.h"
{
# 417 "sdk/cutil_math.h"
return make_float4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 418 "sdk/cutil_math.h"
}
# 419 "sdk/cutil_math.h"
inline void operator+=(float4 &a, float b)
# 420 "sdk/cutil_math.h"
{
# 421 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b; (a.w) += b;
# 422 "sdk/cutil_math.h"
}
# 424 "sdk/cutil_math.h"
inline int4 operator+(int4 a, int4 b)
# 425 "sdk/cutil_math.h"
{
# 426 "sdk/cutil_math.h"
return make_int4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 427 "sdk/cutil_math.h"
}
# 428 "sdk/cutil_math.h"
inline void operator+=(int4 &a, int4 b)
# 429 "sdk/cutil_math.h"
{
# 430 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 431 "sdk/cutil_math.h"
}
# 432 "sdk/cutil_math.h"
inline int4 operator+(int4 a, int b)
# 433 "sdk/cutil_math.h"
{
# 434 "sdk/cutil_math.h"
return make_int4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 435 "sdk/cutil_math.h"
}
# 436 "sdk/cutil_math.h"
inline int4 operator+(int b, int4 a)
# 437 "sdk/cutil_math.h"
{
# 438 "sdk/cutil_math.h"
return make_int4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 439 "sdk/cutil_math.h"
}
# 440 "sdk/cutil_math.h"
inline void operator+=(int4 &a, int b)
# 441 "sdk/cutil_math.h"
{
# 442 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b; (a.w) += b;
# 443 "sdk/cutil_math.h"
}
# 445 "sdk/cutil_math.h"
inline uint4 operator+(uint4 a, uint4 b)
# 446 "sdk/cutil_math.h"
{
# 447 "sdk/cutil_math.h"
return make_uint4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 448 "sdk/cutil_math.h"
}
# 449 "sdk/cutil_math.h"
inline void operator+=(uint4 &a, uint4 b)
# 450 "sdk/cutil_math.h"
{
# 451 "sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 452 "sdk/cutil_math.h"
}
# 453 "sdk/cutil_math.h"
inline uint4 operator+(uint4 a, uint b)
# 454 "sdk/cutil_math.h"
{
# 455 "sdk/cutil_math.h"
return make_uint4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 456 "sdk/cutil_math.h"
}
# 457 "sdk/cutil_math.h"
inline uint4 operator+(uint b, uint4 a)
# 458 "sdk/cutil_math.h"
{
# 459 "sdk/cutil_math.h"
return make_uint4((a.x) + b, (a.y) + b, (a.z) + b, (a.w) + b);
# 460 "sdk/cutil_math.h"
}
# 461 "sdk/cutil_math.h"
inline void operator+=(uint4 &a, uint b)
# 462 "sdk/cutil_math.h"
{
# 463 "sdk/cutil_math.h"
(a.x) += b; (a.y) += b; (a.z) += b; (a.w) += b;
# 464 "sdk/cutil_math.h"
}
# 470 "sdk/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 471 "sdk/cutil_math.h"
{
# 472 "sdk/cutil_math.h"
return make_float2((a.x) - (b.x), (a.y) - (b.y));
# 473 "sdk/cutil_math.h"
}
# 474 "sdk/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 475 "sdk/cutil_math.h"
{
# 476 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 477 "sdk/cutil_math.h"
}
# 478 "sdk/cutil_math.h"
inline float2 operator-(float2 a, float b)
# 479 "sdk/cutil_math.h"
{
# 480 "sdk/cutil_math.h"
return make_float2((a.x) - b, (a.y) - b);
# 481 "sdk/cutil_math.h"
}
# 482 "sdk/cutil_math.h"
inline float2 operator-(float b, float2 a)
# 483 "sdk/cutil_math.h"
{
# 484 "sdk/cutil_math.h"
return make_float2(b - (a.x), b - (a.y));
# 485 "sdk/cutil_math.h"
}
# 486 "sdk/cutil_math.h"
inline void operator-=(float2 &a, float b)
# 487 "sdk/cutil_math.h"
{
# 488 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b;
# 489 "sdk/cutil_math.h"
}
# 491 "sdk/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 492 "sdk/cutil_math.h"
{
# 493 "sdk/cutil_math.h"
return make_int2((a.x) - (b.x), (a.y) - (b.y));
# 494 "sdk/cutil_math.h"
}
# 495 "sdk/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 496 "sdk/cutil_math.h"
{
# 497 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 498 "sdk/cutil_math.h"
}
# 499 "sdk/cutil_math.h"
inline int2 operator-(int2 a, int b)
# 500 "sdk/cutil_math.h"
{
# 501 "sdk/cutil_math.h"
return make_int2((a.x) - b, (a.y) - b);
# 502 "sdk/cutil_math.h"
}
# 503 "sdk/cutil_math.h"
inline int2 operator-(int b, int2 a)
# 504 "sdk/cutil_math.h"
{
# 505 "sdk/cutil_math.h"
return make_int2(b - (a.x), b - (a.y));
# 506 "sdk/cutil_math.h"
}
# 507 "sdk/cutil_math.h"
inline void operator-=(int2 &a, int b)
# 508 "sdk/cutil_math.h"
{
# 509 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b;
# 510 "sdk/cutil_math.h"
}
# 512 "sdk/cutil_math.h"
inline uint2 operator-(uint2 a, uint2 b)
# 513 "sdk/cutil_math.h"
{
# 514 "sdk/cutil_math.h"
return make_uint2((a.x) - (b.x), (a.y) - (b.y));
# 515 "sdk/cutil_math.h"
}
# 516 "sdk/cutil_math.h"
inline void operator-=(uint2 &a, uint2 b)
# 517 "sdk/cutil_math.h"
{
# 518 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 519 "sdk/cutil_math.h"
}
# 520 "sdk/cutil_math.h"
inline uint2 operator-(uint2 a, uint b)
# 521 "sdk/cutil_math.h"
{
# 522 "sdk/cutil_math.h"
return make_uint2((a.x) - b, (a.y) - b);
# 523 "sdk/cutil_math.h"
}
# 524 "sdk/cutil_math.h"
inline uint2 operator-(uint b, uint2 a)
# 525 "sdk/cutil_math.h"
{
# 526 "sdk/cutil_math.h"
return make_uint2(b - (a.x), b - (a.y));
# 527 "sdk/cutil_math.h"
}
# 528 "sdk/cutil_math.h"
inline void operator-=(uint2 &a, uint b)
# 529 "sdk/cutil_math.h"
{
# 530 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b;
# 531 "sdk/cutil_math.h"
}
# 533 "sdk/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 534 "sdk/cutil_math.h"
{
# 535 "sdk/cutil_math.h"
return make_float3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 536 "sdk/cutil_math.h"
}
# 537 "sdk/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 538 "sdk/cutil_math.h"
{
# 539 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 540 "sdk/cutil_math.h"
}
# 541 "sdk/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 542 "sdk/cutil_math.h"
{
# 543 "sdk/cutil_math.h"
return make_float3((a.x) - b, (a.y) - b, (a.z) - b);
# 544 "sdk/cutil_math.h"
}
# 545 "sdk/cutil_math.h"
inline float3 operator-(float b, float3 a)
# 546 "sdk/cutil_math.h"
{
# 547 "sdk/cutil_math.h"
return make_float3(b - (a.x), b - (a.y), b - (a.z));
# 548 "sdk/cutil_math.h"
}
# 549 "sdk/cutil_math.h"
inline void operator-=(float3 &a, float b)
# 550 "sdk/cutil_math.h"
{
# 551 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b;
# 552 "sdk/cutil_math.h"
}
# 554 "sdk/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 555 "sdk/cutil_math.h"
{
# 556 "sdk/cutil_math.h"
return make_int3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 557 "sdk/cutil_math.h"
}
# 558 "sdk/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 559 "sdk/cutil_math.h"
{
# 560 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 561 "sdk/cutil_math.h"
}
# 562 "sdk/cutil_math.h"
inline int3 operator-(int3 a, int b)
# 563 "sdk/cutil_math.h"
{
# 564 "sdk/cutil_math.h"
return make_int3((a.x) - b, (a.y) - b, (a.z) - b);
# 565 "sdk/cutil_math.h"
}
# 566 "sdk/cutil_math.h"
inline int3 operator-(int b, int3 a)
# 567 "sdk/cutil_math.h"
{
# 568 "sdk/cutil_math.h"
return make_int3(b - (a.x), b - (a.y), b - (a.z));
# 569 "sdk/cutil_math.h"
}
# 570 "sdk/cutil_math.h"
inline void operator-=(int3 &a, int b)
# 571 "sdk/cutil_math.h"
{
# 572 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b;
# 573 "sdk/cutil_math.h"
}
# 575 "sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 576 "sdk/cutil_math.h"
{
# 577 "sdk/cutil_math.h"
return make_uint3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 578 "sdk/cutil_math.h"
}
# 579 "sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 580 "sdk/cutil_math.h"
{
# 581 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 582 "sdk/cutil_math.h"
}
# 583 "sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint b)
# 584 "sdk/cutil_math.h"
{
# 585 "sdk/cutil_math.h"
return make_uint3((a.x) - b, (a.y) - b, (a.z) - b);
# 586 "sdk/cutil_math.h"
}
# 587 "sdk/cutil_math.h"
inline uint3 operator-(uint b, uint3 a)
# 588 "sdk/cutil_math.h"
{
# 589 "sdk/cutil_math.h"
return make_uint3(b - (a.x), b - (a.y), b - (a.z));
# 590 "sdk/cutil_math.h"
}
# 591 "sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint b)
# 592 "sdk/cutil_math.h"
{
# 593 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b;
# 594 "sdk/cutil_math.h"
}
# 596 "sdk/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 597 "sdk/cutil_math.h"
{
# 598 "sdk/cutil_math.h"
return make_float4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 599 "sdk/cutil_math.h"
}
# 600 "sdk/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 601 "sdk/cutil_math.h"
{
# 602 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 603 "sdk/cutil_math.h"
}
# 604 "sdk/cutil_math.h"
inline float4 operator-(float4 a, float b)
# 605 "sdk/cutil_math.h"
{
# 606 "sdk/cutil_math.h"
return make_float4((a.x) - b, (a.y) - b, (a.z) - b, (a.w) - b);
# 607 "sdk/cutil_math.h"
}
# 608 "sdk/cutil_math.h"
inline void operator-=(float4 &a, float b)
# 609 "sdk/cutil_math.h"
{
# 610 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b; (a.w) -= b;
# 611 "sdk/cutil_math.h"
}
# 613 "sdk/cutil_math.h"
inline int4 operator-(int4 a, int4 b)
# 614 "sdk/cutil_math.h"
{
# 615 "sdk/cutil_math.h"
return make_int4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 616 "sdk/cutil_math.h"
}
# 617 "sdk/cutil_math.h"
inline void operator-=(int4 &a, int4 b)
# 618 "sdk/cutil_math.h"
{
# 619 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 620 "sdk/cutil_math.h"
}
# 621 "sdk/cutil_math.h"
inline int4 operator-(int4 a, int b)
# 622 "sdk/cutil_math.h"
{
# 623 "sdk/cutil_math.h"
return make_int4((a.x) - b, (a.y) - b, (a.z) - b, (a.w) - b);
# 624 "sdk/cutil_math.h"
}
# 625 "sdk/cutil_math.h"
inline int4 operator-(int b, int4 a)
# 626 "sdk/cutil_math.h"
{
# 627 "sdk/cutil_math.h"
return make_int4(b - (a.x), b - (a.y), b - (a.z), b - (a.w));
# 628 "sdk/cutil_math.h"
}
# 629 "sdk/cutil_math.h"
inline void operator-=(int4 &a, int b)
# 630 "sdk/cutil_math.h"
{
# 631 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b; (a.w) -= b;
# 632 "sdk/cutil_math.h"
}
# 634 "sdk/cutil_math.h"
inline uint4 operator-(uint4 a, uint4 b)
# 635 "sdk/cutil_math.h"
{
# 636 "sdk/cutil_math.h"
return make_uint4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 637 "sdk/cutil_math.h"
}
# 638 "sdk/cutil_math.h"
inline void operator-=(uint4 &a, uint4 b)
# 639 "sdk/cutil_math.h"
{
# 640 "sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 641 "sdk/cutil_math.h"
}
# 642 "sdk/cutil_math.h"
inline uint4 operator-(uint4 a, uint b)
# 643 "sdk/cutil_math.h"
{
# 644 "sdk/cutil_math.h"
return make_uint4((a.x) - b, (a.y) - b, (a.z) - b, (a.w) - b);
# 645 "sdk/cutil_math.h"
}
# 646 "sdk/cutil_math.h"
inline uint4 operator-(uint b, uint4 a)
# 647 "sdk/cutil_math.h"
{
# 648 "sdk/cutil_math.h"
return make_uint4(b - (a.x), b - (a.y), b - (a.z), b - (a.w));
# 649 "sdk/cutil_math.h"
}
# 650 "sdk/cutil_math.h"
inline void operator-=(uint4 &a, uint b)
# 651 "sdk/cutil_math.h"
{
# 652 "sdk/cutil_math.h"
(a.x) -= b; (a.y) -= b; (a.z) -= b; (a.w) -= b;
# 653 "sdk/cutil_math.h"
}
# 659 "sdk/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 660 "sdk/cutil_math.h"
{
# 661 "sdk/cutil_math.h"
return make_float2((a.x) * (b.x), (a.y) * (b.y));
# 662 "sdk/cutil_math.h"
}
# 663 "sdk/cutil_math.h"
inline void operator*=(float2 &a, float2 b)
# 664 "sdk/cutil_math.h"
{
# 665 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y);
# 666 "sdk/cutil_math.h"
}
# 667 "sdk/cutil_math.h"
inline float2 operator*(float2 a, float b)
# 668 "sdk/cutil_math.h"
{
# 669 "sdk/cutil_math.h"
return make_float2((a.x) * b, (a.y) * b);
# 670 "sdk/cutil_math.h"
}
# 671 "sdk/cutil_math.h"
inline float2 operator*(float b, float2 a)
# 672 "sdk/cutil_math.h"
{
# 673 "sdk/cutil_math.h"
return make_float2(b * (a.x), b * (a.y));
# 674 "sdk/cutil_math.h"
}
# 675 "sdk/cutil_math.h"
inline void operator*=(float2 &a, float b)
# 676 "sdk/cutil_math.h"
{
# 677 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b;
# 678 "sdk/cutil_math.h"
}
# 680 "sdk/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 681 "sdk/cutil_math.h"
{
# 682 "sdk/cutil_math.h"
return make_int2((a.x) * (b.x), (a.y) * (b.y));
# 683 "sdk/cutil_math.h"
}
# 684 "sdk/cutil_math.h"
inline void operator*=(int2 &a, int2 b)
# 685 "sdk/cutil_math.h"
{
# 686 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y);
# 687 "sdk/cutil_math.h"
}
# 688 "sdk/cutil_math.h"
inline int2 operator*(int2 a, int b)
# 689 "sdk/cutil_math.h"
{
# 690 "sdk/cutil_math.h"
return make_int2((a.x) * b, (a.y) * b);
# 691 "sdk/cutil_math.h"
}
# 692 "sdk/cutil_math.h"
inline int2 operator*(int b, int2 a)
# 693 "sdk/cutil_math.h"
{
# 694 "sdk/cutil_math.h"
return make_int2(b * (a.x), b * (a.y));
# 695 "sdk/cutil_math.h"
}
# 696 "sdk/cutil_math.h"
inline void operator*=(int2 &a, int b)
# 697 "sdk/cutil_math.h"
{
# 698 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b;
# 699 "sdk/cutil_math.h"
}
# 701 "sdk/cutil_math.h"
inline uint2 operator*(uint2 a, uint2 b)
# 702 "sdk/cutil_math.h"
{
# 703 "sdk/cutil_math.h"
return make_uint2((a.x) * (b.x), (a.y) * (b.y));
# 704 "sdk/cutil_math.h"
}
# 705 "sdk/cutil_math.h"
inline void operator*=(uint2 &a, uint2 b)
# 706 "sdk/cutil_math.h"
{
# 707 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y);
# 708 "sdk/cutil_math.h"
}
# 709 "sdk/cutil_math.h"
inline uint2 operator*(uint2 a, uint b)
# 710 "sdk/cutil_math.h"
{
# 711 "sdk/cutil_math.h"
return make_uint2((a.x) * b, (a.y) * b);
# 712 "sdk/cutil_math.h"
}
# 713 "sdk/cutil_math.h"
inline uint2 operator*(uint b, uint2 a)
# 714 "sdk/cutil_math.h"
{
# 715 "sdk/cutil_math.h"
return make_uint2(b * (a.x), b * (a.y));
# 716 "sdk/cutil_math.h"
}
# 717 "sdk/cutil_math.h"
inline void operator*=(uint2 &a, uint b)
# 718 "sdk/cutil_math.h"
{
# 719 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b;
# 720 "sdk/cutil_math.h"
}
# 722 "sdk/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 723 "sdk/cutil_math.h"
{
# 724 "sdk/cutil_math.h"
return make_float3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 725 "sdk/cutil_math.h"
}
# 726 "sdk/cutil_math.h"
inline void operator*=(float3 &a, float3 b)
# 727 "sdk/cutil_math.h"
{
# 728 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z);
# 729 "sdk/cutil_math.h"
}
# 730 "sdk/cutil_math.h"
inline float3 operator*(float3 a, float b)
# 731 "sdk/cutil_math.h"
{
# 732 "sdk/cutil_math.h"
return make_float3((a.x) * b, (a.y) * b, (a.z) * b);
# 733 "sdk/cutil_math.h"
}
# 734 "sdk/cutil_math.h"
inline float3 operator*(float b, float3 a)
# 735 "sdk/cutil_math.h"
{
# 736 "sdk/cutil_math.h"
return make_float3(b * (a.x), b * (a.y), b * (a.z));
# 737 "sdk/cutil_math.h"
}
# 738 "sdk/cutil_math.h"
inline void operator*=(float3 &a, float b)
# 739 "sdk/cutil_math.h"
{
# 740 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b;
# 741 "sdk/cutil_math.h"
}
# 743 "sdk/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 744 "sdk/cutil_math.h"
{
# 745 "sdk/cutil_math.h"
return make_int3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 746 "sdk/cutil_math.h"
}
# 747 "sdk/cutil_math.h"
inline void operator*=(int3 &a, int3 b)
# 748 "sdk/cutil_math.h"
{
# 749 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z);
# 750 "sdk/cutil_math.h"
}
# 751 "sdk/cutil_math.h"
inline int3 operator*(int3 a, int b)
# 752 "sdk/cutil_math.h"
{
# 753 "sdk/cutil_math.h"
return make_int3((a.x) * b, (a.y) * b, (a.z) * b);
# 754 "sdk/cutil_math.h"
}
# 755 "sdk/cutil_math.h"
inline int3 operator*(int b, int3 a)
# 756 "sdk/cutil_math.h"
{
# 757 "sdk/cutil_math.h"
return make_int3(b * (a.x), b * (a.y), b * (a.z));
# 758 "sdk/cutil_math.h"
}
# 759 "sdk/cutil_math.h"
inline void operator*=(int3 &a, int b)
# 760 "sdk/cutil_math.h"
{
# 761 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b;
# 762 "sdk/cutil_math.h"
}
# 764 "sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 765 "sdk/cutil_math.h"
{
# 766 "sdk/cutil_math.h"
return make_uint3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 767 "sdk/cutil_math.h"
}
# 768 "sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint3 b)
# 769 "sdk/cutil_math.h"
{
# 770 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z);
# 771 "sdk/cutil_math.h"
}
# 772 "sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint b)
# 773 "sdk/cutil_math.h"
{
# 774 "sdk/cutil_math.h"
return make_uint3((a.x) * b, (a.y) * b, (a.z) * b);
# 775 "sdk/cutil_math.h"
}
# 776 "sdk/cutil_math.h"
inline uint3 operator*(uint b, uint3 a)
# 777 "sdk/cutil_math.h"
{
# 778 "sdk/cutil_math.h"
return make_uint3(b * (a.x), b * (a.y), b * (a.z));
# 779 "sdk/cutil_math.h"
}
# 780 "sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint b)
# 781 "sdk/cutil_math.h"
{
# 782 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b;
# 783 "sdk/cutil_math.h"
}
# 785 "sdk/cutil_math.h"
inline float4 operator*(float4 a, float4 b)
# 786 "sdk/cutil_math.h"
{
# 787 "sdk/cutil_math.h"
return make_float4((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z), (a.w) * (b.w));
# 788 "sdk/cutil_math.h"
}
# 789 "sdk/cutil_math.h"
inline void operator*=(float4 &a, float4 b)
# 790 "sdk/cutil_math.h"
{
# 791 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z); (a.w) *= (b.w);
# 792 "sdk/cutil_math.h"
}
# 793 "sdk/cutil_math.h"
inline float4 operator*(float4 a, float b)
# 794 "sdk/cutil_math.h"
{
# 795 "sdk/cutil_math.h"
return make_float4((a.x) * b, (a.y) * b, (a.z) * b, (a.w) * b);
# 796 "sdk/cutil_math.h"
}
# 797 "sdk/cutil_math.h"
inline float4 operator*(float b, float4 a)
# 798 "sdk/cutil_math.h"
{
# 799 "sdk/cutil_math.h"
return make_float4(b * (a.x), b * (a.y), b * (a.z), b * (a.w));
# 800 "sdk/cutil_math.h"
}
# 801 "sdk/cutil_math.h"
inline void operator*=(float4 &a, float b)
# 802 "sdk/cutil_math.h"
{
# 803 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b; (a.w) *= b;
# 804 "sdk/cutil_math.h"
}
# 806 "sdk/cutil_math.h"
inline int4 operator*(int4 a, int4 b)
# 807 "sdk/cutil_math.h"
{
# 808 "sdk/cutil_math.h"
return make_int4((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z), (a.w) * (b.w));
# 809 "sdk/cutil_math.h"
}
# 810 "sdk/cutil_math.h"
inline void operator*=(int4 &a, int4 b)
# 811 "sdk/cutil_math.h"
{
# 812 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z); (a.w) *= (b.w);
# 813 "sdk/cutil_math.h"
}
# 814 "sdk/cutil_math.h"
inline int4 operator*(int4 a, int b)
# 815 "sdk/cutil_math.h"
{
# 816 "sdk/cutil_math.h"
return make_int4((a.x) * b, (a.y) * b, (a.z) * b, (a.w) * b);
# 817 "sdk/cutil_math.h"
}
# 818 "sdk/cutil_math.h"
inline int4 operator*(int b, int4 a)
# 819 "sdk/cutil_math.h"
{
# 820 "sdk/cutil_math.h"
return make_int4(b * (a.x), b * (a.y), b * (a.z), b * (a.w));
# 821 "sdk/cutil_math.h"
}
# 822 "sdk/cutil_math.h"
inline void operator*=(int4 &a, int b)
# 823 "sdk/cutil_math.h"
{
# 824 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b; (a.w) *= b;
# 825 "sdk/cutil_math.h"
}
# 827 "sdk/cutil_math.h"
inline uint4 operator*(uint4 a, uint4 b)
# 828 "sdk/cutil_math.h"
{
# 829 "sdk/cutil_math.h"
return make_uint4((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z), (a.w) * (b.w));
# 830 "sdk/cutil_math.h"
}
# 831 "sdk/cutil_math.h"
inline void operator*=(uint4 &a, uint4 b)
# 832 "sdk/cutil_math.h"
{
# 833 "sdk/cutil_math.h"
(a.x) *= (b.x); (a.y) *= (b.y); (a.z) *= (b.z); (a.w) *= (b.w);
# 834 "sdk/cutil_math.h"
}
# 835 "sdk/cutil_math.h"
inline uint4 operator*(uint4 a, uint b)
# 836 "sdk/cutil_math.h"
{
# 837 "sdk/cutil_math.h"
return make_uint4((a.x) * b, (a.y) * b, (a.z) * b, (a.w) * b);
# 838 "sdk/cutil_math.h"
}
# 839 "sdk/cutil_math.h"
inline uint4 operator*(uint b, uint4 a)
# 840 "sdk/cutil_math.h"
{
# 841 "sdk/cutil_math.h"
return make_uint4(b * (a.x), b * (a.y), b * (a.z), b * (a.w));
# 842 "sdk/cutil_math.h"
}
# 843 "sdk/cutil_math.h"
inline void operator*=(uint4 &a, uint b)
# 844 "sdk/cutil_math.h"
{
# 845 "sdk/cutil_math.h"
(a.x) *= b; (a.y) *= b; (a.z) *= b; (a.w) *= b;
# 846 "sdk/cutil_math.h"
}
# 852 "sdk/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 853 "sdk/cutil_math.h"
{
# 854 "sdk/cutil_math.h"
return make_float2((a.x) / (b.x), (a.y) / (b.y));
# 855 "sdk/cutil_math.h"
}
# 856 "sdk/cutil_math.h"
inline void operator/=(float2 &a, float2 b)
# 857 "sdk/cutil_math.h"
{
# 858 "sdk/cutil_math.h"
(a.x) /= (b.x); (a.y) /= (b.y);
# 859 "sdk/cutil_math.h"
}
# 860 "sdk/cutil_math.h"
inline float2 operator/(float2 a, float b)
# 861 "sdk/cutil_math.h"
{
# 862 "sdk/cutil_math.h"
return make_float2((a.x) / b, (a.y) / b);
# 863 "sdk/cutil_math.h"
}
# 864 "sdk/cutil_math.h"
inline void operator/=(float2 &a, float b)
# 865 "sdk/cutil_math.h"
{
# 866 "sdk/cutil_math.h"
(a.x) /= b; (a.y) /= b;
# 867 "sdk/cutil_math.h"
}
# 868 "sdk/cutil_math.h"
inline float2 operator/(float b, float2 a)
# 869 "sdk/cutil_math.h"
{
# 870 "sdk/cutil_math.h"
return make_float2(b / (a.x), b / (a.y));
# 871 "sdk/cutil_math.h"
}
# 873 "sdk/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 874 "sdk/cutil_math.h"
{
# 875 "sdk/cutil_math.h"
return make_float3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 876 "sdk/cutil_math.h"
}
# 877 "sdk/cutil_math.h"
inline void operator/=(float3 &a, float3 b)
# 878 "sdk/cutil_math.h"
{
# 879 "sdk/cutil_math.h"
(a.x) /= (b.x); (a.y) /= (b.y); (a.z) /= (b.z);
# 880 "sdk/cutil_math.h"
}
# 881 "sdk/cutil_math.h"
inline float3 operator/(float3 a, float b)
# 882 "sdk/cutil_math.h"
{
# 883 "sdk/cutil_math.h"
return make_float3((a.x) / b, (a.y) / b, (a.z) / b);
# 884 "sdk/cutil_math.h"
}
# 885 "sdk/cutil_math.h"
inline void operator/=(float3 &a, float b)
# 886 "sdk/cutil_math.h"
{
# 887 "sdk/cutil_math.h"
(a.x) /= b; (a.y) /= b; (a.z) /= b;
# 888 "sdk/cutil_math.h"
}
# 889 "sdk/cutil_math.h"
inline float3 operator/(float b, float3 a)
# 890 "sdk/cutil_math.h"
{
# 891 "sdk/cutil_math.h"
return make_float3(b / (a.x), b / (a.y), b / (a.z));
# 892 "sdk/cutil_math.h"
}
# 894 "sdk/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 895 "sdk/cutil_math.h"
{
# 896 "sdk/cutil_math.h"
return make_float4((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z), (a.w) / (b.w));
# 897 "sdk/cutil_math.h"
}
# 898 "sdk/cutil_math.h"
inline void operator/=(float4 &a, float4 b)
# 899 "sdk/cutil_math.h"
{
# 900 "sdk/cutil_math.h"
(a.x) /= (b.x); (a.y) /= (b.y); (a.z) /= (b.z); (a.w) /= (b.w);
# 901 "sdk/cutil_math.h"
}
# 902 "sdk/cutil_math.h"
inline float4 operator/(float4 a, float b)
# 903 "sdk/cutil_math.h"
{
# 904 "sdk/cutil_math.h"
return make_float4((a.x) / b, (a.y) / b, (a.z) / b, (a.w) / b);
# 905 "sdk/cutil_math.h"
}
# 906 "sdk/cutil_math.h"
inline void operator/=(float4 &a, float b)
# 907 "sdk/cutil_math.h"
{
# 908 "sdk/cutil_math.h"
(a.x) /= b; (a.y) /= b; (a.z) /= b; (a.w) /= b;
# 909 "sdk/cutil_math.h"
}
# 910 "sdk/cutil_math.h"
inline float4 operator/(float b, float4 a) {
# 911 "sdk/cutil_math.h"
return make_float4(b / (a.x), b / (a.y), b / (a.z), b / (a.w));
# 912 "sdk/cutil_math.h"
}
# 918 "sdk/cutil_math.h"
inline float2 fminf(float2 a, float2 b)
# 919 "sdk/cutil_math.h"
{
# 920 "sdk/cutil_math.h"
return make_float2(fminf(a.x, b.x), fminf(a.y, b.y));
# 921 "sdk/cutil_math.h"
}
# 922 "sdk/cutil_math.h"
inline float3 fminf(float3 a, float3 b)
# 923 "sdk/cutil_math.h"
{
# 924 "sdk/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 925 "sdk/cutil_math.h"
}
# 926 "sdk/cutil_math.h"
inline float4 fminf(float4 a, float4 b)
# 927 "sdk/cutil_math.h"
{
# 928 "sdk/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 929 "sdk/cutil_math.h"
}
# 931 "sdk/cutil_math.h"
inline int2 min(int2 a, int2 b)
# 932 "sdk/cutil_math.h"
{
# 933 "sdk/cutil_math.h"
return make_int2(min(a.x, b.x), min(a.y, b.y));
# 934 "sdk/cutil_math.h"
}
# 935 "sdk/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 936 "sdk/cutil_math.h"
{
# 937 "sdk/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 938 "sdk/cutil_math.h"
}
# 939 "sdk/cutil_math.h"
inline int4 min(int4 a, int4 b)
# 940 "sdk/cutil_math.h"
{
# 941 "sdk/cutil_math.h"
return make_int4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
# 942 "sdk/cutil_math.h"
}
# 944 "sdk/cutil_math.h"
inline uint2 min(uint2 a, uint2 b)
# 945 "sdk/cutil_math.h"
{
# 946 "sdk/cutil_math.h"
return make_uint2(min(a.x, b.x), min(a.y, b.y));
# 947 "sdk/cutil_math.h"
}
# 948 "sdk/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 949 "sdk/cutil_math.h"
{
# 950 "sdk/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 951 "sdk/cutil_math.h"
}
# 952 "sdk/cutil_math.h"
inline uint4 min(uint4 a, uint4 b)
# 953 "sdk/cutil_math.h"
{
# 954 "sdk/cutil_math.h"
return make_uint4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
# 955 "sdk/cutil_math.h"
}
# 961 "sdk/cutil_math.h"
inline float2 fmaxf(float2 a, float2 b)
# 962 "sdk/cutil_math.h"
{
# 963 "sdk/cutil_math.h"
return make_float2(fmaxf(a.x, b.x), fmaxf(a.y, b.y));
# 964 "sdk/cutil_math.h"
}
# 965 "sdk/cutil_math.h"
inline float3 fmaxf(float3 a, float3 b)
# 966 "sdk/cutil_math.h"
{
# 967 "sdk/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 968 "sdk/cutil_math.h"
}
# 969 "sdk/cutil_math.h"
inline float4 fmaxf(float4 a, float4 b)
# 970 "sdk/cutil_math.h"
{
# 971 "sdk/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 972 "sdk/cutil_math.h"
}
# 974 "sdk/cutil_math.h"
inline int2 max(int2 a, int2 b)
# 975 "sdk/cutil_math.h"
{
# 976 "sdk/cutil_math.h"
return make_int2(max(a.x, b.x), max(a.y, b.y));
# 977 "sdk/cutil_math.h"
}
# 978 "sdk/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 979 "sdk/cutil_math.h"
{
# 980 "sdk/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 981 "sdk/cutil_math.h"
}
# 982 "sdk/cutil_math.h"
inline int4 max(int4 a, int4 b)
# 983 "sdk/cutil_math.h"
{
# 984 "sdk/cutil_math.h"
return make_int4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
# 985 "sdk/cutil_math.h"
}
# 987 "sdk/cutil_math.h"
inline uint2 max(uint2 a, uint2 b)
# 988 "sdk/cutil_math.h"
{
# 989 "sdk/cutil_math.h"
return make_uint2(max(a.x, b.x), max(a.y, b.y));
# 990 "sdk/cutil_math.h"
}
# 991 "sdk/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 992 "sdk/cutil_math.h"
{
# 993 "sdk/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 994 "sdk/cutil_math.h"
}
# 995 "sdk/cutil_math.h"
inline uint4 max(uint4 a, uint4 b)
# 996 "sdk/cutil_math.h"
{
# 997 "sdk/cutil_math.h"
return make_uint4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
# 998 "sdk/cutil_math.h"
}
# 1005 "sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
# 1006 "sdk/cutil_math.h"
{
# 1007 "sdk/cutil_math.h"
return a + (t * (b - a));
# 1008 "sdk/cutil_math.h"
}
# 1009 "sdk/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 1010 "sdk/cutil_math.h"
{
# 1011 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 1012 "sdk/cutil_math.h"
}
# 1013 "sdk/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 1014 "sdk/cutil_math.h"
{
# 1015 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 1016 "sdk/cutil_math.h"
}
# 1017 "sdk/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 1018 "sdk/cutil_math.h"
{
# 1019 "sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 1020 "sdk/cutil_math.h"
}
# 1027 "sdk/cutil_math.h"
inline float clamp(float f, float a, float b)
# 1028 "sdk/cutil_math.h"
{
# 1029 "sdk/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 1030 "sdk/cutil_math.h"
}
# 1031 "sdk/cutil_math.h"
inline int clamp(int f, int a, int b)
# 1032 "sdk/cutil_math.h"
{
# 1033 "sdk/cutil_math.h"
return max(a, min(f, b));
# 1034 "sdk/cutil_math.h"
}
# 1035 "sdk/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 1036 "sdk/cutil_math.h"
{
# 1037 "sdk/cutil_math.h"
return max(a, min(f, b));
# 1038 "sdk/cutil_math.h"
}
# 1040 "sdk/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 1041 "sdk/cutil_math.h"
{
# 1042 "sdk/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 1043 "sdk/cutil_math.h"
}
# 1044 "sdk/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 1045 "sdk/cutil_math.h"
{
# 1046 "sdk/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 1047 "sdk/cutil_math.h"
}
# 1048 "sdk/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 1049 "sdk/cutil_math.h"
{
# 1050 "sdk/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 1051 "sdk/cutil_math.h"
}
# 1052 "sdk/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 1053 "sdk/cutil_math.h"
{
# 1054 "sdk/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 1055 "sdk/cutil_math.h"
}
# 1056 "sdk/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 1057 "sdk/cutil_math.h"
{
# 1058 "sdk/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 1059 "sdk/cutil_math.h"
}
# 1060 "sdk/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 1061 "sdk/cutil_math.h"
{
# 1062 "sdk/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 1063 "sdk/cutil_math.h"
}
# 1065 "sdk/cutil_math.h"
inline int2 clamp(int2 v, int a, int b)
# 1066 "sdk/cutil_math.h"
{
# 1067 "sdk/cutil_math.h"
return make_int2(clamp(v.x, a, b), clamp(v.y, a, b));
# 1068 "sdk/cutil_math.h"
}
# 1069 "sdk/cutil_math.h"
inline int2 clamp(int2 v, int2 a, int2 b)
# 1070 "sdk/cutil_math.h"
{
# 1071 "sdk/cutil_math.h"
return make_int2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 1072 "sdk/cutil_math.h"
}
# 1073 "sdk/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 1074 "sdk/cutil_math.h"
{
# 1075 "sdk/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 1076 "sdk/cutil_math.h"
}
# 1077 "sdk/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 1078 "sdk/cutil_math.h"
{
# 1079 "sdk/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 1080 "sdk/cutil_math.h"
}
# 1081 "sdk/cutil_math.h"
inline int4 clamp(int4 v, int a, int b)
# 1082 "sdk/cutil_math.h"
{
# 1083 "sdk/cutil_math.h"
return make_int4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 1084 "sdk/cutil_math.h"
}
# 1085 "sdk/cutil_math.h"
inline int4 clamp(int4 v, int4 a, int4 b)
# 1086 "sdk/cutil_math.h"
{
# 1087 "sdk/cutil_math.h"
return make_int4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 1088 "sdk/cutil_math.h"
}
# 1090 "sdk/cutil_math.h"
inline uint2 clamp(uint2 v, uint a, uint b)
# 1091 "sdk/cutil_math.h"
{
# 1092 "sdk/cutil_math.h"
return make_uint2(clamp(v.x, a, b), clamp(v.y, a, b));
# 1093 "sdk/cutil_math.h"
}
# 1094 "sdk/cutil_math.h"
inline uint2 clamp(uint2 v, uint2 a, uint2 b)
# 1095 "sdk/cutil_math.h"
{
# 1096 "sdk/cutil_math.h"
return make_uint2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 1097 "sdk/cutil_math.h"
}
# 1098 "sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 1099 "sdk/cutil_math.h"
{
# 1100 "sdk/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 1101 "sdk/cutil_math.h"
}
# 1102 "sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 1103 "sdk/cutil_math.h"
{
# 1104 "sdk/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 1105 "sdk/cutil_math.h"
}
# 1106 "sdk/cutil_math.h"
inline uint4 clamp(uint4 v, uint a, uint b)
# 1107 "sdk/cutil_math.h"
{
# 1108 "sdk/cutil_math.h"
return make_uint4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 1109 "sdk/cutil_math.h"
}
# 1110 "sdk/cutil_math.h"
inline uint4 clamp(uint4 v, uint4 a, uint4 b)
# 1111 "sdk/cutil_math.h"
{
# 1112 "sdk/cutil_math.h"
return make_uint4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 1113 "sdk/cutil_math.h"
}
# 1119 "sdk/cutil_math.h"
inline float dot(float2 a, float2 b)
# 1120 "sdk/cutil_math.h"
{
# 1121 "sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 1122 "sdk/cutil_math.h"
}
# 1123 "sdk/cutil_math.h"
inline float dot(float3 a, float3 b)
# 1124 "sdk/cutil_math.h"
{
# 1125 "sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 1126 "sdk/cutil_math.h"
}
# 1127 "sdk/cutil_math.h"
inline float dot(float4 a, float4 b)
# 1128 "sdk/cutil_math.h"
{
# 1129 "sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 1130 "sdk/cutil_math.h"
}
# 1132 "sdk/cutil_math.h"
inline int dot(int2 a, int2 b)
# 1133 "sdk/cutil_math.h"
{
# 1134 "sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 1135 "sdk/cutil_math.h"
}
# 1136 "sdk/cutil_math.h"
inline int dot(int3 a, int3 b)
# 1137 "sdk/cutil_math.h"
{
# 1138 "sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 1139 "sdk/cutil_math.h"
}
# 1140 "sdk/cutil_math.h"
inline int dot(int4 a, int4 b)
# 1141 "sdk/cutil_math.h"
{
# 1142 "sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 1143 "sdk/cutil_math.h"
}
# 1145 "sdk/cutil_math.h"
inline uint dot(uint2 a, uint2 b)
# 1146 "sdk/cutil_math.h"
{
# 1147 "sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 1148 "sdk/cutil_math.h"
}
# 1149 "sdk/cutil_math.h"
inline uint dot(uint3 a, uint3 b)
# 1150 "sdk/cutil_math.h"
{
# 1151 "sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 1152 "sdk/cutil_math.h"
}
# 1153 "sdk/cutil_math.h"
inline uint dot(uint4 a, uint4 b)
# 1154 "sdk/cutil_math.h"
{
# 1155 "sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 1156 "sdk/cutil_math.h"
}
# 1162 "sdk/cutil_math.h"
inline float length(float2 v)
# 1163 "sdk/cutil_math.h"
{
# 1164 "sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 1165 "sdk/cutil_math.h"
}
# 1166 "sdk/cutil_math.h"
inline float length(float3 v)
# 1167 "sdk/cutil_math.h"
{
# 1168 "sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 1169 "sdk/cutil_math.h"
}
# 1170 "sdk/cutil_math.h"
inline float length(float4 v)
# 1171 "sdk/cutil_math.h"
{
# 1172 "sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 1173 "sdk/cutil_math.h"
}
# 1179 "sdk/cutil_math.h"
inline float2 normalize(float2 v)
# 1180 "sdk/cutil_math.h"
{
# 1181 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 1182 "sdk/cutil_math.h"
return (v * invLen);
# 1183 "sdk/cutil_math.h"
}
# 1184 "sdk/cutil_math.h"
inline float3 normalize(float3 v)
# 1185 "sdk/cutil_math.h"
{
# 1186 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 1187 "sdk/cutil_math.h"
return (v * invLen);
# 1188 "sdk/cutil_math.h"
}
# 1189 "sdk/cutil_math.h"
inline float4 normalize(float4 v)
# 1190 "sdk/cutil_math.h"
{
# 1191 "sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 1192 "sdk/cutil_math.h"
return (v * invLen);
# 1193 "sdk/cutil_math.h"
}
# 1199 "sdk/cutil_math.h"
inline float2 floorf(float2 v)
# 1200 "sdk/cutil_math.h"
{
# 1201 "sdk/cutil_math.h"
return make_float2(floorf(v.x), floorf(v.y));
# 1202 "sdk/cutil_math.h"
}
# 1203 "sdk/cutil_math.h"
inline float3 floorf(float3 v)
# 1204 "sdk/cutil_math.h"
{
# 1205 "sdk/cutil_math.h"
return make_float3(floorf(v.x), floorf(v.y), floorf(v.z));
# 1206 "sdk/cutil_math.h"
}
# 1207 "sdk/cutil_math.h"
inline float4 floorf(float4 v)
# 1208 "sdk/cutil_math.h"
{
# 1209 "sdk/cutil_math.h"
return make_float4(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
# 1210 "sdk/cutil_math.h"
}
# 1216 "sdk/cutil_math.h"
inline float fracf(float v)
# 1217 "sdk/cutil_math.h"
{
# 1218 "sdk/cutil_math.h"
return v - floorf(v);
# 1219 "sdk/cutil_math.h"
}
# 1220 "sdk/cutil_math.h"
inline float2 fracf(float2 v)
# 1221 "sdk/cutil_math.h"
{
# 1222 "sdk/cutil_math.h"
return make_float2(fracf(v.x), fracf(v.y));
# 1223 "sdk/cutil_math.h"
}
# 1224 "sdk/cutil_math.h"
inline float3 fracf(float3 v)
# 1225 "sdk/cutil_math.h"
{
# 1226 "sdk/cutil_math.h"
return make_float3(fracf(v.x), fracf(v.y), fracf(v.z));
# 1227 "sdk/cutil_math.h"
}
# 1228 "sdk/cutil_math.h"
inline float4 fracf(float4 v)
# 1229 "sdk/cutil_math.h"
{
# 1230 "sdk/cutil_math.h"
return make_float4(fracf(v.x), fracf(v.y), fracf(v.z), fracf(v.w));
# 1231 "sdk/cutil_math.h"
}
# 1237 "sdk/cutil_math.h"
inline float2 fmodf(float2 a, float2 b)
# 1238 "sdk/cutil_math.h"
{
# 1239 "sdk/cutil_math.h"
return make_float2(fmodf(a.x, b.x), fmodf(a.y, b.y));
# 1240 "sdk/cutil_math.h"
}
# 1241 "sdk/cutil_math.h"
inline float3 fmodf(float3 a, float3 b)
# 1242 "sdk/cutil_math.h"
{
# 1243 "sdk/cutil_math.h"
return make_float3(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z));
# 1244 "sdk/cutil_math.h"
}
# 1245 "sdk/cutil_math.h"
inline float4 fmodf(float4 a, float4 b)
# 1246 "sdk/cutil_math.h"
{
# 1247 "sdk/cutil_math.h"
return make_float4(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z), fmodf(a.w, b.w));
# 1248 "sdk/cutil_math.h"
}
# 1254 "sdk/cutil_math.h"
inline float2 fabs(float2 v)
# 1255 "sdk/cutil_math.h"
{
# 1256 "sdk/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 1257 "sdk/cutil_math.h"
}
# 1258 "sdk/cutil_math.h"
inline float3 fabs(float3 v)
# 1259 "sdk/cutil_math.h"
{
# 1260 "sdk/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 1261 "sdk/cutil_math.h"
}
# 1262 "sdk/cutil_math.h"
inline float4 fabs(float4 v)
# 1263 "sdk/cutil_math.h"
{
# 1264 "sdk/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 1265 "sdk/cutil_math.h"
}
# 1267 "sdk/cutil_math.h"
inline int2 abs(int2 v)
# 1268 "sdk/cutil_math.h"
{
# 1269 "sdk/cutil_math.h"
return make_int2(abs(v.x), abs(v.y));
# 1270 "sdk/cutil_math.h"
}
# 1271 "sdk/cutil_math.h"
inline int3 abs(int3 v)
# 1272 "sdk/cutil_math.h"
{
# 1273 "sdk/cutil_math.h"
return make_int3(abs(v.x), abs(v.y), abs(v.z));
# 1274 "sdk/cutil_math.h"
}
# 1275 "sdk/cutil_math.h"
inline int4 abs(int4 v)
# 1276 "sdk/cutil_math.h"
{
# 1277 "sdk/cutil_math.h"
return make_int4(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
# 1278 "sdk/cutil_math.h"
}
# 1286 "sdk/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 1287 "sdk/cutil_math.h"
{
# 1288 "sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 1289 "sdk/cutil_math.h"
}
# 1295 "sdk/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 1296 "sdk/cutil_math.h"
{
# 1297 "sdk/cutil_math.h"
return make_float3(((a.y) * (b.z)) - ((a.z) * (b.y)), ((a.z) * (b.x)) - ((a.x) * (b.z)), ((a.x) * (b.y)) - ((a.y) * (b.x)));
# 1298 "sdk/cutil_math.h"
}
# 1307 "sdk/cutil_math.h"
inline float smoothstep(float a, float b, float x)
# 1308 "sdk/cutil_math.h"
{
# 1309 "sdk/cutil_math.h"
float y = clamp((x - a) / (b - a), (0.0F), (1.0F));
# 1310 "sdk/cutil_math.h"
return (y * y) * ((3.0F) - ((2.0F) * y));
# 1311 "sdk/cutil_math.h"
}
# 1312 "sdk/cutil_math.h"
inline float2 smoothstep(float2 a, float2 b, float2 x)
# 1313 "sdk/cutil_math.h"
{
# 1314 "sdk/cutil_math.h"
float2 y = clamp((((x - a)) / ((b - a))), (0.0F), (1.0F));
# 1315 "sdk/cutil_math.h"
return (((y * y)) * (((make_float2((3.0F))) - (((make_float2((2.0F))) * y)))));
# 1316 "sdk/cutil_math.h"
}
# 1317 "sdk/cutil_math.h"
inline float3 smoothstep(float3 a, float3 b, float3 x)
# 1318 "sdk/cutil_math.h"
{
# 1319 "sdk/cutil_math.h"
float3 y = clamp((((x - a)) / ((b - a))), (0.0F), (1.0F));
# 1320 "sdk/cutil_math.h"
return (((y * y)) * (((make_float3((3.0F))) - (((make_float3((2.0F))) * y)))));
# 1321 "sdk/cutil_math.h"
}
# 1322 "sdk/cutil_math.h"
inline float4 smoothstep(float4 a, float4 b, float4 x)
# 1323 "sdk/cutil_math.h"
{
# 1324 "sdk/cutil_math.h"
float4 y = clamp((((x - a)) / ((b - a))), (0.0F), (1.0F));
# 1325 "sdk/cutil_math.h"
return (((y * y)) * (((make_float4((3.0F))) - (((make_float4((2.0F))) * y)))));
# 1326 "sdk/cutil_math.h"
}
# 21 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
extern "C" { typedef unsigned uint; }
# 22 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
typedef unsigned char uchar;
# 25 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC, MODE_CATROM};
# 27 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
static texture< unsigned char, 2, cudaReadModeNormalizedFloat> tex;
# 31 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float w0(float a)
# 32 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 34 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * ((a * ((a * ((-a) + (3.0F))) - (3.0F))) + (1.0F));
# 35 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 38 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float w1(float a)
# 39 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 41 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * (((a * a) * (((3.0F) * a) - (6.0F))) + (4.0F));
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 45 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float w2(float a)
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 48 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * ((a * ((a * (((-(3.0F)) * a) + (3.0F))) + (3.0F))) + (1.0F));
# 49 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 52 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float w3(float a)
# 53 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 54 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * ((a * a) * a);
# 55 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 58 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
__attribute__((unused)) float g0(float a)
# 59 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 61 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 63 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
__attribute__((unused)) float g1(float a)
# 64 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 66 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 69 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
__attribute__((unused)) float h0(float a)
# 70 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 73 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 75 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
__attribute__((unused)) float h1(float a)
# 76 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 78 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 81 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T> __attribute__((unused)) T
# 83 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
cubicFilter(float x, T c0, T c1, T c2, T c3)
# 84 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 91 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 94 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T, class R> __attribute__((unused)) R
# 96 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
tex2DBicubic(const texture< T, 2, cudaReadModeNormalizedFloat> texref, float x, float y)
# 97 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 111 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 115 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T, class R> __attribute__((unused)) R
# 117 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
tex2DFastBicubic(const texture< T, 2, cudaReadModeNormalizedFloat> texref, float x, float y)
# 118 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 139 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 142 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T, class R> __attribute__((unused)) R
# 144 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
tex2DBilinear(const texture< T, 2, cudaReadModeNormalizedFloat> tex, float x, float y)
# 145 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 157 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 193 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float catrom_w0(float a)
# 194 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 196 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return a * ((-(0.5F)) + (a * ((1.0F) - ((0.5F) * a))));
# 197 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 200 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float catrom_w1(float a)
# 201 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 203 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return (1.0F) + ((a * a) * ((-(2.5F)) + ((1.5F) * a)));
# 204 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 207 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float catrom_w2(float a)
# 208 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 210 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return a * ((0.5F) + (a * ((2.0F) - ((1.5F) * a))));
# 211 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 214 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
float catrom_w3(float a)
# 215 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{
# 217 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
return (a * a) * ((-(0.5F)) + ((0.5F) * a));
# 218 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 220 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T> __attribute__((unused)) T
# 222 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
catRomFilter(float x, T c0, T c1, T c2, T c3)
# 223 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 230 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 233 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
template< class T, class R> __attribute__((unused)) R
# 235 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
tex2DCatRom(const texture< T, 2, cudaReadModeNormalizedFloat> texref, float x, float y)
# 236 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{int volatile ___ = 1;
# 250 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
exit(___);}
# 257 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
void d_render(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy) ;
# 277 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
void d_renderBicubic(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy) ;
# 295 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
void d_renderFastBicubic(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy) ;
# 313 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
void d_renderCatRom(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy) ;
# 26 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaArray *d_imageArray = (0);
# 29 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
extern "C" void initTexture(int imageWidth, int imageHeight, uchar *h_data)
# 30 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
{
# 32 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 33 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
__cudaSafeCall(cudaMallocArray(&d_imageArray, &channelDesc, imageWidth, imageHeight), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu", 33);
# 34 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
uint size = ((imageWidth * imageHeight) * sizeof(uchar));
# 35 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
__cudaSafeCall(cudaMemcpyToArray(d_imageArray, 0, 0, h_data, size, cudaMemcpyHostToDevice), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu", 35);
# 36 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cutFree(h_data);
# 39 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
((tex.addressMode)[0]) = cudaAddressModeClamp;
# 40 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
((tex.addressMode)[1]) = cudaAddressModeClamp;
# 41 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.normalized) = (false);
# 45 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
__cudaSafeCall(cudaBindTextureToArray(tex, d_imageArray, channelDesc), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu", 45);
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
}
# 49 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
extern "C" void freeTexture()
# 50 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
{
# 51 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
__cudaSafeCall(cudaFreeArray(d_imageArray), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu", 51);
# 52 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
}
# 57 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
extern "C" void render(int width, int height, float tx, float ty, float scale, float cx, float cy, dim3
# 58 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
blockSize, dim3 gridSize, int mode, uchar4 *output)
# 59 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
{
# 61 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
switch (mode) {
# 62 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
case MODE_NEAREST:
# 63 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModePoint;
# 64 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_render(output, width, height, tx, ty, scale, cx, cy);
# 65 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
break;
# 66 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
case MODE_BILINEAR:
# 67 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 68 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_render(output, width, height, tx, ty, scale, cx, cy);
# 69 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
break;
# 70 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
case MODE_BICUBIC:
# 71 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModePoint;
# 72 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_renderBicubic(output, width, height, tx, ty, scale, cx, cy);
# 73 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
break;
# 74 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
case MODE_FAST_BICUBIC:
# 75 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 76 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_renderFastBicubic(output, width, height, tx, ty, scale, cx, cy);
# 77 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
break;
# 78 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
case MODE_CATROM:
# 79 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
(tex.filterMode) = cudaFilterModePoint;
# 80 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_renderCatRom(output, width, height, tx, ty, scale, cx, cy);
# 81 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
break;
# 82 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
}
# 83 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
__cutilCheckMsg("kernel failed", "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu", 83);
# 84 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu"
}
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c" 1
# 1 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 1
# 91 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h"
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

# 1 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h" 1
# 90 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 1 3
# 948 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/math_constants.h" 1 3
# 949 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 2 3
# 2973 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/crt/func_macro.h" 1 3
# 2974 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 2 3
# 4683 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 3
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
# 5006 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.2/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 5007 "/usr/local/cuda3.2/cuda/bin/../include/math_functions.h" 2 3
# 91 "/usr/local/cuda3.2/cuda/bin/../include/common_functions.h" 2
# 164 "/usr/local/cuda3.2/cuda/bin/../include/crt/host_runtime.h" 2







#pragma pack()
# 2 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00007c90_00000000-3_bicubicTexture.fatbin.c" 1
# 1 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
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
# 152 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 166 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
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
# 203 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode,
        __cudaFatForcePTX
    } __cudaFatCompilationPolicy;
# 227 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 240 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
unsigned char fatCheckJitForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *ptx );
# 250 "/usr/local/cuda3.2/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );





void __cudaFatFreePTX( char* ptx );


}
# 2 "/tmp/tmpxft_00007c90_00000000-3_bicubicTexture.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x2e33616475632f6c\n"
".quad 0x6f2f616475632f32,0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f\n"
".quad 0x6220322e33206363,0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3830\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233662e206d6172,0x72616475635f5f20\n"
".quad 0x77325a5f5f667465,0x77325a5f20296630,0x7261702e28206630,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x325a5f5f31666d72,0x2e090a0a29663077,0x20656c6269736976\n"
".quad 0x2e2820636e75662e,0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6674657261\n"
".quad 0x5a5f202966317732,0x702e282066317732,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f31666d726170,0x0a0a29663177325a,0x6c62697369762e09,0x20636e75662e2065\n"
".quad 0x206d617261702e28,0x635f5f203233662e,0x5f66746572616475,0x2029663277325a5f\n"
".quad 0x2820663277325a5f,0x2e206d617261702e,0x75635f5f20323366,0x31666d7261706164\n"
".quad 0x29663277325a5f5f,0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063\n"
".quad 0x5f203233662e206d,0x746572616475635f,0x663377325a5f5f66,0x663377325a5f2029\n"
".quad 0x6d617261702e2820,0x5f5f203233662e20,0x6d72617061647563,0x3377325a5f5f3166\n"
".quad 0x69762e090a0a2966,0x662e20656c626973,0x61702e2820636e75,0x3233662e206d6172\n"
".quad 0x72616475635f5f20,0x67325a5f5f667465,0x67325a5f20296630,0x7261702e28206630\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x325a5f5f31666d72,0x2e090a0a29663067\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x662e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6674657261,0x5a5f202966316732,0x702e282066316732,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f31666d726170,0x0a0a29663167325a,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x206d617261702e28,0x635f5f203233662e,0x5f66746572616475\n"
".quad 0x2029663068325a5f,0x2820663068325a5f,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x31666d7261706164,0x29663068325a5f5f,0x697369762e090a0a,0x6e75662e20656c62\n"
".quad 0x617261702e282063,0x5f203233662e206d,0x746572616475635f,0x663168325a5f5f66\n"
".quad 0x663168325a5f2029,0x6d617261702e2820,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x3168325a5f5f3166,0x69762e090a0a2966,0x662e20656c626973,0x61702e2820636e75\n"
".quad 0x3233662e206d6172,0x72616475635f5f20,0x63395a5f5f667465,0x30775f6d6f727461\n"
".quad 0x6163395a5f202966,0x6630775f6d6f7274,0x6d617261702e2820,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x6163395a5f5f3166,0x6630775f6d6f7274,0x7369762e090a0a29\n"
".quad 0x75662e20656c6269,0x7261702e2820636e,0x203233662e206d61,0x6572616475635f5f\n"
".quad 0x6163395a5f5f6674,0x6631775f6d6f7274,0x746163395a5f2029,0x206631775f6d6f72\n"
".quad 0x206d617261702e28,0x635f5f203233662e,0x666d726170616475,0x746163395a5f5f31\n"
".quad 0x296631775f6d6f72,0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063\n"
".quad 0x5f203233662e206d,0x746572616475635f,0x746163395a5f5f66,0x296632775f6d6f72\n"
".quad 0x72746163395a5f20,0x28206632775f6d6f,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x31666d7261706164,0x72746163395a5f5f,0x0a296632775f6d6f,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x6d617261702e2820,0x5f5f203233662e20,0x6674657261647563\n"
".quad 0x72746163395a5f5f,0x20296633775f6d6f,0x6f72746163395a5f,0x2e28206633775f6d\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5f31666d72617061,0x6f72746163395a5f\n"
".quad 0x0a0a296633775f6d,0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28\n"
".quad 0x635f5f203233662e,0x5f66746572616475,0x6962756331315a5f,0x497265746c694663\n"
".quad 0x5f3053665f544566,0x30535f30535f3053,0x6331315a5f20295f,0x746c694663696275\n"
".quad 0x665f544566497265,0x30535f30535f3053,0x702e28205f30535f,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f31666d726170,0x636962756331315a,0x66497265746c6946\n"
".quad 0x535f3053665f5445,0x5f30535f30535f30,0x6d617261702e202c,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x6331315a5f5f3266,0x746c694663696275,0x665f544566497265\n"
".quad 0x30535f30535f3053,0x702e202c5f30535f,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f33666d726170,0x636962756331315a,0x66497265746c6946,0x535f3053665f5445\n"
".quad 0x5f30535f30535f30,0x6d617261702e202c,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x6331315a5f5f3466,0x746c694663696275,0x665f544566497265,0x30535f30535f3053\n"
".quad 0x702e202c5f30535f,0x33662e206d617261,0x616475635f5f2032,0x5f5f35666d726170\n"
".quad 0x636962756331315a,0x66497265746c6946,0x535f3053665f5445,0x5f30535f30535f30\n"
".quad 0x7369762e090a0a29,0x75662e20656c6269,0x7261702e2820636e,0x203233662e206d61\n"
".quad 0x6572616475635f5f,0x6332315a5f5f6674,0x6c69466d6f527461,0x5f54456649726574\n"
".quad 0x535f30535f305366,0x5f20295f30535f30,0x6f5274616332315a,0x497265746c69466d\n"
".quad 0x5f3053665f544566,0x30535f30535f3053,0x617261702e28205f,0x5f203233662e206d\n"
".quad 0x726170616475635f,0x32315a5f5f31666d,0x69466d6f52746163,0x544566497265746c\n"
".quad 0x5f30535f3053665f,0x202c5f30535f3053,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x32666d7261706164,0x74616332315a5f5f,0x65746c69466d6f52,0x53665f5445664972\n"
".quad 0x5f30535f30535f30,0x61702e202c5f3053,0x3233662e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f33666d7261,0x6d6f527461633231,0x66497265746c6946,0x535f3053665f5445\n"
".quad 0x5f30535f30535f30,0x6d617261702e202c,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x6332315a5f5f3466,0x6c69466d6f527461,0x5f54456649726574,0x535f30535f305366\n"
".quad 0x2e202c5f30535f30,0x662e206d61726170,0x6475635f5f203233,0x5f35666d72617061\n"
".quad 0x5274616332315a5f,0x7265746c69466d6f,0x3053665f54456649,0x535f30535f30535f\n"
".quad 0x2f2f090a0a295f30,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x202f2f090a2d2d2d,0x6e696c69706d6f43,0x742f706d742f2067,0x30305f746678706d\n"
".quad 0x305f303963373030,0x2d30303030303030,0x6962756369625f37,0x6572757478655463\n"
".quad 0x20692e337070632e,0x63632f706d742f28,0x673773552e234942,0x2d2f2f090a296e66\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2f2f090a0a2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x4f202f2f090a2d2d\n"
".quad 0x0a3a736e6f697470,0x2d2d2d2d2d2f2f09,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x090a2d2d2d2d2d2d,0x6772615420202f2f,0x202c7874703a7465,0x325f6d733a415349\n"
".quad 0x6169646e45202c30,0x656c7474696c3a6e,0x65746e696f50202c,0x363a657a69532072\n"
".quad 0x2d20202f2f090a34,0x6974704f2809334f,0x6e6f6974617a696d,0x0a296c6576656c20\n"
".quad 0x30672d20202f2f09,0x2067756265442809,0x090a296c6576656c,0x09326d2d20202f2f\n"
".quad 0x2074726f70655228,0x69726f7369766461,0x2d2f2f090a297365,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x69662e090a0a2d2d,0x633c22093109656c\n"
".quad 0x6c2d646e616d6d6f,0x2e090a223e656e69,0x22093209656c6966,0x706d742f706d742f\n"
".quad 0x303030305f746678,0x3030305f30396337,0x5f362d3030303030,0x5463696275636962\n"
".quad 0x632e657275747865,0x672e326566616475,0x69662e090a227570,0x752f22093309656c\n"
".quad 0x672f62696c2f7273,0x365f3638782f6363,0x2d78756e696c2d34,0x2e342e342f756e67\n"
".quad 0x64756c636e692f33,0x6665646474732f65,0x69662e090a22682e,0x752f22093409656c\n"
".quad 0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x7472632f6564756c,0x5f6563697665642f,0x2e656d69746e7572,0x6c69662e090a2268\n"
".quad 0x73752f2209350965,0x2f6c61636f6c2f72,0x2f322e3361647563,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x74736f682f656475,0x73656e696665645f,0x69662e090a22682e\n"
".quad 0x752f22093609656c,0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x6975622f6564756c,0x7079745f6e69746c,0x2e090a22682e7365\n"
".quad 0x22093709656c6966,0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e\n"
".quad 0x692f2e2e2f6e6962,0x642f6564756c636e,0x79745f6563697665,0x090a22682e736570\n"
".quad 0x093809656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f322e33\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x745f726576697264,0x0a22682e73657079\n"
".quad 0x3909656c69662e09,0x6c2f7273752f2209,0x6475632f6c61636f,0x6475632f322e3361\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x656361667275732f,0x682e73657079745f\n"
".quad 0x656c69662e090a22,0x73752f2209303109,0x2f6c61636f6c2f72,0x2f322e3361647563\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x747865742f656475,0x657079745f657275\n"
".quad 0x662e090a22682e73,0x2209313109656c69,0x636f6c2f7273752f,0x33616475632f6c61\n"
".quad 0x2f616475632f322e,0x692f2e2e2f6e6962,0x762f6564756c636e,0x79745f726f746365\n"
".quad 0x090a22682e736570,0x323109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f6563697665642f\n"
".quad 0x705f68636e75616c,0x726574656d617261,0x662e090a22682e73,0x2209333109656c69\n"
".quad 0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e,0x692f2e2e2f6e6962\n"
".quad 0x632f6564756c636e,0x61726f74732f7472,0x7373616c635f6567,0x69662e090a22682e\n"
".quad 0x2f2209343109656c,0x6c636e692f727375,0x737469622f656475,0x682e73657079742f\n"
".quad 0x656c69662e090a22,0x73752f2209353109,0x64756c636e692f72,0x682e656d69742f65\n"
".quad 0x656c69662e090a22,0x6f682f2209363109,0x6572646e612f656d,0x69736f7065722f77\n"
".quad 0x672f736569726f74,0x746f6c65636f7570,0x632f73747365742f,0x742f322e33616475\n"
".quad 0x6369622f73747365,0x7478655463696275,0x756369622f657275,0x7574786554636962\n"
".quad 0x656e72656b5f6572,0x090a226875632e6c,0x373109656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x5f6e6f6d6d6f632f,0x6e6f6974636e7566,0x662e090a22682e73,0x2209383109656c69\n"
".quad 0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e,0x692f2e2e2f6e6962\n"
".quad 0x6d2f6564756c636e,0x636e75665f687461,0x22682e736e6f6974,0x09656c69662e090a\n"
".quad 0x7273752f22093931,0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x5f6874616d2f6564,0x746e6174736e6f63,0x662e090a22682e73\n"
".quad 0x2209303209656c69,0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e\n"
".quad 0x692f2e2e2f6e6962,0x642f6564756c636e,0x75665f6563697665,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220931320965,0x6c61636f6c2f7273,0x322e33616475632f\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x696d6f74615f3131\n"
".quad 0x6974636e75665f63,0x090a22682e736e6f,0x323209656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x615f32315f6d732f,0x75665f63696d6f74,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220933320965,0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x6c62756f645f3331,0x6974636e75665f65\n"
".quad 0x090a22682e736e6f,0x343209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f,0x615f30325f6d732f\n"
".quad 0x75665f63696d6f74,0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220935320965\n"
".quad 0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x5f6d732f6564756c,0x6972746e695f3032,0x22682e736369736e,0x09656c69662e090a\n"
".quad 0x7273752f22093632,0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x61667275732f6564,0x74636e75665f6563,0x0a22682e736e6f69\n"
".quad 0x3209656c69662e09,0x2f7273752f220937,0x75632f6c61636f6c,0x75632f322e336164\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x7275747865742f65,0x5f68637465665f65\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209383209656c69,0x636f6c2f7273752f\n"
".quad 0x33616475632f6c61,0x2f616475632f322e,0x692f2e2e2f6e6962,0x6d2f6564756c636e\n"
".quad 0x636e75665f687461,0x62645f736e6f6974,0x682e337874705f6c,0x69762e090a0a0a22\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233662e206d6172,0x72616475635f5f20\n"
".quad 0x77325a5f5f667465,0x77325a5f20296630,0x7261702e28206630,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x325a5f5f31666d72,0x0a7b090a29663077,0x662e206765722e09\n"
".quad 0x32313c6625203233,0x636f6c2e090a3b3e,0x3009323309363109,0x67656257444c240a\n"
".quad 0x3077325a5f5f6e69,0x702e646c090a3a66,0x3233662e6d617261,0x5b202c3166250920\n"
".quad 0x6170616475635f5f,0x325a5f5f31666d72,0x6d090a3b5d663077,0x09203233662e766f\n"
".quad 0x316625202c326625,0x09636f6c2e090a3b,0x0a30093433093631,0x3233662e766f6d09\n"
".quad 0x30202c3366250920,0x3030303038663366,0x0920202020203b30,0x6f6d090a31202f2f\n"
".quad 0x2509203233662e76,0x30636630202c3466,0x203b303030303034,0x202f2f0920202020\n"
".quad 0x2e766f6d090a332d,0x3566250920323366,0x303430346630202c,0x2020203b30303030\n"
".quad 0x0a33202f2f092020,0x3233662e62757309,0x25202c3666250920,0x3b326625202c3566\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x202c326625202c37,0x346625202c366625\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x2c326625202c3866,0x6625202c37662520\n"
".quad 0x2e766f6d090a3b33,0x3966250920323366,0x613265336630202c,0x2020203b62616161\n"
".quad 0x2e30202f2f092020,0x090a373636363631,0x203233662e6c756d,0x25202c3031662509\n"
".quad 0x3b396625202c3866,0x7261702e7473090a,0x09203233662e6d61,0x72616475635f5f5b\n"
".quad 0x77325a5f5f667465,0x316625202c5d6630,0x3b746572090a3b30,0x646e6557444c240a\n"
".quad 0x3a663077325a5f5f,0x5f202f2f207d090a,0x090a0a663077325a,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323366,0x5f5f667465726164\n"
".quad 0x5f2029663177325a,0x2e2820663177325a,0x662e206d61726170,0x6475635f5f203233\n"
".quad 0x5f31666d72617061,0x0a29663177325a5f,0x6765722e090a7b09,0x6625203233662e20\n"
".quad 0x2e090a3b3e32313c,0x3309363109636f6c,0x57444c240a300939,0x5a5f5f6e69676562\n"
".quad 0x6c090a3a66317732,0x2e6d617261702e64,0x3166250920323366,0x6475635f5f5b202c\n"
".quad 0x5f31666d72617061,0x3b5d663177325a5f,0x33662e766f6d090a,0x202c326625092032\n"
".quad 0x6c2e090a3b316625,0x313409363109636f,0x2e766f6d090a3009,0x3366250920323366\n"
".quad 0x303830346630202c,0x2020203b30303030,0x0a34202f2f092020,0x3233662e766f6d09\n"
".quad 0x30202c3466250920,0x3030303063306366,0x0920202020203b30,0x6d090a362d202f2f\n"
".quad 0x09203233662e766f,0x346630202c356625,0x3b30303030303430,0x2f2f092020202020\n"
".quad 0x2e616d66090a3320,0x09203233662e6e72,0x356625202c366625,0x25202c326625202c\n"
".quad 0x6c756d090a3b3466,0x662509203233662e,0x202c326625202c37,0x6d66090a3b326625\n"
".quad 0x3233662e6e722e61,0x25202c3866250920,0x2c376625202c3666,0x6d090a3b33662520\n"
".quad 0x09203233662e766f,0x336630202c396625,0x3b62616161613265,0x2f2f092020202020\n"
".quad 0x36363636312e3020,0x662e6c756d090a37,0x3031662509203233,0x25202c386625202c\n"
".quad 0x2e7473090a3b3966,0x33662e6d61726170,0x75635f5f5b092032,0x5f5f667465726164\n"
".quad 0x202c5d663177325a,0x72090a3b30316625,0x57444c240a3b7465,0x77325a5f5f646e65\n"
".quad 0x2f207d090a3a6631,0x663177325a5f202f,0x697369762e090a0a,0x6e75662e20656c62\n"
".quad 0x617261702e282063,0x5f203233662e206d,0x746572616475635f,0x663277325a5f5f66\n"
".quad 0x663277325a5f2029,0x6d617261702e2820,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x3277325a5f5f3166,0x2e090a7b090a2966,0x3233662e20676572,0x3b3e33313c662520\n"
".quad 0x3109636f6c2e090a,0x240a300936340936,0x6e6967656257444c,0x3a663277325a5f5f\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c316625,0x6d72617061647563\n"
".quad 0x3277325a5f5f3166,0x766f6d090a3b5d66,0x662509203233662e,0x0a3b316625202c32\n"
".quad 0x363109636f6c2e09,0x6d090a3009383409,0x09203233662e766f,0x336630202c336625\n"
".quad 0x3b30303030303866,0x2f2f092020202020,0x2e766f6d090a3120,0x3466250920323366\n"
".quad 0x303430346630202c,0x2020203b30303030,0x0a33202f2f092020,0x3233662e766f6d09\n"
".quad 0x30202c3566250920,0x3030303034303466,0x0920202020203b30,0x6f6d090a33202f2f\n"
".quad 0x2509203233662e76,0x30636630202c3666,0x203b303030303034,0x202f2f0920202020\n"
".quad 0x2e616d66090a332d,0x09203233662e6e72,0x366625202c376625,0x25202c326625202c\n"
".quad 0x616d66090a3b3566,0x203233662e6e722e,0x6625202c38662509,0x202c376625202c32\n"
".quad 0x6d66090a3b346625,0x3233662e6e722e61,0x25202c3966250920,0x2c386625202c3266\n"
".quad 0x6d090a3b33662520,0x09203233662e766f,0x6630202c30316625,0x6261616161326533\n"
".quad 0x2f2f09202020203b,0x36363636312e3020,0x662e6c756d090a37,0x3131662509203233\n"
".quad 0x25202c396625202c,0x7473090a3b303166,0x662e6d617261702e,0x635f5f5b09203233\n"
".quad 0x5f66746572616475,0x2c5d663277325a5f,0x090a3b3131662520,0x444c240a3b746572\n"
".quad 0x325a5f5f646e6557,0x207d090a3a663277,0x3277325a5f202f2f,0x7369762e090a0a66\n"
".quad 0x75662e20656c6269,0x7261702e2820636e,0x203233662e206d61,0x6572616475635f5f\n"
".quad 0x3377325a5f5f6674,0x3377325a5f202966,0x617261702e282066,0x5f203233662e206d\n"
".quad 0x726170616475635f,0x77325a5f5f31666d,0x090a7b090a296633,0x33662e206765722e\n"
".quad 0x3b3e383c66252032,0x3109636f6c2e090a,0x240a300933350936,0x6e6967656257444c\n"
".quad 0x3a663377325a5f5f,0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c316625\n"
".quad 0x6d72617061647563,0x3377325a5f5f3166,0x766f6d090a3b5d66,0x662509203233662e\n"
".quad 0x0a3b316625202c32,0x363109636f6c2e09,0x6d090a3009343509,0x09203233662e6c75\n"
".quad 0x326625202c336625,0x090a3b326625202c,0x203233662e6c756d,0x6625202c34662509\n"
".quad 0x0a3b336625202c32,0x3233662e766f6d09,0x30202c3566250920,0x6161616132653366\n"
".quad 0x0920202020203b62,0x3636312e30202f2f,0x6c756d090a373636,0x662509203233662e\n"
".quad 0x202c346625202c36,0x7473090a3b356625,0x662e6d617261702e,0x635f5f5b09203233\n"
".quad 0x5f66746572616475,0x2c5d663377325a5f,0x72090a3b36662520,0x57444c240a3b7465\n"
".quad 0x77325a5f5f646e65,0x2f207d090a3a6633,0x663377325a5f202f,0x697369762e090a0a\n"
".quad 0x6e75662e20656c62,0x617261702e282063,0x5f203233662e206d,0x746572616475635f\n"
".quad 0x663067325a5f5f66,0x663067325a5f2029,0x6d617261702e2820,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x3067325a5f5f3166,0x2e090a7b090a2966,0x3233662e20676572\n"
".quad 0x3b3e30323c662520,0x3109636f6c2e090a,0x240a300939350936,0x6e6967656257444c\n"
".quad 0x3a663067325a5f5f,0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c316625\n"
".quad 0x6d72617061647563,0x3067325a5f5f3166,0x766f6d090a3b5d66,0x662509203233662e\n"
".quad 0x0a3b316625202c32,0x363109636f6c2e09,0x6d090a3009303609,0x09203233662e766f\n"
".quad 0x346630202c336625,0x3b30303030303830,0x2f2f092020202020,0x2e766f6d090a3420\n"
".quad 0x3466250920323366,0x306330636630202c,0x2020203b30303030,0x362d202f2f092020\n"
".quad 0x33662e766f6d090a,0x202c356625092032,0x3030303430346630,0x20202020203b3030\n"
".quad 0x66090a33202f2f09,0x33662e6e722e616d,0x202c366625092032,0x326625202c356625\n"
".quad 0x090a3b346625202c,0x203233662e6c756d,0x6625202c37662509,0x0a3b326625202c32\n"
".quad 0x2e6e722e616d6609,0x3866250920323366,0x25202c366625202c,0x3b336625202c3766\n"
".quad 0x33662e766f6d090a,0x202c396625092032,0x6161613265336630,0x20202020203b6261\n"
".quad 0x36312e30202f2f09,0x756d090a37363636,0x2509203233662e6c,0x386625202c303166\n"
".quad 0x090a3b396625202c,0x203233662e766f6d,0x30202c3131662509,0x3030303038663366\n"
".quad 0x2f09202020203b30,0x766f6d090a31202f,0x662509203233662e,0x30636630202c3231\n"
".quad 0x203b303030303034,0x2d202f2f09202020,0x662e766f6d090a33,0x3331662509203233\n"
".quad 0x303430346630202c,0x2020203b30303030,0x090a33202f2f0920,0x203233662e627573\n"
".quad 0x25202c3431662509,0x326625202c333166,0x722e616d66090a3b,0x2509203233662e6e\n"
".quad 0x326625202c353166,0x202c34316625202c,0x66090a3b32316625,0x33662e6e722e616d\n"
".quad 0x2c36316625092032,0x6625202c32662520,0x31316625202c3531,0x662e766f6d090a3b\n"
".quad 0x3731662509203233,0x613265336630202c,0x2020203b62616161,0x312e30202f2f0920\n"
".quad 0x66090a3736363636,0x33662e6e722e616d,0x2c38316625092032,0x25202c3631662520\n"
".quad 0x316625202c373166,0x702e7473090a3b30,0x3233662e6d617261,0x6475635f5f5b0920\n"
".quad 0x5a5f5f6674657261,0x25202c5d66306732,0x6572090a3b383166,0x6557444c240a3b74\n"
".quad 0x3067325a5f5f646e,0x2f2f207d090a3a66,0x0a663067325a5f20,0x62697369762e090a\n"
".quad 0x636e75662e20656c,0x6d617261702e2820,0x5f5f203233662e20,0x6674657261647563\n"
".quad 0x29663167325a5f5f,0x20663167325a5f20,0x206d617261702e28,0x635f5f203233662e\n"
".quad 0x666d726170616475,0x663167325a5f5f31,0x722e090a7b090a29,0x203233662e206765\n"
".quad 0x0a3b3e37313c6625,0x363109636f6c2e09,0x4c240a3009343609,0x5f6e696765625744\n"
".quad 0x0a3a663167325a5f,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3166\n"
".quad 0x666d726170616475,0x663167325a5f5f31,0x2e766f6d090a3b5d,0x3266250920323366\n"
".quad 0x090a3b316625202c,0x09363109636f6c2e,0x756d090a30093536,0x2509203233662e6c\n"
".quad 0x2c326625202c3366,0x6d090a3b32662520,0x09203233662e6c75,0x326625202c346625\n"
".quad 0x090a3b336625202c,0x203233662e766f6d,0x6630202c35662509,0x6261616161326533\n"
".quad 0x2f0920202020203b,0x363636312e30202f,0x2e6c756d090a3736,0x3666250920323366\n"
".quad 0x25202c346625202c,0x766f6d090a3b3566,0x662509203233662e,0x3866336630202c37\n"
".quad 0x20203b3030303030,0x31202f2f09202020,0x33662e766f6d090a,0x202c386625092032\n"
".quad 0x3030303430346630,0x20202020203b3030,0x6d090a33202f2f09,0x09203233662e766f\n"
".quad 0x346630202c396625,0x3b30303030303430,0x2f2f092020202020,0x2e766f6d090a3320\n"
".quad 0x3166250920323366,0x3430636630202c30,0x20203b3030303030,0x332d202f2f092020\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x30316625202c3131,0x25202c326625202c\n"
".quad 0x616d66090a3b3966,0x203233662e6e722e,0x25202c3231662509,0x31316625202c3266\n"
".quad 0x090a3b386625202c,0x662e6e722e616d66,0x3331662509203233,0x25202c326625202c\n"
".quad 0x376625202c323166,0x662e766f6d090a3b,0x3431662509203233,0x613265336630202c\n"
".quad 0x2020203b62616161,0x312e30202f2f0920,0x66090a3736363636,0x33662e6e722e616d\n"
".quad 0x2c35316625092032,0x25202c3331662520,0x366625202c343166,0x61702e7473090a3b\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x325a5f5f66746572,0x6625202c5d663167\n"
".quad 0x746572090a3b3531,0x6e6557444c240a3b,0x663167325a5f5f64,0x202f2f207d090a3a\n"
".quad 0x0a0a663167325a5f,0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28\n"
".quad 0x635f5f203233662e,0x5f66746572616475,0x2029663068325a5f,0x2820663068325a5f\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x31666d7261706164,0x29663068325a5f5f\n"
".quad 0x65722e090a7b090a,0x25203233662e2067,0x090a3b3e35323c66,0x09363109636f6c2e\n"
".quad 0x444c240a30093037,0x5f5f6e6967656257,0x090a3a663068325a,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c31,0x31666d7261706164,0x5d663068325a5f5f\n"
".quad 0x662e766f6d090a3b,0x2c32662509203233,0x2e090a3b31662520,0x3709363109636f6c\n"
".quad 0x766f6d090a300932,0x662509203233662e,0x6330636630202c33,0x20203b3030303030\n"
".quad 0x2d202f2f09202020,0x662e766f6d090a36,0x2c34662509203233,0x3030343034663020\n"
".quad 0x202020203b303030,0x090a33202f2f0920,0x662e6e722e616d66,0x2c35662509203233\n"
".quad 0x6625202c34662520,0x0a3b336625202c32,0x3233662e6c756d09,0x25202c3666250920\n"
".quad 0x3b326625202c3266,0x33662e766f6d090a,0x202c376625092032,0x3030303830346630\n"
".quad 0x20202020203b3030,0x66090a34202f2f09,0x33662e6e722e616d,0x202c386625092032\n"
".quad 0x366625202c356625,0x090a3b376625202c,0x203233662e766f6d,0x6630202c39662509\n"
".quad 0x6261616161326533,0x2f0920202020203b,0x363636312e30202f,0x2e6c756d090a3736\n"
".quad 0x3166250920323366,0x202c386625202c30,0x6f6d090a3b396625,0x2509203233662e76\n"
".quad 0x336630202c313166,0x3b30303030303866,0x202f2f0920202020,0x662e766f6d090a31\n"
".quad 0x3231662509203233,0x303430636630202c,0x2020203b30303030,0x0a332d202f2f0920\n"
".quad 0x3233662e766f6d09,0x202c333166250920,0x3030303430346630,0x09202020203b3030\n"
".quad 0x7573090a33202f2f,0x2509203233662e62,0x316625202c343166,0x0a3b326625202c33\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x202c326625202c35,0x6625202c34316625\n"
".quad 0x616d66090a3b3231,0x203233662e6e722e,0x25202c3631662509,0x35316625202c3266\n"
".quad 0x0a3b31316625202c,0x3233662e766f6d09,0x202c373166250920,0x6161613265336630\n"
".quad 0x09202020203b6261,0x3636312e30202f2f,0x616d66090a373636,0x203233662e6e722e\n"
".quad 0x25202c3831662509,0x316625202c363166,0x3b30316625202c37,0x6e722e766964090a\n"
".quad 0x662509203233662e,0x30316625202c3931,0x0a3b38316625202c,0x3233662e766f6d09\n"
".quad 0x202c303266250920,0x3030303866626630,0x09202020203b3030,0x61090a312d202f2f\n"
".quad 0x09203233662e6464,0x6625202c31326625,0x30326625202c3931,0x662e766f6d090a3b\n"
".quad 0x3232662509203233,0x303066336630202c,0x2020203b30303030,0x352e30202f2f0920\n"
".quad 0x33662e646461090a,0x2c33326625092032,0x25202c3132662520,0x7473090a3b323266\n"
".quad 0x662e6d617261702e,0x635f5f5b09203233,0x5f66746572616475,0x2c5d663068325a5f\n"
".quad 0x090a3b3332662520,0x444c240a3b746572,0x325a5f5f646e6557,0x207d090a3a663068\n"
".quad 0x3068325a5f202f2f,0x7369762e090a0a66,0x75662e20656c6269,0x7261702e2820636e\n"
".quad 0x203233662e206d61,0x6572616475635f5f,0x3168325a5f5f6674,0x3168325a5f202966\n"
".quad 0x617261702e282066,0x5f203233662e206d,0x726170616475635f,0x68325a5f5f31666d\n"
".quad 0x090a7b090a296631,0x33662e206765722e,0x3e32323c66252032,0x09636f6c2e090a3b\n"
".quad 0x0a30093637093631,0x6967656257444c24,0x663168325a5f5f6e,0x61702e646c090a3a\n"
".quad 0x203233662e6d6172,0x5f5b202c31662509,0x726170616475635f,0x68325a5f5f31666d\n"
".quad 0x6f6d090a3b5d6631,0x2509203233662e76,0x3b316625202c3266,0x3109636f6c2e090a\n"
".quad 0x090a300937370936,0x203233662e6c756d,0x6625202c33662509,0x0a3b326625202c32\n"
".quad 0x3233662e6c756d09,0x25202c3466250920,0x3b326625202c3366,0x33662e766f6d090a\n"
".quad 0x202c356625092032,0x6161613265336630,0x20202020203b6261,0x36312e30202f2f09\n"
".quad 0x756d090a37363636,0x2509203233662e6c,0x2c346625202c3666,0x6d090a3b35662520\n"
".quad 0x09203233662e766f,0x336630202c376625,0x3b30303030303866,0x2f2f092020202020\n"
".quad 0x2e766f6d090a3120,0x3866250920323366,0x303430346630202c,0x2020203b30303030\n"
".quad 0x0a33202f2f092020,0x3233662e766f6d09,0x30202c3966250920,0x3030303034303466\n"
".quad 0x0920202020203b30,0x6f6d090a33202f2f,0x2509203233662e76,0x636630202c303166\n"
".quad 0x3b30303030303430,0x202f2f0920202020,0x2e616d66090a332d,0x09203233662e6e72\n"
".quad 0x6625202c31316625,0x2c326625202c3031,0x66090a3b39662520,0x33662e6e722e616d\n"
".quad 0x2c32316625092032,0x6625202c32662520,0x3b386625202c3131,0x6e722e616d66090a\n"
".quad 0x662509203233662e,0x2c326625202c3331,0x25202c3231662520,0x766f6d090a3b3766\n"
".quad 0x662509203233662e,0x65336630202c3431,0x203b626161616132,0x30202f2f09202020\n"
".quad 0x0a3736363636312e,0x2e6e722e616d6609,0x3166250920323366,0x2c33316625202c35\n"
".quad 0x25202c3431662520,0x766964090a3b3666,0x203233662e6e722e,0x25202c3631662509\n"
".quad 0x35316625202c3666,0x662e766f6d090a3b,0x3731662509203233,0x303866336630202c\n"
".quad 0x2020203b30303030,0x090a31202f2f0920,0x203233662e646461,0x25202c3831662509\n"
".quad 0x316625202c363166,0x2e766f6d090a3b37,0x3166250920323366,0x3066336630202c39\n"
".quad 0x20203b3030303030,0x2e30202f2f092020,0x662e646461090a35,0x3032662509203233\n"
".quad 0x202c38316625202c,0x73090a3b39316625,0x2e6d617261702e74,0x5f5f5b0920323366\n"
".quad 0x6674657261647563,0x5d663168325a5f5f,0x0a3b30326625202c,0x4c240a3b74657209\n"
".quad 0x5a5f5f646e655744,0x7d090a3a66316832,0x68325a5f202f2f20,0x69762e090a0a6631\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233662e206d6172,0x72616475635f5f20\n"
".quad 0x63395a5f5f667465,0x30775f6d6f727461,0x6163395a5f202966,0x6630775f6d6f7274\n"
".quad 0x6d617261702e2820,0x5f5f203233662e20,0x6d72617061647563,0x6163395a5f5f3166\n"
".quad 0x6630775f6d6f7274,0x722e090a7b090a29,0x203233662e206765,0x0a3b3e31313c6625\n"
".quad 0x363109636f6c2e09,0x240a300934393109,0x6e6967656257444c,0x72746163395a5f5f\n"
".quad 0x0a3a6630775f6d6f,0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3166\n"
".quad 0x666d726170616475,0x746163395a5f5f31,0x5d6630775f6d6f72,0x662e766f6d090a3b\n"
".quad 0x2c32662509203233,0x2e090a3b31662520,0x3109363109636f6c,0x6f6d090a30093639\n"
".quad 0x2509203233662e76,0x66626630202c3366,0x203b303030303030,0x202f2f0920202020\n"
".quad 0x6f6d090a352e302d,0x2509203233662e76,0x66336630202c3466,0x203b303030303038\n"
".quad 0x202f2f0920202020,0x662e766f6d090a31,0x2c35662509203233,0x3030306633663020\n"
".quad 0x202020203b303030,0x352e30202f2f0920,0x33662e6c756d090a,0x202c366625092032\n"
".quad 0x326625202c356625,0x662e627573090a3b,0x2c37662509203233,0x6625202c34662520\n"
".quad 0x2e616d66090a3b36,0x09203233662e6e72,0x326625202c386625,0x25202c376625202c\n"
".quad 0x6c756d090a3b3366,0x662509203233662e,0x202c326625202c39,0x7473090a3b386625\n"
".quad 0x662e6d617261702e,0x635f5f5b09203233,0x5f66746572616475,0x6f72746163395a5f\n"
".quad 0x202c5d6630775f6d,0x6572090a3b396625,0x6557444c240a3b74,0x6163395a5f5f646e\n"
".quad 0x6630775f6d6f7274,0x202f2f207d090a3a,0x6f72746163395a5f,0x090a0a6630775f6d\n"
".quad 0x656c62697369762e,0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323366\n"
".quad 0x5f5f667465726164,0x6d6f72746163395a,0x5a5f20296631775f,0x5f6d6f7274616339\n"
".quad 0x61702e2820663177,0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f31666d7261\n"
".quad 0x5f6d6f7274616339,0x0a7b090a29663177,0x662e206765722e09,0x30313c6625203233\n"
".quad 0x636f6c2e090a3b3e,0x0931303209363109,0x656257444c240a30,0x63395a5f5f6e6967\n"
".quad 0x31775f6d6f727461,0x702e646c090a3a66,0x3233662e6d617261,0x5b202c3166250920\n"
".quad 0x6170616475635f5f,0x395a5f5f31666d72,0x775f6d6f72746163,0x6f6d090a3b5d6631\n"
".quad 0x2509203233662e76,0x3b316625202c3266,0x3109636f6c2e090a,0x0a30093330320936\n"
".quad 0x3233662e766f6d09,0x30202c3366250920,0x3030303038663366,0x0920202020203b30\n"
".quad 0x6f6d090a31202f2f,0x2509203233662e76,0x30636630202c3466,0x203b303030303032\n"
".quad 0x202f2f0920202020,0x6f6d090a352e322d,0x2509203233662e76,0x66336630202c3566\n"
".quad 0x203b303030303063,0x202f2f0920202020,0x616d66090a352e31,0x203233662e6e722e\n"
".quad 0x6625202c36662509,0x202c326625202c35,0x756d090a3b346625,0x2509203233662e6c\n"
".quad 0x2c326625202c3766,0x66090a3b32662520,0x33662e6e722e616d,0x202c386625092032\n"
".quad 0x376625202c366625,0x090a3b336625202c,0x6d617261702e7473,0x5f5b09203233662e\n"
".quad 0x746572616475635f,0x746163395a5f5f66,0x5d6631775f6d6f72,0x090a3b386625202c\n"
".quad 0x444c240a3b746572,0x395a5f5f646e6557,0x775f6d6f72746163,0x2f207d090a3a6631\n"
".quad 0x746163395a5f202f,0x0a6631775f6d6f72,0x62697369762e090a,0x636e75662e20656c\n"
".quad 0x6d617261702e2820,0x5f5f203233662e20,0x6674657261647563,0x72746163395a5f5f\n"
".quad 0x20296632775f6d6f,0x6f72746163395a5f,0x2e28206632775f6d,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5f31666d72617061,0x6f72746163395a5f,0x090a296632775f6d\n"
".quad 0x206765722e090a7b,0x3c6625203233662e,0x6c2e090a3b3e3131,0x303209363109636f\n"
".quad 0x57444c240a300938,0x5a5f5f6e69676562,0x5f6d6f7274616339,0x646c090a3a663277\n"
".quad 0x662e6d617261702e,0x2c31662509203233,0x616475635f5f5b20,0x5f5f31666d726170\n"
".quad 0x6d6f72746163395a,0x090a3b5d6632775f,0x203233662e766f6d,0x6625202c32662509\n"
".quad 0x636f6c2e090a3b31,0x0930313209363109,0x662e766f6d090a30,0x2c33662509203233\n"
".quad 0x3030306633663020,0x202020203b303030,0x352e30202f2f0920,0x33662e766f6d090a\n"
".quad 0x202c346625092032,0x3030303030346630,0x20202020203b3030,0x6d090a32202f2f09\n"
".quad 0x09203233662e766f,0x336630202c356625,0x3b30303030306366,0x2f2f092020202020\n"
".quad 0x756d090a352e3120,0x2509203233662e6c,0x2c356625202c3666,0x73090a3b32662520\n"
".quad 0x09203233662e6275,0x346625202c376625,0x090a3b366625202c,0x662e6e722e616d66\n"
".quad 0x2c38662509203233,0x6625202c32662520,0x0a3b336625202c37,0x3233662e6c756d09\n"
".quad 0x25202c3966250920,0x3b386625202c3266,0x7261702e7473090a,0x09203233662e6d61\n"
".quad 0x72616475635f5f5b,0x63395a5f5f667465,0x32775f6d6f727461,0x3b396625202c5d66\n"
".quad 0x240a3b746572090a,0x5f5f646e6557444c,0x6d6f72746163395a,0x7d090a3a6632775f\n"
".quad 0x63395a5f202f2f20,0x32775f6d6f727461,0x7369762e090a0a66,0x75662e20656c6269\n"
".quad 0x7261702e2820636e,0x203233662e206d61,0x6572616475635f5f,0x6163395a5f5f6674\n"
".quad 0x6633775f6d6f7274,0x746163395a5f2029,0x206633775f6d6f72,0x206d617261702e28\n"
".quad 0x635f5f203233662e,0x666d726170616475,0x746163395a5f5f31,0x296633775f6d6f72\n"
".quad 0x65722e090a7b090a,0x25203233662e2067,0x2e090a3b3e393c66,0x3209363109636f6c\n"
".quad 0x444c240a30093531,0x5f5f6e6967656257,0x6d6f72746163395a,0x6c090a3a6633775f\n"
".quad 0x2e6d617261702e64,0x3166250920323366,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x6f72746163395a5f,0x0a3b5d6633775f6d,0x3233662e766f6d09,0x25202c3266250920\n"
".quad 0x6f6c2e090a3b3166,0x3731320936310963,0x2e766f6d090a3009,0x3366250920323366\n"
".quad 0x303066626630202c,0x2020203b30303030,0x302d202f2f092020,0x2e766f6d090a352e\n"
".quad 0x3466250920323366,0x303066336630202c,0x2020203b30303030,0x2e30202f2f092020\n"
".quad 0x722e616d66090a35,0x2509203233662e6e,0x2c346625202c3566,0x6625202c32662520\n"
".quad 0x2e6c756d090a3b33,0x3666250920323366,0x25202c326625202c,0x6c756d090a3b3266\n"
".quad 0x662509203233662e,0x202c356625202c37,0x7473090a3b366625,0x662e6d617261702e\n"
".quad 0x635f5f5b09203233,0x5f66746572616475,0x6f72746163395a5f,0x202c5d6633775f6d\n"
".quad 0x6572090a3b376625,0x6557444c240a3b74,0x6163395a5f5f646e,0x6633775f6d6f7274\n"
".quad 0x202f2f207d090a3a,0x6f72746163395a5f,0x090a0a6633775f6d,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323366,0x5f5f667465726164\n"
".quad 0x636962756331315a,0x66497265746c6946,0x535f3053665f5445,0x5f30535f30535f30\n"
".quad 0x756331315a5f2029,0x65746c6946636962,0x53665f5445664972,0x5f30535f30535f30\n"
".quad 0x61702e28205f3053,0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f31666d7261\n"
".quad 0x4663696275633131,0x4566497265746c69,0x30535f3053665f54,0x2c5f30535f30535f\n"
".quad 0x206d617261702e20,0x635f5f203233662e,0x666d726170616475,0x756331315a5f5f32\n"
".quad 0x65746c6946636962,0x53665f5445664972,0x5f30535f30535f30,0x61702e202c5f3053\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f33666d7261,0x4663696275633131\n"
".quad 0x4566497265746c69,0x30535f3053665f54,0x2c5f30535f30535f,0x206d617261702e20\n"
".quad 0x635f5f203233662e,0x666d726170616475,0x756331315a5f5f34,0x65746c6946636962\n"
".quad 0x53665f5445664972,0x5f30535f30535f30,0x61702e202c5f3053,0x3233662e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f35666d7261,0x4663696275633131,0x4566497265746c69\n"
".quad 0x30535f3053665f54,0x295f30535f30535f,0x65722e090a7b090a,0x25203233662e2067\n"
".quad 0x090a3b3e34343c66,0x09363109636f6c2e,0x444c240a30093438,0x5f5f6e6967656257\n"
".quad 0x636962756331315a,0x66497265746c6946,0x535f3053665f5445,0x5f30535f30535f30\n"
".quad 0x61702e646c090a3a,0x203233662e6d6172,0x5f5b202c31662509,0x726170616475635f\n"
".quad 0x31315a5f5f31666d,0x6c69466369627563,0x5f54456649726574,0x535f30535f305366\n"
".quad 0x0a3b5d5f30535f30,0x3233662e766f6d09,0x25202c3266250920,0x2e646c090a3b3166\n"
".quad 0x33662e6d61726170,0x202c336625092032,0x70616475635f5f5b,0x5a5f5f32666d7261\n"
".quad 0x4663696275633131,0x4566497265746c69,0x30535f3053665f54,0x5d5f30535f30535f\n"
".quad 0x662e766f6d090a3b,0x2c34662509203233,0x6c090a3b33662520,0x2e6d617261702e64\n"
".quad 0x3566250920323366,0x6475635f5f5b202c,0x5f33666d72617061,0x6962756331315a5f\n"
".quad 0x497265746c694663,0x5f3053665f544566,0x30535f30535f3053,0x766f6d090a3b5d5f\n"
".quad 0x662509203233662e,0x0a3b356625202c36,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x635f5f5b202c3766,0x666d726170616475,0x756331315a5f5f34,0x65746c6946636962\n"
".quad 0x53665f5445664972,0x5f30535f30535f30,0x6d090a3b5d5f3053,0x09203233662e766f\n"
".quad 0x376625202c386625,0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c39662509\n"
".quad 0x726170616475635f,0x31315a5f5f35666d,0x6c69466369627563,0x5f54456649726574\n"
".quad 0x535f30535f305366,0x0a3b5d5f30535f30,0x3233662e766f6d09,0x202c303166250920\n"
".quad 0x6c2e090a3b396625,0x303909363109636f,0x2e6c756d090a3009,0x3166250920323366\n"
".quad 0x202c326625202c31,0x6f6d090a3b326625,0x2509203233662e76,0x336630202c323166\n"
".quad 0x3b30303030303866,0x202f2f0920202020,0x662e766f6d090a31,0x3331662509203233\n"
".quad 0x303430636630202c,0x2020203b30303030,0x0a332d202f2f0920,0x3233662e766f6d09\n"
".quad 0x202c343166250920,0x3030303430346630,0x09202020203b3030,0x7573090a33202f2f\n"
".quad 0x2509203233662e62,0x316625202c353166,0x0a3b326625202c34,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x202c326625202c36,0x6625202c35316625,0x616d66090a3b3331\n"
".quad 0x203233662e6e722e,0x25202c3731662509,0x36316625202c3266,0x0a3b32316625202c\n"
".quad 0x3233662e766f6d09,0x202c383166250920,0x6161613265336630,0x09202020203b6261\n"
".quad 0x3636312e30202f2f,0x6c756d090a373636,0x662509203233662e,0x37316625202c3931\n"
".quad 0x0a3b38316625202c,0x3233662e6c756d09,0x202c303266250920,0x316625202c346625\n"
".quad 0x2e766f6d090a3b39,0x3266250920323366,0x3830346630202c31,0x20203b3030303030\n"
".quad 0x0a34202f2f092020,0x3233662e766f6d09,0x202c323266250920,0x3030306330636630\n"
".quad 0x09202020203b3030,0x6d090a362d202f2f,0x09203233662e766f,0x6630202c33326625\n"
".quad 0x3030303030343034,0x2f2f09202020203b,0x2e616d66090a3320,0x09203233662e6e72\n"
".quad 0x6625202c34326625,0x2c326625202c3332,0x090a3b3232662520,0x662e6e722e616d66\n"
".quad 0x3532662509203233,0x202c34326625202c,0x6625202c31316625,0x766f6d090a3b3132\n"
".quad 0x662509203233662e,0x65336630202c3632,0x203b626161616132,0x30202f2f09202020\n"
".quad 0x0a3736363636312e,0x3233662e6c756d09,0x202c373266250920,0x6625202c35326625\n"
".quad 0x616d66090a3b3632,0x203233662e6e722e,0x25202c3832662509,0x37326625202c3666\n"
".quad 0x0a3b30326625202c,0x3233662e766f6d09,0x202c393266250920,0x3030303866336630\n"
".quad 0x09202020203b3030,0x6f6d090a31202f2f,0x2509203233662e76,0x346630202c303366\n"
".quad 0x3b30303030303430,0x202f2f0920202020,0x662e766f6d090a33,0x3133662509203233\n"
".quad 0x303430346630202c,0x2020203b30303030,0x090a33202f2f0920,0x203233662e766f6d\n"
".quad 0x30202c3233662509,0x3030303034306366,0x2f09202020203b30,0x6d66090a332d202f\n"
".quad 0x3233662e6e722e61,0x202c333366250920,0x6625202c32336625,0x3b31336625202c32\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x2c326625202c3433,0x25202c3333662520\n"
".quad 0x6d66090a3b303366,0x3233662e6e722e61,0x202c353366250920,0x336625202c326625\n"
".quad 0x3b39326625202c34,0x33662e766f6d090a,0x2c36336625092032,0x6161326533663020\n"
".quad 0x202020203b626161,0x36312e30202f2f09,0x756d090a37363636,0x2509203233662e6c\n"
".quad 0x336625202c373366,0x3b36336625202c35,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x2c386625202c3833,0x25202c3733662520,0x756d090a3b383266,0x2509203233662e6c\n"
".quad 0x316625202c393366,0x0a3b326625202c31,0x3233662e766f6d09,0x202c303466250920\n"
".quad 0x6161613265336630,0x09202020203b6261,0x3636312e30202f2f,0x6c756d090a373636\n"
".quad 0x662509203233662e,0x39336625202c3134,0x0a3b30346625202c,0x2e6e722e616d6609\n"
".quad 0x3466250920323366,0x2c30316625202c32,0x25202c3134662520,0x7473090a3b383366\n"
".quad 0x662e6d617261702e,0x635f5f5b09203233,0x5f66746572616475,0x6962756331315a5f\n"
".quad 0x497265746c694663,0x5f3053665f544566,0x30535f30535f3053,0x32346625202c5d5f\n"
".quad 0x0a3b746572090a3b,0x5f646e6557444c24,0x6962756331315a5f,0x497265746c694663\n"
".quad 0x5f3053665f544566,0x30535f30535f3053,0x2f2f207d090a3a5f,0x62756331315a5f20\n"
".quad 0x7265746c69466369,0x3053665f54456649,0x535f30535f30535f,0x69762e090a0a5f30\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233662e206d6172,0x72616475635f5f20\n"
".quad 0x32315a5f5f667465,0x69466d6f52746163,0x544566497265746c,0x5f30535f3053665f\n"
".quad 0x20295f30535f3053,0x5274616332315a5f,0x7265746c69466d6f,0x3053665f54456649\n"
".quad 0x535f30535f30535f,0x7261702e28205f30,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f31666d72,0x466d6f5274616332,0x4566497265746c69,0x30535f3053665f54\n"
".quad 0x2c5f30535f30535f,0x206d617261702e20,0x635f5f203233662e,0x666d726170616475\n"
".quad 0x616332315a5f5f32,0x746c69466d6f5274,0x665f544566497265,0x30535f30535f3053\n"
".quad 0x702e202c5f30535f,0x33662e206d617261,0x616475635f5f2032,0x5f5f33666d726170\n"
".quad 0x6f5274616332315a,0x497265746c69466d,0x5f3053665f544566,0x30535f30535f3053\n"
".quad 0x617261702e202c5f,0x5f203233662e206d,0x726170616475635f,0x32315a5f5f34666d\n"
".quad 0x69466d6f52746163,0x544566497265746c,0x5f30535f3053665f,0x202c5f30535f3053\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x35666d7261706164,0x74616332315a5f5f\n"
".quad 0x65746c69466d6f52,0x53665f5445664972,0x5f30535f30535f30,0x0a7b090a295f3053\n"
".quad 0x662e206765722e09,0x30343c6625203233,0x636f6c2e090a3b3e,0x0933323209363109\n"
".quad 0x656257444c240a30,0x32315a5f5f6e6967,0x69466d6f52746163,0x544566497265746c\n"
".quad 0x5f30535f3053665f,0x0a3a5f30535f3053,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x635f5f5b202c3166,0x666d726170616475,0x616332315a5f5f31,0x746c69466d6f5274\n"
".quad 0x665f544566497265,0x30535f30535f3053,0x090a3b5d5f30535f,0x203233662e766f6d\n"
".quad 0x6625202c32662509,0x702e646c090a3b31,0x3233662e6d617261,0x5b202c3366250920\n"
".quad 0x6170616475635f5f,0x315a5f5f32666d72,0x466d6f5274616332,0x4566497265746c69\n"
".quad 0x30535f3053665f54,0x5d5f30535f30535f,0x662e766f6d090a3b,0x2c34662509203233\n"
".quad 0x6c090a3b33662520,0x2e6d617261702e64,0x3566250920323366,0x6475635f5f5b202c\n"
".quad 0x5f33666d72617061,0x5274616332315a5f,0x7265746c69466d6f,0x3053665f54456649\n"
".quad 0x535f30535f30535f,0x6f6d090a3b5d5f30,0x2509203233662e76,0x3b356625202c3666\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c376625,0x6d72617061647563\n"
".quad 0x6332315a5f5f3466,0x6c69466d6f527461,0x5f54456649726574,0x535f30535f305366\n"
".quad 0x0a3b5d5f30535f30,0x3233662e766f6d09,0x25202c3866250920,0x2e646c090a3b3766\n"
".quad 0x33662e6d61726170,0x202c396625092032,0x70616475635f5f5b,0x5a5f5f35666d7261\n"
".quad 0x6d6f527461633231,0x66497265746c6946,0x535f3053665f5445,0x5f30535f30535f30\n"
".quad 0x2e766f6d090a3b5d,0x3166250920323366,0x0a3b396625202c30,0x363109636f6c2e09\n"
".quad 0x090a300939323209,0x203233662e6c756d,0x25202c3131662509,0x3b326625202c3266\n"
".quad 0x33662e766f6d090a,0x2c32316625092032,0x3030306662663020,0x202020203b303030\n"
".quad 0x352e302d202f2f09,0x33662e766f6d090a,0x2c33316625092032,0x3030386633663020\n"
".quad 0x202020203b303030,0x6d090a31202f2f09,0x09203233662e766f,0x6630202c34316625\n"
".quad 0x3030303030306633,0x2f2f09202020203b,0x756d090a352e3020,0x2509203233662e6c\n"
".quad 0x316625202c353166,0x0a3b326625202c34,0x3233662e62757309,0x202c363166250920\n"
".quad 0x6625202c33316625,0x616d66090a3b3531,0x203233662e6e722e,0x25202c3731662509\n"
".quad 0x36316625202c3266,0x0a3b32316625202c,0x3233662e6c756d09,0x202c383166250920\n"
".quad 0x316625202c326625,0x2e6c756d090a3b37,0x3166250920323366,0x202c346625202c39\n"
".quad 0x6d090a3b38316625,0x09203233662e766f,0x6630202c30326625,0x3030303030386633\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3120,0x3266250920323366,0x3230636630202c31\n"
".quad 0x20203b3030303030,0x322d202f2f092020,0x2e766f6d090a352e,0x3266250920323366\n"
".quad 0x6366336630202c32,0x20203b3030303030,0x2e31202f2f092020,0x722e616d66090a35\n"
".quad 0x2509203233662e6e,0x326625202c333266,0x202c326625202c32,0x66090a3b31326625\n"
".quad 0x33662e6e722e616d,0x2c34326625092032,0x25202c3332662520,0x326625202c313166\n"
".quad 0x2e616d66090a3b30,0x09203233662e6e72,0x6625202c35326625,0x2c34326625202c36\n"
".quad 0x090a3b3931662520,0x203233662e766f6d,0x30202c3632662509,0x3030303030663366\n"
".quad 0x2f09202020203b30,0x6d090a352e30202f,0x09203233662e766f,0x6630202c37326625\n"
".quad 0x3030303030303034,0x2f2f09202020203b,0x2e766f6d090a3220,0x3266250920323366\n"
".quad 0x6366336630202c38,0x20203b3030303030,0x2e31202f2f092020,0x662e6c756d090a35\n"
".quad 0x3932662509203233,0x202c38326625202c,0x7573090a3b326625,0x2509203233662e62\n"
".quad 0x326625202c303366,0x3b39326625202c37,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x2c326625202c3133,0x25202c3033662520,0x756d090a3b363266,0x2509203233662e6c\n"
".quad 0x326625202c323366,0x0a3b31336625202c,0x2e6e722e616d6609,0x3366250920323366\n"
".quad 0x202c386625202c33,0x6625202c32336625,0x766f6d090a3b3532,0x662509203233662e\n"
".quad 0x66626630202c3433,0x203b303030303030,0x2d202f2f09202020,0x766f6d090a352e30\n"
".quad 0x662509203233662e,0x66336630202c3533,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x2e616d66090a352e,0x09203233662e6e72,0x6625202c36336625,0x2c326625202c3533\n"
".quad 0x090a3b3433662520,0x203233662e6c756d,0x25202c3733662509,0x336625202c313166\n"
".quad 0x2e616d66090a3b36,0x09203233662e6e72,0x6625202c38336625,0x37336625202c3031\n"
".quad 0x0a3b33336625202c,0x617261702e747309,0x5b09203233662e6d,0x6572616475635f5f\n"
".quad 0x6332315a5f5f6674,0x6c69466d6f527461,0x5f54456649726574,0x535f30535f305366\n"
".quad 0x202c5d5f30535f30,0x72090a3b38336625,0x57444c240a3b7465,0x32315a5f5f646e65\n"
".quad 0x69466d6f52746163,0x544566497265746c,0x5f30535f3053665f,0x0a3a5f30535f3053\n"
".quad 0x5a5f202f2f207d09,0x6d6f527461633231,0x66497265746c6946,0x535f3053665f5445\n"
".quad 0x5f30535f30535f30,0x61626f6c672e090a,0x65727865742e206c,0x0a0a3b7865742066\n"
".quad 0x207972746e652e09,0x6e65725f64385a5f,0x6863753650726564,0x6666666a6a347261\n"
".quad 0x2e09090a28206666,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x65646e65725f6438,0x7261686375365072,0x66666666666a6a34,0x757074756f5f645f\n"
".quad 0x61702e09090a2c74,0x3233752e206d6172,0x70616475635f5f20,0x64385a5f5f6d7261\n"
".quad 0x507265646e65725f,0x6a34726168637536,0x775f66666666666a,0x09090a2c68746469\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x5f5f6d7261706164,0x646e65725f64385a\n"
".quad 0x6168637536507265,0x666666666a6a3472,0x7468676965685f66,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x5f64385a5f5f6d72,0x36507265646e6572\n"
".quad 0x6a6a347261686375,0x78745f6666666666,0x7261702e09090a2c,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x5f64385a5f5f6d72,0x36507265646e6572,0x6a6a347261686375\n"
".quad 0x79745f6666666666,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x5f64385a5f5f6d72,0x36507265646e6572,0x6a6a347261686375,0x63735f6666666666\n"
".quad 0x2e09090a2c656c61,0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x65646e65725f6438,0x7261686375365072,0x66666666666a6a34,0x2e09090a2c78635f\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x65646e65725f6438\n"
".quad 0x7261686375365072,0x66666666666a6a34,0x0a7b090a2979635f,0x752e206765722e09\n"
".quad 0x30333c7225203233,0x6765722e090a3b3e,0x7225203436752e20,0x2e090a3b3e363c64\n"
".quad 0x3233662e20676572,0x3b3e34323c662520,0x2e206765722e090a,0x3c70252064657270\n"
".quad 0x6f6c2e090a3b3e33,0x3735320936310963,0x6257444c240a3009,0x385a5f5f6e696765\n"
".quad 0x7265646e65725f64,0x3472616863753650,0x3a66666666666a6a,0x33752e766f6d090a\n"
".quad 0x202c317225092032,0x782e646961746325,0x752e766f6d090a3b,0x2c32722509203233\n"
".quad 0x782e6469746e2520,0x34326c756d090a3b,0x203233752e6f6c2e,0x7225202c33722509\n"
".quad 0x0a3b327225202c31,0x3233752e766f6d09,0x25202c3472250920,0x3b792e6469617463\n"
".quad 0x33752e766f6d090a,0x202c357225092032,0x3b792e6469746e25,0x2e34326c756d090a\n"
".quad 0x09203233752e6f6c,0x347225202c367225,0x090a3b357225202c,0x203233752e766f6d\n"
".quad 0x7425202c37722509,0x61090a3b782e6469,0x09203233752e6464,0x377225202c387225\n"
".quad 0x090a3b337225202c,0x203233752e766f6d,0x7425202c39722509,0x61090a3b792e6469\n"
".quad 0x09203233752e6464,0x7225202c30317225,0x0a3b367225202c39,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x5f5f5b202c313172,0x6d72617061647563,0x65725f64385a5f5f\n"
".quad 0x637536507265646e,0x66666a6a34726168,0x746469775f666666,0x2e646c090a3b5d68\n"
".quad 0x33752e6d61726170,0x2c32317225092032,0x616475635f5f5b20,0x385a5f5f6d726170\n"
".quad 0x7265646e65725f64,0x3472616863753650,0x5f66666666666a6a,0x3b5d746867696568\n"
".quad 0x74672e746573090a,0x3233752e3233752e,0x202c333172250920,0x7225202c32317225\n"
".quad 0x67656e090a3b3031,0x722509203233732e,0x33317225202c3431,0x6c2e746573090a3b\n"
".quad 0x33752e3233752e74,0x2c35317225092032,0x7225202c38722520,0x67656e090a3b3131\n"
".quad 0x722509203233732e,0x35317225202c3631,0x622e646e61090a3b,0x3731722509203233\n"
".quad 0x202c34317225202c,0x6d090a3b36317225,0x09203233752e766f,0x3b30202c38317225\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x37317225202c3170,0x0a3b38317225202c\n"
".quad 0x7262203170254009,0x315f744c24092061,0x0a3b323832315f34,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x635f5f5b202c3166,0x5f6d726170616475,0x6e65725f64385a5f\n"
".quad 0x6863753650726564,0x6666666a6a347261,0x0a3b5d79635f6666,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x635f5f5b202c3266,0x5f6d726170616475,0x6e65725f64385a5f\n"
".quad 0x6863753650726564,0x6666666a6a347261,0x656c6163735f6666,0x702e646c090a3b5d\n"
".quad 0x3233662e6d617261,0x5b202c3366250920,0x6170616475635f5f,0x5f64385a5f5f6d72\n"
".quad 0x36507265646e6572,0x6a6a347261686375,0x78635f6666666666,0x702e646c090a3b5d\n"
".quad 0x3233662e6d617261,0x5b202c3466250920,0x6170616475635f5f,0x5f64385a5f5f6d72\n"
".quad 0x36507265646e6572,0x6a6a347261686375,0x78745f6666666666,0x2e747663090a3b5d\n"
".quad 0x752e3233662e6e72,0x2c35662509203233,0x73090a3b38722520,0x09203233662e6275\n"
".quad 0x356625202c366625,0x090a3b336625202c,0x662e6e722e616d66,0x2c37662509203233\n"
".quad 0x6625202c32662520,0x0a3b336625202c36,0x3233662e64646109,0x25202c3866250920\n"
".quad 0x3b376625202c3466,0x33662e766f6d090a,0x202c396625092032,0x646c090a3b386625\n"
".quad 0x662e6d617261702e,0x3031662509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x65646e65725f6438,0x7261686375365072,0x66666666666a6a34,0x63090a3b5d79745f\n"
".quad 0x33662e6e722e7476,0x2509203233752e32,0x317225202c313166,0x2e627573090a3b30\n"
".quad 0x3166250920323366,0x2c31316625202c32,0x66090a3b31662520,0x33662e6e722e616d\n"
".quad 0x2c33316625092032,0x6625202c32662520,0x3b316625202c3231,0x33662e646461090a\n"
".quad 0x2c34316625092032,0x25202c3031662520,0x6f6d090a3b333166,0x2509203233662e76\n"
".quad 0x316625202c353166,0x2e766f6d090a3b34,0x3166250920323366,0x3030306630202c36\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c373166250920\n"
".quad 0x6d090a3b36316625,0x09203233662e766f,0x6630202c38316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366,0x3b38316625202c39\n"
".quad 0x64322e786574090a,0x2e3233752e34762e,0x3172257b20323366,0x252c303272252c39\n"
".quad 0x323272252c313272,0x7b2c7865745b2c7d,0x353166252c396625,0x66252c373166252c\n"
".quad 0x2e090a3b5d7d3931,0x3209363109636f6c,0x6f6d090a30093836,0x2509203233732e76\n"
".quad 0x317225202c333272,0x636f6c2e090a3b39,0x0931373209363109,0x622e766f6d090a30\n"
".quad 0x3032662509203233,0x0a3b33327225202c,0x3233662e766f6d09,0x202c313266250920\n"
".quad 0x3030663733346630,0x09202020203b3030,0x090a353532202f2f,0x203233662e6c756d\n"
".quad 0x25202c3232662509,0x326625202c303266,0x326c756d090a3b31,0x3233752e6f6c2e34\n"
".quad 0x202c343272250920,0x7225202c30317225,0x747663090a3b3131,0x3233752e697a722e\n"
".quad 0x722509203233662e,0x32326625202c3532,0x732e766f6d090a3b,0x3632722509203233\n"
".quad 0x0a3b35327225202c,0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c316472\n"
".quad 0x6d72617061647563,0x65725f64385a5f5f,0x637536507265646e,0x66666a6a34726168\n"
".quad 0x756f5f645f666666,0x090a3b5d74757074,0x203233752e646461,0x25202c3732722509\n"
".quad 0x34327225202c3872,0x752e747663090a3b,0x09203233752e3436,0x7225202c32647225\n"
".quad 0x6c756d090a3b3732,0x33752e656469772e,0x2c33647225092032,0x34202c3732722520\n"
".quad 0x752e646461090a3b,0x3464722509203436,0x202c31647225202c,0x6d090a3b33647225\n"
".quad 0x09203233752e766f,0x3b30202c38327225,0x6f6c672e7473090a,0x752e34762e6c6162\n"
".quad 0x346472255b092038,0x72257b202c5d302b,0x2c363272252c3632,0x3272252c36327225\n"
".quad 0x5f744c240a3b7d38,0x3a323832315f3431,0x3109636f6c2e090a,0x0a30093337320936\n"
".quad 0x240a3b7469786509,0x5f5f646e6557444c,0x646e65725f64385a,0x6168637536507265\n"
".quad 0x666666666a6a3472,0x2f2f207d090a3a66,0x65725f64385a5f20,0x637536507265646e\n"
".quad 0x66666a6a34726168,0x652e090a0a666666,0x315a5f207972746e,0x65646e65725f6435\n"
".quad 0x6369627563694272,0x3472616863753650,0x2066666666666a6a,0x7261702e09090a28\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x6435315a5f5f6d72,0x427265646e65725f\n"
".quad 0x3650636962756369,0x6a6a347261686375,0x5f645f6666666666,0x0a2c74757074756f\n"
".quad 0x6d617261702e0909,0x5f5f203233752e20,0x6d72617061647563,0x725f6435315a5f5f\n"
".quad 0x6369427265646e65,0x6375365063696275,0x66666a6a34726168,0x746469775f666666\n"
".quad 0x61702e09090a2c68,0x3233752e206d6172,0x70616475635f5f20,0x35315a5f5f6d7261\n"
".quad 0x7265646e65725f64,0x5063696275636942,0x6a34726168637536,0x685f66666666666a\n"
".quad 0x090a2c7468676965,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x65725f6435315a5f,0x756369427265646e,0x6863753650636962,0x6666666a6a347261\n"
".quad 0x090a2c78745f6666,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x65725f6435315a5f,0x756369427265646e,0x6863753650636962,0x6666666a6a347261\n"
".quad 0x090a2c79745f6666,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x65725f6435315a5f,0x756369427265646e,0x6863753650636962,0x6666666a6a347261\n"
".quad 0x656c6163735f6666,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x6435315a5f5f6d72,0x427265646e65725f,0x3650636962756369,0x6a6a347261686375\n"
".quad 0x78635f6666666666,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x6435315a5f5f6d72,0x427265646e65725f,0x3650636962756369,0x6a6a347261686375\n"
".quad 0x79635f6666666666,0x722e090a7b090a29,0x203233752e206765,0x3b3e3530313c7225\n"
".quad 0x2e206765722e090a,0x3c64722520343675,0x65722e090a3b3e36,0x25203233662e2067\n"
".quad 0x0a3b3e3532323c66,0x702e206765722e09,0x333c702520646572,0x636f6c2e090a3b3e\n"
".quad 0x0937373209363109,0x656257444c240a30,0x35315a5f5f6e6967,0x7265646e65725f64\n"
".quad 0x5063696275636942,0x6a34726168637536,0x0a3a66666666666a,0x3233752e766f6d09\n"
".quad 0x25202c3172250920,0x3b782e6469617463,0x33752e766f6d090a,0x202c327225092032\n"
".quad 0x3b782e6469746e25,0x2e34326c756d090a,0x09203233752e6f6c,0x317225202c337225\n"
".quad 0x090a3b327225202c,0x203233752e766f6d,0x6325202c34722509,0x0a3b792e64696174\n"
".quad 0x3233752e766f6d09,0x25202c3572250920,0x0a3b792e6469746e,0x6c2e34326c756d09\n"
".quad 0x2509203233752e6f,0x2c347225202c3672,0x6d090a3b35722520,0x09203233752e766f\n"
".quad 0x697425202c377225,0x6461090a3b782e64,0x2509203233752e64,0x2c377225202c3872\n"
".quad 0x6d090a3b33722520,0x09203233752e766f,0x697425202c397225,0x6461090a3b792e64\n"
".quad 0x2509203233752e64,0x397225202c303172,0x090a3b367225202c,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x635f5f5b202c3131,0x5f6d726170616475,0x65725f6435315a5f\n"
".quad 0x756369427265646e,0x6863753650636962,0x6666666a6a347261,0x68746469775f6666\n"
".quad 0x702e646c090a3b5d,0x3233752e6d617261,0x202c323172250920,0x70616475635f5f5b\n"
".quad 0x35315a5f5f6d7261,0x7265646e65725f64,0x5063696275636942,0x6a34726168637536\n"
".quad 0x685f66666666666a,0x0a3b5d7468676965,0x2e74672e74657309,0x203233752e323375\n"
".quad 0x25202c3331722509,0x317225202c323172,0x2e67656e090a3b30,0x3172250920323373\n"
".quad 0x3b33317225202c34,0x746c2e746573090a,0x3233752e3233752e,0x202c353172250920\n"
".quad 0x317225202c387225,0x2e67656e090a3b31,0x3172250920323373,0x3b35317225202c36\n"
".quad 0x33622e646e61090a,0x2c37317225092032,0x25202c3431722520,0x6f6d090a3b363172\n"
".quad 0x2509203233752e76,0x0a3b30202c383172,0x71652e7074657309,0x702509203233732e\n"
".quad 0x2c37317225202c31,0x090a3b3831722520,0x6172622031702540,0x35315f744c240920\n"
".quad 0x090a3b323832315f,0x09363109636f6c2e,0x63090a3009383832,0x33662e6e722e7476\n"
".quad 0x2509203233752e32,0x3b387225202c3166,0x6e722e747663090a,0x3233752e3233662e\n"
".quad 0x25202c3266250920,0x646c090a3b303172,0x662e6d617261702e,0x2c33662509203233\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x65646e65725f6435,0x6369627563694272\n"
".quad 0x3472616863753650,0x5f66666666666a6a,0x7573090a3b5d7863,0x2509203233662e62\n"
".quad 0x2c316625202c3466,0x6c090a3b33662520,0x2e6d617261702e64,0x3566250920323366\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x646e65725f643531,0x6962756369427265\n"
".quad 0x7261686375365063,0x66666666666a6a34,0x73090a3b5d79635f,0x09203233662e6275\n"
".quad 0x326625202c366625,0x090a3b356625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c37,0x5f5f6d7261706164,0x6e65725f6435315a,0x6275636942726564\n"
".quad 0x6168637536506369,0x666666666a6a3472,0x5d656c6163735f66,0x722e616d66090a3b\n"
".quad 0x2509203233662e6e,0x2c376625202c3866,0x6625202c34662520,0x2e616d66090a3b33\n"
".quad 0x09203233662e6e72,0x376625202c396625,0x25202c366625202c,0x2e646c090a3b3566\n"
".quad 0x33662e6d61726170,0x2c30316625092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x65646e65725f6435,0x6369627563694272,0x3472616863753650,0x5f66666666666a6a\n"
".quad 0x6461090a3b5d7874,0x2509203233662e64,0x316625202c313166,0x0a3b386625202c30\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x5f5f5b202c323166,0x6d72617061647563\n"
".quad 0x725f6435315a5f5f,0x6369427265646e65,0x6375365063696275,0x66666a6a34726168\n"
".quad 0x3b5d79745f666666,0x33662e646461090a,0x2c33316625092032,0x25202c3231662520\n"
".quad 0x766f6d090a3b3966,0x662509203233662e,0x66626630202c3431,0x203b303030303030\n"
".quad 0x2d202f2f09202020,0x646461090a352e30,0x662509203233662e,0x31316625202c3531\n"
".quad 0x0a3b34316625202c,0x3233662e766f6d09,0x202c363166250920,0x3030303066626630\n"
".quad 0x09202020203b3030,0x0a352e302d202f2f,0x3233662e64646109,0x202c373166250920\n"
".quad 0x6625202c33316625,0x747663090a3b3631,0x3233662e696d722e,0x662509203233662e\n"
".quad 0x35316625202c3831,0x722e747663090a3b,0x662e3233662e696d,0x3931662509203233\n"
".quad 0x0a3b37316625202c,0x3233662e766f6d09,0x202c303266250920,0x3030303866626630\n"
".quad 0x09202020203b3030,0x61090a312d202f2f,0x09203233662e6464,0x6625202c31326625\n"
".quad 0x30326625202c3831,0x662e766f6d090a3b,0x3232662509203233,0x303866626630202c\n"
".quad 0x2020203b30303030,0x0a312d202f2f0920,0x3233662e64646109,0x202c333266250920\n"
".quad 0x6625202c39316625,0x766f6d090a3b3232,0x662509203233662e,0x31326625202c3432\n"
".quad 0x662e766f6d090a3b,0x3532662509203233,0x0a3b33326625202c,0x3233662e766f6d09\n"
".quad 0x202c363266250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x326625202c373266,0x2e766f6d090a3b36,0x3266250920323366\n"
".quad 0x3030306630202c38,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c393266250920,0x74090a3b38326625,0x34762e64322e7865,0x3233662e3233752e\n"
".quad 0x252c393172257b20,0x313272252c303272,0x5b2c7d323272252c,0x3266257b2c786574\n"
".quad 0x252c353266252c34,0x393266252c373266,0x6f6c2e090a3b5d7d,0x3530310936310963\n"
".quad 0x2e766f6d090a3009,0x3272250920323373,0x3b39317225202c33,0x33662e766f6d090a\n"
".quad 0x2c30336625092032,0x090a3b3831662520,0x203233662e766f6d,0x25202c3133662509\n"
".quad 0x6f6d090a3b333266,0x2509203233662e76,0x306630202c323366,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3333662509203233,0x0a3b32336625202c\n"
".quad 0x3233662e766f6d09,0x202c343366250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x336625202c353366,0x2e786574090a3b34\n"
".quad 0x33752e34762e6432,0x257b203233662e32,0x353272252c343272,0x72252c363272252c\n"
".quad 0x7865745b2c7d3732,0x252c303366257b2c,0x333366252c313366,0x3b5d7d353366252c\n"
".quad 0x33732e766f6d090a,0x2c38327225092032,0x090a3b3432722520,0x203233662e766f6d\n"
".quad 0x30202c3633662509,0x3030303038663366,0x2f09202020203b30,0x646461090a31202f\n"
".quad 0x662509203233662e,0x38316625202c3733,0x0a3b36336625202c,0x3233662e766f6d09\n"
".quad 0x202c383366250920,0x6d090a3b37336625,0x09203233662e766f,0x6625202c39336625\n"
".quad 0x766f6d090a3b3332,0x662509203233662e,0x30306630202c3034,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c31346625092032,0x090a3b3034662520\n"
".quad 0x203233662e766f6d,0x30202c3234662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x32346625202c3334,0x322e786574090a3b\n"
".quad 0x3233752e34762e64,0x72257b203233662e,0x2c303372252c3932,0x3372252c31337225\n"
".quad 0x2c7865745b2c7d32,0x66252c383366257b,0x2c313466252c3933,0x0a3b5d7d33346625\n"
".quad 0x3233732e766f6d09,0x202c333372250920,0x6d090a3b39327225,0x09203233662e766f\n"
".quad 0x6630202c34346625,0x3030303030303034,0x2f2f09202020203b,0x2e646461090a3220\n"
".quad 0x3466250920323366,0x2c38316625202c35,0x090a3b3434662520,0x203233662e766f6d\n"
".quad 0x25202c3634662509,0x6f6d090a3b353466,0x2509203233662e76,0x326625202c373466\n"
".quad 0x2e766f6d090a3b33,0x3466250920323366,0x3030306630202c38,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c393466250920,0x6d090a3b38346625\n"
".quad 0x09203233662e766f,0x6630202c30356625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3566250920323366,0x3b30356625202c31,0x64322e786574090a\n"
".quad 0x2e3233752e34762e,0x3372257b20323366,0x252c353372252c34,0x373372252c363372\n"
".quad 0x7b2c7865745b2c7d,0x3466252c36346625,0x252c393466252c37,0x090a3b5d7d313566\n"
".quad 0x203233732e766f6d,0x25202c3833722509,0x6f6d090a3b343372,0x2509203233662e76\n"
".quad 0x326625202c323566,0x2e766f6d090a3b31,0x3566250920323366,0x3b39316625202c33\n"
".quad 0x33662e766f6d090a,0x2c34356625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6625202c35356625,0x766f6d090a3b3435\n"
".quad 0x662509203233662e,0x30306630202c3635,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x2c37356625092032,0x090a3b3635662520,0x762e64322e786574\n"
".quad 0x33662e3233752e34,0x2c393372257b2032,0x3472252c30347225,0x2c7d323472252c31\n"
".quad 0x66257b2c7865745b,0x2c333566252c3235,0x3566252c35356625,0x6f6d090a3b5d7d37\n"
".quad 0x2509203233732e76,0x337225202c333472,0x2e766f6d090a3b39,0x3566250920323366\n"
".quad 0x3b38316625202c38,0x33662e766f6d090a,0x2c39356625092032,0x090a3b3931662520\n"
".quad 0x203233662e766f6d,0x30202c3036662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x30366625202c3136,0x662e766f6d090a3b\n"
".quad 0x3236662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x25202c3336662509,0x6574090a3b323666,0x2e34762e64322e78\n"
".quad 0x203233662e323375,0x72252c343472257b,0x2c363472252c3534,0x745b2c7d37347225\n"
".quad 0x383566257b2c7865,0x66252c393566252c,0x7d333666252c3136,0x2e766f6d090a3b5d\n"
".quad 0x3472250920323373,0x3b34347225202c38,0x33662e766f6d090a,0x2c34366625092032\n"
".quad 0x090a3b3733662520,0x203233662e766f6d,0x25202c3536662509,0x6f6d090a3b393166\n"
".quad 0x2509203233662e76,0x306630202c363666,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3736662509203233,0x0a3b36366625202c,0x3233662e766f6d09\n"
".quad 0x202c383666250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x366625202c393666,0x2e786574090a3b38,0x33752e34762e6432\n"
".quad 0x257b203233662e32,0x303572252c393472,0x72252c313572252c,0x7865745b2c7d3235\n"
".quad 0x252c343666257b2c,0x373666252c353666,0x3b5d7d393666252c,0x33732e766f6d090a\n"
".quad 0x2c33357225092032,0x090a3b3934722520,0x203233662e766f6d,0x25202c3037662509\n"
".quad 0x6f6d090a3b353466,0x2509203233662e76,0x316625202c313766,0x2e766f6d090a3b39\n"
".quad 0x3766250920323366,0x3030306630202c32,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c333766250920,0x6d090a3b32376625,0x09203233662e766f\n"
".quad 0x6630202c34376625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3766250920323366,0x3b34376625202c35,0x64322e786574090a,0x2e3233752e34762e\n"
".quad 0x3572257b20323366,0x252c353572252c34,0x373572252c363572,0x7b2c7865745b2c7d\n"
".quad 0x3766252c30376625,0x252c333766252c31,0x090a3b5d7d353766,0x203233732e766f6d\n"
".quad 0x25202c3835722509,0x6f6d090a3b343572,0x2509203233662e76,0x336630202c363766\n"
".quad 0x3b30303030303866,0x202f2f0920202020,0x662e646461090a31,0x3737662509203233\n"
".quad 0x202c39316625202c,0x6d090a3b36376625,0x09203233662e766f,0x6625202c38376625\n"
".quad 0x766f6d090a3b3132,0x662509203233662e,0x37376625202c3937,0x662e766f6d090a3b\n"
".quad 0x3038662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x25202c3138662509,0x6f6d090a3b303866,0x2509203233662e76\n"
".quad 0x306630202c323866,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3338662509203233,0x0a3b32386625202c,0x2e64322e78657409,0x662e3233752e3476\n"
".quad 0x393572257b203233,0x72252c303672252c,0x7d323672252c3136,0x257b2c7865745b2c\n"
".quad 0x393766252c383766,0x66252c313866252c,0x6d090a3b5d7d3338,0x09203233732e766f\n"
".quad 0x7225202c33367225,0x766f6d090a3b3935,0x662509203233662e,0x38316625202c3438\n"
".quad 0x662e766f6d090a3b,0x3538662509203233,0x0a3b37376625202c,0x3233662e766f6d09\n"
".quad 0x202c363866250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x386625202c373866,0x2e766f6d090a3b36,0x3866250920323366\n"
".quad 0x3030306630202c38,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c393866250920,0x74090a3b38386625,0x34762e64322e7865,0x3233662e3233752e\n"
".quad 0x252c343672257b20,0x363672252c353672,0x5b2c7d373672252c,0x3866257b2c786574\n"
".quad 0x252c353866252c34,0x393866252c373866,0x766f6d090a3b5d7d,0x722509203233732e\n"
".quad 0x34367225202c3836,0x662e766f6d090a3b,0x3039662509203233,0x0a3b37336625202c\n"
".quad 0x3233662e766f6d09,0x202c313966250920,0x6d090a3b37376625,0x09203233662e766f\n"
".quad 0x6630202c32396625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3966250920323366,0x3b32396625202c33,0x33662e766f6d090a,0x2c34396625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6625202c35396625,0x786574090a3b3439,0x752e34762e64322e,0x7b203233662e3233\n"
".quad 0x3772252c39367225,0x252c313772252c30,0x65745b2c7d323772,0x2c303966257b2c78\n"
".quad 0x3966252c31396625,0x5d7d353966252c33,0x732e766f6d090a3b,0x3337722509203233\n"
".quad 0x0a3b39367225202c,0x3233662e766f6d09,0x202c363966250920,0x6d090a3b35346625\n"
".quad 0x09203233662e766f,0x6625202c37396625,0x766f6d090a3b3737,0x662509203233662e\n"
".quad 0x30306630202c3839,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c39396625092032,0x090a3b3839662520,0x203233662e766f6d,0x202c303031662509\n"
".quad 0x3030303030306630,0x2f092020203b3030,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x316625202c313031,0x786574090a3b3030,0x752e34762e64322e,0x7b203233662e3233\n"
".quad 0x3772252c34377225,0x252c363772252c35,0x65745b2c7d373772,0x2c363966257b2c78\n"
".quad 0x3966252c37396625,0x7d31303166252c39,0x2e766f6d090a3b5d,0x3772250920323373\n"
".quad 0x3b34377225202c38,0x33662e766f6d090a,0x3230316625092032,0x303030346630202c\n"
".quad 0x2020203b30303030,0x61090a32202f2f09,0x09203233662e6464,0x25202c3330316625\n"
".quad 0x316625202c393166,0x766f6d090a3b3230,0x662509203233662e,0x326625202c343031\n"
".quad 0x2e766f6d090a3b31,0x3166250920323366,0x30316625202c3530,0x2e766f6d090a3b33\n"
".quad 0x3166250920323366,0x30306630202c3630,0x203b303030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x2c37303166250920,0x0a3b363031662520,0x3233662e766f6d09\n"
".quad 0x2c38303166250920,0x3030303030663020,0x092020203b303030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x6625202c39303166,0x6574090a3b383031,0x2e34762e64322e78\n"
".quad 0x203233662e323375,0x72252c393772257b,0x2c313872252c3038,0x745b2c7d32387225\n"
".quad 0x303166257b2c7865,0x2c35303166252c34,0x66252c3730316625,0x090a3b5d7d393031\n"
".quad 0x203233732e766f6d,0x25202c3338722509,0x6f6d090a3b393772,0x2509203233662e76\n"
".quad 0x6625202c30313166,0x766f6d090a3b3831,0x662509203233662e,0x316625202c313131\n"
".quad 0x766f6d090a3b3330,0x662509203233662e,0x306630202c323131,0x3b30303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x3331316625092032,0x3b3231316625202c\n"
".quad 0x33662e766f6d090a,0x3431316625092032,0x303030306630202c,0x2020203b30303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x25202c3531316625,0x74090a3b34313166\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c343872257b20,0x363872252c353872\n"
".quad 0x5b2c7d373872252c,0x3166257b2c786574,0x31313166252c3031,0x252c33313166252c\n"
".quad 0x0a3b5d7d35313166,0x3233732e766f6d09,0x202c383872250920,0x6d090a3b34387225\n"
".quad 0x09203233662e766f,0x25202c3631316625,0x6f6d090a3b373366,0x2509203233662e76\n"
".quad 0x6625202c37313166,0x6f6d090a3b333031,0x2509203233662e76,0x6630202c38313166\n"
".quad 0x3030303030303030,0x202f2f092020203b,0x662e766f6d090a30,0x3131662509203233\n"
".quad 0x3831316625202c39,0x662e766f6d090a3b,0x3231662509203233,0x3030306630202c30\n"
".quad 0x20203b3030303030,0x090a30202f2f0920,0x203233662e766f6d,0x202c313231662509\n"
".quad 0x090a3b3032316625,0x762e64322e786574,0x33662e3233752e34,0x2c393872257b2032\n"
".quad 0x3972252c30397225,0x2c7d323972252c31,0x66257b2c7865745b,0x313166252c363131\n"
".quad 0x2c39313166252c37,0x3b5d7d3132316625,0x33732e766f6d090a,0x2c33397225092032\n"
".quad 0x090a3b3938722520,0x203233662e766f6d,0x202c323231662509,0x6d090a3b35346625\n"
".quad 0x09203233662e766f,0x25202c3332316625,0x6d090a3b33303166,0x09203233662e766f\n"
".quad 0x30202c3432316625,0x3030303030303066,0x2f2f092020203b30,0x2e766f6d090a3020\n"
".quad 0x3166250920323366,0x32316625202c3532,0x2e766f6d090a3b34,0x3166250920323366\n"
".quad 0x30306630202c3632,0x203b303030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x2c37323166250920,0x0a3b363231662520,0x2e64322e78657409,0x662e3233752e3476\n"
".quad 0x343972257b203233,0x72252c353972252c,0x7d373972252c3639,0x257b2c7865745b2c\n"
".quad 0x3166252c32323166,0x35323166252c3332,0x5d7d37323166252c,0x732e766f6d090a3b\n"
".quad 0x3839722509203233,0x0a3b34397225202c,0x363109636f6c2e09,0x73090a3009343309\n"
".quad 0x09203233662e6275,0x25202c3832316625,0x316625202c353166,0x2e766f6d090a3b38\n"
".quad 0x3166250920323366,0x30346630202c3932,0x203b303030303034,0x0a33202f2f092020\n"
".quad 0x3233662e62757309,0x2c30333166250920,0x202c393231662520,0x090a3b3832316625\n"
".quad 0x203233662e766f6d,0x202c313331662509,0x3030303430636630,0x2f092020203b3030\n"
".quad 0x6d66090a332d202f,0x3233662e6e722e61,0x2c32333166250920,0x202c383231662520\n"
".quad 0x25202c3033316625,0x6d090a3b31333166,0x09203233662e766f,0x30202c3333316625\n"
".quad 0x3030303038663366,0x2f2f092020203b30,0x2e616d66090a3120,0x09203233662e6e72\n"
".quad 0x25202c3433316625,0x6625202c38323166,0x316625202c323331,0x766f6d090a3b3333\n"
".quad 0x662509203233662e,0x336630202c353331,0x3b62616161613265,0x30202f2f09202020\n"
".quad 0x0a3736363636312e,0x3233662e6c756d09,0x2c36333166250920,0x202c343331662520\n"
".quad 0x090a3b3533316625,0x09363109636f6c2e,0x6f6d090a30093134,0x2509203233662e76\n"
".quad 0x6630202c37333166,0x3030303030633063,0x202f2f092020203b,0x2e766f6d090a362d\n"
".quad 0x3166250920323366,0x30346630202c3833,0x203b303030303034,0x0a33202f2f092020\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x33316625202c3933,0x3832316625202c38\n"
".quad 0x3b3733316625202c,0x33662e6c756d090a,0x3034316625092032,0x2c3832316625202c\n"
".quad 0x0a3b383231662520,0x3233662e766f6d09,0x2c31343166250920,0x3030383034663020\n"
".quad 0x092020203b303030,0x6d66090a34202f2f,0x3233662e6e722e61,0x2c32343166250920\n"
".quad 0x202c393331662520,0x25202c3034316625,0x6d090a3b31343166,0x09203233662e766f\n"
".quad 0x30202c3334316625,0x6161616132653366,0x2f2f092020203b62,0x36363636312e3020\n"
".quad 0x662e6c756d090a37,0x3431662509203233,0x3234316625202c34,0x3b3334316625202c\n"
".quad 0x3109636f6c2e090a,0x090a300938340936,0x203233662e766f6d,0x202c353431662509\n"
".quad 0x3030303430346630,0x2f092020203b3030,0x766f6d090a33202f,0x662509203233662e\n"
".quad 0x636630202c363431,0x3b30303030303430,0x2d202f2f09202020,0x722e616d66090a33\n"
".quad 0x2509203233662e6e,0x6625202c37343166,0x316625202c363431,0x34316625202c3832\n"
".quad 0x2e766f6d090a3b35,0x3166250920323366,0x30346630202c3834,0x203b303030303034\n"
".quad 0x0a33202f2f092020,0x2e6e722e616d6609,0x3166250920323366,0x32316625202c3934\n"
".quad 0x3734316625202c38,0x3b3834316625202c,0x33662e766f6d090a,0x3035316625092032\n"
".quad 0x303866336630202c,0x2020203b30303030,0x66090a31202f2f09,0x33662e6e722e616d\n"
".quad 0x3135316625092032,0x2c3832316625202c,0x202c393431662520,0x090a3b3035316625\n"
".quad 0x203233662e766f6d,0x202c323531662509,0x6161613265336630,0x2f092020203b6261\n"
".quad 0x363636312e30202f,0x2e6c756d090a3736,0x3166250920323366,0x35316625202c3335\n"
".quad 0x3235316625202c31,0x09636f6c2e090a3b,0x0a30093435093631,0x3233662e6c756d09\n"
".quad 0x2c34353166250920,0x202c383231662520,0x090a3b3034316625,0x203233662e766f6d\n"
".quad 0x202c353531662509,0x6161613265336630,0x2f092020203b6261,0x363636312e30202f\n"
".quad 0x2e6c756d090a3736,0x3166250920323366,0x35316625202c3635,0x3535316625202c34\n"
".quad 0x09636f6c2e090a3b,0x3009353031093631,0x33622e766f6d090a,0x3735316625092032\n"
".quad 0x0a3b33327225202c,0x3233662e6c756d09,0x2c38353166250920,0x202c363331662520\n"
".quad 0x090a3b3735316625,0x203233622e766f6d,0x202c393531662509,0x66090a3b38327225\n"
".quad 0x33662e6e722e616d,0x3036316625092032,0x2c3935316625202c,0x202c343431662520\n"
".quad 0x090a3b3835316625,0x203233622e766f6d,0x202c313631662509,0x66090a3b33337225\n"
".quad 0x33662e6e722e616d,0x3236316625092032,0x2c3136316625202c,0x202c333531662520\n"
".quad 0x090a3b3036316625,0x203233622e766f6d,0x202c333631662509,0x66090a3b38337225\n"
".quad 0x33662e6e722e616d,0x3436316625092032,0x2c3336316625202c,0x202c363531662520\n"
".quad 0x090a3b3236316625,0x203233622e766f6d,0x202c353631662509,0x6d090a3b33347225\n"
".quad 0x09203233662e6c75,0x25202c3636316625,0x6625202c36333166,0x6f6d090a3b353631\n"
".quad 0x2509203233622e76,0x7225202c37363166,0x616d66090a3b3834,0x203233662e6e722e\n"
".quad 0x202c383631662509,0x25202c3736316625,0x6625202c34343166,0x6f6d090a3b363631\n"
".quad 0x2509203233622e76,0x7225202c39363166,0x616d66090a3b3335,0x203233662e6e722e\n"
".quad 0x202c303731662509,0x25202c3936316625,0x6625202c33353166,0x6f6d090a3b383631\n"
".quad 0x2509203233622e76,0x7225202c31373166,0x616d66090a3b3835,0x203233662e6e722e\n"
".quad 0x202c323731662509,0x25202c3137316625,0x6625202c36353166,0x6f6d090a3b303731\n"
".quad 0x2509203233622e76,0x7225202c33373166,0x6c756d090a3b3336,0x662509203233662e\n"
".quad 0x316625202c343731,0x37316625202c3633,0x2e766f6d090a3b33,0x3166250920323362\n"
".quad 0x38367225202c3537,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c36373166\n"
".quad 0x316625202c353731,0x37316625202c3434,0x2e766f6d090a3b34,0x3166250920323362\n"
".quad 0x33377225202c3737,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c38373166\n"
".quad 0x316625202c373731,0x37316625202c3335,0x2e766f6d090a3b36,0x3166250920323362\n"
".quad 0x38377225202c3937,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c30383166\n"
".quad 0x316625202c393731,0x37316625202c3635,0x2e766f6d090a3b38,0x3166250920323362\n"
".quad 0x33387225202c3138,0x662e6c756d090a3b,0x3831662509203233,0x3633316625202c32\n"
".quad 0x3b3138316625202c,0x33622e766f6d090a,0x3338316625092032,0x0a3b38387225202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x38316625202c3438,0x3434316625202c33\n"
".quad 0x3b3238316625202c,0x33622e766f6d090a,0x3538316625092032,0x0a3b33397225202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x38316625202c3638,0x3335316625202c35\n"
".quad 0x3b3438316625202c,0x33622e766f6d090a,0x3738316625092032,0x0a3b38397225202c\n"
".quad 0x2e6e722e616d6609,0x3166250920323366,0x38316625202c3838,0x3635316625202c37\n"
".quad 0x3b3638316625202c,0x3109636f6c2e090a,0x090a300934330936,0x203233662e627573\n"
".quad 0x202c393831662509,0x6625202c37316625,0x766f6d090a3b3931,0x662509203233662e\n"
".quad 0x336630202c303931,0x3b30303030303866,0x31202f2f09202020,0x33662e766f6d090a\n"
".quad 0x3139316625092032,0x303430636630202c,0x2020203b30303030,0x090a332d202f2f09\n"
".quad 0x203233662e766f6d,0x202c323931662509,0x3030303430346630,0x2f092020203b3030\n"
".quad 0x627573090a33202f,0x662509203233662e,0x316625202c333931,0x38316625202c3239\n"
".quad 0x2e616d66090a3b39,0x09203233662e6e72,0x25202c3439316625,0x6625202c39383166\n"
".quad 0x316625202c333931,0x616d66090a3b3139,0x203233662e6e722e,0x202c353931662509\n"
".quad 0x25202c3938316625,0x6625202c34393166,0x6f6d090a3b303931,0x2509203233662e76\n"
".quad 0x6630202c36393166,0x6261616161326533,0x202f2f092020203b,0x3736363636312e30\n"
".quad 0x33662e6c756d090a,0x3739316625092032,0x2c3539316625202c,0x0a3b363931662520\n"
".quad 0x363109636f6c2e09,0x6d090a3009313409,0x09203233662e6c75,0x25202c3839316625\n"
".quad 0x6625202c39383166,0x6f6d090a3b393831,0x2509203233662e76,0x6630202c39393166\n"
".quad 0x3030303030383034,0x202f2f092020203b,0x662e766f6d090a34,0x3032662509203233\n"
".quad 0x6330636630202c30,0x20203b3030303030,0x0a362d202f2f0920,0x3233662e766f6d09\n"
".quad 0x2c31303266250920,0x3030343034663020,0x092020203b303030,0x6d66090a33202f2f\n"
".quad 0x3233662e6e722e61,0x2c32303266250920,0x202c313032662520,0x25202c3938316625\n"
".quad 0x66090a3b30303266,0x33662e6e722e616d,0x3330326625092032,0x2c3230326625202c\n"
".quad 0x202c383931662520,0x090a3b3939316625,0x203233662e766f6d,0x202c343032662509\n"
".quad 0x6161613265336630,0x2f092020203b6261,0x363636312e30202f,0x2e6c756d090a3736\n"
".quad 0x3266250920323366,0x30326625202c3530,0x3430326625202c33,0x09636f6c2e090a3b\n"
".quad 0x0a30093834093631,0x3233662e766f6d09,0x2c36303266250920,0x3030386633663020\n"
".quad 0x092020203b303030,0x6f6d090a31202f2f,0x2509203233662e76,0x6630202c37303266\n"
".quad 0x3030303030343034,0x202f2f092020203b,0x662e766f6d090a33,0x3032662509203233\n"
".quad 0x3430346630202c38,0x20203b3030303030,0x090a33202f2f0920,0x203233662e766f6d\n"
".quad 0x202c393032662509,0x3030303430636630,0x2f092020203b3030,0x6d66090a332d202f\n"
".quad 0x3233662e6e722e61,0x2c30313266250920,0x202c393032662520,0x25202c3938316625\n"
".quad 0x66090a3b38303266,0x33662e6e722e616d,0x3131326625092032,0x2c3938316625202c\n"
".quad 0x202c303132662520,0x090a3b3730326625,0x662e6e722e616d66,0x3132662509203233\n"
".quad 0x3938316625202c32,0x2c3131326625202c,0x0a3b363032662520,0x3233662e766f6d09\n"
".quad 0x2c33313266250920,0x6161326533663020,0x092020203b626161,0x3636312e30202f2f\n"
".quad 0x6c756d090a373636,0x662509203233662e,0x326625202c343132,0x31326625202c3231\n"
".quad 0x636f6c2e090a3b33,0x3009343509363109,0x33662e6c756d090a,0x3531326625092032\n"
".quad 0x2c3938316625202c,0x0a3b383931662520,0x3233662e766f6d09,0x2c36313266250920\n"
".quad 0x6161326533663020,0x092020203b626161,0x3636312e30202f2f,0x6c756d090a373636\n"
".quad 0x662509203233662e,0x326625202c373132,0x31326625202c3531,0x636f6c2e090a3b36\n"
".quad 0x0939383209363109,0x662e6c756d090a30,0x3132662509203233,0x3739316625202c38\n"
".quad 0x3b3436316625202c,0x6e722e616d66090a,0x662509203233662e,0x316625202c393132\n"
".quad 0x30326625202c3237,0x3831326625202c35,0x34326c756d090a3b,0x203233752e6f6c2e\n"
".quad 0x25202c3939722509,0x317225202c303172,0x2e616d66090a3b31,0x09203233662e6e72\n"
".quad 0x25202c3032326625,0x6625202c30383166,0x326625202c343132,0x616d66090a3b3931\n"
".quad 0x203233662e6e722e,0x202c313232662509,0x25202c3838316625,0x6625202c37313266\n"
".quad 0x6f6d090a3b303232,0x2509203233662e76,0x6630202c32323266,0x3030303066373334\n"
".quad 0x202f2f092020203b,0x6c756d090a353532,0x662509203233662e,0x326625202c333232\n"
".quad 0x32326625202c3132,0x2e747663090a3b32,0x2e3233752e697a72,0x3172250920323366\n"
".quad 0x32326625202c3030,0x702e646c090a3b33,0x3436752e6d617261,0x202c316472250920\n"
".quad 0x70616475635f5f5b,0x35315a5f5f6d7261,0x7265646e65725f64,0x5063696275636942\n"
".quad 0x6a34726168637536,0x645f66666666666a,0x5d74757074756f5f,0x752e646461090a3b\n"
".quad 0x3031722509203233,0x202c387225202c31,0x63090a3b39397225,0x752e3436752e7476\n"
".quad 0x3264722509203233,0x3b3130317225202c,0x69772e6c756d090a,0x09203233752e6564\n"
".quad 0x7225202c33647225,0x0a3b34202c313031,0x3436752e64646109,0x202c346472250920\n"
".quad 0x7225202c31647225,0x766f6d090a3b3364,0x722509203233732e,0x317225202c323031\n"
".quad 0x766f6d090a3b3030,0x722509203233752e,0x0a3b30202c333031,0x626f6c672e747309\n"
".quad 0x38752e34762e6c61,0x2b346472255b0920,0x3172257b202c5d30,0x32303172252c3230\n"
".quad 0x252c32303172252c,0x240a3b7d33303172,0x32315f35315f744c,0x6f6c2e090a3a3238\n"
".quad 0x3139320936310963,0x74697865090a3009,0x6e6557444c240a3b,0x5f6435315a5f5f64\n"
".quad 0x69427265646e6572,0x7536506369627563,0x666a6a3472616863,0x7d090a3a66666666\n"
".quad 0x35315a5f202f2f20,0x7265646e65725f64,0x5063696275636942,0x6a34726168637536\n"
".quad 0x0a0a66666666666a,0x207972746e652e09,0x65725f6439315a5f,0x747361467265646e\n"
".quad 0x5063696275636942,0x6a34726168637536,0x282066666666666a,0x617261702e09090a\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x5f6439315a5f5f6d,0x61467265646e6572\n"
".quad 0x6962756369427473,0x7261686375365063,0x66666666666a6a34,0x757074756f5f645f\n"
".quad 0x61702e09090a2c74,0x3233752e206d6172,0x70616475635f5f20,0x39315a5f5f6d7261\n"
".quad 0x7265646e65725f64,0x7563694274736146,0x6863753650636962,0x6666666a6a347261\n"
".quad 0x68746469775f6666,0x7261702e09090a2c,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x6439315a5f5f6d72,0x467265646e65725f,0x6275636942747361,0x6168637536506369\n"
".quad 0x666666666a6a3472,0x7468676965685f66,0x7261702e09090a2c,0x203233662e206d61\n"
".quad 0x6170616475635f5f,0x6439315a5f5f6d72,0x467265646e65725f,0x6275636942747361\n"
".quad 0x6168637536506369,0x666666666a6a3472,0x09090a2c78745f66,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x5f5f6d7261706164,0x6e65725f6439315a,0x4274736146726564\n"
".quad 0x3650636962756369,0x6a6a347261686375,0x79745f6666666666,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x6439315a5f5f6d72,0x467265646e65725f\n"
".quad 0x6275636942747361,0x6168637536506369,0x666666666a6a3472,0x2c656c6163735f66\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x5f6439315a5f5f6d\n"
".quad 0x61467265646e6572,0x6962756369427473,0x7261686375365063,0x66666666666a6a34\n"
".quad 0x2e09090a2c78635f,0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x646e65725f643931,0x6942747361467265,0x7536506369627563,0x666a6a3472616863\n"
".quad 0x2979635f66666666,0x65722e090a7b090a,0x25203233752e2067,0x090a3b3e35343c72\n"
".quad 0x36752e206765722e,0x3e363c6472252034,0x206765722e090a3b,0x3c6625203233662e\n"
".quad 0x2e090a3b3e333431,0x6572702e20676572,0x3b3e333c70252064,0x3109636f6c2e090a\n"
".quad 0x0a30093539320936,0x6967656257444c24,0x5f6439315a5f5f6e,0x61467265646e6572\n"
".quad 0x6962756369427473,0x7261686375365063,0x66666666666a6a34,0x752e766f6d090a3a\n"
".quad 0x2c31722509203233,0x2e64696174632520,0x2e766f6d090a3b78,0x3272250920323375\n"
".quad 0x2e6469746e25202c,0x326c756d090a3b78,0x3233752e6f6c2e34,0x25202c3372250920\n"
".quad 0x3b327225202c3172,0x33752e766f6d090a,0x202c347225092032,0x792e646961746325\n"
".quad 0x752e766f6d090a3b,0x2c35722509203233,0x792e6469746e2520,0x34326c756d090a3b\n"
".quad 0x203233752e6f6c2e,0x7225202c36722509,0x0a3b357225202c34,0x3233752e766f6d09\n"
".quad 0x25202c3772250920,0x090a3b782e646974,0x203233752e646461,0x7225202c38722509\n"
".quad 0x0a3b337225202c37,0x3233752e766f6d09,0x25202c3972250920,0x090a3b792e646974\n"
".quad 0x203233752e646461,0x25202c3031722509,0x3b367225202c3972,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5b202c31317225,0x726170616475635f,0x5f6439315a5f5f6d\n"
".quad 0x61467265646e6572,0x6962756369427473,0x7261686375365063,0x66666666666a6a34\n"
".quad 0x3b5d68746469775f,0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c32317225\n"
".quad 0x726170616475635f,0x5f6439315a5f5f6d,0x61467265646e6572,0x6962756369427473\n"
".quad 0x7261686375365063,0x66666666666a6a34,0x5d7468676965685f,0x672e746573090a3b\n"
".quad 0x33752e3233752e74,0x2c33317225092032,0x25202c3231722520,0x656e090a3b303172\n"
".quad 0x2509203233732e67,0x317225202c343172,0x2e746573090a3b33,0x752e3233752e746c\n"
".quad 0x3531722509203233,0x25202c387225202c,0x656e090a3b313172,0x2509203233732e67\n"
".quad 0x317225202c363172,0x2e646e61090a3b35,0x3172250920323362,0x2c34317225202c37\n"
".quad 0x090a3b3631722520,0x203233752e766f6d,0x30202c3831722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x317225202c317025,0x3b38317225202c37,0x622031702540090a\n"
".quad 0x5f744c2409206172,0x3b323832315f3631,0x3109636f6c2e090a,0x090a300934330936\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x387225202c316625,0x61702e646c090a3b\n"
".quad 0x203233662e6d6172,0x5f5b202c32662509,0x726170616475635f,0x5f6439315a5f5f6d\n"
".quad 0x61467265646e6572,0x6962756369427473,0x7261686375365063,0x66666666666a6a34\n"
".quad 0x73090a3b5d78635f,0x09203233662e6275,0x316625202c336625,0x090a3b326625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c34,0x5f5f6d7261706164\n"
".quad 0x6e65725f6439315a,0x4274736146726564,0x3650636962756369,0x6a6a347261686375\n"
".quad 0x63735f6666666666,0x66090a3b5d656c61,0x33662e6e722e616d,0x202c356625092032\n"
".quad 0x336625202c346625,0x090a3b326625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c36,0x5f5f6d7261706164,0x6e65725f6439315a,0x4274736146726564\n"
".quad 0x3650636962756369,0x6a6a347261686375,0x78745f6666666666,0x2e646461090a3b5d\n"
".quad 0x3766250920323366,0x25202c366625202c,0x766f6d090a3b3566,0x662509203233662e\n"
".quad 0x3066626630202c38,0x20203b3030303030,0x2d202f2f09202020,0x646461090a352e30\n"
".quad 0x662509203233662e,0x202c376625202c39,0x7663090a3b386625,0x33662e696d722e74\n"
".quad 0x2509203233662e32,0x396625202c303166,0x662e627573090a3b,0x3131662509203233\n"
".quad 0x25202c396625202c,0x6f6d090a3b303166,0x2509203233662e76,0x346630202c323166\n"
".quad 0x3b30303030303430,0x202f2f0920202020,0x662e627573090a33,0x3331662509203233\n"
".quad 0x202c32316625202c,0x6d090a3b31316625,0x09203233662e766f,0x6630202c34316625\n"
".quad 0x3030303030343063,0x2f2f09202020203b,0x616d66090a332d20,0x203233662e6e722e\n"
".quad 0x25202c3531662509,0x316625202c313166,0x3b34316625202c33,0x33662e766f6d090a\n"
".quad 0x2c36316625092032,0x3030386633663020,0x202020203b303030,0x66090a31202f2f09\n"
".quad 0x33662e6e722e616d,0x2c37316625092032,0x25202c3131662520,0x316625202c353166\n"
".quad 0x2e766f6d090a3b36,0x3166250920323366,0x3265336630202c38,0x20203b6261616161\n"
".quad 0x2e30202f2f092020,0x090a373636363631,0x203233662e6c756d,0x25202c3931662509\n"
".quad 0x316625202c373166,0x636f6c2e090a3b38,0x3009313409363109,0x33662e766f6d090a\n"
".quad 0x2c30326625092032,0x3030633063663020,0x202020203b303030,0x090a362d202f2f09\n"
".quad 0x203233662e766f6d,0x30202c3132662509,0x3030303034303466,0x2f09202020203b30\n"
".quad 0x616d66090a33202f,0x203233662e6e722e,0x25202c3232662509,0x316625202c313266\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x2c33326625092032,0x25202c3131662520\n"
".quad 0x6f6d090a3b313166,0x2509203233662e76,0x346630202c343266,0x3b30303030303830\n"
".quad 0x202f2f0920202020,0x722e616d66090a34,0x2509203233662e6e,0x326625202c353266\n"
".quad 0x2c33326625202c32,0x090a3b3432662520,0x203233662e766f6d,0x30202c3632662509\n"
".quad 0x6161616132653366,0x2f09202020203b62,0x363636312e30202f,0x2e6c756d090a3736\n"
".quad 0x3266250920323366,0x2c35326625202c37,0x090a3b3632662520,0x09363109636f6c2e\n"
".quad 0x6461090a30093036,0x2509203233662e64,0x326625202c383266,0x3b39316625202c37\n"
".quad 0x3109636f6c2e090a,0x090a300938340936,0x203233662e766f6d,0x30202c3932662509\n"
".quad 0x3030303034303466,0x2f09202020203b30,0x766f6d090a33202f,0x662509203233662e\n"
".quad 0x30636630202c3033,0x203b303030303034,0x2d202f2f09202020,0x722e616d66090a33\n"
".quad 0x2509203233662e6e,0x336625202c313366,0x2c31316625202c30,0x090a3b3932662520\n"
".quad 0x203233662e766f6d,0x30202c3233662509,0x3030303034303466,0x2f09202020203b30\n"
".quad 0x616d66090a33202f,0x203233662e6e722e,0x25202c3333662509,0x336625202c313166\n"
".quad 0x3b32336625202c31,0x33662e766f6d090a,0x2c34336625092032,0x3030386633663020\n"
".quad 0x202020203b303030,0x66090a31202f2f09,0x33662e6e722e616d,0x2c35336625092032\n"
".quad 0x25202c3131662520,0x336625202c333366,0x2e766f6d090a3b34,0x3366250920323366\n"
".quad 0x3265336630202c36,0x20203b6261616161,0x2e30202f2f092020,0x090a373636363631\n"
".quad 0x203233662e6c756d,0x25202c3733662509,0x336625202c353366,0x636f6c2e090a3b36\n"
".quad 0x3009343509363109,0x33662e6c756d090a,0x2c38336625092032,0x25202c3131662520\n"
".quad 0x6f6d090a3b333266,0x2509203233662e76,0x336630202c393366,0x3b62616161613265\n"
".quad 0x202f2f0920202020,0x3736363636312e30,0x33662e6c756d090a,0x2c30346625092032\n"
".quad 0x25202c3833662520,0x6c2e090a3b393366,0x353609363109636f,0x2e646461090a3009\n"
".quad 0x3466250920323366,0x2c30346625202c31,0x090a3b3733662520,0x09363109636f6c2e\n"
".quad 0x6964090a30093237,0x3233662e6e722e76,0x202c323466250920,0x6625202c37326625\n"
".quad 0x766f6d090a3b3832,0x662509203233662e,0x66626630202c3334,0x203b303030303038\n"
".quad 0x2d202f2f09202020,0x662e646461090a31,0x3434662509203233,0x202c32346625202c\n"
".quad 0x6d090a3b33346625,0x09203233662e766f,0x6630202c35346625,0x3030303030306633\n"
".quad 0x2f2f09202020203b,0x6461090a352e3020,0x2509203233662e64,0x346625202c363466\n"
".quad 0x3b35346625202c34,0x3109636f6c2e090a,0x090a300937370936,0x662e6e722e766964\n"
".quad 0x3734662509203233,0x202c30346625202c,0x6d090a3b31346625,0x09203233662e766f\n"
".quad 0x6630202c38346625,0x3030303030386633,0x2f2f09202020203b,0x2e646461090a3120\n"
".quad 0x3466250920323366,0x2c37346625202c39,0x090a3b3834662520,0x203233662e766f6d\n"
".quad 0x30202c3035662509,0x3030303030663366,0x2f09202020203b30,0x61090a352e30202f\n"
".quad 0x09203233662e6464,0x6625202c31356625,0x30356625202c3934,0x09636f6c2e090a3b\n"
".quad 0x0a30093134093631,0x2e6e722e74766309,0x203233752e323366,0x25202c3235662509\n"
".quad 0x646c090a3b303172,0x662e6d617261702e,0x3335662509203233,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x646e65725f643931,0x6942747361467265,0x7536506369627563\n"
".quad 0x666a6a3472616863,0x5d79635f66666666,0x662e627573090a3b,0x3435662509203233\n"
".quad 0x202c32356625202c,0x66090a3b33356625,0x33662e6e722e616d,0x2c35356625092032\n"
".quad 0x6625202c34662520,0x33356625202c3435,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5b202c3635662509,0x6170616475635f5f,0x6439315a5f5f6d72,0x467265646e65725f\n"
".quad 0x6275636942747361,0x6168637536506369,0x666666666a6a3472,0x090a3b5d79745f66\n"
".quad 0x203233662e646461,0x25202c3735662509,0x356625202c363566,0x2e766f6d090a3b35\n"
".quad 0x3566250920323366,0x3066626630202c38,0x20203b3030303030,0x302d202f2f092020\n"
".quad 0x2e646461090a352e,0x3566250920323366,0x2c37356625202c39,0x090a3b3835662520\n"
".quad 0x2e696d722e747663,0x203233662e323366,0x25202c3036662509,0x7573090a3b393566\n"
".quad 0x2509203233662e62,0x356625202c313666,0x3b30366625202c39,0x33662e766f6d090a\n"
".quad 0x2c32366625092032,0x3030633063663020,0x202020203b303030,0x090a362d202f2f09\n"
".quad 0x203233662e766f6d,0x30202c3336662509,0x3030303034303466,0x2f09202020203b30\n"
".quad 0x616d66090a33202f,0x203233662e6e722e,0x25202c3436662509,0x366625202c333666\n"
".quad 0x3b32366625202c31,0x33662e6c756d090a,0x2c35366625092032,0x25202c3136662520\n"
".quad 0x6f6d090a3b313666,0x2509203233662e76,0x346630202c363666,0x3b30303030303830\n"
".quad 0x202f2f0920202020,0x722e616d66090a34,0x2509203233662e6e,0x366625202c373666\n"
".quad 0x2c35366625202c34,0x090a3b3636662520,0x203233662e766f6d,0x30202c3836662509\n"
".quad 0x6161616132653366,0x2f09202020203b62,0x363636312e30202f,0x2e6c756d090a3736\n"
".quad 0x3666250920323366,0x2c37366625202c39,0x090a3b3836662520,0x09363109636f6c2e\n"
".quad 0x6f6d090a30093433,0x2509203233662e76,0x346630202c303766,0x3b30303030303430\n"
".quad 0x202f2f0920202020,0x662e627573090a33,0x3137662509203233,0x202c30376625202c\n"
".quad 0x6d090a3b31366625,0x09203233662e766f,0x6630202c32376625,0x3030303030343063\n"
".quad 0x2f2f09202020203b,0x616d66090a332d20,0x203233662e6e722e,0x25202c3337662509\n"
".quad 0x376625202c313666,0x3b32376625202c31,0x33662e766f6d090a,0x2c34376625092032\n"
".quad 0x3030386633663020,0x202020203b303030,0x66090a31202f2f09,0x33662e6e722e616d\n"
".quad 0x2c35376625092032,0x25202c3136662520,0x376625202c333766,0x2e766f6d090a3b34\n"
".quad 0x3766250920323366,0x3265336630202c36,0x20203b6261616161,0x2e30202f2f092020\n"
".quad 0x090a373636363631,0x203233662e6c756d,0x25202c3737662509,0x376625202c353766\n"
".quad 0x636f6c2e090a3b36,0x3009343509363109,0x33662e6c756d090a,0x2c38376625092032\n"
".quad 0x25202c3136662520,0x6f6d090a3b353666,0x2509203233662e76,0x336630202c393766\n"
".quad 0x3b62616161613265,0x202f2f0920202020,0x3736363636312e30,0x33662e6c756d090a\n"
".quad 0x2c30386625092032,0x25202c3837662520,0x6c2e090a3b393766,0x383409363109636f\n"
".quad 0x2e766f6d090a3009,0x3866250920323366,0x3430346630202c31,0x20203b3030303030\n"
".quad 0x0a33202f2f092020,0x3233662e766f6d09,0x202c323866250920,0x3030303430636630\n"
".quad 0x09202020203b3030,0x66090a332d202f2f,0x33662e6e722e616d,0x2c33386625092032\n"
".quad 0x25202c3238662520,0x386625202c313666,0x2e766f6d090a3b31,0x3866250920323366\n"
".quad 0x3430346630202c34,0x20203b3030303030,0x0a33202f2f092020,0x2e6e722e616d6609\n"
".quad 0x3866250920323366,0x2c31366625202c35,0x25202c3338662520,0x6f6d090a3b343866\n"
".quad 0x2509203233662e76,0x336630202c363866,0x3b30303030303866,0x202f2f0920202020\n"
".quad 0x722e616d66090a31,0x2509203233662e6e,0x366625202c373866,0x2c35386625202c31\n"
".quad 0x090a3b3638662520,0x203233662e766f6d,0x30202c3838662509,0x6161616132653366\n"
".quad 0x2f09202020203b62,0x363636312e30202f,0x2e6c756d090a3736,0x3866250920323366\n"
".quad 0x2c37386625202c39,0x090a3b3838662520,0x09363109636f6c2e,0x61090a3009323331\n"
".quad 0x09203233662e6464,0x6625202c30396625,0x39366625202c3737,0x722e766964090a3b\n"
".quad 0x2509203233662e6e,0x366625202c313966,0x3b30396625202c39,0x33662e766f6d090a\n"
".quad 0x2c32396625092032,0x3030386662663020,0x202020203b303030,0x090a312d202f2f09\n"
".quad 0x203233662e646461,0x25202c3339662509,0x396625202c313966,0x2e646461090a3b32\n"
".quad 0x3966250920323366,0x2c36346625202c34,0x090a3b3031662520,0x203233662e766f6d\n"
".quad 0x30202c3539662509,0x3030303030663366,0x2f09202020203b30,0x61090a352e30202f\n"
".quad 0x09203233662e6464,0x6625202c36396625,0x35396625202c3339,0x662e646461090a3b\n"
".quad 0x3739662509203233,0x202c30366625202c,0x6d090a3b36396625,0x09203233662e766f\n"
".quad 0x6625202c38396625,0x766f6d090a3b3439,0x662509203233662e,0x37396625202c3939\n"
".quad 0x662e766f6d090a3b,0x3031662509203233,0x3030306630202c30,0x20203b3030303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x202c313031662509,0x090a3b3030316625\n"
".quad 0x203233662e766f6d,0x202c323031662509,0x3030303030306630,0x2f092020203b3030\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x316625202c333031,0x786574090a3b3230\n"
".quad 0x752e34762e64322e,0x7b203233662e3233,0x3272252c39317225,0x252c313272252c30\n"
".quad 0x65745b2c7d323272,0x2c383966257b2c78,0x3166252c39396625,0x33303166252c3130\n"
".quad 0x6f6c2e090a3b5d7d,0x3433310936310963,0x2e766f6d090a3009,0x3272250920323373\n"
".quad 0x3b39317225202c33,0x33662e646461090a,0x3430316625092032,0x202c31356625202c\n"
".quad 0x6d090a3b30316625,0x09203233662e766f,0x25202c3530316625,0x6d090a3b34303166\n"
".quad 0x09203233662e766f,0x25202c3630316625,0x6f6d090a3b373966,0x2509203233662e76\n"
".quad 0x6630202c37303166,0x3030303030303030,0x202f2f092020203b,0x662e766f6d090a30\n"
".quad 0x3031662509203233,0x3730316625202c38,0x662e766f6d090a3b,0x3031662509203233\n"
".quad 0x3030306630202c39,0x20203b3030303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x202c303131662509,0x090a3b3930316625,0x762e64322e786574,0x33662e3233752e34\n"
".quad 0x2c343272257b2032,0x3272252c35327225,0x2c7d373272252c36,0x66257b2c7865745b\n"
".quad 0x303166252c353031,0x2c38303166252c36,0x3b5d7d3031316625,0x33732e766f6d090a\n"
".quad 0x2c38327225092032,0x090a3b3432722520,0x203233662e646461,0x202c313131662509\n"
".quad 0x6625202c39386625,0x766964090a3b3038,0x203233662e6e722e,0x202c323131662509\n"
".quad 0x6625202c30386625,0x6f6d090a3b313131,0x2509203233662e76,0x6630202c33313166\n"
".quad 0x3030303030386633,0x202f2f092020203b,0x662e646461090a31,0x3131662509203233\n"
".quad 0x3231316625202c34,0x3b3331316625202c,0x33662e766f6d090a,0x3531316625092032\n"
".quad 0x303066336630202c,0x2020203b30303030,0x0a352e30202f2f09,0x3233662e64646109\n"
".quad 0x2c36313166250920,0x202c343131662520,0x090a3b3531316625,0x203233662e646461\n"
".quad 0x202c373131662509,0x6625202c30366625,0x6f6d090a3b363131,0x2509203233662e76\n"
".quad 0x6625202c38313166,0x766f6d090a3b3439,0x662509203233662e,0x316625202c393131\n"
".quad 0x766f6d090a3b3731,0x662509203233662e,0x306630202c303231,0x3b30303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x3132316625092032,0x3b3032316625202c\n"
".quad 0x33662e766f6d090a,0x3232316625092032,0x303030306630202c,0x2020203b30303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x25202c3332316625,0x74090a3b32323166\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c393272257b20,0x313372252c303372\n"
".quad 0x5b2c7d323372252c,0x3166257b2c786574,0x39313166252c3831,0x252c31323166252c\n"
".quad 0x0a3b5d7d33323166,0x3233732e766f6d09,0x202c333372250920,0x6d090a3b39327225\n"
".quad 0x09203233662e766f,0x25202c3432316625,0x6d090a3b34303166,0x09203233662e766f\n"
".quad 0x25202c3532316625,0x6d090a3b37313166,0x09203233662e766f,0x30202c3632316625\n"
".quad 0x3030303030303066,0x2f2f092020203b30,0x2e766f6d090a3020,0x3166250920323366\n"
".quad 0x32316625202c3732,0x2e766f6d090a3b36,0x3166250920323366,0x30306630202c3832\n"
".quad 0x203b303030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x2c39323166250920\n"
".quad 0x0a3b383231662520,0x2e64322e78657409,0x662e3233752e3476,0x343372257b203233\n"
".quad 0x72252c353372252c,0x7d373372252c3633,0x257b2c7865745b2c,0x3166252c34323166\n"
".quad 0x37323166252c3532,0x5d7d39323166252c,0x732e766f6d090a3b,0x3833722509203233\n"
".quad 0x0a3b34337225202c,0x363109636f6c2e09,0x090a300937303309,0x203233622e766f6d\n"
".quad 0x202c303331662509,0x6d090a3b38327225,0x09203233622e766f,0x25202c3133316625\n"
".quad 0x6f6d090a3b333272,0x2509203233622e76,0x7225202c32333166,0x766f6d090a3b3833\n"
".quad 0x662509203233622e,0x337225202c333331,0x2e6c756d090a3b33,0x3166250920323366\n"
".quad 0x33316625202c3433,0x3b31346625202c30,0x33662e6c756d090a,0x3533316625092032\n"
".quad 0x2c3233316625202c,0x090a3b3134662520,0x6f6c2e34326c756d,0x722509203233752e\n"
".quad 0x30317225202c3933,0x0a3b31317225202c,0x2e6e722e616d6609,0x3166250920323366\n"
".quad 0x33316625202c3633,0x2c38326625202c31,0x0a3b343331662520,0x2e6e722e616d6609\n"
".quad 0x3166250920323366,0x33316625202c3733,0x2c38326625202c33,0x0a3b353331662520\n"
".quad 0x3233662e6c756d09,0x2c38333166250920,0x202c363331662520,0x66090a3b30396625\n"
".quad 0x33662e6e722e616d,0x3933316625092032,0x2c3131316625202c,0x202c373331662520\n"
".quad 0x090a3b3833316625,0x203233662e766f6d,0x202c303431662509,0x3030663733346630\n"
".quad 0x2f092020203b3030,0x6d090a353532202f,0x09203233662e6c75,0x25202c3134316625\n"
".quad 0x6625202c39333166,0x646c090a3b303431,0x752e6d617261702e,0x3164722509203436\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x646e65725f643931,0x6942747361467265\n"
".quad 0x7536506369627563,0x666a6a3472616863,0x6f5f645f66666666,0x0a3b5d7475707475\n"
".quad 0x3233752e64646109,0x202c303472250920,0x337225202c387225,0x2e747663090a3b39\n"
".quad 0x203233752e343675,0x25202c3264722509,0x756d090a3b303472,0x752e656469772e6c\n"
".quad 0x3364722509203233,0x202c30347225202c,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x2c31647225202c34,0x090a3b3364722520,0x2e697a722e747663,0x203233662e323375\n"
".quad 0x25202c3134722509,0x6d090a3b31343166,0x09203233732e766f,0x7225202c32347225\n"
".quad 0x766f6d090a3b3134,0x722509203233752e,0x090a3b30202c3334,0x61626f6c672e7473\n"
".quad 0x2038752e34762e6c,0x302b346472255b09,0x323472257b202c5d,0x72252c323472252c\n"
".quad 0x7d333472252c3234,0x36315f744c240a3b,0x090a3a323832315f,0x09363109636f6c2e\n"
".quad 0x65090a3009393033,0x444c240a3b746978,0x315a5f5f646e6557,0x65646e65725f6439\n"
".quad 0x6369427473614672,0x6375365063696275,0x66666a6a34726168,0x207d090a3a666666\n"
".quad 0x6439315a5f202f2f,0x467265646e65725f,0x6275636942747361,0x6168637536506369\n"
".quad 0x666666666a6a3472,0x746e652e090a0a66,0x6434315a5f207972,0x437265646e65725f\n"
".quad 0x7536506d6f527461,0x666a6a3472616863,0x090a282066666666,0x206d617261702e09\n"
".quad 0x635f5f203436752e,0x5f6d726170616475,0x65725f6434315a5f,0x527461437265646e\n"
".quad 0x6168637536506d6f,0x666666666a6a3472,0x7074756f5f645f66,0x702e09090a2c7475\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x315a5f5f6d726170,0x65646e65725f6434\n"
".quad 0x506d6f5274614372,0x6a34726168637536,0x775f66666666666a,0x09090a2c68746469\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x5f5f6d7261706164,0x6e65725f6434315a\n"
".quad 0x6f52746143726564,0x726168637536506d,0x66666666666a6a34,0x2c7468676965685f\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x5f6434315a5f5f6d\n"
".quad 0x61437265646e6572,0x637536506d6f5274,0x66666a6a34726168,0x0a2c78745f666666\n"
".quad 0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563,0x725f6434315a5f5f\n"
".quad 0x7461437265646e65,0x68637536506d6f52,0x6666666a6a347261,0x090a2c79745f6666\n"
".quad 0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475,0x65725f6434315a5f\n"
".quad 0x527461437265646e,0x6168637536506d6f,0x666666666a6a3472,0x2c656c6163735f66\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x5f6434315a5f5f6d\n"
".quad 0x61437265646e6572,0x637536506d6f5274,0x66666a6a34726168,0x0a2c78635f666666\n"
".quad 0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563,0x725f6434315a5f5f\n"
".quad 0x7461437265646e65,0x68637536506d6f52,0x6666666a6a347261,0x090a2979635f6666\n"
".quad 0x206765722e090a7b,0x3c7225203233752e,0x2e090a3b3e353031,0x3436752e20676572\n"
".quad 0x3b3e363c64722520,0x2e206765722e090a,0x323c662520323366,0x722e090a3b3e3731\n"
".quad 0x646572702e206765,0x0a3b3e333c702520,0x363109636f6c2e09,0x240a300933313309\n"
".quad 0x6e6967656257444c,0x725f6434315a5f5f,0x7461437265646e65,0x68637536506d6f52\n"
".quad 0x6666666a6a347261,0x766f6d090a3a6666,0x722509203233752e,0x6961746325202c31\n"
".quad 0x6f6d090a3b782e64,0x2509203233752e76,0x69746e25202c3272,0x756d090a3b782e64\n"
".quad 0x752e6f6c2e34326c,0x2c33722509203233,0x7225202c31722520,0x2e766f6d090a3b32\n"
".quad 0x3472250920323375,0x646961746325202c,0x766f6d090a3b792e,0x722509203233752e\n"
".quad 0x6469746e25202c35,0x6c756d090a3b792e,0x33752e6f6c2e3432,0x202c367225092032\n"
".quad 0x357225202c347225,0x752e766f6d090a3b,0x2c37722509203233,0x3b782e6469742520\n"
".quad 0x33752e646461090a,0x202c387225092032,0x337225202c377225,0x752e766f6d090a3b\n"
".quad 0x2c39722509203233,0x3b792e6469742520,0x33752e646461090a,0x2c30317225092032\n"
".quad 0x7225202c39722520,0x702e646c090a3b36,0x3233752e6d617261,0x202c313172250920\n"
".quad 0x70616475635f5f5b,0x34315a5f5f6d7261,0x7265646e65725f64,0x36506d6f52746143\n"
".quad 0x6a6a347261686375,0x69775f6666666666,0x6c090a3b5d687464,0x2e6d617261702e64\n"
".quad 0x3172250920323375,0x75635f5f5b202c32,0x5f5f6d7261706164,0x6e65725f6434315a\n"
".quad 0x6f52746143726564,0x726168637536506d,0x66666666666a6a34,0x5d7468676965685f\n"
".quad 0x672e746573090a3b,0x33752e3233752e74,0x2c33317225092032,0x25202c3231722520\n"
".quad 0x656e090a3b303172,0x2509203233732e67,0x317225202c343172,0x2e746573090a3b33\n"
".quad 0x752e3233752e746c,0x3531722509203233,0x25202c387225202c,0x656e090a3b313172\n"
".quad 0x2509203233732e67,0x317225202c363172,0x2e646e61090a3b35,0x3172250920323362\n"
".quad 0x2c34317225202c37,0x090a3b3631722520,0x203233752e766f6d,0x30202c3831722509\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x317225202c317025,0x3b38317225202c37\n"
".quad 0x622031702540090a,0x5f744c2409206172,0x3b323832315f3731,0x3109636f6c2e090a\n"
".quad 0x0a30093432330936,0x2e6e722e74766309,0x203233752e323366,0x7225202c31662509\n"
".quad 0x2e747663090a3b38,0x752e3233662e6e72,0x2c32662509203233,0x090a3b3031722520\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c33,0x5f5f6d7261706164\n"
".quad 0x6e65725f6434315a,0x6f52746143726564,0x726168637536506d,0x66666666666a6a34\n"
".quad 0x73090a3b5d78635f,0x09203233662e6275,0x316625202c346625,0x090a3b336625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c35,0x5f5f6d7261706164\n"
".quad 0x6e65725f6434315a,0x6f52746143726564,0x726168637536506d,0x66666666666a6a34\n"
".quad 0x73090a3b5d79635f,0x09203233662e6275,0x326625202c366625,0x090a3b356625202c\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c37,0x5f5f6d7261706164\n"
".quad 0x6e65725f6434315a,0x6f52746143726564,0x726168637536506d,0x66666666666a6a34\n"
".quad 0x3b5d656c6163735f,0x6e722e616d66090a,0x662509203233662e,0x202c376625202c38\n"
".quad 0x336625202c346625,0x722e616d66090a3b,0x2509203233662e6e,0x2c376625202c3966\n"
".quad 0x6625202c36662520,0x702e646c090a3b35,0x3233662e6d617261,0x202c303166250920\n"
".quad 0x70616475635f5f5b,0x34315a5f5f6d7261,0x7265646e65725f64,0x36506d6f52746143\n"
".quad 0x6a6a347261686375,0x78745f6666666666,0x2e646461090a3b5d,0x3166250920323366\n"
".quad 0x2c30316625202c31,0x6c090a3b38662520,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x6e65725f6434315a,0x6f52746143726564\n"
".quad 0x726168637536506d,0x66666666666a6a34,0x61090a3b5d79745f,0x09203233662e6464\n"
".quad 0x6625202c33316625,0x3b396625202c3231,0x33662e766f6d090a,0x2c34316625092032\n"
".quad 0x3030306662663020,0x202020203b303030,0x352e302d202f2f09,0x33662e646461090a\n"
".quad 0x2c35316625092032,0x25202c3131662520,0x6f6d090a3b343166,0x2509203233662e76\n"
".quad 0x626630202c363166,0x3b30303030303066,0x202f2f0920202020,0x6461090a352e302d\n"
".quad 0x2509203233662e64,0x316625202c373166,0x3b36316625202c33,0x6d722e747663090a\n"
".quad 0x33662e3233662e69,0x2c38316625092032,0x090a3b3531662520,0x2e696d722e747663\n"
".quad 0x203233662e323366,0x25202c3931662509,0x6f6d090a3b373166,0x2509203233662e76\n"
".quad 0x626630202c303266,0x3b30303030303866,0x202f2f0920202020,0x2e646461090a312d\n"
".quad 0x3266250920323366,0x2c38316625202c31,0x090a3b3032662520,0x203233662e766f6d\n"
".quad 0x30202c3232662509,0x3030303038666266,0x2f09202020203b30,0x6461090a312d202f\n"
".quad 0x2509203233662e64,0x316625202c333266,0x3b32326625202c39,0x33662e766f6d090a\n"
".quad 0x2c34326625092032,0x090a3b3132662520,0x203233662e766f6d,0x25202c3532662509\n"
".quad 0x6f6d090a3b333266,0x2509203233662e76,0x306630202c363266,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3732662509203233,0x0a3b36326625202c\n"
".quad 0x3233662e766f6d09,0x202c383266250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x326625202c393266,0x2e786574090a3b38\n"
".quad 0x33752e34762e6432,0x257b203233662e32,0x303272252c393172,0x72252c313272252c\n"
".quad 0x7865745b2c7d3232,0x252c343266257b2c,0x373266252c353266,0x3b5d7d393266252c\n"
".quad 0x3109636f6c2e090a,0x0a30093434320936,0x3233732e766f6d09,0x202c333272250920\n"
".quad 0x6d090a3b39317225,0x09203233662e766f,0x6625202c30336625,0x766f6d090a3b3831\n"
".quad 0x662509203233662e,0x33326625202c3133,0x662e766f6d090a3b,0x3233662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x25202c3333662509,0x6f6d090a3b323366,0x2509203233662e76,0x306630202c343366\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3533662509203233\n"
".quad 0x0a3b34336625202c,0x2e64322e78657409,0x662e3233752e3476,0x343272257b203233\n"
".quad 0x72252c353272252c,0x7d373272252c3632,0x257b2c7865745b2c,0x313366252c303366\n"
".quad 0x66252c333366252c,0x6d090a3b5d7d3533,0x09203233732e766f,0x7225202c38327225\n"
".quad 0x766f6d090a3b3432,0x662509203233662e,0x66336630202c3633,0x203b303030303038\n"
".quad 0x31202f2f09202020,0x33662e646461090a,0x2c37336625092032,0x25202c3831662520\n"
".quad 0x6f6d090a3b363366,0x2509203233662e76,0x336625202c383366,0x2e766f6d090a3b37\n"
".quad 0x3366250920323366,0x3b33326625202c39,0x33662e766f6d090a,0x2c30346625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6625202c31346625,0x766f6d090a3b3034,0x662509203233662e,0x30306630202c3234\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c33346625092032\n"
".quad 0x090a3b3234662520,0x762e64322e786574,0x33662e3233752e34,0x2c393272257b2032\n"
".quad 0x3372252c30337225,0x2c7d323372252c31,0x66257b2c7865745b,0x2c393366252c3833\n"
".quad 0x3466252c31346625,0x6f6d090a3b5d7d33,0x2509203233732e76,0x327225202c333372\n"
".quad 0x2e766f6d090a3b39,0x3466250920323366,0x3030346630202c34,0x20203b3030303030\n"
".quad 0x0a32202f2f092020,0x3233662e64646109,0x202c353466250920,0x6625202c38316625\n"
".quad 0x766f6d090a3b3434,0x662509203233662e,0x35346625202c3634,0x662e766f6d090a3b\n"
".quad 0x3734662509203233,0x0a3b33326625202c,0x3233662e766f6d09,0x202c383466250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x346625202c393466,0x2e766f6d090a3b38,0x3566250920323366,0x3030306630202c30\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c313566250920\n"
".quad 0x74090a3b30356625,0x34762e64322e7865,0x3233662e3233752e,0x252c343372257b20\n"
".quad 0x363372252c353372,0x5b2c7d373372252c,0x3466257b2c786574,0x252c373466252c36\n"
".quad 0x313566252c393466,0x766f6d090a3b5d7d,0x722509203233732e,0x34337225202c3833\n"
".quad 0x662e766f6d090a3b,0x3235662509203233,0x0a3b31326625202c,0x3233662e766f6d09\n"
".quad 0x202c333566250920,0x6d090a3b39316625,0x09203233662e766f,0x6630202c34356625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3566250920323366\n"
".quad 0x3b34356625202c35,0x33662e766f6d090a,0x2c36356625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f,0x6625202c37356625\n"
".quad 0x786574090a3b3635,0x752e34762e64322e,0x7b203233662e3233,0x3472252c39337225\n"
".quad 0x252c313472252c30,0x65745b2c7d323472,0x2c323566257b2c78,0x3566252c33356625\n"
".quad 0x5d7d373566252c35,0x732e766f6d090a3b,0x3334722509203233,0x0a3b39337225202c\n"
".quad 0x3233662e766f6d09,0x202c383566250920,0x6d090a3b38316625,0x09203233662e766f\n"
".quad 0x6625202c39356625,0x766f6d090a3b3931,0x662509203233662e,0x30306630202c3036\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c31366625092032\n"
".quad 0x090a3b3036662520,0x203233662e766f6d,0x30202c3236662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x32366625202c3336\n"
".quad 0x322e786574090a3b,0x3233752e34762e64,0x72257b203233662e,0x2c353472252c3434\n"
".quad 0x3472252c36347225,0x2c7865745b2c7d37,0x66252c383566257b,0x2c313666252c3935\n"
".quad 0x0a3b5d7d33366625,0x3233732e766f6d09,0x202c383472250920,0x6d090a3b34347225\n"
".quad 0x09203233662e766f,0x6625202c34366625,0x766f6d090a3b3733,0x662509203233662e\n"
".quad 0x39316625202c3536,0x662e766f6d090a3b,0x3636662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x25202c3736662509\n"
".quad 0x6f6d090a3b363666,0x2509203233662e76,0x306630202c383666,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3936662509203233,0x0a3b38366625202c\n"
".quad 0x2e64322e78657409,0x662e3233752e3476,0x393472257b203233,0x72252c303572252c\n"
".quad 0x7d323572252c3135,0x257b2c7865745b2c,0x353666252c343666,0x66252c373666252c\n"
".quad 0x6d090a3b5d7d3936,0x09203233732e766f,0x7225202c33357225,0x766f6d090a3b3934\n"
".quad 0x662509203233662e,0x35346625202c3037,0x662e766f6d090a3b,0x3137662509203233\n"
".quad 0x0a3b39316625202c,0x3233662e766f6d09,0x202c323766250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x376625202c333766\n"
".quad 0x2e766f6d090a3b32,0x3766250920323366,0x3030306630202c34,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c353766250920,0x74090a3b34376625\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c343572257b20,0x363572252c353572\n"
".quad 0x5b2c7d373572252c,0x3766257b2c786574,0x252c313766252c30,0x353766252c333766\n"
".quad 0x766f6d090a3b5d7d,0x722509203233732e,0x34357225202c3835,0x662e766f6d090a3b\n"
".quad 0x3637662509203233,0x303866336630202c,0x2020203b30303030,0x090a31202f2f0920\n"
".quad 0x203233662e646461,0x25202c3737662509,0x376625202c393166,0x2e766f6d090a3b36\n"
".quad 0x3766250920323366,0x3b31326625202c38,0x33662e766f6d090a,0x2c39376625092032\n"
".quad 0x090a3b3737662520,0x203233662e766f6d,0x30202c3038662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30386625202c3138\n"
".quad 0x662e766f6d090a3b,0x3238662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x25202c3338662509,0x6574090a3b323866\n"
".quad 0x2e34762e64322e78,0x203233662e323375,0x72252c393572257b,0x2c313672252c3036\n"
".quad 0x745b2c7d32367225,0x383766257b2c7865,0x66252c393766252c,0x7d333866252c3138\n"
".quad 0x2e766f6d090a3b5d,0x3672250920323373,0x3b39357225202c33,0x33662e766f6d090a\n"
".quad 0x2c34386625092032,0x090a3b3831662520,0x203233662e766f6d,0x25202c3538662509\n"
".quad 0x6f6d090a3b373766,0x2509203233662e76,0x306630202c363866,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3738662509203233,0x0a3b36386625202c\n"
".quad 0x3233662e766f6d09,0x202c383866250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x386625202c393866,0x2e786574090a3b38\n"
".quad 0x33752e34762e6432,0x257b203233662e32,0x353672252c343672,0x72252c363672252c\n"
".quad 0x7865745b2c7d3736,0x252c343866257b2c,0x373866252c353866,0x3b5d7d393866252c\n"
".quad 0x33732e766f6d090a,0x2c38367225092032,0x090a3b3436722520,0x203233662e766f6d\n"
".quad 0x25202c3039662509,0x6f6d090a3b373366,0x2509203233662e76,0x376625202c313966\n"
".quad 0x2e766f6d090a3b37,0x3966250920323366,0x3030306630202c32,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c333966250920,0x6d090a3b32396625\n"
".quad 0x09203233662e766f,0x6630202c34396625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3966250920323366,0x3b34396625202c35,0x64322e786574090a\n"
".quad 0x2e3233752e34762e,0x3672257b20323366,0x252c303772252c39,0x323772252c313772\n"
".quad 0x7b2c7865745b2c7d,0x3966252c30396625,0x252c333966252c31,0x090a3b5d7d353966\n"
".quad 0x203233732e766f6d,0x25202c3337722509,0x6f6d090a3b393672,0x2509203233662e76\n"
".quad 0x346625202c363966,0x2e766f6d090a3b35,0x3966250920323366,0x3b37376625202c37\n"
".quad 0x33662e766f6d090a,0x2c38396625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6625202c39396625,0x766f6d090a3b3839\n"
".quad 0x662509203233662e,0x306630202c303031,0x3b30303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x3130316625092032,0x3b3030316625202c,0x64322e786574090a\n"
".quad 0x2e3233752e34762e,0x3772257b20323366,0x252c353772252c34,0x373772252c363772\n"
".quad 0x7b2c7865745b2c7d,0x3966252c36396625,0x252c393966252c37,0x0a3b5d7d31303166\n"
".quad 0x3233732e766f6d09,0x202c383772250920,0x6d090a3b34377225,0x09203233662e766f\n"
".quad 0x30202c3230316625,0x3030303030303466,0x2f2f092020203b30,0x2e646461090a3220\n"
".quad 0x3166250920323366,0x39316625202c3330,0x3b3230316625202c,0x33662e766f6d090a\n"
".quad 0x3430316625092032,0x0a3b31326625202c,0x3233662e766f6d09,0x2c35303166250920\n"
".quad 0x0a3b333031662520,0x3233662e766f6d09,0x2c36303166250920,0x3030303030663020\n"
".quad 0x092020203b303030,0x6f6d090a30202f2f,0x2509203233662e76,0x6625202c37303166\n"
".quad 0x6f6d090a3b363031,0x2509203233662e76,0x6630202c38303166,0x3030303030303030\n"
".quad 0x202f2f092020203b,0x662e766f6d090a30,0x3031662509203233,0x3830316625202c39\n"
".quad 0x322e786574090a3b,0x3233752e34762e64,0x72257b203233662e,0x2c303872252c3937\n"
".quad 0x3872252c31387225,0x2c7865745b2c7d32,0x252c34303166257b,0x3166252c35303166\n"
".quad 0x39303166252c3730,0x766f6d090a3b5d7d,0x722509203233732e,0x39377225202c3338\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x3b38316625202c30,0x33662e766f6d090a\n"
".quad 0x3131316625092032,0x3b3330316625202c,0x33662e766f6d090a,0x3231316625092032\n"
".quad 0x303030306630202c,0x2020203b30303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x25202c3331316625,0x6d090a3b32313166,0x09203233662e766f,0x30202c3431316625\n"
".quad 0x3030303030303066,0x2f2f092020203b30,0x2e766f6d090a3020,0x3166250920323366\n"
".quad 0x31316625202c3531,0x2e786574090a3b34,0x33752e34762e6432,0x257b203233662e32\n"
".quad 0x353872252c343872,0x72252c363872252c,0x7865745b2c7d3738,0x2c30313166257b2c\n"
".quad 0x66252c3131316625,0x313166252c333131,0x6f6d090a3b5d7d35,0x2509203233732e76\n"
".quad 0x387225202c383872,0x2e766f6d090a3b34,0x3166250920323366,0x37336625202c3631\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x3330316625202c37,0x662e766f6d090a3b\n"
".quad 0x3131662509203233,0x3030306630202c38,0x20203b3030303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x202c393131662509,0x090a3b3831316625,0x203233662e766f6d\n"
".quad 0x202c303231662509,0x3030303030306630,0x2f092020203b3030,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x316625202c313231,0x786574090a3b3032,0x752e34762e64322e\n"
".quad 0x7b203233662e3233,0x3972252c39387225,0x252c313972252c30,0x65745b2c7d323972\n"
".quad 0x36313166257b2c78,0x252c37313166252c,0x3166252c39313166,0x6d090a3b5d7d3132\n"
".quad 0x09203233732e766f,0x7225202c33397225,0x766f6d090a3b3938,0x662509203233662e\n"
".quad 0x346625202c323231,0x2e766f6d090a3b35,0x3166250920323366,0x30316625202c3332\n"
".quad 0x2e766f6d090a3b33,0x3166250920323366,0x30306630202c3432,0x203b303030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x2c35323166250920,0x0a3b343231662520\n"
".quad 0x3233662e766f6d09,0x2c36323166250920,0x3030303030663020,0x092020203b303030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x6625202c37323166,0x6574090a3b363231\n"
".quad 0x2e34762e64322e78,0x203233662e323375,0x72252c343972257b,0x2c363972252c3539\n"
".quad 0x745b2c7d37397225,0x323166257b2c7865,0x2c33323166252c32,0x66252c3532316625\n"
".quad 0x090a3b5d7d373231,0x203233732e766f6d,0x25202c3839722509,0x6c2e090a3b343972\n"
".quad 0x393109363109636f,0x627573090a300936,0x662509203233662e,0x316625202c383231\n"
".quad 0x3b38316625202c35,0x33662e766f6d090a,0x3932316625092032,0x303866336630202c\n"
".quad 0x2020203b30303030,0x6d090a31202f2f09,0x09203233662e766f,0x30202c3033316625\n"
".quad 0x3030303030663366,0x2f2f092020203b30,0x756d090a352e3020,0x2509203233662e6c\n"
".quad 0x6625202c31333166,0x316625202c303331,0x627573090a3b3832,0x662509203233662e\n"
".quad 0x316625202c323331,0x33316625202c3932,0x2e766f6d090a3b31,0x3166250920323366\n"
".quad 0x66626630202c3333,0x203b303030303030,0x302d202f2f092020,0x2e616d66090a352e\n"
".quad 0x09203233662e6e72,0x25202c3433316625,0x6625202c38323166,0x316625202c323331\n"
".quad 0x6c756d090a3b3333,0x662509203233662e,0x316625202c353331,0x33316625202c3832\n"
".quad 0x636f6c2e090a3b34,0x0933303209363109,0x662e766f6d090a30,0x3331662509203233\n"
".quad 0x3230636630202c36,0x20203b3030303030,0x2e322d202f2f0920,0x662e766f6d090a35\n"
".quad 0x3331662509203233,0x6366336630202c37,0x20203b3030303030,0x352e31202f2f0920\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c383331,0x32316625202c3733\n"
".quad 0x3633316625202c38,0x662e6c756d090a3b,0x3331662509203233,0x3832316625202c39\n"
".quad 0x3b3832316625202c,0x33662e766f6d090a,0x3034316625092032,0x303866336630202c\n"
".quad 0x2020203b30303030,0x66090a31202f2f09,0x33662e6e722e616d,0x3134316625092032\n"
".quad 0x2c3833316625202c,0x202c393331662520,0x090a3b3034316625,0x09363109636f6c2e\n"
".quad 0x6d090a3009303132,0x09203233662e766f,0x30202c3234316625,0x3030303030303466\n"
".quad 0x2f2f092020203b30,0x2e766f6d090a3220,0x3166250920323366,0x66336630202c3334\n"
".quad 0x203b303030303063,0x2e31202f2f092020,0x662e6c756d090a35,0x3431662509203233\n"
".quad 0x3334316625202c34,0x3b3832316625202c,0x33662e627573090a,0x3534316625092032\n"
".quad 0x2c3234316625202c,0x0a3b343431662520,0x3233662e766f6d09,0x2c36343166250920\n"
".quad 0x3030306633663020,0x092020203b303030,0x090a352e30202f2f,0x662e6e722e616d66\n"
".quad 0x3431662509203233,0x3832316625202c37,0x2c3534316625202c,0x0a3b363431662520\n"
".quad 0x3233662e6c756d09,0x2c38343166250920,0x202c383231662520,0x090a3b3734316625\n"
".quad 0x09363109636f6c2e,0x6d090a3009373132,0x09203233662e766f,0x30202c3934316625\n"
".quad 0x3030303030666266,0x2f2f092020203b30,0x6d090a352e302d20,0x09203233662e766f\n"
".quad 0x30202c3035316625,0x3030303030663366,0x2f2f092020203b30,0x6d66090a352e3020\n"
".quad 0x3233662e6e722e61,0x2c31353166250920,0x202c303531662520,0x25202c3832316625\n"
".quad 0x6d090a3b39343166,0x09203233662e6c75,0x25202c3235316625,0x6625202c39333166\n"
".quad 0x6c2e090a3b313531,0x343209363109636f,0x766f6d090a300934,0x662509203233622e\n"
".quad 0x327225202c333531,0x2e6c756d090a3b33,0x3166250920323366,0x33316625202c3435\n"
".quad 0x3335316625202c35,0x622e766f6d090a3b,0x3531662509203233,0x3b38327225202c35\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c363531,0x34316625202c3535\n"
".quad 0x3435316625202c31,0x622e766f6d090a3b,0x3531662509203233,0x3b33337225202c37\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c383531,0x34316625202c3735\n"
".quad 0x3635316625202c38,0x622e766f6d090a3b,0x3531662509203233,0x3b38337225202c39\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x316625202c303631,0x35316625202c3935\n"
".quad 0x3835316625202c32,0x622e766f6d090a3b,0x3631662509203233,0x3b33347225202c31\n"
".quad 0x33662e6c756d090a,0x3236316625092032,0x2c3533316625202c,0x0a3b313631662520\n"
".quad 0x3233622e766f6d09,0x2c33363166250920,0x090a3b3834722520,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x3336316625202c34,0x2c3134316625202c,0x0a3b323631662520\n"
".quad 0x3233622e766f6d09,0x2c35363166250920,0x090a3b3335722520,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x3536316625202c36,0x2c3834316625202c,0x0a3b343631662520\n"
".quad 0x3233622e766f6d09,0x2c37363166250920,0x090a3b3835722520,0x662e6e722e616d66\n"
".quad 0x3631662509203233,0x3736316625202c38,0x2c3235316625202c,0x0a3b363631662520\n"
".quad 0x3233622e766f6d09,0x2c39363166250920,0x090a3b3336722520,0x203233662e6c756d\n"
".quad 0x202c303731662509,0x25202c3533316625,0x6d090a3b39363166,0x09203233622e766f\n"
".quad 0x25202c3137316625,0x6d66090a3b383672,0x3233662e6e722e61,0x2c32373166250920\n"
".quad 0x202c313731662520,0x25202c3134316625,0x6d090a3b30373166,0x09203233622e766f\n"
".quad 0x25202c3337316625,0x6d66090a3b333772,0x3233662e6e722e61,0x2c34373166250920\n"
".quad 0x202c333731662520,0x25202c3834316625,0x6d090a3b32373166,0x09203233622e766f\n"
".quad 0x25202c3537316625,0x6d66090a3b383772,0x3233662e6e722e61,0x2c36373166250920\n"
".quad 0x202c353731662520,0x25202c3235316625,0x6d090a3b34373166,0x09203233622e766f\n"
".quad 0x25202c3737316625,0x756d090a3b333872,0x2509203233662e6c,0x6625202c38373166\n"
".quad 0x316625202c353331,0x766f6d090a3b3737,0x662509203233622e,0x387225202c393731\n"
".quad 0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3038316625,0x6625202c39373166\n"
".quad 0x316625202c313431,0x766f6d090a3b3837,0x662509203233622e,0x397225202c313831\n"
".quad 0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3238316625,0x6625202c31383166\n"
".quad 0x316625202c383431,0x766f6d090a3b3038,0x662509203233622e,0x397225202c333831\n"
".quad 0x2e616d66090a3b38,0x09203233662e6e72,0x25202c3438316625,0x6625202c33383166\n"
".quad 0x316625202c323531,0x6f6c2e090a3b3238,0x3639310936310963,0x2e627573090a3009\n"
".quad 0x3166250920323366,0x37316625202c3538,0x0a3b39316625202c,0x3233662e766f6d09\n"
".quad 0x2c36383166250920,0x3030306662663020,0x092020203b303030,0x0a352e302d202f2f\n"
".quad 0x3233662e766f6d09,0x2c37383166250920,0x3030386633663020,0x092020203b303030\n"
".quad 0x6f6d090a31202f2f,0x2509203233662e76,0x6630202c38383166,0x3030303030306633\n"
".quad 0x202f2f092020203b,0x6c756d090a352e30,0x662509203233662e,0x316625202c393831\n"
".quad 0x38316625202c3838,0x2e627573090a3b35,0x3166250920323366,0x38316625202c3039\n"
".quad 0x3938316625202c37,0x722e616d66090a3b,0x2509203233662e6e,0x6625202c31393166\n"
".quad 0x316625202c353831,0x38316625202c3039,0x2e6c756d090a3b36,0x3166250920323366\n"
".quad 0x38316625202c3239,0x3139316625202c35,0x09636f6c2e090a3b,0x3009333032093631\n"
".quad 0x33662e6c756d090a,0x3339316625092032,0x2c3538316625202c,0x0a3b353831662520\n"
".quad 0x3233662e766f6d09,0x2c34393166250920,0x3030386633663020,0x092020203b303030\n"
".quad 0x6f6d090a31202f2f,0x2509203233662e76,0x6630202c35393166,0x3030303030323063\n"
".quad 0x202f2f092020203b,0x6f6d090a352e322d,0x2509203233662e76,0x6630202c36393166\n"
".quad 0x3030303030636633,0x202f2f092020203b,0x616d66090a352e31,0x203233662e6e722e\n"
".quad 0x202c373931662509,0x25202c3639316625,0x6625202c35383166,0x6d66090a3b353931\n"
".quad 0x3233662e6e722e61,0x2c38393166250920,0x202c373931662520,0x25202c3339316625\n"
".quad 0x2e090a3b34393166,0x3209363109636f6c,0x6f6d090a30093031,0x2509203233662e76\n"
".quad 0x6630202c39393166,0x3030303030306633,0x202f2f092020203b,0x766f6d090a352e30\n"
".quad 0x662509203233662e,0x346630202c303032,0x3b30303030303030,0x32202f2f09202020\n"
".quad 0x33662e766f6d090a,0x3130326625092032,0x306366336630202c,0x2020203b30303030\n"
".quad 0x0a352e31202f2f09,0x3233662e6c756d09,0x2c32303266250920,0x202c313032662520\n"
".quad 0x090a3b3538316625,0x203233662e627573,0x202c333032662509,0x25202c3030326625\n"
".quad 0x66090a3b32303266,0x33662e6e722e616d,0x3430326625092032,0x2c3538316625202c\n"
".quad 0x202c333032662520,0x090a3b3939316625,0x203233662e6c756d,0x202c353032662509\n"
".quad 0x25202c3538316625,0x2e090a3b34303266,0x3209363109636f6c,0x6f6d090a30093731\n"
".quad 0x2509203233662e76,0x6630202c36303266,0x3030303030306662,0x202f2f092020203b\n"
".quad 0x6f6d090a352e302d,0x2509203233662e76,0x6630202c37303266,0x3030303030306633\n"
".quad 0x202f2f092020203b,0x616d66090a352e30,0x203233662e6e722e,0x202c383032662509\n"
".quad 0x25202c3730326625,0x6625202c35383166,0x756d090a3b363032,0x2509203233662e6c\n"
".quad 0x6625202c39303266,0x326625202c333931,0x6f6c2e090a3b3830,0x3532330936310963\n"
".quad 0x2e6c756d090a3009,0x3266250920323366,0x39316625202c3031,0x3036316625202c32\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x6625202c31313266,0x316625202c383631\n"
".quad 0x31326625202c3839,0x326c756d090a3b30,0x3233752e6f6c2e34,0x202c393972250920\n"
".quad 0x7225202c30317225,0x616d66090a3b3131,0x203233662e6e722e,0x202c323132662509\n"
".quad 0x25202c3637316625,0x6625202c35303266,0x6d66090a3b313132,0x3233662e6e722e61\n"
".quad 0x2c33313266250920,0x202c343831662520,0x25202c3930326625,0x6d090a3b32313266\n"
".quad 0x09203233662e766f,0x30202c3431326625,0x3030306637333466,0x2f2f092020203b30\n"
".quad 0x756d090a35353220,0x2509203233662e6c,0x6625202c35313266,0x326625202c333132\n"
".quad 0x747663090a3b3431,0x3233752e697a722e,0x722509203233662e,0x326625202c303031\n"
".quad 0x2e646c090a3b3531,0x36752e6d61726170,0x2c31647225092034,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x65646e65725f6434,0x506d6f5274614372,0x6a34726168637536\n"
".quad 0x645f66666666666a,0x5d74757074756f5f,0x752e646461090a3b,0x3031722509203233\n"
".quad 0x202c387225202c31,0x63090a3b39397225,0x752e3436752e7476,0x3264722509203233\n"
".quad 0x3b3130317225202c,0x69772e6c756d090a,0x09203233752e6564,0x7225202c33647225\n"
".quad 0x0a3b34202c313031,0x3436752e64646109,0x202c346472250920,0x7225202c31647225\n"
".quad 0x766f6d090a3b3364,0x722509203233732e,0x317225202c323031,0x766f6d090a3b3030\n"
".quad 0x722509203233752e,0x0a3b30202c333031,0x626f6c672e747309,0x38752e34762e6c61\n"
".quad 0x2b346472255b0920,0x3172257b202c5d30,0x32303172252c3230,0x252c32303172252c\n"
".quad 0x240a3b7d33303172,0x32315f37315f744c,0x6f6c2e090a3a3238,0x3732330936310963\n"
".quad 0x74697865090a3009,0x6e6557444c240a3b,0x5f6434315a5f5f64,0x61437265646e6572\n"
".quad 0x637536506d6f5274,0x66666a6a34726168,0x207d090a3a666666,0x6434315a5f202f2f\n"
".quad 0x437265646e65725f,0x7536506d6f527461,0x666a6a3472616863,0x00000a0a66666666\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[5964];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_20$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x00000000000020d8,0x0000000000000040,0x0038004000140114,0x0001001400400005\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000540\n"
".quad 0x00000000000002e1,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000821\n"
".quad 0x00000000000000a3,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x00000000000008c4\n"
".quad 0x00000000000002a0,0x0000001600000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000144,0x0000000000000006,0x0000000000000000,0x0000000000000b64\n"
".quad 0x0000000000000150,0x0800000d00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001ea,0x0000000000000002,0x0000000000000000,0x0000000000000cb4\n"
".quad 0x0000000000000044,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000165,0x0000000000000002,0x0000000000000000,0x0000000000000cf8\n"
".quad 0x00000000000000cc,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000001000000ef,0x0000000000000006,0x0000000000000000,0x0000000000000dc4\n"
".quad 0x0000000000000420,0x1800000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000002b0,0x0000000000000002,0x0000000000000000,0x00000000000011e4\n"
".quad 0x0000000000000044,0x0000000700000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000027e,0x0000000000000002,0x0000000000000000,0x0000000000001228\n"
".quad 0x0000000000000010,0x0000000700000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000118,0x0000000000000002,0x0000000000000000,0x0000000000001238\n"
".quad 0x00000000000000cc,0x0000000700000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000092,0x0000000000000006,0x0000000000000000,0x0000000000001304\n"
".quad 0x0000000000000708,0x1900000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000249,0x0000000000000002,0x0000000000000000,0x0000000000001a0c\n"
".quad 0x0000000000000044,0x0000000b00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000213,0x0000000000000002,0x0000000000000000,0x0000000000001a50\n"
".quad 0x0000000000000010,0x0000000b00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000bf,0x0000000000000002,0x0000000000000000,0x0000000000001a60\n"
".quad 0x00000000000000cc,0x0000000b00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x0000000000001b2c\n"
".quad 0x0000000000000400,0x1900000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001ba,0x0000000000000002,0x0000000000000000,0x0000000000001f2c\n"
".quad 0x0000000000000044,0x0000000f00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000189,0x0000000000000002,0x0000000000000000,0x0000000000001f70\n"
".quad 0x0000000000000010,0x0000000f00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000005e,0x0000000000000002,0x0000000000000000,0x0000000000001f80\n"
".quad 0x00000000000000cc,0x0000000f00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000089,0x0000000000000002,0x0000000000000000,0x000000000000204c\n"
".quad 0x000000000000008c,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x34315a5f2e747865\n"
".quad 0x7265646e65725f64,0x36506d6f52746143,0x6a6a347261686375,0x6e2e006666666666\n"
".quad 0x5f2e6f666e692e76,0x6e65725f6434315a,0x6f52746143726564,0x726168637536506d\n"
".quad 0x66666666666a6a34,0x666e692e766e2e00,0x2e747865742e006f,0x65725f6439315a5f\n"
".quad 0x747361467265646e,0x5063696275636942,0x6a34726168637536,0x2e0066666666666a\n"
".quad 0x2e6f666e692e766e,0x65725f6439315a5f,0x747361467265646e,0x5063696275636942\n"
".quad 0x6a34726168637536,0x2e0066666666666a,0x315a5f2e74786574,0x65646e65725f6435\n"
".quad 0x6369627563694272,0x3472616863753650,0x0066666666666a6a,0x6f666e692e766e2e\n"
".quad 0x725f6435315a5f2e,0x6369427265646e65,0x6375365063696275,0x66666a6a34726168\n"
".quad 0x7865742e00666666,0x725f64385a5f2e74,0x7536507265646e65,0x666a6a3472616863\n"
".quad 0x766e2e0066666666,0x5a5f2e6f666e692e,0x65646e65725f6438,0x7261686375365072\n"
".quad 0x66666666666a6a34,0x6e6f632e766e2e00,0x2e3631746e617473,0x65725f6434315a5f\n"
".quad 0x527461437265646e,0x6168637536506d6f,0x666666666a6a3472,0x6f632e766e2e0066\n"
".quad 0x2e30746e6174736e,0x65725f6434315a5f,0x527461437265646e,0x6168637536506d6f\n"
".quad 0x666666666a6a3472,0x6f632e766e2e0066,0x2e30746e6174736e,0x6e65725f64385a5f\n"
".quad 0x6863753650726564,0x6666666a6a347261,0x632e766e2e006666,0x31746e6174736e6f\n"
".quad 0x5f6439315a5f2e36,0x61467265646e6572,0x6962756369427473,0x7261686375365063\n"
".quad 0x66666666666a6a34,0x6e6f632e766e2e00,0x5f2e30746e617473,0x6e65725f6439315a\n"
".quad 0x4274736146726564,0x3650636962756369,0x6a6a347261686375,0x6e2e006666666666\n"
".quad 0x6174736e6f632e76,0x315a5f2e3631746e,0x65646e65725f6435,0x6369627563694272\n"
".quad 0x3472616863753650,0x0066666666666a6a,0x736e6f632e766e2e,0x5a5f2e30746e6174\n"
".quad 0x646e65725f643531,0x6962756369427265,0x7261686375365063,0x66666666666a6a34\n"
".quad 0x5f6434315a5f0000,0x61437265646e6572,0x637536506d6f5274,0x66666a6a34726168\n"
".quad 0x39315a5f00666666,0x7265646e65725f64,0x7563694274736146,0x6863753650636962\n"
".quad 0x6666666a6a347261,0x6475635f5f006666,0x645f30326d735f61,0x33665f6e725f7669\n"
".quad 0x5f6435315a5f0032,0x69427265646e6572,0x7536506369627563,0x666a6a3472616863\n"
".quad 0x385a5f0066666666,0x7265646e65725f64,0x3472616863753650,0x0066666666666a6a\n"
".quad 0x0000000000786574,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000010003,0x0000000000000000,0x0000000000000000,0x0000000000020003\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000030003,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000003,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000003,0x0000000000000000,0x0000000000000000,0x00000000000f0003\n"
".quad 0x0000040000000000,0x0000000000000000,0x0000000000120003,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000130003,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000b0003,0x0000070800000000,0x0000000000000000,0x00000000000e0003\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000070003,0x0000042000000000\n"
".quad 0x0000000000000000,0x00000000000a0003,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000040003,0x0000015000000000,0x0000000000000000,0x0000000000060003\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000110003,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000100003,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000050003,0x0000000000000000,0x0000000000000000,0x00000000000d0003\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000000000c0003,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000090003,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000080003,0x0000000000000000,0x0000000100000000,0x00000000000f1012\n"
".quad 0x0000040000000000,0x0000002300000000,0x00000000000b1012,0x0000039800000000\n"
".quad 0x0000004a00000000,0x00000398000b0012,0x0000037000000000,0x0000006100000000\n"
".quad 0x0000000000071012,0x0000042000000000,0x0000008400000000,0x0000000000041012\n"
".quad 0x0000015000000000,0x0000009f00000000,0x000000000000001a,0x0000000000000000\n"
".quad 0x00005de400000000,0x94001c0428004404,0x20009de42c000000,0x84015c0428004000\n"
".quad 0x9800dc042c000000,0x30011de42c000000,0x00001c0328004000,0x00209c037000c060\n"
".quad 0x88019c047000c060,0x0030dc032c000000,0x00411c037000c060,0x08001c037000c060\n"
".quad 0x10309c03200a0000,0xa001dc03200c0000,0xb021dc03188e4000,0x000021e718804000\n"
".quad 0x0120dc0480000000,0x09211c0418000000,0xe0015de418000000,0xf030dd0028004000\n"
".quad 0x00411d0050004000,0xf050dc0050004001,0x00515c0030068000,0xc0311c0030088001\n"
".quad 0xd0515c0050004000,0xfc40dc8650004000,0xa0015de480104000,0x00209c0328004000\n"
".quad 0x80019de47000c060,0xc030dc0028004000,0x0d211c045800d0df,0x0050dc0314060000\n"
".quad 0x11015c047000c060,0x0c201c031c000000,0x20409c0320000000,0x10019c03280ac020\n"
".quad 0x10001c43200dc000,0x40409c035000c000,0x9001dc432804c020,0x63f01c0348004000\n"
".quad 0x00601c852804c020,0x00001de794000000,0x0000000080000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000200c04\n"
".quad 0x0000000c00000008,0x0000001400000010,0x0000001c00000018,0x0008020400000020\n"
".quad 0x000000000000001b,0x0000001100080a04,0x0024190300240020,0xffffffff000c1704\n"
".quad 0x0011f00000200007,0xffffffff000c1704,0x0011f000001c0006,0xffffffff000c1704\n"
".quad 0x0011f00000180005,0xffffffff000c1704,0x0011f00000140004,0xffffffff000c1704\n"
".quad 0x0011f00000100003,0xffffffff000c1704,0x0011f000000c0002,0xffffffff000c1704\n"
".quad 0x0011f00000080001,0xffffffff000c1704,0x0021f00000000000,0x0001000c00080d04\n"
".quad 0x00005de400000001,0x94001c0428004404,0x20009de42c000000,0x84015c0428004000\n"
".quad 0x9800dc042c000000,0x30011de42c000000,0x00001c0328004000,0x00209c037000c060\n"
".quad 0x88019c047000c060,0x0030dc032c000000,0x00411c037000c060,0x08001c037000c060\n"
".quad 0x10331c03200a0000,0xa001dc03200c0000,0xb0c1dc03188e4000,0x000021e718804000\n"
".quad 0x3120dc0480000000,0x01209c0418000000,0xe0011de418000000,0x0030dd0028004000\n"
".quad 0xf0209d0050004001,0x0040dc0050004000,0xf0409c0030068001,0xd030dc0030048000\n"
".quad 0xc0209c0050004000,0x00335c0050004000,0x00239c005000efc0,0x3520dc845000efc0\n"
".quad 0x39209c8410020000,0x00325c0010020000,0x08021de45000efe0,0xfc82dc8628000000\n"
".quad 0x00211c0080104000,0x24015de45000cfe0,0xfc41dc8628000000,0x00221c0080104000\n"
".quad 0xfc83dc865000efe0,0x00219c0080104000,0x24045de45000d000,0x18041de428000000\n"
".quad 0xfd029c8628000000,0x0c025de480104000,0xfc845c8628000000,0xfc225c8680104000\n"
".quad 0x0c015de480104000,0xfc415c8628000000,0x08e49d0080104000,0x00051de250000000\n"
".quad 0x01239e001b010000,0x25441e005000d010,0x4924dc0030248000,0x05239c0058000000\n"
".quad 0x01255d00301c8000,0x35041c003028f010,0x15239c0030268000,0x55255d00301c8000\n"
".quad 0xad041c0230280000,0xace39c0230f8aaaa,0x3ce59c0030f8aaaa,0x1523dc0058000000\n"
".quad 0x40b55c00302a8000,0xacf3dc02302c0000,0x4d22dc0030f8aaaa,0x3c749c0058000000\n"
".quad 0x0c01dde4302a0000,0x44e4dc0028000000,0xacb45c0258000000,0x44a49c0030f8aaaa\n"
".quad 0x40925c0030240000,0x3c54dc0030260000,0xfc655c8630120000,0x00315c0080104000\n"
".quad 0x14025de45000cfe0,0xfc859c8628000000,0x08029de480104000,0x1402dde428000000\n"
".quad 0xfca29c8628000000,0x1401dde480104000,0xfc62dc8628000000,0x0031dc0080104000\n"
".quad 0x1c025de45000d000,0xfc85dc8628000000,0x08021de480104000,0xfc809c8628000000\n"
".quad 0xfc421c8680104000,0x1c015de480104000,0xfc411c8628000000,0xfc615c8680104000\n"
".quad 0x58e1dc0080104000,0x0cd0dd0058000000,0x45519c0050000000,0x40a35c0030260000\n"
".quad 0x00329e00300e0000,0x0034dd005000d010,0x25425e003028f010,0x28329c0030068000\n"
".quad 0x0c31dc0030280000,0x4c34dd0058000000,0x14329c0030280000,0xaca29c0230148000\n"
".quad 0x48a29c0030f8aaaa,0x3c821c0058000000,0x34935c00301a0000,0x14325c00300e8000\n"
".quad 0x1c30dc0030268000,0x5ce1dc0058000000,0xacd35c0258000000,0xac925c0230f8aaaa\n"
".quad 0x4021dc0030f8aaaa,0x34619c00300e0000,0x44b09c0030140000,0xac30dc0230100000\n"
".quad 0x3c411c0030f8aaaa,0x24219c00300e0000,0x44509c00300c0000,0xa0015de430080000\n"
".quad 0x0c209c0028004000,0x80019de4300c0000,0xc020dc0028004000,0x00c09c035800d0df\n"
".quad 0x0d211c047000c060,0x0050dc0314060000,0x11015c047000c060,0x0c201c031c000000\n"
".quad 0x20409c0320000000,0x10019c03280ac020,0x10001c43200dc000,0x40409c035000c000\n"
".quad 0x9001dc432804c020,0x63f01c0348004000,0x00601c852804c020,0x00001de794000000\n"
".quad 0x0000000080000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x3f800000c0400000,0x40800000c0c00000,0x0000000000200c04\n"
".quad 0x0000000c00000008,0x0000001400000010,0x0000001c00000018,0x0008020400000020\n"
".quad 0x000000000000001b,0x0000001500080a04,0x0024190300240020,0xffffffff000c1704\n"
".quad 0x0011f00000200007,0xffffffff000c1704,0x0011f000001c0006,0xffffffff000c1704\n"
".quad 0x0011f00000180005,0xffffffff000c1704,0x0011f00000140004,0xffffffff000c1704\n"
".quad 0x0011f00000100003,0xffffffff000c1704,0x0011f000000c0002,0xffffffff000c1704\n"
".quad 0x0011f00000080001,0xffffffff000c1704,0x0021f00000000000,0x0001000c00080d04\n"
".quad 0x00005de400000001,0x94001c0428004404,0x20009de42c000000,0x84015c0428004000\n"
".quad 0x9800dc042c000000,0x30011de42c000000,0x00001c0328004000,0x00209c037000c060\n"
".quad 0x88019c047000c060,0x0030dc032c000000,0x00411c037000c060,0x0804dc037000c060\n"
".quad 0x10351c03200a0000,0xa131dc03200c0000,0xb141dc03188e4000,0x000021e718804000\n"
".quad 0x4d201c0480000000,0xe0009de418000000,0x00019de228004000,0xf0001d0019010000\n"
".quad 0xf0201c0050004000,0xc0001c0030008000,0x00001c0050004000,0x01245c845000efc0\n"
".quad 0x44001d0010020000,0x00009e0050000000,0x00015c005000d010,0x0460dc00300cf010\n"
".quad 0x00011c0030008000,0x08009d0058000000,0x14019c00300c0000,0x14315c00300c0000\n"
".quad 0x1001dc0030088000,0x2400dc0058000000,0xac511c0230048000,0x24001c0030f8aaaa\n"
".quad 0xac709c02300c8000,0x34355c0030f8aaaa,0x34049c0030084000,0x54015de430044000\n"
".quad 0x4001000728000000,0x00401c0050000009,0x48015de45000efe0,0x08011de428000000\n"
".quad 0x0005dc0028000000,0xa00100075000cfc0,0x51201c0450000008,0xe0009de418000000\n"
".quad 0x0001dde228004000,0x00001d0019010000,0x00201c0050004001,0x00409c0030008001\n"
".quad 0xd0001c005000cfe0,0x00241c0050004000,0x00001c005000cfc0,0x0120dc845000efc0\n"
".quad 0x0c001d0010020000,0x00011e0050000000,0x04709c005000d010,0x00015c0030008000\n"
".quad 0x00019c0058000000,0x10011d00300ef010,0x14209c00300e0000,0x1801dc00300a8000\n"
".quad 0x24019c00300e0000,0xac211c0230088000,0x14009c0030f8aaaa,0x24001c0058000000\n"
".quad 0x34659c00300e8000,0xac209c0230084000,0xac061c0230f8aaaa,0x58015de430f8aaaa\n"
".quad 0x4001000728000000,0x00401c0050000005,0x45719c005000efe0,0x00001c0050000000\n"
".quad 0x0031dc005000cfc0,0xfc65dc8650000000,0x45041c0080104000,0x1c045de450000000\n"
".quad 0xfd045c8628000000,0x09861c0080104000,0x08011de450000000,0x18009de428000000\n"
".quad 0x60015de428000000,0xa001000728000000,0x00401c0050000003,0x40011de45000cfe0\n"
".quad 0x00001c0028000000,0x0030dc005000cfc0,0x0c015de450000000,0xfc411c8628000000\n"
".quad 0xfc201c8680104000,0x49109c0080104000,0x80015de458000000,0x5570dc0028004000\n"
".quad 0x5830dc0030040000,0x48409c0058000000,0xa0011de458000000,0x54001c0028004000\n"
".quad 0x01801c0030040000,0xc0009c0030060000,0x01401c035800d0df,0x0920dc047000c060\n"
".quad 0x00409c0314060000,0x0d011c047000c060,0x08001c031c000000,0x20309c0320260000\n"
".quad 0x10011c032808c020,0x10001c43200bc000,0x40309c035000c000,0x90015c432804c020\n"
".quad 0x63f01c0348004000,0x00401c852804c020,0x00001de794000000,0x04401c0380000000\n"
".quad 0x04519c036000c000,0x60001c036000c000,0x60619c035800c000,0xfc001c035800c000\n"
".quad 0xfc619c034800ffff,0xf401dc034800ffff,0xf461dc031a0ec003,0x200021e71a20c003\n"
".quad 0x0041dc8040000005,0x1121dc44298edfe0,0x600021e710800000,0x0051dc8040000000\n"
".quad 0x15221c44298edfe0,0x400001e710800000,0x14411c2040000000,0x80001de750000000\n"
".quad 0x04425c034000000b,0x04529c036000c000,0xfc93dc036000c000,0xfca5dc03190e0000\n"
".quad 0x0811dc04190e0000,0x800001e70c0e0000,0x0077dc0040000000,0x0081dc00290edfe0\n"
".quad 0x80002de7290edfe0,0x600021e740000000,0x00001de240000000,0x14011c001bff0000\n"
".quad 0xe0001de7c8000000,0x4401dc0440000009,0x600021e70c0e0000,0x10501c8340000000\n"
".quad 0x00011c0268000000,0x40001de73a000000,0x4831dc0440000009,0x800021e70c0e0000\n"
".quad 0x10501c8340000000,0x00001c0268000000,0x00011c423a000000,0x80001de739fe0000\n"
".quad 0xfc01dc2340000008,0xfc63dc231b0e0000,0x0001e1e21b0e0000,0x004120001bffffff\n"
".quad 0xfc01c1e4307ed7e0,0x800005e728000000,0x00515c0040000000,0x0071dc03307ed7e0\n"
".quad 0x20001de74800c001,0xfc01dde440000000,0x08625c0328000000,0x08021c034800fffe\n"
".quad 0x18001d034800fffe,0x14915ee348000000,0x10811ee341000000,0x10521c0041000000\n"
".quad 0x20425c00c8000000,0x24529e00307e0000,0x20a25c0030080000,0x24515e0030120000\n"
".quad 0x20511c0030080000,0x04429c0330120000,0x60a19c036000c000,0x18001c035800c000\n"
".quad 0x0071dc0348000000,0xfc701c0348000000,0xf401dc034800ffff,0x600001e71a0ec003\n"
".quad 0x18701d0340000000,0x10011ee348000000,0xa0001de740000000,0xf871dc2340000004\n"
".quad 0x600001e7198ec003,0x00401c0240000000,0x00011c423a000000,0x00001de739fe0000\n"
".quad 0xfc71dc2340000004,0xc00001e71a0e0000,0xa071dc2340000003,0x400001e71b0effff\n"
".quad 0x00411c0240000000,0x40001de73a000000,0x20529c0040000003,0x20519c0031120000\n"
".quad 0x20515c0030920000,0x1d225f8431920000,0x00401c021c000000,0x18a11c003a000000\n"
".quad 0xfc515c021e8e0000,0xfc91dc233801ffff,0x1d221f84190e0000,0x11211f841c000000\n"
".quad 0x00525c421c000000,0xa00081e738020000,0x8071600340000000,0x149160034800c000\n"
".quad 0x2092600360000000,0x07f1600358000000,0x14412043310ac000,0x78915c0368000000\n"
".quad 0x7c519c036000c000,0x04915c035800c000,0x18411c436800c000,0x10511c0368000000\n"
".quad 0x04915c0368000000,0xfc41dc035800c000,0x045140031a8e0000,0x14011c434800c000\n"
".quad 0x00001de768000000,0x0000000090000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x40800000c0c00000,0x3e2aaaab3f800000\n"
".quad 0x0000000000200c04,0x0000000c00000008,0x0000001400000010,0x0000001c00000018\n"
".quad 0x0008020400000020,0x000000000000001b,0x0000001300080a04,0x0024190300240020\n"
".quad 0xffffffff000c1704,0x0011f00000200007,0xffffffff000c1704,0x0011f000001c0006\n"
".quad 0xffffffff000c1704,0x0011f00000180005,0xffffffff000c1704,0x0011f00000140004\n"
".quad 0xffffffff000c1704,0x0011f00000100003,0xffffffff000c1704,0x0011f000000c0002\n"
".quad 0xffffffff000c1704,0x0011f00000080001,0xffffffff000c1704,0x0021f00000000000\n"
".quad 0x000f00b400080d04,0x00005de40000000d,0x94001c0428004404,0x20009de42c000000\n"
".quad 0x84015c0428004000,0x9800dc042c000000,0x30011de42c000000,0x00001c0328004000\n"
".quad 0x00209c037000c060,0x88019c047000c060,0x0030dc032c000000,0x00411c037000c060\n"
".quad 0x08001c037000c060,0x10331c03200a0000,0xa001dc03200c0000,0xb0c1dc03188e4000\n"
".quad 0x000021e718804000,0x3120dc0480000000,0x01209c0418000000,0xe0011de418000000\n"
".quad 0x0030dd0028004000,0xf0209d0050004001,0x0040dc0050004000,0xf0409c0030068001\n"
".quad 0xd030dc0030048000,0xc0209c0050004000,0x00335c0050004000,0x00239c005000efc0\n"
".quad 0x3520dc845000efc0,0x39209c8410020000,0x00325c0010020000,0x08021de45000efe0\n"
".quad 0xfc849c8628000000,0x00211c0080104000,0x24015de45000cfe0,0xfc41dc8628000000\n"
".quad 0x00221c0080104000,0xfc845c865000efe0,0x00219c0080104000,0x2402dde45000d000\n"
".quad 0x18029de428000000,0xfca15c8628000000,0x0c025de480104000,0xfc84dc8628000000\n"
".quad 0xfc225c8680104000,0x0c02dde480104000,0x10029de428000000,0xfca29c8628000000\n"
".quad 0x00051de280104000,0x08e2dd0018fc0000,0x00055de250000000,0x15439e0018ff0000\n"
".quad 0x35541e0030168000,0x2553dc0030168000,0x38b39d0030168000,0x2cb59c0030280000\n"
".quad 0x40b5dc0058000000,0x38b39c0030280000,0x14f41c0058000000,0x5cb3dc00302c8000\n"
".quad 0x00b2dd0058000000,0x44e45c003028cfc0,0x41249c0058000000,0x2d645c0030220000\n"
".quad 0x3c72dc0058000000,0x0c01dde430240000,0x44549c0028000000,0x4ce4dc0030160000\n"
".quad 0x40925c0058000000,0x3ca4dc0030260000,0xfc659c8630120000,0x00315c0080104000\n"
".quad 0x14025de45000cfe0,0xfc85dc8628000000,0x08029de480104000,0x1402dde428000000\n"
".quad 0xfca29c8628000000,0x1401dde480104000,0xfc62dc8628000000,0x0031dc0080104000\n"
".quad 0x1c025de45000d000,0xfc861c8628000000,0x08021de480104000,0xfc809c8628000000\n"
".quad 0xfc421c8680104000,0x1c015de480104000,0xfc411c8628000000,0xfc615c8680104000\n"
".quad 0x0cd0dd0080104000,0x5ce1dc0050000000,0x45619c0058000000,0x15425e0030260000\n"
".quad 0x40a1dc0030068000,0x35535e00300e0000,0x2434dd0030068000,0x25529c0030280000\n"
".quad 0x34335c0030068000,0x4c34dc0030280000,0x00325d0058000000,0x34335c003028cfc0\n"
".quad 0x49349c0058000000,0x60e39c0058000000,0x3c81dc0058000000,0x0c321c00300e0000\n"
".quad 0x4020dc0058000000,0x44b09c00301c0000,0x14a29c00300e0000,0x28619c0030108000\n"
".quad 0x34219c0030240000,0x3c40dc00300c0000,0x24811c0030060000,0x44509c0058000000\n"
".quad 0xa0015de430060000,0x10209c0028004000,0x80019de4300c0000,0xc020dc0028004000\n"
".quad 0x00c09c035800d0df,0x0d211c047000c060,0x0050dc0314060000,0x11015c047000c060\n"
".quad 0x0c201c031c000000,0x20409c0320000000,0x10019c03280ac020,0x10001c43200dc000\n"
".quad 0x40409c035000c000,0x9001dc432804c020,0x63f01c0348004000,0x00601c852804c020\n"
".quad 0x00001de794000000,0x0000000080000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x3f80000000000001,0x40000000c0200000\n"
".quad 0x0000000000200c04,0x0000000c00000008,0x0000001400000010,0x0000001c00000018\n"
".quad 0x0008020400000020,0x000000000000001b,0x0000001000080a04,0x0024190300240020\n"
".quad 0xffffffff000c1704,0x0011f00000200007,0xffffffff000c1704,0x0011f000001c0006\n"
".quad 0xffffffff000c1704,0x0011f00000180005,0xffffffff000c1704,0x0011f00000140004\n"
".quad 0xffffffff000c1704,0x0011f00000100003,0xffffffff000c1704,0x0011f000000c0002\n"
".quad 0xffffffff000c1704,0x0011f00000080001,0xffffffff000c1704,0x0021f00000000000\n"
".quad 0x0001000c00080d04,0x0010070400000001,0xffffffff0000001b,0xffffffffffffffff\n"
".quad 0x0000001a00081204,0x0008110400000000,0x000000000000001a,0x0000001900081204\n"
".quad 0x0008110400000000,0x0000000000000019,0x0000001800081204,0x0008110400000000\n"
".quad 0x0000000000000018,0x0000001700081204,0x0008110400000000,0x0000000000000017\n"
".quad 0x0000001600081204,0x0008110400000000,0x0000000000000016,0x0000000500000006\n"
".quad 0x00000000000020d8,0x0000000000000000,0x0000000000000000,0x0000000000000118\n"
".quad 0x0000000000000118,0x0000000000000004,0x00001a0560000000,0x0000000000000b64\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000260,0x0000000000000260\n"
".quad 0x0000000000000004,0x0000190560000000,0x0000000000000dc4,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000540,0x0000000000000540,0x0000000000000004\n"
".quad 0x0000170560000000,0x0000000000001304,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000828,0x0000000000000828,0x0000000000000004,0x0000160560000000\n"
".quad 0x0000000000001b2c,0x0000000000000000,0x0000000000000000,0x0000000000000520\n"
".quad 0x0000000000000520,0x0000000000000004,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_20$[1087];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_20", (char*)__deviceText_$sm_20$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_20$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"d8e3085ca35f2362",(char*)"/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xe5bb8e61,&__elfEntries1};
# 3 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T21 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T22 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T23 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
extern void __device_stub__Z8d_renderP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);
extern void __device_stub__Z15d_renderBicubicP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);
extern void __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);
extern void __device_stub__Z14d_renderCatRomP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);
static void __sti____cudaRegisterAll_49_tmpxft_00007c90_00000000_4_bicubicTexture_cpp1_ii_tex(void) __attribute__((__constructor__));
void __device_stub__Z8d_renderP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){ struct __T20 *__T24 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T24->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T24->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T24->__par7) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render))); };}
void d_render( uchar4 *__cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
# 258 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{__device_stub__Z8d_renderP6uchar4jjfffff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 273 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c"
void __device_stub__Z15d_renderBicubicP6uchar4jjfffff( uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7) { struct __T21 *__T25 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T25->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T25->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T25->__par7) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic))); }; }
void d_renderBicubic( uchar4 *__cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
# 278 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{__device_stub__Z15d_renderBicubicP6uchar4jjfffff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 291 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c"
void __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff( uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7) { struct __T22 *__T2174 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2174->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2174->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2174->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2174->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2174->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2174->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2174->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2174->__par7) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic))); }; }
void d_renderFastBicubic( uchar4 *__cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
# 296 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{__device_stub__Z19d_renderFastBicubicP6uchar4jjfffff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 309 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c"
void __device_stub__Z14d_renderCatRomP6uchar4jjfffff( uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7) { struct __T23 *__T2219 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2219->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2219->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2219->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2219->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2219->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2219->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2219->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2219->__par7) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderCatRom)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderCatRom))); }; }
void d_renderCatRom( uchar4 *__cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
# 314 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
{__device_stub__Z14d_renderCatRomP6uchar4jjfffff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 327 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/bicubicTexture/bicubicTexture_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_00007c90_00000000_4_bicubicTexture_cpp1_ii_tex(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderCatRom), (char*)"_Z14d_renderCatRomP6uchar4jjfffff", "_Z14d_renderCatRomP6uchar4jjfffff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic), (char*)"_Z19d_renderFastBicubicP6uchar4jjfffff", "_Z19d_renderFastBicubicP6uchar4jjfffff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic), (char*)"_Z15d_renderBicubicP6uchar4jjfffff", "_Z15d_renderBicubicP6uchar4jjfffff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render), (char*)"_Z8d_renderP6uchar4jjfffff", "_Z8d_renderP6uchar4jjfffff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&tex, (const void**)"tex", "tex", 2, 1, 0); }
# 1 "/tmp/tmpxft_00007c90_00000000-1_bicubicTexture.cudafe1.stub.c" 2

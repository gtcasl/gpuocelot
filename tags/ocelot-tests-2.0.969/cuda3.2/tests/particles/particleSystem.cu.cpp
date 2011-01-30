# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.cpp"
# 1 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
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
# 53 "shared/GL/gl.h"
extern "C" { typedef unsigned GLenum; }
# 54 "shared/GL/gl.h"
extern "C" { typedef unsigned char GLboolean; }
# 55 "shared/GL/gl.h"
extern "C" { typedef unsigned GLbitfield; }
# 56 "shared/GL/gl.h"
extern "C" { typedef signed char GLbyte; }
# 57 "shared/GL/gl.h"
extern "C" { typedef short GLshort; }
# 58 "shared/GL/gl.h"
extern "C" { typedef int GLint; }
# 59 "shared/GL/gl.h"
extern "C" { typedef int GLsizei; }
# 60 "shared/GL/gl.h"
extern "C" { typedef unsigned char GLubyte; }
# 61 "shared/GL/gl.h"
extern "C" { typedef unsigned short GLushort; }
# 62 "shared/GL/gl.h"
extern "C" { typedef unsigned GLuint; }
# 63 "shared/GL/gl.h"
extern "C" { typedef float GLfloat; }
# 64 "shared/GL/gl.h"
extern "C" { typedef float GLclampf; }
# 65 "shared/GL/gl.h"
extern "C" { typedef double GLdouble; }
# 66 "shared/GL/gl.h"
extern "C" { typedef double GLclampd; }
# 67 "shared/GL/gl.h"
extern "C" { typedef void GLvoid; }
# 1287 "shared/GL/gl.h"
extern "C" void glAccum(GLenum, GLfloat);
# 1288 "shared/GL/gl.h"
extern "C" void glAlphaFunc(GLenum, GLclampf);
# 1289 "shared/GL/gl.h"
extern "C" GLboolean glAreTexturesResident(GLsizei, const GLuint *, GLboolean *);
# 1290 "shared/GL/gl.h"
extern "C" void glArrayElement(GLint);
# 1291 "shared/GL/gl.h"
extern "C" void glBegin(GLenum);
# 1292 "shared/GL/gl.h"
extern "C" void glBindTexture(GLenum, GLuint);
# 1293 "shared/GL/gl.h"
extern "C" void glBitmap(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
# 1294 "shared/GL/gl.h"
extern "C" void glBlendFunc(GLenum, GLenum);
# 1295 "shared/GL/gl.h"
extern "C" void glCallList(GLuint);
# 1296 "shared/GL/gl.h"
extern "C" void glCallLists(GLsizei, GLenum, const GLvoid *);
# 1297 "shared/GL/gl.h"
extern "C" void glClear(GLbitfield);
# 1298 "shared/GL/gl.h"
extern "C" void glClearAccum(GLfloat, GLfloat, GLfloat, GLfloat);
# 1299 "shared/GL/gl.h"
extern "C" void glClearColor(GLclampf, GLclampf, GLclampf, GLclampf);
# 1300 "shared/GL/gl.h"
extern "C" void glClearDepth(GLclampd);
# 1301 "shared/GL/gl.h"
extern "C" void glClearIndex(GLfloat);
# 1302 "shared/GL/gl.h"
extern "C" void glClearStencil(GLint);
# 1303 "shared/GL/gl.h"
extern "C" void glClipPlane(GLenum, const GLdouble *);
# 1304 "shared/GL/gl.h"
extern "C" void glColor3b(GLbyte, GLbyte, GLbyte);
# 1305 "shared/GL/gl.h"
extern "C" void glColor3bv(const GLbyte *);
# 1306 "shared/GL/gl.h"
extern "C" void glColor3d(GLdouble, GLdouble, GLdouble);
# 1307 "shared/GL/gl.h"
extern "C" void glColor3dv(const GLdouble *);
# 1308 "shared/GL/gl.h"
extern "C" void glColor3f(GLfloat, GLfloat, GLfloat);
# 1309 "shared/GL/gl.h"
extern "C" void glColor3fv(const GLfloat *);
# 1310 "shared/GL/gl.h"
extern "C" void glColor3i(GLint, GLint, GLint);
# 1311 "shared/GL/gl.h"
extern "C" void glColor3iv(const GLint *);
# 1312 "shared/GL/gl.h"
extern "C" void glColor3s(GLshort, GLshort, GLshort);
# 1313 "shared/GL/gl.h"
extern "C" void glColor3sv(const GLshort *);
# 1314 "shared/GL/gl.h"
extern "C" void glColor3ub(GLubyte, GLubyte, GLubyte);
# 1315 "shared/GL/gl.h"
extern "C" void glColor3ubv(const GLubyte *);
# 1316 "shared/GL/gl.h"
extern "C" void glColor3ui(GLuint, GLuint, GLuint);
# 1317 "shared/GL/gl.h"
extern "C" void glColor3uiv(const GLuint *);
# 1318 "shared/GL/gl.h"
extern "C" void glColor3us(GLushort, GLushort, GLushort);
# 1319 "shared/GL/gl.h"
extern "C" void glColor3usv(const GLushort *);
# 1320 "shared/GL/gl.h"
extern "C" void glColor4b(GLbyte, GLbyte, GLbyte, GLbyte);
# 1321 "shared/GL/gl.h"
extern "C" void glColor4bv(const GLbyte *);
# 1322 "shared/GL/gl.h"
extern "C" void glColor4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1323 "shared/GL/gl.h"
extern "C" void glColor4dv(const GLdouble *);
# 1324 "shared/GL/gl.h"
extern "C" void glColor4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1325 "shared/GL/gl.h"
extern "C" void glColor4fv(const GLfloat *);
# 1326 "shared/GL/gl.h"
extern "C" void glColor4i(GLint, GLint, GLint, GLint);
# 1327 "shared/GL/gl.h"
extern "C" void glColor4iv(const GLint *);
# 1328 "shared/GL/gl.h"
extern "C" void glColor4s(GLshort, GLshort, GLshort, GLshort);
# 1329 "shared/GL/gl.h"
extern "C" void glColor4sv(const GLshort *);
# 1330 "shared/GL/gl.h"
extern "C" void glColor4ub(GLubyte, GLubyte, GLubyte, GLubyte);
# 1331 "shared/GL/gl.h"
extern "C" void glColor4ubv(const GLubyte *);
# 1332 "shared/GL/gl.h"
extern "C" void glColor4ui(GLuint, GLuint, GLuint, GLuint);
# 1333 "shared/GL/gl.h"
extern "C" void glColor4uiv(const GLuint *);
# 1334 "shared/GL/gl.h"
extern "C" void glColor4us(GLushort, GLushort, GLushort, GLushort);
# 1335 "shared/GL/gl.h"
extern "C" void glColor4usv(const GLushort *);
# 1336 "shared/GL/gl.h"
extern "C" void glColorMask(GLboolean, GLboolean, GLboolean, GLboolean);
# 1337 "shared/GL/gl.h"
extern "C" void glColorMaterial(GLenum, GLenum);
# 1338 "shared/GL/gl.h"
extern "C" void glColorPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 1339 "shared/GL/gl.h"
extern "C" void glCopyPixels(GLint, GLint, GLsizei, GLsizei, GLenum);
# 1340 "shared/GL/gl.h"
extern "C" void glCopyTexImage1D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
# 1341 "shared/GL/gl.h"
extern "C" void glCopyTexImage2D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
# 1342 "shared/GL/gl.h"
extern "C" void glCopyTexSubImage1D(GLenum, GLint, GLint, GLint, GLint, GLsizei);
# 1343 "shared/GL/gl.h"
extern "C" void glCopyTexSubImage2D(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
# 1344 "shared/GL/gl.h"
extern "C" void glCullFace(GLenum);
# 1345 "shared/GL/gl.h"
extern "C" void glDeleteLists(GLuint, GLsizei);
# 1346 "shared/GL/gl.h"
extern "C" void glDeleteTextures(GLsizei, const GLuint *);
# 1347 "shared/GL/gl.h"
extern "C" void glDepthFunc(GLenum);
# 1348 "shared/GL/gl.h"
extern "C" void glDepthMask(GLboolean);
# 1349 "shared/GL/gl.h"
extern "C" void glDepthRange(GLclampd, GLclampd);
# 1350 "shared/GL/gl.h"
extern "C" void glDisable(GLenum);
# 1351 "shared/GL/gl.h"
extern "C" void glDisableClientState(GLenum);
# 1352 "shared/GL/gl.h"
extern "C" void glDrawArrays(GLenum, GLint, GLsizei);
# 1353 "shared/GL/gl.h"
extern "C" void glDrawBuffer(GLenum);
# 1354 "shared/GL/gl.h"
extern "C" void glDrawElements(GLenum, GLsizei, GLenum, const GLvoid *);
# 1355 "shared/GL/gl.h"
extern "C" void glDrawPixels(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
# 1356 "shared/GL/gl.h"
extern "C" void glEdgeFlag(GLboolean);
# 1357 "shared/GL/gl.h"
extern "C" void glEdgeFlagPointer(GLsizei, const GLvoid *);
# 1358 "shared/GL/gl.h"
extern "C" void glEdgeFlagv(const GLboolean *);
# 1359 "shared/GL/gl.h"
extern "C" void glEnable(GLenum);
# 1360 "shared/GL/gl.h"
extern "C" void glEnableClientState(GLenum);
# 1361 "shared/GL/gl.h"
extern "C" void glEnd();
# 1362 "shared/GL/gl.h"
extern "C" void glEndList();
# 1363 "shared/GL/gl.h"
extern "C" void glEvalCoord1d(GLdouble);
# 1364 "shared/GL/gl.h"
extern "C" void glEvalCoord1dv(const GLdouble *);
# 1365 "shared/GL/gl.h"
extern "C" void glEvalCoord1f(GLfloat);
# 1366 "shared/GL/gl.h"
extern "C" void glEvalCoord1fv(const GLfloat *);
# 1367 "shared/GL/gl.h"
extern "C" void glEvalCoord2d(GLdouble, GLdouble);
# 1368 "shared/GL/gl.h"
extern "C" void glEvalCoord2dv(const GLdouble *);
# 1369 "shared/GL/gl.h"
extern "C" void glEvalCoord2f(GLfloat, GLfloat);
# 1370 "shared/GL/gl.h"
extern "C" void glEvalCoord2fv(const GLfloat *);
# 1371 "shared/GL/gl.h"
extern "C" void glEvalMesh1(GLenum, GLint, GLint);
# 1372 "shared/GL/gl.h"
extern "C" void glEvalMesh2(GLenum, GLint, GLint, GLint, GLint);
# 1373 "shared/GL/gl.h"
extern "C" void glEvalPoint1(GLint);
# 1374 "shared/GL/gl.h"
extern "C" void glEvalPoint2(GLint, GLint);
# 1375 "shared/GL/gl.h"
extern "C" void glFeedbackBuffer(GLsizei, GLenum, GLfloat *);
# 1376 "shared/GL/gl.h"
extern "C" void glFinish();
# 1377 "shared/GL/gl.h"
extern "C" void glFlush();
# 1378 "shared/GL/gl.h"
extern "C" void glFogf(GLenum, GLfloat);
# 1379 "shared/GL/gl.h"
extern "C" void glFogfv(GLenum, const GLfloat *);
# 1380 "shared/GL/gl.h"
extern "C" void glFogi(GLenum, GLint);
# 1381 "shared/GL/gl.h"
extern "C" void glFogiv(GLenum, const GLint *);
# 1382 "shared/GL/gl.h"
extern "C" void glFrontFace(GLenum);
# 1383 "shared/GL/gl.h"
extern "C" void glFrustum(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 1384 "shared/GL/gl.h"
extern "C" GLuint glGenLists(GLsizei);
# 1385 "shared/GL/gl.h"
extern "C" void glGenTextures(GLsizei, GLuint *);
# 1386 "shared/GL/gl.h"
extern "C" void glGetBooleanv(GLenum, GLboolean *);
# 1387 "shared/GL/gl.h"
extern "C" void glGetClipPlane(GLenum, GLdouble *);
# 1388 "shared/GL/gl.h"
extern "C" void glGetDoublev(GLenum, GLdouble *);
# 1389 "shared/GL/gl.h"
extern "C" GLenum glGetError();
# 1390 "shared/GL/gl.h"
extern "C" void glGetFloatv(GLenum, GLfloat *);
# 1391 "shared/GL/gl.h"
extern "C" void glGetIntegerv(GLenum, GLint *);
# 1392 "shared/GL/gl.h"
extern "C" void glGetLightfv(GLenum, GLenum, GLfloat *);
# 1393 "shared/GL/gl.h"
extern "C" void glGetLightiv(GLenum, GLenum, GLint *);
# 1394 "shared/GL/gl.h"
extern "C" void glGetMapdv(GLenum, GLenum, GLdouble *);
# 1395 "shared/GL/gl.h"
extern "C" void glGetMapfv(GLenum, GLenum, GLfloat *);
# 1396 "shared/GL/gl.h"
extern "C" void glGetMapiv(GLenum, GLenum, GLint *);
# 1397 "shared/GL/gl.h"
extern "C" void glGetMaterialfv(GLenum, GLenum, GLfloat *);
# 1398 "shared/GL/gl.h"
extern "C" void glGetMaterialiv(GLenum, GLenum, GLint *);
# 1399 "shared/GL/gl.h"
extern "C" void glGetPixelMapfv(GLenum, GLfloat *);
# 1400 "shared/GL/gl.h"
extern "C" void glGetPixelMapuiv(GLenum, GLuint *);
# 1401 "shared/GL/gl.h"
extern "C" void glGetPixelMapusv(GLenum, GLushort *);
# 1402 "shared/GL/gl.h"
extern "C" void glGetPointerv(GLenum, GLvoid **);
# 1403 "shared/GL/gl.h"
extern "C" void glGetPolygonStipple(GLubyte *);
# 1404 "shared/GL/gl.h"
extern "C" const GLubyte *glGetString(GLenum);
# 1405 "shared/GL/gl.h"
extern "C" void glGetTexEnvfv(GLenum, GLenum, GLfloat *);
# 1406 "shared/GL/gl.h"
extern "C" void glGetTexEnviv(GLenum, GLenum, GLint *);
# 1407 "shared/GL/gl.h"
extern "C" void glGetTexGendv(GLenum, GLenum, GLdouble *);
# 1408 "shared/GL/gl.h"
extern "C" void glGetTexGenfv(GLenum, GLenum, GLfloat *);
# 1409 "shared/GL/gl.h"
extern "C" void glGetTexGeniv(GLenum, GLenum, GLint *);
# 1410 "shared/GL/gl.h"
extern "C" void glGetTexImage(GLenum, GLint, GLenum, GLenum, GLvoid *);
# 1411 "shared/GL/gl.h"
extern "C" void glGetTexLevelParameterfv(GLenum, GLint, GLenum, GLfloat *);
# 1412 "shared/GL/gl.h"
extern "C" void glGetTexLevelParameteriv(GLenum, GLint, GLenum, GLint *);
# 1413 "shared/GL/gl.h"
extern "C" void glGetTexParameterfv(GLenum, GLenum, GLfloat *);
# 1414 "shared/GL/gl.h"
extern "C" void glGetTexParameteriv(GLenum, GLenum, GLint *);
# 1415 "shared/GL/gl.h"
extern "C" void glHint(GLenum, GLenum);
# 1416 "shared/GL/gl.h"
extern "C" void glIndexMask(GLuint);
# 1417 "shared/GL/gl.h"
extern "C" void glIndexPointer(GLenum, GLsizei, const GLvoid *);
# 1418 "shared/GL/gl.h"
extern "C" void glIndexd(GLdouble);
# 1419 "shared/GL/gl.h"
extern "C" void glIndexdv(const GLdouble *);
# 1420 "shared/GL/gl.h"
extern "C" void glIndexf(GLfloat);
# 1421 "shared/GL/gl.h"
extern "C" void glIndexfv(const GLfloat *);
# 1422 "shared/GL/gl.h"
extern "C" void glIndexi(GLint);
# 1423 "shared/GL/gl.h"
extern "C" void glIndexiv(const GLint *);
# 1424 "shared/GL/gl.h"
extern "C" void glIndexs(GLshort);
# 1425 "shared/GL/gl.h"
extern "C" void glIndexsv(const GLshort *);
# 1426 "shared/GL/gl.h"
extern "C" void glIndexub(GLubyte);
# 1427 "shared/GL/gl.h"
extern "C" void glIndexubv(const GLubyte *);
# 1428 "shared/GL/gl.h"
extern "C" void glInitNames();
# 1429 "shared/GL/gl.h"
extern "C" void glInterleavedArrays(GLenum, GLsizei, const GLvoid *);
# 1430 "shared/GL/gl.h"
extern "C" GLboolean glIsEnabled(GLenum);
# 1431 "shared/GL/gl.h"
extern "C" GLboolean glIsList(GLuint);
# 1432 "shared/GL/gl.h"
extern "C" GLboolean glIsTexture(GLuint);
# 1433 "shared/GL/gl.h"
extern "C" void glLightModelf(GLenum, GLfloat);
# 1434 "shared/GL/gl.h"
extern "C" void glLightModelfv(GLenum, const GLfloat *);
# 1435 "shared/GL/gl.h"
extern "C" void glLightModeli(GLenum, GLint);
# 1436 "shared/GL/gl.h"
extern "C" void glLightModeliv(GLenum, const GLint *);
# 1437 "shared/GL/gl.h"
extern "C" void glLightf(GLenum, GLenum, GLfloat);
# 1438 "shared/GL/gl.h"
extern "C" void glLightfv(GLenum, GLenum, const GLfloat *);
# 1439 "shared/GL/gl.h"
extern "C" void glLighti(GLenum, GLenum, GLint);
# 1440 "shared/GL/gl.h"
extern "C" void glLightiv(GLenum, GLenum, const GLint *);
# 1441 "shared/GL/gl.h"
extern "C" void glLineStipple(GLint, GLushort);
# 1442 "shared/GL/gl.h"
extern "C" void glLineWidth(GLfloat);
# 1443 "shared/GL/gl.h"
extern "C" void glListBase(GLuint);
# 1444 "shared/GL/gl.h"
extern "C" void glLoadIdentity();
# 1445 "shared/GL/gl.h"
extern "C" void glLoadMatrixd(const GLdouble *);
# 1446 "shared/GL/gl.h"
extern "C" void glLoadMatrixf(const GLfloat *);
# 1447 "shared/GL/gl.h"
extern "C" void glLoadName(GLuint);
# 1448 "shared/GL/gl.h"
extern "C" void glLogicOp(GLenum);
# 1449 "shared/GL/gl.h"
extern "C" void glMap1d(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
# 1450 "shared/GL/gl.h"
extern "C" void glMap1f(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
# 1451 "shared/GL/gl.h"
extern "C" void glMap2d(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
# 1452 "shared/GL/gl.h"
extern "C" void glMap2f(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
# 1453 "shared/GL/gl.h"
extern "C" void glMapGrid1d(GLint, GLdouble, GLdouble);
# 1454 "shared/GL/gl.h"
extern "C" void glMapGrid1f(GLint, GLfloat, GLfloat);
# 1455 "shared/GL/gl.h"
extern "C" void glMapGrid2d(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
# 1456 "shared/GL/gl.h"
extern "C" void glMapGrid2f(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
# 1457 "shared/GL/gl.h"
extern "C" void glMaterialf(GLenum, GLenum, GLfloat);
# 1458 "shared/GL/gl.h"
extern "C" void glMaterialfv(GLenum, GLenum, const GLfloat *);
# 1459 "shared/GL/gl.h"
extern "C" void glMateriali(GLenum, GLenum, GLint);
# 1460 "shared/GL/gl.h"
extern "C" void glMaterialiv(GLenum, GLenum, const GLint *);
# 1461 "shared/GL/gl.h"
extern "C" void glMatrixMode(GLenum);
# 1462 "shared/GL/gl.h"
extern "C" void glMultMatrixd(const GLdouble *);
# 1463 "shared/GL/gl.h"
extern "C" void glMultMatrixf(const GLfloat *);
# 1464 "shared/GL/gl.h"
extern "C" void glNewList(GLuint, GLenum);
# 1465 "shared/GL/gl.h"
extern "C" void glNormal3b(GLbyte, GLbyte, GLbyte);
# 1466 "shared/GL/gl.h"
extern "C" void glNormal3bv(const GLbyte *);
# 1467 "shared/GL/gl.h"
extern "C" void glNormal3d(GLdouble, GLdouble, GLdouble);
# 1468 "shared/GL/gl.h"
extern "C" void glNormal3dv(const GLdouble *);
# 1469 "shared/GL/gl.h"
extern "C" void glNormal3f(GLfloat, GLfloat, GLfloat);
# 1470 "shared/GL/gl.h"
extern "C" void glNormal3fv(const GLfloat *);
# 1471 "shared/GL/gl.h"
extern "C" void glNormal3i(GLint, GLint, GLint);
# 1472 "shared/GL/gl.h"
extern "C" void glNormal3iv(const GLint *);
# 1473 "shared/GL/gl.h"
extern "C" void glNormal3s(GLshort, GLshort, GLshort);
# 1474 "shared/GL/gl.h"
extern "C" void glNormal3sv(const GLshort *);
# 1475 "shared/GL/gl.h"
extern "C" void glNormalPointer(GLenum, GLsizei, const GLvoid *);
# 1476 "shared/GL/gl.h"
extern "C" void glOrtho(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 1477 "shared/GL/gl.h"
extern "C" void glPassThrough(GLfloat);
# 1478 "shared/GL/gl.h"
extern "C" void glPixelMapfv(GLenum, GLsizei, const GLfloat *);
# 1479 "shared/GL/gl.h"
extern "C" void glPixelMapuiv(GLenum, GLsizei, const GLuint *);
# 1480 "shared/GL/gl.h"
extern "C" void glPixelMapusv(GLenum, GLsizei, const GLushort *);
# 1481 "shared/GL/gl.h"
extern "C" void glPixelStoref(GLenum, GLfloat);
# 1482 "shared/GL/gl.h"
extern "C" void glPixelStorei(GLenum, GLint);
# 1483 "shared/GL/gl.h"
extern "C" void glPixelTransferf(GLenum, GLfloat);
# 1484 "shared/GL/gl.h"
extern "C" void glPixelTransferi(GLenum, GLint);
# 1485 "shared/GL/gl.h"
extern "C" void glPixelZoom(GLfloat, GLfloat);
# 1486 "shared/GL/gl.h"
extern "C" void glPointSize(GLfloat);
# 1487 "shared/GL/gl.h"
extern "C" void glPolygonMode(GLenum, GLenum);
# 1488 "shared/GL/gl.h"
extern "C" void glPolygonOffset(GLfloat, GLfloat);
# 1489 "shared/GL/gl.h"
extern "C" void glPolygonStipple(const GLubyte *);
# 1490 "shared/GL/gl.h"
extern "C" void glPopAttrib();
# 1491 "shared/GL/gl.h"
extern "C" void glPopClientAttrib();
# 1492 "shared/GL/gl.h"
extern "C" void glPopMatrix();
# 1493 "shared/GL/gl.h"
extern "C" void glPopName();
# 1494 "shared/GL/gl.h"
extern "C" void glPrioritizeTextures(GLsizei, const GLuint *, const GLclampf *);
# 1495 "shared/GL/gl.h"
extern "C" void glPushAttrib(GLbitfield);
# 1496 "shared/GL/gl.h"
extern "C" void glPushClientAttrib(GLbitfield);
# 1497 "shared/GL/gl.h"
extern "C" void glPushMatrix();
# 1498 "shared/GL/gl.h"
extern "C" void glPushName(GLuint);
# 1499 "shared/GL/gl.h"
extern "C" void glRasterPos2d(GLdouble, GLdouble);
# 1500 "shared/GL/gl.h"
extern "C" void glRasterPos2dv(const GLdouble *);
# 1501 "shared/GL/gl.h"
extern "C" void glRasterPos2f(GLfloat, GLfloat);
# 1502 "shared/GL/gl.h"
extern "C" void glRasterPos2fv(const GLfloat *);
# 1503 "shared/GL/gl.h"
extern "C" void glRasterPos2i(GLint, GLint);
# 1504 "shared/GL/gl.h"
extern "C" void glRasterPos2iv(const GLint *);
# 1505 "shared/GL/gl.h"
extern "C" void glRasterPos2s(GLshort, GLshort);
# 1506 "shared/GL/gl.h"
extern "C" void glRasterPos2sv(const GLshort *);
# 1507 "shared/GL/gl.h"
extern "C" void glRasterPos3d(GLdouble, GLdouble, GLdouble);
# 1508 "shared/GL/gl.h"
extern "C" void glRasterPos3dv(const GLdouble *);
# 1509 "shared/GL/gl.h"
extern "C" void glRasterPos3f(GLfloat, GLfloat, GLfloat);
# 1510 "shared/GL/gl.h"
extern "C" void glRasterPos3fv(const GLfloat *);
# 1511 "shared/GL/gl.h"
extern "C" void glRasterPos3i(GLint, GLint, GLint);
# 1512 "shared/GL/gl.h"
extern "C" void glRasterPos3iv(const GLint *);
# 1513 "shared/GL/gl.h"
extern "C" void glRasterPos3s(GLshort, GLshort, GLshort);
# 1514 "shared/GL/gl.h"
extern "C" void glRasterPos3sv(const GLshort *);
# 1515 "shared/GL/gl.h"
extern "C" void glRasterPos4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1516 "shared/GL/gl.h"
extern "C" void glRasterPos4dv(const GLdouble *);
# 1517 "shared/GL/gl.h"
extern "C" void glRasterPos4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1518 "shared/GL/gl.h"
extern "C" void glRasterPos4fv(const GLfloat *);
# 1519 "shared/GL/gl.h"
extern "C" void glRasterPos4i(GLint, GLint, GLint, GLint);
# 1520 "shared/GL/gl.h"
extern "C" void glRasterPos4iv(const GLint *);
# 1521 "shared/GL/gl.h"
extern "C" void glRasterPos4s(GLshort, GLshort, GLshort, GLshort);
# 1522 "shared/GL/gl.h"
extern "C" void glRasterPos4sv(const GLshort *);
# 1523 "shared/GL/gl.h"
extern "C" void glReadBuffer(GLenum);
# 1524 "shared/GL/gl.h"
extern "C" void glReadPixels(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
# 1525 "shared/GL/gl.h"
extern "C" void glRectd(GLdouble, GLdouble, GLdouble, GLdouble);
# 1526 "shared/GL/gl.h"
extern "C" void glRectdv(const GLdouble *, const GLdouble *);
# 1527 "shared/GL/gl.h"
extern "C" void glRectf(GLfloat, GLfloat, GLfloat, GLfloat);
# 1528 "shared/GL/gl.h"
extern "C" void glRectfv(const GLfloat *, const GLfloat *);
# 1529 "shared/GL/gl.h"
extern "C" void glRecti(GLint, GLint, GLint, GLint);
# 1530 "shared/GL/gl.h"
extern "C" void glRectiv(const GLint *, const GLint *);
# 1531 "shared/GL/gl.h"
extern "C" void glRects(GLshort, GLshort, GLshort, GLshort);
# 1532 "shared/GL/gl.h"
extern "C" void glRectsv(const GLshort *, const GLshort *);
# 1533 "shared/GL/gl.h"
extern "C" GLint glRenderMode(GLenum);
# 1534 "shared/GL/gl.h"
extern "C" void glRotated(GLdouble, GLdouble, GLdouble, GLdouble);
# 1535 "shared/GL/gl.h"
extern "C" void glRotatef(GLfloat, GLfloat, GLfloat, GLfloat);
# 1536 "shared/GL/gl.h"
extern "C" void glScaled(GLdouble, GLdouble, GLdouble);
# 1537 "shared/GL/gl.h"
extern "C" void glScalef(GLfloat, GLfloat, GLfloat);
# 1538 "shared/GL/gl.h"
extern "C" void glScissor(GLint, GLint, GLsizei, GLsizei);
# 1539 "shared/GL/gl.h"
extern "C" void glSelectBuffer(GLsizei, GLuint *);
# 1540 "shared/GL/gl.h"
extern "C" void glShadeModel(GLenum);
# 1541 "shared/GL/gl.h"
extern "C" void glStencilFunc(GLenum, GLint, GLuint);
# 1542 "shared/GL/gl.h"
extern "C" void glStencilMask(GLuint);
# 1543 "shared/GL/gl.h"
extern "C" void glStencilOp(GLenum, GLenum, GLenum);
# 1544 "shared/GL/gl.h"
extern "C" void glTexCoord1d(GLdouble);
# 1545 "shared/GL/gl.h"
extern "C" void glTexCoord1dv(const GLdouble *);
# 1546 "shared/GL/gl.h"
extern "C" void glTexCoord1f(GLfloat);
# 1547 "shared/GL/gl.h"
extern "C" void glTexCoord1fv(const GLfloat *);
# 1548 "shared/GL/gl.h"
extern "C" void glTexCoord1i(GLint);
# 1549 "shared/GL/gl.h"
extern "C" void glTexCoord1iv(const GLint *);
# 1550 "shared/GL/gl.h"
extern "C" void glTexCoord1s(GLshort);
# 1551 "shared/GL/gl.h"
extern "C" void glTexCoord1sv(const GLshort *);
# 1552 "shared/GL/gl.h"
extern "C" void glTexCoord2d(GLdouble, GLdouble);
# 1553 "shared/GL/gl.h"
extern "C" void glTexCoord2dv(const GLdouble *);
# 1554 "shared/GL/gl.h"
extern "C" void glTexCoord2f(GLfloat, GLfloat);
# 1555 "shared/GL/gl.h"
extern "C" void glTexCoord2fv(const GLfloat *);
# 1556 "shared/GL/gl.h"
extern "C" void glTexCoord2i(GLint, GLint);
# 1557 "shared/GL/gl.h"
extern "C" void glTexCoord2iv(const GLint *);
# 1558 "shared/GL/gl.h"
extern "C" void glTexCoord2s(GLshort, GLshort);
# 1559 "shared/GL/gl.h"
extern "C" void glTexCoord2sv(const GLshort *);
# 1560 "shared/GL/gl.h"
extern "C" void glTexCoord3d(GLdouble, GLdouble, GLdouble);
# 1561 "shared/GL/gl.h"
extern "C" void glTexCoord3dv(const GLdouble *);
# 1562 "shared/GL/gl.h"
extern "C" void glTexCoord3f(GLfloat, GLfloat, GLfloat);
# 1563 "shared/GL/gl.h"
extern "C" void glTexCoord3fv(const GLfloat *);
# 1564 "shared/GL/gl.h"
extern "C" void glTexCoord3i(GLint, GLint, GLint);
# 1565 "shared/GL/gl.h"
extern "C" void glTexCoord3iv(const GLint *);
# 1566 "shared/GL/gl.h"
extern "C" void glTexCoord3s(GLshort, GLshort, GLshort);
# 1567 "shared/GL/gl.h"
extern "C" void glTexCoord3sv(const GLshort *);
# 1568 "shared/GL/gl.h"
extern "C" void glTexCoord4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1569 "shared/GL/gl.h"
extern "C" void glTexCoord4dv(const GLdouble *);
# 1570 "shared/GL/gl.h"
extern "C" void glTexCoord4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1571 "shared/GL/gl.h"
extern "C" void glTexCoord4fv(const GLfloat *);
# 1572 "shared/GL/gl.h"
extern "C" void glTexCoord4i(GLint, GLint, GLint, GLint);
# 1573 "shared/GL/gl.h"
extern "C" void glTexCoord4iv(const GLint *);
# 1574 "shared/GL/gl.h"
extern "C" void glTexCoord4s(GLshort, GLshort, GLshort, GLshort);
# 1575 "shared/GL/gl.h"
extern "C" void glTexCoord4sv(const GLshort *);
# 1576 "shared/GL/gl.h"
extern "C" void glTexCoordPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 1577 "shared/GL/gl.h"
extern "C" void glTexEnvf(GLenum, GLenum, GLfloat);
# 1578 "shared/GL/gl.h"
extern "C" void glTexEnvfv(GLenum, GLenum, const GLfloat *);
# 1579 "shared/GL/gl.h"
extern "C" void glTexEnvi(GLenum, GLenum, GLint);
# 1580 "shared/GL/gl.h"
extern "C" void glTexEnviv(GLenum, GLenum, const GLint *);
# 1581 "shared/GL/gl.h"
extern "C" void glTexGend(GLenum, GLenum, GLdouble);
# 1582 "shared/GL/gl.h"
extern "C" void glTexGendv(GLenum, GLenum, const GLdouble *);
# 1583 "shared/GL/gl.h"
extern "C" void glTexGenf(GLenum, GLenum, GLfloat);
# 1584 "shared/GL/gl.h"
extern "C" void glTexGenfv(GLenum, GLenum, const GLfloat *);
# 1585 "shared/GL/gl.h"
extern "C" void glTexGeni(GLenum, GLenum, GLint);
# 1586 "shared/GL/gl.h"
extern "C" void glTexGeniv(GLenum, GLenum, const GLint *);
# 1587 "shared/GL/gl.h"
extern "C" void glTexImage1D(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
# 1588 "shared/GL/gl.h"
extern "C" void glTexImage2D(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
# 1589 "shared/GL/gl.h"
extern "C" void glTexParameterf(GLenum, GLenum, GLfloat);
# 1590 "shared/GL/gl.h"
extern "C" void glTexParameterfv(GLenum, GLenum, const GLfloat *);
# 1591 "shared/GL/gl.h"
extern "C" void glTexParameteri(GLenum, GLenum, GLint);
# 1592 "shared/GL/gl.h"
extern "C" void glTexParameteriv(GLenum, GLenum, const GLint *);
# 1593 "shared/GL/gl.h"
extern "C" void glTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
# 1594 "shared/GL/gl.h"
extern "C" void glTexSubImage2D(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
# 1595 "shared/GL/gl.h"
extern "C" void glTranslated(GLdouble, GLdouble, GLdouble);
# 1596 "shared/GL/gl.h"
extern "C" void glTranslatef(GLfloat, GLfloat, GLfloat);
# 1597 "shared/GL/gl.h"
extern "C" void glVertex2d(GLdouble, GLdouble);
# 1598 "shared/GL/gl.h"
extern "C" void glVertex2dv(const GLdouble *);
# 1599 "shared/GL/gl.h"
extern "C" void glVertex2f(GLfloat, GLfloat);
# 1600 "shared/GL/gl.h"
extern "C" void glVertex2fv(const GLfloat *);
# 1601 "shared/GL/gl.h"
extern "C" void glVertex2i(GLint, GLint);
# 1602 "shared/GL/gl.h"
extern "C" void glVertex2iv(const GLint *);
# 1603 "shared/GL/gl.h"
extern "C" void glVertex2s(GLshort, GLshort);
# 1604 "shared/GL/gl.h"
extern "C" void glVertex2sv(const GLshort *);
# 1605 "shared/GL/gl.h"
extern "C" void glVertex3d(GLdouble, GLdouble, GLdouble);
# 1606 "shared/GL/gl.h"
extern "C" void glVertex3dv(const GLdouble *);
# 1607 "shared/GL/gl.h"
extern "C" void glVertex3f(GLfloat, GLfloat, GLfloat);
# 1608 "shared/GL/gl.h"
extern "C" void glVertex3fv(const GLfloat *);
# 1609 "shared/GL/gl.h"
extern "C" void glVertex3i(GLint, GLint, GLint);
# 1610 "shared/GL/gl.h"
extern "C" void glVertex3iv(const GLint *);
# 1611 "shared/GL/gl.h"
extern "C" void glVertex3s(GLshort, GLshort, GLshort);
# 1612 "shared/GL/gl.h"
extern "C" void glVertex3sv(const GLshort *);
# 1613 "shared/GL/gl.h"
extern "C" void glVertex4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1614 "shared/GL/gl.h"
extern "C" void glVertex4dv(const GLdouble *);
# 1615 "shared/GL/gl.h"
extern "C" void glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1616 "shared/GL/gl.h"
extern "C" void glVertex4fv(const GLfloat *);
# 1617 "shared/GL/gl.h"
extern "C" void glVertex4i(GLint, GLint, GLint, GLint);
# 1618 "shared/GL/gl.h"
extern "C" void glVertex4iv(const GLint *);
# 1619 "shared/GL/gl.h"
extern "C" void glVertex4s(GLshort, GLshort, GLshort, GLshort);
# 1620 "shared/GL/gl.h"
extern "C" void glVertex4sv(const GLshort *);
# 1621 "shared/GL/gl.h"
extern "C" void glVertexPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 1622 "shared/GL/gl.h"
extern "C" void glViewport(GLint, GLint, GLsizei, GLsizei);
# 3335 "sdk/GL/glext.h"
extern "C" { typedef char GLchar; }
# 3340 "sdk/GL/glext.h"
extern "C" { typedef ptrdiff_t GLintptr; }
# 3341 "sdk/GL/glext.h"
extern "C" { typedef ptrdiff_t GLsizeiptr; }
# 3346 "sdk/GL/glext.h"
extern "C" { typedef ptrdiff_t GLintptrARB; }
# 3347 "sdk/GL/glext.h"
extern "C" { typedef ptrdiff_t GLsizeiptrARB; }
# 3352 "sdk/GL/glext.h"
extern "C" { typedef char GLcharARB; }
# 3353 "sdk/GL/glext.h"
extern "C" { typedef unsigned GLhandleARB; }
# 3358 "sdk/GL/glext.h"
extern "C" { typedef unsigned short GLhalfARB; }
# 3362 "sdk/GL/glext.h"
extern "C" { typedef unsigned short GLhalfNV; }
# 3366 "sdk/GL/glext.h"
extern "C" { typedef signed long long GLint64EXT; }
# 3367 "sdk/GL/glext.h"
extern "C" { typedef unsigned long long GLuint64EXT; }
# 3412 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
# 3413 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDEQUATIONPROC)(GLenum); }
# 3414 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
# 3415 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 3416 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
# 3417 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
# 3418 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCOLORTABLEPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 3419 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 3420 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 3421 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 3422 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORSUBTABLEPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 3423 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
# 3424 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 3425 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 3426 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum, GLenum, GLfloat); }
# 3427 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
# 3428 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum, GLenum, GLint); }
# 3429 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
# 3430 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 3431 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
# 3432 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 3433 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 3434 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 3435 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *); }
# 3436 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *); }
# 3437 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 3438 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 3439 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 3440 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 3441 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 3442 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 3443 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLHISTOGRAMPROC)(GLenum, GLsizei, GLenum, GLboolean); }
# 3444 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMINMAXPROC)(GLenum, GLenum, GLboolean); }
# 3445 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRESETHISTOGRAMPROC)(GLenum); }
# 3446 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRESETMINMAXPROC)(GLenum); }
# 3447 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXIMAGE3DPROC)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
# 3448 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 3449 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 3502 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLACTIVETEXTUREPROC)(GLenum); }
# 3503 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREPROC)(GLenum); }
# 3504 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DPROC)(GLenum, GLdouble); }
# 3505 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVPROC)(GLenum, const GLdouble *); }
# 3506 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FPROC)(GLenum, GLfloat); }
# 3507 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVPROC)(GLenum, const GLfloat *); }
# 3508 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IPROC)(GLenum, GLint); }
# 3509 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVPROC)(GLenum, const GLint *); }
# 3510 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SPROC)(GLenum, GLshort); }
# 3511 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVPROC)(GLenum, const GLshort *); }
# 3512 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DPROC)(GLenum, GLdouble, GLdouble); }
# 3513 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVPROC)(GLenum, const GLdouble *); }
# 3514 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FPROC)(GLenum, GLfloat, GLfloat); }
# 3515 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVPROC)(GLenum, const GLfloat *); }
# 3516 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IPROC)(GLenum, GLint, GLint); }
# 3517 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVPROC)(GLenum, const GLint *); }
# 3518 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SPROC)(GLenum, GLshort, GLshort); }
# 3519 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVPROC)(GLenum, const GLshort *); }
# 3520 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 3521 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVPROC)(GLenum, const GLdouble *); }
# 3522 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 3523 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVPROC)(GLenum, const GLfloat *); }
# 3524 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IPROC)(GLenum, GLint, GLint, GLint); }
# 3525 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVPROC)(GLenum, const GLint *); }
# 3526 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SPROC)(GLenum, GLshort, GLshort, GLshort); }
# 3527 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVPROC)(GLenum, const GLshort *); }
# 3528 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3529 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVPROC)(GLenum, const GLdouble *); }
# 3530 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3531 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVPROC)(GLenum, const GLfloat *); }
# 3532 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 3533 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVPROC)(GLenum, const GLint *); }
# 3534 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 3535 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVPROC)(GLenum, const GLshort *); }
# 3536 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *); }
# 3537 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *); }
# 3538 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *); }
# 3539 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *); }
# 3540 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEPROC)(GLclampf, GLboolean); }
# 3541 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 3542 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 3543 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
# 3544 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 3545 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 3546 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 3547 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum, GLint, GLvoid *); }
# 3599 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
# 3600 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDFPROC)(GLfloat); }
# 3601 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDFVPROC)(const GLfloat *); }
# 3602 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDDPROC)(GLdouble); }
# 3603 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDDVPROC)(const GLdouble *); }
# 3604 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERPROC)(GLenum, GLsizei, const GLvoid *); }
# 3605 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
# 3606 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSPROC)(GLenum, const GLsizei *, GLenum, const GLvoid **, GLsizei); }
# 3607 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFPROC)(GLenum, GLfloat); }
# 3608 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVPROC)(GLenum, const GLfloat *); }
# 3609 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERIPROC)(GLenum, GLint); }
# 3610 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVPROC)(GLenum, const GLint *); }
# 3611 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BPROC)(GLbyte, GLbyte, GLbyte); }
# 3612 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *); }
# 3613 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DPROC)(GLdouble, GLdouble, GLdouble); }
# 3614 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *); }
# 3615 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FPROC)(GLfloat, GLfloat, GLfloat); }
# 3616 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *); }
# 3617 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IPROC)(GLint, GLint, GLint); }
# 3618 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVPROC)(const GLint *); }
# 3619 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SPROC)(GLshort, GLshort, GLshort); }
# 3620 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *); }
# 3621 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBPROC)(GLubyte, GLubyte, GLubyte); }
# 3622 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *); }
# 3623 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIPROC)(GLuint, GLuint, GLuint); }
# 3624 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *); }
# 3625 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USPROC)(GLushort, GLushort, GLushort); }
# 3626 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *); }
# 3627 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 3628 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DPROC)(GLdouble, GLdouble); }
# 3629 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DVPROC)(const GLdouble *); }
# 3630 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FPROC)(GLfloat, GLfloat); }
# 3631 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FVPROC)(const GLfloat *); }
# 3632 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IPROC)(GLint, GLint); }
# 3633 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IVPROC)(const GLint *); }
# 3634 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SPROC)(GLshort, GLshort); }
# 3635 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SVPROC)(const GLshort *); }
# 3636 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DPROC)(GLdouble, GLdouble, GLdouble); }
# 3637 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DVPROC)(const GLdouble *); }
# 3638 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FPROC)(GLfloat, GLfloat, GLfloat); }
# 3639 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FVPROC)(const GLfloat *); }
# 3640 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IPROC)(GLint, GLint, GLint); }
# 3641 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IVPROC)(const GLint *); }
# 3642 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SPROC)(GLshort, GLshort, GLshort); }
# 3643 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SVPROC)(const GLshort *); }
# 3669 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENQUERIESPROC)(GLsizei, GLuint *); }
# 3670 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEQUERIESPROC)(GLsizei, const GLuint *); }
# 3671 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISQUERYPROC)(GLuint); }
# 3672 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINQUERYPROC)(GLenum, GLuint); }
# 3673 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDQUERYPROC)(GLenum); }
# 3674 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYIVPROC)(GLenum, GLenum, GLint *); }
# 3675 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVPROC)(GLuint, GLenum, GLint *); }
# 3676 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVPROC)(GLuint, GLenum, GLuint *); }
# 3677 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDBUFFERPROC)(GLenum, GLuint); }
# 3678 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei, const GLuint *); }
# 3679 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENBUFFERSPROC)(GLsizei, GLuint *); }
# 3680 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISBUFFERPROC)(GLuint); }
# 3681 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, const GLvoid *, GLenum); }
# 3682 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const GLvoid *); }
# 3683 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, GLvoid *); }
# 3684 "sdk/GL/glext.h"
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERPROC)(GLenum, GLenum); }
# 3685 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERPROC)(GLenum); }
# 3686 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 3687 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVPROC)(GLenum, GLenum, GLvoid **); }
# 3787 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum, GLenum); }
# 3788 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWBUFFERSPROC)(GLsizei, const GLenum *); }
# 3789 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
# 3790 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEPROC)(GLenum, GLenum, GLint, GLuint); }
# 3791 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTENCILMASKSEPARATEPROC)(GLenum, GLuint); }
# 3792 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLATTACHSHADERPROC)(GLuint, GLuint); }
# 3793 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONPROC)(GLuint, GLuint, const GLchar *); }
# 3794 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPILESHADERPROC)(GLuint); }
# 3795 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLCREATEPROGRAMPROC)(void); }
# 3796 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum); }
# 3797 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEPROGRAMPROC)(GLuint); }
# 3798 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETESHADERPROC)(GLuint); }
# 3799 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDETACHSHADERPROC)(GLuint, GLuint); }
# 3800 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint); }
# 3801 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint); }
# 3802 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
# 3803 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
# 3804 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETATTACHEDSHADERSPROC)(GLuint, GLsizei, GLsizei *, GLuint *); }
# 3805 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONPROC)(GLuint, const GLchar *); }
# 3806 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint *); }
# 3807 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
# 3808 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint *); }
# 3809 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
# 3810 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSHADERSOURCEPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
# 3811 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONPROC)(GLuint, const GLchar *); }
# 3812 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETUNIFORMFVPROC)(GLuint, GLint, GLfloat *); }
# 3813 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETUNIFORMIVPROC)(GLuint, GLint, GLint *); }
# 3814 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVPROC)(GLuint, GLenum, GLdouble *); }
# 3815 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVPROC)(GLuint, GLenum, GLfloat *); }
# 3816 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVPROC)(GLuint, GLenum, GLint *); }
# 3817 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint, GLenum, GLvoid **); }
# 3818 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISPROGRAMPROC)(GLuint); }
# 3819 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISSHADERPROC)(GLuint); }
# 3820 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLINKPROGRAMPROC)(GLuint); }
# 3821 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar **, const GLint *); }
# 3822 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUSEPROGRAMPROC)(GLuint); }
# 3823 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1FPROC)(GLint, GLfloat); }
# 3824 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2FPROC)(GLint, GLfloat, GLfloat); }
# 3825 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3FPROC)(GLint, GLfloat, GLfloat, GLfloat); }
# 3826 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4FPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3827 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1IPROC)(GLint, GLint); }
# 3828 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2IPROC)(GLint, GLint, GLint); }
# 3829 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3IPROC)(GLint, GLint, GLint, GLint); }
# 3830 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4IPROC)(GLint, GLint, GLint, GLint, GLint); }
# 3831 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1FVPROC)(GLint, GLsizei, const GLfloat *); }
# 3832 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2FVPROC)(GLint, GLsizei, const GLfloat *); }
# 3833 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3FVPROC)(GLint, GLsizei, const GLfloat *); }
# 3834 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4FVPROC)(GLint, GLsizei, const GLfloat *); }
# 3835 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1IVPROC)(GLint, GLsizei, const GLint *); }
# 3836 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2IVPROC)(GLint, GLsizei, const GLint *); }
# 3837 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3IVPROC)(GLint, GLsizei, const GLint *); }
# 3838 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4IVPROC)(GLint, GLsizei, const GLint *); }
# 3839 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3840 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3841 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3842 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMPROC)(GLuint); }
# 3843 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DPROC)(GLuint, GLdouble); }
# 3844 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVPROC)(GLuint, const GLdouble *); }
# 3845 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FPROC)(GLuint, GLfloat); }
# 3846 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVPROC)(GLuint, const GLfloat *); }
# 3847 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SPROC)(GLuint, GLshort); }
# 3848 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVPROC)(GLuint, const GLshort *); }
# 3849 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DPROC)(GLuint, GLdouble, GLdouble); }
# 3850 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVPROC)(GLuint, const GLdouble *); }
# 3851 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FPROC)(GLuint, GLfloat, GLfloat); }
# 3852 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVPROC)(GLuint, const GLfloat *); }
# 3853 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SPROC)(GLuint, GLshort, GLshort); }
# 3854 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVPROC)(GLuint, const GLshort *); }
# 3855 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 3856 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVPROC)(GLuint, const GLdouble *); }
# 3857 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 3858 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVPROC)(GLuint, const GLfloat *); }
# 3859 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SPROC)(GLuint, GLshort, GLshort, GLshort); }
# 3860 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVPROC)(GLuint, const GLshort *); }
# 3861 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVPROC)(GLuint, const GLbyte *); }
# 3862 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVPROC)(GLuint, const GLint *); }
# 3863 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVPROC)(GLuint, const GLshort *); }
# 3864 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 3865 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVPROC)(GLuint, const GLubyte *); }
# 3866 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVPROC)(GLuint, const GLuint *); }
# 3867 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVPROC)(GLuint, const GLushort *); }
# 3868 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVPROC)(GLuint, const GLbyte *); }
# 3869 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3870 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVPROC)(GLuint, const GLdouble *); }
# 3871 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3872 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVPROC)(GLuint, const GLfloat *); }
# 3873 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVPROC)(GLuint, const GLint *); }
# 3874 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 3875 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVPROC)(GLuint, const GLshort *); }
# 3876 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVPROC)(GLuint, const GLubyte *); }
# 3877 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVPROC)(GLuint, const GLuint *); }
# 3878 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVPROC)(GLuint, const GLushort *); }
# 3879 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *); }
# 3892 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3893 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3894 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3895 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3896 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3897 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 3938 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLACTIVETEXTUREARBPROC)(GLenum); }
# 3939 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum); }
# 3940 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DARBPROC)(GLenum, GLdouble); }
# 3941 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVARBPROC)(GLenum, const GLdouble *); }
# 3942 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FARBPROC)(GLenum, GLfloat); }
# 3943 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVARBPROC)(GLenum, const GLfloat *); }
# 3944 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IARBPROC)(GLenum, GLint); }
# 3945 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVARBPROC)(GLenum, const GLint *); }
# 3946 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SARBPROC)(GLenum, GLshort); }
# 3947 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVARBPROC)(GLenum, const GLshort *); }
# 3948 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DARBPROC)(GLenum, GLdouble, GLdouble); }
# 3949 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVARBPROC)(GLenum, const GLdouble *); }
# 3950 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FARBPROC)(GLenum, GLfloat, GLfloat); }
# 3951 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVARBPROC)(GLenum, const GLfloat *); }
# 3952 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IARBPROC)(GLenum, GLint, GLint); }
# 3953 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVARBPROC)(GLenum, const GLint *); }
# 3954 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SARBPROC)(GLenum, GLshort, GLshort); }
# 3955 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVARBPROC)(GLenum, const GLshort *); }
# 3956 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 3957 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVARBPROC)(GLenum, const GLdouble *); }
# 3958 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 3959 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVARBPROC)(GLenum, const GLfloat *); }
# 3960 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IARBPROC)(GLenum, GLint, GLint, GLint); }
# 3961 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVARBPROC)(GLenum, const GLint *); }
# 3962 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SARBPROC)(GLenum, GLshort, GLshort, GLshort); }
# 3963 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVARBPROC)(GLenum, const GLshort *); }
# 3964 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3965 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVARBPROC)(GLenum, const GLdouble *); }
# 3966 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3967 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVARBPROC)(GLenum, const GLfloat *); }
# 3968 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IARBPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 3969 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVARBPROC)(GLenum, const GLint *); }
# 3970 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SARBPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 3971 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVARBPROC)(GLenum, const GLshort *); }
# 3982 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *); }
# 3983 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *); }
# 3984 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *); }
# 3985 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *); }
# 3993 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEARBPROC)(GLclampf, GLboolean); }
# 4015 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 4016 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 4017 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
# 4018 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 4019 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 4020 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 4021 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum, GLint, GLvoid *); }
# 4034 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFARBPROC)(GLenum, GLfloat); }
# 4035 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVARBPROC)(GLenum, const GLfloat *); }
# 4052 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTBVARBPROC)(GLint, const GLbyte *); }
# 4053 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTSVARBPROC)(GLint, const GLshort *); }
# 4054 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTIVARBPROC)(GLint, const GLint *); }
# 4055 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTFVARBPROC)(GLint, const GLfloat *); }
# 4056 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTDVARBPROC)(GLint, const GLdouble *); }
# 4057 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTUBVARBPROC)(GLint, const GLubyte *); }
# 4058 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTUSVARBPROC)(GLint, const GLushort *); }
# 4059 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTUIVARBPROC)(GLint, const GLuint *); }
# 4060 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWEIGHTPOINTERARBPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 4061 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXBLENDARBPROC)(GLint); }
# 4073 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint); }
# 4074 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMATRIXINDEXUBVARBPROC)(GLint, const GLubyte *); }
# 4075 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMATRIXINDEXUSVARBPROC)(GLint, const GLushort *); }
# 4076 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMATRIXINDEXUIVARBPROC)(GLint, const GLuint *); }
# 4077 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMATRIXINDEXPOINTERARBPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 4128 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DARBPROC)(GLdouble, GLdouble); }
# 4129 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *); }
# 4130 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FARBPROC)(GLfloat, GLfloat); }
# 4131 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *); }
# 4132 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IARBPROC)(GLint, GLint); }
# 4133 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IVARBPROC)(const GLint *); }
# 4134 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SARBPROC)(GLshort, GLshort); }
# 4135 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SVARBPROC)(const GLshort *); }
# 4136 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DARBPROC)(GLdouble, GLdouble, GLdouble); }
# 4137 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *); }
# 4138 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FARBPROC)(GLfloat, GLfloat, GLfloat); }
# 4139 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *); }
# 4140 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IARBPROC)(GLint, GLint, GLint); }
# 4141 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IVARBPROC)(const GLint *); }
# 4142 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SARBPROC)(GLshort, GLshort, GLshort); }
# 4143 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SVARBPROC)(const GLshort *); }
# 4212 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DARBPROC)(GLuint, GLdouble); }
# 4213 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVARBPROC)(GLuint, const GLdouble *); }
# 4214 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FARBPROC)(GLuint, GLfloat); }
# 4215 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVARBPROC)(GLuint, const GLfloat *); }
# 4216 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SARBPROC)(GLuint, GLshort); }
# 4217 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVARBPROC)(GLuint, const GLshort *); }
# 4218 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DARBPROC)(GLuint, GLdouble, GLdouble); }
# 4219 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVARBPROC)(GLuint, const GLdouble *); }
# 4220 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FARBPROC)(GLuint, GLfloat, GLfloat); }
# 4221 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVARBPROC)(GLuint, const GLfloat *); }
# 4222 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SARBPROC)(GLuint, GLshort, GLshort); }
# 4223 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVARBPROC)(GLuint, const GLshort *); }
# 4224 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 4225 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVARBPROC)(GLuint, const GLdouble *); }
# 4226 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 4227 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVARBPROC)(GLuint, const GLfloat *); }
# 4228 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SARBPROC)(GLuint, GLshort, GLshort, GLshort); }
# 4229 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVARBPROC)(GLuint, const GLshort *); }
# 4230 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint, const GLbyte *); }
# 4231 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint, const GLint *); }
# 4232 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint, const GLshort *); }
# 4233 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 4234 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint, const GLubyte *); }
# 4235 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint, const GLuint *); }
# 4236 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint, const GLushort *); }
# 4237 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVARBPROC)(GLuint, const GLbyte *); }
# 4238 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 4239 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVARBPROC)(GLuint, const GLdouble *); }
# 4240 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 4241 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVARBPROC)(GLuint, const GLfloat *); }
# 4242 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVARBPROC)(GLuint, const GLint *); }
# 4243 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SARBPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 4244 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVARBPROC)(GLuint, const GLshort *); }
# 4245 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint, const GLubyte *); }
# 4246 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint, const GLuint *); }
# 4247 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVARBPROC)(GLuint, const GLushort *); }
# 4248 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *); }
# 4249 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
# 4250 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
# 4251 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMSTRINGARBPROC)(GLenum, GLenum, GLsizei, const GLvoid *); }
# 4252 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDPROGRAMARBPROC)(GLenum, GLuint); }
# 4253 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEPROGRAMSARBPROC)(GLsizei, const GLuint *); }
# 4254 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENPROGRAMSARBPROC)(GLsizei, GLuint *); }
# 4255 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 4256 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
# 4257 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 4258 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
# 4259 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 4260 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
# 4261 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 4262 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
# 4263 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
# 4264 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
# 4265 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
# 4266 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
# 4267 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMIVARBPROC)(GLenum, GLenum, GLint *); }
# 4268 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGARBPROC)(GLenum, GLenum, GLvoid *); }
# 4269 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint, GLenum, GLdouble *); }
# 4270 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint, GLenum, GLfloat *); }
# 4271 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint, GLenum, GLint *); }
# 4272 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint, GLenum, GLvoid **); }
# 4273 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISPROGRAMARBPROC)(GLuint); }
# 4296 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDBUFFERARBPROC)(GLenum, GLuint); }
# 4297 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEBUFFERSARBPROC)(GLsizei, const GLuint *); }
# 4298 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENBUFFERSARBPROC)(GLsizei, GLuint *); }
# 4299 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISBUFFERARBPROC)(GLuint); }
# 4300 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBUFFERDATAARBPROC)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum); }
# 4301 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *); }
# 4302 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *); }
# 4303 "sdk/GL/glext.h"
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERARBPROC)(GLenum, GLenum); }
# 4304 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERARBPROC)(GLenum); }
# 4305 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum, GLenum, GLint *); }
# 4306 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVARBPROC)(GLenum, GLenum, GLvoid **); }
# 4321 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENQUERIESARBPROC)(GLsizei, GLuint *); }
# 4322 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEQUERIESARBPROC)(GLsizei, const GLuint *); }
# 4323 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISQUERYARBPROC)(GLuint); }
# 4324 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINQUERYARBPROC)(GLenum, GLuint); }
# 4325 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDQUERYARBPROC)(GLenum); }
# 4326 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYIVARBPROC)(GLenum, GLenum, GLint *); }
# 4327 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVARBPROC)(GLuint, GLenum, GLint *); }
# 4328 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint, GLenum, GLuint *); }
# 4374 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEOBJECTARBPROC)(GLhandleARB); }
# 4375 "sdk/GL/glext.h"
extern "C" { typedef GLhandleARB (*PFNGLGETHANDLEARBPROC)(GLenum); }
# 4376 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDETACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
# 4377 "sdk/GL/glext.h"
extern "C" { typedef GLhandleARB (*PFNGLCREATESHADEROBJECTARBPROC)(GLenum); }
# 4378 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *); }
# 4379 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMPILESHADERARBPROC)(GLhandleARB); }
# 4380 "sdk/GL/glext.h"
extern "C" { typedef GLhandleARB (*PFNGLCREATEPROGRAMOBJECTARBPROC)(void); }
# 4381 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLATTACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
# 4382 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLINKPROGRAMARBPROC)(GLhandleARB); }
# 4383 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB); }
# 4384 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB); }
# 4385 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1FARBPROC)(GLint, GLfloat); }
# 4386 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2FARBPROC)(GLint, GLfloat, GLfloat); }
# 4387 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3FARBPROC)(GLint, GLfloat, GLfloat, GLfloat); }
# 4388 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4FARBPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 4389 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1IARBPROC)(GLint, GLint); }
# 4390 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2IARBPROC)(GLint, GLint, GLint); }
# 4391 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3IARBPROC)(GLint, GLint, GLint, GLint); }
# 4392 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4IARBPROC)(GLint, GLint, GLint, GLint, GLint); }
# 4393 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 4394 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 4395 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 4396 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 4397 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1IVARBPROC)(GLint, GLsizei, const GLint *); }
# 4398 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2IVARBPROC)(GLint, GLsizei, const GLint *); }
# 4399 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3IVARBPROC)(GLint, GLsizei, const GLint *); }
# 4400 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4IVARBPROC)(GLint, GLsizei, const GLint *); }
# 4401 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 4402 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 4403 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 4404 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB, GLenum, GLfloat *); }
# 4405 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB, GLenum, GLint *); }
# 4406 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETINFOLOGARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
# 4407 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *); }
# 4408 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
# 4409 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
# 4410 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETUNIFORMFVARBPROC)(GLhandleARB, GLint, GLfloat *); }
# 4411 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETUNIFORMIVARBPROC)(GLhandleARB, GLint, GLint *); }
# 4412 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
# 4422 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB, GLuint, const GLcharARB *); }
# 4423 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
# 4424 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
# 4452 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWBUFFERSARBPROC)(GLsizei, const GLenum *); }
# 4464 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLAMPCOLORARBPROC)(GLenum, GLenum); }
# 4488 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDCOLOREXTPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
# 4496 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOLYGONOFFSETEXTPROC)(GLfloat, GLfloat); }
# 4509 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXIMAGE3DEXTPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
# 4510 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4519 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLfloat *); }
# 4520 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLsizei, const GLfloat *); }
# 4529 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4530 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4542 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint); }
# 4543 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint); }
# 4544 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei); }
# 4545 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 4546 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 4563 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMEXTPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 4564 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4565 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4566 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXEXTPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 4567 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4568 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4569 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLHISTOGRAMEXTPROC)(GLenum, GLsizei, GLenum, GLboolean); }
# 4570 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMINMAXEXTPROC)(GLenum, GLenum, GLboolean); }
# 4571 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRESETHISTOGRAMEXTPROC)(GLenum); }
# 4572 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRESETMINMAXEXTPROC)(GLenum); }
# 4592 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4593 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4594 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum, GLenum, GLfloat); }
# 4595 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 4596 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum, GLenum, GLint); }
# 4597 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 4598 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 4599 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
# 4600 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 4601 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4602 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4603 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *); }
# 4604 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *); }
# 4622 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLESGIPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4623 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, const GLfloat *); }
# 4624 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, const GLint *); }
# 4625 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCOLORTABLESGIPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 4626 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLESGIPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 4627 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, GLfloat *); }
# 4628 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, GLint *); }
# 4636 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTEXGENSGIXPROC)(GLenum); }
# 4649 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum, GLint); }
# 4650 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum, const GLint *); }
# 4651 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum, GLfloat); }
# 4652 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum, const GLfloat *); }
# 4653 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum, GLint *); }
# 4654 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum, GLfloat *); }
# 4663 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXIMAGE4DSGISPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
# 4664 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4685 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei, const GLuint *, GLboolean *); }
# 4686 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDTEXTUREEXTPROC)(GLenum, GLuint); }
# 4687 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETETEXTURESEXTPROC)(GLsizei, const GLuint *); }
# 4688 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENTEXTURESEXTPROC)(GLsizei, GLuint *); }
# 4689 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISTEXTUREEXTPROC)(GLuint); }
# 4690 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei, const GLuint *, const GLclampf *); }
# 4699 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDETAILTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
# 4700 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 4709 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHARPENTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
# 4710 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 4727 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLEMASKSGISPROC)(GLclampf, GLboolean); }
# 4728 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLEPATTERNSGISPROC)(GLenum); }
# 4748 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLARRAYELEMENTEXTPROC)(GLint); }
# 4749 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
# 4750 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWARRAYSEXTPROC)(GLenum, GLint, GLsizei); }
# 4751 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei, GLsizei, const GLboolean *); }
# 4752 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPOINTERVEXTPROC)(GLenum, GLvoid **); }
# 4753 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINDEXPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const GLvoid *); }
# 4754 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const GLvoid *); }
# 4755 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORDPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
# 4756 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
# 4788 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDEQUATIONEXTPROC)(GLenum); }
# 4819 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum, GLfloat); }
# 4820 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum, const GLfloat *); }
# 4821 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSPRITEPARAMETERISGIXPROC)(GLenum, GLint); }
# 4822 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum, const GLint *); }
# 4835 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFEXTPROC)(GLenum, GLfloat); }
# 4836 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVEXTPROC)(GLenum, const GLfloat *); }
# 4845 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFSGISPROC)(GLenum, GLfloat); }
# 4846 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVSGISPROC)(GLenum, const GLfloat *); }
# 4859 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETINSTRUMENTSSGIXPROC)(void); }
# 4860 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei, GLint *); }
# 4861 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *); }
# 4862 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREADINSTRUMENTSSGIXPROC)(GLint); }
# 4863 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTARTINSTRUMENTSSGIXPROC)(void); }
# 4864 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint); }
# 4876 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEZOOMSGIXPROC)(GLint); }
# 4884 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTAGSAMPLEBUFFERSGIXPROC)(void); }
# 4895 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *); }
# 4896 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *); }
# 4897 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEFORMSGIXPROC)(GLbitfield); }
# 4898 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield); }
# 4906 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *); }
# 4914 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFLUSHRASTERSGIXPROC)(void); }
# 4927 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGFUNCSGISPROC)(GLsizei, const GLfloat *); }
# 4928 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFOGFUNCSGISPROC)(GLfloat *); }
# 4945 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum, GLenum, GLint); }
# 4946 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum, GLenum, GLfloat); }
# 4947 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, const GLint *); }
# 4948 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, const GLfloat *); }
# 4949 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, GLint *); }
# 4950 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, GLfloat *); }
# 4967 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4968 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
# 4980 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLHINTPGIPROC)(GLenum, GLint); }
# 4991 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORTABLEEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 4992 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEEXTPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 4993 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4994 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 5011 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint, GLenum, GLfloat *); }
# 5012 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint, GLenum, GLint *); }
# 5013 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLISTPARAMETERFSGIXPROC)(GLuint, GLenum, GLfloat); }
# 5014 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLISTPARAMETERFVSGIXPROC)(GLuint, GLenum, const GLfloat *); }
# 5015 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLISTPARAMETERISGIXPROC)(GLuint, GLenum, GLint); }
# 5016 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLISTPARAMETERIVSGIXPROC)(GLuint, GLenum, const GLint *); }
# 5044 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINDEXMATERIALEXTPROC)(GLenum, GLenum); }
# 5052 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINDEXFUNCEXTPROC)(GLenum, GLclampf); }
# 5065 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOCKARRAYSEXTPROC)(GLint, GLsizei); }
# 5066 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNLOCKARRAYSEXTPROC)(void); }
# 5075 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCULLPARAMETERDVEXTPROC)(GLenum, GLdouble *); }
# 5076 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCULLPARAMETERFVEXTPROC)(GLenum, GLfloat *); }
# 5105 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum, GLenum); }
# 5106 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum, GLenum, GLfloat); }
# 5107 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
# 5108 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum, GLenum, GLint); }
# 5109 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, const GLint *); }
# 5110 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum, GLfloat); }
# 5111 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum, const GLfloat *); }
# 5112 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum, GLint); }
# 5113 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum, const GLint *); }
# 5114 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum, GLenum, GLfloat); }
# 5115 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
# 5116 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum, GLenum, GLint); }
# 5117 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, const GLint *); }
# 5118 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
# 5119 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, GLint *); }
# 5120 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
# 5121 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, GLint *); }
# 5122 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLIGHTENVISGIXPROC)(GLenum, GLint); }
# 5138 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
# 5156 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLAPPLYTEXTUREEXTPROC)(GLenum); }
# 5157 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXTURELIGHTEXTPROC)(GLenum); }
# 5158 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXTUREMATERIALEXTPROC)(GLenum, GLenum); }
# 5179 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLASYNCMARKERSGIXPROC)(GLuint); }
# 5180 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLFINISHASYNCSGIXPROC)(GLuint *); }
# 5181 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLPOLLASYNCSGIXPROC)(GLuint *); }
# 5182 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei); }
# 5183 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint, GLsizei); }
# 5184 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISASYNCMARKERSGIXPROC)(GLuint); }
# 5203 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
# 5204 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALPOINTERVINTELPROC)(GLenum, const GLvoid **); }
# 5205 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
# 5206 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
# 5221 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum, GLenum, GLint); }
# 5222 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum, GLenum, GLfloat); }
# 5223 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 5224 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 5260 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
# 5261 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *); }
# 5262 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
# 5263 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *); }
# 5264 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
# 5265 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *); }
# 5266 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IEXTPROC)(GLint, GLint, GLint); }
# 5267 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *); }
# 5268 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort, GLshort, GLshort); }
# 5269 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *); }
# 5270 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte, GLubyte, GLubyte); }
# 5271 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *); }
# 5272 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint, GLuint, GLuint); }
# 5273 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *); }
# 5274 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort, GLushort, GLushort); }
# 5275 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *); }
# 5276 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 5284 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXTURENORMALEXTPROC)(GLenum); }
# 5293 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
# 5294 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum, const GLsizei *, GLenum, const GLvoid **, GLsizei); }
# 5306 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDFEXTPROC)(GLfloat); }
# 5307 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDFVEXTPROC)(const GLfloat *); }
# 5308 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDDEXTPROC)(GLdouble); }
# 5309 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDDVEXTPROC)(const GLdouble *); }
# 5310 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 5343 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
# 5344 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3BVEXTPROC)(const GLbyte *); }
# 5345 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
# 5346 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3DVEXTPROC)(const GLdouble *); }
# 5347 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
# 5348 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3FVEXTPROC)(const GLfloat *); }
# 5349 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3IEXTPROC)(GLint, GLint, GLint); }
# 5350 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3IVEXTPROC)(const GLint *); }
# 5351 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3SEXTPROC)(GLshort, GLshort, GLshort); }
# 5352 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENT3SVEXTPROC)(const GLshort *); }
# 5353 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
# 5354 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3BVEXTPROC)(const GLbyte *); }
# 5355 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
# 5356 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3DVEXTPROC)(const GLdouble *); }
# 5357 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
# 5358 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3FVEXTPROC)(const GLfloat *); }
# 5359 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3IEXTPROC)(GLint, GLint, GLint); }
# 5360 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3IVEXTPROC)(const GLint *); }
# 5361 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3SEXTPROC)(GLshort, GLshort, GLshort); }
# 5362 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMAL3SVEXTPROC)(const GLshort *); }
# 5363 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTANGENTPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 5364 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINORMALPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 5388 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFINISHTEXTURESUNXPROC)(void); }
# 5403 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte); }
# 5404 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort); }
# 5405 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORISUNPROC)(GLint); }
# 5406 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat); }
# 5407 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble); }
# 5408 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte); }
# 5409 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort); }
# 5410 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint); }
# 5424 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUISUNPROC)(GLuint); }
# 5425 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort); }
# 5426 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte); }
# 5427 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *); }
# 5428 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *); }
# 5429 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *); }
# 5430 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum, GLsizei, const GLvoid **); }
# 5477 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat); }
# 5478 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *, const GLfloat *); }
# 5479 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 5480 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *, const GLfloat *); }
# 5481 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5482 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 5483 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5484 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 5485 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5486 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 5487 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5488 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 5489 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5490 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 5491 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 5492 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *, const GLubyte *, const GLfloat *); }
# 5493 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5494 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 5495 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5496 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 5497 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5498 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 5499 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5500 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 5501 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 5502 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *); }
# 5503 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 5504 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *, const GLubyte *, const GLfloat *); }
# 5505 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5506 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 5507 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5508 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 5509 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5510 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 5511 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5512 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 5513 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5514 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 5515 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5516 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 5524 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum, GLenum, GLenum, GLenum); }
# 5532 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEINGRPROC)(GLenum, GLenum, GLenum, GLenum); }
# 5578 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat); }
# 5579 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *); }
# 5580 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLsizei, GLenum, GLsizei, const GLvoid *); }
# 5593 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGENVPROC)(void); }
# 5594 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGENVPROC)(GLsizei, const GLvoid *); }
# 5614 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum, const GLfloat *); }
# 5615 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFNVPROC)(GLenum, GLfloat); }
# 5616 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum, const GLint *); }
# 5617 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERINVPROC)(GLenum, GLint); }
# 5618 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum); }
# 5619 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINEROUTPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean); }
# 5620 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFINALCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum); }
# 5621 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLfloat *); }
# 5622 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLint *); }
# 5623 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLfloat *); }
# 5624 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLint *); }
# 5625 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 5626 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
# 5650 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRESIZEBUFFERSMESAPROC)(void); }
# 5681 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DMESAPROC)(GLdouble, GLdouble); }
# 5682 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *); }
# 5683 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FMESAPROC)(GLfloat, GLfloat); }
# 5684 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *); }
# 5685 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IMESAPROC)(GLint, GLint); }
# 5686 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2IVMESAPROC)(const GLint *); }
# 5687 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SMESAPROC)(GLshort, GLshort); }
# 5688 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *); }
# 5689 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DMESAPROC)(GLdouble, GLdouble, GLdouble); }
# 5690 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *); }
# 5691 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FMESAPROC)(GLfloat, GLfloat, GLfloat); }
# 5692 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *); }
# 5693 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IMESAPROC)(GLint, GLint, GLint); }
# 5694 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3IVMESAPROC)(const GLint *); }
# 5695 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SMESAPROC)(GLshort, GLshort, GLshort); }
# 5696 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *); }
# 5697 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4DMESAPROC)(GLdouble, GLdouble, GLdouble, GLdouble); }
# 5698 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *); }
# 5699 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4FMESAPROC)(GLfloat, GLfloat, GLfloat, GLfloat); }
# 5700 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *); }
# 5701 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4IMESAPROC)(GLint, GLint, GLint, GLint); }
# 5702 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4IVMESAPROC)(const GLint *); }
# 5703 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4SMESAPROC)(GLshort, GLshort, GLshort, GLshort); }
# 5704 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *); }
# 5721 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint); }
# 5722 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const *, GLsizei, GLint); }
# 5737 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 5738 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 5739 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint, const GLboolean **, GLint); }
# 5740 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 5741 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINDEXPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 5742 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 5743 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 5744 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 5776 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTBUFFERMASK3DFXPROC)(GLuint); }
# 5785 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLEMASKEXTPROC)(GLclampf, GLboolean); }
# 5786 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLEPATTERNEXTPROC)(GLenum); }
# 5810 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean, GLboolean, GLboolean, GLboolean); }
# 5818 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLIGLOOINTERFACESGIXPROC)(GLenum, const GLvoid *); }
# 5840 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEFENCESNVPROC)(GLsizei, const GLuint *); }
# 5841 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENFENCESNVPROC)(GLsizei, GLuint *); }
# 5842 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISFENCENVPROC)(GLuint); }
# 5843 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLTESTFENCENVPROC)(GLuint); }
# 5844 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFENCEIVNVPROC)(GLuint, GLenum, GLint *); }
# 5845 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFINISHFENCENVPROC)(GLuint); }
# 5846 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSETFENCENVPROC)(GLuint, GLenum); }
# 5862 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *); }
# 5863 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMAPPARAMETERIVNVPROC)(GLenum, GLenum, const GLint *); }
# 5864 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMAPPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
# 5865 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *); }
# 5866 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMAPPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
# 5867 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMAPPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 5868 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
# 5869 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
# 5870 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLEVALMAPSNVPROC)(GLenum, GLenum); }
# 5883 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
# 5884 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 5975 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei, const GLuint *, GLboolean *); }
# 5976 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDPROGRAMNVPROC)(GLenum, GLuint); }
# 5977 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEPROGRAMSNVPROC)(GLsizei, const GLuint *); }
# 5978 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLEXECUTEPROGRAMNVPROC)(GLenum, GLuint, const GLfloat *); }
# 5979 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENPROGRAMSNVPROC)(GLsizei, GLuint *); }
# 5980 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum, GLuint, GLenum, GLdouble *); }
# 5981 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
# 5982 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMIVNVPROC)(GLuint, GLenum, GLint *); }
# 5983 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGNVPROC)(GLuint, GLenum, GLubyte *); }
# 5984 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTRACKMATRIXIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
# 5985 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint, GLenum, GLdouble *); }
# 5986 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint, GLenum, GLfloat *); }
# 5987 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint, GLenum, GLint *); }
# 5988 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint, GLenum, GLvoid **); }
# 5989 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISPROGRAMNVPROC)(GLuint); }
# 5990 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLLOADPROGRAMNVPROC)(GLenum, GLuint, GLsizei, const GLubyte *); }
# 5991 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 5992 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum, GLuint, const GLdouble *); }
# 5993 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 5994 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum, GLuint, const GLfloat *); }
# 5995 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum, GLuint, GLuint, const GLdouble *); }
# 5996 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum, GLuint, GLuint, const GLfloat *); }
# 5997 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei, const GLuint *); }
# 5998 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTRACKMATRIXNVPROC)(GLenum, GLuint, GLenum, GLenum); }
# 5999 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
# 6000 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DNVPROC)(GLuint, GLdouble); }
# 6001 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVNVPROC)(GLuint, const GLdouble *); }
# 6002 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FNVPROC)(GLuint, GLfloat); }
# 6003 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVNVPROC)(GLuint, const GLfloat *); }
# 6004 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SNVPROC)(GLuint, GLshort); }
# 6005 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVNVPROC)(GLuint, const GLshort *); }
# 6006 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DNVPROC)(GLuint, GLdouble, GLdouble); }
# 6007 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVNVPROC)(GLuint, const GLdouble *); }
# 6008 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FNVPROC)(GLuint, GLfloat, GLfloat); }
# 6009 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVNVPROC)(GLuint, const GLfloat *); }
# 6010 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SNVPROC)(GLuint, GLshort, GLshort); }
# 6011 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVNVPROC)(GLuint, const GLshort *); }
# 6012 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 6013 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVNVPROC)(GLuint, const GLdouble *); }
# 6014 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 6015 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVNVPROC)(GLuint, const GLfloat *); }
# 6016 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SNVPROC)(GLuint, GLshort, GLshort, GLshort); }
# 6017 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVNVPROC)(GLuint, const GLshort *); }
# 6018 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 6019 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVNVPROC)(GLuint, const GLdouble *); }
# 6020 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 6021 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVNVPROC)(GLuint, const GLfloat *); }
# 6022 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SNVPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 6023 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVNVPROC)(GLuint, const GLshort *); }
# 6024 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBNVPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 6025 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint, const GLubyte *); }
# 6026 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 6027 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 6028 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 6029 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 6030 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 6031 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 6032 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 6033 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 6034 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 6035 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 6036 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 6037 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 6038 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint, GLsizei, const GLubyte *); }
# 6073 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum, const GLint *); }
# 6074 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum, const GLfloat *); }
# 6075 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum, GLint *); }
# 6076 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum, GLfloat *); }
# 6097 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint); }
# 6098 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint); }
# 6099 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint); }
# 6100 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINFRAGMENTSHADERATIPROC)(void); }
# 6101 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDFRAGMENTSHADERATIPROC)(void); }
# 6102 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPASSTEXCOORDATIPROC)(GLuint, GLuint, GLenum); }
# 6103 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSAMPLEMAPATIPROC)(GLuint, GLuint, GLenum); }
# 6104 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6105 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6106 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6107 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6108 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6109 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6110 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint, const GLfloat *); }
# 6119 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPNTRIANGLESIATIPROC)(GLenum, GLint); }
# 6120 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPNTRIANGLESFATIPROC)(GLenum, GLfloat); }
# 6139 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei, const GLvoid *, GLenum); }
# 6140 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISOBJECTBUFFERATIPROC)(GLuint); }
# 6141 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint, GLuint, GLsizei, const GLvoid *, GLenum); }
# 6142 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 6143 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint, GLenum, GLint *); }
# 6144 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFREEOBJECTBUFFERATIPROC)(GLuint); }
# 6145 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLARRAYOBJECTATIPROC)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint); }
# 6146 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETARRAYOBJECTFVATIPROC)(GLenum, GLenum, GLfloat *); }
# 6147 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETARRAYOBJECTIVATIPROC)(GLenum, GLenum, GLint *); }
# 6148 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint, GLenum, GLsizei, GLuint, GLuint); }
# 6149 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 6150 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 6199 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINVERTEXSHADEREXTPROC)(void); }
# 6200 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDVERTEXSHADEREXTPROC)(void); }
# 6201 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDVERTEXSHADEREXTPROC)(GLuint); }
# 6202 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLGENVERTEXSHADERSEXTPROC)(GLuint); }
# 6203 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint); }
# 6204 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHADEROP1EXTPROC)(GLenum, GLuint, GLuint); }
# 6205 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHADEROP2EXTPROC)(GLenum, GLuint, GLuint, GLuint); }
# 6206 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSHADEROP3EXTPROC)(GLenum, GLuint, GLuint, GLuint, GLuint); }
# 6207 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSWIZZLEEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
# 6208 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLWRITEMASKEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
# 6209 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLINSERTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
# 6210 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
# 6211 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLGENSYMBOLSEXTPROC)(GLenum, GLenum, GLenum, GLuint); }
# 6212 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSETINVARIANTEXTPROC)(GLuint, GLenum, const GLvoid *); }
# 6213 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSETLOCALCONSTANTEXTPROC)(GLuint, GLenum, const GLvoid *); }
# 6214 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTBVEXTPROC)(GLuint, const GLbyte *); }
# 6215 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTSVEXTPROC)(GLuint, const GLshort *); }
# 6216 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTIVEXTPROC)(GLuint, const GLint *); }
# 6217 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTFVEXTPROC)(GLuint, const GLfloat *); }
# 6218 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTDVEXTPROC)(GLuint, const GLdouble *); }
# 6219 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTUBVEXTPROC)(GLuint, const GLubyte *); }
# 6220 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTUSVEXTPROC)(GLuint, const GLushort *); }
# 6221 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTUIVEXTPROC)(GLuint, const GLuint *); }
# 6222 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVARIANTPOINTEREXTPROC)(GLuint, GLenum, GLuint, const GLvoid *); }
# 6223 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
# 6224 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
# 6225 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum, GLenum); }
# 6226 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum, GLenum); }
# 6227 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum, GLenum, GLenum); }
# 6228 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum, GLenum); }
# 6229 "sdk/GL/glext.h"
extern "C" { typedef GLuint (*PFNGLBINDPARAMETEREXTPROC)(GLenum); }
# 6230 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISVARIANTENABLEDEXTPROC)(GLuint, GLenum); }
# 6231 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6232 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6233 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6234 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint, GLenum, GLvoid **); }
# 6235 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6236 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6237 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6238 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6239 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6240 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6292 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1SATIPROC)(GLenum, GLshort); }
# 6293 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1SVATIPROC)(GLenum, const GLshort *); }
# 6294 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1IATIPROC)(GLenum, GLint); }
# 6295 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1IVATIPROC)(GLenum, const GLint *); }
# 6296 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1FATIPROC)(GLenum, GLfloat); }
# 6297 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1FVATIPROC)(GLenum, const GLfloat *); }
# 6298 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1DATIPROC)(GLenum, GLdouble); }
# 6299 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM1DVATIPROC)(GLenum, const GLdouble *); }
# 6300 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SATIPROC)(GLenum, GLshort, GLshort); }
# 6301 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SVATIPROC)(GLenum, const GLshort *); }
# 6302 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IATIPROC)(GLenum, GLint, GLint); }
# 6303 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IVATIPROC)(GLenum, const GLint *); }
# 6304 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FATIPROC)(GLenum, GLfloat, GLfloat); }
# 6305 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FVATIPROC)(GLenum, const GLfloat *); }
# 6306 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DATIPROC)(GLenum, GLdouble, GLdouble); }
# 6307 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DVATIPROC)(GLenum, const GLdouble *); }
# 6308 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
# 6309 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SVATIPROC)(GLenum, const GLshort *); }
# 6310 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
# 6311 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IVATIPROC)(GLenum, const GLint *); }
# 6312 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 6313 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
# 6314 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 6315 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
# 6316 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SATIPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 6317 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SVATIPROC)(GLenum, const GLshort *); }
# 6318 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IATIPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 6319 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IVATIPROC)(GLenum, const GLint *); }
# 6320 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 6321 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FVATIPROC)(GLenum, const GLfloat *); }
# 6322 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 6323 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DVATIPROC)(GLenum, const GLdouble *); }
# 6324 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3BATIPROC)(GLenum, GLbyte, GLbyte, GLbyte); }
# 6325 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3BVATIPROC)(GLenum, const GLbyte *); }
# 6326 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
# 6327 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3SVATIPROC)(GLenum, const GLshort *); }
# 6328 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
# 6329 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3IVATIPROC)(GLenum, const GLint *); }
# 6330 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 6331 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
# 6332 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 6333 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMALSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
# 6334 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum); }
# 6335 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXBLENDENVIATIPROC)(GLenum, GLint); }
# 6336 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXBLENDENVFATIPROC)(GLenum, GLfloat); }
# 6346 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLELEMENTPOINTERATIPROC)(GLenum, const GLvoid *); }
# 6347 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYATIPROC)(GLenum, GLsizei); }
# 6348 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum, GLuint, GLuint, GLsizei); }
# 6356 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWMESHARRAYSSUNPROC)(GLenum, GLint, GLsizei, GLsizei); }
# 6382 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei, GLuint *); }
# 6383 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei, const GLuint *); }
# 6384 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISOCCLUSIONQUERYNVPROC)(GLuint); }
# 6385 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint); }
# 6386 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDOCCLUSIONQUERYNVPROC)(void); }
# 6387 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint, GLenum, GLint *); }
# 6388 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint, GLenum, GLuint *); }
# 6397 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERINVPROC)(GLenum, GLint); }
# 6398 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVNVPROC)(GLenum, const GLint *); }
# 6418 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLACTIVESTENCILFACEEXTPROC)(GLenum); }
# 6438 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLELEMENTPOINTERAPPLEPROC)(GLenum, const GLvoid *); }
# 6439 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum, GLint, GLsizei); }
# 6440 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, GLint, GLsizei); }
# 6441 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum, const GLint *, const GLsizei *, GLsizei); }
# 6442 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei); }
# 6457 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENFENCESAPPLEPROC)(GLsizei, GLuint *); }
# 6458 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEFENCESAPPLEPROC)(GLsizei, const GLuint *); }
# 6459 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSETFENCEAPPLEPROC)(GLuint); }
# 6460 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISFENCEAPPLEPROC)(GLuint); }
# 6461 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLTESTFENCEAPPLEPROC)(GLuint); }
# 6462 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFINISHFENCEAPPLEPROC)(GLuint); }
# 6463 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLTESTOBJECTAPPLEPROC)(GLenum, GLuint); }
# 6464 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFINISHOBJECTAPPLEPROC)(GLenum, GLint); }
# 6475 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint); }
# 6476 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
# 6477 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
# 6478 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISVERTEXARRAYAPPLEPROC)(GLuint); }
# 6488 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei, GLvoid *); }
# 6489 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei, GLvoid *); }
# 6490 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum, GLint); }
# 6506 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWBUFFERSATIPROC)(GLsizei, const GLenum *); }
# 6539 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat); }
# 6540 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble); }
# 6541 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLfloat *); }
# 6542 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLdouble *); }
# 6543 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat *); }
# 6544 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble *); }
# 6597 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX2HNVPROC)(GLhalfNV, GLhalfNV); }
# 6598 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX2HVNVPROC)(const GLhalfNV *); }
# 6599 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
# 6600 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX3HVNVPROC)(const GLhalfNV *); }
# 6601 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6602 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEX4HVNVPROC)(const GLhalfNV *); }
# 6603 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMAL3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
# 6604 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLNORMAL3HVNVPROC)(const GLhalfNV *); }
# 6605 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
# 6606 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR3HVNVPROC)(const GLhalfNV *); }
# 6607 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6608 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLOR4HVNVPROC)(const GLhalfNV *); }
# 6609 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD1HNVPROC)(GLhalfNV); }
# 6610 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD1HVNVPROC)(const GLhalfNV *); }
# 6611 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2HNVPROC)(GLhalfNV, GLhalfNV); }
# 6612 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD2HVNVPROC)(const GLhalfNV *); }
# 6613 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
# 6614 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD3HVNVPROC)(const GLhalfNV *); }
# 6615 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6616 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXCOORD4HVNVPROC)(const GLhalfNV *); }
# 6617 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HNVPROC)(GLenum, GLhalfNV); }
# 6618 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HVNVPROC)(GLenum, const GLhalfNV *); }
# 6619 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HNVPROC)(GLenum, GLhalfNV, GLhalfNV); }
# 6620 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HVNVPROC)(GLenum, const GLhalfNV *); }
# 6621 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HNVPROC)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6622 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HVNVPROC)(GLenum, const GLhalfNV *); }
# 6623 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HNVPROC)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6624 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HVNVPROC)(GLenum, const GLhalfNV *); }
# 6625 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDHNVPROC)(GLhalfNV); }
# 6626 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFOGCOORDHVNVPROC)(const GLhalfNV *); }
# 6627 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
# 6628 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalfNV *); }
# 6629 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHNVPROC)(GLhalfNV); }
# 6630 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalfNV *); }
# 6631 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HNVPROC)(GLuint, GLhalfNV); }
# 6632 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HVNVPROC)(GLuint, const GLhalfNV *); }
# 6633 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HNVPROC)(GLuint, GLhalfNV, GLhalfNV); }
# 6634 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HVNVPROC)(GLuint, const GLhalfNV *); }
# 6635 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HNVPROC)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6636 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HVNVPROC)(GLuint, const GLhalfNV *); }
# 6637 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HNVPROC)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
# 6638 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HVNVPROC)(GLuint, const GLhalfNV *); }
# 6639 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
# 6640 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
# 6641 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
# 6642 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
# 6651 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPIXELDATARANGENVPROC)(GLenum, GLsizei, GLvoid *); }
# 6652 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum); }
# 6661 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTNVPROC)(void); }
# 6662 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint); }
# 6679 "sdk/GL/glext.h"
extern "C" { typedef GLvoid *(*PFNGLMAPOBJECTBUFFERATIPROC)(GLuint); }
# 6680 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint); }
# 6689 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEATIPROC)(GLenum, GLenum, GLenum, GLenum); }
# 6690 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum, GLenum, GLint, GLuint); }
# 6700 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint); }
# 6701 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 6702 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 6714 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEPTHBOUNDSEXTPROC)(GLclampd, GLclampd); }
# 6726 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum, GLenum); }
# 6778 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISRENDERBUFFEREXTPROC)(GLuint); }
# 6779 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDRENDERBUFFEREXTPROC)(GLenum, GLuint); }
# 6780 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei, const GLuint *); }
# 6781 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei, GLuint *); }
# 6782 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum, GLenum, GLsizei, GLsizei); }
# 6783 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 6784 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISFRAMEBUFFEREXTPROC)(GLuint); }
# 6785 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum, GLuint); }
# 6786 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei, const GLuint *); }
# 6787 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei, GLuint *); }
# 6788 "sdk/GL/glext.h"
extern "C" { typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum); }
# 6789 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
# 6790 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
# 6791 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint, GLint); }
# 6792 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum, GLenum, GLenum, GLuint); }
# 6793 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
# 6794 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGENERATEMIPMAPEXTPROC)(GLenum); }
# 6802 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei, const GLvoid *); }
# 6815 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint, GLenum, GLint64EXT *); }
# 6816 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint, GLenum, GLuint64EXT *); }
# 6824 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXBUFFEREXTPROC)(GLenum, GLenum, GLuint); }
# 6842 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum); }
# 6843 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENDTRANSFORMFEEDBACKNVPROC)(void); }
# 6844 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLuint, const GLint *, GLenum); }
# 6845 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDBUFFERRANGENVPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr); }
# 6846 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDBUFFEROFFSETNVPROC)(GLenum, GLuint, GLuint, GLintptr); }
# 6847 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDBUFFERBASENVPROC)(GLenum, GLuint, GLuint); }
# 6848 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint, GLsizei, const GLint *, GLenum); }
# 6849 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLACTIVEVARYINGNVPROC)(GLuint, const GLchar *); }
# 6850 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETVARYINGLOCATIONNVPROC)(GLuint, const GLchar *); }
# 6851 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETACTIVEVARYINGNVPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *); }
# 6852 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint, GLuint, GLint *); }
# 6863 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEPTHRANGEDNVPROC)(GLdouble, GLdouble); }
# 6864 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLEARDEPTHDNVPROC)(GLdouble); }
# 6865 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDEPTHBOUNDSDNVPROC)(GLdouble, GLdouble); }
# 6898 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean); }
# 6899 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum, GLuint, GLboolean *); }
# 6900 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum, GLuint, GLint *); }
# 6901 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLENABLEINDEXEDEXTPROC)(GLenum, GLuint); }
# 6902 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDISABLEINDEXEDEXTPROC)(GLenum, GLuint); }
# 6903 "sdk/GL/glext.h"
extern "C" { typedef GLboolean (*PFNGLISENABLEDINDEXEDEXTPROC)(GLenum, GLuint); }
# 6916 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 6917 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, const GLuint *); }
# 6918 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLint *); }
# 6919 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLuint *); }
# 6920 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLEARCOLORIIEXTPROC)(GLint, GLint, GLint, GLint); }
# 6921 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLCLEARCOLORIUIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
# 6931 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORMBUFFEREXTPROC)(GLuint, GLint, GLuint); }
# 6932 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint, GLint); }
# 6933 "sdk/GL/glext.h"
extern "C" { typedef GLintptr (*PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint, GLint); }
# 6974 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETUNIFORMUIVEXTPROC)(GLuint, GLint, GLuint *); }
# 6975 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint, GLuint, const GLchar *); }
# 6976 "sdk/GL/glext.h"
extern "C" { typedef GLint (*PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint, const GLchar *); }
# 6977 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1UIEXTPROC)(GLint, GLuint); }
# 6978 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2UIEXTPROC)(GLint, GLuint, GLuint); }
# 6979 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3UIEXTPROC)(GLint, GLuint, GLuint, GLuint); }
# 6980 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4UIEXTPROC)(GLint, GLuint, GLuint, GLuint, GLuint); }
# 6981 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM1UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 6982 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM2UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 6983 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM3UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 6984 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLUNIFORM4UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 6985 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint, GLint); }
# 6986 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint, GLint, GLint); }
# 6987 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint, GLint, GLint, GLint); }
# 6988 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint, GLint, GLint, GLint, GLint); }
# 6989 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint, GLuint); }
# 6990 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint, GLuint, GLuint); }
# 6991 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
# 6992 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6993 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint, const GLint *); }
# 6994 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint, const GLint *); }
# 6995 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint, const GLint *); }
# 6996 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint, const GLint *); }
# 6997 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint, const GLuint *); }
# 6998 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint, const GLuint *); }
# 6999 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint, const GLuint *); }
# 7000 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint, const GLuint *); }
# 7001 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint, const GLbyte *); }
# 7002 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint, const GLshort *); }
# 7003 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint, const GLubyte *); }
# 7004 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint, const GLushort *); }
# 7005 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
# 7006 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint, GLenum, GLint *); }
# 7007 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint, GLenum, GLuint *); }
# 7019 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint, GLenum, GLint); }
# 7020 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum, GLenum, GLuint, GLint); }
# 7021 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum, GLenum, GLuint, GLint, GLint); }
# 7022 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum, GLenum, GLuint, GLint, GLenum); }
# 7030 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum, GLint); }
# 7053 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
# 7054 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
# 7055 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
# 7056 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 7057 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
# 7058 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
# 7059 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
# 7060 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
# 7061 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
# 7062 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 7063 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
# 7064 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
# 7065 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum, GLuint, GLint *); }
# 7066 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum, GLuint, GLuint *); }
# 7067 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum, GLuint, GLint *); }
# 7068 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum, GLuint, GLuint *); }
# 7078 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *); }
# 7079 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLint *); }
# 7080 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLuint *); }
# 7088 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei); }
# 7096 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei); }
# 7104 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLBLITFRAMEBUFFEREXTPROC)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum); }
# 7113 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum, GLint, GLsizei, GLsizei); }
# 7114 "sdk/GL/glext.h"
extern "C" { typedef void (*PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei); }
# 266 "shared/GL/glu.h"
class GLUnurbs;
# 267 "shared/GL/glu.h"
class GLUquadric;
# 268 "shared/GL/glu.h"
class GLUtesselator;
# 275 "shared/GL/glu.h"
extern "C" { typedef GLUnurbs GLUnurbsObj; }
# 276 "shared/GL/glu.h"
extern "C" { typedef GLUquadric GLUquadricObj; }
# 277 "shared/GL/glu.h"
extern "C" { typedef GLUtesselator GLUtesselatorObj; }
# 278 "shared/GL/glu.h"
extern "C" { typedef GLUtesselator GLUtriangulatorObj; }
# 283 "shared/GL/glu.h"
extern "C" { typedef void (*_GLUfuncptr)(void); }
# 285 "shared/GL/glu.h"
extern "C" void gluBeginCurve(GLUnurbs *);
# 286 "shared/GL/glu.h"
extern "C" void gluBeginPolygon(GLUtesselator *);
# 287 "shared/GL/glu.h"
extern "C" void gluBeginSurface(GLUnurbs *);
# 288 "shared/GL/glu.h"
extern "C" void gluBeginTrim(GLUnurbs *);
# 289 "shared/GL/glu.h"
extern "C" GLint gluBuild1DMipmapLevels(GLenum, GLint, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 290 "shared/GL/glu.h"
extern "C" GLint gluBuild1DMipmaps(GLenum, GLint, GLsizei, GLenum, GLenum, const void *);
# 291 "shared/GL/glu.h"
extern "C" GLint gluBuild2DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 292 "shared/GL/glu.h"
extern "C" GLint gluBuild2DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
# 293 "shared/GL/glu.h"
extern "C" GLint gluBuild3DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 294 "shared/GL/glu.h"
extern "C" GLint gluBuild3DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
# 295 "shared/GL/glu.h"
extern "C" GLboolean gluCheckExtension(const GLubyte *, const GLubyte *);
# 296 "shared/GL/glu.h"
extern "C" void gluCylinder(GLUquadric *, GLdouble, GLdouble, GLdouble, GLint, GLint);
# 297 "shared/GL/glu.h"
extern "C" void gluDeleteNurbsRenderer(GLUnurbs *);
# 298 "shared/GL/glu.h"
extern "C" void gluDeleteQuadric(GLUquadric *);
# 299 "shared/GL/glu.h"
extern "C" void gluDeleteTess(GLUtesselator *);
# 300 "shared/GL/glu.h"
extern "C" void gluDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint);
# 301 "shared/GL/glu.h"
extern "C" void gluEndCurve(GLUnurbs *);
# 302 "shared/GL/glu.h"
extern "C" void gluEndPolygon(GLUtesselator *);
# 303 "shared/GL/glu.h"
extern "C" void gluEndSurface(GLUnurbs *);
# 304 "shared/GL/glu.h"
extern "C" void gluEndTrim(GLUnurbs *);
# 305 "shared/GL/glu.h"
extern "C" const GLubyte *gluErrorString(GLenum);
# 306 "shared/GL/glu.h"
extern "C" void gluGetNurbsProperty(GLUnurbs *, GLenum, GLfloat *);
# 307 "shared/GL/glu.h"
extern "C" const GLubyte *gluGetString(GLenum);
# 308 "shared/GL/glu.h"
extern "C" void gluGetTessProperty(GLUtesselator *, GLenum, GLdouble *);
# 309 "shared/GL/glu.h"
extern "C" void gluLoadSamplingMatrices(GLUnurbs *, const GLfloat *, const GLfloat *, const GLint *);
# 310 "shared/GL/glu.h"
extern "C" void gluLookAt(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 311 "shared/GL/glu.h"
extern "C" GLUnurbs *gluNewNurbsRenderer();
# 312 "shared/GL/glu.h"
extern "C" GLUquadric *gluNewQuadric();
# 313 "shared/GL/glu.h"
extern "C" GLUtesselator *gluNewTess();
# 314 "shared/GL/glu.h"
extern "C" void gluNextContour(GLUtesselator *, GLenum);
# 315 "shared/GL/glu.h"
extern "C" void gluNurbsCallback(GLUnurbs *, GLenum, _GLUfuncptr);
# 316 "shared/GL/glu.h"
extern "C" void gluNurbsCallbackData(GLUnurbs *, GLvoid *);
# 317 "shared/GL/glu.h"
extern "C" void gluNurbsCallbackDataEXT(GLUnurbs *, GLvoid *);
# 318 "shared/GL/glu.h"
extern "C" void gluNurbsCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLenum);
# 319 "shared/GL/glu.h"
extern "C" void gluNurbsProperty(GLUnurbs *, GLenum, GLfloat);
# 320 "shared/GL/glu.h"
extern "C" void gluNurbsSurface(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLint, GLfloat *, GLint, GLint, GLenum);
# 321 "shared/GL/glu.h"
extern "C" void gluOrtho2D(GLdouble, GLdouble, GLdouble, GLdouble);
# 322 "shared/GL/glu.h"
extern "C" void gluPartialDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble);
# 323 "shared/GL/glu.h"
extern "C" void gluPerspective(GLdouble, GLdouble, GLdouble, GLdouble);
# 324 "shared/GL/glu.h"
extern "C" void gluPickMatrix(GLdouble, GLdouble, GLdouble, GLdouble, GLint *);
# 325 "shared/GL/glu.h"
extern "C" GLint gluProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
# 326 "shared/GL/glu.h"
extern "C" void gluPwlCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLenum);
# 327 "shared/GL/glu.h"
extern "C" void gluQuadricCallback(GLUquadric *, GLenum, _GLUfuncptr);
# 328 "shared/GL/glu.h"
extern "C" void gluQuadricDrawStyle(GLUquadric *, GLenum);
# 329 "shared/GL/glu.h"
extern "C" void gluQuadricNormals(GLUquadric *, GLenum);
# 330 "shared/GL/glu.h"
extern "C" void gluQuadricOrientation(GLUquadric *, GLenum);
# 331 "shared/GL/glu.h"
extern "C" void gluQuadricTexture(GLUquadric *, GLboolean);
# 332 "shared/GL/glu.h"
extern "C" GLint gluScaleImage(GLenum, GLsizei, GLsizei, GLenum, const void *, GLsizei, GLsizei, GLenum, GLvoid *);
# 333 "shared/GL/glu.h"
extern "C" void gluSphere(GLUquadric *, GLdouble, GLint, GLint);
# 334 "shared/GL/glu.h"
extern "C" void gluTessBeginContour(GLUtesselator *);
# 335 "shared/GL/glu.h"
extern "C" void gluTessBeginPolygon(GLUtesselator *, GLvoid *);
# 336 "shared/GL/glu.h"
extern "C" void gluTessCallback(GLUtesselator *, GLenum, _GLUfuncptr);
# 337 "shared/GL/glu.h"
extern "C" void gluTessEndContour(GLUtesselator *);
# 338 "shared/GL/glu.h"
extern "C" void gluTessEndPolygon(GLUtesselator *);
# 339 "shared/GL/glu.h"
extern "C" void gluTessNormal(GLUtesselator *, GLdouble, GLdouble, GLdouble);
# 340 "shared/GL/glu.h"
extern "C" void gluTessProperty(GLUtesselator *, GLenum, GLdouble);
# 341 "shared/GL/glu.h"
extern "C" void gluTessVertex(GLUtesselator *, GLdouble *, GLvoid *);
# 342 "shared/GL/glu.h"
extern "C" GLint gluUnProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
# 343 "shared/GL/glu.h"
extern "C" GLint gluUnProject4(GLdouble, GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble, GLdouble, GLdouble *, GLdouble *, GLdouble *, GLdouble *);
# 232 "sdk/GL/glut.h"
extern "C" { extern void *glutStrokeRoman; }
# 233 "sdk/GL/glut.h"
extern "C" { extern void *glutStrokeMonoRoman; }
# 240 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmap9By15; }
# 241 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmap8By13; }
# 242 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmapTimesRoman10; }
# 243 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmapTimesRoman24; }
# 244 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmapHelvetica10; }
# 245 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmapHelvetica12; }
# 246 "sdk/GL/glut.h"
extern "C" { extern void *glutBitmapHelvetica18; }
# 395 "sdk/GL/glut.h"
extern "C" void glutInit(int *, char **);
# 396 "sdk/GL/glut.h"
extern "C" void glutInitDisplayMode(unsigned);
# 398 "sdk/GL/glut.h"
extern "C" void glutInitDisplayString(const char *);
# 400 "sdk/GL/glut.h"
extern "C" void glutInitWindowPosition(int, int);
# 401 "sdk/GL/glut.h"
extern "C" void glutInitWindowSize(int, int);
# 402 "sdk/GL/glut.h"
extern "C" void glutMainLoop();
# 405 "sdk/GL/glut.h"
extern "C" int glutCreateWindow(const char *);
# 406 "sdk/GL/glut.h"
extern "C" int glutCreateSubWindow(int, int, int, int, int);
# 407 "sdk/GL/glut.h"
extern "C" void glutDestroyWindow(int);
# 408 "sdk/GL/glut.h"
extern "C" void glutPostRedisplay();
# 410 "sdk/GL/glut.h"
extern "C" void glutPostWindowRedisplay(int);
# 412 "sdk/GL/glut.h"
extern "C" void glutSwapBuffers();
# 413 "sdk/GL/glut.h"
extern "C" int glutGetWindow();
# 414 "sdk/GL/glut.h"
extern "C" void glutSetWindow(int);
# 415 "sdk/GL/glut.h"
extern "C" void glutSetWindowTitle(const char *);
# 416 "sdk/GL/glut.h"
extern "C" void glutSetIconTitle(const char *);
# 417 "sdk/GL/glut.h"
extern "C" void glutPositionWindow(int, int);
# 418 "sdk/GL/glut.h"
extern "C" void glutReshapeWindow(int, int);
# 419 "sdk/GL/glut.h"
extern "C" void glutPopWindow();
# 420 "sdk/GL/glut.h"
extern "C" void glutPushWindow();
# 421 "sdk/GL/glut.h"
extern "C" void glutIconifyWindow();
# 422 "sdk/GL/glut.h"
extern "C" void glutShowWindow();
# 423 "sdk/GL/glut.h"
extern "C" void glutHideWindow();
# 425 "sdk/GL/glut.h"
extern "C" void glutFullScreen();
# 426 "sdk/GL/glut.h"
extern "C" void glutSetCursor(int);
# 428 "sdk/GL/glut.h"
extern "C" void glutWarpPointer(int, int);
# 432 "sdk/GL/glut.h"
extern "C" void glutEstablishOverlay();
# 433 "sdk/GL/glut.h"
extern "C" void glutRemoveOverlay();
# 434 "sdk/GL/glut.h"
extern "C" void glutUseLayer(GLenum);
# 435 "sdk/GL/glut.h"
extern "C" void glutPostOverlayRedisplay();
# 437 "sdk/GL/glut.h"
extern "C" void glutPostWindowOverlayRedisplay(int);
# 439 "sdk/GL/glut.h"
extern "C" void glutShowOverlay();
# 440 "sdk/GL/glut.h"
extern "C" void glutHideOverlay();
# 444 "sdk/GL/glut.h"
extern "C" int glutCreateMenu(void (*)(int));
# 445 "sdk/GL/glut.h"
extern "C" void glutDestroyMenu(int);
# 446 "sdk/GL/glut.h"
extern "C" int glutGetMenu();
# 447 "sdk/GL/glut.h"
extern "C" void glutSetMenu(int);
# 448 "sdk/GL/glut.h"
extern "C" void glutAddMenuEntry(const char *, int);
# 449 "sdk/GL/glut.h"
extern "C" void glutAddSubMenu(const char *, int);
# 450 "sdk/GL/glut.h"
extern "C" void glutChangeToMenuEntry(int, const char *, int);
# 451 "sdk/GL/glut.h"
extern "C" void glutChangeToSubMenu(int, const char *, int);
# 452 "sdk/GL/glut.h"
extern "C" void glutRemoveMenuItem(int);
# 453 "sdk/GL/glut.h"
extern "C" void glutAttachMenu(int);
# 454 "sdk/GL/glut.h"
extern "C" void glutDetachMenu(int);
# 457 "sdk/GL/glut.h"
extern "C" void glutDisplayFunc(void (*)(void));
# 458 "sdk/GL/glut.h"
extern "C" void glutReshapeFunc(void (*)(int, int));
# 459 "sdk/GL/glut.h"
extern "C" void glutKeyboardFunc(void (*)(unsigned char, int, int));
# 460 "sdk/GL/glut.h"
extern "C" void glutMouseFunc(void (*)(int, int, int, int));
# 461 "sdk/GL/glut.h"
extern "C" void glutMotionFunc(void (*)(int, int));
# 462 "sdk/GL/glut.h"
extern "C" void glutPassiveMotionFunc(void (*)(int, int));
# 463 "sdk/GL/glut.h"
extern "C" void glutEntryFunc(void (*)(int));
# 464 "sdk/GL/glut.h"
extern "C" void glutVisibilityFunc(void (*)(int));
# 465 "sdk/GL/glut.h"
extern "C" void glutIdleFunc(void (*)(void));
# 466 "sdk/GL/glut.h"
extern "C" void glutTimerFunc(unsigned, void (*)(int), int);
# 467 "sdk/GL/glut.h"
extern "C" void glutMenuStateFunc(void (*)(int));
# 469 "sdk/GL/glut.h"
extern "C" void glutSpecialFunc(void (*)(int, int, int));
# 470 "sdk/GL/glut.h"
extern "C" void glutSpaceballMotionFunc(void (*)(int, int, int));
# 471 "sdk/GL/glut.h"
extern "C" void glutSpaceballRotateFunc(void (*)(int, int, int));
# 472 "sdk/GL/glut.h"
extern "C" void glutSpaceballButtonFunc(void (*)(int, int));
# 473 "sdk/GL/glut.h"
extern "C" void glutButtonBoxFunc(void (*)(int, int));
# 474 "sdk/GL/glut.h"
extern "C" void glutDialsFunc(void (*)(int, int));
# 475 "sdk/GL/glut.h"
extern "C" void glutTabletMotionFunc(void (*)(int, int));
# 476 "sdk/GL/glut.h"
extern "C" void glutTabletButtonFunc(void (*)(int, int, int, int));
# 478 "sdk/GL/glut.h"
extern "C" void glutMenuStatusFunc(void (*)(int, int, int));
# 479 "sdk/GL/glut.h"
extern "C" void glutOverlayDisplayFunc(void (*)(void));
# 481 "sdk/GL/glut.h"
extern "C" void glutWindowStatusFunc(void (*)(int));
# 484 "sdk/GL/glut.h"
extern "C" void glutKeyboardUpFunc(void (*)(unsigned char, int, int));
# 485 "sdk/GL/glut.h"
extern "C" void glutSpecialUpFunc(void (*)(int, int, int));
# 486 "sdk/GL/glut.h"
extern "C" void glutJoystickFunc(void (*)(unsigned, int, int, int), int);
# 492 "sdk/GL/glut.h"
extern "C" void glutSetColor(int, GLfloat, GLfloat, GLfloat);
# 493 "sdk/GL/glut.h"
extern "C" GLfloat glutGetColor(int, int);
# 494 "sdk/GL/glut.h"
extern "C" void glutCopyColormap(int);
# 497 "sdk/GL/glut.h"
extern "C" int glutGet(GLenum);
# 498 "sdk/GL/glut.h"
extern "C" int glutDeviceGet(GLenum);
# 501 "sdk/GL/glut.h"
extern "C" int glutExtensionSupported(const char *);
# 504 "sdk/GL/glut.h"
extern "C" int glutGetModifiers();
# 505 "sdk/GL/glut.h"
extern "C" int glutLayerGet(GLenum);
# 509 "sdk/GL/glut.h"
extern "C" void glutBitmapCharacter(void *, int);
# 510 "sdk/GL/glut.h"
extern "C" int glutBitmapWidth(void *, int);
# 511 "sdk/GL/glut.h"
extern "C" void glutStrokeCharacter(void *, int);
# 512 "sdk/GL/glut.h"
extern "C" int glutStrokeWidth(void *, int);
# 514 "sdk/GL/glut.h"
extern "C" int glutBitmapLength(void *, const unsigned char *);
# 515 "sdk/GL/glut.h"
extern "C" int glutStrokeLength(void *, const unsigned char *);
# 519 "sdk/GL/glut.h"
extern "C" void glutWireSphere(GLdouble, GLint, GLint);
# 520 "sdk/GL/glut.h"
extern "C" void glutSolidSphere(GLdouble, GLint, GLint);
# 521 "sdk/GL/glut.h"
extern "C" void glutWireCone(GLdouble, GLdouble, GLint, GLint);
# 522 "sdk/GL/glut.h"
extern "C" void glutSolidCone(GLdouble, GLdouble, GLint, GLint);
# 523 "sdk/GL/glut.h"
extern "C" void glutWireCube(GLdouble);
# 524 "sdk/GL/glut.h"
extern "C" void glutSolidCube(GLdouble);
# 525 "sdk/GL/glut.h"
extern "C" void glutWireTorus(GLdouble, GLdouble, GLint, GLint);
# 526 "sdk/GL/glut.h"
extern "C" void glutSolidTorus(GLdouble, GLdouble, GLint, GLint);
# 527 "sdk/GL/glut.h"
extern "C" void glutWireDodecahedron();
# 528 "sdk/GL/glut.h"
extern "C" void glutSolidDodecahedron();
# 529 "sdk/GL/glut.h"
extern "C" void glutWireTeapot(GLdouble);
# 530 "sdk/GL/glut.h"
extern "C" void glutSolidTeapot(GLdouble);
# 531 "sdk/GL/glut.h"
extern "C" void glutWireOctahedron();
# 532 "sdk/GL/glut.h"
extern "C" void glutSolidOctahedron();
# 533 "sdk/GL/glut.h"
extern "C" void glutWireTetrahedron();
# 534 "sdk/GL/glut.h"
extern "C" void glutSolidTetrahedron();
# 535 "sdk/GL/glut.h"
extern "C" void glutWireIcosahedron();
# 536 "sdk/GL/glut.h"
extern "C" void glutSolidIcosahedron();
# 540 "sdk/GL/glut.h"
extern "C" int glutVideoResizeGet(GLenum);
# 541 "sdk/GL/glut.h"
extern "C" void glutSetupVideoResizing();
# 542 "sdk/GL/glut.h"
extern "C" void glutStopVideoResizing();
# 543 "sdk/GL/glut.h"
extern "C" void glutVideoResize(int, int, int, int);
# 544 "sdk/GL/glut.h"
extern "C" void glutVideoPan(int, int, int, int);
# 547 "sdk/GL/glut.h"
extern "C" void glutReportErrors();
# 563 "sdk/GL/glut.h"
extern "C" void glutIgnoreKeyRepeat(int);
# 564 "sdk/GL/glut.h"
extern "C" void glutSetKeyRepeat(int);
# 565 "sdk/GL/glut.h"
extern "C" void glutForceJoystickFunc();
# 577 "sdk/GL/glut.h"
extern "C" void glutGameModeString(const char *);
# 578 "sdk/GL/glut.h"
extern "C" int glutEnterGameMode();
# 579 "sdk/GL/glut.h"
extern "C" void glutLeaveGameMode();
# 580 "sdk/GL/glut.h"
extern "C" int glutGameModeGet(GLenum);
# 86 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLSetGLDevice(int);
# 135 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGraphicsGLRegisterImage(cudaGraphicsResource **, GLuint, GLenum, unsigned);
# 173 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGraphicsGLRegisterBuffer(cudaGraphicsResource **, GLuint, unsigned);
# 201 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
enum cudaGLMapFlags {
# 203 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
cudaGLMapFlagsNone,
# 204 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
cudaGLMapFlagsReadOnly,
# 205 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
cudaGLMapFlagsWriteDiscard
# 206 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
};
# 235 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLRegisterBufferObject(GLuint);
# 264 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLMapBufferObject(void **, GLuint);
# 291 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLUnmapBufferObject(GLuint);
# 313 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLUnregisterBufferObject(GLuint);
# 351 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLSetBufferObjectMapFlags(GLuint, unsigned);
# 380 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLMapBufferObjectAsync(void **, GLuint, cudaStream_t);
# 407 "/usr/local/cuda3.2/cuda/bin/../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLUnmapBufferObjectAsync(GLuint, cudaStream_t);
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
# 26 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
extern "C" { typedef unsigned uint; }
# 29 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
struct SimParams {
# 30 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float3 colliderPos;
# 31 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float colliderRadius;
# 33 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float3 gravity;
# 34 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float globalDamping;
# 35 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float particleRadius;
# 37 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
uint3 gridSize;
# 38 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
uint numCells;
# 39 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float3 worldOrigin;
# 40 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float3 cellSize;
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
uint numBodies;
# 43 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
uint maxParticlesPerCell;
# 45 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float spring;
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float damping;
# 47 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float shear;
# 48 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float attraction;
# 49 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
float boundaryDamping;
# 50 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cuh"
};
# 36 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
static SimParams params;
# 40 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
void integrate(float4 *posArray, float4 *
# 41 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
velArray, float
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
deltaTime, uint
# 43 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
numParticles) ;
# 75 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) int3 calcGridPos(float3 p)
# 76 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 82 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
exit(___);}
# 85 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) uint calcGridHash(int3 gridPos)
# 86 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 91 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
exit(___);}
# 95 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
void calcHashD(uint *gridParticleHash, uint *
# 96 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
gridParticleIndex, float4 *
# 97 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
pos, uint
# 98 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
numParticles) ;
# 117 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
void reorderDataAndFindCellStartD(uint *cellStart, uint *
# 118 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
cellEnd, float4 *
# 119 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
sortedPos, float4 *
# 120 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
sortedVel, uint *
# 121 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
gridParticleHash, uint *
# 122 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
gridParticleIndex, float4 *
# 123 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 124 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldVel, uint
# 125 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
numParticles) ;
# 182 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) float3 collideSpheres(float3 posA, float3 posB, float3
# 183 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
velA, float3 velB, float
# 184 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
radiusA, float radiusB, float
# 185 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
attraction)
# 186 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 214 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
exit(___);}
# 220 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
__attribute__((unused)) float3 collideCell(int3 gridPos, uint
# 221 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
index, float3
# 222 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
pos, float3
# 223 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
vel, float4 *
# 224 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 225 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldVel, uint *
# 226 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
cellStart, uint *
# 227 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
cellEnd)
# 228 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{int volatile ___ = 1;
# 249 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
exit(___);}
# 253 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
void collideD(float4 *newVel, float4 *
# 254 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldPos, float4 *
# 255 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
oldVel, uint *
# 256 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
gridParticleIndex, uint *
# 257 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
cellStart, uint *
# 258 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
cellEnd, uint
# 259 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
numParticles) ;
# 33 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void cudaInit(int argc, char **argv)
# 34 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 35 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
int devID;
# 37 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 38 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
devID = cutilDeviceInit(argc, argv);
# 39 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
if (devID < 0) {
# 40 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
printf("exiting...\n");
# 41 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cutilExit(argc, argv);
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
exit(0);
# 43 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
}
# 44 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} else {
# 45 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
devID = cutGetMaxGflopsDeviceId();
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaSetDevice(devID);
# 47 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
}
# 48 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 50 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void cudaGLInit(int argc, char **argv)
# 51 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 53 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 54 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cutilDeviceInit(argc, argv);
# 55 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} else {
# 56 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaGLSetGLDevice(cutGetMaxGflopsDeviceId());
# 57 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
}
# 58 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 60 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void allocateArray(void **devPtr, size_t size)
# 61 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 62 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaMalloc(devPtr, size), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 62);
# 63 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 65 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void freeArray(void *devPtr)
# 66 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 67 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaFree(devPtr), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 67);
# 68 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 70 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void threadSync()
# 71 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 72 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaThreadSynchronize(), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 72);
# 73 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 75 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void copyArrayToDevice(void *device, const void *host, int offset, int size)
# 76 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 77 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaMemcpy(((char *)device) + offset, host, size, cudaMemcpyHostToDevice), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 77);
# 78 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 80 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void registerGLBufferObject(uint vbo, cudaGraphicsResource **cuda_vbo_resource)
# 81 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 82 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaGraphicsGLRegisterBuffer(cuda_vbo_resource, vbo, cudaGraphicsMapFlagsNone), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 83);
# 84 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 86 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void unregisterGLBufferObject(cudaGraphicsResource *cuda_vbo_resource)
# 87 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 88 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaGraphicsUnregisterResource(cuda_vbo_resource), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 88);
# 89 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 91 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void *mapGLBufferObject(cudaGraphicsResource **cuda_vbo_resource)
# 92 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 93 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
void *ptr;
# 94 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaGraphicsMapResources(1, cuda_vbo_resource, 0), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 94);
# 95 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
size_t num_bytes;
# 96 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaGraphicsResourceGetMappedPointer((void **)(&ptr), &num_bytes, *cuda_vbo_resource), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 97);
# 98 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
return ptr;
# 99 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 101 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void unmapGLBufferObject(cudaGraphicsResource *cuda_vbo_resource)
# 102 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 103 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaGraphicsUnmapResources(1, &cuda_vbo_resource, 0), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 103);
# 104 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 106 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void copyArrayFromDevice(void *host, const void *device, cudaGraphicsResource **
# 107 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cuda_vbo_resource, int size)
# 108 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 109 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
if (cuda_vbo_resource) {
# 110 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
device = (mapGLBufferObject(cuda_vbo_resource)); }
# 112 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaMemcpy(host, device, size, cudaMemcpyDeviceToHost), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 112);
# 114 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
if (cuda_vbo_resource) {
# 115 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
unmapGLBufferObject(*cuda_vbo_resource); }
# 116 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 118 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void setParameters(SimParams *hostParams)
# 119 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 121 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaMemcpyToSymbol(params, hostParams, sizeof(SimParams)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 121);
# 122 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 125 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { uint iDivUp(uint a, uint b) {
# 126 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
return ((a % b) != (0)) ? ((a / b) + (1)) : (a / b);
# 127 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 130 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void computeGridSize(uint n, uint blockSize, uint &numBlocks, uint &numThreads)
# 131 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 132 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numThreads = min(blockSize, n);
# 133 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numBlocks = iDivUp(n, numThreads);
# 134 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 136 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void integrateSystem(float *pos, float *
# 137 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
vel, float
# 138 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
deltaTime, uint
# 139 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numParticles)
# 140 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 141 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
uint numThreads, numBlocks;
# 142 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
computeGridSize(numParticles, 256, numBlocks, numThreads);
# 145 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : integrate((float4 *)pos, (float4 *)vel, deltaTime, numParticles);
# 151 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cutilCheckMsg("integrate kernel execution failed", "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 151);
# 152 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 154 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void calcHash(uint *gridParticleHash, uint *
# 155 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
gridParticleIndex, float *
# 156 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
pos, int
# 157 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numParticles)
# 158 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 159 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
uint numThreads, numBlocks;
# 160 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
computeGridSize(numParticles, 256, numBlocks, numThreads);
# 163 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : calcHashD(gridParticleHash, gridParticleIndex, (float4 *)pos, numParticles);
# 169 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cutilCheckMsg("Kernel execution failed", "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 169);
# 170 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 172 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void reorderDataAndFindCellStart(uint *cellStart, uint *
# 173 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cellEnd, float *
# 174 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
sortedPos, float *
# 175 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
sortedVel, uint *
# 176 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
gridParticleHash, uint *
# 177 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
gridParticleIndex, float *
# 178 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
oldPos, float *
# 179 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
oldVel, uint
# 180 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numParticles, uint
# 181 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numCells)
# 182 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 183 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
uint numThreads, numBlocks;
# 184 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
computeGridSize(numParticles, 256, numBlocks, numThreads);
# 187 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cudaSafeCall(cudaMemset(cellStart, 4294967295U, numCells * sizeof(uint)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 187);
# 194 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
uint smemSize = (sizeof(uint) * (numThreads + (1)));
# 195 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaConfigureCall(numBlocks, numThreads, smemSize) ? ((void)0) : reorderDataAndFindCellStartD(cellStart, cellEnd, (float4 *)sortedPos, (float4 *)sortedVel, gridParticleHash, gridParticleIndex, (float4 *)oldPos, (float4 *)oldVel, numParticles);
# 205 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cutilCheckMsg("Kernel execution failed: reorderDataAndFindCellStartD", "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 205);
# 211 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 213 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
extern "C" { void collide(float *newVel, float *
# 214 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
sortedPos, float *
# 215 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
sortedVel, uint *
# 216 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
gridParticleIndex, uint *
# 217 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cellStart, uint *
# 218 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cellEnd, uint
# 219 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numParticles, uint
# 220 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
numCells)
# 221 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
{
# 230 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
uint numThreads, numBlocks;
# 231 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
computeGridSize(numParticles, 64, numBlocks, numThreads);
# 234 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : collideD((float4 *)newVel, (float4 *)sortedPos, (float4 *)sortedVel, gridParticleIndex, cellStart, cellEnd, numParticles);
# 243 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
__cutilCheckMsg("Kernel execution failed", "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu", 243);
# 251 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu"
} }
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000337_00000000-3_particleSystem.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000337_00000000-3_particleSystem.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x2e33616475632f6c\n"
".quad 0x6f2f616475632f32,0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f\n"
".quad 0x6220322e33206363,0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3830\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x696c612e206d6172,0x38622e2034206e67\n"
".quad 0x72616475635f5f20,0x31315a5f5f667465,0x64697247636c6163,0x616f6c6636736f50\n"
".quad 0x20295d32315b3374,0x636c616331315a5f,0x36736f5064697247,0x28203374616f6c66\n"
".quad 0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e,0x31666d7261706164\n"
".quad 0x6c616331315a5f5f,0x736f506469724763,0x5b3374616f6c6636,0x2e090a0a295d3231\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5a5f5f6674657261,0x7247636c61633231,0x6934687361486469,0x315a5f202933746e\n"
".quad 0x697247636c616332,0x6e69346873614864,0x7261702e28203374,0x67696c612e206d61\n"
".quad 0x2038622e2034206e,0x6170616475635f5f,0x315a5f5f31666d72,0x697247636c616332\n"
".quad 0x6e69346873614864,0x0a295d32315b3374,0x62697369762e090a,0x636e75662e20656c\n"
".quad 0x6d617261702e2820,0x206e67696c612e20,0x5f5f2038622e2034,0x6674657261647563\n"
".quad 0x6c6f6334315a5f5f,0x656870536564696c,0x616f6c6636736572,0x5f535f535f533374\n"
".quad 0x295d32315b666666,0x6c6f6334315a5f20,0x656870536564696c,0x616f6c6636736572\n"
".quad 0x5f535f535f533374,0x61702e2820666666,0x696c612e206d6172,0x38622e2034206e67\n"
".quad 0x70616475635f5f20,0x5a5f5f31666d7261,0x64696c6c6f633431,0x7365726568705365\n"
".quad 0x533374616f6c6636,0x6666665f535f535f,0x702e202c5d32315b,0x6c612e206d617261\n"
".quad 0x622e2034206e6769,0x616475635f5f2038,0x5f5f32666d726170,0x696c6c6f6334315a\n"
".quad 0x6572656870536564,0x3374616f6c663673,0x66665f535f535f53,0x2e202c5d32315b66\n"
".quad 0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862,0x5f33666d72617061\n"
".quad 0x6c6c6f6334315a5f,0x7265687053656469,0x74616f6c66367365,0x665f535f535f5333\n"
".quad 0x202c5d32315b6666,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x34666d7261706164,0x6c6f6334315a5f5f,0x656870536564696c,0x616f6c6636736572\n"
".quad 0x5f535f535f533374,0x2c5d32315b666666,0x206d617261702e20,0x635f5f203233662e\n"
".quad 0x666d726170616475,0x6f6334315a5f5f35,0x6870536564696c6c,0x6f6c663673657265\n"
".quad 0x535f535f53337461,0x702e202c6666665f,0x33662e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f36666d726170,0x696c6c6f6334315a,0x6572656870536564,0x3374616f6c663673\n"
".quad 0x66665f535f535f53,0x617261702e202c66,0x5f203233662e206d,0x726170616475635f\n"
".quad 0x34315a5f5f37666d,0x536564696c6c6f63,0x6636736572656870,0x535f533374616f6c\n"
".quad 0x0a296666665f535f,0x62697369762e090a,0x636e75662e20656c,0x6d617261702e2820\n"
".quad 0x206e67696c612e20,0x5f5f2038622e2034,0x6674657261647563,0x6c6f6331315a5f5f\n"
".quad 0x6c6c65436564696c,0x66366a33746e6934,0x5f30533374616f6c,0x3474616f6c663650\n"
".quad 0x5f33536a505f3253,0x5a5f20295d32315b,0x64696c6c6f633131,0x6e69346c6c654365\n"
".quad 0x616f6c66366a3374,0x6636505f30533374,0x5f32533474616f6c,0x2e28205f33536a50\n"
".quad 0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862,0x5f31666d72617061\n"
".quad 0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69,0x505f30533374616f\n"
".quad 0x533474616f6c6636,0x5b5f33536a505f32,0x61702e202c5d3231,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f32666d7261,0x64696c6c6f633131,0x6e69346c6c654365\n"
".quad 0x616f6c66366a3374,0x6636505f30533374,0x5f32533474616f6c,0x2e202c5f33536a50\n"
".quad 0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862,0x5f33666d72617061\n"
".quad 0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69,0x505f30533374616f\n"
".quad 0x533474616f6c6636,0x5b5f33536a505f32,0x61702e202c5d3231,0x696c612e206d6172\n"
".quad 0x38622e2034206e67,0x70616475635f5f20,0x5a5f5f34666d7261,0x64696c6c6f633131\n"
".quad 0x6e69346c6c654365,0x616f6c66366a3374,0x6636505f30533374,0x5f32533474616f6c\n"
".quad 0x32315b5f33536a50,0x617261702e202c5d,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x31315a5f5f35666d,0x436564696c6c6f63,0x33746e69346c6c65,0x3374616f6c66366a\n"
".quad 0x6f6c6636505f3053,0x6a505f3253347461,0x61702e202c5f3353,0x3436752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f36666d7261,0x64696c6c6f633131,0x6e69346c6c654365\n"
".quad 0x616f6c66366a3374,0x6636505f30533374,0x5f32533474616f6c,0x2e202c5f33536a50\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5f37666d72617061,0x6c6c6f6331315a5f\n"
".quad 0x346c6c6543656469,0x6c66366a33746e69,0x505f30533374616f,0x533474616f6c6636\n"
".quad 0x2c5f33536a505f32,0x206d617261702e20,0x635f5f203436752e,0x666d726170616475\n"
".quad 0x6f6331315a5f5f38,0x6c65436564696c6c,0x366a33746e69346c,0x30533374616f6c66\n"
".quad 0x74616f6c6636505f,0x33536a505f325334,0x2d2f2f090a0a295f,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f\n"
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f3733333030,0x372d303030303030\n"
".quad 0x6c6369747261705f,0x2e6d657473795365,0x2820692e33707063,0x4263632f706d742f\n"
".quad 0x6f7842754a2e2349,0x2d2d2f2f090a2937,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2f2f090a0a2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x704f202f2f090a2d,0x090a3a736e6f6974,0x2d2d2d2d2d2d2f2f\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d,0x656772615420202f\n"
".quad 0x49202c7874703a74,0x30325f6d733a4153,0x6e6169646e45202c,0x2c656c7474696c3a\n"
".quad 0x7265746e696f5020,0x34363a657a695320,0x4f2d20202f2f090a,0x6d6974704f280933\n"
".quad 0x206e6f6974617a69,0x090a296c6576656c,0x0930672d20202f2f,0x6c20677562654428\n"
".quad 0x2f090a296c657665,0x2809326d2d20202f,0x612074726f706552,0x6569726f73697664\n"
".quad 0x2d2d2f2f090a2973,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x6c69662e090a0a2d,0x6f633c2209310965,0x696c2d646e616d6d,0x662e090a223e656e\n"
".quad 0x2f22093209656c69,0x78706d742f706d74,0x30303030305f7466,0x303030305f373333\n"
".quad 0x705f362d30303030,0x53656c6369747261,0x75632e6d65747379,0x70672e3265666164\n"
".quad 0x6c69662e090a2275,0x6f682f2209330965,0x6572646e612f656d,0x69736f7065722f77\n"
".quad 0x672f736569726f74,0x746f6c65636f7570,0x632f73747365742f,0x742f322e33616475\n"
".quad 0x7261702f73747365,0x702f73656c636974,0x73656c6369747261,0x2e6c656e72656b5f\n"
".quad 0x662e090a22687563,0x2f22093409656c69,0x2f62696c2f727375,0x5f3638782f636367\n"
".quad 0x78756e696c2d3436,0x342e342f756e672d,0x756c636e692f332e,0x65646474732f6564\n"
".quad 0x662e090a22682e66,0x2f22093509656c69,0x61636f6c2f727375,0x2e33616475632f6c\n"
".quad 0x622f616475632f32,0x6e692f2e2e2f6e69,0x72632f6564756c63,0x6563697665642f74\n"
".quad 0x656d69746e75725f,0x69662e090a22682e,0x752f22093609656c,0x6c61636f6c2f7273\n"
".quad 0x322e33616475632f,0x69622f616475632f,0x636e692f2e2e2f6e,0x736f682f6564756c\n"
".quad 0x656e696665645f74,0x662e090a22682e73,0x2f22093709656c69,0x61636f6c2f727375\n"
".quad 0x2e33616475632f6c,0x622f616475632f32,0x6e692f2e2e2f6e69,0x75622f6564756c63\n"
".quad 0x79745f6e69746c69,0x090a22682e736570,0x093809656c69662e,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x616475632f322e33,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x745f656369766564,0x0a22682e73657079,0x3909656c69662e09,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x5f7265766972642f,0x22682e7365707974,0x09656c69662e090a,0x7273752f22093031\n"
".quad 0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x61667275732f6564,0x73657079745f6563,0x69662e090a22682e,0x2f2209313109656c\n"
".quad 0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f32,0x6e692f2e2e2f6e69\n"
".quad 0x65742f6564756c63,0x79745f6572757478,0x090a22682e736570,0x323109656c69662e\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x6475632f322e3361,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x5f726f746365762f,0x22682e7365707974,0x09656c69662e090a\n"
".quad 0x7273752f22093331,0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x63697665642f6564,0x68636e75616c5f65,0x74656d617261705f\n"
".quad 0x090a22682e737265,0x343109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f,0x6f74732f7472632f\n"
".quad 0x616c635f65676172,0x2e090a22682e7373,0x09353109656c6966,0x6e692f7273752f22\n"
".quad 0x69622f6564756c63,0x73657079742f7374,0x69662e090a22682e,0x2f2209363109656c\n"
".quad 0x6c636e692f727375,0x656d69742f656475,0x69662e090a22682e,0x2f2209373109656c\n"
".quad 0x646e612f656d6f68,0x6f7065722f776572,0x736569726f746973,0x6c65636f7570672f\n"
".quad 0x73747365742f746f,0x322e33616475632f,0x702f73747365742f,0x73656c6369747261\n"
".quad 0x6c6369747261702f,0x656e72656b5f7365,0x2e090a2275632e6c,0x09383109656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f322e33,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x665f6e6f6d6d6f63,0x736e6f6974636e75,0x69662e090a22682e\n"
".quad 0x2f2209393109656c,0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f32\n"
".quad 0x6e692f2e2e2f6e69,0x616d2f6564756c63,0x74636e75665f6874,0x0a22682e736e6f69\n"
".quad 0x3209656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c,0x75632f322e336164\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x635f6874616d2f65,0x73746e6174736e6f\n"
".quad 0x69662e090a22682e,0x2f2209313209656c,0x61636f6c2f727375,0x2e33616475632f6c\n"
".quad 0x622f616475632f32,0x6e692f2e2e2f6e69,0x65642f6564756c63,0x6e75665f65636976\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209323209,0x2f6c61636f6c2f72\n"
".quad 0x2f322e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f,0x315f6d732f656475\n"
".quad 0x63696d6f74615f31,0x6f6974636e75665f,0x2e090a22682e736e,0x09333209656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f322e33,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x74615f32315f6d73,0x6e75665f63696d6f,0x682e736e6f697463\n"
".quad 0x656c69662e090a22,0x73752f2209343209,0x2f6c61636f6c2f72,0x2f322e3361647563\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x315f6d732f656475,0x656c62756f645f33\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09353209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x616475632f322e33,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x74615f30325f6d73,0x6e75665f63696d6f,0x682e736e6f697463,0x656c69662e090a22\n"
".quad 0x73752f2209363209,0x2f6c61636f6c2f72,0x2f322e3361647563,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x325f6d732f656475,0x6e6972746e695f30,0x0a22682e73636973\n"
".quad 0x3209656c69662e09,0x2f7273752f220937,0x75632f6c61636f6c,0x75632f322e336164\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6361667275732f65,0x6974636e75665f65\n"
".quad 0x090a22682e736e6f,0x383209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f,0x657275747865742f\n"
".quad 0x665f68637465665f,0x736e6f6974636e75,0x69662e090a22682e,0x2f2209393209656c\n"
".quad 0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f32,0x6e692f2e2e2f6e69\n"
".quad 0x616d2f6564756c63,0x74636e75665f6874,0x6c62645f736e6f69,0x22682e337874705f\n"
".quad 0x736e6f632e090a0a,0x6e67696c612e2074,0x702038622e203420,0x30315b736d617261\n"
".quad 0x762e090a0a3b5d34,0x2e20656c62697369,0x702e2820636e7566,0x6c612e206d617261\n"
".quad 0x622e2034206e6769,0x616475635f5f2038,0x315a5f5f66746572,0x697247636c616331\n"
".quad 0x6f6c6636736f5064,0x295d32315b337461,0x6c616331315a5f20,0x736f506469724763\n"
".quad 0x203374616f6c6636,0x206d617261702e28,0x34206e67696c612e,0x635f5f2038622e20\n"
".quad 0x666d726170616475,0x616331315a5f5f31,0x6f5064697247636c,0x3374616f6c663673\n"
".quad 0x7b090a295d32315b,0x2e206765722e090a,0x373c722520323375,0x6765722e090a3b3e\n"
".quad 0x6625203233662e20,0x2e090a3b3e33323c,0x3709373109636f6c,0x57444c240a300936\n"
".quad 0x5a5f5f6e69676562,0x7247636c61633131,0x6c6636736f506469,0x6c090a3a3374616f\n"
".quad 0x2e6d617261702e64,0x3166250920323366,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x636c616331315a5f,0x36736f5064697247,0x302b3374616f6c66,0x2e766f6d090a3b5d\n"
".quad 0x3266250920323366,0x090a3b316625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c33,0x31666d7261706164,0x6c616331315a5f5f,0x736f506469724763\n"
".quad 0x2b3374616f6c6636,0x766f6d090a3b5d34,0x662509203233662e,0x0a3b336625202c34\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3566,0x666d726170616475\n"
".quad 0x616331315a5f5f31,0x6f5064697247636c,0x3374616f6c663673,0x6f6d090a3b5d382b\n"
".quad 0x2509203233662e76,0x3b356625202c3666,0x3109636f6c2e090a,0x090a300939370937\n"
".quad 0x74736e6f632e646c,0x662509203233662e,0x617261705b202c37,0x0a3b5d36352b736d\n"
".quad 0x3233662e62757309,0x25202c3866250920,0x3b376625202c3466,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x61705b202c396625,0x5d38362b736d6172,0x722e766964090a3b\n"
".quad 0x2509203233662e6e,0x386625202c303166,0x090a3b396625202c,0x2e696d722e747663\n"
".quad 0x203233662e323366,0x25202c3131662509,0x7663090a3b303166,0x33732e697a722e74\n"
".quad 0x2509203233662e32,0x31316625202c3172,0x09636f6c2e090a3b,0x0a30093038093731\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x61705b202c323166,0x5d30362b736d6172\n"
".quad 0x662e627573090a3b,0x3331662509203233,0x25202c366625202c,0x646c090a3b323166\n"
".quad 0x662e74736e6f632e,0x3431662509203233,0x6d617261705b202c,0x090a3b5d32372b73\n"
".quad 0x662e6e722e766964,0x3531662509203233,0x202c33316625202c,0x63090a3b34316625\n"
".quad 0x662e696d722e7476,0x09203233662e3233,0x6625202c36316625,0x747663090a3b3531\n"
".quad 0x3233732e697a722e,0x722509203233662e,0x3b36316625202c32,0x3109636f6c2e090a\n"
".quad 0x090a300931380937,0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3731\n"
".quad 0x3b5d32352b736d61,0x33662e627573090a,0x2c38316625092032,0x6625202c32662520\n"
".quad 0x2e646c090a3b3731,0x33662e74736e6f63,0x2c39316625092032,0x736d617261705b20\n"
".quad 0x64090a3b5d34362b,0x33662e6e722e7669,0x2c30326625092032,0x25202c3831662520\n"
".quad 0x7663090a3b393166,0x33662e696d722e74,0x2509203233662e32,0x326625202c313266\n"
".quad 0x2e747663090a3b30,0x2e3233732e697a72,0x3372250920323366,0x0a3b31326625202c\n"
".quad 0x617261702e747309,0x5b09203233732e6d,0x6572616475635f5f,0x6331315a5f5f6674\n"
".quad 0x5064697247636c61,0x74616f6c6636736f,0x7225202c5d302b33,0x2e766f6d090a3b33\n"
".quad 0x3472250920323373,0x090a3b317225202c,0x6d617261702e7473,0x5f5b09203233732e\n"
".quad 0x746572616475635f,0x616331315a5f5f66,0x6f5064697247636c,0x3374616f6c663673\n"
".quad 0x347225202c5d342b,0x732e766f6d090a3b,0x2c35722509203233,0x73090a3b32722520\n"
".quad 0x2e6d617261702e74,0x5f5f5b0920323373,0x6674657261647563,0x6c616331315a5f5f\n"
".quad 0x736f506469724763,0x2b3374616f6c6636,0x3b357225202c5d38,0x240a3b746572090a\n"
".quad 0x5f5f646e6557444c,0x47636c616331315a,0x6636736f50646972,0x090a3a3374616f6c\n"
".quad 0x315a5f202f2f207d,0x697247636c616331,0x6f6c6636736f5064,0x762e090a0a337461\n"
".quad 0x2e20656c62697369,0x702e2820636e7566,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x315a5f5f66746572,0x697247636c616332,0x6e69346873614864,0x32315a5f20293374\n"
".quad 0x64697247636c6163,0x746e693468736148,0x617261702e282033,0x6e67696c612e206d\n"
".quad 0x5f2038622e203420,0x726170616475635f,0x32315a5f5f31666d,0x64697247636c6163\n"
".quad 0x746e693468736148,0x090a295d32315b33,0x206765722e090a7b,0x3c7225203233752e\n"
".quad 0x6c2e090a3b3e3232,0x363809373109636f,0x6257444c240a3009,0x315a5f5f6e696765\n"
".quad 0x697247636c616332,0x6e69346873614864,0x2e646c090a3a3374,0x33752e6d61726170\n"
".quad 0x202c317225092032,0x70616475635f5f5b,0x5a5f5f31666d7261,0x7247636c61633231\n"
".quad 0x6934687361486469,0x0a3b5d302b33746e,0x3233732e766f6d09,0x25202c3272250920\n"
".quad 0x2e646c090a3b3172,0x33752e6d61726170,0x202c337225092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f31666d7261,0x7247636c61633231,0x6934687361486469,0x0a3b5d342b33746e\n"
".quad 0x3233732e766f6d09,0x25202c3472250920,0x2e646c090a3b3372,0x33752e6d61726170\n"
".quad 0x202c357225092032,0x70616475635f5f5b,0x5a5f5f31666d7261,0x7247636c61633231\n"
".quad 0x6934687361486469,0x0a3b5d382b33746e,0x3233732e766f6d09,0x25202c3672250920\n"
".quad 0x6f6c2e090a3b3572,0x0937380937310963,0x6f632e646c090a30,0x203233752e74736e\n"
".quad 0x705b202c37722509,0x36332b736d617261,0x2e627573090a3b5d,0x3872250920323375\n"
".quad 0x31202c377225202c,0x622e646e61090a3b,0x2c39722509203233,0x7225202c32722520\n"
".quad 0x636f6c2e090a3b38,0x3009383809373109,0x6e6f632e646c090a,0x09203233752e7473\n"
".quad 0x705b202c30317225,0x30342b736d617261,0x2e627573090a3b5d,0x3172250920323375\n"
".quad 0x2c30317225202c31,0x646e61090a3b3120,0x722509203233622e,0x2c347225202c3231\n"
".quad 0x090a3b3131722520,0x09373109636f6c2e,0x756d090a30093039,0x752e6f6c2e34326c\n"
".quad 0x3331722509203233,0x202c32317225202c,0x646c090a3b377225,0x752e74736e6f632e\n"
".quad 0x3431722509203233,0x6d617261705b202c,0x090a3b5d34342b73,0x203233752e627573\n"
".quad 0x25202c3531722509,0x0a3b31202c343172,0x3233622e646e6109,0x202c363172250920\n"
".quad 0x317225202c367225,0x326c756d090a3b35,0x3233752e6f6c2e34,0x202c373172250920\n"
".quad 0x7225202c36317225,0x6c756d090a3b3031,0x33752e6f6c2e3432,0x2c38317225092032\n"
".quad 0x25202c3731722520,0x646461090a3b3772,0x722509203233752e,0x33317225202c3931\n"
".quad 0x0a3b38317225202c,0x3233752e64646109,0x202c303272250920,0x317225202c397225\n"
".quad 0x702e7473090a3b39,0x3233752e6d617261,0x6475635f5f5b0920,0x5a5f5f6674657261\n"
".quad 0x7247636c61633231,0x6934687361486469,0x7225202c5d33746e,0x746572090a3b3032\n"
".quad 0x6e6557444c240a3b,0x616332315a5f5f64,0x614864697247636c,0x3a33746e69346873\n"
".quad 0x5f202f2f207d090a,0x47636c616332315a,0x3468736148646972,0x2e090a0a33746e69\n"
".quad 0x20656c6269736976,0x2e2820636e75662e,0x612e206d61726170,0x2e2034206e67696c\n"
".quad 0x6475635f5f203862,0x5a5f5f6674657261,0x64696c6c6f633431,0x7365726568705365\n"
".quad 0x533374616f6c6636,0x6666665f535f535f,0x5a5f20295d32315b,0x64696c6c6f633431\n"
".quad 0x7365726568705365,0x533374616f6c6636,0x6666665f535f535f,0x6d617261702e2820\n"
".quad 0x206e67696c612e20,0x5f5f2038622e2034,0x6d72617061647563,0x6334315a5f5f3166\n"
".quad 0x70536564696c6c6f,0x6c66367365726568,0x5f535f533374616f,0x32315b6666665f53\n"
".quad 0x617261702e202c5d,0x6e67696c612e206d,0x5f2038622e203420,0x726170616475635f\n"
".quad 0x34315a5f5f32666d,0x536564696c6c6f63,0x6636736572656870,0x535f533374616f6c\n"
".quad 0x315b6666665f535f,0x7261702e202c5d32,0x67696c612e206d61,0x2038622e2034206e\n"
".quad 0x6170616475635f5f,0x315a5f5f33666d72,0x6564696c6c6f6334,0x3673657265687053\n"
".quad 0x5f533374616f6c66,0x5b6666665f535f53,0x61702e202c5d3231,0x696c612e206d6172\n"
".quad 0x38622e2034206e67,0x70616475635f5f20,0x5a5f5f34666d7261,0x64696c6c6f633431\n"
".quad 0x7365726568705365,0x533374616f6c6636,0x6666665f535f535f,0x702e202c5d32315b\n"
".quad 0x33662e206d617261,0x616475635f5f2032,0x5f5f35666d726170,0x696c6c6f6334315a\n"
".quad 0x6572656870536564,0x3374616f6c663673,0x66665f535f535f53,0x617261702e202c66\n"
".quad 0x5f203233662e206d,0x726170616475635f,0x34315a5f5f36666d,0x536564696c6c6f63\n"
".quad 0x6636736572656870,0x535f533374616f6c,0x202c6666665f535f,0x2e206d617261702e\n"
".quad 0x75635f5f20323366,0x37666d7261706164,0x6c6f6334315a5f5f,0x656870536564696c\n"
".quad 0x616f6c6636736572,0x5f535f535f533374,0x0a7b090a29666666,0x662e206765722e09\n"
".quad 0x31383c6625203233,0x6765722e090a3b3e,0x2520646572702e20,0x2e090a3b3e333c70\n"
".quad 0x3109373109636f6c,0x444c240a30093638,0x5f5f6e6967656257,0x696c6c6f6334315a\n"
".quad 0x6572656870536564,0x3374616f6c663673,0x66665f535f535f53,0x702e646c090a3a66\n"
".quad 0x3233662e6d617261,0x5b202c3166250920,0x6170616475635f5f,0x315a5f5f31666d72\n"
".quad 0x6564696c6c6f6334,0x3673657265687053,0x5f533374616f6c66,0x2b6666665f535f53\n"
".quad 0x766f6d090a3b5d30,0x662509203233662e,0x0a3b316625202c32,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x635f5f5b202c3366,0x666d726170616475,0x6f6334315a5f5f31\n"
".quad 0x6870536564696c6c,0x6f6c663673657265,0x535f535f53337461,0x3b5d342b6666665f\n"
".quad 0x33662e766f6d090a,0x202c346625092032,0x646c090a3b336625,0x662e6d617261702e\n"
".quad 0x2c35662509203233,0x616475635f5f5b20,0x5f5f31666d726170,0x696c6c6f6334315a\n"
".quad 0x6572656870536564,0x3374616f6c663673,0x66665f535f535f53,0x6d090a3b5d382b66\n"
".quad 0x09203233662e766f,0x356625202c366625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c37662509,0x726170616475635f,0x34315a5f5f32666d,0x536564696c6c6f63\n"
".quad 0x6636736572656870,0x535f533374616f6c,0x302b6666665f535f,0x2e766f6d090a3b5d\n"
".quad 0x3866250920323366,0x090a3b376625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x75635f5f5b202c39,0x32666d7261706164,0x6c6f6334315a5f5f,0x656870536564696c\n"
".quad 0x616f6c6636736572,0x5f535f535f533374,0x0a3b5d342b666666,0x3233662e766f6d09\n"
".quad 0x202c303166250920,0x646c090a3b396625,0x662e6d617261702e,0x3131662509203233\n"
".quad 0x6475635f5f5b202c,0x5f32666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d382b6666,0x203233662e766f6d\n"
".quad 0x25202c3231662509,0x646c090a3b313166,0x662e6d617261702e,0x3331662509203233\n"
".quad 0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d302b6666,0x203233662e766f6d\n"
".quad 0x25202c3431662509,0x646c090a3b333166,0x662e6d617261702e,0x3531662509203233\n"
".quad 0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d342b6666,0x203233662e766f6d\n"
".quad 0x25202c3631662509,0x646c090a3b353166,0x662e6d617261702e,0x3731662509203233\n"
".quad 0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d382b6666,0x203233662e766f6d\n"
".quad 0x25202c3831662509,0x646c090a3b373166,0x662e6d617261702e,0x3931662509203233\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d302b6666,0x203233662e766f6d\n"
".quad 0x25202c3032662509,0x646c090a3b393166,0x662e6d617261702e,0x3132662509203233\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d342b6666,0x203233662e766f6d\n"
".quad 0x25202c3232662509,0x646c090a3b313266,0x662e6d617261702e,0x3332662509203233\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x090a3b5d382b6666,0x203233662e766f6d\n"
".quad 0x25202c3432662509,0x646c090a3b333266,0x662e6d617261702e,0x3532662509203233\n"
".quad 0x6475635f5f5b202c,0x5f35666d72617061,0x6c6c6f6334315a5f,0x7265687053656469\n"
".quad 0x74616f6c66367365,0x665f535f535f5333,0x6f6d090a3b5d6666,0x2509203233662e76\n"
".quad 0x326625202c363266,0x702e646c090a3b35,0x3233662e6d617261,0x202c373266250920\n"
".quad 0x70616475635f5f5b,0x5a5f5f36666d7261,0x64696c6c6f633431,0x7365726568705365\n"
".quad 0x533374616f6c6636,0x6666665f535f535f,0x2e766f6d090a3b5d,0x3266250920323366\n"
".quad 0x3b37326625202c38,0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c39326625\n"
".quad 0x726170616475635f,0x34315a5f5f37666d,0x536564696c6c6f63,0x6636736572656870\n"
".quad 0x535f533374616f6c,0x3b5d6666665f535f,0x33662e766f6d090a,0x2c30336625092032\n"
".quad 0x090a3b3932662520,0x203233662e646461,0x25202c3133662509,0x326625202c363266\n"
".quad 0x2e627573090a3b38,0x3366250920323366,0x2c30316625202c32,0x73090a3b34662520\n"
".quad 0x09203233662e6275,0x6625202c33336625,0x0a3b326625202c38,0x3233662e62757309\n"
".quad 0x202c343366250920,0x6625202c32316625,0x2e6c756d090a3b36,0x3366250920323366\n"
".quad 0x2c32336625202c35,0x090a3b3233662520,0x662e6e722e616d66,0x3633662509203233\n"
".quad 0x202c33336625202c,0x6625202c33336625,0x616d66090a3b3533,0x203233662e6e722e\n"
".quad 0x25202c3733662509,0x336625202c343366,0x3b36336625202c34,0x722e74727173090a\n"
".quad 0x2509203233662e6e,0x336625202c383366,0x70746573090a3b37,0x203233662e74672e\n"
".quad 0x6625202c31702509,0x38336625202c3133,0x3170252140090a3b,0x4c24092061726220\n"
".quad 0x323832315f325f74,0x09636f6c2e090a3b,0x3009383032093731,0x33662e627573090a\n"
".quad 0x2c39336625092032,0x25202c3032662520,0x7573090a3b343166,0x2509203233662e62\n"
".quad 0x326625202c303466,0x3b36316625202c32,0x33662e627573090a,0x2c31346625092032\n"
".quad 0x25202c3432662520,0x6964090a3b383166,0x3233662e6e722e76,0x202c323466250920\n"
".quad 0x6625202c33336625,0x766964090a3b3833,0x203233662e6e722e,0x25202c3334662509\n"
".quad 0x336625202c323366,0x2e766964090a3b38,0x09203233662e6e72,0x6625202c34346625\n"
".quad 0x38336625202c3433,0x662e6c756d090a3b,0x3534662509203233,0x202c30346625202c\n"
".quad 0x66090a3b33346625,0x33662e6e722e616d,0x2c36346625092032,0x25202c3933662520\n"
".quad 0x346625202c323466,0x2e616d66090a3b35,0x09203233662e6e72,0x6625202c37346625\n"
".quad 0x34346625202c3134,0x0a3b36346625202c,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x61705b202c383466,0x5d32392b736d6172,0x662e6c756d090a3b,0x3934662509203233\n"
".quad 0x202c32346625202c,0x73090a3b37346625,0x09203233662e6275,0x6625202c30356625\n"
".quad 0x39346625202c3933,0x662e6c756d090a3b,0x3135662509203233,0x202c38346625202c\n"
".quad 0x6d090a3b30356625,0x09203233662e6c75,0x6625202c32356625,0x37346625202c3334\n"
".quad 0x662e627573090a3b,0x3335662509203233,0x202c30346625202c,0x6d090a3b32356625\n"
".quad 0x09203233662e6c75,0x6625202c34356625,0x33356625202c3834,0x662e6c756d090a3b\n"
".quad 0x3535662509203233,0x202c34346625202c,0x73090a3b37346625,0x09203233662e6275\n"
".quad 0x6625202c36356625,0x35356625202c3134,0x662e6c756d090a3b,0x3735662509203233\n"
".quad 0x202c38346625202c,0x2e090a3b36356625,0x3209373109636f6c,0x7573090a30093031\n"
".quad 0x2509203233662e62,0x336625202c383566,0x3b38336625202c31,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c39356625,0x34382b736d617261,0x2e6c756d090a3b5d\n"
".quad 0x3666250920323366,0x2c39356625202c30,0x090a3b3835662520,0x74736e6f632e646c\n"
".quad 0x662509203233662e,0x7261705b202c3136,0x3b5d38382b736d61,0x33662e6c756d090a\n"
".quad 0x2c32366625092032,0x25202c3234662520,0x756d090a3b303666,0x2509203233662e6c\n"
".quad 0x336625202c333666,0x3b31366625202c39,0x33662e627573090a,0x2c34366625092032\n"
".quad 0x25202c3336662520,0x6461090a3b323666,0x2509203233662e64,0x356625202c353666\n"
".quad 0x3b34366625202c31,0x6e722e616d66090a,0x662509203233662e,0x30336625202c3636\n"
".quad 0x202c33336625202c,0x6d090a3b35366625,0x09203233662e6c75,0x6625202c37366625\n"
".quad 0x30366625202c3334,0x662e6c756d090a3b,0x3836662509203233,0x202c30346625202c\n"
".quad 0x73090a3b31366625,0x09203233662e6275,0x6625202c39366625,0x37366625202c3836\n"
".quad 0x662e646461090a3b,0x3037662509203233,0x202c34356625202c,0x66090a3b39366625\n"
".quad 0x33662e6e722e616d,0x2c31376625092032,0x25202c3033662520,0x376625202c323366\n"
".quad 0x2e6c756d090a3b30,0x3766250920323366,0x2c34346625202c32,0x090a3b3036662520\n"
".quad 0x203233662e6c756d,0x25202c3337662509,0x366625202c313466,0x2e627573090a3b31\n"
".quad 0x3766250920323366,0x2c33376625202c34,0x090a3b3237662520,0x203233662e646461\n"
".quad 0x25202c3537662509,0x376625202c373566,0x2e616d66090a3b34,0x09203233662e6e72\n"
".quad 0x6625202c36376625,0x34336625202c3033,0x0a3b35376625202c,0x696e752e61726209\n"
".quad 0x5f325f744c240920,0x4c240a3b36323031,0x323832315f325f74,0x662e766f6d090a3a\n"
".quad 0x3637662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x30202c3137662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x30306630202c3636,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x315f325f744c240a,0x6c2e090a3a363230,0x313209373109636f\n"
".quad 0x766f6d090a300933,0x662509203233662e,0x36366625202c3737,0x61702e7473090a3b\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x315a5f5f66746572,0x6564696c6c6f6334\n"
".quad 0x3673657265687053,0x5f533374616f6c66,0x2b6666665f535f53,0x37376625202c5d30\n"
".quad 0x662e766f6d090a3b,0x3837662509203233,0x0a3b31376625202c,0x617261702e747309\n"
".quad 0x5b09203233662e6d,0x6572616475635f5f,0x6334315a5f5f6674,0x70536564696c6c6f\n"
".quad 0x6c66367365726568,0x5f535f533374616f,0x5d342b6666665f53,0x0a3b38376625202c\n"
".quad 0x3233662e766f6d09,0x202c393766250920,0x73090a3b36376625,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323366,0x6674657261647563,0x6c6f6334315a5f5f,0x656870536564696c\n"
".quad 0x616f6c6636736572,0x5f535f535f533374,0x202c5d382b666666,0x72090a3b39376625\n"
".quad 0x57444c240a3b7465,0x34315a5f5f646e65,0x536564696c6c6f63,0x6636736572656870\n"
".quad 0x535f533374616f6c,0x0a3a6666665f535f,0x5a5f202f2f207d09,0x64696c6c6f633431\n"
".quad 0x7365726568705365,0x533374616f6c6636,0x6666665f535f535f,0x697369762e090a0a\n"
".quad 0x6e75662e20656c62,0x617261702e282063,0x6e67696c612e206d,0x5f2038622e203420\n"
".quad 0x746572616475635f,0x6f6331315a5f5f66,0x6c65436564696c6c,0x366a33746e69346c\n"
".quad 0x30533374616f6c66,0x74616f6c6636505f,0x33536a505f325334,0x5f20295d32315b5f\n"
".quad 0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e,0x36505f3053337461\n"
".quad 0x32533474616f6c66,0x28205f33536a505f,0x2e206d617261702e,0x2034206e67696c61\n"
".quad 0x75635f5f2038622e,0x31666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c\n"
".quad 0x66366a33746e6934,0x5f30533374616f6c,0x3474616f6c663650,0x5f33536a505f3253\n"
".quad 0x702e202c5d32315b,0x33752e206d617261,0x616475635f5f2032,0x5f5f32666d726170\n"
".quad 0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e,0x36505f3053337461\n"
".quad 0x32533474616f6c66,0x202c5f33536a505f,0x2e206d617261702e,0x2034206e67696c61\n"
".quad 0x75635f5f2038622e,0x33666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c\n"
".quad 0x66366a33746e6934,0x5f30533374616f6c,0x3474616f6c663650,0x5f33536a505f3253\n"
".quad 0x702e202c5d32315b,0x6c612e206d617261,0x622e2034206e6769,0x616475635f5f2038\n"
".quad 0x5f5f34666d726170,0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e\n"
".quad 0x36505f3053337461,0x32533474616f6c66,0x315b5f33536a505f,0x7261702e202c5d32\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x315a5f5f35666d72,0x6564696c6c6f6331\n"
".quad 0x746e69346c6c6543,0x74616f6c66366a33,0x6c6636505f305333,0x505f32533474616f\n"
".quad 0x702e202c5f33536a,0x36752e206d617261,0x616475635f5f2034,0x5f5f36666d726170\n"
".quad 0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e,0x36505f3053337461\n"
".quad 0x32533474616f6c66,0x202c5f33536a505f,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x37666d7261706164,0x6c6f6331315a5f5f,0x6c6c65436564696c,0x66366a33746e6934\n"
".quad 0x5f30533374616f6c,0x3474616f6c663650,0x5f33536a505f3253,0x6d617261702e202c\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x6331315a5f5f3866,0x65436564696c6c6f\n"
".quad 0x6a33746e69346c6c,0x533374616f6c6636,0x616f6c6636505f30,0x536a505f32533474\n"
".quad 0x090a7b090a295f33,0x33752e206765722e,0x3e30333c72252032,0x206765722e090a3b\n"
".quad 0x647225203436752e,0x2e090a3b3e38313c,0x3233662e20676572,0x3b3e34373c662520\n"
".quad 0x2e206765722e090a,0x3c70252064657270,0x6f6c2e090a3b3e37,0x3832320937310963\n"
".quad 0x6257444c240a3009,0x315a5f5f6e696765,0x6564696c6c6f6331,0x746e69346c6c6543\n"
".quad 0x74616f6c66366a33,0x6c6636505f305333,0x505f32533474616f,0x6c090a3a5f33536a\n"
".quad 0x2e6d617261702e64,0x3172250920323375,0x6475635f5f5b202c,0x5f31666d72617061\n"
".quad 0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69,0x505f30533374616f\n"
".quad 0x533474616f6c6636,0x2b5f33536a505f32,0x766f6d090a3b5d30,0x722509203233732e\n"
".quad 0x0a3b317225202c32,0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3372\n"
".quad 0x666d726170616475,0x6f6331315a5f5f31,0x6c65436564696c6c,0x366a33746e69346c\n"
".quad 0x30533374616f6c66,0x74616f6c6636505f,0x33536a505f325334,0x6d090a3b5d342b5f\n"
".quad 0x09203233732e766f,0x337225202c347225,0x61702e646c090a3b,0x203233752e6d6172\n"
".quad 0x5f5b202c35722509,0x726170616475635f,0x31315a5f5f31666d,0x436564696c6c6f63\n"
".quad 0x33746e69346c6c65,0x3374616f6c66366a,0x6f6c6636505f3053,0x6a505f3253347461\n"
".quad 0x0a3b5d382b5f3353,0x3233732e766f6d09,0x25202c3672250920,0x2e646c090a3b3572\n"
".quad 0x33752e6d61726170,0x202c377225092032,0x70616475635f5f5b,0x5a5f5f32666d7261\n"
".quad 0x64696c6c6f633131,0x6e69346c6c654365,0x616f6c66366a3374,0x6636505f30533374\n"
".quad 0x5f32533474616f6c,0x0a3b5d5f33536a50,0x3233732e766f6d09,0x25202c3872250920\n"
".quad 0x2e646c090a3b3772,0x33662e6d61726170,0x202c316625092032,0x70616475635f5f5b\n"
".quad 0x5a5f5f33666d7261,0x64696c6c6f633131,0x6e69346c6c654365,0x616f6c66366a3374\n"
".quad 0x6636505f30533374,0x5f32533474616f6c,0x5d302b5f33536a50,0x662e766f6d090a3b\n"
".quad 0x2c32662509203233,0x6c090a3b31662520,0x2e6d617261702e64,0x3366250920323366\n"
".quad 0x6475635f5f5b202c,0x5f33666d72617061,0x6c6c6f6331315a5f,0x346c6c6543656469\n"
".quad 0x6c66366a33746e69,0x505f30533374616f,0x533474616f6c6636,0x2b5f33536a505f32\n"
".quad 0x766f6d090a3b5d34,0x662509203233662e,0x0a3b336625202c34,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x635f5f5b202c3566,0x666d726170616475,0x6f6331315a5f5f33\n"
".quad 0x6c65436564696c6c,0x366a33746e69346c,0x30533374616f6c66,0x74616f6c6636505f\n"
".quad 0x33536a505f325334,0x6d090a3b5d382b5f,0x09203233662e766f,0x356625202c366625\n"
".quad 0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c37662509,0x726170616475635f\n"
".quad 0x31315a5f5f34666d,0x436564696c6c6f63,0x33746e69346c6c65,0x3374616f6c66366a\n"
".quad 0x6f6c6636505f3053,0x6a505f3253347461,0x0a3b5d302b5f3353,0x3233662e766f6d09\n"
".quad 0x25202c3866250920,0x2e646c090a3b3766,0x33662e6d61726170,0x202c396625092032\n"
".quad 0x70616475635f5f5b,0x5a5f5f34666d7261,0x64696c6c6f633131,0x6e69346c6c654365\n"
".quad 0x616f6c66366a3374,0x6636505f30533374,0x5f32533474616f6c,0x5d342b5f33536a50\n"
".quad 0x662e766f6d090a3b,0x3031662509203233,0x090a3b396625202c,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x635f5f5b202c3131,0x666d726170616475,0x6f6331315a5f5f34\n"
".quad 0x6c65436564696c6c,0x366a33746e69346c,0x30533374616f6c66,0x74616f6c6636505f\n"
".quad 0x33536a505f325334,0x6d090a3b5d382b5f,0x09203233662e766f,0x6625202c32316625\n"
".quad 0x2e646c090a3b3131,0x36752e6d61726170,0x2c31647225092034,0x616475635f5f5b20\n"
".quad 0x5f5f35666d726170,0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e\n"
".quad 0x36505f3053337461,0x32533474616f6c66,0x3b5d5f33536a505f,0x36732e766f6d090a\n"
".quad 0x2c32647225092034,0x090a3b3164722520,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x635f5f5b202c3364,0x666d726170616475,0x6f6331315a5f5f36,0x6c65436564696c6c\n"
".quad 0x366a33746e69346c,0x30533374616f6c66,0x74616f6c6636505f,0x33536a505f325334\n"
".quad 0x766f6d090a3b5d5f,0x722509203436732e,0x33647225202c3464,0x61702e646c090a3b\n"
".quad 0x203436752e6d6172,0x5b202c3564722509,0x6170616475635f5f,0x315a5f5f37666d72\n"
".quad 0x6564696c6c6f6331,0x746e69346c6c6543,0x74616f6c66366a33,0x6c6636505f305333\n"
".quad 0x505f32533474616f,0x090a3b5d5f33536a,0x203436732e766f6d,0x25202c3664722509\n"
".quad 0x646c090a3b356472,0x752e6d617261702e,0x3764722509203436,0x6475635f5f5b202c\n"
".quad 0x5f38666d72617061,0x6c6c6f6331315a5f,0x346c6c6543656469,0x6c66366a33746e69\n"
".quad 0x505f30533374616f,0x533474616f6c6636,0x5d5f33536a505f32,0x732e766f6d090a3b\n"
".quad 0x3864722509203436,0x0a3b37647225202c,0x373109636f6c2e09,0x090a300932333209\n"
".quad 0x74736e6f632e646c,0x722509203233752e,0x617261705b202c39,0x0a3b5d30342b736d\n"
".quad 0x3233752e62757309,0x202c303172250920,0x0a3b31202c397225,0x736e6f632e646c09\n"
".quad 0x2509203233752e74,0x61705b202c313172,0x5d34342b736d6172,0x752e627573090a3b\n"
".quad 0x3231722509203233,0x202c31317225202c,0x632e646c090a3b31,0x3233752e74736e6f\n"
".quad 0x202c333172250920,0x2b736d617261705b,0x7573090a3b5d3633,0x2509203233752e62\n"
".quad 0x317225202c343172,0x61090a3b31202c33,0x09203233622e646e,0x7225202c35317225\n"
".quad 0x3b30317225202c34,0x33622e646e61090a,0x2c36317225092032,0x7225202c36722520\n"
".quad 0x646e61090a3b3231,0x722509203233622e,0x2c327225202c3731,0x090a3b3431722520\n"
".quad 0x6f6c2e34326c756d,0x722509203233752e,0x35317225202c3831,0x0a3b33317225202c\n"
".quad 0x6c2e34326c756d09,0x2509203233752e6f,0x317225202c393172,0x0a3b397225202c36\n"
".quad 0x6c2e34326c756d09,0x2509203233752e6f,0x317225202c303272,0x3b33317225202c39\n"
".quad 0x33752e646461090a,0x2c31327225092032,0x25202c3831722520,0x6461090a3b303272\n"
".quad 0x2509203233752e64,0x317225202c323272,0x3b31327225202c37,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x327225202c396472,0x2e6c756d090a3b32,0x3233752e65646977\n"
".quad 0x2c30316472250920,0x34202c3232722520,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x3031647225202c31,0x0a3b36647225202c,0x203233752e646c09,0x5b202c3332722509\n"
".quad 0x5d302b3131647225,0x752e766f6d090a3b,0x3432722509203233,0x73090a3b312d202c\n"
".quad 0x752e71652e707465,0x2c31702509203233,0x25202c3332722520,0x2540090a3b343272\n"
".quad 0x0920617262203170,0x38335f335f744c24,0x6f6c2e090a3b3234,0x3733320937310963\n"
".quad 0x2e646461090a3009,0x6472250920343675,0x31647225202c3231,0x3b38647225202c30\n"
".quad 0x3233752e646c090a,0x202c353272250920,0x302b32316472255b,0x636f6c2e090a3b5d\n"
".quad 0x0938333209373109,0x732e766f6d090a30,0x3632722509203233,0x0a3b33327225202c\n"
".quad 0x65672e7074657309,0x702509203233752e,0x2c33327225202c32,0x090a3b3532722520\n"
".quad 0x6172622032702540,0x5f335f744c240920,0x73090a3b36343136,0x09203233752e6275\n"
".quad 0x7225202c37327225,0x33327225202c3532,0x662e766f6d090a3b,0x3331662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x30202c3431662509,0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x30306630202c3531,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33732e766f6d090a,0x2c38327225092032,0x240a3b3732722520,0x3136345f335f744c\n"
".quad 0x6c3c2f2f200a3a30,0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c38333220656e69\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6d69747365202c31,0x6574692064657461\n"
".quad 0x3a736e6f69746172,0x6e776f6e6b6e7520,0x652e70746573090a,0x2509203233752e71\n"
".quad 0x2c387225202c3370,0x090a3b3632722520,0x6172622033702540,0x5f335f744c240920\n"
".quad 0x2f200a3b36363834,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3833,0x64656c6562616c20,0x345f335f744c2420\n"
".quad 0x6f6c2e090a303136,0x3034320937310963,0x2e747663090a3009,0x203233752e343675\n"
".quad 0x202c333164722509,0x6d090a3b36327225,0x2e656469772e6c75,0x6472250920323375\n"
".quad 0x36327225202c3431,0x61090a3b3631202c,0x09203436752e6464,0x25202c3531647225\n"
".quad 0x7225202c34316472,0x2e646c090a3b3264,0x09203233662e3476,0x66252c363166257b\n"
".quad 0x2c383166252c3731,0x6472255b202c7d5f,0x090a3b5d302b3531,0x09373109636f6c2e\n"
".quad 0x61090a3009313432,0x09203436752e6464,0x25202c3631647225,0x7225202c34316472\n"
".quad 0x2e646c090a3b3464,0x09203233662e3476,0x66252c393166257b,0x2c313266252c3032\n"
".quad 0x6472255b202c7d5f,0x090a3b5d302b3631,0x09373109636f6c2e,0x73090a3009343432\n"
".quad 0x09203233662e6275,0x6625202c32326625,0x3b346625202c3731,0x33662e627573090a\n"
".quad 0x2c33326625092032,0x25202c3631662520,0x627573090a3b3266,0x662509203233662e\n"
".quad 0x38316625202c3432,0x090a3b366625202c,0x74736e6f632e646c,0x662509203233662e\n"
".quad 0x7261705b202c3532,0x3b5d32332b736d61,0x33662e646461090a,0x2c36326625092032\n"
".quad 0x25202c3532662520,0x756d090a3b353266,0x2509203233662e6c,0x326625202c373266\n"
".quad 0x3b32326625202c32,0x6e722e616d66090a,0x662509203233662e,0x33326625202c3832\n"
".quad 0x202c33326625202c,0x66090a3b37326625,0x33662e6e722e616d,0x2c39326625092032\n"
".quad 0x25202c3432662520,0x326625202c343266,0x74727173090a3b38,0x203233662e6e722e\n"
".quad 0x25202c3033662509,0x6573090a3b393266,0x33662e74672e7074,0x202c347025092032\n"
".quad 0x6625202c36326625,0x252140090a3b3033,0x0920617262203470,0x36355f335f744c24\n"
".quad 0x3c2f2f200a3b3433,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x38333220656e696c,0x6c2064616568202c,0x242064656c656261,0x3136345f335f744c\n"
".quad 0x09636f6c2e090a30,0x3009383032093731,0x33662e627573090a,0x2c31336625092032\n"
".quad 0x25202c3931662520,0x627573090a3b3866,0x662509203233662e,0x30326625202c3233\n"
".quad 0x0a3b30316625202c,0x3233662e62757309,0x202c333366250920,0x6625202c31326625\n"
".quad 0x766964090a3b3231,0x203233662e6e722e,0x25202c3433662509,0x336625202c333266\n"
".quad 0x2e766964090a3b30,0x09203233662e6e72,0x6625202c35336625,0x30336625202c3232\n"
".quad 0x722e766964090a3b,0x2509203233662e6e,0x326625202c363366,0x3b30336625202c34\n"
".quad 0x33662e6c756d090a,0x2c37336625092032,0x25202c3233662520,0x6d66090a3b353366\n"
".quad 0x3233662e6e722e61,0x202c383366250920,0x6625202c31336625,0x37336625202c3433\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x336625202c393366,0x2c36336625202c33\n"
".quad 0x090a3b3833662520,0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3034\n"
".quad 0x3b5d32392b736d61,0x33662e6c756d090a,0x2c31346625092032,0x25202c3433662520\n"
".quad 0x7573090a3b393366,0x2509203233662e62,0x336625202c323466,0x3b31346625202c31\n"
".quad 0x33662e6c756d090a,0x2c33346625092032,0x25202c3034662520,0x756d090a3b323466\n"
".quad 0x2509203233662e6c,0x336625202c343466,0x3b39336625202c35,0x33662e627573090a\n"
".quad 0x2c35346625092032,0x25202c3233662520,0x756d090a3b343466,0x2509203233662e6c\n"
".quad 0x346625202c363466,0x3b35346625202c30,0x33662e6c756d090a,0x2c37346625092032\n"
".quad 0x25202c3633662520,0x7573090a3b393366,0x2509203233662e62,0x336625202c383466\n"
".quad 0x3b37346625202c33,0x33662e6c756d090a,0x2c39346625092032,0x25202c3034662520\n"
".quad 0x6c2e090a3b383466,0x313209373109636f,0x627573090a300930,0x662509203233662e\n"
".quad 0x36326625202c3035,0x0a3b30336625202c,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x61705b202c313566,0x5d34382b736d6172,0x662e6c756d090a3b,0x3235662509203233\n"
".quad 0x202c31356625202c,0x6c090a3b30356625,0x2e74736e6f632e64,0x3566250920323366\n"
".quad 0x617261705b202c33,0x0a3b5d36392b736d,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x61705b202c343566,0x5d38382b736d6172,0x662e6c756d090a3b,0x3535662509203233\n"
".quad 0x202c34336625202c,0x6d090a3b32356625,0x09203233662e6c75,0x6625202c36356625\n"
".quad 0x34356625202c3133,0x662e627573090a3b,0x3735662509203233,0x202c36356625202c\n"
".quad 0x61090a3b35356625,0x09203233662e6464,0x6625202c38356625,0x37356625202c3334\n"
".quad 0x722e616d66090a3b,0x2509203233662e6e,0x326625202c393566,0x2c33356625202c33\n"
".quad 0x090a3b3835662520,0x203233662e6c756d,0x25202c3036662509,0x356625202c353366\n"
".quad 0x2e6c756d090a3b32,0x3666250920323366,0x2c32336625202c31,0x090a3b3435662520\n"
".quad 0x203233662e627573,0x25202c3236662509,0x366625202c313666,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x2c36346625202c33,0x090a3b3236662520,0x662e6e722e616d66\n"
".quad 0x3436662509203233,0x202c32326625202c,0x6625202c33356625,0x6c756d090a3b3336\n"
".quad 0x662509203233662e,0x36336625202c3536,0x0a3b32356625202c,0x3233662e6c756d09\n"
".quad 0x202c363666250920,0x6625202c33336625,0x627573090a3b3435,0x662509203233662e\n"
".quad 0x36366625202c3736,0x0a3b35366625202c,0x3233662e64646109,0x202c383666250920\n"
".quad 0x6625202c39346625,0x616d66090a3b3736,0x203233662e6e722e,0x25202c3936662509\n"
".quad 0x356625202c343266,0x3b38366625202c33,0x6e752e617262090a,0x335f744c24092069\n"
".quad 0x240a3b383733355f,0x3336355f335f744c,0x6c3c2f2f200a3a34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x303136345f335f74,0x33662e766f6d090a,0x2c39366625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6630202c34366625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3566250920323366,0x3030306630202c39,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x33355f335f744c24,0x3c2f2f200a3a3837,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x38333220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3136345f335f744c,0x09636f6c2e090a30,0x3009343432093731,0x33662e646461090a\n"
".quad 0x2c35316625092032,0x25202c3935662520,0x6461090a3b353166,0x2509203233662e64\n"
".quad 0x366625202c343166,0x3b34316625202c34,0x33662e646461090a,0x2c33316625092032\n"
".quad 0x25202c3936662520,0x744c240a3b333166,0x3a363638345f335f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3833322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x090a303136345f33,0x203233752e646461\n"
".quad 0x25202c3632722509,0x0a3b31202c363272,0x656e2e7074657309,0x702509203233752e\n"
".quad 0x2c35327225202c35,0x090a3b3632722520,0x6172622035702540,0x5f335f744c240920\n"
".quad 0x62090a3b30313634,0x0920696e752e6172,0x35335f335f744c24,0x5f744c240a3b3638\n"
".quad 0x0a3a363431365f33,0x3233662e766f6d09,0x202c333166250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c343166\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3531662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x20696e752e617262\n"
".quad 0x335f335f744c2409,0x744c240a3b363835,0x3a323438335f335f,0x33662e766f6d090a\n"
".quad 0x2c33316625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c34316625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c35,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x35335f335f744c24,0x6f6c2e090a3a3638,0x3834320937310963\n"
".quad 0x2e766f6d090a3009,0x3766250920323366,0x3b35316625202c30,0x7261702e7473090a\n"
".quad 0x09203233662e6d61,0x72616475635f5f5b,0x31315a5f5f667465,0x436564696c6c6f63\n"
".quad 0x33746e69346c6c65,0x3374616f6c66366a,0x6f6c6636505f3053,0x6a505f3253347461\n"
".quad 0x202c5d302b5f3353,0x6d090a3b30376625,0x09203233662e766f,0x6625202c31376625\n"
".quad 0x2e7473090a3b3431,0x33662e6d61726170,0x75635f5f5b092032,0x5f5f667465726164\n"
".quad 0x696c6c6f6331315a,0x69346c6c65436564,0x6f6c66366a33746e,0x36505f3053337461\n"
".quad 0x32533474616f6c66,0x342b5f33536a505f,0x3b31376625202c5d,0x33662e766f6d090a\n"
".quad 0x2c32376625092032,0x090a3b3331662520,0x6d617261702e7473,0x5f5b09203233662e\n"
".quad 0x746572616475635f,0x6f6331315a5f5f66,0x6c65436564696c6c,0x366a33746e69346c\n"
".quad 0x30533374616f6c66,0x74616f6c6636505f,0x33536a505f325334,0x6625202c5d382b5f\n"
".quad 0x746572090a3b3237,0x6e6557444c240a3b,0x6f6331315a5f5f64,0x6c65436564696c6c\n"
".quad 0x366a33746e69346c,0x30533374616f6c66,0x74616f6c6636505f,0x33536a505f325334\n"
".quad 0x2f2f207d090a3a5f,0x6c6f6331315a5f20,0x6c6c65436564696c,0x66366a33746e6934\n"
".quad 0x5f30533374616f6c,0x3474616f6c663650,0x5f33536a505f3253,0x72746e652e090a0a\n"
".quad 0x746e69395a5f2079,0x3650657461726765,0x30533474616f6c66,0x09090a28206a665f\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x726765746e69395a\n"
".quad 0x6f6c663650657461,0x6a665f3053347461,0x61727241736f705f,0x61702e09090a2c79\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x69395a5f5f6d7261,0x657461726765746e\n"
".quad 0x3474616f6c663650,0x65765f6a665f3053,0x0a2c79617272416c,0x6d617261702e0909\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x65746e69395a5f5f,0x6636506574617267\n"
".quad 0x5f30533474616f6c,0x61746c65645f6a66,0x09090a2c656d6954,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x5f5f6d7261706164,0x726765746e69395a,0x6f6c663650657461\n"
".quad 0x6a665f3053347461,0x747261506d756e5f,0x090a2973656c6369,0x206765722e090a7b\n"
".quad 0x3c7225203233752e,0x65722e090a3b3e38,0x25203436752e2067,0x090a3b3e383c6472\n"
".quad 0x33662e206765722e,0x3e33363c66252032,0x206765722e090a3b,0x702520646572702e\n"
".quad 0x2f2f090a3b3e393c,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f39393032345f72\n"
".quad 0x635f6e6f6e5f3831,0x736f705f74736e6f,0x31203d2061746144,0x5f5f202f2f090a36\n"
".quad 0x636f6c5f61647563,0x345f7261765f6c61,0x5f31325f30303132,0x736e6f635f6e6f6e\n"
".quad 0x7461446c65765f74,0x090a3233203d2061,0x09373109636f6c2e,0x444c240a30093334\n"
".quad 0x5f5f6e6967656257,0x726765746e69395a,0x6f6c663650657461,0x6a665f3053347461\n"
".quad 0x752e766f6d090a3a,0x2c31722509203233,0x2e64696174632520,0x2e766f6d090a3b78\n"
".quad 0x3272250920323375,0x2e6469746e25202c,0x326c756d090a3b78,0x3233752e6f6c2e34\n"
".quad 0x25202c3372250920,0x3b327225202c3172,0x33752e766f6d090a,0x202c347225092032\n"
".quad 0x0a3b782e64697425,0x3233752e64646109,0x25202c3572250920,0x3b337225202c3472\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5f5b202c367225,0x6d72617061647563\n"
".quad 0x65746e69395a5f5f,0x6636506574617267,0x5f30533474616f6c,0x61506d756e5f6a66\n"
".quad 0x5d73656c63697472,0x2e70746573090a3b,0x09203233752e7467,0x367225202c317025\n"
".quad 0x090a3b357225202c,0x6172622031702540,0x5f345f744c240920,0x62090a3b34333635\n"
".quad 0x0920696e752e6172,0x5f5f363142424c24,0x726765746e69395a,0x6f6c663650657461\n"
".quad 0x6a665f3053347461,0x5f345f744c240a3b,0x2e090a3a34333635,0x3409373109636f6c\n"
".quad 0x747663090a300938,0x3233752e3436752e,0x202c316472250920,0x756d090a3b357225\n"
".quad 0x752e656469772e6c,0x3264722509203233,0x31202c357225202c,0x702e646c090a3b36\n"
".quad 0x3436752e6d617261,0x202c336472250920,0x70616475635f5f5b,0x69395a5f5f6d7261\n"
".quad 0x657461726765746e,0x3474616f6c663650,0x6f705f6a665f3053,0x3b5d796172724173\n"
".quad 0x36752e646461090a,0x2c34647225092034,0x25202c3364722520,0x646c090a3b326472\n"
".quad 0x2e6c61626f6c672e,0x09203233662e3476,0x3266252c3166257b,0x3466252c3366252c\n"
".quad 0x346472255b202c7d,0x6f6d090a3b5d302b,0x2509203233662e76,0x3b316625202c3566\n"
".quad 0x33662e766f6d090a,0x202c366625092032,0x6f6d090a3b326625,0x2509203233662e76\n"
".quad 0x3b336625202c3766,0x33662e766f6d090a,0x202c386625092032,0x6c2e090a3b346625\n"
".quad 0x393409373109636f,0x702e646c090a3009,0x3436752e6d617261,0x202c356472250920\n"
".quad 0x70616475635f5f5b,0x69395a5f5f6d7261,0x657461726765746e,0x3474616f6c663650\n"
".quad 0x65765f6a665f3053,0x3b5d79617272416c,0x36752e646461090a,0x2c36647225092034\n"
".quad 0x25202c3564722520,0x646c090a3b326472,0x2e6c61626f6c672e,0x09203233662e3476\n"
".quad 0x3166252c3966257b,0x252c313166252c30,0x255b202c7d323166,0x0a3b5d302b366472\n"
".quad 0x3233662e766f6d09,0x202c333166250920,0x6f6d090a3b396625,0x2509203233662e76\n"
".quad 0x316625202c343166,0x2e766f6d090a3b30,0x3166250920323366,0x3b31316625202c35\n"
".quad 0x33662e766f6d090a,0x2c36316625092032,0x090a3b3231662520,0x09373109636f6c2e\n"
".quad 0x6f6d090a30093035,0x2509203233662e76,0x356625202c373166,0x662e766f6d090a3b\n"
".quad 0x3831662509203233,0x090a3b366625202c,0x203233662e766f6d,0x25202c3931662509\n"
".quad 0x6f6c2e090a3b3766,0x0931350937310963,0x662e766f6d090a30,0x3032662509203233\n"
".quad 0x0a3b33316625202c,0x3233662e766f6d09,0x202c313266250920,0x6d090a3b34316625\n"
".quad 0x09203233662e766f,0x6625202c32326625,0x6f6c2e090a3b3531,0x0934350937310963\n"
".quad 0x61702e646c090a30,0x203233662e6d6172,0x5b202c3332662509,0x6170616475635f5f\n"
".quad 0x6e69395a5f5f6d72,0x5065746172676574,0x533474616f6c6636,0x6c65645f6a665f30\n"
".quad 0x3b5d656d69546174,0x6e6f632e646c090a,0x09203233662e7473,0x705b202c34326625\n"
".quad 0x36312b736d617261,0x2e6c756d090a3b5d,0x3266250920323366,0x2c34326625202c35\n"
".quad 0x090a3b3332662520,0x203233662e646461,0x25202c3632662509,0x326625202c353266\n"
".quad 0x632e646c090a3b30,0x3233662e74736e6f,0x202c373266250920,0x2b736d617261705b\n"
".quad 0x756d090a3b5d3832,0x2509203233662e6c,0x326625202c383266,0x3b37326625202c36\n"
".quad 0x33662e766f6d090a,0x2c39326625092032,0x090a3b3832662520,0x74736e6f632e646c\n"
".quad 0x662509203233662e,0x7261705b202c3033,0x3b5d30322b736d61,0x33662e6c756d090a\n"
".quad 0x2c31336625092032,0x25202c3033662520,0x6461090a3b333266,0x2509203233662e64\n"
".quad 0x336625202c323366,0x3b31326625202c31,0x33662e6c756d090a,0x2c33336625092032\n"
".quad 0x25202c3233662520,0x6f6d090a3b373266,0x2509203233662e76,0x336625202c343366\n"
".quad 0x632e646c090a3b33,0x3233662e74736e6f,0x202c353366250920,0x2b736d617261705b\n"
".quad 0x756d090a3b5d3432,0x2509203233662e6c,0x336625202c363366,0x3b33326625202c35\n"
".quad 0x33662e646461090a,0x2c37336625092032,0x25202c3633662520,0x756d090a3b323266\n"
".quad 0x2509203233662e6c,0x336625202c383366,0x3b37326625202c37,0x33662e766f6d090a\n"
".quad 0x2c39336625092032,0x090a3b3833662520,0x09373109636f6c2e,0x756d090a30093735\n"
".quad 0x2509203233662e6c,0x326625202c303466,0x3b33326625202c38,0x33662e646461090a\n"
".quad 0x2c31346625092032,0x25202c3034662520,0x6f6d090a3b373166,0x2509203233662e76\n"
".quad 0x346625202c323466,0x2e6c756d090a3b31,0x3466250920323366,0x2c33336625202c33\n"
".quad 0x090a3b3332662520,0x203233662e646461,0x25202c3434662509,0x316625202c333466\n"
".quad 0x2e766f6d090a3b38,0x3466250920323366,0x3b34346625202c35,0x33662e6c756d090a\n"
".quad 0x2c36346625092032,0x25202c3833662520,0x6461090a3b333266,0x2509203233662e64\n"
".quad 0x346625202c373466,0x3b39316625202c36,0x33662e766f6d090a,0x2c38346625092032\n"
".quad 0x090a3b3734662520,0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3934\n"
".quad 0x3b5d32332b736d61,0x33662e766f6d090a,0x2c30356625092032,0x3030386633663020\n"
".quad 0x202020203b303030,0x73090a31202f2f09,0x09203233662e6275,0x6625202c31356625\n"
".quad 0x39346625202c3035,0x2e70746573090a3b,0x09203233662e746c,0x356625202c327025\n"
".quad 0x3b31346625202c31,0x203270252140090a,0x744c240920617262,0x3b363431365f345f\n"
".quad 0x3109636f6c2e090a,0x090a300931360937,0x203233662e766f6d,0x25202c3234662509\n"
".quad 0x646c090a3b313566,0x662e74736e6f632e,0x3235662509203233,0x6d617261705b202c\n"
".quad 0x0a3b5d3030312b73,0x3233662e6c756d09,0x202c393266250920,0x6625202c32356625\n"
".quad 0x5f744c240a3b3832,0x0a3a363431365f34,0x3233662e766f6d09,0x202c333566250920\n"
".quad 0x3030303866626630,0x09202020203b3030,0x61090a312d202f2f,0x09203233662e6464\n"
".quad 0x6625202c34356625,0x33356625202c3934,0x2e70746573090a3b,0x09203233662e7467\n"
".quad 0x356625202c337025,0x3b32346625202c34,0x203370252140090a,0x744c240920617262\n"
".quad 0x3b383536365f345f,0x3109636f6c2e090a,0x090a300932360937,0x203233662e766f6d\n"
".quad 0x25202c3234662509,0x646c090a3b343566,0x662e74736e6f632e,0x3535662509203233\n"
".quad 0x6d617261705b202c,0x0a3b5d3030312b73,0x3233662e6c756d09,0x202c393266250920\n"
".quad 0x6625202c35356625,0x5f744c240a3b3932,0x0a3a383536365f34,0x746c2e7074657309\n"
".quad 0x702509203233662e,0x2c31356625202c34,0x090a3b3434662520,0x7262203470252140\n"
".quad 0x345f744c24092061,0x090a3b303731375f,0x09373109636f6c2e,0x6f6d090a30093336\n"
".quad 0x2509203233662e76,0x356625202c353466,0x632e646c090a3b31,0x3233662e74736e6f\n"
".quad 0x202c363566250920,0x2b736d617261705b,0x6d090a3b5d303031,0x09203233662e6c75\n"
".quad 0x6625202c34336625,0x33336625202c3635,0x5f345f744c240a3b,0x73090a3a30373137\n"
".quad 0x662e746c2e707465,0x2c35702509203233,0x25202c3135662520,0x2140090a3b373466\n"
".quad 0x2061726220357025,0x375f345f744c2409,0x6c2e090a3b323836,0x343609373109636f\n"
".quad 0x2e766f6d090a3009,0x3466250920323366,0x3b31356625202c38,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c37356625,0x30312b736d617261,0x6c756d090a3b5d30\n"
".quad 0x662509203233662e,0x37356625202c3933,0x0a3b38336625202c,0x36375f345f744c24\n"
".quad 0x746573090a3a3238,0x3233662e74672e70,0x25202c3670250920,0x346625202c343566\n"
".quad 0x70252140090a3b38,0x2409206172622036,0x3931385f345f744c,0x636f6c2e090a3b34\n"
".quad 0x3009353609373109,0x33662e766f6d090a,0x2c38346625092032,0x090a3b3435662520\n"
".quad 0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3835,0x5d3030312b736d61\n"
".quad 0x662e6c756d090a3b,0x3933662509203233,0x202c38356625202c,0x4c240a3b39336625\n"
".quad 0x343931385f345f74,0x2e70746573090a3a,0x09203233662e7467,0x356625202c377025\n"
".quad 0x3b35346625202c34,0x203770252140090a,0x744c240920617262,0x3b363037385f345f\n"
".quad 0x3109636f6c2e090a,0x090a300937360937,0x203233662e766f6d,0x25202c3534662509\n"
".quad 0x646c090a3b343566,0x662e74736e6f632e,0x3935662509203233,0x6d617261705b202c\n"
".quad 0x0a3b5d3030312b73,0x3233662e6c756d09,0x202c343366250920,0x6625202c39356625\n"
".quad 0x5f744c240a3b3433,0x0a3a363037385f34,0x373109636f6c2e09,0x6d090a3009303709\n"
".quad 0x09203233662e766f,0x6625202c30366625,0x672e7473090a3b38,0x34762e6c61626f6c\n"
".quad 0x255b09203233662e,0x202c5d302b346472,0x66252c323466257b,0x2c383466252c3534\n"
".quad 0x090a3b7d30366625,0x09373109636f6c2e,0x6f6d090a30093137,0x2509203233662e76\n"
".quad 0x316625202c313666,0x672e7473090a3b36,0x34762e6c61626f6c,0x255b09203233662e\n"
".quad 0x202c5d302b366472,0x66252c393266257b,0x2c393366252c3433,0x240a3b7d31366625\n"
".quad 0x5a5f5f363142424c,0x61726765746e6939,0x616f6c6636506574,0x3a6a665f30533474\n"
".quad 0x3109636f6c2e090a,0x090a300932370937,0x4c240a3b74697865,0x5a5f5f646e655744\n"
".quad 0x61726765746e6939,0x616f6c6636506574,0x3a6a665f30533474,0x5f202f2f207d090a\n"
".quad 0x726765746e69395a,0x6f6c663650657461,0x6a665f3053347461,0x72746e652e090a0a\n"
".quad 0x6c6163395a5f2079,0x6a50446873614863,0x616f6c6636505f53,0x09090a28206a3474\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x6148636c6163395a\n"
".quad 0x505f536a50446873,0x6a3474616f6c6636,0x726150646972675f,0x736148656c636974\n"
".quad 0x61702e09090a2c68,0x3436752e206d6172,0x70616475635f5f20,0x63395a5f5f6d7261\n"
".quad 0x4468736148636c61,0x6c6636505f536a50,0x72675f6a3474616f,0x6369747261506469\n"
".quad 0x2c7865646e49656c,0x617261702e09090a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x6c6163395a5f5f6d,0x6a50446873614863,0x616f6c6636505f53,0x2c736f705f6a3474\n"
".quad 0x617261702e09090a,0x5f203233752e206d,0x726170616475635f,0x6c6163395a5f5f6d\n"
".quad 0x6a50446873614863,0x616f6c6636505f53,0x506d756e5f6a3474,0x73656c6369747261\n"
".quad 0x722e090a7b090a29,0x203233752e206765,0x0a3b3e35323c7225,0x752e206765722e09\n"
".quad 0x313c647225203436,0x65722e090a3b3e31,0x25203233662e2067,0x090a3b3e38323c66\n"
".quad 0x72702e206765722e,0x3e333c7025206465,0x5f5f202f2f090a3b,0x636f6c5f61647563\n"
".quad 0x345f7261765f6c61,0x5f31325f34353132,0x736e6f635f6e6f6e,0x3631203d20705f74\n"
".quad 0x3109636f6c2e090a,0x240a300938390937,0x6e6967656257444c,0x636c6163395a5f5f\n"
".quad 0x536a504468736148,0x74616f6c6636505f,0x766f6d090a3a6a34,0x722509203233752e\n"
".quad 0x6961746325202c31,0x6f6d090a3b782e64,0x2509203233752e76,0x69746e25202c3272\n"
".quad 0x756d090a3b782e64,0x752e6f6c2e34326c,0x2c33722509203233,0x7225202c31722520\n"
".quad 0x2e766f6d090a3b32,0x3472250920323375,0x782e64697425202c,0x752e646461090a3b\n"
".quad 0x2c35722509203233,0x7225202c34722520,0x702e646c090a3b33,0x3233752e6d617261\n"
".quad 0x5b202c3672250920,0x6170616475635f5f,0x6163395a5f5f6d72,0x504468736148636c\n"
".quad 0x6f6c6636505f536a,0x6d756e5f6a347461,0x656c636974726150,0x746573090a3b5d73\n"
".quad 0x3233752e74672e70,0x25202c3170250920,0x3b357225202c3672,0x622031702540090a\n"
".quad 0x5f744c2409206172,0x0a3b363230315f35,0x696e752e61726209,0x5f3442424c240920\n"
".quad 0x48636c6163395a5f,0x5f536a5044687361,0x3474616f6c663650,0x355f744c240a3b6a\n"
".quad 0x090a3a363230315f,0x09373109636f6c2e,0x63090a3009333031,0x752e3436752e7476\n"
".quad 0x3164722509203233,0x090a3b357225202c,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x635f5f5b202c3264,0x5f6d726170616475,0x48636c6163395a5f,0x5f536a5044687361\n"
".quad 0x3474616f6c663650,0x0a3b5d736f705f6a,0x6469772e6c756d09,0x2509203233752e65\n"
".quad 0x357225202c336472,0x61090a3b3631202c,0x09203436752e6464,0x7225202c34647225\n"
".quad 0x33647225202c3264,0x6c672e646c090a3b,0x2e34762e6c61626f,0x66257b0920323366\n"
".quad 0x66252c3266252c31,0x202c7d3466252c33,0x5d302b346472255b,0x662e766f6d090a3b\n"
".quad 0x2c35662509203233,0x6d090a3b31662520,0x09203233662e766f,0x326625202c366625\n"
".quad 0x662e766f6d090a3b,0x2c37662509203233,0x6d090a3b33662520,0x09203233662e766f\n"
".quad 0x346625202c386625,0x09636f6c2e090a3b,0x3009363031093731,0x33662e766f6d090a\n"
".quad 0x202c396625092032,0x6f6d090a3b356625,0x2509203233662e76,0x366625202c303166\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x090a3b376625202c,0x09373109636f6c2e\n"
".quad 0x646c090a30093039,0x752e74736e6f632e,0x2c37722509203233,0x736d617261705b20\n"
".quad 0x6c090a3b5d30342b,0x2e74736e6f632e64,0x3872250920323375,0x6d617261705b202c\n"
".quad 0x090a3b5d36332b73,0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3231\n"
".quad 0x3b5d36352b736d61,0x33662e627573090a,0x2c33316625092032,0x25202c3031662520\n"
".quad 0x646c090a3b323166,0x662e74736e6f632e,0x3431662509203233,0x6d617261705b202c\n"
".quad 0x090a3b5d38362b73,0x662e6e722e766964,0x3531662509203233,0x202c33316625202c\n"
".quad 0x63090a3b34316625,0x662e696d722e7476,0x09203233662e3233,0x6625202c36316625\n"
".quad 0x747663090a3b3531,0x3233732e697a722e,0x722509203233662e,0x3b36316625202c39\n"
".quad 0x33752e627573090a,0x2c30317225092032,0x3b31202c37722520,0x33622e646e61090a\n"
".quad 0x2c31317225092032,0x7225202c39722520,0x6c756d090a3b3031,0x33752e6f6c2e3432\n"
".quad 0x2c32317225092032,0x25202c3131722520,0x2e646c090a3b3872,0x33662e74736e6f63\n"
".quad 0x2c37316625092032,0x736d617261705b20,0x73090a3b5d30362b,0x09203233662e6275\n"
".quad 0x6625202c38316625,0x37316625202c3131,0x6f632e646c090a3b,0x203233662e74736e\n"
".quad 0x5b202c3931662509,0x372b736d61726170,0x766964090a3b5d32,0x203233662e6e722e\n"
".quad 0x25202c3032662509,0x316625202c383166,0x2e747663090a3b39,0x2e3233662e696d72\n"
".quad 0x3266250920323366,0x3b30326625202c31,0x7a722e747663090a,0x33662e3233732e69\n"
".quad 0x2c33317225092032,0x090a3b3132662520,0x74736e6f632e646c,0x722509203233752e\n"
".quad 0x7261705b202c3431,0x3b5d34342b736d61,0x33752e627573090a,0x2c35317225092032\n"
".quad 0x31202c3431722520,0x622e646e61090a3b,0x3631722509203233,0x202c33317225202c\n"
".quad 0x6d090a3b35317225,0x2e6f6c2e34326c75,0x3172250920323375,0x2c36317225202c37\n"
".quad 0x6d090a3b37722520,0x2e6f6c2e34326c75,0x3172250920323375,0x2c37317225202c38\n"
".quad 0x61090a3b38722520,0x09203233752e6464,0x7225202c39317225,0x38317225202c3231\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3232662509,0x352b736d61726170\n"
".quad 0x627573090a3b5d32,0x662509203233662e,0x2c396625202c3332,0x090a3b3232662520\n"
".quad 0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3432,0x3b5d34362b736d61\n"
".quad 0x6e722e766964090a,0x662509203233662e,0x33326625202c3532,0x0a3b34326625202c\n"
".quad 0x696d722e74766309,0x3233662e3233662e,0x202c363266250920,0x63090a3b35326625\n"
".quad 0x732e697a722e7476,0x09203233662e3233,0x6625202c30327225,0x627573090a3b3632\n"
".quad 0x722509203233752e,0x2c387225202c3132,0x646e61090a3b3120,0x722509203233622e\n"
".quad 0x30327225202c3232,0x0a3b31327225202c,0x3233752e64646109,0x202c333272250920\n"
".quad 0x7225202c39317225,0x6f6c2e090a3b3232,0x3031310937310963,0x2e6c756d090a3009\n"
".quad 0x3233752e65646977,0x202c356472250920,0x0a3b34202c357225,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5f5b202c366472,0x6d72617061647563,0x636c6163395a5f5f\n"
".quad 0x536a504468736148,0x74616f6c6636505f,0x50646972675f6a34,0x48656c6369747261\n"
".quad 0x61090a3b5d687361,0x09203436752e6464,0x7225202c37647225,0x35647225202c3664\n"
".quad 0x6c672e7473090a3b,0x3233752e6c61626f,0x2b376472255b0920,0x33327225202c5d30\n"
".quad 0x09636f6c2e090a3b,0x3009313131093731,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c38647225,0x726170616475635f,0x6c6163395a5f5f6d,0x6a50446873614863\n"
".quad 0x616f6c6636505f53,0x646972675f6a3474,0x656c636974726150,0x0a3b5d7865646e49\n"
".quad 0x3436752e64646109,0x202c396472250920,0x7225202c38647225,0x2e7473090a3b3564\n"
".quad 0x752e6c61626f6c67,0x6472255b09203233,0x7225202c5d302b39,0x3442424c240a3b35\n"
".quad 0x636c6163395a5f5f,0x536a504468736148,0x74616f6c6636505f,0x6f6c2e090a3a6a34\n"
".quad 0x3231310937310963,0x74697865090a3009,0x6e6557444c240a3b,0x6c6163395a5f5f64\n"
".quad 0x6a50446873614863,0x616f6c6636505f53,0x207d090a3a6a3474,0x6163395a5f202f2f\n"
".quad 0x504468736148636c,0x6f6c6636505f536a,0x652e090a6a347461,0x732e096e72657478\n"
".quad 0x612e206465726168,0x2e2034206e67696c,0x6572616873203862,0x3b5d5b6873614864\n"
".quad 0x72746e652e090a0a,0x657238325a5f2079,0x746144726564726f,0x646e6946646e4161\n"
".quad 0x726174536c6c6543,0x36505f536a504474,0x31533474616f6c66,0x5f31535f535f535f\n"
".quad 0x090a28206a5f3153,0x206d617261702e09,0x635f5f203436752e,0x5f6d726170616475\n"
".quad 0x726f657238325a5f,0x4161746144726564,0x6543646e6946646e,0x4474726174536c6c\n"
".quad 0x6c6636505f536a50,0x535f31533474616f,0x31535f31535f535f,0x536c6c65635f6a5f\n"
".quad 0x09090a2c74726174,0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164\n"
".quad 0x64726f657238325a,0x6e41617461447265,0x6c6543646e694664,0x504474726174536c\n"
".quad 0x6f6c6636505f536a,0x5f535f3153347461,0x5f31535f31535f53,0x6e456c6c65635f6a\n"
".quad 0x61702e09090a2c64,0x3436752e206d6172,0x70616475635f5f20,0x38325a5f5f6d7261\n"
".quad 0x44726564726f6572,0x6946646e41617461,0x74536c6c6543646e,0x5f536a5044747261\n"
".quad 0x3474616f6c663650,0x535f535f535f3153,0x735f6a5f31535f31,0x736f50646574726f\n"
".quad 0x7261702e09090a2c,0x203436752e206d61,0x6170616475635f5f,0x7238325a5f5f6d72\n"
".quad 0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364,0x505f536a50447472\n"
".quad 0x533474616f6c6636,0x31535f535f535f31,0x6f735f6a5f31535f,0x2c6c655664657472\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x657238325a5f5f6d\n"
".quad 0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543,0x36505f536a504474\n"
".quad 0x31533474616f6c66,0x5f31535f535f535f,0x6972675f6a5f3153,0x6c63697472615064\n"
".quad 0x090a2c6873614865,0x206d617261702e09,0x635f5f203436752e,0x5f6d726170616475\n"
".quad 0x726f657238325a5f,0x4161746144726564,0x6543646e6946646e,0x4474726174536c6c\n"
".quad 0x6c6636505f536a50,0x535f31533474616f,0x31535f31535f535f,0x50646972675f6a5f\n"
".quad 0x49656c6369747261,0x09090a2c7865646e,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x64726f657238325a,0x6e41617461447265,0x6c6543646e694664\n"
".quad 0x504474726174536c,0x6f6c6636505f536a,0x5f535f3153347461,0x5f31535f31535f53\n"
".quad 0x736f50646c6f5f6a,0x7261702e09090a2c,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x7238325a5f5f6d72,0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364\n"
".quad 0x505f536a50447472,0x533474616f6c6636,0x31535f535f535f31,0x6c6f5f6a5f31535f\n"
".quad 0x09090a2c6c655664,0x2e206d617261702e,0x75635f5f20323375,0x5f5f6d7261706164\n"
".quad 0x64726f657238325a,0x6e41617461447265,0x6c6543646e694664,0x504474726174536c\n"
".quad 0x6f6c6636505f536a,0x5f535f3153347461,0x5f31535f31535f53,0x7261506d756e5f6a\n"
".quad 0x0a2973656c636974,0x6765722e090a7b09,0x7225203233752e20,0x2e090a3b3e37323c\n"
".quad 0x3436752e20676572,0x3e34343c64722520,0x206765722e090a3b,0x3c6625203233662e\n"
".quad 0x722e090a3b3e3031,0x646572702e206765,0x0a3b3e383c702520,0x75635f5f202f2f09\n"
".quad 0x6c61636f6c5f6164,0x3132345f7261765f,0x6f6e5f30315f3138,0x5f74736e6f635f6e\n"
".quad 0x31203d2068736168,0x09636f6c2e090a36,0x3009353231093731,0x67656257444c240a\n"
".quad 0x7238325a5f5f6e69,0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364\n"
".quad 0x505f536a50447472,0x533474616f6c6636,0x31535f535f535f31,0x090a3a6a5f31535f\n"
".quad 0x203233752e766f6d,0x6325202c31722509,0x0a3b782e64696174,0x3233752e766f6d09\n"
".quad 0x25202c3272250920,0x0a3b782e6469746e,0x6c2e34326c756d09,0x2509203233752e6f\n"
".quad 0x2c317225202c3372,0x6d090a3b32722520,0x09203233752e766f,0x697425202c347225\n"
".quad 0x6461090a3b782e64,0x2509203233752e64,0x2c337225202c3572,0x6c090a3b34722520\n"
".quad 0x2e6d617261702e64,0x3672250920323375,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6564726f65723832,0x646e416174614472,0x6c6c6543646e6946,0x6a50447472617453\n"
".quad 0x616f6c6636505f53,0x535f535f31533474,0x6a5f31535f31535f,0x747261506d756e5f\n"
".quad 0x0a3b5d73656c6369,0x746c2e7074657309,0x702509203233752e,0x202c357225202c31\n"
".quad 0x2140090a3b367225,0x2061726220317025,0x355f365f744c2409,0x6c2e090a3b303938\n"
".quad 0x333109373109636f,0x766f6d090a300933,0x722509203436752e,0x72616873202c3164\n"
".quad 0x0a3b687361486465,0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c326472\n"
".quad 0x6d72617061647563,0x6f657238325a5f5f,0x6174614472656472,0x43646e6946646e41\n"
".quad 0x74726174536c6c65,0x6636505f536a5044,0x5f31533474616f6c,0x535f31535f535f53\n"
".quad 0x646972675f6a5f31,0x656c636974726150,0x090a3b5d68736148,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x0a3b357225202c33,0x6469772e6c756d09,0x2509203233752e65\n"
".quad 0x357225202c346472,0x6461090a3b34202c,0x2509203436752e64,0x647225202c356472\n"
".quad 0x3b34647225202c32,0x6f6c672e646c090a,0x203233752e6c6162,0x255b202c37722509\n"
".quad 0x0a3b5d302b356472,0x3233732e766f6d09,0x25202c3872250920,0x6f6c2e090a3b3772\n"
".quad 0x3833310937310963,0x2e747663090a3009,0x203233752e343675,0x25202c3664722509\n"
".quad 0x6c756d090a3b3472,0x33752e656469772e,0x2c37647225092032,0x3b34202c34722520\n"
".quad 0x36752e646461090a,0x2c38647225092034,0x25202c3164722520,0x7473090a3b376472\n"
".quad 0x2e6465726168732e,0x72255b0920323375,0x25202c5d342b3864,0x766f6d090a3b3772\n"
".quad 0x722509203233752e,0x73090a3b30202c39,0x33752e71652e7465,0x2509203233752e32\n"
".quad 0x347225202c303172,0x090a3b397225202c,0x203233732e67656e,0x25202c3131722509\n"
".quad 0x6f6d090a3b303172,0x2509203233752e76,0x0a3b30202c323172,0x2e656e2e74657309\n"
".quad 0x203233752e323375,0x25202c3331722509,0x32317225202c3572,0x732e67656e090a3b\n"
".quad 0x3431722509203233,0x0a3b33317225202c,0x3233622e646e6109,0x202c353172250920\n"
".quad 0x7225202c31317225,0x766f6d090a3b3431,0x722509203233752e,0x090a3b30202c3631\n"
".quad 0x2e71652e70746573,0x3270250920323373,0x202c35317225202c,0x40090a3b36317225\n"
".quad 0x2061726220327025,0x365f365f744c2409,0x6c2e090a3b323034,0x343109373109636f\n"
".quad 0x2e646c090a300933,0x752e6c61626f6c67,0x3731722509203233,0x2b356472255b202c\n"
".quad 0x7473090a3b5d342d,0x2e6465726168732e,0x68735b0920323375,0x6873614864657261\n"
".quad 0x317225202c5d302b,0x365f744c240a3b37,0x240a3a323034365f,0x3938355f365f744c\n"
".quad 0x2e766f6d090a3a30,0x6472250920343675,0x6572616873202c31,0x090a3b6873614864\n"
".quad 0x09373109636f6c2e,0x62090a3009373431,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x0920617262203170,0x39365f365f744c24,0x6f6c2e090a3b3431,0x3635310937310963\n"
".quad 0x2e766f6d090a3009,0x3772250920323373,0x090a3b387225202c,0x203233752e766f6d\n"
".quad 0x30202c3831722509,0x2e70746573090a3b,0x09203233752e7165,0x357225202c337025\n"
".quad 0x0a3b38317225202c,0x7262203370254009,0x5f365f4c24092061,0x63090a3b34333635\n"
".quad 0x752e3436752e7476,0x3964722509203233,0x090a3b347225202c,0x656469772e6c756d\n"
".quad 0x722509203233752e,0x347225202c303164,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x7225202c31316472,0x31647225202c3164,0x732e646c090a3b30,0x33752e6465726168\n"
".quad 0x2c39317225092032,0x2b31316472255b20,0x747663090a3b5d30,0x3233752e3436752e\n"
".quad 0x2c32316472250920,0x090a3b3931722520,0x2e3233752e747663,0x3272250920343675\n"
".quad 0x3231647225202c30,0x2e70746573090a3b,0x09203233752e7165,0x377225202c347025\n"
".quad 0x0a3b30327225202c,0x7262203470254009,0x5f365f4c24092061,0x4c240a3b38373335\n"
".quad 0x3a343336355f365f,0x3109636f6c2e090a,0x0a30093835310937,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5b202c33316472,0x726170616475635f,0x657238325a5f5f6d\n"
".quad 0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543,0x36505f536a504474\n"
".quad 0x31533474616f6c66,0x5f31535f535f535f,0x6c65635f6a5f3153,0x3b5d74726174536c\n"
".quad 0x36752e747663090a,0x2509203233752e34,0x7225202c34316472,0x2e6c756d090a3b37\n"
".quad 0x3233752e65646977,0x2c35316472250920,0x3b34202c37722520,0x36752e646461090a\n"
".quad 0x3631647225092034,0x2c3331647225202c,0x0a3b353164722520,0x626f6c672e747309\n"
".quad 0x09203233752e6c61,0x302b36316472255b,0x0a3b357225202c5d,0x3233752e766f6d09\n"
".quad 0x202c313272250920,0x70746573090a3b30,0x203233752e71652e,0x7225202c35702509\n"
".quad 0x3b31327225202c35,0x622035702540090a,0x5f744c2409206172,0x0a3b363234375f36\n"
".quad 0x373109636f6c2e09,0x090a300930363109,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x5f5f5b202c373164,0x6d72617061647563,0x6f657238325a5f5f,0x6174614472656472\n"
".quad 0x43646e6946646e41,0x74726174536c6c65,0x6636505f536a5044,0x5f31533474616f6c\n"
".quad 0x535f31535f535f53,0x6c6c65635f6a5f31,0x63090a3b5d646e45,0x752e3436752e7476\n"
".quad 0x3164722509203233,0x0a3b347225202c38,0x6469772e6c756d09,0x2509203233752e65\n"
".quad 0x7225202c39316472,0x61090a3b34202c34,0x09203436752e6464,0x25202c3032647225\n"
".quad 0x647225202c316472,0x2e646c090a3b3931,0x752e646572616873,0x3232722509203233\n"
".quad 0x30326472255b202c,0x7663090a3b5d302b,0x33752e3436752e74,0x3132647225092032\n"
".quad 0x0a3b32327225202c,0x6469772e6c756d09,0x2509203233752e65,0x7225202c32326472\n"
".quad 0x090a3b34202c3232,0x203436752e646461,0x202c333264722509,0x25202c3731647225\n"
".quad 0x73090a3b32326472,0x6c61626f6c672e74,0x255b09203233752e,0x2c5d302b33326472\n"
".quad 0x4c240a3b35722520,0x363234375f365f74,0x355f365f4c240a3a,0x6c2e090a3a383733\n"
".quad 0x353109373109636f,0x627573090a300938,0x722509203233752e,0x2c367225202c3332\n"
".quad 0x746573090a3b3120,0x3233752e656e2e70,0x25202c3670250920,0x33327225202c3572\n"
".quad 0x2036702540090a3b,0x744c240920617262,0x3b383339375f365f,0x3109636f6c2e090a\n"
".quad 0x0a30093536310937,0x3233752e64646109,0x202c343272250920,0x0a3b31202c357225\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5f5b202c34326472,0x726170616475635f\n"
".quad 0x657238325a5f5f6d,0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543\n"
".quad 0x36505f536a504474,0x31533474616f6c66,0x5f31535f535f535f,0x6c65635f6a5f3153\n"
".quad 0x090a3b5d646e456c,0x2e3436752e747663,0x6472250920323375,0x3b377225202c3532\n"
".quad 0x69772e6c756d090a,0x09203233752e6564,0x25202c3632647225,0x090a3b34202c3772\n"
".quad 0x203436752e646461,0x202c373264722509,0x25202c3432647225,0x73090a3b36326472\n"
".quad 0x6c61626f6c672e74,0x255b09203233752e,0x2c5d302b37326472,0x240a3b3432722520\n"
".quad 0x3339375f365f744c,0x636f6c2e090a3a38,0x0939363109373109,0x752e747663090a30\n"
".quad 0x09203233752e3436,0x25202c3832647225,0x2e646c090a3b3572,0x36752e6d61726170\n"
".quad 0x3932647225092034,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6564726f65723832\n"
".quad 0x646e416174614472,0x6c6c6543646e6946,0x6a50447472617453,0x616f6c6636505f53\n"
".quad 0x535f535f31533474,0x6a5f31535f31535f,0x726150646972675f,0x646e49656c636974\n"
".quad 0x756d090a3b5d7865,0x752e656469772e6c,0x3364722509203233,0x202c357225202c30\n"
".quad 0x2e646461090a3b34,0x6472250920343675,0x32647225202c3133,0x3033647225202c39\n"
".quad 0x6c672e646c090a3b,0x3233752e6c61626f,0x202c353272250920,0x302b31336472255b\n"
".quad 0x636f6c2e090a3b5d,0x0930373109373109,0x752e747663090a30,0x09203233752e3436\n"
".quad 0x25202c3233647225,0x756d090a3b353272,0x752e656469772e6c,0x3364722509203233\n"
".quad 0x2c35327225202c33,0x646c090a3b363120,0x752e6d617261702e,0x3364722509203436\n"
".quad 0x75635f5f5b202c34,0x5f5f6d7261706164,0x64726f657238325a,0x6e41617461447265\n"
".quad 0x6c6543646e694664,0x504474726174536c,0x6f6c6636505f536a,0x5f535f3153347461\n"
".quad 0x5f31535f31535f53,0x736f50646c6f5f6a,0x2e646461090a3b5d,0x6472250920343675\n"
".quad 0x33647225202c3533,0x3333647225202c34,0x6c672e646c090a3b,0x2e34762e6c61626f\n"
".quad 0x66257b0920323366,0x66252c3266252c31,0x202c7d3466252c33,0x302b35336472255b\n"
".quad 0x636f6c2e090a3b5d,0x0931373109373109,0x61702e646c090a30,0x203436752e6d6172\n"
".quad 0x202c363364722509,0x70616475635f5f5b,0x38325a5f5f6d7261,0x44726564726f6572\n"
".quad 0x6946646e41617461,0x74536c6c6543646e,0x5f536a5044747261,0x3474616f6c663650\n"
".quad 0x535f535f535f3153,0x6f5f6a5f31535f31,0x0a3b5d6c6556646c,0x3436752e64646109\n"
".quad 0x2c37336472250920,0x202c363364722520,0x090a3b3333647225,0x61626f6c672e646c\n"
".quad 0x3233662e34762e6c,0x252c3566257b0920,0x252c3766252c3666,0x72255b202c7d3866\n"
".quad 0x0a3b5d302b373364,0x373109636f6c2e09,0x090a300933373109,0x656469772e6c756d\n"
".quad 0x722509203233752e,0x357225202c383364,0x6c090a3b3631202c,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x635f5f5b202c3933,0x5f6d726170616475,0x726f657238325a5f\n"
".quad 0x4161746144726564,0x6543646e6946646e,0x4474726174536c6c,0x6c6636505f536a50\n"
".quad 0x535f31533474616f,0x31535f31535f535f,0x6574726f735f6a5f,0x090a3b5d736f5064\n"
".quad 0x203436752e646461,0x202c303464722509,0x25202c3933647225,0x73090a3b38336472\n"
".quad 0x6c61626f6c672e74,0x203233662e34762e,0x2b30346472255b09,0x3166257b202c5d30\n"
".quad 0x3366252c3266252c,0x090a3b7d3466252c,0x09373109636f6c2e,0x6c090a3009343731\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x635f5f5b202c3134,0x5f6d726170616475\n"
".quad 0x726f657238325a5f,0x4161746144726564,0x6543646e6946646e,0x4474726174536c6c\n"
".quad 0x6c6636505f536a50,0x535f31533474616f,0x31535f31535f535f,0x6574726f735f6a5f\n"
".quad 0x090a3b5d6c655664,0x203436752e646461,0x202c323464722509,0x25202c3134647225\n"
".quad 0x73090a3b38336472,0x6c61626f6c672e74,0x203233662e34762e,0x2b32346472255b09\n"
".quad 0x3566257b202c5d30,0x3766252c3666252c,0x240a3b7d3866252c,0x3139365f365f744c\n"
".quad 0x636f6c2e090a3a34,0x0938373109373109,0x3b74697865090a30,0x646e6557444c240a\n"
".quad 0x6f657238325a5f5f,0x6174614472656472,0x43646e6946646e41,0x74726174536c6c65\n"
".quad 0x6636505f536a5044,0x5f31533474616f6c,0x535f31535f535f53,0x207d090a3a6a5f31\n"
".quad 0x7238325a5f202f2f,0x6144726564726f65,0x6e6946646e416174,0x6174536c6c654364\n"
".quad 0x505f536a50447472,0x533474616f6c6636,0x31535f535f535f31,0x090a0a6a5f31535f\n"
".quad 0x5f207972746e652e,0x64696c6c6f63385a,0x616f6c6636504465,0x5f30535f30533474\n"
".quad 0x5f31535f31536a50,0x702e09090a28206a,0x36752e206d617261,0x616475635f5f2034\n"
".quad 0x385a5f5f6d726170,0x446564696c6c6f63,0x3474616f6c663650,0x6a505f30535f3053\n"
".quad 0x5f6a5f31535f3153,0x0a2c6c655677656e,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x6c6c6f63385a5f5f,0x6c66365044656469,0x535f30533474616f\n"
".quad 0x535f31536a505f30,0x50646c6f5f6a5f31,0x702e09090a2c736f,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x385a5f5f6d726170,0x446564696c6c6f63,0x3474616f6c663650\n"
".quad 0x6a505f30535f3053,0x5f6a5f31535f3153,0x0a2c6c6556646c6f,0x6d617261702e0909\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x6c6c6f63385a5f5f,0x6c66365044656469\n"
".quad 0x535f30533474616f,0x535f31536a505f30,0x646972675f6a5f31,0x656c636974726150\n"
".quad 0x090a2c7865646e49,0x206d617261702e09,0x635f5f203436752e,0x5f6d726170616475\n"
".quad 0x696c6c6f63385a5f,0x6f6c663650446564,0x30535f3053347461,0x31535f31536a505f\n"
".quad 0x536c6c65635f6a5f,0x09090a2c74726174,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x64696c6c6f63385a,0x616f6c6636504465,0x5f30535f30533474\n"
".quad 0x5f31535f31536a50,0x6e456c6c65635f6a,0x61702e09090a2c64,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x63385a5f5f6d7261,0x50446564696c6c6f,0x533474616f6c6636\n"
".quad 0x536a505f30535f30,0x6e5f6a5f31535f31,0x6369747261506d75,0x0a7b090a2973656c\n"
".quad 0x752e206765722e09,0x32343c7225203233,0x6765722e090a3b3e,0x7225203436752e20\n"
".quad 0x090a3b3e35323c64,0x33662e206765722e,0x3133313c66252032,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x090a3b3e32313c70,0x09373109636f6c2e,0x4c240a3009393532\n"
".quad 0x5f6e696765625744,0x696c6c6f63385a5f,0x6f6c663650446564,0x30535f3053347461\n"
".quad 0x31535f31536a505f,0x747663090a3a6a5f,0x3233752e3233732e,0x25202c3172250920\n"
".quad 0x3b782e6469617463,0x33732e747663090a,0x2509203233752e32,0x69746e25202c3272\n"
".quad 0x756d090a3b782e64,0x732e6f6c2e34326c,0x2c33722509203233,0x7225202c31722520\n"
".quad 0x2e766f6d090a3b32,0x3472250920323375,0x782e64697425202c,0x752e646461090a3b\n"
".quad 0x2c35722509203233,0x7225202c33722520,0x702e646c090a3b34,0x3233752e6d617261\n"
".quad 0x5b202c3672250920,0x6170616475635f5f,0x6f63385a5f5f6d72,0x3650446564696c6c\n"
".quad 0x30533474616f6c66,0x31536a505f30535f,0x756e5f6a5f31535f,0x6c6369747261506d\n"
".quad 0x6573090a3b5d7365,0x33752e74672e7074,0x202c317025092032,0x357225202c367225\n"
".quad 0x2031702540090a3b,0x744c240920617262,0x3b343931385f375f,0x6e752e617262090a\n"
".quad 0x3242424c24092069,0x6c6f63385a5f5f37,0x663650446564696c,0x5f30533474616f6c\n"
".quad 0x5f31536a505f3053,0x4c240a3b6a5f3153,0x343931385f375f74,0x09636f6c2e090a3a\n"
".quad 0x3009353632093731,0x36752e747663090a,0x2509203233752e34,0x357225202c316472\n"
".quad 0x772e6c756d090a3b,0x203233752e656469,0x25202c3264722509,0x0a3b3631202c3572\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5f5f5b202c336472,0x6d72617061647563\n"
".quad 0x6c6c6f63385a5f5f,0x6c66365044656469,0x535f30533474616f,0x535f31536a505f30\n"
".quad 0x50646c6f5f6a5f31,0x6461090a3b5d736f,0x2509203436752e64,0x647225202c346472\n"
".quad 0x3b33647225202c32,0x6f6c672e646c090a,0x662e34762e6c6162,0x3166257b09203233\n"
".quad 0x3366252c3266252c,0x72255b202c7d5f2c,0x090a3b5d302b3464,0x09373109636f6c2e\n"
".quad 0x6c090a3009363632,0x2e6d617261702e64,0x6472250920343675,0x75635f5f5b202c35\n"
".quad 0x5f5f6d7261706164,0x64696c6c6f63385a,0x616f6c6636504465,0x5f30535f30533474\n"
".quad 0x5f31535f31536a50,0x6c6556646c6f5f6a,0x2e646461090a3b5d,0x6472250920343675\n"
".quad 0x2c32647225202c36,0x090a3b3564722520,0x61626f6c672e646c,0x3233662e34762e6c\n"
".quad 0x252c3466257b0920,0x5f2c3666252c3566,0x366472255b202c7d,0x6c2e090a3b5d302b\n"
".quad 0x363209373109636f,0x2e646c090a300939,0x33662e74736e6f63,0x202c376625092032\n"
".quad 0x2b736d617261705b,0x7573090a3b5d3235,0x2509203233662e62,0x2c316625202c3866\n"
".quad 0x6c090a3b37662520,0x2e74736e6f632e64,0x3966250920323366,0x6d617261705b202c\n"
".quad 0x090a3b5d34362b73,0x662e6e722e766964,0x3031662509203233,0x25202c386625202c\n"
".quad 0x747663090a3b3966,0x3233662e696d722e,0x662509203233662e,0x30316625202c3131\n"
".quad 0x722e747663090a3b,0x662e3233732e697a,0x2c37722509203233,0x090a3b3131662520\n"
".quad 0x74736e6f632e646c,0x662509203233662e,0x7261705b202c3231,0x3b5d36352b736d61\n"
".quad 0x33662e627573090a,0x2c33316625092032,0x6625202c32662520,0x2e646c090a3b3231\n"
".quad 0x33662e74736e6f63,0x2c34316625092032,0x736d617261705b20,0x64090a3b5d38362b\n"
".quad 0x33662e6e722e7669,0x2c35316625092032,0x25202c3331662520,0x7663090a3b343166\n"
".quad 0x33662e696d722e74,0x2509203233662e32,0x316625202c363166,0x2e747663090a3b35\n"
".quad 0x2e3233732e697a72,0x3872250920323366,0x0a3b36316625202c,0x736e6f632e646c09\n"
".quad 0x2509203233662e74,0x61705b202c373166,0x5d30362b736d6172,0x662e627573090a3b\n"
".quad 0x3831662509203233,0x25202c336625202c,0x646c090a3b373166,0x662e74736e6f632e\n"
".quad 0x3931662509203233,0x6d617261705b202c,0x090a3b5d32372b73,0x662e6e722e766964\n"
".quad 0x3032662509203233,0x202c38316625202c,0x63090a3b39316625,0x662e696d722e7476\n"
".quad 0x09203233662e3233,0x6625202c31326625,0x747663090a3b3032,0x3233732e697a722e\n"
".quad 0x722509203233662e,0x3b31326625202c39,0x6e6f632e646c090a,0x09203233752e7473\n"
".quad 0x705b202c30317225,0x34342b736d617261,0x2e627573090a3b5d,0x3172250920323375\n"
".quad 0x2c30317225202c31,0x2e646c090a3b3120,0x33752e74736e6f63,0x2c32317225092032\n"
".quad 0x736d617261705b20,0x73090a3b5d30342b,0x09203233752e6275,0x7225202c33317225\n"
".quad 0x090a3b31202c3231,0x74736e6f632e646c,0x722509203233752e,0x7261705b202c3431\n"
".quad 0x3b5d36332b736d61,0x33752e627573090a,0x2c35317225092032,0x31202c3431722520\n"
".quad 0x732e627573090a3b,0x3631722509203233,0x31202c377225202c,0x732e646461090a3b\n"
".quad 0x3731722509203233,0x32202c377225202c,0x732e627573090a3b,0x3831722509203233\n"
".quad 0x31202c387225202c,0x732e627573090a3b,0x3931722509203233,0x31202c397225202c\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3232662509,0x332b736d61726170\n"
".quad 0x2e646c090a3b5d32,0x36752e6d61726170,0x2c37647225092034,0x616475635f5f5b20\n"
".quad 0x385a5f5f6d726170,0x446564696c6c6f63,0x3474616f6c663650,0x6a505f30535f3053\n"
".quad 0x5f6a5f31535f3153,0x726174536c6c6563,0x766f6d090a3b5d74,0x722509203233732e\n"
".quad 0x0a3b312d202c3032,0x3233662e766f6d09,0x202c333266250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c343266\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3532662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x240a30202f2f0920,0x3132395f375f744c\n"
".quad 0x6c3c2f2f200a3a38,0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6172657469202c31,0x33203a736e6f6974\n"
".quad 0x33732e766f6d090a,0x2c31327225092032,0x090a3b3831722520,0x203233622e646e61\n"
".quad 0x25202c3232722509,0x317225202c393172,0x326c756d090a3b31,0x3233752e6f6c2e34\n"
".quad 0x202c333272250920,0x7225202c32327225,0x6c756d090a3b3231,0x33752e6f6c2e3432\n"
".quad 0x2c34327225092032,0x25202c3332722520,0x6f6d090a3b343172,0x2509203233732e76\n"
".quad 0x3b312d202c353272,0x395f375f744c240a,0x2f2f200a3a363839,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x697473656e202c39,0x687470656420676e\n"
".quad 0x657469202c32203a,0x3a736e6f69746172,0x2e766f6d090a3320,0x3272250920323373\n"
".quad 0x3b36317225202c36,0x33622e646e61090a,0x2c37327225092032,0x25202c3132722520\n"
".quad 0x756d090a3b333172,0x752e6f6c2e34326c,0x3832722509203233,0x202c37327225202c\n"
".quad 0x61090a3b34317225,0x09203233732e6464,0x7225202c39327225,0x34327225202c3832\n"
".quad 0x5f375f744c240a3b,0x200a3a3435373031,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x73656e202c393632,0x70656420676e6974,0x69202c33203a6874\n"
".quad 0x6e6f697461726574,0x6c2e090a33203a73,0x303909373109636f,0x2e646e61090a3009\n"
".quad 0x3372250920323362,0x2c36327225202c30,0x090a3b3531722520,0x203233732e646461\n"
".quad 0x25202c3133722509,0x337225202c393272,0x636f6c2e090a3b30,0x0932333209373109\n"
".quad 0x752e747663090a30,0x09203233752e3436,0x7225202c38647225,0x6c756d090a3b3133\n"
".quad 0x33752e656469772e,0x2c39647225092032,0x34202c3133722520,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x2c39647225202c30,0x090a3b3764722520,0x61626f6c672e646c\n"
".quad 0x2509203233752e6c,0x72255b202c323372,0x0a3b5d302b303164,0x3233752e766f6d09\n"
".quad 0x202c333372250920,0x746573090a3b312d,0x3233752e71652e70,0x25202c3270250920\n"
".quad 0x337225202c323372,0x32702540090a3b33,0x4c24092061726220,0x363231315f375f74\n"
".quad 0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x353730315f375f74\n"
".quad 0x09636f6c2e090a34,0x3009373332093731,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5b202c3131647225,0x6170616475635f5f,0x6f63385a5f5f6d72,0x3650446564696c6c\n"
".quad 0x30533474616f6c66,0x31536a505f30535f,0x65635f6a5f31535f,0x0a3b5d646e456c6c\n"
".quad 0x3436752e64646109,0x2c32316472250920,0x202c313164722520,0x6c090a3b39647225\n"
".quad 0x6c61626f6c672e64,0x722509203233752e,0x6472255b202c3433,0x090a3b5d302b3231\n"
".quad 0x09373109636f6c2e,0x6d090a3009383332,0x09203233732e766f,0x7225202c35337225\n"
".quad 0x746573090a3b3233,0x3233752e65672e70,0x25202c3370250920,0x337225202c323372\n"
".quad 0x33702540090a3b34,0x4c24092061726220,0x353834315f375f74,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x353730315f375f74,0x752e627573090a34\n"
".quad 0x3633722509203233,0x202c34337225202c,0x6d090a3b32337225,0x09203233662e766f\n"
".quad 0x6630202c36326625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3266250920323366,0x3030306630202c37,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c383266250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x2f2f200a30202f2f,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c39,0x2064656c6562616c,0x30315f375f744c24\n"
".quad 0x766f6d090a343537,0x722509203233732e,0x36337225202c3733,0x5f375f744c240a3b\n"
".quad 0x200a3a3433303231,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x73656e202c383332,0x70656420676e6974,0x65202c34203a6874,0x646574616d697473\n"
".quad 0x6974617265746920,0x6b6e75203a736e6f,0x6573090a6e776f6e,0x33752e71652e7074\n"
".quad 0x202c347025092032,0x337225202c357225,0x34702540090a3b35,0x4c24092061726220\n"
".quad 0x393232315f375f74,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333032315f375f74,0x09636f6c2e090a34,0x3009303432093731,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x7225202c33316472,0x6c756d090a3b3533,0x33752e656469772e\n"
".quad 0x3431647225092032,0x202c35337225202c,0x646461090a3b3631,0x722509203436752e\n"
".quad 0x647225202c353164,0x33647225202c3431,0x6c672e646c090a3b,0x2e34762e6c61626f\n"
".quad 0x66257b0920323366,0x2c303366252c3932,0x2c7d5f2c31336625,0x2b35316472255b20\n"
".quad 0x6f6c2e090a3b5d30,0x3134320937310963,0x2e646461090a3009,0x6472250920343675\n"
".quad 0x31647225202c3631,0x3b35647225202c34,0x6f6c672e646c090a,0x662e34762e6c6162\n"
".quad 0x3366257b09203233,0x252c333366252c32,0x202c7d5f2c343366,0x302b36316472255b\n"
".quad 0x636f6c2e090a3b5d,0x0934343209373109,0x662e627573090a30,0x3533662509203233\n"
".quad 0x202c30336625202c,0x7573090a3b326625,0x2509203233662e62,0x326625202c363366\n"
".quad 0x0a3b316625202c39,0x3233662e62757309,0x202c373366250920,0x6625202c31336625\n"
".quad 0x2e646461090a3b33,0x3366250920323366,0x2c32326625202c38,0x090a3b3232662520\n"
".quad 0x203233662e6c756d,0x25202c3933662509,0x336625202c353366,0x2e616d66090a3b35\n"
".quad 0x09203233662e6e72,0x6625202c30346625,0x36336625202c3633,0x0a3b39336625202c\n"
".quad 0x2e6e722e616d6609,0x3466250920323366,0x2c37336625202c31,0x25202c3733662520\n"
".quad 0x7173090a3b303466,0x33662e6e722e7472,0x2c32346625092032,0x090a3b3134662520\n"
".quad 0x2e74672e70746573,0x3570250920323366,0x202c38336625202c,0x40090a3b32346625\n"
".quad 0x6172622035702521,0x5f375f744c240920,0x200a3b3835303331,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332\n"
".quad 0x656c6562616c2064,0x5f375f744c242064,0x2e090a3433303231,0x3209373109636f6c\n"
".quad 0x7573090a30093830,0x2509203233662e62,0x336625202c333466,0x0a3b346625202c32\n"
".quad 0x3233662e62757309,0x202c343466250920,0x6625202c33336625,0x2e627573090a3b35\n"
".quad 0x3466250920323366,0x2c34336625202c35,0x64090a3b36662520,0x33662e6e722e7669\n"
".quad 0x2c36346625092032,0x25202c3633662520,0x6964090a3b323466,0x3233662e6e722e76\n"
".quad 0x202c373466250920,0x6625202c35336625,0x766964090a3b3234,0x203233662e6e722e\n"
".quad 0x25202c3834662509,0x346625202c373366,0x2e6c756d090a3b32,0x3466250920323366\n"
".quad 0x2c34346625202c39,0x090a3b3734662520,0x662e6e722e616d66,0x3035662509203233\n"
".quad 0x202c33346625202c,0x6625202c36346625,0x616d66090a3b3934,0x203233662e6e722e\n"
".quad 0x25202c3135662509,0x346625202c353466,0x3b30356625202c38,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c32356625,0x32392b736d617261,0x2e6c756d090a3b5d\n"
".quad 0x3566250920323366,0x2c36346625202c33,0x090a3b3135662520,0x203233662e627573\n"
".quad 0x25202c3435662509,0x356625202c333466,0x2e6c756d090a3b33,0x3566250920323366\n"
".quad 0x2c32356625202c35,0x090a3b3435662520,0x203233662e6c756d,0x25202c3635662509\n"
".quad 0x356625202c373466,0x2e627573090a3b31,0x3566250920323366,0x2c34346625202c37\n"
".quad 0x090a3b3635662520,0x203233662e6c756d,0x25202c3835662509,0x356625202c323566\n"
".quad 0x2e6c756d090a3b37,0x3566250920323366,0x2c38346625202c39,0x090a3b3135662520\n"
".quad 0x203233662e627573,0x25202c3036662509,0x356625202c353466,0x2e6c756d090a3b39\n"
".quad 0x3666250920323366,0x2c32356625202c31,0x090a3b3036662520,0x09373109636f6c2e\n"
".quad 0x73090a3009303132,0x09203233662e6275,0x6625202c32366625,0x32346625202c3833\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3336662509,0x382b736d61726170\n"
".quad 0x6c756d090a3b5d34,0x662509203233662e,0x33366625202c3436,0x0a3b32366625202c\n"
".quad 0x736e6f632e646c09,0x2509203233662e74,0x61705b202c353666,0x5d36392b736d6172\n"
".quad 0x6f632e646c090a3b,0x203233662e74736e,0x5b202c3636662509,0x382b736d61726170\n"
".quad 0x6c756d090a3b5d38,0x662509203233662e,0x36346625202c3736,0x0a3b34366625202c\n"
".quad 0x3233662e6c756d09,0x202c383666250920,0x6625202c33346625,0x627573090a3b3636\n"
".quad 0x662509203233662e,0x38366625202c3936,0x0a3b37366625202c,0x3233662e64646109\n"
".quad 0x202c303766250920,0x6625202c35356625,0x616d66090a3b3936,0x203233662e6e722e\n"
".quad 0x25202c3137662509,0x366625202c363366,0x3b30376625202c35,0x33662e6c756d090a\n"
".quad 0x2c32376625092032,0x25202c3734662520,0x756d090a3b343666,0x2509203233662e6c\n"
".quad 0x346625202c333766,0x3b36366625202c34,0x33662e627573090a,0x2c34376625092032\n"
".quad 0x25202c3337662520,0x6461090a3b323766,0x2509203233662e64,0x356625202c353766\n"
".quad 0x3b34376625202c38,0x6e722e616d66090a,0x662509203233662e,0x35336625202c3637\n"
".quad 0x202c35366625202c,0x6d090a3b35376625,0x09203233662e6c75,0x6625202c37376625\n"
".quad 0x34366625202c3834,0x662e6c756d090a3b,0x3837662509203233,0x202c35346625202c\n"
".quad 0x73090a3b36366625,0x09203233662e6275,0x6625202c39376625,0x37376625202c3837\n"
".quad 0x662e646461090a3b,0x3038662509203233,0x202c31366625202c,0x66090a3b39376625\n"
".quad 0x33662e6e722e616d,0x2c31386625092032,0x25202c3733662520,0x386625202c353666\n"
".quad 0x2e617262090a3b30,0x744c240920696e75,0x32303832315f375f,0x5f375f744c240a3b\n"
".quad 0x200a3a3835303331,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c383332,0x656c6562616c2064,0x5f375f744c242064\n"
".quad 0x6d090a3433303231,0x09203233662e766f,0x6630202c31386625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3766250920323366,0x3030306630202c36\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c313766250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x744c240a30202f2f,0x32303832315f375f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c38333220656e,0x62616c2064616568,0x744c242064656c65,0x34333032315f375f\n"
".quad 0x3109636f6c2e090a,0x0a30093434320937,0x3233662e64646109,0x202c383266250920\n"
".quad 0x6625202c31376625,0x646461090a3b3832,0x662509203233662e,0x36376625202c3732\n"
".quad 0x0a3b37326625202c,0x3233662e64646109,0x202c363266250920,0x6625202c31386625\n"
".quad 0x5f744c240a3b3632,0x3a30393232315f37,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3833322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333032315f37,0x3233752e64646109,0x202c353372250920\n"
".quad 0x3b31202c35337225,0x6e2e70746573090a,0x2509203233752e65,0x34337225202c3670\n"
".quad 0x0a3b35337225202c,0x7262203670254009,0x375f744c24092061,0x0a3b34333032315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39363220,0x6c6562616c206461,0x375f744c24206465,0x090a34353730315f\n"
".quad 0x20696e752e617262,0x315f375f744c2409,0x4c240a3b30313031,0x353834315f375f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x353730315f375f74\n"
".quad 0x662e766f6d090a34,0x3632662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x30202c3732662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x30306630202c3832\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x6e752e617262090a,0x375f744c24092069\n"
".quad 0x0a3b30313031315f,0x31315f375f744c24,0x2f2f200a3a363632,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x30315f375f744c24,0x766f6d090a343537,0x662509203233662e\n"
".quad 0x30306630202c3632,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c37326625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c38326625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x375f744c240a3020,0x0a3a30313031315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220,0x6c6562616c206461\n"
".quad 0x375f744c24206465,0x090a34353730315f,0x09373109636f6c2e,0x61090a3009373732\n"
".quad 0x09203233662e6464,0x6625202c35326625,0x35326625202c3832,0x662e646461090a3b\n"
".quad 0x3432662509203233,0x202c37326625202c,0x61090a3b34326625,0x09203233662e6464\n"
".quad 0x6625202c33326625,0x33326625202c3632,0x732e646461090a3b,0x3632722509203233\n"
".quad 0x202c36327225202c,0x70746573090a3b31,0x203233732e656e2e,0x7225202c37702509\n"
".quad 0x37317225202c3632,0x2037702540090a3b,0x744c240920617262,0x34353730315f375f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363220656e,0x62616c2064616568,0x744c242064656c65,0x0a363839395f375f\n"
".quad 0x3233732e64646109,0x202c353272250920,0x3b31202c35327225,0x33732e646461090a\n"
".quad 0x2c31327225092032,0x31202c3132722520,0x752e766f6d090a3b,0x3833722509203233\n"
".quad 0x6573090a3b32202c,0x33732e656e2e7074,0x202c387025092032,0x7225202c35327225\n"
".quad 0x702540090a3b3833,0x2409206172622038,0x3839395f375f744c,0x6c3c2f2f200a3b36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x383132395f375f74,0x33732e646461090a\n"
".quad 0x2c30327225092032,0x31202c3032722520,0x732e646461090a3b,0x3931722509203233\n"
".quad 0x202c39317225202c,0x2e766f6d090a3b31,0x3372250920323375,0x73090a3b32202c39\n"
".quad 0x732e656e2e707465,0x2c39702509203233,0x25202c3032722520,0x2540090a3b393372\n"
".quad 0x0920617262203970,0x32395f375f744c24,0x6f6c2e090a3b3831,0x3338320937310963\n"
".quad 0x632e646c090a3009,0x3233662e74736e6f,0x202c323866250920,0x2b736d617261705b\n"
".quad 0x6461090a3b5d3231,0x2509203233662e64,0x386625202c333866,0x3b32326625202c32\n"
".quad 0x6e6f632e646c090a,0x09203233662e7473,0x705b202c34386625,0x5d342b736d617261\n"
".quad 0x662e627573090a3b,0x3538662509203233,0x202c34386625202c,0x646c090a3b326625\n"
".quad 0x662e74736e6f632e,0x3638662509203233,0x6d617261705b202c,0x73090a3b5d302b73\n"
".quad 0x09203233662e6275,0x6625202c37386625,0x3b316625202c3638,0x6e6f632e646c090a\n"
".quad 0x09203233662e7473,0x705b202c38386625,0x5d382b736d617261,0x662e627573090a3b\n"
".quad 0x3938662509203233,0x202c38386625202c,0x756d090a3b336625,0x2509203233662e6c\n"
".quad 0x386625202c303966,0x3b35386625202c35,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x37386625202c3139,0x202c37386625202c,0x66090a3b30396625,0x33662e6e722e616d\n"
".quad 0x2c32396625092032,0x25202c3938662520,0x396625202c393866,0x74727173090a3b31\n"
".quad 0x203233662e6e722e,0x25202c3339662509,0x6573090a3b323966,0x33662e74672e7074\n"
".quad 0x2c30317025092032,0x25202c3338662520,0x2140090a3b333966,0x6172622030317025\n"
".quad 0x5f375f744c240920,0x090a3b3439353431,0x09373109636f6c2e,0x6e090a3009313032\n"
".quad 0x09203233662e6765,0x6625202c34396625,0x2e67656e090a3b34,0x3966250920323366\n"
".quad 0x0a3b366625202c35,0x2e6e722e76696409,0x3966250920323366,0x2c37386625202c36\n"
".quad 0x090a3b3339662520,0x662e6e722e766964,0x3739662509203233,0x202c35386625202c\n"
".quad 0x64090a3b33396625,0x33662e6e722e7669,0x2c38396625092032,0x25202c3938662520\n"
".quad 0x756d090a3b333966,0x2509203233662e6c,0x396625202c393966,0x0a3b356625202c37\n"
".quad 0x3233662e67656e09,0x2c30303166250920,0x090a3b3939662520,0x662e6e722e616d66\n"
".quad 0x3031662509203233,0x2c34396625202c31,0x25202c3639662520,0x66090a3b30303166\n"
".quad 0x33662e6e722e616d,0x3230316625092032,0x202c35396625202c,0x6625202c38396625\n"
".quad 0x6d66090a3b313031,0x3233662e6e722e61,0x2c33303166250920,0x25202c3639662520\n"
".quad 0x6625202c32303166,0x2e67656e090a3b34,0x3166250920323366,0x30316625202c3430\n"
".quad 0x2e616d66090a3b33,0x09203233662e6e72,0x25202c3530316625,0x316625202c373966\n"
".quad 0x3b356625202c3230,0x33662e67656e090a,0x3630316625092032,0x3b3530316625202c\n"
".quad 0x6e722e616d66090a,0x662509203233662e,0x396625202c373031,0x3230316625202c38\n"
".quad 0x090a3b366625202c,0x203233662e67656e,0x202c383031662509,0x090a3b3730316625\n"
".quad 0x09373109636f6c2e,0x73090a3009383032,0x09203233662e6275,0x25202c3930316625\n"
".quad 0x396625202c333866,0x632e646c090a3b33,0x3233662e74736e6f,0x2c30313166250920\n"
".quad 0x736d617261705b20,0x6d090a3b5d34382b,0x09203233662e6c75,0x25202c3131316625\n"
".quad 0x6625202c30313166,0x646c090a3b393031,0x662e74736e6f632e,0x3131662509203233\n"
".quad 0x617261705b202c32,0x0a3b5d38382b736d,0x736e6f632e646c09,0x2509203233662e74\n"
".quad 0x705b202c33313166,0x32392b736d617261,0x2e6c756d090a3b5d,0x3166250920323366\n"
".quad 0x36396625202c3431,0x3b3131316625202c,0x6e722e616d66090a,0x662509203233662e\n"
".quad 0x346625202c353131,0x2c3231316625202c,0x0a3b343131662520,0x3233662e6c756d09\n"
".quad 0x2c36313166250920,0x202c343031662520,0x090a3b3331316625,0x203233662e627573\n"
".quad 0x202c373131662509,0x25202c3631316625,0x6d090a3b35313166,0x09203233662e6c75\n"
".quad 0x25202c3831316625,0x316625202c373966,0x616d66090a3b3131,0x203233662e6e722e\n"
".quad 0x202c393131662509,0x316625202c356625,0x31316625202c3231,0x2e6c756d090a3b38\n"
".quad 0x3166250920323366,0x30316625202c3032,0x3331316625202c36,0x662e627573090a3b\n"
".quad 0x3231662509203233,0x3032316625202c31,0x3b3931316625202c,0x33662e6c756d090a\n"
".quad 0x3232316625092032,0x202c38396625202c,0x090a3b3131316625,0x662e6e722e616d66\n"
".quad 0x3231662509203233,0x202c366625202c33,0x25202c3231316625,0x6d090a3b32323166\n"
".quad 0x09203233662e6c75,0x25202c3432316625,0x6625202c38303166,0x7573090a3b333131\n"
".quad 0x2509203233662e62,0x6625202c35323166,0x316625202c343231,0x617262090a3b3332\n"
".quad 0x4c240920696e752e,0x333334315f375f74,0x375f744c240a3b38,0x0a3a34393534315f\n"
".quad 0x3233662e766f6d09,0x2c35323166250920,0x3030303030663020,0x092020203b303030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x6630202c31323166,0x3030303030303030\n"
".quad 0x202f2f092020203b,0x662e766f6d090a30,0x3131662509203233,0x3030306630202c37\n"
".quad 0x20203b3030303030,0x240a30202f2f0920,0x3334315f375f744c,0x6f6c2e090a3a3833\n"
".quad 0x3338320937310963,0x2e646461090a3009,0x3266250920323366,0x3731316625202c35\n"
".quad 0x0a3b35326625202c,0x3233662e64646109,0x202c343266250920,0x25202c3132316625\n"
".quad 0x6461090a3b343266,0x2509203233662e64,0x316625202c333266,0x33326625202c3532\n"
".quad 0x09636f6c2e090a3b,0x3009363832093731,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5b202c3731647225,0x6170616475635f5f,0x6f63385a5f5f6d72,0x3650446564696c6c\n"
".quad 0x30533474616f6c66,0x31536a505f30535f,0x72675f6a5f31535f,0x6369747261506469\n"
".quad 0x5d7865646e49656c,0x6c2e6c756d090a3b,0x2509203436752e6f,0x7225202c38316472\n"
".quad 0x090a3b34202c3164,0x203436752e646461,0x202c393164722509,0x25202c3731647225\n"
".quad 0x6c090a3b38316472,0x6c61626f6c672e64,0x722509203233752e,0x6472255b202c3034\n"
".quad 0x090a3b5d302b3931,0x09373109636f6c2e,0x6c090a3009373832,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x635f5f5b202c3032,0x5f6d726170616475,0x696c6c6f63385a5f\n"
".quad 0x6f6c663650446564,0x30535f3053347461,0x31535f31536a505f,0x655677656e5f6a5f\n"
".quad 0x747663090a3b5d6c,0x3233752e3436752e,0x2c31326472250920,0x090a3b3034722520\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x347225202c323264,0x090a3b3631202c30\n"
".quad 0x203436752e646461,0x202c333264722509,0x25202c3032647225,0x61090a3b32326472\n"
".quad 0x09203233662e6464,0x25202c3632316625,0x35326625202c3466,0x662e646461090a3b\n"
".quad 0x3231662509203233,0x202c356625202c37,0x61090a3b34326625,0x09203233662e6464\n"
".quad 0x25202c3832316625,0x33326625202c3666,0x662e766f6d090a3b,0x3231662509203233\n"
".quad 0x3030306630202c39,0x20203b3030303030,0x090a30202f2f0920,0x61626f6c672e7473\n"
".quad 0x3233662e34762e6c,0x33326472255b0920,0x66257b202c5d302b,0x323166252c363231\n"
".quad 0x2c38323166252c37,0x0a3b7d3932316625,0x5f5f373242424c24,0x64696c6c6f63385a\n"
".quad 0x616f6c6636504465,0x5f30535f30533474,0x5f31535f31536a50,0x636f6c2e090a3a6a\n"
".quad 0x0938383209373109,0x3b74697865090a30,0x646e6557444c240a,0x6c6c6f63385a5f5f\n"
".quad 0x6c66365044656469,0x535f30533474616f,0x535f31536a505f30,0x207d090a3a6a5f31\n"
".quad 0x6f63385a5f202f2f,0x3650446564696c6c,0x30533474616f6c66,0x31536a505f30535f\n"
".quad 0x000a0a6a5f31535f\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[4869];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_20$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x00000000000024bc,0x0000000000000040,0x0038004000140114,0x0001001300400006\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000500\n"
".quad 0x00000000000002a9,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x00000000000007a9\n"
".quad 0x00000000000000c9,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000872\n"
".quad 0x00000000000002a0,0x0000001500000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x000000010000015c,0x0000000000000006,0x0000000000000000,0x0000000000000b12\n"
".quad 0x00000000000001a0,0x1000000d00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000024b,0x0000000000000002,0x0000000000000000,0x0000000000000cb2\n"
".quad 0x0000000000000038,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000017c,0x0000000000000002,0x0000000000000000,0x0000000000000cea\n"
".quad 0x0000000000000070,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000119,0x0000000000000006,0x0000000000000000,0x0000000000000d5a\n"
".quad 0x0000000000000550,0x1400000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000273,0x0000000000000002,0x0000000000000000,0x00000000000012aa\n"
".quad 0x000000000000003c,0x0000000700000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000139,0x0000000000000002,0x0000000000000000,0x00000000000012e6\n"
".quad 0x0000000000000070,0x0000000700000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000094,0x0000000000100006,0x0000000000000000,0x0000000000001356\n"
".quad 0x0000000000000268,0x1200000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000202,0x0000000000000002,0x0000000000000000,0x00000000000015be\n"
".quad 0x0000000000000064,0x0000000a00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000d5,0x0000000000000002,0x0000000000000000,0x0000000000001622\n"
".quad 0x00000000000000d4,0x0000000a00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x00000000000016f6\n"
".quad 0x0000000000000ba8,0x3f00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001d1,0x0000000000000002,0x0000000000000000,0x000000000000229e\n"
".quad 0x0000000000000054,0x0000000d00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000019f,0x0000000000000002,0x0000000000000000,0x00000000000022f2\n"
".quad 0x000000000000000c,0x0000000d00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000005f,0x0000000000000002,0x0000000000000000,0x00000000000022fe\n"
".quad 0x00000000000000ac,0x0000000d00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000029b,0x0000000000000002,0x0000000000000000,0x00000000000023aa\n"
".quad 0x0000000000000068,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000008b,0x0000000000000002,0x0000000000000000,0x0000000000002412\n"
".quad 0x00000000000000a8,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x63385a5f2e747865\n"
".quad 0x50446564696c6c6f,0x533474616f6c6636,0x536a505f30535f30,0x2e006a5f31535f31\n"
".quad 0x2e6f666e692e766e,0x696c6c6f63385a5f,0x6f6c663650446564,0x30535f3053347461\n"
".quad 0x31535f31536a505f,0x692e766e2e006a5f,0x7865742e006f666e,0x657238325a5f2e74\n"
".quad 0x746144726564726f,0x646e6946646e4161,0x726174536c6c6543,0x36505f536a504474\n"
".quad 0x31533474616f6c66,0x5f31535f535f535f,0x766e2e006a5f3153,0x5a5f2e6f666e692e\n"
".quad 0x6564726f65723832,0x646e416174614472,0x6c6c6543646e6946,0x6a50447472617453\n"
".quad 0x616f6c6636505f53,0x535f535f31533474,0x6a5f31535f31535f,0x5f2e747865742e00\n"
".quad 0x6148636c6163395a,0x505f536a50446873,0x6a3474616f6c6636,0x666e692e766e2e00\n"
".quad 0x6c6163395a5f2e6f,0x6a50446873614863,0x616f6c6636505f53,0x7865742e006a3474\n"
".quad 0x746e69395a5f2e74,0x3650657461726765,0x30533474616f6c66,0x2e766e2e006a665f\n"
".quad 0x395a5f2e6f666e69,0x7461726765746e69,0x74616f6c66365065,0x2e006a665f305334\n"
".quad 0x74736e6f632e766e,0x5a5f2e3631746e61,0x6564696c6c6f6338,0x74616f6c66365044\n"
".quad 0x505f30535f305334,0x6a5f31535f31536a,0x6e6f632e766e2e00,0x5f2e30746e617473\n"
".quad 0x64696c6c6f63385a,0x616f6c6636504465,0x5f30535f30533474,0x5f31535f31536a50\n"
".quad 0x6f632e766e2e006a,0x2e30746e6174736e,0x726f657238325a5f,0x4161746144726564\n"
".quad 0x6543646e6946646e,0x4474726174536c6c,0x6c6636505f536a50,0x535f31533474616f\n"
".quad 0x31535f31535f535f,0x632e766e2e006a5f,0x30746e6174736e6f,0x65746e69395a5f2e\n"
".quad 0x6636506574617267,0x5f30533474616f6c,0x632e766e2e006a66,0x30746e6174736e6f\n"
".quad 0x636c6163395a5f2e,0x536a504468736148,0x74616f6c6636505f,0x632e766e2e006a34\n"
".quad 0x32746e6174736e6f,0x6c6f63385a5f0000,0x663650446564696c,0x5f30533474616f6c\n"
".quad 0x5f31536a505f3053,0x635f5f006a5f3153,0x30326d735f616475,0x5f6e725f7669645f\n"
".quad 0x75635f5f00323366,0x5f30326d735f6164,0x5f6e725f74727173,0x38325a5f00323366\n"
".quad 0x44726564726f6572,0x6946646e41617461,0x74536c6c6543646e,0x5f536a5044747261\n"
".quad 0x3474616f6c663650,0x535f535f535f3153,0x5f006a5f31535f31,0x6148636c6163395a\n"
".quad 0x505f536a50446873,0x6a3474616f6c6636,0x65746e69395a5f00,0x6636506574617267\n"
".quad 0x5f30533474616f6c,0x6d61726170006a66,0x0000000000000073,0x0000000000000000\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000002,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000003,0x0000000000000000,0x0003000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000000d,0x000000000ba80000,0x0003000000000000\n"
".quad 0x0000000000000010,0x0000000000000000,0x0003000000000000,0x0000000000000012\n"
".quad 0x0000000000000000,0x0003000000000000,0x000000000000000a,0x0000000002680000\n"
".quad 0x0003000000000000,0x000000000000000c,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000007,0x0000000005500000,0x0003000000000000,0x0000000000000009\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000004,0x0000000001a00000\n"
".quad 0x0003000000000000,0x0000000000000006,0x0000000000000000,0x0003000000000000\n"
".quad 0x000000000000000f,0x0000000000000000,0x0003000000000000,0x000000000000000e\n"
".quad 0x0000000000000000,0x0003000000000000,0x000000000000000b,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000005,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000008,0x0000000000000000,0x0003000000000000,0x0000000000000011\n"
".quad 0x0000000000000000,0x1012000000010000,0x000000000000000d,0x0000000007400000\n"
".quad 0x0012000000240000,0x0000000001e0000d,0x0000000003700000,0x00120000003b0000\n"
".quad 0x000000000ab0000d,0x0000000000f80000,0x1012000000530000,0x000000000000000a\n"
".quad 0x0000000002680000,0x10120000008e0000,0x0000000000000007,0x0000000001e00000\n"
".quad 0x1012000000a80000,0x0000000000000004,0x0000000001a00000,0x0011000000c20000\n"
".quad 0x0000000000000011,0x0000000000680000,0x440400005de40000,0x000094001c042800\n"
".quad 0x400020009de42c00,0x00008400dc042800,0xc06000001c032c00,0xc06000209c037000\n"
".quad 0x000008001c037000,0x4000d001dc032006,0x0000000021e7188e,0x000040009de28000\n"
".quad 0xc0004000dc431800,0x4000c003dde45000,0x8000a0031c032800,0x480080039de42005\n"
".quad 0x4000b0335c432800,0x800080009c034800,0x480080001de42005,0x000000c11cc52800\n"
".quad 0x40009030dc438400,0xcfe000001e004800,0xefe000e39c005000,0x000000221cc55000\n"
".quad 0x480040f11c008400,0x480050f15c003008,0x480060f19c00300a,0x480070411c00300c\n"
".quad 0x480070515c005800,0x480070619c005800,0x4000c0421c005800,0x4000c0525c003010\n"
".quad 0x4000c0629c003012,0x00002001dc003014,0x00002403dc00208e,0x00002805dc00208e\n"
".quad 0x0000000201e4208e,0x0000000245e42800,0x0000000289e42800,0x4801904100002800\n"
".quad 0x4801905144005800,0x4801906188005800,0x000020e1dc005800,0x000028e3dc00220e\n"
".quad 0x000024e5dc00220e,0x0000380201e4220e,0x0000380285e42800,0x0000380249e42800\n"
".quad 0x4801904100002800,0x4801906184005800,0x4801905148005800,0x000000221cc55800\n"
".quad 0x000000c11cc59400,0x000000001de79400,0x0000000000008000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x000000100c040000,0x0010000000080000,0x0a04000000140000\n"
".quad 0x0020000000120008,0x1704001819030018,0x0003ffffffff000c,0x17040011f0000014\n"
".quad 0x0002ffffffff000c,0x17040011f0000010,0x0001ffffffff000c,0x17040021f0000008\n"
".quad 0x0000ffffffff000c,0x0d040021f0000000,0x0002000300240008,0x440400005de40000\n"
".quad 0x000094001c042800,0x400020009de42c00,0x00008400dc042800,0xc06000001c032c00\n"
".quad 0xc06000209c037000,0x000008009c037000,0x4000e021dc032006,0x0000000021e7188e\n"
".quad 0x4000c000dde48000,0xc00040201c432800,0x480110015de45000,0xc00040219c032800\n"
".quad 0x4000d001dc432007,0x000000641cc54800,0x4800e1111d008400,0x0005600100075000\n"
".quad 0x4800a000dde45000,0x000011201c842800,0x480090011de41002,0xfffffc30dc032800\n"
".quad 0x000001201c844800,0x480120015de41406,0x00000c001c032800,0xc0600040dc036800\n"
".quad 0x4800f1211d007000,0xc06000001c035000,0x00000c00dc037000,0x0003e00100075000\n"
".quad 0x4800b0015de45000,0x000011201c842800,0xfffffc511c031002,0x000001201c844800\n"
".quad 0x4800a0015de41406,0x000010001c032800,0xc06000511c036800,0x480090015de47000\n"
".quad 0xc06000001c032800,0xc06000519c037000,0x000010001c037000,0x480100015de45000\n"
".quad 0x4800d1011d002800,0xc06000001c035000,0x00001800dc037000,0x0001e00100072006\n"
".quad 0x000011201c845000,0x480090011de41002,0x00001001dde22800,0x000001201c841800\n"
".quad 0xfffffc415c031406,0xc00010219c434800,0x800080211c035000,0x000014001c03200f\n"
".quad 0x400090615c436800,0x8000a0221c034800,0x000000301c03200f,0x4000b0625c434800\n"
".quad 0x000000401c854800,0x000000809c859400,0x000000001de79400,0xc00004401c038000\n"
".quad 0xc00004519c036000,0xc00060001c036000,0xc00060619c035800,0xfffffc001c035800\n"
".quad 0xfffffc619c034800,0xc003f401dc034800,0xc003f461dc031a0e,0x0005200021e71a20\n"
".quad 0xdfe00041dc804000,0x00001121dc44298e,0x0000600021e71080,0xdfe00051dc804000\n"
".quad 0x000015221c44298e,0x0000400001e71080,0x000014411c204000,0x000b80001de75000\n"
".quad 0xc00004425c034000,0xc00004529c036000,0x0000fc93dc036000,0x0000fca5dc03190e\n"
".quad 0x00000811dc04190e,0x0000800001e70c0e,0xdfe00077dc004000,0xdfe00081dc00290e\n"
".quad 0x000080002de7290e,0x0000600021e74000,0x000000001de24000,0x000014011c001bff\n"
".quad 0x0009e0001de7c800,0x00004401dc044000,0x0000600021e70c0e,0x000010501c834000\n"
".quad 0x000000011c026800,0x000940001de73a00,0x00004831dc044000,0x0000800021e70c0e\n"
".quad 0x000010501c834000,0x000000001c026800,0x000000011c423a00,0x000880001de739fe\n"
".quad 0x0000fc01dc234000,0x0000fc63dc231b0e,0xffff0001e1e21b0e,0xd7e0004120001bff\n"
".quad 0x0000fc01c1e4307e,0x0000800005e72800,0xd7e000515c004000,0xc0010071dc03307e\n"
".quad 0x000020001de74800,0x0000fc01dde44000,0xfffe08625c032800,0xfffe08021c034800\n"
".quad 0x000018001d034800,0x000014915ee34800,0x000010811ee34100,0x000010521c004100\n"
".quad 0x000020425c00c800,0x000024529e00307e,0x000020a25c003008,0x000024515e003012\n"
".quad 0x000020511c003008,0xc00004429c033012,0xc00060a19c036000,0x000018001c035800\n"
".quad 0x00000071dc034800,0xfffffc701c034800,0xc003f401dc034800,0x0000600001e71a0e\n"
".quad 0x000018701d034000,0x000010011ee34800,0x0004a0001de74000,0xc003f871dc234000\n"
".quad 0x0000600001e7198e,0x000000401c024000,0x000000011c423a00,0x000400001de739fe\n"
".quad 0x0000fc71dc234000,0x0003c00001e71a0e,0xffffa071dc234000,0x0000400001e71b0e\n"
".quad 0x000000411c024000,0x000340001de73a00,0x000020529c004000,0x000020519c003112\n"
".quad 0x000020515c003092,0x00001d225f843192,0x000000401c021c00,0x000018a11c003a00\n"
".quad 0xfffffc515c021e8e,0x0000fc91dc233801,0x00001d221f84190e,0x000011211f841c00\n"
".quad 0x000000525c421c00,0x0000a00081e73802,0xc000807160034000,0x0000149160034800\n"
".quad 0x0000209260036000,0xc00007f160035800,0x000014412043310a,0xc00078915c036800\n"
".quad 0xc0007c519c036000,0xc00004915c035800,0x000018411c436800,0x000010511c036800\n"
".quad 0xc00004915c036800,0x0000fc41dc035800,0xc000045140031a8e,0x000014011c434800\n"
".quad 0x000000001de76800,0x0000000000009000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0c04000000000000,0x0008000000000010,0x0018000000100000,0x001300080a040000\n"
".quad 0x1903001c00200000,0xffff000c1704001c,0xf00000180003ffff,0xffff000c17040011\n"
".quad 0xf00000100002ffff,0xffff000c17040021,0xf00000080001ffff,0xffff000c17040021\n"
".quad 0xf00000000000ffff,0x00b400080d040021,0x5de40000000d000f,0x1c04280044040000\n"
".quad 0x9de42c0000009400,0xdc04280040002000,0x1c032c0000008400,0x9c037000c0600000\n"
".quad 0x00077000c0600020,0x1c0360000001e000,0xdc03200600000800,0x21f4188e40018001\n"
".quad 0x1de4400000000000,0x9c43280040010001,0xdc035000c0001000,0x9c031a8e0000fc03\n"
".quad 0x1e032009c0001001,0xdc036000c0000831,0xdc4319020000fc33,0x9c85480040011021\n"
".quad 0x4485840000000060,0x9c8587fffffff061,0x4485c90000001040,0x1df4c900000003f1\n"
".quad 0xdc03400000000000,0xdc04207e0000fc1f,0x21e750ee0000ffff,0xdc03800000000000\n"
".quad 0x0007190e0000fc01,0x01e7600000028000,0x1e03400000008000,0x1c856000c0000831\n"
".quad 0xdc03c10000000041,0x01e7190e00001021,0x5de440000001c000,0x1c43280040008001\n"
".quad 0xdc035000c0001021,0x9c03190e0000fc01,0xdc43200bc0001021,0x1c85480040009041\n"
".quad 0x81e7940000000060,0xe20340000000e000,0x21e46000c0000830,0xe08528004000a001\n"
".quad 0x2003c10000000030,0xe0432009c0001031,0x60435000c0001030,0x208548004000b031\n"
".quad 0xddf4940000000040,0xdc03280040018000,0xdc034800fffffc30,0x81e71a8e00000c01\n"
".quad 0x21e440000000c000,0xe04328004000a001,0x20035000c0001020,0xa0032009c0001021\n"
".quad 0x60434800c0000400,0xa08548004000b031,0xdde4940000000040,0x9c43280040012000\n"
".quad 0x5de25000c0001000,0x1c03180000004004,0x1c432007c0001001,0x5c435000c0004004\n"
".quad 0x9c85480040013021,0xdc43840000000040,0x9c035000c0004020,0xdc43202380014023\n"
".quad 0x1c03480040015033,0x1cc5202380016023,0x5c438400000000e2,0x9c03480040017033\n"
".quad 0x1cc520238000c000,0xdc438400000000c1,0x1c0348004000d100,0x5c4320238000e003\n"
".quad 0x1cc548004000f103,0x1cc5940000000022,0x1de79400000000c1,0x0000800000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x000000240c040000,0x0010000000080000,0x0020000000180000,0x0030000000280000\n"
".quad 0x0040000000380000,0x001100080a040000,0x1903004400200000,0xffff000c17040044\n"
".quad 0xf00000400008ffff,0xffff000c17040011,0xf00000380007ffff,0xffff000c17040021\n"
".quad 0xf00000300006ffff,0xffff000c17040021,0xf00000280005ffff,0xffff000c17040021\n"
".quad 0xf00000200004ffff,0xffff000c17040021,0xf00000180003ffff,0xffff000c17040021\n"
".quad 0xf00000100002ffff,0xffff000c17040021,0xf00000080001ffff,0xffff000c17040021\n"
".quad 0xf00000000000ffff,0x003c00080d040021,0x5de4000000040005,0x1c04280044040000\n"
".quad 0x9de42c0000009400,0xdc04280040002000,0x1c232c0000008400,0x9c237000c0600000\n"
".quad 0x1ca37000c0600020,0xdc03200600000807,0x21e7188e400141c1,0x1de2800000000000\n"
".quad 0x1c43180000004001,0x5de45000c00041c0,0x9c03280048010001,0xdc4320098000a1c0\n"
".quad 0x9c0348004000b000,0x1cc520098000c1c1,0xdc43840000000026,0x1cc548004000d001\n"
".quad 0x1d00840000000065,0x000750004800d181,0x1c845000001a8001,0x5de4100200001120\n"
".quad 0x1d00280048011001,0x9c8450004800e191,0x0007140600000120,0x1c8450000019e001\n"
".quad 0x5de4100200001120,0x1d00280048012001,0xdc8450004800f1a1,0x0007140600000120\n"
".quad 0x1c84500000194001,0x5c03100200001120,0x9c034800fffffc27,0x9de24800c0000827\n"
".quad 0x1c841bfffffffc00,0x9c03140600000120,0x1de24800fffffc3e,0x5de41bfffffffc0b\n"
".quad 0x9de428000000fc0b,0xdde428000000fc0b,0xdc0328000000fc0b,0xdc0348004800a025\n"
".quad 0xdc03480048009026,0x1de24800fffffc07,0x9de41bfffffffc00,0xdde428004800a000\n"
".quad 0x1c03280048009000,0x9c0348004800b000,0x1de47000c0600020,0x1c0328000000e80c\n"
".quad 0x9de26800000001f0,0x1c031bfffffffc0c,0x1c037000c0600000,0x9c03500000000800\n"
".quad 0x1c037000c0600030,0x5c037000c0600000,0x1c0350000000080c,0x9de4680000005f00\n"
".quad 0xdde4280048009000,0x1c0328000000740c,0x9c037000c0600000,0x00077000c0600020\n"
".quad 0x1c036800000c8000,0x1c0320620000080d,0x0007680000006f30,0x1c036000000b4000\n"
".quad 0x9e03480000000340,0x1c436000c0000800,0x1c035000c0001000,0x5c43480140010021\n"
".quad 0x5c85480040011001,0xdc0384000000004d,0x01e7190effffff51,0x9c0340000009e000\n"
".quad 0xdc43480140012020,0x5c85480040013000,0xdc0384000000002e,0x01e71b0e0000e751\n"
".quad 0x9de440000008e000,0xdde428000000fc0d,0x1de428000000fc0d,0xdc0328000000fc0e\n"
".quad 0x0007190e0000d5c1,0x01f460000007c000,0x9de2400000000000,0x1c43180000004000\n"
".quad 0x1c035000c0004350,0x5c4320058000a352,0x9c0348004000b002,0x1cc520058000c350\n"
".quad 0xdc43840000000081,0x1cc548004000d000,0x9d00840000000024,0xdd00500000006450\n"
".quad 0x1de4500000006040,0x1c00280048008001,0x1d00580000000820,0xdc0050000000686f\n"
".quad 0x1c00500048008044,0x1c00300000000c30,0x000730000000f3c1,0xdc005000001e2001\n"
".quad 0xdde4220e00001131,0x000728000000100e,0x21e760000004c000,0x1d00400000044000\n"
".quad 0x5d00500000005104,0x9d00500000005514,0x1de4500000005924,0x5de4280000000c01\n"
".quad 0x000728000000ec01,0x5de45000000f2001,0x5de428000000100f,0x1de428000000ec01\n"
".quad 0x0007280000000801,0x9de45000000ea001,0x5de428000000100f,0x1de428000000ec01\n"
".quad 0x000728000000f001,0x1c005000000e2001,0x5d0058000000f910,0x9c0050000000ed31\n"
".quad 0x1c00580048016101,0xdc0030000000f500,0x5c00580048015051,0x1c00580048016112\n"
".quad 0x9c00300000001120,0x1e00580048016122,0x5e00300c00001fd2,0x5e003020000003d1\n"
".quad 0x9e00301200001fe2,0x1e003022000003e1,0xde00302400000040,0x1c00301400001c41\n"
".quad 0x5c00301048017051,0x9c00301248017061,0x1c00300e48017001,0x9c00300848018030\n"
".quad 0xdc10300a48018020,0xdde4300c480183c0,0x9de428000000fc00,0x1df428000000fc00\n"
".quad 0x1c0028000000fc00,0xdc0050000000e00e,0x9c1050000000dc2d,0x5c0350000000d83d\n"
".quad 0xdc034800c000075d,0x01e71a8e0000d791,0x1df44003fff7a000,0x9de4400000000000\n"
".quad 0xdde428000000fc0d,0x1df428000000fc0d,0x9de428000000fc0e,0xdde428000000fc0d\n"
".quad 0x1df428000000fc0d,0xdc0328000000fc0e,0xdc004800c000073c,0x9c0050000000bf8b\n"
".quad 0xdc2350000000bb7b,0x5c001a8e00007b31,0x21e750000000b76b,0x1de7a80000000000\n"
".quad 0x9c034003fff3a000,0x1c034800c000072c,0xdc234800c000070c,0x01e71a8ec0000b21\n"
".quad 0x1c034003fff24000,0xdc034800c00006cb,0xdc234800c00005f7,0x01e71a8ec0000ac1\n"
".quad 0x5e004003fff02000,0x1e00500048001194,0x9e00500048000184,0x1c005000480021a4\n"
".quad 0x9de4580000004510,0x1c00280048003000,0x9c00300000004100,0x1c00500048008020\n"
".quad 0x0007300000004921,0xdc00500000146001,0xdde4220e00001021,0x0007280000001000\n"
".quad 0x21e7600000040000,0x1de4400000038000,0x5de4280000004001,0x0007280000000c01\n"
".quad 0x1de450000005c001,0x5de4280000001004,0x1de4280000000c01,0x0007280000004401\n"
".quad 0x5de4500000054001,0x5de4280000001004,0x1de4280000000c01,0x0007280000004801\n"
".quad 0x1c0050000004c001,0x9d00580000005510,0x1f00500000000c20,0x9c00300000004140\n"
".quad 0x1e00580048015020,0x5c00300000001160,0x9c00580000000901,0xdc00580000000911\n"
".quad 0x9c00580000000841,0xdc00302800000100,0x1c00302a00000110,0x1c00302c00000041\n"
".quad 0x5c00300a48016140,0x9c00300c48016151,0x1f00300e48016161,0x9f00300048017020\n"
".quad 0xdf10300a48017030,0xdde4300c48017040,0x9de428000000fc00,0x1df428000000fc00\n"
".quad 0x1de428000000fc00,0x5c0328004000e001,0x1c005800c00079c1,0x1c0350000000bc00\n"
".quad 0x9de42009c00011c1,0x1c00280040008001,0x5c43500000000142,0x9c0048004000f051\n"
".quad 0xdc0050000000b820,0x1c8550000000b430,0xdde4840000000041,0x5c0028000000fc02\n"
".quad 0x9c00500000000952,0x9c03500000000d62,0x1c43200dc0004041,0xdc435000c0004040\n"
".quad 0x1cc5480040009001,0x1de7940000000062,0x1c03800000000000,0x9c036000c0000440\n"
".quad 0x1c036000c0000451,0x9c035800c0006000,0xdc035800c0006061,0x1c034800fffffc01\n"
".quad 0xdc034800fffffc62,0xdc031a0ec003f471,0x21e71a20c003f481,0xdc80400000052000\n"
".quad 0x1c44298edfe00041,0x21e7108000001120,0xdc80400000006000,0x9c44298edfe00051\n"
".quad 0x01e7108000001521,0x1c20400000004000,0x1de7500000001441,0x5c034000000b8000\n"
".quad 0x9c036000c0000442,0xdc036000c0000452,0xdc03190e0000fc93,0xdc04190e0000fca5\n"
".quad 0x01e70c0e00000811,0xdc00400000008000,0xdc00290edfe00007,0x2de7290edfe00061\n"
".quad 0x21e7400000008000,0x1de2400000006000,0x1c001bff00000000,0x1de7c80000001401\n"
".quad 0xdc0440000009e000,0x21e70c0e00004401,0x1c83400000006000,0x1c02680000001050\n"
".quad 0x1de73a0000000001,0xdc04400000094000,0x21e70c0e00004831,0x1c83400000008000\n"
".quad 0x1c02680000001050,0x1c423a0000000000,0x1de739fe00000001,0xdc23400000088000\n"
".quad 0xdc231b0e0000fc71,0x21e21b0e0000fc83,0x20001bffffff0000,0x01e4307ed7e00041\n"
".quad 0x05e728000000fc00,0x5c00400000008000,0x1c03307ed7e00051,0x1de74800c0010000\n"
".quad 0x1de4400000002000,0x5c0328000000fc00,0x9c034800fffe0882,0xdd034800fffe0871\n"
".quad 0x5ee3480000002071,0x1ee3410000001491,0x9c00410000001061,0x5c00c80000001051\n"
".quad 0x9e00307e00001842,0x5c00300800002452,0x5e003012000018a2,0x1c00300800002451\n"
".quad 0x9c03301200001851,0x1c036000c0000442,0xdc035800c00060a2,0xdc03480000002071\n"
".quad 0x1c03480000001c01,0xdc034800fffffc70,0x01e71a0ec003f401,0x1d03400000006000\n"
".quad 0x1ee3480000002070,0x1de7400000001001,0xdc2340000004a000,0x01e7198ec003f871\n"
".quad 0x1c02400000006000,0x1c423a0000000040,0x1de739fe00000001,0xdc23400000040000\n"
".quad 0x01e71a0e0000fc71,0xdc2340000003c000,0x01e71b0effffa071,0x1c02400000004000\n"
".quad 0x1de73a0000000041,0x9c00400000034000,0x1c00311200001852,0x5c00309200001852\n"
".quad 0x5f84319200001851,0x1c021c0000001d22,0x1c003a0000000040,0x5c021e8e000020a1\n"
".quad 0xdc233801fffffc51,0x9f84190e0000fc91,0x1f841c0000001d21,0x1c421c0000001121\n"
".quad 0x81e7380200000052,0x600340000000a000,0x60034800c0008071,0x2003600000001481\n"
".quad 0x6003580000001882,0x2043310ac00007f1,0x5c03680000001441,0x9c036000c0007881\n"
".quad 0x5c035800c0007c51,0x1c436800c0000481,0x1c03680000001841,0x5c03680000001051\n"
".quad 0xdc035800c0000481,0x40031a8e0000fc41,0x1c434800c0000451,0x1de7680000001401\n"
".quad 0x1c02900000000000,0xdc030bcc00000040,0x01e7198e40001401,0x1c02400000022000\n"
".quad 0xdc2339fffffffc40,0x21e71a8e0000fc01,0xdc00400000030000,0x21e7288e0000fc41\n"
".quad 0x1de2400000004000,0x1de719fffffffc01,0xdc80400000028000,0x1c44298edfe00041\n"
".quad 0x01e7108000001120,0x1c20400000004000,0x1de75000cfe00041,0xdc0040000001e000\n"
".quad 0x01e7290edfe00001,0x1c0040000001a000,0xdc04307ed7e00041,0x1de70c0e00001c71\n"
".quad 0xdc04400000002000,0x1c000c0e00001cf1,0x5c40c80000001440,0x1c40580000001001\n"
".quad 0x9e005800cfc00000,0x5c00300080002451,0x9c00300a00001851,0x1e00300000001801\n"
".quad 0x1c00300800001450,0x0040300a00001801,0x1de75800cbe00041,0x0000900000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0xffff000000010000,0x0c043f000000727f\n"
".quad 0x000800000000001c,0x0018000000100000,0x0028000000200000,0x0a04000000300000\n"
".quad 0x0020000000100008,0x1704003419030034,0x0006ffffffff000c,0x17040011f0000030\n"
".quad 0x0005ffffffff000c,0x17040021f0000028,0x0004ffffffff000c,0x17040021f0000020\n"
".quad 0x0003ffffffff000c,0x17040021f0000018,0x0002ffffffff000c,0x17040021f0000010\n"
".quad 0x0001ffffffff000c,0x17040021f0000008,0x0000ffffffff000c,0x0d040021f0000000\n"
".quad 0x0020002601c80008,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x001a000812040000,0x1104000000000000\n"
".quad 0x00000000001a0008,0x0016000812040000,0x1104000000000000,0x0000000000160008\n"
".quad 0x0019000812040000,0x1104000000000000,0x0000000000190008,0x0018000812040000\n"
".quad 0x1104000000000000,0x0000000000180008,0x0017000812040000,0x1104000000000000\n"
".quad 0x0000000000170008,0x0016000812040000,0x1104000000000000,0x0000000000160008\n"
".quad 0x0015000812040000,0x1104000000000000,0x0000000000150008,0x0000000600000000\n"
".quad 0x000024bc00000005,0x0000000000000000,0x0000000000000000,0x0000015000000000\n"
".quad 0x0000015000000000,0x0000000400000000,0x6000000000000000,0x00000b1200001a05\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000024800000000,0x0000024800000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x00000d5a00001905,0x0000000000000000\n"
".quad 0x0000000000000000,0x000005fc00000000,0x000005fc00000000,0x0000000400000000\n"
".quad 0x6000000000000000,0x0000135600001805,0x0000000000000000,0x0000000000000000\n"
".quad 0x000003a000000000,0x000003a000000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x000016f600001505,0x0000000000000000,0x0000000000000000,0x00000cb400000000\n"
".quad 0x00000cb400000000,0x0000000400000000,0x0000000100000000,0x000023aa00000005\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000006800000000,0x0000006800000000\n"
".quad 0x0000000400000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_20$[1218];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_20", (char*)__deviceText_$sm_20$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_20$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"7dcac980aed6e8b8",(char*)"/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particleSystem.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x9e5fe7dd,&__elfEntries1};
# 3 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c" 2
struct __T20 {float4 *__par0;float4 *__par1;float __par2;uint __par3;int __dummy_field;};
struct __T21 {uint *__par0;uint *__par1;float4 *__par2;uint __par3;int __dummy_field;};
struct __T22 {uint *__par0;uint *__par1;float4 *__par2;float4 *__par3;uint *__par4;uint *__par5;float4 *__par6;float4 *__par7;uint __par8;int __dummy_field;};
struct __T23 {float4 *__par0;float4 *__par1;float4 *__par2;uint *__par3;uint *__par4;uint *__par5;uint __par6;int __dummy_field;};
extern void __device_stub__Z9integrateP6float4S0_fj(float4 *, float4 *, float, uint);
extern void __device_stub__Z9calcHashDPjS_P6float4j(uint *, uint *, float4 *, uint);
extern void __device_stub__Z28reorderDataAndFindCellStartDPjS_P6float4S1_S_S_S1_S1_j(uint *, uint *, float4 *, float4 *, uint *, uint *, float4 *, float4 *, uint);
extern void __device_stub__Z8collideDP6float4S0_S0_PjS1_S1_j(float4 *, float4 *, float4 *, uint *, uint *, uint *, uint);
static void __sti____cudaRegisterAll_49_tmpxft_00000337_00000000_4_particleSystem_cpp1_ii_e0d6462c(void) __attribute__((__constructor__));
void __device_stub__Z9integrateP6float4S0_fj(float4 *__par0, float4 *__par1, float __par2, uint __par3){ struct __T20 *__T210 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T210->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T210->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T210->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T210->__par3) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float, uint))integrate)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float, uint))integrate))); };}
void integrate( float4 *__cuda_0,float4 *__cuda_1,float __cuda_2,uint __cuda_3)
# 44 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{__device_stub__Z9integrateP6float4S0_fj( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 72 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c"
void __device_stub__Z9calcHashDPjS_P6float4j( uint *__par0, uint *__par1, float4 *__par2, uint __par3) { struct __T21 *__T214 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T214->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T214->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T214->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T214->__par3) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uint *, uint *, float4 *, uint))calcHashD)); (void)cudaLaunch(((char *)((void ( *)(uint *, uint *, float4 *, uint))calcHashD))); }; }
void calcHashD( uint *__cuda_0,uint *__cuda_1,float4 *__cuda_2,uint __cuda_3)
# 99 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{__device_stub__Z9calcHashDPjS_P6float4j( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 112 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c"
void __device_stub__Z28reorderDataAndFindCellStartDPjS_P6float4S1_S_S_S1_S1_j( uint *__par0, uint *__par1, float4 *__par2, float4 *__par3, uint *__par4, uint *__par5, float4 *__par6, float4 *__par7, uint __par8) { struct __T22 *__T215 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T215->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T215->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T215->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T215->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T215->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T215->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T215->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T215->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T215->__par8) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uint *, uint *, float4 *, float4 *, uint *, uint *, float4 *, float4 *, uint))reorderDataAndFindCellStartD)); (void)cudaLaunch(((char *)((void ( *)(uint *, uint *, float4 *, float4 *, uint *, uint *, float4 *, float4 *, uint))reorderDataAndFindCellStartD))); }; }
void reorderDataAndFindCellStartD( uint *__cuda_0,uint *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,uint *__cuda_4,uint *__cuda_5,float4 *__cuda_6,float4 *__cuda_7,uint __cuda_8)
# 126 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{__device_stub__Z28reorderDataAndFindCellStartDPjS_P6float4S1_S_S_S1_S1_j( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8);
# 178 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c"
void __device_stub__Z8collideDP6float4S0_S0_PjS1_S1_j( float4 *__par0, float4 *__par1, float4 *__par2, uint *__par3, uint *__par4, uint *__par5, uint __par6) { struct __T23 *__T289 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T289->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T289->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T289->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T289->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T289->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T289->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T289->__par6) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, uint *, uint *, uint *, uint))collideD)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, uint *, uint *, uint *, uint))collideD))); }; }
void collideD( float4 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,uint *__cuda_3,uint *__cuda_4,uint *__cuda_5,uint __cuda_6)
# 260 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
{__device_stub__Z8collideDP6float4S0_S0_PjS1_S1_j( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 288 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/particles/particles_kernel.cu"
}
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_00000337_00000000_4_particleSystem_cpp1_ii_e0d6462c(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, uint *, uint *, uint *, uint))collideD), (char*)"_Z8collideDP6float4S0_S0_PjS1_S1_j", "_Z8collideDP6float4S0_S0_PjS1_S1_j", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uint *, uint *, float4 *, float4 *, uint *, uint *, float4 *, float4 *, uint))reorderDataAndFindCellStartD), (char*)"_Z28reorderDataAndFindCellStartDPjS_P6float4S1_S_S_S1_S1_j", "_Z28reorderDataAndFindCellStartDPjS_P6float4S1_S_S_S1_S1_j", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uint *, uint *, float4 *, uint))calcHashD), (char*)"_Z9calcHashDPjS_P6float4j", "_Z9calcHashDPjS_P6float4j", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float, uint))integrate), (char*)"_Z9integrateP6float4S0_fj", "_Z9integrateP6float4S0_fj", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&params, (char*)"params", "params", 0, 104, 1, 0); }
# 1 "/tmp/tmpxft_00000337_00000000-1_particleSystem.cudafe1.stub.c" 2

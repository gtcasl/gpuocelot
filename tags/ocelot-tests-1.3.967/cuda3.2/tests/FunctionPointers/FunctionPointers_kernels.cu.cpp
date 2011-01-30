# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.cpp"
# 1 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
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
# 15 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
typedef unsigned char Pixel;
# 18 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
enum SobelDisplayMode {
# 19 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
SOBELDISPLAY_IMAGE,
# 20 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
SOBELDISPLAY_SOBELTEX,
# 21 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
SOBELDISPLAY_SOBELSHARED
# 22 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
};
# 24 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
static char *filterMode[] = {((char *)("Original Filter")), ((char *)("Sobel Shared")), ((char *)("Sobel Shared+Texture")), (__null)};
# 35 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
enum POINT_ENUM {
# 37 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
SOBEL_FILTER,
# 38 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
BOX_FILTER,
# 39 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
LAST_POINT_FILTER
# 40 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
};
# 42 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
enum BLOCK_ENUM {
# 44 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
THRESHOLD_FILTER,
# 45 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
NULL_FILTER,
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
LAST_BLOCK_FILTER
# 47 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
};
# 49 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
extern SobelDisplayMode g_SobelDisplayMode;
# 51 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
extern "C" void sobelFilter(Pixel *, int, int, SobelDisplayMode, float, int, int);
# 52 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
extern "C" void setupTexture(int, int, Pixel *, int);
# 53 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
extern "C" void deleteTexture();
# 54 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
extern "C" void initFilter();
# 55 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.h"
void setupFunctionTables();
# 19 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static texture< unsigned char, 2, cudaReadModeElementType> tex;
# 20 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__attribute__((unused)) extern unsigned char LocalBlock[];
# 21 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static cudaArray *array = (__null);
# 37 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
typedef unsigned char (*blockFunction_t)(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, float);
# 43 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
typedef unsigned char (*pointFunction_t)(unsigned char, float);
# 46 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static blockFunction_t blockFunction;
# 49 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__attribute__((unused)) unsigned char ComputeSobel(unsigned char ul, unsigned char
# 50 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
um, unsigned char
# 51 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ur, unsigned char
# 52 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ml, unsigned char
# 53 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
mm, unsigned char
# 54 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
mr, unsigned char
# 55 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ll, unsigned char
# 56 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
lm, unsigned char
# 57 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
lr, float
# 58 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
fScale)
# 59 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{int volatile ___ = 1;
# 64 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
exit(___);}
# 67 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static unsigned char (*varFunction)(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, float);
# 75 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__attribute__((unused)) unsigned char ComputeBox(unsigned char ul, unsigned char
# 76 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
um, unsigned char
# 77 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ur, unsigned char
# 78 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ml, unsigned char
# 79 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
mm, unsigned char
# 80 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
mr, unsigned char
# 81 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
ll, unsigned char
# 82 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
lm, unsigned char
# 83 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
lr, float
# 84 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
fscale)
# 86 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{int volatile ___ = 1;
# 91 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
exit(___);}
# 93 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__attribute__((unused)) unsigned char Threshold(unsigned char in, float thresh)
# 94 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{int volatile ___ = 1;
# 97 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
exit(___);}
# 103 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static blockFunction_t blockFunction_table[LAST_BLOCK_FILTER];
# 104 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static pointFunction_t pointFunction_table[LAST_POINT_FILTER];
# 109 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static blockFunction_t pComputeSobel;
# 110 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static blockFunction_t pComputeBox;
# 111 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
static pointFunction_t pComputeThreshold;
# 117 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
blockFunction_t h_blockFunction_table[2];
# 118 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
pointFunction_t h_pointFunction_table[2];
# 130 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
void SobelShared(uchar4 *pSobelOriginal, unsigned short SobelPitch, short
# 132 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
BlockWidth, short SharedPitch, short
# 134 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
w, short h, float fScale, int
# 135 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
blockOperation, pointFunction_t pPointFunction) ;
# 235 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
void SobelCopyImage(Pixel *pSobelOriginal, unsigned Pitch, int
# 236 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
w, int h, float fscale) ;
# 249 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
void SobelTex(Pixel *pSobelOriginal, unsigned Pitch, int
# 250 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
w, int h, float fScale, int blockOperation, pointFunction_t pPointOperation) ;
# 275 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
extern "C" void setupTexture(int iw, int ih, Pixel *data, int Bpp)
# 276 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{
# 277 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
cudaChannelFormatDesc desc;
# 279 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
if (Bpp == 1) {
# 280 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
desc = cudaCreateChannelDesc< unsigned char> ();
# 281 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
} else {
# 282 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
desc = cudaCreateChannelDesc< uchar4> ();
# 283 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 285 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMallocArray(&array, &desc, iw, ih), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 285);
# 286 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyToArray(array, 0, 0, data, ((Bpp * sizeof(Pixel)) * iw) * ih, cudaMemcpyHostToDevice), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 286);
# 287 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 289 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
extern "C" void deleteTexture()
# 290 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{
# 291 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaFreeArray(array), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 291);
# 292 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 295 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
void setupFunctionTables()
# 296 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{
# 299 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyFromSymbol(&((h_blockFunction_table)[SOBEL_FILTER]), pComputeSobel, sizeof(blockFunction_t)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 299);
# 300 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyFromSymbol(&((h_blockFunction_table)[BOX_FILTER]), pComputeBox, sizeof(blockFunction_t)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 300);
# 303 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyFromSymbol(&((h_pointFunction_table)[THRESHOLD_FILTER]), pComputeThreshold, sizeof(pointFunction_t)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 303);
# 304 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
((h_pointFunction_table)[NULL_FILTER]) = (__null);
# 308 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyToSymbol(blockFunction_table, h_blockFunction_table, sizeof(blockFunction_t) * (LAST_BLOCK_FILTER)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 308);
# 309 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaMemcpyToSymbol(pointFunction_table, h_pointFunction_table, sizeof(pointFunction_t) * (LAST_POINT_FILTER)), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 309);
# 310 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 317 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
extern "C" void sobelFilter(Pixel *odata, int iw, int ih, SobelDisplayMode mode, float fScale, int blockOperation, int pointOperation)
# 318 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{
# 319 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaBindTextureToArray(tex, array), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 319);
# 320 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
pointFunction_t pPointOp = ((h_pointFunction_table)[pointOperation]);
# 321 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
switch (mode) {
# 322 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
case SOBELDISPLAY_IMAGE:
# 323 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
cudaConfigureCall(ih, 384) ? ((void)0) : SobelCopyImage(odata, iw, iw, ih, fScale);
# 324 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
break;
# 325 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
case SOBELDISPLAY_SOBELTEX:
# 326 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
cudaConfigureCall(ih, 384) ? ((void)0) : SobelTex(odata, iw, iw, ih, fScale, blockOperation, pPointOp);
# 327 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
break;
# 328 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
case SOBELDISPLAY_SOBELSHARED:
# 329 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{
# 330 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
dim3 threads(16, 4);
# 332 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
int BlockWidth = 80;
# 334 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
dim3 blocks = dim3((iw / (4 * BlockWidth)) + (0 != (iw % (4 * BlockWidth))), (ih / (threads.y)) + ((0) != (ih % (threads.y))));
# 336 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
int SharedPitch = ((~63) & ((4 * (BlockWidth + (2 * 1))) + 63));
# 337 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
int sharedMem = (SharedPitch * ((threads.y) + (2 * 1)));
# 340 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
iw &= (~3);
# 342 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
cudaConfigureCall(blocks, threads, sharedMem) ? ((void)0) : SobelShared((uchar4 *)odata, iw, BlockWidth, SharedPitch, iw, ih, fScale, blockOperation, pPointOp);
# 348 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 349 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
break;
# 350 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 352 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
__cudaSafeCall(cudaUnbindTexture(tex), "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu", 352);
# 353 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00007816_00000000-3_FunctionPointers_kernels.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00007816_00000000-3_FunctionPointers_kernels.fatbin.c" 2

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_20$:\n"
".quad 0x6f69737265762e09,0x2e090a322e32206e,0x7320746567726174,0x2f2f090a30325f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x2e33616475632f6c\n"
".quad 0x6f2f616475632f32,0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f\n"
".quad 0x6220322e33206363,0x206e6f20746c6975,0x2d39302d30313032,0x69762e090a0a3830\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233752e206d6172,0x72616475635f5f20\n"
".quad 0x32315a5f5f667465,0x53657475706d6f43,0x686868686c65626f,0x2029666868686868\n"
".quad 0x706d6f4332315a5f,0x6c65626f53657475,0x6868686868686868,0x7261702e28206668\n"
".quad 0x203233752e206d61,0x6170616475635f5f,0x315a5f5f31666d72,0x657475706d6f4332\n"
".quad 0x6868686c65626f53,0x2c66686868686868,0x206d617261702e20,0x635f5f203233752e\n"
".quad 0x666d726170616475,0x6f4332315a5f5f32,0x626f53657475706d,0x6868686868686c65\n"
".quad 0x702e202c66686868,0x33752e206d617261,0x616475635f5f2032,0x5f5f33666d726170\n"
".quad 0x75706d6f4332315a,0x686c65626f536574,0x6868686868686868,0x617261702e202c66\n"
".quad 0x5f203233752e206d,0x726170616475635f,0x32315a5f5f34666d,0x53657475706d6f43\n"
".quad 0x686868686c65626f,0x202c666868686868,0x2e206d617261702e,0x75635f5f20323375\n"
".quad 0x35666d7261706164,0x6d6f4332315a5f5f,0x65626f5365747570,0x686868686868686c\n"
".quad 0x61702e202c666868,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f36666d7261\n"
".quad 0x7475706d6f433231,0x68686c65626f5365,0x6668686868686868,0x6d617261702e202c\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x4332315a5f5f3766,0x6f53657475706d6f\n"
".quad 0x68686868686c6562,0x2e202c6668686868,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5f38666d72617061,0x706d6f4332315a5f,0x6c65626f53657475,0x6868686868686868\n"
".quad 0x7261702e202c6668,0x203233752e206d61,0x6170616475635f5f,0x315a5f5f39666d72\n"
".quad 0x657475706d6f4332,0x6868686c65626f53,0x2c66686868686868,0x206d617261702e20\n"
".quad 0x635f5f203233662e,0x666d726170616475,0x4332315a5f5f3031,0x6f53657475706d6f\n"
".quad 0x68686868686c6562,0x0a0a296668686868,0x6c62697369762e09,0x20636e75662e2065\n"
".quad 0x206d617261702e28,0x635f5f203233752e,0x5f66746572616475,0x706d6f4330315a5f\n"
".quad 0x6868786f42657475,0x6668686868686868,0x6f4330315a5f2029,0x786f42657475706d\n"
".quad 0x6868686868686868,0x7261702e28206668,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f31666d72,0x657475706d6f4330,0x6868686868786f42,0x2e202c6668686868\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5f32666d72617061,0x706d6f4330315a5f\n"
".quad 0x6868786f42657475,0x6668686868686868,0x6d617261702e202c,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x4330315a5f5f3366,0x6f42657475706d6f,0x6868686868686878\n"
".quad 0x61702e202c666868,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261\n"
".quad 0x7475706d6f433031,0x68686868786f4265,0x202c666868686868,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x35666d7261706164,0x6d6f4330315a5f5f,0x68786f4265747570\n"
".quad 0x6868686868686868,0x617261702e202c66,0x5f203233752e206d,0x726170616475635f\n"
".quad 0x30315a5f5f36666d,0x42657475706d6f43,0x686868686868786f,0x702e202c66686868\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x5f5f37666d726170,0x75706d6f4330315a\n"
".quad 0x686868786f426574,0x2c66686868686868,0x206d617261702e20,0x635f5f203233752e\n"
".quad 0x666d726170616475,0x6f4330315a5f5f38,0x786f42657475706d,0x6868686868686868\n"
".quad 0x7261702e202c6668,0x203233752e206d61,0x6170616475635f5f,0x315a5f5f39666d72\n"
".quad 0x657475706d6f4330,0x6868686868786f42,0x2e202c6668686868,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x3031666d72617061,0x6d6f4330315a5f5f,0x68786f4265747570\n"
".quad 0x6868686868686868,0x69762e090a0a2966,0x662e20656c626973,0x61702e2820636e75\n"
".quad 0x3233752e206d6172,0x72616475635f5f20,0x54395a5f5f667465,0x646c6f6873657268\n"
".quad 0x54395a5f20296668,0x646c6f6873657268,0x7261702e28206668,0x203233752e206d61\n"
".quad 0x6170616475635f5f,0x395a5f5f31666d72,0x6c6f687365726854,0x61702e202c666864\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261,0x6f68736572685439\n"
".quad 0x090a0a296668646c,0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f090a2d2d2d2d2d,0x6c69706d6f43202f,0x706d742f20676e69,0x5f746678706d742f\n"
".quad 0x3631383730303030,0x303030303030305f,0x636e75465f372d30,0x6e696f506e6f6974\n"
".quad 0x72656b5f73726574,0x7070632e736c656e,0x6d742f2820692e33,0x2e23494263632f70\n"
".quad 0x0a297431636c4658,0x2d2d2d2d2d2f2f09,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x0a0a2d2d2d2d2d2d,0x2d2d2d2d2d2f2f09,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x090a2d2d2d2d2d2d,0x6f6974704f202f2f,0x2d2f2f090a3a736e,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x20202f2f090a2d2d,0x703a746567726154\n"
".quad 0x3a415349202c7874,0x45202c30325f6d73,0x696c3a6e6169646e,0x6f50202c656c7474\n"
".quad 0x6953207265746e69,0x2f090a34363a657a,0x2809334f2d20202f,0x617a696d6974704f\n"
".quad 0x76656c206e6f6974,0x202f2f090a296c65,0x6544280930672d20,0x6576656c20677562\n"
".quad 0x20202f2f090a296c,0x7065522809326d2d,0x697664612074726f,0x0a29736569726f73\n"
".quad 0x2d2d2d2d2d2f2f09,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a0a2d2d2d2d2d2d\n"
".quad 0x3109656c69662e09,0x616d6d6f633c2209,0x3e656e696c2d646e,0x656c69662e090a22\n"
".quad 0x706d742f22093209,0x5f746678706d742f,0x3631383730303030,0x303030303030305f\n"
".quad 0x636e75465f362d30,0x6e696f506e6f6974,0x72656b5f73726574,0x6475632e736c656e\n"
".quad 0x7570672e32656661,0x656c69662e090a22,0x7273752f22093309,0x6363672f62696c2f\n"
".quad 0x2d34365f3638782f,0x6e672d78756e696c,0x2f332e342e342f75,0x2f6564756c636e69\n"
".quad 0x682e666564647473,0x656c69662e090a22,0x7273752f22093409,0x632f6c61636f6c2f\n"
".quad 0x632f322e33616475,0x2f6e69622f616475,0x756c636e692f2e2e,0x642f7472632f6564\n"
".quad 0x75725f6563697665,0x22682e656d69746e,0x09656c69662e090a,0x2f7273752f220935\n"
".quad 0x75632f6c61636f6c,0x75632f322e336164,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x645f74736f682f65,0x682e73656e696665,0x656c69662e090a22,0x7273752f22093609\n"
".quad 0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x746c6975622f6564,0x73657079745f6e69,0x69662e090a22682e,0x752f22093709656c\n"
".quad 0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x7665642f6564756c,0x657079745f656369,0x662e090a22682e73,0x2f22093809656c69\n"
".quad 0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f32,0x6e692f2e2e2f6e69\n"
".quad 0x72642f6564756c63,0x7079745f72657669,0x2e090a22682e7365,0x22093909656c6966\n"
".quad 0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e,0x692f2e2e2f6e6962\n"
".quad 0x732f6564756c636e,0x745f656361667275,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220930,0x75632f6c61636f6c,0x75632f322e336164,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x7275747865742f65,0x2e73657079745f65,0x6c69662e090a2268\n"
".quad 0x752f220931310965,0x6c61636f6c2f7273,0x322e33616475632f,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x6365762f6564756c,0x657079745f726f74,0x662e090a22682e73\n"
".quad 0x2209323109656c69,0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e\n"
".quad 0x692f2e2e2f6e6962,0x642f6564756c636e,0x616c5f6563697665,0x7261705f68636e75\n"
".quad 0x2e73726574656d61,0x6c69662e090a2268,0x752f220933310965,0x6c61636f6c2f7273\n"
".quad 0x322e33616475632f,0x69622f616475632f,0x636e692f2e2e2f6e,0x7472632f6564756c\n"
".quad 0x656761726f74732f,0x682e7373616c635f,0x656c69662e090a22,0x73752f2209343109\n"
".quad 0x64756c636e692f72,0x742f737469622f65,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220935,0x2f6564756c636e69,0x0a22682e656d6974,0x3109656c69662e09\n"
".quad 0x656d6f682f220936,0x2f776572646e612f,0x6f7469736f706572,0x7570672f73656972\n"
".quad 0x742f746f6c65636f,0x6475632f73747365,0x7365742f322e3361,0x74636e75462f7374\n"
".quad 0x746e696f506e6f69,0x636e75462f737265,0x6e696f506e6f6974,0x72656b5f73726574\n"
".quad 0x0a22682e736c656e,0x3109656c69662e09,0x656d6f682f220937,0x2f776572646e612f\n"
".quad 0x6f7469736f706572,0x7570672f73656972,0x742f746f6c65636f,0x6475632f73747365\n"
".quad 0x7365742f322e3361,0x74636e75462f7374,0x746e696f506e6f69,0x636e75462f737265\n"
".quad 0x6e696f506e6f6974,0x72656b5f73726574,0x2275632e736c656e,0x09656c69662e090a\n"
".quad 0x7273752f22093831,0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x6f6d6d6f632f6564,0x6974636e75665f6e,0x090a22682e736e6f\n"
".quad 0x393109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x6475632f322e3361\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x75665f6874616d2f,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220930320965,0x6c61636f6c2f7273,0x322e33616475632f\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x74616d2f6564756c,0x6174736e6f635f68\n"
".quad 0x090a22682e73746e,0x313209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x6475632f322e3361,0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f6563697665642f\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209323209656c69,0x636f6c2f7273752f\n"
".quad 0x33616475632f6c61,0x2f616475632f322e,0x692f2e2e2f6e6962,0x732f6564756c636e\n"
".quad 0x6f74615f31315f6d,0x636e75665f63696d,0x22682e736e6f6974,0x09656c69662e090a\n"
".quad 0x7273752f22093332,0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x32315f6d732f6564,0x5f63696d6f74615f,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209343209656c69,0x636f6c2f7273752f,0x33616475632f6c61\n"
".quad 0x2f616475632f322e,0x692f2e2e2f6e6962,0x732f6564756c636e,0x756f645f33315f6d\n"
".quad 0x636e75665f656c62,0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093532\n"
".quad 0x632f6c61636f6c2f,0x632f322e33616475,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x30325f6d732f6564,0x5f63696d6f74615f,0x6e6f6974636e7566,0x662e090a22682e73\n"
".quad 0x2209363209656c69,0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f322e\n"
".quad 0x692f2e2e2f6e6962,0x732f6564756c636e,0x746e695f30325f6d,0x2e736369736e6972\n"
".quad 0x6c69662e090a2268,0x752f220937320965,0x6c61636f6c2f7273,0x322e33616475632f\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x7275732f6564756c,0x6e75665f65636166\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209383209,0x2f6c61636f6c2f72\n"
".quad 0x2f322e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f,0x747865742f656475\n"
".quad 0x637465665f657275,0x6974636e75665f68,0x090a22682e736e6f,0x393209656c69662e\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x6475632f322e3361,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x75665f6874616d2f,0x5f736e6f6974636e,0x337874705f6c6264\n"
".quad 0x2e090a0a0a22682e,0x20656c6269736976,0x2e2820636e75662e,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6674657261,0x7475706d6f433231,0x68686c65626f5365\n"
".quad 0x6668686868686868,0x6f4332315a5f2029,0x626f53657475706d,0x6868686868686c65\n"
".quad 0x702e282066686868,0x33752e206d617261,0x616475635f5f2032,0x5f5f31666d726170\n"
".quad 0x75706d6f4332315a,0x686c65626f536574,0x6868686868686868,0x617261702e202c66\n"
".quad 0x5f203233752e206d,0x726170616475635f,0x32315a5f5f32666d,0x53657475706d6f43\n"
".quad 0x686868686c65626f,0x202c666868686868,0x2e206d617261702e,0x75635f5f20323375\n"
".quad 0x33666d7261706164,0x6d6f4332315a5f5f,0x65626f5365747570,0x686868686868686c\n"
".quad 0x61702e202c666868,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f34666d7261\n"
".quad 0x7475706d6f433231,0x68686c65626f5365,0x6668686868686868,0x6d617261702e202c\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x4332315a5f5f3566,0x6f53657475706d6f\n"
".quad 0x68686868686c6562,0x2e202c6668686868,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5f36666d72617061,0x706d6f4332315a5f,0x6c65626f53657475,0x6868686868686868\n"
".quad 0x7261702e202c6668,0x203233752e206d61,0x6170616475635f5f,0x315a5f5f37666d72\n"
".quad 0x657475706d6f4332,0x6868686c65626f53,0x2c66686868686868,0x206d617261702e20\n"
".quad 0x635f5f203233752e,0x666d726170616475,0x6f4332315a5f5f38,0x626f53657475706d\n"
".quad 0x6868686868686c65,0x702e202c66686868,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f39666d726170,0x75706d6f4332315a,0x686c65626f536574,0x6868686868686868\n"
".quad 0x617261702e202c66,0x5f203233662e206d,0x726170616475635f,0x315a5f5f3031666d\n"
".quad 0x657475706d6f4332,0x6868686c65626f53,0x2966686868686868,0x65722e090a7b090a\n"
".quad 0x25203233752e2067,0x090a3b3e35343c72,0x33662e206765722e,0x3b3e363c66252032\n"
".quad 0x2e206765722e090a,0x3c70252064657270,0x6f6c2e090a3b3e34,0x0939350937310963\n"
".quad 0x656257444c240a30,0x32315a5f5f6e6967,0x53657475706d6f43,0x686868686c65626f\n"
".quad 0x0a3a666868686868,0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3172\n"
".quad 0x666d726170616475,0x6f4332315a5f5f31,0x626f53657475706d,0x6868686868686c65\n"
".quad 0x090a3b5d66686868,0x752e38752e747663,0x2c32722509203233,0x6c090a3b31722520\n"
".quad 0x2e6d617261702e64,0x3372250920323375,0x6475635f5f5b202c,0x5f32666d72617061\n"
".quad 0x706d6f4332315a5f,0x6c65626f53657475,0x6868686868686868,0x7663090a3b5d6668\n"
".quad 0x3233752e38752e74,0x25202c3472250920,0x2e646c090a3b3372,0x33752e6d61726170\n"
".quad 0x202c357225092032,0x70616475635f5f5b,0x5a5f5f33666d7261,0x7475706d6f433231\n"
".quad 0x68686c65626f5365,0x6668686868686868,0x2e747663090a3b5d,0x09203233752e3875\n"
".quad 0x357225202c367225,0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c37722509\n"
".quad 0x726170616475635f,0x32315a5f5f34666d,0x53657475706d6f43,0x686868686c65626f\n"
".quad 0x3b5d666868686868,0x38752e747663090a,0x722509203233752e,0x0a3b377225202c38\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3972,0x666d726170616475\n"
".quad 0x6f4332315a5f5f36,0x626f53657475706d,0x6868686868686c65,0x090a3b5d66686868\n"
".quad 0x752e38752e747663,0x3031722509203233,0x090a3b397225202c,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x635f5f5b202c3131,0x666d726170616475,0x6f4332315a5f5f37\n"
".quad 0x626f53657475706d,0x6868686868686c65,0x090a3b5d66686868,0x752e38752e747663\n"
".quad 0x3231722509203233,0x0a3b31317225202c,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5f5b202c333172,0x6d72617061647563,0x4332315a5f5f3866,0x6f53657475706d6f\n"
".quad 0x68686868686c6562,0x0a3b5d6668686868,0x2e38752e74766309,0x3172250920323375\n"
".quad 0x3b33317225202c34,0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c35317225\n"
".quad 0x726170616475635f,0x32315a5f5f39666d,0x53657475706d6f43,0x686868686c65626f\n"
".quad 0x3b5d666868686868,0x38752e747663090a,0x722509203233752e,0x35317225202c3631\n"
".quad 0x61702e646c090a3b,0x203233662e6d6172,0x5f5b202c31662509,0x726170616475635f\n"
".quad 0x315a5f5f3031666d,0x657475706d6f4332,0x6868686c65626f53,0x5d66686868686868\n"
".quad 0x662e766f6d090a3b,0x2c32662509203233,0x2e090a3b31662520,0x3609373109636f6c\n"
".quad 0x6c756d090a300932,0x203233732e6f6c2e,0x25202c3731722509,0x090a3b32202c3472\n"
".quad 0x203233752e646461,0x25202c3831722509,0x37317225202c3272,0x752e646461090a3b\n"
".quad 0x3931722509203233,0x25202c367225202c,0x7573090a3b383172,0x2509203233752e62\n"
".quad 0x317225202c303272,0x3b32317225202c39,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x34317225202c3132,0x7573090a3b32202c,0x2509203233732e62,0x327225202c323272\n"
".quad 0x3b31327225202c30,0x33752e627573090a,0x2c33327225092032,0x25202c3232722520\n"
".quad 0x7663090a3b363172,0x33732e3631732e74,0x2c34327225092032,0x090a3b3332722520\n"
".quad 0x203233732e736261,0x25202c3532722509,0x756d090a3b343272,0x3233732e6f6c2e6c\n"
".quad 0x202c363272250920,0x3b32202c30317225,0x33752e646461090a,0x2c37327225092032\n"
".quad 0x7225202c36722520,0x646461090a3b3632,0x722509203233752e,0x36317225202c3832\n"
".quad 0x0a3b37327225202c,0x3233752e62757309,0x202c393272250920,0x7225202c38327225\n"
".quad 0x2e6c756d090a3b32,0x09203233732e6f6c,0x7225202c30337225,0x73090a3b32202c38\n"
".quad 0x09203233732e6275,0x7225202c31337225,0x30337225202c3932,0x752e627573090a3b\n"
".quad 0x3233722509203233,0x202c31337225202c,0x63090a3b32317225,0x732e3631732e7476\n"
".quad 0x3333722509203233,0x0a3b32337225202c,0x3233732e73626109,0x202c343372250920\n"
".quad 0x61090a3b33337225,0x09203233732e6464,0x7225202c35337225,0x34337225202c3532\n"
".quad 0x722e747663090a3b,0x33732e3233662e6e,0x202c336625092032,0x6d090a3b35337225\n"
".quad 0x09203233662e6c75,0x336625202c346625,0x090a3b326625202c,0x2e697a722e747663\n"
".quad 0x203233662e323373,0x25202c3633722509,0x747663090a3b3466,0x3233732e3631732e\n"
".quad 0x202c373372250920,0x6d090a3b36337225,0x09203233752e766f,0x3b30202c38337225\n"
".quad 0x6c2e70746573090a,0x2509203233732e74,0x37337225202c3170,0x0a3b38337225202c\n"
".quad 0x7262203170254009,0x305f744c24092061,0x090a3b303530325f,0x09373109636f6c2e\n"
".quad 0x7663090a30093336,0x3233752e38752e74,0x202c393372250920,0x6d090a3b37337225\n"
".quad 0x09203233732e766f,0x3532202c30347225,0x2e766f6d090a3b35,0x3472250920323373\n"
".quad 0x0a3b353532202c31,0x656c2e7074657309,0x702509203233732e,0x2c37337225202c32\n"
".quad 0x090a3b3134722520,0x3233732e706c6573,0x202c323472250920,0x7225202c39337225\n"
".quad 0x3b327025202c3034,0x6e752e617262090a,0x305f744c24092069,0x240a3b343937315f\n"
".quad 0x3530325f305f744c,0x2e766f6d090a3a30,0x3472250920323373,0x4c240a3b30202c32\n"
".quad 0x343937315f305f74,0x732e766f6d090a3a,0x3334722509203233,0x0a3b32347225202c\n"
".quad 0x617261702e747309,0x5b09203233752e6d,0x6572616475635f5f,0x4332315a5f5f6674\n"
".quad 0x6f53657475706d6f,0x68686868686c6562,0x202c5d6668686868,0x72090a3b33347225\n"
".quad 0x57444c240a3b7465,0x32315a5f5f646e65,0x53657475706d6f43,0x686868686c65626f\n"
".quad 0x0a3a666868686868,0x5a5f202f2f207d09,0x7475706d6f433231,0x68686c65626f5365\n"
".quad 0x6668686868686868,0x697369762e090a0a,0x6e75662e20656c62,0x617261702e282063\n"
".quad 0x5f203233752e206d,0x746572616475635f,0x6f4330315a5f5f66,0x786f42657475706d\n"
".quad 0x6868686868686868,0x30315a5f20296668,0x42657475706d6f43,0x686868686868786f\n"
".quad 0x702e282066686868,0x33752e206d617261,0x616475635f5f2032,0x5f5f31666d726170\n"
".quad 0x75706d6f4330315a,0x686868786f426574,0x2c66686868686868,0x206d617261702e20\n"
".quad 0x635f5f203233752e,0x666d726170616475,0x6f4330315a5f5f32,0x786f42657475706d\n"
".quad 0x6868686868686868,0x7261702e202c6668,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x315a5f5f33666d72,0x657475706d6f4330,0x6868686868786f42,0x2e202c6668686868\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5f34666d72617061,0x706d6f4330315a5f\n"
".quad 0x6868786f42657475,0x6668686868686868,0x6d617261702e202c,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x4330315a5f5f3566,0x6f42657475706d6f,0x6868686868686878\n"
".quad 0x61702e202c666868,0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f36666d7261\n"
".quad 0x7475706d6f433031,0x68686868786f4265,0x202c666868686868,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x37666d7261706164,0x6d6f4330315a5f5f,0x68786f4265747570\n"
".quad 0x6868686868686868,0x617261702e202c66,0x5f203233752e206d,0x726170616475635f\n"
".quad 0x30315a5f5f38666d,0x42657475706d6f43,0x686868686868786f,0x702e202c66686868\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x5f5f39666d726170,0x75706d6f4330315a\n"
".quad 0x686868786f426574,0x2c66686868686868,0x206d617261702e20,0x635f5f203233662e\n"
".quad 0x666d726170616475,0x4330315a5f5f3031,0x6f42657475706d6f,0x6868686868686878\n"
".quad 0x0a7b090a29666868,0x752e206765722e09,0x34343c7225203233,0x6765722e090a3b3e\n"
".quad 0x6625203233662e20,0x722e090a3b3e363c,0x646572702e206765,0x0a3b3e353c702520\n"
".quad 0x373109636f6c2e09,0x4c240a3009363809,0x5f6e696765625744,0x706d6f4330315a5f\n"
".quad 0x6868786f42657475,0x6668686868686868,0x61702e646c090a3a,0x203233752e6d6172\n"
".quad 0x5f5b202c31722509,0x726170616475635f,0x30315a5f5f31666d,0x42657475706d6f43\n"
".quad 0x686868686868786f,0x090a3b5d66686868,0x752e38752e747663,0x2c32722509203233\n"
".quad 0x6c090a3b31722520,0x2e6d617261702e64,0x3372250920323375,0x6475635f5f5b202c\n"
".quad 0x5f32666d72617061,0x706d6f4330315a5f,0x6868786f42657475,0x6668686868686868\n"
".quad 0x2e747663090a3b5d,0x09203233752e3875,0x337225202c347225,0x61702e646c090a3b\n"
".quad 0x203233752e6d6172,0x5f5b202c35722509,0x726170616475635f,0x30315a5f5f33666d\n"
".quad 0x42657475706d6f43,0x686868686868786f,0x090a3b5d66686868,0x752e38752e747663\n"
".quad 0x2c36722509203233,0x6c090a3b35722520,0x2e6d617261702e64,0x3772250920323375\n"
".quad 0x6475635f5f5b202c,0x5f34666d72617061,0x706d6f4330315a5f,0x6868786f42657475\n"
".quad 0x6668686868686868,0x2e747663090a3b5d,0x09203233752e3875,0x377225202c387225\n"
".quad 0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c39722509,0x726170616475635f\n"
".quad 0x30315a5f5f35666d,0x42657475706d6f43,0x686868686868786f,0x090a3b5d66686868\n"
".quad 0x752e38752e747663,0x3031722509203233,0x090a3b397225202c,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x635f5f5b202c3131,0x666d726170616475,0x6f4330315a5f5f36\n"
".quad 0x786f42657475706d,0x6868686868686868,0x7663090a3b5d6668,0x3233752e38752e74\n"
".quad 0x202c323172250920,0x6c090a3b31317225,0x2e6d617261702e64,0x3172250920323375\n"
".quad 0x75635f5f5b202c33,0x37666d7261706164,0x6d6f4330315a5f5f,0x68786f4265747570\n"
".quad 0x6868686868686868,0x747663090a3b5d66,0x203233752e38752e,0x25202c3431722509\n"
".quad 0x646c090a3b333172,0x752e6d617261702e,0x3531722509203233,0x6475635f5f5b202c\n"
".quad 0x5f38666d72617061,0x706d6f4330315a5f,0x6868786f42657475,0x6668686868686868\n"
".quad 0x2e747663090a3b5d,0x09203233752e3875,0x7225202c36317225,0x2e646c090a3b3531\n"
".quad 0x33752e6d61726170,0x2c37317225092032,0x616475635f5f5b20,0x5f5f39666d726170\n"
".quad 0x75706d6f4330315a,0x686868786f426574,0x5d66686868686868,0x752e747663090a3b\n"
".quad 0x2509203233752e38,0x317225202c383172,0x702e646c090a3b37,0x3233662e6d617261\n"
".quad 0x5b202c3166250920,0x6170616475635f5f,0x5a5f5f3031666d72,0x7475706d6f433031\n"
".quad 0x68686868786f4265,0x3b5d666868686868,0x33662e766f6d090a,0x202c326625092032\n"
".quad 0x6c2e090a3b316625,0x393809373109636f,0x2e646461090a3009,0x3172250920323375\n"
".quad 0x2c36317225202c39,0x090a3b3831722520,0x203233752e646461,0x25202c3032722509\n"
".quad 0x317225202c323172,0x2e646461090a3b34,0x3272250920323375,0x202c327225202c31\n"
".quad 0x6461090a3b347225,0x2509203233752e64,0x367225202c323272,0x0a3b31327225202c\n"
".quad 0x3233752e64646109,0x202c333272250920,0x317225202c387225,0x2e646461090a3b30\n"
".quad 0x3272250920323375,0x2c32327225202c34,0x090a3b3332722520,0x203233752e646461\n"
".quad 0x25202c3532722509,0x327225202c303272,0x2e646461090a3b34,0x3272250920323375\n"
".quad 0x2c39317225202c36,0x090a3b3532722520,0x2e3631732e747663,0x3272250920323373\n"
".quad 0x3b36327225202c37,0x33732e766f6d090a,0x2c38327225092032,0x3137333434353920\n"
".quad 0x766f6d090a3b3737,0x722509203233732e,0x090a3b30202c3932,0x2e746c2e70746573\n"
".quad 0x3170250920323373,0x202c37327225202c,0x61090a3b39327225,0x09203233732e7362\n"
".quad 0x7225202c30337225,0x6c756d090a3b3732,0x203233752e69682e,0x25202c3133722509\n"
".quad 0x327225202c303372,0x2e726873090a3b38,0x3372250920323373,0x2c31337225202c32\n"
".quad 0x702540090a3b3120,0x33732e6275732031,0x2c32337225092032,0x25202c3932722520\n"
".quad 0x6f6d090a3b323372,0x2509203233732e76,0x337225202c333372,0x2e747663090a3b32\n"
".quad 0x203233732e363173,0x25202c3433722509,0x7663090a3b333372,0x3233662e6e722e74\n"
".quad 0x662509203233732e,0x3b34337225202c33,0x33662e6c756d090a,0x202c346625092032\n"
".quad 0x326625202c336625,0x722e747663090a3b,0x662e3233732e697a,0x3533722509203233\n"
".quad 0x090a3b346625202c,0x2e3631732e747663,0x3372250920323373,0x3b35337225202c36\n"
".quad 0x33752e766f6d090a,0x2c37337225092032,0x746573090a3b3020,0x3233732e746c2e70\n"
".quad 0x25202c3270250920,0x337225202c363372,0x32702540090a3b37,0x4c24092061726220\n"
".quad 0x303530325f315f74,0x09636f6c2e090a3b,0x0a30093039093731,0x2e38752e74766309\n"
".quad 0x3372250920323375,0x3b36337225202c38,0x33732e766f6d090a,0x2c39337225092032\n"
".quad 0x6d090a3b35353220,0x09203233732e766f,0x3532202c30347225,0x70746573090a3b35\n"
".quad 0x203233732e656c2e,0x7225202c33702509,0x30347225202c3633,0x2e706c6573090a3b\n"
".quad 0x3472250920323373,0x2c38337225202c31,0x25202c3933722520,0x617262090a3b3370\n"
".quad 0x4c240920696e752e,0x343937315f315f74,0x5f315f744c240a3b,0x6d090a3a30353032\n"
".quad 0x09203233732e766f,0x3b30202c31347225,0x315f315f744c240a,0x6f6d090a3a343937\n"
".quad 0x2509203233732e76,0x347225202c323472,0x702e7473090a3b31,0x3233752e6d617261\n"
".quad 0x6475635f5f5b0920,0x5a5f5f6674657261,0x7475706d6f433031,0x68686868786f4265\n"
".quad 0x2c5d666868686868,0x090a3b3234722520,0x444c240a3b746572,0x315a5f5f646e6557\n"
".quad 0x657475706d6f4330,0x6868686868786f42,0x090a3a6668686868,0x315a5f202f2f207d\n"
".quad 0x657475706d6f4330,0x6868686868786f42,0x090a0a6668686868,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x75635f5f20323375,0x5f5f667465726164\n"
".quad 0x687365726854395a,0x5f20296668646c6f,0x687365726854395a,0x2e28206668646c6f\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5f31666d72617061,0x7365726854395a5f\n"
".quad 0x202c6668646c6f68,0x2e206d617261702e,0x75635f5f20323366,0x32666d7261706164\n"
".quad 0x65726854395a5f5f,0x296668646c6f6873,0x65722e090a7b090a,0x25203233752e2067\n"
".quad 0x2e090a3b3e363c72,0x3233662e20676572,0x0a3b3e353c662520,0x702e206765722e09\n"
".quad 0x333c702520646572,0x636f6c2e090a3b3e,0x3009343909373109,0x67656257444c240a\n"
".quad 0x6854395a5f5f6e69,0x68646c6f68736572,0x702e646c090a3a66,0x3233752e6d617261\n"
".quad 0x5b202c3172250920,0x6170616475635f5f,0x395a5f5f31666d72,0x6c6f687365726854\n"
".quad 0x63090a3b5d666864,0x33752e38752e7476,0x202c327225092032,0x646c090a3b317225\n"
".quad 0x662e6d617261702e,0x2c31662509203233,0x616475635f5f5b20,0x5f5f32666d726170\n"
".quad 0x687365726854395a,0x0a3b5d6668646c6f,0x3233662e766f6d09,0x25202c3266250920\n"
".quad 0x6f6c2e090a3b3166,0x0935390937310963,0x722e747663090a30,0x33752e3233662e6e\n"
".quad 0x202c336625092032,0x6573090a3b327225,0x33662e74672e7074,0x202c317025092032\n"
".quad 0x326625202c336625,0x3170252140090a3b,0x4c24092061726220,0x3b3037375f325f74\n"
".quad 0x33732e766f6d090a,0x202c337225092032,0x7262090a3b353532,0x240920696e752e61\n"
".quad 0x395a5f5f3442424c,0x6c6f687365726854,0x744c240a3b666864,0x0a3a3037375f325f\n"
".quad 0x373109636f6c2e09,0x6d090a3009363909,0x09203233732e766f,0x0a3b30202c337225\n"
".quad 0x5a5f5f3442424c24,0x6f68736572685439,0x6d090a3a6668646c,0x09203233732e766f\n"
".quad 0x337225202c347225,0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09\n"
".quad 0x395a5f5f66746572,0x6c6f687365726854,0x7225202c5d666864,0x3b746572090a3b34\n"
".quad 0x646e6557444c240a,0x65726854395a5f5f,0x3a6668646c6f6873,0x5f202f2f207d090a\n"
".quad 0x687365726854395a,0x2e090a6668646c6f,0x2e096e7265747865,0x2e20646572616873\n"
".quad 0x2031206e67696c61,0x61636f4c2038622e,0x5d5b6b636f6c426c,0x626f6c672e090a3b\n"
".quad 0x727865742e206c61,0x0a3b786574206665,0x6c61626f6c672e09,0x6c62203436752e20\n"
".quad 0x74636e75466b636f,0x672e090a3b6e6f69,0x612e206c61626f6c,0x2e2038206e67696c\n"
".quad 0x6b636f6c62203862,0x6e6f6974636e7546,0x315b656c6261745f,0x652e090a0a3b5d36\n"
".quad 0x315a5f207972746e,0x68536c65626f5331,0x6375365064657261,0x7373737434726168\n"
".quad 0x6668684650696673,0x702e09090a282045,0x36752e206d617261,0x616475635f5f2034\n"
".quad 0x315a5f5f6d726170,0x68536c65626f5331,0x6375365064657261,0x7373737434726168\n"
".quad 0x6668684650696673,0x6c65626f53705f45,0x6c616e696769724f,0x7261702e09090a2c\n"
".quad 0x203631752e206d61,0x6170616475635f5f,0x5331315a5f5f6d72,0x726168536c65626f\n"
".quad 0x6168637536506465,0x6673737373743472,0x5f45666868465069,0x7469506c65626f53\n"
".quad 0x702e09090a2c6863,0x31732e206d617261,0x616475635f5f2036,0x315a5f5f6d726170\n"
".quad 0x68536c65626f5331,0x6375365064657261,0x7373737434726168,0x6668684650696673\n"
".quad 0x576b636f6c425f45,0x09090a2c68746469,0x2e206d617261702e,0x75635f5f20363173\n"
".quad 0x5f5f6d7261706164,0x6c65626f5331315a,0x3650646572616853,0x7374347261686375\n"
".quad 0x6846506966737373,0x726168535f456668,0x2c68637469506465,0x617261702e09090a\n"
".quad 0x5f203631732e206d,0x726170616475635f,0x6f5331315a5f5f6d,0x65726168536c6562\n"
".quad 0x7261686375365064,0x6966737373737434,0x775f456668684650,0x7261702e09090a2c\n"
".quad 0x203631732e206d61,0x6170616475635f5f,0x5331315a5f5f6d72,0x726168536c65626f\n"
".quad 0x6168637536506465,0x6673737373743472,0x5f45666868465069,0x61702e09090a2c68\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x31315a5f5f6d7261,0x6168536c65626f53\n"
".quad 0x6863753650646572,0x7373737374347261,0x4566686846506966,0x2c656c616353665f\n"
".quad 0x617261702e09090a,0x5f203233732e206d,0x726170616475635f,0x6f5331315a5f5f6d\n"
".quad 0x65726168536c6562,0x7261686375365064,0x6966737373737434,0x625f456668684650\n"
".quad 0x7265704f6b636f6c,0x090a2c6e6f697461,0x206d617261702e09,0x635f5f203436752e\n"
".quad 0x5f6d726170616475,0x65626f5331315a5f,0x506465726168536c,0x7434726168637536\n"
".quad 0x4650696673737373,0x6f50705f45666868,0x74636e7546746e69,0x0a7b090a296e6f69\n"
".quad 0x752e206765722e09,0x38313c7225203233,0x65722e090a3b3e33,0x25203436752e2067\n"
".quad 0x0a3b3e39323c6472,0x662e206765722e09,0x39363c6625203233,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x090a3b3e31313c70,0x2e206d617261702e,0x75635f5f20323375\n"
".quad 0x31616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x3b665f69555f6955,0x6d617261702e090a,0x5f5f203233752e20\n"
".quad 0x6d72617061647563,0x746f7270665f3261,0x5f69555f69555f6f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x7261702e090a3b66,0x203233752e206d61\n"
".quad 0x6170616475635f5f,0x7270665f33616d72,0x555f69555f6f746f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x702e090a3b665f69,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x665f34616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x090a3b665f69555f,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x35616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x3b665f69555f6955,0x6d617261702e090a\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x746f7270665f3661,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x7261702e090a3b66\n"
".quad 0x203233752e206d61,0x6170616475635f5f,0x7270665f37616d72,0x555f69555f6f746f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x702e090a3b665f69\n"
".quad 0x33752e206d617261,0x616475635f5f2032,0x665f38616d726170,0x69555f6f746f7270\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x090a3b665f69555f\n"
".quad 0x2e206d617261702e,0x75635f5f20323375,0x39616d7261706164,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x3b665f69555f6955\n"
".quad 0x6d617261702e090a,0x5f5f203233662e20,0x6d72617061647563,0x6f7270665f303161\n"
".quad 0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x61702e090a3b665f,0x3233752e206d6172,0x72616475635f5f20,0x6f7270665f617465\n"
".quad 0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x61702e090a3b665f,0x3233752e206d6172,0x70616475635f5f20,0x70665f31616d7261\n"
".quad 0x5f69555f6f746f72,0x2e090a3b665f6955,0x662e206d61726170,0x6475635f5f203233\n"
".quad 0x5f32616d72617061,0x555f6f746f727066,0x0a3b665f69555f69,0x206d617261702e09\n"
".quad 0x635f5f203233752e,0x5f61746572616475,0x555f6f746f727066,0x0a3b665f69555f69\n"
".quad 0x373109636f6c2e09,0x240a300935333109,0x6e6967656257444c,0x626f5331315a5f5f\n"
".quad 0x6465726168536c65,0x3472616863753650,0x5069667373737374,0x090a3a4566686846\n"
".quad 0x09373109636f6c2e,0x6d090a3009343431,0x09203233752e766f,0x697425202c317225\n"
".quad 0x7663090a3b782e64,0x33732e3631732e74,0x202c327225092032,0x6f6d090a3b317225\n"
".quad 0x2509203233732e76,0x3b327225202c3372,0x7261702e646c090a,0x09203631732e6d61\n"
".quad 0x5f5f5b202c347225,0x6d72617061647563,0x626f5331315a5f5f,0x6465726168536c65\n"
".quad 0x3472616863753650,0x5069667373737374,0x6c425f4566686846,0x68746469576b636f\n"
".quad 0x2e646461090a3b5d,0x3572250920323373,0x32202c347225202c,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x357225202c317025,0x090a3b327225202c,0x203233752e766f6d\n"
".quad 0x7425202c36722509,0x40090a3b792e6469,0x6172622031702521,0x5f335f744c240920\n"
".quad 0x6d090a3b30393835,0x09203233752e766f,0x746325202c377225,0x090a3b792e646961\n"
".quad 0x203233752e766f6d,0x6e25202c38722509,0x090a3b792e646974,0x752e6f6c2e6c756d\n"
".quad 0x2c39722509203233,0x7225202c37722520,0x2e766f6d090a3b38,0x3172250920323375\n"
".quad 0x6961746325202c30,0x756d090a3b782e64,0x3233752e6f6c2e6c,0x202c313172250920\n"
".quad 0x317225202c347225,0x702e646c090a3b30,0x3631732e6d617261,0x202c323172250920\n"
".quad 0x70616475635f5f5b,0x31315a5f5f6d7261,0x6168536c65626f53,0x6863753650646572\n"
".quad 0x7373737374347261,0x4566686846506966,0x506465726168535f,0x090a3b5d68637469\n"
".quad 0x752e6f6c2e6c756d,0x3331722509203233,0x202c32317225202c,0x6461090a3b367225\n"
".quad 0x2509203233752e64,0x397225202c343172,0x090a3b367225202c,0x752e6f6c2e6c756d\n"
".quad 0x3531722509203233,0x202c31317225202c,0x2e766f6d090a3b34,0x3172250920323373\n"
".quad 0x3b34317225202c36,0x31732e747663090a,0x2509203233732e36,0x317225202c373172\n"
".quad 0x2e747663090a3b35,0x203233732e363173,0x25202c3831722509,0x7573090a3b363172\n"
".quad 0x2509203233732e62,0x317225202c393172,0x63090a3b31202c38,0x33662e6e722e7476\n"
".quad 0x2509203233732e32,0x39317225202c3166,0x752e766f6d090a3b,0x3032722509203233\n"
".quad 0x2e6469746e25202c,0x61747663090a3b78,0x2e6465726168732e,0x6472250920343675\n"
".quad 0x6c61636f4c202c31,0x240a3b6b636f6c42,0x3034365f335f744c,0x6c3c2f2f200a3a32\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x0a34343120656e69,0x2e6f6c2e6c756d09\n"
".quad 0x3272250920323373,0x202c337225202c31,0x2e646461090a3b34,0x3272250920323373\n"
".quad 0x2c31327225202c32,0x090a3b3731722520,0x203233732e627573,0x25202c3332722509\n"
".quad 0x0a3b31202c323272,0x2e6e722e74766309,0x203233732e323366,0x7225202c32662509\n"
".quad 0x766f6d090a3b3332,0x662509203233662e,0x0a3b326625202c33,0x3233662e766f6d09\n"
".quad 0x25202c3466250920,0x766f6d090a3b3166,0x662509203233662e,0x3030306630202c35\n"
".quad 0x20203b3030303030,0x30202f2f09202020,0x33662e766f6d090a,0x202c366625092032\n"
".quad 0x6f6d090a3b356625,0x2509203233662e76,0x30306630202c3766,0x203b303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x2c38662509203233,0x74090a3b37662520\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c343272257b20,0x363272252c353272\n"
".quad 0x5b2c7d373272252c,0x3366257b2c786574,0x3666252c3466252c,0x0a3b5d7d3866252c\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c34343120,0x6c6562616c206461,0x335f744c24206465,0x2e090a323034365f\n"
".quad 0x3109373109636f6c,0x6f6d090a30093534,0x2509203233732e76,0x327225202c383272\n"
".quad 0x2e646461090a3b34,0x3272250920323373,0x2c31327225202c39,0x090a3b3331722520\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x3b39327225202c32,0x36752e646461090a\n"
".quad 0x2c33647225092034,0x25202c3264722520,0x7473090a3b316472,0x72255b092038752e\n"
".quad 0x25202c5d302b3364,0x7663090a3b383272,0x3233662e6e722e74,0x662509203233732e\n"
".quad 0x3b32327225202c39,0x33662e766f6d090a,0x2c30316625092032,0x6d090a3b39662520\n"
".quad 0x09203233662e766f,0x6625202c31316625,0x2e766f6d090a3b31,0x3166250920323366\n"
".quad 0x3030306630202c32,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c333166250920,0x6d090a3b32316625,0x09203233662e766f,0x6630202c34316625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366\n"
".quad 0x3b34316625202c35,0x64322e786574090a,0x2e3233752e34762e,0x3372257b20323366\n"
".quad 0x252c313372252c30,0x333372252c323372,0x7b2c7865745b2c7d,0x3166252c30316625\n"
".quad 0x252c333166252c31,0x200a3b5d7d353166,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c343431,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x6c2e090a32303436,0x343109373109636f,0x766f6d090a300937\n"
".quad 0x722509203233732e,0x30337225202c3433,0x38752e7473090a3b,0x2b336472255b0920\n"
".quad 0x34337225202c5d31,0x732e646461090a3b,0x3533722509203233,0x202c32327225202c\n"
".quad 0x2e747663090a3b31,0x732e3233662e6e72,0x3631662509203233,0x0a3b35337225202c\n"
".quad 0x3233662e766f6d09,0x202c373166250920,0x6d090a3b36316625,0x09203233662e766f\n"
".quad 0x6625202c38316625,0x2e766f6d090a3b31,0x3166250920323366,0x3030306630202c39\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c303266250920\n"
".quad 0x6d090a3b39316625,0x09203233662e766f,0x6630202c31326625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3266250920323366,0x3b31326625202c32\n"
".quad 0x64322e786574090a,0x2e3233752e34762e,0x3372257b20323366,0x252c373372252c36\n"
".quad 0x393372252c383372,0x7b2c7865745b2c7d,0x3166252c37316625,0x252c303266252c38\n"
".quad 0x200a3b5d7d323266,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c343431,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x6c2e090a32303436,0x343109373109636f,0x766f6d090a300939,0x722509203233732e\n"
".quad 0x36337225202c3034,0x38752e7473090a3b,0x2b336472255b0920,0x30347225202c5d32\n"
".quad 0x732e646461090a3b,0x3134722509203233,0x202c32327225202c,0x2e747663090a3b32\n"
".quad 0x732e3233662e6e72,0x3332662509203233,0x0a3b31347225202c,0x3233662e766f6d09\n"
".quad 0x202c343266250920,0x6d090a3b33326625,0x09203233662e766f,0x6625202c35326625\n"
".quad 0x2e766f6d090a3b31,0x3266250920323366,0x3030306630202c36,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c373266250920,0x6d090a3b36326625\n"
".quad 0x09203233662e766f,0x6630202c38326625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3266250920323366,0x3b38326625202c39,0x64322e786574090a\n"
".quad 0x2e3233752e34762e,0x3472257b20323366,0x252c333472252c32,0x353472252c343472\n"
".quad 0x7b2c7865745b2c7d,0x3266252c34326625,0x252c373266252c35,0x200a3b5d7d393266\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c343431,0x656c6562616c2064,0x5f335f744c242064,0x6c2e090a32303436\n"
".quad 0x353109373109636f,0x766f6d090a300931,0x722509203233732e,0x32347225202c3634\n"
".quad 0x38752e7473090a3b,0x2b336472255b0920,0x36347225202c5d33,0x09636f6c2e090a3b\n"
".quad 0x3009343431093731,0x33752e646461090a,0x2c37347225092032,0x7225202c33722520\n"
".quad 0x747663090a3b3032,0x3233732e3631732e,0x25202c3372250920,0x6573090a3b373472\n"
".quad 0x33732e746c2e7074,0x202c327025092032,0x357225202c337225,0x2032702540090a3b\n"
".quad 0x744c240920617262,0x3b323034365f335f,0x355f335f744c240a,0x7663090a3a303938\n"
".quad 0x65726168732e6174,0x2509203436752e64,0x636f4c202c316472,0x3b6b636f6c426c61\n"
".quad 0x33752e766f6d090a,0x2c38347225092032,0x746573090a3b3120,0x3233752e74672e70\n"
".quad 0x25202c3370250920,0x38347225202c3672,0x2033702540090a3b,0x744c240920617262\n"
".quad 0x3b343139365f335f,0x3109636f6c2e090a,0x0a30093935310937,0x3233732e766f6d09\n"
".quad 0x25202c3372250920,0x252140090a3b3272,0x0920617262203170,0x34375f335f744c24\n"
".quad 0x766f6d090a3b3632,0x722509203233752e,0x69746e25202c3934,0x6f6d090a3b792e64\n"
".quad 0x2509203233752e76,0x746325202c303572,0x090a3b792e646961,0x752e6f6c2e6c756d\n"
".quad 0x2c39722509203233,0x25202c3035722520,0x6f6d090a3b393472,0x2509203233752e76\n"
".quad 0x746325202c313572,0x090a3b782e646961,0x752e6f6c2e6c756d,0x3131722509203233\n"
".quad 0x25202c347225202c,0x6461090a3b313572,0x2509203233752e64,0x347225202c323572\n"
".quad 0x0a3b367225202c39,0x3233752e64646109,0x202c343172250920,0x367225202c397225\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x317225202c353172,0x6c090a3b34202c31\n"
".quad 0x2e6d617261702e64,0x3572250920363173,0x75635f5f5b202c33,0x5f5f6d7261706164\n"
".quad 0x6c65626f5331315a,0x3650646572616853,0x7374347261686375,0x6846506966737373\n"
".quad 0x726168535f456668,0x5d68637469506465,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x357225202c343572,0x3b32357225202c33,0x33732e766f6d090a,0x2c36317225092032\n"
".quad 0x090a3b3431722520,0x2e3631732e747663,0x3172250920323373,0x3b35317225202c37\n"
".quad 0x31732e747663090a,0x2509203233732e36,0x317225202c383172,0x2e646461090a3b36\n"
".quad 0x3572250920323375,0x2c38317225202c35,0x090a3b3934722520,0x203233752e627573\n"
".quad 0x25202c3635722509,0x0a3b31202c353572,0x2e6e722e74766309,0x203233752e323366\n"
".quad 0x25202c3033662509,0x6f6d090a3b363572,0x2509203233752e76,0x746e25202c303272\n"
".quad 0x4c240a3b782e6469,0x383339375f335f74,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x090a39353120656e,0x732e6f6c2e6c756d,0x3132722509203233\n"
".quad 0x34202c337225202c,0x732e646461090a3b,0x3232722509203233,0x202c31327225202c\n"
".quad 0x73090a3b37317225,0x09203233732e6275,0x7225202c37357225,0x090a3b31202c3232\n"
".quad 0x662e6e722e747663,0x09203233732e3233,0x7225202c31336625,0x766f6d090a3b3735\n"
".quad 0x662509203233662e,0x31336625202c3233,0x662e766f6d090a3b,0x3333662509203233\n"
".quad 0x0a3b30336625202c,0x3233662e766f6d09,0x202c343366250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x336625202c353366\n"
".quad 0x2e766f6d090a3b34,0x3366250920323366,0x3030306630202c36,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c373366250920,0x74090a3b36336625\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c383572257b20,0x303672252c393572\n"
".quad 0x5b2c7d313672252c,0x3366257b2c786574,0x252c333366252c32,0x373366252c353366\n"
".quad 0x3c2f2f200a3b5d7d,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39353120656e696c,0x6c2064616568202c,0x242064656c656261,0x3339375f335f744c\n"
".quad 0x09636f6c2e090a38,0x3009303631093731,0x33732e766f6d090a,0x2c32367225092032\n"
".quad 0x090a3b3835722520,0x203233732e646461,0x25202c3336722509,0x357225202c313272\n"
".quad 0x2e747663090a3b34,0x203233732e343673,0x25202c3464722509,0x6461090a3b333672\n"
".quad 0x2509203436752e64,0x647225202c356472,0x3b31647225202c34,0x2038752e7473090a\n"
".quad 0x302b356472255b09,0x3b32367225202c5d,0x6e722e747663090a,0x3233732e3233662e\n"
".quad 0x202c383366250920,0x6d090a3b32327225,0x09203233662e766f,0x6625202c39336625\n"
".quad 0x766f6d090a3b3833,0x662509203233662e,0x30336625202c3034,0x662e766f6d090a3b\n"
".quad 0x3134662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x25202c3234662509,0x6f6d090a3b313466,0x2509203233662e76\n"
".quad 0x306630202c333466,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3434662509203233,0x0a3b33346625202c,0x2e64322e78657409,0x662e3233752e3476\n"
".quad 0x343672257b203233,0x72252c353672252c,0x7d373672252c3636,0x257b2c7865745b2c\n"
".quad 0x303466252c393366,0x66252c323466252c,0x2f200a3b5d7d3434,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3935\n"
".quad 0x64656c6562616c20,0x375f335f744c2420,0x6f6c2e090a383339,0x3236310937310963\n"
".quad 0x2e766f6d090a3009,0x3672250920323373,0x3b34367225202c38,0x2038752e7473090a\n"
".quad 0x312b356472255b09,0x3b38367225202c5d,0x33732e646461090a,0x2c39367225092032\n"
".quad 0x31202c3232722520,0x722e747663090a3b,0x33732e3233662e6e,0x2c35346625092032\n"
".quad 0x090a3b3936722520,0x203233662e766f6d,0x25202c3634662509,0x6f6d090a3b353466\n"
".quad 0x2509203233662e76,0x336625202c373466,0x2e766f6d090a3b30,0x3466250920323366\n"
".quad 0x3030306630202c38,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c393466250920,0x6d090a3b38346625,0x09203233662e766f,0x6630202c30356625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3566250920323366\n"
".quad 0x3b30356625202c31,0x64322e786574090a,0x2e3233752e34762e,0x3772257b20323366\n"
".quad 0x252c313772252c30,0x333772252c323772,0x7b2c7865745b2c7d,0x3466252c36346625\n"
".quad 0x252c393466252c37,0x200a3b5d7d313566,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393531,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x6c2e090a38333937,0x363109373109636f,0x766f6d090a300934\n"
".quad 0x722509203233732e,0x30377225202c3437,0x38752e7473090a3b,0x2b356472255b0920\n"
".quad 0x34377225202c5d32,0x732e646461090a3b,0x3537722509203233,0x202c32327225202c\n"
".quad 0x2e747663090a3b32,0x732e3233662e6e72,0x3235662509203233,0x0a3b35377225202c\n"
".quad 0x3233662e766f6d09,0x202c333566250920,0x6d090a3b32356625,0x09203233662e766f\n"
".quad 0x6625202c34356625,0x766f6d090a3b3033,0x662509203233662e,0x30306630202c3535\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c36356625092032\n"
".quad 0x090a3b3535662520,0x203233662e766f6d,0x30202c3735662509,0x3030303030303066\n"
".quad 0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e,0x37356625202c3835\n"
".quad 0x322e786574090a3b,0x3233752e34762e64,0x72257b203233662e,0x2c373772252c3637\n"
".quad 0x3772252c38377225,0x2c7865745b2c7d39,0x66252c333566257b,0x2c363566252c3435\n"
".quad 0x0a3b5d7d38356625,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39353120,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x2e090a383339375f,0x3109373109636f6c,0x6f6d090a30093636,0x2509203233732e76\n"
".quad 0x377225202c303872,0x752e7473090a3b36,0x356472255b092038,0x387225202c5d332b\n"
".quad 0x636f6c2e090a3b30,0x0939353109373109,0x752e646461090a30,0x3138722509203233\n"
".quad 0x25202c337225202c,0x7663090a3b303272,0x33732e3631732e74,0x202c337225092032\n"
".quad 0x73090a3b31387225,0x732e746c2e707465,0x2c34702509203233,0x7225202c33722520\n"
".quad 0x34702540090a3b35,0x4c24092061726220,0x383339375f335f74,0x5f335f744c240a3b\n"
".quad 0x4c240a3a36323437,0x343139365f335f74,0x09636f6c2e090a3a,0x3009313731093731\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x09373109636f6c2e,0x63090a3009373731\n"
".quad 0x626f6c672e617476,0x09203436752e6c61,0x6c62202c36647225,0x74636e75466b636f\n"
".quad 0x6c6261745f6e6f69,0x702e646c090a3b65,0x3233732e6d617261,0x202c323872250920\n"
".quad 0x70616475635f5f5b,0x31315a5f5f6d7261,0x6168536c65626f53,0x6863753650646572\n"
".quad 0x7373737374347261,0x4566686846506966,0x704f6b636f6c625f,0x5d6e6f6974617265\n"
".quad 0x732e747663090a3b,0x09203233732e3436,0x7225202c37647225,0x6c756d090a3b3238\n"
".quad 0x33732e656469772e,0x2c38647225092032,0x38202c3238722520,0x752e646461090a3b\n"
".quad 0x3964722509203436,0x202c36647225202c,0x6c090a3b38647225,0x2509203436752e64\n"
".quad 0x255b202c30316472,0x0a3b5d302b396472,0x626f6c672e747309,0x09203436752e6c61\n"
".quad 0x75466b636f6c625b,0x2c5d6e6f6974636e,0x0a3b303164722520,0x373109636f6c2e09\n"
".quad 0x090a300939373109,0x203233732e766f6d,0x7225202c33722509,0x70746573090a3b32\n"
".quad 0x203233732e65672e,0x7225202c35702509,0x0a3b347225202c32,0x7262203570254009\n"
".quad 0x335f744c24092061,0x090a3b303534385f,0x203233752e766f6d,0x25202c3338722509\n"
".quad 0x3b792e6469617463,0x33752e766f6d090a,0x2c34387225092032,0x792e6469746e2520\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x33387225202c3972,0x0a3b34387225202c\n"
".quad 0x3233752e64646109,0x202c343172250920,0x367225202c397225,0x732e766f6d090a3b\n"
".quad 0x3631722509203233,0x0a3b34317225202c,0x3631732e74766309,0x722509203233732e\n"
".quad 0x36317225202c3831,0x61702e646c090a3b,0x203631752e6d6172,0x5b202c3538722509\n"
".quad 0x6170616475635f5f,0x5331315a5f5f6d72,0x726168536c65626f,0x6168637536506465\n"
".quad 0x6673737373743472,0x5f45666868465069,0x7469506c65626f53,0x756d090a3b5d6863\n"
".quad 0x3233732e6f6c2e6c,0x202c363872250920,0x7225202c38317225,0x747663090a3b3538\n"
".quad 0x3233732e3436752e,0x2c31316472250920,0x090a3b3638722520,0x6d617261702e646c\n"
".quad 0x722509203436752e,0x5f5f5b202c323164,0x6d72617061647563,0x626f5331315a5f5f\n"
".quad 0x6465726168536c65,0x3472616863753650,0x5069667373737374,0x53705f4566686846\n"
".quad 0x6769724f6c65626f,0x090a3b5d6c616e69,0x203436752e646461,0x202c333164722509\n"
".quad 0x25202c3131647225,0x6d090a3b32316472,0x09203233752e766f,0x6325202c37387225\n"
".quad 0x0a3b782e64696174,0x2e6f6c2e6c756d09,0x3172250920323375,0x202c347225202c31\n"
".quad 0x6d090a3b37387225,0x33752e6f6c2e6c75,0x2c35317225092032,0x34202c3131722520\n"
".quad 0x732e747663090a3b,0x09203233732e3631,0x7225202c37317225,0x726873090a3b3531\n"
".quad 0x722509203233732e,0x37317225202c3838,0x7663090a3b32202c,0x33732e3631732e74\n"
".quad 0x2c39387225092032,0x090a3b3838722520,0x6d617261702e646c,0x722509203631732e\n"
".quad 0x635f5f5b202c3039,0x5f6d726170616475,0x65626f5331315a5f,0x506465726168536c\n"
".quad 0x7434726168637536,0x4650696673737373,0x6168535f45666868,0x6863746950646572\n"
".quad 0x2e6c756d090a3b5d,0x09203233752e6f6c,0x7225202c33317225,0x3b367225202c3039\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x5b202c3431647225,0x6170616475635f5f\n"
".quad 0x5331315a5f5f6d72,0x726168536c65626f,0x6168637536506465,0x6673737373743472\n"
".quad 0x5f45666868465069,0x7546746e696f5070,0x3b5d6e6f6974636e,0x36752e766f6d090a\n"
".quad 0x3531647225092034,0x6573090a3b30202c,0x36752e656e2e7074,0x202c367025092034\n"
".quad 0x25202c3431647225,0x6c090a3b35316472,0x2e6d617261702e64,0x3972250920363173\n"
".quad 0x75635f5f5b202c31,0x5f5f6d7261706164,0x6c65626f5331315a,0x3650646572616853\n"
".quad 0x7374347261686375,0x6846506966737373,0x0a3b5d775f456668,0x3233732e72687309\n"
".quad 0x202c323972250920,0x3133202c31397225,0x732e766f6d090a3b,0x3339722509203233\n"
".quad 0x6e61090a3b33202c,0x2509203233622e64,0x397225202c343972,0x3b33397225202c32\n"
".quad 0x33732e646461090a,0x2c35397225092032,0x25202c3439722520,0x6873090a3b313972\n"
".quad 0x2509203233732e72,0x397225202c363972,0x63090a3b32202c35,0x732e3631732e7476\n"
".quad 0x3739722509203233,0x0a3b36397225202c,0x617261702e646c09,0x2509203631732e6d\n"
".quad 0x5f5f5b202c383972,0x6d72617061647563,0x626f5331315a5f5f,0x6465726168536c65\n"
".quad 0x3472616863753650,0x5069667373737374,0x5d685f4566686846,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x397225202c377025,0x3b38317225202c38,0x732e706c6573090a\n"
".quad 0x3939722509203233,0x202c30202c31202c,0x6f6d090a3b377025,0x2509203233752e76\n"
".quad 0x746e25202c303272,0x6c090a3b782e6469,0x2e6d617261702e64,0x3566250920323366\n"
".quad 0x75635f5f5b202c39,0x5f5f6d7261706164,0x6c65626f5331315a,0x3650646572616853\n"
".quad 0x7374347261686375,0x6846506966737373,0x616353665f456668,0x744c240a3b5d656c\n"
".quad 0x3a323639385f335f,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x2e090a3638312065,0x3109373109636f6c,0x756d090a30093638,0x3233732e6f6c2e6c\n"
".quad 0x2c30303172250920,0x3b34202c33722520,0x33732e646461090a,0x3130317225092032\n"
".quad 0x202c33317225202c,0x090a3b3030317225,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x30317225202c3631,0x2e646461090a3b31,0x6472250920343675,0x3631647225202c33\n"
".quad 0x0a3b31647225202c,0x092038752e646c09,0x5b202c3230317225,0x3b5d312b33647225\n"
".quad 0x3109636f6c2e090a,0x0a30093738310937,0x092038752e646c09,0x5b202c3330317225\n"
".quad 0x3b5d322b33647225,0x3109636f6c2e090a,0x0a30093938310937,0x3233732e64646109\n"
".quad 0x2c34303172250920,0x202c313031722520,0x63090a3b30397225,0x732e3436732e7476\n"
".quad 0x3164722509203233,0x3430317225202c37,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x3731647225202c38,0x0a3b31647225202c,0x092038752e646c09,0x5b202c3530317225\n"
".quad 0x5d312b3831647225,0x09636f6c2e090a3b,0x3009303931093731,0x2038752e646c090a\n"
".quad 0x202c363031722509,0x322b38316472255b,0x636f6c2e090a3b5d,0x0932393109373109\n"
".quad 0x6c2e6c756d090a30,0x2509203233732e6f,0x7225202c37303172,0x61090a3b32202c33\n"
".quad 0x09203233732e6464,0x25202c3830317225,0x7225202c37303172,0x6c756d090a3b3039\n"
".quad 0x203233732e6f6c2e,0x202c393031722509,0x32202c3830317225,0x732e646461090a3b\n"
".quad 0x3131722509203233,0x2c33317225202c30,0x0a3b393031722520,0x3436732e74766309\n"
".quad 0x722509203233732e,0x317225202c393164,0x646461090a3b3031,0x722509203436752e\n"
".quad 0x647225202c303264,0x31647225202c3931,0x38752e646c090a3b,0x2c31313172250920\n"
".quad 0x2b30326472255b20,0x6f6c2e090a3b5d31,0x3339310937310963,0x752e646c090a3009\n"
".quad 0x3231317225092038,0x30326472255b202c,0x6c2e090a3b5d322b,0x393109373109636f\n"
".quad 0x2e646c090a300935,0x3131722509203875,0x336472255b202c33,0x7473090a3b5d302b\n"
".quad 0x752e6d617261702e,0x635f5f5b09203233,0x616d726170616475,0x6f746f7270665f31\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f\n"
".quad 0x3331317225202c5d,0x732e766f6d090a3b,0x3131722509203233,0x3230317225202c34\n"
".quad 0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09,0x665f32616d726170\n"
".quad 0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x202c5d665f69555f,0x090a3b3431317225,0x203233732e766f6d,0x202c353131722509\n"
".quad 0x090a3b3330317225,0x6d617261702e7473,0x5f5b09203233752e,0x726170616475635f\n"
".quad 0x6f7270665f33616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x317225202c5d665f,0x2e646c090a3b3531,0x3131722509203875\n"
".quad 0x316472255b202c36,0x73090a3b5d302b38,0x2e6d617261702e74,0x5f5f5b0920323375\n"
".quad 0x6d72617061647563,0x746f7270665f3461,0x5f69555f69555f6f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x31317225202c5d66,0x2e766f6d090a3b36\n"
".quad 0x3172250920323373,0x30317225202c3731,0x702e7473090a3b35,0x3233752e6d617261\n"
".quad 0x6475635f5f5b0920,0x5f35616d72617061,0x555f6f746f727066,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x2c5d665f69555f69,0x0a3b373131722520\n"
".quad 0x3233732e766f6d09,0x2c38313172250920,0x0a3b363031722520,0x617261702e747309\n"
".quad 0x5b09203233752e6d,0x6170616475635f5f,0x7270665f36616d72,0x555f69555f6f746f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x7225202c5d665f69\n"
".quad 0x646c090a3b383131,0x317225092038752e,0x6472255b202c3931,0x090a3b5d302b3032\n"
".quad 0x6d617261702e7473,0x5f5b09203233752e,0x726170616475635f,0x6f7270665f37616d\n"
".quad 0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x317225202c5d665f,0x766f6d090a3b3931,0x722509203233732e,0x317225202c303231\n"
".quad 0x2e7473090a3b3131,0x33752e6d61726170,0x75635f5f5b092032,0x38616d7261706164\n"
".quad 0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x5d665f69555f6955,0x3b3032317225202c,0x33732e766f6d090a,0x3132317225092032\n"
".quad 0x3b3231317225202c,0x7261702e7473090a,0x09203233752e6d61,0x70616475635f5f5b\n"
".quad 0x70665f39616d7261,0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x25202c5d665f6955,0x6d090a3b31323172,0x09203233662e766f\n"
".quad 0x6625202c30366625,0x2e7473090a3b3935,0x33662e6d61726170,0x75635f5f5b092032\n"
".quad 0x31616d7261706164,0x6f746f7270665f30,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x665f69555f69555f,0x3b30366625202c5d,0x6f6c672e646c090a\n"
".quad 0x203436732e6c6162,0x202c313264722509,0x75466b636f6c625b,0x3b5d6e6f6974636e\n"
".quad 0x5f6f746f7270660a,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x3a665f69555f6955,0x72706c6c61632e20,0x20657079746f746f,0x206d617261702e28\n"
".quad 0x20295f203233752e,0x617261702e28205f,0x5f203233752e206d,0x617261702e20202c\n"
".quad 0x5f203233752e206d,0x617261702e20202c,0x5f203233752e206d,0x617261702e20202c\n"
".quad 0x5f203233752e206d,0x617261702e20202c,0x5f203233752e206d,0x617261702e20202c\n"
".quad 0x5f203233752e206d,0x617261702e20202c,0x5f203233752e206d,0x617261702e20202c\n"
".quad 0x5f203233752e206d,0x617261702e20202c,0x5f203233752e206d,0x617261702e20202c\n"
".quad 0x5f203233662e206d,0x6c6c6163090a3b29,0x616475635f5f2820,0x7270665f61746572\n"
".quad 0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x7225202c29665f69,0x5f5f28202c313264,0x6d72617061647563,0x746f7270665f3161\n"
".quad 0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x6475635f5f202c66,0x5f32616d72617061,0x555f6f746f727066,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x202c665f69555f69,0x6170616475635f5f\n"
".quad 0x7270665f33616d72,0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x635f5f202c665f69,0x616d726170616475,0x6f746f7270665f34\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f\n"
".quad 0x616475635f5f202c,0x665f35616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x5f202c665f69555f,0x726170616475635f\n"
".quad 0x6f7270665f36616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x75635f5f202c665f,0x37616d7261706164,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x2c665f69555f6955\n"
".quad 0x70616475635f5f20,0x70665f38616d7261,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x5f5f202c665f6955,0x6d72617061647563\n"
".quad 0x746f7270665f3961,0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x6475635f5f202c66,0x3031616d72617061,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x29665f69555f6955\n"
".quad 0x6f746f727066202c,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36383120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x0a323639385f335f,0x617261702e646c09,0x2509203233752e6d,0x5f5b202c32323172\n"
".quad 0x746572616475635f,0x6f746f7270665f61,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x665f69555f69555f,0x2e766f6d090a3b5d,0x3172250920323373\n"
".quad 0x32317225202c3332,0x2e747663090a3b32,0x09203233752e3875,0x25202c3432317225\n"
".quad 0x2e090a3b33323172,0x3109373109636f6c,0x646c090a30093939,0x317225092038752e\n"
".quad 0x6472255b202c3532,0x2e090a3b5d332b33,0x3209373109636f6c,0x646c090a30093030\n"
".quad 0x317225092038752e,0x6472255b202c3632,0x090a3b5d332b3831,0x09373109636f6c2e\n"
".quad 0x6c090a3009313032,0x7225092038752e64,0x72255b202c373231,0x0a3b5d332b303264\n"
".quad 0x373109636f6c2e09,0x090a300932303209,0x203233732e766f6d,0x202c383231722509\n"
".quad 0x090a3b3230317225,0x6d617261702e7473,0x5f5b09203233752e,0x726170616475635f\n"
".quad 0x6f7270665f31616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x317225202c5d665f,0x766f6d090a3b3832,0x722509203233732e\n"
".quad 0x317225202c393231,0x2e7473090a3b3330,0x33752e6d61726170,0x75635f5f5b092032\n"
".quad 0x32616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x5d665f69555f6955,0x3b3932317225202c,0x33732e766f6d090a\n"
".quad 0x3033317225092032,0x3b3532317225202c,0x7261702e7473090a,0x09203233752e6d61\n"
".quad 0x70616475635f5f5b,0x70665f33616d7261,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x25202c5d665f6955,0x6d090a3b30333172\n"
".quad 0x09203233732e766f,0x25202c3133317225,0x73090a3b35303172,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323375,0x6d72617061647563,0x746f7270665f3461,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x33317225202c5d66\n"
".quad 0x2e766f6d090a3b31,0x3172250920323373,0x30317225202c3233,0x702e7473090a3b36\n"
".quad 0x3233752e6d617261,0x6475635f5f5b0920,0x5f35616d72617061,0x555f6f746f727066\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x2c5d665f69555f69\n"
".quad 0x0a3b323331722520,0x3233732e766f6d09,0x2c33333172250920,0x0a3b363231722520\n"
".quad 0x617261702e747309,0x5b09203233752e6d,0x6170616475635f5f,0x7270665f36616d72\n"
".quad 0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x7225202c5d665f69,0x6f6d090a3b333331,0x2509203233732e76,0x7225202c34333172\n"
".quad 0x7473090a3b313131,0x752e6d617261702e,0x635f5f5b09203233,0x616d726170616475\n"
".quad 0x6f746f7270665f37,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x3433317225202c5d,0x732e766f6d090a3b,0x3331722509203233\n"
".quad 0x3231317225202c35,0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09\n"
".quad 0x665f38616d726170,0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x202c5d665f69555f,0x090a3b3533317225,0x203233732e766f6d\n"
".quad 0x202c363331722509,0x090a3b3732317225,0x6d617261702e7473,0x5f5b09203233752e\n"
".quad 0x726170616475635f,0x6f7270665f39616d,0x69555f69555f6f74,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x317225202c5d665f,0x766f6d090a3b3633\n"
".quad 0x662509203233662e,0x39356625202c3136,0x61702e7473090a3b,0x203233662e6d6172\n"
".quad 0x616475635f5f5b09,0x5f3031616d726170,0x555f6f746f727066,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x2c5d665f69555f69,0x090a3b3136662520\n"
".quad 0x61626f6c672e646c,0x2509203436752e6c,0x625b202c32326472,0x636e75466b636f6c\n"
".quad 0x090a3b5d6e6f6974,0x5f5f28206c6c6163,0x6174657261647563,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x29665f69555f6955\n"
".quad 0x2c3232647225202c,0x616475635f5f2820,0x665f31616d726170,0x69555f6f746f7270\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x5f202c665f69555f\n"
".quad 0x726170616475635f,0x6f7270665f32616d,0x69555f69555f6f74,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x75635f5f202c665f,0x33616d7261706164\n"
".quad 0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x2c665f69555f6955,0x70616475635f5f20,0x70665f34616d7261,0x5f69555f6f746f72\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x5f5f202c665f6955\n"
".quad 0x6d72617061647563,0x746f7270665f3561,0x5f69555f69555f6f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x6475635f5f202c66,0x5f36616d72617061\n"
".quad 0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x202c665f69555f69,0x6170616475635f5f,0x7270665f37616d72,0x555f69555f6f746f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x635f5f202c665f69\n"
".quad 0x616d726170616475,0x6f746f7270665f38,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x665f69555f69555f,0x616475635f5f202c,0x665f39616d726170\n"
".quad 0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x5f202c665f69555f,0x726170616475635f,0x7270665f3031616d,0x555f69555f6f746f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x7066202c29665f69\n"
".quad 0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x2f200a3b665f6955,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3638,0x64656c6562616c20,0x385f335f744c2420\n"
".quad 0x2e646c090a323639,0x33752e6d61726170,0x3733317225092032,0x6475635f5f5b202c\n"
".quad 0x70665f6174657261,0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x090a3b5d665f6955,0x203233732e766f6d,0x202c383331722509\n"
".quad 0x090a3b3733317225,0x752e38752e747663,0x3331722509203233,0x3833317225202c39\n"
".quad 0x09636f6c2e090a3b,0x3009363032093731,0x2038752e646c090a,0x202c323031722509\n"
".quad 0x5d342b336472255b,0x09636f6c2e090a3b,0x3009373032093731,0x2038752e646c090a\n"
".quad 0x202c353031722509,0x342b38316472255b,0x636f6c2e090a3b5d,0x0938303209373109\n"
".quad 0x38752e646c090a30,0x2c31313172250920,0x2b30326472255b20,0x6f6c2e090a3b5d34\n"
".quad 0x3930320937310963,0x2e766f6d090a3009,0x3172250920323373,0x30317225202c3034\n"
".quad 0x702e7473090a3b33,0x3233752e6d617261,0x6475635f5f5b0920,0x5f31616d72617061\n"
".quad 0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x2c5d665f69555f69,0x0a3b303431722520,0x3233732e766f6d09,0x2c31343172250920\n"
".quad 0x0a3b353231722520,0x617261702e747309,0x5b09203233752e6d,0x6170616475635f5f\n"
".quad 0x7270665f32616d72,0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x7225202c5d665f69,0x6f6d090a3b313431,0x2509203233732e76\n"
".quad 0x7225202c32343172,0x7473090a3b323031,0x752e6d617261702e,0x635f5f5b09203233\n"
".quad 0x616d726170616475,0x6f746f7270665f33,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x665f69555f69555f,0x3234317225202c5d,0x732e766f6d090a3b\n"
".quad 0x3431722509203233,0x3630317225202c33,0x61702e7473090a3b,0x203233752e6d6172\n"
".quad 0x616475635f5f5b09,0x665f34616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x202c5d665f69555f,0x090a3b3334317225\n"
".quad 0x203233732e766f6d,0x202c343431722509,0x090a3b3632317225,0x6d617261702e7473\n"
".quad 0x5f5b09203233752e,0x726170616475635f,0x6f7270665f35616d,0x69555f69555f6f74\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x317225202c5d665f\n"
".quad 0x766f6d090a3b3434,0x722509203233732e,0x317225202c353431,0x2e7473090a3b3530\n"
".quad 0x33752e6d61726170,0x75635f5f5b092032,0x36616d7261706164,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x5d665f69555f6955\n"
".quad 0x3b3534317225202c,0x33732e766f6d090a,0x3634317225092032,0x3b3231317225202c\n"
".quad 0x7261702e7473090a,0x09203233752e6d61,0x70616475635f5f5b,0x70665f37616d7261\n"
".quad 0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x25202c5d665f6955,0x6d090a3b36343172,0x09203233732e766f,0x25202c3734317225\n"
".quad 0x73090a3b37323172,0x2e6d617261702e74,0x5f5f5b0920323375,0x6d72617061647563\n"
".quad 0x746f7270665f3861,0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x34317225202c5d66,0x2e766f6d090a3b37,0x3172250920323373\n"
".quad 0x31317225202c3834,0x702e7473090a3b31,0x3233752e6d617261,0x6475635f5f5b0920\n"
".quad 0x5f39616d72617061,0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x2c5d665f69555f69,0x0a3b383431722520,0x3233662e766f6d09\n"
".quad 0x202c323666250920,0x73090a3b39356625,0x2e6d617261702e74,0x5f5f5b0920323366\n"
".quad 0x6d72617061647563,0x6f7270665f303161,0x69555f69555f6f74,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x366625202c5d665f,0x672e646c090a3b32\n"
".quad 0x36752e6c61626f6c,0x3332647225092034,0x6b636f6c625b202c,0x6e6f6974636e7546\n"
".quad 0x6c6c6163090a3b5d,0x616475635f5f2820,0x7270665f61746572,0x555f69555f6f746f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x7225202c29665f69\n"
".quad 0x5f5f28202c333264,0x6d72617061647563,0x746f7270665f3161,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x6475635f5f202c66\n"
".quad 0x5f32616d72617061,0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x202c665f69555f69,0x6170616475635f5f,0x7270665f33616d72\n"
".quad 0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x635f5f202c665f69,0x616d726170616475,0x6f746f7270665f34,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f,0x616475635f5f202c\n"
".quad 0x665f35616d726170,0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x5f202c665f69555f,0x726170616475635f,0x6f7270665f36616d\n"
".quad 0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x75635f5f202c665f,0x37616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x2c665f69555f6955,0x70616475635f5f20\n"
".quad 0x70665f38616d7261,0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x5f5f202c665f6955,0x6d72617061647563,0x746f7270665f3961\n"
".quad 0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x6475635f5f202c66,0x3031616d72617061,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x29665f69555f6955,0x6f746f727066202c\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36383120656e,0x62616c2064616568,0x744c242064656c65,0x0a323639385f335f\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x5f5b202c39343172,0x746572616475635f\n"
".quad 0x6f746f7270665f61,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x2e766f6d090a3b5d,0x3172250920323373,0x34317225202c3035\n"
".quad 0x2e747663090a3b39,0x09203233752e3875,0x25202c3135317225,0x2e090a3b30353172\n"
".quad 0x3209373109636f6c,0x6f6d090a30093631,0x2509203233732e76,0x7225202c32353172\n"
".quad 0x7473090a3b353231,0x752e6d617261702e,0x635f5f5b09203233,0x616d726170616475\n"
".quad 0x6f746f7270665f31,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x3235317225202c5d,0x732e766f6d090a3b,0x3531722509203233\n"
".quad 0x3230317225202c33,0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09\n"
".quad 0x665f32616d726170,0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x202c5d665f69555f,0x090a3b3335317225,0x25092038752e646c\n"
".quad 0x255b202c34353172,0x0a3b5d352b336472,0x617261702e747309,0x5b09203233752e6d\n"
".quad 0x6170616475635f5f,0x7270665f33616d72,0x555f69555f6f746f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x7225202c5d665f69,0x6f6d090a3b343531\n"
".quad 0x2509203233732e76,0x7225202c35353172,0x7473090a3b363231,0x752e6d617261702e\n"
".quad 0x635f5f5b09203233,0x616d726170616475,0x6f746f7270665f34,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f,0x3535317225202c5d\n"
".quad 0x732e766f6d090a3b,0x3531722509203233,0x3530317225202c36,0x61702e7473090a3b\n"
".quad 0x203233752e6d6172,0x616475635f5f5b09,0x665f35616d726170,0x69555f6f746f7270\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x202c5d665f69555f\n"
".quad 0x090a3b3635317225,0x25092038752e646c,0x255b202c37353172,0x3b5d352b38316472\n"
".quad 0x7261702e7473090a,0x09203233752e6d61,0x70616475635f5f5b,0x70665f36616d7261\n"
".quad 0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x25202c5d665f6955,0x6d090a3b37353172,0x09203233732e766f,0x25202c3835317225\n"
".quad 0x73090a3b37323172,0x2e6d617261702e74,0x5f5f5b0920323375,0x6d72617061647563\n"
".quad 0x746f7270665f3761,0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x35317225202c5d66,0x2e766f6d090a3b38,0x3172250920323373\n"
".quad 0x31317225202c3935,0x702e7473090a3b31,0x3233752e6d617261,0x6475635f5f5b0920\n"
".quad 0x5f38616d72617061,0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x2c5d665f69555f69,0x0a3b393531722520,0x092038752e646c09\n"
".quad 0x5b202c3036317225,0x5d352b3032647225,0x61702e7473090a3b,0x203233752e6d6172\n"
".quad 0x616475635f5f5b09,0x665f39616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x202c5d665f69555f,0x090a3b3036317225\n"
".quad 0x203233662e766f6d,0x25202c3336662509,0x7473090a3b393566,0x662e6d617261702e\n"
".quad 0x635f5f5b09203233,0x616d726170616475,0x746f7270665f3031,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x33366625202c5d66\n"
".quad 0x6c672e646c090a3b,0x3436752e6c61626f,0x2c34326472250920,0x466b636f6c625b20\n"
".quad 0x5d6e6f6974636e75,0x206c6c6163090a3b,0x72616475635f5f28,0x6f7270665f617465\n"
".quad 0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x647225202c29665f,0x635f5f28202c3432,0x616d726170616475,0x6f746f7270665f31\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f\n"
".quad 0x616475635f5f202c,0x665f32616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x5f202c665f69555f,0x726170616475635f\n"
".quad 0x6f7270665f33616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x75635f5f202c665f,0x34616d7261706164,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x2c665f69555f6955\n"
".quad 0x70616475635f5f20,0x70665f35616d7261,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x5f5f202c665f6955,0x6d72617061647563\n"
".quad 0x746f7270665f3661,0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x6475635f5f202c66,0x5f37616d72617061,0x555f6f746f727066\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x202c665f69555f69\n"
".quad 0x6170616475635f5f,0x7270665f38616d72,0x555f69555f6f746f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x635f5f202c665f69,0x616d726170616475\n"
".quad 0x6f746f7270665f39,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x616475635f5f202c,0x5f3031616d726170,0x555f6f746f727066\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x2c29665f69555f69\n"
".quad 0x5f6f746f72706620,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x3b665f69555f6955,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3638312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x090a323639385f33,0x6d617261702e646c,0x722509203233752e,0x5f5f5b202c313631\n"
".quad 0x6174657261647563,0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x5d665f69555f6955,0x732e766f6d090a3b,0x3631722509203233\n"
".quad 0x3136317225202c32,0x752e747663090a3b,0x2509203233752e38,0x7225202c33363172\n"
".quad 0x2140090a3b323631,0x2061726220367025,0x395f335f744c2409,0x2f2f200a3b383132\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383120656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x39385f335f744c24,0x636f6c2e090a3236\n"
".quad 0x0930323209373109,0x732e766f6d090a30,0x3631722509203233,0x3432317225202c34\n"
".quad 0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09,0x665f31616d726170\n"
".quad 0x69555f6f746f7270,0x202c5d665f69555f,0x090a3b3436317225,0x203233662e766f6d\n"
".quad 0x30202c3436662509,0x3030303631333466,0x2f09202020203b30,0x73090a303531202f\n"
".quad 0x2e6d617261702e74,0x5f5f5b0920323366,0x6d72617061647563,0x746f7270665f3261\n"
".quad 0x5f69555f69555f6f,0x34366625202c5d66,0x6f746f7270660a3b,0x665f69555f69555f\n"
".quad 0x706c6c61632e203a,0x657079746f746f72,0x6d617261702e2820,0x295f203233752e20\n"
".quad 0x7261702e28205f20,0x203233752e206d61,0x7261702e20202c5f,0x203233662e206d61\n"
".quad 0x6c6163090a3b295f,0x6475635f5f28206c,0x70665f6174657261,0x5f69555f6f746f72\n"
".quad 0x25202c29665f6955,0x5f28202c34316472,0x726170616475635f,0x6f7270665f31616d\n"
".quad 0x69555f69555f6f74,0x75635f5f202c665f,0x32616d7261706164,0x5f6f746f7270665f\n"
".quad 0x29665f69555f6955,0x6f746f727066202c,0x665f69555f69555f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36383120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a323639385f335f,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x5f5b202c35363172,0x746572616475635f,0x6f746f7270665f61\n"
".quad 0x665f69555f69555f,0x2e766f6d090a3b5d,0x3172250920323373,0x36317225202c3636\n"
".quad 0x2e766f6d090a3b35,0x3172250920323373,0x36317225202c3432,0x636f6c2e090a3b36\n"
".quad 0x0931323209373109,0x732e766f6d090a30,0x3631722509203233,0x3933317225202c37\n"
".quad 0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09,0x665f31616d726170\n"
".quad 0x69555f6f746f7270,0x202c5d665f69555f,0x090a3b3736317225,0x203233662e766f6d\n"
".quad 0x30202c3536662509,0x3030303631333466,0x2f09202020203b30,0x73090a303531202f\n"
".quad 0x2e6d617261702e74,0x5f5f5b0920323366,0x6d72617061647563,0x746f7270665f3261\n"
".quad 0x5f69555f69555f6f,0x35366625202c5d66,0x206c6c6163090a3b,0x72616475635f5f28\n"
".quad 0x6f7270665f617465,0x69555f69555f6f74,0x647225202c29665f,0x635f5f28202c3431\n"
".quad 0x616d726170616475,0x6f746f7270665f31,0x665f69555f69555f,0x616475635f5f202c\n"
".quad 0x665f32616d726170,0x69555f6f746f7270,0x202c29665f69555f,0x555f6f746f727066\n"
".quad 0x0a3b665f69555f69,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36383120,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x6c090a323639385f,0x2e6d617261702e64,0x3172250920323375,0x635f5f5b202c3836\n"
".quad 0x5f61746572616475,0x555f6f746f727066,0x3b5d665f69555f69,0x33732e766f6d090a\n"
".quad 0x3936317225092032,0x3b3836317225202c,0x33732e766f6d090a,0x3933317225092032\n"
".quad 0x3b3936317225202c,0x3109636f6c2e090a,0x0a30093232320937,0x3233732e766f6d09\n"
".quad 0x2c30373172250920,0x0a3b313531722520,0x617261702e747309,0x5b09203233752e6d\n"
".quad 0x6170616475635f5f,0x7270665f31616d72,0x555f69555f6f746f,0x7225202c5d665f69\n"
".quad 0x6f6d090a3b303731,0x2509203233662e76,0x346630202c363666,0x3b30303030363133\n"
".quad 0x202f2f0920202020,0x2e7473090a303531,0x33662e6d61726170,0x75635f5f5b092032\n"
".quad 0x32616d7261706164,0x5f6f746f7270665f,0x5d665f69555f6955,0x0a3b36366625202c\n"
".quad 0x5f28206c6c616309,0x746572616475635f,0x6f746f7270665f61,0x665f69555f69555f\n"
".quad 0x3431647225202c29,0x6475635f5f28202c,0x5f31616d72617061,0x555f6f746f727066\n"
".quad 0x202c665f69555f69,0x6170616475635f5f,0x7270665f32616d72,0x555f69555f6f746f\n"
".quad 0x7066202c29665f69,0x5f69555f6f746f72,0x2f200a3b665f6955,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3638\n"
".quad 0x64656c6562616c20,0x385f335f744c2420,0x2e646c090a323639,0x33752e6d61726170\n"
".quad 0x3137317225092032,0x6475635f5f5b202c,0x70665f6174657261,0x5f69555f6f746f72\n"
".quad 0x090a3b5d665f6955,0x203233732e766f6d,0x202c323731722509,0x090a3b3137317225\n"
".quad 0x203233732e766f6d,0x202c313531722509,0x090a3b3237317225,0x09373109636f6c2e\n"
".quad 0x6d090a3009333232,0x09203233732e766f,0x25202c3337317225,0x73090a3b33363172\n"
".quad 0x2e6d617261702e74,0x5f5f5b0920323375,0x6d72617061647563,0x746f7270665f3161\n"
".quad 0x5f69555f69555f6f,0x37317225202c5d66,0x2e766f6d090a3b33,0x3666250920323366\n"
".quad 0x3133346630202c37,0x20203b3030303036,0x3531202f2f092020,0x61702e7473090a30\n"
".quad 0x203233662e6d6172,0x616475635f5f5b09,0x665f32616d726170,0x69555f6f746f7270\n"
".quad 0x202c5d665f69555f,0x63090a3b37366625,0x635f5f28206c6c61,0x5f61746572616475\n"
".quad 0x555f6f746f727066,0x2c29665f69555f69,0x202c343164722520,0x70616475635f5f28\n"
".quad 0x70665f31616d7261,0x5f69555f6f746f72,0x5f5f202c665f6955,0x6d72617061647563\n"
".quad 0x746f7270665f3261,0x5f69555f69555f6f,0x6f727066202c2966,0x69555f69555f6f74\n"
".quad 0x3c2f2f200a3b665f,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x36383120656e696c,0x6c2064616568202c,0x242064656c656261,0x3639385f335f744c\n"
".quad 0x61702e646c090a32,0x203233752e6d6172,0x202c343731722509,0x72616475635f5f5b\n"
".quad 0x6f7270665f617465,0x69555f69555f6f74,0x6f6d090a3b5d665f,0x2509203233732e76\n"
".quad 0x7225202c35373172,0x6f6d090a3b343731,0x2509203233732e76,0x7225202c33363172\n"
".quad 0x744c240a3b353731,0x3a383132395f335f,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3638312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x090a323639385f33,0x203233732e646461,0x202c363731722509\n"
".quad 0x387225202c337225,0x2e746573090a3b39,0x732e3233752e7467,0x3731722509203233\n"
".quad 0x2c37397225202c37,0x0a3b363731722520,0x3233732e67656e09,0x2c38373172250920\n"
".quad 0x0a3b373731722520,0x3233622e646e6109,0x2c39373172250920,0x202c383731722520\n"
".quad 0x6d090a3b39397225,0x09203233752e766f,0x30202c3038317225,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x317225202c387025,0x38317225202c3937,0x38702540090a3b30\n"
".quad 0x4c24092061726220,0x303337395f335f74,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36383120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a323639385f335f,0x373109636f6c2e09,0x090a300936323209\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x37317225202c3532,0x2e6c756d090a3b36\n"
".quad 0x3233732e65646977,0x2c36326472250920,0x202c363731722520,0x2e646461090a3b34\n"
".quad 0x6472250920343675,0x31647225202c3732,0x3632647225202c33,0x6c672e7473090a3b\n"
".quad 0x2e34762e6c61626f,0x6472255b09203875,0x7b202c5d302b3732,0x72252c3432317225\n"
".quad 0x353172252c393331,0x7d33363172252c31,0x5f335f744c240a3b,0x2f200a3a30333739\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3638,0x64656c6562616c20,0x385f335f744c2420,0x6f6c2e090a323639\n"
".quad 0x3937310937310963,0x2e646461090a3009,0x3172250920323375,0x2c337225202c3138\n"
".quad 0x090a3b3032722520,0x2e3631732e747663,0x3372250920323373,0x3b3138317225202c\n"
".quad 0x6c2e70746573090a,0x2509203233732e74,0x2c337225202c3970,0x40090a3b34722520\n"
".quad 0x2061726220397025,0x385f335f744c2409,0x744c240a3b323639,0x3a303534385f335f\n"
".quad 0x3109636f6c2e090a,0x0a30093233320937,0x240a3b7469786509,0x5f5f646e6557444c\n"
".quad 0x6c65626f5331315a,0x3650646572616853,0x7374347261686375,0x6846506966737373\n"
".quad 0x207d090a3a456668,0x5331315a5f202f2f,0x726168536c65626f,0x6168637536506465\n"
".quad 0x6673737373743472,0x0a45666868465069,0x7972746e652e090a,0x626f5334315a5f20\n"
".quad 0x6d4979706f436c65,0x69696a6850656761,0x702e09090a282066,0x36752e206d617261\n"
".quad 0x616475635f5f2034,0x315a5f5f6d726170,0x6f436c65626f5334,0x506567616d497970\n"
".quad 0x53705f6669696a68,0x6769724f6c65626f,0x09090a2c6c616e69,0x2e206d617261702e\n"
".quad 0x75635f5f20323375,0x5f5f6d7261706164,0x6c65626f5334315a,0x67616d4979706f43\n"
".quad 0x5f6669696a685065,0x090a2c6863746950,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x65626f5334315a5f,0x616d4979706f436c,0x6669696a68506567\n"
".quad 0x702e09090a2c775f,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x6f436c65626f5334,0x506567616d497970,0x2c685f6669696a68,0x617261702e09090a\n"
".quad 0x5f203233662e206d,0x726170616475635f,0x6f5334315a5f5f6d,0x4979706f436c6562\n"
".quad 0x696a68506567616d,0x6c616373665f6669,0x2e090a7b090a2965,0x3233752e20676572\n"
".quad 0x3b3e36313c722520,0x2e206765722e090a,0x3c64722520343675,0x65722e090a3b3e38\n"
".quad 0x25203233662e2067,0x090a3b3e37313c66,0x72702e206765722e,0x3e343c7025206465\n"
".quad 0x09636f6c2e090a3b,0x3009363332093731,0x67656257444c240a,0x5334315a5f5f6e69\n"
".quad 0x79706f436c65626f,0x6a68506567616d49,0x6c2e090a3a666969,0x343209373109636f\n"
".quad 0x747663090a300930,0x3233752e3233732e,0x25202c3172250920,0x090a3b782e646974\n"
".quad 0x203233732e766f6d,0x7225202c32722509,0x702e646c090a3b31,0x3233732e6d617261\n"
".quad 0x5b202c3372250920,0x6170616475635f5f,0x5334315a5f5f6d72,0x79706f436c65626f\n"
".quad 0x6a68506567616d49,0x0a3b5d775f666969,0x65672e7074657309,0x702509203233732e\n"
".quad 0x202c317225202c31,0x2540090a3b337225,0x0920617262203170,0x32315f345f744c24\n"
".quad 0x766f6d090a3b3238,0x722509203233752e,0x6961746325202c34,0x7663090a3b782e64\n"
".quad 0x3233662e6e722e74,0x662509203233752e,0x0a3b347225202c31,0x3233752e766f6d09\n"
".quad 0x25202c3572250920,0x0a3b782e6469746e,0x3436732e74766309,0x722509203233752e\n"
".quad 0x3b357225202c3164,0x36732e747663090a,0x2509203233732e34,0x317225202c326472\n"
".quad 0x61702e646c090a3b,0x203233752e6d6172,0x5f5b202c36722509,0x726170616475635f\n"
".quad 0x6f5334315a5f5f6d,0x4979706f436c6562,0x696a68506567616d,0x68637469505f6669\n"
".quad 0x2e6c756d090a3b5d,0x09203233752e6f6c,0x367225202c377225,0x090a3b347225202c\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x0a3b377225202c33,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5f5b202c346472,0x6d72617061647563,0x626f5334315a5f5f\n"
".quad 0x6d4979706f436c65,0x69696a6850656761,0x6c65626f53705f66,0x6c616e696769724f\n"
".quad 0x2e646461090a3b5d,0x6472250920343673,0x2c33647225202c35,0x090a3b3464722520\n"
".quad 0x203436732e646461,0x25202c3664722509,0x647225202c326472,0x702e646c090a3b35\n"
".quad 0x3233662e6d617261,0x5b202c3266250920,0x6170616475635f5f,0x5334315a5f5f6d72\n"
".quad 0x79706f436c65626f,0x6a68506567616d49,0x616373665f666969,0x744c240a3b5d656c\n"
".quad 0x3a343937315f345f,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x6e202c3034322065,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x662e6e722e747663\n"
".quad 0x09203233732e3233,0x327225202c336625,0x662e766f6d090a3b,0x2c34662509203233\n"
".quad 0x6d090a3b33662520,0x09203233662e766f,0x316625202c356625,0x662e766f6d090a3b\n"
".quad 0x2c36662509203233,0x3030303030663020,0x202020203b303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x6625202c37662509,0x2e766f6d090a3b36,0x3866250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x25202c3966250920,0x786574090a3b3866,0x752e34762e64322e,0x7b203233662e3233\n"
".quad 0x2c3972252c387225,0x3172252c30317225,0x2c7865745b2c7d31,0x3566252c3466257b\n"
".quad 0x3966252c3766252c,0x3c2f2f200a3b5d7d,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30343220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3937315f345f744c,0x09636f6c2e090a34,0x3009313432093731,0x33732e766f6d090a\n"
".quad 0x2c32317225092032,0x63090a3b38722520,0x33752e38752e7476,0x2c33317225092032\n"
".quad 0x090a3b3231722520,0x662e6e722e747663,0x09203233752e3233,0x7225202c30316625\n"
".quad 0x6c756d090a3b3331,0x662509203233662e,0x30316625202c3131,0x090a3b326625202c\n"
".quad 0x203233662e766f6d,0x30202c3231662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x78616d090a30202f,0x662509203233662e,0x31316625202c3331,0x0a3b32316625202c\n"
".quad 0x3233662e766f6d09,0x202c343166250920,0x3030663733346630,0x09202020203b3030\n"
".quad 0x090a353532202f2f,0x203233662e6e696d,0x25202c3531662509,0x316625202c333166\n"
".quad 0x2e747663090a3b34,0x2e3233752e697a72,0x3172250920323366,0x3b35316625202c34\n"
".quad 0x6f6c672e7473090a,0x092038752e6c6162,0x5d302b366472255b,0x0a3b34317225202c\n"
".quad 0x3233752e64646109,0x25202c3272250920,0x3b357225202c3272,0x36732e646461090a\n"
".quad 0x2c36647225092034,0x25202c3164722520,0x6573090a3b366472,0x33732e746c2e7074\n"
".quad 0x202c327025092032,0x337225202c327225,0x2032702540090a3b,0x744c240920617262\n"
".quad 0x3b343937315f345f,0x315f345f744c240a,0x6c2e090a3a323832,0x343209373109636f\n"
".quad 0x697865090a300933,0x6557444c240a3b74,0x5334315a5f5f646e,0x79706f436c65626f\n"
".quad 0x6a68506567616d49,0x207d090a3a666969,0x5334315a5f202f2f,0x79706f436c65626f\n"
".quad 0x6a68506567616d49,0x652e090a0a666969,0x385a5f207972746e,0x7865546c65626f53\n"
".quad 0x50696669696a6850,0x0a28204566686846,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x65626f53385a5f5f,0x696a68507865546c,0x6668684650696669\n"
".quad 0x6c65626f53705f45,0x6c616e696769724f,0x7261702e09090a2c,0x203233752e206d61\n"
".quad 0x6170616475635f5f,0x6f53385a5f5f6d72,0x68507865546c6562,0x684650696669696a\n"
".quad 0x637469505f456668,0x61702e09090a2c68,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x53385a5f5f6d7261,0x507865546c65626f,0x4650696669696a68,0x0a2c775f45666868\n"
".quad 0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563,0x65626f53385a5f5f\n"
".quad 0x696a68507865546c,0x6668684650696669,0x2e09090a2c685f45,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x65546c65626f5338,0x696669696a685078\n"
".quad 0x665f456668684650,0x090a2c656c616353,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x6c65626f53385a5f,0x69696a6850786554,0x4566686846506966\n"
".quad 0x704f6b636f6c625f,0x2c6e6f6974617265,0x617261702e09090a,0x5f203436752e206d\n"
".quad 0x726170616475635f,0x626f53385a5f5f6d,0x6a68507865546c65,0x6868465069666969\n"
".quad 0x6e696f50705f4566,0x6974617265704f74,0x090a7b090a296e6f,0x33752e206765722e\n"
".quad 0x3e30373c72252032,0x206765722e090a3b,0x647225203436752e,0x2e090a3b3e35313c\n"
".quad 0x3233662e20676572,0x3b3e39363c662520,0x2e206765722e090a,0x3c70252064657270\n"
".quad 0x61702e090a3b3e35,0x3233752e206d6172,0x70616475635f5f20,0x70665f31616d7261\n"
".quad 0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x2e090a3b665f6955,0x752e206d61726170,0x6475635f5f203233,0x5f32616d72617061\n"
".quad 0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x0a3b665f69555f69,0x206d617261702e09,0x635f5f203233752e,0x616d726170616475\n"
".quad 0x6f746f7270665f33,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x617261702e090a3b,0x5f203233752e206d,0x726170616475635f\n"
".quad 0x6f7270665f34616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x61702e090a3b665f,0x3233752e206d6172,0x70616475635f5f20\n"
".quad 0x70665f35616d7261,0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x2e090a3b665f6955,0x752e206d61726170,0x6475635f5f203233\n"
".quad 0x5f36616d72617061,0x555f6f746f727066,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x0a3b665f69555f69,0x206d617261702e09,0x635f5f203233752e\n"
".quad 0x616d726170616475,0x6f746f7270665f37,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x665f69555f69555f,0x617261702e090a3b,0x5f203233752e206d\n"
".quad 0x726170616475635f,0x6f7270665f38616d,0x69555f69555f6f74,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x61702e090a3b665f,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x70665f39616d7261,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x2e090a3b665f6955,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x3031616d72617061,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x3b665f69555f6955,0x6d617261702e090a\n"
".quad 0x5f5f203233752e20,0x6174657261647563,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x3b665f69555f6955,0x6d617261702e090a\n"
".quad 0x5f5f203233752e20,0x6d72617061647563,0x746f7270665f3161,0x5f69555f69555f6f\n"
".quad 0x7261702e090a3b66,0x203233662e206d61,0x6170616475635f5f,0x7270665f32616d72\n"
".quad 0x555f69555f6f746f,0x702e090a3b665f69,0x33752e206d617261,0x616475635f5f2032\n"
".quad 0x7270665f61746572,0x555f69555f6f746f,0x6c2e090a3b665f69,0x353209373109636f\n"
".quad 0x57444c240a300930,0x5a5f5f6e69676562,0x65546c65626f5338,0x696669696a685078\n"
".quad 0x0a3a456668684650,0x373109636f6c2e09,0x090a300935353209,0x2e3233732e747663\n"
".quad 0x3172250920323375,0x782e64697425202c,0x732e766f6d090a3b,0x2c32722509203233\n"
".quad 0x6c090a3b31722520,0x2e6d617261702e64,0x3372250920323373,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x65546c65626f5338,0x696669696a685078,0x775f456668684650\n"
".quad 0x70746573090a3b5d,0x203233732e65672e,0x7225202c31702509,0x0a3b337225202c31\n"
".quad 0x7262203170254009,0x355f744c24092061,0x090a3b303530325f,0x203233752e766f6d\n"
".quad 0x6325202c34722509,0x0a3b782e64696174,0x2e6e722e74766309,0x203233752e323366\n"
".quad 0x7225202c31662509,0x702e646c090a3b34,0x3436752e6d617261,0x202c316472250920\n"
".quad 0x70616475635f5f5b,0x53385a5f5f6d7261,0x507865546c65626f,0x4650696669696a68\n"
".quad 0x6f50705f45666868,0x617265704f746e69,0x090a3b5d6e6f6974,0x203436752e766f6d\n"
".quad 0x30202c3264722509,0x2e70746573090a3b,0x09203436752e656e,0x647225202c327025\n"
".quad 0x3b32647225202c31,0x33752e766f6d090a,0x202c357225092032,0x3b782e6469746e25\n"
".quad 0x36732e747663090a,0x2509203233752e34,0x357225202c336472,0x662e766f6d090a3b\n"
".quad 0x2c32662509203233,0x3030386662663020,0x202020203b303030,0x0a312d202f2f0920\n"
".quad 0x3233662e64646109,0x25202c3366250920,0x3b326625202c3166,0x33662e766f6d090a\n"
".quad 0x202c346625092032,0x3030303866336630,0x20202020203b3030,0x61090a31202f2f09\n"
".quad 0x09203233662e6464,0x316625202c356625,0x090a3b346625202c,0x6f6c672e61747663\n"
".quad 0x203436752e6c6162,0x62202c3464722509,0x636e75466b636f6c,0x6261745f6e6f6974\n"
".quad 0x2e646c090a3b656c,0x33732e6d61726170,0x202c367225092032,0x70616475635f5f5b\n"
".quad 0x53385a5f5f6d7261,0x507865546c65626f,0x4650696669696a68,0x6f6c625f45666868\n"
".quad 0x74617265704f6b63,0x63090a3b5d6e6f69,0x732e3436732e7476,0x3564722509203233\n"
".quad 0x090a3b367225202c,0x656469772e6c756d,0x722509203233732e,0x2c367225202c3664\n"
".quad 0x646461090a3b3820,0x722509203436752e,0x34647225202c3764,0x0a3b36647225202c\n"
".quad 0x3436732e74766309,0x722509203233732e,0x3b317225202c3864,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c377225,0x6d72617061647563,0x65626f53385a5f5f\n"
".quad 0x696a68507865546c,0x6668684650696669,0x5d68637469505f45,0x6c2e6c756d090a3b\n"
".quad 0x2509203233752e6f,0x2c377225202c3872,0x63090a3b34722520,0x752e3436752e7476\n"
".quad 0x3964722509203233,0x090a3b387225202c,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x5f5f5b202c303164,0x6d72617061647563,0x65626f53385a5f5f,0x696a68507865546c\n"
".quad 0x6668684650696669,0x6c65626f53705f45,0x6c616e696769724f,0x2e646461090a3b5d\n"
".quad 0x6472250920343673,0x39647225202c3131,0x3b3031647225202c,0x36732e646461090a\n"
".quad 0x3231647225092034,0x202c38647225202c,0x090a3b3131647225,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x75635f5f5b202c36,0x5f5f6d7261706164,0x546c65626f53385a\n"
".quad 0x6669696a68507865,0x5f45666868465069,0x3b5d656c61635366,0x325f355f744c240a\n"
".quad 0x2f2f200a3a323635,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x697473656e202c35,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6f6e6b6e75203a73,0x2e747663090a6e77,0x732e3233662e6e72\n"
".quad 0x2c37662509203233,0x6d090a3b32722520,0x09203233662e766f,0x626630202c386625\n"
".quad 0x3b30303030303866,0x2f2f092020202020,0x646461090a312d20,0x662509203233662e\n"
".quad 0x202c376625202c39,0x6f6d090a3b386625,0x2509203233662e76,0x396625202c303166\n"
".quad 0x662e766f6d090a3b,0x3131662509203233,0x090a3b336625202c,0x203233662e766f6d\n"
".quad 0x30202c3231662509,0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x32316625202c3331,0x662e766f6d090a3b,0x3431662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x25202c3531662509,0x6574090a3b343166,0x2e34762e64322e78,0x203233662e323375\n"
".quad 0x3172252c3972257b,0x252c313172252c30,0x65745b2c7d323172,0x2c303166257b2c78\n"
".quad 0x3166252c31316625,0x5d7d353166252c33,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a323635325f355f,0x373109636f6c2e09,0x090a300936353209\n"
".quad 0x203233732e766f6d,0x25202c3331722509,0x766f6d090a3b3972,0x662509203233662e\n"
".quad 0x3b376625202c3631,0x33662e766f6d090a,0x2c37316625092032,0x6d090a3b33662520\n"
".quad 0x09203233662e766f,0x6630202c38316625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3166250920323366,0x3b38316625202c39,0x33662e766f6d090a\n"
".quad 0x2c30326625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6625202c31326625,0x786574090a3b3032,0x752e34762e64322e\n"
".quad 0x7b203233662e3233,0x3172252c34317225,0x252c363172252c35,0x65745b2c7d373172\n"
".quad 0x2c363166257b2c78,0x3166252c37316625,0x5d7d313266252c39,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x0a323635325f355f,0x373109636f6c2e09\n"
".quad 0x090a300937353209,0x203233732e766f6d,0x25202c3831722509,0x6f6d090a3b343172\n"
".quad 0x2509203233662e76,0x336630202c323266,0x3b30303030303866,0x202f2f0920202020\n"
".quad 0x662e646461090a31,0x3332662509203233,0x25202c376625202c,0x6f6d090a3b323266\n"
".quad 0x2509203233662e76,0x326625202c343266,0x2e766f6d090a3b33,0x3266250920323366\n"
".quad 0x0a3b336625202c35,0x3233662e766f6d09,0x202c363266250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x326625202c373266\n"
".quad 0x2e766f6d090a3b36,0x3266250920323366,0x3030306630202c38,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c393266250920,0x74090a3b38326625\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c393172257b20,0x313272252c303272\n"
".quad 0x5b2c7d323272252c,0x3266257b2c786574,0x252c353266252c34,0x393266252c373266\n"
".quad 0x3c2f2f200a3b5d7d,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35353220656e696c,0x6c2064616568202c,0x242064656c656261,0x3635325f355f744c\n"
".quad 0x09636f6c2e090a32,0x3009383532093731,0x33732e766f6d090a,0x2c33327225092032\n"
".quad 0x090a3b3931722520,0x203233662e766f6d,0x25202c3033662509,0x766f6d090a3b3966\n"
".quad 0x662509203233662e,0x3b316625202c3133,0x33662e766f6d090a,0x2c32336625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6625202c33336625,0x766f6d090a3b3233,0x662509203233662e,0x30306630202c3433\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a,0x2c35336625092032\n"
".quad 0x090a3b3433662520,0x762e64322e786574,0x33662e3233752e34,0x2c343272257b2032\n"
".quad 0x3272252c35327225,0x2c7d373272252c36,0x66257b2c7865745b,0x2c313366252c3033\n"
".quad 0x3366252c33336625,0x2f2f200a3b5d7d35,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x35325f355f744c24,0x636f6c2e090a3236,0x0939353209373109,0x732e766f6d090a30\n"
".quad 0x3832722509203233,0x0a3b34327225202c,0x3233662e766f6d09,0x202c363366250920\n"
".quad 0x6f6d090a3b376625,0x2509203233662e76,0x316625202c373366,0x662e766f6d090a3b\n"
".quad 0x3833662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x25202c3933662509,0x6f6d090a3b383366,0x2509203233662e76\n"
".quad 0x306630202c303466,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3134662509203233,0x0a3b30346625202c,0x2e64322e78657409,0x662e3233752e3476\n"
".quad 0x393272257b203233,0x72252c303372252c,0x7d323372252c3133,0x257b2c7865745b2c\n"
".quad 0x373366252c363366,0x66252c393366252c,0x2f200a3b5d7d3134,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3535\n"
".quad 0x64656c6562616c20,0x325f355f744c2420,0x6f6c2e090a323635,0x3036320937310963\n"
".quad 0x2e766f6d090a3009,0x3372250920323373,0x3b39327225202c33,0x33662e766f6d090a\n"
".quad 0x2c32346625092032,0x090a3b3332662520,0x203233662e766f6d,0x25202c3334662509\n"
".quad 0x766f6d090a3b3166,0x662509203233662e,0x30306630202c3434,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x33662e766f6d090a,0x2c35346625092032,0x090a3b3434662520\n"
".quad 0x203233662e766f6d,0x30202c3634662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x766f6d090a30202f,0x662509203233662e,0x36346625202c3734,0x322e786574090a3b\n"
".quad 0x3233752e34762e64,0x72257b203233662e,0x2c353372252c3433,0x3372252c36337225\n"
".quad 0x2c7865745b2c7d37,0x66252c323466257b,0x2c353466252c3334,0x0a3b5d7d37346625\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353220,0x6c6562616c206461,0x355f744c24206465,0x2e090a323635325f\n"
".quad 0x3209373109636f6c,0x6f6d090a30093136,0x2509203233732e76,0x337225202c383372\n"
".quad 0x2e766f6d090a3b34,0x3466250920323366,0x0a3b396625202c38,0x3233662e766f6d09\n"
".quad 0x202c393466250920,0x6f6d090a3b356625,0x2509203233662e76,0x306630202c303566\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3135662509203233\n"
".quad 0x0a3b30356625202c,0x3233662e766f6d09,0x202c323566250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x356625202c333566\n"
".quad 0x2e786574090a3b32,0x33752e34762e6432,0x257b203233662e32,0x303472252c393372\n"
".quad 0x72252c313472252c,0x7865745b2c7d3234,0x252c383466257b2c,0x313566252c393466\n"
".quad 0x3b5d7d333566252c,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3535322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x090a323635325f35,0x09373109636f6c2e,0x6d090a3009323632,0x09203233732e766f\n"
".quad 0x7225202c33347225,0x766f6d090a3b3933,0x662509203233662e,0x3b376625202c3435\n"
".quad 0x33662e766f6d090a,0x2c35356625092032,0x6d090a3b35662520,0x09203233662e766f\n"
".quad 0x6630202c36356625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3566250920323366,0x3b36356625202c37,0x33662e766f6d090a,0x2c38356625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6625202c39356625,0x786574090a3b3835,0x752e34762e64322e,0x7b203233662e3233\n"
".quad 0x3472252c34347225,0x252c363472252c35,0x65745b2c7d373472,0x2c343566257b2c78\n"
".quad 0x3566252c35356625,0x5d7d393566252c37,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x0a323635325f355f,0x373109636f6c2e09,0x090a300933363209\n"
".quad 0x203233732e766f6d,0x25202c3834722509,0x6f6d090a3b343472,0x2509203233662e76\n"
".quad 0x326625202c303666,0x2e766f6d090a3b33,0x3666250920323366,0x0a3b356625202c31\n"
".quad 0x3233662e766f6d09,0x202c323666250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x366625202c333666,0x2e766f6d090a3b32\n"
".quad 0x3666250920323366,0x3030306630202c34,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c353666250920,0x74090a3b34366625,0x34762e64322e7865\n"
".quad 0x3233662e3233752e,0x252c393472257b20,0x313572252c303572,0x5b2c7d323572252c\n"
".quad 0x3666257b2c786574,0x252c313666252c30,0x353666252c333666,0x3c2f2f200a3b5d7d\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x35353220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3635325f355f744c,0x09636f6c2e090a32\n"
".quad 0x3009343632093731,0x33732e766f6d090a,0x2c33357225092032,0x090a3b3934722520\n"
".quad 0x09373109636f6c2e,0x63090a3009353632,0x33752e38752e7476,0x2c34357225092032\n"
".quad 0x090a3b3331722520,0x6d617261702e7473,0x5f5b09203233752e,0x726170616475635f\n"
".quad 0x6f7270665f31616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x357225202c5d665f,0x2e747663090a3b34,0x09203233752e3875\n"
".quad 0x7225202c35357225,0x2e7473090a3b3831,0x33752e6d61726170,0x75635f5f5b092032\n"
".quad 0x32616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x5d665f69555f6955,0x0a3b35357225202c,0x2e38752e74766309\n"
".quad 0x3572250920323375,0x3b33327225202c36,0x7261702e7473090a,0x09203233752e6d61\n"
".quad 0x70616475635f5f5b,0x70665f33616d7261,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x25202c5d665f6955,0x7663090a3b363572\n"
".quad 0x3233752e38752e74,0x202c373572250920,0x73090a3b38327225,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323375,0x6d72617061647563,0x746f7270665f3461,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x37357225202c5d66\n"
".quad 0x752e747663090a3b,0x2509203233752e38,0x337225202c383572,0x702e7473090a3b33\n"
".quad 0x3233752e6d617261,0x6475635f5f5b0920,0x5f35616d72617061,0x555f6f746f727066\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x2c5d665f69555f69\n"
".quad 0x090a3b3835722520,0x752e38752e747663,0x3935722509203233,0x0a3b38337225202c\n"
".quad 0x617261702e747309,0x5b09203233752e6d,0x6170616475635f5f,0x7270665f36616d72\n"
".quad 0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x7225202c5d665f69,0x747663090a3b3935,0x203233752e38752e,0x25202c3036722509\n"
".quad 0x7473090a3b333472,0x752e6d617261702e,0x635f5f5b09203233,0x616d726170616475\n"
".quad 0x6f746f7270665f37,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x665f69555f69555f,0x3b30367225202c5d,0x38752e747663090a,0x722509203233752e\n"
".quad 0x38347225202c3136,0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09\n"
".quad 0x665f38616d726170,0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x202c5d665f69555f,0x63090a3b31367225,0x33752e38752e7476\n"
".quad 0x2c32367225092032,0x090a3b3335722520,0x6d617261702e7473,0x5f5b09203233752e\n"
".quad 0x726170616475635f,0x6f7270665f39616d,0x69555f69555f6f74,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x367225202c5d665f,0x2e766f6d090a3b32\n"
".quad 0x3666250920323366,0x0a3b366625202c36,0x617261702e747309,0x5b09203233662e6d\n"
".quad 0x6170616475635f5f,0x70665f3031616d72,0x5f69555f6f746f72,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x25202c5d665f6955,0x646c090a3b363666\n"
".quad 0x722509203436752e,0x72255b202c333164,0x660a3b5d302b3764,0x69555f6f746f7270\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x2e203a665f69555f\n"
".quad 0x746f72706c6c6163,0x2e2820657079746f,0x752e206d61726170,0x205f20295f203233\n"
".quad 0x206d617261702e28,0x202c5f203233752e,0x206d617261702e20,0x202c5f203233752e\n"
".quad 0x206d617261702e20,0x202c5f203233752e,0x206d617261702e20,0x202c5f203233752e\n"
".quad 0x206d617261702e20,0x202c5f203233752e,0x206d617261702e20,0x202c5f203233752e\n"
".quad 0x206d617261702e20,0x202c5f203233752e,0x206d617261702e20,0x202c5f203233752e\n"
".quad 0x206d617261702e20,0x202c5f203233752e,0x206d617261702e20,0x3b295f203233662e\n"
".quad 0x28206c6c6163090a,0x6572616475635f5f,0x746f7270665f6174,0x5f69555f69555f6f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x31647225202c2966\n"
".quad 0x75635f5f28202c33,0x31616d7261706164,0x5f6f746f7270665f,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x2c665f69555f6955,0x70616475635f5f20\n"
".quad 0x70665f32616d7261,0x5f69555f6f746f72,0x69555f69555f6955,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x5f5f202c665f6955,0x6d72617061647563,0x746f7270665f3361\n"
".quad 0x5f69555f69555f6f,0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x6475635f5f202c66,0x5f34616d72617061,0x555f6f746f727066,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x202c665f69555f69,0x6170616475635f5f\n"
".quad 0x7270665f35616d72,0x555f69555f6f746f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x555f69555f69555f,0x635f5f202c665f69,0x616d726170616475,0x6f746f7270665f36\n"
".quad 0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955,0x665f69555f69555f\n"
".quad 0x616475635f5f202c,0x665f37616d726170,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x5f202c665f69555f,0x726170616475635f\n"
".quad 0x6f7270665f38616d,0x69555f69555f6f74,0x555f69555f69555f,0x5f69555f69555f69\n"
".quad 0x69555f69555f6955,0x75635f5f202c665f,0x39616d7261706164,0x5f6f746f7270665f\n"
".quad 0x69555f69555f6955,0x555f69555f69555f,0x5f69555f69555f69,0x2c665f69555f6955\n"
".quad 0x70616475635f5f20,0x665f3031616d7261,0x69555f6f746f7270,0x555f69555f69555f\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x202c29665f69555f,0x555f6f746f727066\n"
".quad 0x5f69555f69555f69,0x69555f69555f6955,0x555f69555f69555f,0x0a3b665f69555f69\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353220,0x6c6562616c206461,0x355f744c24206465,0x6c090a323635325f\n"
".quad 0x2e6d617261702e64,0x3672250920323375,0x75635f5f5b202c33,0x665f617465726164\n"
".quad 0x69555f6f746f7270,0x555f69555f69555f,0x5f69555f69555f69,0x69555f69555f6955\n"
".quad 0x0a3b5d665f69555f,0x3233732e766f6d09,0x202c343672250920,0x63090a3b33367225\n"
".quad 0x33752e38752e7476,0x2c35367225092032,0x090a3b3436722520,0x7262203270252140\n"
".quad 0x355f744c24092061,0x200a3b383138325f,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353532,0x656c6562616c2064\n"
".quad 0x5f355f744c242064,0x6c2e090a32363532,0x363209373109636f,0x766f6d090a300939\n"
".quad 0x722509203233732e,0x35367225202c3636,0x61702e7473090a3b,0x203233752e6d6172\n"
".quad 0x616475635f5f5b09,0x665f31616d726170,0x69555f6f746f7270,0x202c5d665f69555f\n"
".quad 0x6d090a3b36367225,0x09203233662e766f,0x6630202c37366625,0x3030303036313334\n"
".quad 0x2f2f09202020203b,0x7473090a30353120,0x662e6d617261702e,0x635f5f5b09203233\n"
".quad 0x616d726170616475,0x6f746f7270665f32,0x665f69555f69555f,0x3b37366625202c5d\n"
".quad 0x5f6f746f7270660a,0x3a665f69555f6955,0x72706c6c61632e20,0x20657079746f746f\n"
".quad 0x206d617261702e28,0x20295f203233752e,0x617261702e28205f,0x5f203233752e206d\n"
".quad 0x617261702e20202c,0x5f203233662e206d,0x6c6c6163090a3b29,0x616475635f5f2820\n"
".quad 0x7270665f61746572,0x555f69555f6f746f,0x7225202c29665f69,0x635f5f28202c3164\n"
".quad 0x616d726170616475,0x6f746f7270665f31,0x665f69555f69555f,0x616475635f5f202c\n"
".quad 0x665f32616d726170,0x69555f6f746f7270,0x202c29665f69555f,0x555f6f746f727066\n"
".quad 0x0a3b665f69555f69,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353220,0x6c6562616c206461,0x355f744c24206465\n"
".quad 0x6c090a323635325f,0x2e6d617261702e64,0x3672250920323375,0x75635f5f5b202c37\n"
".quad 0x665f617465726164,0x69555f6f746f7270,0x0a3b5d665f69555f,0x3233732e766f6d09\n"
".quad 0x202c383672250920,0x6d090a3b37367225,0x09203233732e766f,0x7225202c35367225\n"
".quad 0x5f744c240a3b3836,0x0a3a383138325f35,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353220,0x6c6562616c206461\n"
".quad 0x355f744c24206465,0x2e090a323635325f,0x3209373109636f6c,0x7473090a30093137\n"
".quad 0x2e6c61626f6c672e,0x6472255b09203875,0x25202c5d302b3231,0x6461090a3b353672\n"
".quad 0x2509203233752e64,0x2c327225202c3272,0x61090a3b35722520,0x09203436732e6464\n"
".quad 0x25202c3231647225,0x647225202c336472,0x746573090a3b3231,0x3233732e746c2e70\n"
".quad 0x25202c3370250920,0x3b337225202c3272,0x622033702540090a,0x5f744c2409206172\n"
".quad 0x0a3b323635325f35,0x30325f355f744c24,0x6f6c2e090a3a3035,0x3337320937310963\n"
".quad 0x74697865090a3009,0x6e6557444c240a3b,0x626f53385a5f5f64,0x6a68507865546c65\n"
".quad 0x6868465069666969,0x2f207d090a3a4566,0x626f53385a5f202f,0x6a68507865546c65\n"
".quad 0x6868465069666969,0x6f6c672e090a4566,0x696c612e206c6162,0x38622e2038206e67\n"
".quad 0x7546746e696f7020,0x745f6e6f6974636e,0x5d36315b656c6261,0x626f6c672e090a3b\n"
".quad 0x203436752e206c61,0x74636e7546726176,0x3b30203d206e6f69,0x61626f6c672e090a\n"
".quad 0x70203436752e206c,0x53657475706d6f43,0x5f203d206c65626f,0x75706d6f4332315a\n"
".quad 0x686c65626f536574,0x6868686868686868,0x6f6c672e090a3b66,0x3436752e206c6162\n"
".quad 0x7475706d6f437020,0x5f203d20786f4265,0x75706d6f4330315a,0x686868786f426574\n"
".quad 0x3b66686868686868,0x61626f6c672e090a,0x70203436752e206c,0x54657475706d6f43\n"
".quad 0x646c6f6873657268,0x6854395a5f203d20,0x68646c6f68736572,0x000000000a0a3b66\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_20$[5172];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_20$:\n"
".quad 0x33010102464c457f,0x0000000000000004,0x0000000100be0002,0x0000000000000000\n"
".quad 0x00000000000023a4,0x0000000000000040,0x0038004000140114,0x0001001500400006\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000580\n"
".quad 0x0000000000000241,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x00000000000007c1\n"
".quad 0x000000000000010d,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x00000000000008ce\n"
".quad 0x0000000000000348,0x0000001500000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x00000001000000c1,0x0000000000100006,0x0000000000000000,0x0000000000000c16\n"
".quad 0x0000000000000ac0,0x3600000b00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000019d,0x0000000000000002,0x0000000000000000,0x00000000000016d6\n"
".quad 0x0000000000000048,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000169,0x0000000000000002,0x0000000000000000,0x000000000000171e\n"
".quad 0x0000000000000014,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000ec,0x0000000000000002,0x0000000000000000,0x0000000000001732\n"
".quad 0x00000000000000e0,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000080,0x0000000000000006,0x0000000000000000,0x0000000000001812\n"
".quad 0x0000000000000330,0x0e00000900000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000142,0x0000000000000002,0x0000000000000000,0x0000000000001b42\n"
".quad 0x0000000000000038,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000011a,0x0000000000000002,0x0000000000000000,0x0000000000001b7a\n"
".quad 0x0000000000000014,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000009f,0x0000000000000002,0x0000000000000000,0x0000000000001b8e\n"
".quad 0x0000000000000090,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x0000000000001c1e\n"
".quad 0x0000000000000490,0x1a00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001f8,0x0000000000000002,0x0000000000000000,0x00000000000020ae\n"
".quad 0x0000000000000048,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001d0,0x0000000000000002,0x0000000000000000,0x00000000000020f6\n"
".quad 0x0000000000000014,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000055,0x0000000000000002,0x0000000000000000,0x000000000000210a\n"
".quad 0x00000000000000b8,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000010000021f,0x0000000000000002,0x0000000000000000,0x00000000000021c2\n"
".quad 0x000000000000001c,0x0000000000000000,0x0000000000000008,0x0000000000000000\n"
".quad 0x000000090000022e,0x0000000000000000,0x0000000000000000,0x00000000000021de\n"
".quad 0x0000000000000070,0x0000001000000003,0x0000000000000004,0x0000000000000010\n"
".quad 0x000000010000001b,0x0000000000000003,0x0000000000000000,0x000000000000224e\n"
".quad 0x0000000000000020,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000080000002b,0x0000000000000003,0x0000000000000000,0x000000000000226e\n"
".quad 0x0000000000000028,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000077,0x0000000000000002,0x0000000000000000,0x000000000000226e\n"
".quad 0x0000000000000134,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x53385a5f2e747865\n"
".quad 0x507865546c65626f,0x4650696669696a68,0x766e2e0045666868,0x5a5f2e6f666e692e\n"
".quad 0x65546c65626f5338,0x696669696a685078,0x2e00456668684650,0x006f666e692e766e\n"
".quad 0x5a5f2e747865742e,0x436c65626f533431,0x6567616d4979706f,0x2e006669696a6850\n"
".quad 0x2e6f666e692e766e,0x65626f5334315a5f,0x616d4979706f436c,0x6669696a68506567\n"
".quad 0x5f2e747865742e00,0x6c65626f5331315a,0x3650646572616853,0x7374347261686375\n"
".quad 0x6846506966737373,0x2e766e2e00456668,0x315a5f2e6f666e69,0x68536c65626f5331\n"
".quad 0x6375365064657261,0x7373737434726168,0x6668684650696673,0x6f632e766e2e0045\n"
".quad 0x3631746e6174736e,0x626f5334315a5f2e,0x6d4979706f436c65,0x69696a6850656761\n"
".quad 0x6f632e766e2e0066,0x2e30746e6174736e,0x65626f5334315a5f,0x616d4979706f436c\n"
".quad 0x6669696a68506567,0x6e6f632e766e2e00,0x2e3631746e617473,0x65626f5331315a5f\n"
".quad 0x506465726168536c,0x7434726168637536,0x4650696673737373,0x766e2e0045666868\n"
".quad 0x6e6174736e6f632e,0x5331315a5f2e3074,0x726168536c65626f,0x6168637536506465\n"
".quad 0x6673737373743472,0x0045666868465069,0x736e6f632e766e2e,0x5f2e3631746e6174\n"
".quad 0x546c65626f53385a,0x6669696a68507865,0x0045666868465069,0x736e6f632e766e2e\n"
".quad 0x5a5f2e30746e6174,0x65546c65626f5338,0x696669696a685078,0x2e00456668684650\n"
".quad 0x74736e6f632e766e,0x722e003431746e61,0x6f632e766e2e6c65,0x3431746e6174736e\n"
".quad 0x626f53385a5f0000,0x6a68507865546c65,0x6868465069666969,0x4330315a5f004566\n"
".quad 0x6f42657475706d6f,0x6868686868686878,0x54395a5f00666868,0x646c6f6873657268\n"
".quad 0x4332315a5f006668,0x6f53657475706d6f,0x68686868686c6562,0x5a5f006668686868\n"
".quad 0x436c65626f533431,0x6567616d4979706f,0x5f006669696a6850,0x6c65626f5331315a\n"
".quad 0x3650646572616853,0x7374347261686375,0x6846506966737373,0x0078657400456668\n"
".quad 0x74636e7546726176,0x6e696f70006e6f69,0x6f6974636e754674,0x00656c6261745f6e\n"
".quad 0x657475706d6f4370,0x6c62006c65626f53,0x74636e75466b636f,0x636f6c62006e6f69\n"
".quad 0x6f6974636e75466b,0x00656c6261745f6e,0x657475706d6f4370,0x6d6f437000786f42\n"
".quad 0x6572685465747570,0x000000646c6f6873,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000100030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000200030000,0x0000000000000000,0x0000000000000000,0x0000000300030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000001200030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000001300030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000c00030000,0x0490000000000000,0x0000000000000000,0x0000000f00030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000001400030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000800030000,0x0330000000000000,0x0000000000000000\n"
".quad 0x0000000b00030000,0x0000000000000000,0x0000000000000000,0x0000000400030000\n"
".quad 0x0ac0000000000000,0x0000000000000000,0x0000000700030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000a00030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000900030000,0x0000000000000000,0x0000000000000000,0x0000000600030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000500030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000e00030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000d00030000,0x0000000000000000,0x0000000000000000,0x0000001000030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000001100030000,0x0000000000000000\n"
".quad 0x0001000000000000,0x0000000c10120000,0x0238000000000000,0x001a000000000000\n"
".quad 0x0868000c00120000,0x0118000000000000,0x0033000000000000,0x0980000c00120000\n"
".quad 0x0030000000000000,0x0042000000000000,0x09b0000c00120000,0x0110000000000000\n"
".quad 0x005d000000000000,0x0000000810120000,0x00d8000000000000,0x0076000000000000\n"
".quad 0x0000000410120000,0x0868000000000000,0x009b000000000000,0x00000000001a0000\n"
".quad 0x0000000000000000,0x009f000000000000,0x0000001200110000,0x0008000000000000\n"
".quad 0x00ab000000000000,0x0000001300110000,0x0010000000000000,0x00bf000000000000\n"
".quad 0x0008001200110000,0x0008000000000000,0x00cd000000000000,0x0010001300110000\n"
".quad 0x0008000000000000,0x00db000000000000,0x0018001300110000,0x0010000000000000\n"
".quad 0x00ef000000000000,0x0010001200110000,0x0008000000000000,0x00fb000000000000\n"
".quad 0x0018001200110000,0x0008000000000000,0x5de4000000000000,0x9c66280044040000\n"
".quad 0x1c0414000000abf0,0x00072c0000008400,0x9e8460000005c000,0x9e841c00000000a6\n"
".quad 0x1c041c00000008a5,0xdde42c0000008800,0x9c03280000006800,0xdc234800c0000960\n"
".quad 0x21e71a0e00006821,0x1c0440000004c000,0x5c042c0000009801,0x9c662c0000009401\n"
".quad 0xdc0314000000b3f1,0x1c03200040003041,0xde84500000001561,0x5e841c0000001ca1\n"
".quad 0x1e031c00000018a1,0x1c036000c0000841,0x9c034800fffffc72,0xde84500000000051\n"
".quad 0x5e041c00000010a1,0x1e03180000002121,0x5c036000c0000832,0x1e04480000001c82\n"
".quad 0x9c86180000002521,0x1c0380104000fc42,0x1e044800c0000491,0xdc86180000001121\n"
".quad 0x1c0380104000fc42,0x1e044800fffffc91,0x1c86180000001121,0x5c0380104000fc41\n"
".quad 0x5de44800c0000892,0x1e04280000001403,0x5c86180000002523,0x1c0380104000fcc2\n"
".quad 0xdc03480000001882,0x1c23480040002030,0x9c037000c0047c83,0xde84480140000083\n"
".quad 0xdc431c0000000ca0,0xdc2348000000fcc3,0x9c05188e00000833,0xdc059400000004e2\n"
".quad 0x1c059400000008e2,0x5c059400000000e1,0x05e7940000000ce2,0xdc134003fffcc000\n"
".quad 0x00071a0ec0000403,0x05e7600000058000,0xdde4400000054000,0x21e7280000006800\n"
".quad 0x1c04400000050000,0x9c662c0000009801,0x5c0314000000b3f1,0x1c04200040003041\n"
".quad 0x9e842c0000009401,0xde841c00000018a1,0x1c031c00000014a1,0x5c03500000001161\n"
".quad 0xdc03480040003001,0x1e03480040003071,0x9c036000c0000841,0xdc03500000001461\n"
".quad 0xde844800fffffc71,0x5c041c00000010a2,0xde03180000001d21,0x1c036000c0000831\n"
".quad 0x1e04480000002c72,0x5c86180000002121,0x1c0380104000fc42,0x1e044800c0000481\n"
".quad 0x9c86180000001121,0x1c0380104000fc42,0x1e044800fffffc81,0x1c86180000001121\n"
".quad 0x1c0380104000fc41,0x5de44800c0000882,0x1e04280000001403,0x1c86180000002123\n"
".quad 0xdc0380104000fcc2,0xdc03480000001871,0x1c23480040002030,0x9c037000c0047c73\n"
".quad 0xde84480140000073,0xdc431c0000000ca0,0xdc2348000000fcc3,0x5c05188e00000831\n"
".quad 0x9c059400000004e2,0x1c059400000008e2,0x1c059400000000e1,0x01e7940000000ce2\n"
".quad 0xdc134003fffcc000,0xdc04207e0000fc1f,0x9de450ee0000ffff,0xdde228004000e000\n"
".quad 0xdc23180000002000,0x9ca31b0e000059a1,0x9ce32007b8001021,0xdc435000c0002020\n"
".quad 0x9de4480000000bf1,0x1ca5280078000000,0x1ca5840000000061,0x01e7900000000021\n"
".quad 0x5c66800000000000,0x9c6614000000b3f1,0x1c0414000000bbf1,0x9c042c0000009401\n"
".quad 0xdc462c0000009800,0xde8414000000a3f0,0x9e841c00000014a5,0x1c031c00000018a1\n"
".quad 0xdc66500000001161,0xde0314000000c3f1,0x1de44801400103ff,0x9c03280040011002\n"
".quad 0x5c03200040003020,0x1c23500000000176,0x1e035800c0007c60,0xdc436000c0000841\n"
".quad 0xdc041a8e0000fc81,0x9e841c0000000ca0,0xde841c00000008a0,0x5c031c0000001ca1\n"
".quad 0x1e846800c0000c01,0x5c041c00000010a1,0x1ca3080e00001c07,0xdc23500000000c20\n"
".quad 0xdc031a0e00000871,0x9c23480000001850,0x1c235800c0000840,0xdc037000c0047c01\n"
".quad 0x1c23480140008006,0x9c045800c0000830,0x1e84080e00001c07,0x1c431c00000008a5\n"
".quad 0x5e84480040009047,0x1c431c00000000a5,0x1c234000000065a0,0x1de4400000005da1\n"
".quad 0xdc23280078000006,0x9c037000c0047c00,0x1c03480140000000,0x9ca5480000005c00\n"
".quad 0xdc43800000000181,0x5c2348000000fc30,0x1c037000c0047c01,0x1c23480140000004\n"
".quad 0x9c05400000006440,0x5c4384000000042c,0x9c0348000000fc54,0x1c23480140000004\n"
".quad 0x1c057000c0047c00,0xdc0584000000082b,0xdc4384000000050c,0x5c0548000000fc04\n"
".quad 0x1c0584000000090b,0x1c05840000000021,0x9c0584000000052d,0xdc0584000000092b\n"
".quad 0x9c05840000000101,0x5de4840000000122,0x1c8628004000d003,0x5de4140040000060\n"
".quad 0x9de428000000c801,0x1de428000000b001,0x5de428000000cc02,0xdde428000000b402\n"
".quad 0x1de428000000d002,0x000728000000b803,0x1de7780000002001,0x9ca54803ffea6000\n"
".quad 0xdc05800000000181,0x1c05840000000c2b,0x5c05840000000d0c,0xdc04840000000d2c\n"
".quad 0xdde41c0000001027,0x9de428000000cc01,0x5de428000000d002,0x1de428000000b001\n"
".quad 0xdde428000000b402,0x5de428000000b802,0x1de428004000d003,0x1c8628000000c801\n"
".quad 0x5de4140040000060,0x1de428000000c002,0x9de428000000c403,0x000728000000bc01\n"
".quad 0x1de7780000002001,0x9ca54803ffe82000,0xdc05800000000181,0x1c0584000000102c\n"
".quad 0x5c0584000000110d,0x9c0484000000112d,0xdde41c000000102c,0x9de428000000b401\n"
".quad 0x5de428000000b802,0x1de428000000bc01,0xdde428000000c002,0x5de428000000c402\n"
".quad 0x1de428004000d003,0x1c8628000000b001,0x5de4140040000060,0x1de428000000d002\n"
".quad 0x9de428000000d403,0x000728000000cc01,0x1de7780000002001,0x9ca54803ffe5e000\n"
".quad 0x1c04800000000183,0x9c051c000000102b,0x5c05840000001421,0x1c05840000001502\n"
".quad 0x5de4840000001523,0xdde428000000cc01,0x1de428000000c001,0x9de428000000d002\n"
".quad 0xdde428000000c402,0x5de428000000d402,0x1de428004000d003,0x1c8628000000bc01\n"
".quad 0x00071400400000e0,0x1de7780000002001,0xdc034803ffe40000,0x9c041a8e0000fdd1\n"
".quad 0x21e71c0000001020,0xdde4400000032000,0x1de4280040010000,0x5de2280000007c01\n"
".quad 0x1c86190c58000001,0x0007140040000030,0x1de7780000002001,0xdde44803ffe2e000\n"
".quad 0x1c86280000001007,0x5de2140040000030,0x1de4190c58000001,0x000728000000c801\n"
".quad 0x1de7780000002001,0x9de44803ffe22000,0x1c8628000000100c,0x5de2140040000030\n"
".quad 0x1de4190c58000001,0x000728000000b001,0x1de7780000002001,0x1de44803ffe16000\n"
".quad 0x1c8628000000100b,0x5de2140040000030,0x1de4190c58000001,0x0007280000000801\n"
".quad 0x1de7780000002001,0x9de44803ffe0a000,0x1c03280000001000,0xdc034800000051a0\n"
".quad 0xdc231a8e0000fde1,0xa1e71a0000000151,0xc004400000010000,0x80a31c0000007d00\n"
".quad 0x00032037c0001001,0xc0e32806c0202321,0x00035000c0001000,0xc0432808c02042c0\n"
".quad 0x0003480000000dc1,0x00852800c0206020,0x1c03940000000060,0x9e844800400021a0\n"
".quad 0xdc231c00000000a6,0x01e7188e000059a1,0x1de74003ffefe000,0x5c04800000000000\n"
".quad 0x1c041c0000001421,0x1c041c0000001020,0x1c041c0000001821,0x9c041c0000002022\n"
".quad 0x5c031c0000001c21,0x9c04480000001401,0xdc031c0000002822,0x1c04480000002061\n"
".quad 0x9c031c0000002420,0x1c04480000001441,0x1c041c0000003023,0x5c031c0000002c21\n"
".quad 0x9c03480000002801,0x1c03480000001c61,0x1c03480000003040,0x1c03480000001851\n"
".quad 0x1e84480000001000,0x1ec41c00000000a0,0x1c431c0000000121,0x1c23500040004441\n"
".quad 0x5f845800c0000441,0x1c231c0000001121,0x1e84308000001050,0x1e041c00000000a0\n"
".quad 0x1c00180000000120,0x1c84580000003400,0x1e84140600000120,0xdc231c00000000a0\n"
".quad 0x81e7188e0000fc01,0xe023400000006000,0x2004198ec003fc03,0x20041c0000000020\n"
".quad 0x01e42002c003fc01,0x1de728000000fc01,0x1c04900000000000,0x1c041c0000001020\n"
".quad 0xdc00180000000120,0x01e2220e00001401,0x21e418000003fc01,0x1de728000000fc01\n"
".quad 0x1c04900000000000,0x1c041c0000001020,0x9c041c0000001421,0x5c041c0000001821\n"
".quad 0x5c231c0000002421,0x1c04400000000042,0x5c231c0000003022,0x1c04400000001851\n"
".quad 0x9c031c0000002821,0x5c03480000002461,0x5c04480000001482,0x9d031c0000002c21\n"
".quad 0xdc04480000001061,0x5d031c0000001c21,0x1c23480000000092,0x5c23410000001850\n"
".quad 0x1d03410000002471,0x1d03480000002000,0x1e84480000001051,0x1e841c00000000a0\n"
".quad 0x1ec41c00000010a1,0x1ec41c0000000120,0x1c031c0000001121,0x1e04480000001000\n"
".quad 0x1c00180000000120,0x1c84580000003400,0x1e84140600000120,0xdc231c00000000a0\n"
".quad 0x81e7188e0000fc01,0xe023400000006000,0x2004198ec003fc03,0x20041c0000000020\n"
".quad 0x01e42002c003fc01,0x1de728000000fc01,0x0000900000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0001000000000000\n"
".quad 0x0868000009b00000,0x8e39000009800000,0x000000240c0438e3,0x000a000000080000\n"
".quad 0x000e0000000c0000,0x0014000000100000,0x0020000000180000,0x001b000802040000\n"
".quad 0x0a04000000000000,0x0020000000100008,0x1704002819030028,0x0008ffffffff000c\n"
".quad 0x17040021f0000020,0x0007ffffffff000c,0x17040011f0000018,0x0006ffffffff000c\n"
".quad 0x17040011f0000014,0x0005ffffffff000c,0x17040009f0000010,0x0004ffffffff000c\n"
".quad 0x17040009f000000e,0x0003ffffffff000c,0x17040009f000000c,0x0002ffffffff000c\n"
".quad 0x17040009f000000a,0x0001ffffffff000c,0x17040009f0000008,0x0000ffffffff000c\n"
".quad 0x0d040021f0000000,0x00200021018c0008,0x440400005de40000,0x000084001c042800\n"
".quad 0x4000b001dc232c00,0x0000000001e71b0e,0x00009400dc048000,0x4000a0009de42c00\n"
".quad 0xc0047c011c232800,0x00000d215c047000,0x800080209c031800,0x400093f19c432007\n"
".quad 0x000008009c034800,0x00001840dc434801,0x000001211e044800,0x4000fc411c861800\n"
".quad 0x400020001c038010,0x4000b001dc234800,0x000010211c04188e,0x000011211c041c00\n"
".quad 0x4000d0411c001800,0x0000fc411c005800,0xd0dfc0411c00081e,0x000011211c04080e\n"
".quad 0x000000211c051406,0x400020209c039400,0x00000ff0dc434801,0xfffe400001e74800\n"
".quad 0x000000001de74003,0x000014215c048000,0x000010211c041c00,0x000018219c041c00\n"
".quad 0x000020221c041c00,0x00001c21dc041c00,0x000014415c031c00,0x000028229c044800\n"
".quad 0x000024211c041c00,0x00002071dc031c00,0x000014619c034800,0x000030201c044800\n"
".quad 0x00002c215c041c00,0x000028411c031c00,0x00001c619c034800,0x000000501c034800\n"
".quad 0x000018411c034800,0x000010001c034800,0x000000a01e844800,0x000001211ec41c00\n"
".quad 0x400044411c431c00,0xc00004411c235000,0x000011215f845800,0x000010501c231c00\n"
".quad 0x000000a01e843080,0x000001201e041c00,0x000034001c001800,0x000001201c845800\n"
".quad 0x000000a01e841406,0x0000fc01dc231c00,0x0000600081e7188e,0xc003fc03e0234000\n"
".quad 0x000000202004198e,0xc003fc0120041c00,0x0000fc0101e42002,0x000000001de72800\n"
".quad 0x000010201c049000,0x000001201c041c00,0x00001401dc001800,0x0003fc0101e2220e\n"
".quad 0x0000fc0121e41800,0x000000001de72800,0x00001c201c049000,0x000010211c041c00\n"
".quad 0x000014215c041c00,0x000018219c041c00,0x00002421dc041c00,0x000030221c041c00\n"
".quad 0x000010525c231c00,0x000018731c234000,0x000028215c044000,0x00002461dc031c00\n"
".quad 0x000030825c034800,0x00002c219c044800,0x00001471dd031c00,0x000010925d034800\n"
".quad 0x00001c611c234800,0x000024019c234100,0x000020401d034100,0x000014611d034800\n"
".quad 0x000000a01e844800,0x000010a11e841c00,0x000001201ec41c00,0x000011211ec41c00\n"
".quad 0x000010001c031c00,0x000001201e044800,0x000034001c001800,0x000001201c845800\n"
".quad 0x000000a01e841406,0x0000fc01dc231c00,0x0000600081e7188e,0xc003fc03e0234000\n"
".quad 0x000000202004198e,0xc003fc0120041c00,0x0000fc0101e42002,0x000000001de72800\n"
".quad 0x0000000000009000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0220000000010000\n"
".quad 0x01f0000000d80000,0x0c0438e38e390000,0x0008000000000014,0x00100000000c0000\n"
".quad 0x0204000000140000,0x00000000001b0008,0x000e00080a040000,0x1903001800200000\n"
".quad 0xffff000c17040018,0xf00000140004ffff,0xffff000c17040011,0xf00000100003ffff\n"
".quad 0xffff000c17040011,0xf000000c0002ffff,0xffff000c17040011,0xf00000080001ffff\n"
".quad 0xffff000c17040011,0xf00000000000ffff,0x018000080d040021,0x5de4000000200020\n"
".quad 0x1c04280044040000,0xdc232c0000008406,0x01e71b0e4000b181,0xde03800000000000\n"
".quad 0x1de44801400103ff,0xdde4280040011001,0x9de228004000e000,0xdc43180000002000\n"
".quad 0x1c041a8e0000fc41,0x9ca32c0000009400,0xdce32005b8001030,0x1de45000c0002030\n"
".quad 0xdc0428004000a001,0xdc43180000000124,0x5c03480000000ff0,0x1c23200180008041\n"
".quad 0x5c047000c0047d81,0x1c43080e00001c06,0x1c034800400093f0,0x5c00480100001584\n"
".quad 0xdc005000efe00135,0x5c435000cfe00135,0x9e04480000000044,0x1de4180000006124\n"
".quad 0x1c86280000004805,0x9c0080104000fd40,0x1de45000cfe00125,0x9c86280000005805\n"
".quad 0x1c0080104000fd41,0x5de45000efe00125,0x1de4280000004c01,0xdc86280000005001\n"
".quad 0x1c8680104000fc41,0x1de480104000fd62,0x5c86280000005801,0x9c8680104000fc42\n"
".quad 0x9de480104000fd42,0x9c86280000005005,0xdc8680104000fd63,0x9de480104000fd22\n"
".quad 0xdc86280000004805,0x1ca580104000fd63,0x5de4840000000021,0x5c0428004000d003\n"
".quad 0x9c041c0000000021,0xdc041c0000001821,0x1c041c0000001c21,0x5c041c0000002023\n"
".quad 0x9c861c0000002422,0x1c04140040000044,0x9c041c0000002821,0x1c041c0000003822\n"
".quad 0xdc041c0000002c22,0x00071c0000003c22,0x1de7780000002001,0xdc034803fff90120\n"
".quad 0x1c041a8e0000fd91,0x21e71c0000001021,0x1de440000000a000,0x5de2280040010000\n"
".quad 0x1c86190c58000001,0x0007140040000000,0x1de7780000002001,0x1c054803fff80000\n"
".quad 0x1c03940000000101,0x1c03480040002186,0xdc23480140002104,0x5c43188e4000b181\n"
".quad 0x01e74800000047f4,0x1de74003fffa2000,0x5c04800000000000,0x1c041c0000001421\n"
".quad 0x9c041c0000001021,0x1c041c0000001821,0xdc041c0000002022,0x5c031c0000001c21\n"
".quad 0x9c04480000001441,0x1c041c0000002822,0xdc031c0000002421,0x9c03480000002071\n"
".quad 0x1c04480000001461,0x5c041c0000003020,0x1c031c0000002c21,0x9c03480000002841\n"
".quad 0x1c03480000001c61,0x1c03480000000050,0x1c03480000001841,0x1e84480000001000\n"
".quad 0x1ec41c00000000a0,0x1c431c0000000121,0x1c23500040004441,0x5f845800c0000441\n"
".quad 0x1c231c0000001121,0x1e84308000001050,0x1e041c00000000a0,0x1c00180000000120\n"
".quad 0x1c84580000003400,0x1e84140600000120,0xdc231c00000000a0,0x81e7188e0000fc01\n"
".quad 0xe023400000006000,0x2004198ec003fc03,0x20041c0000000020,0x01e42002c003fc01\n"
".quad 0x1de728000000fc01,0x1c04900000000000,0x1c041c0000001020,0xdc00180000000120\n"
".quad 0x01e2220e00001401,0x21e418000003fc01,0x1de728000000fc01,0x1c04900000000000\n"
".quad 0x1c041c0000001c20,0x5c041c0000001021,0x9c041c0000001421,0xdc041c0000001821\n"
".quad 0x1c041c0000002421,0x5c231c0000003022,0x1c23400000001052,0x5c04400000001873\n"
".quad 0xdc031c0000002821,0x5c03480000002461,0x9c04480000003082,0xdd031c0000002c21\n"
".quad 0x5d03480000001471,0x1c23480000001092,0x9c23410000001c61,0x1d03410000002401\n"
".quad 0x1d03480000002040,0x1e84480000001461,0x1e841c00000000a0,0x1ec41c00000010a1\n"
".quad 0x1ec41c0000000120,0x1c031c0000001121,0x1e04480000001000,0x1c00180000000120\n"
".quad 0x1c84580000003400,0x1e84140600000120,0xdc231c00000000a0,0x81e7188e0000fc01\n"
".quad 0xe023400000006000,0x2004198ec003fc03,0x20041c0000000020,0x01e42002c003fc01\n"
".quad 0x1de728000000fc01,0x0000900000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0001000000000000,0x0238000003800000\n"
".quad 0x8e39000003500000,0x0000001c0c0438e3,0x000c000000080000,0x0014000000100000\n"
".quad 0x0020000000180000,0x001b000802040000,0x0a04000000000000,0x0020000000120008\n"
".quad 0x1704002819030028,0x0006ffffffff000c,0x17040021f0000020,0x0005ffffffff000c\n"
".quad 0x17040011f0000018,0x0004ffffffff000c,0x17040011f0000014,0x0003ffffffff000c\n"
".quad 0x17040011f0000010,0x0002ffffffff000c,0x17040011f000000c,0x0001ffffffff000c\n"
".quad 0x17040011f0000008,0x0000ffffffff000c,0x0d040021f0000000,0x0020002001800008\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0018000000000000\n"
".quad 0x0001000000000000,0x0014000000220000,0x0001000000000000,0x0004000000210000\n"
".quad 0x0001000000000000,0x0000000000200000,0x0001000000000000,0x00100000001f0000\n"
".quad 0x0001000000000000,0x00080000001e0000,0x0001000000000000,0x000c0000001d0000\n"
".quad 0x0001000000000000,0x00000000001c0000,0x0004000000000000,0x0008000000000000\n"
".quad 0x000c000000000000,0x0704000000000000,0xffff0000001b0010,0xffffffffffffffff\n"
".quad 0x001800081204ffff,0x1104000000000000,0x0000000000180008,0x0017000812040000\n"
".quad 0x1104000000000000,0x0000000000170008,0x0016000812040000,0x1104000000000000\n"
".quad 0x0000000000160008,0x001a000812040000,0x1104000000000000,0x00000000001a0008\n"
".quad 0x0018000812040000,0x1104000000000000,0x0000000000180008,0x0017000812040000\n"
".quad 0x1104000000000000,0x0000000000170008,0x0016000812040000,0x1104000000000000\n"
".quad 0x0000000000160008,0x0019000812040000,0x1104000000000000,0x0000000000190008\n"
".quad 0x0018000812040000,0x1104000000000000,0x0000000000180008,0x0017000812040000\n"
".quad 0x1104000000000000,0x0000000000170008,0x0016000812040000,0x1104000000000000\n"
".quad 0x0000000000160008,0x0015000812040000,0x1104000000000000,0x0000000000150008\n"
".quad 0x0000000600000000,0x000023a400000005,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000015000000000,0x0000015000000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x00000c1600001a05,0x0000000000000000,0x0000000000000000,0x00000bfc00000000\n"
".quad 0x00000bfc00000000,0x0000000400000000,0x6000000000000000,0x0000181200001905\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000040c00000000,0x0000040c00000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x00001c1e00001505,0x0000000000000000\n"
".quad 0x0000000000000000,0x000005a400000000,0x000005a400000000,0x0000000400000000\n"
".quad 0x0000000100000000,0x000021c200000005,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000008c00000000,0x0000008c00000000,0x0000000400000000,0x0000000100000000\n"
".quad 0x0000224e00000006,0x0000000000000000,0x0000000000000000,0x0000002000000000\n"
".quad 0x0000004800000000,0x0000000400000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_20$[1183];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_20",(char*)__deviceText_$compute_20$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_20", (char*)__deviceText_$sm_20$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_20$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"f0d3622607bf0dc0",(char*)"/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x30393bf2,&__elfEntries1};
# 3 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;unsigned short __par1;short __par2;short __par3;short __par4;short __par5;float __par6;int __par7;pointFunction_t __par8;int __dummy_field;};
struct __T21 {Pixel *__par0;unsigned __par1;int __par2;int __par3;float __par4;int __dummy_field;};
struct __T22 {Pixel *__par0;unsigned __par1;int __par2;int __par3;float __par4;int __par5;pointFunction_t __par6;int __dummy_field;};
extern void __device_stub__Z11SobelSharedP6uchar4tssssfiPFhhfE(uchar4 *, unsigned short, short, short, short, short, float, int, pointFunction_t);
extern void __device_stub__Z14SobelCopyImagePhjiif(Pixel *, unsigned, int, int, float);
extern void __device_stub__Z8SobelTexPhjiifiPFhhfE(Pixel *, unsigned, int, int, float, int, pointFunction_t);
static void __sti____cudaRegisterAll_59_tmpxft_00007816_00000000_4_FunctionPointers_kernels_cpp1_ii_tex(void) __attribute__((__constructor__));
void __device_stub__Z11SobelSharedP6uchar4tssssfiPFhhfE(uchar4 *__par0, unsigned short __par1, short __par2, short __par3, short __par4, short __par5, float __par6, int __par7, pointFunction_t __par8){ struct __T20 *__T23 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T23->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T23->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T23->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T23->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T23->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T23->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T23->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T23->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T23->__par8) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, unsigned short, short, short, short, short, float, int, pointFunction_t))SobelShared)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, unsigned short, short, short, short, short, float, int, pointFunction_t))SobelShared))); };}
void SobelShared( uchar4 *__cuda_0,unsigned short __cuda_1,short __cuda_2,short __cuda_3,short __cuda_4,short __cuda_5,float __cuda_6,int __cuda_7,pointFunction_t __cuda_8)
# 137 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{__device_stub__Z11SobelSharedP6uchar4tssssfiPFhhfE( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8);
# 232 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c"
void __device_stub__Z14SobelCopyImagePhjiif( Pixel *__par0, unsigned __par1, int __par2, int __par3, float __par4) { struct __T21 *__T24 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(Pixel *, unsigned, int, int, float))SobelCopyImage)); (void)cudaLaunch(((char *)((void ( *)(Pixel *, unsigned, int, int, float))SobelCopyImage))); }; }
void SobelCopyImage( Pixel *__cuda_0,unsigned __cuda_1,int __cuda_2,int __cuda_3,float __cuda_4)
# 237 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{__device_stub__Z14SobelCopyImagePhjiif( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);
# 243 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c"
void __device_stub__Z8SobelTexPhjiifiPFhhfE( Pixel *__par0, unsigned __par1, int __par2, int __par3, float __par4, int __par5, pointFunction_t __par6) { struct __T22 *__T25 = 0;
if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T25->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T25->__par6) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(Pixel *, unsigned, int, int, float, int, pointFunction_t))SobelTex)); (void)cudaLaunch(((char *)((void ( *)(Pixel *, unsigned, int, int, float, int, pointFunction_t))SobelTex))); }; }
void SobelTex( Pixel *__cuda_0,unsigned __cuda_1,int __cuda_2,int __cuda_3,float __cuda_4,int __cuda_5,pointFunction_t __cuda_6)
# 251 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
{__device_stub__Z8SobelTexPhjiifiPFhhfE( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 273 "/home/andrew/repositories/gpuocelot/tests/cuda3.2/tests/FunctionPointers/FunctionPointers_kernels.cu"
}
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c"
static void __sti____cudaRegisterAll_59_tmpxft_00007816_00000000_4_FunctionPointers_kernels_cpp1_ii_tex(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(Pixel *, unsigned, int, int, float, int, pointFunction_t))SobelTex), (char*)"_Z8SobelTexPhjiifiPFhhfE", "_Z8SobelTexPhjiifiPFhhfE", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(Pixel *, unsigned, int, int, float))SobelCopyImage), (char*)"_Z14SobelCopyImagePhjiif", "_Z14SobelCopyImagePhjiif", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, unsigned short, short, short, short, short, float, int, pointFunction_t))SobelShared), (char*)"_Z11SobelSharedP6uchar4tssssfiPFhhfE", "_Z11SobelSharedP6uchar4tssssfiPFhhfE", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&tex, (const void**)"tex", "tex", 2, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&blockFunction, (char*)"blockFunction", "blockFunction", 0, 8, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&varFunction, (char*)"varFunction", "varFunction", 0, 8, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&blockFunction_table, (char*)"blockFunction_table", "blockFunction_table", 0, 16, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&pointFunction_table, (char*)"pointFunction_table", "pointFunction_table", 0, 16, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&pComputeSobel, (char*)"pComputeSobel", "pComputeSobel", 0, 8, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&pComputeBox, (char*)"pComputeBox", "pComputeBox", 0, 8, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&pComputeThreshold, (char*)"pComputeThreshold", "pComputeThreshold", 0, 8, 0, 0); }
# 1 "/tmp/tmpxft_00007816_00000000-1_FunctionPointers_kernels.cudafe1.stub.c" 2

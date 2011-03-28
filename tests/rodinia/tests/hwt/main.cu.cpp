# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
# 60 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 56 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/device_types.h" 1 3
# 60 "/usr/local/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 57 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/driver_types.h" 1 3
# 123 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{





  cudaSuccess = 0,





  cudaErrorMissingConfiguration = 1,





  cudaErrorMemoryAllocation = 2,





  cudaErrorInitializationError = 3,
# 158 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchFailure = 4,
# 167 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorPriorLaunchFailure = 5,
# 177 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchTimeout = 6,
# 186 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchOutOfResources = 7,





  cudaErrorInvalidDeviceFunction = 8,
# 201 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 282 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorAddressOfConstant = 22,
# 291 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureFetchFailed = 23,
# 300 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureNotBound = 24,
# 309 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorSynchronizationError = 25,





  cudaErrorInvalidFilterSetting = 26,





  cudaErrorInvalidNormSetting = 27,







  cudaErrorMixedDeviceExecution = 28,







  cudaErrorCudartUnloading = 29,




  cudaErrorUnknown = 30,





  cudaErrorNotYetImplemented = 31,
# 357 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorMemoryValueTooLarge = 32,






  cudaErrorInvalidResourceHandle = 33,







  cudaErrorNotReady = 34,






  cudaErrorInsufficientDriver = 35,
# 392 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 453 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorDevicesUnavailable = 46,




  cudaErrorInvalidKernelImage = 47,







  cudaErrorNoKernelImageForDevice = 48,
# 479 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorIncompatibleDriverContext = 49,






  cudaErrorPeerAccessAlreadyEnabled = 50,
# 495 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorPeerAccessNotEnabled = 51,





  cudaErrorPeerMemoryAlreadyRegistered = 52,





  cudaErrorPeerMemoryNotRegistered = 53,





  cudaErrorDeviceAlreadyInUse = 54,







  cudaErrorProfilerDisabled = 55,






  cudaErrorProfilerNotInitialized = 56,






  cudaErrorProfilerAlreadyStarted = 57,





   cudaErrorProfilerAlreadyStopped = 58,




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





enum cudaMemoryType
{
  cudaMemoryTypeHost = 1,
  cudaMemoryTypeDevice = 2,
};





enum cudaMemcpyKind
{
  cudaMemcpyHostToHost = 0,
  cudaMemcpyHostToDevice = 1,
  cudaMemcpyDeviceToHost = 2,
  cudaMemcpyDeviceToDevice = 3,
  cudaMemcpyDefault = 4
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





struct cudaMemcpy3DPeerParms
{
  struct cudaArray *srcArray;
  struct cudaPos srcPos;
  struct cudaPitchedPtr srcPtr;
  int srcDevice;

  struct cudaArray *dstArray;
  struct cudaPos dstPos;
  struct cudaPitchedPtr dstPtr;
  int dstDevice;

  struct cudaExtent extent;
};





struct cudaGraphicsResource;





enum cudaGraphicsRegisterFlags
{
  cudaGraphicsRegisterFlagsNone = 0,
  cudaGraphicsRegisterFlagsReadOnly = 1,
  cudaGraphicsRegisterFlagsWriteDiscard = 2,
  cudaGraphicsRegisterFlagsSurfaceLoadStore = 4
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





struct cudaPointerAttributes
{




    enum cudaMemoryType memoryType;
# 746 "/usr/local/cuda/bin/../include/driver_types.h" 3
    int device;





    void *devicePointer;





    void *hostPointer;
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
  cudaComputeModeProhibited = 2,
  cudaComputeModeExclusiveProcess = 3
};





enum cudaLimit
{
    cudaLimitStackSize = 0x00,
    cudaLimitPrintfFifoSize = 0x01,
    cudaLimitMallocHeapSize = 0x02
};





enum cudaOutputMode
{
    cudaKeyValuePair = 0x00,
    cudaCSV = 0x01
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
  int maxTexture1DLayered[2];
  int maxTexture2DLayered[3];
  size_t surfaceAlignment;
  int concurrentKernels;
  int ECCEnabled;
  int pciBusID;
  int pciDeviceID;
  int tccDriver;
  int asyncEngineCount;
  int unifiedAddressing;
};
# 944 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct cudaGraphicsResource *cudaGraphicsResource_t;





typedef struct CUuuid_st cudaUUID_t;





typedef enum cudaOutputMode cudaOutputMode_t;
# 58 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_types.h" 1 3
# 77 "/usr/local/cuda/bin/../include/surface_types.h" 3
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
# 59 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 83 "/usr/local/cuda/bin/../include/texture_types.h" 3
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



  int sRGB;
  int __cudaReserved[15];
};
# 60 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 59 "/usr/local/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 60 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 60 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 60 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 61 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 92 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 246 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 390 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 493 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 60 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 70 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 2 3
# 123 "/usr/local/cuda/bin/../include/driver_types.h"
# 559 "/usr/local/cuda/bin/../include/driver_types.h"
# 571 "/usr/local/cuda/bin/../include/driver_types.h"
# 584 "/usr/local/cuda/bin/../include/driver_types.h"
# 590 "/usr/local/cuda/bin/../include/driver_types.h"
# 600 "/usr/local/cuda/bin/../include/driver_types.h"
# 614 "/usr/local/cuda/bin/../include/driver_types.h"
# 627 "/usr/local/cuda/bin/../include/driver_types.h"
# 639 "/usr/local/cuda/bin/../include/driver_types.h"
# 650 "/usr/local/cuda/bin/../include/driver_types.h"
# 668 "/usr/local/cuda/bin/../include/driver_types.h"
# 687 "/usr/local/cuda/bin/../include/driver_types.h"
# 693 "/usr/local/cuda/bin/../include/driver_types.h"
# 705 "/usr/local/cuda/bin/../include/driver_types.h"
# 716 "/usr/local/cuda/bin/../include/driver_types.h"
# 729 "/usr/local/cuda/bin/../include/driver_types.h"
# 765 "/usr/local/cuda/bin/../include/driver_types.h"
# 816 "/usr/local/cuda/bin/../include/driver_types.h"
# 827 "/usr/local/cuda/bin/../include/driver_types.h"
# 839 "/usr/local/cuda/bin/../include/driver_types.h"
# 850 "/usr/local/cuda/bin/../include/driver_types.h"
# 860 "/usr/local/cuda/bin/../include/driver_types.h"
# 944 "/usr/local/cuda/bin/../include/driver_types.h"
# 950 "/usr/local/cuda/bin/../include/driver_types.h"
# 956 "/usr/local/cuda/bin/../include/driver_types.h"
# 962 "/usr/local/cuda/bin/../include/driver_types.h"
# 968 "/usr/local/cuda/bin/../include/driver_types.h"
# 974 "/usr/local/cuda/bin/../include/driver_types.h"
# 77 "/usr/local/cuda/bin/../include/surface_types.h"
# 88 "/usr/local/cuda/bin/../include/surface_types.h"
# 98 "/usr/local/cuda/bin/../include/surface_types.h"
# 83 "/usr/local/cuda/bin/../include/texture_types.h"
# 95 "/usr/local/cuda/bin/../include/texture_types.h"
# 105 "/usr/local/cuda/bin/../include/texture_types.h"
# 115 "/usr/local/cuda/bin/../include/texture_types.h"
# 92 "/usr/local/cuda/bin/../include/vector_types.h"
# 98 "/usr/local/cuda/bin/../include/vector_types.h"
# 104 "/usr/local/cuda/bin/../include/vector_types.h"
# 110 "/usr/local/cuda/bin/../include/vector_types.h"
# 116 "/usr/local/cuda/bin/../include/vector_types.h"
# 122 "/usr/local/cuda/bin/../include/vector_types.h"
# 128 "/usr/local/cuda/bin/../include/vector_types.h"
# 134 "/usr/local/cuda/bin/../include/vector_types.h"
# 140 "/usr/local/cuda/bin/../include/vector_types.h"
# 146 "/usr/local/cuda/bin/../include/vector_types.h"
# 152 "/usr/local/cuda/bin/../include/vector_types.h"
# 158 "/usr/local/cuda/bin/../include/vector_types.h"
# 164 "/usr/local/cuda/bin/../include/vector_types.h"
# 170 "/usr/local/cuda/bin/../include/vector_types.h"
# 176 "/usr/local/cuda/bin/../include/vector_types.h"
# 179 "/usr/local/cuda/bin/../include/vector_types.h"
# 182 "/usr/local/cuda/bin/../include/vector_types.h"
# 188 "/usr/local/cuda/bin/../include/vector_types.h"
# 194 "/usr/local/cuda/bin/../include/vector_types.h"
# 197 "/usr/local/cuda/bin/../include/vector_types.h"
# 200 "/usr/local/cuda/bin/../include/vector_types.h"
# 206 "/usr/local/cuda/bin/../include/vector_types.h"
# 212 "/usr/local/cuda/bin/../include/vector_types.h"
# 218 "/usr/local/cuda/bin/../include/vector_types.h"
# 224 "/usr/local/cuda/bin/../include/vector_types.h"
# 230 "/usr/local/cuda/bin/../include/vector_types.h"
# 246 "/usr/local/cuda/bin/../include/vector_types.h"
# 252 "/usr/local/cuda/bin/../include/vector_types.h"
# 260 "/usr/local/cuda/bin/../include/vector_types.h"
# 266 "/usr/local/cuda/bin/../include/vector_types.h"
# 272 "/usr/local/cuda/bin/../include/vector_types.h"
# 278 "/usr/local/cuda/bin/../include/vector_types.h"
# 284 "/usr/local/cuda/bin/../include/vector_types.h"
# 290 "/usr/local/cuda/bin/../include/vector_types.h"
# 293 "/usr/local/cuda/bin/../include/vector_types.h"
# 299 "/usr/local/cuda/bin/../include/vector_types.h"
# 305 "/usr/local/cuda/bin/../include/vector_types.h"
# 311 "/usr/local/cuda/bin/../include/vector_types.h"
# 317 "/usr/local/cuda/bin/../include/vector_types.h"
# 323 "/usr/local/cuda/bin/../include/vector_types.h"
# 329 "/usr/local/cuda/bin/../include/vector_types.h"
# 335 "/usr/local/cuda/bin/../include/vector_types.h"
# 341 "/usr/local/cuda/bin/../include/vector_types.h"
# 347 "/usr/local/cuda/bin/../include/vector_types.h"
# 353 "/usr/local/cuda/bin/../include/vector_types.h"
# 359 "/usr/local/cuda/bin/../include/vector_types.h"
# 365 "/usr/local/cuda/bin/../include/vector_types.h"
# 371 "/usr/local/cuda/bin/../include/vector_types.h"
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
# 462 "/usr/local/cuda/bin/../include/vector_types.h"
# 464 "/usr/local/cuda/bin/../include/vector_types.h"
# 466 "/usr/local/cuda/bin/../include/vector_types.h"
# 468 "/usr/local/cuda/bin/../include/vector_types.h"
# 470 "/usr/local/cuda/bin/../include/vector_types.h"
# 472 "/usr/local/cuda/bin/../include/vector_types.h"
# 474 "/usr/local/cuda/bin/../include/vector_types.h"
# 476 "/usr/local/cuda/bin/../include/vector_types.h"
# 478 "/usr/local/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda/bin/../include/vector_types.h"
# 482 "/usr/local/cuda/bin/../include/vector_types.h"
# 484 "/usr/local/cuda/bin/../include/vector_types.h"
# 493 "/usr/local/cuda/bin/../include/vector_types.h"
# 504 "/usr/local/cuda/bin/../include/vector_types.h"
# 134 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceReset();
# 151 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSynchronize();
# 203 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSetLimit(cudaLimit , size_t );
# 227 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetLimit(size_t * , cudaLimit );
# 257 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * );
# 298 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache );
# 332 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 356 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 415 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit , size_t );
# 446 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t * , cudaLimit );
# 481 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * );
# 527 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetCacheConfig(cudaFuncCache );
# 581 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 624 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 638 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t );
# 667 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int * );
# 812 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp * , int );
# 831 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int * , const cudaDeviceProp * );
# 864 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int );
# 881 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int * );
# 910 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int * , int );
# 970 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(unsigned );
# 996 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t * );
# 1017 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t );
# 1053 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t , cudaEvent_t , unsigned );
# 1072 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t );
# 1090 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t );
# 1122 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t * );
# 1153 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t * , unsigned );
# 1186 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t , cudaStream_t = 0);
# 1215 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t );
# 1247 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t );
# 1272 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t );
# 1313 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float * , cudaEvent_t , cudaEvent_t );
# 1352 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3 , dim3 , size_t = (0), cudaStream_t = 0);
# 1379 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void * , size_t , size_t );
# 1425 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char * , cudaFuncCache );
# 1460 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char * );
# 1493 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * , const char * );
# 1515 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double * );
# 1537 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double * );
# 1569 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void ** , size_t );
# 1598 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void ** , size_t );
# 1637 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void ** , size_t * , size_t , size_t );
# 1676 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray ** , const cudaChannelFormatDesc * , size_t , size_t = (0), unsigned = (0));
# 1700 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void * );
# 1720 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void * );
# 1742 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray * );
# 1801 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void ** , size_t , unsigned );
# 1857 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostRegister(void * , size_t , unsigned );
# 1876 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostUnregister(void * );
# 1903 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void ** , void * , unsigned );
# 1922 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned * , void * );
# 1957 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr * , cudaExtent );
# 2018 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray ** , const cudaChannelFormatDesc * , cudaExtent , unsigned = (0));
# 2115 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms * );
# 2142 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * );
# 2247 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * , cudaStream_t = 0);
# 2268 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * , cudaStream_t = 0);
# 2287 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t * , size_t * );
# 2320 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void * , const void * , size_t , cudaMemcpyKind );
# 2351 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyPeer(void * , int , const void * , int , size_t );
# 2384 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray * , size_t , size_t , const void * , size_t , cudaMemcpyKind );
# 2417 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void * , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind );
# 2452 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray * , size_t , size_t , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2494 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void * , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind );
# 2535 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray * , size_t , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind );
# 2576 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void * , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind );
# 2615 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray * , size_t , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2650 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char * , const void * , size_t , size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 2684 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void * , const char * , size_t , size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 2727 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void * , const void * , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 2757 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyPeerAsync(void * , int , const void * , int , size_t , cudaStream_t = 0);
# 2799 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray * , size_t , size_t , const void * , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 2841 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void * , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 2892 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void * , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 2942 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray * , size_t , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 2992 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void * , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3036 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char * , const void * , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3079 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void * , const char * , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3101 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void * , int , size_t );
# 3127 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void * , size_t , int , size_t , size_t );
# 3166 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr , int , cudaExtent );
# 3193 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemsetAsync(void * , int , size_t , cudaStream_t = 0);
# 3225 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2DAsync(void * , size_t , int , size_t , size_t , cudaStream_t = 0);
# 3270 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3DAsync(cudaPitchedPtr , int , cudaExtent , cudaStream_t = 0);
# 3297 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void ** , const char * );
# 3320 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t * , const char * );
# 3466 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * , void * );
# 3503 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceCanAccessPeer(int * , int , int );
# 3547 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceEnablePeerAccess(int , unsigned );
# 3575 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceDisablePeerAccess(int );
# 3637 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeerRegister(void * , int , unsigned );
# 3669 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeerUnregister(void * , int );
# 3715 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeerGetDevicePointer(void ** , void * , int , unsigned );
# 3761 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t );
# 3793 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t , unsigned );
# 3828 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int , cudaGraphicsResource_t * , cudaStream_t = 0);
# 3859 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int , cudaGraphicsResource_t * , cudaStream_t = 0);
# 3888 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void ** , size_t * , cudaGraphicsResource_t );
# 3922 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray ** , cudaGraphicsResource_t , unsigned , unsigned );
# 3955 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * , const cudaArray * );
# 3990 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int , int , int , int , cudaChannelFormatKind );
# 4032 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t * , const textureReference * , const void * , const cudaChannelFormatDesc * , size_t = (((2147483647) * 2U) + 1U));
# 4075 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t * , const textureReference * , const void * , const cudaChannelFormatDesc * , size_t , size_t , size_t );
# 4103 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference * , const cudaArray * , const cudaChannelFormatDesc * );
# 4124 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference * );
# 4149 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t * , const textureReference * );
# 4173 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference ** , const char * );
# 4206 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference * , const cudaArray * , const cudaChannelFormatDesc * );
# 4224 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference ** , const char * );
# 4251 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int * );
# 4268 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int * );
# 4273 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void ** , const cudaUUID_t * );
# 107 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 108 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 109 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 110 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 113 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 120 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 127 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 130 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 131 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 133 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 134 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 135 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 137 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 138 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 140 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 141 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 142 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 147 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 149 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 152 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 159 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 166 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 173 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 180 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 187 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 194 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 197 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 201 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 204 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 208 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 215 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 222 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 229 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 236 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 243 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 250 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 253 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 257 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 260 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 264 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 271 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 278 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 285 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 292 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 299 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 305 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 306 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 307 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 309 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 310 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 312 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 313 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 314 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 316 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 317 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 380 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 387 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 393 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 394 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 395 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 397 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 398 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 400 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 401 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 402 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 404 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 405 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 79 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 80 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 81 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 83 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 84 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 85 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 86 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 88 "/usr/local/cuda/bin/../include/driver_functions.h"
return s;
# 89 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 106 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 107 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 108 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 110 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 111 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 112 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 114 "/usr/local/cuda/bin/../include/driver_functions.h"
return p;
# 115 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 132 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 133 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 134 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 136 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 137 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 138 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 140 "/usr/local/cuda/bin/../include/driver_functions.h"
return e;
# 141 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 69 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 70 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 71 "/usr/local/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 72 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 74 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 75 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 76 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 77 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 79 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 80 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 81 "/usr/local/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 82 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 84 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 85 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 86 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 87 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 89 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 90 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 91 "/usr/local/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 92 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 94 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 95 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 96 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 97 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 99 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 100 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 101 "/usr/local/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 102 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 104 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 105 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 106 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 107 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 109 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 110 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 111 "/usr/local/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 112 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 114 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 115 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 116 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 117 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 119 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 120 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 121 "/usr/local/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 122 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 124 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 125 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 126 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 127 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 129 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 130 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 131 "/usr/local/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 132 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 134 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 135 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 136 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 137 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 139 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 140 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 141 "/usr/local/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 142 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 144 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 145 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 146 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 147 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 149 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 150 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 151 "/usr/local/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 152 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 154 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 155 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 156 "/usr/local/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 157 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 159 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 160 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 161 "/usr/local/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 162 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 164 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 165 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 166 "/usr/local/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 167 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 169 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 170 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 171 "/usr/local/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 172 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 174 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 175 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 176 "/usr/local/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 177 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 179 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 180 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 181 "/usr/local/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 182 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 184 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 185 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 186 "/usr/local/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 187 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 189 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 190 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 191 "/usr/local/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 192 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 194 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 195 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 196 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 197 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 199 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 200 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 201 "/usr/local/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 202 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 204 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 205 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 206 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 207 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 209 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 210 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 211 "/usr/local/cuda/bin/../include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 212 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 214 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 215 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 216 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 217 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 219 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 220 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 221 "/usr/local/cuda/bin/../include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 222 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 224 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 225 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 226 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 227 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 229 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 230 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 231 "/usr/local/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 232 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 234 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 235 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 236 "/usr/local/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 237 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 239 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 240 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 241 "/usr/local/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 242 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 244 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 245 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 246 "/usr/local/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 247 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 249 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 250 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 251 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 252 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 254 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 255 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 256 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 257 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 259 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 260 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 261 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 262 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 264 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 265 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 266 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 267 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 269 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 270 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 271 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 272 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 274 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 275 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 276 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 277 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 279 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 280 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 281 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 282 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 284 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 285 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 286 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 287 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 289 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 290 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 291 "/usr/local/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 292 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 294 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 295 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 296 "/usr/local/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 297 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 299 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 300 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 301 "/usr/local/cuda/bin/../include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 302 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 304 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 305 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 306 "/usr/local/cuda/bin/../include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 307 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 44 "/usr/include/string.h" 3
extern "C" void *memcpy(void *__restrict__ , const void *__restrict__ , size_t ) throw()
# 46 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 49 "/usr/include/string.h" 3
extern "C" void *memmove(void * , const void * , size_t ) throw()
# 50 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 57 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__ , const void *__restrict__ , int , size_t ) throw()
# 59 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 65 "/usr/include/string.h" 3
extern "C" void *memset(void * , int , size_t ) throw() __attribute((__nonnull__(1)));
# 68 "/usr/include/string.h" 3
extern "C" int memcmp(const void * , const void * , size_t ) throw()
# 69 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 75 "/usr/include/string.h" 3
extern void *memchr(void * , int , size_t ) throw() __asm__("memchr")
# 76 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 77 "/usr/include/string.h" 3
extern const void *memchr(const void * , int , size_t ) throw() __asm__("memchr")
# 78 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 104 "/usr/include/string.h" 3
void *rawmemchr(void * , int ) throw() __asm__("rawmemchr")
# 105 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 106 "/usr/include/string.h" 3
const void *rawmemchr(const void * , int ) throw() __asm__("rawmemchr")
# 107 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 115 "/usr/include/string.h" 3
void *memrchr(void * , int , size_t ) throw() __asm__("memrchr")
# 116 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 117 "/usr/include/string.h" 3
const void *memrchr(const void * , int , size_t ) throw() __asm__("memrchr")
# 118 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 128 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__ , const char *__restrict__ ) throw()
# 129 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 131 "/usr/include/string.h" 3
extern "C" char *strncpy(char *__restrict__ , const char *__restrict__ , size_t ) throw()
# 133 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 136 "/usr/include/string.h" 3
extern "C" char *strcat(char *__restrict__ , const char *__restrict__ ) throw()
# 137 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 139 "/usr/include/string.h" 3
extern "C" char *strncat(char *__restrict__ , const char *__restrict__ , size_t ) throw()
# 140 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 143 "/usr/include/string.h" 3
extern "C" int strcmp(const char * , const char * ) throw()
# 144 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 146 "/usr/include/string.h" 3
extern "C" int strncmp(const char * , const char * , size_t ) throw()
# 147 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 150 "/usr/include/string.h" 3
extern "C" int strcoll(const char * , const char * ) throw()
# 151 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 153 "/usr/include/string.h" 3
extern "C" size_t strxfrm(char *__restrict__ , const char *__restrict__ , size_t ) throw()
# 155 "/usr/include/string.h" 3
 __attribute((__nonnull__(2)));
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
extern "C" int strcoll_l(const char * , const char * , __locale_t ) throw()
# 166 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3)));
# 168 "/usr/include/string.h" 3
extern "C" size_t strxfrm_l(char * , const char * , size_t , __locale_t ) throw()
# 169 "/usr/include/string.h" 3
 __attribute((__nonnull__(2, 4)));
# 175 "/usr/include/string.h" 3
extern "C" char *strdup(const char * ) throw()
# 176 "/usr/include/string.h" 3
 __attribute((__malloc__)) __attribute((__nonnull__(1)));
# 183 "/usr/include/string.h" 3
extern "C" char *strndup(const char * , size_t ) throw()
# 184 "/usr/include/string.h" 3
 __attribute((__malloc__)) __attribute((__nonnull__(1)));
# 215 "/usr/include/string.h" 3
extern char *strchr(char * , int ) throw() __asm__("strchr")
# 216 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 217 "/usr/include/string.h" 3
extern const char *strchr(const char * , int ) throw() __asm__("strchr")
# 218 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 242 "/usr/include/string.h" 3
extern char *strrchr(char * , int ) throw() __asm__("strrchr")
# 243 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 244 "/usr/include/string.h" 3
extern const char *strrchr(const char * , int ) throw() __asm__("strrchr")
# 245 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 271 "/usr/include/string.h" 3
char *strchrnul(char * , int ) throw() __asm__("strchrnul")
# 272 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 273 "/usr/include/string.h" 3
const char *strchrnul(const char * , int ) throw() __asm__("strchrnul")
# 274 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 284 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char * , const char * ) throw()
# 285 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 288 "/usr/include/string.h" 3
extern "C" size_t strspn(const char * , const char * ) throw()
# 289 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 294 "/usr/include/string.h" 3
extern char *strpbrk(char * , const char * ) throw() __asm__("strpbrk")
# 295 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 296 "/usr/include/string.h" 3
extern const char *strpbrk(const char * , const char * ) throw() __asm__("strpbrk")
# 297 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 321 "/usr/include/string.h" 3
extern char *strstr(char * , const char * ) throw() __asm__("strstr")
# 322 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 323 "/usr/include/string.h" 3
extern const char *strstr(const char * , const char * ) throw() __asm__("strstr")
# 325 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 348 "/usr/include/string.h" 3
extern "C" char *strtok(char *__restrict__ , const char *__restrict__ ) throw()
# 349 "/usr/include/string.h" 3
 __attribute((__nonnull__(2)));
# 354 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__ , const char *__restrict__ , char **__restrict__ ) throw()
# 357 "/usr/include/string.h" 3
 __attribute((__nonnull__(2, 3)));
# 359 "/usr/include/string.h" 3
extern "C" char *strtok_r(char *__restrict__ , const char *__restrict__ , char **__restrict__ ) throw()
# 361 "/usr/include/string.h" 3
 __attribute((__nonnull__(2, 3)));
# 367 "/usr/include/string.h" 3
char *strcasestr(char * , const char * ) throw() __asm__("strcasestr")
# 368 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 369 "/usr/include/string.h" 3
const char *strcasestr(const char * , const char * ) throw() __asm__("strcasestr")
# 371 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 382 "/usr/include/string.h" 3
extern "C" void *memmem(const void * , size_t , const void * , size_t ) throw()
# 384 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 3)));
# 388 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__ , const void *__restrict__ , size_t ) throw()
# 390 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 391 "/usr/include/string.h" 3
extern "C" void *mempcpy(void *__restrict__ , const void *__restrict__ , size_t ) throw()
# 393 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 399 "/usr/include/string.h" 3
extern "C" size_t strlen(const char * ) throw()
# 400 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 406 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char * , size_t ) throw()
# 407 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 413 "/usr/include/string.h" 3
extern "C" char *strerror(int ) throw();
# 438 "/usr/include/string.h" 3
extern "C" char *strerror_r(int , char * , size_t ) throw()
# 439 "/usr/include/string.h" 3
 __attribute((__nonnull__(2)));
# 445 "/usr/include/string.h" 3
extern "C" char *strerror_l(int , __locale_t ) throw();
# 451 "/usr/include/string.h" 3
extern "C" void __bzero(void * , size_t ) throw() __attribute((__nonnull__(1)));
# 455 "/usr/include/string.h" 3
extern "C" void bcopy(const void * , void * , size_t ) throw()
# 456 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 459 "/usr/include/string.h" 3
extern "C" void bzero(void * , size_t ) throw() __attribute((__nonnull__(1)));
# 462 "/usr/include/string.h" 3
extern "C" int bcmp(const void * , const void * , size_t ) throw()
# 463 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 469 "/usr/include/string.h" 3
extern char *index(char * , int ) throw() __asm__("index")
# 470 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 471 "/usr/include/string.h" 3
extern const char *index(const char * , int ) throw() __asm__("index")
# 472 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 497 "/usr/include/string.h" 3
extern char *rindex(char * , int ) throw() __asm__("rindex")
# 498 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 499 "/usr/include/string.h" 3
extern const char *rindex(const char * , int ) throw() __asm__("rindex")
# 500 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 523 "/usr/include/string.h" 3
extern "C" int ffs(int ) throw() __attribute((const));
# 528 "/usr/include/string.h" 3
extern "C" int ffsl(long ) throw() __attribute((const));
# 530 "/usr/include/string.h" 3
extern "C" int ffsll(long long ) throw()
# 531 "/usr/include/string.h" 3
 __attribute((const));
# 536 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char * , const char * ) throw()
# 537 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 540 "/usr/include/string.h" 3
extern "C" int strncasecmp(const char * , const char * , size_t ) throw()
# 541 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 547 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char * , const char * , __locale_t ) throw()
# 549 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3)));
# 551 "/usr/include/string.h" 3
extern "C" int strncasecmp_l(const char * , const char * , size_t , __locale_t ) throw()
# 553 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 4)));
# 559 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__ , const char *__restrict__ ) throw()
# 561 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 566 "/usr/include/string.h" 3
extern "C" char *strsignal(int ) throw();
# 569 "/usr/include/string.h" 3
extern "C" char *__stpcpy(char *__restrict__ , const char *__restrict__ ) throw()
# 570 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 571 "/usr/include/string.h" 3
extern "C" char *stpcpy(char *__restrict__ , const char *__restrict__ ) throw()
# 572 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 576 "/usr/include/string.h" 3
extern "C" char *__stpncpy(char *__restrict__ , const char *__restrict__ , size_t ) throw()
# 578 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 579 "/usr/include/string.h" 3
extern "C" char *stpncpy(char *__restrict__ , const char *__restrict__ , size_t ) throw()
# 581 "/usr/include/string.h" 3
 __attribute((__nonnull__(1, 2)));
# 586 "/usr/include/string.h" 3
extern "C" int strverscmp(const char * , const char * ) throw()
# 587 "/usr/include/string.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1, 2)));
# 590 "/usr/include/string.h" 3
extern "C" char *strfry(char * ) throw() __attribute((__nonnull__(1)));
# 593 "/usr/include/string.h" 3
extern "C" void *memfrob(void * , size_t ) throw() __attribute((__nonnull__(1)));
# 601 "/usr/include/string.h" 3
char *basename(char * ) throw() __asm__("basename")
# 602 "/usr/include/string.h" 3
 __attribute((__nonnull__(1)));
# 603 "/usr/include/string.h" 3
const char *basename(const char * ) throw() __asm__("basename")
# 604 "/usr/include/string.h" 3
 __attribute((__nonnull__(1)));
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
extern "C" clock_t clock() throw();
# 186 "/usr/include/time.h" 3
extern "C" time_t time(time_t * ) throw();
# 189 "/usr/include/time.h" 3
extern "C" double difftime(time_t , time_t ) throw()
# 190 "/usr/include/time.h" 3
 __attribute((const));
# 193 "/usr/include/time.h" 3
extern "C" time_t mktime(tm * ) throw();
# 199 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__ , size_t , const char *__restrict__ , const tm *__restrict__ ) throw();
# 207 "/usr/include/time.h" 3
extern "C" char *strptime(const char *__restrict__ , const char *__restrict__ , tm * ) throw();
# 217 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__ , size_t , const char *__restrict__ , const tm *__restrict__ , __locale_t ) throw();
# 224 "/usr/include/time.h" 3
extern "C" char *strptime_l(const char *__restrict__ , const char *__restrict__ , tm * , __locale_t ) throw();
# 233 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t * ) throw();
# 237 "/usr/include/time.h" 3
extern "C" tm *localtime(const time_t * ) throw();
# 243 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__ , tm *__restrict__ ) throw();
# 248 "/usr/include/time.h" 3
extern "C" tm *localtime_r(const time_t *__restrict__ , tm *__restrict__ ) throw();
# 255 "/usr/include/time.h" 3
extern "C" char *asctime(const tm * ) throw();
# 258 "/usr/include/time.h" 3
extern "C" char *ctime(const time_t * ) throw();
# 266 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__ , char *__restrict__ ) throw();
# 270 "/usr/include/time.h" 3
extern "C" char *ctime_r(const time_t *__restrict__ , char *__restrict__ ) throw();
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
extern "C" int stime(const time_t * ) throw();
# 313 "/usr/include/time.h" 3
extern "C" time_t timegm(tm * ) throw();
# 316 "/usr/include/time.h" 3
extern "C" time_t timelocal(tm * ) throw();
# 319 "/usr/include/time.h" 3
extern "C" int dysize(int ) throw() __attribute((const));
# 328 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec * , timespec * );
# 333 "/usr/include/time.h" 3
extern "C" int clock_getres(clockid_t , timespec * ) throw();
# 336 "/usr/include/time.h" 3
extern "C" int clock_gettime(clockid_t , timespec * ) throw();
# 339 "/usr/include/time.h" 3
extern "C" int clock_settime(clockid_t , const timespec * ) throw();
# 347 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t , int , const timespec * , timespec * );
# 352 "/usr/include/time.h" 3
extern "C" int clock_getcpuclockid(pid_t , clockid_t * ) throw();
# 357 "/usr/include/time.h" 3
extern "C" int timer_create(clockid_t , sigevent *__restrict__ , timer_t *__restrict__ ) throw();
# 362 "/usr/include/time.h" 3
extern "C" int timer_delete(timer_t ) throw();
# 365 "/usr/include/time.h" 3
extern "C" int timer_settime(timer_t , int , const itimerspec *__restrict__ , itimerspec *__restrict__ ) throw();
# 370 "/usr/include/time.h" 3
extern "C" int timer_gettime(timer_t , itimerspec * ) throw();
# 374 "/usr/include/time.h" 3
extern "C" int timer_getoverrun(timer_t ) throw();
# 390 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 399 "/usr/include/time.h" 3
extern "C" tm *getdate(const char * );
# 413 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__ , tm *__restrict__ );
# 71 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" clock_t clock() throw();
# 73 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" void *memset(void *, int, size_t) throw();
# 75 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" void *memcpy(void *, const void *, size_t) throw();
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
# 32 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" double acos(double ) throw(); extern "C" double __acos(double ) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" double asin(double ) throw(); extern "C" double __asin(double ) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" double atan(double ) throw(); extern "C" double __atan(double ) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" double atan2(double , double ) throw(); extern "C" double __atan2(double , double ) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" double cos(double ) throw(); extern "C" double __cos(double ) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" double sin(double ) throw(); extern "C" double __sin(double ) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" double tan(double ) throw(); extern "C" double __tan(double ) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" double cosh(double ) throw(); extern "C" double __cosh(double ) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" double sinh(double ) throw(); extern "C" double __sinh(double ) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" double tanh(double ) throw(); extern "C" double __tanh(double ) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" void sincos(double , double * , double * ) throw(); extern "C" void __sincos(double , double * , double * ) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" double acosh(double ) throw(); extern "C" double __acosh(double ) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" double asinh(double ) throw(); extern "C" double __asinh(double ) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" double atanh(double ) throw(); extern "C" double __atanh(double ) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" double exp(double ) throw(); extern "C" double __exp(double ) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" double frexp(double , int * ) throw(); extern "C" double __frexp(double , int * ) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" double ldexp(double , int ) throw(); extern "C" double __ldexp(double , int ) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" double log(double ) throw(); extern "C" double __log(double ) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" double log10(double ) throw(); extern "C" double __log10(double ) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" double modf(double , double * ) throw(); extern "C" double __modf(double , double * ) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" double exp10(double ) throw(); extern "C" double __exp10(double ) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" double pow10(double ) throw(); extern "C" double __pow10(double ) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" double expm1(double ) throw(); extern "C" double __expm1(double ) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" double log1p(double ) throw(); extern "C" double __log1p(double ) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" double logb(double ) throw(); extern "C" double __logb(double ) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" double exp2(double ) throw(); extern "C" double __exp2(double ) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" double log2(double ) throw(); extern "C" double __log2(double ) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" double pow(double , double ) throw(); extern "C" double __pow(double , double ) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" double sqrt(double ) throw(); extern "C" double __sqrt(double ) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" double hypot(double , double ) throw(); extern "C" double __hypot(double , double ) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" double cbrt(double ) throw(); extern "C" double __cbrt(double ) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" double ceil(double ) throw() __attribute((const)); extern "C" double __ceil(double ) throw() __attribute((const));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" double fabs(double ) throw() __attribute((const)); extern "C" double __fabs(double ) throw() __attribute((const));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" double floor(double ) throw() __attribute((const)); extern "C" double __floor(double ) throw() __attribute((const));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" double fmod(double , double ) throw(); extern "C" double __fmod(double , double ) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isinf(double ) throw() __attribute((const));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" int __finite(double ) throw() __attribute((const));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double ) throw() __attribute((const));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finite(double ) throw() __attribute((const));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" double drem(double , double ) throw(); extern "C" double __drem(double , double ) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" double significand(double ) throw(); extern "C" double __significand(double ) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" double copysign(double , double ) throw() __attribute((const)); extern "C" double __copysign(double , double ) throw() __attribute((const));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" double nan(const char * ) throw() __attribute((const)); extern "C" double __nan(const char * ) throw() __attribute((const));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isnan(double ) throw() __attribute((const));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnan(double ) throw() __attribute((const));
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
extern "C" double erf(double) throw(); extern "C" double __erf(double) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" double erfc(double) throw(); extern "C" double __erfc(double) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int * ) throw(); extern "C" double __lgamma_r(double, int * ) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" double rint(double ) throw(); extern "C" double __rint(double ) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" double nextafter(double , double ) throw() __attribute((const)); extern "C" double __nextafter(double , double ) throw() __attribute((const));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" double nexttoward(double , long double ) throw() __attribute((const)); extern "C" double __nexttoward(double , long double ) throw() __attribute((const));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" double remainder(double , double ) throw(); extern "C" double __remainder(double , double ) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalbn(double , int ) throw(); extern "C" double __scalbn(double , int ) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" int ilogb(double ) throw(); extern "C" int __ilogb(double ) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalbln(double , long ) throw(); extern "C" double __scalbln(double , long ) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" double nearbyint(double ) throw(); extern "C" double __nearbyint(double ) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" double round(double ) throw() __attribute((const)); extern "C" double __round(double ) throw() __attribute((const));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" double trunc(double ) throw() __attribute((const)); extern "C" double __trunc(double ) throw() __attribute((const));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" double remquo(double , double , int * ) throw(); extern "C" double __remquo(double , double , int * ) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrint(double ) throw(); extern "C" long __lrint(double ) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llrint(double ) throw(); extern "C" long long __llrint(double ) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" long lround(double ) throw(); extern "C" long __lround(double ) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llround(double ) throw(); extern "C" long long __llround(double ) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" double fdim(double , double ) throw(); extern "C" double __fdim(double , double ) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" double fmax(double , double ) throw(); extern "C" double __fmax(double , double ) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" double fmin(double , double ) throw(); extern "C" double __fmin(double , double ) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassify(double ) throw()
# 347 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" int __signbit(double ) throw()
# 351 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" double fma(double , double , double ) throw(); extern "C" double __fma(double , double , double ) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double , double ) throw(); extern "C" double __scalb(double , double ) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" float acosf(float ) throw(); extern "C" float __acosf(float ) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" float asinf(float ) throw(); extern "C" float __asinf(float ) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" float atanf(float ) throw(); extern "C" float __atanf(float ) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" float atan2f(float , float ) throw(); extern "C" float __atan2f(float , float ) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" float cosf(float ) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" float sinf(float ) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" float tanf(float ) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" float coshf(float ) throw(); extern "C" float __coshf(float ) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" float sinhf(float ) throw(); extern "C" float __sinhf(float ) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" float tanhf(float ) throw(); extern "C" float __tanhf(float ) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" void sincosf(float , float * , float * ) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" float acoshf(float ) throw(); extern "C" float __acoshf(float ) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" float asinhf(float ) throw(); extern "C" float __asinhf(float ) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" float atanhf(float ) throw(); extern "C" float __atanhf(float ) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" float expf(float ) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" float frexpf(float , int * ) throw(); extern "C" float __frexpf(float , int * ) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" float ldexpf(float , int ) throw(); extern "C" float __ldexpf(float , int ) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" float logf(float ) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" float log10f(float ) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" float modff(float , float * ) throw(); extern "C" float __modff(float , float * ) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" float exp10f(float ) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" float pow10f(float ) throw(); extern "C" float __pow10f(float ) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" float expm1f(float ) throw(); extern "C" float __expm1f(float ) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" float log1pf(float ) throw(); extern "C" float __log1pf(float ) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" float logbf(float ) throw(); extern "C" float __logbf(float ) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" float exp2f(float ) throw(); extern "C" float __exp2f(float ) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" float log2f(float ) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" float powf(float , float ) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" float sqrtf(float ) throw(); extern "C" float __sqrtf(float ) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" float hypotf(float , float ) throw(); extern "C" float __hypotf(float , float ) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" float cbrtf(float ) throw(); extern "C" float __cbrtf(float ) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" float ceilf(float ) throw() __attribute((const)); extern "C" float __ceilf(float ) throw() __attribute((const));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" float fabsf(float ) throw() __attribute((const)); extern "C" float __fabsf(float ) throw() __attribute((const));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" float floorf(float ) throw() __attribute((const)); extern "C" float __floorf(float ) throw() __attribute((const));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" float fmodf(float , float ) throw(); extern "C" float __fmodf(float , float ) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isinff(float ) throw() __attribute((const));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" int __finitef(float ) throw() __attribute((const));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float ) throw() __attribute((const));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitef(float ) throw() __attribute((const));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" float dremf(float , float ) throw(); extern "C" float __dremf(float , float ) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" float significandf(float ) throw(); extern "C" float __significandf(float ) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" float copysignf(float , float ) throw() __attribute((const)); extern "C" float __copysignf(float , float ) throw() __attribute((const));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" float nanf(const char * ) throw() __attribute((const)); extern "C" float __nanf(const char * ) throw() __attribute((const));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isnanf(float ) throw() __attribute((const));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnanf(float ) throw() __attribute((const));
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
extern "C" float erff(float) throw(); extern "C" float __erff(float) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int * ) throw(); extern "C" float __lgammaf_r(float, int * ) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" float rintf(float ) throw(); extern "C" float __rintf(float ) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" float nextafterf(float , float ) throw() __attribute((const)); extern "C" float __nextafterf(float , float ) throw() __attribute((const));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" float nexttowardf(float , long double ) throw() __attribute((const)); extern "C" float __nexttowardf(float , long double ) throw() __attribute((const));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" float remainderf(float , float ) throw(); extern "C" float __remainderf(float , float ) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalbnf(float , int ) throw(); extern "C" float __scalbnf(float , int ) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" int ilogbf(float ) throw(); extern "C" int __ilogbf(float ) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalblnf(float , long ) throw(); extern "C" float __scalblnf(float , long ) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" float nearbyintf(float ) throw(); extern "C" float __nearbyintf(float ) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" float roundf(float ) throw() __attribute((const)); extern "C" float __roundf(float ) throw() __attribute((const));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" float truncf(float ) throw() __attribute((const)); extern "C" float __truncf(float ) throw() __attribute((const));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" float remquof(float , float , int * ) throw(); extern "C" float __remquof(float , float , int * ) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrintf(float ) throw(); extern "C" long __lrintf(float ) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llrintf(float ) throw(); extern "C" long long __llrintf(float ) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" long lroundf(float ) throw(); extern "C" long __lroundf(float ) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llroundf(float ) throw(); extern "C" long long __llroundf(float ) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" float fdimf(float , float ) throw(); extern "C" float __fdimf(float , float ) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" float fmaxf(float , float ) throw(); extern "C" float __fmaxf(float , float ) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" float fminf(float , float ) throw(); extern "C" float __fminf(float , float ) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyf(float ) throw()
# 347 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" int __signbitf(float ) throw()
# 351 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" float fmaf(float , float , float ) throw(); extern "C" float __fmaf(float , float , float ) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalbf(float , float ) throw(); extern "C" float __scalbf(float , float ) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double ) throw(); extern "C" long double __acosl(long double ) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" long double asinl(long double ) throw(); extern "C" long double __asinl(long double ) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atanl(long double ) throw(); extern "C" long double __atanl(long double ) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atan2l(long double , long double ) throw(); extern "C" long double __atan2l(long double , long double ) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cosl(long double ) throw(); extern "C" long double __cosl(long double ) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sinl(long double ) throw(); extern "C" long double __sinl(long double ) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tanl(long double ) throw(); extern "C" long double __tanl(long double ) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" long double coshl(long double ) throw(); extern "C" long double __coshl(long double ) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sinhl(long double ) throw(); extern "C" long double __sinhl(long double ) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tanhl(long double ) throw(); extern "C" long double __tanhl(long double ) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" void sincosl(long double , long double * , long double * ) throw(); extern "C" void __sincosl(long double , long double * , long double * ) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acoshl(long double ) throw(); extern "C" long double __acoshl(long double ) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" long double asinhl(long double ) throw(); extern "C" long double __asinhl(long double ) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atanhl(long double ) throw(); extern "C" long double __atanhl(long double ) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expl(long double ) throw(); extern "C" long double __expl(long double ) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" long double frexpl(long double , int * ) throw(); extern "C" long double __frexpl(long double , int * ) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ldexpl(long double , int ) throw(); extern "C" long double __ldexpl(long double , int ) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" long double logl(long double ) throw(); extern "C" long double __logl(long double ) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log10l(long double ) throw(); extern "C" long double __log10l(long double ) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" long double modfl(long double , long double * ) throw(); extern "C" long double __modfl(long double , long double * ) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp10l(long double ) throw(); extern "C" long double __exp10l(long double ) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" long double pow10l(long double ) throw(); extern "C" long double __pow10l(long double ) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expm1l(long double ) throw(); extern "C" long double __expm1l(long double ) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log1pl(long double ) throw(); extern "C" long double __log1pl(long double ) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" long double logbl(long double ) throw(); extern "C" long double __logbl(long double ) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp2l(long double ) throw(); extern "C" long double __exp2l(long double ) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log2l(long double ) throw(); extern "C" long double __log2l(long double ) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" long double powl(long double , long double ) throw(); extern "C" long double __powl(long double , long double ) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sqrtl(long double ) throw(); extern "C" long double __sqrtl(long double ) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" long double hypotl(long double , long double ) throw(); extern "C" long double __hypotl(long double , long double ) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cbrtl(long double ) throw(); extern "C" long double __cbrtl(long double ) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ceill(long double ) throw() __attribute((const)); extern "C" long double __ceill(long double ) throw() __attribute((const));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fabsl(long double ) throw() __attribute((const)); extern "C" long double __fabsl(long double ) throw() __attribute((const));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" long double floorl(long double ) throw() __attribute((const)); extern "C" long double __floorl(long double ) throw() __attribute((const));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmodl(long double , long double ) throw(); extern "C" long double __fmodl(long double , long double ) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isinfl(long double ) throw() __attribute((const));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" int __finitel(long double ) throw() __attribute((const));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinfl(long double ) throw() __attribute((const));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitel(long double ) throw() __attribute((const));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" long double dreml(long double , long double ) throw(); extern "C" long double __dreml(long double , long double ) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" long double significandl(long double ) throw(); extern "C" long double __significandl(long double ) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" long double copysignl(long double , long double ) throw() __attribute((const)); extern "C" long double __copysignl(long double , long double ) throw() __attribute((const));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nanl(const char * ) throw() __attribute((const)); extern "C" long double __nanl(const char * ) throw() __attribute((const));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" int __isnanl(long double ) throw() __attribute((const));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnanl(long double ) throw() __attribute((const));
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
extern "C" long double lgammal_r(long double, int * ) throw(); extern "C" long double __lgammal_r(long double, int * ) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" long double rintl(long double ) throw(); extern "C" long double __rintl(long double ) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nextafterl(long double , long double ) throw() __attribute((const)); extern "C" long double __nextafterl(long double , long double ) throw() __attribute((const));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nexttowardl(long double , long double ) throw() __attribute((const)); extern "C" long double __nexttowardl(long double , long double ) throw() __attribute((const));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" long double remainderl(long double , long double ) throw(); extern "C" long double __remainderl(long double , long double ) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbnl(long double , int ) throw(); extern "C" long double __scalbnl(long double , int ) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" int ilogbl(long double ) throw(); extern "C" int __ilogbl(long double ) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalblnl(long double , long ) throw(); extern "C" long double __scalblnl(long double , long ) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nearbyintl(long double ) throw(); extern "C" long double __nearbyintl(long double ) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" long double roundl(long double ) throw() __attribute((const)); extern "C" long double __roundl(long double ) throw() __attribute((const));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" long double truncl(long double ) throw() __attribute((const)); extern "C" long double __truncl(long double ) throw() __attribute((const));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" long double remquol(long double , long double , int * ) throw(); extern "C" long double __remquol(long double , long double , int * ) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrintl(long double ) throw(); extern "C" long __lrintl(long double ) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llrintl(long double ) throw(); extern "C" long long __llrintl(long double ) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" long lroundl(long double ) throw(); extern "C" long __lroundl(long double ) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llroundl(long double ) throw(); extern "C" long long __llroundl(long double ) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fdiml(long double , long double ) throw(); extern "C" long double __fdiml(long double , long double ) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmaxl(long double , long double ) throw(); extern "C" long double __fmaxl(long double , long double ) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fminl(long double , long double ) throw(); extern "C" long double __fminl(long double , long double ) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyl(long double ) throw()
# 347 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" int __signbitl(long double ) throw()
# 351 "/usr/include/bits/mathcalls.h" 3
 __attribute((const));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmal(long double , long double , long double ) throw(); extern "C" long double __fmal(long double , long double , long double ) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double , long double ) throw(); extern "C" long double __scalbl(long double , long double ) throw();
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
extern "C" int matherr(__exception * ) throw();
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
extern "C" double atof(const char * ) throw()
# 146 "/usr/include/stdlib.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 148 "/usr/include/stdlib.h" 3
extern "C" int atoi(const char * ) throw()
# 149 "/usr/include/stdlib.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 151 "/usr/include/stdlib.h" 3
extern "C" long atol(const char * ) throw()
# 152 "/usr/include/stdlib.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 158 "/usr/include/stdlib.h" 3
extern "C" long long atoll(const char * ) throw()
# 159 "/usr/include/stdlib.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
# 165 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *__restrict__ , char **__restrict__ ) throw()
# 167 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 173 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *__restrict__ , char **__restrict__ ) throw()
# 174 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 176 "/usr/include/stdlib.h" 3
extern "C" long double strtold(const char *__restrict__ , char **__restrict__ ) throw()
# 178 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 184 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *__restrict__ , char **__restrict__ , int ) throw()
# 186 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 188 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul(const char *__restrict__ , char **__restrict__ , int ) throw()
# 190 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 196 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *__restrict__ , char **__restrict__ , int ) throw()
# 198 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 201 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtouq(const char *__restrict__ , char **__restrict__ , int ) throw()
# 203 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 210 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *__restrict__ , char **__restrict__ , int ) throw()
# 212 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 215 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull(const char *__restrict__ , char **__restrict__ , int ) throw()
# 217 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__ , char **__restrict__ , int , __locale_t ) throw()
# 242 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 244 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul_l(const char *__restrict__ , char **__restrict__ , int , __locale_t ) throw()
# 247 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 250 "/usr/include/stdlib.h" 3
extern "C" long long strtoll_l(const char *__restrict__ , char **__restrict__ , int , __locale_t ) throw()
# 253 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 256 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull_l(const char *__restrict__ , char **__restrict__ , int , __locale_t ) throw()
# 259 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 261 "/usr/include/stdlib.h" 3
extern "C" double strtod_l(const char *__restrict__ , char **__restrict__ , __locale_t ) throw()
# 263 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 3)));
# 265 "/usr/include/stdlib.h" 3
extern "C" float strtof_l(const char *__restrict__ , char **__restrict__ , __locale_t ) throw()
# 267 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 3)));
# 269 "/usr/include/stdlib.h" 3
extern "C" long double strtold_l(const char *__restrict__ , char **__restrict__ , __locale_t ) throw()
# 272 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 3)));
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long ) throw();
# 314 "/usr/include/stdlib.h" 3
extern "C" long a64l(const char * ) throw()
# 315 "/usr/include/stdlib.h" 3
 __attribute((__pure__)) __attribute((__nonnull__(1)));
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
extern "C" { typedef signed char int8_t __attribute((__mode__(__QI__))); }
# 196 "/usr/include/sys/types.h" 3
extern "C" { typedef short int16_t __attribute((__mode__(__HI__))); }
# 197 "/usr/include/sys/types.h" 3
extern "C" { typedef int int32_t __attribute((__mode__(__SI__))); }
# 198 "/usr/include/sys/types.h" 3
extern "C" { typedef long int64_t __attribute((__mode__(__DI__))); }
# 201 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned char u_int8_t __attribute((__mode__(__QI__))); }
# 202 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned short u_int16_t __attribute((__mode__(__HI__))); }
# 203 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned u_int32_t __attribute((__mode__(__SI__))); }
# 204 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long u_int64_t __attribute((__mode__(__DI__))); }
# 206 "/usr/include/sys/types.h" 3
extern "C" { typedef long register_t __attribute((__mode__(__word__))); }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32 "/usr/include/bits/sigset.h" 3
extern "C" { typedef
# 30 "/usr/include/bits/sigset.h" 3
struct {
# 31 "/usr/include/bits/sigset.h" 3
unsigned long __val[(1024) / ((8) * sizeof(unsigned long))];
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
__fd_mask fds_bits[1024 / (8 * ((int)sizeof(__fd_mask)))];
# 78 "/usr/include/sys/select.h" 3
} fd_set; }
# 85 "/usr/include/sys/select.h" 3
extern "C" { typedef __fd_mask fd_mask; }
# 109 "/usr/include/sys/select.h" 3
extern "C" int select(int , fd_set *__restrict__ , fd_set *__restrict__ , fd_set *__restrict__ , timeval *__restrict__ );
# 121 "/usr/include/sys/select.h" 3
extern "C" int pselect(int , fd_set *__restrict__ , fd_set *__restrict__ , fd_set *__restrict__ , const timespec *__restrict__ , const __sigset_t *__restrict__ );
# 31 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned gnu_dev_major(unsigned long long ) throw();
# 34 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned gnu_dev_minor(unsigned long long ) throw();
# 37 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned long long gnu_dev_makedev(unsigned , unsigned ) throw();
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
extern "C" void srandom(unsigned ) throw();
# 336 "/usr/include/stdlib.h" 3
extern "C" char *initstate(unsigned , char * , size_t ) throw()
# 337 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2)));
# 341 "/usr/include/stdlib.h" 3
extern "C" char *setstate(char * ) throw() __attribute((__nonnull__(1)));
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
extern "C" int random_r(random_data *__restrict__ , int32_t *__restrict__ ) throw()
# 361 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 363 "/usr/include/stdlib.h" 3
extern "C" int srandom_r(unsigned , random_data * ) throw()
# 364 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2)));
# 366 "/usr/include/stdlib.h" 3
extern "C" int initstate_r(unsigned , char *__restrict__ , size_t , random_data *__restrict__ ) throw()
# 369 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2, 4)));
# 371 "/usr/include/stdlib.h" 3
extern "C" int setstate_r(char *__restrict__ , random_data *__restrict__ ) throw()
# 373 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 380 "/usr/include/stdlib.h" 3
extern "C" int rand() throw();
# 382 "/usr/include/stdlib.h" 3
extern "C" void srand(unsigned ) throw();
# 387 "/usr/include/stdlib.h" 3
extern "C" int rand_r(unsigned * ) throw();
# 395 "/usr/include/stdlib.h" 3
extern "C" double drand48() throw();
# 396 "/usr/include/stdlib.h" 3
extern "C" double erand48(unsigned short [3]) throw() __attribute((__nonnull__(1)));
# 399 "/usr/include/stdlib.h" 3
extern "C" long lrand48() throw();
# 400 "/usr/include/stdlib.h" 3
extern "C" long nrand48(unsigned short [3]) throw()
# 401 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 404 "/usr/include/stdlib.h" 3
extern "C" long mrand48() throw();
# 405 "/usr/include/stdlib.h" 3
extern "C" long jrand48(unsigned short [3]) throw()
# 406 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 409 "/usr/include/stdlib.h" 3
extern "C" void srand48(long ) throw();
# 410 "/usr/include/stdlib.h" 3
extern "C" unsigned short *seed48(unsigned short [3]) throw()
# 411 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 412 "/usr/include/stdlib.h" 3
extern "C" void lcong48(unsigned short [7]) throw() __attribute((__nonnull__(1)));
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
extern "C" int drand48_r(drand48_data *__restrict__ , double *__restrict__ ) throw()
# 429 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 430 "/usr/include/stdlib.h" 3
extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__ , double *__restrict__ ) throw()
# 432 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 435 "/usr/include/stdlib.h" 3
extern "C" int lrand48_r(drand48_data *__restrict__ , long *__restrict__ ) throw()
# 437 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 438 "/usr/include/stdlib.h" 3
extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__ , long *__restrict__ ) throw()
# 441 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 444 "/usr/include/stdlib.h" 3
extern "C" int mrand48_r(drand48_data *__restrict__ , long *__restrict__ ) throw()
# 446 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 447 "/usr/include/stdlib.h" 3
extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__ , long *__restrict__ ) throw()
# 450 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 453 "/usr/include/stdlib.h" 3
extern "C" int srand48_r(long , drand48_data * ) throw()
# 454 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2)));
# 456 "/usr/include/stdlib.h" 3
extern "C" int seed48_r(unsigned short [3], drand48_data * ) throw()
# 457 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 459 "/usr/include/stdlib.h" 3
extern "C" int lcong48_r(unsigned short [7], drand48_data * ) throw()
# 461 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2)));
# 471 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t ) throw() __attribute((__malloc__));
# 473 "/usr/include/stdlib.h" 3
extern "C" void *calloc(size_t , size_t ) throw()
# 474 "/usr/include/stdlib.h" 3
 __attribute((__malloc__));
# 485 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void * , size_t ) throw()
# 486 "/usr/include/stdlib.h" 3
 __attribute((__warn_unused_result__));
# 488 "/usr/include/stdlib.h" 3
extern "C" void free(void * ) throw();
# 493 "/usr/include/stdlib.h" 3
extern "C" void cfree(void * ) throw();
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t ) throw();
# 503 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t ) throw() __attribute((__malloc__));
# 508 "/usr/include/stdlib.h" 3
extern "C" int posix_memalign(void ** , size_t , size_t ) throw()
# 509 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 514 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute((__noreturn__));
# 518 "/usr/include/stdlib.h" 3
extern "C" int atexit(void (* )(void)) throw() __attribute((__nonnull__(1)));
# 525 "/usr/include/stdlib.h" 3
int at_quick_exit(void (* )(void)) throw() __asm__("at_quick_exit")
# 526 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 536 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (* )(int , void * ), void * ) throw()
# 537 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 544 "/usr/include/stdlib.h" 3
extern "C" void exit(int ) throw() __attribute((__noreturn__));
# 552 "/usr/include/stdlib.h" 3
extern "C" void quick_exit(int ) throw() __attribute((__noreturn__));
# 560 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int ) throw() __attribute((__noreturn__));
# 567 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char * ) throw() __attribute((__nonnull__(1)));
# 572 "/usr/include/stdlib.h" 3
extern "C" char *__secure_getenv(const char * ) throw()
# 573 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 579 "/usr/include/stdlib.h" 3
extern "C" int putenv(char * ) throw() __attribute((__nonnull__(1)));
# 585 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char * , const char * , int ) throw()
# 586 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2)));
# 589 "/usr/include/stdlib.h" 3
extern "C" int unsetenv(const char * ) throw() __attribute((__nonnull__(1)));
# 596 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 606 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char * ) throw() __attribute((__nonnull__(1)));
# 620 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char * ) __attribute((__nonnull__(1)));
# 630 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char * ) __attribute((__nonnull__(1)));
# 642 "/usr/include/stdlib.h" 3
extern "C" int mkstemps(char * , int ) __attribute((__nonnull__(1)));
# 652 "/usr/include/stdlib.h" 3
extern "C" int mkstemps64(char * , int )
# 653 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 663 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char * ) throw() __attribute((__nonnull__(1)));
# 674 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char * , int ) __attribute((__nonnull__(1)));
# 684 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char * , int ) __attribute((__nonnull__(1)));
# 694 "/usr/include/stdlib.h" 3
extern "C" int mkostemps(char * , int , int )
# 695 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 706 "/usr/include/stdlib.h" 3
extern "C" int mkostemps64(char * , int , int )
# 707 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 717 "/usr/include/stdlib.h" 3
extern "C" int system(const char * );
# 724 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char * ) throw()
# 725 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 734 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__ , char *__restrict__ ) throw();
# 742 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 745 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 749 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 755 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void * , const void * , size_t , size_t , __compar_fn_t )
# 757 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2, 5)));
# 761 "/usr/include/stdlib.h" 3
extern "C" void qsort(void * , size_t , size_t , __compar_fn_t )
# 762 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 764 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void * , size_t , size_t , __compar_d_fn_t , void * )
# 766 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 4)));
# 771 "/usr/include/stdlib.h" 3
extern "C" int abs(int ) throw() __attribute((const));
# 772 "/usr/include/stdlib.h" 3
extern "C" long labs(long ) throw() __attribute((const));
# 776 "/usr/include/stdlib.h" 3
extern "C" long long llabs(long long ) throw()
# 777 "/usr/include/stdlib.h" 3
 __attribute((const));
# 785 "/usr/include/stdlib.h" 3
extern "C" div_t div(int , int ) throw()
# 786 "/usr/include/stdlib.h" 3
 __attribute((const));
# 787 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long , long ) throw()
# 788 "/usr/include/stdlib.h" 3
 __attribute((const));
# 793 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long , long long ) throw()
# 795 "/usr/include/stdlib.h" 3
 __attribute((const));
# 808 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double , int , int *__restrict__ , int *__restrict__ ) throw()
# 809 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4)));
# 814 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double , int , int *__restrict__ , int *__restrict__ ) throw()
# 815 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4)));
# 820 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double , int , char * ) throw()
# 821 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3)));
# 826 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double , int , int *__restrict__ , int *__restrict__ ) throw()
# 828 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4)));
# 829 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double , int , int *__restrict__ , int *__restrict__ ) throw()
# 831 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4)));
# 832 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double , int , char * ) throw()
# 833 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3)));
# 838 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double , int , int *__restrict__ , int *__restrict__ , char *__restrict__ , size_t ) throw()
# 840 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4, 5)));
# 841 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double , int , int *__restrict__ , int *__restrict__ , char *__restrict__ , size_t ) throw()
# 843 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4, 5)));
# 845 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double , int , int *__restrict__ , int *__restrict__ , char *__restrict__ , size_t ) throw()
# 848 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4, 5)));
# 849 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double , int , int *__restrict__ , int *__restrict__ , char *__restrict__ , size_t ) throw()
# 852 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(3, 4, 5)));
# 860 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char * , size_t ) throw();
# 863 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__ , const char *__restrict__ , size_t ) throw();
# 867 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char * , wchar_t ) throw();
# 871 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__ , const char *__restrict__ , size_t ) throw();
# 874 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__ , const wchar_t *__restrict__ , size_t ) throw();
# 885 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char * ) throw() __attribute((__nonnull__(1)));
# 896 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__ , char *const *__restrict__ , char **__restrict__ ) throw()
# 899 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1, 2, 3)));
# 905 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char * ) throw() __attribute((__nonnull__(1)));
# 913 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int );
# 921 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int ) throw();
# 925 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int ) throw();
# 930 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int ) throw();
# 937 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int , char * , size_t ) throw()
# 938 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(2)));
# 941 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 948 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int ) throw()
# 949 "/usr/include/stdlib.h" 3
 __attribute((__nonnull__(1)));
# 69 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) {
# 71 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container> class __normal_iterator;
# 74 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 76 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace std __attribute((__visibility__("default")))
# 77 "/usr/include/c++/4.4/cmath" 3
 __attribute((__visibility__("default")))
# 492 "/usr/include/c++/4.4/cmath" 3
 __attribute((__visibility__("default")))
# 35 "/usr/include/c++/4.4/bits/cmath.tcc" 3
 __attribute((__visibility__("default")))
# 49 "/usr/include/c++/4.4/cstddef" 3
 __attribute((__visibility__("default")))
# 100 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
namespace __gnu_cxx __attribute((__visibility__("default")))
# 157 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
public: typedef __typeof__((__type1() + __type2())) __type;
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
public: typedef __typeof__(((__type1() + __type2()) + __type3())) __type;
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
public: typedef __typeof__((((__type1() + __type2()) + __type3()) + __type4())) __type;
# 200 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 202 "/usr/include/c++/4.4/ext/type_traits.h" 3
}
# 77 "/usr/include/c++/4.4/cmath" 3
namespace std __attribute((__visibility__("default")))
# 492 "/usr/include/c++/4.4/cmath" 3
 __attribute((__visibility__("default")))
# 35 "/usr/include/c++/4.4/bits/cmath.tcc" 3
 __attribute((__visibility__("default")))
# 49 "/usr/include/c++/4.4/cstddef" 3
 __attribute((__visibility__("default")))
# 100 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
namespace std __attribute((__visibility__("default")))
# 35 "/usr/include/c++/4.4/bits/cmath.tcc" 3
 __attribute((__visibility__("default")))
# 49 "/usr/include/c++/4.4/cstddef" 3
 __attribute((__visibility__("default")))
# 100 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
namespace std __attribute((__visibility__("default")))
# 49 "/usr/include/c++/4.4/cstddef" 3
 __attribute((__visibility__("default")))
# 100 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
namespace std __attribute((__visibility__("default")))
# 100 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
# 51 "/usr/include/c++/4.4/cstddef" 3
using ::ptrdiff_t;
# 52 "/usr/include/c++/4.4/cstddef" 3
using ::size_t;
# 54 "/usr/include/c++/4.4/cstddef" 3
}
# 100 "/usr/include/c++/4.4/cstdlib" 3
namespace std __attribute((__visibility__("default")))
# 199 "/usr/include/c++/4.4/cstdlib" 3
 __attribute((__visibility__("default"))) {
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
namespace __gnu_cxx __attribute((__visibility__("default"))) {
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
namespace std __attribute((__visibility__("default"))) {
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
# 85 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int abs(int) throw();
# 87 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long labs(long) throw();
# 89 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llabs(long long) throw();
# 91 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fabs(double) throw();
# 93 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fabsf(float) throw();
# 96 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int min(int, int);
# 98 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" unsigned umin(unsigned, unsigned);
# 100 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llmin(long long, long long);
# 102 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" unsigned long long ullmin(unsigned long long, unsigned long long);
# 104 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fminf(float, float) throw();
# 106 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fmin(double, double) throw();
# 109 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int max(int, int);
# 111 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" unsigned umax(unsigned, unsigned);
# 113 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llmax(long long, long long);
# 115 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" unsigned long long ullmax(unsigned long long, unsigned long long);
# 117 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fmaxf(float, float) throw();
# 119 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fmax(double, double) throw();
# 122 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double sin(double) throw();
# 124 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float sinf(float) throw();
# 127 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double cos(double) throw();
# 129 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float cosf(float) throw();
# 132 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" void sincos(double, double *, double *) throw();
# 134 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" void sincosf(float, float *, float *) throw();
# 137 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double tan(double) throw();
# 139 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float tanf(float) throw();
# 142 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double sqrt(double) throw();
# 144 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float sqrtf(float) throw();
# 147 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double rsqrt(double);
# 149 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float rsqrtf(float);
# 152 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double exp2(double) throw();
# 154 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float exp2f(float) throw();
# 157 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double exp10(double) throw();
# 159 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float exp10f(float) throw();
# 162 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double expm1(double) throw();
# 164 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float expm1f(float) throw();
# 167 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double log2(double) throw();
# 169 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float log2f(float) throw();
# 172 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double log10(double) throw();
# 174 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float log10f(float) throw();
# 177 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double log(double) throw();
# 179 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float logf(float) throw();
# 182 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double log1p(double) throw();
# 184 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float log1pf(float) throw();
# 187 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double floor(double) throw();
# 189 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float floorf(float) throw();
# 192 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double exp(double) throw();
# 194 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float expf(float) throw();
# 197 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double cosh(double) throw();
# 199 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float coshf(float) throw();
# 202 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double sinh(double) throw();
# 204 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float sinhf(float) throw();
# 207 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double tanh(double) throw();
# 209 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float tanhf(float) throw();
# 212 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double acosh(double) throw();
# 214 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float acoshf(float) throw();
# 217 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double asinh(double) throw();
# 219 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float asinhf(float) throw();
# 222 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double atanh(double) throw();
# 224 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float atanhf(float) throw();
# 227 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double ldexp(double, int) throw();
# 229 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float ldexpf(float, int) throw();
# 232 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double logb(double) throw();
# 234 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float logbf(float) throw();
# 237 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int ilogb(double) throw();
# 239 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int ilogbf(float) throw();
# 242 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double scalbn(double, int) throw();
# 244 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float scalbnf(float, int) throw();
# 247 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double scalbln(double, long) throw();
# 249 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float scalblnf(float, long) throw();
# 252 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double frexp(double, int *) throw();
# 254 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float frexpf(float, int *) throw();
# 257 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double round(double) throw();
# 259 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float roundf(float) throw();
# 262 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long lround(double) throw();
# 264 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long lroundf(float) throw();
# 267 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llround(double) throw();
# 269 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llroundf(float) throw();
# 272 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double rint(double) throw();
# 274 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float rintf(float) throw();
# 277 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long lrint(double) throw();
# 279 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long lrintf(float) throw();
# 282 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llrint(double) throw();
# 284 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" long long llrintf(float) throw();
# 287 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double nearbyint(double) throw();
# 289 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float nearbyintf(float) throw();
# 292 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double ceil(double) throw();
# 294 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float ceilf(float) throw();
# 297 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double trunc(double) throw();
# 299 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float truncf(float) throw();
# 302 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fdim(double, double) throw();
# 304 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fdimf(float, float) throw();
# 307 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double atan2(double, double) throw();
# 309 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float atan2f(float, float) throw();
# 312 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double atan(double) throw();
# 314 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float atanf(float) throw();
# 317 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double asin(double) throw();
# 319 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float asinf(float) throw();
# 322 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double acos(double) throw();
# 324 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float acosf(float) throw();
# 328 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double hypot(double, double) throw();
# 334 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float hypotf(float, float) throw();
# 337 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double cbrt(double) throw();
# 339 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float cbrtf(float) throw();
# 342 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double rcbrt(double);
# 344 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float rcbrtf(float);
# 347 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double sinpi(double);
# 349 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float sinpif(float);
# 352 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double cospi(double);
# 354 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float cospif(float);
# 357 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double pow(double, double) throw();
# 359 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float powf(float, float) throw();
# 362 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double modf(double, double *) throw();
# 364 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float modff(float, float *) throw();
# 367 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fmod(double, double) throw();
# 369 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fmodf(float, float) throw();
# 372 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double remainder(double, double) throw();
# 374 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float remainderf(float, float) throw();
# 377 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double remquo(double, double, int *) throw();
# 379 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float remquof(float, float, int *) throw();
# 382 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double erf(double) throw();
# 384 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float erff(float) throw();
# 387 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double erfinv(double);
# 389 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float erfinvf(float);
# 392 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double erfc(double) throw();
# 394 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float erfcf(float) throw();
# 397 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double erfcinv(double);
# 399 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float erfcinvf(float);
# 402 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double lgamma(double) throw();
# 404 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float lgammaf(float) throw();
# 407 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double tgamma(double) throw();
# 409 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float tgammaf(float) throw();
# 412 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double copysign(double, double) throw();
# 414 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float copysignf(float, float) throw();
# 417 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double nextafter(double, double) throw();
# 419 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float nextafterf(float, float) throw();
# 422 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double nan(const char *) throw();
# 424 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float nanf(const char *) throw();
# 427 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isinf(double) throw();
# 429 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isinff(float) throw();
# 432 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isnan(double) throw();
# 434 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isnanf(float) throw();
# 448 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __finite(double) throw();
# 450 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __finitef(float) throw();
# 452 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __signbit(double) throw();
# 457 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __signbitf(float) throw();
# 460 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" double fma(double, double, double) throw();
# 462 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" float fmaf(float, float, float) throw();
# 470 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __signbitl(long double) throw();
# 472 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isinfl(long double) throw();
# 474 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __isnanl(long double) throw();
# 484 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" int __finitel(long double) throw();
# 521 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 523 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long);
# 524 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 526 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 528 "/usr/local/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __pow_helper(T, int);
# 529 "/usr/local/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __cmath_power(T, unsigned);
# 530 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 532 "/usr/local/cuda/bin/../include/math_functions.h"
using std::abs;
# 533 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fabs;
# 534 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ceil;
# 535 "/usr/local/cuda/bin/../include/math_functions.h"
using std::floor;
# 536 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 537 "/usr/local/cuda/bin/../include/math_functions.h"
using std::pow;
# 538 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log;
# 539 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log10;
# 540 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fmod;
# 541 "/usr/local/cuda/bin/../include/math_functions.h"
using std::modf;
# 542 "/usr/local/cuda/bin/../include/math_functions.h"
using std::exp;
# 543 "/usr/local/cuda/bin/../include/math_functions.h"
using std::frexp;
# 544 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 545 "/usr/local/cuda/bin/../include/math_functions.h"
using std::asin;
# 546 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sin;
# 547 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sinh;
# 548 "/usr/local/cuda/bin/../include/math_functions.h"
using std::acos;
# 549 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cos;
# 550 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cosh;
# 551 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan;
# 552 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan2;
# 553 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tan;
# 554 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tanh;
# 611 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 614 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long abs(long);
# 615 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float abs(float);
# 616 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double abs(double);
# 617 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fabs(float);
# 618 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ceil(float);
# 619 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float floor(float);
# 620 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float);
# 621 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float);
# 622 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int);
# 623 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int);
# 624 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log(float);
# 625 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log10(float);
# 626 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float);
# 627 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *);
# 628 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float exp(float);
# 629 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *);
# 630 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int);
# 631 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float asin(float);
# 632 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sin(float);
# 633 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sinh(float);
# 634 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float acos(float);
# 635 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cos(float);
# 636 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cosh(float);
# 637 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan(float);
# 638 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float);
# 639 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tan(float);
# 640 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tanh(float);
# 643 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 646 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 647 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 648 "/usr/local/cuda/bin/../include/math_functions.h"
return logbf(a);
# 649 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 651 "/usr/local/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 652 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 653 "/usr/local/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 654 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 656 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 657 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 658 "/usr/local/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 659 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 661 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 662 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 663 "/usr/local/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 664 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 666 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 667 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 668 "/usr/local/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 669 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 671 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 672 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 673 "/usr/local/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 674 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 676 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 677 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 678 "/usr/local/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 679 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 681 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 682 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 683 "/usr/local/cuda/bin/../include/math_functions.h"
return log2f(a);
# 684 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 686 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 687 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 688 "/usr/local/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 689 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 691 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 692 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 693 "/usr/local/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 694 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 696 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 697 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 698 "/usr/local/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 699 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 701 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 702 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 703 "/usr/local/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 704 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 706 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 707 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 708 "/usr/local/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 709 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 711 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 712 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 713 "/usr/local/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 714 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 716 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 717 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 718 "/usr/local/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 719 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 721 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 722 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 723 "/usr/local/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 724 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 726 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 727 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 728 "/usr/local/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 729 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 731 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float cospi(float a)
# 732 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 733 "/usr/local/cuda/bin/../include/math_functions.h"
return cospif(a);
# 734 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 736 "/usr/local/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 737 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 738 "/usr/local/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 739 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 741 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 742 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 743 "/usr/local/cuda/bin/../include/math_functions.h"
return erff(a);
# 744 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 746 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 747 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 748 "/usr/local/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 749 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 751 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 752 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 753 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 754 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 756 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 757 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 758 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 759 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 761 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 762 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 763 "/usr/local/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 764 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 766 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 767 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 768 "/usr/local/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 769 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 771 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 772 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 773 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 774 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 776 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 777 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 778 "/usr/local/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 779 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 781 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 782 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 783 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 784 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 786 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 787 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 788 "/usr/local/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 789 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 791 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 792 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 793 "/usr/local/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 794 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 796 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 797 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 798 "/usr/local/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 799 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 801 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 802 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 803 "/usr/local/cuda/bin/../include/math_functions.h"
return roundf(a);
# 804 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 806 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 807 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 808 "/usr/local/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 809 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 811 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 812 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 813 "/usr/local/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 814 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 816 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 817 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 818 "/usr/local/cuda/bin/../include/math_functions.h"
return truncf(a);
# 819 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 821 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 822 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 823 "/usr/local/cuda/bin/../include/math_functions.h"
return rintf(a);
# 824 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 826 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 827 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 828 "/usr/local/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 829 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 831 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 832 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 833 "/usr/local/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 834 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 836 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 837 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 838 "/usr/local/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 839 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 841 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 842 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 843 "/usr/local/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 844 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 846 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 847 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 848 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 849 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 851 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 852 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 853 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 854 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 856 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 857 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 858 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 859 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 861 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 862 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 863 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 864 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 866 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 867 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 868 "/usr/local/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 869 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 871 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 872 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 873 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 874 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 876 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 877 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 878 "/usr/local/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 879 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 881 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 882 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 883 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 884 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 886 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 887 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 888 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 889 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 891 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 892 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 893 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 894 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 896 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 897 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 898 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 899 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 901 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 902 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 903 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 904 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 906 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 907 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 908 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 909 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 911 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 912 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 913 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 914 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 916 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 917 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 918 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 919 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 921 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 922 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 923 "/usr/local/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 924 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 926 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 927 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 928 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 929 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 931 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 932 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 933 "/usr/local/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 934 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 936 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 937 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 938 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 939 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 941 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 942 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 943 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 944 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 946 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 947 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 948 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 949 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 951 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 952 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 953 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 954 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 956 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 957 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 958 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 959 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 961 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 962 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 963 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 964 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 966 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 967 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 968 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 969 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 74 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template< class T, int dim = 1>
# 75 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 77 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 78 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 79 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 80 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 82 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 83 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 84 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 85 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 86 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 89 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template< int dim>
# 90 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 92 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 93 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 94 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 95 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 96 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 74 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template< class T, int texType = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 75 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 77 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 78 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 79 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 80 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 81 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 82 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 83 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 84 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 85 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 86 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 87 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(sRGB) = 0;
# 88 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 90 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 91 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 92 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 93 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
desc)
# 94 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 95 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 96 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 97 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 98 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 99 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 100 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 101 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(sRGB) = 0;
# 102 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 103 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
};
# 338 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mulhi(int a, int b)
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 341 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 343 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b)
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 346 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 348 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b)
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 351 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 353 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b)
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 356 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 358 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b)
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 361 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 363 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 366 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 368 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 371 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 373 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 376 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 378 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float_as_int(float a)
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 381 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 383 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int_as_float(int a)
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 386 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 388 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float saturate(float a)
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 391 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 393 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mul24(int a, int b)
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 396 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 398 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b)
# 399 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 401 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 403 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void trap()
# 404 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 406 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 409 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void brkpt(int c = 0)
# 410 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)c;
# 412 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 414 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void syncthreads()
# 415 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 417 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 419 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void prof_trigger(int e)
# 420 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)e;
# 437 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 439 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void threadfence(bool global = true)
# 440 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)global;
# 442 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 444 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 445 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 450 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 452 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 453 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 458 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 460 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 461 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 466 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 468 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 469 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 474 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 116 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val)
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 119 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 121 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 124 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 126 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val)
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 129 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 131 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val)
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 134 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 136 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val)
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 139 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 141 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val)
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 144 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 146 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val)
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 149 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 151 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val)
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 154 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 156 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val)
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 159 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 161 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val)
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 164 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 166 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val)
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 169 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 171 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val)
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 174 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 176 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val)
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 179 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 181 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val)
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 184 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 186 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 189 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 191 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val)
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 194 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 196 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val)
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 199 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 201 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val)
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 204 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 206 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val)
# 207 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 209 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 211 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val)
# 212 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 214 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 216 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 217 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 219 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 89 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 92 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 94 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 97 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 99 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 100 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 102 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 104 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond)
# 105 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)cond;
# 107 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 109 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond)
# 110 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)cond;
# 112 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 184 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 185 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;
# 190 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 192 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 193 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 198 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 200 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 201 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 206 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 208 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 209 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 214 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 216 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 217 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 222 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 224 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 225 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 230 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 232 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 233 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 238 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 240 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 241 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 246 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 248 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 249 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 254 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 256 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 257 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 259 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 261 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 262 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 264 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 266 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 267 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 269 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 80 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val)
# 81 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 83 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 138 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned ballot(bool pred)
# 139 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 141 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 143 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred)
# 144 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 146 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 148 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred)
# 149 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 151 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 153 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred)
# 154 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 156 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 111 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 112 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 113 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)s;(void)mode;
# 120 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 122 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 123 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 124 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 130 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 132 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 133 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 134 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)mode;
# 136 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 139 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 140 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 142 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 145 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 146 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 148 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 151 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 152 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 154 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 157 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 158 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 160 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 166 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 174 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 180 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 188 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 191 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 192 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 194 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 197 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 198 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 200 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 203 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 204 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 206 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 209 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 210 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 218 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 226 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 240 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 243 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 244 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 246 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 249 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 250 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 252 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 255 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 256 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 258 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 261 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 262 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 264 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 270 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 278 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 284 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 292 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 295 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 296 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 298 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 301 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 302 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 304 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 307 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 308 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 310 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 313 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 314 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 316 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 322 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 325 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 326 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 330 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 333 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 334 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 336 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 399 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 400 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 402 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 408 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 411 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 412 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 416 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 419 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 420 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 424 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 471 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 472 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 473 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 480 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 482 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 483 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 484 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 490 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 492 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 493 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 494 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)mode;
# 496 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 499 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 500 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 502 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 505 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 506 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 508 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 511 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 512 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 514 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 517 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 518 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 520 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 526 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 534 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 540 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 548 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 551 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 552 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 554 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 557 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 558 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 560 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 563 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 564 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 566 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 569 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 570 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 572 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 578 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 586 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 592 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 600 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 603 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 604 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 606 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 609 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 610 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 612 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 615 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 616 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 618 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 621 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 622 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 624 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 630 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 638 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 644 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 652 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 655 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 656 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 658 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 661 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 662 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 664 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 667 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 668 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 670 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 673 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 674 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 676 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 682 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 685 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 686 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 690 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 693 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 694 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 696 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 759 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 760 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 762 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 768 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 771 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 772 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 776 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 779 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 780 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 784 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 831 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 832 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 833 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)s;(void)mode;
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 853 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 854 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 855 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 857 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 860 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 863 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 865 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 868 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 870 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 873 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 875 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 878 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 880 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 883 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 885 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 888 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 890 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 893 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 895 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 898 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 900 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 903 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 905 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 908 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 910 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 913 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 915 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 918 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 920 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 923 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 925 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 928 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 930 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 933 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 935 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 938 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 940 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 943 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 945 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 948 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 950 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 953 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 955 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 958 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 960 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 963 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 965 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 968 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 970 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 973 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 975 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 978 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 980 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 983 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 985 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 988 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 990 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 993 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 995 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 998 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1000 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1001 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1003 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1005 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1006 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1008 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1010 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1011 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1013 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1059 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1062 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1064 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1065 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1067 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1069 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1070 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1072 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1074 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1075 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1077 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1124 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1125 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1126 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1146 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1147 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1148 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1150 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1153 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1156 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1158 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1161 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1163 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1166 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1168 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1171 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1173 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1176 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1178 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1181 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1183 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1186 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1188 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1191 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1193 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1196 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1198 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1201 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1203 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1206 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1208 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1211 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1213 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1216 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1218 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1221 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1223 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1226 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1228 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1231 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1233 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1236 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1238 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1241 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1243 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1246 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1248 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1251 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1253 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1256 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1258 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1261 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1263 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1266 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1268 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1271 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1273 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1276 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1278 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1281 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1283 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1286 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1288 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1291 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1293 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1294 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1296 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1298 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1299 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1301 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1303 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1304 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1306 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1352 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1355 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1357 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1358 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1360 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1362 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1363 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1365 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1367 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1368 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1370 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 75 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetchi(texture< T, 1, readMode> , int4 );
# 77 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetchi(texture< T, 1, readMode> , int4 );
# 79 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetchi(texture< T, 1, readMode> , int4 );
# 82 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetch(texture< T, texType, readMode> , float4 , int = texType);
# 84 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetch(texture< T, texType, readMode> , float4 , int = texType);
# 86 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetch(texture< T, texType, readMode> , float4 , int = texType);
# 89 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetchl(texture< T, texType, readMode> , float4 , int , int = (texType & 15));
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetchl(texture< T, texType, readMode> , float4 , int , int = (texType & 15));
# 93 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int texType, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetchl(texture< T, texType, readMode> , float4 , int , int = (texType & 15));
# 101 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 102 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 148 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 155 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 162 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 179 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 186 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 193 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 200 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 207 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 209 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 210 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 214 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 217 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 221 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 224 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 228 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 241 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 271 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 272 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 276 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 278 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 279 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 283 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 285 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 286 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 290 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 372 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 376 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 383 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 386 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 390 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 399 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 408 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 410 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 416 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 418 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 424 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 426 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 427 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 432 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 434 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 435 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 440 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 442 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 443 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 448 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 450 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 456 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 464 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 481 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 488 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 489 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 496 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 497 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 502 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 504 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 510 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 512 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 518 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 526 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 536 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 537 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 542 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 550 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 551 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 559 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 566 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 597 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 604 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 611 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 628 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 635 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 642 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 649 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 656 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 658 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 659 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 663 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 666 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 670 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 673 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 677 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 690 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 720 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 721 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 725 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 727 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 728 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 732 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 734 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 735 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 824 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 826 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 827 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 831 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 834 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 838 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 840 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 841 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 854 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 863 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 865 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 871 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 873 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 879 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 881 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 887 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 889 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 890 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 895 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 897 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 898 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 903 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 905 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 906 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 911 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 913 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 919 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 921 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 927 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 935 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 936 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 941 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 943 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 944 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 949 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 951 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 952 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 957 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 959 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 965 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 967 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 968 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 973 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 975 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 976 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 981 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 983 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 989 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 991 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 992 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 997 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1005 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 1006 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1021 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1028 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1051 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1052 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1056 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1058 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1059 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1063 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1066 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1070 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1083 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1111 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1113 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1114 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1118 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1121 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1125 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1128 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1132 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1175 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1176 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1180 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1182 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1183 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1187 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1189 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1190 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1194 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1273 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1275 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1276 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1280 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1282 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1283 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1287 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1289 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1290 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1302 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1303 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1312 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1320 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1323 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1328 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1330 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1331 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1336 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1338 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1339 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1344 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1346 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1347 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1352 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1354 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1360 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1362 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1368 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1370 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1376 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1384 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1390 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1392 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1393 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1400 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1401 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1406 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1408 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1409 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1414 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1416 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1417 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1422 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1424 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1425 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1430 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1432 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1438 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1440 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1441 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1446 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1454 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1DLayered(texture< char, 241, cudaReadModeElementType> t, float x, int layer)
# 1455 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1463 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1DLayered(texture< signed char, 241, cudaReadModeElementType> t, float x, int layer)
# 1466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1470 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1DLayered(texture< unsigned char, 241, cudaReadModeElementType> t, float x, int layer)
# 1473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1477 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1DLayered(texture< char1, 241, cudaReadModeElementType> t, float x, int layer)
# 1480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1DLayered(texture< uchar1, 241, cudaReadModeElementType> t, float x, int layer)
# 1487 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1DLayered(texture< char2, 241, cudaReadModeElementType> t, float x, int layer)
# 1494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1498 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1500 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1DLayered(texture< uchar2, 241, cudaReadModeElementType> t, float x, int layer)
# 1501 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1DLayered(texture< char4, 241, cudaReadModeElementType> t, float x, int layer)
# 1508 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1512 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1514 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1DLayered(texture< uchar4, 241, cudaReadModeElementType> t, float x, int layer)
# 1515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1519 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1DLayered(texture< short, 241, cudaReadModeElementType> t, float x, int layer)
# 1528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1532 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1DLayered(texture< unsigned short, 241, cudaReadModeElementType> t, float x, int layer)
# 1535 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1539 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1DLayered(texture< short1, 241, cudaReadModeElementType> t, float x, int layer)
# 1542 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1546 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1DLayered(texture< ushort1, 241, cudaReadModeElementType> t, float x, int layer)
# 1549 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1553 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1DLayered(texture< short2, 241, cudaReadModeElementType> t, float x, int layer)
# 1556 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1560 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1562 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1DLayered(texture< ushort2, 241, cudaReadModeElementType> t, float x, int layer)
# 1563 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1567 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1DLayered(texture< short4, 241, cudaReadModeElementType> t, float x, int layer)
# 1570 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1574 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1DLayered(texture< ushort4, 241, cudaReadModeElementType> t, float x, int layer)
# 1577 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1581 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1DLayered(texture< int, 241, cudaReadModeElementType> t, float x, int layer)
# 1590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1DLayered(texture< unsigned, 241, cudaReadModeElementType> t, float x, int layer)
# 1597 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1DLayered(texture< int1, 241, cudaReadModeElementType> t, float x, int layer)
# 1604 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1DLayered(texture< uint1, 241, cudaReadModeElementType> t, float x, int layer)
# 1611 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1DLayered(texture< int2, 241, cudaReadModeElementType> t, float x, int layer)
# 1618 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1624 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1DLayered(texture< uint2, 241, cudaReadModeElementType> t, float x, int layer)
# 1625 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1629 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1631 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1DLayered(texture< int4, 241, cudaReadModeElementType> t, float x, int layer)
# 1632 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1636 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1638 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1DLayered(texture< uint4, 241, cudaReadModeElementType> t, float x, int layer)
# 1639 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1643 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< float, 241, cudaReadModeElementType> t, float x, int layer)
# 1718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1722 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1724 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< float1, 241, cudaReadModeElementType> t, float x, int layer)
# 1725 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1729 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1731 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< float2, 241, cudaReadModeElementType> t, float x, int layer)
# 1732 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1736 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1738 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< float4, 241, cudaReadModeElementType> t, float x, int layer)
# 1739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1743 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1751 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1752 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1761 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< signed char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1764 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1769 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1771 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< unsigned char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1772 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1777 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1779 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< char1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1780 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1785 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1787 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< uchar1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1793 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1795 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< char2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1796 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1801 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1803 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< uchar2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1804 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1809 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1811 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< char4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1817 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< uchar4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1825 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< short, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1834 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1839 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1841 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< unsigned short, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1847 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1849 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< short1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1855 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1857 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< ushort1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1863 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1865 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< short2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1871 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1873 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< ushort2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1879 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1881 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< short4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1887 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1889 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< ushort4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1890 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1895 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1903 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2DLayered(texture< char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1904 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1912 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2DLayered(texture< signed char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1915 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1919 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1921 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2DLayered(texture< unsigned char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1926 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1928 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2DLayered(texture< char1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1929 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1933 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1935 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2DLayered(texture< uchar1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1936 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1940 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1942 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2DLayered(texture< char2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1943 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1947 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1949 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2DLayered(texture< uchar2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1950 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1956 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2DLayered(texture< char4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1957 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1961 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1963 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2DLayered(texture< uchar4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1964 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1968 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1976 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2DLayered(texture< short, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1977 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1981 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1983 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2DLayered(texture< unsigned short, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1988 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1990 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2DLayered(texture< short1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1991 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1997 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2DLayered(texture< ushort1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1998 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2004 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2DLayered(texture< short2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2005 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2011 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2DLayered(texture< ushort2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2012 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2018 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2DLayered(texture< short4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2019 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2025 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2DLayered(texture< ushort4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2026 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2038 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2DLayered(texture< int, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2039 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2043 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2DLayered(texture< unsigned, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2046 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2050 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2052 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2DLayered(texture< int1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2053 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2059 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2DLayered(texture< uint1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2060 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2066 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2DLayered(texture< int2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2067 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2073 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2DLayered(texture< uint2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2074 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2080 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2DLayered(texture< int4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2081 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2087 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2DLayered(texture< uint4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2088 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< float, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2171 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< float1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2178 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2180 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< float2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2185 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2187 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< float4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2192 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2200 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2201 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2210 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2212 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< signed char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2213 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2218 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2220 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< unsigned char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2221 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2226 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2228 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< char1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2234 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< uchar1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2242 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2244 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< char2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2245 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2252 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< uchar2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2253 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2260 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< char4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2266 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< uchar4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2274 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2282 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< short, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2283 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2288 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2290 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< unsigned short, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2296 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2298 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< short1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2299 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2304 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2306 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< ushort1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2312 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< short2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2320 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< ushort2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2323 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2328 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2330 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< short4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2331 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2336 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2338 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< ushort4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2339 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2344 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2352 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2353 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2361 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2368 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2370 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2375 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2382 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2384 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2391 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2392 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2396 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2399 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2406 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2410 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2412 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2417 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2425 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2426 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2430 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2432 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2439 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2440 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2446 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2447 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2453 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2454 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2460 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2461 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2468 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2474 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2487 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2488 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2492 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2495 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2501 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2502 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2508 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2509 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2516 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2522 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2523 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2530 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2536 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2537 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2620 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2627 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2629 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2634 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2636 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2641 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2649 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2650 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2659 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2661 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2662 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2667 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2669 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2670 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2675 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2677 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2683 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2691 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2693 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2694 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2701 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2702 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2709 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2715 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2723 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2731 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2732 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2737 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2740 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2745 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2747 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2753 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2755 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2761 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2764 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2769 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2771 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2772 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2777 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2779 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2780 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2785 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2787 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2793 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 67 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 threadIdx; }
# 69 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 blockIdx; }
# 71 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 blockDim; }
# 73 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 gridDim; }
# 75 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const int warpSize; }
# 120 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 121 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 122 "/usr/local/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 123 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset)
# 125 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 126 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 127 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 159 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 160 "/usr/local/cuda/bin/../include/cuda_runtime.h"
event, unsigned
# 161 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 163 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 164 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaEventCreateWithFlags(event, flags);
# 165 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 222 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 223 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 224 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 225 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 227 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 228 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc(ptr, size, flags);
# 229 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 231 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 232 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 233 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 234 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 235 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 237 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 238 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 239 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 241 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 242 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 243 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 244 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 245 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 247 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 248 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 249 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 251 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 253 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 254 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 256 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 257 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 258 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 260 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 261 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 262 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 263 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 264 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags = (0))
# 266 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 267 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size, flags);
# 268 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 270 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 271 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 272 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 273 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 274 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 275 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height)
# 277 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 278 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 279 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 289 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 290 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 291 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 292 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 293 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 294 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 296 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 297 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 298 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 300 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 301 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 302 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 303 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 304 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 305 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 306 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 308 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 309 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 310 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 312 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 313 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 314 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 315 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 316 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 317 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 318 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 320 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 321 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 322 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 324 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 325 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 326 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 327 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 328 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 329 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 330 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 331 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 333 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 334 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 335 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 343 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 344 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 345 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 346 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 347 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 348 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 350 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 351 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 352 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 354 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 355 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 356 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 357 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 358 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 359 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 360 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 362 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 363 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 364 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 366 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 367 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 368 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 369 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 370 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 371 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 372 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 374 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 375 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 376 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 378 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 379 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 380 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 381 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 382 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 383 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 384 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 385 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 387 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 388 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 389 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 391 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 392 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 393 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 395 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 396 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 397 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 424 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 425 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 426 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 427 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 429 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 430 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 431 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 439 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 440 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, char *
# 441 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 443 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 444 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 445 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 472 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 473 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 474 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 475 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 477 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 478 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 479 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 521 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 522 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 523 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 524 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 525 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 526 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 527 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 529 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 530 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 531 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 566 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 567 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 568 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 569 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 570 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 571 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 573 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 574 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 575 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 622 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 623 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 624 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 625 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 626 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 627 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 628 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 629 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 630 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 632 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 633 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 634 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 680 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 681 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 682 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 683 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 684 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 685 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 686 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 687 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 689 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 690 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &(tex.texture< T, dim, readMode> ::channelDesc), width, height, pitch);
# 691 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 722 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 723 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 724 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 725 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 726 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 728 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 729 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 730 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 760 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 761 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 762 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 763 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 765 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 766 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 767 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 769 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 770 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 799 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 800 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 801 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 803 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 804 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 805 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 839 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 840 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 841 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 842 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 844 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 845 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 846 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 900 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 901 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 902 "/usr/local/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 903 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 905 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 906 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 907 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 944 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 945 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 946 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 948 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 949 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 950 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 984 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 985 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 986 "/usr/local/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 987 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 989 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 990 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 991 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 1013 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1014 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1015 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1016 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 1017 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 1019 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1020 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 1021 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 1042 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1043 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1044 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1045 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 1047 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1048 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 1049 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 1051 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 1052 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 46 "/usr/include/bits/stat.h" 3
extern "C" { struct stat {
# 48 "/usr/include/bits/stat.h" 3
__dev_t st_dev;
# 53 "/usr/include/bits/stat.h" 3
__ino_t st_ino;
# 61 "/usr/include/bits/stat.h" 3
__nlink_t st_nlink;
# 62 "/usr/include/bits/stat.h" 3
__mode_t st_mode;
# 64 "/usr/include/bits/stat.h" 3
__uid_t st_uid;
# 65 "/usr/include/bits/stat.h" 3
__gid_t st_gid;
# 67 "/usr/include/bits/stat.h" 3
int __pad0;
# 69 "/usr/include/bits/stat.h" 3
__dev_t st_rdev;
# 74 "/usr/include/bits/stat.h" 3
__off_t st_size;
# 78 "/usr/include/bits/stat.h" 3
__blksize_t st_blksize;
# 80 "/usr/include/bits/stat.h" 3
__blkcnt_t st_blocks;
# 91 "/usr/include/bits/stat.h" 3
timespec st_atim;
# 92 "/usr/include/bits/stat.h" 3
timespec st_mtim;
# 93 "/usr/include/bits/stat.h" 3
timespec st_ctim;
# 106 "/usr/include/bits/stat.h" 3
long __unused[3];
# 115 "/usr/include/bits/stat.h" 3
}; }
# 119 "/usr/include/bits/stat.h" 3
extern "C" { struct stat64 {
# 121 "/usr/include/bits/stat.h" 3
__dev_t st_dev;
# 123 "/usr/include/bits/stat.h" 3
__ino64_t st_ino;
# 124 "/usr/include/bits/stat.h" 3
__nlink_t st_nlink;
# 125 "/usr/include/bits/stat.h" 3
__mode_t st_mode;
# 132 "/usr/include/bits/stat.h" 3
__uid_t st_uid;
# 133 "/usr/include/bits/stat.h" 3
__gid_t st_gid;
# 135 "/usr/include/bits/stat.h" 3
int __pad0;
# 136 "/usr/include/bits/stat.h" 3
__dev_t st_rdev;
# 137 "/usr/include/bits/stat.h" 3
__off_t st_size;
# 143 "/usr/include/bits/stat.h" 3
__blksize_t st_blksize;
# 144 "/usr/include/bits/stat.h" 3
__blkcnt64_t st_blocks;
# 152 "/usr/include/bits/stat.h" 3
timespec st_atim;
# 153 "/usr/include/bits/stat.h" 3
timespec st_mtim;
# 154 "/usr/include/bits/stat.h" 3
timespec st_ctim;
# 167 "/usr/include/bits/stat.h" 3
long __unused[3];
# 171 "/usr/include/bits/stat.h" 3
}; }
# 211 "/usr/include/sys/stat.h" 3
extern "C" int stat(const char *__restrict__ , struct stat *__restrict__ ) throw()
# 212 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1, 2)));
# 216 "/usr/include/sys/stat.h" 3
extern "C" int fstat(int , struct stat * ) throw() __attribute((__nonnull__(2)));
# 230 "/usr/include/sys/stat.h" 3
extern "C" int stat64(const char *__restrict__ , struct stat64 *__restrict__ ) throw()
# 231 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1, 2)));
# 232 "/usr/include/sys/stat.h" 3
extern "C" int fstat64(int , struct stat64 * ) throw() __attribute((__nonnull__(2)));
# 240 "/usr/include/sys/stat.h" 3
extern "C" int fstatat(int , const char *__restrict__ , struct stat *__restrict__ , int ) throw()
# 242 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 255 "/usr/include/sys/stat.h" 3
extern "C" int fstatat64(int , const char *__restrict__ , struct stat64 *__restrict__ , int ) throw()
# 257 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 265 "/usr/include/sys/stat.h" 3
extern "C" int lstat(const char *__restrict__ , struct stat *__restrict__ ) throw()
# 266 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1, 2)));
# 278 "/usr/include/sys/stat.h" 3
extern "C" int lstat64(const char *__restrict__ , struct stat64 *__restrict__ ) throw()
# 280 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1, 2)));
# 286 "/usr/include/sys/stat.h" 3
extern "C" int chmod(const char * , __mode_t ) throw()
# 287 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1)));
# 293 "/usr/include/sys/stat.h" 3
extern "C" int lchmod(const char * , __mode_t ) throw()
# 294 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1)));
# 299 "/usr/include/sys/stat.h" 3
extern "C" int fchmod(int , __mode_t ) throw();
# 305 "/usr/include/sys/stat.h" 3
extern "C" int fchmodat(int , const char * , __mode_t , int ) throw()
# 307 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2)));
# 314 "/usr/include/sys/stat.h" 3
extern "C" __mode_t umask(__mode_t ) throw();
# 319 "/usr/include/sys/stat.h" 3
extern "C" __mode_t getumask() throw();
# 323 "/usr/include/sys/stat.h" 3
extern "C" int mkdir(const char * , __mode_t ) throw()
# 324 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1)));
# 330 "/usr/include/sys/stat.h" 3
extern "C" int mkdirat(int , const char * , __mode_t ) throw()
# 331 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2)));
# 338 "/usr/include/sys/stat.h" 3
extern "C" int mknod(const char * , __mode_t , __dev_t ) throw()
# 339 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1)));
# 345 "/usr/include/sys/stat.h" 3
extern "C" int mknodat(int , const char * , __mode_t , __dev_t ) throw()
# 346 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2)));
# 352 "/usr/include/sys/stat.h" 3
extern "C" int mkfifo(const char * , __mode_t ) throw()
# 353 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(1)));
# 359 "/usr/include/sys/stat.h" 3
extern "C" int mkfifoat(int , const char * , __mode_t ) throw()
# 360 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2)));
# 366 "/usr/include/sys/stat.h" 3
extern "C" int utimensat(int , const char * , const timespec [2], int ) throw()
# 369 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2)));
# 374 "/usr/include/sys/stat.h" 3
extern "C" int futimens(int , const timespec [2]) throw();
# 401 "/usr/include/sys/stat.h" 3
extern "C" int __fxstat(int , int , struct stat * ) throw()
# 402 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(3)));
# 403 "/usr/include/sys/stat.h" 3
extern "C" int __xstat(int , const char * , struct stat * ) throw()
# 404 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 405 "/usr/include/sys/stat.h" 3
extern "C" int __lxstat(int , const char * , struct stat * ) throw()
# 406 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 407 "/usr/include/sys/stat.h" 3
extern "C" int __fxstatat(int , int , const char * , struct stat * , int ) throw()
# 409 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(3, 4)));
# 434 "/usr/include/sys/stat.h" 3
extern "C" int __fxstat64(int , int , struct stat64 * ) throw()
# 435 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(3)));
# 436 "/usr/include/sys/stat.h" 3
extern "C" int __xstat64(int , const char * , struct stat64 * ) throw()
# 437 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 438 "/usr/include/sys/stat.h" 3
extern "C" int __lxstat64(int , const char * , struct stat64 * ) throw()
# 439 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 3)));
# 440 "/usr/include/sys/stat.h" 3
extern "C" int __fxstatat64(int , int , const char * , struct stat64 * , int ) throw()
# 442 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(3, 4)));
# 444 "/usr/include/sys/stat.h" 3
extern "C" int __xmknod(int , const char * , __mode_t , __dev_t * ) throw()
# 445 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(2, 4)));
# 447 "/usr/include/sys/stat.h" 3
extern "C" int __xmknodat(int , int , const char * , __mode_t , __dev_t * ) throw()
# 449 "/usr/include/sys/stat.h" 3
 __attribute((__nonnull__(3, 5)));
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
extern "C" { typedef short _G_int16_t __attribute((__mode__(__HI__))); }
# 54 "/usr/include/_G_config.h" 3
extern "C" { typedef int _G_int32_t __attribute((__mode__(__SI__))); }
# 55 "/usr/include/_G_config.h" 3
extern "C" { typedef unsigned short _G_uint16_t __attribute((__mode__(__HI__))); }
# 56 "/usr/include/_G_config.h" 3
extern "C" { typedef unsigned _G_uint32_t __attribute((__mode__(__SI__))); }
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/va.h" 3
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
char _unused2[(((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(size_t)];
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
extern "C" { typedef __ssize_t __io_read_fn(void * , char * , size_t ); }
# 372 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_write_fn(void * , const char * , size_t ); }
# 381 "/usr/include/libio.h" 3
extern "C" { typedef int __io_seek_fn(void * , __off64_t * , int ); }
# 384 "/usr/include/libio.h" 3
extern "C" { typedef int __io_close_fn(void * ); }
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
extern "C" void _IO_cookie_init(_IO_cookie_file * , int , void * , _IO_cookie_io_functions_t );
# 416 "/usr/include/libio.h" 3
extern "C" int __underflow(_IO_FILE *);
# 417 "/usr/include/libio.h" 3
extern "C" int __uflow(_IO_FILE *);
# 418 "/usr/include/libio.h" 3
extern "C" int __overflow(_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE * );
# 461 "/usr/include/libio.h" 3
extern "C" int _IO_putc(int , _IO_FILE * );
# 462 "/usr/include/libio.h" 3
extern "C" int _IO_feof(_IO_FILE * ) throw();
# 463 "/usr/include/libio.h" 3
extern "C" int _IO_ferror(_IO_FILE * ) throw();
# 465 "/usr/include/libio.h" 3
extern "C" int _IO_peekc_locked(_IO_FILE * );
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
extern "C" int remove(const char * ) throw();
# 177 "/usr/include/stdio.h" 3
extern "C" int rename(const char * , const char * ) throw();
# 182 "/usr/include/stdio.h" 3
extern "C" int renameat(int , const char * , int , const char * ) throw();
# 192 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 202 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64();
# 206 "/usr/include/stdio.h" 3
extern "C" char *tmpnam(char * ) throw();
# 212 "/usr/include/stdio.h" 3
extern "C" char *tmpnam_r(char * ) throw();
# 224 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char * , const char * ) throw()
# 225 "/usr/include/stdio.h" 3
 __attribute((__malloc__));
# 234 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE * );
# 239 "/usr/include/stdio.h" 3
extern "C" int fflush(FILE * );
# 249 "/usr/include/stdio.h" 3
extern "C" int fflush_unlocked(FILE * );
# 259 "/usr/include/stdio.h" 3
extern "C" int fcloseall();
# 269 "/usr/include/stdio.h" 3
extern "C" FILE *fopen(const char *__restrict__ , const char *__restrict__ );
# 275 "/usr/include/stdio.h" 3
extern "C" FILE *freopen(const char *__restrict__ , const char *__restrict__ , FILE *__restrict__ );
# 294 "/usr/include/stdio.h" 3
extern "C" FILE *fopen64(const char *__restrict__ , const char *__restrict__ );
# 296 "/usr/include/stdio.h" 3
extern "C" FILE *freopen64(const char *__restrict__ , const char *__restrict__ , FILE *__restrict__ );
# 303 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int , const char * ) throw();
# 309 "/usr/include/stdio.h" 3
extern "C" FILE *fopencookie(void *__restrict__ , const char *__restrict__ , _IO_cookie_io_functions_t ) throw();
# 316 "/usr/include/stdio.h" 3
extern "C" FILE *fmemopen(void * , size_t , const char * ) throw();
# 322 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char ** , size_t * ) throw();
# 329 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__ , char *__restrict__ ) throw();
# 333 "/usr/include/stdio.h" 3
extern "C" int setvbuf(FILE *__restrict__ , char *__restrict__ , int , size_t ) throw();
# 340 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__ , char *__restrict__ , size_t ) throw();
# 344 "/usr/include/stdio.h" 3
extern "C" void setlinebuf(FILE * ) throw();
# 353 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__ , const char *__restrict__ , ...);
# 359 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__ , ...);
# 361 "/usr/include/stdio.h" 3
extern "C" int sprintf(char *__restrict__ , const char *__restrict__ , ...) throw();
# 368 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__ , const char *__restrict__ , __gnuc_va_list );
# 374 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__ , __gnuc_va_list );
# 376 "/usr/include/stdio.h" 3
extern "C" int vsprintf(char *__restrict__ , const char *__restrict__ , __gnuc_va_list ) throw();
# 383 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__ , size_t , const char *__restrict__ , ...) throw()
# 385 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 3, 4)));
# 387 "/usr/include/stdio.h" 3
extern "C" int vsnprintf(char *__restrict__ , size_t , const char *__restrict__ , __gnuc_va_list ) throw()
# 389 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 3, 0)));
# 396 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__ , const char *__restrict__ , __gnuc_va_list ) throw()
# 398 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 0)));
# 399 "/usr/include/stdio.h" 3
extern "C" int __asprintf(char **__restrict__ , const char *__restrict__ , ...) throw()
# 401 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 3)));
# 402 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **__restrict__ , const char *__restrict__ , ...) throw()
# 404 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 3)));
# 414 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int , const char *__restrict__ , __gnuc_va_list )
# 416 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 0)));
# 417 "/usr/include/stdio.h" 3
extern "C" int dprintf(int , const char *__restrict__ , ...)
# 418 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 3)));
# 427 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__ , const char *__restrict__ , ...);
# 433 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__ , ...);
# 435 "/usr/include/stdio.h" 3
extern "C" int sscanf(const char *__restrict__ , const char *__restrict__ , ...) throw();
# 473 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__ , const char *__restrict__ , __gnuc_va_list )
# 475 "/usr/include/stdio.h" 3
 __attribute((__format__(__scanf__, 2, 0)));
# 481 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__ , __gnuc_va_list )
# 482 "/usr/include/stdio.h" 3
 __attribute((__format__(__scanf__, 1, 0)));
# 485 "/usr/include/stdio.h" 3
extern "C" int vsscanf(const char *__restrict__ , const char *__restrict__ , __gnuc_va_list ) throw()
# 487 "/usr/include/stdio.h" 3
 __attribute((__format__(__scanf__, 2, 0)));
# 533 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE * );
# 534 "/usr/include/stdio.h" 3
extern "C" int getc(FILE * );
# 540 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 552 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE * );
# 553 "/usr/include/stdio.h" 3
extern "C" int getchar_unlocked();
# 563 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE * );
# 575 "/usr/include/stdio.h" 3
extern "C" int fputc(int , FILE * );
# 576 "/usr/include/stdio.h" 3
extern "C" int putc(int , FILE * );
# 582 "/usr/include/stdio.h" 3
extern "C" int putchar(int );
# 596 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int , FILE * );
# 604 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int , FILE * );
# 605 "/usr/include/stdio.h" 3
extern "C" int putchar_unlocked(int );
# 612 "/usr/include/stdio.h" 3
extern "C" int getw(FILE * );
# 615 "/usr/include/stdio.h" 3
extern "C" int putw(int , FILE * );
# 624 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__ , int , FILE *__restrict__ );
# 632 "/usr/include/stdio.h" 3
extern "C" char *gets(char * );
# 642 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__ , int , FILE *__restrict__ );
# 658 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__ , size_t *__restrict__ , int , FILE *__restrict__ );
# 661 "/usr/include/stdio.h" 3
extern "C" __ssize_t getdelim(char **__restrict__ , size_t *__restrict__ , int , FILE *__restrict__ );
# 671 "/usr/include/stdio.h" 3
extern "C" __ssize_t getline(char **__restrict__ , size_t *__restrict__ , FILE *__restrict__ );
# 682 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__ , FILE *__restrict__ );
# 688 "/usr/include/stdio.h" 3
extern "C" int puts(const char * );
# 695 "/usr/include/stdio.h" 3
extern "C" int ungetc(int , FILE * );
# 702 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *__restrict__ , size_t , size_t , FILE *__restrict__ );
# 708 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__ , size_t , size_t , FILE *__restrict__ );
# 719 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__ , FILE *__restrict__ );
# 730 "/usr/include/stdio.h" 3
extern "C" size_t fread_unlocked(void *__restrict__ , size_t , size_t , FILE *__restrict__ );
# 732 "/usr/include/stdio.h" 3
extern "C" size_t fwrite_unlocked(const void *__restrict__ , size_t , size_t , FILE *__restrict__ );
# 742 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE * , long , int );
# 747 "/usr/include/stdio.h" 3
extern "C" long ftell(FILE * );
# 752 "/usr/include/stdio.h" 3
extern "C" void rewind(FILE * );
# 766 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE * , __off_t , int );
# 771 "/usr/include/stdio.h" 3
extern "C" __off_t ftello(FILE * );
# 791 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__ , fpos_t *__restrict__ );
# 796 "/usr/include/stdio.h" 3
extern "C" int fsetpos(FILE * , const fpos_t * );
# 811 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE * , __off64_t , int );
# 812 "/usr/include/stdio.h" 3
extern "C" __off64_t ftello64(FILE * );
# 813 "/usr/include/stdio.h" 3
extern "C" int fgetpos64(FILE *__restrict__ , fpos64_t *__restrict__ );
# 814 "/usr/include/stdio.h" 3
extern "C" int fsetpos64(FILE * , const fpos64_t * );
# 819 "/usr/include/stdio.h" 3
extern "C" void clearerr(FILE * ) throw();
# 821 "/usr/include/stdio.h" 3
extern "C" int feof(FILE * ) throw();
# 823 "/usr/include/stdio.h" 3
extern "C" int ferror(FILE * ) throw();
# 828 "/usr/include/stdio.h" 3
extern "C" void clearerr_unlocked(FILE * ) throw();
# 829 "/usr/include/stdio.h" 3
extern "C" int feof_unlocked(FILE * ) throw();
# 830 "/usr/include/stdio.h" 3
extern "C" int ferror_unlocked(FILE * ) throw();
# 839 "/usr/include/stdio.h" 3
extern "C" void perror(const char * );
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
# 28 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const sys_errlist[]; }
# 31 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int _sys_nerr; }
# 32 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const _sys_errlist[]; }
# 851 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE * ) throw();
# 856 "/usr/include/stdio.h" 3
extern "C" int fileno_unlocked(FILE * ) throw();
# 866 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char * , const char * );
# 872 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE * );
# 878 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char * ) throw();
# 884 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char * );
# 889 "/usr/include/stdio.h" 3
struct obstack;
# 892 "/usr/include/stdio.h" 3
extern "C" int obstack_printf(obstack *__restrict__ , const char *__restrict__ , ...) throw()
# 894 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 3)));
# 895 "/usr/include/stdio.h" 3
extern "C" int obstack_vprintf(obstack *__restrict__ , const char *__restrict__ , __gnuc_va_list ) throw()
# 898 "/usr/include/stdio.h" 3
 __attribute((__format__(__printf__, 2, 0)));
# 906 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE * ) throw();
# 910 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE * ) throw();
# 913 "/usr/include/stdio.h" 3
extern "C" void funlockfile(FILE * ) throw();
# 44 "/usr/include/bits/uio.h" 3
extern "C" { struct iovec {
# 46 "/usr/include/bits/uio.h" 3
void *iov_base;
# 47 "/usr/include/bits/uio.h" 3
size_t iov_len;
# 48 "/usr/include/bits/uio.h" 3
}; }
# 165 "/usr/include/bits/fcntl.h" 3
extern "C" { struct flock {
# 167 "/usr/include/bits/fcntl.h" 3
short l_type;
# 168 "/usr/include/bits/fcntl.h" 3
short l_whence;
# 170 "/usr/include/bits/fcntl.h" 3
__off_t l_start;
# 171 "/usr/include/bits/fcntl.h" 3
__off_t l_len;
# 176 "/usr/include/bits/fcntl.h" 3
__pid_t l_pid;
# 177 "/usr/include/bits/fcntl.h" 3
}; }
# 180 "/usr/include/bits/fcntl.h" 3
extern "C" { struct flock64 {
# 182 "/usr/include/bits/fcntl.h" 3
short l_type;
# 183 "/usr/include/bits/fcntl.h" 3
short l_whence;
# 184 "/usr/include/bits/fcntl.h" 3
__off64_t l_start;
# 185 "/usr/include/bits/fcntl.h" 3
__off64_t l_len;
# 186 "/usr/include/bits/fcntl.h" 3
__pid_t l_pid;
# 187 "/usr/include/bits/fcntl.h" 3
}; }
# 192 "/usr/include/bits/fcntl.h" 3
enum __pid_type {
# 194 "/usr/include/bits/fcntl.h" 3
F_OWNER_TID,
# 195 "/usr/include/bits/fcntl.h" 3
F_OWNER_PID,
# 196 "/usr/include/bits/fcntl.h" 3
F_OWNER_PGRP,
# 197 "/usr/include/bits/fcntl.h" 3
F_OWNER_GID = 2
# 198 "/usr/include/bits/fcntl.h" 3
};
# 201 "/usr/include/bits/fcntl.h" 3
extern "C" { struct f_owner_ex {
# 203 "/usr/include/bits/fcntl.h" 3
__pid_type type;
# 204 "/usr/include/bits/fcntl.h" 3
__pid_t pid;
# 205 "/usr/include/bits/fcntl.h" 3
}; }
# 268 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t readahead(int , __off64_t , size_t ) throw();
# 273 "/usr/include/bits/fcntl.h" 3
extern "C" int sync_file_range(int , __off64_t , __off64_t , unsigned );
# 278 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t vmsplice(int , const iovec * , size_t , unsigned );
# 282 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t splice(int , __off64_t * , int , __off64_t * , size_t , unsigned );
# 287 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t tee(int , int , size_t , unsigned );
# 292 "/usr/include/bits/fcntl.h" 3
extern "C" int fallocate(int , int , __off_t , __off_t );
# 303 "/usr/include/bits/fcntl.h" 3
extern "C" int fallocate64(int , int , __off64_t , __off64_t );
# 110 "/usr/include/fcntl.h" 3
extern "C" int fcntl(int , int , ...);
# 119 "/usr/include/fcntl.h" 3
extern "C" int open(const char * , int , ...) __attribute((__nonnull__(1)));
# 129 "/usr/include/fcntl.h" 3
extern "C" int open64(const char * , int , ...) __attribute((__nonnull__(1)));
# 143 "/usr/include/fcntl.h" 3
extern "C" int openat(int , const char * , int , ...)
# 144 "/usr/include/fcntl.h" 3
 __attribute((__nonnull__(2)));
# 154 "/usr/include/fcntl.h" 3
extern "C" int openat64(int , const char * , int , ...)
# 155 "/usr/include/fcntl.h" 3
 __attribute((__nonnull__(2)));
# 165 "/usr/include/fcntl.h" 3
extern "C" int creat(const char * , __mode_t ) __attribute((__nonnull__(1)));
# 175 "/usr/include/fcntl.h" 3
extern "C" int creat64(const char * , __mode_t ) __attribute((__nonnull__(1)));
# 194 "/usr/include/fcntl.h" 3
extern "C" int lockf(int , int , __off_t );
# 203 "/usr/include/fcntl.h" 3
extern "C" int lockf64(int , int , __off64_t );
# 211 "/usr/include/fcntl.h" 3
extern "C" int posix_fadvise(int , __off_t , __off_t , int ) throw();
# 223 "/usr/include/fcntl.h" 3
extern "C" int posix_fadvise64(int , __off64_t , __off64_t , int ) throw();
# 233 "/usr/include/fcntl.h" 3
extern "C" int posix_fallocate(int , __off_t , __off_t );
# 244 "/usr/include/fcntl.h" 3
extern "C" int posix_fallocate64(int , __off64_t , __off64_t );
# 268 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 275 "/usr/include/unistd.h" 3
extern "C" { typedef __socklen_t socklen_t; }
# 288 "/usr/include/unistd.h" 3
extern "C" int access(const char * , int ) throw() __attribute((__nonnull__(1)));
# 293 "/usr/include/unistd.h" 3
extern "C" int euidaccess(const char * , int ) throw()
# 294 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 297 "/usr/include/unistd.h" 3
extern "C" int eaccess(const char * , int ) throw()
# 298 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 305 "/usr/include/unistd.h" 3
extern "C" int faccessat(int , const char * , int , int ) throw()
# 306 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2)));
# 331 "/usr/include/unistd.h" 3
extern "C" __off_t lseek(int , __off_t , int ) throw();
# 342 "/usr/include/unistd.h" 3
extern "C" __off64_t lseek64(int , __off64_t , int ) throw();
# 350 "/usr/include/unistd.h" 3
extern "C" int close(int );
# 357 "/usr/include/unistd.h" 3
extern "C" ssize_t read(int , void * , size_t );
# 363 "/usr/include/unistd.h" 3
extern "C" ssize_t write(int , const void * , size_t );
# 373 "/usr/include/unistd.h" 3
extern "C" ssize_t pread(int , void * , size_t , __off_t );
# 381 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite(int , const void * , size_t , __off_t );
# 401 "/usr/include/unistd.h" 3
extern "C" ssize_t pread64(int , void * , size_t , __off64_t );
# 405 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite64(int , const void * , size_t , __off64_t );
# 414 "/usr/include/unistd.h" 3
extern "C" int pipe(int [2]) throw();
# 419 "/usr/include/unistd.h" 3
extern "C" int pipe2(int [2], int ) throw();
# 429 "/usr/include/unistd.h" 3
extern "C" unsigned alarm(unsigned ) throw();
# 441 "/usr/include/unistd.h" 3
extern "C" unsigned sleep(unsigned );
# 449 "/usr/include/unistd.h" 3
extern "C" __useconds_t ualarm(__useconds_t , __useconds_t ) throw();
# 457 "/usr/include/unistd.h" 3
extern "C" int usleep(__useconds_t );
# 466 "/usr/include/unistd.h" 3
extern "C" int pause();
# 470 "/usr/include/unistd.h" 3
extern "C" int chown(const char * , __uid_t , __gid_t ) throw()
# 471 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 475 "/usr/include/unistd.h" 3
extern "C" int fchown(int , __uid_t , __gid_t ) throw();
# 480 "/usr/include/unistd.h" 3
extern "C" int lchown(const char * , __uid_t , __gid_t ) throw()
# 481 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 488 "/usr/include/unistd.h" 3
extern "C" int fchownat(int , const char * , __uid_t , __gid_t , int ) throw()
# 490 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2)));
# 494 "/usr/include/unistd.h" 3
extern "C" int chdir(const char * ) throw() __attribute((__nonnull__(1)));
# 498 "/usr/include/unistd.h" 3
extern "C" int fchdir(int ) throw();
# 508 "/usr/include/unistd.h" 3
extern "C" char *getcwd(char * , size_t ) throw();
# 514 "/usr/include/unistd.h" 3
extern "C" char *get_current_dir_name() throw();
# 522 "/usr/include/unistd.h" 3
extern "C" char *getwd(char * ) throw()
# 523 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1))) __attribute((__deprecated__));
# 528 "/usr/include/unistd.h" 3
extern "C" int dup(int ) throw();
# 531 "/usr/include/unistd.h" 3
extern "C" int dup2(int , int ) throw();
# 536 "/usr/include/unistd.h" 3
extern "C" int dup3(int , int , int ) throw();
# 540 "/usr/include/unistd.h" 3
extern "C" { extern char **__environ; }
# 542 "/usr/include/unistd.h" 3
extern "C" { extern char **environ; }
# 548 "/usr/include/unistd.h" 3
extern "C" int execve(const char * , char *const [], char *const []) throw()
# 549 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 554 "/usr/include/unistd.h" 3
extern "C" int fexecve(int , char *const [], char *const []) throw()
# 555 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2)));
# 560 "/usr/include/unistd.h" 3
extern "C" int execv(const char * , char *const []) throw()
# 561 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 565 "/usr/include/unistd.h" 3
extern "C" int execle(const char * , const char * , ...) throw()
# 566 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 570 "/usr/include/unistd.h" 3
extern "C" int execl(const char * , const char * , ...) throw()
# 571 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 575 "/usr/include/unistd.h" 3
extern "C" int execvp(const char * , char *const []) throw()
# 576 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 581 "/usr/include/unistd.h" 3
extern "C" int execlp(const char * , const char * , ...) throw()
# 582 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 587 "/usr/include/unistd.h" 3
extern "C" int execvpe(const char * , char *const [], char *const []) throw()
# 589 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 595 "/usr/include/unistd.h" 3
extern "C" int nice(int ) throw();
# 600 "/usr/include/unistd.h" 3
extern "C" void _exit(int ) __attribute((__noreturn__));
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
extern "C" long pathconf(const char * , int ) throw()
# 610 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 613 "/usr/include/unistd.h" 3
extern "C" long fpathconf(int , int ) throw();
# 616 "/usr/include/unistd.h" 3
extern "C" long sysconf(int ) throw();
# 620 "/usr/include/unistd.h" 3
extern "C" size_t confstr(int , char * , size_t ) throw();
# 625 "/usr/include/unistd.h" 3
extern "C" __pid_t getpid() throw();
# 628 "/usr/include/unistd.h" 3
extern "C" __pid_t getppid() throw();
# 633 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgrp() throw();
# 643 "/usr/include/unistd.h" 3
extern "C" __pid_t __getpgid(__pid_t ) throw();
# 645 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgid(__pid_t ) throw();
# 652 "/usr/include/unistd.h" 3
extern "C" int setpgid(__pid_t , __pid_t ) throw();
# 669 "/usr/include/unistd.h" 3
extern "C" int setpgrp() throw();
# 686 "/usr/include/unistd.h" 3
extern "C" __pid_t setsid() throw();
# 690 "/usr/include/unistd.h" 3
extern "C" __pid_t getsid(__pid_t ) throw();
# 694 "/usr/include/unistd.h" 3
extern "C" __uid_t getuid() throw();
# 697 "/usr/include/unistd.h" 3
extern "C" __uid_t geteuid() throw();
# 700 "/usr/include/unistd.h" 3
extern "C" __gid_t getgid() throw();
# 703 "/usr/include/unistd.h" 3
extern "C" __gid_t getegid() throw();
# 708 "/usr/include/unistd.h" 3
extern "C" int getgroups(int , __gid_t []) throw();
# 712 "/usr/include/unistd.h" 3
extern "C" int group_member(__gid_t ) throw();
# 719 "/usr/include/unistd.h" 3
extern "C" int setuid(__uid_t ) throw();
# 724 "/usr/include/unistd.h" 3
extern "C" int setreuid(__uid_t , __uid_t ) throw();
# 729 "/usr/include/unistd.h" 3
extern "C" int seteuid(__uid_t ) throw();
# 736 "/usr/include/unistd.h" 3
extern "C" int setgid(__gid_t ) throw();
# 741 "/usr/include/unistd.h" 3
extern "C" int setregid(__gid_t , __gid_t ) throw();
# 746 "/usr/include/unistd.h" 3
extern "C" int setegid(__gid_t ) throw();
# 752 "/usr/include/unistd.h" 3
extern "C" int getresuid(__uid_t * , __uid_t * , __uid_t * ) throw();
# 757 "/usr/include/unistd.h" 3
extern "C" int getresgid(__gid_t * , __gid_t * , __gid_t * ) throw();
# 762 "/usr/include/unistd.h" 3
extern "C" int setresuid(__uid_t , __uid_t , __uid_t ) throw();
# 767 "/usr/include/unistd.h" 3
extern "C" int setresgid(__gid_t , __gid_t , __gid_t ) throw();
# 775 "/usr/include/unistd.h" 3
extern "C" __pid_t fork() throw();
# 783 "/usr/include/unistd.h" 3
extern "C" __pid_t vfork() throw();
# 789 "/usr/include/unistd.h" 3
extern "C" char *ttyname(int ) throw();
# 793 "/usr/include/unistd.h" 3
extern "C" int ttyname_r(int , char * , size_t ) throw()
# 794 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2)));
# 798 "/usr/include/unistd.h" 3
extern "C" int isatty(int ) throw();
# 804 "/usr/include/unistd.h" 3
extern "C" int ttyslot() throw();
# 809 "/usr/include/unistd.h" 3
extern "C" int link(const char * , const char * ) throw()
# 810 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 815 "/usr/include/unistd.h" 3
extern "C" int linkat(int , const char * , int , const char * , int ) throw()
# 817 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2, 4)));
# 822 "/usr/include/unistd.h" 3
extern "C" int symlink(const char * , const char * ) throw()
# 823 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 828 "/usr/include/unistd.h" 3
extern "C" ssize_t readlink(const char *__restrict__ , char *__restrict__ , size_t ) throw()
# 830 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 835 "/usr/include/unistd.h" 3
extern "C" int symlinkat(const char * , int , const char * ) throw()
# 836 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 3)));
# 839 "/usr/include/unistd.h" 3
extern "C" ssize_t readlinkat(int , const char *__restrict__ , char *__restrict__ , size_t ) throw()
# 841 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2, 3)));
# 845 "/usr/include/unistd.h" 3
extern "C" int unlink(const char * ) throw() __attribute((__nonnull__(1)));
# 849 "/usr/include/unistd.h" 3
extern "C" int unlinkat(int , const char * , int ) throw()
# 850 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(2)));
# 854 "/usr/include/unistd.h" 3
extern "C" int rmdir(const char * ) throw() __attribute((__nonnull__(1)));
# 858 "/usr/include/unistd.h" 3
extern "C" __pid_t tcgetpgrp(int ) throw();
# 861 "/usr/include/unistd.h" 3
extern "C" int tcsetpgrp(int , __pid_t ) throw();
# 868 "/usr/include/unistd.h" 3
extern "C" char *getlogin();
# 876 "/usr/include/unistd.h" 3
extern "C" int getlogin_r(char * , size_t ) __attribute((__nonnull__(1)));
# 881 "/usr/include/unistd.h" 3
extern "C" int setlogin(const char * ) throw() __attribute((__nonnull__(1)));
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; }
# 73 "/usr/include/getopt.h" 3
extern "C" { extern int optind; }
# 78 "/usr/include/getopt.h" 3
extern "C" { extern int opterr; }
# 82 "/usr/include/getopt.h" 3
extern "C" { extern int optopt; }
# 152 "/usr/include/getopt.h" 3
extern "C" int getopt(int , char *const * , const char * ) throw();
# 898 "/usr/include/unistd.h" 3
extern "C" int gethostname(char * , size_t ) throw() __attribute((__nonnull__(1)));
# 905 "/usr/include/unistd.h" 3
extern "C" int sethostname(const char * , size_t ) throw()
# 906 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 910 "/usr/include/unistd.h" 3
extern "C" int sethostid(long ) throw();
# 916 "/usr/include/unistd.h" 3
extern "C" int getdomainname(char * , size_t ) throw()
# 917 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 918 "/usr/include/unistd.h" 3
extern "C" int setdomainname(const char * , size_t ) throw()
# 919 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 925 "/usr/include/unistd.h" 3
extern "C" int vhangup() throw();
# 928 "/usr/include/unistd.h" 3
extern "C" int revoke(const char * ) throw() __attribute((__nonnull__(1)));
# 936 "/usr/include/unistd.h" 3
extern "C" int profil(unsigned short * , size_t , size_t , unsigned ) throw()
# 938 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 944 "/usr/include/unistd.h" 3
extern "C" int acct(const char * ) throw();
# 948 "/usr/include/unistd.h" 3
extern "C" char *getusershell() throw();
# 949 "/usr/include/unistd.h" 3
extern "C" void endusershell() throw();
# 950 "/usr/include/unistd.h" 3
extern "C" void setusershell() throw();
# 956 "/usr/include/unistd.h" 3
extern "C" int daemon(int , int ) throw();
# 963 "/usr/include/unistd.h" 3
extern "C" int chroot(const char * ) throw() __attribute((__nonnull__(1)));
# 967 "/usr/include/unistd.h" 3
extern "C" char *getpass(const char * ) __attribute((__nonnull__(1)));
# 976 "/usr/include/unistd.h" 3
extern "C" int fsync(int );
# 983 "/usr/include/unistd.h" 3
extern "C" long gethostid();
# 986 "/usr/include/unistd.h" 3
extern "C" void sync() throw();
# 992 "/usr/include/unistd.h" 3
extern "C" int getpagesize() throw() __attribute((const));
# 997 "/usr/include/unistd.h" 3
extern "C" int getdtablesize() throw();
# 1007 "/usr/include/unistd.h" 3
extern "C" int truncate(const char * , __off_t ) throw()
# 1008 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 1019 "/usr/include/unistd.h" 3
extern "C" int truncate64(const char * , __off64_t ) throw()
# 1020 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1)));
# 1026 "/usr/include/unistd.h" 3
extern "C" int ftruncate(int , __off_t ) throw();
# 1036 "/usr/include/unistd.h" 3
extern "C" int ftruncate64(int , __off64_t ) throw();
# 1047 "/usr/include/unistd.h" 3
extern "C" int brk(void * ) throw();
# 1053 "/usr/include/unistd.h" 3
extern "C" void *sbrk(intptr_t ) throw();
# 1068 "/usr/include/unistd.h" 3
extern "C" long syscall(long , ...) throw();
# 1122 "/usr/include/unistd.h" 3
extern "C" int fdatasync(int );
# 1130 "/usr/include/unistd.h" 3
extern "C" char *crypt(const char * , const char * ) throw()
# 1131 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 1135 "/usr/include/unistd.h" 3
extern "C" void encrypt(char * , int ) throw() __attribute((__nonnull__(1)));
# 1142 "/usr/include/unistd.h" 3
extern "C" void swab(const void *__restrict__ , void *__restrict__ , ssize_t ) throw()
# 1143 "/usr/include/unistd.h" 3
 __attribute((__nonnull__(1, 2)));
# 1151 "/usr/include/unistd.h" 3
extern "C" char *ctermid(char * ) throw();
# 49 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned char uint8_t; }
# 50 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned short uint16_t; }
# 52 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned uint32_t; }
# 56 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uint64_t; }
# 66 "/usr/include/stdint.h" 3
extern "C" { typedef signed char int_least8_t; }
# 67 "/usr/include/stdint.h" 3
extern "C" { typedef short int_least16_t; }
# 68 "/usr/include/stdint.h" 3
extern "C" { typedef int int_least32_t; }
# 70 "/usr/include/stdint.h" 3
extern "C" { typedef long int_least64_t; }
# 77 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned char uint_least8_t; }
# 78 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned short uint_least16_t; }
# 79 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned uint_least32_t; }
# 81 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uint_least64_t; }
# 91 "/usr/include/stdint.h" 3
extern "C" { typedef signed char int_fast8_t; }
# 93 "/usr/include/stdint.h" 3
extern "C" { typedef long int_fast16_t; }
# 94 "/usr/include/stdint.h" 3
extern "C" { typedef long int_fast32_t; }
# 95 "/usr/include/stdint.h" 3
extern "C" { typedef long int_fast64_t; }
# 104 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned char uint_fast8_t; }
# 106 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uint_fast16_t; }
# 107 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uint_fast32_t; }
# 108 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uint_fast64_t; }
# 123 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uintptr_t; }
# 135 "/usr/include/stdint.h" 3
extern "C" { typedef long intmax_t; }
# 136 "/usr/include/stdint.h" 3
extern "C" { typedef unsigned long uintmax_t; }
# 283 "/usr/include/inttypes.h" 3
extern "C" { typedef
# 280 "/usr/include/inttypes.h" 3
struct {
# 281 "/usr/include/inttypes.h" 3
long quot;
# 282 "/usr/include/inttypes.h" 3
long rem;
# 283 "/usr/include/inttypes.h" 3
} imaxdiv_t; }
# 298 "/usr/include/inttypes.h" 3
extern "C" intmax_t imaxabs(intmax_t ) throw() __attribute((const));
# 301 "/usr/include/inttypes.h" 3
extern "C" imaxdiv_t imaxdiv(intmax_t , intmax_t ) throw()
# 302 "/usr/include/inttypes.h" 3
 __attribute((const));
# 305 "/usr/include/inttypes.h" 3
extern "C" intmax_t strtoimax(const char *__restrict__ , char **__restrict__ , int ) throw();
# 309 "/usr/include/inttypes.h" 3
extern "C" uintmax_t strtoumax(const char *__restrict__ , char **__restrict__ , int ) throw();
# 313 "/usr/include/inttypes.h" 3
extern "C" intmax_t wcstoimax(const wchar_t *__restrict__ , wchar_t **__restrict__ , int ) throw();
# 318 "/usr/include/inttypes.h" 3
extern "C" uintmax_t wcstoumax(const wchar_t *__restrict__ , wchar_t **__restrict__ , int ) throw();
# 47 "/usr/include/bits/errno.h" 3
extern "C" int *__errno_location() throw() __attribute((const));
# 55 "/usr/include/errno.h" 3
extern "C" { extern char *program_invocation_name, *program_invocation_short_name; }
# 69 "/usr/include/errno.h" 3
extern "C" { typedef int error_t; }
# 54 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { typedef
# 50 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
struct {
# 51 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long key;
# 52 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long pos;
# 53 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long len;
# 54 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
} video_index_entry; }
# 61 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { typedef
# 57 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
struct {
# 58 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long pos;
# 59 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long len;
# 60 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long tot;
# 61 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
} audio_index_entry; }
# 85 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { typedef
# 63 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
struct track_s {
# 66 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_fmt;
# 67 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_chans;
# 68 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_rate;
# 69 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_bits;
# 70 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long mp3rate;
# 72 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long audio_strn;
# 73 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long audio_bytes;
# 74 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long audio_chunks;
# 76 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
char audio_tag[4];
# 77 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long audio_posc;
# 78 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long audio_posb;
# 80 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_codech_off;
# 81 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long a_codecf_off;
# 83 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
audio_index_entry *audio_index;
# 85 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
} track_t; }
# 126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { typedef
# 88 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
struct {
# 90 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long fdes;
# 91 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long mode;
# 93 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long width;
# 94 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long height;
# 95 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
double fps;
# 96 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
char compressor[8];
# 97 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
char compressor2[8];
# 98 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long video_strn;
# 99 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long video_frames;
# 100 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
char video_tag[4];
# 101 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long video_pos;
# 104 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long max_len;
# 106 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
track_t track[8];
# 108 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long pos;
# 109 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long n_idx;
# 110 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long max_idx;
# 112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long v_codech_off;
# 113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long v_codecf_off;
# 115 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned char (*idx)[16];
# 116 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
video_index_entry *video_index;
# 118 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long last_pos;
# 119 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long last_len;
# 120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
int must_use_index;
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long movi_start;
# 123 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
int anum;
# 124 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
int aptr;
# 126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
} avi_t; }
# 195 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" avi_t *AVI_open_output_file(char * );
# 196 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" void AVI_set_video(avi_t * , int , int , double , char * );
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" void AVI_set_audio(avi_t * , int , long , int , int , long );
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_write_frame(avi_t * , char * , long , int );
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_dup_frame(avi_t * );
# 200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_write_audio(avi_t * , char * , long );
# 201 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_append_audio(avi_t * , char * , long );
# 202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_bytes_remain(avi_t * );
# 203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_close(avi_t * );
# 204 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_bytes_written(avi_t * );
# 206 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" avi_t *AVI_open_input_file(char * , int );
# 207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" avi_t *AVI_open_fd(int , int );
# 208 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int avi_parse_input_file(avi_t * , int );
# 209 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_mp3rate(avi_t * );
# 210 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_video_frames(avi_t * );
# 211 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_video_width(avi_t * );
# 212 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_video_height(avi_t * );
# 213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" double AVI_frame_rate(avi_t * );
# 214 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" char *AVI_video_compressor(avi_t * );
# 216 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_audio_channels(avi_t * );
# 217 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_audio_bits(avi_t * );
# 218 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_audio_format(avi_t * );
# 219 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_rate(avi_t * );
# 220 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_bytes(avi_t * );
# 221 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_chunks(avi_t * );
# 223 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_max_video_chunk(avi_t * );
# 225 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_frame_size(avi_t * , long );
# 226 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_size(avi_t * , long );
# 227 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_seek_start(avi_t * );
# 228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_set_video_position(avi_t * , long );
# 229 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_get_video_position(avi_t * , long );
# 230 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_read_frame(avi_t * , char * , int * );
# 232 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_set_audio_position(avi_t * , long );
# 233 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_set_audio_bitrate(avi_t * , long );
# 235 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_read_audio(avi_t * , char * , long );
# 237 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_codech_offset(avi_t * );
# 238 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_audio_codecf_offset(avi_t * );
# 239 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_video_codech_offset(avi_t * );
# 240 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" long AVI_video_codecf_offset(avi_t * );
# 242 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_read_data(avi_t * , char * , long , char * , long , long * );
# 246 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" void AVI_print_error(char * );
# 247 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" char *AVI_strerror();
# 248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" char *AVI_syserror();
# 250 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_scan(char * );
# 251 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_dump(char * , int );
# 253 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" char *AVI_codec2str(short );
# 254 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_file_check(char * );
# 256 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" void AVI_info(avi_t * );
# 257 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" uint64_t AVI_max_size();
# 258 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int avi_update_header(avi_t * );
# 260 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_set_audio_track(avi_t * , int );
# 261 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_get_audio_track(avi_t * );
# 262 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" int AVI_audio_tracks(avi_t * );
# 264 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { struct riff_struct {
# 266 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned char id[4];
# 267 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long len;
# 268 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned char wave_id[4];
# 269 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
}; }
# 272 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { struct chunk_struct {
# 274 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned char id[4];
# 275 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long len;
# 276 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
}; }
# 278 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { struct common_struct {
# 280 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned short wFormatTag;
# 281 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned short wChannels;
# 282 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long dwSamplesPerSec;
# 283 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned long dwAvgBytesPerSec;
# 284 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned short wBlockAlign;
# 285 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
unsigned short wBitsPerSample;
# 286 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
}; }
# 288 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { struct wave_header {
# 290 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
riff_struct riff;
# 291 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
chunk_struct format;
# 292 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
common_struct common;
# 293 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
chunk_struct data;
# 294 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
}; }
# 298 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
extern "C" { struct AVIStreamHeader {
# 299 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long fccType;
# 300 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long fccHandler;
# 301 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwFlags;
# 302 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwPriority;
# 303 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwInitialFrames;
# 304 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwScale;
# 305 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwRate;
# 306 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwStart;
# 307 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwLength;
# 308 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwSuggestedBufferSize;
# 309 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwQuality;
# 310 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
long dwSampleSize;
# 311 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avilib.h"
}; }
# 16 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avimod.h"
extern "C" float *chop_flip_image(char * , int , int , int , int , int );
# 23 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/avimod.h"
extern "C" float *get_frame(avi_t * , int , int , int , int );
# 149 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned long long CUdeviceptr; }
# 156 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 157 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 158 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 159 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 160 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 161 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 162 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 163 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 164 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 165 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 169 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 167 "/usr/local/cuda/bin/../include/cuda.h"
struct CUuuid_st {
# 168 "/usr/local/cuda/bin/../include/cuda.h"
char bytes[16];
# 169 "/usr/local/cuda/bin/../include/cuda.h"
} CUuuid; }
# 185 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 174 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 175 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 176 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 177 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 178 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_BLOCKING_SYNC = 4,
# 179 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC = 4,
# 180 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK = 7,
# 181 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST,
# 182 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 183 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_PRIMARY = 32,
# 184 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 63
# 185 "/usr/local/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 194 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 191 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 192 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 193 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DISABLE_TIMING
# 194 "/usr/local/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 208 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 199 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 200 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 201 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 202 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 203 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 204 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 205 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 206 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 207 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 208 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 218 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 213 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 214 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 215 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 216 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 217 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER
# 218 "/usr/local/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 226 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 223 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 224 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 225 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 226 "/usr/local/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 280 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 231 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 232 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 233 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 234 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 235 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 236 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 237 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 238 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 240 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 241 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 242 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 243 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 244 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 245 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 246 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 247 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 248 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 249 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 250 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 251 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 252 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 253 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 254 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 255 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 256 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 257 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 258 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 259 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 260 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH,
# 261 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT,
# 262 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS,
# 263 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27,
# 264 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 265 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 266 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 267 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 268 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 269 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 270 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 271 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER,
# 272 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE,
# 273 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH,
# 274 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE,
# 275 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR,
# 276 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT,
# 277 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING,
# 278 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH,
# 279 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS
# 280 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 296 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 285 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 286 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 287 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 288 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 289 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 290 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 291 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 292 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 293 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 294 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 295 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 296 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 306 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 301 "/usr/local/cuda/bin/../include/cuda.h"
enum CUpointer_attribute_enum {
# 302 "/usr/local/cuda/bin/../include/cuda.h"
CU_POINTER_ATTRIBUTE_CONTEXT = 1,
# 303 "/usr/local/cuda/bin/../include/cuda.h"
CU_POINTER_ATTRIBUTE_MEMORY_TYPE,
# 304 "/usr/local/cuda/bin/../include/cuda.h"
CU_POINTER_ATTRIBUTE_DEVICE_POINTER,
# 305 "/usr/local/cuda/bin/../include/cuda.h"
CU_POINTER_ATTRIBUTE_HOST_POINTER
# 306 "/usr/local/cuda/bin/../include/cuda.h"
} CUpointer_attribute; }
# 361 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 311 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 317 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 324 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 330 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 335 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 340 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 349 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 358 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 360 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 361 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 370 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 366 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 367 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 369 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 370 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 380 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 375 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 376 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 377 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 378 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY,
# 379 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_UNIFIED
# 380 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 390 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 385 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 386 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 387 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 388 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED,
# 389 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE_PROCESS
# 390 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 482 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 395 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 401 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 414 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 421 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 429 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 437 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 445 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 453 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 460 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 467 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 473 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 480 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 482 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 495 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 487 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 489 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 490 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 491 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 492 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 493 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20,
# 494 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_21
# 495 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 506 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 500 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 502 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 504 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 506 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 516 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 511 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 512 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE,
# 513 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY,
# 514 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD,
# 515 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST = 4
# 516 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 525 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 521 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 522 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 523 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 524 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 525 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 537 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 530 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 531 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 532 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 533 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 534 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 535 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 536 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 537 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 546 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 542 "/usr/local/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 543 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 544 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 545 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE
# 546 "/usr/local/cuda/bin/../include/cuda.h"
} CUlimit; }
# 843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 551 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 557 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 563 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 569 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 575 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 580 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 586 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PROFILER_DISABLED,
# 591 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PROFILER_NOT_INITIALIZED,
# 596 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STARTED,
# 601 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STOPPED,
# 606 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 612 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 619 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 629 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 638 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 643 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 648 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 654 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 659 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 667 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 672 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 677 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 683 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 689 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 695 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 701 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 708 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_IN_USE,
# 713 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 718 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 723 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 728 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 733 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 740 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 747 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 756 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 767 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 778 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 789 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 795 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 802 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
# 811 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
# 817 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PEER_MEMORY_ALREADY_REGISTERED,
# 823 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PEER_MEMORY_NOT_REGISTERED,
# 830 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE,
# 837 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_IS_DESTROYED,
# 842 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 843 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 912 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 891 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 892 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 893 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 895 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 896 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 897 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 898 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 899 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 901 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 902 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 904 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 905 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 906 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 907 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 908 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 910 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 911 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 912 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 945 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 917 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 918 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 919 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 920 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcZ;
# 921 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcLOD;
# 922 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 923 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 924 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 925 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 926 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 927 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 928 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 930 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 931 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 932 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstZ;
# 933 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstLOD;
# 934 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 935 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 936 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 937 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 938 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 939 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 940 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 942 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 943 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 944 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 945 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 978 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 950 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_PEER_st {
# 951 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 952 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 953 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcZ;
# 954 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcLOD;
# 955 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 956 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 957 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 958 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 959 "/usr/local/cuda/bin/../include/cuda.h"
CUcontext srcContext;
# 960 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 961 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 963 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 964 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 965 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstZ;
# 966 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstLOD;
# 967 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 968 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 969 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 970 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 971 "/usr/local/cuda/bin/../include/cuda.h"
CUcontext dstContext;
# 972 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 973 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 975 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 976 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 977 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 978 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D_PEER; }
# 990 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 983 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR_st {
# 985 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 986 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 988 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 989 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 990 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 1004 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 995 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR_st {
# 997 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 998 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 999 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 1001 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 1002 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 1003 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 1004 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 1117 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned );
# 1144 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int * );
# 1182 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice * , int );
# 1208 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int * );
# 1237 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char * , int , CUdevice );
# 1266 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int * , int * , CUdevice );
# 1294 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem_v2(size_t * , CUdevice );
# 1354 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop * , CUdevice );
# 1462 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int * , CUdevice_attribute , CUdevice );
# 1568 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate_v2(CUcontext * , unsigned , CUdevice );
# 1606 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy_v2(CUcontext );
# 1655 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext * , unsigned );
# 1690 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext );
# 1725 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent_v2(CUcontext );
# 1758 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent_v2(CUcontext * );
# 1785 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetCurrent(CUcontext );
# 1804 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetCurrent(CUcontext * );
# 1833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice * );
# 1861 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 1922 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit , size_t );
# 1955 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t * , CUlimit );
# 1996 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetCacheConfig(CUfunc_cache * );
# 2044 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetCacheConfig(CUfunc_cache );
# 2079 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetApiVersion(CUcontext , unsigned * );
# 2128 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule * , const char * );
# 2162 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule * , const void * );
# 2241 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule * , const void * , unsigned , CUjit_option * , void ** );
# 2281 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule * , const void * );
# 2306 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule );
# 2336 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction * , CUmodule , const char * );
# 2370 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal_v2(CUdeviceptr * , size_t * , CUmodule , const char * );
# 2404 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref * , CUmodule , const char * );
# 2435 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref * , CUmodule , const char * );
# 2478 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo_v2(size_t * , size_t * );
# 2511 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc_v2(CUdeviceptr * , size_t );
# 2572 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch_v2(CUdeviceptr * , size_t * , size_t , size_t , unsigned );
# 2601 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree_v2(CUdeviceptr );
# 2634 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange_v2(CUdeviceptr * , size_t * , CUdeviceptr );
# 2680 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost_v2(void ** , size_t );
# 2710 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void * );
# 2792 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void ** , size_t , unsigned );
# 2830 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr * , void * , unsigned );
# 2855 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned * , void * );
# 2918 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostRegister(void * , size_t , unsigned );
# 2941 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostUnregister(void * );
# 2977 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy(CUdeviceptr , CUdeviceptr , size_t );
# 3010 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyPeer(CUdeviceptr , CUcontext , CUdeviceptr , CUcontext , size_t );
# 3048 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD_v2(CUdeviceptr , const void * , size_t );
# 3081 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH_v2(void * , CUdeviceptr , size_t );
# 3114 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD_v2(CUdeviceptr , CUdeviceptr , size_t );
# 3148 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA_v2(CUarray , size_t , CUdeviceptr , size_t );
# 3184 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD_v2(CUdeviceptr , CUarray , size_t , size_t );
# 3218 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA_v2(CUarray , size_t , const void * , size_t );
# 3252 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH_v2(void * , CUarray , size_t , size_t );
# 3290 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA_v2(CUarray , size_t , CUarray , size_t , size_t );
# 3450 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D * );
# 3608 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D * );
# 3775 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D * );
# 3806 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER * );
# 3846 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAsync(CUdeviceptr , CUdeviceptr , size_t , CUstream );
# 3877 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyPeerAsync(CUdeviceptr , CUcontext , CUdeviceptr , CUcontext , size_t , CUstream );
# 3919 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr , const void * , size_t , CUstream );
# 3959 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync_v2(void * , CUdeviceptr , size_t , CUstream );
# 3996 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr , CUdeviceptr , size_t , CUstream );
# 4038 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync_v2(CUarray , size_t , const void * , size_t , CUstream );
# 4080 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync_v2(void * , CUarray , size_t , size_t , CUstream );
# 4251 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D * , CUstream );
# 4426 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D * , CUstream );
# 4451 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER * , CUstream );
# 4486 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8_v2(CUdeviceptr , unsigned char , size_t );
# 4519 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16_v2(CUdeviceptr , unsigned short , size_t );
# 4552 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32_v2(CUdeviceptr , unsigned , size_t );
# 4590 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8_v2(CUdeviceptr , size_t , unsigned char , size_t , size_t );
# 4628 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16_v2(CUdeviceptr , size_t , unsigned short , size_t , size_t );
# 4666 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32_v2(CUdeviceptr , size_t , unsigned , size_t , size_t );
# 4703 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8Async(CUdeviceptr , unsigned char , size_t , CUstream );
# 4740 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16Async(CUdeviceptr , unsigned short , size_t , CUstream );
# 4776 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32Async(CUdeviceptr , unsigned , size_t , CUstream );
# 4818 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8Async(CUdeviceptr , size_t , unsigned char , size_t , size_t , CUstream );
# 4860 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16Async(CUdeviceptr , size_t , unsigned short , size_t , size_t , CUstream );
# 4902 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32Async(CUdeviceptr , size_t , unsigned , size_t , size_t , CUstream );
# 5005 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate_v2(CUarray * , const CUDA_ARRAY_DESCRIPTOR * );
# 5038 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR * , CUarray );
# 5069 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray );
# 5177 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate_v2(CUarray * , const CUDA_ARRAY3D_DESCRIPTOR * );
# 5213 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR * , CUarray );
# 5422 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuPointerGetAttribute(void * , CUpointer_attribute , CUdeviceptr );
# 5459 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream * , unsigned );
# 5501 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamWaitEvent(CUstream , CUevent , unsigned );
# 5525 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream );
# 5550 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream );
# 5577 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy_v2(CUstream );
# 5625 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent * , unsigned );
# 5663 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent , CUstream );
# 5694 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent );
# 5728 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent );
# 5756 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy_v2(CUevent );
# 5799 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float * , CUevent , CUevent );
# 5862 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int * , CUfunction_attribute , CUfunction );
# 5903 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction , CUfunc_cache );
# 6019 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchKernel(CUfunction , unsigned , unsigned , unsigned , unsigned , unsigned , unsigned , unsigned , CUstream , void ** , void ** );
# 6075 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction , int , int , int );
# 6109 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction , unsigned );
# 6141 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction , unsigned );
# 6174 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction , int , unsigned );
# 6207 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction , int , float );
# 6242 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction , int , void * , unsigned );
# 6279 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction );
# 6318 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction , int , int );
# 6362 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction , int , int , CUstream );
# 6387 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction , int , CUtexref );
# 6428 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref , CUarray , unsigned );
# 6466 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress_v2(size_t * , CUtexref , CUdeviceptr , size_t );
# 6507 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D_v2(CUtexref , const CUDA_ARRAY_DESCRIPTOR * , CUdeviceptr , size_t );
# 6536 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref , CUarray_format , int );
# 6576 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref , int , CUaddress_mode );
# 6609 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref , CUfilter_mode );
# 6641 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref , unsigned );
# 6667 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress_v2(CUdeviceptr * , CUtexref );
# 6693 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray * , CUtexref );
# 6719 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode * , CUtexref , int );
# 6743 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode * , CUtexref );
# 6769 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format * , int * , CUtexref );
# 6792 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned * , CUtexref );
# 6826 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref * );
# 6846 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref );
# 6884 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref , CUarray , unsigned );
# 6905 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray * , CUsurfref );
# 6946 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceCanAccessPeer(int * , CUdevice , CUdevice );
# 6998 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxEnablePeerAccess(CUcontext , unsigned );
# 7031 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDisablePeerAccess(CUcontext );
# 7095 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemPeerRegister(CUdeviceptr , CUcontext , unsigned );
# 7130 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemPeerUnregister(CUdeviceptr , CUcontext );
# 7181 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemPeerGetDevicePointer(CUdeviceptr * , CUdeviceptr , CUcontext , unsigned );
# 7222 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource );
# 7260 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray * , CUgraphicsResource , unsigned , unsigned );
# 7294 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr * , size_t * , CUgraphicsResource );
# 7335 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource , unsigned );
# 7373 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned , CUgraphicsResource * , CUstream );
# 7408 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned , CUgraphicsResource * , CUstream );
# 7412 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void ** , const CUuuid * );
# 30 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
typedef
# 21 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
struct params_common_change {
# 27 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_frame;
# 28 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int frame_no;
# 30 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
} params_common_change;
# 262 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
typedef
# 38 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
struct params_common {
# 48 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int sSize;
# 49 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int tSize;
# 50 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int maxMove;
# 51 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float alpha;
# 57 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int no_frames;
# 58 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int frame_rows;
# 59 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int frame_cols;
# 60 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int frame_elem;
# 61 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int frame_mem;
# 67 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int endoPoints;
# 68 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int endo_mem;
# 70 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *endoRow;
# 71 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *endoCol;
# 72 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *tEndoRowLoc;
# 73 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *tEndoColLoc;
# 75 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_endoRow;
# 76 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_endoCol;
# 77 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tEndoRowLoc;
# 78 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tEndoColLoc;
# 80 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_endoT;
# 85 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int epiPoints;
# 86 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int epi_mem;
# 88 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *epiRow;
# 89 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *epiCol;
# 90 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *tEpiRowLoc;
# 91 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *tEpiColLoc;
# 93 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_epiRow;
# 94 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_epiCol;
# 95 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tEpiRowLoc;
# 96 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tEpiColLoc;
# 98 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_epiT;
# 104 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int allPoints;
# 110 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_rows;
# 111 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_cols;
# 112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_elem;
# 113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_mem;
# 119 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_rows;
# 120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_cols;
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_elem;
# 122 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_mem;
# 128 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int conv_rows;
# 129 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int conv_cols;
# 130 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int conv_elem;
# 131 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int conv_mem;
# 132 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int ioffset;
# 133 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int joffset;
# 143 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_add_rows;
# 144 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_add_cols;
# 145 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_rows;
# 146 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_cols;
# 147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_elem;
# 148 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_mem;
# 154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_rows;
# 155 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_cols;
# 156 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_elem;
# 157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_mem;
# 158 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_rowlow;
# 159 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_rowhig;
# 160 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_collow;
# 161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel_colhig;
# 167 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel2_rowlow;
# 168 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel2_rowhig;
# 169 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel2_collow;
# 170 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_pad_cumv_sel2_colhig;
# 171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_rows;
# 172 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_cols;
# 173 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_elem;
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_mem;
# 180 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_rows;
# 181 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_cols;
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_elem;
# 183 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_mem;
# 184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_rowlow;
# 185 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_rowhig;
# 186 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_collow;
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel_colhig;
# 193 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel2_rowlow;
# 194 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel2_rowhig;
# 195 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel2_collow;
# 196 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub_cumh_sel2_colhig;
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub2_rows;
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub2_cols;
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub2_elem;
# 200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sub2_mem;
# 210 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_rows;
# 211 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_cols;
# 212 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_elem;
# 213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_mem;
# 219 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_sub2_rows;
# 220 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_sub2_cols;
# 221 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_sub2_elem;
# 222 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in2_sqr_sub2_mem;
# 228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_sqr_rows;
# 229 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_sqr_cols;
# 230 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_sqr_elem;
# 231 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_sqr_mem;
# 237 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int tMask_rows;
# 238 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int tMask_cols;
# 239 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int tMask_elem;
# 240 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int tMask_mem;
# 246 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_rows;
# 247 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_cols;
# 248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_elem;
# 249 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_mem;
# 255 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_rows;
# 256 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_cols;
# 257 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_elem;
# 258 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_mem;
# 259 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_ioffset;
# 260 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int mask_conv_joffset;
# 262 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
} params_common;
# 381 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
typedef
# 270 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
struct params_unique {
# 276 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_Row;
# 277 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_Col;
# 278 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tRowLoc;
# 279 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int *d_tColLoc;
# 280 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_T;
# 286 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int point_no;
# 292 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
int in_pointer;
# 298 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2;
# 304 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_conv;
# 305 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in_mod;
# 315 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_pad_cumv;
# 321 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_pad_cumv_sel;
# 327 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_sub_cumh;
# 333 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_sub_cumh_sel;
# 339 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_sub2;
# 349 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_sqr;
# 355 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in2_sqr_sub2;
# 361 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_in_sqr;
# 367 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_tMask;
# 373 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_mask;
# 379 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
float *d_mask_conv;
# 381 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/define.c"
} params_unique;
# 25 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
params_common_change common_change;
# 26 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
static params_common_change d_common_change;
# 28 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
params_common common;
# 29 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
static params_common d_common;
# 31 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
params_unique unique[51];
# 32 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
static params_unique d_unique[51];
# 7 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/kernel.cuh"
void kernel() ;
# 46 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
int main(int argc, char *argv[]) {
# 53 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
dim3 threads;
# 54 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
dim3 blocks;
# 57 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
int i;
# 58 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
int frames_processed;
# 61 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
char *video_file_name;
# 62 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
avi_t *frames;
# 63 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
float *frame;
# 70 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
video_file_name = ((char *)("data/hwt.avi"));
# 71 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
frames = ((avi_t *)AVI_open_input_file(video_file_name, 1));
# 72 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
if (frames == (__null)) {
# 73 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
AVI_print_error((char *)("Error with AVI_open_input_file"));
# 74 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
return -1;
# 75 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 78 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.no_frames) = (AVI_video_frames(frames));
# 79 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.frame_rows) = AVI_video_height(frames);
# 80 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.frame_cols) = AVI_video_width(frames);
# 81 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.frame_elem) = ((common.frame_rows) * (common.frame_cols));
# 82 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.frame_mem) = (sizeof(float) * (common.frame_elem));
# 85 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common_change.d_frame)), common.frame_mem);
# 91 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
if (argc != 2) {
# 92 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("ERROR: missing argument (number of frames to processed) or too many arguments\n");
# 93 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
return 0;
# 94 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
} else
# 95 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
{
# 96 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
frames_processed = atoi(argv[1]);
# 97 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
if ((frames_processed < 0) || (frames_processed > (common.no_frames))) {
# 98 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("ERROR: %d is an incorrect number of frames specified, select in the range of 0-%d\n", frames_processed, common.no_frames);
# 99 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
return 0;
# 100 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 101 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 111 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.sSize) = 40;
# 112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tSize) = 25;
# 113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.maxMove) = 10;
# 114 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.alpha) = ((0.8699999999999999956));
# 120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.endoPoints) = 20;
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.endo_mem) = (sizeof(int) * (common.endoPoints));
# 123 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.endoRow) = ((int *)malloc(common.endo_mem));
# 124 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[0]) = 369;
# 125 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[1]) = 400;
# 126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[2]) = 429;
# 127 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[3]) = 452;
# 128 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[4]) = 476;
# 129 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[5]) = 486;
# 130 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[6]) = 479;
# 131 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[7]) = 458;
# 132 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[8]) = 433;
# 133 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[9]) = 404;
# 134 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[10]) = 374;
# 135 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[11]) = 346;
# 136 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[12]) = 318;
# 137 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[13]) = 294;
# 138 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[14]) = 277;
# 139 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[15]) = 269;
# 140 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[16]) = 275;
# 141 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[17]) = 287;
# 142 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[18]) = 311;
# 143 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoRow)[19]) = 339;
# 144 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_endoRow)), common.endo_mem);
# 145 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.d_endoRow, common.endoRow, common.endo_mem, cudaMemcpyHostToDevice);
# 147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.endoCol) = ((int *)malloc(common.endo_mem));
# 148 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[0]) = 408;
# 149 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[1]) = 406;
# 150 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[2]) = 397;
# 151 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[3]) = 383;
# 152 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[4]) = 354;
# 153 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[5]) = 322;
# 154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[6]) = 294;
# 155 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[7]) = 270;
# 156 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[8]) = 250;
# 157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[9]) = 237;
# 158 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[10]) = 235;
# 159 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[11]) = 241;
# 160 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[12]) = 254;
# 161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[13]) = 273;
# 162 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[14]) = 300;
# 163 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[15]) = 328;
# 164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[16]) = 356;
# 165 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[17]) = 383;
# 166 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[18]) = 401;
# 167 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.endoCol)[19]) = 411;
# 168 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_endoCol)), common.endo_mem);
# 169 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.d_endoCol, common.endoCol, common.endo_mem, cudaMemcpyHostToDevice);
# 171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tEndoRowLoc) = ((int *)malloc((common.endo_mem) * (common.no_frames)));
# 172 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_tEndoRowLoc)), (common.endo_mem) * (common.no_frames));
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tEndoColLoc) = ((int *)malloc((common.endo_mem) * (common.no_frames)));
# 175 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_tEndoColLoc)), (common.endo_mem) * (common.no_frames));
# 181 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.epiPoints) = 31;
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.epi_mem) = (sizeof(int) * (common.epiPoints));
# 184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.epiRow) = ((int *)malloc(common.epi_mem));
# 185 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[0]) = 390;
# 186 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[1]) = 419;
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[2]) = 448;
# 188 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[3]) = 474;
# 189 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[4]) = 501;
# 190 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[5]) = 519;
# 191 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[6]) = 535;
# 192 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[7]) = 542;
# 193 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[8]) = 543;
# 194 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[9]) = 538;
# 195 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[10]) = 528;
# 196 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[11]) = 511;
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[12]) = 491;
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[13]) = 466;
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[14]) = 438;
# 200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[15]) = 406;
# 201 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[16]) = 376;
# 202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[17]) = 347;
# 203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[18]) = 318;
# 204 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[19]) = 291;
# 205 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[20]) = 275;
# 206 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[21]) = 259;
# 207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[22]) = 256;
# 208 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[23]) = 252;
# 209 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[24]) = 252;
# 210 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[25]) = 257;
# 211 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[26]) = 266;
# 212 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[27]) = 283;
# 213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[28]) = 305;
# 214 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[29]) = 331;
# 215 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiRow)[30]) = 360;
# 216 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_epiRow)), common.epi_mem);
# 217 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.d_epiRow, common.epiRow, common.epi_mem, cudaMemcpyHostToDevice);
# 219 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.epiCol) = ((int *)malloc(common.epi_mem));
# 220 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[0]) = 457;
# 221 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[1]) = 454;
# 222 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[2]) = 446;
# 223 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[3]) = 431;
# 224 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[4]) = 411;
# 225 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[5]) = 388;
# 226 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[6]) = 361;
# 227 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[7]) = 331;
# 228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[8]) = 301;
# 229 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[9]) = 273;
# 230 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[10]) = 243;
# 231 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[11]) = 218;
# 232 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[12]) = 196;
# 233 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[13]) = 178;
# 234 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[14]) = 166;
# 235 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[15]) = 157;
# 236 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[16]) = 155;
# 237 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[17]) = 165;
# 238 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[18]) = 177;
# 239 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[19]) = 197;
# 240 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[20]) = 218;
# 241 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[21]) = 248;
# 242 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[22]) = 276;
# 243 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[23]) = 304;
# 244 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[24]) = 333;
# 245 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[25]) = 361;
# 246 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[26]) = 391;
# 247 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[27]) = 415;
# 248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[28]) = 434;
# 249 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[29]) = 448;
# 250 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
((common.epiCol)[30]) = 455;
# 251 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_epiCol)), common.epi_mem);
# 252 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.d_epiCol, common.epiCol, common.epi_mem, cudaMemcpyHostToDevice);
# 254 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tEpiRowLoc) = ((int *)malloc((common.epi_mem) * (common.no_frames)));
# 255 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_tEpiRowLoc)), (common.epi_mem) * (common.no_frames));
# 257 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tEpiColLoc) = ((int *)malloc((common.epi_mem) * (common.no_frames)));
# 258 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_tEpiColLoc)), (common.epi_mem) * (common.no_frames));
# 264 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.allPoints) = 51;
# 271 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_rows) = (((common.tSize) + 1) + (common.tSize));
# 272 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_cols) = (common.in_rows);
# 273 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_elem) = ((common.in_rows) * (common.in_cols));
# 274 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_mem) = (sizeof(float) * (common.in_elem));
# 281 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_endoT)), (common.in_mem) * (common.endoPoints));
# 282 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(common.d_epiT)), (common.in_mem) * (common.epiPoints));
# 288 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.endoPoints); i++) {
# 289 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).point_no) = i;
# 290 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_Row) = (common.d_endoRow);
# 291 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_Col) = (common.d_endoCol);
# 292 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_tRowLoc) = (common.d_tEndoRowLoc);
# 293 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_tColLoc) = (common.d_tEndoColLoc);
# 294 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_T) = (common.d_endoT);
# 295 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 296 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = (common.endoPoints); i < (common.allPoints); i++) {
# 297 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).point_no) = (i - (common.endoPoints));
# 298 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_Row) = (common.d_epiRow);
# 299 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_Col) = (common.d_epiCol);
# 300 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_tRowLoc) = (common.d_tEpiRowLoc);
# 301 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_tColLoc) = (common.d_tEpiColLoc);
# 302 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).d_T) = (common.d_epiT);
# 303 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 310 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 311 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(((unique)[i]).in_pointer) = ((((unique)[i]).point_no) * (common.in_elem));
# 312 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 319 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_rows) = ((2 * (common.sSize)) + 1);
# 320 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_cols) = ((2 * (common.sSize)) + 1);
# 321 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_elem) = ((common.in2_rows) * (common.in2_cols));
# 322 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_mem) = (sizeof(float) * (common.in2_elem));
# 325 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 326 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2)), common.in2_mem);
# 327 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 334 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.conv_rows) = (((common.in_rows) + (common.in2_rows)) - 1);
# 335 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.conv_cols) = (((common.in_cols) + (common.in2_cols)) - 1);
# 336 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.conv_elem) = ((common.conv_rows) * (common.conv_cols));
# 337 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.conv_mem) = (sizeof(float) * (common.conv_elem));
# 338 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.ioffset) = 0;
# 339 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.joffset) = 0;
# 342 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 343 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_conv)), common.conv_mem);
# 344 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 355 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_add_rows) = (common.in_rows);
# 356 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_add_cols) = (common.in_cols);
# 358 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_rows) = ((common.in2_rows) + (2 * (common.in2_pad_add_rows)));
# 359 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_cols) = ((common.in2_cols) + (2 * (common.in2_pad_add_cols)));
# 360 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_elem) = ((common.in2_pad_cumv_rows) * (common.in2_pad_cumv_cols));
# 361 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_mem) = (sizeof(float) * (common.in2_pad_cumv_elem));
# 364 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 365 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_pad_cumv)), common.in2_pad_cumv_mem);
# 366 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 373 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_rowlow) = (1 + (common.in_rows));
# 374 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_rowhig) = ((common.in2_pad_cumv_rows) - 1);
# 375 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_collow) = 1;
# 376 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_colhig) = (common.in2_pad_cumv_cols);
# 377 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_rows) = (((common.in2_pad_cumv_sel_rowhig) - (common.in2_pad_cumv_sel_rowlow)) + 1);
# 378 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_cols) = (((common.in2_pad_cumv_sel_colhig) - (common.in2_pad_cumv_sel_collow)) + 1);
# 379 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_elem) = ((common.in2_pad_cumv_sel_rows) * (common.in2_pad_cumv_sel_cols));
# 380 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel_mem) = (sizeof(float) * (common.in2_pad_cumv_sel_elem));
# 383 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 384 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_pad_cumv_sel)), common.in2_pad_cumv_sel_mem);
# 385 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 392 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel2_rowlow) = 1;
# 393 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel2_rowhig) = (((common.in2_pad_cumv_rows) - (common.in_rows)) - 1);
# 394 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel2_collow) = 1;
# 395 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_pad_cumv_sel2_colhig) = (common.in2_pad_cumv_cols);
# 396 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_rows) = (((common.in2_pad_cumv_sel2_rowhig) - (common.in2_pad_cumv_sel2_rowlow)) + 1);
# 397 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_cols) = (((common.in2_pad_cumv_sel2_colhig) - (common.in2_pad_cumv_sel2_collow)) + 1);
# 398 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_elem) = ((common.in2_sub_cumh_rows) * (common.in2_sub_cumh_cols));
# 399 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_mem) = (sizeof(float) * (common.in2_sub_cumh_elem));
# 402 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 403 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub_cumh)), common.in2_sub_cumh_mem);
# 404 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 411 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_rowlow) = 1;
# 412 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_rowhig) = (common.in2_sub_cumh_rows);
# 413 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_collow) = (1 + (common.in_cols));
# 414 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_colhig) = ((common.in2_sub_cumh_cols) - 1);
# 415 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_rows) = (((common.in2_sub_cumh_sel_rowhig) - (common.in2_sub_cumh_sel_rowlow)) + 1);
# 416 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_cols) = (((common.in2_sub_cumh_sel_colhig) - (common.in2_sub_cumh_sel_collow)) + 1);
# 417 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_elem) = ((common.in2_sub_cumh_sel_rows) * (common.in2_sub_cumh_sel_cols));
# 418 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel_mem) = (sizeof(float) * (common.in2_sub_cumh_sel_elem));
# 421 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 422 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub_cumh_sel)), common.in2_sub_cumh_sel_mem);
# 423 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 430 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel2_rowlow) = 1;
# 431 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel2_rowhig) = (common.in2_sub_cumh_rows);
# 432 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel2_collow) = 1;
# 433 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub_cumh_sel2_colhig) = (((common.in2_sub_cumh_cols) - (common.in_cols)) - 1);
# 434 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub2_rows) = (((common.in2_sub_cumh_sel2_rowhig) - (common.in2_sub_cumh_sel2_rowlow)) + 1);
# 435 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub2_cols) = (((common.in2_sub_cumh_sel2_colhig) - (common.in2_sub_cumh_sel2_collow)) + 1);
# 436 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub2_elem) = ((common.in2_sub2_rows) * (common.in2_sub2_cols));
# 437 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sub2_mem) = (sizeof(float) * (common.in2_sub2_elem));
# 440 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 441 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub2)), common.in2_sub2_mem);
# 442 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 453 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_rows) = (common.in2_rows);
# 454 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_cols) = (common.in2_cols);
# 455 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_elem) = (common.in2_elem);
# 456 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_mem) = (common.in2_mem);
# 459 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 460 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sqr)), common.in2_sqr_mem);
# 461 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 468 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_sub2_rows) = (common.in2_sub2_rows);
# 469 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_sub2_cols) = (common.in2_sub2_cols);
# 470 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_sub2_elem) = (common.in2_sub2_elem);
# 471 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in2_sqr_sub2_mem) = (common.in2_sub2_mem);
# 474 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 475 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sqr_sub2)), common.in2_sqr_sub2_mem);
# 476 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 483 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_sqr_rows) = (common.in_rows);
# 484 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_sqr_cols) = (common.in_cols);
# 485 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_sqr_elem) = (common.in_elem);
# 486 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.in_sqr_mem) = (common.in_mem);
# 489 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 490 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in_sqr)), common.in_sqr_mem);
# 491 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 498 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tMask_rows) = (((common.in_rows) + (((common.sSize) + 1) + (common.sSize))) - 1);
# 499 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tMask_cols) = (common.tMask_rows);
# 500 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tMask_elem) = ((common.tMask_rows) * (common.tMask_cols));
# 501 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.tMask_mem) = (sizeof(float) * (common.tMask_elem));
# 504 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 505 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_tMask)), common.tMask_mem);
# 506 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 513 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_rows) = (common.maxMove);
# 514 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_cols) = (common.mask_rows);
# 515 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_elem) = ((common.mask_rows) * (common.mask_cols));
# 516 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_mem) = (sizeof(float) * (common.mask_elem));
# 523 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_rows) = (common.tMask_rows);
# 524 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_cols) = (common.tMask_cols);
# 525 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_elem) = ((common.mask_conv_rows) * (common.mask_conv_cols));
# 526 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_mem) = (sizeof(float) * (common.mask_conv_elem));
# 527 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_ioffset) = (((common.mask_rows) - 1) / 2);
# 528 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
if ((((common.mask_rows) - 1) % 2) > (0.5)) {
# 529 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_ioffset) = ((common.mask_conv_ioffset) + 1);
# 530 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 531 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_joffset) = (((common.mask_cols) - 1) / 2);
# 532 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
if ((((common.mask_cols) - 1) % 2) > (0.5)) {
# 533 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(common.mask_conv_joffset) = ((common.mask_conv_joffset) + 1);
# 534 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 537 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 538 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_mask_conv)), common.mask_conv_mem);
# 539 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 550 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(threads.x) = (512);
# 551 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(threads.y) = (1);
# 552 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(blocks.x) = (common.allPoints);
# 553 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
(blocks.y) = (1);
# 559 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpyToSymbol(d_common, &common, sizeof(params_common));
# 560 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpyToSymbol(d_unique, &unique, sizeof(params_unique) * (51));
# 566 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("frame progress: ");
# 567 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
fflush(__null);
# 573 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for ((common_change.frame_no) = 0; (common_change.frame_no) < frames_processed; (common_change.frame_no)++) {
# 576 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
frame = get_frame(frames, common_change.frame_no, 0, 0, 1);
# 583 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common_change.d_frame, frame, common.frame_mem, cudaMemcpyHostToDevice);
# 584 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpyToSymbol(d_common_change, &common_change, sizeof(params_common_change));
# 587 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaConfigureCall(blocks, threads) ? ((void)0) : kernel();
# 590 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(frame);
# 593 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("%d ", common_change.frame_no);
# 594 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
fflush(__null);
# 596 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 602 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("\n");
# 603 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
fflush(__null);
# 609 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.tEndoRowLoc, common.d_tEndoRowLoc, (common.endo_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 610 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.tEndoColLoc, common.d_tEndoColLoc, (common.endo_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 612 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.tEpiRowLoc, common.d_tEpiRowLoc, (common.epi_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 613 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaMemcpy(common.tEpiColLoc, common.d_tEpiColLoc, (common.epi_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 624 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common_change.d_frame);
# 627 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.endoRow);
# 628 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.endoCol);
# 629 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.tEndoRowLoc);
# 630 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.tEndoColLoc);
# 632 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_endoRow);
# 633 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_endoCol);
# 634 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_tEndoRowLoc);
# 635 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_tEndoColLoc);
# 637 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_endoT);
# 640 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.epiRow);
# 641 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.epiCol);
# 642 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.tEpiRowLoc);
# 643 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
free(common.tEpiColLoc);
# 645 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_epiRow);
# 646 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_epiCol);
# 647 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_tEpiRowLoc);
# 648 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_tEpiColLoc);
# 650 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(common.d_epiT);
# 656 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 657 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2);
# 659 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_conv);
# 660 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_pad_cumv);
# 661 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_pad_cumv_sel);
# 662 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_sub_cumh);
# 663 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_sub_cumh_sel);
# 664 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_sub2);
# 665 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_sqr);
# 666 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in2_sqr_sub2);
# 667 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_in_sqr);
# 669 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_tMask);
# 670 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
cudaFree(((unique)[i]).d_mask_conv);
# 671 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 673 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
printf("TEST PASSED\n"); return 0;
# 675 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/main.cu"
}
# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c"
# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c" 1
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 74 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
template <typename T>
static inline void *__cudaAddressOf(T &val)
{
    return (void *)(&(const_cast<char &>(reinterpret_cast<const volatile char &>(val))));
}
# 103 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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
# 147 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 980 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 981 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 3051 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 3052 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 4765 "/usr/local/cuda/bin/../include/math_functions.h" 3
inline double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

inline double rcbrt(double a)
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

inline double sinpi(double a)
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

inline double cospi(double a)
{
  int n;

  if (__isnan(a)) {
    return a + a;
  }
  if (__isinf(a)) {
    return cos (a);
  }
  if (fabs(a) > 9.0071992547409920e+015) {
    a = 0.0;
  }
  a = remquo (a, 0.5, &n);
  a = a * 3.1415926535897931e+0;
  n++;
  if (n & 1) {
    a = cos (a);
  } else {
    a = sin (a);
  }
  if (n & 2) {
    a = -a;
  }
  if (a == 0.0) {
    a = fabs(a);
  }
  return a;
}

inline double erfinv(double a)
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

inline double erfcinv(double a)
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

inline float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}

inline float rcbrtf(float a)
{
  return (float)rcbrt((double)a);
}

inline float sinpif(float a)
{
  return (float)sinpi((double)a);
}

inline float cospif(float a)
{
  return (float)cospi((double)a);
}

inline float erfinvf(float a)
{
  return (float)erfinv((double)a);
}

inline float erfcinvf(float a)
{
  return (float)erfcinv((double)a);
}







inline int min(int a, int b)
{
  return a < b ? a : b;
}

inline unsigned int umin(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

inline long long int llmin(long long int a, long long int b)
{
  return a < b ? a : b;
}

inline unsigned long long int ullmin(unsigned long long int a, unsigned long long int b)
{
  return a < b ? a : b;
}

inline int max(int a, int b)
{
  return a > b ? a : b;
}

inline unsigned int umax(unsigned int a, unsigned int b)
{
  return a > b ? a : b;
}

inline long long int llmax(long long int a, long long int b)
{
  return a > b ? a : b;
}

inline unsigned long long int ullmax(unsigned long long int a, unsigned long long int b)
{
  return a > b ? a : b;
}
# 5123 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 5124 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 148 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 176 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2







#pragma pack()
# 2 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_000025e3_00000000-3_main.fatbin.c" 1
asm(
".section .rodata\n"
".align 32\n"
"fatbinData:\n"
".quad 0x00100001ba55ed50,0x00000000000167c8,0x0000007801000002,0x00000000000075d8\n"
".quad 0x0000000000000000,0x0000001700010004,0x0000003f00000038,0x0000000000000015\n"
".quad 0x0000000000000000,0x6f6e2f656d6f682f,0x6568632f6c616d72,0x70672f74756f6b63\n"
".quad 0x2f746f6c65636f75,0x6f722f7374736574,0x65742f61696e6964,0x2f7477682f737473\n"
".quad 0x0075632e6e69616d,0x33010102464c457f,0x0000000000000004,0x0000000100be0002\n"
".quad 0x0000000000000000,0x00000000000074f8,0x0000000000000040,0x0038004000140117\n"
".quad 0x0001000b00400004,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000300000001,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000300,0x00000000000000bb,0x0000000000000000,0x0000000000000004\n"
".quad 0x0000000000000000,0x000000030000000b,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000003bb,0x0000000000000083,0x0000000000000000,0x0000000000000001\n"
".quad 0x0000000000000000,0x0000000200000013,0x0000000000000000,0x0000000000000000\n"
".quad 0x000000000000043e,0x00000000000001e0,0x0000000d00000002,0x0000000000000001\n"
".quad 0x0000000000000018,0x0000000100000036,0x0000000000100006,0x0000000000000000\n"
".quad 0x000000000000061e,0x0000000000004c30,0x1c00000600000003,0x0000000000000004\n"
".quad 0x0000000000000000,0x0000000100000094,0x0000000000000002,0x0000000000000000\n"
".quad 0x000000000000524e,0x0000000000000020,0x0000000400000000,0x0000000000000004\n"
".quad 0x0000000000000000,0x000000010000007a,0x0000000000000002,0x0000000000000000\n"
".quad 0x000000000000526e,0x0000000000000018,0x0000000400000000,0x0000000000000004\n"
".quad 0x0000000000000000,0x0000000100000047,0x0000000000000002,0x0000000000000000\n"
".quad 0x0000000000005286,0x0000000000000018,0x0000000400000000,0x0000000000000001\n"
".quad 0x0000000000000000,0x0000000800000064,0x0000000000000003,0x0000000000000000\n"
".quad 0x000000000000529e,0x0000000000002e60,0x0000000400000000,0x0000000000000004\n"
".quad 0x0000000000000000,0x00000001000000ad,0x0000000000000002,0x0000000000000000\n"
".quad 0x000000000000529e,0x00000000000021f8,0x0000000000000000,0x0000000000000004\n"
".quad 0x0000000000000000,0x000000010000005b,0x0000000000000002,0x0000000000000000\n"
".quad 0x0000000000007496,0x0000000000000060,0x0000000000000000,0x0000000000000001\n"
".quad 0x0000000000000000,0x7472747368732e00,0x747274732e006261,0x746d79732e006261\n"
".quad 0x672e766e2e006261,0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c\n"
".quad 0x6b365a5f2e747865,0x2e00766c656e7265,0x2e6f666e692e766e,0x656e72656b365a5f\n"
".quad 0x692e766e2e00766c,0x2e766e2e006f666e,0x5f2e646572616873,0x6c656e72656b365a\n"
".quad 0x6f632e766e2e0076,0x3631746e6174736e,0x6e72656b365a5f2e,0x2e766e2e00766c65\n"
".quad 0x746e6174736e6f63,0x72656b365a5f2e30,0x766e2e00766c656e,0x6e6174736e6f632e\n"
".quad 0x6b365a5f00003274,0x5f00766c656e7265,0x6d735f616475635f,0x725f7669645f3032\n"
".quad 0x5f7a74666f6e5f6e,0x776f6c735f323366,0x635f5f0068746170,0x30326d735f616475\n"
".quad 0x5f6e725f7669645f,0x75635f5f00323366,0x5f30326d735f6164,0x5f6e725f74727173\n"
".quad 0x6e755f6400323366,0x635f640065757169,0x68635f6e6f6d6d6f,0x635f640065676e61\n"
".quad 0x0000006e6f6d6d6f,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000100030000,0x0000000000000000,0x0000000000000000,0x0000000200030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000300030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000030000,0x0000000000000000,0x0000000000000000,0x0000000400030000\n"
".quad 0x4c30000000000000,0x0000000000000000,0x0000000700030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000a00030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000800030000,0x0000000000000000,0x0000000000000000,0x0000000600030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000500030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000900030000,0x0000000000000000,0x0001000000000000\n"
".quad 0x0000000410120000,0x46e8000000000000,0x000c000000000000,0x46e8000400120000\n"
".quad 0x0378000000000000,0x0032000000000000,0x4a60000400120000,0x00d0000000000000\n"
".quad 0x0049000000000000,0x4b30000400120000,0x0100000000000000,0x0061000000000000\n"
".quad 0x0218000900110000,0x1fe0000000000000,0x006a000000000000,0x0000000900110000\n"
".quad 0x0010000000000000,0x007a000000000000,0x0010000900110000,0x0208000000000000\n"
".quad 0x5de4000000000000,0x1de4280044040000,0xdc23400000000000,0x00071a8e480023f1\n"
".quad 0x01e76000000ec000,0x1c044000000e8000,0x9ca32c0000009400,0x1ca65000c0028000\n"
".quad 0x9de414000808e021,0xdc86280000001401,0x5ce3140008091020,0x1c045000c0001031\n"
".quad 0x5ca32c0000008400,0xdc232009c0001034,0x1c031a8e0000fc01,0x9c434800c0086021\n"
".quad 0x81e7480000001464,0x61e440000002a000,0xa0a6280048008002,0x6086140008000040\n"
".quad 0xa0e314000800a041,0xa0a35000c0001052,0xe0432005c0001050,0x60a3480000002830\n"
".quad 0xe0e3200a88002092,0x20855000c0001092,0xa0a6840000000022,0xa0a3140008004040\n"
".quad 0xa0a62005c0001090,0xe043140008002041,0xa0a3480000002c30,0xe043200dc0001051\n"
".quad 0x2085480000002871,0x6085940000000022,0xa0a6840000000061,0xa0a3140008006040\n"
".quad 0xe0432005c0001090,0x6085480000002c30,0xdc23940000000021,0x01e71b0e48039001\n"
".quad 0x9ca64000000a2000,0x5c86140008000040,0x9ce314000800a041,0x9ca65000c0001051\n"
".quad 0x9ca3140008002042,0xdde42005c0001050,0x1de4280000002801,0xdc43280000002c02\n"
".quad 0x1ca3480000001830,0x5c43200fc0001051,0x1de4480000001881,0xdec4400000000000\n"
".quad 0x9ec41c0048037121,0x1c041c0048037121,0x5c04180400001d22,0x1c00180400001922\n"
".quad 0x1c02c80000001082,0x5c00083ffffff882,0x1c04c80000001092,0xdc02148600002122\n"
".quad 0x5c03083ffffff892,0x1c04500000002072,0x9c03148600002d23,0x5f844800c0000402\n"
".quad 0x5c031c0000002522,0xdec4500000003063,0x1c431c0000002922,0xdc23201000002482\n"
".quad 0x5f841b0e0000fca5,0x1c431c0000003522,0x5ec4500000002c82,0x5c431c0000002923\n"
".quad 0x1e032018000024c2,0x5c43201600002072,0xdc03500000003492,0xde03198e00002071\n"
".quad 0x0103201a00002462,0xdc03480000001c82,0xdc03198e00002c63,0xc503198e00002071\n"
".quad 0x44034800000018b2,0x01034800c0000492,0xdc03480000001c82,0xdc231b0e000018b3\n"
".quad 0xdc831a8e480373f1,0x9dc36800480370a1,0x2b846800480373f1,0x44031c0000002122\n"
".quad 0xdc234800c0000492,0x9c041b0e0000fc75,0xdc23201000002061,0xddc31a8e480373f1\n"
".quad 0x6b846800480373f1,0xdc231c0000002522,0x9c031a8e0000fc63,0xdc044800fffffc61\n"
".quad 0x85e7201000002471,0xa5e4400000008000,0xe403280048037001,0xa4034800fffffc71\n"
".quad 0x1de44800fffffc61,0x1c03400000000000,0x1c854800c0080000,0x5c85840000000042\n"
".quad 0x9c03840000000022,0xdc23480000001c82,0x1c03188e48039001,0x5c03480000001892\n"
".quad 0x9ca34800ffff98a2,0x1ca3200c48037071,0xdce3201048009092,0x5de45000c0001061\n"
".quad 0x1c03280048000002,0x9ca34800ffff9882,0x1ce32013c0001082,0xdc435000c0001082\n"
".quad 0x9ca3480048001082,0x1c852023c0001061,0xdc438400000000a2,0x1c85480000001d21\n"
".quad 0x01e7940000000062,0xdc334003fff74000,0x21e71a8e480023f1,0x1c04400000fd8000\n"
".quad 0x5ca32c0000009400,0x1c045000c0028002,0xdc232c0000008404,0x9ca61b0e4803d101\n"
".quad 0xdc03140008086090,0x1c864800c0086094,0x1ce3140008090090,0x9ca65000c0001001\n"
".quad 0x9ca3140008088091,0x5de42005c0001000,0xdc43280000001801,0x0007480000001030\n"
".quad 0x9ca36000000a0000,0x1de4200bc0001001,0xdc43280000004002,0x5c85480000001071\n"
".quad 0x1c85840000000021,0x5d03840000000061,0x9d03480048004052,0x01e7480048004042\n"
".quad 0x5ce340000008e000,0x1ca65000c0001101,0x1de414000800c133,0xdde4280000003001\n"
".quad 0x1ca3280000003402,0x5c432009c0001101,0x1de44800000014b1,0x1ec4400000000000\n"
".quad 0xdec41c004803b123,0x5c041c004803b122,0x5c00180400003123,0x9c04c800000010d3\n"
".quad 0x5c02180400002d23,0xdc00083ffffff8d3,0x9c04c800000010e3,0x5c02148600003523\n"
".quad 0xdc03083ffffff8f4,0x9c045000000038c3,0x5c03148600004524,0xdf844800c0000483\n"
".quad 0x1c031c0000003d23,0x5ec45000000048b5,0x9c431c0000003524,0xdc23201c00003ce3\n"
".quad 0xdf841b0e0000fcd5,0x9c431c0000005123,0x1ec45000000044e3,0xdc431c0000003525\n"
".quad 0x9e03202400003d23,0xdc432022000038c3,0xdc035000000050f3,0x5e03198e000038c1\n"
".quad 0x8103202800003cb4,0xdc034800000030e3,0xdc03198e000044b3,0x4503198e000038c1\n"
".quad 0xc403480000002d14,0x81034800c00004f3,0xdc034800000030e3,0xdc231b0e00002d13\n"
".quad 0x1c831a8e4803b3f1,0xddc368004803b0d3,0xab8468004803b3f2,0xc4031c0000003923\n"
".quad 0xdc234800c00004f3,0xdc041b0e0000fcc5,0xdc232010000038b2,0x1dc31a8e4803b3f1\n"
".quad 0xeb8468004803b3f3,0xdc231c0000003d23,0xdc031a8e0000fcb3,0x1c044800fffffcb2\n"
".quad 0x85e7201000003cc3,0xe5e4400000006000,0x240328004803b002,0xe4034800fffffcc3\n"
".quad 0x1c034800fffffcb2,0xdc034800000028c3,0x5de44800000024b2,0x1c03280048000003\n"
".quad 0xdca34800fffffcc3,0x1c032016480090c2,0x1ca34800c0080082,0xdc23201bc00010b3\n"
".quad 0xdce3188e4803d081,0x5c435000c00010b2,0xdc854800480010b3,0xdc8587fffffff0c2\n"
".quad 0x1c03940000000042,0x5c434801c0200041,0x01e748000000fc51,0x1df44003fff80000\n"
".quad 0xdc04400000000000,0xdc2350ee0000ffff,0x1ca61b0e48039101,0x1c86140008008132\n"
".quad 0x5ce314000800b131,0x00075000c0001041,0x5ca3600000092000,0x1de42011c0001044\n"
".quad 0x9c43280000004002,0x01e7480000001494,0x1de4400000088000,0x5ce3280040000001\n"
".quad 0x1ca35000c0001101,0x5c432009c0001101,0x1de44800000017f1,0x9ec4400000000000\n"
".quad 0x5ec41c0048037122,0xdc041c0048037122,0xdc00180400002922,0x1c04c800000010b2\n"
".quad 0xdc02180400002523,0x5c00083ffffff8b2,0x1c04c800000010c3,0x9c02148600002d23\n"
".quad 0x5c03083ffffff8d3,0xdc045000000030a3,0xdc03148600003923,0x5f844800c0000482\n"
".quad 0x1c031c0000003523,0x9ec4500000003c95,0x1c431c0000002d23,0xdc232018000034c3\n"
".quad 0x5f841b0e0000fcb5,0x1c431c0000005123,0x1ec45000000038c3,0x5c431c0000002d25\n"
".quad 0x1e03201e000034f3,0x5c43201c000030a3,0xdc035000000050d3,0x9e03198e000030a1\n"
".quad 0x0103202800003493,0xdc034800000028c3,0xdc03198e00003893,0x8503198e000030a1\n"
".quad 0x44034800000024e3,0x01034800c00004d3,0xdc034800000028c3,0xdc231b0e000024e3\n"
".quad 0x9c831a8e480373f1,0x5dc36800480370b2,0x2b846800480373f2,0x44031c0000003123\n"
".quad 0xdc234800c00004d3,0x5c041b0e0000fca5,0xdc23201000003092,0x9dc31a8e480373f1\n"
".quad 0x6b846800480373f2,0xdc231c0000003523,0xdc031a8e0000fc93,0x9c044800fffffc92\n"
".quad 0x85e72010000034a2,0x65e4400000006000,0xa403280048037002,0xe4034800fffffca2\n"
".quad 0x5e034800fffffc92,0x1c034800480370a2,0x9e034800c0080082,0x5c034800480370b2\n"
".quad 0x5ca34800fffffc92,0x9ce3201448037092,0x1ca35000c0001092,0x5c432023c0001093\n"
".quad 0xdc23480000002923,0x5c85188e48039081,0x5c8587fffffff0c2,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x01e748000000fc51,0x1df44003fff82000,0xdc04400000000000\n"
".quad 0xdc2350ee0000ffff,0x0007188e48041101,0x5de46000000f6000,0x21e7280000004005\n"
".quad 0x5ce34000000f0000,0x9ca65000c0001101,0x1de414000800e132,0x1de4280000002801\n"
".quad 0x1ca3280000002c02,0x5c432009c0001101,0x1de4480000001481,0x5ec4400000000000\n"
".quad 0x1ec41c004803f122,0x9c041c004803f122,0xdc04180400002522,0x9c00180400002122\n"
".quad 0xdc00c800000010a2,0x9c02c800000010b2,0x1c02083ffffff8a2,0x0007083ffffff8b3\n"
".quad 0xdc046000000c4000,0x9c04148600002922,0x1c03148600003123,0x5c03500000002c93\n"
".quad 0x9c03500000003883,0x1f844800c0000552,0xdf841c0000003123,0xdc431c0000003523\n"
".quad 0x5ec42016000030b2,0x1ec41c0000002923,0x1c431c0000002925,0xdc43201c00003ce3\n"
".quad 0x1c435000000034b2,0xde035000000050c3,0x5e03201a00002c92,0xdc03202800003083\n"
".quad 0xdc03198e00002c93,0xc503198e00003485,0x49034800000024b2,0xdc034800000020d3\n"
".quad 0x0803198e00002c93,0x9c834800c00004c3,0xdc2368004803f0a3,0xdc031b0e0000fca7\n"
".quad 0xc5031b0e000020d5,0xdc234800000024b2,0xdc231b0e0000fce9,0x1dc31a8e4803f3f3\n"
".quad 0x080368004803f3f2,0xef844800c00004c3,0xdc231c0000002d22,0x9dc31a8e4803f3f5\n"
".quad 0x338468004803f3f2,0x5c041c0000003123,0x9c04201200002c82,0xdc232014000030a2\n"
".quad 0x1c031a8e0000fc97,0x6de44800c00004a2,0x2de428004803f002,0x9c03280000002802\n"
".quad 0xdc03480048044082,0x1d034800c00004a2,0xdc2348004803c0a3,0xdc231a0e480380a5\n"
".quad 0xdc031a0e4803c0b3,0x9c044800c00004c2,0x1c042014480380a2,0xdc232002c00004b3\n"
".quad 0x05e7188e000030a3,0xdc03400000060000,0x5c03480048043093,0x5c034800c00004a3\n"
".quad 0xdd034800c00004f2,0xdc2348004803b0f2,0xdc231a0e4803b095,0x5c031a0e480370f3\n"
".quad 0xdc044800c00004b2,0x1c042012480370f2,0x5c032004c0000495,0x9ca34800c00004b2\n"
".quad 0x9de450004803b085,0xdc2328000000fc03,0xdd031b0e000050b3,0x00074800000024f5\n"
".quad 0x25e760000003c000,0x1de4400000038000,0x9ca6280048037002,0x5de414000800c132\n"
".quad 0x1da3280048044002,0x9de42010480370c6,0x5ca3280000002c06,0xdc03202c4803b092\n"
".quad 0x1de4480000006146,0x1d03280040000002,0x5ea34800000050f6,0x1ca320124803b0c6\n"
".quad 0x5ce32011c00011b2,0x1c035000c00011b2,0x5c43480000006586,0xdce34800000027f2\n"
".quad 0x9ca35000c0001182,0x5c032015c0001182,0xdc43480000005d96,0xdc85480000002da2\n"
".quad 0x1c038400000000a6,0x9c854800fffffd86,0x1c0387fffffff086,0xdc234801c0001082\n"
".quad 0x5c431a8e00006585,0x9c0348000000fc92,0xdc434801fffff0a2,0x9c004800fffffcb2\n"
".quad 0x09e7301c000069b3,0x1c134003fffec000,0xdc234800c00004c3,0x09e71a8e000030d5\n"
".quad 0x1df44003fffbe000,0x9df4400000000000,0x5c0328000000fc03,0x9c854800c0080155\n"
".quad 0xdc23940000000043,0x1c03188e48041153,0x5c434801c0200041,0x05e748000000fc51\n"
".quad 0x1df44003fff1e000,0xdc04400000000000,0xdc2350ee0000ffff,0x0007188e48049105\n"
".quad 0xdde46000000ba000,0x29e7280000004002,0x5ce34000000b4000,0x1ca65000c0001101\n"
".quad 0x5de4140008012133,0x1de4280048045002,0x1de4280000003001,0x1ca3280000003402\n"
".quad 0x9c032009c0001101,0x5c434800fffffc92,0x0007480000001481,0x5ec4700000098000\n"
".quad 0x1ec41c0048047122,0x1c041c0048047122,0x5c04180400002523,0x1c00180400002123\n"
".quad 0x1c02c800000010c3,0x9c00083ffffff8c3,0x5c04c800000010d3,0xdc02148600003123\n"
".quad 0x9c03083ffffff8e3,0x1c04500000003493,0x1c03148600003d25,0x9f844800c00004b3\n"
".quad 0x5c031c0000003923,0xdec4500000005085,0x5c431c0000003123,0xdc23201a000038d3\n"
".quad 0x9f841b0e0000fcc9,0x5c431c0000005523,0x5ec4500000003cd3,0x9c431c0000003125\n"
".quad 0x5e03202800003943,0x9c43201e00003493,0xdc035000000054e3,0xde03198e00003493\n"
".quad 0x4503202a00003883,0xdc034800000024d3,0xdc03198e00003c87,0xcd03198e00003493\n"
".quad 0x8c034800000020f3,0x45034800c00004e3,0xdc034800000024d3,0xdc231b0e000020f7\n"
".quad 0x5c831a8e480473f3,0x1dc36800480470c2,0x73846800480473f2,0x8c031c0000003523\n"
".quad 0xdc234800c00004e3,0x1c041b0e0000fc99,0xdc23201200003482,0x5dc31a8e480473f3\n"
".quad 0xb3846800480473f2,0xdc231c0000003923,0x5c031a8e0000fc87,0x1c044800fffffc83\n"
".quad 0x8de7201200003893,0x2de4400000008000,0x2c03280048047002,0x6c034800fffffcc3\n"
".quad 0x1de44800fffffc83,0xdc23400000000000,0x05e71b0e000034a3,0x1de440000002c000\n"
".quad 0x1c0328004803b002,0xdc23480048045082,0x05e71b0e000020d3,0x1de4400000024000\n"
".quad 0x1c03280048046002,0xdc234800fffffc82,0x05e7198e000020c3,0x1de440000001c000\n"
".quad 0x1c0328004803c002,0xdc23480048046082,0x05e71b0e000020c3,0x1d03400000014000\n"
".quad 0x5d034800480460c3,0x1ca34800480450d3,0x1ca6201a4803b0c3,0x5ce314000800c132\n"
".quad 0x1ca35000c00010c3,0x5c432011c00010c2,0x1c85480000003492,0x1c85840000000082\n"
".quad 0x1de7940000000042,0xdc85b00000000000,0x1de794000000004f,0xdc03b00000000000\n"
".quad 0x1c034800c00800b2,0xdc234801c0200041,0x5c43188e480490b3,0x05e748000000fc51\n"
".quad 0x1df44003fff5c000,0xdc04400000000000,0xdc2350ee0000ffff,0x0007188e48048107\n"
".quad 0x9de460000003a000,0x2de7280000004003,0x1de4400000034000,0x1ca3280048047001\n"
".quad 0x5e03500048047102,0x1de46000c0002442,0x1c03400000000000,0x0007480048047083\n"
".quad 0x9de4600000022000,0xdc23280000002002,0x05e7198e000020c3,0x5ce340000001a000\n"
".quad 0x1ca65000c0001083,0xdde4140008012131,0x1ca328000000fc02,0x5c432009c0001081\n"
".quad 0x9c03480000003451,0x5c854800c00004a2,0xdc23840000000043,0xdc001a8e000028c3\n"
".quad 0xdc85500000002cd2,0x1c03940000000042,0x5c434801c0001041,0x05e748000000fc51\n"
".quad 0x9c134003ffff0000,0xdc234800c00800e3,0x1c03188e480480e3,0x05e7480000002482\n"
".quad 0x1df44003fffd4000,0xdc04400000000000,0xdc2350ee0000ffff,0x0007188e4804d109\n"
".quad 0x9de4600000096000,0x31e7280000004002,0x5ce3400000090000,0x1ca65000c0001101\n"
".quad 0x1de4140008014133,0x1ca6280000003001,0x1ca3140008012132,0xdde42009c0001101\n"
".quad 0x1de4280000002002,0x5c43280000002403,0x1ec44800000014d1,0x5c041c004804b122\n"
".quad 0x5c00180400002122,0x5ec4c80000001093,0x5c021c004804b122,0xdc04083ffffff8d3\n"
".quad 0x9c04180400002523,0x5c00148600003523,0xdc03c800000010f3,0x1c02500000003883\n"
".quad 0x5c03083ffffff8d5,0xdf844800c00004a3,0x5c041c0000003d23,0x9c43148600005125\n"
".quad 0x1ec4201c00003ce3,0xdc031c0000003525,0x9c43500000005493,0xdf845000000050e3\n"
".quad 0x9ec41c0000003d23,0x9e031c0000003525,0xdc43202800003883,0xdc03202a00003d53\n"
".quad 0xdc43198e00003883,0x85035000000058f3,0x1e034800000020e3,0xdc03202c00003c95\n"
".quad 0xdc03198e00003883,0x8503198e0000509b,0xdc234800000020e3,0x15031b0e0000fcd3\n"
".quad 0xd403480000002545,0x1c834800c00004f3,0xdc0368004804b0d2,0xa7841b0e0000254b\n"
".quad 0xdc231c0000003923,0x5dc31a8e4804b3f3,0xd40368004804b3f2,0xdc234800c00004f3\n"
".quad 0x1c041b0e0000fc8b,0xf784201200003892,0xdc231c0000003d23,0x5dc31a8e4804b3f3\n"
".quad 0xdc2368004804b3f2,0x5c041a8e0000fc8b,0x1c03201200003c92,0x95e74800fffffc82\n"
".quad 0x35e4400000008000,0x740328004804b002,0x34034800fffffc92,0x1de44800fffffc82\n"
".quad 0x5c03400000000000,0x9c03480048051092,0x1c034800c00800a2,0x5c0348004804f082\n"
".quad 0x1ca34800fffffc92,0x5ce3201048047092,0xdc235000c0001082,0x1ca3188e4804d0a3\n"
".quad 0x5c432017c0001082,0x1c854800000024c2,0x1c8587fffffff082,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x05e748000000fc51,0x1df44003fff80000,0xdc04400000000000\n"
".quad 0xdc2350ee0000ffff,0x0007188e4805910b,0x9de4600000096000,0x35e7280000004002\n"
".quad 0x5ce3400000090000,0x1ca65000c0001101,0x1de4140008016133,0x1ca6280000003001\n"
".quad 0x1ca3140008012132,0xdde42009c0001101,0x1de4280000002002,0x5c43280000002403\n"
".quad 0x1ec44800000014d1,0x5ec41c0048057122,0x5c041c0048057122,0x9c04180400002123\n"
".quad 0x5c00180400002523,0x9c00c800000010d3,0x5c02c800000010e3,0x9c02083ffffff8d3\n"
".quad 0xdc04083ffffff8e3,0x5c04148600003523,0x9c03148600003925,0x5c03500000003c83\n"
".quad 0x9c034800c00004a3,0x1f84500000005495,0x9ec41c0000003925,0x1c431c0000003523\n"
".quad 0x9f84201e000050f5,0xdec41c0000005925,0x1c431c0000003525,0x9c43500000003945\n"
".quad 0x9e03202a00005955,0xdc43201c00005083,0xdc03500000005d63,0x1e03198e00003883\n"
".quad 0x8503202e00003c95,0xdc034800000020e3,0xc403198e00005093,0x05034800c00004f3\n"
".quad 0xdc03480000002545,0x8503198e00003883,0xdc034800000020e3,0x1c831b0e00002543\n"
".quad 0xc4036800480570d2,0x5dc34800c00004f3,0xdc236800480573f2,0xa7841b0e0000fcd3\n"
".quad 0xdc231c0000003923,0x1dc31b0e0000fc83,0xe7846800480573f2,0xdc231c0000003d23\n"
".quad 0x1c041a8e480573f3,0xdc23201200003882,0x5c041a8e480573f3,0xdc23201200003c92\n"
".quad 0x1c031a8e0000fc83,0x85e74800fffffc82,0x25e4400000008000,0x6403280048057002\n"
".quad 0x24034800fffffc92,0x1de44800fffffc82,0x5c03400000000000,0x9c03480048055092\n"
".quad 0x1c034800c00800a2,0x5c03480048053082,0x1ca34800fffffc92,0x5ce3201048047092\n"
".quad 0x1ca35000c0001082,0xdc232017c0001082,0x5c43188e480590a3,0x1c854800000024c2\n"
".quad 0x1c8587fffffff082,0x1c03940000000042,0x5c434801c0200041,0x05e748000000fc51\n"
".quad 0x1df44003fff80000,0xdc04400000000000,0x9de450ee0000ffff,0x0007280000004002\n"
".quad 0x35f4600000046000,0xdce3400000000000,0x1ca65000c0001102,0x1ca6140008016131\n"
".quad 0x1c03140008014132,0x1ca34800c0080103,0x5c432009c0001101,0xdc23480000002c51\n"
".quad 0x1ca3188e480590c3,0x5c432011c0001102,0x25e7480000002c92,0x0007400000028000\n"
".quad 0x9c03600000024000,0xdc854800c01000a2,0xdc23840000000082,0x1c85188e480590a3\n"
".quad 0xdd00840000000043,0x5c855000000030b2,0xdc85840000200043,0x1c85940000000042\n"
".quad 0x1c03840000200083,0x5c434801c0400082,0xdd0048000000fc92,0x1c035000000034c2\n"
".quad 0xdc854800c00800a3,0xdc23940000200042,0x1c031882480590c3,0x5c434801c0400041\n"
".quad 0x05e748000000fc51,0xdc334003fffde000,0x25f4188e480590a3,0x1c85400000000000\n"
".quad 0x9c85840000000082,0x1d00840000000042,0x1c95500000002882,0xdc04940000000042\n"
".quad 0xdc2350ee0000ffff,0x0007188e48057103,0xdde4600000038000,0x9c04280000004003\n"
".quad 0x25e7080e00001c12,0x1c03400000030000,0x00074800480590f2,0x9de4600000028000\n"
".quad 0xdc23280000003c03,0x05e7198e00003c83,0x5de4400000020000,0x1ca6280048057002\n"
".quad 0x1ce3140008016131,0x5de45000c00010f3,0x1ca328000000fc03,0xdce32009c00010f1\n"
".quad 0x5e035000c0001092,0x5c436000c0000892,0x9c03480000003051,0x1c854800480570e3\n"
".quad 0xdc23840000000043,0x5c001a0e00003883,0x5c855000000034c3,0x1c03940000000043\n"
".quad 0x5c43480100002441,0x05e7480000002c51,0xdc134003ffff0000,0xdc234800c00800f3\n"
".quad 0x05e7188e480570f3,0x1df44003fffd0000,0xdc04400000000000,0xdc2350ee0000ffff\n"
".quad 0x1de4188e4805d103,0x0007280000004003,0xdc04600000096000,0x25e7080e00001c12\n"
".quad 0xdce3400000090000,0x1ca65000c0001103,0x1ca3140008018131,0x1ca62009c0001101\n"
".quad 0x5c43140008016132,0x5de4480000003c51,0x9de4280000002003,0x1de4280000002403\n"
".quad 0x1ec4400000000000,0x5c041c004805b122,0x5c00180400002122,0x5c02c80000001092\n"
".quad 0xdc04083ffffff892,0x1c03148600002523,0x5c03500000003c85,0x1f844800c00004c2\n"
".quad 0x5ec41c0000005125,0xdc431c0000002525,0x9ec4201e000050f3,0xdc431c0000002525\n"
".quad 0xde035000000054f3,0xdc03202a00003c83,0xc503198e00003c83,0xdc034800000020f3\n"
".quad 0xc503198e00003c83,0xdc234800000020f3,0x1dc31b0e0000fc93,0xe78468004805b3f2\n"
".quad 0xdc231c0000003d23,0x5c831a8e4805b3f3,0x1c0468004805b092,0xdec4201200003c82\n"
".quad 0x1c041c004805b123,0x1c00180400003d25,0x1c02c80000001145,0x1c04083ffffff945\n"
".quad 0x5c03148600005125,0x5f845000000050f5,0x5c431c0000005525,0x1c43202800005545\n"
".quad 0x5e03500000005955,0xdc03202c000050f5,0x4503198e000054f3,0x0403480000003d55\n"
".quad 0xdc034800c0000545,0x04031b0e00003d53,0xdc034800c0000545,0xdc234800fffffc83\n"
".quad 0x5dc31b0e0000fc93,0x278468004805b3f2,0xdc231c0000005125,0x5c041a8e4805b3f3\n"
".quad 0xdc23201200005092,0x85e71a8e0000fc83,0x25e4400000008000,0x640328004805b002\n"
".quad 0xe4034800fffffc92,0x1de44800fffffc83,0x5c03400000000000,0x1c03480048061092\n"
".quad 0x1c034800c00800c3,0x5c0348004805f0f2,0x5ca34800fffffc92,0x1ca3201048057092\n"
".quad 0xdc23201bc0001092,0x5ce3188e4805d0c3,0x5c435000c0001092,0x1c854800000024e2\n"
".quad 0x1c8587fffffff082,0x1c03940000000042,0x5c434801c0200041,0x05e748000000fc51\n"
".quad 0x1df44003fff80000,0xdc04400000000000,0xdc2350ee0000ffff,0x0007188e48069103\n"
".quad 0x1de4600000096000,0x25e7280000004003,0xdce3400000090000,0x1ca65000c0001103\n"
".quad 0x1ca314000801a131,0x1ca62009c0001101,0x5c43140008016132,0x5de4480000003c51\n"
".quad 0x9de4280000002003,0x1de4280000002403,0x1ec4400000000000,0x5c041c0048067122\n"
".quad 0x5c00180400002122,0x5c02c80000001092,0xdc04083ffffff892,0x1c03148600002523\n"
".quad 0x5c03500000003c85,0x1f844800c00004c2,0x5ec41c0000005125,0x1c431c0000002525\n"
".quad 0xdc43201e000050f5,0x9ec4500000005543,0xde031c0000002525,0xdc03202a00003c83\n"
".quad 0xd903198e00003c8d,0xdc034800000020f3,0xd903198e00003c8d,0xdc234800000020f3\n"
".quad 0x1dc31b0e0000fc9d,0xfb846800480673f2,0x5c831c0000003d23,0xdc23680048067092\n"
".quad 0x1c041a8e480673fd,0xdec4201c00003c82,0x1c041c0048067123,0x1c00180400003d25\n"
".quad 0x1c02c80000001145,0x1c04083ffffff945,0x5c03148600005125,0x5f845000000050f5\n"
".quad 0x5c431c0000005525,0x1c43202800005545,0x9e03500000005955,0xdc03202c000050f5\n"
".quad 0x9903198e000058fd,0x1803480000003d65,0xdc034800c0000545,0x18031b0e00003d6d\n"
".quad 0xdc234800c0000545,0xdc031b0e0000fc9d,0x5dc34800fffffc83,0x3b846800480673f2\n"
".quad 0xdc231c0000005125,0x1c041a8e480673fd,0xdc23201c00005095,0x99e71a8e0000fc8d\n"
".quad 0x39e4400000008000,0x3803280048067002,0xf8034800fffffd45,0x1de44800fffffc83\n"
".quad 0x5c03400000000000,0x1c03480048065142,0x1c034800c00800c3,0x5c034800480630f2\n"
".quad 0x5ca34800fffffc92,0x1ca3201048057092,0xdc23201bc0001092,0x5ce3188e480690cd\n"
".quad 0x5c435000c0001092,0x1c854800000024e2,0x1c8587fffffff082,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x19e748000000fc51,0x1df44003fff80000,0xdc04400000000000\n"
".quad 0x1de450ee0000ffff,0x0007280000004003,0x25f4600000046000,0x1ca6400000000000\n"
".quad 0x5ce314000801a131,0x1ca65000c0001103,0x9c03140008018132,0x1ca34800c0080103\n"
".quad 0x5c432009c0001101,0xdc23480000003451,0x1ca3188e480690ed,0x5c432011c0001102\n"
".quad 0x39e7480000003492,0x0007400000028000,0x1c03600000024000,0x5c854800c01000c3\n"
".quad 0xdc23840000000083,0x9c85188e480690cd,0x5d00840000000043,0xdc855000000038d3\n"
".quad 0x5c85840000200043,0x9c85940000000043,0x1c03840000200083,0x5c434801c0400082\n"
".quad 0x5d0048000000fc92,0x9c03500000003ce3,0x5c854800c00800c3,0xdc23940000200043\n"
".quad 0x1c03188c480690ed,0x5c434801c0400041,0x19e748000000fc51,0xdc334003fffde000\n"
".quad 0x39f4188e480690cd,0x1c85400000000000,0x1c85840000000082,0x1d00840000000043\n"
".quad 0x1c95500000003082,0xdc04940000000042,0xdc2350ee0000ffff,0x00071b0e4806d10d\n"
".quad 0x1de4600000042000,0x19f4280000004003,0x5ce3400000000000,0x1ca65000c0001103\n"
".quad 0x9c0314000801c131,0x1ca64800c0080103,0x1ca314000800c132,0xdc232009c0001101\n"
".quad 0x5c43188e4806d0ed,0x1ca3480000003451,0x5c432011c0001102,0x39e7480000003492\n"
".quad 0x0007400000024000,0x1c03600000020000,0x5c854800c01000c3,0x5c00840000000083\n"
".quad 0xdc235800000034d3,0x5c85188e4806d0cd,0x9c85940000000043,0x1c03840000200083\n"
".quad 0x5c434801c0400082,0x5c0048000000fc92,0x9c035800000038e3,0x5c854800c00800c3\n"
".quad 0xdc23940000200043,0x1c03188c4806d0ed,0x5c434801c0400041,0x19e748000000fc51\n"
".quad 0xdc334003fffe2000,0x39f4188e4806d0cd,0x1c85400000000000,0x1c00840000000082\n"
".quad 0x1c95580000002082,0xdc04940000000042,0x1de450ee0000ffff,0x0007280000004003\n"
".quad 0x29e76000000b4000,0x5ce34000000b0000,0x1ca65000c0001102,0x5de4140008012131\n"
".quad 0x1ca3280048045003,0x5c032009c0001102,0x5c434800fffffcd3,0x0007480000002452\n"
".quad 0x9ec4700000098000,0x1c041c0048047123,0x1c00180400003921,0x1c02c80000001041\n"
".quad 0x5c04083ffffff841,0xdc03148600001121,0x1c035000000014e3,0xdf844800c00004c1\n"
".quad 0x1ec41c0000003d23,0x5c431c0000001125,0x5c43200a00003c51,0x5ec4500000005051\n"
".quad 0x5e031c0000001125,0xdc032028000014e1,0x4903198e000014e5,0xdc03480000003851\n"
".quad 0x4903198e000014e5,0xdc23480000003851,0x9dc31b0e0000fc45,0x6b846800480473f3\n"
".quad 0x1c831c0000001521,0xdc23680048047041,0x5c041a8e480473f5,0x9ec42014000014e1\n"
".quad 0xdc041c0048047123,0xdc00180400003923,0xdc02c800000010f3,0xdc04083ffffff8f3\n"
".quad 0x1c03148600003d23,0x1f84500000003ce5,0xdc431c0000005125,0xdc43201e000050f3\n"
".quad 0x1e035000000054f3,0xdc03202a00003ce5,0x0903198e000050e5,0xc803480000003945\n"
".quad 0xdc034800c00004f3,0xc8031b0e00003945,0x9c034800c00004f3,0xdc234800fffffc53\n"
".quad 0x1dc31b0e0000fc45,0xeb846800480473f1,0xdc231c0000003d23,0xdc041a8e480473f5\n"
".quad 0xdc23201400003c43,0x89e71a8e0000fc55,0x29e4400000008000,0xe803280048047001\n"
".quad 0xa8034800fffffcf3,0x1de44800fffffc43,0xdc23400000000000,0x09e71b0e000038d5\n"
".quad 0x1de440000002c000,0x1c0328004806b001,0xdc23480048045041,0x09e71b0e000010e5\n"
".quad 0x1de4400000024000,0x1c03280048046001,0xdc234800fffffc41,0x09e7198e000010f5\n"
".quad 0x1de440000001c000,0x1c0328004806c001,0xdc23480048046041,0x09e71b0e000010f5\n"
".quad 0xdd03400000014000,0x9d034800480460f3,0x9ca34800480450e3,0x1ca6201c4806b0f3\n"
".quad 0xdce314000801c131,0x1ca35000c00010e3,0x5c432009c00010e1,0x1c85480000003c51\n"
".quad 0x1c85840000000041,0x1de7940000000081,0xdc85b00000000000,0x1de794000000008f\n"
".quad 0x1c03b00000000000,0x1c034800c00800c3,0xdc234801c0200082,0x5c43188e480490c5\n"
".quad 0x09e748000000fc92,0x1df44003fff5c000,0xdc04400000000000,0x1de450ee0000ffff\n"
".quad 0x0007280000004005,0x2de760000003a000,0x1de4400000036000,0xdca3280048047001\n"
".quad 0x9e03500048047103,0x1de46000c0002443,0x1c03400000000000,0x00074800480470f2\n"
".quad 0x5de4600000024000,0xdc23280000003c03,0x09e7198e00003c85,0x1ca640000001c000\n"
".quad 0x5ce3140008012131,0x1de45000c00010f2,0x1ca328000000fc03,0x5c432009c00010f1\n"
".quad 0x1de4480000002451,0x5c03400000000000,0x5c854800c00004d3,0xdc23840000000042\n"
".quad 0x1c001a8e00003485,0x1c85500000003093,0x1c03940000000043,0x5c434801c0001041\n"
".quad 0x09e748000000fc51,0x1c134003ffff0000,0xdc234800c0080145,0xdc03188e48048145\n"
".quad 0x09e74800000038f3,0x1df44003fffd2000,0xdc04400000000000,0x1de450ee0000ffff\n"
".quad 0x0007280000004003,0x31e7600000092000,0xdce340000008e000,0x1ca65000c0001103\n"
".quad 0x1ca3140008014132,0x1ca62011c0001102,0x5c43140008012131,0x5de4480000003c92\n"
".quad 0x9de4280000001003,0x1de4280000001403,0x1ec4400000000000,0x5ec41c004804b121\n"
".quad 0xdc041c004804b121,0x1c04180400001123,0xdc00180400001525,0x1c00c800000010f3\n"
".quad 0xdc02c80000001145,0x1c02083ffffff8f3,0x9c04083ffffff945,0x5c04148600003d25\n"
".quad 0x1c03148600005125,0xdc03500000005845,0x1c034800c00004c3,0xdf84500000005456\n"
".quad 0x1ec41c0000005125,0xdc431c0000003d25,0x1f84202c00005d65,0x9ec41c0000006126\n"
".quad 0xdc431c0000003d25,0x1c43500000005175,0x1e03202a00006156,0x5c43202800005c45\n"
".quad 0xdc03500000005985,0x9e03198e00005045,0x0903202c00005455,0xdc03480000001145\n"
".quad 0x4803198e00005855,0x89034800c0000555,0xdc03480000001565,0x0903198e00005045\n"
".quad 0xdc03480000001145,0x1c831b0e00001565,0x480368004804b0f1,0x5dc34800c0000555\n"
".quad 0xdc2368004804b3f1,0x2b841b0e0000fcf5,0xdc231c0000005125,0x1dc31b0e0000fc45\n"
".quad 0x6b8468004804b3f1,0xdc231c0000005525,0x1c041a8e4804b3f5,0xdc23201400005041\n"
".quad 0x5c041a8e4804b3f5,0xdc23201400005451,0x1c031a8e0000fc45,0x89e74800fffffc41\n"
".quad 0x29e4400000006000,0x680328004804b001,0x28034800fffffc51,0x5c034800fffffc41\n"
".quad 0x1c03480048051051,0x5c0348004804f041,0x1ca34800fffffc51,0x1c03200848047051\n"
".quad 0x5ce34800c00800c3,0xdc235000c0001041,0x1ca3188e4804d0c5,0x5c43201bc0001041\n"
".quad 0x1c854800000014e1,0x1c8587fffffff041,0x1c03940000000081,0x5c434801c0200082\n"
".quad 0x09e748000000fc92,0x1df44003fff82000,0xdc04400000000000,0x000750ee0000ffff\n"
".quad 0x1de4600000096000,0x35e7280000004003,0xdce3400000090000,0x1ca65000c0001103\n"
".quad 0x1ca3140008016131,0x1ca62009c0001101,0x5c43140008012132,0x5de4480000003c51\n"
".quad 0x9de4280000002003,0x1de4280000002403,0x1ec4400000000000,0x5ec41c0048057122\n"
".quad 0xdc041c0048057122,0x1c04180400002123,0xdc00180400002525,0x1c00c800000010f3\n"
".quad 0xdc02c80000001145,0x1c02083ffffff8f3,0x9c04083ffffff945,0x5c04148600003d25\n"
".quad 0x1c03148600005125,0xdc03500000005885,0x1c034800c00004c3,0xdf84500000005496\n"
".quad 0x1ec41c0000005125,0xdc431c0000003d25,0x1f84202c00005d65,0x9ec41c0000006126\n"
".quad 0xdc431c0000003d25,0x1c43500000005175,0x1e03202a00006156,0x5c43202800005c85\n"
".quad 0xdc03500000005985,0x9e03198e00005085,0x0903202c00005495,0xdc03480000002145\n"
".quad 0x4803198e00005895,0x89034800c0000555,0xdc03480000002565,0x0903198e00005085\n"
".quad 0xdc03480000002145,0x1c831b0e00002565,0x48036800480570f2,0x5dc34800c0000555\n"
".quad 0xdc236800480573f2,0x2b841b0e0000fcf5,0xdc231c0000005125,0x1dc31b0e0000fc85\n"
".quad 0x6b846800480573f2,0xdc231c0000005525,0x1c041a8e480573f5,0xdc23201400005082\n"
".quad 0x5c041a8e480573f5,0xdc23201400005492,0x1c031a8e0000fc85,0x89e74800fffffc82\n"
".quad 0x29e4400000008000,0x6803280048057002,0x28034800fffffc92,0x1de44800fffffc82\n"
".quad 0x5c03400000000000,0x1c03480048055092,0x1c034800c00800c3,0x5c03480048053082\n"
".quad 0x1ca34800fffffc92,0x5ce3201048047092,0xdc235000c0001082,0x1ca3188e480590c5\n"
".quad 0x5c43201bc0001082,0x1c854800000024e2,0x1c8587fffffff082,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x09e748000000fc51,0x1df44003fff80000,0xdc04400000000000\n"
".quad 0x1de450ee0000ffff,0x0007280000004003,0x35f4600000046000,0x1ca6400000000000\n"
".quad 0x5ce3140008016131,0x1ca65000c0001103,0x9c03140008014132,0x1ca34800c0080103\n"
".quad 0x5c432009c0001101,0xdc23480000003451,0x1ca3188e480590e5,0x5c432011c0001102\n"
".quad 0x29e7480000003492,0x0007400000028000,0x1c03600000024000,0x5c854800c01000c3\n"
".quad 0xdc23840000000083,0x9c85188e480590c5,0x5d00840000000043,0xdc855000000038d3\n"
".quad 0x5c85840000200043,0x9c85940000000043,0x1c03840000200083,0x5c434801c0400082\n"
".quad 0x5d0048000000fc92,0x9c03500000003ce3,0x5c854800c00800c3,0xdc23940000200043\n"
".quad 0x1c031884480590e5,0x5c434801c0400041,0x09e748000000fc51,0xdc334003fffde000\n"
".quad 0x29f4188e480590c5,0x1c85400000000000,0x1c85840000000082,0x1d00840000000043\n"
".quad 0x1c95500000003082,0xdc03940000000042,0x00071a8e0000fca5,0xdde4600000036000\n"
".quad 0x29e7280000004003,0x1c03400000030000,0x00074800480590f2,0x9de4600000028000\n"
".quad 0xdc23280000003c03,0x09e7198e00003c85,0x5de4400000020000,0x1ca6280048057002\n"
".quad 0x1ce3140008016131,0x5de45000c00010f3,0x1ca328000000fc03,0x9ce32009c00010f1\n"
".quad 0x5e035000c0001092,0x5c436000c0000892,0x9c03480000003051,0x1c854800480570e3\n"
".quad 0xdc23840000000043,0x5c001a0e00003885,0x5c855000000034c3,0x1c03940000000043\n"
".quad 0x5c43480100002441,0x09e7480000002851,0xdc134003ffff0000,0xdc234800c00800f3\n"
".quad 0x09e7188e480570f5,0x1df44003fffd0000,0xdc04400000000000,0xdc0350ee0000ffff\n"
".quad 0x9de41a8e0000fcb5,0x0007280000004002,0x29e7600000096000,0x5ce3400000092000\n"
".quad 0x1ca65000c0001101,0x1de4140008018133,0x1ca6280000003001,0x1ca3140008016132\n"
".quad 0xdde42009c0001101,0x1de4280000002002,0x5c43280000002403,0x1de44800000014d1\n"
".quad 0x1ec4400000000000,0x5ec41c004805b122,0x5c041c004805b122,0x9c04180400002123\n"
".quad 0x5c00180400002523,0xdc00c800000010d3,0x5c02c800000010e3,0x1c02083ffffff8d3\n"
".quad 0x9c04083ffffff8f5,0x5c04148600003523,0xdc03148600005125,0x5c03500000003883\n"
".quad 0x9c034800c00004a3,0xdf84500000005495,0x1ec41c0000003d23,0x9c431c0000003525\n"
".quad 0xdf84201c00003ce3,0x9c431c0000005923,0x9ec45000000050e3,0xdc431c0000003525\n"
".quad 0x9e03202a00003d53,0xdc43202800003883,0xdc035000000058f3,0x1e03198e00003885\n"
".quad 0x8903202c00003c95,0xdc034800000020e3,0xdc03198e00005097,0x0d03198e00003885\n"
".quad 0xdc23480000002545,0xcc031b0e0000fcd9,0x89034800c00004f3,0xdc034800000020e3\n"
".quad 0x1c831b0e00002547,0xdc2368004805b0d2,0x5dc31a8e4805b3f5,0xb38468004805b3f2\n"
".quad 0xdc231c0000003923,0xcc031b0e0000fc89,0x1c044800c00004f3,0xf384201400003892\n"
".quad 0xdc231c0000003d23,0x5dc31a8e4805b3f5,0xdc2368004805b3f2,0x5c041a8e0000fc87\n"
".quad 0x1c03201400003c92,0x8de74800fffffc82,0x2de4400000008000,0x6c0328004805b002\n"
".quad 0x2c034800fffffc92,0x1de44800fffffc82,0x5c03400000000000,0x9c03480048061092\n"
".quad 0x1c034800c00800a2,0x5c0348004805f082,0x1ca34800fffffc92,0x5ce3201048057092\n"
".quad 0xdc235000c0001082,0x1ca3188e4805d0a5,0x5c432017c0001082,0x1c854800000024c2\n"
".quad 0x1c8587fffffff082,0x1c03940000000042,0x5c434801c0200041,0x09e748000000fc51\n"
".quad 0x1df44003fff80000,0xdc04400000000000,0x9de450ee0000ffff,0x0007280000004002\n"
".quad 0x25e7600000096000,0x5ce3400000092000,0x1ca65000c0001101,0x1de414000801e133\n"
".quad 0x1ca6280000003001,0x1ca3140008016132,0xdde42009c0001101,0x1de4280000002002\n"
".quad 0x5c43280000002403,0x1de44800000014d1,0x1ec4400000000000,0x5ec41c0048067122\n"
".quad 0x5c041c0048067122,0x9c04180400002123,0x5c00180400002523,0xdc00c800000010d3\n"
".quad 0x5c02c800000010e3,0x1c02083ffffff8d3,0x9c04083ffffff8f5,0x5c04148600003523\n"
".quad 0xdc03148600005125,0x5c03500000003883,0x9c034800c00004a3,0xdf84500000005495\n"
".quad 0x1ec41c0000003d23,0x9c431c0000003525,0xdf84201c00003ce3,0x9c431c0000005923\n"
".quad 0x9ec45000000050e3,0xdc431c0000003525,0x9e03202a00003d53,0xdc43202800003883\n"
".quad 0xdc035000000058f3,0x1e03198e00003885,0x8903202c00003c95,0xdc034800000020e3\n"
".quad 0xdc03198e00005097,0x0d03198e00003885,0xdc23480000002545,0xcc031b0e0000fcd9\n"
".quad 0x89034800c00004f3,0xdc034800000020e3,0x1c831b0e00002547,0xdc236800480670d2\n"
".quad 0x5dc31a8e480673f5,0xb3846800480673f2,0xdc231c0000003923,0xcc031b0e0000fc89\n"
".quad 0x1c044800c00004f3,0xf384201400003892,0xdc231c0000003d23,0x5dc31a8e480673f5\n"
".quad 0xdc236800480673f2,0x5c041a8e0000fc87,0x1c03201400003c92,0x8de74800fffffc82\n"
".quad 0x2de4400000008000,0x6c03280048067002,0x2c034800fffffc92,0x1de44800fffffc82\n"
".quad 0x5c03400000000000,0x9c03480048065092,0x1c034800c00800a2,0x5c03480048063082\n"
".quad 0x1ca34800fffffc92,0x5ce3201048057092,0xdc235000c0001082,0x1ca3188e480690a5\n"
".quad 0x5c432017c0001082,0x1c854800000024c2,0x1c8587fffffff082,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x09e748000000fc51,0x1df44003fff80000,0xdc04400000000000\n"
".quad 0x9de450ee0000ffff,0x0007280000004002,0x25f4600000046000,0x1ca6400000000000\n"
".quad 0xdce314000801e131,0x1ca65000c0001102,0x1c03140008018132,0x1ca34800c0080103\n"
".quad 0x5c432009c0001101,0xdc23480000002c51,0x1ca3188e480690c5,0x5c432011c0001102\n"
".quad 0x29e7480000002c92,0x0007400000028000,0x9c03600000024000,0xdc854800c01000a2\n"
".quad 0xdc23840000000082,0x1c85188e480690a5,0xdd00840000000043,0x5c855000000030b2\n"
".quad 0xdc85840000200043,0x1c85940000000042,0x1c03840000200083,0x5c434801c0400082\n"
".quad 0xdd0048000000fc92,0x1c035000000034c2,0xdc854800c00800a3,0xdc23940000200042\n"
".quad 0x1c031884480690c5,0x5c434801c0400041,0x09e748000000fc51,0xdc334003fffde000\n"
".quad 0x29f4188e480690a5,0x1c85400000000000,0x9c85840000000082,0x1d00840000000042\n"
".quad 0x1c95500000002882,0xdc04940000000042,0x1de450ee0000ffff,0x0007280000004006\n"
".quad 0x25e7600000036000,0xdce3400000032000,0x1ca65000c0001102,0x1ca614000801e132\n"
".quad 0x1ca314000801a131,0x9e042011c0001102,0x5c43180048039125,0x9ca3480000002c92\n"
".quad 0xdc432009c0001102,0x1de4480000002c52,0x5de4400000000000,0x1c85280000005801\n"
".quad 0x1c008400000000a1,0xdc85580000001041,0x0007840000000085,0x1d00500000662001\n"
".quad 0x1c00500000001171,0x00073888000013f1,0x9c03500000690001,0x1c854801c02000a2\n"
".quad 0x1c03940000000081,0xdc434800c0080186,0x1c0348000000fcb2,0xdc234801c0200082\n"
".quad 0x5c43188e48069185,0x09e748000000fc92,0x1df44003fffe0000,0xdc04400000000000\n"
".quad 0xdc2350ee0000ffff,0x00071b0e48075105,0xdde4600000040000,0x09f4280000004002\n"
".quad 0x5c03400000000000,0x1ca64800c0080101,0x9ce3140008020132,0x1ca35000c0001102\n"
".quad 0xdc232023c0001101,0x5c43188e48075055,0x1ca34800000048a1,0x5c432011c0001102\n"
".quad 0x29e7480000002892,0x0007400000024000,0xdc03600000020000,0x9c854800c01000b2\n"
".quad 0x9c00840000000042,0xdc235800000028a2,0x9c85188e480750b5,0x1c85940000000082\n"
".quad 0x1c03840000200043,0x5c434801c0400041,0x9c0048000000fc51,0x1c035800000030c2\n"
".quad 0x9c854800c00800b3,0xdc23940000200082,0x1c031884480750c5,0x5c434801c0400082\n"
".quad 0x09e748000000fc92,0xdc334003fffe2000,0x29f4188e480750b5,0x1c85400000000000\n"
".quad 0x1c00840000000041,0x1c95580000001041,0xdc04940000000081,0xdc2350ee0000ffff\n"
".quad 0x00071b0e48038105,0x9de4600000044000,0x09e7280000004003,0x1de440000003e000\n"
".quad 0x1c03280040000001,0x5ce34801c0a29041,0x1c435000c0001101,0xdc2348000000fff2\n"
".quad 0x1ca3188e480373f5,0x5c432009c0001101,0x29e7480000001481,0x9ca340000001e000\n"
".quad 0x5de45000480370e2,0x000728000000fc03,0x5ce360000001c000,0x1ca35000c00010a2\n"
".quad 0xdc032023c00010a2,0x5c434800480370a2,0x9c03480000002522,0x1c854800c00004a2\n"
".quad 0xdc23840000000083,0x1c031a8e00002ca7,0x5c434801c0001082,0x5c0048000000fc92\n"
".quad 0x0de75000000034c3,0x1df44003ffff2000,0x5de4400000000000,0x1de728000000fc03\n"
".quad 0x9c03400000000000,0x5c854800c00800e3,0xdc23940000000043,0x1c03188e480380e7\n"
".quad 0x5c434801c0200041,0x0de748000000fc51,0x1df44003fffd0000,0x9c03280040000001\n"
".quad 0xdc434801c0a29042,0xdc0448000000fff2,0xdc2350ee0000ffff,0x00071b0e48073105\n"
".quad 0x9de4600000052000,0x09e7280000004003,0x1de440000004c000,0x5ce3280040000001\n"
".quad 0x1c035000c0001101,0xdc234801c0a5c041,0x1c43188e480743f5,0xdde448000000fff2\n"
".quad 0x1ca3280000004003,0x1c232009c0001101,0x5c437000c0047d05,0x29e7480000001481\n"
".quad 0x1c03400000024000,0x1ca65800c00078f2,0x5de4140008020133,0x5c43280048073005\n"
".quad 0x1c03400000002142,0xdde42019c00010f2,0x9ce328000000fc05,0x1de45000c0001155\n"
".quad 0x5e0328000000fc03,0x5c436000c0000955,0x1c034800000024d2,0x5c854800c00004c3\n"
".quad 0xdc23840000000083,0x1c031a8e480740c7,0x5c43480100002152,0xdc00480000002562\n"
".quad 0x0de7500000005cd5,0x1de74003ffff2000,0xdde4400000004000,0x1de428000000fc05\n"
".quad 0xdc03400000000000,0xdc854801c00800f3,0x9c03940000000045,0x1c434800c00800e3\n"
".quad 0x1c0348000000fd45,0xdc234801c0200041,0x5c43188e480730e7,0x0de748000000fc51\n"
".quad 0x1df44003fffc6000,0x1c03280040000001,0x5c434801c0a5c041,0xdc0448000000fff1\n"
".quad 0xdc2350ee0000ffff,0x0007190e0000fd05,0x29e760000003a000,0xdc2340000001a000\n"
".quad 0x1de41b0e480383f7,0x0de728000000fc01,0x1de4400000012000,0x5c8528000000fc02\n"
".quad 0x1c038400000000a1,0x9c034800c0000482,0xdc234801c00010a2,0xdc431a8e48038087\n"
".quad 0x1c0048000000fcb2,0x0de7500000001051,0x1c954003ffff2000,0xdc95c90000b953f1\n"
".quad 0xdc23c90000b953ff,0x0df41a8ec0000507,0xdc23400000000000,0x1de41b0e480743f7\n"
".quad 0x0de728000000fc02,0x9de4400000012000,0x5c8528000000fc02,0x9c03840000000042\n"
".quad 0xdc234800c00004a2,0x1c031a8e480740a7,0x5c434801c0001041,0x1c0048000000fc51\n"
".quad 0x0de7500000002092,0x1c954003ffff2000,0xdc95c90000b963f2,0xdc04c90000b963ff\n"
".quad 0x000750ee0000ffff,0x29f4600000024000,0x9e04400000000000,0x1c85180048039122\n"
".quad 0x5de4c10000b953f1,0x0007280000002801,0x5de450000050c001,0x1de4280048039001\n"
".quad 0x5c03280000001002,0x1e044800fffffc51,0x0007180000001521,0x5de4500000536001\n"
".quad 0x5de4280000001002,0x1c85280000002801,0x0007c10000b963f1,0x1e005000004fa001\n"
".quad 0x0007300800002081,0x1c0050000052a001,0x1c95580000001091,0xdc04c90000b973f1\n"
".quad 0x5de450ee0000ffff,0x0007280000004002,0x25f460000003c000,0x1ca6400000000000\n"
".quad 0x1c0314000801e133,0x5ce34800c0080101,0x1de45000c0001101,0xdc23280000003002\n"
".quad 0x9de4188e48069047,0x1ca3280000003402,0x5c432011c0001101,0x1c854800000014a1\n"
".quad 0x2de7c10000b973f2,0x0007400000020000,0x5c0360000001c000,0x9c854800c0100092\n"
".quad 0xdc23840000000042,0xdc85188e48069097,0x9c00840000200042,0xdc005800000020a2\n"
".quad 0x9c855800000020b2,0x9c03940000000042,0xdc854800c0080092,0xdc23940000200042\n"
".quad 0x1c031886480690a7,0x5c434801c0400041,0x0de748000000fc51,0xdc334003fffe6000\n"
".quad 0x2df4188e48069097,0x5c85400000000000,0x1c00840000000042,0x1c95580000002092\n"
".quad 0xdc04940000000042,0x5de450ee0000ffff,0x0007280000004006,0x21e7600000034000\n"
".quad 0x1ce3400000030000,0x1ca65000c0001103,0x9ca314000800e132,0x1ca62011c0001102\n"
".quad 0xdc4314000801a131,0x9c85480000003092,0x1ca3c10000b953f5,0x1e042009c0001102\n"
".quad 0x5c43180048039126,0x1de4480000003052,0x5de4400000000000,0x1c85280000006001\n"
".quad 0x1c00840000000081,0xdc85580000005841,0x00078400000000a5,0x1d0050000048a001\n"
".quad 0x1c03500000001171,0x5c034801c0200082,0x5c434800c0080196,0x1c8548000000fc92\n"
".quad 0xdc239400000000a1,0x9c03188e48041191,0xdc434801c02000a2,0x01e748000000fcb2\n"
".quad 0x1df44003fffe4000,0xdc04400000000000,0x9de450ee0000ffff,0x0007280000004005\n"
".quad 0x25e7600000028000,0xdce3400000024000,0x1ca65000c0001102,0x1ca614000801e132\n"
".quad 0x1ca314000800e131,0x5c432011c0001102,0x9ca3480000002c92,0xdc432009c0001102\n"
".quad 0x1c85480000002c52,0x5c858400000000a1,0x0007840000000081,0x1c8550000045a001\n"
".quad 0x9c03940000000081,0x9c034801c02000a2,0xdc434800c0080165,0xdc2348000000fcb2\n"
".quad 0x1c03188e48069161,0x5c434801c0200082,0x01e748000000fc92,0x1df44003fffea000\n"
".quad 0xdc04400000000000,0x9de450ee0000ffff,0x1ca6280048008002,0x1ca3140008004132\n"
".quad 0x1ca62000880020a0,0x9ce3140008006131,0x1ca35000c0001002,0x5c432011c0001003\n"
".quad 0x9ca3480000002893,0x1c852009c0001003,0xdc4387fffffff0c2,0x1c85480000002853\n"
".quad 0x5de4840000000061,0x1c85280048005002,0x9de487fffffff0e0,0x5c85280048004002\n"
".quad 0xdc23840000000021,0x00071b0e48079101,0x1c64600000056000,0x5c64c210e4062892\n"
".quad 0x1d03c200e4062892,0x1de4480000001482,0x5d03280000004000,0x01e7480000001092\n"
".quad 0xdc03400000048000,0x1ca64800c0180102,0x9ce3140008022131,0x1ca35000c0001102\n"
".quad 0xdc23201048077092,0x1ca3188e480790b1,0x5c432009c0001101,0x21e7480000002851\n"
".quad 0x000740000002a000,0x5ca3600000026000,0x9c03110e00000082,0xdc034800c0100002\n"
".quad 0x1c034800c0180002,0x9ca34800c0080005,0x5c85110e00002882,0xdca3940000000042\n"
".quad 0x1c03110e00002c82,0x9c854800c0200000,0x5ca3940000400042,0xdc85110e00005082\n"
".quad 0xdc23940000600042,0x9c03188e48079001,0x5c854800c0300142,0xdc23940000200042\n"
".quad 0x1c031880480790a1,0x5c434801c0800041,0x01e748000000fc51,0xdc334003fffdc000\n"
".quad 0x21e7188e48079001,0x5ca340000000e000,0x1c03110e00000082,0x5c854800c0080000\n"
".quad 0xdc23940000000042,0x1c03188e48079001,0x5c434801c0200041,0x01e748000000fc51\n"
".quad 0x1df44003ffff2000,0xdc04400000000000,0xdc2350ee0000ffff,0x00071b0e48081101\n"
".quad 0x1de46000000e6000,0x01e7280000004000,0xdce34000000e0000,0x1ca65000c0001102\n"
".quad 0x1ca3140008026131,0x1ca62009c0001101,0x5c4314000801e132,0x9ca3480000002c51\n"
".quad 0xdc432011c0001102,0x1de4480000002c92,0x1ec4400000000000,0x5ec41c004807f122\n"
".quad 0x1c041c004807f122,0x5c04180400002125,0x1c00180400002525,0x5c00c80000001145\n"
".quad 0x1c02c80000001155,0x5c02083ffffff945,0xdc04083ffffff955,0x9c04148600005125\n"
".quad 0x5c03148600005525,0x5c03500000005c85,0x1c03500000005896,0x1f844800c0000405\n"
".quad 0x5f841c0000005526,0x5ec41c0000006526,0x1c431c0000005125,0x9c43202e00006176\n"
".quad 0xdec4202c00006565,0x1c431c0000005125,0x9c43500000005586,0x5e03500000005d65\n"
".quad 0xde03202a00006085,0xdc03202e00005895,0xdc03198e00005481,0x4103198e00005c93\n"
".quad 0xc503480000002155,0xdc03480000002575,0x8403198e00005481,0x1c834800c0000565\n"
".quad 0xdc2368004807f146,0xdc031b0e0000fd47,0x41031b0e00002573,0xdc23480000002155\n"
".quad 0xdc231b0e0000fd89,0x1dc31a8e4807f3f1,0x840368004807f3f2,0x6f844800c0000565\n"
".quad 0xdc231c0000005525,0x5dc31a8e4807f3f3,0xb38468004807f3f2,0x1c041c0000005925\n"
".quad 0x5c04201000005482,0xdc23201200005892,0x1c031a8e0000fc87,0x00074800c0000495\n"
".quad 0x2de4600000060000,0x2de4280000002405,0x5c0328004807f002,0x1c03480048084142\n"
".quad 0x5d034800c0000495,0xdc2348004807c095,0xdc231a0e48078093,0x1c031a0e4807c141\n"
".quad 0x5c044800c0000555,0x1c04201248078092,0xdc232000c0000546,0x01e7188e00006091\n"
".quad 0x1c03400000046000,0xdde4480048083082,0x1c0328000000fc05,0x5d034800c0000485\n"
".quad 0xdc2348004807b085,0xdc231a0e48077081,0x1c031a0e4807b143,0x1c044800c0000555\n"
".quad 0x5c04201048077082,0x5c032002c0000545,0x1c034800c0000486,0xdc234800c0000495\n"
".quad 0x00071b0e00005481,0x21e7600000026000,0x9de4400000022000,0x1ca6280048077005\n"
".quad 0x9da3140008022132,0xdde4202c48077185,0x9c03280000002406,0x1ca3480000005566\n"
".quad 0x5ce32011c00011a2,0x9c035000c00011a2,0x5c43480000006565,0x1de44800000025b2\n"
".quad 0x9c03400000000000,0xdc854800c00005a6,0xdc2387fffffff086,0x1c031a8e000059a3\n"
".quad 0x5c434801c0001082,0xdc0048000000fc92,0x05e7500000005db5,0x1c134003ffff2000\n"
".quad 0xdc234800c0000586,0x05e71a8e00006143,0x1df44003fffd4000,0xddf4400000000000\n"
".quad 0x1c0328000000fc05,0x1c854800c0080000,0x9c038400000000a2,0xdc234801c02000a2\n"
".quad 0xdc43188e48081001,0x1c0048000000fcb2,0x1c85580000005c82,0x1c03940000000042\n"
".quad 0x5c434801c0200041,0x01e748000000fc51,0x1df44003fff30000,0xdc04400000000000\n"
".quad 0xdc2350ee0000ffff,0x00071b0e4807f101,0x01e7600000054000,0x5de4400000050000\n"
".quad 0x1c03280040000001,0xdc234801c0a8f050,0x1c43188e480803f1,0x1de448000000fff1\n"
".quad 0x9c0328000000fc05,0x5ce34801c0b12052,0xdc435000c0001101,0x1ca348000000fff2\n"
".quad 0x5c432001c0001102,0x1de4480000001052,0x1ca328000000fc00,0x5c432015c0001101\n"
".quad 0x21e7480000002c51,0x5ca3400000022000,0x9ca650004807f105,0x0007140008026132\n"
".quad 0xdce360000001c000,0x9ca35000c0001155,0x9c032015c0001152,0xdc43480048080155\n"
".quad 0xdc85480000005cb2,0x9c038400000000a5,0xdc434801c00010a2,0xdc8048000000fcb2\n"
".quad 0x05e4220e00000173,0x0444280000005405,0x5c03100000005d20,0xdc234800c0000555\n"
".quad 0x05e71a8e00005953,0x1df44003fffee000,0x1c03400000000000,0x1c854800c0080104\n"
".quad 0x1c03940000000085,0x1c854801c0200082,0xdc23940000000040,0x5c43188e4807f103\n"
".quad 0x1c0348000000fc92,0x5c434801c0200041,0x05e748000000fc51,0x1df44003fffca000\n"
".quad 0x1c03280040000000,0xdc434801c0a8f004,0x1c0348000000fff4,0x5c434801c0b12001\n"
".quad 0xdc0448000000fff1,0x000750ee0000ffff,0x29f46000000b0000,0xdc23400000000000\n"
".quad 0x01e71b0e4807f3f1,0x1de4400000028000,0x5de428000000fc05,0xdde428000000fc05\n"
".quad 0x1de428000000fc02,0x1de428000000fc02,0x9c8528000000fc00,0xdc00840000000042\n"
".quad 0xa1e7220e000000a1,0x0003400000008000,0x01e4480100004142,0x4043280000002800\n"
".quad 0x0085480000004d52,0x1c03840000000082,0xdc034801c0001145,0x5c434800c00004b2\n"
".quad 0x1c0348000000fd55,0xdc234801c0001041,0x5c431a8e4807f0b1,0x01e748000000fc51\n"
".quad 0x1de74003fffe4000,0x1de4400000004000,0x1de428000000fc02,0x1ec4400000000000\n"
".quad 0x1ec41c004807f121,0x5c041c004807f120,0x5c00180400001121,0x5c04c80000001051\n"
".quad 0x5c02180400000122,0x9c00083ffffff851,0x5c04c80000001092,0xdc02148600001522\n"
".quad 0x5c03083ffffff8a2,0x9c034800c0000481,0xdc04500000002442,0x1f84148600002d22\n"
".quad 0x9ec41c0000002922,0x1c031c0000001522,0x1c43500000002c04,0xdc23201200002092\n"
".quad 0x5f841b0e0000fc55,0x1c431c0000004122,0x1ec4500000002882,0x5c431c0000001524\n"
".quad 0x1e032016000024b2,0x5c43201400002042,0xdc03500000004092,0x9e03198e00002041\n"
".quad 0x0103202000002402,0xdc03480000001082,0xdc03198e00002803,0x8503198e00002041\n"
".quad 0x44034800000000a2,0x01034800c0000492,0xdc03480000001082,0xdc231b0e000000a3\n"
".quad 0x1c831a8e4807f3f1,0x1dc368004807f051,0x2b8468004807f3f0,0x44031c0000002122\n"
".quad 0xdc234800c0000492,0x1c041b0e0000fc45,0xdc23201000002000,0x1dc31a8e4807f3f1\n"
".quad 0x6b8468004807f3f1,0xdc231c0000002522,0x1c031a8e0000fc03,0x1c044800fffffc00\n"
".quad 0x85e7201000002441,0x25e4400000006000,0x240328004807f000,0x24034800fffffc41\n"
".quad 0x5de44800fffffc00,0x9c85280048004001,0x1d03840000000020,0x5d03480048037000\n"
".quad 0x1d03480048005051,0xdd03480000001400,0x1c03480048038040,0x9c03480000000020\n"
".quad 0x9c854800c0000400,0x9d039400000000c0,0x1c85480000001430,0x1c03840000000060\n"
".quad 0x1c03480000000800,0x1c954800c0000400,0xdc049400000000e0,0x1ec450ee0000ffff\n"
".quad 0x1c431c0048002120,0x1c23500040000400,0xdc235800c0000c00,0x9f841a0e480023f1\n"
".quad 0xdde41c0000000120,0x1c04280048002000,0xdc23200000000020,0x1ea31a8e480023f1\n"
".quad 0xdc232006c0002800,0x21e719000000fc01,0x1c04800000000000,0x9ca32c0000009400\n"
".quad 0xdde45000c0028000,0x1c86280048008000,0x5ca3140008090020,0x1cc6200088002032\n"
".quad 0xdce3140008088021,0x1ca35000c0001092,0x5c43200dc0001093,0x9ca6480000002c73\n"
".quad 0xdde4140008086023,0x1c85280000003800,0x9ce38400000000c2,0x9ca65000c0001002\n"
".quad 0x1de414000808c021,0x9ca3280000003c03,0xdc432007c0001000,0x9ca34800000028c0\n"
".quad 0xdc43200dc0001091,0x1ca3480000002c71,0x1c852009c0001001,0x9c85940000000022\n"
".quad 0x5c43840000000061,0x1c04480000002851,0xdc232c0000008400,0x9c851b0e48039001\n"
".quad 0x01e7940000000041,0x9ca3800000000000,0xdce32023c0001001,0x1c045000c0001001\n"
".quad 0xdc43100048007132,0x1e01480000001d21,0xdec44800cffc0082,0x9ec41c0048037122\n"
".quad 0x1c041c0048037122,0x5c04180400002d23,0x1c00180400002923,0x5c00c800000010c3\n"
".quad 0x1c02c800000010d3,0xdc02083ffffff8c3,0x1c04083ffffff8d3,0x1c04148600003123\n"
".quad 0x5c03148600003d24,0x9c035000000030b3,0x5c034800c0000403,0x5f845000000040a4\n"
".quad 0xdec41c0000003523,0x1c431c0000003923,0x5f842018000034c3,0x1c431c0000004523\n"
".quad 0x5ec4500000003cc3,0x5c431c0000003924,0x1e03202000003503,0x5c43201e000030b3\n"
".quad 0xdc035000000044d3,0xde03198e000030b1,0x01032022000034a3,0xdc03480000002cc3\n"
".quad 0xdc03198e00003ca3,0xc503198e000030b1,0xdc234800000028f3,0x44031b0e0000fce5\n"
".quad 0x01034800c00004d3,0xdc03480000002cc3,0xdc831b0e000028f3,0xdc236800480370e2\n"
".quad 0x9dc31a8e480373f1,0x2b846800480373f2,0xdc231c0000003123,0x44031b0e0000fcb5\n"
".quad 0x9c044800c00004d3,0xddc32010000030a2,0xdc236800480373f2,0x6b841a8e480373f1\n"
".quad 0xdc231c0000003523,0x1c041a8e0000fca3,0x5c032010000034b3,0x85e74800fffffca3\n"
".quad 0xa5e4400000008000,0x2403280048037002,0x64034800fffffcc3,0x1de44800fffffca3\n"
".quad 0x1c03400000000000,0x9c854800c0080000,0xdc23840000000042,0xdc85188e48039001\n"
".quad 0x1c03840000000022,0x9c034800000030a3,0xdc034800000034b2,0x9ca34800ffff98c2\n"
".quad 0xdde42014480090b2,0x9c03280048000002,0x1ca34800ffff98a2,0x9ce32017c00010a3\n"
".quad 0x5c435000c00010a2,0xdc854800480010a3,0x9c85840000000062,0xdc008400000000c2\n"
".quad 0x1c045800480070b2,0x9c04100000002d33,0x9c01100000002932,0x9c042018000020a2\n"
".quad 0x9c851000000029a2,0x9c03940000000062,0xdc434801c0200061,0x01e748000000fc71\n"
".quad 0x1de74003fff6c000,0x1c03800000000000,0x5c036000c0000443,0x1c036000c0000453\n"
".quad 0x5c035800c00060c3,0x1c035800c00060d3,0x5c034800fffffcc3,0xdc034800fffffcd3\n"
".quad 0xdc031a0ec003f4c7,0x2de71a26c003f4d7,0xdc8040000004e000,0x2de7218edfe00047\n"
".quad 0xdc80400000004000,0x0de7218edfe00057,0x1c00400000004000,0x1de7500000001441\n"
".quad 0x9c034000000be000,0xdc036000c0000443,0xdc036000c0000453,0xdc03190e0000fce7\n"
".quad 0xdc04190e0000fcf9,0x15e70c0e0000103b,0xdc80400000008000,0xdc80210edfe0004b\n"
".quad 0x35e7210edfe0005d,0x39e7400000008000,0x1de2400000006000,0x1c001bff00000001\n"
".quad 0x1de7c80000001441,0xdc044000000a4000,0x2de70c0e00004c67,0x1c83400000006000\n"
".quad 0x1c02680000001051,0x1de73a0000000041,0xdc0440000009a000,0x2de70c0e00005057\n"
".quad 0x1c83400000008000,0x1c02680000001051,0x1c423a0000000041,0x1de739fe00000041\n"
".quad 0xdc2340000008e000,0xdc231b0e0000fcc9,0x30001b0e0000fcd7,0xb1e2307ed7e00041\n"
".quad 0x91e41bffffff0003,0x0de728000000fc03,0x5c0040000000a000,0x9c03307ed7e00051\n"
".quad 0x1de74800c00100e3,0x9de4400000004000,0x1de428000000fc03,0xdc03400000000000\n"
".quad 0xdee34800fffe08d3,0x5d034100000014f3,0x1c004800000034c3,0x5c03c800000010f5\n"
".quad 0x5e004800fffe08c1,0x1ee33028800014f5,0x5c00410000001051,0x5c00302800005545\n"
".quad 0x1e00307e00005441,0x5c003008000014f5,0xde00300a00005541,0x1c003008000014f3\n"
".quad 0x1c03300a000054f1,0x1c046000c0000445,0x5c03c21ce00350d3,0xdc034800fffffcc3\n"
".quad 0x5c031a0ec003f4d7,0x0de75800c0006143,0x5d03400000006000,0x1ee34800000034c3\n"
".quad 0x1de74000000010d1,0xdc2340000004c000,0x0de7198ec003f8c7,0x1c02400000006000\n"
".quad 0x1c423a0000000041,0x1de739fe00000041,0xdc23400000042000,0x0de71a0e0000fcc7\n"
".quad 0xdc2340000003e000,0x0de71b0effffa0c7,0x1c02400000004000,0x1de73a0000000041\n"
".quad 0x5c00400000036000,0x9c00308a000054f3,0x1f84310a000054f3,0x5c001c0000003125\n"
".quad 0x5c00318a000054f1,0xdc23168e000038d3,0x5c02190e0000fd47,0x1c023801fffffc51\n"
".quad 0x9f843a0000000041,0x5f841c0000003123,0x5c421c0000003523,0x8de7380200000051\n"
".quad 0x2c0340000000c000,0x2c034800c00080c3,0x2c03600000003053,0x6c033118c00007f3\n"
".quad 0x6c43580000003851,0x1de46800000030d3,0x9c03400000000000,0x1c036000c0007853\n"
".quad 0x9c036800c0000453,0x5c035800c0007ce3,0x5c435800c0000451,0x5c036800000038d3\n"
".quad 0xdc036800000034c3,0x4c031a8e0000fcd7,0x1c434800c0000451,0x1de7680000001441\n"
".quad 0x5c02900000000000,0x9c0239fe00000043,0x1d0339fe00000053,0xdc234800000038d3\n"
".quad 0x5c02198e400014c7,0xdc230bfe000000d3,0x9c021b06400024c7,0xdc030bfe000000e3\n"
".quad 0xdc031986400034d7,0x2de71986400034e7,0x5c0240000001c000,0x5c023a01fffffc51\n"
".quad 0x5c423a01fffffc43,0x5c4238fe00000051,0x9c0038fe000000d3,0x1e00c80000001053\n"
".quad 0x1c00301c80001451,0x9c00301c000010e1,0xde00307e000010d3,0x9c00301a00003853\n"
".quad 0x5e00301c000010f3,0x1c00301a00003853,0x1c03301c000010d1,0x1de74800000010c1\n"
".quad 0x0007400000002000,0x1de75003ffef0001,0x5c02900000000000,0xdc030bcc00000041\n"
".quad 0x0de7198e40004457,0x5c02400000022000,0xdc2339fffffffc41,0x2de71a8e0000fc57\n"
".quad 0xdc00400000032000,0x2de7288e0000fc47,0x1de2400000004000,0x1de719fffffffc01\n"
".quad 0xdc8040000002a000,0x5c44298edfe00047,0x0de7108000001121,0x1c20400000004000\n"
".quad 0x1de75000cfe00041,0xdc00400000020000,0x0de7290edfe00057,0x1c0040000001c000\n"
".quad 0xdc04307ed7e00041,0x1de70c0e00001c77,0xdc04400000004000,0x1de40c0e00001cf7\n"
".quad 0x5c00400000000000,0x1c40c80000001441,0x5c40580000001053,0x5e005800cfc00051\n"
".quad 0x1c00300a800054c3,0x5c003018000034c3,0x1e00300a00003451,0x1c003008000030c1\n"
".quad 0x0c40301800001441,0x1de75800cbe00041,0x0000900000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0xcccd000000000000,0x00003f800000cccc\n"
".quad 0xffff7effffffc180,0x0a043f000000727f,0x00000000000b0008,0x01b000080d040020\n"
".quad 0x0000000000200024,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x1204000000000000\n"
".quad 0x0000000000100008,0x0010000811040000,0x1204000000000000,0x00000000000f0008\n"
".quad 0x000f000811040000,0x1204000000000000,0x00000000000e0008,0x000e000811040000\n"
".quad 0x1204000000000000,0x00000000000d0008,0x000d000811040000,0x0000000000000000\n"
".quad 0x0000000500000006,0x00000000000074f8,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000000e0,0x00000000000000e0,0x0000000000000004,0x00000d0560000000\n"
".quad 0x000000000000061e,0x0000000000000000,0x0000000000000000,0x0000000000004c80\n"
".quad 0x0000000000004c80,0x0000000000000004,0x00000d0660000000,0x000000000000529e\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000002e60\n"
".quad 0x0000000000000004,0x0000000500000001,0x000000000000529e,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000000021f8,0x00000000000021f8,0x0000000000000004\n"
".quad 0x0000008001000001,0x000000000000f0f8,0x0000003800000000,0x0000001400020003\n"
".quad 0x0000003f00000040,0x0000000000000015,0x0000000000000000,0x0000000000000000\n"
".quad 0x6f6e2f656d6f682f,0x6568632f6c616d72,0x70672f74756f6b63,0x2f746f6c65636f75\n"
".quad 0x6f722f7374736574,0x65742f61696e6964,0x2f7477682f737473,0x0075632e6e69616d\n"
".quad 0x6f69737265762e09,0x2e090a332e32206e,0x7320746567726174,0x612e090a30325f6d\n"
".quad 0x735f737365726464,0x090a343620657a69,0x69706d6f63202f2f,0x687469772064656c\n"
".quad 0x6f6c2f7273752f20,0x616475632f6c6163,0x2f34366e65706f2f,0x0a65622f2f62696c\n"
".quad 0x706f766e202f2f09,0x302e342063636e65,0x6f20746c69756220,0x302d31313032206e\n"
".quad 0x2f090a0a38312d32,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x696c69706d6f4320,0x2f706d742f20676e,0x305f746678706d74\n"
".quad 0x5f33653532303030,0x3030303030303030,0x2e6e69616d5f372d,0x2820692e33707063\n"
".quad 0x4263632f706d742f,0x56615155792e2349,0x2d2d2f2f090a2935,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2f2f090a0a2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x704f202f2f090a2d,0x090a3a736e6f6974\n"
".quad 0x2d2d2d2d2d2d2f2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2f090a2d2d2d2d2d\n"
".quad 0x656772615420202f,0x49202c7874703a74,0x30325f6d733a4153,0x6e6169646e45202c\n"
".quad 0x2c656c7474696c3a,0x7265746e696f5020,0x34363a657a695320,0x4f2d20202f2f090a\n"
".quad 0x6d6974704f280933,0x206e6f6974617a69,0x090a296c6576656c,0x0930672d20202f2f\n"
".quad 0x6c20677562654428,0x2f090a296c657665,0x2809326d2d20202f,0x612074726f706552\n"
".quad 0x6569726f73697664,0x2d2d2f2f090a2973,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x6c69662e090a0a2d,0x6f633c2209310965,0x696c2d646e616d6d\n"
".quad 0x662e090a223e656e,0x2f22093209656c69,0x78706d742f706d74,0x32303030305f7466\n"
".quad 0x303030305f336535,0x6d5f362d30303030,0x616475632e6e6961,0x227570672e326566\n"
".quad 0x09656c69662e090a,0x656d6f682f220933,0x2f6c616d726f6e2f,0x74756f6b63656863\n"
".quad 0x6c65636f7570672f,0x73747365742f746f,0x61696e69646f722f,0x682f73747365742f\n"
".quad 0x6e696665642f7477,0x662e090a22632e65,0x2f22093409656c69,0x2f62696c2f727375\n"
".quad 0x5f3638782f636367,0x78756e696c2d3436,0x342e342f756e672d,0x756c636e692f352e\n"
".quad 0x65646474732f6564,0x662e090a22682e66,0x2f22093509656c69,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x72632f6564756c63,0x6563697665642f74\n"
".quad 0x656d69746e75725f,0x69662e090a22682e,0x752f22093609656c,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x736f682f6564756c,0x656e696665645f74\n"
".quad 0x662e090a22682e73,0x2f22093709656c69,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x75622f6564756c63,0x79745f6e69746c69,0x090a22682e736570\n"
".quad 0x093809656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x745f656369766564,0x0a22682e73657079,0x3909656c69662e09\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x5f7265766972642f,0x22682e7365707974,0x09656c69662e090a,0x7273752f22093031\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x61667275732f6564\n"
".quad 0x73657079745f6563,0x69662e090a22682e,0x2f2209313109656c,0x61636f6c2f727375\n"
".quad 0x622f616475632f6c,0x6e692f2e2e2f6e69,0x65742f6564756c63,0x79745f6572757478\n"
".quad 0x090a22682e736570,0x323109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f726f746365762f,0x22682e7365707974\n"
".quad 0x09656c69662e090a,0x7273752f22093331,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x63697665642f6564,0x68636e75616c5f65,0x74656d617261705f\n"
".quad 0x090a22682e737265,0x343109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x6f74732f7472632f,0x616c635f65676172\n"
".quad 0x2e090a22682e7373,0x09353109656c6966,0x6e692f7273752f22,0x69622f6564756c63\n"
".quad 0x73657079742f7374,0x69662e090a22682e,0x2f2209363109656c,0x6c636e692f727375\n"
".quad 0x656d69742f656475,0x69662e090a22682e,0x2f2209373109656c,0x726f6e2f656d6f68\n"
".quad 0x636568632f6c616d,0x7570672f74756f6b,0x742f746f6c65636f,0x646f722f73747365\n"
".quad 0x7365742f61696e69,0x6b2f7477682f7374,0x75632e6c656e7265,0x6c69662e090a2268\n"
".quad 0x682f220938310965,0x6d726f6e2f656d6f,0x6b636568632f6c61,0x6f7570672f74756f\n"
".quad 0x65742f746f6c6563,0x69646f722f737473,0x747365742f61696e,0x616d2f7477682f73\n"
".quad 0x090a2275632e6e69,0x393109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f6e6f6d6d6f632f,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209303209656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x636e75665f687461,0x22682e736e6f6974\n"
".quad 0x09656c69662e090a,0x7273752f22093132,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x5f6874616d2f6564,0x746e6174736e6f63,0x662e090a22682e73\n"
".quad 0x2209323209656c69,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x642f6564756c636e,0x75665f6563697665,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220933320965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x5f6d732f6564756c,0x696d6f74615f3131,0x6974636e75665f63,0x090a22682e736e6f\n"
".quad 0x343209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x615f32315f6d732f,0x75665f63696d6f74,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220935320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x6c62756f645f3331,0x6974636e75665f65\n"
".quad 0x090a22682e736e6f,0x363209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x615f30325f6d732f,0x75665f63696d6f74\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220937320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x6972746e695f3032\n"
".quad 0x22682e736369736e,0x09656c69662e090a,0x7273752f22093832,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x61667275732f6564,0x74636e75665f6563\n"
".quad 0x0a22682e736e6f69,0x3209656c69662e09,0x2f7273752f220939,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x7275747865742f65,0x5f68637465665f65\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209303309656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x636e75665f687461\n"
".quad 0x62645f736e6f6974,0x682e337874705f6c,0x6e6f632e090a0a22,0x67696c612e207473\n"
".quad 0x2038622e2038206e,0x6e6f6d6d6f635f64,0x5b65676e6168635f,0x632e090a3b5d3631\n"
".quad 0x6c612e2074736e6f,0x622e2038206e6769,0x6d6d6f635f642038,0x3b5d3032355b6e6f\n"
".quad 0x74736e6f632e090a,0x206e67696c612e20,0x5f642038622e2038,0x385b657571696e75\n"
".quad 0x090a0a3b5d303631,0x5f207972746e652e,0x6c656e72656b365a,0x722e090a7b090a76\n"
".quad 0x203233752e206765,0x3b3e3132363c7225,0x2e206765722e090a,0x3c64722520343675\n"
".quad 0x2e090a3b3e383931,0x3233662e20676572,0x3b3e36393c662520,0x2e206765722e090a\n"
".quad 0x3c64662520343666,0x65722e090a3b3e38,0x20646572702e2067,0x3b3e3732313c7025\n"
".quad 0x65726168732e090a,0x6e67696c612e2064,0x5f2038622e203420,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x345f7261765f6c61,0x5f32335f32383434,0x736e6f635f6e6f6e\n"
".quad 0x6d5f6e695f645f74,0x38706d65745f646f,0x303430315b363936,0x68732e090a3b5d34\n"
".quad 0x6c612e2064657261,0x622e2034206e6769,0x616475635f5f2038,0x5f616475635f5f5f\n"
".quad 0x61765f6c61636f6c,0x5f30373434345f72,0x635f6e6f6e5f3233,0x5f6e695f74736e6f\n"
".quad 0x5f6c616974726170,0x30303139316d7573,0x090a3b5d3430325b,0x206465726168732e\n"
".quad 0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3434345f7261765f,0x6f6e5f32335f3137,0x5f74736e6f635f6e,0x705f7271735f6e69\n"
".quad 0x735f6c6169747261,0x5b34303339316d75,0x2e090a3b5d343032,0x2e20646572616873\n"
".quad 0x2034206e67696c61,0x75635f5f2038622e,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x383434345f726176,0x6e6f6e5f30335f30,0x705f74736e6f635f,0x635f78616d5f7261\n"
".quad 0x5b38303539316f6f,0x2e090a3b5d343235,0x2e20646572616873,0x2034206e67696c61\n"
".quad 0x75635f5f2038622e,0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x373434345f726176\n"
".quad 0x6e6f6e5f32335f39,0x705f74736e6f635f,0x765f78616d5f7261,0x5b32333030326c61\n"
".quad 0x2e090a3b5d343235,0x2e20646572616873,0x75635f5f20323366,0x6c61636f6c5f6164\n"
".quad 0x3434345f7261765f,0x6f6e5f32335f3237,0x5f74736e6f635f6e,0x6c616e69665f6e69\n"
".quad 0x2e090a3b6d75735f,0x2e20646572616873,0x75635f5f20323366,0x6c61636f6c5f6164\n"
".quad 0x3434345f7261765f,0x6f6e5f32335f3337,0x5f74736e6f635f6e,0x665f7271735f6e69\n"
".quad 0x6d75735f6c616e69,0x726168732e090a3b,0x203233662e206465,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f38373434345f,0x6f635f6e6f6e5f32,0x6f6e65645f74736e\n"
".quad 0x202f2f090a3b546d,0x6c5f616475635f5f,0x7261765f6c61636f,0x395f31333434345f\n"
".quad 0x6e6f635f6e6f6e5f,0x206e695f645f7473,0x6f6c2e090a30203d,0x3009370937310963\n"
".quad 0x67656257444c240a,0x656b365a5f5f6e69,0x090a3a766c656e72,0x74736e6f632e646c\n"
".quad 0x722509203233732e,0x6f635f645b202c31,0x6168635f6e6f6d6d,0x0a3b5d382b65676e\n"
".quad 0x3233752e766f6d09,0x30202c3272250920,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x317225202c317025,0x090a3b327225202c,0x6172622031702540,0x5f305f744c240920\n"
".quad 0x090a3b3630353538,0x09373109636f6c2e,0x6f6d090a30093039,0x2509203436752e76\n"
".quad 0x755f64202c316472,0x090a3b657571696e,0x2e3233732e747663,0x3372250920323375\n"
".quad 0x646961746325202c,0x747663090a3b782e,0x3233732e3436732e,0x202c326472250920\n"
".quad 0x756d090a3b337225,0x732e656469772e6c,0x3364722509203233,0x31202c337225202c\n"
".quad 0x646461090a3b3036,0x722509203436752e,0x31647225202c3464,0x0a3b33647225202c\n"
".quad 0x736e6f632e646c09,0x2509203436752e74,0x72255b202c356472,0x0a3b5d32332b3464\n"
".quad 0x736e6f632e646c09,0x2509203233732e74,0x6472255b202c3472,0x090a3b5d34342b34\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x0a3b347225202c36,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x347225202c376472,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x647225202c386472,0x3b37647225202c35,0x36732e766f6d090a,0x2c39647225092034\n"
".quad 0x090a3b3864722520,0x2e3233732e747663,0x3572250920323375,0x782e64697425202c\n"
".quad 0x752e766f6d090a3b,0x2c36722509203233,0x746573090a3b3020,0x3233732e656e2e70\n"
".quad 0x25202c3270250920,0x3b367225202c3572,0x622032702540090a,0x5f744c2409206172\n"
".quad 0x3b34393934385f30,0x3109636f6c2e090a,0x0a30093230310937,0x736e6f632e646c09\n"
".quad 0x2509203233732e74,0x6472255b202c3772,0x090a3b5d30342b34,0x74736e6f632e646c\n"
".quad 0x722509203233732e,0x6f635f645b202c38,0x5d36312b6e6f6d6d,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x2c387225202c3972,0x63090a3b37722520,0x732e3436732e7476\n"
".quad 0x3164722509203233,0x0a3b377225202c30,0x3233732e64646109,0x202c303172250920\n"
".quad 0x317225202c397225,0x772e6c756d090a3b,0x203233732e656469,0x202c313164722509\n"
".quad 0x0a3b34202c377225,0x3436732e74766309,0x722509203233732e,0x317225202c323164\n"
".quad 0x2e6c756d090a3b30,0x3233732e65646977,0x2c33316472250920,0x34202c3031722520\n"
".quad 0x6f632e646c090a3b,0x203436752e74736e,0x202c343164722509,0x5d302b346472255b\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x3431647225202c35,0x3b3131647225202c\n"
".quad 0x3233732e646c090a,0x202c313172250920,0x302b35316472255b,0x632e646c090a3b5d\n"
".quad 0x3436752e74736e6f,0x2c36316472250920,0x312b346472255b20,0x646461090a3b5d36\n"
".quad 0x722509203436752e,0x647225202c373164,0x31647225202c3631,0x732e7473090a3b33\n"
".quad 0x6472255b09203233,0x25202c5d302b3731,0x6c2e090a3b313172,0x303109373109636f\n"
".quad 0x2e646c090a300933,0x36752e74736e6f63,0x3831647225092034,0x2b346472255b202c\n"
".quad 0x646461090a3b5d38,0x722509203436752e,0x647225202c393164,0x31647225202c3831\n"
".quad 0x732e646c090a3b31,0x3231722509203233,0x39316472255b202c,0x646c090a3b5d302b\n"
".quad 0x752e74736e6f632e,0x3264722509203436,0x346472255b202c30,0x61090a3b5d34322b\n"
".quad 0x09203436752e6464,0x25202c3132647225,0x7225202c30326472,0x7473090a3b333164\n"
".quad 0x255b09203233732e,0x2c5d302b31326472,0x240a3b3231722520,0x3934385f305f744c\n"
".quad 0x6f6c2e090a3a3439,0x3231310937310963,0x2e766f6d090a3009,0x3172250920323373\n"
".quad 0x0a3b357225202c33,0x736e6f632e646c09,0x2509203233732e74,0x5f645b202c343172\n"
".quad 0x322b6e6f6d6d6f63,0x6573090a3b5d3231,0x33732e65672e7074,0x202c337025092032\n"
".quad 0x317225202c357225,0x33702540090a3b34,0x4c24092061726220,0x303535385f305f74\n"
".quad 0x2e627573090a3b36,0x3172250920323373,0x2c34317225202c35,0x61090a3b35722520\n"
".quad 0x09203233732e6464,0x7225202c36317225,0x3b313135202c3531,0x33732e726873090a\n"
".quad 0x2c37317225092032,0x33202c3631722520,0x2e766f6d090a3b31,0x3172250920323373\n"
".quad 0x0a3b313135202c38,0x3233622e646e6109,0x202c393172250920,0x7225202c37317225\n"
".quad 0x646461090a3b3831,0x722509203233732e,0x39317225202c3032,0x0a3b36317225202c\n"
".quad 0x3233732e72687309,0x202c313272250920,0x3b39202c30327225,0x6e6f632e646c090a\n"
".quad 0x09203233732e7473,0x72255b202c377225,0x0a3b5d30342b3464,0x736e6f632e646c09\n"
".quad 0x2509203436752e74,0x255b202c32326472,0x0a3b5d302b346472,0x736e6f632e646c09\n"
".quad 0x2509203436752e74,0x255b202c33326472,0x0a3b5d382b346472,0x3436732e74766309\n"
".quad 0x722509203233732e,0x377225202c343264,0x772e6c756d090a3b,0x203233732e656469\n"
".quad 0x202c313164722509,0x0a3b34202c377225,0x3436752e64646109,0x2c35326472250920\n"
".quad 0x202c323264722520,0x090a3b3131647225,0x203436752e646461,0x202c363264722509\n"
".quad 0x25202c3332647225,0x6c090a3b31316472,0x2e74736e6f632e64,0x3272250920323373\n"
".quad 0x6f635f645b202c32,0x5d30322b6e6f6d6d,0x6f632e646c090a3b,0x203436752e74736e\n"
".quad 0x202c373264722509,0x6f6d6d6f635f645b,0x65676e6168635f6e,0x646c090a3b5d302b\n"
".quad 0x732e74736e6f632e,0x3332722509203233,0x6d6f635f645b202c,0x5d3430322b6e6f6d\n"
".quad 0x732e766f6d090a3b,0x3432722509203233,0x0a3b31327225202c,0x36385f305f744c24\n"
".quad 0x2f2f200a3a383130,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x313120656e696c20\n"
".quad 0x697473656e202c32,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0936313109373109\n"
".quad 0x732e646461090a30,0x3532722509203233,0x202c33317225202c,0x2e6d6572090a3b31\n"
".quad 0x3272250920323373,0x2c35327225202c36,0x090a3b3332722520,0x203233732e627573\n"
".quad 0x25202c3732722509,0x0a3b31202c363272,0x373109636f6c2e09,0x090a300937313109\n"
".quad 0x203233732e766964,0x25202c3832722509,0x327225202c353272,0x2e766f6d090a3b33\n"
".quad 0x3272250920323375,0x73090a3b30202c39,0x732e656e2e707465,0x2c34702509203233\n"
".quad 0x25202c3632722520,0x2540090a3b393272,0x0920617262203470,0x36385f305f744c24\n"
".quad 0x6c2e090a3b343732,0x313109373109636f,0x627573090a300939,0x722509203233732e\n"
".quad 0x33327225202c3732,0x6c2e090a3b31202c,0x323109373109636f,0x627573090a300930\n"
".quad 0x722509203233732e,0x38327225202c3832,0x744c240a3b31202c,0x34373236385f305f\n"
".quad 0x09636f6c2e090a3a,0x3009393231093731,0x3233732e646c090a,0x202c303372250920\n"
".quad 0x302b35326472255b,0x2e646461090a3b5d,0x3372250920323373,0x2c30337225202c31\n"
".quad 0x090a3b3732722520,0x09203233732e646c,0x255b202c32337225,0x3b5d302b36326472\n"
".quad 0x33732e646461090a,0x2c33337225092032,0x25202c3233722520,0x7573090a3b383272\n"
".quad 0x2509203233732e62,0x337225202c343372,0x090a3b3632202c33,0x732e6f6c2e6c756d\n"
".quad 0x3533722509203233,0x202c32327225202c,0x61090a3b34337225,0x09203233732e6464\n"
".quad 0x7225202c36337225,0x35337225202c3133,0x732e627573090a3b,0x3733722509203233\n"
".quad 0x202c36337225202c,0x747663090a3b3632,0x3233732e3436732e,0x2c38326472250920\n"
".quad 0x090a3b3733722520,0x656469772e6c756d,0x722509203233732e,0x337225202c393264\n"
".quad 0x61090a3b34202c37,0x09203436752e6464,0x25202c3033647225,0x7225202c37326472\n"
".quad 0x646c090a3b393264,0x662509203233662e,0x336472255b202c31,0x6d090a3b5d302b30\n"
".quad 0x33732e6f6c2e6c75,0x2c38337225092032,0x25202c3832722520,0x6461090a3b333272\n"
".quad 0x2509203233732e64,0x327225202c393372,0x3b38337225202c37,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x7225202c31336472,0x6c756d090a3b3933,0x33732e656469772e\n"
".quad 0x3233647225092032,0x202c39337225202c,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x38647225202c3333,0x3b3233647225202c,0x3233662e7473090a,0x33336472255b0920\n"
".quad 0x316625202c5d302b,0x732e646461090a3b,0x3331722509203233,0x202c33317225202c\n"
".quad 0x6573090a3b323135,0x33732e746c2e7074,0x202c357025092032,0x7225202c33317225\n"
".quad 0x702540090a3b3431,0x2409206172622035,0x3036385f305f744c,0x5f744c240a3b3831\n"
".quad 0x3a36303535385f30,0x385f305f744c240a,0x6d090a3a32383434,0x09203436752e766f\n"
".quad 0x5f64202c31647225,0x0a3b657571696e75,0x3233732e766f6d09,0x202c303472250920\n"
".quad 0x70746573090a3b30,0x203233732e656e2e,0x7225202c36702509,0x3b30347225202c31\n"
".quad 0x203670252140090a,0x744c240920617262,0x32343037385f305f,0x09636f6c2e090a3b\n"
".quad 0x3009313531093731,0x33732e747663090a,0x2509203233752e32,0x746325202c313472\n"
".quad 0x090a3b782e646961,0x2e3436732e747663,0x6472250920323373,0x31347225202c3433\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x202c353364722509,0x3631202c31347225\n"
".quad 0x2e646461090a3b30,0x6472250920343675,0x2c31647225202c34,0x0a3b353364722520\n"
".quad 0x736e6f632e646c09,0x2509203233732e74,0x6472255b202c3772,0x090a3b5d30342b34\n"
".quad 0x74736e6f632e646c,0x722509203436752e,0x72255b202c323264,0x090a3b5d302b3464\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x3b377225202c3633,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3131647225,0x090a3b34202c3772,0x203436752e646461\n"
".quad 0x202c353264722509,0x25202c3232647225,0x6c090a3b31316472,0x2e74736e6f632e64\n"
".quad 0x3472250920323373,0x6f635f645b202c32,0x3b5d302b6e6f6d6d,0x3233732e646c090a\n"
".quad 0x202c333472250920,0x302b35326472255b,0x2e627573090a3b5d,0x3472250920323373\n"
".quad 0x2c33347225202c34,0x090a3b3234722520,0x09373109636f6c2e,0x6c090a3009323531\n"
".quad 0x2e74736e6f632e64,0x6472250920343675,0x6472255b202c3332,0x61090a3b5d382b34\n"
".quad 0x09203436752e6464,0x25202c3632647225,0x7225202c33326472,0x646c090a3b313164\n"
".quad 0x722509203233732e,0x6472255b202c3534,0x090a3b5d302b3632,0x203233732e627573\n"
".quad 0x25202c3634722509,0x347225202c353472,0x636f6c2e090a3b32,0x0935353109373109\n"
".quad 0x732e747663090a30,0x09203233752e3233,0x697425202c357225,0x6f6d090a3b782e64\n"
".quad 0x2509203233732e76,0x357225202c333172,0x6f632e646c090a3b,0x203233732e74736e\n"
".quad 0x5b202c3734722509,0x6e6f6d6d6f635f64,0x090a3b5d3832322b,0x2e65672e70746573\n"
".quad 0x3770250920323373,0x25202c357225202c,0x2540090a3b373472,0x0920617262203770\n"
".quad 0x37385f305f744c24,0x7573090a3b343535,0x2509203233732e62,0x347225202c383472\n"
".quad 0x0a3b357225202c37,0x3233732e64646109,0x202c393472250920,0x3135202c38347225\n"
".quad 0x2e726873090a3b31,0x3572250920323373,0x2c39347225202c30,0x6f6d090a3b313320\n"
".quad 0x2509203233732e76,0x313135202c313572,0x622e646e61090a3b,0x3235722509203233\n"
".quad 0x202c30357225202c,0x61090a3b31357225,0x09203233732e6464,0x7225202c33357225\n"
".quad 0x39347225202c3235,0x732e726873090a3b,0x3435722509203233,0x202c33357225202c\n"
".quad 0x2e747663090a3b39,0x203233732e343673,0x202c373364722509,0x756d090a3b357225\n"
".quad 0x732e656469772e6c,0x3364722509203233,0x202c357225202c38,0x632e646c090a3b34\n"
".quad 0x3436752e74736e6f,0x2c39336472250920,0x342b346472255b20,0x646461090a3b5d38\n"
".quad 0x722509203436752e,0x647225202c303464,0x33647225202c3933,0x632e646c090a3b38\n"
".quad 0x3233732e74736e6f,0x202c353572250920,0x6f6d6d6f635f645b,0x0a3b5d3032322b6e\n"
".quad 0x736e6f632e646c09,0x2509203233732e74,0x5f645b202c323272,0x322b6e6f6d6d6f63\n"
".quad 0x2e646c090a3b5d30,0x36752e74736e6f63,0x3732647225092034,0x6d6f635f645b202c\n"
".quad 0x6e6168635f6e6f6d,0x090a3b5d302b6567,0x203233732e766f6d,0x25202c3635722509\n"
".quad 0x744c240a3b343572,0x36363038385f305f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x202c35353120656e,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x616d69747365202c,0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75\n"
".quad 0x373109636f6c2e09,0x090a300939353109,0x203233732e646461,0x25202c3532722509\n"
".quad 0x0a3b31202c333172,0x3233732e6d657209,0x202c373572250920,0x7225202c35327225\n"
".quad 0x627573090a3b3535,0x722509203233732e,0x37357225202c3732,0x6c2e090a3b31202c\n"
".quad 0x363109373109636f,0x766964090a300930,0x722509203233732e,0x35327225202c3832\n"
".quad 0x0a3b35357225202c,0x3233752e766f6d09,0x202c383572250920,0x70746573090a3b30\n"
".quad 0x203233732e656e2e,0x7225202c38702509,0x38357225202c3735,0x2038702540090a3b\n"
".quad 0x744c240920617262,0x32323338385f305f,0x09636f6c2e090a3b,0x3009323631093731\n"
".quad 0x33732e627573090a,0x2c37327225092032,0x31202c3535722520,0x09636f6c2e090a3b\n"
".quad 0x3009333631093731,0x33732e627573090a,0x2c38327225092032,0x31202c3832722520\n"
".quad 0x5f305f744c240a3b,0x090a3a3232333838,0x09373109636f6c2e,0x61090a3009393631\n"
".quad 0x09203233732e6464,0x7225202c39357225,0x34347225202c3732,0x732e646461090a3b\n"
".quad 0x3036722509203233,0x202c38327225202c,0x73090a3b36347225,0x09203233732e6275\n"
".quad 0x7225202c31367225,0x090a3b31202c3036,0x732e6f6c2e6c756d,0x3236722509203233\n"
".quad 0x202c32327225202c,0x61090a3b31367225,0x09203233732e6464,0x7225202c33367225\n"
".quad 0x32367225202c3935,0x732e747663090a3b,0x09203233732e3436,0x25202c3134647225\n"
".quad 0x756d090a3b333672,0x732e656469772e6c,0x3464722509203233,0x2c33367225202c32\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c333464,0x34647225202c3732\n"
".quad 0x662e646c090a3b32,0x2c32662509203233,0x2b33346472255b20,0x7473090a3b5d342d\n"
".quad 0x255b09203233662e,0x2c5d302b30346472,0x61090a3b32662520,0x09203233732e6464\n"
".quad 0x7225202c33317225,0x3b323135202c3331,0x36752e646461090a,0x3034647225092034\n"
".quad 0x2c3034647225202c,0x090a3b3834303220,0x2e746c2e70746573,0x3970250920323373\n"
".quad 0x202c33317225202c,0x40090a3b37347225,0x2061726220397025,0x385f305f744c2409\n"
".quad 0x4c240a3b36363038,0x353537385f305f74,0x636f6c2e090a3a34,0x0930383109373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x373109636f6c2e09,0x090a300931393109\n"
".quad 0x74736e6f632e646c,0x722509203436752e,0x72255b202c343464,0x0a3b5d32332b3464\n"
".quad 0x736e6f632e646c09,0x2509203233732e74,0x72255b202c343672,0x0a3b5d34342b3464\n"
".quad 0x3436732e74766309,0x722509203233732e,0x367225202c353464,0x2e6c756d090a3b34\n"
".quad 0x3233732e65646977,0x2c36346472250920,0x34202c3436722520,0x752e646461090a3b\n"
".quad 0x3864722509203436,0x2c3434647225202c,0x0a3b363464722520,0x3436732e766f6d09\n"
".quad 0x202c396472250920,0x2e090a3b38647225,0x3109373109636f6c,0x6f6d090a30093439\n"
".quad 0x2509203233732e76,0x357225202c333172,0x6f632e646c090a3b,0x203233732e74736e\n"
".quad 0x5b202c3431722509,0x6e6f6d6d6f635f64,0x090a3b5d3231322b,0x2e65672e70746573\n"
".quad 0x3170250920323373,0x202c357225202c30,0x40090a3b34317225,0x6172622030317025\n"
".quad 0x5f305f744c240920,0x090a3b3039303938,0x6168732e61747663,0x203436752e646572\n"
".quad 0x202c373464722509,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32335f3238343434,0x6e6f635f6e6f6e5f,0x5f6e695f645f7473,0x706d65745f646f6d\n"
".quad 0x73090a3b36393638,0x09203233732e6275,0x7225202c35367225,0x3b357225202c3431\n"
".quad 0x33732e646461090a,0x2c36367225092032,0x35202c3536722520,0x726873090a3b3131\n"
".quad 0x722509203233732e,0x36367225202c3736,0x6d090a3b3133202c,0x09203233732e766f\n"
".quad 0x3135202c38367225,0x2e646e61090a3b31,0x3672250920323362,0x2c37367225202c39\n"
".quad 0x090a3b3836722520,0x203233732e646461,0x25202c3037722509,0x367225202c393672\n"
".quad 0x2e726873090a3b36,0x3772250920323373,0x2c30377225202c31,0x747663090a3b3920\n"
".quad 0x3233732e3436732e,0x2c38346472250920,0x6d090a3b35722520,0x2e656469772e6c75\n"
".quad 0x6472250920323373,0x2c357225202c3934,0x646461090a3b3420,0x722509203436752e\n"
".quad 0x647225202c303564,0x34647225202c3734,0x632e646c090a3b39,0x3233732e74736e6f\n"
".quad 0x202c333272250920,0x6f6d6d6f635f645b,0x0a3b5d3430322b6e,0x3233732e766f6d09\n"
".quad 0x202c323772250920,0x4c240a3b31377225,0x303639385f305f74,0x6c3c2f2f200a3a32\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c34393120656e69,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x0a30093839310937,0x3233732e64646109\n"
".quad 0x202c353272250920,0x3b31202c33317225,0x33732e6d6572090a,0x2c36327225092032\n"
".quad 0x25202c3532722520,0x7573090a3b333272,0x2509203233732e62,0x327225202c373272\n"
".quad 0x2e090a3b31202c36,0x3109373109636f6c,0x6964090a30093939,0x2509203233732e76\n"
".quad 0x327225202c383272,0x3b33327225202c35,0x33752e766f6d090a,0x2c33377225092032\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x202c313170250920,0x7225202c36327225\n"
".quad 0x702540090a3b3337,0x0920617262203131,0x39385f305f744c24,0x6c2e090a3b383538\n"
".quad 0x303209373109636f,0x627573090a300931,0x722509203233732e,0x33327225202c3732\n"
".quad 0x6c2e090a3b31202c,0x303209373109636f,0x627573090a300932,0x722509203233732e\n"
".quad 0x38327225202c3832,0x744c240a3b31202c,0x38353839385f305f,0x09636f6c2e090a3a\n"
".quad 0x3009383032093731,0x33732e627573090a,0x2c34377225092032,0x25202c3332722520\n"
".quad 0x7573090a3b383272,0x2509203233732e62,0x377225202c353772,0x6d090a3b31202c34\n"
".quad 0x33732e6f6c2e6c75,0x2c36377225092032,0x25202c3332722520,0x7573090a3b353772\n"
".quad 0x2509203233732e62,0x327225202c373772,0x3b37327225202c33,0x33732e646461090a\n"
".quad 0x2c38377225092032,0x25202c3637722520,0x7663090a3b373772,0x33732e3436732e74\n"
".quad 0x3135647225092032,0x0a3b38377225202c,0x6469772e6c756d09,0x2509203233732e65\n"
".quad 0x7225202c32356472,0x090a3b34202c3837,0x203436752e646461,0x202c333564722509\n"
".quad 0x7225202c38647225,0x646c090a3b323564,0x662509203233662e,0x356472255b202c33\n"
".quad 0x090a3b5d342d2b33,0x09203233662e7473,0x302b30356472255b,0x0a3b336625202c5d\n"
".quad 0x3233732e64646109,0x202c333172250920,0x3135202c33317225,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x35647225202c3035,0x3b38343032202c30,0x6c2e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c323170,0x3b34317225202c33,0x203231702540090a\n"
".quad 0x744c240920617262,0x32303639385f305f,0x5f305f744c240a3b,0x090a3a3039303938\n"
".quad 0x6168732e61747663,0x203436752e646572,0x202c373464722509,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x32335f3238343434,0x6e6f635f6e6f6e5f\n"
".quad 0x5f6e695f645f7473,0x706d65745f646f6d,0x2e090a3b36393638,0x3209373109636f6c\n"
".quad 0x6162090a30093931,0x0920636e79732e72,0x636f6c2e090a3b30,0x0936323209373109\n"
".quad 0x732e766f6d090a30,0x3331722509203233,0x090a3b357225202c,0x74736e6f632e646c\n"
".quad 0x722509203233732e,0x635f645b202c3937,0x34322b6e6f6d6d6f,0x746573090a3b5d34\n"
".quad 0x3233732e746c2e70,0x202c333170250920,0x377225202c357225,0x70252140090a3b39\n"
".quad 0x0920617262203331,0x34315f305f744c24,0x73090a3b36323238,0x09203233732e6275\n"
".quad 0x7225202c30387225,0x3b357225202c3937,0x33732e646461090a,0x2c31387225092032\n"
".quad 0x35202c3038722520,0x726873090a3b3131,0x722509203233732e,0x31387225202c3238\n"
".quad 0x6d090a3b3133202c,0x09203233732e766f,0x3135202c33387225,0x2e646e61090a3b31\n"
".quad 0x3872250920323362,0x2c32387225202c34,0x090a3b3338722520,0x203233732e646461\n"
".quad 0x25202c3538722509,0x387225202c343872,0x2e726873090a3b31,0x3872250920323373\n"
".quad 0x2c35387225202c36,0x747663090a3b3920,0x3233732e3436732e,0x2c34356472250920\n"
".quad 0x6d090a3b35722520,0x2e656469772e6c75,0x6472250920323373,0x2c357225202c3833\n"
".quad 0x2e646c090a3b3420,0x36752e74736e6f63,0x3535647225092034,0x2b346472255b202c\n"
".quad 0x6461090a3b5d3635,0x2509203436752e64,0x7225202c36356472,0x647225202c353564\n"
".quad 0x2e646c090a3b3833,0x33732e74736e6f63,0x2c37387225092032,0x6d6d6f635f645b20\n"
".quad 0x3b5d3635322b6e6f,0x6e6f632e646c090a,0x09203233732e7473,0x645b202c38387225\n"
".quad 0x2b6e6f6d6d6f635f,0x6c090a3b5d363332,0x2e74736e6f632e64,0x3872250920323373\n"
".quad 0x6f635f645b202c39,0x3432322b6e6f6d6d,0x632e646c090a3b5d,0x3233732e74736e6f\n"
".quad 0x202c303972250920,0x6f6d6d6f635f645b,0x0a3b5d3830322b6e,0x3233732e766f6d09\n"
".quad 0x202c313972250920,0x4c240a3b36387225,0x333131395f305f74,0x6c3c2f2f200a3a38\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c36323220656e69,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x0a30093033320937,0x3233732e64646109\n"
".quad 0x202c353272250920,0x3b31202c33317225,0x33732e6d6572090a,0x2c32397225092032\n"
".quad 0x25202c3532722520,0x6f6d090a3b383872,0x2509203233732e76,0x397225202c333972\n"
".quad 0x636f6c2e090a3b32,0x0931333209373109,0x732e766964090a30,0x3439722509203233\n"
".quad 0x202c35327225202c,0x61090a3b38387225,0x09203233732e6464,0x7225202c35397225\n"
".quad 0x090a3b31202c3439,0x203233752e766f6d,0x30202c3639722509,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c34317025,0x36397225202c3239,0x3431702540090a3b\n"
".quad 0x4c24092061726220,0x393331395f305f74,0x636f6c2e090a3b34,0x0933333209373109\n"
".quad 0x732e766f6d090a30,0x3339722509203233,0x0a3b38387225202c,0x373109636f6c2e09\n"
".quad 0x090a300934333209,0x203233732e766f6d,0x25202c3539722509,0x744c240a3b343972\n"
".quad 0x34393331395f305f,0x09636f6c2e090a3a,0x3009313732093731,0x33732e646461090a\n"
".quad 0x2c37397225092032,0x25202c3539722520,0x6461090a3b373872,0x2509203233732e64\n"
".quad 0x397225202c383972,0x73090a3b31202c37,0x09203233732e6275,0x7225202c39397225\n"
".quad 0x39387225202c3739,0x2e70746573090a3b,0x09203233732e7467,0x7225202c35317025\n"
".quad 0x39387225202c3839,0x732e646461090a3b,0x3031722509203233,0x2c39397225202c30\n"
".quad 0x766f6d090a3b3120,0x722509203233732e,0x0a3b31202c313031,0x33732e706c657309\n"
".quad 0x3230317225092032,0x2c3030317225202c,0x202c313031722520,0x6d090a3b35317025\n"
".quad 0x09203233732e766f,0x25202c3330317225,0x73090a3b32303172,0x732e74672e707465\n"
".quad 0x3631702509203233,0x202c37397225202c,0x73090a3b30397225,0x203233732e706c65\n"
".quad 0x202c343031722509,0x7225202c30397225,0x36317025202c3739,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c37317025,0x317225202c343031,0x702540090a3b3230\n"
".quad 0x0920617262203731,0x34315f305f744c24,0x6c090a3b32383438,0x2e74736e6f632e64\n"
".quad 0x3172250920323373,0x635f645b202c3530,0x35322b6e6f6d6d6f,0x646461090a3b5d32\n"
".quad 0x722509203233732e,0x317225202c363031,0x33397225202c3530,0x732e646461090a3b\n"
".quad 0x3031722509203233,0x3630317225202c37,0x646c090a3b31202c,0x732e74736e6f632e\n"
".quad 0x3332722509203233,0x6d6f635f645b202c,0x5d3430322b6e6f6d,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x7225202c38317025,0x327225202c363031,0x706c6573090a3b33\n"
".quad 0x722509203233732e,0x327225202c383031,0x3630317225202c33,0x0a3b38317025202c\n"
".quad 0x3233732e62757309,0x2c39303172250920,0x202c343031722520,0x090a3b3230317225\n"
".quad 0x203233732e646461,0x202c303131722509,0x31202c3930317225,0x6f632e646c090a3b\n"
".quad 0x203233732e74736e,0x5b202c3535722509,0x6e6f6d6d6f635f64,0x090a3b5d3032322b\n"
".quad 0x203233732e627573,0x202c313131722509,0x25202c3630317225,0x6573090a3b353572\n"
".quad 0x33732e74672e7074,0x2c39317025092032,0x202c373031722520,0x61090a3b35357225\n"
".quad 0x09203233732e6464,0x25202c3231317225,0x3b31202c31313172,0x33732e646461090a\n"
".quad 0x3331317225092032,0x2c3430317225202c,0x766f6d090a3b3120,0x722509203233732e\n"
".quad 0x0a3b31202c343131,0x33732e706c657309,0x3531317225092032,0x2c3231317225202c\n"
".quad 0x202c343131722520,0x73090a3b39317025,0x732e65672e707465,0x3032702509203233\n"
".quad 0x2c3830317225202c,0x0a3b353131722520,0x3233662e766f6d09,0x30202c3466250920\n"
".quad 0x3030303030303066,0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233732e76\n"
".quad 0x7225202c36313172,0x744c240a3b303131,0x38313432395f305f,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x202c31373220656e,0x20676e697473656e\n"
".quad 0x32203a6874706564,0x616d69747365202c,0x7265746920646574,0x203a736e6f697461\n"
".quad 0x0a6e776f6e6b6e75,0x2030327025214009,0x744c240920617262,0x34373632395f305f\n"
".quad 0x732e627573090a3b,0x3131722509203233,0x3830317225202c37,0x3b3531317225202c\n"
".quad 0x33732e646461090a,0x3831317225092032,0x2c3731317225202c,0x6c756d090a3b3120\n"
".quad 0x203233732e6f6c2e,0x202c393131722509,0x7225202c35397225,0x6c756d090a3b3535\n"
".quad 0x203233732e6f6c2e,0x202c303231722509,0x7225202c37387225,0x6c756d090a3b3535\n"
".quad 0x203233732e6f6c2e,0x202c313231722509,0x25202c3330317225,0x756d090a3b353572\n"
".quad 0x3233732e6f6c2e6c,0x2c32323172250920,0x202c333031722520,0x6e090a3b33327225\n"
".quad 0x09203233732e6765,0x25202c3332317225,0x7573090a3b333272,0x2509203233732e62\n"
".quad 0x7225202c34323172,0x317225202c363031,0x646461090a3b3531,0x722509203233732e\n"
".quad 0x317225202c353231,0x32317225202c3931,0x2e627573090a3b30,0x3172250920323373\n"
".quad 0x32317225202c3632,0x3132317225202c35,0x6f632e646c090a3b,0x203436752e74736e\n"
".quad 0x202c393364722509,0x38342b346472255b,0x2e646461090a3b5d,0x3172250920323373\n"
".quad 0x30317225202c3732,0x61090a3b31202c38,0x09203233732e6464,0x25202c3832317225\n"
".quad 0x7225202c34323172,0x7573090a3b363231,0x2509203233732e62,0x7225202c39323172\n"
".quad 0x317225202c363031,0x646461090a3b3732,0x722509203233732e,0x317225202c303331\n"
".quad 0x32317225202c3632,0x2e646461090a3b39,0x3172250920323373,0x32317225202c3133\n"
".quad 0x3332317225202c32,0x732e646461090a3b,0x3331722509203233,0x3531317225202c32\n"
".quad 0x3b3133317225202c,0x36732e747663090a,0x2509203233732e34,0x7225202c37356472\n"
".quad 0x756d090a3b323331,0x732e656469772e6c,0x3564722509203233,0x3233317225202c38\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x7225202c39356472,0x647225202c373464\n"
".quad 0x747663090a3b3835,0x3233732e3436732e,0x2c30366472250920,0x0a3b383231722520\n"
".quad 0x6469772e6c756d09,0x2509203233732e65,0x7225202c31366472,0x0a3b34202c383231\n"
".quad 0x3436752e64646109,0x2c32366472250920,0x202c393364722520,0x090a3b3136647225\n"
".quad 0x203233732e766f6d,0x202c333331722509,0x240a3b3831317225,0x3133395f305f744c\n"
".quad 0x3c2f2f200a3a3638,0x6f4c203e706f6f6c,0x2079646f6220706f,0x31373220656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3320,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x3009353732093731\n"
".quad 0x3233662e646c090a,0x5b202c3566250920,0x5d302b3236647225,0x33662e646c090a3b\n"
".quad 0x202c366625092032,0x2d2b39356472255b,0x616d66090a3b5d34,0x203233662e6e722e\n"
".quad 0x6625202c34662509,0x202c366625202c35,0x6461090a3b346625,0x2509203436752e64\n"
".quad 0x7225202c39356472,0x0a3b34202c393564,0x3233732e62757309,0x2c38323172250920\n"
".quad 0x202c383231722520,0x2e627573090a3b31,0x6472250920343675,0x36647225202c3236\n"
".quad 0x73090a3b34202c32,0x732e656e2e707465,0x3132702509203233,0x2c3832317225202c\n"
".quad 0x0a3b303331722520,0x6220313270254009,0x5f744c2409206172,0x3b36383133395f30\n"
".quad 0x395f305f744c240a,0x61090a3a34373632,0x09203233732e6464,0x25202c3330317225\n"
".quad 0x3b31202c33303172,0x6e2e70746573090a,0x2509203233732e65,0x317225202c323270\n"
".quad 0x30317225202c3331,0x32702540090a3b33,0x2409206172622032,0x3432395f305f744c\n"
".quad 0x617262090a3b3831,0x4c240920696e752e,0x303931395f305f74,0x305f744c240a3b36\n"
".quad 0x3a3238343834315f,0x33662e766f6d090a,0x202c346625092032,0x3030303030306630\n"
".quad 0x20202020203b3030,0x4c240a30202f2f09,0x303931395f305f74,0x636f6c2e090a3a36\n"
".quad 0x0930383209373109,0x33662e7473090a30,0x356472255b092032,0x6625202c5d302b36\n"
".quad 0x2e646461090a3b34,0x3172250920323373,0x2c33317225202c33,0x61090a3b32313520\n"
".quad 0x09203436752e6464,0x25202c3635647225,0x3032202c36356472,0x746573090a3b3834\n"
".quad 0x3233732e746c2e70,0x202c333270250920,0x7225202c33317225,0x702540090a3b3937\n"
".quad 0x0920617262203332,0x31395f305f744c24,0x7262090a3b383331,0x240920696e752e61\n"
".quad 0x3630395f305f744c,0x5f744c240a3b3632,0x3632323834315f30,0x6f632e646c090a3a\n"
".quad 0x203233732e74736e,0x5b202c3039722509,0x6e6f6d6d6f635f64,0x240a3b5d3830322b\n"
".quad 0x3630395f305f744c,0x6f6c2e090a3a3632,0x3139320937310963,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x3109636f6c2e090a,0x0a30093630330937,0x3233732e766f6d09\n"
".quad 0x202c333172250920,0x646c090a3b357225,0x732e74736e6f632e,0x3331722509203233\n"
".quad 0x6f635f645b202c34,0x3637322b6e6f6d6d,0x70746573090a3b5d,0x203233732e746c2e\n"
".quad 0x25202c3432702509,0x33317225202c3572,0x70252140090a3b34,0x0920617262203432\n"
".quad 0x34395f305f744c24,0x7573090a3b303132,0x2509203233732e62,0x7225202c35333172\n"
".quad 0x357225202c343331,0x732e646461090a3b,0x3331722509203233,0x3533317225202c36\n"
".quad 0x090a3b313135202c,0x203233732e726873,0x202c373331722509,0x33202c3633317225\n"
".quad 0x2e766f6d090a3b31,0x3172250920323373,0x3b313135202c3833,0x33622e646e61090a\n"
".quad 0x3933317225092032,0x2c3733317225202c,0x0a3b383331722520,0x3233732e64646109\n"
".quad 0x2c30343172250920,0x202c393331722520,0x090a3b3633317225,0x203233732e726873\n"
".quad 0x202c313431722509,0x39202c3034317225,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x25202c3336647225,0x2e646c090a3b3572,0x33732e74736e6f63,0x3234317225092032\n"
".quad 0x6d6f635f645b202c,0x5d3036322b6e6f6d,0x732e627573090a3b,0x3431722509203233\n"
".quad 0x3234317225202c33,0x756d090a3b31202c,0x732e656469772e6c,0x3364722509203233\n"
".quad 0x202c357225202c38,0x632e646c090a3b34,0x3436752e74736e6f,0x2c34366472250920\n"
".quad 0x372b346472255b20,0x646461090a3b5d32,0x722509203436752e,0x647225202c353664\n"
".quad 0x33647225202c3436,0x632e646c090a3b38,0x3233732e74736e6f,0x2c34343172250920\n"
".quad 0x6d6d6f635f645b20,0x3b5d3836322b6e6f,0x33732e766f6d090a,0x3534317225092032\n"
".quad 0x3b3134317225202c,0x395f305f744c240a,0x2f200a3a32323734,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3320656e696c2079,0x7473656e202c3630,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x6f6c2e090a6e776f,0x3031330937310963,0x2e646461090a3009,0x3272250920323373\n"
".quad 0x2c33317225202c35,0x6d6572090a3b3120,0x722509203233732e,0x327225202c363431\n"
".quad 0x3434317225202c35,0x732e627573090a3b,0x3732722509203233,0x2c3634317225202c\n"
".quad 0x6f6c2e090a3b3120,0x3131330937310963,0x2e766964090a3009,0x3272250920323373\n"
".quad 0x2c35327225202c38,0x0a3b343431722520,0x3233752e766f6d09,0x2c37343172250920\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x202c353270250920,0x25202c3634317225\n"
".quad 0x40090a3b37343172,0x6172622035327025,0x5f305f744c240920,0x090a3b3837393439\n"
".quad 0x09373109636f6c2e,0x73090a3009333133,0x09203233732e6275,0x7225202c37327225\n"
".quad 0x0a3b31202c343431,0x373109636f6c2e09,0x090a300934313309,0x203233732e627573\n"
".quad 0x25202c3832722509,0x0a3b31202c383272,0x34395f305f744c24,0x6c2e090a3a383739\n"
".quad 0x313309373109636f,0x746573090a300938,0x3233732e65672e70,0x202c363270250920\n"
".quad 0x25202c3334317225,0x2540090a3b373272,0x2061726220363270,0x315f305f744c2409\n"
".quad 0x090a3b3236373934,0x74736e6f632e646c,0x722509203233732e,0x635f645b202c3535\n"
".quad 0x32322b6e6f6d6d6f,0x646461090a3b5d30,0x722509203233732e,0x357225202c383431\n"
".quad 0x3234317225202c35,0x2e70746573090a3b,0x09203233732e6567,0x7225202c37327025\n"
".quad 0x34317225202c3732,0x32702540090a3b38,0x2409206172622037,0x3934315f305f744c\n"
".quad 0x646c090a3b323637,0x732e74736e6f632e,0x3431722509203233,0x6f635f645b202c39\n"
".quad 0x3436322b6e6f6d6d,0x2e627573090a3b5d,0x3172250920323373,0x34317225202c3035\n"
".quad 0x73090a3b31202c39,0x732e656c2e707465,0x3832702509203233,0x202c38327225202c\n"
".quad 0x090a3b3035317225,0x7262203832702540,0x305f744c24092061,0x3b3236373934315f\n"
".quad 0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3135317225,0x6e6f6d6d6f635f64\n"
".quad 0x090a3b5d3432322b,0x203233732e646461,0x202c323531722509,0x25202c3135317225\n"
".quad 0x73090a3b39343172,0x732e65672e707465,0x3932702509203233,0x202c38327225202c\n"
".quad 0x090a3b3235317225,0x7262203932702540,0x305f744c24092061,0x3b3236373934315f\n"
".quad 0x3109636f6c2e090a,0x0a30093432330937,0x736e6f632e646c09,0x2509203436752e74\n"
".quad 0x255b202c36366472,0x3b5d38342b346472,0x33732e627573090a,0x3335317225092032\n"
".quad 0x202c38327225202c,0x090a3b3934317225,0x732e6f6c2e6c756d,0x3531722509203233\n"
".quad 0x2c35357225202c34,0x0a3b333531722520,0x3233732e62757309,0x2c35353172250920\n"
".quad 0x25202c3732722520,0x61090a3b32343172,0x09203233732e6464,0x25202c3635317225\n"
".quad 0x7225202c34353172,0x7663090a3b353531,0x33732e3436732e74,0x3736647225092032\n"
".quad 0x3b3635317225202c,0x69772e6c756d090a,0x09203233732e6564,0x25202c3836647225\n"
".quad 0x3b34202c36353172,0x36752e646461090a,0x3936647225092034,0x2c3636647225202c\n"
".quad 0x0a3b383664722520,0x203233662e646c09,0x255b202c37662509,0x3b5d302b39366472\n"
".quad 0x3233662e7473090a,0x35366472255b0920,0x376625202c5d302b,0x752e617262090a3b\n"
".quad 0x305f4c240920696e,0x0a3b32323931385f,0x34315f305f744c24,0x4c240a3a32363739\n"
".quad 0x38373132385f305f,0x09636f6c2e090a3a,0x3009373233093731,0x33662e766f6d090a\n"
".quad 0x202c386625092032,0x3030303030306630,0x20202020203b3030,0x73090a30202f2f09\n"
".quad 0x5b09203233662e74,0x5d302b3536647225,0x240a3b386625202c,0x323931385f305f4c\n"
".quad 0x2e646461090a3a32,0x3172250920323373,0x2c33317225202c33,0x61090a3b32313520\n"
".quad 0x09203436752e6464,0x25202c3536647225,0x3032202c35366472,0x746573090a3b3834\n"
".quad 0x3233732e746c2e70,0x202c303370250920,0x7225202c33317225,0x2540090a3b343331\n"
".quad 0x2061726220303370,0x395f305f744c2409,0x4c240a3b32323734,0x313234395f305f74\n"
".quad 0x636f6c2e090a3a30,0x0939333309373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300936343309,0x203233732e766f6d,0x25202c3331722509\n"
".quad 0x2e646c090a3b3572,0x33732e74736e6f63,0x3735317225092032,0x6d6f635f645b202c\n"
".quad 0x5d3237322b6e6f6d,0x2e70746573090a3b,0x09203233732e746c,0x7225202c31337025\n"
".quad 0x3735317225202c35,0x3370252140090a3b,0x2409206172622031,0x3735395f305f744c\n"
".quad 0x627573090a3b3634,0x722509203233732e,0x317225202c383531,0x3b357225202c3735\n"
".quad 0x33732e646461090a,0x3935317225092032,0x2c3835317225202c,0x73090a3b31313520\n"
".quad 0x09203233732e7268,0x25202c3036317225,0x3133202c39353172,0x732e766f6d090a3b\n"
".quad 0x3631722509203233,0x0a3b313135202c31,0x3233622e646e6109,0x2c32363172250920\n"
".quad 0x202c303631722520,0x090a3b3136317225,0x203233732e646461,0x202c333631722509\n"
".quad 0x25202c3236317225,0x73090a3b39353172,0x09203233732e7268,0x25202c3436317225\n"
".quad 0x3b39202c33363172,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3434317225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3836322b,0x732e6f6c2e6c756d,0x3631722509203233\n"
".quad 0x202c357225202c35,0x090a3b3434317225,0x732e6f6c2e6c756d,0x3631722509203233\n"
".quad 0x3434317225202c36,0x090a3b323135202c,0x203233732e766f6d,0x202c373631722509\n"
".quad 0x240a3b3436317225,0x3236395f305f744c,0x3c2f2f200a3a3835,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x36343320656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x09636f6c2e090a6e,0x3009363533093731,0x33732e766f6d090a,0x3836317225092032\n"
".quad 0x3b3536317225202c,0x33732e766f6d090a,0x3936317225092032,0x3b3836317225202c\n"
".quad 0x33732e646461090a,0x3037317225092032,0x2c3836317225202c,0x0a3b343431722520\n"
".quad 0x656c2e7074657309,0x702509203233732e,0x37317225202c3233,0x3836317225202c30\n"
".quad 0x3233702540090a3b,0x4c24092061726220,0x313536395f305f74,0x2e766f6d090a3b34\n"
".quad 0x3172250920323373,0x34317225202c3137,0x632e646c090a3b34,0x3436752e74736e6f\n"
".quad 0x2c34366472250920,0x372b346472255b20,0x747663090a3b5d32,0x3233732e3436732e\n"
".quad 0x2c30376472250920,0x0a3b383631722520,0x6469772e6c756d09,0x2509203233732e65\n"
".quad 0x7225202c31376472,0x0a3b34202c383631,0x3436752e64646109,0x2c32376472250920\n"
".quad 0x202c343664722520,0x090a3b3137647225,0x203233662e766f6d,0x6630202c39662509\n"
".quad 0x3030303030303030,0x2f0920202020203b,0x766f6d090a30202f,0x722509203233732e\n"
".quad 0x317225202c323731,0x5f744c240a3b3137,0x3a36323037395f30,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3635332065,0x6420676e69747365\n"
".quad 0x2c32203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09373109636f6c2e,0x6c090a3009373533,0x2509203233662e64\n"
".quad 0x72255b202c303166,0x0a3b5d302b323764,0x3233662e64646109,0x202c313166250920\n"
".quad 0x6625202c30316625,0x662e7473090a3b39,0x6472255b09203233,0x25202c5d302b3237\n"
".quad 0x6c2e090a3b313166,0x353309373109636f,0x766f6d090a300938,0x662509203233662e\n"
".quad 0x3b31316625202c39,0x33732e646461090a,0x3936317225092032,0x2c3936317225202c\n"
".quad 0x646461090a3b3120,0x722509203436752e,0x647225202c323764,0x090a3b34202c3237\n"
".quad 0x2e656e2e70746573,0x3370250920323373,0x3037317225202c33,0x3b3936317225202c\n"
".quad 0x203333702540090a,0x744c240920617262,0x36323037395f305f,0x5f305f744c240a3b\n"
".quad 0x090a3a3431353639,0x203233732e646461,0x25202c3331722509,0x323135202c333172\n"
".quad 0x732e646461090a3b,0x3631722509203233,0x3836317225202c35,0x3b3636317225202c\n"
".quad 0x6c2e70746573090a,0x2509203233732e74,0x317225202c343370,0x3735317225202c33\n"
".quad 0x3433702540090a3b,0x4c24092061726220,0x353236395f305f74,0x305f744c240a3b38\n"
".quad 0x0a3a36343735395f,0x373109636f6c2e09,0x090a300930373309,0x636e79732e726162\n"
".quad 0x6c2e090a3b300920,0x373309373109636f,0x766f6d090a300937,0x722509203233732e\n"
".quad 0x3b357225202c3331,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3337317225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3239322b,0x2e746c2e70746573,0x3370250920323373\n"
".quad 0x202c357225202c35,0x090a3b3337317225,0x6220353370252140,0x5f744c2409206172\n"
".quad 0x3b34393737395f30,0x33732e627573090a,0x3437317225092032,0x2c3337317225202c\n"
".quad 0x61090a3b35722520,0x09203233732e6464,0x25202c3537317225,0x3135202c34373172\n"
".quad 0x2e726873090a3b31,0x3172250920323373,0x37317225202c3637,0x090a3b3133202c35\n"
".quad 0x203233732e766f6d,0x202c373731722509,0x6e61090a3b313135,0x2509203233622e64\n"
".quad 0x7225202c38373172,0x317225202c363731,0x646461090a3b3737,0x722509203233732e\n"
".quad 0x317225202c393731,0x37317225202c3837,0x2e726873090a3b35,0x3172250920323373\n"
".quad 0x37317225202c3038,0x63090a3b39202c39,0x732e3436732e7476,0x3764722509203233\n"
".quad 0x0a3b357225202c33,0x6469772e6c756d09,0x2509203233732e65,0x7225202c38336472\n"
".quad 0x6c090a3b34202c35,0x2e74736e6f632e64,0x6472250920343675,0x6472255b202c3437\n"
".quad 0x090a3b5d30382b34,0x74736e6f632e646c,0x722509203436752e,0x72255b202c343664\n"
".quad 0x0a3b5d32372b3464,0x3436752e64646109,0x2c35376472250920,0x202c343764722520\n"
".quad 0x090a3b3833647225,0x74736e6f632e646c,0x722509203233732e,0x5f645b202c313831\n"
".quad 0x332b6e6f6d6d6f63,0x646c090a3b5d3830,0x732e74736e6f632e,0x3831722509203233\n"
".quad 0x6f635f645b202c32,0x3030332b6e6f6d6d,0x632e646c090a3b5d,0x3233732e74736e6f\n"
".quad 0x2c33383172250920,0x6d6d6f635f645b20,0x3b5d3438322b6e6f,0x6e6f632e646c090a\n"
".quad 0x09203233732e7473,0x5b202c3434317225,0x6e6f6d6d6f635f64,0x090a3b5d3836322b\n"
".quad 0x203233732e766f6d,0x202c343831722509,0x240a3b3038317225,0x3338395f305f744c\n"
".quad 0x3c2f2f200a3a3630,0x6f4c203e706f6f6c,0x2079646f6220706f,0x37373320656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x3009313833093731\n"
".quad 0x33732e646461090a,0x2c35327225092032,0x31202c3331722520,0x732e6d6572090a3b\n"
".quad 0x3831722509203233,0x2c35327225202c35,0x0a3b333831722520,0x3233732e62757309\n"
".quad 0x202c373272250920,0x31202c3538317225,0x09636f6c2e090a3b,0x3009323833093731\n"
".quad 0x33732e766964090a,0x2c38327225092032,0x25202c3532722520,0x6d090a3b33383172\n"
".quad 0x09203233752e766f,0x30202c3638317225,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x7225202c36337025,0x317225202c353831,0x702540090a3b3638,0x0920617262203633\n"
".quad 0x38395f305f744c24,0x6c2e090a3b323635,0x383309373109636f,0x627573090a300934\n"
".quad 0x722509203233732e,0x38317225202c3732,0x2e090a3b31202c33,0x3309373109636f6c\n"
".quad 0x7573090a30093538,0x2509203233732e62,0x327225202c383272,0x4c240a3b31202c38\n"
".quad 0x363538395f305f74,0x636f6c2e090a3a32,0x0931393309373109,0x732e646461090a30\n"
".quad 0x3831722509203233,0x2c37327225202c37,0x0a3b323831722520,0x3233732e64646109\n"
".quad 0x2c38383172250920,0x25202c3832722520,0x73090a3b31383172,0x09203233732e6275\n"
".quad 0x25202c3938317225,0x3b31202c38383172,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x317225202c303931,0x38317225202c3434,0x2e646461090a3b39,0x3172250920323373\n"
".quad 0x38317225202c3139,0x3039317225202c37,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x25202c3637647225,0x6d090a3b31393172,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x39317225202c3737,0x61090a3b34202c31,0x09203436752e6464,0x25202c3837647225\n"
".quad 0x7225202c34366472,0x646c090a3b373764,0x662509203233662e,0x6472255b202c3231\n"
".quad 0x0a3b5d342d2b3837,0x203233662e747309,0x2b35376472255b09,0x32316625202c5d30\n"
".quad 0x732e646461090a3b,0x3331722509203233,0x202c33317225202c,0x6461090a3b323135\n"
".quad 0x2509203436752e64,0x7225202c35376472,0x343032202c353764,0x70746573090a3b38\n"
".quad 0x203233732e746c2e,0x25202c3733702509,0x317225202c333172,0x702540090a3b3337\n"
".quad 0x0920617262203733,0x38395f305f744c24,0x744c240a3b363033,0x34393737395f305f\n"
".quad 0x09636f6c2e090a3a,0x3009323034093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x09373109636f6c2e,0x6d090a3009333134,0x09203233732e766f,0x7225202c33317225\n"
".quad 0x632e646c090a3b35,0x3233732e74736e6f,0x2c32393172250920,0x6d6d6f635f645b20\n"
".quad 0x3b5d3034332b6e6f,0x6c2e70746573090a,0x2509203233732e74,0x357225202c383370\n"
".quad 0x3b3239317225202c,0x383370252140090a,0x4c24092061726220,0x303135315f305f74\n"
".quad 0x627573090a3b3234,0x722509203233732e,0x317225202c333931,0x3b357225202c3239\n"
".quad 0x33732e646461090a,0x3439317225092032,0x2c3339317225202c,0x73090a3b31313520\n"
".quad 0x09203233732e7268,0x25202c3539317225,0x3133202c34393172,0x732e766f6d090a3b\n"
".quad 0x3931722509203233,0x0a3b313135202c36,0x3233622e646e6109,0x2c37393172250920\n"
".quad 0x202c353931722520,0x090a3b3639317225,0x203233732e646461,0x202c383931722509\n"
".quad 0x25202c3739317225,0x73090a3b34393172,0x09203233732e7268,0x25202c3939317225\n"
".quad 0x3b39202c38393172,0x36732e747663090a,0x2509203233732e34,0x7225202c39376472\n"
".quad 0x2e6c756d090a3b35,0x3233732e65646977,0x2c38336472250920,0x3b34202c35722520\n"
".quad 0x6e6f632e646c090a,0x09203436752e7473,0x5b202c3038647225,0x5d38382b34647225\n"
".quad 0x6f632e646c090a3b,0x203436752e74736e,0x202c343664722509,0x32372b346472255b\n"
".quad 0x2e646461090a3b5d,0x6472250920343675,0x38647225202c3138,0x3833647225202c30\n"
".quad 0x6f632e646c090a3b,0x203233732e74736e,0x202c303032722509,0x6f6d6d6f635f645b\n"
".quad 0x0a3b5d3432332b6e,0x736e6f632e646c09,0x2509203233732e74,0x645b202c34343172\n"
".quad 0x2b6e6f6d6d6f635f,0x6c090a3b5d383632,0x2e74736e6f632e64,0x3272250920323373\n"
".quad 0x635f645b202c3130,0x31332b6e6f6d6d6f,0x2e646c090a3b5d36,0x33732e74736e6f63\n"
".quad 0x3230327225092032,0x6d6f635f645b202c,0x5d3233332b6e6f6d,0x732e766f6d090a3b\n"
".quad 0x3032722509203233,0x3939317225202c33,0x5f305f744c240a3b,0x200a3a3234383939\n"
".quad 0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964,0x73656e202c333134\n"
".quad 0x70656420676e6974,0x65202c31203a6874,0x646574616d697473,0x6974617265746920\n"
".quad 0x6b6e75203a736e6f,0x6c2e090a6e776f6e,0x313409373109636f,0x646461090a300937\n"
".quad 0x722509203233732e,0x33317225202c3532,0x6572090a3b31202c,0x2509203233732e6d\n"
".quad 0x7225202c34303272,0x30327225202c3532,0x2e627573090a3b32,0x3272250920323373\n"
".quad 0x3430327225202c37,0x6c2e090a3b31202c,0x313409373109636f,0x766964090a300938\n"
".quad 0x722509203233732e,0x35327225202c3832,0x3b3230327225202c,0x33752e766f6d090a\n"
".quad 0x3530327225092032,0x6573090a3b30202c,0x33732e656e2e7074,0x2c39337025092032\n"
".quad 0x202c343032722520,0x090a3b3530327225,0x7262203933702540,0x305f744c24092061\n"
".quad 0x3b3839303030315f,0x3109636f6c2e090a,0x0a30093032340937,0x3233732e62757309\n"
".quad 0x202c373272250920,0x31202c3230327225,0x09636f6c2e090a3b,0x3009313234093731\n"
".quad 0x33732e627573090a,0x2c38327225092032,0x31202c3832722520,0x5f305f744c240a3b\n"
".quad 0x0a3a383930303031,0x373109636f6c2e09,0x090a300937323409,0x203233732e646461\n"
".quad 0x202c363032722509,0x7225202c37327225,0x6461090a3b313032,0x2509203233732e64\n"
".quad 0x7225202c37303272,0x30327225202c3832,0x2e627573090a3b30,0x3272250920323373\n"
".quad 0x30327225202c3830,0x6d090a3b31202c37,0x33732e6f6c2e6c75,0x3930327225092032\n"
".quad 0x2c3434317225202c,0x0a3b383032722520,0x3233732e64646109,0x2c30313272250920\n"
".quad 0x202c363032722520,0x090a3b3930327225,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x31327225202c3238,0x2e6c756d090a3b30,0x3233732e65646977,0x2c33386472250920\n"
".quad 0x202c303132722520,0x2e646461090a3b34,0x6472250920343675,0x36647225202c3438\n"
".quad 0x3338647225202c34,0x33662e646c090a3b,0x2c33316625092032,0x2b34386472255b20\n"
".quad 0x7473090a3b5d342d,0x255b09203233662e,0x2c5d302b31386472,0x090a3b3331662520\n"
".quad 0x203233732e646461,0x25202c3331722509,0x323135202c333172,0x752e646461090a3b\n"
".quad 0x3864722509203436,0x3138647225202c31,0x0a3b38343032202c,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x33317225202c3034,0x3b3239317225202c,0x203034702540090a\n"
".quad 0x744c240920617262,0x32343839395f305f,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b30333339395f30,0x315f305f744c240a,0x090a3a3234303135,0x74736e6f632e646c\n"
".quad 0x722509203233732e,0x5f645b202c323032,0x332b6e6f6d6d6f63,0x744c240a3b5d3233\n"
".quad 0x30333339395f305f,0x09636f6c2e090a3a,0x3009383334093731,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x09373109636f6c2e,0x6d090a3009353434,0x09203233732e766f\n"
".quad 0x7225202c33317225,0x70252140090a3b35,0x0920617262203833,0x30315f305f744c24\n"
".quad 0x73090a3b36363830,0x09203233732e6275,0x25202c3131327225,0x7225202c32393172\n"
".quad 0x2e646461090a3b35,0x3272250920323373,0x31327225202c3231,0x0a3b313135202c31\n"
".quad 0x3233732e72687309,0x2c33313272250920,0x202c323132722520,0x766f6d090a3b3133\n"
".quad 0x722509203233732e,0x313135202c343132,0x622e646e61090a3b,0x3132722509203233\n"
".quad 0x3331327225202c35,0x3b3431327225202c,0x33732e646461090a,0x3631327225092032\n"
".quad 0x2c3531327225202c,0x0a3b323132722520,0x3233732e72687309,0x2c37313272250920\n"
".quad 0x202c363132722520,0x2e747663090a3b39,0x203233732e343673,0x202c353864722509\n"
".quad 0x756d090a3b357225,0x732e656469772e6c,0x3364722509203233,0x202c357225202c38\n"
".quad 0x632e646c090a3b34,0x3436752e74736e6f,0x2c30386472250920,0x382b346472255b20\n"
".quad 0x2e646c090a3b5d38,0x36752e74736e6f63,0x3437647225092034,0x2b346472255b202c\n"
".quad 0x6461090a3b5d3038,0x2509203436752e64,0x7225202c31386472,0x647225202c303864\n"
".quad 0x646461090a3b3833,0x722509203436752e,0x647225202c353764,0x33647225202c3437\n"
".quad 0x2e766f6d090a3b38,0x3272250920323373,0x31327225202c3831,0x305f744c240a3b37\n"
".quad 0x3a3837333130315f,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x6e202c3534342065,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09373109636f6c2e\n"
".quad 0x6c090a3009393434,0x2509203233662e64,0x72255b202c343166,0x0a3b5d302b353764\n"
".quad 0x203233662e646c09,0x5b202c3531662509,0x5d302b3138647225,0x662e627573090a3b\n"
".quad 0x3631662509203233,0x202c34316625202c,0x73090a3b35316625,0x5b09203233662e74\n"
".quad 0x5d302b3138647225,0x0a3b36316625202c,0x3233732e64646109,0x202c333172250920\n"
".quad 0x3135202c33317225,0x2e646461090a3b32,0x6472250920343675,0x37647225202c3537\n"
".quad 0x3b38343032202c35,0x36752e646461090a,0x3138647225092034,0x2c3138647225202c\n"
".quad 0x090a3b3834303220,0x2e746c2e70746573,0x3470250920323373,0x2c33317225202c31\n"
".quad 0x0a3b323931722520,0x6220313470254009,0x5f744c2409206172,0x3837333130315f30\n"
".quad 0x5f305f744c240a3b,0x0a3a363638303031,0x373109636f6c2e09,0x090a300930363409\n"
".quad 0x636e79732e726162,0x6c2e090a3b300920,0x363409373109636f,0x766f6d090a300937\n"
".quad 0x722509203233732e,0x3b357225202c3331,0x6c2e70746573090a,0x2509203233732e74\n"
".quad 0x357225202c323470,0x3b3230327225202c,0x323470252140090a,0x4c24092061726220\n"
".quad 0x383130315f305f74,0x627573090a3b3039,0x722509203233732e,0x327225202c393132\n"
".quad 0x3b357225202c3230,0x33732e646461090a,0x3032327225092032,0x2c3931327225202c\n"
".quad 0x73090a3b31313520,0x09203233732e7268,0x25202c3132327225,0x3133202c30323272\n"
".quad 0x732e766f6d090a3b,0x3232722509203233,0x0a3b313135202c32,0x3233622e646e6109\n"
".quad 0x2c33323272250920,0x202c313232722520,0x090a3b3232327225,0x203233732e646461\n"
".quad 0x202c343232722509,0x25202c3332327225,0x73090a3b30323272,0x09203233732e7268\n"
".quad 0x25202c3532327225,0x3b39202c34323272,0x33732e766f6d090a,0x3632327225092032\n"
".quad 0x3b3532327225202c,0x315f305f744c240a,0x200a3a3230343230,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x73656e202c373634,0x70656420676e6974\n"
".quad 0x65202c31203a6874,0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f\n"
".quad 0x6c2e090a6e776f6e,0x373409373109636f,0x766f6d090a300937,0x722509203233732e\n"
".quad 0x317225202c393631,0x2e646461090a3b33,0x3272250920323373,0x33317225202c3732\n"
".quad 0x3b3239317225202c,0x6c2e70746573090a,0x2509203233732e65,0x327225202c333470\n"
".quad 0x33317225202c3732,0x3334702540090a3b,0x4c24092061726220,0x363230315f305f74\n"
".quad 0x747663090a3b3835,0x3233732e3436732e,0x2c36386472250920,0x0a3b323032722520\n"
".quad 0x6469772e6c756d09,0x2509203233732e65,0x7225202c37386472,0x0a3b34202c323032\n"
".quad 0x736e6f632e646c09,0x2509203436752e74,0x255b202c30386472,0x3b5d38382b346472\n"
".quad 0x36732e747663090a,0x2509203233732e34,0x7225202c38386472,0x6c756d090a3b3331\n"
".quad 0x33732e656469772e,0x3938647225092032,0x202c33317225202c,0x2e646461090a3b34\n"
".quad 0x6472250920343675,0x38647225202c3039,0x3938647225202c30,0x662e766f6d090a3b\n"
".quad 0x2c39662509203233,0x3030303030663020,0x202020203b303030,0x240a30202f2f0920\n"
".quad 0x3330315f305f744c,0x2f2f200a3a303731,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x373420656e696c20,0x697473656e202c37,0x687470656420676e,0x747365202c32203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x0938373409373109,0x33662e646c090a30,0x2c37316625092032,0x2b30396472255b20\n"
".quad 0x646461090a3b5d30,0x662509203233662e,0x37316625202c3831,0x090a3b396625202c\n"
".quad 0x09203233662e7473,0x302b30396472255b,0x3b38316625202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093937340937,0x3233662e766f6d09,0x25202c3966250920,0x6461090a3b383166\n"
".quad 0x2509203233732e64,0x7225202c39363172,0x327225202c393631,0x646461090a3b3230\n"
".quad 0x722509203436752e,0x647225202c303964,0x38647225202c3039,0x70746573090a3b37\n"
".quad 0x203233732e74672e,0x25202c3434702509,0x7225202c37323272,0x2540090a3b393631\n"
".quad 0x2061726220343470,0x315f305f744c2409,0x240a3b3037313330,0x3230315f305f744c\n"
".quad 0x6461090a3a383536,0x2509203233732e64,0x317225202c333172,0x0a3b323135202c33\n"
".quad 0x746c2e7074657309,0x702509203233732e,0x33317225202c3534,0x3b3230327225202c\n"
".quad 0x203534702540090a,0x744c240920617262,0x30343230315f305f,0x305f744c240a3b32\n"
".quad 0x3a3039383130315f,0x3109636f6c2e090a,0x0a30093139340937,0x6e79732e72616209\n"
".quad 0x2e090a3b30092063,0x3409373109636f6c,0x6f6d090a30093839,0x2509203233732e76\n"
".quad 0x357225202c333172,0x6f632e646c090a3b,0x203233732e74736e,0x202c383232722509\n"
".quad 0x6f6d6d6f635f645b,0x0a3b5d3635332b6e,0x746c2e7074657309,0x702509203233732e\n"
".quad 0x2c357225202c3634,0x0a3b383232722520,0x2036347025214009,0x744c240920617262\n"
".quad 0x33393330315f305f,0x2e627573090a3b38,0x3272250920323373,0x32327225202c3932\n"
".quad 0x0a3b357225202c38,0x3233732e64646109,0x2c30333272250920,0x202c393232722520\n"
".quad 0x6873090a3b313135,0x2509203233732e72,0x7225202c31333272,0x3b3133202c303332\n"
".quad 0x33732e766f6d090a,0x3233327225092032,0x090a3b313135202c,0x203233622e646e61\n"
".quad 0x202c333332722509,0x25202c3133327225,0x61090a3b32333272,0x09203233732e6464\n"
".quad 0x25202c3433327225,0x7225202c33333272,0x6873090a3b303332,0x2509203233732e72\n"
".quad 0x7225202c35333272,0x0a3b39202c343332,0x3436732e74766309,0x722509203233732e\n"
".quad 0x357225202c313964,0x772e6c756d090a3b,0x203233732e656469,0x202c383364722509\n"
".quad 0x0a3b34202c357225,0x736e6f632e646c09,0x2509203436752e74,0x255b202c32396472\n"
".quad 0x3b5d36392b346472,0x6e6f632e646c090a,0x09203436752e7473,0x5b202c3038647225\n"
".quad 0x5d38382b34647225,0x752e646461090a3b,0x3964722509203436,0x3239647225202c33\n"
".quad 0x3b3833647225202c,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3633327225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3237332b,0x74736e6f632e646c,0x722509203233732e\n"
".quad 0x5f645b202c373332,0x332b6e6f6d6d6f63,0x646c090a3b5d3436,0x732e74736e6f632e\n"
".quad 0x3332722509203233,0x6f635f645b202c38,0x3834332b6e6f6d6d,0x2e766f6d090a3b5d\n"
".quad 0x3272250920323373,0x33327225202c3933,0x305f744c240a3b35,0x3a3035343430315f\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3839342065\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09373109636f6c2e,0x61090a3009323035\n"
".quad 0x09203233732e6464,0x7225202c35327225,0x090a3b31202c3331,0x203233732e6d6572\n"
".quad 0x202c303432722509,0x7225202c35327225,0x7573090a3b383332,0x2509203233732e62\n"
".quad 0x327225202c373272,0x090a3b31202c3034,0x09373109636f6c2e,0x64090a3009333035\n"
".quad 0x09203233732e7669,0x7225202c38327225,0x33327225202c3532,0x2e766f6d090a3b38\n"
".quad 0x3272250920323375,0x090a3b30202c3134,0x2e656e2e70746573,0x3470250920323373\n"
".quad 0x3034327225202c37,0x3b3134327225202c,0x203734702540090a,0x744c240920617262\n"
".quad 0x30373430315f305f,0x636f6c2e090a3b36,0x0935303509373109,0x732e627573090a30\n"
".quad 0x3732722509203233,0x2c3833327225202c,0x6f6c2e090a3b3120,0x3630350937310963\n"
".quad 0x2e627573090a3009,0x3272250920323373,0x2c38327225202c38,0x5f744c240a3b3120\n"
".quad 0x3630373430315f30,0x09636f6c2e090a3a,0x3009323135093731,0x33732e646461090a\n"
".quad 0x3234327225092032,0x202c37327225202c,0x090a3b3733327225,0x203233732e646461\n"
".quad 0x202c333432722509,0x7225202c38327225,0x7573090a3b363332,0x2509203233732e62\n"
".quad 0x7225202c34343272,0x0a3b31202c333432,0x2e6f6c2e6c756d09,0x3272250920323373\n"
".quad 0x30327225202c3534,0x3434327225202c32,0x732e646461090a3b,0x3432722509203233\n"
".quad 0x3234327225202c36,0x3b3534327225202c,0x36732e747663090a,0x2509203233732e34\n"
".quad 0x7225202c34396472,0x756d090a3b363432,0x732e656469772e6c,0x3964722509203233\n"
".quad 0x3634327225202c35,0x6461090a3b34202c,0x2509203436752e64,0x7225202c36396472\n"
".quad 0x647225202c303864,0x2e646c090a3b3539,0x3166250920323366,0x396472255b202c39\n"
".quad 0x090a3b5d342d2b36,0x09203233662e7473,0x302b33396472255b,0x3b39316625202c5d\n"
".quad 0x33732e646461090a,0x2c33317225092032,0x35202c3331722520,0x646461090a3b3231\n"
".quad 0x722509203436752e,0x647225202c333964,0x38343032202c3339,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c38347025,0x32327225202c3331,0x34702540090a3b38\n"
".quad 0x2409206172622038,0x3430315f305f744c,0x744c240a3b303534,0x33393330315f305f\n"
".quad 0x636f6c2e090a3a38,0x0933323509373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300934333509,0x203233732e766f6d,0x25202c3331722509\n"
".quad 0x2e646c090a3b3572,0x33732e74736e6f63,0x3734327225092032,0x6d6f635f645b202c\n"
".quad 0x5d3430342b6e6f6d,0x2e70746573090a3b,0x09203233732e746c,0x7225202c39347025\n"
".quad 0x3734327225202c35,0x3470252140090a3b,0x2409206172622039,0x3530315f305f744c\n"
".quad 0x7573090a3b343734,0x2509203233732e62,0x7225202c38343272,0x357225202c373432\n"
".quad 0x732e646461090a3b,0x3432722509203233,0x3834327225202c39,0x090a3b313135202c\n"
".quad 0x203233732e726873,0x202c303532722509,0x33202c3934327225,0x2e766f6d090a3b31\n"
".quad 0x3272250920323373,0x3b313135202c3135,0x33622e646e61090a,0x3235327225092032\n"
".quad 0x2c3035327225202c,0x0a3b313532722520,0x3233732e64646109,0x2c33353272250920\n"
".quad 0x202c323532722520,0x090a3b3934327225,0x203233732e726873,0x202c343532722509\n"
".quad 0x39202c3335327225,0x732e747663090a3b,0x09203233732e3436,0x25202c3739647225\n"
".quad 0x6c756d090a3b3572,0x33732e656469772e,0x3833647225092032,0x34202c357225202c\n"
".quad 0x6f632e646c090a3b,0x203436752e74736e,0x202c383964722509,0x30312b346472255b\n"
".quad 0x2e646c090a3b5d34,0x36752e74736e6f63,0x3038647225092034,0x2b346472255b202c\n"
".quad 0x6461090a3b5d3838,0x2509203436752e64,0x7225202c39396472,0x647225202c383964\n"
".quad 0x2e646c090a3b3833,0x33732e74736e6f63,0x3535327225092032,0x6d6f635f645b202c\n"
".quad 0x5d3838332b6e6f6d,0x6f632e646c090a3b,0x203233732e74736e,0x202c363532722509\n"
".quad 0x6f6d6d6f635f645b,0x0a3b5d3038332b6e,0x736e6f632e646c09,0x2509203233732e74\n"
".quad 0x645b202c37353272,0x2b6e6f6d6d6f635f,0x6d090a3b5d363933,0x09203233732e766f\n"
".quad 0x25202c3835327225,0x4c240a3b34353272,0x393530315f305f74,0x3c2f2f200a3a3638\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x34333520656e696c,0x6e697473656e202c\n"
".quad 0x3a68747065642067,0x69747365202c3120,0x746920646574616d,0x736e6f6974617265\n"
".quad 0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x3009383335093731,0x33732e646461090a\n"
".quad 0x2c35327225092032,0x31202c3331722520,0x732e6d6572090a3b,0x3532722509203233\n"
".quad 0x2c35327225202c39,0x0a3b373532722520,0x3233732e62757309,0x202c373272250920\n"
".quad 0x31202c3935327225,0x09636f6c2e090a3b,0x3009393335093731,0x33732e766964090a\n"
".quad 0x2c38327225092032,0x25202c3532722520,0x6d090a3b37353272,0x09203233752e766f\n"
".quad 0x30202c3036327225,0x2e70746573090a3b,0x09203233732e656e,0x7225202c30357025\n"
".quad 0x327225202c393532,0x702540090a3b3036,0x0920617262203035,0x30315f305f744c24\n"
".quad 0x2e090a3b32343236,0x3509373109636f6c,0x7573090a30093134,0x2509203233732e62\n"
".quad 0x327225202c373272,0x090a3b31202c3735,0x09373109636f6c2e,0x73090a3009323435\n"
".quad 0x09203233732e6275,0x7225202c38327225,0x240a3b31202c3832,0x3630315f305f744c\n"
".quad 0x6c2e090a3a323432,0x343509373109636f,0x646461090a300938,0x722509203233732e\n"
".quad 0x327225202c313632,0x3635327225202c37,0x732e646461090a3b,0x3632722509203233\n"
".quad 0x2c38327225202c32,0x0a3b353532722520,0x3233732e62757309,0x2c33363272250920\n"
".quad 0x202c323632722520,0x2e6c756d090a3b31,0x09203233732e6f6c,0x25202c3436327225\n"
".quad 0x7225202c32303272,0x6461090a3b333632,0x2509203233732e64,0x7225202c35363272\n"
".quad 0x327225202c313632,0x747663090a3b3436,0x3233732e3436732e,0x3030316472250920\n"
".quad 0x3b3536327225202c,0x69772e6c756d090a,0x09203233732e6564,0x202c313031647225\n"
".quad 0x34202c3536327225,0x752e646461090a3b,0x3164722509203436,0x38647225202c3230\n"
".quad 0x3031647225202c30,0x662e646c090a3b31,0x3032662509203233,0x30316472255b202c\n"
".quad 0x090a3b5d342d2b32,0x09203233662e7473,0x302b39396472255b,0x3b30326625202c5d\n"
".quad 0x33732e646461090a,0x2c33317225092032,0x35202c3331722520,0x646461090a3b3231\n"
".quad 0x722509203436752e,0x647225202c393964,0x38343032202c3939,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c31357025,0x34327225202c3331,0x35702540090a3b37\n"
".quad 0x2409206172622031,0x3530315f305f744c,0x744c240a3b363839,0x37343530315f305f\n"
".quad 0x636f6c2e090a3a34,0x0939353509373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300936363509,0x203233732e766f6d,0x25202c3331722509\n"
".quad 0x252140090a3b3572,0x2061726220393470,0x315f305f744c2409,0x090a3b3031303730\n"
".quad 0x203233732e627573,0x202c363632722509,0x25202c3734327225,0x646461090a3b3572\n"
".quad 0x722509203233732e,0x327225202c373632,0x3b313135202c3636,0x33732e726873090a\n"
".quad 0x3836327225092032,0x2c3736327225202c,0x6f6d090a3b313320,0x2509203233732e76\n"
".quad 0x3135202c39363272,0x2e646e61090a3b31,0x3272250920323362,0x36327225202c3037\n"
".quad 0x3936327225202c38,0x732e646461090a3b,0x3732722509203233,0x3037327225202c31\n"
".quad 0x3b3736327225202c,0x33732e726873090a,0x3237327225092032,0x2c3137327225202c\n"
".quad 0x747663090a3b3920,0x3233732e3436732e,0x3330316472250920,0x090a3b357225202c\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x357225202c383364,0x646c090a3b34202c\n"
".quad 0x752e74736e6f632e,0x3964722509203436,0x346472255b202c38,0x090a3b5d3430312b\n"
".quad 0x74736e6f632e646c,0x722509203436752e,0x72255b202c323964,0x0a3b5d36392b3464\n"
".quad 0x3436752e64646109,0x2c39396472250920,0x202c383964722520,0x090a3b3833647225\n"
".quad 0x203436752e646461,0x202c333964722509,0x25202c3239647225,0x6d090a3b38336472\n"
".quad 0x09203233732e766f,0x25202c3337327225,0x4c240a3b32373272,0x353730315f305f74\n"
".quad 0x3c2f2f200a3a3232,0x6f4c203e706f6f6c,0x2079646f6220706f,0x36363520656e696c\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x3009303735093731\n"
".quad 0x3233662e646c090a,0x202c313266250920,0x302b33396472255b,0x662e646c090a3b5d\n"
".quad 0x3232662509203233,0x39396472255b202c,0x7573090a3b5d302b,0x2509203233662e62\n"
".quad 0x326625202c333266,0x3b32326625202c31,0x3233662e7473090a,0x39396472255b0920\n"
".quad 0x326625202c5d302b,0x2e646461090a3b33,0x3172250920323373,0x2c33317225202c33\n"
".quad 0x61090a3b32313520,0x09203436752e6464,0x25202c3339647225,0x3032202c33396472\n"
".quad 0x646461090a3b3834,0x722509203436752e,0x647225202c393964,0x38343032202c3939\n"
".quad 0x2e70746573090a3b,0x09203233732e746c,0x7225202c32357025,0x34327225202c3331\n"
".quad 0x35702540090a3b37,0x2409206172622032,0x3730315f305f744c,0x744c240a3b323235\n"
".quad 0x31303730315f305f,0x636f6c2e090a3a30,0x0931383509373109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x373109636f6c2e09,0x090a300932393509,0x203233732e766f6d\n"
".quad 0x25202c3331722509,0x2e646c090a3b3572,0x33732e74736e6f63,0x3437327225092032\n"
".quad 0x6d6f635f645b202c,0x5d3032342b6e6f6d,0x2e70746573090a3b,0x09203233732e6567\n"
".quad 0x7225202c33357025,0x3437327225202c35,0x3335702540090a3b,0x4c24092061726220\n"
".quad 0x303830315f305f74,0x627573090a3b3433,0x722509203233732e,0x327225202c353732\n"
".quad 0x3b357225202c3437,0x33732e646461090a,0x3637327225092032,0x2c3537327225202c\n"
".quad 0x73090a3b31313520,0x09203233732e7268,0x25202c3737327225,0x3133202c36373272\n"
".quad 0x732e766f6d090a3b,0x3732722509203233,0x0a3b313135202c38,0x3233622e646e6109\n"
".quad 0x2c39373272250920,0x202c373732722520,0x090a3b3837327225,0x203233732e646461\n"
".quad 0x202c303832722509,0x25202c3937327225,0x73090a3b36373272,0x09203233732e7268\n"
".quad 0x25202c3138327225,0x3b39202c30383272,0x36732e747663090a,0x2509203233732e34\n"
".quad 0x25202c3430316472,0x6c756d090a3b3572,0x33732e656469772e,0x3833647225092032\n"
".quad 0x34202c357225202c,0x6f632e646c090a3b,0x203436752e74736e,0x2c35303164722509\n"
".quad 0x312b346472255b20,0x646c090a3b5d3231,0x752e74736e6f632e,0x3364722509203436\n"
".quad 0x346472255b202c39,0x61090a3b5d38342b,0x09203436752e6464,0x202c363031647225\n"
".quad 0x202c353031647225,0x090a3b3833647225,0x203436752e646461,0x202c303464722509\n"
".quad 0x25202c3933647225,0x6d090a3b38336472,0x09203233732e766f,0x25202c3238327225\n"
".quad 0x4c240a3b31383272,0x353830315f305f74,0x3c2f2f200a3a3634,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x32393520656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x09636f6c2e090a6e,0x3009353935093731,0x3233662e646c090a,0x202c343266250920\n"
".quad 0x302b30346472255b,0x636f6c2e090a3b5d,0x0936393509373109,0x662e6c756d090a30\n"
".quad 0x3532662509203233,0x202c34326625202c,0x73090a3b34326625,0x5b09203233662e74\n"
".quad 0x302b363031647225,0x3b35326625202c5d,0x33732e646461090a,0x2c33317225092032\n"
".quad 0x35202c3331722520,0x646461090a3b3231,0x722509203436752e,0x647225202c303464\n"
".quad 0x38343032202c3034,0x752e646461090a3b,0x3164722509203436,0x31647225202c3630\n"
".quad 0x38343032202c3630,0x2e70746573090a3b,0x09203233732e746c,0x7225202c34357025\n"
".quad 0x37327225202c3331,0x35702540090a3b34,0x2409206172622034,0x3830315f305f744c\n"
".quad 0x744c240a3b363435,0x33303830315f305f,0x636f6c2e090a3a34,0x0937303609373109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x373109636f6c2e09,0x090a300938313609\n"
".quad 0x203233732e766f6d,0x25202c3331722509,0x252140090a3b3572,0x2061726220343270\n"
".quad 0x315f305f744c2409,0x090a3b3835303930,0x203233732e627573,0x202c333832722509\n"
".quad 0x25202c3433317225,0x646461090a3b3572,0x722509203233732e,0x327225202c343832\n"
".quad 0x3b313135202c3338,0x33732e726873090a,0x3538327225092032,0x2c3438327225202c\n"
".quad 0x6f6d090a3b313320,0x2509203233732e76,0x3135202c36383272,0x2e646e61090a3b31\n"
".quad 0x3272250920323362,0x38327225202c3738,0x3638327225202c35,0x732e646461090a3b\n"
".quad 0x3832722509203233,0x3738327225202c38,0x3b3438327225202c,0x33732e726873090a\n"
".quad 0x3938327225092032,0x2c3838327225202c,0x747663090a3b3920,0x3233732e3436732e\n"
".quad 0x2c33366472250920,0x6c090a3b35722520,0x2e74736e6f632e64,0x3172250920323373\n"
".quad 0x635f645b202c3234,0x36322b6e6f6d6d6f,0x627573090a3b5d30,0x722509203233732e\n"
".quad 0x317225202c333431,0x090a3b31202c3234,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x357225202c383364,0x646c090a3b34202c,0x752e74736e6f632e,0x3664722509203436\n"
".quad 0x346472255b202c34,0x61090a3b5d32372b,0x09203436752e6464,0x25202c3536647225\n"
".quad 0x7225202c34366472,0x646c090a3b383364,0x732e74736e6f632e,0x3431722509203233\n"
".quad 0x6f635f645b202c34,0x3836322b6e6f6d6d,0x2e766f6d090a3b5d,0x3272250920323373\n"
".quad 0x38327225202c3039,0x305f744c240a3b39,0x3a3037353930315f,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3831362065,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09373109636f6c2e,0x61090a3009323236,0x09203233732e6464\n"
".quad 0x7225202c35327225,0x090a3b31202c3331,0x203233732e6d6572,0x202c313932722509\n"
".quad 0x7225202c35327225,0x7573090a3b343431,0x2509203233732e62,0x327225202c373272\n"
".quad 0x090a3b31202c3139,0x09373109636f6c2e,0x64090a3009333236,0x09203233732e7669\n"
".quad 0x7225202c38327225,0x34317225202c3532,0x2e766f6d090a3b34,0x3272250920323375\n"
".quad 0x090a3b30202c3239,0x2e656e2e70746573,0x3570250920323373,0x3139327225202c35\n"
".quad 0x3b3239327225202c,0x203535702540090a,0x744c240920617262,0x32383930315f305f\n"
".quad 0x636f6c2e090a3b36,0x0935323609373109,0x732e627573090a30,0x3732722509203233\n"
".quad 0x2c3434317225202c,0x6f6c2e090a3b3120,0x3632360937310963,0x2e627573090a3009\n"
".quad 0x3272250920323373,0x2c38327225202c38,0x5f744c240a3b3120,0x3632383930315f30\n"
".quad 0x09636f6c2e090a3a,0x3009303336093731,0x672e70746573090a,0x2509203233732e65\n"
".quad 0x317225202c363570,0x37327225202c3334,0x3635702540090a3b,0x4c24092061726220\n"
".quad 0x383335315f305f74,0x2e646c090a3b3835,0x33732e74736e6f63,0x3339327225092032\n"
".quad 0x6d6f635f645b202c,0x5d3231342b6e6f6d,0x732e646461090a3b,0x3932722509203233\n"
".quad 0x3339327225202c34,0x3b3234317225202c,0x672e70746573090a,0x2509203233732e65\n"
".quad 0x327225202c373570,0x3439327225202c37,0x3735702540090a3b,0x4c24092061726220\n"
".quad 0x383335315f305f74,0x2e646c090a3b3835,0x33732e74736e6f63,0x3934317225092032\n"
".quad 0x6d6f635f645b202c,0x5d3436322b6e6f6d,0x732e627573090a3b,0x3932722509203233\n"
".quad 0x3934317225202c35,0x6573090a3b31202c,0x33732e656c2e7074,0x2c38357025092032\n"
".quad 0x25202c3832722520,0x40090a3b35393272,0x6172622038357025,0x5f305f744c240920\n"
".quad 0x0a3b383538333531,0x736e6f632e646c09,0x2509203233732e74,0x645b202c36393272\n"
".quad 0x2b6e6f6d6d6f635f,0x61090a3b5d363134,0x09203233732e6464,0x25202c3739327225\n"
".quad 0x7225202c36393272,0x6573090a3b393431,0x33732e65672e7074,0x2c39357025092032\n"
".quad 0x25202c3832722520,0x40090a3b37393272,0x6172622039357025,0x5f305f744c240920\n"
".quad 0x0a3b383538333531,0x373109636f6c2e09,0x090a300936333609,0x74736e6f632e646c\n"
".quad 0x722509203436752e,0x255b202c37303164,0x5d3231312b346472,0x732e627573090a3b\n"
".quad 0x3932722509203233,0x2c38327225202c38,0x0a3b393431722520,0x2e6f6c2e6c756d09\n"
".quad 0x3272250920323373,0x39327225202c3939,0x3839327225202c33,0x732e627573090a3b\n"
".quad 0x3033722509203233,0x2c37327225202c30,0x0a3b323431722520,0x3233732e64646109\n"
".quad 0x2c31303372250920,0x202c393932722520,0x090a3b3030337225,0x2e3436732e747663\n"
".quad 0x6472250920323373,0x337225202c383031,0x6c756d090a3b3130,0x33732e656469772e\n"
".quad 0x3031647225092032,0x3130337225202c39,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x25202c3031316472,0x25202c3730316472,0x090a3b3930316472,0x09203233662e646c\n"
".quad 0x255b202c36326625,0x5d302b3031316472,0x33662e7473090a3b,0x366472255b092032\n"
".quad 0x6625202c5d302b35,0x617262090a3b3632,0x4c240920696e752e,0x32303233385f305f\n"
".quad 0x5f305f744c240a3b,0x0a3a383538333531,0x3433385f305f4c24,0x6f6c2e090a3a3835\n"
".quad 0x3933360937310963,0x2e766f6d090a3009,0x3266250920323366,0x3030306630202c37\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x203233662e747309,0x2b35366472255b09\n"
".quad 0x37326625202c5d30,0x385f305f4c240a3b,0x61090a3a32303233,0x09203233732e6464\n"
".quad 0x7225202c33317225,0x3b323135202c3331,0x36752e646461090a,0x3536647225092034\n"
".quad 0x2c3536647225202c,0x090a3b3834303220,0x2e746c2e70746573,0x3670250920323373\n"
".quad 0x2c33317225202c30,0x0a3b343331722520,0x6220303670254009,0x5f744c2409206172\n"
".quad 0x3037353930315f30,0x5f305f744c240a3b,0x0a3a383530393031,0x373109636f6c2e09\n"
".quad 0x090a300931353609,0x636e79732e726162,0x6c2e090a3b300920,0x353609373109636f\n"
".quad 0x766f6d090a300938,0x722509203233732e,0x3b357225202c3331,0x313370252140090a\n"
".quad 0x4c24092061726220,0x353031315f305f74,0x627573090a3b3439,0x722509203233732e\n"
".quad 0x317225202c323033,0x3b357225202c3735,0x33732e646461090a,0x3330337225092032\n"
".quad 0x2c3230337225202c,0x73090a3b31313520,0x09203233732e7268,0x25202c3430337225\n"
".quad 0x3133202c33303372,0x732e766f6d090a3b,0x3033722509203233,0x0a3b313135202c35\n"
".quad 0x3233622e646e6109,0x2c36303372250920,0x202c343033722520,0x090a3b3530337225\n"
".quad 0x203233732e646461,0x202c373033722509,0x25202c3630337225,0x73090a3b33303372\n"
".quad 0x09203233732e7268,0x25202c3830337225,0x3b39202c37303372,0x6e6f632e646c090a\n"
".quad 0x09203233732e7473,0x5b202c3434317225,0x6e6f6d6d6f635f64,0x090a3b5d3836322b\n"
".quad 0x732e6f6c2e6c756d,0x3631722509203233,0x202c357225202c35,0x090a3b3434317225\n"
".quad 0x732e6f6c2e6c756d,0x3631722509203233,0x3434317225202c36,0x090a3b323135202c\n"
".quad 0x203233732e766f6d,0x202c393033722509,0x240a3b3830337225,0x3131315f305f744c\n"
".quad 0x2f2f200a3a363031,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x353620656e696c20\n"
".quad 0x697473656e202c38,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0938363609373109\n"
".quad 0x732e766f6d090a30,0x3133722509203233,0x3536317225202c30,0x732e766f6d090a3b\n"
".quad 0x3631722509203233,0x3031337225202c39,0x732e646461090a3b,0x3731722509203233\n"
".quad 0x3031337225202c30,0x3b3434317225202c,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x317225202c313670,0x31337225202c3037,0x36702540090a3b30,0x2409206172622031\n"
".quad 0x3131315f305f744c,0x6f6d090a3b323633,0x2509203233732e76,0x7225202c31313372\n"
".quad 0x646c090a3b343431,0x752e74736e6f632e,0x3664722509203436,0x346472255b202c34\n"
".quad 0x63090a3b5d32372b,0x732e3436732e7476,0x3164722509203233,0x31337225202c3131\n"
".quad 0x2e6c756d090a3b30,0x3233732e65646977,0x3231316472250920,0x2c3031337225202c\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c323764,0x31647225202c3436\n"
".quad 0x766f6d090a3b3231,0x662509203233662e,0x3030306630202c39,0x20203b3030303030\n"
".quad 0x30202f2f09202020,0x33732e766f6d090a,0x3231337225092032,0x3b3131337225202c\n"
".quad 0x315f305f744c240a,0x200a3a3437383131,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x73656e202c383636,0x70656420676e6974,0x65202c32203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e\n"
".quad 0x363609373109636f,0x2e646c090a300939,0x3266250920323366,0x376472255b202c38\n"
".quad 0x61090a3b5d302b32,0x09203233662e6464,0x6625202c39326625,0x3b396625202c3832\n"
".quad 0x3233662e7473090a,0x32376472255b0920,0x326625202c5d302b,0x636f6c2e090a3b39\n"
".quad 0x0930373609373109,0x662e766f6d090a30,0x2c39662509203233,0x090a3b3932662520\n"
".quad 0x203233732e646461,0x202c393631722509,0x31202c3936317225,0x752e646461090a3b\n"
".quad 0x3764722509203436,0x3237647225202c32,0x6573090a3b34202c,0x33732e656e2e7074\n"
".quad 0x2c32367025092032,0x202c303731722520,0x090a3b3936317225,0x7262203236702540\n"
".quad 0x305f744c24092061,0x3b3437383131315f,0x315f305f744c240a,0x090a3a3236333131\n"
".quad 0x203233732e646461,0x25202c3331722509,0x323135202c333172,0x732e646461090a3b\n"
".quad 0x3631722509203233,0x3031337225202c35,0x3b3636317225202c,0x6c2e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c333670,0x3735317225202c33,0x3336702540090a3b\n"
".quad 0x4c24092061726220,0x313131315f305f74,0x5f744c240a3b3630,0x3439353031315f30\n"
".quad 0x09636f6c2e090a3a,0x3009323836093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x09373109636f6c2e,0x6d090a3009393836,0x09203233732e766f,0x7225202c33317225\n"
".quad 0x70252140090a3b35,0x0920617262203533,0x31315f305f744c24,0x73090a3b32343632\n"
".quad 0x09203233732e6275,0x25202c3331337225,0x7225202c33373172,0x2e646461090a3b35\n"
".quad 0x3372250920323373,0x31337225202c3431,0x0a3b313135202c33,0x3233732e72687309\n"
".quad 0x2c35313372250920,0x202c343133722520,0x766f6d090a3b3133,0x722509203233732e\n"
".quad 0x313135202c363133,0x622e646e61090a3b,0x3133722509203233,0x3531337225202c37\n"
".quad 0x3b3631337225202c,0x33732e646461090a,0x3831337225092032,0x2c3731337225202c\n"
".quad 0x0a3b343133722520,0x3233732e72687309,0x2c39313372250920,0x202c383133722520\n"
".quad 0x2e747663090a3b39,0x203233732e343673,0x2c33313164722509,0x6d090a3b35722520\n"
".quad 0x2e656469772e6c75,0x6472250920323373,0x2c357225202c3833,0x2e646c090a3b3420\n"
".quad 0x36752e74736e6f63,0x3437647225092034,0x2b346472255b202c,0x646c090a3b5d3038\n"
".quad 0x752e74736e6f632e,0x3664722509203436,0x346472255b202c34,0x61090a3b5d32372b\n"
".quad 0x09203436752e6464,0x25202c3537647225,0x7225202c34376472,0x646c090a3b383364\n"
".quad 0x732e74736e6f632e,0x3831722509203233,0x6f635f645b202c31,0x3830332b6e6f6d6d\n"
".quad 0x632e646c090a3b5d,0x3233732e74736e6f,0x2c32383172250920,0x6d6d6f635f645b20\n"
".quad 0x3b5d3030332b6e6f,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3338317225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3438322b,0x74736e6f632e646c,0x722509203233732e\n"
".quad 0x5f645b202c343431,0x322b6e6f6d6d6f63,0x6f6d090a3b5d3836,0x2509203233732e76\n"
".quad 0x7225202c30323372,0x744c240a3b393133,0x35313331315f305f,0x6c3c2f2f200a3a34\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x2c39383620656e69,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x0a30093339360937,0x3233732e64646109\n"
".quad 0x202c353272250920,0x3b31202c33317225,0x33732e6d6572090a,0x3132337225092032\n"
".quad 0x202c35327225202c,0x090a3b3338317225,0x203233732e627573,0x25202c3732722509\n"
".quad 0x3b31202c31323372,0x3109636f6c2e090a,0x0a30093439360937,0x3233732e76696409\n"
".quad 0x202c383272250920,0x7225202c35327225,0x6f6d090a3b333831,0x2509203233752e76\n"
".quad 0x3b30202c32323372,0x6e2e70746573090a,0x2509203233732e65,0x337225202c343670\n"
".quad 0x32337225202c3132,0x36702540090a3b32,0x2409206172622034,0x3331315f305f744c\n"
".quad 0x6c2e090a3b303134,0x393609373109636f,0x627573090a300936,0x722509203233732e\n"
".quad 0x38317225202c3732,0x2e090a3b31202c33,0x3609373109636f6c,0x7573090a30093739\n"
".quad 0x2509203233732e62,0x327225202c383272,0x4c240a3b31202c38,0x343331315f305f74\n"
".quad 0x6f6c2e090a3a3031,0x3330370937310963,0x2e646461090a3009,0x3372250920323373\n"
".quad 0x37327225202c3332,0x3b3238317225202c,0x33732e646461090a,0x3432337225092032\n"
".quad 0x202c38327225202c,0x090a3b3138317225,0x203233732e627573,0x202c353233722509\n"
".quad 0x31202c3432337225,0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c36323372\n"
".quad 0x337225202c343431,0x646461090a3b3532,0x722509203233732e,0x337225202c373233\n"
".quad 0x32337225202c3332,0x2e747663090a3b36,0x203233732e343673,0x2c34313164722509\n"
".quad 0x0a3b373233722520,0x6469772e6c756d09,0x2509203233732e65,0x25202c3531316472\n"
".quad 0x3b34202c37323372,0x36752e646461090a,0x3131647225092034,0x3436647225202c36\n"
".quad 0x353131647225202c,0x33662e646c090a3b,0x2c30336625092032,0x3631316472255b20\n"
".quad 0x73090a3b5d342d2b,0x5b09203233662e74,0x5d302b3537647225,0x0a3b30336625202c\n"
".quad 0x3233732e64646109,0x202c333172250920,0x3135202c33317225,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x37647225202c3537,0x3b38343032202c35,0x6c2e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c353670,0x3337317225202c33,0x3536702540090a3b\n"
".quad 0x4c24092061726220,0x313331315f305f74,0x5f744c240a3b3435,0x3234363231315f30\n"
".quad 0x09636f6c2e090a3a,0x3009343137093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x09373109636f6c2e,0x6d090a3009353237,0x09203233732e766f,0x7225202c33317225\n"
".quad 0x70252140090a3b35,0x0920617262203833,0x31315f305f744c24,0x73090a3b38373134\n"
".quad 0x09203233732e6275,0x25202c3832337225,0x7225202c32393172,0x2e646461090a3b35\n"
".quad 0x3372250920323373,0x32337225202c3932,0x0a3b313135202c38,0x3233732e72687309\n"
".quad 0x2c30333372250920,0x202c393233722520,0x766f6d090a3b3133,0x722509203233732e\n"
".quad 0x313135202c313333,0x622e646e61090a3b,0x3333722509203233,0x3033337225202c32\n"
".quad 0x3b3133337225202c,0x33732e646461090a,0x3333337225092032,0x2c3233337225202c\n"
".quad 0x0a3b393233722520,0x3233732e72687309,0x2c34333372250920,0x202c333333722520\n"
".quad 0x2e747663090a3b39,0x203233732e343673,0x2c37313164722509,0x6d090a3b35722520\n"
".quad 0x2e656469772e6c75,0x6472250920323373,0x2c357225202c3833,0x2e646c090a3b3420\n"
".quad 0x36752e74736e6f63,0x3038647225092034,0x2b346472255b202c,0x646c090a3b5d3838\n"
".quad 0x752e74736e6f632e,0x3664722509203436,0x346472255b202c34,0x61090a3b5d32372b\n"
".quad 0x09203436752e6464,0x25202c3138647225,0x7225202c30386472,0x646c090a3b383364\n"
".quad 0x732e74736e6f632e,0x3032722509203233,0x6f635f645b202c30,0x3432332b6e6f6d6d\n"
".quad 0x632e646c090a3b5d,0x3233732e74736e6f,0x2c34343172250920,0x6d6d6f635f645b20\n"
".quad 0x3b5d3836322b6e6f,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3130327225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3631332b,0x203233732e766f6d,0x202c353333722509\n"
".quad 0x240a3b3433337225,0x3431315f305f744c,0x2f2f200a3a303936,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x323720656e696c20,0x697473656e202c35,0x687470656420676e\n"
".quad 0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73\n"
".quad 0x636f6c2e090a6e77,0x0939323709373109,0x732e646461090a30,0x3532722509203233\n"
".quad 0x202c33317225202c,0x2e6d6572090a3b31,0x3372250920323373,0x35327225202c3633\n"
".quad 0x3b3230327225202c,0x33732e627573090a,0x2c37327225092032,0x202c363333722520\n"
".quad 0x636f6c2e090a3b31,0x0930333709373109,0x732e766964090a30,0x3832722509203233\n"
".quad 0x202c35327225202c,0x090a3b3230327225,0x203233752e766f6d,0x202c373333722509\n"
".quad 0x70746573090a3b30,0x203233732e656e2e,0x25202c3636702509,0x7225202c36333372\n"
".quad 0x2540090a3b373333,0x2061726220363670,0x315f305f744c2409,0x090a3b3634393431\n"
".quad 0x09373109636f6c2e,0x73090a3009323337,0x09203233732e6275,0x7225202c37327225\n"
".quad 0x0a3b31202c323032,0x373109636f6c2e09,0x090a300933333709,0x203233732e627573\n"
".quad 0x25202c3832722509,0x0a3b31202c383272,0x31315f305f744c24,0x2e090a3a36343934\n"
".quad 0x3709373109636f6c,0x6461090a30093933,0x2509203233732e64,0x7225202c38333372\n"
".quad 0x30327225202c3732,0x2e646461090a3b31,0x3372250920323373,0x38327225202c3933\n"
".quad 0x3b3030327225202c,0x33732e627573090a,0x3034337225092032,0x2c3933337225202c\n"
".quad 0x6c756d090a3b3120,0x203233732e6f6c2e,0x202c313433722509,0x25202c3434317225\n"
".quad 0x61090a3b30343372,0x09203233732e6464,0x25202c3234337225,0x7225202c38333372\n"
".quad 0x7663090a3b313433,0x33732e3436732e74,0x3131647225092032,0x3234337225202c38\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x2c39313164722509,0x202c323433722520\n"
".quad 0x2e646461090a3b34,0x6472250920343675,0x647225202c303231,0x31647225202c3436\n"
".quad 0x2e646c090a3b3931,0x3366250920323366,0x316472255b202c31,0x0a3b5d342d2b3032\n"
".quad 0x203233662e747309,0x2b31386472255b09,0x31336625202c5d30,0x732e646461090a3b\n"
".quad 0x3331722509203233,0x202c33317225202c,0x6461090a3b323135,0x2509203436752e64\n"
".quad 0x7225202c31386472,0x343032202c313864,0x70746573090a3b38,0x203233732e746c2e\n"
".quad 0x25202c3736702509,0x317225202c333172,0x702540090a3b3239,0x0920617262203736\n"
".quad 0x31315f305f744c24,0x4c240a3b30393634,0x313431315f305f74,0x6f6c2e090a3a3837\n"
".quad 0x3035370937310963,0x2e726162090a3009,0x3b300920636e7973,0x3109636f6c2e090a\n"
".quad 0x0a30093735370937,0x3233732e766f6d09,0x202c333172250920,0x2140090a3b357225\n"
".quad 0x6172622038337025,0x5f305f744c240920,0x0a3b343137353131,0x3233732e62757309\n"
".quad 0x2c33343372250920,0x202c323931722520,0x6461090a3b357225,0x2509203233732e64\n"
".quad 0x7225202c34343372,0x313135202c333433,0x732e726873090a3b,0x3433722509203233\n"
".quad 0x3434337225202c35,0x6d090a3b3133202c,0x09203233732e766f,0x35202c3634337225\n"
".quad 0x646e61090a3b3131,0x722509203233622e,0x337225202c373433,0x34337225202c3534\n"
".quad 0x2e646461090a3b36,0x3372250920323373,0x34337225202c3834,0x3434337225202c37\n"
".quad 0x732e726873090a3b,0x3433722509203233,0x3834337225202c39,0x7663090a3b39202c\n"
".quad 0x33732e3436732e74,0x3231647225092032,0x0a3b357225202c31,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x7225202c38336472,0x6c090a3b34202c35,0x2e74736e6f632e64\n"
".quad 0x6472250920343675,0x6472255b202c3038,0x090a3b5d38382b34,0x74736e6f632e646c\n"
".quad 0x722509203436752e,0x72255b202c343764,0x0a3b5d30382b3464,0x3436752e64646109\n"
".quad 0x2c31386472250920,0x202c303864722520,0x090a3b3833647225,0x203436752e646461\n"
".quad 0x202c353764722509,0x25202c3437647225,0x6d090a3b38336472,0x09203233732e766f\n"
".quad 0x25202c3035337225,0x4c240a3b39343372,0x323631315f305f74,0x3c2f2f200a3a3632\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x37353720656e696c,0x6e697473656e202c\n"
".quad 0x3a68747065642067,0x69747365202c3120,0x746920646574616d,0x736e6f6974617265\n"
".quad 0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x3009313637093731,0x3233662e646c090a\n"
".quad 0x202c323366250920,0x302b35376472255b,0x662e646c090a3b5d,0x3333662509203233\n"
".quad 0x31386472255b202c,0x7573090a3b5d302b,0x2509203233662e62,0x336625202c343366\n"
".quad 0x3b33336625202c32,0x3233662e7473090a,0x31386472255b0920,0x336625202c5d302b\n"
".quad 0x2e646461090a3b34,0x3172250920323373,0x2c33317225202c33,0x61090a3b32313520\n"
".quad 0x09203436752e6464,0x25202c3537647225,0x3032202c35376472,0x646461090a3b3834\n"
".quad 0x722509203436752e,0x647225202c313864,0x38343032202c3138,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c38367025,0x39317225202c3331,0x36702540090a3b32\n"
".quad 0x2409206172622038,0x3631315f305f744c,0x744c240a3b363232,0x31373531315f305f\n"
".quad 0x636f6c2e090a3a34,0x0933373709373109,0x732e766f6d090a30,0x3331722509203233\n"
".quad 0x090a3b357225202c,0x6220323470252140,0x5f744c2409206172,0x3833373631315f30\n"
".quad 0x732e627573090a3b,0x3533722509203233,0x3230327225202c31,0x090a3b357225202c\n"
".quad 0x203233732e646461,0x202c323533722509,0x35202c3135337225,0x726873090a3b3131\n"
".quad 0x722509203233732e,0x337225202c333533,0x0a3b3133202c3235,0x3233732e766f6d09\n"
".quad 0x2c34353372250920,0x61090a3b31313520,0x09203233622e646e,0x25202c3535337225\n"
".quad 0x7225202c33353372,0x6461090a3b343533,0x2509203233732e64,0x7225202c36353372\n"
".quad 0x337225202c353533,0x726873090a3b3235,0x722509203233732e,0x337225202c373533\n"
".quad 0x090a3b39202c3635,0x203233732e766f6d,0x202c383533722509,0x240a3b3735337225\n"
".quad 0x3731315f305f744c,0x2f2f200a3a303532,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x373720656e696c20,0x697473656e202c33,0x687470656420676e,0x747365202c31203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x0933383709373109,0x732e766f6d090a30,0x3631722509203233,0x3b33317225202c39\n"
".quad 0x33732e646461090a,0x3732327225092032,0x202c33317225202c,0x090a3b3239317225\n"
".quad 0x2e656c2e70746573,0x3670250920323373,0x3732327225202c39,0x0a3b33317225202c\n"
".quad 0x6220393670254009,0x5f744c2409206172,0x3630353731315f30,0x732e747663090a3b\n"
".quad 0x09203233732e3436,0x202c323231647225,0x090a3b3230327225,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x327225202c373864,0x090a3b34202c3230,0x74736e6f632e646c\n"
".quad 0x722509203436752e,0x72255b202c303864,0x0a3b5d38382b3464,0x3436732e74766309\n"
".quad 0x722509203233732e,0x7225202c33323164,0x6c756d090a3b3331,0x33732e656469772e\n"
".quad 0x3231647225092032,0x2c33317225202c34,0x646461090a3b3420,0x722509203436752e\n"
".quad 0x647225202c303964,0x31647225202c3038,0x766f6d090a3b3432,0x662509203233662e\n"
".quad 0x3030306630202c39,0x20203b3030303030,0x30202f2f09202020,0x315f305f744c240a\n"
".quad 0x200a3a3831303831,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x73656e202c333837,0x70656420676e6974,0x65202c32203a6874,0x646574616d697473\n"
".quad 0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e,0x383709373109636f\n"
".quad 0x2e646c090a300934,0x3366250920323366,0x396472255b202c35,0x61090a3b5d302b30\n"
".quad 0x09203233662e6464,0x6625202c36336625,0x3b396625202c3533,0x3233662e7473090a\n"
".quad 0x30396472255b0920,0x336625202c5d302b,0x636f6c2e090a3b36,0x0935383709373109\n"
".quad 0x662e766f6d090a30,0x2c39662509203233,0x090a3b3633662520,0x203233732e646461\n"
".quad 0x202c393631722509,0x25202c3936317225,0x61090a3b32303272,0x09203436752e6464\n"
".quad 0x25202c3039647225,0x7225202c30396472,0x6573090a3b373864,0x33732e74672e7074\n"
".quad 0x2c30377025092032,0x202c373232722520,0x090a3b3936317225,0x7262203037702540\n"
".quad 0x305f744c24092061,0x3b3831303831315f,0x315f305f744c240a,0x090a3a3630353731\n"
".quad 0x203233732e646461,0x25202c3331722509,0x323135202c333172,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c31377025,0x30327225202c3331,0x37702540090a3b32\n"
".quad 0x2409206172622031,0x3731315f305f744c,0x744c240a3b303532,0x33373631315f305f\n"
".quad 0x636f6c2e090a3a38,0x0937393709373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300934303809,0x203233732e766f6d,0x25202c3331722509\n"
".quad 0x252140090a3b3572,0x2061726220363470,0x315f305f744c2409,0x090a3b3638373831\n"
".quad 0x203233732e627573,0x202c393533722509,0x25202c3832327225,0x646461090a3b3572\n"
".quad 0x722509203233732e,0x337225202c303633,0x3b313135202c3935,0x33732e726873090a\n"
".quad 0x3136337225092032,0x2c3036337225202c,0x6f6d090a3b313320,0x2509203233732e76\n"
".quad 0x3135202c32363372,0x2e646e61090a3b31,0x3372250920323362,0x36337225202c3336\n"
".quad 0x3236337225202c31,0x732e646461090a3b,0x3633722509203233,0x3336337225202c34\n"
".quad 0x3b3036337225202c,0x33732e726873090a,0x3536337225092032,0x2c3436337225202c\n"
".quad 0x747663090a3b3920,0x3233732e3436732e,0x3532316472250920,0x090a3b357225202c\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x357225202c383364,0x646c090a3b34202c\n"
".quad 0x752e74736e6f632e,0x3964722509203436,0x346472255b202c32,0x6c090a3b5d36392b\n"
".quad 0x2e74736e6f632e64,0x6472250920343675,0x6472255b202c3038,0x090a3b5d38382b34\n"
".quad 0x203436752e646461,0x202c333964722509,0x25202c3239647225,0x6c090a3b38336472\n"
".quad 0x2e74736e6f632e64,0x3272250920323373,0x635f645b202c3633,0x37332b6e6f6d6d6f\n"
".quad 0x2e646c090a3b5d32,0x33732e74736e6f63,0x3733327225092032,0x6d6f635f645b202c\n"
".quad 0x5d3436332b6e6f6d,0x6f632e646c090a3b,0x203233732e74736e,0x202c383332722509\n"
".quad 0x6f6d6d6f635f645b,0x0a3b5d3834332b6e,0x3233732e766f6d09,0x2c36363372250920\n"
".quad 0x0a3b353633722520,0x31315f305f744c24,0x2f200a3a38393239,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3820656e696c2079,0x7473656e202c3430,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x6f6c2e090a6e776f,0x3830380937310963,0x2e646461090a3009,0x3272250920323373\n"
".quad 0x2c33317225202c35,0x6d6572090a3b3120,0x722509203233732e,0x327225202c373633\n"
".quad 0x3833327225202c35,0x732e627573090a3b,0x3732722509203233,0x2c3736337225202c\n"
".quad 0x6f6c2e090a3b3120,0x3930380937310963,0x2e766964090a3009,0x3272250920323373\n"
".quad 0x2c35327225202c38,0x0a3b383332722520,0x3233752e766f6d09,0x2c38363372250920\n"
".quad 0x746573090a3b3020,0x3233732e656e2e70,0x202c323770250920,0x25202c3736337225\n"
".quad 0x40090a3b38363372,0x6172622032377025,0x5f305f744c240920,0x0a3b343535393131\n"
".quad 0x373109636f6c2e09,0x090a300931313809,0x203233732e627573,0x25202c3732722509\n"
".quad 0x3b31202c38333272,0x3109636f6c2e090a,0x0a30093231380937,0x3233732e62757309\n"
".quad 0x202c383272250920,0x3b31202c38327225,0x315f305f744c240a,0x090a3a3435353931\n"
".quad 0x09373109636f6c2e,0x61090a3009383138,0x09203233732e6464,0x25202c3936337225\n"
".quad 0x327225202c373272,0x646461090a3b3733,0x722509203233732e,0x327225202c303733\n"
".quad 0x3633327225202c38,0x732e627573090a3b,0x3733722509203233,0x3037337225202c31\n"
".quad 0x756d090a3b31202c,0x3233732e6f6c2e6c,0x2c32373372250920,0x202c323032722520\n"
".quad 0x090a3b3137337225,0x203233732e646461,0x202c333733722509,0x25202c3936337225\n"
".quad 0x63090a3b32373372,0x732e3436732e7476,0x3164722509203233,0x37337225202c3632\n"
".quad 0x2e6c756d090a3b33,0x3233732e65646977,0x3732316472250920,0x2c3337337225202c\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x7225202c38323164,0x647225202c303864\n"
".quad 0x646c090a3b373231,0x662509203233662e,0x6472255b202c3733,0x3b5d342d2b383231\n"
".quad 0x3233662e7473090a,0x33396472255b0920,0x336625202c5d302b,0x2e646461090a3b37\n"
".quad 0x3172250920323373,0x2c33317225202c33,0x61090a3b32313520,0x09203436752e6464\n"
".quad 0x25202c3339647225,0x3032202c33396472,0x746573090a3b3834,0x3233732e746c2e70\n"
".quad 0x202c333770250920,0x7225202c33317225,0x2540090a3b383232,0x2061726220333770\n"
".quad 0x315f305f744c2409,0x240a3b3839323931,0x3831315f305f744c,0x6c2e090a3a363837\n"
".quad 0x323809373109636f,0x726162090a300939,0x300920636e79732e,0x09636f6c2e090a3b\n"
".quad 0x3009303438093731,0x33732e766f6d090a,0x2c33317225092032,0x40090a3b35722520\n"
".quad 0x7262203934702521,0x305f744c24092061,0x3b3232333032315f,0x33732e627573090a\n"
".quad 0x3437337225092032,0x2c3734327225202c,0x61090a3b35722520,0x09203233732e6464\n"
".quad 0x25202c3537337225,0x3135202c34373372,0x2e726873090a3b31,0x3372250920323373\n"
".quad 0x37337225202c3637,0x090a3b3133202c35,0x203233732e766f6d,0x202c373733722509\n"
".quad 0x6e61090a3b313135,0x2509203233622e64,0x7225202c38373372,0x337225202c363733\n"
".quad 0x646461090a3b3737,0x722509203233732e,0x337225202c393733,0x37337225202c3837\n"
".quad 0x2e726873090a3b35,0x3372250920323373,0x37337225202c3038,0x63090a3b39202c39\n"
".quad 0x732e3436732e7476,0x3164722509203233,0x3b357225202c3932,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3833647225,0x090a3b34202c3572,0x74736e6f632e646c\n"
".quad 0x722509203436752e,0x255b202c30333164,0x5d3032312b346472,0x6f632e646c090a3b\n"
".quad 0x203436752e74736e,0x202c303864722509,0x38382b346472255b,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x647225202c313331,0x647225202c303331,0x2e646c090a3b3833\n"
".quad 0x33732e74736e6f63,0x3535327225092032,0x6d6f635f645b202c,0x5d3838332b6e6f6d\n"
".quad 0x6f632e646c090a3b,0x203233732e74736e,0x202c363532722509,0x6f6d6d6f635f645b\n"
".quad 0x0a3b5d3038332b6e,0x736e6f632e646c09,0x2509203233732e74,0x645b202c37353272\n"
".quad 0x2b6e6f6d6d6f635f,0x6d090a3b5d363933,0x09203233732e766f,0x25202c3138337225\n"
".quad 0x4c240a3b30383372,0x383032315f305f74,0x3c2f2f200a3a3433,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x30343820656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x09636f6c2e090a6e,0x3009343438093731,0x33732e646461090a,0x2c35327225092032\n"
".quad 0x31202c3331722520,0x732e6d6572090a3b,0x3833722509203233,0x2c35327225202c32\n"
".quad 0x0a3b373532722520,0x3233732e62757309,0x202c373272250920,0x31202c3238337225\n"
".quad 0x09636f6c2e090a3b,0x3009353438093731,0x33732e766964090a,0x2c38327225092032\n"
".quad 0x25202c3532722520,0x6d090a3b37353272,0x09203233752e766f,0x30202c3338337225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x7225202c34377025,0x337225202c323833\n"
".quad 0x702540090a3b3338,0x0920617262203437,0x32315f305f744c24,0x2e090a3b30393031\n"
".quad 0x3809373109636f6c,0x7573090a30093734,0x2509203233732e62,0x327225202c373272\n"
".quad 0x090a3b31202c3735,0x09373109636f6c2e,0x73090a3009383438,0x09203233732e6275\n"
".quad 0x7225202c38327225,0x240a3b31202c3832,0x3132315f305f744c,0x6c2e090a3a303930\n"
".quad 0x353809373109636f,0x646461090a300934,0x722509203233732e,0x327225202c343833\n"
".quad 0x3635327225202c37,0x732e646461090a3b,0x3833722509203233,0x2c38327225202c35\n"
".quad 0x0a3b353532722520,0x3233732e62757309,0x2c36383372250920,0x202c353833722520\n"
".quad 0x2e6c756d090a3b31,0x09203233732e6f6c,0x25202c3738337225,0x7225202c32303272\n"
".quad 0x6461090a3b363833,0x2509203233732e64,0x7225202c38383372,0x337225202c343833\n"
".quad 0x747663090a3b3738,0x3233732e3436732e,0x3233316472250920,0x3b3838337225202c\n"
".quad 0x69772e6c756d090a,0x09203233732e6564,0x202c333331647225,0x34202c3838337225\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x38647225202c3433,0x3331647225202c30\n"
".quad 0x662e646c090a3b33,0x3833662509203233,0x33316472255b202c,0x090a3b5d342d2b34\n"
".quad 0x09203233662e7473,0x2b3133316472255b,0x38336625202c5d30,0x732e646461090a3b\n"
".quad 0x3331722509203233,0x202c33317225202c,0x6461090a3b323135,0x2509203436752e64\n"
".quad 0x25202c3133316472,0x32202c3133316472,0x6573090a3b383430,0x33732e746c2e7074\n"
".quad 0x2c35377025092032,0x25202c3331722520,0x40090a3b37343272,0x6172622035377025\n"
".quad 0x5f305f744c240920,0x0a3b343338303231,0x32315f305f744c24,0x2e090a3a32323330\n"
".quad 0x3809373109636f6c,0x6162090a30093536,0x0920636e79732e72,0x636f6c2e090a3b30\n"
".quad 0x0932373809373109,0x732e766f6d090a30,0x3331722509203233,0x090a3b357225202c\n"
".quad 0x6220393470252140,0x5f744c2409206172,0x3835383132315f30,0x732e627573090a3b\n"
".quad 0x3833722509203233,0x3734327225202c39,0x090a3b357225202c,0x203233732e646461\n"
".quad 0x202c303933722509,0x35202c3938337225,0x726873090a3b3131,0x722509203233732e\n"
".quad 0x337225202c313933,0x0a3b3133202c3039,0x3233732e766f6d09,0x2c32393372250920\n"
".quad 0x61090a3b31313520,0x09203233622e646e,0x25202c3339337225,0x7225202c31393372\n"
".quad 0x6461090a3b323933,0x2509203233732e64,0x7225202c34393372,0x337225202c333933\n"
".quad 0x726873090a3b3039,0x722509203233732e,0x337225202c353933,0x090a3b39202c3439\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x357225202c353331,0x772e6c756d090a3b\n"
".quad 0x203233732e656469,0x202c383364722509,0x0a3b34202c357225,0x736e6f632e646c09\n"
".quad 0x2509203436752e74,0x5b202c3033316472,0x3032312b34647225,0x632e646c090a3b5d\n"
".quad 0x3436752e74736e6f,0x2c32396472250920,0x392b346472255b20,0x646461090a3b5d36\n"
".quad 0x722509203436752e,0x7225202c31333164,0x7225202c30333164,0x6461090a3b383364\n"
".quad 0x2509203436752e64,0x7225202c33396472,0x647225202c323964,0x766f6d090a3b3833\n"
".quad 0x722509203233732e,0x337225202c363933,0x5f744c240a3b3539,0x3037333232315f30\n"
".quad 0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220,0x202c32373820656e\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x373109636f6c2e09,0x090a300936373809\n"
".quad 0x09203233662e646c,0x255b202c39336625,0x3b5d302b33396472,0x3233662e646c090a\n"
".quad 0x202c303466250920,0x2b3133316472255b,0x627573090a3b5d30,0x662509203233662e\n"
".quad 0x39336625202c3134,0x0a3b30346625202c,0x203233662e747309,0x3133316472255b09\n"
".quad 0x346625202c5d302b,0x2e646461090a3b31,0x3172250920323373,0x2c33317225202c33\n"
".quad 0x61090a3b32313520,0x09203436752e6464,0x25202c3339647225,0x3032202c33396472\n"
".quad 0x646461090a3b3834,0x722509203436752e,0x7225202c31333164,0x3032202c31333164\n"
".quad 0x746573090a3b3834,0x3233732e746c2e70,0x202c363770250920,0x7225202c33317225\n"
".quad 0x2540090a3b373432,0x2061726220363770,0x315f305f744c2409,0x240a3b3037333232\n"
".quad 0x3132315f305f744c,0x6c2e090a3a383538,0x383809373109636f,0x726162090a300937\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x3009383938093731,0x33732e766f6d090a\n"
".quad 0x2c33317225092032,0x40090a3b35722520,0x7262203934702521,0x305f744c24092061\n"
".quad 0x3b3238383232315f,0x33732e627573090a,0x3739337225092032,0x2c3734327225202c\n"
".quad 0x61090a3b35722520,0x09203233732e6464,0x25202c3839337225,0x3135202c37393372\n"
".quad 0x2e726873090a3b31,0x3372250920323373,0x39337225202c3939,0x090a3b3133202c38\n"
".quad 0x203233732e766f6d,0x202c303034722509,0x6e61090a3b313135,0x2509203233622e64\n"
".quad 0x7225202c31303472,0x347225202c393933,0x646461090a3b3030,0x722509203233732e\n"
".quad 0x347225202c323034,0x39337225202c3130,0x2e726873090a3b38,0x3472250920323373\n"
".quad 0x30347225202c3330,0x63090a3b39202c32,0x732e3436732e7476,0x3664722509203233\n"
".quad 0x0a3b357225202c33,0x2e6e722e74766309,0x203233732e323366,0x25202c3234662509\n"
".quad 0x756d090a3b343172,0x732e656469772e6c,0x3364722509203233,0x202c357225202c38\n"
".quad 0x632e646c090a3b34,0x3436752e74736e6f,0x3033316472250920,0x2b346472255b202c\n"
".quad 0x6c090a3b5d303231,0x2e74736e6f632e64,0x6472250920343675,0x6472255b202c3839\n"
".quad 0x0a3b5d3430312b34,0x3436752e64646109,0x3133316472250920,0x303331647225202c\n"
".quad 0x3b3833647225202c,0x36752e646461090a,0x3939647225092034,0x2c3839647225202c\n"
".quad 0x0a3b383364722520,0x3233732e766f6d09,0x2c34303472250920,0x0a3b333034722520\n"
".quad 0x32315f305f744c24,0x2f200a3a34393333,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3820656e696c2079,0x7473656e202c3839,0x7470656420676e69,0x7365202c31203a68\n"
".quad 0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f\n"
".quad 0x3130390937310963,0x662e646c090a3009,0x3432662509203233,0x39396472255b202c\n"
".quad 0x6c2e090a3b5d302b,0x303909373109636f,0x2e646c090a300932,0x3466250920323366\n"
".quad 0x316472255b202c33,0x090a3b5d302b3133,0x203233662e6c756d,0x25202c3434662509\n"
".quad 0x326625202c343266,0x2e766964090a3b34,0x09203233662e6e72,0x6625202c35346625\n"
".quad 0x32346625202c3434,0x662e627573090a3b,0x3634662509203233,0x202c33346625202c\n"
".quad 0x2e090a3b35346625,0x3909373109636f6c,0x6f6d090a30093630,0x2509203233662e76\n"
".quad 0x306630202c373466,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3834662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x2e746c2e70746573,0x3770250920323366,0x2c36346625202c37,0x090a3b3834662520\n"
".quad 0x3233662e706c6573,0x202c393466250920,0x6625202c37346625,0x37377025202c3634\n"
".quad 0x2e74727173090a3b,0x09203233662e6e72,0x6625202c30356625,0x2e7473090a3b3934\n"
".quad 0x72255b0920323366,0x2c5d302b31333164,0x090a3b3035662520,0x203233732e646461\n"
".quad 0x25202c3331722509,0x323135202c333172,0x752e646461090a3b,0x3964722509203436\n"
".quad 0x3939647225202c39,0x0a3b38343032202c,0x3436752e64646109,0x3133316472250920\n"
".quad 0x313331647225202c,0x0a3b38343032202c,0x746c2e7074657309,0x702509203233732e\n"
".quad 0x33317225202c3837,0x3b3734327225202c,0x203837702540090a,0x744c240920617262\n"
".quad 0x39333332315f305f,0x305f744c240a3b34,0x3a3238383232315f,0x3109636f6c2e090a\n"
".quad 0x0a30093831390937,0x6e79732e72616209,0x2e090a3b30092063,0x3909373109636f6c\n"
".quad 0x6f6d090a30093532,0x2509203233732e76,0x357225202c333172,0x6f632e646c090a3b\n"
".quad 0x203233732e74736e,0x202c353034722509,0x6f6d6d6f635f645b,0x0a3b5d3235342b6e\n"
".quad 0x65672e7074657309,0x702509203233732e,0x2c357225202c3937,0x0a3b353034722520\n"
".quad 0x6220393770254009,0x5f744c2409206172,0x3630393332315f30,0x732e627573090a3b\n"
".quad 0x3034722509203233,0x3530347225202c36,0x090a3b357225202c,0x203233732e646461\n"
".quad 0x202c373034722509,0x35202c3630347225,0x726873090a3b3131,0x722509203233732e\n"
".quad 0x347225202c383034,0x0a3b3133202c3730,0x3233732e766f6d09,0x2c39303472250920\n"
".quad 0x61090a3b31313520,0x09203233622e646e,0x25202c3031347225,0x7225202c38303472\n"
".quad 0x6461090a3b393034,0x2509203233732e64,0x7225202c31313472,0x347225202c303134\n"
".quad 0x726873090a3b3730,0x722509203233732e,0x347225202c323134,0x090a3b39202c3131\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x357225202c363331,0x772e6c756d090a3b\n"
".quad 0x203233732e656469,0x202c383364722509,0x0a3b34202c357225,0x3436752e64646109\n"
".quad 0x3733316472250920,0x2c3833647225202c,0x090a3b3864722520,0x74736e6f632e646c\n"
".quad 0x722509203436752e,0x255b202c38333164,0x5d3832312b346472,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x31647225202c3933,0x33647225202c3833,0x2e766f6d090a3b38\n"
".quad 0x3472250920323373,0x31347225202c3331,0x305f744c240a3b32,0x3a3831343432315f\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3532392065\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09373109636f6c2e,0x6c090a3009383239\n"
".quad 0x2509203233662e64,0x72255b202c343266,0x3b5d302b37333164,0x3109636f6c2e090a\n"
".quad 0x0a30093932390937,0x3233662e6c756d09,0x202c313566250920,0x6625202c34326625\n"
".quad 0x2e7473090a3b3432,0x72255b0920323366,0x2c5d302b39333164,0x090a3b3135662520\n"
".quad 0x203233732e646461,0x25202c3331722509,0x323135202c333172,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x31647225202c3933,0x38343032202c3933,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x31647225202c3733,0x38343032202c3733,0x2e70746573090a3b\n"
".quad 0x09203233732e746c,0x7225202c30387025,0x30347225202c3331,0x38702540090a3b35\n"
".quad 0x2409206172622030,0x3432315f305f744c,0x744c240a3b383134,0x30393332315f305f\n"
".quad 0x636f6c2e090a3a36,0x0930343909373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x373109636f6c2e09,0x090a300937343909,0x203233732e766f6d,0x25202c3331722509\n"
".quad 0x746573090a3b3572,0x3233732e65672e70,0x202c313870250920,0x397225202c357225\n"
".quad 0x38702540090a3b30,0x2409206172622031,0x3432315f305f744c,0x7663090a3b303339\n"
".quad 0x65726168732e6174,0x2509203436752e64,0x5f202c3034316472,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x345f7261765f6c61,0x5f32335f30373434,0x736e6f635f6e6f6e\n"
".quad 0x7261705f6e695f74,0x6d75735f6c616974,0x090a3b3030313931,0x203233732e627573\n"
".quad 0x202c343134722509,0x7225202c30397225,0x2e646461090a3b35,0x3472250920323373\n"
".quad 0x31347225202c3531,0x0a3b313135202c34,0x3233732e72687309,0x2c36313472250920\n"
".quad 0x202c353134722520,0x766f6d090a3b3133,0x722509203233732e,0x313135202c373134\n"
".quad 0x622e646e61090a3b,0x3134722509203233,0x3631347225202c38,0x3b3731347225202c\n"
".quad 0x33732e646461090a,0x3931347225092032,0x2c3831347225202c,0x0a3b353134722520\n"
".quad 0x3233732e72687309,0x2c30323472250920,0x202c393134722520,0x2e747663090a3b39\n"
".quad 0x203233732e343673,0x202c333664722509,0x646c090a3b357225,0x732e74736e6f632e\n"
".quad 0x3332722509203233,0x6d6f635f645b202c,0x5d3430322b6e6f6d,0x732e766f6d090a3b\n"
".quad 0x3234722509203233,0x73090a3b30202c31,0x732e74672e707465,0x3238702509203233\n"
".quad 0x202c33327225202c,0x090a3b3132347225,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x7225202c31343164,0x61090a3b34202c35,0x09203436752e6464,0x202c323431647225\n"
".quad 0x202c303431647225,0x0a3b313431647225,0x3233732e766f6d09,0x2c32323472250920\n"
".quad 0x0a3b303234722520,0x32315f305f744c24,0x2f200a3a32343435,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3920656e696c2079,0x7473656e202c3734,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x252140090a6e776f,0x2061726220323870,0x315f305f744c2409,0x090a3b3839363735\n"
".quad 0x203233732e766f6d,0x202c333234722509,0x6d090a3b33327225,0x33732e6f6c2e6c75\n"
".quad 0x3432347225092032,0x202c33317225202c,0x6d090a3b33327225,0x09203233732e766f\n"
".quad 0x25202c3532347225,0x61090a3b34323472,0x09203233732e6464,0x25202c3632347225\n"
".quad 0x7225202c34323472,0x747663090a3b3332,0x3233732e3436732e,0x3334316472250920\n"
".quad 0x3b3432347225202c,0x69772e6c756d090a,0x09203233732e6564,0x202c343431647225\n"
".quad 0x34202c3432347225,0x752e646461090a3b,0x3164722509203436,0x38647225202c3534\n"
".quad 0x343431647225202c,0x662e766f6d090a3b,0x2c39662509203233,0x3030303030663020\n"
".quad 0x202020203b303030,0x090a30202f2f0920,0x203233732e766f6d,0x202c373234722509\n"
".quad 0x240a3b3332347225,0x3632315f305f744c,0x2f2f200a3a303132,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x343920656e696c20,0x697473656e202c37,0x687470656420676e\n"
".quad 0x747365202c32203a,0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73\n"
".quad 0x636f6c2e090a6e77,0x0933353909373109,0x33662e646c090a30,0x2c32356625092032\n"
".quad 0x3534316472255b20,0x6461090a3b5d302b,0x2509203233662e64,0x32356625202c3966\n"
".quad 0x090a3b396625202c,0x203233732e646461,0x202c353234722509,0x31202c3532347225\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3534,0x090a3b34202c3534\n"
".quad 0x2e656e2e70746573,0x3870250920323373,0x3532347225202c33,0x3b3632347225202c\n"
".quad 0x203338702540090a,0x744c240920617262,0x31323632315f305f,0x2e617262090a3b30\n"
".quad 0x744c240920696e75,0x39363532315f305f,0x305f744c240a3b38,0x3a3839363735315f\n"
".quad 0x33662e766f6d090a,0x202c396625092032,0x3030303030306630,0x20202020203b3030\n"
".quad 0x4c240a30202f2f09,0x363532315f305f74,0x6f6c2e090a3a3839,0x3635390937310963\n"
".quad 0x662e7473090a3009,0x6472255b09203233,0x202c5d302b323431,0x6461090a3b396625\n"
".quad 0x2509203233732e64,0x317225202c333172,0x0a3b323135202c33,0x3436752e64646109\n"
".quad 0x3234316472250920,0x323431647225202c,0x0a3b38343032202c,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x33317225202c3438,0x0a3b30397225202c,0x6220343870254009\n"
".quad 0x5f744c2409206172,0x3234343532315f30,0x5f305f744c240a3b,0x0a3a303339343231\n"
".quad 0x68732e6174766309,0x3436752e64657261,0x3034316472250920,0x616475635f5f202c\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f30373434345f72,0x635f6e6f6e5f3233\n"
".quad 0x5f6e695f74736e6f,0x5f6c616974726170,0x30303139316d7573,0x09636f6c2e090a3b\n"
".quad 0x3009373639093731,0x79732e726162090a,0x090a3b300920636e,0x09373109636f6c2e\n"
".quad 0x6d090a3009333739,0x09203233732e766f,0x7225202c33317225,0x632e646c090a3b35\n"
".quad 0x3233732e74736e6f,0x2c38323472250920,0x6d6d6f635f645b20,0x3b5d3434342b6e6f\n"
".quad 0x672e70746573090a,0x2509203233732e65,0x357225202c353870,0x3b3832347225202c\n"
".quad 0x203538702540090a,0x744c240920617262,0x37393632315f305f,0x61747663090a3b38\n"
".quad 0x2e6465726168732e,0x6472250920343675,0x635f5f202c363431,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3434345f7261765f,0x6f6e5f32335f3137,0x5f74736e6f635f6e\n"
".quad 0x705f7271735f6e69,0x735f6c6169747261,0x3b34303339316d75,0x33732e627573090a\n"
".quad 0x3932347225092032,0x2c3832347225202c,0x61090a3b35722520,0x09203233732e6464\n"
".quad 0x25202c3033347225,0x3135202c39323472,0x2e726873090a3b31,0x3472250920323373\n"
".quad 0x33347225202c3133,0x090a3b3133202c30,0x203233732e766f6d,0x202c323334722509\n"
".quad 0x6e61090a3b313135,0x2509203233622e64,0x7225202c33333472,0x347225202c313334\n"
".quad 0x646461090a3b3233,0x722509203233732e,0x347225202c343334,0x33347225202c3333\n"
".quad 0x2e726873090a3b30,0x3472250920323373,0x33347225202c3533,0x63090a3b39202c34\n"
".quad 0x732e3436732e7476,0x3664722509203233,0x0a3b357225202c33,0x3436732e766f6d09\n"
".quad 0x3734316472250920,0x3b3336647225202c,0x6e6f632e646c090a,0x09203233732e7473\n"
".quad 0x5b202c3633347225,0x6e6f6d6d6f635f64,0x090a3b5d3834342b,0x203233732e766f6d\n"
".quad 0x202c373334722509,0x70746573090a3b30,0x203233732e74672e,0x25202c3638702509\n"
".quad 0x7225202c36333472,0x756d090a3b373334,0x732e656469772e6c,0x3164722509203233\n"
".quad 0x2c357225202c3834,0x646461090a3b3420,0x722509203436752e,0x7225202c39343164\n"
".quad 0x7225202c36343164,0x6d090a3b38343164,0x09203233732e766f,0x25202c3833347225\n"
".quad 0x4c240a3b35333472,0x343732315f305f74,0x3c2f2f200a3a3039,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x33373920656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x3870252140090a6e,0x2409206172622036,0x3835315f305f744c,0x6f6d090a3b303132\n"
".quad 0x2509203233732e76,0x7225202c39333472,0x6f6d090a3b363334,0x2509203436732e76\n"
".quad 0x25202c3035316472,0x090a3b3734316472,0x74736e6f632e646c,0x722509203436752e\n"
".quad 0x255b202c31353164,0x5d3832312b346472,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x202c323531647225,0x090a3b3832347225,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x7225202c33353164,0x0a3b34202c383234,0x2e6f6c2e6c756d09,0x6472250920343675\n"
".quad 0x647225202c343531,0x0a3b34202c303531,0x3436752e64646109,0x3535316472250920\n"
".quad 0x313531647225202c,0x343531647225202c,0x662e766f6d090a3b,0x2c39662509203233\n"
".quad 0x3030303030663020,0x202020203b303030,0x090a30202f2f0920,0x203233732e766f6d\n"
".quad 0x202c303434722509,0x2e766f6d090a3b30,0x3472250920323373,0x33347225202c3134\n"
".quad 0x305f744c240a3b39,0x3a3835323832315f,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x6e202c3337392065,0x6420676e69747365,0x2c32203a68747065\n"
".quad 0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e\n"
".quad 0x09373109636f6c2e,0x6c090a3009393739,0x2509203233662e64,0x72255b202c333566\n"
".quad 0x3b5d302b35353164,0x33662e646461090a,0x202c396625092032,0x6625202c33356625\n"
".quad 0x2e646461090a3b39,0x3472250920323373,0x34347225202c3034,0x61090a3b31202c30\n"
".quad 0x09203436752e6464,0x202c353531647225,0x202c333531647225,0x0a3b353531647225\n"
".quad 0x656e2e7074657309,0x702509203233732e,0x33347225202c3738,0x3034347225202c36\n"
".quad 0x3738702540090a3b,0x4c24092061726220,0x323832315f305f74,0x617262090a3b3835\n"
".quad 0x4c240920696e752e,0x373732315f305f74,0x5f744c240a3b3634,0x3031323835315f30\n"
".quad 0x662e766f6d090a3a,0x2c39662509203233,0x3030303030663020,0x202020203b303030\n"
".quad 0x240a30202f2f0920,0x3732315f305f744c,0x6c2e090a3a363437,0x383909373109636f\n"
".quad 0x2e7473090a300932,0x72255b0920323366,0x2c5d302b39343164,0x61090a3b39662520\n"
".quad 0x09203233732e6464,0x7225202c33317225,0x3b323135202c3331,0x36732e646461090a\n"
".quad 0x3431647225092034,0x3431647225202c37,0x0a3b323135202c37,0x3436752e64646109\n"
".quad 0x3934316472250920,0x393431647225202c,0x0a3b38343032202c,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x33317225202c3838,0x3b3832347225202c,0x203838702540090a\n"
".quad 0x744c240920617262,0x39343732315f305f,0x305f744c240a3b30,0x3a3837393632315f\n"
".quad 0x732e61747663090a,0x36752e6465726168,0x3431647225092034,0x6475635f5f202c36\n"
".quad 0x616475635f5f5f61,0x765f6c61636f6c5f,0x31373434345f7261,0x5f6e6f6e5f32335f\n"
".quad 0x6e695f74736e6f63,0x7261705f7271735f,0x6d75735f6c616974,0x090a3b3430333931\n"
".quad 0x09373109636f6c2e,0x62090a3009333939,0x20636e79732e7261,0x766f6d090a3b3009\n"
".quad 0x722509203233732e,0x0a3b30202c323434,0x71652e7074657309,0x702509203233732e\n"
".quad 0x2c357225202c3938,0x0a3b323434722520,0x2039387025214009,0x744c240920617262\n"
".quad 0x38323932315f305f,0x636f6c2e090a3b32,0x3130303109373109,0x2e766f6d090a3009\n"
".quad 0x3566250920323366,0x3030306630202c34,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233752e766f6d09,0x2c33343472250920,0x746573090a3b3020,0x3233732e656c2e70\n"
".quad 0x202c303970250920,0x7225202c30397225,0x2540090a3b333434,0x2061726220303970\n"
".quad 0x315f305f744c2409,0x090a3b3636343835,0x203233732e766f6d,0x202c343434722509\n"
".quad 0x6d090a3b30397225,0x09203436732e766f,0x202c363531647225,0x0a3b303431647225\n"
".quad 0x3233732e766f6d09,0x2c30343472250920,0x766f6d090a3b3020,0x722509203233732e\n"
".quad 0x347225202c353434,0x5f744c240a3b3434,0x3035303033315f30,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x2c3130303120656e,0x676e697473656e20\n"
".quad 0x203a687470656420,0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172\n"
".quad 0x6e776f6e6b6e7520,0x3109636f6c2e090a,0x3009333030310937,0x3233662e646c090a\n"
".quad 0x202c353566250920,0x2b3635316472255b,0x646461090a3b5d30,0x662509203233662e\n"
".quad 0x35356625202c3435,0x0a3b34356625202c,0x3233732e64646109,0x2c30343472250920\n"
".quad 0x202c303434722520,0x2e646461090a3b31,0x6472250920343675,0x647225202c363531\n"
".quad 0x0a3b34202c363531,0x656e2e7074657309,0x702509203233732e,0x34347225202c3139\n"
".quad 0x3b30397225202c30,0x203139702540090a,0x744c240920617262,0x35303033315f305f\n"
".quad 0x732e7473090a3b30,0x33662e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164\n"
".quad 0x3434345f7261765f,0x6f6e5f32335f3237,0x5f74736e6f635f6e,0x6c616e69665f6e69\n"
".quad 0x25202c5d6d75735f,0x7262090a3b343566,0x240920696e752e61,0x3133315f305f744c\n"
".quad 0x744c240a3b343730,0x36343835315f305f,0x732e7473090a3a36,0x33662e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3434345f7261765f,0x6f6e5f32335f3237\n"
".quad 0x5f74736e6f635f6e,0x6c616e69665f6e69,0x25202c5d6d75735f,0x7262090a3b343566\n"
".quad 0x240920696e752e61,0x3133315f305f744c,0x744c240a3b343730,0x38323932315f305f\n"
".quad 0x2e766f6d090a3a32,0x3472250920323375,0x090a3b31202c3634,0x2e656e2e70746573\n"
".quad 0x3970250920323373,0x202c357225202c32,0x090a3b3634347225,0x7262203239702540\n"
".quad 0x305f744c24092061,0x3b3437303133315f,0x3109636f6c2e090a,0x3009383030310937\n"
".quad 0x33662e766f6d090a,0x2c36356625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6c090a30202f2f09,0x2e74736e6f632e64,0x3472250920323373,0x635f645b202c3633\n"
".quad 0x34342b6e6f6d6d6f,0x766f6d090a3b5d38,0x722509203233752e,0x0a3b30202c373434\n"
".quad 0x656c2e7074657309,0x702509203233732e,0x33347225202c3339,0x3734347225202c36\n"
".quad 0x3339702540090a3b,0x4c24092061726220,0x373835315f305f74,0x766f6d090a3b3232\n"
".quad 0x722509203233732e,0x347225202c383434,0x766f6d090a3b3633,0x722509203436732e\n"
".quad 0x7225202c37353164,0x6d090a3b36343164,0x09203233732e766f,0x30202c3034347225\n"
".quad 0x732e766f6d090a3b,0x3434722509203233,0x3834347225202c39,0x5f305f744c240a3b\n"
".quad 0x0a3a363835313331,0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f\n"
".quad 0x6e202c3830303120,0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x09373109636f6c2e\n"
".quad 0x090a300930313031,0x09203233662e646c,0x255b202c37356625,0x5d302b3735316472\n"
".quad 0x662e646461090a3b,0x3635662509203233,0x202c37356625202c,0x61090a3b36356625\n"
".quad 0x09203233732e6464,0x25202c3034347225,0x3b31202c30343472,0x36752e646461090a\n"
".quad 0x3531647225092034,0x3531647225202c37,0x73090a3b34202c37,0x732e656e2e707465\n"
".quad 0x3439702509203233,0x2c3633347225202c,0x0a3b303434722520,0x6220343970254009\n"
".quad 0x5f744c2409206172,0x3638353133315f30,0x68732e7473090a3b,0x3233662e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x373434345f726176,0x6e6f6e5f32335f33\n"
".quad 0x695f74736e6f635f,0x69665f7271735f6e,0x5d6d75735f6c616e,0x0a3b36356625202c\n"
".quad 0x696e752e61726209,0x5f305f744c240920,0x0a3b343730313331,0x35315f305f744c24\n"
".quad 0x73090a3a32323738,0x6465726168732e74,0x5f5b09203233662e,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x32335f3337343434,0x6e6f635f6e6f6e5f,0x71735f6e695f7473\n"
".quad 0x5f6c616e69665f72,0x6625202c5d6d7573,0x5f744c240a3b3635,0x3437303133315f30\n"
".quad 0x5f305f744c240a3a,0x0a3a323635303331,0x32315f305f744c24,0x2e090a3a36323039\n"
".quad 0x3109373109636f6c,0x62090a3009393130,0x20636e79732e7261,0x252140090a3b3009\n"
".quad 0x2061726220393870,0x315f305f744c2409,0x090a3b3839303233,0x09373109636f6c2e\n"
".quad 0x090a300932333031,0x662e6e722e747663,0x09203233732e3233,0x7225202c32346625\n"
".quad 0x2e646c090a3b3431,0x662e646572616873,0x3835662509203233,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x373434345f726176,0x6e6f6e5f32335f32,0x695f74736e6f635f\n"
".quad 0x5f6c616e69665f6e,0x64090a3b5d6d7573,0x33662e6e722e7669,0x2c39356625092032\n"
".quad 0x25202c3835662520,0x7573090a3b323466,0x2509203233732e62,0x7225202c30353472\n"
".quad 0x090a3b31202c3431,0x662e6e722e747663,0x09203233732e3233,0x7225202c30366625\n"
".quad 0x7173090a3b303534,0x33662e6e722e7472,0x2c31366625092032,0x090a3b3036662520\n"
".quad 0x65726168732e646c,0x2509203233662e64,0x5f5f5b202c323666,0x636f6c5f61647563\n"
".quad 0x345f7261765f6c61,0x5f32335f33373434,0x736e6f635f6e6f6e,0x7271735f6e695f74\n"
".quad 0x735f6c616e69665f,0x6964090a3b5d6d75,0x3233662e6e722e76,0x202c333666250920\n"
".quad 0x6625202c32366625,0x6c756d090a3b3234,0x662509203233662e,0x39356625202c3436\n"
".quad 0x0a3b39356625202c,0x3233662e62757309,0x202c353666250920,0x6625202c33366625\n"
".quad 0x727173090a3b3436,0x3233662e6e722e74,0x202c363666250920,0x6d090a3b35366625\n"
".quad 0x09203233662e6c75,0x6625202c37366625,0x36366625202c3136,0x68732e7473090a3b\n"
".quad 0x3233662e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x373434345f726176\n"
".quad 0x6e6f6e5f32335f38,0x645f74736e6f635f,0x202c5d546d6f6e65,0x4c240a3b37366625\n"
".quad 0x303233315f305f74,0x6f6c2e090a3a3839,0x3430310937310963,0x726162090a300930\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x0937343031093731,0x732e766f6d090a30\n"
".quad 0x3331722509203233,0x090a3b357225202c,0x6220393470252140,0x5f744c2409206172\n"
".quad 0x3031363233315f30,0x732e627573090a3b,0x3534722509203233,0x3734327225202c31\n"
".quad 0x090a3b357225202c,0x203233732e646461,0x202c323534722509,0x35202c3135347225\n"
".quad 0x726873090a3b3131,0x722509203233732e,0x347225202c333534,0x0a3b3133202c3235\n"
".quad 0x3233732e766f6d09,0x2c34353472250920,0x61090a3b31313520,0x09203233622e646e\n"
".quad 0x25202c3535347225,0x7225202c33353472,0x6461090a3b343534,0x2509203233732e64\n"
".quad 0x7225202c36353472,0x347225202c353534,0x726873090a3b3235,0x722509203233732e\n"
".quad 0x347225202c373534,0x090a3b39202c3635,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x357225202c383531,0x772e6c756d090a3b,0x203233732e656469,0x202c383364722509\n"
".quad 0x0a3b34202c357225,0x736e6f632e646c09,0x2509203436752e74,0x5b202c3033316472\n"
".quad 0x3032312b34647225,0x2e646461090a3b5d,0x6472250920343675,0x647225202c313331\n"
".quad 0x647225202c303331,0x2e646c090a3b3833,0x662e646572616873,0x3836662509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x373434345f726176,0x6e6f6e5f32335f38\n"
".quad 0x645f74736e6f635f,0x0a3b5d546d6f6e65,0x3233732e766f6d09,0x2c38353472250920\n"
".quad 0x0a3b373534722520,0x33315f305f744c24,0x2f200a3a32323133,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3120656e696c2079,0x73656e202c373430,0x70656420676e6974\n"
".quad 0x65202c31203a6874,0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f\n"
".quad 0x6c2e090a6e776f6e,0x303109373109636f,0x646c090a30093035,0x662509203233662e\n"
".quad 0x6472255b202c3936,0x0a3b5d302b313331,0x3233662e6c756d09,0x202c303766250920\n"
".quad 0x6625202c39366625,0x2e7473090a3b3836,0x72255b0920323366,0x2c5d302b31333164\n"
".quad 0x090a3b3037662520,0x203233732e646461,0x25202c3331722509,0x323135202c333172\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3133,0x38343032202c3133\n"
".quad 0x2e70746573090a3b,0x09203233732e746c,0x7225202c35397025,0x34327225202c3331\n"
".quad 0x39702540090a3b37,0x2409206172622035,0x3333315f305f744c,0x744c240a3b323231\n"
".quad 0x31363233315f305f,0x636f6c2e090a3a30,0x3136303109373109,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x3109636f6c2e090a,0x3009383630310937,0x33732e766f6d090a\n"
".quad 0x2c33317225092032,0x40090a3b35722520,0x7262203331702521,0x305f744c24092061\n"
".quad 0x3b3433363333315f,0x33732e627573090a,0x3935347225092032,0x202c39377225202c\n"
".quad 0x6461090a3b357225,0x2509203233732e64,0x7225202c30363472,0x313135202c393534\n"
".quad 0x732e726873090a3b,0x3634722509203233,0x3036347225202c31,0x6d090a3b3133202c\n"
".quad 0x09203233732e766f,0x35202c3236347225,0x646e61090a3b3131,0x722509203233622e\n"
".quad 0x347225202c333634,0x36347225202c3136,0x2e646461090a3b32,0x3472250920323373\n"
".quad 0x36347225202c3436,0x3036347225202c33,0x732e726873090a3b,0x3634722509203233\n"
".quad 0x3436347225202c35,0x7663090a3b39202c,0x33732e3436732e74,0x3336647225092032\n"
".quad 0x090a3b357225202c,0x662e6e722e747663,0x09203233732e3233,0x7225202c32346625\n"
".quad 0x6c756d090a3b3431,0x33732e656469772e,0x3833647225092032,0x34202c357225202c\n"
".quad 0x6f632e646c090a3b,0x203436752e74736e,0x202c353564722509,0x36352b346472255b\n"
".quad 0x632e646c090a3b5d,0x3436752e74736e6f,0x2c38396472250920,0x312b346472255b20\n"
".quad 0x6461090a3b5d3430,0x2509203436752e64,0x7225202c36356472,0x647225202c353564\n"
".quad 0x646461090a3b3833,0x722509203436752e,0x647225202c393964,0x33647225202c3839\n"
".quad 0x732e646c090a3b38,0x33662e6465726168,0x2c34356625092032,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x32373434345f7261,0x5f6e6f6e5f32335f,0x6e695f74736e6f63\n"
".quad 0x735f6c616e69665f,0x6f6d090a3b5d6d75,0x2509203233732e76,0x7225202c36363472\n"
".quad 0x744c240a3b353634,0x34313433315f305f,0x6c3c2f2f200a3a36,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x3836303120656e69,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x09636f6c2e090a6e,0x0931373031093731,0x33662e646c090a30,0x2c31376625092032\n"
".quad 0x2b36356472255b20,0x2e646c090a3b5d30,0x3766250920323366,0x396472255b202c32\n"
".quad 0x6d090a3b5d302b39,0x09203233662e6c75,0x6625202c33376625,0x34356625202c3237\n"
".quad 0x722e766964090a3b,0x2509203233662e6e,0x376625202c343766,0x3b32346625202c33\n"
".quad 0x33662e627573090a,0x2c35376625092032,0x25202c3137662520,0x7473090a3b343766\n"
".quad 0x255b09203233662e,0x2c5d302b36356472,0x090a3b3537662520,0x203233732e646461\n"
".quad 0x25202c3331722509,0x323135202c333172,0x752e646461090a3b,0x3964722509203436\n"
".quad 0x3939647225202c39,0x0a3b38343032202c,0x3436752e64646109,0x2c36356472250920\n"
".quad 0x202c363564722520,0x73090a3b38343032,0x732e746c2e707465,0x3639702509203233\n"
".quad 0x202c33317225202c,0x40090a3b39377225,0x6172622036397025,0x5f305f744c240920\n"
".quad 0x0a3b363431343331,0x33315f305f744c24,0x2e090a3a34333633,0x3109373109636f6c\n"
".quad 0x62090a3009323830,0x20636e79732e7261,0x6f6c2e090a3b3009,0x3830310937310963\n"
".quad 0x766f6d090a300939,0x722509203233732e,0x3b357225202c3331,0x393470252140090a\n"
".quad 0x4c24092061726220,0x363433315f305f74,0x627573090a3b3835,0x722509203233732e\n"
".quad 0x327225202c373634,0x3b357225202c3734,0x33732e646461090a,0x3836347225092032\n"
".quad 0x2c3736347225202c,0x73090a3b31313520,0x09203233732e7268,0x25202c3936347225\n"
".quad 0x3133202c38363472,0x732e766f6d090a3b,0x3734722509203233,0x0a3b313135202c30\n"
".quad 0x3233622e646e6109,0x2c31373472250920,0x202c393634722520,0x090a3b3037347225\n"
".quad 0x203233732e646461,0x202c323734722509,0x25202c3137347225,0x73090a3b38363472\n"
".quad 0x09203233732e7268,0x25202c3337347225,0x3b39202c32373472,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x25202c3935316472,0x6c756d090a3b3572,0x33732e656469772e\n"
".quad 0x3833647225092032,0x34202c357225202c,0x6f632e646c090a3b,0x203436752e74736e\n"
".quad 0x2c30333164722509,0x312b346472255b20,0x646c090a3b5d3032,0x752e74736e6f632e\n"
".quad 0x3564722509203436,0x346472255b202c35,0x61090a3b5d36352b,0x09203436752e6464\n"
".quad 0x202c313331647225,0x202c303331647225,0x090a3b3833647225,0x203436752e646461\n"
".quad 0x202c363564722509,0x25202c3535647225,0x6d090a3b38336472,0x09203233732e766f\n"
".quad 0x25202c3437347225,0x4c240a3b33373472,0x313533315f305f74,0x3c2f2f200a3a3037\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x38303120656e696c,0x697473656e202c39\n"
".quad 0x687470656420676e,0x747365202c31203a,0x6920646574616d69,0x6e6f697461726574\n"
".quad 0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x3239303109373109,0x662e646c090a3009\n"
".quad 0x3637662509203233,0x36356472255b202c,0x646c090a3b5d302b,0x662509203233662e\n"
".quad 0x6472255b202c3737,0x0a3b5d302b313331,0x2e6e722e76696409,0x3766250920323366\n"
".quad 0x2c36376625202c38,0x090a3b3737662520,0x09203233662e7473,0x2b3133316472255b\n"
".quad 0x38376625202c5d30,0x732e646461090a3b,0x3331722509203233,0x202c33317225202c\n"
".quad 0x6461090a3b323135,0x2509203436752e64,0x7225202c36356472,0x343032202c363564\n"
".quad 0x2e646461090a3b38,0x6472250920343675,0x647225202c313331,0x343032202c313331\n"
".quad 0x70746573090a3b38,0x203233732e746c2e,0x25202c3739702509,0x327225202c333172\n"
".quad 0x702540090a3b3734,0x0920617262203739,0x33315f305f744c24,0x4c240a3b30373135\n"
".quad 0x363433315f305f74,0x6f6c2e090a3a3835,0x3031310937310963,0x726162090a300933\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x0936313131093731,0x6f632e646c090a30\n"
".quad 0x203233732e74736e,0x202c353734722509,0x6f6d6d6f635f645b,0x61090a3b5d342b6e\n"
".quad 0x09203233732e6464,0x25202c3637347225,0x7225202c35373472,0x2e646c090a3b3234\n"
".quad 0x36752e74736e6f63,0x3631647225092034,0x346472255b202c30,0x6c090a3b5d36312b\n"
".quad 0x2e74736e6f632e64,0x3472250920323373,0x635f645b202c3737,0x36312b6e6f6d6d6f\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x25202c3837347225,0x7225202c37373472\n"
".quad 0x2e646461090a3b37,0x3472250920323373,0x2c317225202c3937,0x0a3b383734722520\n"
".quad 0x3436732e74766309,0x722509203233732e,0x7225202c31363164,0x756d090a3b393734\n"
".quad 0x732e656469772e6c,0x3164722509203233,0x3937347225202c33,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x25202c3236316472,0x25202c3036316472,0x6c090a3b33316472\n"
".quad 0x2509203233732e64,0x255b202c30383472,0x342d2b3236316472,0x2e646461090a3b5d\n"
".quad 0x3472250920323373,0x38347225202c3138,0x3637347225202c30,0x33732e646c090a3b\n"
".quad 0x3238347225092032,0x35326472255b202c,0x7573090a3b5d302b,0x2509203233732e62\n"
".quad 0x7225202c33383472,0x347225202c313834,0x6f6c2e090a3b3238,0x3131310937310963\n"
".quad 0x2e646c090a300937,0x36752e74736e6f63,0x3631647225092034,0x346472255b202c33\n"
".quad 0x61090a3b5d34322b,0x09203436752e6464,0x202c343631647225,0x202c333631647225\n"
".quad 0x090a3b3331647225,0x09203233732e646c,0x5b202c3438347225,0x2d2b343631647225\n"
".quad 0x646461090a3b5d34,0x722509203233732e,0x347225202c353834,0x37347225202c3438\n"
".quad 0x732e646c090a3b36,0x3834722509203233,0x326472255b202c36,0x73090a3b5d302b36\n"
".quad 0x09203233732e6275,0x25202c3738347225,0x7225202c35383472,0x6c2e090a3b363834\n"
".quad 0x313109373109636f,0x6f6d090a30093232,0x2509203233732e76,0x357225202c333172\n"
".quad 0x6f632e646c090a3b,0x203233732e74736e,0x202c383834722509,0x6f6d6d6f635f645b\n"
".quad 0x0a3b5d3836342b6e,0x65672e7074657309,0x702509203233732e,0x2c357225202c3839\n"
".quad 0x0a3b383834722520,0x6220383970254009,0x5f744c2409206172,0x3238363533315f30\n"
".quad 0x732e627573090a3b,0x3834722509203233,0x3838347225202c39,0x090a3b357225202c\n"
".quad 0x203233732e646461,0x202c303934722509,0x35202c3938347225,0x726873090a3b3131\n"
".quad 0x722509203233732e,0x347225202c313934,0x0a3b3133202c3039,0x3233732e766f6d09\n"
".quad 0x2c32393472250920,0x61090a3b31313520,0x09203233622e646e,0x25202c3339347225\n"
".quad 0x7225202c31393472,0x6461090a3b323934,0x2509203233732e64,0x7225202c34393472\n"
".quad 0x347225202c333934,0x726873090a3b3039,0x722509203233732e,0x347225202c353934\n"
".quad 0x090a3b39202c3439,0x2e3436732e747663,0x6472250920323373,0x3b357225202c3336\n"
".quad 0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3639347225,0x6e6f6d6d6f635f64\n"
".quad 0x090a3b5d3036342b,0x732e6f6c2e6c756d,0x3934722509203233,0x3639347225202c37\n"
".quad 0x3b3738347225202c,0x69772e6c756d090a,0x09203233732e6564,0x25202c3833647225\n"
".quad 0x090a3b34202c3572,0x203233732e646461,0x202c383934722509,0x25202c3739347225\n"
".quad 0x6c090a3b33383472,0x2e74736e6f632e64,0x6472250920343675,0x72255b202c353631\n"
".quad 0x3b5d3633312b3464,0x36752e646461090a,0x3631647225092034,0x3631647225202c36\n"
".quad 0x3833647225202c35,0x732e766f6d090a3b,0x3934722509203233,0x3539347225202c39\n"
".quad 0x5f305f744c240a3b,0x0a3a343931363331,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x6e202c3232313120,0x6420676e69747365,0x2c31203a68747065\n"
".quad 0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e\n"
".quad 0x09373109636f6c2e,0x090a300935323131,0x203233662e766f6d,0x30202c3937662509\n"
".quad 0x3030303038663366,0x2f09202020203b30,0x766f6d090a31202f,0x662509203233662e\n"
".quad 0x30306630202c3038,0x203b303030303030,0x30202f2f09202020,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x347225202c393970,0x33317225202c3839,0x2e706c6573090a3b\n"
".quad 0x3866250920323366,0x2c39376625202c31,0x25202c3038662520,0x7473090a3b393970\n"
".quad 0x255b09203233662e,0x5d302b3636316472,0x0a3b31386625202c,0x3233732e64646109\n"
".quad 0x202c333172250920,0x3135202c33317225,0x2e646461090a3b32,0x6472250920343675\n"
".quad 0x647225202c363631,0x343032202c363631,0x70746573090a3b38,0x203233732e746c2e\n"
".quad 0x202c303031702509,0x7225202c33317225,0x2540090a3b383834,0x6172622030303170\n"
".quad 0x5f305f744c240920,0x0a3b343931363331,0x33315f305f744c24,0x2e090a3a32383635\n"
".quad 0x3109373109636f6c,0x62090a3009333431,0x20636e79732e7261,0x6f6c2e090a3b3009\n"
".quad 0x3531310937310963,0x766f6d090a300930,0x722509203233732e,0x3b357225202c3331\n"
".quad 0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3030357225,0x6e6f6d6d6f635f64\n"
".quad 0x090a3b5d3030352b,0x2e65672e70746573,0x3170250920323373,0x2c357225202c3130\n"
".quad 0x0a3b303035722520,0x2031303170254009,0x744c240920617262,0x30303036315f305f\n"
".quad 0x2e627573090a3b32,0x3572250920323373,0x30357225202c3130,0x0a3b357225202c30\n"
".quad 0x3233732e64646109,0x2c32303572250920,0x202c313035722520,0x6873090a3b313135\n"
".quad 0x2509203233732e72,0x7225202c33303572,0x3b3133202c323035,0x33732e766f6d090a\n"
".quad 0x3430357225092032,0x090a3b313135202c,0x203233622e646e61,0x202c353035722509\n"
".quad 0x25202c3330357225,0x61090a3b34303572,0x09203233732e6464,0x25202c3630357225\n"
".quad 0x7225202c35303572,0x6873090a3b323035,0x2509203233732e72,0x7225202c37303572\n"
".quad 0x0a3b39202c363035,0x3436732e74766309,0x722509203233732e,0x7225202c37363164\n"
".quad 0x2e6c756d090a3b35,0x3233732e65646977,0x2c38336472250920,0x3b34202c35722520\n"
".quad 0x6e6f632e646c090a,0x09203436752e7473,0x202c383631647225,0x35312b346472255b\n"
".quad 0x2e646c090a3b5d32,0x36752e74736e6f63,0x3331647225092034,0x346472255b202c30\n"
".quad 0x090a3b5d3032312b,0x203436752e646461,0x2c39363164722509,0x2c38363164722520\n"
".quad 0x0a3b383364722520,0x3436752e64646109,0x3133316472250920,0x303331647225202c\n"
".quad 0x3b3833647225202c,0x6e6f632e646c090a,0x09203233732e7473,0x5b202c3830357225\n"
".quad 0x6e6f6d6d6f635f64,0x090a3b5d3436342b,0x74736e6f632e646c,0x722509203233732e\n"
".quad 0x5f645b202c393035,0x342b6e6f6d6d6f63,0x646c090a3b5d3038,0x732e74736e6f632e\n"
".quad 0x3135722509203233,0x6f635f645b202c30,0x3231352b6e6f6d6d,0x632e646c090a3b5d\n"
".quad 0x3233732e74736e6f,0x2c31313572250920,0x6d6d6f635f645b20,0x3b5d3239342b6e6f\n"
".quad 0x33732e766f6d090a,0x3231357225092032,0x3b3730357225202c,0x315f305f744c240a\n"
".quad 0x200a3a3831323733,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964\n"
".quad 0x656e202c30353131,0x656420676e697473,0x202c31203a687470,0x6574616d69747365\n"
".quad 0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3109373109636f6c\n"
".quad 0x61090a3009343531,0x09203233732e6464,0x7225202c35327225,0x090a3b31202c3331\n"
".quad 0x203233732e6d6572,0x202c333135722509,0x7225202c35327225,0x6f6d090a3b313135\n"
".quad 0x2509203233732e76,0x357225202c333972,0x6f6c2e090a3b3331,0x3531310937310963\n"
".quad 0x766964090a300935,0x722509203233732e,0x327225202c343135,0x3131357225202c35\n"
".quad 0x732e646461090a3b,0x3539722509203233,0x2c3431357225202c,0x766f6d090a3b3120\n"
".quad 0x722509203233752e,0x0a3b30202c353135,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x357225202c323031,0x31357225202c3331,0x31702540090a3b35,0x0920617262203230\n"
".quad 0x33315f305f744c24,0x2e090a3b34373437,0x3109373109636f6c,0x6d090a3009373531\n"
".quad 0x09203233732e766f,0x7225202c33397225,0x6c2e090a3b313135,0x313109373109636f\n"
".quad 0x6f6d090a30093835,0x2509203233732e76,0x357225202c353972,0x5f744c240a3b3431\n"
".quad 0x3437343733315f30,0x09636f6c2e090a3a,0x0935393131093731,0x732e646461090a30\n"
".quad 0x3135722509203233,0x2c35397225202c36,0x0a3b303135722520,0x3233732e64646109\n"
".quad 0x2c37313572250920,0x202c363135722520,0x2e627573090a3b31,0x3572250920323373\n"
".quad 0x31357225202c3831,0x3930357225202c36,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x25202c3330317025,0x7225202c37313572,0x6461090a3b393035,0x2509203233732e64\n"
".quad 0x7225202c39313572,0x0a3b31202c383135,0x3233732e766f6d09,0x2c30323572250920\n"
".quad 0x6c6573090a3b3120,0x2509203233732e70,0x7225202c31323572,0x357225202c393135\n"
".quad 0x30317025202c3032,0x2e766f6d090a3b33,0x3172250920323373,0x32357225202c3330\n"
".quad 0x70746573090a3b31,0x203233732e74672e,0x202c343031702509,0x25202c3631357225\n"
".quad 0x73090a3b38303572,0x203233732e706c65,0x202c323235722509,0x25202c3830357225\n"
".quad 0x7025202c36313572,0x6573090a3b343031,0x33732e746c2e7074,0x3530317025092032\n"
".quad 0x2c3232357225202c,0x0a3b313235722520,0x2035303170254009,0x744c240920617262\n"
".quad 0x35323036315f305f,0x632e646c090a3b38,0x3233732e74736e6f,0x2c33323572250920\n"
".quad 0x6d6d6f635f645b20,0x3b5d3830352b6e6f,0x33732e646461090a,0x3432357225092032\n"
".quad 0x2c3332357225202c,0x090a3b3339722520,0x74736e6f632e646c,0x722509203233732e\n"
".quad 0x5f645b202c353235,0x342b6e6f6d6d6f63,0x6573090a3b5d3036,0x33732e74672e7074\n"
".quad 0x3630317025092032,0x2c3432357225202c,0x0a3b353235722520,0x33732e706c657309\n"
".quad 0x3632357225092032,0x2c3532357225202c,0x202c343235722520,0x090a3b3630317025\n"
".quad 0x203233732e627573,0x202c373235722509,0x25202c3232357225,0x61090a3b31323572\n"
".quad 0x09203233732e6464,0x25202c3832357225,0x3b31202c37323572,0x33732e646461090a\n"
".quad 0x3932357225092032,0x2c3432357225202c,0x2e646c090a3b3120,0x33732e74736e6f63\n"
".quad 0x3033357225092032,0x6d6f635f645b202c,0x5d3637342b6e6f6d,0x732e627573090a3b\n"
".quad 0x3335722509203233,0x3432357225202c31,0x3b3033357225202c,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x7225202c37303170,0x357225202c393235,0x646461090a3b3033\n"
".quad 0x722509203233732e,0x357225202c323335,0x090a3b31202c3133,0x203233732e646461\n"
".quad 0x202c333335722509,0x31202c3232357225,0x732e766f6d090a3b,0x3335722509203233\n"
".quad 0x73090a3b31202c34,0x203233732e706c65,0x202c353335722509,0x25202c3233357225\n"
".quad 0x7025202c34333572,0x6573090a3b373031,0x33732e65672e7074,0x3830317025092032\n"
".quad 0x2c3632357225202c,0x0a3b353335722520,0x3233662e766f6d09,0x30202c3466250920\n"
".quad 0x3030303030303066,0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233732e76\n"
".quad 0x7225202c36333572,0x744c240a3b383235,0x39343833315f305f,0x6c3c2f2f200a3a38\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x3539313120656e69,0x6e697473656e202c\n"
".quad 0x3a68747065642067,0x69747365202c3220,0x746920646574616d,0x736e6f6974617265\n"
".quad 0x776f6e6b6e75203a,0x3170252140090a6e,0x0920617262203830,0x33315f305f744c24\n"
".quad 0x73090a3b34353738,0x09203233732e6275,0x25202c3733357225,0x7225202c36323572\n"
".quad 0x6461090a3b353335,0x2509203233732e64,0x7225202c38333572,0x0a3b31202c373335\n"
".quad 0x2e6f6c2e6c756d09,0x3572250920323373,0x30317225202c3933,0x3532357225202c33\n"
".quad 0x732e67656e090a3b,0x3435722509203233,0x3532357225202c30,0x732e646461090a3b\n"
".quad 0x3435722509203233,0x3933357225202c31,0x3b3034357225202c,0x33732e646461090a\n"
".quad 0x3234357225092032,0x2c3134357225202c,0x0a3b353335722520,0x736e6f632e646c09\n"
".quad 0x2509203436752e74,0x5b202c3037316472,0x3633312b34647225,0x2e646461090a3b5d\n"
".quad 0x3572250920323373,0x32357225202c3334,0x61090a3b31202c36,0x09203233732e6464\n"
".quad 0x25202c3434357225,0x7225202c31343572,0x7663090a3b333435,0x33732e3436732e74\n"
".quad 0x3731647225092032,0x3234357225202c31,0x772e6c756d090a3b,0x203233732e656469\n"
".quad 0x2c32373164722509,0x202c323435722520,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x647225202c333731,0x647225202c303731,0x6f6d090a3b323731,0x2509203233732e76\n"
".quad 0x7225202c35343572,0x744c240a3b383335,0x36323933315f305f,0x6c3c2f2f200a3a36\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x3539313120656e69,0x6e697473656e202c\n"
".quad 0x3a68747065642067,0x69747365202c3320,0x746920646574616d,0x736e6f6974617265\n"
".quad 0x776f6e6b6e75203a,0x09636f6c2e090a6e,0x0939393131093731,0x33662e646c090a30\n"
".quad 0x2c32386625092032,0x3337316472255b20,0x61090a3b5d342d2b,0x09203233662e6464\n"
".quad 0x386625202c346625,0x0a3b346625202c32,0x3233732e64646109,0x2c32343572250920\n"
".quad 0x202c323435722520,0x2e646461090a3b31,0x6472250920343675,0x647225202c333731\n"
".quad 0x0a3b34202c333731,0x656e2e7074657309,0x702509203233732e,0x357225202c393031\n"
".quad 0x34357225202c3234,0x31702540090a3b34,0x0920617262203930,0x33315f305f744c24\n"
".quad 0x4c240a3b36363239,0x373833315f305f74,0x646461090a3a3435,0x722509203233732e\n"
".quad 0x317225202c333031,0x090a3b31202c3330,0x2e656e2e70746573,0x3170250920323373\n"
".quad 0x33357225202c3031,0x3330317225202c33,0x3131702540090a3b,0x2409206172622030\n"
".quad 0x3833315f305f744c,0x7262090a3b383934,0x240920696e752e61,0x3733315f305f744c\n"
".quad 0x744c240a3b363839,0x35323036315f305f,0x2e766f6d090a3a38,0x3466250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x33315f305f744c24\n"
".quad 0x2e090a3a36383937,0x3109373109636f6c,0x6c090a3009343032,0x2509203233662e64\n"
".quad 0x72255b202c333866,0x3b5d302b31333164,0x33662e6c756d090a,0x2c34386625092032\n"
".quad 0x25202c3338662520,0x2e7473090a3b3466,0x72255b0920323366,0x2c5d302b39363164\n"
".quad 0x090a3b3438662520,0x203233732e646461,0x25202c3331722509,0x323135202c333172\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3133,0x38343032202c3133\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3936,0x38343032202c3936\n"
".quad 0x2e70746573090a3b,0x09203233732e746c,0x25202c3131317025,0x357225202c333172\n"
".quad 0x702540090a3b3030,0x2061726220313131,0x315f305f744c2409,0x090a3b3831323733\n"
".quad 0x20696e752e617262,0x315f305f744c2409,0x240a3b3630373633,0x3036315f305f744c\n"
".quad 0x646c090a3a323030,0x732e74736e6f632e,0x3135722509203233,0x6f635f645b202c31\n"
".quad 0x3239342b6e6f6d6d,0x305f744c240a3b5d,0x3a3630373633315f,0x3109636f6c2e090a\n"
".quad 0x3009353132310937,0x79732e726162090a,0x090a3b300920636e,0x09373109636f6c2e\n"
".quad 0x090a300935323231,0x203233732e766f6d,0x25202c3331722509,0x746573090a3b3572\n"
".quad 0x3233732e65672e70,0x2c32313170250920,0x7225202c35722520,0x2540090a3b313135\n"
".quad 0x6172622032313170,0x5f305f744c240920,0x0a3b303932303431,0x68732e6174766309\n"
".quad 0x3436752e64657261,0x3437316472250920,0x616475635f5f202c,0x5f616475635f5f5f\n"
".quad 0x61765f6c61636f6c,0x5f30383434345f72,0x635f6e6f6e5f3033,0x7261705f74736e6f\n"
".quad 0x6f6f635f78616d5f,0x090a3b3830353931,0x6168732e61747663,0x203436752e646572\n"
".quad 0x2c35373164722509,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f39373434345f,0x6f635f6e6f6e5f32,0x5f7261705f74736e,0x326c61765f78616d\n"
".quad 0x73090a3b32333030,0x09203233732e6275,0x25202c3634357225,0x7225202c31313572\n"
".quad 0x2e646461090a3b35,0x3572250920323373,0x34357225202c3734,0x0a3b313135202c36\n"
".quad 0x3233732e72687309,0x2c38343572250920,0x202c373435722520,0x766f6d090a3b3133\n"
".quad 0x722509203233732e,0x313135202c393435,0x622e646e61090a3b,0x3535722509203233\n"
".quad 0x3834357225202c30,0x3b3934357225202c,0x33732e646461090a,0x3135357225092032\n"
".quad 0x2c3035357225202c,0x0a3b373435722520,0x3233732e72687309,0x2c32353572250920\n"
".quad 0x202c313535722520,0x2e747663090a3b39,0x203233732e343673,0x202c333664722509\n"
".quad 0x646c090a3b357225,0x732e74736e6f632e,0x3535722509203233,0x6f635f645b202c33\n"
".quad 0x3639342b6e6f6d6d,0x2e766f6d090a3b5d,0x3572250920323373,0x090a3b30202c3435\n"
".quad 0x2e74672e70746573,0x3170250920323373,0x35357225202c3331,0x3435357225202c33\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x202c383364722509,0x0a3b34202c357225\n"
".quad 0x3436752e64646109,0x3637316472250920,0x2c3833647225202c,0x3b34373164722520\n"
".quad 0x36752e646461090a,0x3731647225092034,0x3833647225202c37,0x353731647225202c\n"
".quad 0x732e766f6d090a3b,0x3535722509203233,0x6d090a3b30202c35,0x09203233662e766f\n"
".quad 0x6630202c35386625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3572250920323373,0x35357225202c3635,0x305f744c240a3b32,0x3a3230383034315f\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x202c353232312065\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x3331317025214009,0x4c24092061726220\n"
".quad 0x303134315f305f74,0x766f6d090a3b3835,0x722509203233732e,0x357225202c373535\n"
".quad 0x6c756d090a3b3335,0x203233732e6f6c2e,0x202c383535722509,0x7225202c33317225\n"
".quad 0x6f6d090a3b313135,0x2509203233732e76,0x7225202c39353572,0x6461090a3b383535\n"
".quad 0x2509203233732e64,0x7225202c30363572,0x357225202c383535,0x2e646c090a3b3335\n"
".quad 0x36752e74736e6f63,0x3731647225092034,0x346472255b202c38,0x090a3b5d3235312b\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x357225202c393731,0x6c756d090a3b3835\n"
".quad 0x33732e656469772e,0x3831647225092032,0x3835357225202c30,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x25202c3138316472,0x25202c3837316472,0x090a3b3038316472\n"
".quad 0x203233732e766f6d,0x202c313635722509,0x240a3b3735357225,0x3134315f305f744c\n"
".quad 0x2f2f200a3a303735,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x323120656e696c20\n"
".quad 0x7473656e202c3532,0x7470656420676e69,0x7365202c32203a68,0x20646574616d6974\n"
".quad 0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f,0x3332310937310963\n"
".quad 0x2e646c090a300930,0x3866250920323366,0x316472255b202c36,0x090a3b5d302b3138\n"
".quad 0x203233662e736261,0x25202c3738662509,0x6573090a3b363866,0x33662e74672e7074\n"
".quad 0x3431317025092032,0x202c37386625202c,0x40090a3b35386625,0x6220343131702521\n"
".quad 0x5f744c2409206172,0x3632383134315f30,0x09636f6c2e090a3b,0x0932333231093731\n"
".quad 0x732e766f6d090a30,0x3535722509203233,0x3935357225202c35,0x09636f6c2e090a3b\n"
".quad 0x0933333231093731,0x662e766f6d090a30,0x3538662509203233,0x0a3b37386625202c\n"
".quad 0x34315f305f744c24,0x61090a3a36323831,0x09203233732e6464,0x25202c3935357225\n"
".quad 0x3b31202c39353572,0x36752e646461090a,0x3831647225092034,0x3831647225202c31\n"
".quad 0x73090a3b34202c31,0x732e656e2e707465,0x3131702509203233,0x3935357225202c35\n"
".quad 0x3b3036357225202c,0x353131702540090a,0x4c24092061726220,0x353134315f305f74\n"
".quad 0x5f744c240a3b3037,0x3835303134315f30,0x09636f6c2e090a3a,0x0936333231093731\n"
".quad 0x33732e7473090a30,0x316472255b092032,0x25202c5d302b3637,0x2e090a3b35353572\n"
".quad 0x3109373109636f6c,0x73090a3009373332,0x5b09203233662e74,0x302b373731647225\n"
".quad 0x3b35386625202c5d,0x33732e646461090a,0x2c33317225092032,0x35202c3331722520\n"
".quad 0x646461090a3b3231,0x722509203436752e,0x7225202c37373164,0x3032202c37373164\n"
".quad 0x646461090a3b3834,0x722509203436752e,0x7225202c36373164,0x3032202c36373164\n"
".quad 0x746573090a3b3834,0x3233732e746c2e70,0x2c36313170250920,0x25202c3331722520\n"
".quad 0x40090a3b31313572,0x7262203631317025,0x305f744c24092061,0x3b3230383034315f\n"
".quad 0x315f305f744c240a,0x090a3a3039323034,0x6168732e61747663,0x203436752e646572\n"
".quad 0x2c34373164722509,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f30383434345f,0x6f635f6e6f6e5f30,0x5f7261705f74736e,0x316f6f635f78616d\n"
".quad 0x63090a3b38303539,0x726168732e617476,0x09203436752e6465,0x202c353731647225\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x32335f3937343434\n"
".quad 0x6e6f635f6e6f6e5f,0x6d5f7261705f7473,0x30326c61765f7861,0x6c2e090a3b323330\n"
".quad 0x323109373109636f,0x6162090a30093834,0x0920636e79732e72,0x70252140090a3b30\n"
".quad 0x0920617262203938,0x34315f305f744c24,0x6d090a3b30353832,0x09203233752e766f\n"
".quad 0x30202c3236357225,0x2e70746573090a3b,0x09203233732e656c,0x25202c3731317025\n"
".quad 0x7225202c31313572,0x2540090a3b323635,0x6172622037313170,0x5f305f744c240920\n"
".quad 0x0a3b323832313631,0x3233732e766f6d09,0x2c33363572250920,0x0a3b313135722520\n"
".quad 0x3436732e766f6d09,0x3238316472250920,0x6f6d090a3b30202c,0x2509203436732e76\n"
".quad 0x25202c3338316472,0x090a3b3537316472,0x203233732e766f6d,0x202c303434722509\n"
".quad 0x2e766f6d090a3b30,0x3572250920323373,0x090a3b30202c3436,0x203233662e766f6d\n"
".quad 0x30202c3838662509,0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f\n"
".quad 0x722509203233732e,0x357225202c353635,0x5f744c240a3b3336,0x3437383334315f30\n"
".quad 0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220,0x2c3834323120656e\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6d69747365202c31,0x6574692064657461\n"
".quad 0x3a736e6f69746172,0x6e776f6e6b6e7520,0x3233662e646c090a,0x202c393866250920\n"
".quad 0x2b3338316472255b,0x746573090a3b5d30,0x3233662e74672e70,0x2c38313170250920\n"
".quad 0x25202c3938662520,0x2140090a3b383866,0x7262203831317025,0x305f744c24092061\n"
".quad 0x3b3033313434315f,0x3109636f6c2e090a,0x3009383532310937,0x33662e766f6d090a\n"
".quad 0x2c38386625092032,0x090a3b3938662520,0x09373109636f6c2e,0x090a300939353231\n"
".quad 0x203436752e646461,0x2c34383164722509,0x2c32383164722520,0x3b34373164722520\n"
".quad 0x3233732e646c090a,0x2c34363572250920,0x3438316472255b20,0x744c240a3b5d302b\n"
".quad 0x33313434315f305f,0x2e646461090a3a30,0x3472250920323373,0x34347225202c3034\n"
".quad 0x61090a3b31202c30,0x09203436752e6464,0x202c323831647225,0x202c323831647225\n"
".quad 0x2e646461090a3b34,0x6472250920343675,0x647225202c333831,0x0a3b34202c333831\n"
".quad 0x656e2e7074657309,0x702509203233732e,0x357225202c393131,0x34347225202c3131\n"
".quad 0x31702540090a3b30,0x0920617262203931,0x34315f305f744c24,0x62090a3b34373833\n"
".quad 0x0920696e752e6172,0x34315f305f744c24,0x4c240a3b32363333,0x323136315f305f74\n"
".quad 0x766f6d090a3a3238,0x722509203233732e,0x0a3b30202c343635,0x34315f305f744c24\n"
".quad 0x2e090a3a32363333,0x3109373109636f6c,0x61090a3009343632,0x09203233732e6464\n"
".quad 0x25202c3636357225,0x3b31202c34363572,0x33732e6d6572090a,0x3736357225092032\n"
".quad 0x2c3636357225202c,0x0a3b313135722520,0x3233732e62757309,0x2c38363572250920\n"
".quad 0x202c373635722520,0x636f6c2e090a3b31,0x3536323109373109,0x2e766964090a3009\n"
".quad 0x3572250920323373,0x36357225202c3936,0x3131357225202c36,0x752e766f6d090a3b\n"
".quad 0x3735722509203233,0x73090a3b30202c30,0x732e656e2e707465,0x3231702509203233\n"
".quad 0x3736357225202c30,0x3b3037357225202c,0x303231702540090a,0x4c24092061726220\n"
".quad 0x383434315f305f74,0x6f6c2e090a3b3839,0x3632310937310963,0x627573090a300937\n"
".quad 0x722509203233732e,0x357225202c383635,0x090a3b31202c3131,0x09373109636f6c2e\n"
".quad 0x090a300938363231,0x203233732e627573,0x202c393635722509,0x31202c3936357225\n"
".quad 0x5f305f744c240a3b,0x0a3a383938343431,0x373109636f6c2e09,0x0a30093737323109\n"
".quad 0x3233732e62757309,0x2c31373572250920,0x25202c3234722520,0x6c090a3b35373472\n"
".quad 0x2509203233732e64,0x255b202c32373572,0x3b5d302b35326472,0x6e6f632e646c090a\n"
".quad 0x09203233732e7473,0x5b202c3337357225,0x6e6f6d6d6f635f64,0x090a3b5d3430322b\n"
".quad 0x203233732e627573,0x202c343735722509,0x25202c3836357225,0x73090a3b33373572\n"
".quad 0x09203233732e6275,0x25202c3537357225,0x7225202c34373572,0x6461090a3b313735\n"
".quad 0x2509203233732e64,0x7225202c36373572,0x357225202c323735,0x646461090a3b3537\n"
".quad 0x722509203233732e,0x357225202c373735,0x090a3b31202c3637,0x09203233732e7473\n"
".quad 0x2b3236316472255b,0x37357225202c5d30,0x636f6c2e090a3b37,0x3837323109373109\n"
".quad 0x732e646c090a3009,0x3735722509203233,0x326472255b202c38,0x73090a3b5d302b36\n"
".quad 0x09203233732e6275,0x25202c3937357225,0x7225202c39363572,0x627573090a3b3039\n"
".quad 0x722509203233732e,0x357225202c303835,0x37357225202c3937,0x2e646461090a3b31\n"
".quad 0x3572250920323373,0x37357225202c3138,0x3038357225202c38,0x732e646461090a3b\n"
".quad 0x3835722509203233,0x3138357225202c32,0x7473090a3b31202c,0x255b09203233732e\n"
".quad 0x5d302b3436316472,0x3b3238357225202c,0x315f305f744c240a,0x090a3a3035383234\n"
".quad 0x09373109636f6c2e,0x090a300936383231,0x636e79732e726162,0x744c240a3b300920\n"
".quad 0x32343037385f305f,0x2e706c6573090a3a,0x3572250920323373,0x30202c31202c3338\n"
".quad 0x090a3b367025202c,0x203233732e766f6d,0x202c343835722509,0x343339393835382d\n"
".quad 0x766f6d090a3b3935,0x722509203233732e,0x0a3b30202c353835,0x746c2e7074657309\n"
".quad 0x702509203233732e,0x317225202c313231,0x3b3538357225202c,0x33732e736261090a\n"
".quad 0x3638357225092032,0x090a3b317225202c,0x752e69682e6c756d,0x3835722509203233\n"
".quad 0x3638357225202c37,0x3b3438357225202c,0x33732e726873090a,0x3838357225092032\n"
".quad 0x2c3738357225202c,0x702540090a3b3320,0x2e62757320313231,0x3572250920323373\n"
".quad 0x38357225202c3838,0x3838357225202c35,0x732e766f6d090a3b,0x3835722509203233\n"
".quad 0x3838357225202c39,0x6c2e6c756d090a3b,0x2509203233732e6f,0x7225202c30393572\n"
".quad 0x3b3031202c393835,0x33732e627573090a,0x3139357225092032,0x25202c317225202c\n"
".quad 0x6d090a3b30393572,0x09203233732e766f,0x30202c3239357225,0x652e746573090a3b\n"
".quad 0x33732e3233752e71,0x3339357225092032,0x2c3139357225202c,0x0a3b323935722520\n"
".quad 0x3233732e67656e09,0x2c34393572250920,0x0a3b333935722520,0x3233622e646e6109\n"
".quad 0x2c35393572250920,0x202c333835722520,0x090a3b3439357225,0x203233752e766f6d\n"
".quad 0x202c363935722509,0x70746573090a3b30,0x203233732e71652e,0x202c323231702509\n"
".quad 0x25202c3539357225,0x40090a3b36393572,0x7262203232317025,0x305f744c24092061\n"
".quad 0x3b3232393534315f,0x3109636f6c2e090a,0x3009333033310937,0x33732e747663090a\n"
".quad 0x2509203233752e32,0x6325202c37393572,0x0a3b782e64696174,0x3436732e74766309\n"
".quad 0x722509203233732e,0x7225202c35383164,0x756d090a3b373935,0x732e656469772e6c\n"
".quad 0x3164722509203233,0x39357225202c3638,0x0a3b303631202c37,0x3436752e64646109\n"
".quad 0x202c346472250920,0x7225202c31647225,0x6c090a3b36383164,0x2e74736e6f632e64\n"
".quad 0x3772250920323373,0x2b346472255b202c,0x646c090a3b5d3034,0x752e74736e6f632e\n"
".quad 0x3264722509203436,0x346472255b202c32,0x646c090a3b5d302b,0x732e74736e6f632e\n"
".quad 0x3935722509203233,0x6f635f645b202c38,0x5d36312b6e6f6d6d,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x7225202c39393572,0x377225202c383935,0x732e747663090a3b\n"
".quad 0x09203233732e3436,0x202c373831647225,0x6461090a3b377225,0x2509203233732e64\n"
".quad 0x7225202c30303672,0x317225202c393935,0x772e6c756d090a3b,0x203233732e656469\n"
".quad 0x202c313164722509,0x0a3b34202c377225,0x3436732e74766309,0x722509203233732e\n"
".quad 0x7225202c38383164,0x6461090a3b303036,0x2509203436752e64,0x7225202c35326472\n"
".quad 0x647225202c323264,0x6c756d090a3b3131,0x33732e656469772e,0x3331647225092032\n"
".quad 0x2c3030367225202c,0x2e646c090a3b3420,0x36752e74736e6f63,0x3831647225092034\n"
".quad 0x346472255b202c39,0x61090a3b5d36312b,0x09203436752e6464,0x202c303931647225\n"
".quad 0x202c393831647225,0x090a3b3331647225,0x09203233732e646c,0x5b202c3130367225\n"
".quad 0x302b303931647225,0x732e7473090a3b5d,0x6472255b09203233,0x25202c5d302b3532\n"
".quad 0x2e090a3b31303672,0x3109373109636f6c,0x6c090a3009343033,0x2e74736e6f632e64\n"
".quad 0x6472250920343675,0x6472255b202c3332,0x61090a3b5d382b34,0x09203436752e6464\n"
".quad 0x25202c3632647225,0x7225202c33326472,0x646c090a3b313164,0x752e74736e6f632e\n"
".quad 0x3164722509203436,0x6472255b202c3139,0x090a3b5d34322b34,0x203436752e646461\n"
".quad 0x2c32393164722509,0x2c31393164722520,0x0a3b333164722520,0x203233732e646c09\n"
".quad 0x202c323036722509,0x2b3239316472255b,0x2e7473090a3b5d30,0x72255b0920323373\n"
".quad 0x202c5d302b363264,0x090a3b3230367225,0x09373109636f6c2e,0x090a300937303331\n"
".quad 0x2e3233732e747663,0x3572250920323375,0x782e64697425202c,0x732e766f6d090a3b\n"
".quad 0x3331722509203233,0x090a3b357225202c,0x74736e6f632e646c,0x722509203233732e\n"
".quad 0x635f645b202c3431,0x31322b6e6f6d6d6f,0x746573090a3b5d32,0x3233732e65672e70\n"
".quad 0x2c33323170250920,0x7225202c35722520,0x702540090a3b3431,0x2061726220333231\n"
".quad 0x315f305f744c2409,0x090a3b3232393534,0x203233732e627573,0x202c333036722509\n"
".quad 0x7225202c34317225,0x2e646461090a3b35,0x3672250920323373,0x30367225202c3430\n"
".quad 0x0a3b313135202c33,0x3233732e72687309,0x2c35303672250920,0x202c343036722520\n"
".quad 0x766f6d090a3b3133,0x722509203233732e,0x313135202c363036,0x622e646e61090a3b\n"
".quad 0x3036722509203233,0x3530367225202c37,0x3b3630367225202c,0x33732e646461090a\n"
".quad 0x3830367225092032,0x2c3730367225202c,0x0a3b343036722520,0x3233732e72687309\n"
".quad 0x2c39303672250920,0x202c383036722520,0x2e747663090a3b39,0x203233732e343673\n"
".quad 0x202c333664722509,0x646c090a3b357225,0x662e74736e6f632e,0x3039662509203233\n"
".quad 0x6d6f635f645b202c,0x3b5d32312b6e6f6d,0x69772e6c756d090a,0x09203233732e6564\n"
".quad 0x25202c3833647225,0x090a3b34202c3572,0x203436662e766f6d,0x30202c3164662509\n"
".quad 0x3030303066663364,0x3030303030303030,0x0a31202f2f093b30,0x3436662e74766309\n"
".quad 0x662509203233662e,0x30396625202c3264,0x662e627573090a3b,0x3364662509203436\n"
".quad 0x202c31646625202c,0x6d090a3b32646625,0x09203436732e766f,0x202c333931647225\n"
".quad 0x61090a3b39647225,0x09203436752e6464,0x202c373331647225,0x202c333931647225\n"
".quad 0x090a3b3833647225,0x74736e6f632e646c,0x722509203233732e,0x635f645b202c3232\n"
".quad 0x30322b6e6f6d6d6f,0x632e646c090a3b5d,0x3436752e74736e6f,0x2c37326472250920\n"
".quad 0x6d6d6f635f645b20,0x676e6168635f6e6f,0x6c090a3b5d302b65,0x2e74736e6f632e64\n"
".quad 0x3272250920323373,0x6f635f645b202c33,0x3430322b6e6f6d6d,0x2e766f6d090a3b5d\n"
".quad 0x3672250920323373,0x30367225202c3031,0x305f744c240a3b39,0x3a3433343634315f\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x202c373033312065\n"
".quad 0x20676e697473656e,0x31203a6874706564,0x616d69747365202c,0x7265746920646574\n"
".quad 0x203a736e6f697461,0x0a6e776f6e6b6e75,0x373109636f6c2e09,0x0a30093131333109\n"
".quad 0x3233732e64646109,0x202c353272250920,0x3b31202c33317225,0x33732e6d6572090a\n"
".quad 0x2c36327225092032,0x25202c3532722520,0x7573090a3b333272,0x2509203233732e62\n"
".quad 0x327225202c373272,0x2e090a3b31202c36,0x3109373109636f6c,0x64090a3009323133\n"
".quad 0x09203233732e7669,0x7225202c38327225,0x33327225202c3532,0x752e766f6d090a3b\n"
".quad 0x3136722509203233,0x73090a3b30202c31,0x732e656e2e707465,0x3231702509203233\n"
".quad 0x2c36327225202c34,0x0a3b313136722520,0x2034323170254009,0x744c240920617262\n"
".quad 0x39363634315f305f,0x636f6c2e090a3b30,0x3431333109373109,0x2e627573090a3009\n"
".quad 0x3272250920323373,0x2c33327225202c37,0x6f6c2e090a3b3120,0x3133310937310963\n"
".quad 0x627573090a300935,0x722509203233732e,0x38327225202c3832,0x744c240a3b31202c\n"
".quad 0x39363634315f305f,0x636f6c2e090a3a30,0x3432333109373109,0x662e646c090a3009\n"
".quad 0x3139662509203233,0x33316472255b202c,0x6d090a3b5d302b37,0x09203233662e6c75\n"
".quad 0x6625202c32396625,0x30396625202c3139,0x662e747663090a3b,0x09203233662e3436\n"
".quad 0x6625202c34646625,0x2e646c090a3b3239,0x3672250920323373,0x6472255b202c3231\n"
".quad 0x090a3b5d302b3532,0x203233732e646461,0x202c333136722509,0x25202c3231367225\n"
".quad 0x646c090a3b373272,0x722509203233732e,0x72255b202c343136,0x0a3b5d302b363264\n"
".quad 0x3233732e64646109,0x2c35313672250920,0x202c343136722520,0x73090a3b38327225\n"
".quad 0x09203233732e6275,0x25202c3631367225,0x3632202c35313672,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x7225202c37313672,0x31367225202c3232,0x2e646461090a3b36\n"
".quad 0x3672250920323373,0x31367225202c3831,0x3731367225202c33,0x732e627573090a3b\n"
".quad 0x3136722509203233,0x3831367225202c39,0x63090a3b3632202c,0x732e3436732e7476\n"
".quad 0x3164722509203233,0x31367225202c3439,0x2e6c756d090a3b39,0x3233732e65646977\n"
".quad 0x3539316472250920,0x2c3931367225202c,0x646461090a3b3420,0x722509203436752e\n"
".quad 0x7225202c36393164,0x647225202c373264,0x646c090a3b353931,0x662509203233662e\n"
".quad 0x6472255b202c3339,0x0a3b5d302b363931,0x3436662e74766309,0x662509203233662e\n"
".quad 0x33396625202c3564,0x722e64616d090a3b,0x2509203436662e6e,0x646625202c366466\n"
".quad 0x2c33646625202c35,0x090a3b3464662520,0x662e6e722e747663,0x09203436662e3233\n"
".quad 0x6625202c34396625,0x2e7473090a3b3664,0x72255b0920323366,0x2c5d302b37333164\n"
".quad 0x090a3b3439662520,0x203233732e646461,0x25202c3331722509,0x323135202c333172\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3733,0x38343032202c3733\n"
".quad 0x2e70746573090a3b,0x09203233732e746c,0x25202c3532317025,0x317225202c333172\n"
".quad 0x31702540090a3b34,0x0920617262203532,0x34315f305f744c24,0x4c240a3b34333436\n"
".quad 0x393534315f305f74,0x5f744c240a3a3232,0x3031343534315f30,0x09636f6c2e090a3a\n"
".quad 0x0933333331093731,0x3b74697865090a30,0x646e6557444c240a,0x6e72656b365a5f5f\n"
".quad 0x207d090a3a766c65,0x656b365a5f202f2f,0x000a0a766c656e72,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long fatbinData[11516];

}


static struct {int m; int v; const unsigned long long* d; char* f;} __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))=
 { 0x466243b1, 1, fatbinData, 0 };
# 3 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c" 2
extern void __device_stub__Z6kernelv(void);
static void __sti____cudaRegisterAll_39_tmpxft_000025e3_00000000_4_main_cpp1_ii_b81a68a1(void) __attribute__((__constructor__));
void __device_stub__Z6kernelv(void){{ volatile static char *__f; __f = ((char *)((void ( *)(void))kernel)); (void)cudaLaunch(((char *)((void ( *)(void))kernel))); };}
void kernel(void)
# 7 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/kernel.cuh"
{__device_stub__Z6kernelv();
# 1333 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/hwt/kernel.cuh"
}
# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c"
static void __sti____cudaRegisterAll_39_tmpxft_000025e3_00000000_4_main_cpp1_ii_b81a68a1(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(void))kernel), (char*)"_Z6kernelv", "_Z6kernelv", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_common_change, (char*)"d_common_change", "d_common_change", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_common, (char*)"d_common", "d_common", 0, 520, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_unique, (char*)"d_unique", "d_unique", 0, 8160, 1, 0); }
# 1 "/tmp/tmpxft_000025e3_00000000-1_main.cudafe1.stub.c" 2

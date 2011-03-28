# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
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
# 71 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char * , const char * , unsigned , const char * ) throw()
# 73 "/usr/include/assert.h" 3
 __attribute((__noreturn__));
# 76 "/usr/include/assert.h" 3
extern "C" void __assert_perror_fail(int , const char * , unsigned , const char * ) throw()
# 79 "/usr/include/assert.h" 3
 __attribute((__noreturn__));
# 84 "/usr/include/assert.h" 3
extern "C" void __assert(const char * , const char * , int ) throw()
# 85 "/usr/include/assert.h" 3
 __attribute((__noreturn__));
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
# 47 "/usr/include/bits/errno.h" 3
extern "C" int *__errno_location() throw() __attribute((const));
# 55 "/usr/include/errno.h" 3
extern "C" { extern char *program_invocation_name, *program_invocation_short_name; }
# 69 "/usr/include/errno.h" 3
typedef int error_t;
# 57 "/usr/include/sys/time.h" 3
extern "C" { struct timezone {
# 59 "/usr/include/sys/time.h" 3
int tz_minuteswest;
# 60 "/usr/include/sys/time.h" 3
int tz_dsttime;
# 61 "/usr/include/sys/time.h" 3
}; }
# 63 "/usr/include/sys/time.h" 3
extern "C" { typedef struct timezone *__restrict__ __timezone_ptr_t; }
# 73 "/usr/include/sys/time.h" 3
extern "C" int gettimeofday(timeval *__restrict__ , __timezone_ptr_t ) throw()
# 74 "/usr/include/sys/time.h" 3
 __attribute((__nonnull__(1)));
# 79 "/usr/include/sys/time.h" 3
extern "C" int settimeofday(const timeval * , const struct timezone * ) throw()
# 81 "/usr/include/sys/time.h" 3
 __attribute((__nonnull__(1)));
# 87 "/usr/include/sys/time.h" 3
extern "C" int adjtime(const timeval * , timeval * ) throw();
# 93 "/usr/include/sys/time.h" 3
enum __itimer_which {
# 96 "/usr/include/sys/time.h" 3
ITIMER_REAL,
# 99 "/usr/include/sys/time.h" 3
ITIMER_VIRTUAL,
# 103 "/usr/include/sys/time.h" 3
ITIMER_PROF
# 105 "/usr/include/sys/time.h" 3
};
# 109 "/usr/include/sys/time.h" 3
extern "C" { struct itimerval {
# 112 "/usr/include/sys/time.h" 3
timeval it_interval;
# 114 "/usr/include/sys/time.h" 3
timeval it_value;
# 115 "/usr/include/sys/time.h" 3
}; }
# 122 "/usr/include/sys/time.h" 3
extern "C" { typedef int __itimer_which_t; }
# 127 "/usr/include/sys/time.h" 3
extern "C" int getitimer(__itimer_which_t , itimerval * ) throw();
# 133 "/usr/include/sys/time.h" 3
extern "C" int setitimer(__itimer_which_t , const itimerval *__restrict__ , itimerval *__restrict__ ) throw();
# 140 "/usr/include/sys/time.h" 3
extern "C" int utimes(const char * , const timeval [2]) throw()
# 141 "/usr/include/sys/time.h" 3
 __attribute((__nonnull__(1)));
# 145 "/usr/include/sys/time.h" 3
extern "C" int lutimes(const char * , const timeval [2]) throw()
# 146 "/usr/include/sys/time.h" 3
 __attribute((__nonnull__(1)));
# 149 "/usr/include/sys/time.h" 3
extern "C" int futimes(int , const timeval [2]) throw();
# 156 "/usr/include/sys/time.h" 3
extern "C" int futimesat(int , const char * , const timeval [2]) throw();
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
# 3 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
typedef unsigned uint32_t;
# 6 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
static const int basecount = 5;
# 114 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct TextureAddress {
# 115 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
union {
# 116 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned data;
# 118 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct {
# 120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned short x;
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned short y;
# 125 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 127 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 130 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct PixelOfNode {
# 133 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
union {
# 134 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
uint4 data;
# 136 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct {
# 137 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char parent[3];
# 138 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char suffix[3];
# 140 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char start[3];
# 141 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char end[3];
# 142 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char depth[3];
# 144 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char pad;
# 145 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 146 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 150 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct PixelOfChildren {
# 153 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
union {
# 154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
uint4 data;
# 157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
union {
# 159 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct {
# 160 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char a[3];
# 161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char c[3];
# 162 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char g[3];
# 163 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char t[3];
# 164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char d[3];
# 166 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
char leafchar;
# 167 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 170 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct {
# 171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char leafid[3];
# 172 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned char pad[12];
# 173 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
char leafchar0;
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 175 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 176 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 177 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
};
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
typedef
# 179 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct MatchInfo {
# 181 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned resultsoffset;
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned queryid;
# 183 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
TextureAddress matchnode;
# 184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned numLeaves;
# 185 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned short edgematch;
# 186 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned short qrystartpos;
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
} MatchInfo;
# 193 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
typedef
# 189 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
struct Alignment {
# 191 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
int left_in_ref;
# 192 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
unsigned short matchlen;
# 193 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
} Alignment;
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
static const int MAX_TEXTURE_DIMENSION = 4096;
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
static const int MAX_GRID_DIMENSION = 65535;
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/common.cuh"
static const int MAX_QUERY_LEN = 8192;
# 6 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct QuerySet {
# 7 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int qfile;
# 9 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *h_tex_array;
# 10 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *d_tex_array;
# 11 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int *d_addrs_tex_array;
# 12 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int *h_addrs_tex_array;
# 13 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int *h_lengths_array;
# 14 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int *d_lengths_array;
# 16 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char **h_names;
# 18 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned count;
# 19 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t texlen;
# 22 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t bytes_on_board;
# 23 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 26 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct AuxiliaryNodeData {
# 27 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int length;
# 28 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int numleaves;
# 29 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
TextureAddress printParent;
# 30 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 33 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct Reference {
# 35 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *str;
# 36 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t len;
# 37 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_load_from_disk;
# 39 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned pitch;
# 40 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *d_ref_array;
# 41 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *h_ref_array;
# 44 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *d_node_tex_array;
# 45 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *h_node_tex_array;
# 47 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *d_children_tex_array;
# 48 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *h_children_tex_array;
# 50 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *d_parent_tex_array;
# 51 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
void *h_parent_tex_array;
# 61 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned tex_node_height;
# 62 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned tex_children_height;
# 63 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned tex_width;
# 66 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t bytes_on_board;
# 68 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
AuxiliaryNodeData *aux_data;
# 69 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int num_nodes;
# 71 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 79 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct MatchCoord {
# 81 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
union {
# 82 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int2 data;
# 84 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
struct {
# 85 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
TextureAddress node;
# 86 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int edge_match_length;
# 87 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
};
# 88 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
};
# 89 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 91 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct MatchResults {
# 94 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
MatchCoord *d_match_coords;
# 95 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
MatchCoord *h_match_coords;
# 97 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned numCoords;
# 105 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int *h_coord_tex_array;
# 108 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t bytes_on_board;
# 109 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct Statistics {
# 113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_end_to_end;
# 114 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_match_kernel;
# 115 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_print_kernel;
# 116 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_results_to_disk;
# 117 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_queries_to_board;
# 118 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_match_coords_to_board;
# 119 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_match_coords_from_board;
# 120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_tree_to_board;
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_ref_str_to_board;
# 122 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_queries_from_disk;
# 123 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_ref_from_disk;
# 124 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_tree_construction;
# 125 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_tree_reorder;
# 126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_tree_flatten;
# 127 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_reorder_ref_str;
# 128 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_build_coord_offsets;
# 129 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float t_coords_to_buffers;
# 130 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
float bp_avg_query_length;
# 137 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 139 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct MatchContext {
# 140 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *full_ref;
# 141 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
size_t full_ref_len;
# 143 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
Reference *ref;
# 144 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
QuerySet *queries;
# 145 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
MatchResults results;
# 147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool on_cpu;
# 149 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int min_match_length;
# 151 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool reverse;
# 152 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool forwardreverse;
# 153 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool forwardcoordinates;
# 154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool show_query_length;
# 155 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
bool maxmatch;
# 157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *stats_file;
# 158 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *dotfilename;
# 159 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
char *texfilename;
# 160 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
Statistics statistics;
# 161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct ReferencePage {
# 165 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int begin;
# 166 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int end;
# 167 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int shadow_left;
# 168 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
int shadow_right;
# 169 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
MatchResults results;
# 170 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
unsigned id;
# 171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
Reference ref;
# 172 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { __attribute__((unused)) TextureAddress id2addr(int ); }
# 176 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int createReference(const char * , Reference * );
# 177 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int destroyReference(Reference * );
# 179 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int createQuerySet(const char * , QuerySet * );
# 180 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int destroyQuerySet(QuerySet * );
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int createMatchContext(Reference * , QuerySet * , MatchResults * , bool , int , char * , bool , bool , bool , bool , char * , char * , MatchContext * );
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int destroyMatchContext(MatchContext * );
# 200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" int matchQueries(MatchContext * );
# 202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" void printStringForError(int );
# 205 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" { struct Timer_t {
# 207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
timeval start_m;
# 208 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
timeval end_m;
# 209 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
}; }
# 211 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" char *createTimer();
# 212 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" void startTimer(char * );
# 213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" void stopTimer(char * );
# 214 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" float getTimerValue(char * );
# 215 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.h"
extern "C" void deleteTimer(char * );
# 131 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
static texture< uint4, 2, cudaReadModeElementType> nodetex;
# 132 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
static texture< uint4, 2, cudaReadModeElementType> childrentex;
# 142 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
static texture< char, 1, cudaReadModeElementType> reftex;
# 145 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
static texture< char, 1, cudaReadModeElementType> qrytex;
# 147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct __attribute((aligned(8))) _MatchCoord {
# 150 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
union {
# 151 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
int2 data;
# 153 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct {
# 154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
int node;
# 155 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
int edge_match_length;
# 156 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 158 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct _PixelOfChildren {
# 164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
union {
# 165 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uint4 data;
# 168 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
union {
# 170 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct {
# 171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 a;
# 172 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 c;
# 173 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 g;
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 t;
# 175 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 d;
# 177 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
char leafchar;
# 178 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 181 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct {
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 leafid;
# 183 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
unsigned char pad[12];
# 184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
char leafchar0;
# 185 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 186 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 188 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 191 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct _PixelOfNode {
# 194 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
union {
# 195 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uint4 data;
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
struct {
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 parent;
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 suffix;
# 201 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 start;
# 202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 end;
# 203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
uchar3 depth;
# 205 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
unsigned char pad;
# 206 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 208 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
};
# 228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) int addr2id(unsigned addr)
# 229 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)addr;
# 252 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 254 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) TextureAddress id2addr(int id)
# 255 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)id;
# 284 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 293 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) void arrayToAddress(uchar3 arr, unsigned &addr)
# 294 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)arr;(void)addr;
# 300 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 306 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) inline char getRef(int refpos, char *
# 308 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
ref)
# 311 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)refpos;(void)ref;
# 330 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 336 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) char rc(char c)
# 337 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)c;
# 347 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 353 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) uint4 getNode(unsigned cur, bool
# 354 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
use_two_level)
# 362 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)cur;(void)use_two_level;
# 388 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 396 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) uint4 getChildren(unsigned cur, bool
# 397 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
use_two_level)
# 405 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)cur;(void)use_two_level;
# 429 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 636 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
__attribute__((unused)) void set_result(unsigned cur, _MatchCoord *
# 637 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
result, int
# 638 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
edge_match_length, int
# 639 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
qry_match_len, int
# 640 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
min_match_len, int
# 641 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
rc)
# 651 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{int volatile ___ = 1;(void)cur;(void)result;(void)edge_match_length;(void)qry_match_len;(void)min_match_len;(void)rc;
# 669 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
exit(___);}
# 678 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
void mummergpuKernel(void *match_coords, char *
# 687 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queries, char *
# 700 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
ref, const int *
# 702 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryAddrs, const int *
# 703 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryLengths, const int
# 704 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
numQueries, const int
# 705 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
min_match_len) ;
# 867 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
void mummergpuRCKernel(MatchCoord *match_coords, char *
# 868 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queries, const int *
# 869 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryAddrs, const int *
# 870 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryLengths, const int
# 871 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
numQueries, const int
# 872 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
min_match_len) ;
# 1043 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
void printKernel(MatchInfo *matches, int
# 1044 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
totalMatches, Alignment *
# 1045 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
alignments, char *
# 1050 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queries, const int *
# 1061 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryAddrs, const int *
# 1062 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
queryLengths, const int
# 1063 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
page_begin, const int
# 1064 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
page_end, const int
# 1065 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
page_shadow_left, const int
# 1066 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
page_shadow_right, const int
# 1067 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
min_match_length) ;
# 23 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int USE_PRINT_KERNEL = 1;
# 29 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned cuda_calls = (0);
# 30 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void trap_dbg()
# 31 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 32 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Trapped\n");
# 33 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 78 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned num_bind_tex_calls = (0);
# 106 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void runTest(int , char ** );
# 109 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void computeGold(MatchResults * , char * , char * , int * , int * , PixelOfNode * , PixelOfChildren * , int , int , int );
# 121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void getReferenceString(const char * , char ** , size_t * );
# 124 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void createTreeTexture(const char * , PixelOfNode ** , PixelOfChildren ** , unsigned * , unsigned * , unsigned * , AuxiliaryNodeData ** , int * , int , Statistics * , const char * , const char * );
# 138 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void getQueriesTexture(int , char ** , size_t * , int ** , char *** , int ** , unsigned * , unsigned * , unsigned , int , bool );
# 151 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int lookupNumLeaves(ReferencePage * , TextureAddress );
# 153 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void printAlignments(ReferencePage * , Alignment * , char * , int , TextureAddress , int , int , int , bool , bool );
# 164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int countLeafNodes(int );
# 167 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void mapQueriesEndToEnd(MatchContext * , ReferencePage * , MatchInfo * , unsigned , Alignment * , unsigned );
# 174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *createTimer()
# 175 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 176 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned *ptr = ((unsigned *)malloc(sizeof(Timer_t)));
# 177 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
memset(ptr, 0, sizeof(Timer_t));
# 178 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return (char *)ptr;
# 179 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 181 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void startTimer(char *ptr)
# 182 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 183 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
gettimeofday(&(((Timer_t *)ptr)->start_m), __null);
# 184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 186 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void stopTimer(char *ptr)
# 187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 188 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
gettimeofday(&(((Timer_t *)ptr)->end_m), __null);
# 189 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 191 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float getTimerValue(char *ptr)
# 192 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 193 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Timer_t *timer = ((Timer_t *)ptr);
# 195 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (timer == (__null))
# 196 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Uninitialized timer!!!\n");
# 198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return (0.0);
# 199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 201 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (((timer->end_m).tv_sec) == (0)) { stopTimer(ptr); }
# 203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return (float)(((1000.0) * (((timer->end_m).tv_sec) - ((timer->start_m).tv_sec))) + ((0.001000000000000000021) * (((timer->end_m).tv_usec) - ((timer->start_m).tv_usec))));
# 205 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void deleteTimer(char *ptr)
# 208 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 209 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free((Timer_t *)ptr);
# 210 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int createReference(const char *fromFile, Reference *ref)
# 214 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 215 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((!(fromFile)) || (!(ref))) {
# 216 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return -1; }
# 218 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *loadreftimer = createTimer();
# 219 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(loadreftimer);
# 221 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
getReferenceString(fromFile, &(ref->str), &(ref->len));
# 223 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(loadreftimer);
# 224 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->t_load_from_disk) += getTimerValue(loadreftimer);
# 225 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(loadreftimer);
# 227 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 231 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int destroyReference(Reference *ref)
# 232 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 233 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(ref->h_node_tex_array);
# 234 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(ref->h_children_tex_array);
# 235 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(ref->str);
# 240 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(ref->aux_data);
# 245 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->str) = (__null);
# 246 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->len) = (0);
# 248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 249 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 252 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int createQuerySet(const char *fromFile, QuerySet *queries)
# 253 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 255 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Opening %s...\n", fromFile);
# 256 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qfile = open(fromFile, 0);
# 258 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (qfile == (-1))
# 259 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 260 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Can\'t open %s: %d\n", fromFile, *__errno_location());
# 261 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(1);
# 262 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 264 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->qfile) = qfile;
# 266 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 267 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 270 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int destroyQuerySet(QuerySet *queries)
# 271 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 273 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (queries->qfile) {
# 274 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
close(queries->qfile); }
# 276 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 277 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 280 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" void printStringForError(int err)
# 281 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 283 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 286 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int createMatchContext(Reference *ref, QuerySet *
# 287 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
queries, MatchResults *
# 288 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matches, bool
# 289 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
on_cpu, int
# 290 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
min_match_length, char *
# 291 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stats_file, bool
# 292 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
reverse, bool
# 293 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
forwardreverse, bool
# 294 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
forwardcoordinates, bool
# 295 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
showQueryLength, char *
# 296 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dotfilename, char *
# 297 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
texfilename, MatchContext *
# 298 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
ctx) {
# 300 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->queries) = queries;
# 301 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->ref) = ref;
# 302 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->full_ref) = (ref->str);
# 303 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->full_ref_len) = (ref->len);
# 305 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->on_cpu) = on_cpu;
# 306 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->min_match_length) = min_match_length;
# 307 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->stats_file) = stats_file;
# 308 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->reverse) = reverse;
# 309 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->forwardreverse) = forwardreverse;
# 310 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->forwardcoordinates) = forwardcoordinates;
# 311 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->show_query_length) = showQueryLength;
# 312 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->dotfilename) = dotfilename;
# 313 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->texfilename) = texfilename;
# 314 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 315 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 319 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int destroyMatchContext(MatchContext *ctx)
# 320 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 321 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(ctx->full_ref);
# 323 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
destroyQuerySet(ctx->queries);
# 324 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 325 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 327 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void buildReferenceTexture(Reference *ref, char *
# 328 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
full_ref, size_t
# 329 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
begin, size_t
# 330 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
end, int
# 331 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
min_match_len, char *
# 332 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dotfilename, char *
# 333 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
texfilename, Statistics *
# 334 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
statistics)
# 335 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 336 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Building reference texture...\n");
# 338 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
PixelOfNode *nodeTexture = (__null);
# 339 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
PixelOfChildren *childrenTexture = (__null);
# 341 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned width = (0);
# 342 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned node_height = (0);
# 343 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned children_height = (0);
# 345 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
AuxiliaryNodeData *aux_data = (__null);
# 346 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int num_nodes;
# 348 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *loadreftimer = createTimer();
# 349 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(loadreftimer);
# 351 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->len) = ((end - begin) + (3));
# 352 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->str) = ((char *)malloc(ref->len));
# 353 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ref->str)[0]) = 's';
# 354 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
strncpy((ref->str) + 1, full_ref + begin, (ref->len) - (3));
# 355 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
strcpy(((ref->str) + (ref->len)) - 2, "$");
# 357 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(loadreftimer);
# 358 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(statistics->t_ref_from_disk) += (getTimerValue(loadreftimer) + (ref->t_load_from_disk));
# 359 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(loadreftimer);
# 361 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
createTreeTexture(ref->str, &nodeTexture, &childrenTexture, &width, &node_height, &children_height, &aux_data, &num_nodes, min_match_len, statistics, dotfilename, texfilename);
# 374 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->h_node_tex_array) = nodeTexture;
# 375 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->h_children_tex_array) = childrenTexture;
# 376 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->tex_width) = width;
# 377 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->tex_node_height) = node_height;
# 378 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->tex_children_height) = children_height;
# 385 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->aux_data) = aux_data;
# 386 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->num_nodes) = num_nodes;
# 388 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->bytes_on_board) = (((width * node_height) * sizeof(PixelOfNode)) + ((width * children_height) * sizeof(PixelOfChildren)));
# 390 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "This tree will need %d bytes on the board\n", ref->bytes_on_board);
# 453 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "The refstr requires %d bytes\n", ref->len);
# 454 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->bytes_on_board) += (ref->len);
# 458 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 460 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void boardMemory(unsigned *free_mem, unsigned *total_mem)
# 461 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 465 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*free_mem) = ((512 * 1024) * 1024);
# 466 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*total_mem) = ((768 * 1024) * 1024);
# 470 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 473 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void loadReferenceTexture(MatchContext *ctx)
# 474 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 475 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Reference *ref = (ctx->ref);
# 476 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int numrows = (ceil((ref->len) / ((float)(ref->pitch))));
# 477 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int blocksize = 4;
# 478 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numrows += blocksize;
# 480 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaChannelFormatDesc refTextureDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSigned);
# 483 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(ctx->on_cpu)) {
# 484 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *toboardtimer = createTimer();
# 485 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(toboardtimer);
# 548 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&(ref->d_ref_array)), ref->len); ++num_bind_tex_calls; } while (0);
# 549 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(ref->d_ref_array), ref->str, ref->len, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 552, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 554 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->ref)->bytes_on_board) += (ref->len);
# 557 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(toboardtimer);
# 558 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_ref_str_to_board) += getTimerValue(toboardtimer);
# 559 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(toboardtimer);
# 560 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 561 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 562 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_ref_array) = (__null);
# 563 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 564 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 567 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void unloadReferenceString(Reference *ref)
# 568 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 576 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(ref->d_ref_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 576, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 579 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_ref_array) = (__null);
# 580 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 582 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void unloadReferenceTree(MatchContext *ctx)
# 583 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 584 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Reference *ref = (ctx->ref);
# 589 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaUnbindTexture(nodetex); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 589, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 590 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFreeArray((cudaArray *)(ref->d_node_tex_array)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 590, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 594 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_node_tex_array) = (__null);
# 597 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (ref->d_children_tex_array)
# 598 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 600 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaUnbindTexture(childrentex); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 600, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 601 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFreeArray((cudaArray *)(ref->d_children_tex_array)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 601, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 605 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 607 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_children_tex_array) = (__null);
# 638 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 641 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void loadReference(MatchContext *ctx) {
# 643 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Reference *ref = (ctx->ref);
# 645 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->bytes_on_board) = (0);
# 647 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadReferenceTexture(ctx);
# 649 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(ctx->on_cpu)) {
# 650 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *toboardtimer = createTimer();
# 651 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(toboardtimer);
# 654 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->bytes_on_board) += (((ref->tex_width) * (ref->tex_node_height)) * sizeof(PixelOfNode));
# 657 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->bytes_on_board) += (((ref->tex_width) * (ref->tex_children_height)) * sizeof(PixelOfChildren));
# 662 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaChannelFormatDesc nodeTextureDesc = cudaCreateChannelDesc(32, 32, 32, 32, cudaChannelFormatKindUnsigned);
# 665 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMallocArray((cudaArray **)(&(ref->d_node_tex_array)), &nodeTextureDesc, ref->tex_width, ref->tex_node_height); ++num_bind_tex_calls; } while (0);
# 672 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpyToArray((cudaArray *)(ref->d_node_tex_array), 0, 0, ref->h_node_tex_array, ((ref->tex_width) * (ref->tex_node_height)) * sizeof(PixelOfNode), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 677, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 679 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((nodetex.addressMode)[0]) = cudaAddressModeClamp;
# 680 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((nodetex.addressMode)[1]) = cudaAddressModeClamp;
# 681 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(nodetex.filterMode) = cudaFilterModePoint;
# 682 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(nodetex.normalized) = (false);
# 684 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { do { cuda_calls++; cudaError err = cudaBindTextureToArray(nodetex, (cudaArray *)(ref->d_node_tex_array), nodeTextureDesc); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 685, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0); ++num_bind_tex_calls; } while (0);
# 703 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (ref->tex_children_height)
# 704 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 706 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaChannelFormatDesc childrenTextureDesc = cudaCreateChannelDesc(32, 32, 32, 32, cudaChannelFormatKindUnsigned);
# 708 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMallocArray((cudaArray **)(&(ref->d_children_tex_array)), &childrenTextureDesc, ref->tex_width, ref->tex_children_height); ++num_bind_tex_calls; } while (0);
# 713 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpyToArray((cudaArray *)(ref->d_children_tex_array), 0, 0, ref->h_children_tex_array, ((ref->tex_width) * (ref->tex_children_height)) * sizeof(PixelOfChildren), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 718, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 720 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((childrentex.addressMode)[0]) = cudaAddressModeClamp;
# 721 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((childrentex.addressMode)[1]) = cudaAddressModeClamp;
# 722 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(childrentex.filterMode) = cudaFilterModePoint;
# 723 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(childrentex.normalized) = (false);
# 725 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { do { cuda_calls++; cudaError err = cudaBindTextureToArray(childrentex, (cudaArray *)(ref->d_children_tex_array), childrenTextureDesc); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 726, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0); ++num_bind_tex_calls; } while (0);
# 742 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 883 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(toboardtimer);
# 884 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_tree_to_board) += getTimerValue(toboardtimer);
# 885 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(toboardtimer);
# 887 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "done\n");
# 888 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 889 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 890 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_node_tex_array) = (__null);
# 891 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ref->d_children_tex_array) = (__null);
# 892 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 893 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 897 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void dumpQueryBlockInfo(QuerySet *queries)
# 898 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 899 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "\tProcessing queries %s to %s\n", (queries->h_names)[0], (queries->h_names)[(queries->count) - (1)]);
# 902 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 904 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void loadQueries(MatchContext *ctx)
# 905 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 906 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 907 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->bytes_on_board) = (0);
# 909 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numQueries = (queries->count);
# 911 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(ctx->on_cpu)) {
# 912 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Allocating device memory for queries... ");
# 914 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *toboardtimer = createTimer();
# 915 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(toboardtimer);
# 917 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dumpQueryBlockInfo(queries);
# 918 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_tex_array)), queries->texlen); ++num_bind_tex_calls; } while (0);
# 921 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->bytes_on_board) += (queries->texlen);
# 923 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_tex_array), (queries->h_tex_array) + ((queries->h_addrs_tex_array)[0]), queries->texlen, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 926, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 937 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_addrs_tex_array)), numQueries * sizeof(int)); ++num_bind_tex_calls; } while (0);
# 940 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->bytes_on_board) += (numQueries * sizeof(int));
# 942 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_addrs_tex_array), queries->h_addrs_tex_array, numQueries * sizeof(int), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 945, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 947 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_lengths_array)), numQueries * sizeof(int)); ++num_bind_tex_calls; } while (0);
# 950 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->bytes_on_board) += (numQueries * sizeof(int));
# 952 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_lengths_array), queries->h_lengths_array, numQueries * sizeof(int), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 955, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 956 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(toboardtimer);
# 957 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_queries_to_board) += getTimerValue(toboardtimer);
# 958 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(toboardtimer);
# 960 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "\tallocated %ld bytes\n", queries->bytes_on_board);
# 962 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 963 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 964 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_addrs_tex_array) = (__null);
# 965 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_tex_array) = (__null);
# 966 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_lengths_array) = (__null);
# 967 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, " allocated %ld bytes\n", (((2) * numQueries) * sizeof(int)) + (queries->texlen));
# 968 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 971 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 974 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void unloadQueries(MatchContext *ctx)
# 975 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 976 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 978 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_tex_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 978, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 979 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_tex_array) = (__null);
# 981 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_addrs_tex_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 981, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 982 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_addrs_tex_array) = (__null);
# 984 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_lengths_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 984, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 985 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->d_lengths_array) = (__null);
# 987 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->bytes_on_board) = (0);
# 988 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 992 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
inline int match_coord_addrs(int qryid, int qry_addrs, int match_length)
# 993 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 994 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return qry_addrs - (qryid * (match_length + 1));
# 995 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1000 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void buildCoordOffsetArray(MatchContext *ctx, int **
# 1001 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
h_coord_offset_array, unsigned *
# 1002 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
num_coords)
# 1003 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1004 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int numCoords = 0;
# 1005 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int match_length = (ctx->min_match_length);
# 1006 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int numQueries = ((ctx->queries)->count);
# 1007 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *lengths = ((ctx->queries)->h_lengths_array);
# 1009 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *coord_offsets = ((int *)calloc(numQueries, sizeof(int)));
# 1033 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (unsigned i = (0); i < numQueries; ++i)
# 1034 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1035 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qryoffset = (((ctx->queries)->h_addrs_tex_array)[i]);
# 1036 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(coord_offsets[i]) = match_coord_addrs(i, qryoffset, match_length);
# 1037 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1038 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (numQueries > 0)
# 1039 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1040 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned last_qry = (numQueries - 1);
# 1041 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned last_qry_len = (((lengths[last_qry]) - match_length) + 1);
# 1042 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numCoords = ((coord_offsets[last_qry]) + last_qry_len);
# 1043 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Need %d match coords for this result array\n", numCoords);
# 1045 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1047 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*num_coords) = numCoords;
# 1048 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*h_coord_offset_array) = coord_offsets;
# 1049 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1052 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void loadResultBuffer(MatchContext *ctx)
# 1053 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1054 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numQueries = ((ctx->queries)->count);
# 1056 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(numQueries) ? (static_cast< void>(0)) : __assert_fail("numQueries", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1056, __PRETTY_FUNCTION__);
# 1058 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *offsettimer = createTimer();
# 1059 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(offsettimer);
# 1061 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
buildCoordOffsetArray(ctx, &((ctx->results).h_coord_tex_array), &((ctx->results).numCoords));
# 1065 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(offsettimer);
# 1066 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_build_coord_offsets) += getTimerValue(offsettimer);
# 1067 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(offsettimer);
# 1069 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numCoords = ((ctx->results).numCoords);
# 1070 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Allocating result array for %d queries (%d bytes) ...", numQueries, numCoords * sizeof(MatchCoord));
# 1073 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned boardFreeMemory = (0);
# 1074 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned total_mem = (0);
# 1076 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
boardMemory(&boardFreeMemory, &total_mem);
# 1078 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", boardFreeMemory, total_mem);
# 1081 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).h_match_coords) = ((MatchCoord *)calloc(numCoords, sizeof(MatchCoord)));
# 1082 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (((ctx->results).h_match_coords) == (__null))
# 1083 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1084 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
trap_dbg();
# 1085 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(1);
# 1086 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1088 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(ctx->on_cpu)) {
# 1089 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *toboardtimer = createTimer();
# 1090 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(toboardtimer);
# 1092 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).bytes_on_board) = (0);
# 1094 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&((ctx->results).d_match_coords)), numCoords * sizeof(MatchCoord)); ++num_bind_tex_calls; } while (0);
# 1096 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).bytes_on_board) += (numCoords * sizeof(MatchCoord));
# 1098 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemset((void *)((ctx->results).d_match_coords), 0, numCoords * sizeof(MatchCoord)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1099, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(toboardtimer);
# 1113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_match_coords_to_board) += getTimerValue(toboardtimer);
# 1114 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(toboardtimer);
# 1115 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1116 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1117 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).d_match_coords) = (__null);
# 1118 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "done\n");
# 1121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1124 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void unloadResultBuffer(MatchContext *ctx) {
# 1125 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree((ctx->results).d_match_coords); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1125, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1126 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).d_match_coords) = (__null);
# 1127 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).bytes_on_board) = (0);
# 1132 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1134 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void transferResultsFromDevice(MatchContext *ctx)
# 1135 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1136 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(ctx->on_cpu))
# 1137 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1138 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *fromboardtimer = createTimer();
# 1139 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(fromboardtimer);
# 1141 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((ctx->results).h_match_coords, (ctx->results).d_match_coords, ((ctx->results).numCoords) * sizeof(MatchCoord), cudaMemcpyDeviceToHost); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1144, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1189 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(fromboardtimer);
# 1190 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_match_coords_from_board) += getTimerValue(fromboardtimer);
# 1191 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(fromboardtimer);
# 1192 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1194 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1197 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int flushOutput();
# 1198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int addToBuffer(char * );
# 1200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char numbuffer[32];
# 1202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchCoord *coordForQueryChar(MatchContext *ctx, unsigned
# 1203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
qryid, unsigned
# 1204 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
qrychar)
# 1205 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1206 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchResults *results = (&(ctx->results));
# 1207 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchCoord *coords = (results->h_match_coords);
# 1211 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return (coords + ((results->h_coord_tex_array)[qryid])) + qrychar;
# 1213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1215 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void coordsToPrintBuffers(MatchContext *ctx, ReferencePage *
# 1216 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
page, MatchInfo **
# 1217 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matches, Alignment **
# 1218 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
alignments, unsigned
# 1219 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
mem_avail, unsigned *
# 1220 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
coord_idx, unsigned *
# 1221 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
match_idx, unsigned *
# 1222 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
align_idx, unsigned *
# 1223 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
nextqry, unsigned *
# 1224 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
nextqrychar)
# 1225 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1226 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numQueries = ((ctx->queries)->count);
# 1227 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int match_length = (ctx->min_match_length);
# 1228 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned cidx = (*coord_idx);
# 1229 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned midx = (0);
# 1231 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numCoords = ((ctx->results).numCoords);
# 1233 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numMatches = (0);
# 1234 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numAlignments = (0);
# 1236 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int DEBUG = 0;
# 1237 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((DEBUG) && (cidx == (0)))
# 1238 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1239 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int j = 0; j < numCoords; ++j)
# 1240 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1241 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchCoord *coord = (((ctx->results).h_match_coords) + j);
# 1242 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1243 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1246 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stdout, "node: %d leaves:%d\n", (coord->node).data, lookupNumLeaves(page, coord->node));
# 1248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1249 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1250 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(0);
# 1251 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1255 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int j = (cidx); j < numCoords; ++j)
# 1256 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1257 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchCoord *coord = (((ctx->results).h_match_coords) + j);
# 1259 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int queryAlignments = 0;
# 1260 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int queryMatches = 0;
# 1262 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1263 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1264 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int numLeaves = lookupNumLeaves(page, coord->node);
# 1265 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
queryAlignments += numLeaves;
# 1266 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
queryMatches++;
# 1267 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1268 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int allMatches = (numMatches + queryMatches);
# 1269 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int allAlignments = (numAlignments + queryAlignments);
# 1271 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int neededSize = ((allMatches * sizeof(MatchInfo)) + (allAlignments * sizeof(Alignment)));
# 1273 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((neededSize > mem_avail) || ((allMatches / 256) >= MAX_GRID_DIMENSION))
# 1274 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1276 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
break;
# 1277 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1279 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
++cidx;
# 1280 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numMatches = allMatches;
# 1281 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numAlignments = allAlignments;
# 1282 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1284 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchInfo *M = ((MatchInfo *)calloc(numMatches, sizeof(MatchInfo)));
# 1285 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned alignmentOffset = (0);
# 1287 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qry = (*nextqry);
# 1288 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qrychar = (*nextqrychar);
# 1289 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
bool set_full = false;
# 1290 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
while (qry < numQueries)
# 1291 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1293 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qlen = (((((ctx->queries)->h_lengths_array)[qry]) + 1) - match_length);
# 1295 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
while (qrychar < qlen)
# 1296 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1297 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (midx >= numMatches)
# 1298 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1299 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
set_full = true;
# 1300 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
break;
# 1301 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1303 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchCoord *coord = coordForQueryChar(ctx, qry, qrychar);
# 1305 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1306 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1307 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchInfo m;
# 1308 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.resultsoffset) = alignmentOffset;
# 1309 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.qrystartpos) = qrychar;
# 1310 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.matchnode) = (coord->node);
# 1311 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.edgematch) = (coord->edge_match_length);
# 1312 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.numLeaves) = (lookupNumLeaves(page, m.matchnode));
# 1313 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(m.queryid) = qry;
# 1315 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
alignmentOffset += (m.numLeaves);
# 1316 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(M[midx++]) = m;
# 1317 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1319 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
++qrychar;
# 1320 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1322 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (set_full) {
# 1323 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
break; }
# 1325 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
++qry;
# 1326 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
qrychar = 0;
# 1327 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1329 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*coord_idx) = cidx;
# 1330 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*match_idx) = midx;
# 1331 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*align_idx) = alignmentOffset;
# 1332 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*matches) = M;
# 1333 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*nextqry) = qry;
# 1334 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*nextqrychar) = qrychar;
# 1335 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Allocing %d bytes of host memory for %d alignments\n", alignmentOffset * sizeof(Alignment), numAlignments);
# 1336 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*alignments) = ((Alignment *)calloc(alignmentOffset, sizeof(Alignment)));
# 1338 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1341 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void runPrintKernel(MatchContext *ctx, ReferencePage *
# 1342 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
page, MatchInfo *
# 1343 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
h_matches, unsigned
# 1344 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numMatches, Alignment *
# 1345 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
alignments, unsigned
# 1346 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numAlignments)
# 1347 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1349 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchInfo *d_matches;
# 1350 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
size_t matchesSize = (numMatches * sizeof(MatchInfo));
# 1351 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&d_matches), matchesSize); ++num_bind_tex_calls; } while (0);
# 1353 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Alignment *d_alignments;
# 1354 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
size_t alignmentSize = (numAlignments * sizeof(Alignment));
# 1355 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cudaMalloc((void **)(&d_alignments), alignmentSize); ++num_bind_tex_calls; } while (0);
# 1356 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemset((void *)d_alignments, 0, alignmentSize); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1356, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1358 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *atimer = createTimer();
# 1359 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(atimer);
# 1361 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "prepared %d matches %d alignments\n", numMatches, numAlignments);
# 1362 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Copying %d bytes to host memory for %d alignments\n", numAlignments * sizeof(Alignment), numAlignments);
# 1364 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int DEBUG = 0;
# 1365 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (DEBUG)
# 1366 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1367 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 0; i < numMatches; i++)
# 1368 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1369 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
printf("m[%d]:\t%d\t%d\t%d\t%d\t%d\t%d\n", i, (h_matches[i]).resultsoffset, (h_matches[i]).queryid, ((h_matches[i]).matchnode).data, (h_matches[i]).numLeaves, (h_matches[i]).edgematch, (h_matches[i]).qrystartpos);
# 1377 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1379 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(0);
# 1380 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1382 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy(d_matches, h_matches, matchesSize, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1382, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1383 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(atimer);
# 1384 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float mtime = getTimerValue(atimer);
# 1387 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int blocksize = ((numMatches > (256)) ? (256) : numMatches);
# 1389 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dim3 dimBlock(blocksize, 1, 1);
# 1390 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dim3 dimGrid(ceil(numMatches / ((float)256)), 1, 1);
# 1392 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "  Calling print kernel... ");
# 1394 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : printKernel(d_matches, numMatches, d_alignments, (ctx->queries)->d_tex_array, (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, page->begin, page->end, page->shadow_left, page->shadow_right, ctx->min_match_length);
# 1429 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaThreadSynchronize();
# 1433 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaError_t err = cudaGetLastError();
# 1434 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((cudaSuccess) != err)
# 1435 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1436 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Kernel execution failed: %s.\n", cudaGetErrorString(err));
# 1438 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(1);
# 1439 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1441 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(atimer);
# 1443 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)alignments, (void *)d_alignments, alignmentSize, cudaMemcpyDeviceToHost); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1446, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1447 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaThreadSynchronize();
# 1448 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(atimer);
# 1450 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float atime = getTimerValue(atimer);
# 1451 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "memcpy time= %f\n", atime + mtime);
# 1452 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(atimer);
# 1454 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(d_alignments); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1454, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1455 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(d_matches); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1455, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1456 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1459 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void runPrintOnCPU(MatchContext *ctx, ReferencePage *page, MatchInfo *
# 1460 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
h_matches, unsigned
# 1461 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numMatches, Alignment *
# 1462 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
alignments, unsigned
# 1463 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
numAlignments)
# 1464 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1465 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned min_match_length = (ctx->min_match_length);
# 1467 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *addrs = ((ctx->queries)->h_addrs_tex_array);
# 1468 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *lengths = ((ctx->queries)->h_lengths_array);
# 1469 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *qrychars = ((ctx->queries)->h_tex_array);
# 1471 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(numMatches)) {
# 1472 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return; }
# 1474 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int qry = (-1);
# 1475 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned qrylen;
# 1477 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 0; i < numMatches; ++i)
# 1478 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1479 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchInfo &match = (h_matches[i]);
# 1480 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((match.queryid) != qry)
# 1481 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1482 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
qry = (match.queryid);
# 1483 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
qrylen = (lengths[qry]);
# 1484 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1485 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!((match.edgematch) & 32768))
# 1486 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1487 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
printAlignments(page, alignments + (match.resultsoffset), qrychars + (addrs[qry]), qrylen, match.matchnode, match.qrystartpos, match.edgematch, min_match_length, 0, ctx->forwardcoordinates);
# 1501 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1502 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1503 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1505 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int addMatchToBuffer(int , int , int );
# 1507 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void getExactAlignments(MatchContext *ctx, ReferencePage *page, bool on_cpu)
# 1508 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1509 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((!(ctx->reverse)) && (!(ctx->forwardreverse))) ? (static_cast< void>(0)) : __assert_fail("!ctx->reverse && !ctx->forwardreverse", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 1509, __PRETTY_FUNCTION__);
# 1511 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned boardFreeMemory;
# 1512 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned total_mem;
# 1514 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!on_cpu)
# 1515 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1516 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
boardMemory(&boardFreeMemory, &total_mem);
# 1517 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", boardFreeMemory, total_mem);
# 1519 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1521 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1522 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
boardFreeMemory = ((256 * 1024) * 1024);
# 1523 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
total_mem = boardFreeMemory;
# 1524 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1530 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
boardFreeMemory -= ((16 * 1024) * 1024);
# 1531 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "board free memory: %u\n", boardFreeMemory);
# 1533 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int rTotalMatches = 0;
# 1534 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int rTotalAlignments = 0;
# 1535 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int totalRounds = 0;
# 1536 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned last_coord = ((ctx->results).numCoords);
# 1537 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned next_coord = (0);
# 1538 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned nextqry = (0);
# 1539 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned nextqrychar = (0);
# 1540 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int lastqry = (-1);
# 1541 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
while (next_coord < last_coord) {
# 1542 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1544 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
totalRounds++;
# 1546 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numMatches = (0);
# 1547 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numAlignments = (0);
# 1548 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
MatchInfo *h_matches = (__null);
# 1549 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
Alignment *h_alignments = (__null);
# 1550 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int coord_left = (next_coord);
# 1551 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *btimer = createTimer();
# 1552 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(btimer);
# 1553 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
coordsToPrintBuffers(ctx, page, &h_matches, &h_alignments, boardFreeMemory, &next_coord, &numMatches, &numAlignments, &nextqry, &nextqrychar);
# 1555 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(btimer);
# 1557 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float btime = getTimerValue(btimer);
# 1558 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_coords_to_buffers) += btime;
# 1559 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "buffer prep time= %f\n", btime);
# 1560 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(btimer);
# 1562 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Round %d: Printing results for match coords [%d-%d) of %d using %d matches and %d alignments\n", totalRounds, coord_left, next_coord, last_coord, numMatches, numAlignments);
# 1565 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (numMatches == (0)) {
# 1566 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
continue; }
# 1568 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char buf[256];
# 1571 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
rTotalAlignments += numAlignments;
# 1572 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
rTotalMatches += numMatches;
# 1574 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (num_bind_tex_calls > (100))
# 1575 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1576 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaThreadExit();
# 1577 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
num_bind_tex_calls = (0);
# 1578 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadReference(ctx);
# 1579 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadQueries(ctx);
# 1580 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1582 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *ktimer = createTimer();
# 1583 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(ktimer);
# 1584 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (on_cpu)
# 1585 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1586 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
runPrintOnCPU(ctx, page, h_matches, numMatches, h_alignments, numAlignments);
# 1588 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1590 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1591 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
runPrintKernel(ctx, page, h_matches, numMatches, h_alignments, numAlignments);
# 1593 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1594 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(ktimer);
# 1596 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float ktime = getTimerValue(ktimer);
# 1597 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_print_kernel) += ktime;
# 1598 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "print kernel time= %f\n", ktime);
# 1599 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(ktimer);
# 1619 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *otimer = createTimer();
# 1620 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(otimer);
# 1622 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int m = 0; m < numMatches; m++)
# 1623 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1624 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int base = ((h_matches[m]).resultsoffset);
# 1625 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 0; i < ((h_matches[m]).numLeaves); i++)
# 1626 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1628 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (((h_alignments[base + i]).left_in_ref) == 0)
# 1629 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1630 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
break;
# 1631 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1633 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (((h_matches[m]).queryid) != lastqry)
# 1634 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1635 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
lastqry = ((h_matches[m]).queryid);
# 1636 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
addToBuffer((char *)("> "));
# 1637 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
addToBuffer(*(((ctx->queries)->h_names) + lastqry));
# 1638 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
addToBuffer((char *)("\n"));
# 1639 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1641 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
sprintf(buf, "%d\t%d\t%d\n", (h_alignments[base + i]).left_in_ref, ((h_matches[m]).qrystartpos) + 1, (h_alignments[base + i]).matchlen);
# 1645 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
addToBuffer(buf);
# 1651 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1652 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1655 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
flushOutput();
# 1657 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(otimer);
# 1658 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_results_to_disk) += getTimerValue(otimer);
# 1659 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(otimer);
# 1661 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(h_matches);
# 1662 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(h_alignments);
# 1665 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} }
# 1666 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free((ctx->results).h_coord_tex_array);
# 1667 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free((ctx->results).h_match_coords);
# 1668 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).h_coord_tex_array) = (__null);
# 1669 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).h_match_coords) = (__null);
# 1671 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Finished processing %d matches and %d potential alignments in %d rounds\n", rTotalMatches, rTotalAlignments, totalRounds);
# 1673 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1675 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int getQueryBlock(MatchContext *ctx, size_t device_mem_avail)
# 1676 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1677 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 1678 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *queryTex = (__null);
# 1679 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *queryAddrs = (__null);
# 1680 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *queryLengths = (__null);
# 1681 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned numQueries;
# 1682 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned num_match_coords;
# 1683 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
size_t queryLen;
# 1684 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char **names;
# 1686 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Loading query block... ");
# 1688 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *queryreadtimer = createTimer();
# 1689 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(queryreadtimer);
# 1691 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
getQueriesTexture(queries->qfile, &queryTex, &queryLen, &queryAddrs, &names, &queryLengths, &numQueries, &num_match_coords, device_mem_avail, ctx->min_match_length, (ctx->reverse) || (ctx->forwardreverse));
# 1703 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(queryreadtimer);
# 1704 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_queries_from_disk) += getTimerValue(queryreadtimer);
# 1705 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(queryreadtimer);
# 1707 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_tex_array) = queryTex;
# 1708 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->count) = numQueries;
# 1709 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_addrs_tex_array) = queryAddrs;
# 1710 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->texlen) = queryLen;
# 1711 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_names) = names;
# 1712 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_lengths_array) = queryLengths;
# 1714 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->results).numCoords) = num_match_coords;
# 1716 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "done.\n");
# 1718 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return numQueries;
# 1719 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1721 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void destroyQueryBlock(QuerySet *queries)
# 1722 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1723 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(queries->h_tex_array);
# 1724 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_tex_array) = (__null);
# 1726 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 0; i < (queries->count); ++i) {
# 1727 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free((queries->h_names)[i]); }
# 1729 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(queries->h_names);
# 1731 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->count) = (0);
# 1732 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->texlen) = (0);
# 1734 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(queries->h_addrs_tex_array);
# 1735 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_addrs_tex_array) = (__null);
# 1737 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(queries->h_lengths_array);
# 1738 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(queries->h_lengths_array) = (__null);
# 1739 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1741 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void resetStats(Statistics *stats)
# 1742 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1743 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_end_to_end) = ((0.0));
# 1744 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_match_kernel) = ((0.0));
# 1745 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_print_kernel) = ((0.0));
# 1746 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_queries_to_board) = ((0.0));
# 1747 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_match_coords_to_board) = ((0.0));
# 1748 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_match_coords_from_board) = ((0.0));
# 1749 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_tree_to_board) = ((0.0));
# 1750 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_ref_str_to_board) = ((0.0));
# 1751 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_queries_from_disk) = ((0.0));
# 1752 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_ref_from_disk) = ((0.0));
# 1753 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_results_to_disk) = ((0.0));
# 1754 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_tree_construction) = ((0.0));
# 1755 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_tree_reorder) = ((0.0));
# 1756 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_tree_flatten) = ((0.0));
# 1757 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_reorder_ref_str) = ((0.0));
# 1758 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_build_coord_offsets) = ((0.0));
# 1759 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->t_coords_to_buffers) = ((0.0));
# 1760 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(stats->bp_avg_query_length) = ((0.0));
# 1777 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1779 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void writeStatisticsFile(Statistics *stats, char *
# 1780 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stats_filename, char *
# 1781 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
node_hist_filename = 0, char *
# 1782 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
child_hist_filename = 0)
# 1783 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1784 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (stats_filename)
# 1785 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1786 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
FILE *f = fopen(stats_filename, "w");
# 1788 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!(f))
# 1789 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1790 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "WARNING: could not open %s for writing\n", stats_filename);
# 1791 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1793 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1794 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, "Q");
# 1795 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",R");
# 1796 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",T");
# 1797 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",m");
# 1798 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",r");
# 1799 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",t");
# 1800 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",n");
# 1801 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Total");
# 1802 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Match kernel");
# 1803 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Print Kernel");
# 1804 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Queries to board");
# 1805 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Match coords to board");
# 1806 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Match coords from board");
# 1807 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Tree to board");
# 1808 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Ref str to board");
# 1809 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Queries from disk");
# 1810 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Ref from disk");
# 1811 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Output to disk");
# 1812 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Tree construction");
# 1813 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Tree reorder");
# 1814 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Tree flatten");
# 1815 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Ref reorder");
# 1816 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Build coord table");
# 1817 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Coords to buffers");
# 1818 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",Avg qry length");
# 1819 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, "\n");
# 1821 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, "%d", 0);
# 1822 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 0);
# 1823 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 1);
# 1824 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 0);
# 1825 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 0);
# 1826 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 1);
# 1827 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%d", 1);
# 1828 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_end_to_end);
# 1829 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_match_kernel);
# 1830 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_print_kernel);
# 1831 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_queries_to_board);
# 1832 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_match_coords_to_board);
# 1833 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_match_coords_from_board);
# 1834 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_to_board);
# 1835 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_ref_str_to_board);
# 1836 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_queries_from_disk);
# 1837 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_ref_from_disk);
# 1838 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_results_to_disk);
# 1839 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_construction);
# 1840 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_reorder);
# 1841 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_flatten);
# 1842 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_reorder_ref_str);
# 1843 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_build_coord_offsets);
# 1844 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->t_coords_to_buffers);
# 1845 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, ",%f", stats->bp_avg_query_length);
# 1846 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(f, "\n");
# 1848 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fclose(f);
# 1849 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1850 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1903 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1905 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void matchOnCPU(MatchContext *ctx, bool doRC)
# 1906 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1908 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (doRC) {
# 1910 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
computeGold(&(ctx->results), (ctx->ref)->str, (ctx->queries)->h_tex_array, (ctx->queries)->h_addrs_tex_array, (ctx->queries)->h_lengths_array, (PixelOfNode *)((ctx->ref)->h_node_tex_array), (PixelOfChildren *)((ctx->ref)->h_children_tex_array), (ctx->queries)->count, ctx->min_match_length, 32768);
# 1920 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1921 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1922 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
computeGold(&(ctx->results), (ctx->ref)->str, (ctx->queries)->h_tex_array, (ctx->queries)->h_addrs_tex_array, (ctx->queries)->h_lengths_array, (PixelOfNode *)((ctx->ref)->h_node_tex_array), (PixelOfChildren *)((ctx->ref)->h_children_tex_array), (ctx->queries)->count, ctx->min_match_length, 0);
# 1932 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1933 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1935 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void matchOnGPU(MatchContext *ctx, bool doRC)
# 1936 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1937 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int numQueries = ((ctx->queries)->count);
# 1938 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int blocksize = ((numQueries > 256) ? 256 : numQueries);
# 1940 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dim3 dimBlock(blocksize, 1, 1);
# 1942 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
dim3 dimGrid(ceil(numQueries / ((float)256)), 1, 1);
# 1945 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (doRC) {
# 1947 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : mummergpuRCKernel((ctx->results).d_match_coords, (ctx->queries)->d_tex_array, (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, numQueries, ctx->min_match_length);
# 1953 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 1954 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 1955 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : mummergpuKernel((ctx->results).d_match_coords, (ctx->queries)->d_tex_array, (char *)((ctx->ref)->d_ref_array), (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, numQueries, ctx->min_match_length);
# 1987 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1990 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaError_t err = cudaGetLastError();
# 1991 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((cudaSuccess) != err) {
# 1992 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Kernel execution failed: %s.\n", cudaGetErrorString(err));
# 1994 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
exit(1);
# 1995 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1996 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1998 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void getMatchResults(MatchContext *ctx, unsigned
# 1999 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
page_num)
# 2000 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2001 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
transferResultsFromDevice(ctx);
# 2002 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2004 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void matchQueryBlockToReferencePage(MatchContext *ctx, ReferencePage *
# 2005 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
page, bool
# 2006 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
reverse_complement)
# 2007 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2008 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *ktimer = createTimer();
# 2010 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Memory footprint is:\n\tqueries: %d\n\tref: %d\n\tresults: %d\n", (ctx->queries)->bytes_on_board, (ctx->ref)->bytes_on_board, (ctx->results).bytes_on_board);
# 2015 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(ktimer);
# 2016 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (ctx->on_cpu)
# 2017 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2018 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchOnCPU(ctx, reverse_complement);
# 2019 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 2021 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2023 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchOnGPU(ctx, reverse_complement);
# 2024 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaThreadSynchronize();
# 2026 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2027 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(ktimer);
# 2029 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
float ktime = getTimerValue(ktimer);
# 2030 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_match_kernel) += ktime;
# 2031 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "match kernel time= %f\n", ktime);
# 2032 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(ktimer);
# 2034 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
getMatchResults(ctx, page->id);
# 2035 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unloadResultBuffer(ctx);
# 2036 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2039 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int matchSubset(MatchContext *ctx, ReferencePage *
# 2040 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
page)
# 2041 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2043 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadQueries(ctx);
# 2045 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Matching queries %s - %s against ref coords %d - %d\n", ((ctx->queries)->h_names)[0], ((ctx->queries)->h_names)[((ctx->queries)->count) - (1)], page->begin, page->end);
# 2052 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadResultBuffer(ctx);
# 2056 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchQueryBlockToReferencePage(ctx, page, false);
# 2058 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if ((USE_PRINT_KERNEL) && (!(ctx->on_cpu)))
# 2059 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2060 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
getExactAlignments(ctx, page, false);
# 2061 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 2064 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2065 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
getExactAlignments(ctx, page, true);
# 2066 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2068 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
flushOutput();
# 2069 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unloadQueries(ctx);
# 2070 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 2071 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2073 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int getFreeDeviceMemory(bool on_cpu)
# 2074 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2075 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned free_mem = (0);
# 2076 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned total_mem = (0);
# 2080 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int *p = (__null);
# 2081 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMalloc((void **)(&p), sizeof(int)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 2081, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 2082 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(p); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 2082, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 2083 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (!on_cpu) {
# 2085 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
boardMemory(&free_mem, &total_mem);
# 2086 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", free_mem, total_mem);
# 2088 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
} else
# 2089 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2090 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
total_mem = (free_mem = (804585472));
# 2091 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2093 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return free_mem;
# 2094 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2096 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int matchQueriesToReferencePage(MatchContext *ctx, ReferencePage *page)
# 2097 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2098 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Beginning reference page %p\n", page);
# 2100 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int free_mem = getFreeDeviceMemory(ctx->on_cpu);
# 2102 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int available_mem = ((free_mem - ((page->ref).bytes_on_board)) - ((16 * 1024) * 1024));
# 2103 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(ctx->ref) = (&(page->ref));
# 2104 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadReference(ctx);
# 2106 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
while (getQueryBlock(ctx, available_mem)) {
# 2107 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchSubset(ctx, page);
# 2108 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).bp_avg_query_length) = ((((ctx->queries)->texlen) / ((float)((ctx->queries)->count))) - (2));
# 2110 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
destroyQueryBlock(ctx->queries);
# 2111 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (num_bind_tex_calls > (100))
# 2112 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
{
# 2113 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
cudaThreadExit();
# 2114 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
num_bind_tex_calls = (0);
# 2115 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
loadReference(ctx);
# 2116 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2117 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2119 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unloadReferenceString(ctx->ref);
# 2120 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unloadReferenceTree(ctx);
# 2121 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
lseek((ctx->queries)->qfile, 0, 0);
# 2122 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 2123 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2127 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
void initReferencePages(MatchContext *ctx, int *num_pages, ReferencePage **pages_out) {
# 2128 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned bases_in_ref = ((ctx->full_ref_len) - (3));
# 2129 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned page_size = (((8388608) < bases_in_ref) ? (8388608) : bases_in_ref);
# 2131 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned num_reference_pages = (ceil((bases_in_ref + (0.0)) / page_size));
# 2132 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Stream will use %d pages for %d bases, page size = %d\n", num_reference_pages, bases_in_ref, page_size);
# 2135 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
unsigned page_overlap = (MAX_QUERY_LEN + 1);
# 2136 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
ReferencePage *pages = ((ReferencePage *)calloc(num_reference_pages, sizeof(ReferencePage)));
# 2139 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[0]).begin) = 1;
# 2140 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[0]).end) = (((((pages[0]).begin) + page_size) + ceil(page_overlap / (2.0))) + (1));
# 2143 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[0]).shadow_left) = (-1);
# 2144 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[0]).id) = (0);
# 2146 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 1; i < (num_reference_pages - (1)); ++i) {
# 2147 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[i]).begin) = (((pages[i - 1]).end) - page_overlap);
# 2148 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[i]).end) = ((((pages[i]).begin) + page_size) + page_overlap);
# 2149 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[i - 1]).shadow_right) = ((pages[i]).begin);
# 2150 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[i]).shadow_left) = ((pages[i - 1]).end);
# 2151 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[i]).id) = i;
# 2152 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2154 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (num_reference_pages > (1)) {
# 2155 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int last_page = (num_reference_pages - (1));
# 2156 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page]).begin) = (((pages[last_page - 1]).end) - page_overlap);
# 2157 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page]).end) = ((ctx->full_ref_len) - (1));
# 2158 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page - 1]).shadow_right) = ((pages[last_page]).begin);
# 2159 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page]).shadow_right) = (-1);
# 2160 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page]).shadow_left) = ((pages[last_page - 1]).end);
# 2161 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((pages[last_page]).id) = last_page;
# 2162 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2164 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*pages_out) = pages;
# 2165 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(*num_pages) = num_reference_pages;
# 2166 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2168 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int streamReferenceAgainstQueries(MatchContext *ctx) {
# 2169 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int num_reference_pages = 0;
# 2170 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
ReferencePage *pages = (__null);
# 2171 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
initReferencePages(ctx, &num_reference_pages, &pages);
# 2174 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
buildReferenceTexture(&((pages[0]).ref), ctx->full_ref, (pages[0]).begin, (pages[0]).end, ctx->min_match_length, ctx->dotfilename, ctx->texfilename, &(ctx->statistics));
# 2184 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[0]));
# 2185 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
destroyReference(&((pages[0]).ref));
# 2187 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
for (int i = 1; i < (num_reference_pages - 1); ++i) {
# 2189 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
buildReferenceTexture(&((pages[i]).ref), ctx->full_ref, (pages[i]).begin, (pages[i]).end, ctx->min_match_length, __null, __null, &(ctx->statistics));
# 2198 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[i]));
# 2199 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
destroyReference(&((pages[i]).ref));
# 2200 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2202 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
if (num_reference_pages > 1) {
# 2203 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int last_page = (num_reference_pages - 1);
# 2204 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
buildReferenceTexture(&((pages[last_page]).ref), ctx->full_ref, (pages[last_page]).begin, (pages[last_page]).end, ctx->min_match_length, __null, __null, &(ctx->statistics));
# 2213 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[last_page]));
# 2214 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
destroyReference(&((pages[last_page]).ref));
# 2215 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2216 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
free(pages);
# 2217 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return 0;
# 2218 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 2222 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
extern "C" int matchQueries(MatchContext *ctx) {
# 2223 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(sizeof(PixelOfNode) == sizeof(uint4)) ? (static_cast< void>(0)) : __assert_fail("sizeof(struct PixelOfNode) == sizeof(uint4)", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 2223, __PRETTY_FUNCTION__);
# 2224 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
(sizeof(PixelOfChildren) == sizeof(uint4)) ? (static_cast< void>(0)) : __assert_fail("sizeof(struct PixelOfChildren) == sizeof(uint4)", "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu", 2224, __PRETTY_FUNCTION__);
# 2231 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
resetStats(&(ctx->statistics));
# 2233 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
char *ttimer = createTimer();
# 2234 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
startTimer(ttimer);
# 2236 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
int ret;
# 2238 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
fprintf(stderr, "Streaming reference pages against all queries\n");
# 2239 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
ret = streamReferenceAgainstQueries(ctx);
# 2241 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
stopTimer(ttimer);
# 2242 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
((ctx->statistics).t_end_to_end) += getTimerValue(ttimer);
# 2243 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
deleteTimer(ttimer);
# 2245 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
writeStatisticsFile(&(ctx->statistics), ctx->stats_file, (char *)("node_hist.out"), (char *)("child_hist.out"));
# 2247 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
return ret;
# 2248 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu.cu"
}
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c"
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c" 1
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
# 2 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_000027c9_00000000-3_mummergpu.fatbin.c" 1
asm(
".section .rodata\n"
".align 32\n"
"fatbinData:\n"
".quad 0x00100001ba55ed50,0x000000000000d326,0x0000009001000001,0x000000000000ae7a\n"
".quad 0x0000003800000000,0x0000001400020003,0x0000004a00000040,0x0000000000000015\n"
".quad 0x0000000000000000,0x0000000000000000,0x6f6e2f656d6f682f,0x6568632f6c616d72\n"
".quad 0x70672f74756f6b63,0x2f746f6c65636f75,0x6f722f7374736574,0x65742f61696e6964\n"
".quad 0x6d6d756d2f737473,0x756d2f7570677265,0x2e75706772656d6d,0x0000000000007563\n"
".quad 0x6f69737265762e09,0x2e090a332e32206e,0x7320746567726174,0x612e090a30325f6d\n"
".quad 0x735f737365726464,0x090a343620657a69,0x69706d6f63202f2f,0x687469772064656c\n"
".quad 0x6f6c2f7273752f20,0x616475632f6c6163,0x2f34366e65706f2f,0x0a65622f2f62696c\n"
".quad 0x706f766e202f2f09,0x302e342063636e65,0x6f20746c69756220,0x302d31313032206e\n"
".quad 0x2e090a0a38312d32,0x20656c6269736976,0x2e2820636e75662e,0x732e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6674657261,0x6469327264646137,0x6461375a5f20296a\n"
".quad 0x28206a6469327264,0x2e206d617261702e,0x75635f5f20323375,0x31666d7261706164\n"
".quad 0x72646461375a5f5f,0x090a0a296a646932,0x656c62697369762e,0x2820636e75662e20\n"
".quad 0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e,0x695f667465726164\n"
".quad 0x345b726464613264,0x646132646920295d,0x7261702e28207264,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x3264695f31666d72,0x090a0a2972646461,0x656c62697369762e\n"
".quad 0x5f20636e75662e20,0x796172726134315a,0x7365726464416f54,0x3372616863753673\n"
".quad 0x7261702e28206a52,0x67696c612e206d61,0x2038622e2031206e,0x6170616475635f5f\n"
".quad 0x315a5f5f31666d72,0x6f54796172726134,0x3673736572646441,0x6a52337261686375\n"
".quad 0x61702e202c5d335b,0x3436752e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261\n"
".quad 0x5479617272613431,0x737365726464416f,0x5233726168637536,0x69762e090a0a296a\n"
".quad 0x662e20656c626973,0x61702e2820636e75,0x3233732e206d6172,0x72616475635f5f20\n"
".quad 0x72325a5f5f667465,0x72325a5f20296363,0x7261702e28206363,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x325a5f5f31666d72,0x2e090a0a29636372,0x20656c6269736976\n"
".quad 0x2e2820636e75662e,0x612e206d61726170,0x203631206e67696c,0x75635f5f2038622e\n"
".quad 0x5f5f667465726164,0x646f4e746567375a,0x295d36315b626a65,0x4e746567375a5f20\n"
".quad 0x2e2820626a65646f,0x752e206d61726170,0x6475635f5f203233,0x5f31666d72617061\n"
".quad 0x6f4e746567375a5f,0x702e202c626a6564,0x33732e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f32666d726170,0x646f4e746567375a,0x2e090a0a29626a65,0x20656c6269736976\n"
".quad 0x2e2820636e75662e,0x612e206d61726170,0x203631206e67696c,0x75635f5f2038622e\n"
".quad 0x5f5f667465726164,0x684374656731315a,0x626a6e6572646c69,0x5a5f20295d36315b\n"
".quad 0x6968437465673131,0x20626a6e6572646c,0x206d617261702e28,0x635f5f203233752e\n"
".quad 0x666d726170616475,0x656731315a5f5f31,0x6572646c69684374,0x61702e202c626a6e\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x5a5f5f32666d7261,0x6968437465673131\n"
".quad 0x29626a6e6572646c,0x697369762e090a0a,0x6e75662e20656c62,0x657330315a5f2063\n"
".quad 0x746c757365725f74,0x74614d5f3131506a,0x6964726f6f436863,0x61702e2820696969\n"
".quad 0x3233752e206d6172,0x70616475635f5f20,0x5a5f5f31666d7261,0x65725f7465733031\n"
".quad 0x3131506a746c7573,0x6f43686374614d5f,0x2c6969696964726f,0x206d617261702e20\n"
".quad 0x635f5f203436752e,0x666d726170616475,0x657330315a5f5f32,0x746c757365725f74\n"
".quad 0x74614d5f3131506a,0x6964726f6f436863,0x61702e202c696969,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f33666d7261,0x65725f7465733031,0x3131506a746c7573\n"
".quad 0x6f43686374614d5f,0x2c6969696964726f,0x206d617261702e20,0x635f5f203233732e\n"
".quad 0x666d726170616475,0x657330315a5f5f34,0x746c757365725f74,0x74614d5f3131506a\n"
".quad 0x6964726f6f436863,0x61702e202c696969,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x5a5f5f35666d7261,0x65725f7465733031,0x3131506a746c7573,0x6f43686374614d5f\n"
".quad 0x2c6969696964726f,0x206d617261702e20,0x635f5f203233732e,0x666d726170616475\n"
".quad 0x657330315a5f5f36,0x746c757365725f74,0x74614d5f3131506a,0x6964726f6f436863\n"
".quad 0x2f090a0a29696969,0x2d2d2d2d2d2d2d2f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2f2f090a2d2d2d2d,0x696c69706d6f4320,0x2f706d742f20676e,0x305f746678706d74\n"
".quad 0x5f39633732303030,0x3030303030303030,0x656d6d756d5f372d,0x7070632e75706772\n"
".quad 0x6d742f2820692e33,0x2e23494263632f70,0x0a2975436865484d,0x2d2d2d2d2d2f2f09\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a0a2d2d2d2d2d2d,0x2d2d2d2d2d2f2f09\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x090a2d2d2d2d2d2d,0x6f6974704f202f2f\n"
".quad 0x2d2f2f090a3a736e,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x20202f2f090a2d2d,0x703a746567726154,0x3a415349202c7874,0x45202c30325f6d73\n"
".quad 0x696c3a6e6169646e,0x6f50202c656c7474,0x6953207265746e69,0x2f090a34363a657a\n"
".quad 0x2809334f2d20202f,0x617a696d6974704f,0x76656c206e6f6974,0x202f2f090a296c65\n"
".quad 0x6544280930672d20,0x6576656c20677562,0x20202f2f090a296c,0x7065522809326d2d\n"
".quad 0x697664612074726f,0x0a29736569726f73,0x2d2d2d2d2d2f2f09,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x0a0a2d2d2d2d2d2d,0x3109656c69662e09,0x616d6d6f633c2209\n"
".quad 0x3e656e696c2d646e,0x656c69662e090a22,0x706d742f22093209,0x5f746678706d742f\n"
".quad 0x3963373230303030,0x303030303030305f,0x6d6d756d5f362d30,0x75632e7570677265\n"
".quad 0x70672e3265666164,0x6c69662e090a2275,0x6f682f2209330965,0x616d726f6e2f656d\n"
".quad 0x6f6b636568632f6c,0x636f7570672f7475,0x7365742f746f6c65,0x6e69646f722f7374\n"
".quad 0x73747365742f6169,0x6772656d6d756d2f,0x6f6d6d6f632f7570,0x090a226875632e6e\n"
".quad 0x093409656c69662e,0x6e2f656d6f682f22,0x68632f6c616d726f,0x672f74756f6b6365\n"
".quad 0x746f6c65636f7570,0x722f73747365742f,0x742f61696e69646f,0x6d756d2f73747365\n"
".quad 0x6d2f75706772656d,0x75706772656d6d75,0x69662e090a22682e,0x682f22093509656c\n"
".quad 0x6d726f6e2f656d6f,0x6b636568632f6c61,0x6f7570672f74756f,0x65742f746f6c6563\n"
".quad 0x69646f722f737473,0x747365742f61696e,0x72656d6d756d2f73,0x6d6d756d2f757067\n"
".quad 0x656b5f7570677265,0x6875632e6c656e72,0x656c69662e090a22,0x7273752f22093609\n"
".quad 0x6363672f62696c2f,0x2d34365f3638782f,0x6e672d78756e696c,0x2f352e342e342f75\n"
".quad 0x2f6564756c636e69,0x682e666564647473,0x656c69662e090a22,0x7273752f22093709\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x642f7472632f6564\n"
".quad 0x75725f6563697665,0x22682e656d69746e,0x09656c69662e090a,0x2f7273752f220938\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x645f74736f682f65\n"
".quad 0x682e73656e696665,0x656c69662e090a22,0x7273752f22093909,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x746c6975622f6564,0x73657079745f6e69\n"
".quad 0x69662e090a22682e,0x2f2209303109656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x65642f6564756c63,0x7079745f65636976,0x2e090a22682e7365\n"
".quad 0x09313109656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x745f726576697264,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220932,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x6361667275732f65,0x2e73657079745f65,0x6c69662e090a2268,0x752f220933310965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x7865742f6564756c\n"
".quad 0x7079745f65727574,0x2e090a22682e7365,0x09343109656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x745f726f74636576\n"
".quad 0x0a22682e73657079,0x3109656c69662e09,0x2f7273752f220935,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65,0x5f68636e75616c5f\n"
".quad 0x6574656d61726170,0x2e090a22682e7372,0x09363109656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x726f74732f747263\n"
".quad 0x73616c635f656761,0x662e090a22682e73,0x2209373109656c69,0x636e692f7273752f\n"
".quad 0x7469622f6564756c,0x2e73657079742f73,0x6c69662e090a2268,0x752f220938310965\n"
".quad 0x756c636e692f7273,0x2e656d69742f6564,0x6c69662e090a2268,0x752f220939310965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x6d6f632f6564756c\n"
".quad 0x636e75665f6e6f6d,0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093032\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x5f6874616d2f6564\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209313209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x736e6f635f687461\n"
".quad 0x22682e73746e6174,0x09656c69662e090a,0x7273752f22093232,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x63697665642f6564,0x6974636e75665f65\n"
".quad 0x090a22682e736e6f,0x333209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x615f31315f6d732f,0x75665f63696d6f74\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220934320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x696d6f74615f3231\n"
".quad 0x6974636e75665f63,0x090a22682e736e6f,0x353209656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x645f33315f6d732f\n"
".quad 0x75665f656c62756f,0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220936320965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c\n"
".quad 0x696d6f74615f3032,0x6974636e75665f63,0x090a22682e736e6f,0x373209656c69662e\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x695f30325f6d732f,0x6369736e6972746e,0x662e090a22682e73,0x2209383209656c69\n"
".quad 0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962,0x732f6564756c636e\n"
".quad 0x665f656361667275,0x736e6f6974636e75,0x69662e090a22682e,0x2f2209393209656c\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x65742f6564756c63\n"
".quad 0x65665f6572757478,0x636e75665f686374,0x22682e736e6f6974,0x09656c69662e090a\n"
".quad 0x7273752f22093033,0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x5f6874616d2f6564,0x6e6f6974636e7566,0x74705f6c62645f73,0x0a0a0a22682e3378\n"
".quad 0x6c62697369762e09,0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e\n"
".quad 0x5f66746572616475,0x3272646461375a5f,0x375a5f20296a6469,0x6a64693272646461\n"
".quad 0x6d617261702e2820,0x5f5f203233752e20,0x6d72617061647563,0x6461375a5f5f3166\n"
".quad 0x0a296a6469327264,0x6765722e090a7b09,0x7225203233752e20,0x2e090a3b3e32313c\n"
".quad 0x3232093509636f6c,0x57444c240a300938,0x5a5f5f6e69676562,0x6469327264646137\n"
".quad 0x702e646c090a3a6a,0x3233752e6d617261,0x5b202c3172250920,0x6170616475635f5f\n"
".quad 0x375a5f5f31666d72,0x6a64693272646461,0x2e766f6d090a3b5d,0x3272250920323373\n"
".quad 0x090a3b317225202c,0x32093509636f6c2e,0x6873090a30093434,0x2509203233752e72\n"
".quad 0x2c327225202c3372,0x6873090a3b313220,0x2509203233622e6c,0x2c337225202c3472\n"
".quad 0x6e61090a3b373120,0x2509203233622e64,0x2c327225202c3572,0x0a3b353335353620\n"
".quad 0x3233622e6c687309,0x25202c3672250920,0x090a3b35202c3572,0x203233622e6c6873\n"
".quad 0x7225202c37722509,0x090a3b3131202c32,0x203233752e726873,0x7225202c38722509\n"
".quad 0x090a3b3732202c37,0x203233752e646461,0x7225202c39722509,0x0a3b387225202c36\n"
".quad 0x3233732e64646109,0x202c303172250920,0x397225202c347225,0x61702e7473090a3b\n"
".quad 0x203233732e6d6172,0x616475635f5f5b09,0x375a5f5f66746572,0x6a64693272646461\n"
".quad 0x3b30317225202c5d,0x240a3b746572090a,0x5f5f646e6557444c,0x693272646461375a\n"
".quad 0x2f207d090a3a6a64,0x646461375a5f202f,0x090a0a6a64693272,0x656c62697369762e\n"
".quad 0x2820636e75662e20,0x2e206d617261702e,0x2034206e67696c61,0x75635f5f2038622e\n"
".quad 0x695f667465726164,0x345b726464613264,0x646132646920295d,0x7261702e28207264\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x3264695f31666d72,0x7b090a2972646461\n"
".quad 0x2e206765722e090a,0x323c722520323375,0x6f6c2e090a3b3e34,0x0934353209350963\n"
".quad 0x656257444c240a30,0x613264695f6e6967,0x646c090a3a726464,0x752e6d617261702e\n"
".quad 0x2c31722509203233,0x616475635f5f5b20,0x695f31666d726170,0x3b5d726464613264\n"
".quad 0x33732e766f6d090a,0x202c327225092032,0x6c2e090a3b317225,0x353732093509636f\n"
".quad 0x2e766f6d090a3009,0x3372250920323373,0x090a3b327225202c,0x203233732e726873\n"
".quad 0x7225202c34722509,0x090a3b3731202c32,0x203233622e646e61,0x7225202c35722509\n"
".quad 0x090a3b3133202c33,0x203233622e6c6873,0x7225202c36722509,0x61090a3b35202c34\n"
".quad 0x09203233732e6464,0x357225202c377225,0x090a3b367225202c,0x203233732e766f6d\n"
".quad 0x7225202c38722509,0x2e747663090a3b37,0x203233752e363175,0x7225202c39722509\n"
".quad 0x2e766f6d090a3b38,0x3172250920323375,0x61090a3b30202c30,0x09203233622e646e\n"
".quad 0x7225202c31317225,0x3533353536202c39,0x622e6c6873090a3b,0x3231722509203233\n"
".quad 0x202c31317225202c,0x2e726f090a3b3631,0x3172250920323362,0x2c32317225202c33\n"
".quad 0x6f6c2e090a3b3020,0x0936373209350963,0x732e726873090a30,0x3431722509203233\n"
".quad 0x35202c327225202c,0x622e646e61090a3b,0x3531722509203233,0x202c34317225202c\n"
".quad 0x6d090a3b35393034,0x09203233732e766f,0x7225202c36317225,0x6f6c2e090a3b3531\n"
".quad 0x0933383209350963,0x622e646e61090a30,0x3731722509203233,0x202c33317225202c\n"
".quad 0x0a3b36333535362d,0x3233622e646e6109,0x202c383172250920,0x3536202c36317225\n"
".quad 0x6f6d090a3b353335,0x2509203233752e76,0x317225202c393172,0x622e726f090a3b38\n"
".quad 0x3032722509203233,0x202c37317225202c,0x73090a3b39317225,0x2e6d617261702e74\n"
".quad 0x5f5f5b0920323375,0x6674657261647563,0x726464613264695f,0x327225202c5d302b\n"
".quad 0x2e766f6d090a3b30,0x3272250920323373,0x3b36317225202c31,0x7261702e7473090a\n"
".quad 0x09203631752e6d61,0x72616475635f5f5b,0x613264695f667465,0x202c5d302b726464\n"
".quad 0x6d090a3b31327225,0x09203233732e766f,0x7225202c32327225,0x702e7473090a3b39\n"
".quad 0x3631752e6d617261,0x6475635f5f5b0920,0x64695f6674657261,0x5d322b7264646132\n"
".quad 0x0a3b32327225202c,0x4c240a3b74657209,0x64695f646e655744,0x090a3a7264646132\n"
".quad 0x326469202f2f207d,0x2e090a0a72646461,0x20656c6269736976,0x5a5f20636e75662e\n"
".quad 0x5479617272613431,0x737365726464416f,0x5233726168637536,0x617261702e28206a\n"
".quad 0x6e67696c612e206d,0x5f2038622e203120,0x726170616475635f,0x34315a5f5f31666d\n"
".quad 0x416f547961727261,0x7536737365726464,0x5b6a523372616863,0x7261702e202c5d33\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x315a5f5f32666d72,0x6f54796172726134\n"
".quad 0x3673736572646441,0x6a52337261686375,0x722e090a7b090a29,0x203631752e206765\n"
".quad 0x0a3b3e353c687225,0x752e206765722e09,0x36313c7225203233,0x6765722e090a3b3e\n"
".quad 0x7225203436752e20,0x2e090a3b3e343c64,0x3932093509636f6c,0x57444c240a300933\n"
".quad 0x5a5f5f6e69676562,0x5479617272613431,0x737365726464416f,0x5233726168637536\n"
".quad 0x702e646c090a3a6a,0x2038752e6d617261,0x5f5b202c31722509,0x726170616475635f\n"
".quad 0x34315a5f5f31666d,0x416f547961727261,0x7536737365726464,0x2b6a523372616863\n"
".quad 0x747663090a3b5d30,0x203233752e38752e,0x25202c3168722509,0x2e646c090a3b3172\n"
".quad 0x38752e6d61726170,0x5b202c3272250920,0x6170616475635f5f,0x315a5f5f31666d72\n"
".quad 0x6f54796172726134,0x3673736572646441,0x6a52337261686375,0x7663090a3b5d312b\n"
".quad 0x3233752e38752e74,0x202c326872250920,0x646c090a3b327225,0x752e6d617261702e\n"
".quad 0x202c337225092038,0x70616475635f5f5b,0x5a5f5f31666d7261,0x5479617272613431\n"
".quad 0x737365726464416f,0x5233726168637536,0x63090a3b5d322b6a,0x33752e38752e7476\n"
".quad 0x2c33687225092032,0x6c090a3b33722520,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x75635f5f5b202c31,0x32666d7261706164,0x72726134315a5f5f,0x726464416f547961\n"
".quad 0x6168637536737365,0x090a3b5d6a523372,0x203436732e766f6d,0x25202c3264722509\n"
".quad 0x6c2e090a3b316472,0x363932093509636f,0x2e747663090a3009,0x092038752e323375\n"
".quad 0x687225202c347225,0x2e747663090a3b33,0x092038752e323375,0x687225202c357225\n"
".quad 0x2e646e61090a3b31,0x3672250920323362,0x31202c347225202c,0x2e6c6873090a3b35\n"
".quad 0x3772250920323362,0x38202c367225202c,0x33622e726f090a3b,0x202c387225092032\n"
".quad 0x377225202c357225,0x752e747663090a3b,0x25092038752e3233,0x32687225202c3972\n"
".quad 0x622e646e61090a3b,0x3031722509203233,0x32202c347225202c,0x6c6873090a3b3034\n"
".quad 0x722509203233622e,0x30317225202c3131,0x726f090a3b34202c,0x722509203233622e\n"
".quad 0x2c397225202c3231,0x090a3b3131722520,0x203233622e6c6873,0x25202c3331722509\n"
".quad 0x3b3631202c323172,0x3233622e726f090a,0x202c343172250920,0x317225202c387225\n"
".quad 0x752e7473090a3b33,0x6472255b09203233,0x7225202c5d302b32,0x6f6c2e090a3b3431\n"
".quad 0x0930303309350963,0x0a3b746572090a30,0x5f646e6557444c24,0x6172726134315a5f\n"
".quad 0x65726464416f5479,0x7261686375367373,0x207d090a3a6a5233,0x6134315a5f202f2f\n"
".quad 0x64416f5479617272,0x6375367373657264,0x0a0a6a5233726168,0x6c62697369762e09\n"
".quad 0x20636e75662e2065,0x206d617261702e28,0x635f5f203233732e,0x5f66746572616475\n"
".quad 0x2029636372325a5f,0x2820636372325a5f,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x31666d7261706164,0x29636372325a5f5f,0x65722e090a7b090a,0x25203233752e2067\n"
".quad 0x090a3b3e31313c72,0x72702e206765722e,0x3e373c7025206465,0x09636f6c2e090a3b\n"
".quad 0x0a30093633330935,0x6967656257444c24,0x636372325a5f5f6e,0x61702e646c090a3a\n"
".quad 0x203233752e6d6172,0x5f5b202c31722509,0x726170616475635f,0x72325a5f5f31666d\n"
".quad 0x7663090a3b5d6363,0x3233732e38732e74,0x25202c3272250920,0x6f6c2e090a3b3172\n"
".quad 0x0938333309350963,0x752e766f6d090a30,0x2c33722509203233,0x6573090a3b353620\n"
".quad 0x33732e71652e7074,0x202c317025092032,0x337225202c327225,0x2031702540090a3b\n"
".quad 0x744c240920617262,0x0a3b3835325f335f,0x3233752e766f6d09,0x36202c3472250920\n"
".quad 0x70746573090a3b37,0x203233732e71652e,0x7225202c32702509,0x0a3b347225202c32\n"
".quad 0x7262203270254009,0x335f744c24092061,0x6d090a3b3431355f,0x09203233752e766f\n"
".quad 0x3b3137202c357225,0x652e70746573090a,0x2509203233732e71,0x2c327225202c3370\n"
".quad 0x40090a3b35722520,0x2061726220337025,0x375f335f744c2409,0x766f6d090a3b3037\n"
".quad 0x722509203233752e,0x090a3b3438202c36,0x2e71652e70746573,0x3470250920323373\n"
".quad 0x25202c327225202c,0x702540090a3b3672,0x2409206172622034,0x3230315f335f744c\n"
".quad 0x2e766f6d090a3b36,0x3772250920323375,0x090a3b333131202c,0x2e71652e70746573\n"
".quad 0x3570250920323373,0x25202c327225202c,0x702540090a3b3772,0x2409206172622035\n"
".quad 0x3832315f335f744c,0x2e617262090a3b32,0x744c240920696e75,0x3b383335315f335f\n"
".quad 0x325f335f744c240a,0x6f6c2e090a3a3835,0x0930343309350963,0x732e766f6d090a30\n"
".quad 0x2c38722509203233,0x7262090a3b343820,0x240920696e752e61,0x5a5f5f333142424c\n"
".quad 0x4c240a3b63637232,0x3a3431355f335f74,0x3509636f6c2e090a,0x090a300931343309\n"
".quad 0x203233732e766f6d,0x3137202c38722509,0x752e617262090a3b,0x42424c240920696e\n"
".quad 0x6372325a5f5f3331,0x335f744c240a3b63,0x2e090a3a3037375f,0x3433093509636f6c\n"
".quad 0x766f6d090a300932,0x722509203233732e,0x090a3b3736202c38,0x20696e752e617262\n"
".quad 0x5f333142424c2409,0x0a3b636372325a5f,0x30315f335f744c24,0x6f6c2e090a3a3632\n"
".quad 0x0933343309350963,0x732e766f6d090a30,0x2c38722509203233,0x7262090a3b353620\n"
".quad 0x240920696e752e61,0x5a5f5f333142424c,0x4c240a3b63637232,0x323832315f335f74\n"
".quad 0x09636f6c2e090a3a,0x0a30093434330935,0x3233732e766f6d09,0x30202c3872250920\n"
".quad 0x752e617262090a3b,0x42424c240920696e,0x6372325a5f5f3331,0x335f744c240a3b63\n"
".quad 0x090a3a383335315f,0x33093509636f6c2e,0x6f6d090a30093534,0x2509203233732e76\n"
".quad 0x3b327225202c3872,0x5f333142424c240a,0x0a3a636372325a5f,0x3233732e766f6d09\n"
".quad 0x25202c3972250920,0x2e7473090a3b3872,0x33732e6d61726170,0x75635f5f5b092032\n"
".quad 0x5f5f667465726164,0x202c5d636372325a,0x6572090a3b397225,0x6557444c240a3b74\n"
".quad 0x6372325a5f5f646e,0x2f2f207d090a3a63,0x0a636372325a5f20,0x6c61626f6c672e09\n"
".quad 0x6665727865742e20,0x78657465646f6e20,0x7369762e090a0a3b,0x75662e20656c6269\n"
".quad 0x7261702e2820636e,0x67696c612e206d61,0x38622e203631206e,0x72616475635f5f20\n"
".quad 0x67375a5f5f667465,0x626a65646f4e7465,0x5a5f20295d36315b,0x65646f4e74656737\n"
".quad 0x7261702e2820626a,0x203233752e206d61,0x6170616475635f5f,0x375a5f5f31666d72\n"
".quad 0x6a65646f4e746567,0x617261702e202c62,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x67375a5f5f32666d,0x626a65646f4e7465,0x722e090a7b090a29,0x203233752e206765\n"
".quad 0x0a3b3e38313c7225,0x662e206765722e09,0x30313c6625203233,0x636f6c2e090a3b3e\n"
".quad 0x3009343533093509,0x67656257444c240a,0x6567375a5f5f6e69,0x3a626a65646f4e74\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563\n"
".quad 0x6567375a5f5f3166,0x5d626a65646f4e74,0x732e766f6d090a3b,0x2c32722509203233\n"
".quad 0x61090a3b31722520,0x09203233622e646e,0x327225202c337225,0x3b3533353536202c\n"
".quad 0x6e722e747663090a,0x3233752e3233662e,0x25202c3166250920,0x766f6d090a3b3372\n"
".quad 0x662509203233662e,0x0a3b316625202c32,0x3233752e72687309,0x25202c3472250920\n"
".quad 0x0a3b3631202c3272,0x2e6e722e74766309,0x203233752e323366,0x7225202c33662509\n"
".quad 0x2e766f6d090a3b34,0x3466250920323366,0x090a3b336625202c,0x203233662e766f6d\n"
".quad 0x6630202c35662509,0x3030303030303030,0x2f0920202020203b,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x0a3b356625202c36,0x3233662e766f6d09,0x30202c3766250920\n"
".quad 0x3030303030303066,0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x3b376625202c3866,0x64322e786574090a,0x2e3233752e34762e,0x3572257b20323366\n"
".quad 0x3772252c3672252c,0x6e5b2c7d3872252c,0x7b2c78657465646f,0x2c3466252c326625\n"
".quad 0x7d3866252c366625,0x636f6c2e090a3b5d,0x3009353733093509,0x33732e766f6d090a\n"
".quad 0x202c397225092032,0x6f6d090a3b357225,0x2509203233732e76,0x367225202c303172\n"
".quad 0x732e766f6d090a3b,0x3131722509203233,0x090a3b377225202c,0x203233732e766f6d\n"
".quad 0x25202c3231722509,0x766f6d090a3b3872,0x722509203233732e,0x3b397225202c3331\n"
".quad 0x7261702e7473090a,0x09203233752e6d61,0x72616475635f5f5b,0x67375a5f5f667465\n"
".quad 0x626a65646f4e7465,0x317225202c5d302b,0x2e766f6d090a3b33,0x3172250920323373\n"
".quad 0x3b30317225202c34,0x7261702e7473090a,0x09203233752e6d61,0x72616475635f5f5b\n"
".quad 0x67375a5f5f667465,0x626a65646f4e7465,0x317225202c5d342b,0x2e766f6d090a3b34\n"
".quad 0x3172250920323373,0x3b31317225202c35,0x7261702e7473090a,0x09203233752e6d61\n"
".quad 0x72616475635f5f5b,0x67375a5f5f667465,0x626a65646f4e7465,0x317225202c5d382b\n"
".quad 0x2e766f6d090a3b35,0x3172250920323373,0x3b32317225202c36,0x7261702e7473090a\n"
".quad 0x09203233752e6d61,0x72616475635f5f5b,0x67375a5f5f667465,0x626a65646f4e7465\n"
".quad 0x7225202c5d32312b,0x746572090a3b3631,0x6e6557444c240a3b,0x746567375a5f5f64\n"
".quad 0x0a3a626a65646f4e,0x5a5f202f2f207d09,0x65646f4e74656737,0x6f6c672e090a626a\n"
".quad 0x7865742e206c6162,0x6c69686320666572,0x3b7865746e657264,0x697369762e090a0a\n"
".quad 0x6e75662e20656c62,0x617261702e282063,0x6e67696c612e206d,0x2038622e20363120\n"
".quad 0x6572616475635f5f,0x6731315a5f5f6674,0x72646c6968437465,0x5d36315b626a6e65\n"
".quad 0x656731315a5f2029,0x6572646c69684374,0x61702e2820626a6e,0x3233752e206d6172\n"
".quad 0x70616475635f5f20,0x5a5f5f31666d7261,0x6968437465673131,0x2c626a6e6572646c\n"
".quad 0x206d617261702e20,0x635f5f203233732e,0x666d726170616475,0x656731315a5f5f32\n"
".quad 0x6572646c69684374,0x0a7b090a29626a6e,0x752e206765722e09,0x38313c7225203233\n"
".quad 0x6765722e090a3b3e,0x6625203233662e20,0x2e090a3b3e30313c,0x3933093509636f6c\n"
".quad 0x57444c240a300937,0x5a5f5f6e69676562,0x6968437465673131,0x3a626a6e6572646c\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563\n"
".quad 0x6731315a5f5f3166,0x72646c6968437465,0x090a3b5d626a6e65,0x203233732e766f6d\n"
".quad 0x7225202c32722509,0x2e646e61090a3b31,0x3372250920323362,0x36202c327225202c\n"
".quad 0x63090a3b35333535,0x33662e6e722e7476,0x2509203233752e32,0x3b337225202c3166\n"
".quad 0x33662e766f6d090a,0x202c326625092032,0x6873090a3b316625,0x2509203233752e72\n"
".quad 0x2c327225202c3472,0x7663090a3b363120,0x3233662e6e722e74,0x662509203233752e\n"
".quad 0x0a3b347225202c33,0x3233662e766f6d09,0x25202c3466250920,0x766f6d090a3b3366\n"
".quad 0x662509203233662e,0x3030306630202c35,0x20203b3030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x202c366625092032,0x6f6d090a3b356625,0x2509203233662e76\n"
".quad 0x30306630202c3766,0x203b303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x2c38662509203233,0x74090a3b37662520,0x34762e64322e7865,0x3233662e3233752e\n"
".quad 0x72252c3572257b20,0x72252c3772252c36,0x6c6968635b2c7d38,0x2c7865746e657264\n"
".quad 0x3466252c3266257b,0x3866252c3666252c,0x6f6c2e090a3b5d7d,0x0938313409350963\n"
".quad 0x732e766f6d090a30,0x2c39722509203233,0x6d090a3b35722520,0x09203233732e766f\n"
".quad 0x7225202c30317225,0x2e766f6d090a3b36,0x3172250920323373,0x0a3b377225202c31\n"
".quad 0x3233732e766f6d09,0x202c323172250920,0x6f6d090a3b387225,0x2509203233732e76\n"
".quad 0x397225202c333172,0x61702e7473090a3b,0x203233752e6d6172,0x616475635f5f5b09\n"
".quad 0x315a5f5f66746572,0x6c69684374656731,0x302b626a6e657264,0x3b33317225202c5d\n"
".quad 0x33732e766f6d090a,0x2c34317225092032,0x090a3b3031722520,0x6d617261702e7473\n"
".quad 0x5f5b09203233752e,0x746572616475635f,0x656731315a5f5f66,0x6572646c69684374\n"
".quad 0x202c5d342b626a6e,0x6d090a3b34317225,0x09203233732e766f,0x7225202c35317225\n"
".quad 0x2e7473090a3b3131,0x33752e6d61726170,0x75635f5f5b092032,0x5f5f667465726164\n"
".quad 0x684374656731315a,0x626a6e6572646c69,0x317225202c5d382b,0x2e766f6d090a3b35\n"
".quad 0x3172250920323373,0x3b32317225202c36,0x7261702e7473090a,0x09203233752e6d61\n"
".quad 0x72616475635f5f5b,0x31315a5f5f667465,0x646c696843746567,0x32312b626a6e6572\n"
".quad 0x3b36317225202c5d,0x240a3b746572090a,0x5f5f646e6557444c,0x684374656731315a\n"
".quad 0x626a6e6572646c69,0x202f2f207d090a3a,0x4374656731315a5f,0x6a6e6572646c6968\n"
".quad 0x7369762e090a0a62,0x75662e20656c6269,0x7330315a5f20636e,0x6c757365725f7465\n"
".quad 0x614d5f3131506a74,0x64726f6f43686374,0x702e282069696969,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x5f5f31666d726170,0x725f74657330315a,0x31506a746c757365\n"
".quad 0x43686374614d5f31,0x6969696964726f6f,0x6d617261702e202c,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x7330315a5f5f3266,0x6c757365725f7465,0x614d5f3131506a74\n"
".quad 0x64726f6f43686374,0x702e202c69696969,0x33732e206d617261,0x616475635f5f2032\n"
".quad 0x5f5f33666d726170,0x725f74657330315a,0x31506a746c757365,0x43686374614d5f31\n"
".quad 0x6969696964726f6f,0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x7330315a5f5f3466,0x6c757365725f7465,0x614d5f3131506a74,0x64726f6f43686374\n"
".quad 0x702e202c69696969,0x33732e206d617261,0x616475635f5f2032,0x5f5f35666d726170\n"
".quad 0x725f74657330315a,0x31506a746c757365,0x43686374614d5f31,0x6969696964726f6f\n"
".quad 0x6d617261702e202c,0x5f5f203233732e20,0x6d72617061647563,0x7330315a5f5f3666\n"
".quad 0x6c757365725f7465,0x614d5f3131506a74,0x64726f6f43686374,0x7b090a2969696969\n"
".quad 0x2e206765722e090a,0x313c722520323375,0x65722e090a3b3e32,0x25203436752e2067\n"
".quad 0x090a3b3e343c6472,0x72702e206765722e,0x3e333c7025206465,0x09636f6c2e090a3b\n"
".quad 0x0a30093134360935,0x6967656257444c24,0x657330315a5f5f6e,0x746c757365725f74\n"
".quad 0x74614d5f3131506a,0x6964726f6f436863,0x646c090a3a696969,0x752e6d617261702e\n"
".quad 0x2c31722509203233,0x616475635f5f5b20,0x5f5f31666d726170,0x725f74657330315a\n"
".quad 0x31506a746c757365,0x43686374614d5f31,0x6969696964726f6f,0x2e766f6d090a3b5d\n"
".quad 0x3272250920323373,0x090a3b317225202c,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x635f5f5b202c3164,0x666d726170616475,0x657330315a5f5f32,0x746c757365725f74\n"
".quad 0x74614d5f3131506a,0x6964726f6f436863,0x6d090a3b5d696969,0x09203436732e766f\n"
".quad 0x7225202c32647225,0x2e646c090a3b3164,0x33752e6d61726170,0x202c337225092032\n"
".quad 0x70616475635f5f5b,0x5a5f5f33666d7261,0x65725f7465733031,0x3131506a746c7573\n"
".quad 0x6f43686374614d5f,0x5d6969696964726f,0x732e766f6d090a3b,0x2c34722509203233\n"
".quad 0x6c090a3b33722520,0x2e6d617261702e64,0x3572250920323375,0x6475635f5f5b202c\n"
".quad 0x5f34666d72617061,0x5f74657330315a5f,0x506a746c75736572,0x686374614d5f3131\n"
".quad 0x69696964726f6f43,0x766f6d090a3b5d69,0x722509203233732e,0x0a3b357225202c36\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3772,0x666d726170616475\n"
".quad 0x657330315a5f5f35,0x746c757365725f74,0x74614d5f3131506a,0x6964726f6f436863\n"
".quad 0x6d090a3b5d696969,0x09203233732e766f,0x377225202c387225,0x61702e646c090a3b\n"
".quad 0x203233752e6d6172,0x5f5b202c39722509,0x726170616475635f,0x30315a5f5f36666d\n"
".quad 0x757365725f746573,0x4d5f3131506a746c,0x726f6f4368637461,0x0a3b5d6969696964\n"
".quad 0x3233732e766f6d09,0x202c303172250920,0x6573090a3b397225,0x33732e656c2e7074\n"
".quad 0x202c317025092032,0x387225202c367225,0x2031702540090a3b,0x744c240920617262\n"
".quad 0x3b323635325f365f,0x3509636f6c2e090a,0x090a300934353609,0x09203233622e726f\n"
".quad 0x347225202c347225,0x0a3b30317225202c,0x732e32762e747309,0x6472255b09203233\n"
".quad 0x257b202c5d302b32,0x3b7d3472252c3272,0x325f365f744c240a,0x6c2e090a3a323635\n"
".quad 0x393636093509636f,0x3b746572090a3009,0x646e6557444c240a,0x74657330315a5f5f\n"
".quad 0x6a746c757365725f,0x6374614d5f313150,0x696964726f6f4368,0x2f207d090a3a6969\n"
".quad 0x657330315a5f202f,0x746c757365725f74,0x74614d5f3131506a,0x6964726f6f436863\n"
".quad 0x652e090a0a696969,0x315a5f207972746e,0x6772656d6d756d35,0x6c656e72654b7570\n"
".quad 0x505f305363507650,0x2069695f3253694b,0x7261702e09090a28,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x6d35315a5f5f6d72,0x75706772656d6d75,0x76506c656e72654b\n"
".quad 0x694b505f30536350,0x616d5f69695f3253,0x726f6f635f686374,0x702e09090a2c7364\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x315a5f5f6d726170,0x6772656d6d756d35\n"
".quad 0x6c656e72654b7570,0x505f305363507650,0x5f69695f3253694b,0x61705f6c61765f5f\n"
".quad 0x69726575716d6172,0x702e09090a2c7365,0x36752e206d617261,0x616475635f5f2034\n"
".quad 0x315a5f5f6d726170,0x6772656d6d756d35,0x6c656e72654b7570,0x505f305363507650\n"
".quad 0x5f69695f3253694b,0x2e09090a2c666572,0x752e206d61726170,0x6475635f5f203436\n"
".quad 0x5a5f5f6d72617061,0x72656d6d756d3531,0x656e72654b757067,0x5f3053635076506c\n"
".quad 0x69695f3253694b50,0x644179726575715f,0x2e09090a2c737264,0x752e206d61726170\n"
".quad 0x6475635f5f203436,0x5a5f5f6d72617061,0x72656d6d756d3531,0x656e72654b757067\n"
".quad 0x5f3053635076506c,0x69695f3253694b50,0x654c79726575715f,0x090a2c736874676e\n"
".quad 0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475,0x6d6d756d35315a5f\n"
".quad 0x72654b7570677265,0x53635076506c656e,0x5f3253694b505f30,0x75516d756e5f6969\n"
".quad 0x090a2c7365697265,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x6d6d756d35315a5f,0x72654b7570677265,0x53635076506c656e,0x5f3253694b505f30\n"
".quad 0x6d5f6e696d5f6969,0x6e656c5f68637461,0x722e090a7b090a29,0x203233752e206765\n"
".quad 0x3b3e3334313c7225,0x2e206765722e090a,0x3c64722520343675,0x722e090a3b3e3233\n"
".quad 0x203233662e206765,0x0a3b3e36323c6625,0x702e206765722e09,0x323c702520646572\n"
".quad 0x202f2f090a3b3e32,0x6c5f616475635f5f,0x7261765f6c61636f,0x315f33353234345f\n"
".quad 0x6f635f6e6f6e5f36,0x65646f6e5f74736e,0x3d2074726174735f,0x202f2f090a303220\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x325f34353234345f,0x6f635f6e6f6e5f32\n"
".quad 0x766572705f74736e,0x2e090a3631203d20,0x3037093509636f6c,0x57444c240a300935\n"
".quad 0x5a5f5f6e69676562,0x72656d6d756d3531,0x656e72654b757067,0x5f3053635076506c\n"
".quad 0x69695f3253694b50,0x752e766f6d090a3a,0x2c31722509203233,0x2e64696174632520\n"
".quad 0x2e766f6d090a3b78,0x3272250920323375,0x2e6469746e25202c,0x326c756d090a3b78\n"
".quad 0x3233752e6f6c2e34,0x25202c3372250920,0x3b327225202c3172,0x33752e766f6d090a\n"
".quad 0x202c347225092032,0x0a3b782e64697425,0x3233752e64646109,0x25202c3572250920\n"
".quad 0x3b337225202c3472,0x7261702e646c090a,0x09203233732e6d61,0x5f5f5b202c367225\n"
".quad 0x6d72617061647563,0x6d756d35315a5f5f,0x654b75706772656d,0x635076506c656e72\n"
".quad 0x3253694b505f3053,0x516d756e5f69695f,0x3b5d736569726575,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x2c367225202c3170,0x40090a3b35722520,0x2061726220317025\n"
".quad 0x335f375f744c2409,0x62090a3b30393431,0x0920696e752e6172,0x5f5f373442424c24\n"
".quad 0x656d6d756d35315a,0x6e72654b75706772,0x3053635076506c65,0x695f3253694b505f\n"
".quad 0x375f744c240a3b69,0x0a3a30393431335f,0x093509636f6c2e09,0x63090a3009313237\n"
".quad 0x732e3436732e7476,0x3164722509203233,0x090a3b357225202c,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x2c357225202c3264,0x2e646c090a3b3420,0x36752e6d61726170\n"
".quad 0x2c33647225092034,0x616475635f5f5b20,0x315a5f5f6d726170,0x6772656d6d756d35\n"
".quad 0x6c656e72654b7570,0x505f305363507650,0x5f69695f3253694b,0x6e654c7972657571\n"
".quad 0x090a3b5d73687467,0x203436752e646461,0x25202c3464722509,0x647225202c336472\n"
".quad 0x672e646c090a3b32,0x33732e6c61626f6c,0x202c377225092032,0x5d302b346472255b\n"
".quad 0x09636f6c2e090a3b,0x0a30093232370935,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5f5b202c356472,0x6d72617061647563,0x6d756d35315a5f5f,0x654b75706772656d\n"
".quad 0x635076506c656e72,0x3253694b505f3053,0x726575715f69695f,0x3b5d737264644179\n"
".quad 0x36752e646461090a,0x2c36647225092034,0x25202c3564722520,0x646c090a3b326472\n"
".quad 0x2e6c61626f6c672e,0x3872250920323373,0x2b366472255b202c,0x6f6c2e090a3b5d30\n"
".quad 0x0931333709350963,0x732e747663090a30,0x09203233732e3436,0x7225202c37647225\n"
".quad 0x702e646c090a3b38,0x3233732e6d617261,0x5b202c3972250920,0x6170616475635f5f\n"
".quad 0x6d35315a5f5f6d72,0x75706772656d6d75,0x76506c656e72654b,0x694b505f30536350\n"
".quad 0x696d5f69695f3253,0x5f686374616d5f6e,0x6c090a3b5d6e656c,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x75635f5f5b202c38,0x5f5f6d7261706164,0x656d6d756d35315a\n"
".quad 0x6e72654b75706772,0x3053635076506c65,0x695f3253694b505f,0x5f686374616d5f69\n"
".quad 0x3b5d7364726f6f63,0x69772e6c756d090a,0x09203233732e6564,0x7225202c39647225\n"
".quad 0x61090a3b38202c38,0x09203436752e6464,0x25202c3031647225,0x647225202c386472\n"
".quad 0x2e646461090a3b39,0x3172250920323375,0x202c397225202c30,0x326c756d090a3b31\n"
".quad 0x3233752e6f6c2e34,0x202c313172250920,0x317225202c357225,0x2e747663090a3b30\n"
".quad 0x203233752e343675,0x202c313164722509,0x6d090a3b31317225,0x2e656469772e6c75\n"
".quad 0x6472250920323375,0x31317225202c3231,0x7573090a3b38202c,0x2509203436752e62\n"
".quad 0x7225202c33316472,0x647225202c303164,0x627573090a3b3231,0x722509203233732e\n"
".quad 0x2c377225202c3231,0x6d090a3b39722520,0x09203233752e766f,0x3b30202c33317225\n"
".quad 0x6c2e70746573090a,0x2509203233732e74,0x32317225202c3270,0x0a3b33317225202c\n"
".quad 0x7262203270254009,0x3442424c24092061,0x756d35315a5f5f37,0x4b75706772656d6d\n"
".quad 0x5076506c656e7265,0x53694b505f305363,0x6c090a3b69695f32,0x2e6d617261702e64\n"
".quad 0x6472250920343675,0x635f5f5b202c3431,0x5f6d726170616475,0x6d6d756d35315a5f\n"
".quad 0x72654b7570677265,0x53635076506c656e,0x5f3253694b505f30,0x6c61765f5f5f6969\n"
".quad 0x75716d617261705f,0x0a3b5d7365697265,0x3436752e64646109,0x2c35316472250920\n"
".quad 0x25202c3764722520,0x61090a3b34316472,0x09203233732e6464,0x7225202c34317225\n"
".quad 0x090a3b31202c3231,0x203233732e766f6d,0x25202c3531722509,0x6f6d090a3b343172\n"
".quad 0x2509203233732e76,0x0a3b30202c363172,0x3233732e766f6d09,0x202c373172250920\n"
".quad 0x2e766f6d090a3b30,0x3172250920323373,0x6d090a3b30202c38,0x09203233752e766f\n"
".quad 0x3b30202c39317225,0x33732e766f6d090a,0x2c30327225092032,0x240a3b3531722520\n"
".quad 0x3532335f375f744c,0x3c2f2f200a3a3431,0x6f4c203e706f6f6c,0x2079646f6220706f\n"
".quad 0x31333720656e696c,0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120\n"
".quad 0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a,0x732e766f6d090a6e\n"
".quad 0x3132722509203233,0x6573090a3b30202c,0x3233752e656c2e74,0x722509203233732e\n"
".quad 0x37317225202c3232,0x0a3b31327225202c,0x3233732e67656e09,0x202c333272250920\n"
".quad 0x6d090a3b32327225,0x09203233752e766f,0x3b30202c34327225,0x71652e746573090a\n"
".quad 0x3233752e3233752e,0x202c353272250920,0x7225202c39317225,0x67656e090a3b3432\n"
".quad 0x722509203233732e,0x35327225202c3632,0x33622e726f090a3b,0x2c37327225092032\n"
".quad 0x25202c3332722520,0x6f6d090a3b363272,0x2509203233752e76,0x0a3b30202c383272\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c37327225202c33,0x090a3b3832722520\n"
".quad 0x6172622033702540,0x5f375f744c240920,0x090a3b3037373233,0x203233732e766f6d\n"
".quad 0x31202c3731722509,0x732e766f6d090a3b,0x3831722509203233,0x6f6d090a3b30202c\n"
".quad 0x2509203233752e76,0x353536202c393172,0x5f744c240a3b3633,0x3a30373732335f37\n"
".quad 0x3509636f6c2e090a,0x090a300933353709,0x203233732e646461,0x25202c3932722509\n"
".quad 0x317225202c363172,0x2e747663090a3b37,0x203233732e343675,0x202c363164722509\n"
".quad 0x61090a3b39327225,0x09203436732e6464,0x25202c3731647225,0x7225202c36316472\n"
".quad 0x646c090a3b353164,0x2e6c61626f6c672e,0x3033722509203873,0x37316472255b202c\n"
".quad 0x6f6d090a3b5d302b,0x2509203233752e76,0x0a3b30202c313372,0x71652e7074657309\n"
".quad 0x702509203233732e,0x2c30337225202c34,0x090a3b3133722520,0x6172622034702540\n"
".quad 0x5f375f744c240920,0x240a3b3837333733,0x3733335f375f744c,0x6f6c2e090a3a3439\n"
".quad 0x0934363709350963,0x732e766f6d090a30,0x3233722509203233,0x0a3b39317225202c\n"
".quad 0x3233622e646e6109,0x202c333372250920,0x3536202c32337225,0x7663090a3b353335\n"
".quad 0x3233662e6e722e74,0x662509203233752e,0x3b33337225202c31,0x33662e766f6d090a\n"
".quad 0x202c326625092032,0x6873090a3b316625,0x2509203233752e72,0x337225202c343372\n"
".quad 0x090a3b3631202c32,0x662e6e722e747663,0x09203233752e3233,0x337225202c336625\n"
".quad 0x2e766f6d090a3b34,0x3466250920323366,0x090a3b336625202c,0x203233662e766f6d\n"
".quad 0x6630202c35662509,0x3030303030303030,0x2f0920202020203b,0x766f6d090a30202f\n"
".quad 0x662509203233662e,0x0a3b356625202c36,0x3233662e766f6d09,0x30202c3766250920\n"
".quad 0x3030303030303066,0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x3b376625202c3866,0x64322e786574090a,0x2e3233752e34762e,0x3372257b20323366\n"
".quad 0x252c363372252c35,0x383372252c373372,0x646c6968635b2c7d,0x7b2c7865746e6572\n"
".quad 0x2c3466252c326625,0x7d3866252c366625,0x636f6c2e090a3b5d,0x3009383134093509\n"
".quad 0x33732e766f6d090a,0x2c39337225092032,0x090a3b3533722520,0x203233732e766f6d\n"
".quad 0x25202c3034722509,0x6f6d090a3b363372,0x2509203233732e76,0x337225202c313472\n"
".quad 0x636f6c2e090a3b37,0x3009353637093509,0x33732e766f6d090a,0x2c32347225092032\n"
".quad 0x090a3b3233722520,0x37093509636f6c2e,0x6f6d090a30093736,0x2509203233752e76\n"
".quad 0x3b3536202c333472,0x652e70746573090a,0x2509203233732e71,0x30337225202c3570\n"
".quad 0x0a3b33347225202c,0x7262203570254009,0x375f744c24092061,0x6d090a3b3835325f\n"
".quad 0x09203233752e766f,0x3736202c34347225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x337225202c367025,0x3b34347225202c30,0x622036702540090a,0x5f744c2409206172\n"
".quad 0x090a3b3037375f37,0x203233752e766f6d,0x37202c3534722509,0x70746573090a3b31\n"
".quad 0x203233732e71652e,0x7225202c37702509,0x35347225202c3033,0x2037702540090a3b\n"
".quad 0x744c240920617262,0x3b363230315f375f,0x33752e766f6d090a,0x2c36347225092032\n"
".quad 0x6573090a3b343820,0x33732e71652e7074,0x202c387025092032,0x7225202c30337225\n"
".quad 0x702540090a3b3634,0x2409206172622038,0x3832315f375f744c,0x2e617262090a3b32\n"
".quad 0x744c240920696e75,0x3b383335315f375f,0x325f375f744c240a,0x6f6c2e090a3a3835\n"
".quad 0x0939363709350963,0x622e6c6873090a30,0x3734722509203233,0x202c39337225202c\n"
".quad 0x726873090a3b3432,0x722509203233752e,0x37347225202c3834,0x73090a3b3432202c\n"
".quad 0x09203233622e6c68,0x7225202c39347225,0x0a3b3631202c3933,0x3233752e72687309\n"
".quad 0x202c303572250920,0x3432202c39347225,0x622e6c6873090a3b,0x3135722509203233\n"
".quad 0x202c39337225202c,0x2e726873090a3b38,0x3572250920323375,0x2c31357225202c32\n"
".quad 0x7262090a3b343220,0x240920696e752e61,0x3431355f375f744c,0x5f375f744c240a3b\n"
".quad 0x6c2e090a3a303737,0x303737093509636f,0x2e766f6d090a3009,0x3572250920323375\n"
".quad 0x3b39337225202c33,0x33752e726873090a,0x2c38347225092032,0x32202c3335722520\n"
".quad 0x2e6c6873090a3b34,0x3572250920323362,0x2c30347225202c34,0x6873090a3b343220\n"
".quad 0x2509203233752e72,0x357225202c303572,0x090a3b3432202c34,0x203233622e6c6873\n"
".quad 0x25202c3535722509,0x3b3631202c303472,0x33752e726873090a,0x2c32357225092032\n"
".quad 0x32202c3535722520,0x2e617262090a3b34,0x744c240920696e75,0x0a3b3431355f375f\n"
".quad 0x30315f375f744c24,0x6f6c2e090a3a3632,0x0931373709350963,0x622e6c6873090a30\n"
".quad 0x3635722509203233,0x202c30347225202c,0x2e726873090a3b38,0x3472250920323375\n"
".quad 0x2c36357225202c38,0x6f6d090a3b343220,0x2509203233752e76,0x347225202c373572\n"
".quad 0x2e726873090a3b30,0x3572250920323375,0x2c37357225202c30,0x6873090a3b343220\n"
".quad 0x2509203233622e6c,0x347225202c383572,0x090a3b3432202c31,0x203233752e726873\n"
".quad 0x25202c3235722509,0x3b3432202c383572,0x6e752e617262090a,0x375f744c24092069\n"
".quad 0x4c240a3b3431355f,0x323832315f375f74,0x09636f6c2e090a3a,0x0a30093237370935\n"
".quad 0x3233622e6c687309,0x202c393572250920,0x3631202c31347225,0x752e726873090a3b\n"
".quad 0x3834722509203233,0x202c39357225202c,0x6c6873090a3b3432,0x722509203233622e\n"
".quad 0x31347225202c3036,0x6873090a3b38202c,0x2509203233752e72,0x367225202c303572\n"
".quad 0x090a3b3432202c30,0x203233752e766f6d,0x25202c3136722509,0x6873090a3b313472\n"
".quad 0x2509203233752e72,0x367225202c323572,0x090a3b3432202c31,0x20696e752e617262\n"
".quad 0x355f375f744c2409,0x5f744c240a3b3431,0x0a3a383335315f37,0x093509636f6c2e09\n"
".quad 0x6d090a3009333737,0x09203233752e766f,0x3b30202c32357225,0x33752e766f6d090a\n"
".quad 0x2c30357225092032,0x766f6d090a3b3020,0x722509203233752e,0x240a3b30202c3834\n"
".quad 0x3431355f375f744c,0x09636f6c2e090a3a,0x0a30093639320935,0x3233622e646e6109\n"
".quad 0x202c323672250920,0x3531202c32357225,0x622e646e61090a3b,0x3336722509203233\n"
".quad 0x202c32357225202c,0x6873090a3b303432,0x2509203233622e6c,0x367225202c343672\n"
".quad 0x73090a3b38202c32,0x09203233622e6c68,0x7225202c35367225,0x090a3b34202c3336\n"
".quad 0x09203233622e726f,0x7225202c36367225,0x38347225202c3436,0x33622e726f090a3b\n"
".quad 0x2c37367225092032,0x25202c3536722520,0x6873090a3b303572,0x2509203233622e6c\n"
".quad 0x367225202c383672,0x090a3b3631202c37,0x09203233622e726f,0x7225202c39367225\n"
".quad 0x38367225202c3636,0x732e766f6d090a3b,0x3931722509203233,0x0a3b39367225202c\n"
".quad 0x093509636f6c2e09,0x6d090a3009363737,0x09203233752e766f,0x3b30202c30377225\n"
".quad 0x6e2e70746573090a,0x2509203233752e65,0x39367225202c3970,0x0a3b30377225202c\n"
".quad 0x7262203970254009,0x375f744c24092061,0x0a3b30353034335f,0x093509636f6c2e09\n"
".quad 0x6d090a3009333837,0x09203233732e766f,0x7225202c31377225,0x746573090a3b3234\n"
".quad 0x3233732e65672e70,0x202c303170250920,0x317225202c397225,0x31702540090a3b37\n"
".quad 0x2409206172622030,0x3534335f375f744c,0x6f6c2e090a3b3236,0x0935353609350963\n"
".quad 0x752e747663090a30,0x09203233732e3436,0x25202c3831647225,0x756d090a3b363172\n"
".quad 0x732e656469772e6c,0x3164722509203233,0x2c36317225202c39,0x646461090a3b3820\n"
".quad 0x722509203436752e,0x647225202c303264,0x31647225202c3331,0x2e766f6d090a3b39\n"
".quad 0x3772250920323373,0x73090a3b30202c32,0x6c61626f6c672e74,0x203233732e32762e\n"
".quad 0x2b30326472255b09,0x3372257b202c5d30,0x3b7d323772252c32,0x335f375f744c240a\n"
".quad 0x2e090a3a32363534,0x3837093509636f6c,0x627573090a300935,0x722509203233732e\n"
".quad 0x37317225202c3731,0x6c2e090a3b31202c,0x383837093509636f,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x62090a3b30202c38,0x0920696e752e6172,0x33325f375f744c24\n"
".quad 0x5f744c240a3b3630,0x3a30353034335f37,0x3509636f6c2e090a,0x090a300932393709\n"
".quad 0x203233622e646e61,0x25202c3337722509,0x353536202c393672,0x747663090a3b3533\n"
".quad 0x2e3233662e6e722e,0x3966250920323375,0x0a3b33377225202c,0x3233662e766f6d09\n"
".quad 0x202c303166250920,0x6873090a3b396625,0x2509203233752e72,0x367225202c343772\n"
".quad 0x090a3b3631202c39,0x662e6e722e747663,0x09203233752e3233,0x7225202c31316625\n"
".quad 0x766f6d090a3b3437,0x662509203233662e,0x31316625202c3231,0x662e766f6d090a3b\n"
".quad 0x3331662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x25202c3431662509,0x6f6d090a3b333166,0x2509203233662e76\n"
".quad 0x306630202c353166,0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30\n"
".quad 0x3631662509203233,0x0a3b35316625202c,0x2e64322e78657409,0x662e3233752e3476\n"
".quad 0x353772257b203233,0x72252c363772252c,0x7d383772252c3737,0x657465646f6e5b2c\n"
".quad 0x2c303166257b2c78,0x3166252c32316625,0x5d7d363166252c34,0x09636f6c2e090a3b\n"
".quad 0x0a30093537330935,0x3233732e766f6d09,0x202c393772250920,0x6d090a3b36377225\n"
".quad 0x09203233732e766f,0x7225202c30387225,0x6f6c2e090a3b3737,0x0933393709350963\n"
".quad 0x752e766f6d090a30,0x3138722509203233,0x0a3b39377225202c,0x3233752e72687309\n"
".quad 0x202c323872250920,0x3432202c31387225,0x622e6c6873090a3b,0x3338722509203233\n"
".quad 0x202c39377225202c,0x2e726873090a3b38,0x3872250920323375,0x2c33387225202c34\n"
".quad 0x6873090a3b343220,0x2509203233622e6c,0x387225202c353872,0x090a3b3432202c30\n"
".quad 0x203233752e726873,0x25202c3638722509,0x3b3432202c353872,0x33622e6c6873090a\n"
".quad 0x2c37387225092032,0x38202c3238722520,0x622e6c6873090a3b,0x3838722509203233\n"
".quad 0x202c36387225202c,0x2e726f090a3b3631,0x3872250920323362,0x2c37387225202c39\n"
".quad 0x090a3b3438722520,0x09203233622e726f,0x7225202c30397225,0x39387225202c3838\n"
".quad 0x732e766f6d090a3b,0x3139722509203233,0x0a3b30397225202c,0x3233732e766f6d09\n"
".quad 0x202c323972250920,0x73090a3b31397225,0x09203233622e6c68,0x7225202c33397225\n"
".quad 0x090a3b38202c3038,0x203233752e726873,0x25202c3439722509,0x3b3432202c333972\n"
".quad 0x33622e6c6873090a,0x2c35397225092032,0x31202c3038722520,0x2e726873090a3b36\n"
".quad 0x3972250920323375,0x2c35397225202c36,0x6f6d090a3b343220,0x2509203233752e76\n"
".quad 0x387225202c373972,0x2e726873090a3b30,0x3972250920323375,0x2c37397225202c38\n"
".quad 0x6873090a3b343220,0x2509203233622e6c,0x397225202c393972,0x73090a3b38202c34\n"
".quad 0x09203233622e6c68,0x25202c3030317225,0x3b3631202c383972,0x3233622e726f090a\n"
".quad 0x2c31303172250920,0x25202c3939722520,0x726f090a3b363972,0x722509203233622e\n"
".quad 0x317225202c323031,0x30317225202c3030,0x2e766f6d090a3b31,0x3172250920323375\n"
".quad 0x090a3b30202c3330,0x2e71652e70746573,0x3170250920323373,0x2c38317225202c31\n"
".quad 0x0a3b333031722520,0x6220313170254009,0x5f744c2409206172,0x3b30333335335f37\n"
".quad 0x3509636f6c2e090a,0x090a300933303809,0x203233732e646461,0x202c343031722509\n"
".quad 0x31202c3230317225,0x752e646461090a3b,0x3031722509203233,0x2c30397225202c35\n"
".quad 0x090a3b3831722520,0x203233732e6e696d,0x202c363031722509,0x25202c3430317225\n"
".quad 0x2e090a3b35303172,0x3038093509636f6c,0x627573090a300934,0x722509203233752e\n"
".quad 0x317225202c373031,0x30397225202c3230,0x732e646461090a3b,0x3031722509203233\n"
".quad 0x3730317225202c38,0x696d090a3b31202c,0x2509203233732e6e,0x7225202c39303172\n"
".quad 0x30317225202c3831,0x2e646461090a3b38,0x3172250920323373,0x2c37317225202c37\n"
".quad 0x0a3b393031722520,0x093509636f6c2e09,0x73090a3009353038,0x09203233732e6275\n"
".quad 0x25202c3031317225,0x317225202c383172,0x627573090a3b3730,0x722509203233732e\n"
".quad 0x317225202c313131,0x090a3b31202c3031,0x203233732e766f6d,0x202c323131722509\n"
".quad 0x2e78616d090a3b30,0x3172250920323373,0x3131317225202c38,0x3b3231317225202c\n"
".quad 0x6e752e617262090a,0x375f744c24092069,0x0a3b34373035335f,0x35335f375f744c24\n"
".quad 0x6c2e090a3a303333,0x393038093509636f,0x2e646461090a3009,0x3172250920323373\n"
".quad 0x2c37317225202c37,0x6f6c2e090a3b3120,0x0930313809350963,0x732e646461090a30\n"
".quad 0x3031722509203233,0x2c30397225202c36,0x5f744c240a3b3120,0x3a34373035335f37\n"
".quad 0x3509636f6c2e090a,0x090a300934313809,0x203233732e646461,0x202c333131722509\n"
".quad 0x7225202c36317225,0x747663090a3b3731,0x3233732e3436752e,0x2c31326472250920\n"
".quad 0x0a3b333131722520,0x3436752e64646109,0x2c32326472250920,0x202c313264722520\n"
".quad 0x090a3b3531647225,0x61626f6c672e646c,0x7225092038732e6c,0x6472255b202c3033\n"
".quad 0x090a3b5d302b3232,0x38093509636f6c2e,0x6f6d090a30093631,0x2509203233732e76\n"
".quad 0x3b30202c34313172,0x6e2e70746573090a,0x2509203233732e65,0x337225202c323170\n"
".quad 0x3431317225202c30,0x2e70746573090a3b,0x09203233752e746c,0x7225202c33317025\n"
".quad 0x317225202c323031,0x702540090a3b3630,0x0920617262203331,0x37335f375f744c24\n"
".quad 0x2140090a3b343336,0x6172622032317025,0x5f375f744c240920,0x090a3b3433363733\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x5f5f5b202c333264,0x6d72617061647563\n"
".quad 0x6d756d35315a5f5f,0x654b75706772656d,0x635076506c656e72,0x3253694b505f3053\n"
".quad 0x5d6665725f69695f,0x335f375f4c240a3b,0x63090a3a36363430,0x732e3436732e7476\n"
".quad 0x3264722509203233,0x3630317225202c34,0x752e646461090a3b,0x3264722509203436\n"
".quad 0x3432647225202c35,0x3b3332647225202c,0x6f6c672e646c090a,0x092038732e6c6162\n"
".quad 0x5b202c3531317225,0x5d302b3532647225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c34317025,0x337225202c353131,0x31702540090a3b30,0x2409206172622034\n"
".quad 0x3535335f375f744c,0x766f6d090a3b3638,0x722509203233732e,0x32347225202c3137\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b32383233335f37,0x335f375f744c240a\n"
".quad 0x2e090a3a36383535,0x3238093509636f6c,0x646461090a300939,0x722509203233732e\n"
".quad 0x37317225202c3731,0x6c2e090a3b31202c,0x303338093509636f,0x2e646461090a3009\n"
".quad 0x3172250920323373,0x30317225202c3630,0x2e090a3b31202c36,0x3338093509636f6c\n"
".quad 0x646461090a300932,0x722509203233732e,0x317225202c363131,0x3b37317225202c36\n"
".quad 0x36752e747663090a,0x2509203233732e34,0x7225202c36326472,0x6461090a3b363131\n"
".quad 0x2509203436752e64,0x7225202c37326472,0x647225202c363264,0x2e646c090a3b3531\n"
".quad 0x732e6c61626f6c67,0x2c30337225092038,0x2b37326472255b20,0x6f6c2e090a3b5d30\n"
".quad 0x0936313809350963,0x2e70746573090a30,0x09203233752e746c,0x7225202c35317025\n"
".quad 0x317225202c323031,0x702540090a3b3630,0x0920617262203531,0x38335f375f744c24\n"
".quad 0x6f6d090a3b363431,0x2509203233732e76,0x3b30202c37313172,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x337225202c363170,0x3731317225202c30,0x702e766f6d090a3b\n"
".quad 0x3170250920646572,0x3b36317025202c32,0x72702e766f6d090a,0x3731702509206465\n"
".quad 0x0a3b38317025202c,0x6220363170254009,0x375f4c2409206172,0x0a3b36363430335f\n"
".quad 0x696e752e61726209,0x5f375f744c240920,0x240a3b3433363733,0x3138335f375f744c\n"
".quad 0x766f6d090a3a3634,0x722509203233732e,0x0a3b30202c383131,0x656e2e7074657309\n"
".quad 0x702509203233732e,0x30337225202c3231,0x3b3831317225202c,0x335f375f744c240a\n"
".quad 0x4c240a3a34333637,0x32323730335f375f,0x09636f6c2e090a3a,0x0a30093233380935\n"
".quad 0x6220323170254009,0x5f744c2409206172,0x3b34393733335f37,0x33732e766f6d090a\n"
".quad 0x2c31377225092032,0x090a3b3234722520,0x20696e752e617262,0x335f375f744c2409\n"
".quad 0x4c240a3b32383233,0x373337335f375f74,0x2e766f6d090a3a38,0x3472250920323373\n"
".quad 0x3b31377225202c32,0x33732e766f6d090a,0x2c31397225092032,0x090a3b3239722520\n"
".quad 0x203233732e766f6d,0x202c363031722509,0x375f744c240a3b30,0x0a3a32383233335f\n"
".quad 0x35325f375f744c24,0x6f6c2e090a3a3236,0x0932343809350963,0x752e627573090a30\n"
".quad 0x3131722509203233,0x3630317225202c39,0x0a3b31397225202c,0x65672e7074657309\n"
".quad 0x702509203233732e,0x2c397225202c3931,0x090a3b3731722520,0x7262203931702540\n"
".quad 0x375f744c24092061,0x0a3b34353336335f,0x093509636f6c2e09,0x63090a3009353536\n"
".quad 0x732e3436752e7476,0x3264722509203233,0x3b36317225202c38,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3932647225,0x0a3b38202c363172,0x3436752e64646109\n"
".quad 0x2c30336472250920,0x202c333164722520,0x090a3b3932647225,0x61626f6c672e7473\n"
".quad 0x3233732e32762e6c,0x30336472255b0920,0x72257b202c5d302b,0x39313172252c3931\n"
".quad 0x375f744c240a3b7d,0x0a3a34353336335f,0x093509636f6c2e09,0x6d090a3009353438\n"
".quad 0x09203233732e766f,0x7225202c38317225,0x6c2e090a3b393131,0x363438093509636f\n"
".quad 0x2e627573090a3009,0x3172250920323373,0x37317225202c3032,0x3b3931317225202c\n"
".quad 0x33732e627573090a,0x2c37317225092032,0x202c303231722520,0x375f744c240a3b31\n"
".quad 0x090a3a363033325f,0x38093509636f6c2e,0x6e61090a30093135,0x2509203233622e64\n"
".quad 0x7225202c31323172,0x33353536202c3234,0x2e747663090a3b35,0x752e3233662e6e72\n"
".quad 0x3731662509203233,0x3b3132317225202c,0x33662e766f6d090a,0x2c38316625092032\n"
".quad 0x090a3b3731662520,0x203233752e726873,0x202c323231722509,0x3631202c32347225\n"
".quad 0x722e747663090a3b,0x33752e3233662e6e,0x2c39316625092032,0x0a3b323231722520\n"
".quad 0x3233662e766f6d09,0x202c303266250920,0x6d090a3b39316625,0x09203233662e766f\n"
".quad 0x6630202c31326625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3266250920323366,0x3b31326625202c32,0x33662e766f6d090a,0x2c33326625092032\n"
".quad 0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09,0x09203233662e766f\n"
".quad 0x6625202c34326625,0x786574090a3b3332,0x752e34762e64322e,0x7b203233662e3233\n"
".quad 0x72252c3332317225,0x323172252c343231,0x7d36323172252c35,0x657465646f6e5b2c\n"
".quad 0x2c383166257b2c78,0x3266252c30326625,0x5d7d343266252c32,0x09636f6c2e090a3b\n"
".quad 0x0a30093537330935,0x3233732e766f6d09,0x2c37323172250920,0x0a3b333231722520\n"
".quad 0x3233732e766f6d09,0x2c38323172250920,0x0a3b343231722520,0x093509636f6c2e09\n"
".quad 0x73090a3009363932,0x09203233622e6c68,0x25202c3932317225,0x3631202c38323172\n"
".quad 0x752e726873090a3b,0x3331722509203233,0x3932317225202c30,0x61090a3b3432202c\n"
".quad 0x09203233622e646e,0x25202c3133317225,0x3531202c30333172,0x622e6c6873090a3b\n"
".quad 0x3331722509203233,0x3133317225202c32,0x6f6d090a3b38202c,0x2509203233752e76\n"
".quad 0x7225202c33333172,0x6873090a3b373231,0x2509203233752e72,0x7225202c34333172\n"
".quad 0x3b3432202c333331,0x3233622e726f090a,0x2c35333172250920,0x202c323331722520\n"
".quad 0x090a3b3433317225,0x203233622e646e61,0x202c363331722509,0x32202c3033317225\n"
".quad 0x6c6873090a3b3034,0x722509203233622e,0x317225202c373331,0x090a3b34202c3633\n"
".quad 0x203233622e6c6873,0x202c383331722509,0x32202c3832317225,0x2e726873090a3b34\n"
".quad 0x3172250920323375,0x33317225202c3933,0x090a3b3432202c38,0x09203233622e726f\n"
".quad 0x25202c3034317225,0x7225202c37333172,0x6873090a3b393331,0x2509203233622e6c\n"
".quad 0x7225202c31343172,0x3b3631202c303431,0x3233622e726f090a,0x202c393172250920\n"
".quad 0x25202c3533317225,0x2e090a3b31343172,0x3538093509636f6c,0x646461090a300932\n"
".quad 0x722509203233732e,0x36317225202c3631,0x6573090a3b31202c,0x33732e656e2e7074\n"
".quad 0x2c30327025092032,0x25202c3431722520,0x2540090a3b363172,0x2061726220303270\n"
".quad 0x335f375f744c2409,0x4c240a3b34313532,0x315a5f5f37344242,0x6772656d6d756d35\n"
".quad 0x6c656e72654b7570,0x505f305363507650,0x3a69695f3253694b,0x3509636f6c2e090a\n"
".quad 0x090a300939353809,0x4c240a3b74697865,0x5a5f5f646e655744,0x72656d6d756d3531\n"
".quad 0x656e72654b757067,0x5f3053635076506c,0x69695f3253694b50,0x202f2f207d090a3a\n"
".quad 0x6d6d756d35315a5f,0x72654b7570677265,0x53635076506c656e,0x5f3253694b505f30\n"
".quad 0x6e652e090a0a6969,0x37315a5f20797274,0x706772656d6d756d,0x656e72654b435275\n"
".quad 0x6374614d3031506c,0x635064726f6f4368,0x69695f3353694b50,0x61702e09090a2820\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x37315a5f5f6d7261,0x706772656d6d756d\n"
".quad 0x656e72654b435275,0x6374614d3031506c,0x635064726f6f4368,0x69695f3353694b50\n"
".quad 0x635f686374616d5f,0x090a2c7364726f6f,0x206d617261702e09,0x635f5f203436752e\n"
".quad 0x5f6d726170616475,0x6d6d756d37315a5f,0x4b43527570677265,0x3031506c656e7265\n"
".quad 0x6f6f43686374614d,0x53694b5063506472,0x6575715f69695f33,0x09090a2c73656972\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x656d6d756d37315a\n"
".quad 0x654b435275706772,0x4d3031506c656e72,0x726f6f4368637461,0x3353694b50635064\n"
".quad 0x726575715f69695f,0x0a2c737264644179,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x6d756d37315a5f5f,0x435275706772656d,0x31506c656e72654b\n"
".quad 0x6f43686374614d30,0x694b50635064726f,0x75715f69695f3353,0x74676e654c797265\n"
".quad 0x702e09090a2c7368,0x33732e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x6772656d6d756d37,0x6e72654b43527570,0x74614d3031506c65,0x5064726f6f436863\n"
".quad 0x695f3353694b5063,0x6575516d756e5f69,0x09090a2c73656972,0x2e206d617261702e\n"
".quad 0x75635f5f20323373,0x5f5f6d7261706164,0x656d6d756d37315a,0x654b435275706772\n"
".quad 0x4d3031506c656e72,0x726f6f4368637461,0x3353694b50635064,0x5f6e696d5f69695f\n"
".quad 0x656c5f686374616d,0x2e090a7b090a296e,0x3738093509636f6c,0x57444c240a300932\n"
".quad 0x5a5f5f6e69676562,0x72656d6d756d3731,0x72654b4352757067,0x614d3031506c656e\n"
".quad 0x64726f6f43686374,0x5f3353694b506350,0x6f6c2e090a3a6969,0x3933303109350963\n"
".quad 0x74697865090a3009,0x6e6557444c240a3b,0x756d37315a5f5f64,0x5275706772656d6d\n"
".quad 0x506c656e72654b43,0x43686374614d3031,0x4b50635064726f6f,0x0a3a69695f335369\n"
".quad 0x5a5f202f2f207d09,0x72656d6d756d3731,0x72654b4352757067,0x614d3031506c656e\n"
".quad 0x64726f6f43686374,0x5f3353694b506350,0x6e652e090a0a6969,0x31315a5f20797274\n"
".quad 0x72654b746e697270,0x74614d39506c656e,0x50696f666e496863,0x656d6e67696c4139\n"
".quad 0x53694b506350746e,0x2069696969695f35,0x7261702e09090a28,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x7031315a5f5f6d72,0x6e72654b746e6972,0x6374614d39506c65\n"
".quad 0x3950696f666e4968,0x6e656d6e67696c41,0x3553694b50635074,0x6d5f69696969695f\n"
".quad 0x0a2c736568637461,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x69727031315a5f5f,0x6c656e72654b746e,0x49686374614d3950,0x6c413950696f666e\n"
".quad 0x50746e656d6e6769,0x695f3553694b5063,0x746f745f69696969,0x65686374614d6c61\n"
".quad 0x61702e09090a2c73,0x3436752e206d6172,0x70616475635f5f20,0x31315a5f5f6d7261\n"
".quad 0x72654b746e697270,0x74614d39506c656e,0x50696f666e496863,0x656d6e67696c4139\n"
".quad 0x53694b506350746e,0x5f69696969695f35,0x6e656d6e67696c61,0x702e09090a2c7374\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x315a5f5f6d726170,0x654b746e69727031\n"
".quad 0x614d39506c656e72,0x696f666e49686374,0x6d6e67696c413950,0x694b506350746e65\n"
".quad 0x69696969695f3553,0x705f6c61765f5f5f,0x726575716d617261,0x2e09090a2c736569\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061,0x4b746e6972703131\n"
".quad 0x4d39506c656e7265,0x6f666e4968637461,0x6e67696c41395069,0x4b506350746e656d\n"
".quad 0x696969695f355369,0x4179726575715f69,0x09090a2c73726464,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x5f5f6d7261706164,0x746e69727031315a,0x39506c656e72654b\n"
".quad 0x666e49686374614d,0x67696c413950696f,0x506350746e656d6e,0x6969695f3553694b\n"
".quad 0x79726575715f6969,0x2c736874676e654c,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x727031315a5f5f6d,0x656e72654b746e69,0x686374614d39506c\n"
".quad 0x413950696f666e49,0x746e656d6e67696c,0x5f3553694b506350,0x61705f6969696969\n"
".quad 0x6e696765625f6567,0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f\n"
".quad 0x7031315a5f5f6d72,0x6e72654b746e6972,0x6374614d39506c65,0x3950696f666e4968\n"
".quad 0x6e656d6e67696c41,0x3553694b50635074,0x705f69696969695f,0x2c646e655f656761\n"
".quad 0x617261702e09090a,0x5f203233732e206d,0x726170616475635f,0x727031315a5f5f6d\n"
".quad 0x656e72654b746e69,0x686374614d39506c,0x413950696f666e49,0x746e656d6e67696c\n"
".quad 0x5f3553694b506350,0x61705f6969696969,0x6f646168735f6567,0x0a2c7466656c5f77\n"
".quad 0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563,0x69727031315a5f5f\n"
".quad 0x6c656e72654b746e,0x49686374614d3950,0x6c413950696f666e,0x50746e656d6e6769\n"
".quad 0x695f3553694b5063,0x6761705f69696969,0x776f646168735f65,0x0a2c74686769725f\n"
".quad 0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563,0x69727031315a5f5f\n"
".quad 0x6c656e72654b746e,0x49686374614d3950,0x6c413950696f666e,0x50746e656d6e6769\n"
".quad 0x695f3553694b5063,0x6e696d5f69696969,0x6c5f686374616d5f,0x090a296874676e65\n"
".quad 0x206765722e090a7b,0x3c7225203233752e,0x2e090a3b3e323334,0x3436752e20676572\n"
".quad 0x3e31323c64722520,0x206765722e090a3b,0x3c6625203233662e,0x722e090a3b3e3438\n"
".quad 0x646572702e206765,0x3b3e38333c702520,0x6c61636f6c2e090a,0x206e67696c612e20\n"
".quad 0x5f2038622e203631,0x6f6c5f616475635f,0x5f7261765f6c6163,0x36315f3739353434\n"
".quad 0x6e6f635f6e6f6e5f,0x5f65646f6e5f7473,0x0a3b5d36315b3631,0x093509636f6c2e09\n"
".quad 0x240a300937363031,0x6e6967656257444c,0x69727031315a5f5f,0x6c656e72654b746e\n"
".quad 0x49686374614d3950,0x6c413950696f666e,0x50746e656d6e6769,0x695f3553694b5063\n"
".quad 0x6d090a3a69696969,0x09203233752e766f,0x746325202c317225,0x090a3b782e646961\n"
".quad 0x203233752e766f6d,0x6e25202c32722509,0x090a3b782e646974,0x6f6c2e34326c756d\n"
".quad 0x722509203233752e,0x202c317225202c33,0x6f6d090a3b327225,0x2509203233752e76\n"
".quad 0x64697425202c3472,0x646461090a3b782e,0x722509203233752e,0x202c347225202c35\n"
".quad 0x646c090a3b337225,0x732e6d617261702e,0x2c36722509203233,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x654b746e69727031,0x614d39506c656e72,0x696f666e49686374\n"
".quad 0x6d6e67696c413950,0x694b506350746e65,0x69696969695f3553,0x614d6c61746f745f\n"
".quad 0x0a3b5d7365686374,0x74672e7074657309,0x702509203233732e,0x202c367225202c31\n"
".quad 0x2540090a3b357225,0x0920617262203170,0x38345f395f744c24,0x7262090a3b383938\n"
".quad 0x240920696e752e61,0x5a5f5f313842424c,0x4b746e6972703131,0x4d39506c656e7265\n"
".quad 0x6f666e4968637461,0x6e67696c41395069,0x4b506350746e656d,0x696969695f355369\n"
".quad 0x395f744c240a3b69,0x0a3a38393838345f,0x093509636f6c2e09,0x090a300930383031\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3164,0x5f6d726170616475\n"
".quad 0x6e69727031315a5f,0x506c656e72654b74,0x6e49686374614d39,0x696c413950696f66\n"
".quad 0x6350746e656d6e67,0x69695f3553694b50,0x6374616d5f696969,0x63090a3b5d736568\n"
".quad 0x732e3436732e7476,0x3264722509203233,0x090a3b357225202c,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x2c357225202c3364,0x6461090a3b303220,0x2509203436752e64\n"
".quad 0x647225202c346472,0x3b33647225202c31,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c35647225,0x726170616475635f,0x727031315a5f5f6d,0x656e72654b746e69\n"
".quad 0x686374614d39506c,0x413950696f666e49,0x746e656d6e67696c,0x5f3553694b506350\n"
".quad 0x75715f6969696969,0x7372646441797265,0x672e646c090a3b5d,0x33752e6c61626f6c\n"
".quad 0x202c377225092032,0x5d342b346472255b,0x752e747663090a3b,0x09203233752e3436\n"
".quad 0x7225202c36647225,0x2e6c756d090a3b37,0x3233752e65646977,0x202c376472250920\n"
".quad 0x0a3b34202c377225,0x3436752e64646109,0x202c386472250920,0x7225202c35647225\n"
".quad 0x2e646c090a3b3764,0x732e6c61626f6c67,0x2c38722509203233,0x302b386472255b20\n"
".quad 0x636f6c2e090a3b5d,0x0938383031093509,0x732e747663090a30,0x09203233732e3436\n"
".quad 0x7225202c39647225,0x702e646c090a3b38,0x3436752e6d617261,0x2c30316472250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x654b746e69727031,0x614d39506c656e72\n"
".quad 0x696f666e49686374,0x6d6e67696c413950,0x694b506350746e65,0x69696969695f3553\n"
".quad 0x705f6c61765f5f5f,0x726575716d617261,0x61090a3b5d736569,0x09203436752e6464\n"
".quad 0x25202c3131647225,0x647225202c396472,0x2e646c090a3b3031,0x752e6c61626f6c67\n"
".quad 0x2c39722509203631,0x312b346472255b20,0x747663090a3b5d38,0x3233752e3436752e\n"
".quad 0x2c32316472250920,0x61090a3b39722520,0x09203436752e6464,0x25202c3331647225\n"
".quad 0x7225202c32316472,0x646c090a3b313164,0x2e6c61626f6c672e,0x3031722509203873\n"
".quad 0x33316472255b202c,0x6c2e090a3b5d302b,0x393031093509636f,0x2e646c090a300931\n"
".quad 0x752e6c61626f6c67,0x3131722509203233,0x2b346472255b202c,0x6f6c2e090a3b5d38\n"
".quad 0x3239303109350963,0x2e766f6d090a3009,0x3172250920323373,0x3b31317225202c32\n"
".quad 0x3509636f6c2e090a,0x0a30093339303109,0x3233732e766f6d09,0x202c333172250920\n"
".quad 0x2e090a3b31317225,0x3031093509636f6c,0x6e61090a30093639,0x2509203233622e64\n"
".quad 0x317225202c343172,0x3533353536202c31,0x722e747663090a3b,0x33752e3233662e6e\n"
".quad 0x202c316625092032,0x6d090a3b34317225,0x09203233662e766f,0x316625202c326625\n"
".quad 0x752e726873090a3b,0x3531722509203233,0x202c31317225202c,0x747663090a3b3631\n"
".quad 0x2e3233662e6e722e,0x3366250920323375,0x0a3b35317225202c,0x3233662e766f6d09\n"
".quad 0x25202c3466250920,0x766f6d090a3b3366,0x662509203233662e,0x3030306630202c35\n"
".quad 0x20203b3030303030,0x30202f2f09202020,0x33662e766f6d090a,0x202c366625092032\n"
".quad 0x6f6d090a3b356625,0x2509203233662e76,0x30306630202c3766,0x203b303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x2c38662509203233,0x74090a3b37662520\n"
".quad 0x34762e64322e7865,0x3233662e3233752e,0x252c363172257b20,0x383172252c373172\n"
".quad 0x5b2c7d393172252c,0x2c78657465646f6e,0x3466252c3266257b,0x3866252c3666252c\n"
".quad 0x6f6c2e090a3b5d7d,0x0935373309350963,0x732e766f6d090a30,0x3032722509203233\n"
".quad 0x0a3b36317225202c,0x3233732e766f6d09,0x202c313272250920,0x2e090a3b39317225\n"
".quad 0x3031093509636f6c,0x6f6d090a30093639,0x2509203233732e76,0x327225202c323272\n"
".quad 0x6c2e7473090a3b30,0x3233752e6c61636f,0x6475635f5f5b0920,0x5f6c61636f6c5f61\n"
".quad 0x393534345f726176,0x6e6f6e5f36315f37,0x6e5f74736e6f635f,0x302b36315f65646f\n"
".quad 0x3b32327225202c5d,0x636f6c2e7473090a,0x09203233752e6c61,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f37393534345f72,0x635f6e6f6e5f3631,0x646f6e5f74736e6f\n"
".quad 0x5d32312b36315f65,0x0a3b31327225202c,0x617261702e646c09,0x2509203233732e6d\n"
".quad 0x5f5f5b202c333272,0x6d72617061647563,0x69727031315a5f5f,0x6c656e72654b746e\n"
".quad 0x49686374614d3950,0x6c413950696f666e,0x50746e656d6e6769,0x695f3553694b5063\n"
".quad 0x6e696d5f69696969,0x6c5f686374616d5f,0x0a3b5d6874676e65,0x3233622e6c687309\n"
".quad 0x202c343272250920,0x3631202c31327225,0x752e726873090a3b,0x3532722509203233\n"
".quad 0x202c34327225202c,0x6c6873090a3b3432,0x722509203233622e,0x35327225202c3632\n"
".quad 0x6873090a3b38202c,0x2509203233622e6c,0x327225202c373272,0x090a3b3432202c31\n"
".quad 0x203233752e726873,0x25202c3832722509,0x3b3432202c373272,0x3233622e726f090a\n"
".quad 0x202c393272250920,0x7225202c36327225,0x6c6873090a3b3832,0x722509203233622e\n"
".quad 0x31327225202c3033,0x6873090a3b38202c,0x2509203233752e72,0x337225202c313372\n"
".quad 0x090a3b3432202c30,0x203233622e6c6873,0x25202c3233722509,0x3b3631202c313372\n"
".quad 0x3233622e726f090a,0x202c333372250920,0x7225202c39327225,0x746573090a3b3233\n"
".quad 0x3233732e65672e70,0x25202c3270250920,0x337225202c333272,0x32702540090a3b33\n"
".quad 0x4c24092061726220,0x313439345f395f74,0x395f744c240a3b30,0x0a3a32323939345f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x6e202c3639303120\n"
".quad 0x6420676e69747365,0x2c31203a68747065,0x74616d6974736520,0x6172657469206465\n"
".quad 0x75203a736e6f6974,0x090a6e776f6e6b6e,0x31093509636f6c2e,0x6d090a3009323031\n"
".quad 0x09203233732e766f,0x7225202c33317225,0x6f6c2e090a3b3231,0x0936393209350963\n"
".quad 0x622e6c6873090a30,0x3433722509203233,0x202c32327225202c,0x2e726873090a3b38\n"
".quad 0x3372250920323375,0x2c34337225202c35,0x6873090a3b343220,0x2509203233622e6c\n"
".quad 0x327225202c363372,0x090a3b3432202c32,0x203233752e726873,0x25202c3733722509\n"
".quad 0x3b3432202c363372,0x33622e6c6873090a,0x2c38337225092032,0x31202c3232722520\n"
".quad 0x2e726873090a3b36,0x3372250920323375,0x2c38337225202c39,0x6e61090a3b343220\n"
".quad 0x2509203233622e64,0x337225202c303472,0x090a3b3531202c35,0x203233622e646e61\n"
".quad 0x25202c3134722509,0x303432202c353372,0x622e6c6873090a3b,0x3234722509203233\n"
".quad 0x202c30347225202c,0x2e6c6873090a3b38,0x3472250920323362,0x2c31347225202c33\n"
".quad 0x2e726f090a3b3420,0x3472250920323362,0x2c32347225202c34,0x090a3b3733722520\n"
".quad 0x09203233622e726f,0x7225202c35347225,0x39337225202c3334,0x622e6c6873090a3b\n"
".quad 0x3634722509203233,0x202c35347225202c,0x2e726f090a3b3631,0x3472250920323362\n"
".quad 0x2c34347225202c37,0x090a3b3634722520,0x203233732e766f6d,0x25202c3231722509\n"
".quad 0x6c2e090a3b373472,0x303131093509636f,0x646e61090a300934,0x722509203233622e\n"
".quad 0x37347225202c3834,0x3b3533353536202c,0x6e722e747663090a,0x3233752e3233662e\n"
".quad 0x25202c3966250920,0x6f6d090a3b383472,0x2509203233662e76,0x396625202c303166\n"
".quad 0x752e726873090a3b,0x3934722509203233,0x202c37347225202c,0x747663090a3b3631\n"
".quad 0x2e3233662e6e722e,0x3166250920323375,0x3b39347225202c31,0x33662e766f6d090a\n"
".quad 0x2c32316625092032,0x090a3b3131662520,0x203233662e766f6d,0x30202c3331662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x33316625202c3431,0x662e766f6d090a3b,0x3531662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x25202c3631662509\n"
".quad 0x6574090a3b353166,0x2e34762e64322e78,0x203233662e323375,0x72252c303572257b\n"
".quad 0x2c323572252c3135,0x6e5b2c7d33357225,0x7b2c78657465646f,0x3166252c30316625\n"
".quad 0x252c343166252c32,0x090a3b5d7d363166,0x33093509636f6c2e,0x6f6d090a30093537\n"
".quad 0x2509203233732e76,0x357225202c303272,0x2e766f6d090a3b30,0x3572250920323373\n"
".quad 0x3b33357225202c34,0x3509636f6c2e090a,0x0a30093430313109,0x3233732e766f6d09\n"
".quad 0x202c323272250920,0x73090a3b30327225,0x2e6c61636f6c2e74,0x5f5f5b0920323375\n"
".quad 0x636f6c5f61647563,0x345f7261765f6c61,0x5f36315f37393534,0x736e6f635f6e6f6e\n"
".quad 0x315f65646f6e5f74,0x7225202c5d302b36,0x2e7473090a3b3232,0x33752e6c61636f6c\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3534345f7261765f,0x6f6e5f36315f3739\n"
".quad 0x5f74736e6f635f6e,0x2b36315f65646f6e,0x357225202c5d3231,0x2e6c6873090a3b34\n"
".quad 0x3572250920323362,0x2c34357225202c35,0x6873090a3b363120,0x2509203233752e72\n"
".quad 0x357225202c363572,0x090a3b3432202c35,0x203233622e6c6873,0x25202c3735722509\n"
".quad 0x0a3b38202c363572,0x3233622e6c687309,0x202c383572250920,0x3432202c34357225\n"
".quad 0x752e726873090a3b,0x3935722509203233,0x202c38357225202c,0x2e726f090a3b3432\n"
".quad 0x3672250920323362,0x2c37357225202c30,0x090a3b3935722520,0x203233622e6c6873\n"
".quad 0x25202c3136722509,0x0a3b38202c343572,0x3233752e72687309,0x202c323672250920\n"
".quad 0x3432202c31367225,0x622e6c6873090a3b,0x3336722509203233,0x202c32367225202c\n"
".quad 0x2e726f090a3b3631,0x3672250920323362,0x2c30367225202c34,0x090a3b3336722520\n"
".quad 0x2e746c2e70746573,0x3370250920323373,0x202c33327225202c,0x40090a3b34367225\n"
".quad 0x2061726220337025,0x345f395f744c2409,0x4c240a3b32323939,0x313439345f395f74\n"
".quad 0x636f6c2e090a3a30,0x0931313131093509,0x732e766f6d090a30,0x3536722509203233\n"
".quad 0x0a3b32317225202c,0x093509636f6c2e09,0x090a300932313131,0x203233732e766f6d\n"
".quad 0x25202c3231722509,0x6c2e090a3b333172,0x313131093509636f,0x646e61090a300939\n"
".quad 0x722509203233622e,0x33317225202c3636,0x3b3533353536202c,0x6e722e747663090a\n"
".quad 0x3233752e3233662e,0x202c373166250920,0x6d090a3b36367225,0x09203233662e766f\n"
".quad 0x6625202c38316625,0x726873090a3b3731,0x722509203233752e,0x33317225202c3736\n"
".quad 0x63090a3b3631202c,0x33662e6e722e7476,0x2509203233752e32,0x367225202c393166\n"
".quad 0x2e766f6d090a3b37,0x3266250920323366,0x3b39316625202c30,0x33662e766f6d090a\n"
".quad 0x2c31326625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6625202c32326625,0x766f6d090a3b3132,0x662509203233662e\n"
".quad 0x30306630202c3332,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c34326625092032,0x090a3b3332662520,0x762e64322e786574,0x33662e3233752e34\n"
".quad 0x2c383672257b2032,0x3772252c39367225,0x2c7d313772252c30,0x78657465646f6e5b\n"
".quad 0x252c383166257b2c,0x323266252c303266,0x3b5d7d343266252c,0x3509636f6c2e090a\n"
".quad 0x090a300935373309,0x203233732e766f6d,0x25202c3032722509,0x6f6d090a3b383672\n"
".quad 0x2509203233732e76,0x377225202c323772,0x636f6c2e090a3b31,0x0939313131093509\n"
".quad 0x6f6c2e7473090a30,0x203233752e6c6163,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x37393534345f7261,0x5f6e6f6e5f36315f,0x6f6e5f74736e6f63,0x5d302b36315f6564\n"
".quad 0x0a3b30327225202c,0x61636f6c2e747309,0x5b09203233752e6c,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x315f37393534345f,0x6f635f6e6f6e5f36,0x65646f6e5f74736e\n"
".quad 0x2c5d32312b36315f,0x090a3b3237722520,0x31093509636f6c2e,0x73090a3009313231\n"
".quad 0x09203233622e6c68,0x7225202c33377225,0x0a3b3631202c3237,0x3233752e72687309\n"
".quad 0x202c343772250920,0x3432202c33377225,0x622e6c6873090a3b,0x3537722509203233\n"
".quad 0x202c34377225202c,0x2e6c6873090a3b38,0x3772250920323362,0x2c32377225202c36\n"
".quad 0x6873090a3b343220,0x2509203233752e72,0x377225202c373772,0x090a3b3432202c36\n"
".quad 0x09203233622e726f,0x7225202c38377225,0x37377225202c3537,0x622e6c6873090a3b\n"
".quad 0x3937722509203233,0x202c32377225202c,0x2e726873090a3b38,0x3872250920323375\n"
".quad 0x2c39377225202c30,0x6873090a3b343220,0x2509203233622e6c,0x387225202c313872\n"
".quad 0x090a3b3631202c30,0x09203233622e726f,0x7225202c32387225,0x31387225202c3837\n"
".quad 0x732e627573090a3b,0x3338722509203233,0x202c32387225202c,0x636f6c2e090a3b31\n"
".quad 0x0934323131093509,0x6c672e646c090a30,0x3233732e6c61626f,0x202c343872250920\n"
".quad 0x5d302b346472255b,0x2e70746573090a3b,0x09203233752e656e,0x317225202c347025\n"
".quad 0x3b33317225202c31,0x622034702540090a,0x5f744c2409206172,0x3b30393630355f39\n"
".quad 0x6f6c672e646c090a,0x203631752e6c6162,0x5b202c3538722509,0x5d36312b34647225\n"
".quad 0x752e766f6d090a3b,0x3638722509203233,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x202c357025092032,0x7225202c35387225,0x702540090a3b3638,0x2409206172622035\n"
".quad 0x3930355f395f744c,0x6f6c2e090a3b3634,0x3133313109350963,0x2e646e61090a3009\n"
".quad 0x3872250920323362,0x2c35367225202c37,0x0a3b353335353620,0x2e6e722e74766309\n"
".quad 0x203233752e323366,0x25202c3532662509,0x6f6d090a3b373872,0x2509203233662e76\n"
".quad 0x326625202c363266,0x2e726873090a3b35,0x3872250920323375,0x2c35367225202c38\n"
".quad 0x7663090a3b363120,0x3233662e6e722e74,0x662509203233752e,0x38387225202c3732\n"
".quad 0x662e766f6d090a3b,0x3832662509203233,0x0a3b37326625202c,0x3233662e766f6d09\n"
".quad 0x202c393266250920,0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f\n"
".quad 0x2509203233662e76,0x326625202c303366,0x2e766f6d090a3b39,0x3366250920323366\n"
".quad 0x3030306630202c31,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c323366250920,0x74090a3b31336625,0x34762e64322e7865,0x3233662e3233752e\n"
".quad 0x252c393872257b20,0x313972252c303972,0x5b2c7d323972252c,0x2c78657465646f6e\n"
".quad 0x66252c363266257b,0x2c303366252c3832,0x0a3b5d7d32336625,0x093509636f6c2e09\n"
".quad 0x6d090a3009353733,0x09203233732e766f,0x7225202c30327225,0x766f6d090a3b3938\n"
".quad 0x722509203233732e,0x32397225202c3339,0x09636f6c2e090a3b,0x3009313331310935\n"
".quad 0x636f6c2e7473090a,0x09203233752e6c61,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f37393534345f72,0x635f6e6f6e5f3631,0x646f6e5f74736e6f,0x2c5d302b36315f65\n"
".quad 0x090a3b3032722520,0x6c61636f6c2e7473,0x5f5b09203233752e,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x36315f3739353434,0x6e6f635f6e6f6e5f,0x5f65646f6e5f7473\n"
".quad 0x202c5d32312b3631,0x2e090a3b33397225,0x3131093509636f6c,0x6873090a30093233\n"
".quad 0x2509203233622e6c,0x397225202c343972,0x090a3b3631202c33,0x203233752e726873\n"
".quad 0x25202c3539722509,0x3b3432202c343972,0x33622e6c6873090a,0x2c36397225092032\n"
".quad 0x38202c3539722520,0x622e6c6873090a3b,0x3739722509203233,0x202c33397225202c\n"
".quad 0x726873090a3b3432,0x722509203233752e,0x37397225202c3839,0x6f090a3b3432202c\n"
".quad 0x2509203233622e72,0x397225202c393972,0x3b38397225202c36,0x33622e6c6873090a\n"
".quad 0x3030317225092032,0x202c33397225202c,0x2e726873090a3b38,0x3172250920323375\n"
".quad 0x30317225202c3130,0x090a3b3432202c30,0x203233622e6c6873,0x202c323031722509\n"
".quad 0x31202c3130317225,0x622e726f090a3b36,0x3031722509203233,0x2c39397225202c33\n"
".quad 0x0a3b323031722520,0x3233732e64646109,0x2c34303172250920,0x25202c3538722520\n"
".quad 0x73090a3b33303172,0x09203233732e6275,0x7225202c33387225,0x0a3b31202c343031\n"
".quad 0x30355f395f744c24,0x6f6d090a3a363439,0x2509203233732e76,0x3b31202c35303172\n"
".quad 0x6e752e617262090a,0x395f744c24092069,0x0a3b34333430355f,0x30355f395f744c24\n"
".quad 0x6f6d090a3a303936,0x2509203233732e76,0x3b30202c35303172,0x355f395f744c240a\n"
".quad 0x73090a3a34333430,0x752e71652e707465,0x2c36702509203233,0x25202c3331722520\n"
".quad 0x2540090a3b353672,0x0920617262203670,0x5f5f313842424c24,0x746e69727031315a\n"
".quad 0x39506c656e72654b,0x666e49686374614d,0x67696c413950696f,0x506350746e656d6e\n"
".quad 0x6969695f3553694b,0x766f6d090a3b6969,0x722509203233732e,0x0a3b30202c363031\n"
".quad 0x3233732e766f6d09,0x2c37303172250920,0x744c240a3b353620,0x30373931355f395f\n"
".quad 0x09636f6c2e090a3a,0x3009333431310935,0x33622e646e61090a,0x3830317225092032\n"
".quad 0x202c32317225202c,0x090a3b3533353536,0x662e6e722e747663,0x09203233752e3233\n"
".quad 0x7225202c33336625,0x6873090a3b383031,0x2509203233752e72,0x7225202c39303172\n"
".quad 0x0a3b3631202c3231,0x2e6e722e74766309,0x203233752e323366,0x25202c3433662509\n"
".quad 0x6d090a3b39303172,0x09203233662e766f,0x6625202c35336625,0x766f6d090a3b3333\n"
".quad 0x662509203233662e,0x34336625202c3633,0x662e766f6d090a3b,0x3733662509203233\n"
".quad 0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d\n"
".quad 0x25202c3833662509,0x6f6d090a3b373366,0x2509203233662e76,0x306630202c393366\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x3034662509203233\n"
".quad 0x0a3b39336625202c,0x2e64322e78657409,0x662e3233752e3476,0x313172257b203233\n"
".quad 0x2c31313172252c30,0x72252c3231317225,0x68635b2c7d333131,0x65746e6572646c69\n"
".quad 0x2c353366257b2c78,0x3366252c36336625,0x5d7d303466252c38,0x09636f6c2e090a3b\n"
".quad 0x0a30093831340935,0x3233732e766f6d09,0x2c34313172250920,0x0a3b303131722520\n"
".quad 0x3233732e766f6d09,0x2c35313172250920,0x0a3b333131722520,0x093509636f6c2e09\n"
".quad 0x090a300933343131,0x203233732e766f6d,0x202c363131722509,0x090a3b3531317225\n"
".quad 0x203233732e726873,0x202c373131722509,0x32202c3631317225,0x2e766f6d090a3b34\n"
".quad 0x3172250920323373,0x090a3b30202c3831,0x2e656e2e70746573,0x3770250920323373\n"
".quad 0x2c3731317225202c,0x0a3b383131722520,0x33732e706c657309,0x3931317225092032\n"
".quad 0x202c30202c31202c,0x6f6d090a3b377025,0x2509203233732e76,0x3b30202c30323172\n"
".quad 0x656e2e746573090a,0x3233732e3233752e,0x2c31323172250920,0x202c363031722520\n"
".quad 0x090a3b3032317225,0x203233732e67656e,0x202c323231722509,0x090a3b3132317225\n"
".quad 0x09203233622e726f,0x25202c3332317225,0x7225202c39313172,0x6f6d090a3b323231\n"
".quad 0x2509203233752e76,0x3b30202c34323172,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x32317225202c3870,0x3432317225202c33,0x2038702540090a3b,0x744c240920617262\n"
".quad 0x32383432355f395f,0x6e2e746573090a3b,0x33732e3233752e65,0x3532317225092032\n"
".quad 0x202c30317225202c,0x090a3b3731317225,0x203233732e67656e,0x202c363231722509\n"
".quad 0x090a3b3532317225,0x203233622e646e61,0x202c373231722509,0x25202c3931317225\n"
".quad 0x6d090a3b36323172,0x09203233752e766f,0x30202c3832317225,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x317225202c397025,0x32317225202c3732,0x39702540090a3b38\n"
".quad 0x4c24092061726220,0x333535365f395f74,0x636f6c2e090a3b38,0x0934353131093509\n"
".quad 0x622e6c6873090a30,0x3231722509203233,0x3431317225202c39,0x73090a3b3631202c\n"
".quad 0x09203233752e7268,0x25202c3033317225,0x3432202c39323172,0x622e6c6873090a3b\n"
".quad 0x3331722509203233,0x3431317225202c31,0x73090a3b3432202c,0x09203233752e7268\n"
".quad 0x25202c3233317225,0x3432202c31333172,0x622e6c6873090a3b,0x3331722509203233\n"
".quad 0x3431317225202c33,0x6873090a3b38202c,0x2509203233752e72,0x7225202c34333172\n"
".quad 0x3b3432202c333331,0x33622e6c6873090a,0x3533317225092032,0x2c3033317225202c\n"
".quad 0x6c6873090a3b3820,0x722509203233622e,0x317225202c363331,0x0a3b3631202c3433\n"
".quad 0x203233622e726f09,0x202c373331722509,0x25202c3533317225,0x6f090a3b32333172\n"
".quad 0x2509203233622e72,0x7225202c38333172,0x317225202c363331,0x2e646c090a3b3733\n"
".quad 0x33732e6d61726170,0x3933317225092032,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x4b746e6972703131,0x4d39506c656e7265,0x6f666e4968637461,0x6e67696c41395069\n"
".quad 0x4b506350746e656d,0x696969695f355369,0x625f656761705f69,0x090a3b5d6e696765\n"
".quad 0x203233732e646461,0x202c303431722509,0x25202c3833317225,0x73090a3b39333172\n"
".quad 0x09203233732e6275,0x25202c3134317225,0x3b31202c30343172,0x6e2e70746573090a\n"
".quad 0x2509203233732e65,0x317225202c303170,0x33317225202c3134,0x31702540090a3b39\n"
".quad 0x2409206172622030,0x343638345f395f4c,0x702e646c090a3b32,0x3233732e6d617261\n"
".quad 0x2c32343172250920,0x616475635f5f5b20,0x315a5f5f6d726170,0x654b746e69727031\n"
".quad 0x614d39506c656e72,0x696f666e49686374,0x6d6e67696c413950,0x694b506350746e65\n"
".quad 0x69696969695f3553,0x68735f656761705f,0x66656c5f776f6461,0x766f6d090a3b5d74\n"
".quad 0x722509203233752e,0x3b312d202c333431,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x317225202c313170,0x34317225202c3234,0x31702540090a3b33,0x2409206172622031\n"
".quad 0x3535365f395f744c,0x395f4c240a3b3833,0x0a3a32343638345f,0x3233732e64646109\n"
".quad 0x2c34343172250920,0x202c303431722520,0x73090a3b33387225,0x09203233732e6275\n"
".quad 0x25202c3534317225,0x3b31202c34343172,0x7261702e646c090a,0x09203233732e6d61\n"
".quad 0x5b202c3634317225,0x6170616475635f5f,0x7031315a5f5f6d72,0x6e72654b746e6972\n"
".quad 0x6374614d39506c65,0x3950696f666e4968,0x6e656d6e67696c41,0x3553694b50635074\n"
".quad 0x705f69696969695f,0x5d646e655f656761,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x7225202c32317025,0x317225202c363431,0x702540090a3b3534,0x0920617262203231\n"
".quad 0x3338345f395f4c24,0x2e646c090a3b3638,0x33732e6d61726170,0x3734317225092032\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x4b746e6972703131,0x4d39506c656e7265\n"
".quad 0x6f666e4968637461,0x6e67696c41395069,0x4b506350746e656d,0x696969695f355369\n"
".quad 0x735f656761705f69,0x69725f776f646168,0x6d090a3b5d746867,0x09203233752e766f\n"
".quad 0x2d202c3834317225,0x70746573090a3b31,0x203233732e656e2e,0x25202c3331702509\n"
".quad 0x7225202c37343172,0x2540090a3b383431,0x2061726220333170,0x365f395f744c2409\n"
".quad 0x4c240a3b38333535,0x36383338345f395f,0x61702e646c090a3a,0x203233732e6d6172\n"
".quad 0x202c393431722509,0x70616475635f5f5b,0x31315a5f5f6d7261,0x72654b746e697270\n"
".quad 0x74614d39506c656e,0x50696f666e496863,0x656d6e67696c4139,0x53694b506350746e\n"
".quad 0x5f69696969695f35,0x6168735f65676170,0x7466656c5f776f64,0x2e746573090a3b5d\n"
".quad 0x732e3233752e656c,0x3531722509203233,0x3934317225202c30,0x3b3534317225202c\n"
".quad 0x33732e67656e090a,0x3135317225092032,0x3b3035317225202c,0x656c2e746573090a\n"
".quad 0x3233732e3233752e,0x2c32353172250920,0x202c313431722520,0x090a3b3933317225\n"
".quad 0x203233732e67656e,0x202c333531722509,0x090a3b3235317225,0x09203233622e726f\n"
".quad 0x25202c3435317225,0x7225202c31353172,0x6f6d090a3b333531,0x2509203233752e76\n"
".quad 0x3b30202c35353172,0x652e70746573090a,0x2509203233732e71,0x317225202c343170\n"
".quad 0x35317225202c3435,0x31702540090a3b35,0x2409206172622034,0x3535365f395f744c\n"
".quad 0x6f6c2e090a3b3833,0x3936313109350963,0x702e646c090a3009,0x3436752e6d617261\n"
".quad 0x2c34316472250920,0x616475635f5f5b20,0x315a5f5f6d726170,0x654b746e69727031\n"
".quad 0x614d39506c656e72,0x696f666e49686374,0x6d6e67696c413950,0x694b506350746e65\n"
".quad 0x69696969695f3553,0x656d6e67696c615f,0x63090a3b5d73746e,0x732e3436732e7476\n"
".quad 0x3164722509203233,0x3b34387225202c35,0x69772e6c756d090a,0x09203233732e6564\n"
".quad 0x25202c3631647225,0x0a3b38202c343872,0x3436752e64646109,0x2c37316472250920\n"
".quad 0x202c343164722520,0x090a3b3631647225,0x61626f6c672e7473,0x5b09203233732e6c\n"
".quad 0x5d302b3731647225,0x3b3134317225202c,0x3509636f6c2e090a,0x0a30093037313109\n"
".quad 0x626f6c672e747309,0x09203631752e6c61,0x342b37316472255b,0x3b33387225202c5d\n"
".quad 0x3509636f6c2e090a,0x0a30093137313109,0x3233732e64646109,0x202c343872250920\n"
".quad 0x3b31202c34387225,0x365f395f744c240a,0x4c240a3a38333535,0x30333138345f395f\n"
".quad 0x5f395f744c240a3a,0x090a3a3833373235,0x31093509636f6c2e,0x6d090a3009303831\n"
".quad 0x09203233662e766f,0x6625202c31346625,0x766f6d090a3b3333,0x662509203233662e\n"
".quad 0x34336625202c3234,0x662e766f6d090a3b,0x3334662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x25202c3434662509\n"
".quad 0x6f6d090a3b333466,0x2509203233662e76,0x306630202c353466,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3634662509203233,0x0a3b35346625202c\n"
".quad 0x2e64322e78657409,0x662e3233752e3476,0x353172257b203233,0x2c37353172252c36\n"
".quad 0x72252c3835317225,0x6f6e5b2c7d393531,0x257b2c7865746564,0x323466252c313466\n"
".quad 0x66252c343466252c,0x2e090a3b5d7d3634,0x3733093509636f6c,0x766f6d090a300935\n"
".quad 0x722509203233732e,0x317225202c303631,0x766f6d090a3b3635,0x722509203233732e\n"
".quad 0x317225202c313631,0x6f6c2e090a3b3935,0x3038313109350963,0x6c2e7473090a3009\n"
".quad 0x3233752e6c61636f,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x393534345f726176\n"
".quad 0x6e6f6e5f36315f37,0x6e5f74736e6f635f,0x302b36315f65646f,0x3036317225202c5d\n"
".quad 0x6f6c2e7473090a3b,0x203233752e6c6163,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x37393534345f7261,0x5f6e6f6e5f36315f,0x6f6e5f74736e6f63,0x32312b36315f6564\n"
".quad 0x3136317225202c5d,0x09636f6c2e090a3b,0x3009363831310935,0x33622e6c6873090a\n"
".quad 0x3236317225092032,0x2c3036317225202c,0x726873090a3b3820,0x722509203233752e\n"
".quad 0x36317225202c3533,0x090a3b3432202c32,0x203233622e6c6873,0x202c333631722509\n"
".quad 0x32202c3036317225,0x2e726873090a3b34,0x3372250920323375,0x3336317225202c37\n"
".quad 0x73090a3b3432202c,0x09203233622e6c68,0x25202c3436317225,0x3631202c30363172\n"
".quad 0x752e726873090a3b,0x3933722509203233,0x2c3436317225202c,0x6e61090a3b343220\n"
".quad 0x2509203233622e64,0x337225202c303472,0x090a3b3531202c35,0x203233622e646e61\n"
".quad 0x25202c3134722509,0x303432202c353372,0x622e6c6873090a3b,0x3234722509203233\n"
".quad 0x202c30347225202c,0x2e6c6873090a3b38,0x3472250920323362,0x2c31347225202c33\n"
".quad 0x2e726f090a3b3420,0x3472250920323362,0x2c32347225202c34,0x090a3b3733722520\n"
".quad 0x09203233622e726f,0x7225202c35347225,0x39337225202c3334,0x622e6c6873090a3b\n"
".quad 0x3634722509203233,0x202c35347225202c,0x2e726f090a3b3631,0x3472250920323362\n"
".quad 0x2c34347225202c37,0x090a3b3634722520,0x203233752e726873,0x202c353631722509\n"
".quad 0x3631202c37347225,0x722e747663090a3b,0x33752e3233662e6e,0x2c37346625092032\n"
".quad 0x0a3b353631722520,0x3233622e646e6109,0x2c36363172250920,0x36202c3734722520\n"
".quad 0x63090a3b35333535,0x33662e6e722e7476,0x2509203233752e32,0x317225202c383466\n"
".quad 0x766f6d090a3b3636,0x662509203233662e,0x38346625202c3934,0x662e766f6d090a3b\n"
".quad 0x3035662509203233,0x0a3b37346625202c,0x3233662e766f6d09,0x202c313566250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x356625202c323566,0x2e766f6d090a3b31,0x3566250920323366,0x3030306630202c33\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c343566250920\n"
".quad 0x74090a3b33356625,0x34762e64322e7865,0x3233662e3233752e,0x2c37363172257b20\n"
".quad 0x72252c3836317225,0x373172252c393631,0x6c6968635b2c7d30,0x2c7865746e657264\n"
".quad 0x66252c393466257b,0x2c323566252c3035,0x0a3b5d7d34356625,0x093509636f6c2e09\n"
".quad 0x6d090a3009383134,0x09203233732e766f,0x25202c3137317225,0x6d090a3b37363172\n"
".quad 0x09203233732e766f,0x25202c3237317225,0x6d090a3b38363172,0x09203233732e766f\n"
".quad 0x25202c3337317225,0x2e090a3b39363172,0x3131093509636f6c,0x6873090a30093239\n"
".quad 0x2509203233622e6c,0x7225202c34373172,0x0a3b38202c313731,0x3233752e72687309\n"
".quad 0x2c35373172250920,0x202c343731722520,0x646e61090a3b3432,0x722509203233622e\n"
".quad 0x317225202c363731,0x0a3b3531202c3537,0x3233622e6c687309,0x2c37373172250920\n"
".quad 0x202c363731722520,0x2e6c6873090a3b38,0x3172250920323362,0x37317225202c3837\n"
".quad 0x090a3b3432202c31,0x203233752e726873,0x202c393731722509,0x32202c3837317225\n"
".quad 0x622e726f090a3b34,0x3831722509203233,0x3737317225202c30,0x3b3937317225202c\n"
".quad 0x33622e646e61090a,0x3138317225092032,0x2c3537317225202c,0x73090a3b30343220\n"
".quad 0x09203233622e6c68,0x25202c3238317225,0x3b34202c31383172,0x33622e6c6873090a\n"
".quad 0x3338317225092032,0x2c3137317225202c,0x6873090a3b363120,0x2509203233752e72\n"
".quad 0x7225202c34383172,0x3b3432202c333831,0x3233622e726f090a,0x2c35383172250920\n"
".quad 0x202c323831722520,0x090a3b3438317225,0x203233622e6c6873,0x202c363831722509\n"
".quad 0x31202c3538317225,0x622e726f090a3b36,0x3831722509203233,0x3038317225202c37\n"
".quad 0x3b3638317225202c,0x6e2e70746573090a,0x2509203233752e65,0x317225202c353170\n"
".quad 0x3738317225202c32,0x3531702540090a3b,0x4c24092061726220,0x313034355f395f74\n"
".quad 0x2e766f6d090a3b38,0x3172250920323373,0x090a3b30202c3630,0x203233732e766f6d\n"
".quad 0x202c373031722509,0x617262090a3b3736,0x4c240920696e752e,0x393235355f395f74\n"
".quad 0x395f744c240a3b38,0x0a3a38313034355f,0x3233622e6c687309,0x2c38383172250920\n"
".quad 0x202c323731722520,0x726873090a3b3631,0x722509203233752e,0x317225202c393831\n"
".quad 0x0a3b3432202c3838,0x3233622e646e6109,0x2c30393172250920,0x202c393831722520\n"
".quad 0x6c6873090a3b3531,0x722509203233622e,0x317225202c313931,0x090a3b38202c3039\n"
".quad 0x203233752e766f6d,0x202c323931722509,0x090a3b3137317225,0x203233752e726873\n"
".quad 0x202c333931722509,0x32202c3239317225,0x622e726f090a3b34,0x3931722509203233\n"
".quad 0x3139317225202c34,0x3b3339317225202c,0x33622e646e61090a,0x3539317225092032\n"
".quad 0x2c3938317225202c,0x73090a3b30343220,0x09203233622e6c68,0x25202c3639317225\n"
".quad 0x3b34202c35393172,0x33622e6c6873090a,0x3739317225092032,0x2c3237317225202c\n"
".quad 0x6873090a3b343220,0x2509203233752e72,0x7225202c38393172,0x3b3432202c373931\n"
".quad 0x3233622e726f090a,0x2c39393172250920,0x202c363931722520,0x090a3b3839317225\n"
".quad 0x203233622e6c6873,0x202c303032722509,0x31202c3939317225,0x622e726f090a3b36\n"
".quad 0x3032722509203233,0x3439317225202c31,0x3b3030327225202c,0x6e2e70746573090a\n"
".quad 0x2509203233752e65,0x317225202c363170,0x3130327225202c32,0x3631702540090a3b\n"
".quad 0x4c24092061726220,0x333534355f395f74,0x2e766f6d090a3b30,0x3172250920323373\n"
".quad 0x090a3b30202c3630,0x203233732e766f6d,0x202c373031722509,0x617262090a3b3137\n"
".quad 0x4c240920696e752e,0x393235355f395f74,0x395f744c240a3b38,0x0a3a30333534355f\n"
".quad 0x3233622e6c687309,0x2c32303272250920,0x202c333731722520,0x726873090a3b3432\n"
".quad 0x722509203233752e,0x327225202c333032,0x0a3b3432202c3230,0x3233622e646e6109\n"
".quad 0x2c34303272250920,0x202c333032722520,0x6c6873090a3b3531,0x722509203233622e\n"
".quad 0x327225202c353032,0x090a3b38202c3430,0x203233622e6c6873,0x202c363032722509\n"
".quad 0x38202c3237317225,0x752e726873090a3b,0x3032722509203233,0x3630327225202c37\n"
".quad 0x6f090a3b3432202c,0x2509203233622e72,0x7225202c38303272,0x327225202c353032\n"
".quad 0x646e61090a3b3730,0x722509203233622e,0x327225202c393032,0x3b303432202c3330\n"
".quad 0x33622e6c6873090a,0x3031327225092032,0x2c3930327225202c,0x766f6d090a3b3420\n"
".quad 0x722509203233752e,0x317225202c313132,0x726873090a3b3237,0x722509203233752e\n"
".quad 0x327225202c323132,0x0a3b3432202c3131,0x203233622e726f09,0x202c333132722509\n"
".quad 0x25202c3031327225,0x73090a3b32313272,0x09203233622e6c68,0x25202c3431327225\n"
".quad 0x3631202c33313272,0x33622e726f090a3b,0x3531327225092032,0x2c3830327225202c\n"
".quad 0x0a3b343132722520,0x656e2e7074657309,0x702509203233752e,0x32317225202c3731\n"
".quad 0x3b3531327225202c,0x203731702540090a,0x744c240920617262,0x32343035355f395f\n"
".quad 0x732e766f6d090a3b,0x3031722509203233,0x6d090a3b30202c36,0x09203233732e766f\n"
".quad 0x38202c3730317225,0x2e617262090a3b34,0x744c240920696e75,0x38393235355f395f\n"
".quad 0x5f395f744c240a3b,0x090a3a3234303535,0x203233752e766f6d,0x202c363132722509\n"
".quad 0x090a3b3337317225,0x203233752e726873,0x202c373132722509,0x32202c3631327225\n"
".quad 0x2e646e61090a3b34,0x3272250920323362,0x31327225202c3831,0x090a3b3531202c37\n"
".quad 0x203233622e6c6873,0x202c393132722509,0x38202c3831327225,0x622e6c6873090a3b\n"
".quad 0x3232722509203233,0x3337317225202c30,0x73090a3b3631202c,0x09203233752e7268\n"
".quad 0x25202c3132327225,0x3432202c30323272,0x33622e726f090a3b,0x3232327225092032\n"
".quad 0x2c3931327225202c,0x0a3b313232722520,0x3233622e646e6109,0x2c33323272250920\n"
".quad 0x202c373132722520,0x6873090a3b303432,0x2509203233622e6c,0x7225202c34323272\n"
".quad 0x0a3b34202c333232,0x3233622e6c687309,0x2c35323272250920,0x202c333731722520\n"
".quad 0x2e726873090a3b38,0x3272250920323375,0x32327225202c3632,0x090a3b3432202c35\n"
".quad 0x09203233622e726f,0x25202c3732327225,0x7225202c34323272,0x6873090a3b363232\n"
".quad 0x2509203233622e6c,0x7225202c38323272,0x3b3631202c373232,0x3233622e726f090a\n"
".quad 0x2c39323272250920,0x202c323232722520,0x090a3b3832327225,0x2e656e2e70746573\n"
".quad 0x3170250920323375,0x2c32317225202c38,0x0a3b393232722520,0x6220383170254009\n"
".quad 0x5f744c2409206172,0x3b34353535355f39,0x33732e766f6d090a,0x3630317225092032\n"
".quad 0x6f6d090a3b30202c,0x2509203233732e76,0x3633202c37303172,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b38393235355f39,0x355f395f744c240a,0x2e090a3a34353535\n"
".quad 0x3231093509636f6c,0x6f6d090a30093030,0x2509203233732e76,0x3b31202c36303172\n"
".quad 0x355f395f744c240a,0x4c240a3a38393235,0x383734355f395f74,0x395f744c240a3a36\n"
".quad 0x0a3a34373234355f,0x33355f395f744c24,0x6c2e090a3a323637,0x303231093509636f\n"
".quad 0x766f6d090a300933,0x722509203233732e,0x37347225202c3231,0x732e627573090a3b\n"
".quad 0x3332722509203233,0x3530317225202c30,0x6f6d090a3b31202c,0x2509203233732e76\n"
".quad 0x3b30202c31333272,0x6e2e70746573090a,0x2509203233732e65,0x317225202c393170\n"
".quad 0x33327225202c3530,0x706c6573090a3b31,0x722509203233732e,0x327225202c353031\n"
".quad 0x30317225202c3033,0x3b39317025202c35,0x33752e766f6d090a,0x3233327225092032\n"
".quad 0x6573090a3b30202c,0x33732e656e2e7074,0x2c30327025092032,0x202c353031722520\n"
".quad 0x090a3b3233327225,0x7262203032702540,0x395f744c24092061,0x0a3b34353931365f\n"
".quad 0x093509636f6c2e09,0x090a300939303231,0x203233662e766f6d,0x25202c3535662509\n"
".quad 0x6f6d090a3b383466,0x2509203233662e76,0x346625202c363566,0x2e766f6d090a3b37\n"
".quad 0x3566250920323366,0x3030306630202c37,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c383566250920,0x6d090a3b37356625,0x09203233662e766f\n"
".quad 0x6630202c39356625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3666250920323366,0x3b39356625202c30,0x64322e786574090a,0x2e3233752e34762e\n"
".quad 0x3272257b20323366,0x34333272252c3333,0x252c35333272252c,0x6e5b2c7d36333272\n"
".quad 0x7b2c78657465646f,0x3566252c35356625,0x252c383566252c36,0x090a3b5d7d303666\n"
".quad 0x33093509636f6c2e,0x6f6d090a30093537,0x2509203233732e76,0x327225202c303272\n"
".quad 0x766f6d090a3b3333,0x722509203233732e,0x327225202c373332,0x6f6c2e090a3b3633\n"
".quad 0x3930323109350963,0x6c2e7473090a3009,0x3233752e6c61636f,0x6475635f5f5b0920\n"
".quad 0x5f6c61636f6c5f61,0x393534345f726176,0x6e6f6e5f36315f37,0x6e5f74736e6f635f\n"
".quad 0x302b36315f65646f,0x3b30327225202c5d,0x636f6c2e7473090a,0x09203233752e6c61\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f37393534345f72,0x635f6e6f6e5f3631\n"
".quad 0x646f6e5f74736e6f,0x5d32312b36315f65,0x3b3733327225202c,0x3509636f6c2e090a\n"
".quad 0x0a30093031323109,0x3233622e6c687309,0x2c38333272250920,0x202c373332722520\n"
".quad 0x726873090a3b3631,0x722509203233752e,0x327225202c393332,0x0a3b3432202c3833\n"
".quad 0x3233622e6c687309,0x2c30343272250920,0x202c393332722520,0x2e6c6873090a3b38\n"
".quad 0x3272250920323362,0x33327225202c3134,0x090a3b3432202c37,0x203233752e726873\n"
".quad 0x202c323432722509,0x32202c3134327225,0x622e726f090a3b34,0x3432722509203233\n"
".quad 0x3034327225202c33,0x3b3234327225202c,0x33622e6c6873090a,0x3434327225092032\n"
".quad 0x2c3733327225202c,0x726873090a3b3820,0x722509203233752e,0x327225202c353432\n"
".quad 0x0a3b3432202c3434,0x3233622e6c687309,0x2c36343272250920,0x202c353432722520\n"
".quad 0x2e726f090a3b3631,0x3272250920323362,0x34327225202c3734,0x3634327225202c33\n"
".quad 0x732e627573090a3b,0x3338722509203233,0x2c3734327225202c,0x617262090a3b3120\n"
".quad 0x4c240920696e752e,0x353931365f395f74,0x395f744c240a3b34,0x0a3a32383432355f\n"
".quad 0x093509636f6c2e09,0x090a300937313231,0x203233662e766f6d,0x25202c3136662509\n"
".quad 0x6f6d090a3b333366,0x2509203233662e76,0x336625202c323666,0x2e766f6d090a3b34\n"
".quad 0x3666250920323366,0x3030306630202c33,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c343666250920,0x6d090a3b33366625,0x09203233662e766f\n"
".quad 0x6630202c35366625,0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020\n"
".quad 0x3666250920323366,0x3b35366625202c36,0x64322e786574090a,0x2e3233752e34762e\n"
".quad 0x3272257b20323366,0x39343272252c3834,0x252c30353272252c,0x635b2c7d31353272\n"
".quad 0x746e6572646c6968,0x313666257b2c7865,0x66252c323666252c,0x7d363666252c3436\n"
".quad 0x636f6c2e090a3b5d,0x3009383134093509,0x33732e766f6d090a,0x3235327225092032\n"
".quad 0x3b3834327225202c,0x33732e766f6d090a,0x3335327225092032,0x3b3934327225202c\n"
".quad 0x33732e766f6d090a,0x3435327225092032,0x3b3035327225202c,0x33732e766f6d090a\n"
".quad 0x3535327225092032,0x3b3135327225202c,0x3509636f6c2e090a,0x0a30093731323109\n"
".quad 0x3233732e766f6d09,0x2c36353272250920,0x746573090a3b3020,0x3233732e71652e70\n"
".quad 0x202c313270250920,0x25202c3530317225,0x40090a3b36353272,0x7262203132702521\n"
".quad 0x395f744c24092061,0x0a3b38373536355f,0x093509636f6c2e09,0x090a300935323231\n"
".quad 0x61626f6c672e646c,0x2509203631752e6c,0x255b202c37353272,0x3b5d38312b346472\n"
".quad 0x33732e646461090a,0x3835327225092032,0x202c33387225202c,0x090a3b3735327225\n"
".quad 0x2e3436752e747663,0x6472250920323373,0x35327225202c3831,0x2e646461090a3b38\n"
".quad 0x6472250920343675,0x31647225202c3931,0x3131647225202c38,0x6c672e646c090a3b\n"
".quad 0x2038732e6c61626f,0x202c393532722509,0x312b39316472255b,0x2e617262090a3b5d\n"
".quad 0x744c240920696e75,0x32323336355f395f,0x5f395f744c240a3b,0x090a3a3837353635\n"
".quad 0x203233732e766f6d,0x202c393532722509,0x395f744c240a3b30,0x0a3a32323336355f\n"
".quad 0x3233752e766f6d09,0x2c30363272250920,0x6573090a3b353620,0x33732e656e2e7074\n"
".quad 0x2c32327025092032,0x202c373031722520,0x090a3b3036327225,0x7262203232702540\n"
".quad 0x395f744c24092061,0x0a3b34333836355f,0x3233622e6c687309,0x2c31363272250920\n"
".quad 0x202c323532722520,0x2e726873090a3b38,0x3272250920323375,0x36327225202c3236\n"
".quad 0x090a3b3432202c31,0x203233622e6c6873,0x202c333632722509,0x32202c3235327225\n"
".quad 0x2e726873090a3b34,0x3272250920323375,0x36327225202c3436,0x090a3b3432202c33\n"
".quad 0x203233622e6c6873,0x202c353632722509,0x31202c3235327225,0x2e726873090a3b36\n"
".quad 0x3272250920323375,0x36327225202c3636,0x090a3b3432202c35,0x203233752e766f6d\n"
".quad 0x202c373632722509,0x2e746573090a3b30,0x752e3233752e656e,0x3632722509203233\n"
".quad 0x3236327225202c38,0x3b3736327225202c,0x33732e67656e090a,0x3936327225092032\n"
".quad 0x3b3836327225202c,0x33752e766f6d090a,0x3037327225092032,0x6573090a3b30202c\n"
".quad 0x3233752e656e2e74,0x722509203233752e,0x327225202c313732,0x37327225202c3436\n"
".quad 0x2e67656e090a3b30,0x3272250920323373,0x37327225202c3237,0x2e766f6d090a3b31\n"
".quad 0x3272250920323375,0x090a3b30202c3337,0x752e656e2e746573,0x09203233752e3233\n"
".quad 0x25202c3437327225,0x7225202c36363272,0x656e090a3b333732,0x2509203233732e67\n"
".quad 0x7225202c35373272,0x726f090a3b343732,0x722509203233622e,0x327225202c363732\n"
".quad 0x37327225202c3237,0x622e726f090a3b35,0x3732722509203233,0x3936327225202c37\n"
".quad 0x3b3637327225202c,0x33752e766f6d090a,0x3837327225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c33327025092032,0x202c373732722520,0x090a3b3837327225\n"
".quad 0x7262203332702540,0x395f744c24092061,0x0a3b36343337355f,0x093509636f6c2e09\n"
".quad 0x61090a3009363932,0x09203233622e646e,0x25202c3937327225,0x3531202c32363272\n"
".quad 0x622e6c6873090a3b,0x3832722509203233,0x3937327225202c30,0x726f090a3b38202c\n"
".quad 0x722509203233622e,0x327225202c313832,0x38327225202c3436,0x2e646e61090a3b30\n"
".quad 0x3272250920323362,0x36327225202c3238,0x0a3b303432202c32,0x3233622e6c687309\n"
".quad 0x2c33383272250920,0x202c323832722520,0x622e726f090a3b34,0x3832722509203233\n"
".quad 0x3636327225202c34,0x3b3338327225202c,0x33622e6c6873090a,0x3538327225092032\n"
".quad 0x2c3438327225202c,0x726f090a3b363120,0x722509203233622e,0x38327225202c3231\n"
".quad 0x3538327225202c31,0x09636f6c2e090a3b,0x3009363332310935,0x6e752e617262090a\n"
".quad 0x395f744c24092069,0x4c240a3b3835325f,0x343337355f395f74,0x2e766f6d090a3a36\n"
".quad 0x3172250920323373,0x0a3b3736202c3730,0x36355f395f744c24,0x6f6d090a3a343338\n"
".quad 0x2509203233752e76,0x3736202c36383272,0x2e70746573090a3b,0x09203233732e656e\n"
".quad 0x7225202c34327025,0x327225202c373031,0x702540090a3b3638,0x0920617262203432\n"
".quad 0x37355f395f744c24,0x6873090a3b383538,0x2509203233622e6c,0x7225202c37383272\n"
".quad 0x3b3631202c333532,0x33752e726873090a,0x3838327225092032,0x2c3738327225202c\n"
".quad 0x6873090a3b343220,0x2509203233622e6c,0x7225202c39383272,0x3b3432202c333532\n"
".quad 0x33752e726873090a,0x3039327225092032,0x2c3938327225202c,0x6f6d090a3b343220\n"
".quad 0x2509203233752e76,0x7225202c31393272,0x6873090a3b323532,0x2509203233752e72\n"
".quad 0x7225202c32393272,0x3b3432202c313932,0x33752e766f6d090a,0x3339327225092032\n"
".quad 0x6573090a3b30202c,0x3233752e656e2e74,0x722509203233752e,0x327225202c343932\n"
".quad 0x39327225202c3838,0x2e67656e090a3b33,0x3272250920323373,0x39327225202c3539\n"
".quad 0x2e766f6d090a3b34,0x3272250920323375,0x090a3b30202c3639,0x752e656e2e746573\n"
".quad 0x09203233752e3233,0x25202c3739327225,0x7225202c30393272,0x656e090a3b363932\n"
".quad 0x2509203233732e67,0x7225202c38393272,0x6f6d090a3b373932,0x2509203233752e76\n"
".quad 0x3b30202c39393272,0x656e2e746573090a,0x3233752e3233752e,0x2c30303372250920\n"
".quad 0x202c323932722520,0x090a3b3939327225,0x203233732e67656e,0x202c313033722509\n"
".quad 0x090a3b3030337225,0x09203233622e726f,0x25202c3230337225,0x7225202c38393272\n"
".quad 0x726f090a3b313033,0x722509203233622e,0x327225202c333033,0x30337225202c3539\n"
".quad 0x2e766f6d090a3b32,0x3372250920323375,0x090a3b30202c3430,0x2e71652e70746573\n"
".quad 0x3270250920323373,0x3330337225202c35,0x3b3430337225202c,0x203532702540090a\n"
".quad 0x744c240920617262,0x30373338355f395f,0x09636f6c2e090a3b,0x0a30093639320935\n"
".quad 0x3233622e646e6109,0x2c35303372250920,0x202c383832722520,0x6c6873090a3b3531\n"
".quad 0x722509203233622e,0x337225202c363033,0x090a3b38202c3530,0x09203233622e726f\n"
".quad 0x25202c3730337225,0x7225202c32393272,0x6e61090a3b363033,0x2509203233622e64\n"
".quad 0x7225202c38303372,0x303432202c383832,0x622e6c6873090a3b,0x3033722509203233\n"
".quad 0x3830337225202c39,0x726f090a3b34202c,0x722509203233622e,0x327225202c303133\n"
".quad 0x30337225202c3039,0x2e6c6873090a3b39,0x3372250920323362,0x31337225202c3131\n"
".quad 0x090a3b3631202c30,0x09203233622e726f,0x7225202c32317225,0x337225202c373033\n"
".quad 0x6f6c2e090a3b3131,0x3834323109350963,0x2e617262090a3009,0x744c240920696e75\n"
".quad 0x0a3b3835325f395f,0x38355f395f744c24,0x6f6d090a3a303733,0x2509203233732e76\n"
".quad 0x3137202c37303172,0x5f395f744c240a3b,0x090a3a3835383735,0x203233752e766f6d\n"
".quad 0x202c323133722509,0x746573090a3b3137,0x3233732e656e2e70,0x202c363270250920\n"
".quad 0x25202c3730317225,0x40090a3b32313372,0x6172622036327025,0x5f395f744c240920\n"
".quad 0x090a3b3238383835,0x203233622e6c6873,0x202c333133722509,0x32202c3435327225\n"
".quad 0x2e726873090a3b34,0x3372250920323375,0x31337225202c3431,0x090a3b3432202c33\n"
".quad 0x203233622e6c6873,0x202c353133722509,0x38202c3335327225,0x752e726873090a3b\n"
".quad 0x3133722509203233,0x3531337225202c36,0x6d090a3b3432202c,0x09203233752e766f\n"
".quad 0x25202c3731337225,0x73090a3b33353272,0x09203233752e7268,0x25202c3831337225\n"
".quad 0x3432202c37313372,0x752e766f6d090a3b,0x3133722509203233,0x73090a3b30202c39\n"
".quad 0x33752e656e2e7465,0x2509203233752e32,0x7225202c30323372,0x337225202c343133\n"
".quad 0x67656e090a3b3931,0x722509203233732e,0x337225202c313233,0x766f6d090a3b3032\n"
".quad 0x722509203233752e,0x0a3b30202c323233,0x2e656e2e74657309,0x203233752e323375\n"
".quad 0x202c333233722509,0x25202c3631337225,0x6e090a3b32323372,0x09203233732e6765\n"
".quad 0x25202c3432337225,0x6d090a3b33323372,0x09203233752e766f,0x30202c3532337225\n"
".quad 0x6e2e746573090a3b,0x33752e3233752e65,0x3632337225092032,0x2c3831337225202c\n"
".quad 0x0a3b353233722520,0x3233732e67656e09,0x2c37323372250920,0x0a3b363233722520\n"
".quad 0x203233622e726f09,0x202c383233722509,0x25202c3432337225,0x6f090a3b37323372\n"
".quad 0x2509203233622e72,0x7225202c39323372,0x337225202c313233,0x766f6d090a3b3832\n"
".quad 0x722509203233752e,0x0a3b30202c303333,0x71652e7074657309,0x702509203233732e\n"
".quad 0x32337225202c3732,0x3033337225202c39,0x3732702540090a3b,0x4c24092061726220\n"
".quad 0x393339355f395f74,0x636f6c2e090a3b34,0x3009363932093509,0x33622e646e61090a\n"
".quad 0x3133337225092032,0x2c3431337225202c,0x6873090a3b353120,0x2509203233622e6c\n"
".quad 0x7225202c32333372,0x0a3b38202c313333,0x203233622e726f09,0x202c333333722509\n"
".quad 0x25202c3631337225,0x61090a3b32333372,0x09203233622e646e,0x25202c3433337225\n"
".quad 0x3432202c34313372,0x2e6c6873090a3b30,0x3372250920323362,0x33337225202c3533\n"
".quad 0x6f090a3b34202c34,0x2509203233622e72,0x7225202c36333372,0x337225202c383133\n"
".quad 0x6c6873090a3b3533,0x722509203233622e,0x337225202c373333,0x0a3b3631202c3633\n"
".quad 0x203233622e726f09,0x25202c3231722509,0x7225202c33333372,0x6c2e090a3b373333\n"
".quad 0x353231093509636f,0x617262090a300939,0x4c240920696e752e,0x3b3835325f395f74\n"
".quad 0x355f395f744c240a,0x6d090a3a34393339,0x09203233732e766f,0x38202c3730317225\n"
".quad 0x395f744c240a3b34,0x0a3a32383838355f,0x3233752e766f6d09,0x2c38333372250920\n"
".quad 0x6573090a3b343820,0x33732e656e2e7074,0x2c38327025092032,0x202c373031722520\n"
".quad 0x090a3b3833337225,0x7262203832702540,0x395f744c24092061,0x0a3b36303939355f\n"
".quad 0x3233752e766f6d09,0x2c39333372250920,0x0a3b343532722520,0x3233752e72687309\n"
".quad 0x2c30343372250920,0x202c393333722520,0x6c6873090a3b3432,0x722509203233622e\n"
".quad 0x327225202c313433,0x0a3b3631202c3435,0x3233752e72687309,0x2c32343372250920\n"
".quad 0x202c313433722520,0x6c6873090a3b3432,0x722509203233622e,0x327225202c333433\n"
".quad 0x090a3b38202c3435,0x203233752e726873,0x202c343433722509,0x32202c3334337225\n"
".quad 0x2e766f6d090a3b34,0x3372250920323375,0x090a3b30202c3534,0x752e656e2e746573\n"
".quad 0x09203233752e3233,0x25202c3634337225,0x7225202c30343372,0x656e090a3b353433\n"
".quad 0x2509203233732e67,0x7225202c37343372,0x6f6d090a3b363433,0x2509203233752e76\n"
".quad 0x3b30202c38343372,0x656e2e746573090a,0x3233752e3233752e,0x2c39343372250920\n"
".quad 0x202c323433722520,0x090a3b3834337225,0x203233732e67656e,0x202c303533722509\n"
".quad 0x090a3b3934337225,0x203233752e766f6d,0x202c313533722509,0x2e746573090a3b30\n"
".quad 0x752e3233752e656e,0x3533722509203233,0x3434337225202c32,0x3b3135337225202c\n"
".quad 0x33732e67656e090a,0x3335337225092032,0x3b3235337225202c,0x3233622e726f090a\n"
".quad 0x2c34353372250920,0x202c303533722520,0x090a3b3335337225,0x09203233622e726f\n"
".quad 0x25202c3535337225,0x7225202c37343372,0x6f6d090a3b343533,0x2509203233752e76\n"
".quad 0x3b30202c36353372,0x652e70746573090a,0x2509203233732e71,0x337225202c393270\n"
".quad 0x35337225202c3535,0x32702540090a3b36,0x2409206172622039,0x3430365f395f744c\n"
".quad 0x6f6c2e090a3b3831,0x0936393209350963,0x622e646e61090a30,0x3533722509203233\n"
".quad 0x3034337225202c37,0x73090a3b3531202c,0x09203233622e6c68,0x25202c3835337225\n"
".quad 0x3b38202c37353372,0x3233622e726f090a,0x2c39353372250920,0x202c323433722520\n"
".quad 0x090a3b3835337225,0x203233622e646e61,0x202c303633722509,0x32202c3034337225\n"
".quad 0x6c6873090a3b3034,0x722509203233622e,0x337225202c313633,0x090a3b34202c3036\n"
".quad 0x09203233622e726f,0x25202c3236337225,0x7225202c34343372,0x6873090a3b313633\n"
".quad 0x2509203233622e6c,0x7225202c33363372,0x3b3631202c323633,0x3233622e726f090a\n"
".quad 0x202c323172250920,0x25202c3935337225,0x2e090a3b33363372,0x3231093509636f6c\n"
".quad 0x7262090a30093037,0x240920696e752e61,0x3835325f395f744c,0x5f395f744c240a3b\n"
".quad 0x090a3a3831343036,0x203233732e766f6d,0x202c373031722509,0x5f744c240a3b3633\n"
".quad 0x3a36303939355f39,0x33752e766f6d090a,0x3436337225092032,0x73090a3b3633202c\n"
".quad 0x732e656e2e707465,0x3033702509203233,0x2c3730317225202c,0x0a3b343633722520\n"
".quad 0x6220303370254009,0x5f744c2409206172,0x3b38393631365f39,0x33622e6c6873090a\n"
".quad 0x3536337225092032,0x2c3535327225202c,0x726873090a3b3820,0x722509203233752e\n"
".quad 0x337225202c363633,0x0a3b3432202c3536,0x3233622e6c687309,0x2c37363372250920\n"
".quad 0x202c353532722520,0x726873090a3b3432,0x722509203233752e,0x337225202c383633\n"
".quad 0x0a3b3432202c3736,0x3233622e6c687309,0x2c39363372250920,0x202c353532722520\n"
".quad 0x726873090a3b3631,0x722509203233752e,0x337225202c303733,0x0a3b3432202c3936\n"
".quad 0x3233752e766f6d09,0x2c31373372250920,0x746573090a3b3020,0x2e3233752e656e2e\n"
".quad 0x3372250920323375,0x36337225202c3237,0x3137337225202c36,0x732e67656e090a3b\n"
".quad 0x3733722509203233,0x3237337225202c33,0x752e766f6d090a3b,0x3733722509203233\n"
".quad 0x73090a3b30202c34,0x33752e656e2e7465,0x2509203233752e32,0x7225202c35373372\n"
".quad 0x337225202c383633,0x67656e090a3b3437,0x722509203233732e,0x337225202c363733\n"
".quad 0x766f6d090a3b3537,0x722509203233752e,0x0a3b30202c373733,0x2e656e2e74657309\n"
".quad 0x203233752e323375,0x202c383733722509,0x25202c3037337225,0x6e090a3b37373372\n"
".quad 0x09203233732e6765,0x25202c3937337225,0x6f090a3b38373372,0x2509203233622e72\n"
".quad 0x7225202c30383372,0x337225202c363733,0x2e726f090a3b3937,0x3372250920323362\n"
".quad 0x37337225202c3138,0x3038337225202c33,0x752e766f6d090a3b,0x3833722509203233\n"
".quad 0x73090a3b30202c32,0x732e71652e707465,0x3133702509203233,0x2c3138337225202c\n"
".quad 0x0a3b323833722520,0x6220313370254009,0x5f744c2409206172,0x3b38393631365f39\n"
".quad 0x3509636f6c2e090a,0x090a300936393209,0x203233622e646e61,0x202c333833722509\n"
".quad 0x31202c3636337225,0x2e6c6873090a3b35,0x3372250920323362,0x38337225202c3438\n"
".quad 0x6f090a3b38202c33,0x2509203233622e72,0x7225202c35383372,0x337225202c383633\n"
".quad 0x646e61090a3b3438,0x722509203233622e,0x337225202c363833,0x3b303432202c3636\n"
".quad 0x33622e6c6873090a,0x3738337225092032,0x2c3638337225202c,0x2e726f090a3b3420\n"
".quad 0x3372250920323362,0x37337225202c3838,0x3738337225202c30,0x622e6c6873090a3b\n"
".quad 0x3833722509203233,0x3838337225202c39,0x6f090a3b3631202c,0x2509203233622e72\n"
".quad 0x337225202c323172,0x38337225202c3538,0x636f6c2e090a3b39,0x0931383231093509\n"
".quad 0x752e617262090a30,0x5f744c240920696e,0x240a3b3835325f39,0x3631365f395f744c\n"
".quad 0x5f744c240a3a3839,0x3a30333930365f39,0x3509636f6c2e090a,0x0a30093638323109\n"
".quad 0x3233732e766f6d09,0x2c36303172250920,0x5f744c240a3b3120,0x090a3a3835325f39\n"
".quad 0x31093509636f6c2e,0x6d090a3009373832,0x09203233752e766f,0x30202c3039337225\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x7225202c32337025,0x337225202c363031\n"
".quad 0x702540090a3b3039,0x0920617262203233,0x31365f395f744c24,0x2140090a3b343539\n"
".quad 0x6172622031327025,0x5f395f744c240920,0x090a3b3232373236,0x2e656e2e70746573\n"
".quad 0x3370250920323373,0x3935327225202c33,0x3b3730317225202c,0x203333702540090a\n"
".quad 0x744c240920617262,0x34333233365f395f,0x09636f6c2e090a3b,0x3009363932310935\n"
".quad 0x33622e646e61090a,0x3139337225092032,0x202c32317225202c,0x090a3b3533353536\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x7225202c37366625,0x6f6d090a3b313933\n"
".quad 0x2509203233662e76,0x366625202c383666,0x2e726873090a3b37,0x3372250920323375\n"
".quad 0x32317225202c3239,0x63090a3b3631202c,0x33662e6e722e7476,0x2509203233752e32\n"
".quad 0x337225202c393666,0x766f6d090a3b3239,0x662509203233662e,0x39366625202c3037\n"
".quad 0x662e766f6d090a3b,0x3137662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x203233662e766f6d,0x25202c3237662509,0x6f6d090a3b313766\n"
".quad 0x2509203233662e76,0x306630202c333766,0x3b30303030303030,0x202f2f0920202020\n"
".quad 0x662e766f6d090a30,0x3437662509203233,0x0a3b33376625202c,0x2e64322e78657409\n"
".quad 0x662e3233752e3476,0x393372257b203233,0x2c34393372252c33,0x72252c3539337225\n"
".quad 0x6f6e5b2c7d363933,0x257b2c7865746564,0x303766252c383666,0x66252c323766252c\n"
".quad 0x2e090a3b5d7d3437,0x3733093509636f6c,0x766f6d090a300935,0x722509203233732e\n"
".quad 0x337225202c373933,0x766f6d090a3b3339,0x722509203233732e,0x337225202c383933\n"
".quad 0x6f6c2e090a3b3639,0x3639323109350963,0x6c2e7473090a3009,0x3233752e6c61636f\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x393534345f726176,0x6e6f6e5f36315f37\n"
".quad 0x6e5f74736e6f635f,0x302b36315f65646f,0x3739337225202c5d,0x6f6c2e7473090a3b\n"
".quad 0x203233752e6c6163,0x616475635f5f5b09,0x765f6c61636f6c5f,0x37393534345f7261\n"
".quad 0x5f6e6f6e5f36315f,0x6f6e5f74736e6f63,0x32312b36315f6564,0x3839337225202c5d\n"
".quad 0x09636f6c2e090a3b,0x3009373932310935,0x33622e6c6873090a,0x3939337225092032\n"
".quad 0x2c3839337225202c,0x6873090a3b363120,0x2509203233752e72,0x7225202c30303472\n"
".quad 0x3b3432202c393933,0x33622e6c6873090a,0x3130347225092032,0x2c3030347225202c\n"
".quad 0x6c6873090a3b3820,0x722509203233622e,0x337225202c323034,0x0a3b3432202c3839\n"
".quad 0x3233752e72687309,0x2c33303472250920,0x202c323034722520,0x2e726f090a3b3432\n"
".quad 0x3472250920323362,0x30347225202c3430,0x3330347225202c31,0x622e6c6873090a3b\n"
".quad 0x3034722509203233,0x3839337225202c35,0x6873090a3b38202c,0x2509203233752e72\n"
".quad 0x7225202c36303472,0x3b3432202c353034,0x33622e6c6873090a,0x3730347225092032\n"
".quad 0x2c3630347225202c,0x726f090a3b363120,0x722509203233622e,0x347225202c383034\n"
".quad 0x30347225202c3430,0x2e627573090a3b37,0x3872250920323373,0x3830347225202c33\n"
".quad 0x6573090a3b31202c,0x33752e656e2e7074,0x2c34337025092032,0x25202c3131722520\n"
".quad 0x2540090a3b323172,0x2061726220343370,0x365f395f744c2409,0x6c090a3b36363432\n"
".quad 0x6c61626f6c672e64,0x722509203631752e,0x6472255b202c3538,0x090a3b5d36312b34\n"
".quad 0x203233752e766f6d,0x202c393034722509,0x70746573090a3b30,0x203233752e71652e\n"
".quad 0x25202c3533702509,0x347225202c353872,0x702540090a3b3930,0x0920617262203533\n"
".quad 0x34365f395f744c24,0x6c2e090a3b323030,0x303331093509636f,0x6c6873090a300939\n"
".quad 0x722509203233622e,0x337225202c303134,0x090a3b38202c3739,0x203233752e726873\n"
".quad 0x25202c3533722509,0x3432202c30313472,0x622e6c6873090a3b,0x3134722509203233\n"
".quad 0x3739337225202c31,0x73090a3b3432202c,0x09203233752e7268,0x7225202c37337225\n"
".quad 0x3b3432202c313134,0x33622e6c6873090a,0x3231347225092032,0x2c3739337225202c\n"
".quad 0x6873090a3b363120,0x2509203233752e72,0x347225202c393372,0x0a3b3432202c3231\n"
".quad 0x3233622e646e6109,0x202c303472250920,0x3531202c35337225,0x622e646e61090a3b\n"
".quad 0x3134722509203233,0x202c35337225202c,0x6873090a3b303432,0x2509203233622e6c\n"
".quad 0x347225202c323472,0x73090a3b38202c30,0x09203233622e6c68,0x7225202c33347225\n"
".quad 0x090a3b34202c3134,0x09203233622e726f,0x7225202c34347225,0x37337225202c3234\n"
".quad 0x33622e726f090a3b,0x2c35347225092032,0x25202c3334722520,0x6873090a3b393372\n"
".quad 0x2509203233622e6c,0x347225202c363472,0x090a3b3631202c35,0x09203233622e726f\n"
".quad 0x7225202c37347225,0x36347225202c3434,0x622e646e61090a3b,0x3134722509203233\n"
".quad 0x2c37347225202c33,0x0a3b353335353620,0x2e6e722e74766309,0x203233752e323366\n"
".quad 0x25202c3537662509,0x6d090a3b33313472,0x09203233662e766f,0x6625202c36376625\n"
".quad 0x726873090a3b3537,0x722509203233752e,0x347225202c343134,0x090a3b3631202c37\n"
".quad 0x662e6e722e747663,0x09203233752e3233,0x7225202c37376625,0x6f6d090a3b343134\n"
".quad 0x2509203233662e76,0x376625202c383766,0x2e766f6d090a3b37,0x3766250920323366\n"
".quad 0x3030306630202c39,0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09\n"
".quad 0x202c303866250920,0x6d090a3b39376625,0x09203233662e766f,0x6630202c31386625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x2e766f6d090a3020,0x3866250920323366\n"
".quad 0x3b31386625202c32,0x64322e786574090a,0x2e3233752e34762e,0x3472257b20323366\n"
".quad 0x36313472252c3531,0x252c37313472252c,0x6e5b2c7d38313472,0x7b2c78657465646f\n"
".quad 0x3766252c36376625,0x252c303866252c38,0x090a3b5d7d323866,0x33093509636f6c2e\n"
".quad 0x6f6d090a30093537,0x2509203233732e76,0x347225202c303272,0x766f6d090a3b3531\n"
".quad 0x722509203233732e,0x347225202c393134,0x6f6c2e090a3b3831,0x3930333109350963\n"
".quad 0x6c2e7473090a3009,0x3233752e6c61636f,0x6475635f5f5b0920,0x5f6c61636f6c5f61\n"
".quad 0x393534345f726176,0x6e6f6e5f36315f37,0x6e5f74736e6f635f,0x302b36315f65646f\n"
".quad 0x3b30327225202c5d,0x636f6c2e7473090a,0x09203233752e6c61,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f37393534345f72,0x635f6e6f6e5f3631,0x646f6e5f74736e6f\n"
".quad 0x5d32312b36315f65,0x3b3931347225202c,0x3509636f6c2e090a,0x0a30093031333109\n"
".quad 0x3233622e6c687309,0x2c30323472250920,0x202c393134722520,0x726873090a3b3631\n"
".quad 0x722509203233752e,0x347225202c313234,0x0a3b3432202c3032,0x3233622e6c687309\n"
".quad 0x2c32323472250920,0x202c313234722520,0x2e6c6873090a3b38,0x3472250920323362\n"
".quad 0x31347225202c3332,0x090a3b3432202c39,0x203233752e726873,0x202c343234722509\n"
".quad 0x32202c3332347225,0x622e726f090a3b34,0x3234722509203233,0x3232347225202c35\n"
".quad 0x3b3432347225202c,0x33622e6c6873090a,0x3632347225092032,0x2c3931347225202c\n"
".quad 0x726873090a3b3820,0x722509203233752e,0x347225202c373234,0x0a3b3432202c3632\n"
".quad 0x3233622e6c687309,0x2c38323472250920,0x202c373234722520,0x2e726f090a3b3631\n"
".quad 0x3472250920323362,0x32347225202c3932,0x3832347225202c35,0x732e646461090a3b\n"
".quad 0x3334722509203233,0x2c35387225202c30,0x0a3b393234722520,0x3233732e62757309\n"
".quad 0x202c333872250920,0x31202c3033347225,0x5f395f744c240a3b,0x090a3a3230303436\n"
".quad 0x203233732e766f6d,0x202c353031722509,0x2e617262090a3b31,0x744c240920696e75\n"
".quad 0x36363432365f395f,0x5f395f744c240a3b,0x090a3a3433323336,0x31093509636f6c2e\n"
".quad 0x6d090a3009363133,0x09203233732e766f,0x31202c3530317225,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b36363432365f39,0x365f395f744c240a,0x2e090a3a32323732\n"
".quad 0x3331093509636f6c,0x6461090a30093132,0x2509203233732e64,0x7225202c35303172\n"
".quad 0x0a3b31202c353031,0x32365f395f744c24,0x6f6d090a3a363634,0x2509203233732e76\n"
".quad 0x3536202c37303172,0x5f395f744c240a3b,0x240a3a3435393136,0x3232355f395f744c\n"
".quad 0x746573090a3a3632,0x3233752e656e2e70,0x202c363370250920,0x7225202c32317225\n"
".quad 0x702540090a3b3536,0x0920617262203633,0x31355f395f744c24,0x424c240a3b303739\n"
".quad 0x31315a5f5f313842,0x72654b746e697270,0x74614d39506c656e,0x50696f666e496863\n"
".quad 0x656d6e67696c4139,0x53694b506350746e,0x3a69696969695f35,0x3509636f6c2e090a\n"
".quad 0x0a30093832333109,0x240a3b7469786509,0x5f5f646e6557444c,0x746e69727031315a\n"
".quad 0x39506c656e72654b,0x666e49686374614d,0x67696c413950696f,0x506350746e656d6e\n"
".quad 0x6969695f3553694b,0x2f207d090a3a6969,0x727031315a5f202f,0x656e72654b746e69\n"
".quad 0x686374614d39506c,0x413950696f666e49,0x746e656d6e67696c,0x5f3553694b506350\n"
".quad 0x2e090a6969696969,0x2e206c61626f6c67,0x7220666572786574,0x090a3b7865746665\n"
".quad 0x206c61626f6c672e,0x206665727865742e,0x0a3b786574797271,0x008801000002000a\n"
".quad 0x0000000023940000,0x0000000000000000,0x0017000100040000,0x004a000000380000\n"
".quad 0x0000000000150000,0x0000000000000000,0x2f656d6f682f0000,0x632f6c616d726f6e\n"
".quad 0x2f74756f6b636568,0x6f6c65636f757067,0x2f73747365742f74,0x2f61696e69646f72\n"
".quad 0x756d2f7374736574,0x2f75706772656d6d,0x706772656d6d756d,0x0000000075632e75\n"
".quad 0x0102464c457f0000,0x0000000000043301,0x000100be00020000,0x0000000000000000\n"
".quad 0x0000000022b40000,0x0000000000400000,0x0040001405170000,0x000e004000040038\n"
".quad 0x0000000000000001,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0003000000010000,0x0000000000000000,0x0000000000000000,0x0000000003c00000\n"
".quad 0x0000000002220000,0x0000000000000000,0x0000000000040000,0x0000000000000000\n"
".quad 0x00030000000b0000,0x0000000000000000,0x0000000000000000,0x0000000005e20000\n"
".quad 0x0000000000a70000,0x0000000000000000,0x0000000000010000,0x0000000000000000\n"
".quad 0x0002000000130000,0x0000000000000000,0x0000000000000000,0x0000000006890000\n"
".quad 0x0000000002280000,0x0010000000020000,0x0000000000010000,0x0000000000180000\n"
".quad 0x00010000011f0000,0x0000000000060000,0x0000000000000000,0x0000000008b10000\n"
".quad 0x0000000006d80000,0x000b000000030000,0x0000000000041200,0x0000000000000000\n"
".quad 0x0001000001f10000,0x0000000000020000,0x0000000000000000,0x000000000f890000\n"
".quad 0x0000000000500000,0x0004000000000000,0x0000000000040000,0x0000000000000000\n"
".quad 0x0001000001480000,0x0000000000020000,0x0000000000000000,0x000000000fd90000\n"
".quad 0x0000000000c40000,0x0004000000000000,0x0000000000010000,0x0000000000000000\n"
".quad 0x0001000000b60000,0x0000000000060000,0x0000000000000000,0x00000000109d0000\n"
".quad 0x0000000000100000,0x0009000000030000,0x0000000000040200,0x0000000000000000\n"
".quad 0x0001000001740000,0x0000000000020000,0x0000000000000000,0x0000000010ad0000\n"
".quad 0x0000000000480000,0x0007000000000000,0x0000000000040000,0x0000000000000000\n"
".quad 0x0001000000e90000,0x0000000000020000,0x0000000000000000,0x0000000010f50000\n"
".quad 0x00000000008c0000,0x0007000000000000,0x0000000000010000,0x0000000000000000\n"
".quad 0x0001000000360000,0x0000000000060000,0x0000000000000000,0x0000000011810000\n"
".quad 0x000000000f200000,0x0006000000030000,0x0000000000041800,0x0000000000000000\n"
".quad 0x0001000001af0000,0x0000000000020000,0x0000000000000000,0x0000000020a10000\n"
".quad 0x0000000000640000,0x000a000000000000,0x0000000000040000,0x0000000000000000\n"
".quad 0x0001000000700000,0x0000000000020000,0x0000000000000000,0x0000000021050000\n"
".quad 0x0000000001140000,0x000a000000000000,0x0000000000010000,0x0000000000000000\n"
".quad 0x0001000000ad0000,0x0000000000020000,0x0000000000000000,0x0000000022190000\n"
".quad 0x0000000000980000,0x0000000000000000,0x0000000000010000,0x0000000000000000\n"
".quad 0x747368732e000000,0x74732e0062617472,0x79732e0062617472,0x766e2e006261746d\n"
".quad 0x2e6c61626f6c672e,0x766e2e0074696e69,0x006c61626f6c672e,0x5a5f2e747865742e\n"
".quad 0x4b746e6972703131,0x4d39506c656e7265,0x6f666e4968637461,0x6e67696c41395069\n"
".quad 0x4b506350746e656d,0x696969695f355369,0x6e692e766e2e0069,0x7031315a5f2e6f66\n"
".quad 0x6e72654b746e6972,0x6374614d39506c65,0x3950696f666e4968,0x6e656d6e67696c41\n"
".quad 0x3553694b50635074,0x2e0069696969695f,0x006f666e692e766e,0x5a5f2e747865742e\n"
".quad 0x72656d6d756d3731,0x72654b4352757067,0x614d3031506c656e,0x64726f6f43686374\n"
".quad 0x5f3353694b506350,0x692e766e2e006969,0x37315a5f2e6f666e,0x706772656d6d756d\n"
".quad 0x656e72654b435275,0x6374614d3031506c,0x635064726f6f4368,0x69695f3353694b50\n"
".quad 0x5f2e747865742e00,0x656d6d756d35315a,0x6e72654b75706772,0x3053635076506c65\n"
".quad 0x695f3253694b505f,0x6e692e766e2e0069,0x6d35315a5f2e6f66,0x75706772656d6d75\n"
".quad 0x76506c656e72654b,0x694b505f30536350,0x6e2e0069695f3253,0x6174736e6f632e76\n"
".quad 0x37315a5f2e30746e,0x706772656d6d756d,0x656e72654b435275,0x6374614d3031506c\n"
".quad 0x635064726f6f4368,0x69695f3353694b50,0x6e6f632e766e2e00,0x5f2e30746e617473\n"
".quad 0x746e69727031315a,0x39506c656e72654b,0x666e49686374614d,0x67696c413950696f\n"
".quad 0x506350746e656d6e,0x6969695f3553694b,0x632e766e2e006969,0x30746e6174736e6f\n"
".quad 0x6d756d35315a5f2e,0x654b75706772656d,0x635076506c656e72,0x3253694b505f3053\n"
".quad 0x315a5f000069695f,0x654b746e69727031,0x614d39506c656e72,0x696f666e49686374\n"
".quad 0x6d6e67696c413950,0x694b506350746e65,0x69696969695f3553,0x6d756d37315a5f00\n"
".quad 0x435275706772656d,0x31506c656e72654b,0x6f43686374614d30,0x694b50635064726f\n"
".quad 0x5a5f0069695f3353,0x72656d6d756d3531,0x656e72654b757067,0x5f3053635076506c\n"
".quad 0x69695f3253694b50,0x78657465646f6e00,0x6572646c69686300,0x666572007865746e\n"
".quad 0x7479727100786574,0x0000000000007865,0x0000000000000000,0x0000000000000000\n"
".quad 0x0300000000000000,0x0000000000000100,0x0000000000000000,0x0300000000000000\n"
".quad 0x0000000000000200,0x0000000000000000,0x0300000000000000,0x0000000000000300\n"
".quad 0x0000000000000000,0x0300000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0300000000000000,0x0000000000000000,0x0000000000000000,0x0300000000000000\n"
".quad 0x0000000000000a00,0x0000000f20000000,0x0300000000000000,0x0000000000000c00\n"
".quad 0x0000000000000000,0x0300000000000000,0x0000000000000d00,0x0000000000000000\n"
".quad 0x0300000000000000,0x0000000000000700,0x0000000010000000,0x0300000000000000\n"
".quad 0x0000000000000900,0x0000000000000000,0x0300000000000000,0x0000000000000400\n"
".quad 0x00000006d8000000,0x0300000000000000,0x0000000000000600,0x0000000000000000\n"
".quad 0x0300000000000000,0x0000000000000800,0x0000000000000000,0x0300000000000000\n"
".quad 0x0000000000000b00,0x0000000000000000,0x0300000000000000,0x0000000000000500\n"
".quad 0x0000000000000000,0x1200000001000000,0x0000000000000a10,0x0000000f20000000\n"
".quad 0x1200000035000000,0x0000000000000710,0x0000000010000000,0x1200000062000000\n"
".quad 0x0000000000000410,0x00000006d8000000,0x1a00000085000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x1a0000008d000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x1a00000099000000,0x0000000000000000,0x0000000000000000,0x1a000000a0000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0400005de4000000,0x0094001c04280044\n"
".quad 0x0020009de42c0000,0x6000001c03280040,0x6000209c037000c0,0x008400dc047000c0\n"
".quad 0x0008001c032c0000,0x012001dc23200600,0x00000021e7188e40,0x001000dde2800000\n"
".quad 0x0010009ce3180000,0x00e0011ca35000c0,0x00f0215c43200780,0x0100019ca3480040\n"
".quad 0x0130021de4200780,0x011021dc43280040,0x6000001c03480040,0x0000409c857000c0\n"
".quad 0x0004811c03840000,0x000060dc854800c0,0x0080015de4840000,0x6000411c03280040\n"
".quad 0x0010011c037000c0,0x0000001de4500000,0x0020219ca3400000,0x0000001de4200bc0\n"
".quad 0x0020201ce3400000,0x0130315d035000c0,0x002040dc43480040,0x0090001c435000c0\n"
".quad 0x0020435e03480040,0x00fc51dc23200dc0,0x047c211c23188e00,0x000c039d437000c0\n"
".quad 0x00000001e7480000,0x00a023dc03800000,0x0004531c03480140,0x00fc001de44800c0\n"
".quad 0x00fc01dde4280000,0x00fc00dde4280000,0x00fc009de4280000,0x00b0441c43280000\n"
".quad 0x00fc71dc23480040,0x00fc21dc03198e00,0x006000a1e7192000,0x000401c1e2400000\n"
".quad 0x00fc00c1e4180000,0x00000081e2280000,0x001c011c03180004,0x1240000007480000\n"
".quad 0x047c415c23680000,0x003c411c037000c0,0x0040515c43480100,0x0000425c25480000\n"
".quad 0x00fc91dc23840000,0x10000001e7190e00,0x0fa0000007400000,0x0040215c03700000\n"
".quad 0xfffc211c035800c0,0x0015215c046800c3,0x0011211c04180000,0x010491dc23180000\n"
".quad 0x00fc411d06190ec0,0x04400000078011c0,0x0008021de4600000,0x000802dde4280000\n"
".quad 0x00e00001e7280000,0x010c91dc23400000,0x01600001e7190ec0,0x011c91dc23400000\n"
".quad 0x01c00001e7190ec0,0x015091dc23400000,0x02200001e7190ec0,0x02a0001de7400000\n"
".quad 0x0040415c03400000,0x0060409c036000c0,0x0020419c036000c0,0x0060209c036000c0\n"
".quad 0x0060511c035800c0,0x0060615c135800c0,0x0060519c035800c0,0x0060409c036000c0\n"
".quad 0x0040515c035800c0,0x0060611c036000c0,0x0060515c135800c0,0x0060619c035800c0\n"
".quad 0x0020509c036000c0,0x0060511c036000c0,0x0060615c035800c0,0x0060209c135800c0\n"
".quad 0x0040609c035800c0,0x0020611c036000c0,0x0060615c036000c0,0x0060209c035800c0\n"
".quad 0x0060411c135800c0,0x00fc015de45800c0,0x00fc011de4280000,0x00fc009df4280000\n"
".quad 0x03c0519c03280000,0x003c515c036800c0,0x0010619c036800c0,0x0020515c036000c0\n"
".quad 0x0010611c436000c0,0x0008509c43680000,0x0040411c03680000,0x0010209c436000c0\n"
".quad 0x00fc21dc03680000,0x01400001e71a8e00,0x013071dc23400000,0x00a00081e7198e40\n"
".quad 0x002000e0e3400000,0x002000a0a35000c0,0x00fc0261e4201bc0,0x000ce0e043280000\n"
".quad 0x00002220a5480000,0xfffc71dc03940000,0x00fc00dde44800ff,0x0000001de7280000\n"
".quad 0x0040215c03a80000,0xfffc211c035800c0,0x0015215c046800c3,0x0011211c04180000\n"
".quad 0x00fc31dc23180000,0x01fc411d06190e00,0x0020519c03801181,0x0020445c036000c0\n"
".quad 0x0060429c036000c0,0x0060525c035800c0,0x0040521c036000c0,0x0060619c036000c0\n"
".quad 0x0060515c035800c0,0x0061111c035800c0,0x0020a29c035800c0,0x0060925c036000c0\n"
".quad 0x0060821c035800c0,0x0020619c035800c0,0x0040515c036000c0,0x0010a11c436000c0\n"
".quad 0x0040925c03680000,0x0020621c436000c0,0x0010929c43680000,0x0020519c43680000\n"
".quad 0x01000081e7680000,0x0028616103400000,0x000ca12003480000,0x0014322103480000\n"
".quad 0x000450e064480000,0xfffc816003c28664,0x000c71e0034800ff,0x0004622064480000\n"
".quad 0x00fc50e023c28864,0x000471c003081e00,0x001c011c034800c0,0x0004a20003480000\n"
".quad 0x047c415c234800c0,0x002063dc037000c0,0x003c411c03188e00,0x0040515c43480100\n"
".quad 0x0000425c25480000,0x00fc91dc23840000,0x00000005e71a8e00,0x00000021e7b00000\n"
".quad 0x047c815c23b00000,0x00c0811c037000c0,0x00d0515c43480140,0x0000415c25480040\n"
".quad 0x002451dc23840000,0x02400021e7190e00,0x000471dc03400000,0x0004821c034800c0\n"
".quad 0x001c011c034800c0,0x002061dc03480000,0x047c415c23188e00,0x003c411c037000c0\n"
".quad 0x0040515c43480100,0x0000425c25480000,0x00600001e7840000,0x00fc91dc23400000\n"
".quad 0x00000021e71a8e00,0xfdc0001de7b00000,0x00fc91dc234003ff,0x0000001de71a8e00\n"
".quad 0xf0200001e7b00000,0x0040001de74003ff,0x00fc021de4400000,0x0000001de4280000\n"
".quad 0x013071dc23400000,0x002880dd03198e40,0x00800081e7480000,0x00200160e3400000\n"
".quad 0x00200120a35000c0,0x0014e16043201bc0,0x000040a0a5480000,0x000c709d03940000\n"
".quad 0xfffc21dc03480000,0x0000001de74800ff,0x0040b11c03a80000,0xfffcb09c035800c0\n"
".quad 0x0011215c046800c3,0x0004001c03180000,0x0009211c044800c0,0x0000001de4180000\n"
".quad 0x0000c1dc23400000,0x01fc411d061a8e00,0x0040509c038010c1,0x0060519c036000c0\n"
".quad 0x0060209c036000c0,0x0060619c035800c0,0x03c0215c035800c0,0x0060411c036800c0\n"
".quad 0x003c209c035800c0,0x0010515c036800c0,0x0020209c036000c0,0x0018515c436000c0\n"
".quad 0x0010209c43680000,0x0040511c03680000,0x0010209c436000c0,0xea000001e7680000\n"
".quad 0x0000001de74003ff,0x0000000000800000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x00001c0c04000000\n"
".quad 0x1000000008000000,0x2000000018000000,0x2c00000028000000,0x1300080204000000\n"
".quad 0x0400000001000000,0x0000000014000802,0x0f00080a04000000,0x0300300020000000\n"
".quad 0xff000c1704003019,0x00002c0006ffffff,0xff000c17040011f0,0x0000280005ffffff\n"
".quad 0xff000c17040011f0,0x0000200004ffffff,0xff000c17040021f0,0x0000180003ffffff\n"
".quad 0xff000c17040021f0,0x0000100002ffffff,0xff000c17040021f0,0x0000080001ffffff\n"
".quad 0xff000c17040021f0,0x0000000000ffffff,0xa400080d040021f0,0xe400000020002301\n"
".quad 0xe72800440400005d,0x008000000000001d,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0400000000000000,0x080000000000180c\n"
".quad 0x1800000010000000,0x2400000020000000,0x0d00080a04000000,0x0300280020000000\n"
".quad 0xff000c1704002819,0x0000240005ffffff,0xff000c17040011f0,0x0000200004ffffff\n"
".quad 0xff000c17040011f0,0x0000180003ffffff,0xff000c17040021f0,0x0000100002ffffff\n"
".quad 0xff000c17040021f0,0x0000080001ffffff,0xff000c17040021f0,0x0000000000ffffff\n"
".quad 0x0400005de40021f0,0x0000001de4280044,0x0040105d03400000,0x0094001c044800c0\n"
".quad 0x0020009de42c0000,0x6000001c03280040,0x6000209c037000c0,0x008400dc047000c0\n"
".quad 0x0008001c032c0000,0x00a001dc23200600,0x00000021e7188e40,0x0080009de4800000\n"
".quad 0x005000dce3280040,0x0050009ca35000c0,0x0100011de42005c0,0x009030dc43280040\n"
".quad 0x0010201c85480040,0x0020245c85840000,0x0010019c03840000,0x0048221c452009c0\n"
".quad 0x0010001c43840000,0x0041115c035000c0,0xfffd111c035800c0,0x011001dc436800c3\n"
".quad 0x0015215c04480040,0x0011211c04180000,0x0044035de4180000,0x0000601c85280000\n"
".quad 0x0044049de4840000,0x00fc411d06280000,0x047c019c23801240,0x07200000077000c0\n"
".quad 0x00e004dc03600000,0x00f0651c43480140,0x004c819c03480040,0x0053f1dc43480100\n"
".quad 0x0000631c25480000,0x0040501c03840000,0x0060519c036000c0,0x002051dc036000c0\n"
".quad 0x0060001c036000c0,0x0060619c035800c0,0x006071dc035800c0,0x0020001c035800c0\n"
".quad 0x004071dc036000c0,0x0018001c436000c0,0x001c001c43680000,0x0030115c85680000\n"
".quad 0x018001dc23c80000,0x0010001de4198e40,0x0000111c85280000,0x04800001e7c80000\n"
".quad 0x0020011c03400000,0x0040015c036000c0,0x0060411c036000c0,0x0060001c035800c0\n"
".quad 0x03c0419c036000c0,0x0060515c036800c0,0x003c411c035800c0,0x0060001c036800c0\n"
".quad 0x0010619c035800c0,0x0020411c036000c0,0x0014615c436000c0,0x0000401c43680000\n"
".quad 0x0040511c03680000,0x0034049de46000c0,0x0010001c43280000,0x0040015c03680000\n"
".quad 0xfffc011c035800c0,0x0015215c046800c3,0x0011211c04180000,0x00fc411d06180000\n"
".quad 0x0000035de4801240,0x0040519c03280000,0x006051dc036000c0,0x0020521c036000c0\n"
".quad 0x0060619c036000c0,0x006071dc035800c0,0x0060821c035800c0,0x0020619c035800c0\n"
".quad 0x0040821c036000c0,0x001c619c436000c0,0x0020619c43680000,0x0030115c85680000\n"
".quad 0x018061dc23c80000,0x0010001de41a0e40,0x0000111c85280000,0xfb800001e7c80000\n"
".quad 0x0041211c134003ff,0xfffd201c035800c0,0x0011215c046800c3,0x0001211c04180000\n"
".quad 0x004911dc03180000,0x00fc411d061a8e00,0x0000201c85801240,0x04c0000007840000\n"
".quad 0x0040519c03600000,0x006051dc036000c0,0x0020521c036000c0,0x0060619c036000c0\n"
".quad 0x006071dc035800c0,0x0060821c035800c0,0x0020619c035800c0,0x0040821c036000c0\n"
".quad 0x001c619c436000c0,0x0000111c85680000,0x0020619c43c80000,0x0030115c85680000\n"
".quad 0xfffc639c03c80000,0x02e00001e74800ff,0x0040219c45400000,0x00fc61dc03840000\n"
".quad 0x02600081e7190e00,0x0040d16003400000,0xfffcd120035800c0,0x00152160046800c3\n"
".quad 0x0011212004180000,0x00fc412106180000,0x004051e003801240,0x00605220036000c0\n"
".quad 0x00205260036000c0,0x006071e0036000c0,0x00608220035800c0,0x00609260035800c0\n"
".quad 0x002071e0035800c0,0x00409260036000c0,0x002071e0436000c0,0x0000112085680000\n"
".quad 0x002471e043c80000,0x0030116085680000,0x001c61a003c80000,0xfffc63a003480000\n"
".quad 0x000403ddf24800ff,0x00fc03ddf4180000,0x003521dc03280000,0x00000001e7190e00\n"
".quad 0x00fc029de4800000,0x0104041de2280000,0xfffd211c03180000,0x0041215c036800c3\n"
".quad 0x0011211c045800c0,0x0015215c04180000,0x00fca3dc23180000,0x01fc419d061a8e00\n"
".quad 0x006071dc23801241,0x29e00000075800c0,0x00fc71dc23600000,0x004403dc041a8e00\n"
".quad 0x12c00025e70c0e00,0x001cc1dc23400000,0x04800000071a8000,0x04400021e7600000\n"
".quad 0x004061dc03400000,0x0060621c036000c0,0x0020625c036000c0,0x0060719c036000c0\n"
".quad 0x006081dc035800c0,0x0020619c035800c0,0x0060921c036000c0,0x001c619c435800c0\n"
".quad 0x0040821c03680000,0x0018819c436000c0,0x0140619c03680000,0xfffc621c03480040\n"
".quad 0x014081dc234800ff,0x00600001e71a8e40,0x016001dde4400000,0xfffc71dc23280040\n"
".quad 0x02200001e71a8eff,0x0038619c03400000,0xfffc619c03480000,0x015061dc234800ff\n"
".quad 0x00600001e71a8e40,0x017001dde4400000,0xfffc71dc23280040,0x01400001e71a8eff\n"
".quad 0x014081dc23400000,0x016061dc23198e40,0x00e000a1e71b2040,0x00c00181e4400000\n"
".quad 0x002001c0e3280040,0x00200180a35000c0,0x00d071c043200dc0,0x0004000003480040\n"
".quad 0x00006200854800c0,0x0010638045940000,0x0000001df4940000,0x00fc429d06400000\n"
".quad 0x0020a11c03801240,0x0040a19c036000c0,0x0060411c036000c0,0x0060a15c035800c0\n"
".quad 0x03c0421c036000c0,0x003c41dc036800c0,0x0060619c036800c0,0x0060511c035800c0\n"
".quad 0x0010821c035800c0,0x0020715c036000c0,0x0018819c436000c0,0x0010511c43680000\n"
".quad 0x0040615c03680000,0x0000129c856000c0,0x001441dc43c80000,0x003012dc85680000\n"
".quad 0x0040711c03c80000,0xfffc715c035800c0,0x0011225c046800c3,0x0015221c04180000\n"
".quad 0x01fc811d06180000,0x0020455c038011c1,0x08a00000076000c0,0x0061555c03600000\n"
".quad 0x006045dc035800c0,0x003d559c036000c0,0x006175dc036800c0,0x03c1555c035800c0\n"
".quad 0x0021629c036800c0,0x0011555c036000c0,0x0040459c036000c0,0x005ca29c436000c0\n"
".quad 0x0061659c03680000,0x0059555c435800c0,0x0041555c03680000,0x0054a29c436000c0\n"
".quad 0x002921dc03680000,0x00400001e71a8e00,0x00fc029de4400000,0x010c041df2280000\n"
".quad 0x0040529c03180000,0x0060555c036000c0,0x0060a29c036000c0,0x0061555c035800c0\n"
".quad 0x03c0a2dc035800c0,0x003ca29c036800c0,0x0010b2dc036800c0,0x0054b55c436000c0\n"
".quad 0x006042dc03680000,0x0020a11c035800c0,0x0041529c036000c0,0x002c411c436000c0\n"
".quad 0x0028411c43680000,0x001121dc03680000,0x00400001e71a8e00,0x00fc029de4400000\n"
".quad 0x011c041df2280000,0x0060611c03180000,0x002052dc036000c0,0x0060429c036000c0\n"
".quad 0x0060511c035800c0,0x03c0a55c035800c0,0x003ca15c036800c0,0x0011555c036800c0\n"
".quad 0x0060b29c036000c0,0x0020515c035800c0,0x001152dc436000c0,0x0028511c43680000\n"
".quad 0x0040b15c03680000,0x0014411c436000c0,0x001121dc03680000,0x00400001e71a8e00\n"
".quad 0x00fc029de4400000,0x0150041df2280000,0x0060615c03180000,0x0020611c035800c0\n"
".quad 0x0040619c036000c0,0x03c052dc036000c0,0x003c515c036800c0,0x0060411c036800c0\n"
".quad 0x0010b2dc035800c0,0x0060619c036000c0,0x0020515c035800c0,0x0010b2dc436000c0\n"
".quad 0x0018511c43680000,0x0040b15c03680000,0x0014411c436000c0,0x001121dc03680000\n"
".quad 0x00fc02a1e41a8e00,0x00900421e2280000,0x00040281e2180000,0x0000001df4180000\n"
".quad 0xfffcf11c03400000,0x001c049de44800ff,0x003c43dc23280000,0x00fcf1dc23329e00\n"
".quad 0x00000001f41a8e00,0x00fc811d06400000,0x0040519c03801240,0x006051dc036000c0\n"
".quad 0x0020521c036000c0,0x0060619c036000c0,0x006071dc035800c0,0x0060821c035800c0\n"
".quad 0x0020619c035800c0,0x0040821c036000c0,0x001c619c436000c0,0x0000111c85680000\n"
".quad 0x0020619c43c80000,0x0030115c85680000,0xfffc639c13c80000,0x00fcf1dc234800ff\n"
".quad 0x01fc411d06190e00,0x00c000a1e78013c1,0x0048220045400000,0x0020e20003840000\n"
".quad 0x047c824023480000,0x004c8200037000c0,0x0050924043480100,0x0004820025480000\n"
".quad 0x010503dc23840000,0x0d200000071a8ec0,0x00fc0221e4600000,0x02800005e7280000\n"
".quad 0x0040425c03400000,0x006042dc036000c0,0x0020455c036000c0,0x0060925c036000c0\n"
".quad 0x0060b2dc035800c0,0x00fc93dc035800c0,0x0061555c031a8e00,0x00fcb3dc035800c0\n"
".quad 0x00fd53dc031aa200,0x01000025e71aa200,0x03c1515c03400000,0x003d511c036800c0\n"
".quad 0x0010515c036800c0,0x0020411c036000c0,0x0014915c436000c0,0x0010b11c43680000\n"
".quad 0x0040515c03680000,0x0014449c536000c0,0x010c041de2680000,0x0000001de4180000\n"
".quad 0x010d03dc23400000,0x02400005e71a8ec0,0x0060411c03400000,0x0060525c035800c0\n"
".quad 0x004052dc036000c0,0x00fc43dc036000c0,0x0060925c031a8e00,0x0060b2dc035800c0\n"
".quad 0x00fc93dc035800c0,0x00fcb3dc031aa200,0x01000025e71aa200,0x03c0b19c03400000\n"
".quad 0x003cb15c036800c0,0x0010619c036800c0,0x0020515c036000c0,0x0018919c436000c0\n"
".quad 0x0014411c43680000,0x0040615c03680000,0x0014449c536000c0,0x011c041de2680000\n"
".quad 0x011d03dc23180000,0x02600005e71a8ec0,0x002052dc03400000,0x0060511c036000c0\n"
".quad 0x0060625c035800c0,0x0060b15c036000c0,0x00fc43dc035800c0,0x0060925c031a8e00\n"
".quad 0x00fc53dc035800c0,0x00fc93dc031aa200,0x01000025e71aa200,0x03c091dc03400000\n"
".quad 0x003c919c036800c0,0x001071dc036800c0,0x0020619c036000c0,0x001c41dc436000c0\n"
".quad 0x0018511c43680000,0x0040715c03680000,0x0014449c536000c0,0x0150041de2680000\n"
".quad 0x0000001de4180000,0x015103dc23400000,0x02600005e71a8ec0,0x0020611c03400000\n"
".quad 0x0040615c036000c0,0x0060411c036000c0,0x0060515c035800c0,0x00fc43dc035800c0\n"
".quad 0x0060619c031a8e00,0x00fc53dc035800c0,0x00fc63dc031aa200,0x01000025e71aa200\n"
".quad 0x03c061dc03400000,0x003c619c036800c0,0x001071dc036800c0,0x0020619c036000c0\n"
".quad 0x001c41dc436000c0,0x0018511c43680000,0x0040715c03680000,0x0014449c536000c0\n"
".quad 0x0090041de2680000,0x0000001de4180000,0x009103dc23400000,0x02400005e71a8ec0\n"
".quad 0x0040711c03400000,0x0060719c036000c0,0x0020715c036000c0,0x0060411c036000c0\n"
".quad 0x0060619c035800c0,0x00fc43dc035800c0,0x0060515c031a8e00,0x00fc63dc035800c0\n"
".quad 0x00fc53dc031aa200,0x01000025e71aa200,0x03c051dc03400000,0x003c515c036800c0\n"
".quad 0x001071dc036800c0,0x0020515c036000c0,0x001c41dc436000c0,0x0014611c43680000\n"
".quad 0x0040715c03680000,0x0014449c536000c0,0x0004029df2680000,0x00fca3dc23180000\n"
".quad 0x00000005f41a8e00,0x07c0000007400000,0x07800021e7600000,0x004081dc23400000\n"
".quad 0x07200001e71a8e00,0x0041215c03400000,0xfffd211c035800c0,0x0015215c046800c3\n"
".quad 0x0011211c04180000,0x004911dc03180000,0x00fc411d061a8e00,0x0040519c03801240\n"
".quad 0x006051dc036000c0,0x0020521c036000c0,0x0060619c036000c0,0x006071dc035800c0\n"
".quad 0x0060821c035800c0,0x0020619c035800c0,0x0040821c036000c0,0x001c619c436000c0\n"
".quad 0x0020619c43680000,0x0030115c85680000,0xfffc639c03c80000,0x0000111c854800ff\n"
".quad 0x00000001f4c80000,0x0040219c45400000,0x00fc61dc03840000,0x04200081e7190e00\n"
".quad 0x0020416003400000,0x004041e0036000c0,0x00605160036000c0,0x00604120035800c0\n"
".quad 0x03c05220036000c0,0x006071e0036800c0,0x003c5160035800c0,0x00604120036800c0\n"
".quad 0x00108220035800c0,0x00205160036000c0,0x001c81e0436000c0,0x0010512043680000\n"
".quad 0x0040716003680000,0x00144120436000c0,0x0040416003680000,0xfffc4120035800c0\n"
".quad 0x00152160046800c3,0x0011212004180000,0x00fc412106180000,0x004051e003801240\n"
".quad 0x00605220036000c0,0x00205260036000c0,0x006071e0036000c0,0x00608220035800c0\n"
".quad 0x00609260035800c0,0x002071e0035800c0,0x00409260036000c0,0x002071e0436000c0\n"
".quad 0x002471e043680000,0x0000112085680000,0x001c61a003c80000,0x0030116085480000\n"
".quad 0xfffc63a003c80000,0x000403ddf24800ff,0x000403ddf2180000,0x0004f3dc13180000\n"
".quad 0x0104041df24800c0,0x003521dc03180000,0xd4e00001e71a8e00,0x0000001de74003ff\n"
".quad 0x0000000000800000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0400000000000000,0x0800000000002c0c,0x1800000010000000,0x2800000020000000\n"
".quad 0x3400000030000000,0x3c00000038000000,0x0400000040000000,0x0000000013000802\n"
".quad 0x1400080204000000,0x0400000001000000,0x200000000e00080a,0x0400441903004400\n"
".quad 0x0affffffff000c17,0x040011f000004000,0x09ffffffff000c17,0x040011f000003c00\n"
".quad 0x08ffffffff000c17,0x040011f000003800,0x07ffffffff000c17,0x040011f000003400\n"
".quad 0x06ffffffff000c17,0x040011f000003000,0x05ffffffff000c17,0x040021f000002800\n"
".quad 0x04ffffffff000c17,0x040021f000002000,0x03ffffffff000c17,0x040021f000001800\n"
".quad 0x02ffffffff000c17,0x040021f000001000,0x01ffffffff000c17,0x040011f000000800\n"
".quad 0x00ffffffff000c17,0x040021f000000000,0x20002301a400080d,0x1600100704000000\n"
".quad 0xffffffffff000000,0x04ffffffffffffff,0xff00000015001007,0xffffffffffffffff\n"
".quad 0x1400100704ffffff,0xffffffffff000000,0x04ffffffffffffff,0xff00000013001007\n"
".quad 0xffffffffffffffff,0x1200081204ffffff,0x0400000000000000,0x0000000012000811\n"
".quad 0x1100081204000000,0x0400000000000000,0x0000000011000811,0x1000081204000000\n"
".quad 0x0400000010000000,0x1000000010000811,0x0006000000000000,0x22b4000000050000\n"
".quad 0x0000000000000000,0x0000000000000000,0x00e0000000000000,0x00e0000000000000\n"
".quad 0x0004000000000000,0x0000000000000000,0x08b1000012056000,0x0000000000000000\n"
".quad 0x0000000000000000,0x07ec000000000000,0x07ec000000000000,0x0004000000000000\n"
".quad 0x0000000000000000,0x109d000011056000,0x0000000000000000,0x0000000000000000\n"
".quad 0x00e4000000000000,0x00e4000000000000,0x0004000000000000,0x0000000000000000\n"
".quad 0x1181000010056000,0x0000000000000000,0x0000000000000000,0x1098000000000000\n"
".quad 0x1098000000000000,0x0004000000000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long fatbinData[6759];

}


static struct {int m; int v; const unsigned long long* d; char* f;} __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))=
 { 0x466243b1, 1, fatbinData, 0 };
# 3 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c" 2
extern void __device_stub__Z15mummergpuKernelPvPcS0_PKiS2_ii(void *, char *, char *, const int *, const int *, const int, const int);
extern void __device_stub__Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii(struct MatchCoord *, char *, const int *, const int *, const int, const int);
extern void __device_stub__Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int);
static void __sti____cudaRegisterAll_44_tmpxft_000027c9_00000000_4_mummergpu_cpp1_ii_nodetex(void) __attribute__((__constructor__));
void __device_stub__Z15mummergpuKernelPvPcS0_PKiS2_ii(void *__par0, char *__par1, char *__par2, const int *__par3, const int *__par4, const int __par5, const int __par6){if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)24UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)32UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)40UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)44UL) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel)); (void)cudaLaunch(((char *)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel))); };}
void mummergpuKernel( void *__cuda_0,char *__cuda_1,char *__cuda_2,const int *__cuda_3,const int *__cuda_4,const int __cuda_5,const int __cuda_6)
# 711 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{__device_stub__Z15mummergpuKernelPvPcS0_PKiS2_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 860 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
}
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c"
void __device_stub__Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii( struct MatchCoord *__par0, char *__par1, const int *__par2, const int *__par3, const int __par4, const int __par5) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)32UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)36UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel)); (void)cudaLaunch(((char *)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel))); }; }
void mummergpuRCKernel( struct MatchCoord *__cuda_0,char *__cuda_1,const int *__cuda_2,const int *__cuda_3,const int __cuda_4,const int __cuda_5)
# 873 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{__device_stub__Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 1040 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
}
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c"
void __device_stub__Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii( MatchInfo *__par0, int __par1, Alignment *__par2, char *__par3, const int *__par4, const int *__par5, const int __par6, const int __par7, const int __par8, const int __par9, const int __par10) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)32UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)40UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)48UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par7, sizeof(__par7), (size_t)52UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par8, sizeof(__par8), (size_t)56UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par9, sizeof(__par9), (size_t)60UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par10, sizeof(__par10), (size_t)64UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel)); (void)cudaLaunch(((char *)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel))); }; }
void printKernel( MatchInfo *__cuda_0,int __cuda_1,Alignment *__cuda_2,char *__cuda_3,const int *__cuda_4,const int *__cuda_5,const int __cuda_6,const int __cuda_7,const int __cuda_8,const int __cuda_9,const int __cuda_10)
# 1074 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
{__device_stub__Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10);
# 1328 "/home/normal/checkout/gpuocelot/tests/rodinia/tests/mummergpu/mummergpu_kernel.cuh"
}
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c"
static void __sti____cudaRegisterAll_44_tmpxft_000027c9_00000000_4_mummergpu_cpp1_ii_nodetex(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel), (char*)"_Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii", "_Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel), (char*)"_Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii", "_Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel), (char*)"_Z15mummergpuKernelPvPcS0_PKiS2_ii", "_Z15mummergpuKernelPvPcS0_PKiS2_ii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&nodetex, (const void**)"nodetex", "nodetex", 2, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&childrentex, (const void**)"childrentex", "childrentex", 2, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&reftex, (const void**)"reftex", "reftex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&qrytex, (const void**)"qrytex", "qrytex", 1, 0, 0); }
# 1 "/tmp/tmpxft_000027c9_00000000-1_mummergpu.cudafe1.stub.c" 2
